//
// Created by menegais1 on 01/08/2020.
//

#include "../IMGui/imgui.h"
#include "../IMGui/imgui_impl_glfw.h"
#include "../IMGui/imgui_impl_opengl3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "GraphicsLibrary.h"
#include "../Managers/GlobalManager.h"


void setupIMGui(GLFWwindow *window) {
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer bindings
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(nullptr);

}

GLFWwindow *GraphicsLibrary::init(int width, int height, std::string title) {

    GLFWwindow *window;

    /* Initialize the library */
    if (!glfwInit())
        return nullptr;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
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


    glViewport(0, 0, width, height);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSwapInterval(0);
    setupIMGui(window);
    glEnable(GL_DEPTH_TEST);
    return window;
}

void GraphicsLibrary::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
    GlobalManager::getInstance()->reshape(width, height);
}

void GraphicsLibrary::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    GlobalManager::getInstance()->keyboard(key, scancode, action, mods);

}

void GraphicsLibrary::cursorPosCallback(GLFWwindow *window, double xpos, double ypos) {
    GlobalManager::getInstance()->mouseMovement(xpos, ypos);
}

void GraphicsLibrary::mouseButtonCallback(GLFWwindow *window, int button, int action, int modifier) {
    GlobalManager::getInstance()->mouseButton(button, action, modifier);

}

void GraphicsLibrary::render(GLFWwindow *window) {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    GlobalManager::getInstance()->render();

    ImGui::Render();

    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
}
