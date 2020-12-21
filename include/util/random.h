#ifndef UTIL_RANDOM
#define UTIL_RANDOM

#include "common/types.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CG_RandRange
 *  Description:  Generate a random number from a given range
 * =====================================================================================
 */
s16 
CG_RandRange(s16 min, s16 max)
{
    return rand() % (min + 1 - max) + min;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  CG_RandRangeF
 *  Description:  Generate a random float from a given range
 * =====================================================================================
 */
f32 
CG_RandRangeF(f32 min, f32 max)
{
    f32 r = ((f32)rand()) / (f32)RAND_MAX;
    f32 diff = max - min;
    f32 rn = r * diff;
    return rn;
}


#endif
