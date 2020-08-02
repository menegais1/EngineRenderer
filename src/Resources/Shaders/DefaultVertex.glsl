#version 460 core

layout (location = 0) in vec3 var;

void main(){
    gl_Position = vec4(var.x, var.y, var.z, 1);
}