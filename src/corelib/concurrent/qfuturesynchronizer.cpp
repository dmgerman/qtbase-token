begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*! \class QFutureSynchronizer     \since 4.4      \brief The QFutureSynchronizer class is a convenience class that simplifies     QFuture synchronization.      \ingroup thread      QFutureSynchronizer is a template class that simplifies synchronization of     one or more QFuture objects. Futures are added using the addFuture() or     setFuture() functions. The futures() function returns a list of futures.     Use clearFutures() to remove all futures from the QFutureSynchronizer.          The waitForFinished() function waits for all futures to finish.     The destructor of QFutureSynchronizer calls waitForFinished(), providing     an easy way to ensure that all futures have finished before returning from     a function:          \snippet doc/src/snippets/code/src_corelib_concurrent_qfuturesynchronizer.cpp 0          The behavior of waitForFinished() can be changed using the     setCancelOnWait() function. Calling setCancelOnWait(true) will cause     waitForFinished() to cancel all futures before waiting for them to finish.     You can query the status of the cancel-on-wait feature using the     cancelOnWait() function.          \sa QFuture, QFutureWatcher, {Concurrent Programming}{Qt Concurrent} */
end_comment
begin_comment
comment|/*!     \fn QFutureSynchronizer::QFutureSynchronizer()      Constructs a QFutureSynchronizer. */
end_comment
begin_comment
comment|/*!     \fn QFutureSynchronizer::QFutureSynchronizer(const QFuture<T>&future)      Constructs a QFutureSynchronizer and begins watching \a future by calling     addFuture().          \sa addFuture() */
end_comment
begin_comment
comment|/*!     \fn QFutureSynchronizer::~QFutureSynchronizer()          Calls waitForFinished() function to ensure that all futures have finished     before destroying this QFutureSynchronizer.          \sa waitForFinished() */
end_comment
begin_comment
comment|/*!     \fn void QFutureSynchronizer::setFuture(const QFuture<T>&future)          Sets \a future to be the only future managed by this QFutureSynchronizer.     This is a convenience function that calls waitForFinished(),     then clearFutures(), and finally passes \a future to addFuture().          \sa addFuture(), waitForFinished(), clearFutures() */
end_comment
begin_comment
comment|/*!     \fn void QFutureSynchronizer::addFuture(const QFuture<T>&future)      Adds \a future to the list of managed futures.          \sa futures() */
end_comment
begin_comment
comment|/*!     \fn void QFutureSynchronizer::waitForFinished()      Waits for all futures to finish. If cancelOnWait() returns true, each     future is canceled before waiting for them to finish.          \sa cancelOnWait(), setCancelOnWait() */
end_comment
begin_comment
comment|/*!     \fn void QFutureSynchronizer::clearFutures()      Removes all managed futures from this QFutureSynchronizer.          \sa addFuture(), setFuture()    */
end_comment
begin_comment
comment|/*!     \fn QList<QFuture<T>> QFutureSynchronizer::futures() const      Returns a list of all managed futures.          \sa addFuture(), setFuture() */
end_comment
begin_comment
comment|/*!     \fn void QFutureSynchronizer::setCancelOnWait(bool enabled)          Enables or disables the cancel-on-wait feature based on the \a enabled     argument. If \a enabled is true, the waitForFinished() function will cancel     all futures before waiting for them to finish.      \sa waitForFinished() */
end_comment
begin_comment
comment|/*!     \fn bool QFutureSynchronizer::cancelOnWait() const      Returns true if the cancel-on-wait feature is enabled; otherwise returns     false. If cancel-on-wait is enabled, the waitForFinished() function will     cancel all futures before waiting for them to finish.      \sa waitForFinished() */
end_comment
end_unit
