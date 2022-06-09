#include "Ax/Common/Types.h"
#include "Ax/Window.h"
#include "Ax/GL/Shader.h"
#include "Ax/Mesh/Mesh.h"
#include "Ax/Mesh/CubeMesh.h"
#include "Ax/Renderer/Renderer.h"
#include "Ax/Entity/Entity.h"
#include "Ax/Math/Random.h"
#include "Ax/Camera/Camera3D.h"

int wireframe_mode = false;
constexpr int MAX_PARTICLES = 1000;

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


double mx = 0;
double my = 0;

static void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    mx = xpos;
    my = ypos;
}

// Redraw the window correctly when the window is resized.
void framebuffer_callback(GLFWwindow* window, int width, int height){
    glViewport(0,0, width, height);
}

void genGL(GLUI* vao, GLUI* vbo)
{
    glGenVertexArrays(1, vao);
    glBindVertexArray(*vao);

    glGenBuffers(1, vbo);
    glBindBuffer(GL_ARRAY_BUFFER, *vbo);

    std::vector<float> verts = {
        -0.5, 0.5,
        -0.5, -0.5,
        0.5, 0.5,
        0.5, -0.5
    };

    glEnableVertexAttribArray(0);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verts.size(), verts.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(
            0,
            2,
            GL_FLOAT,
            GL_FALSE,
            0,
            0
            );
}

int main(int argc, const char *argv[])
{
    Ax::System::Window window;
    Ax::Camera::Camera3D camera;
    Ax::Renderer::Renderer renderer;
    Ax::GL::Shader shader;

    GLUI vao;
    GLUI vbo;

    genGL(&vao, &vbo);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, {0,0,-13.0});


    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        camera.update(1.0f);
        model = glm::rotate(model, glm::radians((float)glfwGetTime()), {1,1,1});

        shader.use();
        shader.setMat4("projection", camera.getProjection());
        shader.setMat4("view", camera.getView());
        shader.setMat4("model", model);

        renderer.clear();
        renderer.basicDraw(&vao, shader);
        //glDrawArrays(GL_TRIANGLE_STRIP, 0,4);
        //glDrawArraysInstanced(GL_TRIANGLE_STRIP, 0,4, MAX_PARTICLES);

        glfwSwapBuffers(window.getWindow());
        glfwSetFramebufferSizeCallback(window.getWindow(), framebuffer_callback);
        glfwSetKeyCallback(window.getWindow(), key_callback);
        glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    }


    return 0;
}
