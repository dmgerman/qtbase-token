begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGui/QtGui>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_include
include|#
directive|include
file|"modeltest.h"
end_include
begin_include
include|#
directive|include
file|"dynamictreemodel.h"
end_include
begin_class
DECL|class|tst_ModelTest
class|class
name|tst_ModelTest
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_ModelTest
name|tst_ModelTest
parameter_list|()
block|{}
DECL|function|~tst_ModelTest
specifier|virtual
name|~
name|tst_ModelTest
parameter_list|()
block|{}
public|public
name|slots
public|:
name|void
name|initTestCase
parameter_list|()
function_decl|;
name|void
name|cleanupTestCase
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|stringListModel
parameter_list|()
function_decl|;
name|void
name|treeWidgetModel
parameter_list|()
function_decl|;
name|void
name|standardItemModel
parameter_list|()
function_decl|;
name|void
name|testInsertThroughProxy
parameter_list|()
function_decl|;
name|void
name|moveSourceItems
parameter_list|()
function_decl|;
name|void
name|testResetThroughProxy
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|initTestCase
name|void
name|tst_ModelTest
operator|::
name|initTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_ModelTest
operator|::
name|cleanupTestCase
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|init
name|void
name|tst_ModelTest
operator|::
name|init
parameter_list|()
block|{  }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_ModelTest
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_comment
comment|/*   tests */
end_comment
begin_function
DECL|function|stringListModel
name|void
name|tst_ModelTest
operator|::
name|stringListModel
parameter_list|()
block|{
name|QStringListModel
name|model
decl_stmt|;
name|QSortFilterProxyModel
name|proxy
decl_stmt|;
name|ModelTest
name|t1
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|ModelTest
name|t2
argument_list|(
operator|&
name|proxy
argument_list|)
decl_stmt|;
name|proxy
operator|.
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|model
operator|.
name|setStringList
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"2"
operator|<<
literal|"3"
operator|<<
literal|"1"
argument_list|)
expr_stmt|;
name|model
operator|.
name|setStringList
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"a"
operator|<<
literal|"e"
operator|<<
literal|"plop"
operator|<<
literal|"b"
operator|<<
literal|"c"
argument_list|)
expr_stmt|;
name|proxy
operator|.
name|setDynamicSortFilter
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|proxy
operator|.
name|setFilterRegExp
argument_list|(
name|QRegExp
argument_list|(
literal|"[^b]"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|treeWidgetModel
name|void
name|tst_ModelTest
operator|::
name|treeWidgetModel
parameter_list|()
block|{
name|QTreeWidget
name|widget
decl_stmt|;
name|ModelTest
name|t1
argument_list|(
name|widget
operator|.
name|model
argument_list|()
argument_list|)
decl_stmt|;
name|QTreeWidgetItem
modifier|*
name|root
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
operator|&
name|widget
argument_list|,
name|QStringList
argument_list|(
literal|"root"
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|20
condition|;
operator|++
name|i
control|)
block|{
operator|new
name|QTreeWidgetItem
argument_list|(
name|root
argument_list|,
name|QStringList
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QTreeWidgetItem
modifier|*
name|remove
init|=
name|root
operator|->
name|child
argument_list|(
literal|2
argument_list|)
decl_stmt|;
name|root
operator|->
name|removeChild
argument_list|(
name|remove
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|parent
init|=
operator|new
name|QTreeWidgetItem
argument_list|(
operator|&
name|widget
argument_list|,
name|QStringList
argument_list|(
literal|"parent"
argument_list|)
argument_list|)
decl_stmt|;
operator|new
name|QTreeWidgetItem
argument_list|(
name|parent
argument_list|,
name|QStringList
argument_list|(
literal|"child"
argument_list|)
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setItemHidden
argument_list|(
name|parent
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|.
name|sortByColumn
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|standardItemModel
name|void
name|tst_ModelTest
operator|::
name|standardItemModel
parameter_list|()
block|{
name|QStandardItemModel
name|model
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QSortFilterProxyModel
name|proxy
decl_stmt|;
name|ModelTest
name|t1
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|ModelTest
name|t2
argument_list|(
operator|&
name|proxy
argument_list|)
decl_stmt|;
name|proxy
operator|.
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|model
operator|.
name|insertRows
argument_list|(
literal|2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|model
operator|.
name|removeRows
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|model
operator|.
name|insertColumns
argument_list|(
literal|2
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|model
operator|.
name|removeColumns
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|model
operator|.
name|insertRows
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|,
name|model
operator|.
name|index
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|model
operator|.
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|5
argument_list|,
name|model
operator|.
name|index
argument_list|(
literal|1
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testInsertThroughProxy
name|void
name|tst_ModelTest
operator|::
name|testInsertThroughProxy
parameter_list|()
block|{
name|DynamicTreeModel
modifier|*
name|model
init|=
operator|new
name|DynamicTreeModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QSortFilterProxyModel
modifier|*
name|proxy
init|=
operator|new
name|QSortFilterProxyModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|proxy
operator|->
name|setSourceModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
operator|new
name|ModelTest
argument_list|(
name|proxy
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|ModelInsertCommand
modifier|*
name|insertCommand
init|=
operator|new
name|ModelInsertCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|insertCommand
operator|->
name|setNumCols
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setEndRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
comment|// Parent is QModelIndex()
name|insertCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|insertCommand
operator|=
operator|new
name|ModelInsertCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setNumCols
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setAncestorRowNumbers
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|5
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setEndRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|ModelMoveCommand
modifier|*
name|moveCommand
init|=
operator|new
name|ModelMoveCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|moveCommand
operator|->
name|setNumCols
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setEndRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setDestRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setDestAncestors
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|5
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/**   Makes the persistent index list publicly accessible */
end_comment
begin_class
DECL|class|AccessibleProxyModel
class|class
name|AccessibleProxyModel
super|:
specifier|public
name|QSortFilterProxyModel
block|{
name|Q_OBJECT
public|public:
DECL|function|AccessibleProxyModel
name|AccessibleProxyModel
parameter_list|(
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QSortFilterProxyModel
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|persistent
name|QModelIndexList
name|persistent
parameter_list|()
block|{
return|return
name|persistentIndexList
argument_list|()
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|ObservingObject
class|class
name|ObservingObject
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|ObservingObject
name|ObservingObject
parameter_list|(
name|AccessibleProxyModel
modifier|*
name|proxy
parameter_list|,
name|QObject
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|m_proxy
argument_list|(
name|proxy
argument_list|)
member_init_list|,
name|storePersistentFailureCount
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|checkPersistentFailureCount
argument_list|(
literal|0
argument_list|)
block|{
name|connect
argument_list|(
name|m_proxy
argument_list|,
name|SIGNAL
argument_list|(
name|rowsAboutToBeMoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|QModelIndex
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|storePersistent
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|m_proxy
argument_list|,
name|SIGNAL
argument_list|(
name|rowsMoved
argument_list|(
name|QModelIndex
argument_list|,
name|int
argument_list|,
name|int
argument_list|,
name|QModelIndex
argument_list|,
name|int
argument_list|)
argument_list|)
argument_list|,
name|SLOT
argument_list|(
name|checkPersistent
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
public|public
name|slots
public|:
DECL|function|storePersistent
name|void
name|storePersistent
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|m_proxy
operator|->
name|rowCount
argument_list|(
name|parent
argument_list|)
condition|;
operator|++
name|row
control|)
block|{
name|QModelIndex
name|proxyIndex
init|=
name|m_proxy
operator|->
name|index
argument_list|(
name|row
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
decl_stmt|;
name|QModelIndex
name|sourceIndex
init|=
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proxyIndex
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: Invalid proxy index"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
operator|++
name|storePersistentFailureCount
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|sourceIndex
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: invalid source index"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
operator|++
name|storePersistentFailureCount
expr_stmt|;
block|}
name|m_persistentSourceIndexes
operator|.
name|append
argument_list|(
name|sourceIndex
argument_list|)
expr_stmt|;
name|m_persistentProxyIndexes
operator|.
name|append
argument_list|(
name|proxyIndex
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_proxy
operator|->
name|hasChildren
argument_list|(
name|proxyIndex
argument_list|)
condition|)
name|storePersistent
argument_list|(
name|proxyIndex
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|storePersistent
name|void
name|storePersistent
parameter_list|()
block|{
comment|// This method is called from rowsAboutToBeMoved. Persistent indexes should be valid
foreach|foreach
control|(
specifier|const
name|QModelIndex
modifier|&
name|idx
decl|,
name|m_persistentProxyIndexes
control|)
if|if
condition|(
operator|!
name|idx
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: persistentProxyIndexes contains invalid index"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
operator|++
name|storePersistentFailureCount
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|m_proxy
operator|->
name|persistent
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: proxy should have no persistent indexes when storePersistent called"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
operator|++
name|storePersistentFailureCount
expr_stmt|;
block|}
name|storePersistent
argument_list|(
name|QModelIndex
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|m_proxy
operator|->
name|persistent
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: proxy should have persistent index after storePersistent called"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
operator|++
name|storePersistentFailureCount
expr_stmt|;
block|}
block|}
DECL|function|checkPersistent
name|void
name|checkPersistent
parameter_list|()
block|{
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|m_persistentProxyIndexes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
name|m_persistentProxyIndexes
operator|.
name|at
argument_list|(
name|row
argument_list|)
expr_stmt|;
name|m_persistentSourceIndexes
operator|.
name|at
argument_list|(
name|row
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|m_persistentProxyIndexes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|row
control|)
block|{
name|QModelIndex
name|updatedProxy
init|=
name|m_persistentProxyIndexes
operator|.
name|at
argument_list|(
name|row
argument_list|)
decl_stmt|;
name|QModelIndex
name|updatedSource
init|=
name|m_persistentSourceIndexes
operator|.
name|at
argument_list|(
name|row
argument_list|)
decl_stmt|;
if|if
condition|(
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|updatedProxy
argument_list|)
operator|!=
name|updatedSource
condition|)
block|{
name|qWarning
argument_list|(
literal|"%s: check failed at row %d"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|row
argument_list|)
expr_stmt|;
operator|++
name|checkPersistentFailureCount
expr_stmt|;
block|}
block|}
name|m_persistentSourceIndexes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_persistentProxyIndexes
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|m_proxy
name|AccessibleProxyModel
modifier|*
name|m_proxy
decl_stmt|;
DECL|member|m_persistentSourceIndexes
name|QList
argument_list|<
name|QPersistentModelIndex
argument_list|>
name|m_persistentSourceIndexes
decl_stmt|;
DECL|member|m_persistentProxyIndexes
name|QList
argument_list|<
name|QPersistentModelIndex
argument_list|>
name|m_persistentProxyIndexes
decl_stmt|;
public|public:
DECL|member|storePersistentFailureCount
name|int
name|storePersistentFailureCount
decl_stmt|;
DECL|member|checkPersistentFailureCount
name|int
name|checkPersistentFailureCount
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|moveSourceItems
name|void
name|tst_ModelTest
operator|::
name|moveSourceItems
parameter_list|()
block|{
name|DynamicTreeModel
modifier|*
name|model
init|=
operator|new
name|DynamicTreeModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|AccessibleProxyModel
modifier|*
name|proxy
init|=
operator|new
name|AccessibleProxyModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|proxy
operator|->
name|setSourceModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|ModelInsertCommand
modifier|*
name|insertCommand
init|=
operator|new
name|ModelInsertCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|insertCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setEndRow
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|insertCommand
operator|=
operator|new
name|ModelInsertCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setAncestorRowNumbers
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|1
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setEndRow
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|ObservingObject
name|observer
argument_list|(
name|proxy
argument_list|)
decl_stmt|;
name|ModelMoveCommand
modifier|*
name|moveCommand
init|=
operator|new
name|ModelMoveCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|moveCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setEndRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setDestAncestors
argument_list|(
name|QList
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|1
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|setDestRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|moveCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|observer
operator|.
name|storePersistentFailureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|observer
operator|.
name|checkPersistentFailureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testResetThroughProxy
name|void
name|tst_ModelTest
operator|::
name|testResetThroughProxy
parameter_list|()
block|{
name|DynamicTreeModel
modifier|*
name|model
init|=
operator|new
name|DynamicTreeModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|ModelInsertCommand
modifier|*
name|insertCommand
init|=
operator|new
name|ModelInsertCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|insertCommand
operator|->
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|setEndRow
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|insertCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|QPersistentModelIndex
name|persistent
init|=
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|AccessibleProxyModel
modifier|*
name|proxy
init|=
operator|new
name|AccessibleProxyModel
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|proxy
operator|->
name|setSourceModel
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|ObservingObject
name|observer
argument_list|(
name|proxy
argument_list|)
decl_stmt|;
name|observer
operator|.
name|storePersistent
argument_list|()
expr_stmt|;
name|ModelResetCommand
modifier|*
name|resetCommand
init|=
operator|new
name|ModelResetCommand
argument_list|(
name|model
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|resetCommand
operator|->
name|setNumCols
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|resetCommand
operator|->
name|doCommand
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|observer
operator|.
name|storePersistentFailureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|observer
operator|.
name|checkPersistentFailureCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_ModelTest
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_modeltest.moc"
end_include
end_unit
