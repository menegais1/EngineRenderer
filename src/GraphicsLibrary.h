//
// Created by menegais1 on 01/08/2020.
//

#ifndef RENDERERENGINE_GRAPHICSLIBRARY_H
#define RENDERERENGINE_GRAPHICSLIBRARY_H


#include <string>

class GraphicsLibrary {
public:

    static GLFWwindow *init(int width, int height, std::string title);

    static void render(GLFWwindow *window);

private:
    static void mouseButtonCallback(GLFWwindow *window, int button, int action, int modifier);

    static void cursorPosCallback(GLFWwindow *window, double xpos, double ypos);

    static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);
};


#endif //RENDERERENGINE_GRAPHICSLIBRARY_H
