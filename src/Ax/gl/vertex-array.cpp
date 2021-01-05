#include "Ax/gl/vertex-array.h"

namespace Ax::GL {

    VertexArray::VertexArray() 
    {
        glGenVertexArrays(1, &this->id);
        glBindVertexArray(this->id);
    }

    VertexArray::~VertexArray() {}

    void VertexArray::bind() {}
    void VertexArray::unbind() {}
}
