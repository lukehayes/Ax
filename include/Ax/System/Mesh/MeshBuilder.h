/*
 * =====================================================================================
 *
 *       Filename:  MeshBuilder.h
 *
 *    Description:  A Mesh Builder setups all of the data so that it is ready
 *                  for the GPU to use it.
 *    
 * =====================================================================================
 */
#ifndef  AX_SYS_MESHBLDR_H
#define  AX_SYS_MESHBLDR_H

#include "Ax/System/Builder/Builder.h"
#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/GL/BufferTarget.h"
#include "Ax/System/GL/BufferConfig.h"
#include <memory>

namespace Ax::System::Mesh
{

    class MeshBuilder : public Builder::Builder
    {
    public:

        MeshBuilder() {}
        MeshBuilder(const std::shared_ptr<IMesh>& mesh) 
            : meshObject(mesh)
        {
        }


        void setMesh(const std::shared_ptr<IMesh>& mesh)
        {
            this->meshObject = mesh;
        }

        /**
         * Load all of the mesh data onto the GPU.
         */
        void build() override
        {
            RectangleMesh* mesh = dynamic_cast<RectangleMesh*>(this->meshObject.get());

            // VAO Initializaltion
            this->VertexArray.generate();
            this->VertexArray.bind();

            this->BufferObject.setConfig(mesh->config);

            // Buffer Initializaltion
            this->BufferObject.generate();
            this->BufferObject.bind();
            this->BufferObject.setBufferData(mesh->verticies);
            this->BufferObject.setAttribPointers();

            LOG("Rectangle Mesh Data Loaded Into GPU.");
        }

        std::shared_ptr<IMesh> meshObject;
        GL::VertexArray VertexArray;
        GL::BufferObject BufferObject;
    };
}

#endif

