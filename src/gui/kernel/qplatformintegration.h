begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINTEGRATION_H
define|#
directive|define
name|QPLATFORMINTEGRATION_H
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
comment|// This file is part of the QPA API and is not meant to be used
end_comment
begin_comment
comment|// in applications. Usage of this API may make your code
end_comment
begin_comment
comment|// source and binary incompatible with future versions of Qt.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qsurfaceformat.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPlatformWindow
name|class
name|QPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformBackingStore
name|class
name|QPlatformBackingStore
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformFontDatabase
name|class
name|QPlatformFontDatabase
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformClipboard
name|class
name|QPlatformClipboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformNativeInterface
name|class
name|QPlatformNativeInterface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDrag
name|class
name|QPlatformDrag
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformOpenGLContext
name|class
name|QPlatformOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGuiGLFormat
name|class
name|QGuiGLFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractEventDispatcher
name|class
name|QAbstractEventDispatcher
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformInputContext
name|class
name|QPlatformInputContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformAccessibility
name|class
name|QPlatformAccessibility
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformTheme
name|class
name|QPlatformTheme
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformDialogHelper
name|class
name|QPlatformDialogHelper
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformSharedGraphicsCache
name|class
name|QPlatformSharedGraphicsCache
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformServices
name|class
name|QPlatformServices
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformSessionManager
name|class
name|QPlatformSessionManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformOffscreenSurface
name|class
name|QPlatformOffscreenSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOffscreenSurface
name|class
name|QOffscreenSurface
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPlatformIntegration
block|{
name|public
label|:
enum|enum
name|Capability
block|{
name|ThreadedPixmaps
init|=
literal|1
block|,
name|OpenGL
block|,
name|ThreadedOpenGL
block|,
name|SharedGraphicsCache
block|,
name|BufferQueueingOpenGL
block|,
name|WindowMasks
block|,
name|MultipleWindows
block|,
name|ApplicationState
block|,
name|ForeignWindows
block|,
name|NonFullScreenWindows
block|,
name|NativeWidgets
block|,
name|WindowManagement
block|}
enum|;
name|virtual
operator|~
name|QPlatformIntegration
argument_list|()
block|{ }
name|virtual
name|bool
name|hasCapability
argument_list|(
argument|Capability cap
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|QPlatformPixmap
modifier|*
name|createPlatformPixmap
argument_list|(
name|QPlatformPixmap
operator|::
name|PixelType
name|type
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
name|virtual
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|virtual
name|QPlatformSharedGraphicsCache
modifier|*
name|createPlatformSharedGraphicsCache
argument_list|(
specifier|const
name|char
operator|*
name|cacheId
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPaintEngine
modifier|*
name|createImagePaintEngine
argument_list|(
name|QPaintDevice
operator|*
name|paintDevice
argument_list|)
decl|const
decl_stmt|;
comment|// Event dispatcher:
name|virtual
name|QAbstractEventDispatcher
operator|*
name|guiThreadEventDispatcher
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//Deeper window system integrations
name|virtual
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
name|virtual
name|QPlatformClipboard
operator|*
name|clipboard
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
name|virtual
name|QPlatformDrag
operator|*
name|drag
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|virtual
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
name|virtual
name|QPlatformAccessibility
operator|*
name|accessibility
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
comment|// Access native handles. The window handle is already available from Wid;
name|virtual
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|StyleHint
block|{
name|CursorFlashTime
block|,
name|KeyboardInputInterval
block|,
name|MouseDoubleClickInterval
block|,
name|StartDragDistance
block|,
name|StartDragTime
block|,
name|KeyboardAutoRepeatRate
block|,
name|ShowIsFullScreen
block|,
name|PasswordMaskDelay
block|,
name|FontSmoothingGamma
block|,
name|StartDragVelocity
block|,
name|UseRtlExtensions
block|,
name|SynthesizeMouseFromTouchEvents
block|,
name|PasswordMaskCharacter
block|,
name|SetFocusOnTouchRelease
block|}
enum|;
name|virtual
name|QVariant
name|styleHint
argument_list|(
name|StyleHint
name|hint
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *
argument_list|)
specifier|const
expr_stmt|;
name|virtual
name|QStringList
name|themeNames
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|QPlatformTheme
modifier|*
name|createPlatformTheme
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
decl|const
decl_stmt|;
name|virtual
name|QPlatformOffscreenSurface
modifier|*
name|createPlatformOffscreenSurface
argument_list|(
name|QOffscreenSurface
operator|*
name|surface
argument_list|)
decl|const
decl_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_SESSIONMANAGER
name|virtual
name|QPlatformSessionManager
modifier|*
name|createPlatformSessionManager
argument_list|(
specifier|const
name|QString
operator|&
name|id
argument_list|,
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
decl_stmt|;
endif|#
directive|endif
name|protected
label|:
name|void
name|screenAdded
parameter_list|(
name|QPlatformScreen
modifier|*
name|screen
parameter_list|)
function_decl|;
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
comment|// QPLATFORMINTEGRATION_H
end_comment
end_unit
