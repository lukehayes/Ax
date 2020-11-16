#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "util/log.h"

typedef struct Engine
{
    // Properties
    int width;
    int height;
    const char* title;
    GLFWwindow* window;
    GLFWmonitor* monitor;

    // Function Pointers
    void (*init)();


} Engine;

void init()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

Engine CG_CreateEngine()
{
    int width = 800;
    int height = 600;
    char* title = "Game";

    /* Initialize the library */
    if (!glfwInit()) { LE("GLFW FAILED TO INITIALIZE", NULL); }

    Engine e = { width, height, title };
    e.init = &init;
    e.init();
    e.window = glfwCreateWindow(width, height, title, NULL, NULL);


    glfwMakeContextCurrent(e.window);

    /* Glew MUST be initialized after context creation*/
    GLenum err = glewInit();

    if( GLEW_OK != err )
    {
        fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
    }

    return e;
}



#endif
