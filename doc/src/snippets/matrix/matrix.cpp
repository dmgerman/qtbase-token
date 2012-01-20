begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_class
DECL|class|SimpleTransformation
class|class
name|SimpleTransformation
super|:
specifier|public
name|QWidget
block|{
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [0]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|SimpleTransformation
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
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
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|painter
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|QFont
argument_list|(
literal|"Helvetica"
argument_list|,
literal|24
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|,
literal|"QMatrix"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_class
DECL|class|CombinedTransformation
class|class
name|CombinedTransformation
super|:
specifier|public
name|QWidget
block|{
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [1]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|CombinedTransformation
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
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
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|QMatrix
name|matrix
decl_stmt|;
name|matrix
operator|.
name|translate
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|matrix
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
name|matrix
operator|.
name|scale
argument_list|(
literal|0.5
argument_list|,
literal|1.0
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setMatrix
argument_list|(
name|matrix
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|QFont
argument_list|(
literal|"Helvetica"
argument_list|,
literal|24
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|,
literal|"QMatrix"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [1]
end_comment
begin_class
DECL|class|BasicOperations
class|class
name|BasicOperations
super|:
specifier|public
name|QWidget
block|{
name|void
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_comment
comment|//! [2]
end_comment
begin_function
DECL|function|paintEvent
name|void
name|BasicOperations
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|double
name|pi
init|=
literal|3.14
decl_stmt|;
name|double
name|a
init|=
name|pi
operator|/
literal|180
operator|*
literal|45.0
decl_stmt|;
name|double
name|sina
init|=
name|sin
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|double
name|cosa
init|=
name|cos
argument_list|(
name|a
argument_list|)
decl_stmt|;
name|QMatrix
name|translationMatrix
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|50.0
argument_list|,
literal|50.0
argument_list|)
decl_stmt|;
name|QMatrix
name|rotationMatrix
argument_list|(
name|cosa
argument_list|,
name|sina
argument_list|,
operator|-
name|sina
argument_list|,
name|cosa
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QMatrix
name|scalingMatrix
argument_list|(
literal|0.5
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1.0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QMatrix
name|matrix
decl_stmt|;
name|matrix
operator|=
name|scalingMatrix
operator|*
name|rotationMatrix
operator|*
name|translationMatrix
expr_stmt|;
name|QPainter
name|painter
argument_list|(
name|this
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
name|blue
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|DashLine
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setMatrix
argument_list|(
name|matrix
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|QFont
argument_list|(
literal|"Helvetica"
argument_list|,
literal|24
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|black
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|20
argument_list|,
literal|10
argument_list|,
literal|"QMatrix"
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [2]
end_comment
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
modifier|*
name|argv
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
name|QWidget
name|widget
decl_stmt|;
name|SimpleTransformation
modifier|*
name|simpleWidget
init|=
operator|new
name|SimpleTransformation
decl_stmt|;
name|CombinedTransformation
modifier|*
name|combinedWidget
init|=
operator|new
name|CombinedTransformation
decl_stmt|;
name|BasicOperations
modifier|*
name|basicWidget
init|=
operator|new
name|BasicOperations
decl_stmt|;
name|QVBoxLayout
modifier|*
name|layout
init|=
operator|new
name|QVBoxLayout
decl_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|simpleWidget
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|combinedWidget
argument_list|)
expr_stmt|;
name|layout
operator|->
name|addWidget
argument_list|(
name|basicWidget
argument_list|)
expr_stmt|;
name|widget
operator|.
name|setLayout
argument_list|(
name|layout
argument_list|)
expr_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
name|widget
operator|.
name|resize
argument_list|(
literal|130
argument_list|,
literal|350
argument_list|)
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
