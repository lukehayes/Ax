#ifndef _CG_VEC2_H_
#define _CG_VEC2_H_

#include "common/types.h"

/** Structs **/
typedef struct IV2
{
    s32 x;
    s32 y;
} IV2;

typedef struct FV2
{
    f32 x;
    f32 y;
} FV2;

/** Functions **/

IV2 
CG_IV2_Add(const IV2, const IV2);

IV2 
CG_IV2_Sub(const IV2, const IV2);

IV2 
CG_IV2_Mul_Scalar(const IV2, const s32);

IV2 
CG_IV2_Div(const IV2, const IV2);

s32
CG_IV2_Length(const IV2);

u8
CG_IV2_Normalize(const IV2);

#endif

