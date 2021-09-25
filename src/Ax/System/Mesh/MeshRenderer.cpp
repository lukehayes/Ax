#include "Ax/System/Mesh/MeshRenderer.h"
#include "Ax/System/Mesh/MeshBuilder.h"

namespace Ax::System::Mesh {
     
    using Ax::System::Graphics::Camera;

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

    MeshRenderer::~MeshRenderer() {}

    void MeshRenderer::draw(f32 x, f32 y, f32 w = 1, f32 h = 1)
    {
        //LOG("Vertex Count", this->Mesh.vertexCount);
        M4 model = M4(1.0f);
        static float c = 0.0f;
        c += 0.1;


        this->Shader.use();

        this->Camera.transform.position.z = std::sin(c) * 100.0f;
        
        //this->Shader.setMat4("view", this->Camera.view);
        this->Shader.setVec3("color", glm::vec3(1,1,1));

        model = glm::translate(model, glm::vec3(x,y, 0.0f));
        //model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        //model = glm::scale(model,  glm::vec3(10.0f));

        this->Shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    }

    void MeshRenderer::draw(int x, int y, const Ax::System::Graphics::Camera& camera )
    {
        // This method should only be concerned with rendering
        // All shader, camera and unrelated code should be
        // abstracted out into respected classes.


        M4 model = M4(1.0f);
        static float c = 0.0f;
        c += 0.001;

        //Ax::System::Mesh::RectangleMesh mesh;
        //Ax::System::Mesh::MeshBuilder builder(std::make_shared<IMesh>(mesh));
        //builder.build();


        this->Shader.use();
        this->Camera.update();
        
        // All of this should be moved to Camera class.
        this->Shader.setMat4("projection", this->Camera.projection);
        this->Shader.setMat4("view", this->Camera.view);
        this->Shader.setVec3("color", glm::vec3(0.6,0.0,.9));

        model = glm::translate(model, glm::vec3(x,y, 0.0f));
        //model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        model = glm::scale(model,  glm::vec3(1.0f));

        this->Shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }

    void MeshRenderer::draw(int x, int y, const Ax::System::GL::Shader& shader )
    {
        shader.use();
        this->Camera.update();

        std::cout << shader.vertexSource << std::endl;

        // All of this should be moved to Camera class.
        shader.setMat4("projection", this->Camera.projection);
        shader.setMat4("view", this->Camera.view);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }
}
