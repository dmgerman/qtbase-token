begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopenglcontextwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOffscreenSurface>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformnativeinterface.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglconvenience_p.h>
end_include
begin_include
include|#
directive|include
file|<QtPlatformHeaders/QEGLNativeContext>
end_include
begin_constructor
DECL|function|QOpenGLContextWindow
name|QOpenGLContextWindow
operator|::
name|QOpenGLContextWindow
parameter_list|()
member_init_list|:
name|m_blitter
argument_list|(
literal|0
argument_list|)
block|{
name|setSurfaceType
argument_list|(
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|m_context
operator|=
operator|new
name|QOpenGLContext
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|setFormat
argument_list|(
name|requestedFormat
argument_list|()
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
name|m_image
operator|=
name|QImage
argument_list|(
name|QStringLiteral
argument_list|(
literal|"qticon64.png"
argument_list|)
argument_list|)
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_RGBA8888
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|m_image
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
comment|// to make sure format() returns something real
name|createForeignContext
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QOpenGLContextWindow
name|QOpenGLContextWindow
operator|::
name|~
name|QOpenGLContextWindow
parameter_list|()
block|{
if|if
condition|(
name|m_blitter
condition|)
block|{
name|m_blitter
operator|->
name|destroy
argument_list|()
expr_stmt|;
comment|// the dtor does not call this for some reason
operator|delete
name|m_blitter
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|render
name|void
name|QOpenGLContextWindow
operator|::
name|render
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"makeCurrent() failed"
argument_list|)
expr_stmt|;
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|m_context
operator|->
name|functions
argument_list|()
decl_stmt|;
name|f
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|dWidth
argument_list|()
argument_list|,
name|dHeight
argument_list|()
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClearColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|f
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_blitter
condition|)
block|{
name|m_blitter
operator|=
operator|new
name|QOpenGLTextureBlitter
expr_stmt|;
name|m_blitter
operator|->
name|create
argument_list|()
expr_stmt|;
block|}
comment|// Draw the image. If nothing gets shown, then something went wrong with the context
comment|// adoption or sharing was not successfully enabled.
name|m_blitter
operator|->
name|bind
argument_list|()
expr_stmt|;
name|QRectF
name|r
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|dWidth
argument_list|()
argument_list|,
name|dHeight
argument_list|()
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|target
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|QRectF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|r
operator|.
name|toRect
argument_list|()
argument_list|)
decl_stmt|;
name|m_blitter
operator|->
name|blit
argument_list|(
name|m_textureId
argument_list|,
name|target
argument_list|,
name|QOpenGLTextureBlitter
operator|::
name|OriginTopLeft
argument_list|)
expr_stmt|;
name|m_blitter
operator|->
name|release
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|exposeEvent
name|void
name|QOpenGLContextWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|isExposed
argument_list|()
condition|)
name|render
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createForeignContext
name|void
name|QOpenGLContextWindow
operator|::
name|createForeignContext
parameter_list|()
block|{
comment|// Here a context will be created manually. This context will share with m_context's
comment|// underlying native context.  This way the texture, that belongs to the context
comment|// created here, will be accessible from m_context too.
name|EGLContext
name|shareCtx
init|=
name|m_context
operator|->
name|nativeHandle
argument_list|()
operator|.
name|value
argument_list|<
name|QEGLNativeContext
argument_list|>
argument_list|()
operator|.
name|context
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|shareCtx
operator|!=
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
name|EGLDisplay
name|dpy
init|=
operator|(
name|EGLDisplay
operator|)
name|qGuiApp
operator|->
name|platformNativeInterface
argument_list|()
operator|->
name|nativeResourceForWindow
argument_list|(
name|QByteArrayLiteral
argument_list|(
literal|"egldisplay"
argument_list|)
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|dpy
operator|!=
name|EGL_NO_DISPLAY
argument_list|)
expr_stmt|;
name|QSurfaceFormat
name|fmt
init|=
name|format
argument_list|()
decl_stmt|;
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|dpy
argument_list|,
name|fmt
argument_list|)
decl_stmt|;
name|QVector
argument_list|<
name|EGLint
argument_list|>
name|contextAttrs
decl_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_CONTEXT_CLIENT_VERSION
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|fmt
operator|.
name|majorVersion
argument_list|()
argument_list|)
expr_stmt|;
name|contextAttrs
operator|.
name|append
argument_list|(
name|EGL_NONE
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|fmt
operator|.
name|renderableType
argument_list|()
condition|)
block|{
ifdef|#
directive|ifdef
name|EGL_VERSION_1_4
case|case
name|QSurfaceFormat
operator|::
name|OpenGL
case|:
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_API
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
comment|// EGL_VERSION_1_4
default|default:
name|eglBindAPI
argument_list|(
name|EGL_OPENGL_ES_API
argument_list|)
expr_stmt|;
break|break;
block|}
name|EGLContext
name|ctx
init|=
name|eglCreateContext
argument_list|(
name|dpy
argument_list|,
name|config
argument_list|,
name|shareCtx
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|ctx
operator|!=
name|EGL_NO_CONTEXT
argument_list|)
expr_stmt|;
comment|// Wrap ctx into a QOpenGLContext.
name|QOpenGLContext
modifier|*
name|ctxWrap
init|=
operator|new
name|QOpenGLContext
decl_stmt|;
name|ctxWrap
operator|->
name|setNativeHandle
argument_list|(
name|QVariant
operator|::
name|fromValue
argument_list|<
name|QEGLNativeContext
argument_list|>
argument_list|(
name|QEGLNativeContext
argument_list|(
name|ctx
argument_list|,
name|dpy
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ctxWrap
operator|->
name|setShareContext
argument_list|(
name|m_context
argument_list|)
expr_stmt|;
comment|// only needed for correct bookkeeping
if|if
condition|(
operator|!
name|ctxWrap
operator|->
name|create
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"Failed to created wrapping context"
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|ctxWrap
operator|->
name|nativeHandle
argument_list|()
operator|.
name|value
argument_list|<
name|QEGLNativeContext
argument_list|>
argument_list|()
operator|.
name|context
argument_list|()
operator|==
name|ctx
argument_list|)
expr_stmt|;
name|QOffscreenSurface
name|surface
decl_stmt|;
name|surface
operator|.
name|setFormat
argument_list|(
name|fmt
argument_list|)
expr_stmt|;
name|surface
operator|.
name|create
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|ctxWrap
operator|->
name|makeCurrent
argument_list|(
operator|&
name|surface
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"Failed to make pbuffer surface current"
argument_list|)
expr_stmt|;
comment|// Create the texture.
name|QOpenGLFunctions
modifier|*
name|f
init|=
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
name|GLuint
name|textureId
init|=
literal|0
decl_stmt|;
name|f
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|textureId
argument_list|)
expr_stmt|;
name|f
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|textureId
argument_list|)
expr_stmt|;
name|f
operator|->
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|f
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|m_image
operator|.
name|width
argument_list|()
argument_list|,
name|m_image
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|m_image
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|f
operator|->
name|glGetError
argument_list|()
operator|==
name|GL_NO_ERROR
argument_list|)
expr_stmt|;
name|ctxWrap
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
operator|delete
name|ctxWrap
expr_stmt|;
comment|// ctx is not destroyed
name|eglDestroyContext
argument_list|(
name|dpy
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
comment|// resources like the texture stay alive until any context on the share list is alive
name|Q_ASSERT
argument_list|(
name|eglGetError
argument_list|()
operator|==
name|EGL_SUCCESS
argument_list|)
expr_stmt|;
name|m_textureId
operator|=
name|textureId
expr_stmt|;
block|}
end_function
end_unit
