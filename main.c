#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <GLEW/glew.h>
#include <GLEW/glxew.h>
#include <GLFW/glfw3.h>
#include "graphics/buffer.h"
#include "engine.h"
#include "linmath.h"
#include "io/io.h"
#include "util/log.h"

GLuint vertex_array, vertex_buffer, vertex_shader, fragment_shader, program;
GLint mvp_location, vpos_location, vcol_location;

float verts[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f
};

void Error_Callback(int error, const char* description)
{
    printf("Error: \n");
    fprintf(stderr, "Error: %s\n", description);
}

void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


void Setup_OpenGL()
{
    const int BUFFER_SIZE = sizeof(float) * 9;
    const int VERTEX_SIZE = sizeof(float) * 3;
    const char* vsh_source = CG_Read_File("assets/shaders/VSH-Default.glsl");
    const char* fsh_source = CG_Read_File("assets/shaders/FSH-Default.glsl");

    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

    glBufferData(GL_ARRAY_BUFFER, BUFFER_SIZE, verts, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_SIZE, (void*)0 );

    unsigned int vertex_shader, fragment_shader;
    int success;
    char infoLog[512];

    vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vsh_source, NULL);
    glCompileShader(vertex_shader);

    // print compile errors if any
    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        LE("Vertex Shader Compilation Failed", infoLog);
    };

    fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fsh_source, NULL);
    glCompileShader(fragment_shader);

    // print compile errors if any
    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        LE("Fragment Shader Compilation Failed", infoLog);
    };

    program = glCreateProgram();

    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);

    glGetShaderiv(program, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
        printf("Linking Shader Failed. %s \n", infoLog);
    };

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    L("Shaders Loaded. All fine.");

    mvp_location = glGetUniformLocation(program, "MVP");
    /*vpos_location = glGetAttribLocation(program, "vtx_position");*/

    /*glEnableVertexAttribArray(vpos_location);*/
    /*glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,*/
    /*sizeof(verts[0]), (void*) 0);*/

    /*glEnableVertexAttribArray(vcol_location);*/
    /*glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,*/
    /*sizeof(verts[0]), (void*) (sizeof(float) * 2));*/

    /*free(vsh_source);*/
    /*free(fsh_source);*/

}

int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;
    // Initialize GLFW Context etc
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    Engine e = CG_CreateEngine();

    glfwSetErrorCallback(Error_Callback);

    /* Create a windowed mode window and its OpenGL context */
    e.window = glfwCreateWindow(e.width, e.height, e.title, NULL, NULL);
    if (!e.window)
    {
        glfwTerminate();
        return -1;
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(e.window);

    /* Get Key Input*/
    glfwSetKeyCallback(e.window, Key_Callback);


    /* Glew MUST be initialized after context creation*/
    GLenum err = glewInit();

    if( GLEW_OK != err )
    {
        fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
    }

    Setup_OpenGL();

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(e.window))
    {
        float ratio;
        int width, height;
        mat4x4 m, p, mvp;

        glfwGetFramebufferSize(e.window, &width, &height);
        ratio = width / (float) height;

        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

        mat4x4_identity(m);
        mat4x4_rotate_Z(m, m, (float) glfwGetTime());
        mat4x4_ortho(p, -ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        mat4x4_mul(mvp, p, m);

        glUseProgram(program);
        glBindVertexArray(vertex_array);
        glUniformMatrix4fv(mvp_location, 1, GL_FALSE, (const GLfloat*) mvp);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        /* Swap front and back buffers */
        glfwSwapBuffers(e.window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
