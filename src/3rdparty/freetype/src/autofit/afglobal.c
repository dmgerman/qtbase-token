begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afglobal.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter routines to compute global hinting values (body).        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003-2015 by                                                 */
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
begin_include
include|#
directive|include
file|"afglobal.h"
end_include
begin_include
include|#
directive|include
file|"afranges.h"
end_include
begin_include
include|#
directive|include
file|"hbshim.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
end_comment
begin_comment
comment|/* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
end_comment
begin_comment
comment|/* messages during execution.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_afglobal
end_define
begin_comment
comment|/* get writing system specific header files */
end_comment
begin_undef
DECL|macro|WRITING_SYSTEM
undef|#
directive|undef
name|WRITING_SYSTEM
end_undef
begin_define
DECL|macro|WRITING_SYSTEM
define|#
directive|define
name|WRITING_SYSTEM
parameter_list|(
name|ws
parameter_list|,
name|WS
parameter_list|)
end_define
begin_comment
DECL|macro|WRITING_SYSTEM
comment|/* empty */
end_comment
begin_include
include|#
directive|include
file|"afwrtsys.h"
end_include
begin_include
include|#
directive|include
file|"aferrors.h"
end_include
begin_include
include|#
directive|include
file|"afpic.h"
end_include
begin_undef
DECL|macro|SCRIPT
undef|#
directive|undef
name|SCRIPT
end_undef
begin_define
DECL|macro|SCRIPT
define|#
directive|define
name|SCRIPT
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|h
parameter_list|,
name|sc1
parameter_list|,
name|sc2
parameter_list|,
name|sc3
parameter_list|)
define|\
value|AF_DEFINE_SCRIPT_CLASS(           \             af_ ## s ## _script_class,      \             AF_SCRIPT_ ## S,                \             af_ ## s ## _uniranges,         \             af_ ## s ## _nonbase_uniranges, \             sc1, sc2, sc3 )
end_define
begin_include
include|#
directive|include
file|"afscript.h"
end_include
begin_undef
DECL|macro|STYLE
undef|#
directive|undef
name|STYLE
end_undef
begin_define
DECL|macro|STYLE
define|#
directive|define
name|STYLE
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|ws
parameter_list|,
name|sc
parameter_list|,
name|ss
parameter_list|,
name|c
parameter_list|)
define|\
value|AF_DEFINE_STYLE_CLASS(         \             af_ ## s ## _style_class,    \             AF_STYLE_ ## S,              \             ws,                          \             sc,                          \             ss,                          \             c )
end_define
begin_include
include|#
directive|include
file|"afstyles.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_undef
DECL|macro|WRITING_SYSTEM
undef|#
directive|undef
name|WRITING_SYSTEM
end_undef
begin_define
DECL|macro|WRITING_SYSTEM
define|#
directive|define
name|WRITING_SYSTEM
parameter_list|(
name|ws
parameter_list|,
name|WS
parameter_list|)
define|\
value|&af_ ## ws ## _writing_system_class,
end_define
begin_macro
name|FT_LOCAL_ARRAY_DEF
argument_list|(
argument|AF_WritingSystemClass
argument_list|)
end_macro
begin_expr_stmt
name|af_writing_system_classes
index|[]
operator|=
block|{
include|#
directive|include
file|"afwrtsys.h"
name|NULL
comment|/* do not remove */
block|}
expr_stmt|;
end_expr_stmt
begin_undef
DECL|macro|SCRIPT
undef|#
directive|undef
name|SCRIPT
end_undef
begin_define
DECL|macro|SCRIPT
define|#
directive|define
name|SCRIPT
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|h
parameter_list|,
name|sc1
parameter_list|,
name|sc2
parameter_list|,
name|sc3
parameter_list|)
define|\
value|&af_ ## s ## _script_class,
end_define
begin_macro
name|FT_LOCAL_ARRAY_DEF
argument_list|(
argument|AF_ScriptClass
argument_list|)
end_macro
begin_expr_stmt
name|af_script_classes
index|[]
operator|=
block|{
include|#
directive|include
file|"afscript.h"
name|NULL
comment|/* do not remove */
block|}
expr_stmt|;
end_expr_stmt
begin_undef
DECL|macro|STYLE
undef|#
directive|undef
name|STYLE
end_undef
begin_define
DECL|macro|STYLE
define|#
directive|define
name|STYLE
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|ws
parameter_list|,
name|sc
parameter_list|,
name|ss
parameter_list|,
name|c
parameter_list|)
define|\
value|&af_ ## s ## _style_class,
end_define
begin_macro
name|FT_LOCAL_ARRAY_DEF
argument_list|(
argument|AF_StyleClass
argument_list|)
end_macro
begin_expr_stmt
name|af_style_classes
index|[]
operator|=
block|{
include|#
directive|include
file|"afstyles.h"
name|NULL
comment|/* do not remove */
block|}
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_PIC */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
end_ifdef
begin_undef
DECL|macro|STYLE
undef|#
directive|undef
name|STYLE
end_undef
begin_define
DECL|macro|STYLE
define|#
directive|define
name|STYLE
parameter_list|(
name|s
parameter_list|,
name|S
parameter_list|,
name|d
parameter_list|,
name|ws
parameter_list|,
name|sc
parameter_list|,
name|ss
parameter_list|,
name|c
parameter_list|)
value|#s,
end_define
begin_macro
name|FT_LOCAL_ARRAY_DEF
argument_list|(
argument|char*
argument_list|)
end_macro
begin_expr_stmt
name|af_style_names
index|[]
operator|=
block|{
include|#
directive|include
file|"afstyles.h"
block|}
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_DEBUG_LEVEL_TRACE */
end_comment
begin_comment
comment|/* Compute the style index of each glyph within a given face. */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|af_face_globals_compute_style_coverage
name|af_face_globals_compute_style_coverage
parameter_list|(
name|AF_FaceGlobals
name|globals
parameter_list|)
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Face
name|face
init|=
name|globals
operator|->
name|face
decl_stmt|;
name|FT_CharMap
name|old_charmap
init|=
name|face
operator|->
name|charmap
decl_stmt|;
name|FT_UShort
modifier|*
name|gstyles
init|=
name|globals
operator|->
name|glyph_styles
decl_stmt|;
name|FT_UInt
name|ss
decl_stmt|;
name|FT_UInt
name|i
decl_stmt|;
name|FT_UInt
name|dflt
init|=
operator|~
literal|0U
decl_stmt|;
comment|/* a non-valid value */
comment|/* the value AF_STYLE_UNASSIGNED means `uncovered glyph' */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
operator|(
name|FT_UInt
operator|)
name|globals
operator|->
name|glyph_count
condition|;
name|i
operator|++
control|)
name|gstyles
index|[
name|i
index|]
operator|=
name|AF_STYLE_UNASSIGNED
expr_stmt|;
name|error
operator|=
name|FT_Select_Charmap
argument_list|(
name|face
argument_list|,
name|FT_ENCODING_UNICODE
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
comment|/*        * Ignore this error; we simply use the fallback style.        * XXX: Shouldn't we rather disable hinting?        */
name|error
operator|=
name|FT_Err_Ok
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* scan each style in a Unicode charmap */
for|for
control|(
name|ss
operator|=
literal|0
init|;
name|AF_STYLE_CLASSES_GET
index|[
name|ss
index|]
condition|;
name|ss
operator|++
control|)
block|{
name|AF_StyleClass
name|style_class
init|=
name|AF_STYLE_CLASSES_GET
index|[
name|ss
index|]
decl_stmt|;
name|AF_ScriptClass
name|script_class
init|=
name|AF_SCRIPT_CLASSES_GET
index|[
name|style_class
operator|->
name|script
index|]
decl_stmt|;
name|AF_Script_UniRange
name|range
decl_stmt|;
if|if
condition|(
name|script_class
operator|->
name|script_uni_ranges
operator|==
name|NULL
condition|)
continue|continue;
comment|/*        *  Scan all Unicode points in the range and set the corresponding        *  glyph style index.        */
if|if
condition|(
name|style_class
operator|->
name|coverage
operator|==
name|AF_COVERAGE_DEFAULT
condition|)
block|{
if|if
condition|(
operator|(
name|FT_UInt
operator|)
name|style_class
operator|->
name|script
operator|==
name|globals
operator|->
name|module
operator|->
name|default_script
condition|)
name|dflt
operator|=
name|ss
expr_stmt|;
for|for
control|(
name|range
operator|=
name|script_class
operator|->
name|script_uni_ranges
init|;
name|range
operator|->
name|first
operator|!=
literal|0
condition|;
name|range
operator|++
control|)
block|{
name|FT_ULong
name|charcode
init|=
name|range
operator|->
name|first
decl_stmt|;
name|FT_UInt
name|gindex
decl_stmt|;
name|gindex
operator|=
name|FT_Get_Char_Index
argument_list|(
name|face
argument_list|,
name|charcode
argument_list|)
expr_stmt|;
if|if
condition|(
name|gindex
operator|!=
literal|0
operator|&&
name|gindex
operator|<
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
operator|&&
operator|(
name|gstyles
index|[
name|gindex
index|]
operator|&
name|AF_STYLE_MASK
operator|)
operator|==
name|AF_STYLE_UNASSIGNED
condition|)
name|gstyles
index|[
name|gindex
index|]
operator|=
operator|(
name|FT_UShort
operator|)
name|ss
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|charcode
operator|=
name|FT_Get_Next_Char
argument_list|(
name|face
argument_list|,
name|charcode
argument_list|,
operator|&
name|gindex
argument_list|)
expr_stmt|;
if|if
condition|(
name|gindex
operator|==
literal|0
operator|||
name|charcode
operator|>
name|range
operator|->
name|last
condition|)
break|break;
if|if
condition|(
name|gindex
operator|<
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
operator|&&
operator|(
name|gstyles
index|[
name|gindex
index|]
operator|&
name|AF_STYLE_MASK
operator|)
operator|==
name|AF_STYLE_UNASSIGNED
condition|)
name|gstyles
index|[
name|gindex
index|]
operator|=
operator|(
name|FT_UShort
operator|)
name|ss
expr_stmt|;
block|}
block|}
comment|/* do the same for the script's non-base characters */
for|for
control|(
name|range
operator|=
name|script_class
operator|->
name|script_uni_nonbase_ranges
init|;
name|range
operator|->
name|first
operator|!=
literal|0
condition|;
name|range
operator|++
control|)
block|{
name|FT_ULong
name|charcode
init|=
name|range
operator|->
name|first
decl_stmt|;
name|FT_UInt
name|gindex
decl_stmt|;
name|gindex
operator|=
name|FT_Get_Char_Index
argument_list|(
name|face
argument_list|,
name|charcode
argument_list|)
expr_stmt|;
if|if
condition|(
name|gindex
operator|!=
literal|0
operator|&&
name|gindex
operator|<
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
operator|&&
operator|(
name|gstyles
index|[
name|gindex
index|]
operator|&
name|AF_STYLE_MASK
operator|)
operator|==
operator|(
name|FT_UShort
operator|)
name|ss
condition|)
name|gstyles
index|[
name|gindex
index|]
operator||=
name|AF_NONBASE
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|charcode
operator|=
name|FT_Get_Next_Char
argument_list|(
name|face
argument_list|,
name|charcode
argument_list|,
operator|&
name|gindex
argument_list|)
expr_stmt|;
if|if
condition|(
name|gindex
operator|==
literal|0
operator|||
name|charcode
operator|>
name|range
operator|->
name|last
condition|)
break|break;
if|if
condition|(
name|gindex
operator|<
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
operator|&&
operator|(
name|gstyles
index|[
name|gindex
index|]
operator|&
name|AF_STYLE_MASK
operator|)
operator|==
operator|(
name|FT_UShort
operator|)
name|ss
condition|)
name|gstyles
index|[
name|gindex
index|]
operator||=
name|AF_NONBASE
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
comment|/* get glyphs not directly addressable by cmap */
name|af_get_coverage
argument_list|(
name|globals
argument_list|,
name|style_class
argument_list|,
name|gstyles
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* handle the default OpenType features of the default script ... */
name|af_get_coverage
argument_list|(
name|globals
argument_list|,
name|AF_STYLE_CLASSES_GET
index|[
name|dflt
index|]
argument_list|,
name|gstyles
argument_list|)
expr_stmt|;
comment|/* ... and the remaining default OpenType features */
for|for
control|(
name|ss
operator|=
literal|0
init|;
name|AF_STYLE_CLASSES_GET
index|[
name|ss
index|]
condition|;
name|ss
operator|++
control|)
block|{
name|AF_StyleClass
name|style_class
init|=
name|AF_STYLE_CLASSES_GET
index|[
name|ss
index|]
decl_stmt|;
if|if
condition|(
name|ss
operator|!=
name|dflt
operator|&&
name|style_class
operator|->
name|coverage
operator|==
name|AF_COVERAGE_DEFAULT
condition|)
name|af_get_coverage
argument_list|(
name|globals
argument_list|,
name|style_class
argument_list|,
name|gstyles
argument_list|)
expr_stmt|;
block|}
comment|/* mark ASCII digits */
for|for
control|(
name|i
operator|=
literal|0x30
init|;
name|i
operator|<=
literal|0x39
condition|;
name|i
operator|++
control|)
block|{
name|FT_UInt
name|gindex
init|=
name|FT_Get_Char_Index
argument_list|(
name|face
argument_list|,
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|gindex
operator|!=
literal|0
operator|&&
name|gindex
operator|<
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
condition|)
name|gstyles
index|[
name|gindex
index|]
operator||=
name|AF_DIGIT
expr_stmt|;
block|}
name|Exit
label|:
comment|/*      *  By default, all uncovered glyphs are set to the fallback style.      *  XXX: Shouldn't we disable hinting or do something similar?      */
if|if
condition|(
name|globals
operator|->
name|module
operator|->
name|fallback_style
operator|!=
name|AF_STYLE_UNASSIGNED
condition|)
block|{
name|FT_Long
name|nn
decl_stmt|;
for|for
control|(
name|nn
operator|=
literal|0
init|;
name|nn
operator|<
name|globals
operator|->
name|glyph_count
condition|;
name|nn
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|gstyles
index|[
name|nn
index|]
operator|&
name|AF_STYLE_MASK
operator|)
operator|==
name|AF_STYLE_UNASSIGNED
condition|)
block|{
name|gstyles
index|[
name|nn
index|]
operator|&=
operator|~
name|AF_STYLE_MASK
expr_stmt|;
name|gstyles
index|[
name|nn
index|]
operator||=
name|globals
operator|->
name|module
operator|->
name|fallback_style
expr_stmt|;
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
name|FT_TRACE4
argument_list|(
operator|(
literal|"\n"
literal|"style coverage\n"
literal|"==============\n"
literal|"\n"
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|ss
operator|=
literal|0
init|;
name|AF_STYLE_CLASSES_GET
index|[
name|ss
index|]
condition|;
name|ss
operator|++
control|)
block|{
name|AF_StyleClass
name|style_class
init|=
name|AF_STYLE_CLASSES_GET
index|[
name|ss
index|]
decl_stmt|;
name|FT_UInt
name|count
init|=
literal|0
decl_stmt|;
name|FT_Long
name|idx
decl_stmt|;
name|FT_TRACE4
argument_list|(
operator|(
literal|"%s:\n"
operator|,
name|af_style_names
index|[
name|style_class
operator|->
name|style
index|]
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|globals
operator|->
name|glyph_count
condition|;
name|idx
operator|++
control|)
block|{
if|if
condition|(
operator|(
name|gstyles
index|[
name|idx
index|]
operator|&
name|AF_STYLE_MASK
operator|)
operator|==
name|style_class
operator|->
name|style
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|count
operator|%
literal|10
operator|)
condition|)
name|FT_TRACE4
argument_list|(
operator|(
literal|" "
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE4
argument_list|(
operator|(
literal|" %d"
operator|,
name|idx
operator|)
argument_list|)
expr_stmt|;
name|count
operator|++
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|count
operator|%
literal|10
operator|)
condition|)
name|FT_TRACE4
argument_list|(
operator|(
literal|"\n"
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|count
condition|)
name|FT_TRACE4
argument_list|(
operator|(
literal|"  (none)\n"
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|%
literal|10
condition|)
name|FT_TRACE4
argument_list|(
operator|(
literal|"\n"
operator|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* FT_DEBUG_LEVEL_TRACE */
name|FT_Set_Charmap
argument_list|(
name|face
argument_list|,
name|old_charmap
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_face_globals_new
argument_list|(
argument|FT_Face          face
argument_list|,
argument|AF_FaceGlobals  *aglobals
argument_list|,
argument|AF_Module        module
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
decl_stmt|;
name|AF_FaceGlobals
name|globals
init|=
name|NULL
decl_stmt|;
name|memory
operator|=
name|face
operator|->
name|memory
expr_stmt|;
comment|/* we allocate an AF_FaceGlobals structure together */
comment|/* with the glyph_styles array                      */
if|if
condition|(
name|FT_ALLOC
argument_list|(
name|globals
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|globals
argument_list|)
operator|+
operator|(
name|FT_ULong
operator|)
name|face
operator|->
name|num_glyphs
operator|*
sizeof|sizeof
argument_list|(
name|FT_UShort
argument_list|)
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|globals
operator|->
name|face
operator|=
name|face
expr_stmt|;
name|globals
operator|->
name|glyph_count
operator|=
name|face
operator|->
name|num_glyphs
expr_stmt|;
comment|/* right after the globals structure come the glyph styles */
name|globals
operator|->
name|glyph_styles
operator|=
operator|(
name|FT_UShort
operator|*
operator|)
operator|(
name|globals
operator|+
literal|1
operator|)
expr_stmt|;
name|globals
operator|->
name|module
operator|=
name|module
expr_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_HARFBUZZ
name|globals
operator|->
name|hb_font
operator|=
name|hb_ft_font_create
argument_list|(
name|face
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|error
operator|=
name|af_face_globals_compute_style_coverage
argument_list|(
name|globals
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|af_face_globals_free
argument_list|(
name|globals
argument_list|)
expr_stmt|;
name|globals
operator|=
name|NULL
expr_stmt|;
block|}
else|else
name|globals
operator|->
name|increase_x_height
operator|=
name|AF_PROP_INCREASE_X_HEIGHT_MAX
expr_stmt|;
name|Exit
label|:
operator|*
name|aglobals
operator|=
name|globals
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|af_face_globals_free
name|af_face_globals_free
argument_list|(
argument|AF_FaceGlobals  globals
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|globals
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|globals
operator|->
name|face
operator|->
name|memory
decl_stmt|;
name|FT_UInt
name|nn
decl_stmt|;
for|for
control|(
name|nn
operator|=
literal|0
init|;
name|nn
operator|<
name|AF_STYLE_MAX
condition|;
name|nn
operator|++
control|)
block|{
if|if
condition|(
name|globals
operator|->
name|metrics
index|[
name|nn
index|]
condition|)
block|{
name|AF_StyleClass
name|style_class
init|=
name|AF_STYLE_CLASSES_GET
index|[
name|nn
index|]
decl_stmt|;
name|AF_WritingSystemClass
name|writing_system_class
init|=
name|AF_WRITING_SYSTEM_CLASSES_GET
index|[
name|style_class
operator|->
name|writing_system
index|]
decl_stmt|;
if|if
condition|(
name|writing_system_class
operator|->
name|style_metrics_done
condition|)
name|writing_system_class
operator|->
name|style_metrics_done
argument_list|(
name|globals
operator|->
name|metrics
index|[
name|nn
index|]
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|globals
operator|->
name|metrics
index|[
name|nn
index|]
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_HARFBUZZ
name|hb_font_destroy
argument_list|(
name|globals
operator|->
name|hb_font
argument_list|)
expr_stmt|;
name|globals
operator|->
name|hb_font
operator|=
name|NULL
expr_stmt|;
endif|#
directive|endif
name|globals
operator|->
name|glyph_count
operator|=
literal|0
expr_stmt|;
name|globals
operator|->
name|glyph_styles
operator|=
name|NULL
expr_stmt|;
comment|/* no need to free this one! */
name|globals
operator|->
name|face
operator|=
name|NULL
expr_stmt|;
name|FT_FREE
argument_list|(
name|globals
argument_list|)
expr_stmt|;
block|}
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_face_globals_get_metrics
argument_list|(
argument|AF_FaceGlobals    globals
argument_list|,
argument|FT_UInt           gindex
argument_list|,
argument|FT_UInt           options
argument_list|,
argument|AF_StyleMetrics  *ametrics
argument_list|)
end_macro
begin_block
block|{
name|AF_StyleMetrics
name|metrics
init|=
name|NULL
decl_stmt|;
name|AF_Style
name|style
init|=
operator|(
name|AF_Style
operator|)
name|options
decl_stmt|;
name|AF_WritingSystemClass
name|writing_system_class
decl_stmt|;
name|AF_StyleClass
name|style_class
decl_stmt|;
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
if|if
condition|(
name|gindex
operator|>=
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
comment|/* if we have a forced style (via `options'), use it, */
comment|/* otherwise look into `glyph_styles' array           */
if|if
condition|(
name|style
operator|==
name|AF_STYLE_NONE_DFLT
operator|||
name|style
operator|+
literal|1
operator|>=
name|AF_STYLE_MAX
condition|)
name|style
operator|=
call|(
name|AF_Style
call|)
argument_list|(
name|globals
operator|->
name|glyph_styles
index|[
name|gindex
index|]
operator|&
name|AF_STYLE_UNASSIGNED
argument_list|)
expr_stmt|;
name|style_class
operator|=
name|AF_STYLE_CLASSES_GET
index|[
name|style
index|]
expr_stmt|;
name|writing_system_class
operator|=
name|AF_WRITING_SYSTEM_CLASSES_GET
index|[
name|style_class
operator|->
name|writing_system
index|]
expr_stmt|;
name|metrics
operator|=
name|globals
operator|->
name|metrics
index|[
name|style
index|]
expr_stmt|;
if|if
condition|(
name|metrics
operator|==
name|NULL
condition|)
block|{
comment|/* create the global metrics object if necessary */
name|FT_Memory
name|memory
init|=
name|globals
operator|->
name|face
operator|->
name|memory
decl_stmt|;
if|if
condition|(
name|FT_ALLOC
argument_list|(
name|metrics
argument_list|,
name|writing_system_class
operator|->
name|style_metrics_size
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|metrics
operator|->
name|style_class
operator|=
name|style_class
expr_stmt|;
name|metrics
operator|->
name|globals
operator|=
name|globals
expr_stmt|;
if|if
condition|(
name|writing_system_class
operator|->
name|style_metrics_init
condition|)
block|{
name|error
operator|=
name|writing_system_class
operator|->
name|style_metrics_init
argument_list|(
name|metrics
argument_list|,
name|globals
operator|->
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
if|if
condition|(
name|writing_system_class
operator|->
name|style_metrics_done
condition|)
name|writing_system_class
operator|->
name|style_metrics_done
argument_list|(
name|metrics
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|metrics
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
block|}
name|globals
operator|->
name|metrics
index|[
name|style
index|]
operator|=
name|metrics
expr_stmt|;
block|}
name|Exit
label|:
operator|*
name|ametrics
operator|=
name|metrics
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|af_face_globals_is_digit
argument_list|(
argument|AF_FaceGlobals  globals
argument_list|,
argument|FT_UInt         gindex
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|gindex
operator|<
operator|(
name|FT_ULong
operator|)
name|globals
operator|->
name|glyph_count
condition|)
return|return
call|(
name|FT_Bool
call|)
argument_list|(
name|globals
operator|->
name|glyph_styles
index|[
name|gindex
index|]
operator|&
name|AF_DIGIT
argument_list|)
return|;
return|return
operator|(
name|FT_Bool
operator|)
literal|0
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
