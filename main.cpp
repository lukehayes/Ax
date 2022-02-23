#include "Ax/Common/Types.h"
#include "Ax/Window.h"
#include "Ax/GL/Shader.h"
#include "Ax/Mesh/Mesh.h"
#include "Ax/Renderer/Renderer.h"

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
    glm::translate(model, {0,0,-10});

    Ax::Mesh::Mesh mesh;
    Ax::Renderer::Renderer renderer;
    //renderer.add(mesh);

    Ax::Mesh::Mesh mesh2;
    Ax::GL::BufferConfig config;
    config.vertexSize = 3;
    //config.vertexCount = 36;
    mesh2.verticies = {
                    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
                        -1.0f,-1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f, // triangle 1 : end
                        1.0f, 1.0f,-1.0f, // triangle 2 : begin
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f,-1.0f, // triangle 2 : end
                        1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f,-1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f,-1.0f,
                        -1.0f, 1.0f,-1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f};

    mesh2.primitive = Ax::GL::Primitive::TRIANGLES;
    renderer.add(mesh2, config);
    


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

    Ax::GL::Shader shader(
        "assets/shaders/VSH-Default.glsl",
        "assets/shaders/FSH-Default.glsl"
    );

    shader.setMat4("model", model);
    shader.setMat4("projection", projection);
    shader.setMat4("view", view);

    static float c = 0.0;
    model = glm::translate(model, {0,0,-10.0});
    
    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        c += 0.01;

        shader.use();
        shader.setVec3("color", {0.7,0.9,0.4});
        model = glm::rotate(model, glm::radians(std::sin(c)), {1,1,1});
        //glm::translate(model, {std::cos(c) * 100, std::sin(c) * 100, -std::sin(c) * 100});
        //std::cout << glm::to_string(model) << std::endl;

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);
        shader.setMat4("model", model);

        glClearColor(0.1f,0.1f,0.1f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        renderer.draw();

        glfwSwapBuffers(window.getWindow());
        glfwSetKeyCallback(window.getWindow(), key_callback);
    }


    return 0;
}
