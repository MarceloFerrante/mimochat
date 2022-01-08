// Dear ImGui: standalone example application for Glfw + Vulkan
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

// Important note to the reader who wish to integrate imgui_impl_vulkan.cpp/.h in their own engine/app.
// - Common ImGui_ImplVulkan_XXX functions and structures are used to interface with imgui_impl_vulkan.cpp/.h.
//   You will use those if you want to use this rendering backend in your engine/app.
// - Helper ImGui_ImplVulkanH_XXX functions and structures are only used by this example (main.cpp) and by
//   the backend itself (imgui_impl_vulkan.cpp), but should PROBABLY NOT be used by your own engine/app code.
// Read comments in imgui_impl_vulkan.h.

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include <stdio.h>          // printf, fprintf
#include <stdlib.h>         // abort
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>
#include <string>
#include "vulkanHelper.cpp" //FIXME separar .h/.cpp

#include "bancoDeDados/BD.h"
#include <servidorCliente/encripta.h>

#include "interfaceImGui.h"

const uint16_t  janelaLargura = 600,
        janelaAltura = 720;

int main(int, char**)
{
    // Setup GLFW window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(janelaLargura, janelaAltura, "Mimo Chat", NULL, NULL);

    // Setup Vulkan
    if (!glfwVulkanSupported())
    {
        printf("GLFW: Vulkan Not Supported\n");
        return 1;
    }
    uint32_t extensions_count = 0;
    const char** extensions = glfwGetRequiredInstanceExtensions(&extensions_count);
    SetupVulkan(extensions, extensions_count);

    // Create Window Surface
    VkSurfaceKHR surface;
    VkResult err = glfwCreateWindowSurface(g_Instance, window, g_Allocator, &surface);
    check_vk_result(err);

    // Create Framebuffers
    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    ImGui_ImplVulkanH_Window* wd = &g_MainWindowData;
    SetupVulkanWindow(wd, surface, w, h);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForVulkan(window, true);
    ImGui_ImplVulkan_InitInfo init_info = {};
    init_info.Instance = g_Instance;
    init_info.PhysicalDevice = g_PhysicalDevice;
    init_info.Device = g_Device;
    init_info.QueueFamily = g_QueueFamily;
    init_info.Queue = g_Queue;
    init_info.PipelineCache = g_PipelineCache;
    init_info.DescriptorPool = g_DescriptorPool;
    init_info.Allocator = g_Allocator;
    init_info.MinImageCount = g_MinImageCount;
    init_info.ImageCount = wd->ImageCount;
    init_info.CheckVkResultFn = check_vk_result;
    ImGui_ImplVulkan_Init(&init_info, wd->RenderPass);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Upload Fonts
    {
        // Use any command queue
        VkCommandPool command_pool = wd->Frames[wd->FrameIndex].CommandPool;
        VkCommandBuffer command_buffer = wd->Frames[wd->FrameIndex].CommandBuffer;

        err = vkResetCommandPool(g_Device, command_pool, 0);
        check_vk_result(err);
        VkCommandBufferBeginInfo begin_info = {};
        begin_info.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        begin_info.flags |= VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;
        err = vkBeginCommandBuffer(command_buffer, &begin_info);
        check_vk_result(err);

        ImGui_ImplVulkan_CreateFontsTexture(command_buffer);

        VkSubmitInfo end_info = {};
        end_info.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
        end_info.commandBufferCount = 1;
        end_info.pCommandBuffers = &command_buffer;
        err = vkEndCommandBuffer(command_buffer);
        check_vk_result(err);
        err = vkQueueSubmit(g_Queue, 1, &end_info, VK_NULL_HANDLE);
        check_vk_result(err);

        err = vkDeviceWaitIdle(g_Device);
        check_vk_result(err);
        ImGui_ImplVulkan_DestroyFontUploadObjects();
    }

    // Our state
    bool show_demo_window = false;

    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    BD::bancoDeDados listaDePessoas;
    interface::menu menuPrincipal;

    // popula lista
    for (int x = 0; x < 5; ++x) {
        std::string nome, email, ipv4, pub, priv, msg;
        nome = encripta::random_string(4) + " amigo " + std::to_string(x);
        email = encripta::random_string(4) + "@ab.com";
        ipv4 =  "192.168.0.10" + std::to_string(x);
        pub = encripta::random_string(16);
        priv =  pub;
        msg =  "Mensagem de teste " + std::to_string(x);
        listaDePessoas.adicionaContato(email, nome, ipv4, pub, priv, msg);
    }

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Resize swap chain?
        if (g_SwapChainRebuild)
        {
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);
            if (width > 0 && height > 0)
            {
                ImGui_ImplVulkan_SetMinImageCount(g_MinImageCount);
                ImGui_ImplVulkanH_CreateOrResizeWindow(g_Instance, g_PhysicalDevice, g_Device, &g_MainWindowData, g_QueueFamily, g_Allocator, width, height, g_MinImageCount);
                g_MainWindowData.FrameIndex = 0;
                g_SwapChainRebuild = false;
            }
        }

        // Start the Dear ImGui frame
        ImGui_ImplVulkan_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
        if (show_demo_window)
            ImGui::ShowDemoWindow(&show_demo_window);

        //Barra de menu Principal
        ImGui::BeginMainMenuBar();
        {
            if (ImGui::BeginMenu("Amigos")) {
                menuPrincipal.Amigos(listaDePessoas);
                ImGui::EndMenu();
            }
            if (ImGui::BeginMenu("Teste")) {
                menuPrincipal.janelaChat();
                ImGui::EndMenu();
            }
        }
        ImGui::EndMainMenuBar();

        {

        ImGuiWindowFlags window_flags = 0;
        window_flags |= ImGuiWindowFlags_NoTitleBar;
        window_flags |= ImGuiWindowFlags_NoScrollbar;
        window_flags |= ImGuiWindowFlags_NoMove;
        window_flags |= ImGuiWindowFlags_NoResize;

        // We specify a default position/size in case there's no data in the .ini file.
        // We only do it to make the demo applications a little more welcoming, but typically this isn't required.
        const ImGuiViewport* main_viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(ImVec2(main_viewport->WorkPos.x, main_viewport->WorkPos.y), ImGuiCond_Always);
        ImGui::SetNextWindowSize(ImVec2(janelaLargura, janelaAltura), ImGuiCond_Always);

        ImGui::Begin("MimO Chat", NULL ,window_flags);
        {
            static bool enable_extra_decorations = true;

            ImGuiStyle& style = ImGui::GetStyle();
            float largura = (ImGui::GetContentRegionAvail().x -  style.ItemSpacing.x) / 5;
            if (largura < 100.0f)
                largura = 100.0f;
            float altura = (ImGui::GetContentRegionAvail().y -  style.ItemSpacing.y);
            if (altura < 100.0f)
                altura = 100.0f;

            ImGui::PushID("##VerticalScrolling");

            //ID dos widgets
            uint16_t id = 0;

            const ImGuiWindowFlags amigosFlags = enable_extra_decorations ? ImGuiWindowFlags_MenuBar : 0;
            const ImGuiID idAmigos = ImGui::GetID((void*)(intptr_t)id);
            const bool listaAmigos = ImGui::BeginChild(idAmigos, ImVec2(largura, altura), true, amigosFlags);
            {
                //popula lista de amigos
                for (int n = 0; n < listaDePessoas.size(); n++)
                {
                    std::string nome = listaDePessoas.getNome(n);
                    std::string email = listaDePessoas.getEmail(n);
                    ImGui::Selectable(nome.c_str()); //TODO fazer funcao pra mudar os nomes

                    if (ImGui::BeginPopupContextItem()) // <-- use last item id as popup id
                    {//FIXME Bug ao editar
                        ImGui::Text("Editar Contato:");
                        ImGui::InputText("##editNome", nome.begin().base(), nome.size());
                        ImGui::InputText("##editEmail", email.begin().base(), email.size());
                        if (ImGui::Button("Confirmar")) {
                            listaDePessoas.editaContato(email,nome);
                            ImGui::CloseCurrentPopup();
                        }
                        ImGui::SameLine();
                        if (ImGui::Button("Cancelar"))
                            ImGui::CloseCurrentPopup();

                        ImGui::Separator();

                        std::string remover = "Remover " + nome;
                        if (ImGui::Button(remover.c_str())){
                            listaDePessoas.removeContato(email);
                            ImGui::CloseCurrentPopup();
                        }

                        ImGui::EndPopup();
                    }
                    if (ImGui::IsItemHovered())
                        ImGui::SetTooltip("Clique com o botão direito para opções");
                }
            }
            ImGui::EndChild();

            id++;
            ImGui::SameLine();
            const ImGuiWindowFlags chatFlags = enable_extra_decorations ? ImGuiWindowFlags_MenuBar : 0;
            const ImGuiID idChat = ImGui::GetID((void*)(intptr_t)id);
            const bool areaDeChat = ImGui::BeginChild(idChat, ImVec2(largura * 4, altura), true, chatFlags);

            if(areaDeChat){
                for (int item = 0; item < 5; item++) {
                    std::string txt = "%d texto do chat texto do chat texto do chat texto do "
                                      "chat texto do chat texto do chat texto do chat texto "
                                      "do chat texto do chat texto do chat texto do chat "
                                      "texto do chat texto do chat texto do chat texto do chat texto do chat";
                    ImGui::TextWrapped(txt.c_str(), item);
                }
            }
            ImGui::EndChild();
            ImGui::PopID();

        }
        ImGui::End();
    }

        // Rendering
        ImGui::Render();
        ImDrawData* draw_data = ImGui::GetDrawData();
        const bool is_minimized = (draw_data->DisplaySize.x <= 0.0f || draw_data->DisplaySize.y <= 0.0f);
        if (!is_minimized)
        {
            wd->ClearValue.color.float32[0] = clear_color.x * clear_color.w;
            wd->ClearValue.color.float32[1] = clear_color.y * clear_color.w;
            wd->ClearValue.color.float32[2] = clear_color.z * clear_color.w;
            wd->ClearValue.color.float32[3] = clear_color.w;
            FrameRender(wd, draw_data);
            FramePresent(wd);
        }
    }

    // Cleanup
    err = vkDeviceWaitIdle(g_Device);
    check_vk_result(err);
    ImGui_ImplVulkan_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    CleanupVulkanWindow();
    CleanupVulkan();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
