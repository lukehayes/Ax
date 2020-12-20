#include "model/cube-model.h"
#include "util/log.h"
#include <string.h>

void CG_CreateCubeModel(CubeModel* self)
{
    mat4 mat = GLM_MAT4_IDENTITY_INIT;
    memcpy(self->matrix, &mat, sizeof(float) * 16);

    vec3 pos = GLM_VEC3_ZERO_INIT;
    memcpy(self->position, &pos, sizeof(float) * 3);
}





