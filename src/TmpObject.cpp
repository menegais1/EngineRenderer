//
// Created by Roberto on 08/04/20.
//

#include "TmpObject.h"
#include "IMGui/imgui.h"
#include "Base3DObjects/ModelLoader.h"
#include "Camera/Camera.h"

void TmpObject::render() {
    texture2D.activateTexture(1);
    shader.setUniform("UNIFORM_color", fvec4(std::sin(0), std::cos(0), 0, 1));
    shader.setUniform("UNIFORM_projection", Camera::getInstance()->Projection);
    shader.setUniform("UNIFORM_view", Camera::getInstance()->View);
    shader.setUniform("UNIFORM_model", dMatrix::identity(4));
    shader.setUniform("UNIFORM_texture", 1);
    shader.activateShader();
    temp->render();

    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", &show_another_window);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float *) &clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();

        if (show_demo_window) {
            ImGui::ShowDemoWindow();
        }

    }
}

TmpObject::TmpObject(Shader shader) : shader(shader) {

    std::vector<fvec3> vertices = {{-0.5, -0.5, 0},
                                   {-0.5, 0.5,  0},
                                   {0.5,  -0.5, 0}};
    std::vector<fvec3> normals = {{0, 0, 1}};
    std::vector<fvec3> uv = {{0, 0, 0},
                             {0, 1, 0},
                             {1, 1, 0}};
    std::vector<ObjectFace> faces = {{ivec3(0, 1, 2), ivec3(0, 0, 0), ivec3(0, 1, 2)}};

    temp = new ObjectGL(shader, vertices, faces, normals, uv);
    temp->setup();

}
