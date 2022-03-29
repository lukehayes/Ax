#ifndef AX_CUBE_MESH_H
#define AX_CUBE_MESH_H

#include "Ax/Common/Types.h"
#include "Ax/Mesh/Mesh.h"

namespace Ax::Mesh
{
    class CubeMesh : public Ax::Mesh::Mesh
    {
        public:
            CubeMesh() 
                : verticies({
        //Top
        -1, 1, -1, //0
         1, 1, -1  //1
        -1, 1,  1, //2
         1, 1,  1, //3

        //Bottom
        -1, -1, -1, //4
         1, -1, -1, //5
        -1, -1,  1, //6
         1, -1,  1  //7

        //Front
        -1,  1, 1, //8
         1,  1, 1, //9
        -1, -1, 1, //10
         1, -1, 1, //11

        //Back
        -1,  1, -1, //12
         1,  1, -1, //13
        -1, -1, -1, //14
         1, -1, -1, //15

        //Left
        -1,  1,  1, //16
        -1,  1, -1, //17
        -1, -1,  1, //18
        -1, -1, -1, //19

        //Right
        1,  1,  1, //20
        1,  1, -1, //21
        1, -1,  1, //22
        1, -1, -1  }),
        indicies({
        //Top
        0, 1, 2,
        2, 3, 1,

        //Bottom
        4, 5, 6,
        6, 7, 5,

        //Front
        8, 9, 10,
        10, 11, 9,

        //Back
        12, 13, 14,
        14, 15, 13,

        //Left
        16, 17, 18,
        18, 19, 17,

        //Right
        20, 21, 22, 
        22, 23, 21

                })
                        {}
            ~CubeMesh() {}

            VecFloat getVerticies() const
            {
                return this->verticies;
            }

            virtual void init() override
            {
                // TODO Maybe Implement?
            }

            Ax::GL::VertexArray getVertexArray() override
            {
                return this->vao;
            }

            Ax::GL::VertexBuffer getVertexBuffer() override
            {
                return this->vbo;
            }

            int getVertexCount() override
            {
                return this->vertexCount;
            }

            VecFloat getVerticies() override
            {
                return this->verticies;
            }

            VecInt getIndicies() override
            {
                return this->indicies;
            }

        private:
            VecFloat verticies;
            VecInt   indicies;
            Ax::GL::VertexArray vao;
            Ax::GL::VertexBuffer vbo;
            int vertexCount = 36;
    };

}



#endif // AX_CUBE_MESH_H
