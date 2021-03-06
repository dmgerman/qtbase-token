begin_unit
begin_comment
comment|/*  * Copyright Â© 2009  Red Hat, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Behdad Esfahbod  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HB_H_IN
end_ifndef
begin_error
error|#
directive|error
literal|"Include<hb.h> instead."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|HB_BLOB_H
end_ifndef
begin_define
DECL|macro|HB_BLOB_H
define|#
directive|define
name|HB_BLOB_H
end_define
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_macro
name|HB_BEGIN_DECLS
end_macro
begin_comment
comment|/*  * Note re various memory-modes:  *  * - In no case shall the HarfBuzz client modify memory  *   that is passed to HarfBuzz in a blob.  If there is  *   any such possibility, MODE_DUPLICATE should be used  *   such that HarfBuzz makes a copy immediately,  *  * - Use MODE_READONLY otherse, unless you really really  *   really know what you are doing,  *  * - MODE_WRITABLE is appropriate if you really made a  *   copy of data solely for the purpose of passing to  *   HarfBuzz and doing that just once (no reuse!),  *  * - If the font is mmap()ed, it's ok to use  *   READONLY_MAY_MAKE_WRITABLE, however, using that mode  *   correctly is very tricky.  Use MODE_READONLY instead.  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_MEMORY_MODE_DUPLICATE
name|HB_MEMORY_MODE_DUPLICATE
block|,
DECL|enumerator|HB_MEMORY_MODE_READONLY
name|HB_MEMORY_MODE_READONLY
block|,
DECL|enumerator|HB_MEMORY_MODE_WRITABLE
name|HB_MEMORY_MODE_WRITABLE
block|,
DECL|enumerator|HB_MEMORY_MODE_READONLY_MAY_MAKE_WRITABLE
name|HB_MEMORY_MODE_READONLY_MAY_MAKE_WRITABLE
block|}
DECL|typedef|hb_memory_mode_t
name|hb_memory_mode_t
typedef|;
end_typedef
begin_typedef
DECL|typedef|hb_blob_t
typedef|typedef
name|struct
name|hb_blob_t
name|hb_blob_t
typedef|;
end_typedef
begin_function_decl
name|hb_blob_t
modifier|*
name|hb_blob_create
parameter_list|(
specifier|const
name|char
modifier|*
name|data
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|,
name|hb_memory_mode_t
name|mode
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Always creates with MEMORY_MODE_READONLY.  * Even if the parent blob is writable, we don't  * want the user of the sub-blob to be able to  * modify the parent data as that data may be  * shared among multiple sub-blobs.  */
end_comment
begin_function_decl
name|hb_blob_t
modifier|*
name|hb_blob_create_sub_blob
parameter_list|(
name|hb_blob_t
modifier|*
name|parent
parameter_list|,
name|unsigned
name|int
name|offset
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_blob_t
modifier|*
name|hb_blob_get_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_blob_t
modifier|*
name|hb_blob_reference
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_blob_destroy
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_blob_set_user_data
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|hb_destroy_func_t
name|destroy
parameter_list|,
name|hb_bool_t
name|replace
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
modifier|*
name|hb_blob_get_user_data
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_blob_make_immutable
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_blob_is_immutable
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_blob_get_length
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|hb_blob_get_data
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|,
name|unsigned
name|int
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|char
modifier|*
name|hb_blob_get_data_writable
parameter_list|(
name|hb_blob_t
modifier|*
name|blob
parameter_list|,
name|unsigned
name|int
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|HB_END_DECLS
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* HB_BLOB_H */
end_comment
end_unit
