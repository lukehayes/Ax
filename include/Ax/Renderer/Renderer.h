#ifndef AX_RENDERER_H
#define AX_RENDERER_H

#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/GL/Shader.h"
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

        void add(std::shared_ptr<Ax::Mesh::CubeMesh>& mesh) 
        {
            std::shared_ptr<Ax::Mesh::CubeMesh> m = std::make_shared<Ax::Mesh::CubeMesh>();
            m->init();
            this->meshes.push_back(m);
        }

        void drawCube(Ax::Entity::Entity& entity, const Ax::GL::Shader& shader, double x, double y)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, entity.position);
            model = glm::rotate(model, glm::radians((float)x), {1,1,1});

            std::shared_ptr<Ax::Mesh::CubeMesh> m = meshes.at(0);
            //m->getVertexArray().bind();
            shader.setMat4("model", model);
            shader.setVec3("color", entity.color);
            glDrawArrays(m->getVertexBuffer().config.primitive, 0, m->getVertexCount());
        }

        std::vector<std::shared_ptr<Ax::Mesh::CubeMesh>> meshes;
    };
}


#endif // AX_RENDERER_H
