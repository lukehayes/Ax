#ifndef AX_BUFFER_H
#define AX_BUFFER_H

#include "Ax/Common/Types.h"
#include "Ax/GL/BufferTarget.h"
#include "Ax/GL/BufferConfig.h"

namespace Ax::GL {

class Buffer
{
public:

   Buffer();
   Buffer(
           const VecFloat& verticies,
           const VecInt& indicies
           );
  ~Buffer();

    void   generateVertexBuffer();
    void   generateElementBuffer();

    void   bindVertexBuffer();
    void   bindElementBuffer();

    void   unbindVertexBuffer();
    void   unbindElementBuffer();

    void   destroyVertexBuffer();
    void   destroyElementBuffer();

    void   setAttribPointers();
    void   setBufferData();

    std::vector<f32> verticies;
    std::vector<size_t> indicies;
    GLuint vertex_buffer_id;
    GLuint element_buffer_id;
};
}

#endif
