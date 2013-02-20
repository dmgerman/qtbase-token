begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstackedlayout.h"
end_include
begin_include
include|#
directive|include
file|"qlayout_p.h"
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qwidget.h>
end_include
begin_include
include|#
directive|include
file|"private/qlayoutengine_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QStackedLayoutPrivate
class|class
name|QStackedLayoutPrivate
super|:
specifier|public
name|QLayoutPrivate
block|{
name|Q_DECLARE_PUBLIC
parameter_list|(
name|QStackedLayout
parameter_list|)
specifier|public
private|:
DECL|function|QStackedLayoutPrivate
name|QStackedLayoutPrivate
parameter_list|()
member_init_list|:
name|index
argument_list|(
operator|-
literal|1
argument_list|)
member_init_list|,
name|stackingMode
argument_list|(
name|QStackedLayout
operator|::
name|StackOne
argument_list|)
block|{}
DECL|member|list
name|QList
argument_list|<
name|QLayoutItem
modifier|*
argument_list|>
name|list
decl_stmt|;
DECL|member|index
name|int
name|index
decl_stmt|;
DECL|member|stackingMode
name|QStackedLayout
operator|::
name|StackingMode
name|stackingMode
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|/*!     \class QStackedLayout      \brief The QStackedLayout class provides a stack of widgets where     only one widget is visible at a time.      \ingroup geomanagement     \inmodule QtWidgets      QStackedLayout can be used to create a user interface similar to     the one provided by QTabWidget. There is also a convenience     QStackedWidget class built on top of QStackedLayout.      A QStackedLayout can be populated with a number of child widgets     ("pages"). For example:      \snippet qstackedlayout/main.cpp 0     \codeline     \snippet qstackedlayout/main.cpp 2     \snippet qstackedlayout/main.cpp 3      QStackedLayout provides no intrinsic means for the user to switch     page. This is typically done through a QComboBox or a QListWidget     that stores the titles of the QStackedLayout's pages. For     example:      \snippet qstackedlayout/main.cpp 1      When populating a layout, the widgets are added to an internal     list. The indexOf() function returns the index of a widget in that     list. The widgets can either be added to the end of the list using     the addWidget() function, or inserted at a given index using the     insertWidget() function. The removeWidget() function removes the     widget at the given index from the layout. The number of widgets     contained in the layout, can be obtained using the count()     function.      The widget() function returns the widget at a given index     position. The index of the widget that is shown on screen is given     by currentIndex() and can be changed using setCurrentIndex(). In a     similar manner, the currently shown widget can be retrieved using     the currentWidget() function, and altered using the     setCurrentWidget() function.      Whenever the current widget in the layout changes or a widget is     removed from the layout, the currentChanged() and widgetRemoved()     signals are emitted respectively.      \sa QStackedWidget, QTabWidget */
end_comment
begin_comment
comment|/*!     \fn void QStackedLayout::currentChanged(int index)      This signal is emitted whenever the current widget in the layout     changes.  The \a index specifies the index of the new current     widget, or -1 if there isn't a new one (for example, if there     are no widgets in the QStackedLayout)      \sa currentWidget(), setCurrentWidget() */
end_comment
begin_comment
comment|/*!     \fn void QStackedLayout::widgetRemoved(int index)      This signal is emitted whenever a widget is removed from the     layout. The widget's \a index is passed as parameter.      \sa removeWidget() */
end_comment
begin_comment
comment|/*!     \fn QWidget *QStackedLayout::widget()     \internal */
end_comment
begin_comment
comment|/*!     Constructs a QStackedLayout with no parent.      This QStackedLayout must be installed on a widget later on to     become effective.      \sa addWidget(), insertWidget() */
end_comment
begin_constructor
DECL|function|QStackedLayout
name|QStackedLayout
operator|::
name|QStackedLayout
parameter_list|()
member_init_list|:
name|QLayout
argument_list|(
operator|*
operator|new
name|QStackedLayoutPrivate
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a new QStackedLayout with the given \a parent.      This layout will install itself on the \a parent widget and     manage the geometry of its children. */
end_comment
begin_constructor
DECL|function|QStackedLayout
name|QStackedLayout
operator|::
name|QStackedLayout
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QLayout
argument_list|(
operator|*
operator|new
name|QStackedLayoutPrivate
argument_list|,
literal|0
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a new QStackedLayout and inserts it into     the given \a parentLayout. */
end_comment
begin_constructor
DECL|function|QStackedLayout
name|QStackedLayout
operator|::
name|QStackedLayout
parameter_list|(
name|QLayout
modifier|*
name|parentLayout
parameter_list|)
member_init_list|:
name|QLayout
argument_list|(
operator|*
operator|new
name|QStackedLayoutPrivate
argument_list|,
name|parentLayout
argument_list|,
literal|0
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys this QStackedLayout. Note that the layout's widgets are     \e not destroyed. */
end_comment
begin_destructor
DECL|function|~QStackedLayout
name|QStackedLayout
operator|::
name|~
name|QStackedLayout
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
name|qDeleteAll
argument_list|(
name|d
operator|->
name|list
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Adds the given \a widget to the end of this layout and returns the     index position of the \a widget.      If the QStackedLayout is empty before this function is called,     the given \a widget becomes the current widget.      \sa insertWidget(), removeWidget(), setCurrentWidget() */
end_comment
begin_function
DECL|function|addWidget
name|int
name|QStackedLayout
operator|::
name|addWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
return|return
name|insertWidget
argument_list|(
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
argument_list|,
name|widget
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Inserts the given \a widget at the given \a index in this     QStackedLayout. If \a index is out of range, the widget is     appended (in which case it is the actual index of the \a widget     that is returned).      If the QStackedLayout is empty before this function is called, the     given \a widget becomes the current widget.      Inserting a new widget at an index less than or equal to the current index     will increment the current index, but keep the current widget.      \sa addWidget(), removeWidget(), setCurrentWidget() */
end_comment
begin_function
DECL|function|insertWidget
name|int
name|QStackedLayout
operator|::
name|insertWidget
parameter_list|(
name|int
name|index
parameter_list|,
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
name|addChildWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|index
operator|=
name|qMin
argument_list|(
name|index
argument_list|,
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|<
literal|0
condition|)
name|index
operator|=
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
expr_stmt|;
name|QWidgetItem
modifier|*
name|wi
init|=
name|QLayoutPrivate
operator|::
name|createWidgetItem
argument_list|(
name|this
argument_list|,
name|widget
argument_list|)
decl_stmt|;
name|d
operator|->
name|list
operator|.
name|insert
argument_list|(
name|index
argument_list|,
name|wi
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|index
operator|<
literal|0
condition|)
block|{
name|setCurrentIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|index
operator|<=
name|d
operator|->
name|index
condition|)
operator|++
name|d
operator|->
name|index
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|stackingMode
operator|==
name|StackOne
condition|)
name|widget
operator|->
name|hide
argument_list|()
expr_stmt|;
name|widget
operator|->
name|lower
argument_list|()
expr_stmt|;
block|}
return|return
name|index
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|itemAt
name|QLayoutItem
modifier|*
name|QStackedLayout
operator|::
name|itemAt
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|list
operator|.
name|value
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// Code that enables proper handling of the case that takeAt() is
end_comment
begin_comment
comment|// called somewhere inside QObject destructor (can't call hide()
end_comment
begin_comment
comment|// on the object then)
end_comment
begin_class
DECL|class|QtFriendlyLayoutWidget
class|class
name|QtFriendlyLayoutWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
DECL|function|wasDeleted
specifier|inline
name|bool
name|wasDeleted
parameter_list|()
specifier|const
block|{
return|return
name|d_ptr
operator|->
name|wasDeleted
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|qt_wasDeleted
specifier|static
name|bool
name|qt_wasDeleted
parameter_list|(
specifier|const
name|QWidget
modifier|*
name|w
parameter_list|)
block|{
return|return
cast|static_cast
argument_list|<
specifier|const
name|QtFriendlyLayoutWidget
operator|*
argument_list|>
argument_list|(
name|w
argument_list|)
operator|->
name|wasDeleted
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|takeAt
name|QLayoutItem
modifier|*
name|QStackedLayout
operator|::
name|takeAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|<
literal|0
operator|||
name|index
operator|>=
name|d
operator|->
name|list
operator|.
name|size
argument_list|()
condition|)
return|return
literal|0
return|;
name|QLayoutItem
modifier|*
name|item
init|=
name|d
operator|->
name|list
operator|.
name|takeAt
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
name|d
operator|->
name|index
condition|)
block|{
name|d
operator|->
name|index
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
operator|>
literal|0
condition|)
block|{
name|int
name|newIndex
init|=
operator|(
name|index
operator|==
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
operator|)
condition|?
name|index
operator|-
literal|1
else|:
name|index
decl_stmt|;
name|setCurrentIndex
argument_list|(
name|newIndex
argument_list|)
expr_stmt|;
block|}
else|else
block|{
emit|emit
name|currentChanged
argument_list|(
operator|-
literal|1
argument_list|)
emit|;
block|}
block|}
elseif|else
if|if
condition|(
name|index
operator|<
name|d
operator|->
name|index
condition|)
block|{
operator|--
name|d
operator|->
name|index
expr_stmt|;
block|}
emit|emit
name|widgetRemoved
argument_list|(
name|index
argument_list|)
emit|;
if|if
condition|(
name|item
operator|->
name|widget
argument_list|()
operator|&&
operator|!
name|qt_wasDeleted
argument_list|(
name|item
operator|->
name|widget
argument_list|()
argument_list|)
condition|)
name|item
operator|->
name|widget
argument_list|()
operator|->
name|hide
argument_list|()
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_comment
comment|/*!     \property QStackedLayout::currentIndex     \brief the index position of the widget that is visible      The current index is -1 if there is no current widget.      \sa currentWidget(), indexOf() */
end_comment
begin_function
DECL|function|setCurrentIndex
name|void
name|QStackedLayout
operator|::
name|setCurrentIndex
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|prev
init|=
name|currentWidget
argument_list|()
decl_stmt|;
name|QWidget
modifier|*
name|next
init|=
name|widget
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|next
operator|||
name|next
operator|==
name|prev
condition|)
return|return;
name|bool
name|reenableUpdates
init|=
literal|false
decl_stmt|;
name|QWidget
modifier|*
name|parent
init|=
name|parentWidget
argument_list|()
decl_stmt|;
if|if
condition|(
name|parent
operator|&&
name|parent
operator|->
name|updatesEnabled
argument_list|()
condition|)
block|{
name|reenableUpdates
operator|=
literal|true
expr_stmt|;
name|parent
operator|->
name|setUpdatesEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
name|QPointer
argument_list|<
name|QWidget
argument_list|>
name|fw
init|=
name|parent
condition|?
name|parent
operator|->
name|window
argument_list|()
operator|->
name|focusWidget
argument_list|()
else|:
literal|0
decl_stmt|;
specifier|const
name|bool
name|focusWasOnOldPage
init|=
name|fw
operator|&&
operator|(
name|prev
operator|&&
name|prev
operator|->
name|isAncestorOf
argument_list|(
name|fw
argument_list|)
operator|)
decl_stmt|;
if|if
condition|(
name|prev
condition|)
block|{
name|prev
operator|->
name|clearFocus
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|stackingMode
operator|==
name|StackOne
condition|)
name|prev
operator|->
name|hide
argument_list|()
expr_stmt|;
block|}
name|d
operator|->
name|index
operator|=
name|index
expr_stmt|;
name|next
operator|->
name|raise
argument_list|()
expr_stmt|;
name|next
operator|->
name|show
argument_list|()
expr_stmt|;
comment|// try to move focus onto the incoming widget if focus
comment|// was somewhere on the outgoing widget.
if|if
condition|(
name|parent
condition|)
block|{
if|if
condition|(
name|focusWasOnOldPage
condition|)
block|{
comment|// look for the best focus widget we can find
if|if
condition|(
name|QWidget
modifier|*
name|nfw
init|=
name|next
operator|->
name|focusWidget
argument_list|()
condition|)
name|nfw
operator|->
name|setFocus
argument_list|()
expr_stmt|;
else|else
block|{
comment|// second best: first child widget in the focus chain
if|if
condition|(
name|QWidget
modifier|*
name|i
init|=
name|fw
condition|)
block|{
while|while
condition|(
operator|(
name|i
operator|=
name|i
operator|->
name|nextInFocusChain
argument_list|()
operator|)
operator|!=
name|fw
condition|)
block|{
if|if
condition|(
operator|(
operator|(
name|i
operator|->
name|focusPolicy
argument_list|()
operator|&
name|Qt
operator|::
name|TabFocus
operator|)
operator|==
name|Qt
operator|::
name|TabFocus
operator|)
operator|&&
operator|!
name|i
operator|->
name|focusProxy
argument_list|()
operator|&&
name|i
operator|->
name|isVisibleTo
argument_list|(
name|next
argument_list|)
operator|&&
name|i
operator|->
name|isEnabled
argument_list|()
operator|&&
name|next
operator|->
name|isAncestorOf
argument_list|(
name|i
argument_list|)
condition|)
block|{
name|i
operator|->
name|setFocus
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
comment|// third best: incoming widget
if|if
condition|(
name|i
operator|==
name|fw
condition|)
name|next
operator|->
name|setFocus
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
if|if
condition|(
name|reenableUpdates
condition|)
name|parent
operator|->
name|setUpdatesEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
emit|emit
name|currentChanged
argument_list|(
name|index
argument_list|)
emit|;
block|}
end_function
begin_function
DECL|function|currentIndex
name|int
name|QStackedLayout
operator|::
name|currentIndex
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|index
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QStackedLayout::setCurrentWidget(QWidget *widget)      Sets the current widget to be the specified \a widget. The new     current widget must already be contained in this stacked layout.      \sa setCurrentIndex(), currentWidget()  */
end_comment
begin_function
DECL|function|setCurrentWidget
name|void
name|QStackedLayout
operator|::
name|setCurrentWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|int
name|index
init|=
name|indexOf
argument_list|(
name|widget
argument_list|)
decl_stmt|;
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
block|{
name|qWarning
argument_list|(
literal|"QStackedLayout::setCurrentWidget: Widget %p not contained in stack"
argument_list|,
name|widget
argument_list|)
expr_stmt|;
return|return;
block|}
name|setCurrentIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the current widget, or 0 if there are no widgets in this     layout.      \sa currentIndex(), setCurrentWidget() */
end_comment
begin_function
DECL|function|currentWidget
name|QWidget
modifier|*
name|QStackedLayout
operator|::
name|currentWidget
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|index
operator|>=
literal|0
condition|?
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|d
operator|->
name|index
argument_list|)
operator|->
name|widget
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the widget at the given \a index, or 0 if there is no     widget at the given position.      \sa currentWidget(), indexOf() */
end_comment
begin_function
DECL|function|widget
name|QWidget
modifier|*
name|QStackedLayout
operator|::
name|widget
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|index
operator|<
literal|0
operator|||
name|index
operator|>=
name|d
operator|->
name|list
operator|.
name|size
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|->
name|widget
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \property QStackedLayout::count     \brief the number of widgets contained in the layout      \sa currentIndex(), widget() */
end_comment
begin_function
DECL|function|count
name|int
name|QStackedLayout
operator|::
name|count
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|list
operator|.
name|size
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|addItem
name|void
name|QStackedLayout
operator|::
name|addItem
parameter_list|(
name|QLayoutItem
modifier|*
name|item
parameter_list|)
block|{
name|QWidget
modifier|*
name|widget
init|=
name|item
operator|->
name|widget
argument_list|()
decl_stmt|;
if|if
condition|(
name|widget
condition|)
block|{
name|addWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
operator|delete
name|item
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QStackedLayout::addItem: Only widgets can be added"
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSize
name|QStackedLayout
operator|::
name|sizeHint
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
name|QSize
name|s
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
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
name|n
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QWidget
modifier|*
name|widget
init|=
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
condition|)
block|{
name|QSize
name|ws
argument_list|(
name|widget
operator|->
name|sizeHint
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|widget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|horizontalPolicy
argument_list|()
operator|==
name|QSizePolicy
operator|::
name|Ignored
condition|)
name|ws
operator|.
name|setWidth
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
operator|->
name|sizePolicy
argument_list|()
operator|.
name|verticalPolicy
argument_list|()
operator|==
name|QSizePolicy
operator|::
name|Ignored
condition|)
name|ws
operator|.
name|setHeight
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|s
operator|=
name|s
operator|.
name|expandedTo
argument_list|(
name|ws
argument_list|)
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|minimumSize
name|QSize
name|QStackedLayout
operator|::
name|minimumSize
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
name|QSize
name|s
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
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
name|n
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QWidget
modifier|*
name|widget
init|=
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
condition|)
name|s
operator|=
name|s
operator|.
name|expandedTo
argument_list|(
name|qSmartMinSize
argument_list|(
name|widget
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|setGeometry
name|void
name|QStackedLayout
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRect
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|d
operator|->
name|stackingMode
condition|)
block|{
case|case
name|StackOne
case|:
if|if
condition|(
name|QWidget
modifier|*
name|widget
init|=
name|currentWidget
argument_list|()
condition|)
name|widget
operator|->
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
break|break;
case|case
name|StackAll
case|:
if|if
condition|(
specifier|const
name|int
name|n
init|=
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
condition|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QWidget
modifier|*
name|widget
init|=
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
condition|)
name|widget
operator|->
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|hasHeightForWidth
name|bool
name|QStackedLayout
operator|::
name|hasHeightForWidth
parameter_list|()
specifier|const
block|{
specifier|const
name|int
name|n
init|=
name|count
argument_list|()
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
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLayoutItem
modifier|*
name|item
init|=
name|itemAt
argument_list|(
name|i
argument_list|)
condition|)
block|{
if|if
condition|(
name|item
operator|->
name|hasHeightForWidth
argument_list|()
condition|)
return|return
literal|true
return|;
block|}
block|}
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|heightForWidth
name|int
name|QStackedLayout
operator|::
name|heightForWidth
parameter_list|(
name|int
name|width
parameter_list|)
specifier|const
block|{
specifier|const
name|int
name|n
init|=
name|count
argument_list|()
decl_stmt|;
name|int
name|hfw
init|=
literal|0
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
name|n
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|QLayoutItem
modifier|*
name|item
init|=
name|itemAt
argument_list|(
name|i
argument_list|)
condition|)
block|{
if|if
condition|(
name|QWidget
modifier|*
name|w
init|=
name|item
operator|->
name|widget
argument_list|()
condition|)
comment|/*                 Note: Does not query the layout item, but bypasses it and asks the widget                 directly. This is consistent with how QStackedLayout::sizeHint() is                 implemented. This also avoids an issue where QWidgetItem::heightForWidth()                 returns -1 if the widget is hidden.                 */
name|hfw
operator|=
name|qMax
argument_list|(
name|hfw
argument_list|,
name|w
operator|->
name|heightForWidth
argument_list|(
name|width
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
name|hfw
operator|=
name|qMax
argument_list|(
name|hfw
argument_list|,
name|minimumSize
argument_list|()
operator|.
name|height
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|hfw
return|;
block|}
end_function
begin_comment
comment|/*!     \enum QStackedLayout::StackingMode     \since 4.4      This enum specifies how the layout handles its child widgets     regarding their visibility.      \value StackOne            Only the current widget is visible. This is the default.      \value StackAll            All widgets are visible. The current widget is merely raised. */
end_comment
begin_comment
comment|/*!     \property QStackedLayout::stackingMode     \brief determines the way visibility of child widgets are handled.     \since 4.4      The default value is StackOne. Setting the property to StackAll     allows you to make use of the layout for overlay widgets     that do additional drawing on top of other widgets, for example,     graphical editors. */
end_comment
begin_function
DECL|function|stackingMode
name|QStackedLayout
operator|::
name|StackingMode
name|QStackedLayout
operator|::
name|stackingMode
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QStackedLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|stackingMode
return|;
block|}
end_function
begin_function
DECL|function|setStackingMode
name|void
name|QStackedLayout
operator|::
name|setStackingMode
parameter_list|(
name|StackingMode
name|stackingMode
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QStackedLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|stackingMode
operator|==
name|stackingMode
condition|)
return|return;
name|d
operator|->
name|stackingMode
operator|=
name|stackingMode
expr_stmt|;
specifier|const
name|int
name|n
init|=
name|d
operator|->
name|list
operator|.
name|count
argument_list|()
decl_stmt|;
if|if
condition|(
name|n
operator|==
literal|0
condition|)
return|return;
switch|switch
condition|(
name|d
operator|->
name|stackingMode
condition|)
block|{
case|case
name|StackOne
case|:
if|if
condition|(
specifier|const
name|int
name|idx
init|=
name|currentIndex
argument_list|()
condition|)
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QWidget
modifier|*
name|widget
init|=
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
condition|)
name|widget
operator|->
name|setVisible
argument_list|(
name|i
operator|==
name|idx
argument_list|)
expr_stmt|;
break|break;
case|case
name|StackAll
case|:
block|{
comment|// Turn overlay on: Make sure all widgets are the same size
name|QRect
name|geometry
decl_stmt|;
if|if
condition|(
specifier|const
name|QWidget
modifier|*
name|widget
init|=
name|currentWidget
argument_list|()
condition|)
name|geometry
operator|=
name|widget
operator|->
name|geometry
argument_list|()
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
name|n
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|QWidget
modifier|*
name|widget
init|=
name|d
operator|->
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|widget
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|geometry
operator|.
name|isNull
argument_list|()
condition|)
name|widget
operator|->
name|setGeometry
argument_list|(
name|geometry
argument_list|)
expr_stmt|;
name|widget
operator|->
name|setVisible
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
