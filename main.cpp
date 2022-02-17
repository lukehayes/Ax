#include "Ax/System/Engine.h"
#include "Ax/System/Game.h"
#include "Ax/System/Builder/MeshInitializer.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){    
   if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS){
       glfwSetWindowShouldClose(window, GL_TRUE); 
   }
}

void framebuffer_callback(GLFWwindow* window, int width, int height){    
    glViewport(0,0, width, height);
}

int main(int argc, const char *argv[])
{
    using namespace Ax::System;
    using Ax::System::Mesh::RectangleMesh;
    using Ax::System::Mesh::LineMesh;

    Game game;

    RectangleMesh mesh;
    GL::VertexArray vao;
    vao.generate();
    vao.bind();

    GL::BufferObject vbo(mesh.verticies, mesh.config);
    vbo.generate();
    vbo.bind();


    glfwSetKeyCallback(game.engine.getWindow().window(), key_callback);
    glfwSetFramebufferSizeCallback(game.engine.getWindow().window(), framebuffer_callback);

    game.update();

    //---------------------------------------------------------------------
    // Engine Initialization.
    //---------------------------------------------------------------------

        //---------------------------------------------------------------------
        // Transformation Order - Translate, Rotate, Scale.
        //---------------------------------------------------------------------
        // model = glm::translate(model, glm::vec3(100.0f, 100.0f, 0.0f));
        // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        // model = glm::scale(model,  glm::vec3(10.0f));
        //---------------------------------------------------------------------
        //

    return 0;
}
