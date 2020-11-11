#include "math/vec2.h"
#include <math.h>
#include <stdio.h>

/** Integer Vector **/

IV2 
CG_Add_IV2(const IV2 a, const IV2 b)
{
    IV2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

IV2 
CG_IV2_Sub(const IV2 a, const IV2 b) 
{
    IV2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

IV2 
CG_IV2_Mul_Scalar(const IV2 a, const s32 scalar)
{
    IV2 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    return result;
}

s32
CG_IV2_Length(const IV2 a) 
{
    return sqrt( (a.x * a.x) + (a.y * a.y) );
}

IV2
CG_IV2_Normalize(const IV2 a)
{
    IV2 result;
    s32 length = CG_IV2_Length(a);
    result.x = a.x / length;
    result.y = a.y / length;
    return result;
}

/** Float Vector **/

FV2 
CG_Add_FV2(const FV2 a, const FV2 b)
{
    FV2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

FV2 
CG_FV2_Sub(const FV2 a, const FV2 b) 
{
    FV2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

FV2 
CG_FV2_Mul_Scalar(const FV2 a, const s32 scalar)
{
    FV2 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    return result;
}

s32
CG_FV2_Length(const FV2 a) 
{
    return sqrt( (a.x * a.x) + (a.y * a.y) );
}

FV2
CG_FV2_Normalize(const FV2 a)
{
    FV2 result;
    s32 length = CG_FV2_Length(a);
    result.x = a.x / length;
    result.y = a.y / length;
    return result;
}
