/*
 * =====================================================================================
 *
 *        Class:  RectangleMesh
 *
 *  Description:  A Rectangle Mesh defines how the mesh is describes so that the
 *                GPU can interpret it correctly.
 *
 * =====================================================================================
 */
#ifndef AX_SYS_RECTMESH_H
#define AX_SYS_RECTMESH_H

#include "Ax/System/Mesh/IMesh.h"
#include <glad/glad.h>
#include "Ax/System/Common/Types.h"
#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/GL/Primitive.h"

namespace Ax::System::Mesh {

    using Ax::System::GL::VertexArray;
    using Ax::System::GL::BufferObject;
    using Ax::System::GL::Primitive;

    class RectangleMesh : public IMesh
    {
    public:
        RectangleMesh()
            : verticies{
                -1.0, 1.0,
                -1.0, -1.0,

                1.0, 1.0,
                1.0, -1.0
            },
            config({0,2,0, Ax::System::GL::ARRAY_BUFFER, Primitive::TRIANGLE_STRIP }),
            vertexCount(verticies.size())
        {}

        ~RectangleMesh(){}

        friend std::ostream& operator<<(std::ostream& stream, RectangleMesh const& mesh)
        {
            stream << "Rectangle Mesh ";
            return stream;
        }

        std::vector<f32> verticies;
        GL::BufferConfig config;
        s32 vertexCount;
        GL::VertexArray vertexArray;
        GL::BufferObject bufferObject;
    };
}

#endif
