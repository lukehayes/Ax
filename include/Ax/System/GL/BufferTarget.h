#ifndef AX_SYS_GL_BUFFER_TARGET_H
#define AX_SYS_GL_BUFFER_TARGET_H

#include <glad/glad.h>

namespace Ax::System::GL
{
    enum BufferTarget
    {
        ARRAY_BUFFER = GL_ARRAY_BUFFER,
        ELEMENT_BUFFER = GL_ELEMENT_ARRAY_BUFFER,
        TEXTURE_BUFFER = GL_TEXTURE_BUFFER
    };

}

#endif
