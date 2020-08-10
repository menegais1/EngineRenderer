//
// Created by Roberto on 08/04/20.
//

#include "TmpObject.h"
#include "IMGui/imgui.h"
#include "FileManagers/ModelLoader.h"
#include "Camera/Camera.h"

void TmpObject::render() {
    shader.activateShader();
    texture2D.activateTexture(1);
    shader.setUniform("UNIFORM_MVP",  Camera::getInstance()->Projection * Camera::getInstance()->View *fMatrix::identity(4));
    shader.setUniform("UNIFORM_texture", 1);
    temp->render();
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
