#ifdef VERTEX_SHADER

in vec3 input_position;
in vec3 input_normal;
in vec2 input_uv;

void main(void)
{
    gl_Position = vec4(input_position, 1.0);
}

#endif

#ifdef FRAGMENT_SHADER

out vec4 output_color;

void main(void)
{
    output_color = vec4(1.0, 0.5, 0.2, 1.0);
}

#endif