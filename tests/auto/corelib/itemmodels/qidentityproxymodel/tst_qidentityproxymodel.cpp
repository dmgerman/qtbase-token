begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 KlarÃ¤lvdalens Datakonsult AB, a KDAB Group company, info@kdab.com, author Stephen Kelly<stephen.kelly@kdab.com> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtCore/QCoreApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QStandardItemModel>
end_include
begin_include
include|#
directive|include
file|"dynamictreemodel.h"
end_include
begin_include
include|#
directive|include
file|"qidentityproxymodel.h"
end_include
begin_class
DECL|class|DataChangedModel
class|class
name|DataChangedModel
super|:
specifier|public
name|QAbstractListModel
block|{
public|public:
DECL|function|rowCount
name|int
name|rowCount
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
return|return
name|parent
operator|.
name|isValid
argument_list|()
condition|?
literal|0
else|:
literal|1
return|;
block|}
DECL|function|data
name|QVariant
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
parameter_list|,
name|int
parameter_list|)
specifier|const
block|{
return|return
name|QVariant
argument_list|()
return|;
block|}
DECL|function|index
name|QModelIndex
name|index
parameter_list|(
name|int
name|row
parameter_list|,
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
parameter_list|)
specifier|const
block|{
return|return
name|createIndex
argument_list|(
name|row
argument_list|,
name|column
argument_list|)
return|;
block|}
DECL|function|changeData
name|void
name|changeData
parameter_list|()
block|{
specifier|const
name|QModelIndex
name|idx
init|=
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
name|Q_EMIT
name|dataChanged
argument_list|(
name|idx
argument_list|,
name|idx
argument_list|,
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|1
argument_list|)
decl_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|tst_QIdentityProxyModel
class|class
name|tst_QIdentityProxyModel
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QIdentityProxyModel
parameter_list|()
constructor_decl|;
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
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|insertRows
parameter_list|()
function_decl|;
name|void
name|removeRows
parameter_list|()
function_decl|;
name|void
name|moveRows
parameter_list|()
function_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
name|void
name|dataChanged
parameter_list|()
function_decl|;
name|void
name|itemData
parameter_list|()
function_decl|;
protected|protected:
name|void
name|verifyIdentity
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
init|=
name|QModelIndex
argument_list|()
parameter_list|)
function_decl|;
private|private:
DECL|member|m_model
name|QStandardItemModel
modifier|*
name|m_model
decl_stmt|;
DECL|member|m_proxy
name|QIdentityProxyModel
modifier|*
name|m_proxy
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QIdentityProxyModel
name|tst_QIdentityProxyModel
operator|::
name|tst_QIdentityProxyModel
parameter_list|()
member_init_list|:
name|m_model
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|m_proxy
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|initTestCase
name|void
name|tst_QIdentityProxyModel
operator|::
name|initTestCase
parameter_list|()
block|{
name|qRegisterMetaType
argument_list|<
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
expr_stmt|;
name|m_model
operator|=
operator|new
name|QStandardItemModel
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|m_proxy
operator|=
operator|new
name|QIdentityProxyModel
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanupTestCase
name|void
name|tst_QIdentityProxyModel
operator|::
name|cleanupTestCase
parameter_list|()
block|{
operator|delete
name|m_proxy
expr_stmt|;
operator|delete
name|m_model
expr_stmt|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QIdentityProxyModel
operator|::
name|cleanup
parameter_list|()
block|{
name|m_model
operator|->
name|clear
argument_list|()
expr_stmt|;
name|m_model
operator|->
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|verifyIdentity
name|void
name|tst_QIdentityProxyModel
operator|::
name|verifyIdentity
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
specifier|const
name|int
name|rows
init|=
name|model
operator|->
name|rowCount
argument_list|(
name|parent
argument_list|)
decl_stmt|;
specifier|const
name|int
name|columns
init|=
name|model
operator|->
name|columnCount
argument_list|(
name|parent
argument_list|)
decl_stmt|;
specifier|const
name|QModelIndex
name|proxyParent
init|=
name|m_proxy
operator|->
name|mapFromSource
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyParent
argument_list|)
operator|==
name|parent
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|rows
operator|==
name|m_proxy
operator|->
name|rowCount
argument_list|(
name|proxyParent
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|columns
operator|==
name|m_proxy
operator|->
name|columnCount
argument_list|(
name|proxyParent
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
literal|0
init|;
name|row
operator|<
name|rows
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|column
init|=
literal|0
init|;
name|column
operator|<
name|columns
condition|;
operator|++
name|column
control|)
block|{
specifier|const
name|QModelIndex
name|idx
init|=
name|model
operator|->
name|index
argument_list|(
name|row
argument_list|,
name|column
argument_list|,
name|parent
argument_list|)
decl_stmt|;
specifier|const
name|QModelIndex
name|proxyIdx
init|=
name|m_proxy
operator|->
name|mapFromSource
argument_list|(
name|idx
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|model
argument_list|()
operator|==
name|m_proxy
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyIdx
argument_list|)
operator|==
name|idx
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|row
argument_list|()
operator|==
name|row
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|column
argument_list|()
operator|==
name|column
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|parent
argument_list|()
operator|==
name|proxyParent
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|data
argument_list|()
operator|==
name|idx
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyIdx
operator|.
name|flags
argument_list|()
operator|==
name|idx
operator|.
name|flags
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|int
name|childCount
init|=
name|m_proxy
operator|->
name|rowCount
argument_list|(
name|proxyIdx
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|hasChildren
init|=
name|m_proxy
operator|->
name|hasChildren
argument_list|(
name|proxyIdx
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|model
operator|->
name|hasChildren
argument_list|(
name|idx
argument_list|)
operator|==
name|hasChildren
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|(
name|childCount
operator|>
literal|0
operator|)
operator|==
name|hasChildren
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasChildren
condition|)
name|verifyIdentity
argument_list|(
name|model
argument_list|,
name|idx
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|/*   tests */
end_comment
begin_function
DECL|function|insertRows
name|void
name|tst_QIdentityProxyModel
operator|::
name|insertRows
parameter_list|()
block|{
name|QStandardItem
modifier|*
name|parentItem
init|=
name|m_model
operator|->
name|invisibleRootItem
argument_list|()
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
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|QString
argument_list|(
literal|"item %0"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|parentItem
operator|->
name|appendRow
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|parentItem
operator|=
name|item
expr_stmt|;
block|}
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
name|QSignalSpy
name|modelBeforeSpy
argument_list|(
name|m_model
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsAboutToBeInserted
argument_list|)
decl_stmt|;
name|QSignalSpy
name|modelAfterSpy
argument_list|(
name|m_model
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsInserted
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyBeforeSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsAboutToBeInserted
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyAfterSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsInserted
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|QString
argument_list|(
literal|"new item"
argument_list|)
argument_list|)
decl_stmt|;
name|parentItem
operator|->
name|appendRow
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyBeforeSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyAfterSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeRows
name|void
name|tst_QIdentityProxyModel
operator|::
name|removeRows
parameter_list|()
block|{
name|QStandardItem
modifier|*
name|parentItem
init|=
name|m_model
operator|->
name|invisibleRootItem
argument_list|()
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
literal|4
condition|;
operator|++
name|i
control|)
block|{
name|QStandardItem
modifier|*
name|item
init|=
operator|new
name|QStandardItem
argument_list|(
name|QString
argument_list|(
literal|"item %0"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
name|parentItem
operator|->
name|appendRow
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|parentItem
operator|=
name|item
expr_stmt|;
block|}
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
name|QSignalSpy
name|modelBeforeSpy
argument_list|(
name|m_model
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsAboutToBeRemoved
argument_list|)
decl_stmt|;
name|QSignalSpy
name|modelAfterSpy
argument_list|(
name|m_model
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsRemoved
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyBeforeSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsAboutToBeRemoved
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyAfterSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QStandardItemModel
operator|::
name|rowsRemoved
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|QModelIndex
name|topLevel
init|=
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|QModelIndex
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QModelIndex
name|secondLevel
init|=
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|topLevel
argument_list|)
decl_stmt|;
specifier|const
name|QModelIndex
name|thirdLevel
init|=
name|m_model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|secondLevel
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|thirdLevel
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|m_model
operator|->
name|removeRow
argument_list|(
literal|0
argument_list|,
name|secondLevel
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyBeforeSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyAfterSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
name|m_model
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|moveRows
name|void
name|tst_QIdentityProxyModel
operator|::
name|moveRows
parameter_list|()
block|{
name|DynamicTreeModel
name|model
decl_stmt|;
block|{
name|ModelInsertCommand
name|insertCommand
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|insertCommand
operator|.
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|setEndRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|doCommand
argument_list|()
expr_stmt|;
block|}
block|{
name|ModelInsertCommand
name|insertCommand
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|insertCommand
operator|.
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
operator|.
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|setEndRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|doCommand
argument_list|()
expr_stmt|;
block|}
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QSignalSpy
name|modelBeforeSpy
argument_list|(
operator|&
name|model
argument_list|,
operator|&
name|DynamicTreeModel
operator|::
name|rowsAboutToBeMoved
argument_list|)
decl_stmt|;
name|QSignalSpy
name|modelAfterSpy
argument_list|(
operator|&
name|model
argument_list|,
operator|&
name|DynamicTreeModel
operator|::
name|rowsMoved
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyBeforeSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QIdentityProxyModel
operator|::
name|rowsAboutToBeMoved
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyAfterSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QIdentityProxyModel
operator|::
name|rowsMoved
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|ModelMoveCommand
name|moveCommand
argument_list|(
operator|&
name|model
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|moveCommand
operator|.
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
name|moveCommand
operator|.
name|setStartRow
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|moveCommand
operator|.
name|setEndRow
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|moveCommand
operator|.
name|setDestRow
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|moveCommand
operator|.
name|doCommand
argument_list|()
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyBeforeSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyAfterSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|4
argument_list|)
operator|==
name|proxyBeforeSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|first
argument_list|()
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
operator|==
name|m_proxy
operator|->
name|mapToSource
argument_list|(
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|3
argument_list|)
operator|.
name|value
argument_list|<
name|QModelIndex
argument_list|>
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|4
argument_list|)
operator|==
name|proxyAfterSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|4
argument_list|)
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|tst_QIdentityProxyModel
operator|::
name|reset
parameter_list|()
block|{
name|DynamicTreeModel
name|model
decl_stmt|;
block|{
name|ModelInsertCommand
name|insertCommand
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|insertCommand
operator|.
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|setEndRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|doCommand
argument_list|()
expr_stmt|;
block|}
block|{
name|ModelInsertCommand
name|insertCommand
argument_list|(
operator|&
name|model
argument_list|)
decl_stmt|;
name|insertCommand
operator|.
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
operator|.
name|setStartRow
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|setEndRow
argument_list|(
literal|9
argument_list|)
expr_stmt|;
name|insertCommand
operator|.
name|doCommand
argument_list|()
expr_stmt|;
block|}
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QSignalSpy
name|modelBeforeSpy
argument_list|(
operator|&
name|model
argument_list|,
operator|&
name|DynamicTreeModel
operator|::
name|modelAboutToBeReset
argument_list|)
decl_stmt|;
name|QSignalSpy
name|modelAfterSpy
argument_list|(
operator|&
name|model
argument_list|,
operator|&
name|DynamicTreeModel
operator|::
name|modelReset
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyBeforeSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QIdentityProxyModel
operator|::
name|modelAboutToBeReset
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxyAfterSpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QIdentityProxyModel
operator|::
name|modelReset
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyBeforeSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxyAfterSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|{
name|ModelResetCommandFixed
name|resetCommand
argument_list|(
operator|&
name|model
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|resetCommand
operator|.
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
name|resetCommand
operator|.
name|setStartRow
argument_list|(
literal|3
argument_list|)
expr_stmt|;
name|resetCommand
operator|.
name|setEndRow
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|resetCommand
operator|.
name|setDestRow
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|resetCommand
operator|.
name|doCommand
argument_list|()
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|modelBeforeSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyBeforeSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelAfterSpy
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|&&
literal|1
operator|==
name|proxyAfterSpy
operator|.
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|dataChanged
name|void
name|tst_QIdentityProxyModel
operator|::
name|dataChanged
parameter_list|()
block|{
name|DataChangedModel
name|model
decl_stmt|;
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|QSignalSpy
name|modelSpy
argument_list|(
operator|&
name|model
argument_list|,
operator|&
name|DataChangedModel
operator|::
name|dataChanged
argument_list|)
decl_stmt|;
name|QSignalSpy
name|proxySpy
argument_list|(
name|m_proxy
argument_list|,
operator|&
name|QIdentityProxyModel
operator|::
name|dataChanged
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|modelSpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|proxySpy
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|model
operator|.
name|changeData
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|modelSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|.
name|value
argument_list|<
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|>
argument_list|()
argument_list|,
name|QVector
argument_list|<
name|int
argument_list|>
argument_list|()
operator|<<
literal|1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|modelSpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|proxySpy
operator|.
name|first
argument_list|()
operator|.
name|at
argument_list|(
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|verifyIdentity
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
name|m_proxy
operator|->
name|setSourceModel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|AppendStringProxy
class|class
name|AppendStringProxy
super|:
specifier|public
name|QIdentityProxyModel
block|{
public|public:
DECL|function|data
name|QVariant
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
specifier|const
name|QVariant
name|result
init|=
name|sourceModel
argument_list|()
operator|->
name|data
argument_list|(
name|index
argument_list|,
name|role
argument_list|)
decl_stmt|;
if|if
condition|(
name|role
operator|!=
name|Qt
operator|::
name|DisplayRole
condition|)
return|return
name|result
return|;
return|return
name|result
operator|.
name|toString
argument_list|()
operator|+
literal|"_appended"
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|itemData
name|void
name|tst_QIdentityProxyModel
operator|::
name|itemData
parameter_list|()
block|{
name|QStringListModel
name|model
argument_list|(
name|QStringList
argument_list|()
operator|<<
literal|"Monday"
operator|<<
literal|"Tuesday"
operator|<<
literal|"Wednesday"
argument_list|)
decl_stmt|;
name|AppendStringProxy
name|proxy
decl_stmt|;
name|proxy
operator|.
name|setSourceModel
argument_list|(
operator|&
name|model
argument_list|)
expr_stmt|;
specifier|const
name|QModelIndex
name|topIndex
init|=
name|proxy
operator|.
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|topIndex
operator|.
name|data
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Monday_appended"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|proxy
operator|.
name|data
argument_list|(
name|topIndex
argument_list|,
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Monday_appended"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|proxy
operator|.
name|itemData
argument_list|(
name|topIndex
argument_list|)
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|DisplayRole
argument_list|)
operator|.
name|toString
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Monday_appended"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QIdentityProxyModel
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qidentityproxymodel.moc"
end_include
end_unit
