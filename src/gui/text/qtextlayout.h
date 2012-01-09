begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTEXTLAYOUT_H
end_ifndef
begin_define
DECL|macro|QTEXTLAYOUT_H
define|#
directive|define
name|QTEXTLAYOUT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qstring.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qvector.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qcolor.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qevent.h>
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
begin_include
include|#
directive|include
file|<QtGui/qtextcursor.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QTextEngine
name|class
name|QTextEngine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QFont
name|class
name|QFont
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRect
name|class
name|QRect
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QRegion
name|class
name|QRegion
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFormat
name|class
name|QTextFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPalette
name|class
name|QPalette
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPainter
name|class
name|QPainter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextInlineObject
block|{
name|public
label|:
name|QTextInlineObject
argument_list|(
argument|int i
argument_list|,
argument|QTextEngine *e
argument_list|)
block|:
name|itm
argument_list|(
name|i
argument_list|)
operator|,
name|eng
argument_list|(
argument|e
argument_list|)
block|{}
specifier|inline
name|QTextInlineObject
argument_list|()
operator|:
name|itm
argument_list|(
literal|0
argument_list|)
operator|,
name|eng
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|eng
return|;
block|}
name|QRectF
name|rect
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|width
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|ascent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|descent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|height
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
name|void
name|setWidth
parameter_list|(
name|qreal
name|w
parameter_list|)
function_decl|;
name|void
name|setAscent
parameter_list|(
name|qreal
name|a
parameter_list|)
function_decl|;
name|void
name|setDescent
parameter_list|(
name|qreal
name|d
parameter_list|)
function_decl|;
name|int
name|textPosition
argument_list|()
specifier|const
expr_stmt|;
name|int
name|formatIndex
argument_list|()
specifier|const
expr_stmt|;
name|QTextFormat
name|format
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|friend
name|class
name|QTextLayout
decl_stmt|;
name|int
name|itm
decl_stmt|;
name|QTextEngine
modifier|*
name|eng
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
DECL|variable|QPaintDevice
name|class
name|QPaintDevice
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextFormat
name|class
name|QTextFormat
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextLine
name|class
name|QTextLine
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextBlock
name|class
name|QTextBlock
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QTextOption
name|class
name|QTextOption
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextLayout
block|{
name|public
label|:
comment|// does itemization
name|QTextLayout
argument_list|()
expr_stmt|;
name|QTextLayout
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|)
expr_stmt|;
name|QTextLayout
argument_list|(
specifier|const
name|QString
operator|&
name|text
argument_list|,
specifier|const
name|QFont
operator|&
name|font
argument_list|,
name|QPaintDevice
operator|*
name|paintdevice
operator|=
literal|0
argument_list|)
expr_stmt|;
name|QTextLayout
argument_list|(
specifier|const
name|QTextBlock
operator|&
name|b
argument_list|)
expr_stmt|;
operator|~
name|QTextLayout
argument_list|()
expr_stmt|;
name|void
name|setFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|f
parameter_list|)
function_decl|;
name|QFont
name|font
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setText
parameter_list|(
specifier|const
name|QString
modifier|&
name|string
parameter_list|)
function_decl|;
name|QString
name|text
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setTextOption
parameter_list|(
specifier|const
name|QTextOption
modifier|&
name|option
parameter_list|)
function_decl|;
name|QTextOption
name|textOption
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPreeditArea
parameter_list|(
name|int
name|position
parameter_list|,
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
function_decl|;
name|int
name|preeditAreaPosition
argument_list|()
specifier|const
expr_stmt|;
name|QString
name|preeditAreaText
argument_list|()
specifier|const
decl_stmt|;
struct|struct
name|FormatRange
block|{
name|int
name|start
decl_stmt|;
name|int
name|length
decl_stmt|;
name|QTextCharFormat
name|format
decl_stmt|;
block|}
struct|;
name|void
name|setAdditionalFormats
argument_list|(
specifier|const
name|QList
operator|<
name|FormatRange
operator|>
operator|&
name|overrides
argument_list|)
decl_stmt|;
name|QList
operator|<
name|FormatRange
operator|>
name|additionalFormats
argument_list|()
specifier|const
expr_stmt|;
name|void
name|clearAdditionalFormats
parameter_list|()
function_decl|;
name|void
name|setCacheEnabled
parameter_list|(
name|bool
name|enable
parameter_list|)
function_decl|;
name|bool
name|cacheEnabled
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setCursorMoveStyle
argument_list|(
name|Qt
operator|::
name|CursorMoveStyle
name|style
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|CursorMoveStyle
name|cursorMoveStyle
argument_list|()
specifier|const
expr_stmt|;
name|void
name|beginLayout
parameter_list|()
function_decl|;
name|void
name|endLayout
parameter_list|()
function_decl|;
name|void
name|clearLayout
parameter_list|()
function_decl|;
name|QTextLine
name|createLine
parameter_list|()
function_decl|;
name|int
name|lineCount
argument_list|()
specifier|const
expr_stmt|;
name|QTextLine
name|lineAt
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|QTextLine
name|lineForTextPosition
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
enum|enum
name|CursorMode
block|{
name|SkipCharacters
block|,
name|SkipWords
block|}
enum|;
name|bool
name|isValidCursorPosition
argument_list|(
name|int
name|pos
argument_list|)
decl|const
decl_stmt|;
name|int
name|nextCursorPosition
argument_list|(
name|int
name|oldPos
argument_list|,
name|CursorMode
name|mode
operator|=
name|SkipCharacters
argument_list|)
decl|const
decl_stmt|;
name|int
name|previousCursorPosition
argument_list|(
name|int
name|oldPos
argument_list|,
name|CursorMode
name|mode
operator|=
name|SkipCharacters
argument_list|)
decl|const
decl_stmt|;
name|int
name|leftCursorPosition
argument_list|(
name|int
name|oldPos
argument_list|)
decl|const
decl_stmt|;
name|int
name|rightCursorPosition
argument_list|(
name|int
name|oldPos
argument_list|)
decl|const
decl_stmt|;
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
specifier|const
name|QVector
operator|<
name|FormatRange
operator|>
operator|&
name|selections
operator|=
name|QVector
operator|<
name|FormatRange
operator|>
operator|(
operator|)
argument_list|,
specifier|const
name|QRectF
operator|&
name|clip
operator|=
name|QRectF
argument_list|()
argument_list|)
decl|const
decl_stmt|;
name|void
name|drawCursor
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
name|int
name|cursorPosition
argument_list|)
decl|const
decl_stmt|;
name|void
name|drawCursor
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QPointF
operator|&
name|pos
argument_list|,
name|int
name|cursorPosition
argument_list|,
name|int
name|width
argument_list|)
decl|const
decl_stmt|;
name|QPointF
name|position
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setPosition
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
name|QRectF
name|boundingRect
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|minimumWidth
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|maximumWidth
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
argument_list|(
argument|int from = -
literal|1
argument_list|,
argument|int length = -
literal|1
argument_list|)
specifier|const
expr_stmt|;
endif|#
directive|endif
name|QTextEngine
operator|*
name|engine
argument_list|()
specifier|const
block|{
return|return
name|d
return|;
block|}
name|void
name|setFlags
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
name|private
label|:
name|QTextLayout
argument_list|(
name|QTextEngine
operator|*
name|e
argument_list|)
operator|:
name|d
argument_list|(
argument|e
argument_list|)
block|{}
name|Q_DISABLE_COPY
argument_list|(
argument|QTextLayout
argument_list|)
name|friend
name|class
name|QPainter
expr_stmt|;
name|friend
name|class
name|QPSPrinter
decl_stmt|;
name|friend
name|class
name|QGraphicsSimpleTextItemPrivate
decl_stmt|;
name|friend
name|class
name|QGraphicsSimpleTextItem
decl_stmt|;
name|friend
name|void
name|qt_format_text
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|_r
parameter_list|,
name|int
name|tf
parameter_list|,
specifier|const
name|QTextOption
modifier|*
parameter_list|,
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
name|QRectF
modifier|*
name|brect
parameter_list|,
name|int
name|tabstops
parameter_list|,
name|int
modifier|*
name|tabarray
parameter_list|,
name|int
name|tabarraylen
parameter_list|,
name|QPainter
modifier|*
name|painter
parameter_list|)
function_decl|;
name|QTextEngine
modifier|*
name|d
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QTextLine
block|{
name|public
label|:
specifier|inline
name|QTextLine
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
operator|,
name|eng
argument_list|(
literal|0
argument_list|)
block|{}
specifier|inline
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|eng
return|;
block|}
name|QRectF
name|rect
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|x
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|y
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|width
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|ascent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|descent
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|height
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|leading
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setLeadingIncluded
parameter_list|(
name|bool
name|included
parameter_list|)
function_decl|;
name|bool
name|leadingIncluded
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|naturalTextWidth
argument_list|()
specifier|const
expr_stmt|;
name|qreal
name|horizontalAdvance
argument_list|()
specifier|const
expr_stmt|;
name|QRectF
name|naturalTextRect
argument_list|()
specifier|const
expr_stmt|;
enum|enum
name|Edge
block|{
name|Leading
block|,
name|Trailing
block|}
enum|;
enum|enum
name|CursorPosition
block|{
name|CursorBetweenCharacters
block|,
name|CursorOnCharacter
block|}
enum|;
comment|/* cursorPos gets set to the valid position */
name|qreal
name|cursorToX
argument_list|(
name|int
operator|*
name|cursorPos
argument_list|,
name|Edge
name|edge
operator|=
name|Leading
argument_list|)
decl|const
decl_stmt|;
specifier|inline
name|qreal
name|cursorToX
argument_list|(
name|int
name|cursorPos
argument_list|,
name|Edge
name|edge
operator|=
name|Leading
argument_list|)
decl|const
block|{
return|return
name|cursorToX
argument_list|(
operator|&
name|cursorPos
argument_list|,
name|edge
argument_list|)
return|;
block|}
name|int
name|xToCursor
argument_list|(
name|qreal
name|x
argument_list|,
name|CursorPosition
operator|=
name|CursorBetweenCharacters
argument_list|)
decl|const
decl_stmt|;
name|void
name|setLineWidth
parameter_list|(
name|qreal
name|width
parameter_list|)
function_decl|;
name|void
name|setNumColumns
parameter_list|(
name|int
name|columns
parameter_list|)
function_decl|;
name|void
name|setNumColumns
parameter_list|(
name|int
name|columns
parameter_list|,
name|qreal
name|alignmentWidth
parameter_list|)
function_decl|;
name|void
name|setPosition
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|pos
parameter_list|)
function_decl|;
name|QPointF
name|position
argument_list|()
specifier|const
expr_stmt|;
name|int
name|textStart
argument_list|()
specifier|const
expr_stmt|;
name|int
name|textLength
argument_list|()
specifier|const
expr_stmt|;
name|int
name|lineNumber
argument_list|()
specifier|const
block|{
return|return
name|index
return|;
block|}
name|void
name|draw
argument_list|(
name|QPainter
operator|*
name|p
argument_list|,
specifier|const
name|QPointF
operator|&
name|point
argument_list|,
specifier|const
name|QTextLayout
operator|::
name|FormatRange
operator|*
name|selection
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
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
argument_list|(
argument|int from = -
literal|1
argument_list|,
argument|int length = -
literal|1
argument_list|)
specifier|const
expr_stmt|;
endif|#
directive|endif
name|private
label|:
name|QTextLine
argument_list|(
argument|int line
argument_list|,
argument|QTextEngine *e
argument_list|)
block|:
name|index
argument_list|(
name|line
argument_list|)
operator|,
name|eng
argument_list|(
argument|e
argument_list|)
block|{}
name|void
name|layout_helper
argument_list|(
argument|int numGlyphs
argument_list|)
expr_stmt|;
name|friend
name|class
name|QTextLayout
decl_stmt|;
name|friend
name|class
name|QTextFragment
decl_stmt|;
name|int
name|index
decl_stmt|;
name|QTextEngine
modifier|*
name|eng
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
comment|// QTEXTLAYOUT_H
end_comment
end_unit
