begin_unit
begin_comment
comment|/**  * Copyright Â© 2012 Intel Corporation  * Copyright Â© 2012 Ran Benita<ran234@gmail.com>  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Author: Daniel Stone<daniel@fooishbar.org>  */
end_comment
begin_comment
comment|/************************************************************  * Copyright (c) 1993 by Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting  * documentation, and that the name of Silicon Graphics not be  * used in advertising or publicity pertaining to distribution  * of the software without specific prior written permission.  * Silicon Graphics makes no representation about the suitability  * of this software for any purpose. It is provided "as is"  * without any express or implied warranty.  *  * SILICON GRAPHICS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS  * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SILICON  * GRAPHICS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH  * THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * ********************************************************/
end_comment
begin_include
include|#
directive|include
file|"keymap.h"
end_include
begin_include
include|#
directive|include
file|"text.h"
end_include
begin_function
specifier|static
name|struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_new
name|xkb_keymap_new
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|enum
name|xkb_keymap_format
name|format
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
block|{
name|struct
name|xkb_keymap
modifier|*
name|keymap
decl_stmt|;
name|keymap
operator|=
name|calloc
argument_list|(
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|keymap
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keymap
condition|)
return|return
name|NULL
return|;
name|keymap
operator|->
name|refcnt
operator|=
literal|1
expr_stmt|;
name|keymap
operator|->
name|ctx
operator|=
name|xkb_context_ref
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|keymap
operator|->
name|format
operator|=
name|format
expr_stmt|;
name|keymap
operator|->
name|flags
operator|=
name|flags
expr_stmt|;
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_ref
name|xkb_keymap_ref
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
name|keymap
operator|->
name|refcnt
operator|++
expr_stmt|;
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|void
DECL|function|xkb_keymap_unref
name|xkb_keymap_unref
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|struct
name|xkb_key
modifier|*
name|key
decl_stmt|;
if|if
condition|(
operator|!
name|keymap
operator|||
operator|--
name|keymap
operator|->
name|refcnt
operator|>
literal|0
condition|)
return|return;
if|if
condition|(
name|keymap
operator|->
name|keys
condition|)
block|{
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|key
operator|->
name|num_groups
condition|;
name|i
operator|++
control|)
block|{
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|XkbKeyGroupWidth
argument_list|(
name|key
argument_list|,
name|i
argument_list|)
condition|;
name|j
operator|++
control|)
if|if
condition|(
name|key
operator|->
name|groups
index|[
name|i
index|]
operator|.
name|levels
index|[
name|j
index|]
operator|.
name|num_syms
operator|>
literal|1
condition|)
name|free
argument_list|(
name|key
operator|->
name|groups
index|[
name|i
index|]
operator|.
name|levels
index|[
name|j
index|]
operator|.
name|u
operator|.
name|syms
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|key
operator|->
name|groups
index|[
name|i
index|]
operator|.
name|levels
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|key
operator|->
name|groups
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|keymap
operator|->
name|keys
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|keymap
operator|->
name|num_types
condition|;
name|i
operator|++
control|)
block|{
name|free
argument_list|(
name|keymap
operator|->
name|types
index|[
name|i
index|]
operator|.
name|entries
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|types
index|[
name|i
index|]
operator|.
name|level_names
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|keymap
operator|->
name|types
argument_list|)
expr_stmt|;
name|darray_free
argument_list|(
name|keymap
operator|->
name|sym_interprets
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|key_aliases
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|group_names
argument_list|)
expr_stmt|;
name|darray_free
argument_list|(
name|keymap
operator|->
name|mods
argument_list|)
expr_stmt|;
name|darray_free
argument_list|(
name|keymap
operator|->
name|leds
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|keycodes_section_name
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|symbols_section_name
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|types_section_name
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
operator|->
name|compat_section_name
argument_list|)
expr_stmt|;
name|xkb_context_unref
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|keymap
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
DECL|function|get_keymap_format_ops
name|get_keymap_format_ops
parameter_list|(
name|enum
name|xkb_keymap_format
name|format
parameter_list|)
block|{
specifier|static
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
name|keymap_format_ops
index|[]
init|=
block|{
index|[
name|XKB_KEYMAP_FORMAT_TEXT_V1
index|]
operator|=
operator|&
name|text_v1_keymap_format_ops
block|,     }
decl_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|format
operator|<
literal|0
operator|||
operator|(
name|int
operator|)
name|format
operator|>=
name|ARRAY_SIZE
argument_list|(
name|keymap_format_ops
argument_list|)
condition|)
return|return
name|NULL
return|;
return|return
name|keymap_format_ops
index|[
name|format
index|]
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_new_from_names
name|xkb_keymap_new_from_names
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|struct
name|xkb_rule_names
modifier|*
name|rmlvo_in
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
block|{
name|struct
name|xkb_keymap
modifier|*
name|keymap
decl_stmt|;
name|struct
name|xkb_rule_names
name|rmlvo
decl_stmt|;
specifier|const
name|enum
name|xkb_keymap_format
name|format
init|=
name|XKB_KEYMAP_FORMAT_TEXT_V1
decl_stmt|;
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
name|ops
decl_stmt|;
name|ops
operator|=
name|get_keymap_format_ops
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ops
operator|||
operator|!
name|ops
operator|->
name|keymap_new_from_names
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unsupported keymap format: %d\n"
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|flags
operator|&
operator|~
operator|(
name|XKB_MAP_COMPILE_PLACEHOLDER
operator|)
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unrecognized flags: %#x\n"
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|rmlvo_in
condition|)
name|rmlvo
operator|=
operator|*
name|rmlvo_in
expr_stmt|;
else|else
name|memset
argument_list|(
operator|&
name|rmlvo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|rmlvo
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|isempty
argument_list|(
name|rmlvo
operator|.
name|rules
argument_list|)
condition|)
name|rmlvo
operator|.
name|rules
operator|=
name|xkb_context_get_default_rules
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
if|if
condition|(
name|isempty
argument_list|(
name|rmlvo
operator|.
name|model
argument_list|)
condition|)
name|rmlvo
operator|.
name|model
operator|=
name|xkb_context_get_default_model
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
comment|/* Layout and variant are tied together, so don't try to use one from      * the caller and one from the environment. */
if|if
condition|(
name|isempty
argument_list|(
name|rmlvo
operator|.
name|layout
argument_list|)
condition|)
block|{
name|rmlvo
operator|.
name|layout
operator|=
name|xkb_context_get_default_layout
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|rmlvo
operator|.
name|variant
operator|=
name|xkb_context_get_default_variant
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
block|}
comment|/* Options can be empty, so respect that if passed in. */
if|if
condition|(
name|rmlvo
operator|.
name|options
operator|==
name|NULL
condition|)
name|rmlvo
operator|.
name|options
operator|=
name|xkb_context_get_default_options
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|keymap
operator|=
name|xkb_keymap_new
argument_list|(
name|ctx
argument_list|,
name|format
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keymap
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|!
name|ops
operator|->
name|keymap_new_from_names
argument_list|(
name|keymap
argument_list|,
operator|&
name|rmlvo
argument_list|)
condition|)
block|{
name|xkb_keymap_unref
argument_list|(
name|keymap
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_new_from_string
name|xkb_keymap_new_from_string
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|,
name|enum
name|xkb_keymap_format
name|format
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
block|{
name|struct
name|xkb_keymap
modifier|*
name|keymap
decl_stmt|;
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
name|ops
decl_stmt|;
name|ops
operator|=
name|get_keymap_format_ops
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ops
operator|||
operator|!
name|ops
operator|->
name|keymap_new_from_string
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unsupported keymap format: %d\n"
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|flags
operator|&
operator|~
operator|(
name|XKB_MAP_COMPILE_PLACEHOLDER
operator|)
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unrecognized flags: %#x\n"
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
operator|!
name|string
condition|)
block|{
name|log_err_func1
argument_list|(
name|ctx
argument_list|,
literal|"no string specified\n"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|keymap
operator|=
name|xkb_keymap_new
argument_list|(
name|ctx
argument_list|,
name|format
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keymap
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|!
name|ops
operator|->
name|keymap_new_from_string
argument_list|(
name|keymap
argument_list|,
name|string
argument_list|)
condition|)
block|{
name|xkb_keymap_unref
argument_list|(
name|keymap
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_new_from_buffer
name|xkb_keymap_new_from_buffer
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|length
parameter_list|,
name|enum
name|xkb_keymap_format
name|format
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
block|{
name|struct
name|xkb_keymap
modifier|*
name|keymap
decl_stmt|;
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
name|ops
decl_stmt|;
name|ops
operator|=
name|get_keymap_format_ops
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ops
operator|||
operator|!
name|ops
operator|->
name|keymap_new_from_string
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unsupported keymap format: %d\n"
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|flags
operator|&
operator|~
operator|(
name|XKB_MAP_COMPILE_PLACEHOLDER
operator|)
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unrecognized flags: %#x\n"
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
operator|!
name|buffer
condition|)
block|{
name|log_err_func1
argument_list|(
name|ctx
argument_list|,
literal|"no buffer specified\n"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|keymap
operator|=
name|xkb_keymap_new
argument_list|(
name|ctx
argument_list|,
name|format
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keymap
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|!
name|ops
operator|->
name|keymap_new_from_buffer
argument_list|(
name|keymap
argument_list|,
name|buffer
argument_list|,
name|length
argument_list|)
condition|)
block|{
name|xkb_keymap_unref
argument_list|(
name|keymap
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|struct
name|xkb_keymap
modifier|*
DECL|function|xkb_keymap_new_from_file
name|xkb_keymap_new_from_file
parameter_list|(
name|struct
name|xkb_context
modifier|*
name|ctx
parameter_list|,
name|FILE
modifier|*
name|file
parameter_list|,
name|enum
name|xkb_keymap_format
name|format
parameter_list|,
name|enum
name|xkb_keymap_compile_flags
name|flags
parameter_list|)
block|{
name|struct
name|xkb_keymap
modifier|*
name|keymap
decl_stmt|;
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
name|ops
decl_stmt|;
name|ops
operator|=
name|get_keymap_format_ops
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ops
operator|||
operator|!
name|ops
operator|->
name|keymap_new_from_file
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unsupported keymap format: %d\n"
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|flags
operator|&
operator|~
operator|(
name|XKB_MAP_COMPILE_PLACEHOLDER
operator|)
condition|)
block|{
name|log_err_func
argument_list|(
name|ctx
argument_list|,
literal|"unrecognized flags: %#x\n"
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
operator|!
name|file
condition|)
block|{
name|log_err_func1
argument_list|(
name|ctx
argument_list|,
literal|"no file specified\n"
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|keymap
operator|=
name|xkb_keymap_new
argument_list|(
name|ctx
argument_list|,
name|format
argument_list|,
name|flags
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|keymap
condition|)
return|return
name|NULL
return|;
if|if
condition|(
operator|!
name|ops
operator|->
name|keymap_new_from_file
argument_list|(
name|keymap
argument_list|,
name|file
argument_list|)
condition|)
block|{
name|xkb_keymap_unref
argument_list|(
name|keymap
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|keymap
return|;
block|}
end_function
begin_function
name|XKB_EXPORT
name|char
modifier|*
DECL|function|xkb_keymap_get_as_string
name|xkb_keymap_get_as_string
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|enum
name|xkb_keymap_format
name|format
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_keymap_format_ops
modifier|*
name|ops
decl_stmt|;
if|if
condition|(
name|format
operator|==
name|XKB_KEYMAP_USE_ORIGINAL_FORMAT
condition|)
name|format
operator|=
name|keymap
operator|->
name|format
expr_stmt|;
name|ops
operator|=
name|get_keymap_format_ops
argument_list|(
name|format
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ops
operator|||
operator|!
name|ops
operator|->
name|keymap_get_as_string
condition|)
block|{
name|log_err_func
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
literal|"unsupported keymap format: %d\n"
argument_list|,
name|format
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
return|return
name|ops
operator|->
name|keymap_get_as_string
argument_list|(
name|keymap
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the total number of modifiers active in the keymap.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_mod_index_t
DECL|function|xkb_keymap_num_mods
name|xkb_keymap_num_mods
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
return|return
name|darray_size
argument_list|(
name|keymap
operator|->
name|mods
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Return the name for a given modifier.  */
end_comment
begin_function
name|XKB_EXPORT
specifier|const
name|char
modifier|*
DECL|function|xkb_keymap_mod_get_name
name|xkb_keymap_mod_get_name
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_mod_index_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|>=
name|darray_size
argument_list|(
name|keymap
operator|->
name|mods
argument_list|)
condition|)
return|return
name|NULL
return|;
return|return
name|xkb_atom_text
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|darray_item
argument_list|(
name|keymap
operator|->
name|mods
argument_list|,
name|idx
argument_list|)
operator|.
name|name
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the index for a named modifier.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_mod_index_t
DECL|function|xkb_keymap_mod_get_index
name|xkb_keymap_mod_get_index
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|xkb_mod_index_t
name|i
decl_stmt|;
name|xkb_atom_t
name|atom
decl_stmt|;
specifier|const
name|struct
name|xkb_mod
modifier|*
name|mod
decl_stmt|;
name|atom
operator|=
name|xkb_atom_lookup
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|atom
operator|==
name|XKB_ATOM_NONE
condition|)
return|return
name|XKB_MOD_INVALID
return|;
name|darray_enumerate
argument_list|(
argument|i
argument_list|,
argument|mod
argument_list|,
argument|keymap->mods
argument_list|)
if|if
condition|(
name|mod
operator|->
name|name
operator|==
name|atom
condition|)
return|return
name|i
return|;
return|return
name|XKB_MOD_INVALID
return|;
block|}
end_function
begin_comment
comment|/**  * Return the total number of active groups in the keymap.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_layout_index_t
DECL|function|xkb_keymap_num_layouts
name|xkb_keymap_num_layouts
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
return|return
name|keymap
operator|->
name|num_groups
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the name for a given group.  */
end_comment
begin_function
name|XKB_EXPORT
specifier|const
name|char
modifier|*
DECL|function|xkb_keymap_layout_get_name
name|xkb_keymap_layout_get_name
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_layout_index_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|>=
name|keymap
operator|->
name|num_group_names
condition|)
return|return
name|NULL
return|;
return|return
name|xkb_atom_text
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|keymap
operator|->
name|group_names
index|[
name|idx
index|]
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the index for a named layout.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_layout_index_t
DECL|function|xkb_keymap_layout_get_index
name|xkb_keymap_layout_get_index
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|xkb_atom_t
name|atom
init|=
name|xkb_atom_lookup
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|name
argument_list|)
decl_stmt|;
name|xkb_layout_index_t
name|i
decl_stmt|;
if|if
condition|(
name|atom
operator|==
name|XKB_ATOM_NONE
condition|)
return|return
name|XKB_LAYOUT_INVALID
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|keymap
operator|->
name|num_group_names
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|keymap
operator|->
name|group_names
index|[
name|i
index|]
operator|==
name|atom
condition|)
return|return
name|i
return|;
return|return
name|XKB_LAYOUT_INVALID
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the number of layouts active for a particular key.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_layout_index_t
DECL|function|xkb_keymap_num_layouts_for_key
name|xkb_keymap_num_layouts_for_key
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_keycode_t
name|kc
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_key
modifier|*
name|key
init|=
name|XkbKey
argument_list|(
name|keymap
argument_list|,
name|kc
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|key
condition|)
return|return
literal|0
return|;
return|return
name|key
operator|->
name|num_groups
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the number of levels active for a particular key and layout.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_level_index_t
DECL|function|xkb_keymap_num_levels_for_key
name|xkb_keymap_num_levels_for_key
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_keycode_t
name|kc
parameter_list|,
name|xkb_layout_index_t
name|layout
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_key
modifier|*
name|key
init|=
name|XkbKey
argument_list|(
name|keymap
argument_list|,
name|kc
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|key
condition|)
return|return
literal|0
return|;
name|layout
operator|=
name|wrap_group_into_range
argument_list|(
name|layout
argument_list|,
name|key
operator|->
name|num_groups
argument_list|,
name|key
operator|->
name|out_of_range_group_action
argument_list|,
name|key
operator|->
name|out_of_range_group_number
argument_list|)
expr_stmt|;
if|if
condition|(
name|layout
operator|==
name|XKB_LAYOUT_INVALID
condition|)
return|return
literal|0
return|;
return|return
name|XkbKeyGroupWidth
argument_list|(
name|key
argument_list|,
name|layout
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Return the total number of LEDs in the keymap.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_led_index_t
DECL|function|xkb_keymap_num_leds
name|xkb_keymap_num_leds
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|)
block|{
return|return
name|darray_size
argument_list|(
name|keymap
operator|->
name|leds
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the name for a given LED.  */
end_comment
begin_function
name|XKB_EXPORT
specifier|const
name|char
modifier|*
DECL|function|xkb_keymap_led_get_name
name|xkb_keymap_led_get_name
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_led_index_t
name|idx
parameter_list|)
block|{
if|if
condition|(
name|idx
operator|>=
name|darray_size
argument_list|(
name|keymap
operator|->
name|leds
argument_list|)
condition|)
return|return
name|NULL
return|;
return|return
name|xkb_atom_text
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|darray_item
argument_list|(
name|keymap
operator|->
name|leds
argument_list|,
name|idx
argument_list|)
operator|.
name|name
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/**  * Returns the index for a named LED.  */
end_comment
begin_function
name|XKB_EXPORT
name|xkb_led_index_t
DECL|function|xkb_keymap_led_get_index
name|xkb_keymap_led_get_index
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
name|xkb_atom_t
name|atom
init|=
name|xkb_atom_lookup
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|name
argument_list|)
decl_stmt|;
name|xkb_led_index_t
name|i
decl_stmt|;
specifier|const
name|struct
name|xkb_led
modifier|*
name|led
decl_stmt|;
if|if
condition|(
name|atom
operator|==
name|XKB_ATOM_NONE
condition|)
return|return
name|XKB_LED_INVALID
return|;
name|darray_enumerate
argument_list|(
argument|i
argument_list|,
argument|led
argument_list|,
argument|keymap->leds
argument_list|)
if|if
condition|(
name|led
operator|->
name|name
operator|==
name|atom
condition|)
return|return
name|i
return|;
return|return
name|XKB_LED_INVALID
return|;
block|}
end_function
begin_comment
comment|/**  * As below, but takes an explicit layout/level rather than state.  */
end_comment
begin_function
name|XKB_EXPORT
name|int
DECL|function|xkb_keymap_key_get_syms_by_level
name|xkb_keymap_key_get_syms_by_level
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_keycode_t
name|kc
parameter_list|,
name|xkb_layout_index_t
name|layout
parameter_list|,
name|xkb_level_index_t
name|level
parameter_list|,
specifier|const
name|xkb_keysym_t
modifier|*
modifier|*
name|syms_out
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_key
modifier|*
name|key
init|=
name|XkbKey
argument_list|(
name|keymap
argument_list|,
name|kc
argument_list|)
decl_stmt|;
name|int
name|num_syms
decl_stmt|;
if|if
condition|(
operator|!
name|key
condition|)
goto|goto
name|err
goto|;
name|layout
operator|=
name|wrap_group_into_range
argument_list|(
name|layout
argument_list|,
name|key
operator|->
name|num_groups
argument_list|,
name|key
operator|->
name|out_of_range_group_action
argument_list|,
name|key
operator|->
name|out_of_range_group_number
argument_list|)
expr_stmt|;
if|if
condition|(
name|layout
operator|==
name|XKB_LAYOUT_INVALID
condition|)
goto|goto
name|err
goto|;
if|if
condition|(
name|level
operator|>=
name|XkbKeyGroupWidth
argument_list|(
name|key
argument_list|,
name|layout
argument_list|)
condition|)
goto|goto
name|err
goto|;
name|num_syms
operator|=
name|key
operator|->
name|groups
index|[
name|layout
index|]
operator|.
name|levels
index|[
name|level
index|]
operator|.
name|num_syms
expr_stmt|;
if|if
condition|(
name|num_syms
operator|==
literal|0
condition|)
goto|goto
name|err
goto|;
if|if
condition|(
name|num_syms
operator|==
literal|1
condition|)
operator|*
name|syms_out
operator|=
operator|&
name|key
operator|->
name|groups
index|[
name|layout
index|]
operator|.
name|levels
index|[
name|level
index|]
operator|.
name|u
operator|.
name|sym
expr_stmt|;
else|else
operator|*
name|syms_out
operator|=
name|key
operator|->
name|groups
index|[
name|layout
index|]
operator|.
name|levels
index|[
name|level
index|]
operator|.
name|u
operator|.
name|syms
expr_stmt|;
return|return
name|num_syms
return|;
name|err
label|:
operator|*
name|syms_out
operator|=
name|NULL
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/**  * Simple boolean specifying whether or not the key should repeat.  */
end_comment
begin_function
name|XKB_EXPORT
name|int
DECL|function|xkb_keymap_key_repeats
name|xkb_keymap_key_repeats
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_keycode_t
name|kc
parameter_list|)
block|{
specifier|const
name|struct
name|xkb_key
modifier|*
name|key
init|=
name|XkbKey
argument_list|(
name|keymap
argument_list|,
name|kc
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|key
condition|)
return|return
literal|0
return|;
return|return
name|key
operator|->
name|repeats
return|;
block|}
end_function
begin_function
name|struct
name|xkb_key
modifier|*
DECL|function|XkbKeyByName
name|XkbKeyByName
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_atom_t
name|name
parameter_list|,
name|bool
name|use_aliases
parameter_list|)
block|{
name|struct
name|xkb_key
modifier|*
name|key
decl_stmt|;
name|xkb_foreach_key
argument_list|(
argument|key
argument_list|,
argument|keymap
argument_list|)
if|if
condition|(
name|key
operator|->
name|name
operator|==
name|name
condition|)
return|return
name|key
return|;
if|if
condition|(
name|use_aliases
condition|)
block|{
name|xkb_atom_t
name|new_name
init|=
name|XkbResolveKeyAlias
argument_list|(
name|keymap
argument_list|,
name|name
argument_list|)
decl_stmt|;
if|if
condition|(
name|new_name
operator|!=
name|XKB_ATOM_NONE
condition|)
return|return
name|XkbKeyByName
argument_list|(
name|keymap
argument_list|,
name|new_name
argument_list|,
name|false
argument_list|)
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function
begin_function
name|xkb_atom_t
DECL|function|XkbResolveKeyAlias
name|XkbResolveKeyAlias
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|xkb_atom_t
name|name
parameter_list|)
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|<
name|keymap
operator|->
name|num_key_aliases
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|keymap
operator|->
name|key_aliases
index|[
name|i
index|]
operator|.
name|alias
operator|==
name|name
condition|)
return|return
name|keymap
operator|->
name|key_aliases
index|[
name|i
index|]
operator|.
name|real
return|;
return|return
name|XKB_ATOM_NONE
return|;
block|}
end_function
end_unit
