#ifndef AX_RECTANGLE_MESH_H
#define AX_RECTANGLE_MESH_H

#include "Ax/Common/Types.h"

namespace Ax::Mesh
{
    class RectangleMesh
    {
        public:
            RectangleMesh() : verticies({
                    0.5f,  0.5f, 0.0f,  // top right
                    0.5f, -0.5f, 0.0f,  // bottom right
                    -0.5f, -0.5f, 0.0f,  // bottom left
                    -0.5f,  0.5f, 0.0f   // top left
                    }),
                indicies({
                        0, 1, 3,
                        1, 2, 3
                        })
            {}

            ~RectangleMesh() {}

            VecFloat getVerticies() const
            {
                return this->verticies;
            }

            VecInt getIndicies() const
            {
                return this->indicies;
            }

        private:
            VecFloat verticies;
            VecInt   indicies;
            Ax::GL::VertexArray vao;
            Ax::GL::VertexBuffer vbo;
            int vertexCount = 8;

    };

}



#endif // AX_CUBE_MESH_H
