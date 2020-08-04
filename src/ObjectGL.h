//
// Created by menegais1 on 03/08/2020.
//

#ifndef RENDERERENGINE_OBJECTGL_H
#define RENDERERENGINE_OBJECTGL_H


#include <glad/glad.h>
#include "Texture2D.h"
#include "Shader.h"

struct ObjectFace {
    ivec3 vertices;
    ivec3 normals;
    ivec3 uv;

    ObjectFace(ivec3 vertices, ivec3 normals, ivec3 uv) : vertices(vertices), normals(normals), uv(uv) {};
};

class ObjectGL {
private:
    GLuint VBO;
    GLuint VAO;
    GLuint EBO;
    std::vector<float> vertexBuffer;
    std::vector<unsigned int> elementBuffer;
    std::vector<fvec3> &vertices;
    std::vector<ObjectFace> &faces;
    std::vector<fvec3> &normals;
    std::vector<fvec3> &uvs;
    Shader shader;
public:
    ObjectGL(Shader shader,std::vector<fvec3> &vertices, std::vector<ObjectFace> &faces,
             std::vector<fvec3> &normals, std::vector<fvec3> &uvs);

    void setup();

    void render();

    void dispose();

};


#endif //RENDERERENGINE_OBJECTGL_H