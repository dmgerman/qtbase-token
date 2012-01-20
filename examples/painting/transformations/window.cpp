begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_comment
comment|//! [0]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|originalRenderArea
operator|=
operator|new
name|RenderArea
expr_stmt|;
name|shapeComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Clock"
argument_list|)
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"House"
argument_list|)
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Text"
argument_list|)
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Truck"
argument_list|)
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|layout
init|=
operator|new
name|QGridLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|originalRenderArea
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|shapeComboBox
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|//! [0]
comment|//! [1]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumTransformedAreas
condition|;
operator|++
name|i
control|)
block|{
name|transformedRenderAreas
index|[
name|i
index|]
operator|=
operator|new
name|RenderArea
expr_stmt|;
name|operationComboBoxes
index|[
name|i
index|]
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|operationComboBoxes
index|[
name|i
index|]
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"No transformation"
argument_list|)
argument_list|)
expr_stmt|;
name|operationComboBoxes
index|[
name|i
index|]
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Rotate by 60\xB0"
argument_list|)
argument_list|)
expr_stmt|;
name|operationComboBoxes
index|[
name|i
index|]
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Scale to 75%"
argument_list|)
argument_list|)
expr_stmt|;
name|operationComboBoxes
index|[
name|i
index|]
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Translate by (50, 50)"
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|operationComboBoxes
index|[
name|i
index|]
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|operationChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|transformedRenderAreas
index|[
name|i
index|]
argument_list|,
literal|0
argument_list|,
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|operationComboBoxes
index|[
name|i
index|]
argument_list|,
literal|1
argument_list|,
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
comment|//! [1]
comment|//! [2]
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|setupShapes
argument_list|()
expr_stmt|;
name|shapeSelected
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Transformations"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_function
DECL|function|setupShapes
name|void
name|Window
operator|::
name|setupShapes
parameter_list|()
block|{
name|QPainterPath
name|truck
decl_stmt|;
comment|//! [3]
name|truck
operator|.
name|setFillRule
argument_list|(
name|Qt
operator|::
name|WindingFill
argument_list|)
expr_stmt|;
name|truck
operator|.
name|moveTo
argument_list|(
literal|0.0
argument_list|,
literal|87.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|0.0
argument_list|,
literal|60.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|10.0
argument_list|,
literal|60.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|35.0
argument_list|,
literal|35.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|100.0
argument_list|,
literal|35.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|100.0
argument_list|,
literal|87.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|0.0
argument_list|,
literal|87.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|moveTo
argument_list|(
literal|17.0
argument_list|,
literal|60.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|55.0
argument_list|,
literal|60.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|55.0
argument_list|,
literal|40.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|37.0
argument_list|,
literal|40.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|lineTo
argument_list|(
literal|17.0
argument_list|,
literal|60.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|addEllipse
argument_list|(
literal|17.0
argument_list|,
literal|75.0
argument_list|,
literal|25.0
argument_list|,
literal|25.0
argument_list|)
expr_stmt|;
name|truck
operator|.
name|addEllipse
argument_list|(
literal|63.0
argument_list|,
literal|75.0
argument_list|,
literal|25.0
argument_list|,
literal|25.0
argument_list|)
expr_stmt|;
comment|//! [4]
name|QPainterPath
name|clock
decl_stmt|;
comment|//! [4]
name|clock
operator|.
name|addEllipse
argument_list|(
operator|-
literal|50.0
argument_list|,
operator|-
literal|50.0
argument_list|,
literal|100.0
argument_list|,
literal|100.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|addEllipse
argument_list|(
operator|-
literal|48.0
argument_list|,
operator|-
literal|48.0
argument_list|,
literal|96.0
argument_list|,
literal|96.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|moveTo
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
operator|-
literal|2.0
argument_list|,
operator|-
literal|2.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|0.0
argument_list|,
operator|-
literal|42.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|2.0
argument_list|,
operator|-
literal|2.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|moveTo
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|2.732
argument_list|,
operator|-
literal|0.732
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|24.495
argument_list|,
literal|14.142
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|0.732
argument_list|,
literal|2.732
argument_list|)
expr_stmt|;
name|clock
operator|.
name|lineTo
argument_list|(
literal|0.0
argument_list|,
literal|0.0
argument_list|)
expr_stmt|;
comment|//! [5]
name|QPainterPath
name|house
decl_stmt|;
comment|//! [5]
name|house
operator|.
name|moveTo
argument_list|(
operator|-
literal|45.0
argument_list|,
operator|-
literal|20.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|lineTo
argument_list|(
literal|0.0
argument_list|,
operator|-
literal|45.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|lineTo
argument_list|(
literal|45.0
argument_list|,
operator|-
literal|20.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|lineTo
argument_list|(
literal|45.0
argument_list|,
literal|45.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|lineTo
argument_list|(
operator|-
literal|45.0
argument_list|,
literal|45.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|lineTo
argument_list|(
operator|-
literal|45.0
argument_list|,
operator|-
literal|20.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|addRect
argument_list|(
literal|15.0
argument_list|,
literal|5.0
argument_list|,
literal|20.0
argument_list|,
literal|35.0
argument_list|)
expr_stmt|;
name|house
operator|.
name|addRect
argument_list|(
operator|-
literal|35.0
argument_list|,
operator|-
literal|15.0
argument_list|,
literal|25.0
argument_list|,
literal|25.0
argument_list|)
expr_stmt|;
comment|//! [6]
name|QPainterPath
name|text
decl_stmt|;
comment|//! [6]
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setPixelSize
argument_list|(
literal|50
argument_list|)
expr_stmt|;
name|QRect
name|fontBoundingRect
init|=
name|QFontMetrics
argument_list|(
name|font
argument_list|)
operator|.
name|boundingRect
argument_list|(
name|tr
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
decl_stmt|;
name|text
operator|.
name|addText
argument_list|(
operator|-
name|QPointF
argument_list|(
name|fontBoundingRect
operator|.
name|center
argument_list|()
argument_list|)
argument_list|,
name|font
argument_list|,
name|tr
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [7]
name|shapes
operator|.
name|append
argument_list|(
name|clock
argument_list|)
expr_stmt|;
name|shapes
operator|.
name|append
argument_list|(
name|house
argument_list|)
expr_stmt|;
name|shapes
operator|.
name|append
argument_list|(
name|text
argument_list|)
expr_stmt|;
name|shapes
operator|.
name|append
argument_list|(
name|truck
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|shapeComboBox
argument_list|,
name|SIGNAL
argument_list|(
name|activated
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|shapeSelected
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|operationChanged
name|void
name|Window
operator|::
name|operationChanged
parameter_list|()
block|{
specifier|static
specifier|const
name|Operation
name|operationTable
index|[]
init|=
block|{
name|NoTransformation
block|,
name|Rotate
block|,
name|Scale
block|,
name|Translate
block|}
decl_stmt|;
name|QList
argument_list|<
name|Operation
argument_list|>
name|operations
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumTransformedAreas
condition|;
operator|++
name|i
control|)
block|{
name|int
name|index
init|=
name|operationComboBoxes
index|[
name|i
index|]
operator|->
name|currentIndex
argument_list|()
decl_stmt|;
name|operations
operator|.
name|append
argument_list|(
name|operationTable
index|[
name|index
index|]
argument_list|)
expr_stmt|;
name|transformedRenderAreas
index|[
name|i
index|]
operator|->
name|setOperations
argument_list|(
name|operations
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_function
DECL|function|shapeSelected
name|void
name|Window
operator|::
name|shapeSelected
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|QPainterPath
name|shape
init|=
name|shapes
index|[
name|index
index|]
decl_stmt|;
name|originalRenderArea
operator|->
name|setShape
argument_list|(
name|shape
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|NumTransformedAreas
condition|;
operator|++
name|i
control|)
name|transformedRenderAreas
index|[
name|i
index|]
operator|->
name|setShape
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
end_unit
