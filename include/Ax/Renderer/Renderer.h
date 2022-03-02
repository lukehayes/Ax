#ifndef AX_RENDERER_H
#define AX_RENDERER_H

#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/GL/Shader.h"
#include "Ax/Mesh/Mesh.h"
#include "Ax/Entity/Entity.h"
#include <memory>
#include "Ax/Mesh/MeshFactory.h"

namespace Ax::Renderer
{
    class Renderer
    {
    public:
        Renderer() {}
        ~Renderer() {}

        void drawCube(Ax::Entity::Entity& entity, double x, double y)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, entity.position);
            model = glm::rotate(model, glm::radians((float)x), {1,1,1});

            std::shared_ptr<Ax::GL::VertexArray> vao = this->meshFactory.vertexArrays["cube"];
            vao->bind();
            this->shader.setMat4("model", model);
            this->shader.setVec3("color", entity.color);
            //glDrawArrays(m->getVertexBuffer().config.primitive, 0, m->getVertexCount());
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        void drawRectangle(Ax::Entity::Entity& entity, double x, double y)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, entity.position);
            model = glm::rotate(model, glm::radians((float)x), {1,1,1});

            std::shared_ptr<Ax::GL::VertexArray> vao = this->meshFactory.vertexArrays["rectangle"];
            vao->bind();
            this->shader.setMat4("model", model);
            this->shader.setVec3("color", entity.color);
            //glDrawArrays(m->getVertexBuffer().config.primitive, 0, m->getVertexCount());
            glDrawArrays(GL_TRIANGLE_STRIP, 0, 8);
        }

        Ax::Mesh::MeshFactory meshFactory;
        Ax::GL::Shader shader;
    };
}


#endif // AX_RENDERER_H
