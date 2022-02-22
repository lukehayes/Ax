/*
 * =====================================================================================
 *
 *        Class:  IMesh
 *
 *  Description:  Parent class for all meshes inside Ax.
 *
 * =====================================================================================
 */

#ifndef AX_SYS_IMESH_H
#define AX_SYS_IMESH_H

#include <glad/glad.h>
#include "Ax/System/Common/Types.h"
#include "Ax/System/GL/Primitive.h"

namespace Ax::System::Mesh {

    using Ax::System::GL::Primitive;

    class IMesh
    {
    public:
        virtual ~IMesh(){}
        Primitive primitive = Primitive::TRIANGLES;
    };
}

#endif
