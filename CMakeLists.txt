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
        src/FileLoader.h
        src/Camera/Camera.h
        src/Camera/Camera.cpp
        src/Camera/CameraMovement.cpp
        src/Camera/CameraMovement.h
        src/Texture2D.cpp
        src/Texture2D.h
        src/Bitmap/Bitmap.h
        src/Bitmap/Bitmap.cpp
        src/Utilities.cpp
        src/Utilities.h
        src/ObjectGL.cpp
        src/ObjectGL.h )
include_directories(Dependencies/glfw/include)
include_directories(Dependencies/glad/include)
find_package(OpenGL REQUIRED)

if (WIN32)
    add_subdirectory(Dependencies/glfw-WIN_64)
    target_link_libraries(RendererEngine glfw ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})
endif ()

if (UNIX)

    add_subdirectory(Dependencies/glfw)
    target_link_libraries(RendererEngine glfw ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})
endif ()



