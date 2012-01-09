begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTCURSOR_H
end_ifndef
begin_define
DECL|macro|QTEXTCURSOR_H
define|#
directive|define
name|QTEXTCURSOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qshareddata.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextformat.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursorPrivate
name|class
name|QTextCursorPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocumentFragment
name|class
name|QTextDocumentFragment
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCharFormat
name|class
name|QTextCharFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlockFormat
name|class
name|QTextBlockFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextListFormat
name|class
name|QTextListFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextTableFormat
name|class
name|QTextTableFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrameFormat
name|class
name|QTextFrameFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextImageFormat
name|class
name|QTextImageFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocumentPrivate
name|class
name|QTextDocumentPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextList
name|class
name|QTextList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextTable
name|class
name|QTextTable
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFrame
name|class
name|QTextFrame
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlock
name|class
name|QTextBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextCursor
block|{
name|public
label|:
name|QTextCursor
argument_list|()
expr_stmt|;
name|explicit
name|QTextCursor
parameter_list|(
name|QTextDocument
modifier|*
name|document
parameter_list|)
function_decl|;
name|QTextCursor
argument_list|(
argument|QTextDocumentPrivate *p
argument_list|,
argument|int pos
argument_list|)
empty_stmt|;
name|explicit
name|QTextCursor
parameter_list|(
name|QTextFrame
modifier|*
name|frame
parameter_list|)
function_decl|;
name|explicit
name|QTextCursor
parameter_list|(
specifier|const
name|QTextBlock
modifier|&
name|block
parameter_list|)
function_decl|;
name|explicit
name|QTextCursor
parameter_list|(
name|QTextCursorPrivate
modifier|*
name|d
parameter_list|)
function_decl|;
name|QTextCursor
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|cursor
argument_list|)
expr_stmt|;
name|QTextCursor
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QTextCursor
operator|&
name|other
operator|)
decl_stmt|;
operator|~
name|QTextCursor
argument_list|()
expr_stmt|;
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|MoveMode
block|{
name|MoveAnchor
block|,
name|KeepAnchor
block|}
enum|;
name|void
name|setPosition
parameter_list|(
name|int
name|pos
parameter_list|,
name|MoveMode
name|mode
init|=
name|MoveAnchor
parameter_list|)
function_decl|;
name|int
name|position
argument_list|()
specifier|const
expr_stmt|;
name|int
name|positionInBlock
argument_list|()
specifier|const
expr_stmt|;
name|int
name|anchor
argument_list|()
specifier|const
expr_stmt|;
name|void
name|insertText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|void
name|insertText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|,
specifier|const
name|QTextCharFormat
modifier|&
name|format
parameter_list|)
function_decl|;
enum|enum
name|MoveOperation
block|{
name|NoMove
block|,
name|Start
block|,
name|Up
block|,
name|StartOfLine
block|,
name|StartOfBlock
block|,
name|StartOfWord
block|,
name|PreviousBlock
block|,
name|PreviousCharacter
block|,
name|PreviousWord
block|,
name|Left
block|,
name|WordLeft
block|,
name|End
block|,
name|Down
block|,
name|EndOfLine
block|,
name|EndOfWord
block|,
name|EndOfBlock
block|,
name|NextBlock
block|,
name|NextCharacter
block|,
name|NextWord
block|,
name|Right
block|,
name|WordRight
block|,
name|NextCell
block|,
name|PreviousCell
block|,
name|NextRow
block|,
name|PreviousRow
block|}
enum|;
name|bool
name|movePosition
parameter_list|(
name|MoveOperation
name|op
parameter_list|,
name|MoveMode
init|=
name|MoveAnchor
parameter_list|,
name|int
name|n
init|=
literal|1
parameter_list|)
function_decl|;
name|bool
name|visualNavigation
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVisualNavigation
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|void
name|setVerticalMovementX
parameter_list|(
name|int
name|x
parameter_list|)
function_decl|;
name|int
name|verticalMovementX
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setKeepPositionOnInsert
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|bool
name|keepPositionOnInsert
argument_list|()
specifier|const
expr_stmt|;
name|void
name|deleteChar
parameter_list|()
function_decl|;
name|void
name|deletePreviousChar
parameter_list|()
function_decl|;
enum|enum
name|SelectionType
block|{
name|WordUnderCursor
block|,
name|LineUnderCursor
block|,
name|BlockUnderCursor
block|,
name|Document
block|}
enum|;
name|void
name|select
parameter_list|(
name|SelectionType
name|selection
parameter_list|)
function_decl|;
name|bool
name|hasSelection
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|hasComplexSelection
argument_list|()
specifier|const
expr_stmt|;
name|void
name|removeSelectedText
parameter_list|()
function_decl|;
name|void
name|clearSelection
parameter_list|()
function_decl|;
name|int
name|selectionStart
argument_list|()
specifier|const
expr_stmt|;
name|int
name|selectionEnd
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|selectedText
argument_list|()
specifier|const
expr_stmt|;
name|QTextDocumentFragment
name|selection
argument_list|()
specifier|const
expr_stmt|;
name|void
name|selectedTableCells
argument_list|(
name|int
operator|*
name|firstRow
argument_list|,
name|int
operator|*
name|numRows
argument_list|,
name|int
operator|*
name|firstColumn
argument_list|,
name|int
operator|*
name|numColumns
argument_list|)
decl|const
decl_stmt|;
name|QTextBlock
name|block
argument_list|()
specifier|const
expr_stmt|;
name|QTextCharFormat
name|charFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCharFormat
parameter_list|(
specifier|const
name|QTextCharFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|mergeCharFormat
parameter_list|(
specifier|const
name|QTextCharFormat
modifier|&
name|modifier
parameter_list|)
function_decl|;
name|QTextBlockFormat
name|blockFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBlockFormat
parameter_list|(
specifier|const
name|QTextBlockFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|mergeBlockFormat
parameter_list|(
specifier|const
name|QTextBlockFormat
modifier|&
name|modifier
parameter_list|)
function_decl|;
name|QTextCharFormat
name|blockCharFormat
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setBlockCharFormat
parameter_list|(
specifier|const
name|QTextCharFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|mergeBlockCharFormat
parameter_list|(
specifier|const
name|QTextCharFormat
modifier|&
name|modifier
parameter_list|)
function_decl|;
name|bool
name|atBlockStart
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|atBlockEnd
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|atStart
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|atEnd
argument_list|()
specifier|const
expr_stmt|;
name|void
name|insertBlock
parameter_list|()
function_decl|;
name|void
name|insertBlock
parameter_list|(
specifier|const
name|QTextBlockFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|insertBlock
parameter_list|(
specifier|const
name|QTextBlockFormat
modifier|&
name|format
parameter_list|,
specifier|const
name|QTextCharFormat
modifier|&
name|charFormat
parameter_list|)
function_decl|;
name|QTextList
modifier|*
name|insertList
parameter_list|(
specifier|const
name|QTextListFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QTextList
modifier|*
name|insertList
argument_list|(
name|QTextListFormat
operator|::
name|Style
name|style
argument_list|)
decl_stmt|;
name|QTextList
modifier|*
name|createList
parameter_list|(
specifier|const
name|QTextListFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QTextList
modifier|*
name|createList
argument_list|(
name|QTextListFormat
operator|::
name|Style
name|style
argument_list|)
decl_stmt|;
name|QTextList
operator|*
name|currentList
argument_list|()
specifier|const
expr_stmt|;
name|QTextTable
modifier|*
name|insertTable
parameter_list|(
name|int
name|rows
parameter_list|,
name|int
name|cols
parameter_list|,
specifier|const
name|QTextTableFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QTextTable
modifier|*
name|insertTable
parameter_list|(
name|int
name|rows
parameter_list|,
name|int
name|cols
parameter_list|)
function_decl|;
name|QTextTable
operator|*
name|currentTable
argument_list|()
specifier|const
expr_stmt|;
name|QTextFrame
modifier|*
name|insertFrame
parameter_list|(
specifier|const
name|QTextFrameFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|QTextFrame
operator|*
name|currentFrame
argument_list|()
specifier|const
expr_stmt|;
name|void
name|insertFragment
parameter_list|(
specifier|const
name|QTextDocumentFragment
modifier|&
name|fragment
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_TEXTHTMLPARSER
name|void
name|insertHtml
parameter_list|(
specifier|const
name|QString
modifier|&
name|html
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|// QT_NO_TEXTHTMLPARSER
name|void
name|insertImage
argument_list|(
specifier|const
name|QTextImageFormat
operator|&
name|format
argument_list|,
name|QTextFrameFormat
operator|::
name|Position
name|alignment
argument_list|)
decl_stmt|;
name|void
name|insertImage
parameter_list|(
specifier|const
name|QTextImageFormat
modifier|&
name|format
parameter_list|)
function_decl|;
name|void
name|insertImage
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|void
name|insertImage
parameter_list|(
specifier|const
name|QImage
modifier|&
name|image
parameter_list|,
specifier|const
name|QString
modifier|&
name|name
init|=
name|QString
argument_list|()
parameter_list|)
function_decl|;
name|void
name|beginEditBlock
parameter_list|()
function_decl|;
name|void
name|joinPreviousEditBlock
parameter_list|()
function_decl|;
name|void
name|endEditBlock
parameter_list|()
function_decl|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTextCursor
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QTextCursor
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|QTextCursor
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTextCursor
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|QTextCursor
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|>
operator|(
specifier|const
name|QTextCursor
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|isCopyOf
argument_list|(
specifier|const
name|QTextCursor
operator|&
name|other
argument_list|)
decl|const
decl_stmt|;
name|int
name|blockNumber
argument_list|()
specifier|const
expr_stmt|;
name|int
name|columnNumber
argument_list|()
specifier|const
expr_stmt|;
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|QSharedDataPointer
operator|<
name|QTextCursorPrivate
operator|>
name|d
expr_stmt|;
name|friend
name|class
name|QTextCursorPrivate
decl_stmt|;
name|friend
name|class
name|QTextDocumentFragmentPrivate
decl_stmt|;
name|friend
name|class
name|QTextCopyHelper
decl_stmt|;
name|friend
name|class
name|QWidgetTextControlPrivate
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTCURSOR_H
end_comment
end_unit
