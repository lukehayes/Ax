/*
 * =====================================================================================
 *
 *        Class:  Engine
 *
 *  Description:  Where Ax begins.
 *
 * =====================================================================================
 */
#ifndef AX_SYS_ENGINE_H
#define AX_SYS_ENGINE_H

#include "Ax/System/Window.h"

namespace Ax::System {

    class Engine
    {
        public:
            Engine();
            ~Engine();

            void initSystems();
            void start();
            void shutdown();

            void errors();
            void keyboardInput();

            Ax::System::Window window() const;

        private: 
            Ax::System::Window m_window;
    };

} /* namespace Ax::System*/


#endif
