#ifndef AX_CAM3D_H
#define AX_CAM3D_H

#include "Ax/Camera/Camera.h"
#include "Ax/Component/Transform.h"

namespace Ax::Camera {

    class Camera3D
    {
    public:
        Camera3D();
        ~Camera3D();

        void update(double delta);

        M4 getProjection() const;
        M4 getView() const;

        void updateFPS(double x, double y);

        Ax::Component::Transform transform;

        private:
            M4  projection;
            M4  view;
    };
} /* namespace Ax::System::Graphics */


#endif
