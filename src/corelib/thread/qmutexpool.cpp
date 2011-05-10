begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qatomic.h"
end_include
begin_include
include|#
directive|include
file|"qmutexpool_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|// qt_global_mutexpool is here for backwards compatibility only,
comment|// use QMutexpool::instance() in new clode.
DECL|variable|qt_global_mutexpool
name|Q_CORE_EXPORT
name|QMutexPool
modifier|*
name|qt_global_mutexpool
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|QMutexPool
argument_list|,
argument|globalMutexPool
argument_list|,
argument|(QMutex::Recursive)
argument_list|)
end_macro
begin_comment
comment|/*!     \class QMutexPool     \brief The QMutexPool class provides a pool of QMutex objects.      \internal      \ingroup thread      QMutexPool is a convenience class that provides access to a fixed     number of QMutex objects.      Typical use of a QMutexPool is in situations where it is not     possible or feasible to use one QMutex for every protected object.     The mutex pool will return a mutex based on the address of the     object that needs protection.      For example, consider this simple class:      \snippet doc/src/snippets/code/src_corelib_thread_qmutexpool.cpp 0      Adding a QMutex member to the Number class does not make sense,     because it is so small. However, in order to ensure that access to     each Number is protected, you need to use a mutex. In this case, a     QMutexPool would be ideal.      Code to calculate the square of a number would then look something     like this:      \snippet doc/src/snippets/code/src_corelib_thread_qmutexpool.cpp 1      This function will safely calculate the square of a number, since     it uses a mutex from a QMutexPool. The mutex is locked and     unlocked automatically by the QMutexLocker class. See the     QMutexLocker documentation for more details. */
end_comment
begin_comment
comment|/*!     Constructs  a QMutexPool, reserving space for \a size QMutexes. All     mutexes in the pool are created with \a recursionMode. By default,     all mutexes are non-recursive.      The QMutexes are created when needed, and deleted when the     QMutexPool is destructed. */
end_comment
begin_constructor
DECL|function|QMutexPool
name|QMutexPool
operator|::
name|QMutexPool
parameter_list|(
name|QMutex
operator|::
name|RecursionMode
name|recursionMode
parameter_list|,
name|int
name|size
parameter_list|)
member_init_list|:
name|mutexes
argument_list|(
name|size
argument_list|)
member_init_list|,
name|recursionMode
argument_list|(
name|recursionMode
argument_list|)
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
name|mutexes
operator|.
name|count
argument_list|()
condition|;
operator|++
name|index
control|)
block|{
name|mutexes
index|[
name|index
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_constructor
begin_comment
comment|/*!     Destructs a QMutexPool. All QMutexes that were created by the pool     are deleted. */
end_comment
begin_destructor
DECL|function|~QMutexPool
name|QMutexPool
operator|::
name|~
name|QMutexPool
parameter_list|()
block|{
for|for
control|(
name|int
name|index
init|=
literal|0
init|;
name|index
operator|<
name|mutexes
operator|.
name|count
argument_list|()
condition|;
operator|++
name|index
control|)
block|{
operator|delete
name|mutexes
index|[
name|index
index|]
expr_stmt|;
name|mutexes
index|[
name|index
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_destructor
begin_comment
comment|/*!     Returns the global QMutexPool instance. */
end_comment
begin_function
DECL|function|instance
name|QMutexPool
modifier|*
name|QMutexPool
operator|::
name|instance
parameter_list|()
block|{
return|return
name|globalMutexPool
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QMutexPool::get(const void *address)     Returns a QMutex from the pool. QMutexPool uses the value \a address     to determine which mutex is returned from the pool. */
end_comment
begin_comment
comment|/*! \internal   create the mutex for the given index  */
end_comment
begin_function
DECL|function|createMutex
name|QMutex
modifier|*
name|QMutexPool
operator|::
name|createMutex
parameter_list|(
name|int
name|index
parameter_list|)
block|{
comment|// mutex not created, create one
name|QMutex
modifier|*
name|newMutex
init|=
operator|new
name|QMutex
argument_list|(
name|recursionMode
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|mutexes
index|[
name|index
index|]
operator|.
name|testAndSetOrdered
argument_list|(
literal|0
argument_list|,
name|newMutex
argument_list|)
condition|)
operator|delete
name|newMutex
expr_stmt|;
return|return
name|mutexes
index|[
name|index
index|]
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a QMutex from the global mutex pool. */
end_comment
begin_function
DECL|function|globalInstanceGet
name|QMutex
modifier|*
name|QMutexPool
operator|::
name|globalInstanceGet
parameter_list|(
specifier|const
name|void
modifier|*
name|address
parameter_list|)
block|{
name|QMutexPool
modifier|*
specifier|const
name|globalInstance
init|=
name|globalMutexPool
argument_list|()
decl_stmt|;
if|if
condition|(
name|globalInstance
operator|==
literal|0
condition|)
return|return
literal|0
return|;
return|return
name|globalInstance
operator|->
name|get
argument_list|(
name|address
argument_list|)
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
comment|// QT_NO_THREAD
end_comment
end_unit
