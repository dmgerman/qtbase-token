begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"renderarea.h"
end_include
begin_include
include|#
directive|include
file|"window.h"
end_include
begin_include
include|#
directive|include
file|<QtWidgets>
end_include
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|IdRole
specifier|const
name|int
name|IdRole
init|=
name|Qt
operator|::
name|UserRole
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_constructor
DECL|function|Window
name|Window
operator|::
name|Window
parameter_list|()
block|{
name|renderArea
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
literal|"Polygon"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Polygon
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Rectangle"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Rect
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Rounded Rectangle"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|RoundedRect
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Ellipse"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Ellipse
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Pie"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Pie
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Chord"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Chord
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Path"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Path
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Line"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Line
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Polyline"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Polyline
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Arc"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Arc
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Points"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Points
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
argument_list|,
name|RenderArea
operator|::
name|Text
argument_list|)
expr_stmt|;
name|shapeComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Pixmap"
argument_list|)
argument_list|,
name|RenderArea
operator|::
name|Pixmap
argument_list|)
expr_stmt|;
name|shapeLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Shape:"
argument_list|)
argument_list|)
expr_stmt|;
name|shapeLabel
operator|->
name|setBuddy
argument_list|(
name|shapeComboBox
argument_list|)
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|penWidthSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|penWidthSpinBox
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|penWidthSpinBox
operator|->
name|setSpecialValueText
argument_list|(
name|tr
argument_list|(
literal|"0 (cosmetic pen)"
argument_list|)
argument_list|)
expr_stmt|;
name|penWidthLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Pen&Width:"
argument_list|)
argument_list|)
expr_stmt|;
name|penWidthLabel
operator|->
name|setBuddy
argument_list|(
name|penWidthSpinBox
argument_list|)
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|penStyleComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|penStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Solid"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|SolidLine
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dash"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|DashLine
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dot"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|DotLine
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dash Dot"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|DashDotLine
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dash Dot Dot"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|DashDotDotLine
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|NoPen
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Pen Style:"
argument_list|)
argument_list|)
expr_stmt|;
name|penStyleLabel
operator|->
name|setBuddy
argument_list|(
name|penStyleComboBox
argument_list|)
expr_stmt|;
name|penCapComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|penCapComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Flat"
argument_list|)
argument_list|,
name|Qt
operator|::
name|FlatCap
argument_list|)
expr_stmt|;
name|penCapComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Square"
argument_list|)
argument_list|,
name|Qt
operator|::
name|SquareCap
argument_list|)
expr_stmt|;
name|penCapComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Round"
argument_list|)
argument_list|,
name|Qt
operator|::
name|RoundCap
argument_list|)
expr_stmt|;
name|penCapLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Pen&Cap:"
argument_list|)
argument_list|)
expr_stmt|;
name|penCapLabel
operator|->
name|setBuddy
argument_list|(
name|penCapComboBox
argument_list|)
expr_stmt|;
name|penJoinComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|penJoinComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Miter"
argument_list|)
argument_list|,
name|Qt
operator|::
name|MiterJoin
argument_list|)
expr_stmt|;
name|penJoinComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Bevel"
argument_list|)
argument_list|,
name|Qt
operator|::
name|BevelJoin
argument_list|)
expr_stmt|;
name|penJoinComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Round"
argument_list|)
argument_list|,
name|Qt
operator|::
name|RoundJoin
argument_list|)
expr_stmt|;
name|penJoinLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Pen&Join:"
argument_list|)
argument_list|)
expr_stmt|;
name|penJoinLabel
operator|->
name|setBuddy
argument_list|(
name|penJoinComboBox
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|brushStyleComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Linear Gradient"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|LinearGradientPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Radial Gradient"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|RadialGradientPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Conical Gradient"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|ConicalGradientPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Texture"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|TexturePattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Solid"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|SolidPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Horizontal"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|HorPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Vertical"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|VerPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Cross"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|CrossPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Backward Diagonal"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|BDiagPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Forward Diagonal"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|FDiagPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Diagonal Cross"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|DiagCrossPattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 1"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense1Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 2"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense2Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 3"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense3Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 4"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense4Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 5"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense5Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 6"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense6Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Dense 7"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|Dense7Pattern
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"None"
argument_list|)
argument_list|,
cast|static_cast
argument_list|<
name|int
argument_list|>
argument_list|(
name|Qt
operator|::
name|NoBrush
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Brush:"
argument_list|)
argument_list|)
expr_stmt|;
name|brushStyleLabel
operator|->
name|setBuddy
argument_list|(
name|brushStyleComboBox
argument_list|)
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|otherOptionsLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Options:"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [5] //! [6]
name|antialiasingCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Antialiasing"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [6] //! [7]
name|transformationsCheckBox
operator|=
operator|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"&Transformations"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
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
name|shapeChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|penWidthSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|penChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|penStyleComboBox
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
name|penChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|penCapComboBox
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
name|penChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|penJoinComboBox
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
name|penChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|brushStyleComboBox
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
name|brushChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|antialiasingCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|renderArea
argument_list|,
name|SLOT
argument_list|(
name|setAntialiased
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|transformationsCheckBox
argument_list|,
name|SIGNAL
argument_list|(
name|toggled
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|,
name|renderArea
argument_list|,
name|SLOT
argument_list|(
name|setTransformed
argument_list|(
name|bool
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
comment|//! [9] //! [10]
name|mainLayout
operator|->
name|setColumnStretch
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|setColumnStretch
argument_list|(
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|renderArea
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|shapeLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|shapeComboBox
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penWidthLabel
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penWidthSpinBox
argument_list|,
literal|3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penStyleLabel
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penStyleComboBox
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penCapLabel
argument_list|,
literal|3
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penCapComboBox
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penJoinLabel
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penJoinComboBox
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|brushStyleLabel
argument_list|,
literal|4
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|brushStyleComboBox
argument_list|,
literal|4
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|otherOptionsLabel
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|antialiasingCheckBox
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|transformationsCheckBox
argument_list|,
literal|5
argument_list|,
literal|2
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|,
name|Qt
operator|::
name|AlignRight
argument_list|)
expr_stmt|;
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
name|shapeChanged
argument_list|()
expr_stmt|;
name|penChanged
argument_list|()
expr_stmt|;
name|brushChanged
argument_list|()
expr_stmt|;
name|antialiasingCheckBox
operator|->
name|setChecked
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Basic Drawing"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_function
DECL|function|shapeChanged
name|void
name|Window
operator|::
name|shapeChanged
parameter_list|()
block|{
name|RenderArea
operator|::
name|Shape
name|shape
init|=
name|RenderArea
operator|::
name|Shape
argument_list|(
name|shapeComboBox
operator|->
name|itemData
argument_list|(
name|shapeComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|IdRole
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|renderArea
operator|->
name|setShape
argument_list|(
name|shape
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_function
DECL|function|penChanged
name|void
name|Window
operator|::
name|penChanged
parameter_list|()
block|{
name|int
name|width
init|=
name|penWidthSpinBox
operator|->
name|value
argument_list|()
decl_stmt|;
name|Qt
operator|::
name|PenStyle
name|style
init|=
name|Qt
operator|::
name|PenStyle
argument_list|(
name|penStyleComboBox
operator|->
name|itemData
argument_list|(
name|penStyleComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|IdRole
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|PenCapStyle
name|cap
init|=
name|Qt
operator|::
name|PenCapStyle
argument_list|(
name|penCapComboBox
operator|->
name|itemData
argument_list|(
name|penCapComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|IdRole
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|Qt
operator|::
name|PenJoinStyle
name|join
init|=
name|Qt
operator|::
name|PenJoinStyle
argument_list|(
name|penJoinComboBox
operator|->
name|itemData
argument_list|(
name|penJoinComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|IdRole
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
name|renderArea
operator|->
name|setPen
argument_list|(
name|QPen
argument_list|(
name|Qt
operator|::
name|blue
argument_list|,
name|width
argument_list|,
name|style
argument_list|,
name|cap
argument_list|,
name|join
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_function
DECL|function|brushChanged
name|void
name|Window
operator|::
name|brushChanged
parameter_list|()
block|{
name|Qt
operator|::
name|BrushStyle
name|style
init|=
name|Qt
operator|::
name|BrushStyle
argument_list|(
name|brushStyleComboBox
operator|->
name|itemData
argument_list|(
comment|//! [13]
name|brushStyleComboBox
operator|->
name|currentIndex
argument_list|()
argument_list|,
name|IdRole
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|)
decl_stmt|;
comment|//! [14]
if|if
condition|(
name|style
operator|==
name|Qt
operator|::
name|LinearGradientPattern
condition|)
block|{
name|QLinearGradient
name|linearGradient
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|linearGradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|linearGradient
operator|.
name|setColorAt
argument_list|(
literal|0.2
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|linearGradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|renderArea
operator|->
name|setBrush
argument_list|(
name|linearGradient
argument_list|)
expr_stmt|;
comment|//! [14] //! [15]
block|}
elseif|else
if|if
condition|(
name|style
operator|==
name|Qt
operator|::
name|RadialGradientPattern
condition|)
block|{
name|QRadialGradient
name|radialGradient
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|70
argument_list|,
literal|70
argument_list|)
decl_stmt|;
name|radialGradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|radialGradient
operator|.
name|setColorAt
argument_list|(
literal|0.2
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|radialGradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|renderArea
operator|->
name|setBrush
argument_list|(
name|radialGradient
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|style
operator|==
name|Qt
operator|::
name|ConicalGradientPattern
condition|)
block|{
name|QConicalGradient
name|conicalGradient
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|150
argument_list|)
decl_stmt|;
name|conicalGradient
operator|.
name|setColorAt
argument_list|(
literal|0.0
argument_list|,
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|conicalGradient
operator|.
name|setColorAt
argument_list|(
literal|0.2
argument_list|,
name|Qt
operator|::
name|green
argument_list|)
expr_stmt|;
name|conicalGradient
operator|.
name|setColorAt
argument_list|(
literal|1.0
argument_list|,
name|Qt
operator|::
name|black
argument_list|)
expr_stmt|;
name|renderArea
operator|->
name|setBrush
argument_list|(
name|conicalGradient
argument_list|)
expr_stmt|;
comment|//! [15] //! [16]
block|}
elseif|else
if|if
condition|(
name|style
operator|==
name|Qt
operator|::
name|TexturePattern
condition|)
block|{
name|renderArea
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|QPixmap
argument_list|(
literal|":/images/brick.png"
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [16] //! [17]
block|}
else|else
block|{
name|renderArea
operator|->
name|setBrush
argument_list|(
name|QBrush
argument_list|(
name|Qt
operator|::
name|green
argument_list|,
name|style
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|//! [17]
end_comment
end_unit
