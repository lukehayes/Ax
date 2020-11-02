#ifndef __GFX_BUFFER_H__
#define __GFX_BUFFER_H__

#include "common/types.h"

typedef struct Buffer
{
    f32* verticies;

} Buffer;


_inline void
CG_CreateBuffer(Buffer* buffer)
{
    f32 data[] = {0.3,0.4,0.3};

    buffer->verticies = data;

    printf("Creating BUffer");
}

#endif
