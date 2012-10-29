begin_unit
begin_comment
comment|/*  * This file generated automatically from shape.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_Shape_API XCB Shape API  * @brief Shape XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__SHAPE_H
end_ifndef
begin_define
DECL|macro|__SHAPE_H
define|#
directive|define
name|__SHAPE_H
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
DECL|macro|XCB_SHAPE_MAJOR_VERSION
define|#
directive|define
name|XCB_SHAPE_MAJOR_VERSION
value|1
DECL|macro|XCB_SHAPE_MINOR_VERSION
define|#
directive|define
name|XCB_SHAPE_MINOR_VERSION
value|1
specifier|extern
name|xcb_extension_t
name|xcb_shape_id
decl_stmt|;
DECL|typedef|xcb_shape_op_t
typedef|typedef
name|uint8_t
name|xcb_shape_op_t
typedef|;
comment|/**  * @brief xcb_shape_op_iterator_t  **/
DECL|struct|xcb_shape_op_iterator_t
typedef|typedef
struct|struct
name|xcb_shape_op_iterator_t
block|{
DECL|member|data
name|xcb_shape_op_t
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
DECL|typedef|xcb_shape_op_iterator_t
name|xcb_shape_op_iterator_t
typedef|;
DECL|typedef|xcb_shape_kind_t
typedef|typedef
name|uint8_t
name|xcb_shape_kind_t
typedef|;
comment|/**  * @brief xcb_shape_kind_iterator_t  **/
DECL|struct|xcb_shape_kind_iterator_t
typedef|typedef
struct|struct
name|xcb_shape_kind_iterator_t
block|{
DECL|member|data
name|xcb_shape_kind_t
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
DECL|typedef|xcb_shape_kind_iterator_t
name|xcb_shape_kind_iterator_t
typedef|;
DECL|enum|xcb_shape_so_t
typedef|typedef
enum|enum
name|xcb_shape_so_t
block|{
DECL|enumerator|XCB_SHAPE_SO_SET
name|XCB_SHAPE_SO_SET
block|,
DECL|enumerator|XCB_SHAPE_SO_UNION
name|XCB_SHAPE_SO_UNION
block|,
DECL|enumerator|XCB_SHAPE_SO_INTERSECT
name|XCB_SHAPE_SO_INTERSECT
block|,
DECL|enumerator|XCB_SHAPE_SO_SUBTRACT
name|XCB_SHAPE_SO_SUBTRACT
block|,
DECL|enumerator|XCB_SHAPE_SO_INVERT
name|XCB_SHAPE_SO_INVERT
block|}
DECL|typedef|xcb_shape_so_t
name|xcb_shape_so_t
typedef|;
DECL|enum|xcb_shape_sk_t
typedef|typedef
enum|enum
name|xcb_shape_sk_t
block|{
DECL|enumerator|XCB_SHAPE_SK_BOUNDING
name|XCB_SHAPE_SK_BOUNDING
block|,
DECL|enumerator|XCB_SHAPE_SK_CLIP
name|XCB_SHAPE_SK_CLIP
block|,
DECL|enumerator|XCB_SHAPE_SK_INPUT
name|XCB_SHAPE_SK_INPUT
block|}
DECL|typedef|xcb_shape_sk_t
name|xcb_shape_sk_t
typedef|;
comment|/** Opcode for xcb_shape_notify. */
DECL|macro|XCB_SHAPE_NOTIFY
define|#
directive|define
name|XCB_SHAPE_NOTIFY
value|0
comment|/**  * @brief xcb_shape_notify_event_t  **/
DECL|struct|xcb_shape_notify_event_t
typedef|typedef
struct|struct
name|xcb_shape_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|shape_kind
name|xcb_shape_kind_t
name|shape_kind
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|affected_window
name|xcb_window_t
name|affected_window
decl_stmt|;
comment|/**<  */
DECL|member|extents_x
name|int16_t
name|extents_x
decl_stmt|;
comment|/**<  */
DECL|member|extents_y
name|int16_t
name|extents_y
decl_stmt|;
comment|/**<  */
DECL|member|extents_width
name|uint16_t
name|extents_width
decl_stmt|;
comment|/**<  */
DECL|member|extents_height
name|uint16_t
name|extents_height
decl_stmt|;
comment|/**<  */
DECL|member|server_time
name|xcb_timestamp_t
name|server_time
decl_stmt|;
comment|/**<  */
DECL|member|shaped
name|uint8_t
name|shaped
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|11
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_notify_event_t
name|xcb_shape_notify_event_t
typedef|;
comment|/**  * @brief xcb_shape_query_version_cookie_t  **/
DECL|struct|xcb_shape_query_version_cookie_t
typedef|typedef
struct|struct
name|xcb_shape_query_version_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_query_version_cookie_t
name|xcb_shape_query_version_cookie_t
typedef|;
comment|/** Opcode for xcb_shape_query_version. */
DECL|macro|XCB_SHAPE_QUERY_VERSION
define|#
directive|define
name|XCB_SHAPE_QUERY_VERSION
value|0
comment|/**  * @brief xcb_shape_query_version_request_t  **/
DECL|struct|xcb_shape_query_version_request_t
typedef|typedef
struct|struct
name|xcb_shape_query_version_request_t
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
DECL|typedef|xcb_shape_query_version_request_t
name|xcb_shape_query_version_request_t
typedef|;
comment|/**  * @brief xcb_shape_query_version_reply_t  **/
DECL|struct|xcb_shape_query_version_reply_t
typedef|typedef
struct|struct
name|xcb_shape_query_version_reply_t
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
name|uint16_t
name|major_version
decl_stmt|;
comment|/**<  */
DECL|member|minor_version
name|uint16_t
name|minor_version
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_query_version_reply_t
name|xcb_shape_query_version_reply_t
typedef|;
comment|/** Opcode for xcb_shape_rectangles. */
DECL|macro|XCB_SHAPE_RECTANGLES
define|#
directive|define
name|XCB_SHAPE_RECTANGLES
value|1
comment|/**  * @brief xcb_shape_rectangles_request_t  **/
DECL|struct|xcb_shape_rectangles_request_t
typedef|typedef
struct|struct
name|xcb_shape_rectangles_request_t
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
DECL|member|operation
name|xcb_shape_op_t
name|operation
decl_stmt|;
comment|/**<  */
DECL|member|destination_kind
name|xcb_shape_kind_t
name|destination_kind
decl_stmt|;
comment|/**<  */
DECL|member|ordering
name|uint8_t
name|ordering
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
DECL|member|x_offset
name|int16_t
name|x_offset
decl_stmt|;
comment|/**<  */
DECL|member|y_offset
name|int16_t
name|y_offset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_rectangles_request_t
name|xcb_shape_rectangles_request_t
typedef|;
comment|/** Opcode for xcb_shape_mask. */
DECL|macro|XCB_SHAPE_MASK
define|#
directive|define
name|XCB_SHAPE_MASK
value|2
comment|/**  * @brief xcb_shape_mask_request_t  **/
DECL|struct|xcb_shape_mask_request_t
typedef|typedef
struct|struct
name|xcb_shape_mask_request_t
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
DECL|member|operation
name|xcb_shape_op_t
name|operation
decl_stmt|;
comment|/**<  */
DECL|member|destination_kind
name|xcb_shape_kind_t
name|destination_kind
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
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
DECL|member|x_offset
name|int16_t
name|x_offset
decl_stmt|;
comment|/**<  */
DECL|member|y_offset
name|int16_t
name|y_offset
decl_stmt|;
comment|/**<  */
DECL|member|source_bitmap
name|xcb_pixmap_t
name|source_bitmap
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_mask_request_t
name|xcb_shape_mask_request_t
typedef|;
comment|/** Opcode for xcb_shape_combine. */
DECL|macro|XCB_SHAPE_COMBINE
define|#
directive|define
name|XCB_SHAPE_COMBINE
value|3
comment|/**  * @brief xcb_shape_combine_request_t  **/
DECL|struct|xcb_shape_combine_request_t
typedef|typedef
struct|struct
name|xcb_shape_combine_request_t
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
DECL|member|operation
name|xcb_shape_op_t
name|operation
decl_stmt|;
comment|/**<  */
DECL|member|destination_kind
name|xcb_shape_kind_t
name|destination_kind
decl_stmt|;
comment|/**<  */
DECL|member|source_kind
name|xcb_shape_kind_t
name|source_kind
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
DECL|member|x_offset
name|int16_t
name|x_offset
decl_stmt|;
comment|/**<  */
DECL|member|y_offset
name|int16_t
name|y_offset
decl_stmt|;
comment|/**<  */
DECL|member|source_window
name|xcb_window_t
name|source_window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_combine_request_t
name|xcb_shape_combine_request_t
typedef|;
comment|/** Opcode for xcb_shape_offset. */
DECL|macro|XCB_SHAPE_OFFSET
define|#
directive|define
name|XCB_SHAPE_OFFSET
value|4
comment|/**  * @brief xcb_shape_offset_request_t  **/
DECL|struct|xcb_shape_offset_request_t
typedef|typedef
struct|struct
name|xcb_shape_offset_request_t
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
DECL|member|destination_kind
name|xcb_shape_kind_t
name|destination_kind
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
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
DECL|member|x_offset
name|int16_t
name|x_offset
decl_stmt|;
comment|/**<  */
DECL|member|y_offset
name|int16_t
name|y_offset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_offset_request_t
name|xcb_shape_offset_request_t
typedef|;
comment|/**  * @brief xcb_shape_query_extents_cookie_t  **/
DECL|struct|xcb_shape_query_extents_cookie_t
typedef|typedef
struct|struct
name|xcb_shape_query_extents_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_query_extents_cookie_t
name|xcb_shape_query_extents_cookie_t
typedef|;
comment|/** Opcode for xcb_shape_query_extents. */
DECL|macro|XCB_SHAPE_QUERY_EXTENTS
define|#
directive|define
name|XCB_SHAPE_QUERY_EXTENTS
value|5
comment|/**  * @brief xcb_shape_query_extents_request_t  **/
DECL|struct|xcb_shape_query_extents_request_t
typedef|typedef
struct|struct
name|xcb_shape_query_extents_request_t
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
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_query_extents_request_t
name|xcb_shape_query_extents_request_t
typedef|;
comment|/**  * @brief xcb_shape_query_extents_reply_t  **/
DECL|struct|xcb_shape_query_extents_reply_t
typedef|typedef
struct|struct
name|xcb_shape_query_extents_reply_t
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
DECL|member|bounding_shaped
name|uint8_t
name|bounding_shaped
decl_stmt|;
comment|/**<  */
DECL|member|clip_shaped
name|uint8_t
name|clip_shaped
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|2
index|]
decl_stmt|;
comment|/**<  */
DECL|member|bounding_shape_extents_x
name|int16_t
name|bounding_shape_extents_x
decl_stmt|;
comment|/**<  */
DECL|member|bounding_shape_extents_y
name|int16_t
name|bounding_shape_extents_y
decl_stmt|;
comment|/**<  */
DECL|member|bounding_shape_extents_width
name|uint16_t
name|bounding_shape_extents_width
decl_stmt|;
comment|/**<  */
DECL|member|bounding_shape_extents_height
name|uint16_t
name|bounding_shape_extents_height
decl_stmt|;
comment|/**<  */
DECL|member|clip_shape_extents_x
name|int16_t
name|clip_shape_extents_x
decl_stmt|;
comment|/**<  */
DECL|member|clip_shape_extents_y
name|int16_t
name|clip_shape_extents_y
decl_stmt|;
comment|/**<  */
DECL|member|clip_shape_extents_width
name|uint16_t
name|clip_shape_extents_width
decl_stmt|;
comment|/**<  */
DECL|member|clip_shape_extents_height
name|uint16_t
name|clip_shape_extents_height
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_query_extents_reply_t
name|xcb_shape_query_extents_reply_t
typedef|;
comment|/** Opcode for xcb_shape_select_input. */
DECL|macro|XCB_SHAPE_SELECT_INPUT
define|#
directive|define
name|XCB_SHAPE_SELECT_INPUT
value|6
comment|/**  * @brief xcb_shape_select_input_request_t  **/
DECL|struct|xcb_shape_select_input_request_t
typedef|typedef
struct|struct
name|xcb_shape_select_input_request_t
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
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
DECL|member|enable
name|uint8_t
name|enable
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
block|}
DECL|typedef|xcb_shape_select_input_request_t
name|xcb_shape_select_input_request_t
typedef|;
comment|/**  * @brief xcb_shape_input_selected_cookie_t  **/
DECL|struct|xcb_shape_input_selected_cookie_t
typedef|typedef
struct|struct
name|xcb_shape_input_selected_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_input_selected_cookie_t
name|xcb_shape_input_selected_cookie_t
typedef|;
comment|/** Opcode for xcb_shape_input_selected. */
DECL|macro|XCB_SHAPE_INPUT_SELECTED
define|#
directive|define
name|XCB_SHAPE_INPUT_SELECTED
value|7
comment|/**  * @brief xcb_shape_input_selected_request_t  **/
DECL|struct|xcb_shape_input_selected_request_t
typedef|typedef
struct|struct
name|xcb_shape_input_selected_request_t
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
DECL|member|destination_window
name|xcb_window_t
name|destination_window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_input_selected_request_t
name|xcb_shape_input_selected_request_t
typedef|;
comment|/**  * @brief xcb_shape_input_selected_reply_t  **/
DECL|struct|xcb_shape_input_selected_reply_t
typedef|typedef
struct|struct
name|xcb_shape_input_selected_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|enabled
name|uint8_t
name|enabled
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
block|}
DECL|typedef|xcb_shape_input_selected_reply_t
name|xcb_shape_input_selected_reply_t
typedef|;
comment|/**  * @brief xcb_shape_get_rectangles_cookie_t  **/
DECL|struct|xcb_shape_get_rectangles_cookie_t
typedef|typedef
struct|struct
name|xcb_shape_get_rectangles_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_get_rectangles_cookie_t
name|xcb_shape_get_rectangles_cookie_t
typedef|;
comment|/** Opcode for xcb_shape_get_rectangles. */
DECL|macro|XCB_SHAPE_GET_RECTANGLES
define|#
directive|define
name|XCB_SHAPE_GET_RECTANGLES
value|8
comment|/**  * @brief xcb_shape_get_rectangles_request_t  **/
DECL|struct|xcb_shape_get_rectangles_request_t
typedef|typedef
struct|struct
name|xcb_shape_get_rectangles_request_t
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
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|source_kind
name|xcb_shape_kind_t
name|source_kind
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
block|}
DECL|typedef|xcb_shape_get_rectangles_request_t
name|xcb_shape_get_rectangles_request_t
typedef|;
comment|/**  * @brief xcb_shape_get_rectangles_reply_t  **/
DECL|struct|xcb_shape_get_rectangles_reply_t
typedef|typedef
struct|struct
name|xcb_shape_get_rectangles_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|ordering
name|uint8_t
name|ordering
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
DECL|member|rectangles_len
name|uint32_t
name|rectangles_len
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|20
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shape_get_rectangles_reply_t
name|xcb_shape_get_rectangles_reply_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_shape_op_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_shape_op_t)  */
comment|/*****************************************************************************  **  ** void xcb_shape_op_next  **   ** @param xcb_shape_op_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_shape_op_next
parameter_list|(
name|xcb_shape_op_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_shape_op_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_shape_op_end  **   ** @param xcb_shape_op_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_shape_op_end
parameter_list|(
name|xcb_shape_op_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_shape_kind_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_shape_kind_t)  */
comment|/*****************************************************************************  **  ** void xcb_shape_kind_next  **   ** @param xcb_shape_kind_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_shape_kind_next
parameter_list|(
name|xcb_shape_kind_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_shape_kind_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_shape_kind_end  **   ** @param xcb_shape_kind_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_shape_kind_end
parameter_list|(
name|xcb_shape_kind_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_shape_query_version_cookie_t xcb_shape_query_version  **   ** @param xcb_connection_t *c  ** @returns xcb_shape_query_version_cookie_t  **  *****************************************************************************/
name|xcb_shape_query_version_cookie_t
name|xcb_shape_query_version
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_shape_query_version_cookie_t xcb_shape_query_version_unchecked  **   ** @param xcb_connection_t *c  ** @returns xcb_shape_query_version_cookie_t  **  *****************************************************************************/
name|xcb_shape_query_version_cookie_t
name|xcb_shape_query_version_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_shape_query_version_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_shape_query_version_reply_t * xcb_shape_query_version_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_shape_query_version_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_shape_query_version_reply_t *  **  *****************************************************************************/
name|xcb_shape_query_version_reply_t
modifier|*
name|xcb_shape_query_version_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_query_version_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_rectangles_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_shape_op_t         operation  ** @param xcb_shape_kind_t       destination_kind  ** @param uint8_t                ordering  ** @param xcb_window_t           destination_window  ** @param int16_t                x_offset  ** @param int16_t                y_offset  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_rectangles_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_op_t
name|operation
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|uint8_t
name|ordering
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_rectangles  **   ** @param xcb_connection_t      *c  ** @param xcb_shape_op_t         operation  ** @param xcb_shape_kind_t       destination_kind  ** @param uint8_t                ordering  ** @param xcb_window_t           destination_window  ** @param int16_t                x_offset  ** @param int16_t                y_offset  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_rectangles
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_op_t
name|operation
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|uint8_t
name|ordering
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_mask_checked  **   ** @param xcb_connection_t *c  ** @param xcb_shape_op_t    operation  ** @param xcb_shape_kind_t  destination_kind  ** @param xcb_window_t      destination_window  ** @param int16_t           x_offset  ** @param int16_t           y_offset  ** @param xcb_pixmap_t      source_bitmap  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_mask_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_op_t
name|operation
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
comment|/**< */
parameter_list|,
name|xcb_pixmap_t
name|source_bitmap
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_mask  **   ** @param xcb_connection_t *c  ** @param xcb_shape_op_t    operation  ** @param xcb_shape_kind_t  destination_kind  ** @param xcb_window_t      destination_window  ** @param int16_t           x_offset  ** @param int16_t           y_offset  ** @param xcb_pixmap_t      source_bitmap  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_mask
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_op_t
name|operation
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
comment|/**< */
parameter_list|,
name|xcb_pixmap_t
name|source_bitmap
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_combine_checked  **   ** @param xcb_connection_t *c  ** @param xcb_shape_op_t    operation  ** @param xcb_shape_kind_t  destination_kind  ** @param xcb_shape_kind_t  source_kind  ** @param xcb_window_t      destination_window  ** @param int16_t           x_offset  ** @param int16_t           y_offset  ** @param xcb_window_t      source_window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_combine_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_op_t
name|operation
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|source_kind
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
comment|/**< */
parameter_list|,
name|xcb_window_t
name|source_window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_combine  **   ** @param xcb_connection_t *c  ** @param xcb_shape_op_t    operation  ** @param xcb_shape_kind_t  destination_kind  ** @param xcb_shape_kind_t  source_kind  ** @param xcb_window_t      destination_window  ** @param int16_t           x_offset  ** @param int16_t           y_offset  ** @param xcb_window_t      source_window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_combine
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_op_t
name|operation
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|source_kind
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
comment|/**< */
parameter_list|,
name|xcb_window_t
name|source_window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_offset_checked  **   ** @param xcb_connection_t *c  ** @param xcb_shape_kind_t  destination_kind  ** @param xcb_window_t      destination_window  ** @param int16_t           x_offset  ** @param int16_t           y_offset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_offset_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_offset  **   ** @param xcb_connection_t *c  ** @param xcb_shape_kind_t  destination_kind  ** @param xcb_window_t      destination_window  ** @param int16_t           x_offset  ** @param int16_t           y_offset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_offset
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|destination_kind
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|int16_t
name|x_offset
comment|/**< */
parameter_list|,
name|int16_t
name|y_offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_shape_query_extents_cookie_t xcb_shape_query_extents  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      destination_window  ** @returns xcb_shape_query_extents_cookie_t  **  *****************************************************************************/
name|xcb_shape_query_extents_cookie_t
name|xcb_shape_query_extents
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_shape_query_extents_cookie_t xcb_shape_query_extents_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      destination_window  ** @returns xcb_shape_query_extents_cookie_t  **  *****************************************************************************/
name|xcb_shape_query_extents_cookie_t
name|xcb_shape_query_extents_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_shape_query_extents_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_shape_query_extents_reply_t * xcb_shape_query_extents_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_shape_query_extents_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_shape_query_extents_reply_t *  **  *****************************************************************************/
name|xcb_shape_query_extents_reply_t
modifier|*
name|xcb_shape_query_extents_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_query_extents_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_select_input_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      destination_window  ** @param uint8_t           enable  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_select_input_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|uint8_t
name|enable
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shape_select_input  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      destination_window  ** @param uint8_t           enable  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shape_select_input
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|,
name|uint8_t
name|enable
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_shape_input_selected_cookie_t xcb_shape_input_selected  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      destination_window  ** @returns xcb_shape_input_selected_cookie_t  **  *****************************************************************************/
name|xcb_shape_input_selected_cookie_t
name|xcb_shape_input_selected
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_shape_input_selected_cookie_t xcb_shape_input_selected_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      destination_window  ** @returns xcb_shape_input_selected_cookie_t  **  *****************************************************************************/
name|xcb_shape_input_selected_cookie_t
name|xcb_shape_input_selected_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|destination_window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_shape_input_selected_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_shape_input_selected_reply_t * xcb_shape_input_selected_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_shape_input_selected_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_shape_input_selected_reply_t *  **  *****************************************************************************/
name|xcb_shape_input_selected_reply_t
modifier|*
name|xcb_shape_input_selected_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_input_selected_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_shape_get_rectangles_cookie_t xcb_shape_get_rectangles  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param xcb_shape_kind_t  source_kind  ** @returns xcb_shape_get_rectangles_cookie_t  **  *****************************************************************************/
name|xcb_shape_get_rectangles_cookie_t
name|xcb_shape_get_rectangles
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|source_kind
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_shape_get_rectangles_cookie_t xcb_shape_get_rectangles_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param xcb_shape_kind_t  source_kind  ** @returns xcb_shape_get_rectangles_cookie_t  **  *****************************************************************************/
name|xcb_shape_get_rectangles_cookie_t
name|xcb_shape_get_rectangles_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|source_kind
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_rectangle_t * xcb_shape_get_rectangles_rectangles  **   ** @param const xcb_shape_get_rectangles_reply_t *R  ** @returns xcb_rectangle_t *  **  *****************************************************************************/
name|xcb_rectangle_t
modifier|*
name|xcb_shape_get_rectangles_rectangles
parameter_list|(
specifier|const
name|xcb_shape_get_rectangles_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_shape_get_rectangles_rectangles_length  **   ** @param const xcb_shape_get_rectangles_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_shape_get_rectangles_rectangles_length
parameter_list|(
specifier|const
name|xcb_shape_get_rectangles_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_rectangle_iterator_t xcb_shape_get_rectangles_rectangles_iterator  **   ** @param const xcb_shape_get_rectangles_reply_t *R  ** @returns xcb_rectangle_iterator_t  **  *****************************************************************************/
name|xcb_rectangle_iterator_t
name|xcb_shape_get_rectangles_rectangles_iterator
parameter_list|(
specifier|const
name|xcb_shape_get_rectangles_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_shape_get_rectangles_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_shape_get_rectangles_reply_t * xcb_shape_get_rectangles_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_shape_get_rectangles_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_shape_get_rectangles_reply_t *  **  *****************************************************************************/
name|xcb_shape_get_rectangles_reply_t
modifier|*
name|xcb_shape_get_rectangles_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shape_get_rectangles_cookie_t
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
