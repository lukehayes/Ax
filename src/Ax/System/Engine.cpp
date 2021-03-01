#include "Ax/System/Engine.h"

namespace Ax::System{

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

    Ax::System::Window
    Engine::window() const { return m_window; }

} /* namespace Ax::System*/


