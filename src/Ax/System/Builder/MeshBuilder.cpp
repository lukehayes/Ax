#include "Ax/System/Builder/MeshBuilder.h"

#include <memory>

namespace Ax::System::Builder
{
    MeshBuilder::MeshBuilder() {}

    /**
     * Load all of the mesh data onto the GPU.
     */
    void MeshBuilder::build()
    {
        const std::shared_ptr<RectangleMesh> meshObject = std::make_shared<RectangleMesh>();
        //const std::shared_ptr<LineMesh> meshObject = std::make_shared<LineMesh>();
       
        // VAO Initializaltion
        this->VertexArray.generate();
        this->VertexArray.bind();

        this->BufferObject.config = meshObject->config;
        
        // Buffer Initializaltion
        this->BufferObject.generate();
        this->BufferObject.bind();
        this->BufferObject.setBufferData(meshObject->verticies);
        this->BufferObject.setAttribPointers();

        std::cout << *meshObject.get() << " Data Loaded Into GPU."<< std::endl;
    }
}

