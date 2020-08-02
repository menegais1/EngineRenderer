//
// Created by menegais1 on 01/08/2020.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GraphicsLibrary.h"

GLFWwindow * GraphicsLibrary::init(int width, int height, std::string title) {

    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return nullptr;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return nullptr;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGL()) {
        std::cout << "Something went wrong!\n" << std::endl;
        exit(-1);
    }
    std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;


    glViewport(0, 0, 640, 480);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    return window;
}


void GraphicsLibrary::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    std::cout << "resize" << std::endl;
}

void GraphicsLibrary::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    std::cout << key << " ";
    std::cout << scancode << " ";
    std::cout << action << " ";
    std::cout << mods << std::endl;
}

void GraphicsLibrary::cursorPosCallback(GLFWwindow *window, double xpos, double ypos) {
//    std::cout << xpos << " " << ypos << std::endl;
}

void GraphicsLibrary::mouseButtonCallback(GLFWwindow *window, int button, int action, int modifier) {
    std::cout << button << " ";
    std::cout << action << " ";
    std::cout << modifier << std::endl;
}