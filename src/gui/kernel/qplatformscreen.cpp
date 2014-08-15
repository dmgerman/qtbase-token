begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformcursor.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qguiapplication_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen_p.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindow.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QPlatformScreen
name|QPlatformScreen
operator|::
name|QPlatformScreen
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformScreenPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformScreen
argument_list|)
expr_stmt|;
name|d
operator|->
name|screen
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QPlatformScreen
name|QPlatformScreen
operator|::
name|~
name|QPlatformScreen
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QPlatformScreen
argument_list|)
expr_stmt|;
name|QGuiApplicationPrivate
operator|::
name|screen_list
operator|.
name|removeOne
argument_list|(
name|d
operator|->
name|screen
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|screen
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     \fn QPixmap QPlatformScreen::grabWindow(WId window, int x, int y, int width, int height) const      This function is called when Qt needs to be able to grab the content of a window.      Returnes the content of the window specified with the WId handle within the boundaries of     QRect(x,y,width,height). */
end_comment
begin_function
DECL|function|grabWindow
name|QPixmap
name|QPlatformScreen
operator|::
name|grabWindow
parameter_list|(
name|WId
name|window
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|width
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|height
argument_list|)
expr_stmt|;
return|return
name|QPixmap
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Return the given top level window for a given position.      Default implementation retrieves a list of all top level windows and finds the first window     which contains point \a pos */
end_comment
begin_function
DECL|function|topLevelAt
name|QWindow
modifier|*
name|QPlatformScreen
operator|::
name|topLevelAt
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
specifier|const
block|{
name|QWindowList
name|list
init|=
name|QGuiApplication
operator|::
name|topLevelWindows
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
name|list
operator|.
name|size
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|QWindow
modifier|*
name|w
init|=
name|list
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|w
operator|->
name|isVisible
argument_list|()
operator|&&
name|w
operator|->
name|geometry
argument_list|()
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
return|return
name|w
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a list of all the platform screens that are part of the same     virtual desktop.      Screens part of the same virtual desktop share a common coordinate system,     and windows can be freely moved between them. */
end_comment
begin_function
DECL|function|virtualSiblings
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|QPlatformScreen
operator|::
name|virtualSiblings
parameter_list|()
specifier|const
block|{
name|QList
argument_list|<
name|QPlatformScreen
modifier|*
argument_list|>
name|list
decl_stmt|;
name|list
operator|<<
cast|const_cast
argument_list|<
name|QPlatformScreen
operator|*
argument_list|>
argument_list|(
name|this
argument_list|)
expr_stmt|;
return|return
name|list
return|;
block|}
end_function
begin_function
DECL|function|screen
name|QScreen
modifier|*
name|QPlatformScreen
operator|::
name|screen
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QPlatformScreen
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|screen
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this function in subclass to return the physical size of the     screen, in millimeters. The physical size represents the actual physical     dimensions of the display.      The default implementation takes the pixel size of the screen, considers a     resolution of 100 dots per inch, and returns the calculated physical size.     A device with a screen that has different resolutions will need to be     supported by a suitable reimplementation of this function.      \sa logcalDpi */
end_comment
begin_function
DECL|function|physicalSize
name|QSizeF
name|QPlatformScreen
operator|::
name|physicalSize
parameter_list|()
specifier|const
block|{
specifier|static
specifier|const
name|int
name|dpi
init|=
literal|100
decl_stmt|;
return|return
name|QSizeF
argument_list|(
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
argument_list|)
operator|/
name|dpi
operator|*
name|qreal
argument_list|(
literal|25.4
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this function in subclass to return the logical horizontal     and vertical dots per inch metrics of the screen.      The logical dots per inch metrics are used by QFont to convert point sizes     to pixel sizes.      The default implementation uses the screen pixel size and physical size to     compute the metrics.      \sa physicalSize */
end_comment
begin_function
DECL|function|logicalDpi
name|QDpi
name|QPlatformScreen
operator|::
name|logicalDpi
parameter_list|()
specifier|const
block|{
name|QSizeF
name|ps
init|=
name|physicalSize
argument_list|()
decl_stmt|;
name|QSize
name|s
init|=
name|geometry
argument_list|()
operator|.
name|size
argument_list|()
decl_stmt|;
return|return
name|QDpi
argument_list|(
literal|25.4
operator|*
name|s
operator|.
name|width
argument_list|()
operator|/
name|ps
operator|.
name|width
argument_list|()
argument_list|,
literal|25.4
operator|*
name|s
operator|.
name|height
argument_list|()
operator|/
name|ps
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this function in subclass to return the device pixel     ratio for the screen. This is the ratio between physical pixels     and device-independent pixels.      \sa QPlatformWindow::devicePixelRatio(); */
end_comment
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QPlatformScreen
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
begin_comment
comment|/*!     Reimplement this function in subclass to return the vertical refresh rate     of the screen, in Hz.      The default returns 60, a sensible default for modern displays. */
end_comment
begin_function
DECL|function|refreshRate
name|qreal
name|QPlatformScreen
operator|::
name|refreshRate
parameter_list|()
specifier|const
block|{
return|return
literal|60
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this function in subclass to return the native orientation     of the screen, e.g. the orientation where the logo sticker of the device     appears the right way up.      The default implementation returns Qt::PrimaryOrientation. */
end_comment
begin_function
DECL|function|nativeOrientation
name|Qt
operator|::
name|ScreenOrientation
name|QPlatformScreen
operator|::
name|nativeOrientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_comment
comment|/*!     Reimplement this function in subclass to return the current orientation     of the screen, for example based on accelerometer data to determine     the device orientation.      The default implementation returns Qt::PrimaryOrientation. */
end_comment
begin_function
DECL|function|orientation
name|Qt
operator|::
name|ScreenOrientation
name|QPlatformScreen
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
return|return
name|Qt
operator|::
name|PrimaryOrientation
return|;
block|}
end_function
begin_comment
comment|/*     Reimplement this function in subclass to filter out unneeded screen     orientation updates.      The orientations will anyway be filtered before QScreen::orientationChanged()     is emitted, but the mask can be used by the platform plugin for example to     prevent having to have an accelerometer sensor running all the time, or to     improve the reported values. As an example of the latter, in case of only     Landscape | InvertedLandscape being set in the mask, on a platform that gets     its orientation readings from an accelerometer sensor embedded in a handheld     device, the platform can report transitions between the two even when the     device is held in an orientation that's closer to portrait.      By default, the orientation update mask is empty, so unless this function     has been called with a non-empty mask the platform does not need to report     any orientation updates through     QWindowSystemInterface::handleScreenOrientationChange(). */
end_comment
begin_function
DECL|function|setOrientationUpdateMask
name|void
name|QPlatformScreen
operator|::
name|setOrientationUpdateMask
parameter_list|(
name|Qt
operator|::
name|ScreenOrientations
name|mask
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|mask
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|platformScreenForWindow
name|QPlatformScreen
modifier|*
name|QPlatformScreen
operator|::
name|platformScreenForWindow
parameter_list|(
specifier|const
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
comment|// QTBUG 32681: It can happen during the transition between screens
comment|// when one screen is disconnected that the window doesn't have a screen.
if|if
condition|(
operator|!
name|window
operator|->
name|screen
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|window
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
comment|/*!     \class QPlatformScreen     \since 4.8     \internal     \preliminary     \ingroup qpa      \brief The QPlatformScreen class provides an abstraction for visual displays.      Many window systems has support for retrieving information on the attached displays. To be able     to query the display QPA uses QPlatformScreen. Qt its self is most dependent on the     physicalSize() function, since this is the function it uses to calculate the dpi to use when     converting point sizes to pixels sizes. However, this is unfortunate on some systems, as the     native system fakes its dpi size.      QPlatformScreen is also used by the public api QDesktopWidget for information about the desktop.  */
end_comment
begin_comment
comment|/*! \fn QRect QPlatformScreen::geometry() const = 0     Reimplement in subclass to return the pixel geometry of the screen */
end_comment
begin_comment
comment|/*! \fn QRect QPlatformScreen::availableGeometry() const     Reimplement in subclass to return the pixel geometry of the available space     This normally is the desktop screen minus the task manager, global menubar etc. */
end_comment
begin_comment
comment|/*! \fn int QPlatformScreen::depth() const = 0     Reimplement in subclass to return current depth of the screen */
end_comment
begin_comment
comment|/*! \fn QImage::Format QPlatformScreen::format() const = 0     Reimplement in subclass to return the image format which corresponds to the screen format */
end_comment
begin_comment
comment|/*!     Reimplement this function in subclass to return the cursor of the screen.      The default implementation returns 0. */
end_comment
begin_function
DECL|function|cursor
name|QPlatformCursor
modifier|*
name|QPlatformScreen
operator|::
name|cursor
parameter_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!   Convenience method to resize all the maximized and fullscreen windows   of this platform screen. */
end_comment
begin_function
DECL|function|resizeMaximizedWindows
name|void
name|QPlatformScreen
operator|::
name|resizeMaximizedWindows
parameter_list|()
block|{
name|QList
argument_list|<
name|QWindow
modifier|*
argument_list|>
name|windows
init|=
name|QGuiApplication
operator|::
name|allWindows
argument_list|()
decl_stmt|;
comment|// 'screen()' still has the old geometry info while 'this' has the new geometry info
specifier|const
name|QRect
name|oldGeometry
init|=
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|oldAvailableGeometry
init|=
name|screen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|newGeometry
init|=
name|geometry
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|newAvailableGeometry
init|=
name|availableGeometry
argument_list|()
decl_stmt|;
comment|// make sure maximized and fullscreen windows are updated
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|windows
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QWindow
modifier|*
name|w
init|=
name|windows
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|platformScreenForWindow
argument_list|(
name|w
argument_list|)
operator|!=
name|this
condition|)
continue|continue;
if|if
condition|(
name|w
operator|->
name|windowState
argument_list|()
operator|&
name|Qt
operator|::
name|WindowFullScreen
operator|||
name|w
operator|->
name|geometry
argument_list|()
operator|==
name|oldGeometry
condition|)
name|w
operator|->
name|setGeometry
argument_list|(
name|newGeometry
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|w
operator|->
name|windowState
argument_list|()
operator|&
name|Qt
operator|::
name|WindowMaximized
operator|||
name|w
operator|->
name|geometry
argument_list|()
operator|==
name|oldAvailableGeometry
condition|)
name|w
operator|->
name|setGeometry
argument_list|(
name|newAvailableGeometry
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
