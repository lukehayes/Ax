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
#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include "Ax/System/Mesh/LineMesh.h"

#include <memory>

namespace Ax::System::Builder
{

    class MeshBuilder : public Builder::Builder
    {
    public:

        MeshBuilder();

        /**
         * Load all of the mesh data onto the GPU.
         */
        void build() override;
    };
}

#endif

