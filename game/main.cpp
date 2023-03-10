#include <stdio.h>
#include <GLFW/glfw3.h>
#include <GL/glew.h>

#include "shader.h"
#include "my_math.h"

struct mesh_vertex_t
{
    vec3 position;
    vec3 normal;
    vec2 uv;
};

#define MESH_VERTEX_OFFSET_position 0
#define MESH_VERTEX_OFFSET_normal 12
#define MESH_VERTEX_OFFSET_uv 24

static void
set_vertex_format_to_mesh(void)
{
    shader_t *shader = get_current_shader();

    GLint loc = shader->input_position_loc;
    if (loc != -1)
    {
        glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, sizeof(mesh_vertex_t), (void *)MESH_VERTEX_OFFSET_position);
        glEnableVertexAttribArray(loc);
    }
    else
    {
        glDisableVertexAttribArray(loc);
    }

    loc = shader->input_normal_loc;
    if (loc != -1)
    {
        glVertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, sizeof(mesh_vertex_t), (void *)MESH_VERTEX_OFFSET_normal);
        glEnableVertexAttribArray(loc);
    }
    else
    {
        glDisableVertexAttribArray(loc);
    }

    loc = shader->input_uv_loc;
    if (loc != -1)
    {
        glVertexAttribPointer(loc, 2, GL_FLOAT, GL_FALSE, sizeof(mesh_vertex_t), (void *)MESH_VERTEX_OFFSET_uv);
        glEnableVertexAttribArray(loc);
    }
    else
    {
        glDisableVertexAttribArray(loc);
    }
}

static shader_t shader_basic;

static bool
init_shaders()
{
    if (!load_shader(&shader_basic, "data/shaders/basic.glsl")) return false;

    return true;
}

int
main(int argc, char **argv)
{
    if (!glfwInit())
    {
        printf("glfwInit failed.\n");
        return 1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(1280, 720, "Game", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        printf("glewInit failed.\n");
        return 1;
    }
    
    if (!init_shaders())
    {
        getchar();
        return 1;
    }

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    mesh_vertex_t vertices[] =
    {
        { { -0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 0.0f } },
        { { +0.5f, -0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 0.0f } },
        { { +0.5f, +0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 1.0f, 1.0f } },
        { { -0.5f, +0.5f, 0.0f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
    };

    uint8_t indices[] =
    {
        0, 1, 2,
        0, 2, 3,
    };

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        int window_width, window_height;
        glfwGetFramebufferSize(window, &window_width, &window_height);
        glViewport(0, 0, window_width, window_height);
        
        glClearColor(0.2f, 0.5f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        set_shader(&shader_basic);
        
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

        set_vertex_format_to_mesh();

        glDrawElements(GL_TRIANGLES, ARRAY_SIZE(indices), GL_UNSIGNED_BYTE, NULL);
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    
    return 0;
}
