#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Common/glm.h"

#include <iostream>

namespace Ax::System::Graphics {

    Camera2D::Camera2D()
        : Camera(glm::ortho(
                0.0f,
                800.0f,
                600.0f,
                0.0f,
                0.1f,
                1000.0f
                ),

                glm::lookAt(
                    glm::vec3(0.0, 0.0, 0.0), // Position
                    glm::vec3(0, 0, 0), // Look at direction
                    glm::vec3(0, 1, 0) // Y is UP
                )

                )
    {}

    Camera2D::~Camera2D(){}

    void   
    Camera2D::update() 
    {
        std::cout << "2D" << std::endl;
        static float c = 0.0f;
        c += 0.01;

        this->transform.position.x = -50;
        this->transform.position.y = 0;
        this->transform.position.z = 0;

        this->view = glm::lookAt(
                this->transform.position,
                glm::vec3(0.0f, 0.0f, -10.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
            );
    }

} /* namespace Ax::System::Graphics */



