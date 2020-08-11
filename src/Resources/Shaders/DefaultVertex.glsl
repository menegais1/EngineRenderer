#version 460 core

layout (location = 0) in vec3 vertex_position;

uniform mat4 UNIFORM_MVP;

void main(){
    gl_Position = UNIFORM_MVP * vec4(vertex_position, 1);
}