begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qabstractproxymodel.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PROXYMODEL
end_ifndef
begin_include
include|#
directive|include
file|"qitemselectionmodel.h"
end_include
begin_include
include|#
directive|include
file|<private/qabstractproxymodel_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QSize>
end_include
begin_include
include|#
directive|include
file|<QtCore/QStringList>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     \since 4.1     \class QAbstractProxyModel     \brief The QAbstractProxyModel class provides a base class for proxy item     models that can do sorting, filtering or other data processing tasks.     \ingroup model-view     \inmodule QtCore      This class defines the standard interface that proxy models must use to be     able to interoperate correctly with other model/view components. It is not     supposed to be instantiated directly.      All standard proxy models are derived from the QAbstractProxyModel class.     If you need to create a new proxy model class, it is usually better to     subclass an existing class that provides the closest behavior to the one     you want to provide.      Proxy models that filter or sort items of data from a source model should     be created by using or subclassing QSortFilterProxyModel.      To subclass QAbstractProxyModel, you need to implement mapFromSource() and     mapToSource(). The mapSelectionFromSource() and mapSelectionToSource()     functions only need to be reimplemented if you need a behavior different     from the default behavior.      \note If the source model is deleted or no source model is specified, the     proxy model operates on a empty placeholder model.      \sa QSortFilterProxyModel, QAbstractItemModel, {Model/View Programming} */
comment|//detects the deletion of the source model
DECL|function|_q_sourceModelDestroyed
name|void
name|QAbstractProxyModelPrivate
operator|::
name|_q_sourceModelDestroyed
parameter_list|()
block|{
name|model
operator|=
name|QAbstractItemModelPrivate
operator|::
name|staticEmptyModel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a proxy model with the given \a parent. */
end_comment
begin_constructor
DECL|function|QAbstractProxyModel
name|QAbstractProxyModel
operator|::
name|QAbstractProxyModel
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractItemModel
argument_list|(
operator|*
operator|new
name|QAbstractProxyModelPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|setSourceModel
argument_list|(
name|QAbstractItemModelPrivate
operator|::
name|staticEmptyModel
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QAbstractProxyModel
name|QAbstractProxyModel
operator|::
name|QAbstractProxyModel
parameter_list|(
name|QAbstractProxyModelPrivate
modifier|&
name|dd
parameter_list|,
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractItemModel
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{
name|setSourceModel
argument_list|(
name|QAbstractItemModelPrivate
operator|::
name|staticEmptyModel
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the proxy model. */
end_comment
begin_destructor
DECL|function|~QAbstractProxyModel
name|QAbstractProxyModel
operator|::
name|~
name|QAbstractProxyModel
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!     Sets the given \a sourceModel to be processed by the proxy model. */
end_comment
begin_function
DECL|function|setSourceModel
name|void
name|QAbstractProxyModel
operator|::
name|setSourceModel
parameter_list|(
name|QAbstractItemModel
modifier|*
name|sourceModel
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|model
condition|)
name|disconnect
argument_list|(
name|d
operator|->
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_sourceModelDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sourceModel
condition|)
block|{
name|d
operator|->
name|model
operator|=
name|sourceModel
expr_stmt|;
name|connect
argument_list|(
name|d
operator|->
name|model
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|()
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_sourceModelDestroyed
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|d
operator|->
name|model
operator|=
name|QAbstractItemModelPrivate
operator|::
name|staticEmptyModel
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|roleNames
operator|=
name|d
operator|->
name|model
operator|->
name|roleNames
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the model that contains the data that is available through the proxy model. */
end_comment
begin_function
DECL|function|sourceModel
name|QAbstractItemModel
modifier|*
name|QAbstractProxyModel
operator|::
name|sourceModel
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|model
operator|==
name|QAbstractItemModelPrivate
operator|::
name|staticEmptyModel
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|model
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|submit
name|bool
name|QAbstractProxyModel
operator|::
name|submit
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|submit
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|revert
name|void
name|QAbstractProxyModel
operator|::
name|revert
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
name|d
operator|->
name|model
operator|->
name|revert
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \fn QModelIndex QAbstractProxyModel::mapToSource(const QModelIndex&proxyIndex) const    Reimplement this function to return the model index in the source model that   corresponds to the \a proxyIndex in the proxy model.    \sa mapFromSource() */
end_comment
begin_comment
comment|/*!   \fn QModelIndex QAbstractProxyModel::mapFromSource(const QModelIndex&sourceIndex) const    Reimplement this function to return the model index in the proxy model that   corresponds to the \a sourceIndex from the source model.    \sa mapToSource() */
end_comment
begin_comment
comment|/*!   Returns a source selection mapped from the specified \a proxySelection.    Reimplement this method to map proxy selections to source selections.  */
end_comment
begin_function
DECL|function|mapSelectionToSource
name|QItemSelection
name|QAbstractProxyModel
operator|::
name|mapSelectionToSource
parameter_list|(
specifier|const
name|QItemSelection
modifier|&
name|proxySelection
parameter_list|)
specifier|const
block|{
name|QModelIndexList
name|proxyIndexes
init|=
name|proxySelection
operator|.
name|indexes
argument_list|()
decl_stmt|;
name|QItemSelection
name|sourceSelection
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
name|proxyIndexes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QModelIndex
name|proxyIdx
init|=
name|mapToSource
argument_list|(
name|proxyIndexes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|proxyIdx
operator|.
name|isValid
argument_list|()
condition|)
continue|continue;
name|sourceSelection
operator|<<
name|QItemSelectionRange
argument_list|(
name|proxyIdx
argument_list|)
expr_stmt|;
block|}
return|return
name|sourceSelection
return|;
block|}
end_function
begin_comment
comment|/*!   Returns a proxy selection mapped from the specified \a sourceSelection.    Reimplement this method to map source selections to proxy selections. */
end_comment
begin_function
DECL|function|mapSelectionFromSource
name|QItemSelection
name|QAbstractProxyModel
operator|::
name|mapSelectionFromSource
parameter_list|(
specifier|const
name|QItemSelection
modifier|&
name|sourceSelection
parameter_list|)
specifier|const
block|{
name|QModelIndexList
name|sourceIndexes
init|=
name|sourceSelection
operator|.
name|indexes
argument_list|()
decl_stmt|;
name|QItemSelection
name|proxySelection
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
name|sourceIndexes
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QModelIndex
name|srcIdx
init|=
name|mapFromSource
argument_list|(
name|sourceIndexes
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|srcIdx
operator|.
name|isValid
argument_list|()
condition|)
continue|continue;
name|proxySelection
operator|<<
name|QItemSelectionRange
argument_list|(
name|srcIdx
argument_list|)
expr_stmt|;
block|}
return|return
name|proxySelection
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|data
name|QVariant
name|QAbstractProxyModel
operator|::
name|data
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|proxyIndex
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|data
argument_list|(
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
argument_list|,
name|role
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|headerData
name|QVariant
name|QAbstractProxyModel
operator|::
name|headerData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|int
name|role
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
name|int
name|sourceSection
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
specifier|const
name|QModelIndex
name|proxyIndex
init|=
name|index
argument_list|(
literal|0
argument_list|,
name|section
argument_list|)
decl_stmt|;
name|sourceSection
operator|=
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
operator|.
name|column
argument_list|()
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QModelIndex
name|proxyIndex
init|=
name|index
argument_list|(
name|section
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|sourceSection
operator|=
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
operator|.
name|row
argument_list|()
expr_stmt|;
block|}
return|return
name|d
operator|->
name|model
operator|->
name|headerData
argument_list|(
name|sourceSection
argument_list|,
name|orientation
argument_list|,
name|role
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|itemData
name|QMap
argument_list|<
name|int
argument_list|,
name|QVariant
argument_list|>
name|QAbstractProxyModel
operator|::
name|itemData
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|proxyIndex
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|itemData
argument_list|(
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|flags
name|Qt
operator|::
name|ItemFlags
name|QAbstractProxyModel
operator|::
name|flags
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|flags
argument_list|(
name|mapToSource
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|setData
name|bool
name|QAbstractProxyModel
operator|::
name|setData
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|setData
argument_list|(
name|mapToSource
argument_list|(
name|index
argument_list|)
argument_list|,
name|value
argument_list|,
name|role
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|setItemData
name|bool
name|QAbstractProxyModel
operator|::
name|setItemData
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|,
specifier|const
name|QMap
argument_list|<
name|int
argument_list|,
name|QVariant
argument_list|>
modifier|&
name|roles
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|setItemData
argument_list|(
name|mapToSource
argument_list|(
name|index
argument_list|)
argument_list|,
name|roles
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|setHeaderData
name|bool
name|QAbstractProxyModel
operator|::
name|setHeaderData
parameter_list|(
name|int
name|section
parameter_list|,
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
specifier|const
name|QVariant
modifier|&
name|value
parameter_list|,
name|int
name|role
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
name|int
name|sourceSection
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
specifier|const
name|QModelIndex
name|proxyIndex
init|=
name|index
argument_list|(
literal|0
argument_list|,
name|section
argument_list|)
decl_stmt|;
name|sourceSection
operator|=
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
operator|.
name|column
argument_list|()
expr_stmt|;
block|}
else|else
block|{
specifier|const
name|QModelIndex
name|proxyIndex
init|=
name|index
argument_list|(
name|section
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|sourceSection
operator|=
name|mapToSource
argument_list|(
name|proxyIndex
argument_list|)
operator|.
name|row
argument_list|()
expr_stmt|;
block|}
return|return
name|d
operator|->
name|model
operator|->
name|setHeaderData
argument_list|(
name|sourceSection
argument_list|,
name|orientation
argument_list|,
name|value
argument_list|,
name|role
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|buddy
name|QModelIndex
name|QAbstractProxyModel
operator|::
name|buddy
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|mapFromSource
argument_list|(
name|d
operator|->
name|model
operator|->
name|buddy
argument_list|(
name|mapToSource
argument_list|(
name|index
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|canFetchMore
name|bool
name|QAbstractProxyModel
operator|::
name|canFetchMore
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|canFetchMore
argument_list|(
name|mapToSource
argument_list|(
name|parent
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|fetchMore
name|void
name|QAbstractProxyModel
operator|::
name|fetchMore
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
name|d
operator|->
name|model
operator|->
name|fetchMore
argument_list|(
name|mapToSource
argument_list|(
name|parent
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|sort
name|void
name|QAbstractProxyModel
operator|::
name|sort
parameter_list|(
name|int
name|column
parameter_list|,
name|Qt
operator|::
name|SortOrder
name|order
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
name|d
operator|->
name|model
operator|->
name|sort
argument_list|(
name|column
argument_list|,
name|order
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|span
name|QSize
name|QAbstractProxyModel
operator|::
name|span
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|span
argument_list|(
name|mapToSource
argument_list|(
name|index
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|hasChildren
name|bool
name|QAbstractProxyModel
operator|::
name|hasChildren
parameter_list|(
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|hasChildren
argument_list|(
name|mapToSource
argument_list|(
name|parent
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QAbstractProxyModel
operator|::
name|mimeData
parameter_list|(
specifier|const
name|QModelIndexList
modifier|&
name|indexes
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
name|QModelIndexList
name|list
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QModelIndex
modifier|&
name|index
decl|,
name|indexes
control|)
name|list
operator|<<
name|mapToSource
argument_list|(
name|index
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|mimeData
argument_list|(
name|list
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|mimeTypes
name|QStringList
name|QAbstractProxyModel
operator|::
name|mimeTypes
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|mimeTypes
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|supportedDropActions
name|Qt
operator|::
name|DropActions
name|QAbstractProxyModel
operator|::
name|supportedDropActions
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QAbstractProxyModel
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|model
operator|->
name|supportedDropActions
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qabstractproxymodel.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PROXYMODEL
end_comment
end_unit
