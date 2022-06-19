#ifndef AX_RENDERER_H
#define AX_RENDERER_H

#include "Ax/Common/Types.h"
#include "Ax/GL/VertexArray.h"
#include "Ax/GL/VertexBuffer.h"
#include "Ax/GL/BufferConfig.h"
#include "Ax/GL/Shader.h"
#include "Ax/Entity/Entity.h"
#include <memory>
#include "Ax/Mesh/MeshFactory.h"
#include "Ax/Camera/Camera3D.h"

using meshMap = std::map<std::string, std::shared_ptr<Ax::GL::VertexArray>>;

namespace Ax::Renderer
{
    class Renderer
    {
    public:
        Renderer() {
            this->vaoMap = this->meshFactory.getVAOMap();
        }
        ~Renderer() {}

        /**
         * Clear the currenty frame.
         * @param glm::vec3 color
         */
        void clear(V3 color = {0.5f, 0.5f, 0.5f})
        {
            glClearColor(color.r, color.g, color.b, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void drawCube(Ax::Entity::Entity& entity, const Ax::GL::Primitive& primitive = GL::TRIANGLES)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, entity.position);
            model = glm::rotate(model, glm::radians((float)45.0f), {1,1,1});
            model = glm::scale(model, {entity.scale, entity.scale, entity.scale});

            std::shared_ptr<Ax::GL::VertexArray> vao = this->vaoMap["cube"];
            vao->bind();
            this->shader.setMat4("model", model);
            this->shader.setVec3("color", entity.color);
            //glDrawArrays(m->getVertexBuffer().config.primitive, 0, m->getVertexCount());
            //glDrawArrays(primitive, 0, 36);
            glDrawElements(primitive, 72, GL_UNSIGNED_INT,0);
        }

        void drawRectangle(Ax::Entity::Entity& entity, const Ax::GL::Primitive& primitive = GL::TRIANGLE_STRIP)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, entity.position);
            model = glm::rotate(model, glm::radians((float)0.0f), {1,1,1});

            std::shared_ptr<Ax::GL::VertexArray> vao = this->vaoMap["rectangle"];
            vao->bind();
            this->shader.setMat4("model", model);
            this->shader.setVec3("color", entity.color);
            //glDrawArrays(m->getVertexBuffer().config.primitive, 0, m->getVertexCount());
            glDrawArrays(primitive, 0, 8);
        }

        void basicDraw(Ax::Camera::Camera3D* camera, Ax::GL::Shader& shader, const Ax::Entity::Entity e)
        {
            static double c = 0.0;
            c += 0.0001;

            // Get the pointer to a VAO
            std::shared_ptr<Ax::GL::VertexArray> vaoObject = this->vaoMap["rectangle"];

            // Set model matrix for the current model
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, e.position);
            model = glm::rotate(model, (float)std::sin(c), {1,1,1});
            model = glm::scale(model, {10,10,10});

            vaoObject->bind();

            shader.use();

            camera->update(0.0f);
            this->shader.setMat4("projection", camera->getProjection());
            this->shader.setMat4("view", camera->getView());
            this->shader.setMat4("model", model);
            this->shader.setFloat("c", c);
            this->shader.setVec3("color", e.color);

            glDrawArrays(GL_TRIANGLE_STRIP, 0,4);
        }

        meshMap vaoMap;
        Ax::GL::Shader shader;
        Ax::Mesh::MeshFactory meshFactory;
    };


}


#endif // AX_RENDERER_H
