begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|scene
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|scene
operator|.
name|addText
argument_list|(
literal|"Hello, world!"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|scene
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|scene
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|scene
operator|.
name|addRect
argument_list|(
name|QRectF
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|10
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|scene
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|view
operator|.
name|setRenderHints
argument_list|(
name|QPainter
operator|::
name|Antialiasing
operator||
name|QPainter
operator|::
name|SmoothPixmapTransform
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|view
name|QGraphicsView
name|view
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|view
operator|.
name|setBackgroundBrush
argument_list|(
name|QImage
argument_list|(
literal|":/images/backgroundtile.png"
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|view
operator|.
name|setCacheMode
argument_list|(
name|QGraphicsView
operator|::
name|CacheBackground
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|scene
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|scene
operator|.
name|addText
argument_list|(
literal|"GraphicsView rotated clockwise"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|scene
name|QGraphicsView
name|view
argument_list|(
operator|&
name|scene
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|view
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// the text is rendered with a 90 degree clockwise rotation
end_comment
begin_expr_stmt
name|view
operator|.
name|show
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|scene
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_macro
name|scene
end_macro
begin_expr_stmt
operator|.
name|addItem
argument_list|(
argument|... ...  QGraphicsView view(&scene); view.show(); ...  QPrinter printer(QPrinter::HighResolution); printer.setPageSize(QPrinter::A4); QPainter painter(&printer);
comment|// print, fitting the viewport contents into a full page
argument|view.render(&painter);
comment|// print the upper half of the viewport into the lower.
comment|// half of the page.
argument|QRect viewport = view.viewport()->rect(); view.render(&painter,             QRectF(
literal|0
argument|, printer.height() /
literal|2
argument|,                    printer.width(), printer.height() /
literal|2
argument|),             viewport.adjusted(
literal|0
argument|,
literal|0
argument|,
literal|0
argument|, -viewport.height() /
literal|2
argument|));
comment|//! [4]
comment|//! [5]
argument|void CustomView::mousePressEvent(QMouseEvent *event) {     qDebug()<<
literal|"There are"
argument|<< items(event->pos()).size()<<
literal|"items at position"
argument|<< mapToScene(event->pos()); }
comment|//! [5]
comment|//! [6]
argument|void CustomView::mousePressEvent(QMouseEvent *event) {     if (QGraphicsItem *item = itemAt(event->pos())) {         qDebug()<<
literal|"You clicked on item"
argument|<< item;     } else {         qDebug()<<
literal|"You didn't click on an item."
argument|;     } }
comment|//! [6]
comment|//! [7]
argument|QGraphicsScene scene; scene.addText(
literal|"GraphicsView rotated clockwise"
argument|);  QGraphicsView view(&scene); view.rotate(
literal|90
argument|);
comment|// the text is rendered with a 90 degree clockwise rotation
argument|view.show();
end_expr_stmt
begin_comment
comment|//! [7]
end_comment
end_unit
