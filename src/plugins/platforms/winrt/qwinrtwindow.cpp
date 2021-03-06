begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|<private/qeventdispatcher_winrt_p.h>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_include
include|#
directive|include
file|<EGL/eglext.h>
end_include
begin_include
include|#
directive|include
file|<qfunctions_winrt.h>
end_include
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
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<functional>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.h>
end_include
begin_include
include|#
directive|include
file|<windows.foundation.collections.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.xaml.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.xaml.controls.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.viewmanagement.h>
end_include
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|ViewManagement
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
operator|::
name|Collections
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Xaml
operator|::
name|Controls
namespace|;
end_using
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcQpaWindows
argument_list|,
literal|"qt.qpa.windows"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|setUIElementVisibility
specifier|static
name|void
name|setUIElementVisibility
parameter_list|(
name|IUIElement
modifier|*
name|uiElement
parameter_list|,
name|bool
name|visibility
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|uiElement
argument_list|)
expr_stmt|;
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|uiElement
capture|,
name|visibility
capture|]
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|uiElement
operator|->
name|put_Visibility
argument_list|(
name|visibility
condition|?
name|Visibility_Visible
else|:
name|Visibility_Collapsed
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|QWinRTWindowPrivate
class|class
name|QWinRTWindowPrivate
block|{
public|public:
DECL|member|screen
name|QWinRTScreen
modifier|*
name|screen
decl_stmt|;
DECL|member|surfaceFormat
name|QSurfaceFormat
name|surfaceFormat
decl_stmt|;
DECL|member|windowTitle
name|QString
name|windowTitle
decl_stmt|;
DECL|member|state
name|Qt
operator|::
name|WindowState
name|state
decl_stmt|;
DECL|member|display
name|EGLDisplay
name|display
decl_stmt|;
DECL|member|surface
name|EGLSurface
name|surface
decl_stmt|;
DECL|member|swapChainPanel
name|ComPtr
argument_list|<
name|ISwapChainPanel
argument_list|>
name|swapChainPanel
decl_stmt|;
DECL|member|canvas
name|ComPtr
argument_list|<
name|ICanvasStatics
argument_list|>
name|canvas
decl_stmt|;
DECL|member|uiElement
name|ComPtr
argument_list|<
name|IUIElement
argument_list|>
name|uiElement
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWinRTWindow
name|QWinRTWindow
operator|::
name|QWinRTWindow
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformWindow
argument_list|(
name|window
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QWinRTWindowPrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
name|d
operator|->
name|surface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
name|d
operator|->
name|display
operator|=
name|EGL_NO_DISPLAY
expr_stmt|;
name|d
operator|->
name|screen
operator|=
cast|static_cast
argument_list|<
name|QWinRTScreen
operator|*
argument_list|>
argument_list|(
name|screen
argument_list|()
argument_list|)
expr_stmt|;
name|handleContentOrientationChange
argument_list|(
name|window
operator|->
name|contentOrientation
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setAlphaBufferSize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setRedBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setGreenBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setBlueBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setDepthBufferSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setStencilBufferSize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setRenderableType
argument_list|(
name|QSurfaceFormat
operator|::
name|OpenGLES
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setSamples
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|d
operator|->
name|surfaceFormat
operator|.
name|setSwapBehavior
argument_list|(
name|QSurfaceFormat
operator|::
name|DoubleBuffer
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_Xaml_Controls_Canvas
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|d
operator|->
name|canvas
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|this
capture|,
name|d
capture|]
parameter_list|()
block|{
comment|// Create a new swapchain and place it inside the canvas
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|RoActivateInstance
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_Xaml_Controls_SwapChainPanel
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|d
operator|->
name|swapChainPanel
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|d
operator|->
name|swapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|d
operator|->
name|uiElement
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|Xaml
operator|::
name|IFrameworkElement
argument_list|>
name|frameworkElement
decl_stmt|;
name|hr
operator|=
name|d
operator|->
name|swapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|frameworkElement
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
specifier|const
name|QSizeF
name|size
type|=
name|QSizeF
type|(
name|d
operator|->
name|screen
operator|->
name|geometry
type|(
decl_stmt|).size(
block|)
argument_list|)
operator|/
name|d
operator|->
name|screen
operator|->
name|scaleFactor
argument_list|()
expr_stmt|;
name|hr
operator|=
name|frameworkElement
operator|->
name|put_Width
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|frameworkElement
operator|->
name|put_Height
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IDependencyObject
argument_list|>
name|canvas
init|=
name|d
operator|->
name|screen
operator|->
name|canvas
argument_list|()
decl_stmt|;
name|ComPtr
argument_list|<
name|IPanel
argument_list|>
name|panel
decl_stmt|;
name|hr
operator|=
name|canvas
operator|.
name|As
argument_list|(
operator|&
name|panel
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IVector
argument_list|<
name|UIElement
modifier|*
argument_list|>
argument_list|>
name|children
decl_stmt|;
name|hr
operator|=
name|panel
operator|->
name|get_Children
argument_list|(
operator|&
name|children
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|children
operator|->
name|Append
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
end_constructor
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|setWindowFlags
argument_list|(
name|window
operator|->
name|flags
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|setWindowState
argument_list|(
name|window
operator|->
name|windowState
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|setWindowTitle
argument_list|(
name|window
operator|->
name|title
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|setGeometry
argument_list|(
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_destructor
unit|}  QWinRTWindow
DECL|function|~QWinRTWindow
operator|::
name|~
name|QWinRTWindow
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|d
capture|]
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|IDependencyObject
argument_list|>
name|canvas
type|=
name|d
operator|->
name|screen
operator|->
name|canvas
type|(
decl_stmt|);
name|ComPtr
argument_list|<
name|IPanel
argument_list|>
name|panel
decl_stmt|;
name|hr
operator|=
name|canvas
operator|.
name|As
argument_list|(
operator|&
name|panel
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|ComPtr
argument_list|<
name|IVector
argument_list|<
name|UIElement
operator|*
argument_list|>
argument_list|>
name|children
decl_stmt|;
name|hr
operator|=
name|panel
operator|->
name|get_Children
argument_list|(
operator|&
name|children
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|quint32
name|index
decl_stmt|;
name|boolean
name|found
decl_stmt|;
name|hr
operator|=
name|children
operator|->
name|IndexOf
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|index
argument_list|,
operator|&
name|found
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
if|if
condition|(
name|found
condition|)
block|{
name|hr
operator|=
name|children
operator|->
name|RemoveAt
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
block|}
return|return
name|S_OK
return|;
block|}
argument_list|)
expr_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to completely destroy window resources, likely because the application is shutting down"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|surface
condition|)
return|return;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|": Destroying surface"
expr_stmt|;
name|EGLBoolean
name|value
init|=
name|eglDestroySurface
argument_list|(
name|d
operator|->
name|display
argument_list|,
name|d
operator|->
name|surface
argument_list|)
decl_stmt|;
name|d
operator|->
name|surface
operator|=
name|EGL_NO_SURFACE
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|value
operator|==
name|EGL_FALSE
argument_list|)
condition|)
name|qCritical
argument_list|(
literal|"Failed to destroy EGL window surface: 0x%x"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|format
name|QSurfaceFormat
name|QWinRTWindow
operator|::
name|format
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|surfaceFormat
return|;
block|}
end_function
begin_function
DECL|function|isActive
name|bool
name|QWinRTWindow
operator|::
name|isActive
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|screen
operator|->
name|topWindow
argument_list|()
operator|==
name|window
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isExposed
name|bool
name|QWinRTWindow
operator|::
name|isExposed
parameter_list|()
specifier|const
block|{
specifier|const
name|bool
name|exposed
init|=
name|isActive
argument_list|()
decl_stmt|;
return|return
name|exposed
return|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|QWinRTWindow
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
name|QWinRTWindow
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|rect
expr_stmt|;
specifier|const
name|Qt
operator|::
name|WindowFlags
name|windowFlags
init|=
name|window
argument_list|()
operator|->
name|flags
argument_list|()
decl_stmt|;
specifier|const
name|Qt
operator|::
name|WindowFlags
name|windowType
init|=
name|windowFlags
operator|&
name|Qt
operator|::
name|WindowType_Mask
decl_stmt|;
if|if
condition|(
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
operator|&&
operator|(
name|windowType
operator|==
name|Qt
operator|::
name|Window
operator|||
name|windowType
operator|==
name|Qt
operator|::
name|Dialog
operator|)
condition|)
block|{
specifier|const
name|QRect
name|screenRect
init|=
name|windowFlags
operator|&
name|Qt
operator|::
name|MaximizeUsingFullscreenGeometryHint
condition|?
name|d
operator|->
name|screen
operator|->
name|geometry
argument_list|()
else|:
name|d
operator|->
name|screen
operator|->
name|availableGeometry
argument_list|()
decl_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|"top-level, overwrite"
operator|<<
name|screenRect
expr_stmt|;
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|screenRect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QPlatformWindow
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QWindowSystemInterface
operator|::
name|handleGeometryChange
argument_list|(
name|window
argument_list|()
argument_list|,
name|rect
argument_list|)
expr_stmt|;
block|}
name|HRESULT
name|hr
decl_stmt|;
name|hr
operator|=
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|this
capture|,
name|d
capture|]
parameter_list|()
block|{
name|HRESULT
name|hr
decl_stmt|;
specifier|const
name|QRect
name|windowGeometry
type|=
name|geometry
type|(
decl_stmt|);
specifier|const
name|QPointF
name|topLeft
type|=
name|QPointF
type|(
name|windowGeometry
operator|.
name|topLeft
type|(
decl_stmt|)
block|)
lambda|/
name|d
lambda|->
name|screen
operator|->
name|scaleFactor
parameter_list|()
argument_list|;
name|hr
operator|=
name|d
operator|->
name|canvas
operator|->
name|SetTop
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
name|topLeft
operator|.
name|y
argument_list|()
argument_list|)
argument_list|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|;
name|hr
operator|=
name|d
operator|->
name|canvas
operator|->
name|SetLeft
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
name|topLeft
operator|.
name|x
argument_list|()
argument_list|)
argument_list|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|;
name|ComPtr
argument_list|<
name|Xaml
operator|::
name|IFrameworkElement
argument_list|>
name|frameworkElement
argument_list|;
name|hr
operator|=
name|d
operator|->
name|swapChainPanel
operator|.
name|As
argument_list|(
operator|&
name|frameworkElement
argument_list|)
argument_list|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|;
specifier|const
name|QSizeF
name|size
operator|=
name|QSizeF
argument_list|(
name|windowGeometry
operator|.
name|size
argument_list|()
argument_list|)
operator|/
name|d
operator|->
name|screen
operator|->
name|scaleFactor
argument_list|()
argument_list|;
name|hr
operator|=
name|frameworkElement
operator|->
name|put_Width
argument_list|(
name|size
operator|.
name|width
argument_list|()
argument_list|)
argument_list|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|;
name|hr
operator|=
name|frameworkElement
operator|->
name|put_Height
argument_list|(
name|size
operator|.
name|height
argument_list|()
argument_list|)
argument_list|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
argument_list|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
literal|"(setGeometry Xaml)"
operator|<<
name|this
operator|<<
name|topLeft
operator|<<
name|size
argument_list|;         return
name|S_OK
argument_list|;
block|}
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  void
DECL|function|setVisible
name|QWinRTWindow
end_macro
begin_expr_stmt
DECL|function|setVisible
operator|::
name|setVisible
operator|(
name|bool
name|visible
operator|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
block|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|visible
block|;
if|if
condition|(
operator|!
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
return|return;
end_expr_stmt
begin_if
if|if
condition|(
name|visible
condition|)
block|{
name|d
operator|->
name|screen
operator|->
name|addWindow
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
name|setUIElementVisibility
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
name|d
operator|->
name|state
operator|!=
name|Qt
operator|::
name|WindowMinimized
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|screen
operator|->
name|removeWindow
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
name|setUIElementVisibility
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
end_if
begin_macro
unit|}  void
DECL|function|setWindowTitle
name|QWinRTWindow
end_macro
begin_expr_stmt
DECL|function|setWindowTitle
operator|::
name|setWindowTitle
operator|(
specifier|const
name|QString
operator|&
name|title
operator|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
block|;
name|d
operator|->
name|windowTitle
operator|=
name|title
block|;
name|d
operator|->
name|screen
operator|->
name|updateWindowTitle
argument_list|()
block|; }
DECL|function|raise
name|void
name|QWinRTWindow
operator|::
name|raise
operator|(
operator|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
block|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
block|;
if|if
condition|(
operator|!
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
return|return;
name|d
operator|->
name|screen
operator|->
name|raise
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  void
DECL|function|lower
name|QWinRTWindow
end_macro
begin_expr_stmt
DECL|function|lower
operator|::
name|lower
operator|(
operator|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
block|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
block|;
if|if
condition|(
operator|!
name|window
argument_list|()
operator|->
name|isTopLevel
argument_list|()
condition|)
return|return;
name|d
operator|->
name|screen
operator|->
name|lower
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
unit|}  WId
DECL|function|winId
name|QWinRTWindow
end_macro
begin_expr_stmt
DECL|function|winId
operator|::
name|winId
operator|(
operator|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTWindow
argument_list|)
block|;
return|return
name|WId
argument_list|(
name|d
operator|->
name|swapChainPanel
operator|.
name|Get
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|devicePixelRatio
name|qreal
name|QWinRTWindow
operator|::
name|devicePixelRatio
parameter_list|()
specifier|const
block|{
return|return
name|screen
argument_list|()
operator|->
name|devicePixelRatio
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setWindowState
name|void
name|QWinRTWindow
operator|::
name|setWindowState
parameter_list|(
name|Qt
operator|::
name|WindowState
name|state
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
expr_stmt|;
name|qCDebug
argument_list|(
name|lcQpaWindows
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|state
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|state
condition|)
return|return;
if|if
condition|(
name|state
operator|==
name|Qt
operator|::
name|WindowMinimized
condition|)
name|setUIElementVisibility
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
literal|false
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|state
operator|==
name|Qt
operator|::
name|WindowMinimized
condition|)
name|setUIElementVisibility
argument_list|(
name|d
operator|->
name|uiElement
operator|.
name|Get
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|d
operator|->
name|state
operator|=
name|state
expr_stmt|;
block|}
end_function
begin_function
DECL|function|eglSurface
name|EGLSurface
name|QWinRTWindow
operator|::
name|eglSurface
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTWindow
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|surface
return|;
block|}
end_function
begin_function
DECL|function|createEglSurface
name|void
name|QWinRTWindow
operator|::
name|createEglSurface
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLConfig
name|config
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTWindow
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|surface
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|d
operator|->
name|display
operator|=
name|display
expr_stmt|;
name|QEventDispatcherWinRT
operator|::
name|runOnXamlThread
argument_list|(
capture|[
name|this
capture|,
name|d
capture|,
name|display
capture|,
name|config
capture|]
parameter_list|()
block|{
name|d
operator|->
name|surface
operator|=
name|eglCreateWindowSurface
argument_list|(
name|display
argument_list|,
name|config
argument_list|,
cast|reinterpret_cast
argument_list|<
name|EGLNativeWindowType
argument_list|>
argument_list|(
name|winId
argument_list|()
argument_list|)
argument_list|,
literal|nullptr
argument_list|)
expr_stmt|;
if|if
condition|(
name|Q_UNLIKELY
argument_list|(
name|d
operator|->
name|surface
operator|==
name|EGL_NO_SURFACE
argument_list|)
condition|)
name|qCritical
argument_list|(
literal|"Failed to create EGL window surface: 0x%x"
argument_list|,
name|eglGetError
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
