#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "common/types.h"
#include "util/log.h"
#include "engine.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

#define BUFFER_SIZE 108


typedef struct CubeModel 
{
    u8 id;
    u8 stride;
    s32 vertexCount;
    s32 vertexBytes;
    float* verticies;

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
void CG_CreateModelCube(struct CubeModel* model)
{
f32 cube_verticies[BUFFER_SIZE] = {
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
    model->vertexCount = BUFFER_SIZE;
    model->vertexBytes = sizeof(f32) * model->vertexCount;
    model->verticies = malloc(model->vertexBytes);
    memcpy(model->verticies, cube_verticies, model->vertexBytes);

    LB((Buffer*) model);
    LI(model->vertexBytes);

    for (int i = 0; i < 10; i++) {
        
        printf("--Bytes Loaded: %f \n", *(cube_verticies+ i));
    }



    // TODO Abstract this out later
	glGenVertexArrays(1, &model->VAO_ID);
	glBindVertexArray(model->VAO_ID);

	glGenBuffers(1, &model->VBO_ID);
	glBindBuffer(GL_ARRAY_BUFFER, model->VBO_ID);

	//glBufferData(GL_ARRAY_BUFFER, sizeof(f32) * cube_verticies, cube_verticies, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, model->stride, (void*)0 );
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
