begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBASICKEYEVENTTRANSITION_P_H
end_ifndef
begin_define
DECL|macro|QBASICKEYEVENTTRANSITION_P_H
define|#
directive|define
name|QBASICKEYEVENTTRANSITION_P_H
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
file|<QtCore/qabstracttransition.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_STATEMACHINE
end_ifndef
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QBasicKeyEventTransitionPrivate
name|class
name|QBasicKeyEventTransitionPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QBasicKeyEventTransition
range|:
name|public
name|QAbstractTransition
block|{
name|Q_OBJECT
name|public
operator|:
name|QBasicKeyEventTransition
argument_list|(
name|QState
operator|*
name|sourceState
operator|=
literal|0
argument_list|)
block|;
name|QBasicKeyEventTransition
argument_list|(
argument|QEvent::Type type
argument_list|,
argument|int key
argument_list|,
argument|QState *sourceState =
literal|0
argument_list|)
block|;
name|QBasicKeyEventTransition
argument_list|(
argument|QEvent::Type type
argument_list|,
argument|int key
argument_list|,
argument|Qt::KeyboardModifiers modifierMask
argument_list|,
argument|QState *sourceState =
literal|0
argument_list|)
block|;
operator|~
name|QBasicKeyEventTransition
argument_list|()
block|;
name|QEvent
operator|::
name|Type
name|eventType
argument_list|()
specifier|const
block|;
name|void
name|setEventType
argument_list|(
argument|QEvent::Type type
argument_list|)
block|;
name|int
name|key
argument_list|()
specifier|const
block|;
name|void
name|setKey
argument_list|(
argument|int key
argument_list|)
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|modifierMask
argument_list|()
specifier|const
block|;
name|void
name|setModifierMask
argument_list|(
argument|Qt::KeyboardModifiers modifiers
argument_list|)
block|;
name|protected
operator|:
name|bool
name|eventTest
argument_list|(
argument|QEvent *event
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|void
name|onTransition
argument_list|(
argument|QEvent *
argument_list|)
name|Q_DECL_OVERRIDE
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QBasicKeyEventTransition
argument_list|)
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QBasicKeyEventTransition
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
comment|//QT_NO_STATEMACHINE
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
