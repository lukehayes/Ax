#include "Ax/System/Graphics/Camera3D.h"
#include "Ax/System/Common/glm.h"

namespace Ax::System::Graphics {

    Camera3D::Camera3D()
        : 
            transform(),
            projection(glm::perspective(
            glm::radians(45.0f),
            800.0f / 600.0f,
            0.1f,
            1000.0f
                )),

          view( glm::lookAt(
                this->transform.position(),
                glm::vec3(0.0f, 0.0f, -1.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
                ))
    {}

    Camera3D::~Camera3D(){}

    void   
    Camera3D::update(double dt) 
    {
        static float c = 0.0f;
        float x = this->transform.position().x;
        float y = this->transform.position().y;
        float z = this->transform.position().z;

        c += 0.1;

        this->transform.position().x = std::cos(c) * 200.0f;
        this->transform.position().y = std::cos(c) * 200.0f;
        this->transform.position().z = std::sin(c) * 200.0f;

        this->view = glm::lookAt(
            this->transform.position(),
            glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3(0.0f, 1.0f,0.0f)
        );
    }

} /* namespace Ax::System::Graphics */



