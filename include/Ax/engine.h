#ifndef Ax_ENGINE_H
#define Ax_ENGINE_H

#include "Ax/window.h"

namespace Ax {

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
            Ax::Window getWindow() const;
            
            Ax::Window window;
    };
    
} /* namespace Ax */


#endif
