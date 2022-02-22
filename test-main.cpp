#include "Ax/Common/Types.h"
#include "Ax/Window.h"
#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferTarget.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/GL/Shader.h"
#include <glm/gtx/string_cast.hpp>

int wireframe_mode = false;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){    

    if ((key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q) && action == GLFW_PRESS){
        glfwSetWindowShouldClose(window, GL_TRUE); 
    }

    // Toggle wireframe mode with the LEFT SHIFT KEY
    if ((key == GLFW_KEY_LEFT_SHIFT) && action == GLFW_PRESS && ! wireframe_mode){
        wireframe_mode = true;
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    }else
    {
        wireframe_mode = false;
        glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
    }
}

void framebuffer_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0, width, height);
}

int main(int argc, const char *argv[])
{
    Ax::System::Window window;

    glm::mat4 projection = glm::mat4(1.0);
    glm::mat4 view = glm::mat4(1.0);
    glm::mat4 model = glm::mat4(1.0);
    glm::translate(model, {0,0,-100});


    projection = glm::perspective(
        glm::radians(45.0f),
        800.0f / 600.0f,
        0.1f,
        1000.0f
        );

    view = glm::lookAt(
        glm::vec3(0.0f, 0.0f, 3.0f),
        glm::vec3(0.0f, 0.0f, -1.0f),
        glm::vec3(0.0f, 1.0f,0.0f)
        );


    Ax::GL::BufferConfig config;
    config.attributePosition = 0;
    config.vertexSize = 3;
    config.vertexStride = 0;
    config.target = Ax::GL::BufferTarget::ARRAY_BUFFER;

    Ax::GL::VertexArray vao;
    vao.generate();
    vao.bind();


    std::vector<float> verticies;

    int MAX = 10;

    for(float i = 0; i<=MAX; i++)
    {
        for(float j = 0; j<=MAX; j++)
        {
            for(float k = 0; k<=MAX; k++)
            {
                float x = i * 10;
                float y = j * 20;
                float z = k * 10;

                verticies.push_back(x);
                verticies.push_back(y);
                verticies.push_back(z);
            }
        }
    }

    Ax::GL::VertexBuffer vbo;
    vbo.config = config;
    vbo.generate();
    vbo.bind(Ax::GL::BufferTarget::ARRAY_BUFFER);
    vbo.setBufferData(verticies);
    vbo.setAttribPointers();


    Ax::GL::Shader shader(
        "assets/shaders/VSH-Default.glsl",
        "assets/shaders/FSH-Default.glsl"
    );

    shader.setMat4("model", model);
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    static float c = 0.0;
    model = glm::translate(model, {0,0,-200});
    
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        c += 0.01;

        shader.use();
        shader.setVec3("color", {0.4,0.7,0.3});
        model = glm::rotate(model, glm::radians(std::sin(c)), {1,1,1});
        //glm::translate(model, {std::cos(c) * 100, std::sin(c) * 100, -std::sin(c) * 100});
        
        //std::cout << glm::to_string(model) << std::endl;

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        shader.setMat4("model", model);

        glClearColor(0.1f,0.1f,0.1f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        glDrawArrays(GL_LINE_STRIP, 0,verticies.size());

        glfwSwapBuffers(window.getWindow());
        glfwSetKeyCallback(window.getWindow(), key_callback);
    }


    return 0;
}
