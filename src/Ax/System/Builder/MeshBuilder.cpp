#include "Ax/System/Builder/MeshBuilder.h"

#include <memory>

namespace Ax::System::Builder
{
    MeshBuilder::MeshBuilder() {}

    MeshBuilder::MeshBuilder(const std::shared_ptr<IMesh>& mesh) 
        : meshObject(mesh){}

    void MeshBuilder::setMesh(const std::shared_ptr<IMesh>& mesh)
    {
        this->meshObject = mesh;
    }

    /**
     * Load all of the mesh data onto the GPU.
     */
    void MeshBuilder::build()
    {
        const std::shared_ptr<RectangleMesh> meshObject = std::make_shared<RectangleMesh>();
        RectangleMesh* mesh = dynamic_cast<RectangleMesh*>(this->meshObject.get());

        //const std::shared_ptr<LineMesh> meshObject = std::make_shared<LineMesh>();
        //Ax::System::Mesh::LineMesh* mesh = dynamic_cast<Ax::System::Mesh::LineMesh*>(this->meshObject.get());

        // VAO Initializaltion
        this->VertexArray.generate();
        this->VertexArray.bind();

        Ax::System::GL::BufferConfig config = {0,2,0, Ax::System::GL::ARRAY_BUFFER};

        this->BufferObject.config = config;
        //this->BufferObject.setConfig(mesh->config);
        
        // Buffer Initializaltion
        this->BufferObject.generate();
        this->BufferObject.bind();
        this->BufferObject.setBufferData(meshObject->verticies);
        this->BufferObject.setAttribPointers();

        std::cout << *mesh << " Data Loaded Into GPU."<< std::endl;
    }
}

