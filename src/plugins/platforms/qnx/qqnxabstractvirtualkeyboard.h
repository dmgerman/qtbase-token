begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2013 BlackBerry Limited. All rights reserved. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXABSTRACTVIRTUALKEYBOARD_H
end_ifndef
begin_define
DECL|macro|QQNXABSTRACTVIRTUALKEYBOARD_H
define|#
directive|define
name|QQNXABSTRACTVIRTUALKEYBOARD_H
end_define
begin_include
include|#
directive|include
file|<QLocale>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQnxAbstractVirtualKeyboard
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
comment|// NOTE:  Not all the following keyboard modes are currently used.
comment|// Default - Regular Keyboard
comment|// Url/Email - Enhanced keys for each types.
comment|// Web - Regular keyboard with two blank keys, currently unused.
comment|// NumPunc - Numbers& Punctionation, alternate to Symbol
comment|// Symbol - All symbols, alternate to NumPunc, currently unused.
comment|// Phone - Phone enhanced keyboard - currently unused as no alternate keyboard available to access a-zA-Z
comment|// Pin - Keyboard for entering Pins (Hex values) currently unused.
comment|// Password - Keyboard for entering passwords.
comment|//
comment|// SPECIAL NOTE: Usage of NumPunc may have to be removed, ABC button is non-functional.
comment|//
expr|enum
name|KeyboardMode
block|{
name|Default
block|,
name|Url
block|,
name|Email
block|,
name|Web
block|,
name|NumPunc
block|,
name|Symbol
block|,
name|Phone
block|,
name|Pin
block|,
name|Password
block|}
block|;
name|explicit
name|QQnxAbstractVirtualKeyboard
argument_list|(
name|QObject
operator|*
name|parent
operator|=
literal|0
argument_list|)
block|;
name|virtual
name|bool
name|showKeyboard
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|bool
name|hideKeyboard
argument_list|()
operator|=
literal|0
block|;
name|int
name|height
argument_list|()
block|{
return|return
name|m_visible
operator|?
name|m_height
operator|:
literal|0
return|;
block|}
name|bool
name|isVisible
argument_list|()
specifier|const
block|{
return|return
name|m_visible
return|;
block|}
name|QLocale
name|locale
argument_list|()
specifier|const
block|{
return|return
name|m_locale
return|;
block|}
name|void
name|setKeyboardMode
argument_list|(
argument|KeyboardMode mode
argument_list|)
block|;
name|void
name|setInputHints
argument_list|(
argument|int inputHints
argument_list|)
block|;
name|KeyboardMode
name|keyboardMode
argument_list|()
specifier|const
block|{
return|return
name|m_keyboardMode
return|;
block|}
name|Q_SIGNALS
operator|:
name|void
name|heightChanged
argument_list|(
argument|int height
argument_list|)
block|;
name|void
name|visibilityChanged
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|localeChanged
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|void
name|applyKeyboardMode
argument_list|(
argument|KeyboardMode mode
argument_list|)
operator|=
literal|0
block|;
name|void
name|setHeight
argument_list|(
argument|int height
argument_list|)
block|;
name|void
name|setVisible
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|setLocale
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
block|;
name|private
operator|:
name|int
name|m_height
block|;
name|bool
name|m_visible
block|;
name|QLocale
name|m_locale
block|;
name|KeyboardMode
name|m_keyboardMode
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
comment|// QQNXABSTRACTVIRTUALKEYBOARD_H
end_comment
end_unit
