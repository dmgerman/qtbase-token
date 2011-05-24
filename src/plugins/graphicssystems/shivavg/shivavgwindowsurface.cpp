begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_define
DECL|macro|GL_GLEXT_PROTOTYPES
define|#
directive|define
name|GL_GLEXT_PROTOTYPES
end_define
begin_include
include|#
directive|include
file|"shivavgwindowsurface.h"
end_include
begin_include
include|#
directive|include
file|<QtOpenVG/private/qpaintengine_vg_p.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
end_if
begin_include
include|#
directive|include
file|"private/qt_x11_p.h"
end_include
begin_include
include|#
directive|include
file|"qx11info_x11.h"
end_include
begin_include
include|#
directive|include
file|<GL/glx.h>
end_include
begin_function_decl
specifier|extern
name|QX11Info
modifier|*
name|qt_x11Info
parameter_list|(
specifier|const
name|QPaintDevice
modifier|*
name|pd
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Define this to use framebuffer objects.
end_comment
begin_comment
comment|//#define QVG_USE_FBO 1
end_comment
begin_include
include|#
directive|include
file|<vg/openvg.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QShivaContext
class|class
name|QShivaContext
block|{
public|public:
name|QShivaContext
parameter_list|()
constructor_decl|;
name|~
name|QShivaContext
parameter_list|()
destructor_decl|;
name|bool
name|makeCurrent
parameter_list|(
name|ShivaVGWindowSurfacePrivate
modifier|*
name|surface
parameter_list|)
function_decl|;
name|void
name|doneCurrent
parameter_list|()
function_decl|;
DECL|member|initialized
name|bool
name|initialized
decl_stmt|;
DECL|member|currentSize
name|QSize
name|currentSize
decl_stmt|;
DECL|member|currentSurface
name|ShivaVGWindowSurfacePrivate
modifier|*
name|currentSurface
decl_stmt|;
block|}
class|;
end_class
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QShivaContext
argument_list|,
name|shivaContext
argument_list|)
expr_stmt|;
end_expr_stmt
begin_class
DECL|class|ShivaVGWindowSurfacePrivate
class|class
name|ShivaVGWindowSurfacePrivate
block|{
public|public:
DECL|function|ShivaVGWindowSurfacePrivate
name|ShivaVGWindowSurfacePrivate
parameter_list|()
member_init_list|:
name|isCurrent
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|needsResize
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|engine
argument_list|(
literal|0
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|QVG_USE_FBO
argument_list|)
member_init_list|,
name|fbo
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|texture
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
member_init_list|,
name|drawable
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|context
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{     }
name|~
name|ShivaVGWindowSurfacePrivate
parameter_list|()
destructor_decl|;
name|void
name|ensureContext
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
function_decl|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
DECL|member|isCurrent
name|bool
name|isCurrent
decl_stmt|;
DECL|member|needsResize
name|bool
name|needsResize
decl_stmt|;
DECL|member|engine
name|QVGPaintEngine
modifier|*
name|engine
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QVG_USE_FBO
argument_list|)
DECL|member|fbo
name|GLuint
name|fbo
decl_stmt|;
DECL|member|texture
name|GLuint
name|texture
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
DECL|member|drawable
name|GLXDrawable
name|drawable
decl_stmt|;
DECL|member|context
name|GLXContext
name|context
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_constructor
DECL|function|QShivaContext
name|QShivaContext
operator|::
name|QShivaContext
parameter_list|()
member_init_list|:
name|initialized
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|currentSurface
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QShivaContext
name|QShivaContext
operator|::
name|~
name|QShivaContext
parameter_list|()
block|{
if|if
condition|(
name|initialized
condition|)
name|vgDestroyContextSH
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|makeCurrent
name|bool
name|QShivaContext
operator|::
name|makeCurrent
parameter_list|(
name|ShivaVGWindowSurfacePrivate
modifier|*
name|surface
parameter_list|)
block|{
if|if
condition|(
name|currentSurface
condition|)
name|currentSurface
operator|->
name|isCurrent
operator|=
literal|false
expr_stmt|;
name|surface
operator|->
name|isCurrent
operator|=
literal|true
expr_stmt|;
name|currentSurface
operator|=
name|surface
expr_stmt|;
name|currentSize
operator|=
name|surface
operator|->
name|size
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXMakeCurrent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|surface
operator|->
name|drawable
argument_list|,
name|surface
operator|->
name|context
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
if|if
condition|(
operator|!
name|vgCreateContextSH
argument_list|(
name|currentSize
operator|.
name|width
argument_list|()
argument_list|,
name|currentSize
operator|.
name|height
argument_list|()
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"vgCreateContextSH(%d, %d): could not create context"
argument_list|,
name|currentSize
operator|.
name|width
argument_list|()
argument_list|,
name|currentSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|initialized
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
name|vgResizeSurfaceSH
argument_list|(
name|currentSize
operator|.
name|width
argument_list|()
argument_list|,
name|currentSize
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|QVG_USE_FBO
argument_list|)
if|if
condition|(
name|surface
operator|->
name|fbo
condition|)
name|glBindFramebufferEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
name|surface
operator|->
name|fbo
argument_list|)
expr_stmt|;
else|else
name|glBindFramebufferEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|doneCurrent
name|void
name|QShivaContext
operator|::
name|doneCurrent
parameter_list|()
block|{
if|if
condition|(
name|currentSurface
condition|)
block|{
name|currentSurface
operator|->
name|isCurrent
operator|=
literal|false
expr_stmt|;
name|currentSurface
operator|=
literal|0
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXMakeCurrent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_destructor
DECL|function|~ShivaVGWindowSurfacePrivate
name|ShivaVGWindowSurfacePrivate
operator|::
name|~
name|ShivaVGWindowSurfacePrivate
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|QVG_USE_FBO
argument_list|)
if|if
condition|(
name|fbo
condition|)
block|{
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|texture
argument_list|)
expr_stmt|;
name|glDeleteFramebuffersEXT
argument_list|(
literal|1
argument_list|,
operator|&
name|fbo
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_destructor
begin_function
DECL|function|ensureContext
name|void
name|ShivaVGWindowSurfacePrivate
operator|::
name|ensureContext
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|Window
name|win
init|=
name|widget
operator|->
name|winId
argument_list|()
decl_stmt|;
if|if
condition|(
name|win
operator|!=
name|drawable
condition|)
block|{
if|if
condition|(
name|context
condition|)
name|glXDestroyContext
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|context
argument_list|)
expr_stmt|;
name|drawable
operator|=
name|win
expr_stmt|;
block|}
if|if
condition|(
name|context
operator|==
literal|0
condition|)
block|{
specifier|const
name|QX11Info
modifier|*
name|xinfo
init|=
name|qt_x11Info
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|int
name|spec
index|[
literal|64
index|]
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_DOUBLEBUFFER
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_DEPTH_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_STENCIL_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_RGBA
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_RED_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_GREEN_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_BLUE_SIZE
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_SAMPLE_BUFFERS_ARB
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|1
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
name|GLX_SAMPLES_ARB
expr_stmt|;
name|spec
index|[
name|i
operator|++
index|]
operator|=
literal|4
expr_stmt|;
name|spec
index|[
name|i
index|]
operator|=
name|XNone
expr_stmt|;
name|XVisualInfo
modifier|*
name|visual
init|=
name|glXChooseVisual
argument_list|(
name|xinfo
operator|->
name|display
argument_list|()
argument_list|,
name|xinfo
operator|->
name|screen
argument_list|()
argument_list|,
name|spec
argument_list|)
decl_stmt|;
name|context
operator|=
name|glXCreateContext
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|visual
argument_list|,
literal|0
argument_list|,
name|True
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|context
condition|)
name|qWarning
argument_list|(
literal|"glXCreateContext: could not create GL context for VG rendering"
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|QVG_USE_FBO
argument_list|)
if|if
condition|(
name|needsResize
operator|&&
name|fbo
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXMakeCurrent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|drawable
argument_list|,
name|context
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|texture
argument_list|)
expr_stmt|;
name|glDeleteFramebuffersEXT
argument_list|(
literal|1
argument_list|,
operator|&
name|fbo
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXMakeCurrent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fbo
operator|=
literal|0
expr_stmt|;
name|texture
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|fbo
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXMakeCurrent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|drawable
argument_list|,
name|context
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|glGenFramebuffersEXT
argument_list|(
literal|1
argument_list|,
operator|&
name|fbo
argument_list|)
expr_stmt|;
name|glBindFramebufferEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
name|fbo
argument_list|)
expr_stmt|;
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
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA8
argument_list|,
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|size
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
name|NULL
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glFramebufferTexture2DEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
name|GL_COLOR_ATTACHMENT0_EXT
argument_list|,
name|GL_TEXTURE_2D
argument_list|,
name|texture
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glBindFramebufferEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXMakeCurrent
argument_list|(
name|X11
operator|->
name|display
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
endif|#
directive|endif
name|needsResize
operator|=
literal|false
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|ShivaVGWindowSurface
name|ShivaVGWindowSurface
operator|::
name|ShivaVGWindowSurface
parameter_list|(
name|QWidget
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QWindowSurface
argument_list|(
name|window
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|ShivaVGWindowSurfacePrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~ShivaVGWindowSurface
name|ShivaVGWindowSurface
operator|::
name|~
name|ShivaVGWindowSurface
parameter_list|()
block|{
if|if
condition|(
name|d_ptr
operator|->
name|isCurrent
condition|)
block|{
name|shivaContext
argument_list|()
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
name|glBindFramebufferEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
if|if
condition|(
name|d_ptr
operator|->
name|context
condition|)
name|glXDestroyContext
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|d_ptr
operator|->
name|context
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|ShivaVGWindowSurface
operator|::
name|paintDevice
parameter_list|()
block|{
name|d_ptr
operator|->
name|ensureContext
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
name|shivaContext
argument_list|()
operator|->
name|makeCurrent
argument_list|(
name|d_ptr
argument_list|)
expr_stmt|;
name|glClearDepth
argument_list|(
literal|0.0f
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_DEPTH_BUFFER_BIT
operator||
name|GL_STENCIL_BUFFER_BIT
argument_list|)
expr_stmt|;
return|return
name|this
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|ShivaVGWindowSurface
operator|::
name|flush
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|,
specifier|const
name|QPoint
modifier|&
name|offset
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|parent
init|=
name|widget
operator|->
name|internalWinId
argument_list|()
condition|?
name|widget
else|:
name|widget
operator|->
name|nativeParentWidget
argument_list|()
decl_stmt|;
name|d_ptr
operator|->
name|ensureContext
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|QShivaContext
modifier|*
name|context
init|=
name|shivaContext
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|isCurrent
condition|)
name|context
operator|->
name|makeCurrent
argument_list|(
name|d_ptr
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|QVG_USE_FBO
argument_list|)
name|glBindFramebufferEXT
argument_list|(
name|GL_FRAMEBUFFER_EXT
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|d_ptr
operator|->
name|fbo
condition|)
block|{
specifier|static
name|GLfloat
specifier|const
name|vertices
index|[]
index|[
literal|2
index|]
init|=
block|{
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|1
block|,
operator|-
literal|1
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|1
block|}
block|}
decl_stmt|;
specifier|static
name|GLfloat
specifier|const
name|texCoords
index|[]
index|[
literal|2
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|0
block|}
block|,
block|{
literal|1
block|,
literal|1
block|}
block|,
block|{
literal|0
block|,
literal|1
block|}
block|}
decl_stmt|;
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
name|glVertexPointer
argument_list|(
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
name|vertices
argument_list|)
expr_stmt|;
name|glTexCoordPointer
argument_list|(
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
name|texCoords
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d_ptr
operator|->
name|texture
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_TEXTURE_COORD_ARRAY
argument_list|)
expr_stmt|;
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_FAN
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|glDisableClientState
argument_list|(
name|GL_TEXTURE_COORD_ARRAY
argument_list|)
expr_stmt|;
name|glDisableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|glXSwapBuffers
argument_list|(
name|X11
operator|->
name|display
argument_list|,
name|d_ptr
operator|->
name|drawable
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setGeometry
name|void
name|ShivaVGWindowSurface
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|QWindowSurface
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|d_ptr
operator|->
name|needsResize
operator|=
literal|true
expr_stmt|;
name|d_ptr
operator|->
name|size
operator|=
name|rect
operator|.
name|size
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scroll
name|bool
name|ShivaVGWindowSurface
operator|::
name|scroll
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|area
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
block|{
return|return
name|QWindowSurface
operator|::
name|scroll
argument_list|(
name|area
argument_list|,
name|dx
argument_list|,
name|dy
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|ShivaVGWindowSurface
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
comment|// Nothing to do here.
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|ShivaVGWindowSurface
operator|::
name|endPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
comment|// Nothing to do here.
name|Q_UNUSED
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|Q_GLOBAL_STATIC
argument_list|(
name|QVGPaintEngine
argument_list|,
name|sharedPaintEngine
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|ShivaVGWindowSurface
operator|::
name|paintEngine
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|d_ptr
operator|->
name|engine
condition|)
name|d_ptr
operator|->
name|engine
operator|=
name|sharedPaintEngine
argument_list|()
expr_stmt|;
return|return
name|d_ptr
operator|->
name|engine
return|;
block|}
end_function
begin_function
DECL|function|metric
name|int
name|ShivaVGWindowSurface
operator|::
name|metric
parameter_list|(
name|PaintDeviceMetric
name|met
parameter_list|)
specifier|const
block|{
return|return
name|qt_paint_device_metric
argument_list|(
name|window
argument_list|()
argument_list|,
name|met
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
