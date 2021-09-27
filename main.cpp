#include "Ax/System/Engine.h"
#include "Ax/System/Game.h"
#include "Ax/System/Common/Log.h"
#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/GL/BufferTarget.h"
#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/System/GL/Primitive.h"
#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Graphics/Camera3D.h"
#include "Ax/System/Mesh/MeshRenderer.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include "Ax/System/Math/Random.h"
#include "Ax/System/Mesh/MeshBuilder.h"

#include <vector>
#include <memory>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){    
   if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
       glfwSetWindowShouldClose(window, GL_TRUE); 
   }
}

void framebuffer_callback(GLFWwindow* window, int width, int height){    
    glViewport(0,0, width, height);
}

int main(int argc, const char *argv[])
{
    using namespace Ax::System;
    using namespace Ax::System::GL;
    using namespace Ax::System::Graphics;
    using namespace Ax::System::Mesh;
    using namespace Ax::System::Math;

    Game game;

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
