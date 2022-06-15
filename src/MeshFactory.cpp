#include "Ax/Mesh/MeshFactory.h"
#include "Ax/GL/Buffer.h"
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
        //vao->bind();

        Ax::GL::Buffer buffer(mesh.getVerticies(), mesh.getIndicies());

        //buffer.generateVertexBuffer();
        //buffer.bindVertexBuffer();
        //buffer.setBufferData();
        //buffer.setAttribPointers();

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
        //Ax::GL::VertexBuffer vbo(mesh.getVerticies(), mesh.getIndicies());

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

    void MeshFactory::createRawRect()
    {
        glGenVertexArrays(1, vao);
        glBindVertexArray(*vao);

        glGenBuffers(1, vbo);
        glBindBuffer(GL_ARRAY_BUFFER, *vbo);

        std::vector<float> verts = {
            -0.5, 0.5,
            -0.5, -0.5,
            0.5, 0.5,
            0.5, -0.5
        };

        glEnableVertexAttribArray(0);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verts.size(), verts.data(), GL_STATIC_DRAW);
        glVertexAttribPointer(
                0,
                2,
                GL_FLOAT,
                GL_FALSE,
                0,
                0
                );
    }

    std::map<std::string, std::shared_ptr<Ax::GL::VertexArray>> MeshFactory::getVAOMap()
    {
        return this->vertexArrays;
    }

}
