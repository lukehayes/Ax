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
constexpr int ENT = 10;

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
    Ax::Camera::Camera3D camera;
    Ax::Renderer::Renderer renderer;
    Ax::GL::Shader shader;
    Ax::Entity::Entity e;

    int N = 100;
    std::vector<Ax::Entity::Entity> entities;
    for(int i = 0; i <= MAX_ENTITIES; i++)
    {
        double x = Ax::Math::Random::randDouble(-N,N);
        double y = Ax::Math::Random::randDouble(-N,N);
        double z = Ax::Math::Random::randDouble(-N,N);
        double r = Ax::Math::Random::randDouble(0.5,0.8);
        double g = Ax::Math::Random::randDouble(0.6,0.8);
        double b = Ax::Math::Random::randDouble(0.7,1.0);
        double s = Ax::Math::Random::randDouble(1.0,10.0);

        Ax::Entity::Entity e{{x,y,z}, {r,g,b}};
        e.scale = s;
        //Ax::Entity::Entity e{{x,y,z}};
        entities.push_back(e);
    }

    double currentTime = glfwGetTime();
    double previousTime = 0;
    double delta = 0;
    const double MS_PER_UPDATE = 0.15f;

    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        previousTime = currentTime;
        currentTime = glfwGetTime();
        delta = currentTime - previousTime;

        if(delta > MS_PER_UPDATE)
        {
            delta = MS_PER_UPDATE;
            camera.update(delta);
        }

        //camera.updateFPS(mx,my);
        renderer.clear({0.3,0.3,0.3});
        //renderer.basicDraw(&camera, shader, e, delta);

        for(auto e:entities)
        {
            renderer.basicDraw(&camera, shader, e, delta);
        }

        glfwSwapBuffers(window.getWindow());
        glfwSetFramebufferSizeCallback(window.getWindow(), framebuffer_callback);
        glfwSetKeyCallback(window.getWindow(), key_callback);
        glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    }


    return 0;
}
