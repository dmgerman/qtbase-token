begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QRESOURCE_P_H
end_ifndef
begin_define
DECL|macro|QRESOURCE_P_H
define|#
directive|define
name|QRESOURCE_P_H
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
file|"qabstractfileengine_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QResourceFileEnginePrivate
name|class
name|QResourceFileEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QResourceFileEngine
range|:
name|public
name|QAbstractFileEngine
block|{
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QResourceFileEngine
argument_list|)
name|public
operator|:
name|explicit
name|QResourceFileEngine
argument_list|(
specifier|const
name|QString
operator|&
name|path
argument_list|)
block|;
operator|~
name|QResourceFileEngine
argument_list|()
block|;
name|virtual
name|void
name|setFileName
argument_list|(
argument|const QString&file
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|open
argument_list|(
argument|QIODevice::OpenMode flags
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|close
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|flush
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qint64
name|size
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qint64
name|pos
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|atEnd
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|seek
argument_list|(
argument|qint64
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qint64
name|read
argument_list|(
argument|char *data
argument_list|,
argument|qint64 maxlen
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|qint64
name|write
argument_list|(
argument|const char *data
argument_list|,
argument|qint64 len
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|remove
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|copy
argument_list|(
argument|const QString&newName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|rename
argument_list|(
argument|const QString&newName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|link
argument_list|(
argument|const QString&newName
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|isSequential
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|isRelativePath
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|mkdir
argument_list|(
argument|const QString&dirName
argument_list|,
argument|bool createParentDirectories
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|rmdir
argument_list|(
argument|const QString&dirName
argument_list|,
argument|bool recurseParentDirectories
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|setSize
argument_list|(
argument|qint64 size
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QStringList
name|entryList
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|caseSensitive
argument_list|()
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|FileFlags
name|fileFlags
argument_list|(
argument|FileFlags type
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|bool
name|setPermissions
argument_list|(
argument|uint perms
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|fileName
argument_list|(
argument|QAbstractFileEngine::FileName file
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|uint
name|ownerId
argument_list|(
argument|FileOwner
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QString
name|owner
argument_list|(
argument|FileOwner
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|QDateTime
name|fileTime
argument_list|(
argument|FileTime time
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|Iterator
operator|*
name|beginEntryList
argument_list|(
argument|QDir::Filters filters
argument_list|,
argument|const QStringList&filterNames
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|virtual
name|Iterator
operator|*
name|endEntryList
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|bool
name|extension
argument_list|(
argument|Extension extension
argument_list|,
argument|const ExtensionOption *option =
literal|0
argument_list|,
argument|ExtensionReturn *output =
literal|0
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|bool
name|supportsExtension
argument_list|(
argument|Extension extension
argument_list|)
specifier|const
name|Q_DECL_OVERRIDE
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
comment|// QRESOURCE_P_H
end_comment
end_unit
