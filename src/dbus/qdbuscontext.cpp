begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbusmessage.h"
end_include
begin_include
include|#
directive|include
file|"qdbusconnection.h"
end_include
begin_include
include|#
directive|include
file|"qdbusabstractadaptor.h"
end_include
begin_include
include|#
directive|include
file|"qdbuscontext.h"
end_include
begin_include
include|#
directive|include
file|"qdbuscontext_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|set
name|QDBusContextPrivate
modifier|*
name|QDBusContextPrivate
operator|::
name|set
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QDBusContextPrivate
modifier|*
name|newContext
parameter_list|)
block|{
comment|// determine if this is an adaptor or not
if|if
condition|(
name|qobject_cast
argument_list|<
name|QDBusAbstractAdaptor
operator|*
argument_list|>
argument_list|(
name|obj
argument_list|)
condition|)
name|obj
operator|=
name|obj
operator|->
name|parent
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|obj
argument_list|)
expr_stmt|;
name|void
modifier|*
name|ptr
init|=
name|obj
operator|->
name|qt_metacast
argument_list|(
literal|"QDBusContext"
argument_list|)
decl_stmt|;
name|QDBusContext
modifier|*
name|q_ptr
init|=
cast|reinterpret_cast
argument_list|<
name|QDBusContext
operator|*
argument_list|>
argument_list|(
name|ptr
argument_list|)
decl_stmt|;
if|if
condition|(
name|q_ptr
condition|)
block|{
name|QDBusContextPrivate
modifier|*
name|old
init|=
name|q_ptr
operator|->
name|d_ptr
decl_stmt|;
name|q_ptr
operator|->
name|d_ptr
operator|=
name|newContext
expr_stmt|;
return|return
name|old
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.3     \class QDBusContext     \inmodule QtDBus      \brief The QDBusContext class allows slots to determine the D-Bus context of the calls.      When a slot is called in an object due to a signal delivery or due     to a remote method call, it is sometimes necessary to know the     context in which that happened. In particular, if the slot     determines that it wants to send the reply at a later opportunity     or if it wants to reply with an error, the context is needed.      The QDBusContext class is an alternative to accessing the context     that doesn't involve modifying the code generated by the \l     {QtDBus XML Compiler (qdbusxml2cpp)}.      QDBusContext is used by subclassing it from the objects being     exported using QDBusConnection::registerObject(). The following     example illustrates the usage:      \snippet doc/src/snippets/code/src_qdbus_qdbuscontext.cpp 0      The example illustrates the two typical uses, that of sending     error replies and that of delayed replies.      Note: do not subclass QDBusContext and QDBusAbstractAdaptor at the     same time. QDBusContext should appear in the real object, not the     adaptor. If it's necessary from the adaptor code to determine the     context, use a public inheritance and access the functions via     QObject::parent(). */
end_comment
begin_comment
comment|/*!   Constructs an empty QDBusContext.  */
end_comment
begin_constructor
DECL|function|QDBusContext
name|QDBusContext
operator|::
name|QDBusContext
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   An empty destructor.  */
end_comment
begin_destructor
DECL|function|~QDBusContext
name|QDBusContext
operator|::
name|~
name|QDBusContext
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns true if we are processing a D-Bus call. If this function     returns true, the rest of the functions in this class are     available.      Accessing those functions when this function returns false is     undefined and may lead to crashes. */
end_comment
begin_function
DECL|function|calledFromDBus
name|bool
name|QDBusContext
operator|::
name|calledFromDBus
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the connection from which this call was received. */
end_comment
begin_function
DECL|function|connection
name|QDBusConnection
name|QDBusContext
operator|::
name|connection
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|connection
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the message that generated this call. */
end_comment
begin_function
DECL|function|message
specifier|const
name|QDBusMessage
modifier|&
name|QDBusContext
operator|::
name|message
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|message
return|;
block|}
end_function
begin_comment
comment|/*!     Returns true if this call will have a delayed reply.      \sa setDelayedReply() */
end_comment
begin_function
DECL|function|isDelayedReply
name|bool
name|QDBusContext
operator|::
name|isDelayedReply
parameter_list|()
specifier|const
block|{
return|return
name|message
argument_list|()
operator|.
name|isDelayedReply
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Sets whether this call will have a delayed reply or not.      If \a enable is false, QtDBus will automatically generate a reply     back to the caller, if needed, as soon as the called slot returns.      If \a enable is true, QtDBus will not generate automatic     replies. It will also ignore the return value from the slot and     any output parameters. Instead, the called object is responsible     for storing the incoming message and send a reply or error at a     later time.      Failing to send a reply will result in an automatic timeout error     being generated by D-Bus. */
end_comment
begin_function
DECL|function|setDelayedReply
name|void
name|QDBusContext
operator|::
name|setDelayedReply
parameter_list|(
name|bool
name|enable
parameter_list|)
specifier|const
block|{
name|message
argument_list|()
operator|.
name|setDelayedReply
argument_list|(
name|enable
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sends an error \a name as a reply to the caller. The optional \a     msg parameter is a human-readable text explaining the failure.      If an error is sent, the return value and any output parameters     from the called slot will be ignored by QtDBus. */
end_comment
begin_function
DECL|function|sendErrorReply
name|void
name|QDBusContext
operator|::
name|sendErrorReply
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
specifier|const
block|{
name|setDelayedReply
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connection
argument_list|()
operator|.
name|send
argument_list|(
name|message
argument_list|()
operator|.
name|createErrorReply
argument_list|(
name|name
argument_list|,
name|msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \overload     Sends an error \a type as a reply to the caller. The optional \a     msg parameter is a human-readable text explaining the failure.      If an error is sent, the return value and any output parameters     from the called slot will be ignored by QtDBus. */
end_comment
begin_function
DECL|function|sendErrorReply
name|void
name|QDBusContext
operator|::
name|sendErrorReply
parameter_list|(
name|QDBusError
operator|::
name|ErrorType
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|msg
parameter_list|)
specifier|const
block|{
name|setDelayedReply
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|connection
argument_list|()
operator|.
name|send
argument_list|(
name|message
argument_list|()
operator|.
name|createErrorReply
argument_list|(
name|type
argument_list|,
name|msg
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
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
end_unit
