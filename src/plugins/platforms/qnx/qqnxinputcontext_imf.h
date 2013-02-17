begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXINPUTCONTEXT_H
end_ifndef
begin_define
DECL|macro|QQNXINPUTCONTEXT_H
define|#
directive|define
name|QQNXINPUTCONTEXT_H
end_define
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QLocale>
end_include
begin_include
include|#
directive|include
file|<QtCore/QMetaType>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatformintegration.h>
end_include
begin_include
include|#
directive|include
file|"imf/imf_client.h"
end_include
begin_include
include|#
directive|include
file|"imf/input_control.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QQnxAbstractVirtualKeyboard
name|class
name|QQnxAbstractVirtualKeyboard
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QQnxIntegration
name|class
name|QQnxIntegration
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QQnxInputContext
range|:
name|public
name|QPlatformInputContext
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QQnxInputContext
argument_list|(
name|QQnxIntegration
operator|*
name|integration
argument_list|,
name|QQnxAbstractVirtualKeyboard
operator|&
name|keyboard
argument_list|)
block|;
operator|~
name|QQnxInputContext
argument_list|()
block|;
name|bool
name|isValid
argument_list|()
specifier|const
block|;
name|bool
name|filterEvent
argument_list|(
specifier|const
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|QRectF
name|keyboardRect
argument_list|()
specifier|const
block|;
name|void
name|reset
argument_list|()
block|;
name|void
name|update
argument_list|(
name|Qt
operator|::
name|InputMethodQueries
argument_list|)
block|;
name|bool
name|handleKeyboardEvent
argument_list|(
argument|int flags
argument_list|,
argument|int sym
argument_list|,
argument|int mod
argument_list|,
argument|int scan
argument_list|,
argument|int cap
argument_list|)
block|;
name|void
name|showInputPanel
argument_list|()
block|;
name|void
name|hideInputPanel
argument_list|()
block|;
name|bool
name|isInputPanelVisible
argument_list|()
specifier|const
block|;
name|QLocale
name|locale
argument_list|()
specifier|const
block|;
name|void
name|setFocusObject
argument_list|(
name|QObject
operator|*
name|object
argument_list|)
block|;
name|protected
operator|:
comment|// Filters only for IMF events.
name|bool
name|eventFilter
argument_list|(
name|QObject
operator|*
name|obj
argument_list|,
name|QEvent
operator|*
name|event
argument_list|)
block|;
name|private
name|Q_SLOTS
operator|:
name|void
name|keyboardVisibilityChanged
argument_list|(
argument|bool visible
argument_list|)
block|;
name|void
name|keyboardLocaleChanged
argument_list|(
specifier|const
name|QLocale
operator|&
name|locale
argument_list|)
block|;
name|private
operator|:
comment|// IMF Event dispatchers
name|bool
name|dispatchFocusEvent
argument_list|(
argument|FocusEventId id
argument_list|,
argument|int hints = Qt::ImhNone
argument_list|)
block|;
name|bool
name|dispatchRequestSoftwareInputPanel
argument_list|()
block|;
name|bool
name|dispatchCloseSoftwareInputPanel
argument_list|()
block|;
name|int32_t
name|processEvent
argument_list|(
name|event_t
operator|*
name|event
argument_list|)
block|;
name|void
name|closeSession
argument_list|()
block|;
name|void
name|openSession
argument_list|()
block|;
name|bool
name|hasSession
argument_list|()
block|;
name|void
name|endComposition
argument_list|()
block|;
name|void
name|setComposingText
argument_list|(
name|QString
specifier|const
operator|&
name|composingText
argument_list|)
block|;
name|bool
name|hasSelectedText
argument_list|()
block|;
comment|// IMF Event handlers - these events will come in from QCoreApplication.
name|int32_t
name|onBeginBatchEdit
argument_list|(
name|input_session_t
operator|*
name|ic
argument_list|)
block|;
name|int32_t
name|onClearMetaKeyStates
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t states
argument_list|)
block|;
name|int32_t
name|onCommitText
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|spannable_string_t *text
argument_list|,
argument|int32_t new_cursor_position
argument_list|)
block|;
name|int32_t
name|onDeleteSurroundingText
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t left_length
argument_list|,
argument|int32_t right_length
argument_list|)
block|;
name|int32_t
name|onEndBatchEdit
argument_list|(
name|input_session_t
operator|*
name|ic
argument_list|)
block|;
name|int32_t
name|onFinishComposingText
argument_list|(
name|input_session_t
operator|*
name|ic
argument_list|)
block|;
name|int32_t
name|onGetCursorCapsMode
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t req_modes
argument_list|)
block|;
name|int32_t
name|onGetCursorPosition
argument_list|(
name|input_session_t
operator|*
name|ic
argument_list|)
block|;
name|extracted_text_t
operator|*
name|onGetExtractedText
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|extracted_text_request_t *request
argument_list|,
argument|int32_t flags
argument_list|)
block|;
name|spannable_string_t
operator|*
name|onGetSelectedText
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t flags
argument_list|)
block|;
name|spannable_string_t
operator|*
name|onGetTextAfterCursor
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t n
argument_list|,
argument|int32_t flags
argument_list|)
block|;
name|spannable_string_t
operator|*
name|onGetTextBeforeCursor
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t n
argument_list|,
argument|int32_t flags
argument_list|)
block|;
name|int32_t
name|onPerformEditorAction
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t editor_action
argument_list|)
block|;
name|int32_t
name|onReportFullscreenMode
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t enabled
argument_list|)
block|;
name|int32_t
name|onSendEvent
argument_list|(
name|input_session_t
operator|*
name|ic
argument_list|,
name|event_t
operator|*
name|event
argument_list|)
block|;
name|int32_t
name|onSendAsyncEvent
argument_list|(
name|input_session_t
operator|*
name|ic
argument_list|,
name|event_t
operator|*
name|event
argument_list|)
block|;
name|int32_t
name|onSetComposingRegion
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t start
argument_list|,
argument|int32_t end
argument_list|)
block|;
name|int32_t
name|onSetComposingText
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|spannable_string_t *text
argument_list|,
argument|int32_t new_cursor_position
argument_list|)
block|;
name|int32_t
name|onSetSelection
argument_list|(
argument|input_session_t *ic
argument_list|,
argument|int32_t start
argument_list|,
argument|int32_t end
argument_list|)
block|;
name|int32_t
name|onForceUpdate
argument_list|()
block|;
name|int
name|m_lastCaretPos
block|;
name|bool
name|m_isComposing
block|;
name|QString
name|m_composingText
block|;
name|bool
name|m_inputPanelVisible
block|;
name|QLocale
name|m_inputPanelLocale
block|;
name|QQnxIntegration
operator|*
name|m_integration
block|;
name|QQnxAbstractVirtualKeyboard
operator|&
name|m_virtualKeyboad
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|extracted_text_t*
argument_list|)
end_macro
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QQNXINPUTCONTEXT_H
end_comment
end_unit
