cmake_minimum_required(VERSION 3.16)
project(RendererEngine)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
add_executable(RendererEngine
        Dependencies/glad/src/glad.c
        src/main.cpp
        src/GraphicsLibrary.cpp
        src/GraphicsLibrary.h
        src/Shader.cpp
        src/Shader.h
        src/FileLoader.cpp
        src/FileLoader.h)

add_subdirectory(Dependencies/glfw)
include_directories(Dependencies/glfw/include)
include_directories(Dependencies/glad/include)

find_package(OpenGL REQUIRED)

target_link_libraries(RendererEngine glfw ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})

