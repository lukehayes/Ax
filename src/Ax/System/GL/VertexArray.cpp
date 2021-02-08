#include "Ax/System/GL/VertexArray.h"

namespace Ax::System::GL {

    VertexArray::VertexArray() 
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }

    VertexArray::VertexArray(std::vector<f32> verticies, const BufferConfig& config)
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);


        this->m_buffer = verticies;
        this->setAttribPointers(config);
        this->setBufferData(verticies, config);
    }

    VertexArray::~VertexArray() 
    {
        glDeleteBuffers(1, &m_ArrayBufferID);
        glDeleteVertexArrays(1, &m_id);
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
