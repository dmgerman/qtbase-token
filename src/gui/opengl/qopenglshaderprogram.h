begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLSHADERPROGRAM_H
end_ifndef
begin_define
DECL|macro|QOPENGLSHADERPROGRAM_H
define|#
directive|define
name|QOPENGLSHADERPROGRAM_H
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_OPENGL
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qopengl.h>
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
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLShaderProgram
name|class
name|QOpenGLShaderProgram
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QOpenGLShaderPrivate
name|class
name|QOpenGLShaderPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLShader
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
block|}
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|ShaderType
argument_list|,
argument|ShaderTypeBit
argument_list|)
name|explicit
name|QOpenGLShader
argument_list|(
argument|QOpenGLShader::ShaderType type
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QOpenGLShader
argument_list|()
block|;
name|QOpenGLShader
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
argument|QOpenGLContext *context =
literal|0
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QOpenGLShaderProgram
block|;
name|Q_DISABLE_COPY
argument_list|(
argument|QOpenGLShader
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLShader
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QOpenGLShader::ShaderType
argument_list|)
end_macro
begin_decl_stmt
DECL|variable|QOpenGLShaderProgramPrivate
name|class
name|QOpenGLShaderProgramPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLShaderProgram
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QOpenGLShaderProgram
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QOpenGLShaderProgram
argument_list|()
block|;
name|bool
name|addShader
argument_list|(
name|QOpenGLShader
operator|*
name|shader
argument_list|)
block|;
name|void
name|removeShader
argument_list|(
name|QOpenGLShader
operator|*
name|shader
argument_list|)
block|;
name|QList
operator|<
name|QOpenGLShader
operator|*
operator|>
name|shaders
argument_list|()
specifier|const
block|;
name|bool
name|addShaderFromSourceCode
argument_list|(
argument|QOpenGLShader::ShaderType type
argument_list|,
argument|const char *source
argument_list|)
block|;
name|bool
name|addShaderFromSourceCode
argument_list|(
argument|QOpenGLShader::ShaderType type
argument_list|,
argument|const QByteArray& source
argument_list|)
block|;
name|bool
name|addShaderFromSourceCode
argument_list|(
argument|QOpenGLShader::ShaderType type
argument_list|,
argument|const QString& source
argument_list|)
block|;
name|bool
name|addShaderFromSourceFile
argument_list|(
argument|QOpenGLShader::ShaderType type
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
name|QOpenGLContext
operator|*
name|context
operator|=
literal|0
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
argument|QOpenGLShaderProgram
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QOpenGLShaderProgram
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
begin_comment
comment|// QT_NO_OPENGL
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
