# GLFW
find_package(glfw QUIET)
if (NOT glfw_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            glfw
            GIT_REPOSITORY https://github.com/glfw/glfw
            GIT_TAG 3.3.6
    )
    FetchContent_GetProperties(glfw)
    if (NOT glfw_POPULATED)
        FetchContent_Populate(glfw)
        add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
    endif()
endif()

option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)

# Dear ImGui
#find_package(imgui QUIET)
#if (NOT imgui_FOUND)
#    include(FetchContent)
#    FetchContent_Declare(
#            imgui
#            GIT_REPOSITORY https://github.com/ocornut/imgui
#            GIT_TAG v1.86
#    )
#    FetchContent_GetProperties(imgui)
#    if (NOT imgui_POPULATED)
#        FetchContent_Populate(ImGui)
#        add_subdirectory(${imgui_SOURCE_DIR} ${imgui_BINARY_DIR})
#    endif()
#endif()

set(IMGUI_DIR ../imgui)
include_directories(${IMGUI_DIR} ${IMGUI_DIR}/backends )

# Libraries
find_package(Vulkan REQUIRED)
set(LIBRARIES "glfw;Vulkan::Vulkan")

# Use vulkan headers from glfw:
include_directories(${GLFW_DIR}/deps)
file(GLOB sources *.cpp)

add_executable(vulkanClient main.cpp
        ${sources}
        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
        ${IMGUI_DIR}/imgui.cpp ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_demo.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        interfaceImGui.cpp
        vulkanHelper.cpp
        )

target_link_libraries(vulkanClient PRIVATE ${LIBRARIES})

#add_executable(vulkanClient main.cpp)

target_link_libraries(vulkanClient PRIVATE email)
target_link_libraries(vulkanClient PRIVATE servidorCliente)
target_link_libraries(vulkanClient PRIVATE bancoDeDados)
target_link_libraries(vulkanClient ${Boost_LIBRARIES} )

