begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qeglfscursor.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowsysteminterface_qpa.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonDocument>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonArray>
end_include
begin_include
include|#
directive|include
file|<QtCore/QJsonObject>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QEglFSCursor
name|QEglFSCursor
operator|::
name|QEglFSCursor
parameter_list|(
name|QEglFSScreen
modifier|*
name|screen
parameter_list|)
member_init_list|:
name|m_screen
argument_list|(
name|screen
argument_list|)
member_init_list|,
name|m_pos
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
member_init_list|,
name|m_program
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_vertexCoordEntry
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_textureCoordEntry
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_textureEntry
argument_list|(
literal|0
argument_list|)
block|{
name|initCursorAtlas
argument_list|()
expr_stmt|;
comment|// initialize the cursor
name|QCursor
name|cursor
argument_list|(
name|Qt
operator|::
name|ArrowCursor
argument_list|)
decl_stmt|;
name|setCurrentCursor
argument_list|(
operator|&
name|cursor
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QEglFSCursor
name|QEglFSCursor
operator|::
name|~
name|QEglFSCursor
parameter_list|()
block|{
if|if
condition|(
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
condition|)
block|{
name|glDeleteProgram
argument_list|(
name|m_program
argument_list|)
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_cursor
operator|.
name|customCursorTexture
argument_list|)
expr_stmt|;
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_cursorAtlas
operator|.
name|texture
argument_list|)
expr_stmt|;
block|}
block|}
end_destructor
begin_function
DECL|function|createShader
specifier|static
name|GLuint
name|createShader
parameter_list|(
name|GLenum
name|shaderType
parameter_list|,
specifier|const
name|char
modifier|*
name|program
parameter_list|)
block|{
name|GLuint
name|shader
init|=
name|glCreateShader
argument_list|(
name|shaderType
argument_list|)
decl_stmt|;
name|glShaderSource
argument_list|(
name|shader
argument_list|,
literal|1
comment|/* count */
argument_list|,
operator|&
name|program
argument_list|,
name|NULL
comment|/* lengths */
argument_list|)
expr_stmt|;
name|glCompileShader
argument_list|(
name|shader
argument_list|)
expr_stmt|;
name|GLint
name|status
decl_stmt|;
name|glGetShaderiv
argument_list|(
name|shader
argument_list|,
name|GL_COMPILE_STATUS
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|GL_TRUE
condition|)
return|return
name|shader
return|;
name|GLint
name|length
decl_stmt|;
name|glGetShaderiv
argument_list|(
name|shader
argument_list|,
name|GL_INFO_LOG_LENGTH
argument_list|,
operator|&
name|length
argument_list|)
expr_stmt|;
name|char
modifier|*
name|infoLog
init|=
operator|new
name|char
index|[
name|length
index|]
decl_stmt|;
name|glGetShaderInfoLog
argument_list|(
name|shader
argument_list|,
name|length
argument_list|,
name|NULL
argument_list|,
name|infoLog
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%s shader compilation error: %s"
argument_list|,
name|shaderType
operator|==
name|GL_VERTEX_SHADER
condition|?
literal|"vertex"
else|:
literal|"fragment"
argument_list|,
name|infoLog
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|infoLog
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createProgram
specifier|static
name|GLuint
name|createProgram
parameter_list|(
name|GLuint
name|vshader
parameter_list|,
name|GLuint
name|fshader
parameter_list|)
block|{
name|GLuint
name|program
init|=
name|glCreateProgram
argument_list|()
decl_stmt|;
name|glAttachShader
argument_list|(
name|program
argument_list|,
name|vshader
argument_list|)
expr_stmt|;
name|glAttachShader
argument_list|(
name|program
argument_list|,
name|fshader
argument_list|)
expr_stmt|;
name|glLinkProgram
argument_list|(
name|program
argument_list|)
expr_stmt|;
name|GLint
name|status
decl_stmt|;
name|glGetProgramiv
argument_list|(
name|program
argument_list|,
name|GL_LINK_STATUS
argument_list|,
operator|&
name|status
argument_list|)
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|GL_TRUE
condition|)
return|return
name|program
return|;
name|GLint
name|length
decl_stmt|;
name|glGetProgramiv
argument_list|(
name|program
argument_list|,
name|GL_INFO_LOG_LENGTH
argument_list|,
operator|&
name|length
argument_list|)
expr_stmt|;
name|char
modifier|*
name|infoLog
init|=
operator|new
name|char
index|[
name|length
index|]
decl_stmt|;
name|glGetProgramInfoLog
argument_list|(
name|program
argument_list|,
name|length
argument_list|,
name|NULL
argument_list|,
name|infoLog
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"program link error: %s"
argument_list|,
name|infoLog
argument_list|)
expr_stmt|;
operator|delete
index|[]
name|infoLog
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|createShaderPrograms
name|void
name|QEglFSCursor
operator|::
name|createShaderPrograms
parameter_list|()
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
literal|"   gl_Position = vec4(vertexCoordEntry, 1.0, 1.0);\n"
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
name|GLuint
name|vertexShader
init|=
name|createShader
argument_list|(
name|GL_VERTEX_SHADER
argument_list|,
name|textureVertexProgram
argument_list|)
decl_stmt|;
name|GLuint
name|fragmentShader
init|=
name|createShader
argument_list|(
name|GL_FRAGMENT_SHADER
argument_list|,
name|textureFragmentProgram
argument_list|)
decl_stmt|;
name|m_program
operator|=
name|createProgram
argument_list|(
name|vertexShader
argument_list|,
name|fragmentShader
argument_list|)
expr_stmt|;
name|glDeleteShader
argument_list|(
name|vertexShader
argument_list|)
expr_stmt|;
name|glDeleteShader
argument_list|(
name|fragmentShader
argument_list|)
expr_stmt|;
name|m_vertexCoordEntry
operator|=
name|glGetAttribLocation
argument_list|(
name|m_program
argument_list|,
literal|"vertexCoordEntry"
argument_list|)
expr_stmt|;
name|m_textureCoordEntry
operator|=
name|glGetAttribLocation
argument_list|(
name|m_program
argument_list|,
literal|"textureCoordEntry"
argument_list|)
expr_stmt|;
name|m_textureEntry
operator|=
name|glGetUniformLocation
argument_list|(
name|m_program
argument_list|,
literal|"texture"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|createCursorTexture
name|void
name|QEglFSCursor
operator|::
name|createCursorTexture
parameter_list|(
name|uint
modifier|*
name|texture
parameter_list|,
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
if|if
condition|(
operator|!
operator|*
name|texture
condition|)
name|glGenTextures
argument_list|(
literal|1
argument_list|,
name|texture
argument_list|)
expr_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
operator|*
name|texture
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
comment|/* level */
argument_list|,
name|GL_RGBA
argument_list|,
name|image
operator|.
name|width
argument_list|()
argument_list|,
name|image
operator|.
name|height
argument_list|()
argument_list|,
literal|0
comment|/* border */
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|initCursorAtlas
name|void
name|QEglFSCursor
operator|::
name|initCursorAtlas
parameter_list|()
block|{
specifier|static
name|QByteArray
name|json
init|=
name|qgetenv
argument_list|(
literal|"QT_QPA_EGLFS_CURSOR"
argument_list|)
decl_stmt|;
if|if
condition|(
name|json
operator|.
name|isEmpty
argument_list|()
condition|)
name|json
operator|=
literal|":/cursor.json"
expr_stmt|;
name|QFile
name|file
argument_list|(
name|json
argument_list|)
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QJsonDocument
name|doc
init|=
name|QJsonDocument
operator|::
name|fromJson
argument_list|(
name|file
operator|.
name|readAll
argument_list|()
argument_list|)
decl_stmt|;
name|QJsonObject
name|object
init|=
name|doc
operator|.
name|object
argument_list|()
decl_stmt|;
name|QString
name|atlas
init|=
name|object
operator|.
name|value
argument_list|(
literal|"image"
argument_list|)
operator|.
name|toString
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|atlas
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|cursorsPerRow
init|=
name|object
operator|.
name|value
argument_list|(
literal|"cursorsPerRow"
argument_list|)
operator|.
name|toDouble
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|cursorsPerRow
argument_list|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|=
name|cursorsPerRow
expr_stmt|;
specifier|const
name|QJsonArray
name|hotSpots
init|=
name|object
operator|.
name|value
argument_list|(
literal|"hotSpots"
argument_list|)
operator|.
name|toArray
argument_list|()
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|hotSpots
operator|.
name|count
argument_list|()
operator|==
name|Qt
operator|::
name|LastCursor
argument_list|)
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
name|hotSpots
operator|.
name|count
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QPoint
name|hotSpot
argument_list|(
name|hotSpots
index|[
name|i
index|]
operator|.
name|toArray
argument_list|()
index|[
literal|0
index|]
operator|.
name|toDouble
argument_list|()
argument_list|,
name|hotSpots
index|[
name|i
index|]
operator|.
name|toArray
argument_list|()
index|[
literal|1
index|]
operator|.
name|toDouble
argument_list|()
argument_list|)
decl_stmt|;
name|m_cursorAtlas
operator|.
name|hotSpots
operator|<<
name|hotSpot
expr_stmt|;
block|}
name|QImage
name|image
init|=
name|QImage
argument_list|(
name|atlas
argument_list|)
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_ARGB32_Premultiplied
argument_list|)
decl_stmt|;
name|m_cursorAtlas
operator|.
name|cursorWidth
operator|=
name|image
operator|.
name|width
argument_list|()
operator|/
name|m_cursorAtlas
operator|.
name|cursorsPerRow
expr_stmt|;
name|m_cursorAtlas
operator|.
name|cursorHeight
operator|=
name|image
operator|.
name|height
argument_list|()
operator|/
operator|(
operator|(
name|Qt
operator|::
name|LastCursor
operator|+
name|cursorsPerRow
operator|-
literal|1
operator|)
operator|/
name|cursorsPerRow
operator|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|width
operator|=
name|image
operator|.
name|width
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|height
operator|=
name|image
operator|.
name|height
argument_list|()
expr_stmt|;
name|m_cursorAtlas
operator|.
name|image
operator|=
name|image
expr_stmt|;
block|}
end_function
begin_function
DECL|function|changeCursor
name|void
name|QEglFSCursor
operator|::
name|changeCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|,
name|QWindow
modifier|*
name|window
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|window
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|oldCursorRect
init|=
name|cursorRect
argument_list|()
decl_stmt|;
if|if
condition|(
name|setCurrentCursor
argument_list|(
name|cursor
argument_list|)
condition|)
name|update
argument_list|(
name|oldCursorRect
operator||
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|setCurrentCursor
name|bool
name|QEglFSCursor
operator|::
name|setCurrentCursor
parameter_list|(
name|QCursor
modifier|*
name|cursor
parameter_list|)
block|{
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|==
name|cursor
operator|->
name|shape
argument_list|()
operator|&&
name|cursor
operator|->
name|shape
argument_list|()
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|==
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
name|m_cursor
operator|.
name|customCursorImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
comment|// in case render() never uploaded it
block|}
name|m_cursor
operator|.
name|shape
operator|=
name|cursor
operator|->
name|shape
argument_list|()
expr_stmt|;
if|if
condition|(
name|cursor
operator|->
name|shape
argument_list|()
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
block|{
comment|// standard cursor
specifier|const
name|float
name|ws
init|=
operator|(
name|float
operator|)
name|m_cursorAtlas
operator|.
name|cursorWidth
operator|/
name|m_cursorAtlas
operator|.
name|width
decl_stmt|,
name|hs
init|=
operator|(
name|float
operator|)
name|m_cursorAtlas
operator|.
name|cursorHeight
operator|/
name|m_cursorAtlas
operator|.
name|height
decl_stmt|;
name|m_cursor
operator|.
name|textureRect
operator|=
name|QRectF
argument_list|(
name|ws
operator|*
operator|(
name|m_cursor
operator|.
name|shape
operator|%
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|)
argument_list|,
name|hs
operator|*
operator|(
name|m_cursor
operator|.
name|shape
operator|/
name|m_cursorAtlas
operator|.
name|cursorsPerRow
operator|)
argument_list|,
name|ws
argument_list|,
name|hs
argument_list|)
expr_stmt|;
name|m_cursor
operator|.
name|hotSpot
operator|=
name|m_cursorAtlas
operator|.
name|hotSpots
index|[
name|m_cursor
operator|.
name|shape
index|]
expr_stmt|;
name|m_cursor
operator|.
name|texture
operator|=
name|m_cursorAtlas
operator|.
name|texture
expr_stmt|;
name|m_cursor
operator|.
name|size
operator|=
name|QSize
argument_list|(
name|m_cursorAtlas
operator|.
name|cursorWidth
argument_list|,
name|m_cursorAtlas
operator|.
name|cursorHeight
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QImage
name|image
init|=
name|cursor
operator|->
name|pixmap
argument_list|()
operator|.
name|toImage
argument_list|()
decl_stmt|;
name|m_cursor
operator|.
name|textureRect
operator|=
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_cursor
operator|.
name|hotSpot
operator|=
name|cursor
operator|->
name|hotSpot
argument_list|()
expr_stmt|;
name|m_cursor
operator|.
name|texture
operator|=
literal|0
expr_stmt|;
comment|// will get updated in the next render()
name|m_cursor
operator|.
name|size
operator|=
name|image
operator|.
name|size
argument_list|()
expr_stmt|;
name|m_cursor
operator|.
name|customCursorImage
operator|=
name|image
expr_stmt|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|update
name|void
name|QEglFSCursor
operator|::
name|update
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|rgn
parameter_list|)
block|{
name|QWindowSystemInterface
operator|::
name|handleSynchronousExposeEvent
argument_list|(
name|m_screen
operator|->
name|topLevelAt
argument_list|(
name|m_pos
argument_list|)
argument_list|,
name|rgn
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cursorRect
name|QRect
name|QEglFSCursor
operator|::
name|cursorRect
parameter_list|()
specifier|const
block|{
return|return
name|QRect
argument_list|(
name|m_pos
operator|-
name|m_cursor
operator|.
name|hotSpot
argument_list|,
name|m_cursor
operator|.
name|size
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pos
name|QPoint
name|QEglFSCursor
operator|::
name|pos
parameter_list|()
specifier|const
block|{
return|return
name|m_pos
return|;
block|}
end_function
begin_function
DECL|function|setPos
name|void
name|QEglFSCursor
operator|::
name|setPos
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
specifier|const
name|QRect
name|oldCursorRect
init|=
name|cursorRect
argument_list|()
decl_stmt|;
name|m_pos
operator|=
name|pos
expr_stmt|;
name|update
argument_list|(
name|oldCursorRect
operator||
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pointerEvent
name|void
name|QEglFSCursor
operator|::
name|pointerEvent
parameter_list|(
specifier|const
name|QMouseEvent
modifier|&
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|.
name|type
argument_list|()
operator|!=
name|QEvent
operator|::
name|MouseMove
condition|)
return|return;
specifier|const
name|QRect
name|oldCursorRect
init|=
name|cursorRect
argument_list|()
decl_stmt|;
name|m_pos
operator|=
name|event
operator|.
name|pos
argument_list|()
expr_stmt|;
name|update
argument_list|(
name|oldCursorRect
operator||
name|cursorRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintOnScreen
name|void
name|QEglFSCursor
operator|::
name|paintOnScreen
parameter_list|()
block|{
specifier|const
name|QRectF
name|cr
init|=
name|cursorRect
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|screenRect
argument_list|(
name|m_screen
operator|->
name|geometry
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|GLfloat
name|x1
init|=
literal|2
operator|*
operator|(
name|cr
operator|.
name|left
argument_list|()
operator|/
name|screenRect
operator|.
name|width
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|GLfloat
name|x2
init|=
literal|2
operator|*
operator|(
name|cr
operator|.
name|right
argument_list|()
operator|/
name|screenRect
operator|.
name|width
argument_list|()
operator|)
operator|-
literal|1
decl_stmt|;
specifier|const
name|GLfloat
name|y1
init|=
literal|1
operator|-
operator|(
name|cr
operator|.
name|top
argument_list|()
operator|/
name|screenRect
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
decl_stmt|;
specifier|const
name|GLfloat
name|y2
init|=
literal|1
operator|-
operator|(
name|cr
operator|.
name|bottom
argument_list|()
operator|/
name|screenRect
operator|.
name|height
argument_list|()
operator|)
operator|*
literal|2
decl_stmt|;
name|QRectF
name|r
argument_list|(
name|QPointF
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
argument_list|,
name|QPointF
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|)
argument_list|)
decl_stmt|;
name|draw
argument_list|(
name|r
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|draw
name|void
name|QEglFSCursor
operator|::
name|draw
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|r
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_program
condition|)
block|{
comment|// one time initialization
name|createShaderPrograms
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_cursorAtlas
operator|.
name|texture
condition|)
block|{
name|createCursorTexture
argument_list|(
operator|&
name|m_cursorAtlas
operator|.
name|texture
argument_list|,
name|m_cursorAtlas
operator|.
name|image
argument_list|)
expr_stmt|;
name|m_cursorAtlas
operator|.
name|image
operator|=
name|QImage
argument_list|()
expr_stmt|;
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|!=
name|Qt
operator|::
name|BitmapCursor
condition|)
name|m_cursor
operator|.
name|texture
operator|=
name|m_cursorAtlas
operator|.
name|texture
expr_stmt|;
block|}
block|}
if|if
condition|(
name|m_cursor
operator|.
name|shape
operator|==
name|Qt
operator|::
name|BitmapCursor
operator|&&
operator|!
name|m_cursor
operator|.
name|customCursorImage
operator|.
name|isNull
argument_list|()
condition|)
block|{
comment|// upload the custom cursor
name|createCursorTexture
argument_list|(
operator|&
name|m_cursor
operator|.
name|customCursorTexture
argument_list|,
name|m_cursor
operator|.
name|customCursorImage
argument_list|)
expr_stmt|;
name|m_cursor
operator|.
name|texture
operator|=
name|m_cursor
operator|.
name|customCursorTexture
expr_stmt|;
name|m_cursor
operator|.
name|customCursorImage
operator|=
name|QImage
argument_list|()
expr_stmt|;
block|}
name|Q_ASSERT
argument_list|(
name|m_cursor
operator|.
name|texture
argument_list|)
expr_stmt|;
name|glUseProgram
argument_list|(
name|m_program
argument_list|)
expr_stmt|;
specifier|const
name|GLfloat
name|x1
init|=
name|r
operator|.
name|left
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|x2
init|=
name|r
operator|.
name|right
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|y1
init|=
name|r
operator|.
name|top
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|y2
init|=
name|r
operator|.
name|bottom
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|cursorCoordinates
index|[]
init|=
block|{
name|x1
block|,
name|y2
block|,
name|x2
block|,
name|y2
block|,
name|x1
block|,
name|y1
block|,
name|x2
block|,
name|y1
block|}
decl_stmt|;
specifier|const
name|GLfloat
name|s1
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|left
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|s2
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|right
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|t1
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|top
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|t2
init|=
name|m_cursor
operator|.
name|textureRect
operator|.
name|bottom
argument_list|()
decl_stmt|;
specifier|const
name|GLfloat
name|textureCoordinates
index|[]
init|=
block|{
name|s1
block|,
name|t2
block|,
name|s2
block|,
name|t2
block|,
name|s1
block|,
name|t1
block|,
name|s2
block|,
name|t1
block|}
decl_stmt|;
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_cursor
operator|.
name|texture
argument_list|)
expr_stmt|;
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
name|cursorCoordinates
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
name|glUniform1f
argument_list|(
name|m_textureEntry
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glEnable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|glBlendFunc
argument_list|(
name|GL_ONE
argument_list|,
name|GL_ONE_MINUS_SRC_ALPHA
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
comment|// disable depth testing to make sure cursor is always on top
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_STRIP
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
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
name|glUseProgram
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
