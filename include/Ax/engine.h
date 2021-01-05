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

            void       errors();
            void       keyboardInput();
            Ax::Window window() const;

        private: 
            Ax::Window m_window;
    };
    
} /* namespace Ax */


#endif
