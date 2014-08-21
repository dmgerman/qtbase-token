begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFINALSTATE_H
end_ifndef
begin_define
DECL|macro|QFINALSTATE_H
define|#
directive|define
name|QFINALSTATE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qabstractstate.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
DECL|variable|QFinalStatePrivate
name|class
name|QFinalStatePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QFinalState
range|:
name|public
name|QAbstractState
block|{
name|Q_OBJECT
name|public
operator|:
name|QFinalState
argument_list|(
name|QState
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QFinalState
argument_list|()
block|;
name|protected
operator|:
name|void
name|onEntry
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|void
name|onExit
argument_list|(
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|event
argument_list|(
name|QEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QFinalState
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QFinalState
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_STATEMACHINE
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
