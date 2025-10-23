cmake_minimum_required(VERSION 3.24)

project(2D-Parallax-Maps-Editor CXX)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_language(C)

# Assets Path
#Copy assets folder 
file(COPY ${CMAKE_SOURCE_DIR}/Assets 
DESTINATION ${CMAKE_BINARY_DIR})


# ========================
# SDL3 Setup
# ========================

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/external/SDL3")

find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3)

set(SDL3_DLL_PATH "${CMAKE_SOURCE_DIR}/external/SDL3/lib/x64")

# ========================
# glad Setup
# ========================
add_library(glad STATIC
    external/glad/src/glad.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

# ========================
# ImGui Docking
# ========================
add_library(ImGui
            external/ImGui/imgui.cpp 
            external/ImGui/ImGuiFileDialog.cpp 
            external/ImGui/imgui_demo.cpp 
            external/ImGui/imgui_draw.cpp
            external/ImGui/imgui_impl_opengl3.cpp 
            external/ImGui/imgui_impl_sdl3.cpp 
            external/ImGui/imgui_tables.cpp 
            external/ImGui/imgui_widgets.cpp
            external/ImGui/stb_image.cpp)

target_include_directories(ImGui PUBLIC
                            external/ImGui
                            external/SDL3/include)

# ========================
# Final Executable
# ========================
add_executable(2D-Parallax-Maps-Editor
               src/main.cpp "src/Window.cpp" "src/UIMenus/HPP/MenusManager.h" "src/UIMenus/MenusManager.cpp" "src/Core/Graphics/RendererSystem.cpp" "src/Core/Graphics/AssetsManager.cpp" 
               "src/UIMenus/StartMenu.cpp" "src/Core/GL/Texture.cpp" "src/Core/Events/EventsSystem.cpp")

# Definitions


# Include Paths
target_include_directories(2D-Parallax-Maps-Editor PUBLIC
    external/glad/include
    external/glm
    external/Json/nlohmann
    external/Json/RapidJson/include
)

# Link Libraries
target_link_libraries(2D-Parallax-Maps-Editor
    ImGui
    SDL3::SDL3
    glad
)

# Copy SDL3.dll after build
add_custom_command(TARGET 2D-Parallax-Maps-Editor POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3_DLL_PATH}/SDL3.dll"
        $<TARGET_FILE_DIR:2D-Parallax-Maps-Editor>
)
