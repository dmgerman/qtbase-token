begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLTEXTURECACHE_P_H
end_ifndef
begin_define
DECL|macro|QOPENGLTEXTURECACHE_P_H
define|#
directive|define
name|QOPENGLTEXTURECACHE_P_H
end_define
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QCache>
end_include
begin_include
include|#
directive|include
file|<private/qopenglcontext_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmutex.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QOpenGLCachedTexture
block|{
name|public
label|:
name|QOpenGLCachedTexture
argument_list|(
argument|GLuint id
argument_list|,
argument|int options
argument_list|,
argument|QOpenGLContext *context
argument_list|)
empty_stmt|;
operator|~
name|QOpenGLCachedTexture
argument_list|()
block|{
name|m_resource
operator|->
name|free
argument_list|()
block|; }
name|GLuint
name|id
argument_list|()
specifier|const
block|{
return|return
name|m_resource
operator|->
name|id
argument_list|()
return|;
block|}
name|int
name|options
argument_list|()
specifier|const
block|{
return|return
name|m_options
return|;
block|}
name|private
label|:
name|QOpenGLSharedResourceGuard
modifier|*
name|m_resource
decl_stmt|;
name|int
name|m_options
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QOpenGLTextureCache
range|:
name|public
name|QOpenGLSharedResource
block|{
name|public
operator|:
specifier|static
name|QOpenGLTextureCache
operator|*
name|cacheForContext
argument_list|(
name|QOpenGLContext
operator|*
name|context
argument_list|)
block|;
name|QOpenGLTextureCache
argument_list|(
name|QOpenGLContext
operator|*
argument_list|)
block|;
operator|~
name|QOpenGLTextureCache
argument_list|()
block|;      enum
name|BindOption
block|{
name|NoBindOption
operator|=
literal|0x0000
block|,
name|PremultipliedAlphaBindOption
operator|=
literal|0x0001
block|,
name|UseRedFor8BitBindOption
operator|=
literal|0x0002
block|,     }
block|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|BindOptions
argument_list|,
argument|BindOption
argument_list|)
name|GLuint
name|bindTexture
argument_list|(
argument|QOpenGLContext *context
argument_list|,
argument|const QPixmap&pixmap
argument_list|,
argument|QOpenGLTextureCache::BindOptions options = PremultipliedAlphaBindOption
argument_list|)
block|;
name|GLuint
name|bindTexture
argument_list|(
argument|QOpenGLContext *context
argument_list|,
argument|const QImage&image
argument_list|,
argument|QOpenGLTextureCache::BindOptions options = PremultipliedAlphaBindOption
argument_list|)
block|;
name|void
name|invalidate
argument_list|(
argument|qint64 key
argument_list|)
block|;
name|void
name|invalidateResource
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|freeResource
argument_list|(
argument|QOpenGLContext *ctx
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|GLuint
name|bindTexture
argument_list|(
argument|QOpenGLContext *context
argument_list|,
argument|qint64 key
argument_list|,
argument|const QImage&image
argument_list|,
argument|QOpenGLTextureCache::BindOptions options
argument_list|)
block|;
name|QMutex
name|m_mutex
block|;
name|QCache
operator|<
name|quint64
block|,
name|QOpenGLCachedTexture
operator|>
name|m_cache
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QOpenGLTextureCache::BindOptions
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
