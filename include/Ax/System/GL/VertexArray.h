#ifndef AX_SYS_GL_VTXARRAY_H
#define AX_SYS_GL_VTXARRAY_H

#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/Common/Types.h"

namespace Ax::System::GL {

    class VertexArray
    {
        public:

                   VertexArray();
                   VertexArray(std::vector<f32> verticies, const BufferConfig& config);
                  ~VertexArray();

            void   bind();
            void   unbind();

            void   setAttribPointers(const BufferConfig& config);
            void   setBufferData(std::vector<f32> verticies, const BufferConfig& config);

        private:
            GLuint m_id;
            GLuint m_ArrayBufferID;
            std::vector<f32> m_buffer;
    };
}

#endif
