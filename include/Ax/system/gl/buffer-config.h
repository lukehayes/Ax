#ifndef GL_BUFCONFIG_H
#define GL_BUFCONFIG_H

#include "Ax/system/gl/buffer-target.h"
#include "Ax/system/common/types.h"

namespace Ax::System::GL {

    struct BufferConfig
    {
        s32 attributePosition;
        s32 vertexSize;
        s32 vertexStride;
        BufferTarget target;
    };
}


#endif
