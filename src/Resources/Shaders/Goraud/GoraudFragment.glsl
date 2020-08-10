#version 460 core

out vec4 FragColor;
in vec3 v_color;
in vec3 v_uv;

uniform sampler2D UNIFORM_texture;
uniform int UNIFORM_useTexture;

void main() {
    vec4 color;
    if(UNIFORM_useTexture == 1)
        color = vec4(v_color * texture(UNIFORM_texture, v_uv.xy).xyz,1);
    else if(UNIFORM_useTexture == 0)
        color = vec4(v_color,1);

    FragColor = color;
}
