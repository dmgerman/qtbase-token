begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtextureglyphcache_gl_p.h"
end_include
begin_include
include|#
directive|include
file|"qpaintengineex_opengl2_p.h"
end_include
begin_include
include|#
directive|include
file|"qglfunctions.h"
end_include
begin_include
include|#
directive|include
file|"private/qglengineshadersource_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qgltextureglyphcache_serial_number
name|QBasicAtomicInt
name|qgltextureglyphcache_serial_number
init|=
name|Q_BASIC_ATOMIC_INITIALIZER
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QGLTextureGlyphCache
name|QGLTextureGlyphCache
operator|::
name|QGLTextureGlyphCache
parameter_list|(
name|QFontEngine
operator|::
name|GlyphFormat
name|format
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
member_init_list|:
name|QImageTextureGlyphCache
argument_list|(
name|format
argument_list|,
name|matrix
argument_list|)
member_init_list|,
name|m_textureResource
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pex
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_blitProgram
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_filterMode
argument_list|(
name|Nearest
argument_list|)
member_init_list|,
name|m_serialNumber
argument_list|(
name|qgltextureglyphcache_serial_number
operator|.
name|fetchAndAddRelaxed
argument_list|(
literal|1
argument_list|)
argument_list|)
block|{
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|" -> QGLTextureGlyphCache() %p for context %p."
argument_list|,
name|this
argument_list|,
name|QOpenGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|m_vertexCoordinateArray
index|[
literal|0
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|1
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|2
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|3
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|4
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|5
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|6
index|]
operator|=
operator|-
literal|1.0f
expr_stmt|;
name|m_vertexCoordinateArray
index|[
literal|7
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|0
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|1
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|2
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|3
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|4
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|5
index|]
operator|=
literal|1.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|6
index|]
operator|=
literal|0.0f
expr_stmt|;
name|m_textureCoordinateArray
index|[
literal|7
index|]
operator|=
literal|1.0f
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QGLTextureGlyphCache
name|QGLTextureGlyphCache
operator|::
name|~
name|QGLTextureGlyphCache
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|" -> ~QGLTextureGlyphCache() %p."
argument_list|,
name|this
argument_list|)
expr_stmt|;
endif|#
directive|endif
operator|delete
name|m_blitProgram
expr_stmt|;
if|if
condition|(
name|m_textureResource
condition|)
name|m_textureResource
operator|->
name|free
argument_list|()
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|createTextureData
name|void
name|QGLTextureGlyphCache
operator|::
name|createTextureData
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLTextureGlyphCache::createTextureData: Called with no context"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
comment|// create in QImageTextureGlyphCache baseclass is meant to be called
comment|// only to create the initial image and does not preserve the content,
comment|// so we don't call when this function is called from resize.
if|if
condition|(
operator|(
operator|!
name|QGLFramebufferObject
operator|::
name|hasOpenGLFramebufferObjects
argument_list|()
operator|||
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenFBOReadBack
operator|)
operator|&&
name|image
argument_list|()
operator|.
name|isNull
argument_list|()
condition|)
name|QImageTextureGlyphCache
operator|::
name|createTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
comment|// Make the lower glyph texture size 16 x 16.
if|if
condition|(
name|width
operator|<
literal|16
condition|)
name|width
operator|=
literal|16
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|16
condition|)
name|height
operator|=
literal|16
expr_stmt|;
if|if
condition|(
name|m_textureResource
operator|&&
operator|!
name|m_textureResource
operator|->
name|m_texture
condition|)
block|{
operator|delete
name|m_textureResource
expr_stmt|;
name|m_textureResource
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_textureResource
condition|)
name|m_textureResource
operator|=
operator|new
name|QGLGlyphTexture
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
name|m_textureResource
operator|->
name|m_width
operator|=
name|width
expr_stmt|;
name|m_textureResource
operator|->
name|m_height
operator|=
name|height
expr_stmt|;
if|if
condition|(
name|m_format
operator|==
name|QFontEngine
operator|::
name|Format_A32
condition|)
block|{
name|QVarLengthArray
argument_list|<
name|uchar
argument_list|>
name|data
argument_list|(
name|width
operator|*
name|height
operator|*
literal|4
argument_list|)
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
name|data
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|data
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
operator|&
name|data
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QVarLengthArray
argument_list|<
name|uchar
argument_list|>
name|data
argument_list|(
name|width
operator|*
name|height
argument_list|)
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
name|data
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|data
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_ALPHA
argument_list|,
name|width
argument_list|,
name|height
argument_list|,
literal|0
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
operator|&
name|data
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|m_filterMode
operator|=
name|Nearest
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeTextureData
name|void
name|QGLTextureGlyphCache
operator|::
name|resizeTextureData
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
block|{
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLTextureGlyphCache::resizeTextureData: Called with no context"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
name|int
name|oldWidth
init|=
name|m_textureResource
operator|->
name|m_width
decl_stmt|;
name|int
name|oldHeight
init|=
name|m_textureResource
operator|->
name|m_height
decl_stmt|;
comment|// Make the lower glyph texture size 16 x 16.
if|if
condition|(
name|width
operator|<
literal|16
condition|)
name|width
operator|=
literal|16
expr_stmt|;
if|if
condition|(
name|height
operator|<
literal|16
condition|)
name|height
operator|=
literal|16
expr_stmt|;
name|GLuint
name|oldTexture
init|=
name|m_textureResource
operator|->
name|m_texture
decl_stmt|;
name|createTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|QGLFramebufferObject
operator|::
name|hasOpenGLFramebufferObjects
argument_list|()
operator|||
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenFBOReadBack
condition|)
block|{
name|QImageTextureGlyphCache
operator|::
name|resizeTextureData
argument_list|(
name|width
argument_list|,
name|height
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|image
argument_list|()
operator|.
name|depth
argument_list|()
operator|==
literal|8
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|width
argument_list|,
name|oldHeight
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|image
argument_list|()
operator|.
name|constBits
argument_list|()
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|oldTexture
argument_list|)
expr_stmt|;
return|return;
block|}
comment|// ### the QTextureGlyphCache API needs to be reworked to allow
comment|// ### resizeTextureData to fail
name|ctx
operator|->
name|d_ptr
operator|->
name|refreshCurrentFbo
argument_list|()
expr_stmt|;
name|funcs
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|m_textureResource
operator|->
name|m_fbo
argument_list|)
expr_stmt|;
name|GLuint
name|tmp_texture
decl_stmt|;
name|funcs
operator|->
name|glGenTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|tmp_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|tmp_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|oldWidth
argument_list|,
name|oldHeight
argument_list|,
literal|0
argument_list|,
name|GL_RGBA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MIN_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_MAG_FILTER
argument_list|,
name|GL_NEAREST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_S
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glTexParameteri
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|GL_TEXTURE_WRAP_T
argument_list|,
name|GL_CLAMP_TO_EDGE
argument_list|)
expr_stmt|;
name|m_filterMode
operator|=
name|Nearest
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glFramebufferTexture2D
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_TEXTURE_2D
argument_list|,
name|tmp_texture
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glActiveTexture
argument_list|(
name|GL_TEXTURE0
operator|+
name|QT_IMAGE_TEXTURE_UNIT
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|oldTexture
argument_list|)
expr_stmt|;
if|if
condition|(
name|pex
operator|!=
literal|0
condition|)
name|pex
operator|->
name|transferMode
argument_list|(
name|BrushDrawingMode
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_STENCIL_TEST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_DEPTH_TEST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_SCISSOR_TEST
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDisable
argument_list|(
name|GL_BLEND
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|oldWidth
argument_list|,
name|oldHeight
argument_list|)
expr_stmt|;
name|QGLShaderProgram
modifier|*
name|blitProgram
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|pex
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|m_blitProgram
operator|==
literal|0
condition|)
block|{
name|m_blitProgram
operator|=
operator|new
name|QGLShaderProgram
argument_list|(
name|ctx
argument_list|)
expr_stmt|;
block|{
name|QString
name|source
decl_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|qglslMainWithTexCoordsVertexShader
argument_list|)
argument_list|)
expr_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|qglslUntransformedPositionVertexShader
argument_list|)
argument_list|)
expr_stmt|;
name|QGLShader
modifier|*
name|vertexShader
init|=
operator|new
name|QGLShader
argument_list|(
name|QGLShader
operator|::
name|Vertex
argument_list|,
name|m_blitProgram
argument_list|)
decl_stmt|;
name|vertexShader
operator|->
name|compileSourceCode
argument_list|(
name|source
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|addShader
argument_list|(
name|vertexShader
argument_list|)
expr_stmt|;
block|}
block|{
name|QString
name|source
decl_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|qglslMainFragmentShader
argument_list|)
argument_list|)
expr_stmt|;
name|source
operator|.
name|append
argument_list|(
name|QLatin1String
argument_list|(
name|qglslImageSrcFragmentShader
argument_list|)
argument_list|)
expr_stmt|;
name|QGLShader
modifier|*
name|fragmentShader
init|=
operator|new
name|QGLShader
argument_list|(
name|QGLShader
operator|::
name|Fragment
argument_list|,
name|m_blitProgram
argument_list|)
decl_stmt|;
name|fragmentShader
operator|->
name|compileSourceCode
argument_list|(
name|source
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|addShader
argument_list|(
name|fragmentShader
argument_list|)
expr_stmt|;
block|}
name|m_blitProgram
operator|->
name|bindAttributeLocation
argument_list|(
literal|"vertexCoordsArray"
argument_list|,
name|QT_VERTEX_COORDS_ATTR
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|bindAttributeLocation
argument_list|(
literal|"textureCoordArray"
argument_list|,
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|link
argument_list|()
expr_stmt|;
block|}
name|funcs
operator|->
name|glVertexAttribPointer
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|m_vertexCoordinateArray
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glVertexAttribPointer
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|,
literal|2
argument_list|,
name|GL_FLOAT
argument_list|,
name|GL_FALSE
argument_list|,
literal|0
argument_list|,
name|m_textureCoordinateArray
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|bind
argument_list|()
expr_stmt|;
name|m_blitProgram
operator|->
name|enableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|)
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|enableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|)
argument_list|)
expr_stmt|;
name|m_blitProgram
operator|->
name|disableAttributeArray
argument_list|(
name|int
argument_list|(
name|QT_OPACITY_ATTR
argument_list|)
argument_list|)
expr_stmt|;
name|blitProgram
operator|=
name|m_blitProgram
expr_stmt|;
block|}
else|else
block|{
name|pex
operator|->
name|setVertexAttributePointer
argument_list|(
name|QT_VERTEX_COORDS_ATTR
argument_list|,
name|m_vertexCoordinateArray
argument_list|)
expr_stmt|;
name|pex
operator|->
name|setVertexAttributePointer
argument_list|(
name|QT_TEXTURE_COORDS_ATTR
argument_list|,
name|m_textureCoordinateArray
argument_list|)
expr_stmt|;
name|pex
operator|->
name|shaderManager
operator|->
name|useBlitProgram
argument_list|()
expr_stmt|;
name|blitProgram
operator|=
name|pex
operator|->
name|shaderManager
operator|->
name|blitProgram
argument_list|()
expr_stmt|;
block|}
name|blitProgram
operator|->
name|setUniformValue
argument_list|(
literal|"imageTexture"
argument_list|,
name|QT_IMAGE_TEXTURE_UNIT
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDrawArrays
argument_list|(
name|GL_TRIANGLE_FAN
argument_list|,
literal|0
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glCopyTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|oldWidth
argument_list|,
name|oldHeight
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glFramebufferRenderbuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|GL_COLOR_ATTACHMENT0
argument_list|,
name|GL_RENDERBUFFER
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|tmp_texture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|oldTexture
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindFramebuffer
argument_list|(
name|GL_FRAMEBUFFER
argument_list|,
name|ctx
operator|->
name|d_ptr
operator|->
name|current_fbo
argument_list|)
expr_stmt|;
if|if
condition|(
name|pex
operator|!=
literal|0
condition|)
block|{
name|funcs
operator|->
name|glViewport
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|pex
operator|->
name|width
argument_list|,
name|pex
operator|->
name|height
argument_list|)
expr_stmt|;
name|pex
operator|->
name|updateClipScissorTest
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|fillTexture
name|void
name|QGLTextureGlyphCache
operator|::
name|fillTexture
parameter_list|(
specifier|const
name|Coord
modifier|&
name|c
parameter_list|,
name|glyph_t
name|glyph
parameter_list|,
name|QFixed
name|subPixelPosition
parameter_list|)
block|{
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGLTextureGlyphCache::fillTexture: Called with no context"
argument_list|)
expr_stmt|;
return|return;
block|}
name|QOpenGLFunctions
modifier|*
name|funcs
init|=
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|functions
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|QGLFramebufferObject
operator|::
name|hasOpenGLFramebufferObjects
argument_list|()
operator|||
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenFBOReadBack
condition|)
block|{
name|QImageTextureGlyphCache
operator|::
name|fillTexture
argument_list|(
name|c
argument_list|,
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
expr_stmt|;
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
specifier|const
name|QImage
modifier|&
name|texture
init|=
name|image
argument_list|()
decl_stmt|;
specifier|const
name|uchar
modifier|*
name|bits
init|=
name|texture
operator|.
name|constBits
argument_list|()
decl_stmt|;
name|bits
operator|+=
name|c
operator|.
name|y
operator|*
name|texture
operator|.
name|bytesPerLine
argument_list|()
operator|+
name|c
operator|.
name|x
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
name|c
operator|.
name|h
condition|;
operator|++
name|i
control|)
block|{
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
operator|+
name|i
argument_list|,
name|c
operator|.
name|w
argument_list|,
literal|1
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|bits
argument_list|)
expr_stmt|;
name|bits
operator|+=
name|texture
operator|.
name|bytesPerLine
argument_list|()
expr_stmt|;
block|}
return|return;
block|}
name|QImage
name|mask
init|=
name|textureMapForGlyph
argument_list|(
name|glyph
argument_list|,
name|subPixelPosition
argument_list|)
decl_stmt|;
specifier|const
name|int
name|maskWidth
init|=
name|mask
operator|.
name|width
argument_list|()
decl_stmt|;
specifier|const
name|int
name|maskHeight
init|=
name|mask
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|mask
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_Mono
condition|)
block|{
name|mask
operator|=
name|mask
operator|.
name|convertToFormat
argument_list|(
name|QImage
operator|::
name|Format_Indexed8
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|maskHeight
condition|;
operator|++
name|y
control|)
block|{
name|uchar
modifier|*
name|src
init|=
operator|(
name|uchar
operator|*
operator|)
name|mask
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|maskWidth
condition|;
operator|++
name|x
control|)
name|src
index|[
name|x
index|]
operator|=
operator|-
name|src
index|[
name|x
index|]
expr_stmt|;
comment|// convert 0 and 1 into 0 and 255
block|}
block|}
elseif|else
if|if
condition|(
name|mask
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
comment|// Make the alpha component equal to the average of the RGB values.
comment|// This is needed when drawing sub-pixel antialiased text on translucent targets.
for|for
control|(
name|int
name|y
init|=
literal|0
init|;
name|y
operator|<
name|maskHeight
condition|;
operator|++
name|y
control|)
block|{
name|quint32
modifier|*
name|src
init|=
operator|(
name|quint32
operator|*
operator|)
name|mask
operator|.
name|scanLine
argument_list|(
name|y
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|x
init|=
literal|0
init|;
name|x
operator|<
name|maskWidth
condition|;
operator|++
name|x
control|)
block|{
name|uchar
name|r
init|=
name|src
index|[
name|x
index|]
operator|>>
literal|16
decl_stmt|;
name|uchar
name|g
init|=
name|src
index|[
name|x
index|]
operator|>>
literal|8
decl_stmt|;
name|uchar
name|b
init|=
name|src
index|[
name|x
index|]
decl_stmt|;
name|quint32
name|avg
init|=
operator|(
name|quint32
argument_list|(
name|r
argument_list|)
operator|+
name|quint32
argument_list|(
name|g
argument_list|)
operator|+
name|quint32
argument_list|(
name|b
argument_list|)
operator|+
literal|1
operator|)
operator|/
literal|3
decl_stmt|;
comment|// "+1" for rounding.
if|if
condition|(
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
block|{
comment|// swizzle the bits to accommodate for the GL_RGBA upload.
name|src
index|[
name|x
index|]
operator|=
operator|(
name|avg
operator|<<
literal|24
operator|)
operator||
operator|(
name|quint32
argument_list|(
name|r
argument_list|)
operator|<<
literal|0
operator|)
operator||
operator|(
name|quint32
argument_list|(
name|g
argument_list|)
operator|<<
literal|8
operator|)
operator||
operator|(
name|quint32
argument_list|(
name|b
argument_list|)
operator|<<
literal|16
operator|)
expr_stmt|;
block|}
else|else
block|{
name|src
index|[
name|x
index|]
operator|=
operator|(
name|src
index|[
name|x
index|]
operator|&
literal|0x00ffffff
operator|)
operator||
operator|(
name|avg
operator|<<
literal|24
operator|)
expr_stmt|;
block|}
block|}
block|}
block|}
name|funcs
operator|->
name|glBindTexture
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
name|m_textureResource
operator|->
name|m_texture
argument_list|)
expr_stmt|;
if|if
condition|(
name|mask
operator|.
name|format
argument_list|()
operator|==
name|QImage
operator|::
name|Format_RGB32
condition|)
block|{
name|GLenum
name|format
init|=
name|GL_RGBA
decl_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_OPENGL_ES_2
argument_list|)
if|if
condition|(
operator|!
name|ctx
operator|->
name|contextHandle
argument_list|()
operator|->
name|isOpenGLES
argument_list|()
condition|)
name|format
operator|=
name|GL_BGRA
expr_stmt|;
endif|#
directive|endif
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|maskWidth
argument_list|,
name|maskHeight
argument_list|,
name|format
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|mask
operator|.
name|bits
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// glTexSubImage2D() might cause some garbage to appear in the texture if the mask width is
comment|// not a multiple of four bytes. The bug appeared on a computer with 32-bit Windows Vista
comment|// and nVidia GeForce 8500GT. GL_UNPACK_ALIGNMENT is set to four bytes, 'mask' has a
comment|// multiple of four bytes per line, and most of the glyph shows up correctly in the
comment|// texture, which makes me think that this is a driver bug.
comment|// One workaround is to make sure the mask width is a multiple of four bytes, for instance
comment|// by converting it to a format with four bytes per pixel. Another is to copy one line at a
comment|// time.
if|if
condition|(
operator|!
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenAlphaTexSubImage_init
condition|)
block|{
comment|// don't know which driver versions exhibit this bug, so be conservative for now
specifier|const
name|QByteArray
name|vendorString
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|char
operator|*
argument_list|>
argument_list|(
name|funcs
operator|->
name|glGetString
argument_list|(
name|GL_VENDOR
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenAlphaTexSubImage
operator|=
name|vendorString
operator|.
name|indexOf
argument_list|(
literal|"NVIDIA"
argument_list|)
operator|>=
literal|0
expr_stmt|;
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenAlphaTexSubImage_init
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenAlphaTexSubImage
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|maskHeight
condition|;
operator|++
name|i
control|)
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
operator|+
name|i
argument_list|,
name|maskWidth
argument_list|,
literal|1
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|mask
operator|.
name|scanLine
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|funcs
operator|->
name|glTexSubImage2D
argument_list|(
name|GL_TEXTURE_2D
argument_list|,
literal|0
argument_list|,
name|c
operator|.
name|x
argument_list|,
name|c
operator|.
name|y
argument_list|,
name|maskWidth
argument_list|,
name|maskHeight
argument_list|,
name|GL_ALPHA
argument_list|,
name|GL_UNSIGNED_BYTE
argument_list|,
name|mask
operator|.
name|bits
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|glyphPadding
name|int
name|QGLTextureGlyphCache
operator|::
name|glyphPadding
parameter_list|()
specifier|const
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|maxTextureWidth
name|int
name|QGLTextureGlyphCache
operator|::
name|maxTextureWidth
parameter_list|()
specifier|const
block|{
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
return|return
name|QImageTextureGlyphCache
operator|::
name|maxTextureWidth
argument_list|()
return|;
else|else
return|return
name|ctx
operator|->
name|d_ptr
operator|->
name|maxTextureSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|maxTextureHeight
name|int
name|QGLTextureGlyphCache
operator|::
name|maxTextureHeight
parameter_list|()
specifier|const
block|{
name|QGLContext
modifier|*
name|ctx
init|=
cast|const_cast
argument_list|<
name|QGLContext
operator|*
argument_list|>
argument_list|(
name|QGLContext
operator|::
name|currentContext
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|ctx
operator|==
literal|0
condition|)
return|return
name|QImageTextureGlyphCache
operator|::
name|maxTextureHeight
argument_list|()
return|;
if|if
condition|(
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenTexSubImage
condition|)
return|return
name|qMin
argument_list|(
literal|1024
argument_list|,
name|ctx
operator|->
name|d_ptr
operator|->
name|maxTextureSize
argument_list|()
argument_list|)
return|;
else|else
return|return
name|ctx
operator|->
name|d_ptr
operator|->
name|maxTextureSize
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|clear
name|void
name|QGLTextureGlyphCache
operator|::
name|clear
parameter_list|()
block|{
name|m_textureResource
operator|->
name|free
argument_list|()
expr_stmt|;
name|m_textureResource
operator|=
literal|0
expr_stmt|;
name|m_w
operator|=
literal|0
expr_stmt|;
name|m_h
operator|=
literal|0
expr_stmt|;
name|m_cx
operator|=
literal|0
expr_stmt|;
name|m_cy
operator|=
literal|0
expr_stmt|;
name|m_currentRowHeight
operator|=
literal|0
expr_stmt|;
name|coords
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
