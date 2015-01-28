begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QITEMDELEGATE_H
end_ifndef
begin_define
DECL|macro|QITEMDELEGATE_H
define|#
directive|define
name|QITEMDELEGATE_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qabstractitemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvariant.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
DECL|variable|QItemDelegatePrivate
name|class
name|QItemDelegatePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QItemEditorFactory
name|class
name|QItemEditorFactory
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QItemDelegate
range|:
name|public
name|QAbstractItemDelegate
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|bool clipping READ hasClipping WRITE setClipping
argument_list|)
name|public
operator|:
name|explicit
name|QItemDelegate
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QItemDelegate
argument_list|()
block|;
name|bool
name|hasClipping
argument_list|()
specifier|const
block|;
name|void
name|setClipping
argument_list|(
argument|bool clip
argument_list|)
block|;
comment|// painting
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
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeHint
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
comment|// editing
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
name|Q_DECL_OVERRIDE
block|;
name|void
name|setEditorData
argument_list|(
argument|QWidget *editor
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
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
name|Q_DECL_OVERRIDE
block|;
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
name|Q_DECL_OVERRIDE
block|;
comment|// editor factory
name|QItemEditorFactory
operator|*
name|itemEditorFactory
argument_list|()
specifier|const
block|;
name|void
name|setItemEditorFactory
argument_list|(
name|QItemEditorFactory
operator|*
name|factory
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|drawDisplay
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QRect&rect
argument_list|,
argument|const QString&text
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawDecoration
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QRect&rect
argument_list|,
argument|const QPixmap&pixmap
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawFocus
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QRect&rect
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|drawCheck
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QRect&rect
argument_list|,
argument|Qt::CheckState state
argument_list|)
specifier|const
block|;
name|void
name|drawBackground
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|;
name|void
name|doLayout
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|QRect *checkRect
argument_list|,
argument|QRect *iconRect
argument_list|,
argument|QRect *textRect
argument_list|,
argument|bool hint
argument_list|)
specifier|const
block|;
name|QRect
name|rect
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|,
argument|int role
argument_list|)
specifier|const
block|;
name|bool
name|eventFilter
argument_list|(
argument|QObject *object
argument_list|,
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|editorEvent
argument_list|(
argument|QEvent *event
argument_list|,
argument|QAbstractItemModel *model
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QStyleOptionViewItem
name|setOptions
argument_list|(
argument|const QModelIndex&index
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|)
specifier|const
block|;
name|QPixmap
name|decoration
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QVariant&variant
argument_list|)
specifier|const
block|;
name|QPixmap
operator|*
name|selected
argument_list|(
argument|const QPixmap&pixmap
argument_list|,
argument|const QPalette&palette
argument_list|,
argument|bool enabled
argument_list|)
specifier|const
block|;
name|QRect
name|doCheck
argument_list|(
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QRect&bounding
argument_list|,
argument|const QVariant&variant
argument_list|)
specifier|const
block|;
name|QRect
name|textRectangle
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QRect&rect
argument_list|,
argument|const QFont&font
argument_list|,
argument|const QString&text
argument_list|)
specifier|const
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QItemDelegate
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QItemDelegate
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
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QITEMDELEGATE_H
end_comment
end_unit
