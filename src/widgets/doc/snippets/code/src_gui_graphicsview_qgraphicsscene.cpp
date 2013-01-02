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
begin_macro
name|scene
end_macro
begin_expr_stmt
operator|.
name|addItem
argument_list|(
argument|... ... QPrinter printer(QPrinter::HighResolution); printer.setPaperSize(QPrinter::A4);  QPainter painter(&printer); scene.render(&painter);
comment|//! [1]
comment|//! [2]
argument|QSizeF segmentSize = sceneRect().size() / pow(
literal|2
argument|, depth -
literal|1
argument|);
comment|//! [2]
comment|//! [3]
argument|QGraphicsScene scene; QGraphicsView view(&scene); view.show();
comment|// a blue background
argument|scene.setBackgroundBrush(Qt::blue);
comment|// a gradient background
argument|QRadialGradient gradient(
literal|0
argument|,
literal|0
argument|,
literal|10
argument|); gradient.setSpread(QGradient::RepeatSpread); scene.setBackgroundBrush(gradient);
comment|//! [3]
comment|//! [4]
argument|QGraphicsScene scene; QGraphicsView view(&scene); view.show();
comment|// a white semi-transparent foreground
argument|scene.setForegroundBrush(QColor(
literal|255
argument|,
literal|255
argument|,
literal|255
argument|,
literal|127
argument|));
comment|// a grid foreground
argument|scene.setForegroundBrush(QBrush(Qt::lightGray, Qt::CrossPattern));
comment|//! [4]
comment|//! [5]
argument|QRectF TileScene::rectForTile(int x, int y) const {
comment|// Return the rectangle for the tile at position (x, y).
argument|return QRectF(x * tileWidth, y * tileHeight, tileWidth, tileHeight); }  void TileScene::setTile(int x, int y, const QPixmap&pixmap) {
comment|// Sets or replaces the tile at position (x, y) with pixmap.
argument|if (x>=
literal|0
argument|&& x< numTilesH&& y>=
literal|0
argument|&& y< numTilesV) {         tiles[y][x] = pixmap;         invalidate(rectForTile(x, y), BackgroundLayer);     } }  void TileScene::drawBackground(QPainter *painter, const QRectF&exposed) {
comment|// Draws all tiles that intersect the exposed area.
argument|for (int y =
literal|0
argument|; y< numTilesV; ++y) {         for (int x =
literal|0
argument|; x< numTilesH; ++x) {             QRectF rect = rectForTile(x, y);             if (exposed.intersects(rect))                 painter->drawPixmap(rect.topLeft(), tiles[y][x]);         }     } }
end_expr_stmt
begin_comment
comment|//! [5]
end_comment
end_unit
