#version 460 core

layout (location = 0) in vec3 vertex_position;

uniform mat4 UNIFORM_model;
uniform mat4 UNIFORM_view;
uniform mat4 UNIFORM_projection;

void main(){
    gl_Position = UNIFORM_projection* UNIFORM_view* UNIFORM_model * vec4(vertex_position, 1);
}