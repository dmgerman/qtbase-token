begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qplatforminputcontext_qpa.h>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QPlatformInputContext
name|QPlatformInputContext
operator|::
name|QPlatformInputContext
parameter_list|()
block|{ }
end_function
begin_destructor
DECL|function|~QPlatformInputContext
name|QPlatformInputContext
operator|::
name|~
name|QPlatformInputContext
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
name|bool
name|QPlatformInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QPlatformInputContext
operator|::
name|reset
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|commit
name|void
name|QPlatformInputContext
operator|::
name|commit
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|update
name|void
name|QPlatformInputContext
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
parameter_list|)
block|{ }
end_function
begin_function
DECL|function|invokeAction
name|void
name|QPlatformInputContext
operator|::
name|invokeAction
parameter_list|(
name|QInputPanel
operator|::
name|Action
name|action
parameter_list|,
name|int
name|cursorPosition
parameter_list|)
block|{
comment|// Default behavior for simple ephemeral input contexts. Some
comment|// complex input contexts should not be reset here.
if|if
condition|(
name|action
operator|==
name|QInputPanel
operator|::
name|Click
condition|)
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardRect
name|QRectF
name|QPlatformInputContext
operator|::
name|keyboardRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|emitKeyboardRectChanged
name|void
name|QPlatformInputContext
operator|::
name|emitKeyboardRectChanged
parameter_list|()
specifier|const
block|{
emit|emit
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|keyboardRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_function
DECL|function|isAnimating
name|bool
name|QPlatformInputContext
operator|::
name|isAnimating
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|emitAnimatingChanged
name|void
name|QPlatformInputContext
operator|::
name|emitAnimatingChanged
parameter_list|()
block|{
emit|emit
name|qApp
operator|->
name|inputPanel
argument_list|()
operator|->
name|animatingChanged
argument_list|()
emit|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
