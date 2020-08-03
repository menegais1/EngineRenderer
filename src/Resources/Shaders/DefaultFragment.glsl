#version 460 core

out vec4 FragColor;
uniform sampler2D UNIFORM_texture;

in vec2 v_uv;

void main()
{
    vec4 color = texture(UNIFORM_texture, v_uv);
    FragColor = vec4(color.x, color.y, color.z, color.w);
}