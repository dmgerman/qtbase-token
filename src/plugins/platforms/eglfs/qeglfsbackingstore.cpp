begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfsbackingstore.h"
end_include
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|"qeglfswindow.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLPaintDevice>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QtGui/QScreen>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSBackingStore
name|QEglFSBackingStore
operator|::
name|QEglFSBackingStore
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
name|m_context
argument_list|(
operator|new
name|QOpenGLContext
argument_list|)
member_init_list|,
name|m_texture
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_program
argument_list|(
literal|0
argument_list|)
block|{
name|m_context
operator|->
name|setFormat
argument_list|(
name|window
operator|->
name|requestedFormat
argument_list|()
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|setScreen
argument_list|(
name|window
operator|->
name|screen
argument_list|()
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|create
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSBackingStore
name|QEglFSBackingStore
operator|::
name|~
name|QEglFSBackingStore
parameter_list|()
block|{
operator|delete
name|m_context
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintDevice
name|QPaintDevice
modifier|*
name|QEglFSBackingStore
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
DECL|function|flush
name|void
name|QEglFSBackingStore
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
name|makeCurrent
argument_list|()
expr_stmt|;
name|QRectF
name|sr
init|=
name|window
operator|->
name|screen
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|sr
operator|.
name|width
argument_list|()
argument_list|,
name|sr
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QEGL_EXTRA_DEBUG
name|qWarning
argument_list|(
literal|"QEglBackingStore::flush %p"
argument_list|,
name|window
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|m_program
condition|)
block|{
specifier|static
specifier|const
name|char
modifier|*
name|textureVertexProgram
init|=
literal|"attribute highp vec2 vertexCoordEntry;\n"
literal|"attribute highp vec2 textureCoordEntry;\n"
literal|"varying highp vec2 textureCoord;\n"
literal|"void main() {\n"
literal|"   textureCoord = textureCoordEntry;\n"
literal|"   gl_Position = vec4(vertexCoordEntry, 0.0, 1.0);\n"
literal|"}\n"
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|textureFragmentProgram
init|=
literal|"uniform sampler2D texture;\n"
literal|"varying highp vec2 textureCoord;\n"
literal|"void main() {\n"
literal|"   gl_FragColor = texture2D(texture, textureCoord).bgra;\n"
literal|"}\n"
decl_stmt|;
name|m_program
operator|=
operator|new
name|QOpenGLShaderProgram
expr_stmt|;
name|m_program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|,
name|textureVertexProgram
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|addShaderFromSourceCode
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|,
name|textureFragmentProgram
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|link
argument_list|()
expr_stmt|;
name|m_vertexCoordEntry
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"vertexCoordEntry"
argument_list|)
expr_stmt|;
name|m_textureCoordEntry
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"textureCoordEntry"
argument_list|)
expr_stmt|;
block|}
name|m_program
operator|->
name|bind
argument_list|()
expr_stmt|;
specifier|const
name|GLfloat
name|textureCoordinates
index|[]
init|=
block|{
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|QRectF
name|r
init|=
name|window
operator|->
name|geometry
argument_list|()
decl_stmt|;
name|GLfloat
name|x1
init|=
operator|(
name|r
operator|.
name|left
argument_list|()
operator|/
name|sr
operator|.
name|width
argument_list|()
operator|)
operator|*
literal|2
operator|-
literal|1
decl_stmt|;
name|GLfloat
name|x2
init|=
operator|(
name|r
operator|.
name|right
argument_list|()
operator|/
name|sr
operator|.
name|width
argument_list|()
operator|)
operator|*
literal|2
operator|-
literal|1
decl_stmt|;
name|GLfloat
name|y1
init|=
operator|(
name|r
operator|.
name|top
argument_list|()
operator|/
name|sr
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
operator|-
literal|1
decl_stmt|;
name|GLfloat
name|y2
init|=
operator|(
name|r
operator|.
name|bottom
argument_list|()
operator|/
name|sr
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
operator|-
literal|1
decl_stmt|;
specifier|const
name|GLfloat
name|vertexCoordinates
index|[]
init|=
block|{
name|x1
block|,
name|y1
block|,
name|x2
block|,
name|y1
block|,
name|x2
block|,
name|y2
block|,
name|x1
block|,
name|y2
block|}
decl_stmt|;
name|glEnableVertexAttribArray
argument_list|(
name|m_vertexCoordEntry
argument_list|)
expr_stmt|;
name|glEnableVertexAttribArray
argument_list|(
name|m_textureCoordEntry
argument_list|)
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|m_vertexCoordEntry
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|vertexCoordinates
argument_list|)
expr_stmt|;
name|glVertexAttribPointer
argument_list|(
name|m_textureCoordEntry
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|textureCoordinates
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_texture
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_dirty
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QRect
name|imageRect
init|=
name|m_image
operator|.
name|rect
argument_list|()
decl_stmt|;
name|QRegion
name|fixed
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
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_FAN
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|release
argument_list|()
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glDisableVertexAttribArray
argument_list|(
name|m_vertexCoordEntry
argument_list|)
expr_stmt|;
name|glDisableVertexAttribArray
argument_list|(
name|m_textureCoordEntry
argument_list|)
expr_stmt|;
comment|// draw the cursor
if|if
condition|(
name|QEglFSCursor
modifier|*
name|cursor
init|=
cast|static_cast
argument_list|<
name|QEglFSCursor
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
operator|->
name|cursor
argument_list|()
argument_list|)
condition|)
name|cursor
operator|->
name|paintOnScreen
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|window
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|doneCurrent
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|makeCurrent
name|void
name|QEglFSBackingStore
operator|::
name|makeCurrent
parameter_list|()
block|{
operator|(
cast|static_cast
argument_list|<
name|QEglFSWindow
operator|*
argument_list|>
argument_list|(
name|window
argument_list|()
operator|->
name|handle
argument_list|()
argument_list|)
operator|)
operator|->
name|create
argument_list|()
expr_stmt|;
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|window
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|beginPaint
name|void
name|QEglFSBackingStore
operator|::
name|beginPaint
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
block|{
name|m_dirty
operator|=
name|m_dirty
operator||
name|rgn
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endPaint
name|void
name|QEglFSBackingStore
operator|::
name|endPaint
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|resize
name|void
name|QEglFSBackingStore
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
name|m_image
operator|=
name|QImage
argument_list|(
name|size
argument_list|,
name|QImage
operator|::
name|Format_RGB32
argument_list|)
expr_stmt|;
name|makeCurrent
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_texture
condition|)
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_texture
argument_list|)
expr_stmt|;
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_texture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_texture
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
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
