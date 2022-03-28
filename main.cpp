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
    Ax::Camera::Camera3D camera;
    renderer.vaoMap = factory.getVAOMap();


    Ax::GL::Shader shader;

    std::vector<Ax::Entity::Entity> entities;

    float N = 100.0;
    for(int i = 0; i <=MAX_ENTITIES; i++)
    {
        Ax::Entity::Entity e;
        e.position.x = Ax::Math::Random::randDouble(-N,N);
        e.position.y = Ax::Math::Random::randDouble(-N,N);
        e.position.z = Ax::Math::Random::randDouble(-N,N);
        e.color.r = Ax::Math::Random::randDouble(0.1, 0.2f);
        e.color.g = Ax::Math::Random::randDouble(0.3, 0.95f);
        e.color.b = Ax::Math::Random::randDouble(0.3, 0.9f);

        entities.push_back(e);
    }


    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        camera.update(1.0f);

        shader.use();
        shader.setMat4("projection", camera.getProjection());
        shader.setMat4("view", camera.getView());

        renderer.clear();
        for(auto& e : entities)
        {
            renderer.drawCube(e, mx, my);
        }

        glfwSwapBuffers(window.getWindow());
        glfwSetFramebufferSizeCallback(window.getWindow(), framebuffer_callback);
        glfwSetKeyCallback(window.getWindow(), key_callback);
        glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    }


    return 0;
}
