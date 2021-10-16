#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Common/glm.h"

#include <iostream>

namespace Ax::System::Graphics {

    Camera2D::Camera2D()
        : Camera(glm::ortho(
                0.0f,
                800.0f,
                0.0f,
                600.0f,
                0.1f,
                100.0f
                ),

                glm::lookAt(
                    glm::vec3(0.0, 0.0, 3.0), // Position
                    glm::vec3(0, 0, 0), // Look at direction
                    glm::vec3(0, 1, 0) // Y is UP
                )

                )
    {}

    void Camera2D::setView(float width, float height) 
    {
        std::cout << "Set View Called." << std::endl;
        this->projection = glm::ortho(0.0f, width, 0.0f, height, 0.1f, 1000.0f);
    }

    Camera2D::~Camera2D(){}

    void   
    Camera2D::update() 
    {
        this->view = glm::translate(this->view, this->transform.position);
    }

} /* namespace Ax::System::Graphics */



