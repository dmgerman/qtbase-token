begin_unit
begin_comment
comment|/*  * Copyright Â© 2010 Kristian HÃ¸gsberg  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that copyright  * notice and this permission notice appear in supporting documentation, and  * that the name of the copyright holders not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  The copyright holders make no representations  * about the suitability of this software for any purpose.  It is provided "as  * is" without express or implied warranty.  *  * THE COPYRIGHT HOLDERS DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,  * INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO  * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY SPECIAL, INDIRECT OR  * CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,  * DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER  * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE  * OF THIS SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WAYLAND_WINDOWMANAGER_CLIENT_PROTOCOL_H
end_ifndef
begin_define
DECL|macro|WAYLAND_WINDOWMANAGER_CLIENT_PROTOCOL_H
define|#
directive|define
name|WAYLAND_WINDOWMANAGER_CLIENT_PROTOCOL_H
end_define
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
include|#
directive|include
file|<stdint.h>
include|#
directive|include
file|<stddef.h>
include|#
directive|include
file|"wayland-util.h"
struct_decl|struct
name|wl_client
struct_decl|;
struct_decl|struct
name|wl_windowmanager
struct_decl|;
specifier|extern
specifier|const
name|struct
name|wl_interface
name|wl_windowmanager_interface
decl_stmt|;
DECL|struct|wl_windowmanager_listener
struct|struct
name|wl_windowmanager_listener
block|{
DECL|member|client_onscreen_visibility
name|void
function_decl|(
modifier|*
name|client_onscreen_visibility
function_decl|)
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|,
name|int
name|visible
parameter_list|)
function_decl|;
block|}
struct|;
specifier|static
specifier|inline
name|int
DECL|function|wl_windowmanager_add_listener
name|wl_windowmanager_add_listener
parameter_list|(
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|,
specifier|const
name|struct
name|wl_windowmanager_listener
modifier|*
name|listener
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
return|return
name|wl_proxy_add_listener
argument_list|(
operator|(
expr|struct
name|wl_proxy
operator|*
operator|)
name|wl_windowmanager
argument_list|,
operator|(
name|void
argument_list|(
operator|*
operator|*
argument_list|)
argument_list|(
name|void
argument_list|)
operator|)
name|listener
argument_list|,
name|data
argument_list|)
return|;
block|}
DECL|macro|WL_WINDOWMANAGER_MAP_CLIENT_TO_PROCESS
define|#
directive|define
name|WL_WINDOWMANAGER_MAP_CLIENT_TO_PROCESS
value|0
DECL|macro|WL_WINDOWMANAGER_AUTHENTICATE_WITH_TOKEN
define|#
directive|define
name|WL_WINDOWMANAGER_AUTHENTICATE_WITH_TOKEN
value|1
specifier|static
specifier|inline
name|struct
name|wl_windowmanager
modifier|*
DECL|function|wl_windowmanager_create
name|wl_windowmanager_create
parameter_list|(
name|struct
name|wl_display
modifier|*
name|display
parameter_list|,
name|uint32_t
name|id
parameter_list|,
name|uint32_t
name|version
parameter_list|)
block|{
name|wl_display_bind
argument_list|(
name|display
argument_list|,
name|id
argument_list|,
literal|"wl_windowmanager"
argument_list|,
name|version
argument_list|)
expr_stmt|;
return|return
operator|(
expr|struct
name|wl_windowmanager
operator|*
operator|)
name|wl_proxy_create_for_id
argument_list|(
name|display
argument_list|,
operator|&
name|wl_windowmanager_interface
argument_list|,
name|id
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|void
DECL|function|wl_windowmanager_set_user_data
name|wl_windowmanager_set_user_data
parameter_list|(
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|,
name|void
modifier|*
name|user_data
parameter_list|)
block|{
name|wl_proxy_set_user_data
argument_list|(
operator|(
expr|struct
name|wl_proxy
operator|*
operator|)
name|wl_windowmanager
argument_list|,
name|user_data
argument_list|)
expr_stmt|;
block|}
specifier|static
specifier|inline
name|void
modifier|*
DECL|function|wl_windowmanager_get_user_data
name|wl_windowmanager_get_user_data
parameter_list|(
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|)
block|{
return|return
name|wl_proxy_get_user_data
argument_list|(
operator|(
expr|struct
name|wl_proxy
operator|*
operator|)
name|wl_windowmanager
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|void
DECL|function|wl_windowmanager_destroy
name|wl_windowmanager_destroy
parameter_list|(
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|)
block|{
name|wl_proxy_destroy
argument_list|(
operator|(
expr|struct
name|wl_proxy
operator|*
operator|)
name|wl_windowmanager
argument_list|)
expr_stmt|;
block|}
specifier|static
specifier|inline
name|void
DECL|function|wl_windowmanager_map_client_to_process
name|wl_windowmanager_map_client_to_process
parameter_list|(
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|,
name|uint32_t
name|processid
parameter_list|)
block|{
name|wl_proxy_marshal
argument_list|(
operator|(
expr|struct
name|wl_proxy
operator|*
operator|)
name|wl_windowmanager
argument_list|,
name|WL_WINDOWMANAGER_MAP_CLIENT_TO_PROCESS
argument_list|,
name|processid
argument_list|)
expr_stmt|;
block|}
specifier|static
specifier|inline
name|void
DECL|function|wl_windowmanager_authenticate_with_token
name|wl_windowmanager_authenticate_with_token
parameter_list|(
name|struct
name|wl_windowmanager
modifier|*
name|wl_windowmanager
parameter_list|,
specifier|const
name|char
modifier|*
name|processid
parameter_list|)
block|{
name|wl_proxy_marshal
argument_list|(
operator|(
expr|struct
name|wl_proxy
operator|*
operator|)
name|wl_windowmanager
argument_list|,
name|WL_WINDOWMANAGER_AUTHENTICATE_WITH_TOKEN
argument_list|,
name|processid
argument_list|)
expr_stmt|;
block|}
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
end_unit
