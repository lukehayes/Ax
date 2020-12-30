#ifndef CG_WINDOW_H
#define CG_WINDOW_H

#ifdef _WIN32
#define GLEW_STATIC
#endif

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "common/types.h"

namespace CG 
{
    class Window
    {
        public:
            Window();
            ~Window();

            void Create();

            GLFWwindow* GetWindow();

            s32 width = 800;
            s32 height = 600;
            const_str title = "Game Title";
            GLFWwindow* window;
            GLFWmonitor* monitor;
    };
}


#endif
