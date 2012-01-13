begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<QtSql/QtSql>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QtWidgets>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSortFilterProxyModel>
end_include
begin_comment
comment|/*     To add a model to be tested add the header file to the includes     and impliment what is needed in the four functions below.      You can add more then one model, several Qt models and included as examples.      In tst_qitemmodel.cpp a new ModelsToTest object is created for each test.      When you have errors fix the first ones first.  Later tests depend upon them working */
end_comment
begin_class
DECL|class|ModelsToTest
class|class
name|ModelsToTest
block|{
public|public:
name|ModelsToTest
parameter_list|()
constructor_decl|;
name|QAbstractItemModel
modifier|*
name|createModel
parameter_list|(
specifier|const
name|QString
modifier|&
name|modelType
parameter_list|)
function_decl|;
name|QModelIndex
name|populateTestArea
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
function_decl|;
name|void
name|cleanupTestArea
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
function_decl|;
DECL|enum|Read
enum|enum
name|Read
block|{
DECL|enumerator|ReadOnly
name|ReadOnly
block|,
comment|// wont perform remove(), insert(), and setData()
DECL|enumerator|ReadWrite
name|ReadWrite
block|}
enum|;
DECL|enum|Contains
enum|enum
name|Contains
block|{
DECL|enumerator|Empty
name|Empty
block|,
comment|// Confirm that rowCount() == 0 etc throughout the test
DECL|enumerator|HasData
name|HasData
comment|// Confirm that rowCount() != 0 etc throughout the test
block|}
enum|;
DECL|struct|test
struct|struct
name|test
block|{
DECL|function|test
name|test
parameter_list|(
name|QString
name|m
parameter_list|,
name|Read
name|r
parameter_list|,
name|Contains
name|c
parameter_list|)
member_init_list|:
name|modelType
argument_list|(
name|m
argument_list|)
member_init_list|,
name|read
argument_list|(
name|r
argument_list|)
member_init_list|,
name|contains
argument_list|(
name|c
argument_list|)
block|{}
empty_stmt|;
DECL|member|modelType
name|QString
name|modelType
decl_stmt|;
DECL|member|read
name|Read
name|read
decl_stmt|;
DECL|member|contains
name|Contains
name|contains
decl_stmt|;
block|}
struct|;
DECL|member|tests
name|QList
argument_list|<
name|test
argument_list|>
name|tests
decl_stmt|;
specifier|static
name|void
name|setupDatabase
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|/*!     Add new tests, they can be the same model, but in a different state.      The name of the model is passed to createModel     If readOnly is true the remove tests will be skipped.  Example: QDirModel is disabled.     If createModel returns an empty model.  Example: QDirModel does not  */
end_comment
begin_constructor
DECL|function|ModelsToTest
name|ModelsToTest
operator|::
name|ModelsToTest
parameter_list|()
block|{
name|setupDatabase
argument_list|()
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QDirModel"
argument_list|,
name|ReadOnly
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QStringListModel"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QStringListModelEmpty"
argument_list|,
name|ReadWrite
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QStandardItemModel"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QStandardItemModelEmpty"
argument_list|,
name|ReadWrite
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
comment|// QSortFilterProxyModel test uses QStandardItemModel so test it first
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QSortFilterProxyModel"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QSortFilterProxyModelEmpty"
argument_list|,
name|ReadWrite
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QSortFilterProxyModelRegExp"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QListModel"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QListModelEmpty"
argument_list|,
name|ReadWrite
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTableModel"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTableModelEmpty"
argument_list|,
name|ReadWrite
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTreeModel"
argument_list|,
name|ReadWrite
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QTreeModelEmpty"
argument_list|,
name|ReadWrite
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QSqlQueryModel"
argument_list|,
name|ReadOnly
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QSqlQueryModelEmpty"
argument_list|,
name|ReadOnly
argument_list|,
name|Empty
argument_list|)
argument_list|)
expr_stmt|;
comment|// Fails on remove
name|tests
operator|.
name|append
argument_list|(
name|test
argument_list|(
literal|"QSqlTableModel"
argument_list|,
name|ReadOnly
argument_list|,
name|HasData
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Return a new modelType.  */
end_comment
begin_function
DECL|function|createModel
name|QAbstractItemModel
modifier|*
name|ModelsToTest
operator|::
name|createModel
parameter_list|(
specifier|const
name|QString
modifier|&
name|modelType
parameter_list|)
block|{
if|if
condition|(
name|modelType
operator|==
literal|"QStringListModelEmpty"
condition|)
return|return
operator|new
name|QStringListModel
argument_list|()
return|;
if|if
condition|(
name|modelType
operator|==
literal|"QStringListModel"
condition|)
block|{
name|QStringListModel
modifier|*
name|model
init|=
operator|new
name|QStringListModel
argument_list|()
decl_stmt|;
name|populateTestArea
argument_list|(
name|model
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QStandardItemModelEmpty"
condition|)
block|{
return|return
operator|new
name|QStandardItemModel
argument_list|()
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QStandardItemModel"
condition|)
block|{
name|QStandardItemModel
modifier|*
name|model
init|=
operator|new
name|QStandardItemModel
argument_list|()
decl_stmt|;
name|populateTestArea
argument_list|(
name|model
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QSortFilterProxyModelEmpty"
condition|)
block|{
name|QSortFilterProxyModel
modifier|*
name|model
init|=
operator|new
name|QSortFilterProxyModel
decl_stmt|;
name|QStandardItemModel
modifier|*
name|standardItemModel
init|=
operator|new
name|QStandardItemModel
decl_stmt|;
name|model
operator|->
name|setSourceModel
argument_list|(
name|standardItemModel
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QSortFilterProxyModelRegExp"
condition|)
block|{
name|QSortFilterProxyModel
modifier|*
name|model
init|=
operator|new
name|QSortFilterProxyModel
decl_stmt|;
name|QStandardItemModel
modifier|*
name|standardItemModel
init|=
operator|new
name|QStandardItemModel
decl_stmt|;
name|model
operator|->
name|setSourceModel
argument_list|(
name|standardItemModel
argument_list|)
expr_stmt|;
name|populateTestArea
argument_list|(
name|model
argument_list|)
expr_stmt|;
name|model
operator|->
name|setFilterRegExp
argument_list|(
name|QRegExp
argument_list|(
literal|"(^$|I.*)"
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QSortFilterProxyModel"
condition|)
block|{
name|QSortFilterProxyModel
modifier|*
name|model
init|=
operator|new
name|QSortFilterProxyModel
decl_stmt|;
name|QStandardItemModel
modifier|*
name|standardItemModel
init|=
operator|new
name|QStandardItemModel
decl_stmt|;
name|model
operator|->
name|setSourceModel
argument_list|(
name|standardItemModel
argument_list|)
expr_stmt|;
name|populateTestArea
argument_list|(
name|model
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QDirModel"
condition|)
block|{
name|QDirModel
modifier|*
name|model
init|=
operator|new
name|QDirModel
argument_list|()
decl_stmt|;
name|model
operator|->
name|setReadOnly
argument_list|(
literal|false
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QSqlQueryModel"
condition|)
block|{
name|QSqlQueryModel
modifier|*
name|model
init|=
operator|new
name|QSqlQueryModel
argument_list|()
decl_stmt|;
name|populateTestArea
argument_list|(
name|model
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QSqlQueryModelEmpty"
condition|)
block|{
name|QSqlQueryModel
modifier|*
name|model
init|=
operator|new
name|QSqlQueryModel
argument_list|()
decl_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QSqlTableModel"
condition|)
block|{
name|QSqlTableModel
modifier|*
name|model
init|=
operator|new
name|QSqlTableModel
argument_list|()
decl_stmt|;
name|populateTestArea
argument_list|(
name|model
argument_list|)
expr_stmt|;
return|return
name|model
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QListModelEmpty"
condition|)
return|return
operator|(
operator|new
name|QListWidget
operator|)
operator|->
name|model
argument_list|()
return|;
if|if
condition|(
name|modelType
operator|==
literal|"QListModel"
condition|)
block|{
name|QListWidget
modifier|*
name|widget
init|=
operator|new
name|QListWidget
decl_stmt|;
name|populateTestArea
argument_list|(
name|widget
operator|->
name|model
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|widget
operator|->
name|model
argument_list|()
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QTableModelEmpty"
condition|)
return|return
operator|(
operator|new
name|QTableWidget
operator|)
operator|->
name|model
argument_list|()
return|;
if|if
condition|(
name|modelType
operator|==
literal|"QTableModel"
condition|)
block|{
name|QTableWidget
modifier|*
name|widget
init|=
operator|new
name|QTableWidget
decl_stmt|;
name|populateTestArea
argument_list|(
name|widget
operator|->
name|model
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|widget
operator|->
name|model
argument_list|()
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QTreeModelEmpty"
condition|)
block|{
name|QTreeWidget
modifier|*
name|widget
init|=
operator|new
name|QTreeWidget
decl_stmt|;
return|return
name|widget
operator|->
name|model
argument_list|()
return|;
block|}
if|if
condition|(
name|modelType
operator|==
literal|"QTreeModel"
condition|)
block|{
name|QTreeWidget
modifier|*
name|widget
init|=
operator|new
name|QTreeWidget
decl_stmt|;
name|populateTestArea
argument_list|(
name|widget
operator|->
name|model
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|widget
operator|->
name|model
argument_list|()
return|;
block|}
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Fills model with some test data at least twenty rows and if possible twenty or more columns.     Return the parent of a row/column that can be tested.      NOTE: If readOnly is true tests will try to remove and add rows and columns.     If you have a tree model returning not the root index will help catch more errors.  */
end_comment
begin_function
DECL|function|populateTestArea
name|QModelIndex
name|ModelsToTest
operator|::
name|populateTestArea
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
block|{
if|if
condition|(
name|QStringListModel
modifier|*
name|stringListModel
init|=
name|qobject_cast
argument_list|<
name|QStringListModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
name|QString
name|alphabet
init|=
literal|"a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z"
decl_stmt|;
name|stringListModel
operator|->
name|setStringList
argument_list|(
name|alphabet
operator|.
name|split
argument_list|(
literal|","
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
if|if
condition|(
name|qobject_cast
argument_list|<
name|QStandardItemModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
comment|// Basic tree StandardItemModel
name|QModelIndex
name|parent
decl_stmt|;
name|QVariant
name|blue
init|=
name|QVariant
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
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
else|#
directive|else
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
operator|++
name|i
control|)
block|{
endif|#
directive|endif
name|parent
operator|=
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
expr_stmt|;
name|model
operator|->
name|insertRows
argument_list|(
literal|0
argument_list|,
literal|26
operator|+
name|i
argument_list|,
name|parent
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|model
operator|->
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|26
operator|+
name|i
argument_list|,
name|parent
argument_list|)
expr_stmt|;
else|#
directive|else
name|model
operator|->
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|4
operator|+
name|i
argument_list|,
name|parent
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Fill in some values to make it easier to debug
comment|/*             for (int x = 0; x< 26 + i; ++x) {                 QString xval = QString::number(x);                 for (int y = 0; y< 26 + i; ++y) {                     QString val = xval + QString::number(y) + QString::number(i);                     QModelIndex index = model->index(x, y, parent);                     model->setData(index, val);                     model->setData(index, blue, Qt::TextColorRole);                 }             }             */
block|}
return|return
name|model
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
return|;
block|}
if|if
condition|(
name|qobject_cast
argument_list|<
name|QSortFilterProxyModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
name|QAbstractItemModel
modifier|*
name|realModel
init|=
operator|(
name|qobject_cast
argument_list|<
name|QSortFilterProxyModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
operator|)
operator|->
name|sourceModel
argument_list|()
decl_stmt|;
comment|// Basic tree StandardItemModel
name|QModelIndex
name|parent
decl_stmt|;
name|QVariant
name|blue
init|=
name|QVariant
argument_list|(
name|QColor
argument_list|(
name|Qt
operator|::
name|blue
argument_list|)
argument_list|)
decl_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
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
else|#
directive|else
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
operator|++
name|i
control|)
block|{
endif|#
directive|endif
name|parent
operator|=
name|realModel
operator|->
name|index
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
expr_stmt|;
name|realModel
operator|->
name|insertRows
argument_list|(
literal|0
argument_list|,
literal|26
operator|+
name|i
argument_list|,
name|parent
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|realModel
operator|->
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|26
operator|+
name|i
argument_list|,
name|parent
argument_list|)
expr_stmt|;
else|#
directive|else
name|realModel
operator|->
name|insertColumns
argument_list|(
literal|0
argument_list|,
literal|4
argument_list|,
name|parent
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Fill in some values to make it easier to debug
comment|/*             for (int x = 0; x< 26+i; ++x) {                 QString xval = QString::number(x);                 for (int y = 0; y< 26 + i; ++y) {                     QString val = xval + QString::number(y) + QString::number(i);                     QModelIndex index = realModel->index(x, y, parent);                     realModel->setData(index, val);                     realModel->setData(index, blue, Qt::TextColorRole);                 }             }             */
block|}
name|QModelIndex
name|returnIndex
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
if|if
condition|(
operator|!
name|returnIndex
operator|.
name|isValid
argument_list|()
condition|)
name|qFatal
argument_list|(
literal|"%s: model index to be returned is invalid"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
return|return
name|returnIndex
return|;
block|}
if|if
condition|(
name|QDirModel
modifier|*
name|dirModel
init|=
name|qobject_cast
argument_list|<
name|QDirModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|QDir
operator|::
name|current
argument_list|()
operator|.
name|mkdir
argument_list|(
literal|"test"
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"%s: cannot create directory %s"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/test"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|26
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|subdir
init|=
name|QString
argument_list|(
literal|"test/foo_%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|current
argument_list|()
operator|.
name|mkdir
argument_list|(
name|subdir
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"%s: cannot create directory %s"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/"
operator|+
name|subdir
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|dirModel
operator|->
name|index
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/test"
argument_list|)
return|;
block|}
if|if
condition|(
name|QSqlQueryModel
modifier|*
name|queryModel
init|=
name|qobject_cast
argument_list|<
name|QSqlQueryModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
name|QSqlQuery
name|q
decl_stmt|;
name|q
operator|.
name|exec
argument_list|(
literal|"CREATE TABLE test(id int primary key, name varchar(30))"
argument_list|)
expr_stmt|;
name|q
operator|.
name|prepare
argument_list|(
literal|"INSERT INTO test(id, name) values (?, ?)"
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|Q_OS_WINCE
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1024
condition|;
operator|++
name|i
control|)
block|{
else|#
directive|else
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|512
condition|;
operator|++
name|i
control|)
block|{
endif|#
directive|endif
name|q
operator|.
name|addBindValue
argument_list|(
name|i
argument_list|)
expr_stmt|;
name|q
operator|.
name|addBindValue
argument_list|(
literal|"Mr. Smith"
operator|+
name|QString
operator|::
name|number
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
name|q
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|QSqlTableModel
modifier|*
name|tableModel
init|=
name|qobject_cast
argument_list|<
name|QSqlTableModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
name|tableModel
operator|->
name|setTable
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
name|tableModel
operator|->
name|setEditStrategy
argument_list|(
name|QSqlTableModel
operator|::
name|OnManualSubmit
argument_list|)
expr_stmt|;
name|tableModel
operator|->
name|select
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|queryModel
operator|->
name|setQuery
argument_list|(
literal|"select * from test"
argument_list|)
expr_stmt|;
block|}
return|return
name|QModelIndex
argument_list|()
return|;
block|}
if|if
condition|(
name|QListWidget
modifier|*
name|listWidget
init|=
name|qobject_cast
argument_list|<
name|QListWidget
operator|*
argument_list|>
argument_list|(
name|model
operator|->
name|parent
argument_list|()
argument_list|)
condition|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINCE
name|int
name|items
init|=
literal|100
decl_stmt|;
else|#
directive|else
name|int
name|items
init|=
literal|50
decl_stmt|;
endif|#
directive|endif
while|while
condition|(
name|items
operator|--
condition|)
name|listWidget
operator|->
name|addItem
argument_list|(
name|QString
argument_list|(
literal|"item %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|items
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
if|if
condition|(
name|QTableWidget
modifier|*
name|tableWidget
init|=
name|qobject_cast
argument_list|<
name|QTableWidget
operator|*
argument_list|>
argument_list|(
name|model
operator|->
name|parent
argument_list|()
argument_list|)
condition|)
block|{
name|tableWidget
operator|->
name|setColumnCount
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|tableWidget
operator|->
name|setRowCount
argument_list|(
literal|20
argument_list|)
expr_stmt|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
if|if
condition|(
name|QTreeWidget
modifier|*
name|treeWidget
init|=
name|qobject_cast
argument_list|<
name|QTreeWidget
operator|*
argument_list|>
argument_list|(
name|model
operator|->
name|parent
argument_list|()
argument_list|)
condition|)
block|{
name|int
name|topItems
init|=
literal|20
decl_stmt|;
name|treeWidget
operator|->
name|setColumnCount
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|QTreeWidgetItem
modifier|*
name|parent
decl_stmt|;
while|while
condition|(
name|topItems
operator|--
condition|)
block|{
name|parent
operator|=
operator|new
name|QTreeWidgetItem
argument_list|(
name|treeWidget
argument_list|,
name|QStringList
argument_list|(
name|QString
argument_list|(
literal|"top %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|topItems
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
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
operator|new
name|QTreeWidgetItem
argument_list|(
name|parent
argument_list|,
name|QStringList
argument_list|(
name|QString
argument_list|(
literal|"child %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|topItems
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|QModelIndex
argument_list|()
return|;
block|}
name|qFatal
argument_list|(
literal|"%s: unknown type of model"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
return|return
name|QModelIndex
argument_list|()
return|;
block|}
comment|/*!     If you need to cleanup from populateTest() do it here.     Note that this is called after every test even if populateTestArea isn't called.  */
DECL|function|cleanupTestArea
name|void
name|ModelsToTest
operator|::
name|cleanupTestArea
parameter_list|(
name|QAbstractItemModel
modifier|*
name|model
parameter_list|)
block|{
if|if
condition|(
name|qobject_cast
argument_list|<
name|QDirModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
if|if
condition|(
name|QDir
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/test"
argument_list|)
operator|.
name|exists
argument_list|()
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|26
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|subdir
argument_list|(
name|QString
argument_list|(
literal|"test/foo_%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|QDir
operator|::
name|current
argument_list|()
operator|.
name|rmdir
argument_list|(
name|subdir
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"%s: cannot remove directory %s"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/"
operator|+
name|subdir
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|QDir
operator|::
name|current
argument_list|()
operator|.
name|rmdir
argument_list|(
literal|"test"
argument_list|)
condition|)
name|qFatal
argument_list|(
literal|"%s: cannot remove directory %s"
argument_list|,
name|Q_FUNC_INFO
argument_list|,
name|qPrintable
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|QDir
operator|::
name|currentPath
argument_list|()
operator|+
literal|"/test"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|qobject_cast
argument_list|<
name|QSqlQueryModel
operator|*
argument_list|>
argument_list|(
name|model
argument_list|)
condition|)
block|{
name|QSqlQuery
name|q
argument_list|(
literal|"DROP TABLE test"
argument_list|)
decl_stmt|;
block|}
block|}
DECL|function|setupDatabase
name|void
name|ModelsToTest
operator|::
name|setupDatabase
parameter_list|()
block|{
if|if
condition|(
operator|!
name|QSqlDatabase
operator|::
name|database
argument_list|()
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QSqlDatabase
name|db
init|=
name|QSqlDatabase
operator|::
name|addDatabase
argument_list|(
literal|"QSQLITE"
argument_list|)
decl_stmt|;
name|db
operator|.
name|setDatabaseName
argument_list|(
literal|":memory:"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|db
operator|.
name|open
argument_list|()
condition|)
block|{
name|qWarning
argument_list|()
operator|<<
literal|"Unable to open database"
operator|<<
name|db
operator|.
name|lastError
argument_list|()
expr_stmt|;
return|return;
block|}
block|}
block|}
end_function
end_unit
