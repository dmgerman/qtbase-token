begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"glwindow.h"
end_include
begin_include
include|#
directive|include
file|<QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QScreen>
end_include
begin_include
include|#
directive|include
file|<QTimer>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_function
DECL|function|CrossProduct
specifier|inline
name|void
name|CrossProduct
parameter_list|(
name|qreal
modifier|&
name|xOut
parameter_list|,
name|qreal
modifier|&
name|yOut
parameter_list|,
name|qreal
modifier|&
name|zOut
parameter_list|,
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|z1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|,
name|qreal
name|z2
parameter_list|)
block|{
name|xOut
operator|=
name|y1
operator|*
name|z2
operator|-
name|z1
operator|*
name|y2
expr_stmt|;
name|yOut
operator|=
name|z1
operator|*
name|x2
operator|-
name|x1
operator|*
name|z2
expr_stmt|;
name|zOut
operator|=
name|x1
operator|*
name|y2
operator|-
name|y1
operator|*
name|x2
expr_stmt|;
block|}
end_function
begin_function
DECL|function|Normalize
specifier|inline
name|void
name|Normalize
parameter_list|(
name|qreal
modifier|&
name|x
parameter_list|,
name|qreal
modifier|&
name|y
parameter_list|,
name|qreal
modifier|&
name|z
parameter_list|)
block|{
name|qreal
name|l
init|=
name|sqrt
argument_list|(
name|x
operator|*
name|x
operator|+
name|y
operator|*
name|y
operator|+
name|z
operator|*
name|z
argument_list|)
decl_stmt|;
name|x
operator|=
name|x
operator|/
name|l
expr_stmt|;
name|y
operator|=
name|y
operator|/
name|l
expr_stmt|;
name|z
operator|=
name|z
operator|/
name|l
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|GLWindow
name|GLWindow
operator|::
name|GLWindow
parameter_list|()
block|{
name|qtLogo
operator|=
literal|true
expr_stmt|;
name|createdVertices
operator|=
literal|0
expr_stmt|;
name|createdNormals
operator|=
literal|0
expr_stmt|;
name|m_vertexNumber
operator|=
literal|0
expr_stmt|;
name|frames
operator|=
literal|0
expr_stmt|;
name|m_fScale
operator|=
literal|1
expr_stmt|;
name|QSurfaceFormat
name|format
decl_stmt|;
name|format
operator|.
name|setDepthBufferSize
argument_list|(
literal|24
argument_list|)
expr_stmt|;
name|format
operator|.
name|setMajorVersion
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|format
operator|.
name|setMinorVersion
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|setGeometry
argument_list|(
name|QGuiApplication
operator|::
name|primaryScreen
argument_list|()
operator|->
name|availableGeometry
argument_list|()
argument_list|)
expr_stmt|;
name|setFormat
argument_list|(
name|format
argument_list|)
expr_stmt|;
name|create
argument_list|()
expr_stmt|;
name|m_context
operator|=
operator|new
name|QOpenGLContext
expr_stmt|;
name|m_context
operator|->
name|setFormat
argument_list|(
name|format
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
name|initializeGL
argument_list|()
expr_stmt|;
name|QTimer
modifier|*
name|timer
init|=
operator|new
name|QTimer
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|timer
operator|->
name|setInterval
argument_list|(
literal|16
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|timer
argument_list|,
name|SIGNAL
argument_list|(
name|timeout
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|paintGL
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|timer
operator|->
name|start
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~GLWindow
name|GLWindow
operator|::
name|~
name|GLWindow
parameter_list|()
block|{
if|if
condition|(
name|createdVertices
condition|)
operator|delete
index|[]
name|createdVertices
expr_stmt|;
if|if
condition|(
name|createdNormals
condition|)
operator|delete
index|[]
name|createdNormals
expr_stmt|;
operator|delete
name|m_context
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|paintQtLogo
name|void
name|GLWindow
operator|::
name|paintQtLogo
parameter_list|()
block|{
name|glDisable
argument_list|(
name|GL_TEXTURE_2D
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_VERTEX_ARRAY
argument_list|)
expr_stmt|;
name|glVertexPointer
argument_list|(
literal|3
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
name|createdVertices
argument_list|)
expr_stmt|;
name|glEnableClientState
argument_list|(
name|GL_NORMAL_ARRAY
argument_list|)
expr_stmt|;
name|glNormalPointer
argument_list|(
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
name|createdNormals
argument_list|)
expr_stmt|;
name|glDrawArrays
argument_list|(
name|GL_TRIANGLES
argument_list|,
literal|0
argument_list|,
name|m_vertexNumber
operator|/
literal|3
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initializeGL
name|void
name|GLWindow
operator|::
name|initializeGL
parameter_list|()
block|{
name|glClearColor
argument_list|(
literal|0.1f
argument_list|,
literal|0.1f
argument_list|,
literal|0.2f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHTING
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHT0
argument_list|)
expr_stmt|;
name|GLfloat
name|aLightPosition
index|[]
init|=
block|{
literal|0.0f
block|,
literal|0.3f
block|,
literal|1.0f
block|,
literal|0.0f
block|}
decl_stmt|;
name|glLightfv
argument_list|(
name|GL_LIGHT0
argument_list|,
name|GL_SPOT_DIRECTION
argument_list|,
name|aLightPosition
argument_list|)
expr_stmt|;
name|m_fAngle
operator|=
literal|0
expr_stmt|;
name|m_fScale
operator|=
literal|1
expr_stmt|;
name|createGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintGL
name|void
name|GLWindow
operator|::
name|paintGL
parameter_list|()
block|{
name|m_context
operator|->
name|makeCurrent
argument_list|(
name|this
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
name|glLoadIdentity
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
name|glMatrixMode
argument_list|(
name|GL_TEXTURE
argument_list|)
expr_stmt|;
name|glPushMatrix
argument_list|()
expr_stmt|;
comment|//Since OpenGL ES does not support glPush/PopAttrib(GL_ALL_ATTRIB_BITS)
comment|//we have to take care of the states ourselves
name|glClearColor
argument_list|(
literal|0.1f
argument_list|,
literal|0.1f
argument_list|,
literal|0.2f
argument_list|,
literal|1.0f
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
operator||
name|GL_DEPTH_BUFFER_BIT
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_TEXTURE_2D
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
name|glTexParameterf
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_LINEAR
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHTING
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_LIGHT0
argument_list|)
expr_stmt|;
name|glShadeModel
argument_list|(
name|GL_FLAT
argument_list|)
expr_stmt|;
name|glFrontFace
argument_list|(
name|GL_CW
argument_list|)
expr_stmt|;
name|glCullFace
argument_list|(
name|GL_FRONT
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_DEPTH_TEST
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
name|glRotatef
argument_list|(
name|m_fAngle
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
name|m_fAngle
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
name|m_fAngle
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
name|m_fScale
argument_list|,
name|m_fScale
argument_list|,
name|m_fScale
argument_list|)
expr_stmt|;
name|glTranslatef
argument_list|(
literal|0.0f
argument_list|,
operator|-
literal|0.2f
argument_list|,
literal|0.0f
argument_list|)
expr_stmt|;
name|GLfloat
name|matDiff
index|[]
init|=
block|{
literal|0.40f
block|,
literal|1.0f
block|,
literal|0.0f
block|,
literal|1.0f
block|}
decl_stmt|;
name|glMaterialfv
argument_list|(
name|GL_FRONT_AND_BACK
argument_list|,
name|GL_DIFFUSE
argument_list|,
name|matDiff
argument_list|)
expr_stmt|;
name|paintQtLogo
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
name|GL_TEXTURE
argument_list|)
expr_stmt|;
name|glPopMatrix
argument_list|()
expr_stmt|;
name|glDisable
argument_list|(
name|GL_LIGHTING
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_LIGHT0
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_CULL_FACE
argument_list|)
expr_stmt|;
name|m_context
operator|->
name|swapBuffers
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_fAngle
operator|+=
literal|1.0f
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createGeometry
name|void
name|GLWindow
operator|::
name|createGeometry
parameter_list|()
block|{
name|vertices
operator|.
name|clear
argument_list|()
expr_stmt|;
name|normals
operator|.
name|clear
argument_list|()
expr_stmt|;
name|qreal
name|x1
init|=
operator|+
literal|0.06f
decl_stmt|;
name|qreal
name|y1
init|=
operator|-
literal|0.14f
decl_stmt|;
name|qreal
name|x2
init|=
operator|+
literal|0.14f
decl_stmt|;
name|qreal
name|y2
init|=
operator|-
literal|0.06f
decl_stmt|;
name|qreal
name|x3
init|=
operator|+
literal|0.08f
decl_stmt|;
name|qreal
name|y3
init|=
operator|+
literal|0.00f
decl_stmt|;
name|qreal
name|x4
init|=
operator|+
literal|0.30f
decl_stmt|;
name|qreal
name|y4
init|=
operator|+
literal|0.22f
decl_stmt|;
name|quad
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|,
name|y2
argument_list|,
name|x2
argument_list|,
name|y1
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|quad
argument_list|(
name|x3
argument_list|,
name|y3
argument_list|,
name|x4
argument_list|,
name|y4
argument_list|,
name|y4
argument_list|,
name|x4
argument_list|,
name|y3
argument_list|,
name|x3
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|,
name|y2
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|y2
argument_list|,
name|x2
argument_list|,
name|y1
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|y1
argument_list|,
name|x1
argument_list|,
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x3
argument_list|,
name|y3
argument_list|,
name|x4
argument_list|,
name|y4
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x4
argument_list|,
name|y4
argument_list|,
name|y4
argument_list|,
name|x4
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|y4
argument_list|,
name|x4
argument_list|,
name|y3
argument_list|,
name|x3
argument_list|)
expr_stmt|;
specifier|const
name|qreal
name|Pi
init|=
literal|3.14159f
decl_stmt|;
specifier|const
name|int
name|NumSectors
init|=
literal|100
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumSectors
condition|;
operator|++
name|i
control|)
block|{
name|qreal
name|angle1
init|=
operator|(
name|i
operator|*
literal|2
operator|*
name|Pi
operator|)
operator|/
name|NumSectors
decl_stmt|;
name|qreal
name|x5
init|=
literal|0.30
operator|*
name|sin
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|y5
init|=
literal|0.30
operator|*
name|cos
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|x6
init|=
literal|0.20
operator|*
name|sin
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|y6
init|=
literal|0.20
operator|*
name|cos
argument_list|(
name|angle1
argument_list|)
decl_stmt|;
name|qreal
name|angle2
init|=
operator|(
operator|(
name|i
operator|+
literal|1
operator|)
operator|*
literal|2
operator|*
name|Pi
operator|)
operator|/
name|NumSectors
decl_stmt|;
name|qreal
name|x7
init|=
literal|0.20
operator|*
name|sin
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|qreal
name|y7
init|=
literal|0.20
operator|*
name|cos
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|qreal
name|x8
init|=
literal|0.30
operator|*
name|sin
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|qreal
name|y8
init|=
literal|0.30
operator|*
name|cos
argument_list|(
name|angle2
argument_list|)
decl_stmt|;
name|quad
argument_list|(
name|x5
argument_list|,
name|y5
argument_list|,
name|x6
argument_list|,
name|y6
argument_list|,
name|x7
argument_list|,
name|y7
argument_list|,
name|x8
argument_list|,
name|y8
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x6
argument_list|,
name|y6
argument_list|,
name|x7
argument_list|,
name|y7
argument_list|)
expr_stmt|;
name|extrude
argument_list|(
name|x8
argument_list|,
name|y8
argument_list|,
name|x5
argument_list|,
name|y5
argument_list|)
expr_stmt|;
block|}
name|m_vertexNumber
operator|=
name|vertices
operator|.
name|size
argument_list|()
expr_stmt|;
name|createdVertices
operator|=
operator|new
name|GLfloat
index|[
name|m_vertexNumber
index|]
expr_stmt|;
name|createdNormals
operator|=
operator|new
name|GLfloat
index|[
name|m_vertexNumber
index|]
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
name|m_vertexNumber
condition|;
name|i
operator|++
control|)
block|{
name|createdVertices
index|[
name|i
index|]
operator|=
name|vertices
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|*
literal|2
expr_stmt|;
name|createdNormals
index|[
name|i
index|]
operator|=
name|normals
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|vertices
operator|.
name|clear
argument_list|()
expr_stmt|;
name|normals
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|quad
name|void
name|GLWindow
operator|::
name|quad
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|,
name|qreal
name|x3
parameter_list|,
name|qreal
name|y3
parameter_list|,
name|qreal
name|x4
parameter_list|,
name|qreal
name|y4
parameter_list|)
block|{
name|qreal
name|nx
decl_stmt|,
name|ny
decl_stmt|,
name|nz
decl_stmt|;
name|vertices
operator|<<
name|x1
operator|<<
name|y1
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x4
operator|<<
name|y4
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x3
operator|<<
name|y3
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x4
operator|<<
name|y4
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|CrossProduct
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|,
name|nz
argument_list|,
name|x2
operator|-
name|x1
argument_list|,
name|y2
operator|-
name|y1
argument_list|,
literal|0
argument_list|,
name|x4
operator|-
name|x1
argument_list|,
name|y4
operator|-
name|y1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|Normalize
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|,
name|nz
argument_list|)
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|vertices
operator|<<
name|x4
operator|<<
name|y4
operator|<<
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x1
operator|<<
name|y1
operator|<<
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x4
operator|<<
name|y4
operator|<<
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x3
operator|<<
name|y3
operator|<<
literal|0.05f
expr_stmt|;
name|CrossProduct
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|,
name|nz
argument_list|,
name|x2
operator|-
name|x4
argument_list|,
name|y2
operator|-
name|y4
argument_list|,
literal|0
argument_list|,
name|x1
operator|-
name|x4
argument_list|,
name|y1
operator|-
name|y4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|Normalize
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|,
name|nz
argument_list|)
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
block|}
end_function
begin_function
DECL|function|extrude
name|void
name|GLWindow
operator|::
name|extrude
parameter_list|(
name|qreal
name|x1
parameter_list|,
name|qreal
name|y1
parameter_list|,
name|qreal
name|x2
parameter_list|,
name|qreal
name|y2
parameter_list|)
block|{
name|qreal
name|nx
decl_stmt|,
name|ny
decl_stmt|,
name|nz
decl_stmt|;
name|vertices
operator|<<
name|x1
operator|<<
name|y1
operator|<<
operator|+
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
operator|+
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x1
operator|<<
name|y1
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x1
operator|<<
name|y1
operator|<<
operator|-
literal|0.05f
expr_stmt|;
name|vertices
operator|<<
name|x2
operator|<<
name|y2
operator|<<
operator|+
literal|0.05f
expr_stmt|;
name|CrossProduct
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|,
name|nz
argument_list|,
name|x2
operator|-
name|x1
argument_list|,
name|y2
operator|-
name|y1
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
literal|0.0f
argument_list|,
operator|-
literal|0.1f
argument_list|)
expr_stmt|;
name|Normalize
argument_list|(
name|nx
argument_list|,
name|ny
argument_list|,
name|nz
argument_list|)
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
name|normals
operator|<<
name|nx
operator|<<
name|ny
operator|<<
name|nz
expr_stmt|;
block|}
end_function
end_unit
