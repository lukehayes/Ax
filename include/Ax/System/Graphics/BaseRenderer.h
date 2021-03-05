/**
 * Base Renderer that Ax Renderers should inherit from.
 */
#ifndef AX_SYS_BSREND_H
#define AX_SYS_BSREND_H

#include "Ax/System/Common/glm.h"

namespace Ax::System::Graphics {

    class BaseRenderer
    {
        public:
                        BaseRenderer();
                        ~BaseRenderer();

            virtual void update(double dt) = 0;

        private: 
    };

} /* namespace Ax::System::Graphics */


#endif
