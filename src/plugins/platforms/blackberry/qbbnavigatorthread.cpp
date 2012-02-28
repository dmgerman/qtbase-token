begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qbbnavigatorthread.h"
end_include
begin_include
include|#
directive|include
file|"qbbscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindowSystemInterface>
end_include
begin_include
include|#
directive|include
file|<QtCore/QByteArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_decl_stmt
DECL|variable|navigatorControlPath
specifier|static
specifier|const
name|char
modifier|*
name|navigatorControlPath
init|=
literal|"/pps/services/navigator/control"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ppsBufferSize
specifier|static
specifier|const
name|int
name|ppsBufferSize
init|=
literal|4096
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QBBNavigatorThread
name|QBBNavigatorThread
operator|::
name|QBBNavigatorThread
parameter_list|(
name|QBBScreen
modifier|&
name|primaryScreen
parameter_list|)
member_init_list|:
name|m_primaryScreen
argument_list|(
name|primaryScreen
argument_list|)
member_init_list|,
name|m_fd
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|m_readNotifier
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QBBNavigatorThread
name|QBBNavigatorThread
operator|::
name|~
name|QBBNavigatorThread
parameter_list|()
block|{
comment|// block until thread terminates
name|shutdown
argument_list|()
expr_stmt|;
operator|delete
name|m_readNotifier
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|run
name|void
name|QBBNavigatorThread
operator|::
name|run
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: navigator thread started"
expr_stmt|;
endif|#
directive|endif
comment|// open connection to navigator
name|errno
operator|=
literal|0
expr_stmt|;
name|m_fd
operator|=
name|open
argument_list|(
name|navigatorControlPath
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_fd
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QBB: failed to open navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
return|return;
block|}
name|m_readNotifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|m_fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|)
expr_stmt|;
comment|// using direct connection to get the slot called in this thread's context
name|connect
argument_list|(
name|m_readNotifier
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|readData
argument_list|()
argument_list|)
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|)
expr_stmt|;
name|exec
argument_list|()
expr_stmt|;
comment|// close connection to navigator
name|close
argument_list|(
name|m_fd
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: navigator thread stopped"
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|shutdown
name|void
name|QBBNavigatorThread
operator|::
name|shutdown
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: navigator thread shutdown begin"
expr_stmt|;
endif|#
directive|endif
comment|// signal thread to terminate
name|quit
argument_list|()
expr_stmt|;
comment|// block until thread terminates
name|wait
argument_list|()
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: navigator thread shutdown end"
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|parsePPS
name|void
name|QBBNavigatorThread
operator|::
name|parsePPS
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|ppsData
parameter_list|,
name|QByteArray
modifier|&
name|msg
parameter_list|,
name|QByteArray
modifier|&
name|dat
parameter_list|,
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: data="
operator|<<
name|ppsData
expr_stmt|;
endif|#
directive|endif
comment|// tokenize pps data into lines
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|lines
init|=
name|ppsData
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|)
decl_stmt|;
comment|// validate pps object
if|if
condition|(
name|lines
operator|.
name|size
argument_list|()
operator|==
literal|0
operator|||
name|lines
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|!=
literal|"@control"
condition|)
block|{
name|qFatal
argument_list|(
literal|"QBB: unrecognized pps object, data=%s"
argument_list|,
name|ppsData
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// parse pps object attributes and extract values
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|lines
operator|.
name|size
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
comment|// tokenize current attribute
specifier|const
name|QByteArray
modifier|&
name|attr
init|=
name|lines
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: attr="
operator|<<
name|attr
expr_stmt|;
endif|#
directive|endif
name|int
name|firstColon
init|=
name|attr
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|)
decl_stmt|;
if|if
condition|(
name|firstColon
operator|==
operator|-
literal|1
condition|)
block|{
comment|// abort - malformed attribute
continue|continue;
block|}
name|int
name|secondColon
init|=
name|attr
operator|.
name|indexOf
argument_list|(
literal|':'
argument_list|,
name|firstColon
operator|+
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|secondColon
operator|==
operator|-
literal|1
condition|)
block|{
comment|// abort - malformed attribute
continue|continue;
block|}
name|QByteArray
name|key
init|=
name|attr
operator|.
name|left
argument_list|(
name|firstColon
argument_list|)
decl_stmt|;
name|QByteArray
name|value
init|=
name|attr
operator|.
name|mid
argument_list|(
name|secondColon
operator|+
literal|1
argument_list|)
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: key="
operator|<<
name|key
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"PPS: val="
operator|<<
name|value
expr_stmt|;
endif|#
directive|endif
comment|// save attribute value
if|if
condition|(
name|key
operator|==
literal|"msg"
condition|)
block|{
name|msg
operator|=
name|value
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|key
operator|==
literal|"dat"
condition|)
block|{
name|dat
operator|=
name|value
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|key
operator|==
literal|"id"
condition|)
block|{
name|id
operator|=
name|value
expr_stmt|;
block|}
else|else
block|{
name|qFatal
argument_list|(
literal|"QBB: unrecognized pps attribute, attr=%s"
argument_list|,
name|key
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|replyPPS
name|void
name|QBBNavigatorThread
operator|::
name|replyPPS
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|res
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|dat
parameter_list|)
block|{
comment|// construct pps message
name|QByteArray
name|ppsData
init|=
literal|"res::"
decl_stmt|;
name|ppsData
operator|+=
name|res
expr_stmt|;
name|ppsData
operator|+=
literal|"\nid::"
expr_stmt|;
name|ppsData
operator|+=
name|id
expr_stmt|;
if|if
condition|(
operator|!
name|dat
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|ppsData
operator|+=
literal|"\ndat::"
expr_stmt|;
name|ppsData
operator|+=
name|dat
expr_stmt|;
block|}
name|ppsData
operator|+=
literal|"\n"
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS reply="
operator|<<
name|ppsData
expr_stmt|;
endif|#
directive|endif
comment|// send pps message to navigator
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|bytes
init|=
name|write
argument_list|(
name|m_fd
argument_list|,
name|ppsData
operator|.
name|constData
argument_list|()
argument_list|,
name|ppsData
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|bytes
operator|==
operator|-
literal|1
condition|)
block|{
name|qFatal
argument_list|(
literal|"QBB: failed to write navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|handleMessage
name|void
name|QBBNavigatorThread
operator|::
name|handleMessage
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|msg
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|dat
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: msg="
operator|<<
name|msg
operator|<<
literal|", dat="
operator|<<
name|dat
operator|<<
literal|", id="
operator|<<
name|id
expr_stmt|;
endif|#
directive|endif
comment|// check message type
if|if
condition|(
name|msg
operator|==
literal|"orientationCheck"
condition|)
block|{
comment|// reply to navigator that (any) orientation is acceptable
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: orientation check, o="
operator|<<
name|dat
expr_stmt|;
endif|#
directive|endif
name|replyPPS
argument_list|(
name|msg
argument_list|,
name|id
argument_list|,
literal|"true"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"orientation"
condition|)
block|{
comment|// update screen geometry and reply to navigator that we're ready
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: orientation, o="
operator|<<
name|dat
expr_stmt|;
endif|#
directive|endif
name|m_primaryScreen
operator|.
name|setRotation
argument_list|(
name|dat
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleScreenGeometryChange
argument_list|(
literal|0
argument_list|,
name|m_primaryScreen
operator|.
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|replyPPS
argument_list|(
name|msg
argument_list|,
name|id
argument_list|,
literal|""
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"SWIPE_DOWN"
condition|)
block|{
comment|// simulate menu key press
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: menu"
expr_stmt|;
endif|#
directive|endif
name|QWindow
modifier|*
name|w
init|=
name|QGuiApplication
operator|::
name|focusWindow
argument_list|()
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
name|w
argument_list|,
name|QEvent
operator|::
name|KeyPress
argument_list|,
name|Qt
operator|::
name|Key_Menu
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleKeyEvent
argument_list|(
name|w
argument_list|,
name|QEvent
operator|::
name|KeyRelease
argument_list|,
name|Qt
operator|::
name|Key_Menu
argument_list|,
name|Qt
operator|::
name|NoModifier
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|msg
operator|==
literal|"exit"
condition|)
block|{
comment|// shutdown everything
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"PPS: exit"
expr_stmt|;
endif|#
directive|endif
name|QCoreApplication
operator|::
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|readData
name|void
name|QBBNavigatorThread
operator|::
name|readData
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QBBNAVIGATORTHREAD_DEBUG
argument_list|)
name|qDebug
argument_list|()
operator|<<
literal|"QBB: reading navigator data"
expr_stmt|;
endif|#
directive|endif
comment|// allocate buffer for pps data
name|char
name|buffer
index|[
name|ppsBufferSize
index|]
decl_stmt|;
comment|// attempt to read pps data
name|errno
operator|=
literal|0
expr_stmt|;
name|int
name|bytes
init|=
name|read
argument_list|(
name|m_fd
argument_list|,
name|buffer
argument_list|,
name|ppsBufferSize
operator|-
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|bytes
operator|==
operator|-
literal|1
condition|)
block|{
name|qFatal
argument_list|(
literal|"QBB: failed to read navigator pps, errno=%d"
argument_list|,
name|errno
argument_list|)
expr_stmt|;
block|}
comment|// check if pps data was received
if|if
condition|(
name|bytes
operator|>
literal|0
condition|)
block|{
comment|// ensure data is null terminated
name|buffer
index|[
name|bytes
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|// process received message
name|QByteArray
name|ppsData
argument_list|(
name|buffer
argument_list|)
decl_stmt|;
name|QByteArray
name|msg
decl_stmt|;
name|QByteArray
name|dat
decl_stmt|;
name|QByteArray
name|id
decl_stmt|;
name|parsePPS
argument_list|(
name|ppsData
argument_list|,
name|msg
argument_list|,
name|dat
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|handleMessage
argument_list|(
name|msg
argument_list|,
name|dat
argument_list|,
name|id
argument_list|)
expr_stmt|;
block|}
block|}
end_function
end_unit
