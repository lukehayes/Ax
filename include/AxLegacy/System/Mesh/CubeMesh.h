/*
 * =====================================================================================
 *
 *        Class:  CubeMesh
 *
 *  Description:  A Cube Mesh defines how the mesh is describes so that the
 *                GPU can interpret it correctly.
 *
 * =====================================================================================
 */
#ifndef AX_SYS_CUBEMESH_H
#define AX_SYS_CUBEMESH_H

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

    class CubeMesh : public IMesh
    {
        public:
            CubeMesh()
                : verticies{

                    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
                        -1.0f,-1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f, // triangle 1 : end
                        1.0f, 1.0f,-1.0f, // triangle 2 : begin
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f,-1.0f, // triangle 2 : end
                        1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f,-1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f,-1.0f,
                        -1.0f, 1.0f,-1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f

                },
                config({0,3,0, Ax::System::GL::ARRAY_BUFFER, Primitive::TRIANGLE_STRIP }),
                vertexCount(verticies.size())
                {}

            ~CubeMesh(){}

            friend std::ostream& operator<<(std::ostream& stream, CubeMesh const& mesh)
            {
                stream << "Cube Mesh ";
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
