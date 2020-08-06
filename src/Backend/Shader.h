//
// Created by menegais1 on 01/08/2020.
//

#ifndef RENDERERENGINE_SHADER_H
#define RENDERERENGINE_SHADER_H


#include <string>
#include <glad/glad.h>
#include "../Vectors/Vector2.h"

class Shader {
private:

    void setUniform(int location, int value);

    void setUniform(int location, unsigned int value);

    void setUniform(int location, float value);

    void setUniform(int location, fvec2 value);

    void setUniform(int location, fvec3 value);

    void setUniform(int location, fvec4 value);

    void setUniform(int location, fMatrix value);

public:

    unsigned int shaderProgram;

    static unsigned int createVertexShader(std::string shader);

    static unsigned int createFragmentShader(std::string shader);

    Shader(unsigned int vertexShader, unsigned int fragmentShader);

    static std::string loadShaderFile(std::string filePath);

    void activateShader();

    template<typename T>
    void setUniform(const char *uniform, T value) {
        int uniformLocation = glGetUniformLocation(shaderProgram, uniform);
        setUniform(uniformLocation, value);
    }

};


#endif //RENDERERENGINE_SHADER_H
