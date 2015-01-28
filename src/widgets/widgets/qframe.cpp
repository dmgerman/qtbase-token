begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qframe.h"
end_include
begin_include
include|#
directive|include
file|"qbitmap.h"
end_include
begin_include
include|#
directive|include
file|"qdrawutil.h"
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
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qframe_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QFramePrivate
name|QFramePrivate
operator|::
name|QFramePrivate
parameter_list|()
member_init_list|:
name|frect
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
member_init_list|,
name|frameStyle
argument_list|(
name|QFrame
operator|::
name|NoFrame
operator||
name|QFrame
operator|::
name|Plain
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|1
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|frameWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|leftFrameWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|rightFrameWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|topFrameWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|bottomFrameWidth
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|init
specifier|inline
name|void
name|QFramePrivate
operator|::
name|init
parameter_list|()
block|{
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_FrameLayoutItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \class QFrame     \brief The QFrame class is the base class of widgets that can have a frame.      \ingroup abstractwidgets     \inmodule QtWidgets      QMenu uses this to "raise" the menu above the surrounding     screen. QProgressBar has a "sunken" look. QLabel has a flat look.     The frames of widgets like these can be changed.      \snippet code/src_gui_widgets_qframe.cpp 0      The QFrame class can also be used directly for creating simple     placeholder frames without any contents.      The frame style is specified by a \l{QFrame::Shape}{frame shape} and     a \l{QFrame::Shadow}{shadow style} that is used to visually separate     the frame from surrounding widgets. These properties can be set     together using the setFrameStyle() function and read with frameStyle().      The frame shapes are \l NoFrame, \l Box, \l Panel, \l StyledPanel,     HLine and \l VLine; the shadow styles are \l Plain, \l Raised and     \l Sunken.      A frame widget has three attributes that describe the thickness of the     border: \l lineWidth, \l midLineWidth, and \l frameWidth.      \list     \li The line width is the width of the frame border. It can be modified        to customize the frame's appearance.      \li The mid-line width specifies the width of an extra line in the        middle of the frame, which uses a third color to obtain a special        3D effect. Notice that a mid-line is only drawn for \l Box, \l        HLine and \l VLine frames that are raised or sunken.      \li The frame width is determined by the frame style, and the frameWidth()        function is used to obtain the value defined for the style used.     \endlist      The margin between the frame and the contents of the frame can be     customized with the QWidget::setContentsMargins() function.      \target picture     This table shows some of the combinations of styles and line widths:      \image frames.png Table of frame styles */
end_comment
begin_comment
comment|/*!     \enum QFrame::Shape      This enum type defines the shapes of frame available.      \value NoFrame  QFrame draws nothing     \value Box  QFrame draws a box around its contents     \value Panel  QFrame draws a panel to make the contents appear     raised or sunken     \value StyledPanel  draws a rectangular panel with a look that     depends on the current GUI style. It can be raised or sunken.     \value HLine  QFrame draws a horizontal line that frames nothing     (useful as separator)     \value VLine  QFrame draws a vertical line that frames nothing     (useful as separator)     \value WinPanel draws a rectangular panel that can be raised or     sunken like those in Windows 2000. Specifying this shape sets     the line width to 2 pixels. WinPanel is provided for compatibility.     For GUI style independence we recommend using StyledPanel instead.      When it does not call QStyle, Shape interacts with QFrame::Shadow,     the lineWidth() and the midLineWidth() to create the total result.     See the picture of the frames in the main class documentation.      \sa QFrame::Shadow, QFrame::style(), QStyle::drawPrimitive() */
end_comment
begin_comment
comment|/*!     \enum QFrame::Shadow      This enum type defines the types of shadow that are used to give     a 3D effect to frames.      \value Plain  the frame and contents appear level with the     surroundings; draws using the palette QPalette::WindowText color     (without any 3D effect)      \value Raised the frame and contents appear raised; draws a 3D     raised line using the light and dark colors of the current color     group     \value Sunken the frame and contents appear sunken; draws a 3D     sunken line using the light and dark colors of the current color     group      Shadow interacts with QFrame::Shape, the lineWidth() and the     midLineWidth(). See the picture of the frames in the main class     documentation.      \sa QFrame::Shape, lineWidth(), midLineWidth() */
end_comment
begin_comment
comment|/*!     \enum QFrame::StyleMask      This enum defines two constants that can be used to extract the     two components of frameStyle():      \value Shadow_Mask The \l Shadow part of frameStyle()     \value Shape_Mask  The \l Shape part of frameStyle()      Normally, you don't need to use these, since frameShadow() and     frameShape() already extract the \l Shadow and the \l Shape parts     of frameStyle().      \sa frameStyle(), setFrameStyle() */
end_comment
begin_comment
comment|/*!     Constructs a frame widget with frame style \l NoFrame and a     1-pixel frame width.      The \a parent and \a f arguments are passed to the QWidget     constructor. */
end_comment
begin_constructor
DECL|function|QFrame
name|QFrame
operator|::
name|QFrame
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QFramePrivate
argument_list|,
name|parent
argument_list|,
name|f
argument_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*! \internal */
end_comment
begin_constructor
DECL|function|QFrame
name|QFrame
operator|::
name|QFrame
parameter_list|(
name|QFramePrivate
modifier|&
name|dd
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|,
name|Qt
operator|::
name|WindowFlags
name|f
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|,
name|f
argument_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
name|d
operator|->
name|init
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \since 5.5      Initializes \a option with the values from this QFrame. This method is     useful for subclasses when they need a QStyleOptionFrame but don't want to     fill in all the information themselves.      \sa QStyleOption::initFrom() */
end_comment
begin_function
DECL|function|initStyleOption
name|void
name|QFrame
operator|::
name|initStyleOption
parameter_list|(
name|QStyleOptionFrame
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
name|QFrame
argument_list|)
expr_stmt|;
name|option
operator|->
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|int
name|frameShape
init|=
name|d
operator|->
name|frameStyle
operator|&
name|QFrame
operator|::
name|Shape_Mask
decl_stmt|;
name|int
name|frameShadow
init|=
name|d
operator|->
name|frameStyle
operator|&
name|QFrame
operator|::
name|Shadow_Mask
decl_stmt|;
name|option
operator|->
name|frameShape
operator|=
name|Shape
argument_list|(
name|int
argument_list|(
name|option
operator|->
name|frameShape
argument_list|)
operator||
name|frameShape
argument_list|)
expr_stmt|;
name|option
operator|->
name|rect
operator|=
name|frameRect
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|frameShape
condition|)
block|{
case|case
name|QFrame
operator|::
name|Box
case|:
case|case
name|QFrame
operator|::
name|HLine
case|:
case|case
name|QFrame
operator|::
name|VLine
case|:
case|case
name|QFrame
operator|::
name|StyledPanel
case|:
case|case
name|QFrame
operator|::
name|Panel
case|:
name|option
operator|->
name|lineWidth
operator|=
name|d
operator|->
name|lineWidth
expr_stmt|;
name|option
operator|->
name|midLineWidth
operator|=
name|d
operator|->
name|midLineWidth
expr_stmt|;
break|break;
default|default:
comment|// most frame styles do not handle customized line and midline widths
comment|// (see updateFrameWidth()).
name|option
operator|->
name|lineWidth
operator|=
name|d
operator|->
name|frameWidth
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|frameShadow
operator|==
name|Sunken
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Sunken
expr_stmt|;
elseif|else
if|if
condition|(
name|frameShadow
operator|==
name|Raised
condition|)
name|option
operator|->
name|state
operator||=
name|QStyle
operator|::
name|State_Raised
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Destroys the frame.  */
end_comment
begin_destructor
DECL|function|~QFrame
name|QFrame
operator|::
name|~
name|QFrame
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Returns the frame style.      The default value is QFrame::Plain.      \sa setFrameStyle(), frameShape(), frameShadow() */
end_comment
begin_function
DECL|function|frameStyle
name|int
name|QFrame
operator|::
name|frameStyle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|frameStyle
return|;
block|}
end_function
begin_comment
comment|/*!     \property QFrame::frameShape     \brief the frame shape value from the frame style      \sa frameStyle(), frameShadow() */
end_comment
begin_function
DECL|function|frameShape
name|QFrame
operator|::
name|Shape
name|QFrame
operator|::
name|frameShape
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
return|return
call|(
name|Shape
call|)
argument_list|(
name|d
operator|->
name|frameStyle
operator|&
name|Shape_Mask
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setFrameShape
name|void
name|QFrame
operator|::
name|setFrameShape
parameter_list|(
name|QFrame
operator|::
name|Shape
name|s
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
operator|(
name|d
operator|->
name|frameStyle
operator|&
name|Shadow_Mask
operator|)
operator||
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QFrame::frameShadow     \brief the frame shadow value from the frame style      \sa frameStyle(), frameShape() */
end_comment
begin_function
DECL|function|frameShadow
name|QFrame
operator|::
name|Shadow
name|QFrame
operator|::
name|frameShadow
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
return|return
call|(
name|Shadow
call|)
argument_list|(
name|d
operator|->
name|frameStyle
operator|&
name|Shadow_Mask
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|setFrameShadow
name|void
name|QFrame
operator|::
name|setFrameShadow
parameter_list|(
name|QFrame
operator|::
name|Shadow
name|s
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
name|setFrameStyle
argument_list|(
operator|(
name|d
operator|->
name|frameStyle
operator|&
name|Shape_Mask
operator|)
operator||
name|s
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the frame style to \a style.      The \a style is the bitwise OR between a frame shape and a frame     shadow style. See the picture of the frames in the main class     documentation.      The frame shapes are given in \l{QFrame::Shape} and the shadow     styles in \l{QFrame::Shadow}.      If a mid-line width greater than 0 is specified, an additional     line is drawn for \l Raised or \l Sunken \l Box, \l HLine, and \l     VLine frames. The mid-color of the current color group is used for     drawing middle lines.      \sa frameStyle() */
end_comment
begin_function
DECL|function|setFrameStyle
name|void
name|QFrame
operator|::
name|setFrameStyle
parameter_list|(
name|int
name|style
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_OwnSizePolicy
argument_list|)
condition|)
block|{
name|QSizePolicy
name|sp
decl_stmt|;
switch|switch
condition|(
name|style
operator|&
name|Shape_Mask
condition|)
block|{
case|case
name|HLine
case|:
name|sp
operator|=
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Line
argument_list|)
expr_stmt|;
break|break;
case|case
name|VLine
case|:
name|sp
operator|=
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
argument_list|,
name|QSizePolicy
operator|::
name|Minimum
argument_list|,
name|QSizePolicy
operator|::
name|Line
argument_list|)
expr_stmt|;
break|break;
default|default:
name|sp
operator|=
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Preferred
argument_list|,
name|QSizePolicy
operator|::
name|Frame
argument_list|)
expr_stmt|;
block|}
name|setSizePolicy
argument_list|(
name|sp
argument_list|)
expr_stmt|;
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_OwnSizePolicy
argument_list|,
literal|false
argument_list|)
expr_stmt|;
block|}
name|d
operator|->
name|frameStyle
operator|=
operator|(
name|short
operator|)
name|style
expr_stmt|;
name|update
argument_list|()
expr_stmt|;
name|d
operator|->
name|updateFrameWidth
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QFrame::lineWidth     \brief the line width      Note that the \e total line width for frames used as separators     (\l HLine and \l VLine) is specified by \l frameWidth.      The default value is 1.      \sa midLineWidth, frameWidth */
end_comment
begin_function
DECL|function|setLineWidth
name|void
name|QFrame
operator|::
name|setLineWidth
parameter_list|(
name|int
name|w
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
if|if
condition|(
name|short
argument_list|(
name|w
argument_list|)
operator|==
name|d
operator|->
name|lineWidth
condition|)
return|return;
name|d
operator|->
name|lineWidth
operator|=
name|short
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateFrameWidth
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lineWidth
name|int
name|QFrame
operator|::
name|lineWidth
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|lineWidth
return|;
block|}
end_function
begin_comment
comment|/*!     \property QFrame::midLineWidth     \brief the width of the mid-line      The default value is 0.      \sa lineWidth, frameWidth */
end_comment
begin_function
DECL|function|setMidLineWidth
name|void
name|QFrame
operator|::
name|setMidLineWidth
parameter_list|(
name|int
name|w
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
if|if
condition|(
name|short
argument_list|(
name|w
argument_list|)
operator|==
name|d
operator|->
name|midLineWidth
condition|)
return|return;
name|d
operator|->
name|midLineWidth
operator|=
name|short
argument_list|(
name|w
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateFrameWidth
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|midLineWidth
name|int
name|QFrame
operator|::
name|midLineWidth
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|midLineWidth
return|;
block|}
end_function
begin_comment
comment|/*!   \internal   Updates the frame widths from the style. */
end_comment
begin_function
DECL|function|updateStyledFrameWidths
name|void
name|QFramePrivate
operator|::
name|updateStyledFrameWidths
parameter_list|()
block|{
name|Q_Q
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
name|QStyleOptionFrame
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
name|cr
init|=
name|q
operator|->
name|style
argument_list|()
operator|->
name|subElementRect
argument_list|(
name|QStyle
operator|::
name|SE_ShapedFrameContents
argument_list|,
operator|&
name|opt
argument_list|,
name|q
argument_list|)
decl_stmt|;
name|leftFrameWidth
operator|=
name|cr
operator|.
name|left
argument_list|()
operator|-
name|opt
operator|.
name|rect
operator|.
name|left
argument_list|()
expr_stmt|;
name|topFrameWidth
operator|=
name|cr
operator|.
name|top
argument_list|()
operator|-
name|opt
operator|.
name|rect
operator|.
name|top
argument_list|()
expr_stmt|;
name|rightFrameWidth
operator|=
name|opt
operator|.
name|rect
operator|.
name|right
argument_list|()
operator|-
name|cr
operator|.
name|right
argument_list|()
operator|,
name|bottomFrameWidth
operator|=
name|opt
operator|.
name|rect
operator|.
name|bottom
argument_list|()
operator|-
name|cr
operator|.
name|bottom
argument_list|()
expr_stmt|;
name|frameWidth
operator|=
name|qMax
argument_list|(
name|qMax
argument_list|(
name|leftFrameWidth
argument_list|,
name|rightFrameWidth
argument_list|)
argument_list|,
name|qMax
argument_list|(
name|topFrameWidth
argument_list|,
name|bottomFrameWidth
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   \internal   Updated the frameWidth parameter. */
end_comment
begin_function
DECL|function|updateFrameWidth
name|void
name|QFramePrivate
operator|::
name|updateFrameWidth
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
name|QRect
name|fr
init|=
name|q
operator|->
name|frameRect
argument_list|()
decl_stmt|;
name|updateStyledFrameWidths
argument_list|()
expr_stmt|;
name|q
operator|->
name|setFrameRect
argument_list|(
name|fr
argument_list|)
expr_stmt|;
name|setLayoutItemMargins
argument_list|(
name|QStyle
operator|::
name|SE_FrameLayoutItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QFrame::frameWidth     \brief the width of the frame that is drawn.      Note that the frame width depends on the \l{QFrame::setFrameStyle()}{frame style},     not only the line width and the mid-line width. For example, the style specified     by \l NoFrame always has a frame width of 0, whereas the style \l Panel has a     frame width equivalent to the line width.      \sa lineWidth(), midLineWidth(), frameStyle() */
end_comment
begin_function
DECL|function|frameWidth
name|int
name|QFrame
operator|::
name|frameWidth
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|frameWidth
return|;
block|}
end_function
begin_comment
comment|/*!     \property QFrame::frameRect     \brief the frame's rectangle      The frame's rectangle is the rectangle the frame is drawn in. By     default, this is the entire widget. Setting the rectangle does     does \e not cause a widget update. The frame rectangle is     automatically adjusted when the widget changes size.      If you set the rectangle to a null rectangle (for example,     QRect(0, 0, 0, 0)), then the resulting frame rectangle is     equivalent to the \l{QWidget::rect()}{widget rectangle}. */
end_comment
begin_function
DECL|function|frameRect
name|QRect
name|QFrame
operator|::
name|frameRect
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
name|QRect
name|fr
init|=
name|contentsRect
argument_list|()
decl_stmt|;
name|fr
operator|.
name|adjust
argument_list|(
operator|-
name|d
operator|->
name|leftFrameWidth
argument_list|,
operator|-
name|d
operator|->
name|topFrameWidth
argument_list|,
name|d
operator|->
name|rightFrameWidth
argument_list|,
name|d
operator|->
name|bottomFrameWidth
argument_list|)
expr_stmt|;
return|return
name|fr
return|;
block|}
end_function
begin_function
DECL|function|setFrameRect
name|void
name|QFrame
operator|::
name|setFrameRect
parameter_list|(
specifier|const
name|QRect
modifier|&
name|r
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
name|QRect
name|cr
init|=
name|r
operator|.
name|isValid
argument_list|()
condition|?
name|r
else|:
name|rect
argument_list|()
decl_stmt|;
name|cr
operator|.
name|adjust
argument_list|(
name|d
operator|->
name|leftFrameWidth
argument_list|,
name|d
operator|->
name|topFrameWidth
argument_list|,
operator|-
name|d
operator|->
name|rightFrameWidth
argument_list|,
operator|-
name|d
operator|->
name|bottomFrameWidth
argument_list|)
expr_stmt|;
name|setContentsMargins
argument_list|(
name|cr
operator|.
name|left
argument_list|()
argument_list|,
name|cr
operator|.
name|top
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|right
argument_list|()
operator|-
name|cr
operator|.
name|right
argument_list|()
argument_list|,
name|rect
argument_list|()
operator|.
name|bottom
argument_list|()
operator|-
name|cr
operator|.
name|bottom
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!\reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QFrame
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QFrame
argument_list|)
expr_stmt|;
comment|//   Returns a size hint for the frame - for HLine and VLine
comment|//   shapes, this is stretchable one way and 3 pixels wide the
comment|//   other.  For other shapes, QWidget::sizeHint() is used.
switch|switch
condition|(
name|d
operator|->
name|frameStyle
operator|&
name|Shape_Mask
condition|)
block|{
case|case
name|HLine
case|:
return|return
name|QSize
argument_list|(
operator|-
literal|1
argument_list|,
literal|3
argument_list|)
return|;
case|case
name|VLine
case|:
return|return
name|QSize
argument_list|(
literal|3
argument_list|,
operator|-
literal|1
argument_list|)
return|;
default|default:
return|return
name|QWidget
operator|::
name|sizeHint
argument_list|()
return|;
block|}
block|}
end_function
begin_comment
comment|/*!\reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QFrame
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
parameter_list|)
block|{
name|QPainter
name|paint
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|drawFrame
argument_list|(
operator|&
name|paint
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal      Used by QLabel and QLCDNumber  */
end_comment
begin_function
DECL|function|drawFrame
name|void
name|QFrame
operator|::
name|drawFrame
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|QStyleOptionFrame
name|opt
decl_stmt|;
name|initStyleOption
argument_list|(
operator|&
name|opt
argument_list|)
expr_stmt|;
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_ShapedFrame
argument_list|,
operator|&
name|opt
argument_list|,
name|p
argument_list|,
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!\reimp  */
end_comment
begin_function
DECL|function|changeEvent
name|void
name|QFrame
operator|::
name|changeEvent
parameter_list|(
name|QEvent
modifier|*
name|ev
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QFrame
argument_list|)
expr_stmt|;
if|if
condition|(
name|ev
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StyleChange
ifdef|#
directive|ifdef
name|Q_OS_MAC
operator|||
name|ev
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|MacSizeChange
endif|#
directive|endif
condition|)
name|d
operator|->
name|updateFrameWidth
argument_list|()
expr_stmt|;
name|QWidget
operator|::
name|changeEvent
argument_list|(
name|ev
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*! \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QFrame
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
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
name|ParentChange
condition|)
name|d_func
argument_list|()
operator|->
name|updateFrameWidth
argument_list|()
expr_stmt|;
name|bool
name|result
init|=
name|QWidget
operator|::
name|event
argument_list|(
name|e
argument_list|)
decl_stmt|;
comment|//this has to be done after the widget has been polished
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Polish
condition|)
name|d_func
argument_list|()
operator|->
name|updateFrameWidth
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
