begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSOCKETNOTIFIER_H
end_ifndef
begin_define
DECL|macro|QSOCKETNOTIFIER_H
define|#
directive|define
name|QSOCKETNOTIFIER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QSocketNotifierPrivate
name|class
name|QSocketNotifierPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QSocketNotifier
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QSocketNotifier
argument_list|)
name|public
operator|:
expr|enum
name|Type
block|{
name|Read
block|,
name|Write
block|,
name|Exception
block|}
block|;
name|QSocketNotifier
argument_list|(
argument|qintptr socket
argument_list|,
argument|Type
argument_list|,
argument|QObject *parent = Q_NULLPTR
argument_list|)
block|;
operator|~
name|QSocketNotifier
argument_list|()
block|;
name|qintptr
name|socket
argument_list|()
specifier|const
block|;
name|Type
name|type
argument_list|()
specifier|const
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|;
name|public
name|Q_SLOTS
operator|:
name|void
name|setEnabled
argument_list|(
name|bool
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|activated
argument_list|(
argument|int socket
argument_list|,
argument|QPrivateSignal
argument_list|)
block|;
name|protected
operator|:
name|bool
name|event
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QSocketNotifier
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
comment|// QSOCKETNOTIFIER_H
end_comment
end_unit
