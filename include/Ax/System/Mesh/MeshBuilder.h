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
#ifdef  AX_SYS_MESHBLDR_H
#define AX_SYS_MESHBLDR_H

#include "Ax/System/Builder/Builder.h"

namespace Ax::System::Mesh
{
    using Ax::System::Builder;

    class MeshBuilder : public Builder
    {
    public:

        MeshBuilder() {}
        MeshBuilder(const IMesh* mesh) : meshObject(mesh) {}

        /**
         * Load all of the mesh data onto the GPU.
         */
        virtual void build()
        {

        }

        IMesh* meshObject = nullptr;

    }
}

#endif

