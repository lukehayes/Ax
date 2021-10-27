#ifndef AX_SYS_MESH_INITLZR_H
#define AX_SYS_MESH_INITLZR_H

#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include <memory>

namespace Ax::System::Builder
{
    using Ax::System::GL::VertexArray;
    using Ax::System::Mesh::RectangleMesh;

    class MeshInitializer
    {
        public:
            MeshInitializer()
            {
                this->vertexArray.bind();

                const std::shared_ptr<RectangleMesh> meshObject = std::make_shared<RectangleMesh>();

                this->BufferObject.config = meshObject->config;

                // Buffer Initializaltion
                this->BufferObject.generate();
                this->BufferObject.bind();
                this->BufferObject.setBufferData(meshObject->verticies);
                this->BufferObject.setAttribPointers();


                this->vertexArray.unbind();
            }

            ~MeshInitializer()
            {
            }

            GL::VertexArray vertexArray;
            GL::BufferObject BufferObject;
    };
}


#endif
