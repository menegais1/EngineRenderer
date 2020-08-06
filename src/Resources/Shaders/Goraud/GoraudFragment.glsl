#version 460 core

out vec4 FragColor;
in vec3 v_color;
in vec3 v_uv;

uniform sampler2D UNIFORM_texture;


void main() {
    FragColor = vec4(v_color /** texture(UNIFORM_texture, v_uv.xy).xyz*/,1);
}
