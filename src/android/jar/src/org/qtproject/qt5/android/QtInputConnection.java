begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the Android port of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_package
DECL|package|org.qtproject.qt5.android
package|package
name|org
operator|.
name|qtproject
operator|.
name|qt5
operator|.
name|android
package|;
end_package
begin_import
import|import
name|android
operator|.
name|content
operator|.
name|Context
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|View
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|BaseInputConnection
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|CompletionInfo
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|ExtractedText
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|ExtractedTextRequest
import|;
end_import
begin_import
import|import
name|android
operator|.
name|view
operator|.
name|inputmethod
operator|.
name|InputMethodManager
import|;
end_import
begin_class
DECL|class|QtExtractedText
class|class
name|QtExtractedText
block|{
DECL|field|partialEndOffset
specifier|public
name|int
name|partialEndOffset
decl_stmt|;
DECL|field|partialStartOffset
specifier|public
name|int
name|partialStartOffset
decl_stmt|;
DECL|field|selectionEnd
specifier|public
name|int
name|selectionEnd
decl_stmt|;
DECL|field|selectionStart
specifier|public
name|int
name|selectionStart
decl_stmt|;
DECL|field|startOffset
specifier|public
name|int
name|startOffset
decl_stmt|;
DECL|field|text
specifier|public
name|String
name|text
decl_stmt|;
block|}
end_class
begin_class
DECL|class|QtNativeInputConnection
class|class
name|QtNativeInputConnection
block|{
DECL|method|commitText
specifier|static
specifier|native
name|boolean
name|commitText
parameter_list|(
name|String
name|text
parameter_list|,
name|int
name|newCursorPosition
parameter_list|)
function_decl|;
DECL|method|commitCompletion
specifier|static
specifier|native
name|boolean
name|commitCompletion
parameter_list|(
name|String
name|text
parameter_list|,
name|int
name|position
parameter_list|)
function_decl|;
DECL|method|deleteSurroundingText
specifier|static
specifier|native
name|boolean
name|deleteSurroundingText
parameter_list|(
name|int
name|leftLength
parameter_list|,
name|int
name|rightLength
parameter_list|)
function_decl|;
DECL|method|finishComposingText
specifier|static
specifier|native
name|boolean
name|finishComposingText
parameter_list|()
function_decl|;
DECL|method|getCursorCapsMode
specifier|static
specifier|native
name|int
name|getCursorCapsMode
parameter_list|(
name|int
name|reqModes
parameter_list|)
function_decl|;
DECL|method|getExtractedText
specifier|static
specifier|native
name|QtExtractedText
name|getExtractedText
parameter_list|(
name|int
name|hintMaxChars
parameter_list|,
name|int
name|hintMaxLines
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
DECL|method|getSelectedText
specifier|static
specifier|native
name|String
name|getSelectedText
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
DECL|method|getTextAfterCursor
specifier|static
specifier|native
name|String
name|getTextAfterCursor
parameter_list|(
name|int
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
DECL|method|getTextBeforeCursor
specifier|static
specifier|native
name|String
name|getTextBeforeCursor
parameter_list|(
name|int
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
DECL|method|setComposingText
specifier|static
specifier|native
name|boolean
name|setComposingText
parameter_list|(
name|String
name|text
parameter_list|,
name|int
name|newCursorPosition
parameter_list|)
function_decl|;
DECL|method|setComposingRegion
specifier|static
specifier|native
name|boolean
name|setComposingRegion
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
DECL|method|setSelection
specifier|static
specifier|native
name|boolean
name|setSelection
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
function_decl|;
DECL|method|selectAll
specifier|static
specifier|native
name|boolean
name|selectAll
parameter_list|()
function_decl|;
DECL|method|cut
specifier|static
specifier|native
name|boolean
name|cut
parameter_list|()
function_decl|;
DECL|method|copy
specifier|static
specifier|native
name|boolean
name|copy
parameter_list|()
function_decl|;
DECL|method|copyURL
specifier|static
specifier|native
name|boolean
name|copyURL
parameter_list|()
function_decl|;
DECL|method|paste
specifier|static
specifier|native
name|boolean
name|paste
parameter_list|()
function_decl|;
block|}
end_class
begin_class
DECL|class|QtInputConnection
specifier|public
class|class
name|QtInputConnection
extends|extends
name|BaseInputConnection
block|{
DECL|field|ID_SELECT_ALL
specifier|private
specifier|static
specifier|final
name|int
name|ID_SELECT_ALL
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|selectAll
decl_stmt|;
DECL|field|ID_CUT
specifier|private
specifier|static
specifier|final
name|int
name|ID_CUT
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|cut
decl_stmt|;
DECL|field|ID_COPY
specifier|private
specifier|static
specifier|final
name|int
name|ID_COPY
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|copy
decl_stmt|;
DECL|field|ID_PASTE
specifier|private
specifier|static
specifier|final
name|int
name|ID_PASTE
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|paste
decl_stmt|;
DECL|field|ID_COPY_URL
specifier|private
specifier|static
specifier|final
name|int
name|ID_COPY_URL
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|copyUrl
decl_stmt|;
DECL|field|ID_SWITCH_INPUT_METHOD
specifier|private
specifier|static
specifier|final
name|int
name|ID_SWITCH_INPUT_METHOD
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|switchInputMethod
decl_stmt|;
DECL|field|ID_ADD_TO_DICTIONARY
specifier|private
specifier|static
specifier|final
name|int
name|ID_ADD_TO_DICTIONARY
init|=
name|android
operator|.
name|R
operator|.
name|id
operator|.
name|addToDictionary
decl_stmt|;
DECL|field|m_view
name|View
name|m_view
decl_stmt|;
DECL|field|m_closing
name|boolean
name|m_closing
decl_stmt|;
DECL|method|QtInputConnection
specifier|public
name|QtInputConnection
parameter_list|(
name|View
name|targetView
parameter_list|)
block|{
name|super
argument_list|(
name|targetView
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|m_view
operator|=
name|targetView
expr_stmt|;
name|m_closing
operator|=
literal|false
expr_stmt|;
block|}
annotation|@
name|Override
DECL|method|beginBatchEdit
specifier|public
name|boolean
name|beginBatchEdit
parameter_list|()
block|{
name|m_closing
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
annotation|@
name|Override
DECL|method|endBatchEdit
specifier|public
name|boolean
name|endBatchEdit
parameter_list|()
block|{
name|m_closing
operator|=
literal|false
expr_stmt|;
return|return
literal|true
return|;
block|}
annotation|@
name|Override
DECL|method|commitCompletion
specifier|public
name|boolean
name|commitCompletion
parameter_list|(
name|CompletionInfo
name|text
parameter_list|)
block|{
name|m_closing
operator|=
literal|false
expr_stmt|;
return|return
name|QtNativeInputConnection
operator|.
name|commitCompletion
argument_list|(
name|text
operator|.
name|getText
argument_list|()
operator|.
name|toString
argument_list|()
argument_list|,
name|text
operator|.
name|getPosition
argument_list|()
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|commitText
specifier|public
name|boolean
name|commitText
parameter_list|(
name|CharSequence
name|text
parameter_list|,
name|int
name|newCursorPosition
parameter_list|)
block|{
name|m_closing
operator|=
literal|false
expr_stmt|;
return|return
name|QtNativeInputConnection
operator|.
name|commitText
argument_list|(
name|text
operator|.
name|toString
argument_list|()
argument_list|,
name|newCursorPosition
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|deleteSurroundingText
specifier|public
name|boolean
name|deleteSurroundingText
parameter_list|(
name|int
name|leftLength
parameter_list|,
name|int
name|rightLength
parameter_list|)
block|{
name|m_closing
operator|=
literal|false
expr_stmt|;
return|return
name|QtNativeInputConnection
operator|.
name|deleteSurroundingText
argument_list|(
name|leftLength
argument_list|,
name|rightLength
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|finishComposingText
specifier|public
name|boolean
name|finishComposingText
parameter_list|()
block|{
if|if
condition|(
name|m_closing
condition|)
block|{
name|m_view
operator|.
name|postDelayed
argument_list|(
operator|new
name|Runnable
argument_list|()
block|{
annotation|@
name|Override
specifier|public
name|void
name|run
parameter_list|()
block|{
name|QtNative
operator|.
name|activityDelegate
argument_list|()
operator|.
name|m_keyboardIsVisible
operator|=
literal|false
expr_stmt|;
block|}
block|}
argument_list|,
literal|100
argument_list|)
expr_stmt|;
comment|// it seems finishComposingText comes much faster than onKeyUp event,
comment|// so we must delay hide notification
name|m_closing
operator|=
literal|false
expr_stmt|;
block|}
else|else
block|{
name|m_closing
operator|=
literal|true
expr_stmt|;
block|}
return|return
name|QtNativeInputConnection
operator|.
name|finishComposingText
argument_list|()
return|;
block|}
annotation|@
name|Override
DECL|method|getCursorCapsMode
specifier|public
name|int
name|getCursorCapsMode
parameter_list|(
name|int
name|reqModes
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|getCursorCapsMode
argument_list|(
name|reqModes
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|getExtractedText
specifier|public
name|ExtractedText
name|getExtractedText
parameter_list|(
name|ExtractedTextRequest
name|request
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|QtExtractedText
name|qExtractedText
init|=
name|QtNativeInputConnection
operator|.
name|getExtractedText
argument_list|(
name|request
operator|.
name|hintMaxChars
argument_list|,
name|request
operator|.
name|hintMaxLines
argument_list|,
name|flags
argument_list|)
decl_stmt|;
name|ExtractedText
name|extractedText
init|=
operator|new
name|ExtractedText
argument_list|()
decl_stmt|;
name|extractedText
operator|.
name|partialEndOffset
operator|=
name|qExtractedText
operator|.
name|partialEndOffset
expr_stmt|;
name|extractedText
operator|.
name|partialStartOffset
operator|=
name|qExtractedText
operator|.
name|partialStartOffset
expr_stmt|;
name|extractedText
operator|.
name|selectionEnd
operator|=
name|qExtractedText
operator|.
name|selectionEnd
expr_stmt|;
name|extractedText
operator|.
name|selectionStart
operator|=
name|qExtractedText
operator|.
name|selectionStart
expr_stmt|;
name|extractedText
operator|.
name|startOffset
operator|=
name|qExtractedText
operator|.
name|startOffset
expr_stmt|;
name|extractedText
operator|.
name|text
operator|=
name|qExtractedText
operator|.
name|text
expr_stmt|;
return|return
name|extractedText
return|;
block|}
DECL|method|getSelectedText
specifier|public
name|CharSequence
name|getSelectedText
parameter_list|(
name|int
name|flags
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|getSelectedText
argument_list|(
name|flags
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|getTextAfterCursor
specifier|public
name|CharSequence
name|getTextAfterCursor
parameter_list|(
name|int
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|getTextAfterCursor
argument_list|(
name|length
argument_list|,
name|flags
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|getTextBeforeCursor
specifier|public
name|CharSequence
name|getTextBeforeCursor
parameter_list|(
name|int
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|getTextBeforeCursor
argument_list|(
name|length
argument_list|,
name|flags
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|performContextMenuAction
specifier|public
name|boolean
name|performContextMenuAction
parameter_list|(
name|int
name|id
parameter_list|)
block|{
switch|switch
condition|(
name|id
condition|)
block|{
case|case
name|ID_SELECT_ALL
case|:
return|return
name|QtNativeInputConnection
operator|.
name|selectAll
argument_list|()
return|;
case|case
name|ID_COPY
case|:
return|return
name|QtNativeInputConnection
operator|.
name|copy
argument_list|()
return|;
case|case
name|ID_COPY_URL
case|:
return|return
name|QtNativeInputConnection
operator|.
name|copyURL
argument_list|()
return|;
case|case
name|ID_CUT
case|:
return|return
name|QtNativeInputConnection
operator|.
name|cut
argument_list|()
return|;
case|case
name|ID_PASTE
case|:
return|return
name|QtNativeInputConnection
operator|.
name|paste
argument_list|()
return|;
case|case
name|ID_SWITCH_INPUT_METHOD
case|:
name|InputMethodManager
name|imm
init|=
operator|(
name|InputMethodManager
operator|)
name|m_view
operator|.
name|getContext
argument_list|()
operator|.
name|getSystemService
argument_list|(
name|Context
operator|.
name|INPUT_METHOD_SERVICE
argument_list|)
decl_stmt|;
if|if
condition|(
name|imm
operator|!=
literal|null
condition|)
name|imm
operator|.
name|showInputMethodPicker
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
case|case
name|ID_ADD_TO_DICTIONARY
case|:
comment|// TODO
comment|//            String word = m_editable.subSequence(0, m_editable.length()).toString();
comment|//            if (word != null) {
comment|//                Intent i = new Intent("com.android.settings.USER_DICTIONARY_INSERT");
comment|//                i.putExtra("word", word);
comment|//                i.setFlags(i.getFlags() | Intent.FLAG_ACTIVITY_NEW_TASK);
comment|//                m_view.getContext().startActivity(i);
comment|//            }
return|return
literal|true
return|;
block|}
return|return
name|super
operator|.
name|performContextMenuAction
argument_list|(
name|id
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|setComposingText
specifier|public
name|boolean
name|setComposingText
parameter_list|(
name|CharSequence
name|text
parameter_list|,
name|int
name|newCursorPosition
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|setComposingText
argument_list|(
name|text
operator|.
name|toString
argument_list|()
argument_list|,
name|newCursorPosition
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|setComposingRegion
specifier|public
name|boolean
name|setComposingRegion
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|setComposingRegion
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
return|;
block|}
annotation|@
name|Override
DECL|method|setSelection
specifier|public
name|boolean
name|setSelection
parameter_list|(
name|int
name|start
parameter_list|,
name|int
name|end
parameter_list|)
block|{
return|return
name|QtNativeInputConnection
operator|.
name|setSelection
argument_list|(
name|start
argument_list|,
name|end
argument_list|)
return|;
block|}
block|}
end_class
end_unit
