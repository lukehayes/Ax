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
    srand(time(NULL));
    return rand() % (min + 1 - max) + min;
}

#endif
