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
#include <memory>

namespace Ax::System::Mesh
{

    class MeshBuilder : public Builder::Builder
    {
    public:

        MeshBuilder() {}
        MeshBuilder(const IMesh& mesh) 
        {
            //this->meshObject = std::make_shared<IMesh>();
        }

        /**
         * Load all of the mesh data onto the GPU.
         */
        virtual void build()
        {

        }

        std::shared_ptr<IMesh> meshObject;
    };
}

#endif

