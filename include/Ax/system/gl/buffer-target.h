#ifndef BUFFER_TARGET_H
#define BUFFER_TARGET_H

#include <GLEW/glew.h>

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
