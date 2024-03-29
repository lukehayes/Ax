#include "Ax/GL/VertexBuffer.h"

namespace Ax::GL {

    VertexBuffer::VertexBuffer() {}

    VertexBuffer::VertexBuffer(
           const VecFloat& verticies,
           const VecInt& indicies
           ) : verticies(verticies), indicies(indicies){}

    VertexBuffer::~VertexBuffer() 
    {
        //glDeleteBuffers(1, &this->id);
        //LOG("Buffer Object ID:", this->id, " Destroyed");
    }

    void
    VertexBuffer::generate() 
    {
        glGenBuffers(1, &this->id);
        LOG("Buffer Object ID:", this->id, "Generated");
    }

    void
    VertexBuffer::bind()
    {
        glBindBuffer(this->config.target, this->id);
        LOG("Buffer Object ID:", this->id, "Bound");
    }

    void
    VertexBuffer::unbind()
    {
        glBindBuffer(this->config.target, 0);
        }

    void 
    VertexBuffer::destroy() 
    {
        glDeleteBuffers(1, &this->id);
    }

    void 
    VertexBuffer::setAttribPointers()
    {
        std::cout << this->config.vertexSize << std::endl;
        glVertexAttribPointer(
                this->config.attributePosition,
                this->config.vertexSize,
                GL_FLOAT, 
                false, 
                this->config.vertexStride,
                0);
        glEnableVertexAttribArray(this->config.attributePosition);
    }

    void
    VertexBuffer::setBufferData(std::vector<f32> verticies)
    {
        glGenBuffers(1, &this->id);
        glBindBuffer(this->config.target, this->id);
        glBufferData(this->config.target, sizeof(f32) * verticies.size(), verticies.data(), GL_STATIC_DRAW );
    }
}
