begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2009 David Faure<dfaure@kdab.net> ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNETWORKPROXY_P_H
end_ifndef
begin_define
DECL|macro|QNETWORKPROXY_P_H
define|#
directive|define
name|QNETWORKPROXY_P_H
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
comment|// of the QLibrary class.  This header file may change from
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_NETWORKPROXY
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QSystemConfigurationProxyFactory
range|:
name|public
name|QNetworkProxyFactory
block|{
name|public
operator|:
name|QSystemConfigurationProxyFactory
argument_list|()
operator|:
name|QNetworkProxyFactory
argument_list|()
block|{}
name|virtual
name|QList
operator|<
name|QNetworkProxy
operator|>
name|queryProxy
argument_list|(
argument|const QNetworkProxyQuery& query
argument_list|)
block|{
name|QList
operator|<
name|QNetworkProxy
operator|>
name|proxies
operator|=
name|QNetworkProxyFactory
operator|::
name|systemProxyForQuery
argument_list|(
name|query
argument_list|)
block|;
comment|// Make sure NoProxy is in the list, so that QTcpServer can work:
comment|// it searches for the first proxy that can has the ListeningCapability capability
comment|// if none have (as is the case with HTTP proxies), it fails to bind.
comment|// NoProxy allows it to fallback to the 'no proxy' case and bind.
name|proxies
operator|.
name|append
argument_list|(
name|QNetworkProxy
operator|::
name|NoProxy
argument_list|)
block|;
return|return
name|proxies
return|;
block|}
expr|}
block|;
name|QT_END_NAMESPACE
end_decl_stmt
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
