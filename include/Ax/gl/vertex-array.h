#ifndef GL_VTX_ARRAY_H
#define GL_VTX_ARRAY_H

#include "buffer-target.h"
#include "Ax/common/types.h"

namespace Ax::GL {

    class VertexArray
    {
        public:

            VertexArray();
            ~VertexArray();

            void bind();
            void unbind();

            void addData(Array3f verticies, BufferTarget target)
            {
                glGenBuffers(1, &this->bufferID);
                glBindBuffer(target, this->bufferID);

                glBufferData(target, sizeof(float) * verticies.size(), verticies.data(), GL_STATIC_DRAW );



            }

        private:
            GLuint id;
            GLuint bufferID;


    };
}

#endif
