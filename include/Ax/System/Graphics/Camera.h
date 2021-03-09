#ifndef AX_SYS_CAM_H
#define AX_SYS_CAM_H

#include "Ax/System/Common/glm.h"
#include "Ax/System/Component/Transform.h"

namespace Ax::System::Graphics {

    using namespace Ax::System::Component;

    class Camera
    {
        public:
            Camera();
            Camera(const M4& projection, const M4& view);
            Camera(const M4& projection, const M4& view, const V3& position);
            ~Camera();

            virtual void update() = 0;

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
            Transform  transform;
    };

} /* namespace Ax::System::Graphics */


#endif
