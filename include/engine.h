#ifndef _CG_ENGINE_H
#define _CG_ENGINE_H

#ifdef _WIN32
#define GLEW_STATIC
#endif
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "common/types.h"
#include "window.h"

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

            CG::Window GetWindow() const;

            CG::Window window;
    };
    
} /* namespace CG */


#endif
