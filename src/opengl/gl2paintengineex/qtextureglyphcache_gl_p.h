begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenGL module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTUREGLYPHCACHE_GL_P_H
end_ifndef
begin_define
DECL|macro|QTEXTUREGLYPHCACHE_GL_P_H
define|#
directive|define
name|QTEXTUREGLYPHCACHE_GL_P_H
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
file|<private/qgl_p.h>
end_include
begin_include
include|#
directive|include
file|<qglshaderprogram.h>
end_include
begin_comment
comment|// #define QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
end_comment
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGL2PaintEngineExPrivate
name|class
name|QGL2PaintEngineExPrivate
decl_stmt|;
end_decl_stmt
begin_struct
DECL|struct|QGLGlyphTexture
struct|struct
name|QGLGlyphTexture
block|{
DECL|function|QGLGlyphTexture
name|QGLGlyphTexture
argument_list|(
specifier|const
name|QGLContext
operator|*
name|ctx
argument_list|)
operator|:
name|m_width
argument_list|(
literal|0
argument_list|)
operator|,
name|m_height
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|ctx
operator|&&
operator|!
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenFBOReadBack
condition|)
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
literal|" -> QGLGlyphTexture() %p for context %p."
argument_list|,
name|this
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
DECL|function|~QGLGlyphTexture
decl|~
name|QGLGlyphTexture
argument_list|()
block|{
specifier|const
name|QGLContext
modifier|*
name|ctx
init|=
name|QGLContext
operator|::
name|currentContext
argument_list|()
decl_stmt|;
ifdef|#
directive|ifdef
name|QT_GL_TEXTURE_GLYPH_CACHE_DEBUG
name|qDebug
argument_list|(
literal|"~QGLGlyphTexture() %p for context %p."
argument_list|,
name|this
argument_list|,
name|ctx
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// At this point, the context group is made current, so it's safe to
comment|// release resources without a makeCurrent() call
if|if
condition|(
name|ctx
condition|)
block|{
if|if
condition|(
operator|!
name|ctx
operator|->
name|d_ptr
operator|->
name|workaround_brokenFBOReadBack
condition|)
name|glDeleteFramebuffers
argument_list|(
literal|1
argument_list|,
operator|&
name|m_fbo
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_width
operator|||
name|m_height
condition|)
name|glDeleteTextures
argument_list|(
literal|1
argument_list|,
operator|&
name|m_texture
argument_list|)
expr_stmt|;
block|}
block|}
DECL|member|m_texture
name|GLuint
name|m_texture
struct|;
end_struct
begin_decl_stmt
DECL|member|m_fbo
name|GLuint
name|m_fbo
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_width
name|int
name|m_width
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_height
name|int
name|m_height
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|member|m_height
unit|};
DECL|variable|QImageTextureGlyphCache
name|class
name|Q_OPENGL_EXPORT
name|QGLTextureGlyphCache
range|:
name|public
name|QImageTextureGlyphCache
decl_stmt|,
name|public
name|QGLContextGroupResourceBase
block|{
name|public
label|:
name|QGLTextureGlyphCache
argument_list|(
argument|const QGLContext *context
argument_list|,
argument|QFontEngineGlyphCache::Type type
argument_list|,
argument|const QTransform&matrix
argument_list|)
empty_stmt|;
operator|~
name|QGLTextureGlyphCache
argument_list|()
expr_stmt|;
name|virtual
name|void
name|createTextureData
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|virtual
name|void
name|resizeTextureData
parameter_list|(
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|)
function_decl|;
name|virtual
name|void
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
function_decl|;
name|virtual
name|int
name|glyphPadding
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|maxTextureWidth
argument_list|()
specifier|const
expr_stmt|;
name|virtual
name|int
name|maxTextureHeight
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|GLuint
name|texture
argument_list|()
specifier|const
block|{
name|QGLTextureGlyphCache
operator|*
name|that
operator|=
name|const_cast
operator|<
name|QGLTextureGlyphCache
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|QGLGlyphTexture
operator|*
name|glyphTexture
operator|=
name|that
operator|->
name|m_textureResource
operator|.
name|value
argument_list|(
name|ctx
argument_list|)
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
name|QGLTextureGlyphCache
operator|*
name|that
operator|=
name|const_cast
operator|<
name|QGLTextureGlyphCache
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|QGLGlyphTexture
operator|*
name|glyphTexture
operator|=
name|that
operator|->
name|m_textureResource
operator|.
name|value
argument_list|(
name|ctx
argument_list|)
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
name|QGLTextureGlyphCache
operator|*
name|that
operator|=
name|const_cast
operator|<
name|QGLTextureGlyphCache
operator|*
operator|>
operator|(
name|this
operator|)
block|;
name|QGLGlyphTexture
operator|*
name|glyphTexture
operator|=
name|that
operator|->
name|m_textureResource
operator|.
name|value
argument_list|(
name|ctx
argument_list|)
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
parameter_list|(
name|QGL2PaintEngineExPrivate
modifier|*
name|p
parameter_list|)
block|{
name|pex
operator|=
name|p
expr_stmt|;
block|}
name|void
name|setContext
parameter_list|(
specifier|const
name|QGLContext
modifier|*
name|context
parameter_list|)
function_decl|;
specifier|inline
specifier|const
name|QGLContext
operator|*
name|context
argument_list|()
specifier|const
block|{
return|return
name|ctx
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
enum|enum
name|FilterMode
block|{
name|Nearest
block|,
name|Linear
block|}
enum|;
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
parameter_list|(
name|FilterMode
name|m
parameter_list|)
block|{
name|m_filterMode
operator|=
name|m
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
function_decl|;
name|void
name|freeResource
parameter_list|(
name|void
modifier|*
parameter_list|)
block|{
name|ctx
operator|=
literal|0
expr_stmt|;
block|}
name|private
label|:
name|QGLContextGroupResource
operator|<
name|QGLGlyphTexture
operator|>
name|m_textureResource
expr_stmt|;
specifier|const
name|QGLContext
modifier|*
name|ctx
decl_stmt|;
name|QGL2PaintEngineExPrivate
modifier|*
name|pex
decl_stmt|;
name|QGLShaderProgram
modifier|*
name|m_blitProgram
decl_stmt|;
name|FilterMode
name|m_filterMode
decl_stmt|;
name|GLfloat
name|m_vertexCoordinateArray
index|[
literal|8
index|]
decl_stmt|;
name|GLfloat
name|m_textureCoordinateArray
index|[
literal|8
index|]
decl_stmt|;
name|int
name|m_serialNumber
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
