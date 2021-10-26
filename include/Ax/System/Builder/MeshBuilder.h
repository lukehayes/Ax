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
#include "Ax/System/Mesh/RectangleMesh.h"
#include "Ax/System/Mesh/LineMesh.h"
#include "Ax/System/Mesh/IMesh.h"

#include <memory>

namespace Ax::System::Builder
{

    using Ax::System::Mesh::IMesh;
    using Ax::System::Mesh::RectangleMesh;
    using Ax::System::Mesh::LineMesh;

    class MeshBuilder : public Builder::Builder
    {
    public:

        MeshBuilder();
        MeshBuilder(const std::shared_ptr<IMesh>& mesh);

        void setMesh(const std::shared_ptr<IMesh>& mesh);

        /**
         * Load all of the mesh data onto the GPU.
         */
        void build() override;

        std::shared_ptr<IMesh> meshObject = nullptr;
        GL::VertexArray VertexArray;
        GL::BufferObject BufferObject;
    };
}

#endif

