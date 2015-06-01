begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|"qopenglcompositorbackingstore_p.h"
end_include
begin_include
include|#
directive|include
file|"qopenglcompositor_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QOpenGLCompositorBackingStore     \brief A backing store implementation for OpenGL     \since 5.4     \internal     \ingroup qpa      This implementation uploads raster-rendered widget windows into     textures. It is meant to be used with QOpenGLCompositor that     composites the textures onto a single native window using OpenGL.     This means that multiple top-level widgets are supported without     creating actual native windows for each of them.      \note It is important to call notifyComposited() from the     corresponding platform window's endCompositing() callback     (inherited from QOpenGLCompositorWindow).      \note When implementing QOpenGLCompositorWindow::textures() for     windows of type RasterSurface or RasterGLSurface, simply return     the list provided by this class' textures(). */
end_comment
begin_constructor
DECL|function|QOpenGLCompositorBackingStore
name|QOpenGLCompositorBackingStore
operator|::
name|QOpenGLCompositorBackingStore
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
name|m_window
argument_list|(
name|window
argument_list|)
member_init_list|,
name|m_bsTexture
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_textures
argument_list|(
operator|new
name|QPlatformTextureList
argument_list|)
member_init_list|,
name|m_lockedWidgetTextures
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QOpenGLCompositorBackingStore
name|QOpenGLCompositorBackingStore
operator|::
name|~
name|QOpenGLCompositorBackingStore
parameter_list|()
block|{
operator|delete
name|m_textures
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QOpenGLCompositorBackingStore
operator|::
name|paintDevice
parameter_list|()
block|{
return|return
operator|&
name|m_image
return|;
block|}
end_function
begin_function
DECL|function|updateTexture
name|void
name|QOpenGLCompositorBackingStore
operator|::
name|updateTexture
parameter_list|()
block|{
if|if
condition|(
operator|!
name|m_bsTexture
condition|)
block|{
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_bsTexture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_bsTexture
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
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
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_bsTexture
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_dirty
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QRegion
name|fixed
decl_stmt|;
name|QRect
name|imageRect
init|=
name|m_image
operator|.
name|rect
argument_list|()
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|m_dirty
operator|.
name|rects
argument_list|()
control|)
block|{
comment|// intersect with image rect to be sure
name|QRect
name|r
init|=
name|imageRect
operator|&
name|rect
decl_stmt|;
comment|// if the rect is wide enough it's cheaper to just
comment|// extend it instead of doing an image copy
if|if
condition|(
name|r
operator|.
name|width
argument_list|()
operator|>=
name|imageRect
operator|.
name|width
argument_list|()
operator|/
literal|2
condition|)
block|{
name|r
operator|.
name|setX
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|r
operator|.
name|setWidth
argument_list|(
name|imageRect
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|fixed
operator||=
name|r
expr_stmt|;
block|}
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|rect
decl|,
name|fixed
operator|.
name|rects
argument_list|()
control|)
block|{
comment|// if the sub-rect is full-width we can pass the image data directly to
comment|// OpenGL instead of copying, since there's no gap between scanlines
if|if
condition|(
name|rect
operator|.
name|width
argument_list|()
operator|==
name|imageRect
operator|.
name|width
argument_list|()
condition|)
block|{
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|m_image
operator|.
name|constScanLine
argument_list|(
name|rect
operator|.
name|y
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|rect
operator|.
name|x
argument_list|()
argument_list|,
name|rect
operator|.
name|y
argument_list|()
argument_list|,
name|rect
operator|.
name|width
argument_list|()
argument_list|,
name|rect
operator|.
name|height
argument_list|()
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|m_image
operator|.
name|copy
argument_list|(
name|rect
argument_list|)
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|m_dirty
operator|=
name|QRegion
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|flush
name|void
name|QOpenGLCompositorBackingStore
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
comment|// Called for ordinary raster windows. This is rare since RasterGLSurface
comment|// support is claimed which leads to having all QWidget windows marked as
comment|// RasterGLSurface instead of just Raster. These go through
comment|// compositeAndFlush() instead of this function.
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
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QOpenGLContext
modifier|*
name|dstCtx
init|=
name|compositor
operator|->
name|context
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|dstWin
init|=
name|compositor
operator|->
name|targetWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dstWin
condition|)
return|return;
name|dstCtx
operator|->
name|makeCurrent
argument_list|(
name|dstWin
argument_list|)
expr_stmt|;
name|updateTexture
argument_list|()
expr_stmt|;
name|m_textures
operator|->
name|clear
argument_list|()
expr_stmt|;
name|m_textures
operator|->
name|appendTexture
argument_list|(
name|Q_NULLPTR
argument_list|,
name|m_bsTexture
argument_list|,
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|compositor
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|composeAndFlush
name|void
name|QOpenGLCompositorBackingStore
operator|::
name|composeAndFlush
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
parameter_list|,
name|QPlatformTextureList
modifier|*
name|textures
parameter_list|,
name|QOpenGLContext
modifier|*
name|context
parameter_list|,
name|bool
name|translucentBackground
parameter_list|)
block|{
comment|// QOpenGLWidget/QQuickWidget content provided as textures. The raster content should go on top.
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
name|Q_UNUSED
argument_list|(
name|context
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|translucentBackground
argument_list|)
expr_stmt|;
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QOpenGLContext
modifier|*
name|dstCtx
init|=
name|compositor
operator|->
name|context
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|dstWin
init|=
name|compositor
operator|->
name|targetWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dstWin
condition|)
return|return;
name|dstCtx
operator|->
name|makeCurrent
argument_list|(
name|dstWin
argument_list|)
expr_stmt|;
name|m_textures
operator|->
name|clear
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|textures
operator|->
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|m_textures
operator|->
name|appendTexture
argument_list|(
name|textures
operator|->
name|widget
argument_list|(
name|i
argument_list|)
argument_list|,
name|textures
operator|->
name|textureId
argument_list|(
name|i
argument_list|)
argument_list|,
name|textures
operator|->
name|geometry
argument_list|(
name|i
argument_list|)
argument_list|,
name|textures
operator|->
name|clipRect
argument_list|(
name|i
argument_list|)
argument_list|,
name|textures
operator|->
name|flags
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|updateTexture
argument_list|()
expr_stmt|;
name|m_textures
operator|->
name|appendTexture
argument_list|(
name|Q_NULLPTR
argument_list|,
name|m_bsTexture
argument_list|,
name|window
operator|->
name|geometry
argument_list|()
argument_list|)
expr_stmt|;
name|textures
operator|->
name|lock
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_lockedWidgetTextures
operator|=
name|textures
expr_stmt|;
name|compositor
operator|->
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|notifyComposited
name|void
name|QOpenGLCompositorBackingStore
operator|::
name|notifyComposited
parameter_list|()
block|{
if|if
condition|(
name|m_lockedWidgetTextures
condition|)
block|{
name|QPlatformTextureList
modifier|*
name|textureList
init|=
name|m_lockedWidgetTextures
decl_stmt|;
name|m_lockedWidgetTextures
operator|=
literal|0
expr_stmt|;
comment|// may reenter so null before unlocking
name|textureList
operator|->
name|lock
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QOpenGLCompositorBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|region
parameter_list|)
block|{
name|m_dirty
operator||=
name|region
expr_stmt|;
if|if
condition|(
name|m_image
operator|.
name|hasAlphaChannel
argument_list|()
condition|)
block|{
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
argument_list|)
decl_stmt|;
name|p
operator|.
name|setCompositionMode
argument_list|(
name|QPainter
operator|::
name|CompositionMode_Source
argument_list|)
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QRect
modifier|&
name|r
decl|,
name|region
operator|.
name|rects
argument_list|()
control|)
name|p
operator|.
name|fillRect
argument_list|(
name|r
argument_list|,
name|Qt
operator|::
name|transparent
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|resize
name|void
name|QOpenGLCompositorBackingStore
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
name|Q_UNUSED
argument_list|(
name|staticContents
argument_list|)
expr_stmt|;
name|QOpenGLCompositor
modifier|*
name|compositor
init|=
name|QOpenGLCompositor
operator|::
name|instance
argument_list|()
decl_stmt|;
name|QOpenGLContext
modifier|*
name|dstCtx
init|=
name|compositor
operator|->
name|context
argument_list|()
decl_stmt|;
name|QWindow
modifier|*
name|dstWin
init|=
name|compositor
operator|->
name|targetWindow
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|dstWin
condition|)
return|return;
name|m_image
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|QImage
operator|::
name|Format_RGBA8888
argument_list|)
expr_stmt|;
name|m_window
operator|->
name|create
argument_list|()
expr_stmt|;
name|dstCtx
operator|->
name|makeCurrent
argument_list|(
name|dstWin
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_bsTexture
condition|)
block|{
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_bsTexture
argument_list|)
expr_stmt|;
name|m_bsTexture
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|toImage
name|QImage
name|QOpenGLCompositorBackingStore
operator|::
name|toImage
parameter_list|()
specifier|const
block|{
return|return
name|m_image
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
