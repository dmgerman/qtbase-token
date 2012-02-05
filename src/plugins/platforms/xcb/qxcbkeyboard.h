begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXCBKEYBOARD_H
end_ifndef
begin_define
DECL|macro|QXCBKEYBOARD_H
define|#
directive|define
name|QXCBKEYBOARD_H
end_define
begin_include
include|#
directive|include
file|"qxcbobject.h"
end_include
begin_include
include|#
directive|include
file|"xcb/xcb_keysyms.h"
end_include
begin_include
include|#
directive|include
file|<QEvent>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QWindow
name|class
name|QWindow
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QXcbKeyboard
range|:
name|public
name|QXcbObject
block|{
name|public
operator|:
name|QXcbKeyboard
argument_list|(
name|QXcbConnection
operator|*
name|connection
argument_list|)
block|;
operator|~
name|QXcbKeyboard
argument_list|()
block|;
name|void
name|handleKeyPressEvent
argument_list|(
name|QXcbWindow
operator|*
name|window
argument_list|,
specifier|const
name|xcb_key_press_event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|handleKeyReleaseEvent
argument_list|(
name|QXcbWindow
operator|*
name|window
argument_list|,
specifier|const
name|xcb_key_release_event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|handleMappingNotifyEvent
argument_list|(
specifier|const
name|xcb_mapping_notify_event_t
operator|*
name|event
argument_list|)
block|;
name|Qt
operator|::
name|KeyboardModifiers
name|translateModifiers
argument_list|(
argument|int s
argument_list|)
block|;
name|private
operator|:
name|void
name|handleKeyEvent
argument_list|(
argument|QWindow *window
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|xcb_keycode_t code
argument_list|,
argument|quint16 state
argument_list|,
argument|xcb_timestamp_t time
argument_list|)
block|;
name|int
name|translateKeySym
argument_list|(
argument|uint key
argument_list|)
specifier|const
block|;
name|QString
name|translateKeySym
argument_list|(
argument|xcb_keysym_t keysym
argument_list|,
argument|uint xmodifiers
argument_list|,
argument|int&code
argument_list|,
argument|Qt::KeyboardModifiers&modifiers
argument_list|,
argument|QByteArray&chars
argument_list|,
argument|int&count
argument_list|)
block|;
name|void
name|setupModifiers
argument_list|()
block|;
name|void
name|setMask
argument_list|(
argument|uint sym
argument_list|,
argument|uint mask
argument_list|)
block|;
name|xcb_keysym_t
name|lookupString
argument_list|(
argument|QWindow *window
argument_list|,
argument|uint state
argument_list|,
argument|xcb_keycode_t code
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|QByteArray *chars
argument_list|)
block|;
name|uint
name|m_alt_mask
block|;
name|uint
name|m_super_mask
block|;
name|uint
name|m_hyper_mask
block|;
name|uint
name|m_meta_mask
block|;
name|uint
name|m_mode_switch_mask
block|;
name|uint
name|m_num_lock_mask
block|;
name|uint
name|m_caps_lock_mask
block|;
name|xcb_key_symbols_t
operator|*
name|m_key_symbols
block|;
name|xcb_keycode_t
name|m_autorepeat_code
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
end_unit
