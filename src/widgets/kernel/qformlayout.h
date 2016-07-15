begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFORMLAYOUT_H
end_ifndef
begin_define
DECL|macro|QFORMLAYOUT_H
define|#
directive|define
name|QFORMLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/QLayout>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFormLayoutPrivate
name|class
name|QFormLayoutPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QFormLayout
range|:
name|public
name|QLayout
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFormLayout
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|FieldGrowthPolicy fieldGrowthPolicy READ fieldGrowthPolicy WRITE setFieldGrowthPolicy RESET resetFieldGrowthPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|RowWrapPolicy rowWrapPolicy READ rowWrapPolicy WRITE setRowWrapPolicy RESET resetRowWrapPolicy
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment labelAlignment READ labelAlignment WRITE setLabelAlignment RESET resetLabelAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Qt::Alignment formAlignment READ formAlignment WRITE setFormAlignment RESET resetFormAlignment
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int horizontalSpacing READ horizontalSpacing WRITE setHorizontalSpacing
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|int verticalSpacing READ verticalSpacing WRITE setVerticalSpacing
argument_list|)
name|public
operator|:
expr|enum
name|FieldGrowthPolicy
block|{
name|FieldsStayAtSizeHint
block|,
name|ExpandingFieldsGrow
block|,
name|AllNonFixedFieldsGrow
block|}
block|;
name|Q_ENUM
argument_list|(
name|FieldGrowthPolicy
argument_list|)
expr|enum
name|RowWrapPolicy
block|{
name|DontWrapRows
block|,
name|WrapLongRows
block|,
name|WrapAllRows
block|}
block|;
name|Q_ENUM
argument_list|(
name|RowWrapPolicy
argument_list|)
expr|enum
name|ItemRole
block|{
name|LabelRole
operator|=
literal|0
block|,
name|FieldRole
operator|=
literal|1
block|,
name|SpanningRole
operator|=
literal|2
block|}
block|;
name|Q_ENUM
argument_list|(
argument|ItemRole
argument_list|)
name|explicit
name|QFormLayout
argument_list|(
name|QWidget
operator|*
name|parent
operator|=
name|Q_NULLPTR
argument_list|)
block|;
operator|~
name|QFormLayout
argument_list|()
block|;
name|void
name|setFieldGrowthPolicy
argument_list|(
argument|FieldGrowthPolicy policy
argument_list|)
block|;
name|FieldGrowthPolicy
name|fieldGrowthPolicy
argument_list|()
specifier|const
block|;
name|void
name|setRowWrapPolicy
argument_list|(
argument|RowWrapPolicy policy
argument_list|)
block|;
name|RowWrapPolicy
name|rowWrapPolicy
argument_list|()
specifier|const
block|;
name|void
name|setLabelAlignment
argument_list|(
argument|Qt::Alignment alignment
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|labelAlignment
argument_list|()
specifier|const
block|;
name|void
name|setFormAlignment
argument_list|(
argument|Qt::Alignment alignment
argument_list|)
block|;
name|Qt
operator|::
name|Alignment
name|formAlignment
argument_list|()
specifier|const
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
name|int
name|spacing
argument_list|()
specifier|const
block|;
name|void
name|setSpacing
argument_list|(
name|int
argument_list|)
block|;
name|void
name|addRow
argument_list|(
name|QWidget
operator|*
name|label
argument_list|,
name|QWidget
operator|*
name|field
argument_list|)
block|;
name|void
name|addRow
argument_list|(
name|QWidget
operator|*
name|label
argument_list|,
name|QLayout
operator|*
name|field
argument_list|)
block|;
name|void
name|addRow
argument_list|(
specifier|const
name|QString
operator|&
name|labelText
argument_list|,
name|QWidget
operator|*
name|field
argument_list|)
block|;
name|void
name|addRow
argument_list|(
specifier|const
name|QString
operator|&
name|labelText
argument_list|,
name|QLayout
operator|*
name|field
argument_list|)
block|;
name|void
name|addRow
argument_list|(
name|QWidget
operator|*
name|widget
argument_list|)
block|;
name|void
name|addRow
argument_list|(
name|QLayout
operator|*
name|layout
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|QWidget *label
argument_list|,
argument|QWidget *field
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|QWidget *label
argument_list|,
argument|QLayout *field
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|const QString&labelText
argument_list|,
argument|QWidget *field
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|const QString&labelText
argument_list|,
argument|QLayout *field
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
name|void
name|insertRow
argument_list|(
argument|int row
argument_list|,
argument|QLayout *layout
argument_list|)
block|;
name|void
name|setItem
argument_list|(
argument|int row
argument_list|,
argument|ItemRole role
argument_list|,
argument|QLayoutItem *item
argument_list|)
block|;
name|void
name|setWidget
argument_list|(
argument|int row
argument_list|,
argument|ItemRole role
argument_list|,
argument|QWidget *widget
argument_list|)
block|;
name|void
name|setLayout
argument_list|(
argument|int row
argument_list|,
argument|ItemRole role
argument_list|,
argument|QLayout *layout
argument_list|)
block|;
name|QLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int row
argument_list|,
argument|ItemRole role
argument_list|)
specifier|const
block|;
name|void
name|getItemPosition
argument_list|(
argument|int index
argument_list|,
argument|int *rowPtr
argument_list|,
argument|ItemRole *rolePtr
argument_list|)
specifier|const
block|;
name|void
name|getWidgetPosition
argument_list|(
argument|QWidget *widget
argument_list|,
argument|int *rowPtr
argument_list|,
argument|ItemRole *rolePtr
argument_list|)
specifier|const
block|;
name|void
name|getLayoutPosition
argument_list|(
argument|QLayout *layout
argument_list|,
argument|int *rowPtr
argument_list|,
argument|ItemRole *rolePtr
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|labelForField
argument_list|(
argument|QWidget *field
argument_list|)
specifier|const
block|;
name|QWidget
operator|*
name|labelForField
argument_list|(
argument|QLayout *field
argument_list|)
specifier|const
block|;
comment|// reimplemented from QLayout
name|void
name|addItem
argument_list|(
argument|QLayoutItem *item
argument_list|)
name|Q_DECL_OVERRIDE
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
name|takeAt
argument_list|(
argument|int index
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|setGeometry
argument_list|(
argument|const QRect&rect
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|minimumSize
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QSize
name|sizeHint
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|void
name|invalidate
argument_list|()
name|Q_DECL_OVERRIDE
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
argument|int width
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
name|int
name|count
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|int
name|rowCount
argument_list|()
specifier|const
block|;
if|#
directive|if
literal|0
block|void dump() const;
endif|#
directive|endif
name|private
operator|:
name|void
name|resetFieldGrowthPolicy
argument_list|()
block|;
name|void
name|resetRowWrapPolicy
argument_list|()
block|;
name|void
name|resetLabelAlignment
argument_list|()
block|;
name|void
name|resetFormAlignment
argument_list|()
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
end_unit
