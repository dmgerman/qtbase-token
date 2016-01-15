begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QOPENGLCOMPOSITORBACKINGSTORE_H
end_ifndef
begin_define
DECL|macro|QOPENGLCOMPOSITORBACKINGSTORE_H
define|#
directive|define
name|QOPENGLCOMPOSITORBACKINGSTORE_H
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
begin_include
include|#
directive|include
file|<qpa/qplatformbackingstore.h>
end_include
begin_include
include|#
directive|include
file|<QImage>
end_include
begin_include
include|#
directive|include
file|<QRegion>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QOpenGLContext
name|class
name|QOpenGLContext
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPlatformTextureList
name|class
name|QPlatformTextureList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QOpenGLCompositorBackingStore
range|:
name|public
name|QPlatformBackingStore
block|{
name|public
operator|:
name|QOpenGLCompositorBackingStore
argument_list|(
name|QWindow
operator|*
name|window
argument_list|)
block|;
operator|~
name|QOpenGLCompositorBackingStore
argument_list|()
block|;
name|QPaintDevice
operator|*
name|paintDevice
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|beginPaint
argument_list|(
argument|const QRegion&region
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|flush
argument_list|(
argument|QWindow *window
argument_list|,
argument|const QRegion&region
argument_list|,
argument|const QPoint&offset
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|resize
argument_list|(
argument|const QSize&size
argument_list|,
argument|const QRegion&staticContents
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QImage
name|toImage
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|composeAndFlush
argument_list|(
argument|QWindow *window
argument_list|,
argument|const QRegion&region
argument_list|,
argument|const QPoint&offset
argument_list|,
argument|QPlatformTextureList *textures
argument_list|,
argument|QOpenGLContext *context
argument_list|,
argument|bool translucentBackground
argument_list|)
name|Q_DECL_OVERRIDE
block|;
specifier|const
name|QPlatformTextureList
operator|*
name|textures
argument_list|()
specifier|const
block|{
return|return
name|m_textures
return|;
block|}
name|void
name|notifyComposited
argument_list|()
block|;
name|private
operator|:
name|void
name|updateTexture
argument_list|()
block|;
name|QWindow
operator|*
name|m_window
block|;
name|QImage
name|m_image
block|;
name|QRegion
name|m_dirty
block|;
name|uint
name|m_bsTexture
block|;
name|QOpenGLContext
operator|*
name|m_bsTextureContext
block|;
name|QPlatformTextureList
operator|*
name|m_textures
block|;
name|QPlatformTextureList
operator|*
name|m_lockedWidgetTextures
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
comment|// QOPENGLCOMPOSITORBACKINGSTORE_H
end_comment
end_unit
