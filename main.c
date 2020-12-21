#include "engine.h"
#include "graphics/buffer.h"
#include "graphics/shader.h"
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
/*Buffer buffer;*/

void Setup_OpenGL()
{

    CG_CreateCubeMesh(&mesh);
    /*CG_CreateBuffer((Buffer*)&buffer);*/

    /*LB((Buffer*)&buffer);*/

    CG_CreateShader(&shader, CG_Read_File("assets/shaders/VSH-Default.glsl"), CG_Read_File("assets/shaders/FSH-Default.glsl"));
    

}
int main(int argc, const char *argv[])
{
	Engine e = CG_CreateEngine();

    Setup_OpenGL();



	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	/*glm_ortho(0,800.0f,600.0f, 0, 0.01f, 1000.0f, projection);*/
	glm_perspective(glm_rad(45.0f), 800.0f/600.0f, 0.1, 100.0f, projection);

	mat4 view = GLM_MAT4_IDENTITY_INIT;
	/*glm_translate_make(view, (float[]){0.0f,0.0f,-10.0f} );*/
	glm_lookat((float[]){0.0f, 0.0f, -3.0f}, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, view );

	/*mat4 model = GLM_MAT4_IDENTITY_INIT;*/
	/*vec3 position = GLM_VEC3_ZERO_INIT;*/

    CG_CreateCubeModel(&model);


	model.transform.position[0] = 0.0f;
	model.transform.position[1] = 0.0f;
	model.transform.position[2] = 1.0f;
	glm_translate_make(model.matrix, model.transform.position);

    int range = 20;
    vec3 positions[MAX_MODELS];
    CubeModel models[MAX_MODELS];

    for(int i = 0; i <= MAX_MODELS - 1; i++)
    {
        f32 x = (f32)CG_RandRange(0,range) - (range / 2);
        f32 y = (f32)CG_RandRange(0,range) - (range / 2);
        f32 z = (f32)CG_RandRange(0,range) - (range / 2);

        CubeModel model;
        CG_CreateCubeModel(&model);

        vec3 pos;
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        memcpy(model.transform.position, pos, sizeof(float) * 3);
        models[i] = model;
    }

	static float c = 0.0;

    vec3 scale = GLM_VEC3_ZERO_INIT;
    scale[1] = 1.0f;


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(e.window))
	{
		int width, height;

        c+= 0.001;

        glm_lookat((float[]){cos(c) / 10.0, -43.0f}, (float[]){0.0f,0.0f, 0.0f}, (float[]){0.0f,1.0f,0.0f}, view );


		glfwGetFramebufferSize(e.window, &width, &height);

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(shader.program);
        glBindVertexArray(mesh.VAO_ID);

        glm_rotate(view, glm_rad(c) * 10.0, (float[]) {1,1,1});

		glUniformMatrix4fv(glGetUniformLocation(shader.program, "projection"), 1, GL_FALSE, (float*)projection);
		glUniformMatrix4fv(glGetUniformLocation(shader.program, "view"), 1, GL_FALSE, (float*)view);
        glUniformMatrix4fv(glGetUniformLocation(shader.program, "model"), 1, GL_FALSE, (float*)model.matrix);
        

        for(int i = 0; i <= MAX_MODELS - 1; i++)
        {
            CubeModel model = models[i];
            glm_translate_make(model.matrix, model.transform.position);
            glUniformMatrix4fv(glGetUniformLocation(shader.program, "model"), 1, GL_FALSE, (float*)model.matrix);
            glDrawArrays(GL_LINE_LOOP, 0, mesh.count);
        }

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
