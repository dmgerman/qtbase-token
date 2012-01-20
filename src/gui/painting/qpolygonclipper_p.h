begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPOLYGONCLIPPER_P_H
end_ifndef
begin_define
DECL|macro|QPOLYGONCLIPPER_P_H
define|#
directive|define
name|QPOLYGONCLIPPER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of other Qt classes.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"private/qdatabuffer_p.h"
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
comment|/* based on sutherland-hodgman line-by-line clipping, as described in    Computer Graphics and Principles */
DECL|variable|InType
DECL|variable|OutType
name|template
operator|<
name|typename
name|InType
operator|,
name|typename
name|OutType
operator|,
name|typename
name|CastType
operator|>
name|class
name|QPolygonClipper
block|{
name|public
operator|:
name|QPolygonClipper
argument_list|()
operator|:
name|buffer1
argument_list|(
literal|0
argument_list|)
block|,
name|buffer2
argument_list|(
literal|0
argument_list|)
block|{
name|x1
operator|=
name|y1
operator|=
name|x2
operator|=
name|y2
operator|=
literal|0
block|;     }
operator|~
name|QPolygonClipper
argument_list|()
block|{     }
name|void
name|setBoundingRect
argument_list|(
argument|const QRect bounds
argument_list|)
block|{
name|x1
operator|=
name|bounds
operator|.
name|x
argument_list|()
block|;
name|x2
operator|=
name|bounds
operator|.
name|x
argument_list|()
operator|+
name|bounds
operator|.
name|width
argument_list|()
block|;
name|y1
operator|=
name|bounds
operator|.
name|y
argument_list|()
block|;
name|y2
operator|=
name|bounds
operator|.
name|y
argument_list|()
operator|+
name|bounds
operator|.
name|height
argument_list|()
block|;     }
name|QRect
name|boundingRect
argument_list|()
block|{
return|return
name|QRect
argument_list|(
name|QPoint
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
argument_list|,
name|QPoint
argument_list|(
name|x2
argument_list|,
name|y2
argument_list|)
argument_list|)
return|;
block|}
specifier|inline
name|OutType
name|intersectLeft
argument_list|(
argument|const OutType&p1
argument_list|,
argument|const OutType&p2
argument_list|)
block|{
name|OutType
name|t
block|;
name|qreal
name|dy
operator|=
operator|(
name|p1
operator|.
name|y
operator|-
name|p2
operator|.
name|y
operator|)
operator|/
name|qreal
argument_list|(
name|p1
operator|.
name|x
operator|-
name|p2
operator|.
name|x
argument_list|)
block|;
name|t
operator|.
name|x
operator|=
name|x1
block|;
name|t
operator|.
name|y
operator|=
name|static_cast
operator|<
name|CastType
operator|>
operator|(
name|p2
operator|.
name|y
operator|+
operator|(
name|x1
operator|-
name|p2
operator|.
name|x
operator|)
operator|*
name|dy
operator|)
block|;
return|return
name|t
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|OutType
name|intersectRight
parameter_list|(
specifier|const
name|OutType
modifier|&
name|p1
parameter_list|,
specifier|const
name|OutType
modifier|&
name|p2
parameter_list|)
block|{
name|OutType
name|t
decl_stmt|;
name|qreal
name|dy
init|=
operator|(
name|p1
operator|.
name|y
operator|-
name|p2
operator|.
name|y
operator|)
operator|/
name|qreal
argument_list|(
name|p1
operator|.
name|x
operator|-
name|p2
operator|.
name|x
argument_list|)
decl_stmt|;
name|t
operator|.
name|x
operator|=
name|x2
expr_stmt|;
name|t
operator|.
name|y
operator|=
name|static_cast
operator|<
name|CastType
operator|>
operator|(
name|p2
operator|.
name|y
operator|+
operator|(
name|x2
operator|-
name|p2
operator|.
name|x
operator|)
operator|*
name|dy
operator|)
expr_stmt|;
return|return
name|t
return|;
block|}
end_function
begin_function
specifier|inline
name|OutType
name|intersectTop
parameter_list|(
specifier|const
name|OutType
modifier|&
name|p1
parameter_list|,
specifier|const
name|OutType
modifier|&
name|p2
parameter_list|)
block|{
name|OutType
name|t
decl_stmt|;
name|qreal
name|dx
init|=
operator|(
name|p1
operator|.
name|x
operator|-
name|p2
operator|.
name|x
operator|)
operator|/
name|qreal
argument_list|(
name|p1
operator|.
name|y
operator|-
name|p2
operator|.
name|y
argument_list|)
decl_stmt|;
name|t
operator|.
name|x
operator|=
name|static_cast
operator|<
name|CastType
operator|>
operator|(
name|p2
operator|.
name|x
operator|+
operator|(
name|y1
operator|-
name|p2
operator|.
name|y
operator|)
operator|*
name|dx
operator|)
expr_stmt|;
name|t
operator|.
name|y
operator|=
name|y1
expr_stmt|;
return|return
name|t
return|;
block|}
end_function
begin_function
specifier|inline
name|OutType
name|intersectBottom
parameter_list|(
specifier|const
name|OutType
modifier|&
name|p1
parameter_list|,
specifier|const
name|OutType
modifier|&
name|p2
parameter_list|)
block|{
name|OutType
name|t
decl_stmt|;
name|qreal
name|dx
init|=
operator|(
name|p1
operator|.
name|x
operator|-
name|p2
operator|.
name|x
operator|)
operator|/
name|qreal
argument_list|(
name|p1
operator|.
name|y
operator|-
name|p2
operator|.
name|y
argument_list|)
decl_stmt|;
name|t
operator|.
name|x
operator|=
name|static_cast
operator|<
name|CastType
operator|>
operator|(
name|p2
operator|.
name|x
operator|+
operator|(
name|y2
operator|-
name|p2
operator|.
name|y
operator|)
operator|*
name|dx
operator|)
expr_stmt|;
name|t
operator|.
name|y
operator|=
name|y2
expr_stmt|;
return|return
name|t
return|;
block|}
end_function
begin_function
name|void
name|clipPolygon
parameter_list|(
specifier|const
name|InType
modifier|*
name|inPoints
parameter_list|,
name|int
name|inCount
parameter_list|,
name|OutType
modifier|*
modifier|*
name|outPoints
parameter_list|,
name|int
modifier|*
name|outCount
parameter_list|,
name|bool
name|closePolygon
init|=
name|true
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|outPoints
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|outCount
argument_list|)
expr_stmt|;
if|if
condition|(
name|inCount
operator|<
literal|2
condition|)
block|{
operator|*
name|outCount
operator|=
literal|0
expr_stmt|;
return|return;
block|}
name|buffer1
operator|.
name|reset
argument_list|()
expr_stmt|;
name|buffer2
operator|.
name|reset
argument_list|()
expr_stmt|;
name|QDataBuffer
operator|<
name|OutType
operator|>
operator|*
name|source
operator|=
operator|&
name|buffer1
expr_stmt|;
name|QDataBuffer
operator|<
name|OutType
operator|>
operator|*
name|clipped
operator|=
operator|&
name|buffer2
expr_stmt|;
comment|// Gather some info since we are iterating through the points anyway..
name|bool
name|doLeft
init|=
name|false
decl_stmt|,
name|doRight
init|=
name|false
decl_stmt|,
name|doTop
init|=
name|false
decl_stmt|,
name|doBottom
init|=
name|false
decl_stmt|;
name|OutType
name|ot
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
name|inCount
condition|;
operator|++
name|i
control|)
block|{
name|ot
operator|=
name|inPoints
index|[
name|i
index|]
expr_stmt|;
name|clipped
operator|->
name|add
argument_list|(
name|ot
argument_list|)
expr_stmt|;
if|if
condition|(
name|ot
operator|.
name|x
operator|<
name|x1
condition|)
name|doLeft
operator|=
name|true
expr_stmt|;
elseif|else
if|if
condition|(
name|ot
operator|.
name|x
operator|>
name|x2
condition|)
name|doRight
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|ot
operator|.
name|y
operator|<
name|y1
condition|)
name|doTop
operator|=
name|true
expr_stmt|;
elseif|else
if|if
condition|(
name|ot
operator|.
name|y
operator|>
name|y2
condition|)
name|doBottom
operator|=
name|true
expr_stmt|;
block|}
if|if
condition|(
name|doLeft
operator|&&
name|clipped
operator|->
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|QDataBuffer
operator|<
name|OutType
operator|>
operator|*
name|tmp
operator|=
name|source
expr_stmt|;
name|source
operator|=
name|clipped
expr_stmt|;
name|clipped
operator|=
name|tmp
expr_stmt|;
name|clipped
operator|->
name|reset
argument_list|()
expr_stmt|;
name|int
name|lastPos
decl_stmt|,
name|start
decl_stmt|;
if|if
condition|(
name|closePolygon
condition|)
block|{
name|lastPos
operator|=
name|source
operator|->
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
name|start
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|lastPos
operator|=
literal|0
expr_stmt|;
name|start
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|x
operator|>=
name|x1
condition|)
name|clipped
operator|->
name|add
argument_list|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|inCount
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|OutType
modifier|&
name|cpt
init|=
name|source
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|OutType
modifier|&
name|ppt
init|=
name|source
operator|->
name|at
argument_list|(
name|lastPos
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpt
operator|.
name|x
operator|>=
name|x1
condition|)
block|{
if|if
condition|(
name|ppt
operator|.
name|x
operator|>=
name|x1
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectLeft
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|ppt
operator|.
name|x
operator|>=
name|x1
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectLeft
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|doRight
operator|&&
name|clipped
operator|->
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|QDataBuffer
operator|<
name|OutType
operator|>
operator|*
name|tmp
operator|=
name|source
expr_stmt|;
name|source
operator|=
name|clipped
expr_stmt|;
name|clipped
operator|=
name|tmp
expr_stmt|;
name|clipped
operator|->
name|reset
argument_list|()
expr_stmt|;
name|int
name|lastPos
decl_stmt|,
name|start
decl_stmt|;
if|if
condition|(
name|closePolygon
condition|)
block|{
name|lastPos
operator|=
name|source
operator|->
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
name|start
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|lastPos
operator|=
literal|0
expr_stmt|;
name|start
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|x
operator|<=
name|x2
condition|)
name|clipped
operator|->
name|add
argument_list|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|source
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|OutType
modifier|&
name|cpt
init|=
name|source
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|OutType
modifier|&
name|ppt
init|=
name|source
operator|->
name|at
argument_list|(
name|lastPos
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpt
operator|.
name|x
operator|<=
name|x2
condition|)
block|{
if|if
condition|(
name|ppt
operator|.
name|x
operator|<=
name|x2
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectRight
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|ppt
operator|.
name|x
operator|<=
name|x2
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectRight
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|doTop
operator|&&
name|clipped
operator|->
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|QDataBuffer
operator|<
name|OutType
operator|>
operator|*
name|tmp
operator|=
name|source
expr_stmt|;
name|source
operator|=
name|clipped
expr_stmt|;
name|clipped
operator|=
name|tmp
expr_stmt|;
name|clipped
operator|->
name|reset
argument_list|()
expr_stmt|;
name|int
name|lastPos
decl_stmt|,
name|start
decl_stmt|;
if|if
condition|(
name|closePolygon
condition|)
block|{
name|lastPos
operator|=
name|source
operator|->
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
name|start
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|lastPos
operator|=
literal|0
expr_stmt|;
name|start
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|y
operator|>=
name|y1
condition|)
name|clipped
operator|->
name|add
argument_list|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|source
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|OutType
modifier|&
name|cpt
init|=
name|source
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|OutType
modifier|&
name|ppt
init|=
name|source
operator|->
name|at
argument_list|(
name|lastPos
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpt
operator|.
name|y
operator|>=
name|y1
condition|)
block|{
if|if
condition|(
name|ppt
operator|.
name|y
operator|>=
name|y1
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectTop
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|ppt
operator|.
name|y
operator|>=
name|y1
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectTop
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|doBottom
operator|&&
name|clipped
operator|->
name|size
argument_list|()
operator|>
literal|1
condition|)
block|{
name|QDataBuffer
operator|<
name|OutType
operator|>
operator|*
name|tmp
operator|=
name|source
expr_stmt|;
name|source
operator|=
name|clipped
expr_stmt|;
name|clipped
operator|=
name|tmp
expr_stmt|;
name|clipped
operator|->
name|reset
argument_list|()
expr_stmt|;
name|int
name|lastPos
decl_stmt|,
name|start
decl_stmt|;
if|if
condition|(
name|closePolygon
condition|)
block|{
name|lastPos
operator|=
name|source
operator|->
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
name|start
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|lastPos
operator|=
literal|0
expr_stmt|;
name|start
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|y
operator|<=
name|y2
condition|)
name|clipped
operator|->
name|add
argument_list|(
name|source
operator|->
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
name|start
init|;
name|i
operator|<
name|source
operator|->
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|OutType
modifier|&
name|cpt
init|=
name|source
operator|->
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
specifier|const
name|OutType
modifier|&
name|ppt
init|=
name|source
operator|->
name|at
argument_list|(
name|lastPos
argument_list|)
decl_stmt|;
if|if
condition|(
name|cpt
operator|.
name|y
operator|<=
name|y2
condition|)
block|{
if|if
condition|(
name|ppt
operator|.
name|y
operator|<=
name|y2
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectBottom
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
name|clipped
operator|->
name|add
argument_list|(
name|cpt
argument_list|)
expr_stmt|;
block|}
block|}
elseif|else
if|if
condition|(
name|ppt
operator|.
name|y
operator|<=
name|y2
condition|)
block|{
name|clipped
operator|->
name|add
argument_list|(
name|intersectBottom
argument_list|(
name|cpt
argument_list|,
name|ppt
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|lastPos
operator|=
name|i
expr_stmt|;
block|}
block|}
if|if
condition|(
name|closePolygon
operator|&&
name|clipped
operator|->
name|size
argument_list|()
operator|>
literal|0
condition|)
block|{
comment|// close clipped polygon
if|if
condition|(
name|clipped
operator|->
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|x
operator|!=
name|clipped
operator|->
name|at
argument_list|(
name|clipped
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|x
operator|||
name|clipped
operator|->
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|y
operator|!=
name|clipped
operator|->
name|at
argument_list|(
name|clipped
operator|->
name|size
argument_list|()
operator|-
literal|1
argument_list|)
operator|.
name|y
condition|)
block|{
name|OutType
name|ot
init|=
name|clipped
operator|->
name|at
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|clipped
operator|->
name|add
argument_list|(
name|ot
argument_list|)
expr_stmt|;
block|}
block|}
operator|*
name|outCount
operator|=
name|clipped
operator|->
name|size
argument_list|()
expr_stmt|;
operator|*
name|outPoints
operator|=
name|clipped
operator|->
name|data
argument_list|()
expr_stmt|;
block|}
end_function
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|int
name|x1
decl_stmt|,
name|x2
decl_stmt|,
name|y1
decl_stmt|,
name|y2
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QDataBuffer
operator|<
name|OutType
operator|>
name|buffer1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QDataBuffer
operator|<
name|OutType
operator|>
name|buffer2
expr_stmt|;
end_expr_stmt
begin_macro
unit|};
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPOLYGONCLIPPER_P_H
end_comment
end_unit
