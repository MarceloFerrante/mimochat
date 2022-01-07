//
// Created by marcelo on 06/01/2022.
//

#ifndef MIMOCHAT_VULKANHELPER_H
#define MIMOCHAT_VULKANHELPER_H


static void CleanupVulkan();
static void CleanupVulkanWindow();
static void check_vk_result(VkResult err);
static void FramePresent(ImGui_ImplVulkanH_Window* wd);
static void FrameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* draw_data);
static void SetupVulkan(const char** extensions, uint32_t extensions_count);
static void SetupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height);
static void glfw_error_callback(int error, const char* description);


#endif //MIMOCHAT_VULKANHELPER_H
