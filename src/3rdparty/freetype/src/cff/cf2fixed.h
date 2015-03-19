begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2fixed.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for Fixed Point Mathematics (specification only).       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007-2013 Adobe Systems Incorporated.                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This software, and all works of authorship, whether in source or       */
end_comment
begin_comment
comment|/*  object code form as indicated by the copyright notice(s) included      */
end_comment
begin_comment
comment|/*  herein (collectively, the "Work") is made available, and may only be   */
end_comment
begin_comment
comment|/*  used, modified, and distributed under the FreeType Project License,    */
end_comment
begin_comment
comment|/*  LICENSE.TXT.  Additionally, subject to the terms and conditions of the */
end_comment
begin_comment
comment|/*  FreeType Project License, each contributor to the Work hereby grants   */
end_comment
begin_comment
comment|/*  to any individual or legal entity exercising permissions granted by    */
end_comment
begin_comment
comment|/*  the FreeType Project License and this section (hereafter, "You" or     */
end_comment
begin_comment
comment|/*  "Your") a perpetual, worldwide, non-exclusive, no-charge,              */
end_comment
begin_comment
comment|/*  royalty-free, irrevocable (except as stated in this section) patent    */
end_comment
begin_comment
comment|/*  license to make, have made, use, offer to sell, sell, import, and      */
end_comment
begin_comment
comment|/*  otherwise transfer the Work, where such license applies only to those  */
end_comment
begin_comment
comment|/*  patent claims licensable by such contributor that are necessarily      */
end_comment
begin_comment
comment|/*  infringed by their contribution(s) alone or by combination of their    */
end_comment
begin_comment
comment|/*  contribution(s) with the Work to which such contribution(s) was        */
end_comment
begin_comment
comment|/*  submitted.  If You institute patent litigation against any entity      */
end_comment
begin_comment
comment|/*  (including a cross-claim or counterclaim in a lawsuit) alleging that   */
end_comment
begin_comment
comment|/*  the Work or a contribution incorporated within the Work constitutes    */
end_comment
begin_comment
comment|/*  direct or contributory patent infringement, then any patent licenses   */
end_comment
begin_comment
comment|/*  granted to You under this License for that Work shall terminate as of  */
end_comment
begin_comment
comment|/*  the date such litigation is filed.                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  By using, modifying, or distributing the Work you indicate that you    */
end_comment
begin_comment
comment|/*  have read and understood the terms and conditions of the               */
end_comment
begin_comment
comment|/*  FreeType Project License as well as those provided in this section,    */
end_comment
begin_comment
comment|/*  and you accept them fully.                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__CF2FIXED_H__
end_ifndef
begin_define
DECL|macro|__CF2FIXED_H__
define|#
directive|define
name|__CF2FIXED_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* rasterizer integer and fixed point arithmetic must be 32-bit */
end_comment
begin_define
DECL|macro|CF2_Fixed
define|#
directive|define
name|CF2_Fixed
value|CF2_F16Dot16
end_define
begin_typedef
DECL|typedef|CF2_Frac
typedef|typedef
name|FT_Int32
name|CF2_Frac
typedef|;
end_typedef
begin_comment
DECL|typedef|CF2_Frac
comment|/* 2.30 fixed point */
end_comment
begin_define
DECL|macro|CF2_FIXED_MAX
define|#
directive|define
name|CF2_FIXED_MAX
value|( (CF2_Fixed)0x7FFFFFFFL )
end_define
begin_define
DECL|macro|CF2_FIXED_MIN
define|#
directive|define
name|CF2_FIXED_MIN
value|( (CF2_Fixed)0x80000000L )
end_define
begin_define
DECL|macro|CF2_FIXED_ONE
define|#
directive|define
name|CF2_FIXED_ONE
value|0x10000L
end_define
begin_define
DECL|macro|CF2_FIXED_EPSILON
define|#
directive|define
name|CF2_FIXED_EPSILON
value|0x0001
end_define
begin_comment
comment|/* in C 89, left and right shift of negative numbers is  */
end_comment
begin_comment
comment|/* implementation specific behaviour in the general case */
end_comment
begin_define
DECL|macro|cf2_intToFixed
define|#
directive|define
name|cf2_intToFixed
parameter_list|(
name|i
parameter_list|)
define|\
value|( (CF2_Fixed)( (FT_UInt32)(i)<< 16 ) )
end_define
begin_define
DECL|macro|cf2_fixedToInt
define|#
directive|define
name|cf2_fixedToInt
parameter_list|(
name|x
parameter_list|)
define|\
value|( (FT_Short)( ( (FT_UInt32)(x) + 0x8000U )>> 16 ) )
end_define
begin_define
DECL|macro|cf2_fixedRound
define|#
directive|define
name|cf2_fixedRound
parameter_list|(
name|x
parameter_list|)
define|\
value|( (CF2_Fixed)( ( (x) + 0x8000 )& 0xFFFF0000L ) )
end_define
begin_define
DECL|macro|cf2_floatToFixed
define|#
directive|define
name|cf2_floatToFixed
parameter_list|(
name|f
parameter_list|)
define|\
value|( (CF2_Fixed)( (f) * 65536.0 + 0.5 ) )
end_define
begin_define
DECL|macro|cf2_fixedAbs
define|#
directive|define
name|cf2_fixedAbs
parameter_list|(
name|x
parameter_list|)
define|\
value|( (x)< 0 ? -(x) : (x) )
end_define
begin_define
DECL|macro|cf2_fixedFloor
define|#
directive|define
name|cf2_fixedFloor
parameter_list|(
name|x
parameter_list|)
define|\
value|( (CF2_Fixed)( (x)& 0xFFFF0000L ) )
end_define
begin_define
DECL|macro|cf2_fixedFraction
define|#
directive|define
name|cf2_fixedFraction
parameter_list|(
name|x
parameter_list|)
define|\
value|( (x) - cf2_fixedFloor( x ) )
end_define
begin_define
DECL|macro|cf2_fracToFixed
define|#
directive|define
name|cf2_fracToFixed
parameter_list|(
name|x
parameter_list|)
define|\
value|( (x)< 0 ? -( ( -(x) + 0x2000 )>> 14 )             \                     :  ( (  (x) + 0x2000 )>> 14 ) )
end_define
begin_comment
comment|/* signed numeric types */
end_comment
begin_typedef
DECL|enum|CF2_NumberType_
typedef|typedef
enum|enum
name|CF2_NumberType_
block|{
DECL|enumerator|CF2_NumberFixed
name|CF2_NumberFixed
block|,
comment|/* 16.16 */
DECL|enumerator|CF2_NumberFrac
name|CF2_NumberFrac
block|,
comment|/*  2.30 */
DECL|enumerator|CF2_NumberInt
name|CF2_NumberInt
comment|/* 32.0  */
block|}
DECL|typedef|CF2_NumberType
name|CF2_NumberType
typedef|;
end_typedef
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  __CF2FIXED_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
