/**
 * Mesh Renderer for drawing basic Meshes.
 */
#ifndef AX_SYS_MESHREND_H
#define AX_SYS_MESHREND_H

#include "Ax/System/Graphics/BaseRenderer.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/System/Mesh/RectangleMesh.h"
#include "Ax/System/Graphics/Camera.h"
#include "Ax/System/Graphics/Camera2D.h"
#include "Ax/System/Graphics/Camera3D.h"
#include "Ax/System/GL/Shader.h"
#include "Ax/Engine/Component/TestEntity.h"

namespace Ax::System::Mesh {

    using Ax::System::Mesh::RectangleMesh;
    using Ax::System::Graphics::BaseRenderer;
    //using Ax::System::Graphics::Camera;
    using namespace Ax::System::GL;

    class MeshRenderer 
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
            void draw(int x, int y, glm::vec3 color);

            void draw(int x, int y, const Ax::System::GL::Shader& shader );

            void draw(f32 x, f32 y, f32 w, f32 h);

            void draw(
                    const Ax::Engine::Component::TestEntity& entity,
                    const Ax::System::GL::Shader& shader );

            void setCamera(Graphics::Camera* camera);

            inline GL::Shader getShader() 
            {
                return this->Shader;
            }

            RectangleMesh Mesh;
            GL::Shader Shader;
            Graphics::Camera* camera;
    };

} /* namespace Ax::System::Graphics */


#endif
