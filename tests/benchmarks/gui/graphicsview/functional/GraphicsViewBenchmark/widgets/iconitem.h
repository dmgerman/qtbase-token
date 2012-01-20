begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ICONITEM_H
end_ifndef
begin_define
DECL|macro|ICONITEM_H
define|#
directive|define
name|ICONITEM_H
end_define
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|"gvbwidget.h"
end_include
begin_decl_stmt
DECL|variable|QGraphicsOpacityEffect
name|class
name|QGraphicsOpacityEffect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|IconItem
range|:
name|public
name|GvbWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|IconItem
argument_list|(
specifier|const
name|QString
operator|&
name|filename
operator|=
literal|""
argument_list|,
name|QGraphicsItem
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|IconItem
argument_list|()
block|;
name|QString
name|fileName
argument_list|()
specifier|const
block|;
name|void
name|setFileName
argument_list|(
specifier|const
name|QString
operator|&
name|filename
argument_list|)
block|;
name|void
name|setOpacityEffectEnabled
argument_list|(
argument|const bool enable
argument_list|)
block|;
name|bool
name|isOpacityEffectEnabled
argument_list|()
specifier|const
block|;
name|void
name|setRotation
argument_list|(
argument|const qreal rotation
argument_list|)
block|{
name|m_rotation
operator|=
name|rotation
block|; }
name|qreal
name|rotation
argument_list|()
specifier|const
block|{
return|return
name|m_rotation
return|;
block|}
name|void
name|setSmoothTransformationEnabled
argument_list|(
argument|const bool enable
argument_list|)
block|{
name|m_smoothTransformation
operator|=
name|enable
block|; }
name|bool
name|isSmoothTransformationEnabled
argument_list|()
specifier|const
block|{
return|return
name|m_smoothTransformation
return|;
block|}
name|private
operator|:
name|virtual
name|void
name|paint
argument_list|(
name|QPainter
operator|*
name|painter
argument_list|,
specifier|const
name|QStyleOptionGraphicsItem
operator|*
name|option
argument_list|,
name|QWidget
operator|*
comment|/*widget = 0*/
argument_list|)
block|;
name|QSizeF
name|sizeHint
argument_list|(
argument|Qt::SizeHint which
argument_list|,
argument|const QSizeF&constraint = QSizeF()
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|IconItem
argument_list|)
name|void
name|reload
argument_list|()
block|;
name|QString
name|m_filename
block|;
name|QPixmap
name|m_pixmap
block|;
name|qreal
name|m_rotation
block|;
name|QGraphicsOpacityEffect
operator|*
name|m_opacityEffect
block|;
name|bool
name|m_smoothTransformation
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
