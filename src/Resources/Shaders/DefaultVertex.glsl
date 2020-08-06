#version 460 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_normal;
layout (location = 2) in vec3 vertex_uv;

uniform mat4 UNIFORM_MVP;

out vec3 v_uv;
out vec3 v_normal;

void main(){
    gl_Position = UNIFORM_MVP * vec4(vertex_position, 1);
    v_normal = vertex_normal;
    v_uv = vertex_uv;
}