#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

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

void init();

void error_callback(int error, const char* description);

Engine CG_CreateEngine();



#endif
