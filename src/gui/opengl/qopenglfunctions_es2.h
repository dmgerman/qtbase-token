begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Klaralvdalens Datakonsult AB (KDAB) ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLVERSIONFUNCTIONS_ES2_H
end_ifndef
begin_define
DECL|macro|QOPENGLVERSIONFUNCTIONS_ES2_H
define|#
directive|define
name|QOPENGLVERSIONFUNCTIONS_ES2_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_QDOC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<QtGui/QOpenGLVersionFunctions>
end_include
begin_include
include|#
directive|include
file|<QtGui/qopenglcontext.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLFunctions_ES2Private
name|class
name|QOpenGLFunctions_ES2Private
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLFunctions_ES2
range|:
name|public
name|QAbstractOpenGLFunctions
block|{
name|public
operator|:
name|QOpenGLFunctions_ES2
argument_list|()
block|;
operator|~
name|QOpenGLFunctions_ES2
argument_list|()
block|;
name|bool
name|initializeOpenGLFunctions
argument_list|()
name|Q_DECL_OVERRIDE
block|;
comment|// OpenGL ES2 core functions
name|void
name|glActiveTexture
argument_list|(
argument|GLenum texture
argument_list|)
block|;
name|void
name|glAttachShader
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint shader
argument_list|)
block|;
name|void
name|glBindAttribLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|const GLchar* name
argument_list|)
block|;
name|void
name|glBindBuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint buffer
argument_list|)
block|;
name|void
name|glBindFramebuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint framebuffer
argument_list|)
block|;
name|void
name|glBindRenderbuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint renderbuffer
argument_list|)
block|;
name|void
name|glBindTexture
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint texture
argument_list|)
block|;
name|void
name|glBlendColor
argument_list|(
argument|GLclampf red
argument_list|,
argument|GLclampf green
argument_list|,
argument|GLclampf blue
argument_list|,
argument|GLclampf alpha
argument_list|)
block|;
name|void
name|glBlendEquation
argument_list|(
argument|GLenum mode
argument_list|)
block|;
name|void
name|glBlendEquationSeparate
argument_list|(
argument|GLenum modeRGB
argument_list|,
argument|GLenum modeAlpha
argument_list|)
block|;
name|void
name|glBlendFunc
argument_list|(
argument|GLenum sfactor
argument_list|,
argument|GLenum dfactor
argument_list|)
block|;
name|void
name|glBlendFuncSeparate
argument_list|(
argument|GLenum srcRGB
argument_list|,
argument|GLenum dstRGB
argument_list|,
argument|GLenum srcAlpha
argument_list|,
argument|GLenum dstAlpha
argument_list|)
block|;
name|void
name|glBufferData
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizeiptr size
argument_list|,
argument|const GLvoid* data
argument_list|,
argument|GLenum usage
argument_list|)
block|;
name|void
name|glBufferSubData
argument_list|(
argument|GLenum target
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|,
argument|const GLvoid* data
argument_list|)
block|;
name|GLenum
name|glCheckFramebufferStatus
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|void
name|glClear
argument_list|(
argument|GLbitfield mask
argument_list|)
block|;
name|void
name|glClearColor
argument_list|(
argument|GLclampf red
argument_list|,
argument|GLclampf green
argument_list|,
argument|GLclampf blue
argument_list|,
argument|GLclampf alpha
argument_list|)
block|;
name|void
name|glClearDepthf
argument_list|(
argument|GLclampf depth
argument_list|)
block|;
name|void
name|glClearStencil
argument_list|(
argument|GLint s
argument_list|)
block|;
name|void
name|glColorMask
argument_list|(
argument|GLboolean red
argument_list|,
argument|GLboolean green
argument_list|,
argument|GLboolean blue
argument_list|,
argument|GLboolean alpha
argument_list|)
block|;
name|void
name|glCompileShader
argument_list|(
argument|GLuint shader
argument_list|)
block|;
name|void
name|glCompressedTexImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint border
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const GLvoid* data
argument_list|)
block|;
name|void
name|glCompressedTexSubImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const GLvoid* data
argument_list|)
block|;
name|void
name|glCopyTexImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint border
argument_list|)
block|;
name|void
name|glCopyTexSubImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|GLuint
name|glCreateProgram
argument_list|(
name|void
argument_list|)
block|;
name|GLuint
name|glCreateShader
argument_list|(
argument|GLenum type
argument_list|)
block|;
name|void
name|glCullFace
argument_list|(
argument|GLenum mode
argument_list|)
block|;
name|void
name|glDeleteBuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* buffers
argument_list|)
block|;
name|void
name|glDeleteFramebuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* framebuffers
argument_list|)
block|;
name|void
name|glDeleteProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|void
name|glDeleteRenderbuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* renderbuffers
argument_list|)
block|;
name|void
name|glDeleteShader
argument_list|(
argument|GLuint shader
argument_list|)
block|;
name|void
name|glDeleteTextures
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* textures
argument_list|)
block|;
name|void
name|glDepthFunc
argument_list|(
argument|GLenum func
argument_list|)
block|;
name|void
name|glDepthMask
argument_list|(
argument|GLboolean flag
argument_list|)
block|;
name|void
name|glDepthRangef
argument_list|(
argument|GLclampf zNear
argument_list|,
argument|GLclampf zFar
argument_list|)
block|;
name|void
name|glDetachShader
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint shader
argument_list|)
block|;
name|void
name|glDisable
argument_list|(
argument|GLenum cap
argument_list|)
block|;
name|void
name|glDisableVertexAttribArray
argument_list|(
argument|GLuint index
argument_list|)
block|;
name|void
name|glDrawArrays
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|)
block|;
name|void
name|glDrawElements
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid* indices
argument_list|)
block|;
name|void
name|glEnable
argument_list|(
argument|GLenum cap
argument_list|)
block|;
name|void
name|glEnableVertexAttribArray
argument_list|(
argument|GLuint index
argument_list|)
block|;
name|void
name|glFinish
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glFlush
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glFramebufferRenderbuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLenum renderbuffertarget
argument_list|,
argument|GLuint renderbuffer
argument_list|)
block|;
name|void
name|glFramebufferTexture2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLenum textarget
argument_list|,
argument|GLuint texture
argument_list|,
argument|GLint level
argument_list|)
block|;
name|void
name|glFrontFace
argument_list|(
argument|GLenum mode
argument_list|)
block|;
name|void
name|glGenBuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* buffers
argument_list|)
block|;
name|void
name|glGenerateMipmap
argument_list|(
argument|GLenum target
argument_list|)
block|;
name|void
name|glGenFramebuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* framebuffers
argument_list|)
block|;
name|void
name|glGenRenderbuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* renderbuffers
argument_list|)
block|;
name|void
name|glGenTextures
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* textures
argument_list|)
block|;
name|void
name|glGetActiveAttrib
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLint* size
argument_list|,
argument|GLenum* type
argument_list|,
argument|GLchar* name
argument_list|)
block|;
name|void
name|glGetActiveUniform
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLint* size
argument_list|,
argument|GLenum* type
argument_list|,
argument|GLchar* name
argument_list|)
block|;
name|void
name|glGetAttachedShaders
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei maxcount
argument_list|,
argument|GLsizei* count
argument_list|,
argument|GLuint* shaders
argument_list|)
block|;
name|int
name|glGetAttribLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar* name
argument_list|)
block|;
name|void
name|glGetBooleanv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLboolean* params
argument_list|)
block|;
name|void
name|glGetBufferParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|GLenum
name|glGetError
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glGetFloatv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|;
name|void
name|glGetFramebufferAttachmentParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetIntegerv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetProgramiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetProgramInfoLog
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* infolog
argument_list|)
block|;
name|void
name|glGetRenderbufferParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetShaderiv
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetShaderInfoLog
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* infolog
argument_list|)
block|;
name|void
name|glGetShaderPrecisionFormat
argument_list|(
argument|GLenum shadertype
argument_list|,
argument|GLenum precisiontype
argument_list|,
argument|GLint* range
argument_list|,
argument|GLint* precision
argument_list|)
block|;
name|void
name|glGetShaderSource
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* source
argument_list|)
block|;
specifier|const
name|GLubyte
operator|*
name|glGetString
argument_list|(
argument|GLenum name
argument_list|)
block|;
name|void
name|glGetTexParameterfv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|;
name|void
name|glGetTexParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetUniformfv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat* params
argument_list|)
block|;
name|void
name|glGetUniformiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|int
name|glGetUniformLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar* name
argument_list|)
block|;
name|void
name|glGetVertexAttribfv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|;
name|void
name|glGetVertexAttribiv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|;
name|void
name|glGetVertexAttribPointerv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLvoid** pointer
argument_list|)
block|;
name|void
name|glHint
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum mode
argument_list|)
block|;
name|GLboolean
name|glIsBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|;
name|GLboolean
name|glIsEnabled
argument_list|(
argument|GLenum cap
argument_list|)
block|;
name|GLboolean
name|glIsFramebuffer
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|;
name|GLboolean
name|glIsProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|GLboolean
name|glIsRenderbuffer
argument_list|(
argument|GLuint renderbuffer
argument_list|)
block|;
name|GLboolean
name|glIsShader
argument_list|(
argument|GLuint shader
argument_list|)
block|;
name|GLboolean
name|glIsTexture
argument_list|(
argument|GLuint texture
argument_list|)
block|;
name|void
name|glLineWidth
argument_list|(
argument|GLfloat width
argument_list|)
block|;
name|void
name|glLinkProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|void
name|glPixelStorei
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|;
name|void
name|glPolygonOffset
argument_list|(
argument|GLfloat factor
argument_list|,
argument|GLfloat units
argument_list|)
block|;
name|void
name|glReadPixels
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLvoid* pixels
argument_list|)
block|;
name|void
name|glReleaseShaderCompiler
argument_list|(
name|void
argument_list|)
block|;
name|void
name|glRenderbufferStorage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glSampleCoverage
argument_list|(
argument|GLclampf value
argument_list|,
argument|GLboolean invert
argument_list|)
block|;
name|void
name|glScissor
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|void
name|glShaderBinary
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* shaders
argument_list|,
argument|GLenum binaryformat
argument_list|,
argument|const GLvoid* binary
argument_list|,
argument|GLsizei length
argument_list|)
block|;
name|void
name|glShaderSource
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLchar* *string
argument_list|,
argument|const GLint* length
argument_list|)
block|;
name|void
name|glStencilFunc
argument_list|(
argument|GLenum func
argument_list|,
argument|GLint ref
argument_list|,
argument|GLuint mask
argument_list|)
block|;
name|void
name|glStencilFuncSeparate
argument_list|(
argument|GLenum face
argument_list|,
argument|GLenum func
argument_list|,
argument|GLint ref
argument_list|,
argument|GLuint mask
argument_list|)
block|;
name|void
name|glStencilMask
argument_list|(
argument|GLuint mask
argument_list|)
block|;
name|void
name|glStencilMaskSeparate
argument_list|(
argument|GLenum face
argument_list|,
argument|GLuint mask
argument_list|)
block|;
name|void
name|glStencilOp
argument_list|(
argument|GLenum fail
argument_list|,
argument|GLenum zfail
argument_list|,
argument|GLenum zpass
argument_list|)
block|;
name|void
name|glStencilOpSeparate
argument_list|(
argument|GLenum face
argument_list|,
argument|GLenum fail
argument_list|,
argument|GLenum zfail
argument_list|,
argument|GLenum zpass
argument_list|)
block|;
name|void
name|glTexImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint border
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid* pixels
argument_list|)
block|;
name|void
name|glTexParameterf
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat param
argument_list|)
block|;
name|void
name|glTexParameterfv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLfloat* params
argument_list|)
block|;
name|void
name|glTexParameteri
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|;
name|void
name|glTexParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLint* params
argument_list|)
block|;
name|void
name|glTexSubImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid* pixels
argument_list|)
block|;
name|void
name|glUniform1f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|)
block|;
name|void
name|glUniform1fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|;
name|void
name|glUniform1i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|)
block|;
name|void
name|glUniform1iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|;
name|void
name|glUniform2f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|;
name|void
name|glUniform2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|;
name|void
name|glUniform2i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|)
block|;
name|void
name|glUniform2iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|;
name|void
name|glUniform3f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|;
name|void
name|glUniform3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|;
name|void
name|glUniform3i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLint z
argument_list|)
block|;
name|void
name|glUniform3iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|;
name|void
name|glUniform4f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|,
argument|GLfloat w
argument_list|)
block|;
name|void
name|glUniform4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|;
name|void
name|glUniform4i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLint z
argument_list|,
argument|GLint w
argument_list|)
block|;
name|void
name|glUniform4iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|;
name|void
name|glUniformMatrix2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat* value
argument_list|)
block|;
name|void
name|glUniformMatrix3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat* value
argument_list|)
block|;
name|void
name|glUniformMatrix4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat* value
argument_list|)
block|;
name|void
name|glUseProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|void
name|glValidateProgram
argument_list|(
argument|GLuint program
argument_list|)
block|;
name|void
name|glVertexAttrib1f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|)
block|;
name|void
name|glVertexAttrib1fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|;
name|void
name|glVertexAttrib2f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|;
name|void
name|glVertexAttrib2fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|;
name|void
name|glVertexAttrib3f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|;
name|void
name|glVertexAttrib3fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|;
name|void
name|glVertexAttrib4f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|,
argument|GLfloat w
argument_list|)
block|;
name|void
name|glVertexAttrib4fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|;
name|void
name|glVertexAttribPointer
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLboolean normalized
argument_list|,
argument|GLsizei stride
argument_list|,
argument|const GLvoid* ptr
argument_list|)
block|;
name|void
name|glViewport
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QOpenGLContext
block|;
specifier|static
name|bool
name|isContextCompatible
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
specifier|static
name|QOpenGLVersionProfile
name|versionProfile
argument_list|()
block|;
comment|// For future expansion - not used
name|QOpenGLFunctions_ES2Private
operator|*
name|d_es2
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// OpenGL ES2 core functions
end_comment
begin_expr_stmt
DECL|function|glActiveTexture
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glActiveTexture
argument_list|(
argument|GLenum texture
argument_list|)
block|{
operator|::
name|glActiveTexture
argument_list|(
name|texture
argument_list|)
block|; }
DECL|function|glAttachShader
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glAttachShader
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint shader
argument_list|)
block|{
operator|::
name|glAttachShader
argument_list|(
name|program
argument_list|,
name|shader
argument_list|)
block|; }
DECL|function|glBindAttribLocation
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBindAttribLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|const GLchar* name
argument_list|)
block|{
operator|::
name|glBindAttribLocation
argument_list|(
name|program
argument_list|,
name|index
argument_list|,
name|name
argument_list|)
block|; }
DECL|function|glBindBuffer
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBindBuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint buffer
argument_list|)
block|{
operator|::
name|glBindBuffer
argument_list|(
name|target
argument_list|,
name|buffer
argument_list|)
block|; }
DECL|function|glBindFramebuffer
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBindFramebuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint framebuffer
argument_list|)
block|{
operator|::
name|glBindFramebuffer
argument_list|(
name|target
argument_list|,
name|framebuffer
argument_list|)
block|; }
DECL|function|glBindRenderbuffer
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBindRenderbuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint renderbuffer
argument_list|)
block|{
operator|::
name|glBindRenderbuffer
argument_list|(
name|target
argument_list|,
name|renderbuffer
argument_list|)
block|; }
DECL|function|glBindTexture
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBindTexture
argument_list|(
argument|GLenum target
argument_list|,
argument|GLuint texture
argument_list|)
block|{
operator|::
name|glBindTexture
argument_list|(
name|target
argument_list|,
name|texture
argument_list|)
block|; }
DECL|function|glBlendColor
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBlendColor
argument_list|(
argument|GLclampf red
argument_list|,
argument|GLclampf green
argument_list|,
argument|GLclampf blue
argument_list|,
argument|GLclampf alpha
argument_list|)
block|{
operator|::
name|glBlendColor
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
block|; }
DECL|function|glBlendEquation
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBlendEquation
argument_list|(
argument|GLenum mode
argument_list|)
block|{
operator|::
name|glBlendEquation
argument_list|(
name|mode
argument_list|)
block|; }
DECL|function|glBlendEquationSeparate
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBlendEquationSeparate
argument_list|(
argument|GLenum modeRGB
argument_list|,
argument|GLenum modeAlpha
argument_list|)
block|{
operator|::
name|glBlendEquationSeparate
argument_list|(
name|modeRGB
argument_list|,
name|modeAlpha
argument_list|)
block|; }
DECL|function|glBlendFunc
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBlendFunc
argument_list|(
argument|GLenum sfactor
argument_list|,
argument|GLenum dfactor
argument_list|)
block|{
operator|::
name|glBlendFunc
argument_list|(
name|sfactor
argument_list|,
name|dfactor
argument_list|)
block|; }
DECL|function|glBlendFuncSeparate
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBlendFuncSeparate
argument_list|(
argument|GLenum srcRGB
argument_list|,
argument|GLenum dstRGB
argument_list|,
argument|GLenum srcAlpha
argument_list|,
argument|GLenum dstAlpha
argument_list|)
block|{
operator|::
name|glBlendFuncSeparate
argument_list|(
name|srcRGB
argument_list|,
name|dstRGB
argument_list|,
name|srcAlpha
argument_list|,
name|dstAlpha
argument_list|)
block|; }
DECL|function|glBufferData
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBufferData
argument_list|(
argument|GLenum target
argument_list|,
argument|GLsizeiptr size
argument_list|,
argument|const GLvoid* data
argument_list|,
argument|GLenum usage
argument_list|)
block|{
operator|::
name|glBufferData
argument_list|(
name|target
argument_list|,
name|size
argument_list|,
name|data
argument_list|,
name|usage
argument_list|)
block|; }
DECL|function|glBufferSubData
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glBufferSubData
argument_list|(
argument|GLenum target
argument_list|,
argument|GLintptr offset
argument_list|,
argument|GLsizeiptr size
argument_list|,
argument|const GLvoid* data
argument_list|)
block|{
operator|::
name|glBufferSubData
argument_list|(
name|target
argument_list|,
name|offset
argument_list|,
name|size
argument_list|,
name|data
argument_list|)
block|; }
DECL|function|glCheckFramebufferStatus
specifier|inline
name|GLenum
name|QOpenGLFunctions_ES2
operator|::
name|glCheckFramebufferStatus
argument_list|(
argument|GLenum target
argument_list|)
block|{
return|return
operator|::
name|glCheckFramebufferStatus
argument_list|(
name|target
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glClear
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glClear
argument_list|(
argument|GLbitfield mask
argument_list|)
block|{
operator|::
name|glClear
argument_list|(
name|mask
argument_list|)
block|; }
DECL|function|glClearColor
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glClearColor
argument_list|(
argument|GLclampf red
argument_list|,
argument|GLclampf green
argument_list|,
argument|GLclampf blue
argument_list|,
argument|GLclampf alpha
argument_list|)
block|{
operator|::
name|glClearColor
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
block|; }
DECL|function|glClearDepthf
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glClearDepthf
argument_list|(
argument|GLclampf depth
argument_list|)
block|{
operator|::
name|glClearDepthf
argument_list|(
name|depth
argument_list|)
block|; }
DECL|function|glClearStencil
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glClearStencil
argument_list|(
argument|GLint s
argument_list|)
block|{
operator|::
name|glClearStencil
argument_list|(
name|s
argument_list|)
block|; }
DECL|function|glColorMask
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glColorMask
argument_list|(
argument|GLboolean red
argument_list|,
argument|GLboolean green
argument_list|,
argument|GLboolean blue
argument_list|,
argument|GLboolean alpha
argument_list|)
block|{
operator|::
name|glColorMask
argument_list|(
name|red
argument_list|,
name|green
argument_list|,
name|blue
argument_list|,
name|alpha
argument_list|)
block|; }
DECL|function|glCompileShader
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glCompileShader
argument_list|(
argument|GLuint shader
argument_list|)
block|{
operator|::
name|glCompileShader
argument_list|(
name|shader
argument_list|)
block|; }
DECL|function|glCompressedTexImage2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glCompressedTexImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint border
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const GLvoid* data
argument_list|)
block|{
operator|::
name|glCompressedTexImage2D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|border
argument_list|,
name|imageSize
argument_list|,
name|data
argument_list|)
block|; }
DECL|function|glCompressedTexSubImage2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glCompressedTexSubImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLsizei imageSize
argument_list|,
argument|const GLvoid* data
argument_list|)
block|{
operator|::
name|glCompressedTexSubImage2D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|xoffset
argument_list|,
name|yoffset
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|,
name|imageSize
argument_list|,
name|data
argument_list|)
block|; }
DECL|function|glCopyTexImage2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glCopyTexImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint border
argument_list|)
block|{
operator|::
name|glCopyTexImage2D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|internalformat
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|border
argument_list|)
block|; }
DECL|function|glCopyTexSubImage2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glCopyTexSubImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
operator|::
name|glCopyTexSubImage2D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|xoffset
argument_list|,
name|yoffset
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|; }
DECL|function|glCreateProgram
specifier|inline
name|GLuint
name|QOpenGLFunctions_ES2
operator|::
name|glCreateProgram
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|::
name|glCreateProgram
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glCreateShader
specifier|inline
name|GLuint
name|QOpenGLFunctions_ES2
operator|::
name|glCreateShader
argument_list|(
argument|GLenum type
argument_list|)
block|{
return|return
operator|::
name|glCreateShader
argument_list|(
name|type
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glCullFace
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glCullFace
argument_list|(
argument|GLenum mode
argument_list|)
block|{
operator|::
name|glCullFace
argument_list|(
name|mode
argument_list|)
block|; }
DECL|function|glDeleteBuffers
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDeleteBuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* buffers
argument_list|)
block|{
operator|::
name|glDeleteBuffers
argument_list|(
name|n
argument_list|,
name|buffers
argument_list|)
block|; }
DECL|function|glDeleteFramebuffers
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDeleteFramebuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* framebuffers
argument_list|)
block|{
operator|::
name|glDeleteFramebuffers
argument_list|(
name|n
argument_list|,
name|framebuffers
argument_list|)
block|; }
DECL|function|glDeleteProgram
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDeleteProgram
argument_list|(
argument|GLuint program
argument_list|)
block|{
operator|::
name|glDeleteProgram
argument_list|(
name|program
argument_list|)
block|; }
DECL|function|glDeleteRenderbuffers
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDeleteRenderbuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* renderbuffers
argument_list|)
block|{
operator|::
name|glDeleteRenderbuffers
argument_list|(
name|n
argument_list|,
name|renderbuffers
argument_list|)
block|; }
DECL|function|glDeleteShader
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDeleteShader
argument_list|(
argument|GLuint shader
argument_list|)
block|{
operator|::
name|glDeleteShader
argument_list|(
name|shader
argument_list|)
block|; }
DECL|function|glDeleteTextures
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDeleteTextures
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* textures
argument_list|)
block|{
operator|::
name|glDeleteTextures
argument_list|(
name|n
argument_list|,
name|textures
argument_list|)
block|; }
DECL|function|glDepthFunc
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDepthFunc
argument_list|(
argument|GLenum func
argument_list|)
block|{
operator|::
name|glDepthFunc
argument_list|(
name|func
argument_list|)
block|; }
DECL|function|glDepthMask
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDepthMask
argument_list|(
argument|GLboolean flag
argument_list|)
block|{
operator|::
name|glDepthMask
argument_list|(
name|flag
argument_list|)
block|; }
DECL|function|glDepthRangef
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDepthRangef
argument_list|(
argument|GLclampf zNear
argument_list|,
argument|GLclampf zFar
argument_list|)
block|{
operator|::
name|glDepthRangef
argument_list|(
name|zNear
argument_list|,
name|zFar
argument_list|)
block|; }
DECL|function|glDetachShader
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDetachShader
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint shader
argument_list|)
block|{
operator|::
name|glDetachShader
argument_list|(
name|program
argument_list|,
name|shader
argument_list|)
block|; }
DECL|function|glDisable
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDisable
argument_list|(
argument|GLenum cap
argument_list|)
block|{
operator|::
name|glDisable
argument_list|(
name|cap
argument_list|)
block|; }
DECL|function|glDisableVertexAttribArray
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDisableVertexAttribArray
argument_list|(
argument|GLuint index
argument_list|)
block|{
operator|::
name|glDisableVertexAttribArray
argument_list|(
name|index
argument_list|)
block|; }
DECL|function|glDrawArrays
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDrawArrays
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLint first
argument_list|,
argument|GLsizei count
argument_list|)
block|{
operator|::
name|glDrawArrays
argument_list|(
name|mode
argument_list|,
name|first
argument_list|,
name|count
argument_list|)
block|; }
DECL|function|glDrawElements
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glDrawElements
argument_list|(
argument|GLenum mode
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid* indices
argument_list|)
block|{
operator|::
name|glDrawElements
argument_list|(
name|mode
argument_list|,
name|count
argument_list|,
name|type
argument_list|,
name|indices
argument_list|)
block|; }
DECL|function|glEnable
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glEnable
argument_list|(
argument|GLenum cap
argument_list|)
block|{
operator|::
name|glEnable
argument_list|(
name|cap
argument_list|)
block|; }
DECL|function|glEnableVertexAttribArray
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glEnableVertexAttribArray
argument_list|(
argument|GLuint index
argument_list|)
block|{
operator|::
name|glEnableVertexAttribArray
argument_list|(
name|index
argument_list|)
block|; }
DECL|function|glFinish
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glFinish
argument_list|(
argument|void
argument_list|)
block|{
operator|::
name|glFinish
argument_list|()
block|; }
DECL|function|glFlush
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glFlush
argument_list|(
argument|void
argument_list|)
block|{
operator|::
name|glFlush
argument_list|()
block|; }
DECL|function|glFramebufferRenderbuffer
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glFramebufferRenderbuffer
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLenum renderbuffertarget
argument_list|,
argument|GLuint renderbuffer
argument_list|)
block|{
operator|::
name|glFramebufferRenderbuffer
argument_list|(
name|target
argument_list|,
name|attachment
argument_list|,
name|renderbuffertarget
argument_list|,
name|renderbuffer
argument_list|)
block|; }
DECL|function|glFramebufferTexture2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glFramebufferTexture2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLenum textarget
argument_list|,
argument|GLuint texture
argument_list|,
argument|GLint level
argument_list|)
block|{
operator|::
name|glFramebufferTexture2D
argument_list|(
name|target
argument_list|,
name|attachment
argument_list|,
name|textarget
argument_list|,
name|texture
argument_list|,
name|level
argument_list|)
block|; }
DECL|function|glFrontFace
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glFrontFace
argument_list|(
argument|GLenum mode
argument_list|)
block|{
operator|::
name|glFrontFace
argument_list|(
name|mode
argument_list|)
block|; }
DECL|function|glGenBuffers
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGenBuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* buffers
argument_list|)
block|{
operator|::
name|glGenBuffers
argument_list|(
name|n
argument_list|,
name|buffers
argument_list|)
block|; }
DECL|function|glGenerateMipmap
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGenerateMipmap
argument_list|(
argument|GLenum target
argument_list|)
block|{
operator|::
name|glGenerateMipmap
argument_list|(
name|target
argument_list|)
block|; }
DECL|function|glGenFramebuffers
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGenFramebuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* framebuffers
argument_list|)
block|{
operator|::
name|glGenFramebuffers
argument_list|(
name|n
argument_list|,
name|framebuffers
argument_list|)
block|; }
DECL|function|glGenRenderbuffers
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGenRenderbuffers
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* renderbuffers
argument_list|)
block|{
operator|::
name|glGenRenderbuffers
argument_list|(
name|n
argument_list|,
name|renderbuffers
argument_list|)
block|; }
DECL|function|glGenTextures
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGenTextures
argument_list|(
argument|GLsizei n
argument_list|,
argument|GLuint* textures
argument_list|)
block|{
operator|::
name|glGenTextures
argument_list|(
name|n
argument_list|,
name|textures
argument_list|)
block|; }
DECL|function|glGetActiveAttrib
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetActiveAttrib
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLint* size
argument_list|,
argument|GLenum* type
argument_list|,
argument|GLchar* name
argument_list|)
block|{
operator|::
name|glGetActiveAttrib
argument_list|(
name|program
argument_list|,
name|index
argument_list|,
name|bufsize
argument_list|,
name|length
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|name
argument_list|)
block|; }
DECL|function|glGetActiveUniform
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetActiveUniform
argument_list|(
argument|GLuint program
argument_list|,
argument|GLuint index
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLint* size
argument_list|,
argument|GLenum* type
argument_list|,
argument|GLchar* name
argument_list|)
block|{
operator|::
name|glGetActiveUniform
argument_list|(
name|program
argument_list|,
name|index
argument_list|,
name|bufsize
argument_list|,
name|length
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|name
argument_list|)
block|; }
DECL|function|glGetAttachedShaders
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetAttachedShaders
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei maxcount
argument_list|,
argument|GLsizei* count
argument_list|,
argument|GLuint* shaders
argument_list|)
block|{
operator|::
name|glGetAttachedShaders
argument_list|(
name|program
argument_list|,
name|maxcount
argument_list|,
name|count
argument_list|,
name|shaders
argument_list|)
block|; }
DECL|function|glGetAttribLocation
specifier|inline
name|int
name|QOpenGLFunctions_ES2
operator|::
name|glGetAttribLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar* name
argument_list|)
block|{
return|return
operator|::
name|glGetAttribLocation
argument_list|(
name|program
argument_list|,
name|name
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glGetBooleanv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetBooleanv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLboolean* params
argument_list|)
block|{
operator|::
name|glGetBooleanv
argument_list|(
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetBufferParameteriv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetBufferParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetBufferParameteriv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetError
specifier|inline
name|GLenum
name|QOpenGLFunctions_ES2
operator|::
name|glGetError
argument_list|(
argument|void
argument_list|)
block|{
return|return
operator|::
name|glGetError
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glGetFloatv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetFloatv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|{
operator|::
name|glGetFloatv
argument_list|(
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetFramebufferAttachmentParameteriv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetFramebufferAttachmentParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum attachment
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetFramebufferAttachmentParameteriv
argument_list|(
name|target
argument_list|,
name|attachment
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetIntegerv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetIntegerv
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetIntegerv
argument_list|(
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetProgramiv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetProgramiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetProgramiv
argument_list|(
name|program
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetProgramInfoLog
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetProgramInfoLog
argument_list|(
argument|GLuint program
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* infolog
argument_list|)
block|{
operator|::
name|glGetProgramInfoLog
argument_list|(
name|program
argument_list|,
name|bufsize
argument_list|,
name|length
argument_list|,
name|infolog
argument_list|)
block|; }
DECL|function|glGetRenderbufferParameteriv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetRenderbufferParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetRenderbufferParameteriv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetShaderiv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetShaderiv
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetShaderiv
argument_list|(
name|shader
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetShaderInfoLog
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetShaderInfoLog
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* infolog
argument_list|)
block|{
operator|::
name|glGetShaderInfoLog
argument_list|(
name|shader
argument_list|,
name|bufsize
argument_list|,
name|length
argument_list|,
name|infolog
argument_list|)
block|; }
DECL|function|glGetShaderPrecisionFormat
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetShaderPrecisionFormat
argument_list|(
argument|GLenum shadertype
argument_list|,
argument|GLenum precisiontype
argument_list|,
argument|GLint* range
argument_list|,
argument|GLint* precision
argument_list|)
block|{
operator|::
name|glGetShaderPrecisionFormat
argument_list|(
name|shadertype
argument_list|,
name|precisiontype
argument_list|,
name|range
argument_list|,
name|precision
argument_list|)
block|; }
DECL|function|glGetShaderSource
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetShaderSource
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLsizei bufsize
argument_list|,
argument|GLsizei* length
argument_list|,
argument|GLchar* source
argument_list|)
block|{
operator|::
name|glGetShaderSource
argument_list|(
name|shader
argument_list|,
name|bufsize
argument_list|,
name|length
argument_list|,
name|source
argument_list|)
block|; }
DECL|function|glGetString
specifier|inline
specifier|const
name|GLubyte
operator|*
name|QOpenGLFunctions_ES2
operator|::
name|glGetString
argument_list|(
argument|GLenum name
argument_list|)
block|{
return|return
operator|::
name|glGetString
argument_list|(
name|name
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glGetTexParameterfv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetTexParameterfv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|{
operator|::
name|glGetTexParameterfv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetTexParameteriv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetTexParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetTexParameteriv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetUniformfv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetUniformfv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLfloat* params
argument_list|)
block|{
operator|::
name|glGetUniformfv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetUniformiv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetUniformiv
argument_list|(
argument|GLuint program
argument_list|,
argument|GLint location
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetUniformiv
argument_list|(
name|program
argument_list|,
name|location
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetUniformLocation
specifier|inline
name|int
name|QOpenGLFunctions_ES2
operator|::
name|glGetUniformLocation
argument_list|(
argument|GLuint program
argument_list|,
argument|const GLchar* name
argument_list|)
block|{
return|return
operator|::
name|glGetUniformLocation
argument_list|(
name|program
argument_list|,
name|name
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glGetVertexAttribfv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetVertexAttribfv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat* params
argument_list|)
block|{
operator|::
name|glGetVertexAttribfv
argument_list|(
name|index
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetVertexAttribiv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetVertexAttribiv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint* params
argument_list|)
block|{
operator|::
name|glGetVertexAttribiv
argument_list|(
name|index
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glGetVertexAttribPointerv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glGetVertexAttribPointerv
argument_list|(
argument|GLuint index
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLvoid** pointer
argument_list|)
block|{
operator|::
name|glGetVertexAttribPointerv
argument_list|(
name|index
argument_list|,
name|pname
argument_list|,
name|pointer
argument_list|)
block|; }
DECL|function|glHint
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glHint
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum mode
argument_list|)
block|{
operator|::
name|glHint
argument_list|(
name|target
argument_list|,
name|mode
argument_list|)
block|; }
DECL|function|glIsBuffer
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsBuffer
argument_list|(
argument|GLuint buffer
argument_list|)
block|{
return|return
operator|::
name|glIsBuffer
argument_list|(
name|buffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glIsEnabled
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsEnabled
argument_list|(
argument|GLenum cap
argument_list|)
block|{
return|return
operator|::
name|glIsEnabled
argument_list|(
name|cap
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glIsFramebuffer
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsFramebuffer
argument_list|(
argument|GLuint framebuffer
argument_list|)
block|{
return|return
operator|::
name|glIsFramebuffer
argument_list|(
name|framebuffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glIsProgram
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsProgram
argument_list|(
argument|GLuint program
argument_list|)
block|{
return|return
operator|::
name|glIsProgram
argument_list|(
name|program
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glIsRenderbuffer
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsRenderbuffer
argument_list|(
argument|GLuint renderbuffer
argument_list|)
block|{
return|return
operator|::
name|glIsRenderbuffer
argument_list|(
name|renderbuffer
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glIsShader
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsShader
argument_list|(
argument|GLuint shader
argument_list|)
block|{
return|return
operator|::
name|glIsShader
argument_list|(
name|shader
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glIsTexture
specifier|inline
name|GLboolean
name|QOpenGLFunctions_ES2
operator|::
name|glIsTexture
argument_list|(
argument|GLuint texture
argument_list|)
block|{
return|return
operator|::
name|glIsTexture
argument_list|(
name|texture
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|glLineWidth
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glLineWidth
argument_list|(
argument|GLfloat width
argument_list|)
block|{
operator|::
name|glLineWidth
argument_list|(
name|width
argument_list|)
block|; }
DECL|function|glLinkProgram
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glLinkProgram
argument_list|(
argument|GLuint program
argument_list|)
block|{
operator|::
name|glLinkProgram
argument_list|(
name|program
argument_list|)
block|; }
DECL|function|glPixelStorei
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glPixelStorei
argument_list|(
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|{
operator|::
name|glPixelStorei
argument_list|(
name|pname
argument_list|,
name|param
argument_list|)
block|; }
DECL|function|glPolygonOffset
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glPolygonOffset
argument_list|(
argument|GLfloat factor
argument_list|,
argument|GLfloat units
argument_list|)
block|{
operator|::
name|glPolygonOffset
argument_list|(
name|factor
argument_list|,
name|units
argument_list|)
block|; }
DECL|function|glReadPixels
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glReadPixels
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|GLvoid* pixels
argument_list|)
block|{
operator|::
name|glReadPixels
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|pixels
argument_list|)
block|; }
DECL|function|glReleaseShaderCompiler
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glReleaseShaderCompiler
argument_list|(
argument|void
argument_list|)
block|{
operator|::
name|glReleaseShaderCompiler
argument_list|()
block|; }
DECL|function|glRenderbufferStorage
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glRenderbufferStorage
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
operator|::
name|glRenderbufferStorage
argument_list|(
name|target
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|; }
DECL|function|glSampleCoverage
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glSampleCoverage
argument_list|(
argument|GLclampf value
argument_list|,
argument|GLboolean invert
argument_list|)
block|{
operator|::
name|glSampleCoverage
argument_list|(
name|value
argument_list|,
name|invert
argument_list|)
block|; }
DECL|function|glScissor
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glScissor
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
operator|::
name|glScissor
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|; }
DECL|function|glShaderBinary
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glShaderBinary
argument_list|(
argument|GLsizei n
argument_list|,
argument|const GLuint* shaders
argument_list|,
argument|GLenum binaryformat
argument_list|,
argument|const GLvoid* binary
argument_list|,
argument|GLsizei length
argument_list|)
block|{
operator|::
name|glShaderBinary
argument_list|(
name|n
argument_list|,
name|shaders
argument_list|,
name|binaryformat
argument_list|,
name|binary
argument_list|,
name|length
argument_list|)
block|; }
DECL|function|glShaderSource
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glShaderSource
argument_list|(
argument|GLuint shader
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLchar* *string
argument_list|,
argument|const GLint* length
argument_list|)
block|{
operator|::
name|glShaderSource
argument_list|(
name|shader
argument_list|,
name|count
argument_list|,
name|string
argument_list|,
name|length
argument_list|)
block|; }
DECL|function|glStencilFunc
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glStencilFunc
argument_list|(
argument|GLenum func
argument_list|,
argument|GLint ref
argument_list|,
argument|GLuint mask
argument_list|)
block|{
operator|::
name|glStencilFunc
argument_list|(
name|func
argument_list|,
name|ref
argument_list|,
name|mask
argument_list|)
block|; }
DECL|function|glStencilFuncSeparate
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glStencilFuncSeparate
argument_list|(
argument|GLenum face
argument_list|,
argument|GLenum func
argument_list|,
argument|GLint ref
argument_list|,
argument|GLuint mask
argument_list|)
block|{
operator|::
name|glStencilFuncSeparate
argument_list|(
name|face
argument_list|,
name|func
argument_list|,
name|ref
argument_list|,
name|mask
argument_list|)
block|; }
DECL|function|glStencilMask
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glStencilMask
argument_list|(
argument|GLuint mask
argument_list|)
block|{
operator|::
name|glStencilMask
argument_list|(
name|mask
argument_list|)
block|; }
DECL|function|glStencilMaskSeparate
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glStencilMaskSeparate
argument_list|(
argument|GLenum face
argument_list|,
argument|GLuint mask
argument_list|)
block|{
operator|::
name|glStencilMaskSeparate
argument_list|(
name|face
argument_list|,
name|mask
argument_list|)
block|; }
DECL|function|glStencilOp
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glStencilOp
argument_list|(
argument|GLenum fail
argument_list|,
argument|GLenum zfail
argument_list|,
argument|GLenum zpass
argument_list|)
block|{
operator|::
name|glStencilOp
argument_list|(
name|fail
argument_list|,
name|zfail
argument_list|,
name|zpass
argument_list|)
block|; }
DECL|function|glStencilOpSeparate
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glStencilOpSeparate
argument_list|(
argument|GLenum face
argument_list|,
argument|GLenum fail
argument_list|,
argument|GLenum zfail
argument_list|,
argument|GLenum zpass
argument_list|)
block|{
operator|::
name|glStencilOpSeparate
argument_list|(
name|face
argument_list|,
name|fail
argument_list|,
name|zfail
argument_list|,
name|zpass
argument_list|)
block|; }
DECL|function|glTexImage2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glTexImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint internalformat
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLint border
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid* pixels
argument_list|)
block|{
operator|::
name|glTexImage2D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|internalformat
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|border
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|pixels
argument_list|)
block|; }
DECL|function|glTexParameterf
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glTexParameterf
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLfloat param
argument_list|)
block|{
operator|::
name|glTexParameterf
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|; }
DECL|function|glTexParameterfv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glTexParameterfv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLfloat* params
argument_list|)
block|{
operator|::
name|glTexParameterfv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glTexParameteri
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glTexParameteri
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|GLint param
argument_list|)
block|{
operator|::
name|glTexParameteri
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|param
argument_list|)
block|; }
DECL|function|glTexParameteriv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glTexParameteriv
argument_list|(
argument|GLenum target
argument_list|,
argument|GLenum pname
argument_list|,
argument|const GLint* params
argument_list|)
block|{
operator|::
name|glTexParameteriv
argument_list|(
name|target
argument_list|,
name|pname
argument_list|,
name|params
argument_list|)
block|; }
DECL|function|glTexSubImage2D
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glTexSubImage2D
argument_list|(
argument|GLenum target
argument_list|,
argument|GLint level
argument_list|,
argument|GLint xoffset
argument_list|,
argument|GLint yoffset
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|,
argument|GLenum format
argument_list|,
argument|GLenum type
argument_list|,
argument|const GLvoid* pixels
argument_list|)
block|{
operator|::
name|glTexSubImage2D
argument_list|(
name|target
argument_list|,
name|level
argument_list|,
name|xoffset
argument_list|,
name|yoffset
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
name|format
argument_list|,
name|type
argument_list|,
name|pixels
argument_list|)
block|; }
DECL|function|glUniform1f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform1f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|)
block|{
operator|::
name|glUniform1f
argument_list|(
name|location
argument_list|,
name|x
argument_list|)
block|; }
DECL|function|glUniform1fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform1fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|{
operator|::
name|glUniform1fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform1i
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform1i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|)
block|{
operator|::
name|glUniform1i
argument_list|(
name|location
argument_list|,
name|x
argument_list|)
block|; }
DECL|function|glUniform1iv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform1iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|{
operator|::
name|glUniform1iv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform2f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform2f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|{
operator|::
name|glUniform2f
argument_list|(
name|location
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|glUniform2fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|{
operator|::
name|glUniform2fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform2i
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform2i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|)
block|{
operator|::
name|glUniform2i
argument_list|(
name|location
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|glUniform2iv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform2iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|{
operator|::
name|glUniform2iv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform3f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform3f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|{
operator|::
name|glUniform3f
argument_list|(
name|location
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|)
block|; }
DECL|function|glUniform3fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|{
operator|::
name|glUniform3fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform3i
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform3i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLint z
argument_list|)
block|{
operator|::
name|glUniform3i
argument_list|(
name|location
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|)
block|; }
DECL|function|glUniform3iv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform3iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|{
operator|::
name|glUniform3iv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform4f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform4f
argument_list|(
argument|GLint location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|,
argument|GLfloat w
argument_list|)
block|{
operator|::
name|glUniform4f
argument_list|(
name|location
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|w
argument_list|)
block|; }
DECL|function|glUniform4fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLfloat* v
argument_list|)
block|{
operator|::
name|glUniform4fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniform4i
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform4i
argument_list|(
argument|GLint location
argument_list|,
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLint z
argument_list|,
argument|GLint w
argument_list|)
block|{
operator|::
name|glUniform4i
argument_list|(
name|location
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|w
argument_list|)
block|; }
DECL|function|glUniform4iv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniform4iv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|const GLint* v
argument_list|)
block|{
operator|::
name|glUniform4iv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|v
argument_list|)
block|; }
DECL|function|glUniformMatrix2fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniformMatrix2fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat* value
argument_list|)
block|{
operator|::
name|glUniformMatrix2fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|; }
DECL|function|glUniformMatrix3fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniformMatrix3fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat* value
argument_list|)
block|{
operator|::
name|glUniformMatrix3fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|; }
DECL|function|glUniformMatrix4fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUniformMatrix4fv
argument_list|(
argument|GLint location
argument_list|,
argument|GLsizei count
argument_list|,
argument|GLboolean transpose
argument_list|,
argument|const GLfloat* value
argument_list|)
block|{
operator|::
name|glUniformMatrix4fv
argument_list|(
name|location
argument_list|,
name|count
argument_list|,
name|transpose
argument_list|,
name|value
argument_list|)
block|; }
DECL|function|glUseProgram
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glUseProgram
argument_list|(
argument|GLuint program
argument_list|)
block|{
operator|::
name|glUseProgram
argument_list|(
name|program
argument_list|)
block|; }
DECL|function|glValidateProgram
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glValidateProgram
argument_list|(
argument|GLuint program
argument_list|)
block|{
operator|::
name|glValidateProgram
argument_list|(
name|program
argument_list|)
block|; }
DECL|function|glVertexAttrib1f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib1f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|)
block|{
operator|::
name|glVertexAttrib1f
argument_list|(
name|indx
argument_list|,
name|x
argument_list|)
block|; }
DECL|function|glVertexAttrib1fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib1fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|{
operator|::
name|glVertexAttrib1fv
argument_list|(
name|indx
argument_list|,
name|values
argument_list|)
block|; }
DECL|function|glVertexAttrib2f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib2f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|{
operator|::
name|glVertexAttrib2f
argument_list|(
name|indx
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|glVertexAttrib2fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib2fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|{
operator|::
name|glVertexAttrib2fv
argument_list|(
name|indx
argument_list|,
name|values
argument_list|)
block|; }
DECL|function|glVertexAttrib3f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib3f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|{
operator|::
name|glVertexAttrib3f
argument_list|(
name|indx
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|)
block|; }
DECL|function|glVertexAttrib3fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib3fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|{
operator|::
name|glVertexAttrib3fv
argument_list|(
name|indx
argument_list|,
name|values
argument_list|)
block|; }
DECL|function|glVertexAttrib4f
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib4f
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|,
argument|GLfloat w
argument_list|)
block|{
operator|::
name|glVertexAttrib4f
argument_list|(
name|indx
argument_list|,
name|x
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|w
argument_list|)
block|; }
DECL|function|glVertexAttrib4fv
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttrib4fv
argument_list|(
argument|GLuint indx
argument_list|,
argument|const GLfloat* values
argument_list|)
block|{
operator|::
name|glVertexAttrib4fv
argument_list|(
name|indx
argument_list|,
name|values
argument_list|)
block|; }
DECL|function|glVertexAttribPointer
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glVertexAttribPointer
argument_list|(
argument|GLuint indx
argument_list|,
argument|GLint size
argument_list|,
argument|GLenum type
argument_list|,
argument|GLboolean normalized
argument_list|,
argument|GLsizei stride
argument_list|,
argument|const GLvoid* ptr
argument_list|)
block|{
operator|::
name|glVertexAttribPointer
argument_list|(
name|indx
argument_list|,
name|size
argument_list|,
name|type
argument_list|,
name|normalized
argument_list|,
name|stride
argument_list|,
name|ptr
argument_list|)
block|; }
DECL|function|glViewport
specifier|inline
name|void
name|QOpenGLFunctions_ES2
operator|::
name|glViewport
argument_list|(
argument|GLint x
argument_list|,
argument|GLint y
argument_list|,
argument|GLsizei width
argument_list|,
argument|GLsizei height
argument_list|)
block|{
operator|::
name|glViewport
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_OPENGL_ES_2
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
