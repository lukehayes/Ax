#include "Ax/System/GL/VertexArray.h"

namespace Ax::System::GL {

    VertexArray::VertexArray() 
    {
        glGenVertexArrays(1, &this->id);
        glBindVertexArray(this->id);
    }

    VertexArray::VertexArray(const std::vector<f32>& verticies, const BufferConfig& config)
        : buffer(verticies),
          config(config)
    {

        this->generate();
        this->setBufferData(this->buffer, this->config);
        this->setAttribPointers(this->config);
    }

    VertexArray::~VertexArray() 
    {
        glDeleteBuffers(1, &this->arrayBufferID);
        glDeleteVertexArrays(1, &this->id);
    }

    void 
    VertexArray::generate() 
    {
        glGenVertexArrays(1, &this->id);
        glBindVertexArray(this->id);

        glGenBuffers(1, &this->arrayBufferID);
        glBindBuffer(this->config.target, this->arrayBufferID);
    }

    void 
    VertexArray::bind() 
    {
        glBindVertexArray(this->id);
    }

    void 
    VertexArray::unbind() 
    {
        glBindVertexArray(0);
    }

    void 
    VertexArray::setAttribPointers(const BufferConfig& config)
    {

        glVertexAttribPointer(
                config.attributePosition,
                config.vertexSize,
                GL_FLOAT, 
                false, 
                config.vertexStride,
                0);
        glEnableVertexAttribArray(config.attributePosition);
    }

    void
    VertexArray::setBufferData(std::vector<f32> verticies, const BufferConfig& config)
    {
        glGenBuffers(1, &this->arrayBufferID);
        glBindBuffer(config.target, this->arrayBufferID);
        glBufferData(config.target, sizeof(f32) * verticies.size(), verticies.data(), GL_STATIC_DRAW );
    }
}
