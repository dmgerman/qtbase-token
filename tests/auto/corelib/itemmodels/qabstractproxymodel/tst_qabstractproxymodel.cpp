begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qabstractproxymodel.h>
end_include
begin_include
include|#
directive|include
file|<QItemSelection>
end_include
begin_include
include|#
directive|include
file|<qstandarditemmodel.h>
end_include
begin_class
DECL|class|tst_QAbstractProxyModel
class|class
name|tst_QAbstractProxyModel
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|qabstractproxymodel
parameter_list|()
function_decl|;
name|void
name|data_data
parameter_list|()
function_decl|;
name|void
name|data
parameter_list|()
function_decl|;
name|void
name|flags_data
parameter_list|()
function_decl|;
name|void
name|flags
parameter_list|()
function_decl|;
name|void
name|headerData_data
parameter_list|()
function_decl|;
name|void
name|headerData
parameter_list|()
function_decl|;
name|void
name|itemData_data
parameter_list|()
function_decl|;
name|void
name|itemData
parameter_list|()
function_decl|;
name|void
name|mapFromSource_data
parameter_list|()
function_decl|;
name|void
name|mapFromSource
parameter_list|()
function_decl|;
name|void
name|mapSelectionFromSource_data
parameter_list|()
function_decl|;
name|void
name|mapSelectionFromSource
parameter_list|()
function_decl|;
name|void
name|mapSelectionToSource_data
parameter_list|()
function_decl|;
name|void
name|mapSelectionToSource
parameter_list|()
function_decl|;
name|void
name|mapToSource_data
parameter_list|()
function_decl|;
name|void
name|mapToSource
parameter_list|()
function_decl|;
name|void
name|revert
parameter_list|()
function_decl|;
name|void
name|setSourceModel
parameter_list|()
function_decl|;
name|void
name|submit_data
parameter_list|()
function_decl|;
name|void
name|submit
parameter_list|()
function_decl|;
name|void
name|testRoleNames
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Subclass that exposes the protected functions.
end_comment
begin_class
DECL|class|SubQAbstractProxyModel
class|class
name|SubQAbstractProxyModel
super|:
specifier|public
name|QAbstractProxyModel
block|{
public|public:
comment|// QAbstractProxyModel::mapFromSource is a pure virtual function.
DECL|function|mapFromSource
name|QModelIndex
name|mapFromSource
parameter_list|(
name|QModelIndex
specifier|const
modifier|&
name|sourceIndex
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|sourceIndex
argument_list|)
expr_stmt|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
comment|// QAbstractProxyModel::mapToSource is a pure virtual function.
DECL|function|mapToSource
name|QModelIndex
name|mapToSource
parameter_list|(
name|QModelIndex
specifier|const
modifier|&
name|proxyIndex
parameter_list|)
specifier|const
block|{
name|Q_UNUSED
argument_list|(
name|proxyIndex
argument_list|)
expr_stmt|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
DECL|function|index
name|QModelIndex
name|index
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
DECL|function|parent
name|QModelIndex
name|parent
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|QModelIndex
argument_list|()
return|;
block|}
DECL|function|rowCount
name|int
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
DECL|function|columnCount
name|int
name|columnCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
literal|0
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|qabstractproxymodel
name|void
name|tst_QAbstractProxyModel
operator|::
name|qabstractproxymodel
parameter_list|()
block|{
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|model
operator|.
name|data
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|flags
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|headerData
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Vertical
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|model
operator|.
name|itemData
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|mapFromSource
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|mapSelectionFromSource
argument_list|(
name|QItemSelection
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|mapSelectionToSource
argument_list|(
name|QItemSelection
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|mapToSource
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|revert
argument_list|()
expr_stmt|;
name|model
operator|.
name|setSourceModel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|sourceModel
argument_list|()
argument_list|,
operator|(
name|QAbstractItemModel
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|model
operator|.
name|submit
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QVariant
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QModelIndex
argument_list|)
end_macro
begin_function
DECL|function|data_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|data_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"proxyIndex"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"role"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"data"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QModelIndex
argument_list|()
operator|<<
literal|0
operator|<<
name|QVariant
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QVariant data(QModelIndex const& proxyIndex, int role = Qt::DisplayRole) const
end_comment
begin_function
DECL|function|data
name|void
name|tst_QAbstractProxyModel
operator|::
name|data
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|proxyIndex
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|role
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|data
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|data
argument_list|(
name|proxyIndex
argument_list|,
name|role
argument_list|)
argument_list|,
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::ItemFlags
argument_list|)
end_macro
begin_function
DECL|function|flags_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|flags_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"index"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|ItemFlags
argument_list|>
argument_list|(
literal|"flags"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QModelIndex
argument_list|()
operator|<<
operator|(
name|Qt
operator|::
name|ItemFlags
operator|)
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|// public Qt::ItemFlags flags(QModelIndex const& index) const
end_comment
begin_function
DECL|function|flags
name|void
name|tst_QAbstractProxyModel
operator|::
name|flags
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|ItemFlags
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|flags
argument_list|(
name|index
argument_list|)
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::Orientation
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|Qt::ItemDataRole
argument_list|)
end_macro
begin_function
DECL|function|headerData_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|headerData_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"section"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|Orientation
argument_list|>
argument_list|(
literal|"orientation"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|Qt
operator|::
name|ItemDataRole
argument_list|>
argument_list|(
literal|"role"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QVariant
argument_list|>
argument_list|(
literal|"headerData"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
literal|0
operator|<<
name|Qt
operator|::
name|Vertical
operator|<<
name|Qt
operator|::
name|UserRole
operator|<<
name|QVariant
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QVariant headerData(int section, Qt::Orientation orientation, int role) const
end_comment
begin_function
DECL|function|headerData
name|void
name|tst_QAbstractProxyModel
operator|::
name|headerData
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|section
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|Orientation
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|Qt
operator|::
name|ItemDataRole
argument_list|,
name|role
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QVariant
argument_list|,
name|headerData
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|headerData
argument_list|(
name|section
argument_list|,
name|orientation
argument_list|,
name|role
argument_list|)
argument_list|,
name|headerData
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|itemData_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|itemData_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"index"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QModelIndex
argument_list|()
operator|<<
literal|0
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QMap<int,QVariant> itemData(QModelIndex const& index) const
end_comment
begin_function
DECL|function|itemData
name|void
name|tst_QAbstractProxyModel
operator|::
name|itemData
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|itemData
argument_list|(
name|index
argument_list|)
operator|.
name|count
argument_list|()
argument_list|,
name|count
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapFromSource_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapFromSource_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"sourceIndex"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"mapFromSource"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QModelIndex
argument_list|()
operator|<<
name|QModelIndex
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QModelIndex mapFromSource(QModelIndex const& sourceIndex) const
end_comment
begin_function
DECL|function|mapFromSource
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapFromSource
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|sourceIndex
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|mapFromSource
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|mapFromSource
argument_list|(
name|sourceIndex
argument_list|)
argument_list|,
name|mapFromSource
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QItemSelection
argument_list|)
end_macro
begin_function
DECL|function|mapSelectionFromSource_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapSelectionFromSource_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QItemSelection
argument_list|>
argument_list|(
literal|"selection"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QItemSelection
argument_list|>
argument_list|(
literal|"mapSelectionFromSource"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QItemSelection
argument_list|()
operator|<<
name|QItemSelection
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty"
argument_list|)
operator|<<
name|QItemSelection
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
operator|<<
name|QItemSelection
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QItemSelection mapSelectionFromSource(QItemSelection const& selection) const
end_comment
begin_function
DECL|function|mapSelectionFromSource
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapSelectionFromSource
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QItemSelection
argument_list|,
name|selection
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QItemSelection
argument_list|,
name|mapSelectionFromSource
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|mapSelectionFromSource
argument_list|(
name|selection
argument_list|)
argument_list|,
name|mapSelectionFromSource
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapSelectionToSource_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapSelectionToSource_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QItemSelection
argument_list|>
argument_list|(
literal|"selection"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QItemSelection
argument_list|>
argument_list|(
literal|"mapSelectionToSource"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QItemSelection
argument_list|()
operator|<<
name|QItemSelection
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty"
argument_list|)
operator|<<
name|QItemSelection
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
operator|<<
name|QItemSelection
argument_list|(
name|QModelIndex
argument_list|()
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QItemSelection mapSelectionToSource(QItemSelection const& selection) const
end_comment
begin_function
DECL|function|mapSelectionToSource
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapSelectionToSource
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QItemSelection
argument_list|,
name|selection
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QItemSelection
argument_list|,
name|mapSelectionToSource
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|mapSelectionToSource
argument_list|(
name|selection
argument_list|)
argument_list|,
name|mapSelectionToSource
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapToSource_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapToSource_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"proxyIndex"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QModelIndex
argument_list|>
argument_list|(
literal|"mapToSource"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
name|QModelIndex
argument_list|()
operator|<<
name|QModelIndex
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public QModelIndex mapToSource(QModelIndex const& proxyIndex) const
end_comment
begin_function
DECL|function|mapToSource
name|void
name|tst_QAbstractProxyModel
operator|::
name|mapToSource
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|proxyIndex
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QModelIndex
argument_list|,
name|mapToSource
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
argument_list|,
name|mapToSource
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// public void revert()
end_comment
begin_function
DECL|function|revert
name|void
name|tst_QAbstractProxyModel
operator|::
name|revert
parameter_list|()
block|{
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|model
operator|.
name|revert
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|// public void setSourceModel(QAbstractItemModel* sourceModel)
end_comment
begin_function
DECL|function|setSourceModel
name|void
name|tst_QAbstractProxyModel
operator|::
name|setSourceModel
parameter_list|()
block|{
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QStandardItemModel
modifier|*
name|sourceModel
init|=
operator|new
name|QStandardItemModel
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|model
operator|.
name|setSourceModel
argument_list|(
name|sourceModel
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|sourceModel
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAbstractItemModel
operator|*
argument_list|>
argument_list|(
name|sourceModel
argument_list|)
argument_list|)
expr_stmt|;
name|QStandardItemModel
modifier|*
name|sourceModel2
init|=
operator|new
name|QStandardItemModel
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|model
operator|.
name|setSourceModel
argument_list|(
name|sourceModel2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|sourceModel
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAbstractItemModel
operator|*
argument_list|>
argument_list|(
name|sourceModel2
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|sourceModel2
expr_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|sourceModel
argument_list|()
argument_list|,
cast|static_cast
argument_list|<
name|QAbstractItemModel
operator|*
argument_list|>
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|submit_data
name|void
name|tst_QAbstractProxyModel
operator|::
name|submit_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"submit"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|// public bool submit()
end_comment
begin_function
DECL|function|submit
name|void
name|tst_QAbstractProxyModel
operator|::
name|submit
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|submit
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|model
decl_stmt|;
name|QCOMPARE
argument_list|(
name|model
operator|.
name|submit
argument_list|()
argument_list|,
name|submit
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|StandardItemModelWithCustomRoleNames
class|class
name|StandardItemModelWithCustomRoleNames
super|:
specifier|public
name|QStandardItemModel
block|{
public|public:
DECL|enum|CustomRole
enum|enum
name|CustomRole
block|{
DECL|enumerator|CustomRole1
name|CustomRole1
init|=
name|Qt
operator|::
name|UserRole
block|,
DECL|enumerator|CustomRole2
name|CustomRole2
block|}
enum|;
DECL|function|StandardItemModelWithCustomRoleNames
name|StandardItemModelWithCustomRoleNames
parameter_list|()
block|{
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
name|_roleNames
init|=
name|roleNames
argument_list|()
decl_stmt|;
name|_roleNames
operator|.
name|insert
argument_list|(
name|CustomRole1
argument_list|,
literal|"custom1"
argument_list|)
expr_stmt|;
name|_roleNames
operator|.
name|insert
argument_list|(
name|CustomRole2
argument_list|,
literal|"custom2"
argument_list|)
expr_stmt|;
name|setRoleNames
argument_list|(
name|_roleNames
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|AnotherStandardItemModelWithCustomRoleNames
class|class
name|AnotherStandardItemModelWithCustomRoleNames
super|:
specifier|public
name|QStandardItemModel
block|{
public|public:
DECL|enum|CustomRole
enum|enum
name|CustomRole
block|{
DECL|enumerator|AnotherCustomRole1
name|AnotherCustomRole1
init|=
name|Qt
operator|::
name|UserRole
operator|+
literal|10
block|,
comment|// Different to StandardItemModelWithCustomRoleNames::CustomRole1
DECL|enumerator|AnotherCustomRole2
name|AnotherCustomRole2
block|}
enum|;
DECL|function|AnotherStandardItemModelWithCustomRoleNames
name|AnotherStandardItemModelWithCustomRoleNames
parameter_list|()
block|{
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
name|_roleNames
init|=
name|roleNames
argument_list|()
decl_stmt|;
name|_roleNames
operator|.
name|insert
argument_list|(
name|AnotherCustomRole1
argument_list|,
literal|"another_custom1"
argument_list|)
expr_stmt|;
name|_roleNames
operator|.
name|insert
argument_list|(
name|AnotherCustomRole2
argument_list|,
literal|"another_custom2"
argument_list|)
expr_stmt|;
name|setRoleNames
argument_list|(
name|_roleNames
argument_list|)
expr_stmt|;
block|}
block|}
class|;
end_class
begin_comment
comment|/**     Verifies that @p subSet is a subset of @p superSet. That is, all keys in @p subSet exist in @p superSet and have the same values. */
end_comment
begin_function
DECL|function|verifySubSetOf
specifier|static
name|void
name|verifySubSetOf
parameter_list|(
specifier|const
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
modifier|&
name|superSet
parameter_list|,
specifier|const
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
modifier|&
name|subSet
parameter_list|)
block|{
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|subSet
operator|.
name|constBegin
argument_list|()
decl_stmt|;
specifier|const
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
operator|::
name|const_iterator
name|end
init|=
name|subSet
operator|.
name|constEnd
argument_list|()
decl_stmt|;
for|for
control|(
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|QVERIFY
argument_list|(
name|superSet
operator|.
name|contains
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|it
operator|.
name|value
argument_list|()
operator|==
name|superSet
operator|.
name|value
argument_list|(
name|it
operator|.
name|key
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|testRoleNames
name|void
name|tst_QAbstractProxyModel
operator|::
name|testRoleNames
parameter_list|()
block|{
name|QStandardItemModel
name|defaultModel
decl_stmt|;
name|StandardItemModelWithCustomRoleNames
name|model
decl_stmt|;
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
name|rootModelRoleNames
init|=
name|model
operator|.
name|roleNames
argument_list|()
decl_stmt|;
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
name|defaultModelRoleNames
init|=
name|defaultModel
operator|.
name|roleNames
argument_list|()
decl_stmt|;
name|verifySubSetOf
argument_list|(
name|rootModelRoleNames
argument_list|,
name|defaultModelRoleNames
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rootModelRoleNames
operator|.
name|size
argument_list|()
operator|==
name|defaultModelRoleNames
operator|.
name|size
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rootModelRoleNames
operator|.
name|contains
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rootModelRoleNames
operator|.
name|contains
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rootModelRoleNames
operator|.
name|value
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole1
argument_list|)
operator|==
literal|"custom1"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rootModelRoleNames
operator|.
name|value
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole2
argument_list|)
operator|==
literal|"custom2"
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|proxy1
decl_stmt|;
name|proxy1
operator|.
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
name|proxy1RoleNames
init|=
name|proxy1
operator|.
name|roleNames
argument_list|()
decl_stmt|;
name|verifySubSetOf
argument_list|(
name|proxy1RoleNames
argument_list|,
name|defaultModelRoleNames
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy1RoleNames
operator|.
name|size
argument_list|()
operator|==
name|defaultModelRoleNames
operator|.
name|size
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy1RoleNames
operator|.
name|contains
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy1RoleNames
operator|.
name|contains
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy1RoleNames
operator|.
name|value
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole1
argument_list|)
operator|==
literal|"custom1"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy1RoleNames
operator|.
name|value
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole2
argument_list|)
operator|==
literal|"custom2"
argument_list|)
expr_stmt|;
name|SubQAbstractProxyModel
name|proxy2
decl_stmt|;
name|proxy2
operator|.
name|setSourceModel
argument_list|(
operator|&
name|proxy1
argument_list|)
expr_stmt|;
name|QHash
argument_list|<
name|int
argument_list|,
name|QByteArray
argument_list|>
name|proxy2RoleNames
init|=
name|proxy2
operator|.
name|roleNames
argument_list|()
decl_stmt|;
name|verifySubSetOf
argument_list|(
name|proxy2RoleNames
argument_list|,
name|defaultModelRoleNames
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy2RoleNames
operator|.
name|size
argument_list|()
operator|==
name|defaultModelRoleNames
operator|.
name|size
argument_list|()
operator|+
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy2RoleNames
operator|.
name|contains
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy2RoleNames
operator|.
name|contains
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy2RoleNames
operator|.
name|value
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole1
argument_list|)
operator|==
literal|"custom1"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxy2RoleNames
operator|.
name|value
argument_list|(
name|StandardItemModelWithCustomRoleNames
operator|::
name|CustomRole2
argument_list|)
operator|==
literal|"custom2"
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QAbstractProxyModel
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qabstractproxymodel.moc"
end_include
end_unit
