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

            GLFWwindow*  window();
            s32          height();
            s32          width();

        private:
            s32          m_width = 800;
            s32          m_height = 600;
            const_str    m_title = "Game Title";
            GLFWwindow*  m_window;
            GLFWmonitor* m_monitor;
    };
}

#include "Ax/window-inl.h"

#endif
