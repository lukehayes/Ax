#include "core/transform.h"

void
CG_CreateTransform(Transform* self)
{
    vec3 position = GLM_VEC3_ZERO_INIT;
    memcpy(self->position, &position, sizeof(float) * 3);

    vec3 rotation = GLM_VEC3_ZERO_INIT;
    memcpy(self->rotation, &rotation, sizeof(float) * 3);

    vec3 scale = GLM_VEC3_ZERO_INIT;
    memcpy(self->scale, &scale, sizeof(float) * 3);
}
