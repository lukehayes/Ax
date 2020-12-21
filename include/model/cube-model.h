#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "math/cglm-all.h"
#include "core/transform.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

typedef struct CubeModel 
{
    mat4 matrix;
    Transform transform;
    
} CubeModel;

void CG_CreateCubeModel(CubeModel* self);

#endif
