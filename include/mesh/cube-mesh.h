#ifndef CUBE_MESH_H
#define CUBE_MESH_H

#include "engine.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

#define BUFFER_SIZE 108

typedef struct CubeMesh
{
    s8 id;
    s8 stride;
    s8 count;
    s32 vertexCount;
    s32 vertexBytes;
    float verticies[108];

    // OpenGL Specific Types
    GLuint VAO_ID;
    GLuint VBO_ID;
    
} CubeMesh;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CG_Generate_Buffers
 *  Description:  Generate the VAO and VBO for this mesh
 * =====================================================================================
 */
void CG_Generate_Buffers(CubeMesh* mesh);

/* #####   FUNCTION DEFINITIONS  -   ############################################### */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateCubeMesh
 *  Description:  Create an instance of a cube mesh.
 * =====================================================================================
 */
void CG_CreateCubeMesh(CubeMesh* mesh);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DestroyCubeMesh
 *  Description:  Free all memory that the Cube Mesh struct holds.
 * =====================================================================================
 */
void CG_DestroyCubeMesh(CubeMesh* mesh);


#endif
