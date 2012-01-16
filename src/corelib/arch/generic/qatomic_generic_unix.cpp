begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_RVCT
argument_list|)
operator|)
end_if
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qatomic.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|qAtomicMutex
specifier|static
name|pthread_mutex_t
name|qAtomicMutex
init|=
name|PTHREAD_MUTEX_INITIALIZER
decl_stmt|;
end_decl_stmt
begin_function
name|Q_CORE_EXPORT
DECL|function|QBasicAtomicInt_testAndSetOrdered
name|bool
name|QBasicAtomicInt_testAndSetOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|expectedValue
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|bool
name|returnValue
init|=
literal|false
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
operator|*
name|_q_value
operator|=
name|newValue
expr_stmt|;
name|returnValue
operator|=
literal|true
expr_stmt|;
block|}
name|pthread_mutex_unlock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
name|Q_CORE_EXPORT
DECL|function|QBasicAtomicInt_fetchAndStoreOrdered
name|int
name|QBasicAtomicInt_fetchAndStoreOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|newValue
parameter_list|)
block|{
name|int
name|returnValue
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
name|returnValue
operator|=
operator|*
name|_q_value
expr_stmt|;
operator|*
name|_q_value
operator|=
name|newValue
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
name|Q_CORE_EXPORT
DECL|function|QBasicAtomicInt_fetchAndAddOrdered
name|int
name|QBasicAtomicInt_fetchAndAddOrdered
parameter_list|(
specifier|volatile
name|int
modifier|*
name|_q_value
parameter_list|,
name|int
name|valueToAdd
parameter_list|)
block|{
name|int
name|returnValue
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
name|returnValue
operator|=
operator|*
name|_q_value
expr_stmt|;
operator|*
name|_q_value
operator|+=
name|valueToAdd
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
name|Q_CORE_EXPORT
DECL|function|QBasicAtomicPointer_testAndSetOrdered
name|bool
name|QBasicAtomicPointer_testAndSetOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|expectedValue
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|bool
name|returnValue
init|=
literal|false
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|_q_value
operator|==
name|expectedValue
condition|)
block|{
operator|*
name|_q_value
operator|=
name|newValue
expr_stmt|;
name|returnValue
operator|=
literal|true
expr_stmt|;
block|}
name|pthread_mutex_unlock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
name|Q_CORE_EXPORT
DECL|function|QBasicAtomicPointer_fetchAndStoreOrdered
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndStoreOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|void
modifier|*
name|newValue
parameter_list|)
block|{
name|void
modifier|*
name|returnValue
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
name|returnValue
operator|=
operator|*
name|_q_value
expr_stmt|;
operator|*
name|_q_value
operator|=
name|newValue
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
return|return
name|returnValue
return|;
block|}
end_function
begin_function
name|Q_CORE_EXPORT
DECL|function|QBasicAtomicPointer_fetchAndAddOrdered
name|void
modifier|*
name|QBasicAtomicPointer_fetchAndAddOrdered
parameter_list|(
name|void
modifier|*
specifier|volatile
modifier|*
name|_q_value
parameter_list|,
name|qptrdiff
name|valueToAdd
parameter_list|)
block|{
name|void
modifier|*
name|returnValue
decl_stmt|;
name|pthread_mutex_lock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
name|returnValue
operator|=
operator|*
name|_q_value
expr_stmt|;
operator|*
name|_q_value
operator|=
cast|reinterpret_cast
argument_list|<
name|char
operator|*
argument_list|>
argument_list|(
name|returnValue
argument_list|)
operator|+
name|valueToAdd
expr_stmt|;
name|pthread_mutex_unlock
argument_list|(
operator|&
name|qAtomicMutex
argument_list|)
expr_stmt|;
return|return
name|returnValue
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
comment|//!defined(Q_OS_SYMBIAN)&& !defined(Q_CC_RVCT)
end_comment
end_unit
