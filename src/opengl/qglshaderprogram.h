begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLSHADERPROGRAM_H
end_ifndef
begin_define
DECL|macro|QGLSHADERPROGRAM_H
define|#
directive|define
name|QGLSHADERPROGRAM_H
end_define
begin_include
include|#
directive|include
file|<QtOpenGL/qgl.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector2d.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector3d.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qvector4d.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qmatrix4x4.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLShaderProgram
name|class
name|QGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLShaderPrivate
name|class
name|QGLShaderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLShader
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|ShaderTypeBit
block|{
name|Vertex
operator|=
literal|0x0001
block|,
name|Fragment
operator|=
literal|0x0002
block|,
name|Geometry
operator|=
literal|0x0004
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ShaderType
argument_list|,
argument|ShaderTypeBit
argument_list|)
name|explicit
name|QGLShader
argument_list|(
argument|QGLShader::ShaderType type
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|)
block|;
name|QGLShader
argument_list|(
argument|QGLShader::ShaderType type
argument_list|,
argument|const QGLContext *context
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QGLShader
argument_list|()
block|;
name|QGLShader
operator|::
name|ShaderType
name|shaderType
argument_list|()
specifier|const
block|;
name|bool
name|compileSourceCode
argument_list|(
specifier|const
name|char
operator|*
name|source
argument_list|)
block|;
name|bool
name|compileSourceCode
argument_list|(
specifier|const
name|QByteArray
operator|&
name|source
argument_list|)
block|;
name|bool
name|compileSourceCode
argument_list|(
specifier|const
name|QString
operator|&
name|source
argument_list|)
block|;
name|bool
name|compileSourceFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
block|;
name|QByteArray
name|sourceCode
argument_list|()
specifier|const
block|;
name|bool
name|isCompiled
argument_list|()
specifier|const
block|;
name|QString
name|log
argument_list|()
specifier|const
block|;
name|GLuint
name|shaderId
argument_list|()
specifier|const
block|;
specifier|static
name|bool
name|hasOpenGLShaders
argument_list|(
argument|ShaderType type
argument_list|,
argument|const QGLContext *context = Q_NULLPTR
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QGLShaderProgram
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QGLShader
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLShader
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGLShader::ShaderType
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QGLShaderProgramPrivate
name|class
name|QGLShaderProgramPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_OPENGL_EXPORT
name|QGLShaderProgram
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QGLShaderProgram
argument_list|(
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|explicit
name|QGLShaderProgram
argument_list|(
specifier|const
name|QGLContext
operator|*
name|context
argument_list|,
name|QObject
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|virtual
operator|~
name|QGLShaderProgram
argument_list|()
block|;
name|bool
name|addShader
argument_list|(
name|QGLShader
operator|*
name|shader
argument_list|)
block|;
name|void
name|removeShader
argument_list|(
name|QGLShader
operator|*
name|shader
argument_list|)
block|;
name|QList
operator|<
name|QGLShader
operator|*
operator|>
name|shaders
argument_list|()
specifier|const
block|;
name|bool
name|addShaderFromSourceCode
argument_list|(
argument|QGLShader::ShaderType type
argument_list|,
argument|const char *source
argument_list|)
block|;
name|bool
name|addShaderFromSourceCode
argument_list|(
argument|QGLShader::ShaderType type
argument_list|,
argument|const QByteArray& source
argument_list|)
block|;
name|bool
name|addShaderFromSourceCode
argument_list|(
argument|QGLShader::ShaderType type
argument_list|,
argument|const QString& source
argument_list|)
block|;
name|bool
name|addShaderFromSourceFile
argument_list|(
argument|QGLShader::ShaderType type
argument_list|,
argument|const QString& fileName
argument_list|)
block|;
name|void
name|removeAllShaders
argument_list|()
block|;
name|virtual
name|bool
name|link
argument_list|()
block|;
name|bool
name|isLinked
argument_list|()
specifier|const
block|;
name|QString
name|log
argument_list|()
specifier|const
block|;
name|bool
name|bind
argument_list|()
block|;
name|void
name|release
argument_list|()
block|;
name|GLuint
name|programId
argument_list|()
specifier|const
block|;
name|int
name|maxGeometryOutputVertices
argument_list|()
specifier|const
block|;
name|void
name|setGeometryOutputVertexCount
argument_list|(
argument|int count
argument_list|)
block|;
name|int
name|geometryOutputVertexCount
argument_list|()
specifier|const
block|;
name|void
name|setGeometryInputType
argument_list|(
argument|GLenum inputType
argument_list|)
block|;
name|GLenum
name|geometryInputType
argument_list|()
specifier|const
block|;
name|void
name|setGeometryOutputType
argument_list|(
argument|GLenum outputType
argument_list|)
block|;
name|GLenum
name|geometryOutputType
argument_list|()
specifier|const
block|;
name|void
name|bindAttributeLocation
argument_list|(
argument|const char *name
argument_list|,
argument|int location
argument_list|)
block|;
name|void
name|bindAttributeLocation
argument_list|(
argument|const QByteArray& name
argument_list|,
argument|int location
argument_list|)
block|;
name|void
name|bindAttributeLocation
argument_list|(
argument|const QString& name
argument_list|,
argument|int location
argument_list|)
block|;
name|int
name|attributeLocation
argument_list|(
argument|const char *name
argument_list|)
specifier|const
block|;
name|int
name|attributeLocation
argument_list|(
argument|const QByteArray& name
argument_list|)
specifier|const
block|;
name|int
name|attributeLocation
argument_list|(
argument|const QString& name
argument_list|)
specifier|const
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|GLfloat value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
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
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|const QVector2D& value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|const QVector3D& value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|const QVector4D& value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|const QColor& value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|int location
argument_list|,
argument|const GLfloat *values
argument_list|,
argument|int columns
argument_list|,
argument|int rows
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLfloat value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|const char *name
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
name|setAttributeValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVector2D
operator|&
name|value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVector3D
operator|&
name|value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVector4D
operator|&
name|value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QColor
operator|&
name|value
argument_list|)
block|;
name|void
name|setAttributeValue
argument_list|(
argument|const char *name
argument_list|,
argument|const GLfloat *values
argument_list|,
argument|int columns
argument_list|,
argument|int rows
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|int location
argument_list|,
argument|const GLfloat *values
argument_list|,
argument|int tupleSize
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|int location
argument_list|,
argument|const QVector2D *values
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|int location
argument_list|,
argument|const QVector3D *values
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|int location
argument_list|,
argument|const QVector4D *values
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|int location
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *values
argument_list|,
argument|int tupleSize
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|const char *name
argument_list|,
argument|const GLfloat *values
argument_list|,
argument|int tupleSize
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QVector2D *values
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QVector3D *values
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QVector4D *values
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeArray
argument_list|(
argument|const char *name
argument_list|,
argument|GLenum type
argument_list|,
argument|const void *values
argument_list|,
argument|int tupleSize
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeBuffer
argument_list|(
argument|int location
argument_list|,
argument|GLenum type
argument_list|,
argument|int offset
argument_list|,
argument|int tupleSize
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|setAttributeBuffer
argument_list|(
argument|const char *name
argument_list|,
argument|GLenum type
argument_list|,
argument|int offset
argument_list|,
argument|int tupleSize
argument_list|,
argument|int stride =
literal|0
argument_list|)
block|;
name|void
name|enableAttributeArray
argument_list|(
argument|int location
argument_list|)
block|;
name|void
name|enableAttributeArray
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|void
name|disableAttributeArray
argument_list|(
argument|int location
argument_list|)
block|;
name|void
name|disableAttributeArray
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|int
name|uniformLocation
argument_list|(
argument|const char *name
argument_list|)
specifier|const
block|;
name|int
name|uniformLocation
argument_list|(
argument|const QByteArray& name
argument_list|)
specifier|const
block|;
name|int
name|uniformLocation
argument_list|(
argument|const QString& name
argument_list|)
specifier|const
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|GLfloat value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|GLint value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|GLuint value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
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
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QVector2D& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QVector3D& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QVector4D& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QColor& color
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QPoint& point
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QPointF& point
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QSize& size
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QSizeF& size
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix2x2& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix2x3& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix2x4& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix3x2& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix3x3& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix3x4& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix4x2& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix4x3& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix4x4& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const GLfloat value[
literal|2
argument|][
literal|2
argument|]
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const GLfloat value[
literal|3
argument|][
literal|3
argument|]
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const GLfloat value[
literal|4
argument|][
literal|4
argument|]
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|int location
argument_list|,
argument|const QTransform& value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLfloat value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLint value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLuint value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|GLfloat x
argument_list|,
argument|GLfloat y
argument_list|,
argument|GLfloat z
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
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
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVector2D
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVector3D
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QVector4D
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QColor
operator|&
name|color
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QPointF
operator|&
name|point
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QSize
operator|&
name|size
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QSizeF
operator|&
name|size
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix2x2
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix2x3
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix2x4
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix3x2
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix3x3
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix3x4
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix4x2
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix4x3
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QMatrix4x4
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|const GLfloat value[
literal|2
argument|][
literal|2
argument|]
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|const GLfloat value[
literal|3
argument|][
literal|3
argument|]
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
argument|const char *name
argument_list|,
argument|const GLfloat value[
literal|4
argument|][
literal|4
argument|]
argument_list|)
block|;
name|void
name|setUniformValue
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|QTransform
operator|&
name|value
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const GLfloat *values
argument_list|,
argument|int count
argument_list|,
argument|int tupleSize
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const GLint *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const GLuint *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QVector2D *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QVector3D *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QVector4D *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix2x2 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix2x3 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix2x4 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix3x2 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix3x3 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix3x4 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix4x2 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix4x3 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|int location
argument_list|,
argument|const QMatrix4x4 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const GLfloat *values
argument_list|,
argument|int count
argument_list|,
argument|int tupleSize
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const GLint *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const GLuint *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QVector2D *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QVector3D *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QVector4D *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix2x2 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix2x3 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix2x4 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix3x2 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix3x3 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix3x4 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix4x2 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix4x3 *values
argument_list|,
argument|int count
argument_list|)
block|;
name|void
name|setUniformValueArray
argument_list|(
argument|const char *name
argument_list|,
argument|const QMatrix4x4 *values
argument_list|,
argument|int count
argument_list|)
block|;
specifier|static
name|bool
name|hasOpenGLShaderPrograms
argument_list|(
specifier|const
name|QGLContext
operator|*
name|context
operator|=
name|Q_NULLPTR
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|shaderDestroyed
argument_list|()
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGLShaderProgram
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLShaderProgram
argument_list|)
name|bool
name|init
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
