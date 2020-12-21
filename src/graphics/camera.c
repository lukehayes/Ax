#include "graphics/camera.h"
#include "core/transform.h"

void
CG_CreateCamera3D(Camera* camera)
{
    CG_CreateTransform(&camera->transform);

	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	glm_perspective(glm_rad(45.0f), 800.0f/600.0f, 0.1, 100.0f, projection);
    memcpy(camera->projection, &projection, sizeof(mat4));

	mat4 view = GLM_MAT4_IDENTITY_INIT;
	glm_lookat((float[]){0.0f, 0.0f, -3.0f}, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, view );
    memcpy(camera->view, &view, sizeof(mat4));
}

