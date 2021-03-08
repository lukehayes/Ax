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
                        ~Camera();

            virtual void update() = 0;

        private: 
    };

} /* namespace Ax::System::Graphics */


#endif
