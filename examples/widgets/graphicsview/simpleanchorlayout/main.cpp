begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_class
DECL|class|Widget
class|class
name|Widget
super|:
specifier|public
name|QGraphicsWidget
block|{
public|public:
DECL|function|Widget
name|Widget
parameter_list|(
specifier|const
name|QColor
modifier|&
name|color
parameter_list|,
specifier|const
name|QColor
modifier|&
name|textColor
parameter_list|,
specifier|const
name|QString
modifier|&
name|caption
parameter_list|,
name|QGraphicsItem
modifier|*
name|parent
init|=
literal|0
parameter_list|)
member_init_list|:
name|QGraphicsWidget
argument_list|(
name|parent
argument_list|)
member_init_list|,
name|caption
argument_list|(
name|caption
argument_list|)
member_init_list|,
name|color
argument_list|(
name|color
argument_list|)
member_init_list|,
name|textColor
argument_list|(
name|textColor
argument_list|)
block|{     }
name|void
name|paint
parameter_list|(
name|QPainter
modifier|*
name|painter
parameter_list|,
specifier|const
name|QStyleOptionGraphicsItem
modifier|*
parameter_list|,
name|QWidget
modifier|*
init|=
literal|0
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
literal|0.75
operator|*
name|qMin
argument_list|(
name|boundingRect
argument_list|()
operator|.
name|width
argument_list|()
argument_list|,
name|boundingRect
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|->
name|fillRect
argument_list|(
name|boundingRect
argument_list|()
argument_list|,
name|color
argument_list|)
expr_stmt|;
name|painter
operator|->
name|save
argument_list|()
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
name|setPen
argument_list|(
name|textColor
argument_list|)
expr_stmt|;
name|painter
operator|->
name|drawText
argument_list|(
name|boundingRect
argument_list|()
argument_list|,
name|Qt
operator|::
name|AlignCenter
argument_list|,
name|caption
argument_list|)
expr_stmt|;
name|painter
operator|->
name|restore
argument_list|()
expr_stmt|;
block|}
private|private:
DECL|member|caption
name|QString
name|caption
decl_stmt|;
DECL|member|color
name|QColor
name|color
decl_stmt|;
DECL|member|textColor
name|QColor
name|textColor
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|QGraphicsScene
modifier|*
name|scene
init|=
operator|new
name|QGraphicsScene
argument_list|()
decl_stmt|;
name|Widget
modifier|*
name|a
init|=
operator|new
name|Widget
argument_list|(
name|Qt
operator|::
name|blue
argument_list|,
name|Qt
operator|::
name|white
argument_list|,
literal|"a"
argument_list|)
decl_stmt|;
name|a
operator|->
name|setPreferredSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|Widget
modifier|*
name|b
init|=
operator|new
name|Widget
argument_list|(
name|Qt
operator|::
name|green
argument_list|,
name|Qt
operator|::
name|black
argument_list|,
literal|"b"
argument_list|)
decl_stmt|;
name|b
operator|->
name|setPreferredSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|Widget
modifier|*
name|c
init|=
operator|new
name|Widget
argument_list|(
name|Qt
operator|::
name|red
argument_list|,
name|Qt
operator|::
name|black
argument_list|,
literal|"c"
argument_list|)
decl_stmt|;
name|c
operator|->
name|setPreferredSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QGraphicsAnchorLayout
modifier|*
name|layout
init|=
operator|new
name|QGraphicsAnchorLayout
argument_list|()
decl_stmt|;
comment|/*     //! [adding a corner anchor in two steps]     layout->addAnchor(a, Qt::AnchorTop, layout, Qt::AnchorTop);     layout->addAnchor(a, Qt::AnchorLeft, layout, Qt::AnchorLeft);     //! [adding a corner anchor in two steps] */
comment|//! [adding a corner anchor]
name|layout
operator|->
name|addCornerAnchors
argument_list|(
name|a
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|,
name|layout
argument_list|,
name|Qt
operator|::
name|TopLeftCorner
argument_list|)
expr_stmt|;
comment|//! [adding a corner anchor]
comment|//! [adding anchors]
name|layout
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
name|a
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|)
expr_stmt|;
comment|//! [adding anchors]
comment|// Place a third widget below the second.
name|layout
operator|->
name|addAnchor
argument_list|(
name|b
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|)
expr_stmt|;
comment|/*     //! [adding anchors to match sizes in two steps]     layout->addAnchor(b, Qt::AnchorLeft, c, Qt::AnchorLeft);     layout->addAnchor(b, Qt::AnchorRight, c, Qt::AnchorRight);     //! [adding anchors to match sizes in two steps] */
comment|//! [adding anchors to match sizes]
name|layout
operator|->
name|addAnchors
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
name|Qt
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
comment|//! [adding anchors to match sizes]
comment|// Anchor the bottom-right corner of the third widget to the bottom-right
comment|// corner of the layout.
name|layout
operator|->
name|addCornerAnchors
argument_list|(
name|c
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|,
name|layout
argument_list|,
name|Qt
operator|::
name|BottomRightCorner
argument_list|)
expr_stmt|;
name|QGraphicsWidget
modifier|*
name|w
init|=
operator|new
name|QGraphicsWidget
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Window
operator||
name|Qt
operator|::
name|CustomizeWindowHint
operator||
name|Qt
operator|::
name|WindowTitleHint
argument_list|)
decl_stmt|;
name|w
operator|->
name|setPos
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|w
operator|->
name|setMinimumSize
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|w
operator|->
name|setPreferredSize
argument_list|(
literal|320
argument_list|,
literal|240
argument_list|)
expr_stmt|;
name|w
operator|->
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|w
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"simpleanchorlayout"
argument_list|,
literal|"QGraphicsAnchorLayout in use"
argument_list|)
argument_list|)
expr_stmt|;
name|scene
operator|->
name|addItem
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|QGraphicsView
modifier|*
name|view
init|=
operator|new
name|QGraphicsView
argument_list|()
decl_stmt|;
name|view
operator|->
name|setScene
argument_list|(
name|scene
argument_list|)
expr_stmt|;
name|view
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"simpleanchorlayout"
argument_list|,
literal|"Simple Anchor Layout"
argument_list|)
argument_list|)
expr_stmt|;
name|view
operator|->
name|resize
argument_list|(
literal|360
argument_list|,
literal|320
argument_list|)
expr_stmt|;
name|view
operator|->
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
