begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ttpload.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueType-specific tables loader (body).                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2015 by                                                 */
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
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TAGS_H
end_include
begin_include
include|#
directive|include
file|"ttpload.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
end_ifdef
begin_include
include|#
directive|include
file|"ttgxvar.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"tterrors.h"
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
value|trace_ttpload
end_define
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
comment|/*    tt_face_load_loca                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the locations table.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream :: The input stream.                                        */
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
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_loca
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_ULong
name|table_len
decl_stmt|;
name|FT_Int
name|shift
decl_stmt|;
comment|/* we need the size of the `glyf' table for malformed `loca' tables */
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_glyf
argument_list|,
name|stream
argument_list|,
operator|&
name|face
operator|->
name|glyf_len
argument_list|)
expr_stmt|;
comment|/* it is possible that a font doesn't have a glyf table at all */
comment|/* or its size is zero                                         */
if|if
condition|(
name|FT_ERR_EQ
argument_list|(
name|error
argument_list|,
name|Table_Missing
argument_list|)
condition|)
name|face
operator|->
name|glyf_len
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"Locations "
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_loca
argument_list|,
name|stream
argument_list|,
operator|&
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Locations_Missing
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|face
operator|->
name|header
operator|.
name|Index_To_Loc_Format
operator|!=
literal|0
condition|)
block|{
name|shift
operator|=
literal|2
expr_stmt|;
if|if
condition|(
name|table_len
operator|>=
literal|0x40000L
condition|)
block|{
name|FT_TRACE2
argument_list|(
operator|(
literal|"table too large\n"
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Table
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|face
operator|->
name|num_locations
operator|=
name|table_len
operator|>>
name|shift
expr_stmt|;
block|}
else|else
block|{
name|shift
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|table_len
operator|>=
literal|0x20000L
condition|)
block|{
name|FT_TRACE2
argument_list|(
operator|(
literal|"table too large\n"
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Table
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|face
operator|->
name|num_locations
operator|=
name|table_len
operator|>>
name|shift
expr_stmt|;
block|}
if|if
condition|(
name|face
operator|->
name|num_locations
operator|!=
operator|(
name|FT_ULong
operator|)
name|face
operator|->
name|root
operator|.
name|num_glyphs
operator|+
literal|1
condition|)
block|{
name|FT_TRACE2
argument_list|(
operator|(
literal|"glyph count mismatch!  loca: %d, maxp: %d\n"
operator|,
name|face
operator|->
name|num_locations
operator|-
literal|1
operator|,
name|face
operator|->
name|root
operator|.
name|num_glyphs
operator|)
argument_list|)
expr_stmt|;
comment|/* we only handle the case where `maxp' gives a larger value */
if|if
condition|(
name|face
operator|->
name|num_locations
operator|<=
operator|(
name|FT_ULong
operator|)
name|face
operator|->
name|root
operator|.
name|num_glyphs
condition|)
block|{
name|FT_ULong
name|new_loca_len
init|=
operator|(
operator|(
name|FT_ULong
operator|)
name|face
operator|->
name|root
operator|.
name|num_glyphs
operator|+
literal|1
operator|)
operator|<<
name|shift
decl_stmt|;
name|TT_Table
name|entry
init|=
name|face
operator|->
name|dir_tables
decl_stmt|;
name|TT_Table
name|limit
init|=
name|entry
operator|+
name|face
operator|->
name|num_tables
decl_stmt|;
name|FT_Long
name|pos
init|=
operator|(
name|FT_Long
operator|)
name|FT_STREAM_POS
argument_list|()
decl_stmt|;
name|FT_Long
name|dist
init|=
literal|0x7FFFFFFFL
decl_stmt|;
comment|/* compute the distance to next table in font file */
for|for
control|(
init|;
name|entry
operator|<
name|limit
condition|;
name|entry
operator|++
control|)
block|{
name|FT_Long
name|diff
init|=
operator|(
name|FT_Long
operator|)
name|entry
operator|->
name|Offset
operator|-
name|pos
decl_stmt|;
if|if
condition|(
name|diff
operator|>
literal|0
operator|&&
name|diff
operator|<
name|dist
condition|)
name|dist
operator|=
name|diff
expr_stmt|;
block|}
if|if
condition|(
name|entry
operator|==
name|limit
condition|)
block|{
comment|/* `loca' is the last table */
name|dist
operator|=
operator|(
name|FT_Long
operator|)
name|stream
operator|->
name|size
operator|-
name|pos
expr_stmt|;
block|}
if|if
condition|(
name|new_loca_len
operator|<=
operator|(
name|FT_ULong
operator|)
name|dist
condition|)
block|{
name|face
operator|->
name|num_locations
operator|=
operator|(
name|FT_ULong
operator|)
name|face
operator|->
name|root
operator|.
name|num_glyphs
operator|+
literal|1
expr_stmt|;
name|table_len
operator|=
name|new_loca_len
expr_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"adjusting num_locations to %d\n"
operator|,
name|face
operator|->
name|num_locations
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|face
operator|->
name|root
operator|.
name|num_glyphs
operator|=
name|face
operator|->
name|num_locations
condition|?
operator|(
name|FT_Long
operator|)
name|face
operator|->
name|num_locations
operator|-
literal|1
else|:
literal|0
expr_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"adjusting num_glyphs to %d\n"
operator|,
name|face
operator|->
name|root
operator|.
name|num_glyphs
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/*      * Extract the frame.  We don't need to decompress it since      * we are able to parse it directly.      */
if|if
condition|(
name|FT_FRAME_EXTRACT
argument_list|(
name|table_len
argument_list|,
name|face
operator|->
name|glyph_locations
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"loaded\n"
operator|)
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
name|tt_face_get_location
argument_list|(
argument|TT_Face   face
argument_list|,
argument|FT_UInt   gindex
argument_list|,
argument|FT_UInt  *asize
argument_list|)
end_macro
begin_block
block|{
name|FT_ULong
name|pos1
decl_stmt|,
name|pos2
decl_stmt|;
name|FT_Byte
modifier|*
name|p
decl_stmt|;
name|FT_Byte
modifier|*
name|p_limit
decl_stmt|;
name|pos1
operator|=
name|pos2
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|gindex
operator|<
name|face
operator|->
name|num_locations
condition|)
block|{
if|if
condition|(
name|face
operator|->
name|header
operator|.
name|Index_To_Loc_Format
operator|!=
literal|0
condition|)
block|{
name|p
operator|=
name|face
operator|->
name|glyph_locations
operator|+
name|gindex
operator|*
literal|4
expr_stmt|;
name|p_limit
operator|=
name|face
operator|->
name|glyph_locations
operator|+
name|face
operator|->
name|num_locations
operator|*
literal|4
expr_stmt|;
name|pos1
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|pos2
operator|=
name|pos1
expr_stmt|;
if|if
condition|(
name|p
operator|+
literal|4
operator|<=
name|p_limit
condition|)
name|pos2
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|p
operator|=
name|face
operator|->
name|glyph_locations
operator|+
name|gindex
operator|*
literal|2
expr_stmt|;
name|p_limit
operator|=
name|face
operator|->
name|glyph_locations
operator|+
name|face
operator|->
name|num_locations
operator|*
literal|2
expr_stmt|;
name|pos1
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|pos2
operator|=
name|pos1
expr_stmt|;
if|if
condition|(
name|p
operator|+
literal|2
operator|<=
name|p_limit
condition|)
name|pos2
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|pos1
operator|<<=
literal|1
expr_stmt|;
name|pos2
operator|<<=
literal|1
expr_stmt|;
block|}
block|}
comment|/* Check broken location data */
if|if
condition|(
name|pos1
operator|>
name|face
operator|->
name|glyf_len
condition|)
block|{
name|FT_TRACE1
argument_list|(
operator|(
literal|"tt_face_get_location:"
literal|" too large offset=0x%08lx found for gid=0x%04lx,"
literal|" exceeding the end of glyf table (0x%08lx)\n"
operator|,
name|pos1
operator|,
name|gindex
operator|,
name|face
operator|->
name|glyf_len
operator|)
argument_list|)
expr_stmt|;
operator|*
name|asize
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|pos2
operator|>
name|face
operator|->
name|glyf_len
condition|)
block|{
name|FT_TRACE1
argument_list|(
operator|(
literal|"tt_face_get_location:"
literal|" too large offset=0x%08lx found for gid=0x%04lx,"
literal|" truncate at the end of glyf table (0x%08lx)\n"
operator|,
name|pos2
operator|,
name|gindex
operator|+
literal|1
operator|,
name|face
operator|->
name|glyf_len
operator|)
argument_list|)
expr_stmt|;
name|pos2
operator|=
name|face
operator|->
name|glyf_len
expr_stmt|;
block|}
comment|/* The `loca' table must be ordered; it refers to the length of */
comment|/* an entry as the difference between the current and the next  */
comment|/* position.  However, there do exist (malformed) fonts which   */
comment|/* don't obey this rule, so we are only able to provide an      */
comment|/* upper bound for the size.                                    */
comment|/*                                                              */
comment|/* We get (intentionally) a wrong, non-zero result in case the  */
comment|/* `glyf' table is missing.                                     */
if|if
condition|(
name|pos2
operator|>=
name|pos1
condition|)
operator|*
name|asize
operator|=
call|(
name|FT_UInt
call|)
argument_list|(
name|pos2
operator|-
name|pos1
argument_list|)
expr_stmt|;
else|else
operator|*
name|asize
operator|=
call|(
name|FT_UInt
call|)
argument_list|(
name|face
operator|->
name|glyf_len
operator|-
name|pos1
argument_list|)
expr_stmt|;
return|return
name|pos1
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
DECL|function|tt_face_done_loca
name|tt_face_done_loca
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_block
block|{
name|FT_Stream
name|stream
init|=
name|face
operator|->
name|root
operator|.
name|stream
decl_stmt|;
name|FT_FRAME_RELEASE
argument_list|(
name|face
operator|->
name|glyph_locations
argument_list|)
expr_stmt|;
name|face
operator|->
name|num_locations
operator|=
literal|0
expr_stmt|;
block|}
end_block
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
comment|/*    tt_face_load_cvt                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the control value table into a face object.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream :: A handle to the input stream.                            */
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
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_cvt
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
name|FT_ULong
name|table_len
decl_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"CVT "
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_cvt
argument_list|,
name|stream
argument_list|,
operator|&
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|FT_TRACE2
argument_list|(
operator|(
literal|"is missing\n"
operator|)
argument_list|)
expr_stmt|;
name|face
operator|->
name|cvt_size
operator|=
literal|0
expr_stmt|;
name|face
operator|->
name|cvt
operator|=
name|NULL
expr_stmt|;
name|error
operator|=
name|FT_Err_Ok
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|face
operator|->
name|cvt_size
operator|=
name|table_len
operator|/
literal|2
expr_stmt|;
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|face
operator|->
name|cvt
argument_list|,
name|face
operator|->
name|cvt_size
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
if|if
condition|(
name|FT_FRAME_ENTER
argument_list|(
name|face
operator|->
name|cvt_size
operator|*
literal|2L
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
block|{
name|FT_Short
modifier|*
name|cur
init|=
name|face
operator|->
name|cvt
decl_stmt|;
name|FT_Short
modifier|*
name|limit
init|=
name|cur
operator|+
name|face
operator|->
name|cvt_size
decl_stmt|;
for|for
control|(
init|;
name|cur
operator|<
name|limit
condition|;
name|cur
operator|++
control|)
operator|*
name|cur
operator|=
name|FT_GET_SHORT
argument_list|()
expr_stmt|;
block|}
name|FT_FRAME_EXIT
argument_list|()
expr_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"loaded\n"
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
if|if
condition|(
name|face
operator|->
name|doblend
condition|)
name|error
operator|=
name|tt_face_vary_cvt
argument_list|(
name|face
argument_list|,
name|stream
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Exit
label|:
return|return
name|error
return|;
else|#
directive|else
comment|/* !TT_USE_BYTECODE_INTERPRETER */
name|FT_UNUSED
argument_list|(
name|face
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
endif|#
directive|endif
block|}
end_block
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
comment|/*    tt_face_load_fpgm                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the font program.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream :: A handle to the input stream.                            */
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
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_fpgm
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
name|FT_Error
name|error
decl_stmt|;
name|FT_ULong
name|table_len
decl_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"Font program "
operator|)
argument_list|)
expr_stmt|;
comment|/* The font program is optional */
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_fpgm
argument_list|,
name|stream
argument_list|,
operator|&
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|face
operator|->
name|font_program
operator|=
name|NULL
expr_stmt|;
name|face
operator|->
name|font_program_size
operator|=
literal|0
expr_stmt|;
name|error
operator|=
name|FT_Err_Ok
expr_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"is missing\n"
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|face
operator|->
name|font_program_size
operator|=
name|table_len
expr_stmt|;
if|if
condition|(
name|FT_FRAME_EXTRACT
argument_list|(
name|table_len
argument_list|,
name|face
operator|->
name|font_program
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"loaded, %12d bytes\n"
operator|,
name|face
operator|->
name|font_program_size
operator|)
argument_list|)
expr_stmt|;
block|}
name|Exit
label|:
return|return
name|error
return|;
else|#
directive|else
comment|/* !TT_USE_BYTECODE_INTERPRETER */
name|FT_UNUSED
argument_list|(
name|face
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
endif|#
directive|endif
block|}
end_block
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
comment|/*    tt_face_load_prep                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the cvt program.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream :: A handle to the input stream.                            */
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
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_prep
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
ifdef|#
directive|ifdef
name|TT_USE_BYTECODE_INTERPRETER
name|FT_Error
name|error
decl_stmt|;
name|FT_ULong
name|table_len
decl_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"Prep program "
operator|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_prep
argument_list|,
name|stream
argument_list|,
operator|&
name|table_len
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|face
operator|->
name|cvt_program
operator|=
name|NULL
expr_stmt|;
name|face
operator|->
name|cvt_program_size
operator|=
literal|0
expr_stmt|;
name|error
operator|=
name|FT_Err_Ok
expr_stmt|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"is missing\n"
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|face
operator|->
name|cvt_program_size
operator|=
name|table_len
expr_stmt|;
if|if
condition|(
name|FT_FRAME_EXTRACT
argument_list|(
name|table_len
argument_list|,
name|face
operator|->
name|cvt_program
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|FT_TRACE2
argument_list|(
operator|(
literal|"loaded, %12d bytes\n"
operator|,
name|face
operator|->
name|cvt_program_size
operator|)
argument_list|)
expr_stmt|;
block|}
name|Exit
label|:
return|return
name|error
return|;
else|#
directive|else
comment|/* !TT_USE_BYTECODE_INTERPRETER */
name|FT_UNUSED
argument_list|(
name|face
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|stream
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
endif|#
directive|endif
block|}
end_block
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
comment|/*    tt_face_load_hdmx                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the `hdmx' table into the face object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream :: A handle to the input stream.                            */
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
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|tt_face_load_hdmx
argument_list|(
argument|TT_Face    face
argument_list|,
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
name|FT_UInt
name|version
decl_stmt|,
name|nn
decl_stmt|,
name|num_records
decl_stmt|;
name|FT_ULong
name|table_size
decl_stmt|,
name|record_size
decl_stmt|;
name|FT_Byte
modifier|*
name|p
decl_stmt|;
name|FT_Byte
modifier|*
name|limit
decl_stmt|;
comment|/* this table is optional */
name|error
operator|=
name|face
operator|->
name|goto_table
argument_list|(
name|face
argument_list|,
name|TTAG_hdmx
argument_list|,
name|stream
argument_list|,
operator|&
name|table_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|||
name|table_size
operator|<
literal|8
condition|)
return|return
name|FT_Err_Ok
return|;
if|if
condition|(
name|FT_FRAME_EXTRACT
argument_list|(
name|table_size
argument_list|,
name|face
operator|->
name|hdmx_table
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
name|p
operator|=
name|face
operator|->
name|hdmx_table
expr_stmt|;
name|limit
operator|=
name|p
operator|+
name|table_size
expr_stmt|;
name|version
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|num_records
operator|=
name|FT_NEXT_USHORT
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|record_size
operator|=
name|FT_NEXT_ULONG
argument_list|(
name|p
argument_list|)
expr_stmt|;
comment|/* The maximum number of bytes in an hdmx device record is the */
comment|/* maximum number of glyphs + 2; this is 0xFFFF + 2, thus      */
comment|/* explaining why `record_size' is a long (which we read as    */
comment|/* unsigned long for convenience).  In practice, two bytes are */
comment|/* sufficient to hold the size value.                          */
comment|/*                                                             */
comment|/* There are at least two fonts, HANNOM-A and HANNOM-B version */
comment|/* 2.0 (2005), which get this wrong: The upper two bytes of    */
comment|/* the size value are set to 0xFF instead of 0x00.  We catch   */
comment|/* and fix this.                                               */
if|if
condition|(
name|record_size
operator|>=
literal|0xFFFF0000UL
condition|)
name|record_size
operator|&=
literal|0xFFFFU
expr_stmt|;
comment|/* The limit for `num_records' is a heuristic value. */
if|if
condition|(
name|version
operator|!=
literal|0
operator|||
name|num_records
operator|>
literal|255
operator|||
name|record_size
operator|>
literal|0x10001L
operator|||
name|record_size
operator|<
literal|4
condition|)
block|{
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_File_Format
argument_list|)
expr_stmt|;
goto|goto
name|Fail
goto|;
block|}
if|if
condition|(
name|FT_NEW_ARRAY
argument_list|(
name|face
operator|->
name|hdmx_record_sizes
argument_list|,
name|num_records
argument_list|)
condition|)
goto|goto
name|Fail
goto|;
for|for
control|(
name|nn
operator|=
literal|0
init|;
name|nn
operator|<
name|num_records
condition|;
name|nn
operator|++
control|)
block|{
if|if
condition|(
name|p
operator|+
name|record_size
operator|>
name|limit
condition|)
break|break;
name|face
operator|->
name|hdmx_record_sizes
index|[
name|nn
index|]
operator|=
name|p
index|[
literal|0
index|]
expr_stmt|;
name|p
operator|+=
name|record_size
expr_stmt|;
block|}
name|face
operator|->
name|hdmx_record_count
operator|=
name|nn
expr_stmt|;
name|face
operator|->
name|hdmx_table_size
operator|=
name|table_size
expr_stmt|;
name|face
operator|->
name|hdmx_record_size
operator|=
name|record_size
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
name|Fail
label|:
name|FT_FRAME_RELEASE
argument_list|(
name|face
operator|->
name|hdmx_table
argument_list|)
expr_stmt|;
name|face
operator|->
name|hdmx_table_size
operator|=
literal|0
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|tt_face_free_hdmx
name|tt_face_free_hdmx
argument_list|(
argument|TT_Face  face
argument_list|)
end_macro
begin_block
block|{
name|FT_Stream
name|stream
init|=
name|face
operator|->
name|root
operator|.
name|stream
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
name|FT_FREE
argument_list|(
name|face
operator|->
name|hdmx_record_sizes
argument_list|)
expr_stmt|;
name|FT_FRAME_RELEASE
argument_list|(
name|face
operator|->
name|hdmx_table
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Return the advance width table for a given pixel size if it is found  */
end_comment
begin_comment
comment|/* in the font's `hdmx' table (if any).                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Byte*
argument_list|)
end_macro
begin_macro
DECL|function|tt_face_get_device_metrics
name|tt_face_get_device_metrics
argument_list|(
argument|TT_Face  face
argument_list|,
argument|FT_UInt  ppem
argument_list|,
argument|FT_UInt  gindex
argument_list|)
end_macro
begin_block
block|{
name|FT_UInt
name|nn
decl_stmt|;
name|FT_Byte
modifier|*
name|result
init|=
name|NULL
decl_stmt|;
name|FT_ULong
name|record_size
init|=
name|face
operator|->
name|hdmx_record_size
decl_stmt|;
name|FT_Byte
modifier|*
name|record
init|=
name|face
operator|->
name|hdmx_table
operator|+
literal|8
decl_stmt|;
for|for
control|(
name|nn
operator|=
literal|0
init|;
name|nn
operator|<
name|face
operator|->
name|hdmx_record_count
condition|;
name|nn
operator|++
control|)
if|if
condition|(
name|face
operator|->
name|hdmx_record_sizes
index|[
name|nn
index|]
operator|==
name|ppem
condition|)
block|{
name|gindex
operator|+=
literal|2
expr_stmt|;
if|if
condition|(
name|gindex
operator|<
name|record_size
condition|)
name|result
operator|=
name|record
operator|+
name|nn
operator|*
name|record_size
operator|+
name|gindex
expr_stmt|;
break|break;
block|}
return|return
name|result
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
