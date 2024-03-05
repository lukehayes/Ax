#ifndef AX_TRANSFORH_H
#define AX_TRANSFORH_H

#include "Ax/Common/Types.h"

namespace Ax::Component {

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
    f32 allAxisScale = 10.0f;
    f32 angle = 0.0;
    f32 single_scale = 1.0f;
};
}

#endif
