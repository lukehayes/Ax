#include "Ax/System/GL/BufferObject.h"

namespace Ax::System::GL {

    BufferObject::BufferObject() {}

    BufferObject::BufferObject(const std::vector<f32>& verticies, const BufferConfig& config)
        : data(verticies),
          config(config)
    {

        this->generate();
        this->bind();
        this->setBufferData(this->data);
        this->setAttribPointers();
    }

    BufferObject::~BufferObject() 
    {
        //glDeleteBuffers(1, &this->id);
        //LOG("Buffer Object ID:", this->id, " Destroyed");
    }

    void 
    BufferObject::generate() 
    {
        glGenBuffers(1, &this->id);
        LOG("Buffer Object ID:", this->id, "Generated");
    }

    void 
    BufferObject::bind() 
    {
        glBindBuffer(this->config.target, this->id);
        LOG("Buffer Object ID:", this->id, "Bound");
    }

    void 
    BufferObject::unbind() 
    {
    }

    void 
    BufferObject::setAttribPointers()
    {
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
    BufferObject::setBufferData(std::vector<f32> verticies)
    {
        glGenBuffers(1, &this->id);
        glBindBuffer(this->config.target, this->id);
        glBufferData(this->config.target, sizeof(f32) * verticies.size(), verticies.data(), GL_STATIC_DRAW );
    }
}
