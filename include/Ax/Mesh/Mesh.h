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

            virtual Ax::GL::VertexArray getVertexArray() = 0;
            virtual Ax::GL::VertexBuffer getVertexBuffer() = 0;
            virtual int getVertexCount() = 0;
            virtual void init() = 0;
            virtual VecFloat getVerticies() = 0;
    };
}



#endif // AX_MESH_H

