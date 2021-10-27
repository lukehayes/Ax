#include "Ax/System/GL/VertexArray.h"

namespace Ax::System::GL {

    VertexArray::VertexArray() 
    {
        this->generate();
        //this->bind();
    }

    VertexArray::~VertexArray() 
    {
        //glDeleteVertexArrays(1, &this->id);
        LOG("Vertex Array ID:", this->id, "Destroyed");
    }

    void 
    VertexArray::generate() 
    {
        glGenVertexArrays(1, &this->id);
        LOG("Vertex Array ID:", this->id, "Generated");
    }

    void 
    VertexArray::bind() 
    {
        glBindVertexArray(this->id);
        LOG("Vertex Array ID:", this->id, "Bound.");
    }

    void 
    VertexArray::unbind() 
    {
        glBindVertexArray(0);
        LOG("Vertex Array ID:", this->id, "UnBound.");
    }
}
