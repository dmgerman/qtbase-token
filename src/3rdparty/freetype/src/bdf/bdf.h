begin_unit
begin_comment
comment|/*  * Copyright 2000 Computing Research Labs, New Mexico State University  * Copyright 2001-2004, 2011 Francesco Zappa Nardelli  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COMPUTING RESEARCH LAB OR NEW MEXICO STATE UNIVERSITY BE LIABLE FOR ANY  * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT  * OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__BDF_H__
end_ifndef
begin_define
DECL|macro|__BDF_H__
define|#
directive|define
name|__BDF_H__
end_define
begin_comment
comment|/*  * Based on bdf.h,v 1.16 2000/03/16 20:08:51 mleisher  */
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* Imported from bdfP.h */
end_comment
begin_define
DECL|macro|_bdf_glyph_modified
define|#
directive|define
name|_bdf_glyph_modified
parameter_list|(
name|map
parameter_list|,
name|e
parameter_list|)
define|\
value|( (map)[(e)>> 5]& ( 1UL<< ( (e)& 31 ) ) )
end_define
begin_define
DECL|macro|_bdf_set_glyph_modified
define|#
directive|define
name|_bdf_set_glyph_modified
parameter_list|(
name|map
parameter_list|,
name|e
parameter_list|)
define|\
value|( (map)[(e)>> 5] |= ( 1UL<< ( (e)& 31 ) ) )
end_define
begin_define
DECL|macro|_bdf_clear_glyph_modified
define|#
directive|define
name|_bdf_clear_glyph_modified
parameter_list|(
name|map
parameter_list|,
name|e
parameter_list|)
define|\
value|( (map)[(e)>> 5]&= ~( 1UL<< ( (e)& 31 ) ) )
end_define
begin_comment
comment|/* end of bdfP.h */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* BDF font options macros and types.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|BDF_CORRECT_METRICS
define|#
directive|define
name|BDF_CORRECT_METRICS
value|0x01
end_define
begin_comment
DECL|macro|BDF_CORRECT_METRICS
comment|/* Correct invalid metrics when loading. */
end_comment
begin_define
DECL|macro|BDF_KEEP_COMMENTS
define|#
directive|define
name|BDF_KEEP_COMMENTS
value|0x02
end_define
begin_comment
DECL|macro|BDF_KEEP_COMMENTS
comment|/* Preserve the font comments.           */
end_comment
begin_define
DECL|macro|BDF_KEEP_UNENCODED
define|#
directive|define
name|BDF_KEEP_UNENCODED
value|0x04
end_define
begin_comment
DECL|macro|BDF_KEEP_UNENCODED
comment|/* Keep the unencoded glyphs.            */
end_comment
begin_define
DECL|macro|BDF_PROPORTIONAL
define|#
directive|define
name|BDF_PROPORTIONAL
value|0x08
end_define
begin_comment
DECL|macro|BDF_PROPORTIONAL
comment|/* Font has proportional spacing.        */
end_comment
begin_define
DECL|macro|BDF_MONOWIDTH
define|#
directive|define
name|BDF_MONOWIDTH
value|0x10
end_define
begin_comment
DECL|macro|BDF_MONOWIDTH
comment|/* Font has mono width.                  */
end_comment
begin_define
DECL|macro|BDF_CHARCELL
define|#
directive|define
name|BDF_CHARCELL
value|0x20
end_define
begin_comment
DECL|macro|BDF_CHARCELL
comment|/* Font has charcell spacing.            */
end_comment
begin_define
DECL|macro|BDF_ALL_SPACING
define|#
directive|define
name|BDF_ALL_SPACING
value|( BDF_PROPORTIONAL | \                            BDF_MONOWIDTH    | \                            BDF_CHARCELL     )
end_define
begin_define
DECL|macro|BDF_DEFAULT_LOAD_OPTIONS
define|#
directive|define
name|BDF_DEFAULT_LOAD_OPTIONS
value|( BDF_CORRECT_METRICS | \                                     BDF_KEEP_COMMENTS   | \                                     BDF_KEEP_UNENCODED  | \                                     BDF_PROPORTIONAL    )
end_define
begin_typedef
DECL|struct|bdf_options_t_
typedef|typedef
struct|struct
name|bdf_options_t_
block|{
DECL|member|correct_metrics
name|int
name|correct_metrics
decl_stmt|;
DECL|member|keep_unencoded
name|int
name|keep_unencoded
decl_stmt|;
DECL|member|keep_comments
name|int
name|keep_comments
decl_stmt|;
DECL|member|font_spacing
name|int
name|font_spacing
decl_stmt|;
block|}
DECL|typedef|bdf_options_t
name|bdf_options_t
typedef|;
end_typedef
begin_comment
comment|/* Callback function type for unknown configuration options. */
end_comment
begin_typedef
typedef|typedef
name|int
function_decl|(
DECL|typedef|bdf_options_callback_t
modifier|*
name|bdf_options_callback_t
function_decl|)
parameter_list|(
name|bdf_options_t
modifier|*
name|opts
parameter_list|,
name|char
modifier|*
modifier|*
name|params
parameter_list|,
name|unsigned
name|long
name|nparams
parameter_list|,
name|void
modifier|*
name|client_data
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* BDF font property macros and types.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|BDF_ATOM
define|#
directive|define
name|BDF_ATOM
value|1
end_define
begin_define
DECL|macro|BDF_INTEGER
define|#
directive|define
name|BDF_INTEGER
value|2
end_define
begin_define
DECL|macro|BDF_CARDINAL
define|#
directive|define
name|BDF_CARDINAL
value|3
end_define
begin_comment
comment|/* This structure represents a particular property of a font. */
end_comment
begin_comment
comment|/* There are a set of defaults and each font has their own.   */
end_comment
begin_typedef
DECL|struct|bdf_property_t_
typedef|typedef
struct|struct
name|bdf_property_t_
block|{
DECL|member|name
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the property.   */
DECL|member|format
name|int
name|format
decl_stmt|;
comment|/* Format of the property. */
DECL|member|builtin
name|int
name|builtin
decl_stmt|;
comment|/* A builtin property.     */
union|union
block|{
DECL|member|atom
name|char
modifier|*
name|atom
decl_stmt|;
DECL|member|l
name|long
name|l
decl_stmt|;
DECL|member|ul
name|unsigned
name|long
name|ul
decl_stmt|;
block|}
DECL|member|value
name|value
union|;
comment|/* Value of the property.  */
block|}
DECL|typedef|bdf_property_t
name|bdf_property_t
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* BDF font metric and glyph types.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_typedef
DECL|struct|bdf_bbx_t_
typedef|typedef
struct|struct
name|bdf_bbx_t_
block|{
DECL|member|width
name|unsigned
name|short
name|width
decl_stmt|;
DECL|member|height
name|unsigned
name|short
name|height
decl_stmt|;
DECL|member|x_offset
name|short
name|x_offset
decl_stmt|;
DECL|member|y_offset
name|short
name|y_offset
decl_stmt|;
DECL|member|ascent
name|short
name|ascent
decl_stmt|;
DECL|member|descent
name|short
name|descent
decl_stmt|;
block|}
DECL|typedef|bdf_bbx_t
name|bdf_bbx_t
typedef|;
end_typedef
begin_typedef
DECL|struct|bdf_glyph_t_
typedef|typedef
struct|struct
name|bdf_glyph_t_
block|{
DECL|member|name
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Glyph name.                          */
DECL|member|encoding
name|long
name|encoding
decl_stmt|;
comment|/* Glyph encoding.                      */
DECL|member|swidth
name|unsigned
name|short
name|swidth
decl_stmt|;
comment|/* Scalable width.                      */
DECL|member|dwidth
name|unsigned
name|short
name|dwidth
decl_stmt|;
comment|/* Device width.                        */
DECL|member|bbx
name|bdf_bbx_t
name|bbx
decl_stmt|;
comment|/* Glyph bounding box.                  */
DECL|member|bitmap
name|unsigned
name|char
modifier|*
name|bitmap
decl_stmt|;
comment|/* Glyph bitmap.                        */
DECL|member|bpr
name|unsigned
name|long
name|bpr
decl_stmt|;
comment|/* Number of bytes used per row.        */
DECL|member|bytes
name|unsigned
name|short
name|bytes
decl_stmt|;
comment|/* Number of bytes used for the bitmap. */
block|}
DECL|typedef|bdf_glyph_t
name|bdf_glyph_t
typedef|;
end_typedef
begin_typedef
DECL|struct|_hashnode_
typedef|typedef
struct|struct
name|_hashnode_
block|{
DECL|member|key
specifier|const
name|char
modifier|*
name|key
decl_stmt|;
DECL|member|data
name|size_t
name|data
decl_stmt|;
block|}
DECL|typedef|_hashnode
DECL|typedef|hashnode
name|_hashnode
operator|,
typedef|*
name|hashnode
typedef|;
end_typedef
begin_typedef
DECL|struct|hashtable_
typedef|typedef
struct|struct
name|hashtable_
block|{
DECL|member|limit
name|unsigned
name|int
name|limit
decl_stmt|;
DECL|member|size
name|unsigned
name|int
name|size
decl_stmt|;
DECL|member|used
name|unsigned
name|int
name|used
decl_stmt|;
DECL|member|table
name|hashnode
modifier|*
name|table
decl_stmt|;
block|}
DECL|typedef|hashtable
name|hashtable
typedef|;
end_typedef
begin_typedef
DECL|struct|bdf_glyphlist_t_
typedef|typedef
struct|struct
name|bdf_glyphlist_t_
block|{
DECL|member|pad
name|unsigned
name|short
name|pad
decl_stmt|;
comment|/* Pad to 4-byte boundary.              */
DECL|member|bpp
name|unsigned
name|short
name|bpp
decl_stmt|;
comment|/* Bits per pixel.                      */
DECL|member|start
name|long
name|start
decl_stmt|;
comment|/* Beginning encoding value of glyphs.  */
DECL|member|end
name|long
name|end
decl_stmt|;
comment|/* Ending encoding value of glyphs.     */
DECL|member|glyphs
name|bdf_glyph_t
modifier|*
name|glyphs
decl_stmt|;
comment|/* Glyphs themselves.                   */
DECL|member|glyphs_size
name|unsigned
name|long
name|glyphs_size
decl_stmt|;
comment|/* Glyph structures allocated.          */
DECL|member|glyphs_used
name|unsigned
name|long
name|glyphs_used
decl_stmt|;
comment|/* Glyph structures used.               */
DECL|member|bbx
name|bdf_bbx_t
name|bbx
decl_stmt|;
comment|/* Overall bounding box of glyphs.      */
block|}
DECL|typedef|bdf_glyphlist_t
name|bdf_glyphlist_t
typedef|;
end_typedef
begin_typedef
DECL|struct|bdf_font_t_
typedef|typedef
struct|struct
name|bdf_font_t_
block|{
DECL|member|name
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Name of the font.                   */
DECL|member|bbx
name|bdf_bbx_t
name|bbx
decl_stmt|;
comment|/* Font bounding box.                  */
DECL|member|point_size
name|unsigned
name|long
name|point_size
decl_stmt|;
comment|/* Point size of the font.             */
DECL|member|resolution_x
name|unsigned
name|long
name|resolution_x
decl_stmt|;
comment|/* Font horizontal resolution.         */
DECL|member|resolution_y
name|unsigned
name|long
name|resolution_y
decl_stmt|;
comment|/* Font vertical resolution.           */
DECL|member|spacing
name|int
name|spacing
decl_stmt|;
comment|/* Font spacing value.                 */
DECL|member|monowidth
name|unsigned
name|short
name|monowidth
decl_stmt|;
comment|/* Logical width for monowidth font.   */
DECL|member|default_char
name|long
name|default_char
decl_stmt|;
comment|/* Encoding of the default glyph.      */
DECL|member|font_ascent
name|long
name|font_ascent
decl_stmt|;
comment|/* Font ascent.                        */
DECL|member|font_descent
name|long
name|font_descent
decl_stmt|;
comment|/* Font descent.                       */
DECL|member|glyphs_size
name|unsigned
name|long
name|glyphs_size
decl_stmt|;
comment|/* Glyph structures allocated.         */
DECL|member|glyphs_used
name|unsigned
name|long
name|glyphs_used
decl_stmt|;
comment|/* Glyph structures used.              */
DECL|member|glyphs
name|bdf_glyph_t
modifier|*
name|glyphs
decl_stmt|;
comment|/* Glyphs themselves.                  */
DECL|member|unencoded_size
name|unsigned
name|long
name|unencoded_size
decl_stmt|;
comment|/* Unencoded glyph struct. allocated.  */
DECL|member|unencoded_used
name|unsigned
name|long
name|unencoded_used
decl_stmt|;
comment|/* Unencoded glyph struct. used.       */
DECL|member|unencoded
name|bdf_glyph_t
modifier|*
name|unencoded
decl_stmt|;
comment|/* Unencoded glyphs themselves.        */
DECL|member|props_size
name|unsigned
name|long
name|props_size
decl_stmt|;
comment|/* Font properties allocated.          */
DECL|member|props_used
name|unsigned
name|long
name|props_used
decl_stmt|;
comment|/* Font properties used.               */
DECL|member|props
name|bdf_property_t
modifier|*
name|props
decl_stmt|;
comment|/* Font properties themselves.         */
DECL|member|comments
name|char
modifier|*
name|comments
decl_stmt|;
comment|/* Font comments.                      */
DECL|member|comments_len
name|unsigned
name|long
name|comments_len
decl_stmt|;
comment|/* Length of comment string.           */
DECL|member|overflow
name|bdf_glyphlist_t
name|overflow
decl_stmt|;
comment|/* Storage used for glyph insertion.   */
DECL|member|internal
name|void
modifier|*
name|internal
decl_stmt|;
comment|/* Internal data for the font.         */
comment|/* The size of the next two arrays must be in sync with the */
comment|/* size of the `have' array in the `bdf_parse_t' structure. */
DECL|member|nmod
name|unsigned
name|long
name|nmod
index|[
literal|34816
index|]
decl_stmt|;
comment|/* Bitmap indicating modified glyphs.  */
DECL|member|umod
name|unsigned
name|long
name|umod
index|[
literal|34816
index|]
decl_stmt|;
comment|/* Bitmap indicating modified          */
comment|/* unencoded glyphs.                   */
DECL|member|modified
name|unsigned
name|short
name|modified
decl_stmt|;
comment|/* Boolean indicating font modified.   */
DECL|member|bpp
name|unsigned
name|short
name|bpp
decl_stmt|;
comment|/* Bits per pixel.                     */
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|user_props
name|bdf_property_t
modifier|*
name|user_props
decl_stmt|;
DECL|member|nuser_props
name|unsigned
name|long
name|nuser_props
decl_stmt|;
DECL|member|proptbl
name|hashtable
name|proptbl
decl_stmt|;
block|}
DECL|typedef|bdf_font_t
name|bdf_font_t
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Types for load/save callbacks.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* Error codes. */
end_comment
begin_define
DECL|macro|BDF_MISSING_START
define|#
directive|define
name|BDF_MISSING_START
value|-1
end_define
begin_define
DECL|macro|BDF_MISSING_FONTNAME
define|#
directive|define
name|BDF_MISSING_FONTNAME
value|-2
end_define
begin_define
DECL|macro|BDF_MISSING_SIZE
define|#
directive|define
name|BDF_MISSING_SIZE
value|-3
end_define
begin_define
DECL|macro|BDF_MISSING_CHARS
define|#
directive|define
name|BDF_MISSING_CHARS
value|-4
end_define
begin_define
DECL|macro|BDF_MISSING_STARTCHAR
define|#
directive|define
name|BDF_MISSING_STARTCHAR
value|-5
end_define
begin_define
DECL|macro|BDF_MISSING_ENCODING
define|#
directive|define
name|BDF_MISSING_ENCODING
value|-6
end_define
begin_define
DECL|macro|BDF_MISSING_BBX
define|#
directive|define
name|BDF_MISSING_BBX
value|-7
end_define
begin_define
DECL|macro|BDF_OUT_OF_MEMORY
define|#
directive|define
name|BDF_OUT_OF_MEMORY
value|-20
end_define
begin_define
DECL|macro|BDF_INVALID_LINE
define|#
directive|define
name|BDF_INVALID_LINE
value|-100
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* BDF font API.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|bdf_load_font
argument_list|(
argument|FT_Stream       stream
argument_list|,
argument|FT_Memory       memory
argument_list|,
argument|bdf_options_t*  opts
argument_list|,
argument|bdf_font_t*    *font
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
begin_expr_stmt
DECL|variable|bdf_free_font
name|bdf_free_font
argument_list|(
name|bdf_font_t
operator|*
name|font
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|bdf_property_t *
argument_list|)
end_macro
begin_expr_stmt
name|bdf_get_property
argument_list|(
name|char
operator|*
name|name
argument_list|,
name|bdf_font_t
operator|*
name|font
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|bdf_property_t *
argument_list|)
end_macro
begin_expr_stmt
name|bdf_get_font_property
argument_list|(
name|bdf_font_t
operator|*
name|font
argument_list|,
specifier|const
name|char
operator|*
name|name
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __BDF_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
