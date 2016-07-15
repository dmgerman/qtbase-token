begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTCURSOR_P_H
end_ifndef
begin_define
DECL|macro|QTEXTCURSOR_P_H
define|#
directive|define
name|QTEXTCURSOR_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"qtextcursor.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocument.h"
end_include
begin_include
include|#
directive|include
file|"qtextdocument_p.h"
end_include
begin_include
include|#
directive|include
file|<private/qtextformat_p.h>
end_include
begin_include
include|#
directive|include
file|"qtextobject.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QTextCursorPrivate
range|:
name|public
name|QSharedData
block|{
name|public
operator|:
name|QTextCursorPrivate
argument_list|(
name|QTextDocumentPrivate
operator|*
name|p
argument_list|)
block|;
name|QTextCursorPrivate
argument_list|(
specifier|const
name|QTextCursorPrivate
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|QTextCursorPrivate
argument_list|()
block|;      enum
name|AdjustResult
block|{
name|CursorMoved
block|,
name|CursorUnchanged
block|}
block|;
name|AdjustResult
name|adjustPosition
argument_list|(
argument|int positionOfChange
argument_list|,
argument|int charsAddedOrRemoved
argument_list|,
argument|QTextUndoCommand::Operation op
argument_list|)
block|;
name|void
name|adjustCursor
argument_list|(
argument|QTextCursor::MoveOperation m
argument_list|)
block|;
name|void
name|remove
argument_list|()
block|;
name|void
name|clearCells
argument_list|(
argument|QTextTable *table
argument_list|,
argument|int startRow
argument_list|,
argument|int startCol
argument_list|,
argument|int numRows
argument_list|,
argument|int numCols
argument_list|,
argument|QTextUndoCommand::Operation op
argument_list|)
block|;
specifier|inline
name|bool
name|setPosition
argument_list|(
argument|int newPosition
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|newPosition
operator|>=
literal|0
operator|&&
name|newPosition
operator|<
name|priv
operator|->
name|length
argument_list|()
argument_list|)
block|;
name|bool
name|moved
operator|=
name|position
operator|!=
name|newPosition
block|;
if|if
condition|(
name|moved
condition|)
block|{
name|position
operator|=
name|newPosition
expr_stmt|;
name|currentCharFormat
operator|=
operator|-
literal|1
expr_stmt|;
block|}
return|return
name|moved
return|;
block|}
name|void
name|setX
argument_list|()
block|;
name|bool
name|canDelete
argument_list|(
argument|int pos
argument_list|)
specifier|const
block|;
name|void
name|insertBlock
argument_list|(
specifier|const
name|QTextBlockFormat
operator|&
name|format
argument_list|,
specifier|const
name|QTextCharFormat
operator|&
name|charFormat
argument_list|)
block|;
name|bool
name|movePosition
argument_list|(
argument|QTextCursor::MoveOperation op
argument_list|,
argument|QTextCursor::MoveMode mode = QTextCursor::MoveAnchor
argument_list|)
block|;
specifier|inline
name|QTextBlock
name|block
argument_list|()
specifier|const
block|{
return|return
name|QTextBlock
argument_list|(
name|priv
argument_list|,
name|priv
operator|->
name|blockMap
argument_list|()
operator|.
name|findNode
argument_list|(
name|position
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|QTextBlockFormat
name|blockFormat
argument_list|()
specifier|const
block|{
return|return
name|block
argument_list|()
operator|.
name|blockFormat
argument_list|()
return|;
block|}
name|QTextLayout
operator|*
name|blockLayout
argument_list|(
argument|QTextBlock&block
argument_list|)
specifier|const
block|;
name|QTextTable
operator|*
name|complexSelectionTable
argument_list|()
specifier|const
block|;
name|void
name|selectedTableCells
argument_list|(
argument|int *firstRow
argument_list|,
argument|int *numRows
argument_list|,
argument|int *firstColumn
argument_list|,
argument|int *numColumns
argument_list|)
specifier|const
block|;
name|void
name|setBlockCharFormat
argument_list|(
argument|const QTextCharFormat&format
argument_list|,
argument|QTextDocumentPrivate::FormatChangeMode changeMode
argument_list|)
block|;
name|void
name|setBlockFormat
argument_list|(
argument|const QTextBlockFormat&format
argument_list|,
argument|QTextDocumentPrivate::FormatChangeMode changeMode
argument_list|)
block|;
name|void
name|setCharFormat
argument_list|(
argument|const QTextCharFormat&format
argument_list|,
argument|QTextDocumentPrivate::FormatChangeMode changeMode
argument_list|)
block|;
name|void
name|aboutToRemoveCell
argument_list|(
argument|int from
argument_list|,
argument|int to
argument_list|)
block|;
name|QTextDocumentPrivate
operator|*
name|priv
block|;
name|qreal
name|x
block|;
name|int
name|position
block|;
name|int
name|anchor
block|;
name|int
name|adjusted_anchor
block|;
name|int
name|currentCharFormat
block|;
name|uint
name|visualNavigation
operator|:
literal|1
block|;
name|uint
name|keepPositionOnInsert
operator|:
literal|1
block|;
name|uint
name|changed
operator|:
literal|1
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
comment|// QTEXTCURSOR_P_H
end_comment
end_unit
