
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


int main(void) {
    int width = 500, height = 500;
    auto window = GraphicsLibrary::init(width, height, "Backend");

    unsigned int vertex = Shader::createVertexShader(FileLoader::getPath("Resources/Shaders/DefaultVertex.glsl"));
    unsigned int fragment = Shader::createFragmentShader(FileLoader::getPath("Resources/Shaders/DefaultFragment.glsl"));
    Shader *defaultShader = new Shader(vertex, fragment);
    Bitmap *bmp = new Bitmap(FileLoader::getPath("Resources/Textures/Albedo.bmp"));
    Texture2D rustyMetal(GL_RGBA, GL_RGBA, GL_FLOAT, bmp->originalBitmapArray, bmp->width, bmp->height);
    dvec3 center(0, 0, 0);
    dvec3 eye = dvec3(0, 1, 1);
    Camera::getInstance()->generateViewMatrix(eye, center, dvec3(0, 1, 0));
    Camera::getInstance()->generateProjectionMatrix(60 * (3.14) / 180.0, width /
                                                                         (float) height,
                                                    0.1,
                                                    10);
    Camera::getInstance()->setViewport(width,
                                       height, 0, 0);
    dMatrix Model(4, 4);
    Model.m = {{1, 0, 0, 0},
               {0, 1, 0, 0},
               {0, 0, 1, 0},
               {0, 0, 0, 1}};
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    fvec3 vertices[] = {{-0.5, -0.5, 0},
                        {-0.5, 0.5,  0},
                        {0.5,  -0.5, 0}};
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(fvec3), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(glGetAttribLocation(defaultShader->shaderProgram, "vertex_position"), 3, GL_FLOAT, GL_FALSE,
                          sizeof(fvec3), nullptr);
    glEnableVertexAttribArray(0);
    unsigned int C_VBO;
    glGenBuffers(1, &C_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, C_VBO);
    fvec2 uv[] = {{0, 0},
                  {0, 1},
                  {1, 0}};

    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(fvec2), uv, GL_STATIC_DRAW);
    glVertexAttribPointer(glGetAttribLocation(defaultShader->shaderProgram, "vertex_uv"), 2, GL_FLOAT, false,
                          2 * sizeof(float), 0);
    glEnableVertexAttribArray(1);
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    unsigned int indices[] = {0, 1, 2};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {

        /* Render here */
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(defaultShader->shaderProgram);
        defaultShader->setUniform("UNIFORM_color", fvec4(std::sin(glfwGetTime()), std::cos(glfwGetTime()), 0, 1));
        defaultShader->setUniform("UNIFORM_projection", Camera::getInstance()->Projection);
        defaultShader->setUniform("UNIFORM_view", Camera::getInstance()->View);
        defaultShader->setUniform("UNIFORM_model", Model);
        defaultShader->setUniform("UNIFORM_texture", 0);
        glBindVertexArray(VAO);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, rustyMetal.texture);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
