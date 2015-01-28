begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|WINDOW_H
end_ifndef
begin_define
DECL|macro|WINDOW_H
define|#
directive|define
name|WINDOW_H
end_define
begin_include
include|#
directive|include
file|<QGraphicsScene>
end_include
begin_include
include|#
directive|include
file|<QGraphicsWidget>
end_include
begin_include
include|#
directive|include
file|<QGraphicsLinearLayout>
end_include
begin_include
include|#
directive|include
file|<QGraphicsView>
end_include
begin_include
include|#
directive|include
file|<QSpinBox>
end_include
begin_include
include|#
directive|include
file|<QCheckBox>
end_include
begin_include
include|#
directive|include
file|<QPushButton>
end_include
begin_include
include|#
directive|include
file|<QLabel>
end_include
begin_include
include|#
directive|include
file|<QHBoxLayout>
end_include
begin_include
include|#
directive|include
file|<QPainter>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<QThread>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QTime>
end_include
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_struct
DECL|struct|Statistics
struct|struct
name|Statistics
block|{
DECL|function|Statistics
name|Statistics
argument_list|()
operator|:
name|setGeometryCount
argument_list|(
literal|0
argument_list|)
operator|,
name|sleepMsecs
argument_list|(
literal|0
argument_list|)
operator|,
name|output
argument_list|(
literal|0
argument_list|)
operator|,
name|currentBenchmarkIteration
argument_list|(
literal|0
argument_list|)
operator|,
name|relayoutClicked
argument_list|(
argument|false
argument_list|)
block|{     }
DECL|member|QGraphicsWidget
DECL|member|setGeometryTracker
name|QMap
operator|<
name|QGraphicsWidget
operator|*
operator|,
name|int
operator|>
name|setGeometryTracker
expr_stmt|;
DECL|member|time
name|QTime
name|time
decl_stmt|;
DECL|member|setGeometryCount
name|int
name|setGeometryCount
decl_stmt|;
DECL|member|sleepMsecs
name|int
name|sleepMsecs
decl_stmt|;
DECL|member|output
name|QLabel
modifier|*
name|output
decl_stmt|;
DECL|function|sleep
name|void
name|sleep
parameter_list|()
block|{
if|#
directive|if
name|QT_VERSION
operator|>=
literal|0x050000
name|QThread
operator|::
name|msleep
argument_list|(
name|sleepMsecs
argument_list|)
expr_stmt|;
else|#
directive|else
name|qWarning
argument_list|(
literal|"%s unimplemented"
argument_list|,
name|Q_FUNC_INFO
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
DECL|member|currentBenchmarkIteration
name|int
name|currentBenchmarkIteration
decl_stmt|;
DECL|member|relayoutClicked
name|bool
name|relayoutClicked
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
DECL|variable|Window
name|class
name|Window
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|SlowWidget
range|:
name|public
name|QGraphicsWidget
block|{
name|public
operator|:
name|SlowWidget
argument_list|(
argument|QGraphicsWidget *w =
literal|0
argument_list|,
argument|Qt::WindowFlags wFlags =
literal|0
argument_list|)
operator|:
name|QGraphicsWidget
argument_list|(
argument|w
argument_list|,
argument|wFlags
argument_list|)
block|{
name|m_window
operator|=
literal|0
block|;     }
name|void
name|setStats
argument_list|(
argument|Statistics *stats
argument_list|)
block|{
name|m_stats
operator|=
name|stats
block|;     }
name|void
name|setWindow
argument_list|(
argument|Window *window
argument_list|)
block|{
name|m_window
operator|=
name|window
block|;     }
name|void
name|setGeometry
argument_list|(
specifier|const
name|QRectF
operator|&
name|rect
argument_list|)
block|;
name|bool
name|event
argument_list|(
argument|QEvent *e
argument_list|)
block|{
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|LayoutRequest
condition|)
block|{
if|if
condition|(
name|m_stats
operator|->
name|sleepMsecs
operator|>
literal|0
condition|)
block|{
name|m_stats
operator|->
name|sleep
argument_list|()
expr_stmt|;
name|qDebug
argument_list|(
literal|"sleep %d ms\n"
argument_list|,
name|m_stats
operator|->
name|sleepMsecs
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|QGraphicsWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
name|void
name|paint
argument_list|(
argument|QPainter *painter
argument_list|,
argument|const QStyleOptionGraphicsItem *option
argument_list|,
argument|QWidget *widget
argument_list|)
block|{
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
block|;
name|Q_UNUSED
argument_list|(
name|widget
argument_list|)
block|;
name|painter
operator|->
name|setBrush
argument_list|(
name|m_brush
argument_list|)
block|;
name|painter
operator|->
name|drawRoundRect
argument_list|(
name|rect
argument_list|()
argument_list|)
block|;
name|painter
operator|->
name|drawLine
argument_list|(
name|rect
argument_list|()
operator|.
name|topLeft
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|bottomRight
argument_list|()
argument_list|)
block|;
name|painter
operator|->
name|drawLine
argument_list|(
name|rect
argument_list|()
operator|.
name|bottomLeft
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|topRight
argument_list|()
argument_list|)
block|;     }
name|void
name|setBrush
argument_list|(
argument|const QBrush&brush
argument_list|)
block|{
name|m_brush
operator|=
name|brush
block|;     }
name|private
operator|:
name|QBrush
name|m_brush
block|;
name|Statistics
operator|*
name|m_stats
block|;
name|Window
operator|*
name|m_window
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Window
range|:
name|public
name|QWidget
block|{
name|Q_OBJECT
name|public
operator|:
name|Window
argument_list|()
operator|:
name|QWidget
argument_list|()
block|{
name|QGraphicsView
operator|*
name|m_view
operator|=
name|new
name|QGraphicsView
argument_list|(
operator|&
name|scene
argument_list|)
block|;
name|m_window
operator|=
literal|0
block|;
name|m_leaf
operator|=
literal|0
block|;
name|m_button
operator|=
name|new
name|QPushButton
argument_list|(
name|tr
argument_list|(
literal|"Relayout"
argument_list|)
argument_list|)
block|;
name|m_button
operator|->
name|setObjectName
argument_list|(
literal|"button"
argument_list|)
block|;
name|m_sleepLabel
operator|=
name|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Sleep:"
argument_list|)
argument_list|)
block|;
name|m_sleepSpinBox
operator|=
name|new
name|QSpinBox
block|;
name|m_sleepSpinBox
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
literal|1000
argument_list|)
block|;
name|m_sleepSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|10
argument_list|)
block|;
name|m_depthLabel
operator|=
name|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Depth:"
argument_list|)
argument_list|)
block|;
name|m_depthSpinBox
operator|=
name|new
name|QSpinBox
block|;
name|m_depthSpinBox
operator|->
name|setObjectName
argument_list|(
literal|"depthSpinBox"
argument_list|)
block|;
name|m_depthSpinBox
operator|->
name|setRange
argument_list|(
literal|1
argument_list|,
literal|200
argument_list|)
block|;
name|m_depthSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|5
argument_list|)
block|;
name|m_benchmarkIterationsLabel
operator|=
name|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Benchmark iterations"
argument_list|)
argument_list|)
block|;
name|m_benchmarkIterationsSpinBox
operator|=
name|new
name|QSpinBox
block|;
name|m_benchmarkIterationsSpinBox
operator|->
name|setObjectName
argument_list|(
literal|"benchmarkIterationsSpinBox"
argument_list|)
block|;
name|m_benchmarkIterationsSpinBox
operator|->
name|setRange
argument_list|(
literal|1
argument_list|,
literal|1000
argument_list|)
block|;
name|m_benchmarkIterationsSpinBox
operator|->
name|setValue
argument_list|(
literal|41
argument_list|)
block|;
name|m_benchmarkIterationsSpinBox
operator|->
name|setSingleStep
argument_list|(
literal|10
argument_list|)
block|;
name|m_instantCheckBox
operator|=
name|new
name|QCheckBox
argument_list|(
name|tr
argument_list|(
literal|"Instant propagation"
argument_list|)
argument_list|)
block|;
name|m_instantCheckBox
operator|->
name|setObjectName
argument_list|(
literal|"instantPropagationCheckbox"
argument_list|)
block|;
name|QGraphicsLayout
operator|::
name|setInstantInvalidatePropagation
argument_list|(
name|true
argument_list|)
block|;
name|m_instantCheckBox
operator|->
name|setChecked
argument_list|(
name|QGraphicsLayout
operator|::
name|instantInvalidatePropagation
argument_list|()
argument_list|)
block|;
name|m_resultLabel
operator|=
name|new
name|QLabel
argument_list|(
name|tr
argument_list|(
literal|"Press relayout to start test"
argument_list|)
argument_list|)
block|;
name|QHBoxLayout
operator|*
name|hbox
operator|=
name|new
name|QHBoxLayout
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_sleepLabel
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_sleepSpinBox
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_depthLabel
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_depthSpinBox
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_benchmarkIterationsLabel
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_benchmarkIterationsSpinBox
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_instantCheckBox
argument_list|)
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_resultLabel
argument_list|)
block|;
name|hbox
operator|->
name|addStretch
argument_list|()
block|;
name|hbox
operator|->
name|addWidget
argument_list|(
name|m_button
argument_list|)
block|;
name|QVBoxLayout
operator|*
name|vbox
operator|=
name|new
name|QVBoxLayout
block|;
name|vbox
operator|->
name|addWidget
argument_list|(
name|m_view
argument_list|)
block|;
name|vbox
operator|->
name|addLayout
argument_list|(
name|hbox
argument_list|)
block|;
name|setLayout
argument_list|(
name|vbox
argument_list|)
block|;
name|metaObject
argument_list|()
operator|->
name|connectSlotsByName
argument_list|(
name|this
argument_list|)
block|;
name|m_depthSpinBox
operator|->
name|setValue
argument_list|(
literal|20
argument_list|)
block|;
comment|// triggers purposedly on_depthSpinBox_valueChanged
block|}
name|private
name|slots
operator|:
name|void
name|on_depthSpinBox_valueChanged
argument_list|(
argument|int value
argument_list|)
block|{
name|m_stats
operator|.
name|relayoutClicked
operator|=
name|false
block|;
if|if
condition|(
name|m_window
condition|)
block|{
name|QApplication
operator|::
name|processEvents
argument_list|()
expr_stmt|;
name|delete
name|m_window
decl_stmt|;
block|}
name|m_window
operator|=
name|new
name|SlowWidget
argument_list|(
literal|0
argument_list|,
name|Qt
operator|::
name|Window
argument_list|)
expr_stmt|;
name|m_window
operator|->
name|setStats
argument_list|(
operator|&
name|m_stats
argument_list|)
block|;
name|m_window
operator|->
name|setWindow
argument_list|(
name|this
argument_list|)
block|;
name|QColor
name|col
argument_list|(
name|Qt
operator|::
name|black
argument_list|)
block|;
name|m_window
operator|->
name|setBrush
argument_list|(
name|col
argument_list|)
block|;
name|scene
operator|.
name|addItem
argument_list|(
name|m_window
argument_list|)
block|;
name|m_leaf
operator|=
literal|0
block|;
specifier|const
name|int
name|depth
operator|=
name|value
block|;
name|SlowWidget
operator|*
name|parent
operator|=
name|m_window
block|;
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|depth
condition|;
operator|++
name|i
control|)
block|{
name|QGraphicsLinearLayout
modifier|*
name|l
init|=
name|new
name|QGraphicsLinearLayout
argument_list|(
name|parent
argument_list|)
decl_stmt|;
name|l
operator|->
name|setContentsMargins
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|SlowWidget
modifier|*
name|child
init|=
name|new
name|SlowWidget
decl_stmt|;
name|QColor
name|col
decl_stmt|;
name|col
operator|.
name|setHsl
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|255
operator|*
name|i
operator|/
operator|(
name|depth
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
name|child
operator|->
name|setBrush
argument_list|(
name|col
argument_list|)
expr_stmt|;
name|child
operator|->
name|setStats
argument_list|(
operator|&
name|m_stats
argument_list|)
expr_stmt|;
name|child
operator|->
name|setWindow
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|l
operator|->
name|addItem
argument_list|(
name|child
argument_list|)
expr_stmt|;
name|parent
operator|=
name|child
expr_stmt|;
block|}
name|m_leaf
operator|=
name|parent
expr_stmt|;
block|}
end_decl_stmt
begin_function
name|void
name|on_button_clicked
parameter_list|(
name|bool
comment|/*check = false*/
parameter_list|)
block|{
name|m_stats
operator|.
name|relayoutClicked
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|m_leaf
condition|)
block|{
name|QSizeF
name|sz
init|=
name|m_leaf
operator|->
name|size
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|int
argument_list|(
name|sz
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|w
operator|^=
literal|16
expr_stmt|;
name|sz
operator|=
name|QSizeF
argument_list|(
name|w
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|m_stats
operator|.
name|output
operator|=
name|m_resultLabel
expr_stmt|;
name|m_stats
operator|.
name|output
operator|->
name|setText
argument_list|(
name|QString
argument_list|(
literal|"wait..."
argument_list|)
argument_list|)
expr_stmt|;
name|m_stats
operator|.
name|setGeometryCount
operator|=
literal|0
expr_stmt|;
name|m_stats
operator|.
name|setGeometryTracker
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_stats
operator|.
name|sleepMsecs
operator|=
name|m_sleepSpinBox
operator|->
name|value
argument_list|()
expr_stmt|;
name|m_stats
operator|.
name|time
operator|.
name|start
argument_list|()
expr_stmt|;
name|m_stats
operator|.
name|currentBenchmarkIteration
operator|=
literal|0
expr_stmt|;
name|m_leaf
operator|->
name|setMinimumSize
argument_list|(
name|sz
argument_list|)
expr_stmt|;
name|m_leaf
operator|->
name|setMaximumSize
argument_list|(
name|sz
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
name|void
name|on_instantPropagationCheckbox_toggled
parameter_list|(
name|bool
name|checked
parameter_list|)
block|{
name|QGraphicsLayout
operator|::
name|setInstantInvalidatePropagation
argument_list|(
name|checked
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|public
name|slots
range|:
name|void
name|doAgain
argument_list|()
block|{
if|if
condition|(
name|m_leaf
condition|)
block|{
name|QSizeF
name|sz
init|=
name|m_leaf
operator|->
name|size
argument_list|()
decl_stmt|;
name|int
name|w
init|=
name|int
argument_list|(
name|sz
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|w
operator|^=
literal|16
expr_stmt|;
name|sz
operator|=
name|QSizeF
argument_list|(
name|w
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|m_leaf
operator|->
name|setMinimumSize
argument_list|(
name|sz
argument_list|)
expr_stmt|;
name|m_leaf
operator|->
name|setMaximumSize
argument_list|(
name|sz
argument_list|)
expr_stmt|;
block|}
block|}
name|private
operator|:
name|public
operator|:
name|QGraphicsScene
name|scene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QGraphicsView
modifier|*
name|m_view
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPushButton
modifier|*
name|m_button
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLabel
modifier|*
name|m_sleepLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSpinBox
modifier|*
name|m_sleepSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLabel
modifier|*
name|m_depthLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSpinBox
modifier|*
name|m_depthSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLabel
modifier|*
name|m_benchmarkIterationsLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QSpinBox
modifier|*
name|m_benchmarkIterationsSpinBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QCheckBox
modifier|*
name|m_instantCheckBox
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLabel
modifier|*
name|m_resultLabel
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QGraphicsWidget
modifier|*
name|m_leaf
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|SlowWidget
modifier|*
name|m_window
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|Statistics
name|m_stats
decl_stmt|;
end_decl_stmt
begin_endif
unit|};
endif|#
directive|endif
end_endif
begin_comment
comment|//WINDOW_H
end_comment
end_unit
