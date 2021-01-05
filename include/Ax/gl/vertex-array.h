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

            void   bind();
            void   unbind();

            void   setAttribPointers(const BufferConfig& config);
            void   setBufferData(std::array<f32, 8>verticies, const BufferConfig& config);

        private:
            GLuint m_id;
            GLuint m_bufferID;


    };
}

#endif
