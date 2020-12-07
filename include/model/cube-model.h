#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "common/types.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

typedef struct CubeModel 
{
    u8 id;
    u8 stride;
    s32 vertexCount;
    s32 vertexBytes;
    float* verticies;

} CubeModel;

f32 cube_verticies[108] = {
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

/* #####   FUNCTION DEFINITIONS  -   ############################################### */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateModelCube
 *  Description:  Create an instance of a cube model.
 * =====================================================================================
 */
void CG_CreateModelCube(struct CubeModel* model)
{
    static u8 id = 1;
    model->id = id;
    id++;

    model->stride = 0;
    model->vertexCount = 108;
    model->vertexBytes = sizeof(float) * model->vertexCount;
    model->verticies = malloc(model->vertexBytes);
    memcpy(model->verticies, cube_verticies, model->vertexBytes);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DestroyCubeModel
 *  Description:  Free all memory that the Cube Model struct holds.
 * =====================================================================================
 */
void CG_DestroyModelCube(CubeModel* model)
{
    free(model->verticies);
    model->verticies = NULL;
}


#endif
