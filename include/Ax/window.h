#ifndef Ax_WINDOW_H
#define Ax_WINDOW_H

#ifdef _WIN32
 #define GLEW_STATIC
#endif

#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "Ax/common/types.h"

namespace Ax {

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

#include "Ax/window-inl.h"

#endif
