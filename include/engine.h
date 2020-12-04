#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "common/types.h"

typedef struct Engine
{
    // Properties
    s32 width;
    s32 height;
    const_str title;
    GLFWwindow* window;
    GLFWmonitor* monitor;

    // Function Pointers
    void (*init)();
    void (*hello)();


} Engine;

Engine CG_CreateEngine();



#endif
