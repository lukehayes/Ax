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
        c += 0.0000001;

        // Setup Model
        M4 model = M4(1.0f);
        model = glm::translate(model, entity.transform.position);
        model = glm::rotate(model, entity.transform.angle + glm::radians(std::sin(c)) * 1000, {1,1,1});
        model = glm::scale(model,  glm::vec3(entity.transform.single_scale));

        // Send data to shader
        shader.setMat4("projection", this->camera->projection);
        shader.setMat4("view", this->camera->view);
        shader.setMat4("model", model);
        shader.setVec3("color", entity.color);

        // Draw The Model
        glDrawArrays(entity.primitive, 0, entity.verticies);
        //glDrawArrays(primitive, 0, 3);
    }


    void MeshRenderer::setCamera(Graphics::Camera* camera)
    {
        this->camera = camera;
    }
}
