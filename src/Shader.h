//
// Created by menegais1 on 01/08/2020.
//

#ifndef RENDERERENGINE_SHADER_H
#define RENDERERENGINE_SHADER_H


#include <string>

class Shader {
public:

    static unsigned int createVertexShader(std::string shader);

    static unsigned int createFragmentShader(std::string shader);

    static unsigned int createShaderProgram(unsigned int vertexShader, unsigned int fragmentShader);

    static std::string loadShaderFile(std::string filePath);
};


#endif //RENDERERENGINE_SHADER_H
