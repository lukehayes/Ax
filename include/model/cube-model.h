#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "common/types.h"
#include "util/log.h"
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


/* #####   FUNCTION DEFINITIONS  -   ############################################### */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CreateModelCube
 *  Description:  Create an instance of a cube model.
 * =====================================================================================
 */
void CG_CreateModelCube(CubeModel* model)
{
    f32 cube_verticies[] = {
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

    static u8 id = 1;
    model->id = id;
    id++;

    model->stride = 0;
    model->count = 36;
    model->vertexCount = 108;
    model->vertexBytes = sizeof(f32) * model->vertexCount;
    memcpy(model->verticies, cube_verticies, sizeof(f32) * 108);

    // TODO Abstract this out later
	glGenVertexArrays(1, &model->VAO_ID);
	glBindVertexArray(model->VAO_ID);

	glGenBuffers(1, &model->VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, model->VBO_ID);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );


    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_verticies), cube_verticies, GL_STATIC_DRAW);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  DestroyCubeModel
 *  Description:  Free all memory that the Cube Model struct holds.
 * =====================================================================================
 */
void CG_DestroyModelCube(CubeModel* model)
{
    //free(model->verticies);
    //model->verticies = NULL;
}


#endif
