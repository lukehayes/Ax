#include "mesh/cube-mesh.h"
#include "engine.h"
#include "util/log.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

static f32 cube_verticies[] = {
            -0.5f, -0.5f, -0.5f,
             0.5f, -0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f, -0.5f,  0.5f,
             0.5f, -0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,

            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f, -0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,

             0.5f,  0.5f,  0.5f,
             0.5f,  0.5f, -0.5f,
             0.5f, -0.5f, -0.5f,
             0.5f, -0.5f, -0.5f,
             0.5f, -0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,

            -0.5f, -0.5f, -0.5f,
             0.5f, -0.5f, -0.5f,
             0.5f, -0.5f,  0.5f,
             0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f,  0.5f,
            -0.5f, -0.5f, -0.5f,

            -0.5f,  0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
             0.5f,  0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f, -0.5f,
    };

void CG_Generate_Buffers(CubeMesh* mesh);

/* #####   FUNCTION DEFINITIONS  -   ############################################### */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateCubeMesh
 *  Description:  Create an instance of a cube mesh.
 * =====================================================================================
 */
void CG_CreateCubeMesh(CubeMesh* mesh)
{

    static u8 id = 1;
    mesh->id = id;
    id++;

    mesh->stride = 0;
    mesh->count = 36;
    mesh->vertexCount = BUFFER_SIZE;
    mesh->vertexBytes = sizeof(f32) * mesh->vertexCount;
    memcpy(mesh->verticies, cube_verticies, sizeof(f32) * BUFFER_SIZE);

    CG_Generate_Buffers(mesh);
}


void CG_Generate_Buffers(CubeMesh* mesh)
{
    // TODO Abstract this out later
	glGenVertexArrays(1, &mesh->VAO_ID);
	glBindVertexArray(mesh->VAO_ID);

	glGenBuffers(1, &mesh->VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, mesh->VBO_ID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );


    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_verticies), cube_verticies, GL_STATIC_DRAW);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DestroyCubeMesh
 *  Description:  Free all memory that the Cube Mesh struct holds.
 * =====================================================================================
 */
void CG_DestroyCubeMesh(CubeMesh* mesh)
{
    //free(mesh->verticies);
    //mesh->verticies = NULL;
}

