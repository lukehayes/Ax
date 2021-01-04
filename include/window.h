#ifndef AX_WINDOW_H
#define AX_WINDOW_H

#ifdef _WIN32
 #define GLEW_STATIC
#endif

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "common/types.h"

namespace AX {

    class Window
    {
        public:
            Window();
            ~Window();

            void         create();

            GLFWwindow*  getWindow();
            s32          getHeight();
            s32          getWidth();

        private:
            s32          width = 800;
            s32          height = 600;
            const_str    title = "Game Title";
            GLFWwindow*  window;
            GLFWmonitor* monitor;
    };
}

inline GLFWwindow* AX::Window::getWindow() { return this->window; }
inline s32         AX::Window::getHeight() { return this->height; }
inline s32         AX::Window::getWidth() { return this->width; }

#endif
