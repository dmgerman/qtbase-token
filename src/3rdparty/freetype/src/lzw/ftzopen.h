begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftzopen.h                                                              */
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
comment|/*  Copyright 2005, 2006, 2007, 2008 by David Turner.                      */
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
name|__FT_ZOPEN_H__
end_ifndef
begin_define
DECL|macro|__FT_ZOPEN_H__
define|#
directive|define
name|__FT_ZOPEN_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_comment
comment|/*    *  This is a complete re-implementation of the LZW file reader,    *  since the old one was incredibly badly written, using    *  400 KByte of heap memory before decompressing anything.    *    */
end_comment
begin_define
DECL|macro|FT_LZW_IN_BUFF_SIZE
define|#
directive|define
name|FT_LZW_IN_BUFF_SIZE
value|64
end_define
begin_define
DECL|macro|FT_LZW_DEFAULT_STACK_SIZE
define|#
directive|define
name|FT_LZW_DEFAULT_STACK_SIZE
value|64
end_define
begin_define
DECL|macro|LZW_INIT_BITS
define|#
directive|define
name|LZW_INIT_BITS
value|9
end_define
begin_define
DECL|macro|LZW_MAX_BITS
define|#
directive|define
name|LZW_MAX_BITS
value|16
end_define
begin_define
DECL|macro|LZW_CLEAR
define|#
directive|define
name|LZW_CLEAR
value|256
end_define
begin_define
DECL|macro|LZW_FIRST
define|#
directive|define
name|LZW_FIRST
value|257
end_define
begin_define
DECL|macro|LZW_BIT_MASK
define|#
directive|define
name|LZW_BIT_MASK
value|0x1f
end_define
begin_define
DECL|macro|LZW_BLOCK_MASK
define|#
directive|define
name|LZW_BLOCK_MASK
value|0x80
end_define
begin_define
DECL|macro|LZW_MASK
define|#
directive|define
name|LZW_MASK
parameter_list|(
name|n
parameter_list|)
value|( ( 1U<< (n) ) - 1U )
end_define
begin_typedef
DECL|enum|FT_LzwPhase_
typedef|typedef
enum|enum
name|FT_LzwPhase_
block|{
DECL|enumerator|FT_LZW_PHASE_START
name|FT_LZW_PHASE_START
init|=
literal|0
block|,
DECL|enumerator|FT_LZW_PHASE_CODE
name|FT_LZW_PHASE_CODE
block|,
DECL|enumerator|FT_LZW_PHASE_STACK
name|FT_LZW_PHASE_STACK
block|,
DECL|enumerator|FT_LZW_PHASE_EOF
name|FT_LZW_PHASE_EOF
block|}
DECL|typedef|FT_LzwPhase
name|FT_LzwPhase
typedef|;
end_typedef
begin_comment
comment|/*    *  state of LZW decompressor    *    *  small technical note    *  --------------------    *    *  We use a few tricks in this implementation that are explained here to    *  ease debugging and maintenance.    *    *  - First of all, the `prefix' and `suffix' arrays contain the suffix    *    and prefix for codes over 256; this means that    *    *      prefix_of(code) == state->prefix[code-256]    *      suffix_of(code) == state->suffix[code-256]    *    *    Each prefix is a 16-bit code, and each suffix an 8-bit byte.    *    *    Both arrays are stored in a single memory block, pointed to by    *    `state->prefix'.  This means that the following equality is always    *    true:    *    *      state->suffix == (FT_Byte*)(state->prefix + state->prefix_size)    *    *    Of course, state->prefix_size is the number of prefix/suffix slots    *    in the arrays, corresponding to codes 256..255+prefix_size.    *    *  - `free_ent' is the index of the next free entry in the `prefix'    *    and `suffix' arrays.  This means that the corresponding `next free    *    code' is really `256+free_ent'.    *    *    Moreover, `max_free' is the maximum value that `free_ent' can reach.    *    *    `max_free' corresponds to `(1<< max_bits) - 256'.  Note that this    *    value is always<= 0xFF00, which means that both `free_ent' and    *    `max_free' can be stored in an FT_UInt variable, even on 16-bit    *    machines.    *    *    If `free_ent == max_free', you cannot add new codes to the    *    prefix/suffix table.    *    *  - `num_bits' is the current number of code bits, starting at 9 and    *    growing each time `free_ent' reaches the value of `free_bits'.  The    *    latter is computed as follows    *    *      if num_bits< max_bits:    *         free_bits = (1<< num_bits)-256    *      else:    *         free_bits = max_free + 1    *    *    Since the value of `max_free + 1' can never be reached by    *    `free_ent', `num_bits' cannot grow larger than `max_bits'.    */
end_comment
begin_typedef
DECL|struct|FT_LzwStateRec_
typedef|typedef
struct|struct
name|FT_LzwStateRec_
block|{
DECL|member|phase
name|FT_LzwPhase
name|phase
decl_stmt|;
DECL|member|in_eof
name|FT_Int
name|in_eof
decl_stmt|;
DECL|member|buf_tab
name|FT_Byte
name|buf_tab
index|[
literal|16
index|]
decl_stmt|;
DECL|member|buf_offset
name|FT_Int
name|buf_offset
decl_stmt|;
DECL|member|buf_size
name|FT_Int
name|buf_size
decl_stmt|;
DECL|member|buf_clear
name|FT_Bool
name|buf_clear
decl_stmt|;
DECL|member|buf_total
name|FT_Offset
name|buf_total
decl_stmt|;
DECL|member|max_bits
name|FT_UInt
name|max_bits
decl_stmt|;
comment|/* max code bits, from file header   */
DECL|member|block_mode
name|FT_Int
name|block_mode
decl_stmt|;
comment|/* block mode flag, from file header */
DECL|member|max_free
name|FT_UInt
name|max_free
decl_stmt|;
comment|/* (1<< max_bits) - 256             */
DECL|member|num_bits
name|FT_UInt
name|num_bits
decl_stmt|;
comment|/* current code bit number */
DECL|member|free_ent
name|FT_UInt
name|free_ent
decl_stmt|;
comment|/* index of next free entry */
DECL|member|free_bits
name|FT_UInt
name|free_bits
decl_stmt|;
comment|/* if reached by free_ent, increment num_bits */
DECL|member|old_code
name|FT_UInt
name|old_code
decl_stmt|;
DECL|member|old_char
name|FT_UInt
name|old_char
decl_stmt|;
DECL|member|in_code
name|FT_UInt
name|in_code
decl_stmt|;
DECL|member|prefix
name|FT_UShort
modifier|*
name|prefix
decl_stmt|;
comment|/* always dynamically allocated / reallocated */
DECL|member|suffix
name|FT_Byte
modifier|*
name|suffix
decl_stmt|;
comment|/* suffix = (FT_Byte*)(prefix + prefix_size)  */
DECL|member|prefix_size
name|FT_UInt
name|prefix_size
decl_stmt|;
comment|/* number of slots in `prefix' or `suffix'    */
DECL|member|stack
name|FT_Byte
modifier|*
name|stack
decl_stmt|;
comment|/* character stack */
DECL|member|stack_top
name|FT_UInt
name|stack_top
decl_stmt|;
DECL|member|stack_size
name|FT_Offset
name|stack_size
decl_stmt|;
DECL|member|stack_0
name|FT_Byte
name|stack_0
index|[
name|FT_LZW_DEFAULT_STACK_SIZE
index|]
decl_stmt|;
comment|/* minimize heap alloc */
DECL|member|source
name|FT_Stream
name|source
decl_stmt|;
comment|/* source stream */
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
block|}
DECL|typedef|FT_LzwStateRec
DECL|typedef|FT_LzwState
name|FT_LzwStateRec
operator|,
typedef|*
name|FT_LzwState
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ft_lzwstate_init
argument_list|(
argument|FT_LzwState  state
argument_list|,
argument|FT_Stream    source
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
DECL|variable|state
name|ft_lzwstate_done
argument_list|(
argument|FT_LzwState  state
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|state
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|state
name|ft_lzwstate_reset
argument_list|(
argument|FT_LzwState  state
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|state
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
name|ft_lzwstate_io
argument_list|(
argument|FT_LzwState  state
argument_list|,
argument|FT_Byte*     buffer
argument_list|,
argument|FT_ULong     out_size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FT_ZOPEN_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
