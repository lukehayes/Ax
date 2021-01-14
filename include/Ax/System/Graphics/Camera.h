#ifndef AX_SYS_CAM_H
#define AX_SYS_CAM_H

#include "Ax/System/Common/glm.h"
#include "Ax/System/Component/Transform.h"

namespace Ax::System::Graphics {

    using namespace Ax::System::Compontent;

    class Camera
    {
        public:
                   Camera();
                  ~Camera();
        
        Transform transform;

        private: 
    };
    
} /* namespace Ax::System*/


#endif
