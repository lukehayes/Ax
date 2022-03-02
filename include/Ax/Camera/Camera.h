#ifndef AX_CAMERA_H
#define AX_CAMERA_H

#include "Ax/Common/Types.h"
//#include "Ax/Component/Transform.h"

namespace Ax::Camera {

    class Camera
    {
        public:
            Camera();
            ~Camera();

            virtual void update(double delta) = 0;

            /**
             * Get the combined projection and view matricies
             * that have been multiplied together.
             *
             * @return glm::mat4
             */
            M4 combined();

            //Properties
            M4  projection;
            M4  view;
            //Transform  transform;
    };

} /* namespace Ax::System::Graphics */


#endif
