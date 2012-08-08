begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qplatformdrag.h"
end_include
begin_include
include|#
directive|include
file|<QtGui/private/qdnd_p.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/QKeyEvent>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtCore/QEventLoop>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_DRAGANDDROP
ifdef|#
directive|ifdef
name|QDND_DEBUG
DECL|function|dragActionsToString
name|QString
name|dragActionsToString
parameter_list|(
name|Qt
operator|::
name|DropActions
name|actions
parameter_list|)
block|{
name|QString
name|str
decl_stmt|;
if|if
condition|(
name|actions
operator|==
name|Qt
operator|::
name|IgnoreAction
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"IgnoreAction"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|actions
operator|&
name|Qt
operator|::
name|LinkAction
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"LinkAction"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|actions
operator|&
name|Qt
operator|::
name|CopyAction
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"CopyAction"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|actions
operator|&
name|Qt
operator|::
name|MoveAction
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"MoveAction"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|actions
operator|&
name|Qt
operator|::
name|TargetMoveAction
operator|)
operator|==
name|Qt
operator|::
name|TargetMoveAction
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"TargetMoveAction"
argument_list|)
expr_stmt|;
block|}
return|return
name|str
return|;
block|}
end_function
begin_function
DECL|function|KeyboardModifiersToString
name|QString
name|KeyboardModifiersToString
parameter_list|(
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
block|{
name|QString
name|str
decl_stmt|;
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"ControlModifier"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"AltModifier"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
block|{
if|if
condition|(
operator|!
name|str
operator|.
name|isEmpty
argument_list|()
condition|)
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|" | "
argument_list|)
expr_stmt|;
name|str
operator|+=
name|QLatin1String
argument_list|(
literal|"ShiftModifier"
argument_list|)
expr_stmt|;
block|}
return|return
name|str
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_constructor
DECL|function|QPlatformDropQtResponse
name|QPlatformDropQtResponse
operator|::
name|QPlatformDropQtResponse
parameter_list|(
name|bool
name|accepted
parameter_list|,
name|Qt
operator|::
name|DropAction
name|acceptedAction
parameter_list|)
member_init_list|:
name|m_accepted
argument_list|(
name|accepted
argument_list|)
member_init_list|,
name|m_accepted_action
argument_list|(
name|acceptedAction
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|isAccepted
name|bool
name|QPlatformDropQtResponse
operator|::
name|isAccepted
parameter_list|()
specifier|const
block|{
return|return
name|m_accepted
return|;
block|}
end_function
begin_function
DECL|function|acceptedAction
name|Qt
operator|::
name|DropAction
name|QPlatformDropQtResponse
operator|::
name|acceptedAction
parameter_list|()
specifier|const
block|{
return|return
name|m_accepted_action
return|;
block|}
end_function
begin_constructor
DECL|function|QPlatformDragQtResponse
name|QPlatformDragQtResponse
operator|::
name|QPlatformDragQtResponse
parameter_list|(
name|bool
name|accepted
parameter_list|,
name|Qt
operator|::
name|DropAction
name|acceptedAction
parameter_list|,
name|QRect
name|answerRect
parameter_list|)
member_init_list|:
name|QPlatformDropQtResponse
argument_list|(
name|accepted
argument_list|,
name|acceptedAction
argument_list|)
member_init_list|,
name|m_answer_rect
argument_list|(
name|answerRect
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|answerRect
name|QRect
name|QPlatformDragQtResponse
operator|::
name|answerRect
parameter_list|()
specifier|const
block|{
return|return
name|m_answer_rect
return|;
block|}
end_function
begin_class
DECL|class|QPlatformDragPrivate
class|class
name|QPlatformDragPrivate
block|{
public|public:
DECL|function|QPlatformDragPrivate
name|QPlatformDragPrivate
parameter_list|()
member_init_list|:
name|cursor_drop_action
argument_list|(
name|Qt
operator|::
name|IgnoreAction
argument_list|)
block|{}
DECL|member|cursor_drop_action
name|Qt
operator|::
name|DropAction
name|cursor_drop_action
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QPlatformDrag     \since 5.0     \internal     \preliminary     \ingroup qpa      \brief The QPlatformDrag class provides an abstraction for drag.  */
end_comment
begin_constructor
DECL|function|QPlatformDrag
name|QPlatformDrag
operator|::
name|QPlatformDrag
parameter_list|()
member_init_list|:
name|d_ptr
argument_list|(
operator|new
name|QPlatformDragPrivate
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QPlatformDrag
name|QPlatformDrag
operator|::
name|~
name|QPlatformDrag
parameter_list|()
block|{
operator|delete
name|d_ptr
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|currentDrag
name|QDrag
modifier|*
name|QPlatformDrag
operator|::
name|currentDrag
parameter_list|()
specifier|const
block|{
return|return
name|QDragManager
operator|::
name|self
argument_list|()
operator|->
name|object
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|defaultAction
name|Qt
operator|::
name|DropAction
name|QPlatformDrag
operator|::
name|defaultAction
parameter_list|(
name|Qt
operator|::
name|DropActions
name|possibleActions
parameter_list|,
name|Qt
operator|::
name|KeyboardModifiers
name|modifiers
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QDND_DEBUG
name|qDebug
argument_list|(
literal|"QDragManager::defaultAction(Qt::DropActions possibleActions)"
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"keyboard modifiers : %s"
argument_list|,
name|qPrintable
argument_list|(
name|KeyboardModifiersToString
argument_list|(
name|modifiers
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|Qt
operator|::
name|DropAction
name|default_action
init|=
name|Qt
operator|::
name|IgnoreAction
decl_stmt|;
if|if
condition|(
name|currentDrag
argument_list|()
condition|)
block|{
name|default_action
operator|=
name|currentDrag
argument_list|()
operator|->
name|defaultAction
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|default_action
operator|==
name|Qt
operator|::
name|IgnoreAction
condition|)
block|{
comment|//This means that the drag was initiated by QDrag::start and we need to
comment|//preserve the old behavior
name|default_action
operator|=
name|Qt
operator|::
name|CopyAction
expr_stmt|;
block|}
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|ControlModifier
operator|&&
name|modifiers
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|LinkAction
expr_stmt|;
elseif|else
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|ControlModifier
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|CopyAction
expr_stmt|;
elseif|else
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|ShiftModifier
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|MoveAction
expr_stmt|;
elseif|else
if|if
condition|(
name|modifiers
operator|&
name|Qt
operator|::
name|AltModifier
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|LinkAction
expr_stmt|;
ifdef|#
directive|ifdef
name|QDND_DEBUG
name|qDebug
argument_list|(
literal|"possible actions : %s"
argument_list|,
name|qPrintable
argument_list|(
name|dragActionsToString
argument_list|(
name|possibleActions
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Check if the action determined is allowed
if|if
condition|(
operator|!
operator|(
name|possibleActions
operator|&
name|default_action
operator|)
condition|)
block|{
if|if
condition|(
name|possibleActions
operator|&
name|Qt
operator|::
name|CopyAction
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|CopyAction
expr_stmt|;
elseif|else
if|if
condition|(
name|possibleActions
operator|&
name|Qt
operator|::
name|MoveAction
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|MoveAction
expr_stmt|;
elseif|else
if|if
condition|(
name|possibleActions
operator|&
name|Qt
operator|::
name|LinkAction
condition|)
name|default_action
operator|=
name|Qt
operator|::
name|LinkAction
expr_stmt|;
else|else
name|default_action
operator|=
name|Qt
operator|::
name|IgnoreAction
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QDND_DEBUG
name|qDebug
argument_list|(
literal|"default action : %s"
argument_list|,
name|qPrintable
argument_list|(
name|dragActionsToString
argument_list|(
name|default_action
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|default_action
return|;
block|}
end_function
begin_comment
comment|/*!     \brief Called to notify QDrag about changes of the current action.  */
end_comment
begin_function
DECL|function|updateAction
name|void
name|QPlatformDrag
operator|::
name|updateAction
parameter_list|(
name|Qt
operator|::
name|DropAction
name|action
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QPlatformDrag
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|cursor_drop_action
operator|!=
name|action
condition|)
block|{
name|d
operator|->
name|cursor_drop_action
operator|=
name|action
expr_stmt|;
emit|emit
name|currentDrag
argument_list|()
operator|->
name|actionChanged
argument_list|(
name|action
argument_list|)
emit|;
block|}
block|}
end_function
begin_decl_stmt
DECL|variable|default_pm
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|default_pm
index|[]
init|=
block|{
literal|"13 9 3 1"
block|,
literal|".      c None"
block|,
literal|"       c #000000"
block|,
literal|"X      c #FFFFFF"
block|,
literal|"X X X X X X X"
block|,
literal|" X X X X X X "
block|,
literal|"X ......... X"
block|,
literal|" X.........X "
block|,
literal|"X ......... X"
block|,
literal|" X.........X "
block|,
literal|"X ......... X"
block|,
literal|" X X X X X X "
block|,
literal|"X X X X X X X"
block|, }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_GLOBAL_STATIC_WITH_ARGS
argument_list|(
argument|QPixmap
argument_list|,
argument|qt_drag_default_pixmap
argument_list|,
argument|(default_pm)
argument_list|)
end_macro
begin_function
DECL|function|defaultPixmap
name|QPixmap
name|QPlatformDrag
operator|::
name|defaultPixmap
parameter_list|()
block|{
return|return
operator|*
name|qt_drag_default_pixmap
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_DRAGANDDROP
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
