begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 David Faure<faure+bluesystems@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QLOCKFILE_H
end_ifndef
begin_define
DECL|macro|QLOCKFILE_H
define|#
directive|define
name|QLOCKFILE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QLockFilePrivate
name|class
name|QLockFilePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QLockFile
block|{
name|public
label|:
name|QLockFile
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|)
expr_stmt|;
operator|~
name|QLockFile
argument_list|()
expr_stmt|;
name|bool
name|lock
parameter_list|()
function_decl|;
name|bool
name|tryLock
parameter_list|(
name|int
name|timeout
init|=
literal|0
parameter_list|)
function_decl|;
name|void
name|unlock
parameter_list|()
function_decl|;
name|void
name|setStaleLockTime
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|int
name|staleLockTime
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isLocked
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|getLockInfo
argument_list|(
name|qint64
operator|*
name|pid
argument_list|,
name|QString
operator|*
name|hostname
argument_list|,
name|QString
operator|*
name|appname
argument_list|)
decl|const
decl_stmt|;
name|bool
name|removeStaleLockFile
parameter_list|()
function_decl|;
enum|enum
name|LockError
block|{
name|NoError
init|=
literal|0
block|,
name|LockFailedError
init|=
literal|1
block|,
name|PermissionError
init|=
literal|2
block|,
name|UnknownError
init|=
literal|3
block|}
enum|;
name|LockError
name|error
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
name|QScopedPointer
operator|<
name|QLockFilePrivate
operator|>
name|d_ptr
expr_stmt|;
name|private
label|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QLockFile
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QLockFile
argument_list|)
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QLOCKFILE_H
end_comment
end_unit
