#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "common/types.h"

namespace CG {

    class Engine
    {
        public:
            Engine();
            ~Engine();
            void Init();
            void Create();
            void GetErrors();
            void GetKeyboardInput();
            GLFWwindow* GetWindow() const;

        //private:
            s32 width = 800;
            s32 height = 600;
            const_str title = "Game Title";
            GLFWwindow* window;
            GLFWmonitor* monitor;
    };
    
} /* namespace CG */


#endif
