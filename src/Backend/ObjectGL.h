//
// Created by menegais1 on 03/08/2020.
//

#ifndef RENDERERENGINE_OBJECTGL_H
#define RENDERERENGINE_OBJECTGL_H


#include <glad/glad.h>
#include "Texture2D.h"
#include "Shader.h"
#include "../FileManagers/ModelLoader.h"
#include "../Base/3D/ObjectFace.h"

class ObjectGL {
private:
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;
    bool initialized = false;
    std::vector<float> vertexBuffer;
    std::vector<unsigned int> elementBuffer;
    std::vector<fvec3> &vertices;
    std::vector<ObjectFace> &faces;
    std::vector<fvec3> &normals;
    std::vector<fvec3> &uvs;
public:
    ObjectGL(Shader shader,std::vector<fvec3> &vertices, std::vector<ObjectFace> &faces,
             std::vector<fvec3> &normals, std::vector<fvec3> &uvs);

    GLenum renderType = GL_FILL;
    GLenum primitiveType = GL_TRIANGLES;
    Shader shader;
    void setup();

    void render();

    void dispose();

};


#endif //RENDERERENGINE_OBJECTGL_H
