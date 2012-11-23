begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"splashitem.h"
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|SplashItem
name|SplashItem
operator|::
name|SplashItem
parameter_list|(
name|QGraphicsItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsObject
argument_list|(
name|parent
argument_list|)
block|{
name|text
operator|=
name|tr
argument_list|(
literal|"Welcome to the Pad Navigator Example. You can use the"
literal|" keyboard arrows to navigate the icons, and press enter"
literal|" to activate an item. Press any key to begin."
argument_list|)
expr_stmt|;
name|setCacheMode
argument_list|(
name|DeviceCoordinateCache
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
DECL|function|boundingRect
name|QRectF
name|SplashItem
operator|::
name|boundingRect
parameter_list|()
specifier|const
block|{
return|return
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|400
argument_list|,
literal|175
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|paint
name|void
name|SplashItem
operator|::
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
name|option
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|2
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setBrush
argument_list|(
name|QColor
argument_list|(
literal|245
argument_list|,
literal|245
argument_list|,
literal|255
argument_list|,
literal|220
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setClipRect
argument_list|(
name|boundingRect
argument_list|()
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawRoundRect
argument_list|(
literal|3
argument_list|,
operator|-
literal|100
operator|+
literal|3
argument_list|,
literal|400
operator|-
literal|6
argument_list|,
literal|250
operator|-
literal|6
argument_list|)
expr_stmt|;
name|QRectF
name|textRect
init|=
name|boundingRect
argument_list|()
operator|.
name|adjusted
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|)
decl_stmt|;
name|int
name|flags
init|=
name|Qt
operator|::
name|AlignTop
operator||
name|Qt
operator|::
name|AlignLeft
operator||
name|Qt
operator|::
name|TextWordWrap
decl_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
literal|18
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|painter
operator|->
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|textRect
argument_list|,
name|flags
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
end_unit
