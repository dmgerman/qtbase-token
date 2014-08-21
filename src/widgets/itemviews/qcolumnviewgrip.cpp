begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_QCOLUMNVIEW
end_ifndef
begin_include
include|#
directive|include
file|"qcolumnviewgrip_p.h"
end_include
begin_include
include|#
directive|include
file|<qstyleoption.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qbrush.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*     \internal     class QColumnViewGrip      QColumnViewGrip is created to go inside QAbstractScrollArea's corner.     When the mouse it moved it will resize the scroll area and emit's a signal.  */
end_comment
begin_comment
comment|/*     \internal     \fn void QColumnViewGrip::gripMoved()     Signal that is emitted when the grip moves the parent widget.  */
end_comment
begin_comment
comment|/*!     Creates a new QColumnViewGrip with the given \a parent to view a model.     Use setModel() to set the model. */
end_comment
begin_constructor
DECL|function|QColumnViewGrip
name|QColumnViewGrip
operator|::
name|QColumnViewGrip
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
operator|*
operator|new
name|QColumnViewGripPrivate
argument_list|,
name|parent
argument_list|,
literal|0
argument_list|)
block|{
ifndef|#
directive|ifndef
name|QT_NO_CURSOR
name|setCursor
argument_list|(
name|Qt
operator|::
name|SplitHCursor
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_constructor
begin_comment
comment|/*!   \internal */
end_comment
begin_constructor
DECL|function|QColumnViewGrip
name|QColumnViewGrip
operator|::
name|QColumnViewGrip
parameter_list|(
name|QColumnViewGripPrivate
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
block|{ }
end_constructor
begin_comment
comment|/*!   Destroys the view. */
end_comment
begin_destructor
DECL|function|~QColumnViewGrip
name|QColumnViewGrip
operator|::
name|~
name|QColumnViewGrip
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     Attempt to resize the parent object by \a offset     returns the amount of offset that it was actually able to resized */
end_comment
begin_function
DECL|function|moveGrip
name|int
name|QColumnViewGrip
operator|::
name|moveGrip
parameter_list|(
name|int
name|offset
parameter_list|)
block|{
name|QWidget
modifier|*
name|parentWidget
init|=
operator|(
name|QWidget
operator|*
operator|)
name|parent
argument_list|()
decl_stmt|;
comment|// first resize the parent
name|int
name|oldWidth
init|=
name|parentWidget
operator|->
name|width
argument_list|()
decl_stmt|;
name|int
name|newWidth
init|=
name|oldWidth
decl_stmt|;
if|if
condition|(
name|isRightToLeft
argument_list|()
condition|)
name|newWidth
operator|-=
name|offset
expr_stmt|;
else|else
name|newWidth
operator|+=
name|offset
expr_stmt|;
name|newWidth
operator|=
name|qMax
argument_list|(
name|parentWidget
operator|->
name|minimumWidth
argument_list|()
argument_list|,
name|newWidth
argument_list|)
expr_stmt|;
name|parentWidget
operator|->
name|resize
argument_list|(
name|newWidth
argument_list|,
name|parentWidget
operator|->
name|height
argument_list|()
argument_list|)
expr_stmt|;
comment|// Then have the view move the widget
name|int
name|realOffset
init|=
name|parentWidget
operator|->
name|width
argument_list|()
operator|-
name|oldWidth
decl_stmt|;
name|int
name|oldX
init|=
name|parentWidget
operator|->
name|x
argument_list|()
decl_stmt|;
if|if
condition|(
name|realOffset
operator|!=
literal|0
condition|)
emit|emit
name|gripMoved
argument_list|(
name|realOffset
argument_list|)
emit|;
if|if
condition|(
name|isRightToLeft
argument_list|()
condition|)
name|realOffset
operator|=
operator|-
literal|1
operator|*
operator|(
name|oldX
operator|-
name|parentWidget
operator|->
name|x
argument_list|()
operator|)
expr_stmt|;
return|return
name|realOffset
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|paintEvent
name|void
name|QColumnViewGrip
operator|::
name|paintEvent
parameter_list|(
name|QPaintEvent
modifier|*
name|event
parameter_list|)
block|{
name|QPainter
name|painter
argument_list|(
name|this
argument_list|)
decl_stmt|;
name|QStyleOption
name|opt
decl_stmt|;
name|opt
operator|.
name|initFrom
argument_list|(
name|this
argument_list|)
expr_stmt|;
name|style
argument_list|()
operator|->
name|drawControl
argument_list|(
name|QStyle
operator|::
name|CE_ColumnViewGrip
argument_list|,
operator|&
name|opt
argument_list|,
operator|&
name|painter
argument_list|,
name|this
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp     Resize the parent window to the sizeHint */
end_comment
begin_function
DECL|function|mouseDoubleClickEvent
name|void
name|QColumnViewGrip
operator|::
name|mouseDoubleClickEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|event
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|parentWidget
init|=
operator|(
name|QWidget
operator|*
operator|)
name|parent
argument_list|()
decl_stmt|;
name|int
name|offset
init|=
name|parentWidget
operator|->
name|sizeHint
argument_list|()
operator|.
name|width
argument_list|()
operator|-
name|parentWidget
operator|->
name|width
argument_list|()
decl_stmt|;
if|if
condition|(
name|isRightToLeft
argument_list|()
condition|)
name|offset
operator|*=
operator|-
literal|1
expr_stmt|;
name|moveGrip
argument_list|(
name|offset
argument_list|)
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp     Begin watching for mouse movements */
end_comment
begin_function
DECL|function|mousePressEvent
name|void
name|QColumnViewGrip
operator|::
name|mousePressEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QColumnViewGrip
argument_list|)
expr_stmt|;
name|d
operator|->
name|originalXLocation
operator|=
name|event
operator|->
name|globalX
argument_list|()
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp     Calculate the movement of the grip and moveGrip() and emit gripMoved */
end_comment
begin_function
DECL|function|mouseMoveEvent
name|void
name|QColumnViewGrip
operator|::
name|mouseMoveEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QColumnViewGrip
argument_list|)
expr_stmt|;
name|int
name|offset
init|=
name|event
operator|->
name|globalX
argument_list|()
operator|-
name|d
operator|->
name|originalXLocation
decl_stmt|;
name|d
operator|->
name|originalXLocation
operator|=
name|moveGrip
argument_list|(
name|offset
argument_list|)
operator|+
name|d
operator|->
name|originalXLocation
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp     Stop watching for mouse movements */
end_comment
begin_function
DECL|function|mouseReleaseEvent
name|void
name|QColumnViewGrip
operator|::
name|mouseReleaseEvent
parameter_list|(
name|QMouseEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QColumnViewGrip
argument_list|)
expr_stmt|;
name|d
operator|->
name|originalXLocation
operator|=
operator|-
literal|1
expr_stmt|;
name|event
operator|->
name|accept
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*  * private object implementation  */
end_comment
begin_constructor
DECL|function|QColumnViewGripPrivate
name|QColumnViewGripPrivate
operator|::
name|QColumnViewGripPrivate
parameter_list|()
member_init_list|:
name|QWidgetPrivate
argument_list|()
member_init_list|,
name|originalXLocation
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_QCOLUMNVIEW
end_comment
end_unit
