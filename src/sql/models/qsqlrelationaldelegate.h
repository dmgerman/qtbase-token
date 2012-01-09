begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtSql module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSQLRELATIONALDELEGATE_H
end_ifndef
begin_define
DECL|macro|QSQLRELATIONALDELEGATE_H
define|#
directive|define
name|QSQLRELATIONALDELEGATE_H
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_GUI_LIB
end_ifdef
begin_include
include|#
directive|include
file|<QtWidgets/qitemdelegate.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qlistview.h>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<QtSql/qsqlrelationaltablemodel.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|class
name|QSqlRelationalDelegate
range|:
name|public
name|QItemDelegate
block|{
name|public
operator|:
name|explicit
name|QSqlRelationalDelegate
argument_list|(
name|QObject
operator|*
name|aParent
operator|=
literal|0
argument_list|)
operator|:
name|QItemDelegate
argument_list|(
argument|aParent
argument_list|)
block|{}
operator|~
name|QSqlRelationalDelegate
argument_list|()
block|{}
name|QWidget
operator|*
name|createEditor
argument_list|(
argument|QWidget *aParent
argument_list|,
argument|const QStyleOptionViewItem&option
argument_list|,
argument|const QModelIndex&index
argument_list|)
specifier|const
block|{
specifier|const
name|QSqlRelationalTableModel
operator|*
name|sqlModel
operator|=
name|qobject_cast
operator|<
specifier|const
name|QSqlRelationalTableModel
operator|*
operator|>
operator|(
name|index
operator|.
name|model
argument_list|()
operator|)
block|;
name|QSqlTableModel
operator|*
name|childModel
operator|=
name|sqlModel
condition|?
name|sqlModel
operator|->
name|relationModel
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
else|:
literal|0
block|;
if|if
condition|(
operator|!
name|childModel
condition|)
return|return
name|QItemDelegate
operator|::
name|createEditor
argument_list|(
name|aParent
argument_list|,
name|option
argument_list|,
name|index
argument_list|)
return|;
name|QComboBox
operator|*
name|combo
operator|=
name|new
name|QComboBox
argument_list|(
name|aParent
argument_list|)
block|;
name|combo
operator|->
name|setModel
argument_list|(
name|childModel
argument_list|)
block|;
name|combo
operator|->
name|setModelColumn
argument_list|(
name|childModel
operator|->
name|fieldIndex
argument_list|(
name|sqlModel
operator|->
name|relation
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
operator|.
name|displayColumn
argument_list|()
argument_list|)
argument_list|)
block|;
name|combo
operator|->
name|installEventFilter
argument_list|(
name|const_cast
operator|<
name|QSqlRelationalDelegate
operator|*
operator|>
operator|(
name|this
operator|)
argument_list|)
block|;
return|return
name|combo
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|void
name|setEditorData
argument_list|(
name|QWidget
operator|*
name|editor
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
specifier|const
name|QSqlRelationalTableModel
modifier|*
name|sqlModel
init|=
name|qobject_cast
operator|<
specifier|const
name|QSqlRelationalTableModel
operator|*
operator|>
operator|(
name|index
operator|.
name|model
argument_list|()
operator|)
decl_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
name|qobject_cast
operator|<
name|QComboBox
operator|*
operator|>
operator|(
name|editor
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|sqlModel
operator|||
operator|!
name|combo
condition|)
block|{
name|QItemDelegate
operator|::
name|setEditorData
argument_list|(
name|editor
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return;
block|}
name|combo
operator|->
name|setCurrentIndex
argument_list|(
name|combo
operator|->
name|findText
argument_list|(
name|sqlModel
operator|->
name|data
argument_list|(
name|index
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|void
name|setModelData
argument_list|(
name|QWidget
operator|*
name|editor
argument_list|,
name|QAbstractItemModel
operator|*
name|model
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|index
operator|.
name|isValid
argument_list|()
condition|)
return|return;
name|QSqlRelationalTableModel
modifier|*
name|sqlModel
init|=
name|qobject_cast
operator|<
name|QSqlRelationalTableModel
operator|*
operator|>
operator|(
name|model
operator|)
decl_stmt|;
name|QSqlTableModel
modifier|*
name|childModel
init|=
name|sqlModel
condition|?
name|sqlModel
operator|->
name|relationModel
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
else|:
literal|0
decl_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
name|qobject_cast
operator|<
name|QComboBox
operator|*
operator|>
operator|(
name|editor
operator|)
decl_stmt|;
if|if
condition|(
operator|!
name|sqlModel
operator|||
operator|!
name|childModel
operator|||
operator|!
name|combo
condition|)
block|{
name|QItemDelegate
operator|::
name|setModelData
argument_list|(
name|editor
argument_list|,
name|model
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return;
block|}
name|int
name|currentItem
init|=
name|combo
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|int
name|childColIndex
init|=
name|childModel
operator|->
name|fieldIndex
argument_list|(
name|sqlModel
operator|->
name|relation
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
operator|.
name|displayColumn
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|childEditIndex
init|=
name|childModel
operator|->
name|fieldIndex
argument_list|(
name|sqlModel
operator|->
name|relation
argument_list|(
name|index
operator|.
name|column
argument_list|()
argument_list|)
operator|.
name|indexColumn
argument_list|()
argument_list|)
decl_stmt|;
name|sqlModel
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|childModel
operator|->
name|data
argument_list|(
name|childModel
operator|->
name|index
argument_list|(
name|currentItem
argument_list|,
name|childColIndex
argument_list|)
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
expr_stmt|;
name|sqlModel
operator|->
name|setData
argument_list|(
name|index
argument_list|,
name|childModel
operator|->
name|data
argument_list|(
name|childModel
operator|->
name|index
argument_list|(
name|currentItem
argument_list|,
name|childEditIndex
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
argument_list|,
name|Qt
operator|::
name|EditRole
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_GUI_LIB
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSQLRELATIONALDELEGATE_H
end_comment
end_unit
