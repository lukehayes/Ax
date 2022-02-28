#ifndef AX_MESH_H
#define AX_MESH_H

#include <vector>
#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/GL/BufferTarget.h"
#include "Ax/GL/Primitive.h"

namespace Ax::Mesh
{
    class Mesh
    {
    public:
        Mesh() {}
        ~Mesh() {}

        virtual void init() = 0;
    };
}



#endif // AX_MESH_H

