#include "Ax/GL/Buffer.h"

namespace Ax::GL {

    Buffer::Buffer() {}

    Buffer::Buffer(
           const VecFloat& verticies,
           const VecInt& indicies
           ) : verticies(verticies), indicies(indicies){}

    Buffer::~Buffer() 
    {
        //glDeleteBuffers(1, &this->vertex_buffer_id);
        //LOG("Buffer Object ID:", this->vertex_buffer_id, " Destroyed");
    }

    void
    Buffer::generateVertexBuffer()
    {
        glGenBuffers(1, &this->vertex_buffer_id);
        LOG("Buffer Object ID:", this->vertex_buffer_id, "Generated");
    }

    void
    Buffer::generateElementBuffer()
    {
        glGenBuffers(1, &this->element_buffer_id);
        LOG("Buffer Object ID:", this->element_buffer_id, "Generated");
    }

    void
    Buffer::bindVertexBuffer()
    {
        glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer_id);
        LOG("Buffer Object ID:", this->vertex_buffer_id, "Bound");
    }

    void
    Buffer::bindElementBuffer()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->element_buffer_id);
        LOG("Buffer Object ID:", this->element_buffer_id, "Bound");
    }

    void
    Buffer::unbindVertexBuffer()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void
    Buffer::unbindElementBuffer()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void
    Buffer::destroyVertexBuffer()
    {
        glDeleteBuffers(1, &this->vertex_buffer_id);
    }

    void
    Buffer::destroyElementBuffer()
    {
        glDeleteBuffers(1, &this->element_buffer_id);
    }

    void 
    Buffer::setAttribPointers()
    {
        glVertexAttribPointer(
                0,
                3,
                GL_FLOAT,
                false,
                0,
                0);
        glEnableVertexAttribArray(0);
    }

    void
    Buffer::setBufferData()
    {
        //glGenBuffers(1, &this->vertex_buffer_id);
        glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer_id);
        glBufferData(GL_ARRAY_BUFFER, sizeof(f32) * verticies.size(), verticies.data(), GL_STATIC_DRAW );

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->element_buffer_id);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indicies.size(), indicies.data(), GL_STATIC_DRAW );
    }
}
