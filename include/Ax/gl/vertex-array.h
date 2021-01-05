#ifndef GL_VTX_ARRAY_H
#define GL_VTX_ARRAY_H

#include "Ax/gl/buffer-config.h"
#include "Ax/common/types.h"

namespace Ax::GL {

    class VertexArray
    {
        public:

            VertexArray();
            ~VertexArray();

            void bind();
            void unbind();

            void addData(std::array<float, 9>verticies, const BufferConfig& config)
            {
                glGenBuffers(1, &this->bufferID);
                glBindBuffer(config.target, this->bufferID);
                glBufferData(config.target, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW );

                glVertexAttribPointer(
                        config.attributePosition,
                        config.vertexSize,
                        GL_FLOAT, 
                        false, 
                        config.vertexStride,
                        0);

                glEnableVertexAttribArray(config.attributePosition);
            }

        private:
            GLuint id;
            GLuint bufferID;


    };
}

#endif
