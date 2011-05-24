begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the examples of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
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
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|Pi
specifier|const
name|float
name|Pi
init|=
literal|3.14159f
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
name|QPainterPath
name|rectPath
decl_stmt|;
name|rectPath
operator|.
name|moveTo
argument_list|(
literal|20.0
argument_list|,
literal|30.0
argument_list|)
expr_stmt|;
name|rectPath
operator|.
name|lineTo
argument_list|(
literal|80.0
argument_list|,
literal|30.0
argument_list|)
expr_stmt|;
name|rectPath
operator|.
name|lineTo
argument_list|(
literal|80.0
argument_list|,
literal|70.0
argument_list|)
expr_stmt|;
name|rectPath
operator|.
name|lineTo
argument_list|(
literal|20.0
argument_list|,
literal|70.0
argument_list|)
expr_stmt|;
name|rectPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
comment|//! [1]
comment|//! [2]
name|QPainterPath
name|roundRectPath
decl_stmt|;
name|roundRectPath
operator|.
name|moveTo
argument_list|(
literal|80.0
argument_list|,
literal|35.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|arcTo
argument_list|(
literal|70.0
argument_list|,
literal|30.0
argument_list|,
literal|10.0
argument_list|,
literal|10.0
argument_list|,
literal|0.0
argument_list|,
literal|90.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|lineTo
argument_list|(
literal|25.0
argument_list|,
literal|30.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|arcTo
argument_list|(
literal|20.0
argument_list|,
literal|30.0
argument_list|,
literal|10.0
argument_list|,
literal|10.0
argument_list|,
literal|90.0
argument_list|,
literal|90.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|lineTo
argument_list|(
literal|20.0
argument_list|,
literal|65.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|arcTo
argument_list|(
literal|20.0
argument_list|,
literal|60.0
argument_list|,
literal|10.0
argument_list|,
literal|10.0
argument_list|,
literal|180.0
argument_list|,
literal|90.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|lineTo
argument_list|(
literal|75.0
argument_list|,
literal|70.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|arcTo
argument_list|(
literal|70.0
argument_list|,
literal|60.0
argument_list|,
literal|10.0
argument_list|,
literal|10.0
argument_list|,
literal|270.0
argument_list|,
literal|90.0
argument_list|)
expr_stmt|;
name|roundRectPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
comment|//! [2]
comment|//! [3]
name|QPainterPath
name|ellipsePath
decl_stmt|;
name|ellipsePath
operator|.
name|moveTo
argument_list|(
literal|80.0
argument_list|,
literal|50.0
argument_list|)
expr_stmt|;
name|ellipsePath
operator|.
name|arcTo
argument_list|(
literal|20.0
argument_list|,
literal|30.0
argument_list|,
literal|60.0
argument_list|,
literal|40.0
argument_list|,
literal|0.0
argument_list|,
literal|360.0
argument_list|)
expr_stmt|;
comment|//! [3]
comment|//! [4]
name|QPainterPath
name|piePath
decl_stmt|;
name|piePath
operator|.
name|moveTo
argument_list|(
literal|50.0
argument_list|,
literal|50.0
argument_list|)
expr_stmt|;
name|piePath
operator|.
name|arcTo
argument_list|(
literal|20.0
argument_list|,
literal|30.0
argument_list|,
literal|60.0
argument_list|,
literal|40.0
argument_list|,
literal|60.0
argument_list|,
literal|240.0
argument_list|)
expr_stmt|;
name|piePath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
comment|//! [4]
comment|//! [5]
name|QPainterPath
name|polygonPath
decl_stmt|;
name|polygonPath
operator|.
name|moveTo
argument_list|(
literal|10.0
argument_list|,
literal|80.0
argument_list|)
expr_stmt|;
name|polygonPath
operator|.
name|lineTo
argument_list|(
literal|20.0
argument_list|,
literal|10.0
argument_list|)
expr_stmt|;
name|polygonPath
operator|.
name|lineTo
argument_list|(
literal|80.0
argument_list|,
literal|30.0
argument_list|)
expr_stmt|;
name|polygonPath
operator|.
name|lineTo
argument_list|(
literal|90.0
argument_list|,
literal|70.0
argument_list|)
expr_stmt|;
name|polygonPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
comment|//! [5]
comment|//! [6]
name|QPainterPath
name|groupPath
decl_stmt|;
name|groupPath
operator|.
name|moveTo
argument_list|(
literal|60.0
argument_list|,
literal|40.0
argument_list|)
expr_stmt|;
name|groupPath
operator|.
name|arcTo
argument_list|(
literal|20.0
argument_list|,
literal|20.0
argument_list|,
literal|40.0
argument_list|,
literal|40.0
argument_list|,
literal|0.0
argument_list|,
literal|360.0
argument_list|)
expr_stmt|;
name|groupPath
operator|.
name|moveTo
argument_list|(
literal|40.0
argument_list|,
literal|40.0
argument_list|)
expr_stmt|;
name|groupPath
operator|.
name|lineTo
argument_list|(
literal|40.0
argument_list|,
literal|80.0
argument_list|)
expr_stmt|;
name|groupPath
operator|.
name|lineTo
argument_list|(
literal|80.0
argument_list|,
literal|80.0
argument_list|)
expr_stmt|;
name|groupPath
operator|.
name|lineTo
argument_list|(
literal|80.0
argument_list|,
literal|40.0
argument_list|)
expr_stmt|;
name|groupPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
comment|//! [6]
comment|//! [7]
name|QPainterPath
name|textPath
decl_stmt|;
name|QFont
name|timesFont
argument_list|(
literal|"Times"
argument_list|,
literal|50
argument_list|)
decl_stmt|;
name|timesFont
operator|.
name|setStyleStrategy
argument_list|(
name|QFont
operator|::
name|ForceOutline
argument_list|)
expr_stmt|;
name|textPath
operator|.
name|addText
argument_list|(
literal|10
argument_list|,
literal|70
argument_list|,
name|timesFont
argument_list|,
name|tr
argument_list|(
literal|"Qt"
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [7]
comment|//! [8]
name|QPainterPath
name|bezierPath
decl_stmt|;
name|bezierPath
operator|.
name|moveTo
argument_list|(
literal|20
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|bezierPath
operator|.
name|cubicTo
argument_list|(
literal|80
argument_list|,
literal|0
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|80
argument_list|,
literal|80
argument_list|)
expr_stmt|;
comment|//! [8]
comment|//! [9]
name|QPainterPath
name|starPath
decl_stmt|;
name|starPath
operator|.
name|moveTo
argument_list|(
literal|90
argument_list|,
literal|50
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
literal|5
condition|;
operator|++
name|i
control|)
block|{
name|starPath
operator|.
name|lineTo
argument_list|(
literal|50
operator|+
literal|40
operator|*
name|cos
argument_list|(
literal|0.8
operator|*
name|i
operator|*
name|Pi
argument_list|)
argument_list|,
literal|50
operator|+
literal|40
operator|*
name|sin
argument_list|(
literal|0.8
operator|*
name|i
operator|*
name|Pi
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|starPath
operator|.
name|closeSubpath
argument_list|()
expr_stmt|;
comment|//! [9]
comment|//! [10]
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|rectPath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|roundRectPath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|ellipsePath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|piePath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|polygonPath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|groupPath
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|textPath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|bezierPath
argument_list|)
argument_list|)
expr_stmt|;
name|renderAreas
operator|.
name|push_back
argument_list|(
operator|new
name|RenderArea
argument_list|(
name|starPath
argument_list|)
argument_list|)
expr_stmt|;
comment|//! [10]
comment|//! [11]
name|fillRuleComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|fillRuleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Odd Even"
argument_list|)
argument_list|,
name|Qt
operator|::
name|OddEvenFill
argument_list|)
expr_stmt|;
name|fillRuleComboBox
operator|->
name|addItem
argument_list|(
name|tr
argument_list|(
literal|"Winding"
argument_list|)
argument_list|,
name|Qt
operator|::
name|WindingFill
argument_list|)
expr_stmt|;
name|fillRuleLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Fill&Rule:"
argument_list|)
argument_list|)
expr_stmt|;
name|fillRuleLabel
operator|->
name|setBuddy
argument_list|(
name|fillRuleComboBox
argument_list|)
expr_stmt|;
comment|//! [11]
comment|//! [12]
name|fillColor1ComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|populateWithColors
argument_list|(
name|fillColor1ComboBox
argument_list|)
expr_stmt|;
name|fillColor1ComboBox
operator|->
name|setCurrentIndex
argument_list|(
name|fillColor1ComboBox
operator|->
name|findText
argument_list|(
literal|"mediumslateblue"
argument_list|)
argument_list|)
expr_stmt|;
name|fillColor2ComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|populateWithColors
argument_list|(
name|fillColor2ComboBox
argument_list|)
expr_stmt|;
name|fillColor2ComboBox
operator|->
name|setCurrentIndex
argument_list|(
name|fillColor2ComboBox
operator|->
name|findText
argument_list|(
literal|"cornsilk"
argument_list|)
argument_list|)
expr_stmt|;
name|fillGradientLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Fill Gradient:"
argument_list|)
argument_list|)
expr_stmt|;
name|fillGradientLabel
operator|->
name|setBuddy
argument_list|(
name|fillColor1ComboBox
argument_list|)
expr_stmt|;
name|fillToLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"to"
argument_list|)
argument_list|)
expr_stmt|;
name|fillToLabel
operator|->
name|setSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|)
expr_stmt|;
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
name|penWidthLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Pen Width:"
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
name|penColorComboBox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|populateWithColors
argument_list|(
name|penColorComboBox
argument_list|)
expr_stmt|;
name|penColorComboBox
operator|->
name|setCurrentIndex
argument_list|(
name|penColorComboBox
operator|->
name|findText
argument_list|(
literal|"darkslateblue"
argument_list|)
argument_list|)
expr_stmt|;
name|penColorLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Pen&Color:"
argument_list|)
argument_list|)
expr_stmt|;
name|penColorLabel
operator|->
name|setBuddy
argument_list|(
name|penColorComboBox
argument_list|)
expr_stmt|;
name|rotationAngleSpinBox
operator|=
operator|new
name|QSpinBox
expr_stmt|;
name|rotationAngleSpinBox
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|359
argument_list|)
expr_stmt|;
name|rotationAngleSpinBox
operator|->
name|setWrapping
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|rotationAngleSpinBox
operator|->
name|setSuffix
argument_list|(
literal|"\xB0"
argument_list|)
expr_stmt|;
name|rotationAngleLabel
operator|=
operator|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"&Rotation Angle:"
argument_list|)
argument_list|)
expr_stmt|;
name|rotationAngleLabel
operator|->
name|setBuddy
argument_list|(
name|rotationAngleSpinBox
argument_list|)
expr_stmt|;
comment|//! [12]
comment|//! [16]
name|connect
argument_list|(
name|fillRuleComboBox
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
name|fillRuleChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fillColor1ComboBox
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
name|fillGradientChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|fillColor2ComboBox
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
name|fillGradientChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|penColorComboBox
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
name|penColorChanged
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|QList
argument_list|<
name|RenderArea
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|renderAreas
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|renderAreas
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
block|{
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
operator|*
name|it
argument_list|,
name|SLOT
argument_list|(
name|setPenWidth
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|connect
argument_list|(
name|rotationAngleSpinBox
argument_list|,
name|SIGNAL
argument_list|(
name|valueChanged
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|,
operator|*
name|it
argument_list|,
name|SLOT
argument_list|(
name|setRotationAngle
argument_list|(
name|int
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|//! [16] //! [17]
name|QGridLayout
modifier|*
name|topLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|topLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetNoConstraint
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|RenderArea
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|renderAreas
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|renderAreas
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
operator|,
name|i
operator|++
control|)
name|topLayout
operator|->
name|addWidget
argument_list|(
operator|*
name|it
argument_list|,
name|i
operator|/
literal|3
argument_list|,
name|i
operator|%
literal|3
argument_list|)
expr_stmt|;
name|QGridLayout
modifier|*
name|mainLayout
init|=
operator|new
name|QGridLayout
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|mainLayout
operator|->
name|setSizeConstraint
argument_list|(
name|QLayout
operator|::
name|SetNoConstraint
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mainLayout
operator|->
name|addLayout
argument_list|(
name|topLayout
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
name|fillRuleLabel
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fillRuleComboBox
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fillGradientLabel
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fillColor1ComboBox
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
name|fillToLabel
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|fillColor2ComboBox
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
name|penWidthLabel
argument_list|,
literal|3
argument_list|,
literal|0
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
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penColorLabel
argument_list|,
literal|4
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|penColorComboBox
argument_list|,
literal|4
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_MAEMO_5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_WS_SIMULATOR
argument_list|)
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|rotationAngleLabel
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mainLayout
operator|->
name|addWidget
argument_list|(
name|rotationAngleSpinBox
argument_list|,
literal|5
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|3
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|setLayout
argument_list|(
name|mainLayout
argument_list|)
expr_stmt|;
comment|//! [17]
comment|//! [18]
name|fillRuleChanged
argument_list|()
expr_stmt|;
name|fillGradientChanged
argument_list|()
expr_stmt|;
name|penColorChanged
argument_list|()
expr_stmt|;
name|penWidthSpinBox
operator|->
name|setValue
argument_list|(
literal|2
argument_list|)
expr_stmt|;
name|setWindowTitle
argument_list|(
name|tr
argument_list|(
literal|"Painter Paths"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_function
DECL|function|fillRuleChanged
name|void
name|Window
operator|::
name|fillRuleChanged
parameter_list|()
block|{
name|Qt
operator|::
name|FillRule
name|rule
init|=
operator|(
name|Qt
operator|::
name|FillRule
operator|)
name|currentItemData
argument_list|(
name|fillRuleComboBox
argument_list|)
operator|.
name|toInt
argument_list|()
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|RenderArea
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|renderAreas
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|renderAreas
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
operator|(
operator|*
name|it
operator|)
operator|->
name|setFillRule
argument_list|(
name|rule
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_function
DECL|function|fillGradientChanged
name|void
name|Window
operator|::
name|fillGradientChanged
parameter_list|()
block|{
name|QColor
name|color1
init|=
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|currentItemData
argument_list|(
name|fillColor1ComboBox
argument_list|)
argument_list|)
decl_stmt|;
name|QColor
name|color2
init|=
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|currentItemData
argument_list|(
name|fillColor2ComboBox
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|RenderArea
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|renderAreas
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|renderAreas
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
operator|(
operator|*
name|it
operator|)
operator|->
name|setFillGradient
argument_list|(
name|color1
argument_list|,
name|color2
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_function
DECL|function|penColorChanged
name|void
name|Window
operator|::
name|penColorChanged
parameter_list|()
block|{
name|QColor
name|color
init|=
name|qvariant_cast
argument_list|<
name|QColor
argument_list|>
argument_list|(
name|currentItemData
argument_list|(
name|penColorComboBox
argument_list|)
argument_list|)
decl_stmt|;
for|for
control|(
name|QList
argument_list|<
name|RenderArea
operator|*
argument_list|>
operator|::
name|iterator
name|it
init|=
name|renderAreas
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|renderAreas
operator|.
name|end
argument_list|()
condition|;
name|it
operator|++
control|)
operator|(
operator|*
name|it
operator|)
operator|->
name|setPenColor
argument_list|(
name|color
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_function
DECL|function|populateWithColors
name|void
name|Window
operator|::
name|populateWithColors
parameter_list|(
name|QComboBox
modifier|*
name|comboBox
parameter_list|)
block|{
name|QStringList
name|colorNames
init|=
name|QColor
operator|::
name|colorNames
argument_list|()
decl_stmt|;
foreach|foreach
control|(
name|QString
name|name
decl|,
name|colorNames
control|)
name|comboBox
operator|->
name|addItem
argument_list|(
name|name
argument_list|,
name|QColor
argument_list|(
name|name
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_function
DECL|function|currentItemData
name|QVariant
name|Window
operator|::
name|currentItemData
parameter_list|(
name|QComboBox
modifier|*
name|comboBox
parameter_list|)
block|{
return|return
name|comboBox
operator|->
name|itemData
argument_list|(
name|comboBox
operator|->
name|currentIndex
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [23]
end_comment
end_unit
