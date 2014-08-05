begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwinrtbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtscreen.h"
end_include
begin_include
include|#
directive|include
file|"qwinrtwindow.h"
end_include
begin_include
include|#
directive|include
file|"qwinrteglcontext.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFramebufferObject>
end_include
begin_include
include|#
directive|include
file|<GLES3/gl3.h>
end_include
begin_include
include|#
directive|include
file|<GLES3/gl3ext.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QWinRTBackingStorePrivate
class|class
name|QWinRTBackingStorePrivate
block|{
public|public:
DECL|member|initialized
name|bool
name|initialized
decl_stmt|;
DECL|member|size
name|QSize
name|size
decl_stmt|;
DECL|member|context
name|QScopedPointer
argument_list|<
name|QOpenGLContext
argument_list|>
name|context
decl_stmt|;
DECL|member|fbo
name|QScopedPointer
argument_list|<
name|QOpenGLFramebufferObject
argument_list|>
name|fbo
decl_stmt|;
DECL|member|screen
name|QWinRTScreen
modifier|*
name|screen
decl_stmt|;
DECL|member|paintDevice
name|QImage
name|paintDevice
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|QWinRTBackingStore
name|QWinRTBackingStore
operator|::
name|QWinRTBackingStore
parameter_list|(
name|QWindow
modifier|*
name|window
parameter_list|)
member_init_list|:
name|QPlatformBackingStore
argument_list|(
name|window
argument_list|)
member_init_list|,
name|d_ptr
argument_list|(
operator|new
name|QWinRTBackingStorePrivate
argument_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTBackingStore
argument_list|)
expr_stmt|;
name|d
operator|->
name|initialized
operator|=
literal|false
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
name|window
operator|->
name|screen
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
name|window
operator|->
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
comment|// Required for flipping, but could be done in the swap
block|}
end_constructor
begin_function
DECL|function|initialize
name|bool
name|QWinRTBackingStore
operator|::
name|initialize
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinRTBackingStore
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|initialized
condition|)
return|return
literal|true
return|;
name|d
operator|->
name|context
operator|.
name|reset
argument_list|(
operator|new
name|QOpenGLContext
argument_list|)
expr_stmt|;
name|QSurfaceFormat
name|format
init|=
name|window
argument_list|()
operator|->
name|requestedFormat
argument_list|()
decl_stmt|;
name|format
operator|.
name|setVersion
argument_list|(
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// Required for ES3 framebuffer blit
name|d
operator|->
name|context
operator|->
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|setScreen
argument_list|(
name|window
argument_list|()
operator|->
name|screen
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|context
operator|->
name|create
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
operator|!
name|d
operator|->
name|context
operator|->
name|makeCurrent
argument_list|(
name|window
argument_list|()
argument_list|)
condition|)
return|return
literal|false
return|;
name|d
operator|->
name|context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
name|d
operator|->
name|initialized
operator|=
literal|true
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_destructor
DECL|function|~QWinRTBackingStore
name|QWinRTBackingStore
operator|::
name|~
name|QWinRTBackingStore
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QWinRTBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWinRTBackingStore
argument_list|)
expr_stmt|;
return|return
operator|&
name|d
operator|->
name|paintDevice
return|;
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QWinRTBackingStore
operator|::
name|flush
parameter_list|(
name|QWindow
modifier|*
name|window
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
name|Q_D
argument_list|(
name|QWinRTBackingStore
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|offset
argument_list|)
if|if
condition|(
name|d
operator|->
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
specifier|const
name|bool
name|ok
init|=
name|d
operator|->
name|context
operator|->
name|makeCurrent
argument_list|(
name|window
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"unable to flush"
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|bounds
init|=
name|region
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|d
operator|->
name|fbo
operator|->
name|texture
argument_list|()
argument_list|)
expr_stmt|;
comment|// TODO: when ANGLE GLES3 support is finished, use the glPixelStorei functions to minimize upload
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|bounds
operator|.
name|y
argument_list|()
argument_list|,
name|d
operator|->
name|size
operator|.
name|width
argument_list|()
argument_list|,
name|bounds
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|d
operator|->
name|paintDevice
operator|.
name|constScanLine
argument_list|(
name|bounds
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_READ_FRAMEBUFFER
argument_list|,
name|d
operator|->
name|fbo
operator|->
name|handle
argument_list|()
argument_list|)
expr_stmt|;
name|glBindFramebuffer
argument_list|(
name|GL_DRAW_FRAMEBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
specifier|const
name|int
name|y1
init|=
name|bounds
operator|.
name|height
argument_list|()
operator|+
name|bounds
operator|.
name|y
argument_list|()
decl_stmt|;
specifier|const
name|int
name|y2
init|=
name|d
operator|->
name|size
operator|.
name|height
argument_list|()
operator|-
name|y1
decl_stmt|;
specifier|const
name|int
name|x1
init|=
name|bounds
operator|.
name|x
argument_list|()
decl_stmt|;
specifier|const
name|int
name|x2
init|=
name|x1
operator|+
name|bounds
operator|.
name|width
argument_list|()
decl_stmt|;
name|glBlitFramebuffer
argument_list|(
name|x1
argument_list|,
name|y2
argument_list|,
name|x2
argument_list|,
name|y1
argument_list|,
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|,
name|GL_COLOR_BUFFER_BIT
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|swapBuffers
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QWinRTBackingStore
operator|::
name|resize
parameter_list|(
specifier|const
name|QSize
modifier|&
name|size
parameter_list|,
specifier|const
name|QRegion
modifier|&
name|staticContents
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWinRTBackingStore
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
argument|staticContents
argument_list|)
if|if
condition|(
operator|!
name|initialize
argument_list|()
condition|)
return|return;
if|if
condition|(
name|d
operator|->
name|size
operator|==
name|size
condition|)
return|return;
name|d
operator|->
name|size
operator|=
name|size
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|size
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|d
operator|->
name|paintDevice
operator|=
name|QImage
argument_list|(
name|d
operator|->
name|size
argument_list|,
name|QImage
operator|::
name|Format_RGBA8888_Premultiplied
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|ok
init|=
name|d
operator|->
name|context
operator|->
name|makeCurrent
argument_list|(
name|window
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
name|qWarning
argument_list|(
literal|"unable to resize"
argument_list|)
expr_stmt|;
name|d
operator|->
name|fbo
operator|.
name|reset
argument_list|(
operator|new
name|QOpenGLFramebufferObject
argument_list|(
name|d
operator|->
name|size
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QWinRTBackingStore
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWinRTBackingStore
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|paintDevice
return|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QWinRTBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|resize
argument_list|(
name|window
argument_list|()
operator|->
name|size
argument_list|()
argument_list|,
name|region
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QWinRTBackingStore
operator|::
name|endPaint
parameter_list|()
block|{ }
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
