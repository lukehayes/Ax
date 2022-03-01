#ifndef AX_VTX_BUFFER_H
#define AX_VTX_BUFFER_H

#include "Ax/Common/Types.h"
#include "Ax/GL/BufferTarget.h"
#include "Ax/GL/BufferConfig.h"

namespace Ax::GL {

    class VertexBuffer
    {
        public:

                   VertexBuffer();
                  ~VertexBuffer();

                  //VertexBuffer(const VertexBuffer& rhs) : data(data), id(id), config(config)
                  //{
                      //std::cout << "Copy" << std::endl;
                  //}
            void   generate();
            void   bind();
            void   unbind();
            void   destroy();

            void   setAttribPointers();
            void   setBufferData(std::vector<f32> verticies);

            std::vector<f32> data;
            GLuint id;
            BufferConfig config;
    };
}

#endif
