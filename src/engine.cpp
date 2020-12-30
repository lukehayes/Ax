#include "engine.h"

namespace CG {

    Engine::Engine() {}
    Engine::~Engine() {
    }

    void
    Engine::Start()
    {
        glfwInit();
    }

    void
    Engine::Shutdown()
    {
        glfwTerminate();
    }

    void 
    Engine::GetErrors() {}

    void 
    Engine::GetKeyboardInput() {}

    CG::Window
    Engine::GetWindow() const { return this->window; }

} /* namespace CG */


