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
            void init(T* meshObject)
            {
                meshObject->vertexArray.bind();
                //this->vertexArray.bind();

                ////const std::shared_ptr<IMesh> meshObject = std::make_shared<IMesh>();

                meshObject->bufferObject.config = meshObject->config;

                ////// Buffer Initializaltion
                meshObject->bufferObject.generate();
                meshObject->bufferObject.bind();
                meshObject->bufferObject.setBufferData(meshObject->verticies);
                meshObject->bufferObject.setAttribPointers();

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
