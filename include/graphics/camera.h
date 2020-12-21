#ifndef GFX_CAMERA_H
#define GFX_CAMERA_H

#include "common/types.h"
#include "core/transform.h"

typedef struct Camera
{
    // Properties
    mat4 projection;
    mat4 view;
    Transform transform;

    // Function Pointers
    void (*update)(struct Camera* camera, f64 dt);

} Camera;

void
CG_CreateCamera3D(Camera* camera);


#endif
