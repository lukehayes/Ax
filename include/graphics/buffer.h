#ifndef GFX_BUFFER_H
#define GFX_BUFFER_H

#include "common/types.h"

typedef struct Buffer
{
    u8 id;
    u32 stride;
    s32 vertexCount;
    s32 vertexBytes;
    f32* verticies;
    u32* indicies;
} Buffer;

void
CG_CreateBuffer(Buffer* buffer);

void
CG_DestroyBuffer(Buffer* buffer);

#endif
