begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSYSTEM_QWS_P_H
end_ifndef
begin_define
DECL|macro|QWINDOWSYSTEM_QWS_P_H
define|#
directive|define
name|QWINDOWSYSTEM_QWS_P_H
end_define
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QWSServer class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsystem_qws.h"
end_include
begin_include
include|#
directive|include
file|"qbrush.h"
end_include
begin_include
include|#
directive|include
file|"qwsproperty_qws.h"
end_include
begin_include
include|#
directive|include
file|"qwscommand_qws_p.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qbasictimer.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QWSServerPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|friend
name|class
name|QCopChannel
block|;
name|friend
name|class
name|QWSMouseHandler
block|;
name|friend
name|class
name|QWSWindow
block|;
name|friend
name|class
name|QWSDisplay
block|;
name|friend
name|class
name|QWSInputMethod
block|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QWSServer
argument_list|)
name|public
operator|:
name|QWSServerPrivate
argument_list|()
operator|:
name|screensaverintervals
argument_list|(
literal|0
argument_list|)
block|,
name|screensavereventblocklevel
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|screensaverblockevents
argument_list|(
name|false
argument_list|)
block|,
name|saver
argument_list|(
literal|0
argument_list|)
block|,
name|cursorClient
argument_list|(
literal|0
argument_list|)
block|,
name|mouseState
argument_list|(
literal|0
argument_list|)
block|,
name|nReserved
argument_list|(
literal|0
argument_list|)
block|,
name|doClientIsActive
argument_list|(
argument|false
argument_list|)
block|{     }
operator|~
name|QWSServerPrivate
argument_list|()
block|{
name|closeDisplay
argument_list|()
block|;
name|qDeleteAll
argument_list|(
name|deletedWindows
argument_list|)
block|;
name|delete
index|[]
name|screensaverintervals
block|;
name|delete
name|saver
block|;
name|qDeleteAll
argument_list|(
name|windows
argument_list|)
block|;
name|windows
operator|.
name|clear
argument_list|()
block|;
name|delete
name|bgBrush
block|;
name|bgBrush
operator|=
literal|0
block|;     }
name|QTime
name|screensavertime
block|;
name|QTimer
operator|*
name|screensavertimer
block|;
name|int
operator|*
name|screensaverintervals
block|;
name|int
name|screensavereventblocklevel
block|;
name|bool
name|screensaverblockevents
block|;
name|bool
name|screensaverblockevent
argument_list|(
argument|int index
argument_list|,
argument|int *screensaverinterval
argument_list|,
argument|bool isDown
argument_list|)
block|;
name|QWSScreenSaver
operator|*
name|saver
block|;
name|QWSClient
operator|*
name|cursorClient
block|;
name|int
name|mouseState
block|;
comment|//    bool prevWin;
name|QList
operator|<
name|QWSWindow
operator|*
operator|>
name|deletedWindows
block|;
name|QList
operator|<
name|int
operator|>
name|crashedClientIds
block|;
name|void
name|update_regions
argument_list|()
block|;
comment|//private functions moved from class
name|private
operator|:
name|void
name|initServer
argument_list|(
argument|int flags
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_COP
specifier|static
name|void
name|sendQCopEvent
argument_list|(
argument|QWSClient *c
argument_list|,
argument|const QString&ch
argument_list|,
argument|const QString&msg
argument_list|,
argument|const QByteArray&data
argument_list|,
argument|bool response = false
argument_list|)
block|;
endif|#
directive|endif
name|void
name|move_region
argument_list|(
specifier|const
name|QWSRegionMoveCommand
operator|*
argument_list|)
block|;
name|void
name|set_altitude
argument_list|(
specifier|const
name|QWSChangeAltitudeCommand
operator|*
argument_list|)
block|;
name|void
name|set_opacity
argument_list|(
specifier|const
name|QWSSetOpacityCommand
operator|*
argument_list|)
block|;
name|void
name|request_focus
argument_list|(
specifier|const
name|QWSRequestFocusCommand
operator|*
argument_list|)
block|;
name|QRegion
name|reserve_region
argument_list|(
name|QWSWindow
operator|*
name|window
argument_list|,
specifier|const
name|QRegion
operator|&
name|region
argument_list|)
block|;
name|void
name|request_region
argument_list|(
argument|int winId
argument_list|,
argument|const QString&surfaceKey
argument_list|,
argument|const QByteArray&surfaceData
argument_list|,
argument|const QRegion&region
argument_list|)
block|;
name|void
name|repaint_region
argument_list|(
argument|int winId
argument_list|,
argument|int windowFlags
argument_list|,
argument|bool opaque
argument_list|,
argument|const QRegion&
argument_list|)
block|;
name|void
name|destroy_region
argument_list|(
specifier|const
name|QWSRegionDestroyCommand
operator|*
argument_list|)
block|;
name|void
name|name_region
argument_list|(
specifier|const
name|QWSRegionNameCommand
operator|*
argument_list|)
block|;
name|void
name|set_identity
argument_list|(
specifier|const
name|QWSIdentifyCommand
operator|*
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_PROPERTIES
name|bool
name|get_property
argument_list|(
argument|int winId
argument_list|,
argument|int property
argument_list|,
argument|const char *&data
argument_list|,
argument|int&len
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
name|void
name|im_response
argument_list|(
specifier|const
name|QWSIMResponseCommand
operator|*
argument_list|)
block|;
name|void
name|im_update
argument_list|(
specifier|const
name|QWSIMUpdateCommand
operator|*
argument_list|)
block|;
name|void
name|send_im_mouse
argument_list|(
specifier|const
name|QWSIMMouseCommand
operator|*
argument_list|)
block|;
endif|#
directive|endif
comment|// not in ifndef as this results in more readable functions.
specifier|static
name|void
name|sendKeyEventUnfiltered
argument_list|(
argument|int unicode
argument_list|,
argument|int keycode
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|bool isPress
argument_list|,
argument|bool autoRepeat
argument_list|)
block|;
specifier|static
name|void
name|sendMouseEventUnfiltered
argument_list|(
argument|const QPoint&pos
argument_list|,
argument|int state
argument_list|,
argument|int wheel =
literal|0
argument_list|)
block|;
specifier|static
name|void
name|emergency_cleanup
argument_list|()
block|;
specifier|static
name|QBrush
operator|*
name|bgBrush
block|;
name|void
name|sendMaxWindowRectEvents
argument_list|(
specifier|const
name|QRect
operator|&
name|rect
argument_list|)
block|;
name|void
name|invokeIdentify
argument_list|(
specifier|const
name|QWSIdentifyCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeCreate
argument_list|(
name|QWSCreateCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeRegionName
argument_list|(
specifier|const
name|QWSRegionNameCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeRegion
argument_list|(
name|QWSRegionCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeRegionMove
argument_list|(
specifier|const
name|QWSRegionMoveCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeRegionDestroy
argument_list|(
specifier|const
name|QWSRegionDestroyCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeSetAltitude
argument_list|(
specifier|const
name|QWSChangeAltitudeCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeSetOpacity
argument_list|(
specifier|const
name|QWSSetOpacityCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_PROPERTIES
name|void
name|invokeAddProperty
argument_list|(
name|QWSAddPropertyCommand
operator|*
name|cmd
argument_list|)
block|;
name|void
name|invokeSetProperty
argument_list|(
name|QWSSetPropertyCommand
operator|*
name|cmd
argument_list|)
block|;
name|void
name|invokeRemoveProperty
argument_list|(
name|QWSRemovePropertyCommand
operator|*
name|cmd
argument_list|)
block|;
name|void
name|invokeGetProperty
argument_list|(
name|QWSGetPropertyCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
endif|#
directive|endif
comment|//QT_NO_QWS_PROPERTIES
name|void
name|invokeSetSelectionOwner
argument_list|(
name|QWSSetSelectionOwnerCommand
operator|*
name|cmd
argument_list|)
block|;
name|void
name|invokeConvertSelection
argument_list|(
name|QWSConvertSelectionCommand
operator|*
name|cmd
argument_list|)
block|;
name|void
name|invokeSetFocus
argument_list|(
specifier|const
name|QWSRequestFocusCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|initIO
argument_list|()
block|;
name|void
name|setFocus
argument_list|(
argument|QWSWindow*
argument_list|,
argument|bool gain
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
name|void
name|invokeDefineCursor
argument_list|(
name|QWSDefineCursorCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeSelectCursor
argument_list|(
name|QWSSelectCursorCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokePositionCursor
argument_list|(
name|QWSPositionCursorCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
endif|#
directive|endif
name|void
name|invokeGrabMouse
argument_list|(
name|QWSGrabMouseCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeGrabKeyboard
argument_list|(
name|QWSGrabKeyboardCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_SOUND
name|void
name|invokePlaySound
argument_list|(
name|QWSPlaySoundCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_COP
name|void
name|invokeRegisterChannel
argument_list|(
name|QWSQCopRegisterChannelCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeQCopSend
argument_list|(
name|QWSQCopSendCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
endif|#
directive|endif
name|void
name|invokeRepaintRegion
argument_list|(
name|QWSRepaintRegionCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWSEMBEDWIDGET
name|void
name|invokeEmbed
argument_list|(
name|QWSEmbedCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_QWS_INPUTMETHODS
name|void
name|invokeIMResponse
argument_list|(
specifier|const
name|QWSIMResponseCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeIMUpdate
argument_list|(
specifier|const
name|QWSIMUpdateCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
endif|#
directive|endif
name|void
name|invokeFont
argument_list|(
specifier|const
name|QWSFontCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|void
name|invokeScreenTransform
argument_list|(
specifier|const
name|QWSScreenTransformCommand
operator|*
name|cmd
argument_list|,
name|QWSClient
operator|*
name|client
argument_list|)
block|;
name|QWSMouseHandler
operator|*
name|newMouseHandler
argument_list|(
specifier|const
name|QString
operator|&
name|spec
argument_list|)
block|;
name|void
name|openDisplay
argument_list|()
block|;
name|void
name|closeDisplay
argument_list|()
block|;
name|void
name|showCursor
argument_list|()
block|;
name|void
name|hideCursor
argument_list|()
block|;
name|void
name|initializeCursor
argument_list|()
block|;
name|void
name|resetEngine
argument_list|()
block|;
comment|//private Q_SLOTS:
ifndef|#
directive|ifndef
name|QT_NO_QWS_MULTIPROCESS
name|void
name|_q_clientClosed
argument_list|()
block|;
name|void
name|_q_doClient
argument_list|()
block|;
name|void
name|_q_deleteWindowsLater
argument_list|()
block|;
endif|#
directive|endif
name|void
name|_q_screenSaverWake
argument_list|()
block|;
name|void
name|_q_screenSaverSleep
argument_list|()
block|;
name|void
name|_q_screenSaverTimeout
argument_list|()
block|;
ifndef|#
directive|ifndef
name|QT_NO_QWS_MULTIPROCESS
name|void
name|_q_newConnection
argument_list|()
block|;
endif|#
directive|endif
comment|//other private moved from class
name|void
name|disconnectClient
argument_list|(
name|QWSClient
operator|*
argument_list|)
block|;
name|void
name|screenSave
argument_list|(
argument|int level
argument_list|)
block|;
name|void
name|doClient
argument_list|(
name|QWSClient
operator|*
argument_list|)
block|;
typedef|typedef
name|QMap
operator|<
name|int
operator|,
name|QWSClient
operator|*
operator|>
operator|::
name|Iterator
name|ClientIterator
expr_stmt|;
end_decl_stmt
begin_typedef
typedef|typedef
name|QMap
operator|<
name|int
operator|,
name|QWSClient
operator|*
operator|>
name|ClientMap
expr_stmt|;
end_typedef
begin_function_decl
name|void
name|handleWindowClose
parameter_list|(
name|QWSWindow
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|releaseMouse
parameter_list|(
name|QWSWindow
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|releaseKeyboard
parameter_list|(
name|QWSWindow
modifier|*
name|w
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|updateClientCursorPos
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|uchar
modifier|*
name|sharedram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|ramlen
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ClientMap
name|clientMap
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_PROPERTIES
end_ifndef
begin_decl_stmt
name|QWSPropertyManager
name|propertyManager
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_struct
struct|struct
name|SelectionOwner
block|{
name|int
name|windowid
decl_stmt|;
struct|struct
name|Time
block|{
name|void
name|set
parameter_list|(
name|int
name|h
parameter_list|,
name|int
name|m
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|s2
parameter_list|)
block|{
name|hour
operator|=
name|h
expr_stmt|;
name|minute
operator|=
name|m
expr_stmt|;
name|sec
operator|=
name|s
expr_stmt|;
name|ms
operator|=
name|s2
expr_stmt|;
block|}
name|int
name|hour
decl_stmt|,
name|minute
decl_stmt|,
name|sec
decl_stmt|,
name|ms
decl_stmt|;
block|}
name|time
struct|;
block|}
name|selectionOwner
struct|;
end_struct
begin_decl_stmt
name|QTime
name|timer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
modifier|*
name|screensaverinterval
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWSWindow
modifier|*
name|focusw
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWSWindow
modifier|*
name|mouseGrabber
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|mouseGrabbing
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|inputMethodMouseGrabbed
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|swidth
decl_stmt|,
name|sheight
decl_stmt|,
name|sdepth
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_CURSOR
end_ifndef
begin_decl_stmt
name|bool
name|haveviscurs
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QWSCursor
modifier|*
name|cursor
decl_stmt|;
end_decl_stmt
begin_comment
comment|// cursor currently shown
end_comment
begin_decl_stmt
name|QWSCursor
modifier|*
name|nextCursor
decl_stmt|;
end_decl_stmt
begin_comment
comment|// cursor to show once grabbing is off
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|bool
name|disablePainting
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QWSMouseHandler
operator|*
operator|>
name|mousehandlers
expr_stmt|;
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_KEYBOARD
end_ifndef
begin_expr_stmt
name|QList
operator|<
name|QWSKeyboardHandler
operator|*
operator|>
name|keyboardhandlers
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QList
operator|<
name|QWSCommandStruct
operator|*
operator|>
name|commandQueue
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Window management
end_comment
begin_expr_stmt
name|QList
operator|<
name|QWSWindow
operator|*
operator|>
name|windows
expr_stmt|;
end_expr_stmt
begin_comment
comment|// first=topmost
end_comment
begin_decl_stmt
name|int
name|nReserved
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QWSWindow
modifier|*
name|newWindow
parameter_list|(
name|int
name|id
parameter_list|,
name|QWSClient
modifier|*
name|client
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QWSWindow
modifier|*
name|findWindow
parameter_list|(
name|int
name|windowid
parameter_list|,
name|QWSClient
modifier|*
name|client
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|moveWindowRegion
parameter_list|(
name|QWSWindow
modifier|*
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setWindowRegion
parameter_list|(
name|QWSWindow
modifier|*
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|r
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|raiseWindow
parameter_list|(
name|QWSWindow
modifier|*
parameter_list|,
name|int
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|lowerWindow
parameter_list|(
name|QWSWindow
modifier|*
parameter_list|,
name|int
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|exposeRegion
parameter_list|(
specifier|const
name|QRegion
modifier|&
parameter_list|,
name|int
name|index
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setCursor
parameter_list|(
name|QWSCursor
modifier|*
name|curs
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|// multimedia
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SOUND
end_ifndef
begin_decl_stmt
name|QWSSoundServer
modifier|*
name|soundserver
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_COP
end_ifndef
begin_expr_stmt
name|QMap
operator|<
name|QString
operator|,
name|QList
operator|<
name|QWSClient
operator|*
operator|>
expr|>
name|channels
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QWS_MULTIPROCESS
end_ifndef
begin_decl_stmt
name|QWSServerSocket
modifier|*
name|ssocket
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// filename -> refcount
end_comment
begin_expr_stmt
name|QMap
operator|<
name|QByteArray
operator|,
name|int
operator|>
name|fontReferenceCount
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QBasicTimer
name|fontCleanupTimer
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|referenceFont
parameter_list|(
name|QWSClientPrivate
modifier|*
name|client
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|dereferenceFont
parameter_list|(
name|QWSClientPrivate
modifier|*
name|client
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|cleanupFonts
parameter_list|(
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|sendFontRemovedEvent
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|font
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|bool
name|doClientIsActive
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QList
operator|<
name|QWSClient
operator|*
operator|>
name|pendingDoClients
expr_stmt|;
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
