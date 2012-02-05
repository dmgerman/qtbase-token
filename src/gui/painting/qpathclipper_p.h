begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPATHCLIPPER_P_H
end_ifndef
begin_define
DECL|macro|QPATHCLIPPER_P_H
define|#
directive|define
name|QPATHCLIPPER_P_H
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
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
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
file|<QtGui/qpainterpath.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qlist.h>
end_include
begin_include
include|#
directive|include
file|<private/qbezier_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qdatabuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
DECL|variable|QWingedEdge
name|class
name|QWingedEdge
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QPathClipper
block|{
name|public
label|:
enum|enum
name|Operation
block|{
name|BoolAnd
block|,
name|BoolOr
block|,
name|BoolSub
block|,
name|Simplify
block|}
enum|;
name|public
label|:
name|QPathClipper
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|subject
argument_list|,
specifier|const
name|QPainterPath
operator|&
name|clip
argument_list|)
expr_stmt|;
name|QPainterPath
name|clip
parameter_list|(
name|Operation
name|op
init|=
name|BoolAnd
parameter_list|)
function_decl|;
name|bool
name|intersect
parameter_list|()
function_decl|;
name|bool
name|contains
parameter_list|()
function_decl|;
specifier|static
name|bool
name|pathToRect
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
name|QRectF
modifier|*
name|rect
init|=
literal|0
parameter_list|)
function_decl|;
specifier|static
name|QPainterPath
name|intersect
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|)
function_decl|;
name|private
label|:
name|Q_DISABLE_COPY
argument_list|(
name|QPathClipper
argument_list|)
expr|enum
name|ClipperMode
block|{
name|ClipMode
block|,
comment|// do the full clip
name|CheckMode
comment|// for contains/intersects (only interested in whether the result path is non-empty)
block|}
expr_stmt|;
name|bool
name|handleCrossingEdges
parameter_list|(
name|QWingedEdge
modifier|&
name|list
parameter_list|,
name|qreal
name|y
parameter_list|,
name|ClipperMode
name|mode
parameter_list|)
function_decl|;
name|bool
name|doClip
parameter_list|(
name|QWingedEdge
modifier|&
name|list
parameter_list|,
name|ClipperMode
name|mode
parameter_list|)
function_decl|;
name|QPainterPath
name|subjectPath
decl_stmt|;
name|QPainterPath
name|clipPath
decl_stmt|;
name|Operation
name|op
decl_stmt|;
name|int
name|aMask
decl_stmt|;
name|int
name|bMask
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_struct
DECL|struct|QPathVertex
struct|struct
name|QPathVertex
block|{
DECL|member|public
name|public
label|:
DECL|member|e
name|QPathVertex
argument_list|(
argument|const QPointF&p = QPointF()
argument_list|,
argument|int e = -
literal|1
argument_list|)
empty_stmt|;
name|operator
name|QPointF
argument_list|()
specifier|const
expr_stmt|;
DECL|member|edge
name|int
name|edge
decl_stmt|;
DECL|member|x
name|qreal
name|x
decl_stmt|;
DECL|member|y
name|qreal
name|y
decl_stmt|;
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QPathEdge
block|{
name|public
label|:
enum|enum
name|Traversal
block|{
name|RightTraversal
block|,
name|LeftTraversal
block|}
enum|;
enum|enum
name|Direction
block|{
name|Forward
block|,
name|Backward
block|}
enum|;
enum|enum
name|Type
block|{
name|Line
block|,
name|Curve
block|}
enum|;
name|QPathEdge
argument_list|(
argument|int a = -
literal|1
argument_list|,
argument|int b = -
literal|1
argument_list|)
empty_stmt|;
name|mutable
name|int
name|flag
decl_stmt|;
name|int
name|windingA
decl_stmt|;
name|int
name|windingB
decl_stmt|;
name|int
name|first
decl_stmt|;
name|int
name|second
decl_stmt|;
name|double
name|angle
decl_stmt|;
name|double
name|invAngle
decl_stmt|;
name|int
name|next
argument_list|(
name|Traversal
name|traversal
argument_list|,
name|Direction
name|direction
argument_list|)
decl|const
decl_stmt|;
name|void
name|setNext
parameter_list|(
name|Traversal
name|traversal
parameter_list|,
name|Direction
name|direction
parameter_list|,
name|int
name|next
parameter_list|)
function_decl|;
name|void
name|setNext
parameter_list|(
name|Direction
name|direction
parameter_list|,
name|int
name|next
parameter_list|)
function_decl|;
name|Direction
name|directionTo
argument_list|(
name|int
name|vertex
argument_list|)
decl|const
decl_stmt|;
name|int
name|vertex
argument_list|(
name|Direction
name|direction
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|int
name|m_next
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|QPathSegments
block|{
name|public
label|:
struct|struct
name|Intersection
block|{
name|int
name|vertex
decl_stmt|;
name|qreal
name|t
decl_stmt|;
name|int
name|next
decl_stmt|;
name|bool
name|operator
operator|<
operator|(
specifier|const
name|Intersection
operator|&
name|o
operator|)
specifier|const
block|{
return|return
name|t
operator|<
name|o
operator|.
name|t
return|;
block|}
block|}
struct|;
struct|struct
name|Segment
block|{
name|Segment
argument_list|(
argument|int pathId
argument_list|,
argument|int vertexA
argument_list|,
argument|int vertexB
argument_list|)
block|:
name|path
argument_list|(
name|pathId
argument_list|)
operator|,
name|va
argument_list|(
name|vertexA
argument_list|)
operator|,
name|vb
argument_list|(
name|vertexB
argument_list|)
operator|,
name|intersection
argument_list|(
argument|-
literal|1
argument_list|)
block|{         }
name|int
name|path
expr_stmt|;
comment|// vertices
name|int
name|va
decl_stmt|;
name|int
name|vb
decl_stmt|;
comment|// intersection index
name|int
name|intersection
decl_stmt|;
name|QRectF
name|bounds
decl_stmt|;
block|}
struct|;
name|QPathSegments
argument_list|(
argument|int reserve
argument_list|)
empty_stmt|;
name|void
name|setPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|void
name|addPath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|)
function_decl|;
name|int
name|intersections
argument_list|()
specifier|const
expr_stmt|;
name|int
name|segments
argument_list|()
specifier|const
expr_stmt|;
name|int
name|points
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|Segment
modifier|&
name|segmentAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QLineF
name|lineAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QRectF
modifier|&
name|elementBounds
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|int
name|pathId
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|QPointF
modifier|&
name|pointAt
argument_list|(
name|int
name|vertex
argument_list|)
decl|const
decl_stmt|;
name|int
name|addPoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|)
function_decl|;
specifier|const
name|Intersection
modifier|*
name|intersectionAt
argument_list|(
name|int
name|index
argument_list|)
decl|const
decl_stmt|;
name|void
name|addIntersection
parameter_list|(
name|int
name|index
parameter_list|,
specifier|const
name|Intersection
modifier|&
name|intersection
parameter_list|)
function_decl|;
name|void
name|mergePoints
parameter_list|()
function_decl|;
name|private
label|:
name|QDataBuffer
operator|<
name|QPointF
operator|>
name|m_points
expr_stmt|;
name|QDataBuffer
operator|<
name|Segment
operator|>
name|m_segments
expr_stmt|;
name|QDataBuffer
operator|<
name|Intersection
operator|>
name|m_intersections
expr_stmt|;
name|int
name|m_pathId
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_AUTOTEST_EXPORT
name|QWingedEdge
block|{
name|public
label|:
struct|struct
name|TraversalStatus
block|{
name|int
name|edge
decl_stmt|;
name|QPathEdge
operator|::
name|Traversal
name|traversal
expr_stmt|;
name|QPathEdge
operator|::
name|Direction
name|direction
expr_stmt|;
name|void
name|flipDirection
parameter_list|()
function_decl|;
name|void
name|flipTraversal
parameter_list|()
function_decl|;
name|void
name|flip
parameter_list|()
function_decl|;
block|}
struct|;
name|QWingedEdge
argument_list|()
expr_stmt|;
name|QWingedEdge
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|subject
argument_list|,
specifier|const
name|QPainterPath
operator|&
name|clip
argument_list|)
expr_stmt|;
name|void
name|simplify
parameter_list|()
function_decl|;
name|QPainterPath
name|toPath
argument_list|()
specifier|const
expr_stmt|;
name|int
name|edgeCount
argument_list|()
specifier|const
expr_stmt|;
name|QPathEdge
modifier|*
name|edge
parameter_list|(
name|int
name|edge
parameter_list|)
function_decl|;
specifier|const
name|QPathEdge
modifier|*
name|edge
argument_list|(
name|int
name|edge
argument_list|)
decl|const
decl_stmt|;
name|int
name|vertexCount
argument_list|()
specifier|const
expr_stmt|;
name|int
name|addVertex
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|)
function_decl|;
name|QPathVertex
modifier|*
name|vertex
parameter_list|(
name|int
name|vertex
parameter_list|)
function_decl|;
specifier|const
name|QPathVertex
modifier|*
name|vertex
argument_list|(
name|int
name|vertex
argument_list|)
decl|const
decl_stmt|;
name|TraversalStatus
name|next
argument_list|(
specifier|const
name|TraversalStatus
operator|&
name|status
argument_list|)
decl|const
decl_stmt|;
name|int
name|addEdge
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|a
parameter_list|,
specifier|const
name|QPointF
modifier|&
name|b
parameter_list|)
function_decl|;
name|int
name|addEdge
parameter_list|(
name|int
name|vertexA
parameter_list|,
name|int
name|vertexB
parameter_list|)
function_decl|;
name|bool
name|isInside
argument_list|(
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|QPathEdge
operator|::
name|Traversal
name|flip
argument_list|(
argument|QPathEdge::Traversal traversal
argument_list|)
expr_stmt|;
specifier|static
name|QPathEdge
operator|::
name|Direction
name|flip
argument_list|(
argument|QPathEdge::Direction direction
argument_list|)
expr_stmt|;
name|private
label|:
name|void
name|intersectAndAdd
parameter_list|()
function_decl|;
name|void
name|printNode
parameter_list|(
name|int
name|i
parameter_list|,
name|FILE
modifier|*
name|handle
parameter_list|)
function_decl|;
name|void
name|removeEdge
parameter_list|(
name|int
name|ei
parameter_list|)
function_decl|;
name|int
name|insert
parameter_list|(
specifier|const
name|QPathVertex
modifier|&
name|vertex
parameter_list|)
function_decl|;
name|TraversalStatus
name|findInsertStatus
argument_list|(
name|int
name|vertex
argument_list|,
name|int
name|edge
argument_list|)
decl|const
decl_stmt|;
name|qreal
name|delta
argument_list|(
name|int
name|vertex
argument_list|,
name|int
name|a
argument_list|,
name|int
name|b
argument_list|)
decl|const
decl_stmt|;
name|QDataBuffer
operator|<
name|QPathEdge
operator|>
name|m_edges
expr_stmt|;
name|QDataBuffer
operator|<
name|QPathVertex
operator|>
name|m_vertices
expr_stmt|;
name|QVector
operator|<
name|qreal
operator|>
name|m_splitPoints
expr_stmt|;
name|QPathSegments
name|m_segments
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|QPathEdge
specifier|inline
name|QPathEdge
operator|::
name|QPathEdge
argument_list|(
argument|int a
argument_list|,
argument|int b
argument_list|)
operator|:
name|flag
argument_list|(
literal|0
argument_list|)
operator|,
name|windingA
argument_list|(
literal|0
argument_list|)
operator|,
name|windingB
argument_list|(
literal|0
argument_list|)
operator|,
name|first
argument_list|(
name|a
argument_list|)
operator|,
name|second
argument_list|(
name|b
argument_list|)
operator|,
name|angle
argument_list|(
literal|0
argument_list|)
operator|,
name|invAngle
argument_list|(
literal|0
argument_list|)
block|{
name|m_next
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
operator|-
literal|1
block|;
name|m_next
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|=
operator|-
literal|1
block|;
name|m_next
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|=
operator|-
literal|1
block|;
name|m_next
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|=
operator|-
literal|1
block|; }
DECL|function|next
specifier|inline
name|int
name|QPathEdge
operator|::
name|next
argument_list|(
argument|Traversal traversal
argument_list|,
argument|Direction direction
argument_list|)
specifier|const
block|{
return|return
name|m_next
index|[
name|int
argument_list|(
name|traversal
argument_list|)
index|]
index|[
name|int
argument_list|(
name|direction
argument_list|)
index|]
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setNext
specifier|inline
name|void
name|QPathEdge
operator|::
name|setNext
argument_list|(
argument|Traversal traversal
argument_list|,
argument|Direction direction
argument_list|,
argument|int next
argument_list|)
block|{
name|m_next
index|[
name|int
argument_list|(
name|traversal
argument_list|)
index|]
index|[
name|int
argument_list|(
name|direction
argument_list|)
index|]
operator|=
name|next
block|; }
DECL|function|setNext
specifier|inline
name|void
name|QPathEdge
operator|::
name|setNext
argument_list|(
argument|Direction direction
argument_list|,
argument|int next
argument_list|)
block|{
name|m_next
index|[
literal|0
index|]
index|[
name|int
argument_list|(
name|direction
argument_list|)
index|]
operator|=
name|next
block|;
name|m_next
index|[
literal|1
index|]
index|[
name|int
argument_list|(
name|direction
argument_list|)
index|]
operator|=
name|next
block|; }
DECL|function|directionTo
specifier|inline
name|QPathEdge
operator|::
name|Direction
name|QPathEdge
operator|::
name|directionTo
argument_list|(
argument|int vertex
argument_list|)
specifier|const
block|{
return|return
name|first
operator|==
name|vertex
operator|?
name|Backward
operator|:
name|Forward
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|vertex
specifier|inline
name|int
name|QPathEdge
operator|::
name|vertex
argument_list|(
argument|Direction direction
argument_list|)
specifier|const
block|{
return|return
name|direction
operator|==
name|Backward
operator|?
name|first
operator|:
name|second
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|QPathVertex
specifier|inline
name|QPathVertex
operator|::
name|QPathVertex
argument_list|(
argument|const QPointF&p
argument_list|,
argument|int e
argument_list|)
operator|:
name|edge
argument_list|(
name|e
argument_list|)
operator|,
name|x
argument_list|(
name|p
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|y
argument_list|(
argument|p.y()
argument_list|)
block|{ }
DECL|function|QPointF
specifier|inline
name|QPathVertex
operator|::
name|operator
name|QPointF
argument_list|()
specifier|const
block|{
return|return
name|QPointF
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|QPathSegments
specifier|inline
name|QPathSegments
operator|::
name|QPathSegments
argument_list|(
argument|int reserve
argument_list|)
operator|:
name|m_points
argument_list|(
name|reserve
argument_list|)
operator|,
name|m_segments
argument_list|(
name|reserve
argument_list|)
operator|,
name|m_intersections
argument_list|(
argument|reserve
argument_list|)
block|{ }
DECL|function|segments
specifier|inline
name|int
name|QPathSegments
operator|::
name|segments
argument_list|()
specifier|const
block|{
return|return
name|m_segments
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|points
specifier|inline
name|int
name|QPathSegments
operator|::
name|points
argument_list|()
specifier|const
block|{
return|return
name|m_points
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|pointAt
specifier|inline
specifier|const
name|QPointF
operator|&
name|QPathSegments
operator|::
name|pointAt
argument_list|(
argument|int i
argument_list|)
specifier|const
block|{
return|return
name|m_points
operator|.
name|at
argument_list|(
name|i
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|addPoint
specifier|inline
name|int
name|QPathSegments
operator|::
name|addPoint
argument_list|(
argument|const QPointF&point
argument_list|)
block|{
name|m_points
operator|<<
name|point
block|;
return|return
name|m_points
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|segmentAt
specifier|inline
specifier|const
name|QPathSegments
operator|::
name|Segment
operator|&
name|QPathSegments
operator|::
name|segmentAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
return|return
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|lineAt
specifier|inline
specifier|const
name|QLineF
name|QPathSegments
operator|::
name|lineAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
specifier|const
name|Segment
operator|&
name|segment
operator|=
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
block|;
return|return
name|QLineF
argument_list|(
name|m_points
operator|.
name|at
argument_list|(
name|segment
operator|.
name|va
argument_list|)
argument_list|,
name|m_points
operator|.
name|at
argument_list|(
name|segment
operator|.
name|vb
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|elementBounds
specifier|inline
specifier|const
name|QRectF
operator|&
name|QPathSegments
operator|::
name|elementBounds
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
return|return
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|bounds
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|pathId
specifier|inline
name|int
name|QPathSegments
operator|::
name|pathId
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
return|return
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|path
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|intersectionAt
specifier|inline
specifier|const
name|QPathSegments
operator|::
name|Intersection
operator|*
name|QPathSegments
operator|::
name|intersectionAt
argument_list|(
argument|int index
argument_list|)
specifier|const
block|{
specifier|const
name|int
name|intersection
operator|=
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
operator|.
name|intersection
block|;
if|if
condition|(
name|intersection
operator|<
literal|0
condition|)
return|return
literal|0
return|;
else|else
return|return
operator|&
name|m_intersections
operator|.
name|at
argument_list|(
name|intersection
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|intersections
specifier|inline
name|int
name|QPathSegments
operator|::
name|intersections
argument_list|()
specifier|const
block|{
return|return
name|m_intersections
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|addIntersection
specifier|inline
name|void
name|QPathSegments
operator|::
name|addIntersection
argument_list|(
argument|int index
argument_list|,
argument|const Intersection&intersection
argument_list|)
block|{
name|m_intersections
operator|<<
name|intersection
block|;
name|Segment
operator|&
name|segment
operator|=
name|m_segments
operator|.
name|at
argument_list|(
name|index
argument_list|)
block|;
if|if
condition|(
name|segment
operator|.
name|intersection
operator|<
literal|0
condition|)
block|{
name|segment
operator|.
name|intersection
operator|=
name|m_intersections
operator|.
name|size
argument_list|()
operator|-
literal|1
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|Intersection
modifier|*
name|isect
init|=
operator|&
name|m_intersections
operator|.
name|at
argument_list|(
name|segment
operator|.
name|intersection
argument_list|)
decl_stmt|;
while|while
condition|(
name|isect
operator|->
name|next
operator|!=
literal|0
condition|)
name|isect
operator|+=
name|isect
operator|->
name|next
expr_stmt|;
name|isect
operator|->
name|next
operator|=
operator|(
name|m_intersections
operator|.
name|size
argument_list|()
operator|-
literal|1
operator|)
operator|-
operator|(
name|isect
operator|-
name|m_intersections
operator|.
name|data
argument_list|()
operator|)
expr_stmt|;
block|}
end_else
begin_expr_stmt
unit|}  inline
DECL|function|flipDirection
name|void
name|QWingedEdge
operator|::
name|TraversalStatus
operator|::
name|flipDirection
argument_list|()
block|{
name|direction
operator|=
name|QWingedEdge
operator|::
name|flip
argument_list|(
name|direction
argument_list|)
block|; }
DECL|function|flipTraversal
specifier|inline
name|void
name|QWingedEdge
operator|::
name|TraversalStatus
operator|::
name|flipTraversal
argument_list|()
block|{
name|traversal
operator|=
name|QWingedEdge
operator|::
name|flip
argument_list|(
name|traversal
argument_list|)
block|; }
DECL|function|flip
specifier|inline
name|void
name|QWingedEdge
operator|::
name|TraversalStatus
operator|::
name|flip
argument_list|()
block|{
name|flipDirection
argument_list|()
block|;
name|flipTraversal
argument_list|()
block|; }
DECL|function|edgeCount
specifier|inline
name|int
name|QWingedEdge
operator|::
name|edgeCount
argument_list|()
specifier|const
block|{
return|return
name|m_edges
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|edge
specifier|inline
name|QPathEdge
operator|*
name|QWingedEdge
operator|::
name|edge
argument_list|(
argument|int edge
argument_list|)
block|{
return|return
name|edge
operator|<
literal|0
operator|?
literal|0
operator|:
operator|&
name|m_edges
operator|.
name|at
argument_list|(
name|edge
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|edge
specifier|inline
specifier|const
name|QPathEdge
operator|*
name|QWingedEdge
operator|::
name|edge
argument_list|(
argument|int edge
argument_list|)
specifier|const
block|{
return|return
name|edge
operator|<
literal|0
operator|?
literal|0
operator|:
operator|&
name|m_edges
operator|.
name|at
argument_list|(
name|edge
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|vertexCount
specifier|inline
name|int
name|QWingedEdge
operator|::
name|vertexCount
argument_list|()
specifier|const
block|{
return|return
name|m_vertices
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|addVertex
specifier|inline
name|int
name|QWingedEdge
operator|::
name|addVertex
argument_list|(
argument|const QPointF&p
argument_list|)
block|{
name|m_vertices
operator|<<
name|p
block|;
return|return
name|m_vertices
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|vertex
specifier|inline
name|QPathVertex
operator|*
name|QWingedEdge
operator|::
name|vertex
argument_list|(
argument|int vertex
argument_list|)
block|{
return|return
name|vertex
operator|<
literal|0
operator|?
literal|0
operator|:
operator|&
name|m_vertices
operator|.
name|at
argument_list|(
name|vertex
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|vertex
specifier|inline
specifier|const
name|QPathVertex
operator|*
name|QWingedEdge
operator|::
name|vertex
argument_list|(
argument|int vertex
argument_list|)
specifier|const
block|{
return|return
name|vertex
operator|<
literal|0
operator|?
literal|0
operator|:
operator|&
name|m_vertices
operator|.
name|at
argument_list|(
name|vertex
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|flip
specifier|inline
name|QPathEdge
operator|::
name|Traversal
name|QWingedEdge
operator|::
name|flip
argument_list|(
argument|QPathEdge::Traversal traversal
argument_list|)
block|{
return|return
name|traversal
operator|==
name|QPathEdge
operator|::
name|RightTraversal
operator|?
name|QPathEdge
operator|::
name|LeftTraversal
operator|:
name|QPathEdge
operator|::
name|RightTraversal
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|flip
specifier|inline
name|QPathEdge
operator|::
name|Direction
name|QWingedEdge
operator|::
name|flip
argument_list|(
argument|QPathEdge::Direction direction
argument_list|)
block|{
return|return
name|direction
operator|==
name|QPathEdge
operator|::
name|Forward
operator|?
name|QPathEdge
operator|::
name|Backward
operator|:
name|QPathEdge
operator|::
name|Forward
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPATHCLIPPER_P_H
end_comment
end_unit
