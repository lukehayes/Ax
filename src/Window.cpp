#include "Ax/Window.h"
#include "Ax/Config.h"
#include <iostream>

Config config;

namespace Ax::System
{

    Window::Window() 
        : m_width(config.width),
          m_height(config.height)
    {
        this->create();
    }

    Window::Window(s32 width, s32 height) : m_width(width), m_height(height) 
    {
        std::cout << "Window CTOR Throw " << __FILE__ << " Line:" << __LINE__ << std::endl;
        throw;
        this->create();
    }

    Window::~Window() {}

    GLFWwindow*  Window::getWindow() const { return this->m_window; }

    void
        Window::create()
        {
            glfwInit();

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            m_window = glfwCreateWindow(m_width, m_height, m_title, NULL, NULL);
            glfwMakeContextCurrent(m_window);

            gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        }
}
