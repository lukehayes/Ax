#ifndef AX_RENDERER_H
#define AX_RENDERER_H

#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/Mesh/Mesh.h"
#include <memory>

namespace Ax::Renderer
{
    class Renderer
    {
    public:
        Renderer() {}
        ~Renderer() {}

        void add(const Ax::Mesh::Mesh& mesh, const Ax::GL::BufferConfig& config) 
        {
            std::shared_ptr<Ax::Mesh::Mesh> m = std::make_shared<Ax::Mesh::Mesh>(mesh);
            m->config = config;
            m->init();
            this->meshes.push_back(m);
        }

        void draw()
        {
            for(auto mesh : meshes)
            {
                mesh->vao.bind();
                glDrawArrays(mesh->vbo.config.primitive, 0, mesh->vertexCount);
                //mesh->vao.unbind();
            }
        }

        std::vector<std::shared_ptr<Ax::Mesh::Mesh>> meshes;
    };
}


#endif // AX_RENDERER_H
