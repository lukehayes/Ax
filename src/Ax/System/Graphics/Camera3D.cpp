#include "Ax/System/Graphics/Camera3D.h"
#include "Ax/System/Common/glm.h"

#include <iostream>

namespace Ax::System::Graphics {

    Camera3D::Camera3D()
        : projection(glm::perspective(
            glm::radians(45.0f),
            800.0f / 600.0f,
            0.1f,
            100.0f
                )),

          view( glm::lookAt(
                glm::vec3(0.0f, 0.0f, 3.0f),
                glm::vec3(0.0f, 0.0f, -1.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
                ))
    {}

    Camera3D::~Camera3D(){}

    void   
    Camera3D::update(double dt) 
    {
    }

} /* namespace Ax::System::Graphics */



