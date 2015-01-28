begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINRTSCREEN_H
end_ifndef
begin_define
DECL|macro|QWINRTSCREEN_H
define|#
directive|define
name|QWINRTSCREEN_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatformscreen.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qwindowsysteminterface.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_decl_stmt
name|namespace
name|ABI
block|{
name|namespace
name|Windows
block|{
name|namespace
name|ApplicationModel
block|{
struct_decl|struct
name|ISuspendingEventArgs
struct_decl|;
block|}
name|namespace
name|UI
block|{
name|namespace
name|Core
block|{
struct_decl|struct
name|IAutomationProviderRequestedEventArgs
struct_decl|;
struct_decl|struct
name|ICharacterReceivedEventArgs
struct_decl|;
struct_decl|struct
name|ICoreWindow
struct_decl|;
struct_decl|struct
name|ICoreWindowEventArgs
struct_decl|;
struct_decl|struct
name|IKeyEventArgs
struct_decl|;
struct_decl|struct
name|IPointerEventArgs
struct_decl|;
struct_decl|struct
name|IVisibilityChangedEventArgs
struct_decl|;
struct_decl|struct
name|IWindowActivatedEventArgs
struct_decl|;
struct_decl|struct
name|IWindowSizeChangedEventArgs
struct_decl|;
block|}
block|}
name|namespace
name|Graphics
block|{
name|namespace
name|Display
block|{
struct_decl|struct
name|IDisplayInformation
struct_decl|;
block|}
block|}
ifdef|#
directive|ifdef
name|Q_OS_WINPHONE
name|namespace
name|Phone
block|{
name|namespace
name|UI
block|{
name|namespace
name|Input
block|{
struct_decl|struct
name|IBackPressedEventArgs
struct_decl|;
block|}
block|}
block|}
endif|#
directive|endif
block|}
block|}
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|IInspectable
struct_decl|;
end_struct_decl
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QTouchDevice
name|class
name|QTouchDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTEGLContext
name|class
name|QWinRTEGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTCursor
name|class
name|QWinRTCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTInputContext
name|class
name|QWinRTInputContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWinRTScreenPrivate
name|class
name|QWinRTScreenPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QWinRTScreen
range|:
name|public
name|QPlatformScreen
block|{
name|public
operator|:
name|explicit
name|QWinRTScreen
argument_list|()
block|;
operator|~
name|QWinRTScreen
argument_list|()
block|;
name|QRect
name|geometry
argument_list|()
specifier|const
block|;
name|int
name|depth
argument_list|()
specifier|const
block|;
name|QImage
operator|::
name|Format
name|format
argument_list|()
specifier|const
block|;
name|QSurfaceFormat
name|surfaceFormat
argument_list|()
specifier|const
block|;
name|QSizeF
name|physicalSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QDpi
name|logicalDpi
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QWinRTInputContext
operator|*
name|inputContext
argument_list|()
specifier|const
block|;
name|QPlatformCursor
operator|*
name|cursor
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|keyboardModifiers
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScreenOrientation
name|nativeOrientation
argument_list|()
specifier|const
block|;
name|Qt
operator|::
name|ScreenOrientation
name|orientation
argument_list|()
specifier|const
block|;
name|QWindow
operator|*
name|topWindow
argument_list|()
specifier|const
block|;
name|void
name|addWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|removeWindow
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|raise
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|void
name|lower
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
name|coreWindow
argument_list|()
specifier|const
block|;
name|EGLDisplay
name|eglDisplay
argument_list|()
specifier|const
block|;
comment|// To opengl context
name|EGLSurface
name|eglSurface
argument_list|()
specifier|const
block|;
comment|// To window
name|EGLConfig
name|eglConfig
argument_list|()
specifier|const
block|;
name|private
operator|:
name|void
name|handleExpose
argument_list|()
block|;
name|HRESULT
name|onKeyDown
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IKeyEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onKeyUp
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IKeyEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onCharacterReceived
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICharacterReceivedEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onPointerEntered
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IPointerEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onPointerExited
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IPointerEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onPointerUpdated
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IPointerEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onSizeChanged
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IWindowSizeChangedEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onActivated
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IWindowActivatedEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onSuspended
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|ISuspendingEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onResume
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|IInspectable
operator|*
argument_list|)
block|;
name|HRESULT
name|onClosed
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindowEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onVisibilityChanged
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IVisibilityChangedEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onAutomationProviderRequested
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|IAutomationProviderRequestedEventArgs
operator|*
argument_list|)
block|;
name|HRESULT
name|onOrientationChanged
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Graphics
operator|::
name|Display
operator|::
name|IDisplayInformation
operator|*
argument_list|,
name|IInspectable
operator|*
argument_list|)
block|;
name|HRESULT
name|onDpiChanged
argument_list|(
name|ABI
operator|::
name|Windows
operator|::
name|Graphics
operator|::
name|Display
operator|::
name|IDisplayInformation
operator|*
argument_list|,
name|IInspectable
operator|*
argument_list|)
block|;
ifdef|#
directive|ifdef
name|Q_OS_WINPHONE
name|HRESULT
name|onBackButtonPressed
argument_list|(
name|IInspectable
operator|*
argument_list|,
name|ABI
operator|::
name|Windows
operator|::
name|Phone
operator|::
name|UI
operator|::
name|Input
operator|::
name|IBackPressedEventArgs
operator|*
name|args
argument_list|)
block|;
endif|#
directive|endif
name|QScopedPointer
operator|<
name|QWinRTScreenPrivate
operator|>
name|d_ptr
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QWinRTScreen
argument_list|)
block|}
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
comment|// QWINRTSCREEN_H
end_comment
end_unit
