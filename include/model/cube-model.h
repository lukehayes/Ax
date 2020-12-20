#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "math/cglm-all.h"

/* #####   TYPE DEFINITIONS   ###################################################### */

typedef struct CubeModel 
{
    mat4 matrix;
    vec3 position;
    vec3 rotation;
    vec3 scale;
    
} CubeModel;

void CG_CreateCubeModel(CubeModel* self);

#endif
