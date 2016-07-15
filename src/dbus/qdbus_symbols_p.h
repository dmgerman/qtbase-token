begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the public API.  This header file may
end_comment
begin_comment
comment|// change from version to version without notice, or even be
end_comment
begin_comment
comment|// removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDBUS_SYMBOLS_P_H
end_ifndef
begin_define
DECL|macro|QDBUS_SYMBOLS_P_H
define|#
directive|define
name|QDBUS_SYMBOLS_P_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LINKED_LIBDBUS
end_ifdef
begin_include
include|#
directive|include
file|<dbus/dbus.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"dbus_minimal_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
operator|!
name|defined
name|QT_LINKED_LIBDBUS
name|void
argument_list|(
operator|*
name|qdbus_resolve_conditionally
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
argument_list|)
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|// doesn't print a warning
end_comment
begin_expr_stmt
name|void
argument_list|(
operator|*
name|qdbus_resolve_me
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
argument_list|)
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|// prints a warning
end_comment
begin_function_decl
name|bool
name|qdbus_loadLibDBus
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|//# define TRACE_DBUS_CALLS
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TRACE_DBUS_CALLS
end_ifdef
begin_decl_stmt
name|namespace
name|QtDBusCallTracing
block|{
struct|struct
name|TraceDBusCall
block|{
struct|struct
name|ThreadData
block|{
name|TraceDBusCall
modifier|*
name|ptr
decl_stmt|;
name|int
name|level
decl_stmt|;
name|bool
name|finishedPrinted
decl_stmt|;
block|}
struct|;
specifier|static
specifier|inline
name|ThreadData
modifier|&
name|td
parameter_list|()
block|{
specifier|static
name|thread_local
name|ThreadData
name|value
decl_stmt|;
return|return
name|value
return|;
block|}
name|ThreadData
name|savedData
decl_stmt|;
name|QDebug
name|s
decl_stmt|;
name|TraceDBusCall
argument_list|(
argument|QDebug s
argument_list|,
argument|const char *fname
argument_list|)
block|:
name|savedData
argument_list|(
name|td
argument_list|()
argument_list|)
operator|,
name|s
argument_list|(
argument|s.nospace()<< QByteArray(savedData.level *
literal|3
argument|,
literal|' '
argument|).constData()<< fname
argument_list|)
block|{
if|if
condition|(
name|savedData
operator|.
name|ptr
operator|&&
operator|!
name|savedData
operator|.
name|finishedPrinted
condition|)
block|{
name|savedData
operator|.
name|ptr
operator|->
name|s
operator|<<
literal|" ...unfinished"
expr_stmt|;
name|savedData
operator|.
name|ptr
operator|->
name|s
operator|=
name|qDebug
argument_list|()
operator|.
name|nospace
argument_list|()
operator|<<
name|QByteArray
argument_list|(
name|savedData
operator|.
name|level
operator|*
literal|3
operator|-
literal|3
argument_list|,
literal|' '
argument_list|)
operator|.
name|constData
argument_list|()
expr_stmt|;
name|savedData
operator|.
name|finishedPrinted
operator|=
name|true
expr_stmt|;
block|}
name|ThreadData
modifier|&
name|data
init|=
name|td
argument_list|()
decl_stmt|;
name|data
operator|.
name|ptr
operator|=
name|this
expr_stmt|;
name|data
operator|.
name|level
operator|++
expr_stmt|;
name|data
operator|.
name|finishedPrinted
operator|=
name|false
expr_stmt|;
block|}
decl|~
name|TraceDBusCall
argument_list|()
block|{
name|td
argument_list|()
operator|=
name|savedData
expr_stmt|;
block|}
name|void
name|operator
argument_list|()
argument_list|()
block|{
name|s
operator|<<
literal|")"
expr_stmt|;
block|}
name|template
decl|<
name|typename
modifier|...
name|Args
decl|>
name|void
name|operator
argument_list|()
argument_list|(
specifier|const
name|char
operator|*
name|arg1
argument_list|,
name|Args
operator|&&
operator|...
name|args
argument_list|)
block|{
name|s
operator|<<
literal|'"'
operator|<<
name|arg1
operator|<<
literal|'"'
expr_stmt|;
if|if
condition|(
sizeof|sizeof...
argument_list|(
name|args
argument_list|)
condition|)
name|s
operator|<<
literal|", "
expr_stmt|;
name|operator
argument_list|()
argument_list|(
name|args
operator|...
argument_list|)
expr_stmt|;
block|}
name|template
decl|<
name|typename
name|Arg1
struct|,
name|typename
modifier|...
name|Args
decl|>
name|void
name|operator
argument_list|()
argument_list|(
name|Arg1
operator|&&
name|arg1
argument_list|,
name|Args
operator|&&
operator|...
name|args
argument_list|)
block|{
name|s
operator|<<
name|arg1
expr_stmt|;
if|if
condition|(
sizeof|sizeof...
argument_list|(
name|args
argument_list|)
condition|)
name|s
operator|<<
literal|", "
expr_stmt|;
name|operator
argument_list|()
argument_list|(
name|args
operator|...
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|operator
operator|,
operator|(
name|TraceDBusCall
operator|&&
name|tc
operator|,
name|T
operator|&&
name|ret
operator|)
block|{
name|tc
operator|.
name|s
operator|<<
literal|" = "
operator|<<
name|ret
block|;
return|return
name|ret
return|;
block|}
end_expr_stmt
begin_decl_stmt
specifier|inline
specifier|const
name|char
modifier|*
name|operator
decl_stmt|,
argument_list|(
name|TraceDBusCall
operator|&&
name|tc
argument_list|,
specifier|const
name|char
operator|*
name|ret
argument_list|)
block|{
name|tc
operator|.
name|s
operator|<<
literal|" = \""
operator|<<
name|ret
operator|<<
literal|'"'
expr_stmt|;
return|return
name|ret
return|;
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|TraceReturn
block|{
typedef|typedef
name|TraceDBusCall
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|TraceReturn
operator|<
name|void
operator|>
block|{
typedef|typedef
name|void
name|Type
typedef|;
block|}
end_expr_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|DEBUGCALL
unit|}
define|#
directive|define
name|DEBUGCALL
parameter_list|(
name|name
parameter_list|,
name|argcall
parameter_list|)
value|QtDBusCallTracing::TraceDBusCall tc(qDebug(), name "("); tc argcall
end_define
begin_define
DECL|macro|DEBUGRET
define|#
directive|define
name|DEBUGRET
parameter_list|(
name|ret
parameter_list|)
value|(QtDBusCallTracing::TraceReturn<ret>::Type) tc ,
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|DEBUGCALL
define|#
directive|define
name|DEBUGCALL
parameter_list|(
name|name
parameter_list|,
name|argcall
parameter_list|)
end_define
begin_define
DECL|macro|DEBUGRET
define|#
directive|define
name|DEBUGRET
parameter_list|(
name|ret
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|DEFINEFUNC
define|#
directive|define
name|DEFINEFUNC
parameter_list|(
name|ret
parameter_list|,
name|func
parameter_list|,
name|args
parameter_list|,
name|argcall
parameter_list|,
name|funcret
parameter_list|)
define|\
value|typedef ret (* _q_PTR_##func) args;                         \     static inline ret q_##func args                             \     {                                                           \         static _q_PTR_##func ptr;                               \         DEBUGCALL(#func, argcall);                              \         if (!ptr)                                               \             ptr = (_q_PTR_##func) qdbus_resolve_me(#func);      \         funcret DEBUGRET(ret) ptr argcall;                      \     }
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|// defined QT_LINKED_LIBDBUS
end_comment
begin_function
unit|inline
name|bool
name|qdbus_loadLibDBus
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function
begin_define
define|#
directive|define
name|DEFINEFUNC
parameter_list|(
name|ret
parameter_list|,
name|func
parameter_list|,
name|args
parameter_list|,
name|argcall
parameter_list|,
name|funcret
parameter_list|)
define|\
value|static inline ret q_##func args { funcret func argcall; }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// defined QT_LINKED_LIBDBUS
end_comment
begin_comment
comment|/* dbus-bus.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_bus_add_match
argument_list|,
argument|(DBusConnection *connection,                                       const char     *rule,                                       DBusError      *error)
argument_list|,
argument|(connection, rule, error)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_bus_remove_match
argument_list|,
argument|(DBusConnection *connection,                                          const char     *rule,                                          DBusError      *error)
argument_list|,
argument|(connection, rule, error)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_bus_register
argument_list|,
argument|(DBusConnection *connection,                                            DBusError      *error)
argument_list|,
argument|(connection, error)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusConnection *
argument_list|,
argument|dbus_bus_get_private
argument_list|,
argument|(DBusBusType     type,                                                     DBusError      *error)
argument_list|,
argument|(type, error)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_bus_get_unique_name
argument_list|,
argument|(DBusConnection *connection)
argument_list|,
argument|(connection)
argument_list|,
argument|return
argument_list|)
end_macro
begin_comment
comment|/* dbus-connection.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_add_filter
argument_list|,
argument|(DBusConnection            *connection,                                                              DBusHandleMessageFunction  function,                                                              void                      *user_data,                                                              DBusFreeFunction           free_data_function)
argument_list|,
argument|(connection, function, user_data, free_data_function)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_can_send_type
argument_list|,
argument|(DBusConnection             *connection,                                                                 int                         type)
argument_list|,
argument|(connection, type)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_connection_close
argument_list|,
argument|(DBusConnection             *connection)
argument_list|,
argument|(connection)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusDispatchStatus
argument_list|,
argument|dbus_connection_dispatch
argument_list|,
argument|(DBusConnection             *connection)
argument_list|,
argument|(connection)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusDispatchStatus
argument_list|,
argument|dbus_connection_get_dispatch_status
argument_list|,
argument|(DBusConnection             *connection)
argument_list|,
argument|(connection)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_get_is_connected
argument_list|,
argument|(DBusConnection             *connection)
argument_list|,
argument|(connection)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusConnection*
argument_list|,
argument|dbus_connection_open_private
argument_list|,
argument|(const char                 *address,                                                                DBusError                  *error)
argument_list|,
argument|(address, error)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusConnection*
argument_list|,
argument|dbus_connection_ref
argument_list|,
argument|(DBusConnection             *connection)
argument_list|,
argument|(connection)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_send
argument_list|,
argument|(DBusConnection             *connection,                                                                DBusMessage                *message,                                                                dbus_uint32_t              *client_serial)
argument_list|,
argument|(connection, message, client_serial)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_send_with_reply
argument_list|,
argument|(DBusConnection             *connection,                                                                   DBusMessage                *message,                                                                   DBusPendingCall           **pending_return,                                                                   int                         timeout_milliseconds)
argument_list|,
argument|(connection, message, pending_return, timeout_milliseconds)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage *
argument_list|,
argument|dbus_connection_send_with_reply_and_block
argument_list|,
argument|(DBusConnection             *connection,                                                                             DBusMessage                *message,                                                                             int                         timeout_milliseconds,                                                                             DBusError                  *error)
argument_list|,
argument|(connection, message, timeout_milliseconds, error)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_connection_set_exit_on_disconnect
argument_list|,
argument|(DBusConnection             *connection,                                                                          dbus_bool_t                 exit_on_disconnect)
argument_list|,
argument|(connection, exit_on_disconnect)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_set_timeout_functions
argument_list|,
argument|(DBusConnection             *connection,                                                                         DBusAddTimeoutFunction      add_function,                                                                         DBusRemoveTimeoutFunction   remove_function,                                                                         DBusTimeoutToggledFunction  toggled_function,                                                                         void                       *data,                                                                         DBusFreeFunction            free_data_function)
argument_list|,
argument|(connection, add_function, remove_function, toggled_function, data, free_data_function)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_connection_set_watch_functions
argument_list|,
argument|(DBusConnection             *connection,                                                                       DBusAddWatchFunction        add_function,                                                                       DBusRemoveWatchFunction     remove_function,                                                                       DBusWatchToggledFunction    toggled_function,                                                                       void                       *data,                                                                       DBusFreeFunction            free_data_function)
argument_list|,
argument|(connection, add_function, remove_function, toggled_function, data, free_data_function)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_connection_set_wakeup_main_function
argument_list|,
argument|(DBusConnection             *connection,                                                                           DBusWakeupMainFunction      wakeup_main_function,                                                                           void                       *data,                                                                           DBusFreeFunction            free_data_function)
argument_list|,
argument|(connection, wakeup_main_function, data, free_data_function)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_connection_set_dispatch_status_function
argument_list|,
argument|(DBusConnection             *connection,                                                                               DBusDispatchStatusFunction  function,                                                                               void                       *data,                                                                               DBusFreeFunction            free_data_function)
argument_list|,
argument|(connection, function, data, free_data_function)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_connection_unref
argument_list|,
argument|(DBusConnection             *connection)
argument_list|,
argument|(connection)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_timeout_get_enabled
argument_list|,
argument|(DBusTimeout      *timeout)
argument_list|,
argument|(timeout)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|int
argument_list|,
argument|dbus_timeout_get_interval
argument_list|,
argument|(DBusTimeout      *timeout)
argument_list|,
argument|(timeout)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_timeout_handle
argument_list|,
argument|(DBusTimeout      *timeout)
argument_list|,
argument|(timeout)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_watch_get_enabled
argument_list|,
argument|(DBusWatch        *watch)
argument_list|,
argument|(watch)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|int
argument_list|,
argument|dbus_watch_get_unix_fd
argument_list|,
argument|(DBusWatch        *watch)
argument_list|,
argument|(watch)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|unsigned int
argument_list|,
argument|dbus_watch_get_flags
argument_list|,
argument|(DBusWatch        *watch)
argument_list|,
argument|(watch)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_watch_handle
argument_list|,
argument|(DBusWatch        *watch,                                               unsigned int      flags)
argument_list|,
argument|(watch, flags)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_connection_set_allow_anonymous
argument_list|,
argument|(DBusConnection             *connection,                                                                 dbus_bool_t                 value)
argument_list|,
argument|(connection, value)
argument_list|,
argument|return
argument_list|)
end_macro
begin_comment
comment|/* dbus-errors.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_error_free
argument_list|,
argument|(DBusError       *error)
argument_list|,
argument|(error)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_error_init
argument_list|,
argument|(DBusError       *error)
argument_list|,
argument|(error)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_error_is_set
argument_list|,
argument|(const DBusError *error)
argument_list|,
argument|(error)
argument_list|,
argument|return
argument_list|)
end_macro
begin_comment
comment|/* dbus-memory.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_free
argument_list|,
argument|(void  *memory)
argument_list|,
argument|(memory)
argument_list|, )
end_macro
begin_comment
comment|/* dbus-message.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage*
argument_list|,
argument|dbus_message_copy
argument_list|,
argument|(const DBusMessage *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_get_auto_start
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_message_get_error_name
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_message_get_interface
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_message_get_member
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_get_no_reply
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_message_get_path
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_message_get_sender
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_uint32_t
argument_list|,
argument|dbus_message_get_serial
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|const char*
argument_list|,
argument|dbus_message_get_signature
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|int
argument_list|,
argument|dbus_message_get_type
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_iter_append_basic
argument_list|,
argument|(DBusMessageIter *iter,                                                           int              type,                                                           const void      *value)
argument_list|,
argument|(iter, type, value)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_iter_append_fixed_array
argument_list|,
argument|(DBusMessageIter *iter,                                                                 int              element_type,                                                                 const void      *value,                                                                 int              n_elements)
argument_list|,
argument|(iter, element_type, value, n_elements)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_iter_close_container
argument_list|,
argument|(DBusMessageIter *iter,                                                              DBusMessageIter *sub)
argument_list|,
argument|(iter, sub)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|int
argument_list|,
argument|dbus_message_iter_get_arg_type
argument_list|,
argument|(DBusMessageIter *iter)
argument_list|,
argument|(iter)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_iter_get_basic
argument_list|,
argument|(DBusMessageIter *iter,                                                        void            *value)
argument_list|,
argument|(iter, value)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|int
argument_list|,
argument|dbus_message_iter_get_element_type
argument_list|,
argument|(DBusMessageIter *iter)
argument_list|,
argument|(iter)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_iter_get_fixed_array
argument_list|,
argument|(DBusMessageIter *iter,                                                              void            *value,                                                              int             *n_elements)
argument_list|,
argument|(iter, value, n_elements)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|char*
argument_list|,
argument|dbus_message_iter_get_signature
argument_list|,
argument|(DBusMessageIter *iter)
argument_list|,
argument|(iter)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_iter_init
argument_list|,
argument|(DBusMessage     *message,                                                   DBusMessageIter *iter)
argument_list|,
argument|(message, iter)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_iter_init_append
argument_list|,
argument|(DBusMessage     *message,                                                          DBusMessageIter *iter)
argument_list|,
argument|(message, iter)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_iter_next
argument_list|,
argument|(DBusMessageIter *iter)
argument_list|,
argument|(iter)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_iter_open_container
argument_list|,
argument|(DBusMessageIter *iter,                                                             int              type,                                                             const char      *contained_signature,                                                             DBusMessageIter *sub)
argument_list|,
argument|(iter, type, contained_signature, sub)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_iter_recurse
argument_list|,
argument|(DBusMessageIter *iter,                                                      DBusMessageIter *sub)
argument_list|,
argument|(iter, sub)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage*
argument_list|,
argument|dbus_message_new
argument_list|,
argument|(int          message_type)
argument_list|,
argument|(message_type)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage*
argument_list|,
argument|dbus_message_new_method_call
argument_list|,
argument|(const char  *bus_name,                                                          const char  *path,                                                          const char  *interface,                                                          const char  *method)
argument_list|,
argument|(bus_name, path, interface, method)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage*
argument_list|,
argument|dbus_message_new_signal
argument_list|,
argument|(const char  *path,                                                     const char  *interface,                                                     const char  *name)
argument_list|,
argument|(path, interface, name)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage*
argument_list|,
argument|dbus_message_ref
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_set_auto_start
argument_list|,
argument|(DBusMessage   *message,                                                          dbus_bool_t    auto_start)
argument_list|,
argument|(message, auto_start)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_set_destination
argument_list|,
argument|(DBusMessage   *message,                                                           const char    *destination)
argument_list|,
argument|(message, destination)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_set_error_name
argument_list|,
argument|(DBusMessage   *message,                                                          const char    *name)
argument_list|,
argument|(message, name)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_set_no_reply
argument_list|,
argument|(DBusMessage   *message,                                                        dbus_bool_t    no_reply)
argument_list|,
argument|(message, no_reply)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_set_path
argument_list|,
argument|(DBusMessage   *message,                                                    const char    *object_path)
argument_list|,
argument|(message, object_path)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_set_reply_serial
argument_list|,
argument|(DBusMessage   *message,                                                            dbus_uint32_t  reply_serial)
argument_list|,
argument|(message, reply_serial)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_message_set_sender
argument_list|,
argument|(DBusMessage   *message,                                                      const char    *sender)
argument_list|,
argument|(message, sender)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_message_unref
argument_list|,
argument|(DBusMessage   *message)
argument_list|,
argument|(message)
argument_list|, )
end_macro
begin_comment
comment|/* dbus-misc.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|char*
argument_list|,
argument|dbus_get_local_machine_id
argument_list|,
argument|(void)
argument_list|,
argument|()
argument_list|,
argument|return
argument_list|)
end_macro
begin_comment
comment|/* dbus-pending-call.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_pending_call_set_notify
argument_list|,
argument|(DBusPendingCall               *pending,                                                          DBusPendingCallNotifyFunction  function,                                                          void                          *user_data,                                                          DBusFreeFunction               free_user_data)
argument_list|,
argument|(pending, function, user_data, free_user_data)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_pending_call_block
argument_list|,
argument|(DBusPendingCall               *pending)
argument_list|,
argument|(pending)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_pending_call_cancel
argument_list|,
argument|(DBusPendingCall               *pending)
argument_list|,
argument|(pending)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_pending_call_get_completed
argument_list|,
argument|(DBusPendingCall               *pending)
argument_list|,
argument|(pending)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusMessage*
argument_list|,
argument|dbus_pending_call_steal_reply
argument_list|,
argument|(DBusPendingCall               *pending)
argument_list|,
argument|(pending)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_pending_call_unref
argument_list|,
argument|(DBusPendingCall               *pending)
argument_list|,
argument|(pending)
argument_list|,
argument|return
argument_list|)
end_macro
begin_comment
comment|/* dbus-server.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_server_allocate_data_slot
argument_list|,
argument|(dbus_int32_t     *slot_p)
argument_list|,
argument|(slot_p)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_server_free_data_slot
argument_list|,
argument|(dbus_int32_t     *slot_p)
argument_list|,
argument|(slot_p)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_server_disconnect
argument_list|,
argument|(DBusServer     *server)
argument_list|,
argument|(server)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|char*
argument_list|,
argument|dbus_server_get_address
argument_list|,
argument|(DBusServer     *server)
argument_list|,
argument|(server)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_server_get_is_connected
argument_list|,
argument|(DBusServer     *server)
argument_list|,
argument|(server)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|DBusServer*
argument_list|,
argument|dbus_server_listen
argument_list|,
argument|(const char     *address,                                               DBusError      *error)
argument_list|,
argument|(address, error)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_server_set_data
argument_list|,
argument|(DBusServer       *server,                                                 int               slot,                                                 void             *data,                                                 DBusFreeFunction  free_data_func)
argument_list|,
argument|(server, slot, data, free_data_func)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_server_set_new_connection_function
argument_list|,
argument|(DBusServer                *server,                                                                    DBusNewConnectionFunction  function,                                                                    void                      *data,                                                                    DBusFreeFunction           free_data_function)
argument_list|,
argument|(server, function, data, free_data_function)
argument_list|, )
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_server_set_timeout_functions
argument_list|,
argument|(DBusServer                *server,                                                              DBusAddTimeoutFunction     add_function,                                                              DBusRemoveTimeoutFunction  remove_function,                                                              DBusTimeoutToggledFunction toggled_function,                                                              void                      *data,                                                              DBusFreeFunction           free_data_function)
argument_list|,
argument|(server, add_function, remove_function, toggled_function, data, free_data_function)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_server_set_watch_functions
argument_list|,
argument|(DBusServer                *server,                                                            DBusAddWatchFunction       add_function,                                                            DBusRemoveWatchFunction    remove_function,                                                            DBusWatchToggledFunction   toggled_function,                                                            void                      *data,                                                            DBusFreeFunction           free_data_function)
argument_list|,
argument|(server, add_function, remove_function, toggled_function, data, free_data_function)
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|DEFINEFUNC
argument_list|(
argument|void
argument_list|,
argument|dbus_server_unref
argument_list|,
argument|(DBusServer     *server)
argument_list|,
argument|(server)
argument_list|, )
end_macro
begin_comment
comment|/* dbus-thread.h */
end_comment
begin_macro
name|DEFINEFUNC
argument_list|(
argument|dbus_bool_t
argument_list|,
argument|dbus_threads_init_default
argument_list|,
argument|()
argument_list|,
argument|()
argument_list|,
argument|return
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DBUS
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QDBUS_SYMBOLS_P_H
end_comment
end_unit
