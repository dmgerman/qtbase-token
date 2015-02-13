begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui/QImage>
end_include
begin_include
include|#
directive|include
file|"glwidget.h"
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|GL_MULTISAMPLE
end_ifndef
begin_define
DECL|macro|GL_MULTISAMPLE
define|#
directive|define
name|GL_MULTISAMPLE
value|0x809D
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|GLWidget
name|GLWidget
operator|::
name|GLWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGLWidget
argument_list|(
name|QGLFormat
argument_list|(
name|QGL
operator|::
name|SampleBuffers
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"OpenGL pbuffers 2"
argument_list|)
argument_list|)
expr_stmt|;
name|pbuffer
operator|=
operator|new
name|QGLPixelBuffer
argument_list|(
literal|1024
argument_list|,
literal|1024
argument_list|,
name|format
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|rot_x
operator|=
name|rot_y
operator|=
name|rot_z
operator|=
literal|0.0f
expr_stmt|;
name|scale
operator|=
literal|0.1f
expr_stmt|;
name|anim
operator|=
operator|new
name|QTimeLine
argument_list|(
literal|750
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|anim
operator|->
name|setUpdateInterval
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|qreal
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|animate
argument_list|(
name|qreal
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|anim
argument_list|,
name|SIGNAL
argument_list|(
name|finished
argument_list|()
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|animFinished
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|svg_renderer
operator|=
operator|new
name|QSvgRenderer
argument_list|(
name|QLatin1String
argument_list|(
literal|":/res/bubbles.svg"
argument_list|)
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|svg_renderer
argument_list|,
name|SIGNAL
argument_list|(
name|repaintNeeded
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|draw
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|logo
operator|=
name|QImage
argument_list|(
literal|":/res/designer.png"
argument_list|)
expr_stmt|;
name|logo
operator|=
name|logo
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32
argument_list|)
expr_stmt|;
name|makeCurrent
argument_list|()
expr_stmt|;
comment|// need a current context to create the display list
name|tile_list
operator|=
name|glGenLists
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|glNewList
argument_list|(
name|tile_list
argument_list|,
name|GL_COMPILE
argument_list|)
expr_stmt|;
name|glBegin
argument_list|(
name|GL_QUADS
argument_list|)
expr_stmt|;
block|{
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glTexCoord2f
argument_list|(
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glVertex3f
argument_list|(
operator|-
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
operator|-
literal|1.0f
argument_list|)
expr_stmt|;
block|}
name|glEnd
argument_list|()
expr_stmt|;
name|glEndList
argument_list|()
expr_stmt|;
name|wave
operator|=
operator|new
name|GLfloat
index|[
name|logo
operator|.
name|width
argument_list|()
operator|*
name|logo
operator|.
name|height
argument_list|()
index|]
expr_stmt|;
name|memset
argument_list|(
name|wave
argument_list|,
literal|0
argument_list|,
name|logo
operator|.
name|width
argument_list|()
operator|*
name|logo
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|startTimer
argument_list|(
literal|30
argument_list|)
expr_stmt|;
comment|// wave timer
name|pbuffer
operator|->
name|makeCurrent
argument_list|()
expr_stmt|;
name|dynamicTexture
operator|=
name|pbuffer
operator|->
name|generateDynamicTexture
argument_list|()
expr_stmt|;
comment|// bind the dynamic texture to the pbuffer - this is a no-op under X11
name|hasDynamicTextureUpdate
operator|=
name|pbuffer
operator|->
name|bindToDynamicTexture
argument_list|(
name|dynamicTexture
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~GLWidget
name|GLWidget
operator|::
name|~
name|GLWidget
parameter_list|()
block|{
operator|delete
index|[]
name|wave
expr_stmt|;
name|glDeleteLists
argument_list|(
name|tile_list
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|pbuffer
operator|->
name|releaseFromDynamicTexture
argument_list|()
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|dynamicTexture
argument_list|)
expr_stmt|;
operator|delete
name|pbuffer
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintEvent
name|void
name|GLWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|draw
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|draw
name|void
name|GLWidget
operator|::
name|draw
parameter_list|()
block|{
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
comment|// used for text overlay
comment|// save the GL state set for QPainter
name|p
operator|.
name|beginNativePainting
argument_list|()
expr_stmt|;
name|saveGLState
argument_list|()
expr_stmt|;
comment|// render the 'bubbles.svg' file into our pbuffer
name|QPainter
name|pbuffer_painter
argument_list|(
name|pbuffer
argument_list|)
decl_stmt|;
name|svg_renderer
operator|->
name|render
argument_list|(
operator|&
name|pbuffer_painter
argument_list|)
expr_stmt|;
name|pbuffer_painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|glFlush
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|hasDynamicTextureUpdate
condition|)
name|pbuffer
operator|->
name|updateDynamicTexture
argument_list|(
name|dynamicTexture
argument_list|)
expr_stmt|;
name|makeCurrent
argument_list|()
expr_stmt|;
comment|// draw into the GL widget
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
name|glFrustum
argument_list|(
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
operator|-
literal|1
argument_list|,
literal|1
argument_list|,
literal|10
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|glTranslatef
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
literal|15.0f
argument_list|)
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
name|glLoadIdentity
argument_list|()
expr_stmt|;
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
operator|*
name|devicePixelRatio
argument_list|()
argument_list|,
name|height
argument_list|()
operator|*
name|devicePixelRatio
argument_list|()
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|dynamicTexture
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_MULTISAMPLE
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glBlendFunc
argument_list|(
name|GL_SRC_ALPHA
argument_list|,
name|GL_ONE_MINUS_SRC_ALPHA
argument_list|)
expr_stmt|;
comment|// draw background
name|glPushMatrix
argument_list|()
expr_stmt|;
name|glScalef
argument_list|(
literal|1.7f
argument_list|,
literal|1.7f
argument_list|,
literal|1.7f
argument_list|)
expr_stmt|;
name|glColor4f
argument_list|(
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glCallList
argument_list|(
name|tile_list
argument_list|)
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
specifier|const
name|int
name|w
init|=
name|logo
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|h
init|=
name|logo
operator|.
name|height
argument_list|()
decl_stmt|;
name|glRotatef
argument_list|(
name|rot_x
argument_list|,
literal|1.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glRotatef
argument_list|(
name|rot_y
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|glRotatef
argument_list|(
name|rot_z
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glScalef
argument_list|(
name|scale
operator|/
name|w
argument_list|,
name|scale
operator|/
name|w
argument_list|,
name|scale
operator|/
name|w
argument_list|)
expr_stmt|;
name|glDepthFunc
argument_list|(
name|GL_LESS
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
comment|// draw the Qt icon
name|glTranslatef
argument_list|(
operator|-
name|w
operator|+
literal|1
argument_list|,
operator|-
name|h
operator|+
literal|1
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
name|h
operator|-
literal|1
init|;
name|y
operator|>=
literal|0
condition|;
operator|--
name|y
control|)
block|{
name|uint
modifier|*
name|p
init|=
operator|(
name|uint
operator|*
operator|)
name|logo
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
name|uint
modifier|*
name|end
init|=
name|p
operator|+
name|w
decl_stmt|;
name|int
name|x
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|p
operator|<
name|end
condition|)
block|{
name|glColor4ub
argument_list|(
name|qRed
argument_list|(
operator|*
name|p
argument_list|)
argument_list|,
name|qGreen
argument_list|(
operator|*
name|p
argument_list|)
argument_list|,
name|qBlue
argument_list|(
operator|*
name|p
argument_list|)
argument_list|,
name|uchar
argument_list|(
name|qAlpha
argument_list|(
operator|*
name|p
argument_list|)
operator|*
literal|.9
argument_list|)
argument_list|)
expr_stmt|;
name|glTranslatef
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
name|wave
index|[
name|y
operator|*
name|w
operator|+
name|x
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|qAlpha
argument_list|(
operator|*
name|p
argument_list|)
operator|>
literal|128
condition|)
name|glCallList
argument_list|(
name|tile_list
argument_list|)
expr_stmt|;
name|glTranslatef
argument_list|(
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
name|wave
index|[
name|y
operator|*
name|w
operator|+
name|x
index|]
argument_list|)
expr_stmt|;
name|glTranslatef
argument_list|(
literal|2.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
operator|++
name|x
expr_stmt|;
operator|++
name|p
expr_stmt|;
block|}
name|glTranslatef
argument_list|(
operator|-
name|w
operator|*
literal|2.0f
argument_list|,
literal|2.0f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
block|}
comment|// restore the GL state that QPainter expects
name|restoreGLState
argument_list|()
expr_stmt|;
name|p
operator|.
name|endNativePainting
argument_list|()
expr_stmt|;
comment|// draw the overlayed text using QPainter
name|p
operator|.
name|setPen
argument_list|(
name|QColor
argument_list|(
literal|197
argument_list|,
literal|197
argument_list|,
literal|197
argument_list|,
literal|157
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|197
argument_list|,
literal|197
argument_list|,
literal|197
argument_list|,
literal|127
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawRect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|()
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|.
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|p
operator|.
name|setBrush
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
expr_stmt|;
specifier|const
name|QString
name|str1
argument_list|(
name|tr
argument_list|(
literal|"A simple OpenGL pbuffer example."
argument_list|)
argument_list|)
decl_stmt|;
specifier|const
name|QString
name|str2
argument_list|(
name|tr
argument_list|(
literal|"Use the mouse wheel to zoom, press buttons and move mouse to rotate, double-click to flip."
argument_list|)
argument_list|)
decl_stmt|;
name|QFontMetrics
name|fm
argument_list|(
name|p
operator|.
name|font
argument_list|()
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|width
argument_list|()
operator|/
literal|2
operator|-
name|fm
operator|.
name|width
argument_list|(
name|str1
argument_list|)
operator|/
literal|2
argument_list|,
literal|20
argument_list|,
name|str1
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawText
argument_list|(
name|width
argument_list|()
operator|/
literal|2
operator|-
name|fm
operator|.
name|width
argument_list|(
name|str2
argument_list|)
operator|/
literal|2
argument_list|,
literal|20
operator|+
name|fm
operator|.
name|lineSpacing
argument_list|()
argument_list|,
name|str2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mousePressEvent
name|void
name|GLWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|anchor
operator|=
name|e
operator|->
name|pos
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseMoveEvent
name|void
name|GLWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|e
parameter_list|)
block|{
name|QPoint
name|diff
init|=
name|e
operator|->
name|pos
argument_list|()
operator|-
name|anchor
decl_stmt|;
if|if
condition|(
name|e
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|rot_x
operator|+=
name|diff
operator|.
name|y
argument_list|()
operator|/
literal|5.0f
expr_stmt|;
name|rot_y
operator|+=
name|diff
operator|.
name|x
argument_list|()
operator|/
literal|5.0f
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|e
operator|->
name|buttons
argument_list|()
operator|&
name|Qt
operator|::
name|RightButton
condition|)
block|{
name|rot_z
operator|+=
name|diff
operator|.
name|x
argument_list|()
operator|/
literal|5.0f
expr_stmt|;
block|}
name|anchor
operator|=
name|e
operator|->
name|pos
argument_list|()
expr_stmt|;
name|draw
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|wheelEvent
name|void
name|GLWidget
operator|::
name|wheelEvent
parameter_list|(
name|QWheelEvent
modifier|*
name|e
parameter_list|)
block|{
name|e
operator|->
name|delta
argument_list|()
operator|>
literal|0
condition|?
name|scale
operator|+=
name|scale
operator|*
literal|0.1f
else|:
name|scale
operator|-=
name|scale
operator|*
literal|0.1f
expr_stmt|;
name|draw
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|GLWidget
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
parameter_list|)
block|{
name|anim
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|animate
name|void
name|GLWidget
operator|::
name|animate
parameter_list|(
name|qreal
name|val
parameter_list|)
block|{
name|rot_y
operator|=
name|val
operator|*
literal|180
expr_stmt|;
name|draw
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|animFinished
name|void
name|GLWidget
operator|::
name|animFinished
parameter_list|()
block|{
if|if
condition|(
name|anim
operator|->
name|direction
argument_list|()
operator|==
name|QTimeLine
operator|::
name|Forward
condition|)
name|anim
operator|->
name|setDirection
argument_list|(
name|QTimeLine
operator|::
name|Backward
argument_list|)
expr_stmt|;
else|else
name|anim
operator|->
name|setDirection
argument_list|(
name|QTimeLine
operator|::
name|Forward
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|saveGLState
name|void
name|GLWidget
operator|::
name|saveGLState
parameter_list|()
block|{
name|glPushAttrib
argument_list|(
name|GL_ALL_ATTRIB_BITS
argument_list|)
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glPushMatrix
argument_list|()
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
name|glPushMatrix
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|restoreGLState
name|void
name|GLWidget
operator|::
name|restoreGLState
parameter_list|()
block|{
name|glMatrixMode
argument_list|(
name|GL_PROJECTION
argument_list|)
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
name|glMatrixMode
argument_list|(
name|GL_MODELVIEW
argument_list|)
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
name|glPopAttrib
argument_list|()
expr_stmt|;
block|}
end_function
begin_define
DECL|macro|PI
define|#
directive|define
name|PI
value|3.14159
end_define
begin_function
DECL|function|timerEvent
name|void
name|GLWidget
operator|::
name|timerEvent
parameter_list|(
name|QTimerEvent
modifier|*
parameter_list|)
block|{
if|if
condition|(
name|QApplication
operator|::
name|mouseButtons
argument_list|()
operator|!=
literal|0
condition|)
return|return;
specifier|static
name|bool
name|scale_in
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|scale_in
operator|&&
name|scale
operator|>
literal|35.0f
condition|)
name|scale_in
operator|=
literal|false
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|scale_in
operator|&&
name|scale
operator|<
literal|.5f
condition|)
name|scale_in
operator|=
literal|true
expr_stmt|;
name|scale
operator|=
name|scale_in
condition|?
name|scale
operator|+
name|scale
operator|*
literal|0.01f
else|:
name|scale
operator|-
name|scale
operator|*
literal|0.01f
expr_stmt|;
name|rot_z
operator|+=
literal|0.3f
expr_stmt|;
name|rot_x
operator|+=
literal|0.1f
expr_stmt|;
name|int
name|dx
decl_stmt|,
name|dy
decl_stmt|;
comment|// disturbance point
name|float
name|s
decl_stmt|,
name|v
decl_stmt|,
name|W
decl_stmt|,
name|t
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
specifier|static
name|float
name|wt
index|[
literal|128
index|]
index|[
literal|128
index|]
decl_stmt|;
specifier|const
name|int
name|width
init|=
name|logo
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|AMP
init|=
literal|5
decl_stmt|;
name|dx
operator|=
name|dy
operator|=
name|width
operator|>>
literal|1
expr_stmt|;
name|W
operator|=
literal|.3f
expr_stmt|;
name|v
operator|=
operator|-
literal|4
expr_stmt|;
comment|// wave speed
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|width
condition|;
operator|++
name|i
control|)
block|{
for|for
control|(
name|j
operator|=
literal|0
init|;
name|j
operator|<
name|width
condition|;
operator|++
name|j
control|)
block|{
name|s
operator|=
name|sqrt
argument_list|(
call|(
name|double
call|)
argument_list|(
operator|(
name|j
operator|-
name|dx
operator|)
operator|*
operator|(
name|j
operator|-
name|dx
operator|)
operator|+
operator|(
name|i
operator|-
name|dy
operator|)
operator|*
operator|(
name|i
operator|-
name|dy
operator|)
argument_list|)
argument_list|)
expr_stmt|;
name|wt
index|[
name|i
index|]
index|[
name|j
index|]
operator|+=
literal|0.1f
expr_stmt|;
name|t
operator|=
name|s
operator|/
name|v
expr_stmt|;
if|if
condition|(
name|s
operator|!=
literal|0
condition|)
name|wave
index|[
name|i
operator|*
name|width
operator|+
name|j
index|]
operator|=
name|AMP
operator|*
name|sin
argument_list|(
literal|2
operator|*
name|PI
operator|*
name|W
operator|*
operator|(
name|wt
index|[
name|i
index|]
index|[
name|j
index|]
operator|+
name|t
operator|)
argument_list|)
operator|/
operator|(
literal|0.2
operator|*
operator|(
name|s
operator|+
literal|2
operator|)
operator|)
expr_stmt|;
else|else
name|wave
index|[
name|i
operator|*
name|width
operator|+
name|j
index|]
operator|=
name|AMP
operator|*
name|sin
argument_list|(
literal|2
operator|*
name|PI
operator|*
name|W
operator|*
operator|(
name|wt
index|[
name|i
index|]
index|[
name|j
index|]
operator|+
name|t
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
