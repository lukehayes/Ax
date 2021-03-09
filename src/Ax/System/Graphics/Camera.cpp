#include "Ax/System/Graphics/Camera.h"
#include "Ax/System/Common/glm.h"

#include <iostream>

namespace Ax::System::Graphics {

    Camera::Camera() { std::cout << "Camera Base Class" << std::endl; }
    Camera::~Camera(){}

    M4 Camera::combined() { return this->projection * this->view; }

} /* namespace Ax::System::Graphics */



