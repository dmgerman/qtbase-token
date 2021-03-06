begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qscrollarea.h"
end_include
begin_include
include|#
directive|include
file|"private/qscrollarea_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_SCROLLAREA
end_ifndef
begin_include
include|#
directive|include
file|"qscrollbar.h"
end_include
begin_include
include|#
directive|include
file|"qlayout.h"
end_include
begin_include
include|#
directive|include
file|"qstyle.h"
end_include
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_include
include|#
directive|include
file|"qvariant.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_include
include|#
directive|include
file|"private/qlayoutengine_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QScrollArea      \brief The QScrollArea class provides a scrolling view onto     another widget.      \ingroup basicwidgets     \inmodule QtWidgets      A scroll area is used to display the contents of a child widget     within a frame. If the widget exceeds the size of the frame, the     view can provide scroll bars so that the entire area of the child     widget can be viewed. The child widget must be specified with     setWidget(). For example:      \snippet code/src_gui_widgets_qscrollarea.cpp 0      The code above creates a scroll area (shown in the images below)     containing an image label. When scaling the image, the scroll area     can provide the necessary scroll bars:      \table     \row     \li \inlineimage qscrollarea-noscrollbars.png     \li \inlineimage qscrollarea-onescrollbar.png     \li \inlineimage qscrollarea-twoscrollbars.png     \endtable      The scroll bars appearance depends on the currently set \l     {Qt::ScrollBarPolicy}{scroll bar policies}. You can control the     appearance of the scroll bars using the inherited functionality     from QAbstractScrollArea.      For example, you can set the     QAbstractScrollArea::horizontalScrollBarPolicy and     QAbstractScrollArea::verticalScrollBarPolicy properties. Or if you     want the scroll bars to adjust dynamically when the contents of     the scroll area changes, you can use the \l     {QAbstractScrollArea::horizontalScrollBar()}{horizontalScrollBar()}     and \l     {QAbstractScrollArea::verticalScrollBar()}{verticalScrollBar()}     functions (which enable you to access the scroll bars) and set the     scroll bars' values whenever the scroll area's contents change,     using the QScrollBar::setValue() function.      You can retrieve the child widget using the widget() function. The     view can be made to be resizable with the setWidgetResizable()     function. The alignment of the widget can be specified with     setAlignment().      Two convenience functions ensureVisible() and     ensureWidgetVisible() ensure a certain region of the contents is     visible inside the viewport, by scrolling the contents if     necessary.      \section1 Size Hints and Layouts      When using a scroll area to display the contents of a custom     widget, it is important to ensure that the     \l{QWidget::sizeHint}{size hint} of the child widget is set to a     suitable value. If a standard QWidget is used for the child     widget, it may be necessary to call QWidget::setMinimumSize() to     ensure that the contents of the widget are shown correctly within     the scroll area.      If a scroll area is used to display the contents of a widget that     contains child widgets arranged in a layout, it is important to     realize that the size policy of the layout will also determine the     size of the widget. This is especially useful to know if you intend     to dynamically change the contents of the layout. In such cases,     setting the layout's \l{QLayout::sizeConstraint}{size constraint}     property to one which provides constraints on the minimum and/or     maximum size of the layout (e.g., QLayout::SetMinAndMaxSize) will     cause the size of the scroll area to be updated whenever the     contents of the layout changes.      For a complete example using the QScrollArea class, see the \l     {widgets/imageviewer}{Image Viewer} example. The example shows how     to combine QLabel and QScrollArea to display an image.      \sa QAbstractScrollArea, QScrollBar, {Image Viewer Example} */
end_comment
begin_comment
comment|/*!     Constructs an empty scroll area with the given \a parent.      \sa setWidget() */
end_comment
begin_constructor
DECL|function|QScrollArea
name|QScrollArea
operator|::
name|QScrollArea
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractScrollArea
argument_list|(
operator|*
operator|new
name|QScrollAreaPrivate
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|d
operator|->
name|viewport
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|NoRole
argument_list|)
expr_stmt|;
name|d
operator|->
name|vbar
operator|->
name|setSingleStep
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|d
operator|->
name|hbar
operator|->
name|setSingleStep
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|d
operator|->
name|layoutChildren
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QScrollArea
name|QScrollArea
operator|::
name|QScrollArea
parameter_list|(
name|QScrollAreaPrivate
modifier|&
name|dd
parameter_list|,
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAbstractScrollArea
argument_list|(
name|dd
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|d
operator|->
name|viewport
operator|->
name|setBackgroundRole
argument_list|(
name|QPalette
operator|::
name|NoRole
argument_list|)
expr_stmt|;
name|d
operator|->
name|vbar
operator|->
name|setSingleStep
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|d
operator|->
name|hbar
operator|->
name|setSingleStep
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|d
operator|->
name|layoutChildren
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the scroll area and its child widget.      \sa setWidget() */
end_comment
begin_destructor
DECL|function|~QScrollArea
name|QScrollArea
operator|::
name|~
name|QScrollArea
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|updateWidgetPosition
name|void
name|QScrollAreaPrivate
operator|::
name|updateWidgetPosition
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|dir
init|=
name|q
operator|->
name|layoutDirection
argument_list|()
decl_stmt|;
name|QRect
name|scrolled
init|=
name|QStyle
operator|::
name|visualRect
argument_list|(
name|dir
argument_list|,
name|viewport
operator|->
name|rect
argument_list|()
argument_list|,
name|QRect
argument_list|(
name|QPoint
argument_list|(
operator|-
name|hbar
operator|->
name|value
argument_list|()
argument_list|,
operator|-
name|vbar
operator|->
name|value
argument_list|()
argument_list|)
argument_list|,
name|widget
operator|->
name|size
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
name|QRect
name|aligned
init|=
name|QStyle
operator|::
name|alignedRect
argument_list|(
name|dir
argument_list|,
name|alignment
argument_list|,
name|widget
operator|->
name|size
argument_list|()
argument_list|,
name|viewport
operator|->
name|rect
argument_list|()
argument_list|)
decl_stmt|;
name|widget
operator|->
name|move
argument_list|(
name|widget
operator|->
name|width
argument_list|()
operator|<
name|viewport
operator|->
name|width
argument_list|()
condition|?
name|aligned
operator|.
name|x
argument_list|()
else|:
name|scrolled
operator|.
name|x
argument_list|()
argument_list|,
name|widget
operator|->
name|height
argument_list|()
operator|<
name|viewport
operator|->
name|height
argument_list|()
condition|?
name|aligned
operator|.
name|y
argument_list|()
else|:
name|scrolled
operator|.
name|y
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|updateScrollBars
name|void
name|QScrollAreaPrivate
operator|::
name|updateScrollBars
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
name|QSize
name|p
init|=
name|viewport
operator|->
name|size
argument_list|()
decl_stmt|;
name|QSize
name|m
init|=
name|q
operator|->
name|maximumViewportSize
argument_list|()
decl_stmt|;
name|QSize
name|min
init|=
name|qSmartMinSize
argument_list|(
name|widget
argument_list|)
decl_stmt|;
name|QSize
name|max
init|=
name|qSmartMaxSize
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|resizable
condition|)
block|{
if|if
condition|(
operator|(
name|widget
operator|->
name|layout
argument_list|()
condition|?
name|widget
operator|->
name|layout
argument_list|()
operator|->
name|hasHeightForWidth
argument_list|()
else|:
name|widget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
operator|)
condition|)
block|{
name|QSize
name|p_hfw
init|=
name|p
operator|.
name|expandedTo
argument_list|(
name|min
argument_list|)
operator|.
name|boundedTo
argument_list|(
name|max
argument_list|)
decl_stmt|;
name|int
name|h
init|=
name|widget
operator|->
name|heightForWidth
argument_list|(
name|p_hfw
operator|.
name|width
argument_list|()
argument_list|)
decl_stmt|;
name|min
operator|=
name|QSize
argument_list|(
name|p_hfw
operator|.
name|width
argument_list|()
argument_list|,
name|qMax
argument_list|(
name|p_hfw
operator|.
name|height
argument_list|()
argument_list|,
name|h
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|resizable
operator|&&
name|m
operator|.
name|expandedTo
argument_list|(
name|min
argument_list|)
operator|==
name|m
operator|&&
name|m
operator|.
name|boundedTo
argument_list|(
name|max
argument_list|)
operator|==
name|m
operator|)
operator|||
operator|(
operator|!
name|resizable
operator|&&
name|m
operator|.
name|expandedTo
argument_list|(
name|widget
operator|->
name|size
argument_list|()
argument_list|)
operator|==
name|m
operator|)
condition|)
name|p
operator|=
name|m
expr_stmt|;
comment|// no scroll bars needed
if|if
condition|(
name|resizable
condition|)
name|widget
operator|->
name|resize
argument_list|(
name|p
operator|.
name|expandedTo
argument_list|(
name|min
argument_list|)
operator|.
name|boundedTo
argument_list|(
name|max
argument_list|)
argument_list|)
expr_stmt|;
name|QSize
name|v
init|=
name|widget
operator|->
name|size
argument_list|()
decl_stmt|;
name|hbar
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
name|v
operator|.
name|width
argument_list|()
operator|-
name|p
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|hbar
operator|->
name|setPageStep
argument_list|(
name|p
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
name|vbar
operator|->
name|setRange
argument_list|(
literal|0
argument_list|,
name|v
operator|.
name|height
argument_list|()
operator|-
name|p
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|vbar
operator|->
name|setPageStep
argument_list|(
name|p
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
name|updateWidgetPosition
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the scroll area's widget, or 0 if there is none.      \sa setWidget() */
end_comment
begin_function
DECL|function|widget
name|QWidget
modifier|*
name|QScrollArea
operator|::
name|widget
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScrollArea
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|widget
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QScrollArea::setWidget(QWidget *widget)      Sets the scroll area's \a widget.      The \a widget becomes a child of the scroll area, and will be     destroyed when the scroll area is deleted or when a new widget is     set.      The widget's \l{QWidget::setAutoFillBackground()}{autoFillBackground}     property will be set to \c{true}.      If the scroll area is visible when the \a widget is     added, you must \l{QWidget::}{show()} it explicitly.      Note that You must add the layout of \a widget before you call     this function; if you add it later, the \a widget will not be     visible - regardless of when you \l{QWidget::}{show()} the scroll     area. In this case, you can also not \l{QWidget::}{show()} the \a     widget later.      \sa widget() */
end_comment
begin_function
DECL|function|setWidget
name|void
name|QScrollArea
operator|::
name|setWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
operator|==
name|d
operator|->
name|widget
operator|||
operator|!
name|widget
condition|)
return|return;
operator|delete
name|d
operator|->
name|widget
expr_stmt|;
name|d
operator|->
name|widget
operator|=
literal|0
expr_stmt|;
name|d
operator|->
name|hbar
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|vbar
operator|->
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|parentWidget
argument_list|()
operator|!=
name|d
operator|->
name|viewport
condition|)
name|widget
operator|->
name|setParent
argument_list|(
name|d
operator|->
name|viewport
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Resized
argument_list|)
condition|)
name|widget
operator|->
name|resize
argument_list|(
name|widget
operator|->
name|sizeHint
argument_list|()
argument_list|)
expr_stmt|;
name|d
operator|->
name|widget
operator|=
name|widget
expr_stmt|;
name|d
operator|->
name|widget
operator|->
name|setAutoFillBackground
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|widget
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|d
operator|->
name|widgetSize
operator|=
name|QSize
argument_list|()
expr_stmt|;
name|d
operator|->
name|updateScrollBars
argument_list|()
expr_stmt|;
name|d
operator|->
name|widget
operator|->
name|show
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the scroll area's widget, and passes ownership of the     widget to the caller.      \sa widget()  */
end_comment
begin_function
DECL|function|takeWidget
name|QWidget
modifier|*
name|QScrollArea
operator|::
name|takeWidget
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|d
operator|->
name|widget
decl_stmt|;
name|d
operator|->
name|widget
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|w
condition|)
name|w
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|event
name|bool
name|QScrollArea
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|StyleChange
operator|||
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
name|d
operator|->
name|updateScrollBars
argument_list|()
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
elseif|else
if|if
condition|(
name|QApplication
operator|::
name|keypadNavigationEnabled
argument_list|()
condition|)
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
name|Show
condition|)
name|QApplication
operator|::
name|instance
argument_list|()
operator|->
name|installEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Hide
condition|)
name|QApplication
operator|::
name|instance
argument_list|()
operator|->
name|removeEventFilter
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|QAbstractScrollArea
operator|::
name|event
argument_list|(
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|eventFilter
name|bool
name|QScrollArea
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|o
parameter_list|,
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
if|if
condition|(
name|d
operator|->
name|widget
operator|&&
name|o
operator|!=
name|d
operator|->
name|widget
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|FocusIn
operator|&&
name|QApplication
operator|::
name|keypadNavigationEnabled
argument_list|()
condition|)
block|{
if|if
condition|(
name|o
operator|->
name|isWidgetType
argument_list|()
condition|)
name|ensureWidgetVisible
argument_list|(
cast|static_cast
argument_list|<
name|QWidget
operator|*
argument_list|>
argument_list|(
name|o
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
if|if
condition|(
name|o
operator|==
name|d
operator|->
name|widget
operator|&&
name|e
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|Resize
condition|)
name|d
operator|->
name|updateScrollBars
argument_list|()
expr_stmt|;
return|return
name|QAbstractScrollArea
operator|::
name|eventFilter
argument_list|(
name|o
argument_list|,
name|e
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|resizeEvent
name|void
name|QScrollArea
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|d
operator|->
name|updateScrollBars
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!\reimp  */
end_comment
begin_function
DECL|function|scrollContentsBy
name|void
name|QScrollArea
operator|::
name|scrollContentsBy
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|widget
condition|)
return|return;
name|d
operator|->
name|updateWidgetPosition
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QScrollArea::widgetResizable     \brief whether the scroll area should resize the view widget      If this property is set to false (the default), the scroll area     honors the size of its widget. Regardless of this property, you     can programmatically resize the widget using widget()->resize(),     and the scroll area will automatically adjust itself to the new     size.      If this property is set to true, the scroll area will     automatically resize the widget in order to avoid scroll bars     where they can be avoided, or to take advantage of extra space. */
end_comment
begin_function
DECL|function|widgetResizable
name|bool
name|QScrollArea
operator|::
name|widgetResizable
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScrollArea
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|resizable
return|;
block|}
end_function
begin_function
DECL|function|setWidgetResizable
name|void
name|QScrollArea
operator|::
name|setWidgetResizable
parameter_list|(
name|bool
name|resizable
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|d
operator|->
name|resizable
operator|=
name|resizable
expr_stmt|;
name|updateGeometry
argument_list|()
expr_stmt|;
name|d
operator|->
name|updateScrollBars
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QScrollArea
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScrollArea
argument_list|)
expr_stmt|;
name|int
name|f
init|=
literal|2
operator|*
name|d
operator|->
name|frameWidth
decl_stmt|;
name|QSize
name|sz
argument_list|(
name|f
argument_list|,
name|f
argument_list|)
decl_stmt|;
name|int
name|h
init|=
name|fontMetrics
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|widget
condition|)
block|{
if|if
condition|(
operator|!
name|d
operator|->
name|widgetSize
operator|.
name|isValid
argument_list|()
condition|)
name|d
operator|->
name|widgetSize
operator|=
name|d
operator|->
name|resizable
condition|?
name|d
operator|->
name|widget
operator|->
name|sizeHint
argument_list|()
else|:
name|d
operator|->
name|widget
operator|->
name|size
argument_list|()
expr_stmt|;
name|sz
operator|+=
name|d
operator|->
name|widgetSize
expr_stmt|;
block|}
else|else
block|{
name|sz
operator|+=
name|QSize
argument_list|(
literal|12
operator|*
name|h
argument_list|,
literal|8
operator|*
name|h
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|d
operator|->
name|vbarpolicy
operator|==
name|Qt
operator|::
name|ScrollBarAlwaysOn
condition|)
name|sz
operator|.
name|setWidth
argument_list|(
name|sz
operator|.
name|width
argument_list|()
operator|+
name|d
operator|->
name|vbar
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|hbarpolicy
operator|==
name|Qt
operator|::
name|ScrollBarAlwaysOn
condition|)
name|sz
operator|.
name|setHeight
argument_list|(
name|sz
operator|.
name|height
argument_list|()
operator|+
name|d
operator|->
name|hbar
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|sz
operator|.
name|boundedTo
argument_list|(
name|QSize
argument_list|(
literal|36
operator|*
name|h
argument_list|,
literal|24
operator|*
name|h
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|viewportSizeHint
name|QSize
name|QScrollArea
operator|::
name|viewportSizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScrollArea
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|widget
condition|)
block|{
return|return
name|d
operator|->
name|resizable
condition|?
name|d
operator|->
name|widget
operator|->
name|sizeHint
argument_list|()
else|:
name|d
operator|->
name|widget
operator|->
name|size
argument_list|()
return|;
block|}
specifier|const
name|int
name|h
init|=
name|fontMetrics
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
return|return
name|QSize
argument_list|(
literal|6
operator|*
name|h
argument_list|,
literal|4
operator|*
name|h
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|focusNextPrevChild
name|bool
name|QScrollArea
operator|::
name|focusNextPrevChild
parameter_list|(
name|bool
name|next
parameter_list|)
block|{
if|if
condition|(
name|QWidget
operator|::
name|focusNextPrevChild
argument_list|(
name|next
argument_list|)
condition|)
block|{
if|if
condition|(
name|QWidget
modifier|*
name|fw
init|=
name|focusWidget
argument_list|()
condition|)
name|ensureWidgetVisible
argument_list|(
name|fw
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Scrolls the contents of the scroll area so that the point (\a x, \a y) is visible     inside the region of the viewport with margins specified in pixels by \a xmargin and     \a ymargin. If the specified point cannot be reached, the contents are scrolled to     the nearest valid position. The default value for both margins is 50 pixels. */
end_comment
begin_function
DECL|function|ensureVisible
name|void
name|QScrollArea
operator|::
name|ensureVisible
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|xmargin
parameter_list|,
name|int
name|ymargin
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|int
name|logicalX
init|=
name|QStyle
operator|::
name|visualPos
argument_list|(
name|layoutDirection
argument_list|()
argument_list|,
name|d
operator|->
name|viewport
operator|->
name|rect
argument_list|()
argument_list|,
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
operator|.
name|x
argument_list|()
decl_stmt|;
if|if
condition|(
name|logicalX
operator|-
name|xmargin
operator|<
name|d
operator|->
name|hbar
operator|->
name|value
argument_list|()
condition|)
block|{
name|d
operator|->
name|hbar
operator|->
name|setValue
argument_list|(
name|qMax
argument_list|(
literal|0
argument_list|,
name|logicalX
operator|-
name|xmargin
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|logicalX
operator|>
name|d
operator|->
name|hbar
operator|->
name|value
argument_list|()
operator|+
name|d
operator|->
name|viewport
operator|->
name|width
argument_list|()
operator|-
name|xmargin
condition|)
block|{
name|d
operator|->
name|hbar
operator|->
name|setValue
argument_list|(
name|qMin
argument_list|(
name|logicalX
operator|-
name|d
operator|->
name|viewport
operator|->
name|width
argument_list|()
operator|+
name|xmargin
argument_list|,
name|d
operator|->
name|hbar
operator|->
name|maximum
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|y
operator|-
name|ymargin
operator|<
name|d
operator|->
name|vbar
operator|->
name|value
argument_list|()
condition|)
block|{
name|d
operator|->
name|vbar
operator|->
name|setValue
argument_list|(
name|qMax
argument_list|(
literal|0
argument_list|,
name|y
operator|-
name|ymargin
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|y
operator|>
name|d
operator|->
name|vbar
operator|->
name|value
argument_list|()
operator|+
name|d
operator|->
name|viewport
operator|->
name|height
argument_list|()
operator|-
name|ymargin
condition|)
block|{
name|d
operator|->
name|vbar
operator|->
name|setValue
argument_list|(
name|qMin
argument_list|(
name|y
operator|-
name|d
operator|->
name|viewport
operator|->
name|height
argument_list|()
operator|+
name|ymargin
argument_list|,
name|d
operator|->
name|vbar
operator|->
name|maximum
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \since 4.2      Scrolls the contents of the scroll area so that the \a childWidget     of QScrollArea::widget() is visible inside the viewport with     margins specified in pixels by \a xmargin and \a ymargin. If the     specified point cannot be reached, the contents are scrolled to     the nearest valid position. The default value for both margins is     50 pixels.  */
end_comment
begin_function
DECL|function|ensureWidgetVisible
name|void
name|QScrollArea
operator|::
name|ensureWidgetVisible
parameter_list|(
name|QWidget
modifier|*
name|childWidget
parameter_list|,
name|int
name|xmargin
parameter_list|,
name|int
name|ymargin
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|widget
operator|->
name|isAncestorOf
argument_list|(
name|childWidget
argument_list|)
condition|)
return|return;
specifier|const
name|QRect
name|microFocus
init|=
name|childWidget
operator|->
name|inputMethodQuery
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
operator|.
name|toRect
argument_list|()
decl_stmt|;
specifier|const
name|QRect
name|defaultMicroFocus
init|=
name|childWidget
operator|->
name|QWidget
operator|::
name|inputMethodQuery
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
operator|.
name|toRect
argument_list|()
decl_stmt|;
name|QRect
name|focusRect
init|=
operator|(
name|microFocus
operator|!=
name|defaultMicroFocus
operator|)
condition|?
name|QRect
argument_list|(
name|childWidget
operator|->
name|mapTo
argument_list|(
name|d
operator|->
name|widget
argument_list|,
name|microFocus
operator|.
name|topLeft
argument_list|()
argument_list|)
argument_list|,
name|microFocus
operator|.
name|size
argument_list|()
argument_list|)
else|:
name|QRect
argument_list|(
name|childWidget
operator|->
name|mapTo
argument_list|(
name|d
operator|->
name|widget
argument_list|,
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
argument_list|)
argument_list|,
name|childWidget
operator|->
name|size
argument_list|()
argument_list|)
decl_stmt|;
specifier|const
name|QRect
name|visibleRect
argument_list|(
operator|-
name|d
operator|->
name|widget
operator|->
name|pos
argument_list|()
argument_list|,
name|d
operator|->
name|viewport
operator|->
name|size
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|visibleRect
operator|.
name|contains
argument_list|(
name|focusRect
argument_list|)
condition|)
return|return;
name|focusRect
operator|.
name|adjust
argument_list|(
operator|-
name|xmargin
argument_list|,
operator|-
name|ymargin
argument_list|,
name|xmargin
argument_list|,
name|ymargin
argument_list|)
expr_stmt|;
if|if
condition|(
name|focusRect
operator|.
name|width
argument_list|()
operator|>
name|visibleRect
operator|.
name|width
argument_list|()
condition|)
name|d
operator|->
name|hbar
operator|->
name|setValue
argument_list|(
name|focusRect
operator|.
name|center
argument_list|()
operator|.
name|x
argument_list|()
operator|-
name|d
operator|->
name|viewport
operator|->
name|width
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|focusRect
operator|.
name|right
argument_list|()
operator|>
name|visibleRect
operator|.
name|right
argument_list|()
condition|)
name|d
operator|->
name|hbar
operator|->
name|setValue
argument_list|(
name|focusRect
operator|.
name|right
argument_list|()
operator|-
name|d
operator|->
name|viewport
operator|->
name|width
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|focusRect
operator|.
name|left
argument_list|()
operator|<
name|visibleRect
operator|.
name|left
argument_list|()
condition|)
name|d
operator|->
name|hbar
operator|->
name|setValue
argument_list|(
name|focusRect
operator|.
name|left
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|focusRect
operator|.
name|height
argument_list|()
operator|>
name|visibleRect
operator|.
name|height
argument_list|()
condition|)
name|d
operator|->
name|vbar
operator|->
name|setValue
argument_list|(
name|focusRect
operator|.
name|center
argument_list|()
operator|.
name|y
argument_list|()
operator|-
name|d
operator|->
name|viewport
operator|->
name|height
argument_list|()
operator|/
literal|2
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|focusRect
operator|.
name|bottom
argument_list|()
operator|>
name|visibleRect
operator|.
name|bottom
argument_list|()
condition|)
name|d
operator|->
name|vbar
operator|->
name|setValue
argument_list|(
name|focusRect
operator|.
name|bottom
argument_list|()
operator|-
name|d
operator|->
name|viewport
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|focusRect
operator|.
name|top
argument_list|()
operator|<
name|visibleRect
operator|.
name|top
argument_list|()
condition|)
name|d
operator|->
name|vbar
operator|->
name|setValue
argument_list|(
name|focusRect
operator|.
name|top
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QScrollArea::alignment     \brief the alignment of the scroll area's widget     \since 4.2      A valid alignment is a combination of the following flags:     \list     \li \c Qt::AlignLeft     \li \c Qt::AlignHCenter     \li \c Qt::AlignRight     \li \c Qt::AlignTop     \li \c Qt::AlignVCenter     \li \c Qt::AlignBottom     \endlist     By default, the widget stays rooted to the top-left corner of the     scroll area. */
end_comment
begin_function
DECL|function|setAlignment
name|void
name|QScrollArea
operator|::
name|setAlignment
parameter_list|(
name|Qt
operator|::
name|Alignment
name|alignment
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QScrollArea
argument_list|)
expr_stmt|;
name|d
operator|->
name|alignment
operator|=
name|alignment
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|widget
condition|)
name|d
operator|->
name|updateWidgetPosition
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|alignment
name|Qt
operator|::
name|Alignment
name|QScrollArea
operator|::
name|alignment
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QScrollArea
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|alignment
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qscrollarea.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_SCROLLAREA
end_comment
end_unit
