begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qimagepixmapcleanuphooks_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformpixmap_qpa.h"
end_include
begin_include
include|#
directive|include
file|"private/qimage_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// Legacy, single instance hooks: ### Qt 5: remove
end_comment
begin_typedef
DECL|typedef|_qt_pixmap_cleanup_hook
typedef|typedef
name|void
function_decl|(
modifier|*
name|_qt_pixmap_cleanup_hook
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|_qt_pixmap_cleanup_hook_64
typedef|typedef
name|void
function_decl|(
modifier|*
name|_qt_pixmap_cleanup_hook_64
function_decl|)
parameter_list|(
name|qint64
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|_qt_image_cleanup_hook
typedef|typedef
name|void
function_decl|(
modifier|*
name|_qt_image_cleanup_hook
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef
begin_decl_stmt
DECL|variable|qt_pixmap_cleanup_hook
name|Q_GUI_EXPORT
name|_qt_pixmap_cleanup_hook
name|qt_pixmap_cleanup_hook
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_pixmap_cleanup_hook_64
name|Q_GUI_EXPORT
name|_qt_pixmap_cleanup_hook_64
name|qt_pixmap_cleanup_hook_64
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_image_cleanup_hook
name|Q_GUI_EXPORT
name|_qt_image_cleanup_hook
name|qt_image_cleanup_hook
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|qt_image_cleanup_hook_64
name|Q_GUI_EXPORT
name|_qt_image_cleanup_hook_64
name|qt_image_cleanup_hook_64
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|QImagePixmapCleanupHooks
argument_list|,
argument|qt_image_and_pixmap_cleanup_hooks
argument_list|)
end_macro
begin_function
DECL|function|instance
name|QImagePixmapCleanupHooks
modifier|*
name|QImagePixmapCleanupHooks
operator|::
name|instance
parameter_list|()
block|{
return|return
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|addPlatformPixmapModificationHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|addPlatformPixmapModificationHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
parameter_list|)
block|{
name|pixmapModificationHooks
operator|.
name|append
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addPlatformPixmapDestructionHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|addPlatformPixmapDestructionHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
parameter_list|)
block|{
name|pixmapDestructionHooks
operator|.
name|append
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addImageHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|addImageHook
parameter_list|(
name|_qt_image_cleanup_hook_64
name|hook
parameter_list|)
block|{
name|imageHooks
operator|.
name|append
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removePlatformPixmapModificationHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|removePlatformPixmapModificationHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
parameter_list|)
block|{
name|pixmapModificationHooks
operator|.
name|removeAll
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removePlatformPixmapDestructionHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|removePlatformPixmapDestructionHook
parameter_list|(
name|_qt_pixmap_cleanup_hook_pmd
name|hook
parameter_list|)
block|{
name|pixmapDestructionHooks
operator|.
name|removeAll
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeImageHook
name|void
name|QImagePixmapCleanupHooks
operator|::
name|removeImageHook
parameter_list|(
name|_qt_image_cleanup_hook_64
name|hook
parameter_list|)
block|{
name|imageHooks
operator|.
name|removeAll
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|executePlatformPixmapModificationHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|executePlatformPixmapModificationHooks
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pmd
parameter_list|)
block|{
name|QImagePixmapCleanupHooks
modifier|*
name|h
init|=
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
decl_stmt|;
comment|// the global destructor for the pixmap and image hooks might have
comment|// been called already if the app is "leaking" global
comment|// pixmaps/images
if|if
condition|(
operator|!
name|h
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|h
operator|->
name|pixmapModificationHooks
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|h
operator|->
name|pixmapModificationHooks
index|[
name|i
index|]
operator|(
name|pmd
operator|)
expr_stmt|;
if|if
condition|(
name|qt_pixmap_cleanup_hook_64
condition|)
name|qt_pixmap_cleanup_hook_64
argument_list|(
name|pmd
operator|->
name|cacheKey
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|executePlatformPixmapDestructionHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|executePlatformPixmapDestructionHooks
parameter_list|(
name|QPlatformPixmap
modifier|*
name|pmd
parameter_list|)
block|{
name|QImagePixmapCleanupHooks
modifier|*
name|h
init|=
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
decl_stmt|;
comment|// the global destructor for the pixmap and image hooks might have
comment|// been called already if the app is "leaking" global
comment|// pixmaps/images
if|if
condition|(
operator|!
name|h
condition|)
return|return;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|h
operator|->
name|pixmapDestructionHooks
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|h
operator|->
name|pixmapDestructionHooks
index|[
name|i
index|]
operator|(
name|pmd
operator|)
expr_stmt|;
if|if
condition|(
name|qt_pixmap_cleanup_hook_64
condition|)
name|qt_pixmap_cleanup_hook_64
argument_list|(
name|pmd
operator|->
name|cacheKey
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|executeImageHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|executeImageHooks
parameter_list|(
name|qint64
name|key
parameter_list|)
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
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
operator|->
name|imageHooks
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|qt_image_and_pixmap_cleanup_hooks
argument_list|()
operator|->
name|imageHooks
index|[
name|i
index|]
operator|(
name|key
operator|)
expr_stmt|;
if|if
condition|(
name|qt_image_cleanup_hook_64
condition|)
name|qt_image_cleanup_hook_64
argument_list|(
name|key
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableCleanupHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
parameter_list|(
name|QPlatformPixmap
modifier|*
name|handle
parameter_list|)
block|{
name|handle
operator|->
name|is_cached
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableCleanupHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
name|enableCleanupHooks
argument_list|(
cast|const_cast
argument_list|<
name|QPixmap
operator|&
argument_list|>
argument_list|(
name|pixmap
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|enableCleanupHooks
name|void
name|QImagePixmapCleanupHooks
operator|::
name|enableCleanupHooks
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
cast|const_cast
argument_list|<
name|QImage
operator|&
argument_list|>
argument_list|(
name|image
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|is_cached
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isImageCached
name|bool
name|QImagePixmapCleanupHooks
operator|::
name|isImageCached
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|)
block|{
return|return
cast|const_cast
argument_list|<
name|QImage
operator|&
argument_list|>
argument_list|(
name|image
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|->
name|is_cached
return|;
block|}
end_function
begin_function
DECL|function|isPixmapCached
name|bool
name|QImagePixmapCleanupHooks
operator|::
name|isPixmapCached
parameter_list|(
specifier|const
name|QPixmap
modifier|&
name|pixmap
parameter_list|)
block|{
return|return
cast|const_cast
argument_list|<
name|QPixmap
operator|&
argument_list|>
argument_list|(
name|pixmap
argument_list|)
operator|.
name|data_ptr
argument_list|()
operator|.
name|data
argument_list|()
operator|->
name|is_cached
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
