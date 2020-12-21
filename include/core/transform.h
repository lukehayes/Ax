#ifndef CORE_TRANSFORM_H
#define CORE_TRANSFORM_H

#include "common/types.h"
#include "math/cglm-all.h"

typedef struct Transform
{
    vec3 position;
    vec3 rotation;
    vec3 scale;
} Transform;

void
CG_CreateTransform(Transform* self);

#endif
