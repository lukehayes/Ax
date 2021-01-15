#ifndef AX_SYS_CAM3D_H
#define AX_SYS_CAM3D_H

#include "Ax/System/Graphics/Camera.h"

namespace Ax::System::Graphics {

    class Camera3D : public Camera
    {
        public:
                   Camera3D();
                  ~Camera3D();

            void   update(double dt);

        Transform  transform;
        glm::mat4  projection;
        glm::mat4  view;

        private: 

    };
    
} /* namespace Ax::System::Graphics */


#endif
