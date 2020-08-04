#include "IMGui/imgui.h"
#include "IMGui/imgui_impl_glfw.h"
#include "IMGui/imgui_impl_opengl3.h"
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

int main(void) {
    int width = 500, height = 500;
    auto window = GraphicsLibrary::init(width, height, "Backend");
    setupIMGui(window);
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

    // Our state
    bool show_demo_window = true;
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    while (!glfwWindowShouldClose(window)) {

        /* Render here */
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();



        rustyMetal.activateTexture(1);
        defaultShader.setUniform("UNIFORM_color", fvec4(std::sin(glfwGetTime()), std::cos(glfwGetTime()), 0, 1));
        defaultShader.setUniform("UNIFORM_projection", Camera::getInstance()->Projection);
        defaultShader.setUniform("UNIFORM_view", Camera::getInstance()->View);
        defaultShader.setUniform("UNIFORM_model", dMatrix::identity(4));
        defaultShader.setUniform("UNIFORM_texture", 1);
        defaultShader.activateShader();
        temp->render();


        {
            static float f = 0.0f;
            static int counter = 0;

            ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

            ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
            ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
            ImGui::Checkbox("Another Window", &show_another_window);

            ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
            ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

            if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);

            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::Image((void*)rustyMetal.texture,ImVec2(100,100));
            ImGui::End();

            if(show_demo_window){
                ImGui::ShowDemoWindow();
            }

        }


        ImGui::Render();

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
