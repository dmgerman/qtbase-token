begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2glue.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for shared stuff (specification only).                  */
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
name|__CF2GLUE_H__
end_ifndef
begin_define
DECL|macro|__CF2GLUE_H__
define|#
directive|define
name|__CF2GLUE_H__
end_define
begin_comment
comment|/* common includes for other modules */
end_comment
begin_include
include|#
directive|include
file|"cf2error.h"
end_include
begin_include
include|#
directive|include
file|"cf2fixed.h"
end_include
begin_include
include|#
directive|include
file|"cf2arrst.h"
end_include
begin_include
include|#
directive|include
file|"cf2read.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* rendering parameters */
end_comment
begin_comment
comment|/* apply hints to rendered glyphs */
end_comment
begin_define
DECL|macro|CF2_FlagsHinted
define|#
directive|define
name|CF2_FlagsHinted
value|1
end_define
begin_comment
comment|/* for testing */
end_comment
begin_define
DECL|macro|CF2_FlagsDarkened
define|#
directive|define
name|CF2_FlagsDarkened
value|2
end_define
begin_comment
comment|/* type for holding the flags */
end_comment
begin_typedef
DECL|typedef|CF2_RenderingFlags
typedef|typedef
name|CF2_Int
name|CF2_RenderingFlags
typedef|;
end_typedef
begin_comment
comment|/* elements of a glyph outline */
end_comment
begin_typedef
DECL|enum|CF2_PathOp_
typedef|typedef
enum|enum
name|CF2_PathOp_
block|{
DECL|enumerator|CF2_PathOpMoveTo
name|CF2_PathOpMoveTo
init|=
literal|1
block|,
comment|/* change the current point */
DECL|enumerator|CF2_PathOpLineTo
name|CF2_PathOpLineTo
init|=
literal|2
block|,
comment|/* line                     */
DECL|enumerator|CF2_PathOpQuadTo
name|CF2_PathOpQuadTo
init|=
literal|3
block|,
comment|/* quadratic curve          */
DECL|enumerator|CF2_PathOpCubeTo
name|CF2_PathOpCubeTo
init|=
literal|4
comment|/* cubic curve              */
block|}
DECL|typedef|CF2_PathOp
name|CF2_PathOp
typedef|;
end_typedef
begin_comment
comment|/* a matrix of fixed point values */
end_comment
begin_typedef
DECL|struct|CF2_Matrix_
typedef|typedef
struct|struct
name|CF2_Matrix_
block|{
DECL|member|a
name|CF2_F16Dot16
name|a
decl_stmt|;
DECL|member|b
name|CF2_F16Dot16
name|b
decl_stmt|;
DECL|member|c
name|CF2_F16Dot16
name|c
decl_stmt|;
DECL|member|d
name|CF2_F16Dot16
name|d
decl_stmt|;
DECL|member|tx
name|CF2_F16Dot16
name|tx
decl_stmt|;
DECL|member|ty
name|CF2_F16Dot16
name|ty
decl_stmt|;
block|}
DECL|typedef|CF2_Matrix
name|CF2_Matrix
typedef|;
end_typedef
begin_comment
comment|/* these typedefs are needed by more than one header file */
end_comment
begin_comment
comment|/* and gcc compiler doesn't allow redefinition            */
end_comment
begin_typedef
DECL|typedef|CF2_FontRec
DECL|typedef|CF2_Font
typedef|typedef
name|struct
name|CF2_FontRec_
name|CF2_FontRec
typedef|,
modifier|*
name|CF2_Font
typedef|;
end_typedef
begin_typedef
DECL|typedef|CF2_HintRec
DECL|typedef|CF2_Hint
typedef|typedef
name|struct
name|CF2_HintRec_
name|CF2_HintRec
typedef|,
modifier|*
name|CF2_Hint
typedef|;
end_typedef
begin_comment
comment|/* A common structure for all callback parameters.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Some members may be unused.  For example, `pt0' is not used for       */
end_comment
begin_comment
comment|/* `moveTo' and `pt3' is not used for `quadTo'.  The initial point `pt0' */
end_comment
begin_comment
comment|/* is included for each path element for generality; curve conversions   */
end_comment
begin_comment
comment|/* need it.  The `op' parameter allows one function to handle multiple   */
end_comment
begin_comment
comment|/* element types.                                                        */
end_comment
begin_typedef
DECL|struct|CF2_CallbackParamsRec_
typedef|typedef
struct|struct
name|CF2_CallbackParamsRec_
block|{
DECL|member|pt0
name|FT_Vector
name|pt0
decl_stmt|;
DECL|member|pt1
name|FT_Vector
name|pt1
decl_stmt|;
DECL|member|pt2
name|FT_Vector
name|pt2
decl_stmt|;
DECL|member|pt3
name|FT_Vector
name|pt3
decl_stmt|;
DECL|member|op
name|CF2_Int
name|op
decl_stmt|;
block|}
DECL|typedef|CF2_CallbackParamsRec
DECL|typedef|CF2_CallbackParams
name|CF2_CallbackParamsRec
operator|,
typedef|*
name|CF2_CallbackParams
typedef|;
end_typedef
begin_comment
comment|/* forward reference */
end_comment
begin_typedef
DECL|typedef|CF2_OutlineCallbacksRec
typedef|typedef
name|struct
name|CF2_OutlineCallbacksRec_
name|CF2_OutlineCallbacksRec
typedef|,
DECL|typedef|CF2_OutlineCallbacks
modifier|*
name|CF2_OutlineCallbacks
typedef|;
end_typedef
begin_comment
comment|/* callback function pointers */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|CF2_Callback_Type
modifier|*
name|CF2_Callback_Type
function_decl|)
parameter_list|(
name|CF2_OutlineCallbacks
name|callbacks
parameter_list|,
specifier|const
name|CF2_CallbackParams
name|params
parameter_list|)
function_decl|;
end_typedef
begin_struct
DECL|struct|CF2_OutlineCallbacksRec_
struct|struct
name|CF2_OutlineCallbacksRec_
block|{
DECL|member|moveTo
name|CF2_Callback_Type
name|moveTo
decl_stmt|;
DECL|member|lineTo
name|CF2_Callback_Type
name|lineTo
decl_stmt|;
DECL|member|quadTo
name|CF2_Callback_Type
name|quadTo
decl_stmt|;
DECL|member|cubeTo
name|CF2_Callback_Type
name|cubeTo
decl_stmt|;
DECL|member|windingMomentum
name|CF2_Int
name|windingMomentum
decl_stmt|;
comment|/* for winding order detection */
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|error
name|FT_Error
modifier|*
name|error
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CF2GLUE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
