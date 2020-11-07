#ifdef LINUX
#include <GL/gl3.h>
#elif _WIN32
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>
#include "graphics/buffer.h"
#include "engine.h"

int main(void)
{

    Engine e = CG_CreateEngine();

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    // Initialize GLFW Context etc
    e.init();

    /* Create a windowed mode window and its OpenGL context */
    e.window = glfwCreateWindow(e.width, e.height, e.title, NULL, NULL);
    if (!e.window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(e.window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(e.window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.0f,0.3f, 0.8f, 1.0f);


        /* Swap front and back buffers */
        glfwSwapBuffers(e.window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
