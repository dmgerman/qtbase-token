begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qapplication.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_include
include|#
directive|include
file|"qgraphicslayout.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayout_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayoutitem.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayoutitem_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicswidget.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicswidget_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsscene.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QGraphicsLayout     \brief The QGraphicsLayout class provides the base class for all layouts     in Graphics View.     \since 4.4     \ingroup graphicsview-api     \inmodule QtWidgets      QGraphicsLayout is an abstract class that defines a virtual API for     arranging QGraphicsWidget children and other QGraphicsLayoutItem objects     for a QGraphicsWidget. QGraphicsWidget assigns responsibility to a     QGraphicsLayout through QGraphicsWidget::setLayout(). As the widget     is resized, the layout will automatically arrange the widget's children.     QGraphicsLayout inherits QGraphicsLayoutItem, so, it can be managed by     any layout, including its own subclasses.      \section1 Writing a Custom Layout      You can use QGraphicsLayout as a base to write your own custom layout     (e.g., a flowlayout), but it is more common to use one of its subclasses     instead - QGraphicsLinearLayout or QGraphicsGridLayout. When creating     a custom layout, the following functions must be reimplemented as a bare     minimum:      \table     \header \li Function                     \li Description     \row     \li QGraphicsLayoutItem::setGeometry()                \li Notifies you when the geometry of the layout is set. You can                    store the geometry in your own layout class in a reimplementation                    of this function.     \row    \li QGraphicsLayoutItem::sizeHint()                \li Returns the layout's size hints.     \row    \li QGraphicsLayout::count()               \li Returns the number of items in your layout.     \row    \li QGraphicsLayout::itemAt()               \li Returns a pointer to an item in your layout.     \row    \li QGraphicsLayout::removeAt()               \li Removes an item from your layout without destroying it.     \endtable      For more details on how to implement each function, refer to the individual     function documentation.      Each layout defines its own API for arranging widgets and layout items.     For example, with a grid layout, you require a row and a     column index with optional row and column spans, alignment, spacing, and more.     A linear layout, however, requires a single row or column index to position its     items. For a grid layout, the order of insertion does not affect the layout in     any way, but for a linear layout, the order is essential. When writing your own     layout subclass, you are free to choose the API that best suits your layout.      QGraphicsLayout provides the addChildLayoutItem() convenience function to add     layout items to a custom layout. The function will automatically reparent     graphics items, if required.      \section1 Activating the Layout      When the layout's geometry changes, QGraphicsLayout immediately rearranges     all of its managed items by calling setGeometry() on each item. This     rearrangement is called \e activating the layout.      QGraphicsLayout updates its own geometry to match the contentsRect() of the     QGraphicsLayoutItem it is managing. Thus, it will automatically rearrange all     its items when the widget is resized. QGraphicsLayout caches the sizes of all     its managed items to avoid calling setGeometry() too often.      \note A QGraphicsLayout will have the same geometry as the contentsRect()     of the widget (not the layout) it is assigned to.      \section2 Activating the Layout Implicitly      The layout can be activated implicitly using one of two ways: by calling     activate() or by calling invalidate(). Calling activate() activates the layout     immediately. In contrast, calling invalidate() is delayed, as it posts a     \l{QEvent::LayoutRequest}{LayoutRequest} event to the managed widget. Due     to event compression, the activate() will only be called once after control has     returned to the event loop. This is referred to as \e invalidating the layout.     Invalidating the layout also invalidates any cached information. Also, the     invalidate() function is a virtual function. So, you can invalidate your own     cache in a subclass of QGraphicsLayout by reimplementing this function.      \section1 Event Handling      QGraphicsLayout listens to events for the widget it manages through the     virtual widgetEvent() event handler. When the layout is assigned to a     widget, all events delivered to the widget are first processed by     widgetEvent(). This allows the layout to be aware of any relevant state     changes on the widget such as visibility changes or layout direction changes.      \section1 Margin Handling      The margins of a QGraphicsLayout can be modified by reimplementing     setContentsMargins() and getContentsMargins().  */
end_comment
begin_comment
comment|/*!     Contructs a QGraphicsLayout object.      \a parent is passed to QGraphicsLayoutItem's constructor and the     QGraphicsLayoutItem's isLayout argument is set to \e true.      If \a parent is a QGraphicsWidget the layout will be installed     on that widget. (Note that installing a layout will delete the old one     installed.) */
end_comment
begin_constructor
DECL|function|QGraphicsLayout
name|QGraphicsLayout
operator|::
name|QGraphicsLayout
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsLayoutItem
argument_list|(
operator|*
operator|new
name|QGraphicsLayoutPrivate
argument_list|)
block|{
name|setParentLayoutItem
argument_list|(
name|parent
argument_list|)
expr_stmt|;
if|if
condition|(
name|parent
operator|&&
operator|!
name|parent
operator|->
name|isLayout
argument_list|()
condition|)
block|{
comment|// If a layout has a parent that is not a layout it must be a QGraphicsWidget.
name|QGraphicsItem
modifier|*
name|itemParent
init|=
name|parent
operator|->
name|graphicsItem
argument_list|()
decl_stmt|;
if|if
condition|(
name|itemParent
operator|&&
name|itemParent
operator|->
name|isWidget
argument_list|()
condition|)
block|{
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|itemParent
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|setLayout_helper
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLayout::QGraphicsLayout: Attempt to create a layout with a parent that is"
literal|" neither a QGraphicsWidget nor QGraphicsLayout"
argument_list|)
expr_stmt|;
block|}
block|}
name|d_func
argument_list|()
operator|->
name|sizePolicy
operator|=
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
expr_stmt|;
name|setOwnedByLayout
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QGraphicsLayout
name|QGraphicsLayout
operator|::
name|QGraphicsLayout
parameter_list|(
name|QGraphicsLayoutPrivate
modifier|&
name|dd
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsLayoutItem
argument_list|(
name|dd
argument_list|)
block|{
name|setParentLayoutItem
argument_list|(
name|parent
argument_list|)
expr_stmt|;
if|if
condition|(
name|parent
operator|&&
operator|!
name|parent
operator|->
name|isLayout
argument_list|()
condition|)
block|{
comment|// If a layout has a parent that is not a layout it must be a QGraphicsWidget.
name|QGraphicsItem
modifier|*
name|itemParent
init|=
name|parent
operator|->
name|graphicsItem
argument_list|()
decl_stmt|;
if|if
condition|(
name|itemParent
operator|&&
name|itemParent
operator|->
name|isWidget
argument_list|()
condition|)
block|{
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|itemParent
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|setLayout_helper
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLayout::QGraphicsLayout: Attempt to create a layout with a parent that is"
literal|" neither a QGraphicsWidget nor QGraphicsLayout"
argument_list|)
expr_stmt|;
block|}
block|}
name|d_func
argument_list|()
operator|->
name|sizePolicy
operator|=
name|QSizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|Expanding
argument_list|,
name|QSizePolicy
operator|::
name|DefaultType
argument_list|)
expr_stmt|;
name|setOwnedByLayout
argument_list|(
literal|true
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QGraphicsLayout object. */
end_comment
begin_destructor
DECL|function|~QGraphicsLayout
name|QGraphicsLayout
operator|::
name|~
name|QGraphicsLayout
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Sets the contents margins to \a left, \a top, \a right and \a bottom. The     default contents margins for toplevel layouts are style dependent     (by querying the pixelMetric for QStyle::PM_LayoutLeftMargin,     QStyle::PM_LayoutTopMargin, QStyle::PM_LayoutRightMargin and     QStyle::PM_LayoutBottomMargin).      For sublayouts the default margins are 0.      Changing the contents margins automatically invalidates the layout.      \sa invalidate() */
end_comment
begin_function
DECL|function|setContentsMargins
name|void
name|QGraphicsLayout
operator|::
name|setContentsMargins
parameter_list|(
name|qreal
name|left
parameter_list|,
name|qreal
name|top
parameter_list|,
name|qreal
name|right
parameter_list|,
name|qreal
name|bottom
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|left
operator|==
name|left
operator|&&
name|d
operator|->
name|top
operator|==
name|top
operator|&&
name|d
operator|->
name|right
operator|==
name|right
operator|&&
name|d
operator|->
name|bottom
operator|==
name|bottom
condition|)
return|return;
name|d
operator|->
name|left
operator|=
name|left
expr_stmt|;
name|d
operator|->
name|right
operator|=
name|right
expr_stmt|;
name|d
operator|->
name|top
operator|=
name|top
expr_stmt|;
name|d
operator|->
name|bottom
operator|=
name|bottom
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|getContentsMargins
name|void
name|QGraphicsLayout
operator|::
name|getContentsMargins
parameter_list|(
name|qreal
modifier|*
name|left
parameter_list|,
name|qreal
modifier|*
name|top
parameter_list|,
name|qreal
modifier|*
name|right
parameter_list|,
name|qreal
modifier|*
name|bottom
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|getMargin
argument_list|(
name|left
argument_list|,
name|d
operator|->
name|left
argument_list|,
name|QStyle
operator|::
name|PM_LayoutLeftMargin
argument_list|)
expr_stmt|;
name|d
operator|->
name|getMargin
argument_list|(
name|top
argument_list|,
name|d
operator|->
name|top
argument_list|,
name|QStyle
operator|::
name|PM_LayoutTopMargin
argument_list|)
expr_stmt|;
name|d
operator|->
name|getMargin
argument_list|(
name|right
argument_list|,
name|d
operator|->
name|right
argument_list|,
name|QStyle
operator|::
name|PM_LayoutRightMargin
argument_list|)
expr_stmt|;
name|d
operator|->
name|getMargin
argument_list|(
name|bottom
argument_list|,
name|d
operator|->
name|bottom
argument_list|,
name|QStyle
operator|::
name|PM_LayoutBottomMargin
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Activates the layout, causing all items in the layout to be immediately     rearranged. This function is based on calling count() and itemAt(), and     then calling setGeometry() on all items sequentially. When activated,     the layout will adjust its geometry to its parent's contentsRect().     The parent will then invalidate any layout of its own.      If called in sequence or recursively, e.g., by one of the arranged items     in response to being resized, this function will do nothing.      Note that the layout is free to use geometry caching to optimize this     process.  To forcefully invalidate any such cache, you can call     invalidate() before calling activate().      \sa invalidate() */
end_comment
begin_function
DECL|function|activate
name|void
name|QGraphicsLayout
operator|::
name|activate
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGraphicsLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|activated
condition|)
return|return;
name|d
operator|->
name|activateRecursive
argument_list|(
name|this
argument_list|)
expr_stmt|;
comment|// we don't call activate on a sublayout, but somebody might.
comment|// Therefore, we walk to the parentitem of the toplevel layout.
name|QGraphicsLayoutItem
modifier|*
name|parentItem
init|=
name|this
decl_stmt|;
while|while
condition|(
name|parentItem
operator|&&
name|parentItem
operator|->
name|isLayout
argument_list|()
condition|)
name|parentItem
operator|=
name|parentItem
operator|->
name|parentLayoutItem
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|parentItem
condition|)
return|return;
name|Q_ASSERT
argument_list|(
operator|!
name|parentItem
operator|->
name|isLayout
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGraphicsLayout
operator|::
name|instantInvalidatePropagation
argument_list|()
condition|)
block|{
name|QGraphicsWidget
modifier|*
name|parentWidget
init|=
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|parentItem
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|parentWidget
operator|->
name|parentLayoutItem
argument_list|()
condition|)
block|{
comment|// we've reached the topmost widget, resize it
name|bool
name|wasResized
init|=
name|parentWidget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_Resized
argument_list|)
decl_stmt|;
name|parentWidget
operator|->
name|resize
argument_list|(
name|parentWidget
operator|->
name|size
argument_list|()
argument_list|)
expr_stmt|;
name|parentWidget
operator|->
name|setAttribute
argument_list|(
name|Qt
operator|::
name|WA_Resized
argument_list|,
name|wasResized
argument_list|)
expr_stmt|;
block|}
name|setGeometry
argument_list|(
name|parentItem
operator|->
name|contentsRect
argument_list|()
argument_list|)
expr_stmt|;
comment|// relayout children
block|}
else|else
block|{
name|setGeometry
argument_list|(
name|parentItem
operator|->
name|contentsRect
argument_list|()
argument_list|)
expr_stmt|;
comment|// relayout children
name|parentLayoutItem
argument_list|()
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the layout is currently being activated; otherwise,     returns \c false. If the layout is being activated, this means that it is     currently in the process of rearranging its items (i.e., the activate()     function has been called, and has not yet returned).      \sa activate(), invalidate() */
end_comment
begin_function
DECL|function|isActivated
name|bool
name|QGraphicsLayout
operator|::
name|isActivated
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|activated
return|;
block|}
end_function
begin_comment
comment|/*!     Clears any cached geometry and size hint information in the layout, and     posts a \l{QEvent::LayoutRequest}{LayoutRequest} event to the managed     parent QGraphicsLayoutItem.      \sa activate(), setGeometry() */
end_comment
begin_function
DECL|function|invalidate
name|void
name|QGraphicsLayout
operator|::
name|invalidate
parameter_list|()
block|{
if|if
condition|(
name|QGraphicsLayout
operator|::
name|instantInvalidatePropagation
argument_list|()
condition|)
block|{
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
else|else
block|{
comment|// only mark layouts as invalid (activated = false) if we can post a LayoutRequest event.
name|QGraphicsLayoutItem
modifier|*
name|layoutItem
init|=
name|this
decl_stmt|;
while|while
condition|(
name|layoutItem
operator|&&
name|layoutItem
operator|->
name|isLayout
argument_list|()
condition|)
block|{
comment|// we could call updateGeometry(), but what if that method
comment|// does not call the base implementation? In addition, updateGeometry()
comment|// does more than we need.
name|layoutItem
operator|->
name|d_func
argument_list|()
operator|->
name|sizeHintCacheDirty
operator|=
literal|true
expr_stmt|;
name|layoutItem
operator|->
name|d_func
argument_list|()
operator|->
name|sizeHintWithConstraintCacheDirty
operator|=
literal|true
expr_stmt|;
name|layoutItem
operator|=
name|layoutItem
operator|->
name|parentLayoutItem
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|layoutItem
condition|)
block|{
name|layoutItem
operator|->
name|d_func
argument_list|()
operator|->
name|sizeHintCacheDirty
operator|=
literal|true
expr_stmt|;
name|layoutItem
operator|->
name|d_func
argument_list|()
operator|->
name|sizeHintWithConstraintCacheDirty
operator|=
literal|true
expr_stmt|;
block|}
name|bool
name|postIt
init|=
name|layoutItem
condition|?
operator|!
name|layoutItem
operator|->
name|isLayout
argument_list|()
else|:
literal|false
decl_stmt|;
if|if
condition|(
name|postIt
condition|)
block|{
name|layoutItem
operator|=
name|this
expr_stmt|;
while|while
condition|(
name|layoutItem
operator|&&
name|layoutItem
operator|->
name|isLayout
argument_list|()
operator|&&
cast|static_cast
argument_list|<
name|QGraphicsLayout
operator|*
argument_list|>
argument_list|(
name|layoutItem
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|activated
condition|)
block|{
cast|static_cast
argument_list|<
name|QGraphicsLayout
operator|*
argument_list|>
argument_list|(
name|layoutItem
argument_list|)
operator|->
name|d_func
argument_list|()
operator|->
name|activated
operator|=
literal|false
expr_stmt|;
name|layoutItem
operator|=
name|layoutItem
operator|->
name|parentLayoutItem
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
name|layoutItem
operator|&&
operator|!
name|layoutItem
operator|->
name|isLayout
argument_list|()
condition|)
block|{
comment|// If a layout has a parent that is not a layout it must be a QGraphicsWidget.
name|QApplication
operator|::
name|postEvent
argument_list|(
cast|static_cast
argument_list|<
name|QGraphicsWidget
operator|*
argument_list|>
argument_list|(
name|layoutItem
argument_list|)
argument_list|,
operator|new
name|QEvent
argument_list|(
name|QEvent
operator|::
name|LayoutRequest
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|updateGeometry
name|void
name|QGraphicsLayout
operator|::
name|updateGeometry
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGraphicsLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGraphicsLayout
operator|::
name|instantInvalidatePropagation
argument_list|()
condition|)
block|{
name|d
operator|->
name|activated
operator|=
literal|false
expr_stmt|;
name|QGraphicsLayoutItem
operator|::
name|updateGeometry
argument_list|()
expr_stmt|;
name|QGraphicsLayoutItem
modifier|*
name|parentItem
init|=
name|parentLayoutItem
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|parentItem
condition|)
return|return;
if|if
condition|(
name|parentItem
operator|->
name|isLayout
argument_list|()
condition|)
cast|static_cast
argument_list|<
name|QGraphicsLayout
operator|*
argument_list|>
argument_list|(
name|parentItem
argument_list|)
operator|->
name|invalidate
argument_list|()
expr_stmt|;
else|else
name|parentItem
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|QGraphicsLayoutItem
operator|::
name|updateGeometry
argument_list|()
expr_stmt|;
if|if
condition|(
name|QGraphicsLayoutItem
modifier|*
name|parentItem
init|=
name|parentLayoutItem
argument_list|()
condition|)
block|{
if|if
condition|(
name|parentItem
operator|->
name|isLayout
argument_list|()
condition|)
block|{
name|parentItem
operator|->
name|updateGeometry
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|invalidate
argument_list|()
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_comment
comment|/*!     This virtual event handler receives all events for the managed     widget. QGraphicsLayout uses this event handler to listen for layout     related events such as geometry changes, layout changes or layout     direction changes.      \a e is a pointer to the event.      You can reimplement this event handler to track similar events for your     own custom layout.      \sa QGraphicsWidget::event(), QGraphicsItem::sceneEvent() */
end_comment
begin_function
DECL|function|widgetEvent
name|void
name|QGraphicsLayout
operator|::
name|widgetEvent
parameter_list|(
name|QEvent
modifier|*
name|e
parameter_list|)
block|{
switch|switch
condition|(
name|e
operator|->
name|type
argument_list|()
condition|)
block|{
case|case
name|QEvent
operator|::
name|GraphicsSceneResize
case|:
if|if
condition|(
name|isActivated
argument_list|()
condition|)
block|{
name|setGeometry
argument_list|(
name|parentLayoutItem
argument_list|()
operator|->
name|contentsRect
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|activate
argument_list|()
expr_stmt|;
comment|// relies on that activate() will call updateGeometry()
block|}
break|break;
case|case
name|QEvent
operator|::
name|LayoutRequest
case|:
name|activate
argument_list|()
expr_stmt|;
break|break;
case|case
name|QEvent
operator|::
name|LayoutDirectionChange
case|:
name|invalidate
argument_list|()
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
end_function
begin_comment
comment|/*!     \fn virtual int QGraphicsLayout::count() const = 0      This pure virtual function must be reimplemented in a subclass of     QGraphicsLayout to return the number of items in the layout.      The subclass is free to decide how to store the items.      \sa itemAt(), removeAt() */
end_comment
begin_comment
comment|/*!     \fn virtual QGraphicsLayoutItem *QGraphicsLayout::itemAt(int i) const = 0      This pure virtual function must be reimplemented in a subclass of     QGraphicsLayout to return a pointer to the item at index \a i. The     reimplementation can assume that \a i is valid (i.e., it respects the     value of count()).     Together with count(), it is provided as a means of iterating over all items in a layout.      The subclass is free to decide how to store the items, and the visual arrangement     does not have to be reflected through this function.      \sa count(), removeAt() */
end_comment
begin_comment
comment|/*!     \fn virtual void QGraphicsLayout::removeAt(int index) = 0      This pure virtual function must be reimplemented in a subclass of     QGraphicsLayout to remove the item at \a index. The     reimplementation can assume that \a index is valid (i.e., it     respects the value of count()).      The implementation must ensure that the parentLayoutItem() of     the removed item does not point to this layout, since the item is     considered to be removed from the layout hierarchy.      If the layout is to be reused between applications, we recommend     that the layout deletes the item, but the graphics view framework     does not depend on this.      The subclass is free to decide how to store the items.      \sa itemAt(), count() */
end_comment
begin_comment
comment|/*!     \since 4.6      This function is a convenience function provided for custom layouts, and will go through     all items in the layout and reparent their graphics items to the closest QGraphicsWidget     ancestor of the layout.      If \a layoutItem is already in a different layout, it will be removed  from that layout.      If custom layouts want special behaviour they can ignore to use this function, and implement     their own behaviour.      \sa graphicsItem()  */
end_comment
begin_function
DECL|function|addChildLayoutItem
name|void
name|QGraphicsLayout
operator|::
name|addChildLayoutItem
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|layoutItem
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|addChildLayoutItem
argument_list|(
name|layoutItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
DECL|variable|g_instantInvalidatePropagation
specifier|static
name|bool
name|g_instantInvalidatePropagation
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     \internal     \since 4.8     \sa instantInvalidatePropagation()      Calling this function with \a enable set to true will enable a feature that     makes propagation of invalidation up to ancestor layout items to be done in     one go. It will propagate up the parentLayoutItem() hierarchy until it has     reached the root. If the root item is a QGraphicsWidget, it will *post* a     layout request to it. When the layout request is consumed it will traverse     down the hierarchy of layouts and widgets and activate all layouts that is     invalid (not activated). This is the recommended behaviour.      If not set it will also propagate up the parentLayoutItem() hierarchy, but     it will stop at the \e{first widget} it encounters, and post a layout     request to the widget. When the layout request is consumed, this might     cause it to continue propagation up to the parentLayoutItem() of the     widget. It will continue in this fashion until it has reached a widget with     no parentLayoutItem(). This strategy might cause drawing artifacts, since     it is not done in one go, and the consumption of layout requests might be     interleaved by consumption of paint events, which might cause significant     flicker.     Note, this is not the recommended behavior, but for compatibility reasons     this is the default behaviour. */
end_comment
begin_function
DECL|function|setInstantInvalidatePropagation
name|void
name|QGraphicsLayout
operator|::
name|setInstantInvalidatePropagation
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|g_instantInvalidatePropagation
operator|=
name|enable
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal     \since 4.8     \sa setInstantInvalidatePropagation()      returns \c true if the complete widget/layout hierarchy is rearranged in one go. */
end_comment
begin_function
DECL|function|instantInvalidatePropagation
name|bool
name|QGraphicsLayout
operator|::
name|instantInvalidatePropagation
parameter_list|()
block|{
return|return
name|g_instantInvalidatePropagation
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_GRAPHICSVIEW
end_comment
end_unit
