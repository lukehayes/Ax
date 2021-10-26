/**
 * Mesh Renderer for drawing basic Meshes.
 */
#ifndef AX_SYS_MESHREND_H
#define AX_SYS_MESHREND_H

#include "Ax/System/Graphics/BaseRenderer.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/System/Graphics/Camera.h"
#include "Ax/System/GL/Primitive.h"
#include "Ax/Engine/Component/TestEntity.h"
#include "Ax/System/Common/Types.h"

namespace Ax::System::Mesh {

    using Ax::System::Graphics::BaseRenderer;
    using namespace Ax::System::GL;

    class MeshRenderer 
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
            void draw(int x, int y, glm::vec3 color);

            void draw(int x, int y, const Ax::System::GL::Shader& shader );

            void draw(f32 x, f32 y, f32 w, f32 h);

            void draw(
                    const Ax::Engine::Component::TestEntity& entity,
                    const Ax::System::GL::Shader& shader,
                    GL::Primitive primitive = GL::TRIANGLES
                    );

            void setCamera(Graphics::Camera* camera);

            /** Data Members **/
            Graphics::Camera* camera;
    };

} /* namespace Ax::System::Graphics */


#endif
