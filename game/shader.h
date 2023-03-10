#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

struct shader_t
{
    GLuint program;

    GLint input_position_loc;
    GLint input_normal_loc;
    GLint input_uv_loc;
};

bool load_shader(shader_t *shader, char *filepath);
void set_shader(shader_t *shader);

shader_t *get_current_shader();

#endif
