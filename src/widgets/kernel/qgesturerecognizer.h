begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGESTURERECOGNIZER_H
end_ifndef
begin_define
DECL|macro|QGESTURERECOGNIZER_H
define|#
directive|define
name|QGESTURERECOGNIZER_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QObject
decl_stmt|;
DECL|variable|QEvent
name|class
name|QEvent
decl_stmt|;
DECL|variable|QGesture
name|class
name|QGesture
decl_stmt|;
name|class
name|Q_WIDGETS_EXPORT
name|QGestureRecognizer
decl_stmt|{ public:     enum ResultFlag
block|{
name|Ignore
operator|=
literal|0x0001
operator|,
name|MayBeGesture
operator|=
literal|0x0002
operator|,
name|TriggerGesture
operator|=
literal|0x0004
operator|,
name|FinishGesture
operator|=
literal|0x0008
operator|,
name|CancelGesture
operator|=
literal|0x0010
operator|,
name|ResultState_Mask
operator|=
literal|0x00ff
operator|,
name|ConsumeEventHint
operator|=
literal|0x0100
operator|,
comment|// StoreEventHint          = 0x0200,
comment|// ReplayStoredEventsHint  = 0x0400,
comment|// DiscardStoredEventsHint = 0x0800,
name|ResultHint_Mask
operator|=
literal|0xff00
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_FLAGS
argument_list|(
argument|Result
argument_list|,
argument|ResultFlag
argument_list|)
end_macro
begin_expr_stmt
name|QGestureRecognizer
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|virtual
operator|~
name|QGestureRecognizer
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|QGesture
modifier|*
name|create
parameter_list|(
name|QObject
modifier|*
name|target
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|Result
name|recognize
parameter_list|(
name|QGesture
modifier|*
name|state
parameter_list|,
name|QObject
modifier|*
name|watched
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|reset
parameter_list|(
name|QGesture
modifier|*
name|state
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
specifier|static
name|Qt
operator|::
name|GestureType
name|registerRecognizer
argument_list|(
name|QGestureRecognizer
operator|*
name|recognizer
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
specifier|static
name|void
name|unregisterRecognizer
argument_list|(
name|Qt
operator|::
name|GestureType
name|type
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
unit|};
name|Q_DECLARE_OPERATORS_FOR_FLAGS
argument_list|(
argument|QGestureRecognizer::Result
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_GESTURES
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QGESTURERECOGNIZER_H
end_comment
end_unit
