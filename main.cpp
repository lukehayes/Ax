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
#include "Ax/System/Graphics/MeshRenderer.h"
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

    MeshRenderer Renderer;


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Engine.window().window() ))
	{
		/* Poll for and process events */
		glfwPollEvents();

		//glViewport(0, 0, width, height);
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        Renderer.draw(1,1, 10,10);
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
