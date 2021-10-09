#ifndef AX_COMPONENT_TRANSFORH
#define AX_COMPONENT_TRANSFORH

#include "Ax/System/Common/Types.h"

namespace Ax::System::Component {

    class Transform
    {
        public:
               Transform():
                   position(0.0f, 0.0f, 0.0f),
                   rotation(0.0f, 0.0f, 0.0f),
                   scale(10.0f, 10.0f, 10.0f)
               {}

               Transform(const V3& position):
                   position(position),
                   rotation(0.0f, 0.0f, 0.0f),
                   scale(10.0f, 10.0f, 10.0f)
               {}

               ~Transform(){}

            V3 position;
            V3 rotation;
            V3 scale;
    };
}

#endif
