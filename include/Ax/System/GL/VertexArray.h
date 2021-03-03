#ifndef AX_SYS_GL_VTXARRAY_H
#define AX_SYS_GL_VTXARRAY_H

#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/Common/Types.h"

namespace Ax::System::GL {

    class VertexArray
    {
        public:

                   VertexArray();
                   VertexArray(const std::vector<f32>& verticies, const BufferConfig& config);
                  ~VertexArray();

            void   generate();
            void   bind();
            void   unbind();

            void   setAttribPointers(const BufferConfig& config);
            void   setBufferData(std::vector<f32> verticies, const BufferConfig& config);

        private:
            std::vector<f32> buffer;
            BufferConfig config;
            GLuint id;
            GLuint arrayBufferID;
    };
}

#endif
