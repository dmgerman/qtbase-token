begin_unit
begin_comment
comment|/*  * This file generated automatically from xfixes.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_XFixes_API XCB XFixes API  * @brief XFixes XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__XFIXES_H
end_ifndef
begin_define
DECL|macro|__XFIXES_H
define|#
directive|define
name|__XFIXES_H
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
begin_include
include|#
directive|include
file|"render.h"
end_include
begin_include
include|#
directive|include
file|"shape.h"
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
DECL|macro|XCB_XFIXES_MAJOR_VERSION
define|#
directive|define
name|XCB_XFIXES_MAJOR_VERSION
value|4
DECL|macro|XCB_XFIXES_MINOR_VERSION
define|#
directive|define
name|XCB_XFIXES_MINOR_VERSION
value|0
specifier|extern
name|xcb_extension_t
name|xcb_xfixes_id
decl_stmt|;
comment|/**  * @brief xcb_xfixes_query_version_cookie_t  **/
DECL|struct|xcb_xfixes_query_version_cookie_t
typedef|typedef
struct|struct
name|xcb_xfixes_query_version_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_query_version_cookie_t
name|xcb_xfixes_query_version_cookie_t
typedef|;
comment|/** Opcode for xcb_xfixes_query_version. */
DECL|macro|XCB_XFIXES_QUERY_VERSION
define|#
directive|define
name|XCB_XFIXES_QUERY_VERSION
value|0
comment|/**  * @brief xcb_xfixes_query_version_request_t  **/
DECL|struct|xcb_xfixes_query_version_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_query_version_request_t
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
DECL|typedef|xcb_xfixes_query_version_request_t
name|xcb_xfixes_query_version_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_query_version_reply_t  **/
DECL|struct|xcb_xfixes_query_version_reply_t
typedef|typedef
struct|struct
name|xcb_xfixes_query_version_reply_t
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
DECL|typedef|xcb_xfixes_query_version_reply_t
name|xcb_xfixes_query_version_reply_t
typedef|;
DECL|enum|xcb_xfixes_save_set_mode_t
typedef|typedef
enum|enum
name|xcb_xfixes_save_set_mode_t
block|{
DECL|enumerator|XCB_XFIXES_SAVE_SET_MODE_INSERT
name|XCB_XFIXES_SAVE_SET_MODE_INSERT
block|,
DECL|enumerator|XCB_XFIXES_SAVE_SET_MODE_DELETE
name|XCB_XFIXES_SAVE_SET_MODE_DELETE
block|}
DECL|typedef|xcb_xfixes_save_set_mode_t
name|xcb_xfixes_save_set_mode_t
typedef|;
DECL|enum|xcb_xfixes_save_set_target_t
typedef|typedef
enum|enum
name|xcb_xfixes_save_set_target_t
block|{
DECL|enumerator|XCB_XFIXES_SAVE_SET_TARGET_NEAREST
name|XCB_XFIXES_SAVE_SET_TARGET_NEAREST
block|,
DECL|enumerator|XCB_XFIXES_SAVE_SET_TARGET_ROOT
name|XCB_XFIXES_SAVE_SET_TARGET_ROOT
block|}
DECL|typedef|xcb_xfixes_save_set_target_t
name|xcb_xfixes_save_set_target_t
typedef|;
DECL|enum|xcb_xfixes_save_set_mapping_t
typedef|typedef
enum|enum
name|xcb_xfixes_save_set_mapping_t
block|{
DECL|enumerator|XCB_XFIXES_SAVE_SET_MAPPING_MAP
name|XCB_XFIXES_SAVE_SET_MAPPING_MAP
block|,
DECL|enumerator|XCB_XFIXES_SAVE_SET_MAPPING_UNMAP
name|XCB_XFIXES_SAVE_SET_MAPPING_UNMAP
block|}
DECL|typedef|xcb_xfixes_save_set_mapping_t
name|xcb_xfixes_save_set_mapping_t
typedef|;
comment|/** Opcode for xcb_xfixes_change_save_set. */
DECL|macro|XCB_XFIXES_CHANGE_SAVE_SET
define|#
directive|define
name|XCB_XFIXES_CHANGE_SAVE_SET
value|1
comment|/**  * @brief xcb_xfixes_change_save_set_request_t  **/
DECL|struct|xcb_xfixes_change_save_set_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_change_save_set_request_t
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
DECL|member|mode
name|uint8_t
name|mode
decl_stmt|;
comment|/**<  */
DECL|member|target
name|uint8_t
name|target
decl_stmt|;
comment|/**<  */
DECL|member|map
name|uint8_t
name|map
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_change_save_set_request_t
name|xcb_xfixes_change_save_set_request_t
typedef|;
DECL|enum|xcb_xfixes_selection_event_t
typedef|typedef
enum|enum
name|xcb_xfixes_selection_event_t
block|{
DECL|enumerator|XCB_XFIXES_SELECTION_EVENT_SET_SELECTION_OWNER
name|XCB_XFIXES_SELECTION_EVENT_SET_SELECTION_OWNER
block|,
DECL|enumerator|XCB_XFIXES_SELECTION_EVENT_SELECTION_WINDOW_DESTROY
name|XCB_XFIXES_SELECTION_EVENT_SELECTION_WINDOW_DESTROY
block|,
DECL|enumerator|XCB_XFIXES_SELECTION_EVENT_SELECTION_CLIENT_CLOSE
name|XCB_XFIXES_SELECTION_EVENT_SELECTION_CLIENT_CLOSE
block|}
DECL|typedef|xcb_xfixes_selection_event_t
name|xcb_xfixes_selection_event_t
typedef|;
DECL|enum|xcb_xfixes_selection_event_mask_t
typedef|typedef
enum|enum
name|xcb_xfixes_selection_event_mask_t
block|{
DECL|enumerator|XCB_XFIXES_SELECTION_EVENT_MASK_SET_SELECTION_OWNER
name|XCB_XFIXES_SELECTION_EVENT_MASK_SET_SELECTION_OWNER
init|=
literal|1
block|,
DECL|enumerator|XCB_XFIXES_SELECTION_EVENT_MASK_SELECTION_WINDOW_DESTROY
name|XCB_XFIXES_SELECTION_EVENT_MASK_SELECTION_WINDOW_DESTROY
init|=
literal|2
block|,
DECL|enumerator|XCB_XFIXES_SELECTION_EVENT_MASK_SELECTION_CLIENT_CLOSE
name|XCB_XFIXES_SELECTION_EVENT_MASK_SELECTION_CLIENT_CLOSE
init|=
literal|4
block|}
DECL|typedef|xcb_xfixes_selection_event_mask_t
name|xcb_xfixes_selection_event_mask_t
typedef|;
comment|/** Opcode for xcb_xfixes_selection_notify. */
DECL|macro|XCB_XFIXES_SELECTION_NOTIFY
define|#
directive|define
name|XCB_XFIXES_SELECTION_NOTIFY
value|0
comment|/**  * @brief xcb_xfixes_selection_notify_event_t  **/
DECL|struct|xcb_xfixes_selection_notify_event_t
typedef|typedef
struct|struct
name|xcb_xfixes_selection_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|subtype
name|uint8_t
name|subtype
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|owner
name|xcb_window_t
name|owner
decl_stmt|;
comment|/**<  */
DECL|member|selection
name|xcb_atom_t
name|selection
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|selection_timestamp
name|xcb_timestamp_t
name|selection_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|8
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_selection_notify_event_t
name|xcb_xfixes_selection_notify_event_t
typedef|;
comment|/** Opcode for xcb_xfixes_select_selection_input. */
DECL|macro|XCB_XFIXES_SELECT_SELECTION_INPUT
define|#
directive|define
name|XCB_XFIXES_SELECT_SELECTION_INPUT
value|2
comment|/**  * @brief xcb_xfixes_select_selection_input_request_t  **/
DECL|struct|xcb_xfixes_select_selection_input_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_select_selection_input_request_t
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
DECL|member|selection
name|xcb_atom_t
name|selection
decl_stmt|;
comment|/**<  */
DECL|member|event_mask
name|uint32_t
name|event_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_select_selection_input_request_t
name|xcb_xfixes_select_selection_input_request_t
typedef|;
DECL|enum|xcb_xfixes_cursor_notify_t
typedef|typedef
enum|enum
name|xcb_xfixes_cursor_notify_t
block|{
DECL|enumerator|XCB_XFIXES_CURSOR_NOTIFY_DISPLAY_CURSOR
name|XCB_XFIXES_CURSOR_NOTIFY_DISPLAY_CURSOR
block|}
DECL|typedef|xcb_xfixes_cursor_notify_t
name|xcb_xfixes_cursor_notify_t
typedef|;
DECL|enum|xcb_xfixes_cursor_notify_mask_t
typedef|typedef
enum|enum
name|xcb_xfixes_cursor_notify_mask_t
block|{
DECL|enumerator|XCB_XFIXES_CURSOR_NOTIFY_MASK_DISPLAY_CURSOR
name|XCB_XFIXES_CURSOR_NOTIFY_MASK_DISPLAY_CURSOR
init|=
literal|1
block|}
DECL|typedef|xcb_xfixes_cursor_notify_mask_t
name|xcb_xfixes_cursor_notify_mask_t
typedef|;
comment|/** Opcode for xcb_xfixes_cursor_notify. */
DECL|macro|XCB_XFIXES_CURSOR_NOTIFY
define|#
directive|define
name|XCB_XFIXES_CURSOR_NOTIFY
value|1
comment|/**  * @brief xcb_xfixes_cursor_notify_event_t  **/
DECL|struct|xcb_xfixes_cursor_notify_event_t
typedef|typedef
struct|struct
name|xcb_xfixes_cursor_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|subtype
name|uint8_t
name|subtype
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|cursor_serial
name|uint32_t
name|cursor_serial
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|name
name|xcb_atom_t
name|name
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|12
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_cursor_notify_event_t
name|xcb_xfixes_cursor_notify_event_t
typedef|;
comment|/** Opcode for xcb_xfixes_select_cursor_input. */
DECL|macro|XCB_XFIXES_SELECT_CURSOR_INPUT
define|#
directive|define
name|XCB_XFIXES_SELECT_CURSOR_INPUT
value|3
comment|/**  * @brief xcb_xfixes_select_cursor_input_request_t  **/
DECL|struct|xcb_xfixes_select_cursor_input_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_select_cursor_input_request_t
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
DECL|member|event_mask
name|uint32_t
name|event_mask
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_select_cursor_input_request_t
name|xcb_xfixes_select_cursor_input_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_get_cursor_image_cookie_t  **/
DECL|struct|xcb_xfixes_get_cursor_image_cookie_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_image_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_get_cursor_image_cookie_t
name|xcb_xfixes_get_cursor_image_cookie_t
typedef|;
comment|/** Opcode for xcb_xfixes_get_cursor_image. */
DECL|macro|XCB_XFIXES_GET_CURSOR_IMAGE
define|#
directive|define
name|XCB_XFIXES_GET_CURSOR_IMAGE
value|4
comment|/**  * @brief xcb_xfixes_get_cursor_image_request_t  **/
DECL|struct|xcb_xfixes_get_cursor_image_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_image_request_t
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
DECL|typedef|xcb_xfixes_get_cursor_image_request_t
name|xcb_xfixes_get_cursor_image_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_get_cursor_image_reply_t  **/
DECL|struct|xcb_xfixes_get_cursor_image_reply_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_image_reply_t
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
DECL|member|xhot
name|uint16_t
name|xhot
decl_stmt|;
comment|/**<  */
DECL|member|yhot
name|uint16_t
name|yhot
decl_stmt|;
comment|/**<  */
DECL|member|cursor_serial
name|uint32_t
name|cursor_serial
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|8
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_get_cursor_image_reply_t
name|xcb_xfixes_get_cursor_image_reply_t
typedef|;
DECL|typedef|xcb_xfixes_region_t
typedef|typedef
name|uint32_t
name|xcb_xfixes_region_t
typedef|;
comment|/**  * @brief xcb_xfixes_region_iterator_t  **/
DECL|struct|xcb_xfixes_region_iterator_t
typedef|typedef
struct|struct
name|xcb_xfixes_region_iterator_t
block|{
DECL|member|data
name|xcb_xfixes_region_t
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
DECL|typedef|xcb_xfixes_region_iterator_t
name|xcb_xfixes_region_iterator_t
typedef|;
comment|/** Opcode for xcb_xfixes_bad_region. */
DECL|macro|XCB_XFIXES_BAD_REGION
define|#
directive|define
name|XCB_XFIXES_BAD_REGION
value|0
comment|/**  * @brief xcb_xfixes_bad_region_error_t  **/
DECL|struct|xcb_xfixes_bad_region_error_t
typedef|typedef
struct|struct
name|xcb_xfixes_bad_region_error_t
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
DECL|typedef|xcb_xfixes_bad_region_error_t
name|xcb_xfixes_bad_region_error_t
typedef|;
DECL|enum|xcb_xfixes_region_enum_t
typedef|typedef
enum|enum
name|xcb_xfixes_region_enum_t
block|{
DECL|enumerator|XCB_XFIXES_REGION_NONE
name|XCB_XFIXES_REGION_NONE
block|}
DECL|typedef|xcb_xfixes_region_enum_t
name|xcb_xfixes_region_enum_t
typedef|;
comment|/** Opcode for xcb_xfixes_create_region. */
DECL|macro|XCB_XFIXES_CREATE_REGION
define|#
directive|define
name|XCB_XFIXES_CREATE_REGION
value|5
comment|/**  * @brief xcb_xfixes_create_region_request_t  **/
DECL|struct|xcb_xfixes_create_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_create_region_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_create_region_request_t
name|xcb_xfixes_create_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_create_region_from_bitmap. */
DECL|macro|XCB_XFIXES_CREATE_REGION_FROM_BITMAP
define|#
directive|define
name|XCB_XFIXES_CREATE_REGION_FROM_BITMAP
value|6
comment|/**  * @brief xcb_xfixes_create_region_from_bitmap_request_t  **/
DECL|struct|xcb_xfixes_create_region_from_bitmap_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_create_region_from_bitmap_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|bitmap
name|xcb_pixmap_t
name|bitmap
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_create_region_from_bitmap_request_t
name|xcb_xfixes_create_region_from_bitmap_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_create_region_from_window. */
DECL|macro|XCB_XFIXES_CREATE_REGION_FROM_WINDOW
define|#
directive|define
name|XCB_XFIXES_CREATE_REGION_FROM_WINDOW
value|7
comment|/**  * @brief xcb_xfixes_create_region_from_window_request_t  **/
DECL|struct|xcb_xfixes_create_region_from_window_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_create_region_from_window_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|kind
name|xcb_shape_kind_t
name|kind
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
DECL|typedef|xcb_xfixes_create_region_from_window_request_t
name|xcb_xfixes_create_region_from_window_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_create_region_from_gc. */
DECL|macro|XCB_XFIXES_CREATE_REGION_FROM_GC
define|#
directive|define
name|XCB_XFIXES_CREATE_REGION_FROM_GC
value|8
comment|/**  * @brief xcb_xfixes_create_region_from_gc_request_t  **/
DECL|struct|xcb_xfixes_create_region_from_gc_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_create_region_from_gc_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|gc
name|xcb_gcontext_t
name|gc
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_create_region_from_gc_request_t
name|xcb_xfixes_create_region_from_gc_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_create_region_from_picture. */
DECL|macro|XCB_XFIXES_CREATE_REGION_FROM_PICTURE
define|#
directive|define
name|XCB_XFIXES_CREATE_REGION_FROM_PICTURE
value|9
comment|/**  * @brief xcb_xfixes_create_region_from_picture_request_t  **/
DECL|struct|xcb_xfixes_create_region_from_picture_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_create_region_from_picture_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|picture
name|xcb_render_picture_t
name|picture
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_create_region_from_picture_request_t
name|xcb_xfixes_create_region_from_picture_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_destroy_region. */
DECL|macro|XCB_XFIXES_DESTROY_REGION
define|#
directive|define
name|XCB_XFIXES_DESTROY_REGION
value|10
comment|/**  * @brief xcb_xfixes_destroy_region_request_t  **/
DECL|struct|xcb_xfixes_destroy_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_destroy_region_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_destroy_region_request_t
name|xcb_xfixes_destroy_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_set_region. */
DECL|macro|XCB_XFIXES_SET_REGION
define|#
directive|define
name|XCB_XFIXES_SET_REGION
value|11
comment|/**  * @brief xcb_xfixes_set_region_request_t  **/
DECL|struct|xcb_xfixes_set_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_set_region_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_set_region_request_t
name|xcb_xfixes_set_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_copy_region. */
DECL|macro|XCB_XFIXES_COPY_REGION
define|#
directive|define
name|XCB_XFIXES_COPY_REGION
value|12
comment|/**  * @brief xcb_xfixes_copy_region_request_t  **/
DECL|struct|xcb_xfixes_copy_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_copy_region_request_t
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
DECL|member|source
name|xcb_xfixes_region_t
name|source
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_copy_region_request_t
name|xcb_xfixes_copy_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_union_region. */
DECL|macro|XCB_XFIXES_UNION_REGION
define|#
directive|define
name|XCB_XFIXES_UNION_REGION
value|13
comment|/**  * @brief xcb_xfixes_union_region_request_t  **/
DECL|struct|xcb_xfixes_union_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_union_region_request_t
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
DECL|member|source1
name|xcb_xfixes_region_t
name|source1
decl_stmt|;
comment|/**<  */
DECL|member|source2
name|xcb_xfixes_region_t
name|source2
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_union_region_request_t
name|xcb_xfixes_union_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_intersect_region. */
DECL|macro|XCB_XFIXES_INTERSECT_REGION
define|#
directive|define
name|XCB_XFIXES_INTERSECT_REGION
value|14
comment|/**  * @brief xcb_xfixes_intersect_region_request_t  **/
DECL|struct|xcb_xfixes_intersect_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_intersect_region_request_t
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
DECL|member|source1
name|xcb_xfixes_region_t
name|source1
decl_stmt|;
comment|/**<  */
DECL|member|source2
name|xcb_xfixes_region_t
name|source2
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_intersect_region_request_t
name|xcb_xfixes_intersect_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_subtract_region. */
DECL|macro|XCB_XFIXES_SUBTRACT_REGION
define|#
directive|define
name|XCB_XFIXES_SUBTRACT_REGION
value|15
comment|/**  * @brief xcb_xfixes_subtract_region_request_t  **/
DECL|struct|xcb_xfixes_subtract_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_subtract_region_request_t
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
DECL|member|source1
name|xcb_xfixes_region_t
name|source1
decl_stmt|;
comment|/**<  */
DECL|member|source2
name|xcb_xfixes_region_t
name|source2
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_subtract_region_request_t
name|xcb_xfixes_subtract_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_invert_region. */
DECL|macro|XCB_XFIXES_INVERT_REGION
define|#
directive|define
name|XCB_XFIXES_INVERT_REGION
value|16
comment|/**  * @brief xcb_xfixes_invert_region_request_t  **/
DECL|struct|xcb_xfixes_invert_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_invert_region_request_t
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
DECL|member|source
name|xcb_xfixes_region_t
name|source
decl_stmt|;
comment|/**<  */
DECL|member|bounds
name|xcb_rectangle_t
name|bounds
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_invert_region_request_t
name|xcb_xfixes_invert_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_translate_region. */
DECL|macro|XCB_XFIXES_TRANSLATE_REGION
define|#
directive|define
name|XCB_XFIXES_TRANSLATE_REGION
value|17
comment|/**  * @brief xcb_xfixes_translate_region_request_t  **/
DECL|struct|xcb_xfixes_translate_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_translate_region_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|dx
name|int16_t
name|dx
decl_stmt|;
comment|/**<  */
DECL|member|dy
name|int16_t
name|dy
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_translate_region_request_t
name|xcb_xfixes_translate_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_region_extents. */
DECL|macro|XCB_XFIXES_REGION_EXTENTS
define|#
directive|define
name|XCB_XFIXES_REGION_EXTENTS
value|18
comment|/**  * @brief xcb_xfixes_region_extents_request_t  **/
DECL|struct|xcb_xfixes_region_extents_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_region_extents_request_t
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
DECL|member|source
name|xcb_xfixes_region_t
name|source
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_region_extents_request_t
name|xcb_xfixes_region_extents_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_fetch_region_cookie_t  **/
DECL|struct|xcb_xfixes_fetch_region_cookie_t
typedef|typedef
struct|struct
name|xcb_xfixes_fetch_region_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_fetch_region_cookie_t
name|xcb_xfixes_fetch_region_cookie_t
typedef|;
comment|/** Opcode for xcb_xfixes_fetch_region. */
DECL|macro|XCB_XFIXES_FETCH_REGION
define|#
directive|define
name|XCB_XFIXES_FETCH_REGION
value|19
comment|/**  * @brief xcb_xfixes_fetch_region_request_t  **/
DECL|struct|xcb_xfixes_fetch_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_fetch_region_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_fetch_region_request_t
name|xcb_xfixes_fetch_region_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_fetch_region_reply_t  **/
DECL|struct|xcb_xfixes_fetch_region_reply_t
typedef|typedef
struct|struct
name|xcb_xfixes_fetch_region_reply_t
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
DECL|member|extents
name|xcb_rectangle_t
name|extents
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
DECL|typedef|xcb_xfixes_fetch_region_reply_t
name|xcb_xfixes_fetch_region_reply_t
typedef|;
comment|/** Opcode for xcb_xfixes_set_gc_clip_region. */
DECL|macro|XCB_XFIXES_SET_GC_CLIP_REGION
define|#
directive|define
name|XCB_XFIXES_SET_GC_CLIP_REGION
value|20
comment|/**  * @brief xcb_xfixes_set_gc_clip_region_request_t  **/
DECL|struct|xcb_xfixes_set_gc_clip_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_set_gc_clip_region_request_t
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
DECL|member|gc
name|xcb_gcontext_t
name|gc
decl_stmt|;
comment|/**<  */
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|x_origin
name|int16_t
name|x_origin
decl_stmt|;
comment|/**<  */
DECL|member|y_origin
name|int16_t
name|y_origin
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_set_gc_clip_region_request_t
name|xcb_xfixes_set_gc_clip_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_set_window_shape_region. */
DECL|macro|XCB_XFIXES_SET_WINDOW_SHAPE_REGION
define|#
directive|define
name|XCB_XFIXES_SET_WINDOW_SHAPE_REGION
value|21
comment|/**  * @brief xcb_xfixes_set_window_shape_region_request_t  **/
DECL|struct|xcb_xfixes_set_window_shape_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_set_window_shape_region_request_t
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
DECL|member|dest
name|xcb_window_t
name|dest
decl_stmt|;
comment|/**<  */
DECL|member|dest_kind
name|xcb_shape_kind_t
name|dest_kind
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_set_window_shape_region_request_t
name|xcb_xfixes_set_window_shape_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_set_picture_clip_region. */
DECL|macro|XCB_XFIXES_SET_PICTURE_CLIP_REGION
define|#
directive|define
name|XCB_XFIXES_SET_PICTURE_CLIP_REGION
value|22
comment|/**  * @brief xcb_xfixes_set_picture_clip_region_request_t  **/
DECL|struct|xcb_xfixes_set_picture_clip_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_set_picture_clip_region_request_t
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
DECL|member|region
name|xcb_xfixes_region_t
name|region
decl_stmt|;
comment|/**<  */
DECL|member|x_origin
name|int16_t
name|x_origin
decl_stmt|;
comment|/**<  */
DECL|member|y_origin
name|int16_t
name|y_origin
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_set_picture_clip_region_request_t
name|xcb_xfixes_set_picture_clip_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_set_cursor_name. */
DECL|macro|XCB_XFIXES_SET_CURSOR_NAME
define|#
directive|define
name|XCB_XFIXES_SET_CURSOR_NAME
value|23
comment|/**  * @brief xcb_xfixes_set_cursor_name_request_t  **/
DECL|struct|xcb_xfixes_set_cursor_name_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_set_cursor_name_request_t
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
DECL|member|cursor
name|xcb_cursor_t
name|cursor
decl_stmt|;
comment|/**<  */
DECL|member|nbytes
name|uint16_t
name|nbytes
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
DECL|typedef|xcb_xfixes_set_cursor_name_request_t
name|xcb_xfixes_set_cursor_name_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_get_cursor_name_cookie_t  **/
DECL|struct|xcb_xfixes_get_cursor_name_cookie_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_name_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_get_cursor_name_cookie_t
name|xcb_xfixes_get_cursor_name_cookie_t
typedef|;
comment|/** Opcode for xcb_xfixes_get_cursor_name. */
DECL|macro|XCB_XFIXES_GET_CURSOR_NAME
define|#
directive|define
name|XCB_XFIXES_GET_CURSOR_NAME
value|24
comment|/**  * @brief xcb_xfixes_get_cursor_name_request_t  **/
DECL|struct|xcb_xfixes_get_cursor_name_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_name_request_t
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
DECL|member|cursor
name|xcb_cursor_t
name|cursor
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_get_cursor_name_request_t
name|xcb_xfixes_get_cursor_name_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_get_cursor_name_reply_t  **/
DECL|struct|xcb_xfixes_get_cursor_name_reply_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_name_reply_t
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
DECL|member|atom
name|xcb_atom_t
name|atom
decl_stmt|;
comment|/**<  */
DECL|member|nbytes
name|uint16_t
name|nbytes
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|18
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_get_cursor_name_reply_t
name|xcb_xfixes_get_cursor_name_reply_t
typedef|;
comment|/**  * @brief xcb_xfixes_get_cursor_image_and_name_cookie_t  **/
DECL|struct|xcb_xfixes_get_cursor_image_and_name_cookie_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_image_and_name_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_get_cursor_image_and_name_cookie_t
name|xcb_xfixes_get_cursor_image_and_name_cookie_t
typedef|;
comment|/** Opcode for xcb_xfixes_get_cursor_image_and_name. */
DECL|macro|XCB_XFIXES_GET_CURSOR_IMAGE_AND_NAME
define|#
directive|define
name|XCB_XFIXES_GET_CURSOR_IMAGE_AND_NAME
value|25
comment|/**  * @brief xcb_xfixes_get_cursor_image_and_name_request_t  **/
DECL|struct|xcb_xfixes_get_cursor_image_and_name_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_image_and_name_request_t
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
DECL|typedef|xcb_xfixes_get_cursor_image_and_name_request_t
name|xcb_xfixes_get_cursor_image_and_name_request_t
typedef|;
comment|/**  * @brief xcb_xfixes_get_cursor_image_and_name_reply_t  **/
DECL|struct|xcb_xfixes_get_cursor_image_and_name_reply_t
typedef|typedef
struct|struct
name|xcb_xfixes_get_cursor_image_and_name_reply_t
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
DECL|member|xhot
name|uint16_t
name|xhot
decl_stmt|;
comment|/**<  */
DECL|member|yhot
name|uint16_t
name|yhot
decl_stmt|;
comment|/**<  */
DECL|member|cursor_serial
name|uint32_t
name|cursor_serial
decl_stmt|;
comment|/**<  */
DECL|member|cursor_atom
name|xcb_atom_t
name|cursor_atom
decl_stmt|;
comment|/**<  */
DECL|member|nbytes
name|uint16_t
name|nbytes
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
block|}
DECL|typedef|xcb_xfixes_get_cursor_image_and_name_reply_t
name|xcb_xfixes_get_cursor_image_and_name_reply_t
typedef|;
comment|/** Opcode for xcb_xfixes_change_cursor. */
DECL|macro|XCB_XFIXES_CHANGE_CURSOR
define|#
directive|define
name|XCB_XFIXES_CHANGE_CURSOR
value|26
comment|/**  * @brief xcb_xfixes_change_cursor_request_t  **/
DECL|struct|xcb_xfixes_change_cursor_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_change_cursor_request_t
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
DECL|member|source
name|xcb_cursor_t
name|source
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_cursor_t
name|destination
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_change_cursor_request_t
name|xcb_xfixes_change_cursor_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_change_cursor_by_name. */
DECL|macro|XCB_XFIXES_CHANGE_CURSOR_BY_NAME
define|#
directive|define
name|XCB_XFIXES_CHANGE_CURSOR_BY_NAME
value|27
comment|/**  * @brief xcb_xfixes_change_cursor_by_name_request_t  **/
DECL|struct|xcb_xfixes_change_cursor_by_name_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_change_cursor_by_name_request_t
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
DECL|member|src
name|xcb_cursor_t
name|src
decl_stmt|;
comment|/**<  */
DECL|member|nbytes
name|uint16_t
name|nbytes
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
DECL|typedef|xcb_xfixes_change_cursor_by_name_request_t
name|xcb_xfixes_change_cursor_by_name_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_expand_region. */
DECL|macro|XCB_XFIXES_EXPAND_REGION
define|#
directive|define
name|XCB_XFIXES_EXPAND_REGION
value|28
comment|/**  * @brief xcb_xfixes_expand_region_request_t  **/
DECL|struct|xcb_xfixes_expand_region_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_expand_region_request_t
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
DECL|member|source
name|xcb_xfixes_region_t
name|source
decl_stmt|;
comment|/**<  */
DECL|member|destination
name|xcb_xfixes_region_t
name|destination
decl_stmt|;
comment|/**<  */
DECL|member|left
name|uint16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|right
name|uint16_t
name|right
decl_stmt|;
comment|/**<  */
DECL|member|top
name|uint16_t
name|top
decl_stmt|;
comment|/**<  */
DECL|member|bottom
name|uint16_t
name|bottom
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xfixes_expand_region_request_t
name|xcb_xfixes_expand_region_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_hide_cursor. */
DECL|macro|XCB_XFIXES_HIDE_CURSOR
define|#
directive|define
name|XCB_XFIXES_HIDE_CURSOR
value|29
comment|/**  * @brief xcb_xfixes_hide_cursor_request_t  **/
DECL|struct|xcb_xfixes_hide_cursor_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_hide_cursor_request_t
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
block|}
DECL|typedef|xcb_xfixes_hide_cursor_request_t
name|xcb_xfixes_hide_cursor_request_t
typedef|;
comment|/** Opcode for xcb_xfixes_show_cursor. */
DECL|macro|XCB_XFIXES_SHOW_CURSOR
define|#
directive|define
name|XCB_XFIXES_SHOW_CURSOR
value|30
comment|/**  * @brief xcb_xfixes_show_cursor_request_t  **/
DECL|struct|xcb_xfixes_show_cursor_request_t
typedef|typedef
struct|struct
name|xcb_xfixes_show_cursor_request_t
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
block|}
DECL|typedef|xcb_xfixes_show_cursor_request_t
name|xcb_xfixes_show_cursor_request_t
typedef|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xfixes_query_version_cookie_t xcb_xfixes_query_version  **   ** @param xcb_connection_t *c  ** @param uint32_t          client_major_version  ** @param uint32_t          client_minor_version  ** @returns xcb_xfixes_query_version_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_query_version_cookie_t
name|xcb_xfixes_query_version
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
comment|/*****************************************************************************  **  ** xcb_xfixes_query_version_cookie_t xcb_xfixes_query_version_unchecked  **   ** @param xcb_connection_t *c  ** @param uint32_t          client_major_version  ** @param uint32_t          client_minor_version  ** @returns xcb_xfixes_query_version_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_query_version_cookie_t
name|xcb_xfixes_query_version_unchecked
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
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xfixes_query_version_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xfixes_query_version_reply_t * xcb_xfixes_query_version_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_xfixes_query_version_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_xfixes_query_version_reply_t *  **  *****************************************************************************/
name|xcb_xfixes_query_version_reply_t
modifier|*
name|xcb_xfixes_query_version_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_query_version_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_change_save_set_checked  **   ** @param xcb_connection_t *c  ** @param uint8_t           mode  ** @param uint8_t           target  ** @param uint8_t           map  ** @param xcb_window_t      window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_change_save_set_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|mode
comment|/**< */
parameter_list|,
name|uint8_t
name|target
comment|/**< */
parameter_list|,
name|uint8_t
name|map
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_change_save_set  **   ** @param xcb_connection_t *c  ** @param uint8_t           mode  ** @param uint8_t           target  ** @param uint8_t           map  ** @param xcb_window_t      window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_change_save_set
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|mode
comment|/**< */
parameter_list|,
name|uint8_t
name|target
comment|/**< */
parameter_list|,
name|uint8_t
name|map
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_select_selection_input_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param xcb_atom_t        selection  ** @param uint32_t          event_mask  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_select_selection_input_checked
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
name|xcb_atom_t
name|selection
comment|/**< */
parameter_list|,
name|uint32_t
name|event_mask
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_select_selection_input  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param xcb_atom_t        selection  ** @param uint32_t          event_mask  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_select_selection_input
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
name|xcb_atom_t
name|selection
comment|/**< */
parameter_list|,
name|uint32_t
name|event_mask
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_select_cursor_input_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint32_t          event_mask  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_select_cursor_input_checked
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
name|uint32_t
name|event_mask
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_select_cursor_input  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint32_t          event_mask  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_select_cursor_input
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
name|uint32_t
name|event_mask
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_image_cookie_t xcb_xfixes_get_cursor_image  **   ** @param xcb_connection_t *c  ** @returns xcb_xfixes_get_cursor_image_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_image_cookie_t
name|xcb_xfixes_get_cursor_image
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_image_cookie_t xcb_xfixes_get_cursor_image_unchecked  **   ** @param xcb_connection_t *c  ** @returns xcb_xfixes_get_cursor_image_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_image_cookie_t
name|xcb_xfixes_get_cursor_image_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint32_t * xcb_xfixes_get_cursor_image_cursor_image  **   ** @param const xcb_xfixes_get_cursor_image_reply_t *R  ** @returns uint32_t *  **  *****************************************************************************/
name|uint32_t
modifier|*
name|xcb_xfixes_get_cursor_image_cursor_image
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xfixes_get_cursor_image_cursor_image_length  **   ** @param const xcb_xfixes_get_cursor_image_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xfixes_get_cursor_image_cursor_image_length
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xfixes_get_cursor_image_cursor_image_end  **   ** @param const xcb_xfixes_get_cursor_image_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xfixes_get_cursor_image_cursor_image_end
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xfixes_get_cursor_image_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_image_reply_t * xcb_xfixes_get_cursor_image_reply  **   ** @param xcb_connection_t                      *c  ** @param xcb_xfixes_get_cursor_image_cookie_t   cookie  ** @param xcb_generic_error_t                  **e  ** @returns xcb_xfixes_get_cursor_image_reply_t *  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_image_reply_t
modifier|*
name|xcb_xfixes_get_cursor_image_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_get_cursor_image_cookie_t
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
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xfixes_region_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xfixes_region_t)  */
comment|/*****************************************************************************  **  ** void xcb_xfixes_region_next  **   ** @param xcb_xfixes_region_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xfixes_region_next
parameter_list|(
name|xcb_xfixes_region_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xfixes_region_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xfixes_region_end  **   ** @param xcb_xfixes_region_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xfixes_region_end
parameter_list|(
name|xcb_xfixes_region_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xfixes_region_t    region  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region  **   ** @param xcb_connection_t      *c  ** @param xcb_xfixes_region_t    region  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_bitmap_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param xcb_pixmap_t         bitmap  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_bitmap_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_pixmap_t
name|bitmap
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_bitmap  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param xcb_pixmap_t         bitmap  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_bitmap
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_pixmap_t
name|bitmap
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_window_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param xcb_window_t         window  ** @param xcb_shape_kind_t     kind  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_window_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|kind
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_window  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param xcb_window_t         window  ** @param xcb_shape_kind_t     kind  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_window
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|kind
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_gc_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param xcb_gcontext_t       gc  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_gc_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_gcontext_t
name|gc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_gc  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param xcb_gcontext_t       gc  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_gc
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_gcontext_t
name|gc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_picture_checked  **   ** @param xcb_connection_t     *c  ** @param xcb_xfixes_region_t   region  ** @param xcb_render_picture_t  picture  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_picture_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_create_region_from_picture  **   ** @param xcb_connection_t     *c  ** @param xcb_xfixes_region_t   region  ** @param xcb_render_picture_t  picture  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_create_region_from_picture
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|xcb_render_picture_t
name|picture
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_destroy_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_destroy_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_destroy_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_destroy_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_region_checked  **   ** @param xcb_connection_t      *c  ** @param xcb_xfixes_region_t    region  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_region  **   ** @param xcb_connection_t      *c  ** @param xcb_xfixes_region_t    region  ** @param uint32_t               rectangles_len  ** @param const xcb_rectangle_t *rectangles  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_copy_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_copy_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_copy_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_copy_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_union_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source1  ** @param xcb_xfixes_region_t  source2  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_union_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source1
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source2
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_union_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source1  ** @param xcb_xfixes_region_t  source2  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_union_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source1
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source2
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_intersect_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source1  ** @param xcb_xfixes_region_t  source2  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_intersect_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source1
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source2
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_intersect_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source1  ** @param xcb_xfixes_region_t  source2  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_intersect_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source1
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source2
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_subtract_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source1  ** @param xcb_xfixes_region_t  source2  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_subtract_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source1
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source2
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_subtract_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source1  ** @param xcb_xfixes_region_t  source2  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_subtract_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source1
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source2
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_invert_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_rectangle_t      bounds  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_invert_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_rectangle_t
name|bounds
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_invert_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_rectangle_t      bounds  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_invert_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_rectangle_t
name|bounds
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_translate_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param int16_t              dx  ** @param int16_t              dy  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_translate_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|int16_t
name|dx
comment|/**< */
parameter_list|,
name|int16_t
name|dy
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_translate_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @param int16_t              dx  ** @param int16_t              dy  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_translate_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|int16_t
name|dx
comment|/**< */
parameter_list|,
name|int16_t
name|dy
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_region_extents_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_region_extents_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_region_extents  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_xfixes_region_t  destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_region_extents
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xfixes_fetch_region_cookie_t xcb_xfixes_fetch_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @returns xcb_xfixes_fetch_region_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_fetch_region_cookie_t
name|xcb_xfixes_fetch_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xfixes_fetch_region_cookie_t xcb_xfixes_fetch_region_unchecked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  region  ** @returns xcb_xfixes_fetch_region_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_fetch_region_cookie_t
name|xcb_xfixes_fetch_region_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_rectangle_t * xcb_xfixes_fetch_region_rectangles  **   ** @param const xcb_xfixes_fetch_region_reply_t *R  ** @returns xcb_rectangle_t *  **  *****************************************************************************/
name|xcb_rectangle_t
modifier|*
name|xcb_xfixes_fetch_region_rectangles
parameter_list|(
specifier|const
name|xcb_xfixes_fetch_region_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xfixes_fetch_region_rectangles_length  **   ** @param const xcb_xfixes_fetch_region_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xfixes_fetch_region_rectangles_length
parameter_list|(
specifier|const
name|xcb_xfixes_fetch_region_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_rectangle_iterator_t xcb_xfixes_fetch_region_rectangles_iterator  **   ** @param const xcb_xfixes_fetch_region_reply_t *R  ** @returns xcb_rectangle_iterator_t  **  *****************************************************************************/
name|xcb_rectangle_iterator_t
name|xcb_xfixes_fetch_region_rectangles_iterator
parameter_list|(
specifier|const
name|xcb_xfixes_fetch_region_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xfixes_fetch_region_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xfixes_fetch_region_reply_t * xcb_xfixes_fetch_region_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_xfixes_fetch_region_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_xfixes_fetch_region_reply_t *  **  *****************************************************************************/
name|xcb_xfixes_fetch_region_reply_t
modifier|*
name|xcb_xfixes_fetch_region_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_fetch_region_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_gc_clip_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_gcontext_t       gc  ** @param xcb_xfixes_region_t  region  ** @param int16_t              x_origin  ** @param int16_t              y_origin  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_gc_clip_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_gcontext_t
name|gc
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|int16_t
name|x_origin
comment|/**< */
parameter_list|,
name|int16_t
name|y_origin
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_gc_clip_region  **   ** @param xcb_connection_t    *c  ** @param xcb_gcontext_t       gc  ** @param xcb_xfixes_region_t  region  ** @param int16_t              x_origin  ** @param int16_t              y_origin  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_gc_clip_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_gcontext_t
name|gc
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|int16_t
name|x_origin
comment|/**< */
parameter_list|,
name|int16_t
name|y_origin
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_window_shape_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_window_t         dest  ** @param xcb_shape_kind_t     dest_kind  ** @param int16_t              x_offset  ** @param int16_t              y_offset  ** @param xcb_xfixes_region_t  region  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_window_shape_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|dest
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|dest_kind
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
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_window_shape_region  **   ** @param xcb_connection_t    *c  ** @param xcb_window_t         dest  ** @param xcb_shape_kind_t     dest_kind  ** @param int16_t              x_offset  ** @param int16_t              y_offset  ** @param xcb_xfixes_region_t  region  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_window_shape_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|dest
comment|/**< */
parameter_list|,
name|xcb_shape_kind_t
name|dest_kind
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
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_picture_clip_region_checked  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @param xcb_xfixes_region_t   region  ** @param int16_t               x_origin  ** @param int16_t               y_origin  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_picture_clip_region_checked
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
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|int16_t
name|x_origin
comment|/**< */
parameter_list|,
name|int16_t
name|y_origin
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_picture_clip_region  **   ** @param xcb_connection_t     *c  ** @param xcb_render_picture_t  picture  ** @param xcb_xfixes_region_t   region  ** @param int16_t               x_origin  ** @param int16_t               y_origin  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_picture_clip_region
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
name|xcb_xfixes_region_t
name|region
comment|/**< */
parameter_list|,
name|int16_t
name|x_origin
comment|/**< */
parameter_list|,
name|int16_t
name|y_origin
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_cursor_name_checked  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      cursor  ** @param uint16_t          nbytes  ** @param const char       *name  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_cursor_name_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cursor
comment|/**< */
parameter_list|,
name|uint16_t
name|nbytes
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_set_cursor_name  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      cursor  ** @param uint16_t          nbytes  ** @param const char       *name  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_set_cursor_name
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cursor
comment|/**< */
parameter_list|,
name|uint16_t
name|nbytes
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_name_cookie_t xcb_xfixes_get_cursor_name  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      cursor  ** @returns xcb_xfixes_get_cursor_name_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_name_cookie_t
name|xcb_xfixes_get_cursor_name
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cursor
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_name_cookie_t xcb_xfixes_get_cursor_name_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      cursor  ** @returns xcb_xfixes_get_cursor_name_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_name_cookie_t
name|xcb_xfixes_get_cursor_name_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|cursor
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** char * xcb_xfixes_get_cursor_name_name  **   ** @param const xcb_xfixes_get_cursor_name_reply_t *R  ** @returns char *  **  *****************************************************************************/
name|char
modifier|*
name|xcb_xfixes_get_cursor_name_name
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xfixes_get_cursor_name_name_length  **   ** @param const xcb_xfixes_get_cursor_name_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xfixes_get_cursor_name_name_length
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xfixes_get_cursor_name_name_end  **   ** @param const xcb_xfixes_get_cursor_name_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xfixes_get_cursor_name_name_end
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xfixes_get_cursor_name_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_name_reply_t * xcb_xfixes_get_cursor_name_reply  **   ** @param xcb_connection_t                     *c  ** @param xcb_xfixes_get_cursor_name_cookie_t   cookie  ** @param xcb_generic_error_t                 **e  ** @returns xcb_xfixes_get_cursor_name_reply_t *  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_name_reply_t
modifier|*
name|xcb_xfixes_get_cursor_name_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_get_cursor_name_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_image_and_name_cookie_t xcb_xfixes_get_cursor_image_and_name  **   ** @param xcb_connection_t *c  ** @returns xcb_xfixes_get_cursor_image_and_name_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_image_and_name_cookie_t
name|xcb_xfixes_get_cursor_image_and_name
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_image_and_name_cookie_t xcb_xfixes_get_cursor_image_and_name_unchecked  **   ** @param xcb_connection_t *c  ** @returns xcb_xfixes_get_cursor_image_and_name_cookie_t  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_image_and_name_cookie_t
name|xcb_xfixes_get_cursor_image_and_name_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** char * xcb_xfixes_get_cursor_image_and_name_name  **   ** @param const xcb_xfixes_get_cursor_image_and_name_reply_t *R  ** @returns char *  **  *****************************************************************************/
name|char
modifier|*
name|xcb_xfixes_get_cursor_image_and_name_name
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xfixes_get_cursor_image_and_name_name_length  **   ** @param const xcb_xfixes_get_cursor_image_and_name_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xfixes_get_cursor_image_and_name_name_length
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xfixes_get_cursor_image_and_name_name_end  **   ** @param const xcb_xfixes_get_cursor_image_and_name_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xfixes_get_cursor_image_and_name_name_end
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint32_t * xcb_xfixes_get_cursor_image_and_name_cursor_image  **   ** @param const xcb_xfixes_get_cursor_image_and_name_reply_t *R  ** @returns uint32_t *  **  *****************************************************************************/
name|uint32_t
modifier|*
name|xcb_xfixes_get_cursor_image_and_name_cursor_image
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xfixes_get_cursor_image_and_name_cursor_image_length  **   ** @param const xcb_xfixes_get_cursor_image_and_name_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xfixes_get_cursor_image_and_name_cursor_image_length
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xfixes_get_cursor_image_and_name_cursor_image_end  **   ** @param const xcb_xfixes_get_cursor_image_and_name_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xfixes_get_cursor_image_and_name_cursor_image_end
parameter_list|(
specifier|const
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_xfixes_get_cursor_image_and_name_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xfixes_get_cursor_image_and_name_reply_t * xcb_xfixes_get_cursor_image_and_name_reply  **   ** @param xcb_connection_t                               *c  ** @param xcb_xfixes_get_cursor_image_and_name_cookie_t   cookie  ** @param xcb_generic_error_t                           **e  ** @returns xcb_xfixes_get_cursor_image_and_name_reply_t *  **  *****************************************************************************/
name|xcb_xfixes_get_cursor_image_and_name_reply_t
modifier|*
name|xcb_xfixes_get_cursor_image_and_name_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_get_cursor_image_and_name_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_change_cursor_checked  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      source  ** @param xcb_cursor_t      destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_change_cursor_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|source
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_change_cursor  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      source  ** @param xcb_cursor_t      destination  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_change_cursor
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|source
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|destination
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_change_cursor_by_name_checked  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      src  ** @param uint16_t          nbytes  ** @param const char       *name  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_change_cursor_by_name_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|src
comment|/**< */
parameter_list|,
name|uint16_t
name|nbytes
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_change_cursor_by_name  **   ** @param xcb_connection_t *c  ** @param xcb_cursor_t      src  ** @param uint16_t          nbytes  ** @param const char       *name  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_change_cursor_by_name
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_cursor_t
name|src
comment|/**< */
parameter_list|,
name|uint16_t
name|nbytes
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_expand_region_checked  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_xfixes_region_t  destination  ** @param uint16_t             left  ** @param uint16_t             right  ** @param uint16_t             top  ** @param uint16_t             bottom  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_expand_region_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|,
name|uint16_t
name|left
comment|/**< */
parameter_list|,
name|uint16_t
name|right
comment|/**< */
parameter_list|,
name|uint16_t
name|top
comment|/**< */
parameter_list|,
name|uint16_t
name|bottom
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_expand_region  **   ** @param xcb_connection_t    *c  ** @param xcb_xfixes_region_t  source  ** @param xcb_xfixes_region_t  destination  ** @param uint16_t             left  ** @param uint16_t             right  ** @param uint16_t             top  ** @param uint16_t             bottom  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_expand_region
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|source
comment|/**< */
parameter_list|,
name|xcb_xfixes_region_t
name|destination
comment|/**< */
parameter_list|,
name|uint16_t
name|left
comment|/**< */
parameter_list|,
name|uint16_t
name|right
comment|/**< */
parameter_list|,
name|uint16_t
name|top
comment|/**< */
parameter_list|,
name|uint16_t
name|bottom
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_hide_cursor_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_hide_cursor_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_hide_cursor  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_hide_cursor
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_show_cursor_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_show_cursor_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_xfixes_show_cursor  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_xfixes_show_cursor
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_window_t
name|window
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
