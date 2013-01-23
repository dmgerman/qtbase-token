begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlocalserver.h"
end_include
begin_include
include|#
directive|include
file|"qlocalserver_p.h"
end_include
begin_include
include|#
directive|include
file|"qlocalsocket.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qsystemerror_p.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<aclapi.h>
end_include
begin_include
include|#
directive|include
file|<accctrl.h>
end_include
begin_include
include|#
directive|include
file|<sddl.h>
end_include
begin_comment
comment|// The buffer size need to be 0 otherwise data could be
end_comment
begin_comment
comment|// lost if the socket that has written data closes the connection
end_comment
begin_comment
comment|// before it is read.  Pipewriter is used for write buffering.
end_comment
begin_define
DECL|macro|BUFSIZE
define|#
directive|define
name|BUFSIZE
value|0
end_define
begin_comment
comment|// ###: This should be a property. Should replace the insane 50 on unix as well.
end_comment
begin_define
DECL|macro|SYSTEM_MAX_PENDING_SOCKETS
define|#
directive|define
name|SYSTEM_MAX_PENDING_SOCKETS
value|8
end_define
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|addListener
name|bool
name|QLocalServerPrivate
operator|::
name|addListener
parameter_list|()
block|{
comment|// The object must not change its address once the
comment|// contained OVERLAPPED struct is passed to Windows.
name|listeners
operator|<<
name|Listener
argument_list|()
expr_stmt|;
name|Listener
modifier|&
name|listener
init|=
name|listeners
operator|.
name|last
argument_list|()
decl_stmt|;
name|SECURITY_ATTRIBUTES
name|sa
decl_stmt|;
name|sa
operator|.
name|nLength
operator|=
sizeof|sizeof
argument_list|(
name|SECURITY_ATTRIBUTES
argument_list|)
expr_stmt|;
name|sa
operator|.
name|bInheritHandle
operator|=
name|FALSE
expr_stmt|;
comment|//non inheritable handle, same as default
name|sa
operator|.
name|lpSecurityDescriptor
operator|=
literal|0
expr_stmt|;
comment|//default security descriptor
name|QScopedPointer
argument_list|<
name|SECURITY_DESCRIPTOR
argument_list|>
name|pSD
decl_stmt|;
name|PSID
name|worldSID
init|=
literal|0
decl_stmt|;
name|QByteArray
name|aclBuffer
decl_stmt|;
name|QByteArray
name|tokenUserBuffer
decl_stmt|;
name|QByteArray
name|tokenGroupBuffer
decl_stmt|;
comment|// create security descriptor if access options were specified
if|if
condition|(
operator|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|WorldAccessOption
operator|)
condition|)
block|{
name|pSD
operator|.
name|reset
argument_list|(
operator|new
name|SECURITY_DESCRIPTOR
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|InitializeSecurityDescriptor
argument_list|(
name|pSD
operator|.
name|data
argument_list|()
argument_list|,
name|SECURITY_DESCRIPTOR_REVISION
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|HANDLE
name|hToken
init|=
name|NULL
decl_stmt|;
if|if
condition|(
operator|!
name|OpenProcessToken
argument_list|(
name|GetCurrentProcess
argument_list|()
argument_list|,
name|TOKEN_QUERY
argument_list|,
operator|&
name|hToken
argument_list|)
condition|)
return|return
literal|false
return|;
name|DWORD
name|dwBufferSize
init|=
literal|0
decl_stmt|;
name|GetTokenInformation
argument_list|(
name|hToken
argument_list|,
name|TokenUser
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|dwBufferSize
argument_list|)
expr_stmt|;
name|tokenUserBuffer
operator|.
name|fill
argument_list|(
literal|0
argument_list|,
name|dwBufferSize
argument_list|)
expr_stmt|;
name|PTOKEN_USER
name|pTokenUser
init|=
operator|(
name|PTOKEN_USER
operator|)
name|tokenUserBuffer
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|GetTokenInformation
argument_list|(
name|hToken
argument_list|,
name|TokenUser
argument_list|,
name|pTokenUser
argument_list|,
name|dwBufferSize
argument_list|,
operator|&
name|dwBufferSize
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hToken
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|dwBufferSize
operator|=
literal|0
expr_stmt|;
name|GetTokenInformation
argument_list|(
name|hToken
argument_list|,
name|TokenPrimaryGroup
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|dwBufferSize
argument_list|)
expr_stmt|;
name|tokenGroupBuffer
operator|.
name|fill
argument_list|(
literal|0
argument_list|,
name|dwBufferSize
argument_list|)
expr_stmt|;
name|PTOKEN_PRIMARY_GROUP
name|pTokenGroup
init|=
operator|(
name|PTOKEN_PRIMARY_GROUP
operator|)
name|tokenGroupBuffer
operator|.
name|data
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|GetTokenInformation
argument_list|(
name|hToken
argument_list|,
name|TokenPrimaryGroup
argument_list|,
name|pTokenGroup
argument_list|,
name|dwBufferSize
argument_list|,
operator|&
name|dwBufferSize
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|hToken
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|CloseHandle
argument_list|(
name|hToken
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QLOCALSERVER_DEBUG
name|DWORD
name|groupNameSize
decl_stmt|;
name|DWORD
name|domainNameSize
decl_stmt|;
name|SID_NAME_USE
name|groupNameUse
decl_stmt|;
name|LPWSTR
name|groupNameSid
decl_stmt|;
name|LookupAccountSid
argument_list|(
literal|0
argument_list|,
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|,
literal|0
argument_list|,
operator|&
name|groupNameSize
argument_list|,
literal|0
argument_list|,
operator|&
name|domainNameSize
argument_list|,
operator|&
name|groupNameUse
argument_list|)
expr_stmt|;
name|QScopedPointer
argument_list|<
name|wchar_t
argument_list|,
name|QScopedPointerArrayDeleter
argument_list|<
name|wchar_t
argument_list|>
argument_list|>
name|groupName
argument_list|(
operator|new
name|wchar_t
index|[
name|groupNameSize
index|]
argument_list|)
decl_stmt|;
name|QScopedPointer
argument_list|<
name|wchar_t
argument_list|,
name|QScopedPointerArrayDeleter
argument_list|<
name|wchar_t
argument_list|>
argument_list|>
name|domainName
argument_list|(
operator|new
name|wchar_t
index|[
name|domainNameSize
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|LookupAccountSid
argument_list|(
literal|0
argument_list|,
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|,
name|groupName
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|groupNameSize
argument_list|,
name|domainName
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|domainNameSize
argument_list|,
operator|&
name|groupNameUse
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"primary group"
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|domainName
operator|.
name|data
argument_list|()
argument_list|)
operator|<<
literal|"\\"
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|groupName
operator|.
name|data
argument_list|()
argument_list|)
operator|<<
literal|"type="
operator|<<
name|groupNameUse
expr_stmt|;
block|}
if|if
condition|(
name|ConvertSidToStringSid
argument_list|(
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|,
operator|&
name|groupNameSid
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"primary group SID"
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|groupNameSid
argument_list|)
operator|<<
literal|"valid"
operator|<<
name|IsValidSid
argument_list|(
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|)
expr_stmt|;
name|LocalFree
argument_list|(
name|groupNameSid
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|SID_IDENTIFIER_AUTHORITY
name|WorldAuth
init|=
block|{
name|SECURITY_WORLD_SID_AUTHORITY
block|}
decl_stmt|;
if|if
condition|(
operator|!
name|AllocateAndInitializeSid
argument_list|(
operator|&
name|WorldAuth
argument_list|,
literal|1
argument_list|,
name|SECURITY_WORLD_RID
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|worldSID
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|//calculate size of ACL buffer
name|DWORD
name|aclSize
init|=
sizeof|sizeof
argument_list|(
name|ACL
argument_list|)
operator|+
operator|(
operator|(
sizeof|sizeof
argument_list|(
name|ACCESS_ALLOWED_ACE
argument_list|)
operator|)
operator|*
literal|3
operator|)
decl_stmt|;
name|aclSize
operator|+=
name|GetLengthSid
argument_list|(
name|pTokenUser
operator|->
name|User
operator|.
name|Sid
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
expr_stmt|;
name|aclSize
operator|+=
name|GetLengthSid
argument_list|(
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
expr_stmt|;
name|aclSize
operator|+=
name|GetLengthSid
argument_list|(
name|worldSID
argument_list|)
operator|-
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
expr_stmt|;
name|aclSize
operator|=
operator|(
name|aclSize
operator|+
operator|(
sizeof|sizeof
argument_list|(
name|DWORD
argument_list|)
operator|-
literal|1
operator|)
operator|)
operator|&
literal|0xfffffffc
expr_stmt|;
name|aclBuffer
operator|.
name|fill
argument_list|(
literal|0
argument_list|,
name|aclSize
argument_list|)
expr_stmt|;
name|PACL
name|acl
init|=
operator|(
name|PACL
operator|)
name|aclBuffer
operator|.
name|data
argument_list|()
decl_stmt|;
name|InitializeAcl
argument_list|(
name|acl
argument_list|,
name|aclSize
argument_list|,
name|ACL_REVISION_DS
argument_list|)
expr_stmt|;
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|UserAccessOption
condition|)
block|{
if|if
condition|(
operator|!
name|AddAccessAllowedAce
argument_list|(
name|acl
argument_list|,
name|ACL_REVISION
argument_list|,
name|FILE_ALL_ACCESS
argument_list|,
name|pTokenUser
operator|->
name|User
operator|.
name|Sid
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|FreeSid
argument_list|(
name|worldSID
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|GroupAccessOption
condition|)
block|{
if|if
condition|(
operator|!
name|AddAccessAllowedAce
argument_list|(
name|acl
argument_list|,
name|ACL_REVISION
argument_list|,
name|FILE_ALL_ACCESS
argument_list|,
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|FreeSid
argument_list|(
name|worldSID
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
if|if
condition|(
name|socketOptions
operator|&
name|QLocalServer
operator|::
name|OtherAccessOption
condition|)
block|{
if|if
condition|(
operator|!
name|AddAccessAllowedAce
argument_list|(
name|acl
argument_list|,
name|ACL_REVISION
argument_list|,
name|FILE_ALL_ACCESS
argument_list|,
name|worldSID
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|FreeSid
argument_list|(
name|worldSID
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
name|SetSecurityDescriptorOwner
argument_list|(
name|pSD
operator|.
name|data
argument_list|()
argument_list|,
name|pTokenUser
operator|->
name|User
operator|.
name|Sid
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|SetSecurityDescriptorGroup
argument_list|(
name|pSD
operator|.
name|data
argument_list|()
argument_list|,
name|pTokenGroup
operator|->
name|PrimaryGroup
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|SetSecurityDescriptorDacl
argument_list|(
name|pSD
operator|.
name|data
argument_list|()
argument_list|,
name|TRUE
argument_list|,
name|acl
argument_list|,
name|FALSE
argument_list|)
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|FreeSid
argument_list|(
name|worldSID
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|sa
operator|.
name|lpSecurityDescriptor
operator|=
name|pSD
operator|.
name|data
argument_list|()
expr_stmt|;
block|}
name|listener
operator|.
name|handle
operator|=
name|CreateNamedPipe
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|fullServerName
operator|.
name|utf16
argument_list|()
argument_list|,
comment|// pipe name
name|PIPE_ACCESS_DUPLEX
operator||
name|FILE_FLAG_OVERLAPPED
argument_list|,
comment|// read/write access
name|PIPE_TYPE_BYTE
operator||
comment|// byte type pipe
name|PIPE_READMODE_BYTE
operator||
comment|// byte-read mode
name|PIPE_WAIT
argument_list|,
comment|// blocking mode
name|PIPE_UNLIMITED_INSTANCES
argument_list|,
comment|// max. instances
name|BUFSIZE
argument_list|,
comment|// output buffer size
name|BUFSIZE
argument_list|,
comment|// input buffer size
literal|3000
argument_list|,
comment|// client time-out
operator|&
name|sa
argument_list|)
expr_stmt|;
if|if
condition|(
name|listener
operator|.
name|handle
operator|==
name|INVALID_HANDLE_VALUE
condition|)
block|{
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|listeners
operator|.
name|removeLast
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|worldSID
condition|)
name|FreeSid
argument_list|(
name|worldSID
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|listener
operator|.
name|overlapped
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|listener
operator|.
name|overlapped
argument_list|)
argument_list|)
expr_stmt|;
name|listener
operator|.
name|overlapped
operator|.
name|hEvent
operator|=
name|eventHandle
expr_stmt|;
if|if
condition|(
operator|!
name|ConnectNamedPipe
argument_list|(
name|listener
operator|.
name|handle
argument_list|,
operator|&
name|listener
operator|.
name|overlapped
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|GetLastError
argument_list|()
condition|)
block|{
case|case
name|ERROR_IO_PENDING
case|:
name|listener
operator|.
name|connected
operator|=
literal|false
expr_stmt|;
break|break;
case|case
name|ERROR_PIPE_CONNECTED
case|:
name|listener
operator|.
name|connected
operator|=
literal|true
expr_stmt|;
name|SetEvent
argument_list|(
name|eventHandle
argument_list|)
expr_stmt|;
break|break;
default|default:
name|CloseHandle
argument_list|(
name|listener
operator|.
name|handle
argument_list|)
expr_stmt|;
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::addListener"
argument_list|)
argument_list|)
expr_stmt|;
name|listeners
operator|.
name|removeLast
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
else|else
block|{
name|Q_ASSERT_X
argument_list|(
literal|false
argument_list|,
literal|"QLocalServerPrivate::addListener"
argument_list|,
literal|"The impossible happened"
argument_list|)
expr_stmt|;
name|SetEvent
argument_list|(
name|eventHandle
argument_list|)
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setError
name|void
name|QLocalServerPrivate
operator|::
name|setError
parameter_list|(
specifier|const
name|QString
modifier|&
name|function
parameter_list|)
block|{
name|int
name|windowsError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
name|errorString
operator|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1: %2"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
operator|.
name|arg
argument_list|(
name|qt_error_string
argument_list|(
name|windowsError
argument_list|)
argument_list|)
expr_stmt|;
name|error
operator|=
name|QAbstractSocket
operator|::
name|UnknownSocketError
expr_stmt|;
block|}
end_function
begin_function
DECL|function|init
name|void
name|QLocalServerPrivate
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|removeServer
name|bool
name|QLocalServerPrivate
operator|::
name|removeServer
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|name
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|listen
name|bool
name|QLocalServerPrivate
operator|::
name|listen
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
name|QString
name|pipePath
init|=
name|QLatin1String
argument_list|(
literal|"\\\\.\\pipe\\"
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|.
name|startsWith
argument_list|(
name|pipePath
argument_list|)
condition|)
name|fullServerName
operator|=
name|name
expr_stmt|;
else|else
name|fullServerName
operator|=
name|pipePath
operator|+
name|name
expr_stmt|;
comment|// Use only one event for all listeners of one socket.
comment|// The idea is that listener events are rare, so polling all listeners once in a while is
comment|// cheap compared to waiting for N additional events in each iteration of the main loop.
name|eventHandle
operator|=
name|CreateEvent
argument_list|(
name|NULL
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|connectionEventNotifier
operator|=
operator|new
name|QWinEventNotifier
argument_list|(
name|eventHandle
argument_list|,
name|q
argument_list|)
expr_stmt|;
name|q
operator|->
name|connect
argument_list|(
name|connectionEventNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|HANDLE
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_onNewConnection
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|SYSTEM_MAX_PENDING_SOCKETS
condition|;
operator|++
name|i
control|)
if|if
condition|(
operator|!
name|addListener
argument_list|()
condition|)
return|return
literal|false
return|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|listen
name|bool
name|QLocalServerPrivate
operator|::
name|listen
parameter_list|(
name|qintptr
parameter_list|)
block|{
name|qWarning
argument_list|(
literal|"QLocalServer::listen(qintptr) is not supported on Windows QTBUG-24230"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|_q_onNewConnection
name|void
name|QLocalServerPrivate
operator|::
name|_q_onNewConnection
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
name|DWORD
name|dummy
decl_stmt|;
comment|// Reset first, otherwise we could reset an event which was asserted
comment|// immediately after we checked the conn status.
name|ResetEvent
argument_list|(
name|eventHandle
argument_list|)
expr_stmt|;
comment|// Testing shows that there is indeed absolutely no guarantee which listener gets
comment|// a client connection first, so there is no way around polling all of them.
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|listeners
operator|.
name|size
argument_list|()
condition|;
control|)
block|{
name|HANDLE
name|handle
init|=
name|listeners
index|[
name|i
index|]
operator|.
name|handle
decl_stmt|;
if|if
condition|(
name|listeners
index|[
name|i
index|]
operator|.
name|connected
operator|||
name|GetOverlappedResult
argument_list|(
name|handle
argument_list|,
operator|&
name|listeners
index|[
name|i
index|]
operator|.
name|overlapped
argument_list|,
operator|&
name|dummy
argument_list|,
name|FALSE
argument_list|)
condition|)
block|{
name|listeners
operator|.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|addListener
argument_list|()
expr_stmt|;
if|if
condition|(
name|pendingConnections
operator|.
name|size
argument_list|()
operator|>
name|maxPendingConnections
condition|)
name|connectionEventNotifier
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// Make this the last thing so connected slots can wreak the least havoc
name|q
operator|->
name|incomingConnection
argument_list|(
operator|(
name|quintptr
operator|)
name|handle
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|GetLastError
argument_list|()
operator|!=
name|ERROR_IO_INCOMPLETE
condition|)
block|{
name|q
operator|->
name|close
argument_list|()
expr_stmt|;
name|setError
argument_list|(
name|QLatin1String
argument_list|(
literal|"QLocalServerPrivate::_q_onNewConnection"
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
operator|++
name|i
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|closeServer
name|void
name|QLocalServerPrivate
operator|::
name|closeServer
parameter_list|()
block|{
name|connectionEventNotifier
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|// Otherwise, closed handle is checked before deleter runs
name|connectionEventNotifier
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
name|connectionEventNotifier
operator|=
literal|0
expr_stmt|;
name|CloseHandle
argument_list|(
name|eventHandle
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|listeners
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|CloseHandle
argument_list|(
name|listeners
index|[
name|i
index|]
operator|.
name|handle
argument_list|)
expr_stmt|;
name|listeners
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|waitForNewConnection
name|void
name|QLocalServerPrivate
operator|::
name|waitForNewConnection
parameter_list|(
name|int
name|msecs
parameter_list|,
name|bool
modifier|*
name|timedOut
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pendingConnections
operator|.
name|isEmpty
argument_list|()
operator|||
operator|!
name|q
operator|->
name|isListening
argument_list|()
condition|)
return|return;
name|DWORD
name|result
init|=
name|WaitForSingleObject
argument_list|(
name|eventHandle
argument_list|,
operator|(
name|msecs
operator|==
operator|-
literal|1
operator|)
condition|?
name|INFINITE
else|:
name|msecs
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|WAIT_TIMEOUT
condition|)
block|{
if|if
condition|(
name|timedOut
condition|)
operator|*
name|timedOut
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|_q_onNewConnection
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
