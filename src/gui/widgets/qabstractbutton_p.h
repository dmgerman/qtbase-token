begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QABSTRACTBUTTON_P_H
end_ifndef
begin_define
DECL|macro|QABSTRACTBUTTON_P_H
define|#
directive|define
name|QABSTRACTBUTTON_P_H
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
file|"QtCore/qbasictimer.h"
end_include
begin_include
include|#
directive|include
file|"private/qwidget_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QAbstractButtonPrivate
range|:
name|public
name|QWidgetPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAbstractButton
argument_list|)
name|public
operator|:
name|QAbstractButtonPrivate
argument_list|(
argument|QSizePolicy::ControlType type = QSizePolicy::DefaultType
argument_list|)
block|;
name|QString
name|text
block|;
name|QIcon
name|icon
block|;
name|QSize
name|iconSize
block|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|QKeySequence
name|shortcut
block|;
name|int
name|shortcutId
block|;
endif|#
directive|endif
name|uint
name|checkable
operator|:
literal|1
block|;
name|uint
name|checked
operator|:
literal|1
block|;
name|uint
name|autoRepeat
operator|:
literal|1
block|;
name|uint
name|autoExclusive
operator|:
literal|1
block|;
name|uint
name|down
operator|:
literal|1
block|;
name|uint
name|blockRefresh
operator|:
literal|1
block|;
name|uint
name|pressed
operator|:
literal|1
block|;
ifndef|#
directive|ifndef
name|QT_NO_BUTTONGROUP
name|QButtonGroup
operator|*
name|group
block|;
endif|#
directive|endif
name|QBasicTimer
name|repeatTimer
block|;
name|QBasicTimer
name|animateTimer
block|;
name|int
name|autoRepeatDelay
block|,
name|autoRepeatInterval
block|;
name|QSizePolicy
operator|::
name|ControlType
name|controlType
block|;
name|mutable
name|QSize
name|sizeHint
block|;
name|void
name|init
argument_list|()
block|;
name|void
name|click
argument_list|()
block|;
name|void
name|refresh
argument_list|()
block|;
name|QList
operator|<
name|QAbstractButton
operator|*
operator|>
name|queryButtonList
argument_list|()
specifier|const
block|;
name|QAbstractButton
operator|*
name|queryCheckedButton
argument_list|()
specifier|const
block|;
name|void
name|notifyChecked
argument_list|()
block|;
name|void
name|moveFocus
argument_list|(
argument|int key
argument_list|)
block|;
name|void
name|fixFocusPolicy
argument_list|()
block|;
name|void
name|emitPressed
argument_list|()
block|;
name|void
name|emitReleased
argument_list|()
block|;
name|void
name|emitClicked
argument_list|()
block|; }
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
comment|// QABSTRACTBUTTON_P_H
end_comment
end_unit
