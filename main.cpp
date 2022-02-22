#include "Ax/Common/Types.h"
#include "Ax/Window.h"
#include "Ax/GL/VertexArray.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){    
    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE); 
    }

    std::cout << "Key" << std::endl;
}

void framebuffer_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0, width, height);
}

int main(int argc, const char *argv[])
{
    Ax::System::Window window;

    Ax::GL::VertexArray vao;

    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();


        glClearColor(0.1f,0.1f,0.2f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window.getWindow());
        glfwSetKeyCallback(window.getWindow(), key_callback);
    }


    return 0;
}
