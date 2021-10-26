#include "Ax/System/Mesh/MeshRenderer.h"
#include "Ax/System/Builder/MeshBuilder.h"
#include "Ax/System/Graphics/Camera2D.h"

namespace Ax::System::Mesh {
     
    using Ax::System::Graphics::Camera;
    using Ax::System::Graphics::Camera2D;

    MeshRenderer::MeshRenderer() {}

    MeshRenderer::~MeshRenderer() {}

    void MeshRenderer::draw(int x, int y, const Ax::System::GL::Shader& shader )
    {
        shader.use();
        
        // All of this should be moved to Camera class.
        shader.setMat4("projection", this->camera->projection);
        shader.setMat4("view", this->camera->view);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    void MeshRenderer::draw(
            const Ax::Engine::Component::TestEntity& entity,
            const Ax::System::GL::Shader& shader )
    {
        shader.use();

        // Setup Model
        M4 model = M4(1.0f);
        model = glm::translate(model, entity.transform.position);
        model = glm::rotate(model, glm::radians(90.0f), entity.transform.position);
        model = glm::scale(model,  glm::vec3(entity.transform.allAxisScale));

        // Send data to shader
        shader.setMat4("projection", this->camera->projection);
        shader.setMat4("view", this->camera->view);
        shader.setMat4("model", model);

        // Draw The Model
        //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glDrawArrays(GL_LINES, 0, 2);
    }


    void MeshRenderer::setCamera(Graphics::Camera* camera)
    {
        this->camera = camera;
    }
}
