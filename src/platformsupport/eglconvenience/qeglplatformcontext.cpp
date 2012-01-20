begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglplatformcontext_p.h"
end_include
begin_include
include|#
directive|include
file|"qeglconvenience_p.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPlatformWindow>
end_include
begin_include
include|#
directive|include
file|<EGL/egl.h>
end_include
begin_constructor
DECL|function|QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|QEGLPlatformContext
parameter_list|(
specifier|const
name|QSurfaceFormat
modifier|&
name|format
parameter_list|,
name|QPlatformOpenGLContext
modifier|*
name|share
parameter_list|,
name|EGLDisplay
name|display
parameter_list|,
name|EGLenum
name|eglApi
parameter_list|)
member_init_list|:
name|m_eglDisplay
argument_list|(
name|display
argument_list|)
member_init_list|,
name|m_eglApi
argument_list|(
name|eglApi
argument_list|)
member_init_list|,
name|m_format
argument_list|(
name|format
argument_list|)
block|{
name|EGLConfig
name|config
init|=
name|q_configFromGLFormat
argument_list|(
name|display
argument_list|,
name|format
argument_list|,
literal|true
argument_list|)
decl_stmt|;
name|m_format
operator|=
name|q_glFormatFromConfig
argument_list|(
name|display
argument_list|,
name|config
argument_list|)
expr_stmt|;
name|m_shareContext
operator|=
name|share
condition|?
cast|static_cast
argument_list|<
name|QEGLPlatformContext
operator|*
argument_list|>
argument_list|(
name|share
argument_list|)
operator|->
name|m_eglContext
else|:
literal|0
expr_stmt|;
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
name|format
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
name|eglBindAPI
argument_list|(
name|m_eglApi
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|config
argument_list|,
name|m_shareContext
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_eglContext
operator|==
name|EGL_NO_CONTEXT
operator|&&
name|m_shareContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|m_shareContext
operator|=
literal|0
expr_stmt|;
name|m_eglContext
operator|=
name|eglCreateContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|config
argument_list|,
literal|0
argument_list|,
name|contextAttrs
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|makeCurrent
name|bool
name|QEGLPlatformContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglContext::makeCurrent: %p\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|eglBindAPI
argument_list|(
name|m_eglApi
argument_list|)
expr_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|eglSurfaceForPlatformSurface
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|eglSurface
argument_list|,
name|eglSurface
argument_list|,
name|m_eglContext
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::makeCurrent: eglError: %x, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
specifier|static
name|bool
name|showDebug
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|showDebug
condition|)
block|{
name|showDebug
operator|=
literal|false
expr_stmt|;
specifier|const
name|char
modifier|*
name|str
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_VENDOR
argument_list|)
decl_stmt|;
name|qWarning
argument_list|(
literal|"Vendor %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Renderer %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_VERSION
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Version %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_SHADING_LANGUAGE_VERSION
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Extensions %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
name|str
operator|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|glGetString
argument_list|(
name|GL_EXTENSIONS
argument_list|)
expr_stmt|;
name|qWarning
argument_list|(
literal|"Extensions %s\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|ok
return|;
block|}
end_function
begin_destructor
DECL|function|~QEGLPlatformContext
name|QEGLPlatformContext
operator|::
name|~
name|QEGLPlatformContext
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglContext::~QEglContext(): %p\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|m_eglContext
operator|!=
name|EGL_NO_CONTEXT
condition|)
block|{
name|eglDestroyContext
argument_list|(
name|m_eglDisplay
argument_list|,
name|m_eglContext
argument_list|)
expr_stmt|;
name|m_eglContext
operator|=
name|EGL_NO_CONTEXT
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|doneCurrent
name|void
name|QEGLPlatformContext
operator|::
name|doneCurrent
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglContext::doneCurrent:%p\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|eglBindAPI
argument_list|(
name|m_eglApi
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
name|eglMakeCurrent
argument_list|(
name|m_eglDisplay
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_SURFACE
argument_list|,
name|EGL_NO_CONTEXT
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::doneCurrent(): eglError: %d, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|swapBuffers
name|void
name|QEGLPlatformContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglContext::swapBuffers:%p\n"
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|eglBindAPI
argument_list|(
name|m_eglApi
argument_list|)
expr_stmt|;
name|EGLSurface
name|eglSurface
init|=
name|eglSurfaceForPlatformSurface
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|bool
name|ok
init|=
name|eglSwapBuffers
argument_list|(
name|m_eglDisplay
argument_list|,
name|eglSurface
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"QEGLPlatformContext::swapBuffers(): eglError: %d, this: %p \n"
argument_list|,
name|eglGetError
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
DECL|function|getProcAddress
name|void
argument_list|(
argument|*QEGLPlatformContext::getProcAddress(const QByteArray&procName)
argument_list|)
end_macro
begin_expr_stmt
DECL|function|getProcAddress
operator|(
operator|)
block|{
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglContext::getProcAddress%p\n"
argument_list|,
name|this
argument_list|)
block|;
endif|#
directive|endif
name|eglBindAPI
argument_list|(
name|m_eglApi
argument_list|)
block|;
return|return
name|eglGetProcAddress
argument_list|(
name|procName
operator|.
name|constData
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|format
name|QSurfaceFormat
name|QEGLPlatformContext
operator|::
name|format
parameter_list|()
specifier|const
block|{
return|return
name|m_format
return|;
block|}
end_function
begin_function
DECL|function|eglContext
name|EGLContext
name|QEGLPlatformContext
operator|::
name|eglContext
parameter_list|()
specifier|const
block|{
return|return
name|m_eglContext
return|;
block|}
end_function
end_unit
