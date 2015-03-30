begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtDBus module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qdbuserror.h"
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_include
include|#
directive|include
file|"qdbus_symbols_p.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmessage.h"
end_include
begin_include
include|#
directive|include
file|"qdbusmessage_p.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DBUS
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*  * Use the following Perl script to generate the error string index list: ===== PERL SCRIPT ==== print "static const char errorMessages_string[] =\n"; $counter = 0; $i = 0; while (<STDIN>) {     chomp;     print "    \"$_\\0\"\n";     $sizes[$i++] = $counter;     $counter += 1 + length $_; } print "    \"\\0\";\n\nstatic const int errorMessages_indices[] = {\n    "; for ($j = 0; $j< $i; ++$j) {     printf "$sizes[$j], "; } print "0\n};\n"; ===== PERL SCRIPT ====   * The input data is as follows: other org.freedesktop.DBus.Error.Failed org.freedesktop.DBus.Error.NoMemory org.freedesktop.DBus.Error.ServiceUnknown org.freedesktop.DBus.Error.NoReply org.freedesktop.DBus.Error.BadAddress org.freedesktop.DBus.Error.NotSupported org.freedesktop.DBus.Error.LimitsExceeded org.freedesktop.DBus.Error.AccessDenied org.freedesktop.DBus.Error.NoServer org.freedesktop.DBus.Error.Timeout org.freedesktop.DBus.Error.NoNetwork org.freedesktop.DBus.Error.AddressInUse org.freedesktop.DBus.Error.Disconnected org.freedesktop.DBus.Error.InvalidArgs org.freedesktop.DBus.Error.UnknownMethod org.freedesktop.DBus.Error.TimedOut org.freedesktop.DBus.Error.InvalidSignature org.freedesktop.DBus.Error.UnknownInterface org.freedesktop.DBus.Error.UnknownObject org.freedesktop.DBus.Error.UnknownProperty org.freedesktop.DBus.Error.PropertyReadOnly org.qtproject.QtDBus.Error.InternalError org.qtproject.QtDBus.Error.InvalidService org.qtproject.QtDBus.Error.InvalidObjectPath org.qtproject.QtDBus.Error.InvalidInterface org.qtproject.QtDBus.Error.InvalidMember */
comment|// in the same order as KnownErrors!
DECL|variable|errorMessages_string
specifier|static
specifier|const
name|char
name|errorMessages_string
index|[]
init|=
literal|"other\0"
literal|"org.freedesktop.DBus.Error.Failed\0"
literal|"org.freedesktop.DBus.Error.NoMemory\0"
literal|"org.freedesktop.DBus.Error.ServiceUnknown\0"
literal|"org.freedesktop.DBus.Error.NoReply\0"
literal|"org.freedesktop.DBus.Error.BadAddress\0"
literal|"org.freedesktop.DBus.Error.NotSupported\0"
literal|"org.freedesktop.DBus.Error.LimitsExceeded\0"
literal|"org.freedesktop.DBus.Error.AccessDenied\0"
literal|"org.freedesktop.DBus.Error.NoServer\0"
literal|"org.freedesktop.DBus.Error.Timeout\0"
literal|"org.freedesktop.DBus.Error.NoNetwork\0"
literal|"org.freedesktop.DBus.Error.AddressInUse\0"
literal|"org.freedesktop.DBus.Error.Disconnected\0"
literal|"org.freedesktop.DBus.Error.InvalidArgs\0"
literal|"org.freedesktop.DBus.Error.UnknownMethod\0"
literal|"org.freedesktop.DBus.Error.TimedOut\0"
literal|"org.freedesktop.DBus.Error.InvalidSignature\0"
literal|"org.freedesktop.DBus.Error.UnknownInterface\0"
literal|"org.freedesktop.DBus.Error.UnknownObject\0"
literal|"org.freedesktop.DBus.Error.UnknownProperty\0"
literal|"org.freedesktop.DBus.Error.PropertyReadOnly\0"
literal|"org.qtproject.QtDBus.Error.InternalError\0"
literal|"org.qtproject.QtDBus.Error.InvalidService\0"
literal|"org.qtproject.QtDBus.Error.InvalidObjectPath\0"
literal|"org.qtproject.QtDBus.Error.InvalidInterface\0"
literal|"org.qtproject.QtDBus.Error.InvalidMember\0"
literal|"\0"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|errorMessages_indices
specifier|static
specifier|const
name|int
name|errorMessages_indices
index|[]
init|=
block|{
literal|0
block|,
literal|6
block|,
literal|40
block|,
literal|76
block|,
literal|118
block|,
literal|153
block|,
literal|191
block|,
literal|231
block|,
literal|273
block|,
literal|313
block|,
literal|349
block|,
literal|384
block|,
literal|421
block|,
literal|461
block|,
literal|501
block|,
literal|540
block|,
literal|581
block|,
literal|617
block|,
literal|661
block|,
literal|705
block|,
literal|746
block|,
literal|789
block|,
literal|833
block|,
literal|874
block|,
literal|916
block|,
literal|961
block|,
literal|1005
block|,
operator|-
literal|1
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|errorMessages_count
specifier|static
specifier|const
name|int
name|errorMessages_count
init|=
sizeof|sizeof
name|errorMessages_indices
operator|/
sizeof|sizeof
name|errorMessages_indices
index|[
literal|0
index|]
operator|-
literal|1
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|get
specifier|static
specifier|inline
specifier|const
name|char
modifier|*
name|get
parameter_list|(
name|QDBusError
operator|::
name|ErrorType
name|code
parameter_list|)
block|{
name|int
name|intcode
init|=
name|qBound
argument_list|(
literal|0
argument_list|,
name|int
argument_list|(
name|code
argument_list|)
operator|-
name|int
argument_list|(
name|QDBusError
operator|::
name|Other
argument_list|)
argument_list|,
name|errorMessages_count
argument_list|)
decl_stmt|;
return|return
name|errorMessages_string
operator|+
name|errorMessages_indices
index|[
name|intcode
index|]
return|;
block|}
end_function
begin_function
DECL|function|get
specifier|static
specifier|inline
name|QDBusError
operator|::
name|ErrorType
name|get
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
operator|!
name|name
operator|||
operator|!
operator|*
name|name
condition|)
return|return
name|QDBusError
operator|::
name|NoError
return|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|errorMessages_count
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|errorMessages_string
operator|+
name|errorMessages_indices
index|[
name|i
index|]
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QDBusError
operator|::
name|ErrorType
argument_list|(
name|i
operator|+
name|int
argument_list|(
name|QDBusError
operator|::
name|Other
argument_list|)
argument_list|)
return|;
return|return
name|QDBusError
operator|::
name|Other
return|;
block|}
end_function
begin_comment
comment|/*!     \class QDBusError     \inmodule QtDBus     \since 4.2      \brief The QDBusError class represents an error received from the     D-Bus bus or from remote applications found in the bus.      When dealing with the D-Bus bus service or with remote     applications over D-Bus, a number of error conditions can     happen. This error conditions are sometimes signalled by a     returned error value or by a QDBusError.      C++ and Java exceptions are a valid analogy for D-Bus errors:     instead of returning normally with a return value, remote     applications and the bus may decide to throw an error     condition. However, the Qt D-Bus implementation does not use the C++     exception-throwing mechanism, so you will receive QDBusErrors in     the return reply (see QDBusReply::error()).      QDBusError objects are used to inspect the error name and message     as received from the bus and remote applications. You should not     create such objects yourself to signal error conditions when     called from D-Bus: instead, use QDBusMessage::createError() and     QDBusConnection::send().      \sa QDBusConnection::send(), QDBusMessage, QDBusReply */
end_comment
begin_comment
comment|/*!     \enum QDBusError::ErrorType      In order to facilitate verification of the most common D-Bus errors generated by the D-Bus     implementation and by the bus daemon itself, QDBusError can be compared to a set of pre-defined     values:      \value NoError              QDBusError is invalid (i.e., the call succeeded)     \value Other                QDBusError contains an error that is one of the well-known ones     \value Failed               The call failed (\c org.freedesktop.DBus.Error.Failed)     \value NoMemory             Out of memory (\c org.freedesktop.DBus.Error.NoMemory)     \value ServiceUnknown       The called service is not known                                 (\c org.freedesktop.DBus.Error.ServiceUnknown)     \value NoReply              The called method did not reply within the specified timeout                                 (\c org.freedesktop.DBus.Error.NoReply)     \value BadAddress           The address given is not valid                                 (\c org.freedesktop.DBus.Error.BadAddress)     \value NotSupported         The call/operation is not supported                                 (\c org.freedesktop.DBus.Error.NotSupported)     \value LimitsExceeded       The limits allocated to this process/call/connection exceeded the                                 pre-defined values (\c org.freedesktop.DBus.Error.LimitsExceeded)     \value AccessDenied         The call/operation tried to access a resource it isn't allowed to                                 (\c org.freedesktop.DBus.Error.AccessDenied)     \value NoServer             \e {Documentation doesn't say what this is for}                                 (\c org.freedesktop.DBus.Error.NoServer)     \value Timeout              \e {Documentation doesn't say what this is for or how it's used}                                 (\c org.freedesktop.DBus.Error.Timeout)     \value NoNetwork            \e {Documentation doesn't say what this is for}                                 (\c org.freedesktop.DBus.Error.NoNetwork)     \value AddressInUse         QDBusServer tried to bind to an address that is already in use                                 (\c org.freedesktop.DBus.Error.AddressInUse)     \value Disconnected         The call/process/message was sent after QDBusConnection disconnected                                 (\c org.freedesktop.DBus.Error.Disconnected)     \value InvalidArgs          The arguments passed to this call/operation are not valid                                 (\c org.freedesktop.DBus.Error.InvalidArgs)     \value UnknownMethod        The method called was not found in this object/interface with the                                 given parameters (\c org.freedesktop.DBus.Error.UnknownMethod)     \value TimedOut             \e {Documentation doesn't say...}                                 (\c org.freedesktop.DBus.Error.TimedOut)     \value InvalidSignature     The type signature is not valid or compatible                                 (\c org.freedesktop.DBus.Error.InvalidSignature)     \value UnknownInterface     The interface is not known in this object                                 (\c org.freedesktop.DBus.Error.UnknownInterface)     \value UnknownObject        The object path points to an object that does not exist                                 (\c org.freedesktop.DBus.Error.UnknownObject)     \value UnknownProperty      The property does not exist in this interface                                 (\c org.freedesktop.DBus.Error.UnknownProperty)     \value PropertyReadOnly     The property set failed because the property is read-only                                 (\c org.freedesktop.DBus.Error.PropertyReadOnly)      \value InternalError        An internal error occurred      \value InvalidObjectPath    The object path provided is invalid.      \value InvalidService       The service requested is invalid.      \value InvalidMember        The member is invalid.      \value InvalidInterface     The interface is invalid. */
end_comment
begin_comment
comment|/*!     \internal     Constructs a QDBusError that represents no error. */
end_comment
begin_constructor
DECL|function|QDBusError
name|QDBusError
operator|::
name|QDBusError
parameter_list|()
member_init_list|:
name|code
argument_list|(
name|NoError
argument_list|)
block|{
comment|// ### This class has an implicit (therefore inline) destructor
comment|// so the following field cannot be used.
name|Q_UNUSED
argument_list|(
name|unused
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_comment
comment|/*!     \internal     Constructs a QDBusError from a DBusError structure. */
end_comment
begin_constructor
DECL|function|QDBusError
name|QDBusError
operator|::
name|QDBusError
parameter_list|(
specifier|const
name|DBusError
modifier|*
name|error
parameter_list|)
member_init_list|:
name|code
argument_list|(
name|NoError
argument_list|)
block|{
if|if
condition|(
operator|!
name|error
operator|||
operator|!
name|q_dbus_error_is_set
argument_list|(
name|error
argument_list|)
condition|)
return|return;
name|code
operator|=
operator|::
name|get
argument_list|(
name|error
operator|->
name|name
argument_list|)
expr_stmt|;
name|msg
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|error
operator|->
name|message
argument_list|)
expr_stmt|;
name|nm
operator|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|error
operator|->
name|name
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal     Constructs a QDBusError from a QDBusMessage. */
end_comment
begin_constructor
DECL|function|QDBusError
name|QDBusError
operator|::
name|QDBusError
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|qdmsg
parameter_list|)
member_init_list|:
name|code
argument_list|(
name|NoError
argument_list|)
block|{
if|if
condition|(
name|qdmsg
operator|.
name|type
argument_list|()
operator|!=
name|QDBusMessage
operator|::
name|ErrorMessage
condition|)
return|return;
name|code
operator|=
operator|::
name|get
argument_list|(
name|qdmsg
operator|.
name|errorName
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|nm
operator|=
name|qdmsg
operator|.
name|errorName
argument_list|()
expr_stmt|;
name|msg
operator|=
name|qdmsg
operator|.
name|errorMessage
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \internal     Constructs a QDBusError from a well-known error code */
end_comment
begin_constructor
DECL|function|QDBusError
name|QDBusError
operator|::
name|QDBusError
parameter_list|(
name|ErrorType
name|error
parameter_list|,
specifier|const
name|QString
modifier|&
name|mess
parameter_list|)
member_init_list|:
name|code
argument_list|(
name|error
argument_list|)
block|{
name|nm
operator|=
name|QLatin1String
argument_list|(
operator|::
name|get
argument_list|(
name|error
argument_list|)
argument_list|)
expr_stmt|;
name|msg
operator|=
name|mess
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal     Constructs a QDBusError from another QDBusError object */
end_comment
begin_constructor
DECL|function|QDBusError
name|QDBusError
operator|::
name|QDBusError
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|other
parameter_list|)
member_init_list|:
name|code
argument_list|(
name|other
operator|.
name|code
argument_list|)
member_init_list|,
name|msg
argument_list|(
name|other
operator|.
name|msg
argument_list|)
member_init_list|,
name|nm
argument_list|(
name|other
operator|.
name|nm
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!   \internal   Assignment operator */
end_comment
begin_function
DECL|function|operator =
name|QDBusError
modifier|&
name|QDBusError
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QDBusError
modifier|&
name|other
parameter_list|)
block|{
name|code
operator|=
name|other
operator|.
name|code
expr_stmt|;
name|msg
operator|=
name|other
operator|.
name|msg
expr_stmt|;
name|nm
operator|=
name|other
operator|.
name|nm
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_BOOTSTRAPPED
end_ifndef
begin_comment
comment|/*!   \internal   Assignment operator from a QDBusMessage */
end_comment
begin_function
DECL|function|operator =
name|QDBusError
modifier|&
name|QDBusError
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QDBusMessage
modifier|&
name|qdmsg
parameter_list|)
block|{
if|if
condition|(
name|qdmsg
operator|.
name|type
argument_list|()
operator|==
name|QDBusMessage
operator|::
name|ErrorMessage
condition|)
block|{
name|code
operator|=
operator|::
name|get
argument_list|(
name|qdmsg
operator|.
name|errorName
argument_list|()
operator|.
name|toUtf8
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
name|nm
operator|=
name|qdmsg
operator|.
name|errorName
argument_list|()
expr_stmt|;
name|msg
operator|=
name|qdmsg
operator|.
name|errorMessage
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|code
operator|=
name|NoError
expr_stmt|;
name|nm
operator|.
name|clear
argument_list|()
expr_stmt|;
name|msg
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     Returns this error's ErrorType.      \sa ErrorType */
end_comment
begin_function
DECL|function|type
name|QDBusError
operator|::
name|ErrorType
name|QDBusError
operator|::
name|type
parameter_list|()
specifier|const
block|{
return|return
name|code
return|;
block|}
end_function
begin_comment
comment|/*!     Returns this error's name. Error names are similar to D-Bus Interface names, like     \c org.freedesktop.DBus.InvalidArgs.      \sa type() */
end_comment
begin_function
DECL|function|name
name|QString
name|QDBusError
operator|::
name|name
parameter_list|()
specifier|const
block|{
return|return
name|nm
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the message that the callee associated with this error. Error messages are     implementation defined and usually contain a human-readable error code, though this does not     mean it is suitable for your end-users. */
end_comment
begin_function
DECL|function|message
name|QString
name|QDBusError
operator|::
name|message
parameter_list|()
specifier|const
block|{
return|return
name|msg
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if this is a valid error condition (i.e., if there was an error),     otherwise false. */
end_comment
begin_function
DECL|function|isValid
name|bool
name|QDBusError
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|code
operator|!=
name|NoError
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.3     Returns the error name associated with error condition \a error. */
end_comment
begin_function
DECL|function|errorString
name|QString
name|QDBusError
operator|::
name|errorString
parameter_list|(
name|ErrorType
name|error
parameter_list|)
block|{
return|return
name|QLatin1String
argument_list|(
operator|::
name|get
argument_list|(
name|error
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|dbg
parameter_list|,
specifier|const
name|QDBusError
modifier|&
name|msg
parameter_list|)
block|{
name|QDebugStateSaver
name|saver
argument_list|(
name|dbg
argument_list|)
decl_stmt|;
name|dbg
operator|.
name|nospace
argument_list|()
operator|<<
literal|"QDBusError("
operator|<<
name|msg
operator|.
name|name
argument_list|()
operator|<<
literal|", "
operator|<<
name|msg
operator|.
name|message
argument_list|()
operator|<<
literal|')'
expr_stmt|;
return|return
name|dbg
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
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
