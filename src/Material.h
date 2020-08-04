//
// Created by menegais1 on 03/08/2020.
//

#ifndef RENDERERENGINE_MATERIAL_H
#define RENDERERENGINE_MATERIAL_H


#include <map>
#include "Shader.h"

class Material {
public:
    Shader shader;
    std::map<std::string, void *> properties;

    template<typename T>
    void setProperty(std::string property, T value) {
        glUseProgram(shader.shaderProgram);
        shader.setUniform(property.c_str(), value);
        glUseProgram(0);
    }

    virtual void update();

    virtual void fill();

    Material(Shader shader);
};


#endif //RENDERERENGINE_MATERIAL_H
