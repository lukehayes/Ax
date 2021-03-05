
#include "Ax/System/Graphics/MeshRenderer.h"

namespace Ax::System::Graphics {

    MeshRenderer::MeshRenderer() 
    {
        //---------------------------------------------------------------------
        // Shader, VertexArray/Buffer Setup.
        //---------------------------------------------------------------------
        this->shader = GL::Shader(
                "assets/shaders/VSH-Default.glsl",
                "assets/shaders/FSH-Default.glsl"
                );

        GL::BufferConfig config{0,2,0, Ax::System::GL::ARRAY_BUFFER};

        this->vertexArray.bind();
        this->bufferObject = GL::BufferObject({
                -1.0, 1.0,
                -1.0, -1.0,
                1.0, 1.0,
                1.0, -1.0
                }, config);
    }

    MeshRenderer::~MeshRenderer() {}

    void MeshRenderer::draw(int x, int y)
    {
        M4 model = M4(1.0f);
        static float c = 0.0f;
        c += 0.1;
        this->shader.use();
        this->vertexArray.bind();
        this->shader.setMat4("projection", this->camera.projection);
        this->shader.setMat4("view", this->camera.view);
        this->shader.setVec3("color", glm::vec3(1,1,1));
        model = glm::rotate(model, glm::radians(c/10.0f), glm::vec3(1.0f, 1.0f, 1.0f));

        this->shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

}
