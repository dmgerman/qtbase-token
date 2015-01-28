begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qthreadstorage.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_THREAD
end_ifndef
begin_include
include|#
directive|include
file|"qthread.h"
end_include
begin_include
include|#
directive|include
file|"qthread_p.h"
end_include
begin_include
include|#
directive|include
file|"qmutex.h"
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// #define THREADSTORAGE_DEBUG
ifdef|#
directive|ifdef
name|THREADSTORAGE_DEBUG
DECL|macro|DEBUG_MSG
define|#
directive|define
name|DEBUG_MSG
value|qtsDebug
include|#
directive|include
file|<stdio.h>
include|#
directive|include
file|<stdarg.h>
DECL|function|qtsDebug
name|void
name|qtsDebug
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|va
decl_stmt|;
name|va_start
argument_list|(
name|va
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"QThreadStorage: "
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|va
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|DEBUG_MSG
value|if(false)qDebug
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|destructorsMutex
specifier|static
name|QBasicMutex
name|destructorsMutex
decl_stmt|;
end_decl_stmt
begin_typedef
DECL|typedef|DestructorMap
typedef|typedef
name|QVector
argument_list|<
name|void
operator|(
operator|*
operator|)
operator|(
name|void
modifier|*
operator|)
argument_list|>
name|DestructorMap
typedef|;
end_typedef
begin_macro
name|Q_GLOBAL_STATIC
argument_list|(
argument|DestructorMap
argument_list|,
argument|destructors
argument_list|)
end_macro
begin_constructor
DECL|function|QThreadStorageData
name|QThreadStorageData
operator|::
name|QThreadStorageData
parameter_list|(
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
block|{
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|destructorsMutex
argument_list|)
decl_stmt|;
name|DestructorMap
modifier|*
name|destr
init|=
name|destructors
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|destr
condition|)
block|{
comment|/*          the destructors vector has already been destroyed, yet a new          QThreadStorage is being allocated. this can only happen during global          destruction, at which point we assume that there is only one thread.          in order to keep QThreadStorage working, we need somewhere to store          the data, best place we have in this situation is at the tail of the          current thread's tls vector. the destructor is ignored, since we have          no where to store it, and no way to actually call it.          */
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|current
argument_list|()
decl_stmt|;
name|id
operator|=
name|data
operator|->
name|tls
operator|.
name|count
argument_list|()
expr_stmt|;
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Allocated id %d, destructor %p cannot be stored"
argument_list|,
name|id
argument_list|,
name|func
argument_list|)
expr_stmt|;
return|return;
block|}
for|for
control|(
name|id
operator|=
literal|0
init|;
name|id
operator|<
name|destr
operator|->
name|count
argument_list|()
condition|;
name|id
operator|++
control|)
block|{
if|if
condition|(
name|destr
operator|->
name|at
argument_list|(
name|id
argument_list|)
operator|==
literal|0
condition|)
break|break;
block|}
if|if
condition|(
name|id
operator|==
name|destr
operator|->
name|count
argument_list|()
condition|)
block|{
name|destr
operator|->
name|append
argument_list|(
name|func
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
operator|*
name|destr
operator|)
index|[
name|id
index|]
operator|=
name|func
expr_stmt|;
block|}
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Allocated id %d, destructor %p"
argument_list|,
name|id
argument_list|,
name|func
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QThreadStorageData
name|QThreadStorageData
operator|::
name|~
name|QThreadStorageData
parameter_list|()
block|{
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Released id %d"
argument_list|,
name|id
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|destructorsMutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|destructors
argument_list|()
condition|)
operator|(
operator|*
name|destructors
argument_list|()
operator|)
index|[
name|id
index|]
operator|=
literal|0
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|get
name|void
modifier|*
modifier|*
name|QThreadStorageData
operator|::
name|get
parameter_list|()
specifier|const
block|{
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|data
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThreadStorage::get: QThreadStorage can only be used with threads started with QThread"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QVector
argument_list|<
name|void
modifier|*
argument_list|>
modifier|&
name|tls
init|=
name|data
operator|->
name|tls
decl_stmt|;
if|if
condition|(
name|tls
operator|.
name|size
argument_list|()
operator|<=
name|id
condition|)
name|tls
operator|.
name|resize
argument_list|(
name|id
operator|+
literal|1
argument_list|)
expr_stmt|;
name|void
modifier|*
modifier|*
name|v
init|=
operator|&
name|tls
index|[
name|id
index|]
decl_stmt|;
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Returning storage %d, data %p, for thread %p"
argument_list|,
name|id
argument_list|,
operator|*
name|v
argument_list|,
name|data
operator|->
name|thread
argument_list|)
expr_stmt|;
return|return
operator|*
name|v
condition|?
name|v
else|:
literal|0
return|;
block|}
end_function
begin_function
DECL|function|set
name|void
modifier|*
modifier|*
name|QThreadStorageData
operator|::
name|set
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|QThreadData
modifier|*
name|data
init|=
name|QThreadData
operator|::
name|current
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|data
condition|)
block|{
name|qWarning
argument_list|(
literal|"QThreadStorage::set: QThreadStorage can only be used with threads started with QThread"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QVector
argument_list|<
name|void
modifier|*
argument_list|>
modifier|&
name|tls
init|=
name|data
operator|->
name|tls
decl_stmt|;
if|if
condition|(
name|tls
operator|.
name|size
argument_list|()
operator|<=
name|id
condition|)
name|tls
operator|.
name|resize
argument_list|(
name|id
operator|+
literal|1
argument_list|)
expr_stmt|;
name|void
modifier|*
modifier|&
name|value
init|=
name|tls
index|[
name|id
index|]
decl_stmt|;
comment|// delete any previous data
if|if
condition|(
name|value
operator|!=
literal|0
condition|)
block|{
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Deleting previous storage %d, data %p, for thread %p"
argument_list|,
name|id
argument_list|,
name|value
argument_list|,
name|data
operator|->
name|thread
argument_list|)
expr_stmt|;
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|destructorsMutex
argument_list|)
decl_stmt|;
name|DestructorMap
modifier|*
name|destr
init|=
name|destructors
argument_list|()
decl_stmt|;
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|destr
condition|?
name|destr
operator|->
name|value
argument_list|(
name|id
argument_list|)
operator|:
literal|0
function_decl|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
name|void
modifier|*
name|q
init|=
name|value
decl_stmt|;
name|value
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|destructor
condition|)
name|destructor
argument_list|(
name|q
argument_list|)
expr_stmt|;
block|}
comment|// store new data
name|value
operator|=
name|p
expr_stmt|;
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Set storage %d for thread %p to %p"
argument_list|,
name|id
argument_list|,
name|data
operator|->
name|thread
argument_list|,
name|p
argument_list|)
expr_stmt|;
return|return
operator|&
name|value
return|;
block|}
end_function
begin_function
DECL|function|finish
name|void
name|QThreadStorageData
operator|::
name|finish
parameter_list|(
name|void
modifier|*
modifier|*
name|p
parameter_list|)
block|{
name|QVector
argument_list|<
name|void
modifier|*
argument_list|>
modifier|*
name|tls
init|=
cast|reinterpret_cast
argument_list|<
name|QVector
argument_list|<
name|void
operator|*
argument_list|>
operator|*
argument_list|>
argument_list|(
name|p
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|tls
operator|||
name|tls
operator|->
name|isEmpty
argument_list|()
operator|||
operator|!
name|destructors
argument_list|()
condition|)
return|return;
comment|// nothing to do
name|DEBUG_MSG
argument_list|(
literal|"QThreadStorageData: Destroying storage for thread %p"
argument_list|,
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|tls
operator|->
name|isEmpty
argument_list|()
condition|)
block|{
name|void
modifier|*
modifier|&
name|value
init|=
name|tls
operator|->
name|last
argument_list|()
decl_stmt|;
name|void
modifier|*
name|q
init|=
name|value
decl_stmt|;
name|value
operator|=
literal|0
expr_stmt|;
name|int
name|i
init|=
name|tls
operator|->
name|size
argument_list|()
operator|-
literal|1
decl_stmt|;
name|tls
operator|->
name|resize
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|q
condition|)
block|{
comment|// data already deleted
continue|continue;
block|}
name|QMutexLocker
name|locker
argument_list|(
operator|&
name|destructorsMutex
argument_list|)
decl_stmt|;
name|void
function_decl|(
modifier|*
name|destructor
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
init|=
name|destructors
argument_list|()
operator|->
name|value
argument_list|(
name|i
argument_list|)
function_decl|;
name|locker
operator|.
name|unlock
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|destructor
condition|)
block|{
if|if
condition|(
name|QThread
operator|::
name|currentThread
argument_list|()
condition|)
name|qWarning
argument_list|(
literal|"QThreadStorage: Thread %p exited after QThreadStorage %d destroyed"
argument_list|,
name|QThread
operator|::
name|currentThread
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|destructor
argument_list|(
name|q
argument_list|)
expr_stmt|;
comment|//crash here might mean the thread exited after qthreadstorage was destroyed
if|if
condition|(
name|tls
operator|->
name|size
argument_list|()
operator|>
name|i
condition|)
block|{
comment|//re reset the tls in case it has been recreated by its own destructor.
operator|(
operator|*
name|tls
operator|)
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|tls
operator|->
name|clear
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QThreadStorage     \inmodule QtCore     \brief The QThreadStorage class provides per-thread data storage.      \threadsafe      \ingroup thread      QThreadStorage is a template class that provides per-thread data     storage.      The setLocalData() function stores a single thread-specific value     for the calling thread. The data can be accessed later using     localData().      The hasLocalData() function allows the programmer to determine if     data has previously been set using the setLocalData() function.     This is also useful for lazy initializiation.      If T is a pointer type, QThreadStorage takes ownership of the data     (which must be created on the heap with \c new) and deletes it when     the thread exits, either normally or via termination.      For example, the following code uses QThreadStorage to store a     single cache for each thread that calls the cacheObject() and     removeFromCache() functions. The cache is automatically     deleted when the calling thread exits.      \snippet threads/threads.cpp 7     \snippet threads/threads.cpp 8     \snippet threads/threads.cpp 9      \section1 Caveats      \list      \li The QThreadStorage destructor does not delete per-thread data.     QThreadStorage only deletes per-thread data when the thread exits     or when setLocalData() is called multiple times.      \li QThreadStorage can be used to store data for the \c main()     thread. QThreadStorage deletes all data set for the \c main()     thread when QApplication is destroyed, regardless of whether or     not the \c main() thread has actually finished.      \endlist      \sa QThread */
end_comment
begin_comment
comment|/*!     \fn QThreadStorage::QThreadStorage()      Constructs a new per-thread data storage object. */
end_comment
begin_comment
comment|/*!     \fn QThreadStorage::~QThreadStorage()      Destroys the per-thread data storage object.      Note: The per-thread data stored is not deleted. Any data left     in QThreadStorage is leaked. Make sure that all threads using     QThreadStorage have exited before deleting the QThreadStorage.      \sa hasLocalData() */
end_comment
begin_comment
comment|/*!     \fn bool QThreadStorage::hasLocalData() const      If T is a pointer type, returns \c true if the calling thread has     non-zero data available.      If T is a value type, returns whether the data has already been     constructed by calling setLocalData or localData.      \sa localData() */
end_comment
begin_comment
comment|/*!     \fn T&QThreadStorage::localData()      Returns a reference to the data that was set by the calling     thread.      If no data has been set, this will create a default constructed     instance of type T.      \sa hasLocalData() */
end_comment
begin_comment
comment|/*!     \fn const T QThreadStorage::localData() const     \overload      Returns a copy of the data that was set by the calling thread.      \sa hasLocalData() */
end_comment
begin_comment
comment|/*!     \fn void QThreadStorage::setLocalData(T data)      Sets the local data for the calling thread to \a data. It can be     accessed later using the localData() functions.      If T is a pointer type, QThreadStorage takes ownership of the data     and deletes it automatically either when the thread exits (either     normally or via termination) or when setLocalData() is called again.      \sa localData(), hasLocalData() */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_THREAD
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
