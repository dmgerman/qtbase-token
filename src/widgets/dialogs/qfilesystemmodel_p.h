begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMMODEL_P_H
end_ifndef
begin_define
DECL|macro|QFILESYSTEMMODEL_P_H
define|#
directive|define
name|QFILESYSTEMMODEL_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qfilesystemmodel.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMMODEL
end_ifndef
begin_include
include|#
directive|include
file|<private/qabstractitemmodel_p.h>
end_include
begin_include
include|#
directive|include
file|<qabstractitemmodel.h>
end_include
begin_include
include|#
directive|include
file|"qfileinfogatherer_p.h"
end_include
begin_include
include|#
directive|include
file|<qpair.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qicon.h>
end_include
begin_include
include|#
directive|include
file|<qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|ExtendedInformation
name|class
name|ExtendedInformation
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileSystemModelPrivate
name|class
name|QFileSystemModelPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFileIconProvider
name|class
name|QFileIconProvider
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QFileSystemModelPrivate
range|:
name|public
name|QAbstractItemModelPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFileSystemModel
argument_list|)
name|public
operator|:
name|class
name|QFileSystemNode
block|{
name|public
operator|:
name|explicit
name|QFileSystemNode
argument_list|(
specifier|const
name|QString
operator|&
name|filename
operator|=
name|QString
argument_list|()
argument_list|,
name|QFileSystemNode
operator|*
name|p
operator|=
literal|0
argument_list|)
operator|:
name|fileName
argument_list|(
name|filename
argument_list|)
block|,
name|populatedChildren
argument_list|(
name|false
argument_list|)
block|,
name|isVisible
argument_list|(
name|false
argument_list|)
block|,
name|dirtyChildrenIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|parent
argument_list|(
name|p
argument_list|)
block|,
name|info
argument_list|(
literal|0
argument_list|)
block|{}
operator|~
name|QFileSystemNode
argument_list|()
block|{
name|QHash
operator|<
name|QString
block|,
name|QFileSystemNode
operator|*
operator|>
operator|::
name|const_iterator
name|i
operator|=
name|children
operator|.
name|constBegin
argument_list|()
block|;
while|while
condition|(
name|i
operator|!=
name|children
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|delete
name|i
operator|.
name|value
parameter_list|()
function_decl|;
operator|++
name|i
expr_stmt|;
block|}
name|delete
name|info
decl_stmt|;
name|info
operator|=
literal|0
block|;
name|parent
operator|=
literal|0
block|;         }
name|QString
name|fileName
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|QString
name|volumeName
block|;
endif|#
directive|endif
specifier|inline
name|qint64
name|size
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
operator|&&
operator|!
name|info
operator|->
name|isDir
argument_list|()
condition|)
return|return
name|info
operator|->
name|size
argument_list|()
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt
begin_expr_stmt
specifier|inline
name|QString
name|type
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|displayType
return|;
end_expr_stmt
begin_return
return|return
name|QLatin1String
argument_list|(
literal|""
argument_list|)
return|;
end_return
begin_expr_stmt
unit|}         inline
name|QDateTime
name|lastModified
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|lastModified
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|QDateTime
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}         inline
name|QFile
operator|::
name|Permissions
name|permissions
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|permissions
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
literal|0
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|isReadable
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|permissions
argument_list|()
operator|&
name|QFile
operator|::
name|ReadUser
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isWritable
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|permissions
argument_list|()
operator|&
name|QFile
operator|::
name|WriteUser
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isExecutable
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|(
name|permissions
argument_list|()
operator|&
name|QFile
operator|::
name|ExeUser
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|isDir
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|isDir
argument_list|()
return|;
end_expr_stmt
begin_if
if|if
condition|(
name|children
operator|.
name|count
argument_list|()
operator|>
literal|0
condition|)
return|return
name|true
return|;
end_if
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|isFile
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|isFile
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|isSystem
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|isSystem
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|true
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|isHidden
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|isHidden
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|isSymLink
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|isSymLink
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|caseSensitive
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|isCaseSensitive
argument_list|()
return|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|}         inline
name|QIcon
name|icon
argument_list|()
specifier|const
block|{
if|if
condition|(
name|info
condition|)
return|return
name|info
operator|->
name|icon
return|;
end_expr_stmt
begin_return
return|return
name|QIcon
argument_list|()
return|;
end_return
begin_expr_stmt
unit|}          inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QFileSystemNode
operator|&
name|node
operator|)
specifier|const
block|{
if|if
condition|(
name|caseSensitive
argument_list|()
operator|||
name|node
operator|.
name|caseSensitive
argument_list|()
condition|)
return|return
name|fileName
operator|<
name|node
operator|.
name|fileName
return|;
end_expr_stmt
begin_return
return|return
name|QString
operator|::
name|compare
argument_list|(
name|fileName
argument_list|,
name|node
operator|.
name|fileName
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|<
literal|0
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QString
operator|&
name|name
operator|)
specifier|const
block|{
if|if
condition|(
name|caseSensitive
argument_list|()
condition|)
return|return
name|fileName
operator|>
name|name
return|;
end_expr_stmt
begin_return
return|return
name|QString
operator|::
name|compare
argument_list|(
name|fileName
argument_list|,
name|name
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|>
literal|0
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QString
operator|&
name|name
operator|)
specifier|const
block|{
if|if
condition|(
name|caseSensitive
argument_list|()
condition|)
return|return
name|fileName
operator|<
name|name
return|;
end_expr_stmt
begin_return
return|return
name|QString
operator|::
name|compare
argument_list|(
name|fileName
argument_list|,
name|name
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|<
literal|0
return|;
end_return
begin_expr_stmt
unit|}         inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QExtendedInformation
operator|&
name|fileInfo
operator|)
specifier|const
block|{
return|return
operator|!
name|operator
operator|==
operator|(
name|fileInfo
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QString
operator|&
name|name
operator|)
specifier|const
block|{
if|if
condition|(
name|caseSensitive
argument_list|()
condition|)
return|return
name|fileName
operator|==
name|name
return|;
end_expr_stmt
begin_return
return|return
name|QString
operator|::
name|compare
argument_list|(
name|fileName
argument_list|,
name|name
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|==
literal|0
return|;
end_return
begin_expr_stmt
unit|}         bool
name|operator
operator|==
operator|(
specifier|const
name|QExtendedInformation
operator|&
name|fileInfo
operator|)
specifier|const
block|{
return|return
name|info
operator|&&
operator|(
operator|*
name|info
operator|==
name|fileInfo
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|hasInformation
argument_list|()
specifier|const
block|{
return|return
name|info
operator|!=
literal|0
return|;
block|}
end_expr_stmt
begin_function
name|void
name|populate
parameter_list|(
specifier|const
name|QExtendedInformation
modifier|&
name|fileInfo
parameter_list|)
block|{
if|if
condition|(
operator|!
name|info
condition|)
name|info
operator|=
name|new
name|QExtendedInformation
argument_list|(
name|fileInfo
operator|.
name|fileInfo
argument_list|()
argument_list|)
expr_stmt|;
operator|(
operator|*
name|info
operator|)
operator|=
name|fileInfo
expr_stmt|;
block|}
end_function
begin_comment
comment|// children shouldn't normally be accessed directly, use node()
end_comment
begin_function
specifier|inline
name|int
name|visibleLocation
parameter_list|(
name|QString
name|childName
parameter_list|)
block|{
return|return
name|visibleChildren
operator|.
name|indexOf
argument_list|(
name|childName
argument_list|)
return|;
block|}
end_function
begin_function
name|void
name|updateIcon
parameter_list|(
name|QFileIconProvider
modifier|*
name|iconProvider
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|info
condition|)
name|info
operator|->
name|icon
operator|=
name|iconProvider
operator|->
name|icon
argument_list|(
name|QFileInfo
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|QFileSystemNode
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
for|for
control|(
name|iterator
operator|=
name|children
operator|.
name|constBegin
argument_list|()
init|;
name|iterator
operator|!=
name|children
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|iterator
control|)
block|{
comment|//On windows the root (My computer) has no path so we don't want to add a / for nothing (e.g. /C:/)
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|updateIcon
argument_list|(
name|iconProvider
argument_list|,
name|path
operator|+
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|fileName
argument_list|)
expr_stmt|;
else|else
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|updateIcon
argument_list|(
name|iconProvider
argument_list|,
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|fileName
argument_list|)
expr_stmt|;
block|}
else|else
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|updateIcon
argument_list|(
name|iconProvider
argument_list|,
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|fileName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
name|void
name|retranslateStrings
parameter_list|(
name|QFileIconProvider
modifier|*
name|iconProvider
parameter_list|,
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|info
condition|)
name|info
operator|->
name|displayType
operator|=
name|iconProvider
operator|->
name|type
argument_list|(
name|QFileInfo
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|QFileSystemNode
operator|*
operator|>
operator|::
name|const_iterator
name|iterator
expr_stmt|;
for|for
control|(
name|iterator
operator|=
name|children
operator|.
name|constBegin
argument_list|()
init|;
name|iterator
operator|!=
name|children
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|iterator
control|)
block|{
comment|//On windows the root (My computer) has no path so we don't want to add a / for nothing (e.g. /C:/)
if|if
condition|(
operator|!
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|path
operator|.
name|endsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|retranslateStrings
argument_list|(
name|iconProvider
argument_list|,
name|path
operator|+
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|fileName
argument_list|)
expr_stmt|;
else|else
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|retranslateStrings
argument_list|(
name|iconProvider
argument_list|,
name|path
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|fileName
argument_list|)
expr_stmt|;
block|}
else|else
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|retranslateStrings
argument_list|(
name|iconProvider
argument_list|,
name|iterator
operator|.
name|value
argument_list|()
operator|->
name|fileName
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_decl_stmt
name|bool
name|populatedChildren
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|isVisible
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QHash
operator|<
name|QString
operator|,
name|QFileSystemNode
operator|*
operator|>
name|children
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QList
operator|<
name|QString
operator|>
name|visibleChildren
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|dirtyChildrenIndex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileSystemNode
modifier|*
name|parent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QExtendedInformation
modifier|*
name|info
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|QFileSystemModelPrivate
argument_list|()
operator|:
name|forceSort
argument_list|(
name|true
argument_list|)
operator|,
name|sortColumn
argument_list|(
literal|0
argument_list|)
operator|,
name|sortOrder
argument_list|(
name|Qt
operator|::
name|AscendingOrder
argument_list|)
operator|,
name|readOnly
argument_list|(
name|true
argument_list|)
operator|,
name|setRootPath
argument_list|(
name|false
argument_list|)
operator|,
name|filters
argument_list|(
name|QDir
operator|::
name|AllEntries
operator||
name|QDir
operator|::
name|NoDotAndDotDot
operator||
name|QDir
operator|::
name|AllDirs
argument_list|)
operator|,
name|nameFilterDisables
argument_list|(
name|true
argument_list|)
operator|,
comment|// false on windows, true on mac and unix
name|disableRecursiveSort
argument_list|(
argument|false
argument_list|)
block|{
name|delayedSortTimer
operator|.
name|setSingleShot
argument_list|(
name|true
argument_list|)
block|;     }
name|void
name|init
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*       \internal        Return true if index which is owned by node is hidden by the filter.     */
end_comment
begin_decl_stmt
specifier|inline
name|bool
name|isHiddenByFilter
argument_list|(
name|QFileSystemNode
operator|*
name|indexNode
argument_list|,
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
block|{
return|return
operator|(
name|indexNode
operator|!=
operator|&
name|root
operator|&&
operator|!
name|index
operator|.
name|isValid
argument_list|()
operator|)
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QFileSystemNode
modifier|*
name|node
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QFileSystemNode
modifier|*
name|node
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
name|bool
name|fetch
operator|=
name|true
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function
specifier|inline
name|QModelIndex
name|index
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
return|return
name|index
argument_list|(
name|node
argument_list|(
name|path
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
name|QModelIndex
name|index
argument_list|(
specifier|const
name|QFileSystemNode
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|filtersAcceptsNode
argument_list|(
specifier|const
name|QFileSystemNode
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|passNameFilters
argument_list|(
specifier|const
name|QFileSystemNode
operator|*
name|node
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|removeNode
parameter_list|(
name|QFileSystemNode
modifier|*
name|parentNode
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QFileSystemNode
modifier|*
name|addNode
parameter_list|(
name|QFileSystemNode
modifier|*
name|parentNode
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QFileInfo
modifier|&
name|info
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|addVisibleFiles
parameter_list|(
name|QFileSystemNode
modifier|*
name|parentNode
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|newFiles
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|removeVisibleFile
parameter_list|(
name|QFileSystemNode
modifier|*
name|parentNode
parameter_list|,
name|int
name|visibleLocation
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|sortChildren
parameter_list|(
name|int
name|column
parameter_list|,
specifier|const
name|QModelIndex
modifier|&
name|parent
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|inline
name|int
name|translateVisibleLocation
argument_list|(
name|QFileSystemNode
operator|*
name|parent
argument_list|,
name|int
name|row
argument_list|)
decl|const
block|{
if|if
condition|(
name|sortOrder
operator|!=
name|Qt
operator|::
name|AscendingOrder
condition|)
block|{
if|if
condition|(
name|parent
operator|->
name|dirtyChildrenIndex
operator|==
operator|-
literal|1
condition|)
return|return
name|parent
operator|->
name|visibleChildren
operator|.
name|count
argument_list|()
operator|-
name|row
operator|-
literal|1
return|;
if|if
condition|(
name|row
operator|<
name|parent
operator|->
name|dirtyChildrenIndex
condition|)
return|return
name|parent
operator|->
name|dirtyChildrenIndex
operator|-
name|row
operator|-
literal|1
return|;
block|}
return|return
name|row
return|;
block|}
end_decl_stmt
begin_function
specifier|inline
specifier|static
name|QString
name|myComputer
parameter_list|()
block|{
comment|// ### TODO We should query the system to find out what the string should be
comment|// XP == "My Computer",
comment|// Vista == "Computer",
comment|// OS X == "Computer" (sometime user generated) "Benjamin's PowerBook G4"
ifdef|#
directive|ifdef
name|Q_OS_WIN
return|return
name|QFileSystemModel
operator|::
name|tr
argument_list|(
literal|"My Computer"
argument_list|)
return|;
else|#
directive|else
return|return
name|QFileSystemModel
operator|::
name|tr
argument_list|(
literal|"Computer"
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
specifier|inline
name|void
name|delayedSort
parameter_list|()
block|{
if|if
condition|(
operator|!
name|delayedSortTimer
operator|.
name|isActive
argument_list|()
condition|)
name|delayedSortTimer
operator|.
name|start
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|bool
name|caseInsensitiveLessThan
parameter_list|(
specifier|const
name|QString
modifier|&
name|s1
parameter_list|,
specifier|const
name|QString
modifier|&
name|s2
parameter_list|)
block|{
return|return
name|QString
operator|::
name|compare
argument_list|(
name|s1
argument_list|,
name|s2
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|<
literal|0
return|;
block|}
end_function
begin_decl_stmt
specifier|static
name|bool
name|nodeCaseInsensitiveLessThan
argument_list|(
specifier|const
name|QFileSystemModelPrivate
operator|::
name|QFileSystemNode
operator|&
name|s1
argument_list|,
specifier|const
name|QFileSystemModelPrivate
operator|::
name|QFileSystemNode
operator|&
name|s2
argument_list|)
block|{
return|return
name|QString
operator|::
name|compare
argument_list|(
name|s1
operator|.
name|fileName
argument_list|,
name|s2
operator|.
name|fileName
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|<
literal|0
return|;
block|}
end_decl_stmt
begin_decl_stmt
name|QIcon
name|icon
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|name
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|displayName
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|filePath
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|size
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
specifier|static
name|QString
name|size
parameter_list|(
name|qint64
name|bytes
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QString
name|type
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|time
argument_list|(
specifier|const
name|QModelIndex
operator|&
name|index
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_directoryChanged
parameter_list|(
specifier|const
name|QString
modifier|&
name|directory
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|list
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|_q_performDelayedSort
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|void
name|_q_fileSystemChanged
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|,
specifier|const
name|QList
operator|<
name|QPair
operator|<
name|QString
argument_list|,
name|QFileInfo
operator|>
expr|>
operator|&
argument_list|)
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|_q_resolvedName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|,
specifier|const
name|QString
modifier|&
name|resolvedName
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
specifier|static
name|int
name|naturalCompare
argument_list|(
specifier|const
name|QString
operator|&
name|s1
argument_list|,
specifier|const
name|QString
operator|&
name|s2
argument_list|,
name|Qt
operator|::
name|CaseSensitivity
name|cs
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QDir
name|rootDir
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_decl_stmt
name|QFileInfoGatherer
name|fileInfoGatherer
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QTimer
name|delayedSortTimer
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|forceSort
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|sortColumn
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|SortOrder
name|sortOrder
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|readOnly
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|setRootPath
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QDir
operator|::
name|Filters
name|filters
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QHash
operator|<
specifier|const
name|QFileSystemNode
operator|*
operator|,
name|bool
operator|>
name|bypassFilters
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|bool
name|nameFilterDisables
decl_stmt|;
end_decl_stmt
begin_comment
comment|//This flag is an optimization for the QFileDialog
end_comment
begin_comment
comment|//It enable a sort which is not recursive, it means
end_comment
begin_comment
comment|//we sort only what we see.
end_comment
begin_decl_stmt
name|bool
name|disableRecursiveSort
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_REGEXP
end_ifndef
begin_expr_stmt
name|QList
operator|<
name|QRegExp
operator|>
name|nameFilters
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QHash
operator|<
name|QString
operator|,
name|QString
operator|>
name|resolvedSymLinks
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QFileSystemNode
name|root
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QBasicTimer
name|fetchingTimer
decl_stmt|;
end_decl_stmt
begin_struct
struct|struct
name|Fetching
block|{
name|QString
name|dir
decl_stmt|;
name|QString
name|file
decl_stmt|;
specifier|const
name|QFileSystemNode
modifier|*
name|node
decl_stmt|;
block|}
struct|;
end_struct
begin_expr_stmt
name|QList
operator|<
name|Fetching
operator|>
name|toFetch
expr_stmt|;
end_expr_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FILESYSTEMMODEL
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
