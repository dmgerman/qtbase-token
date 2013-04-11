begin_unit
begin_comment
comment|/************************************************************  * Copyright (c) 1994 by Silicon Graphics Computer Systems, Inc.  *  * Permission to use, copy, modify, and distribute this  * software and its documentation for any purpose and without  * fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting  * documentation, and that the name of Silicon Graphics not be  * used in advertising or publicity pertaining to distribution  * of the software without specific prior written permission.  * Silicon Graphics makes no representation about the suitability  * of this software for any purpose. It is provided "as is"  * without any express or implied warranty.  *  * SILICON GRAPHICS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS  * SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL SILICON  * GRAPHICS BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL  * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION  WITH  * THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  ********************************************************/
end_comment
begin_include
include|#
directive|include
file|"xkbcomp-priv.h"
end_include
begin_include
include|#
directive|include
file|"text.h"
end_include
begin_include
include|#
directive|include
file|"expr.h"
end_include
begin_include
include|#
directive|include
file|"vmod.h"
end_include
begin_function
name|bool
DECL|function|HandleVModDef
name|HandleVModDef
parameter_list|(
name|struct
name|xkb_keymap
modifier|*
name|keymap
parameter_list|,
name|VModDef
modifier|*
name|stmt
parameter_list|)
block|{
name|xkb_mod_index_t
name|i
decl_stmt|;
specifier|const
name|struct
name|xkb_mod
modifier|*
name|mod
decl_stmt|;
name|struct
name|xkb_mod
name|new
decl_stmt|;
if|if
condition|(
name|stmt
operator|->
name|value
condition|)
name|log_err
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
literal|"Support for setting a value in a virtual_modifiers statement has been removed; "
literal|"Value ignored\n"
argument_list|)
expr_stmt|;
name|darray_enumerate
argument_list|(
argument|i
argument_list|,
argument|mod
argument_list|,
argument|keymap->mods
argument_list|)
block|{
if|if
condition|(
name|mod
operator|->
name|name
operator|==
name|stmt
operator|->
name|name
condition|)
block|{
if|if
condition|(
name|mod
operator|->
name|type
operator|==
name|MOD_VIRT
condition|)
return|return
name|true
return|;
name|log_err
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
literal|"Can't add a virtual modifier named \"%s\"; "
literal|"there is already a non-virtual modifier with this name! Ignored\n"
argument_list|,
name|xkb_atom_text
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
name|mod
operator|->
name|name
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
block|}
if|if
condition|(
name|darray_size
argument_list|(
name|keymap
operator|->
name|mods
argument_list|)
operator|>=
name|XKB_MAX_MODS
condition|)
block|{
name|log_err
argument_list|(
name|keymap
operator|->
name|ctx
argument_list|,
literal|"Too many modifiers defined (maximum %d)\n"
argument_list|,
name|XKB_MAX_MODS
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|new
operator|.
name|name
operator|=
name|stmt
operator|->
name|name
expr_stmt|;
name|new
operator|.
name|mapping
operator|=
literal|0
expr_stmt|;
name|new
operator|.
name|type
operator|=
name|MOD_VIRT
expr_stmt|;
name|darray_append
argument_list|(
name|keymap
operator|->
name|mods
argument_list|,
name|new
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function
end_unit
