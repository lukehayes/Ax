#include "Ax/GL/VertexArray.h"

namespace Ax::GL {

    VertexArray::VertexArray() 
    {
        this->generate();
        //this->bind();
    }

    VertexArray::~VertexArray() 
    {
        glDeleteVertexArrays(1, &this->id);
    }

    void 
    VertexArray::generate() 
    {
        glGenVertexArrays(1, &this->id);
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
}
