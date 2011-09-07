begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QPLATFORMINPUTCONTEXT_H
define|#
directive|define
name|QPLATFORMINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qinputpanel.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QWindow
decl_stmt|;
DECL|variable|QMouseEvent
name|class
name|QMouseEvent
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QPlatformInputContext
decl_stmt|{ public:     QPlatformInputContext(
end_function
begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|virtual
operator|~
name|QPlatformInputContext
argument_list|()
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|virtual
name|void
name|commit
parameter_list|()
function_decl|;
end_function_decl
begin_decl_stmt
name|virtual
name|void
name|update
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|invokeAction
argument_list|(
name|QInputPanel
operator|::
name|Action
argument_list|,
name|int
name|cursorPosition
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|virtual
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|void
name|emitKeyboardRectChanged
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|virtual
name|bool
name|isAnimating
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|void
name|emitAnimatingChanged
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
unit|};
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMINPUTCONTEXT_H
end_comment
end_unit
