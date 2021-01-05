#ifndef GL_BUFCONFIG_H
#define GL_BUFCONFIG_H

#include "Ax/gl/buffer-target.h"
#include "Ax/common/types.h"

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
