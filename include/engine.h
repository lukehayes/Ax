#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

typedef struct Engine
{
    int width;
    int height;
    const char* title;

    void (*init)();
} Engine;

void init()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
}

Engine CG_CreateEngine()
{
    Engine e = { 800,600, "Game" };
    e.init = &init;
    return e;
}



#endif
