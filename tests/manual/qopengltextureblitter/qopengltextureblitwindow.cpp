begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qopengltextureblitwindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QPainter>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLTexture>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/QMatrix4x4>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_constructor
DECL|function|QOpenGLTextureBlitWindow
name|QOpenGLTextureBlitWindow
operator|::
name|QOpenGLTextureBlitWindow
parameter_list|()
member_init_list|:
name|QWindow
argument_list|()
member_init_list|,
name|m_context
argument_list|(
operator|new
name|QOpenGLContext
argument_list|(
name|this
argument_list|)
argument_list|)
block|{
name|resize
argument_list|(
literal|500
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|setSurfaceType
argument_list|(
name|OpenGLSurface
argument_list|)
expr_stmt|;
name|QSurfaceFormat
name|surfaceFormat
init|=
name|format
argument_list|()
decl_stmt|;
if|if
condition|(
name|QCoreApplication
operator|::
name|arguments
argument_list|()
operator|.
name|contains
argument_list|(
name|QStringLiteral
argument_list|(
literal|"-coreprofile"
argument_list|)
argument_list|)
condition|)
block|{
name|surfaceFormat
operator|.
name|setVersion
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|surfaceFormat
operator|.
name|setProfile
argument_list|(
name|QSurfaceFormat
operator|::
name|CoreProfile
argument_list|)
expr_stmt|;
block|}
name|setFormat
argument_list|(
name|surfaceFormat
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|setFormat
argument_list|(
name|surfaceFormat
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|create
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|render
name|void
name|QOpenGLTextureBlitWindow
operator|::
name|render
parameter_list|()
block|{
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|QRect
name|viewport
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
name|QOpenGLFunctions
modifier|*
name|functions
init|=
name|m_context
operator|->
name|functions
argument_list|()
decl_stmt|;
name|functions
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
name|functions
operator|->
name|glClearColor
argument_list|(
literal|0.f
argument_list|,
literal|.6f
argument_list|,
literal|.0f
argument_list|,
literal|0.f
argument_list|)
expr_stmt|;
name|functions
operator|->
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|QOpenGLTexture
name|texture
argument_list|(
name|m_image
argument_list|)
decl_stmt|;
name|texture
operator|.
name|setWrapMode
argument_list|(
name|QOpenGLTexture
operator|::
name|ClampToEdge
argument_list|)
expr_stmt|;
name|texture
operator|.
name|create
argument_list|()
expr_stmt|;
name|QOpenGLTexture
name|texture_mirrored
argument_list|(
name|m_image_mirrord
argument_list|)
decl_stmt|;
name|texture_mirrored
operator|.
name|setWrapMode
argument_list|(
name|QOpenGLTexture
operator|::
name|ClampToEdge
argument_list|)
expr_stmt|;
name|texture_mirrored
operator|.
name|create
argument_list|()
expr_stmt|;
name|QRectF
name|topLeftOriginTopLeft
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|dWidth
argument_list|()
operator|/
literal|2.0
argument_list|,
name|dHeight
argument_list|()
operator|/
literal|2.0
argument_list|)
argument_list|)
decl_stmt|;
name|QRectF
name|topRightOriginTopLeft
argument_list|(
name|QPointF
argument_list|(
name|dWidth
argument_list|()
operator|/
literal|2.0
argument_list|,
literal|0
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|dWidth
argument_list|()
argument_list|,
name|dHeight
argument_list|()
operator|/
literal|2.0
argument_list|)
argument_list|)
decl_stmt|;
name|QRectF
name|bottomLeftOriginTopLeft
argument_list|(
name|QPointF
argument_list|(
literal|0
argument_list|,
name|dHeight
argument_list|()
operator|/
literal|2.0
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|dWidth
argument_list|()
operator|/
literal|2.0
argument_list|,
name|dHeight
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QRectF
name|bottomRightOriginTopLeft
argument_list|(
name|QPoint
argument_list|(
name|dWidth
argument_list|()
operator|/
literal|2.0
argument_list|,
name|dHeight
argument_list|()
operator|/
literal|2.0
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|dWidth
argument_list|()
argument_list|,
name|dHeight
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QRectF
name|topLeftOriginBottomLeft
init|=
name|bottomLeftOriginTopLeft
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|topLeftOriginBottomLeft
argument_list|)
expr_stmt|;
name|QRectF
name|topRightOriginBottomLeft
init|=
name|bottomRightOriginTopLeft
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|topRightOriginBottomLeft
argument_list|)
expr_stmt|;
name|QRectF
name|bottomLeftOriginBottomLeft
init|=
name|topLeftOriginTopLeft
decl_stmt|;
name|QRectF
name|bottomRightOriginBottomLeft
init|=
name|topRightOriginTopLeft
decl_stmt|;
name|QOpenGLTextureBlitter
operator|::
name|Origin
name|topLeftOrigin
init|=
name|QOpenGLTextureBlitter
operator|::
name|OriginTopLeft
decl_stmt|;
name|QOpenGLTextureBlitter
operator|::
name|Origin
name|bottomLeftOrigin
init|=
name|QOpenGLTextureBlitter
operator|::
name|OriginBottomLeft
decl_stmt|;
name|QMatrix4x4
name|topRightOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|topRightOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|bottomLeftOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|bottomLeftOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|bottomRightOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|bottomRightOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|QMatrix3x3
name|texTopLeftOriginTopLeft
init|=
name|QOpenGLTextureBlitter
operator|::
name|sourceTransform
argument_list|(
name|topLeftOriginTopLeft
argument_list|,
name|m_image
operator|.
name|size
argument_list|()
argument_list|,
name|topLeftOrigin
argument_list|)
decl_stmt|;
name|QMatrix3x3
name|texTopRightOriginBottomLeft
init|=
name|QOpenGLTextureBlitter
operator|::
name|sourceTransform
argument_list|(
name|topRightOriginBottomLeft
argument_list|,
name|m_image
operator|.
name|size
argument_list|()
argument_list|,
name|bottomLeftOrigin
argument_list|)
decl_stmt|;
name|QMatrix3x3
name|texBottomLeftOriginBottomLeft
init|=
name|QOpenGLTextureBlitter
operator|::
name|sourceTransform
argument_list|(
name|bottomLeftOriginBottomLeft
argument_list|,
name|m_image
operator|.
name|size
argument_list|()
argument_list|,
name|bottomLeftOrigin
argument_list|)
decl_stmt|;
name|QMatrix3x3
name|texBottomRightOriginBottomLeft
init|=
name|QOpenGLTextureBlitter
operator|::
name|sourceTransform
argument_list|(
name|bottomRightOriginBottomLeft
argument_list|,
name|m_image
operator|.
name|size
argument_list|()
argument_list|,
name|bottomLeftOrigin
argument_list|)
decl_stmt|;
name|QSizeF
name|subSize
argument_list|(
name|topLeftOriginTopLeft
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|topLeftOriginTopLeft
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
decl_stmt|;
name|QRectF
name|subTopLeftOriginTopLeft
argument_list|(
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
argument_list|,
name|subSize
argument_list|)
decl_stmt|;
name|QRectF
name|subTopRightOriginTopLeft
argument_list|(
name|QPointF
argument_list|(
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
operator|.
name|x
argument_list|()
operator|+
name|topLeftOriginTopLeft
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
operator|.
name|y
argument_list|()
argument_list|)
argument_list|,
name|subSize
argument_list|)
decl_stmt|;
name|QRectF
name|subBottomLeftOriginTopLeft
argument_list|(
name|QPointF
argument_list|(
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
operator|.
name|x
argument_list|()
argument_list|,
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|topLeftOriginTopLeft
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|,
name|subSize
argument_list|)
decl_stmt|;
name|QRectF
name|subBottomRightOriginTopLeft
argument_list|(
name|QPointF
argument_list|(
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
operator|.
name|x
argument_list|()
operator|+
name|topLeftOriginTopLeft
operator|.
name|width
argument_list|()
operator|/
literal|2
argument_list|,
name|topLeftOriginTopLeft
operator|.
name|topLeft
argument_list|()
operator|.
name|y
argument_list|()
operator|+
name|topLeftOriginTopLeft
operator|.
name|height
argument_list|()
operator|/
literal|2
argument_list|)
argument_list|,
name|subSize
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|subTopLeftOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|subTopLeftOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|subTopRightOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|subTopRightOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|subBottomLeftOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|subBottomLeftOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|QMatrix4x4
name|subBottomRightOriginTopLeftVertex
init|=
name|QOpenGLTextureBlitter
operator|::
name|targetTransform
argument_list|(
name|subBottomRightOriginTopLeft
argument_list|,
name|viewport
argument_list|)
decl_stmt|;
name|m_blitter
operator|.
name|bind
argument_list|()
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture_mirrored
operator|.
name|textureId
argument_list|()
argument_list|,
name|subTopLeftOriginTopLeftVertex
argument_list|,
name|texBottomRightOriginBottomLeft
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture_mirrored
operator|.
name|textureId
argument_list|()
argument_list|,
name|subTopRightOriginTopLeftVertex
argument_list|,
name|texBottomLeftOriginBottomLeft
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture
operator|.
name|textureId
argument_list|()
argument_list|,
name|subBottomLeftOriginTopLeftVertex
argument_list|,
name|texTopRightOriginBottomLeft
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture
operator|.
name|textureId
argument_list|()
argument_list|,
name|subBottomRightOriginTopLeftVertex
argument_list|,
name|texTopLeftOriginTopLeft
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture
operator|.
name|textureId
argument_list|()
argument_list|,
name|topRightOriginTopLeftVertex
argument_list|,
name|topLeftOrigin
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture_mirrored
operator|.
name|textureId
argument_list|()
argument_list|,
name|bottomLeftOriginTopLeftVertex
argument_list|,
name|topLeftOrigin
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|setSwizzleRB
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|blit
argument_list|(
name|texture
operator|.
name|textureId
argument_list|()
argument_list|,
name|bottomRightOriginTopLeftVertex
argument_list|,
name|texTopLeftOriginTopLeft
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
name|setSwizzleRB
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|m_blitter
operator|.
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
name|QOpenGLTextureBlitWindow
operator|::
name|exposeEvent
parameter_list|(
name|QExposeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|render
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|QOpenGLTextureBlitWindow
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|m_image
operator|=
name|QImage
argument_list|(
name|size
argument_list|()
operator|*
name|devicePixelRatio
argument_list|()
argument_list|,
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
expr_stmt|;
name|m_image
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|m_image
argument_list|)
decl_stmt|;
name|QPen
name|pen
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
decl_stmt|;
name|pen
operator|.
name|setWidth
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|pen
argument_list|)
expr_stmt|;
name|QFont
name|font
init|=
name|p
operator|.
name|font
argument_list|()
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
name|qMin
argument_list|(
name|m_image
operator|.
name|height
argument_list|()
argument_list|,
name|m_image
operator|.
name|width
argument_list|()
argument_list|)
operator|/
literal|20
argument_list|)
expr_stmt|;
name|p
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|int
name|dx
init|=
name|dWidth
argument_list|()
operator|/
literal|5
decl_stmt|;
name|int
name|dy
init|=
name|dHeight
argument_list|()
operator|/
literal|5
decl_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
literal|5
condition|;
name|y
operator|++
control|)
block|{
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
literal|5
condition|;
name|x
operator|++
control|)
block|{
name|QRect
name|textRect
argument_list|(
name|x
operator|*
name|dx
argument_list|,
name|y
operator|*
name|dy
argument_list|,
name|dx
argument_list|,
name|dy
argument_list|)
decl_stmt|;
name|QString
name|text
init|=
name|QString
argument_list|(
literal|"[%1,%2]"
argument_list|)
operator|.
name|arg
argument_list|(
name|x
argument_list|)
operator|.
name|arg
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|textRect
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
block|}
name|p
operator|.
name|drawRect
argument_list|(
name|QRectF
argument_list|(
literal|2.5
argument_list|,
literal|2.5
argument_list|,
name|dWidth
argument_list|()
operator|-
literal|5
argument_list|,
name|dHeight
argument_list|()
operator|-
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|m_image_mirrord
operator|=
name|m_image
operator|.
name|mirrored
argument_list|(
literal|false
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
