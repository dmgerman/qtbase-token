begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWAITCONDITION_H
end_ifndef
begin_define
DECL|macro|QWAITCONDITION_H
define|#
directive|define
name|QWAITCONDITION_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
ifndef|#
directive|ifndef
name|QT_NO_THREAD
name|class
name|QWaitConditionPrivate
decl_stmt|;
DECL|variable|QMutex
name|class
name|QMutex
decl_stmt|;
DECL|variable|QReadWriteLock
name|class
name|QReadWriteLock
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QWaitCondition
decl_stmt|{ public:     QWaitCondition(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
operator|~
name|QWaitCondition
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|bool
name|wait
parameter_list|(
name|QMutex
modifier|*
name|mutex
parameter_list|,
name|unsigned
name|long
name|time
init|=
name|ULONG_MAX
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|wait
parameter_list|(
name|QReadWriteLock
modifier|*
name|readWriteLock
parameter_list|,
name|unsigned
name|long
name|time
init|=
name|ULONG_MAX
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|wakeOne
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|wakeAll
parameter_list|()
function_decl|;
end_function_decl
begin_label
name|private
label|:
end_label
begin_macro
name|Q_DISABLE_COPY
argument_list|(
argument|QWaitCondition
argument_list|)
end_macro
begin_decl_stmt
name|QWaitConditionPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_else
unit|};
else|#
directive|else
end_else
begin_decl_stmt
name|class
name|QMutex
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QWaitCondition
block|{
name|public
label|:
name|QWaitCondition
argument_list|()
block|{}
operator|~
name|QWaitCondition
argument_list|()
block|{}
name|bool
name|wait
argument_list|(
argument|QMutex *mutex
argument_list|,
argument|unsigned long time = ULONG_MAX
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|mutex
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|time
argument_list|)
block|;
return|return
name|true
return|;
block|}
name|void
name|wakeOne
parameter_list|()
block|{}
name|void
name|wakeAll
parameter_list|()
block|{}
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
comment|// QT_NO_THREAD
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
comment|// QWAITCONDITION_H
end_comment
end_unit
