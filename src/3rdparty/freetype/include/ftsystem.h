begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftsystem.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType low-level system interface definition (specification).      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2005, 2010, 2014 by                         */
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
name|__FTSYSTEM_H__
end_ifndef
begin_define
DECL|macro|__FTSYSTEM_H__
define|#
directive|define
name|__FTSYSTEM_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*   system_interface                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*   System Interface                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*   How FreeType manages memory and i/o.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*   This section contains various definitions related to memory         */
end_comment
begin_comment
comment|/*   management and i/o access.  You need to understand this             */
end_comment
begin_comment
comment|/*   information if you want to use a custom memory manager or you own   */
end_comment
begin_comment
comment|/*   i/o streams.                                                        */
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
comment|/*                  M E M O R Y   M A N A G E M E N T                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type:    *   FT_Memory    *    * @description:    *   A handle to a given memory manager object, defined with an    *   @FT_MemoryRec structure.    *    */
end_comment
begin_typedef
DECL|typedef|FT_Memory
typedef|typedef
name|struct
name|FT_MemoryRec_
modifier|*
name|FT_Memory
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   FT_Alloc_Func    *    * @description:    *   A function used to allocate `size' bytes from `memory'.    *    * @input:    *   memory ::    *     A handle to the source memory manager.    *    *   size ::    *     The size in bytes to allocate.    *    * @return:    *   Address of new memory block.  0~in case of failure.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
DECL|typedef|FT_Alloc_Func
modifier|*
name|FT_Alloc_Func
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   FT_Free_Func    *    * @description:    *   A function used to release a given block of memory.    *    * @input:    *   memory ::    *     A handle to the source memory manager.    *    *   block ::    *     The address of the target memory block.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Free_Func
modifier|*
name|FT_Free_Func
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   FT_Realloc_Func    *    * @description:    *   A function used to re-allocate a given block of memory.    *    * @input:    *   memory ::    *     A handle to the source memory manager.    *    *   cur_size ::    *     The block's current size in bytes.    *    *   new_size ::    *     The block's requested new size.    *    *   block ::    *     The block's current address.    *    * @return:    *   New block address.  0~in case of memory shortage.    *    * @note:    *   In case of error, the old block must still be available.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
DECL|typedef|FT_Realloc_Func
modifier|*
name|FT_Realloc_Func
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|long
name|cur_size
parameter_list|,
name|long
name|new_size
parameter_list|,
name|void
modifier|*
name|block
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @struct:    *   FT_MemoryRec    *    * @description:    *   A structure used to describe a given memory manager to FreeType~2.    *    * @fields:    *   user ::    *     A generic typeless pointer for user data.    *    *   alloc ::    *     A pointer type to an allocation function.    *    *   free ::    *     A pointer type to an memory freeing function.    *    *   realloc ::    *     A pointer type to a reallocation function.    *    */
end_comment
begin_struct
DECL|struct|FT_MemoryRec_
struct|struct
name|FT_MemoryRec_
block|{
DECL|member|user
name|void
modifier|*
name|user
decl_stmt|;
DECL|member|alloc
name|FT_Alloc_Func
name|alloc
decl_stmt|;
DECL|member|free
name|FT_Free_Func
name|free
decl_stmt|;
DECL|member|realloc
name|FT_Realloc_Func
name|realloc
decl_stmt|;
block|}
struct|;
end_struct
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                       I / O   M A N A G E M E N T                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @type:    *   FT_Stream    *    * @description:    *   A handle to an input stream.    *    * @also:    *   See @FT_StreamRec for the publicly accessible fields of a given    *   stream object.    *    */
end_comment
begin_typedef
DECL|typedef|FT_Stream
typedef|typedef
name|struct
name|FT_StreamRec_
modifier|*
name|FT_Stream
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @struct:    *   FT_StreamDesc    *    * @description:    *   A union type used to store either a long or a pointer.  This is used    *   to store a file descriptor or a `FILE*' in an input stream.    *    */
end_comment
begin_typedef
DECL|union|FT_StreamDesc_
typedef|typedef
union|union
name|FT_StreamDesc_
block|{
DECL|member|value
name|long
name|value
decl_stmt|;
DECL|member|pointer
name|void
modifier|*
name|pointer
decl_stmt|;
block|}
DECL|typedef|FT_StreamDesc
name|FT_StreamDesc
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   FT_Stream_IoFunc    *    * @description:    *   A function used to seek and read data from a given input stream.    *    * @input:    *   stream ::    *     A handle to the source stream.    *    *   offset ::    *     The offset of read in stream (always from start).    *    *   buffer ::    *     The address of the read buffer.    *    *   count ::    *     The number of bytes to read from the stream.    *    * @return:    *   The number of bytes effectively read by the stream.    *    * @note:    *   This function might be called to perform a seek or skip operation    *   with a `count' of~0.  A non-zero return value then indicates an    *   error.    *    */
end_comment
begin_typedef
typedef|typedef
name|unsigned
name|long
function_decl|(
DECL|typedef|FT_Stream_IoFunc
modifier|*
name|FT_Stream_IoFunc
function_decl|)
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|long
name|count
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @functype:    *   FT_Stream_CloseFunc    *    * @description:    *   A function used to close a given input stream.    *    * @input:    *  stream ::    *     A handle to the target stream.    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Stream_CloseFunc
modifier|*
name|FT_Stream_CloseFunc
function_decl|)
parameter_list|(
name|FT_Stream
name|stream
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************    *    * @struct:    *   FT_StreamRec    *    * @description:    *   A structure used to describe an input stream.    *    * @input:    *   base ::    *     For memory-based streams, this is the address of the first stream    *     byte in memory.  This field should always be set to NULL for    *     disk-based streams.    *    *   size ::    *     The stream size in bytes.    *    *     In case of compressed streams where the size is unknown before    *     actually doing the decompression, the value is set to 0x7FFFFFFF.     *     (Note that this size value can occur for normal streams also; it is    *     thus just a hint.)    *    *   pos ::    *     The current position within the stream.    *    *   descriptor ::    *     This field is a union that can hold an integer or a pointer.  It is    *     used by stream implementations to store file descriptors or `FILE*'    *     pointers.    *    *   pathname ::    *     This field is completely ignored by FreeType.  However, it is often    *     useful during debugging to use it to store the stream's filename    *     (where available).    *    *   read ::    *     The stream's input function.    *    *   close ::    *     The stream's close function.    *    *   memory ::    *     The memory manager to use to preload frames.  This is set    *     internally by FreeType and shouldn't be touched by stream    *     implementations.    *    *   cursor ::    *     This field is set and used internally by FreeType when parsing    *     frames.    *    *   limit ::    *     This field is set and used internally by FreeType when parsing    *     frames.    *    */
end_comment
begin_typedef
DECL|struct|FT_StreamRec_
typedef|typedef
struct|struct
name|FT_StreamRec_
block|{
DECL|member|base
name|unsigned
name|char
modifier|*
name|base
decl_stmt|;
DECL|member|size
name|unsigned
name|long
name|size
decl_stmt|;
DECL|member|pos
name|unsigned
name|long
name|pos
decl_stmt|;
DECL|member|descriptor
name|FT_StreamDesc
name|descriptor
decl_stmt|;
DECL|member|pathname
name|FT_StreamDesc
name|pathname
decl_stmt|;
DECL|member|read
name|FT_Stream_IoFunc
name|read
decl_stmt|;
DECL|member|close
name|FT_Stream_CloseFunc
name|close
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|cursor
name|unsigned
name|char
modifier|*
name|cursor
decl_stmt|;
DECL|member|limit
name|unsigned
name|char
modifier|*
name|limit
decl_stmt|;
block|}
DECL|typedef|FT_StreamRec
name|FT_StreamRec
typedef|;
end_typedef
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
comment|/* __FTSYSTEM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
