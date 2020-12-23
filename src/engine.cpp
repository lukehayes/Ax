#include "engine.h"
#include "util/log.h"

namespace CG {

    Engine::Engine() {}
    Engine::~Engine() {
        glfwTerminate();
    }
    void 
    Engine::Init(){
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void 
    Engine::GetErrors() {}

    void 
    Engine::GetKeyboardInput() {}

    void
    Engine::Create() {}

    CG::Window
    Engine::GetWindow() const { return this->window; }

} /* namespace CG */


