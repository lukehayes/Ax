/**
 * A simple instance of a rectangle, using
 * GL_TRIANGLE_FAN.
 */
#ifndef AX_SYS_RECTMESH_H
#define AX_SYS_RECTMESH_H

#include "Ax/System/Mesh/IMesh.h"
#include <glad/glad.h>
#include "Ax/System/Common/Types.h"

namespace Ax::System::Mesh {

    class RectangleMesh : public IMesh
    {
    public:
        RectangleMesh(){

            this->config = {0,2,0, Ax::System::GL::ARRAY_BUFFER};

            this->verticies = {
                    -1.0, 1.0,
                    -1.0, -1.0,
                    1.0, 1.0,
                    1.0, -1.0
            };

            this->vertexCount = this->verticies.size();
        }
        ~RectangleMesh(){}


        std::vector<f32> verticies;
        GL::BufferConfig config;
        s32 vertexCount;
    };
}

#endif
