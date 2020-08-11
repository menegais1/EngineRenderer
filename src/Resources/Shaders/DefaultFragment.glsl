#version 460 core

out vec4 FragColor;
uniform vec4 UNIFORM_color;

void main()
{
    FragColor = UNIFORM_color;
}