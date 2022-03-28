#ifndef AX_BUFCONFIG_H
#define AX_BUFCONFIG_H

#include "Ax/GL/BufferTarget.h"
#include "Ax/GL/Primitive.h"
#include "Ax/Common/Types.h"

namespace Ax::GL {

    struct BufferConfig
    {
        s32 attributePosition;
        s32 vertexSize;
        s32 vertexStride;
        BufferTarget target;
    };
}


#endif
