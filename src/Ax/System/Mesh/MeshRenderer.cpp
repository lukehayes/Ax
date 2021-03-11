#include "Ax/System/Mesh/MeshRenderer.h"

namespace Ax::System::Mesh {

    MeshRenderer::MeshRenderer() 
    {
        //---------------------------------------------------------------------
        // Shader, VertexArray/Buffer Setup.
        //---------------------------------------------------------------------
        this->Shader = GL::Shader(
                "assets/shaders/VSH-Default.glsl",
                "assets/shaders/FSH-Default.glsl"
                );

    }

    MeshRenderer::~MeshRenderer() {
        LOG("Renderer Destoryed!", "Buffer ID:", this->Mesh.BufferObject.id);
    }

    void MeshRenderer::draw(f32 x, f32 y, f32 w = 1, f32 h = 1)
    {
        LOG("Vertex Count", this->Mesh.vertexCount);
        M4 model = M4(1.0f);
        static float c = 0.0f;
        c += 0.1;
        this->Mesh.VertexArray.bind();
        this->Shader.use();

        this->Camera.transform.position().z = std::sin(c) * 100.0f;
        
        //this->Shader.setMat4("view", this->Camera.view);
        this->Shader.setVec3("color", glm::vec3(1,1,1));

        model = glm::translate(model, glm::vec3(x,y, 0.0f));
        //model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        //model = glm::scale(model,  glm::vec3(10.0f));

        this->Shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    }
    void MeshRenderer::draw(int x, int y)
    {
        M4 model = M4(1.0f);
        static float c = 0.0f;
        c += 0.01;
        this->Mesh.VertexArray.bind();
        this->Shader.use();

        this->Camera.transform.position().x = 100.0f + std::cos(c) * 100.0f;
        this->Camera.transform.position().y = 100.0f + std::sin(c) * 100.0f;
        this->Camera.transform.position().z = -100.0f + std::sin(c) * 100.0f;
        this->Camera.update();
        
        this->Shader.setMat4("projection", this->Camera.projection);
        this->Shader.setMat4("view", this->Camera.view);
        this->Shader.setVec3("color", glm::vec3(1,1,1));

        model = glm::translate(model, glm::vec3(x,y, 0.0f));
        //model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        //model = glm::scale(model,  glm::vec3(10.0f));

        this->Shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

}
