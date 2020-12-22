#include "engine.h"
#include "graphics/buffer.h"
#include "graphics/shader.h"
#include "graphics/camera.h"
#include "graphics/color.h"
#include "io/io.h"
#include "util/log.h"
#include "util/random.h"
#include "mesh/cube-mesh.h"
#include "model/cube-model.h"
#include "math/cglm-all.h"

#define CGGLM_ALL_UNALIGNED

CubeMesh mesh;
CubeModel model;
Shader shader;
Camera camera;

void Setup_OpenGL()
{
    CG_CreateCubeMesh(&mesh);
    CG_CreateShader(&shader, CG_Read_File("assets/shaders/VSH-Default.glsl"), CG_Read_File("assets/shaders/FSH-Default.glsl"));
}
int main(int argc, const char *argv[])
{
	Engine e = CG_CreateEngine();
    Setup_OpenGL();

    CG_CreateCamera3D(&camera);
    CG_CreateCubeModel(&model);

	static float c = 0.0;
    model.transform.position[2] = cos(c) * -10.0f;
    glm_translate(model.matrix, model.transform.position);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(e.window))
	{
		int width, height;

        c+= 0.01;

        /*model.transform.position[0] = sin(c) * 2.0f;*/
        /*model.transform.position[1] = cos(c) * 2.0f;*/
        /*model.transform.position[2] = cos(c) * 10.0f;*/
        /*glm_translate(model.matrix, model.transform.position);*/

        /*camera.update(&camera, 3.4);*/

		glfwGetFramebufferSize(e.window, &width, &height);

		glViewport(0, 0, width, height);
        glClearColor(0.0,0.3f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader.program);
        glBindVertexArray(mesh.VAO_ID);

        glUniformMatrix4fv(glGetUniformLocation(shader.program, "projection"), 1, GL_FALSE, (float*)camera.projection);
		glUniformMatrix4fv(glGetUniformLocation(shader.program, "view"), 1, GL_FALSE, (float*)camera.view);
        glUniformMatrix4fv(glGetUniformLocation(shader.program, "model"), 1, GL_FALSE, (float*)model.matrix);
        
        glDrawArrays(GL_TRIANGLES, 0, mesh.count );

		/* Swap front and back buffers */
		glfwSwapBuffers(e.window);

		/* Poll for and process events */
		glfwPollEvents();
        /*CG_DestroyModelCube(&cube);*/
	}
   
    /*CG_DestroyBuffer(&mesh);*/
	glfwTerminate();
	return 0;
}
