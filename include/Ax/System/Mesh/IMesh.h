/**
 * Parent class of all mesh instances inside AX.
 */
#ifndef AX_SYS_IMESH_H
#define AX_SYS_IMESH_H
#include <glad/glad.h>
#include "Ax/System/Common/Types.h"

namespace Ax::System::GL {

    class IMesh
    {
    public:
        virtual ~IMesh(){}
    };
}

#endif
