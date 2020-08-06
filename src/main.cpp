#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Backend/GraphicsLibrary.h"
#include "Vectors/Vector3.h"
#include "Backend/Shader.h"
#include "FileManagers/FileLoader.h"
#include "Camera/Camera.h"
#include "FileManagers/Bitmap/Bitmap.h"
#include "Backend/Texture2D.h"
#include "Backend/ObjectGL.h"
#include "TmpObject.h"
#include "Camera/CameraMovement.h"
#include "Engine.h"


int main(void) {
    int width = 500, height = 500;
    auto window = GraphicsLibrary::init(width, height, "Backend");
    unsigned int vertex = Shader::createVertexShader(FileLoader::getPath("Resources/Shaders/DefaultVertex.glsl"));
    unsigned int fragment = Shader::createFragmentShader(FileLoader::getPath("Resources/Shaders/DefaultFragment.glsl"));
    Shader defaultShader(vertex, fragment);
    Bitmap *bmp = new Bitmap(FileLoader::getPath("Resources/Textures/Albedo.bmp"));
    Texture2D rustyMetal(GL_RGBA, GL_RGBA, GL_FLOAT, bmp->originalBitmapArray, bmp->width, bmp->height);
    fvec3 center(0, 0, 0);
    fvec3 eye = fvec3(0, 0, 1);
    Camera::getInstance()->generateViewMatrix(eye, center, fvec3(0, 1, 0));
    Camera::getInstance()->generateProjectionMatrix(60 * (3.14) / 180.0, width /
                                                                         (float) height,
                                                    0.1,
                                                    10);
    Camera::getInstance()->setViewport(width, height, 0, 0);
    CameraMovement *movement = new CameraMovement(Camera::getInstance());

    TmpObject *obj = new TmpObject(defaultShader);
    obj->texture2D = rustyMetal;


    Engine *engine = new Engine(
            Transform(fvec3(2, 0, 0), fvec3(0, 0, 0), fvec3(1, 1, 1)), defaultShader);
    engine->rpm = 5000;
    while (!glfwWindowShouldClose(window)) {

        GraphicsLibrary::render(window);

    }

    glfwTerminate();
    return 0;
}
