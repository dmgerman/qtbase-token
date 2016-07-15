begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOREEVENT_H
end_ifndef
begin_define
DECL|macro|QCOREEVENT_H
define|#
directive|define
name|QCOREEVENT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEventPrivate
name|class
name|QEventPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QEvent
comment|// event base class
block|{
name|Q_GADGET
name|QDOC_PROPERTY
argument_list|(
name|bool
name|accepted
name|READ
name|isAccepted
name|WRITE
name|setAccepted
argument_list|)
name|public
range|:     enum
name|Type
block|{
comment|/*           If you get a strange compiler error on the line with None,           it's probably because you're also including X11 headers,           which #define the symbol None. Put the X11 includes after           the Qt includes to solve this problem.         */
name|None
operator|=
literal|0
block|,
comment|// invalid event
name|Timer
operator|=
literal|1
block|,
comment|// timer event
name|MouseButtonPress
operator|=
literal|2
block|,
comment|// mouse button pressed
name|MouseButtonRelease
operator|=
literal|3
block|,
comment|// mouse button released
name|MouseButtonDblClick
operator|=
literal|4
block|,
comment|// mouse button double click
name|MouseMove
operator|=
literal|5
block|,
comment|// mouse move
name|KeyPress
operator|=
literal|6
block|,
comment|// key pressed
name|KeyRelease
operator|=
literal|7
block|,
comment|// key released
name|FocusIn
operator|=
literal|8
block|,
comment|// keyboard focus received
name|FocusOut
operator|=
literal|9
block|,
comment|// keyboard focus lost
name|FocusAboutToChange
operator|=
literal|23
block|,
comment|// keyboard focus is about to be lost
name|Enter
operator|=
literal|10
block|,
comment|// mouse enters widget
name|Leave
operator|=
literal|11
block|,
comment|// mouse leaves widget
name|Paint
operator|=
literal|12
block|,
comment|// paint widget
name|Move
operator|=
literal|13
block|,
comment|// move widget
name|Resize
operator|=
literal|14
block|,
comment|// resize widget
name|Create
operator|=
literal|15
block|,
comment|// after widget creation
name|Destroy
operator|=
literal|16
block|,
comment|// during widget destruction
name|Show
operator|=
literal|17
block|,
comment|// widget is shown
name|Hide
operator|=
literal|18
block|,
comment|// widget is hidden
name|Close
operator|=
literal|19
block|,
comment|// request to close widget
name|Quit
operator|=
literal|20
block|,
comment|// request to quit application
name|ParentChange
operator|=
literal|21
block|,
comment|// widget has been reparented
name|ParentAboutToChange
operator|=
literal|131
block|,
comment|// sent just before the parent change is done
name|ThreadChange
operator|=
literal|22
block|,
comment|// object has changed threads
name|WindowActivate
operator|=
literal|24
block|,
comment|// window was activated
name|WindowDeactivate
operator|=
literal|25
block|,
comment|// window was deactivated
name|ShowToParent
operator|=
literal|26
block|,
comment|// widget is shown to parent
name|HideToParent
operator|=
literal|27
block|,
comment|// widget is hidden to parent
name|Wheel
operator|=
literal|31
block|,
comment|// wheel event
name|WindowTitleChange
operator|=
literal|33
block|,
comment|// window title changed
name|WindowIconChange
operator|=
literal|34
block|,
comment|// icon changed
name|ApplicationWindowIconChange
operator|=
literal|35
block|,
comment|// application icon changed
name|ApplicationFontChange
operator|=
literal|36
block|,
comment|// application font changed
name|ApplicationLayoutDirectionChange
operator|=
literal|37
block|,
comment|// application layout direction changed
name|ApplicationPaletteChange
operator|=
literal|38
block|,
comment|// application palette changed
name|PaletteChange
operator|=
literal|39
block|,
comment|// widget palette changed
name|Clipboard
operator|=
literal|40
block|,
comment|// internal clipboard event
name|Speech
operator|=
literal|42
block|,
comment|// reserved for speech input
name|MetaCall
operator|=
literal|43
block|,
comment|// meta call event
name|SockAct
operator|=
literal|50
block|,
comment|// socket activation
name|WinEventAct
operator|=
literal|132
block|,
comment|// win event activation
name|DeferredDelete
operator|=
literal|52
block|,
comment|// deferred delete event
name|DragEnter
operator|=
literal|60
block|,
comment|// drag moves into widget
name|DragMove
operator|=
literal|61
block|,
comment|// drag moves in widget
name|DragLeave
operator|=
literal|62
block|,
comment|// drag leaves or is cancelled
name|Drop
operator|=
literal|63
block|,
comment|// actual drop
name|DragResponse
operator|=
literal|64
block|,
comment|// drag accepted/rejected
name|ChildAdded
operator|=
literal|68
block|,
comment|// new child widget
name|ChildPolished
operator|=
literal|69
block|,
comment|// polished child widget
name|ChildRemoved
operator|=
literal|71
block|,
comment|// deleted child widget
name|ShowWindowRequest
operator|=
literal|73
block|,
comment|// widget's window should be mapped
name|PolishRequest
operator|=
literal|74
block|,
comment|// widget should be polished
name|Polish
operator|=
literal|75
block|,
comment|// widget is polished
name|LayoutRequest
operator|=
literal|76
block|,
comment|// widget should be relayouted
name|UpdateRequest
operator|=
literal|77
block|,
comment|// widget should be repainted
name|UpdateLater
operator|=
literal|78
block|,
comment|// request update() later
name|EmbeddingControl
operator|=
literal|79
block|,
comment|// ActiveX embedding
name|ActivateControl
operator|=
literal|80
block|,
comment|// ActiveX activation
name|DeactivateControl
operator|=
literal|81
block|,
comment|// ActiveX deactivation
name|ContextMenu
operator|=
literal|82
block|,
comment|// context popup menu
name|InputMethod
operator|=
literal|83
block|,
comment|// input method
name|TabletMove
operator|=
literal|87
block|,
comment|// Wacom tablet event
name|LocaleChange
operator|=
literal|88
block|,
comment|// the system locale changed
name|LanguageChange
operator|=
literal|89
block|,
comment|// the application language changed
name|LayoutDirectionChange
operator|=
literal|90
block|,
comment|// the layout direction changed
name|Style
operator|=
literal|91
block|,
comment|// internal style event
name|TabletPress
operator|=
literal|92
block|,
comment|// tablet press
name|TabletRelease
operator|=
literal|93
block|,
comment|// tablet release
name|OkRequest
operator|=
literal|94
block|,
comment|// CE (Ok) button pressed
name|HelpRequest
operator|=
literal|95
block|,
comment|// CE (?)  button pressed
name|IconDrag
operator|=
literal|96
block|,
comment|// proxy icon dragged
name|FontChange
operator|=
literal|97
block|,
comment|// font has changed
name|EnabledChange
operator|=
literal|98
block|,
comment|// enabled state has changed
name|ActivationChange
operator|=
literal|99
block|,
comment|// window activation has changed
name|StyleChange
operator|=
literal|100
block|,
comment|// style has changed
name|IconTextChange
operator|=
literal|101
block|,
comment|// icon text has changed.  Deprecated.
name|ModifiedChange
operator|=
literal|102
block|,
comment|// modified state has changed
name|MouseTrackingChange
operator|=
literal|109
block|,
comment|// mouse tracking state has changed
name|WindowBlocked
operator|=
literal|103
block|,
comment|// window is about to be blocked modally
name|WindowUnblocked
operator|=
literal|104
block|,
comment|// windows modal blocking has ended
name|WindowStateChange
operator|=
literal|105
block|,
name|ReadOnlyChange
operator|=
literal|106
block|,
comment|// readonly state has changed
name|ToolTip
operator|=
literal|110
block|,
name|WhatsThis
operator|=
literal|111
block|,
name|StatusTip
operator|=
literal|112
block|,
name|ActionChanged
operator|=
literal|113
block|,
name|ActionAdded
operator|=
literal|114
block|,
name|ActionRemoved
operator|=
literal|115
block|,
name|FileOpen
operator|=
literal|116
block|,
comment|// file open request
name|Shortcut
operator|=
literal|117
block|,
comment|// shortcut triggered
name|ShortcutOverride
operator|=
literal|51
block|,
comment|// shortcut override request
name|WhatsThisClicked
operator|=
literal|118
block|,
name|ToolBarChange
operator|=
literal|120
block|,
comment|// toolbar visibility toggled
name|ApplicationActivate
operator|=
literal|121
block|,
comment|// deprecated. Use ApplicationStateChange instead.
name|ApplicationActivated
operator|=
name|ApplicationActivate
block|,
comment|// deprecated
name|ApplicationDeactivate
operator|=
literal|122
block|,
comment|// deprecated. Use ApplicationStateChange instead.
name|ApplicationDeactivated
operator|=
name|ApplicationDeactivate
block|,
comment|// deprecated
name|QueryWhatsThis
operator|=
literal|123
block|,
comment|// query what's this widget help
name|EnterWhatsThisMode
operator|=
literal|124
block|,
name|LeaveWhatsThisMode
operator|=
literal|125
block|,
name|ZOrderChange
operator|=
literal|126
block|,
comment|// child widget has had its z-order changed
name|HoverEnter
operator|=
literal|127
block|,
comment|// mouse cursor enters a hover widget
name|HoverLeave
operator|=
literal|128
block|,
comment|// mouse cursor leaves a hover widget
name|HoverMove
operator|=
literal|129
block|,
comment|// mouse cursor move inside a hover widget
comment|// last event id used = 132
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|EnterEditFocus
operator|=
literal|150
block|,
comment|// enter edit mode in keypad navigation
name|LeaveEditFocus
operator|=
literal|151
block|,
comment|// enter edit mode in keypad navigation
endif|#
directive|endif
name|AcceptDropsChange
operator|=
literal|152
block|,
name|ZeroTimerEvent
operator|=
literal|154
block|,
comment|// Used for Windows Zero timer events
name|GraphicsSceneMouseMove
operator|=
literal|155
block|,
comment|// GraphicsView
name|GraphicsSceneMousePress
operator|=
literal|156
block|,
name|GraphicsSceneMouseRelease
operator|=
literal|157
block|,
name|GraphicsSceneMouseDoubleClick
operator|=
literal|158
block|,
name|GraphicsSceneContextMenu
operator|=
literal|159
block|,
name|GraphicsSceneHoverEnter
operator|=
literal|160
block|,
name|GraphicsSceneHoverMove
operator|=
literal|161
block|,
name|GraphicsSceneHoverLeave
operator|=
literal|162
block|,
name|GraphicsSceneHelp
operator|=
literal|163
block|,
name|GraphicsSceneDragEnter
operator|=
literal|164
block|,
name|GraphicsSceneDragMove
operator|=
literal|165
block|,
name|GraphicsSceneDragLeave
operator|=
literal|166
block|,
name|GraphicsSceneDrop
operator|=
literal|167
block|,
name|GraphicsSceneWheel
operator|=
literal|168
block|,
name|KeyboardLayoutChange
operator|=
literal|169
block|,
comment|// keyboard layout changed
name|DynamicPropertyChange
operator|=
literal|170
block|,
comment|// A dynamic property was changed through setProperty/property
name|TabletEnterProximity
operator|=
literal|171
block|,
name|TabletLeaveProximity
operator|=
literal|172
block|,
name|NonClientAreaMouseMove
operator|=
literal|173
block|,
name|NonClientAreaMouseButtonPress
operator|=
literal|174
block|,
name|NonClientAreaMouseButtonRelease
operator|=
literal|175
block|,
name|NonClientAreaMouseButtonDblClick
operator|=
literal|176
block|,
name|MacSizeChange
operator|=
literal|177
block|,
comment|// when the Qt::WA_Mac{Normal,Small,Mini}Size changes
name|ContentsRectChange
operator|=
literal|178
block|,
comment|// sent by QWidget::setContentsMargins (internal)
name|MacGLWindowChange
operator|=
literal|179
block|,
comment|// Internal! the window of the GLWidget has changed
name|FutureCallOut
operator|=
literal|180
block|,
name|GraphicsSceneResize
operator|=
literal|181
block|,
name|GraphicsSceneMove
operator|=
literal|182
block|,
name|CursorChange
operator|=
literal|183
block|,
name|ToolTipChange
operator|=
literal|184
block|,
name|NetworkReplyUpdated
operator|=
literal|185
block|,
comment|// Internal for QNetworkReply
name|GrabMouse
operator|=
literal|186
block|,
name|UngrabMouse
operator|=
literal|187
block|,
name|GrabKeyboard
operator|=
literal|188
block|,
name|UngrabKeyboard
operator|=
literal|189
block|,
name|MacGLClearDrawable
operator|=
literal|191
block|,
comment|// Internal Cocoa, the window has changed, so we must clear
name|StateMachineSignal
operator|=
literal|192
block|,
name|StateMachineWrapped
operator|=
literal|193
block|,
name|TouchBegin
operator|=
literal|194
block|,
name|TouchUpdate
operator|=
literal|195
block|,
name|TouchEnd
operator|=
literal|196
block|,
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|NativeGesture
operator|=
literal|197
block|,
comment|// QtGui native gesture
endif|#
directive|endif
name|RequestSoftwareInputPanel
operator|=
literal|199
block|,
name|CloseSoftwareInputPanel
operator|=
literal|200
block|,
name|WinIdChange
operator|=
literal|203
block|,
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|Gesture
operator|=
literal|198
block|,
name|GestureOverride
operator|=
literal|202
block|,
endif|#
directive|endif
name|ScrollPrepare
operator|=
literal|204
block|,
name|Scroll
operator|=
literal|205
block|,
name|Expose
operator|=
literal|206
block|,
name|InputMethodQuery
operator|=
literal|207
block|,
name|OrientationChange
operator|=
literal|208
block|,
comment|// Screen orientation has changed
name|TouchCancel
operator|=
literal|209
block|,
name|ThemeChange
operator|=
literal|210
block|,
name|SockClose
operator|=
literal|211
block|,
comment|// socket closed
name|PlatformPanel
operator|=
literal|212
block|,
name|StyleAnimationUpdate
operator|=
literal|213
block|,
comment|// style animation target should be updated
name|ApplicationStateChange
operator|=
literal|214
block|,
name|WindowChangeInternal
operator|=
literal|215
block|,
comment|// internal for QQuickWidget
name|ScreenChangeInternal
operator|=
literal|216
block|,
name|PlatformSurface
operator|=
literal|217
block|,
comment|// Platform surface created or about to be destroyed
name|Pointer
operator|=
literal|218
block|,
comment|// QQuickPointerEvent; ### Qt 6: QPointerEvent
comment|// 512 reserved for Qt Jambi's MetaCall event
comment|// 513 reserved for Qt Jambi's DeleteOnMainThread event
name|User
operator|=
literal|1000
block|,
comment|// first user event id
name|MaxUser
operator|=
literal|65535
comment|// last user event id
block|}
decl_stmt|;
name|Q_ENUM
argument_list|(
argument|Type
argument_list|)
name|explicit
name|QEvent
parameter_list|(
name|Type
name|type
parameter_list|)
function_decl|;
name|QEvent
argument_list|(
specifier|const
name|QEvent
operator|&
name|other
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|QEvent
argument_list|()
expr_stmt|;
name|QEvent
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QEvent
operator|&
name|other
operator|)
decl_stmt|;
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Type
operator|>
operator|(
name|t
operator|)
return|;
block|}
specifier|inline
name|bool
name|spontaneous
argument_list|()
specifier|const
block|{
return|return
name|spont
return|;
block|}
specifier|inline
name|void
name|setAccepted
parameter_list|(
name|bool
name|accepted
parameter_list|)
block|{
name|m_accept
operator|=
name|accepted
expr_stmt|;
block|}
specifier|inline
name|bool
name|isAccepted
argument_list|()
specifier|const
block|{
return|return
name|m_accept
return|;
block|}
specifier|inline
name|void
name|accept
parameter_list|()
block|{
name|m_accept
operator|=
name|true
expr_stmt|;
block|}
specifier|inline
name|void
name|ignore
parameter_list|()
block|{
name|m_accept
operator|=
name|false
expr_stmt|;
block|}
specifier|static
name|int
name|registerEventType
argument_list|(
name|int
name|hint
operator|=
operator|-
literal|1
argument_list|)
name|Q_DECL_NOTHROW
decl_stmt|;
name|protected
label|:
name|QEventPrivate
modifier|*
name|d
decl_stmt|;
name|ushort
name|t
decl_stmt|;
name|private
label|:
name|ushort
name|posted
range|:
literal|1
decl_stmt|;
name|ushort
name|spont
range|:
literal|1
decl_stmt|;
name|ushort
name|m_accept
range|:
literal|1
decl_stmt|;
name|ushort
name|reserved
range|:
literal|13
decl_stmt|;
name|friend
name|class
name|QCoreApplication
decl_stmt|;
name|friend
name|class
name|QCoreApplicationPrivate
decl_stmt|;
name|friend
name|class
name|QThreadData
decl_stmt|;
name|friend
name|class
name|QApplication
decl_stmt|;
name|friend
name|class
name|QShortcutMap
decl_stmt|;
name|friend
name|class
name|QGraphicsView
decl_stmt|;
name|friend
name|class
name|QGraphicsScene
decl_stmt|;
name|friend
name|class
name|QGraphicsScenePrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QTimerEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|explicit
name|QTimerEvent
argument_list|(
argument|int timerId
argument_list|)
block|;
operator|~
name|QTimerEvent
argument_list|()
block|;
name|int
name|timerId
argument_list|()
specifier|const
block|{
return|return
name|id
return|;
block|}
name|protected
operator|:
name|int
name|id
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QChildEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|QChildEvent
argument_list|(
argument|Type type
argument_list|,
argument|QObject *child
argument_list|)
block|;
operator|~
name|QChildEvent
argument_list|()
block|;
name|QObject
operator|*
name|child
argument_list|()
specifier|const
block|{
return|return
name|c
return|;
block|}
name|bool
name|added
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|ChildAdded
return|;
block|}
name|bool
name|polished
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|ChildPolished
return|;
block|}
name|bool
name|removed
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|ChildRemoved
return|;
block|}
name|protected
operator|:
name|QObject
operator|*
name|c
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDynamicPropertyChangeEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|explicit
name|QDynamicPropertyChangeEvent
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|)
block|;
operator|~
name|QDynamicPropertyChangeEvent
argument_list|()
block|;
specifier|inline
name|QByteArray
name|propertyName
argument_list|()
specifier|const
block|{
return|return
name|n
return|;
block|}
name|private
operator|:
name|QByteArray
name|n
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDeferredDeleteEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|explicit
name|QDeferredDeleteEvent
argument_list|()
block|;
operator|~
name|QDeferredDeleteEvent
argument_list|()
block|;
name|int
name|loopLevel
argument_list|()
specifier|const
block|{
return|return
name|level
return|;
block|}
name|private
operator|:
name|int
name|level
block|;
name|friend
name|class
name|QCoreApplication
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOREEVENT_H
end_comment
end_unit
