begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSHAREDNETWORKSESSIONPRIVATE_H
end_ifndef
begin_define
DECL|macro|QSHAREDNETWORKSESSIONPRIVATE_H
define|#
directive|define
name|QSHAREDNETWORKSESSIONPRIVATE_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
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
file|"qnetworksession.h"
end_include
begin_include
include|#
directive|include
file|"qnetworkconfiguration.h"
end_include
begin_include
include|#
directive|include
file|<QHash>
end_include
begin_include
include|#
directive|include
file|<QSharedPointer>
end_include
begin_include
include|#
directive|include
file|<QWeakPointer>
end_include
begin_include
include|#
directive|include
file|<QMutex>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_function_decl
name|QT_BEGIN_NAMESPACE
name|uint
name|qHash
parameter_list|(
specifier|const
name|QNetworkConfiguration
modifier|&
name|config
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|QSharedNetworkSessionManager
block|{
name|public
label|:
specifier|static
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|getSession
argument_list|(
argument|QNetworkConfiguration config
argument_list|)
expr_stmt|;
specifier|static
name|void
name|setSession
argument_list|(
name|QNetworkConfiguration
name|config
argument_list|,
name|QSharedPointer
operator|<
name|QNetworkSession
operator|>
name|session
argument_list|)
decl_stmt|;
name|private
label|:
name|QHash
operator|<
name|QNetworkConfiguration
operator|,
name|QWeakPointer
operator|<
name|QNetworkSession
operator|>
expr|>
name|sessions
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_BEARERMANAGEMENT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QSHAREDNETWORKSESSIONPRIVATE_H
end_comment
end_unit
