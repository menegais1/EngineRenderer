#version 460 core

out vec4 FragColor;
uniform vec4 UNIFORM_color;
void main()
{
    FragColor = vec4(UNIFORM_color.x, UNIFORM_color.y, UNIFORM_color.z, UNIFORM_color.w);
}