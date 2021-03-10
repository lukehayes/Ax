/**
 * A simple instance of a rectangle, using
 * GL_TRIANGLE_FAN.
 */
#ifndef AX_SYS_RECTMESH_H
#define AX_SYS_RECTMESH_H

#include "Ax/System/GL/IMesh.h"
#include <glad/glad.h>
#include "Ax/System/Common/Types.h"
#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/GL/BufferTarget.h"
#include "Ax/System/GL/BufferConfig.h"

namespace Ax::System::GL {

    class RectangleMesh : public IMesh
    {
    public:
        RectangleMesh(){

            GL::BufferConfig config{0,2,0, Ax::System::GL::ARRAY_BUFFER};

            this->VertexArray.bind();
            this->BufferObject = GL::BufferObject({
                    -1.0, 1.0,
                    -1.0, -1.0,
                    1.0, 1.0,
                    1.0, -1.0
                    }, config);

            this->vertexCount = this->BufferObject.data.size();
        }
        ~RectangleMesh(){}


        GL::VertexArray VertexArray;
        GL::BufferObject BufferObject;
        GL::BufferConfig BufferConfig;
        s32 vertexCount;
    };
}

#endif
