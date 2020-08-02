
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GraphicsLibrary.h"
#include "Vectors/Vector3.h"
#include "Shader.h"
#include "FileLoader.h"
#include "Camera/Camera.h"


int main(void) {
    int width = 500, height = 500;
    auto window = GraphicsLibrary::init(width, height, "Backend");

    unsigned int vertex = Shader::createVertexShader(FileLoader::getPath("Resources/Shaders/DefaultVertex.glsl"));
    unsigned int fragment = Shader::createFragmentShader(FileLoader::getPath("Resources/Shaders/DefaultFragment.glsl"));
    Shader *defaultShader = new Shader(vertex, fragment);

    dvec3 center(0, 0, 0);
    dvec3 eye = dvec3(0, 1, 1);
    Camera::getInstance()->generateViewMatrix(eye, center, dvec3(0, 1, 0));
    Camera::getInstance()->generateProjectionMatrix(60 * (M_PI) / 180.0, width /
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
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    unsigned int indices[] = {0, 1, 2};
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof(unsigned int), indices, GL_STATIC_DRAW);
    fvec3 vertices[] = {{-0.5, -0.5, 0},
                        {-0.5, 0.5,  0},
                        {0.5,  -0.5, 0}};

    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(fvec3), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(glGetAttribLocation(defaultShader->shaderProgram, "vertex_position"), 3, GL_FLOAT, GL_FALSE,
                          sizeof(fvec3), nullptr);
    glEnableVertexAttribArray(0);
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
        glBindVertexArray(VAO);
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
