begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qslider.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACCESSIBILITY
end_ifndef
begin_include
include|#
directive|include
file|"qaccessible.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qevent.h"
end_include
begin_include
include|#
directive|include
file|"qpainter.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qstyleoption.h"
end_include
begin_include
include|#
directive|include
file|"private/qabstractslider_p.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QSliderPrivate
class|class
name|QSliderPrivate
super|:
specifier|public
name|QAbstractSliderPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QSlider
parameter_list|)
specifier|public
private|:
DECL|member|pressedControl
name|QStyle
operator|::
name|SubControl
name|pressedControl
decl_stmt|;
DECL|member|tickInterval
name|int
name|tickInterval
decl_stmt|;
DECL|member|tickPosition
name|QSlider
operator|::
name|TickPosition
name|tickPosition
decl_stmt|;
DECL|member|clickOffset
name|int
name|clickOffset
decl_stmt|;
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|resetLayoutItemMargins
parameter_list|()
function_decl|;
name|int
name|pixelPosToRangeValue
parameter_list|(
name|int
name|pos
parameter_list|)
specifier|const
function_decl|;
specifier|inline
name|int
name|pick
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
specifier|const
function_decl|;
name|QStyle
operator|::
name|SubControl
name|newHoverControl
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
function_decl|;
name|bool
name|updateHoverControl
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
function_decl|;
DECL|member|hoverControl
name|QStyle
operator|::
name|SubControl
name|hoverControl
decl_stmt|;
DECL|member|hoverRect
name|QRect
name|hoverRect
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|init
name|void
name|QSliderPrivate
operator|::
name|init
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
name|pressedControl
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
name|tickInterval
operator|=
literal|0
expr_stmt|;
name|tickPosition
operator|=
name|QSlider
operator|::
name|NoTicks
expr_stmt|;
name|hoverControl
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
name|q
operator|->
name|setFocusPolicy
argument_list|(
name|Qt
operator|::
name|FocusPolicy
argument_list|(
name|q
operator|->
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Button_FocusPolicy
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sp
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Slider
argument_list|)
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Vertical
condition|)
name|sp
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|q
operator|->
name|setSizePolicy
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|q
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_OwnSizePolicy
argument_list|,
literal|false
argument_list|)
expr_stmt|;
name|resetLayoutItemMargins
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resetLayoutItemMargins
name|void
name|QSliderPrivate
operator|::
name|resetLayoutItemMargins
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_SliderLayoutItem
argument_list|,
operator|&
name|opt
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|pixelPosToRangeValue
name|int
name|QSliderPrivate
operator|::
name|pixelPosToRangeValue
parameter_list|(
name|int
name|pos
parameter_list|)
specifier|const
block|{
name|Q_Q
argument_list|(
specifier|const
name|QSlider
argument_list|)
expr_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|QRect
name|gr
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderGroove
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|QRect
name|sr
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderHandle
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|int
name|sliderMin
decl_stmt|,
name|sliderMax
decl_stmt|,
name|sliderLength
decl_stmt|;
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|sliderLength
operator|=
name|sr
operator|.
name|width
argument_list|()
expr_stmt|;
name|sliderMin
operator|=
name|gr
operator|.
name|x
argument_list|()
expr_stmt|;
name|sliderMax
operator|=
name|gr
operator|.
name|right
argument_list|()
operator|-
name|sliderLength
operator|+
literal|1
expr_stmt|;
block|}
else|else
block|{
name|sliderLength
operator|=
name|sr
operator|.
name|height
argument_list|()
expr_stmt|;
name|sliderMin
operator|=
name|gr
operator|.
name|y
argument_list|()
expr_stmt|;
name|sliderMax
operator|=
name|gr
operator|.
name|bottom
argument_list|()
operator|-
name|sliderLength
operator|+
literal|1
expr_stmt|;
block|}
return|return
name|QStyle
operator|::
name|sliderValueFromPosition
argument_list|(
name|minimum
argument_list|,
name|maximum
argument_list|,
name|pos
operator|-
name|sliderMin
argument_list|,
name|sliderMax
operator|-
name|sliderMin
argument_list|,
name|opt
operator|.
name|upsideDown
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|pick
specifier|inline
name|int
name|QSliderPrivate
operator|::
name|pick
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pt
parameter_list|)
specifier|const
block|{
return|return
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
name|pt
operator|.
name|x
argument_list|()
else|:
name|pt
operator|.
name|y
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Initialize \a option with the values from this QSlider. This method     is useful for subclasses when they need a QStyleOptionSlider, but don't want     to fill in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QSlider
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionSlider
modifier|*
name|option
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|option
condition|)
return|return;
name|Q_D
argument_list|(
specifier|const
name|QSlider
argument_list|)
expr_stmt|;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|option
operator|->
name|subControls
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
name|option
operator|->
name|activeSubControls
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
name|option
operator|->
name|orientation
operator|=
name|d
operator|->
name|orientation
expr_stmt|;
name|option
operator|->
name|maximum
operator|=
name|d
operator|->
name|maximum
expr_stmt|;
name|option
operator|->
name|minimum
operator|=
name|d
operator|->
name|minimum
expr_stmt|;
name|option
operator|->
name|tickPosition
operator|=
operator|(
name|QSlider
operator|::
name|TickPosition
operator|)
name|d
operator|->
name|tickPosition
expr_stmt|;
name|option
operator|->
name|tickInterval
operator|=
name|d
operator|->
name|tickInterval
expr_stmt|;
name|option
operator|->
name|upsideDown
operator|=
operator|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
operator|)
condition|?
operator|(
name|d
operator|->
name|invertedAppearance
operator|!=
operator|(
name|option
operator|->
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
operator|)
operator|)
else|:
operator|(
operator|!
name|d
operator|->
name|invertedAppearance
operator|)
expr_stmt|;
name|option
operator|->
name|direction
operator|=
name|Qt
operator|::
name|LeftToRight
expr_stmt|;
comment|// we use the upsideDown option instead
name|option
operator|->
name|sliderPosition
operator|=
name|d
operator|->
name|position
expr_stmt|;
name|option
operator|->
name|sliderValue
operator|=
name|d
operator|->
name|value
expr_stmt|;
name|option
operator|->
name|singleStep
operator|=
name|d
operator|->
name|singleStep
expr_stmt|;
name|option
operator|->
name|pageStep
operator|=
name|d
operator|->
name|pageStep
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Horizontal
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateHoverControl
name|bool
name|QSliderPrivate
operator|::
name|updateHoverControl
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
name|QRect
name|lastHoverRect
init|=
name|hoverRect
decl_stmt|;
name|QStyle
operator|::
name|SubControl
name|lastHoverControl
init|=
name|hoverControl
decl_stmt|;
name|bool
name|doesHover
init|=
name|q
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Hover
argument_list|)
decl_stmt|;
if|if
condition|(
name|lastHoverControl
operator|!=
name|newHoverControl
argument_list|(
name|pos
argument_list|)
operator|&&
name|doesHover
condition|)
block|{
name|q
operator|->
name|update
argument_list|(
name|lastHoverRect
argument_list|)
expr_stmt|;
name|q
operator|->
name|update
argument_list|(
name|hoverRect
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
operator|!
name|doesHover
return|;
block|}
end_function
begin_function
DECL|function|newHoverControl
name|QStyle
operator|::
name|SubControl
name|QSliderPrivate
operator|::
name|newHoverControl
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|pos
parameter_list|)
block|{
name|Q_Q
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|q
operator|->
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|opt
operator|.
name|subControls
operator|=
name|QStyle
operator|::
name|SC_All
expr_stmt|;
name|QRect
name|handleRect
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderHandle
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|QRect
name|grooveRect
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderGroove
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|QRect
name|tickmarksRect
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderTickmarks
argument_list|,
name|q
argument_list|)
decl_stmt|;
if|if
condition|(
name|handleRect
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|hoverRect
operator|=
name|handleRect
expr_stmt|;
name|hoverControl
operator|=
name|QStyle
operator|::
name|SC_SliderHandle
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|grooveRect
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|hoverRect
operator|=
name|grooveRect
expr_stmt|;
name|hoverControl
operator|=
name|QStyle
operator|::
name|SC_SliderGroove
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tickmarksRect
operator|.
name|contains
argument_list|(
name|pos
argument_list|)
condition|)
block|{
name|hoverRect
operator|=
name|tickmarksRect
expr_stmt|;
name|hoverControl
operator|=
name|QStyle
operator|::
name|SC_SliderTickmarks
expr_stmt|;
block|}
else|else
block|{
name|hoverRect
operator|=
name|QRect
argument_list|()
expr_stmt|;
name|hoverControl
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
block|}
return|return
name|hoverControl
return|;
block|}
end_function
begin_comment
comment|/*!     \class QSlider     \brief The QSlider widget provides a vertical or horizontal slider.      \ingroup basicwidgets     \inmodule QtWidgets      The slider is the classic widget for controlling a bounded value.     It lets the user move a slider handle along a horizontal or vertical     groove and translates the handle's position into an integer value     within the legal range.      QSlider has very few of its own functions; most of the functionality is in     QAbstractSlider. The most useful functions are setValue() to set     the slider directly to some value; triggerAction() to simulate     the effects of clicking (useful for shortcut keys);     setSingleStep(), setPageStep() to set the steps; and setMinimum()     and setMaximum() to define the range of the scroll bar.      QSlider provides methods for controlling tickmarks.  You can use     setTickPosition() to indicate where you want the tickmarks to be,     setTickInterval() to indicate how many of them you want. the     currently set tick position and interval can be queried using the     tickPosition() and tickInterval() functions, respectively.      QSlider inherits a comprehensive set of signals:     \table     \header \li Signal \li Description     \row \li \l valueChanged()     \li Emitted when the slider's value has changed. The tracking()        determines whether this signal is emitted during user        interaction.     \row \li \l sliderPressed()     \li Emitted when the user starts to drag the slider.     \row \li \l sliderMoved()     \li Emitted when the user drags the slider.     \row \li \l sliderReleased()     \li Emitted when the user releases the slider.     \endtable      QSlider only provides integer ranges. Note that although     QSlider handles very large numbers, it becomes difficult for users     to use a slider accurately for very large ranges.      A slider accepts focus on Tab and provides both a mouse wheel and a     keyboard interface. The keyboard interface is the following:      \list         \li Left/Right move a horizontal slider by one single step.         \li Up/Down move a vertical slider by one single step.         \li PageUp moves up one page.         \li PageDown moves down one page.         \li Home moves to the start (mininum).         \li End moves to the end (maximum).     \endlist      \table 100%     \row \li \inlineimage macintosh-slider.png Screenshot of a Macintosh slider          \li A slider shown in the \l{Macintosh Style Widget Gallery}{Macintosh widget style}.     \row \li \inlineimage windows-slider.png Screenshot of a Windows XP slider          \li A slider shown in the \l{Windows XP Style Widget Gallery}{Windows XP widget style}.     \row \li \inlineimage plastique-slider.png Screenshot of a Plastique slider          \li A slider shown in the \l{Plastique Style Widget Gallery}{Plastique widget style}.     \endtable      \sa QScrollBar, QSpinBox, QDial, {fowler}{GUI Design Handbook: Slider}, {Sliders Example} */
end_comment
begin_comment
comment|/*!     \enum QSlider::TickPosition      This enum specifies where the tick marks are to be drawn relative     to the slider's groove and the handle the user moves.      \value NoTicks Do not draw any tick marks.     \value TicksBothSides Draw tick marks on both sides of the groove.     \value TicksAbove Draw tick marks above the (horizontal) slider     \value TicksBelow Draw tick marks below the (horizontal) slider     \value TicksLeft Draw tick marks to the left of the (vertical) slider     \value TicksRight Draw tick marks to the right of the (vertical) slider */
end_comment
begin_comment
comment|/*!     Constructs a vertical slider with the given \a parent. */
end_comment
begin_constructor
DECL|function|QSlider
name|QSlider
operator|::
name|QSlider
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractSlider
argument_list|(
operator|*
operator|new
name|QSliderPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|orientation
operator|=
name|Qt
operator|::
name|Vertical
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Constructs a slider with the given \a parent. The \a orientation     parameter determines whether the slider is horizontal or vertical;     the valid values are Qt::Vertical and Qt::Horizontal. */
end_comment
begin_constructor
DECL|function|QSlider
name|QSlider
operator|::
name|QSlider
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractSlider
argument_list|(
operator|*
operator|new
name|QSliderPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|d_func
argument_list|()
operator|->
name|orientation
operator|=
name|orientation
expr_stmt|;
name|d_func
argument_list|()
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys this slider. */
end_comment
begin_destructor
DECL|function|~QSlider
name|QSlider
operator|::
name|~
name|QSlider
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QSlider
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
name|QPainter
name|p
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|opt
operator|.
name|subControls
operator|=
name|QStyle
operator|::
name|SC_SliderGroove
operator||
name|QStyle
operator|::
name|SC_SliderHandle
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|tickPosition
operator|!=
name|NoTicks
condition|)
name|opt
operator|.
name|subControls
operator||=
name|QStyle
operator|::
name|SC_SliderTickmarks
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pressedControl
condition|)
block|{
name|opt
operator|.
name|activeSubControls
operator|=
name|d
operator|->
name|pressedControl
expr_stmt|;
name|opt
operator|.
name|state
operator||=
name|QStyle
operator|::
name|State_Sunken
expr_stmt|;
block|}
else|else
block|{
name|opt
operator|.
name|activeSubControls
operator|=
name|d
operator|->
name|hoverControl
expr_stmt|;
block|}
name|style
argument_list|()
operator|->
name|drawComplexControl
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
operator|&
name|p
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QSlider
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|event
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|HoverEnter
case|:
case|case
name|QEvent
operator|::
name|HoverLeave
case|:
case|case
name|QEvent
operator|::
name|HoverMove
case|:
if|if
condition|(
specifier|const
name|QHoverEvent
modifier|*
name|he
init|=
cast|static_cast
argument_list|<
specifier|const
name|QHoverEvent
operator|*
argument_list|>
argument_list|(
name|event
argument_list|)
condition|)
name|d
operator|->
name|updateHoverControl
argument_list|(
name|he
operator|->
name|pos
argument_list|()
argument_list|)
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|StyleChange
case|:
case|case
name|QEvent
operator|::
name|MacSizeChange
case|:
name|d
operator|->
name|resetLayoutItemMargins
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|QAbstractSlider
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|QSlider
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|maximum
operator|==
name|d
operator|->
name|minimum
operator|||
operator|(
name|ev
operator|->
name|buttons
argument_list|()
operator|^
name|ev
operator|->
name|button
argument_list|()
operator|)
condition|)
block|{
name|ev
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
if|if
condition|(
name|QApplication
operator|::
name|keypadNavigationEnabled
argument_list|()
condition|)
name|setEditFocus
argument_list|(
literal|true
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|ev
operator|->
name|accept
argument_list|()
expr_stmt|;
if|if
condition|(
operator|(
name|ev
operator|->
name|button
argument_list|()
operator|&
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Slider_AbsoluteSetButtons
argument_list|)
operator|)
operator|==
name|ev
operator|->
name|button
argument_list|()
condition|)
block|{
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
specifier|const
name|QRect
name|sliderRect
init|=
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderHandle
argument_list|,
name|this
argument_list|)
decl_stmt|;
specifier|const
name|QPoint
name|center
init|=
name|sliderRect
operator|.
name|center
argument_list|()
operator|-
name|sliderRect
operator|.
name|topLeft
argument_list|()
decl_stmt|;
comment|// to take half of the slider off for the setSliderPosition call we use the center - topLeft
name|setSliderPosition
argument_list|(
name|d
operator|->
name|pixelPosToRangeValue
argument_list|(
name|d
operator|->
name|pick
argument_list|(
name|ev
operator|->
name|pos
argument_list|()
operator|-
name|center
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|triggerAction
argument_list|(
name|SliderMove
argument_list|)
expr_stmt|;
name|setRepeatAction
argument_list|(
name|SliderNoAction
argument_list|)
expr_stmt|;
name|d
operator|->
name|pressedControl
operator|=
name|QStyle
operator|::
name|SC_SliderHandle
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|ev
operator|->
name|button
argument_list|()
operator|&
name|style
argument_list|()
operator|->
name|styleHint
argument_list|(
name|QStyle
operator|::
name|SH_Slider_PageSetButtons
argument_list|)
operator|)
operator|==
name|ev
operator|->
name|button
argument_list|()
condition|)
block|{
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|d
operator|->
name|pressedControl
operator|=
name|style
argument_list|()
operator|->
name|hitTestComplexControl
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|ev
operator|->
name|pos
argument_list|()
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|SliderAction
name|action
init|=
name|SliderNoAction
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|pressedControl
operator|==
name|QStyle
operator|::
name|SC_SliderGroove
condition|)
block|{
specifier|const
name|QRect
name|sliderRect
init|=
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderHandle
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|int
name|pressValue
init|=
name|d
operator|->
name|pixelPosToRangeValue
argument_list|(
name|d
operator|->
name|pick
argument_list|(
name|ev
operator|->
name|pos
argument_list|()
operator|-
name|sliderRect
operator|.
name|center
argument_list|()
operator|+
name|sliderRect
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|d
operator|->
name|pressValue
operator|=
name|pressValue
expr_stmt|;
if|if
condition|(
name|pressValue
operator|>
name|d
operator|->
name|value
condition|)
name|action
operator|=
name|SliderPageStepAdd
expr_stmt|;
elseif|else
if|if
condition|(
name|pressValue
operator|<
name|d
operator|->
name|value
condition|)
name|action
operator|=
name|SliderPageStepSub
expr_stmt|;
if|if
condition|(
name|action
condition|)
block|{
name|triggerAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|setRepeatAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
block|}
block|}
block|}
else|else
block|{
name|ev
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|d
operator|->
name|pressedControl
operator|==
name|QStyle
operator|::
name|SC_SliderHandle
condition|)
block|{
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|setRepeatAction
argument_list|(
name|SliderNoAction
argument_list|)
expr_stmt|;
name|QRect
name|sr
init|=
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QStyle
operator|::
name|SC_SliderHandle
argument_list|,
name|this
argument_list|)
decl_stmt|;
name|d
operator|->
name|clickOffset
operator|=
name|d
operator|->
name|pick
argument_list|(
name|ev
operator|->
name|pos
argument_list|()
operator|-
name|sr
operator|.
name|topLeft
argument_list|()
argument_list|)
expr_stmt|;
name|update
argument_list|(
name|sr
argument_list|)
expr_stmt|;
name|setSliderDown
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|QSlider
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pressedControl
operator|!=
name|QStyle
operator|::
name|SC_SliderHandle
condition|)
block|{
name|ev
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
name|ev
operator|->
name|accept
argument_list|()
expr_stmt|;
name|int
name|newPosition
init|=
name|d
operator|->
name|pixelPosToRangeValue
argument_list|(
name|d
operator|->
name|pick
argument_list|(
name|ev
operator|->
name|pos
argument_list|()
argument_list|)
operator|-
name|d
operator|->
name|clickOffset
argument_list|)
decl_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|setSliderPosition
argument_list|(
name|newPosition
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|QSlider
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|ev
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|pressedControl
operator|==
name|QStyle
operator|::
name|SC_None
operator|||
name|ev
operator|->
name|buttons
argument_list|()
condition|)
block|{
name|ev
operator|->
name|ignore
argument_list|()
expr_stmt|;
return|return;
block|}
name|ev
operator|->
name|accept
argument_list|()
expr_stmt|;
name|QStyle
operator|::
name|SubControl
name|oldPressed
init|=
name|QStyle
operator|::
name|SubControl
argument_list|(
name|d
operator|->
name|pressedControl
argument_list|)
decl_stmt|;
name|d
operator|->
name|pressedControl
operator|=
name|QStyle
operator|::
name|SC_None
expr_stmt|;
name|setRepeatAction
argument_list|(
name|SliderNoAction
argument_list|)
expr_stmt|;
if|if
condition|(
name|oldPressed
operator|==
name|QStyle
operator|::
name|SC_SliderHandle
condition|)
name|setSliderDown
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|opt
operator|.
name|subControls
operator|=
name|oldPressed
expr_stmt|;
name|update
argument_list|(
name|style
argument_list|()
operator|->
name|subControlRect
argument_list|(
name|QStyle
operator|::
name|CC_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|oldPressed
argument_list|,
name|this
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QSlider
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSlider
argument_list|)
expr_stmt|;
name|ensurePolished
argument_list|()
expr_stmt|;
specifier|const
name|int
name|SliderLength
init|=
literal|84
decl_stmt|,
name|TickSpace
init|=
literal|5
decl_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|int
name|thick
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_SliderThickness
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|tickPosition
operator|&
name|TicksAbove
condition|)
name|thick
operator|+=
name|TickSpace
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|tickPosition
operator|&
name|TicksBelow
condition|)
name|thick
operator|+=
name|TickSpace
expr_stmt|;
name|int
name|w
init|=
name|thick
decl_stmt|,
name|h
init|=
name|SliderLength
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
block|{
name|w
operator|=
name|SliderLength
expr_stmt|;
name|h
operator|=
name|thick
expr_stmt|;
block|}
return|return
name|style
argument_list|()
operator|->
name|sizeFromContents
argument_list|(
name|QStyle
operator|::
name|CT_Slider
argument_list|,
operator|&
name|opt
argument_list|,
name|QSize
argument_list|(
name|w
argument_list|,
name|h
argument_list|)
argument_list|,
name|this
argument_list|)
operator|.
name|expandedTo
argument_list|(
name|QApplication
operator|::
name|globalStrut
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|minimumSizeHint
name|QSize
name|QSlider
operator|::
name|minimumSizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QSlider
argument_list|)
expr_stmt|;
name|QSize
name|s
init|=
name|sizeHint
argument_list|()
decl_stmt|;
name|QStyleOptionSlider
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|int
name|length
init|=
name|style
argument_list|()
operator|->
name|pixelMetric
argument_list|(
name|QStyle
operator|::
name|PM_SliderLength
argument_list|,
operator|&
name|opt
argument_list|,
name|this
argument_list|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
name|s
operator|.
name|setWidth
argument_list|(
name|length
argument_list|)
expr_stmt|;
else|else
name|s
operator|.
name|setHeight
argument_list|(
name|length
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \property QSlider::tickPosition     \brief the tickmark position for this slider      The valid values are described by the QSlider::TickPosition enum.      The default value is \l QSlider::NoTicks.      \sa tickInterval */
end_comment
begin_function
DECL|function|setTickPosition
name|void
name|QSlider
operator|::
name|setTickPosition
parameter_list|(
name|TickPosition
name|position
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QSlider
argument_list|)
expr_stmt|;
name|d
operator|->
name|tickPosition
operator|=
name|position
expr_stmt|;
name|d
operator|->
name|resetLayoutItemMargins
argument_list|()
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tickPosition
name|QSlider
operator|::
name|TickPosition
name|QSlider
operator|::
name|tickPosition
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|tickPosition
return|;
block|}
end_function
begin_comment
comment|/*!     \property QSlider::tickInterval     \brief the interval between tickmarks      This is a value interval, not a pixel interval. If it is 0, the     slider will choose between singleStep and pageStep.      The default value is 0.      \sa tickPosition, singleStep, pageStep */
end_comment
begin_function
DECL|function|setTickInterval
name|void
name|QSlider
operator|::
name|setTickInterval
parameter_list|(
name|int
name|ts
parameter_list|)
block|{
name|d_func
argument_list|()
operator|->
name|tickInterval
operator|=
name|qMax
argument_list|(
literal|0
argument_list|,
name|ts
argument_list|)
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|tickInterval
name|int
name|QSlider
operator|::
name|tickInterval
parameter_list|()
specifier|const
block|{
return|return
name|d_func
argument_list|()
operator|->
name|tickInterval
return|;
block|}
end_function
begin_function
DECL|function|qt_qsliderStyleOption
name|Q_WIDGETS_EXPORT
name|QStyleOptionSlider
name|qt_qsliderStyleOption
parameter_list|(
name|QSlider
modifier|*
name|slider
parameter_list|)
block|{
name|QStyleOptionSlider
name|sliderOption
decl_stmt|;
name|slider
operator|->
name|initStyleOption
argument_list|(
operator|&
name|sliderOption
argument_list|)
expr_stmt|;
return|return
name|sliderOption
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
