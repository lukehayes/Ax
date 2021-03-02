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
    using namespace Ax::System::Math;

    //---------------------------------------------------------------------
    // Engine Initialization.
    //---------------------------------------------------------------------
    Engine Engine;
    Engine.start();

    //---------------------------------------------------------------------
    // Shader, VertexArray/Buffer Setup.
    //---------------------------------------------------------------------
    Ax::System::GL::Shader shader(
        "assets/shaders/VSH-Default.glsl",
        "assets/shaders/FSH-Default.glsl"
    );
    
    Ax::System::GL::BufferConfig config{0,2,0, Ax::System::GL::ARRAY_BUFFER};

    Ax::System::GL::VertexArray vao({
       -1.0,   1.0,
       -1.0,  -1.0,
        1.0,   1.0,
        1.0,  -1.0
    }, config);

    //---------------------------------------------------------------------
    // Camera Setup.
    //---------------------------------------------------------------------
    Camera2D camera;
    Camera3D camera3D;

    glm::mat4 model = glm::mat4(1.0f);

    float c = 0.0;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Engine.window().window() ))
	{
        c += 0.1;

		/* Poll for and process events */
		glfwPollEvents();

		//glViewport(0, 0, width, height);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        camera3D.update(2.0);

        vao.bind();
        shader.use();
        shader.setMat4("projection", camera3D.projection);
        shader.setMat4("view", camera3D.view);
        shader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);

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
