#ifndef AX_SYS_WINDOW_H
#define AX_SYS_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Ax/System/Common/Types.h"

namespace Ax::System{

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

#include "Ax/System/Window-inl.h"

#endif
