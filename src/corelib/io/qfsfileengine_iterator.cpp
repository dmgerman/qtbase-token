begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qfsfileengine_iterator_p.h"
end_include
begin_include
include|#
directive|include
file|"qfileinfo_p.h"
end_include
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FSFILEENGINE
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QFSFileEngineIterator
name|QFSFileEngineIterator
operator|::
name|QFSFileEngineIterator
parameter_list|(
name|QDir
operator|::
name|Filters
name|filters
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|filterNames
parameter_list|)
member_init_list|:
name|QAbstractFileEngineIterator
argument_list|(
name|filters
argument_list|,
name|filterNames
argument_list|)
member_init_list|,
name|done
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QFSFileEngineIterator
name|QFSFileEngineIterator
operator|::
name|~
name|QFSFileEngineIterator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|hasNext
name|bool
name|QFSFileEngineIterator
operator|::
name|hasNext
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|done
operator|&&
operator|!
name|nativeIterator
condition|)
block|{
name|nativeIterator
operator|.
name|reset
argument_list|(
operator|new
name|QFileSystemIterator
argument_list|(
name|QFileSystemEntry
argument_list|(
name|path
argument_list|()
argument_list|)
argument_list|,
name|filters
argument_list|()
argument_list|,
name|nameFilters
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|advance
argument_list|()
expr_stmt|;
block|}
return|return
operator|!
name|done
return|;
block|}
end_function
begin_function
DECL|function|next
name|QString
name|QFSFileEngineIterator
operator|::
name|next
parameter_list|()
block|{
if|if
condition|(
operator|!
name|hasNext
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
name|advance
argument_list|()
expr_stmt|;
return|return
name|currentFilePath
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|advance
name|void
name|QFSFileEngineIterator
operator|::
name|advance
parameter_list|()
specifier|const
block|{
name|currentInfo
operator|=
name|nextInfo
expr_stmt|;
name|QFileSystemEntry
name|entry
decl_stmt|;
name|QFileSystemMetaData
name|data
decl_stmt|;
if|if
condition|(
name|nativeIterator
operator|->
name|advance
argument_list|(
name|entry
argument_list|,
name|data
argument_list|)
condition|)
block|{
name|nextInfo
operator|=
name|QFileInfo
argument_list|(
operator|new
name|QFileInfoPrivate
argument_list|(
name|entry
argument_list|,
name|data
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|done
operator|=
literal|true
expr_stmt|;
name|nativeIterator
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|currentFileName
name|QString
name|QFSFileEngineIterator
operator|::
name|currentFileName
parameter_list|()
specifier|const
block|{
return|return
name|currentInfo
operator|.
name|fileName
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|currentFileInfo
name|QFileInfo
name|QFSFileEngineIterator
operator|::
name|currentFileInfo
parameter_list|()
specifier|const
block|{
return|return
name|currentInfo
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_FSFILEENGINE
end_comment
end_unit
