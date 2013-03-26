begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftlzw.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType support for .Z compressed files.                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This optional component relies on NetBSD's zopen().  It should mainly  */
end_comment
begin_comment
comment|/*  be used to parse compressed PCF fonts, as found with many X11 server   */
end_comment
begin_comment
comment|/*  distributions.                                                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005, 2006, 2009, 2010 by                              */
end_comment
begin_comment
comment|/*  Albert Chin-A-Young.                                                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Based on code in src/gzip/ftgzip.c, Copyright 2004 by                  */
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
include|FT_INTERNAL_MEMORY_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_LZW_H
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_STANDARD_LIBRARY_H
end_include
begin_include
include|#
directive|include
include|FT_MODULE_ERRORS_H
end_include
begin_undef
DECL|macro|__FTERRORS_H__
undef|#
directive|undef
name|__FTERRORS_H__
end_undef
begin_define
DECL|macro|FT_ERR_PREFIX
define|#
directive|define
name|FT_ERR_PREFIX
value|LZW_Err_
end_define
begin_define
DECL|macro|FT_ERR_BASE
define|#
directive|define
name|FT_ERR_BASE
value|FT_Mod_Err_LZW
end_define
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_LZW
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
end_ifdef
begin_error
error|#
directive|error
literal|"lzw code does not support PIC yet"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"ftzopen.h"
end_include
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*****                                                                 *****/
end_comment
begin_comment
comment|/*****                  M E M O R Y   M A N A G E M E N T              *****/
end_comment
begin_comment
comment|/*****                                                                 *****/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*****                                                                 *****/
end_comment
begin_comment
comment|/*****                   F I L E   D E S C R I P T O R                 *****/
end_comment
begin_comment
comment|/*****                                                                 *****/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_define
DECL|macro|FT_LZW_BUFFER_SIZE
define|#
directive|define
name|FT_LZW_BUFFER_SIZE
value|4096
end_define
begin_typedef
DECL|struct|FT_LZWFileRec_
typedef|typedef
struct|struct
name|FT_LZWFileRec_
block|{
DECL|member|source
name|FT_Stream
name|source
decl_stmt|;
comment|/* parent/source stream        */
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
comment|/* embedding stream            */
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
comment|/* memory allocator            */
DECL|member|lzw
name|FT_LzwStateRec
name|lzw
decl_stmt|;
comment|/* lzw decompressor state      */
DECL|member|buffer
name|FT_Byte
name|buffer
index|[
name|FT_LZW_BUFFER_SIZE
index|]
decl_stmt|;
comment|/* output buffer      */
DECL|member|pos
name|FT_ULong
name|pos
decl_stmt|;
comment|/* position in output */
DECL|member|cursor
name|FT_Byte
modifier|*
name|cursor
decl_stmt|;
DECL|member|limit
name|FT_Byte
modifier|*
name|limit
decl_stmt|;
block|}
DECL|typedef|FT_LZWFileRec
DECL|typedef|FT_LZWFile
name|FT_LZWFileRec
operator|,
typedef|*
name|FT_LZWFile
typedef|;
end_typedef
begin_comment
comment|/* check and skip .Z header */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_lzw_check_header
name|ft_lzw_check_header
parameter_list|(
name|FT_Stream
name|stream
parameter_list|)
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Byte
name|head
index|[
literal|2
index|]
decl_stmt|;
if|if
condition|(
name|FT_STREAM_SEEK
argument_list|(
literal|0
argument_list|)
operator|||
name|FT_STREAM_READ
argument_list|(
name|head
argument_list|,
literal|2
argument_list|)
condition|)
goto|goto
name|Exit
goto|;
comment|/* head[0]&& head[1] are the magic numbers */
if|if
condition|(
name|head
index|[
literal|0
index|]
operator|!=
literal|0x1f
operator|||
name|head
index|[
literal|1
index|]
operator|!=
literal|0x9d
condition|)
name|error
operator|=
name|LZW_Err_Invalid_File_Format
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|ft_lzw_file_init
name|ft_lzw_file_init
parameter_list|(
name|FT_LZWFile
name|zip
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_Stream
name|source
parameter_list|)
block|{
name|FT_LzwState
name|lzw
init|=
operator|&
name|zip
operator|->
name|lzw
decl_stmt|;
name|FT_Error
name|error
init|=
name|LZW_Err_Ok
decl_stmt|;
name|zip
operator|->
name|stream
operator|=
name|stream
expr_stmt|;
name|zip
operator|->
name|source
operator|=
name|source
expr_stmt|;
name|zip
operator|->
name|memory
operator|=
name|stream
operator|->
name|memory
expr_stmt|;
name|zip
operator|->
name|limit
operator|=
name|zip
operator|->
name|buffer
operator|+
name|FT_LZW_BUFFER_SIZE
expr_stmt|;
name|zip
operator|->
name|cursor
operator|=
name|zip
operator|->
name|limit
expr_stmt|;
name|zip
operator|->
name|pos
operator|=
literal|0
expr_stmt|;
comment|/* check and skip .Z header */
name|error
operator|=
name|ft_lzw_check_header
argument_list|(
name|source
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
comment|/* initialize internal lzw variable */
name|ft_lzwstate_init
argument_list|(
name|lzw
argument_list|,
name|source
argument_list|)
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|ft_lzw_file_done
name|ft_lzw_file_done
parameter_list|(
name|FT_LZWFile
name|zip
parameter_list|)
block|{
comment|/* clear the rest */
name|ft_lzwstate_done
argument_list|(
operator|&
name|zip
operator|->
name|lzw
argument_list|)
expr_stmt|;
name|zip
operator|->
name|memory
operator|=
name|NULL
expr_stmt|;
name|zip
operator|->
name|source
operator|=
name|NULL
expr_stmt|;
name|zip
operator|->
name|stream
operator|=
name|NULL
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|ft_lzw_file_reset
name|ft_lzw_file_reset
parameter_list|(
name|FT_LZWFile
name|zip
parameter_list|)
block|{
name|FT_Stream
name|stream
init|=
name|zip
operator|->
name|source
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
if|if
condition|(
operator|!
name|FT_STREAM_SEEK
argument_list|(
literal|0
argument_list|)
condition|)
block|{
name|ft_lzwstate_reset
argument_list|(
operator|&
name|zip
operator|->
name|lzw
argument_list|)
expr_stmt|;
name|zip
operator|->
name|limit
operator|=
name|zip
operator|->
name|buffer
operator|+
name|FT_LZW_BUFFER_SIZE
expr_stmt|;
name|zip
operator|->
name|cursor
operator|=
name|zip
operator|->
name|limit
expr_stmt|;
name|zip
operator|->
name|pos
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|ft_lzw_file_fill_output
name|ft_lzw_file_fill_output
parameter_list|(
name|FT_LZWFile
name|zip
parameter_list|)
block|{
name|FT_LzwState
name|lzw
init|=
operator|&
name|zip
operator|->
name|lzw
decl_stmt|;
name|FT_ULong
name|count
decl_stmt|;
name|FT_Error
name|error
init|=
literal|0
decl_stmt|;
name|zip
operator|->
name|cursor
operator|=
name|zip
operator|->
name|buffer
expr_stmt|;
name|count
operator|=
name|ft_lzwstate_io
argument_list|(
name|lzw
argument_list|,
name|zip
operator|->
name|buffer
argument_list|,
name|FT_LZW_BUFFER_SIZE
argument_list|)
expr_stmt|;
name|zip
operator|->
name|limit
operator|=
name|zip
operator|->
name|cursor
operator|+
name|count
expr_stmt|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
name|error
operator|=
name|LZW_Err_Invalid_Stream_Operation
expr_stmt|;
return|return
name|error
return|;
block|}
end_function
begin_comment
comment|/* fill output buffer; `count' must be<= FT_LZW_BUFFER_SIZE */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|ft_lzw_file_skip_output
name|ft_lzw_file_skip_output
parameter_list|(
name|FT_LZWFile
name|zip
parameter_list|,
name|FT_ULong
name|count
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|LZW_Err_Ok
decl_stmt|;
comment|/* first, we skip what we can from the output buffer */
block|{
name|FT_ULong
name|delta
init|=
call|(
name|FT_ULong
call|)
argument_list|(
name|zip
operator|->
name|limit
operator|-
name|zip
operator|->
name|cursor
argument_list|)
decl_stmt|;
if|if
condition|(
name|delta
operator|>=
name|count
condition|)
name|delta
operator|=
name|count
expr_stmt|;
name|zip
operator|->
name|cursor
operator|+=
name|delta
expr_stmt|;
name|zip
operator|->
name|pos
operator|+=
name|delta
expr_stmt|;
name|count
operator|-=
name|delta
expr_stmt|;
block|}
comment|/* next, we skip as many bytes remaining as possible */
while|while
condition|(
name|count
operator|>
literal|0
condition|)
block|{
name|FT_ULong
name|delta
init|=
name|FT_LZW_BUFFER_SIZE
decl_stmt|;
name|FT_ULong
name|numread
decl_stmt|;
if|if
condition|(
name|delta
operator|>
name|count
condition|)
name|delta
operator|=
name|count
expr_stmt|;
name|numread
operator|=
name|ft_lzwstate_io
argument_list|(
operator|&
name|zip
operator|->
name|lzw
argument_list|,
name|NULL
argument_list|,
name|delta
argument_list|)
expr_stmt|;
if|if
condition|(
name|numread
operator|<
name|delta
condition|)
block|{
comment|/* not enough bytes */
name|error
operator|=
name|LZW_Err_Invalid_Stream_Operation
expr_stmt|;
break|break;
block|}
name|zip
operator|->
name|pos
operator|+=
name|delta
expr_stmt|;
name|count
operator|-=
name|delta
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_ULong
DECL|function|ft_lzw_file_io
name|ft_lzw_file_io
parameter_list|(
name|FT_LZWFile
name|zip
parameter_list|,
name|FT_ULong
name|pos
parameter_list|,
name|FT_Byte
modifier|*
name|buffer
parameter_list|,
name|FT_ULong
name|count
parameter_list|)
block|{
name|FT_ULong
name|result
init|=
literal|0
decl_stmt|;
name|FT_Error
name|error
decl_stmt|;
comment|/* seeking backwards. */
if|if
condition|(
name|pos
operator|<
name|zip
operator|->
name|pos
condition|)
block|{
comment|/* If the new position is within the output buffer, simply       */
comment|/* decrement pointers, otherwise we reset the stream completely! */
if|if
condition|(
operator|(
name|zip
operator|->
name|pos
operator|-
name|pos
operator|)
operator|<=
call|(
name|FT_ULong
call|)
argument_list|(
name|zip
operator|->
name|cursor
operator|-
name|zip
operator|->
name|buffer
argument_list|)
condition|)
block|{
name|zip
operator|->
name|cursor
operator|-=
name|zip
operator|->
name|pos
operator|-
name|pos
expr_stmt|;
name|zip
operator|->
name|pos
operator|=
name|pos
expr_stmt|;
block|}
else|else
block|{
name|error
operator|=
name|ft_lzw_file_reset
argument_list|(
name|zip
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
block|}
comment|/* skip unwanted bytes */
if|if
condition|(
name|pos
operator|>
name|zip
operator|->
name|pos
condition|)
block|{
name|error
operator|=
name|ft_lzw_file_skip_output
argument_list|(
name|zip
argument_list|,
call|(
name|FT_ULong
call|)
argument_list|(
name|pos
operator|-
name|zip
operator|->
name|pos
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
block|}
if|if
condition|(
name|count
operator|==
literal|0
condition|)
goto|goto
name|Exit
goto|;
comment|/* now read the data */
for|for
control|(
init|;
condition|;
control|)
block|{
name|FT_ULong
name|delta
decl_stmt|;
name|delta
operator|=
call|(
name|FT_ULong
call|)
argument_list|(
name|zip
operator|->
name|limit
operator|-
name|zip
operator|->
name|cursor
argument_list|)
expr_stmt|;
if|if
condition|(
name|delta
operator|>=
name|count
condition|)
name|delta
operator|=
name|count
expr_stmt|;
name|FT_MEM_COPY
argument_list|(
name|buffer
operator|+
name|result
argument_list|,
name|zip
operator|->
name|cursor
argument_list|,
name|delta
argument_list|)
expr_stmt|;
name|result
operator|+=
name|delta
expr_stmt|;
name|zip
operator|->
name|cursor
operator|+=
name|delta
expr_stmt|;
name|zip
operator|->
name|pos
operator|+=
name|delta
expr_stmt|;
name|count
operator|-=
name|delta
expr_stmt|;
if|if
condition|(
name|count
operator|==
literal|0
condition|)
break|break;
name|error
operator|=
name|ft_lzw_file_fill_output
argument_list|(
name|zip
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
break|break;
block|}
name|Exit
label|:
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*****                                                                 *****/
end_comment
begin_comment
comment|/*****            L Z W   E M B E D D I N G   S T R E A M              *****/
end_comment
begin_comment
comment|/*****                                                                 *****/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_function
specifier|static
name|void
DECL|function|ft_lzw_stream_close
name|ft_lzw_stream_close
parameter_list|(
name|FT_Stream
name|stream
parameter_list|)
block|{
name|FT_LZWFile
name|zip
init|=
operator|(
name|FT_LZWFile
operator|)
name|stream
operator|->
name|descriptor
operator|.
name|pointer
decl_stmt|;
name|FT_Memory
name|memory
init|=
name|stream
operator|->
name|memory
decl_stmt|;
if|if
condition|(
name|zip
condition|)
block|{
comment|/* finalize lzw file descriptor */
name|ft_lzw_file_done
argument_list|(
name|zip
argument_list|)
expr_stmt|;
name|FT_FREE
argument_list|(
name|zip
argument_list|)
expr_stmt|;
name|stream
operator|->
name|descriptor
operator|.
name|pointer
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function
begin_function
specifier|static
name|FT_ULong
DECL|function|ft_lzw_stream_io
name|ft_lzw_stream_io
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|FT_ULong
name|pos
parameter_list|,
name|FT_Byte
modifier|*
name|buffer
parameter_list|,
name|FT_ULong
name|count
parameter_list|)
block|{
name|FT_LZWFile
name|zip
init|=
operator|(
name|FT_LZWFile
operator|)
name|stream
operator|->
name|descriptor
operator|.
name|pointer
decl_stmt|;
return|return
name|ft_lzw_file_io
argument_list|(
name|zip
argument_list|,
name|pos
argument_list|,
name|buffer
argument_list|,
name|count
argument_list|)
return|;
block|}
end_function
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_OpenLZW
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Stream  source
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
name|source
operator|->
name|memory
decl_stmt|;
name|FT_LZWFile
name|zip
decl_stmt|;
comment|/*      *  Check the header right now; this prevents allocation of a huge      *  LZWFile object (400 KByte of heap memory) if not necessary.      *      *  Did I mention that you should never use .Z compressed font      *  files?      */
name|error
operator|=
name|ft_lzw_check_header
argument_list|(
name|source
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
goto|goto
name|Exit
goto|;
name|FT_ZERO
argument_list|(
name|stream
argument_list|)
expr_stmt|;
name|stream
operator|->
name|memory
operator|=
name|memory
expr_stmt|;
if|if
condition|(
operator|!
name|FT_NEW
argument_list|(
name|zip
argument_list|)
condition|)
block|{
name|error
operator|=
name|ft_lzw_file_init
argument_list|(
name|zip
argument_list|,
name|stream
argument_list|,
name|source
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
block|{
name|FT_FREE
argument_list|(
name|zip
argument_list|)
expr_stmt|;
goto|goto
name|Exit
goto|;
block|}
name|stream
operator|->
name|descriptor
operator|.
name|pointer
operator|=
name|zip
expr_stmt|;
block|}
name|stream
operator|->
name|size
operator|=
literal|0x7FFFFFFFL
expr_stmt|;
comment|/* don't know the real size! */
name|stream
operator|->
name|pos
operator|=
literal|0
expr_stmt|;
name|stream
operator|->
name|base
operator|=
literal|0
expr_stmt|;
name|stream
operator|->
name|read
operator|=
name|ft_lzw_stream_io
expr_stmt|;
name|stream
operator|->
name|close
operator|=
name|ft_lzw_stream_close
expr_stmt|;
name|Exit
label|:
return|return
name|error
return|;
block|}
end_block
begin_include
include|#
directive|include
file|"ftzopen.c"
end_include
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_CONFIG_OPTION_USE_LZW */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_OpenLZW
argument_list|(
argument|FT_Stream  stream
argument_list|,
argument|FT_Stream  source
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|stream
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|source
argument_list|)
expr_stmt|;
return|return
name|LZW_Err_Unimplemented_Feature
return|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_USE_LZW */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
