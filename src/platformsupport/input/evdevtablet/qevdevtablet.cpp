begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qevdevtablet_p.h"
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QSocketNotifier>
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qdevicediscovery_p.h>
end_include
begin_include
include|#
directive|include
file|<linux/input.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QEvdevTabletData
class|class
name|QEvdevTabletData
block|{
public|public:
name|QEvdevTabletData
parameter_list|(
name|QEvdevTabletHandler
modifier|*
name|q_ptr
parameter_list|)
constructor_decl|;
name|bool
name|queryLimits
parameter_list|()
function_decl|;
name|void
name|testGrab
parameter_list|()
function_decl|;
name|void
name|processInputEvent
parameter_list|(
name|input_event
modifier|*
name|ev
parameter_list|)
function_decl|;
name|void
name|reportProximityEnter
parameter_list|()
function_decl|;
name|void
name|reportProximityLeave
parameter_list|()
function_decl|;
name|void
name|report
parameter_list|()
function_decl|;
DECL|member|q
name|QEvdevTabletHandler
modifier|*
name|q
decl_stmt|;
DECL|member|notifier
name|QSocketNotifier
modifier|*
name|notifier
decl_stmt|;
DECL|member|fd
name|int
name|fd
decl_stmt|;
DECL|member|lastEventType
name|int
name|lastEventType
decl_stmt|;
DECL|member|devName
name|QString
name|devName
decl_stmt|;
struct|struct
block|{
DECL|member|x
DECL|member|y
DECL|member|p
DECL|member|d
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|p
decl_stmt|,
name|d
decl_stmt|;
DECL|member|minValues
DECL|member|maxValues
block|}
name|minValues
struct|,
name|maxValues
struct|;
struct|struct
block|{
DECL|member|x
DECL|member|y
DECL|member|p
DECL|member|d
name|int
name|x
decl_stmt|,
name|y
decl_stmt|,
name|p
decl_stmt|,
name|d
decl_stmt|;
DECL|member|down
DECL|member|lastReportDown
name|bool
name|down
decl_stmt|,
name|lastReportDown
decl_stmt|;
DECL|member|tool
DECL|member|lastReportTool
name|int
name|tool
decl_stmt|,
name|lastReportTool
decl_stmt|;
DECL|member|lastReportPos
name|QPointF
name|lastReportPos
decl_stmt|;
DECL|member|state
block|}
name|state
struct|;
block|}
class|;
end_class
begin_constructor
DECL|function|QEvdevTabletData
name|QEvdevTabletData
operator|::
name|QEvdevTabletData
parameter_list|(
name|QEvdevTabletHandler
modifier|*
name|q_ptr
parameter_list|)
member_init_list|:
name|q
argument_list|(
name|q_ptr
argument_list|)
member_init_list|,
name|notifier
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|fd
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|lastEventType
argument_list|(
literal|0
argument_list|)
block|{
name|memset
argument_list|(
operator|&
name|minValues
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|minValues
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|maxValues
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|maxValues
argument_list|)
argument_list|)
expr_stmt|;
name|memset
argument_list|(
operator|&
name|state
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|state
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|queryLimits
name|bool
name|QEvdevTabletData
operator|::
name|queryLimits
parameter_list|()
block|{
name|bool
name|ok
init|=
literal|true
decl_stmt|;
name|input_absinfo
name|absInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|absInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|input_absinfo
argument_list|)
argument_list|)
expr_stmt|;
name|ok
operator|&=
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGABS
argument_list|(
name|ABS_X
argument_list|)
argument_list|,
operator|&
name|absInfo
argument_list|)
operator|>=
literal|0
expr_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|minValues
operator|.
name|x
operator|=
name|absInfo
operator|.
name|minimum
expr_stmt|;
name|maxValues
operator|.
name|x
operator|=
name|absInfo
operator|.
name|maximum
expr_stmt|;
name|qDebug
argument_list|(
literal|"evdevtablet: min X: %d max X: %d"
argument_list|,
name|minValues
operator|.
name|x
argument_list|,
name|maxValues
operator|.
name|x
argument_list|)
expr_stmt|;
block|}
name|ok
operator|&=
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGABS
argument_list|(
name|ABS_Y
argument_list|)
argument_list|,
operator|&
name|absInfo
argument_list|)
operator|>=
literal|0
expr_stmt|;
if|if
condition|(
name|ok
condition|)
block|{
name|minValues
operator|.
name|y
operator|=
name|absInfo
operator|.
name|minimum
expr_stmt|;
name|maxValues
operator|.
name|y
operator|=
name|absInfo
operator|.
name|maximum
expr_stmt|;
name|qDebug
argument_list|(
literal|"evdevtablet: min Y: %d max Y: %d"
argument_list|,
name|minValues
operator|.
name|y
argument_list|,
name|maxValues
operator|.
name|y
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGABS
argument_list|(
name|ABS_PRESSURE
argument_list|)
argument_list|,
operator|&
name|absInfo
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|minValues
operator|.
name|p
operator|=
name|absInfo
operator|.
name|minimum
expr_stmt|;
name|maxValues
operator|.
name|p
operator|=
name|absInfo
operator|.
name|maximum
expr_stmt|;
name|qDebug
argument_list|(
literal|"evdevtablet: min pressure: %d max pressure: %d"
argument_list|,
name|minValues
operator|.
name|p
argument_list|,
name|maxValues
operator|.
name|p
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGABS
argument_list|(
name|ABS_DISTANCE
argument_list|)
argument_list|,
operator|&
name|absInfo
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|minValues
operator|.
name|d
operator|=
name|absInfo
operator|.
name|minimum
expr_stmt|;
name|maxValues
operator|.
name|d
operator|=
name|absInfo
operator|.
name|maximum
expr_stmt|;
name|qDebug
argument_list|(
literal|"evdevtablet: min distance: %d max distance: %d"
argument_list|,
name|minValues
operator|.
name|d
argument_list|,
name|maxValues
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|char
name|name
index|[
literal|128
index|]
decl_stmt|;
if|if
condition|(
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGNAME
argument_list|(
sizeof|sizeof
argument_list|(
name|name
argument_list|)
operator|-
literal|1
argument_list|)
argument_list|,
name|name
argument_list|)
operator|>=
literal|0
condition|)
block|{
name|devName
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"evdevtablet: device name: %s"
argument_list|,
name|name
argument_list|)
expr_stmt|;
block|}
return|return
name|ok
return|;
block|}
end_function
begin_function
DECL|function|testGrab
name|void
name|QEvdevTabletData
operator|::
name|testGrab
parameter_list|()
block|{
name|bool
name|grabSuccess
init|=
operator|!
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGRAB
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|grabSuccess
condition|)
name|ioctl
argument_list|(
name|fd
argument_list|,
name|EVIOCGRAB
argument_list|,
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"evdevtablet: ERROR: The device is grabbed by another process. No events will be read."
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|processInputEvent
name|void
name|QEvdevTabletData
operator|::
name|processInputEvent
parameter_list|(
name|input_event
modifier|*
name|ev
parameter_list|)
block|{
if|if
condition|(
name|ev
operator|->
name|type
operator|==
name|EV_ABS
condition|)
block|{
switch|switch
condition|(
name|ev
operator|->
name|code
condition|)
block|{
case|case
name|ABS_X
case|:
name|state
operator|.
name|x
operator|=
name|ev
operator|->
name|value
expr_stmt|;
break|break;
case|case
name|ABS_Y
case|:
name|state
operator|.
name|y
operator|=
name|ev
operator|->
name|value
expr_stmt|;
break|break;
case|case
name|ABS_PRESSURE
case|:
name|state
operator|.
name|p
operator|=
name|ev
operator|->
name|value
expr_stmt|;
break|break;
case|case
name|ABS_DISTANCE
case|:
name|state
operator|.
name|d
operator|=
name|ev
operator|->
name|value
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|ev
operator|->
name|type
operator|==
name|EV_KEY
condition|)
block|{
comment|// code BTN_TOOL_* value 1 -> proximity enter
comment|// code BTN_TOOL_* value 0 -> proximity leave
comment|// code BTN_TOUCH value 1 -> contact with screen
comment|// code BTN_TOUCH value 0 -> no contact
switch|switch
condition|(
name|ev
operator|->
name|code
condition|)
block|{
case|case
name|BTN_TOUCH
case|:
name|state
operator|.
name|down
operator|=
name|ev
operator|->
name|value
operator|!=
literal|0
expr_stmt|;
break|break;
case|case
name|BTN_TOOL_PEN
case|:
name|state
operator|.
name|tool
operator|=
name|ev
operator|->
name|value
condition|?
name|QTabletEvent
operator|::
name|Pen
else|:
literal|0
expr_stmt|;
break|break;
case|case
name|BTN_TOOL_RUBBER
case|:
name|state
operator|.
name|tool
operator|=
name|ev
operator|->
name|value
condition|?
name|QTabletEvent
operator|::
name|Eraser
else|:
literal|0
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
elseif|else
if|if
condition|(
name|ev
operator|->
name|type
operator|==
name|EV_SYN
operator|&&
name|ev
operator|->
name|code
operator|==
name|SYN_REPORT
operator|&&
name|lastEventType
operator|!=
name|ev
operator|->
name|type
condition|)
block|{
name|report
argument_list|()
expr_stmt|;
block|}
name|lastEventType
operator|=
name|ev
operator|->
name|type
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reportProximityEnter
name|void
name|QEvdevTabletData
operator|::
name|reportProximityEnter
parameter_list|()
block|{
name|QWindowSystemInterface
operator|::
name|handleTabletEnterProximityEvent
argument_list|(
name|QTabletEvent
operator|::
name|Stylus
argument_list|,
name|state
operator|.
name|tool
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reportProximityLeave
name|void
name|QEvdevTabletData
operator|::
name|reportProximityLeave
parameter_list|()
block|{
name|QWindowSystemInterface
operator|::
name|handleTabletLeaveProximityEvent
argument_list|(
name|QTabletEvent
operator|::
name|Stylus
argument_list|,
name|state
operator|.
name|tool
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|report
name|void
name|QEvdevTabletData
operator|::
name|report
parameter_list|()
block|{
if|if
condition|(
operator|!
name|state
operator|.
name|lastReportTool
operator|&&
name|state
operator|.
name|tool
condition|)
name|reportProximityEnter
argument_list|()
expr_stmt|;
name|qreal
name|nx
init|=
operator|(
name|state
operator|.
name|x
operator|-
name|minValues
operator|.
name|x
operator|)
operator|/
name|qreal
argument_list|(
name|maxValues
operator|.
name|x
operator|-
name|minValues
operator|.
name|x
argument_list|)
decl_stmt|;
name|qreal
name|ny
init|=
operator|(
name|state
operator|.
name|y
operator|-
name|minValues
operator|.
name|y
operator|)
operator|/
name|qreal
argument_list|(
name|maxValues
operator|.
name|y
operator|-
name|minValues
operator|.
name|y
argument_list|)
decl_stmt|;
name|QRect
name|winRect
init|=
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|QPointF
name|globalPos
argument_list|(
name|nx
operator|*
name|winRect
operator|.
name|width
argument_list|()
argument_list|,
name|ny
operator|*
name|winRect
operator|.
name|height
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|pointer
init|=
name|state
operator|.
name|tool
decl_stmt|;
comment|// Prevent sending confusing values of 0 when moving the pen outside the active area.
if|if
condition|(
operator|!
name|state
operator|.
name|down
operator|&&
name|state
operator|.
name|lastReportDown
condition|)
block|{
name|globalPos
operator|=
name|state
operator|.
name|lastReportPos
expr_stmt|;
name|pointer
operator|=
name|state
operator|.
name|lastReportTool
expr_stmt|;
block|}
name|qreal
name|pressure
init|=
operator|(
name|state
operator|.
name|p
operator|-
name|minValues
operator|.
name|p
operator|)
operator|/
name|qreal
argument_list|(
name|maxValues
operator|.
name|p
operator|-
name|minValues
operator|.
name|p
argument_list|)
decl_stmt|;
if|if
condition|(
name|state
operator|.
name|down
operator|||
name|state
operator|.
name|lastReportDown
condition|)
block|{
name|QWindowSystemInterface
operator|::
name|handleTabletEvent
argument_list|(
literal|0
argument_list|,
name|state
operator|.
name|down
argument_list|,
name|QPointF
argument_list|()
argument_list|,
name|globalPos
argument_list|,
name|QTabletEvent
operator|::
name|Stylus
argument_list|,
name|pointer
argument_list|,
name|pressure
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
literal|1
argument_list|,
name|qGuiApp
operator|->
name|keyboardModifiers
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|state
operator|.
name|lastReportTool
operator|&&
operator|!
name|state
operator|.
name|tool
condition|)
name|reportProximityLeave
argument_list|()
expr_stmt|;
name|state
operator|.
name|lastReportDown
operator|=
name|state
operator|.
name|down
expr_stmt|;
name|state
operator|.
name|lastReportTool
operator|=
name|state
operator|.
name|tool
expr_stmt|;
name|state
operator|.
name|lastReportPos
operator|=
name|globalPos
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QEvdevTabletHandler
name|QEvdevTabletHandler
operator|::
name|QEvdevTabletHandler
parameter_list|(
specifier|const
name|QString
modifier|&
name|spec
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|d
argument_list|(
literal|0
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QLatin1String
argument_list|(
literal|"Evdev Tablet Handler"
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|=
operator|new
name|QEvdevTabletData
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QString
name|dev
decl_stmt|;
name|QStringList
name|args
init|=
name|spec
operator|.
name|split
argument_list|(
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|args
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|startsWith
argument_list|(
name|QLatin1String
argument_list|(
literal|"/dev/"
argument_list|)
argument_list|)
condition|)
block|{
name|dev
operator|=
name|args
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
if|if
condition|(
name|dev
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|QScopedPointer
argument_list|<
name|QDeviceDiscovery
argument_list|>
name|deviceDiscovery
argument_list|(
name|QDeviceDiscovery
operator|::
name|create
argument_list|(
name|QDeviceDiscovery
operator|::
name|Device_Tablet
argument_list|,
name|this
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|deviceDiscovery
condition|)
block|{
name|QStringList
name|devices
init|=
name|deviceDiscovery
operator|->
name|scanConnectedDevices
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|devices
operator|.
name|isEmpty
argument_list|()
condition|)
name|dev
operator|=
name|devices
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|dev
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qDebug
argument_list|(
literal|"evdevtablet: using %s"
argument_list|,
name|qPrintable
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|fd
operator|=
name|QT_OPEN
argument_list|(
name|dev
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
name|O_RDONLY
operator||
name|O_NDELAY
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|fd
operator|>=
literal|0
condition|)
block|{
name|d
operator|->
name|testGrab
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|queryLimits
argument_list|()
condition|)
block|{
name|d
operator|->
name|notifier
operator|=
operator|new
name|QSocketNotifier
argument_list|(
name|d
operator|->
name|fd
argument_list|,
name|QSocketNotifier
operator|::
name|Read
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|notifier
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
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qErrnoWarning
argument_list|(
name|errno
argument_list|,
literal|"evdevtablet: Cannot open input device"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_constructor
begin_destructor
DECL|function|~QEvdevTabletHandler
name|QEvdevTabletHandler
operator|::
name|~
name|QEvdevTabletHandler
parameter_list|()
block|{
operator|delete
name|d
operator|->
name|notifier
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|fd
operator|>=
literal|0
condition|)
name|QT_CLOSE
argument_list|(
name|d
operator|->
name|fd
argument_list|)
expr_stmt|;
operator|delete
name|d
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|readData
name|void
name|QEvdevTabletHandler
operator|::
name|readData
parameter_list|()
block|{
specifier|static
name|input_event
name|buffer
index|[
literal|32
index|]
decl_stmt|;
name|int
name|n
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|int
name|result
init|=
name|QT_READ
argument_list|(
name|d
operator|->
name|fd
argument_list|,
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|buffer
argument_list|)
operator|+
name|n
argument_list|,
sizeof|sizeof
argument_list|(
name|buffer
argument_list|)
operator|-
name|n
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
block|{
name|qWarning
argument_list|(
literal|"evdevtablet: Got EOF from input device"
argument_list|)
expr_stmt|;
return|return;
block|}
elseif|else
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
if|if
condition|(
name|errno
operator|!=
name|EINTR
operator|&&
name|errno
operator|!=
name|EAGAIN
condition|)
block|{
name|qErrnoWarning
argument_list|(
name|errno
argument_list|,
literal|"evdevtablet: Could not read from input device"
argument_list|)
expr_stmt|;
if|if
condition|(
name|errno
operator|==
name|ENODEV
condition|)
block|{
comment|// device got disconnected -> stop reading
operator|delete
name|d
operator|->
name|notifier
expr_stmt|;
name|d
operator|->
name|notifier
operator|=
literal|0
expr_stmt|;
name|QT_CLOSE
argument_list|(
name|d
operator|->
name|fd
argument_list|)
expr_stmt|;
name|d
operator|->
name|fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
return|return;
block|}
block|}
else|else
block|{
name|n
operator|+=
name|result
expr_stmt|;
if|if
condition|(
name|n
operator|%
sizeof|sizeof
argument_list|(
name|input_event
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
block|}
name|n
operator|/=
sizeof|sizeof
argument_list|(
name|input_event
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
name|n
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|processInputEvent
argument_list|(
operator|&
name|buffer
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|QEvdevTabletHandlerThread
name|QEvdevTabletHandlerThread
operator|::
name|QEvdevTabletHandlerThread
parameter_list|(
specifier|const
name|QString
modifier|&
name|spec
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QThread
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_spec
argument_list|(
name|spec
argument_list|)
member_init_list|,
name|m_handler
argument_list|(
literal|0
argument_list|)
block|{
name|start
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEvdevTabletHandlerThread
name|QEvdevTabletHandlerThread
operator|::
name|~
name|QEvdevTabletHandlerThread
parameter_list|()
block|{
name|quit
argument_list|()
expr_stmt|;
name|wait
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|run
name|void
name|QEvdevTabletHandlerThread
operator|::
name|run
parameter_list|()
block|{
name|m_handler
operator|=
operator|new
name|QEvdevTabletHandler
argument_list|(
name|m_spec
argument_list|)
expr_stmt|;
name|exec
argument_list|()
expr_stmt|;
operator|delete
name|m_handler
expr_stmt|;
name|m_handler
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
