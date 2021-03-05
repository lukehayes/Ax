/**
 * Mesh Renderer
 */
#ifndef AX_SYS_MESHREND_H
#define AX_SYS_MESHREND_H

#include "Ax/System/Graphics/BaseRenderer.h"

namespace Ax::System::Graphics {


    class MeshRenderer : public BaseRenderer
    {
        public:
            /**
             * Default Constructor.
             */
            MeshRenderer();

            /**
             * Destructor.
             */
            ~MeshRenderer();

            /**
             * Draw from the data loaded in the BufferObject
             * currently bound to the VertexArray.
             *
             * @param int x The x position.
             * @param int y The y position.
             *
             * @return void.
             */
            void draw(int x, int y);

        private: 
    };

} /* namespace Ax::System::Graphics */


#endif
