begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHAREDMEMORY_H
end_ifndef
begin_define
DECL|macro|QSHAREDMEMORY_H
define|#
directive|define
name|QSHAREDMEMORY_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SHAREDMEMORY
DECL|variable|QSharedMemoryPrivate
name|class
name|QSharedMemoryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSharedMemory
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSharedMemory
argument_list|)
name|public
operator|:
expr|enum
name|AccessMode
block|{
name|ReadOnly
block|,
name|ReadWrite
block|}
block|;      enum
name|SharedMemoryError
block|{
name|NoError
block|,
name|PermissionDenied
block|,
name|InvalidSize
block|,
name|KeyError
block|,
name|AlreadyExists
block|,
name|NotFound
block|,
name|LockError
block|,
name|OutOfResources
block|,
name|UnknownError
block|}
block|;
name|QSharedMemory
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QSharedMemory
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|,
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QSharedMemory
argument_list|()
block|;
name|void
name|setKey
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
block|;
name|QString
name|key
argument_list|()
specifier|const
block|;
name|void
name|setNativeKey
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
block|;
name|QString
name|nativeKey
argument_list|()
specifier|const
block|;
name|bool
name|create
argument_list|(
argument|int size
argument_list|,
argument|AccessMode mode = ReadWrite
argument_list|)
block|;
name|int
name|size
argument_list|()
specifier|const
block|;
name|bool
name|attach
argument_list|(
argument|AccessMode mode = ReadWrite
argument_list|)
block|;
name|bool
name|isAttached
argument_list|()
specifier|const
block|;
name|bool
name|detach
argument_list|()
block|;
name|void
operator|*
name|data
argument_list|()
block|;
specifier|const
name|void
operator|*
name|constData
argument_list|()
specifier|const
block|;
specifier|const
name|void
operator|*
name|data
argument_list|()
specifier|const
block|;
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
name|bool
name|lock
argument_list|()
block|;
name|bool
name|unlock
argument_list|()
block|;
endif|#
directive|endif
name|SharedMemoryError
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSharedMemory
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHAREDMEMORY
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSHAREDMEMORY_H
end_comment
end_unit
