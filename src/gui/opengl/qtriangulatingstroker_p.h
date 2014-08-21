begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QTRIANGULATINGSTROKER_P_H
end_ifndef
begin_define
DECL|macro|QTRIANGULATINGSTROKER_P_H
define|#
directive|define
name|QTRIANGULATINGSTROKER_P_H
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
file|<private/qdatabuffer_p.h>
end_include
begin_include
include|#
directive|include
file|<qvarlengtharray.h>
end_include
begin_include
include|#
directive|include
file|<private/qvectorpath_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qbezier_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qnumeric_p.h>
end_include
begin_include
include|#
directive|include
file|<private/qmath_p.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Q_GUI_EXPORT
name|QTriangulatingStroker
block|{
name|public
label|:
name|QTriangulatingStroker
argument_list|()
operator|:
name|m_vertices
argument_list|(
literal|0
argument_list|)
operator|,
name|m_cx
argument_list|(
literal|0
argument_list|)
operator|,
name|m_cy
argument_list|(
literal|0
argument_list|)
operator|,
name|m_nvx
argument_list|(
literal|0
argument_list|)
operator|,
name|m_nvy
argument_list|(
literal|0
argument_list|)
operator|,
name|m_width
argument_list|(
literal|1
argument_list|)
operator|,
name|m_miter_limit
argument_list|(
literal|2
argument_list|)
operator|,
name|m_roundness
argument_list|(
literal|0
argument_list|)
operator|,
name|m_sin_theta
argument_list|(
literal|0
argument_list|)
operator|,
name|m_cos_theta
argument_list|(
literal|0
argument_list|)
operator|,
name|m_inv_scale
argument_list|(
literal|1
argument_list|)
operator|,
name|m_curvyness_mul
argument_list|(
literal|1
argument_list|)
operator|,
name|m_curvyness_add
argument_list|(
literal|0
argument_list|)
operator|,
name|m_join_style
argument_list|(
name|Qt
operator|::
name|BevelJoin
argument_list|)
operator|,
name|m_cap_style
argument_list|(
argument|Qt::SquareCap
argument_list|)
block|{}
name|void
name|process
argument_list|(
argument|const QVectorPath&path
argument_list|,
argument|const QPen&pen
argument_list|,
argument|const QRectF&clip
argument_list|,
argument|QPainter::RenderHints hints
argument_list|)
expr_stmt|;
specifier|inline
name|int
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
specifier|inline
specifier|const
name|float
operator|*
name|vertices
argument_list|()
specifier|const
block|{
return|return
name|m_vertices
operator|.
name|data
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setInvScale
parameter_list|(
name|qreal
name|invScale
parameter_list|)
block|{
name|m_inv_scale
operator|=
name|invScale
expr_stmt|;
block|}
name|private
label|:
specifier|inline
name|void
name|emitLineSegment
parameter_list|(
name|float
name|x
parameter_list|,
name|float
name|y
parameter_list|,
name|float
name|nx
parameter_list|,
name|float
name|ny
parameter_list|)
function_decl|;
name|void
name|moveTo
parameter_list|(
specifier|const
name|qreal
modifier|*
name|pts
parameter_list|)
function_decl|;
specifier|inline
name|void
name|lineTo
parameter_list|(
specifier|const
name|qreal
modifier|*
name|pts
parameter_list|)
function_decl|;
name|void
name|cubicTo
parameter_list|(
specifier|const
name|qreal
modifier|*
name|pts
parameter_list|)
function_decl|;
name|void
name|join
parameter_list|(
specifier|const
name|qreal
modifier|*
name|pts
parameter_list|)
function_decl|;
specifier|inline
name|void
name|normalVector
parameter_list|(
name|float
name|x1
parameter_list|,
name|float
name|y1
parameter_list|,
name|float
name|x2
parameter_list|,
name|float
name|y2
parameter_list|,
name|float
modifier|*
name|nx
parameter_list|,
name|float
modifier|*
name|ny
parameter_list|)
function_decl|;
name|void
name|endCap
parameter_list|(
specifier|const
name|qreal
modifier|*
name|pts
parameter_list|)
function_decl|;
name|void
name|arcPoints
argument_list|(
name|float
name|cx
argument_list|,
name|float
name|cy
argument_list|,
name|float
name|fromX
argument_list|,
name|float
name|fromY
argument_list|,
name|float
name|toX
argument_list|,
name|float
name|toY
argument_list|,
name|QVarLengthArray
operator|<
name|float
operator|>
operator|&
name|points
argument_list|)
decl_stmt|;
name|void
name|endCapOrJoinClosed
parameter_list|(
specifier|const
name|qreal
modifier|*
name|start
parameter_list|,
specifier|const
name|qreal
modifier|*
name|cur
parameter_list|,
name|bool
name|implicitClose
parameter_list|,
name|bool
name|endsAtStart
parameter_list|)
function_decl|;
name|QDataBuffer
operator|<
name|float
operator|>
name|m_vertices
expr_stmt|;
name|float
name|m_cx
decl_stmt|,
name|m_cy
decl_stmt|;
comment|// current points
name|float
name|m_nvx
decl_stmt|,
name|m_nvy
decl_stmt|;
comment|// normal vector...
name|float
name|m_width
decl_stmt|;
name|qreal
name|m_miter_limit
decl_stmt|;
name|int
name|m_roundness
decl_stmt|;
comment|// Number of line segments in a round join
name|qreal
name|m_sin_theta
decl_stmt|;
comment|// sin(m_roundness / 360);
name|qreal
name|m_cos_theta
decl_stmt|;
comment|// cos(m_roundness / 360);
name|qreal
name|m_inv_scale
decl_stmt|;
name|float
name|m_curvyness_mul
decl_stmt|;
name|float
name|m_curvyness_add
decl_stmt|;
name|Qt
operator|::
name|PenJoinStyle
name|m_join_style
expr_stmt|;
name|Qt
operator|::
name|PenCapStyle
name|m_cap_style
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDashedStrokeProcessor
block|{
name|public
label|:
name|QDashedStrokeProcessor
argument_list|()
expr_stmt|;
name|void
name|process
argument_list|(
specifier|const
name|QVectorPath
operator|&
name|path
argument_list|,
specifier|const
name|QPen
operator|&
name|pen
argument_list|,
specifier|const
name|QRectF
operator|&
name|clip
argument_list|,
name|QPainter
operator|::
name|RenderHints
name|hints
argument_list|)
decl_stmt|;
specifier|inline
name|void
name|addElement
argument_list|(
name|QPainterPath
operator|::
name|ElementType
name|type
argument_list|,
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|)
block|{
name|m_points
operator|.
name|add
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|m_points
operator|.
name|add
argument_list|(
name|y
argument_list|)
expr_stmt|;
name|m_types
operator|.
name|add
argument_list|(
name|type
argument_list|)
expr_stmt|;
block|}
specifier|inline
name|int
name|elementCount
argument_list|()
specifier|const
block|{
return|return
name|m_types
operator|.
name|size
argument_list|()
return|;
block|}
specifier|inline
name|qreal
operator|*
name|points
argument_list|()
specifier|const
block|{
return|return
name|m_points
operator|.
name|data
argument_list|()
return|;
block|}
specifier|inline
name|QPainterPath
operator|::
name|ElementType
operator|*
name|elementTypes
argument_list|()
specifier|const
block|{
return|return
name|m_types
operator|.
name|data
argument_list|()
return|;
block|}
specifier|inline
name|void
name|setInvScale
parameter_list|(
name|qreal
name|invScale
parameter_list|)
block|{
name|m_inv_scale
operator|=
name|invScale
expr_stmt|;
block|}
name|private
label|:
name|QDataBuffer
operator|<
name|qreal
operator|>
name|m_points
expr_stmt|;
name|QDataBuffer
operator|<
name|QPainterPath
operator|::
name|ElementType
operator|>
name|m_types
expr_stmt|;
name|QDashStroker
name|m_dash_stroker
decl_stmt|;
name|qreal
name|m_inv_scale
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
DECL|function|normalVector
specifier|inline
name|void
name|QTriangulatingStroker
operator|::
name|normalVector
argument_list|(
argument|float x1
argument_list|,
argument|float y1
argument_list|,
argument|float x2
argument_list|,
argument|float y2
argument_list|,
argument|float *nx
argument_list|,
argument|float *ny
argument_list|)
block|{
name|float
name|dx
operator|=
name|x2
operator|-
name|x1
block|;
name|float
name|dy
operator|=
name|y2
operator|-
name|y1
block|;
name|Q_ASSERT
argument_list|(
name|dx
operator|!=
literal|0
operator|||
name|dy
operator|!=
literal|0
argument_list|)
block|;
name|float
name|pw
block|;
if|if
condition|(
name|dx
operator|==
literal|0
condition|)
name|pw
operator|=
name|m_width
operator|/
name|qAbs
argument_list|(
name|dy
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|dy
operator|==
literal|0
condition|)
name|pw
operator|=
name|m_width
operator|/
name|qAbs
argument_list|(
name|dx
argument_list|)
expr_stmt|;
else|else
name|pw
operator|=
name|m_width
operator|/
name|sqrt
argument_list|(
name|dx
operator|*
name|dx
operator|+
name|dy
operator|*
name|dy
argument_list|)
expr_stmt|;
operator|*
name|nx
operator|=
operator|-
name|dy
operator|*
name|pw
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|*
name|ny
operator|=
name|dx
operator|*
name|pw
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  inline
DECL|function|emitLineSegment
name|void
name|QTriangulatingStroker
operator|::
name|emitLineSegment
argument_list|(
argument|float x
argument_list|,
argument|float y
argument_list|,
argument|float vx
argument_list|,
argument|float vy
argument_list|)
block|{
name|m_vertices
operator|.
name|add
argument_list|(
name|x
operator|+
name|vx
argument_list|)
block|;
name|m_vertices
operator|.
name|add
argument_list|(
name|y
operator|+
name|vy
argument_list|)
block|;
name|m_vertices
operator|.
name|add
argument_list|(
name|x
operator|-
name|vx
argument_list|)
block|;
name|m_vertices
operator|.
name|add
argument_list|(
name|y
operator|-
name|vy
argument_list|)
block|; }
DECL|function|lineTo
name|void
name|QTriangulatingStroker
operator|::
name|lineTo
argument_list|(
argument|const qreal *pts
argument_list|)
block|{
name|emitLineSegment
argument_list|(
name|pts
index|[
literal|0
index|]
argument_list|,
name|pts
index|[
literal|1
index|]
argument_list|,
name|m_nvx
argument_list|,
name|m_nvy
argument_list|)
block|;
name|m_cx
operator|=
name|pts
index|[
literal|0
index|]
block|;
name|m_cy
operator|=
name|pts
index|[
literal|1
index|]
block|; }
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
end_unit
