#ifndef AX_SYS_GL_VTXARRAY_H
#define AX_SYS_GL_VTXARRAY_H

#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/Common/Types.h"

namespace Ax::System::GL {

    class VertexArray
    {
        public:

                   VertexArray();
                  ~VertexArray();

            void   generate();
            void   bind();
            void   unbind();

        private:
            GLUI   id;
    };
}

#endif
