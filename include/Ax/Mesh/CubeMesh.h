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
                        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
                        -1.0f,-1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f, // triangle 1 : end
                        1.0f, 1.0f,-1.0f, // triangle 2 : begin
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f,-1.0f, // triangle 2 : end
                        1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f, 1.0f,
                        -1.0f,-1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        -1.0f,-1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f,-1.0f,
                        1.0f,-1.0f,-1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f,-1.0f,
                        -1.0f, 1.0f,-1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f,-1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f, 1.0f, 1.0f,
                        -1.0f, 1.0f, 1.0f,
                        1.0f,-1.0f, 1.0f})
                        {}
            ~CubeMesh() {}

            //CubeMesh(const CubeMesh& rhs)
            //{
                //std::cout << "CubeMesh Copy" << std::endl;
                //this->verticies = rhs.verticies;
                //this->vao = rhs.vao;
                //this->vbo = rhs.vbo;
                //this->vertexCount = rhs.vertexCount;
            //}

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



        private:
            VecFloat verticies;
            Ax::GL::VertexArray vao;
            Ax::GL::VertexBuffer vbo;
            int vertexCount = 36;
    };

}



#endif // AX_CUBE_MESH_H
