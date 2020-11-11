#ifndef _CG_VEC2_H_
#define _CG_VEC2_H_

#include "common/types.h"


/** Generic Functions **/
#define Add_V2(a,b, Type) \
    CG_Add_##Type( (a),(b) );

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
CG_Add_IV2(const IV2, const IV2);

IV2 
CG_IV2_Sub(const IV2, const IV2);

IV2 
CG_IV2_Mul_Scalar(const IV2, const s32);

IV2 
CG_IV2_Div(const IV2, const IV2);

s32
CG_IV2_Length(const IV2);

IV2
CG_IV2_Normalize(const IV2);

FV2 
CG_Add_FV2(const FV2, const FV2);

FV2 
CG_FV2_Sub(const FV2, const FV2);

FV2 
CG_FV2_Mul_Scalar(const FV2, const s32);

FV2 
CG_FV2_Div(const FV2, const FV2);

s32
CG_FV2_Length(const FV2);

FV2
CG_FV2_Normalize(const FV2);




#endif

