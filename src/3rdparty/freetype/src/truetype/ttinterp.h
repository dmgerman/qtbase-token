begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttinterp.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType bytecode interpreter (specification).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2007, 2010, 2012-2014 by                                */
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
name|__TTINTERP_H__
end_ifndef
begin_define
DECL|macro|__TTINTERP_H__
define|#
directive|define
name|__TTINTERP_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"ttobjs.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|TT_CONFIG_OPTION_STATIC_INTERPRETER
end_ifndef
begin_comment
comment|/* indirect implementation */
end_comment
begin_define
DECL|macro|EXEC_OP_
define|#
directive|define
name|EXEC_OP_
value|TT_ExecContext  exc,
end_define
begin_define
DECL|macro|EXEC_OP
define|#
directive|define
name|EXEC_OP
value|TT_ExecContext  exc
end_define
begin_define
DECL|macro|EXEC_ARG_
define|#
directive|define
name|EXEC_ARG_
value|exc,
end_define
begin_define
DECL|macro|EXEC_ARG
define|#
directive|define
name|EXEC_ARG
value|exc
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* static implementation */
end_comment
begin_define
define|#
directive|define
name|EXEC_OP_
end_define
begin_comment
comment|/* void */
end_comment
begin_define
define|#
directive|define
name|EXEC_OP
end_define
begin_comment
comment|/* void */
end_comment
begin_define
define|#
directive|define
name|EXEC_ARG_
end_define
begin_comment
comment|/* void */
end_comment
begin_define
define|#
directive|define
name|EXEC_ARG
end_define
begin_comment
comment|/* void */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_CONFIG_OPTION_STATIC_INTERPRETER */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Rounding mode constants.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|TT_Round_Off
define|#
directive|define
name|TT_Round_Off
value|5
end_define
begin_define
DECL|macro|TT_Round_To_Half_Grid
define|#
directive|define
name|TT_Round_To_Half_Grid
value|0
end_define
begin_define
DECL|macro|TT_Round_To_Grid
define|#
directive|define
name|TT_Round_To_Grid
value|1
end_define
begin_define
DECL|macro|TT_Round_To_Double_Grid
define|#
directive|define
name|TT_Round_To_Double_Grid
value|2
end_define
begin_define
DECL|macro|TT_Round_Up_To_Grid
define|#
directive|define
name|TT_Round_Up_To_Grid
value|4
end_define
begin_define
DECL|macro|TT_Round_Down_To_Grid
define|#
directive|define
name|TT_Round_Down_To_Grid
value|3
end_define
begin_define
DECL|macro|TT_Round_Super
define|#
directive|define
name|TT_Round_Super
value|6
end_define
begin_define
DECL|macro|TT_Round_Super_45
define|#
directive|define
name|TT_Round_Super_45
value|7
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Function types used by the interpreter, depending on various modes    */
end_comment
begin_comment
comment|/* (e.g. the rounding mode, whether to render a vertical or horizontal   */
end_comment
begin_comment
comment|/* line etc).                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* Rounding function */
end_comment
begin_typedef
typedef|typedef
name|FT_F26Dot6
function_decl|(
DECL|typedef|TT_Round_Func
modifier|*
name|TT_Round_Func
function_decl|)
parameter_list|(
name|EXEC_OP_
name|FT_F26Dot6
name|distance
parameter_list|,
name|FT_F26Dot6
name|compensation
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* Point displacement along the freedom vector routine */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|TT_Move_Func
modifier|*
name|TT_Move_Func
function_decl|)
parameter_list|(
name|EXEC_OP_
name|TT_GlyphZone
name|zone
parameter_list|,
name|FT_UShort
name|point
parameter_list|,
name|FT_F26Dot6
name|distance
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* Distance projection along one of the projection vectors */
end_comment
begin_typedef
typedef|typedef
name|FT_F26Dot6
function_decl|(
DECL|typedef|TT_Project_Func
modifier|*
name|TT_Project_Func
function_decl|)
parameter_list|(
name|EXEC_OP_
name|FT_Pos
name|dx
parameter_list|,
name|FT_Pos
name|dy
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* getting current ppem.  Take care of non-square pixels if necessary */
end_comment
begin_typedef
typedef|typedef
name|FT_Long
function_decl|(
DECL|typedef|TT_Cur_Ppem_Func
modifier|*
name|TT_Cur_Ppem_Func
function_decl|)
parameter_list|(
name|EXEC_OP
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* reading a cvt value.  Take care of non-square pixels if necessary */
end_comment
begin_typedef
typedef|typedef
name|FT_F26Dot6
function_decl|(
DECL|typedef|TT_Get_CVT_Func
modifier|*
name|TT_Get_CVT_Func
function_decl|)
parameter_list|(
name|EXEC_OP_
name|FT_ULong
name|idx
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* setting or moving a cvt value.  Take care of non-square pixels  */
end_comment
begin_comment
comment|/* if necessary                                                    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|TT_Set_CVT_Func
modifier|*
name|TT_Set_CVT_Func
function_decl|)
parameter_list|(
name|EXEC_OP_
name|FT_ULong
name|idx
parameter_list|,
name|FT_F26Dot6
name|value
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This structure defines a call record, used to manage function calls.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_CallRec_
typedef|typedef
struct|struct
name|TT_CallRec_
block|{
DECL|member|Caller_Range
name|FT_Int
name|Caller_Range
decl_stmt|;
DECL|member|Caller_IP
name|FT_Long
name|Caller_IP
decl_stmt|;
DECL|member|Cur_Count
name|FT_Long
name|Cur_Count
decl_stmt|;
DECL|member|Def
name|TT_DefRecord
modifier|*
name|Def
decl_stmt|;
comment|/* either FDEF or IDEF */
block|}
DECL|typedef|TT_CallRec
DECL|typedef|TT_CallStack
name|TT_CallRec
operator|,
typedef|*
name|TT_CallStack
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_SUBPIXEL_HINTING
end_ifdef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These structures define rules used to tweak subpixel hinting for      */
end_comment
begin_comment
comment|/* various fonts.  "", 0, "", NULL value indicates to match any value.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|SPH_MAX_NAME_SIZE
define|#
directive|define
name|SPH_MAX_NAME_SIZE
value|32
end_define
begin_define
DECL|macro|SPH_MAX_CLASS_MEMBERS
define|#
directive|define
name|SPH_MAX_CLASS_MEMBERS
value|100
end_define
begin_typedef
DECL|struct|SPH_TweakRule_
typedef|typedef
struct|struct
name|SPH_TweakRule_
block|{
DECL|member|family
specifier|const
name|char
name|family
index|[
name|SPH_MAX_NAME_SIZE
index|]
decl_stmt|;
DECL|member|ppem
specifier|const
name|FT_UInt
name|ppem
decl_stmt|;
DECL|member|style
specifier|const
name|char
name|style
index|[
name|SPH_MAX_NAME_SIZE
index|]
decl_stmt|;
DECL|member|glyph
specifier|const
name|FT_ULong
name|glyph
decl_stmt|;
block|}
DECL|typedef|SPH_TweakRule
name|SPH_TweakRule
typedef|;
end_typedef
begin_typedef
DECL|struct|SPH_ScaleRule_
typedef|typedef
struct|struct
name|SPH_ScaleRule_
block|{
DECL|member|family
specifier|const
name|char
name|family
index|[
name|SPH_MAX_NAME_SIZE
index|]
decl_stmt|;
DECL|member|ppem
specifier|const
name|FT_UInt
name|ppem
decl_stmt|;
DECL|member|style
specifier|const
name|char
name|style
index|[
name|SPH_MAX_NAME_SIZE
index|]
decl_stmt|;
DECL|member|glyph
specifier|const
name|FT_ULong
name|glyph
decl_stmt|;
DECL|member|scale
specifier|const
name|FT_ULong
name|scale
decl_stmt|;
block|}
DECL|typedef|SPH_ScaleRule
name|SPH_ScaleRule
typedef|;
end_typedef
begin_typedef
DECL|struct|SPH_Font_Class_
typedef|typedef
struct|struct
name|SPH_Font_Class_
block|{
DECL|member|name
specifier|const
name|char
name|name
index|[
name|SPH_MAX_NAME_SIZE
index|]
decl_stmt|;
DECL|member|member
specifier|const
name|char
name|member
index|[
name|SPH_MAX_CLASS_MEMBERS
index|]
index|[
name|SPH_MAX_NAME_SIZE
index|]
decl_stmt|;
block|}
DECL|typedef|SPH_Font_Class
name|SPH_Font_Class
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_CONFIG_OPTION_SUBPIXEL_HINTING */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The main structure for the interpreter which collects all necessary   */
end_comment
begin_comment
comment|/* variables and states.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_ExecContextRec_
typedef|typedef
struct|struct
name|TT_ExecContextRec_
block|{
DECL|member|face
name|TT_Face
name|face
decl_stmt|;
DECL|member|size
name|TT_Size
name|size
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
comment|/* instructions state */
DECL|member|error
name|FT_Error
name|error
decl_stmt|;
comment|/* last execution error */
DECL|member|top
name|FT_Long
name|top
decl_stmt|;
comment|/* top of exec. stack   */
DECL|member|stackSize
name|FT_UInt
name|stackSize
decl_stmt|;
comment|/* size of exec. stack  */
DECL|member|stack
name|FT_Long
modifier|*
name|stack
decl_stmt|;
comment|/* current exec. stack  */
DECL|member|args
name|FT_Long
name|args
decl_stmt|;
DECL|member|new_top
name|FT_UInt
name|new_top
decl_stmt|;
comment|/* new top after exec.  */
DECL|member|zp0
name|TT_GlyphZoneRec
name|zp0
decl_stmt|,
comment|/* zone records */
DECL|member|zp1
name|zp1
decl_stmt|,
DECL|member|zp2
name|zp2
decl_stmt|,
DECL|member|pts
name|pts
decl_stmt|,
DECL|member|twilight
name|twilight
decl_stmt|;
DECL|member|metrics
name|FT_Size_Metrics
name|metrics
decl_stmt|;
DECL|member|tt_metrics
name|TT_Size_Metrics
name|tt_metrics
decl_stmt|;
comment|/* size metrics */
DECL|member|GS
name|TT_GraphicsState
name|GS
decl_stmt|;
comment|/* current graphics state */
DECL|member|curRange
name|FT_Int
name|curRange
decl_stmt|;
comment|/* current code range number   */
DECL|member|code
name|FT_Byte
modifier|*
name|code
decl_stmt|;
comment|/* current code range          */
DECL|member|IP
name|FT_Long
name|IP
decl_stmt|;
comment|/* current instruction pointer */
DECL|member|codeSize
name|FT_Long
name|codeSize
decl_stmt|;
comment|/* size of current range       */
DECL|member|opcode
name|FT_Byte
name|opcode
decl_stmt|;
comment|/* current opcode              */
DECL|member|length
name|FT_Int
name|length
decl_stmt|;
comment|/* length of current opcode    */
DECL|member|step_ins
name|FT_Bool
name|step_ins
decl_stmt|;
comment|/* true if the interpreter must */
comment|/* increment IP after ins. exec */
DECL|member|cvtSize
name|FT_ULong
name|cvtSize
decl_stmt|;
DECL|member|cvt
name|FT_Long
modifier|*
name|cvt
decl_stmt|;
DECL|member|glyphSize
name|FT_UInt
name|glyphSize
decl_stmt|;
comment|/* glyph instructions buffer size */
DECL|member|glyphIns
name|FT_Byte
modifier|*
name|glyphIns
decl_stmt|;
comment|/* glyph instructions buffer */
DECL|member|numFDefs
name|FT_UInt
name|numFDefs
decl_stmt|;
comment|/* number of function defs         */
DECL|member|maxFDefs
name|FT_UInt
name|maxFDefs
decl_stmt|;
comment|/* maximum number of function defs */
DECL|member|FDefs
name|TT_DefArray
name|FDefs
decl_stmt|;
comment|/* table of FDefs entries          */
DECL|member|numIDefs
name|FT_UInt
name|numIDefs
decl_stmt|;
comment|/* number of instruction defs */
DECL|member|maxIDefs
name|FT_UInt
name|maxIDefs
decl_stmt|;
comment|/* maximum number of ins defs */
DECL|member|IDefs
name|TT_DefArray
name|IDefs
decl_stmt|;
comment|/* table of IDefs entries     */
DECL|member|maxFunc
name|FT_UInt
name|maxFunc
decl_stmt|;
comment|/* maximum function index     */
DECL|member|maxIns
name|FT_UInt
name|maxIns
decl_stmt|;
comment|/* maximum instruction index  */
DECL|member|callTop
name|FT_Int
name|callTop
decl_stmt|,
comment|/* top of call stack during execution */
DECL|member|callSize
name|callSize
decl_stmt|;
comment|/* size of call stack */
DECL|member|callStack
name|TT_CallStack
name|callStack
decl_stmt|;
comment|/* call stack */
DECL|member|maxPoints
name|FT_UShort
name|maxPoints
decl_stmt|;
comment|/* capacity of this context's `pts' */
DECL|member|maxContours
name|FT_Short
name|maxContours
decl_stmt|;
comment|/* record, expressed in points and  */
comment|/* contours.                        */
DECL|member|codeRangeTable
name|TT_CodeRangeTable
name|codeRangeTable
decl_stmt|;
comment|/* table of valid code ranges */
comment|/* useful for the debugger   */
DECL|member|storeSize
name|FT_UShort
name|storeSize
decl_stmt|;
comment|/* size of current storage */
DECL|member|storage
name|FT_Long
modifier|*
name|storage
decl_stmt|;
comment|/* storage area            */
DECL|member|period
name|FT_F26Dot6
name|period
decl_stmt|;
comment|/* values used for the */
DECL|member|phase
name|FT_F26Dot6
name|phase
decl_stmt|;
comment|/* `SuperRounding'     */
DECL|member|threshold
name|FT_F26Dot6
name|threshold
decl_stmt|;
DECL|member|instruction_trap
name|FT_Bool
name|instruction_trap
decl_stmt|;
comment|/* If `True', the interpreter will */
comment|/* exit after each instruction     */
DECL|member|default_GS
name|TT_GraphicsState
name|default_GS
decl_stmt|;
comment|/* graphics state resulting from   */
comment|/* the prep program                */
DECL|member|is_composite
name|FT_Bool
name|is_composite
decl_stmt|;
comment|/* true if the glyph is composite  */
DECL|member|pedantic_hinting
name|FT_Bool
name|pedantic_hinting
decl_stmt|;
comment|/* true if pedantic interpretation */
comment|/* latest interpreter additions */
DECL|member|F_dot_P
name|FT_Long
name|F_dot_P
decl_stmt|;
comment|/* dot product of freedom and projection */
comment|/* vectors                               */
DECL|member|func_round
name|TT_Round_Func
name|func_round
decl_stmt|;
comment|/* current rounding function             */
DECL|member|func_project
name|TT_Project_Func
name|func_project
decl_stmt|,
comment|/* current projection function */
DECL|member|func_dualproj
name|func_dualproj
decl_stmt|,
comment|/* current dual proj. function */
DECL|member|func_freeProj
name|func_freeProj
decl_stmt|;
comment|/* current freedom proj. func  */
DECL|member|func_move
name|TT_Move_Func
name|func_move
decl_stmt|;
comment|/* current point move function */
DECL|member|func_move_orig
name|TT_Move_Func
name|func_move_orig
decl_stmt|;
comment|/* move original position function */
DECL|member|func_cur_ppem
name|TT_Cur_Ppem_Func
name|func_cur_ppem
decl_stmt|;
comment|/* get current proj. ppem value  */
DECL|member|func_read_cvt
name|TT_Get_CVT_Func
name|func_read_cvt
decl_stmt|;
comment|/* read a cvt entry              */
DECL|member|func_write_cvt
name|TT_Set_CVT_Func
name|func_write_cvt
decl_stmt|;
comment|/* write a cvt entry (in pixels) */
DECL|member|func_move_cvt
name|TT_Set_CVT_Func
name|func_move_cvt
decl_stmt|;
comment|/* incr a cvt entry (in pixels)  */
DECL|member|grayscale
name|FT_Bool
name|grayscale
decl_stmt|;
comment|/* are we hinting for grayscale? */
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_SUBPIXEL_HINTING
DECL|member|func_round_sphn
name|TT_Round_Func
name|func_round_sphn
decl_stmt|;
comment|/* subpixel rounding function */
DECL|member|subpixel
name|FT_Bool
name|subpixel
decl_stmt|;
comment|/* Using subpixel hinting?       */
DECL|member|ignore_x_mode
name|FT_Bool
name|ignore_x_mode
decl_stmt|;
comment|/* Standard rendering mode for   */
comment|/* subpixel hinting.  On if gray */
comment|/* or subpixel hinting is on.    */
comment|/* The following 4 aren't fully implemented but here for MS rasterizer */
comment|/* compatibility.                                                      */
DECL|member|compatible_widths
name|FT_Bool
name|compatible_widths
decl_stmt|;
comment|/* compatible widths?        */
DECL|member|symmetrical_smoothing
name|FT_Bool
name|symmetrical_smoothing
decl_stmt|;
comment|/* symmetrical_smoothing?    */
DECL|member|bgr
name|FT_Bool
name|bgr
decl_stmt|;
comment|/* bgr instead of rgb?       */
DECL|member|subpixel_positioned
name|FT_Bool
name|subpixel_positioned
decl_stmt|;
comment|/* subpixel positioned       */
comment|/* (DirectWrite ClearType)?  */
DECL|member|rasterizer_version
name|FT_Int
name|rasterizer_version
decl_stmt|;
comment|/* MS rasterizer version     */
DECL|member|iup_called
name|FT_Bool
name|iup_called
decl_stmt|;
comment|/* IUP called for glyph?     */
DECL|member|sph_tweak_flags
name|FT_ULong
name|sph_tweak_flags
decl_stmt|;
comment|/* flags to control          */
comment|/* hint tweaks               */
DECL|member|sph_in_func_flags
name|FT_ULong
name|sph_in_func_flags
decl_stmt|;
comment|/* flags to indicate if in   */
comment|/* special functions         */
endif|#
directive|endif
comment|/* TT_CONFIG_OPTION_SUBPIXEL_HINTING */
block|}
DECL|typedef|TT_ExecContextRec
name|TT_ExecContextRec
typedef|;
end_typedef
begin_decl_stmt
specifier|extern
specifier|const
name|TT_GraphicsState
name|tt_default_graphics_state
decl_stmt|;
end_decl_stmt
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
name|TT_Goto_CodeRange
argument_list|(
argument|TT_ExecContext  exec
argument_list|,
argument|FT_Int          range
argument_list|,
argument|FT_Long         IP
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
name|TT_Set_CodeRange
argument_list|(
argument|TT_ExecContext  exec
argument_list|,
argument|FT_Int          range
argument_list|,
argument|void*           base
argument_list|,
argument|FT_Long         length
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
name|TT_Clear_CodeRange
argument_list|(
argument|TT_ExecContext  exec
argument_list|,
argument|FT_Int          range
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
name|Update_Max
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_ULong*  size
argument_list|,
argument|FT_Long    multiplier
argument_list|,
argument|void*      _pbuff
argument_list|,
argument|FT_ULong   new_max
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    TT_New_Context                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Queries the face context for a given font.  Note that there is     */
end_comment
begin_comment
comment|/*    now a _single_ execution context in the TrueType driver which is   */
end_comment
begin_comment
comment|/*    shared among faces.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the source face object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A handle to the execution context.  Initialized for `face'.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Only the glyph loader and debugger should call this function.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|TT_ExecContext
argument_list|)
end_macro
begin_macro
DECL|variable|TT_New_Context
name|TT_New_Context
argument_list|(
argument|TT_Driver  driver
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|TT_New_Context
empty_stmt|;
end_empty_stmt
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
DECL|variable|exec
name|TT_Done_Context
argument_list|(
argument|TT_ExecContext  exec
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|exec
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|TT_Load_Context
argument_list|(
argument|TT_ExecContext  exec
argument_list|,
argument|TT_Face         face
argument_list|,
argument|TT_Size         size
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
DECL|variable|TT_Save_Context
name|TT_Save_Context
argument_list|(
argument|TT_ExecContext  exec
argument_list|,
argument|TT_Size         ins
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
name|TT_Run_Context
argument_list|(
argument|TT_ExecContext  exec
argument_list|,
argument|FT_Bool         debug
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    TT_RunIns                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Executes one or more instruction in the execution context.  This   */
end_comment
begin_comment
comment|/*    is the main function of the TrueType opcode interpreter.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    exec :: A handle to the target execution context.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Only the object manager and debugger should call this function.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function is publicly exported because it is directly          */
end_comment
begin_comment
comment|/*    invoked by the TrueType debugger.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|TT_RunIns
name|TT_RunIns
argument_list|(
argument|TT_ExecContext  exec
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|TT_RunIns
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
comment|/* __TTINTERP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
