#ifndef GL_VTX_ARRAY_H
#define GL_VTX_ARRAY_H

#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/Common/Types.h"

namespace Ax::System::GL {

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
