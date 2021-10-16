#include "Ax/System/Graphics/Camera.h"
#include "Ax/System/Common/glm.h"

#include <iostream>

namespace Ax::System::Graphics {

    Camera::Camera() : 
        projection(1.0f),
        view(1.0f)
    { std::cout << "Camera Base Class" << std::endl; }



    Camera::Camera(const M4& projection, const M4& view)
        : projection(projection),
          view(view),
          transform()
    {}

    Camera::Camera(const M4& projection, const M4& view, const V3& position)
        : projection(projection),
          view(view),
          transform(transform)
    {}

    Camera::~Camera(){}

    M4 Camera::combined() { return this->projection * this->view; }

} /* namespace Ax::System::Graphics */



