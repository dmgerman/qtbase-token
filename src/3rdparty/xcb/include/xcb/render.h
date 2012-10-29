begin_unit
begin_comment
comment|/*  * This file generated automatically from render.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_Render_API XCB Render API  * @brief Render XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__RENDER_H
end_ifndef
begin_define
DECL|macro|__RENDER_H
define|#
directive|define
name|__RENDER_H
end_define
begin_include
include|#
directive|include
file|"xcb.h"
end_include
begin_include
include|#
directive|include
file|"xproto.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
DECL|macro|XCB_RENDER_MAJOR_VERSION
define|#
directive|define
name|XCB_RENDER_MAJOR_VERSION
value|0
DECL|macro|XCB_RENDER_MINOR_VERSION
define|#
directive|define
name|XCB_RENDER_MINOR_VERSION
value|10
specifier|extern
name|xcb_extension_t
name|xcb_render_id
decl_stmt|;
DECL|enum|xcb_render_pict_type_t
typedef|typedef
enum|enum
name|xcb_render_pict_type_t
block|{
DECL|enumerator|XCB_RENDER_PICT_TYPE_INDEXED
name|XCB_RENDER_PICT_TYPE_INDEXED
block|,
DECL|enumerator|XCB_RENDER_PICT_TYPE_DIRECT
name|XCB_RENDER_PICT_TYPE_DIRECT
block|}
DECL|typedef|xcb_render_pict_type_t
name|xcb_render_pict_type_t
typedef|;
DECL|enum|xcb_render_picture_enum_t
typedef|typedef
enum|enum
name|xcb_render_picture_enum_t
block|{
DECL|enumerator|XCB_RENDER_PICTURE_NONE
name|XCB_RENDER_PICTURE_NONE
block|}
DECL|typedef|xcb_render_picture_enum_t
name|xcb_render_picture_enum_t
typedef|;
DECL|enum|xcb_render_pict_op_t
typedef|typedef
enum|enum
name|xcb_render_pict_op_t
block|{
DECL|enumerator|XCB_RENDER_PICT_OP_CLEAR
name|XCB_RENDER_PICT_OP_CLEAR
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_SRC
name|XCB_RENDER_PICT_OP_SRC
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DST
name|XCB_RENDER_PICT_OP_DST
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_OVER
name|XCB_RENDER_PICT_OP_OVER
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_OVER_REVERSE
name|XCB_RENDER_PICT_OP_OVER_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_IN
name|XCB_RENDER_PICT_OP_IN
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_IN_REVERSE
name|XCB_RENDER_PICT_OP_IN_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_OUT
name|XCB_RENDER_PICT_OP_OUT
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_OUT_REVERSE
name|XCB_RENDER_PICT_OP_OUT_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_ATOP
name|XCB_RENDER_PICT_OP_ATOP
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_ATOP_REVERSE
name|XCB_RENDER_PICT_OP_ATOP_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_XOR
name|XCB_RENDER_PICT_OP_XOR
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_ADD
name|XCB_RENDER_PICT_OP_ADD
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_SATURATE
name|XCB_RENDER_PICT_OP_SATURATE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_CLEAR
name|XCB_RENDER_PICT_OP_DISJOINT_CLEAR
init|=
literal|16
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_SRC
name|XCB_RENDER_PICT_OP_DISJOINT_SRC
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_DST
name|XCB_RENDER_PICT_OP_DISJOINT_DST
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_OVER
name|XCB_RENDER_PICT_OP_DISJOINT_OVER
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_OVER_REVERSE
name|XCB_RENDER_PICT_OP_DISJOINT_OVER_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_IN
name|XCB_RENDER_PICT_OP_DISJOINT_IN
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_IN_REVERSE
name|XCB_RENDER_PICT_OP_DISJOINT_IN_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_OUT
name|XCB_RENDER_PICT_OP_DISJOINT_OUT
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_OUT_REVERSE
name|XCB_RENDER_PICT_OP_DISJOINT_OUT_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_ATOP
name|XCB_RENDER_PICT_OP_DISJOINT_ATOP
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_ATOP_REVERSE
name|XCB_RENDER_PICT_OP_DISJOINT_ATOP_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_DISJOINT_XOR
name|XCB_RENDER_PICT_OP_DISJOINT_XOR
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_CLEAR
name|XCB_RENDER_PICT_OP_CONJOINT_CLEAR
init|=
literal|32
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_SRC
name|XCB_RENDER_PICT_OP_CONJOINT_SRC
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_DST
name|XCB_RENDER_PICT_OP_CONJOINT_DST
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_OVER
name|XCB_RENDER_PICT_OP_CONJOINT_OVER
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_OVER_REVERSE
name|XCB_RENDER_PICT_OP_CONJOINT_OVER_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_IN
name|XCB_RENDER_PICT_OP_CONJOINT_IN
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_IN_REVERSE
name|XCB_RENDER_PICT_OP_CONJOINT_IN_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_OUT
name|XCB_RENDER_PICT_OP_CONJOINT_OUT
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_OUT_REVERSE
name|XCB_RENDER_PICT_OP_CONJOINT_OUT_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_ATOP
name|XCB_RENDER_PICT_OP_CONJOINT_ATOP
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_ATOP_REVERSE
name|XCB_RENDER_PICT_OP_CONJOINT_ATOP_REVERSE
block|,
DECL|enumerator|XCB_RENDER_PICT_OP_CONJOINT_XOR
name|XCB_RENDER_PICT_OP_CONJOINT_XOR
block|}
DECL|typedef|xcb_render_pict_op_t
name|xcb_render_pict_op_t
typedef|;
DECL|enum|xcb_render_poly_edge_t
typedef|typedef
enum|enum
name|xcb_render_poly_edge_t
block|{
DECL|enumerator|XCB_RENDER_POLY_EDGE_SHARP
name|XCB_RENDER_POLY_EDGE_SHARP
block|,
DECL|enumerator|XCB_RENDER_POLY_EDGE_SMOOTH
name|XCB_RENDER_POLY_EDGE_SMOOTH
block|}
DECL|typedef|xcb_render_poly_edge_t
name|xcb_render_poly_edge_t
typedef|;
DECL|enum|xcb_render_poly_mode_t
typedef|typedef
enum|enum
name|xcb_render_poly_mode_t
block|{
DECL|enumerator|XCB_RENDER_POLY_MODE_PRECISE
name|XCB_RENDER_POLY_MODE_PRECISE
block|,
DECL|enumerator|XCB_RENDER_POLY_MODE_IMPRECISE
name|XCB_RENDER_POLY_MODE_IMPRECISE
block|}
DECL|typedef|xcb_render_poly_mode_t
name|xcb_render_poly_mode_t
typedef|;
DECL|enum|xcb_render_cp_t
typedef|typedef
enum|enum
name|xcb_render_cp_t
block|{
DECL|enumerator|XCB_RENDER_CP_REPEAT
name|XCB_RENDER_CP_REPEAT
init|=
literal|1
block|,
DECL|enumerator|XCB_RENDER_CP_ALPHA_MAP
name|XCB_RENDER_CP_ALPHA_MAP
init|=
literal|2
block|,
DECL|enumerator|XCB_RENDER_CP_ALPHA_X_ORIGIN
name|XCB_RENDER_CP_ALPHA_X_ORIGIN
init|=
literal|4
block|,
DECL|enumerator|XCB_RENDER_CP_ALPHA_Y_ORIGIN
name|XCB_RENDER_CP_ALPHA_Y_ORIGIN
init|=
literal|8
block|,
DECL|enumerator|XCB_RENDER_CP_CLIP_X_ORIGIN
name|XCB_RENDER_CP_CLIP_X_ORIGIN
init|=
literal|16
block|,
DECL|enumerator|XCB_RENDER_CP_CLIP_Y_ORIGIN
name|XCB_RENDER_CP_CLIP_Y_ORIGIN
init|=
literal|32
block|,
DECL|enumerator|XCB_RENDER_CP_CLIP_MASK
name|XCB_RENDER_CP_CLIP_MASK
init|=
literal|64
block|,
DECL|enumerator|XCB_RENDER_CP_GRAPHICS_EXPOSURE
name|XCB_RENDER_CP_GRAPHICS_EXPOSURE
init|=
literal|128
block|,
DECL|enumerator|XCB_RENDER_CP_SUBWINDOW_MODE
name|XCB_RENDER_CP_SUBWINDOW_MODE
init|=
literal|256
block|,
DECL|enumerator|XCB_RENDER_CP_POLY_EDGE
name|XCB_RENDER_CP_POLY_EDGE
init|=
literal|512
block|,
DECL|enumerator|XCB_RENDER_CP_POLY_MODE
name|XCB_RENDER_CP_POLY_MODE
init|=
literal|1024
block|,
DECL|enumerator|XCB_RENDER_CP_DITHER
name|XCB_RENDER_CP_DITHER
init|=
literal|2048
block|,
DECL|enumerator|XCB_RENDER_CP_COMPONENT_ALPHA
name|XCB_RENDER_CP_COMPONENT_ALPHA
init|=
literal|4096
block|}
DECL|typedef|xcb_render_cp_t
name|xcb_render_cp_t
typedef|;
DECL|enum|xcb_render_sub_pixel_t
typedef|typedef
enum|enum
name|xcb_render_sub_pixel_t
block|{
DECL|enumerator|XCB_RENDER_SUB_PIXEL_UNKNOWN
name|XCB_RENDER_SUB_PIXEL_UNKNOWN
block|,
DECL|enumerator|XCB_RENDER_SUB_PIXEL_HORIZONTAL_RGB
name|XCB_RENDER_SUB_PIXEL_HORIZONTAL_RGB
block|,
DECL|enumerator|XCB_RENDER_SUB_PIXEL_HORIZONTAL_BGR
name|XCB_RENDER_SUB_PIXEL_HORIZONTAL_BGR
block|,
DECL|enumerator|XCB_RENDER_SUB_PIXEL_VERTICAL_RGB
name|XCB_RENDER_SUB_PIXEL_VERTICAL_RGB
block|,
DECL|enumerator|XCB_RENDER_SUB_PIXEL_VERTICAL_BGR
name|XCB_RENDER_SUB_PIXEL_VERTICAL_BGR
block|,
DECL|enumerator|XCB_RENDER_SUB_PIXEL_NONE
name|XCB_RENDER_SUB_PIXEL_NONE
block|}
DECL|typedef|xcb_render_sub_pixel_t
name|xcb_render_sub_pixel_t
typedef|;
DECL|enum|xcb_render_repeat_t
typedef|typedef
enum|enum
name|xcb_render_repeat_t
block|{
DECL|enumerator|XCB_RENDER_REPEAT_NONE
name|XCB_RENDER_REPEAT_NONE
block|,
DECL|enumerator|XCB_RENDER_REPEAT_NORMAL
name|XCB_RENDER_REPEAT_NORMAL
block|,
DECL|enumerator|XCB_RENDER_REPEAT_PAD
name|XCB_RENDER_REPEAT_PAD
block|,
DECL|enumerator|XCB_RENDER_REPEAT_REFLECT
name|XCB_RENDER_REPEAT_REFLECT
block|}
DECL|typedef|xcb_render_repeat_t
name|xcb_render_repeat_t
typedef|;
DECL|typedef|xcb_render_glyph_t
typedef|typedef
name|uint32_t
name|xcb_render_glyph_t
typedef|;
comment|/**  * @brief xcb_render_glyph_iterator_t  **/
DECL|struct|xcb_render_glyph_iterator_t
typedef|typedef
struct|struct
name|xcb_render_glyph_iterator_t
block|{
DECL|member|data
name|xcb_render_glyph_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_glyph_iterator_t
name|xcb_render_glyph_iterator_t
typedef|;
DECL|typedef|xcb_render_glyphset_t
typedef|typedef
name|uint32_t
name|xcb_render_glyphset_t
typedef|;
comment|/**  * @brief xcb_render_glyphset_iterator_t  **/
DECL|struct|xcb_render_glyphset_iterator_t
typedef|typedef
struct|struct
name|xcb_render_glyphset_iterator_t
block|{
DECL|member|data
name|xcb_render_glyphset_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_glyphset_iterator_t
name|xcb_render_glyphset_iterator_t
typedef|;
DECL|typedef|xcb_render_picture_t
typedef|typedef
name|uint32_t
name|xcb_render_picture_t
typedef|;
comment|/**  * @brief xcb_render_picture_iterator_t  **/
DECL|struct|xcb_render_picture_iterator_t
typedef|typedef
struct|struct
name|xcb_render_picture_iterator_t
block|{
DECL|member|data
name|xcb_render_picture_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_picture_iterator_t
name|xcb_render_picture_iterator_t
typedef|;
DECL|typedef|xcb_render_pictformat_t
typedef|typedef
name|uint32_t
name|xcb_render_pictformat_t
typedef|;
comment|/**  * @brief xcb_render_pictformat_iterator_t  **/
DECL|struct|xcb_render_pictformat_iterator_t
typedef|typedef
struct|struct
name|xcb_render_pictformat_iterator_t
block|{
DECL|member|data
name|xcb_render_pictformat_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictformat_iterator_t
name|xcb_render_pictformat_iterator_t
typedef|;
DECL|typedef|xcb_render_fixed_t
typedef|typedef
name|int32_t
name|xcb_render_fixed_t
typedef|;
comment|/**  * @brief xcb_render_fixed_iterator_t  **/
DECL|struct|xcb_render_fixed_iterator_t
typedef|typedef
struct|struct
name|xcb_render_fixed_iterator_t
block|{
DECL|member|data
name|xcb_render_fixed_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_fixed_iterator_t
name|xcb_render_fixed_iterator_t
typedef|;
comment|/** Opcode for xcb_render_pict_format. */
DECL|macro|XCB_RENDER_PICT_FORMAT
define|#
directive|define
name|XCB_RENDER_PICT_FORMAT
value|0
comment|/**  * @brief xcb_render_pict_format_error_t  **/
DECL|struct|xcb_render_pict_format_error_t
typedef|typedef
struct|struct
name|xcb_render_pict_format_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pict_format_error_t
name|xcb_render_pict_format_error_t
typedef|;
comment|/** Opcode for xcb_render_picture. */
DECL|macro|XCB_RENDER_PICTURE
define|#
directive|define
name|XCB_RENDER_PICTURE
value|1
comment|/**  * @brief xcb_render_picture_error_t  **/
DECL|struct|xcb_render_picture_error_t
typedef|typedef
struct|struct
name|xcb_render_picture_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_picture_error_t
name|xcb_render_picture_error_t
typedef|;
comment|/** Opcode for xcb_render_pict_op. */
DECL|macro|XCB_RENDER_PICT_OP
define|#
directive|define
name|XCB_RENDER_PICT_OP
value|2
comment|/**  * @brief xcb_render_pict_op_error_t  **/
DECL|struct|xcb_render_pict_op_error_t
typedef|typedef
struct|struct
name|xcb_render_pict_op_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pict_op_error_t
name|xcb_render_pict_op_error_t
typedef|;
comment|/** Opcode for xcb_render_glyph_set. */
DECL|macro|XCB_RENDER_GLYPH_SET
define|#
directive|define
name|XCB_RENDER_GLYPH_SET
value|3
comment|/**  * @brief xcb_render_glyph_set_error_t  **/
DECL|struct|xcb_render_glyph_set_error_t
typedef|typedef
struct|struct
name|xcb_render_glyph_set_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_glyph_set_error_t
name|xcb_render_glyph_set_error_t
typedef|;
comment|/** Opcode for xcb_render_glyph. */
DECL|macro|XCB_RENDER_GLYPH
define|#
directive|define
name|XCB_RENDER_GLYPH
value|4
comment|/**  * @brief xcb_render_glyph_error_t  **/
DECL|struct|xcb_render_glyph_error_t
typedef|typedef
struct|struct
name|xcb_render_glyph_error_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|error_code
name|uint8_t
name|error_code
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_glyph_error_t
name|xcb_render_glyph_error_t
typedef|;
comment|/**  * @brief xcb_render_directformat_t  **/
DECL|struct|xcb_render_directformat_t
typedef|typedef
struct|struct
name|xcb_render_directformat_t
block|{
DECL|member|red_shift
name|uint16_t
name|red_shift
decl_stmt|;
comment|/**<  */
DECL|member|red_mask
name|uint16_t
name|red_mask
decl_stmt|;
comment|/**<  */
DECL|member|green_shift
name|uint16_t
name|green_shift
decl_stmt|;
comment|/**<  */
DECL|member|green_mask
name|uint16_t
name|green_mask
decl_stmt|;
comment|/**<  */
DECL|member|blue_shift
name|uint16_t
name|blue_shift
decl_stmt|;
comment|/**<  */
DECL|member|blue_mask
name|uint16_t
name|blue_mask
decl_stmt|;
comment|/**<  */
DECL|member|alpha_shift
name|uint16_t
name|alpha_shift
decl_stmt|;
comment|/**<  */
DECL|member|alpha_mask
name|uint16_t
name|alpha_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_directformat_t
name|xcb_render_directformat_t
typedef|;
comment|/**  * @brief xcb_render_directformat_iterator_t  **/
DECL|struct|xcb_render_directformat_iterator_t
typedef|typedef
struct|struct
name|xcb_render_directformat_iterator_t
block|{
DECL|member|data
name|xcb_render_directformat_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_directformat_iterator_t
name|xcb_render_directformat_iterator_t
typedef|;
comment|/**  * @brief xcb_render_pictforminfo_t  **/
DECL|struct|xcb_render_pictforminfo_t
typedef|typedef
struct|struct
name|xcb_render_pictforminfo_t
block|{
DECL|member|id
name|xcb_render_pictformat_t
name|id
decl_stmt|;
comment|/**<  */
DECL|member|type
name|uint8_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|depth
name|uint8_t
name|depth
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|direct
name|xcb_render_directformat_t
name|direct
decl_stmt|;
comment|/**<  */
DECL|member|colormap
name|xcb_colormap_t
name|colormap
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictforminfo_t
name|xcb_render_pictforminfo_t
typedef|;
comment|/**  * @brief xcb_render_pictforminfo_iterator_t  **/
DECL|struct|xcb_render_pictforminfo_iterator_t
typedef|typedef
struct|struct
name|xcb_render_pictforminfo_iterator_t
block|{
DECL|member|data
name|xcb_render_pictforminfo_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictforminfo_iterator_t
name|xcb_render_pictforminfo_iterator_t
typedef|;
comment|/**  * @brief xcb_render_pictvisual_t  **/
DECL|struct|xcb_render_pictvisual_t
typedef|typedef
struct|struct
name|xcb_render_pictvisual_t
block|{
DECL|member|visual
name|xcb_visualid_t
name|visual
decl_stmt|;
comment|/**<  */
DECL|member|format
name|xcb_render_pictformat_t
name|format
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictvisual_t
name|xcb_render_pictvisual_t
typedef|;
comment|/**  * @brief xcb_render_pictvisual_iterator_t  **/
DECL|struct|xcb_render_pictvisual_iterator_t
typedef|typedef
struct|struct
name|xcb_render_pictvisual_iterator_t
block|{
DECL|member|data
name|xcb_render_pictvisual_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictvisual_iterator_t
name|xcb_render_pictvisual_iterator_t
typedef|;
comment|/**  * @brief xcb_render_pictdepth_t  **/
DECL|struct|xcb_render_pictdepth_t
typedef|typedef
struct|struct
name|xcb_render_pictdepth_t
block|{
DECL|member|depth
name|uint8_t
name|depth
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|num_visuals
name|uint16_t
name|num_visuals
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictdepth_t
name|xcb_render_pictdepth_t
typedef|;
comment|/**  * @brief xcb_render_pictdepth_iterator_t  **/
DECL|struct|xcb_render_pictdepth_iterator_t
typedef|typedef
struct|struct
name|xcb_render_pictdepth_iterator_t
block|{
DECL|member|data
name|xcb_render_pictdepth_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictdepth_iterator_t
name|xcb_render_pictdepth_iterator_t
typedef|;
comment|/**  * @brief xcb_render_pictscreen_t  **/
DECL|struct|xcb_render_pictscreen_t
typedef|typedef
struct|struct
name|xcb_render_pictscreen_t
block|{
DECL|member|num_depths
name|uint32_t
name|num_depths
decl_stmt|;
comment|/**<  */
DECL|member|fallback
name|xcb_render_pictformat_t
name|fallback
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictscreen_t
name|xcb_render_pictscreen_t
typedef|;
comment|/**  * @brief xcb_render_pictscreen_iterator_t  **/
DECL|struct|xcb_render_pictscreen_iterator_t
typedef|typedef
struct|struct
name|xcb_render_pictscreen_iterator_t
block|{
DECL|member|data
name|xcb_render_pictscreen_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pictscreen_iterator_t
name|xcb_render_pictscreen_iterator_t
typedef|;
comment|/**  * @brief xcb_render_indexvalue_t  **/
DECL|struct|xcb_render_indexvalue_t
typedef|typedef
struct|struct
name|xcb_render_indexvalue_t
block|{
DECL|member|pixel
name|uint32_t
name|pixel
decl_stmt|;
comment|/**<  */
DECL|member|red
name|uint16_t
name|red
decl_stmt|;
comment|/**<  */
DECL|member|green
name|uint16_t
name|green
decl_stmt|;
comment|/**<  */
DECL|member|blue
name|uint16_t
name|blue
decl_stmt|;
comment|/**<  */
DECL|member|alpha
name|uint16_t
name|alpha
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_indexvalue_t
name|xcb_render_indexvalue_t
typedef|;
comment|/**  * @brief xcb_render_indexvalue_iterator_t  **/
DECL|struct|xcb_render_indexvalue_iterator_t
typedef|typedef
struct|struct
name|xcb_render_indexvalue_iterator_t
block|{
DECL|member|data
name|xcb_render_indexvalue_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_indexvalue_iterator_t
name|xcb_render_indexvalue_iterator_t
typedef|;
comment|/**  * @brief xcb_render_color_t  **/
DECL|struct|xcb_render_color_t
typedef|typedef
struct|struct
name|xcb_render_color_t
block|{
DECL|member|red
name|uint16_t
name|red
decl_stmt|;
comment|/**<  */
DECL|member|green
name|uint16_t
name|green
decl_stmt|;
comment|/**<  */
DECL|member|blue
name|uint16_t
name|blue
decl_stmt|;
comment|/**<  */
DECL|member|alpha
name|uint16_t
name|alpha
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_color_t
name|xcb_render_color_t
typedef|;
comment|/**  * @brief xcb_render_color_iterator_t  **/
DECL|struct|xcb_render_color_iterator_t
typedef|typedef
struct|struct
name|xcb_render_color_iterator_t
block|{
DECL|member|data
name|xcb_render_color_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_color_iterator_t
name|xcb_render_color_iterator_t
typedef|;
comment|/**  * @brief xcb_render_pointfix_t  **/
DECL|struct|xcb_render_pointfix_t
typedef|typedef
struct|struct
name|xcb_render_pointfix_t
block|{
DECL|member|x
name|xcb_render_fixed_t
name|x
decl_stmt|;
comment|/**<  */
DECL|member|y
name|xcb_render_fixed_t
name|y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pointfix_t
name|xcb_render_pointfix_t
typedef|;
comment|/**  * @brief xcb_render_pointfix_iterator_t  **/
DECL|struct|xcb_render_pointfix_iterator_t
typedef|typedef
struct|struct
name|xcb_render_pointfix_iterator_t
block|{
DECL|member|data
name|xcb_render_pointfix_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_pointfix_iterator_t
name|xcb_render_pointfix_iterator_t
typedef|;
comment|/**  * @brief xcb_render_linefix_t  **/
DECL|struct|xcb_render_linefix_t
typedef|typedef
struct|struct
name|xcb_render_linefix_t
block|{
DECL|member|p1
name|xcb_render_pointfix_t
name|p1
decl_stmt|;
comment|/**<  */
DECL|member|p2
name|xcb_render_pointfix_t
name|p2
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_linefix_t
name|xcb_render_linefix_t
typedef|;
comment|/**  * @brief xcb_render_linefix_iterator_t  **/
DECL|struct|xcb_render_linefix_iterator_t
typedef|typedef
struct|struct
name|xcb_render_linefix_iterator_t
block|{
DECL|member|data
name|xcb_render_linefix_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_linefix_iterator_t
name|xcb_render_linefix_iterator_t
typedef|;
comment|/**  * @brief xcb_render_triangle_t  **/
DECL|struct|xcb_render_triangle_t
typedef|typedef
struct|struct
name|xcb_render_triangle_t
block|{
DECL|member|p1
name|xcb_render_pointfix_t
name|p1
decl_stmt|;
comment|/**<  */
DECL|member|p2
name|xcb_render_pointfix_t
name|p2
decl_stmt|;
comment|/**<  */
DECL|member|p3
name|xcb_render_pointfix_t
name|p3
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_triangle_t
name|xcb_render_triangle_t
typedef|;
comment|/**  * @brief xcb_render_triangle_iterator_t  **/
DECL|struct|xcb_render_triangle_iterator_t
typedef|typedef
struct|struct
name|xcb_render_triangle_iterator_t
block|{
DECL|member|data
name|xcb_render_triangle_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_triangle_iterator_t
name|xcb_render_triangle_iterator_t
typedef|;
comment|/**  * @brief xcb_render_trapezoid_t  **/
DECL|struct|xcb_render_trapezoid_t
typedef|typedef
struct|struct
name|xcb_render_trapezoid_t
block|{
DECL|member|top
name|xcb_render_fixed_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|bottom
name|xcb_render_fixed_t
name|bottom
decl_stmt|;
comment|/**<  */
DECL|member|left
name|xcb_render_linefix_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|right
name|xcb_render_linefix_t
name|right
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_trapezoid_t
name|xcb_render_trapezoid_t
typedef|;
comment|/**  * @brief xcb_render_trapezoid_iterator_t  **/
DECL|struct|xcb_render_trapezoid_iterator_t
typedef|typedef
struct|struct
name|xcb_render_trapezoid_iterator_t
block|{
DECL|member|data
name|xcb_render_trapezoid_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_trapezoid_iterator_t
name|xcb_render_trapezoid_iterator_t
typedef|;
comment|/**  * @brief xcb_render_glyphinfo_t  **/
DECL|struct|xcb_render_glyphinfo_t
typedef|typedef
struct|struct
name|xcb_render_glyphinfo_t
block|{
DECL|member|width
name|uint16_t
name|width
decl_stmt|;
comment|/**<  */
DECL|member|height
name|uint16_t
name|height
decl_stmt|;
comment|/**<  */
DECL|member|x
name|int16_t
name|x
decl_stmt|;
comment|/**<  */
DECL|member|y
name|int16_t
name|y
decl_stmt|;
comment|/**<  */
DECL|member|x_off
name|int16_t
name|x_off
decl_stmt|;
comment|/**<  */
DECL|member|y_off
name|int16_t
name|y_off
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_glyphinfo_t
name|xcb_render_glyphinfo_t
typedef|;
comment|/**  * @brief xcb_render_glyphinfo_iterator_t  **/
DECL|struct|xcb_render_glyphinfo_iterator_t
typedef|typedef
struct|struct
name|xcb_render_glyphinfo_iterator_t
block|{
DECL|member|data
name|xcb_render_glyphinfo_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_glyphinfo_iterator_t
name|xcb_render_glyphinfo_iterator_t
typedef|;
comment|/**  * @brief xcb_render_query_version_cookie_t  **/
DECL|struct|xcb_render_query_version_cookie_t
typedef|typedef
struct|struct
name|xcb_render_query_version_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_version_cookie_t
name|xcb_render_query_version_cookie_t
typedef|;
comment|/** Opcode for xcb_render_query_version. */
DECL|macro|XCB_RENDER_QUERY_VERSION
define|#
directive|define
name|XCB_RENDER_QUERY_VERSION
value|0
comment|/**  * @brief xcb_render_query_version_request_t  **/
DECL|struct|xcb_render_query_version_request_t
typedef|typedef
struct|struct
name|xcb_render_query_version_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|client_major_version
name|uint32_t
name|client_major_version
decl_stmt|;
comment|/**<  */
DECL|member|client_minor_version
name|uint32_t
name|client_minor_version
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_version_request_t
name|xcb_render_query_version_request_t
typedef|;
comment|/**  * @brief xcb_render_query_version_reply_t  **/
DECL|struct|xcb_render_query_version_reply_t
typedef|typedef
struct|struct
name|xcb_render_query_version_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|major_version
name|uint32_t
name|major_version
decl_stmt|;
comment|/**<  */
DECL|member|minor_version
name|uint32_t
name|minor_version
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_version_reply_t
name|xcb_render_query_version_reply_t
typedef|;
comment|/**  * @brief xcb_render_query_pict_formats_cookie_t  **/
DECL|struct|xcb_render_query_pict_formats_cookie_t
typedef|typedef
struct|struct
name|xcb_render_query_pict_formats_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_pict_formats_cookie_t
name|xcb_render_query_pict_formats_cookie_t
typedef|;
comment|/** Opcode for xcb_render_query_pict_formats. */
DECL|macro|XCB_RENDER_QUERY_PICT_FORMATS
define|#
directive|define
name|XCB_RENDER_QUERY_PICT_FORMATS
value|1
comment|/**  * @brief xcb_render_query_pict_formats_request_t  **/
DECL|struct|xcb_render_query_pict_formats_request_t
typedef|typedef
struct|struct
name|xcb_render_query_pict_formats_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_pict_formats_request_t
name|xcb_render_query_pict_formats_request_t
typedef|;
comment|/**  * @brief xcb_render_query_pict_formats_reply_t  **/
DECL|struct|xcb_render_query_pict_formats_reply_t
typedef|typedef
struct|struct
name|xcb_render_query_pict_formats_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|num_formats
name|uint32_t
name|num_formats
decl_stmt|;
comment|/**<  */
DECL|member|num_screens
name|uint32_t
name|num_screens
decl_stmt|;
comment|/**<  */
DECL|member|num_depths
name|uint32_t
name|num_depths
decl_stmt|;
comment|/**<  */
DECL|member|num_visuals
name|uint32_t
name|num_visuals
decl_stmt|;
comment|/**<  */
DECL|member|num_subpixel
name|uint32_t
name|num_subpixel
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_pict_formats_reply_t
name|xcb_render_query_pict_formats_reply_t
typedef|;
comment|/**  * @brief xcb_render_query_pict_index_values_cookie_t  **/
DECL|struct|xcb_render_query_pict_index_values_cookie_t
typedef|typedef
struct|struct
name|xcb_render_query_pict_index_values_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_pict_index_values_cookie_t
name|xcb_render_query_pict_index_values_cookie_t
typedef|;
comment|/** Opcode for xcb_render_query_pict_index_values. */
DECL|macro|XCB_RENDER_QUERY_PICT_INDEX_VALUES
define|#
directive|define
name|XCB_RENDER_QUERY_PICT_INDEX_VALUES
value|2
comment|/**  * @brief xcb_render_query_pict_index_values_request_t  **/
DECL|struct|xcb_render_query_pict_index_values_request_t
typedef|typedef
struct|struct
name|xcb_render_query_pict_index_values_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|format
name|xcb_render_pictformat_t
name|format
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_pict_index_values_request_t
name|xcb_render_query_pict_index_values_request_t
typedef|;
comment|/**  * @brief xcb_render_query_pict_index_values_reply_t  **/
DECL|struct|xcb_render_query_pict_index_values_reply_t
typedef|typedef
struct|struct
name|xcb_render_query_pict_index_values_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|num_values
name|uint32_t
name|num_values
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|20
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_pict_index_values_reply_t
name|xcb_render_query_pict_index_values_reply_t
typedef|;
comment|/** Opcode for xcb_render_create_picture. */
DECL|macro|XCB_RENDER_CREATE_PICTURE
define|#
directive|define
name|XCB_RENDER_CREATE_PICTURE
value|4
comment|/**  * @brief xcb_render_create_picture_request_t  **/
DECL|struct|xcb_render_create_picture_request_t
typedef|typedef
struct|struct
name|xcb_render_create_picture_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|pid
name|xcb_render_picture_t
name|pid
decl_stmt|;
comment|/**<  */
DECL|member|drawable
name|xcb_drawable_t
name|drawable
decl_stmt|;
comment|/**<  */
DECL|member|format
name|xcb_render_pictformat_t
name|format
decl_stmt|;
comment|/**<  */
DECL|member|value_mask
name|uint32_t
name|value_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_picture_request_t
name|xcb_render_create_picture_request_t
typedef|;
comment|/** Opcode for xcb_render_change_picture. */
DECL|macro|XCB_RENDER_CHANGE_PICTURE
define|#
directive|define
name|XCB_RENDER_CHANGE_PICTURE
value|5
comment|/**  * @brief xcb_render_change_picture_request_t  **/
DECL|struct|xcb_render_change_picture_request_t
typedef|typedef
struct|struct
name|xcb_render_change_picture_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|value_mask
name|uint32_t
name|value_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_change_picture_request_t
name|xcb_render_change_picture_request_t
typedef|;
comment|/** Opcode for xcb_render_set_picture_clip_rectangles. */
DECL|macro|XCB_RENDER_SET_PICTURE_CLIP_RECTANGLES
define|#
directive|define
name|XCB_RENDER_SET_PICTURE_CLIP_RECTANGLES
value|6
comment|/**  * @brief xcb_render_set_picture_clip_rectangles_request_t  **/
DECL|struct|xcb_render_set_picture_clip_rectangles_request_t
typedef|typedef
struct|struct
name|xcb_render_set_picture_clip_rectangles_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|clip_x_origin
name|int16_t
name|clip_x_origin
decl_stmt|;
comment|/**<  */
DECL|member|clip_y_origin
name|int16_t
name|clip_y_origin
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_set_picture_clip_rectangles_request_t
name|xcb_render_set_picture_clip_rectangles_request_t
typedef|;
comment|/** Opcode for xcb_render_free_picture. */
DECL|macro|XCB_RENDER_FREE_PICTURE
define|#
directive|define
name|XCB_RENDER_FREE_PICTURE
value|7
comment|/**  * @brief xcb_render_free_picture_request_t  **/
DECL|struct|xcb_render_free_picture_request_t
typedef|typedef
struct|struct
name|xcb_render_free_picture_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_free_picture_request_t
name|xcb_render_free_picture_request_t
typedef|;
comment|/** Opcode for xcb_render_composite. */
DECL|macro|XCB_RENDER_COMPOSITE
define|#
directive|define
name|XCB_RENDER_COMPOSITE
value|8
comment|/**  * @brief xcb_render_composite_request_t  **/
DECL|struct|xcb_render_composite_request_t
typedef|typedef
struct|struct
name|xcb_render_composite_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|mask
name|xcb_render_picture_t
name|mask
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
DECL|member|mask_x
name|int16_t
name|mask_x
decl_stmt|;
comment|/**<  */
DECL|member|mask_y
name|int16_t
name|mask_y
decl_stmt|;
comment|/**<  */
DECL|member|dst_x
name|int16_t
name|dst_x
decl_stmt|;
comment|/**<  */
DECL|member|dst_y
name|int16_t
name|dst_y
decl_stmt|;
comment|/**<  */
DECL|member|width
name|uint16_t
name|width
decl_stmt|;
comment|/**<  */
DECL|member|height
name|uint16_t
name|height
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_composite_request_t
name|xcb_render_composite_request_t
typedef|;
comment|/** Opcode for xcb_render_trapezoids. */
DECL|macro|XCB_RENDER_TRAPEZOIDS
define|#
directive|define
name|XCB_RENDER_TRAPEZOIDS
value|10
comment|/**  * @brief xcb_render_trapezoids_request_t  **/
DECL|struct|xcb_render_trapezoids_request_t
typedef|typedef
struct|struct
name|xcb_render_trapezoids_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_trapezoids_request_t
name|xcb_render_trapezoids_request_t
typedef|;
comment|/** Opcode for xcb_render_triangles. */
DECL|macro|XCB_RENDER_TRIANGLES
define|#
directive|define
name|XCB_RENDER_TRIANGLES
value|11
comment|/**  * @brief xcb_render_triangles_request_t  **/
DECL|struct|xcb_render_triangles_request_t
typedef|typedef
struct|struct
name|xcb_render_triangles_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_triangles_request_t
name|xcb_render_triangles_request_t
typedef|;
comment|/** Opcode for xcb_render_tri_strip. */
DECL|macro|XCB_RENDER_TRI_STRIP
define|#
directive|define
name|XCB_RENDER_TRI_STRIP
value|12
comment|/**  * @brief xcb_render_tri_strip_request_t  **/
DECL|struct|xcb_render_tri_strip_request_t
typedef|typedef
struct|struct
name|xcb_render_tri_strip_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_tri_strip_request_t
name|xcb_render_tri_strip_request_t
typedef|;
comment|/** Opcode for xcb_render_tri_fan. */
DECL|macro|XCB_RENDER_TRI_FAN
define|#
directive|define
name|XCB_RENDER_TRI_FAN
value|13
comment|/**  * @brief xcb_render_tri_fan_request_t  **/
DECL|struct|xcb_render_tri_fan_request_t
typedef|typedef
struct|struct
name|xcb_render_tri_fan_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_tri_fan_request_t
name|xcb_render_tri_fan_request_t
typedef|;
comment|/** Opcode for xcb_render_create_glyph_set. */
DECL|macro|XCB_RENDER_CREATE_GLYPH_SET
define|#
directive|define
name|XCB_RENDER_CREATE_GLYPH_SET
value|17
comment|/**  * @brief xcb_render_create_glyph_set_request_t  **/
DECL|struct|xcb_render_create_glyph_set_request_t
typedef|typedef
struct|struct
name|xcb_render_create_glyph_set_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|gsid
name|xcb_render_glyphset_t
name|gsid
decl_stmt|;
comment|/**<  */
DECL|member|format
name|xcb_render_pictformat_t
name|format
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_glyph_set_request_t
name|xcb_render_create_glyph_set_request_t
typedef|;
comment|/** Opcode for xcb_render_reference_glyph_set. */
DECL|macro|XCB_RENDER_REFERENCE_GLYPH_SET
define|#
directive|define
name|XCB_RENDER_REFERENCE_GLYPH_SET
value|18
comment|/**  * @brief xcb_render_reference_glyph_set_request_t  **/
DECL|struct|xcb_render_reference_glyph_set_request_t
typedef|typedef
struct|struct
name|xcb_render_reference_glyph_set_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|gsid
name|xcb_render_glyphset_t
name|gsid
decl_stmt|;
comment|/**<  */
DECL|member|existing
name|xcb_render_glyphset_t
name|existing
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_reference_glyph_set_request_t
name|xcb_render_reference_glyph_set_request_t
typedef|;
comment|/** Opcode for xcb_render_free_glyph_set. */
DECL|macro|XCB_RENDER_FREE_GLYPH_SET
define|#
directive|define
name|XCB_RENDER_FREE_GLYPH_SET
value|19
comment|/**  * @brief xcb_render_free_glyph_set_request_t  **/
DECL|struct|xcb_render_free_glyph_set_request_t
typedef|typedef
struct|struct
name|xcb_render_free_glyph_set_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|glyphset
name|xcb_render_glyphset_t
name|glyphset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_free_glyph_set_request_t
name|xcb_render_free_glyph_set_request_t
typedef|;
comment|/** Opcode for xcb_render_add_glyphs. */
DECL|macro|XCB_RENDER_ADD_GLYPHS
define|#
directive|define
name|XCB_RENDER_ADD_GLYPHS
value|20
comment|/**  * @brief xcb_render_add_glyphs_request_t  **/
DECL|struct|xcb_render_add_glyphs_request_t
typedef|typedef
struct|struct
name|xcb_render_add_glyphs_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|glyphset
name|xcb_render_glyphset_t
name|glyphset
decl_stmt|;
comment|/**<  */
DECL|member|glyphs_len
name|uint32_t
name|glyphs_len
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_add_glyphs_request_t
name|xcb_render_add_glyphs_request_t
typedef|;
comment|/** Opcode for xcb_render_free_glyphs. */
DECL|macro|XCB_RENDER_FREE_GLYPHS
define|#
directive|define
name|XCB_RENDER_FREE_GLYPHS
value|22
comment|/**  * @brief xcb_render_free_glyphs_request_t  **/
DECL|struct|xcb_render_free_glyphs_request_t
typedef|typedef
struct|struct
name|xcb_render_free_glyphs_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|glyphset
name|xcb_render_glyphset_t
name|glyphset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_free_glyphs_request_t
name|xcb_render_free_glyphs_request_t
typedef|;
comment|/** Opcode for xcb_render_composite_glyphs_8. */
DECL|macro|XCB_RENDER_COMPOSITE_GLYPHS_8
define|#
directive|define
name|XCB_RENDER_COMPOSITE_GLYPHS_8
value|23
comment|/**  * @brief xcb_render_composite_glyphs_8_request_t  **/
DECL|struct|xcb_render_composite_glyphs_8_request_t
typedef|typedef
struct|struct
name|xcb_render_composite_glyphs_8_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|glyphset
name|xcb_render_glyphset_t
name|glyphset
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_composite_glyphs_8_request_t
name|xcb_render_composite_glyphs_8_request_t
typedef|;
comment|/** Opcode for xcb_render_composite_glyphs_16. */
DECL|macro|XCB_RENDER_COMPOSITE_GLYPHS_16
define|#
directive|define
name|XCB_RENDER_COMPOSITE_GLYPHS_16
value|24
comment|/**  * @brief xcb_render_composite_glyphs_16_request_t  **/
DECL|struct|xcb_render_composite_glyphs_16_request_t
typedef|typedef
struct|struct
name|xcb_render_composite_glyphs_16_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|glyphset
name|xcb_render_glyphset_t
name|glyphset
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_composite_glyphs_16_request_t
name|xcb_render_composite_glyphs_16_request_t
typedef|;
comment|/** Opcode for xcb_render_composite_glyphs_32. */
DECL|macro|XCB_RENDER_COMPOSITE_GLYPHS_32
define|#
directive|define
name|XCB_RENDER_COMPOSITE_GLYPHS_32
value|25
comment|/**  * @brief xcb_render_composite_glyphs_32_request_t  **/
DECL|struct|xcb_render_composite_glyphs_32_request_t
typedef|typedef
struct|struct
name|xcb_render_composite_glyphs_32_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|src
name|xcb_render_picture_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|mask_format
name|xcb_render_pictformat_t
name|mask_format
decl_stmt|;
comment|/**<  */
DECL|member|glyphset
name|xcb_render_glyphset_t
name|glyphset
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|int16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|int16_t
name|src_y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_composite_glyphs_32_request_t
name|xcb_render_composite_glyphs_32_request_t
typedef|;
comment|/** Opcode for xcb_render_fill_rectangles. */
DECL|macro|XCB_RENDER_FILL_RECTANGLES
define|#
directive|define
name|XCB_RENDER_FILL_RECTANGLES
value|26
comment|/**  * @brief xcb_render_fill_rectangles_request_t  **/
DECL|struct|xcb_render_fill_rectangles_request_t
typedef|typedef
struct|struct
name|xcb_render_fill_rectangles_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|op
name|uint8_t
name|op
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|dst
name|xcb_render_picture_t
name|dst
decl_stmt|;
comment|/**<  */
DECL|member|color
name|xcb_render_color_t
name|color
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_fill_rectangles_request_t
name|xcb_render_fill_rectangles_request_t
typedef|;
comment|/** Opcode for xcb_render_create_cursor. */
DECL|macro|XCB_RENDER_CREATE_CURSOR
define|#
directive|define
name|XCB_RENDER_CREATE_CURSOR
value|27
comment|/**  * @brief xcb_render_create_cursor_request_t  **/
DECL|struct|xcb_render_create_cursor_request_t
typedef|typedef
struct|struct
name|xcb_render_create_cursor_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|cid
name|xcb_cursor_t
name|cid
decl_stmt|;
comment|/**<  */
DECL|member|source
name|xcb_render_picture_t
name|source
decl_stmt|;
comment|/**<  */
DECL|member|x
name|uint16_t
name|x
decl_stmt|;
comment|/**<  */
DECL|member|y
name|uint16_t
name|y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_cursor_request_t
name|xcb_render_create_cursor_request_t
typedef|;
comment|/**  * @brief xcb_render_transform_t  **/
DECL|struct|xcb_render_transform_t
typedef|typedef
struct|struct
name|xcb_render_transform_t
block|{
DECL|member|matrix11
name|xcb_render_fixed_t
name|matrix11
decl_stmt|;
comment|/**<  */
DECL|member|matrix12
name|xcb_render_fixed_t
name|matrix12
decl_stmt|;
comment|/**<  */
DECL|member|matrix13
name|xcb_render_fixed_t
name|matrix13
decl_stmt|;
comment|/**<  */
DECL|member|matrix21
name|xcb_render_fixed_t
name|matrix21
decl_stmt|;
comment|/**<  */
DECL|member|matrix22
name|xcb_render_fixed_t
name|matrix22
decl_stmt|;
comment|/**<  */
DECL|member|matrix23
name|xcb_render_fixed_t
name|matrix23
decl_stmt|;
comment|/**<  */
DECL|member|matrix31
name|xcb_render_fixed_t
name|matrix31
decl_stmt|;
comment|/**<  */
DECL|member|matrix32
name|xcb_render_fixed_t
name|matrix32
decl_stmt|;
comment|/**<  */
DECL|member|matrix33
name|xcb_render_fixed_t
name|matrix33
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_transform_t
name|xcb_render_transform_t
typedef|;
comment|/**  * @brief xcb_render_transform_iterator_t  **/
DECL|struct|xcb_render_transform_iterator_t
typedef|typedef
struct|struct
name|xcb_render_transform_iterator_t
block|{
DECL|member|data
name|xcb_render_transform_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_transform_iterator_t
name|xcb_render_transform_iterator_t
typedef|;
comment|/** Opcode for xcb_render_set_picture_transform. */
DECL|macro|XCB_RENDER_SET_PICTURE_TRANSFORM
define|#
directive|define
name|XCB_RENDER_SET_PICTURE_TRANSFORM
value|28
comment|/**  * @brief xcb_render_set_picture_transform_request_t  **/
DECL|struct|xcb_render_set_picture_transform_request_t
typedef|typedef
struct|struct
name|xcb_render_set_picture_transform_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|transform
name|xcb_render_transform_t
name|transform
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_set_picture_transform_request_t
name|xcb_render_set_picture_transform_request_t
typedef|;
comment|/**  * @brief xcb_render_query_filters_cookie_t  **/
DECL|struct|xcb_render_query_filters_cookie_t
typedef|typedef
struct|struct
name|xcb_render_query_filters_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_filters_cookie_t
name|xcb_render_query_filters_cookie_t
typedef|;
comment|/** Opcode for xcb_render_query_filters. */
DECL|macro|XCB_RENDER_QUERY_FILTERS
define|#
directive|define
name|XCB_RENDER_QUERY_FILTERS
value|29
comment|/**  * @brief xcb_render_query_filters_request_t  **/
DECL|struct|xcb_render_query_filters_request_t
typedef|typedef
struct|struct
name|xcb_render_query_filters_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|drawable
name|xcb_drawable_t
name|drawable
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_filters_request_t
name|xcb_render_query_filters_request_t
typedef|;
comment|/**  * @brief xcb_render_query_filters_reply_t  **/
DECL|struct|xcb_render_query_filters_reply_t
typedef|typedef
struct|struct
name|xcb_render_query_filters_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint32_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|num_aliases
name|uint32_t
name|num_aliases
decl_stmt|;
comment|/**<  */
DECL|member|num_filters
name|uint32_t
name|num_filters
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|16
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_query_filters_reply_t
name|xcb_render_query_filters_reply_t
typedef|;
comment|/** Opcode for xcb_render_set_picture_filter. */
DECL|macro|XCB_RENDER_SET_PICTURE_FILTER
define|#
directive|define
name|XCB_RENDER_SET_PICTURE_FILTER
value|30
comment|/**  * @brief xcb_render_set_picture_filter_request_t  **/
DECL|struct|xcb_render_set_picture_filter_request_t
typedef|typedef
struct|struct
name|xcb_render_set_picture_filter_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|filter_len
name|uint16_t
name|filter_len
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_set_picture_filter_request_t
name|xcb_render_set_picture_filter_request_t
typedef|;
comment|/**  * @brief xcb_render_animcursorelt_t  **/
DECL|struct|xcb_render_animcursorelt_t
typedef|typedef
struct|struct
name|xcb_render_animcursorelt_t
block|{
DECL|member|cursor
name|xcb_cursor_t
name|cursor
decl_stmt|;
comment|/**<  */
DECL|member|delay
name|uint32_t
name|delay
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_animcursorelt_t
name|xcb_render_animcursorelt_t
typedef|;
comment|/**  * @brief xcb_render_animcursorelt_iterator_t  **/
DECL|struct|xcb_render_animcursorelt_iterator_t
typedef|typedef
struct|struct
name|xcb_render_animcursorelt_iterator_t
block|{
DECL|member|data
name|xcb_render_animcursorelt_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_animcursorelt_iterator_t
name|xcb_render_animcursorelt_iterator_t
typedef|;
comment|/** Opcode for xcb_render_create_anim_cursor. */
DECL|macro|XCB_RENDER_CREATE_ANIM_CURSOR
define|#
directive|define
name|XCB_RENDER_CREATE_ANIM_CURSOR
value|31
comment|/**  * @brief xcb_render_create_anim_cursor_request_t  **/
DECL|struct|xcb_render_create_anim_cursor_request_t
typedef|typedef
struct|struct
name|xcb_render_create_anim_cursor_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|cid
name|xcb_cursor_t
name|cid
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_anim_cursor_request_t
name|xcb_render_create_anim_cursor_request_t
typedef|;
comment|/**  * @brief xcb_render_spanfix_t  **/
DECL|struct|xcb_render_spanfix_t
typedef|typedef
struct|struct
name|xcb_render_spanfix_t
block|{
DECL|member|l
name|xcb_render_fixed_t
name|l
decl_stmt|;
comment|/**<  */
DECL|member|r
name|xcb_render_fixed_t
name|r
decl_stmt|;
comment|/**<  */
DECL|member|y
name|xcb_render_fixed_t
name|y
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_spanfix_t
name|xcb_render_spanfix_t
typedef|;
comment|/**  * @brief xcb_render_spanfix_iterator_t  **/
DECL|struct|xcb_render_spanfix_iterator_t
typedef|typedef
struct|struct
name|xcb_render_spanfix_iterator_t
block|{
DECL|member|data
name|xcb_render_spanfix_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_spanfix_iterator_t
name|xcb_render_spanfix_iterator_t
typedef|;
comment|/**  * @brief xcb_render_trap_t  **/
DECL|struct|xcb_render_trap_t
typedef|typedef
struct|struct
name|xcb_render_trap_t
block|{
DECL|member|top
name|xcb_render_spanfix_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|bot
name|xcb_render_spanfix_t
name|bot
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_trap_t
name|xcb_render_trap_t
typedef|;
comment|/**  * @brief xcb_render_trap_iterator_t  **/
DECL|struct|xcb_render_trap_iterator_t
typedef|typedef
struct|struct
name|xcb_render_trap_iterator_t
block|{
DECL|member|data
name|xcb_render_trap_t
modifier|*
name|data
decl_stmt|;
comment|/**<  */
DECL|member|rem
name|int
name|rem
decl_stmt|;
comment|/**<  */
DECL|member|index
name|int
name|index
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_trap_iterator_t
name|xcb_render_trap_iterator_t
typedef|;
comment|/** Opcode for xcb_render_add_traps. */
DECL|macro|XCB_RENDER_ADD_TRAPS
define|#
directive|define
name|XCB_RENDER_ADD_TRAPS
value|32
comment|/**  * @brief xcb_render_add_traps_request_t  **/
DECL|struct|xcb_render_add_traps_request_t
typedef|typedef
struct|struct
name|xcb_render_add_traps_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|x_off
name|int16_t
name|x_off
decl_stmt|;
comment|/**<  */
DECL|member|y_off
name|int16_t
name|y_off
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_add_traps_request_t
name|xcb_render_add_traps_request_t
typedef|;
comment|/** Opcode for xcb_render_create_solid_fill. */
DECL|macro|XCB_RENDER_CREATE_SOLID_FILL
define|#
directive|define
name|XCB_RENDER_CREATE_SOLID_FILL
value|33
comment|/**  * @brief xcb_render_create_solid_fill_request_t  **/
DECL|struct|xcb_render_create_solid_fill_request_t
typedef|typedef
struct|struct
name|xcb_render_create_solid_fill_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|color
name|xcb_render_color_t
name|color
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_solid_fill_request_t
name|xcb_render_create_solid_fill_request_t
typedef|;
comment|/** Opcode for xcb_render_create_linear_gradient. */
DECL|macro|XCB_RENDER_CREATE_LINEAR_GRADIENT
define|#
directive|define
name|XCB_RENDER_CREATE_LINEAR_GRADIENT
value|34
comment|/**  * @brief xcb_render_create_linear_gradient_request_t  **/
DECL|struct|xcb_render_create_linear_gradient_request_t
typedef|typedef
struct|struct
name|xcb_render_create_linear_gradient_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|p1
name|xcb_render_pointfix_t
name|p1
decl_stmt|;
comment|/**<  */
DECL|member|p2
name|xcb_render_pointfix_t
name|p2
decl_stmt|;
comment|/**<  */
DECL|member|num_stops
name|uint32_t
name|num_stops
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_linear_gradient_request_t
name|xcb_render_create_linear_gradient_request_t
typedef|;
comment|/** Opcode for xcb_render_create_radial_gradient. */
DECL|macro|XCB_RENDER_CREATE_RADIAL_GRADIENT
define|#
directive|define
name|XCB_RENDER_CREATE_RADIAL_GRADIENT
value|35
comment|/**  * @brief xcb_render_create_radial_gradient_request_t  **/
DECL|struct|xcb_render_create_radial_gradient_request_t
typedef|typedef
struct|struct
name|xcb_render_create_radial_gradient_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|inner
name|xcb_render_pointfix_t
name|inner
decl_stmt|;
comment|/**<  */
DECL|member|outer
name|xcb_render_pointfix_t
name|outer
decl_stmt|;
comment|/**<  */
DECL|member|inner_radius
name|xcb_render_fixed_t
name|inner_radius
decl_stmt|;
comment|/**<  */
DECL|member|outer_radius
name|xcb_render_fixed_t
name|outer_radius
decl_stmt|;
comment|/**<  */
DECL|member|num_stops
name|uint32_t
name|num_stops
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_radial_gradient_request_t
name|xcb_render_create_radial_gradient_request_t
typedef|;
comment|/** Opcode for xcb_render_create_conical_gradient. */
DECL|macro|XCB_RENDER_CREATE_CONICAL_GRADIENT
define|#
directive|define
name|XCB_RENDER_CREATE_CONICAL_GRADIENT
value|36
comment|/**  * @brief xcb_render_create_conical_gradient_request_t  **/
DECL|struct|xcb_render_create_conical_gradient_request_t
typedef|typedef
struct|struct
name|xcb_render_create_conical_gradient_request_t
block|{
DECL|member|major_opcode
name|uint8_t
name|major_opcode
decl_stmt|;
comment|/**<  */
DECL|member|minor_opcode
name|uint8_t
name|minor_opcode
decl_stmt|;
comment|/**<  */
DECL|member|length
name|uint16_t
name|length
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
DECL|member|center
name|xcb_render_pointfix_t
name|center
decl_stmt|;
comment|/**<  */
DECL|member|angle
name|xcb_render_fixed_t
name|angle
decl_stmt|;
comment|/**<  */
DECL|member|num_stops
name|uint32_t
name|num_stops
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_render_create_conical_gradient_request_t
name|xcb_render_create_conical_gradient_request_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_glyph_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_glyph_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_glyph_next  **   ** @param xcb_render_glyph_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_glyph_next
parameter_list|(
name|xcb_render_glyph_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_glyph_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_glyph_end  **   ** @param xcb_render_glyph_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_glyph_end
parameter_list|(
name|xcb_render_glyph_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_glyphset_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_glyphset_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_glyphset_next  **   ** @param xcb_render_glyphset_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_glyphset_next
parameter_list|(
name|xcb_render_glyphset_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_glyphset_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_glyphset_end  **   ** @param xcb_render_glyphset_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_glyphset_end
parameter_list|(
name|xcb_render_glyphset_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_picture_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_picture_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_picture_next  **   ** @param xcb_render_picture_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_picture_next
parameter_list|(
name|xcb_render_picture_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_picture_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_picture_end  **   ** @param xcb_render_picture_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_picture_end
parameter_list|(
name|xcb_render_picture_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_pictformat_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_pictformat_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_pictformat_next  **   ** @param xcb_render_pictformat_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_pictformat_next
parameter_list|(
name|xcb_render_pictformat_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_pictformat_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_pictformat_end  **   ** @param xcb_render_pictformat_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_pictformat_end
parameter_list|(
name|xcb_render_pictformat_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_fixed_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_fixed_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_fixed_next  **   ** @param xcb_render_fixed_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_fixed_next
parameter_list|(
name|xcb_render_fixed_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_fixed_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_fixed_end  **   ** @param xcb_render_fixed_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_fixed_end
parameter_list|(
name|xcb_render_fixed_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_directformat_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_directformat_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_directformat_next  **   ** @param xcb_render_directformat_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_directformat_next
parameter_list|(
name|xcb_render_directformat_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_directformat_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_directformat_end  **   ** @param xcb_render_directformat_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_directformat_end
parameter_list|(
name|xcb_render_directformat_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_pictforminfo_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_pictforminfo_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_pictforminfo_next  **   ** @param xcb_render_pictforminfo_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_pictforminfo_next
parameter_list|(
name|xcb_render_pictforminfo_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_pictforminfo_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_pictforminfo_end  **   ** @param xcb_render_pictforminfo_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_pictforminfo_end
parameter_list|(
name|xcb_render_pictforminfo_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_pictvisual_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_pictvisual_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_pictvisual_next  **   ** @param xcb_render_pictvisual_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_pictvisual_next
parameter_list|(
name|xcb_render_pictvisual_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_pictvisual_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_pictvisual_end  **   ** @param xcb_render_pictvisual_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_pictvisual_end
parameter_list|(
name|xcb_render_pictvisual_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_pictvisual_t * xcb_render_pictdepth_visuals  **   ** @param const xcb_render_pictdepth_t *R  ** @returns xcb_render_pictvisual_t *  **  *****************************************************************************/
name|xcb_render_pictvisual_t
modifier|*
name|xcb_render_pictdepth_visuals
parameter_list|(
specifier|const
name|xcb_render_pictdepth_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_pictdepth_visuals_length  **   ** @param const xcb_render_pictdepth_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_pictdepth_visuals_length
parameter_list|(
specifier|const
name|xcb_render_pictdepth_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_pictvisual_iterator_t xcb_render_pictdepth_visuals_iterator  **   ** @param const xcb_render_pictdepth_t *R  ** @returns xcb_render_pictvisual_iterator_t  **  *****************************************************************************/
name|xcb_render_pictvisual_iterator_t
name|xcb_render_pictdepth_visuals_iterator
parameter_list|(
specifier|const
name|xcb_render_pictdepth_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_pictdepth_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_pictdepth_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_pictdepth_next  **   ** @param xcb_render_pictdepth_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_pictdepth_next
parameter_list|(
name|xcb_render_pictdepth_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_pictdepth_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_pictdepth_end  **   ** @param xcb_render_pictdepth_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_pictdepth_end
parameter_list|(
name|xcb_render_pictdepth_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_pictscreen_depths_length  **   ** @param const xcb_render_pictscreen_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_pictscreen_depths_length
parameter_list|(
specifier|const
name|xcb_render_pictscreen_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_pictdepth_iterator_t xcb_render_pictscreen_depths_iterator  **   ** @param const xcb_render_pictscreen_t *R  ** @returns xcb_render_pictdepth_iterator_t  **  *****************************************************************************/
name|xcb_render_pictdepth_iterator_t
name|xcb_render_pictscreen_depths_iterator
parameter_list|(
specifier|const
name|xcb_render_pictscreen_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_pictscreen_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_pictscreen_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_pictscreen_next  **   ** @param xcb_render_pictscreen_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_pictscreen_next
parameter_list|(
name|xcb_render_pictscreen_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_pictscreen_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_pictscreen_end  **   ** @param xcb_render_pictscreen_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_pictscreen_end
parameter_list|(
name|xcb_render_pictscreen_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_indexvalue_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_indexvalue_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_indexvalue_next  **   ** @param xcb_render_indexvalue_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_indexvalue_next
parameter_list|(
name|xcb_render_indexvalue_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_indexvalue_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_indexvalue_end  **   ** @param xcb_render_indexvalue_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_indexvalue_end
parameter_list|(
name|xcb_render_indexvalue_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_color_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_color_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_color_next  **   ** @param xcb_render_color_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_color_next
parameter_list|(
name|xcb_render_color_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_color_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_color_end  **   ** @param xcb_render_color_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_color_end
parameter_list|(
name|xcb_render_color_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_pointfix_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_pointfix_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_pointfix_next  **   ** @param xcb_render_pointfix_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_pointfix_next
parameter_list|(
name|xcb_render_pointfix_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_pointfix_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_pointfix_end  **   ** @param xcb_render_pointfix_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_pointfix_end
parameter_list|(
name|xcb_render_pointfix_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_linefix_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_linefix_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_linefix_next  **   ** @param xcb_render_linefix_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_linefix_next
parameter_list|(
name|xcb_render_linefix_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_linefix_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_linefix_end  **   ** @param xcb_render_linefix_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_linefix_end
parameter_list|(
name|xcb_render_linefix_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_triangle_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_triangle_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_triangle_next  **   ** @param xcb_render_triangle_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_triangle_next
parameter_list|(
name|xcb_render_triangle_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_triangle_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_triangle_end  **   ** @param xcb_render_triangle_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_triangle_end
parameter_list|(
name|xcb_render_triangle_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_trapezoid_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_trapezoid_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_trapezoid_next  **   ** @param xcb_render_trapezoid_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_trapezoid_next
parameter_list|(
name|xcb_render_trapezoid_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_trapezoid_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_trapezoid_end  **   ** @param xcb_render_trapezoid_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_trapezoid_end
parameter_list|(
name|xcb_render_trapezoid_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_glyphinfo_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_glyphinfo_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_glyphinfo_next  **   ** @param xcb_render_glyphinfo_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_glyphinfo_next
parameter_list|(
name|xcb_render_glyphinfo_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_glyphinfo_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_glyphinfo_end  **   ** @param xcb_render_glyphinfo_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_glyphinfo_end
parameter_list|(
name|xcb_render_glyphinfo_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_render_query_version_cookie_t xcb_render_query_version  **   ** @param xcb_connection_t *c  ** @param uint32_t          client_major_version  ** @param uint32_t          client_minor_version  ** @returns xcb_render_query_version_cookie_t  **  *****************************************************************************/
name|xcb_render_query_version_cookie_t
name|xcb_render_query_version
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|client_major_version
comment|/**< */
parameter_list|,
name|uint32_t
name|client_minor_version
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_render_query_version_cookie_t xcb_render_query_version_unchecked  **   ** @param xcb_connection_t *c  ** @param uint32_t          client_major_version  ** @param uint32_t          client_minor_version  ** @returns xcb_render_query_version_cookie_t  **  *****************************************************************************/
name|xcb_render_query_version_cookie_t
name|xcb_render_query_version_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|client_major_version
comment|/**< */
parameter_list|,
name|uint32_t
name|client_minor_version
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_render_query_version_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_render_query_version_reply_t * xcb_render_query_version_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_render_query_version_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_render_query_version_reply_t *  **  *****************************************************************************/
name|xcb_render_query_version_reply_t
modifier|*
name|xcb_render_query_version_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_query_version_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_render_query_pict_formats_cookie_t xcb_render_query_pict_formats  **   ** @param xcb_connection_t *c  ** @returns xcb_render_query_pict_formats_cookie_t  **  *****************************************************************************/
name|xcb_render_query_pict_formats_cookie_t
name|xcb_render_query_pict_formats
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_render_query_pict_formats_cookie_t xcb_render_query_pict_formats_unchecked  **   ** @param xcb_connection_t *c  ** @returns xcb_render_query_pict_formats_cookie_t  **  *****************************************************************************/
name|xcb_render_query_pict_formats_cookie_t
name|xcb_render_query_pict_formats_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_pictforminfo_t * xcb_render_query_pict_formats_formats  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns xcb_render_pictforminfo_t *  **  *****************************************************************************/
name|xcb_render_pictforminfo_t
modifier|*
name|xcb_render_query_pict_formats_formats
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_query_pict_formats_formats_length  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_query_pict_formats_formats_length
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_pictforminfo_iterator_t xcb_render_query_pict_formats_formats_iterator  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns xcb_render_pictforminfo_iterator_t  **  *****************************************************************************/
name|xcb_render_pictforminfo_iterator_t
name|xcb_render_query_pict_formats_formats_iterator
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_query_pict_formats_screens_length  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_query_pict_formats_screens_length
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_pictscreen_iterator_t xcb_render_query_pict_formats_screens_iterator  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns xcb_render_pictscreen_iterator_t  **  *****************************************************************************/
name|xcb_render_pictscreen_iterator_t
name|xcb_render_query_pict_formats_screens_iterator
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint32_t * xcb_render_query_pict_formats_subpixels  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns uint32_t *  **  *****************************************************************************/
name|uint32_t
modifier|*
name|xcb_render_query_pict_formats_subpixels
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_query_pict_formats_subpixels_length  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_query_pict_formats_subpixels_length
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_query_pict_formats_subpixels_end  **   ** @param const xcb_render_query_pict_formats_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_query_pict_formats_subpixels_end
parameter_list|(
specifier|const
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_render_query_pict_formats_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_render_query_pict_formats_reply_t * xcb_render_query_pict_formats_reply  **   ** @param xcb_connection_t                        *c  ** @param xcb_render_query_pict_formats_cookie_t   cookie  ** @param xcb_generic_error_t                    **e  ** @returns xcb_render_query_pict_formats_reply_t *  **  *****************************************************************************/
name|xcb_render_query_pict_formats_reply_t
modifier|*
name|xcb_render_query_pict_formats_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_query_pict_formats_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_render_query_pict_index_values_cookie_t xcb_render_query_pict_index_values  **   ** @param xcb_connection_t        *c  ** @param xcb_render_pictformat_t  format  ** @returns xcb_render_query_pict_index_values_cookie_t  **  *****************************************************************************/
name|xcb_render_query_pict_index_values_cookie_t
name|xcb_render_query_pict_index_values
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|format
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_render_query_pict_index_values_cookie_t xcb_render_query_pict_index_values_unchecked  **   ** @param xcb_connection_t        *c  ** @param xcb_render_pictformat_t  format  ** @returns xcb_render_query_pict_index_values_cookie_t  **  *****************************************************************************/
name|xcb_render_query_pict_index_values_cookie_t
name|xcb_render_query_pict_index_values_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|format
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_indexvalue_t * xcb_render_query_pict_index_values_values  **   ** @param const xcb_render_query_pict_index_values_reply_t *R  ** @returns xcb_render_indexvalue_t *  **  *****************************************************************************/
name|xcb_render_indexvalue_t
modifier|*
name|xcb_render_query_pict_index_values_values
parameter_list|(
specifier|const
name|xcb_render_query_pict_index_values_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_query_pict_index_values_values_length  **   ** @param const xcb_render_query_pict_index_values_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_query_pict_index_values_values_length
parameter_list|(
specifier|const
name|xcb_render_query_pict_index_values_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_indexvalue_iterator_t xcb_render_query_pict_index_values_values_iterator  **   ** @param const xcb_render_query_pict_index_values_reply_t *R  ** @returns xcb_render_indexvalue_iterator_t  **  *****************************************************************************/
name|xcb_render_indexvalue_iterator_t
name|xcb_render_query_pict_index_values_values_iterator
parameter_list|(
specifier|const
name|xcb_render_query_pict_index_values_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_render_query_pict_index_values_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_render_query_pict_index_values_reply_t * xcb_render_query_pict_index_values_reply  **   ** @param xcb_connection_t                             *c  ** @param xcb_render_query_pict_index_values_cookie_t   cookie  ** @param xcb_generic_error_t                         **e  ** @returns xcb_render_query_pict_index_values_reply_t *  **  *****************************************************************************/
name|xcb_render_query_pict_index_values_reply_t
modifier|*
name|xcb_render_query_pict_index_values_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_query_pict_index_values_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_picture_checked  **   ** @param xcb_connection_t        *c  ** @param xcb_render_picture_t     pid  ** @param xcb_drawable_t           drawable  ** @param xcb_render_pictformat_t  format  ** @param uint32_t                 value_mask  ** @param const uint32_t          *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_picture_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|pid
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|format
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_picture  **   ** @param xcb_connection_t        *c  ** @param xcb_render_picture_t     pid  ** @param xcb_drawable_t           drawable  ** @param xcb_render_pictformat_t  format  ** @param uint32_t                 value_mask  ** @param const uint32_t          *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_picture
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|pid
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|format
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_change_picture_checked  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @param uint32_t              value_mask  ** @param const uint32_t       *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_change_picture_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_change_picture  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @param uint32_t              value_mask  ** @param const uint32_t       *value_list  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_change_picture
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|uint32_t
name|value_mask
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|value_list
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_set_picture_clip_rectangles_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_render_picture_t   picture  ** @param int16_t                clip_x_origin  ** @param int16_t                clip_y_origin  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_set_picture_clip_rectangles_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|int16_t
name|clip_x_origin
comment|/**< */
parameter_list|,
name|int16_t
name|clip_y_origin
comment|/**< */
parameter_list|,
name|uint32_t
name|rectangles_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_rectangle_t
modifier|*
name|rectangles
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_set_picture_clip_rectangles  **   ** @param xcb_connection_t      *c  ** @param xcb_render_picture_t   picture  ** @param int16_t                clip_x_origin  ** @param int16_t                clip_y_origin  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_set_picture_clip_rectangles
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|int16_t
name|clip_x_origin
comment|/**< */
parameter_list|,
name|int16_t
name|clip_y_origin
comment|/**< */
parameter_list|,
name|uint32_t
name|rectangles_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_rectangle_t
modifier|*
name|rectangles
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_free_picture_checked  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_free_picture_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_free_picture  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_free_picture
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_checked  **   ** @param xcb_connection_t     *c  ** @param uint8_t               op  ** @param xcb_render_picture_t  src  ** @param xcb_render_picture_t  mask  ** @param xcb_render_picture_t  dst  ** @param int16_t               src_x  ** @param int16_t               src_y  ** @param int16_t               mask_x  ** @param int16_t               mask_y  ** @param int16_t               dst_x  ** @param int16_t               dst_y  ** @param uint16_t              width  ** @param uint16_t              height  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|mask
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|int16_t
name|mask_x
comment|/**< */
parameter_list|,
name|int16_t
name|mask_y
comment|/**< */
parameter_list|,
name|int16_t
name|dst_x
comment|/**< */
parameter_list|,
name|int16_t
name|dst_y
comment|/**< */
parameter_list|,
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite  **   ** @param xcb_connection_t     *c  ** @param uint8_t               op  ** @param xcb_render_picture_t  src  ** @param xcb_render_picture_t  mask  ** @param xcb_render_picture_t  dst  ** @param int16_t               src_x  ** @param int16_t               src_y  ** @param int16_t               mask_x  ** @param int16_t               mask_y  ** @param int16_t               dst_x  ** @param int16_t               dst_y  ** @param uint16_t              width  ** @param uint16_t              height  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|mask
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|int16_t
name|mask_x
comment|/**< */
parameter_list|,
name|int16_t
name|mask_y
comment|/**< */
parameter_list|,
name|int16_t
name|dst_x
comment|/**< */
parameter_list|,
name|int16_t
name|dst_y
comment|/**< */
parameter_list|,
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_trapezoids_checked  **   ** @param xcb_connection_t             *c  ** @param uint8_t                       op  ** @param xcb_render_picture_t          src  ** @param xcb_render_picture_t          dst  ** @param xcb_render_pictformat_t       mask_format  ** @param int16_t                       src_x  ** @param int16_t                       src_y  ** @param uint32_t                      traps_len  ** @param const xcb_render_trapezoid_t *traps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_trapezoids_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|traps_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_trapezoid_t
modifier|*
name|traps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_trapezoids  **   ** @param xcb_connection_t             *c  ** @param uint8_t                       op  ** @param xcb_render_picture_t          src  ** @param xcb_render_picture_t          dst  ** @param xcb_render_pictformat_t       mask_format  ** @param int16_t                       src_x  ** @param int16_t                       src_y  ** @param uint32_t                      traps_len  ** @param const xcb_render_trapezoid_t *traps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_trapezoids
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|traps_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_trapezoid_t
modifier|*
name|traps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_triangles_checked  **   ** @param xcb_connection_t            *c  ** @param uint8_t                      op  ** @param xcb_render_picture_t         src  ** @param xcb_render_picture_t         dst  ** @param xcb_render_pictformat_t      mask_format  ** @param int16_t                      src_x  ** @param int16_t                      src_y  ** @param uint32_t                     triangles_len  ** @param const xcb_render_triangle_t *triangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_triangles_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|triangles_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_triangle_t
modifier|*
name|triangles
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_triangles  **   ** @param xcb_connection_t            *c  ** @param uint8_t                      op  ** @param xcb_render_picture_t         src  ** @param xcb_render_picture_t         dst  ** @param xcb_render_pictformat_t      mask_format  ** @param int16_t                      src_x  ** @param int16_t                      src_y  ** @param uint32_t                     triangles_len  ** @param const xcb_render_triangle_t *triangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_triangles
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|triangles_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_triangle_t
modifier|*
name|triangles
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_tri_strip_checked  **   ** @param xcb_connection_t            *c  ** @param uint8_t                      op  ** @param xcb_render_picture_t         src  ** @param xcb_render_picture_t         dst  ** @param xcb_render_pictformat_t      mask_format  ** @param int16_t                      src_x  ** @param int16_t                      src_y  ** @param uint32_t                     points_len  ** @param const xcb_render_pointfix_t *points  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_tri_strip_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|points_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_pointfix_t
modifier|*
name|points
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_tri_strip  **   ** @param xcb_connection_t            *c  ** @param uint8_t                      op  ** @param xcb_render_picture_t         src  ** @param xcb_render_picture_t         dst  ** @param xcb_render_pictformat_t      mask_format  ** @param int16_t                      src_x  ** @param int16_t                      src_y  ** @param uint32_t                     points_len  ** @param const xcb_render_pointfix_t *points  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_tri_strip
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|points_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_pointfix_t
modifier|*
name|points
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_tri_fan_checked  **   ** @param xcb_connection_t            *c  ** @param uint8_t                      op  ** @param xcb_render_picture_t         src  ** @param xcb_render_picture_t         dst  ** @param xcb_render_pictformat_t      mask_format  ** @param int16_t                      src_x  ** @param int16_t                      src_y  ** @param uint32_t                     points_len  ** @param const xcb_render_pointfix_t *points  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_tri_fan_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|points_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_pointfix_t
modifier|*
name|points
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_tri_fan  **   ** @param xcb_connection_t            *c  ** @param uint8_t                      op  ** @param xcb_render_picture_t         src  ** @param xcb_render_picture_t         dst  ** @param xcb_render_pictformat_t      mask_format  ** @param int16_t                      src_x  ** @param int16_t                      src_y  ** @param uint32_t                     points_len  ** @param const xcb_render_pointfix_t *points  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_tri_fan
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|points_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_pointfix_t
modifier|*
name|points
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_glyph_set_checked  **   ** @param xcb_connection_t        *c  ** @param xcb_render_glyphset_t    gsid  ** @param xcb_render_pictformat_t  format  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_glyph_set_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|gsid
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|format
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_glyph_set  **   ** @param xcb_connection_t        *c  ** @param xcb_render_glyphset_t    gsid  ** @param xcb_render_pictformat_t  format  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_glyph_set
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|gsid
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|format
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_reference_glyph_set_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_render_glyphset_t  gsid  ** @param xcb_render_glyphset_t  existing  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_reference_glyph_set_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|gsid
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|existing
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_reference_glyph_set  **   ** @param xcb_connection_t      *c  ** @param xcb_render_glyphset_t  gsid  ** @param xcb_render_glyphset_t  existing  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_reference_glyph_set
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|gsid
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|existing
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_free_glyph_set_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_render_glyphset_t  glyphset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_free_glyph_set_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_free_glyph_set  **   ** @param xcb_connection_t      *c  ** @param xcb_render_glyphset_t  glyphset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_free_glyph_set
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_add_glyphs_checked  **   ** @param xcb_connection_t             *c  ** @param xcb_render_glyphset_t         glyphset  ** @param uint32_t                      glyphs_len  ** @param const uint32_t               *glyphids  ** @param const xcb_render_glyphinfo_t *glyphs  ** @param uint32_t                      data_len  ** @param const uint8_t                *data  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_add_glyphs_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphs_len
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|glyphids
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_glyphinfo_t
modifier|*
name|glyphs
comment|/**< */
parameter_list|,
name|uint32_t
name|data_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|data
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_add_glyphs  **   ** @param xcb_connection_t             *c  ** @param xcb_render_glyphset_t         glyphset  ** @param uint32_t                      glyphs_len  ** @param const uint32_t               *glyphids  ** @param const xcb_render_glyphinfo_t *glyphs  ** @param uint32_t                      data_len  ** @param const uint8_t                *data  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_add_glyphs
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphs_len
comment|/**< */
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|glyphids
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_glyphinfo_t
modifier|*
name|glyphs
comment|/**< */
parameter_list|,
name|uint32_t
name|data_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|data
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_free_glyphs_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_render_glyphset_t     glyphset  ** @param uint32_t                  glyphs_len  ** @param const xcb_render_glyph_t *glyphs  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_free_glyphs_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphs_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_glyph_t
modifier|*
name|glyphs
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_free_glyphs  **   ** @param xcb_connection_t         *c  ** @param xcb_render_glyphset_t     glyphset  ** @param uint32_t                  glyphs_len  ** @param const xcb_render_glyph_t *glyphs  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_free_glyphs
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphs_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_glyph_t
modifier|*
name|glyphs
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_glyphs_8_checked  **   ** @param xcb_connection_t        *c  ** @param uint8_t                  op  ** @param xcb_render_picture_t     src  ** @param xcb_render_picture_t     dst  ** @param xcb_render_pictformat_t  mask_format  ** @param xcb_render_glyphset_t    glyphset  ** @param int16_t                  src_x  ** @param int16_t                  src_y  ** @param uint32_t                 glyphcmds_len  ** @param const uint8_t           *glyphcmds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_glyphs_8_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphcmds_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|glyphcmds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_glyphs_8  **   ** @param xcb_connection_t        *c  ** @param uint8_t                  op  ** @param xcb_render_picture_t     src  ** @param xcb_render_picture_t     dst  ** @param xcb_render_pictformat_t  mask_format  ** @param xcb_render_glyphset_t    glyphset  ** @param int16_t                  src_x  ** @param int16_t                  src_y  ** @param uint32_t                 glyphcmds_len  ** @param const uint8_t           *glyphcmds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_glyphs_8
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphcmds_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|glyphcmds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_glyphs_16_checked  **   ** @param xcb_connection_t        *c  ** @param uint8_t                  op  ** @param xcb_render_picture_t     src  ** @param xcb_render_picture_t     dst  ** @param xcb_render_pictformat_t  mask_format  ** @param xcb_render_glyphset_t    glyphset  ** @param int16_t                  src_x  ** @param int16_t                  src_y  ** @param uint32_t                 glyphcmds_len  ** @param const uint8_t           *glyphcmds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_glyphs_16_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphcmds_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|glyphcmds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_glyphs_16  **   ** @param xcb_connection_t        *c  ** @param uint8_t                  op  ** @param xcb_render_picture_t     src  ** @param xcb_render_picture_t     dst  ** @param xcb_render_pictformat_t  mask_format  ** @param xcb_render_glyphset_t    glyphset  ** @param int16_t                  src_x  ** @param int16_t                  src_y  ** @param uint32_t                 glyphcmds_len  ** @param const uint8_t           *glyphcmds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_glyphs_16
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphcmds_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|glyphcmds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_glyphs_32_checked  **   ** @param xcb_connection_t        *c  ** @param uint8_t                  op  ** @param xcb_render_picture_t     src  ** @param xcb_render_picture_t     dst  ** @param xcb_render_pictformat_t  mask_format  ** @param xcb_render_glyphset_t    glyphset  ** @param int16_t                  src_x  ** @param int16_t                  src_y  ** @param uint32_t                 glyphcmds_len  ** @param const uint8_t           *glyphcmds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_glyphs_32_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphcmds_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|glyphcmds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_composite_glyphs_32  **   ** @param xcb_connection_t        *c  ** @param uint8_t                  op  ** @param xcb_render_picture_t     src  ** @param xcb_render_picture_t     dst  ** @param xcb_render_pictformat_t  mask_format  ** @param xcb_render_glyphset_t    glyphset  ** @param int16_t                  src_x  ** @param int16_t                  src_y  ** @param uint32_t                 glyphcmds_len  ** @param const uint8_t           *glyphcmds  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_composite_glyphs_32
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|src
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_pictformat_t
name|mask_format
comment|/**< */
parameter_list|,
name|xcb_render_glyphset_t
name|glyphset
comment|/**< */
parameter_list|,
name|int16_t
name|src_x
comment|/**< */
parameter_list|,
name|int16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint32_t
name|glyphcmds_len
comment|/**< */
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|glyphcmds
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_fill_rectangles_checked  **   ** @param xcb_connection_t      *c  ** @param uint8_t                op  ** @param xcb_render_picture_t   dst  ** @param xcb_render_color_t     color  ** @param uint32_t               rects_len  ** @param const xcb_rectangle_t *rects  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_fill_rectangles_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_color_t
name|color
comment|/**< */
parameter_list|,
name|uint32_t
name|rects_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_rectangle_t
modifier|*
name|rects
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_fill_rectangles  **   ** @param xcb_connection_t      *c  ** @param uint8_t                op  ** @param xcb_render_picture_t   dst  ** @param xcb_render_color_t     color  ** @param uint32_t               rects_len  ** @param const xcb_rectangle_t *rects  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_fill_rectangles
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|op
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|dst
comment|/**< */
parameter_list|,
name|xcb_render_color_t
name|color
comment|/**< */
parameter_list|,
name|uint32_t
name|rects_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_rectangle_t
modifier|*
name|rects
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_cursor_checked  **   ** @param xcb_connection_t     *c  ** @param xcb_cursor_t          cid  ** @param xcb_render_picture_t  source  ** @param uint16_t              x  ** @param uint16_t              y  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_cursor_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cid
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|source
comment|/**< */
parameter_list|,
name|uint16_t
name|x
comment|/**< */
parameter_list|,
name|uint16_t
name|y
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_cursor  **   ** @param xcb_connection_t     *c  ** @param xcb_cursor_t          cid  ** @param xcb_render_picture_t  source  ** @param uint16_t              x  ** @param uint16_t              y  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_cursor
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cid
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|source
comment|/**< */
parameter_list|,
name|uint16_t
name|x
comment|/**< */
parameter_list|,
name|uint16_t
name|y
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_transform_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_transform_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_transform_next  **   ** @param xcb_render_transform_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_transform_next
parameter_list|(
name|xcb_render_transform_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_transform_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_transform_end  **   ** @param xcb_render_transform_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_transform_end
parameter_list|(
name|xcb_render_transform_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_set_picture_transform_checked  **   ** @param xcb_connection_t       *c  ** @param xcb_render_picture_t    picture  ** @param xcb_render_transform_t  transform  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_set_picture_transform_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_transform_t
name|transform
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_set_picture_transform  **   ** @param xcb_connection_t       *c  ** @param xcb_render_picture_t    picture  ** @param xcb_render_transform_t  transform  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_set_picture_transform
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_transform_t
name|transform
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_render_query_filters_cookie_t xcb_render_query_filters  **   ** @param xcb_connection_t *c  ** @param xcb_drawable_t    drawable  ** @returns xcb_render_query_filters_cookie_t  **  *****************************************************************************/
name|xcb_render_query_filters_cookie_t
name|xcb_render_query_filters
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_render_query_filters_cookie_t xcb_render_query_filters_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_drawable_t    drawable  ** @returns xcb_render_query_filters_cookie_t  **  *****************************************************************************/
name|xcb_render_query_filters_cookie_t
name|xcb_render_query_filters_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint16_t * xcb_render_query_filters_aliases  **   ** @param const xcb_render_query_filters_reply_t *R  ** @returns uint16_t *  **  *****************************************************************************/
name|uint16_t
modifier|*
name|xcb_render_query_filters_aliases
parameter_list|(
specifier|const
name|xcb_render_query_filters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_query_filters_aliases_length  **   ** @param const xcb_render_query_filters_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_query_filters_aliases_length
parameter_list|(
specifier|const
name|xcb_render_query_filters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_query_filters_aliases_end  **   ** @param const xcb_render_query_filters_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_query_filters_aliases_end
parameter_list|(
specifier|const
name|xcb_render_query_filters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_render_query_filters_filters_length  **   ** @param const xcb_render_query_filters_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_render_query_filters_filters_length
parameter_list|(
specifier|const
name|xcb_render_query_filters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_str_iterator_t xcb_render_query_filters_filters_iterator  **   ** @param const xcb_render_query_filters_reply_t *R  ** @returns xcb_str_iterator_t  **  *****************************************************************************/
name|xcb_str_iterator_t
name|xcb_render_query_filters_filters_iterator
parameter_list|(
specifier|const
name|xcb_render_query_filters_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_render_query_filters_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_render_query_filters_reply_t * xcb_render_query_filters_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_render_query_filters_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_render_query_filters_reply_t *  **  *****************************************************************************/
name|xcb_render_query_filters_reply_t
modifier|*
name|xcb_render_query_filters_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_query_filters_cookie_t
name|cookie
comment|/**< */
parameter_list|,
name|xcb_generic_error_t
modifier|*
modifier|*
name|e
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_set_picture_filter_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param uint16_t                  filter_len  ** @param const char               *filter  ** @param uint32_t                  values_len  ** @param const xcb_render_fixed_t *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_set_picture_filter_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|uint16_t
name|filter_len
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|filter
comment|/**< */
parameter_list|,
name|uint32_t
name|values_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_set_picture_filter  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param uint16_t                  filter_len  ** @param const char               *filter  ** @param uint32_t                  values_len  ** @param const xcb_render_fixed_t *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_set_picture_filter
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|uint16_t
name|filter_len
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|filter
comment|/**< */
parameter_list|,
name|uint32_t
name|values_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_animcursorelt_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_animcursorelt_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_animcursorelt_next  **   ** @param xcb_render_animcursorelt_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_animcursorelt_next
parameter_list|(
name|xcb_render_animcursorelt_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_animcursorelt_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_animcursorelt_end  **   ** @param xcb_render_animcursorelt_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_animcursorelt_end
parameter_list|(
name|xcb_render_animcursorelt_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_anim_cursor_checked  **   ** @param xcb_connection_t                 *c  ** @param xcb_cursor_t                      cid  ** @param uint32_t                          cursors_len  ** @param const xcb_render_animcursorelt_t *cursors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_anim_cursor_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cid
comment|/**< */
parameter_list|,
name|uint32_t
name|cursors_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_animcursorelt_t
modifier|*
name|cursors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_anim_cursor  **   ** @param xcb_connection_t                 *c  ** @param xcb_cursor_t                      cid  ** @param uint32_t                          cursors_len  ** @param const xcb_render_animcursorelt_t *cursors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_anim_cursor
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cid
comment|/**< */
parameter_list|,
name|uint32_t
name|cursors_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_animcursorelt_t
modifier|*
name|cursors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_spanfix_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_spanfix_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_spanfix_next  **   ** @param xcb_render_spanfix_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_spanfix_next
parameter_list|(
name|xcb_render_spanfix_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_spanfix_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_spanfix_end  **   ** @param xcb_render_spanfix_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_spanfix_end
parameter_list|(
name|xcb_render_spanfix_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_render_trap_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_render_trap_t)  */
comment|/*****************************************************************************  **  ** void xcb_render_trap_next  **   ** @param xcb_render_trap_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_render_trap_next
parameter_list|(
name|xcb_render_trap_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_render_trap_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_render_trap_end  **   ** @param xcb_render_trap_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_render_trap_end
parameter_list|(
name|xcb_render_trap_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_add_traps_checked  **   ** @param xcb_connection_t        *c  ** @param xcb_render_picture_t     picture  ** @param int16_t                  x_off  ** @param int16_t                  y_off  ** @param uint32_t                 traps_len  ** @param const xcb_render_trap_t *traps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_add_traps_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|int16_t
name|x_off
comment|/**< */
parameter_list|,
name|int16_t
name|y_off
comment|/**< */
parameter_list|,
name|uint32_t
name|traps_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_trap_t
modifier|*
name|traps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_add_traps  **   ** @param xcb_connection_t        *c  ** @param xcb_render_picture_t     picture  ** @param int16_t                  x_off  ** @param int16_t                  y_off  ** @param uint32_t                 traps_len  ** @param const xcb_render_trap_t *traps  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_add_traps
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|int16_t
name|x_off
comment|/**< */
parameter_list|,
name|int16_t
name|y_off
comment|/**< */
parameter_list|,
name|uint32_t
name|traps_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_trap_t
modifier|*
name|traps
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_solid_fill_checked  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @param xcb_render_color_t    color  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_solid_fill_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_color_t
name|color
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_solid_fill  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @param xcb_render_color_t    color  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_solid_fill
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_color_t
name|color
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_linear_gradient_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param xcb_render_pointfix_t     p1  ** @param xcb_render_pointfix_t     p2  ** @param uint32_t                  num_stops  ** @param const xcb_render_fixed_t *stops  ** @param const xcb_render_color_t *colors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_linear_gradient_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|p1
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|p2
comment|/**< */
parameter_list|,
name|uint32_t
name|num_stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_color_t
modifier|*
name|colors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_linear_gradient  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param xcb_render_pointfix_t     p1  ** @param xcb_render_pointfix_t     p2  ** @param uint32_t                  num_stops  ** @param const xcb_render_fixed_t *stops  ** @param const xcb_render_color_t *colors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_linear_gradient
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|p1
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|p2
comment|/**< */
parameter_list|,
name|uint32_t
name|num_stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_color_t
modifier|*
name|colors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_radial_gradient_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param xcb_render_pointfix_t     inner  ** @param xcb_render_pointfix_t     outer  ** @param xcb_render_fixed_t        inner_radius  ** @param xcb_render_fixed_t        outer_radius  ** @param uint32_t                  num_stops  ** @param const xcb_render_fixed_t *stops  ** @param const xcb_render_color_t *colors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_radial_gradient_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|inner
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|outer
comment|/**< */
parameter_list|,
name|xcb_render_fixed_t
name|inner_radius
comment|/**< */
parameter_list|,
name|xcb_render_fixed_t
name|outer_radius
comment|/**< */
parameter_list|,
name|uint32_t
name|num_stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_color_t
modifier|*
name|colors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_radial_gradient  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param xcb_render_pointfix_t     inner  ** @param xcb_render_pointfix_t     outer  ** @param xcb_render_fixed_t        inner_radius  ** @param xcb_render_fixed_t        outer_radius  ** @param uint32_t                  num_stops  ** @param const xcb_render_fixed_t *stops  ** @param const xcb_render_color_t *colors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_radial_gradient
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|inner
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|outer
comment|/**< */
parameter_list|,
name|xcb_render_fixed_t
name|inner_radius
comment|/**< */
parameter_list|,
name|xcb_render_fixed_t
name|outer_radius
comment|/**< */
parameter_list|,
name|uint32_t
name|num_stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_color_t
modifier|*
name|colors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_conical_gradient_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param xcb_render_pointfix_t     center  ** @param xcb_render_fixed_t        angle  ** @param uint32_t                  num_stops  ** @param const xcb_render_fixed_t *stops  ** @param const xcb_render_color_t *colors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_conical_gradient_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|center
comment|/**< */
parameter_list|,
name|xcb_render_fixed_t
name|angle
comment|/**< */
parameter_list|,
name|uint32_t
name|num_stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_color_t
modifier|*
name|colors
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_render_create_conical_gradient  **   ** @param xcb_connection_t         *c  ** @param xcb_render_picture_t      picture  ** @param xcb_render_pointfix_t     center  ** @param xcb_render_fixed_t        angle  ** @param uint32_t                  num_stops  ** @param const xcb_render_fixed_t *stops  ** @param const xcb_render_color_t *colors  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_render_create_conical_gradient
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|,
name|xcb_render_pointfix_t
name|center
comment|/**< */
parameter_list|,
name|xcb_render_fixed_t
name|angle
comment|/**< */
parameter_list|,
name|uint32_t
name|num_stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|stops
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_color_t
modifier|*
name|colors
comment|/**< */
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/**  * @}  */
end_comment
end_unit
