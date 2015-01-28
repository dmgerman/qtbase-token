begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qlabel.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qpixmap.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qlist.h"
end_include
begin_include
include|#
directive|include
file|"qmenu.h"
end_include
begin_include
include|#
directive|include
file|"qtimer.h"
end_include
begin_include
include|#
directive|include
file|"qsystemtrayicon_p.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengine.h"
end_include
begin_include
include|#
directive|include
file|<qwindow.h>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qscreen.h>
end_include
begin_include
include|#
directive|include
file|<qbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformsystemtrayicon.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformtheme.h>
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMTRAYICON
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|locateSystemTray
specifier|static
specifier|inline
name|unsigned
name|long
name|locateSystemTray
parameter_list|()
block|{
return|return
operator|(
name|unsigned
name|long
operator|)
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
operator|->
name|nativeResourceForScreen
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"traywindow"
argument_list|)
argument_list|,
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// System tray widget. Could be replaced by a QWindow with
end_comment
begin_comment
comment|// a backing store if it did not need tooltip handling.
end_comment
begin_class
DECL|class|QSystemTrayIconSys
class|class
name|QSystemTrayIconSys
super|:
specifier|public
name|QWidget
block|{
name|Q_OBJECT
public|public:
specifier|explicit
name|QSystemTrayIconSys
parameter_list|(
name|QSystemTrayIcon
modifier|*
name|q
parameter_list|)
constructor_decl|;
DECL|function|updateIcon
specifier|inline
name|void
name|updateIcon
parameter_list|()
block|{
name|update
argument_list|()
expr_stmt|;
block|}
DECL|function|systemTrayIcon
specifier|inline
name|QSystemTrayIcon
modifier|*
name|systemTrayIcon
parameter_list|()
specifier|const
block|{
return|return
name|q
return|;
block|}
name|QRect
name|globalGeometry
parameter_list|()
specifier|const
function_decl|;
protected|protected:
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|void
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|void
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|bool
name|event
parameter_list|(
name|QEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
DECL|member|Q_DECL_OVERRIDE
specifier|virtual
name|void
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
parameter_list|)
name|Q_DECL_OVERRIDE
function_decl|;
private|private
name|slots
private|:
name|void
name|systemTrayWindowChanged
parameter_list|(
name|QScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
private|private:
name|bool
name|addToTray
parameter_list|()
function_decl|;
DECL|member|q
name|QSystemTrayIcon
modifier|*
name|q
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QSystemTrayIconSys
name|QSystemTrayIconSys
operator|::
name|QSystemTrayIconSys
parameter_list|(
name|QSystemTrayIcon
modifier|*
name|qIn
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|FramelessWindowHint
operator||
name|Qt
operator|::
name|BypassWindowManagerHint
argument_list|)
member_init_list|,
name|q
argument_list|(
name|qIn
argument_list|)
block|{
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"QSystemTrayIconSys"
argument_list|)
argument_list|)
expr_stmt|;
name|setToolTip
argument_list|(
name|q
operator|->
name|toolTip
argument_list|()
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_AlwaysShowToolTips
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_QuitOnClose
argument_list|,
literal|false
argument_list|)
expr_stmt|;
specifier|const
name|QSize
name|size
argument_list|(
literal|22
argument_list|,
literal|22
argument_list|)
decl_stmt|;
comment|// Gnome, standard size
name|setGeometry
argument_list|(
name|QRect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|setMinimumSize
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|// We need two different behaviors depending on whether the X11 visual for the system tray
comment|// (a) exists and (b) supports an alpha channel, i.e. is 32 bits.
comment|// If we have a visual that has an alpha channel, we can paint this widget with a transparent
comment|// background and it will work.
comment|// However, if there's no alpha channel visual, in order for transparent tray icons to work,
comment|// we do not have a transparent background on the widget, but set the BackPixmap property of our
comment|// window to ParentRelative (so that it inherits the background of its X11 parent window), call
comment|// xcb_clear_region before painting (so that the inherited background is visible) and then grab
comment|// the just-drawn background from the X11 server.
name|bool
name|hasAlphaChannel
init|=
literal|false
decl_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
argument_list|,
literal|"systrayVisualHasAlphaChannel"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|bool
argument_list|,
name|hasAlphaChannel
argument_list|)
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|,
name|hasAlphaChannel
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|hasAlphaChannel
condition|)
block|{
name|createWinId
argument_list|()
expr_stmt|;
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
argument_list|,
literal|"setParentRelativeBackPixmap"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_ARG
argument_list|(
specifier|const
name|QWindow
operator|*
argument_list|,
name|windowHandle
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
comment|// XXX: This is actually required, but breaks things ("QWidget::paintEngine: Should no
comment|// longer be called"). Why is this needed? When the widget is drawn, we use tricks to grab
comment|// the tray icon's background from the server. If the tray icon isn't visible (because
comment|// another window is on top of it), the trick fails and instead uses the content of that
comment|// other window as the background.
comment|// setAttribute(Qt::WA_PaintOnScreen);
block|}
name|addToTray
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|addToTray
name|bool
name|QSystemTrayIconSys
operator|::
name|addToTray
parameter_list|()
block|{
if|if
condition|(
operator|!
name|locateSystemTray
argument_list|()
condition|)
return|return
literal|false
return|;
name|createWinId
argument_list|()
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|bool
name|requestResult
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
argument_list|,
literal|"requestSystemTrayWindowDock"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|bool
argument_list|,
name|requestResult
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
specifier|const
name|QWindow
operator|*
argument_list|,
name|windowHandle
argument_list|()
argument_list|)
argument_list|)
operator|||
operator|!
name|requestResult
condition|)
block|{
name|qWarning
argument_list|(
literal|"requestSystemTrayWindowDock failed."
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|show
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|systemTrayWindowChanged
name|void
name|QSystemTrayIconSys
operator|::
name|systemTrayWindowChanged
parameter_list|(
name|QScreen
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|locateSystemTray
argument_list|()
condition|)
block|{
name|addToTray
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QBalloonTip
operator|::
name|hideBalloon
argument_list|()
expr_stmt|;
name|hide
argument_list|()
expr_stmt|;
comment|// still no luck
name|destroy
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|globalGeometry
name|QRect
name|QSystemTrayIconSys
operator|::
name|globalGeometry
parameter_list|()
specifier|const
block|{
name|QRect
name|result
decl_stmt|;
if|if
condition|(
operator|!
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
argument_list|,
literal|"systemTrayWindowGlobalGeometry"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_RETURN_ARG
argument_list|(
name|QRect
argument_list|,
name|result
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
specifier|const
name|QWindow
operator|*
argument_list|,
name|windowHandle
argument_list|()
argument_list|)
argument_list|)
operator|||
operator|!
name|result
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"systemTrayWindowGlobalGeometry failed."
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|QSystemTrayIconSys
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
name|QPoint
name|globalPos
init|=
name|ev
operator|->
name|globalPos
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CONTEXTMENU
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
operator|&&
name|q
operator|->
name|contextMenu
argument_list|()
condition|)
name|q
operator|->
name|contextMenu
argument_list|()
operator|->
name|popup
argument_list|(
name|globalPos
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|QBalloonTip
operator|::
name|isBalloonVisible
argument_list|()
condition|)
block|{
emit|emit
name|q
operator|->
name|messageClicked
argument_list|()
emit|;
name|QBalloonTip
operator|::
name|hideBalloon
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|Trigger
argument_list|)
emit|;
elseif|else
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|RightButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|Context
argument_list|)
emit|;
elseif|else
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|MidButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|MiddleClick
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|QSystemTrayIconSys
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
if|if
condition|(
name|ev
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
emit|emit
name|q
operator|->
name|activated
argument_list|(
name|QSystemTrayIcon
operator|::
name|DoubleClick
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|event
name|bool
name|QSystemTrayIconSys
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_WHEELEVENT
case|case
name|QEvent
operator|::
name|Wheel
case|:
return|return
name|QApplication
operator|::
name|sendEvent
argument_list|(
name|q
argument_list|,
name|e
argument_list|)
return|;
endif|#
directive|endif
default|default:
break|break;
block|}
return|return
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintEvent
name|void
name|QSystemTrayIconSys
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
specifier|const
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|// If we have Qt::WA_TranslucentBackground set, during widget creation
comment|// we detected the systray visual supported an alpha channel
if|if
condition|(
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_TranslucentBackground
argument_list|)
condition|)
block|{
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Without Qt::WA_TranslucentBackground, we use a ParentRelative BackPixmap and jump through
comment|// some hops to draw this background below our icon. This clears the whole tray icon to its
comment|// background color and thus causes flickering (you can see that the icon is being
comment|// repainted). However, we can't really do much about this.
name|QMetaObject
operator|::
name|invokeMethod
argument_list|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
argument_list|,
literal|"clearRegion"
argument_list|,
name|Qt
operator|::
name|DirectConnection
argument_list|,
name|Q_ARG
argument_list|(
specifier|const
name|QWindow
operator|*
argument_list|,
name|windowHandle
argument_list|()
argument_list|)
argument_list|,
name|Q_ARG
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|,
name|rect
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPixmap
argument_list|(
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|grabWindow
argument_list|(
name|winId
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|size
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|size
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|painter
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_SourceOver
argument_list|)
expr_stmt|;
name|q
operator|->
name|icon
argument_list|()
operator|.
name|paint
argument_list|(
operator|&
name|painter
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|moveEvent
name|void
name|QSystemTrayIconSys
operator|::
name|moveEvent
parameter_list|(
name|QMoveEvent
modifier|*
name|event
parameter_list|)
block|{
name|QWidget
operator|::
name|moveEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|QBalloonTip
operator|::
name|isBalloonVisible
argument_list|()
condition|)
name|QBalloonTip
operator|::
name|updateBalloonPosition
argument_list|(
name|globalGeometry
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QSystemTrayIconSys
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|update
argument_list|()
expr_stmt|;
name|QWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
if|if
condition|(
name|QBalloonTip
operator|::
name|isBalloonVisible
argument_list|()
condition|)
name|QBalloonTip
operator|::
name|updateBalloonPosition
argument_list|(
name|globalGeometry
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|////////////////////////////////////////////////////////////////////////////
end_comment
begin_constructor
DECL|function|QSystemTrayIconPrivate
name|QSystemTrayIconPrivate
operator|::
name|QSystemTrayIconPrivate
parameter_list|()
member_init_list|:
name|sys
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|qpa_sys
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformSystemTrayIcon
argument_list|()
argument_list|)
member_init_list|,
name|visible
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QSystemTrayIconPrivate
name|QSystemTrayIconPrivate
operator|::
name|~
name|QSystemTrayIconPrivate
parameter_list|()
block|{
operator|delete
name|qpa_sys
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|install_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|install_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
block|{
name|install_sys_qpa
argument_list|()
expr_stmt|;
return|return;
block|}
name|Q_Q
argument_list|(
name|QSystemTrayIcon
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sys
operator|&&
name|locateSystemTray
argument_list|()
condition|)
block|{
name|sys
operator|=
operator|new
name|QSystemTrayIconSys
argument_list|(
name|q
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|QGuiApplication
operator|::
name|platformNativeInterface
argument_list|()
argument_list|,
name|SIGNAL
argument_list|(
name|systemTrayWindowChanged
argument_list|(
name|QScreen
operator|*
argument_list|)
argument_list|)
argument_list|,
name|sys
argument_list|,
name|SLOT
argument_list|(
name|systemTrayWindowChanged
argument_list|(
name|QScreen
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|geometry_sys
name|QRect
name|QSystemTrayIconPrivate
operator|::
name|geometry_sys
parameter_list|()
specifier|const
block|{
if|if
condition|(
name|qpa_sys
condition|)
return|return
name|geometry_sys_qpa
argument_list|()
return|;
if|if
condition|(
operator|!
name|sys
condition|)
return|return
name|QRect
argument_list|()
return|;
return|return
name|sys
operator|->
name|globalGeometry
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|remove_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|remove_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
block|{
name|remove_sys_qpa
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
name|QBalloonTip
operator|::
name|hideBalloon
argument_list|()
expr_stmt|;
name|sys
operator|->
name|hide
argument_list|()
expr_stmt|;
comment|// this should do the trick, but...
operator|delete
name|sys
expr_stmt|;
comment|// wm may resize system tray only for DestroyEvents
name|sys
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateIcon_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateIcon_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
block|{
name|updateIcon_sys_qpa
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|sys
condition|)
name|sys
operator|->
name|updateIcon
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateMenu_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateMenu_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
name|updateMenu_sys_qpa
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateToolTip_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|updateToolTip_sys
parameter_list|()
block|{
if|if
condition|(
name|qpa_sys
condition|)
block|{
name|updateToolTip_sys_qpa
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
ifndef|#
directive|ifndef
name|QT_NO_TOOLTIP
name|sys
operator|->
name|setToolTip
argument_list|(
name|toolTip
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|isSystemTrayAvailable_sys
name|bool
name|QSystemTrayIconPrivate
operator|::
name|isSystemTrayAvailable_sys
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QPlatformSystemTrayIcon
argument_list|>
name|sys
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformSystemTrayIcon
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|sys
operator|&&
name|sys
operator|->
name|isSystemTrayAvailable
argument_list|()
condition|)
return|return
literal|true
return|;
comment|// no QPlatformSystemTrayIcon so fall back to default xcb platform behavior
specifier|const
name|QString
name|platform
init|=
name|QGuiApplication
operator|::
name|platformName
argument_list|()
decl_stmt|;
if|if
condition|(
name|platform
operator|.
name|compare
argument_list|(
name|QLatin1String
argument_list|(
literal|"xcb"
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
condition|)
return|return
name|locateSystemTray
argument_list|()
return|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|supportsMessages_sys
name|bool
name|QSystemTrayIconPrivate
operator|::
name|supportsMessages_sys
parameter_list|()
block|{
name|QScopedPointer
argument_list|<
name|QPlatformSystemTrayIcon
argument_list|>
name|sys
argument_list|(
name|QGuiApplicationPrivate
operator|::
name|platformTheme
argument_list|()
operator|->
name|createPlatformSystemTrayIcon
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|sys
condition|)
return|return
name|sys
operator|->
name|supportsMessages
argument_list|()
return|;
comment|// no QPlatformSystemTrayIcon so fall back to default xcb platform behavior
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|showMessage_sys
name|void
name|QSystemTrayIconPrivate
operator|::
name|showMessage_sys
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|,
name|QSystemTrayIcon
operator|::
name|MessageIcon
name|icon
parameter_list|,
name|int
name|msecs
parameter_list|)
block|{
if|if
condition|(
name|qpa_sys
condition|)
block|{
name|showMessage_sys_qpa
argument_list|(
name|title
argument_list|,
name|message
argument_list|,
name|icon
argument_list|,
name|msecs
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|sys
condition|)
return|return;
name|QBalloonTip
operator|::
name|showBalloon
argument_list|(
name|icon
argument_list|,
name|message
argument_list|,
name|title
argument_list|,
name|sys
operator|->
name|systemTrayIcon
argument_list|()
argument_list|,
name|sys
operator|->
name|globalGeometry
argument_list|()
operator|.
name|center
argument_list|()
argument_list|,
name|msecs
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"qsystemtrayicon_x11.moc"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_SYSTEMTRAYICON
end_comment
end_unit
