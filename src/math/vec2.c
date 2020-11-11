#include "math/vec2.h"
#include <math.h>

IV2 
CG_IV2_Add(const IV2 a, const IV2 b)
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
    return sqrt(a.x * a.x + a.y * a.y);
}

u8
CG_IV2_Normalize(const IV2 a)
{
    return 1;
}
