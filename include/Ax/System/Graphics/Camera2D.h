#ifndef AX_SYS_CAM2D_H
#define AX_SYS_CAM2D_H

#include "Ax/System/Graphics/Camera.h"

namespace Ax::System::Graphics {

    class Camera2D : public Camera
    {
        public:
                   Camera2D();
                  ~Camera2D();

            void   update();


        Transform  transform;
        M4  projection;
        M4  view;

        private: 

    };
    
} /* namespace Ax::System::Graphics */


#endif
