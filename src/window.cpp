#include "window.h"

namespace Ax
{

    Window::Window() {
        this->create();
    }
    Window::~Window() {}

    void
    Window::create()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        glfwInit();

        this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);

        glfwMakeContextCurrent(this->window);

        /* Glew MUST be initialized after context creation*/
        GLenum err = glewInit();

        if( GLEW_OK != err )
        {
            fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
        }
    }
}
