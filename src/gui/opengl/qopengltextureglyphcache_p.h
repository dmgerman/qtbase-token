begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLTEXTUREGLYPHCACHE_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLTEXTUREGLYPHCACHE_P_H
define|#
directive|define
name|QOPENGLTEXTUREGLYPHCACHE_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<private/qtextureglyphcache_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<qopenglshaderprogram.h>
end_include
begin_include
include|#
directive|include
file|<qopenglfunctions.h>
end_include
begin_include
include|#
directive|include
file|<qopenglbuffer.h>
end_include
begin_include
include|#
directive|include
file|<qopenglvertexarrayobject.h>
end_include
begin_comment
comment|// #define QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGL2PaintEngineExPrivate
name|class
name|QOpenGL2PaintEngineExPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenGLGlyphTexture
range|:
name|public
name|QOpenGLSharedResource
block|{
name|public
operator|:
name|explicit
name|QOpenGLGlyphTexture
argument_list|(
name|QOpenGLContext
operator|*
name|ctx
argument_list|)
operator|:
name|QOpenGLSharedResource
argument_list|(
name|ctx
operator|->
name|shareGroup
argument_list|()
argument_list|)
block|,
name|m_width
argument_list|(
literal|0
argument_list|)
block|,
name|m_height
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
operator|!
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_brokenFBOReadBack
condition|)
name|QOpenGLFunctions
argument_list|(
name|ctx
argument_list|)
operator|.
name|glGenFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_fbo
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|" -> QOpenGLGlyphTexture() %p for context %p."
argument_list|,
name|this
argument_list|,
name|ctx
argument_list|)
block|;
endif|#
directive|endif
block|}
name|void
name|freeResource
argument_list|(
argument|QOpenGLContext *context
argument_list|)
name|Q_DECL_OVERRIDE
block|{
name|QOpenGLContext
operator|*
name|ctx
operator|=
name|context
block|;
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|"~QOpenGLGlyphTexture() %p for context %p."
argument_list|,
name|this
argument_list|,
name|ctx
argument_list|)
block|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|ctx
operator|->
name|d_func
argument_list|()
operator|->
name|workaround_brokenFBOReadBack
condition|)
name|ctx
operator|->
name|functions
argument_list|()
operator|->
name|glDeleteFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_fbo
argument_list|)
expr_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|m_width
operator|||
name|m_height
condition|)
name|ctx
operator|->
name|functions
argument_list|()
operator|->
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_texture
argument_list|)
expr_stmt|;
end_if
begin_macro
unit|}      void
name|invalidateResource
argument_list|()
end_macro
begin_macro
name|Q_DECL_OVERRIDE
end_macro
begin_block
block|{
name|m_texture
operator|=
literal|0
expr_stmt|;
name|m_fbo
operator|=
literal|0
expr_stmt|;
name|m_width
operator|=
literal|0
expr_stmt|;
name|m_height
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_decl_stmt
name|GLuint
name|m_texture
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|GLuint
name|m_fbo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_width
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_height
decl_stmt|;
end_decl_stmt
begin_decl_stmt
unit|};
name|class
name|Q_GUI_EXPORT
name|QOpenGLTextureGlyphCache
range|:
name|public
name|QImageTextureGlyphCache
block|{
name|public
operator|:
name|QOpenGLTextureGlyphCache
argument_list|(
argument|QFontEngine::GlyphFormat glyphFormat
argument_list|,
argument|const QTransform&matrix
argument_list|)
block|;
operator|~
name|QOpenGLTextureGlyphCache
argument_list|()
block|;
name|virtual
name|void
name|createTextureData
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|resizeTextureData
argument_list|(
argument|int width
argument_list|,
argument|int height
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|void
name|fillTexture
argument_list|(
argument|const Coord&c
argument_list|,
argument|glyph_t glyph
argument_list|,
argument|QFixed subPixelPosition
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|int
name|glyphPadding
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|int
name|maxTextureWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|int
name|maxTextureHeight
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
specifier|inline
name|GLuint
name|texture
argument_list|()
specifier|const
block|{
name|QOpenGLTextureGlyphCache
operator|*
name|that
operator|=
name|const_cast
operator|<
name|QOpenGLTextureGlyphCache
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|QOpenGLGlyphTexture
operator|*
name|glyphTexture
operator|=
name|that
operator|->
name|m_textureResource
block|;
return|return
name|glyphTexture
condition|?
name|glyphTexture
operator|->
name|m_texture
else|:
literal|0
return|;
block|}
specifier|inline
name|int
name|width
argument_list|()
specifier|const
block|{
name|QOpenGLTextureGlyphCache
operator|*
name|that
operator|=
name|const_cast
operator|<
name|QOpenGLTextureGlyphCache
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|QOpenGLGlyphTexture
operator|*
name|glyphTexture
operator|=
name|that
operator|->
name|m_textureResource
block|;
return|return
name|glyphTexture
condition|?
name|glyphTexture
operator|->
name|m_width
else|:
literal|0
return|;
block|}
specifier|inline
name|int
name|height
argument_list|()
specifier|const
block|{
name|QOpenGLTextureGlyphCache
operator|*
name|that
operator|=
name|const_cast
operator|<
name|QOpenGLTextureGlyphCache
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|QOpenGLGlyphTexture
operator|*
name|glyphTexture
operator|=
name|that
operator|->
name|m_textureResource
block|;
return|return
name|glyphTexture
condition|?
name|glyphTexture
operator|->
name|m_height
else|:
literal|0
return|;
block|}
specifier|inline
name|void
name|setPaintEnginePrivate
argument_list|(
argument|QOpenGL2PaintEngineExPrivate *p
argument_list|)
block|{
name|pex
operator|=
name|p
block|; }
specifier|inline
specifier|const
name|QOpenGLContextGroup
operator|*
name|contextGroup
argument_list|()
specifier|const
block|{
return|return
name|m_textureResource
condition|?
name|m_textureResource
operator|->
name|group
argument_list|()
else|:
literal|0
return|;
block|}
specifier|inline
name|int
name|serialNumber
argument_list|()
specifier|const
block|{
return|return
name|m_serialNumber
return|;
block|}
expr|enum
name|FilterMode
block|{
name|Nearest
block|,
name|Linear
block|}
block|;
name|FilterMode
name|filterMode
argument_list|()
specifier|const
block|{
return|return
name|m_filterMode
return|;
block|}
name|void
name|setFilterMode
argument_list|(
argument|FilterMode m
argument_list|)
block|{
name|m_filterMode
operator|=
name|m
block|; }
name|void
name|clear
argument_list|()
block|;
name|private
operator|:
name|void
name|setupVertexAttribs
argument_list|()
block|;
name|QOpenGLGlyphTexture
operator|*
name|m_textureResource
block|;
name|QOpenGL2PaintEngineExPrivate
operator|*
name|pex
block|;
name|QOpenGLShaderProgram
operator|*
name|m_blitProgram
block|;
name|FilterMode
name|m_filterMode
block|;
name|GLfloat
name|m_vertexCoordinateArray
index|[
literal|8
index|]
block|;
name|GLfloat
name|m_textureCoordinateArray
index|[
literal|8
index|]
block|;
name|int
name|m_serialNumber
block|;
name|QOpenGLBuffer
name|m_buffer
block|;
name|QOpenGLVertexArrayObject
name|m_vao
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
comment|// QOPENGLTEXTUREGLYPHCACHE_P_H
end_comment
end_unit
