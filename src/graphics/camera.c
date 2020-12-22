#include "graphics/camera.h"
#include "core/transform.h"

void 
update(struct Camera* camera, f64 dt)
{
    /*glm_lookat((float[]){0.0,0.0, 0.0}, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, camera->view );*/

    /*static float c = 0.0;*/
    /*c += 0.1;*/
    /*printf("Updating %f \n", c);*/
    /*glm_translate(camera->view, (float[]){ 0.0, 0.0, sin(c) * -10.0});*/
}

void
CG_CreateCamera3D(Camera* camera)
{
    CG_CreateTransform(&camera->transform);

	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	glm_perspective(glm_rad(45.0f), 800.0f/600.0f, 0.1, 100.0f, projection);
    memcpy(camera->projection, &projection, sizeof(mat4));

	mat4 view = GLM_MAT4_IDENTITY_INIT;
	glm_lookat(camera->transform.position, (float[]){0.0f,0.0f,-3.0f}, (float[]){0.0f,1.0f,0.0f}, view );
    memcpy(camera->view, &view, sizeof(mat4));

    camera->update = update;
}

void
CG_CreateCamera2D(Camera* camera)
{
    CG_CreateTransform(&camera->transform);

	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	glm_ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 10.0f, projection);
    memcpy(camera->projection, &projection, sizeof(mat4));

	mat4 view = GLM_MAT4_IDENTITY_INIT;
    glm_translate(view, (float[]){0.0, 0.0, -3.0f});
    memcpy(camera->view, &view, sizeof(mat4));

    camera->update = update;
}


