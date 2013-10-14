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
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_LOCALSERVER
end_ifndef
begin_comment
comment|/*!     \class QLocalServer     \since 4.4     \inmodule QtNetwork      \brief The QLocalServer class provides a local socket based server.      This class makes it possible to accept incoming local socket     connections.      Call listen() to have the server start listening     for incoming connections on a specified key.  The     newConnection() signal is then emitted each time a client     connects to the server.      Call nextPendingConnection() to accept the pending connection     as a connected QLocalSocket.  The function returns a pointer to a     QLocalSocket that can be used for communicating with the client.      If an error occurs, serverError() returns the type of error, and     errorString() can be called to get a human readable description     of what happened.      When listening for connections, the name which the server is     listening on is available through serverName().      Calling close() makes QLocalServer stop listening for incoming connections.      Although QLocalServer is designed for use with an event loop, it's possible     to use it without one. In that case, you must use waitForNewConnection(),     which blocks until either a connection is available or a timeout expires.      \sa QLocalSocket, QTcpServer */
end_comment
begin_comment
comment|/*!     \enum QLocalServer::SocketOption     \since 5.0      This enum describes the possible options that can be used to create the     socket. This changes the access permissions on platforms (Linux, Windows)     that support access permissions on the socket. Both GroupAccess and OtherAccess     may vary slightly in meanings depending on the platform.      \value NoOptions No access restrictions have been set.     \value UserAccessOption     Access is restricted to the same user as the process that created the socket.     \value GroupAccessOption     Access is restricted to the same group but not the user that created the socket on Linux.     Access is restricted to the primary group of the process on Windows     \value OtherAccessOption     Access is available to everyone but the user and group that created the socket on Linux.     Access is available to everyone on Windows.     \value WorldAccessOption     No access restrictions.      \sa socketOptions */
end_comment
begin_comment
comment|/*!     Create a new local socket server with the given \a parent.      \sa listen()  */
end_comment
begin_constructor
DECL|function|QLocalServer
name|QLocalServer
operator|::
name|QLocalServer
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QLocalServerPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QLocalServer object.  If the server is listening for     connections, it is automatically closed.      Any client QLocalSockets that are still connected must either     disconnect or be reparented before the server is deleted.      \sa close()  */
end_comment
begin_destructor
DECL|function|~QLocalServer
name|QLocalServer
operator|::
name|~
name|QLocalServer
parameter_list|()
block|{
if|if
condition|(
name|isListening
argument_list|()
condition|)
name|close
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \property QLocalServer::socketOptions     \since 5.0      The setSocketOptions method controls how the socket operates.     For example the socket may restrict access to what user ids can     connect to the socket.      These options must be set before listen() is called.      In some cases, such as with Unix domain sockets on Linux, the     access to the socket will be determined by file system permissions,     and are created based on the umask. Setting the access flags will     overide this and will restrict or permit access as specified.      Other Unix-based operating systems, such as Mac OS X, do not     honor file permissions for Unix domain sockets and by default     have WorldAccess and these permission flags will have no effect.      On Windows, UserAccessOption is sufficient to allow a non     elevated process to connect to a local server created by an     elevated process run by the same user. GroupAccessOption     refers to the primary group of the process (see TokenPrimaryGroup     in the Windows documentation). OtherAccessOption refers to     the well known "Everyone" group.      By default none of the flags are set, access permissions     are the platform default.      \sa listen() */
end_comment
begin_function
DECL|function|setSocketOptions
name|void
name|QLocalServer
operator|::
name|setSocketOptions
parameter_list|(
name|SocketOptions
name|options
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
name|d
operator|->
name|socketOptions
operator|=
name|options
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \since 5.0     Returns the socket options set on the socket.      \sa setSocketOptions()  */
end_comment
begin_function
DECL|function|socketOptions
name|QLocalServer
operator|::
name|SocketOptions
name|QLocalServer
operator|::
name|socketOptions
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|socketOptions
return|;
block|}
end_function
begin_comment
comment|/*!     Stop listening for incoming connections.  Existing connections are not     effected, but any new connections will be refused.      \sa isListening(), listen()  */
end_comment
begin_function
DECL|function|close
name|void
name|QLocalServer
operator|::
name|close
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|isListening
argument_list|()
condition|)
return|return;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|pendingConnections
argument_list|)
expr_stmt|;
name|d
operator|->
name|pendingConnections
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|closeServer
argument_list|()
expr_stmt|;
name|d
operator|->
name|serverName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|fullServerName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|errorString
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|error
operator|=
name|QAbstractSocket
operator|::
name|UnknownSocketError
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the human-readable message appropriate to the current error     reported by serverError(). If no suitable string is available, an empty     string is returned.      \sa serverError()  */
end_comment
begin_function
DECL|function|errorString
name|QString
name|QLocalServer
operator|::
name|errorString
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|errorString
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the server has a pending connection; otherwise     returns \c false.      \sa nextPendingConnection(), setMaxPendingConnections()  */
end_comment
begin_function
DECL|function|hasPendingConnections
name|bool
name|QLocalServer
operator|::
name|hasPendingConnections
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
operator|!
operator|(
name|d
operator|->
name|pendingConnections
operator|.
name|isEmpty
argument_list|()
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     This virtual function is called by QLocalServer when a new connection     is available. \a socketDescriptor is the native socket descriptor for     the accepted connection.      The base implementation creates a QLocalSocket, sets the socket descriptor     and then stores the QLocalSocket in an internal list of pending     connections. Finally newConnection() is emitted.      Reimplement this function to alter the server's behavior     when a connection is available.      \sa newConnection(), nextPendingConnection(),     QLocalSocket::setSocketDescriptor()  */
end_comment
begin_function
DECL|function|incomingConnection
name|void
name|QLocalServer
operator|::
name|incomingConnection
parameter_list|(
name|quintptr
name|socketDescriptor
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
name|QLocalSocket
modifier|*
name|socket
init|=
operator|new
name|QLocalSocket
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|socket
operator|->
name|setSocketDescriptor
argument_list|(
name|socketDescriptor
argument_list|)
expr_stmt|;
name|d
operator|->
name|pendingConnections
operator|.
name|enqueue
argument_list|(
name|socket
argument_list|)
expr_stmt|;
emit|emit
name|newConnection
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the server is listening for incoming connections     otherwise false.      \sa listen(), close()  */
end_comment
begin_function
DECL|function|isListening
name|bool
name|QLocalServer
operator|::
name|isListening
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
operator|!
operator|(
name|d
operator|->
name|serverName
operator|.
name|isEmpty
argument_list|()
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Tells the server to listen for incoming connections on \a name.     If the server is currently listening then it will return false.     Return true on success otherwise false.      \a name can be a single name and QLocalServer will determine     the correct platform specific path.  serverName() will return     the name that is passed into listen.      Usually you would just pass in a name like "foo", but on Unix this     could also be a path such as "/tmp/foo" and on Windows this could     be a pipe path such as "\\\\.\\pipe\\foo"      Note:     On Unix if the server crashes without closing listen will fail     with AddressInUseError.  To create a new server the file should be removed.     On Windows two local servers can listen to the same pipe at the same     time, but any connections will go to one of the server.      \sa serverName(), isListening(), close()  */
end_comment
begin_function
DECL|function|listen
name|bool
name|QLocalServer
operator|::
name|listen
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
name|isListening
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QLocalServer::listen() called when already listening"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|d
operator|->
name|error
operator|=
name|QAbstractSocket
operator|::
name|HostNotFoundError
expr_stmt|;
name|QString
name|function
init|=
name|QLatin1String
argument_list|(
literal|"QLocalServer::listen"
argument_list|)
decl_stmt|;
name|d
operator|->
name|errorString
operator|=
name|tr
argument_list|(
literal|"%1: Name error"
argument_list|)
operator|.
name|arg
argument_list|(
name|function
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
operator|!
name|d
operator|->
name|listen
argument_list|(
name|name
argument_list|)
condition|)
block|{
name|d
operator|->
name|serverName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|fullServerName
operator|.
name|clear
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|serverName
operator|=
name|name
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     \since 5.0      Instructs the server to listen for incoming connections on     \a socketDescriptor. The property returns \c false if the server is     currently listening. It returns \c true on success; otherwise,     it returns \c false. The socket must be ready to accept     new connections with no extra platform-specific functions     called. The socket is set into non-blocking mode.      serverName(), fullServerName() may return a string with     a name if this option is supported by the platform;     otherwise, they return an empty QString.      \sa isListening(), close()  */
end_comment
begin_function
DECL|function|listen
name|bool
name|QLocalServer
operator|::
name|listen
parameter_list|(
name|qintptr
name|socketDescriptor
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
name|isListening
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QLocalServer::listen() called when already listening"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|d
operator|->
name|serverName
operator|.
name|clear
argument_list|()
expr_stmt|;
name|d
operator|->
name|fullServerName
operator|.
name|clear
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|listen
argument_list|(
name|socketDescriptor
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the maximum number of pending accepted connections.     The default is 30.      \sa setMaxPendingConnections(), hasPendingConnections()  */
end_comment
begin_function
DECL|function|maxPendingConnections
name|int
name|QLocalServer
operator|::
name|maxPendingConnections
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|maxPendingConnections
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QLocalServer::newConnection()      This signal is emitted every time a new connection is available.      \sa hasPendingConnections(), nextPendingConnection() */
end_comment
begin_comment
comment|/*!     Returns the next pending connection as a connected QLocalSocket object.      The socket is created as a child of the server, which means that it is     automatically deleted when the QLocalServer object is destroyed. It is     still a good idea to delete the object explicitly when you are done with     it, to avoid wasting memory.      0 is returned if this function is called when there are no pending     connections.      \sa hasPendingConnections(), newConnection(), incomingConnection()  */
end_comment
begin_function
DECL|function|nextPendingConnection
name|QLocalSocket
modifier|*
name|QLocalServer
operator|::
name|nextPendingConnection
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pendingConnections
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
literal|0
return|;
name|QLocalSocket
modifier|*
name|nextSocket
init|=
name|d
operator|->
name|pendingConnections
operator|.
name|dequeue
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_LOCALSOCKET_TCP
if|if
condition|(
name|d
operator|->
name|pendingConnections
operator|.
name|size
argument_list|()
operator|<=
name|d
operator|->
name|maxPendingConnections
condition|)
ifndef|#
directive|ifndef
name|Q_OS_WIN
name|d
operator|->
name|socketNotifier
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
else|#
directive|else
name|d
operator|->
name|connectionEventNotifier
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
return|return
name|nextSocket
return|;
block|}
end_function
begin_comment
comment|/*!     \since 4.5      Removes any server instance that might cause a call to listen() to fail     and returns \c true if successful; otherwise returns \c false.     This function is meant to recover from a crash, when the previous server     instance has not been cleaned up.      On Windows, this function does nothing; on Unix, it removes the socket file     given by \a name.      \warning Be careful to avoid removing sockets of running instances. */
end_comment
begin_function
DECL|function|removeServer
name|bool
name|QLocalServer
operator|::
name|removeServer
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
return|return
name|QLocalServerPrivate
operator|::
name|removeServer
argument_list|(
name|name
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the server name if the server is listening for connections;     otherwise returns QString()      \sa listen(), fullServerName()  */
end_comment
begin_function
DECL|function|serverName
name|QString
name|QLocalServer
operator|::
name|serverName
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|serverName
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the full path that the server is listening on.      Note: This is platform specific      \sa listen(), serverName()  */
end_comment
begin_function
DECL|function|fullServerName
name|QString
name|QLocalServer
operator|::
name|fullServerName
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|fullServerName
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the type of error that occurred last or NoError.      \sa errorString()  */
end_comment
begin_function
DECL|function|serverError
name|QAbstractSocket
operator|::
name|SocketError
name|QLocalServer
operator|::
name|serverError
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QLocalServer
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|error
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the maximum number of pending accepted connections to     \a numConnections.  QLocalServer will accept no more than     \a numConnections incoming connections before nextPendingConnection()     is called.      Note: Even though QLocalServer will stop accepting new connections     after it has reached its maximum number of pending connections,     the operating system may still keep them in queue which will result     in clients signaling that it is connected.      \sa maxPendingConnections(), hasPendingConnections()  */
end_comment
begin_function
DECL|function|setMaxPendingConnections
name|void
name|QLocalServer
operator|::
name|setMaxPendingConnections
parameter_list|(
name|int
name|numConnections
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
name|d
operator|->
name|maxPendingConnections
operator|=
name|numConnections
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Waits for at most \a msec milliseconds or until an incoming connection     is available.  Returns \c true if a connection is available; otherwise     returns \c false.  If the operation timed out and \a timedOut is not 0,     *timedOut will be set to true.      This is a blocking function call. Its use is ill-advised in a     single-threaded GUI application, since the whole application will stop     responding until the function returns. waitForNewConnection() is mostly     useful when there is no event loop available.      The non-blocking alternative is to connect to the newConnection() signal.      If msec is -1, this function will not time out.      \sa hasPendingConnections(), nextPendingConnection()  */
end_comment
begin_function
DECL|function|waitForNewConnection
name|bool
name|QLocalServer
operator|::
name|waitForNewConnection
parameter_list|(
name|int
name|msec
parameter_list|,
name|bool
modifier|*
name|timedOut
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QLocalServer
argument_list|)
expr_stmt|;
if|if
condition|(
name|timedOut
condition|)
operator|*
name|timedOut
operator|=
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|isListening
argument_list|()
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|waitForNewConnection
argument_list|(
name|msec
argument_list|,
name|timedOut
argument_list|)
expr_stmt|;
return|return
operator|!
name|d
operator|->
name|pendingConnections
operator|.
name|isEmpty
argument_list|()
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
begin_include
include|#
directive|include
file|"moc_qlocalserver.cpp"
end_include
end_unit
