#include "engine.h"

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
    Engine::getErrors() {}

    void 
    Engine::getKeyboardInput() {}

    Ax::Window
    Engine::getWindow() const { return this->window; }

} /* namespace Ax */


