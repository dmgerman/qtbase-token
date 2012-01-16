begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QACTIONGROUP_H
end_ifndef
begin_define
DECL|macro|QACTIONGROUP_H
define|#
directive|define
name|QACTIONGROUP_H
end_define
begin_include
include|#
directive|include
file|<QtWidgets/qaction.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
ifndef|#
directive|ifndef
name|QT_NO_ACTION
name|class
name|QActionGroupPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_WIDGETS_EXPORT
name|QActionGroup
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QActionGroup
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool exclusive READ isExclusive WRITE setExclusive
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool enabled READ isEnabled WRITE setEnabled
argument_list|)
name|Q_PROPERTY
argument_list|(
argument|bool visible READ isVisible WRITE setVisible
argument_list|)
name|public
operator|:
name|explicit
name|QActionGroup
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QActionGroup
argument_list|()
block|;
name|QAction
operator|*
name|addAction
argument_list|(
name|QAction
operator|*
name|a
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|QAction
operator|*
name|addAction
argument_list|(
specifier|const
name|QIcon
operator|&
name|icon
argument_list|,
specifier|const
name|QString
operator|&
name|text
argument_list|)
block|;
name|void
name|removeAction
argument_list|(
name|QAction
operator|*
name|a
argument_list|)
block|;
name|QList
operator|<
name|QAction
operator|*
operator|>
name|actions
argument_list|()
specifier|const
block|;
name|QAction
operator|*
name|checkedAction
argument_list|()
specifier|const
block|;
name|bool
name|isExclusive
argument_list|()
specifier|const
block|;
name|bool
name|isEnabled
argument_list|()
specifier|const
block|;
name|bool
name|isVisible
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
specifier|inline
name|void
name|setDisabled
argument_list|(
argument|bool b
argument_list|)
block|{
name|setEnabled
argument_list|(
operator|!
name|b
argument_list|)
block|; }
name|void
name|setVisible
argument_list|(
name|bool
argument_list|)
block|;
name|void
name|setExclusive
argument_list|(
name|bool
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|triggered
argument_list|(
name|QAction
operator|*
argument_list|)
block|;
name|void
name|hovered
argument_list|(
name|QAction
operator|*
argument_list|)
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QActionGroup
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionTriggered()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionChanged()
argument_list|)
name|Q_PRIVATE_SLOT
argument_list|(
argument|d_func()
argument_list|,
argument|void _q_actionHovered()
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACTION
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QACTIONGROUP_H
end_comment
end_unit
