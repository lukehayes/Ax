#ifndef CG_ENGINE_H
#define CG_ENGINE_H

#include "window.h"

namespace CG {

    class Engine
    {
        public:
            Engine();
            ~Engine();

            void init();

            void start();
            void shutdown();

            void getErrors();
            void getKeyboardInput();

            CG::Window getWindow() const;

            CG::Window window;
    };
    
} /* namespace CG */


#endif
