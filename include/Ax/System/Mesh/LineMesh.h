/*
 * =====================================================================================
 *
 *        Class:  LineMesh
 *
 *  Description:  A Line Mesh defines how the mesh is describes so that the
 *                GPU can interpret it correctly.
 *
 * =====================================================================================
 */

#ifndef AX_SYS_LINEMESH_H
#define AX_SYS_LINEMESH_H

#include "Ax/System/Mesh/IMesh.h"
#include <glad/glad.h>
#include "Ax/System/Common/Types.h"
#include "Ax/System/GL/BufferConfig.h"

namespace Ax::System::Mesh {

    class LineMesh : public IMesh
    {
    public:
        LineMesh()
            : verticies{
                 0.5, 0.0,
                -0.5, 0.0
            },
            config({0,2,0, Ax::System::GL::ARRAY_BUFFER}),
            vertexCount(verticies.size())
        {}

        friend std::ostream& operator<<(std::ostream& stream, LineMesh const& mesh)
        {
            stream << "Line Mesh ";
            return stream;
        }

        ~LineMesh(){}


        std::vector<f32> verticies;
        GL::BufferConfig config;
        s32 vertexCount;
    };
}

#endif
