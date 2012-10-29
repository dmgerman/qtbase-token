begin_unit
begin_comment
comment|/*  * This file generated automatically from randr.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_RandR_API XCB RandR API  * @brief RandR XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__RANDR_H
end_ifndef
begin_define
DECL|macro|__RANDR_H
define|#
directive|define
name|__RANDR_H
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
DECL|macro|XCB_RANDR_MAJOR_VERSION
define|#
directive|define
name|XCB_RANDR_MAJOR_VERSION
value|1
DECL|macro|XCB_RANDR_MINOR_VERSION
define|#
directive|define
name|XCB_RANDR_MINOR_VERSION
value|3
specifier|extern
name|xcb_extension_t
name|xcb_randr_id
decl_stmt|;
DECL|typedef|xcb_randr_mode_t
typedef|typedef
name|uint32_t
name|xcb_randr_mode_t
typedef|;
comment|/**  * @brief xcb_randr_mode_iterator_t  **/
DECL|struct|xcb_randr_mode_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_mode_iterator_t
block|{
DECL|member|data
name|xcb_randr_mode_t
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
DECL|typedef|xcb_randr_mode_iterator_t
name|xcb_randr_mode_iterator_t
typedef|;
DECL|typedef|xcb_randr_crtc_t
typedef|typedef
name|uint32_t
name|xcb_randr_crtc_t
typedef|;
comment|/**  * @brief xcb_randr_crtc_iterator_t  **/
DECL|struct|xcb_randr_crtc_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_crtc_iterator_t
block|{
DECL|member|data
name|xcb_randr_crtc_t
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
DECL|typedef|xcb_randr_crtc_iterator_t
name|xcb_randr_crtc_iterator_t
typedef|;
DECL|typedef|xcb_randr_output_t
typedef|typedef
name|uint32_t
name|xcb_randr_output_t
typedef|;
comment|/**  * @brief xcb_randr_output_iterator_t  **/
DECL|struct|xcb_randr_output_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_output_iterator_t
block|{
DECL|member|data
name|xcb_randr_output_t
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
DECL|typedef|xcb_randr_output_iterator_t
name|xcb_randr_output_iterator_t
typedef|;
comment|/** Opcode for xcb_randr_bad_output. */
DECL|macro|XCB_RANDR_BAD_OUTPUT
define|#
directive|define
name|XCB_RANDR_BAD_OUTPUT
value|0
comment|/**  * @brief xcb_randr_bad_output_error_t  **/
DECL|struct|xcb_randr_bad_output_error_t
typedef|typedef
struct|struct
name|xcb_randr_bad_output_error_t
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
DECL|typedef|xcb_randr_bad_output_error_t
name|xcb_randr_bad_output_error_t
typedef|;
comment|/** Opcode for xcb_randr_bad_crtc. */
DECL|macro|XCB_RANDR_BAD_CRTC
define|#
directive|define
name|XCB_RANDR_BAD_CRTC
value|1
comment|/**  * @brief xcb_randr_bad_crtc_error_t  **/
DECL|struct|xcb_randr_bad_crtc_error_t
typedef|typedef
struct|struct
name|xcb_randr_bad_crtc_error_t
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
DECL|typedef|xcb_randr_bad_crtc_error_t
name|xcb_randr_bad_crtc_error_t
typedef|;
comment|/** Opcode for xcb_randr_bad_mode. */
DECL|macro|XCB_RANDR_BAD_MODE
define|#
directive|define
name|XCB_RANDR_BAD_MODE
value|2
comment|/**  * @brief xcb_randr_bad_mode_error_t  **/
DECL|struct|xcb_randr_bad_mode_error_t
typedef|typedef
struct|struct
name|xcb_randr_bad_mode_error_t
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
DECL|typedef|xcb_randr_bad_mode_error_t
name|xcb_randr_bad_mode_error_t
typedef|;
DECL|enum|xcb_randr_rotation_t
typedef|typedef
enum|enum
name|xcb_randr_rotation_t
block|{
DECL|enumerator|XCB_RANDR_ROTATION_ROTATE_0
name|XCB_RANDR_ROTATION_ROTATE_0
init|=
literal|1
block|,
DECL|enumerator|XCB_RANDR_ROTATION_ROTATE_90
name|XCB_RANDR_ROTATION_ROTATE_90
init|=
literal|2
block|,
DECL|enumerator|XCB_RANDR_ROTATION_ROTATE_180
name|XCB_RANDR_ROTATION_ROTATE_180
init|=
literal|4
block|,
DECL|enumerator|XCB_RANDR_ROTATION_ROTATE_270
name|XCB_RANDR_ROTATION_ROTATE_270
init|=
literal|8
block|,
DECL|enumerator|XCB_RANDR_ROTATION_REFLECT_X
name|XCB_RANDR_ROTATION_REFLECT_X
init|=
literal|16
block|,
DECL|enumerator|XCB_RANDR_ROTATION_REFLECT_Y
name|XCB_RANDR_ROTATION_REFLECT_Y
init|=
literal|32
block|}
DECL|typedef|xcb_randr_rotation_t
name|xcb_randr_rotation_t
typedef|;
comment|/**  * @brief xcb_randr_screen_size_t  **/
DECL|struct|xcb_randr_screen_size_t
typedef|typedef
struct|struct
name|xcb_randr_screen_size_t
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
DECL|member|mwidth
name|uint16_t
name|mwidth
decl_stmt|;
comment|/**<  */
DECL|member|mheight
name|uint16_t
name|mheight
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_screen_size_t
name|xcb_randr_screen_size_t
typedef|;
comment|/**  * @brief xcb_randr_screen_size_iterator_t  **/
DECL|struct|xcb_randr_screen_size_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_screen_size_iterator_t
block|{
DECL|member|data
name|xcb_randr_screen_size_t
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
DECL|typedef|xcb_randr_screen_size_iterator_t
name|xcb_randr_screen_size_iterator_t
typedef|;
comment|/**  * @brief xcb_randr_refresh_rates_t  **/
DECL|struct|xcb_randr_refresh_rates_t
typedef|typedef
struct|struct
name|xcb_randr_refresh_rates_t
block|{
DECL|member|nRates
name|uint16_t
name|nRates
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_refresh_rates_t
name|xcb_randr_refresh_rates_t
typedef|;
comment|/**  * @brief xcb_randr_refresh_rates_iterator_t  **/
DECL|struct|xcb_randr_refresh_rates_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_refresh_rates_iterator_t
block|{
DECL|member|data
name|xcb_randr_refresh_rates_t
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
DECL|typedef|xcb_randr_refresh_rates_iterator_t
name|xcb_randr_refresh_rates_iterator_t
typedef|;
comment|/**  * @brief xcb_randr_query_version_cookie_t  **/
DECL|struct|xcb_randr_query_version_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_query_version_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_query_version_cookie_t
name|xcb_randr_query_version_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_query_version. */
DECL|macro|XCB_RANDR_QUERY_VERSION
define|#
directive|define
name|XCB_RANDR_QUERY_VERSION
value|0
comment|/**  * @brief xcb_randr_query_version_request_t  **/
DECL|struct|xcb_randr_query_version_request_t
typedef|typedef
struct|struct
name|xcb_randr_query_version_request_t
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
block|}
DECL|typedef|xcb_randr_query_version_request_t
name|xcb_randr_query_version_request_t
typedef|;
comment|/**  * @brief xcb_randr_query_version_reply_t  **/
DECL|struct|xcb_randr_query_version_reply_t
typedef|typedef
struct|struct
name|xcb_randr_query_version_reply_t
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
DECL|typedef|xcb_randr_query_version_reply_t
name|xcb_randr_query_version_reply_t
typedef|;
DECL|enum|xcb_randr_set_config_t
typedef|typedef
enum|enum
name|xcb_randr_set_config_t
block|{
DECL|enumerator|XCB_RANDR_SET_CONFIG_SUCCESS
name|XCB_RANDR_SET_CONFIG_SUCCESS
init|=
literal|0
block|,
DECL|enumerator|XCB_RANDR_SET_CONFIG_INVALID_CONFIG_TIME
name|XCB_RANDR_SET_CONFIG_INVALID_CONFIG_TIME
init|=
literal|1
block|,
DECL|enumerator|XCB_RANDR_SET_CONFIG_INVALID_TIME
name|XCB_RANDR_SET_CONFIG_INVALID_TIME
init|=
literal|2
block|,
DECL|enumerator|XCB_RANDR_SET_CONFIG_FAILED
name|XCB_RANDR_SET_CONFIG_FAILED
init|=
literal|3
block|}
DECL|typedef|xcb_randr_set_config_t
name|xcb_randr_set_config_t
typedef|;
comment|/**  * @brief xcb_randr_set_screen_config_cookie_t  **/
DECL|struct|xcb_randr_set_screen_config_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_set_screen_config_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_screen_config_cookie_t
name|xcb_randr_set_screen_config_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_set_screen_config. */
DECL|macro|XCB_RANDR_SET_SCREEN_CONFIG
define|#
directive|define
name|XCB_RANDR_SET_SCREEN_CONFIG
value|2
comment|/**  * @brief xcb_randr_set_screen_config_request_t  **/
DECL|struct|xcb_randr_set_screen_config_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_screen_config_request_t
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|sizeID
name|uint16_t
name|sizeID
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint16_t
name|rotation
decl_stmt|;
comment|/**<  */
DECL|member|rate
name|uint16_t
name|rate
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
DECL|typedef|xcb_randr_set_screen_config_request_t
name|xcb_randr_set_screen_config_request_t
typedef|;
comment|/**  * @brief xcb_randr_set_screen_config_reply_t  **/
DECL|struct|xcb_randr_set_screen_config_reply_t
typedef|typedef
struct|struct
name|xcb_randr_set_screen_config_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|member|new_timestamp
name|xcb_timestamp_t
name|new_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|root
name|xcb_window_t
name|root
decl_stmt|;
comment|/**<  */
DECL|member|subpixel_order
name|uint16_t
name|subpixel_order
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|10
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_screen_config_reply_t
name|xcb_randr_set_screen_config_reply_t
typedef|;
DECL|enum|xcb_randr_notify_mask_t
typedef|typedef
enum|enum
name|xcb_randr_notify_mask_t
block|{
DECL|enumerator|XCB_RANDR_NOTIFY_MASK_SCREEN_CHANGE
name|XCB_RANDR_NOTIFY_MASK_SCREEN_CHANGE
init|=
literal|1
block|,
DECL|enumerator|XCB_RANDR_NOTIFY_MASK_CRTC_CHANGE
name|XCB_RANDR_NOTIFY_MASK_CRTC_CHANGE
init|=
literal|2
block|,
DECL|enumerator|XCB_RANDR_NOTIFY_MASK_OUTPUT_CHANGE
name|XCB_RANDR_NOTIFY_MASK_OUTPUT_CHANGE
init|=
literal|4
block|,
DECL|enumerator|XCB_RANDR_NOTIFY_MASK_OUTPUT_PROPERTY
name|XCB_RANDR_NOTIFY_MASK_OUTPUT_PROPERTY
init|=
literal|8
block|}
DECL|typedef|xcb_randr_notify_mask_t
name|xcb_randr_notify_mask_t
typedef|;
comment|/** Opcode for xcb_randr_select_input. */
DECL|macro|XCB_RANDR_SELECT_INPUT
define|#
directive|define
name|XCB_RANDR_SELECT_INPUT
value|4
comment|/**  * @brief xcb_randr_select_input_request_t  **/
DECL|struct|xcb_randr_select_input_request_t
typedef|typedef
struct|struct
name|xcb_randr_select_input_request_t
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
DECL|member|enable
name|uint16_t
name|enable
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
DECL|typedef|xcb_randr_select_input_request_t
name|xcb_randr_select_input_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_info_cookie_t  **/
DECL|struct|xcb_randr_get_screen_info_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_info_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_screen_info_cookie_t
name|xcb_randr_get_screen_info_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_screen_info. */
DECL|macro|XCB_RANDR_GET_SCREEN_INFO
define|#
directive|define
name|XCB_RANDR_GET_SCREEN_INFO
value|5
comment|/**  * @brief xcb_randr_get_screen_info_request_t  **/
DECL|struct|xcb_randr_get_screen_info_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_info_request_t
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
DECL|typedef|xcb_randr_get_screen_info_request_t
name|xcb_randr_get_screen_info_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_info_reply_t  **/
DECL|struct|xcb_randr_get_screen_info_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_info_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|rotations
name|uint8_t
name|rotations
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
DECL|member|root
name|xcb_window_t
name|root
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|nSizes
name|uint16_t
name|nSizes
decl_stmt|;
comment|/**<  */
DECL|member|sizeID
name|uint16_t
name|sizeID
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint16_t
name|rotation
decl_stmt|;
comment|/**<  */
DECL|member|rate
name|uint16_t
name|rate
decl_stmt|;
comment|/**<  */
DECL|member|nInfo
name|uint16_t
name|nInfo
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
DECL|typedef|xcb_randr_get_screen_info_reply_t
name|xcb_randr_get_screen_info_reply_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_size_range_cookie_t  **/
DECL|struct|xcb_randr_get_screen_size_range_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_size_range_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_screen_size_range_cookie_t
name|xcb_randr_get_screen_size_range_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_screen_size_range. */
DECL|macro|XCB_RANDR_GET_SCREEN_SIZE_RANGE
define|#
directive|define
name|XCB_RANDR_GET_SCREEN_SIZE_RANGE
value|6
comment|/**  * @brief xcb_randr_get_screen_size_range_request_t  **/
DECL|struct|xcb_randr_get_screen_size_range_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_size_range_request_t
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
DECL|typedef|xcb_randr_get_screen_size_range_request_t
name|xcb_randr_get_screen_size_range_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_size_range_reply_t  **/
DECL|struct|xcb_randr_get_screen_size_range_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_size_range_reply_t
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
DECL|member|min_width
name|uint16_t
name|min_width
decl_stmt|;
comment|/**<  */
DECL|member|min_height
name|uint16_t
name|min_height
decl_stmt|;
comment|/**<  */
DECL|member|max_width
name|uint16_t
name|max_width
decl_stmt|;
comment|/**<  */
DECL|member|max_height
name|uint16_t
name|max_height
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
DECL|typedef|xcb_randr_get_screen_size_range_reply_t
name|xcb_randr_get_screen_size_range_reply_t
typedef|;
comment|/** Opcode for xcb_randr_set_screen_size. */
DECL|macro|XCB_RANDR_SET_SCREEN_SIZE
define|#
directive|define
name|XCB_RANDR_SET_SCREEN_SIZE
value|7
comment|/**  * @brief xcb_randr_set_screen_size_request_t  **/
DECL|struct|xcb_randr_set_screen_size_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_screen_size_request_t
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
DECL|member|mm_width
name|uint32_t
name|mm_width
decl_stmt|;
comment|/**<  */
DECL|member|mm_height
name|uint32_t
name|mm_height
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_screen_size_request_t
name|xcb_randr_set_screen_size_request_t
typedef|;
DECL|enum|xcb_randr_mode_flag_t
typedef|typedef
enum|enum
name|xcb_randr_mode_flag_t
block|{
DECL|enumerator|XCB_RANDR_MODE_FLAG_HSYNC_POSITIVE
name|XCB_RANDR_MODE_FLAG_HSYNC_POSITIVE
init|=
literal|1
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_HSYNC_NEGATIVE
name|XCB_RANDR_MODE_FLAG_HSYNC_NEGATIVE
init|=
literal|2
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_VSYNC_POSITIVE
name|XCB_RANDR_MODE_FLAG_VSYNC_POSITIVE
init|=
literal|4
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_VSYNC_NEGATIVE
name|XCB_RANDR_MODE_FLAG_VSYNC_NEGATIVE
init|=
literal|8
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_INTERLACE
name|XCB_RANDR_MODE_FLAG_INTERLACE
init|=
literal|16
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_DOUBLE_SCAN
name|XCB_RANDR_MODE_FLAG_DOUBLE_SCAN
init|=
literal|32
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_CSYNC
name|XCB_RANDR_MODE_FLAG_CSYNC
init|=
literal|64
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_CSYNC_POSITIVE
name|XCB_RANDR_MODE_FLAG_CSYNC_POSITIVE
init|=
literal|128
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_CSYNC_NEGATIVE
name|XCB_RANDR_MODE_FLAG_CSYNC_NEGATIVE
init|=
literal|256
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_HSKEW_PRESENT
name|XCB_RANDR_MODE_FLAG_HSKEW_PRESENT
init|=
literal|512
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_BCAST
name|XCB_RANDR_MODE_FLAG_BCAST
init|=
literal|1024
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_PIXEL_MULTIPLEX
name|XCB_RANDR_MODE_FLAG_PIXEL_MULTIPLEX
init|=
literal|2048
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_DOUBLE_CLOCK
name|XCB_RANDR_MODE_FLAG_DOUBLE_CLOCK
init|=
literal|4096
block|,
DECL|enumerator|XCB_RANDR_MODE_FLAG_HALVE_CLOCK
name|XCB_RANDR_MODE_FLAG_HALVE_CLOCK
init|=
literal|8192
block|}
DECL|typedef|xcb_randr_mode_flag_t
name|xcb_randr_mode_flag_t
typedef|;
comment|/**  * @brief xcb_randr_mode_info_t  **/
DECL|struct|xcb_randr_mode_info_t
typedef|typedef
struct|struct
name|xcb_randr_mode_info_t
block|{
DECL|member|id
name|uint32_t
name|id
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
DECL|member|dot_clock
name|uint32_t
name|dot_clock
decl_stmt|;
comment|/**<  */
DECL|member|hsync_start
name|uint16_t
name|hsync_start
decl_stmt|;
comment|/**<  */
DECL|member|hsync_end
name|uint16_t
name|hsync_end
decl_stmt|;
comment|/**<  */
DECL|member|htotal
name|uint16_t
name|htotal
decl_stmt|;
comment|/**<  */
DECL|member|hskew
name|uint16_t
name|hskew
decl_stmt|;
comment|/**<  */
DECL|member|vsync_start
name|uint16_t
name|vsync_start
decl_stmt|;
comment|/**<  */
DECL|member|vsync_end
name|uint16_t
name|vsync_end
decl_stmt|;
comment|/**<  */
DECL|member|vtotal
name|uint16_t
name|vtotal
decl_stmt|;
comment|/**<  */
DECL|member|name_len
name|uint16_t
name|name_len
decl_stmt|;
comment|/**<  */
DECL|member|mode_flags
name|uint32_t
name|mode_flags
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_mode_info_t
name|xcb_randr_mode_info_t
typedef|;
comment|/**  * @brief xcb_randr_mode_info_iterator_t  **/
DECL|struct|xcb_randr_mode_info_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_mode_info_iterator_t
block|{
DECL|member|data
name|xcb_randr_mode_info_t
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
DECL|typedef|xcb_randr_mode_info_iterator_t
name|xcb_randr_mode_info_iterator_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_resources_cookie_t  **/
DECL|struct|xcb_randr_get_screen_resources_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_resources_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_screen_resources_cookie_t
name|xcb_randr_get_screen_resources_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_screen_resources. */
DECL|macro|XCB_RANDR_GET_SCREEN_RESOURCES
define|#
directive|define
name|XCB_RANDR_GET_SCREEN_RESOURCES
value|8
comment|/**  * @brief xcb_randr_get_screen_resources_request_t  **/
DECL|struct|xcb_randr_get_screen_resources_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_resources_request_t
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
DECL|typedef|xcb_randr_get_screen_resources_request_t
name|xcb_randr_get_screen_resources_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_resources_reply_t  **/
DECL|struct|xcb_randr_get_screen_resources_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_resources_reply_t
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|num_crtcs
name|uint16_t
name|num_crtcs
decl_stmt|;
comment|/**<  */
DECL|member|num_outputs
name|uint16_t
name|num_outputs
decl_stmt|;
comment|/**<  */
DECL|member|num_modes
name|uint16_t
name|num_modes
decl_stmt|;
comment|/**<  */
DECL|member|names_len
name|uint16_t
name|names_len
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
DECL|typedef|xcb_randr_get_screen_resources_reply_t
name|xcb_randr_get_screen_resources_reply_t
typedef|;
DECL|enum|xcb_randr_connection_t
typedef|typedef
enum|enum
name|xcb_randr_connection_t
block|{
DECL|enumerator|XCB_RANDR_CONNECTION_CONNECTED
name|XCB_RANDR_CONNECTION_CONNECTED
block|,
DECL|enumerator|XCB_RANDR_CONNECTION_DISCONNECTED
name|XCB_RANDR_CONNECTION_DISCONNECTED
block|,
DECL|enumerator|XCB_RANDR_CONNECTION_UNKNOWN
name|XCB_RANDR_CONNECTION_UNKNOWN
block|}
DECL|typedef|xcb_randr_connection_t
name|xcb_randr_connection_t
typedef|;
comment|/**  * @brief xcb_randr_get_output_info_cookie_t  **/
DECL|struct|xcb_randr_get_output_info_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_info_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_output_info_cookie_t
name|xcb_randr_get_output_info_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_output_info. */
DECL|macro|XCB_RANDR_GET_OUTPUT_INFO
define|#
directive|define
name|XCB_RANDR_GET_OUTPUT_INFO
value|9
comment|/**  * @brief xcb_randr_get_output_info_request_t  **/
DECL|struct|xcb_randr_get_output_info_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_info_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_output_info_request_t
name|xcb_randr_get_output_info_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_output_info_reply_t  **/
DECL|struct|xcb_randr_get_output_info_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_info_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|mm_width
name|uint32_t
name|mm_width
decl_stmt|;
comment|/**<  */
DECL|member|mm_height
name|uint32_t
name|mm_height
decl_stmt|;
comment|/**<  */
DECL|member|connection
name|uint8_t
name|connection
decl_stmt|;
comment|/**<  */
DECL|member|subpixel_order
name|uint8_t
name|subpixel_order
decl_stmt|;
comment|/**<  */
DECL|member|num_crtcs
name|uint16_t
name|num_crtcs
decl_stmt|;
comment|/**<  */
DECL|member|num_modes
name|uint16_t
name|num_modes
decl_stmt|;
comment|/**<  */
DECL|member|num_preferred
name|uint16_t
name|num_preferred
decl_stmt|;
comment|/**<  */
DECL|member|num_clones
name|uint16_t
name|num_clones
decl_stmt|;
comment|/**<  */
DECL|member|name_len
name|uint16_t
name|name_len
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_output_info_reply_t
name|xcb_randr_get_output_info_reply_t
typedef|;
comment|/**  * @brief xcb_randr_list_output_properties_cookie_t  **/
DECL|struct|xcb_randr_list_output_properties_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_list_output_properties_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_list_output_properties_cookie_t
name|xcb_randr_list_output_properties_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_list_output_properties. */
DECL|macro|XCB_RANDR_LIST_OUTPUT_PROPERTIES
define|#
directive|define
name|XCB_RANDR_LIST_OUTPUT_PROPERTIES
value|10
comment|/**  * @brief xcb_randr_list_output_properties_request_t  **/
DECL|struct|xcb_randr_list_output_properties_request_t
typedef|typedef
struct|struct
name|xcb_randr_list_output_properties_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_list_output_properties_request_t
name|xcb_randr_list_output_properties_request_t
typedef|;
comment|/**  * @brief xcb_randr_list_output_properties_reply_t  **/
DECL|struct|xcb_randr_list_output_properties_reply_t
typedef|typedef
struct|struct
name|xcb_randr_list_output_properties_reply_t
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
DECL|member|num_atoms
name|uint16_t
name|num_atoms
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|22
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_list_output_properties_reply_t
name|xcb_randr_list_output_properties_reply_t
typedef|;
comment|/**  * @brief xcb_randr_query_output_property_cookie_t  **/
DECL|struct|xcb_randr_query_output_property_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_query_output_property_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_query_output_property_cookie_t
name|xcb_randr_query_output_property_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_query_output_property. */
DECL|macro|XCB_RANDR_QUERY_OUTPUT_PROPERTY
define|#
directive|define
name|XCB_RANDR_QUERY_OUTPUT_PROPERTY
value|11
comment|/**  * @brief xcb_randr_query_output_property_request_t  **/
DECL|struct|xcb_randr_query_output_property_request_t
typedef|typedef
struct|struct
name|xcb_randr_query_output_property_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|property
name|xcb_atom_t
name|property
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_query_output_property_request_t
name|xcb_randr_query_output_property_request_t
typedef|;
comment|/**  * @brief xcb_randr_query_output_property_reply_t  **/
DECL|struct|xcb_randr_query_output_property_reply_t
typedef|typedef
struct|struct
name|xcb_randr_query_output_property_reply_t
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
DECL|member|pending
name|uint8_t
name|pending
decl_stmt|;
comment|/**<  */
DECL|member|range
name|uint8_t
name|range
decl_stmt|;
comment|/**<  */
DECL|member|immutable
name|uint8_t
name|immutable
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|21
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_query_output_property_reply_t
name|xcb_randr_query_output_property_reply_t
typedef|;
comment|/** Opcode for xcb_randr_configure_output_property. */
DECL|macro|XCB_RANDR_CONFIGURE_OUTPUT_PROPERTY
define|#
directive|define
name|XCB_RANDR_CONFIGURE_OUTPUT_PROPERTY
value|12
comment|/**  * @brief xcb_randr_configure_output_property_request_t  **/
DECL|struct|xcb_randr_configure_output_property_request_t
typedef|typedef
struct|struct
name|xcb_randr_configure_output_property_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|property
name|xcb_atom_t
name|property
decl_stmt|;
comment|/**<  */
DECL|member|pending
name|uint8_t
name|pending
decl_stmt|;
comment|/**<  */
DECL|member|range
name|uint8_t
name|range
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
DECL|typedef|xcb_randr_configure_output_property_request_t
name|xcb_randr_configure_output_property_request_t
typedef|;
comment|/** Opcode for xcb_randr_change_output_property. */
DECL|macro|XCB_RANDR_CHANGE_OUTPUT_PROPERTY
define|#
directive|define
name|XCB_RANDR_CHANGE_OUTPUT_PROPERTY
value|13
comment|/**  * @brief xcb_randr_change_output_property_request_t  **/
DECL|struct|xcb_randr_change_output_property_request_t
typedef|typedef
struct|struct
name|xcb_randr_change_output_property_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|property
name|xcb_atom_t
name|property
decl_stmt|;
comment|/**<  */
DECL|member|type
name|xcb_atom_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|format
name|uint8_t
name|format
decl_stmt|;
comment|/**<  */
DECL|member|mode
name|uint8_t
name|mode
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
DECL|member|num_units
name|uint32_t
name|num_units
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_change_output_property_request_t
name|xcb_randr_change_output_property_request_t
typedef|;
comment|/** Opcode for xcb_randr_delete_output_property. */
DECL|macro|XCB_RANDR_DELETE_OUTPUT_PROPERTY
define|#
directive|define
name|XCB_RANDR_DELETE_OUTPUT_PROPERTY
value|14
comment|/**  * @brief xcb_randr_delete_output_property_request_t  **/
DECL|struct|xcb_randr_delete_output_property_request_t
typedef|typedef
struct|struct
name|xcb_randr_delete_output_property_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|property
name|xcb_atom_t
name|property
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_delete_output_property_request_t
name|xcb_randr_delete_output_property_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_output_property_cookie_t  **/
DECL|struct|xcb_randr_get_output_property_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_property_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_output_property_cookie_t
name|xcb_randr_get_output_property_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_output_property. */
DECL|macro|XCB_RANDR_GET_OUTPUT_PROPERTY
define|#
directive|define
name|XCB_RANDR_GET_OUTPUT_PROPERTY
value|15
comment|/**  * @brief xcb_randr_get_output_property_request_t  **/
DECL|struct|xcb_randr_get_output_property_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_property_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|property
name|xcb_atom_t
name|property
decl_stmt|;
comment|/**<  */
DECL|member|type
name|xcb_atom_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|long_offset
name|uint32_t
name|long_offset
decl_stmt|;
comment|/**<  */
DECL|member|long_length
name|uint32_t
name|long_length
decl_stmt|;
comment|/**<  */
DECL|member|_delete
name|uint8_t
name|_delete
decl_stmt|;
comment|/**<  */
DECL|member|pending
name|uint8_t
name|pending
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
DECL|typedef|xcb_randr_get_output_property_request_t
name|xcb_randr_get_output_property_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_output_property_reply_t  **/
DECL|struct|xcb_randr_get_output_property_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_property_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|format
name|uint8_t
name|format
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
DECL|member|type
name|xcb_atom_t
name|type
decl_stmt|;
comment|/**<  */
DECL|member|bytes_after
name|uint32_t
name|bytes_after
decl_stmt|;
comment|/**<  */
DECL|member|num_items
name|uint32_t
name|num_items
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
DECL|typedef|xcb_randr_get_output_property_reply_t
name|xcb_randr_get_output_property_reply_t
typedef|;
comment|/**  * @brief xcb_randr_create_mode_cookie_t  **/
DECL|struct|xcb_randr_create_mode_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_create_mode_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_create_mode_cookie_t
name|xcb_randr_create_mode_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_create_mode. */
DECL|macro|XCB_RANDR_CREATE_MODE
define|#
directive|define
name|XCB_RANDR_CREATE_MODE
value|16
comment|/**  * @brief xcb_randr_create_mode_request_t  **/
DECL|struct|xcb_randr_create_mode_request_t
typedef|typedef
struct|struct
name|xcb_randr_create_mode_request_t
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
DECL|member|mode_info
name|xcb_randr_mode_info_t
name|mode_info
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_create_mode_request_t
name|xcb_randr_create_mode_request_t
typedef|;
comment|/**  * @brief xcb_randr_create_mode_reply_t  **/
DECL|struct|xcb_randr_create_mode_reply_t
typedef|typedef
struct|struct
name|xcb_randr_create_mode_reply_t
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
DECL|member|mode
name|xcb_randr_mode_t
name|mode
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
DECL|typedef|xcb_randr_create_mode_reply_t
name|xcb_randr_create_mode_reply_t
typedef|;
comment|/** Opcode for xcb_randr_destroy_mode. */
DECL|macro|XCB_RANDR_DESTROY_MODE
define|#
directive|define
name|XCB_RANDR_DESTROY_MODE
value|17
comment|/**  * @brief xcb_randr_destroy_mode_request_t  **/
DECL|struct|xcb_randr_destroy_mode_request_t
typedef|typedef
struct|struct
name|xcb_randr_destroy_mode_request_t
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
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_destroy_mode_request_t
name|xcb_randr_destroy_mode_request_t
typedef|;
comment|/** Opcode for xcb_randr_add_output_mode. */
DECL|macro|XCB_RANDR_ADD_OUTPUT_MODE
define|#
directive|define
name|XCB_RANDR_ADD_OUTPUT_MODE
value|18
comment|/**  * @brief xcb_randr_add_output_mode_request_t  **/
DECL|struct|xcb_randr_add_output_mode_request_t
typedef|typedef
struct|struct
name|xcb_randr_add_output_mode_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|mode
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_add_output_mode_request_t
name|xcb_randr_add_output_mode_request_t
typedef|;
comment|/** Opcode for xcb_randr_delete_output_mode. */
DECL|macro|XCB_RANDR_DELETE_OUTPUT_MODE
define|#
directive|define
name|XCB_RANDR_DELETE_OUTPUT_MODE
value|19
comment|/**  * @brief xcb_randr_delete_output_mode_request_t  **/
DECL|struct|xcb_randr_delete_output_mode_request_t
typedef|typedef
struct|struct
name|xcb_randr_delete_output_mode_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|mode
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_delete_output_mode_request_t
name|xcb_randr_delete_output_mode_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_info_cookie_t  **/
DECL|struct|xcb_randr_get_crtc_info_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_info_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_info_cookie_t
name|xcb_randr_get_crtc_info_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_crtc_info. */
DECL|macro|XCB_RANDR_GET_CRTC_INFO
define|#
directive|define
name|XCB_RANDR_GET_CRTC_INFO
value|20
comment|/**  * @brief xcb_randr_get_crtc_info_request_t  **/
DECL|struct|xcb_randr_get_crtc_info_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_info_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_info_request_t
name|xcb_randr_get_crtc_info_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_info_reply_t  **/
DECL|struct|xcb_randr_get_crtc_info_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_info_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
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
DECL|member|mode
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint16_t
name|rotation
decl_stmt|;
comment|/**<  */
DECL|member|rotations
name|uint16_t
name|rotations
decl_stmt|;
comment|/**<  */
DECL|member|num_outputs
name|uint16_t
name|num_outputs
decl_stmt|;
comment|/**<  */
DECL|member|num_possible_outputs
name|uint16_t
name|num_possible_outputs
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_info_reply_t
name|xcb_randr_get_crtc_info_reply_t
typedef|;
comment|/**  * @brief xcb_randr_set_crtc_config_cookie_t  **/
DECL|struct|xcb_randr_set_crtc_config_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_set_crtc_config_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_crtc_config_cookie_t
name|xcb_randr_set_crtc_config_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_set_crtc_config. */
DECL|macro|XCB_RANDR_SET_CRTC_CONFIG
define|#
directive|define
name|XCB_RANDR_SET_CRTC_CONFIG
value|21
comment|/**  * @brief xcb_randr_set_crtc_config_request_t  **/
DECL|struct|xcb_randr_set_crtc_config_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_crtc_config_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
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
DECL|member|mode
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint16_t
name|rotation
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
DECL|typedef|xcb_randr_set_crtc_config_request_t
name|xcb_randr_set_crtc_config_request_t
typedef|;
comment|/**  * @brief xcb_randr_set_crtc_config_reply_t  **/
DECL|struct|xcb_randr_set_crtc_config_reply_t
typedef|typedef
struct|struct
name|xcb_randr_set_crtc_config_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
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
DECL|typedef|xcb_randr_set_crtc_config_reply_t
name|xcb_randr_set_crtc_config_reply_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_gamma_size_cookie_t  **/
DECL|struct|xcb_randr_get_crtc_gamma_size_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_gamma_size_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_gamma_size_cookie_t
name|xcb_randr_get_crtc_gamma_size_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_crtc_gamma_size. */
DECL|macro|XCB_RANDR_GET_CRTC_GAMMA_SIZE
define|#
directive|define
name|XCB_RANDR_GET_CRTC_GAMMA_SIZE
value|22
comment|/**  * @brief xcb_randr_get_crtc_gamma_size_request_t  **/
DECL|struct|xcb_randr_get_crtc_gamma_size_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_gamma_size_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_gamma_size_request_t
name|xcb_randr_get_crtc_gamma_size_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_gamma_size_reply_t  **/
DECL|struct|xcb_randr_get_crtc_gamma_size_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_gamma_size_reply_t
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
DECL|member|size
name|uint16_t
name|size
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|22
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_gamma_size_reply_t
name|xcb_randr_get_crtc_gamma_size_reply_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_gamma_cookie_t  **/
DECL|struct|xcb_randr_get_crtc_gamma_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_gamma_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_gamma_cookie_t
name|xcb_randr_get_crtc_gamma_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_crtc_gamma. */
DECL|macro|XCB_RANDR_GET_CRTC_GAMMA
define|#
directive|define
name|XCB_RANDR_GET_CRTC_GAMMA
value|23
comment|/**  * @brief xcb_randr_get_crtc_gamma_request_t  **/
DECL|struct|xcb_randr_get_crtc_gamma_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_gamma_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_gamma_request_t
name|xcb_randr_get_crtc_gamma_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_gamma_reply_t  **/
DECL|struct|xcb_randr_get_crtc_gamma_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_gamma_reply_t
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
DECL|member|size
name|uint16_t
name|size
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|22
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_gamma_reply_t
name|xcb_randr_get_crtc_gamma_reply_t
typedef|;
comment|/** Opcode for xcb_randr_set_crtc_gamma. */
DECL|macro|XCB_RANDR_SET_CRTC_GAMMA
define|#
directive|define
name|XCB_RANDR_SET_CRTC_GAMMA
value|24
comment|/**  * @brief xcb_randr_set_crtc_gamma_request_t  **/
DECL|struct|xcb_randr_set_crtc_gamma_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_crtc_gamma_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|size
name|uint16_t
name|size
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
DECL|typedef|xcb_randr_set_crtc_gamma_request_t
name|xcb_randr_set_crtc_gamma_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_resources_current_cookie_t  **/
DECL|struct|xcb_randr_get_screen_resources_current_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_resources_current_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_screen_resources_current_cookie_t
name|xcb_randr_get_screen_resources_current_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_screen_resources_current. */
DECL|macro|XCB_RANDR_GET_SCREEN_RESOURCES_CURRENT
define|#
directive|define
name|XCB_RANDR_GET_SCREEN_RESOURCES_CURRENT
value|25
comment|/**  * @brief xcb_randr_get_screen_resources_current_request_t  **/
DECL|struct|xcb_randr_get_screen_resources_current_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_resources_current_request_t
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
DECL|typedef|xcb_randr_get_screen_resources_current_request_t
name|xcb_randr_get_screen_resources_current_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_screen_resources_current_reply_t  **/
DECL|struct|xcb_randr_get_screen_resources_current_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_screen_resources_current_reply_t
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|num_crtcs
name|uint16_t
name|num_crtcs
decl_stmt|;
comment|/**<  */
DECL|member|num_outputs
name|uint16_t
name|num_outputs
decl_stmt|;
comment|/**<  */
DECL|member|num_modes
name|uint16_t
name|num_modes
decl_stmt|;
comment|/**<  */
DECL|member|names_len
name|uint16_t
name|names_len
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
DECL|typedef|xcb_randr_get_screen_resources_current_reply_t
name|xcb_randr_get_screen_resources_current_reply_t
typedef|;
comment|/** Opcode for xcb_randr_set_crtc_transform. */
DECL|macro|XCB_RANDR_SET_CRTC_TRANSFORM
define|#
directive|define
name|XCB_RANDR_SET_CRTC_TRANSFORM
value|26
comment|/**  * @brief xcb_randr_set_crtc_transform_request_t  **/
DECL|struct|xcb_randr_set_crtc_transform_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_crtc_transform_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|transform
name|xcb_render_transform_t
name|transform
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
DECL|typedef|xcb_randr_set_crtc_transform_request_t
name|xcb_randr_set_crtc_transform_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_transform_cookie_t  **/
DECL|struct|xcb_randr_get_crtc_transform_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_transform_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_transform_cookie_t
name|xcb_randr_get_crtc_transform_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_crtc_transform. */
DECL|macro|XCB_RANDR_GET_CRTC_TRANSFORM
define|#
directive|define
name|XCB_RANDR_GET_CRTC_TRANSFORM
value|27
comment|/**  * @brief xcb_randr_get_crtc_transform_request_t  **/
DECL|struct|xcb_randr_get_crtc_transform_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_transform_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_transform_request_t
name|xcb_randr_get_crtc_transform_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_crtc_transform_reply_t  **/
DECL|struct|xcb_randr_get_crtc_transform_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_crtc_transform_reply_t
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
DECL|member|pending_transform
name|xcb_render_transform_t
name|pending_transform
decl_stmt|;
comment|/**<  */
DECL|member|has_transforms
name|uint8_t
name|has_transforms
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
index|[
literal|3
index|]
decl_stmt|;
comment|/**<  */
DECL|member|current_transform
name|xcb_render_transform_t
name|current_transform
decl_stmt|;
comment|/**<  */
DECL|member|pad2
name|uint8_t
name|pad2
index|[
literal|4
index|]
decl_stmt|;
comment|/**<  */
DECL|member|pending_len
name|uint16_t
name|pending_len
decl_stmt|;
comment|/**<  */
DECL|member|pending_nparams
name|uint16_t
name|pending_nparams
decl_stmt|;
comment|/**<  */
DECL|member|current_len
name|uint16_t
name|current_len
decl_stmt|;
comment|/**<  */
DECL|member|current_nparams
name|uint16_t
name|current_nparams
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_crtc_transform_reply_t
name|xcb_randr_get_crtc_transform_reply_t
typedef|;
comment|/**  * @brief xcb_randr_get_panning_cookie_t  **/
DECL|struct|xcb_randr_get_panning_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_panning_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_panning_cookie_t
name|xcb_randr_get_panning_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_panning. */
DECL|macro|XCB_RANDR_GET_PANNING
define|#
directive|define
name|XCB_RANDR_GET_PANNING
value|28
comment|/**  * @brief xcb_randr_get_panning_request_t  **/
DECL|struct|xcb_randr_get_panning_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_panning_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_panning_request_t
name|xcb_randr_get_panning_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_panning_reply_t  **/
DECL|struct|xcb_randr_get_panning_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_panning_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|left
name|uint16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|top
name|uint16_t
name|top
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
DECL|member|track_left
name|uint16_t
name|track_left
decl_stmt|;
comment|/**<  */
DECL|member|track_top
name|uint16_t
name|track_top
decl_stmt|;
comment|/**<  */
DECL|member|track_width
name|uint16_t
name|track_width
decl_stmt|;
comment|/**<  */
DECL|member|track_height
name|uint16_t
name|track_height
decl_stmt|;
comment|/**<  */
DECL|member|border_left
name|int16_t
name|border_left
decl_stmt|;
comment|/**<  */
DECL|member|border_top
name|int16_t
name|border_top
decl_stmt|;
comment|/**<  */
DECL|member|border_right
name|int16_t
name|border_right
decl_stmt|;
comment|/**<  */
DECL|member|border_bottom
name|int16_t
name|border_bottom
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_panning_reply_t
name|xcb_randr_get_panning_reply_t
typedef|;
comment|/**  * @brief xcb_randr_set_panning_cookie_t  **/
DECL|struct|xcb_randr_set_panning_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_set_panning_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_panning_cookie_t
name|xcb_randr_set_panning_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_set_panning. */
DECL|macro|XCB_RANDR_SET_PANNING
define|#
directive|define
name|XCB_RANDR_SET_PANNING
value|29
comment|/**  * @brief xcb_randr_set_panning_request_t  **/
DECL|struct|xcb_randr_set_panning_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_panning_request_t
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
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|left
name|uint16_t
name|left
decl_stmt|;
comment|/**<  */
DECL|member|top
name|uint16_t
name|top
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
DECL|member|track_left
name|uint16_t
name|track_left
decl_stmt|;
comment|/**<  */
DECL|member|track_top
name|uint16_t
name|track_top
decl_stmt|;
comment|/**<  */
DECL|member|track_width
name|uint16_t
name|track_width
decl_stmt|;
comment|/**<  */
DECL|member|track_height
name|uint16_t
name|track_height
decl_stmt|;
comment|/**<  */
DECL|member|border_left
name|int16_t
name|border_left
decl_stmt|;
comment|/**<  */
DECL|member|border_top
name|int16_t
name|border_top
decl_stmt|;
comment|/**<  */
DECL|member|border_right
name|int16_t
name|border_right
decl_stmt|;
comment|/**<  */
DECL|member|border_bottom
name|int16_t
name|border_bottom
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_panning_request_t
name|xcb_randr_set_panning_request_t
typedef|;
comment|/**  * @brief xcb_randr_set_panning_reply_t  **/
DECL|struct|xcb_randr_set_panning_reply_t
typedef|typedef
struct|struct
name|xcb_randr_set_panning_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_panning_reply_t
name|xcb_randr_set_panning_reply_t
typedef|;
comment|/** Opcode for xcb_randr_set_output_primary. */
DECL|macro|XCB_RANDR_SET_OUTPUT_PRIMARY
define|#
directive|define
name|XCB_RANDR_SET_OUTPUT_PRIMARY
value|30
comment|/**  * @brief xcb_randr_set_output_primary_request_t  **/
DECL|struct|xcb_randr_set_output_primary_request_t
typedef|typedef
struct|struct
name|xcb_randr_set_output_primary_request_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_set_output_primary_request_t
name|xcb_randr_set_output_primary_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_output_primary_cookie_t  **/
DECL|struct|xcb_randr_get_output_primary_cookie_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_primary_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_output_primary_cookie_t
name|xcb_randr_get_output_primary_cookie_t
typedef|;
comment|/** Opcode for xcb_randr_get_output_primary. */
DECL|macro|XCB_RANDR_GET_OUTPUT_PRIMARY
define|#
directive|define
name|XCB_RANDR_GET_OUTPUT_PRIMARY
value|31
comment|/**  * @brief xcb_randr_get_output_primary_request_t  **/
DECL|struct|xcb_randr_get_output_primary_request_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_primary_request_t
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
DECL|typedef|xcb_randr_get_output_primary_request_t
name|xcb_randr_get_output_primary_request_t
typedef|;
comment|/**  * @brief xcb_randr_get_output_primary_reply_t  **/
DECL|struct|xcb_randr_get_output_primary_reply_t
typedef|typedef
struct|struct
name|xcb_randr_get_output_primary_reply_t
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
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_get_output_primary_reply_t
name|xcb_randr_get_output_primary_reply_t
typedef|;
comment|/** Opcode for xcb_randr_screen_change_notify. */
DECL|macro|XCB_RANDR_SCREEN_CHANGE_NOTIFY
define|#
directive|define
name|XCB_RANDR_SCREEN_CHANGE_NOTIFY
value|0
comment|/**  * @brief xcb_randr_screen_change_notify_event_t  **/
DECL|struct|xcb_randr_screen_change_notify_event_t
typedef|typedef
struct|struct
name|xcb_randr_screen_change_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint8_t
name|rotation
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|root
name|xcb_window_t
name|root
decl_stmt|;
comment|/**<  */
DECL|member|request_window
name|xcb_window_t
name|request_window
decl_stmt|;
comment|/**<  */
DECL|member|sizeID
name|uint16_t
name|sizeID
decl_stmt|;
comment|/**<  */
DECL|member|subpixel_order
name|uint16_t
name|subpixel_order
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
DECL|member|mwidth
name|uint16_t
name|mwidth
decl_stmt|;
comment|/**<  */
DECL|member|mheight
name|uint16_t
name|mheight
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_screen_change_notify_event_t
name|xcb_randr_screen_change_notify_event_t
typedef|;
DECL|enum|xcb_randr_notify_t
typedef|typedef
enum|enum
name|xcb_randr_notify_t
block|{
DECL|enumerator|XCB_RANDR_NOTIFY_CRTC_CHANGE
name|XCB_RANDR_NOTIFY_CRTC_CHANGE
init|=
literal|0
block|,
DECL|enumerator|XCB_RANDR_NOTIFY_OUTPUT_CHANGE
name|XCB_RANDR_NOTIFY_OUTPUT_CHANGE
init|=
literal|1
block|,
DECL|enumerator|XCB_RANDR_NOTIFY_OUTPUT_PROPERTY
name|XCB_RANDR_NOTIFY_OUTPUT_PROPERTY
init|=
literal|2
block|}
DECL|typedef|xcb_randr_notify_t
name|xcb_randr_notify_t
typedef|;
comment|/**  * @brief xcb_randr_crtc_change_t  **/
DECL|struct|xcb_randr_crtc_change_t
typedef|typedef
struct|struct
name|xcb_randr_crtc_change_t
block|{
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|mode
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint16_t
name|rotation
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
block|}
DECL|typedef|xcb_randr_crtc_change_t
name|xcb_randr_crtc_change_t
typedef|;
comment|/**  * @brief xcb_randr_crtc_change_iterator_t  **/
DECL|struct|xcb_randr_crtc_change_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_crtc_change_iterator_t
block|{
DECL|member|data
name|xcb_randr_crtc_change_t
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
DECL|typedef|xcb_randr_crtc_change_iterator_t
name|xcb_randr_crtc_change_iterator_t
typedef|;
comment|/**  * @brief xcb_randr_output_change_t  **/
DECL|struct|xcb_randr_output_change_t
typedef|typedef
struct|struct
name|xcb_randr_output_change_t
block|{
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|config_timestamp
name|xcb_timestamp_t
name|config_timestamp
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|crtc
name|xcb_randr_crtc_t
name|crtc
decl_stmt|;
comment|/**<  */
DECL|member|mode
name|xcb_randr_mode_t
name|mode
decl_stmt|;
comment|/**<  */
DECL|member|rotation
name|uint16_t
name|rotation
decl_stmt|;
comment|/**<  */
DECL|member|connection
name|uint8_t
name|connection
decl_stmt|;
comment|/**<  */
DECL|member|subpixel_order
name|uint8_t
name|subpixel_order
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_output_change_t
name|xcb_randr_output_change_t
typedef|;
comment|/**  * @brief xcb_randr_output_change_iterator_t  **/
DECL|struct|xcb_randr_output_change_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_output_change_iterator_t
block|{
DECL|member|data
name|xcb_randr_output_change_t
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
DECL|typedef|xcb_randr_output_change_iterator_t
name|xcb_randr_output_change_iterator_t
typedef|;
comment|/**  * @brief xcb_randr_output_property_t  **/
DECL|struct|xcb_randr_output_property_t
typedef|typedef
struct|struct
name|xcb_randr_output_property_t
block|{
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|output
name|xcb_randr_output_t
name|output
decl_stmt|;
comment|/**<  */
DECL|member|atom
name|xcb_atom_t
name|atom
decl_stmt|;
comment|/**<  */
DECL|member|timestamp
name|xcb_timestamp_t
name|timestamp
decl_stmt|;
comment|/**<  */
DECL|member|status
name|uint8_t
name|status
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
DECL|typedef|xcb_randr_output_property_t
name|xcb_randr_output_property_t
typedef|;
comment|/**  * @brief xcb_randr_output_property_iterator_t  **/
DECL|struct|xcb_randr_output_property_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_output_property_iterator_t
block|{
DECL|member|data
name|xcb_randr_output_property_t
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
DECL|typedef|xcb_randr_output_property_iterator_t
name|xcb_randr_output_property_iterator_t
typedef|;
comment|/**  * @brief xcb_randr_notify_data_t  **/
DECL|union|xcb_randr_notify_data_t
typedef|typedef
union|union
name|xcb_randr_notify_data_t
block|{
DECL|member|cc
name|xcb_randr_crtc_change_t
name|cc
decl_stmt|;
comment|/**<  */
DECL|member|oc
name|xcb_randr_output_change_t
name|oc
decl_stmt|;
comment|/**<  */
DECL|member|op
name|xcb_randr_output_property_t
name|op
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_notify_data_t
name|xcb_randr_notify_data_t
typedef|;
comment|/**  * @brief xcb_randr_notify_data_iterator_t  **/
DECL|struct|xcb_randr_notify_data_iterator_t
typedef|typedef
struct|struct
name|xcb_randr_notify_data_iterator_t
block|{
DECL|member|data
name|xcb_randr_notify_data_t
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
DECL|typedef|xcb_randr_notify_data_iterator_t
name|xcb_randr_notify_data_iterator_t
typedef|;
comment|/** Opcode for xcb_randr_notify. */
DECL|macro|XCB_RANDR_NOTIFY
define|#
directive|define
name|XCB_RANDR_NOTIFY
value|1
comment|/**  * @brief xcb_randr_notify_event_t  **/
DECL|struct|xcb_randr_notify_event_t
typedef|typedef
struct|struct
name|xcb_randr_notify_event_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|subCode
name|uint8_t
name|subCode
decl_stmt|;
comment|/**<  */
DECL|member|sequence
name|uint16_t
name|sequence
decl_stmt|;
comment|/**<  */
DECL|member|u
name|xcb_randr_notify_data_t
name|u
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_randr_notify_event_t
name|xcb_randr_notify_event_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_mode_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_mode_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_mode_next  **   ** @param xcb_randr_mode_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_mode_next
parameter_list|(
name|xcb_randr_mode_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_mode_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_mode_end  **   ** @param xcb_randr_mode_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_mode_end
parameter_list|(
name|xcb_randr_mode_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_crtc_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_crtc_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_crtc_next  **   ** @param xcb_randr_crtc_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_crtc_next
parameter_list|(
name|xcb_randr_crtc_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_crtc_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_crtc_end  **   ** @param xcb_randr_crtc_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_crtc_end
parameter_list|(
name|xcb_randr_crtc_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_output_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_output_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_output_next  **   ** @param xcb_randr_output_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_output_next
parameter_list|(
name|xcb_randr_output_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_output_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_output_end  **   ** @param xcb_randr_output_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_output_end
parameter_list|(
name|xcb_randr_output_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_screen_size_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_screen_size_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_screen_size_next  **   ** @param xcb_randr_screen_size_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_screen_size_next
parameter_list|(
name|xcb_randr_screen_size_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_screen_size_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_screen_size_end  **   ** @param xcb_randr_screen_size_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_screen_size_end
parameter_list|(
name|xcb_randr_screen_size_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint16_t * xcb_randr_refresh_rates_rates  **   ** @param const xcb_randr_refresh_rates_t *R  ** @returns uint16_t *  **  *****************************************************************************/
name|uint16_t
modifier|*
name|xcb_randr_refresh_rates_rates
parameter_list|(
specifier|const
name|xcb_randr_refresh_rates_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_refresh_rates_rates_length  **   ** @param const xcb_randr_refresh_rates_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_refresh_rates_rates_length
parameter_list|(
specifier|const
name|xcb_randr_refresh_rates_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_refresh_rates_rates_end  **   ** @param const xcb_randr_refresh_rates_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_refresh_rates_rates_end
parameter_list|(
specifier|const
name|xcb_randr_refresh_rates_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_refresh_rates_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_refresh_rates_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_refresh_rates_next  **   ** @param xcb_randr_refresh_rates_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_refresh_rates_next
parameter_list|(
name|xcb_randr_refresh_rates_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_refresh_rates_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_refresh_rates_end  **   ** @param xcb_randr_refresh_rates_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_refresh_rates_end
parameter_list|(
name|xcb_randr_refresh_rates_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_query_version_cookie_t xcb_randr_query_version  **   ** @param xcb_connection_t *c  ** @param uint32_t          major_version  ** @param uint32_t          minor_version  ** @returns xcb_randr_query_version_cookie_t  **  *****************************************************************************/
name|xcb_randr_query_version_cookie_t
name|xcb_randr_query_version
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|major_version
comment|/**< */
parameter_list|,
name|uint32_t
name|minor_version
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_query_version_cookie_t xcb_randr_query_version_unchecked  **   ** @param xcb_connection_t *c  ** @param uint32_t          major_version  ** @param uint32_t          minor_version  ** @returns xcb_randr_query_version_cookie_t  **  *****************************************************************************/
name|xcb_randr_query_version_cookie_t
name|xcb_randr_query_version_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint32_t
name|major_version
comment|/**< */
parameter_list|,
name|uint32_t
name|minor_version
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_query_version_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_query_version_reply_t * xcb_randr_query_version_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_randr_query_version_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_randr_query_version_reply_t *  **  *****************************************************************************/
name|xcb_randr_query_version_reply_t
modifier|*
name|xcb_randr_query_version_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_query_version_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_set_screen_config_cookie_t xcb_randr_set_screen_config  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param xcb_timestamp_t   timestamp  ** @param xcb_timestamp_t   config_timestamp  ** @param uint16_t          sizeID  ** @param uint16_t          rotation  ** @param uint16_t          rate  ** @returns xcb_randr_set_screen_config_cookie_t  **  *****************************************************************************/
name|xcb_randr_set_screen_config_cookie_t
name|xcb_randr_set_screen_config
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
name|xcb_timestamp_t
name|timestamp
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|,
name|uint16_t
name|sizeID
comment|/**< */
parameter_list|,
name|uint16_t
name|rotation
comment|/**< */
parameter_list|,
name|uint16_t
name|rate
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_set_screen_config_cookie_t xcb_randr_set_screen_config_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param xcb_timestamp_t   timestamp  ** @param xcb_timestamp_t   config_timestamp  ** @param uint16_t          sizeID  ** @param uint16_t          rotation  ** @param uint16_t          rate  ** @returns xcb_randr_set_screen_config_cookie_t  **  *****************************************************************************/
name|xcb_randr_set_screen_config_cookie_t
name|xcb_randr_set_screen_config_unchecked
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
name|xcb_timestamp_t
name|timestamp
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|,
name|uint16_t
name|sizeID
comment|/**< */
parameter_list|,
name|uint16_t
name|rotation
comment|/**< */
parameter_list|,
name|uint16_t
name|rate
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_set_screen_config_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_set_screen_config_reply_t * xcb_randr_set_screen_config_reply  **   ** @param xcb_connection_t                      *c  ** @param xcb_randr_set_screen_config_cookie_t   cookie  ** @param xcb_generic_error_t                  **e  ** @returns xcb_randr_set_screen_config_reply_t *  **  *****************************************************************************/
name|xcb_randr_set_screen_config_reply_t
modifier|*
name|xcb_randr_set_screen_config_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_set_screen_config_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_select_input_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint16_t          enable  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_select_input_checked
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
name|uint16_t
name|enable
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_select_input  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint16_t          enable  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_select_input
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
name|uint16_t
name|enable
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_info_cookie_t xcb_randr_get_screen_info  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_info_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_info_cookie_t
name|xcb_randr_get_screen_info
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_info_cookie_t xcb_randr_get_screen_info_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_info_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_info_cookie_t
name|xcb_randr_get_screen_info_unchecked
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
comment|/*****************************************************************************  **  ** xcb_randr_screen_size_t * xcb_randr_get_screen_info_sizes  **   ** @param const xcb_randr_get_screen_info_reply_t *R  ** @returns xcb_randr_screen_size_t *  **  *****************************************************************************/
name|xcb_randr_screen_size_t
modifier|*
name|xcb_randr_get_screen_info_sizes
parameter_list|(
specifier|const
name|xcb_randr_get_screen_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_info_sizes_length  **   ** @param const xcb_randr_get_screen_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_info_sizes_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_screen_size_iterator_t xcb_randr_get_screen_info_sizes_iterator  **   ** @param const xcb_randr_get_screen_info_reply_t *R  ** @returns xcb_randr_screen_size_iterator_t  **  *****************************************************************************/
name|xcb_randr_screen_size_iterator_t
name|xcb_randr_get_screen_info_sizes_iterator
parameter_list|(
specifier|const
name|xcb_randr_get_screen_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_info_rates_length  **   ** @param const xcb_randr_get_screen_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_info_rates_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_refresh_rates_iterator_t xcb_randr_get_screen_info_rates_iterator  **   ** @param const xcb_randr_get_screen_info_reply_t *R  ** @returns xcb_randr_refresh_rates_iterator_t  **  *****************************************************************************/
name|xcb_randr_refresh_rates_iterator_t
name|xcb_randr_get_screen_info_rates_iterator
parameter_list|(
specifier|const
name|xcb_randr_get_screen_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_screen_info_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_info_reply_t * xcb_randr_get_screen_info_reply  **   ** @param xcb_connection_t                    *c  ** @param xcb_randr_get_screen_info_cookie_t   cookie  ** @param xcb_generic_error_t                **e  ** @returns xcb_randr_get_screen_info_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_screen_info_reply_t
modifier|*
name|xcb_randr_get_screen_info_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_screen_info_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_size_range_cookie_t xcb_randr_get_screen_size_range  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_size_range_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_size_range_cookie_t
name|xcb_randr_get_screen_size_range
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_size_range_cookie_t xcb_randr_get_screen_size_range_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_size_range_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_size_range_cookie_t
name|xcb_randr_get_screen_size_range_unchecked
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
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_screen_size_range_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_size_range_reply_t * xcb_randr_get_screen_size_range_reply  **   ** @param xcb_connection_t                          *c  ** @param xcb_randr_get_screen_size_range_cookie_t   cookie  ** @param xcb_generic_error_t                      **e  ** @returns xcb_randr_get_screen_size_range_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_screen_size_range_reply_t
modifier|*
name|xcb_randr_get_screen_size_range_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_screen_size_range_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_screen_size_checked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint32_t          mm_width  ** @param uint32_t          mm_height  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_screen_size_checked
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
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|,
name|uint32_t
name|mm_width
comment|/**< */
parameter_list|,
name|uint32_t
name|mm_height
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_screen_size  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint32_t          mm_width  ** @param uint32_t          mm_height  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_screen_size
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
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|,
name|uint32_t
name|mm_width
comment|/**< */
parameter_list|,
name|uint32_t
name|mm_height
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_mode_info_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_mode_info_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_mode_info_next  **   ** @param xcb_randr_mode_info_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_mode_info_next
parameter_list|(
name|xcb_randr_mode_info_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_mode_info_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_mode_info_end  **   ** @param xcb_randr_mode_info_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_mode_info_end
parameter_list|(
name|xcb_randr_mode_info_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_resources_cookie_t xcb_randr_get_screen_resources  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_resources_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_resources_cookie_t
name|xcb_randr_get_screen_resources
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_resources_cookie_t xcb_randr_get_screen_resources_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_resources_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_resources_cookie_t
name|xcb_randr_get_screen_resources_unchecked
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
comment|/*****************************************************************************  **  ** xcb_randr_crtc_t * xcb_randr_get_screen_resources_crtcs  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_randr_crtc_t *  **  *****************************************************************************/
name|xcb_randr_crtc_t
modifier|*
name|xcb_randr_get_screen_resources_crtcs
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_crtcs_length  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_crtcs_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_screen_resources_crtcs_end  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_screen_resources_crtcs_end
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_output_t * xcb_randr_get_screen_resources_outputs  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_randr_output_t *  **  *****************************************************************************/
name|xcb_randr_output_t
modifier|*
name|xcb_randr_get_screen_resources_outputs
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_outputs_length  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_outputs_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_screen_resources_outputs_end  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_screen_resources_outputs_end
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_mode_info_t * xcb_randr_get_screen_resources_modes  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_randr_mode_info_t *  **  *****************************************************************************/
name|xcb_randr_mode_info_t
modifier|*
name|xcb_randr_get_screen_resources_modes
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_modes_length  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_modes_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_mode_info_iterator_t xcb_randr_get_screen_resources_modes_iterator  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_randr_mode_info_iterator_t  **  *****************************************************************************/
name|xcb_randr_mode_info_iterator_t
name|xcb_randr_get_screen_resources_modes_iterator
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_randr_get_screen_resources_names  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_randr_get_screen_resources_names
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_names_length  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_names_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_screen_resources_names_end  **   ** @param const xcb_randr_get_screen_resources_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_screen_resources_names_end
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_screen_resources_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_resources_reply_t * xcb_randr_get_screen_resources_reply  **   ** @param xcb_connection_t                         *c  ** @param xcb_randr_get_screen_resources_cookie_t   cookie  ** @param xcb_generic_error_t                     **e  ** @returns xcb_randr_get_screen_resources_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_screen_resources_reply_t
modifier|*
name|xcb_randr_get_screen_resources_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_screen_resources_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_get_output_info_cookie_t xcb_randr_get_output_info  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_timestamp_t     config_timestamp  ** @returns xcb_randr_get_output_info_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_output_info_cookie_t
name|xcb_randr_get_output_info
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_info_cookie_t xcb_randr_get_output_info_unchecked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_timestamp_t     config_timestamp  ** @returns xcb_randr_get_output_info_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_output_info_cookie_t
name|xcb_randr_get_output_info_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_crtc_t * xcb_randr_get_output_info_crtcs  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_randr_crtc_t *  **  *****************************************************************************/
name|xcb_randr_crtc_t
modifier|*
name|xcb_randr_get_output_info_crtcs
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_output_info_crtcs_length  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_output_info_crtcs_length
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_output_info_crtcs_end  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_output_info_crtcs_end
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_mode_t * xcb_randr_get_output_info_modes  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_randr_mode_t *  **  *****************************************************************************/
name|xcb_randr_mode_t
modifier|*
name|xcb_randr_get_output_info_modes
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_output_info_modes_length  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_output_info_modes_length
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_output_info_modes_end  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_output_info_modes_end
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_output_t * xcb_randr_get_output_info_clones  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_randr_output_t *  **  *****************************************************************************/
name|xcb_randr_output_t
modifier|*
name|xcb_randr_get_output_info_clones
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_output_info_clones_length  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_output_info_clones_length
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_output_info_clones_end  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_output_info_clones_end
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_randr_get_output_info_name  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_randr_get_output_info_name
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_output_info_name_length  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_output_info_name_length
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_output_info_name_end  **   ** @param const xcb_randr_get_output_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_output_info_name_end
parameter_list|(
specifier|const
name|xcb_randr_get_output_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_output_info_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_info_reply_t * xcb_randr_get_output_info_reply  **   ** @param xcb_connection_t                    *c  ** @param xcb_randr_get_output_info_cookie_t   cookie  ** @param xcb_generic_error_t                **e  ** @returns xcb_randr_get_output_info_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_output_info_reply_t
modifier|*
name|xcb_randr_get_output_info_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_output_info_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_list_output_properties_cookie_t xcb_randr_list_output_properties  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @returns xcb_randr_list_output_properties_cookie_t  **  *****************************************************************************/
name|xcb_randr_list_output_properties_cookie_t
name|xcb_randr_list_output_properties
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_list_output_properties_cookie_t xcb_randr_list_output_properties_unchecked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @returns xcb_randr_list_output_properties_cookie_t  **  *****************************************************************************/
name|xcb_randr_list_output_properties_cookie_t
name|xcb_randr_list_output_properties_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_atom_t * xcb_randr_list_output_properties_atoms  **   ** @param const xcb_randr_list_output_properties_reply_t *R  ** @returns xcb_atom_t *  **  *****************************************************************************/
name|xcb_atom_t
modifier|*
name|xcb_randr_list_output_properties_atoms
parameter_list|(
specifier|const
name|xcb_randr_list_output_properties_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_list_output_properties_atoms_length  **   ** @param const xcb_randr_list_output_properties_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_list_output_properties_atoms_length
parameter_list|(
specifier|const
name|xcb_randr_list_output_properties_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_list_output_properties_atoms_end  **   ** @param const xcb_randr_list_output_properties_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_list_output_properties_atoms_end
parameter_list|(
specifier|const
name|xcb_randr_list_output_properties_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_list_output_properties_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_list_output_properties_reply_t * xcb_randr_list_output_properties_reply  **   ** @param xcb_connection_t                           *c  ** @param xcb_randr_list_output_properties_cookie_t   cookie  ** @param xcb_generic_error_t                       **e  ** @returns xcb_randr_list_output_properties_reply_t *  **  *****************************************************************************/
name|xcb_randr_list_output_properties_reply_t
modifier|*
name|xcb_randr_list_output_properties_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_list_output_properties_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_query_output_property_cookie_t xcb_randr_query_output_property  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @returns xcb_randr_query_output_property_cookie_t  **  *****************************************************************************/
name|xcb_randr_query_output_property_cookie_t
name|xcb_randr_query_output_property
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_query_output_property_cookie_t xcb_randr_query_output_property_unchecked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @returns xcb_randr_query_output_property_cookie_t  **  *****************************************************************************/
name|xcb_randr_query_output_property_cookie_t
name|xcb_randr_query_output_property_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int32_t * xcb_randr_query_output_property_valid_values  **   ** @param const xcb_randr_query_output_property_reply_t *R  ** @returns int32_t *  **  *****************************************************************************/
name|int32_t
modifier|*
name|xcb_randr_query_output_property_valid_values
parameter_list|(
specifier|const
name|xcb_randr_query_output_property_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_query_output_property_valid_values_length  **   ** @param const xcb_randr_query_output_property_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_query_output_property_valid_values_length
parameter_list|(
specifier|const
name|xcb_randr_query_output_property_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_query_output_property_valid_values_end  **   ** @param const xcb_randr_query_output_property_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_query_output_property_valid_values_end
parameter_list|(
specifier|const
name|xcb_randr_query_output_property_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_query_output_property_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_query_output_property_reply_t * xcb_randr_query_output_property_reply  **   ** @param xcb_connection_t                          *c  ** @param xcb_randr_query_output_property_cookie_t   cookie  ** @param xcb_generic_error_t                      **e  ** @returns xcb_randr_query_output_property_reply_t *  **  *****************************************************************************/
name|xcb_randr_query_output_property_reply_t
modifier|*
name|xcb_randr_query_output_property_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_query_output_property_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_configure_output_property_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @param uint8_t             pending  ** @param uint8_t             range  ** @param uint32_t            values_len  ** @param const int32_t      *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_configure_output_property_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|,
name|uint8_t
name|pending
comment|/**< */
parameter_list|,
name|uint8_t
name|range
comment|/**< */
parameter_list|,
name|uint32_t
name|values_len
comment|/**< */
parameter_list|,
specifier|const
name|int32_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_configure_output_property  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @param uint8_t             pending  ** @param uint8_t             range  ** @param uint32_t            values_len  ** @param const int32_t      *values  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_configure_output_property
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|,
name|uint8_t
name|pending
comment|/**< */
parameter_list|,
name|uint8_t
name|range
comment|/**< */
parameter_list|,
name|uint32_t
name|values_len
comment|/**< */
parameter_list|,
specifier|const
name|int32_t
modifier|*
name|values
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_change_output_property_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @param xcb_atom_t          type  ** @param uint8_t             format  ** @param uint8_t             mode  ** @param uint32_t            num_units  ** @param const void         *data  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_change_output_property_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|type
comment|/**< */
parameter_list|,
name|uint8_t
name|format
comment|/**< */
parameter_list|,
name|uint8_t
name|mode
comment|/**< */
parameter_list|,
name|uint32_t
name|num_units
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|data
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_change_output_property  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @param xcb_atom_t          type  ** @param uint8_t             format  ** @param uint8_t             mode  ** @param uint32_t            num_units  ** @param const void         *data  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_change_output_property
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|type
comment|/**< */
parameter_list|,
name|uint8_t
name|format
comment|/**< */
parameter_list|,
name|uint8_t
name|mode
comment|/**< */
parameter_list|,
name|uint32_t
name|num_units
comment|/**< */
parameter_list|,
specifier|const
name|void
modifier|*
name|data
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_delete_output_property_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_delete_output_property_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_delete_output_property  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_delete_output_property
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_property_cookie_t xcb_randr_get_output_property  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @param xcb_atom_t          type  ** @param uint32_t            long_offset  ** @param uint32_t            long_length  ** @param uint8_t             _delete  ** @param uint8_t             pending  ** @returns xcb_randr_get_output_property_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_output_property_cookie_t
name|xcb_randr_get_output_property
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|type
comment|/**< */
parameter_list|,
name|uint32_t
name|long_offset
comment|/**< */
parameter_list|,
name|uint32_t
name|long_length
comment|/**< */
parameter_list|,
name|uint8_t
name|_delete
comment|/**< */
parameter_list|,
name|uint8_t
name|pending
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_property_cookie_t xcb_randr_get_output_property_unchecked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_atom_t          property  ** @param xcb_atom_t          type  ** @param uint32_t            long_offset  ** @param uint32_t            long_length  ** @param uint8_t             _delete  ** @param uint8_t             pending  ** @returns xcb_randr_get_output_property_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_output_property_cookie_t
name|xcb_randr_get_output_property_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|property
comment|/**< */
parameter_list|,
name|xcb_atom_t
name|type
comment|/**< */
parameter_list|,
name|uint32_t
name|long_offset
comment|/**< */
parameter_list|,
name|uint32_t
name|long_length
comment|/**< */
parameter_list|,
name|uint8_t
name|_delete
comment|/**< */
parameter_list|,
name|uint8_t
name|pending
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_randr_get_output_property_data  **   ** @param const xcb_randr_get_output_property_reply_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_randr_get_output_property_data
parameter_list|(
specifier|const
name|xcb_randr_get_output_property_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_output_property_data_length  **   ** @param const xcb_randr_get_output_property_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_output_property_data_length
parameter_list|(
specifier|const
name|xcb_randr_get_output_property_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_output_property_data_end  **   ** @param const xcb_randr_get_output_property_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_output_property_data_end
parameter_list|(
specifier|const
name|xcb_randr_get_output_property_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_output_property_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_property_reply_t * xcb_randr_get_output_property_reply  **   ** @param xcb_connection_t                        *c  ** @param xcb_randr_get_output_property_cookie_t   cookie  ** @param xcb_generic_error_t                    **e  ** @returns xcb_randr_get_output_property_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_output_property_reply_t
modifier|*
name|xcb_randr_get_output_property_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_output_property_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_create_mode_cookie_t xcb_randr_create_mode  **   ** @param xcb_connection_t      *c  ** @param xcb_window_t           window  ** @param xcb_randr_mode_info_t  mode_info  ** @param uint32_t               name_len  ** @param const char            *name  ** @returns xcb_randr_create_mode_cookie_t  **  *****************************************************************************/
name|xcb_randr_create_mode_cookie_t
name|xcb_randr_create_mode
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
name|xcb_randr_mode_info_t
name|mode_info
comment|/**< */
parameter_list|,
name|uint32_t
name|name_len
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_create_mode_cookie_t xcb_randr_create_mode_unchecked  **   ** @param xcb_connection_t      *c  ** @param xcb_window_t           window  ** @param xcb_randr_mode_info_t  mode_info  ** @param uint32_t               name_len  ** @param const char            *name  ** @returns xcb_randr_create_mode_cookie_t  **  *****************************************************************************/
name|xcb_randr_create_mode_cookie_t
name|xcb_randr_create_mode_unchecked
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
name|xcb_randr_mode_info_t
name|mode_info
comment|/**< */
parameter_list|,
name|uint32_t
name|name_len
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|name
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_create_mode_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_create_mode_reply_t * xcb_randr_create_mode_reply  **   ** @param xcb_connection_t                *c  ** @param xcb_randr_create_mode_cookie_t   cookie  ** @param xcb_generic_error_t            **e  ** @returns xcb_randr_create_mode_reply_t *  **  *****************************************************************************/
name|xcb_randr_create_mode_reply_t
modifier|*
name|xcb_randr_create_mode_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_create_mode_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_destroy_mode_checked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_mode_t  mode  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_destroy_mode_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_destroy_mode  **   ** @param xcb_connection_t *c  ** @param xcb_randr_mode_t  mode  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_destroy_mode
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_add_output_mode_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_randr_mode_t    mode  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_add_output_mode_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_add_output_mode  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_randr_mode_t    mode  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_add_output_mode
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_delete_output_mode_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_randr_mode_t    mode  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_delete_output_mode_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_delete_output_mode  **   ** @param xcb_connection_t   *c  ** @param xcb_randr_output_t  output  ** @param xcb_randr_mode_t    mode  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_delete_output_mode
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_info_cookie_t xcb_randr_get_crtc_info  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @param xcb_timestamp_t   config_timestamp  ** @returns xcb_randr_get_crtc_info_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_info_cookie_t
name|xcb_randr_get_crtc_info
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_info_cookie_t xcb_randr_get_crtc_info_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @param xcb_timestamp_t   config_timestamp  ** @returns xcb_randr_get_crtc_info_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_info_cookie_t
name|xcb_randr_get_crtc_info_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_output_t * xcb_randr_get_crtc_info_outputs  **   ** @param const xcb_randr_get_crtc_info_reply_t *R  ** @returns xcb_randr_output_t *  **  *****************************************************************************/
name|xcb_randr_output_t
modifier|*
name|xcb_randr_get_crtc_info_outputs
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_info_outputs_length  **   ** @param const xcb_randr_get_crtc_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_info_outputs_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_info_outputs_end  **   ** @param const xcb_randr_get_crtc_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_info_outputs_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_output_t * xcb_randr_get_crtc_info_possible  **   ** @param const xcb_randr_get_crtc_info_reply_t *R  ** @returns xcb_randr_output_t *  **  *****************************************************************************/
name|xcb_randr_output_t
modifier|*
name|xcb_randr_get_crtc_info_possible
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_info_possible_length  **   ** @param const xcb_randr_get_crtc_info_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_info_possible_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_info_possible_end  **   ** @param const xcb_randr_get_crtc_info_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_info_possible_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_crtc_info_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_info_reply_t * xcb_randr_get_crtc_info_reply  **   ** @param xcb_connection_t                  *c  ** @param xcb_randr_get_crtc_info_cookie_t   cookie  ** @param xcb_generic_error_t              **e  ** @returns xcb_randr_get_crtc_info_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_crtc_info_reply_t
modifier|*
name|xcb_randr_get_crtc_info_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_crtc_info_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_set_crtc_config_cookie_t xcb_randr_set_crtc_config  **   ** @param xcb_connection_t         *c  ** @param xcb_randr_crtc_t          crtc  ** @param xcb_timestamp_t           timestamp  ** @param xcb_timestamp_t           config_timestamp  ** @param int16_t                   x  ** @param int16_t                   y  ** @param xcb_randr_mode_t          mode  ** @param uint16_t                  rotation  ** @param uint32_t                  outputs_len  ** @param const xcb_randr_output_t *outputs  ** @returns xcb_randr_set_crtc_config_cookie_t  **  *****************************************************************************/
name|xcb_randr_set_crtc_config_cookie_t
name|xcb_randr_set_crtc_config
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|timestamp
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|,
name|int16_t
name|x
comment|/**< */
parameter_list|,
name|int16_t
name|y
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|,
name|uint16_t
name|rotation
comment|/**< */
parameter_list|,
name|uint32_t
name|outputs_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_randr_output_t
modifier|*
name|outputs
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_set_crtc_config_cookie_t xcb_randr_set_crtc_config_unchecked  **   ** @param xcb_connection_t         *c  ** @param xcb_randr_crtc_t          crtc  ** @param xcb_timestamp_t           timestamp  ** @param xcb_timestamp_t           config_timestamp  ** @param int16_t                   x  ** @param int16_t                   y  ** @param xcb_randr_mode_t          mode  ** @param uint16_t                  rotation  ** @param uint32_t                  outputs_len  ** @param const xcb_randr_output_t *outputs  ** @returns xcb_randr_set_crtc_config_cookie_t  **  *****************************************************************************/
name|xcb_randr_set_crtc_config_cookie_t
name|xcb_randr_set_crtc_config_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|timestamp
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|config_timestamp
comment|/**< */
parameter_list|,
name|int16_t
name|x
comment|/**< */
parameter_list|,
name|int16_t
name|y
comment|/**< */
parameter_list|,
name|xcb_randr_mode_t
name|mode
comment|/**< */
parameter_list|,
name|uint16_t
name|rotation
comment|/**< */
parameter_list|,
name|uint32_t
name|outputs_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_randr_output_t
modifier|*
name|outputs
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_set_crtc_config_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_set_crtc_config_reply_t * xcb_randr_set_crtc_config_reply  **   ** @param xcb_connection_t                    *c  ** @param xcb_randr_set_crtc_config_cookie_t   cookie  ** @param xcb_generic_error_t                **e  ** @returns xcb_randr_set_crtc_config_reply_t *  **  *****************************************************************************/
name|xcb_randr_set_crtc_config_reply_t
modifier|*
name|xcb_randr_set_crtc_config_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_set_crtc_config_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_gamma_size_cookie_t xcb_randr_get_crtc_gamma_size  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_crtc_gamma_size_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_gamma_size_cookie_t
name|xcb_randr_get_crtc_gamma_size
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_gamma_size_cookie_t xcb_randr_get_crtc_gamma_size_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_crtc_gamma_size_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_gamma_size_cookie_t
name|xcb_randr_get_crtc_gamma_size_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_crtc_gamma_size_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_gamma_size_reply_t * xcb_randr_get_crtc_gamma_size_reply  **   ** @param xcb_connection_t                        *c  ** @param xcb_randr_get_crtc_gamma_size_cookie_t   cookie  ** @param xcb_generic_error_t                    **e  ** @returns xcb_randr_get_crtc_gamma_size_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_crtc_gamma_size_reply_t
modifier|*
name|xcb_randr_get_crtc_gamma_size_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_crtc_gamma_size_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_gamma_cookie_t xcb_randr_get_crtc_gamma  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_crtc_gamma_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_gamma_cookie_t
name|xcb_randr_get_crtc_gamma
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_gamma_cookie_t xcb_randr_get_crtc_gamma_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_crtc_gamma_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_gamma_cookie_t
name|xcb_randr_get_crtc_gamma_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint16_t * xcb_randr_get_crtc_gamma_red  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns uint16_t *  **  *****************************************************************************/
name|uint16_t
modifier|*
name|xcb_randr_get_crtc_gamma_red
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_gamma_red_length  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_gamma_red_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_gamma_red_end  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_gamma_red_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint16_t * xcb_randr_get_crtc_gamma_green  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns uint16_t *  **  *****************************************************************************/
name|uint16_t
modifier|*
name|xcb_randr_get_crtc_gamma_green
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_gamma_green_length  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_gamma_green_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_gamma_green_end  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_gamma_green_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint16_t * xcb_randr_get_crtc_gamma_blue  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns uint16_t *  **  *****************************************************************************/
name|uint16_t
modifier|*
name|xcb_randr_get_crtc_gamma_blue
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_gamma_blue_length  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_gamma_blue_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_gamma_blue_end  **   ** @param const xcb_randr_get_crtc_gamma_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_gamma_blue_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_crtc_gamma_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_gamma_reply_t * xcb_randr_get_crtc_gamma_reply  **   ** @param xcb_connection_t                   *c  ** @param xcb_randr_get_crtc_gamma_cookie_t   cookie  ** @param xcb_generic_error_t               **e  ** @returns xcb_randr_get_crtc_gamma_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_crtc_gamma_reply_t
modifier|*
name|xcb_randr_get_crtc_gamma_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_crtc_gamma_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_crtc_gamma_checked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @param uint16_t          size  ** @param const uint16_t   *red  ** @param const uint16_t   *green  ** @param const uint16_t   *blue  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_crtc_gamma_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|uint16_t
name|size
comment|/**< */
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|red
comment|/**< */
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|green
comment|/**< */
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|blue
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_crtc_gamma  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @param uint16_t          size  ** @param const uint16_t   *red  ** @param const uint16_t   *green  ** @param const uint16_t   *blue  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_crtc_gamma
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|uint16_t
name|size
comment|/**< */
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|red
comment|/**< */
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|green
comment|/**< */
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|blue
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_resources_current_cookie_t xcb_randr_get_screen_resources_current  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_resources_current_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_resources_current_cookie_t
name|xcb_randr_get_screen_resources_current
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_resources_current_cookie_t xcb_randr_get_screen_resources_current_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_screen_resources_current_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_screen_resources_current_cookie_t
name|xcb_randr_get_screen_resources_current_unchecked
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
comment|/*****************************************************************************  **  ** xcb_randr_crtc_t * xcb_randr_get_screen_resources_current_crtcs  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_randr_crtc_t *  **  *****************************************************************************/
name|xcb_randr_crtc_t
modifier|*
name|xcb_randr_get_screen_resources_current_crtcs
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_current_crtcs_length  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_current_crtcs_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_screen_resources_current_crtcs_end  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_screen_resources_current_crtcs_end
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_output_t * xcb_randr_get_screen_resources_current_outputs  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_randr_output_t *  **  *****************************************************************************/
name|xcb_randr_output_t
modifier|*
name|xcb_randr_get_screen_resources_current_outputs
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_current_outputs_length  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_current_outputs_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_screen_resources_current_outputs_end  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_screen_resources_current_outputs_end
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_mode_info_t * xcb_randr_get_screen_resources_current_modes  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_randr_mode_info_t *  **  *****************************************************************************/
name|xcb_randr_mode_info_t
modifier|*
name|xcb_randr_get_screen_resources_current_modes
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_current_modes_length  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_current_modes_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_randr_mode_info_iterator_t xcb_randr_get_screen_resources_current_modes_iterator  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_randr_mode_info_iterator_t  **  *****************************************************************************/
name|xcb_randr_mode_info_iterator_t
name|xcb_randr_get_screen_resources_current_modes_iterator
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** uint8_t * xcb_randr_get_screen_resources_current_names  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns uint8_t *  **  *****************************************************************************/
name|uint8_t
modifier|*
name|xcb_randr_get_screen_resources_current_names
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_screen_resources_current_names_length  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_screen_resources_current_names_length
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_screen_resources_current_names_end  **   ** @param const xcb_randr_get_screen_resources_current_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_screen_resources_current_names_end
parameter_list|(
specifier|const
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_screen_resources_current_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_screen_resources_current_reply_t * xcb_randr_get_screen_resources_current_reply  **   ** @param xcb_connection_t                                 *c  ** @param xcb_randr_get_screen_resources_current_cookie_t   cookie  ** @param xcb_generic_error_t                             **e  ** @returns xcb_randr_get_screen_resources_current_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_screen_resources_current_reply_t
modifier|*
name|xcb_randr_get_screen_resources_current_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_screen_resources_current_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_crtc_transform_checked  **   ** @param xcb_connection_t         *c  ** @param xcb_randr_crtc_t          crtc  ** @param xcb_render_transform_t    transform  ** @param uint16_t                  filter_len  ** @param const char               *filter_name  ** @param uint32_t                  filter_params_len  ** @param const xcb_render_fixed_t *filter_params  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_crtc_transform_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_render_transform_t
name|transform
comment|/**< */
parameter_list|,
name|uint16_t
name|filter_len
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|filter_name
comment|/**< */
parameter_list|,
name|uint32_t
name|filter_params_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|filter_params
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_crtc_transform  **   ** @param xcb_connection_t         *c  ** @param xcb_randr_crtc_t          crtc  ** @param xcb_render_transform_t    transform  ** @param uint16_t                  filter_len  ** @param const char               *filter_name  ** @param uint32_t                  filter_params_len  ** @param const xcb_render_fixed_t *filter_params  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_crtc_transform
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_render_transform_t
name|transform
comment|/**< */
parameter_list|,
name|uint16_t
name|filter_len
comment|/**< */
parameter_list|,
specifier|const
name|char
modifier|*
name|filter_name
comment|/**< */
parameter_list|,
name|uint32_t
name|filter_params_len
comment|/**< */
parameter_list|,
specifier|const
name|xcb_render_fixed_t
modifier|*
name|filter_params
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_transform_cookie_t xcb_randr_get_crtc_transform  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_crtc_transform_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_transform_cookie_t
name|xcb_randr_get_crtc_transform
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_transform_cookie_t xcb_randr_get_crtc_transform_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_crtc_transform_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_crtc_transform_cookie_t
name|xcb_randr_get_crtc_transform_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** char * xcb_randr_get_crtc_transform_pending_filter_name  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns char *  **  *****************************************************************************/
name|char
modifier|*
name|xcb_randr_get_crtc_transform_pending_filter_name
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_transform_pending_filter_name_length  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_transform_pending_filter_name_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_transform_pending_filter_name_end  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_transform_pending_filter_name_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_fixed_t * xcb_randr_get_crtc_transform_pending_params  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns xcb_render_fixed_t *  **  *****************************************************************************/
name|xcb_render_fixed_t
modifier|*
name|xcb_randr_get_crtc_transform_pending_params
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_transform_pending_params_length  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_transform_pending_params_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_transform_pending_params_end  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_transform_pending_params_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** char * xcb_randr_get_crtc_transform_current_filter_name  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns char *  **  *****************************************************************************/
name|char
modifier|*
name|xcb_randr_get_crtc_transform_current_filter_name
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_transform_current_filter_name_length  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_transform_current_filter_name_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_transform_current_filter_name_end  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_transform_current_filter_name_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_render_fixed_t * xcb_randr_get_crtc_transform_current_params  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns xcb_render_fixed_t *  **  *****************************************************************************/
name|xcb_render_fixed_t
modifier|*
name|xcb_randr_get_crtc_transform_current_params
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_randr_get_crtc_transform_current_params_length  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_randr_get_crtc_transform_current_params_length
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_get_crtc_transform_current_params_end  **   ** @param const xcb_randr_get_crtc_transform_reply_t *R  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_get_crtc_transform_current_params_end
parameter_list|(
specifier|const
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_crtc_transform_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_crtc_transform_reply_t * xcb_randr_get_crtc_transform_reply  **   ** @param xcb_connection_t                       *c  ** @param xcb_randr_get_crtc_transform_cookie_t   cookie  ** @param xcb_generic_error_t                   **e  ** @returns xcb_randr_get_crtc_transform_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_crtc_transform_reply_t
modifier|*
name|xcb_randr_get_crtc_transform_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_crtc_transform_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_get_panning_cookie_t xcb_randr_get_panning  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_panning_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_panning_cookie_t
name|xcb_randr_get_panning
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_panning_cookie_t xcb_randr_get_panning_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @returns xcb_randr_get_panning_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_panning_cookie_t
name|xcb_randr_get_panning_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_panning_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_panning_reply_t * xcb_randr_get_panning_reply  **   ** @param xcb_connection_t                *c  ** @param xcb_randr_get_panning_cookie_t   cookie  ** @param xcb_generic_error_t            **e  ** @returns xcb_randr_get_panning_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_panning_reply_t
modifier|*
name|xcb_randr_get_panning_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_panning_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_randr_set_panning_cookie_t xcb_randr_set_panning  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @param xcb_timestamp_t   timestamp  ** @param uint16_t          left  ** @param uint16_t          top  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint16_t          track_left  ** @param uint16_t          track_top  ** @param uint16_t          track_width  ** @param uint16_t          track_height  ** @param int16_t           border_left  ** @param int16_t           border_top  ** @param int16_t           border_right  ** @param int16_t           border_bottom  ** @returns xcb_randr_set_panning_cookie_t  **  *****************************************************************************/
name|xcb_randr_set_panning_cookie_t
name|xcb_randr_set_panning
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|timestamp
comment|/**< */
parameter_list|,
name|uint16_t
name|left
comment|/**< */
parameter_list|,
name|uint16_t
name|top
comment|/**< */
parameter_list|,
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|,
name|uint16_t
name|track_left
comment|/**< */
parameter_list|,
name|uint16_t
name|track_top
comment|/**< */
parameter_list|,
name|uint16_t
name|track_width
comment|/**< */
parameter_list|,
name|uint16_t
name|track_height
comment|/**< */
parameter_list|,
name|int16_t
name|border_left
comment|/**< */
parameter_list|,
name|int16_t
name|border_top
comment|/**< */
parameter_list|,
name|int16_t
name|border_right
comment|/**< */
parameter_list|,
name|int16_t
name|border_bottom
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_set_panning_cookie_t xcb_randr_set_panning_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_randr_crtc_t  crtc  ** @param xcb_timestamp_t   timestamp  ** @param uint16_t          left  ** @param uint16_t          top  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint16_t          track_left  ** @param uint16_t          track_top  ** @param uint16_t          track_width  ** @param uint16_t          track_height  ** @param int16_t           border_left  ** @param int16_t           border_top  ** @param int16_t           border_right  ** @param int16_t           border_bottom  ** @returns xcb_randr_set_panning_cookie_t  **  *****************************************************************************/
name|xcb_randr_set_panning_cookie_t
name|xcb_randr_set_panning_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_crtc_t
name|crtc
comment|/**< */
parameter_list|,
name|xcb_timestamp_t
name|timestamp
comment|/**< */
parameter_list|,
name|uint16_t
name|left
comment|/**< */
parameter_list|,
name|uint16_t
name|top
comment|/**< */
parameter_list|,
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|,
name|uint16_t
name|track_left
comment|/**< */
parameter_list|,
name|uint16_t
name|track_top
comment|/**< */
parameter_list|,
name|uint16_t
name|track_width
comment|/**< */
parameter_list|,
name|uint16_t
name|track_height
comment|/**< */
parameter_list|,
name|int16_t
name|border_left
comment|/**< */
parameter_list|,
name|int16_t
name|border_top
comment|/**< */
parameter_list|,
name|int16_t
name|border_right
comment|/**< */
parameter_list|,
name|int16_t
name|border_bottom
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_set_panning_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_set_panning_reply_t * xcb_randr_set_panning_reply  **   ** @param xcb_connection_t                *c  ** @param xcb_randr_set_panning_cookie_t   cookie  ** @param xcb_generic_error_t            **e  ** @returns xcb_randr_set_panning_reply_t *  **  *****************************************************************************/
name|xcb_randr_set_panning_reply_t
modifier|*
name|xcb_randr_set_panning_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_set_panning_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_output_primary_checked  **   ** @param xcb_connection_t   *c  ** @param xcb_window_t        window  ** @param xcb_randr_output_t  output  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_output_primary_checked
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
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_randr_set_output_primary  **   ** @param xcb_connection_t   *c  ** @param xcb_window_t        window  ** @param xcb_randr_output_t  output  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_randr_set_output_primary
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
name|xcb_randr_output_t
name|output
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_primary_cookie_t xcb_randr_get_output_primary  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_output_primary_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_output_primary_cookie_t
name|xcb_randr_get_output_primary
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_primary_cookie_t xcb_randr_get_output_primary_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_randr_get_output_primary_cookie_t  **  *****************************************************************************/
name|xcb_randr_get_output_primary_cookie_t
name|xcb_randr_get_output_primary_unchecked
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
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_randr_get_output_primary_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_randr_get_output_primary_reply_t * xcb_randr_get_output_primary_reply  **   ** @param xcb_connection_t                       *c  ** @param xcb_randr_get_output_primary_cookie_t   cookie  ** @param xcb_generic_error_t                   **e  ** @returns xcb_randr_get_output_primary_reply_t *  **  *****************************************************************************/
name|xcb_randr_get_output_primary_reply_t
modifier|*
name|xcb_randr_get_output_primary_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_randr_get_output_primary_cookie_t
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
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_crtc_change_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_crtc_change_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_crtc_change_next  **   ** @param xcb_randr_crtc_change_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_crtc_change_next
parameter_list|(
name|xcb_randr_crtc_change_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_crtc_change_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_crtc_change_end  **   ** @param xcb_randr_crtc_change_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_crtc_change_end
parameter_list|(
name|xcb_randr_crtc_change_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_output_change_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_output_change_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_output_change_next  **   ** @param xcb_randr_output_change_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_output_change_next
parameter_list|(
name|xcb_randr_output_change_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_output_change_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_output_change_end  **   ** @param xcb_randr_output_change_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_output_change_end
parameter_list|(
name|xcb_randr_output_change_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_output_property_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_output_property_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_output_property_next  **   ** @param xcb_randr_output_property_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_output_property_next
parameter_list|(
name|xcb_randr_output_property_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_output_property_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_output_property_end  **   ** @param xcb_randr_output_property_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_output_property_end
parameter_list|(
name|xcb_randr_output_property_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_randr_notify_data_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_randr_notify_data_t)  */
comment|/*****************************************************************************  **  ** void xcb_randr_notify_data_next  **   ** @param xcb_randr_notify_data_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_randr_notify_data_next
parameter_list|(
name|xcb_randr_notify_data_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_randr_notify_data_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_randr_notify_data_end  **   ** @param xcb_randr_notify_data_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_randr_notify_data_end
parameter_list|(
name|xcb_randr_notify_data_iterator_t
name|i
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
