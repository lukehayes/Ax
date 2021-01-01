#include "engine.h"

int main(int argc, const char *argv[])
{
    
    CG::Engine Engine;
    Engine.start();


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Engine.getWindow().getWindow() ))
	{
		//glfwGetFramebufferSize(Engine.getWindow().window, Engine.getWindow().width, &Engine.getWindow().height);

		//glViewport(0, 0, width, height);
        //glClearColor(0.0,0.3f,1.0f,1.0f);
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glUseProgram(shader.program);
        //glBindVertexArray(mesh.VAO_ID);

        //glUniformMatrix4fv(glGetUniformLocation(shader.program, "projection"), 1, GL_FALSE, (float*)camera.projection);
		//glUniformMatrix4fv(glGetUniformLocation(shader.program, "view"), 1, GL_FALSE, (float*)camera.view);
        //glUniformMatrix4fv(glGetUniformLocation(shader.program, "model"), 1, GL_FALSE, (float*)model.matrix);
        
        //glDrawArrays(GL_TRIANGLES, 0, mesh.count );

		/* Swap front and back buffers */
		glfwSwapBuffers(Engine.getWindow().getWindow());

		/* Poll for and process events */
		glfwPollEvents();
        /*CG_DestroyModelCube(&cube);*/
	}

    Engine.shutdown();

	return 0;
}
