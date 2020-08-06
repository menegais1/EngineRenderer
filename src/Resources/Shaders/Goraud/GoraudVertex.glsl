#version 460 core

layout (location = 0) in vec3 vertex_position;
layout (location = 1) in vec3 vertex_normal;
layout (location = 2) in vec3 vertex_uv;

uniform mat4 UNIFORM_MVP;
uniform mat4 UNIFORM_InverseModel;
uniform vec3 UNIFORM_lightPosition;

out vec3 v_uv;
out vec3 v_normal;
out vec3 v_color;


void main() {
    gl_Position = UNIFORM_MVP * vec4(vertex_position, 1);
    v_normal = vertex_normal;
    v_uv = vertex_uv;

    vec3 lightPosition = (UNIFORM_InverseModel * vec4(UNIFORM_lightPosition,1)).xyz;
    vec3 lightDirection =(lightPosition - vertex_position);
    lightDirection = lightDirection / length(lightDirection);
    float diffuseComponent = max(0,dot(v_normal, lightDirection));
    v_color = vec3(1,1,1) * diffuseComponent;
}
