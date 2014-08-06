begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"background_renderer.h"
end_include
begin_include
include|#
directive|include
file|<qmath.h>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<QOpenGLShaderProgram>
end_include
begin_include
include|#
directive|include
file|<QOpenGLContext>
end_include
begin_include
include|#
directive|include
file|<QOpenGLFunctions>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_decl_stmt
DECL|variable|vertex_shader
specifier|static
specifier|const
name|char
name|vertex_shader
index|[]
init|=
literal|"attribute highp vec3 vertexCoord;"
literal|"void main() {"
literal|"   gl_Position = vec4(vertexCoord,1.0);"
literal|"}"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|fragment_shader
specifier|static
specifier|const
name|char
name|fragment_shader
index|[]
init|=
literal|"void main() {"
literal|"   gl_FragColor = vec4(0.0,1.0,0.0,1.0);"
literal|"}"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|vertices
specifier|static
specifier|const
name|float
name|vertices
index|[]
init|=
block|{
operator|-
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
operator|-
literal|1
block|,
literal|1
block|,
literal|0
block|,
literal|1
block|,
operator|-
literal|1
block|,
literal|0
block|,
literal|1
block|,
literal|1
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|FragmentToy
name|FragmentToy
operator|::
name|FragmentToy
parameter_list|(
specifier|const
name|QString
modifier|&
name|fragmentSource
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_recompile_shaders
argument_list|(
literal|true
argument_list|)
block|{
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|fragmentSource
argument_list|)
condition|)
block|{
name|QFileInfo
name|info
argument_list|(
name|fragmentSource
argument_list|)
decl_stmt|;
name|m_fragment_file_last_modified
operator|=
name|info
operator|.
name|lastModified
argument_list|()
expr_stmt|;
name|m_fragment_file
operator|=
name|fragmentSource
expr_stmt|;
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
name|m_watcher
operator|.
name|addPath
argument_list|(
name|info
operator|.
name|canonicalFilePath
argument_list|()
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
operator|&
name|m_watcher
argument_list|,
operator|&
name|QFileSystemWatcher
operator|::
name|fileChanged
argument_list|,
name|this
argument_list|,
operator|&
name|FragmentToy
operator|::
name|fileChanged
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_constructor
begin_function
DECL|function|draw
name|void
name|FragmentToy
operator|::
name|draw
parameter_list|(
specifier|const
name|QSize
modifier|&
name|windowSize
parameter_list|)
block|{
if|if
condition|(
operator|!
name|m_program
condition|)
name|initializeOpenGLFunctions
argument_list|()
expr_stmt|;
name|glDisable
argument_list|(
name|GL_STENCIL_TEST
argument_list|)
expr_stmt|;
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|glClearColor
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|glClear
argument_list|(
name|GL_COLOR_BUFFER_BIT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_vao
operator|.
name|isCreated
argument_list|()
condition|)
name|m_vao
operator|.
name|create
argument_list|()
expr_stmt|;
name|m_vao
operator|.
name|bind
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|m_vertex_buffer
operator|.
name|isCreated
argument_list|()
condition|)
block|{
name|m_vertex_buffer
operator|.
name|create
argument_list|()
expr_stmt|;
name|m_vertex_buffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|m_vertex_buffer
operator|.
name|allocate
argument_list|(
name|vertices
argument_list|,
sizeof|sizeof
argument_list|(
name|vertices
argument_list|)
argument_list|)
expr_stmt|;
name|m_vertex_buffer
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_program
condition|)
block|{
name|m_program
operator|.
name|reset
argument_list|(
operator|new
name|QOpenGLShaderProgram
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|create
argument_list|()
expr_stmt|;
name|m_vertex_shader
operator|.
name|reset
argument_list|(
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Vertex
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_vertex_shader
operator|->
name|compileSourceCode
argument_list|(
name|vertex_shader
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to compile the vertex shader:"
operator|<<
name|m_vertex_shader
operator|->
name|log
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_program
operator|->
name|addShader
argument_list|(
name|m_vertex_shader
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to add vertex shader to program:"
operator|<<
name|m_program
operator|->
name|log
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|m_fragment_shader
condition|)
block|{
name|QByteArray
name|data
decl_stmt|;
if|if
condition|(
name|m_fragment_file
operator|.
name|size
argument_list|()
condition|)
block|{
name|QFile
name|file
argument_list|(
name|m_fragment_file
argument_list|)
decl_stmt|;
if|if
condition|(
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
block|{
name|data
operator|=
name|file
operator|.
name|readAll
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to load input file, falling back to default"
expr_stmt|;
name|data
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|fragment_shader
argument_list|,
sizeof|sizeof
argument_list|(
name|fragment_shader
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|QFile
name|qrcFile
argument_list|(
literal|":/background.frag"
argument_list|)
decl_stmt|;
if|if
condition|(
name|qrcFile
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
name|data
operator|=
name|qrcFile
operator|.
name|readAll
argument_list|()
expr_stmt|;
else|else
name|data
operator|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|fragment_shader
argument_list|,
sizeof|sizeof
argument_list|(
name|fragment_shader
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|data
operator|.
name|size
argument_list|()
condition|)
block|{
name|m_fragment_shader
operator|.
name|reset
argument_list|(
operator|new
name|QOpenGLShader
argument_list|(
name|QOpenGLShader
operator|::
name|Fragment
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_fragment_shader
operator|->
name|compileSourceCode
argument_list|(
name|data
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to compile fragment shader:"
operator|<<
name|m_fragment_shader
operator|->
name|log
argument_list|()
expr_stmt|;
name|m_fragment_shader
operator|.
name|reset
argument_list|(
name|Q_NULLPTR
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Unknown error, no fragment shader"
expr_stmt|;
block|}
if|if
condition|(
name|m_fragment_shader
condition|)
block|{
if|if
condition|(
operator|!
name|m_program
operator|->
name|addShader
argument_list|(
name|m_fragment_shader
operator|.
name|data
argument_list|()
argument_list|)
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to add fragment shader to program:"
operator|<<
name|m_program
operator|->
name|log
argument_list|()
expr_stmt|;
block|}
block|}
block|}
if|if
condition|(
name|m_recompile_shaders
condition|)
block|{
name|m_recompile_shaders
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|m_program
operator|->
name|link
argument_list|()
condition|)
block|{
name|m_vertex_coord_pos
operator|=
name|m_program
operator|->
name|attributeLocation
argument_list|(
literal|"vertexCoord"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Failed to link shader program"
operator|<<
name|m_program
operator|->
name|log
argument_list|()
expr_stmt|;
block|}
block|}
name|m_program
operator|->
name|bind
argument_list|()
expr_stmt|;
name|m_vertex_buffer
operator|.
name|bind
argument_list|()
expr_stmt|;
name|m_program
operator|->
name|setAttributeBuffer
argument_list|(
literal|"vertexCoord"
argument_list|,
name|GL_FLOAT
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|enableAttributeArray
argument_list|(
literal|"vertexCoord"
argument_list|)
expr_stmt|;
name|m_vertex_buffer
operator|.
name|release
argument_list|()
expr_stmt|;
name|float
name|radiens
init|=
operator|(
name|QTime
operator|::
name|currentTime
argument_list|()
operator|.
name|msecsSinceStartOfDay
argument_list|()
operator|/
literal|60
operator|)
operator|/
operator|(
literal|2
operator|*
name|M_PI
operator|)
decl_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
literal|"currentTime"
argument_list|,
operator|(
name|uint
operator|)
name|QDateTime
operator|::
name|currentDateTime
argument_list|()
operator|.
name|toMSecsSinceEpoch
argument_list|()
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
literal|"radiens"
argument_list|,
name|radiens
argument_list|)
expr_stmt|;
name|m_program
operator|->
name|setUniformValue
argument_list|(
literal|"windowSize"
argument_list|,
name|windowSize
argument_list|)
expr_stmt|;
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
operator|->
name|functions
argument_list|()
operator|->
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_STRIP
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
name|m_vao
operator|.
name|release
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fileChanged
name|void
name|FragmentToy
operator|::
name|fileChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|m_fragment_file
argument_list|)
condition|)
block|{
name|QFileInfo
name|fragment_source
argument_list|(
name|m_fragment_file
argument_list|)
decl_stmt|;
if|if
condition|(
name|fragment_source
operator|.
name|lastModified
argument_list|()
operator|>
name|m_fragment_file_last_modified
condition|)
block|{
name|m_fragment_file_last_modified
operator|=
name|fragment_source
operator|.
name|lastModified
argument_list|()
expr_stmt|;
name|m_recompile_shaders
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|m_program
condition|)
block|{
name|m_program
operator|->
name|removeShader
argument_list|(
name|m_fragment_shader
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|m_fragment_shader
operator|.
name|reset
argument_list|(
name|Q_NULLPTR
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|m_recompile_shaders
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|m_program
condition|)
block|{
name|m_program
operator|->
name|removeShader
argument_list|(
name|m_fragment_shader
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|m_fragment_shader
operator|.
name|reset
argument_list|(
name|Q_NULLPTR
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
end_unit
