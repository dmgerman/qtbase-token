begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMSEMAPHORE_H
end_ifndef
begin_define
DECL|macro|QSYSTEMSEMAPHORE_H
define|#
directive|define
name|QSYSTEMSEMAPHORE_H
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
ifndef|#
directive|ifndef
name|QT_NO_SYSTEMSEMAPHORE
DECL|variable|QSystemSemaphorePrivate
name|class
name|QSystemSemaphorePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSystemSemaphore
block|{
name|public
label|:
enum|enum
name|AccessMode
block|{
name|Open
block|,
name|Create
block|}
enum|;
enum|enum
name|SystemSemaphoreError
block|{
name|NoError
block|,
name|PermissionDenied
block|,
name|KeyError
block|,
name|AlreadyExists
block|,
name|NotFound
block|,
name|OutOfResources
block|,
name|UnknownError
block|}
enum|;
name|QSystemSemaphore
argument_list|(
argument|const QString&key
argument_list|,
argument|int initialValue =
literal|0
argument_list|,
argument|AccessMode mode = Open
argument_list|)
empty_stmt|;
operator|~
name|QSystemSemaphore
argument_list|()
expr_stmt|;
name|void
name|setKey
parameter_list|(
specifier|const
name|QString
modifier|&
name|key
parameter_list|,
name|int
name|initialValue
init|=
literal|0
parameter_list|,
name|AccessMode
name|mode
init|=
name|Open
parameter_list|)
function_decl|;
name|QString
name|key
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|acquire
parameter_list|()
function_decl|;
name|bool
name|release
parameter_list|(
name|int
name|n
init|=
literal|1
parameter_list|)
function_decl|;
name|SystemSemaphoreError
name|error
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|errorString
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSystemSemaphore
argument_list|)
name|QScopedPointer
operator|<
name|QSystemSemaphorePrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SYSTEMSEMAPHORE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMSEMAPHORE_H
end_comment
end_unit
