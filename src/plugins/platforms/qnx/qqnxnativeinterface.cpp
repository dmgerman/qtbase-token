begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2012 Research In Motion ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxnativeinterface.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxglcontext.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|"qqnxwindow.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNX_IMF
argument_list|)
end_if
begin_include
include|#
directive|include
file|"qqnxinputcontext_imf.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_include
include|#
directive|include
file|<QtGui/QWindow>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxNativeInterface
name|QQnxNativeInterface
operator|::
name|QQnxNativeInterface
parameter_list|(
name|QQnxIntegration
modifier|*
name|integration
parameter_list|)
member_init_list|:
name|m_integration
argument_list|(
name|integration
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|nativeResourceForWindow
name|void
modifier|*
name|QQnxNativeInterface
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
name|resource
operator|==
literal|"windowGroup"
operator|&&
name|window
operator|&&
name|window
operator|->
name|screen
argument_list|()
condition|)
block|{
name|QQnxScreen
modifier|*
specifier|const
name|screen
init|=
cast|static_cast
argument_list|<
name|QQnxScreen
operator|*
argument_list|>
argument_list|(
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|screen
condition|)
block|{
name|screen_window_t
name|screenWindow
init|=
cast|reinterpret_cast
argument_list|<
name|screen_window_t
argument_list|>
argument_list|(
name|window
operator|->
name|winId
argument_list|()
argument_list|)
decl_stmt|;
name|QQnxWindow
modifier|*
name|qnxWindow
init|=
name|screen
operator|->
name|findWindow
argument_list|(
name|screenWindow
argument_list|)
decl_stmt|;
comment|// We can't just call data() instead of constData() here, since that would detach
comment|// and the lifetime of the char * would not be long enough. Therefore the const_cast.
return|return
name|qnxWindow
condition|?
cast|const_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|qnxWindow
operator|->
name|groupName
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
else|:
literal|0
return|;
block|}
block|}
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForScreen
name|void
modifier|*
name|QQnxNativeInterface
operator|::
name|nativeResourceForScreen
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|,
name|QScreen
modifier|*
name|screen
parameter_list|)
block|{
if|if
condition|(
name|resource
operator|==
literal|"QObject*"
operator|&&
name|screen
condition|)
return|return
cast|static_cast
argument_list|<
name|QObject
operator|*
argument_list|>
argument_list|(
cast|static_cast
argument_list|<
name|QQnxScreen
operator|*
argument_list|>
argument_list|(
name|screen
operator|->
name|handle
argument_list|()
argument_list|)
argument_list|)
return|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|nativeResourceForIntegration
name|void
modifier|*
name|QQnxNativeInterface
operator|::
name|nativeResourceForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_OPENGL
argument_list|)
end_if
begin_function
DECL|function|nativeResourceForContext
name|void
modifier|*
name|QQnxNativeInterface
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
name|resource
operator|==
literal|"eglcontext"
operator|&&
name|context
condition|)
return|return
cast|static_cast
argument_list|<
name|QQnxGLContext
operator|*
argument_list|>
argument_list|(
name|context
operator|->
name|handle
argument_list|()
argument_list|)
operator|->
name|getEglContext
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|setWindowProperty
name|void
name|QQnxNativeInterface
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
name|QQnxWindow
modifier|*
name|qnxWindow
init|=
cast|static_cast
argument_list|<
name|QQnxWindow
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
literal|"mmRendererWindowName"
argument_list|)
condition|)
block|{
name|qnxWindow
operator|->
name|setMMRendererWindowName
argument_list|(
name|value
operator|.
name|toString
argument_list|()
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"qnxWindowGroup"
argument_list|)
condition|)
block|{
if|if
condition|(
name|value
operator|.
name|isNull
argument_list|()
condition|)
name|qnxWindow
operator|->
name|joinWindowGroup
argument_list|(
name|QByteArray
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|value
operator|.
name|canConvert
argument_list|<
name|QByteArray
argument_list|>
argument_list|()
condition|)
name|qnxWindow
operator|->
name|joinWindowGroup
argument_list|(
name|value
operator|.
name|toByteArray
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|nativeResourceFunctionForIntegration
name|QPlatformNativeInterface
operator|::
name|NativeResourceForIntegrationFunction
name|QQnxNativeInterface
operator|::
name|nativeResourceFunctionForIntegration
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|resource
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|QQNX_IMF
argument_list|)
if|if
condition|(
name|resource
operator|==
literal|"blackberryIMFSetHighlightColor"
condition|)
return|return
cast|reinterpret_cast
argument_list|<
name|NativeResourceForIntegrationFunction
argument_list|>
argument_list|(
name|QQnxInputContext
operator|::
name|setHighlightColor
argument_list|)
return|;
if|if
condition|(
name|resource
operator|==
literal|"blackberryIMFCheckSpelling"
condition|)
return|return
cast|reinterpret_cast
argument_list|<
name|NativeResourceForIntegrationFunction
argument_list|>
argument_list|(
name|QQnxInputContext
operator|::
name|checkSpelling
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
argument|resource
argument_list|)
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
