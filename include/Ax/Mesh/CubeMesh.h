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
        -1.0, 1.0, -1.0, //0
         1.0, 1.0, -1.0  //1
        -1.0, 1.0,  1.0, //2
         1.0, 1.0,  1.0, //3

        //Bottom
        -1.0, -1.0, -1.0, //4
         1.0, -1.0, -1.0, //5
        -1.0, -1.0,  1.0, //6
         1.0, -1.0,  1.0  //7

        //Front
        -1.0,  1.0, 1.0, //8
         1.0,  1.0, 1.0, //9
        -1.0, -1.0, 1.0, //10
         1.0, -1.0, 1.0, //11

        //Back
        -1.0,  1.0, -1.0, //12
         1.0,  1.0, -1.0, //13
        -1.0, -1.0, -1.0, //14
         1.0, -1.0, -1.0, //15

        //Left
        -1.0,  1.0,  1.0, //16
        -1.0,  1.0, -1.0, //17
        -1.0, -1.0,  1.0, //18
        -1.0, -1.0, -1.0, //19

        //Right
        1.0,  1.0,  1.0, //20
        1.0,  1.0, -1.0, //21
        1.0, -1.0,  1.0, //22
        1.0, -1.0, -1.0  }),
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
