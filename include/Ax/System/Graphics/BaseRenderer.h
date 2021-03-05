/**
 * Base Renderer that Ax Renderers should inherit from for polymorphism benefits.
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
        private: 
    };

} /* namespace Ax::System::Graphics */


#endif
