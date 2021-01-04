#include "engine.h"

namespace AX {

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

    AX::Window
    Engine::getWindow() const { return this->window; }

} /* namespace AX */


