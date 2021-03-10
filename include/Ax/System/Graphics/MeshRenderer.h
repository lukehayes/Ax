/**
 * Mesh Renderer
 */
#ifndef AX_SYS_MESHREND_H
#define AX_SYS_MESHREND_H

#include "Ax/System/Graphics/BaseRenderer.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/System/GL/RectangleMesh.h"
#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Graphics/Camera3D.h"

namespace Ax::System::Graphics {

    using Ax::System::GL::RectangleMesh;

    class MeshRenderer : public BaseRenderer
    {
        public:
            /**
             * Default Constructor.
             */
            MeshRenderer();

            
            MeshRenderer(const RectangleMesh& mesh)
            {
                this->Mesh = mesh;
            }


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

            void draw(f32 x, f32 y, f32 w, f32 h);

            RectangleMesh Mesh;
            GL::Shader Shader;
            Graphics::Camera2D Camera;
    };

} /* namespace Ax::System::Graphics */


#endif
