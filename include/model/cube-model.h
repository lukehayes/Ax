#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "engine.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

#define BUFFER_SIZE 108


typedef struct CubeModel 
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

    
} CubeModel;


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CG_Generate_Buffers
 *  Description:  Generate the VAO and VBO for this model
 * =====================================================================================
 */
void CG_Generate_Buffers(CubeModel* model);

/* #####   FUNCTION DEFINITIONS  -   ############################################### */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateModelCube
 *  Description:  Create an instance of a cube model.
 * =====================================================================================
 */
void CG_CreateModelCube(CubeModel* model);

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DestroyCubeModel
 *  Description:  Free all memory that the Cube Model struct holds.
 * =====================================================================================
 */
void CG_DestroyModelCube(CubeModel* model);


#endif
