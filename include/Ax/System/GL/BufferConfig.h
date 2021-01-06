#ifndef AX_SYS_GL_BUFCONFIG_H
#define AX_SYS_GL_BUFCONFIG_H

#include "Ax/System/GL/BufferTarget.h"
#include "Ax/System/Common/Types.h"

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
