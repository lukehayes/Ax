#include "Ax/System/Builder/MeshBuilder.h"
#include <memory>

namespace Ax::System::Builder
{
    using Ax::System::Mesh::RectangleMesh;
    using Ax::System::Mesh::LineMesh;

    MeshBuilder::MeshBuilder() {}

    /**
     * Load all of the mesh data onto the GPU.
     */
    void MeshBuilder::build()
    {
        //const std::shared_ptr<RectangleMesh> meshObject = std::make_shared<RectangleMesh>();
        //const std::shared_ptr<LineMesh> meshObject = std::make_shared<LineMesh>();
       
        RectangleMesh meshObject;


        // VAO Initializaltion
        meshObject.vertexArray.generate();
        meshObject.vertexArray.bind();

        meshObject.config = meshObject.config;
        
        // Buffer Initializaltion
        meshObject.bufferObject.generate();
        meshObject.bufferObject.bind();
        meshObject.bufferObject.setBufferData(meshObject.verticies);
        meshObject.bufferObject.setAttribPointers();

        //std::cout << *meshObject.get() << " Data Loaded Into GPU."<< std::endl;
    }
}

