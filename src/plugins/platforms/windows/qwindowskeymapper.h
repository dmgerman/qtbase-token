begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*     \internal     A Windows KeyboardLayoutItem has 8 possible states:         1. Unmodified         2. Shift         3. Control         4. Control + Shift         5. Alt         6. Alt + Shift         7. Alt + Control         8. Alt + Control + Shift */
end_comment
begin_struct
DECL|struct|KeyboardLayoutItem
struct|struct
name|KeyboardLayoutItem
block|{
DECL|member|dirty
name|uint
name|dirty
range|:
literal|1
decl_stmt|;
DECL|member|exists
name|uint
name|exists
range|:
literal|1
decl_stmt|;
comment|// whether this item has been initialized (by updatePossibleKeyCodes)
DECL|member|deadkeys
name|quint8
name|deadkeys
decl_stmt|;
DECL|member|NumQtKeys
specifier|static
specifier|const
name|size_t
name|NumQtKeys
init|=
literal|9
decl_stmt|;
DECL|member|qtKey
name|quint32
name|qtKey
index|[
name|NumQtKeys
index|]
decl_stmt|;
comment|// Can by any Qt::Key_<foo>, or unicode character
block|}
struct|;
end_struct
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
specifier|static
name|Qt
operator|::
name|KeyboardModifiers
name|queryKeyboardModifiers
argument_list|()
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *e
argument_list|)
specifier|const
expr_stmt|;
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
name|bool
name|translateMultimediaKeyEventInternal
parameter_list|(
name|QWindow
modifier|*
name|receiver
parameter_list|,
specifier|const
name|MSG
modifier|&
name|msg
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
name|void
name|deleteLayouts
parameter_list|()
function_decl|;
name|QWindow
modifier|*
name|m_keyGrabber
decl_stmt|;
specifier|static
specifier|const
name|size_t
name|NumKeyboardLayoutItems
init|=
literal|256
decl_stmt|;
name|KeyboardLayoutItem
name|keyLayout
index|[
name|NumKeyboardLayoutItems
index|]
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
