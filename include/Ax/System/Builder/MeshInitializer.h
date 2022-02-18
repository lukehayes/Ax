#ifndef AX_SYS_MESH_INITLZR_H
#define AX_SYS_MESH_INITLZR_H

#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include "Ax/System/Mesh/LineMesh.h"
#include <memory>

namespace Ax::System::Builder
{
    using Ax::System::GL::VertexArray;
    using Ax::System::Mesh::RectangleMesh;
    using Ax::System::Mesh::IMesh;

    class MeshInitializer
    {
        public:
            MeshInitializer() {}

            template<class T>
            void init(const T* meshObject)
            {
                this->vertexArray.bind();

                //const std::shared_ptr<IMesh> meshObject = std::make_shared<IMesh>();

                this->BufferObject.config = meshObject->config;

                //// Buffer Initializaltion
                this->BufferObject.generate();
                this->BufferObject.bind();
                this->BufferObject.setBufferData(meshObject->verticies);
                this->BufferObject.setAttribPointers();

                std::cout << *meshObject << " Loaded onto GPU" << std::endl;
                //this->vertexArray.unbind();
            }

            ~MeshInitializer()
            {
            }

            GL::VertexArray vertexArray;
            GL::BufferObject BufferObject;
    };
}


#endif
