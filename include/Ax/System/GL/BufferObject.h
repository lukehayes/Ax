#ifndef AX_SYS_GL_BUFOBJ_H
#define AX_SYS_GL_BUFOBJ_H

#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/Common/Types.h"

namespace Ax::System::GL {

    class BufferObject
    {
        public:

                   BufferObject();
                   BufferObject(const std::vector<f32>& verticies, const BufferConfig& config);
                  ~BufferObject();

            void   generate();
            void   bind();
            void   unbind();

            void   setAttribPointers();
            void   setBufferData(std::vector<f32> verticies);

            std::vector<f32> data;
            BufferConfig config;
            GLuint id;
    };
}

#endif
