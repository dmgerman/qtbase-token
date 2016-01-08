begin_unit
begin_comment
comment|/*  * This file generated automatically from xinerama.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_Xinerama_API XCB Xinerama API  * @brief Xinerama XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__XINERAMA_H
end_ifndef
begin_define
DECL|macro|__XINERAMA_H
define|#
directive|define
name|__XINERAMA_H
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
DECL|macro|XCB_XINERAMA_MAJOR_VERSION
define|#
directive|define
name|XCB_XINERAMA_MAJOR_VERSION
value|1
DECL|macro|XCB_XINERAMA_MINOR_VERSION
define|#
directive|define
name|XCB_XINERAMA_MINOR_VERSION
value|1
specifier|extern
name|xcb_extension_t
name|xcb_xinerama_id
decl_stmt|;
comment|/**  * @brief xcb_xinerama_screen_info_t  **/
DECL|struct|xcb_xinerama_screen_info_t
typedef|typedef
struct|struct
name|xcb_xinerama_screen_info_t
block|{
DECL|member|x_org
name|int16_t
name|x_org
decl_stmt|;
comment|/**<  */
DECL|member|y_org
name|int16_t
name|y_org
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
DECL|typedef|xcb_xinerama_screen_info_t
name|xcb_xinerama_screen_info_t
typedef|;
comment|/**  * @brief xcb_xinerama_screen_info_iterator_t  **/
DECL|struct|xcb_xinerama_screen_info_iterator_t
typedef|typedef
struct|struct
name|xcb_xinerama_screen_info_iterator_t
block|{
DECL|member|data
name|xcb_xinerama_screen_info_t
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
DECL|typedef|xcb_xinerama_screen_info_iterator_t
name|xcb_xinerama_screen_info_iterator_t
typedef|;
comment|/**  * @brief xcb_xinerama_query_version_cookie_t  **/
DECL|struct|xcb_xinerama_query_version_cookie_t
typedef|typedef
struct|struct
name|xcb_xinerama_query_version_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_query_version_cookie_t
name|xcb_xinerama_query_version_cookie_t
typedef|;
comment|/** Opcode for xcb_xinerama_query_version. */
DECL|macro|XCB_XINERAMA_QUERY_VERSION
define|#
directive|define
name|XCB_XINERAMA_QUERY_VERSION
value|0
comment|/**  * @brief xcb_xinerama_query_version_request_t  **/
DECL|struct|xcb_xinerama_query_version_request_t
typedef|typedef
struct|struct
name|xcb_xinerama_query_version_request_t
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
DECL|member|major
name|uint8_t
name|major
decl_stmt|;
comment|/**<  */
DECL|member|minor
name|uint8_t
name|minor
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_query_version_request_t
name|xcb_xinerama_query_version_request_t
typedef|;
comment|/**  * @brief xcb_xinerama_query_version_reply_t  **/
DECL|struct|xcb_xinerama_query_version_reply_t
typedef|typedef
struct|struct
name|xcb_xinerama_query_version_reply_t
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
DECL|member|major
name|uint16_t
name|major
decl_stmt|;
comment|/**<  */
DECL|member|minor
name|uint16_t
name|minor
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_query_version_reply_t
name|xcb_xinerama_query_version_reply_t
typedef|;
comment|/**  * @brief xcb_xinerama_get_state_cookie_t  **/
DECL|struct|xcb_xinerama_get_state_cookie_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_state_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_state_cookie_t
name|xcb_xinerama_get_state_cookie_t
typedef|;
comment|/** Opcode for xcb_xinerama_get_state. */
DECL|macro|XCB_XINERAMA_GET_STATE
define|#
directive|define
name|XCB_XINERAMA_GET_STATE
value|1
comment|/**  * @brief xcb_xinerama_get_state_request_t  **/
DECL|struct|xcb_xinerama_get_state_request_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_state_request_t
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
DECL|typedef|xcb_xinerama_get_state_request_t
name|xcb_xinerama_get_state_request_t
typedef|;
comment|/**  * @brief xcb_xinerama_get_state_reply_t  **/
DECL|struct|xcb_xinerama_get_state_reply_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_state_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|state
name|uint8_t
name|state
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
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_state_reply_t
name|xcb_xinerama_get_state_reply_t
typedef|;
comment|/**  * @brief xcb_xinerama_get_screen_count_cookie_t  **/
DECL|struct|xcb_xinerama_get_screen_count_cookie_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_screen_count_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_screen_count_cookie_t
name|xcb_xinerama_get_screen_count_cookie_t
typedef|;
comment|/** Opcode for xcb_xinerama_get_screen_count. */
DECL|macro|XCB_XINERAMA_GET_SCREEN_COUNT
define|#
directive|define
name|XCB_XINERAMA_GET_SCREEN_COUNT
value|2
comment|/**  * @brief xcb_xinerama_get_screen_count_request_t  **/
DECL|struct|xcb_xinerama_get_screen_count_request_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_screen_count_request_t
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
DECL|typedef|xcb_xinerama_get_screen_count_request_t
name|xcb_xinerama_get_screen_count_request_t
typedef|;
comment|/**  * @brief xcb_xinerama_get_screen_count_reply_t  **/
DECL|struct|xcb_xinerama_get_screen_count_reply_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_screen_count_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|screen_count
name|uint8_t
name|screen_count
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
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_screen_count_reply_t
name|xcb_xinerama_get_screen_count_reply_t
typedef|;
comment|/**  * @brief xcb_xinerama_get_screen_size_cookie_t  **/
DECL|struct|xcb_xinerama_get_screen_size_cookie_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_screen_size_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_screen_size_cookie_t
name|xcb_xinerama_get_screen_size_cookie_t
typedef|;
comment|/** Opcode for xcb_xinerama_get_screen_size. */
DECL|macro|XCB_XINERAMA_GET_SCREEN_SIZE
define|#
directive|define
name|XCB_XINERAMA_GET_SCREEN_SIZE
value|3
comment|/**  * @brief xcb_xinerama_get_screen_size_request_t  **/
DECL|struct|xcb_xinerama_get_screen_size_request_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_screen_size_request_t
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
DECL|member|screen
name|uint32_t
name|screen
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_screen_size_request_t
name|xcb_xinerama_get_screen_size_request_t
typedef|;
comment|/**  * @brief xcb_xinerama_get_screen_size_reply_t  **/
DECL|struct|xcb_xinerama_get_screen_size_reply_t
typedef|typedef
struct|struct
name|xcb_xinerama_get_screen_size_reply_t
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
DECL|member|width
name|uint32_t
name|width
decl_stmt|;
comment|/**<  */
DECL|member|height
name|uint32_t
name|height
decl_stmt|;
comment|/**<  */
DECL|member|window
name|xcb_window_t
name|window
decl_stmt|;
comment|/**<  */
DECL|member|screen
name|uint32_t
name|screen
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_get_screen_size_reply_t
name|xcb_xinerama_get_screen_size_reply_t
typedef|;
comment|/**  * @brief xcb_xinerama_is_active_cookie_t  **/
DECL|struct|xcb_xinerama_is_active_cookie_t
typedef|typedef
struct|struct
name|xcb_xinerama_is_active_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_is_active_cookie_t
name|xcb_xinerama_is_active_cookie_t
typedef|;
comment|/** Opcode for xcb_xinerama_is_active. */
DECL|macro|XCB_XINERAMA_IS_ACTIVE
define|#
directive|define
name|XCB_XINERAMA_IS_ACTIVE
value|4
comment|/**  * @brief xcb_xinerama_is_active_request_t  **/
DECL|struct|xcb_xinerama_is_active_request_t
typedef|typedef
struct|struct
name|xcb_xinerama_is_active_request_t
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
DECL|typedef|xcb_xinerama_is_active_request_t
name|xcb_xinerama_is_active_request_t
typedef|;
comment|/**  * @brief xcb_xinerama_is_active_reply_t  **/
DECL|struct|xcb_xinerama_is_active_reply_t
typedef|typedef
struct|struct
name|xcb_xinerama_is_active_reply_t
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
DECL|member|state
name|uint32_t
name|state
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_is_active_reply_t
name|xcb_xinerama_is_active_reply_t
typedef|;
comment|/**  * @brief xcb_xinerama_query_screens_cookie_t  **/
DECL|struct|xcb_xinerama_query_screens_cookie_t
typedef|typedef
struct|struct
name|xcb_xinerama_query_screens_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_xinerama_query_screens_cookie_t
name|xcb_xinerama_query_screens_cookie_t
typedef|;
comment|/** Opcode for xcb_xinerama_query_screens. */
DECL|macro|XCB_XINERAMA_QUERY_SCREENS
define|#
directive|define
name|XCB_XINERAMA_QUERY_SCREENS
value|5
comment|/**  * @brief xcb_xinerama_query_screens_request_t  **/
DECL|struct|xcb_xinerama_query_screens_request_t
typedef|typedef
struct|struct
name|xcb_xinerama_query_screens_request_t
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
DECL|typedef|xcb_xinerama_query_screens_request_t
name|xcb_xinerama_query_screens_request_t
typedef|;
comment|/**  * @brief xcb_xinerama_query_screens_reply_t  **/
DECL|struct|xcb_xinerama_query_screens_reply_t
typedef|typedef
struct|struct
name|xcb_xinerama_query_screens_reply_t
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
DECL|member|number
name|uint32_t
name|number
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
DECL|typedef|xcb_xinerama_query_screens_reply_t
name|xcb_xinerama_query_screens_reply_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_xinerama_screen_info_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_xinerama_screen_info_t)  */
comment|/*****************************************************************************  **  ** void xcb_xinerama_screen_info_next  **  ** @param xcb_xinerama_screen_info_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_xinerama_screen_info_next
parameter_list|(
name|xcb_xinerama_screen_info_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_xinerama_screen_info_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_xinerama_screen_info_end  **  ** @param xcb_xinerama_screen_info_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_xinerama_screen_info_end
parameter_list|(
name|xcb_xinerama_screen_info_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  */
comment|/*****************************************************************************  **  ** xcb_xinerama_query_version_cookie_t xcb_xinerama_query_version  **  ** @param xcb_connection_t *c  ** @param uint8_t           major  ** @param uint8_t           minor  ** @returns xcb_xinerama_query_version_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_query_version_cookie_t
name|xcb_xinerama_query_version
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|major
comment|/**< */
parameter_list|,
name|uint8_t
name|minor
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xinerama_query_version_cookie_t xcb_xinerama_query_version_unchecked  **  ** @param xcb_connection_t *c  ** @param uint8_t           major  ** @param uint8_t           minor  ** @returns xcb_xinerama_query_version_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_query_version_cookie_t
name|xcb_xinerama_query_version_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|uint8_t
name|major
comment|/**< */
parameter_list|,
name|uint8_t
name|minor
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *  * The parameter @p e supplied to this function must be NULL if  * xcb_xinerama_query_version_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xinerama_query_version_reply_t * xcb_xinerama_query_version_reply  **  ** @param xcb_connection_t                     *c  ** @param xcb_xinerama_query_version_cookie_t   cookie  ** @param xcb_generic_error_t                 **e  ** @returns xcb_xinerama_query_version_reply_t *  **  *****************************************************************************/
name|xcb_xinerama_query_version_reply_t
modifier|*
name|xcb_xinerama_query_version_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xinerama_query_version_cookie_t
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_state_cookie_t xcb_xinerama_get_state  **  ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_xinerama_get_state_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_get_state_cookie_t
name|xcb_xinerama_get_state
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_state_cookie_t xcb_xinerama_get_state_unchecked  **  ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_xinerama_get_state_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_get_state_cookie_t
name|xcb_xinerama_get_state_unchecked
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
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *  * The parameter @p e supplied to this function must be NULL if  * xcb_xinerama_get_state_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_state_reply_t * xcb_xinerama_get_state_reply  **  ** @param xcb_connection_t                 *c  ** @param xcb_xinerama_get_state_cookie_t   cookie  ** @param xcb_generic_error_t             **e  ** @returns xcb_xinerama_get_state_reply_t *  **  *****************************************************************************/
name|xcb_xinerama_get_state_reply_t
modifier|*
name|xcb_xinerama_get_state_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xinerama_get_state_cookie_t
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_screen_count_cookie_t xcb_xinerama_get_screen_count  **  ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_xinerama_get_screen_count_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_get_screen_count_cookie_t
name|xcb_xinerama_get_screen_count
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_screen_count_cookie_t xcb_xinerama_get_screen_count_unchecked  **  ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @returns xcb_xinerama_get_screen_count_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_get_screen_count_cookie_t
name|xcb_xinerama_get_screen_count_unchecked
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
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *  * The parameter @p e supplied to this function must be NULL if  * xcb_xinerama_get_screen_count_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_screen_count_reply_t * xcb_xinerama_get_screen_count_reply  **  ** @param xcb_connection_t                        *c  ** @param xcb_xinerama_get_screen_count_cookie_t   cookie  ** @param xcb_generic_error_t                    **e  ** @returns xcb_xinerama_get_screen_count_reply_t *  **  *****************************************************************************/
name|xcb_xinerama_get_screen_count_reply_t
modifier|*
name|xcb_xinerama_get_screen_count_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xinerama_get_screen_count_cookie_t
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_screen_size_cookie_t xcb_xinerama_get_screen_size  **  ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint32_t          screen  ** @returns xcb_xinerama_get_screen_size_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_get_screen_size_cookie_t
name|xcb_xinerama_get_screen_size
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
name|screen
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_screen_size_cookie_t xcb_xinerama_get_screen_size_unchecked  **  ** @param xcb_connection_t *c  ** @param xcb_window_t      window  ** @param uint32_t          screen  ** @returns xcb_xinerama_get_screen_size_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_get_screen_size_cookie_t
name|xcb_xinerama_get_screen_size_unchecked
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
name|screen
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *  * The parameter @p e supplied to this function must be NULL if  * xcb_xinerama_get_screen_size_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xinerama_get_screen_size_reply_t * xcb_xinerama_get_screen_size_reply  **  ** @param xcb_connection_t                       *c  ** @param xcb_xinerama_get_screen_size_cookie_t   cookie  ** @param xcb_generic_error_t                   **e  ** @returns xcb_xinerama_get_screen_size_reply_t *  **  *****************************************************************************/
name|xcb_xinerama_get_screen_size_reply_t
modifier|*
name|xcb_xinerama_get_screen_size_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xinerama_get_screen_size_cookie_t
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  */
comment|/*****************************************************************************  **  ** xcb_xinerama_is_active_cookie_t xcb_xinerama_is_active  **  ** @param xcb_connection_t *c  ** @returns xcb_xinerama_is_active_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_is_active_cookie_t
name|xcb_xinerama_is_active
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xinerama_is_active_cookie_t xcb_xinerama_is_active_unchecked  **  ** @param xcb_connection_t *c  ** @returns xcb_xinerama_is_active_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_is_active_cookie_t
name|xcb_xinerama_is_active_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *  * The parameter @p e supplied to this function must be NULL if  * xcb_xinerama_is_active_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xinerama_is_active_reply_t * xcb_xinerama_is_active_reply  **  ** @param xcb_connection_t                 *c  ** @param xcb_xinerama_is_active_cookie_t   cookie  ** @param xcb_generic_error_t             **e  ** @returns xcb_xinerama_is_active_reply_t *  **  *****************************************************************************/
name|xcb_xinerama_is_active_reply_t
modifier|*
name|xcb_xinerama_is_active_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xinerama_is_active_cookie_t
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
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  */
comment|/*****************************************************************************  **  ** xcb_xinerama_query_screens_cookie_t xcb_xinerama_query_screens  **  ** @param xcb_connection_t *c  ** @returns xcb_xinerama_query_screens_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_query_screens_cookie_t
name|xcb_xinerama_query_screens
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *  * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_xinerama_query_screens_cookie_t xcb_xinerama_query_screens_unchecked  **  ** @param xcb_connection_t *c  ** @returns xcb_xinerama_query_screens_cookie_t  **  *****************************************************************************/
name|xcb_xinerama_query_screens_cookie_t
name|xcb_xinerama_query_screens_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xinerama_screen_info_t * xcb_xinerama_query_screens_screen_info  **  ** @param const xcb_xinerama_query_screens_reply_t *R  ** @returns xcb_xinerama_screen_info_t *  **  *****************************************************************************/
name|xcb_xinerama_screen_info_t
modifier|*
name|xcb_xinerama_query_screens_screen_info
parameter_list|(
specifier|const
name|xcb_xinerama_query_screens_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** int xcb_xinerama_query_screens_screen_info_length  **  ** @param const xcb_xinerama_query_screens_reply_t *R  ** @returns int  **  *****************************************************************************/
name|int
name|xcb_xinerama_query_screens_screen_info_length
parameter_list|(
specifier|const
name|xcb_xinerama_query_screens_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/*****************************************************************************  **  ** xcb_xinerama_screen_info_iterator_t xcb_xinerama_query_screens_screen_info_iterator  **  ** @param const xcb_xinerama_query_screens_reply_t *R  ** @returns xcb_xinerama_screen_info_iterator_t  **  *****************************************************************************/
name|xcb_xinerama_screen_info_iterator_t
name|xcb_xinerama_query_screens_screen_info_iterator
parameter_list|(
specifier|const
name|xcb_xinerama_query_screens_reply_t
modifier|*
name|R
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *  * The parameter @p e supplied to this function must be NULL if  * xcb_xinerama_query_screens_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_xinerama_query_screens_reply_t * xcb_xinerama_query_screens_reply  **  ** @param xcb_connection_t                     *c  ** @param xcb_xinerama_query_screens_cookie_t   cookie  ** @param xcb_generic_error_t                 **e  ** @returns xcb_xinerama_query_screens_reply_t *  **  *****************************************************************************/
name|xcb_xinerama_query_screens_reply_t
modifier|*
name|xcb_xinerama_query_screens_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_xinerama_query_screens_cookie_t
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
