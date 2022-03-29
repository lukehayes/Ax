#include "Ax/Mesh/MeshFactory.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/Mesh/CubeMesh.h"
#include "Ax/Mesh/RectangleMesh.h"


namespace Ax::Mesh
{
    MeshFactory::MeshFactory() noexcept
    {
        createCubeMesh();
        createRectangleMesh();
    }

    MeshFactory::~MeshFactory()
    {
    }

    void MeshFactory::createCubeMesh()
    {
        Ax::Mesh::CubeMesh mesh;
        std::shared_ptr<Ax::GL::VertexArray> vao = std::make_shared<Ax::GL::VertexArray>();
        vao->generate();
        vao->bind();

        Ax::GL::VertexBuffer vbo;

        // BUFFER CONFIG MUST BE SET!
        vbo.config.attributePosition = 0;
        vbo.config.vertexStride = 0;
        vbo.config.vertexSize = 3;
        vbo.config.target = Ax::GL::BufferTarget::ARRAY_BUFFER;

        vbo.generate();
        vbo.bind();
        vbo.setBufferData(mesh.getVerticies());
        vbo.setAttribPointers();

        this->vertexArrays.insert(std::pair<std::string, std::shared_ptr<Ax::GL::VertexArray>>("cube", vao));
        vao->unbind();

    }

    void MeshFactory::createRectangleMesh()
    {
        Ax::Mesh::RectangleMesh mesh;
        std::shared_ptr<Ax::GL::VertexArray> vao = std::make_shared<Ax::GL::VertexArray>();
        vao->generate();
        vao->bind();

        Ax::GL::VertexBuffer vbo;

        // BUFFER CONFIG MUST BE SET!
        vbo.config.attributePosition = 0;
        vbo.config.vertexStride = 0;
        vbo.config.vertexSize = 2;
        vbo.config.target = Ax::GL::BufferTarget::ARRAY_BUFFER;

        vbo.generate();
        vbo.bind();
        vbo.setBufferData(mesh.getVerticies());
        vbo.setAttribPointers();

        this->vertexArrays.insert(std::pair<std::string, std::shared_ptr<Ax::GL::VertexArray>>("rectangle", vao));
        vao->unbind();

    }

    std::map<std::string, std::shared_ptr<Ax::GL::VertexArray>> MeshFactory::getVAOMap()
    {
        return this->vertexArrays;
    }

}
