#include "Ax/System/Mesh/MeshRenderer.h"
#include "Ax/System/Mesh/MeshBuilder.h"
#include "Ax/System/Graphics/Camera2D.h"

namespace Ax::System::Mesh {
     
    using Ax::System::Graphics::Camera;
    using Ax::System::Graphics::Camera2D;

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

    //void MeshRenderer::draw(f32 x, f32 y, f32 w = 1, f32 h = 1)
    //{
        ////LOG("Vertex Count", this->Mesh.vertexCount);
        //M4 model = M4(1.0f);
        //static float c = 0.0f;
        //c += 0.1;


        //shader.use();

        //this->Camera.transform.position.z = std::sin(c) * 100.0f;
        
        ////shader.setMat4("view", this->Camera.view);
        //shader.setVec3("color", glm::vec3(1,1,1));

        //model = glm::translate(model, glm::vec3(x,y, 0.0f));
        ////model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        ////model = glm::scale(model,  glm::vec3(10.0f));

        //shader.setMat4("model", model);

        //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    //}

    //void MeshRenderer::draw(int x, int y, glm::vec3 color)
    //{
        //// This method should only be concerned with rendering
        //// All shader, camera and unrelated code should be
        //// abstracted out into respected classes.

        //M4 model = M4(1.0f);
        //static float c = 0.0f;
        //c += 0.001;

        ////Ax::System::Mesh::RectangleMesh mesh;
        ////Ax::System::Mesh::MeshBuilder builder(std::make_shared<IMesh>(mesh));
        ////builder.build();

        //shader.use();
        
        //// All of this should be moved to Camera class.
        //shader.setMat4("projection", this->camera->projection);
        //shader.setMat4("view", this->camera->view);
        //shader.setVec3("color", color);

        //model = glm::translate(model, glm::vec3(x,y, 0.0f));
        ////model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        ////model = glm::scale(model,  glm::vec3(10.0f));

        //shader.setMat4("model", model);

        //glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    //}

    void MeshRenderer::draw(int x, int y, const Ax::System::GL::Shader& shader )
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

        shader.use();
        
        // All of this should be moved to Camera class.
        shader.setMat4("projection", this->camera->projection);
        shader.setMat4("view", this->camera->view);
        shader.setVec3("color", {1,0,1});

        model = glm::translate(model, glm::vec3(x,y, 0.0f));
        //model = glm::rotate(model, glm::radians(c*5.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        //model = glm::scale(model,  glm::vec3(10.0f));

        shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    }


    void MeshRenderer::setCamera(Graphics::Camera* camera)
    {
        this->camera = camera;
    }
}
