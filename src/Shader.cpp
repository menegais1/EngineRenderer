//
// Created by menegais1 on 01/08/2020.
//

#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <iostream>


std::string Shader::loadShaderFile(std::string filePath) {
    std::string sourceCode;

    std::fstream file(filePath, std::ios::in);
    if (!file.is_open()) {
        std::cerr << "ERROR OPENING FILE " << filePath << std::endl;
        return nullptr;
    }

    while (!file.eof()) {
        sourceCode.append(1, file.get());
    }

    return sourceCode;
}

unsigned int Shader::createVertexShader(std::string shader) {
    std::string sourceCode = loadShaderFile(shader);
    const char *source = sourceCode.c_str();
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &source, nullptr);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
                  infoLog << std::endl;
        return -1;
    }

    return vertexShader;
}

unsigned int Shader::createFragmentShader(std::string shader) {
    std::string sourceCode = loadShaderFile(shader);
    const char *source = sourceCode.c_str();
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &source, nullptr);
    glCompileShader(fragmentShader);

    int success;
    char infoLog[512];
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
                  infoLog << std::endl;
        return -1;
    }

    return fragmentShader;
}

unsigned int Shader::createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader) {
    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    GLchar infoLog[1024];
    glGetProgramiv(shaderProgram, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 1024, NULL, infoLog);
        std::cerr << "ERROR::LINKING_SHADER::\n" <<
                  infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}
