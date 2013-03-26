begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsystem.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    ANSI-specific FreeType low-level system interface (body).            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2006, 2008, 2009 by                         */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This file contains the default interface used by FreeType to access   */
end_comment
begin_comment
comment|/* low-level, i.e. memory management, i/o access as well as thread       */
end_comment
begin_comment
comment|/* synchronisation.  It can be replaced by user-specific routines if     */
end_comment
begin_comment
comment|/* necessary.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_include
include|#
directive|include
include|FT_SYSTEM_H
end_include
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_include
include|#
directive|include
include|FT_TYPES_H
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                       MEMORY MANAGEMENT INTERFACE                     */
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
comment|/* It is not necessary to do any error checking for the                  */
end_comment
begin_comment
comment|/* allocation-related functions.  This will be done by the higher level  */
end_comment
begin_comment
comment|/* routines like ft_mem_alloc() or ft_mem_realloc().                     */
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    ft_alloc                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The memory allocation function.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory :: A pointer to the memory object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    size   :: The requested size in bytes.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The address of newly allocated block.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
DECL|function|ft_alloc
name|ft_alloc
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|long       size
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|memory
argument_list|)
expr_stmt|;
return|return
name|ft_smalloc
argument_list|(
name|size
argument_list|)
return|;
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
comment|/*    ft_realloc                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The memory reallocation function.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory   :: A pointer to the memory object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cur_size :: The current size of the allocated memory block.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    new_size :: The newly requested size in bytes.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    block    :: The current address of the block in memory.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The address of the reallocated memory block.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
DECL|function|ft_realloc
name|ft_realloc
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|long       cur_size
argument_list|,
argument|long       new_size
argument_list|,
argument|void*      block
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|memory
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|cur_size
argument_list|)
expr_stmt|;
return|return
name|ft_srealloc
argument_list|(
name|block
argument_list|,
name|new_size
argument_list|)
return|;
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
comment|/*    ft_free                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The memory release function.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory  :: A pointer to the memory object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    block   :: The address of block in memory to be freed.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ft_free
name|ft_free
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|void*      block
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|memory
argument_list|)
expr_stmt|;
name|ft_sfree
argument_list|(
name|block
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
comment|/*                     RESOURCE MANAGEMENT INTERFACE                     */
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
value|trace_io
end_define
begin_comment
comment|/* We use the macro STREAM_FILE for convenience to extract the       */
end_comment
begin_comment
comment|/* system-specific stream handle from a given FreeType stream object */
end_comment
begin_define
DECL|macro|STREAM_FILE
define|#
directive|define
name|STREAM_FILE
parameter_list|(
name|stream
parameter_list|)
value|( (FT_FILE*)stream->descriptor.pointer )
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
comment|/*    ft_ansi_stream_close                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The function to close a stream.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream :: A pointer to the stream object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|ft_ansi_stream_close
name|ft_ansi_stream_close
argument_list|(
argument|FT_Stream  stream
argument_list|)
end_macro
begin_block
block|{
name|ft_fclose
argument_list|(
name|STREAM_FILE
argument_list|(
name|stream
argument_list|)
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
name|stream
operator|->
name|size
operator|=
literal|0
expr_stmt|;
name|stream
operator|->
name|base
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
comment|/*    ft_ansi_stream_io                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The function to open a stream.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream :: A pointer to the stream object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    offset :: The position in the data stream to start reading.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    buffer :: The address of buffer to store the read data.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    count  :: The number of bytes to read from the stream.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The number of bytes actually read.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|unsigned long
argument_list|)
end_macro
begin_macro
DECL|function|ft_ansi_stream_io
name|ft_ansi_stream_io
argument_list|(
argument|FT_Stream       stream
argument_list|,
argument|unsigned long   offset
argument_list|,
argument|unsigned char*  buffer
argument_list|,
argument|unsigned long   count
argument_list|)
end_macro
begin_block
block|{
name|FT_FILE
modifier|*
name|file
decl_stmt|;
name|file
operator|=
name|STREAM_FILE
argument_list|(
name|stream
argument_list|)
expr_stmt|;
if|if
condition|(
name|stream
operator|->
name|pos
operator|!=
name|offset
condition|)
name|ft_fseek
argument_list|(
name|file
argument_list|,
name|offset
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
return|return
operator|(
name|unsigned
name|long
operator|)
name|ft_fread
argument_list|(
name|buffer
argument_list|,
literal|1
argument_list|,
name|count
argument_list|,
name|file
argument_list|)
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftstream.h */
end_comment
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Stream_Open
argument_list|(
argument|FT_Stream    stream
argument_list|,
argument|const char*  filepathname
argument_list|)
end_macro
begin_block
block|{
name|FT_FILE
modifier|*
name|file
decl_stmt|;
if|if
condition|(
operator|!
name|stream
condition|)
return|return
name|FT_Err_Invalid_Stream_Handle
return|;
name|file
operator|=
name|ft_fopen
argument_list|(
name|filepathname
argument_list|,
literal|"rb"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"FT_Stream_Open:"
literal|" could not open `%s'\n"
operator|,
name|filepathname
operator|)
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Cannot_Open_Resource
return|;
block|}
name|ft_fseek
argument_list|(
name|file
argument_list|,
literal|0
argument_list|,
name|SEEK_END
argument_list|)
expr_stmt|;
name|stream
operator|->
name|size
operator|=
name|ft_ftell
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|ft_fseek
argument_list|(
name|file
argument_list|,
literal|0
argument_list|,
name|SEEK_SET
argument_list|)
expr_stmt|;
name|stream
operator|->
name|descriptor
operator|.
name|pointer
operator|=
name|file
expr_stmt|;
name|stream
operator|->
name|pathname
operator|.
name|pointer
operator|=
operator|(
name|char
operator|*
operator|)
name|filepathname
expr_stmt|;
name|stream
operator|->
name|pos
operator|=
literal|0
expr_stmt|;
name|stream
operator|->
name|read
operator|=
name|ft_ansi_stream_io
expr_stmt|;
name|stream
operator|->
name|close
operator|=
name|ft_ansi_stream_close
expr_stmt|;
name|FT_TRACE1
argument_list|(
operator|(
literal|"FT_Stream_Open:"
operator|)
argument_list|)
expr_stmt|;
name|FT_TRACE1
argument_list|(
operator|(
literal|" opened `%s' (%d bytes) successfully\n"
operator|,
name|filepathname
operator|,
name|stream
operator|->
name|size
operator|)
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
block|}
end_block
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_MEMORY
end_ifdef
begin_function_decl
specifier|extern
name|FT_Int
name|ft_mem_debug_init
parameter_list|(
name|FT_Memory
name|memory
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|extern
name|void
name|ft_mem_debug_done
parameter_list|(
name|FT_Memory
name|memory
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* documentation is in ftobjs.h */
end_comment
begin_macro
DECL|function|FT_BASE_DEF
name|FT_BASE_DEF
argument_list|(
argument|FT_Memory
argument_list|)
end_macro
begin_macro
name|FT_New_Memory
argument_list|(
argument|void
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
decl_stmt|;
name|memory
operator|=
operator|(
name|FT_Memory
operator|)
name|ft_smalloc
argument_list|(
sizeof|sizeof
argument_list|(
operator|*
name|memory
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|memory
condition|)
block|{
name|memory
operator|->
name|user
operator|=
literal|0
expr_stmt|;
name|memory
operator|->
name|alloc
operator|=
name|ft_alloc
expr_stmt|;
name|memory
operator|->
name|realloc
operator|=
name|ft_realloc
expr_stmt|;
name|memory
operator|->
name|free
operator|=
name|ft_free
expr_stmt|;
ifdef|#
directive|ifdef
name|FT_DEBUG_MEMORY
name|ft_mem_debug_init
argument_list|(
name|memory
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
return|return
name|memory
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftobjs.h */
end_comment
begin_macro
name|FT_BASE_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_Done_Memory
name|FT_Done_Memory
argument_list|(
argument|FT_Memory  memory
argument_list|)
end_macro
begin_block
block|{
ifdef|#
directive|ifdef
name|FT_DEBUG_MEMORY
name|ft_mem_debug_done
argument_list|(
name|memory
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ft_sfree
argument_list|(
name|memory
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
