begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QHTTPNETWORKHEADER_H
end_ifndef
begin_define
DECL|macro|QHTTPNETWORKHEADER_H
define|#
directive|define
name|QHTTPNETWORKHEADER_H
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
comment|// of the Network Access API.  This header file may change from
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
name|QT_NO_HTTP
end_ifndef
begin_include
include|#
directive|include
file|<qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<qurl.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_AUTOTEST_EXPORT
name|QHttpNetworkHeader
block|{
name|public
label|:
name|virtual
operator|~
name|QHttpNetworkHeader
argument_list|()
block|{}
expr_stmt|;
name|virtual
name|QUrl
name|url
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setUrl
parameter_list|(
specifier|const
name|QUrl
modifier|&
name|url
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|int
name|majorVersion
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|int
name|minorVersion
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|qint64
name|contentLength
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|void
name|setContentLength
parameter_list|(
name|qint64
name|length
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
operator|,
name|QByteArray
operator|>
expr|>
name|header
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QByteArray
name|headerField
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|,
specifier|const
name|QByteArray
operator|&
name|defaultValue
operator|=
name|QByteArray
argument_list|()
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
name|virtual
name|void
name|setHeaderField
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|name
parameter_list|,
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|)
init|=
literal|0
function_decl|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QHttpNetworkHeaderPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QUrl
name|url
block|;
name|QList
operator|<
name|QPair
operator|<
name|QByteArray
block|,
name|QByteArray
operator|>
expr|>
name|fields
block|;
name|QHttpNetworkHeaderPrivate
argument_list|(
specifier|const
name|QUrl
operator|&
name|newUrl
operator|=
name|QUrl
argument_list|()
argument_list|)
block|;
name|QHttpNetworkHeaderPrivate
argument_list|(
specifier|const
name|QHttpNetworkHeaderPrivate
operator|&
name|other
argument_list|)
block|;
name|qint64
name|contentLength
argument_list|()
specifier|const
block|;
name|void
name|setContentLength
argument_list|(
argument|qint64 length
argument_list|)
block|;
name|QByteArray
name|headerField
argument_list|(
argument|const QByteArray&name
argument_list|,
argument|const QByteArray&defaultValue = QByteArray()
argument_list|)
specifier|const
block|;
name|QList
operator|<
name|QByteArray
operator|>
name|headerFieldValues
argument_list|(
argument|const QByteArray&name
argument_list|)
specifier|const
block|;
name|void
name|setHeaderField
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|,
specifier|const
name|QByteArray
operator|&
name|data
argument_list|)
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QHttpNetworkHeaderPrivate
operator|&
name|other
operator|)
specifier|const
block|;  }
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
comment|// QT_NO_HTTP
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QHTTPNETWORKHEADER_H
end_comment
end_unit
