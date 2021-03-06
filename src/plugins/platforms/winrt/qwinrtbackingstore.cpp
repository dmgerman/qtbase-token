begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<GLES2/gl2.h>
end_include
begin_include
include|#
directive|include
file|<GLES2/gl2ext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcQpaBackingStore
argument_list|,
literal|"qt.qpa.backingstore"
argument_list|)
name|Q_LOGGING_CATEGORY
argument_list|(
name|lcQpaBackingStoreVerbose
argument_list|,
literal|"qt.qpa.backingstore.verbose"
argument_list|)
DECL|class|QWinRTBackingStorePrivate
name|class
name|QWinRTBackingStorePrivate
argument_list|{
specifier|public
operator|:
DECL|member|initialized
name|bool
name|initialized
argument_list|;
DECL|member|size
name|QSize
name|size
argument_list|;
DECL|member|context
name|QScopedPointer
argument_list|<
name|QOpenGLContext
argument_list|>
name|context
argument_list|;
DECL|member|fbo
name|QScopedPointer
argument_list|<
name|QOpenGLFramebufferObject
argument_list|>
name|fbo
argument_list|;
DECL|member|screen
name|QWinRTScreen
operator|*
name|screen
argument_list|;
DECL|member|paintDevice
name|QImage
name|paintDevice
argument_list|; }
decl_stmt|;
end_decl_stmt
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
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|window
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
if|if
condition|(
name|window
operator|->
name|surfaceType
argument_list|()
operator|==
name|QSurface
operator|::
name|RasterSurface
condition|)
name|window
operator|->
name|setSurfaceType
argument_list|(
name|QSurface
operator|::
name|OpenGLSurface
argument_list|)
expr_stmt|;
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
name|qCDebug
argument_list|(
name|lcQpaBackingStoreVerbose
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|d
operator|->
name|initialized
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
block|{
name|qCDebug
argument_list|(
name|lcQpaBackingStore
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
block|}
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
name|qCDebug
argument_list|(
name|lcQpaBackingStoreVerbose
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|window
operator|<<
name|region
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
name|GL_READ_FRAMEBUFFER_ANGLE
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
name|GL_DRAW_FRAMEBUFFER_ANGLE
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
name|y
argument_list|()
decl_stmt|;
specifier|const
name|int
name|y2
init|=
name|y1
operator|+
name|bounds
operator|.
name|height
argument_list|()
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
name|glBlitFramebufferANGLE
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|,
name|x1
argument_list|,
name|d
operator|->
name|size
operator|.
name|height
argument_list|()
operator|-
name|y1
argument_list|,
name|x2
argument_list|,
name|d
operator|->
name|size
operator|.
name|height
argument_list|()
operator|-
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
name|qCDebug
argument_list|(
name|lcQpaBackingStoreVerbose
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|size
expr_stmt|;
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
name|qCDebug
argument_list|(
name|lcQpaBackingStoreVerbose
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
operator|<<
name|region
expr_stmt|;
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
block|{
name|qCDebug
argument_list|(
name|lcQpaBackingStoreVerbose
argument_list|)
operator|<<
name|__FUNCTION__
operator|<<
name|this
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
