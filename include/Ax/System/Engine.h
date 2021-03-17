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

            /**
             * Initalize all of the systems that Ax needs in place to
             * be able to run. Example - Loading all of the data
             * into the GPU. Needs to be refactored.
             */
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
