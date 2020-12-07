#include "graphics/buffer.h"

static float arr[9] = {
   -1.0f, -1.0f, 0.0f,
   1.0f, -1.0f, 0.0f,
   0.0f,  1.0f, 0.0f,
};

static u8 id = 1;

void
CG_CreateBuffer(Buffer* buffer)
{
    buffer->id = id;
    buffer->stride = 0;
    buffer->vertexCount = 9;
    buffer->vertexBytes = sizeof(float) * (buffer->vertexCount);

    buffer->verticies = malloc(buffer->vertexBytes);
    memcpy(buffer->verticies, arr, buffer->vertexBytes);
}

void
CG_DestroyBuffer(Buffer* buffer)
{
    free(buffer->verticies);
    buffer->verticies = NULL;
}
