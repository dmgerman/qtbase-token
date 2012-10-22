begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
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
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_MAC
end_ifdef
begin_include
include|#
directive|include
file|"qmacstyle_mac.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmath.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QStyleOption     \brief The QStyleOption class stores the parameters used by QStyle functions.      \ingroup appearance     \inmodule QtWidgets      QStyleOption and its subclasses contain all the information that     QStyle functions need to draw a graphical element.      For performance reasons, there are few member functions and the     access to the member variables is direct (i.e., using the \c . or     \c -> operator). This low-level feel makes the structures     straightforward to use and emphasizes that these are simply     parameters used by the style functions.      The caller of a QStyle function usually creates QStyleOption     objects on the stack. This combined with Qt's extensive use of     \l{implicit sharing} for types such as QString, QPalette, and     QColor ensures that no memory allocation needlessly takes place.      The following code snippet shows how to use a specific     QStyleOption subclass to paint a push button:      \snippet qstyleoption/main.cpp 0      In our example, the control is a QStyle::CE_PushButton, and     according to the QStyle::drawControl() documentation the     corresponding class is QStyleOptionButton.      When reimplementing QStyle functions that take a QStyleOption     parameter, you often need to cast the QStyleOption to a subclass.     For safety, you can use qstyleoption_cast() to ensure that the     pointer type is correct. For example:      \snippet qstyleoption/main.cpp 4      The qstyleoption_cast() function will return 0 if the object to     which \c option points is not of the correct type.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyle, QStylePainter */
end_comment
begin_comment
comment|/*!     \enum QStyleOption::OptionType      This enum is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \value SO_Button \l QStyleOptionButton     \value SO_ComboBox \l QStyleOptionComboBox     \value SO_Complex \l QStyleOptionComplex     \value SO_Default QStyleOption     \value SO_DockWidget \l QStyleOptionDockWidget     \value SO_FocusRect \l QStyleOptionFocusRect     \value SO_Frame \l QStyleOptionFrame     \value SO_GraphicsItem \l QStyleOptionGraphicsItem     \value SO_GroupBox \l QStyleOptionGroupBox     \value SO_Header \l QStyleOptionHeader     \value SO_MenuItem \l QStyleOptionMenuItem     \value SO_ProgressBar \l QStyleOptionProgressBar     \value SO_RubberBand \l QStyleOptionRubberBand     \value SO_SizeGrip \l QStyleOptionSizeGrip     \value SO_Slider \l QStyleOptionSlider     \value SO_SpinBox \l QStyleOptionSpinBox     \value SO_Tab \l QStyleOptionTab     \value SO_TabBarBase \l QStyleOptionTabBarBase     \value SO_TabWidgetFrame \l QStyleOptionTabWidgetFrame     \value SO_TitleBar \l QStyleOptionTitleBar     \value SO_ToolBar \l QStyleOptionToolBar     \value SO_ToolBox \l QStyleOptionToolBox     \value SO_ToolButton \l QStyleOptionToolButton     \value SO_ViewItem \l QStyleOptionViewItem (used in Interviews)      The following values are used for custom controls:      \value SO_CustomBase Reserved for custom QStyleOptions;                          all custom controls values must be above this value     \value SO_ComplexCustomBase Reserved for custom QStyleOptions;                          all custom complex controls values must be above this value      \sa type */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOption with the specified \a version and \a     type.      The version has no special meaning for QStyleOption; it can be     used by subclasses to distinguish between different version of     the same option type.      The \l state member variable is initialized to     QStyle::State_None.      \sa version, type */
end_comment
begin_constructor
DECL|function|QStyleOption
name|QStyleOption
operator|::
name|QStyleOption
parameter_list|(
name|int
name|version
parameter_list|,
name|int
name|type
parameter_list|)
member_init_list|:
name|version
argument_list|(
name|version
argument_list|)
member_init_list|,
name|type
argument_list|(
name|type
argument_list|)
member_init_list|,
name|state
argument_list|(
name|QStyle
operator|::
name|State_None
argument_list|)
member_init_list|,
name|direction
argument_list|(
name|QApplication
operator|::
name|layoutDirection
argument_list|()
argument_list|)
member_init_list|,
name|fontMetrics
argument_list|(
name|QFont
argument_list|()
argument_list|)
member_init_list|,
name|styleObject
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys this style option object. */
end_comment
begin_destructor
DECL|function|~QStyleOption
name|QStyleOption
operator|::
name|~
name|QStyleOption
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \fn void QStyleOption::initFrom(const QWidget *widget)     \since 4.1      Initializes the \l state, \l direction, \l rect, \l palette, \l fontMetrics     and \l styleObject member variables based on the specified \a widget.      This is a convenience function; the member variables can also be     initialized manually.      \sa QWidget::layoutDirection(), QWidget::rect(),         QWidget::palette(), QWidget::fontMetrics() */
end_comment
begin_comment
comment|/*!     \obsolete      Use initFrom(\a widget) instead. */
end_comment
begin_function
DECL|function|init
name|void
name|QStyleOption
operator|::
name|init
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|QWidget
modifier|*
name|window
init|=
name|widget
operator|->
name|window
argument_list|()
decl_stmt|;
name|state
operator|=
name|QStyle
operator|::
name|State_None
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|isEnabled
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_Enabled
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|hasFocus
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_HasFocus
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_KeyboardFocusChange
argument_list|)
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_KeyboardFocusChange
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|underMouse
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_MouseOver
expr_stmt|;
if|if
condition|(
name|window
operator|->
name|isActiveWindow
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_Active
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|isWindow
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_Window
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_WS_MAC
specifier|extern
name|bool
name|qt_mac_can_clickThrough
argument_list|(
specifier|const
name|QWidget
operator|*
name|w
argument_list|)
decl_stmt|;
comment|//qwidget_mac.cpp
if|if
condition|(
operator|!
operator|(
name|state
operator|&
name|QStyle
operator|::
name|State_Active
operator|)
operator|&&
operator|!
name|qt_mac_can_clickThrough
argument_list|(
name|widget
argument_list|)
condition|)
name|state
operator|&=
operator|~
name|QStyle
operator|::
name|State_Enabled
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_MAC
switch|switch
condition|(
name|QMacStyle
operator|::
name|widgetSizePolicy
argument_list|(
name|widget
argument_list|)
condition|)
block|{
case|case
name|QMacStyle
operator|::
name|SizeSmall
case|:
name|state
operator||=
name|QStyle
operator|::
name|State_Small
expr_stmt|;
break|break;
case|case
name|QMacStyle
operator|::
name|SizeMini
case|:
name|state
operator||=
name|QStyle
operator|::
name|State_Mini
expr_stmt|;
break|break;
default|default:
empty_stmt|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
if|if
condition|(
name|widget
operator|->
name|hasEditFocus
argument_list|()
condition|)
name|state
operator||=
name|QStyle
operator|::
name|State_HasEditFocus
expr_stmt|;
endif|#
directive|endif
name|direction
operator|=
name|widget
operator|->
name|layoutDirection
argument_list|()
expr_stmt|;
name|rect
operator|=
name|widget
operator|->
name|rect
argument_list|()
expr_stmt|;
name|palette
operator|=
name|widget
operator|->
name|palette
argument_list|()
expr_stmt|;
name|fontMetrics
operator|=
name|widget
operator|->
name|fontMetrics
argument_list|()
expr_stmt|;
name|styleObject
operator|=
cast|const_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!    Constructs a copy of \a other. */
end_comment
begin_constructor
DECL|function|QStyleOption
name|QStyleOption
operator|::
name|QStyleOption
parameter_list|(
specifier|const
name|QStyleOption
modifier|&
name|other
parameter_list|)
member_init_list|:
name|version
argument_list|(
name|Version
argument_list|)
member_init_list|,
name|type
argument_list|(
name|Type
argument_list|)
member_init_list|,
name|state
argument_list|(
name|other
operator|.
name|state
argument_list|)
member_init_list|,
name|direction
argument_list|(
name|other
operator|.
name|direction
argument_list|)
member_init_list|,
name|rect
argument_list|(
name|other
operator|.
name|rect
argument_list|)
member_init_list|,
name|fontMetrics
argument_list|(
name|other
operator|.
name|fontMetrics
argument_list|)
member_init_list|,
name|palette
argument_list|(
name|other
operator|.
name|palette
argument_list|)
member_init_list|,
name|styleObject
argument_list|(
name|other
operator|.
name|styleObject
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Assign \a other to this QStyleOption. */
end_comment
begin_function
DECL|function|operator =
name|QStyleOption
modifier|&
name|QStyleOption
operator|::
name|operator
name|=
parameter_list|(
specifier|const
name|QStyleOption
modifier|&
name|other
parameter_list|)
block|{
name|state
operator|=
name|other
operator|.
name|state
expr_stmt|;
name|direction
operator|=
name|other
operator|.
name|direction
expr_stmt|;
name|rect
operator|=
name|other
operator|.
name|rect
expr_stmt|;
name|fontMetrics
operator|=
name|other
operator|.
name|fontMetrics
expr_stmt|;
name|palette
operator|=
name|other
operator|.
name|palette
expr_stmt|;
name|styleObject
operator|=
name|other
operator|.
name|styleObject
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QStyleOption::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Default} for            this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOption::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::palette     \brief the palette that should be used when painting the control      By default, the application's default palette is used.      \sa initFrom() */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::direction     \brief the text layout direction that should be used when drawing text in the control      By default, the layout direction is Qt::LeftToRight.      \sa initFrom() */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::fontMetrics     \brief the font metrics that should be used when drawing text in the control      By default, the application's default font is used.      \sa initFrom() */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::styleObject     \brief the object being styled      The built-in styles support the following types: QWidget, QGraphicsObject and QQuickItem.      \sa initFrom() */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::rect     \brief the area that should be used for various calculations and painting      This can have different meanings for different types of elements.     For example, for a \l QStyle::CE_PushButton element it would be     the rectangle for the entire button, while for a \l     QStyle::CE_PushButtonLabel element it would be just the area for     the push button label.      The default value is a null rectangle, i.e. a rectangle with both     the width and the height set to 0.      \sa initFrom() */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::state     \brief the style flags that are used when drawing the control      The default value is QStyle::State_None.      \sa initFrom(), QStyle::drawPrimitive(), QStyle::drawControl(),     QStyle::drawComplexControl(), QStyle::State */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::type     \brief the option type of the style option      The default value is SO_Default.      \sa OptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOption::version     \brief the version of the style option      This value can be used by subclasses to implement extensions     without breaking compatibility. If you use the qstyleoption_cast()     function, you normally do not need to check it.      The default value is 1. */
end_comment
begin_comment
comment|/*!     \class QStyleOptionFocusRect     \brief The QStyleOptionFocusRect class is used to describe the     parameters for drawing a focus rectangle with QStyle.      \inmodule QtWidgets       For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionFocusRect, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionFocusRect
name|QStyleOptionFocusRect
operator|::
name|QStyleOptionFocusRect
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_FocusRect
argument_list|)
block|{
name|state
operator||=
name|QStyle
operator|::
name|State_KeyboardFocusChange
expr_stmt|;
comment|// assume we had one, will be corrected in initFrom()
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionFocusRect
name|QStyleOptionFocusRect
operator|::
name|QStyleOptionFocusRect
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_FocusRect
argument_list|)
block|{
name|state
operator||=
name|QStyle
operator|::
name|State_KeyboardFocusChange
expr_stmt|;
comment|// assume we had one, will be corrected in initFrom()
block|}
end_constructor
begin_comment
comment|/*!     \enum QStyleOptionFocusRect::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_FocusRect} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionFocusRect::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \fn QStyleOptionFocusRect::QStyleOptionFocusRect(const QStyleOptionFocusRect&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionFocusRect::backgroundColor     \brief the background color on which the focus rectangle is being drawn      The default value is an invalid color with the RGB value (0, 0,     0). An invalid color is a color that is not properly set up for     the underlying window system. */
end_comment
begin_comment
comment|/*!     \class QStyleOptionFrame     \brief The QStyleOptionFrame class is used to describe the     parameters for drawing a frame.      \inmodule QtWidgets       QStyleOptionFrame is used for drawing several built-in Qt widgets,     including QFrame, QGroupBox, QLineEdit, and QMenu.      An instance of the QStyleOptionFrame class has     \l{QStyleOption::type} {type} SO_Frame and \l{QStyleOption::version}     {version} 3.      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.  The     version is used by QStyleOption subclasses to implement extensions     without breaking compatibility. If you use qstyleoption_cast(),     you normally do not need to check it.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionFrameV2     \relates QStyleOptionFrame      Synonym for QStyleOptionFrame. */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionFrameV3     \relates QStyleOptionFrame      Synonym for QStyleOptionFrame. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionFrame, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionFrame
name|QStyleOptionFrame
operator|::
name|QStyleOptionFrame
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_Frame
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|frameShape
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionFrame
name|QStyleOptionFrame
operator|::
name|QStyleOptionFrame
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_Frame
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|frameShape
argument_list|(
name|QFrame
operator|::
name|NoFrame
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionFrame::QStyleOptionFrame(const QStyleOptionFrame&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionFrame::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Frame} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionFrame::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 3      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionFrame::lineWidth     \brief the line width for drawing the frame      The default value is 0.      \sa QFrame::lineWidth */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionFrame::midLineWidth     \brief the mid-line width for drawing the frame      This is usually used in drawing sunken or raised frames.      The default value is 0.      \sa QFrame::midLineWidth */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionFrame::FrameFeature      This enum describes the different types of features a frame can have.      \value None Indicates a normal frame.     \value Flat Indicates a flat frame. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionFrame::features     \brief a bitwise OR of the features that describe this frame.      \sa FrameFeature */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionFrame::frameShape     \brief This property holds the frame shape value of the frame.      \sa QFrame::frameShape */
end_comment
begin_comment
comment|/*!     \class QStyleOptionGroupBox     \brief The QStyleOptionGroupBox class describes the parameters for     drawing a group box.      \since 4.1     \inmodule QtWidgets      QStyleOptionButton contains all the information that QStyle     functions need the various graphical elements of a group box.      It holds the lineWidth and the midLineWidth for drawing the panel,     the group box's \l {text}{title} and the title's \l     {textAlignment}{alignment} and \l {textColor}{color}.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionComplex, QGroupBox */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionGroupBox::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_GroupBox} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionGroupBox::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGroupBox::lineWidth     \brief the line width for drawing the panel      The value of this variable is, currently, always 1.      \sa QFrame::lineWidth */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGroupBox::midLineWidth     \brief the mid-line width for drawing the panel      The mid-line width is usually used when drawing sunken or raised     group box frames. The value of this variable is, currently, always 0.      \sa QFrame::midLineWidth */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGroupBox::text     \brief the text of the group box      The default value is an empty string.      \sa QGroupBox::title */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGroupBox::textAlignment     \brief the alignment of the group box title      The default value is Qt::AlignLeft.      \sa QGroupBox::alignment */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGroupBox::features     \brief the features of the group box frame      The frame is flat by default.      \sa QStyleOptionFrame::FrameFeature */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGroupBox::textColor     \brief the color of the group box title      The default value is an invalid color with the RGB value (0, 0,     0). An invalid color is a color that is not properly set up for     the underlying window system. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionGroupBox, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionGroupBox
name|QStyleOptionGroupBox
operator|::
name|QStyleOptionGroupBox
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|Type
argument_list|)
member_init_list|,
name|features
argument_list|(
name|QStyleOptionFrame
operator|::
name|None
argument_list|)
member_init_list|,
name|textAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionGroupBox::QStyleOptionGroupBox(const QStyleOptionGroupBox&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionGroupBox
name|QStyleOptionGroupBox
operator|::
name|QStyleOptionGroupBox
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|Type
argument_list|)
member_init_list|,
name|features
argument_list|(
name|QStyleOptionFrame
operator|::
name|None
argument_list|)
member_init_list|,
name|textAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \class QStyleOptionHeader     \brief The QStyleOptionHeader class is used to describe the     parameters for drawing a header.      \inmodule QtWidgets       QStyleOptionHeader contains all the information that QStyle     functions need to draw the item views' header pane, header sort     arrow, and header label.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionHeader, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionHeader
name|QStyleOptionHeader
operator|::
name|QStyleOptionHeader
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|QStyleOptionHeader
operator|::
name|Version
argument_list|,
name|SO_Header
argument_list|)
member_init_list|,
name|section
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|textAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|iconAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|position
argument_list|(
name|QStyleOptionHeader
operator|::
name|Beginning
argument_list|)
member_init_list|,
name|selectedPosition
argument_list|(
name|QStyleOptionHeader
operator|::
name|NotAdjacent
argument_list|)
member_init_list|,
name|sortIndicator
argument_list|(
name|None
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionHeader
name|QStyleOptionHeader
operator|::
name|QStyleOptionHeader
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_Header
argument_list|)
member_init_list|,
name|section
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|textAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|iconAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|position
argument_list|(
name|QStyleOptionHeader
operator|::
name|Beginning
argument_list|)
member_init_list|,
name|selectedPosition
argument_list|(
name|QStyleOptionHeader
operator|::
name|NotAdjacent
argument_list|)
member_init_list|,
name|sortIndicator
argument_list|(
name|None
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \variable QStyleOptionHeader::orientation     \brief the header's orientation (horizontal or vertical)      The default orientation is Qt::Horizontal */
end_comment
begin_comment
comment|/*!     \fn QStyleOptionHeader::QStyleOptionHeader(const QStyleOptionHeader&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionHeader::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Header} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionHeader::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::section     \brief which section of the header is being painted      The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::text     \brief the text of the header      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::textAlignment     \brief the alignment flags for the text of the header      The default value is Qt::AlignLeft. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::icon     \brief the icon of the header      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::iconAlignment     \brief the alignment flags for the icon of the header      The default value is Qt::AlignLeft. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::position     \brief the section's position in relation to the other sections      The default value is QStyleOptionHeader::Beginning. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::selectedPosition     \brief the section's position in relation to the selected section      The default value is QStyleOptionHeader::NotAdjacent */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionHeader::sortIndicator     \brief the direction the sort indicator should be drawn      The default value is QStyleOptionHeader::None. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionHeader::SectionPosition      This enum lets you know where the section's position is in relation to the other sections.      \value Beginning At the beginining of the header     \value Middle In the middle of the header     \value End At the end of the header     \value OnlyOneSection Only one header section      \sa position */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionHeader::SelectedPosition      This enum lets you know where the section's position is in relation to the selected section.      \value NotAdjacent Not adjacent to the selected section     \value NextIsSelected The next section is selected     \value PreviousIsSelected The previous section is selected     \value NextAndPreviousAreSelected Both the next and previous section are selected      \sa selectedPosition */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionHeader::SortIndicator      Indicates which direction the sort indicator should be drawn      \value None No sort indicator is needed     \value SortUp Draw an up indicator     \value SortDown Draw a down indicator      \sa sortIndicator */
end_comment
begin_comment
comment|/*!     \class QStyleOptionButton     \brief The QStyleOptionButton class is used to describe the     parameters for drawing buttons.      \inmodule QtWidgets       QStyleOptionButton contains all the information that QStyle     functions need to draw graphical elements like QPushButton,     QCheckBox, and QRadioButton.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionToolButton */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionButton::ButtonFeature      This enum describes the different types of features a push button can have.      \value None Indicates a normal push button.     \value Flat Indicates a flat push button.     \value HasMenu Indicates that the button has a drop down menu.     \value DefaultButton Indicates that the button is a default button.     \value AutoDefaultButton Indicates that the button is an auto default button.     \value CommandLinkButton Indicates that the button is a Windows Vista type command link.      \sa features */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionButton, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionButton
name|QStyleOptionButton
operator|::
name|QStyleOptionButton
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|QStyleOptionButton
operator|::
name|Version
argument_list|,
name|SO_Button
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionButton
name|QStyleOptionButton
operator|::
name|QStyleOptionButton
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_Button
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionButton::QStyleOptionButton(const QStyleOptionButton&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionButton::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Button} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionButton::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionButton::features     \brief a bitwise OR of the features that describe this button      \sa ButtonFeature */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionButton::text     \brief the text of the button      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionButton::icon     \brief the icon of the button      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename.      \sa iconSize */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionButton::iconSize     \brief the size of the icon for the button      The default value is QSize(-1, -1), i.e. an invalid size. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TOOLBAR
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionToolBar     \brief The QStyleOptionToolBar class is used to describe the     parameters for drawing a toolbar.      \since 4.1     \inmodule QtWidgets      QStyleOptionToolBar contains all the information that QStyle     functions need to draw QToolBar.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      The QStyleOptionToolBar class holds the lineWidth and the     midLineWidth for drawing the widget. It also stores information     about which \l {toolBarArea}{area} the toolbar should be located     in, whether it is movable or not, which position the toolbar line     should have (positionOfLine), and the toolbar's position within     the line (positionWithinLine).      In addition, the class provides a couple of enums: The     ToolBarFeature enum is used to describe whether a toolbar is     movable or not, and the ToolBarPosition enum is used to describe     the position of a toolbar line, as well as the toolbar's position     within the line.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionToolBar, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionToolBar
name|QStyleOptionToolBar
operator|::
name|QStyleOptionToolBar
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_ToolBar
argument_list|)
member_init_list|,
name|positionOfLine
argument_list|(
name|OnlyOne
argument_list|)
member_init_list|,
name|positionWithinLine
argument_list|(
name|OnlyOne
argument_list|)
member_init_list|,
name|toolBarArea
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionToolBar::QStyleOptionToolBar(const QStyleOptionToolBar&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionToolBar
name|QStyleOptionToolBar
operator|::
name|QStyleOptionToolBar
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_ToolBar
argument_list|)
member_init_list|,
name|positionOfLine
argument_list|(
name|OnlyOne
argument_list|)
member_init_list|,
name|positionWithinLine
argument_list|(
name|OnlyOne
argument_list|)
member_init_list|,
name|toolBarArea
argument_list|(
name|Qt
operator|::
name|TopToolBarArea
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
block|{  }
end_constructor
begin_comment
comment|/*!     \enum QStyleOptionToolBar::ToolBarPosition      \image qstyleoptiontoolbar-position.png      This enum is used to describe the position of a toolbar line, as     well as the toolbar's position within the line.      The order of the positions within a line starts at the top of a     vertical line, and from the left within a horizontal line. The     order of the positions for the lines is always from the the     parent widget's boundary edges.      \value Beginning The toolbar is located at the beginning of the line,            or the toolbar line is the first of several lines. There can            only be one toolbar (and only one line) with this position.     \value Middle The toolbar is located in the middle of the line,            or the toolbar line is in the middle of several lines. There can            several toolbars (and lines) with this position.     \value End The toolbar is located at the end of the line,            or the toolbar line is the last of several lines. There can            only be one toolbar (and only one line) with this position.     \value OnlyOne There is only one toolbar or line. This is the default value            of the positionOfLine and positionWithinLine variables.      \sa positionWithinLine, positionOfLine */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBar::ToolBarFeature      This enum is used to describe whether a toolbar is movable or not.      \value None The toolbar cannot be moved. The default value.     \value Movable The toolbar is movable, and a handle will appear when            holding the cursor over the toolbar's boundary.      \sa features, QToolBar::isMovable() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBar::positionOfLine      This variable holds the position of the toolbar line.      The default value is QStyleOptionToolBar::OnlyOne. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBar::positionWithinLine      This variable holds the position of the toolbar within a line.      The default value is QStyleOptionToolBar::OnlyOne. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBar::toolBarArea      This variable holds the location for drawing the toolbar.      The default value is Qt::TopToolBarArea.      \sa Qt::ToolBarArea */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBar::features      This variable holds whether the toolbar is movable or not.      The default value is \l None. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBar::lineWidth      This variable holds the line width for drawing the toolbar.      The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBar::midLineWidth      This variable holds the mid-line width for drawing the toolbar.      The default value is 0. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBar::StyleOptionType      This enum is used to hold information about the type of the style     option, and is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_ToolBar} for     this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBar::StyleOptionVersion      This enum is used to hold information about the version of the     style option, and is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionTab     \brief The QStyleOptionTab class is used to describe the     parameters for drawing a tab bar.      \inmodule QtWidgets       The QStyleOptionTab class is used for drawing several built-in Qt     widgets including \l QTabBar and the panel for \l QTabWidget.      An instance of the QStyleOptionTab class has     \l{QStyleOption::type} {type} \l SO_Tab and     \l{QStyleOption::version} {version} 3. The type is used internally     by QStyleOption, its subclasses, and qstyleoption_cast() to     determine the type of style option. In general you do not need to     worry about this unless you want to create your own QStyleOption     subclass and your own styles. The version is used by QStyleOption     subclasses to implement extensions without breaking     compatibility. If you use qstyleoption_cast(), you normally do not     need to check it.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionTabV2     \relates QStyleOptionTab      Synonym for QStyleOptionTab. */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionTabV3     \relates QStyleOptionTab      Synonym for QStyleOptionTab. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionTab object, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionTab
name|QStyleOptionTab
operator|::
name|QStyleOptionTab
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|QStyleOptionTab
operator|::
name|Version
argument_list|,
name|SO_Tab
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
member_init_list|,
name|row
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|position
argument_list|(
name|Beginning
argument_list|)
member_init_list|,
name|selectedPosition
argument_list|(
name|NotAdjacent
argument_list|)
member_init_list|,
name|cornerWidgets
argument_list|(
name|QStyleOptionTab
operator|::
name|NoCornerWidgets
argument_list|)
member_init_list|,
name|documentMode
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|features
argument_list|(
name|QStyleOptionTab
operator|::
name|None
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionTab
name|QStyleOptionTab
operator|::
name|QStyleOptionTab
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_Tab
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
member_init_list|,
name|row
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|position
argument_list|(
name|Beginning
argument_list|)
member_init_list|,
name|selectedPosition
argument_list|(
name|NotAdjacent
argument_list|)
member_init_list|,
name|cornerWidgets
argument_list|(
name|QStyleOptionTab
operator|::
name|NoCornerWidgets
argument_list|)
member_init_list|,
name|documentMode
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|features
argument_list|(
name|QStyleOptionTab
operator|::
name|None
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionTab::QStyleOptionTab(const QStyleOptionTab&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTab::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Tab} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTab::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 3      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTab::TabPosition      This enum describes the position of the tab.      \value Beginning The tab is the first tab in the tab bar.     \value Middle The tab is neither the first nor the last tab in the tab bar.     \value End The tab is the last tab in the tab bar.     \value OnlyOneTab The tab is both the first and the last tab in the tab bar.      \sa position */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTab::CornerWidget      These flags indicate the corner widgets in a tab.      \value NoCornerWidgets  There are no corner widgets     \value LeftCornerWidget  Left corner widget     \value RightCornerWidget Right corner widget      \sa cornerWidgets */
end_comment
begin_comment
comment|/*! \enum QStyleOptionTab::SelectedPosition      This enum describes the position of the selected tab. Some styles     need to draw a tab differently depending on whether or not it is     adjacent to the selected tab.      \value NotAdjacent The tab is not adjacent to a selected tab (or is the selected tab).     \value NextIsSelected The next tab (typically the tab on the right) is selected.     \value PreviousIsSelected The previous tab (typically the tab on the left) is selected.      \sa selectedPosition */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::selectedPosition     \brief the position of the selected tab in relation to this tab      The default value is NotAdjacent, i.e. the tab is not adjacent to     a selected tab nor is it the selected tab. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::cornerWidgets     \brief an OR combination of CornerWidget values indicating the     corner widgets of the tab bar      The default value is NoCornerWidgets.      \sa CornerWidget */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::shape     \brief the tab shape used to draw the tab; by default     QTabBar::RoundedNorth      \sa QTabBar::Shape */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::text     \brief the text of the tab      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::icon     \brief the icon for the tab      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::row     \brief which row the tab is currently in      The default value is 0, indicating the front row.  Currently this     property can only be 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::position     \brief the position of the tab in the tab bar      The default value is \l Beginning, i.e. the tab is the first tab     in the tab bar. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::iconSize     \brief the size for the icons      The default value is QSize(-1, -1), i.e. an invalid size; use     QStyle::pixelMetric() to find the default icon size for tab bars.      \sa QTabBar::iconSize() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::documentMode     \brief whether the tabbar is in document mode.      The default value is false; */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTab::TabFeature      Describes the various features that a tab button can have.      \value None A normal tab button.     \value HasFrame The tab button is positioned on a tab frame      \sa features */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::leftButtonSize     \brief the size for the left widget on the tab.      The default value is QSize(-1, -1), i.e. an invalid size; */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTab::rightButtonSize     \brief the size for the right widget on the tab.      The default value is QSize(-1, -1), i.e. an invalid size; */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABBAR
end_comment
begin_comment
comment|/*!     \class QStyleOptionProgressBar     \brief The QStyleOptionProgressBar class is used to describe the     parameters necessary for drawing a progress bar.      \inmodule QtWidgets      An instance of the QStyleOptionProgressBar class has type     SO_ProgressBar and version 2.      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.  The     version is used by QStyleOption subclasses to implement extensions     without breaking compatibility. If you use qstyleoption_cast(),     you normally do not need to check it.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionProgressBarV2     \relates QStyleOptionProgressBar      Synonym for QStyleOptionProgressBar. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionProgressBar, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionProgressBar
name|QStyleOptionProgressBar
operator|::
name|QStyleOptionProgressBar
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|QStyleOptionProgressBar
operator|::
name|Version
argument_list|,
name|SO_ProgressBar
argument_list|)
member_init_list|,
name|minimum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|progress
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|textAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|textVisible
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
member_init_list|,
name|invertedAppearance
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|bottomToTop
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionProgressBar
name|QStyleOptionProgressBar
operator|::
name|QStyleOptionProgressBar
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_ProgressBar
argument_list|)
member_init_list|,
name|minimum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|progress
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|textAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|textVisible
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
member_init_list|,
name|invertedAppearance
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|bottomToTop
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionProgressBar::QStyleOptionProgressBar(const QStyleOptionProgressBar&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionProgressBar::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_ProgressBar} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionProgressBar::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 2      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::minimum     \brief the minimum value for the progress bar      This is the minimum value in the progress bar. The default value     is 0.      \sa QProgressBar::minimum */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::maximum     \brief the maximum value for the progress bar      This is the maximum value in the progress bar. The default value     is 0.      \sa QProgressBar::maximum */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::text     \brief the text for the progress bar      The progress bar text is usually just the progress expressed as a     string.  An empty string indicates that the progress bar has not     started yet. The default value is an empty string.      \sa QProgressBar::text */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::textVisible     \brief a flag indicating whether or not text is visible      If this flag is true then the text is visible. Otherwise, the text     is not visible. The default value is false.      \sa QProgressBar::textVisible */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::textAlignment     \brief the text alignment for the text in the QProgressBar      This can be used as a guide on where the text should be in the     progress bar. The default value is Qt::AlignLeft. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::progress     \brief the current progress for the progress bar      The current progress. A value of QStyleOptionProgressBar::minimum     - 1 indicates that the progress hasn't started yet. The default     value is 0.      \sa QProgressBar::value */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::orientation     \brief the progress bar's orientation (horizontal or vertical);     the default orentation is Qt::Horizontal      \sa QProgressBar::orientation */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::invertedAppearance     \brief whether the progress bar's appearance is inverted      The default value is false.      \sa QProgressBar::invertedAppearance */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionProgressBar::bottomToTop     \brief whether the text reads from bottom to top when the progress     bar is vertical      The default value is false.      \sa QProgressBar::textDirection */
end_comment
begin_comment
comment|/*!     \class QStyleOptionMenuItem     \brief The QStyleOptionMenuItem class is used to describe the     parameter necessary for drawing a menu item.      \inmodule QtWidgets       QStyleOptionMenuItem contains all the information that QStyle     functions need to draw the menu items from \l QMenu. It is also     used for drawing other menu-related widgets.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionMenuItem, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionMenuItem
name|QStyleOptionMenuItem
operator|::
name|QStyleOptionMenuItem
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|QStyleOptionMenuItem
operator|::
name|Version
argument_list|,
name|SO_MenuItem
argument_list|)
member_init_list|,
name|menuItemType
argument_list|(
name|Normal
argument_list|)
member_init_list|,
name|checkType
argument_list|(
name|NotCheckable
argument_list|)
member_init_list|,
name|checked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|menuHasCheckableItems
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|maxIconWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tabWidth
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionMenuItem
name|QStyleOptionMenuItem
operator|::
name|QStyleOptionMenuItem
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_MenuItem
argument_list|)
member_init_list|,
name|menuItemType
argument_list|(
name|Normal
argument_list|)
member_init_list|,
name|checkType
argument_list|(
name|NotCheckable
argument_list|)
member_init_list|,
name|checked
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|menuHasCheckableItems
argument_list|(
literal|true
argument_list|)
member_init_list|,
name|maxIconWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tabWidth
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionMenuItem::QStyleOptionMenuItem(const QStyleOptionMenuItem&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionMenuItem::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_MenuItem} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionMenuItem::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionMenuItem::MenuItemType      This enum indicates the type of menu item that the structure describes.      \value Normal A normal menu item.     \value DefaultItem A menu item that is the default action as specified with \l QMenu::defaultAction().     \value Separator A menu separator.     \value SubMenu Indicates the menu item points to a sub-menu.     \value Scroller A popup menu scroller (currently only used on Mac OS X).     \value TearOff A tear-off handle for the menu.     \value Margin The margin of the menu.     \value EmptyArea The empty area of the menu.      \sa menuItemType */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionMenuItem::CheckType      This enum is used to indicate whether or not a check mark should be     drawn for the item, or even if it should be drawn at all.      \value NotCheckable The item is not checkable.     \value Exclusive The item is an exclusive check item (like a radio button).     \value NonExclusive The item is a non-exclusive check item (like a check box).      \sa checkType, QAction::checkable, QAction::checked, QActionGroup::exclusive */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::menuItemType     \brief the type of menu item      The default value is \l Normal.      \sa MenuItemType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::checkType     \brief the type of checkmark of the menu item      The default value is \l NotCheckable.      \sa CheckType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::checked     \brief whether the menu item is checked or not      The default value is false. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::menuHasCheckableItems     \brief whether the menu as a whole has checkable items or not      The default value is true.      If this option is set to false, then the menu has no checkable     items. This makes it possible for GUI styles to save some     horizontal space that would normally be used for the check column. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::menuRect     \brief the rectangle for the entire menu      The default value is a null rectangle, i.e. a rectangle with both     the width and the height set to 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::text     \brief the text for the menu item      Note that the text format is something like this "Menu     text\b{\\t}Shortcut".      If the menu item doesn't have a shortcut, it will just contain the     menu item's text. The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::icon     \brief the icon for the menu item      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::maxIconWidth     \brief the maximum icon width for the icon in the menu item      This can be used for drawing the icon into the correct place or     properly aligning items. The variable must be set regardless of     whether or not the menu item has an icon. The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::tabWidth     \brief the tab width for the menu item      The tab width is the distance between the text of the menu item     and the shortcut. The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionMenuItem::font     \brief the font used for the menu item text      This is the font that should be used for drawing the menu text     minus the shortcut. The shortcut is usually drawn using the     painter's font. By default, the application's default font is     used. */
end_comment
begin_comment
comment|/*!     \class QStyleOptionComplex     \brief The QStyleOptionComplex class is used to hold parameters that are     common to all complex controls.      \inmodule QtWidgets       This class is not used on its own. Instead it is used to derive     other complex control options, for example QStyleOptionSlider and     QStyleOptionSpinBox.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator).      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionComplex of the specified \a type and \a     version, initializing the member variables to their default     values. This constructor is usually called by subclasses. */
end_comment
begin_constructor
DECL|function|QStyleOptionComplex
name|QStyleOptionComplex
operator|::
name|QStyleOptionComplex
parameter_list|(
name|int
name|version
parameter_list|,
name|int
name|type
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|type
argument_list|)
member_init_list|,
name|subControls
argument_list|(
name|QStyle
operator|::
name|SC_All
argument_list|)
member_init_list|,
name|activeSubControls
argument_list|(
name|QStyle
operator|::
name|SC_None
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionComplex::QStyleOptionComplex(const QStyleOptionComplex&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionComplex::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Complex} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionComplex::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComplex::subControls      This variable holds a bitwise OR of the \l{QStyle::SubControl}     {sub-controls} to be drawn for the complex control.      The default value is QStyle::SC_All.      \sa QStyle::SubControl */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComplex::activeSubControls      This variable holds a bitwise OR of the \l{QStyle::SubControl}     {sub-controls} that are active for the complex control.      The default value is QStyle::SC_None.      \sa QStyle::SubControl */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SLIDER
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionSlider     \brief The QStyleOptionSlider class is used to describe the     parameters needed for drawing a slider.      \inmodule QtWidgets       QStyleOptionSlider contains all the information that QStyle     functions need to draw QSlider and QScrollBar.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOptionComplex, QSlider, QScrollBar */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionSlider, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionSlider
name|QStyleOptionSlider
operator|::
name|QStyleOptionSlider
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|SO_Slider
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
member_init_list|,
name|minimum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tickPosition
argument_list|(
name|QSlider
operator|::
name|NoTicks
argument_list|)
member_init_list|,
name|tickInterval
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|upsideDown
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|sliderPosition
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sliderValue
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|singleStep
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pageStep
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|notchTarget
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|dialWrapping
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionSlider
name|QStyleOptionSlider
operator|::
name|QStyleOptionSlider
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|SO_Slider
argument_list|)
member_init_list|,
name|orientation
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
member_init_list|,
name|minimum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|maximum
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|tickPosition
argument_list|(
name|QSlider
operator|::
name|NoTicks
argument_list|)
member_init_list|,
name|tickInterval
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|upsideDown
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|sliderPosition
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|sliderValue
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|singleStep
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|pageStep
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|notchTarget
argument_list|(
literal|0.0
argument_list|)
member_init_list|,
name|dialWrapping
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionSlider::QStyleOptionSlider(const QStyleOptionSlider&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionSlider::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_Slider} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionSlider::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::orientation     \brief the slider's orientation (horizontal or vertical)      The default orientation is Qt::Horizontal.      \sa Qt::Orientation */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::minimum     \brief the minimum value for the slider      The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::maximum     \brief the maximum value for the slider      The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::tickPosition     \brief the position of the slider's tick marks, if any      The default value is QSlider::NoTicks.      \sa QSlider::TickPosition */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::tickInterval     \brief the interval that should be drawn between tick marks      The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::notchTarget     \brief the number of pixel between notches      The default value is 0.0.      \sa QDial::notchTarget() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::dialWrapping     \brief whether the dial should wrap or not      The default value is false, i.e. the dial is not wrapped.      \sa QDial::wrapping() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::upsideDown     \brief the slider control orientation      Normally a slider increases as it moves up or to the right;     upsideDown indicates that it should do the opposite (increase as     it moves down or to the left).  The default value is false,     i.e. the slider increases as it moves up or to the right.      \sa QStyle::sliderPositionFromValue(),     QStyle::sliderValueFromPosition(),     QAbstractSlider::invertedAppearance */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::sliderPosition     \brief the position of the slider handle      If the slider has active feedback (i.e.,     QAbstractSlider::tracking is true), this value will be the same as     \l sliderValue. Otherwise, it will have the current position of     the handle. The default value is 0.      \sa QAbstractSlider::tracking, sliderValue */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::sliderValue     \brief the value of the slider      If the slider has active feedback (i.e.,     QAbstractSlider::tracking is true), this value will be the same     as \l sliderPosition. Otherwise, it will have the value the     slider had before the mouse was pressed.      The default value is 0.      \sa QAbstractSlider::tracking, sliderPosition */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::singleStep     \brief the size of the single step of the slider      The default value is 0.      \sa QAbstractSlider::singleStep */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSlider::pageStep     \brief the size of the page step of the slider      The default value is 0.      \sa QAbstractSlider::pageStep */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SLIDER
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SPINBOX
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionSpinBox     \brief The QStyleOptionSpinBox class is used to describe the     parameters necessary for drawing a spin box.      \inmodule QtWidgets       QStyleOptionSpinBox contains all the information that QStyle     functions need to draw QSpinBox and QDateTimeEdit.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionComplex */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionSpinBox, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionSpinBox
name|QStyleOptionSpinBox
operator|::
name|QStyleOptionSpinBox
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|SO_SpinBox
argument_list|)
member_init_list|,
name|buttonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|UpDownArrows
argument_list|)
member_init_list|,
name|stepEnabled
argument_list|(
name|QAbstractSpinBox
operator|::
name|StepNone
argument_list|)
member_init_list|,
name|frame
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionSpinBox
name|QStyleOptionSpinBox
operator|::
name|QStyleOptionSpinBox
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|SO_SpinBox
argument_list|)
member_init_list|,
name|buttonSymbols
argument_list|(
name|QAbstractSpinBox
operator|::
name|UpDownArrows
argument_list|)
member_init_list|,
name|stepEnabled
argument_list|(
name|QAbstractSpinBox
operator|::
name|StepNone
argument_list|)
member_init_list|,
name|frame
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionSpinBox::QStyleOptionSpinBox(const QStyleOptionSpinBox&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionSpinBox::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_SpinBox} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionSpinBox::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSpinBox::buttonSymbols     \brief the type of button symbols to draw for the spin box      The default value is QAbstractSpinBox::UpDownArrows specufying     little arrows in the classic style.      \sa QAbstractSpinBox::ButtonSymbols */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSpinBox::stepEnabled     \brief which buttons of the spin box that are enabled      The default value is QAbstractSpinBox::StepNone.      \sa QAbstractSpinBox::StepEnabled */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionSpinBox::frame     \brief whether the spin box has a frame      The default value is false, i.e. the spin box has no frame. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SPINBOX
end_comment
begin_comment
comment|/*!     \class QStyleOptionDockWidget     \brief The QStyleOptionDockWidget class is used to describe the     parameters for drawing a dock widget.      \inmodule QtWidgets       QStyleOptionDockWidget contains all the information that QStyle     functions need to draw graphical elements like QDockWidget.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionDockWidgetV2     \relates QStyleOptionDockWidget      Synonym for QStyleOptionDockWidget. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionDockWidget, initializing the member     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionDockWidget
name|QStyleOptionDockWidget
operator|::
name|QStyleOptionDockWidget
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_DockWidget
argument_list|)
member_init_list|,
name|closable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|movable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|floatable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|verticalTitleBar
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionDockWidget
name|QStyleOptionDockWidget
operator|::
name|QStyleOptionDockWidget
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_DockWidget
argument_list|)
member_init_list|,
name|closable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|movable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|floatable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|verticalTitleBar
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionDockWidget::QStyleOptionDockWidget(const QStyleOptionDockWidget&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionDockWidget::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_DockWidget} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionDockWidget::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 2      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionDockWidget::title     \brief the title of the dock window      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionDockWidget::closable     \brief whether the dock window is closable      The default value is true. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionDockWidget::movable     \brief whether the dock window is movable      The default value is false. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionDockWidget::floatable     \brief whether the dock window is floatable      The default value is true. */
end_comment
begin_comment
comment|/*!     \class QStyleOptionToolButton     \brief The QStyleOptionToolButton class is used to describe the     parameters for drawing a tool button.      \inmodule QtWidgets      QStyleOptionToolButton contains all the information that QStyle     functions need to draw QToolButton.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionComplex, QStyleOptionButton */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolButton::ToolButtonFeature     Describes the various features that a tool button can have.      \value None A normal tool button.     \value Arrow The tool button is an arrow.     \value Menu The tool button has a menu.     \value PopupDelay There is a delay to showing the menu.     \value HasMenu The button has a popup menu.     \value MenuButtonPopup The button should display an arrow to            indicate that a menu is present.      \sa features, QToolButton::toolButtonStyle(), QToolButton::popupMode() */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionToolButton, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionToolButton
name|QStyleOptionToolButton
operator|::
name|QStyleOptionToolButton
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|SO_ToolButton
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|arrowType
argument_list|(
name|Qt
operator|::
name|DownArrow
argument_list|)
member_init_list|,
name|toolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonIconOnly
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionToolButton
name|QStyleOptionToolButton
operator|::
name|QStyleOptionToolButton
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|SO_ToolButton
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|arrowType
argument_list|(
name|Qt
operator|::
name|DownArrow
argument_list|)
member_init_list|,
name|toolButtonStyle
argument_list|(
name|Qt
operator|::
name|ToolButtonIconOnly
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionToolButton::QStyleOptionToolButton(const QStyleOptionToolButton&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolButton::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_ToolButton} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolButton::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::features     \brief an OR combination of the tool button's features      The default value is \l None.      \sa ToolButtonFeature */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::icon     \brief the icon for the tool button      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename.      \sa iconSize */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::iconSize     \brief the size of the icon for the tool button      The default value is QSize(-1, -1), i.e. an invalid size. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::text     \brief the text of the tool button      This value is only used if toolButtonStyle is     Qt::ToolButtonTextUnderIcon, Qt::ToolButtonTextBesideIcon, or     Qt::ToolButtonTextOnly. The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::arrowType     \brief the direction of the arrow for the tool button      This value is only used if \l features includes \l Arrow. The     default value is Qt::DownArrow. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::toolButtonStyle     \brief a Qt::ToolButtonStyle value describing the appearance of     the tool button      The default value is Qt::ToolButtonIconOnly.      \sa QToolButton::toolButtonStyle() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::pos     \brief the position of the tool button      The default value is a null point, i.e. (0, 0) */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolButton::font     \brief the font that is used for the text      This value is only used if toolButtonStyle is     Qt::ToolButtonTextUnderIcon, Qt::ToolButtonTextBesideIcon, or     Qt::ToolButtonTextOnly. By default, the application's default font     is used. */
end_comment
begin_comment
comment|/*!     \class QStyleOptionComboBox     \brief The QStyleOptionComboBox class is used to describe the     parameter for drawing a combobox.      \inmodule QtWidgets      QStyleOptionButton contains all the information that QStyle     functions need to draw QComboBox.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionComplex, QComboBox */
end_comment
begin_comment
comment|/*!     Creates a QStyleOptionComboBox, initializing the members variables     to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionComboBox
name|QStyleOptionComboBox
operator|::
name|QStyleOptionComboBox
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|SO_ComboBox
argument_list|)
member_init_list|,
name|editable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|frame
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionComboBox
name|QStyleOptionComboBox
operator|::
name|QStyleOptionComboBox
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|SO_ComboBox
argument_list|)
member_init_list|,
name|editable
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|frame
argument_list|(
literal|true
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionComboBox::QStyleOptionComboBox(const QStyleOptionComboBox&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionComboBox::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_ComboBox} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionComboBox::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComboBox::editable     \brief whether or not the combobox is editable or not      the default     value is false      \sa QComboBox::isEditable() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComboBox::frame     \brief whether the combo box has a frame      The default value is true. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComboBox::currentText     \brief the text for the current item of the combo box      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComboBox::currentIcon     \brief the icon for the current item of the combo box      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComboBox::iconSize     \brief the icon size for the current item of the combo box      The default value is QSize(-1, -1), i.e. an invalid size. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionComboBox::popupRect     \brief the popup rectangle for the combobox      The default value is a null rectangle, i.e. a rectangle with both     the width and the height set to 0.      This variable is currently unused. You can safely ignore it.      \sa QStyle::SC_ComboBoxListBoxPopup */
end_comment
begin_comment
comment|/*!     \class QStyleOptionToolBox     \brief The QStyleOptionToolBox class is used to describe the     parameters needed for drawing a tool box.      \inmodule QtWidgets      QStyleOptionToolBox contains all the information that QStyle     functions need to draw QToolBox.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QToolBox */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionToolBoxV2     \relates QStyleOptionToolBox      Synonym for QStyleOptionToolBox. */
end_comment
begin_comment
comment|/*!     Creates a QStyleOptionToolBox, initializing the members variables     to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionToolBox
name|QStyleOptionToolBox
operator|::
name|QStyleOptionToolBox
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_ToolBox
argument_list|)
member_init_list|,
name|position
argument_list|(
name|Beginning
argument_list|)
member_init_list|,
name|selectedPosition
argument_list|(
name|NotAdjacent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionToolBox
name|QStyleOptionToolBox
operator|::
name|QStyleOptionToolBox
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_ToolBox
argument_list|)
member_init_list|,
name|position
argument_list|(
name|Beginning
argument_list|)
member_init_list|,
name|selectedPosition
argument_list|(
name|NotAdjacent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionToolBox::QStyleOptionToolBox(const QStyleOptionToolBox&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBox::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_ToolBox} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBox::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 2      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBox::icon     \brief the icon for the tool box tab     The default value is an empty icon, i.e. an icon with neither a    pixmap nor a filename. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBox::text     \brief the text for the tool box tab      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBox::SelectedPosition      This enum describes the position of the selected tab. Some styles     need to draw a tab differently depending on whether or not it is     adjacent to the selected tab.      \value NotAdjacent The tab is not adjacent to a selected tab (or is the selected tab).     \value NextIsSelected The next tab (typically the tab on the right) is selected.     \value PreviousIsSelected The previous tab (typically the tab on the left) is selected.      \sa selectedPosition */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionToolBox::TabPosition      This enum describes tab positions relative to other tabs.      \value Beginning The tab is the first (i.e., top-most) tab in            the toolbox.     \value Middle The tab is placed in the middle of the toolbox.     \value End The tab is placed at the bottom of the toolbox.     \value OnlyOneTab There is only one tab in the toolbox. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionToolBox::selectedPosition     \brief the position of the selected tab in relation to this tab      The default value is NotAdjacent, i.e. the tab is not adjacent to     a selected tab nor is it the selected tab. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_RUBBERBAND
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionRubberBand     \brief The QStyleOptionRubberBand class is used to describe the     parameters needed for drawing a rubber band.      \inmodule QtWidgets      QStyleOptionRubberBand contains all the information that     QStyle functions need to draw QRubberBand.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QRubberBand */
end_comment
begin_comment
comment|/*!     Creates a QStyleOptionRubberBand, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionRubberBand
name|QStyleOptionRubberBand
operator|::
name|QStyleOptionRubberBand
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_RubberBand
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QRubberBand
operator|::
name|Line
argument_list|)
member_init_list|,
name|opaque
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionRubberBand
name|QStyleOptionRubberBand
operator|::
name|QStyleOptionRubberBand
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_RubberBand
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QRubberBand
operator|::
name|Line
argument_list|)
member_init_list|,
name|opaque
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionRubberBand::QStyleOptionRubberBand(const QStyleOptionRubberBand&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionRubberBand::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_RubberBand} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionRubberBand::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionRubberBand::shape     \brief the shape of the rubber band      The default shape is QRubberBand::Line. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionRubberBand::opaque     \brief whether the rubber band is required to be drawn in an opaque style      The default value is true. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_RUBBERBAND
end_comment
begin_comment
comment|/*!     \class QStyleOptionTitleBar     \brief The QStyleOptionTitleBar class is used to describe the     parameters for drawing a title bar.      \inmodule QtWidgets      QStyleOptionTitleBar contains all the information that QStyle     functions need to draw the title bar of a QMdiSubWindow.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionComplex, QMdiSubWindow */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionTitleBar, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionTitleBar
name|QStyleOptionTitleBar
operator|::
name|QStyleOptionTitleBar
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|SO_TitleBar
argument_list|)
member_init_list|,
name|titleBarState
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|titleBarFlags
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionTitleBar::QStyleOptionTitleBar(const QStyleOptionTitleBar&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTitleBar::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_TitleBar} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTitleBar::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionTitleBar
name|QStyleOptionTitleBar
operator|::
name|QStyleOptionTitleBar
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|SO_TitleBar
argument_list|)
member_init_list|,
name|titleBarState
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|titleBarFlags
argument_list|(
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \variable QStyleOptionTitleBar::text     \brief the text of the title bar      The default value is an empty string. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTitleBar::icon     \brief the icon for the title bar      The default value is an empty icon, i.e. an icon with neither a     pixmap nor a filename. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTitleBar::titleBarState     \brief the state of the title bar      This is basically the window state of the underlying widget. The     default value is 0.      \sa QWidget::windowState() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTitleBar::titleBarFlags     \brief the widget flags for the title bar      The default value is Qt::Widget.      \sa Qt::WindowFlags */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ITEMVIEWS
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionViewItem     \brief The QStyleOptionViewItem class is used to describe the     parameters used to draw an item in a view widget.      \inmodule QtWidgets      QStyleOptionViewItem contains all the information that QStyle     functions need to draw the items for Qt's model/view classes.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, {model-view-programming.html}{Model/View     Programming} */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionViewItemV2     \relates QStyleOptionViewItem      Synonym for QStyleOptionViewItem. */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionViewItemV3     \relates QStyleOptionViewItem      Synonym for QStyleOptionViewItem. */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionViewItemV4     \relates QStyleOptionViewItem      Synonym for QStyleOptionViewItem. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionViewItem::Position      This enum describes the position of the item's decoration.      \value Left On the left of the text.     \value Right On the right of the text.     \value Top Above the text.     \value Bottom Below the text.      \sa decorationPosition */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::showDecorationSelected     \brief whether the decoration should be highlighted on selected     items      If this option is true, the branch and any decorations on selected items     should be highlighted, indicating that the item is selected; otherwise, no     highlighting is required. The default value is false.      \sa QStyle::SH_ItemView_ShowDecorationSelected, QAbstractItemView */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::textElideMode     \brief where ellipsis should be added for text that is too long to fit     into an item      The default value is Qt::ElideMiddle, i.e. the ellipsis appears in     the middle of the text.      \sa Qt::TextElideMode, QStyle::SH_ItemView_EllipsisLocation */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionViewItem, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionViewItem
name|QStyleOptionViewItem
operator|::
name|QStyleOptionViewItem
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_ViewItem
argument_list|)
member_init_list|,
name|displayAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|decorationAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|textElideMode
argument_list|(
name|Qt
operator|::
name|ElideMiddle
argument_list|)
member_init_list|,
name|decorationPosition
argument_list|(
name|Left
argument_list|)
member_init_list|,
name|showDecorationSelected
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|widget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|checkState
argument_list|(
name|Qt
operator|::
name|Unchecked
argument_list|)
member_init_list|,
name|viewItemPosition
argument_list|(
name|QStyleOptionViewItem
operator|::
name|Invalid
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionViewItem
name|QStyleOptionViewItem
operator|::
name|QStyleOptionViewItem
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_ViewItem
argument_list|)
member_init_list|,
name|displayAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|decorationAlignment
argument_list|(
name|Qt
operator|::
name|AlignLeft
argument_list|)
member_init_list|,
name|textElideMode
argument_list|(
name|Qt
operator|::
name|ElideMiddle
argument_list|)
member_init_list|,
name|decorationPosition
argument_list|(
name|Left
argument_list|)
member_init_list|,
name|showDecorationSelected
argument_list|(
literal|false
argument_list|)
member_init_list|,
name|features
argument_list|(
name|None
argument_list|)
member_init_list|,
name|widget
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|checkState
argument_list|(
name|Qt
operator|::
name|Unchecked
argument_list|)
member_init_list|,
name|viewItemPosition
argument_list|(
name|QStyleOptionViewItem
operator|::
name|Invalid
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionViewItem::QStyleOptionViewItem(const QStyleOptionViewItem&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionViewItem::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_ViewItem} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionViewItem::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 4      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::displayAlignment     \brief the alignment of the display value for the item      The default value is Qt::AlignLeft. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::decorationAlignment     \brief the alignment of the decoration for the item      The default value is Qt::AlignLeft. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::decorationPosition     \brief the position of the decoration for the item      The default value is \l Left.      \sa Position */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::decorationSize     \brief the size of the decoration for the item      The default value is QSize(-1, -1), i.e. an invalid size.      \sa decorationAlignment, decorationPosition */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::font     \brief the font used for the item      By default, the application's default font is used.      \sa QFont */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::features     \brief a bitwise OR of the features that describe this view item      \sa ViewItemFeature */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionViewItem::ViewItemFeature      This enum describes the different types of features an item can have.      \value None      Indicates a normal item.     \value WrapText  Indicates an item with wrapped text.     \value Alternate Indicates that the item's background is rendered using alternateBase.     \value HasCheckIndicator Indicates that the item has a check state indicator.     \value HasDisplay        Indicates that the item has a display role.     \value HasDecoration     Indicates that the item has a decoration role. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::index      The model index that is to be drawn. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::checkState      If this view item is checkable, i.e.,     ViewItemFeature::HasCheckIndicator is true, \c checkState is true     if the item is checked; otherwise, it is false.  */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::icon      The icon (if any) to be drawn in the view item. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::text      The text (if any) to be drawn in the view item. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::backgroundBrush      The QBrush that should be used to paint the view items     background. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionViewItem::viewItemPosition      Gives the position of this view item relative to other items. See     the \l{QStyleOptionViewItem::}{ViewItemPosition} enum for the     details. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionViewItem::ViewItemPosition      This enum is used to represent the placement of the item on     a row. This can be used to draw items differently depending     on their placement, for example by putting rounded edges at     the beginning and end, and straight edges in between.      \value Invalid   The ViewItemPosition is unknown and should be                      disregarded.     \value Beginning The item appears at the beginning of the row.     \value Middle    The item appears in the middle of the row.     \value End       The item appears at the end of the row.     \value OnlyOne   The item is the only one on the row, and is                      therefore both at the beginning and the end. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ITEMVIEWS
end_comment
begin_comment
comment|/*!     \fn T qstyleoption_cast<T>(const QStyleOption *option)     \relates QStyleOption      Returns a T or 0 depending on the \l{QStyleOption::type}{type} and     \l{QStyleOption::version}{version} of the given \a option.      Example:      \snippet qstyleoption/main.cpp 4      \sa QStyleOption::type, QStyleOption::version */
end_comment
begin_comment
comment|/*!     \fn T qstyleoption_cast<T>(QStyleOption *option)     \overload     \relates QStyleOption      Returns a T or 0 depending on the type of the given \a option. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABWIDGET
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionTabWidgetFrame     \brief The QStyleOptionTabWidgetFrame class is used to describe the     parameters for drawing the frame around a tab widget.      \inmodule QtWidgets      QStyleOptionTabWidgetFrame contains all the information that     QStyle functions need to draw the frame around QTabWidget.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QTabWidget */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionTabWidgetFrameV2     \relates QStyleOptionTabWidgetFrame      Synonym for QStyleOptionTabWidgetFrame. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionTabWidgetFrame, initializing the members     variables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionTabWidgetFrame
name|QStyleOptionTabWidgetFrame
operator|::
name|QStyleOptionTabWidgetFrame
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_TabWidgetFrame
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionTabWidgetFrame::QStyleOptionTabWidgetFrame(const QStyleOptionTabWidgetFrame&other)      Constructs a copy of \a other. */
end_comment
begin_comment
comment|/*! \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionTabWidgetFrame
name|QStyleOptionTabWidgetFrame
operator|::
name|QStyleOptionTabWidgetFrame
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_TabWidgetFrame
argument_list|)
member_init_list|,
name|lineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|midLineWidth
argument_list|(
literal|0
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \enum QStyleOptionTabWidgetFrame::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_TabWidgetFrame} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTabWidgetFrame::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 2      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::lineWidth     \brief the line width for drawing the panel      The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::midLineWidth     \brief the mid-line width for drawing the panel      The mid line width is usually used in drawing sunken or raised     frames. The default value is 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::shape     \brief the tab shape used to draw the tabs      The default value is QTabBar::RoundedNorth. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::tabBarSize     \brief the size of the tab bar      The default value is QSize(-1, -1), i.e. an invalid size. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::rightCornerWidgetSize     \brief the size of the right-corner widget      The default value is QSize(-1, -1), i.e. an invalid size. */
end_comment
begin_comment
comment|/*! \variable QStyleOptionTabWidgetFrame::leftCornerWidgetSize     \brief the size of the left-corner widget      The default value is QSize(-1, -1), i.e. an invalid size. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::tabBarRect     \brief the rectangle containing all the tabs      The default value is a null rectangle, i.e. a rectangle with both     the width and the height set to 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabWidgetFrame::selectedTabRect     \brief the rectangle containing the selected tab      This rectangle is contained within the tabBarRect. The default     value is a null rectangle, i.e. a rectangle with both the width     and the height set to 0. */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABWIDGET
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_TABBAR
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionTabBarBase     \brief The QStyleOptionTabBarBase class is used to describe     the base of a tab bar, i.e. the part that the tab bar usually     overlaps with.      \inmodule QtWidgets      QStyleOptionTabBarBase  contains all the information that QStyle     functions need to draw the tab bar base. Note that this is only     drawn for a standalone QTabBar (one that isn't part of a     QTabWidget).      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QTabBar::drawBase() */
end_comment
begin_comment
comment|/*!     \typedef QStyleOptionTabBarBaseV2     \relates QStyleOptionTabBarBase      Synonym for QStyleOptionTabBarBase. */
end_comment
begin_comment
comment|/*!     Construct a QStyleOptionTabBarBase, initializing the members     vaiables to their default values. */
end_comment
begin_constructor
DECL|function|QStyleOptionTabBarBase
name|QStyleOptionTabBarBase
operator|::
name|QStyleOptionTabBarBase
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|SO_TabBarBase
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
member_init_list|,
name|documentMode
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*! \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionTabBarBase
name|QStyleOptionTabBarBase
operator|::
name|QStyleOptionTabBarBase
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|SO_TabBarBase
argument_list|)
member_init_list|,
name|shape
argument_list|(
name|QTabBar
operator|::
name|RoundedNorth
argument_list|)
member_init_list|,
name|documentMode
argument_list|(
literal|false
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionTabBarBase::QStyleOptionTabBarBase(const QStyleOptionTabBarBase&other)      Constructs a copy of \a other. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTabBarBase::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_TabBarBase} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionTabBarBase::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 2      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabBarBase::shape     \brief the shape of the tab bar      The default value is QTabBar::RoundedNorth. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabBarBase::tabBarRect     \brief the rectangle containing all the tabs      The default value is a null rectangle, i.e. a rectangle with both     the width and the height set to 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabBarBase::selectedTabRect     \brief the rectangle containing the selected tab      This rectangle is contained within the tabBarRect. The default     value is a null rectangle, i.e. a rectangle with both the width     and the height set to 0. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionTabBarBase::documentMode     \brief whether the tabbar is in document mode.      The default value is false; */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_TABBAR
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SIZEGRIP
end_ifndef
begin_comment
comment|/*!     \class QStyleOptionSizeGrip     \brief The QStyleOptionSizeGrip class is used to describe the     parameter for drawing a size grip.     \since 4.2     \inmodule QtWidgets      QStyleOptionButton contains all the information that QStyle     functions need to draw QSizeGrip.      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters used by the style functions.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QStyleOptionComplex, QSizeGrip */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionSizeGrip. */
end_comment
begin_constructor
DECL|function|QStyleOptionSizeGrip
name|QStyleOptionSizeGrip
operator|::
name|QStyleOptionSizeGrip
parameter_list|()
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|Version
argument_list|,
name|Type
argument_list|)
member_init_list|,
name|corner
argument_list|(
name|Qt
operator|::
name|BottomRightCorner
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \fn QStyleOptionSizeGrip::QStyleOptionSizeGrip(const QStyleOptionSizeGrip&other)      Constructs a copy of the \a other style option. */
end_comment
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionSizeGrip
name|QStyleOptionSizeGrip
operator|::
name|QStyleOptionSizeGrip
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOptionComplex
argument_list|(
name|version
argument_list|,
name|Type
argument_list|)
member_init_list|,
name|corner
argument_list|(
name|Qt
operator|::
name|BottomRightCorner
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \variable QStyleOptionSizeGrip::corner      The corner in which the size grip is located. */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionSizeGrip::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l{SO_TabBarBase} for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionSizeGrip::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SIZEGRIP
end_comment
begin_comment
comment|/*!     \class QStyleOptionGraphicsItem     \brief The QStyleOptionGraphicsItem class is used to describe     the parameters needed to draw a QGraphicsItem.     \since 4.2     \ingroup graphicsview-api     \inmodule QtWidgets      For performance reasons, the access to the member variables is     direct (i.e., using the \c . or \c -> operator). This low-level feel     makes the structures straightforward to use and emphasizes that     these are simply parameters.      For an example demonstrating how style options can be used, see     the \l {widgets/styles}{Styles} example.      \sa QStyleOption, QGraphicsItem::paint() */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionGraphicsItem::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleOption subclass.      \value Type The type of style option provided (\l SO_GraphicsItem for this class).      The type is used internally by QStyleOption, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleOption subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleOptionGraphicsItem::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleOption subclass.      \value Version 1      The version is used by QStyleOption subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     Constructs a QStyleOptionGraphicsItem. */
end_comment
begin_constructor
DECL|function|QStyleOptionGraphicsItem
name|QStyleOptionGraphicsItem
operator|::
name|QStyleOptionGraphicsItem
parameter_list|()
member_init_list|:
name|QStyleOption
argument_list|(
name|Version
argument_list|,
name|Type
argument_list|)
member_init_list|,
name|levelOfDetail
argument_list|(
literal|1
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QStyleOptionGraphicsItem
name|QStyleOptionGraphicsItem
operator|::
name|QStyleOptionGraphicsItem
parameter_list|(
name|int
name|version
parameter_list|)
member_init_list|:
name|QStyleOption
argument_list|(
name|version
argument_list|,
name|Type
argument_list|)
member_init_list|,
name|levelOfDetail
argument_list|(
literal|1
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \since 4.6      Returns the level of detail from the \a worldTransform.      Its value represents the maximum value of the height and     width of a unity rectangle, mapped using the \a worldTransform     of the painter used to draw the item. By default, if no     transformations are applied, its value is 1. If zoomed out 1:2, the level     of detail will be 0.5, and if zoomed in 2:1, its value is 2. */
end_comment
begin_function
DECL|function|levelOfDetailFromTransform
name|qreal
name|QStyleOptionGraphicsItem
operator|::
name|levelOfDetailFromTransform
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|worldTransform
parameter_list|)
block|{
if|if
condition|(
name|worldTransform
operator|.
name|type
argument_list|()
operator|<=
name|QTransform
operator|::
name|TxTranslate
condition|)
return|return
literal|1
return|;
comment|// Translation only? The LOD is 1.
comment|// Two unit vectors.
name|QLineF
name|v1
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|QLineF
name|v2
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
decl_stmt|;
comment|// LOD is the transformed area of a 1x1 rectangle.
return|return
name|qSqrt
argument_list|(
name|worldTransform
operator|.
name|map
argument_list|(
name|v1
argument_list|)
operator|.
name|length
argument_list|()
operator|*
name|worldTransform
operator|.
name|map
argument_list|(
name|v2
argument_list|)
operator|.
name|length
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \fn QStyleOptionGraphicsItem::QStyleOptionGraphicsItem(const QStyleOptionGraphicsItem&other)      Constructs a copy of \a other. */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGraphicsItem::exposedRect     \brief the exposed rectangle, in item coordinates      Make use of this rectangle to speed up item drawing when only parts of the     item are exposed. If the whole item is exposed, this rectangle will be the     same as QGraphicsItem::boundingRect().      This member is only initialized for items that have the     QGraphicsItem::ItemUsesExtendedStyleOption flag set. */
end_comment
begin_comment
comment|/*!      \variable QStyleOptionGraphicsItem::matrix      \brief the complete transformation matrix for the item      \obsolete       The QMatrix provided through this member does include information about      any perspective transformations applied to the view or item. To get the      correct transformation matrix, use QPainter::transform() on the painter      passed into the QGraphicsItem::paint() implementation.       This matrix is the combination of the item's scene matrix and the matrix      of the painter used for drawing the item. It is provided for convenience,      allowing anvanced level-of-detail metrics that can be used to speed up      item drawing.       To find the dimensions of an item in screen coordinates (i.e., pixels),      you can use the mapping functions of QMatrix, such as QMatrix::map().       This member is only initialized for items that have the      QGraphicsItem::ItemUsesExtendedStyleOption flag set.       \sa QStyleOptionGraphicsItem::levelOfDetailFromTransform() */
end_comment
begin_comment
comment|/*!     \variable QStyleOptionGraphicsItem::levelOfDetail     \obsolete      Use QStyleOptionGraphicsItem::levelOfDetailFromTransform()     together with QPainter::worldTransform() instead. */
end_comment
begin_comment
comment|/*!     \class QStyleHintReturn     \brief The QStyleHintReturn class provides style hints that return more     than basic data types.      \ingroup appearance     \inmodule QtWidgets      QStyleHintReturn and its subclasses are used to pass information     from a style back to the querying widget. This is most useful     when the return value from QStyle::styleHint() does not provide enough     detail; for example, when a mask is to be returned.      \omit     ### --Sam     \endomit */
end_comment
begin_comment
comment|/*!     \enum QStyleHintReturn::HintReturnType      \value SH_Default QStyleHintReturn     \value SH_Mask \l QStyle::SH_RubberBand_Mask QStyle::SH_FocusFrame_Mask     \value SH_Variant \l QStyle::SH_TextControl_FocusIndicatorTextCharFormat */
end_comment
begin_comment
comment|/*!     \enum QStyleHintReturn::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleHintReturn subclass.      \value Type The type of style option provided (\l SH_Default for            this class).      The type is used internally by QStyleHintReturn, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleHintReturn subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleHintReturn::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleHintReturn subclass.      \value Version 1      The version is used by QStyleHintReturn subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \variable QStyleHintReturn::type     \brief the type of the style hint container      \sa HintReturnType */
end_comment
begin_comment
comment|/*!     \variable QStyleHintReturn::version     \brief the version of the style hint return container      This value can be used by subclasses to implement extensions     without breaking compatibility. If you use qstyleoption_cast<T>(), you     normally do not need to check it. */
end_comment
begin_comment
comment|/*!     Constructs a QStyleHintReturn with version \a version and type \a     type.      The version has no special meaning for QStyleHintReturn; it can be     used by subclasses to distinguish between different version of     the same hint type.      \sa QStyleOption::version, QStyleOption::type */
end_comment
begin_constructor
DECL|function|QStyleHintReturn
name|QStyleHintReturn
operator|::
name|QStyleHintReturn
parameter_list|(
name|int
name|version
parameter_list|,
name|int
name|type
parameter_list|)
member_init_list|:
name|version
argument_list|(
name|version
argument_list|)
member_init_list|,
name|type
argument_list|(
name|type
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QStyleHintReturn
name|QStyleHintReturn
operator|::
name|~
name|QStyleHintReturn
parameter_list|()
block|{  }
end_destructor
begin_comment
comment|/*!     \class QStyleHintReturnMask     \brief The QStyleHintReturnMask class provides style hints that return a QRegion.      \ingroup appearance     \inmodule QtWidgets      \omit     ### --Sam     \endomit */
end_comment
begin_comment
comment|/*!     \variable QStyleHintReturnMask::region     \brief the region for style hints that return a QRegion */
end_comment
begin_comment
comment|/*!     Constructs a QStyleHintReturnMask. The member variables are     initialized to default values. */
end_comment
begin_constructor
DECL|function|QStyleHintReturnMask
name|QStyleHintReturnMask
operator|::
name|QStyleHintReturnMask
parameter_list|()
member_init_list|:
name|QStyleHintReturn
argument_list|(
name|Version
argument_list|,
name|Type
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destructor. */
end_comment
begin_destructor
DECL|function|~QStyleHintReturnMask
name|QStyleHintReturnMask
operator|::
name|~
name|QStyleHintReturnMask
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \enum QStyleHintReturnMask::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleHintReturn subclass.      \value Type The type of style option provided (\l{SH_Mask} for            this class).      The type is used internally by QStyleHintReturn, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleHintReturn subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleHintReturnMask::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleHintReturn subclass.      \value Version 1      The version is used by QStyleHintReturn subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \class QStyleHintReturnVariant     \brief The QStyleHintReturnVariant class provides style hints that return a QVariant.     \since 4.3     \ingroup appearance     \inmodule QtWidgets */
end_comment
begin_comment
comment|/*!     \variable QStyleHintReturnVariant::variant     \brief the variant for style hints that return a QVariant */
end_comment
begin_comment
comment|/*!     Constructs a QStyleHintReturnVariant. The member variables are     initialized to default values. */
end_comment
begin_constructor
DECL|function|QStyleHintReturnVariant
name|QStyleHintReturnVariant
operator|::
name|QStyleHintReturnVariant
parameter_list|()
member_init_list|:
name|QStyleHintReturn
argument_list|(
name|Version
argument_list|,
name|Type
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destructor. */
end_comment
begin_destructor
DECL|function|~QStyleHintReturnVariant
name|QStyleHintReturnVariant
operator|::
name|~
name|QStyleHintReturnVariant
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \enum QStyleHintReturnVariant::StyleOptionType      This enum is used to hold information about the type of the style option, and     is defined for each QStyleHintReturn subclass.      \value Type The type of style option provided (\l{SH_Variant} for            this class).      The type is used internally by QStyleHintReturn, its subclasses, and     qstyleoption_cast() to determine the type of style option. In     general you do not need to worry about this unless you want to     create your own QStyleHintReturn subclass and your own styles.      \sa StyleOptionVersion */
end_comment
begin_comment
comment|/*!     \enum QStyleHintReturnVariant::StyleOptionVersion      This enum is used to hold information about the version of the style option, and     is defined for each QStyleHintReturn subclass.      \value Version 1      The version is used by QStyleHintReturn subclasses to implement     extensions without breaking compatibility. If you use     qstyleoption_cast(), you normally do not need to check it.      \sa StyleOptionType */
end_comment
begin_comment
comment|/*!     \fn T qstyleoption_cast<T>(const QStyleHintReturn *hint)     \relates QStyleHintReturn      Returns a T or 0 depending on the \l{QStyleHintReturn::type}{type}     and \l{QStyleHintReturn::version}{version} of \a hint.      Example:      \snippet code/src_gui_styles_qstyleoption.cpp 0      \sa QStyleHintReturn::type, QStyleHintReturn::version */
end_comment
begin_comment
comment|/*!     \fn T qstyleoption_cast<T>(QStyleHintReturn *hint)     \overload     \relates QStyleHintReturn      Returns a T or 0 depending on the type of \a hint. */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG_STREAM
argument_list|)
end_if
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QStyleOption
operator|::
name|OptionType
modifier|&
name|optionType
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
switch|switch
condition|(
name|optionType
condition|)
block|{
case|case
name|QStyleOption
operator|::
name|SO_Default
case|:
name|debug
operator|<<
literal|"SO_Default"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_FocusRect
case|:
name|debug
operator|<<
literal|"SO_FocusRect"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_Button
case|:
name|debug
operator|<<
literal|"SO_Button"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_Tab
case|:
name|debug
operator|<<
literal|"SO_Tab"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_MenuItem
case|:
name|debug
operator|<<
literal|"SO_MenuItem"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_Frame
case|:
name|debug
operator|<<
literal|"SO_Frame"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ProgressBar
case|:
name|debug
operator|<<
literal|"SO_ProgressBar"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ToolBox
case|:
name|debug
operator|<<
literal|"SO_ToolBox"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_Header
case|:
name|debug
operator|<<
literal|"SO_Header"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_DockWidget
case|:
name|debug
operator|<<
literal|"SO_DockWidget"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ViewItem
case|:
name|debug
operator|<<
literal|"SO_ViewItem"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_TabWidgetFrame
case|:
name|debug
operator|<<
literal|"SO_TabWidgetFrame"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_TabBarBase
case|:
name|debug
operator|<<
literal|"SO_TabBarBase"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_RubberBand
case|:
name|debug
operator|<<
literal|"SO_RubberBand"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_Complex
case|:
name|debug
operator|<<
literal|"SO_Complex"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_Slider
case|:
name|debug
operator|<<
literal|"SO_Slider"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_SpinBox
case|:
name|debug
operator|<<
literal|"SO_SpinBox"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ToolButton
case|:
name|debug
operator|<<
literal|"SO_ToolButton"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ComboBox
case|:
name|debug
operator|<<
literal|"SO_ComboBox"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_TitleBar
case|:
name|debug
operator|<<
literal|"SO_TitleBar"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_CustomBase
case|:
name|debug
operator|<<
literal|"SO_CustomBase"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_GroupBox
case|:
name|debug
operator|<<
literal|"SO_GroupBox"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ToolBar
case|:
name|debug
operator|<<
literal|"SO_ToolBar"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_ComplexCustomBase
case|:
name|debug
operator|<<
literal|"SO_ComplexCustomBase"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_SizeGrip
case|:
name|debug
operator|<<
literal|"SO_SizeGrip"
expr_stmt|;
break|break;
case|case
name|QStyleOption
operator|::
name|SO_GraphicsItem
case|:
name|debug
operator|<<
literal|"SO_GraphicsItem"
expr_stmt|;
break|break;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|optionType
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|debug
return|;
block|}
end_function
begin_function
DECL|function|operator <<
name|QDebug
name|operator
name|<<
parameter_list|(
name|QDebug
name|debug
parameter_list|,
specifier|const
name|QStyleOption
modifier|&
name|option
parameter_list|)
block|{
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_DEBUG
argument_list|)
name|debug
operator|<<
literal|"QStyleOption("
expr_stmt|;
name|debug
operator|<<
name|QStyleOption
operator|::
name|OptionType
argument_list|(
name|option
operator|.
name|type
argument_list|)
expr_stmt|;
name|debug
operator|<<
literal|','
operator|<<
operator|(
name|option
operator|.
name|direction
operator|==
name|Qt
operator|::
name|RightToLeft
condition|?
literal|"RightToLeft"
else|:
literal|"LeftToRight"
operator|)
expr_stmt|;
name|debug
operator|<<
literal|','
operator|<<
name|option
operator|.
name|state
expr_stmt|;
name|debug
operator|<<
literal|','
operator|<<
name|option
operator|.
name|rect
expr_stmt|;
name|debug
operator|<<
literal|','
operator|<<
name|option
operator|.
name|styleObject
expr_stmt|;
name|debug
operator|<<
literal|')'
expr_stmt|;
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|option
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|debug
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
