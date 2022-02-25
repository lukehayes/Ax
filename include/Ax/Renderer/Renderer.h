#ifndef AX_RENDERER_H
#define AX_RENDERER_H

#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/Mesh/Mesh.h"
#include "Ax/Entity/Entity.h"
#include <memory>

namespace Ax::Renderer
{
    class Renderer
    {
    public:
        Renderer() {}
        ~Renderer() {}

        void add(const Ax::Mesh::Mesh& mesh) 
        {
            std::shared_ptr<Ax::Mesh::Mesh> m = std::make_shared<Ax::Mesh::Mesh>(mesh);
            m->init();
            this->meshes.push_back(m);
        }

        void draw(Ax::Entity::Entity entity, const Ax::GL::Shader& shader, double x, double y)
        {

            entity.position.x = x / 100.0;
            entity.position.y = y / 100.0;

            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, entity.position);
            model = glm::rotate(model, glm::radians((float)x), {1,1,1});

            std::shared_ptr<Ax::Mesh::Mesh> m = meshes[1];
            m->vao.bind();
            shader.setMat4("model", model);
            glDrawArrays(m->primitive, 0, m->vertexCount);

            shader.setVec3("color", {0.1,0.7,0.3});
            model = glm::mat4(1.0f);
            entity.position.x = 0.0f;
            entity.position.y = 1.0f;
            model = glm::translate(model, entity.position);

            m = meshes[0];
            m->vao.bind();
            shader.setMat4("model", model);
            glDrawArrays(m->primitive, 0, m->vertexCount);

            //for(auto mesh : meshes)
            //{
                //shader.setMat4("model", model);
                //mesh->vao.bind();
                //glDrawArrays(mesh->primitive, 0, mesh->vertexCount);
                ////mesh->vao.unbind();
            //}
        }

        std::vector<std::shared_ptr<Ax::Mesh::Mesh>> meshes;
    };
}


#endif // AX_RENDERER_H
