#ifndef __GFX_BUFFER_H__
#define __GFX_BUFFER_H__

#include <stdio.h>
#include "common/types.h"

typedef struct Buffer
{
    f32 x, y;
    f32 r, g, b;
    f32 verticies[9];
} Buffer;

_inline void
CG_CreateBuffer(Buffer* buffer)
{
    float arr[9] = {
       -1.0f, -1.0f, 0.0f,
       1.0f, -1.0f, 0.0f,
       0.0f,  1.0f, 0.0f,
    };

    for(int i = 0; i<9; i++)
    {
        buffer->verticies[i] = arr[i];
        printf("%i", i);
    }
}

#endif
