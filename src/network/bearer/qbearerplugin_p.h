begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtNetwork module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBEARERPLUGIN_P_H
end_ifndef
begin_define
DECL|macro|QBEARERPLUGIN_P_H
define|#
directive|define
name|QBEARERPLUGIN_P_H
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
file|"qbearerengine_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qplugin.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfactoryinterface.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_BEARERMANAGEMENT
end_ifndef
begin_expr_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
expr|struct
DECL|struct|QFactoryInterface
name|Q_NETWORK_EXPORT
name|QBearerEngineFactoryInterface
operator|:
name|public
name|QFactoryInterface
block|{
name|virtual
name|QBearerEngine
operator|*
name|create
argument_list|(
argument|const QString&key
argument_list|)
specifier|const
operator|=
literal|0
block|; }
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|QBearerEngineFactoryInterface_iid
define|#
directive|define
name|QBearerEngineFactoryInterface_iid
value|"org.qt-project.Qt.QBearerEngineFactoryInterface"
end_define
begin_macro
DECL|function|Q_DECLARE_INTERFACE
name|Q_DECLARE_INTERFACE
argument_list|(
argument|QBearerEngineFactoryInterface
argument_list|,
argument|QBearerEngineFactoryInterface_iid
argument_list|)
end_macro
begin_decl_stmt
name|class
name|Q_NETWORK_EXPORT
name|QBearerEnginePlugin
range|:
name|public
name|QObject
decl_stmt|,
name|public
name|QBearerEngineFactoryInterface
block|{
name|Q_OBJECT
name|Q_INTERFACES
argument_list|(
name|QBearerEngineFactoryInterface
operator|:
name|QFactoryInterface
argument_list|)
name|public
range|:
name|explicit
name|QBearerEnginePlugin
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
decl_stmt|;
name|virtual
operator|~
name|QBearerEnginePlugin
argument_list|()
expr_stmt|;
name|virtual
name|QStringList
name|keys
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|QBearerEngine
modifier|*
name|create
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
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
comment|// QBEARERPLUGIN_P_H
end_comment
end_unit
