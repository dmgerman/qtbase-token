begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKINTERFACE_H
end_ifndef
begin_define
DECL|macro|QNETWORKINTERFACE_H
define|#
directive|define
name|QNETWORKINTERFACE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qscopedpointer.h>
end_include
begin_include
include|#
directive|include
file|<QtNetwork/qhostaddress.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKINTERFACE
end_ifndef
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Network
argument_list|)
name|template
decl|<
name|typename
name|T
decl|>
name|class
name|QList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QNetworkAddressEntryPrivate
name|class
name|QNetworkAddressEntryPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkAddressEntry
block|{
name|public
label|:
name|QNetworkAddressEntry
argument_list|()
expr_stmt|;
name|QNetworkAddressEntry
argument_list|(
specifier|const
name|QNetworkAddressEntry
operator|&
name|other
argument_list|)
expr_stmt|;
name|QNetworkAddressEntry
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkAddressEntry
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QNetworkAddressEntry
argument_list|()
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QNetworkAddressEntry
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QNetworkAddressEntry
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
name|QHostAddress
name|ip
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setIp
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|newIp
parameter_list|)
function_decl|;
name|QHostAddress
name|netmask
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setNetmask
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|newNetmask
parameter_list|)
function_decl|;
name|int
name|prefixLength
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPrefixLength
parameter_list|(
name|int
name|length
parameter_list|)
function_decl|;
name|QHostAddress
name|broadcast
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBroadcast
parameter_list|(
specifier|const
name|QHostAddress
modifier|&
name|newBroadcast
parameter_list|)
function_decl|;
name|private
label|:
name|QScopedPointer
operator|<
name|QNetworkAddressEntryPrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QNetworkInterfacePrivate
name|class
name|QNetworkInterfacePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QNetworkInterface
block|{
name|public
label|:
enum|enum
name|InterfaceFlag
block|{
name|IsUp
init|=
literal|0x1
block|,
name|IsRunning
init|=
literal|0x2
block|,
name|CanBroadcast
init|=
literal|0x4
block|,
name|IsLoopBack
init|=
literal|0x8
block|,
name|IsPointToPoint
init|=
literal|0x10
block|,
name|CanMulticast
init|=
literal|0x20
block|}
enum|;
name|Q_DECLARE_FLAGS
argument_list|(
argument|InterfaceFlags
argument_list|,
argument|InterfaceFlag
argument_list|)
name|QNetworkInterface
argument_list|()
expr_stmt|;
name|QNetworkInterface
argument_list|(
specifier|const
name|QNetworkInterface
operator|&
name|other
argument_list|)
expr_stmt|;
name|QNetworkInterface
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QNetworkInterface
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QNetworkInterface
argument_list|()
expr_stmt|;
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
name|int
name|index
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|name
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|humanReadableName
argument_list|()
specifier|const
expr_stmt|;
name|InterfaceFlags
name|flags
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|hardwareAddress
argument_list|()
specifier|const
expr_stmt|;
name|QList
operator|<
name|QNetworkAddressEntry
operator|>
name|addressEntries
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|QNetworkInterface
name|interfaceFromName
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
specifier|static
name|QNetworkInterface
name|interfaceFromIndex
parameter_list|(
name|int
name|index
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QNetworkInterface
operator|>
name|allInterfaces
argument_list|()
expr_stmt|;
specifier|static
name|QList
operator|<
name|QHostAddress
operator|>
name|allAddresses
argument_list|()
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QNetworkInterfacePrivate
decl_stmt|;
name|QSharedDataPointer
operator|<
name|QNetworkInterfacePrivate
operator|>
name|d
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QNetworkInterface::InterfaceFlags
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_NETWORK_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
name|debug
operator|,
specifier|const
name|QNetworkInterface
operator|&
name|networkInterface
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_NETWORKINTERFACE
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
