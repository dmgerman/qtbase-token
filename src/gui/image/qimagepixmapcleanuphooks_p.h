begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QIMAGEPIXMAP_CLEANUPHOOKS_P_H
end_ifndef
begin_define
DECL|macro|QIMAGEPIXMAP_CLEANUPHOOKS_P_H
define|#
directive|define
name|QIMAGEPIXMAP_CLEANUPHOOKS_P_H
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
file|<QtGui/qpixmap.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_typedef
DECL|typedef|_qt_image_cleanup_hook_64
typedef|typedef
name|void
function_decl|(
modifier|*
name|_qt_image_cleanup_hook_64
function_decl|)
parameter_list|(
name|qint64
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|_qt_pixmap_cleanup_hook_pmd
typedef|typedef
name|void
function_decl|(
modifier|*
name|_qt_pixmap_cleanup_hook_pmd
function_decl|)
parameter_list|(
name|QPlatformPixmap
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|QImagePixmapCleanupHooks
name|class
name|QImagePixmapCleanupHooks
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QImagePixmapCleanupHooks
block|{
name|public
label|:
specifier|static
name|QImagePixmapCleanupHooks
modifier|*
name|instance
parameter_list|()
function_decl|;
specifier|static
name|void
name|enableCleanupHooks
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
specifier|static
name|void
name|enableCleanupHooks
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
function_decl|;
specifier|static
name|void
name|enableCleanupHooks
parameter_list|(
name|QPlatformPixmap
modifier|*
name|handle
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isImageCached
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
function_decl|;
specifier|static
name|bool
name|isPixmapCached
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
function_decl|;
comment|// Gets called when a pixmap data is about to be modified:
name|void
name|addPlatformPixmapModificationHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
parameter_list|)
function_decl|;
comment|// Gets called when a pixmap data is about to be destroyed:
name|void
name|addPlatformPixmapDestructionHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
parameter_list|)
function_decl|;
comment|// Gets called when an image is about to be modified or destroyed:
name|void
name|addImageHook
parameter_list|(
name|_qt_image_cleanup_hook_64
parameter_list|)
function_decl|;
name|void
name|removePlatformPixmapModificationHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
parameter_list|)
function_decl|;
name|void
name|removePlatformPixmapDestructionHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
parameter_list|)
function_decl|;
name|void
name|removeImageHook
parameter_list|(
name|_qt_image_cleanup_hook_64
parameter_list|)
function_decl|;
specifier|static
name|void
name|executePlatformPixmapModificationHooks
parameter_list|(
name|QPlatformPixmap
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
name|executePlatformPixmapDestructionHooks
parameter_list|(
name|QPlatformPixmap
modifier|*
parameter_list|)
function_decl|;
specifier|static
name|void
name|executeImageHooks
parameter_list|(
name|qint64
name|key
parameter_list|)
function_decl|;
name|private
label|:
name|QList
operator|<
name|_qt_image_cleanup_hook_64
operator|>
name|imageHooks
expr_stmt|;
name|QList
operator|<
name|_qt_pixmap_cleanup_hook_pmd
operator|>
name|pixmapModificationHooks
expr_stmt|;
name|QList
operator|<
name|_qt_pixmap_cleanup_hook_pmd
operator|>
name|pixmapDestructionHooks
expr_stmt|;
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
begin_comment
comment|// QIMAGEPIXMAP_CLEANUPHOOKS_P_H
end_comment
end_unit
