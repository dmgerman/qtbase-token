begin_unit
begin_comment
comment|/*  * Copyright Â© 2012  Google, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Google Author(s): Behdad Esfahbod  */
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
name|HB_SET_H
end_ifndef
begin_define
DECL|macro|HB_SET_H
define|#
directive|define
name|HB_SET_H
end_define
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_macro
name|HB_BEGIN_DECLS
end_macro
begin_typedef
DECL|typedef|hb_set_t
typedef|typedef
name|struct
name|hb_set_t
name|hb_set_t
typedef|;
end_typedef
begin_function_decl
name|hb_set_t
modifier|*
name|hb_set_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_set_t
modifier|*
name|hb_set_get_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_set_t
modifier|*
name|hb_set_reference
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_destroy
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_set_set_user_data
parameter_list|(
name|hb_set_t
modifier|*
name|set
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
name|hb_set_get_user_data
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Returns false if allocation has failed before */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_set_allocation_successful
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_clear
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_set_is_empty
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_set_has
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
name|codepoint
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Right now limited to 16-bit integers.  Eventually will do full codepoint range, sans -1  * which we will use as a sentinel. */
end_comment
begin_function_decl
name|void
name|hb_set_add
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
name|codepoint
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_add_range
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
name|first
parameter_list|,
name|hb_codepoint_t
name|last
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_del
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
name|codepoint
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_del_range
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
name|first
parameter_list|,
name|hb_codepoint_t
name|last
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_set_is_equal
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|,
specifier|const
name|hb_set_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_set
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
specifier|const
name|hb_set_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_union
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
specifier|const
name|hb_set_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_intersect
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
specifier|const
name|hb_set_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_subtract
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
specifier|const
name|hb_set_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_symmetric_difference
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|,
specifier|const
name|hb_set_t
modifier|*
name|other
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_set_invert
parameter_list|(
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_set_get_population
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Returns -1 if set empty. */
end_comment
begin_function_decl
name|hb_codepoint_t
name|hb_set_get_min
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Returns -1 if set empty. */
end_comment
begin_function_decl
name|hb_codepoint_t
name|hb_set_get_max
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Pass -1 in to get started. */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_set_next
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
modifier|*
name|codepoint
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Pass -1 for first and last to get started. */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_set_next_range
parameter_list|(
specifier|const
name|hb_set_t
modifier|*
name|set
parameter_list|,
name|hb_codepoint_t
modifier|*
name|first
parameter_list|,
name|hb_codepoint_t
modifier|*
name|last
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
comment|/* HB_SET_H */
end_comment
end_unit