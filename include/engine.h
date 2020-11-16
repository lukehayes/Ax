#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

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
    Engine e = { 800,600, "Game" };
    e.init = &init;
    return e;
}



#endif
