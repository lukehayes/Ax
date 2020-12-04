#include "engine.h"
#include "util/log.h"

void init()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void ErrorCallback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);

	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        L("Pressed");
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

    e.GetErrors = *glfwSetErrorCallback(ErrorCallback);
    e.GetKeyboardInput = *glfwSetKeyCallback(e.window, KeyCallback);


    glfwMakeContextCurrent(e.window);

    /* Glew MUST be initialized after context creation*/
    GLenum err = glewInit();

    if( GLEW_OK != err )
    {
        fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
    }

    return e;
}


