begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformwindow.h"
end_include
begin_include
include|#
directive|include
file|"qplatformwindow_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|<private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_include
include|#
directive|include
file|<private/qwindow_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     Constructs a platform window with the given top level window. */
end_comment
begin_constructor
DECL|function|QPlatformWindow
name|QPlatformWindow
operator|::
name|QPlatformWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformSurface
argument_list|(
name|window
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QPlatformWindowPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|rect
operator|=
name|window
operator|->
name|geometry
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Virtual destructor does not delete its top level window. */
end_comment
begin_destructor
DECL|function|~QPlatformWindow
name|QPlatformWindow
operator|::
name|~
name|QPlatformWindow
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the window which belongs to the QPlatformWindow */
end_comment
begin_function
DECL|function|window
name|QWindow
modifier|*
name|QPlatformWindow
operator|::
name|window
parameter_list|()
specifier|const
block|{
return|return
cast|static_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|m_surface
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the parent platform window (or 0 if orphan). */
end_comment
begin_function
DECL|function|parent
name|QPlatformWindow
modifier|*
name|QPlatformWindow
operator|::
name|parent
parameter_list|()
specifier|const
block|{
return|return
name|window
argument_list|()
operator|->
name|parent
argument_list|()
condition|?
name|window
argument_list|()
operator|->
name|parent
argument_list|()
operator|->
name|handle
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the platform screen handle corresponding to this platform window. */
end_comment
begin_function
DECL|function|screen
name|QPlatformScreen
modifier|*
name|QPlatformWindow
operator|::
name|screen
parameter_list|()
specifier|const
block|{
return|return
name|window
argument_list|()
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the actual surface format of the window. */
end_comment
begin_function
DECL|function|format
name|QSurfaceFormat
name|QPlatformWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|QSurfaceFormat
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called by Qt whenever a window is moved or the window is resized. The resize     can happen programatically(from ie. user application) or by the window manager. This means that     there is no need to call this function specifically from the window manager callback, instead     call QWindowSystemInterface::handleGeometryChange(QWindow *w, const QRect&newRect);      The position(x, y) part of the rect might be inclusive or exclusive of the window frame     as returned by frameMargins(). You can detect this in the plugin by checking     qt_window_private(window())->positionPolicy. */
end_comment
begin_function
DECL|function|setGeometry
name|void
name|QPlatformWindow
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformWindow
argument_list|)
expr_stmt|;
name|d
operator|->
name|rect
operator|=
name|rect
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returnes the current geometry of a window */
end_comment
begin_function
DECL|function|geometry
name|QRect
name|QPlatformWindow
operator|::
name|geometry
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|rect
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the geometry of a window in 'normal' state     (neither maximized, fullscreen nor minimized) for saving geometries to     application settings.      \since 5.3 */
end_comment
begin_function
DECL|function|normalGeometry
name|QRect
name|QPlatformWindow
operator|::
name|normalGeometry
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|frameMargins
name|QMargins
name|QPlatformWindow
operator|::
name|frameMargins
parameter_list|()
specifier|const
block|{
return|return
name|QMargins
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplemented in subclasses to show the surface     if \a visible is \c true, and hide it if \a visible is \c false.      The default implementation sends a synchronous expose event. */
end_comment
begin_function
DECL|function|setVisible
name|void
name|QPlatformWindow
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|visible
argument_list|)
expr_stmt|;
name|QRect
name|rect
argument_list|(
name|QPoint
argument_list|()
argument_list|,
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
decl_stmt|;
name|QWindowSystemInterface
operator|::
name|handleExposeEvent
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|flushWindowSystemEvents
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Requests setting the window flags of this surface     to \a flags. */
end_comment
begin_function
DECL|function|setWindowFlags
name|void
name|QPlatformWindow
operator|::
name|setWindowFlags
parameter_list|(
name|Qt
operator|::
name|WindowFlags
name|flags
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns if this window is exposed in the windowing system.      An exposeEvent() is sent every time this value changes.  */
end_comment
begin_function
DECL|function|isExposed
name|bool
name|QPlatformWindow
operator|::
name|isExposed
parameter_list|()
specifier|const
block|{
return|return
name|window
argument_list|()
operator|->
name|isVisible
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the window should appear active from a style perspective.      This function can make platform-specific isActive checks, such as checking     if the QWindow is embedded in an active native window. */
end_comment
begin_function
DECL|function|isActive
name|bool
name|QPlatformWindow
operator|::
name|isActive
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the window is a descendant of an embedded non-Qt window.     Example of an embedded non-Qt window is the parent window of an in-process QAxServer.      If \a parentWindow is nonzero, only check if the window is embedded in the     specified \a parentWindow. */
end_comment
begin_function
DECL|function|isEmbedded
name|bool
name|QPlatformWindow
operator|::
name|isEmbedded
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|parentWindow
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|parentWindow
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Translates the window coordinate \a pos to global screen     coordinates using native methods. This is required for embedded windows,     where the topmost QWindow coordinates are not global screen coordinates.      Returns \a pos if there is no platform specific implementation. */
end_comment
begin_function
DECL|function|mapToGlobal
name|QPoint
name|QPlatformWindow
operator|::
name|mapToGlobal
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
specifier|const
name|QPlatformWindow
modifier|*
name|p
init|=
name|this
decl_stmt|;
name|QPoint
name|result
init|=
name|pos
decl_stmt|;
while|while
condition|(
name|p
condition|)
block|{
name|result
operator|+=
name|p
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
expr_stmt|;
name|p
operator|=
name|p
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Translates the global screen coordinate \a pos to window     coordinates using native methods. This is required for embedded windows,     where the topmost QWindow coordinates are not global screen coordinates.      Returns \a pos if there is no platform specific implementation. */
end_comment
begin_function
DECL|function|mapFromGlobal
name|QPoint
name|QPlatformWindow
operator|::
name|mapFromGlobal
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
specifier|const
name|QPlatformWindow
modifier|*
name|p
init|=
name|this
decl_stmt|;
name|QPoint
name|result
init|=
name|pos
decl_stmt|;
while|while
condition|(
name|p
condition|)
block|{
name|result
operator|-=
name|p
operator|->
name|geometry
argument_list|()
operator|.
name|topLeft
argument_list|()
expr_stmt|;
name|p
operator|=
name|p
operator|->
name|parent
argument_list|()
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|/*!     Requests setting the window state of this surface     to \a type.      Qt::WindowActive can be ignored. */
end_comment
begin_function
DECL|function|setWindowState
name|void
name|QPlatformWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
parameter_list|)
block|{ }
end_function
begin_comment
comment|/*!   Reimplement in subclasses to return a handle to the native window */
end_comment
begin_function
DECL|function|winId
name|WId
name|QPlatformWindow
operator|::
name|winId
parameter_list|()
specifier|const
block|{
comment|// Return anything but 0. Returning 0 would cause havoc with QWidgets on
comment|// very basic platform plugins that do not reimplement this function,
comment|// because the top-level widget's internalWinId() would always be 0 which
comment|// would mean top-levels are never treated as native.
return|return
name|WId
argument_list|(
literal|1
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called to enable native child window in QPA. It is common not to support this     feature in Window systems, but can be faked. When this function is called all geometry of this     platform window will be relative to the parent. */
end_comment
begin_comment
comment|//jl: It would be useful to have a property on the platform window which indicated if the sub-class
end_comment
begin_comment
comment|// supported the setParent. If not, then geometry would be in screen coordinates.
end_comment
begin_function
DECL|function|setParent
name|void
name|QPlatformWindow
operator|::
name|setParent
parameter_list|(
specifier|const
name|QPlatformWindow
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support setParent!"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to set the window title to \a title.    The implementation might want to append the application display name to   the window title, like Windows and Linux do.    \sa QGuiApplication::applicationDisplayName() */
end_comment
begin_function
DECL|function|setWindowTitle
name|void
name|QPlatformWindow
operator|::
name|setWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|title
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to set the window file path to \a filePath */
end_comment
begin_function
DECL|function|setWindowFilePath
name|void
name|QPlatformWindow
operator|::
name|setWindowFilePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|filePath
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|filePath
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to set the window icon to \a icon */
end_comment
begin_function
DECL|function|setWindowIcon
name|void
name|QPlatformWindow
operator|::
name|setWindowIcon
parameter_list|(
specifier|const
name|QIcon
modifier|&
name|icon
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|icon
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to be able to let Qt raise windows to the top of the desktop */
end_comment
begin_function
DECL|function|raise
name|void
name|QPlatformWindow
operator|::
name|raise
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support raise()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to be able to let Qt lower windows to the bottom of the desktop */
end_comment
begin_function
DECL|function|lower
name|void
name|QPlatformWindow
operator|::
name|lower
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support lower()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to propagate the size hints of the QWindow.    The size hints include QWindow::minimumSize(), QWindow::maximumSize(),   QWindow::sizeIncrement(), and QWindow::baseSize(). */
end_comment
begin_function
DECL|function|propagateSizeHints
name|void
name|QPlatformWindow
operator|::
name|propagateSizeHints
parameter_list|()
block|{
name|qWarning
argument_list|(
literal|"This plugin does not support propagateSizeHints()"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to be able to let Qt set the opacity level of a window */
end_comment
begin_function
DECL|function|setOpacity
name|void
name|QPlatformWindow
operator|::
name|setOpacity
parameter_list|(
name|qreal
name|level
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|level
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support setting window opacity"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to  be able to let Qt set the mask of a window */
end_comment
begin_function
DECL|function|setMask
name|void
name|QPlatformWindow
operator|::
name|setMask
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support setting window masks"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Reimplement to let Qt be able to request activation/focus for a window    Some window systems will probably not have callbacks for this functionality,   and then calling QWindowSystemInterface::handleWindowActivated(QWindow *w)   would be sufficient.    If the window system has some event handling/callbacks then call   QWindowSystemInterface::handleWindowActivated(QWindow *w) when the window system   gives the notification.    Default implementation calls QWindowSystem::handleWindowActivated(QWindow *w) */
end_comment
begin_function
DECL|function|requestActivateWindow
name|void
name|QPlatformWindow
operator|::
name|requestActivateWindow
parameter_list|()
block|{
name|QWindowSystemInterface
operator|::
name|handleWindowActivated
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Handle changes to the orientation of the platform window's contents.    This is a hint to the window manager in case it needs to display   additional content like popups, dialogs, status bars, or similar   in relation to the window.    \sa QWindow::reportContentOrientationChange() */
end_comment
begin_function
DECL|function|handleContentOrientationChange
name|void
name|QPlatformWindow
operator|::
name|handleContentOrientationChange
parameter_list|(
name|Qt
operator|::
name|ScreenOrientation
name|orientation
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|orientation
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this function in subclass to return the device pixel ratio     for the window. This is the ratio between physical pixels     and device-independent pixels.      \sa QPlatformWindow::devicePixelRatio(); */
end_comment
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QPlatformWindow
operator|::
name|devicePixelRatio
parameter_list|()
specifier|const
block|{
return|return
literal|1.0
return|;
block|}
end_function
begin_function
DECL|function|setKeyboardGrabEnabled
name|bool
name|QPlatformWindow
operator|::
name|setKeyboardGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|grab
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support grabbing the keyboard"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|setMouseGrabEnabled
name|bool
name|QPlatformWindow
operator|::
name|setMouseGrabEnabled
parameter_list|(
name|bool
name|grab
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|grab
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"This plugin does not support grabbing the mouse"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement to be able to let Qt indicate that the window has been     modified. Return true if the native window supports setting the modified     flag, false otherwise. */
end_comment
begin_function
DECL|function|setWindowModified
name|bool
name|QPlatformWindow
operator|::
name|setWindowModified
parameter_list|(
name|bool
name|modified
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|modified
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this method to be able to do any platform specific event     handling. All events for window() are passed to this function before being     sent to QWindow::event().      The default implementation is empty and does nothing with \a event. */
end_comment
begin_function
DECL|function|windowEvent
name|void
name|QPlatformWindow
operator|::
name|windowEvent
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this method to start a system size grip drag     operation if the system supports it and return true to indicate     success.     It is called from the mouse press event handler of the size grip.      The default implementation is empty and does nothing with \a pos     and \a corner. */
end_comment
begin_function
DECL|function|startSystemResize
name|bool
name|QPlatformWindow
operator|::
name|startSystemResize
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|,
name|Qt
operator|::
name|Corner
name|corner
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|pos
argument_list|)
name|Q_UNUSED
argument_list|(
argument|corner
argument_list|)
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this method to set whether frame strut events     should be sent to \a enabled.      \sa frameStrutEventsEnabled */
end_comment
begin_function
DECL|function|setFrameStrutEventsEnabled
name|void
name|QPlatformWindow
operator|::
name|setFrameStrutEventsEnabled
parameter_list|(
name|bool
name|enabled
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|enabled
argument_list|)
comment|// Do not warn as widgets enable it by default causing warnings with XCB.
block|}
end_function
begin_comment
comment|/*!     Reimplement this method to return whether     frame strut events are enabled. */
end_comment
begin_function
DECL|function|frameStrutEventsEnabled
name|bool
name|QPlatformWindow
operator|::
name|frameStrutEventsEnabled
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Call this method to put together a window title composed of     \a title     \a separator     the application display name      If the display name isn't set, and the title is empty, the raw app name is used. */
end_comment
begin_function
DECL|function|formatWindowTitle
name|QString
name|QPlatformWindow
operator|::
name|formatWindowTitle
parameter_list|(
specifier|const
name|QString
modifier|&
name|title
parameter_list|,
specifier|const
name|QString
modifier|&
name|separator
parameter_list|)
block|{
name|QString
name|fullTitle
init|=
name|title
decl_stmt|;
if|if
condition|(
name|QGuiApplicationPrivate
operator|::
name|displayName
operator|&&
operator|!
name|title
operator|.
name|endsWith
argument_list|(
operator|*
name|QGuiApplicationPrivate
operator|::
name|displayName
argument_list|)
condition|)
block|{
comment|// Append display name, if set.
if|if
condition|(
operator|!
name|fullTitle
operator|.
name|isEmpty
argument_list|()
condition|)
name|fullTitle
operator|+=
name|separator
expr_stmt|;
name|fullTitle
operator|+=
operator|*
name|QGuiApplicationPrivate
operator|::
name|displayName
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|fullTitle
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
comment|// Don't let the window title be completely empty, use the app name as fallback.
name|fullTitle
operator|=
name|QCoreApplication
operator|::
name|applicationName
argument_list|()
expr_stmt|;
block|}
return|return
name|fullTitle
return|;
block|}
end_function
begin_comment
comment|/*!     Helper function for finding the new screen for \a newGeometry in response to     a geometry changed event. Returns the new screen if the window was moved to     another virtual sibling. If the screen changes, the platform plugin should call     QWindowSystemInterface::handleWindowScreenChanged().     \note: The current screen will always be returned for child windows since     they should never signal screen changes.      \since 5.4     \sa QWindowSystemInterface::handleWindowScreenChanged() */
end_comment
begin_function
DECL|function|screenForGeometry
name|QPlatformScreen
modifier|*
name|QPlatformWindow
operator|::
name|screenForGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|newGeometry
parameter_list|)
specifier|const
block|{
name|QPlatformScreen
modifier|*
name|currentScreen
init|=
name|screen
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parent
argument_list|()
operator|&&
operator|!
name|currentScreen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|newGeometry
argument_list|)
condition|)
block|{
name|Q_FOREACH
argument_list|(
argument|QPlatformScreen* screen
argument_list|,
argument|currentScreen->virtualSiblings()
argument_list|)
block|{
if|if
condition|(
name|screen
operator|->
name|geometry
argument_list|()
operator|.
name|intersects
argument_list|(
name|newGeometry
argument_list|)
condition|)
return|return
name|screen
return|;
block|}
block|}
return|return
name|currentScreen
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this method to set whether the window demands attention     (for example, by flashing the taskbar icon) depending on \a enabled.      \sa isAlertState()     \since 5.1 */
end_comment
begin_function
DECL|function|setAlertState
name|void
name|QPlatformWindow
operator|::
name|setAlertState
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|enable
argument_list|)
block|}
end_function
begin_comment
comment|/*!     Reimplement this method return whether the window is in     an alert state.      \sa setAlertState()     \since 5.1 */
end_comment
begin_function
DECL|function|isAlertState
name|bool
name|QPlatformWindow
operator|::
name|isAlertState
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|// Return the effective screen for the initial geometry of a window. In a
end_comment
begin_comment
comment|// multimonitor-setup, try to find the right screen by checking the transient
end_comment
begin_comment
comment|// parent or the mouse cursor for parentless windows (cf QTBUG-34204,
end_comment
begin_comment
comment|// QDialog::adjustPosition()).
end_comment
begin_function
DECL|function|effectiveScreen
specifier|static
specifier|inline
specifier|const
name|QScreen
modifier|*
name|effectiveScreen
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|window
condition|)
return|return
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
return|;
specifier|const
name|QScreen
modifier|*
name|screen
init|=
name|window
operator|->
name|screen
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|screen
condition|)
return|return
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
return|;
specifier|const
name|QList
argument_list|<
name|QScreen
modifier|*
argument_list|>
name|siblings
init|=
name|screen
operator|->
name|virtualSiblings
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
if|if
condition|(
name|siblings
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
specifier|const
name|QPoint
name|referencePoint
init|=
name|window
operator|->
name|transientParent
argument_list|()
condition|?
name|window
operator|->
name|transientParent
argument_list|()
operator|->
name|geometry
argument_list|()
operator|.
name|center
argument_list|()
else|:
name|QCursor
operator|::
name|pos
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QScreen
modifier|*
name|sibling
decl|,
name|siblings
control|)
if|if
condition|(
name|sibling
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|referencePoint
argument_list|)
condition|)
return|return
name|sibling
return|;
block|}
endif|#
directive|endif
return|return
name|screen
return|;
block|}
end_function
begin_comment
comment|/*!     Invalidates the window's surface by releasing its surface buffers.      Many platforms do not support releasing the surface memory,     and the default implementation does nothing.      The platform window is expected to recreate the surface again if     it is needed. For instance, if an OpenGL context is made current     on this window.  */
end_comment
begin_function
DECL|function|invalidateSurface
name|void
name|QPlatformWindow
operator|::
name|invalidateSurface
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*!     Helper function to get initial geometry on windowing systems which do not     do smart positioning and also do not provide a means of centering a     transient window w.r.t. its parent. For example this is useful on Windows     and MacOS but not X11, because an X11 window manager typically tries to     layout new windows to optimize usage of the available desktop space.     However if the given window already has geometry which the application has     initialized, it takes priority. */
end_comment
begin_function
DECL|function|initialGeometry
name|QRect
name|QPlatformWindow
operator|::
name|initialGeometry
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|w
parameter_list|,
specifier|const
name|QRect
modifier|&
name|initialGeometry
parameter_list|,
name|int
name|defaultWidth
parameter_list|,
name|int
name|defaultHeight
parameter_list|)
block|{
name|QRect
name|rect
argument_list|(
name|initialGeometry
argument_list|)
decl_stmt|;
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|==
literal|0
condition|)
block|{
specifier|const
name|int
name|minWidth
init|=
name|w
operator|->
name|minimumWidth
argument_list|()
decl_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|minWidth
operator|>
literal|0
condition|?
name|minWidth
else|:
name|defaultWidth
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rect
operator|.
name|height
argument_list|()
operator|==
literal|0
condition|)
block|{
specifier|const
name|int
name|minHeight
init|=
name|w
operator|->
name|minimumHeight
argument_list|()
decl_stmt|;
name|rect
operator|.
name|setHeight
argument_list|(
name|minHeight
operator|>
literal|0
condition|?
name|minHeight
else|:
name|defaultHeight
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|w
operator|->
name|isTopLevel
argument_list|()
operator|&&
name|qt_window_private
argument_list|(
cast|const_cast
argument_list|<
name|QWindow
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
argument_list|)
operator|->
name|positionAutomatic
operator|&&
name|w
operator|->
name|type
argument_list|()
operator|!=
name|Qt
operator|::
name|Popup
condition|)
block|{
if|if
condition|(
specifier|const
name|QScreen
modifier|*
name|screen
init|=
name|effectiveScreen
argument_list|(
name|w
argument_list|)
condition|)
block|{
specifier|const
name|QRect
name|availableGeometry
init|=
name|screen
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
comment|// Center unless the geometry ( + unknown window frame) is too large for the screen).
if|if
condition|(
name|rect
operator|.
name|height
argument_list|()
operator|<
operator|(
name|availableGeometry
operator|.
name|height
argument_list|()
operator|*
literal|8
operator|)
operator|/
literal|9
operator|&&
name|rect
operator|.
name|width
argument_list|()
operator|<
operator|(
name|availableGeometry
operator|.
name|width
argument_list|()
operator|*
literal|8
operator|)
operator|/
literal|9
condition|)
block|{
specifier|const
name|QWindow
modifier|*
name|tp
init|=
name|w
operator|->
name|transientParent
argument_list|()
decl_stmt|;
if|if
condition|(
name|tp
condition|)
block|{
comment|// A transient window should be centered w.r.t. its transient parent.
name|rect
operator|.
name|moveCenter
argument_list|(
name|tp
operator|->
name|geometry
argument_list|()
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Center the window on the screen.  (Only applicable on platforms
comment|// which do not provide a better way.)
name|rect
operator|.
name|moveCenter
argument_list|(
name|availableGeometry
operator|.
name|center
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
return|return
name|rect
return|;
block|}
end_function
begin_comment
comment|/*!     Requests an QEvent::UpdateRequest event. The event will be     delivered to the QWindow.      QPlatformWindow subclasses can re-implement this function to     provide display refresh synchronized updates. The event     should be delivered using QWindowPrivate::deliverUpdateRequest()     to not get out of sync with the the internal state of QWindow.      The default implementation posts an UpdateRequest event to the     window after 5 ms. The additional time is there to give the event     loop a bit of idle time to gather system events.  */
end_comment
begin_function
DECL|function|requestUpdate
name|void
name|QPlatformWindow
operator|::
name|requestUpdate
parameter_list|()
block|{
specifier|static
name|int
name|timeout
init|=
operator|-
literal|1
decl_stmt|;
if|if
condition|(
name|timeout
operator|==
operator|-
literal|1
condition|)
block|{
name|bool
name|ok
init|=
literal|false
decl_stmt|;
name|timeout
operator|=
name|qEnvironmentVariableIntValue
argument_list|(
literal|"QT_QPA_UPDATE_IDLE_TIME"
argument_list|,
operator|&
name|ok
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|timeout
operator|=
literal|5
expr_stmt|;
block|}
name|QWindow
modifier|*
name|w
init|=
name|window
argument_list|()
decl_stmt|;
name|QWindowPrivate
modifier|*
name|wp
init|=
operator|(
name|QWindowPrivate
operator|*
operator|)
name|QObjectPrivate
operator|::
name|get
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|wp
operator|->
name|updateTimer
operator|==
literal|0
argument_list|)
expr_stmt|;
name|wp
operator|->
name|updateTimer
operator|=
name|w
operator|->
name|startTimer
argument_list|(
name|timeout
argument_list|,
name|Qt
operator|::
name|PreciseTimer
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QPlatformWindow     \since 4.8     \internal     \preliminary     \ingroup qpa      \brief The QPlatformWindow class provides an abstraction for top-level windows.      The QPlatformWindow abstraction is used by QWindow for all its top level windows. It is being     created by calling the createPlatformWindow function in the loaded QPlatformIntegration     instance.      QPlatformWindow is used to signal to the windowing system, how Qt perceives its frame.     However, it is not concerned with how Qt renders into the window it represents.      Visible QWindows will always have a QPlatformWindow. However, it is not necessary for     all windows to have a QBackingStore. This is the case for QOpenGLWidget. And could be the case for     windows where some  3.party renders into it.      The platform specific window handle can be retrieved by the winId function.      QPlatformWindow is also the way QPA defines how native child windows should be supported     through the setParent function.      \section1 Implementation Aspects      \list 1         \li Mouse grab: Qt expects windows to automatically grab the mouse if the user presses             a button until the button is released.             Automatic grab should be released if some window is explicitly grabbed.         \li Enter/Leave events: If there is a window explicitly grabbing mouse events             (\c{setMouseGrabEnabled()}), enter and leave events should only be sent to the             grabbing window when mouse cursor passes over the grabbing window boundary.             Other windows will not receive enter or leave events while the grab is active.             While an automatic mouse grab caused by a mouse button press is active, no window             will receive enter or leave events. When the last mouse button is released, the             autograbbing window will receive leave event if mouse cursor is no longer within             the window boundary.             When any grab starts, the window under cursor will receive a leave event unless             it is the grabbing window.             When any grab ends, the window under cursor will receive an enter event unless it             was the grabbing window.         \li Window positioning: When calling \c{QWindow::setFramePosition()}, the flag             \c{QWindowPrivate::positionPolicy} is set to \c{QWindowPrivate::WindowFrameInclusive}.             This means the position includes the window frame, whose size is at this point             unknown and the geometry's topleft point is the position of the window frame.     \endlist      Apart from the auto-tests (\c{tests/auto/gui/kernel/qwindow},     \c{tests/auto/gui/kernel/qguiapplication} and \c{tests/auto/widgets/kernel/qwidget}),     there are a number of manual tests and examples that can help testing a platform plugin:      \list 1         \li \c{examples/qpa/windows}: Basic \c{QWindow} creation.         \li \c{examples/opengl/hellowindow}: Basic Open GL windows.         \li \c{tests/manual/windowflags}: Tests setting the window flags.         \li \c{tests/manual/windowgeometry} Tests setting the window geometry.         \li \c{tests/manual/windowmodality} Tests setting the window modality.         \li \c{tests/manual/widgetgrab} Tests mouse grab and dialogs.     \endlist      \sa QBackingStore, QWindow */
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
