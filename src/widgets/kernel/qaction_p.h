begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACTION_P_H
end_ifndef
begin_define
DECL|macro|QACTION_P_H
define|#
directive|define
name|QACTION_P_H
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
comment|// of other Qt classes.  This header file may change from version to
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
file|"QtWidgets/qaction.h"
end_include
begin_include
include|#
directive|include
file|"QtWidgets/qmenu.h"
end_include
begin_include
include|#
directive|include
file|"private/qgraphicswidget_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qobject_p.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_ACTION
DECL|variable|QShortcutMap
name|class
name|QShortcutMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QActionPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QAction
argument_list|)
name|public
operator|:
name|QActionPrivate
argument_list|()
block|;
operator|~
name|QActionPrivate
argument_list|()
block|;
specifier|static
name|QActionPrivate
operator|*
name|get
argument_list|(
argument|QAction *q
argument_list|)
block|{
return|return
name|q
operator|->
name|d_func
argument_list|()
return|;
block|}
name|bool
name|showStatusText
argument_list|(
name|QWidget
operator|*
name|w
argument_list|,
specifier|const
name|QString
operator|&
name|str
argument_list|)
block|;
name|QPointer
operator|<
name|QActionGroup
operator|>
name|group
block|;
name|QString
name|text
block|;
name|QString
name|iconText
block|;
name|QIcon
name|icon
block|;
name|QString
name|tooltip
block|;
name|QString
name|statustip
block|;
name|QString
name|whatsthis
block|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|QKeySequence
name|shortcut
block|;
name|QList
operator|<
name|QKeySequence
operator|>
name|alternateShortcuts
block|;
endif|#
directive|endif
name|QVariant
name|userData
block|;
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|int
name|shortcutId
block|;
name|QList
operator|<
name|int
operator|>
name|alternateShortcutIds
block|;
name|Qt
operator|::
name|ShortcutContext
name|shortcutContext
block|;
name|uint
name|autorepeat
operator|:
literal|1
block|;
endif|#
directive|endif
name|QFont
name|font
block|;
name|QPointer
operator|<
name|QMenu
operator|>
name|menu
block|;
name|uint
name|enabled
operator|:
literal|1
block|,
name|forceDisabled
operator|:
literal|1
block|;
name|uint
name|visible
operator|:
literal|1
block|,
name|forceInvisible
operator|:
literal|1
block|;
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
name|separator
operator|:
literal|1
block|;
name|uint
name|fontSet
operator|:
literal|1
block|;
name|int
name|iconVisibleInMenu
operator|:
literal|3
block|;
comment|// Only has values -1, 0, and 1
name|QAction
operator|::
name|MenuRole
name|menuRole
block|;
name|QAction
operator|::
name|Priority
name|priority
block|;
name|QList
operator|<
name|QWidget
operator|*
operator|>
name|widgets
block|;
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
name|QList
operator|<
name|QGraphicsWidget
operator|*
operator|>
name|graphicsWidgets
block|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
name|void
name|redoGrab
argument_list|(
name|QShortcutMap
operator|&
name|map
argument_list|)
block|;
name|void
name|redoGrabAlternate
argument_list|(
name|QShortcutMap
operator|&
name|map
argument_list|)
block|;
name|void
name|setShortcutEnabled
argument_list|(
argument|bool enable
argument_list|,
argument|QShortcutMap&map
argument_list|)
block|;
specifier|static
name|QShortcutMap
operator|*
name|globalMap
block|;
endif|#
directive|endif
comment|// QT_NO_SHORTCUT
name|void
name|sendDataChanged
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACTION
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACTION_P_H
end_comment
end_unit
