#include "Ax/system/gl/vertex-array.h"

namespace Ax::System::GL {

    VertexArray::VertexArray() 
    {
        glGenVertexArrays(1, &m_id);
        glBindVertexArray(m_id);
    }

    VertexArray::~VertexArray() {}

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
    VertexArray::setBufferData(std::array<f32, 8>verticies, const BufferConfig& config)
    {
        glGenBuffers(1, &m_bufferID);
        glBindBuffer(config.target, m_bufferID);
        glBufferData(config.target, sizeof(f32) * verticies.size(), verticies.data(), GL_STATIC_DRAW );
    }
}
