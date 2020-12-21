#include "graphics/camera.h"
#include "core/transform.h"

void 
update(struct Camera* camera, f64 dt)
{
    printf("Updateing %f \n", dt);
    printf("Camera position: %f %f %f \n", 
            camera->transform.position[0],
            camera->transform.position[1],
            camera->transform.position[2]
            );
	glm_lookat(camera->transform.position, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, camera->view );
}

void
CG_CreateCamera3D(Camera* camera)
{
    CG_CreateTransform(&camera->transform);

	mat4 projection = GLM_MAT4_IDENTITY_INIT;
	glm_perspective(glm_rad(45.0f), 800.0f/600.0f, 0.1, 100.0f, projection);
    memcpy(camera->projection, &projection, sizeof(mat4));

	mat4 view = GLM_MAT4_IDENTITY_INIT;
	glm_lookat(camera->transform.position, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, view );
    memcpy(camera->view, &view, sizeof(mat4));

    /*camera->c = 0.0;*/

    camera->update = update;
}


/*void move(Camera* camera) {*/

    /*printf("static value %f \n", camera->c);*/

    /*camera->transform.position[2] = sin(camera->c) * 20.0;*/
    /*camera->transform.position[1] = cos(camera->c) * 10.0;*/

	/*glm_lookat(camera->transform.position, (float[]){0.0f,0.0f,0.0f}, (float[]){0.0f,1.0f,0.0f}, camera->view );*/

    /*camera->c += 0.01;*/

/*}*/
