#ifndef AX_SYS_GL_PRIMITIVE_H
#define AX_SYS_GL_PRIMITIVE_H

#include <glad/glad.h>

namespace Ax::System::GL
{
    /**
     * Enum that defines all of the primitive rendering types.
     */
    enum Primitive
    {
        POINTS         = GL_POINTS,
        TRIANGLES      = GL_TRIANGLES,
        LINES          = GL_LINES,
        LINE_STRIP     = GL_LINE_STRIP,
        LINE_LOOP      = GL_LINE_LOOP,
        TRIANGLE_FAN   = GL_TRIANGLE_FAN,
        TRIANGLE_STRIP = GL_TRIANGLE_STRIP
    };
}

#endif
