#ifndef AX_CAM3D_H
#define AX_CAM3D_H

#include "Ax/Camera/Camera.h"

namespace Ax::Camera {

    class Camera3D
    {
    public:
        Camera3D():
                projection(glm::perspective(
                    glm::radians(45.0f),
                    800.0f / 600.0f,
                    0.1f,
                    1000.0f
                    )),

                view(glm::lookAt(
                    //this->transform.position,
                    glm::vec3(0.0f, 0.0f, 20.0f),
                    glm::vec3(0.0f, 0.0f, 0.0f),
                    glm::vec3(0.0f, 1.0f,0.0f)
                    ))

                // Explicitly set cameras transform.position
                //{0.0f, 0.0f, 100.0f}
              {}

        void update(double delta)
        {
        }

        M4 getProjection() const
        {
            return this->projection;
        }

        M4 getView() const
        {
            return this->view;
        }

        private:
            M4  projection;
            M4  view;

    };
} /* namespace Ax::System::Graphics */


#endif
