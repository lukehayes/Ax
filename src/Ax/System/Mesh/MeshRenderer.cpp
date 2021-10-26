#include "Ax/System/Mesh/MeshRenderer.h"
#include "Ax/System/Builder/MeshBuilder.h"

namespace Ax::System::Mesh {

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
            const Ax::System::GL::Shader& shader,
            GL::Primitive primitive
            )
    {
        shader.use();

        static float c = 0.0;
        c += 0.0001;

        // Setup Model
        M4 model = M4(1.0f);
        model = glm::translate(model, entity.transform.position);
        //model = glm::rotate(model, glm::radians(c), entity.transform.position);
        model = glm::scale(model,  glm::vec3(entity.transform.allAxisScale));

        // Send data to shader
        shader.setMat4("projection", this->camera->projection);
        shader.setMat4("view", this->camera->view);
        shader.setMat4("model", model);

        // Draw The Model
        //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glDrawArrays(primitive, 0, 3);
    }


    void MeshRenderer::setCamera(Graphics::Camera* camera)
    {
        this->camera = camera;
    }
}
