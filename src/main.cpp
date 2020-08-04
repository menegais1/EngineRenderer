
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GraphicsLibrary.h"
#include "Vectors/Vector3.h"
#include "Shader.h"
#include "FileLoader.h"
#include "Camera/Camera.h"
#include "Bitmap/Bitmap.h"
#include "Texture2D.h"
#include "ObjectGL.h"


int main(void) {
    int width = 500, height = 500;
    auto window = GraphicsLibrary::init(width, height, "Backend");

    unsigned int vertex = Shader::createVertexShader(FileLoader::getPath("Resources/Shaders/DefaultVertex.glsl"));
    unsigned int fragment = Shader::createFragmentShader(FileLoader::getPath("Resources/Shaders/DefaultFragment.glsl"));
    Shader defaultShader(vertex, fragment);
    Bitmap *bmp = new Bitmap(FileLoader::getPath("Resources/Textures/Albedo.bmp"));
    Texture2D rustyMetal(GL_RGBA, GL_RGBA, GL_FLOAT, bmp->originalBitmapArray, bmp->width, bmp->height);
    dvec3 center(0, 0, 0);
    dvec3 eye = dvec3(0, 0, 1);
    Camera::getInstance()->generateViewMatrix(eye, center, dvec3(0, 1, 0));
    Camera::getInstance()->generateProjectionMatrix(60 * (3.14) / 180.0, width /
                                                                         (float) height,
                                                    0.1,
                                                    10);
    Camera::getInstance()->setViewport(width, height, 0, 0);

    std::vector<fvec3> vertices = {{-0.5, -0.5, 0},
                                   {-0.5, 0.5,  0},
                                   {0.5,  -0.5, 0}};
    std::vector<fvec3> normals = {{0, 0, 1}};
    std::vector<fvec3> uv = {{0, 0, 0},
                             {0, 1, 0},
                             {1, 1, 0}};
    std::vector<ObjectFace> faces = {{ivec3(0, 1, 2), ivec3(0, 0, 0), ivec3(0, 1, 2)}};

    ObjectGL *temp = new ObjectGL(defaultShader, vertices, faces, normals, uv);
    temp->setup();
    while (!glfwWindowShouldClose(window)) {

        /* Render here */
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        rustyMetal.activateTexture(1);
        defaultShader.setUniform("UNIFORM_color", fvec4(std::sin(glfwGetTime()), std::cos(glfwGetTime()), 0, 1));
        defaultShader.setUniform("UNIFORM_projection", Camera::getInstance()->Projection);
        defaultShader.setUniform("UNIFORM_view", Camera::getInstance()->View);
        defaultShader.setUniform("UNIFORM_model", dMatrix::identity(4));
        defaultShader.setUniform("UNIFORM_texture", 1);
        defaultShader.activateShader();
        temp->render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
