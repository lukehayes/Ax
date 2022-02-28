#ifndef AX_RECTANGLE_MESH_H
#define AX_RECTANGLE_MESH_H

#include "Ax/Common/Types.h"
#include "Ax/Mesh/Mesh.h"

namespace Ax::Mesh
{
    class RectangleMesh : public Ax::Mesh::Mesh
    {
        public:
            RectangleMesh() : verticies({
                    -1.0, 1.0,
                    -1.0, -1.0,
                    1.0, 1.0,
                    1.0, -1.0
                    }){}

            ~RectangleMesh() {}

            VecFloat getVerticies() const
            {
                return this->verticies;
            }

            virtual void init() override
            {
                this->vao.generate();
                this->vao.bind();

                // BUFFER CONFIG MUST BE SET!

                this->vbo.generate();
                this->vbo.bind();
                this->vbo.setBufferData(this->verticies);
                this->vbo.setAttribPointers();
            }

            Ax::GL::VertexArray getVertexArray() 
            {
                return this->vao;
            }

            Ax::GL::VertexBuffer getVertexBuffer()
            {
                return this->vbo;
            }

        private:
            VecFloat verticies;
            Ax::GL::VertexArray vao;
            Ax::GL::VertexBuffer vbo;
            int vertexCount = 8;

    };

}



#endif // AX_CUBE_MESH_H
