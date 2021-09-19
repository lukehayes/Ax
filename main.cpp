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

    double now = 0.0;
    double lastFrame = 0.0;
    double delta = 0.0;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(Engine.window().window() ))
    {
        /* Poll for and process events */
        glfwPollEvents();

        glfwSetTime(glfwGetTime());
        now = glfwGetTime();

        //glViewport(0, 0, width, height);
        glClearColor(0.8f,0.8f,0.8f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Renders on 2D Camera
        for(int i = 0; i <= 10; i++)
        {
            Renderer.draw(200 + std::sin(i) * 10,  200 + i * 10, 10,10);
        }

        // Renders on 3D Camera
        for(int i = 0; i <= 50; i++)
        {
            Renderer.draw(std::cos(i) * 100, std::sin(i) * 100);

            Renderer.draw(
                    Ax::System::Math::Random::randDouble(0.0, 200.0),
                    Ax::System::Math::Random::randDouble(0.0, 200.0)
            );
        }

        //---------------------------------------------------------------------
        // Transformation Order - Translate, Rotate, Scale.
        //---------------------------------------------------------------------
        // model = glm::translate(model, glm::vec3(100.0f, 100.0f, 0.0f));
        // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        // model = glm::scale(model,  glm::vec3(10.0f));
        //---------------------------------------------------------------------

        lastFrame = glfwGetTime();

        delta = lastFrame - now;

        std::cout << delta << std::endl;

        /* Swap front and back buffers */
        glfwSwapBuffers(Engine.window().window());
    }

    Engine.shutdown();

    return 0;
}
