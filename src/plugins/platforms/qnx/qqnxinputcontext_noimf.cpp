begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qqnxinputcontext_noimf.h"
end_include
begin_include
include|#
directive|include
file|"qqnxabstractvirtualkeyboard.h"
end_include
begin_include
include|#
directive|include
file|"qqnxintegration.h"
end_include
begin_include
include|#
directive|include
file|"qqnxscreen.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QDebug>
end_include
begin_include
include|#
directive|include
file|<QtGui/QGuiApplication>
end_include
begin_include
include|#
directive|include
file|<QtGui/QInputMethodEvent>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QQNXINPUTCONTEXT_DEBUG
argument_list|)
end_if
begin_define
DECL|macro|qInputContextDebug
define|#
directive|define
name|qInputContextDebug
value|qDebug
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|qInputContextDebug
define|#
directive|define
name|qInputContextDebug
value|QT_NO_QDEBUG_MACRO
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QQnxInputContext
name|QQnxInputContext
operator|::
name|QQnxInputContext
parameter_list|(
name|QQnxIntegration
modifier|*
name|integration
parameter_list|,
name|QQnxAbstractVirtualKeyboard
modifier|&
name|keyboard
parameter_list|)
member_init_list|:
name|QPlatformInputContext
argument_list|()
member_init_list|,
name|m_inputPanelVisible
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|m_inputPanelLocale
argument_list|(
name|QLocale
operator|::
name|c
argument_list|()
argument_list|)
member_init_list|,
name|m_integration
argument_list|(
name|integration
argument_list|)
member_init_list|,
name|m_virtualKeyboard
argument_list|(
name|keyboard
argument_list|)
block|{
name|connect
argument_list|(
operator|&
name|keyboard
argument_list|,
name|SIGNAL
argument_list|(
name|heightChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|keyboardHeightChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|keyboard
argument_list|,
name|SIGNAL
argument_list|(
name|visibilityChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|keyboardVisibilityChanged
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
operator|&
name|keyboard
argument_list|,
name|SIGNAL
argument_list|(
name|localeChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|keyboardLocaleChanged
argument_list|(
name|QLocale
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|keyboardVisibilityChanged
argument_list|(
name|keyboard
operator|.
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|keyboardLocaleChanged
argument_list|(
name|keyboard
operator|.
name|locale
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QQnxInputContext
name|QQnxInputContext
operator|::
name|~
name|QQnxInputContext
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
name|bool
name|QQnxInputContext
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|hasPhysicalKeyboard
name|bool
name|QQnxInputContext
operator|::
name|hasPhysicalKeyboard
parameter_list|()
block|{
comment|// TODO: This should query the system to check if a USB keyboard is connected.
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|reset
name|void
name|QQnxInputContext
operator|::
name|reset
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|filterEvent
name|bool
name|QQnxInputContext
operator|::
name|filterEvent
parameter_list|(
specifier|const
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|hasPhysicalKeyboard
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|CloseSoftwareInputPanel
condition|)
block|{
name|m_virtualKeyboard
operator|.
name|hideKeyboard
argument_list|()
expr_stmt|;
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"hiding virtual keyboard"
expr_stmt|;
return|return
literal|false
return|;
block|}
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|RequestSoftwareInputPanel
condition|)
block|{
name|m_virtualKeyboard
operator|.
name|showKeyboard
argument_list|()
expr_stmt|;
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"requesting virtual keyboard"
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|keyboardRect
name|QRectF
name|QQnxInputContext
operator|::
name|keyboardRect
parameter_list|()
specifier|const
block|{
name|QRect
name|screenGeometry
init|=
name|m_integration
operator|->
name|primaryDisplay
argument_list|()
operator|->
name|geometry
argument_list|()
decl_stmt|;
return|return
name|QRectF
argument_list|(
name|screenGeometry
operator|.
name|x
argument_list|()
argument_list|,
name|screenGeometry
operator|.
name|height
argument_list|()
operator|-
name|m_virtualKeyboard
operator|.
name|height
argument_list|()
argument_list|,
name|screenGeometry
operator|.
name|width
argument_list|()
argument_list|,
name|m_virtualKeyboard
operator|.
name|height
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|handleKeyboardEvent
name|bool
name|QQnxInputContext
operator|::
name|handleKeyboardEvent
parameter_list|(
name|int
name|flags
parameter_list|,
name|int
name|sym
parameter_list|,
name|int
name|mod
parameter_list|,
name|int
name|scan
parameter_list|,
name|int
name|cap
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|flags
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|sym
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|mod
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|scan
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|cap
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|showInputPanel
name|void
name|QQnxInputContext
operator|::
name|showInputPanel
parameter_list|()
block|{
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|m_virtualKeyboard
operator|.
name|showKeyboard
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hideInputPanel
name|void
name|QQnxInputContext
operator|::
name|hideInputPanel
parameter_list|()
block|{
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
expr_stmt|;
name|m_virtualKeyboard
operator|.
name|hideKeyboard
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|isInputPanelVisible
name|bool
name|QQnxInputContext
operator|::
name|isInputPanelVisible
parameter_list|()
specifier|const
block|{
return|return
name|m_inputPanelVisible
return|;
block|}
end_function
begin_function
DECL|function|locale
name|QLocale
name|QQnxInputContext
operator|::
name|locale
parameter_list|()
specifier|const
block|{
return|return
name|m_inputPanelLocale
return|;
block|}
end_function
begin_function
DECL|function|keyboardHeightChanged
name|void
name|QQnxInputContext
operator|::
name|keyboardHeightChanged
parameter_list|()
block|{
name|emitKeyboardRectChanged
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyboardVisibilityChanged
name|void
name|QQnxInputContext
operator|::
name|keyboardVisibilityChanged
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"visible="
operator|<<
name|visible
expr_stmt|;
if|if
condition|(
name|m_inputPanelVisible
operator|!=
name|visible
condition|)
block|{
name|m_inputPanelVisible
operator|=
name|visible
expr_stmt|;
name|emitInputPanelVisibleChanged
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|keyboardLocaleChanged
name|void
name|QQnxInputContext
operator|::
name|keyboardLocaleChanged
parameter_list|(
specifier|const
name|QLocale
modifier|&
name|locale
parameter_list|)
block|{
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"locale="
operator|<<
name|locale
expr_stmt|;
if|if
condition|(
name|m_inputPanelLocale
operator|!=
name|locale
condition|)
block|{
name|m_inputPanelLocale
operator|=
name|locale
expr_stmt|;
name|emitLocaleChanged
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setFocusObject
name|void
name|QQnxInputContext
operator|::
name|setFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|qInputContextDebug
argument_list|()
operator|<<
name|Q_FUNC_INFO
operator|<<
literal|"input item="
operator|<<
name|object
expr_stmt|;
if|if
condition|(
operator|!
name|inputMethodAccepted
argument_list|()
condition|)
block|{
if|if
condition|(
name|m_inputPanelVisible
condition|)
name|hideInputPanel
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QInputMethodQueryEvent
name|query
argument_list|(
name|Qt
operator|::
name|ImHints
operator||
name|Qt
operator|::
name|ImEnterKeyType
argument_list|)
decl_stmt|;
name|QCoreApplication
operator|::
name|sendEvent
argument_list|(
name|object
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
name|int
name|inputHints
init|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImHints
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|EnterKeyType
name|qtEnterKeyType
init|=
name|Qt
operator|::
name|EnterKeyType
argument_list|(
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImEnterKeyType
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|m_virtualKeyboard
operator|.
name|setInputHints
argument_list|(
name|inputHints
argument_list|)
expr_stmt|;
name|m_virtualKeyboard
operator|.
name|setEnterKeyType
argument_list|(
name|QQnxAbstractVirtualKeyboard
operator|::
name|qtEnterKeyTypeToQnx
argument_list|(
name|qtEnterKeyType
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|m_inputPanelVisible
condition|)
name|showInputPanel
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
