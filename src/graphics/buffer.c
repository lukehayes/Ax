#include "graphics/buffer.h"


void
CG_CreateBuffer(Buffer* buffer)
{
    buffer->stride = 0;
    s32 vertexCount = 9;
    s32 vertexBytes = sizeof(float) * vertexCount;
    buffer->vertexCount = vertexCount;
    buffer->vertexBytes = vertexBytes;

    float arr[9] = {
       -1.0f, -1.0f, 0.0f,
       1.0f, -1.0f, 0.0f,
       0.0f,  1.0f, 0.0f,
    };

    buffer->verticies = malloc(vertexBytes);
    memcpy(buffer->verticies, arr, sizeof(vertexBytes));
}

void
CG_DestroyBuffer(Buffer* buffer)
{
    free(buffer->verticies);
    buffer->verticies = NULL;
}
