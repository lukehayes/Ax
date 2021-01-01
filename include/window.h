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

            void create();

            inline GLFWwindow* 
            getWindow() { return this->window; }

            inline s32 
            getHeight() { return this->height; }

            inline s32 
            GetWidth() { return this->width; }

        private:
            s32          width = 800;
            s32          height = 600;
            const_str    title = "Game Title";
            GLFWwindow*  window;
            GLFWmonitor* monitor;
    };
}


#endif
