begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKEYSEQUENCE_H
end_ifndef
begin_define
DECL|macro|QKEYSEQUENCE_H
define|#
directive|define
name|QKEYSEQUENCE_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_SHORTCUT
comment|/*****************************************************************************   QKeySequence stream functions  *****************************************************************************/
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
DECL|variable|QKeySequence
name|class
name|QKeySequence
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|in
operator|,
specifier|const
name|QKeySequence
operator|&
name|ks
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|out
operator|,
name|QKeySequence
operator|&
name|ks
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|qdoc
end_ifdef
begin_function_decl
name|void
name|qt_set_sequence_auto_mnemonic
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QKeySequencePrivate
name|class
name|QKeySequencePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QKeySequence
block|{
name|public
label|:
enum|enum
name|StandardKey
block|{
name|UnknownKey
block|,
name|HelpContents
block|,
name|WhatsThis
block|,
name|Open
block|,
name|Close
block|,
name|Save
block|,
name|New
block|,
name|Delete
block|,
name|Cut
block|,
name|Copy
block|,
name|Paste
block|,
name|Undo
block|,
name|Redo
block|,
name|Back
block|,
name|Forward
block|,
name|Refresh
block|,
name|ZoomIn
block|,
name|ZoomOut
block|,
name|Print
block|,
name|AddTab
block|,
name|NextChild
block|,
name|PreviousChild
block|,
name|Find
block|,
name|FindNext
block|,
name|FindPrevious
block|,
name|Replace
block|,
name|SelectAll
block|,
name|Bold
block|,
name|Italic
block|,
name|Underline
block|,
name|MoveToNextChar
block|,
name|MoveToPreviousChar
block|,
name|MoveToNextWord
block|,
name|MoveToPreviousWord
block|,
name|MoveToNextLine
block|,
name|MoveToPreviousLine
block|,
name|MoveToNextPage
block|,
name|MoveToPreviousPage
block|,
name|MoveToStartOfLine
block|,
name|MoveToEndOfLine
block|,
name|MoveToStartOfBlock
block|,
name|MoveToEndOfBlock
block|,
name|MoveToStartOfDocument
block|,
name|MoveToEndOfDocument
block|,
name|SelectNextChar
block|,
name|SelectPreviousChar
block|,
name|SelectNextWord
block|,
name|SelectPreviousWord
block|,
name|SelectNextLine
block|,
name|SelectPreviousLine
block|,
name|SelectNextPage
block|,
name|SelectPreviousPage
block|,
name|SelectStartOfLine
block|,
name|SelectEndOfLine
block|,
name|SelectStartOfBlock
block|,
name|SelectEndOfBlock
block|,
name|SelectStartOfDocument
block|,
name|SelectEndOfDocument
block|,
name|DeleteStartOfWord
block|,
name|DeleteEndOfWord
block|,
name|DeleteEndOfLine
block|,
name|InsertParagraphSeparator
block|,
name|InsertLineSeparator
block|,
name|SaveAs
block|,
name|Preferences
block|,
name|Quit
block|}
enum|;
enum|enum
name|SequenceFormat
block|{
name|NativeText
block|,
name|PortableText
block|}
enum|;
name|QKeySequence
argument_list|()
expr_stmt|;
name|QKeySequence
argument_list|(
specifier|const
name|QString
operator|&
name|key
argument_list|)
expr_stmt|;
name|QKeySequence
argument_list|(
argument|const QString&key
argument_list|,
argument|SequenceFormat format
argument_list|)
empty_stmt|;
name|QKeySequence
argument_list|(
argument|int k1
argument_list|,
argument|int k2 =
literal|0
argument_list|,
argument|int k3 =
literal|0
argument_list|,
argument|int k4 =
literal|0
argument_list|)
empty_stmt|;
name|QKeySequence
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|ks
argument_list|)
expr_stmt|;
name|QKeySequence
argument_list|(
argument|StandardKey key
argument_list|)
empty_stmt|;
operator|~
name|QKeySequence
argument_list|()
expr_stmt|;
name|int
name|count
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|isEmpty
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|SequenceMatch
block|{
name|NoMatch
block|,
name|PartialMatch
block|,
name|ExactMatch
block|}
enum|;
name|QString
name|toString
argument_list|(
name|SequenceFormat
name|format
operator|=
name|PortableText
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QKeySequence
name|fromString
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|SequenceFormat
name|format
init|=
name|PortableText
parameter_list|)
function_decl|;
name|SequenceMatch
name|matches
argument_list|(
specifier|const
name|QKeySequence
operator|&
name|seq
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QKeySequence
name|mnemonic
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
specifier|static
name|QList
operator|<
name|QKeySequence
operator|>
name|keyBindings
argument_list|(
argument|StandardKey key
argument_list|)
expr_stmt|;
if|#
directive|if
name|QT_DEPRECATED_SINCE
argument_list|(
literal|5
operator|,
literal|0
argument_list|)
name|QT_DEPRECATED
name|operator
name|QString
argument_list|()
specifier|const
block|{
return|return
name|toString
argument_list|(
name|QKeySequence
operator|::
name|NativeText
argument_list|)
return|;
block|}
name|QT_DEPRECATED
name|operator
name|int
argument_list|()
specifier|const
block|{
if|if
condition|(
literal|1
operator|<=
name|count
argument_list|()
condition|)
return|return
name|operator
index|[]
operator|(
literal|0
operator|)
return|;
return|return
literal|0
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|int
name|operator
index|[]
argument_list|(
name|uint
name|i
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QKeySequence
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QKeySequence
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_RVALUE_REFS
end_ifdef
begin_decl_stmt
specifier|inline
name|QKeySequence
modifier|&
name|operator
init|=
operator|(
name|QKeySequence
operator|&&
name|other
operator|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|inline
name|void
name|swap
parameter_list|(
name|QKeySequence
modifier|&
name|other
parameter_list|)
block|{
name|qSwap
argument_list|(
name|d
argument_list|,
name|other
operator|.
name|d
argument_list|)
expr_stmt|;
block|}
end_function
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QKeySequence
operator|&
name|other
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QKeySequence
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QKeySequence
operator|&
name|ks
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QKeySequence
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|other
operator|<
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QKeySequence
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
name|other
operator|<
operator|*
name|this
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QKeySequence
operator|&
name|other
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|<
name|other
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|bool
name|isDetached
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_function_decl
specifier|static
name|int
name|decodeString
parameter_list|(
specifier|const
name|QString
modifier|&
name|ks
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
specifier|static
name|QString
name|encodeString
parameter_list|(
name|int
name|key
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|assign
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|int
name|assign
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|SequenceFormat
name|format
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|setKey
parameter_list|(
name|int
name|key
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|QKeySequencePrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
name|in
operator|,
specifier|const
name|QKeySequence
operator|&
name|ks
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|friend
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
name|in
operator|,
name|QKeySequence
operator|&
name|ks
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|friend
name|class
name|Q3AccelManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QShortcutMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QShortcut
decl_stmt|;
end_decl_stmt
begin_label
name|public
label|:
end_label
begin_typedef
typedef|typedef
name|QKeySequencePrivate
modifier|*
name|DataPtr
typedef|;
end_typedef
begin_function
specifier|inline
name|DataPtr
modifier|&
name|data_ptr
parameter_list|()
block|{
return|return
name|d
return|;
block|}
end_function
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QKeySequence
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QKeySequence
argument_list|)
end_macro
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QKeySequence
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QKeySequence
block|{
name|public
label|:
name|QKeySequence
argument_list|()
block|{}
name|QKeySequence
argument_list|(
argument|int
argument_list|)
block|{}
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SHORTCUT
end_comment
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QKEYSEQUENCE_H
end_comment
end_unit
