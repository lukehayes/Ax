/**
 * Base Renderer that Ax Renderers should inherit from for polymorphism benefits.
 */
#ifndef AX_SYS_BSREND_H
#define AX_SYS_BSREND_H

#include "Ax/System/Common/Types.h"
#include "Ax/System/Graphics/Camera.h"

namespace Ax::System::Graphics {

    using Ax::System::Graphics::Camera;

    class BaseRenderer
    {
        public:
            /**
             * Draw from the data loaded in the BufferObject
             * currently bound to the VertexArray.
             *
             * @param int x The x position.
             * @param int y The y position.
             *
             * @return void.
             */
            virtual void draw(int x, int y, const Camera* camera ) = 0;

        private: 
    };

} /* namespace Ax::System::Graphics */


#endif
