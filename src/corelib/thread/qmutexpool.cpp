begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
name|QMutexPool
argument_list|,
name|globalMutexPool
argument_list|,
operator|(
name|QMutex
operator|::
name|Recursive
operator|)
argument_list|)
comment|/*!     \class QMutexPool     \inmodule QtCore     \brief The QMutexPool class provides a pool of QMutex objects.      \internal      \ingroup thread      QMutexPool is a convenience class that provides access to a fixed     number of QMutex objects.      Typical use of a QMutexPool is in situations where it is not     possible or feasible to use one QMutex for every protected object.     The mutex pool will return a mutex based on the address of the     object that needs protection.      For example, consider this simple class:      \snippet code/src_corelib_thread_qmutexpool.cpp 0      Adding a QMutex member to the Number class does not make sense,     because it is so small. However, in order to ensure that access to     each Number is protected, you need to use a mutex. In this case, a     QMutexPool would be ideal.      Code to calculate the square of a number would then look something     like this:      \snippet code/src_corelib_thread_qmutexpool.cpp 1      This function will safely calculate the square of a number, since     it uses a mutex from a QMutexPool. The mutex is locked and     unlocked automatically by the QMutexLocker class. See the     QMutexLocker documentation for more details. */
comment|/*!     Constructs  a QMutexPool, reserving space for \a size QMutexes. All     mutexes in the pool are created with \a recursionMode. By default,     all mutexes are non-recursive.      The QMutexes are created when needed, and deleted when the     QMutexPool is destructed. */
DECL|function|QMutexPool
name|QMutexPool
operator|::
name|QMutexPool
argument_list|(
name|QMutex
operator|::
name|RecursionMode
name|recursionMode
argument_list|,
name|int
name|size
argument_list|)
range|:
name|count
argument_list|(
name|size
argument_list|)
decl_stmt|,
name|mutexes
argument_list|(
operator|new
name|QAtomicPointer
argument_list|<
name|QMutex
argument_list|>
index|[
name|size
index|]
operator|(
operator|)
argument_list|)
decl_stmt|,
comment|// (): zero-initialize
name|recursionMode
argument_list|(
name|recursionMode
argument_list|)
argument_list|{ }
comment|/*!     Destructs a QMutexPool. All QMutexes that were created by the pool     are deleted. */
DECL|function|~QMutexPool
name|QMutexPool
operator|::
name|~
name|QMutexPool
argument_list|()
argument_list|{
name|qDeleteAll
argument_list|(
name|mutexes
argument_list|,
name|mutexes
operator|+
name|count
argument_list|)
argument_list|;
operator|delete
index|[]
name|mutexes
argument_list|; }
comment|/*!     Returns the global QMutexPool instance. */
DECL|function|instance
name|QMutexPool
modifier|*
name|QMutexPool
operator|::
name|instance
argument_list|()
argument_list|{     return
name|globalMutexPool
argument_list|()
argument_list|; }
comment|/*!     \fn QMutexPool::get(const void *address)     Returns a QMutex from the pool. QMutexPool uses the value \a address     to determine which mutex is returned from the pool. */
comment|/*!     \internal   create the mutex for the given index  */
DECL|function|createMutex
name|QMutex
modifier|*
name|QMutexPool
operator|::
name|createMutex
argument_list|(
name|int
name|index
argument_list|)
argument_list|{
comment|// mutex not created, create one
name|QMutex
operator|*
name|newMutex
operator|=
operator|new
name|QMutex
argument_list|(
name|recursionMode
argument_list|)
argument_list|;     if
operator|(
operator|!
name|mutexes
index|[
name|index
index|]
operator|.
name|testAndSetRelease
argument_list|(
literal|0
argument_list|,
name|newMutex
argument_list|)
operator|)
operator|delete
name|newMutex
argument_list|;     return
name|mutexes
index|[
name|index
index|]
operator|.
name|load
argument_list|()
argument_list|; }
comment|/*!     Returns a QMutex from the global mutex pool. */
DECL|function|globalInstanceGet
name|QMutex
modifier|*
name|QMutexPool
operator|::
name|globalInstanceGet
argument_list|(
specifier|const
name|void
operator|*
name|address
argument_list|)
argument_list|{
name|QMutexPool
operator|*
specifier|const
name|globalInstance
operator|=
name|globalMutexPool
argument_list|()
argument_list|;     if
operator|(
name|globalInstance
operator|==
literal|0
operator|)
return|return
literal|0
return|;
end_decl_stmt
begin_return
return|return
name|globalInstance
operator|->
name|get
argument_list|(
name|address
argument_list|)
return|;
end_return
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
end_unit
