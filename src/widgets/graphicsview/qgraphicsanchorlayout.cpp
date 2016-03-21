begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*!     \class QGraphicsAnchorLayout     \brief The QGraphicsAnchorLayout class provides a layout where one can anchor widgets     together in Graphics View.     \since 4.6     \ingroup appearance     \ingroup geomanagement     \ingroup graphicsview-api     \inmodule QtWidgets      The anchor layout allows developers to specify how widgets should be placed relative to     each other, and to the layout itself. The specification is made by adding anchors to the     layout by calling addAnchor(), addAnchors() or addCornerAnchors().      Existing anchors in the layout can be accessed with the anchor() function.     Items that are anchored are automatically added to the layout, and if items     are removed, all their anchors will be automatically removed.      \div {class="float-left"}     \inlineimage simpleanchorlayout-example.png Using an anchor layout to align simple colored widgets.     \enddiv      Anchors are always set up between edges of an item, where the "center" is also considered to     be an edge. Consider the following example:      \snippet graphicsview/simpleanchorlayout/main.cpp adding anchors      Here, the right edge of item \c a is anchored to the left edge of item \c b and the bottom     edge of item \c a is anchored to the top edge of item \c b, with the result that     item \c b will be placed diagonally to the right and below item \c b.      The addCornerAnchors() function provides a simpler way of anchoring the corners     of two widgets than the two individual calls to addAnchor() shown in the code     above. Here, we see how a widget can be anchored to the top-left corner of the enclosing     layout:      \snippet graphicsview/simpleanchorlayout/main.cpp adding a corner anchor      In cases where anchors are used to match the widths or heights of widgets, it is     convenient to use the addAnchors() function. As with the other functions for specifying     anchors, it can also be used to anchor a widget to a layout.      \section1 Size Hints and Size Policies in an Anchor Layout      QGraphicsAnchorLayout respects each item's size hints and size policies.     Note that there are some properties of QSizePolicy that are \l{Known issues}{not respected}.      \section1 Spacing within an Anchor Layout      The layout may distribute some space between the items. If the spacing has not been     explicitly specified, the actual amount of space will usually be 0.      However, if the first edge is the \e opposite of the second edge (e.g., the right edge     of the first widget is anchored to the left edge of the second widget), the size of the     anchor will be queried from the style through a pixel metric:     \l{QStyle::}{PM_LayoutHorizontalSpacing} for horizontal anchors and     \l{QStyle::}{PM_LayoutVerticalSpacing} for vertical anchors.      If the spacing is negative, the items will overlap to some extent.       \section1 Known Issues     There are some features that QGraphicsAnchorLayout currently does not support.     This might change in the future, so avoid using these features if you want to     avoid any future regressions in behaviour:     \list      \li Stretch factors are not respected.      \li QSizePolicy::ExpandFlag is not respected.      \li Height for width is not respected.      \endlist      \sa QGraphicsLinearLayout, QGraphicsGridLayout, QGraphicsLayout */
end_comment
begin_comment
comment|/*!     \class QGraphicsAnchor     \brief The QGraphicsAnchor class represents an anchor between two items in a            QGraphicsAnchorLayout.     \since 4.6     \ingroup appearance     \ingroup geomanagement     \ingroup graphicsview-api     \inmodule QtWidgets      The graphics anchor provides an API that enables you to query and manipulate the     properties an anchor has. When an anchor is added to the layout with     QGraphicsAnchorLayout::addAnchor(), a QGraphicsAnchor instance is returned where the properties     are initialized to their default values. The properties can then be further changed, and they     will be picked up the next time the layout is activated.      \sa QGraphicsAnchorLayout::anchor()  */
end_comment
begin_include
include|#
directive|include
file|"qgraphicsanchorlayout_p.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GRAPHICSVIEW
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QGraphicsAnchor
name|QGraphicsAnchor
operator|::
name|QGraphicsAnchor
parameter_list|(
name|QGraphicsAnchorLayout
modifier|*
name|parentLayout
parameter_list|)
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|(
operator|new
name|QGraphicsAnchorPrivate
operator|)
argument_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchor
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|parentLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|layoutPrivate
operator|=
name|parentLayout
operator|->
name|d_func
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Removes the QGraphicsAnchor object from the layout and destroys it. */
end_comment
begin_destructor
DECL|function|~QGraphicsAnchor
name|QGraphicsAnchor
operator|::
name|~
name|QGraphicsAnchor
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \property QGraphicsAnchor::sizePolicy     \brief the size policy for the QGraphicsAnchor.      By setting the size policy on an anchor you can configure how the anchor can resize itself     from its preferred spacing. For instance, if the anchor has the size policy     QSizePolicy::Minimum, the spacing is the minimum size of the anchor. However, its size     can grow up to the anchors maximum size. If the default size policy is QSizePolicy::Fixed,     the anchor can neither grow or shrink, which means that the only size the anchor can have     is the spacing. QSizePolicy::Fixed is the default size policy.     QGraphicsAnchor always has a minimum spacing of 0 and a very large maximum spacing.      \sa QGraphicsAnchor::spacing */
end_comment
begin_function
DECL|function|setSizePolicy
name|void
name|QGraphicsAnchor
operator|::
name|setSizePolicy
parameter_list|(
name|QSizePolicy
operator|::
name|Policy
name|policy
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchor
argument_list|)
expr_stmt|;
name|d
operator|->
name|setSizePolicy
argument_list|(
name|policy
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sizePolicy
name|QSizePolicy
operator|::
name|Policy
name|QGraphicsAnchor
operator|::
name|sizePolicy
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsAnchor
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|sizePolicy
return|;
block|}
end_function
begin_comment
comment|/*!     \property QGraphicsAnchor::spacing     \brief the preferred space between items in the QGraphicsAnchorLayout.      Depending on the anchor type, the default spacing is either     0 or a value returned from the style.      \sa QGraphicsAnchorLayout::addAnchor() */
end_comment
begin_function
DECL|function|setSpacing
name|void
name|QGraphicsAnchor
operator|::
name|setSpacing
parameter_list|(
name|qreal
name|spacing
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchor
argument_list|)
expr_stmt|;
name|d
operator|->
name|setSpacing
argument_list|(
name|spacing
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|spacing
name|qreal
name|QGraphicsAnchor
operator|::
name|spacing
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsAnchor
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|spacing
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|unsetSpacing
name|void
name|QGraphicsAnchor
operator|::
name|unsetSpacing
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchor
argument_list|)
expr_stmt|;
name|d
operator|->
name|unsetSpacing
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Constructs a QGraphicsAnchorLayout instance.  \a parent is passed to     QGraphicsLayout's constructor.   */
end_comment
begin_constructor
DECL|function|QGraphicsAnchorLayout
name|QGraphicsAnchorLayout
operator|::
name|QGraphicsAnchorLayout
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
name|QGraphicsAnchorLayoutPrivate
argument_list|()
argument_list|,
name|parent
argument_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|createLayoutEdges
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     Destroys the QGraphicsAnchorLayout object. */
end_comment
begin_destructor
DECL|function|~QGraphicsAnchorLayout
name|QGraphicsAnchorLayout
operator|::
name|~
name|QGraphicsAnchorLayout
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
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
name|d
operator|->
name|items
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
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
name|d
operator|->
name|removeCenterConstraints
argument_list|(
name|this
argument_list|,
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeCenterConstraints
argument_list|(
name|this
argument_list|,
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|d
operator|->
name|deleteLayoutEdges
argument_list|()
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|itemCenterConstraints
index|[
literal|0
index|]
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|itemCenterConstraints
index|[
literal|1
index|]
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|items
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|d
operator|->
name|m_vertexList
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Creates an anchor between the edge \a firstEdge of item \a firstItem and the edge \a secondEdge     of item \a secondItem. The spacing of the anchor is picked up from the style. Anchors     between a layout edge and an item edge will have a size of 0.     If there is already an anchor between the edges, the new anchor will replace the old one.      \a firstItem and \a secondItem are automatically added to the layout if they are not part     of the layout. This means that count() can increase by up to 2.      The spacing an anchor will get depends on the type of anchor. For instance, anchors from the     Right edge of one item to the Left edge of another (or vice versa) will use the default     horizontal spacing. The same behaviour applies to Bottom to Top anchors, (but they will use     the default vertical spacing). For all other anchor combinations, the spacing will be 0.     All anchoring functions will follow this rule.      The spacing can also be set manually by using QGraphicsAnchor::setSpacing() method.      Calling this function where \a firstItem or \a secondItem are ancestors of the layout have     undefined behaviour.      \sa addAnchors(), addCornerAnchors()  */
end_comment
begin_function
name|QGraphicsAnchor
modifier|*
DECL|function|addAnchor
name|QGraphicsAnchorLayout
operator|::
name|addAnchor
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|firstItem
parameter_list|,
name|Qt
operator|::
name|AnchorPoint
name|firstEdge
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|secondItem
parameter_list|,
name|Qt
operator|::
name|AnchorPoint
name|secondEdge
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|QGraphicsAnchor
modifier|*
name|a
init|=
name|d
operator|->
name|addAnchor
argument_list|(
name|firstItem
argument_list|,
name|firstEdge
argument_list|,
name|secondItem
argument_list|,
name|secondEdge
argument_list|)
decl_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
return|return
name|a
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the anchor between the anchor points defined by \a firstItem and \a firstEdge and     \a secondItem and \a secondEdge. If there is no such anchor, the function will return 0. */
end_comment
begin_function
name|QGraphicsAnchor
modifier|*
DECL|function|anchor
name|QGraphicsAnchorLayout
operator|::
name|anchor
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|firstItem
parameter_list|,
name|Qt
operator|::
name|AnchorPoint
name|firstEdge
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|secondItem
parameter_list|,
name|Qt
operator|::
name|AnchorPoint
name|secondEdge
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|getAnchor
argument_list|(
name|firstItem
argument_list|,
name|firstEdge
argument_list|,
name|secondItem
argument_list|,
name|secondEdge
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Creates two anchors between \a firstItem and \a secondItem specified by the corners,     \a firstCorner and \a secondCorner, where one is for the horizontal edge and another     one for the vertical edge.      This is a convenience function, since anchoring corners can be expressed as anchoring     two edges. For instance:      \snippet graphicsview/simpleanchorlayout/main.cpp adding a corner anchor in two steps      This can also be achieved with the following line of code:      \snippet graphicsview/simpleanchorlayout/main.cpp adding a corner anchor      If there is already an anchor between the edge pairs, it will be replaced by the anchors that     this function specifies.      \a firstItem and \a secondItem are automatically added to the layout if they are not part of the     layout. This means that count() can increase by up to 2.      \sa addAnchor(), addAnchors() */
end_comment
begin_function
DECL|function|addCornerAnchors
name|void
name|QGraphicsAnchorLayout
operator|::
name|addCornerAnchors
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|firstItem
parameter_list|,
name|Qt
operator|::
name|Corner
name|firstCorner
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|secondItem
parameter_list|,
name|Qt
operator|::
name|Corner
name|secondCorner
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
comment|// Horizontal anchor
name|Qt
operator|::
name|AnchorPoint
name|firstEdge
init|=
operator|(
name|firstCorner
operator|&
literal|1
condition|?
name|Qt
operator|::
name|AnchorRight
else|:
name|Qt
operator|::
name|AnchorLeft
operator|)
decl_stmt|;
name|Qt
operator|::
name|AnchorPoint
name|secondEdge
init|=
operator|(
name|secondCorner
operator|&
literal|1
condition|?
name|Qt
operator|::
name|AnchorRight
else|:
name|Qt
operator|::
name|AnchorLeft
operator|)
decl_stmt|;
if|if
condition|(
name|d
operator|->
name|addAnchor
argument_list|(
name|firstItem
argument_list|,
name|firstEdge
argument_list|,
name|secondItem
argument_list|,
name|secondEdge
argument_list|)
condition|)
block|{
comment|// Vertical anchor
name|firstEdge
operator|=
operator|(
name|firstCorner
operator|&
literal|2
condition|?
name|Qt
operator|::
name|AnchorBottom
else|:
name|Qt
operator|::
name|AnchorTop
operator|)
expr_stmt|;
name|secondEdge
operator|=
operator|(
name|secondCorner
operator|&
literal|2
condition|?
name|Qt
operator|::
name|AnchorBottom
else|:
name|Qt
operator|::
name|AnchorTop
operator|)
expr_stmt|;
name|d
operator|->
name|addAnchor
argument_list|(
name|firstItem
argument_list|,
name|firstEdge
argument_list|,
name|secondItem
argument_list|,
name|secondEdge
argument_list|)
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Anchors two or four edges of \a firstItem with the corresponding     edges of \a secondItem, so that \a firstItem has the same size as     \a secondItem in the dimensions specified by \a orientations.      For example, the following example anchors the left and right edges of two items     to match their widths:      \snippet graphicsview/simpleanchorlayout/main.cpp adding anchors to match sizes in two steps      This can also be achieved using the following line of code:      \snippet graphicsview/simpleanchorlayout/main.cpp adding anchors to match sizes      \sa addAnchor(), addCornerAnchors() */
end_comment
begin_function
DECL|function|addAnchors
name|void
name|QGraphicsAnchorLayout
operator|::
name|addAnchors
parameter_list|(
name|QGraphicsLayoutItem
modifier|*
name|firstItem
parameter_list|,
name|QGraphicsLayoutItem
modifier|*
name|secondItem
parameter_list|,
name|Qt
operator|::
name|Orientations
name|orientations
parameter_list|)
block|{
name|bool
name|ok
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|orientations
operator|&
name|Qt
operator|::
name|Horizontal
condition|)
block|{
comment|// Currently, if the first is ok, then the rest of the calls should be ok
name|ok
operator|=
name|addAnchor
argument_list|(
name|secondItem
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|,
name|firstItem
argument_list|,
name|Qt
operator|::
name|AnchorLeft
argument_list|)
operator|!=
literal|0
expr_stmt|;
if|if
condition|(
name|ok
condition|)
name|addAnchor
argument_list|(
name|firstItem
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|,
name|secondItem
argument_list|,
name|Qt
operator|::
name|AnchorRight
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|orientations
operator|&
name|Qt
operator|::
name|Vertical
operator|&&
name|ok
condition|)
block|{
name|addAnchor
argument_list|(
name|secondItem
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|,
name|firstItem
argument_list|,
name|Qt
operator|::
name|AnchorTop
argument_list|)
expr_stmt|;
name|addAnchor
argument_list|(
name|firstItem
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|,
name|secondItem
argument_list|,
name|Qt
operator|::
name|AnchorBottom
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_comment
comment|/*!     Sets the default horizontal spacing for the anchor layout to \a spacing.      \sa horizontalSpacing(), setVerticalSpacing(), setSpacing() */
end_comment
begin_function
DECL|function|setHorizontalSpacing
name|void
name|QGraphicsAnchorLayout
operator|::
name|setHorizontalSpacing
parameter_list|(
name|qreal
name|spacing
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|spacings
index|[
literal|0
index|]
operator|=
name|spacing
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the default vertical spacing for the anchor layout to \a spacing.      \sa verticalSpacing(), setHorizontalSpacing(), setSpacing() */
end_comment
begin_function
DECL|function|setVerticalSpacing
name|void
name|QGraphicsAnchorLayout
operator|::
name|setVerticalSpacing
parameter_list|(
name|qreal
name|spacing
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|spacings
index|[
literal|1
index|]
operator|=
name|spacing
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Sets the default horizontal and the default vertical spacing for the anchor layout to \a spacing.      If an item is anchored with no spacing associated with the anchor, it will use the default     spacing.      QGraphicsAnchorLayout does not support negative spacings. Setting a negative value will unset the     previous spacing and make the layout use the spacing provided by the current widget style.      \sa setHorizontalSpacing(), setVerticalSpacing() */
end_comment
begin_function
DECL|function|setSpacing
name|void
name|QGraphicsAnchorLayout
operator|::
name|setSpacing
parameter_list|(
name|qreal
name|spacing
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|d
operator|->
name|spacings
index|[
literal|0
index|]
operator|=
name|d
operator|->
name|spacings
index|[
literal|1
index|]
operator|=
name|spacing
expr_stmt|;
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the default horizontal spacing for the anchor layout.      \sa verticalSpacing(), setHorizontalSpacing() */
end_comment
begin_function
DECL|function|horizontalSpacing
name|qreal
name|QGraphicsAnchorLayout
operator|::
name|horizontalSpacing
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|styleInfo
argument_list|()
operator|.
name|defaultSpacing
argument_list|(
name|Qt
operator|::
name|Horizontal
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the default vertical spacing for the anchor layout.      \sa horizontalSpacing(), setVerticalSpacing() */
end_comment
begin_function
DECL|function|verticalSpacing
name|qreal
name|QGraphicsAnchorLayout
operator|::
name|verticalSpacing
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|styleInfo
argument_list|()
operator|.
name|defaultSpacing
argument_list|(
name|Qt
operator|::
name|Vertical
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|setGeometry
name|void
name|QGraphicsAnchorLayout
operator|::
name|setGeometry
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|geom
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|QGraphicsLayout
operator|::
name|setGeometry
argument_list|(
name|geom
argument_list|)
expr_stmt|;
name|d
operator|->
name|calculateVertexPositions
argument_list|(
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|d
operator|->
name|calculateVertexPositions
argument_list|(
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|d
operator|->
name|setItemsGeometries
argument_list|(
name|geom
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Removes the layout item at \a index without destroying it. Ownership of     the item is transferred to the caller.      Removing an item will also remove any of the anchors associated with it.      \sa itemAt(), count() */
end_comment
begin_function
DECL|function|removeAt
name|void
name|QGraphicsAnchorLayout
operator|::
name|removeAt
parameter_list|(
name|int
name|index
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|QGraphicsLayoutItem
modifier|*
name|item
init|=
name|d
operator|->
name|items
operator|.
name|value
argument_list|(
name|index
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|item
condition|)
return|return;
comment|// Removing an item affects both horizontal and vertical graphs
name|d
operator|->
name|removeCenterConstraints
argument_list|(
name|item
argument_list|,
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Horizontal
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeCenterConstraints
argument_list|(
name|item
argument_list|,
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Vertical
argument_list|)
expr_stmt|;
name|d
operator|->
name|removeAnchors
argument_list|(
name|item
argument_list|)
expr_stmt|;
name|d
operator|->
name|items
operator|.
name|remove
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|item
operator|->
name|setParentLayoutItem
argument_list|(
literal|0
argument_list|)
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
DECL|function|count
name|int
name|QGraphicsAnchorLayout
operator|::
name|count
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|items
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
DECL|function|itemAt
name|QGraphicsLayoutItem
modifier|*
name|QGraphicsAnchorLayout
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
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|items
operator|.
name|value
argument_list|(
name|index
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|invalidate
name|void
name|QGraphicsAnchorLayout
operator|::
name|invalidate
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
name|QGraphicsLayout
operator|::
name|invalidate
argument_list|()
expr_stmt|;
name|d
operator|->
name|calculateGraphCacheDirty
operator|=
literal|true
expr_stmt|;
name|d
operator|->
name|styleInfoDirty
operator|=
literal|true
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|sizeHint
name|QSizeF
name|QGraphicsAnchorLayout
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
name|Q_UNUSED
argument_list|(
name|constraint
argument_list|)
expr_stmt|;
name|Q_D
argument_list|(
specifier|const
name|QGraphicsAnchorLayout
argument_list|)
expr_stmt|;
comment|// Some setup calculations are delayed until the information is
comment|// actually needed, avoiding unnecessary recalculations when
comment|// adding multiple anchors.
comment|// sizeHint() / effectiveSizeHint() already have a cache
comment|// mechanism, using invalidate() to force recalculation. However
comment|// sizeHint() is called three times after invalidation (for max,
comment|// min and pref), but we just need do our setup once.
cast|const_cast
argument_list|<
name|QGraphicsAnchorLayoutPrivate
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
operator|->
name|calculateGraphs
argument_list|()
expr_stmt|;
comment|// ### apply constraint!
name|QSizeF
name|engineSizeHint
argument_list|(
name|d
operator|->
name|sizeHints
index|[
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Horizontal
index|]
index|[
name|which
index|]
argument_list|,
name|d
operator|->
name|sizeHints
index|[
name|QGraphicsAnchorLayoutPrivate
operator|::
name|Vertical
index|]
index|[
name|which
index|]
argument_list|)
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
return|return
name|engineSizeHint
operator|+
name|QSizeF
argument_list|(
name|left
operator|+
name|right
argument_list|,
name|top
operator|+
name|bottom
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qgraphicsanchorlayout.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_GRAPHICSVIEW
end_comment
end_unit
