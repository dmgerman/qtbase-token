begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"characterwidget.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|CharacterWidget
name|CharacterWidget
operator|::
name|CharacterWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|squareSize
operator|=
literal|24
expr_stmt|;
name|columns
operator|=
literal|16
expr_stmt|;
name|lastKey
operator|=
operator|-
literal|1
expr_stmt|;
name|setMouseTracking
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|updateFont
name|void
name|CharacterWidget
operator|::
name|updateFont
parameter_list|(
specifier|const
name|QFont
modifier|&
name|font
parameter_list|)
block|{
name|displayFont
operator|.
name|setFamily
argument_list|(
name|font
operator|.
name|family
argument_list|()
argument_list|)
expr_stmt|;
name|squareSize
operator|=
name|qMax
argument_list|(
literal|24
argument_list|,
name|QFontMetrics
argument_list|(
name|displayFont
argument_list|)
operator|.
name|xHeight
argument_list|()
operator|*
literal|3
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|updateSize
name|void
name|CharacterWidget
operator|::
name|updateSize
parameter_list|(
specifier|const
name|QString
modifier|&
name|fontSize
parameter_list|)
block|{
name|displayFont
operator|.
name|setPointSize
argument_list|(
name|fontSize
operator|.
name|toInt
argument_list|()
argument_list|)
expr_stmt|;
name|squareSize
operator|=
name|qMax
argument_list|(
literal|24
argument_list|,
name|QFontMetrics
argument_list|(
name|displayFont
argument_list|)
operator|.
name|xHeight
argument_list|()
operator|*
literal|3
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|updateStyle
name|void
name|CharacterWidget
operator|::
name|updateStyle
parameter_list|(
specifier|const
name|QString
modifier|&
name|fontStyle
parameter_list|)
block|{
name|QFontDatabase
name|fontDatabase
decl_stmt|;
specifier|const
name|QFont
operator|::
name|StyleStrategy
name|oldStrategy
init|=
name|displayFont
operator|.
name|styleStrategy
argument_list|()
decl_stmt|;
name|displayFont
operator|=
name|fontDatabase
operator|.
name|font
argument_list|(
name|displayFont
operator|.
name|family
argument_list|()
argument_list|,
name|fontStyle
argument_list|,
name|displayFont
operator|.
name|pointSize
argument_list|()
argument_list|)
expr_stmt|;
name|displayFont
operator|.
name|setStyleStrategy
argument_list|(
name|oldStrategy
argument_list|)
expr_stmt|;
name|squareSize
operator|=
name|qMax
argument_list|(
literal|24
argument_list|,
name|QFontMetrics
argument_list|(
name|displayFont
argument_list|)
operator|.
name|xHeight
argument_list|()
operator|*
literal|3
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateFontMerging
name|void
name|CharacterWidget
operator|::
name|updateFontMerging
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
if|if
condition|(
name|enable
condition|)
name|displayFont
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|PreferDefault
argument_list|)
expr_stmt|;
else|else
name|displayFont
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|NoFontMerging
argument_list|)
expr_stmt|;
name|adjustSize
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|CharacterWidget
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
return|return
name|QSize
argument_list|(
name|columns
operator|*
name|squareSize
argument_list|,
operator|(
literal|65536
operator|/
name|columns
operator|)
operator|*
name|squareSize
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|CharacterWidget
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPoint
name|widgetPosition
init|=
name|mapFromGlobal
argument_list|(
name|event
operator|->
name|globalPos
argument_list|()
argument_list|)
decl_stmt|;
name|uint
name|key
init|=
operator|(
name|widgetPosition
operator|.
name|y
argument_list|()
operator|/
name|squareSize
operator|)
operator|*
name|columns
operator|+
name|widgetPosition
operator|.
name|x
argument_list|()
operator|/
name|squareSize
decl_stmt|;
name|QString
name|text
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"<p>Character:<span style=\"font-size: 24pt; font-family: %1\">"
argument_list|)
operator|.
name|arg
argument_list|(
name|displayFont
operator|.
name|family
argument_list|()
argument_list|)
operator|+
name|QChar
argument_list|(
name|key
argument_list|)
operator|+
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"</span><p>Value: 0x"
argument_list|)
operator|+
name|QString
operator|::
name|number
argument_list|(
name|key
argument_list|,
literal|16
argument_list|)
decl_stmt|;
name|QToolTip
operator|::
name|showText
argument_list|(
name|event
operator|->
name|globalPos
argument_list|()
argument_list|,
name|text
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|CharacterWidget
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
if|if
condition|(
name|event
operator|->
name|button
argument_list|()
operator|==
name|Qt
operator|::
name|LeftButton
condition|)
block|{
name|lastKey
operator|=
operator|(
name|event
operator|->
name|y
argument_list|()
operator|/
name|squareSize
operator|)
operator|*
name|columns
operator|+
name|event
operator|->
name|x
argument_list|()
operator|/
name|squareSize
expr_stmt|;
if|if
condition|(
name|QChar
argument_list|(
name|lastKey
argument_list|)
operator|.
name|category
argument_list|()
operator|!=
name|QChar
operator|::
name|NoCategory
condition|)
emit|emit
name|characterSelected
argument_list|(
name|QString
argument_list|(
name|QChar
argument_list|(
name|lastKey
argument_list|)
argument_list|)
argument_list|)
emit|;
name|update
argument_list|()
expr_stmt|;
block|}
else|else
name|QWidget
operator|::
name|mousePressEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|CharacterWidget
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|painter
operator|.
name|fillRect
argument_list|(
name|event
operator|->
name|rect
argument_list|()
argument_list|,
name|QBrush
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|displayFont
argument_list|)
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QRect
name|redrawRect
init|=
name|event
operator|->
name|rect
argument_list|()
decl_stmt|;
name|int
name|beginRow
init|=
name|redrawRect
operator|.
name|top
argument_list|()
operator|/
name|squareSize
decl_stmt|;
name|int
name|endRow
init|=
name|redrawRect
operator|.
name|bottom
argument_list|()
operator|/
name|squareSize
decl_stmt|;
name|int
name|beginColumn
init|=
name|redrawRect
operator|.
name|left
argument_list|()
operator|/
name|squareSize
decl_stmt|;
name|int
name|endColumn
init|=
name|redrawRect
operator|.
name|right
argument_list|()
operator|/
name|squareSize
decl_stmt|;
comment|//! [7]
comment|//! [8]
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|gray
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
name|beginRow
init|;
name|row
operator|<=
name|endRow
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|column
init|=
name|beginColumn
init|;
name|column
operator|<=
name|endColumn
condition|;
operator|++
name|column
control|)
block|{
name|painter
operator|.
name|drawRect
argument_list|(
name|column
operator|*
name|squareSize
argument_list|,
name|row
operator|*
name|squareSize
argument_list|,
name|squareSize
argument_list|,
name|squareSize
argument_list|)
expr_stmt|;
block|}
comment|//! [8] //! [9]
block|}
comment|//! [9]
comment|//! [10]
name|QFontMetrics
name|fontMetrics
argument_list|(
name|displayFont
argument_list|)
decl_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|row
init|=
name|beginRow
init|;
name|row
operator|<=
name|endRow
condition|;
operator|++
name|row
control|)
block|{
for|for
control|(
name|int
name|column
init|=
name|beginColumn
init|;
name|column
operator|<=
name|endColumn
condition|;
operator|++
name|column
control|)
block|{
name|int
name|key
init|=
name|row
operator|*
name|columns
operator|+
name|column
decl_stmt|;
name|painter
operator|.
name|setClipRect
argument_list|(
name|column
operator|*
name|squareSize
argument_list|,
name|row
operator|*
name|squareSize
argument_list|,
name|squareSize
argument_list|,
name|squareSize
argument_list|)
expr_stmt|;
if|if
condition|(
name|key
operator|==
name|lastKey
condition|)
name|painter
operator|.
name|fillRect
argument_list|(
name|column
operator|*
name|squareSize
operator|+
literal|1
argument_list|,
name|row
operator|*
name|squareSize
operator|+
literal|1
argument_list|,
name|squareSize
argument_list|,
name|squareSize
argument_list|,
name|QBrush
argument_list|(
name|Qt
operator|::
name|red
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
name|column
operator|*
name|squareSize
operator|+
operator|(
name|squareSize
operator|/
literal|2
operator|)
operator|-
name|fontMetrics
operator|.
name|width
argument_list|(
name|QChar
argument_list|(
name|key
argument_list|)
argument_list|)
operator|/
literal|2
argument_list|,
name|row
operator|*
name|squareSize
operator|+
literal|4
operator|+
name|fontMetrics
operator|.
name|ascent
argument_list|()
argument_list|,
name|QString
argument_list|(
name|QChar
argument_list|(
name|key
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
