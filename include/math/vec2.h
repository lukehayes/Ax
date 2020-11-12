#ifndef _CG_VEC2_H_
#define _CG_VEC2_H_

#include "common/types.h"


/** Generic Functions **/
#define Add_V2(a,b, Type) \
    CG_Add_##Type( (a),(b) );

#define Norm_V2(a, Type) \
    CG_Normalize_##Type( (a) );

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
CG_Sub_IV2(const IV2, const IV2);

IV2 
CG_Mul_IV2_Scalar(const IV2, const s32);

IV2 
CG_Div_IV2(const IV2, const IV2);

s32
CG_Length_IV2(const IV2);

IV2
CG_Normalize_IV2(const IV2);

/** Float Version **/

FV2 
CG_Add_FV2(const FV2, const FV2);

FV2 
CG_Sub_FV2(const FV2, const FV2);

FV2 
CG_Mul_Scalar_FV2(const FV2, const s32);

FV2 
CG_Div_FV2(const FV2, const FV2);

s32
CG_Length_FV2(const FV2);

FV2
CG_Normalize_FV2(const FV2);




#endif

