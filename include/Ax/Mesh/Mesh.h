#ifndef AX_MESH_H
#define AX_MESH_H

#include <vector>
#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/GL/BufferTarget.h"

namespace Ax::Mesh
{
    class Mesh
    {
    public:
        Mesh() : verticies({
            -1.0, 1.0,
            -1.0, -1.0,
            1.0, 1.0,
            1.0, -1.0
            })
        {}
        ~Mesh() {}

        void init()
        {
            this->vao.generate();
            this->vao.bind();

            this->config.attributePosition = 0;
            this->config.vertexSize = 2;
            this->config.vertexStride = 0;
            this->config.target = Ax::GL::BufferTarget::ARRAY_BUFFER;

            this->vbo.config = config;
            this->vbo.generate();
            this->vbo.bind(Ax::GL::BufferTarget::ARRAY_BUFFER);
            this->vbo.setBufferData(this->verticies);
            this->vbo.setAttribPointers();
        }

        std::vector<float> verticies;
        Ax::GL::VertexArray vao;
        Ax::GL::VertexBuffer vbo;
        Ax::GL::BufferConfig config;

    };
}



#endif // AX_MESH_H

