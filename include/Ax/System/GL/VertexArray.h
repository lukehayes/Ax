#ifndef AX_SYS_GL_VTXARRAY_H
#define AX_SYS_GL_VTXARRAY_H

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
            GLuint m_ArrayBufferID;
            Array8f m_buffer;
    };
}

#endif
