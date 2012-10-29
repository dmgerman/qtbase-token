begin_unit
begin_comment
comment|/*  * This file generated automatically from shm.xml by c_client.py.  * Edit at your peril.  */
end_comment
begin_comment
comment|/**  * @defgroup XCB_Shm_API XCB Shm API  * @brief Shm XCB Protocol Implementation.  * @{  **/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__SHM_H
end_ifndef
begin_define
DECL|macro|__SHM_H
define|#
directive|define
name|__SHM_H
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
DECL|macro|XCB_SHM_MAJOR_VERSION
define|#
directive|define
name|XCB_SHM_MAJOR_VERSION
value|1
DECL|macro|XCB_SHM_MINOR_VERSION
define|#
directive|define
name|XCB_SHM_MINOR_VERSION
value|1
specifier|extern
name|xcb_extension_t
name|xcb_shm_id
decl_stmt|;
DECL|typedef|xcb_shm_seg_t
typedef|typedef
name|uint32_t
name|xcb_shm_seg_t
typedef|;
comment|/**  * @brief xcb_shm_seg_iterator_t  **/
DECL|struct|xcb_shm_seg_iterator_t
typedef|typedef
struct|struct
name|xcb_shm_seg_iterator_t
block|{
DECL|member|data
name|xcb_shm_seg_t
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
DECL|typedef|xcb_shm_seg_iterator_t
name|xcb_shm_seg_iterator_t
typedef|;
comment|/** Opcode for xcb_shm_completion. */
DECL|macro|XCB_SHM_COMPLETION
define|#
directive|define
name|XCB_SHM_COMPLETION
value|0
comment|/**  * @brief xcb_shm_completion_event_t  **/
DECL|struct|xcb_shm_completion_event_t
typedef|typedef
struct|struct
name|xcb_shm_completion_event_t
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
DECL|member|drawable
name|xcb_drawable_t
name|drawable
decl_stmt|;
comment|/**<  */
DECL|member|minor_event
name|uint16_t
name|minor_event
decl_stmt|;
comment|/**<  */
DECL|member|major_event
name|uint8_t
name|major_event
decl_stmt|;
comment|/**<  */
DECL|member|pad1
name|uint8_t
name|pad1
decl_stmt|;
comment|/**<  */
DECL|member|shmseg
name|xcb_shm_seg_t
name|shmseg
decl_stmt|;
comment|/**<  */
DECL|member|offset
name|uint32_t
name|offset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_completion_event_t
name|xcb_shm_completion_event_t
typedef|;
comment|/** Opcode for xcb_shm_bad_seg. */
DECL|macro|XCB_SHM_BAD_SEG
define|#
directive|define
name|XCB_SHM_BAD_SEG
value|0
DECL|typedef|xcb_shm_bad_seg_error_t
typedef|typedef
name|xcb_value_error_t
name|xcb_shm_bad_seg_error_t
typedef|;
comment|/**  * @brief xcb_shm_query_version_cookie_t  **/
DECL|struct|xcb_shm_query_version_cookie_t
typedef|typedef
struct|struct
name|xcb_shm_query_version_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_query_version_cookie_t
name|xcb_shm_query_version_cookie_t
typedef|;
comment|/** Opcode for xcb_shm_query_version. */
DECL|macro|XCB_SHM_QUERY_VERSION
define|#
directive|define
name|XCB_SHM_QUERY_VERSION
value|0
comment|/**  * @brief xcb_shm_query_version_request_t  **/
DECL|struct|xcb_shm_query_version_request_t
typedef|typedef
struct|struct
name|xcb_shm_query_version_request_t
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
DECL|typedef|xcb_shm_query_version_request_t
name|xcb_shm_query_version_request_t
typedef|;
comment|/**  * @brief xcb_shm_query_version_reply_t  **/
DECL|struct|xcb_shm_query_version_reply_t
typedef|typedef
struct|struct
name|xcb_shm_query_version_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|shared_pixmaps
name|uint8_t
name|shared_pixmaps
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
DECL|member|uid
name|uint16_t
name|uid
decl_stmt|;
comment|/**<  */
DECL|member|gid
name|uint16_t
name|gid
decl_stmt|;
comment|/**<  */
DECL|member|pixmap_format
name|uint8_t
name|pixmap_format
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
index|[
literal|15
index|]
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_query_version_reply_t
name|xcb_shm_query_version_reply_t
typedef|;
comment|/** Opcode for xcb_shm_attach. */
DECL|macro|XCB_SHM_ATTACH
define|#
directive|define
name|XCB_SHM_ATTACH
value|1
comment|/**  * @brief xcb_shm_attach_request_t  **/
DECL|struct|xcb_shm_attach_request_t
typedef|typedef
struct|struct
name|xcb_shm_attach_request_t
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
DECL|member|shmseg
name|xcb_shm_seg_t
name|shmseg
decl_stmt|;
comment|/**<  */
DECL|member|shmid
name|uint32_t
name|shmid
decl_stmt|;
comment|/**<  */
DECL|member|read_only
name|uint8_t
name|read_only
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
DECL|typedef|xcb_shm_attach_request_t
name|xcb_shm_attach_request_t
typedef|;
comment|/** Opcode for xcb_shm_detach. */
DECL|macro|XCB_SHM_DETACH
define|#
directive|define
name|XCB_SHM_DETACH
value|2
comment|/**  * @brief xcb_shm_detach_request_t  **/
DECL|struct|xcb_shm_detach_request_t
typedef|typedef
struct|struct
name|xcb_shm_detach_request_t
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
DECL|member|shmseg
name|xcb_shm_seg_t
name|shmseg
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_detach_request_t
name|xcb_shm_detach_request_t
typedef|;
comment|/** Opcode for xcb_shm_put_image. */
DECL|macro|XCB_SHM_PUT_IMAGE
define|#
directive|define
name|XCB_SHM_PUT_IMAGE
value|3
comment|/**  * @brief xcb_shm_put_image_request_t  **/
DECL|struct|xcb_shm_put_image_request_t
typedef|typedef
struct|struct
name|xcb_shm_put_image_request_t
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
DECL|member|gc
name|xcb_gcontext_t
name|gc
decl_stmt|;
comment|/**<  */
DECL|member|total_width
name|uint16_t
name|total_width
decl_stmt|;
comment|/**<  */
DECL|member|total_height
name|uint16_t
name|total_height
decl_stmt|;
comment|/**<  */
DECL|member|src_x
name|uint16_t
name|src_x
decl_stmt|;
comment|/**<  */
DECL|member|src_y
name|uint16_t
name|src_y
decl_stmt|;
comment|/**<  */
DECL|member|src_width
name|uint16_t
name|src_width
decl_stmt|;
comment|/**<  */
DECL|member|src_height
name|uint16_t
name|src_height
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
DECL|member|depth
name|uint8_t
name|depth
decl_stmt|;
comment|/**<  */
DECL|member|format
name|uint8_t
name|format
decl_stmt|;
comment|/**<  */
DECL|member|send_event
name|uint8_t
name|send_event
decl_stmt|;
comment|/**<  */
DECL|member|pad0
name|uint8_t
name|pad0
decl_stmt|;
comment|/**<  */
DECL|member|shmseg
name|xcb_shm_seg_t
name|shmseg
decl_stmt|;
comment|/**<  */
DECL|member|offset
name|uint32_t
name|offset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_put_image_request_t
name|xcb_shm_put_image_request_t
typedef|;
comment|/**  * @brief xcb_shm_get_image_cookie_t  **/
DECL|struct|xcb_shm_get_image_cookie_t
typedef|typedef
struct|struct
name|xcb_shm_get_image_cookie_t
block|{
DECL|member|sequence
name|unsigned
name|int
name|sequence
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_get_image_cookie_t
name|xcb_shm_get_image_cookie_t
typedef|;
comment|/** Opcode for xcb_shm_get_image. */
DECL|macro|XCB_SHM_GET_IMAGE
define|#
directive|define
name|XCB_SHM_GET_IMAGE
value|4
comment|/**  * @brief xcb_shm_get_image_request_t  **/
DECL|struct|xcb_shm_get_image_request_t
typedef|typedef
struct|struct
name|xcb_shm_get_image_request_t
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
DECL|member|plane_mask
name|uint32_t
name|plane_mask
decl_stmt|;
comment|/**<  */
DECL|member|format
name|uint8_t
name|format
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
DECL|member|shmseg
name|xcb_shm_seg_t
name|shmseg
decl_stmt|;
comment|/**<  */
DECL|member|offset
name|uint32_t
name|offset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_get_image_request_t
name|xcb_shm_get_image_request_t
typedef|;
comment|/**  * @brief xcb_shm_get_image_reply_t  **/
DECL|struct|xcb_shm_get_image_reply_t
typedef|typedef
struct|struct
name|xcb_shm_get_image_reply_t
block|{
DECL|member|response_type
name|uint8_t
name|response_type
decl_stmt|;
comment|/**<  */
DECL|member|depth
name|uint8_t
name|depth
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
DECL|member|visual
name|xcb_visualid_t
name|visual
decl_stmt|;
comment|/**<  */
DECL|member|size
name|uint32_t
name|size
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_get_image_reply_t
name|xcb_shm_get_image_reply_t
typedef|;
comment|/** Opcode for xcb_shm_create_pixmap. */
DECL|macro|XCB_SHM_CREATE_PIXMAP
define|#
directive|define
name|XCB_SHM_CREATE_PIXMAP
value|5
comment|/**  * @brief xcb_shm_create_pixmap_request_t  **/
DECL|struct|xcb_shm_create_pixmap_request_t
typedef|typedef
struct|struct
name|xcb_shm_create_pixmap_request_t
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
name|xcb_pixmap_t
name|pid
decl_stmt|;
comment|/**<  */
DECL|member|drawable
name|xcb_drawable_t
name|drawable
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
DECL|member|depth
name|uint8_t
name|depth
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
DECL|member|shmseg
name|xcb_shm_seg_t
name|shmseg
decl_stmt|;
comment|/**<  */
DECL|member|offset
name|uint32_t
name|offset
decl_stmt|;
comment|/**<  */
block|}
DECL|typedef|xcb_shm_create_pixmap_request_t
name|xcb_shm_create_pixmap_request_t
typedef|;
comment|/**  * Get the next element of the iterator  * @param i Pointer to a xcb_shm_seg_iterator_t  *  * Get the next element in the iterator. The member rem is  * decreased by one. The member data points to the next  * element. The member index is increased by sizeof(xcb_shm_seg_t)  */
comment|/*****************************************************************************  **  ** void xcb_shm_seg_next  **   ** @param xcb_shm_seg_iterator_t *i  ** @returns void  **  *****************************************************************************/
name|void
name|xcb_shm_seg_next
parameter_list|(
name|xcb_shm_seg_iterator_t
modifier|*
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the iterator pointing to the last element  * @param i An xcb_shm_seg_iterator_t  * @return  The iterator pointing to the last element  *  * Set the current element in the iterator to the last element.  * The member rem is set to 0. The member data points to the  * last element.  */
comment|/*****************************************************************************  **  ** xcb_generic_iterator_t xcb_shm_seg_end  **   ** @param xcb_shm_seg_iterator_t i  ** @returns xcb_generic_iterator_t  **  *****************************************************************************/
name|xcb_generic_iterator_t
name|xcb_shm_seg_end
parameter_list|(
name|xcb_shm_seg_iterator_t
name|i
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_shm_query_version_cookie_t xcb_shm_query_version  **   ** @param xcb_connection_t *c  ** @returns xcb_shm_query_version_cookie_t  **  *****************************************************************************/
name|xcb_shm_query_version_cookie_t
name|xcb_shm_query_version
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_shm_query_version_cookie_t xcb_shm_query_version_unchecked  **   ** @param xcb_connection_t *c  ** @returns xcb_shm_query_version_cookie_t  **  *****************************************************************************/
name|xcb_shm_query_version_cookie_t
name|xcb_shm_query_version_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_shm_query_version_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_shm_query_version_reply_t * xcb_shm_query_version_reply  **   ** @param xcb_connection_t                *c  ** @param xcb_shm_query_version_cookie_t   cookie  ** @param xcb_generic_error_t            **e  ** @returns xcb_shm_query_version_reply_t *  **  *****************************************************************************/
name|xcb_shm_query_version_reply_t
modifier|*
name|xcb_shm_query_version_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shm_query_version_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_attach_checked  **   ** @param xcb_connection_t *c  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          shmid  ** @param uint8_t           read_only  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_attach_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|shmid
comment|/**< */
parameter_list|,
name|uint8_t
name|read_only
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_attach  **   ** @param xcb_connection_t *c  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          shmid  ** @param uint8_t           read_only  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_attach
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|shmid
comment|/**< */
parameter_list|,
name|uint8_t
name|read_only
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_detach_checked  **   ** @param xcb_connection_t *c  ** @param xcb_shm_seg_t     shmseg  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_detach_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_detach  **   ** @param xcb_connection_t *c  ** @param xcb_shm_seg_t     shmseg  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_detach
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will not cause  * a reply to be generated. Any returned error will be  * saved for handling by xcb_request_check().  */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_put_image_checked  **   ** @param xcb_connection_t *c  ** @param xcb_drawable_t    drawable  ** @param xcb_gcontext_t    gc  ** @param uint16_t          total_width  ** @param uint16_t          total_height  ** @param uint16_t          src_x  ** @param uint16_t          src_y  ** @param uint16_t          src_width  ** @param uint16_t          src_height  ** @param int16_t           dst_x  ** @param int16_t           dst_y  ** @param uint8_t           depth  ** @param uint8_t           format  ** @param uint8_t           send_event  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          offset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_put_image_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
comment|/**< */
parameter_list|,
name|xcb_gcontext_t
name|gc
comment|/**< */
parameter_list|,
name|uint16_t
name|total_width
comment|/**< */
parameter_list|,
name|uint16_t
name|total_height
comment|/**< */
parameter_list|,
name|uint16_t
name|src_x
comment|/**< */
parameter_list|,
name|uint16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint16_t
name|src_width
comment|/**< */
parameter_list|,
name|uint16_t
name|src_height
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
name|uint8_t
name|depth
comment|/**< */
parameter_list|,
name|uint8_t
name|format
comment|/**< */
parameter_list|,
name|uint8_t
name|send_event
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_put_image  **   ** @param xcb_connection_t *c  ** @param xcb_drawable_t    drawable  ** @param xcb_gcontext_t    gc  ** @param uint16_t          total_width  ** @param uint16_t          total_height  ** @param uint16_t          src_x  ** @param uint16_t          src_y  ** @param uint16_t          src_width  ** @param uint16_t          src_height  ** @param int16_t           dst_x  ** @param int16_t           dst_y  ** @param uint8_t           depth  ** @param uint8_t           format  ** @param uint8_t           send_event  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          offset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_put_image
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
comment|/**< */
parameter_list|,
name|xcb_gcontext_t
name|gc
comment|/**< */
parameter_list|,
name|uint16_t
name|total_width
comment|/**< */
parameter_list|,
name|uint16_t
name|total_height
comment|/**< */
parameter_list|,
name|uint16_t
name|src_x
comment|/**< */
parameter_list|,
name|uint16_t
name|src_y
comment|/**< */
parameter_list|,
name|uint16_t
name|src_width
comment|/**< */
parameter_list|,
name|uint16_t
name|src_height
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
name|uint8_t
name|depth
comment|/**< */
parameter_list|,
name|uint8_t
name|format
comment|/**< */
parameter_list|,
name|uint8_t
name|send_event
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_shm_get_image_cookie_t xcb_shm_get_image  **   ** @param xcb_connection_t *c  ** @param xcb_drawable_t    drawable  ** @param int16_t           x  ** @param int16_t           y  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint32_t          plane_mask  ** @param uint8_t           format  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          offset  ** @returns xcb_shm_get_image_cookie_t  **  *****************************************************************************/
name|xcb_shm_get_image_cookie_t
name|xcb_shm_get_image
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
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
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|,
name|uint32_t
name|plane_mask
comment|/**< */
parameter_list|,
name|uint8_t
name|format
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   * This form can be used only if the request will cause  * a reply to be generated. Any returned error will be  * placed in the event queue.  */
comment|/*****************************************************************************  **  ** xcb_shm_get_image_cookie_t xcb_shm_get_image_unchecked  **   ** @param xcb_connection_t *c  ** @param xcb_drawable_t    drawable  ** @param int16_t           x  ** @param int16_t           y  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint32_t          plane_mask  ** @param uint8_t           format  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          offset  ** @returns xcb_shm_get_image_cookie_t  **  *****************************************************************************/
name|xcb_shm_get_image_cookie_t
name|xcb_shm_get_image_unchecked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
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
name|uint16_t
name|width
comment|/**< */
parameter_list|,
name|uint16_t
name|height
comment|/**< */
parameter_list|,
name|uint32_t
name|plane_mask
comment|/**< */
parameter_list|,
name|uint8_t
name|format
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Return the reply  * @param c      The connection  * @param cookie The cookie  * @param e      The xcb_generic_error_t supplied  *  * Returns the reply of the request asked by  *   * The parameter @p e supplied to this function must be NULL if  * xcb_shm_get_image_unchecked(). is used.  * Otherwise, it stores the error if any.  *  * The returned value must be freed by the caller using free().  */
comment|/*****************************************************************************  **  ** xcb_shm_get_image_reply_t * xcb_shm_get_image_reply  **   ** @param xcb_connection_t            *c  ** @param xcb_shm_get_image_cookie_t   cookie  ** @param xcb_generic_error_t        **e  ** @returns xcb_shm_get_image_reply_t *  **  *****************************************************************************/
name|xcb_shm_get_image_reply_t
modifier|*
name|xcb_shm_get_image_reply
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_shm_get_image_cookie_t
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
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_create_pixmap_checked  **   ** @param xcb_connection_t *c  ** @param xcb_pixmap_t      pid  ** @param xcb_drawable_t    drawable  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint8_t           depth  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          offset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_create_pixmap_checked
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_pixmap_t
name|pid
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
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
name|uint8_t
name|depth
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|offset
comment|/**< */
parameter_list|)
function_decl|;
comment|/**  * Delivers a request to the X server  * @param c The connection  * @return A cookie  *  * Delivers a request to the X server.  *   */
comment|/*****************************************************************************  **  ** xcb_void_cookie_t xcb_shm_create_pixmap  **   ** @param xcb_connection_t *c  ** @param xcb_pixmap_t      pid  ** @param xcb_drawable_t    drawable  ** @param uint16_t          width  ** @param uint16_t          height  ** @param uint8_t           depth  ** @param xcb_shm_seg_t     shmseg  ** @param uint32_t          offset  ** @returns xcb_void_cookie_t  **  *****************************************************************************/
name|xcb_void_cookie_t
name|xcb_shm_create_pixmap
parameter_list|(
name|xcb_connection_t
modifier|*
name|c
comment|/**< */
parameter_list|,
name|xcb_pixmap_t
name|pid
comment|/**< */
parameter_list|,
name|xcb_drawable_t
name|drawable
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
name|uint8_t
name|depth
comment|/**< */
parameter_list|,
name|xcb_shm_seg_t
name|shmseg
comment|/**< */
parameter_list|,
name|uint32_t
name|offset
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
