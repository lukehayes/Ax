#include "Ax/Camera/Camera3D.h"

extern double mx;
extern double my;
namespace Ax::Camera {

    Camera3D::Camera3D():
                projection(glm::perspective(
                    glm::radians(45.0f),
                    800.0f / 600.0f,
                    0.1f,
                    1000.0f
                    )),

                view(glm::lookAt(
                    glm::vec3(0.0f, 0.0f, 20.0f),
                    glm::vec3(0.0f, 0.0f, 0.0f),
                    glm::vec3(0.0f, 1.0f,0.0f)
                    ))

                // Explicitly set cameras transform.position
                //{0.0f, 0.0f, 100.0f}
              {}

        Camera3D::~Camera3D() {}

        void Camera3D::updateFPS(double x, double y)
        {
            V3 direction = {0,0,0};
            double SENSITIVITY = 0.00000000001;

            direction.x = cos(glm::radians(x)) * cos(glm::radians(y));
            direction.y = sin(glm::radians(y));
            direction.z = sin(glm::radians(x)) * cos(glm::radians(y));

            //std::cout << front.x << "||" << front.y << std::endl;

            this->view = glm::lookAt(
                this->transform.position,
                direction,
                glm::vec3(0.0f, 1.0f,0.0f)
                );

        }

        void Camera3D::update(double delta)
        {
            static float c = 0.0;

            c += 0.01;

            this->transform.position.x = std::cos(c) * 100;
            this->transform.position.y = std::cos(c) * 100;
            this->transform.position.z = std::sin(c) * 100;


            this->view = glm::lookAt(
                this->transform.position,
                glm::vec3(0.0f, 0.0f, 0.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
                );
        }

        M4 Camera3D::getProjection() const
        {
            return this->projection;
        }

        M4 Camera3D::getView() const
        {
            return this->view;
        }
} /* namespace Ax::System::Graphics */

