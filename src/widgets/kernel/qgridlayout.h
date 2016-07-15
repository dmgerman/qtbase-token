begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGRIDLAYOUT_H
end_ifndef
begin_define
DECL|macro|QGRIDLAYOUT_H
define|#
directive|define
name|QGRIDLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qlayout.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_INCLUDE_COMPAT
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qwidget.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QGridLayoutPrivate
name|class
name|QGridLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QGridLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QGridLayout
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int horizontalSpacing READ horizontalSpacing WRITE setHorizontalSpacing
argument_list|)
name|QDOC_PROPERTY
argument_list|(
argument|int verticalSpacing READ verticalSpacing WRITE setVerticalSpacing
argument_list|)
name|public
operator|:
name|explicit
name|QGridLayout
argument_list|(
name|QWidget
operator|*
name|parent
argument_list|)
block|;
name|QGridLayout
argument_list|()
block|;
operator|~
name|QGridLayout
argument_list|()
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|maximumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setHorizontalSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|int
name|horizontalSpacing
argument_list|()
specifier|const
block|;
name|void
name|setVerticalSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|int
name|verticalSpacing
argument_list|()
specifier|const
block|;
name|void
name|setSpacing
argument_list|(
argument|int spacing
argument_list|)
block|;
name|int
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setRowStretch
argument_list|(
argument|int row
argument_list|,
argument|int stretch
argument_list|)
block|;
name|void
name|setColumnStretch
argument_list|(
argument|int column
argument_list|,
argument|int stretch
argument_list|)
block|;
name|int
name|rowStretch
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|columnStretch
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|void
name|setRowMinimumHeight
argument_list|(
argument|int row
argument_list|,
argument|int minSize
argument_list|)
block|;
name|void
name|setColumnMinimumWidth
argument_list|(
argument|int column
argument_list|,
argument|int minSize
argument_list|)
block|;
name|int
name|rowMinimumHeight
argument_list|(
argument|int row
argument_list|)
specifier|const
block|;
name|int
name|columnMinimumWidth
argument_list|(
argument|int column
argument_list|)
specifier|const
block|;
name|int
name|columnCount
argument_list|()
specifier|const
block|;
name|int
name|rowCount
argument_list|()
specifier|const
block|;
name|QRect
name|cellRect
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|bool
name|hasHeightForWidth
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|heightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|minimumHeightForWidth
argument_list|(
argument|int
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|Qt
operator|::
name|Orientations
name|expandingDirections
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|invalidate
argument_list|()
name|Q_DECL_OVERRIDE
block|;
specifier|inline
name|void
name|addWidget
argument_list|(
argument|QWidget *w
argument_list|)
block|{
name|QLayout
operator|::
name|addWidget
argument_list|(
name|w
argument_list|)
block|; }
name|void
name|addWidget
argument_list|(
argument|QWidget *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|Qt::Alignment = Qt::Alignment()
argument_list|)
block|;
name|void
name|addWidget
argument_list|(
argument|QWidget *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan
argument_list|,
argument|int columnSpan
argument_list|,
argument|Qt::Alignment = Qt::Alignment()
argument_list|)
block|;
name|void
name|addLayout
argument_list|(
argument|QLayout *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|Qt::Alignment = Qt::Alignment()
argument_list|)
block|;
name|void
name|addLayout
argument_list|(
argument|QLayout *
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan
argument_list|,
argument|int columnSpan
argument_list|,
argument|Qt::Alignment = Qt::Alignment()
argument_list|)
block|;
name|void
name|setOriginCorner
argument_list|(
name|Qt
operator|::
name|Corner
argument_list|)
block|;
name|Qt
operator|::
name|Corner
name|originCorner
argument_list|()
specifier|const
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QLayoutItem
operator|*
name|itemAtPosition
argument_list|(
argument|int row
argument_list|,
argument|int column
argument_list|)
specifier|const
block|;
name|QLayoutItem
operator|*
name|takeAt
argument_list|(
argument|int index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|int
name|count
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRect&
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|addItem
argument_list|(
argument|QLayoutItem *item
argument_list|,
argument|int row
argument_list|,
argument|int column
argument_list|,
argument|int rowSpan =
literal|1
argument_list|,
argument|int columnSpan =
literal|1
argument_list|,
argument|Qt::Alignment = Qt::Alignment()
argument_list|)
block|;
name|void
name|setDefaultPositioning
argument_list|(
argument|int n
argument_list|,
argument|Qt::Orientation orient
argument_list|)
block|;
name|void
name|getItemPosition
argument_list|(
argument|int idx
argument_list|,
argument|int *row
argument_list|,
argument|int *column
argument_list|,
argument|int *rowSpan
argument_list|,
argument|int *columnSpan
argument_list|)
specifier|const
block|;
name|protected
operator|:
name|void
name|addItem
argument_list|(
argument|QLayoutItem *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QGridLayout
argument_list|)
block|}
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
comment|// QGRIDLAYOUT_H
end_comment
end_unit
