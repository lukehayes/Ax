
#include "Ax/Common/Types.h"
#include "Ax/Window.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){    
    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS){
    glfwSetWindowShouldClose(window, GL_TRUE); 
    }
}

void framebuffer_callback(GLFWwindow* window, int width, int height){    
glViewport(0,0, width, height);
}

int main(int argc, const char *argv[])
{
    Ax::System::Window window;

    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        glClear(GL_DEPTH_BUFFER_BIT);
        glClearColor(1,0,0,1);
    }

    glfwSetKeyCallback(window.getWindow(), key_callback);

    return 0;
}
