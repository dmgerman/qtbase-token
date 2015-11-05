begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pshrec.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Postscript (Type1/Type2) hints recorder (specification).             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001-2015 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/**************************************************************************/
end_comment
begin_comment
comment|/*                                                                        */
end_comment
begin_comment
comment|/*  The functions defined here are called from the Type 1, CID and CFF    */
end_comment
begin_comment
comment|/*  font drivers to record the hints of a given character/glyph.          */
end_comment
begin_comment
comment|/*                                                                        */
end_comment
begin_comment
comment|/*  The hints are recorded in a unified format, and are later processed   */
end_comment
begin_comment
comment|/*  by the `optimizer' and `fitter' to adjust the outlines to the pixel   */
end_comment
begin_comment
comment|/*  grid.                                                                 */
end_comment
begin_comment
comment|/*                                                                        */
end_comment
begin_comment
comment|/**************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__PSHREC_H__
end_ifndef
begin_define
DECL|macro|__PSHREC_H__
define|#
directive|define
name|__PSHREC_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_HINTS_H
end_include
begin_include
include|#
directive|include
file|"pshglob.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                 GLYPH HINTS RECORDER INTERNALS                *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* handle to hint record */
end_comment
begin_typedef
DECL|typedef|PS_Hint
typedef|typedef
name|struct
name|PS_HintRec_
modifier|*
name|PS_Hint
typedef|;
end_typedef
begin_comment
comment|/* hint types */
end_comment
begin_typedef
DECL|enum|PS_Hint_Type_
typedef|typedef
enum|enum
name|PS_Hint_Type_
block|{
DECL|enumerator|PS_HINT_TYPE_1
name|PS_HINT_TYPE_1
init|=
literal|1
block|,
DECL|enumerator|PS_HINT_TYPE_2
name|PS_HINT_TYPE_2
init|=
literal|2
block|}
DECL|typedef|PS_Hint_Type
name|PS_Hint_Type
typedef|;
end_typedef
begin_comment
comment|/* hint flags */
end_comment
begin_define
DECL|macro|PS_HINT_FLAG_GHOST
define|#
directive|define
name|PS_HINT_FLAG_GHOST
value|1U
end_define
begin_define
DECL|macro|PS_HINT_FLAG_BOTTOM
define|#
directive|define
name|PS_HINT_FLAG_BOTTOM
value|2U
end_define
begin_comment
comment|/* hint descriptor */
end_comment
begin_typedef
DECL|struct|PS_HintRec_
typedef|typedef
struct|struct
name|PS_HintRec_
block|{
DECL|member|pos
name|FT_Int
name|pos
decl_stmt|;
DECL|member|len
name|FT_Int
name|len
decl_stmt|;
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
block|}
DECL|typedef|PS_HintRec
name|PS_HintRec
typedef|;
end_typedef
begin_define
DECL|macro|ps_hint_is_active
define|#
directive|define
name|ps_hint_is_active
parameter_list|(
name|x
parameter_list|)
value|( (x)->flags& PS_HINT_FLAG_ACTIVE )
end_define
begin_define
DECL|macro|ps_hint_is_ghost
define|#
directive|define
name|ps_hint_is_ghost
parameter_list|(
name|x
parameter_list|)
value|( (x)->flags& PS_HINT_FLAG_GHOST  )
end_define
begin_define
DECL|macro|ps_hint_is_bottom
define|#
directive|define
name|ps_hint_is_bottom
parameter_list|(
name|x
parameter_list|)
value|( (x)->flags& PS_HINT_FLAG_BOTTOM )
end_define
begin_comment
comment|/* hints table descriptor */
end_comment
begin_typedef
DECL|struct|PS_Hint_TableRec_
typedef|typedef
struct|struct
name|PS_Hint_TableRec_
block|{
DECL|member|num_hints
name|FT_UInt
name|num_hints
decl_stmt|;
DECL|member|max_hints
name|FT_UInt
name|max_hints
decl_stmt|;
DECL|member|hints
name|PS_Hint
name|hints
decl_stmt|;
block|}
DECL|typedef|PS_Hint_TableRec
DECL|typedef|PS_Hint_Table
name|PS_Hint_TableRec
operator|,
typedef|*
name|PS_Hint_Table
typedef|;
end_typedef
begin_comment
comment|/* hint and counter mask descriptor */
end_comment
begin_typedef
DECL|struct|PS_MaskRec_
typedef|typedef
struct|struct
name|PS_MaskRec_
block|{
DECL|member|num_bits
name|FT_UInt
name|num_bits
decl_stmt|;
DECL|member|max_bits
name|FT_UInt
name|max_bits
decl_stmt|;
DECL|member|bytes
name|FT_Byte
modifier|*
name|bytes
decl_stmt|;
DECL|member|end_point
name|FT_UInt
name|end_point
decl_stmt|;
block|}
DECL|typedef|PS_MaskRec
DECL|typedef|PS_Mask
name|PS_MaskRec
operator|,
typedef|*
name|PS_Mask
typedef|;
end_typedef
begin_comment
comment|/* masks and counters table descriptor */
end_comment
begin_typedef
DECL|struct|PS_Mask_TableRec_
typedef|typedef
struct|struct
name|PS_Mask_TableRec_
block|{
DECL|member|num_masks
name|FT_UInt
name|num_masks
decl_stmt|;
DECL|member|max_masks
name|FT_UInt
name|max_masks
decl_stmt|;
DECL|member|masks
name|PS_Mask
name|masks
decl_stmt|;
block|}
DECL|typedef|PS_Mask_TableRec
DECL|typedef|PS_Mask_Table
name|PS_Mask_TableRec
operator|,
typedef|*
name|PS_Mask_Table
typedef|;
end_typedef
begin_comment
comment|/* dimension-specific hints descriptor */
end_comment
begin_typedef
DECL|struct|PS_DimensionRec_
typedef|typedef
struct|struct
name|PS_DimensionRec_
block|{
DECL|member|hints
name|PS_Hint_TableRec
name|hints
decl_stmt|;
DECL|member|masks
name|PS_Mask_TableRec
name|masks
decl_stmt|;
DECL|member|counters
name|PS_Mask_TableRec
name|counters
decl_stmt|;
block|}
DECL|typedef|PS_DimensionRec
DECL|typedef|PS_Dimension
name|PS_DimensionRec
operator|,
typedef|*
name|PS_Dimension
typedef|;
end_typedef
begin_comment
comment|/* glyph hints descriptor                                */
end_comment
begin_comment
comment|/* dimension 0 => X coordinates + vertical hints/stems   */
end_comment
begin_comment
comment|/* dimension 1 => Y coordinates + horizontal hints/stems */
end_comment
begin_typedef
DECL|struct|PS_HintsRec_
typedef|typedef
struct|struct
name|PS_HintsRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|error
name|FT_Error
name|error
decl_stmt|;
DECL|member|magic
name|FT_UInt32
name|magic
decl_stmt|;
DECL|member|hint_type
name|PS_Hint_Type
name|hint_type
decl_stmt|;
DECL|member|dimension
name|PS_DimensionRec
name|dimension
index|[
literal|2
index|]
decl_stmt|;
block|}
DECL|typedef|PS_HintsRec
DECL|typedef|PS_Hints
name|PS_HintsRec
operator|,
typedef|*
name|PS_Hints
typedef|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_comment
comment|/* initialize hints recorder */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ps_hints_init
argument_list|(
argument|PS_Hints   hints
argument_list|,
argument|FT_Memory  memory
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* finalize hints recorder */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|hints
name|ps_hints_done
argument_list|(
argument|PS_Hints  hints
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|hints
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* initialize Type1 hints recorder interface */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|funcs
name|t1_hints_funcs_init
argument_list|(
name|T1_Hints_FuncsRec
operator|*
name|funcs
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/* initialize Type2 hints recorder interface */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|funcs
name|t2_hints_funcs_init
argument_list|(
name|T2_Hints_FuncsRec
operator|*
name|funcs
argument_list|)
expr_stmt|;
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_HINTER
end_ifdef
begin_decl_stmt
specifier|extern
name|PS_Hints
name|ps_debug_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|int
name|ps_debug_no_horz_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|int
name|ps_debug_no_vert_hints
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PS_HINTER_RECORD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
