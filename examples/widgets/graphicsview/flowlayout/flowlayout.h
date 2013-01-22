begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QGraphicsLayout>
end_include
begin_decl_stmt
name|class
name|FlowLayout
range|:
name|public
name|QGraphicsLayout
block|{
name|public
operator|:
name|FlowLayout
argument_list|()
block|;
specifier|inline
name|void
name|addItem
argument_list|(
name|QGraphicsLayoutItem
operator|*
name|item
argument_list|)
block|;
name|void
name|insertItem
argument_list|(
argument|int index
argument_list|,
argument|QGraphicsLayoutItem *item
argument_list|)
block|;
name|void
name|setSpacing
argument_list|(
argument|Qt::Orientations o
argument_list|,
argument|qreal spacing
argument_list|)
block|;
name|qreal
name|spacing
argument_list|(
argument|Qt::Orientation o
argument_list|)
specifier|const
block|;
comment|// inherited functions
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRectF
operator|&
name|geom
argument_list|)
block|;
name|int
name|count
argument_list|()
specifier|const
block|;
name|QGraphicsLayoutItem
operator|*
name|itemAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|;
name|void
name|removeAt
argument_list|(
argument|int index
argument_list|)
block|;
name|protected
operator|:
name|QSizeF
name|sizeHint
argument_list|(
argument|Qt::SizeHint which
argument_list|,
argument|const QSizeF&constraint = QSizeF()
argument_list|)
specifier|const
block|;
name|private
operator|:
name|qreal
name|doLayout
argument_list|(
argument|const QRectF&geom
argument_list|,
argument|bool applyNewGeometry
argument_list|)
specifier|const
block|;
name|QSizeF
name|minSize
argument_list|(
argument|const QSizeF&constraint
argument_list|)
specifier|const
block|;
name|QSizeF
name|prefSize
argument_list|()
specifier|const
block|;
name|QSizeF
name|maxSize
argument_list|()
specifier|const
block|;
name|QList
operator|<
name|QGraphicsLayoutItem
operator|*
operator|>
name|m_items
block|;
name|qreal
name|m_spacing
index|[
literal|2
index|]
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|function|addItem
specifier|inline
name|void
name|FlowLayout
operator|::
name|addItem
argument_list|(
argument|QGraphicsLayoutItem *item
argument_list|)
block|{
name|insertItem
argument_list|(
operator|-
literal|1
argument_list|,
name|item
argument_list|)
block|; }
end_expr_stmt
end_unit
