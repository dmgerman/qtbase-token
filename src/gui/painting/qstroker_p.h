begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QSTROKER_P_H
end_ifndef
begin_define
DECL|macro|QSTROKER_P_H
define|#
directive|define
name|QSTROKER_P_H
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
file|"QtGui/qpainterpath.h"
end_include
begin_include
include|#
directive|include
file|"private/qdatabuffer_p.h"
end_include
begin_include
include|#
directive|include
file|"private/qnumeric_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|// #define QFIXED_IS_26_6
end_comment
begin_if
if|#
directive|if
name|defined
name|QFIXED_IS_26_6
end_if
begin_typedef
DECL|typedef|qfixed
typedef|typedef
name|int
name|qfixed
typedef|;
end_typedef
begin_define
DECL|macro|qt_real_to_fixed
define|#
directive|define
name|qt_real_to_fixed
parameter_list|(
name|real
parameter_list|)
value|qfixed(real * 64)
end_define
begin_define
DECL|macro|qt_int_to_fixed
define|#
directive|define
name|qt_int_to_fixed
parameter_list|(
name|real
parameter_list|)
value|qfixed(int(real)<< 6)
end_define
begin_define
DECL|macro|qt_fixed_to_real
define|#
directive|define
name|qt_fixed_to_real
parameter_list|(
name|fixed
parameter_list|)
value|qreal(fixed / qreal(64))
end_define
begin_define
DECL|macro|qt_fixed_to_int
define|#
directive|define
name|qt_fixed_to_int
parameter_list|(
name|fixed
parameter_list|)
value|int(fixed>> 6)
end_define
begin_struct
DECL|struct|qfixed2d
struct|struct
name|qfixed2d
block|{
DECL|member|x
name|qfixed
name|x
decl_stmt|;
DECL|member|y
name|qfixed
name|y
decl_stmt|;
DECL|function|operator
name|bool
name|operator
operator|==
operator|(
specifier|const
name|qfixed2d
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|x
operator|==
name|other
operator|.
name|x
operator|&&
name|y
operator|==
name|other
operator|.
name|y
return|;
block|}
block|}
struct|;
end_struct
begin_elif
elif|#
directive|elif
name|defined
name|QFIXED_IS_32_32
end_elif
begin_typedef
typedef|typedef
name|qint64
name|qfixed
typedef|;
end_typedef
begin_define
define|#
directive|define
name|qt_real_to_fixed
parameter_list|(
name|real
parameter_list|)
value|qfixed(real * double(qint64(1)<< 32))
end_define
begin_define
define|#
directive|define
name|qt_fixed_to_real
parameter_list|(
name|fixed
parameter_list|)
value|qreal(fixed / double(qint64(1)<< 32))
end_define
begin_struct
struct|struct
name|qfixed2d
block|{
name|qfixed
name|x
decl_stmt|;
name|qfixed
name|y
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|qfixed2d
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|x
operator|==
name|other
operator|.
name|x
operator|&&
name|y
operator|==
name|other
operator|.
name|y
return|;
block|}
block|}
struct|;
end_struct
begin_elif
elif|#
directive|elif
name|defined
name|QFIXED_IS_16_16
end_elif
begin_typedef
typedef|typedef
name|int
name|qfixed
typedef|;
end_typedef
begin_define
define|#
directive|define
name|qt_real_to_fixed
parameter_list|(
name|real
parameter_list|)
value|qfixed(real * qreal(1<< 16))
end_define
begin_define
define|#
directive|define
name|qt_fixed_to_real
parameter_list|(
name|fixed
parameter_list|)
value|qreal(fixed / qreal(1<< 16))
end_define
begin_struct
struct|struct
name|qfixed2d
block|{
name|qfixed
name|x
decl_stmt|;
name|qfixed
name|y
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|qfixed2d
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|x
operator|==
name|other
operator|.
name|x
operator|&&
name|y
operator|==
name|other
operator|.
name|y
return|;
block|}
block|}
struct|;
end_struct
begin_else
else|#
directive|else
end_else
begin_typedef
typedef|typedef
name|qreal
name|qfixed
typedef|;
end_typedef
begin_define
define|#
directive|define
name|qt_real_to_fixed
parameter_list|(
name|real
parameter_list|)
value|qfixed(real)
end_define
begin_define
define|#
directive|define
name|qt_fixed_to_real
parameter_list|(
name|fixed
parameter_list|)
value|fixed
end_define
begin_struct
struct|struct
name|qfixed2d
block|{
name|qfixed
name|x
decl_stmt|;
name|qfixed
name|y
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|qfixed2d
operator|&
name|other
operator|)
specifier|const
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|x
argument_list|,
name|other
operator|.
name|x
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|y
argument_list|,
name|other
operator|.
name|y
argument_list|)
return|;
block|}
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_PATH_KAPPA
define|#
directive|define
name|QT_PATH_KAPPA
value|0.5522847498
end_define
begin_function_decl
name|QPointF
name|qt_curves_for_arc
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|qreal
name|startAngle
parameter_list|,
name|qreal
name|sweepLength
parameter_list|,
name|QPointF
modifier|*
name|controlPoints
parameter_list|,
name|int
modifier|*
name|point_count
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|qreal
name|qt_t_for_arc_angle
parameter_list|(
name|qreal
name|angle
parameter_list|)
function_decl|;
end_function_decl
begin_typedef
DECL|typedef|qStrokerMoveToHook
typedef|typedef
name|void
function_decl|(
modifier|*
name|qStrokerMoveToHook
function_decl|)
parameter_list|(
name|qfixed
name|x
parameter_list|,
name|qfixed
name|y
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|qStrokerLineToHook
typedef|typedef
name|void
function_decl|(
modifier|*
name|qStrokerLineToHook
function_decl|)
parameter_list|(
name|qfixed
name|x
parameter_list|,
name|qfixed
name|y
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|qStrokerCubicToHook
typedef|typedef
name|void
function_decl|(
modifier|*
name|qStrokerCubicToHook
function_decl|)
parameter_list|(
name|qfixed
name|c1x
parameter_list|,
name|qfixed
name|c1y
parameter_list|,
name|qfixed
name|c2x
parameter_list|,
name|qfixed
name|c2y
parameter_list|,
name|qfixed
name|ex
parameter_list|,
name|qfixed
name|ey
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|// qtransform.cpp
end_comment
begin_function_decl
name|Q_GUI_EXPORT
name|bool
name|qt_scaleForTransform
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|transform
parameter_list|,
name|qreal
modifier|*
name|scale
parameter_list|)
function_decl|;
end_function_decl
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStrokerOps
block|{
name|public
label|:
struct|struct
name|Element
block|{
name|QPainterPath
operator|::
name|ElementType
name|type
expr_stmt|;
name|qfixed
name|x
decl_stmt|;
name|qfixed
name|y
decl_stmt|;
specifier|inline
name|bool
name|isMoveTo
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|QPainterPath
operator|::
name|MoveToElement
return|;
block|}
specifier|inline
name|bool
name|isLineTo
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|QPainterPath
operator|::
name|LineToElement
return|;
block|}
specifier|inline
name|bool
name|isCurveTo
argument_list|()
specifier|const
block|{
return|return
name|type
operator|==
name|QPainterPath
operator|::
name|CurveToElement
return|;
block|}
name|operator
name|qfixed2d
parameter_list|()
block|{
name|qfixed2d
name|pt
init|=
block|{
name|x
block|,
name|y
block|}
decl_stmt|;
return|return
name|pt
return|;
block|}
block|}
struct|;
name|QStrokerOps
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|QStrokerOps
argument_list|()
expr_stmt|;
name|void
name|setMoveToHook
parameter_list|(
name|qStrokerMoveToHook
name|moveToHook
parameter_list|)
block|{
name|m_moveTo
operator|=
name|moveToHook
expr_stmt|;
block|}
name|void
name|setLineToHook
parameter_list|(
name|qStrokerLineToHook
name|lineToHook
parameter_list|)
block|{
name|m_lineTo
operator|=
name|lineToHook
expr_stmt|;
block|}
name|void
name|setCubicToHook
parameter_list|(
name|qStrokerCubicToHook
name|cubicToHook
parameter_list|)
block|{
name|m_cubicTo
operator|=
name|cubicToHook
expr_stmt|;
block|}
name|virtual
name|void
name|begin
parameter_list|(
name|void
modifier|*
name|customData
parameter_list|)
function_decl|;
name|virtual
name|void
name|end
parameter_list|()
function_decl|;
specifier|inline
name|void
name|moveTo
parameter_list|(
name|qfixed
name|x
parameter_list|,
name|qfixed
name|y
parameter_list|)
function_decl|;
specifier|inline
name|void
name|lineTo
parameter_list|(
name|qfixed
name|x
parameter_list|,
name|qfixed
name|y
parameter_list|)
function_decl|;
specifier|inline
name|void
name|cubicTo
parameter_list|(
name|qfixed
name|x1
parameter_list|,
name|qfixed
name|y1
parameter_list|,
name|qfixed
name|x2
parameter_list|,
name|qfixed
name|y2
parameter_list|,
name|qfixed
name|ex
parameter_list|,
name|qfixed
name|ey
parameter_list|)
function_decl|;
name|void
name|strokePath
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|path
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
function_decl|;
name|void
name|strokePolygon
parameter_list|(
specifier|const
name|QPointF
modifier|*
name|points
parameter_list|,
name|int
name|pointCount
parameter_list|,
name|bool
name|implicit_close
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
function_decl|;
name|void
name|strokeEllipse
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|ellipse
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
specifier|const
name|QTransform
modifier|&
name|matrix
parameter_list|)
function_decl|;
name|QRectF
name|clipRect
argument_list|()
specifier|const
block|{
return|return
name|m_clip_rect
return|;
block|}
name|void
name|setClipRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|clip
parameter_list|)
block|{
name|m_clip_rect
operator|=
name|clip
expr_stmt|;
block|}
name|void
name|setCurveThresholdFromTransform
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|transform
parameter_list|)
block|{
name|qreal
name|scale
decl_stmt|;
name|qt_scaleForTransform
argument_list|(
name|transform
argument_list|,
operator|&
name|scale
argument_list|)
expr_stmt|;
name|m_dashThreshold
operator|=
name|scale
operator|==
literal|0
condition|?
name|qreal
argument_list|(
literal|0.5
argument_list|)
else|:
operator|(
name|qreal
argument_list|(
literal|0.5
argument_list|)
operator|/
name|scale
operator|)
expr_stmt|;
block|}
name|void
name|setCurveThreshold
parameter_list|(
name|qfixed
name|threshold
parameter_list|)
block|{
name|m_curveThreshold
operator|=
name|threshold
expr_stmt|;
block|}
name|qfixed
name|curveThreshold
argument_list|()
specifier|const
block|{
return|return
name|m_curveThreshold
return|;
block|}
name|protected
label|:
specifier|inline
name|void
name|emitMoveTo
parameter_list|(
name|qfixed
name|x
parameter_list|,
name|qfixed
name|y
parameter_list|)
function_decl|;
specifier|inline
name|void
name|emitLineTo
parameter_list|(
name|qfixed
name|x
parameter_list|,
name|qfixed
name|y
parameter_list|)
function_decl|;
specifier|inline
name|void
name|emitCubicTo
parameter_list|(
name|qfixed
name|c1x
parameter_list|,
name|qfixed
name|c1y
parameter_list|,
name|qfixed
name|c2x
parameter_list|,
name|qfixed
name|c2y
parameter_list|,
name|qfixed
name|ex
parameter_list|,
name|qfixed
name|ey
parameter_list|)
function_decl|;
name|virtual
name|void
name|processCurrentSubpath
parameter_list|()
init|=
literal|0
function_decl|;
name|QDataBuffer
operator|<
name|Element
operator|>
name|m_elements
expr_stmt|;
name|QRectF
name|m_clip_rect
decl_stmt|;
name|qfixed
name|m_curveThreshold
decl_stmt|;
name|qfixed
name|m_dashThreshold
decl_stmt|;
name|void
modifier|*
name|m_customData
decl_stmt|;
name|qStrokerMoveToHook
name|m_moveTo
decl_stmt|;
name|qStrokerLineToHook
name|m_lineTo
decl_stmt|;
name|qStrokerCubicToHook
name|m_cubicTo
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QStroker
range|:
name|public
name|QStrokerOps
block|{
name|public
operator|:
expr|enum
name|LineJoinMode
block|{
name|FlatJoin
block|,
name|SquareJoin
block|,
name|MiterJoin
block|,
name|RoundJoin
block|,
name|RoundCap
block|,
name|SvgMiterJoin
block|}
block|;
name|QStroker
argument_list|()
block|;
operator|~
name|QStroker
argument_list|()
block|;
name|void
name|setStrokeWidth
argument_list|(
argument|qfixed width
argument_list|)
block|{
name|m_strokeWidth
operator|=
name|width
block|; }
name|qfixed
name|strokeWidth
argument_list|()
specifier|const
block|{
return|return
name|m_strokeWidth
return|;
block|}
name|void
name|setCapStyle
argument_list|(
argument|Qt::PenCapStyle capStyle
argument_list|)
block|{
name|m_capStyle
operator|=
name|joinModeForCap
argument_list|(
name|capStyle
argument_list|)
block|; }
name|Qt
operator|::
name|PenCapStyle
name|capStyle
argument_list|()
specifier|const
block|{
return|return
name|capForJoinMode
argument_list|(
name|m_capStyle
argument_list|)
return|;
block|}
name|LineJoinMode
name|capStyleMode
argument_list|()
specifier|const
block|{
return|return
name|m_capStyle
return|;
block|}
name|void
name|setJoinStyle
argument_list|(
argument|Qt::PenJoinStyle style
argument_list|)
block|{
name|m_joinStyle
operator|=
name|joinModeForJoin
argument_list|(
name|style
argument_list|)
block|; }
name|Qt
operator|::
name|PenJoinStyle
name|joinStyle
argument_list|()
specifier|const
block|{
return|return
name|joinForJoinMode
argument_list|(
name|m_joinStyle
argument_list|)
return|;
block|}
name|LineJoinMode
name|joinStyleMode
argument_list|()
specifier|const
block|{
return|return
name|m_joinStyle
return|;
block|}
name|void
name|setMiterLimit
argument_list|(
argument|qfixed length
argument_list|)
block|{
name|m_miterLimit
operator|=
name|length
block|; }
name|qfixed
name|miterLimit
argument_list|()
specifier|const
block|{
return|return
name|m_miterLimit
return|;
block|}
name|void
name|joinPoints
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|,
argument|const QLineF&nextLine
argument_list|,
argument|LineJoinMode join
argument_list|)
block|;
specifier|inline
name|void
name|emitMoveTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|;
specifier|inline
name|void
name|emitLineTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|;
specifier|inline
name|void
name|emitCubicTo
argument_list|(
argument|qfixed c1x
argument_list|,
argument|qfixed c1y
argument_list|,
argument|qfixed c2x
argument_list|,
argument|qfixed c2y
argument_list|,
argument|qfixed ex
argument_list|,
argument|qfixed ey
argument_list|)
block|;
name|protected
operator|:
specifier|static
name|Qt
operator|::
name|PenCapStyle
name|capForJoinMode
argument_list|(
argument|LineJoinMode mode
argument_list|)
block|;
specifier|static
name|LineJoinMode
name|joinModeForCap
argument_list|(
name|Qt
operator|::
name|PenCapStyle
argument_list|)
block|;
specifier|static
name|Qt
operator|::
name|PenJoinStyle
name|joinForJoinMode
argument_list|(
argument|LineJoinMode mode
argument_list|)
block|;
specifier|static
name|LineJoinMode
name|joinModeForJoin
argument_list|(
argument|Qt::PenJoinStyle joinStyle
argument_list|)
block|;
name|virtual
name|void
name|processCurrentSubpath
argument_list|()
block|;
name|qfixed
name|m_strokeWidth
block|;
name|qfixed
name|m_miterLimit
block|;
name|LineJoinMode
name|m_capStyle
block|;
name|LineJoinMode
name|m_joinStyle
block|;
name|qfixed
name|m_back1X
block|;
name|qfixed
name|m_back1Y
block|;
name|qfixed
name|m_back2X
block|;
name|qfixed
name|m_back2Y
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QDashStroker
range|:
name|public
name|QStrokerOps
block|{
name|public
operator|:
name|QDashStroker
argument_list|(
name|QStroker
operator|*
name|stroker
argument_list|)
block|;
operator|~
name|QDashStroker
argument_list|()
block|;
name|QStroker
operator|*
name|stroker
argument_list|()
specifier|const
block|{
return|return
name|m_stroker
return|;
block|}
specifier|static
name|QVector
operator|<
name|qfixed
operator|>
name|patternForStyle
argument_list|(
argument|Qt::PenStyle style
argument_list|)
block|;
name|void
name|setDashPattern
argument_list|(
argument|const QVector<qfixed>&dashPattern
argument_list|)
block|{
name|m_dashPattern
operator|=
name|dashPattern
block|; }
name|QVector
operator|<
name|qfixed
operator|>
name|dashPattern
argument_list|()
specifier|const
block|{
return|return
name|m_dashPattern
return|;
block|}
name|void
name|setDashOffset
argument_list|(
argument|qreal offset
argument_list|)
block|{
name|m_dashOffset
operator|=
name|offset
block|; }
name|qreal
name|dashOffset
argument_list|()
specifier|const
block|{
return|return
name|m_dashOffset
return|;
block|}
name|virtual
name|void
name|begin
argument_list|(
name|void
operator|*
name|data
argument_list|)
block|;
name|virtual
name|void
name|end
argument_list|()
block|;
specifier|inline
name|void
name|setStrokeWidth
argument_list|(
argument|qreal width
argument_list|)
block|{
name|m_stroke_width
operator|=
name|width
block|; }
specifier|inline
name|void
name|setMiterLimit
argument_list|(
argument|qreal limit
argument_list|)
block|{
name|m_miter_limit
operator|=
name|limit
block|; }
name|protected
operator|:
name|virtual
name|void
name|processCurrentSubpath
argument_list|()
block|;
name|QStroker
operator|*
name|m_stroker
block|;
name|QVector
operator|<
name|qfixed
operator|>
name|m_dashPattern
block|;
name|qreal
name|m_dashOffset
block|;
name|qreal
name|m_stroke_width
block|;
name|qreal
name|m_miter_limit
block|; }
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*******************************************************************************  * QStrokerOps inline membmers  */
end_comment
begin_expr_stmt
DECL|function|emitMoveTo
specifier|inline
name|void
name|QStrokerOps
operator|::
name|emitMoveTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_moveTo
argument_list|)
block|;
name|m_moveTo
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|m_customData
argument_list|)
block|; }
DECL|function|emitLineTo
specifier|inline
name|void
name|QStrokerOps
operator|::
name|emitLineTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_lineTo
argument_list|)
block|;
name|m_lineTo
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
name|m_customData
argument_list|)
block|; }
DECL|function|emitCubicTo
specifier|inline
name|void
name|QStrokerOps
operator|::
name|emitCubicTo
argument_list|(
argument|qfixed c1x
argument_list|,
argument|qfixed c1y
argument_list|,
argument|qfixed c2x
argument_list|,
argument|qfixed c2y
argument_list|,
argument|qfixed ex
argument_list|,
argument|qfixed ey
argument_list|)
block|{
name|Q_ASSERT
argument_list|(
name|m_cubicTo
argument_list|)
block|;
name|m_cubicTo
argument_list|(
name|c1x
argument_list|,
name|c1y
argument_list|,
name|c2x
argument_list|,
name|c2y
argument_list|,
name|ex
argument_list|,
name|ey
argument_list|,
name|m_customData
argument_list|)
block|; }
DECL|function|moveTo
specifier|inline
name|void
name|QStrokerOps
operator|::
name|moveTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|{
if|if
condition|(
name|m_elements
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|processCurrentSubpath
argument_list|()
expr_stmt|;
name|m_elements
operator|.
name|reset
argument_list|()
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|Element
name|e
init|=
block|{
name|QPainterPath
operator|::
name|MoveToElement
block|,
name|x
block|,
name|y
block|}
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|m_elements
operator|.
name|add
argument_list|(
name|e
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  inline
DECL|function|lineTo
name|void
name|QStrokerOps
operator|::
name|lineTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|{
name|Element
name|e
operator|=
block|{
name|QPainterPath
operator|::
name|LineToElement
block|,
name|x
block|,
name|y
block|}
block|;
name|m_elements
operator|.
name|add
argument_list|(
name|e
argument_list|)
block|; }
DECL|function|cubicTo
specifier|inline
name|void
name|QStrokerOps
operator|::
name|cubicTo
argument_list|(
argument|qfixed x1
argument_list|,
argument|qfixed y1
argument_list|,
argument|qfixed x2
argument_list|,
argument|qfixed y2
argument_list|,
argument|qfixed ex
argument_list|,
argument|qfixed ey
argument_list|)
block|{
name|Element
name|c1
operator|=
block|{
name|QPainterPath
operator|::
name|CurveToElement
block|,
name|x1
block|,
name|y1
block|}
block|;
name|Element
name|c2
operator|=
block|{
name|QPainterPath
operator|::
name|CurveToDataElement
block|,
name|x2
block|,
name|y2
block|}
block|;
name|Element
name|e
operator|=
block|{
name|QPainterPath
operator|::
name|CurveToDataElement
block|,
name|ex
block|,
name|ey
block|}
block|;
name|m_elements
operator|.
name|add
argument_list|(
name|c1
argument_list|)
block|;
name|m_elements
operator|.
name|add
argument_list|(
name|c2
argument_list|)
block|;
name|m_elements
operator|.
name|add
argument_list|(
name|e
argument_list|)
block|; }
comment|/*******************************************************************************  * QStroker inline members  */
DECL|function|emitMoveTo
specifier|inline
name|void
name|QStroker
operator|::
name|emitMoveTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|{
name|m_back2X
operator|=
name|m_back1X
block|;
name|m_back2Y
operator|=
name|m_back1Y
block|;
name|m_back1X
operator|=
name|x
block|;
name|m_back1Y
operator|=
name|y
block|;
name|QStrokerOps
operator|::
name|emitMoveTo
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|emitLineTo
specifier|inline
name|void
name|QStroker
operator|::
name|emitLineTo
argument_list|(
argument|qfixed x
argument_list|,
argument|qfixed y
argument_list|)
block|{
name|m_back2X
operator|=
name|m_back1X
block|;
name|m_back2Y
operator|=
name|m_back1Y
block|;
name|m_back1X
operator|=
name|x
block|;
name|m_back1Y
operator|=
name|y
block|;
name|QStrokerOps
operator|::
name|emitLineTo
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
block|; }
DECL|function|emitCubicTo
specifier|inline
name|void
name|QStroker
operator|::
name|emitCubicTo
argument_list|(
argument|qfixed c1x
argument_list|,
argument|qfixed c1y
argument_list|,
argument|qfixed c2x
argument_list|,
argument|qfixed c2y
argument_list|,
argument|qfixed ex
argument_list|,
argument|qfixed ey
argument_list|)
block|{
if|if
condition|(
name|c2x
operator|==
name|ex
operator|&&
name|c2y
operator|==
name|ey
condition|)
block|{
if|if
condition|(
name|c1x
operator|==
name|ex
operator|&&
name|c1y
operator|==
name|ey
condition|)
block|{
name|m_back2X
operator|=
name|m_back1X
expr_stmt|;
name|m_back2Y
operator|=
name|m_back1Y
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|m_back2X
operator|=
name|c1x
expr_stmt|;
name|m_back2Y
operator|=
name|c1y
expr_stmt|;
block|}
end_else
begin_block
unit|} else
block|{
name|m_back2X
operator|=
name|c2x
expr_stmt|;
name|m_back2Y
operator|=
name|c2y
expr_stmt|;
block|}
end_block
begin_expr_stmt
name|m_back1X
operator|=
name|ex
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|m_back1Y
operator|=
name|ey
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QStrokerOps
operator|::
name|emitCubicTo
argument_list|(
name|c1x
argument_list|,
name|c1y
argument_list|,
name|c2x
argument_list|,
name|c2y
argument_list|,
name|ex
argument_list|,
name|ey
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
unit|}
comment|/*******************************************************************************  * QDashStroker inline members  */
end_comment
begin_expr_stmt
unit|inline
DECL|function|begin
name|void
name|QDashStroker
operator|::
name|begin
argument_list|(
argument|void *data
argument_list|)
block|{
if|if
condition|(
name|m_stroker
condition|)
name|m_stroker
operator|->
name|begin
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|QStrokerOps
operator|::
name|begin
argument_list|(
name|data
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}  inline
DECL|function|end
name|void
name|QDashStroker
operator|::
name|end
argument_list|()
block|{
name|QStrokerOps
operator|::
name|end
argument_list|()
block|;
if|if
condition|(
name|m_stroker
condition|)
name|m_stroker
operator|->
name|end
argument_list|()
expr_stmt|;
block|}
end_expr_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSTROKER_P_H
end_comment
end_unit
