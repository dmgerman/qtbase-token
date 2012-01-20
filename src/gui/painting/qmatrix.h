begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMATRIX_H
end_ifndef
begin_define
DECL|macro|QMATRIX_H
define|#
directive|define
name|QMATRIX_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpolygon.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qregion.h>
end_include
begin_include
include|#
directive|include
file|<QtGui/qwindowdefs.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qline.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qrect.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Gui
parameter_list|)
name|class
name|QPainterPath
decl_stmt|;
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
name|class
name|Q_GUI_EXPORT
name|QMatrix
comment|// 2D transform matrix
decl_stmt|{ public:
specifier|inline
namespace|explicit
name|QMatrix
namespace|(
name|Qt
namespace|::
name|Initialization
end_function
begin_block
unit|)
block|{}
end_block
begin_expr_stmt
name|QMatrix
argument_list|()
expr_stmt|;
end_expr_stmt
begin_macro
name|QMatrix
argument_list|(
argument|qreal m11
argument_list|,
argument|qreal m12
argument_list|,
argument|qreal m21
argument_list|,
argument|qreal m22
argument_list|,
argument|qreal dx
argument_list|,
argument|qreal dy
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|QMatrix
argument_list|(
specifier|const
name|QMatrix
operator|&
name|matrix
argument_list|)
expr_stmt|;
end_expr_stmt
begin_function_decl
name|void
name|setMatrix
parameter_list|(
name|qreal
name|m11
parameter_list|,
name|qreal
name|m12
parameter_list|,
name|qreal
name|m21
parameter_list|,
name|qreal
name|m22
parameter_list|,
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|qreal
name|m11
argument_list|()
specifier|const
block|{
return|return
name|_m11
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|qreal
name|m12
argument_list|()
specifier|const
block|{
return|return
name|_m12
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|qreal
name|m21
argument_list|()
specifier|const
block|{
return|return
name|_m21
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|qreal
name|m22
argument_list|()
specifier|const
block|{
return|return
name|_m22
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|qreal
name|dx
argument_list|()
specifier|const
block|{
return|return
name|_dx
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|qreal
name|dy
argument_list|()
specifier|const
block|{
return|return
name|_dy
return|;
block|}
end_expr_stmt
begin_decl_stmt
name|void
name|map
argument_list|(
name|int
name|x
argument_list|,
name|int
name|y
argument_list|,
name|int
operator|*
name|tx
argument_list|,
name|int
operator|*
name|ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|void
name|map
argument_list|(
name|qreal
name|x
argument_list|,
name|qreal
name|y
argument_list|,
name|qreal
operator|*
name|tx
argument_list|,
name|qreal
operator|*
name|ty
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRect
name|mapRect
argument_list|(
specifier|const
name|QRect
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRectF
name|mapRect
argument_list|(
specifier|const
name|QRectF
operator|&
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPoint
name|map
argument_list|(
specifier|const
name|QPoint
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPointF
name|map
argument_list|(
specifier|const
name|QPointF
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLine
name|map
argument_list|(
specifier|const
name|QLine
operator|&
name|l
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QLineF
name|map
argument_list|(
specifier|const
name|QLineF
operator|&
name|l
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPolygonF
name|map
argument_list|(
specifier|const
name|QPolygonF
operator|&
name|a
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPolygon
name|map
argument_list|(
specifier|const
name|QPolygon
operator|&
name|a
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QRegion
name|map
argument_list|(
specifier|const
name|QRegion
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPainterPath
name|map
argument_list|(
specifier|const
name|QPainterPath
operator|&
name|p
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QPolygon
name|mapToPolygon
argument_list|(
specifier|const
name|QRect
operator|&
name|r
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_function_decl
name|void
name|reset
parameter_list|()
function_decl|;
end_function_decl
begin_expr_stmt
specifier|inline
name|bool
name|isIdentity
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_function_decl
name|QMatrix
modifier|&
name|translate
parameter_list|(
name|qreal
name|dx
parameter_list|,
name|qreal
name|dy
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QMatrix
modifier|&
name|scale
parameter_list|(
name|qreal
name|sx
parameter_list|,
name|qreal
name|sy
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QMatrix
modifier|&
name|shear
parameter_list|(
name|qreal
name|sh
parameter_list|,
name|qreal
name|sv
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|QMatrix
modifier|&
name|rotate
parameter_list|(
name|qreal
name|a
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
name|bool
name|isInvertible
argument_list|()
specifier|const
block|{
return|return
operator|!
name|qFuzzyIsNull
argument_list|(
name|_m11
operator|*
name|_m22
operator|-
name|_m12
operator|*
name|_m21
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|qreal
name|determinant
argument_list|()
specifier|const
block|{
return|return
name|_m11
operator|*
name|_m22
operator|-
name|_m12
operator|*
name|_m21
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QT_DEPRECATED
end_ifdef
begin_expr_stmt
name|QT_DEPRECATED
name|qreal
name|det
argument_list|()
specifier|const
block|{
return|return
name|_m11
operator|*
name|_m22
operator|-
name|_m12
operator|*
name|_m21
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QMatrix
name|inverted
argument_list|(
name|bool
operator|*
name|invertible
operator|=
literal|0
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QMatrix
operator|&
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QMatrix
operator|&
operator|)
specifier|const
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|QMatrix
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|QMatrix
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|QMatrix
name|operator
modifier|*
argument_list|(
specifier|const
name|QMatrix
operator|&
name|o
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|QMatrix
modifier|&
name|operator
init|=
operator|(
specifier|const
name|QMatrix
operator|&
operator|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt
begin_label
name|private
label|:
end_label
begin_expr_stmt
specifier|inline
name|QMatrix
argument_list|(
name|bool
argument_list|)
operator|:
name|_m11
argument_list|(
literal|1.
argument_list|)
operator|,
name|_m12
argument_list|(
literal|0.
argument_list|)
operator|,
name|_m21
argument_list|(
literal|0.
argument_list|)
operator|,
name|_m22
argument_list|(
literal|1.
argument_list|)
operator|,
name|_dx
argument_list|(
literal|0.
argument_list|)
operator|,
name|_dy
argument_list|(
literal|0.
argument_list|)
block|{}
specifier|inline
name|QMatrix
argument_list|(
argument|qreal am11
argument_list|,
argument|qreal am12
argument_list|,
argument|qreal am21
argument_list|,
argument|qreal am22
argument_list|,
argument|qreal adx
argument_list|,
argument|qreal ady
argument_list|,
argument|bool
argument_list|)
operator|:
name|_m11
argument_list|(
name|am11
argument_list|)
operator|,
name|_m12
argument_list|(
name|am12
argument_list|)
operator|,
name|_m21
argument_list|(
name|am21
argument_list|)
operator|,
name|_m22
argument_list|(
name|am22
argument_list|)
operator|,
name|_dx
argument_list|(
name|adx
argument_list|)
operator|,
name|_dy
argument_list|(
argument|ady
argument_list|)
block|{}
name|friend
name|class
name|QTransform
expr_stmt|;
end_expr_stmt
begin_decl_stmt
name|qreal
name|_m11
decl_stmt|,
name|_m12
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|_m21
decl_stmt|,
name|_m22
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|qreal
name|_dx
decl_stmt|,
name|_dy
decl_stmt|;
end_decl_stmt
begin_expr_stmt
unit|};
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QMatrix
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// mathematical semantics
end_comment
begin_function
name|Q_GUI_EXPORT_INLINE
name|QPoint
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|p
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_GUI_EXPORT_INLINE
name|QPointF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|p
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_GUI_EXPORT_INLINE
name|QLineF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QLineF
modifier|&
name|l
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|l
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_GUI_EXPORT_INLINE
name|QLine
name|operator
modifier|*
parameter_list|(
specifier|const
name|QLine
modifier|&
name|l
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|l
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_GUI_EXPORT_INLINE
name|QPolygon
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPolygon
modifier|&
name|a
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_GUI_EXPORT_INLINE
name|QPolygonF
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPolygonF
modifier|&
name|a
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_GUI_EXPORT_INLINE
name|QRegion
name|operator
modifier|*
parameter_list|(
specifier|const
name|QRegion
modifier|&
name|r
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
block|{
return|return
name|m
operator|.
name|map
argument_list|(
name|r
argument_list|)
return|;
block|}
end_function
begin_function_decl
name|Q_GUI_EXPORT
name|QPainterPath
name|operator
modifier|*
parameter_list|(
specifier|const
name|QPainterPath
modifier|&
name|p
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m
parameter_list|)
function_decl|;
end_function_decl
begin_expr_stmt
DECL|function|isIdentity
specifier|inline
name|bool
name|QMatrix
operator|::
name|isIdentity
argument_list|()
specifier|const
block|{
return|return
name|qFuzzyIsNull
argument_list|(
name|_m11
operator|-
literal|1
argument_list|)
operator|&&
name|qFuzzyIsNull
argument_list|(
name|_m22
operator|-
literal|1
argument_list|)
operator|&&
name|qFuzzyIsNull
argument_list|(
name|_m12
argument_list|)
operator|&&
name|qFuzzyIsNull
argument_list|(
name|_m21
argument_list|)
operator|&&
name|qFuzzyIsNull
argument_list|(
name|_dx
argument_list|)
operator|&&
name|qFuzzyIsNull
argument_list|(
name|_dy
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
DECL|function|qFuzzyCompare
specifier|inline
name|bool
name|qFuzzyCompare
parameter_list|(
specifier|const
name|QMatrix
modifier|&
name|m1
parameter_list|,
specifier|const
name|QMatrix
modifier|&
name|m2
parameter_list|)
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|m1
operator|.
name|m11
argument_list|()
argument_list|,
name|m2
operator|.
name|m11
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|m1
operator|.
name|m12
argument_list|()
argument_list|,
name|m2
operator|.
name|m12
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|m1
operator|.
name|m21
argument_list|()
argument_list|,
name|m2
operator|.
name|m21
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|m1
operator|.
name|m22
argument_list|()
argument_list|,
name|m2
operator|.
name|m22
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|m1
operator|.
name|dx
argument_list|()
argument_list|,
name|m2
operator|.
name|dx
argument_list|()
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|m1
operator|.
name|dy
argument_list|()
argument_list|,
name|m2
operator|.
name|dy
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*****************************************************************************  QMatrix stream functions  *****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DATASTREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|<<
operator|(
name|QDataStream
operator|&
operator|,
specifier|const
name|QMatrix
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDataStream
operator|&
name|operator
operator|>>
operator|(
name|QDataStream
operator|&
operator|,
name|QMatrix
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_DEBUG_STREAM
end_ifndef
begin_expr_stmt
name|Q_GUI_EXPORT
name|QDebug
name|operator
operator|<<
operator|(
name|QDebug
operator|,
specifier|const
name|QMatrix
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMATRIX_H
end_comment
end_unit
