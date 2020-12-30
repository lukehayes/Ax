#include "engine.h"

namespace CG {

    Engine::Engine() {}
    Engine::~Engine() {
        glfwTerminate();
    }

    void
    Engine::Start()
    {
        // TODO
    }

    void
    Engine::Shutdown()
    {
        // TODO
    }

    void 
    Engine::GetErrors() {}

    void 
    Engine::GetKeyboardInput() {}

    CG::Window
    Engine::GetWindow() const { return this->window; }

} /* namespace CG */


