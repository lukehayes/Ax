#include "engine.h"
#include "util/log.h"

namespace CG {

    Engine::Engine() {}
    Engine::~Engine() {
        glfwTerminate();
    }
    void Engine::Init(){
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    void 
    Engine::GetErrors() {}

    void 
    Engine::GetKeyboardInput() {}

    void
    Engine::Create()
    {
        /* Initialize the library */
        if (!glfwInit()) { LE("GLFW FAILED TO INITIALIZE", NULL); }

        this->Init();
        this->window = glfwCreateWindow(this->width, this->height, this->title, NULL, NULL);

        glfwMakeContextCurrent(this->window);

        /* Glew MUST be initialized after context creation*/
        GLenum err = glewInit();

        if( GLEW_OK != err )
        {
            fprintf(stderr, "Error: %s \n", glewGetErrorString(err));
        }
    }

} /* namespace CG */


