begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LISTITEMCACHE_H
end_ifndef
begin_define
DECL|macro|LISTITEMCACHE_H
define|#
directive|define
name|LISTITEMCACHE_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsEffect>
end_include
begin_include
include|#
directive|include
file|<QPixmapCache>
end_include
begin_decl_stmt
name|class
name|ListItemCache
range|:
name|public
name|QGraphicsEffect
block|{
name|Q_OBJECT
name|public
operator|:
name|ListItemCache
argument_list|()
block|;
operator|~
name|ListItemCache
argument_list|()
block|;
name|public
operator|:
comment|// QGraphicsEffect
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|)
block|;
name|void
name|sourceChanged
argument_list|(
argument|ChangeFlags flags
argument_list|)
block|;
name|private
operator|:
name|QPixmapCache
operator|::
name|Key
name|m_cacheKey
block|;
name|QRectF
name|m_visibleRect
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LISTITEMCACHE_H
end_comment
end_unit
