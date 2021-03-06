begin_unit
begin_comment
comment|/*  * Copyright Â© 1998-2004  David Turner and Werner Lemberg  * Copyright Â© 2004,2007,2009  Red Hat, Inc.  * Copyright Â© 2011,2012  Google, Inc.  *  *  This is part of HarfBuzz, a text shaping library.  *  * Permission is hereby granted, without written agreement and without  * license or royalty fees, to use, copy, modify, and distribute this  * software and its documentation for any purpose, provided that the  * above copyright notice and the following two paragraphs appear in  * all copies of this software.  *  * IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE TO ANY PARTY FOR  * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES  * ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN  * IF THE COPYRIGHT HOLDER HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH  * DAMAGE.  *  * THE COPYRIGHT HOLDER SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING,  * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  * FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS  * ON AN "AS IS" BASIS, AND THE COPYRIGHT HOLDER HAS NO OBLIGATION TO  * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.  *  * Red Hat Author(s): Owen Taylor, Behdad Esfahbod  * Google Author(s): Behdad Esfahbod  */
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
name|HB_BUFFER_H
end_ifndef
begin_define
DECL|macro|HB_BUFFER_H
define|#
directive|define
name|HB_BUFFER_H
end_define
begin_include
include|#
directive|include
file|"hb-common.h"
end_include
begin_include
include|#
directive|include
file|"hb-unicode.h"
end_include
begin_include
include|#
directive|include
file|"hb-font.h"
end_include
begin_macro
name|HB_BEGIN_DECLS
end_macro
begin_typedef
DECL|struct|hb_glyph_info_t
typedef|typedef
struct|struct
name|hb_glyph_info_t
block|{
DECL|member|codepoint
name|hb_codepoint_t
name|codepoint
decl_stmt|;
DECL|member|mask
name|hb_mask_t
name|mask
decl_stmt|;
DECL|member|cluster
name|uint32_t
name|cluster
decl_stmt|;
comment|/*< private>*/
DECL|member|var1
name|hb_var_int_t
name|var1
decl_stmt|;
DECL|member|var2
name|hb_var_int_t
name|var2
decl_stmt|;
block|}
DECL|typedef|hb_glyph_info_t
name|hb_glyph_info_t
typedef|;
end_typedef
begin_typedef
DECL|struct|hb_glyph_position_t
typedef|typedef
struct|struct
name|hb_glyph_position_t
block|{
DECL|member|x_advance
name|hb_position_t
name|x_advance
decl_stmt|;
DECL|member|y_advance
name|hb_position_t
name|y_advance
decl_stmt|;
DECL|member|x_offset
name|hb_position_t
name|x_offset
decl_stmt|;
DECL|member|y_offset
name|hb_position_t
name|y_offset
decl_stmt|;
comment|/*< private>*/
DECL|member|var
name|hb_var_int_t
name|var
decl_stmt|;
block|}
DECL|typedef|hb_glyph_position_t
name|hb_glyph_position_t
typedef|;
end_typedef
begin_typedef
DECL|struct|hb_segment_properties_t
typedef|typedef
struct|struct
name|hb_segment_properties_t
block|{
DECL|member|direction
name|hb_direction_t
name|direction
decl_stmt|;
DECL|member|script
name|hb_script_t
name|script
decl_stmt|;
DECL|member|language
name|hb_language_t
name|language
decl_stmt|;
comment|/*< private>*/
DECL|member|reserved1
name|void
modifier|*
name|reserved1
decl_stmt|;
DECL|member|reserved2
name|void
modifier|*
name|reserved2
decl_stmt|;
block|}
DECL|typedef|hb_segment_properties_t
name|hb_segment_properties_t
typedef|;
end_typedef
begin_define
DECL|macro|HB_SEGMENT_PROPERTIES_DEFAULT
define|#
directive|define
name|HB_SEGMENT_PROPERTIES_DEFAULT
value|{HB_DIRECTION_INVALID, \ 				       HB_SCRIPT_INVALID, \ 				       HB_LANGUAGE_INVALID, \ 				       NULL, \ 				       NULL}
end_define
begin_function_decl
name|hb_bool_t
name|hb_segment_properties_equal
parameter_list|(
specifier|const
name|hb_segment_properties_t
modifier|*
name|a
parameter_list|,
specifier|const
name|hb_segment_properties_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|hb_segment_properties_hash
parameter_list|(
specifier|const
name|hb_segment_properties_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * hb_buffer_t  */
end_comment
begin_typedef
DECL|typedef|hb_buffer_t
typedef|typedef
name|struct
name|hb_buffer_t
name|hb_buffer_t
typedef|;
end_typedef
begin_function_decl
name|hb_buffer_t
modifier|*
name|hb_buffer_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_buffer_t
modifier|*
name|hb_buffer_get_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_buffer_t
modifier|*
name|hb_buffer_reference
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_destroy
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_buffer_set_user_data
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
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
name|hb_buffer_get_user_data
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_user_data_key_t
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_BUFFER_CONTENT_TYPE_INVALID
name|HB_BUFFER_CONTENT_TYPE_INVALID
init|=
literal|0
block|,
DECL|enumerator|HB_BUFFER_CONTENT_TYPE_UNICODE
name|HB_BUFFER_CONTENT_TYPE_UNICODE
block|,
DECL|enumerator|HB_BUFFER_CONTENT_TYPE_GLYPHS
name|HB_BUFFER_CONTENT_TYPE_GLYPHS
block|}
DECL|typedef|hb_buffer_content_type_t
name|hb_buffer_content_type_t
typedef|;
end_typedef
begin_function_decl
name|void
name|hb_buffer_set_content_type
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_buffer_content_type_t
name|content_type
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_buffer_content_type_t
name|hb_buffer_get_content_type
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_set_unicode_funcs
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_unicode_funcs_t
modifier|*
name|unicode_funcs
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_unicode_funcs_t
modifier|*
name|hb_buffer_get_unicode_funcs
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_set_direction
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_direction_t
name|direction
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_direction_t
name|hb_buffer_get_direction
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_set_script
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_script_t
name|script
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_script_t
name|hb_buffer_get_script
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_set_language
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_language_t
name|language
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_language_t
name|hb_buffer_get_language
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_set_segment_properties
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|hb_segment_properties_t
modifier|*
name|props
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_get_segment_properties
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_segment_properties_t
modifier|*
name|props
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_guess_segment_properties
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * Since: 0.9.20  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
comment|/*< flags>*/
DECL|enumerator|HB_BUFFER_FLAG_DEFAULT
name|HB_BUFFER_FLAG_DEFAULT
init|=
literal|0x00000000u
block|,
DECL|enumerator|HB_BUFFER_FLAG_BOT
name|HB_BUFFER_FLAG_BOT
init|=
literal|0x00000001u
block|,
comment|/* Beginning-of-text */
DECL|enumerator|HB_BUFFER_FLAG_EOT
name|HB_BUFFER_FLAG_EOT
init|=
literal|0x00000002u
block|,
comment|/* End-of-text */
DECL|enumerator|HB_BUFFER_FLAG_PRESERVE_DEFAULT_IGNORABLES
name|HB_BUFFER_FLAG_PRESERVE_DEFAULT_IGNORABLES
init|=
literal|0x00000004u
block|}
DECL|typedef|hb_buffer_flags_t
name|hb_buffer_flags_t
typedef|;
end_typedef
begin_function_decl
name|void
name|hb_buffer_set_flags
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_buffer_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_buffer_flags_t
name|hb_buffer_get_flags
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * Since: 0.9.42  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES
name|HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES
init|=
literal|0
block|,
DECL|enumerator|HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS
name|HB_BUFFER_CLUSTER_LEVEL_MONOTONE_CHARACTERS
init|=
literal|1
block|,
DECL|enumerator|HB_BUFFER_CLUSTER_LEVEL_CHARACTERS
name|HB_BUFFER_CLUSTER_LEVEL_CHARACTERS
init|=
literal|2
block|,
DECL|enumerator|HB_BUFFER_CLUSTER_LEVEL_DEFAULT
name|HB_BUFFER_CLUSTER_LEVEL_DEFAULT
init|=
name|HB_BUFFER_CLUSTER_LEVEL_MONOTONE_GRAPHEMES
block|}
DECL|typedef|hb_buffer_cluster_level_t
name|hb_buffer_cluster_level_t
typedef|;
end_typedef
begin_function_decl
name|void
name|hb_buffer_set_cluster_level
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_buffer_cluster_level_t
name|cluster_level
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_buffer_cluster_level_t
name|hb_buffer_get_cluster_level
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|HB_BUFFER_REPLACEMENT_CODEPOINT_DEFAULT
define|#
directive|define
name|HB_BUFFER_REPLACEMENT_CODEPOINT_DEFAULT
value|0xFFFDu
end_define
begin_comment
comment|/* Sets codepoint used to replace invalid UTF-8/16/32 entries.  * Default is 0xFFFDu. */
end_comment
begin_function_decl
name|void
name|hb_buffer_set_replacement_codepoint
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_codepoint_t
name|replacement
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_codepoint_t
name|hb_buffer_get_replacement_codepoint
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Resets the buffer.  Afterwards it's as if it was just created,  * except that it has a larger buffer allocated perhaps... */
end_comment
begin_function_decl
name|void
name|hb_buffer_reset
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Like reset, but does NOT clear unicode_funcs and replacement_codepoint. */
end_comment
begin_function_decl
name|void
name|hb_buffer_clear_contents
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Returns false if allocation failed */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_buffer_pre_allocate
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Returns false if allocation has failed before */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_buffer_allocation_successful
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_reverse
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_reverse_range
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|start
parameter_list|,
name|unsigned
name|int
name|end
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_reverse_clusters
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Filling the buffer in */
end_comment
begin_function_decl
name|void
name|hb_buffer_add
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|hb_codepoint_t
name|codepoint
parameter_list|,
name|unsigned
name|int
name|cluster
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_add_utf8
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|,
name|int
name|text_length
parameter_list|,
name|unsigned
name|int
name|item_offset
parameter_list|,
name|int
name|item_length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_add_utf16
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|text
parameter_list|,
name|int
name|text_length
parameter_list|,
name|unsigned
name|int
name|item_offset
parameter_list|,
name|int
name|item_length
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|hb_buffer_add_utf32
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|text
parameter_list|,
name|int
name|text_length
parameter_list|,
name|unsigned
name|int
name|item_offset
parameter_list|,
name|int
name|item_length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Allows only access to first 256 Unicode codepoints. */
end_comment
begin_function_decl
name|void
name|hb_buffer_add_latin1
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|text
parameter_list|,
name|int
name|text_length
parameter_list|,
name|unsigned
name|int
name|item_offset
parameter_list|,
name|int
name|item_length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Like add_utf32 but does NOT check for invalid Unicode codepoints. */
end_comment
begin_function_decl
name|void
name|hb_buffer_add_codepoints
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|hb_codepoint_t
modifier|*
name|text
parameter_list|,
name|int
name|text_length
parameter_list|,
name|unsigned
name|int
name|item_offset
parameter_list|,
name|int
name|item_length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Clears any new items added at the end */
end_comment
begin_function_decl
name|hb_bool_t
name|hb_buffer_set_length
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Return value valid as long as buffer not modified */
end_comment
begin_function_decl
name|unsigned
name|int
name|hb_buffer_get_length
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Getting glyphs out of the buffer */
end_comment
begin_comment
comment|/* Return value valid as long as buffer not modified */
end_comment
begin_function_decl
name|hb_glyph_info_t
modifier|*
name|hb_buffer_get_glyph_infos
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Return value valid as long as buffer not modified */
end_comment
begin_function_decl
name|hb_glyph_position_t
modifier|*
name|hb_buffer_get_glyph_positions
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
modifier|*
name|length
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Reorders a glyph buffer to have canonical in-cluster glyph order / position.  * The resulting clusters should behave identical to pre-reordering clusters.  * NOTE: This has nothing to do with Unicode normalization. */
end_comment
begin_function_decl
name|void
name|hb_buffer_normalize_glyphs
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*  * Serialize  */
end_comment
begin_comment
comment|/*  * Since: 0.9.20  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
comment|/*< flags>*/
DECL|enumerator|HB_BUFFER_SERIALIZE_FLAG_DEFAULT
name|HB_BUFFER_SERIALIZE_FLAG_DEFAULT
init|=
literal|0x00000000u
block|,
DECL|enumerator|HB_BUFFER_SERIALIZE_FLAG_NO_CLUSTERS
name|HB_BUFFER_SERIALIZE_FLAG_NO_CLUSTERS
init|=
literal|0x00000001u
block|,
DECL|enumerator|HB_BUFFER_SERIALIZE_FLAG_NO_POSITIONS
name|HB_BUFFER_SERIALIZE_FLAG_NO_POSITIONS
init|=
literal|0x00000002u
block|,
DECL|enumerator|HB_BUFFER_SERIALIZE_FLAG_NO_GLYPH_NAMES
name|HB_BUFFER_SERIALIZE_FLAG_NO_GLYPH_NAMES
init|=
literal|0x00000004u
block|,
DECL|enumerator|HB_BUFFER_SERIALIZE_FLAG_GLYPH_EXTENTS
name|HB_BUFFER_SERIALIZE_FLAG_GLYPH_EXTENTS
init|=
literal|0x00000008u
block|}
DECL|typedef|hb_buffer_serialize_flags_t
name|hb_buffer_serialize_flags_t
typedef|;
end_typedef
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|HB_BUFFER_SERIALIZE_FORMAT_TEXT
name|HB_BUFFER_SERIALIZE_FORMAT_TEXT
init|=
name|HB_TAG
argument_list|(
literal|'T'
argument_list|,
literal|'E'
argument_list|,
literal|'X'
argument_list|,
literal|'T'
argument_list|)
block|,
DECL|enumerator|HB_BUFFER_SERIALIZE_FORMAT_JSON
name|HB_BUFFER_SERIALIZE_FORMAT_JSON
init|=
name|HB_TAG
argument_list|(
literal|'J'
argument_list|,
literal|'S'
argument_list|,
literal|'O'
argument_list|,
literal|'N'
argument_list|)
block|,
DECL|enumerator|HB_BUFFER_SERIALIZE_FORMAT_INVALID
name|HB_BUFFER_SERIALIZE_FORMAT_INVALID
init|=
name|HB_TAG_NONE
block|}
DECL|typedef|hb_buffer_serialize_format_t
name|hb_buffer_serialize_format_t
typedef|;
end_typedef
begin_comment
comment|/* len=-1 means str is NUL-terminated. */
end_comment
begin_function_decl
name|hb_buffer_serialize_format_t
name|hb_buffer_serialize_format_from_string
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
name|hb_buffer_serialize_format_to_string
parameter_list|(
name|hb_buffer_serialize_format_t
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|const
name|char
modifier|*
modifier|*
name|hb_buffer_serialize_list_formats
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* Returns number of items, starting at start, that were serialized. */
end_comment
begin_function_decl
name|unsigned
name|int
name|hb_buffer_serialize_glyphs
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|start
parameter_list|,
name|unsigned
name|int
name|end
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|unsigned
name|int
name|buf_size
parameter_list|,
name|unsigned
name|int
modifier|*
name|buf_consumed
parameter_list|,
comment|/* May be NULL */
name|hb_font_t
modifier|*
name|font
parameter_list|,
comment|/* May be NULL */
name|hb_buffer_serialize_format_t
name|format
parameter_list|,
name|hb_buffer_serialize_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|hb_bool_t
name|hb_buffer_deserialize_glyphs
parameter_list|(
name|hb_buffer_t
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|buf_len
parameter_list|,
comment|/* -1 means nul-terminated */
specifier|const
name|char
modifier|*
modifier|*
name|end_ptr
parameter_list|,
comment|/* May be NULL */
name|hb_font_t
modifier|*
name|font
parameter_list|,
comment|/* May be NULL */
name|hb_buffer_serialize_format_t
name|format
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
comment|/* HB_BUFFER_H */
end_comment
end_unit
