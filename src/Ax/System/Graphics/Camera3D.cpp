#include "Ax/System/Graphics/Camera3D.h"
#include "Ax/System/Common/glm.h"

namespace Ax::System::Graphics {

    Camera3D::Camera3D()
        :
            Camera(
                    glm::perspective(
                        glm::radians(45.0f),
                        800.0f / 600.0f,
                        0.1f,
                        1000.0f
                        ),

                    glm::lookAt(
                        this->transform.position,
                        glm::vec3(0.0f, 0.0f, -1.0f),
                        glm::vec3(0.0f, 1.0f,0.0f)
                        ),

                    {0.0f, 0.0f, -10.0f}
                  ){}

    Camera3D::~Camera3D(){}

    /**
     * Update the objects view or projection matrix.
     *
     * @return void
     */
    void Camera3D::update() 
    {
        this->view = glm::lookAt(
                this->transform.position,
                glm::vec3(0.0f, 0.0f, -1.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
            );

        //this->transform.position.x = 100.0f + std::cos(c) * 100.0f;
        //this->transform.position.y = 100.0f + std::sin(c) * 100.0f;
        //this->transform.position.z = -400 + -100.0f + std::sin(c) * 100.0f;
    }

} /* namespace Ax::System::Graphics */



