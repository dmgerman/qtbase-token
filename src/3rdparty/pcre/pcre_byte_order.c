begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2014 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains an internal function that tests a compiled pattern to see if it was compiled with the opposite endianness. If so, it uses an auxiliary local function to flip the appropriate bytes. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_comment
comment|/************************************************* *             Swap byte functions                * *************************************************/
end_comment
begin_comment
comment|/* The following functions swap the bytes of a pcre_uint16 and pcre_uint32 value.  Arguments:   value        any number  Returns:       the byte swapped value */
end_comment
begin_function
specifier|static
name|pcre_uint32
DECL|function|swap_uint32
name|swap_uint32
parameter_list|(
name|pcre_uint32
name|value
parameter_list|)
block|{
return|return
operator|(
operator|(
name|value
operator|&
literal|0x000000ff
operator|)
operator|<<
literal|24
operator|)
operator||
operator|(
operator|(
name|value
operator|&
literal|0x0000ff00
operator|)
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
name|value
operator|&
literal|0x00ff0000
operator|)
operator|>>
literal|8
operator|)
operator||
operator|(
name|value
operator|>>
literal|24
operator|)
return|;
block|}
end_function
begin_function
specifier|static
name|pcre_uint16
DECL|function|swap_uint16
name|swap_uint16
parameter_list|(
name|pcre_uint16
name|value
parameter_list|)
block|{
return|return
operator|(
name|value
operator|>>
literal|8
operator|)
operator||
operator|(
name|value
operator|<<
literal|8
operator|)
return|;
block|}
end_function
begin_comment
comment|/************************************************* *       Test for a byte-flipped compiled regex   * *************************************************/
end_comment
begin_comment
comment|/* This function swaps the bytes of a compiled pattern usually loaded form the disk. It also sets the tables pointer, which is likely an invalid pointer after reload.  Arguments:   argument_re     points to the compiled expression   extra_data      points to extra data or is NULL   tables          points to the character tables or NULL  Returns:          0 if the swap is successful, negative on error */
end_comment
begin_if
if|#
directive|if
name|defined
name|COMPILE_PCRE8
end_if
begin_decl_stmt
DECL|function|pcre_pattern_to_host_byte_order
name|PCRE_EXP_DECL
name|int
name|pcre_pattern_to_host_byte_order
argument_list|(
name|pcre
operator|*
name|argument_re
argument_list|,
name|pcre_extra
operator|*
name|extra_data
argument_list|,
specifier|const
name|unsigned
name|char
operator|*
name|tables
argument_list|)
elif|#
directive|elif
name|defined
name|COMPILE_PCRE16
name|PCRE_EXP_DECL
name|int
name|pcre16_pattern_to_host_byte_order
argument_list|(
name|pcre16
operator|*
name|argument_re
argument_list|,
name|pcre16_extra
operator|*
name|extra_data
argument_list|,
specifier|const
name|unsigned
name|char
operator|*
name|tables
argument_list|)
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
name|PCRE_EXP_DECL
name|int
name|pcre32_pattern_to_host_byte_order
argument_list|(
name|pcre32
operator|*
name|argument_re
argument_list|,
name|pcre32_extra
operator|*
name|extra_data
argument_list|,
specifier|const
name|unsigned
name|char
operator|*
name|tables
argument_list|)
endif|#
directive|endif
block|{
name|REAL_PCRE
modifier|*
name|re
init|=
operator|(
name|REAL_PCRE
operator|*
operator|)
name|argument_re
decl_stmt|;
name|pcre_study_data
modifier|*
name|study
decl_stmt|;
ifndef|#
directive|ifndef
name|COMPILE_PCRE8
name|pcre_uchar
modifier|*
name|ptr
decl_stmt|;
name|int
name|length
decl_stmt|;
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|&&
name|defined
name|COMPILE_PCRE16
name|BOOL
name|utf
decl_stmt|;
name|BOOL
name|utf16_char
decl_stmt|;
endif|#
directive|endif
comment|/* SUPPORT_UTF&& COMPILE_PCRE16 */
endif|#
directive|endif
comment|/* !COMPILE_PCRE8 */
if|if
condition|(
name|re
operator|==
name|NULL
condition|)
return|return
name|PCRE_ERROR_NULL
return|;
if|if
condition|(
name|re
operator|->
name|magic_number
operator|==
name|MAGIC_NUMBER
condition|)
block|{
if|if
condition|(
operator|(
name|re
operator|->
name|flags
operator|&
name|PCRE_MODE
operator|)
operator|==
literal|0
condition|)
return|return
name|PCRE_ERROR_BADMODE
return|;
name|re
operator|->
name|tables
operator|=
name|tables
expr_stmt|;
return|return
literal|0
return|;
block|}
if|if
condition|(
name|re
operator|->
name|magic_number
operator|!=
name|REVERSED_MAGIC_NUMBER
condition|)
return|return
name|PCRE_ERROR_BADMAGIC
return|;
if|if
condition|(
operator|(
name|swap_uint32
argument_list|(
name|re
operator|->
name|flags
argument_list|)
operator|&
name|PCRE_MODE
operator|)
operator|==
literal|0
condition|)
return|return
name|PCRE_ERROR_BADMODE
return|;
name|re
operator|->
name|magic_number
operator|=
name|MAGIC_NUMBER
expr_stmt|;
name|re
operator|->
name|size
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|size
argument_list|)
expr_stmt|;
name|re
operator|->
name|options
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|options
argument_list|)
expr_stmt|;
name|re
operator|->
name|flags
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|flags
argument_list|)
expr_stmt|;
name|re
operator|->
name|limit_match
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|limit_match
argument_list|)
expr_stmt|;
name|re
operator|->
name|limit_recursion
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|limit_recursion
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
name|COMPILE_PCRE8
operator|||
name|defined
name|COMPILE_PCRE16
name|re
operator|->
name|first_char
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|first_char
argument_list|)
expr_stmt|;
name|re
operator|->
name|req_char
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|req_char
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
name|re
operator|->
name|first_char
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|first_char
argument_list|)
expr_stmt|;
name|re
operator|->
name|req_char
operator|=
name|swap_uint32
argument_list|(
name|re
operator|->
name|req_char
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|re
operator|->
name|max_lookbehind
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|max_lookbehind
argument_list|)
expr_stmt|;
name|re
operator|->
name|top_bracket
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|top_bracket
argument_list|)
expr_stmt|;
name|re
operator|->
name|top_backref
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|top_backref
argument_list|)
expr_stmt|;
name|re
operator|->
name|name_table_offset
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|name_table_offset
argument_list|)
expr_stmt|;
name|re
operator|->
name|name_entry_size
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|name_entry_size
argument_list|)
expr_stmt|;
name|re
operator|->
name|name_count
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|name_count
argument_list|)
expr_stmt|;
name|re
operator|->
name|ref_count
operator|=
name|swap_uint16
argument_list|(
name|re
operator|->
name|ref_count
argument_list|)
expr_stmt|;
name|re
operator|->
name|tables
operator|=
name|tables
expr_stmt|;
if|if
condition|(
name|extra_data
operator|!=
name|NULL
operator|&&
operator|(
name|extra_data
operator|->
name|flags
operator|&
name|PCRE_EXTRA_STUDY_DATA
operator|)
operator|!=
literal|0
condition|)
block|{
name|study
operator|=
operator|(
name|pcre_study_data
operator|*
operator|)
name|extra_data
operator|->
name|study_data
expr_stmt|;
name|study
operator|->
name|size
operator|=
name|swap_uint32
argument_list|(
name|study
operator|->
name|size
argument_list|)
expr_stmt|;
name|study
operator|->
name|flags
operator|=
name|swap_uint32
argument_list|(
name|study
operator|->
name|flags
argument_list|)
expr_stmt|;
name|study
operator|->
name|minlength
operator|=
name|swap_uint32
argument_list|(
name|study
operator|->
name|minlength
argument_list|)
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|COMPILE_PCRE8
name|ptr
operator|=
operator|(
name|pcre_uchar
operator|*
operator|)
name|re
operator|+
name|re
operator|->
name|name_table_offset
expr_stmt|;
name|length
operator|=
name|re
operator|->
name|name_count
operator|*
name|re
operator|->
name|name_entry_size
expr_stmt|;
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|&&
name|defined
name|COMPILE_PCRE16
name|utf
operator|=
operator|(
name|re
operator|->
name|options
operator|&
name|PCRE_UTF16
operator|)
operator|!=
literal|0
expr_stmt|;
name|utf16_char
operator|=
name|FALSE
expr_stmt|;
endif|#
directive|endif
comment|/* SUPPORT_UTF&& COMPILE_PCRE16 */
while|while
condition|(
name|TRUE
condition|)
block|{
comment|/* Swap previous characters. */
while|while
condition|(
name|length
operator|--
operator|>
literal|0
condition|)
block|{
if|#
directive|if
name|defined
name|COMPILE_PCRE16
operator|*
name|ptr
operator|=
name|swap_uint16
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
operator|*
name|ptr
operator|=
name|swap_uint32
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ptr
operator|++
expr_stmt|;
block|}
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|&&
name|defined
name|COMPILE_PCRE16
if|if
condition|(
name|utf16_char
condition|)
block|{
if|if
condition|(
name|HAS_EXTRALEN
argument_list|(
name|ptr
index|[
operator|-
literal|1
index|]
argument_list|)
condition|)
block|{
comment|/* We know that there is only one extra character in UTF-16. */
operator|*
name|ptr
operator|=
name|swap_uint16
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
name|ptr
operator|++
expr_stmt|;
block|}
block|}
name|utf16_char
operator|=
name|FALSE
expr_stmt|;
endif|#
directive|endif
comment|/* SUPPORT_UTF */
comment|/* Get next opcode. */
name|length
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|defined
name|COMPILE_PCRE16
operator|*
name|ptr
operator|=
name|swap_uint16
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
operator|*
name|ptr
operator|=
name|swap_uint32
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
endif|#
directive|endif
switch|switch
condition|(
operator|*
name|ptr
condition|)
block|{
case|case
name|OP_END
case|:
return|return
literal|0
return|;
if|#
directive|if
name|defined
name|SUPPORT_UTF
operator|&&
name|defined
name|COMPILE_PCRE16
case|case
name|OP_CHAR
case|:
case|case
name|OP_CHARI
case|:
case|case
name|OP_NOT
case|:
case|case
name|OP_NOTI
case|:
case|case
name|OP_STAR
case|:
case|case
name|OP_MINSTAR
case|:
case|case
name|OP_PLUS
case|:
case|case
name|OP_MINPLUS
case|:
case|case
name|OP_QUERY
case|:
case|case
name|OP_MINQUERY
case|:
case|case
name|OP_UPTO
case|:
case|case
name|OP_MINUPTO
case|:
case|case
name|OP_EXACT
case|:
case|case
name|OP_POSSTAR
case|:
case|case
name|OP_POSPLUS
case|:
case|case
name|OP_POSQUERY
case|:
case|case
name|OP_POSUPTO
case|:
case|case
name|OP_STARI
case|:
case|case
name|OP_MINSTARI
case|:
case|case
name|OP_PLUSI
case|:
case|case
name|OP_MINPLUSI
case|:
case|case
name|OP_QUERYI
case|:
case|case
name|OP_MINQUERYI
case|:
case|case
name|OP_UPTOI
case|:
case|case
name|OP_MINUPTOI
case|:
case|case
name|OP_EXACTI
case|:
case|case
name|OP_POSSTARI
case|:
case|case
name|OP_POSPLUSI
case|:
case|case
name|OP_POSQUERYI
case|:
case|case
name|OP_POSUPTOI
case|:
case|case
name|OP_NOTSTAR
case|:
case|case
name|OP_NOTMINSTAR
case|:
case|case
name|OP_NOTPLUS
case|:
case|case
name|OP_NOTMINPLUS
case|:
case|case
name|OP_NOTQUERY
case|:
case|case
name|OP_NOTMINQUERY
case|:
case|case
name|OP_NOTUPTO
case|:
case|case
name|OP_NOTMINUPTO
case|:
case|case
name|OP_NOTEXACT
case|:
case|case
name|OP_NOTPOSSTAR
case|:
case|case
name|OP_NOTPOSPLUS
case|:
case|case
name|OP_NOTPOSQUERY
case|:
case|case
name|OP_NOTPOSUPTO
case|:
case|case
name|OP_NOTSTARI
case|:
case|case
name|OP_NOTMINSTARI
case|:
case|case
name|OP_NOTPLUSI
case|:
case|case
name|OP_NOTMINPLUSI
case|:
case|case
name|OP_NOTQUERYI
case|:
case|case
name|OP_NOTMINQUERYI
case|:
case|case
name|OP_NOTUPTOI
case|:
case|case
name|OP_NOTMINUPTOI
case|:
case|case
name|OP_NOTEXACTI
case|:
case|case
name|OP_NOTPOSSTARI
case|:
case|case
name|OP_NOTPOSPLUSI
case|:
case|case
name|OP_NOTPOSQUERYI
case|:
case|case
name|OP_NOTPOSUPTOI
case|:
if|if
condition|(
name|utf
condition|)
name|utf16_char
operator|=
name|TRUE
expr_stmt|;
endif|#
directive|endif
comment|/* Fall through. */
default|default:
name|length
operator|=
name|PRIV
argument_list|(
name|OP_lengths
argument_list|)
index|[
operator|*
name|ptr
index|]
operator|-
literal|1
expr_stmt|;
break|break;
case|case
name|OP_CLASS
case|:
case|case
name|OP_NCLASS
case|:
comment|/* Skip the character bit map. */
name|ptr
operator|+=
literal|32
operator|/
sizeof|sizeof
argument_list|(
name|pcre_uchar
argument_list|)
expr_stmt|;
name|length
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|OP_XCLASS
case|:
comment|/* Reverse the size of the XCLASS instance. */
name|ptr
operator|++
expr_stmt|;
if|#
directive|if
name|defined
name|COMPILE_PCRE16
operator|*
name|ptr
operator|=
name|swap_uint16
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
operator|*
name|ptr
operator|=
name|swap_uint32
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|COMPILE_PCRE32
if|if
condition|(
name|LINK_SIZE
operator|>
literal|1
condition|)
block|{
comment|/* LINK_SIZE can be 1 or 2 in 16 bit mode. */
name|ptr
operator|++
expr_stmt|;
operator|*
name|ptr
operator|=
name|swap_uint16
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|ptr
operator|++
expr_stmt|;
name|length
operator|=
operator|(
name|GET
argument_list|(
name|ptr
argument_list|,
operator|-
name|LINK_SIZE
argument_list|)
operator|)
operator|-
operator|(
literal|1
operator|+
name|LINK_SIZE
operator|+
literal|1
operator|)
expr_stmt|;
if|#
directive|if
name|defined
name|COMPILE_PCRE16
operator|*
name|ptr
operator|=
name|swap_uint16
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
name|COMPILE_PCRE32
operator|*
name|ptr
operator|=
name|swap_uint32
argument_list|(
operator|*
name|ptr
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|(
operator|*
name|ptr
operator|&
name|XCL_MAP
operator|)
operator|!=
literal|0
condition|)
block|{
comment|/* Skip the character bit map. */
name|ptr
operator|+=
literal|32
operator|/
sizeof|sizeof
argument_list|(
name|pcre_uchar
argument_list|)
expr_stmt|;
name|length
operator|-=
literal|32
operator|/
sizeof|sizeof
argument_list|(
name|pcre_uchar
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
name|ptr
operator|++
expr_stmt|;
block|}
comment|/* Control should never reach here in 16/32 bit mode. */
else|#
directive|else
comment|/* In 8-bit mode, the pattern does not need to be processed. */
return|return
literal|0
return|;
endif|#
directive|endif
comment|/* !COMPILE_PCRE8 */
block|}
end_decl_stmt
begin_comment
comment|/* End of pcre_byte_order.c */
end_comment
end_unit
