#ifndef _AX_GAME_H
#define _AX_GAME_H

#include "Ax/System/Common/Types.h"
#include "Ax/System/Engine.h"

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



};

#endif
