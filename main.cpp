#include "Ax/Common/Types.h"
#include "Ax/Window.h"
#include "Ax/GL/Shader.h"
#include "Ax/Mesh/Mesh.h"
#include "Ax/Mesh/CubeMesh.h"
#include "Ax/Renderer/Renderer.h"
#include "Ax/Entity/Entity.h"
#include "Ax/Entity/Entity.h"
#include "Ax/Math/Random.h"

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

    Ax::Mesh::Mesh mesh;
    Ax::GL::BufferConfig conf;
    mesh.vbo.config.attributePosition = 0;
    mesh.vbo.config.vertexStride = 0;
    mesh.vbo.config.vertexSize = 2;
    mesh.vbo.config.target = Ax::GL::BufferTarget::ARRAY_BUFFER;
    mesh.vbo.config.primitive = Ax::GL::Primitive::LINES;
    mesh.vbo.destroy();
    Ax::Renderer::Renderer renderer;
    renderer.add(mesh);

    Ax::Mesh::Mesh mesh2;
    Ax::GL::BufferConfig config;
    mesh2.vbo.config.attributePosition = 0;
    mesh2.vbo.config.vertexStride = 0;
    mesh2.vbo.config.vertexSize = 3;
    mesh2.vbo.config.target = Ax::GL::BufferTarget::ARRAY_BUFFER;
    mesh2.vbo.config.primitive = Ax::GL::Primitive::POINTS;
    mesh2.vertexCount = 36;

    Ax::Mesh::CubeMesh cube;
    mesh2.verticies = cube.getVerticies();

    mesh2.primitive = Ax::GL::Primitive::TRIANGLES;
    renderer.add(mesh2);

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

    std::vector<Ax::Entity::Entity> entities;

    for(int i = 0; i <=1000; i++)
    {
        Ax::Entity::Entity e;
        e.position.x = Ax::Math::Random::randDouble(-10, 1);
        e.position.y = Ax::Math::Random::randDouble(-10, 10);
        e.position.z = -40 + Ax::Math::Random::randDouble(-10, 10);

        e.color.r = Ax::Math::Random::randDouble(0.3, 0.4f);
        e.color.g = Ax::Math::Random::randDouble(0.3, 0.8f);
        e.color.b = Ax::Math::Random::randDouble(0.3, 0.9f);

        entities.push_back(e);
    }

    while (!glfwWindowShouldClose(window.getWindow()))
    {
        /* Poll for and process events */
        glfwPollEvents();

        c += 0.01;

        shader.use();
        //std::cout << glm::to_string(model) << std::endl;

        shader.setMat4("projection", projection);
        shader.setMat4("view", view);

        glClearColor(0.1f,0.1f,0.1f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for(auto& e : entities)
        {
            renderer.drawCube(e, shader, mx, my);
        }

        glfwSwapBuffers(window.getWindow());
        glfwSetKeyCallback(window.getWindow(), key_callback);
        glfwSetCursorPosCallback(window.getWindow(), mouse_callback);
    }


    return 0;
}
