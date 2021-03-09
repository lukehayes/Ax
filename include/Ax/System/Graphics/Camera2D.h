#ifndef AX_SYS_CAM2D_H
#define AX_SYS_CAM2D_H

#include "Ax/System/Graphics/Camera.h"

namespace Ax::System::Graphics {

    class Camera2D : public Camera
    {
    public:

        /**
         * Default Constructor
         */
        Camera2D();

        /**
         * Destructor
         */
        ~Camera2D();

        void update();

    };

} /* namespace Ax::System::Graphics */


#endif
