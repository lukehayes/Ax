#include "Ax/System/Window.h"

namespace Ax::System
{

    Window::Window() {
        this->create();
    }
    Window::~Window() {}

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
