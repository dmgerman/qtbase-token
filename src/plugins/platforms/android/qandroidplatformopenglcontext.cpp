begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 BogDan Vatra<bogdan@kde.org> ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformopenglcontext.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformopenglwindow.h"
end_include
begin_include
include|#
directive|include
file|"qandroidplatformintegration.h"
end_include
begin_include
include|#
directive|include
file|<QtPlatformSupport/private/qeglpbuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<QSurface>
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qopenglcontext_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QAndroidPlatformOpenGLContext
name|QAndroidPlatformOpenGLContext
operator|::
name|QAndroidPlatformOpenGLContext
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
parameter_list|)
member_init_list|:
name|QEGLPlatformContext
argument_list|(
name|format
argument_list|,
name|share
argument_list|,
name|display
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|swapBuffers
name|void
name|QAndroidPlatformOpenGLContext
operator|::
name|swapBuffers
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
if|if
condition|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
operator|==
name|QSurface
operator|::
name|Window
operator|&&
cast|static_cast
argument_list|<
name|QAndroidPlatformOpenGLWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|checkNativeSurface
argument_list|(
name|eglConfig
argument_list|()
argument_list|)
condition|)
block|{
name|QEGLPlatformContext
operator|::
name|makeCurrent
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
name|QEGLPlatformContext
operator|::
name|swapBuffers
argument_list|(
name|surface
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|needsFBOReadBackWorkaround
name|bool
name|QAndroidPlatformOpenGLContext
operator|::
name|needsFBOReadBackWorkaround
parameter_list|()
block|{
specifier|static
name|bool
name|set
init|=
literal|false
decl_stmt|;
specifier|static
name|bool
name|needsWorkaround
init|=
literal|false
decl_stmt|;
if|if
condition|(
operator|!
name|set
condition|)
block|{
name|QByteArray
name|env
init|=
name|qgetenv
argument_list|(
literal|"QT_ANDROID_DISABLE_GLYPH_CACHE_WORKAROUND"
argument_list|)
decl_stmt|;
name|needsWorkaround
operator|=
name|env
operator|.
name|isEmpty
argument_list|()
operator|||
name|env
operator|==
literal|"0"
operator|||
name|env
operator|==
literal|"false"
expr_stmt|;
if|if
condition|(
operator|!
name|needsWorkaround
condition|)
block|{
specifier|const
name|char
modifier|*
name|rendererString
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
argument_list|)
decl_stmt|;
name|needsWorkaround
operator|=
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Mali-4xx"
argument_list|,
literal|6
argument_list|)
operator|==
literal|0
comment|// Mali-400, Mali-450
operator|||
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Adreno (TM) 2xx"
argument_list|,
literal|13
argument_list|)
operator|==
literal|0
comment|// Adreno 200, 203, 205
operator|||
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Adreno 2xx"
argument_list|,
literal|8
argument_list|)
operator|==
literal|0
comment|// Same as above but without the '(TM)'
operator|||
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Adreno (TM) 30x"
argument_list|,
literal|14
argument_list|)
operator|==
literal|0
comment|// Adreno 302, 305
operator|||
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Adreno 30x"
argument_list|,
literal|9
argument_list|)
operator|==
literal|0
comment|// Same as above but without the '(TM)'
operator|||
name|qstrcmp
argument_list|(
name|rendererString
argument_list|,
literal|"GC800 core"
argument_list|)
operator|==
literal|0
operator|||
name|qstrcmp
argument_list|(
name|rendererString
argument_list|,
literal|"GC1000 core"
argument_list|)
operator|==
literal|0
operator|||
name|qstrcmp
argument_list|(
name|rendererString
argument_list|,
literal|"Immersion.16"
argument_list|)
operator|==
literal|0
expr_stmt|;
block|}
name|set
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|needsWorkaround
return|;
block|}
end_function
begin_function
DECL|function|makeCurrent
name|bool
name|QAndroidPlatformOpenGLContext
operator|::
name|makeCurrent
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
name|bool
name|ret
init|=
name|QEGLPlatformContext
operator|::
name|makeCurrent
argument_list|(
name|surface
argument_list|)
decl_stmt|;
name|QOpenGLContextPrivate
modifier|*
name|ctx_d
init|=
name|QOpenGLContextPrivate
operator|::
name|get
argument_list|(
name|context
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|rendererString
init|=
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|glGetString
argument_list|(
name|GL_RENDERER
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|rendererString
operator|!=
literal|0
operator|&&
name|qstrncmp
argument_list|(
name|rendererString
argument_list|,
literal|"Android Emulator"
argument_list|,
literal|16
argument_list|)
operator|==
literal|0
condition|)
name|ctx_d
operator|->
name|workaround_missingPrecisionQualifiers
operator|=
literal|true
expr_stmt|;
if|if
condition|(
operator|!
name|ctx_d
operator|->
name|workaround_brokenFBOReadBack
operator|&&
name|needsFBOReadBackWorkaround
argument_list|()
condition|)
name|ctx_d
operator|->
name|workaround_brokenFBOReadBack
operator|=
literal|true
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|eglSurfaceForPlatformSurface
name|EGLSurface
name|QAndroidPlatformOpenGLContext
operator|::
name|eglSurfaceForPlatformSurface
parameter_list|(
name|QPlatformSurface
modifier|*
name|surface
parameter_list|)
block|{
if|if
condition|(
name|surface
operator|->
name|surface
argument_list|()
operator|->
name|surfaceClass
argument_list|()
operator|==
name|QSurface
operator|::
name|Window
condition|)
return|return
cast|static_cast
argument_list|<
name|QAndroidPlatformOpenGLWindow
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|eglSurface
argument_list|(
name|eglConfig
argument_list|()
argument_list|)
return|;
else|else
return|return
cast|static_cast
argument_list|<
name|QEGLPbuffer
operator|*
argument_list|>
argument_list|(
name|surface
argument_list|)
operator|->
name|pbuffer
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
