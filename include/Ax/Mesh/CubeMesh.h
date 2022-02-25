#ifndef AX_CUBE_MESH_H
#define AX_CUBE_MESH_H

#include "Ax/Common/Types.h"

namespace Ax::Mesh
{
class CubeMesh
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

    VecFloat getVerticies() const
    {
        return this->verticies;
    }


private:
    VecFloat verticies;
};

}



#endif // AX_CUBE_MESH_H
