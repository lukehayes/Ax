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

        /**
         * Update the objects view matrix.
         *
         * @return void
         */
        void update(double delta);

        /**
         * Set the projection matrix for the camera.
         *
         * @param float width
         *
         * @param float height
         *
         * @return void
         */
        void setView(float width, float height);

    };

} /* namespace Ax::System::Graphics */


#endif