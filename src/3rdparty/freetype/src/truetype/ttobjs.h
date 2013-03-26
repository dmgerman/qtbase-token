begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttobjs.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Objects manager (specification).                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 by */
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
begin_ifndef
ifndef|#
directive|ifndef
name|__TTOBJS_H__
end_ifndef
begin_define
DECL|macro|__TTOBJS_H__
define|#
directive|define
name|__TTOBJS_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TRUETYPE_TYPES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    TT_Driver                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a TrueType driver object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|TT_Driver
typedef|typedef
name|struct
name|TT_DriverRec_
modifier|*
name|TT_Driver
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    TT_Instance                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a TrueType size object.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|TT_Size
typedef|typedef
name|struct
name|TT_SizeRec_
modifier|*
name|TT_Size
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    TT_GlyphSlot                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a TrueType glyph slot object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This is a direct typedef of FT_GlyphSlot, as there is nothing      */
end_comment
begin_comment
comment|/*    specific about the TrueType glyph slot.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|TT_GlyphSlot
typedef|typedef
name|FT_GlyphSlot
name|TT_GlyphSlot
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    TT_GraphicsState                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The TrueType graphics state used during bytecode interpretation.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_GraphicsState_
typedef|typedef
struct|struct
name|TT_GraphicsState_
block|{
DECL|member|rp0
name|FT_UShort
name|rp0
decl_stmt|;
DECL|member|rp1
name|FT_UShort
name|rp1
decl_stmt|;
DECL|member|rp2
name|FT_UShort
name|rp2
decl_stmt|;
DECL|member|dualVector
name|FT_UnitVector
name|dualVector
decl_stmt|;
DECL|member|projVector
name|FT_UnitVector
name|projVector
decl_stmt|;
DECL|member|freeVector
name|FT_UnitVector
name|freeVector
decl_stmt|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_UNPATENTED_HINTING
DECL|member|both_x_axis
name|FT_Bool
name|both_x_axis
decl_stmt|;
endif|#
directive|endif
DECL|member|loop
name|FT_Long
name|loop
decl_stmt|;
DECL|member|minimum_distance
name|FT_F26Dot6
name|minimum_distance
decl_stmt|;
DECL|member|round_state
name|FT_Int
name|round_state
decl_stmt|;
DECL|member|auto_flip
name|FT_Bool
name|auto_flip
decl_stmt|;
DECL|member|control_value_cutin
name|FT_F26Dot6
name|control_value_cutin
decl_stmt|;
DECL|member|single_width_cutin
name|FT_F26Dot6
name|single_width_cutin
decl_stmt|;
DECL|member|single_width_value
name|FT_F26Dot6
name|single_width_value
decl_stmt|;
DECL|member|delta_base
name|FT_Short
name|delta_base
decl_stmt|;
DECL|member|delta_shift
name|FT_Short
name|delta_shift
decl_stmt|;
DECL|member|instruct_control
name|FT_Byte
name|instruct_control
decl_stmt|;
comment|/* According to Greg Hitchcock from Microsoft, the `scan_control'     */
comment|/* variable as documented in the TrueType specification is a 32-bit   */
comment|/* integer; the high-word part holds the SCANTYPE value, the low-word */
comment|/* part the SCANCTRL value.  We separate it into two fields.          */
DECL|member|scan_control
name|FT_Bool
name|scan_control
decl_stmt|;
DECL|member|scan_type
name|FT_Int
name|scan_type
decl_stmt|;
DECL|member|gep0
name|FT_UShort
name|gep0
decl_stmt|;
DECL|member|gep1
name|FT_UShort
name|gep1
decl_stmt|;
DECL|member|gep2
name|FT_UShort
name|gep2
decl_stmt|;
block|}
DECL|typedef|TT_GraphicsState
name|TT_GraphicsState
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|zone
name|tt_glyphzone_done
argument_list|(
argument|TT_GlyphZone  zone
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|zone
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_glyphzone_new
argument_list|(
argument|FT_Memory     memory
argument_list|,
argument|FT_UShort     maxPoints
argument_list|,
argument|FT_Short      maxContours
argument_list|,
argument|TT_GlyphZone  zone
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_USE_BYTECODE_INTERPRETER */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  EXECUTION SUBTABLES                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  These sub-tables relate to instruction execution.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|TT_MAX_CODE_RANGES
define|#
directive|define
name|TT_MAX_CODE_RANGES
value|3
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* There can only be 3 active code ranges at once:                       */
end_comment
begin_comment
comment|/*   - the Font Program                                                  */
end_comment
begin_comment
comment|/*   - the CVT Program                                                   */
end_comment
begin_comment
comment|/*   - a glyph's instructions set                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|TT_CodeRange_Tag_
typedef|typedef
enum|enum
name|TT_CodeRange_Tag_
block|{
DECL|enumerator|tt_coderange_none
name|tt_coderange_none
init|=
literal|0
block|,
DECL|enumerator|tt_coderange_font
name|tt_coderange_font
block|,
DECL|enumerator|tt_coderange_cvt
name|tt_coderange_cvt
block|,
DECL|enumerator|tt_coderange_glyph
name|tt_coderange_glyph
block|}
DECL|typedef|TT_CodeRange_Tag
name|TT_CodeRange_Tag
typedef|;
end_typedef
begin_typedef
DECL|struct|TT_CodeRange_
typedef|typedef
struct|struct
name|TT_CodeRange_
block|{
DECL|member|base
name|FT_Byte
modifier|*
name|base
decl_stmt|;
DECL|member|size
name|FT_ULong
name|size
decl_stmt|;
block|}
DECL|typedef|TT_CodeRange
name|TT_CodeRange
typedef|;
end_typedef
begin_typedef
DECL|typedef|TT_CodeRangeTable
typedef|typedef
name|TT_CodeRange
name|TT_CodeRangeTable
index|[
name|TT_MAX_CODE_RANGES
index|]
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Defines a function/instruction definition record.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_DefRecord_
typedef|typedef
struct|struct
name|TT_DefRecord_
block|{
DECL|member|range
name|FT_Int
name|range
decl_stmt|;
comment|/* in which code range is it located? */
DECL|member|start
name|FT_Long
name|start
decl_stmt|;
comment|/* where does it start?               */
DECL|member|opc
name|FT_UInt
name|opc
decl_stmt|;
comment|/* function #, or instruction code    */
DECL|member|active
name|FT_Bool
name|active
decl_stmt|;
comment|/* is it active?                      */
block|}
DECL|typedef|TT_DefRecord
DECL|typedef|TT_DefArray
name|TT_DefRecord
operator|,
typedef|*
name|TT_DefArray
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Subglyph transformation record.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Transform_
typedef|typedef
struct|struct
name|TT_Transform_
block|{
DECL|member|xx
DECL|member|xy
name|FT_Fixed
name|xx
decl_stmt|,
name|xy
decl_stmt|;
comment|/* transformation matrix coefficients */
DECL|member|yx
DECL|member|yy
name|FT_Fixed
name|yx
decl_stmt|,
name|yy
decl_stmt|;
DECL|member|ox
DECL|member|oy
name|FT_F26Dot6
name|ox
decl_stmt|,
name|oy
decl_stmt|;
comment|/* offsets        */
block|}
DECL|typedef|TT_Transform
name|TT_Transform
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A note regarding non-squared pixels:                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* (This text will probably go into some docs at some time; for now, it  */
end_comment
begin_comment
comment|/* is kept here to explain some definitions in the TT_Size_Metrics       */
end_comment
begin_comment
comment|/* record).                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The CVT is a one-dimensional array containing values that control     */
end_comment
begin_comment
comment|/* certain important characteristics in a font, like the height of all   */
end_comment
begin_comment
comment|/* capitals, all lowercase letter, default spacing or stem width/height. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These values are found in FUnits in the font file, and must be scaled */
end_comment
begin_comment
comment|/* to pixel coordinates before being used by the CVT and glyph programs. */
end_comment
begin_comment
comment|/* Unfortunately, when using distinct x and y resolutions (or distinct x */
end_comment
begin_comment
comment|/* and y pointsizes), there are two possible scalings.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A first try was to implement a `lazy' scheme where all values were    */
end_comment
begin_comment
comment|/* scaled when first used.  However, while some values are always used   */
end_comment
begin_comment
comment|/* in the same direction, some others are used under many different      */
end_comment
begin_comment
comment|/* circumstances and orientations.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* I have found a simpler way to do the same, and it even seems to work  */
end_comment
begin_comment
comment|/* in most of the cases:                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* - All CVT values are scaled to the maximum ppem size.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* - When performing a read or write in the CVT, a ratio factor is used  */
end_comment
begin_comment
comment|/*   to perform adequate scaling.  Example:                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     x_ppem = 14                                                       */
end_comment
begin_comment
comment|/*     y_ppem = 10                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   We choose ppem = x_ppem = 14 as the CVT scaling size.  All cvt      */
end_comment
begin_comment
comment|/*   entries are scaled to it.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     x_ratio = 1.0                                                     */
end_comment
begin_comment
comment|/*     y_ratio = y_ppem/ppem (< 1.0)                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   We compute the current ratio like:                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - If projVector is horizontal,                                      */
end_comment
begin_comment
comment|/*       ratio = x_ratio = 1.0                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - if projVector is vertical,                                        */
end_comment
begin_comment
comment|/*       ratio = y_ratio                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   - else,                                                             */
end_comment
begin_comment
comment|/*       ratio = sqrt( (proj.x * x_ratio) ^ 2 + (proj.y * y_ratio) ^ 2 ) */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Reading a cvt value returns                                         */
end_comment
begin_comment
comment|/*     ratio * cvt[index]                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Writing a cvt value in pixels:                                      */
end_comment
begin_comment
comment|/*     cvt[index] / ratio                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   The current ppem is simply                                          */
end_comment
begin_comment
comment|/*     ratio * ppem                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Metrics used by the TrueType size and context objects.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Size_Metrics_
typedef|typedef
struct|struct
name|TT_Size_Metrics_
block|{
comment|/* for non-square pixels */
DECL|member|x_ratio
name|FT_Long
name|x_ratio
decl_stmt|;
DECL|member|y_ratio
name|FT_Long
name|y_ratio
decl_stmt|;
DECL|member|ppem
name|FT_UShort
name|ppem
decl_stmt|;
comment|/* maximum ppem size              */
DECL|member|ratio
name|FT_Long
name|ratio
decl_stmt|;
comment|/* current ratio                  */
DECL|member|scale
name|FT_Fixed
name|scale
decl_stmt|;
DECL|member|compensations
name|FT_F26Dot6
name|compensations
index|[
literal|4
index|]
decl_stmt|;
comment|/* device-specific compensations  */
DECL|member|valid
name|FT_Bool
name|valid
decl_stmt|;
DECL|member|rotated
name|FT_Bool
name|rotated
decl_stmt|;
comment|/* `is the glyph rotated?'-flag   */
DECL|member|stretched
name|FT_Bool
name|stretched
decl_stmt|;
comment|/* `is the glyph stretched?'-flag */
block|}
DECL|typedef|TT_Size_Metrics
name|TT_Size_Metrics
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* TrueType size class.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SizeRec_
typedef|typedef
struct|struct
name|TT_SizeRec_
block|{
DECL|member|root
name|FT_SizeRec
name|root
decl_stmt|;
comment|/* we have our own copy of metrics so that we can modify */
comment|/* it without affecting auto-hinting (when used)         */
DECL|member|metrics
name|FT_Size_Metrics
name|metrics
decl_stmt|;
DECL|member|ttmetrics
name|TT_Size_Metrics
name|ttmetrics
decl_stmt|;
DECL|member|strike_index
name|FT_ULong
name|strike_index
decl_stmt|;
comment|/* 0xFFFFFFFF to indicate invalid */
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
DECL|member|num_function_defs
name|FT_UInt
name|num_function_defs
decl_stmt|;
comment|/* number of function definitions */
DECL|member|max_function_defs
name|FT_UInt
name|max_function_defs
decl_stmt|;
DECL|member|function_defs
name|TT_DefArray
name|function_defs
decl_stmt|;
comment|/* table of function definitions  */
DECL|member|num_instruction_defs
name|FT_UInt
name|num_instruction_defs
decl_stmt|;
comment|/* number of ins. definitions */
DECL|member|max_instruction_defs
name|FT_UInt
name|max_instruction_defs
decl_stmt|;
DECL|member|instruction_defs
name|TT_DefArray
name|instruction_defs
decl_stmt|;
comment|/* table of ins. definitions  */
DECL|member|max_func
name|FT_UInt
name|max_func
decl_stmt|;
DECL|member|max_ins
name|FT_UInt
name|max_ins
decl_stmt|;
DECL|member|codeRangeTable
name|TT_CodeRangeTable
name|codeRangeTable
decl_stmt|;
DECL|member|GS
name|TT_GraphicsState
name|GS
decl_stmt|;
DECL|member|cvt_size
name|FT_ULong
name|cvt_size
decl_stmt|;
comment|/* the scaled control value table */
DECL|member|cvt
name|FT_Long
modifier|*
name|cvt
decl_stmt|;
DECL|member|storage_size
name|FT_UShort
name|storage_size
decl_stmt|;
comment|/* The storage area is now part of */
DECL|member|storage
name|FT_Long
modifier|*
name|storage
decl_stmt|;
comment|/* the instance                    */
DECL|member|twilight
name|TT_GlyphZoneRec
name|twilight
decl_stmt|;
comment|/* The instance's twilight zone    */
comment|/* debugging variables */
comment|/* When using the debugger, we must keep the */
comment|/* execution context tied to the instance    */
comment|/* object rather than asking it on demand.   */
DECL|member|debug
name|FT_Bool
name|debug
decl_stmt|;
DECL|member|context
name|TT_ExecContext
name|context
decl_stmt|;
DECL|member|bytecode_ready
name|FT_Bool
name|bytecode_ready
decl_stmt|;
DECL|member|cvt_ready
name|FT_Bool
name|cvt_ready
decl_stmt|;
endif|#
directive|endif
comment|/* TT_USE_BYTECODE_INTERPRETER */
block|}
DECL|typedef|TT_SizeRec
name|TT_SizeRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* TrueType driver class.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_DriverRec_
typedef|typedef
struct|struct
name|TT_DriverRec_
block|{
DECL|member|root
name|FT_DriverRec
name|root
decl_stmt|;
DECL|member|context
name|TT_ExecContext
name|context
decl_stmt|;
comment|/* execution context        */
DECL|member|zone
name|TT_GlyphZoneRec
name|zone
decl_stmt|;
comment|/* glyph loader points zone */
DECL|member|extension_component
name|void
modifier|*
name|extension_component
decl_stmt|;
block|}
DECL|typedef|TT_DriverRec
name|TT_DriverRec
typedef|;
end_typedef
begin_comment
comment|/* Note: All of the functions below (except tt_size_reset()) are used    */
end_comment
begin_comment
comment|/* as function pointers in a FT_Driver_ClassRec.  Therefore their        */
end_comment
begin_comment
comment|/* parameters are of types FT_Face, FT_Size, etc., rather than TT_Face,  */
end_comment
begin_comment
comment|/* TT_Size, etc., so that the compiler can confirm that the types and    */
end_comment
begin_comment
comment|/* number of parameters are correct.  In all cases the FT_xxx types are  */
end_comment
begin_comment
comment|/* cast to their TT_xxx counterparts inside the functions since FreeType */
end_comment
begin_comment
comment|/* will always use the TT driver to create them.                         */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Face functions                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_init
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|FT_Face        ttface
argument_list|,
comment|/* TT_Face */
argument|FT_Int         face_index
argument_list|,
argument|FT_Int         num_params
argument_list|,
argument|FT_Parameter*  params
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|tt_face_done
name|tt_face_done
argument_list|(
argument|FT_Face  ttface
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_face_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|tt_face_done
comment|/* TT_Face */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Size functions                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_size_init
argument_list|(
argument|FT_Size  ttsize
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* TT_Size */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|tt_size_done
name|tt_size_done
argument_list|(
argument|FT_Size  ttsize
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_size_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|tt_size_done
comment|/* TT_Size */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_size_run_fpgm
argument_list|(
argument|TT_Size  size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_size_run_prep
name|tt_size_run_prep
argument_list|(
argument|TT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_size_run_prep
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_size_ready_bytecode
argument_list|(
argument|TT_Size  size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_USE_BYTECODE_INTERPRETER */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|tt_size_reset
name|tt_size_reset
argument_list|(
argument|TT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_size_reset
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Driver functions                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_driver_init
argument_list|(
argument|FT_Module  ttdriver
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* TT_Driver */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|tt_driver_done
name|tt_driver_done
argument_list|(
argument|FT_Module  ttdriver
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|tt_driver_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|tt_driver_done
comment|/* TT_Driver */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Slot functions                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_slot_init
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __TTOBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
