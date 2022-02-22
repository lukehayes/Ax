
#ifndef AX_GL_VTXARRAY_H
#define AX_GL_VTXARRAY_H

#include "Ax/Common/Types.h"

namespace Ax::GL {

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
