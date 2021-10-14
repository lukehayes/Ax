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

                float r = Ax::System::Math::Random::randDouble(0,1);
                float g = Ax::System::Math::Random::randDouble(0,1);
                float b = Ax::System::Math::Random::randDouble(0,1);

                /* Loop until the user closes the window */
                while (!glfwWindowShouldClose(engine.getWindow().window() ))
                {
                    /* Poll for and process events */
                    glfwPollEvents();

                    glfwSetTime(glfwGetTime());
                    this->now = glfwGetTime();

                    //glViewport(0, 0, width, height);
                    glClearColor(0.8f,0.8f,0.8f,1.0f);
                    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


                    //---------------------------------------------------------------------
                    // Transformation Order - Translate, Rotate, Scale.
                    //---------------------------------------------------------------------
                    // model = glm::translate(model, glm::vec3(100.0f, 100.0f, 0.0f));
                    // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
                    // model = glm::scale(model,  glm::vec3(10.0f));
                    //---------------------------------------------------------------------

                    static float c = 0.0f;
                    c += 0.001;
                    float speed = 100000;

                    Ax::System::Graphics::Camera2D camera2d;
                    this->renderer.setCamera(&camera2d);
                    camera2d.update();

                    te.update(delta);
                    te.transform.position.x = 100;
                    te.transform.position.y = 100;
                    te.transform.position.z = -5.0;
                    shader.setVec3("color", te.color);

                    this->renderer.draw(te,shader);

                    //---------------------------------------------------------------------
                    //---------------------------------------------------------------------
                    //---------------------------------------------------------------------
                    //Ax::System::Graphics::Camera2D camera2d;
                    //this->renderer.setCamera(&camera2d);
                    //camera2d.update();

                    //for (int i = 0; i < 10; i++) {
                        //for (int j = 0; j < 10; j++) {
                            //M4 model = M4(1.0f);
                            //model = glm::translate(model, glm::vec3(i * 100.0, j * 100.0, 0.0f));
                            //model = glm::scale(model,  glm::vec3(1.0f));
                            //shader.setVec3("color", {0.4,0,1});
                            //shader.setMat4("model", model);
                            //this->renderer.draw(i * 100.0, j * 100.0, shader);
                        //}
                    //}

                    //Ax::System::Graphics::Camera3D camera3d;
                    //this->renderer.setCamera(&camera3d);

                    //camera3d.transform.position.x = 100.0f + std::cos(c) * 100.0f;
                    //camera3d.transform.position.y = 100.0f + std::sin(c) * 100.0f;
                    //camera3d.transform.position.z = -400 + -100.0f + std::sin(c) * 100.0f;

                    //camera3d.update();

                    //for (int i = 0; i < 10; i++) {
                        //for (int j = 0; j < 10; j++) {
                            //M4 model = M4(1.0f);
                            //model = glm::translate(model, glm::vec3(i * 100.0, j * 100.0, 0.0f));
                            //model = glm::scale(model,  glm::vec3(10.0f));
                            //shader.setMat4("model", model);
                            //shader.setVec3("color", {r,b,g});
                            //this->renderer.draw(i * 100.0, j * 100.0, shader);
                        //}
                    //}

                    //---------------------------------------------------------------------
                    //---------------------------------------------------------------------
                    //---------------------------------------------------------------------

                    //Ax::System::Graphics::Camera3D camera;
                    //camera.update();

                    //this->renderer.setCamera(&camera);


                    //for (int i = 0; i < 10; i++) {
                    //for (int j = 0; j < 10; j++) {
                    //this->renderer.draw(i * 20, j * 20, {0.5,0,1});
                    //}
                    //}

                    this->lastFrame = glfwGetTime();
                    this->delta = lastFrame - now;

                    /* Swap front and back buffers */
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
