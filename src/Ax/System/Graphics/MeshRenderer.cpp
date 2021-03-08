
#include "Ax/System/Graphics/MeshRenderer.h"

namespace Ax::System::Graphics {

    MeshRenderer::MeshRenderer() 
    {
        //---------------------------------------------------------------------
        // Shader, VertexArray/Buffer Setup.
        //---------------------------------------------------------------------
        this->Shader = GL::Shader(
                "assets/shaders/VSH-Default.glsl",
                "assets/shaders/FSH-Default.glsl"
                );

        GL::BufferConfig config{0,2,0, Ax::System::GL::ARRAY_BUFFER};

        this->VertexArray.bind();
        this->BufferObject = GL::BufferObject({
                -1.0, 1.0,
                -1.0, -1.0,
                1.0, 1.0,
                1.0, -1.0
                }, config);
    }

    MeshRenderer::~MeshRenderer() {
        LOG("Renderer Destoryed!", "Buffer ID:", this->BufferObject.id);
    }

    void MeshRenderer::draw(int x, int y)
    {
        M4 model = M4(1.0f);
        static float c = 0.0f;
        c += 0.1;
        this->VertexArray.bind();
        this->Shader.use();

        this->Camera.transform.position().z = std::sin(c) * 100.0f;
        
        this->Shader.setMat4("projection", this->Camera.projection);
        this->Shader.setMat4("view", this->Camera.view);
        this->Shader.setVec3("color", glm::vec3(1,1,1));

        model = glm::rotate(model, glm::radians(c/10.0f), glm::vec3(1.0f, 1.0f, 1.0f));

        this->Shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
    }

}
