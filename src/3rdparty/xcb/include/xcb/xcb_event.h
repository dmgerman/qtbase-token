begin_unit
begin_comment
comment|/*  * Copyright (C) 2008-2009 Julien Danjou<julien@danjou.info>  *  * Permission is hereby granted, free of charge, to any person  * obtaining a copy of this software and associated documentation  * files (the "Software"), to deal in the Software without  * restriction, including without limitation the rights to use, copy,  * modify, merge, publish, distribute, sublicense, and/or sell copies  * of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be  * included in all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY  * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  * Except as contained in this notice, the names of the authors or  * their institutions shall not be used in advertising or otherwise to  * promote the sale, use or other dealings in this Software without  * prior written authorization from the authors.  */
end_comment
begin_comment
comment|/**  * @defgroup xcb__event_t XCB Event Functions  *  * These functions ease the handling of X events received.  *  * @{  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__XCB_EVENT_H__
end_ifndef
begin_define
DECL|macro|__XCB_EVENT_H__
define|#
directive|define
name|__XCB_EVENT_H__
end_define
begin_include
include|#
directive|include
file|<xcb/xcb.h>
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
comment|/**  * @brief Bit mask to find event type regardless of event source.  *  * Each event in the X11 protocol contains an 8-bit type code.  * The most-significant bit in this code is set if the event was  * generated from a SendEvent request. This mask can be used to  * determine the type of event regardless of how the event was  * generated. See the X11R6 protocol specification for details.  */
DECL|macro|XCB_EVENT_RESPONSE_TYPE_MASK
define|#
directive|define
name|XCB_EVENT_RESPONSE_TYPE_MASK
value|(0x7f)
DECL|macro|XCB_EVENT_RESPONSE_TYPE
define|#
directive|define
name|XCB_EVENT_RESPONSE_TYPE
parameter_list|(
name|e
parameter_list|)
value|(e->response_type&  XCB_EVENT_RESPONSE_TYPE_MASK)
DECL|macro|XCB_EVENT_SENT
define|#
directive|define
name|XCB_EVENT_SENT
parameter_list|(
name|e
parameter_list|)
value|(e->response_type& ~XCB_EVENT_RESPONSE_TYPE_MASK)
comment|/**  * @brief Convert an event response type to a label.  * @param type The event type.  * @return A string with the event name, or NULL if unknown.  */
specifier|const
name|char
modifier|*
name|xcb_event_get_label
parameter_list|(
name|uint8_t
name|type
parameter_list|)
function_decl|;
comment|/**  * @brief Convert an event error type to a label.  * @param type The error type.  * @return A string with the event name, or NULL if unknown or if the event is  * not an error.  */
specifier|const
name|char
modifier|*
name|xcb_event_get_error_label
parameter_list|(
name|uint8_t
name|type
parameter_list|)
function_decl|;
comment|/**  * @brief Convert an event request type to a label.  * @param type The request type.  * @return A string with the event name, or NULL if unknown or if the event is  * not an error.  */
specifier|const
name|char
modifier|*
name|xcb_event_get_request_label
parameter_list|(
name|uint8_t
name|type
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
begin_comment
comment|/**  * @}  */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __XCB_EVENT_H__ */
end_comment
end_unit
