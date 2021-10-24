#include "Ax/System/Builder/MeshBuilder.h"

#include <memory>

namespace Ax::System::Builder
{

    using Ax::System::Mesh::IMesh;
    using Ax::System::Mesh::RectangleMesh;
    using Ax::System::Mesh::LineMesh;

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
        //RectangleMesh* mesh = dynamic_cast<RectangleMesh*>(this->meshObject.get());
        Ax::System::Mesh::LineMesh* mesh = dynamic_cast<Ax::System::Mesh::LineMesh*>(this->meshObject.get());

        // VAO Initializaltion
        this->VertexArray.generate();
        this->VertexArray.bind();

        this->BufferObject.setConfig(mesh->config);

        // Buffer Initializaltion
        this->BufferObject.generate();
        this->BufferObject.bind();
        this->BufferObject.setBufferData(mesh->verticies);
        this->BufferObject.setAttribPointers();

        std::cout << mesh << " Data Loaded Into GPU."<< std::endl;
    }
}

