#include "engine.h"

namespace CG {

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
    Engine::getErrors() {}

    void 
    Engine::getKeyboardInput() {}

    CG::Window
    Engine::getWindow() const { return this->window; }

} /* namespace CG */


