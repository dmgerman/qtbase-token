begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QWINDOWSKEYMAPPER_H
end_ifndef
begin_define
DECL|macro|QWINDOWSKEYMAPPER_H
define|#
directive|define
name|QWINDOWSKEYMAPPER_H
end_define
begin_include
include|#
directive|include
file|"qtwindows_additional.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_struct_decl
struct_decl|struct
name|KeyboardLayoutItem
struct_decl|;
end_struct_decl
begin_decl_stmt
name|class
name|QWindowsKeyMapper
block|{
name|Q_DISABLE_COPY
argument_list|(
argument|QWindowsKeyMapper
argument_list|)
name|public
label|:
name|explicit
name|QWindowsKeyMapper
parameter_list|()
function_decl|;
operator|~
name|QWindowsKeyMapper
argument_list|()
expr_stmt|;
name|void
name|changeKeyboard
parameter_list|()
function_decl|;
name|void
name|setUseRTLExtensions
parameter_list|(
name|bool
name|e
parameter_list|)
block|{
name|m_useRTLExtensions
operator|=
name|e
expr_stmt|;
block|}
name|bool
name|useRTLExtensions
argument_list|()
specifier|const
block|{
return|return
name|m_useRTLExtensions
return|;
block|}
name|bool
name|translateKeyEvent
parameter_list|(
name|QWindow
modifier|*
name|widget
parameter_list|,
name|HWND
name|hwnd
parameter_list|,
specifier|const
name|MSG
modifier|&
name|msg
parameter_list|,
name|LRESULT
modifier|*
name|result
parameter_list|)
function_decl|;
name|QWindow
operator|*
name|keyGrabber
argument_list|()
specifier|const
block|{
return|return
name|m_keyGrabber
return|;
block|}
name|void
name|setKeyGrabber
parameter_list|(
name|QWindow
modifier|*
name|w
parameter_list|)
block|{
name|m_keyGrabber
operator|=
name|w
expr_stmt|;
block|}
name|private
label|:
name|bool
name|translateKeyEventInternal
parameter_list|(
name|QWindow
modifier|*
name|receiver
parameter_list|,
specifier|const
name|MSG
modifier|&
name|msg
parameter_list|,
name|bool
name|grab
parameter_list|)
function_decl|;
name|void
name|updateKeyMap
parameter_list|(
specifier|const
name|MSG
modifier|&
name|msg
parameter_list|)
function_decl|;
name|bool
name|m_useRTLExtensions
decl_stmt|;
name|QLocale
name|keyboardInputLocale
decl_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|keyboardInputDirection
expr_stmt|;
name|void
name|clearRecordedKeys
parameter_list|()
function_decl|;
name|void
name|updatePossibleKeyCodes
parameter_list|(
name|unsigned
name|char
modifier|*
name|kbdBuffer
parameter_list|,
name|quint32
name|scancode
parameter_list|,
name|quint32
name|vk_key
parameter_list|)
function_decl|;
name|bool
name|isADeadKey
parameter_list|(
name|unsigned
name|int
name|vk_key
parameter_list|,
name|unsigned
name|int
name|modifiers
parameter_list|)
function_decl|;
name|void
name|deleteLayouts
parameter_list|()
function_decl|;
name|KeyboardLayoutItem
modifier|*
name|keyLayout
index|[
literal|256
index|]
decl_stmt|;
name|QWindow
modifier|*
name|m_keyGrabber
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_enum
DECL|enum|WindowsNativeModifiers
enum|enum
name|WindowsNativeModifiers
block|{
DECL|enumerator|ShiftLeft
name|ShiftLeft
init|=
literal|0x00000001
block|,
DECL|enumerator|ControlLeft
name|ControlLeft
init|=
literal|0x00000002
block|,
DECL|enumerator|AltLeft
name|AltLeft
init|=
literal|0x00000004
block|,
DECL|enumerator|MetaLeft
name|MetaLeft
init|=
literal|0x00000008
block|,
DECL|enumerator|ShiftRight
name|ShiftRight
init|=
literal|0x00000010
block|,
DECL|enumerator|ControlRight
name|ControlRight
init|=
literal|0x00000020
block|,
DECL|enumerator|AltRight
name|AltRight
init|=
literal|0x00000040
block|,
DECL|enumerator|MetaRight
name|MetaRight
init|=
literal|0x00000080
block|,
DECL|enumerator|CapsLock
name|CapsLock
init|=
literal|0x00000100
block|,
DECL|enumerator|NumLock
name|NumLock
init|=
literal|0x00000200
block|,
DECL|enumerator|ScrollLock
name|ScrollLock
init|=
literal|0x00000400
block|,
DECL|enumerator|ExtendedKey
name|ExtendedKey
init|=
literal|0x01000000
block|,
comment|// Convenience mappings
DECL|enumerator|ShiftAny
name|ShiftAny
init|=
literal|0x00000011
block|,
DECL|enumerator|ControlAny
name|ControlAny
init|=
literal|0x00000022
block|,
DECL|enumerator|AltAny
name|AltAny
init|=
literal|0x00000044
block|,
DECL|enumerator|MetaAny
name|MetaAny
init|=
literal|0x00000088
block|,
DECL|enumerator|LockAny
name|LockAny
init|=
literal|0x00000700
block|}
enum|;
end_enum
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QWINDOWSKEYMAPPER_H
end_comment
end_unit
