#ifndef _AX_GAME_H
#define _AX_GAME_H

#include "Ax/System/Common/Types.h"
#include "Ax/System/Engine.h"
#include "Ax/System/Mesh/MeshRenderer.h"
#include "Ax/System/Math/Random.h"
#include "Ax/Engine/Component/TestEntity.h"


namespace Ax::System
{
    using Ax::Engine::Component::TestEntity;

    class Game
    {

        public:
            Game() 
            {
                engine.start();
                engine.initSystems();
            }

            ~Game() 
            {
                engine.shutdown();
            }

            void update() 
            {
                glfwSetTime(glfwGetTime());
                now = glfwGetTime();

                TestEntity te;

                Ax::System::GL::Shader shader(
                        "assets/shaders/VSH-Default.glsl",
                        "assets/shaders/FSH-Default.glsl"
                        );

                // Loop Timing Variables
                static double limitFPS = 1.0 / 60.0;
                double lastTime = glfwGetTime(), timer = lastTime;
                double deltaTime = 0, nowTime = 0;
                int frames = 0 , updates = 0;

                // - While window is alive
                while (!glfwWindowShouldClose(engine.getWindow().window() ))
                {
                    /* Poll for and process events */
                    glfwPollEvents();

                    //---------------------------------------------------------------------
                    // Transformation Order - Translate, Rotate, Scale.
                    //---------------------------------------------------------------------
                    // model = glm::translate(model, glm::vec3(100.0f, 100.0f, 0.0f));
                    // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                    // model = glm::scale(model,  glm::vec3(10.0f));
                    //---------------------------------------------------------------------

                    // - Measure time
                    nowTime = glfwGetTime();
                    deltaTime += (nowTime - lastTime) / limitFPS;
                    lastTime = nowTime;
                    Ax::System::Graphics::Camera3D camera2d;
                    this->renderer.setCamera(&camera2d);

                    // - Only update at 60 frames / s
                    while (deltaTime >= 1.0){
                        //update();   // - Update function

                        camera2d.update(deltaTime);
                        te.update(deltaTime);

                        updates++;
                        deltaTime--;
                    }

                    // - Render at maximum possible frames
                    
                    glClearColor(0.8f,0.8f,0.8f,1.0f);
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                    shader.setVec3("color", te.color);

                    this->renderer.draw(te,shader);

                    //render(); // - Render function
                    frames++;

                    // - Reset after one second
                    if (glfwGetTime() - timer > 1.0) {
                        timer ++;
                        std::cout << "FPS: " << frames << " Updates:" << updates << std::endl;
                        updates = 0, frames = 0;
                    }

                    glfwSwapBuffers(engine.getWindow().window());
                }
            }

            void draw() {}

            Ax::System::Engine engine;
        private:
            double now = 0.0;
            double lastFrame = 0.0;
            double delta = 0.0;
            Ax::System::Mesh::MeshRenderer renderer;
    };

}


#endif
