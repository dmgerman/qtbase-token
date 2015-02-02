begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QVECTOR2D_H
end_ifndef
begin_define
DECL|macro|QVECTOR2D_H
define|#
directive|define
name|QVECTOR2D_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qpoint.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qmetatype.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QVector3D
name|class
name|QVector3D
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVector4D
name|class
name|QVector4D
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QVariant
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_VECTOR2D
end_ifndef
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QVector2D
block|{
name|public
label|:
name|Q_DECL_CONSTEXPR
name|QVector2D
parameter_list|()
function_decl|;
name|explicit
name|QVector2D
argument_list|(
name|Qt
operator|::
name|Initialization
argument_list|)
block|{}
name|Q_DECL_CONSTEXPR
name|QVector2D
parameter_list|(
name|float
name|xpos
parameter_list|,
name|float
name|ypos
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
name|explicit
name|QVector2D
parameter_list|(
specifier|const
name|QPoint
modifier|&
name|point
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
name|explicit
name|QVector2D
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
name|explicit
name|QVector2D
parameter_list|(
specifier|const
name|QVector3D
modifier|&
name|vector
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
name|explicit
name|QVector2D
parameter_list|(
specifier|const
name|QVector4D
modifier|&
name|vector
parameter_list|)
function_decl|;
endif|#
directive|endif
name|bool
name|isNull
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|float
name|x
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|float
name|y
argument_list|()
specifier|const
expr_stmt|;
name|void
name|setX
parameter_list|(
name|float
name|x
parameter_list|)
function_decl|;
name|void
name|setY
parameter_list|(
name|float
name|y
parameter_list|)
function_decl|;
name|float
modifier|&
name|operator
function_decl|[]
parameter_list|(
name|int
name|i
parameter_list|)
function_decl|;
name|float
name|operator
index|[]
argument_list|(
name|int
name|i
argument_list|)
decl|const
decl_stmt|;
name|float
name|length
argument_list|()
specifier|const
expr_stmt|;
name|float
name|lengthSquared
argument_list|()
specifier|const
expr_stmt|;
comment|//In Qt 6 convert to inline and constexpr
name|QVector2D
name|normalized
argument_list|()
specifier|const
expr_stmt|;
name|void
name|normalize
parameter_list|()
function_decl|;
name|float
name|distanceToPoint
argument_list|(
specifier|const
name|QVector2D
operator|&
name|point
argument_list|)
decl|const
decl_stmt|;
name|float
name|distanceToLine
argument_list|(
specifier|const
name|QVector2D
operator|&
name|point
argument_list|,
specifier|const
name|QVector2D
operator|&
name|direction
argument_list|)
decl|const
decl_stmt|;
name|QVector2D
operator|&
name|operator
operator|+=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
expr_stmt|;
name|QVector2D
operator|&
name|operator
operator|-=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
expr_stmt|;
name|QVector2D
operator|&
name|operator
operator|*=
operator|(
name|float
name|factor
operator|)
expr_stmt|;
name|QVector2D
operator|&
name|operator
operator|*=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
expr_stmt|;
name|QVector2D
operator|&
name|operator
operator|/=
operator|(
name|float
name|divisor
operator|)
expr_stmt|;
specifier|inline
name|QVector2D
operator|&
name|operator
operator|/=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
expr_stmt|;
specifier|static
name|float
name|dotProduct
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|v2
parameter_list|)
function_decl|;
comment|//In Qt 6 convert to inline and constexpr
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|+
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|-
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
modifier|*
parameter_list|(
name|float
name|factor
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
modifier|*
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|,
name|float
name|factor
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
modifier|*
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|v2
parameter_list|)
function_decl|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|-
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|/
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|,
name|float
name|divisor
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|/
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|,
specifier|const
name|QVector2D
operator|&
name|divisor
operator|)
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|friend
specifier|inline
name|bool
name|qFuzzyCompare
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|v2
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_VECTOR3D
name|QVector3D
name|toVector3D
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|QT_NO_VECTOR4D
name|QVector4D
name|toVector4D
argument_list|()
specifier|const
expr_stmt|;
endif|#
directive|endif
name|Q_DECL_CONSTEXPR
name|QPoint
name|toPoint
argument_list|()
specifier|const
expr_stmt|;
name|Q_DECL_CONSTEXPR
name|QPointF
name|toPointF
argument_list|()
specifier|const
expr_stmt|;
name|operator
name|QVariant
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|float
name|xp
decl_stmt|,
name|yp
decl_stmt|;
name|friend
name|class
name|QVector3D
decl_stmt|;
name|friend
name|class
name|QVector4D
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|Q_DECLARE_TYPEINFO
argument_list|(
name|QVector2D
argument_list|,
name|Q_MOVABLE_TYPE
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
DECL|function|QVector2D
name|Q_DECL_CONSTEXPR
specifier|inline
name|QVector2D
operator|::
name|QVector2D
argument_list|()
operator|:
name|xp
argument_list|(
literal|0.0f
argument_list|)
operator|,
name|yp
argument_list|(
literal|0.0f
argument_list|)
block|{}
DECL|function|QVector2D
name|Q_DECL_CONSTEXPR
specifier|inline
name|QVector2D
operator|::
name|QVector2D
argument_list|(
argument|float xpos
argument_list|,
argument|float ypos
argument_list|)
operator|:
name|xp
argument_list|(
name|xpos
argument_list|)
operator|,
name|yp
argument_list|(
argument|ypos
argument_list|)
block|{}
DECL|function|QVector2D
name|Q_DECL_CONSTEXPR
specifier|inline
name|QVector2D
operator|::
name|QVector2D
argument_list|(
specifier|const
name|QPoint
operator|&
name|point
argument_list|)
operator|:
name|xp
argument_list|(
name|point
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|yp
argument_list|(
argument|point.y()
argument_list|)
block|{}
DECL|function|QVector2D
name|Q_DECL_CONSTEXPR
specifier|inline
name|QVector2D
operator|::
name|QVector2D
argument_list|(
specifier|const
name|QPointF
operator|&
name|point
argument_list|)
operator|:
name|xp
argument_list|(
name|point
operator|.
name|x
argument_list|()
argument_list|)
operator|,
name|yp
argument_list|(
argument|point.y()
argument_list|)
block|{}
DECL|function|isNull
specifier|inline
name|bool
name|QVector2D
operator|::
name|isNull
argument_list|()
specifier|const
block|{
return|return
name|qIsNull
argument_list|(
name|xp
argument_list|)
operator|&&
name|qIsNull
argument_list|(
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|x
name|Q_DECL_CONSTEXPR
specifier|inline
name|float
name|QVector2D
operator|::
name|x
argument_list|()
specifier|const
block|{
return|return
name|xp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|y
name|Q_DECL_CONSTEXPR
specifier|inline
name|float
name|QVector2D
operator|::
name|y
argument_list|()
specifier|const
block|{
return|return
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|setX
specifier|inline
name|void
name|QVector2D
operator|::
name|setX
argument_list|(
argument|float aX
argument_list|)
block|{
name|xp
operator|=
name|aX
block|; }
DECL|function|setY
specifier|inline
name|void
name|QVector2D
operator|::
name|setY
argument_list|(
argument|float aY
argument_list|)
block|{
name|yp
operator|=
name|aY
block|; }
DECL|function|operator
specifier|inline
name|float
operator|&
name|QVector2D
operator|::
name|operator
index|[]
operator|(
name|int
name|i
operator|)
block|{
name|Q_ASSERT
argument_list|(
name|uint
argument_list|(
name|i
argument_list|)
operator|<
literal|2u
argument_list|)
block|;
return|return
operator|*
operator|(
operator|&
name|xp
operator|+
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|function|operator
specifier|inline
name|float
name|QVector2D
operator|::
name|operator
index|[]
operator|(
name|int
name|i
operator|)
specifier|const
block|{
name|Q_ASSERT
argument_list|(
name|uint
argument_list|(
name|i
argument_list|)
operator|<
literal|2u
argument_list|)
block|;
return|return
operator|*
operator|(
operator|&
name|xp
operator|+
name|i
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
DECL|member|operator
specifier|inline
name|QVector2D
operator|&
name|QVector2D
operator|::
name|operator
operator|+=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
block|{
name|xp
operator|+=
name|vector
operator|.
name|xp
block|;
name|yp
operator|+=
name|vector
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QVector2D
operator|&
name|QVector2D
operator|::
name|operator
operator|-=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
block|{
name|xp
operator|-=
name|vector
operator|.
name|xp
block|;
name|yp
operator|-=
name|vector
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QVector2D
operator|&
name|QVector2D
operator|::
name|operator
operator|*=
operator|(
name|float
name|factor
operator|)
block|{
name|xp
operator|*=
name|factor
block|;
name|yp
operator|*=
name|factor
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QVector2D
operator|&
name|QVector2D
operator|::
name|operator
operator|*=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
block|{
name|xp
operator|*=
name|vector
operator|.
name|xp
block|;
name|yp
operator|*=
name|vector
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QVector2D
operator|&
name|QVector2D
operator|::
name|operator
operator|/=
operator|(
name|float
name|divisor
operator|)
block|{
name|xp
operator|/=
name|divisor
block|;
name|yp
operator|/=
name|divisor
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|QVector2D
operator|&
name|QVector2D
operator|::
name|operator
operator|/=
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
block|{
name|xp
operator|/=
name|vector
operator|.
name|xp
block|;
name|yp
operator|/=
name|vector
operator|.
name|yp
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|==
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
block|{
return|return
name|v1
operator|.
name|xp
operator|==
name|v2
operator|.
name|xp
operator|&&
name|v1
operator|.
name|yp
operator|==
name|v2
operator|.
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
block|{
return|return
name|v1
operator|.
name|xp
operator|!=
name|v2
operator|.
name|xp
operator|||
name|v1
operator|.
name|yp
operator|!=
name|v2
operator|.
name|yp
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|+
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
block|{
return|return
name|QVector2D
argument_list|(
name|v1
operator|.
name|xp
operator|+
name|v2
operator|.
name|xp
argument_list|,
name|v1
operator|.
name|yp
operator|+
name|v2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|-
operator|(
specifier|const
name|QVector2D
operator|&
name|v1
operator|,
specifier|const
name|QVector2D
operator|&
name|v2
operator|)
block|{
return|return
name|QVector2D
argument_list|(
name|v1
operator|.
name|xp
operator|-
name|v2
operator|.
name|xp
argument_list|,
name|v1
operator|.
name|yp
operator|-
name|v2
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
modifier|*
parameter_list|(
name|float
name|factor
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|)
block|{
return|return
name|QVector2D
argument_list|(
name|vector
operator|.
name|xp
operator|*
name|factor
argument_list|,
name|vector
operator|.
name|yp
operator|*
name|factor
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
modifier|*
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|vector
parameter_list|,
name|float
name|factor
parameter_list|)
block|{
return|return
name|QVector2D
argument_list|(
name|vector
operator|.
name|xp
operator|*
name|factor
argument_list|,
name|vector
operator|.
name|yp
operator|*
name|factor
argument_list|)
return|;
block|}
end_function
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
modifier|*
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|QVector2D
argument_list|(
name|v1
operator|.
name|xp
operator|*
name|v2
operator|.
name|xp
argument_list|,
name|v1
operator|.
name|yp
operator|*
name|v2
operator|.
name|yp
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|-
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|)
block|{
return|return
name|QVector2D
argument_list|(
operator|-
name|vector
operator|.
name|xp
argument_list|,
operator|-
name|vector
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|/
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|,
name|float
name|divisor
operator|)
block|{
return|return
name|QVector2D
argument_list|(
name|vector
operator|.
name|xp
operator|/
name|divisor
argument_list|,
name|vector
operator|.
name|yp
operator|/
name|divisor
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
specifier|const
name|QVector2D
name|operator
operator|/
operator|(
specifier|const
name|QVector2D
operator|&
name|vector
operator|,
specifier|const
name|QVector2D
operator|&
name|divisor
operator|)
block|{
return|return
name|QVector2D
argument_list|(
name|vector
operator|.
name|xp
operator|/
name|divisor
operator|.
name|xp
argument_list|,
name|vector
operator|.
name|yp
operator|/
name|divisor
operator|.
name|yp
argument_list|)
return|;
block|}
end_expr_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|inline
name|bool
name|qFuzzyCompare
parameter_list|(
specifier|const
name|QVector2D
modifier|&
name|v1
parameter_list|,
specifier|const
name|QVector2D
modifier|&
name|v2
parameter_list|)
block|{
return|return
name|qFuzzyCompare
argument_list|(
name|v1
operator|.
name|xp
argument_list|,
name|v2
operator|.
name|xp
argument_list|)
operator|&&
name|qFuzzyCompare
argument_list|(
name|v1
operator|.
name|yp
argument_list|,
name|v2
operator|.
name|yp
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPoint
name|QVector2D
operator|::
name|toPoint
argument_list|()
specifier|const
block|{
return|return
name|QPoint
argument_list|(
name|qRound
argument_list|(
name|xp
argument_list|)
argument_list|,
name|qRound
argument_list|(
name|yp
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|Q_DECL_CONSTEXPR
specifier|inline
name|QPointF
name|QVector2D
operator|::
name|toPointF
argument_list|()
specifier|const
block|{
return|return
name|QPointF
argument_list|(
name|qreal
argument_list|(
name|xp
argument_list|)
argument_list|,
name|qreal
argument_list|(
name|yp
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt
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
name|dbg
operator|,
specifier|const
name|QVector2D
operator|&
name|vector
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
name|QVector2D
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
name|QVector2D
operator|&
operator|)
expr_stmt|;
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
