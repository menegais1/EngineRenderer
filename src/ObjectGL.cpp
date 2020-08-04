//
// Created by menegais1 on 03/08/2020.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "ObjectGL.h"
#include "Camera/Camera.h"
#include "Bitmap/Bitmap.h"
#include "Texture2D.h"
#include "FileLoader.h"

void ObjectGL::setup() {

    int cont = 0;
    for (int i = 0; i < this->faces.size(); ++i) {
        for (int j = 0; j < 3; ++j) {
            vertexBuffer.push_back(vertices[faces[i].vertices[j]][0]);
            vertexBuffer.push_back(vertices[faces[i].vertices[j]][1]);
            vertexBuffer.push_back(vertices[faces[i].vertices[j]][2]);
            vertexBuffer.push_back(this->normals[this->faces[i].normals[j]][0]);
            vertexBuffer.push_back(this->normals[this->faces[i].normals[j]][1]);
            vertexBuffer.push_back(this->normals[this->faces[i].normals[j]][2]);
            vertexBuffer.push_back(this->uvs[this->faces[i].uv[j]][0]);
            vertexBuffer.push_back(this->uvs[this->faces[i].uv[j]][1]);
            vertexBuffer.push_back(this->uvs[this->faces[i].uv[j]][2]);
        }

        elementBuffer.push_back(cont + 0);
        elementBuffer.push_back(cont + 1);
        elementBuffer.push_back(cont + 2);
        cont += 3;
    }
    float *verts = vertexBuffer.data();
    unsigned int *elements = elementBuffer.data();

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexBuffer.size() * sizeof(float), verts, GL_STATIC_DRAW);
    glVertexAttribPointer(glGetAttribLocation(shader.shaderProgram, "vertex_position"), 3, GL_FLOAT, GL_FALSE,
                          sizeof(fvec3) * 3, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(glGetAttribLocation(shader.shaderProgram, "vertex_uv"), 3, GL_FLOAT, false,
                          sizeof(fvec3) * 3, (void *) (sizeof(fvec3) * 2));
    glEnableVertexAttribArray(1);
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementBuffer.size() * sizeof(unsigned int), elements, GL_STATIC_DRAW);
    glBindVertexArray(0);

}

void ObjectGL::render() {
    glBindVertexArray(VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawElements(GL_TRIANGLES, elementBuffer.size(), GL_UNSIGNED_INT, 0);
}

void ObjectGL::dispose() {

}

ObjectGL::ObjectGL(Shader shader, std::vector<fvec3> &vertices, std::vector<ObjectFace> &faces,
                   std::vector<fvec3> &normals, std::vector<fvec3> &uvs) : shader(shader), vertices(vertices),
                                                                           faces(faces), normals(normals),
                                                                           uvs(uvs) {}