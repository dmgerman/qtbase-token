begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"mydecoration.h"
end_include
begin_comment
comment|/* XPM */
end_comment
begin_decl_stmt
DECL|variable|_close_button
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|_close_button
index|[]
init|=
block|{
literal|"16 16 3 1"
block|,
literal|"  c none"
block|,
literal|". c #ffafaf"
block|,
literal|"x c #000000"
block|,
literal|"                "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|" x............x "
block|,
literal|" x.x........x.x "
block|,
literal|" x..x......x..x "
block|,
literal|" x...x....x...x "
block|,
literal|" x....x..x....x "
block|,
literal|" x.....xx.....x "
block|,
literal|" x.....xx.....x "
block|,
literal|" x....x..x....x "
block|,
literal|" x...x....x...x "
block|,
literal|" x..x......x..x "
block|,
literal|" x.x........x.x "
block|,
literal|" x............x "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|"                "
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_normalize_button
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|_normalize_button
index|[]
init|=
block|{
literal|"16 16 4 1"
block|,
literal|"  c none"
block|,
literal|". c #dfdfff"
block|,
literal|"o c #7f7f7f"
block|,
literal|"x c #000000"
block|,
literal|"                "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|" xx...........x "
block|,
literal|" x.x..........x "
block|,
literal|" x..x..x......x "
block|,
literal|" x...xxx......x "
block|,
literal|" x...xxx......x "
block|,
literal|" x..xxxx......x "
block|,
literal|" x............x "
block|,
literal|" x.......xxxx.x "
block|,
literal|" x.......x..x.x "
block|,
literal|" x.......x..x.x "
block|,
literal|" x.......xxxx.x "
block|,
literal|" x............x "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|"                "
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_maximize_button
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|_maximize_button
index|[]
init|=
block|{
literal|"16 16 4 1"
block|,
literal|"  c none"
block|,
literal|". c #dfdfff"
block|,
literal|"o c #7f7f7f"
block|,
literal|"x c #000000"
block|,
literal|"                "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|" x............x "
block|,
literal|" x.......xxxx.x "
block|,
literal|" x........xxx.x "
block|,
literal|" x........xxx.x "
block|,
literal|" x.......x..x.x "
block|,
literal|" x......x.....x "
block|,
literal|" x.....x......x "
block|,
literal|" x.oooo.......x "
block|,
literal|" x.o..o.......x "
block|,
literal|" x.o..o.......x "
block|,
literal|" x.oooo.......x "
block|,
literal|" x............x "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|"                "
block|}
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_help_button
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|_help_button
index|[]
init|=
block|{
literal|"16 16 3 1"
block|,
literal|"  c none"
block|,
literal|". c #afffdf"
block|,
literal|"x c #000000"
block|,
literal|"                "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|" x............x "
block|,
literal|" x....xxxx....x "
block|,
literal|" x..xx....xx..x "
block|,
literal|" x.xx......xx.x "
block|,
literal|" x.xx......xx.x "
block|,
literal|" x........xx..x "
block|,
literal|" x......xx....x "
block|,
literal|" x.....xx.....x "
block|,
literal|" x.....xx.....x "
block|,
literal|" x............x "
block|,
literal|" x.....xx.....x "
block|,
literal|" x............x "
block|,
literal|" xxxxxxxxxxxxxx "
block|,
literal|"                "
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [constructor start]
end_comment
begin_constructor
DECL|function|MyDecoration
name|MyDecoration
operator|::
name|MyDecoration
parameter_list|()
member_init_list|:
name|QDecorationDefault
argument_list|()
block|{
name|border
operator|=
literal|4
expr_stmt|;
name|titleHeight
operator|=
literal|24
expr_stmt|;
name|buttonWidth
operator|=
literal|20
expr_stmt|;
name|buttonHeight
operator|=
literal|20
expr_stmt|;
name|buttonMargin
operator|=
literal|2
expr_stmt|;
name|buttonHints
operator|<<
name|Qt
operator|::
name|Window
operator|<<
name|Qt
operator|::
name|WindowMaximizeButtonHint
operator|<<
name|Qt
operator|::
name|WindowContextHelpButtonHint
expr_stmt|;
comment|//! [constructor start]
comment|//! [map window flags to decoration regions]
name|buttonHintMap
index|[
name|Qt
operator|::
name|Window
index|]
operator|=
name|Close
expr_stmt|;
name|buttonHintMap
index|[
name|Qt
operator|::
name|WindowMaximizeButtonHint
index|]
operator|=
name|Maximize
expr_stmt|;
name|buttonHintMap
index|[
name|Qt
operator|::
name|WindowContextHelpButtonHint
index|]
operator|=
name|Help
expr_stmt|;
comment|//! [map window flags to decoration regions]
comment|//! [map decoration regions to pixmaps]
name|normalButtonPixmaps
index|[
name|Close
index|]
operator|=
name|QPixmap
argument_list|(
name|_close_button
argument_list|)
expr_stmt|;
name|normalButtonPixmaps
index|[
name|Maximize
index|]
operator|=
name|QPixmap
argument_list|(
name|_maximize_button
argument_list|)
expr_stmt|;
name|normalButtonPixmaps
index|[
name|Normalize
index|]
operator|=
name|QPixmap
argument_list|(
name|_normalize_button
argument_list|)
expr_stmt|;
name|normalButtonPixmaps
index|[
name|Help
index|]
operator|=
name|QPixmap
argument_list|(
name|_help_button
argument_list|)
expr_stmt|;
name|maximizedButtonPixmaps
index|[
name|Close
index|]
operator|=
name|QPixmap
argument_list|(
name|_close_button
argument_list|)
expr_stmt|;
name|maximizedButtonPixmaps
index|[
name|Maximize
index|]
operator|=
name|QPixmap
argument_list|(
name|_normalize_button
argument_list|)
expr_stmt|;
name|maximizedButtonPixmaps
index|[
name|Normalize
index|]
operator|=
name|QPixmap
argument_list|(
name|_normalize_button
argument_list|)
expr_stmt|;
name|maximizedButtonPixmaps
index|[
name|Help
index|]
operator|=
name|QPixmap
argument_list|(
name|_help_button
argument_list|)
expr_stmt|;
comment|//! [map decoration regions to pixmaps]
comment|//! [constructor end]
name|stateRegions
operator|<<
name|Close
operator|<<
name|Maximize
operator|<<
name|Help
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [constructor end]
end_comment
begin_comment
comment|//! [region start]
end_comment
begin_function
DECL|function|region
name|QRegion
name|MyDecoration
operator|::
name|region
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|,
specifier|const
name|QRect
modifier|&
name|insideRect
parameter_list|,
name|int
name|decorationRegion
parameter_list|)
block|{
comment|//! [region start]
comment|//! [calculate the positions of buttons based on the window flags used]
name|QHash
argument_list|<
name|DecorationRegion
argument_list|,
name|int
argument_list|>
name|buttons
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|widget
operator|->
name|windowFlags
argument_list|()
decl_stmt|;
name|int
name|dx
init|=
operator|-
name|buttonMargin
operator|-
name|buttonWidth
decl_stmt|;
foreach|foreach
control|(
name|Qt
operator|::
name|WindowType
name|button
decl|,
name|buttonHints
control|)
block|{
if|if
condition|(
name|flags
operator|&
name|button
condition|)
block|{
name|int
name|x
init|=
operator|(
name|buttons
operator|.
name|size
argument_list|()
operator|+
literal|1
operator|)
operator|*
name|dx
decl_stmt|;
name|buttons
index|[
name|buttonHintMap
index|[
name|button
index|]
index|]
operator|=
name|x
expr_stmt|;
block|}
block|}
comment|//! [calculate the positions of buttons based on the window flags used]
comment|//! [calculate the extent of the title]
name|int
name|titleRightMargin
init|=
name|buttons
operator|.
name|size
argument_list|()
operator|*
name|dx
decl_stmt|;
name|QRect
name|outsideRect
argument_list|(
name|insideRect
operator|.
name|left
argument_list|()
operator|-
name|border
argument_list|,
name|insideRect
operator|.
name|top
argument_list|()
operator|-
name|titleHeight
operator|-
name|border
argument_list|,
name|insideRect
operator|.
name|width
argument_list|()
operator|+
literal|2
operator|*
name|border
argument_list|,
name|insideRect
operator|.
name|height
argument_list|()
operator|+
name|titleHeight
operator|+
literal|2
operator|*
name|border
argument_list|)
decl_stmt|;
comment|//! [calculate the extent of the title]
comment|//! [check for all regions]
name|QRegion
name|region
decl_stmt|;
if|if
condition|(
name|decorationRegion
operator|==
name|All
condition|)
block|{
name|region
operator|+=
name|QRegion
argument_list|(
name|outsideRect
argument_list|)
operator|-
name|QRegion
argument_list|(
name|insideRect
argument_list|)
expr_stmt|;
return|return
name|region
return|;
block|}
comment|//! [check for all regions]
comment|//! [compose a region based on the decorations specified]
if|if
condition|(
name|decorationRegion
operator|&
name|Title
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
operator|.
name|adjusted
argument_list|(
name|border
argument_list|,
name|border
argument_list|,
operator|-
name|border
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setHeight
argument_list|(
name|titleHeight
argument_list|)
expr_stmt|;
comment|// Adjust the width to accommodate buttons.
name|rect
operator|.
name|setWidth
argument_list|(
name|qMax
argument_list|(
literal|0
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|+
name|titleRightMargin
argument_list|)
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Top
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
operator|.
name|adjusted
argument_list|(
name|border
argument_list|,
literal|0
argument_list|,
operator|-
name|border
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setHeight
argument_list|(
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Left
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
name|border
argument_list|,
literal|0
argument_list|,
operator|-
name|border
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Right
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
name|border
argument_list|,
literal|0
argument_list|,
operator|-
name|border
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setLeft
argument_list|(
name|rect
operator|.
name|right
argument_list|()
operator|+
literal|1
operator|-
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Bottom
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
operator|.
name|adjusted
argument_list|(
name|border
argument_list|,
literal|0
argument_list|,
operator|-
name|border
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setTop
argument_list|(
name|rect
operator|.
name|bottom
argument_list|()
operator|+
literal|1
operator|-
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|TopLeft
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
decl_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|border
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setHeight
argument_list|(
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|TopRight
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
decl_stmt|;
name|rect
operator|.
name|setLeft
argument_list|(
name|rect
operator|.
name|right
argument_list|()
operator|+
literal|1
operator|-
name|border
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setHeight
argument_list|(
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|BottomLeft
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
decl_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|border
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setTop
argument_list|(
name|rect
operator|.
name|bottom
argument_list|()
operator|+
literal|1
operator|-
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|BottomRight
condition|)
block|{
name|QRect
name|rect
init|=
name|outsideRect
decl_stmt|;
name|rect
operator|.
name|setLeft
argument_list|(
name|rect
operator|.
name|right
argument_list|()
operator|+
literal|1
operator|-
name|border
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setTop
argument_list|(
name|rect
operator|.
name|bottom
argument_list|()
operator|+
literal|1
operator|-
name|border
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
comment|//! [compose a region based on the decorations specified]
comment|//! [add a region for each button only if it is present]
foreach|foreach
control|(
name|QDecoration
operator|::
name|DecorationRegion
name|testRegion
decl|,
name|stateRegions
control|)
block|{
if|if
condition|(
name|decorationRegion
operator|&
name|testRegion
operator|and
name|buttons
operator|.
name|contains
argument_list|(
name|testRegion
argument_list|)
condition|)
block|{
comment|// Inside the title rectangle
name|QRect
name|rect
init|=
name|outsideRect
operator|.
name|adjusted
argument_list|(
name|border
argument_list|,
name|border
argument_list|,
operator|-
name|border
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|rect
operator|.
name|setHeight
argument_list|(
name|titleHeight
argument_list|)
expr_stmt|;
name|dx
operator|=
name|buttons
index|[
name|testRegion
index|]
expr_stmt|;
name|rect
operator|.
name|setLeft
argument_list|(
name|rect
operator|.
name|right
argument_list|()
operator|+
literal|1
operator|+
name|dx
argument_list|)
expr_stmt|;
name|rect
operator|.
name|setWidth
argument_list|(
name|buttonWidth
operator|+
name|buttonMargin
argument_list|)
expr_stmt|;
name|region
operator|+=
name|rect
expr_stmt|;
block|}
block|}
comment|//! [add a region for each button only if it is present]
comment|//! [region end]
return|return
name|region
return|;
block|}
end_function
begin_comment
comment|//! [region end]
end_comment
begin_comment
comment|//! [paint start]
end_comment
begin_function
DECL|function|paint
name|bool
name|MyDecoration
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|,
name|int
name|decorationRegion
parameter_list|,
name|DecorationState
name|state
parameter_list|)
block|{
if|if
condition|(
name|decorationRegion
operator|==
name|None
condition|)
return|return
literal|false
return|;
comment|//! [paint start]
comment|//! [paint different regions]
name|bool
name|handled
init|=
literal|false
decl_stmt|;
name|QPalette
name|palette
init|=
name|QApplication
operator|::
name|palette
argument_list|()
decl_stmt|;
name|QHash
argument_list|<
name|DecorationRegion
argument_list|,
name|QPixmap
argument_list|>
name|buttonPixmaps
decl_stmt|;
if|if
condition|(
name|widget
operator|->
name|windowState
argument_list|()
operator|==
name|Qt
operator|::
name|WindowMaximized
condition|)
name|buttonPixmaps
operator|=
name|maximizedButtonPixmaps
expr_stmt|;
else|else
name|buttonPixmaps
operator|=
name|normalButtonPixmaps
expr_stmt|;
if|if
condition|(
name|decorationRegion
operator|&
name|Title
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|Title
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|save
argument_list|()
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|palette
operator|.
name|color
argument_list|(
name|QPalette
operator|::
name|Text
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|rect
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|widget
operator|->
name|windowTitle
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Top
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|Top
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Left
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|Left
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Right
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|Right
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|Bottom
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|Bottom
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|TopLeft
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|TopLeft
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|TopRight
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|TopRight
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|BottomLeft
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|BottomLeft
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|decorationRegion
operator|&
name|BottomRight
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|BottomRight
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Dark
argument_list|)
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
comment|//! [paint different regions]
comment|//! [paint buttons]
name|int
name|margin
init|=
operator|(
name|titleHeight
operator|-
literal|16
operator|)
operator|/
literal|2
decl_stmt|;
name|Qt
operator|::
name|WindowFlags
name|flags
init|=
name|widget
operator|->
name|windowFlags
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|DecorationRegion
name|testRegion
decl|,
name|stateRegions
control|)
block|{
if|if
condition|(
name|decorationRegion
operator|&
name|testRegion
operator|&&
name|flags
operator|&
name|buttonHintMap
operator|.
name|key
argument_list|(
name|testRegion
argument_list|)
condition|)
block|{
name|QRect
name|rect
init|=
name|QDecoration
operator|::
name|region
argument_list|(
name|widget
argument_list|,
name|testRegion
argument_list|)
operator|.
name|boundingRect
argument_list|()
decl_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|rect
argument_list|,
name|palette
operator|.
name|brush
argument_list|(
name|QPalette
operator|::
name|Base
argument_list|)
argument_list|)
expr_stmt|;
name|QRect
name|buttonRect
init|=
name|rect
operator|.
name|adjusted
argument_list|(
literal|0
argument_list|,
name|margin
argument_list|,
operator|-
name|buttonMargin
operator|-
name|margin
argument_list|,
operator|-
name|buttonMargin
argument_list|)
decl_stmt|;
name|painter
operator|->
name|drawPixmap
argument_list|(
name|buttonRect
operator|.
name|topLeft
argument_list|()
argument_list|,
name|buttonPixmaps
index|[
name|testRegion
index|]
argument_list|)
expr_stmt|;
name|handled
operator|=
literal|true
expr_stmt|;
block|}
block|}
comment|//! [paint buttons]
comment|//! [paint end]
return|return
name|handled
return|;
block|}
end_function
begin_comment
comment|//! [paint end]
end_comment
end_unit
