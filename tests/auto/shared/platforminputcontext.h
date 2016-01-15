begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_decl_stmt
name|class
name|PlatformInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|public
operator|:
name|PlatformInputContext
argument_list|()
operator|:
name|m_animating
argument_list|(
name|false
argument_list|)
block|,
name|m_visible
argument_list|(
name|false
argument_list|)
block|,
name|m_updateCallCount
argument_list|(
literal|0
argument_list|)
block|,
name|m_resetCallCount
argument_list|(
literal|0
argument_list|)
block|,
name|m_commitCallCount
argument_list|(
literal|0
argument_list|)
block|,
name|m_localeCallCount
argument_list|(
literal|0
argument_list|)
block|,
name|m_inputDirectionCallCount
argument_list|(
literal|0
argument_list|)
block|,
name|m_lastQueries
argument_list|(
name|Qt
operator|::
name|ImhNone
argument_list|)
block|,
name|m_action
argument_list|(
name|QInputMethod
operator|::
name|Click
argument_list|)
block|,
name|m_cursorPosition
argument_list|(
literal|0
argument_list|)
block|,
name|m_lastEventType
argument_list|(
name|QEvent
operator|::
name|None
argument_list|)
block|,
name|m_setFocusObjectCallCount
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
block|{
return|return
name|m_keyboardRect
return|;
block|}
name|virtual
name|bool
name|isAnimating
argument_list|()
specifier|const
block|{
return|return
name|m_animating
return|;
block|}
name|virtual
name|void
name|reset
argument_list|()
block|{
name|m_resetCallCount
operator|++
block|; }
name|virtual
name|void
name|commit
argument_list|()
block|{
name|m_commitCallCount
operator|++
block|;
if|if
condition|(
name|m_commitString
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QInputMethodEvent
name|commitEvent
block|;
name|commitEvent
operator|.
name|setCommitString
argument_list|(
name|m_commitString
argument_list|)
block|;
if|if
condition|(
name|qGuiApp
operator|->
name|focusObject
argument_list|()
condition|)
name|qGuiApp
operator|->
name|sendEvent
argument_list|(
name|qGuiApp
operator|->
name|focusObject
argument_list|()
argument_list|,
operator|&
name|commitEvent
argument_list|)
expr_stmt|;
else|else
name|qWarning
argument_list|(
literal|"Test input context to commit without focused object"
argument_list|)
expr_stmt|;
block|}
end_decl_stmt
begin_function
name|void
name|setCommitString
parameter_list|(
specifier|const
name|QString
modifier|&
name|commitString
parameter_list|)
block|{
name|m_commitString
operator|=
name|commitString
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|virtual
name|void
name|update
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
name|queries
argument_list|)
block|{
name|m_updateCallCount
operator|++
expr_stmt|;
name|m_lastQueries
operator|=
name|queries
expr_stmt|;
block|}
end_decl_stmt
begin_decl_stmt
name|virtual
name|void
name|invokeAction
argument_list|(
name|QInputMethod
operator|::
name|Action
name|action
argument_list|,
name|int
name|cursorPosition
argument_list|)
block|{
name|m_action
operator|=
name|action
expr_stmt|;
name|m_cursorPosition
operator|=
name|cursorPosition
expr_stmt|;
block|}
end_decl_stmt
begin_function
name|virtual
name|bool
name|filterEvent
parameter_list|(
specifier|const
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|m_lastEventType
operator|=
name|event
operator|->
name|type
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
end_function
begin_function
name|virtual
name|void
name|showInputPanel
parameter_list|()
block|{
name|m_visible
operator|=
name|true
expr_stmt|;
block|}
end_function
begin_function
name|virtual
name|void
name|hideInputPanel
parameter_list|()
block|{
name|m_visible
operator|=
name|false
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|virtual
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
block|{
return|return
name|m_visible
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|QLocale
name|locale
argument_list|()
specifier|const
block|{
name|m_localeCallCount
operator|++
block|;
return|return
name|QLocale
operator|::
name|c
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|virtual
name|Qt
operator|::
name|LayoutDirection
name|inputDirection
argument_list|()
specifier|const
block|{
name|m_inputDirectionCallCount
operator|++
block|;
return|return
name|Qt
operator|::
name|LeftToRight
return|;
block|}
end_expr_stmt
begin_function
name|virtual
name|void
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|object
argument_list|)
expr_stmt|;
name|m_setFocusObjectCallCount
operator|++
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|bool
name|m_animating
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|bool
name|m_visible
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_updateCallCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_resetCallCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_commitCallCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QString
name|m_commitString
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|int
name|m_localeCallCount
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|mutable
name|int
name|m_inputDirectionCallCount
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Qt
operator|::
name|InputMethodQueries
name|m_lastQueries
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QInputMethod
operator|::
name|Action
name|m_action
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|m_cursorPosition
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_lastEventType
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRectF
name|m_keyboardRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|int
name|m_setFocusObjectCallCount
decl_stmt|;
end_decl_stmt
unit|};
end_unit
