begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTITEMDELEGATE_H
end_ifndef
begin_define
DECL|macro|QABSTRACTITEMDELEGATE_H
define|#
directive|define
name|QABSTRACTITEMDELEGATE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qstyleoption.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QModelIndex
name|class
name|QModelIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemModel
name|class
name|QAbstractItemModel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QAbstractItemView
name|class
name|QAbstractItemView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QHelpEvent
name|class
name|QHelpEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QAbstractItemDelegate
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
expr|enum
name|EndEditHint
block|{
name|NoHint
block|,
name|EditNextItem
block|,
name|EditPreviousItem
block|,
name|SubmitModelCache
block|,
name|RevertModelCache
block|}
block|;
name|explicit
name|QAbstractItemDelegate
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
operator|~
name|QAbstractItemDelegate
argument_list|()
block|;
comment|// painting
name|virtual
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|virtual
name|QSize
name|sizeHint
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// editing
name|virtual
name|QWidget
operator|*
name|createEditor
argument_list|(
argument|QWidget *parent
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setEditorData
argument_list|(
argument|QWidget *editor
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|setModelData
argument_list|(
argument|QWidget *editor
argument_list|,
argument|QAbstractItemModel *model
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|updateEditorGeometry
argument_list|(
argument|QWidget *editor
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
comment|// for non-widget editors
name|virtual
name|bool
name|editorEvent
argument_list|(
name|QEvent
operator|*
name|event
argument_list|,
name|QAbstractItemModel
operator|*
name|model
argument_list|,
specifier|const
name|QStyleOptionViewItem
operator|&
name|option
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
specifier|static
name|QString
name|elidedText
argument_list|(
argument|const QFontMetrics&fontMetrics
argument_list|,
argument|int width
argument_list|,
argument|Qt::TextElideMode mode
argument_list|,
argument|const QString&text
argument_list|)
block|;
name|virtual
name|bool
name|helpEvent
argument_list|(
name|QHelpEvent
operator|*
name|event
argument_list|,
name|QAbstractItemView
operator|*
name|view
argument_list|,
specifier|const
name|QStyleOptionViewItem
operator|&
name|option
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|commitData
argument_list|(
name|QWidget
operator|*
name|editor
argument_list|)
block|;
name|void
name|closeEditor
argument_list|(
argument|QWidget *editor
argument_list|,
argument|QAbstractItemDelegate::EndEditHint hint = NoHint
argument_list|)
block|;
name|void
name|sizeHintChanged
argument_list|(
specifier|const
name|QModelIndex
operator|&
argument_list|)
block|;
name|protected
operator|:
name|QAbstractItemDelegate
argument_list|(
name|QObjectPrivate
operator|&
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QAbstractItemDelegate
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QABSTRACTITEMDELEGATE_H
end_comment
end_unit
