begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHOSTINFO_P_H
end_ifndef
begin_define
DECL|macro|QHOSTINFO_P_H
define|#
directive|define
name|QHOSTINFO_P_H
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
comment|// of the QHostInfo class.  This header file may change from
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
file|"QtCore/qcoreapplication.h"
end_include
begin_include
include|#
directive|include
file|"private/qcoreapplication_p.h"
end_include
begin_include
include|#
directive|include
file|"QtNetwork/qhostinfo.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qmutex.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qwaitcondition.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qobject.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qpointer.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qthread.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qthreadpool.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qrunnable.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qqueue.h"
end_include
begin_include
include|#
directive|include
file|<QElapsedTimer>
end_include
begin_include
include|#
directive|include
file|<QCache>
end_include
begin_include
include|#
directive|include
file|<QNetworkSession>
end_include
begin_include
include|#
directive|include
file|<QSharedPointer>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QHostInfoResult
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
name|Q_SLOTS
operator|:
specifier|inline
name|void
name|emitResultsReady
argument_list|(
argument|const QHostInfo&info
argument_list|)
block|{
name|emit
name|resultsReady
argument_list|(
name|info
argument_list|)
block|;     }
name|Q_SIGNALS
operator|:
name|void
name|resultsReady
argument_list|(
specifier|const
name|QHostInfo
operator|&
name|info
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|// needs to be QObject because fromName calls tr()
end_comment
begin_decl_stmt
name|class
name|QHostInfoAgent
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
specifier|static
name|QHostInfo
name|fromName
argument_list|(
specifier|const
name|QString
operator|&
name|hostName
argument_list|)
block|;
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
specifier|static
name|QHostInfo
name|fromName
argument_list|(
specifier|const
name|QString
operator|&
name|hostName
argument_list|,
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|networkSession
argument_list|)
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QHostInfoPrivate
block|{
name|public
label|:
specifier|inline
name|QHostInfoPrivate
argument_list|()
operator|:
name|err
argument_list|(
name|QHostInfo
operator|::
name|NoError
argument_list|)
operator|,
name|errorStr
argument_list|(
name|QLatin1String
argument_list|(
name|QT_TRANSLATE_NOOP
argument_list|(
literal|"QHostInfo"
argument_list|,
literal|"Unknown error"
argument_list|)
argument_list|)
argument_list|)
operator|,
name|lookupId
argument_list|(
literal|0
argument_list|)
block|{     }
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
comment|//not a public API yet
specifier|static
name|QHostInfo
name|fromName
argument_list|(
specifier|const
name|QString
operator|&
name|hostName
argument_list|,
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|networkSession
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QHostInfo
operator|::
name|HostInfoError
name|err
expr_stmt|;
name|QString
name|errorStr
decl_stmt|;
name|QList
operator|<
name|QHostAddress
operator|>
name|addrs
expr_stmt|;
name|QString
name|hostName
decl_stmt|;
name|int
name|lookupId
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// These functions are outside of the QHostInfo class and strictly internal.
end_comment
begin_comment
comment|// Do NOT use them outside of QAbstractSocket.
end_comment
begin_function_decl
name|QHostInfo
name|Q_NETWORK_EXPORT
name|qt_qhostinfo_lookup
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|QObject
modifier|*
name|receiver
parameter_list|,
specifier|const
name|char
modifier|*
name|member
parameter_list|,
name|bool
modifier|*
name|valid
parameter_list|,
name|int
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|Q_AUTOTEST_EXPORT
name|qt_qhostinfo_clear_cache
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|Q_AUTOTEST_EXPORT
name|qt_qhostinfo_enable_cache
parameter_list|(
name|bool
name|e
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|Q_AUTOTEST_EXPORT
name|qt_qhostinfo_cache_inject
parameter_list|(
specifier|const
name|QString
modifier|&
name|hostname
parameter_list|,
specifier|const
name|QHostInfo
modifier|&
name|resolution
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|QHostInfoCache
block|{
name|public
label|:
name|QHostInfoCache
argument_list|()
expr_stmt|;
specifier|const
name|int
name|max_age
decl_stmt|;
comment|// seconds
name|QHostInfo
name|get
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
name|bool
modifier|*
name|valid
parameter_list|)
function_decl|;
name|void
name|put
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QHostInfo
modifier|&
name|info
parameter_list|)
function_decl|;
name|void
name|clear
parameter_list|()
function_decl|;
name|bool
name|isEnabled
parameter_list|()
function_decl|;
name|void
name|setEnabled
parameter_list|(
name|bool
name|e
parameter_list|)
function_decl|;
name|private
label|:
name|bool
name|enabled
decl_stmt|;
struct|struct
name|QHostInfoCacheElement
block|{
name|QHostInfo
name|info
decl_stmt|;
name|QElapsedTimer
name|age
decl_stmt|;
block|}
struct|;
name|QCache
operator|<
name|QString
operator|,
name|QHostInfoCacheElement
operator|>
name|cache
expr_stmt|;
name|QMutex
name|mutex
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|// the following classes are used for the (normal) case: We use multiple threads to lookup DNS
end_comment
begin_decl_stmt
name|class
name|QHostInfoRunnable
range|:
name|public
name|QRunnable
block|{
name|public
operator|:
name|QHostInfoRunnable
argument_list|(
argument|const QString&hn
argument_list|,
argument|int i
argument_list|)
block|;
name|void
name|run
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|QString
name|toBeLookedUp
block|;
name|int
name|id
block|;
name|QHostInfoResult
name|resultEmitter
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QAbstractHostInfoLookupManager
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
operator|~
name|QAbstractHostInfoLookupManager
argument_list|()
block|{}
name|virtual
name|void
name|clear
argument_list|()
operator|=
literal|0
block|;
name|QHostInfoCache
name|cache
block|;
name|protected
operator|:
name|QAbstractHostInfoLookupManager
argument_list|()
block|{}
specifier|static
name|QAbstractHostInfoLookupManager
operator|*
name|globalInstance
argument_list|()
block|;  }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QHostInfoLookupManager
range|:
name|public
name|QAbstractHostInfoLookupManager
block|{
name|Q_OBJECT
name|public
operator|:
name|QHostInfoLookupManager
argument_list|()
block|;
operator|~
name|QHostInfoLookupManager
argument_list|()
block|;
name|void
name|clear
argument_list|()
name|Q_DECL_OVERRIDE
block|;
name|void
name|work
argument_list|()
block|;
comment|// called from QHostInfo
name|void
name|scheduleLookup
argument_list|(
name|QHostInfoRunnable
operator|*
name|r
argument_list|)
block|;
name|void
name|abortLookup
argument_list|(
argument|int id
argument_list|)
block|;
comment|// called from QHostInfoRunnable
name|void
name|lookupFinished
argument_list|(
name|QHostInfoRunnable
operator|*
name|r
argument_list|)
block|;
name|bool
name|wasAborted
argument_list|(
argument|int id
argument_list|)
block|;
name|friend
name|class
name|QHostInfoRunnable
block|;
name|protected
operator|:
name|QList
operator|<
name|QHostInfoRunnable
operator|*
operator|>
name|currentLookups
block|;
comment|// in progress
name|QList
operator|<
name|QHostInfoRunnable
operator|*
operator|>
name|postponedLookups
block|;
comment|// postponed because in progress for same host
name|QQueue
operator|<
name|QHostInfoRunnable
operator|*
operator|>
name|scheduledLookups
block|;
comment|// not yet started
name|QList
operator|<
name|QHostInfoRunnable
operator|*
operator|>
name|finishedLookups
block|;
comment|// recently finished
name|QList
operator|<
name|int
operator|>
name|abortedLookups
block|;
comment|// ids of aborted lookups
name|QThreadPool
name|threadPool
block|;
name|QMutex
name|mutex
block|;
name|bool
name|wasDeleted
block|;
name|private
name|slots
operator|:
name|void
name|waitForThreadPoolDone
argument_list|()
block|{
name|threadPool
operator|.
name|waitForDone
argument_list|()
block|; }
block|}
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
comment|// QHOSTINFO_P_H
end_comment
end_unit
