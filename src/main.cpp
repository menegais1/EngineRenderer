
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "GraphicsLibrary.h"
#include "Vectors/Vector3.h"
#include "Shader.h"
#include "FileLoader.h"


int main(void) {

    auto window = GraphicsLibrary::init(500, 500, "Backend");

    unsigned int vertex = Shader::createVertexShader(FileLoader::getPath("Resources/Shaders/DefaultVertex.glsl"));
    unsigned int fragment = Shader::createFragmentShader(FileLoader::getPath("Resources/Shaders/DefaultFragment.glsl"));
    unsigned int program = Shader::createShaderProgram(vertex, fragment);
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
    float vertices[] = {-0.5, -0.5, 0,
                        -0.5, 0.5, 0,
                        0.5, -0.5, 0};

    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
    glUseProgram(program);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {

        /* Render here */
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);
        glBindVertexArray(VAO);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT,0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
