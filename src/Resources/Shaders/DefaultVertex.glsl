#version 460 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec2 vertex_uv;

uniform mat4 UNIFORM_model;
uniform mat4 UNIFORM_view;
uniform mat4 UNIFORM_projection;

varying vec2 v_uv;

void main(){
    gl_Position = UNIFORM_projection* UNIFORM_view* UNIFORM_model * vec4(vertex_position, 1);
    v_uv = vertex_uv;
}