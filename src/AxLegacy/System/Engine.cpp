#include "Ax/System/Engine.h"
#include "Ax/System/Builder/MeshBuilder.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include "Ax/System/Mesh/LineMesh.h"
#include <memory>

namespace Ax::System {

    Engine::Engine() : m_window(800,600) {}
    Engine::~Engine() {}

    void Engine::start()
    {
        glfwInit();
    }

    void Engine::shutdown()
    {
        glfwTerminate();
    }

    void Engine::initSystems()
    {
        // Initalize all of the systems that
        // Ax needs - MeshBuilders etc.

        using namespace Ax::System::Builder;

        // Load data onto the GPU
        Builder::MeshBuilder b;
        b.build();
    }

    void Engine::errors() {}

    void Engine::keyboardInput() {}

    Ax::System::Window
    Engine::getWindow() const { return m_window; }

} /* namespace Ax::System*/


