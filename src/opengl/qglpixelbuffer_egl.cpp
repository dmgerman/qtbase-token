begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|"qglpixelbuffer.h"
end_include
begin_include
include|#
directive|include
file|"qglpixelbuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"qgl_egl_p.h"
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<private/qgl_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|EGL_BIND_TO_TEXTURE_RGBA
DECL|macro|QGL_RENDER_TEXTURE
define|#
directive|define
name|QGL_RENDER_TEXTURE
value|1
else|#
directive|else
define|#
directive|define
name|QGL_RENDER_TEXTURE
value|0
endif|#
directive|endif
DECL|function|init
name|bool
name|QGLPixelBufferPrivate
operator|::
name|init
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QGLFormat
modifier|&
name|f
parameter_list|,
name|QGLWidget
modifier|*
name|shareWidget
parameter_list|)
block|{
comment|// Create the EGL context.
name|ctx
operator|=
operator|new
name|QEglContext
argument_list|()
expr_stmt|;
name|ctx
operator|->
name|setApi
argument_list|(
name|QEgl
operator|::
name|OpenGL
argument_list|)
expr_stmt|;
comment|// Find the shared context.
name|QEglContext
modifier|*
name|shareContext
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|shareWidget
operator|&&
name|shareWidget
operator|->
name|d_func
argument_list|()
operator|->
name|glcx
condition|)
name|shareContext
operator|=
name|shareWidget
operator|->
name|d_func
argument_list|()
operator|->
name|glcx
operator|->
name|d_func
argument_list|()
operator|->
name|eglContext
expr_stmt|;
comment|// Choose an appropriate configuration.  We use the best format
comment|// we can find, even if it is greater than the requested format.
comment|// We try for a pbuffer that is capable of texture rendering if possible.
name|textureFormat
operator|=
name|EGL_NONE
expr_stmt|;
if|if
condition|(
name|shareContext
condition|)
block|{
comment|// Use the same configuration as the widget we are sharing with.
name|ctx
operator|->
name|setConfig
argument_list|(
name|shareContext
operator|->
name|config
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
name|QGL_RENDER_TEXTURE
if|if
condition|(
name|ctx
operator|->
name|configAttrib
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
operator|==
name|EGL_TRUE
condition|)
name|textureFormat
operator|=
name|EGL_TEXTURE_RGBA
expr_stmt|;
elseif|else
if|if
condition|(
name|ctx
operator|->
name|configAttrib
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
operator|==
name|EGL_TRUE
condition|)
name|textureFormat
operator|=
name|EGL_TEXTURE_RGB
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
name|QEglProperties
name|configProps
decl_stmt|;
name|qt_eglproperties_set_glformat
argument_list|(
name|configProps
argument_list|,
name|f
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setDeviceType
argument_list|(
name|QInternal
operator|::
name|Pbuffer
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setRenderableType
argument_list|(
name|ctx
operator|->
name|api
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|ok
init|=
literal|false
decl_stmt|;
if|#
directive|if
name|QGL_RENDER_TEXTURE
name|textureFormat
operator|=
name|EGL_TEXTURE_RGBA
expr_stmt|;
name|configProps
operator|.
name|setValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|,
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|ok
operator|=
name|ctx
operator|->
name|chooseConfig
argument_list|(
name|configProps
argument_list|,
name|QEgl
operator|::
name|BestPixelFormat
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
comment|// Try again with RGB texture rendering.
name|textureFormat
operator|=
name|EGL_TEXTURE_RGB
expr_stmt|;
name|configProps
operator|.
name|removeValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGBA
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|,
name|EGL_TRUE
argument_list|)
expr_stmt|;
name|ok
operator|=
name|ctx
operator|->
name|chooseConfig
argument_list|(
name|configProps
argument_list|,
name|QEgl
operator|::
name|BestPixelFormat
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
block|{
comment|// One last try for a pbuffer with no texture rendering.
name|configProps
operator|.
name|removeValue
argument_list|(
name|EGL_BIND_TO_TEXTURE_RGB
argument_list|)
expr_stmt|;
name|textureFormat
operator|=
name|EGL_NONE
expr_stmt|;
block|}
block|}
endif|#
directive|endif
if|if
condition|(
operator|!
name|ok
condition|)
block|{
if|if
condition|(
operator|!
name|ctx
operator|->
name|chooseConfig
argument_list|(
name|configProps
argument_list|,
name|QEgl
operator|::
name|BestPixelFormat
argument_list|)
condition|)
block|{
operator|delete
name|ctx
expr_stmt|;
name|ctx
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
block|}
block|}
comment|// Retrieve the actual format properties.
name|qt_glformat_from_eglconfig
argument_list|(
name|format
argument_list|,
name|ctx
operator|->
name|config
argument_list|()
argument_list|)
expr_stmt|;
comment|// Create the attributes needed for the pbuffer.
name|QEglProperties
name|attribs
decl_stmt|;
name|attribs
operator|.
name|setValue
argument_list|(
name|EGL_WIDTH
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|setValue
argument_list|(
name|EGL_HEIGHT
argument_list|,
name|size
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
name|QGL_RENDER_TEXTURE
if|if
condition|(
name|textureFormat
operator|!=
name|EGL_NONE
condition|)
block|{
name|attribs
operator|.
name|setValue
argument_list|(
name|EGL_TEXTURE_FORMAT
argument_list|,
name|textureFormat
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|setValue
argument_list|(
name|EGL_TEXTURE_TARGET
argument_list|,
name|EGL_TEXTURE_2D
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|// Create the pbuffer surface.
name|pbuf
operator|=
name|eglCreatePbufferSurface
argument_list|(
name|ctx
operator|->
name|display
argument_list|()
argument_list|,
name|ctx
operator|->
name|config
argument_list|()
argument_list|,
name|attribs
operator|.
name|properties
argument_list|()
argument_list|)
expr_stmt|;
if|#
directive|if
name|QGL_RENDER_TEXTURE
if|if
condition|(
name|pbuf
operator|==
name|EGL_NO_SURFACE
operator|&&
name|textureFormat
operator|!=
name|EGL_NONE
condition|)
block|{
comment|// Try again with texture rendering disabled.
name|textureFormat
operator|=
name|EGL_NONE
expr_stmt|;
name|attribs
operator|.
name|removeValue
argument_list|(
name|EGL_TEXTURE_FORMAT
argument_list|)
expr_stmt|;
name|attribs
operator|.
name|removeValue
argument_list|(
name|EGL_TEXTURE_TARGET
argument_list|)
expr_stmt|;
name|pbuf
operator|=
name|eglCreatePbufferSurface
argument_list|(
name|ctx
operator|->
name|display
argument_list|()
argument_list|,
name|ctx
operator|->
name|config
argument_list|()
argument_list|,
name|attribs
operator|.
name|properties
argument_list|()
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|pbuf
operator|==
name|EGL_NO_SURFACE
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"QGLPixelBufferPrivate::init(): Unable to create EGL pbuffer surface:"
operator|<<
name|QEgl
operator|::
name|errorString
argument_list|()
expr_stmt|;
return|return
literal|false
return|;
block|}
comment|// Create a new context for the configuration.
if|if
condition|(
operator|!
name|ctx
operator|->
name|createContext
argument_list|(
name|shareContext
argument_list|)
condition|)
block|{
operator|delete
name|ctx
expr_stmt|;
name|ctx
operator|=
literal|0
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|cleanup
name|bool
name|QGLPixelBufferPrivate
operator|::
name|cleanup
parameter_list|()
block|{
comment|// No need to destroy "pbuf" here - it is done in QGLContext::reset().
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|bindToDynamicTexture
name|bool
name|QGLPixelBuffer
operator|::
name|bindToDynamicTexture
parameter_list|(
name|GLuint
name|texture_id
parameter_list|)
block|{
if|#
directive|if
name|QGL_RENDER_TEXTURE
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
operator|||
name|d
operator|->
name|textureFormat
operator|==
name|EGL_NONE
operator|||
operator|!
name|d
operator|->
name|ctx
condition|)
return|return
literal|false
return|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|texture_id
argument_list|)
expr_stmt|;
return|return
name|eglBindTexImage
argument_list|(
name|d
operator|->
name|ctx
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|pbuf
argument_list|,
name|EGL_BACK_BUFFER
argument_list|)
return|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|texture_id
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|releaseFromDynamicTexture
name|void
name|QGLPixelBuffer
operator|::
name|releaseFromDynamicTexture
parameter_list|()
block|{
if|#
directive|if
name|QGL_RENDER_TEXTURE
name|Q_D
argument_list|(
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|invalid
operator|||
name|d
operator|->
name|textureFormat
operator|==
name|EGL_NONE
operator|||
operator|!
name|d
operator|->
name|ctx
condition|)
return|return;
name|eglReleaseTexImage
argument_list|(
name|d
operator|->
name|ctx
operator|->
name|display
argument_list|()
argument_list|,
name|d
operator|->
name|pbuf
argument_list|,
name|EGL_BACK_BUFFER
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|generateDynamicTexture
name|GLuint
name|QGLPixelBuffer
operator|::
name|generateDynamicTexture
parameter_list|()
specifier|const
block|{
if|#
directive|if
name|QGL_RENDER_TEXTURE
name|Q_D
argument_list|(
specifier|const
name|QGLPixelBuffer
argument_list|)
expr_stmt|;
name|GLuint
name|texture
decl_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|texture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|texture
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|textureFormat
operator|==
name|EGL_TEXTURE_RGB
condition|)
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGB
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|height
argument_list|()
argument_list|,
literal|0
argument_list|,
name|GL_RGB
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|d
operator|->
name|req_size
operator|.
name|width
argument_list|()
argument_list|,
name|d
operator|->
name|req_size
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
literal|0
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
return|return
name|texture
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|hasOpenGLPbuffers
name|bool
name|QGLPixelBuffer
operator|::
name|hasOpenGLPbuffers
parameter_list|()
block|{
comment|// See if we have at least 1 configuration that matches the default format.
name|EGLDisplay
name|dpy
init|=
name|QEgl
operator|::
name|display
argument_list|()
decl_stmt|;
if|if
condition|(
name|dpy
operator|==
name|EGL_NO_DISPLAY
condition|)
return|return
literal|false
return|;
name|QEglProperties
name|configProps
decl_stmt|;
name|qt_eglproperties_set_glformat
argument_list|(
name|configProps
argument_list|,
name|QGLFormat
operator|::
name|defaultFormat
argument_list|()
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setDeviceType
argument_list|(
name|QInternal
operator|::
name|Pbuffer
argument_list|)
expr_stmt|;
name|configProps
operator|.
name|setRenderableType
argument_list|(
name|QEgl
operator|::
name|OpenGL
argument_list|)
expr_stmt|;
do|do
block|{
name|EGLConfig
name|cfg
init|=
literal|0
decl_stmt|;
name|EGLint
name|matching
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|eglChooseConfig
argument_list|(
name|dpy
argument_list|,
name|configProps
operator|.
name|properties
argument_list|()
argument_list|,
operator|&
name|cfg
argument_list|,
literal|1
argument_list|,
operator|&
name|matching
argument_list|)
operator|&&
name|matching
operator|>
literal|0
condition|)
return|return
literal|true
return|;
block|}
do|while
condition|(
name|configProps
operator|.
name|reduceConfiguration
argument_list|()
condition|)
do|;
return|return
literal|false
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
