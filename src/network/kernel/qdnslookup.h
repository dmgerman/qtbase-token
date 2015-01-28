begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Jeremy LainÃ©<jeremy.laine@m4x.org> ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDNSLOOKUP_H
end_ifndef
begin_define
DECL|macro|QDNSLOOKUP_H
define|#
directive|define
name|QDNSLOOKUP_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qsharedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QHostAddress
name|class
name|QHostAddress
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDnsLookupPrivate
name|class
name|QDnsLookupPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDnsDomainNameRecordPrivate
name|class
name|QDnsDomainNameRecordPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDnsHostAddressRecordPrivate
name|class
name|QDnsHostAddressRecordPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDnsMailExchangeRecordPrivate
name|class
name|QDnsMailExchangeRecordPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDnsServiceRecordPrivate
name|class
name|QDnsServiceRecordPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QDnsTextRecordPrivate
name|class
name|QDnsTextRecordPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QDnsDomainNameRecord
block|{
name|public
label|:
name|QDnsDomainNameRecord
argument_list|()
expr_stmt|;
name|QDnsDomainNameRecord
argument_list|(
specifier|const
name|QDnsDomainNameRecord
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDnsDomainNameRecord
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QDnsDomainNameRecord
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|quint32
name|timeToLive
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|value
argument_list|()
specifier|const
expr_stmt|;
name|QDnsDomainNameRecord
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDnsDomainNameRecord
operator|&
name|other
operator|)
decl_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QDnsDomainNameRecordPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDnsLookupRunnable
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QDnsDomainNameRecord
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QDnsHostAddressRecord
block|{
name|public
label|:
name|QDnsHostAddressRecord
argument_list|()
expr_stmt|;
name|QDnsHostAddressRecord
argument_list|(
specifier|const
name|QDnsHostAddressRecord
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDnsHostAddressRecord
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QDnsHostAddressRecord
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|quint32
name|timeToLive
argument_list|()
specifier|const
expr_stmt|;
name|QHostAddress
name|value
argument_list|()
specifier|const
expr_stmt|;
name|QDnsHostAddressRecord
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDnsHostAddressRecord
operator|&
name|other
operator|)
decl_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QDnsHostAddressRecordPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDnsLookupRunnable
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QDnsHostAddressRecord
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QDnsMailExchangeRecord
block|{
name|public
label|:
name|QDnsMailExchangeRecord
argument_list|()
expr_stmt|;
name|QDnsMailExchangeRecord
argument_list|(
specifier|const
name|QDnsMailExchangeRecord
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDnsMailExchangeRecord
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QDnsMailExchangeRecord
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|exchange
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|quint16
name|preference
argument_list|()
specifier|const
expr_stmt|;
name|quint32
name|timeToLive
argument_list|()
specifier|const
expr_stmt|;
name|QDnsMailExchangeRecord
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDnsMailExchangeRecord
operator|&
name|other
operator|)
decl_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QDnsMailExchangeRecordPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDnsLookupRunnable
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QDnsMailExchangeRecord
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QDnsServiceRecord
block|{
name|public
label|:
name|QDnsServiceRecord
argument_list|()
expr_stmt|;
name|QDnsServiceRecord
argument_list|(
specifier|const
name|QDnsServiceRecord
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDnsServiceRecord
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QDnsServiceRecord
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|quint16
name|port
argument_list|()
specifier|const
expr_stmt|;
name|quint16
name|priority
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|target
argument_list|()
specifier|const
expr_stmt|;
name|quint32
name|timeToLive
argument_list|()
specifier|const
expr_stmt|;
name|quint16
name|weight
argument_list|()
specifier|const
expr_stmt|;
name|QDnsServiceRecord
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDnsServiceRecord
operator|&
name|other
operator|)
decl_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QDnsServiceRecordPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDnsLookupRunnable
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QDnsServiceRecord
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QDnsTextRecord
block|{
name|public
label|:
name|QDnsTextRecord
argument_list|()
expr_stmt|;
name|QDnsTextRecord
argument_list|(
specifier|const
name|QDnsTextRecord
operator|&
name|other
argument_list|)
expr_stmt|;
operator|~
name|QDnsTextRecord
argument_list|()
expr_stmt|;
name|void
name|swap
parameter_list|(
name|QDnsTextRecord
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|quint32
name|timeToLive
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QByteArray
operator|>
name|values
argument_list|()
specifier|const
expr_stmt|;
name|QDnsTextRecord
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QDnsTextRecord
operator|&
name|other
operator|)
decl_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QDnsTextRecordPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QDnsLookupRunnable
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
DECL|function|Q_DECLARE_SHARED
name|Q_DECLARE_SHARED
argument_list|(
argument|QDnsTextRecord
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QDnsLookup
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_PROPERTY
argument_list|(
argument|Error error READ error NOTIFY finished
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString errorString READ errorString NOTIFY finished
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QString name READ name WRITE setName NOTIFY nameChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|Type type READ type WRITE setType NOTIFY typeChanged
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|QHostAddress nameserver READ nameserver WRITE setNameserver NOTIFY nameserverChanged
argument_list|)
name|public
operator|:
expr|enum
name|Error
block|{
name|NoError
operator|=
literal|0
block|,
name|ResolverError
block|,
name|OperationCancelledError
block|,
name|InvalidRequestError
block|,
name|InvalidReplyError
block|,
name|ServerFailureError
block|,
name|ServerRefusedError
block|,
name|NotFoundError
block|}
block|;
name|Q_ENUM
argument_list|(
name|Error
argument_list|)
expr|enum
name|Type
block|{
name|A
operator|=
literal|1
block|,
name|AAAA
operator|=
literal|28
block|,
name|ANY
operator|=
literal|255
block|,
name|CNAME
operator|=
literal|5
block|,
name|MX
operator|=
literal|15
block|,
name|NS
operator|=
literal|2
block|,
name|PTR
operator|=
literal|12
block|,
name|SRV
operator|=
literal|33
block|,
name|TXT
operator|=
literal|16
block|}
block|;
name|Q_ENUM
argument_list|(
argument|Type
argument_list|)
name|explicit
name|QDnsLookup
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|QDnsLookup
argument_list|(
argument|Type type
argument_list|,
argument|const QString&name
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
name|QDnsLookup
argument_list|(
argument|Type type
argument_list|,
argument|const QString&name
argument_list|,
argument|const QHostAddress&nameserver
argument_list|,
argument|QObject *parent =
literal|0
argument_list|)
block|;
operator|~
name|QDnsLookup
argument_list|()
block|;
name|Error
name|error
argument_list|()
specifier|const
block|;
name|QString
name|errorString
argument_list|()
specifier|const
block|;
name|bool
name|isFinished
argument_list|()
specifier|const
block|;
name|QString
name|name
argument_list|()
specifier|const
block|;
name|void
name|setName
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|Type
name|type
argument_list|()
specifier|const
block|;
name|void
name|setType
argument_list|(
name|QDnsLookup
operator|::
name|Type
argument_list|)
block|;
name|QHostAddress
name|nameserver
argument_list|()
specifier|const
block|;
name|void
name|setNameserver
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|nameserver
argument_list|)
block|;
name|QList
operator|<
name|QDnsDomainNameRecord
operator|>
name|canonicalNameRecords
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDnsHostAddressRecord
operator|>
name|hostAddressRecords
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDnsMailExchangeRecord
operator|>
name|mailExchangeRecords
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDnsDomainNameRecord
operator|>
name|nameServerRecords
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDnsDomainNameRecord
operator|>
name|pointerRecords
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDnsServiceRecord
operator|>
name|serviceRecords
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QDnsTextRecord
operator|>
name|textRecords
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|abort
argument_list|()
block|;
name|void
name|lookup
argument_list|()
block|;
name|Q_SIGNALS
operator|:
name|void
name|finished
argument_list|()
block|;
name|void
name|nameChanged
argument_list|(
specifier|const
name|QString
operator|&
name|name
argument_list|)
block|;
name|void
name|typeChanged
argument_list|(
argument|Type type
argument_list|)
block|;
name|void
name|nameserverChanged
argument_list|(
specifier|const
name|QHostAddress
operator|&
name|nameserver
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QDnsLookup
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_lookupFinished(const QDnsLookupReply&reply)
argument_list|)
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
comment|// QDNSLOOKUP_H
end_comment
end_unit
