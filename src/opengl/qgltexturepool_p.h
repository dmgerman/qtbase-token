begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtOpenVG module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLTEXTUREPOOL_P_H
end_ifndef
begin_define
DECL|macro|QGLTEXTUREPOOL_P_H
define|#
directive|define
name|QGLTEXTUREPOOL_P_H
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
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"qgl.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGLPixmapData
name|class
name|QGLPixmapData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QGLTexturePoolPrivate
name|class
name|QGLTexturePoolPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QGLTexturePool
block|{
name|public
label|:
name|QGLTexturePool
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QGLTexturePool
argument_list|()
expr_stmt|;
specifier|static
name|QGLTexturePool
modifier|*
name|instance
parameter_list|()
function_decl|;
comment|// Create a new texture with the specified parameters and associate
comment|// it with "data".  The QGLPixmapData will be notified when the
comment|// texture needs to be reclaimed by the pool.
comment|//
comment|// This function will call reclaimSpace() when texture creation fails.
name|GLuint
name|createTextureForPixmap
parameter_list|(
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|QGLPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Create a permanent texture with the specified parameters.
comment|// If there is insufficient space for the texture,
comment|// then this function will call reclaimSpace() and try again.
comment|//
comment|// The caller is responsible for calling glDeleteTextures()
comment|// when it no longer needs the texture, as the texture is not
comment|// recorded in the texture pool.
name|bool
name|createPermanentTexture
parameter_list|(
name|GLuint
name|texture
parameter_list|,
name|GLenum
name|target
parameter_list|,
name|GLint
name|level
parameter_list|,
name|GLint
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
specifier|const
name|GLvoid
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Release a texture that is no longer required.
name|void
name|releaseTexture
parameter_list|(
name|QGLPixmapData
modifier|*
name|data
parameter_list|,
name|GLuint
name|texture
parameter_list|)
function_decl|;
comment|// Notify the pool that a QGLPixmapData object is using
comment|// an texture again.  This allows the pool to move the texture
comment|// within a least-recently-used list of QGLPixmapData objects.
name|void
name|useTexture
parameter_list|(
name|QGLPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Notify the pool that the texture associated with a
comment|// QGLPixmapData is being detached from the pool.  The caller
comment|// will become responsible for calling glDeleteTextures().
name|void
name|detachTexture
parameter_list|(
name|QGLPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Reclaim space for an image allocation with the specified parameters.
comment|// Returns true if space was reclaimed, or false if there is no
comment|// further space that can be reclaimed.  The "data" parameter
comment|// indicates the pixmap that is trying to obtain space which should
comment|// not itself be reclaimed.
name|bool
name|reclaimSpace
parameter_list|(
name|GLint
name|internalformat
parameter_list|,
name|GLsizei
name|width
parameter_list|,
name|GLsizei
name|height
parameter_list|,
name|GLenum
name|format
parameter_list|,
name|GLenum
name|type
parameter_list|,
name|QGLPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
comment|// Hibernate the image pool because the context is about to be
comment|// destroyed.  All textures left in the pool should be released.
name|void
name|hibernate
parameter_list|()
function_decl|;
name|protected
label|:
comment|// Helper functions for managing the LRU list of QGLPixmapData objects.
name|void
name|moveToHeadOfLRU
parameter_list|(
name|QGLPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
name|removeFromLRU
parameter_list|(
name|QGLPixmapData
modifier|*
name|data
parameter_list|)
function_decl|;
name|QGLPixmapData
modifier|*
name|pixmapLRU
parameter_list|()
function_decl|;
name|private
label|:
name|QScopedPointer
operator|<
name|QGLTexturePoolPrivate
operator|>
name|d_ptr
expr_stmt|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGLTexturePool
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QGLTexturePool
argument_list|)
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
