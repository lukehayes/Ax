#ifndef CG_ENGINE_H
#define CG_ENGINE_H

#include "window.h"

namespace CG {

    class Engine
    {
        public:
            Engine();
            ~Engine();

            void Init();

            void Start();

            void Shutdown();

            void GetErrors();

            void GetKeyboardInput();

            CG::Window GetWindow() const;

            CG::Window window;
    };
    
} /* namespace CG */


#endif
