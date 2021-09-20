#include "Ax/System/Engine.h"
#include "Ax/System/Mesh/MeshBuilder.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include <memory>

namespace Ax::System {

    Engine::Engine() : m_window(800,900) {}
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

        using namespace Ax::System::Mesh;

        // Load data onto the GPU
        const std::shared_ptr<RectangleMesh> mesh = std::make_shared<RectangleMesh>();
        Mesh::MeshBuilder b(mesh);
        b.build();
    }

    void Engine::errors() {}

    void Engine::keyboardInput() {}

    Ax::System::Window
    Engine::getWindow() const { return m_window; }

} /* namespace Ax::System*/


