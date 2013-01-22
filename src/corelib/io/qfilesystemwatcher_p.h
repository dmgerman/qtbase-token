begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFILESYSTEMWATCHER_P_H
end_ifndef
begin_define
DECL|macro|QFILESYSTEMWATCHER_P_H
define|#
directive|define
name|QFILESYSTEMWATCHER_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"qfilesystemwatcher.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_FILESYSTEMWATCHER
end_ifndef
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QFileSystemWatcherEngine
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|protected
operator|:
specifier|inline
name|QFileSystemWatcherEngine
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
operator|:
name|QObject
argument_list|(
argument|parent
argument_list|)
block|{     }
name|public
operator|:
comment|// fills \a files and \a directories with the \a paths it could
comment|// watch, and returns a list of paths this engine could not watch
name|virtual
name|QStringList
name|addPaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|,
name|QStringList
operator|*
name|files
argument_list|,
name|QStringList
operator|*
name|directories
argument_list|)
operator|=
literal|0
block|;
comment|// removes \a paths from \a files and \a directories, and returns
comment|// a list of paths this engine does not know about (either addPath
comment|// failed or wasn't called)
name|virtual
name|QStringList
name|removePaths
argument_list|(
specifier|const
name|QStringList
operator|&
name|paths
argument_list|,
name|QStringList
operator|*
name|files
argument_list|,
name|QStringList
operator|*
name|directories
argument_list|)
operator|=
literal|0
block|;
name|Q_SIGNALS
operator|:
name|void
name|fileChanged
argument_list|(
argument|const QString&path
argument_list|,
argument|bool removed
argument_list|)
block|;
name|void
name|directoryChanged
argument_list|(
argument|const QString&path
argument_list|,
argument|bool removed
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QFileSystemWatcherPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QFileSystemWatcher
argument_list|)
specifier|static
name|QFileSystemWatcherEngine
operator|*
name|createNativeEngine
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
name|public
operator|:
name|QFileSystemWatcherPrivate
argument_list|()
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|initPollerEngine
argument_list|()
block|;
name|QFileSystemWatcherEngine
operator|*
name|native
block|,
operator|*
name|poller
block|;
name|QStringList
name|files
block|,
name|directories
block|;
comment|// private slots
name|void
name|_q_fileChanged
argument_list|(
argument|const QString&path
argument_list|,
argument|bool removed
argument_list|)
block|;
name|void
name|_q_directoryChanged
argument_list|(
argument|const QString&path
argument_list|,
argument|bool removed
argument_list|)
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
comment|// QT_NO_FILESYSTEMWATCHER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFILESYSTEMWATCHER_P_H
end_comment
end_unit
