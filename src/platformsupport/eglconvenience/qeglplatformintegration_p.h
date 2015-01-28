begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QEGLPLATFORMINTEGRATION_H
end_ifndef
begin_define
DECL|macro|QEGLPLATFORMINTEGRATION_H
define|#
directive|define
name|QEGLPLATFORMINTEGRATION_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|<QtCore/QVariant>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QEGLPlatformWindow
name|class
name|QEGLPlatformWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEGLPlatformContext
name|class
name|QEGLPlatformContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFbVtHandler
name|class
name|QFbVtHandler
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QEvdevKeyboardManager
name|class
name|QEvdevKeyboardManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformIntegration
name|class
name|QEGLPlatformIntegration
range|:
name|public
name|QPlatformIntegration
decl_stmt|,
name|public
name|QPlatformNativeInterface
block|{
name|public
label|:
name|QEGLPlatformIntegration
argument_list|()
expr_stmt|;
operator|~
name|QEGLPlatformIntegration
argument_list|()
expr_stmt|;
name|void
name|initialize
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|void
name|destroy
argument_list|()
name|Q_DECL_OVERRIDE
expr_stmt|;
name|EGLDisplay
name|display
argument_list|()
specifier|const
block|{
return|return
name|m_display
return|;
block|}
name|QAbstractEventDispatcher
operator|*
name|createEventDispatcher
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformFontDatabase
operator|*
name|fontDatabase
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformServices
operator|*
name|services
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
name|QPlatformInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|{
return|return
name|m_inputContext
return|;
block|}
name|QPlatformWindow
modifier|*
name|createPlatformWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformBackingStore
modifier|*
name|createPlatformBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformOpenGLContext
modifier|*
name|createPlatformOpenGLContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformOffscreenSurface
modifier|*
name|createPlatformOffscreenSurface
argument_list|(
name|QOffscreenSurface
operator|*
name|surface
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|bool
name|hasCapability
argument_list|(
name|QPlatformIntegration
operator|::
name|Capability
name|cap
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QPlatformNativeInterface
operator|*
name|nativeInterface
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
expr_stmt|;
comment|// QPlatformNativeInterface
name|void
modifier|*
name|nativeResourceForIntegration
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
modifier|*
name|nativeResourceForScreen
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QScreen
operator|*
name|screen
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
modifier|*
name|nativeResourceForWindow
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QWindow
operator|*
name|window
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|void
modifier|*
name|nativeResourceForContext
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|,
name|QOpenGLContext
operator|*
name|context
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|NativeResourceForContextFunction
name|nativeResourceFunctionForContext
argument_list|(
specifier|const
name|QByteArray
operator|&
name|resource
argument_list|)
name|Q_DECL_OVERRIDE
decl_stmt|;
name|QFunctionPointer
name|platformFunction
argument_list|(
specifier|const
name|QByteArray
operator|&
name|function
argument_list|)
decl|const
name|Q_DECL_OVERRIDE
decl_stmt|;
name|protected
label|:
name|virtual
name|QEGLPlatformWindow
modifier|*
name|createWindow
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
name|QEGLPlatformContext
modifier|*
name|createContext
argument_list|(
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QPlatformOpenGLContext
operator|*
name|shareContext
argument_list|,
name|EGLDisplay
name|display
argument_list|,
name|QVariant
operator|*
name|nativeHandle
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|QPlatformOffscreenSurface
modifier|*
name|createOffscreenSurface
argument_list|(
name|EGLDisplay
name|display
argument_list|,
specifier|const
name|QSurfaceFormat
operator|&
name|format
argument_list|,
name|QOffscreenSurface
operator|*
name|surface
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|EGLNativeDisplayType
name|nativeDisplay
argument_list|()
specifier|const
block|{
return|return
name|EGL_DEFAULT_DISPLAY
return|;
block|}
name|void
name|createInputHandlers
parameter_list|()
function_decl|;
name|private
label|:
specifier|static
name|void
name|loadKeymapStatic
parameter_list|(
specifier|const
name|QString
modifier|&
name|filename
parameter_list|)
function_decl|;
name|EGLDisplay
name|m_display
decl_stmt|;
name|QPlatformInputContext
modifier|*
name|m_inputContext
decl_stmt|;
name|QScopedPointer
operator|<
name|QPlatformFontDatabase
operator|>
name|m_fontDb
expr_stmt|;
name|QScopedPointer
operator|<
name|QPlatformServices
operator|>
name|m_services
expr_stmt|;
name|QScopedPointer
operator|<
name|QFbVtHandler
operator|>
name|m_vtHandler
expr_stmt|;
name|QEvdevKeyboardManager
modifier|*
name|m_kbdMgr
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
comment|// QEGLPLATFORMINTEGRATION_H
end_comment
end_unit
