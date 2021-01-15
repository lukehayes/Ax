#include "Ax/System/Engine.h"
#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferTarget.h"
#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/System/GL/Primitive.h"
#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Graphics/Camera3D.h"
#include "Ax/System/Math/Random.h"

#include <vector>

int main(int argc, const char *argv[])
{

    using namespace Ax::System;
    using namespace Ax::System::GL;
    using namespace Ax::System::Graphics;

    Engine Engine;
    Engine.start();

    Ax::System::GL::VertexArray vao;

    Ax::System::GL::Shader shader(
        "assets/shaders/VSH-Default.glsl",
        "assets/shaders/FSH-Default.glsl"
    );

    Ax::System::GL::BufferConfig config{0,2,0, Ax::System::GL::ARRAY_BUFFER};

    vao.setBufferData({
           -1.0,   1.0,
           -1.0,  -1.0,
            1.0,   1.0,
            1.0,  -1.0,
            }, config);
    vao.setAttribPointers(config);

    Ax::System::GL::VertexArray vao2;
    vao2.setBufferData({
           -1.0,   1.0,
           -1.0,  -1.0,
            1.0,   1.0,
            1.0,  -1.0,
            }, config);
    vao2.setAttribPointers(config);

    //glm::mat4 projection = glm::perspective(
            //glm::radians(45.0f),
            //4.0f/ 3.0f,
            //0.1f,
            //100.0f
    //);

    Camera2D camera;
    Camera3D camera3D;

    glm::mat4 model = glm::mat4(1.0f);

    //glm::translate(model, glm::vec3(0.0f, 0.0f, -40.0f));
    //model = glm::translate(model,  glm::vec3(0.0f, 0.0f, 0.0f));

    float c = 0.0;


    std::vector<glm::vec3> cubePositions(MAX, {0.0f,0.0f,0.0f});

    using namespace Ax::System::Math;

    for(auto &p : cubePositions)
    {
        p.x = Random::randDouble(-10.0f, 100.0f);
        p.y = Random::randDouble(-10.0f, 100.0f);
        p.z = Random::randDouble(-10.0f, 100.0f);
    }


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Engine.window().window() ))
	{

        c += 0.01;

		/* Poll for and process events */
		glfwPollEvents();

		//glfwGetFramebufferSize(Engine.window().window, Engine.window().width, &Engine.window().height);

		//glViewport(0, 0, width, height);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //view = glm::lookAt(
            //glm::vec3(0.0f, 0.0f, 1.0f),
            //glm::vec3(0.0f, 0.0f,0.0f),
            //glm::vec3(0.0f, 1.0f,0.0f)
    //);
    
        camera3D.update(2.0);
        shader.use();
        shader.setMat4("projection", camera3D.projection);
        shader.setMat4("view", camera3D.view);

        vao.bind();

        for(auto &pos : cubePositions)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, pos);
            //model = glm::translate(model,  glm::vec3(std::sin(c) * 10.0f));
            //model = glm::scale(model,  glm::vec3(std::sin(c) * 10.0f));
            model = glm::rotate(model, glm::radians(std::sin(c) * 10.0f), glm::vec3(1.0f, 1.0f, 1.0f));
            shader.setMat4("model", model);
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
        }

        glm::mat4 model = glm::mat4(1.0f);

        //---------------------------------------------------------------------
        // Transformation Order - Translate, Rotate, Scale.
        //---------------------------------------------------------------------
        // model = glm::translate(model, glm::vec3(100.0f, 100.0f, 0.0f));
        // model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0.0f, 0.0f, 1.0f));
        // model = glm::scale(model,  glm::vec3(10.0f));
        //---------------------------------------------------------------------

        //model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        //model = glm::scale(model,  10.0f * glm::vec3(std::cos(c), 10.0f * std::sin(c), 0.0f));
        
        shader.setMat4("model", model);
        //glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);


		/* Swap front and back buffers */
		glfwSwapBuffers(Engine.window().window());
	}

    Engine.shutdown();

	return 0;
}
