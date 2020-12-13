#include "model/cube-model.h"
#include "util/log.h"

void CG_CreateCubeModel(CubeModel* self)
{
	self->matrix = GLM_MAT4_IDENTITY_INIT;
	self->position = GLM_VEC3_ZERO_INIT;
}





