#include "Ax/engine.h"
#include "Ax/gl/vertex-array.h"
#include "Ax/gl/buffer-target.h"
#include "Ax/gl/buffer-config.h"
#include "Ax/gl/shader.h"

int main(int argc, const char *argv[])
{

    Ax::Engine Engine;
    Engine.start();

    Ax::GL::VertexArray vao;

    Ax::GL::Shader shader(
        "assets/shaders/VSH-Default.glsl",
        "assets/shaders/FSH-Default.glsl"
    );

    Ax::GL::BufferConfig config{0,2,0, Ax::GL::ARRAY_BUFFER};

    vao.setBufferData({
           -1.0,   1.0,
           -1.0,  -1.0,
            1.0,   1.0,
            1.0,  -1.0,
            }, config);
    vao.setAttribPointers(config);

    Ax::GL::VertexArray vao2;
    vao2.setBufferData({
           -1.0,   1.0,
           -1.0,  -1.0,
            1.0,   1.0,
            1.0,  -1.0,
            }, config);
    vao2.setAttribPointers(config);

    glm::mat4 projection = glm::perspective(
            glm::radians(45.0f),
            4.0f/ 3.0f,
            0.1f,
            100.0f
    );

    glm::mat4 view = glm::lookAt(
            glm::vec3(0.0f, 0.0f, -3.0f),
            glm::vec3(0.0f, 0.0f,0.0f),
            glm::vec3(0.0f, 1.0f,0.0f)
    );

    glm::mat4 model = glm::mat4(1.0f);

    //glm::translate(model, glm::vec3(0.0f, 0.0f, -40.0f));

    float c = 0.0;


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Engine.window().window() ))
	{

        c += 0.1;

		/* Poll for and process events */
		glfwPollEvents();

		//glfwGetFramebufferSize(Engine.window().window, Engine.window().width, &Engine.window().height);

		//glViewport(0, 0, width, height);
        glClearColor(0.0,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
        shader.use();
        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        vao.bind();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model,  glm::vec3(std::cos(c), std::sin(c), 11.0f));
        model = glm::rotate(model, glm::radians(45.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);

        model = glm::mat4(1.0f);
        model = glm::translate(model,  glm::vec3(-2.0f, 0.0f, 30.0f + std::sin(c) * 11.0f));
        model = glm::rotate(model, glm::radians(c * 100), glm::vec3(1.0f, 1.0f, 1.0f));
        shader.setMat4("model", model);
        glDrawArrays(GL_LINE_STRIP, 0, 8);



		/* Swap front and back buffers */
		glfwSwapBuffers(Engine.window().window());
	}

    Engine.shutdown();

	return 0;
}
