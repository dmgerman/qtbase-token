begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwindowsnativeinterface.h"
end_include
begin_include
include|#
directive|include
file|"qwindowswindow.h"
end_include
begin_include
include|#
directive|include
file|"qwindowscontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsopengltester.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsintegration.h"
end_include
begin_include
include|#
directive|include
file|"qwindowsmime.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|enum|ResourceType
name|enum
name|ResourceType
argument_list|{
DECL|enumerator|RenderingContextType
name|RenderingContextType
argument_list|,
DECL|enumerator|EglContextType
name|EglContextType
argument_list|,
DECL|enumerator|EglDisplayType
name|EglDisplayType
argument_list|,
DECL|enumerator|EglConfigType
name|EglConfigType
argument_list|,
DECL|enumerator|HandleType
name|HandleType
argument_list|,
DECL|enumerator|GlHandleType
name|GlHandleType
argument_list|,
DECL|enumerator|GetDCType
name|GetDCType
argument_list|,
DECL|enumerator|ReleaseDCType
name|ReleaseDCType
argument_list|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|resourceType
specifier|static
name|int
name|resourceType
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|key
parameter_list|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|names
index|[]
init|=
block|{
comment|// match ResourceType
literal|"renderingcontext"
block|,
literal|"eglcontext"
block|,
literal|"egldisplay"
block|,
literal|"eglconfig"
block|,
literal|"handle"
block|,
literal|"glhandle"
block|,
literal|"getdc"
block|,
literal|"releasedc"
block|}
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
specifier|const
name|end
init|=
name|names
operator|+
sizeof|sizeof
argument_list|(
name|names
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|names
index|[
literal|0
index|]
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|result
init|=
name|std
operator|::
name|find
argument_list|(
name|names
argument_list|,
name|end
argument_list|,
name|key
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
operator|==
name|end
condition|)
name|result
operator|=
name|std
operator|::
name|find
argument_list|(
name|names
argument_list|,
name|end
argument_list|,
name|key
operator|.
name|toLower
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|int
argument_list|(
name|result
operator|-
name|names
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForWindow
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
if|if
condition|(
operator|!
name|window
operator|||
operator|!
name|window
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null window or window without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsWindow
modifier|*
name|bw
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|type
init|=
name|resourceType
argument_list|(
name|resource
argument_list|)
decl_stmt|;
if|if
condition|(
name|type
operator|==
name|HandleType
condition|)
return|return
name|bw
operator|->
name|handle
argument_list|()
return|;
switch|switch
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
condition|)
block|{
case|case
name|QWindow
operator|::
name|RasterSurface
case|:
case|case
name|QWindow
operator|::
name|RasterGLSurface
case|:
if|if
condition|(
name|type
operator|==
name|GetDCType
condition|)
return|return
name|bw
operator|->
name|getDC
argument_list|()
return|;
if|if
condition|(
name|type
operator|==
name|ReleaseDCType
condition|)
block|{
name|bw
operator|->
name|releaseDC
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
break|break;
case|case
name|QWindow
operator|::
name|OpenGLSurface
case|:
break|break;
block|}
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|customMarginPropertyC
specifier|static
specifier|const
name|char
name|customMarginPropertyC
index|[]
init|=
literal|"WindowsCustomMargins"
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|windowProperty
name|QVariant
name|QWindowsNativeInterface
operator|::
name|windowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
specifier|const
block|{
name|QWindowsWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
name|customMarginPropertyC
argument_list|)
condition|)
return|return
name|qVariantFromValue
argument_list|(
name|platformWindow
operator|->
name|customMargins
argument_list|()
argument_list|)
return|;
return|return
name|QVariant
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|windowProperty
name|QVariant
name|QWindowsNativeInterface
operator|::
name|windowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|defaultValue
parameter_list|)
specifier|const
block|{
specifier|const
name|QVariant
name|result
init|=
name|windowProperty
argument_list|(
name|window
argument_list|,
name|name
argument_list|)
decl_stmt|;
return|return
name|result
operator|.
name|isValid
argument_list|()
condition|?
name|result
else|:
name|defaultValue
return|;
block|}
end_function
begin_function
DECL|function|setWindowProperty
name|void
name|QWindowsNativeInterface
operator|::
name|setWindowProperty
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|)
block|{
name|QWindowsWindow
modifier|*
name|platformWindow
init|=
cast|static_cast
argument_list|<
name|QWindowsWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
name|customMarginPropertyC
argument_list|)
condition|)
name|platformWindow
operator|->
name|setCustomMargins
argument_list|(
name|qvariant_cast
argument_list|<
name|QMargins
argument_list|>
argument_list|(
name|value
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|windowProperties
name|QVariantMap
name|QWindowsNativeInterface
operator|::
name|windowProperties
parameter_list|(
name|QPlatformWindow
modifier|*
name|window
parameter_list|)
specifier|const
block|{
name|QVariantMap
name|result
decl_stmt|;
specifier|const
name|QString
name|customMarginProperty
init|=
name|QLatin1String
argument_list|(
name|customMarginPropertyC
argument_list|)
decl_stmt|;
name|result
operator|.
name|insert
argument_list|(
name|customMarginProperty
argument_list|,
name|windowProperty
argument_list|(
name|window
argument_list|,
name|customMarginProperty
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
if|if
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
operator|==
name|GlHandleType
condition|)
return|return
name|QWindowsIntegration
operator|::
name|staticOpenGLContext
argument_list|()
operator|->
name|moduleHandle
argument_list|()
return|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|nativeResourceForContext
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|)
block|{
if|if
condition|(
operator|!
name|context
operator|||
operator|!
name|context
operator|->
name|handle
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: '%s' requested for null context or context without handle."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QWindowsOpenGLContext
modifier|*
name|glcontext
init|=
cast|static_cast
argument_list|<
name|QWindowsOpenGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|resourceType
argument_list|(
name|resource
argument_list|)
condition|)
block|{
case|case
name|RenderingContextType
case|:
comment|// Fall through.
case|case
name|EglContextType
case|:
return|return
name|glcontext
operator|->
name|nativeContext
argument_list|()
return|;
case|case
name|EglDisplayType
case|:
return|return
name|glcontext
operator|->
name|nativeDisplay
argument_list|()
return|;
case|case
name|EglConfigType
case|:
return|return
name|glcontext
operator|->
name|nativeConfig
argument_list|()
return|;
default|default:
break|break;
block|}
name|qWarning
argument_list|(
literal|"%s: Invalid key '%s' requested."
argument_list|,
name|__FUNCTION__
argument_list|,
name|resource
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// !QT_NO_OPENGL
end_comment
begin_comment
comment|/*!     \brief Creates a non-visible window handle for filtering messages. */
end_comment
begin_function
DECL|function|createMessageWindow
name|void
modifier|*
name|QWindowsNativeInterface
operator|::
name|createMessageWindow
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameTemplate
parameter_list|,
specifier|const
name|QString
modifier|&
name|windowName
parameter_list|,
name|void
modifier|*
name|eventProc
parameter_list|)
specifier|const
block|{
name|QWindowsContext
modifier|*
name|ctx
init|=
name|QWindowsContext
operator|::
name|instance
argument_list|()
decl_stmt|;
specifier|const
name|HWND
name|hwnd
init|=
name|ctx
operator|->
name|createDummyWindow
argument_list|(
name|classNameTemplate
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|windowName
operator|.
name|utf16
argument_list|()
argument_list|,
operator|(
name|WNDPROC
operator|)
name|eventProc
argument_list|)
decl_stmt|;
return|return
name|hwnd
return|;
block|}
end_function
begin_comment
comment|/*!     \brief Registers a unique window class with a callback function based on \a classNameIn. */
end_comment
begin_function
DECL|function|registerWindowClass
name|QString
name|QWindowsNativeInterface
operator|::
name|registerWindowClass
parameter_list|(
specifier|const
name|QString
modifier|&
name|classNameIn
parameter_list|,
name|void
modifier|*
name|eventProc
parameter_list|)
specifier|const
block|{
return|return
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|registerWindowClass
argument_list|(
name|classNameIn
argument_list|,
operator|(
name|WNDPROC
operator|)
name|eventProc
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|asyncExpose
name|bool
name|QWindowsNativeInterface
operator|::
name|asyncExpose
parameter_list|()
specifier|const
block|{
return|return
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|asyncExpose
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setAsyncExpose
name|void
name|QWindowsNativeInterface
operator|::
name|setAsyncExpose
parameter_list|(
name|bool
name|value
parameter_list|)
block|{
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|setAsyncExpose
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerWindowsMime
name|void
name|QWindowsNativeInterface
operator|::
name|registerWindowsMime
parameter_list|(
name|void
modifier|*
name|mimeIn
parameter_list|)
block|{
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|mimeConverter
argument_list|()
operator|.
name|registerMime
argument_list|(
cast|reinterpret_cast
argument_list|<
name|QWindowsMime
operator|*
argument_list|>
argument_list|(
name|mimeIn
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|unregisterWindowsMime
name|void
name|QWindowsNativeInterface
operator|::
name|unregisterWindowsMime
parameter_list|(
name|void
modifier|*
name|mimeIn
parameter_list|)
block|{
name|QWindowsContext
operator|::
name|instance
argument_list|()
operator|->
name|mimeConverter
argument_list|()
operator|.
name|unregisterMime
argument_list|(
cast|reinterpret_cast
argument_list|<
name|QWindowsMime
operator|*
argument_list|>
argument_list|(
name|mimeIn
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|registerMimeType
name|int
name|QWindowsNativeInterface
operator|::
name|registerMimeType
parameter_list|(
specifier|const
name|QString
modifier|&
name|mimeType
parameter_list|)
block|{
return|return
name|QWindowsMime
operator|::
name|registerMimeType
argument_list|(
name|mimeType
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|platformFunction
name|QFunctionPointer
name|QWindowsNativeInterface
operator|::
name|platformFunction
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|function
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|function
operator|==
name|QWindowsWindowFunctions
operator|::
name|setTouchWindowTouchTypeIdentifier
argument_list|()
condition|)
return|return
name|QFunctionPointer
argument_list|(
name|QWindowsWindow
operator|::
name|setTouchWindowTouchTypeStatic
argument_list|)
return|;
return|return
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|gpu
name|QVariant
name|QWindowsNativeInterface
operator|::
name|gpu
parameter_list|()
specifier|const
block|{
return|return
name|GpuDescription
operator|::
name|detect
argument_list|()
operator|.
name|toVariant
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
