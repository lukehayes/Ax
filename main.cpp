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

int main(int argc, const char *argv[])
{
    Ax::System::Window window;
    Ax::Mesh::MeshFactory factory;

    Ax::Renderer::Renderer renderer;
    renderer.vaoMap = factory.getVAOMap();


    Ax::Camera::Camera3D camera;
    Ax::GL::Shader shader;

    Ax::Entity::Entity e({0,0,0});
    e.color = {0.2,0.2,0.2};
    e.scale = 5;

    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        //camera.update(1.0f);

        shader.use();
        shader.setMat4("projection", camera.getProjection());
        shader.setMat4("view", camera.getView());

        renderer.clear();
        renderer.drawCube(e);

        glfwSwapBuffers(window.getWindow());
        glfwSetFramebufferSizeCallback(window.getWindow(), framebuffer_callback);
        glfwSetKeyCallback(window.getWindow(), key_callback);
        glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    }


    return 0;
}
