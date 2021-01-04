#ifndef AX_ENGINE_H
#define AX_ENGINE_H

#include "window.h"

namespace AX {

    class Engine
    {
        public:
            Engine();
            ~Engine();

            void       init();
            void       start();
            void       shutdown();

            void       getErrors();
            void       getKeyboardInput();
            AX::Window getWindow() const;

            AX::Window window;
    };
    
} /* namespace AX */


#endif
