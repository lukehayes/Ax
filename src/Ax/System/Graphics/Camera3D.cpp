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
                        glm::vec3(0.0f, 0.0f, 0.0f),
                        glm::vec3(0.0f, 1.0f,0.0f)
                        ),

                    // Explicitly set cameras transform.position
                    {0.0f, 0.0f, 10.0f}
                  ){

            }

    Camera3D::~Camera3D(){}

    /**
     * Update the objects view or projection matrix.
     *
     * @return void
     */
    void Camera3D::update() 
    {
        static float c = 0.0f;
        c += 0.01;

        //this->transform.position.x = 100.0f + std::cos(c) * 100.0f;
        //this->transform.position.y = 100.0f + std::sin(c) * 100.0f;
        //this->transform.position.z = -100.0f + std::cos(c) * 100.0f;
        
        this->view = glm::lookAt(
                this->transform.position,
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
            );
    }

} /* namespace Ax::System::Graphics */



