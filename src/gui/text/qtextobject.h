begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTOBJECT_H
end_ifndef
begin_define
DECL|macro|QTEXTOBJECT_H
define|#
directive|define
name|QTEXTOBJECT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qtextformat.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qglyphrun.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QTextObjectPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocument
name|class
name|QTextDocument
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextDocumentPrivate
name|class
name|QTextDocumentPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextCursor
name|class
name|QTextCursor
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlock
name|class
name|QTextBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFragment
name|class
name|QTextFragment
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextLayout
name|class
name|QTextLayout
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextList
name|class
name|QTextList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextObject
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|protected
operator|:
name|explicit
name|QTextObject
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
operator|~
name|QTextObject
argument_list|()
block|;
name|void
name|setFormat
argument_list|(
specifier|const
name|QTextFormat
operator|&
name|format
argument_list|)
block|;
name|public
operator|:
name|QTextFormat
name|format
argument_list|()
specifier|const
block|;
name|int
name|formatIndex
argument_list|()
specifier|const
block|;
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
block|;
name|int
name|objectIndex
argument_list|()
specifier|const
block|;
name|QTextDocumentPrivate
operator|*
name|docHandle
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QTextObject
argument_list|(
name|QTextObjectPrivate
operator|&
name|p
argument_list|,
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextObject
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTextObject
argument_list|)
name|friend
name|class
name|QTextDocumentPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlockGroupPrivate
name|class
name|QTextBlockGroupPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextBlockGroup
range|:
name|public
name|QTextObject
block|{
name|Q_OBJECT
name|protected
operator|:
name|explicit
name|QTextBlockGroup
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
operator|~
name|QTextBlockGroup
argument_list|()
block|;
name|virtual
name|void
name|blockInserted
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|virtual
name|void
name|blockRemoved
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|virtual
name|void
name|blockFormatChanged
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|block
argument_list|)
block|;
name|QList
operator|<
name|QTextBlock
operator|>
name|blockList
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QTextBlockGroup
argument_list|(
name|QTextBlockGroupPrivate
operator|&
name|p
argument_list|,
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
name|private
operator|:
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextBlockGroup
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTextBlockGroup
argument_list|)
name|friend
name|class
name|QTextDocumentPrivate
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextFrameLayoutData
block|{
name|public
label|:
name|virtual
operator|~
name|QTextFrameLayoutData
argument_list|()
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QTextFramePrivate
name|class
name|QTextFramePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextFrame
range|:
name|public
name|QTextObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QTextFrame
argument_list|(
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
operator|~
name|QTextFrame
argument_list|()
block|;
specifier|inline
name|void
name|setFrameFormat
argument_list|(
specifier|const
name|QTextFrameFormat
operator|&
name|format
argument_list|)
block|;
name|QTextFrameFormat
name|frameFormat
argument_list|()
specifier|const
block|{
return|return
name|QTextObject
operator|::
name|format
argument_list|()
operator|.
name|toFrameFormat
argument_list|()
return|;
block|}
name|QTextCursor
name|firstCursorPosition
argument_list|()
specifier|const
block|;
name|QTextCursor
name|lastCursorPosition
argument_list|()
specifier|const
block|;
name|int
name|firstPosition
argument_list|()
specifier|const
block|;
name|int
name|lastPosition
argument_list|()
specifier|const
block|;
name|QTextFrameLayoutData
operator|*
name|layoutData
argument_list|()
specifier|const
block|;
name|void
name|setLayoutData
argument_list|(
name|QTextFrameLayoutData
operator|*
name|data
argument_list|)
block|;
name|QList
operator|<
name|QTextFrame
operator|*
operator|>
name|childFrames
argument_list|()
specifier|const
block|;
name|QTextFrame
operator|*
name|parentFrame
argument_list|()
specifier|const
block|;
name|class
name|Q_GUI_EXPORT
name|iterator
block|{
name|QTextFrame
operator|*
name|f
block|;
name|int
name|b
block|;
name|int
name|e
block|;
name|QTextFrame
operator|*
name|cf
block|;
name|int
name|cb
block|;
name|friend
name|class
name|QTextFrame
block|;
name|friend
name|class
name|QTextTableCell
block|;
name|friend
name|class
name|QTextDocumentLayoutPrivate
block|;
name|iterator
argument_list|(
argument|QTextFrame *frame
argument_list|,
argument|int block
argument_list|,
argument|int begin
argument_list|,
argument|int end
argument_list|)
block|;
name|public
operator|:
name|iterator
argument_list|()
block|;
name|iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
block|;
name|iterator
operator|&
name|operator
operator|=
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
block|;
name|QTextFrame
operator|*
name|parentFrame
argument_list|()
specifier|const
block|{
return|return
name|f
return|;
block|}
name|QTextFrame
operator|*
name|currentFrame
argument_list|()
specifier|const
block|;
name|QTextBlock
name|currentBlock
argument_list|()
specifier|const
block|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|{
return|return
operator|!
name|cf
operator|&&
name|cb
operator|==
name|e
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|f
operator|==
name|o
operator|.
name|f
operator|&&
name|cf
operator|==
name|o
operator|.
name|cf
operator|&&
name|cb
operator|==
name|o
operator|.
name|cb
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|f
operator|!=
name|o
operator|.
name|f
operator|||
name|cf
operator|!=
name|o
operator|.
name|cf
operator|||
name|cb
operator|!=
name|o
operator|.
name|cb
return|;
block|}
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|;
specifier|inline
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|++
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|;
specifier|inline
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|--
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
expr|}
block|;
name|friend
name|class
name|iterator
block|;
comment|// more Qt
typedef|typedef
name|iterator
name|Iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
block|;
name|iterator
name|end
argument_list|()
specifier|const
block|;
name|protected
operator|:
name|QTextFrame
argument_list|(
name|QTextFramePrivate
operator|&
name|p
argument_list|,
name|QTextDocument
operator|*
name|doc
argument_list|)
block|;
name|private
operator|:
name|friend
name|class
name|QTextDocumentPrivate
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QTextFrame
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QTextFrame
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTextFrame
operator|::
name|iterator
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|setFrameFormat
specifier|inline
name|void
name|QTextFrame
operator|::
name|setFrameFormat
argument_list|(
argument|const QTextFrameFormat&aformat
argument_list|)
block|{
name|QTextObject
operator|::
name|setFormat
argument_list|(
name|aformat
argument_list|)
block|; }
name|class
name|Q_GUI_EXPORT
name|QTextBlockUserData
block|{
name|public
operator|:
name|virtual
operator|~
name|QTextBlockUserData
argument_list|()
block|; }
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextBlock
block|{
name|friend
name|class
name|QSyntaxHighlighter
decl_stmt|;
name|public
label|:
specifier|inline
name|QTextBlock
argument_list|(
argument|QTextDocumentPrivate *priv
argument_list|,
argument|int b
argument_list|)
operator|:
name|p
argument_list|(
name|priv
argument_list|)
operator|,
name|n
argument_list|(
argument|b
argument_list|)
block|{}
specifier|inline
name|QTextBlock
argument_list|()
operator|:
name|p
argument_list|(
literal|0
argument_list|)
operator|,
name|n
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QTextBlock
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|o
argument_list|)
operator|:
name|p
argument_list|(
name|o
operator|.
name|p
argument_list|)
operator|,
name|n
argument_list|(
argument|o.n
argument_list|)
block|{}
specifier|inline
name|QTextBlock
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QTextBlock
operator|&
name|o
operator|)
block|{
name|p
operator|=
name|o
operator|.
name|p
block|;
name|n
operator|=
name|o
operator|.
name|n
block|;
return|return
operator|*
name|this
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTextBlock
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|p
operator|==
name|o
operator|.
name|p
operator|&&
name|n
operator|==
name|o
operator|.
name|n
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTextBlock
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|p
operator|!=
name|o
operator|.
name|p
operator|||
name|n
operator|!=
name|o
operator|.
name|n
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QTextBlock
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|position
argument_list|()
operator|<
name|o
operator|.
name|position
argument_list|()
return|;
block|}
name|int
name|position
argument_list|()
specifier|const
expr_stmt|;
name|int
name|length
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|contains
argument_list|(
name|int
name|position
argument_list|)
decl|const
decl_stmt|;
name|QTextLayout
operator|*
name|layout
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clearLayout
parameter_list|()
function_decl|;
name|QTextBlockFormat
name|blockFormat
argument_list|()
specifier|const
expr_stmt|;
name|int
name|blockFormatIndex
argument_list|()
specifier|const
expr_stmt|;
name|QTextCharFormat
name|charFormat
argument_list|()
specifier|const
expr_stmt|;
name|int
name|charFormatIndex
argument_list|()
specifier|const
expr_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|textDirection
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|QTextDocument
operator|*
name|document
argument_list|()
specifier|const
expr_stmt|;
name|QTextList
operator|*
name|textList
argument_list|()
specifier|const
expr_stmt|;
name|QTextBlockUserData
operator|*
name|userData
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUserData
parameter_list|(
name|QTextBlockUserData
modifier|*
name|data
parameter_list|)
function_decl|;
name|int
name|userState
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setUserState
parameter_list|(
name|int
name|state
parameter_list|)
function_decl|;
name|int
name|revision
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setRevision
parameter_list|(
name|int
name|rev
parameter_list|)
function_decl|;
name|bool
name|isVisible
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
function_decl|;
name|int
name|blockNumber
argument_list|()
specifier|const
expr_stmt|;
name|int
name|firstLineNumber
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLineCount
parameter_list|(
name|int
name|count
parameter_list|)
function_decl|;
name|int
name|lineCount
parameter_list|()
function|const;
name|class
name|Q_GUI_EXPORT
name|iterator
block|{
specifier|const
name|QTextDocumentPrivate
modifier|*
name|p
decl_stmt|;
name|int
name|b
decl_stmt|;
name|int
name|e
decl_stmt|;
name|int
name|n
decl_stmt|;
name|friend
name|class
name|QTextBlock
decl_stmt|;
name|iterator
argument_list|(
argument|const QTextDocumentPrivate *priv
argument_list|,
argument|int begin
argument_list|,
argument|int end
argument_list|,
argument|int f
argument_list|)
block|:
name|p
argument_list|(
name|priv
argument_list|)
operator|,
name|b
argument_list|(
name|begin
argument_list|)
operator|,
name|e
argument_list|(
name|end
argument_list|)
operator|,
name|n
argument_list|(
argument|f
argument_list|)
block|{}
name|public
operator|:
name|iterator
argument_list|()
operator|:
name|p
argument_list|(
literal|0
argument_list|)
operator|,
name|b
argument_list|(
literal|0
argument_list|)
operator|,
name|e
argument_list|(
literal|0
argument_list|)
operator|,
name|n
argument_list|(
literal|0
argument_list|)
block|{}
name|iterator
argument_list|(
specifier|const
name|iterator
operator|&
name|o
argument_list|)
operator|:
name|p
argument_list|(
name|o
operator|.
name|p
argument_list|)
operator|,
name|b
argument_list|(
name|o
operator|.
name|b
argument_list|)
operator|,
name|e
argument_list|(
name|o
operator|.
name|e
argument_list|)
operator|,
name|n
argument_list|(
argument|o.n
argument_list|)
block|{}
name|QTextFragment
name|fragment
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|atEnd
argument_list|()
specifier|const
block|{
return|return
name|n
operator|==
name|e
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|p
operator|==
name|o
operator|.
name|p
operator|&&
name|n
operator|==
name|o
operator|.
name|n
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|p
operator|!=
name|o
operator|.
name|p
operator|||
name|n
operator|!=
name|o
operator|.
name|n
return|;
block|}
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
expr_stmt|;
specifier|inline
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|++
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
expr_stmt|;
specifier|inline
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|tmp
operator|=
operator|*
name|this
block|;
name|operator
operator|--
operator|(
operator|)
block|;
return|return
name|tmp
return|;
block|}
block|}
empty_stmt|;
comment|// more Qt
typedef|typedef
name|iterator
name|Iterator
typedef|;
name|iterator
name|begin
argument_list|()
specifier|const
expr_stmt|;
name|iterator
name|end
argument_list|()
specifier|const
expr_stmt|;
name|QTextBlock
name|next
argument_list|()
specifier|const
expr_stmt|;
name|QTextBlock
name|previous
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|QTextDocumentPrivate
operator|*
name|docHandle
argument_list|()
specifier|const
block|{
return|return
name|p
return|;
block|}
specifier|inline
name|int
name|fragmentIndex
argument_list|()
specifier|const
block|{
return|return
name|n
return|;
block|}
name|private
label|:
name|QTextDocumentPrivate
modifier|*
name|p
decl_stmt|;
name|int
name|n
decl_stmt|;
name|friend
name|class
name|QTextDocumentPrivate
decl_stmt|;
name|friend
name|class
name|QTextLayout
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTextBlock
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTextBlock
operator|::
name|iterator
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextFragment
block|{
name|public
label|:
specifier|inline
name|QTextFragment
argument_list|(
argument|const QTextDocumentPrivate *priv
argument_list|,
argument|int f
argument_list|,
argument|int fe
argument_list|)
operator|:
name|p
argument_list|(
name|priv
argument_list|)
operator|,
name|n
argument_list|(
name|f
argument_list|)
operator|,
name|ne
argument_list|(
argument|fe
argument_list|)
block|{}
specifier|inline
name|QTextFragment
argument_list|()
operator|:
name|p
argument_list|(
literal|0
argument_list|)
operator|,
name|n
argument_list|(
literal|0
argument_list|)
operator|,
name|ne
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|QTextFragment
argument_list|(
specifier|const
name|QTextFragment
operator|&
name|o
argument_list|)
operator|:
name|p
argument_list|(
name|o
operator|.
name|p
argument_list|)
operator|,
name|n
argument_list|(
name|o
operator|.
name|n
argument_list|)
operator|,
name|ne
argument_list|(
argument|o.ne
argument_list|)
block|{}
specifier|inline
name|QTextFragment
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QTextFragment
operator|&
name|o
operator|)
block|{
name|p
operator|=
name|o
operator|.
name|p
block|;
name|n
operator|=
name|o
operator|.
name|n
block|;
name|ne
operator|=
name|o
operator|.
name|ne
block|;
return|return
operator|*
name|this
return|;
block|}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|p
operator|&&
name|n
return|;
block|}
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QTextFragment
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|p
operator|==
name|o
operator|.
name|p
operator|&&
name|n
operator|==
name|o
operator|.
name|n
return|;
block|}
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QTextFragment
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|p
operator|!=
name|o
operator|.
name|p
operator|||
name|n
operator|!=
name|o
operator|.
name|n
return|;
block|}
specifier|inline
name|bool
name|operator
operator|<
operator|(
specifier|const
name|QTextFragment
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|position
argument_list|()
operator|<
name|o
operator|.
name|position
argument_list|()
return|;
block|}
name|int
name|position
argument_list|()
specifier|const
expr_stmt|;
name|int
name|length
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|contains
argument_list|(
name|int
name|position
argument_list|)
decl|const
decl_stmt|;
name|QTextCharFormat
name|charFormat
argument_list|()
specifier|const
expr_stmt|;
name|int
name|charFormatIndex
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_RAWFONT
argument_list|)
name|QList
operator|<
name|QGlyphRun
operator|>
name|glyphRuns
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
specifier|const
name|QTextDocumentPrivate
modifier|*
name|p
decl_stmt|;
name|int
name|n
decl_stmt|;
name|int
name|ne
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QTextFragment
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTEXTOBJECT_H
end_comment
end_unit
