begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFSFILEENGINE_ITERATOR_P_H
end_ifndef
begin_define
DECL|macro|QFSFILEENGINE_ITERATOR_P_H
define|#
directive|define
name|QFSFILEENGINE_ITERATOR_P_H
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
file|"private/qabstractfileengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qfilesystemiterator_p.h"
end_include
begin_include
include|#
directive|include
file|"qdir.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMITERATOR
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QFSFileEngineIteratorPrivate
name|class
name|QFSFileEngineIteratorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFSFileEngineIteratorPlatformSpecificData
name|class
name|QFSFileEngineIteratorPlatformSpecificData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFSFileEngineIterator
range|:
name|public
name|QAbstractFileEngineIterator
block|{
name|public
operator|:
name|QFSFileEngineIterator
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
block|;
operator|~
name|QFSFileEngineIterator
argument_list|()
block|;
name|QString
name|next
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|hasNext
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QString
name|currentFileName
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|QFileInfo
name|currentFileInfo
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|void
name|advance
argument_list|()
specifier|const
block|;
name|mutable
name|QScopedPointer
operator|<
name|QFileSystemIterator
operator|>
name|nativeIterator
block|;
name|mutable
name|QFileInfo
name|currentInfo
block|;
name|mutable
name|QFileInfo
name|nextInfo
block|;
name|mutable
name|bool
name|done
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
begin_comment
comment|// QT_NO_FILESYSTEMITERATOR
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFSFILEENGINE_ITERATOR_P_H
end_comment
end_unit
