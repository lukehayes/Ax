#include "Ax/engine.h"

namespace Ax {

    Engine::Engine() {}
    Engine::~Engine() {
    }

    void
    Engine::start()
    {
        glfwInit();
    }

    void
    Engine::shutdown()
    {
        glfwTerminate();
    }

    void 
    Engine::errors() {}

    void 
    Engine::keyboardInput() {}

    Ax::Window
    Engine::window() const { return m_window; }

} /* namespace Ax */


