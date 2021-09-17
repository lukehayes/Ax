#include "Ax/System/Engine.h"
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

int main(int argc, const char *argv[])
{
    using namespace Ax::System;
    using namespace Ax::System::GL;
    using namespace Ax::System::Graphics;
    using namespace Ax::System::Mesh;
    using namespace Ax::System::Math;

    //---------------------------------------------------------------------
    // Engine Initialization.
    //---------------------------------------------------------------------
    Engine Engine;
    Engine.start();

    MeshRenderer Renderer;

    Engine.initSystems();
   
    glfwSetKeyCallback(Engine.window().window(), key_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(Engine.window().window() ))
    {
        /* Poll for and process events */
        glfwPollEvents();

        //glViewport(0, 0, width, height);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(int i = 0; i <= 10; i++)
        {
            Renderer.draw(200 + std::sin(i) * 10,  200 + i * 10, 10,10);
        }

        Renderer.draw(1,1, 10.0f, 10.0f);
        Renderer.draw(11,11);
        Renderer.draw(100,100);
        Renderer.draw(200,200);

        //---------------------------------------------------------------------
        // Transformation Order - Translate, Rotate, Scale.
        //---------------------------------------------------------------------
        // model = glm::translate(model, glm::vec3(100.0f, 100.0f, 0.0f));
        // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        // model = glm::scale(model,  glm::vec3(10.0f));
        //---------------------------------------------------------------------

        /* Swap front and back buffers */
        glfwSwapBuffers(Engine.window().window());
    }

    Engine.shutdown();

    return 0;
}
