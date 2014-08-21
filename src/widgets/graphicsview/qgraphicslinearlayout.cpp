begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QGraphicsLinearLayout     \brief The QGraphicsLinearLayout class provides a horizontal or vertical     layout for managing widgets in Graphics View.     \since 4.4     \ingroup graphicsview-api     \inmodule QtWidgets      The default orientation for a linear layout is Qt::Horizontal. You can     choose a vertical orientation either by calling setOrientation(), or by     passing Qt::Vertical to QGraphicsLinearLayout's constructor.      The most common way to use QGraphicsLinearLayout is to construct an object     on the heap with no parent, add widgets and layouts by calling addItem(),     and finally assign the layout to a widget by calling     QGraphicsWidget::setLayout().      \snippet code/src_gui_graphicsview_qgraphicslinearlayout.cpp 0      You can add widgets, layouts, stretches (addStretch(), insertStretch() or     setStretchFactor()), and spacings (setItemSpacing()) to a linear     layout. The layout takes ownership of the items. In some cases when the layout     item also inherits from QGraphicsItem (such as QGraphicsWidget) there will be a     ambiguity in ownership because the layout item belongs to two ownership hierarchies.     See the documentation of QGraphicsLayoutItem::setOwnedByLayout() how to handle     this.     You can access each item in the layout by calling count() and itemAt(). Calling     removeAt() or removeItem() will remove an item from the layout, without     destroying it.      \section1 Size Hints and Size Policies in QGraphicsLinearLayout      QGraphicsLinearLayout respects each item's size hints and size policies,     and when the layout contains more space than the items can fill, each item     is arranged according to the layout's alignment for that item. You can set     an alignment for each item by calling setAlignment(), and check the     alignment for any item by calling alignment(). By default, items are     aligned to the top left.      \section1 Spacing within QGraphicsLinearLayout      Between the items, the layout distributes some space. The actual amount of     space depends on the managed widget's current style, but the common     spacing is 4. You can also set your own spacing by calling setSpacing(),     and get the current spacing value by calling spacing(). If you want to     configure individual spacing for your items, you can call setItemSpacing().      \section1 Stretch Factor in QGraphicsLinearLayout      You can assign a stretch factor to each item to control how much space it     will get compared to the other items. By default, two identical widgets     arranged in a linear layout will have the same size, but if the first     widget has a stretch factor of 1 and the second widget has a stretch     factor of 2, the first widget will get 1/3 of the available space, and the     second will get 2/3.      QGraphicsLinearLayout calculates the distribution of sizes by adding up     the stretch factors of all items, and then dividing the available space     accordingly. The default stretch factor is 0 for all items; a factor of 0     means the item does not have any defined stretch factor; effectively this     is the same as setting the stretch factor to 1. The stretch factor only     applies to the available space in the lengthwise direction of the layout     (following its orientation). If you want to control both the item's     horizontal and vertical stretch, you can use QGraphicsGridLayout instead.      \section1 QGraphicsLinearLayout Compared to Other Layouts      QGraphicsLinearLayout is very similar to QVBoxLayout and QHBoxLayout, but     in contrast to these classes, it is used to manage QGraphicsWidget and     QGraphicsLayout instead of QWidget and QLayout.      \sa QGraphicsGridLayout, QGraphicsWidget */
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
file|"qwidget.h"
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
file|"qgraphicslinearlayout.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicswidget.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicsgridlayoutengine_p.h"
end_include
begin_include
include|#
directive|include
file|"qgraphicslayoutstyleinfo_p.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEBUG
end_ifdef
begin_include
include|#
directive|include
file|<QtCore/qdebug.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QGraphicsLinearLayoutPrivate
class|class
name|QGraphicsLinearLayoutPrivate
super|:
specifier|public
name|QGraphicsLayoutPrivate
block|{
public|public:
DECL|function|QGraphicsLinearLayoutPrivate
name|QGraphicsLinearLayoutPrivate
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
member_init_list|:
name|orientation
argument_list|(
name|orientation
argument_list|)
member_init_list|,
name|m_styleInfo
argument_list|(
literal|0
argument_list|)
block|{ }
name|void
name|removeGridItem
parameter_list|(
name|QGridLayoutItem
modifier|*
name|gridItem
parameter_list|)
function_decl|;
name|QGraphicsLayoutStyleInfo
modifier|*
name|styleInfo
parameter_list|()
specifier|const
function_decl|;
name|void
name|fixIndex
parameter_list|(
name|int
modifier|*
name|index
parameter_list|)
specifier|const
function_decl|;
name|int
name|gridRow
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
function_decl|;
name|int
name|gridColumn
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
function_decl|;
DECL|member|orientation
name|Qt
operator|::
name|Orientation
name|orientation
decl_stmt|;
DECL|member|m_styleInfo
specifier|mutable
name|QGraphicsLayoutStyleInfo
modifier|*
name|m_styleInfo
decl_stmt|;
DECL|member|engine
name|QGraphicsGridLayoutEngine
name|engine
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|removeGridItem
name|void
name|QGraphicsLinearLayoutPrivate
operator|::
name|removeGridItem
parameter_list|(
name|QGridLayoutItem
modifier|*
name|gridItem
parameter_list|)
block|{
name|int
name|index
init|=
name|gridItem
operator|->
name|firstRow
argument_list|(
name|orientation
argument_list|)
decl_stmt|;
name|engine
operator|.
name|removeItem
argument_list|(
name|gridItem
argument_list|)
expr_stmt|;
name|engine
operator|.
name|removeRows
argument_list|(
name|index
argument_list|,
literal|1
argument_list|,
name|orientation
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|fixIndex
name|void
name|QGraphicsLinearLayoutPrivate
operator|::
name|fixIndex
parameter_list|(
name|int
modifier|*
name|index
parameter_list|)
specifier|const
block|{
name|int
name|count
init|=
name|engine
operator|.
name|rowCount
argument_list|(
name|orientation
argument_list|)
decl_stmt|;
if|if
condition|(
name|uint
argument_list|(
operator|*
name|index
argument_list|)
operator|>
name|uint
argument_list|(
name|count
argument_list|)
condition|)
operator|*
name|index
operator|=
name|count
expr_stmt|;
block|}
end_function
begin_function
DECL|function|gridRow
name|int
name|QGraphicsLinearLayoutPrivate
operator|::
name|gridRow
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|)
return|return
literal|0
return|;
return|return
name|int
argument_list|(
name|qMin
argument_list|(
name|uint
argument_list|(
name|index
argument_list|)
argument_list|,
name|uint
argument_list|(
name|engine
operator|.
name|rowCount
argument_list|()
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|gridColumn
name|int
name|QGraphicsLinearLayoutPrivate
operator|::
name|gridColumn
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
if|if
condition|(
name|orientation
operator|==
name|Qt
operator|::
name|Vertical
condition|)
return|return
literal|0
return|;
return|return
name|int
argument_list|(
name|qMin
argument_list|(
name|uint
argument_list|(
name|index
argument_list|)
argument_list|,
name|uint
argument_list|(
name|engine
operator|.
name|columnCount
argument_list|()
argument_list|)
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|styleInfo
name|QGraphicsLayoutStyleInfo
modifier|*
name|QGraphicsLinearLayoutPrivate
operator|::
name|styleInfo
parameter_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|m_styleInfo
condition|)
name|m_styleInfo
operator|=
operator|new
name|QGraphicsLayoutStyleInfo
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|m_styleInfo
operator|->
name|updateChanged
argument_list|(
name|QAbstractLayoutStyleInfo
operator|::
name|Unknown
argument_list|)
expr_stmt|;
return|return
name|m_styleInfo
return|;
block|}
end_function
begin_comment
comment|/*!     Constructs a QGraphicsLinearLayout instance. You can pass the     \a orientation for the layout, either horizontal or vertical, and     \a parent is passed to QGraphicsLayout's constructor. */
end_comment
begin_constructor
DECL|function|QGraphicsLinearLayout
name|QGraphicsLinearLayout
operator|::
name|QGraphicsLinearLayout
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsLayout
argument_list|(
operator|*
operator|new
name|QGraphicsLinearLayoutPrivate
argument_list|(
name|orientation
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Constructs a QGraphicsLinearLayout instance using Qt::Horizontal     orientation. \a parent is passed to QGraphicsLayout's constructor. */
end_comment
begin_constructor
DECL|function|QGraphicsLinearLayout
name|QGraphicsLinearLayout
operator|::
name|QGraphicsLinearLayout
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QGraphicsLayout
argument_list|(
operator|*
operator|new
name|QGraphicsLinearLayoutPrivate
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the QGraphicsLinearLayout object. */
end_comment
begin_destructor
DECL|function|~QGraphicsLinearLayout
name|QGraphicsLinearLayout
operator|::
name|~
name|QGraphicsLinearLayout
parameter_list|()
block|{
for|for
control|(
name|int
name|i
init|=
name|count
argument_list|()
operator|-
literal|1
init|;
name|i
operator|>=
literal|0
condition|;
operator|--
name|i
control|)
block|{
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
name|itemAt
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// The following lines can be removed, but this removes the item
comment|// from the layout more efficiently than the implementation of
comment|// ~QGraphicsLayoutItem.
name|removeAt
argument_list|(
name|i
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
condition|)
block|{
name|item
operator|->
name|setParentLayoutItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|item
operator|->
name|ownedByLayout
argument_list|()
condition|)
operator|delete
name|item
expr_stmt|;
block|}
block|}
block|}
end_destructor
begin_comment
comment|/*!   Change the layout orientation to \a orientation. Changing the layout   orientation will automatically invalidate the layout.    \sa orientation() */
end_comment
begin_function
DECL|function|setOrientation
name|void
name|QGraphicsLinearLayout
operator|::
name|setOrientation
parameter_list|(
name|Qt
operator|::
name|Orientation
name|orientation
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|orientation
operator|!=
name|d
operator|->
name|orientation
condition|)
block|{
name|d
operator|->
name|engine
operator|.
name|transpose
argument_list|()
expr_stmt|;
name|d
operator|->
name|orientation
operator|=
name|orientation
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Returns the layout orientation.   \sa setOrientation()  */
end_comment
begin_function
DECL|function|orientation
name|Qt
operator|::
name|Orientation
name|QGraphicsLinearLayout
operator|::
name|orientation
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|orientation
return|;
block|}
end_function
begin_comment
comment|/*!     \fn void QGraphicsLinearLayout::addItem(QGraphicsLayoutItem *item)      This convenience function is equivalent to calling     insertItem(-1, \a item). */
end_comment
begin_comment
comment|/*!     \fn void QGraphicsLinearLayout::addStretch(int stretch)      This convenience function is equivalent to calling     insertStretch(-1, \a stretch). */
end_comment
begin_comment
comment|/*!     Inserts \a item into the layout at \a index, or before any item that is     currently at \a index.      \sa addItem(), itemAt(), insertStretch(), setItemSpacing() */
end_comment
begin_function
DECL|function|insertItem
name|void
name|QGraphicsLinearLayout
operator|::
name|insertItem
parameter_list|(
name|int
name|index
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::insertItem: cannot insert null item"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|item
operator|==
name|this
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::insertItem: cannot insert itself"
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|addChildLayoutItem
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|d
operator|->
name|fixIndex
argument_list|(
operator|&
name|index
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|.
name|insertRow
argument_list|(
name|index
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
expr_stmt|;
name|QGraphicsGridLayoutEngineItem
modifier|*
name|gridEngineItem
init|=
operator|new
name|QGraphicsGridLayoutEngineItem
argument_list|(
name|item
argument_list|,
name|d
operator|->
name|gridRow
argument_list|(
name|index
argument_list|)
argument_list|,
name|d
operator|->
name|gridColumn
argument_list|(
name|index
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
name|d
operator|->
name|engine
operator|.
name|insertItem
argument_list|(
name|gridEngineItem
argument_list|,
name|index
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Inserts a stretch of \a stretch at \a index, or before any item that is     currently at \a index.      \sa addStretch(), setStretchFactor(), setItemSpacing(), insertItem() */
end_comment
begin_function
DECL|function|insertStretch
name|void
name|QGraphicsLinearLayout
operator|::
name|insertStretch
parameter_list|(
name|int
name|index
parameter_list|,
name|int
name|stretch
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|fixIndex
argument_list|(
operator|&
name|index
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|.
name|insertRow
argument_list|(
name|index
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|.
name|setRowStretchFactor
argument_list|(
name|index
argument_list|,
name|stretch
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes \a item from the layout without destroying it. Ownership of     \a item is transferred to the caller.      \sa removeAt(), insertItem() */
end_comment
begin_function
DECL|function|removeItem
name|void
name|QGraphicsLinearLayout
operator|::
name|removeItem
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|gridItem
init|=
name|d
operator|->
name|engine
operator|.
name|findLayoutItem
argument_list|(
name|item
argument_list|)
condition|)
block|{
name|item
operator|->
name|setParentLayoutItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeGridItem
argument_list|(
name|gridItem
argument_list|)
expr_stmt|;
operator|delete
name|gridItem
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Removes the item at \a index without destroying it. Ownership of the item     is transferred to the caller.      \sa removeItem(), insertItem() */
end_comment
begin_function
DECL|function|removeAt
name|void
name|QGraphicsLinearLayout
operator|::
name|removeAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
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
name|engine
operator|.
name|itemCount
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::removeAt: invalid index %d"
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|gridItem
init|=
cast|static_cast
argument_list|<
name|QGraphicsGridLayoutEngineItem
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|engine
operator|.
name|itemAt
argument_list|(
name|index
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
name|QGraphicsLayoutItem
modifier|*
name|layoutItem
init|=
name|gridItem
operator|->
name|layoutItem
argument_list|()
condition|)
name|layoutItem
operator|->
name|setParentLayoutItem
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeGridItem
argument_list|(
name|gridItem
argument_list|)
expr_stmt|;
operator|delete
name|gridItem
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!   Sets the layout's spacing to \a spacing. Spacing refers to the   vertical and horizontal distances between items.     \sa setItemSpacing(), setStretchFactor(), QGraphicsGridLayout::setSpacing() */
end_comment
begin_function
DECL|function|setSpacing
name|void
name|QGraphicsLinearLayout
operator|::
name|setSpacing
parameter_list|(
name|qreal
name|spacing
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|spacing
operator|<
literal|0
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::setSpacing: invalid spacing %g"
argument_list|,
name|spacing
argument_list|)
expr_stmt|;
return|return;
block|}
name|d
operator|->
name|engine
operator|.
name|setSpacing
argument_list|(
name|spacing
argument_list|,
name|Qt
operator|::
name|Horizontal
operator||
name|Qt
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!   Returns the layout's spacing. Spacing refers to the   vertical and horizontal distances between items.    \sa setSpacing()  */
end_comment
begin_function
DECL|function|spacing
name|qreal
name|QGraphicsLinearLayout
operator|::
name|spacing
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|.
name|spacing
argument_list|(
name|d
operator|->
name|orientation
argument_list|,
name|d
operator|->
name|styleInfo
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the spacing after item at \a index to \a spacing. */
end_comment
begin_function
DECL|function|setItemSpacing
name|void
name|QGraphicsLinearLayout
operator|::
name|setItemSpacing
parameter_list|(
name|int
name|index
parameter_list|,
name|qreal
name|spacing
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|.
name|setRowSpacing
argument_list|(
name|index
argument_list|,
name|spacing
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the spacing after item at \a index. */
end_comment
begin_function
DECL|function|itemSpacing
name|qreal
name|QGraphicsLinearLayout
operator|::
name|itemSpacing
parameter_list|(
name|int
name|index
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|.
name|rowSpacing
argument_list|(
name|index
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the stretch factor for \a item to \a stretch. If an item's stretch     factor changes, this function will invalidate the layout.      Setting \a stretch to 0 removes the stretch factor from the item, and is     effectively equivalent to setting \a stretch to 1.      \sa stretchFactor() */
end_comment
begin_function
DECL|function|setStretchFactor
name|void
name|QGraphicsLinearLayout
operator|::
name|setStretchFactor
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|,
name|int
name|stretch
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::setStretchFactor: cannot assign"
literal|" a stretch factor to a null item"
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|stretchFactor
argument_list|(
name|item
argument_list|)
operator|==
name|stretch
condition|)
return|return;
name|d
operator|->
name|engine
operator|.
name|setStretchFactor
argument_list|(
name|item
argument_list|,
name|stretch
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the stretch factor for \a item. The default stretch factor is 0,     meaning that the item has no assigned stretch factor.      \sa setStretchFactor() */
end_comment
begin_function
DECL|function|stretchFactor
name|int
name|QGraphicsLinearLayout
operator|::
name|stretchFactor
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::setStretchFactor: cannot return"
literal|" a stretch factor for a null item"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
name|d
operator|->
name|engine
operator|.
name|stretchFactor
argument_list|(
name|item
argument_list|,
name|d
operator|->
name|orientation
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the alignment of \a item to \a alignment. If \a item's alignment     changes, the layout is automatically invalidated.      \sa alignment(), invalidate() */
end_comment
begin_function
DECL|function|setAlignment
name|void
name|QGraphicsLinearLayout
operator|::
name|setAlignment
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|,
name|Qt
operator|::
name|Alignment
name|alignment
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
if|if
condition|(
name|this
operator|->
name|alignment
argument_list|(
name|item
argument_list|)
operator|==
name|alignment
condition|)
return|return;
name|d
operator|->
name|engine
operator|.
name|setAlignment
argument_list|(
name|item
argument_list|,
name|alignment
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the alignment for \a item. The default alignment is     Qt::AlignTop | Qt::AlignLeft.      The alignment decides how the item is positioned within its assigned space     in the case where there's more space available in the layout than the     widgets can occupy.      \sa setAlignment() */
end_comment
begin_function
DECL|function|alignment
name|Qt
operator|::
name|Alignment
name|QGraphicsLinearLayout
operator|::
name|alignment
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|item
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|.
name|alignment
argument_list|(
name|item
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|// ###
end_comment
begin_endif
unit|QSizePolicy::ControlTypes QGraphicsLinearLayout::controlTypes(LayoutSide side) const {     return d->engine.controlTypes(side); }
endif|#
directive|endif
end_endif
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|count
name|int
name|QGraphicsLinearLayout
operator|::
name|count
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|engine
operator|.
name|itemCount
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp     When iterating from 0 and up, it will return the items in the visual arranged order. */
end_comment
begin_function
DECL|function|itemAt
name|QGraphicsLayoutItem
modifier|*
name|QGraphicsLinearLayout
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
name|QGraphicsLinearLayout
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
name|engine
operator|.
name|itemCount
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"QGraphicsLinearLayout::itemAt: invalid index %d"
argument_list|,
name|index
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|QGraphicsGridLayoutEngineItem
modifier|*
name|gridItem
init|=
cast|static_cast
argument_list|<
name|QGraphicsGridLayoutEngineItem
operator|*
argument_list|>
argument_list|(
name|d
operator|->
name|engine
operator|.
name|itemAt
argument_list|(
name|index
argument_list|)
argument_list|)
condition|)
name|item
operator|=
name|gridItem
operator|->
name|layoutItem
argument_list|()
expr_stmt|;
return|return
name|item
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|setGeometry
name|void
name|QGraphicsLinearLayout
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
name|QGraphicsLayout
operator|::
name|setGeometry
argument_list|(
name|rect
argument_list|)
expr_stmt|;
name|QRectF
name|effectiveRect
init|=
name|geometry
argument_list|()
decl_stmt|;
name|qreal
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|visualDir
init|=
name|d
operator|->
name|visualDirection
argument_list|()
decl_stmt|;
name|d
operator|->
name|engine
operator|.
name|setVisualDirection
argument_list|(
name|visualDir
argument_list|)
expr_stmt|;
if|if
condition|(
name|visualDir
operator|==
name|Qt
operator|::
name|RightToLeft
condition|)
name|qSwap
argument_list|(
name|left
argument_list|,
name|right
argument_list|)
expr_stmt|;
name|effectiveRect
operator|.
name|adjust
argument_list|(
operator|+
name|left
argument_list|,
operator|+
name|top
argument_list|,
operator|-
name|right
argument_list|,
operator|-
name|bottom
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QGRIDLAYOUTENGINE_DEBUG
if|if
condition|(
name|qt_graphicsLayoutDebug
argument_list|()
condition|)
block|{
specifier|static
name|int
name|counter
init|=
literal|0
decl_stmt|;
name|qDebug
argument_list|()
operator|<<
name|counter
operator|++
operator|<<
literal|"QGraphicsLinearLayout::setGeometry - "
operator|<<
name|rect
expr_stmt|;
name|dump
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|d
operator|->
name|engine
operator|.
name|setGeometries
argument_list|(
name|effectiveRect
argument_list|,
name|d
operator|->
name|styleInfo
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|QGRIDLAYOUTENGINE_DEBUG
if|if
condition|(
name|qt_graphicsLayoutDebug
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"post dump"
expr_stmt|;
name|dump
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSizeF
name|QGraphicsLinearLayout
operator|::
name|sizeHint
parameter_list|(
name|Qt
operator|::
name|SizeHint
name|which
parameter_list|,
specifier|const
name|QSizeF
modifier|&
name|constraint
parameter_list|)
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
name|qreal
name|left
decl_stmt|,
name|top
decl_stmt|,
name|right
decl_stmt|,
name|bottom
decl_stmt|;
name|getContentsMargins
argument_list|(
operator|&
name|left
argument_list|,
operator|&
name|top
argument_list|,
operator|&
name|right
argument_list|,
operator|&
name|bottom
argument_list|)
expr_stmt|;
specifier|const
name|QSizeF
name|extraMargins
argument_list|(
name|left
operator|+
name|right
argument_list|,
name|top
operator|+
name|bottom
argument_list|)
decl_stmt|;
return|return
name|d
operator|->
name|engine
operator|.
name|sizeHint
argument_list|(
name|which
argument_list|,
name|constraint
operator|-
name|extraMargins
argument_list|,
name|d
operator|->
name|styleInfo
argument_list|()
argument_list|)
operator|+
name|extraMargins
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|invalidate
name|void
name|QGraphicsLinearLayout
operator|::
name|invalidate
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|.
name|invalidate
argument_list|()
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|m_styleInfo
condition|)
name|d
operator|->
name|m_styleInfo
operator|->
name|invalidate
argument_list|()
expr_stmt|;
name|QGraphicsLayout
operator|::
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \internal */
end_comment
begin_function
DECL|function|dump
name|void
name|QGraphicsLinearLayout
operator|::
name|dump
parameter_list|(
name|int
name|indent
parameter_list|)
specifier|const
block|{
ifdef|#
directive|ifdef
name|QGRIDLAYOUTENGINE_DEBUG
if|if
condition|(
name|qt_graphicsLayoutDebug
argument_list|()
condition|)
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsLinearLayout
argument_list|)
expr_stmt|;
name|qDebug
argument_list|(
literal|"%*s%s layout"
argument_list|,
name|indent
argument_list|,
literal|""
argument_list|,
name|d
operator|->
name|orientation
operator|==
name|Qt
operator|::
name|Horizontal
condition|?
literal|"Horizontal"
else|:
literal|"Vertical"
argument_list|)
expr_stmt|;
name|d
operator|->
name|engine
operator|.
name|dump
argument_list|(
name|indent
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|indent
argument_list|)
expr_stmt|;
endif|#
directive|endif
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
