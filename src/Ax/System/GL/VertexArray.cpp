#include "Ax/System/GL/VertexArray.h"
#include <iostream>

namespace Ax::System::GL {

    VertexArray::VertexArray() 
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }

    VertexArray::VertexArray(const std::vector<f32>& verticies, const BufferConfig& config)
        : m_buffer(verticies),
          m_config(config)
    {

        this->generate();
        this->setAttribPointers(m_config);
        this->setBufferData(m_buffer, m_config);
        std::cout << 1 << std::endl;
    }

    VertexArray::~VertexArray() 
    {
        glDeleteBuffers(1, &m_ArrayBufferID);
        glDeleteVertexArrays(1, &m_id);
    }

    void 
    VertexArray::generate() 
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);

        glGenBuffers(1, &m_ArrayBufferID);
        glBindBuffer(m_config.target, m_ArrayBufferID);
    }

    void 
    VertexArray::bind() 
    {
        glBindVertexArray(m_id);
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
        glGenBuffers(1, &m_ArrayBufferID);
        glBindBuffer(config.target, m_ArrayBufferID);
        glBufferData(config.target, sizeof(f32) * verticies.size(), verticies.data(), GL_STATIC_DRAW );
    }
}
