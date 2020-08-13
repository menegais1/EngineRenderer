cmake_minimum_required(VERSION 3.16)
project(RendererEngine)

set(CMAKE_CXX_STANDARD 14)
add_executable(RendererEngine
        Dependencies/glad/src/glad.c
        src/main.cpp
        src/Backend/GraphicsLibrary.cpp
        src/Backend/GraphicsLibrary.h
        src/Backend/Shader.cpp
        src/Backend/Shader.h
        src/FileManagers/FileLoader.cpp
        src/FileManagers/FileLoader.h
        src/Camera/Camera.h
        src/Camera/Camera.cpp
        src/Camera/CameraMovement.cpp
        src/Camera/CameraMovement.h
        src/Backend/Texture2D.cpp
        src/Backend/Texture2D.h
        src/FileManagers/Bitmap/Bitmap.h
        src/FileManagers/Bitmap/Bitmap.cpp
        src/Utilities.cpp
        src/Utilities.h
        src/Backend/ObjectGL.cpp
        src/Backend/ObjectGL.h
        src/IMGui/imconfig.h
        src/IMGui/imgui_demo.cpp
        src/IMGui/imgui_draw.cpp
        src/IMGui/imgui_impl_glfw.cpp
        src/IMGui/imgui_impl_glfw.h
        src/IMGui/imgui_impl_opengl3.cpp
        src/IMGui/imgui_impl_opengl3.h
        src/IMGui/imgui_internal.h
        src/IMGui/imgui_widgets.cpp
        src/IMGui/imgui.cpp
        src/IMGui/imgui.h
        src/IMGui/imstb_rectpack.h
        src/IMGui/imstb_textedit.h
        src/IMGui/imstb_truetype.h
        src/Base/CanvasObject.cpp
        src/Base/CanvasObject.h
        src/Base/Interfaces/ITransformable.h
        src/Base3DObjects/Cylinder.cpp
        src/Base3DObjects/Cylinder.h
        src/Base/3D/Object3D.cpp
        src/Base/3D/Object3D.h
        src/Base/3D/Transform.cpp
        src/Base/3D/Transform.h
        src/Base3DObjects/OpenEndedCylinder.cpp
        src/Base3DObjects/OpenEndedCylinder.h
        src/FileManagers/ModelLoader.cpp
        src/FileManagers/ModelLoader.h
        src/Managers/GlobalManager.cpp
        src/Managers/GlobalManager.h
        src/Base/3D/ObjectFace.cpp
        src/Base/3D/ObjectFace.h
        src/Engine.cpp
        src/Engine.h
        )
include_directories(Dependencies/glad/include)
find_package(OpenGL REQUIRED)

if (WIN32)
    include_directories(Dependencies/glfw-WIN_64/include)
    add_subdirectory(Dependencies/glfw-WIN_64)
    target_link_libraries(RendererEngine glfw gdi32 ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})
endif ()

if (UNIX)

    include_directories(Dependencies/glfw/include)
    add_subdirectory(Dependencies/glfw)
    target_link_libraries(RendererEngine glfw ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES})
endif ()



