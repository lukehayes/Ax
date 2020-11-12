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
CG_Sub_IV2(const IV2 a, const IV2 b) 
{
    IV2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

IV2 
CG_Mul_Scalar_IV2(const IV2 a, const s32 scalar)
{
    IV2 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    return result;
}

s32
CG_Length_IV2(const IV2 a) 
{
    return sqrt( (a.x * a.x) + (a.y * a.y) );
}

IV2
CG_Normalize_IV2(const IV2 a)
{
    IV2 result;
    s32 length = CG_Length_IV2(a);
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
CG_Sub_FV2(const FV2 a, const FV2 b) 
{
    FV2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

FV2 
CG_Mul_Scalar_FV2(const FV2 a, const s32 scalar)
{
    FV2 result;
    result.x = a.x * scalar;
    result.y = a.y * scalar;
    return result;
}

s32
CG_Length_FV2(const FV2 a) 
{
    return sqrt( (a.x * a.x) + (a.y * a.y) );
}

FV2
CG_Normalize_FV2(const FV2 a)
{
    FV2 result;
    s32 length = CG_Length_FV2(a);
    result.x = a.x / length;
    result.y = a.y / length;
    return result;
}
