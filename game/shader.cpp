#include "shader.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

static shader_t *current_shader;

static char *
read_entire_text_file(char *filepath, size_t *out_length = NULL)
{
    char *result = NULL;

    FILE *file = fopen(filepath, "rt");
    if (file)
    {
        fseek(file, 0, SEEK_END);
        size_t length = ftell(file);
        fseek(file, 0, SEEK_SET);

        result = (char *)calloc(length, sizeof(char));
        size_t num_read = fread(result, sizeof(char), length, file);
        fclose(file);

        result[num_read] = 0;
        if (out_length) *out_length = num_read;
    }
    return result;
}

bool
load_shader(shader_t *shader, char *filepath)
{
    char *data = read_entire_text_file(filepath);
    if (!data)
    {
        fprintf(stderr, "Failed to read file '%s'.\n", filepath);
        return false;
    }
    
    char *vertex_source[] =
    {
        "#version 330 core\n#define VERTEX_SHADER\n#define OUT_IN out\n",
        data,
    };

    GLuint v = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v, ARRAY_SIZE(vertex_source), vertex_source, NULL);
    glCompileShader(v);
    int success = 0;
    glGetShaderiv(v, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char info_log[4096] = {};
        glGetShaderInfoLog(v, sizeof(info_log), NULL, info_log);
        fprintf(stderr, "Failed to compile '%s' vertex shader:\n%s\n", filepath, info_log);
        glDeleteShader(v);
        free(data);
        return false;
    }

    char *fragment_source[] =
    {
        "#version 330 core\n#define FRAGMENT_SHADER\n#define OUT_IN in\n",
        data,
    };

    GLuint f = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f, ARRAY_SIZE(fragment_source), fragment_source, NULL);
    glCompileShader(f);
    glGetShaderiv(f, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char info_log[4096] = {};
        glGetShaderInfoLog(f, sizeof(info_log), NULL, info_log);
        fprintf(stderr, "Failed to compile '%s' fragment shader:\n%s\n", filepath, info_log);
        glDeleteShader(v);
        glDeleteShader(f);
        free(data);
        return false;
    }

    GLuint p = glCreateProgram();
    glAttachShader(p, v);
    glAttachShader(p, f);
    glLinkProgram(p);
    glGetProgramiv(p, GL_LINK_STATUS, &success);
    if (!success)
    {
        char info_log[4096] = {};
        glGetProgramInfoLog(p, sizeof(info_log), NULL, info_log);
        fprintf(stderr, "Failed to link '%s' shader program:\n%s\n", filepath, info_log);
        glDeleteShader(v);
        glDeleteShader(f);
        glDeleteProgram(p);
        free(data);
        return false; 
    }
    glValidateProgram(p);
    glGetProgramiv(p, GL_VALIDATE_STATUS, &success);
    if (!success)
    {
        char info_log[4096] = {};
        glGetProgramInfoLog(p, sizeof(info_log), NULL, info_log);
        fprintf(stderr, "Failed to validate '%s' shader program:\n%s\n", filepath, info_log);
        glDeleteShader(v);
        glDeleteShader(f);
        glDeleteProgram(p);
        free(data);
        return false; 
    }

    shader->program = p;

    shader->input_position_loc = glGetAttribLocation(p, "input_position");
    shader->input_normal_loc = glGetAttribLocation(p, "input_normal");
    shader->input_uv_loc = glGetAttribLocation(p, "input_uv");
    
    glDeleteShader(v);
    glDeleteShader(f);
    free(data);
    return true;
}

void
set_shader(shader_t *shader)
{
    if (current_shader == shader) return;

    current_shader = shader;

    if (shader)
    {
        glUseProgram(shader->program);
    }
    else
    {
        glUseProgram(0);
    }
}

shader_t *
get_current_shader()
{
    return current_shader;
}
