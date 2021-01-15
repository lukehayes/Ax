#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Common/glm.h"

#include <iostream>

namespace Ax::System::Graphics {

    Camera2D::Camera2D()
        : projection(glm::ortho(
                0.0f,
                800.0f,
                0.0f,
                600.0f,
                0.1f,
                100.0f
                )),

          view( glm::lookAt(
                glm::vec3(0.0f, 0.0f, 1.0f),
                glm::vec3(0.0f, 0.0f,0.0f),
                glm::vec3(0.0f, 1.0f,0.0f)
                ))
    {}

    Camera2D::~Camera2D(){}

    void   
    Camera2D::update(double dt) 
    {
    }

} /* namespace Ax::System::Graphics */



