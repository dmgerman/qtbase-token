begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBBSCREEN_H
end_ifndef
begin_define
DECL|macro|QBBSCREEN_H
define|#
directive|define
name|QBBSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|"qqnxrootwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QObject>
end_include
begin_include
include|#
directive|include
file|<QtCore/QScopedPointer>
end_include
begin_include
include|#
directive|include
file|<screen/screen.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxWindow
name|class
name|QQnxWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QQnxScreen
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QPlatformScreen
block|{
name|Q_OBJECT
name|public
range|:
name|QQnxScreen
argument_list|(
argument|screen_context_t context
argument_list|,
argument|screen_display_t display
argument_list|,
argument|bool primaryScreen
argument_list|)
decl_stmt|;
operator|~
name|QQnxScreen
argument_list|()
expr_stmt|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|{
return|return
name|m_currentGeometry
return|;
block|}
name|QRect
name|availableGeometry
argument_list|()
specifier|const
expr_stmt|;
name|int
name|depth
argument_list|()
specifier|const
expr_stmt|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|{
return|return
operator|(
name|depth
argument_list|()
operator|==
literal|32
operator|)
operator|?
name|QImage
operator|::
name|Format_RGB32
operator|:
name|QImage
operator|::
name|Format_RGB16
return|;
block|}
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
block|{
return|return
name|m_currentPhysicalSize
return|;
block|}
name|qreal
name|refreshRate
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isPrimaryScreen
argument_list|()
specifier|const
block|{
return|return
name|m_primaryScreen
return|;
block|}
name|int
name|rotation
argument_list|()
specifier|const
block|{
return|return
name|m_currentRotation
return|;
block|}
name|int
name|nativeFormat
argument_list|()
specifier|const
block|{
return|return
operator|(
name|depth
argument_list|()
operator|==
literal|32
operator|)
operator|?
name|SCREEN_FORMAT_RGBA8888
operator|:
name|SCREEN_FORMAT_RGB565
return|;
block|}
name|screen_display_t
name|nativeDisplay
argument_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
name|screen_context_t
name|nativeContext
argument_list|()
specifier|const
block|{
return|return
name|m_screenContext
return|;
block|}
specifier|const
name|char
operator|*
name|windowGroupName
argument_list|()
specifier|const
block|{
return|return
name|rootWindow
argument_list|()
operator|->
name|groupName
argument_list|()
operator|.
name|constData
argument_list|()
return|;
block|}
name|QQnxWindow
modifier|*
name|findWindow
parameter_list|(
name|screen_window_t
name|windowHandle
parameter_list|)
function_decl|;
comment|/* Window hierarchy management */
name|void
name|addWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|child
parameter_list|)
function_decl|;
name|void
name|removeWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|child
parameter_list|)
function_decl|;
name|void
name|raiseWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|lowerWindow
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|updateHierarchy
parameter_list|()
function_decl|;
name|void
name|onWindowPost
parameter_list|(
name|QQnxWindow
modifier|*
name|window
parameter_list|)
function_decl|;
name|QSharedPointer
operator|<
name|QQnxRootWindow
operator|>
name|rootWindow
argument_list|()
specifier|const
expr_stmt|;
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
expr_stmt|;
name|public
name|Q_SLOTS
range|:
name|void
name|setRotation
argument_list|(
argument|int rotation
argument_list|)
decl_stmt|;
name|void
name|newWindowCreated
parameter_list|(
name|void
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|windowClosed
parameter_list|(
name|void
modifier|*
name|window
parameter_list|)
function_decl|;
name|void
name|windowGroupStateChanged
argument_list|(
specifier|const
name|QByteArray
operator|&
name|id
argument_list|,
name|Qt
operator|::
name|WindowState
name|state
argument_list|)
decl_stmt|;
name|void
name|activateWindowGroup
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
function_decl|;
name|void
name|deactivateWindowGroup
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|id
parameter_list|)
function_decl|;
name|private
name|Q_SLOTS
range|:
name|void
name|keyboardHeightChanged
argument_list|(
argument|int height
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|resizeNativeWidgetWindow
argument_list|(
name|QQnxWindow
operator|*
name|w
argument_list|,
specifier|const
name|QRect
operator|&
name|previousScreenGeometry
argument_list|)
decl|const
decl_stmt|;
name|void
name|resizeTopLevelWindow
argument_list|(
name|QQnxWindow
operator|*
name|w
argument_list|,
specifier|const
name|QRect
operator|&
name|previousScreenGeometry
argument_list|)
decl|const
decl_stmt|;
name|void
name|resizeWindows
parameter_list|(
specifier|const
name|QRect
modifier|&
name|previousScreenGeometry
parameter_list|)
function_decl|;
name|void
name|addOverlayWindow
parameter_list|(
name|screen_window_t
name|window
parameter_list|)
function_decl|;
name|void
name|removeOverlayWindow
parameter_list|(
name|screen_window_t
name|window
parameter_list|)
function_decl|;
name|QWindow
operator|*
name|topMostChildWindow
argument_list|()
specifier|const
expr_stmt|;
name|screen_context_t
name|m_screenContext
decl_stmt|;
name|screen_display_t
name|m_display
decl_stmt|;
name|mutable
name|QSharedPointer
operator|<
name|QQnxRootWindow
operator|>
name|m_rootWindow
expr_stmt|;
specifier|const
name|bool
name|m_primaryScreen
decl_stmt|;
name|bool
name|m_posted
decl_stmt|;
name|int
name|m_initialRotation
decl_stmt|;
name|int
name|m_currentRotation
decl_stmt|;
name|int
name|m_keyboardHeight
decl_stmt|;
name|QSize
name|m_initialPhysicalSize
decl_stmt|;
name|QSize
name|m_currentPhysicalSize
decl_stmt|;
name|Qt
operator|::
name|ScreenOrientation
name|m_nativeOrientation
expr_stmt|;
name|QRect
name|m_initialGeometry
decl_stmt|;
name|QRect
name|m_currentGeometry
decl_stmt|;
name|QPlatformOpenGLContext
modifier|*
name|m_platformContext
decl_stmt|;
name|QList
operator|<
name|QQnxWindow
operator|*
operator|>
name|m_childWindows
expr_stmt|;
name|QList
operator|<
name|screen_window_t
operator|>
name|m_overlays
expr_stmt|;
name|QPlatformCursor
modifier|*
name|m_cursor
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBBSCREEN_H
end_comment
end_unit
