#include "engine.h"
#include "graphics/buffer.h"
#include "io/io.h"
#include "util/log.h"
#include "model/cube-model.h"
#include "math/cglm-all.h"

GLuint vertex_array, vertex_buffer, vertex_shader, fragment_shader, program;
GLint mvp_location, vpos_location, vcol_location;
CubeModel buffer;
/*Buffer buffer;*/

float randRange(int min, int max)
{
    return rand() % (min + 1 - max) + min;
}

void Error_Callback(int error, const char* description)
{
	printf("Error: \n");
	fprintf(stderr, "Error: %s\n", description);
}

void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}


void Setup_OpenGL()
{
	/*const int BUFFER_SIZE = sizeof(float) * 18 * 6;*/
	/*const int VERTEX_SIZE = sizeof(float) * 0;*/
	const char* vsh_source = CG_Read_File("assets/shaders/VSH-Default.glsl");
	const char* fsh_source = CG_Read_File("assets/shaders/FSH-Default.glsl");

    CG_CreateModelCube((CubeModel*)&buffer);
    /*CG_CreateBuffer((Buffer*)&buffer);*/

	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);

	glGenBuffers(1, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);

    LSI("Sizeof : ", sizeof(buffer.verticies));
    LSI("Bytes loaded: ", buffer.vertexBytes);
    LSI("Vertex Count: ", buffer.vertexCount);
    LSI("Stride: ", buffer.stride);

	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * buffer.vertexCount, buffer.verticies, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, buffer.stride, (void*)0 );

	unsigned int vertex_shader, fragment_shader;
	int success;
	char infoLog[512];

	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vsh_source, NULL);
	glCompileShader(vertex_shader);

	// print compile errors if any
	glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		LE("Vertex Shader Compilation Failed", infoLog);
	};

	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fsh_source, NULL);
	glCompileShader(fragment_shader);

	// print compile errors if any
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		LE("Fragment Shader Compilation Failed", infoLog);
	};

	program = glCreateProgram();

	glAttachShader(program, vertex_shader);
	glAttachShader(program, fragment_shader);
	glLinkProgram(program);

	glGetShaderiv(program, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(vertex_shader, 512, NULL, infoLog);
		printf("Linking Shader Failed. %s \n", infoLog);
	};

	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	L("Shaders Loaded. All fine.");

	free((char*)vsh_source);
	free((char*)fsh_source);

}

int main(void)
{

	Engine e = CG_CreateEngine();

	glfwSetErrorCallback(Error_Callback);

	/* Get Key Input*/
	glfwSetKeyCallback(e.window, Key_Callback);

	Setup_OpenGL();

	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	/*glm_ortho(0,800.0f,600.0f, 0, 0.01f, 1000.0f, projection);*/
	glm_perspective(glm_rad(45.0f), 800.0f/600.0f, 0.1, 100.0f, projection);

	mat4 view = GLM_MAT4_IDENTITY_INIT;
	/*glm_translate_make(view, (float[]){0.0f,0.0f,-10.0f} );*/
	glm_lookat((float[]){0.0f, 0.0f, -3.0f}, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, view );

	mat4 model = GLM_MAT4_IDENTITY_INIT;
	vec3 position = GLM_VEC3_ZERO_INIT;



	position[0] = 0.0f;
	position[1] = 0.0f;
	position[2] = 1.0f;
	glm_translate_make(model, position);

    int range = 10;
    vec3 positions[MAX_MODELS];

    for(int i = 0; i <= MAX_MODELS - 1; i++)
    {
        float x = randRange(0,range) - (range / 2);
        float y = randRange(0,range) - (range / 2);
        float z = randRange(0,range) - (range / 2);

        vec3 pos;
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        memcpy(positions[i], pos, sizeof(float) * 3);
    }

	/*vec3 positions[] = {*/
		/*{ 0.0f,  0.0f,  0.0f}, */
		/*{ 2.0f,  5.0f, -15.0f}, */
		/*{-1.5f, -2.2f, -2.5f},  */
		/*{-3.8f, -2.0f, -12.3f},  */
		/*{ 2.4f, -0.4f, -3.5f},  */
		/*{-1.7f,  3.0f, -7.5f},  */
		/*{ 1.3f, -2.0f, -2.5f},  */
		/*{ 1.5f,  2.0f, -2.5f}, */
		/*{ 1.5f,  0.2f, -1.5f}, */
		/*{-1.3f,  1.0f, -1.5f}  */
	/*};*/

	static float c = 0.0;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(e.window))
	{
		int width, height;

        c+= 0.1;

        glm_lookat((float[]){0.0f, 0.0f, -33.0}, (float[]){0.0f,0.0f, 0.0f}, (float[]){0.0f,1.0f,0.0f}, view );


		glfwGetFramebufferSize(e.window, &width, &height);

		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(program);
		glBindVertexArray(vertex_array);

        glm_rotate(view, glm_rad(c), (float[]) {1,1,1});

		glUniformMatrix4fv(glGetUniformLocation(program, "projection"), 1, GL_FALSE, (float*)projection);
		glUniformMatrix4fv(glGetUniformLocation(program, "view"), 1, GL_FALSE, (float*)view);
		glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, (float*)model);

        glDrawArrays(GL_TRIANGLES, 0, buffer.vertexCount);

        for(int i = 0; i <= MAX_MODELS - 1; i++)
        {
            mat4 model = GLM_MAT4_IDENTITY_INIT;
            glm_translate_make(model, positions[i]);
            glUniformMatrix4fv(glGetUniformLocation(program, "model"), 1, GL_FALSE, (float*)model);
            glDrawArrays(GL_LINES, 0, buffer.vertexCount);
        }


		/* Swap front and back buffers */
		glfwSwapBuffers(e.window);

		/* Poll for and process events */
		glfwPollEvents();
        /*CG_DestroyModelCube(&cube);*/
	}
   
    /*CG_DestroyBuffer(&buffer);*/
	glfwTerminate();
	return 0;
}
