/**
 * Mesh Renderer
 */
#ifndef AX_SYS_MESHREND_H
#define AX_SYS_MESHREND_H

#include "Ax/System/Graphics/BaseRenderer.h"
#include "Ax/System/GL/VertexArray.h"
#include "Ax/System/GL/BufferObject.h"
#include "Ax/System/GL/BufferTarget.h"
#include "Ax/System/GL/BufferConfig.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Graphics/Camera3D.h"

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

            GL::VertexArray vertexArray;
            GL::BufferObject bufferObject;
            GL::BufferConfig bufferConfig;
            GL::Shader shader;
            Graphics::Camera3D camera;
    };

} /* namespace Ax::System::Graphics */


#endif
