begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QMATH_H
end_ifndef
begin_define
DECL|macro|QMATH_H
define|#
directive|define
name|QMATH_H
end_define
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<e32math.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Core
argument_list|)
DECL|macro|QT_SINE_TABLE_SIZE
define|#
directive|define
name|QT_SINE_TABLE_SIZE
value|256
decl|extern
name|Q_CORE_EXPORT
decl|const
name|qreal
name|qt_sine_table
index|[
name|QT_SINE_TABLE_SIZE
index|]
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|qCeil
specifier|inline
name|int
name|qCeil
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|int
argument_list|(
name|ceilf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|int
argument_list|(
name|ceil
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qFloor
specifier|inline
name|int
name|qFloor
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|int
argument_list|(
name|floorf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|int
argument_list|(
name|floor
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qFabs
specifier|inline
name|qreal
name|qFabs
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|fabsf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|fabs
argument_list|(
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qSin
specifier|inline
name|qreal
name|qSin
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|sin_v
decl_stmt|;
name|Math
operator|::
name|Sin
argument_list|(
name|sin_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|sin_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|sinf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|sin
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qCos
specifier|inline
name|qreal
name|qCos
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|cos_v
decl_stmt|;
name|Math
operator|::
name|Cos
argument_list|(
name|cos_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|cos_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|cosf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|cos
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qTan
specifier|inline
name|qreal
name|qTan
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|tan_v
decl_stmt|;
name|Math
operator|::
name|Tan
argument_list|(
name|tan_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|tan_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|tanf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|tan
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qAcos
specifier|inline
name|qreal
name|qAcos
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|acos_v
decl_stmt|;
name|Math
operator|::
name|ACos
argument_list|(
name|acos_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|acos_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|acosf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|acos
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qAsin
specifier|inline
name|qreal
name|qAsin
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|asin_v
decl_stmt|;
name|Math
operator|::
name|ASin
argument_list|(
name|asin_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|asin_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|asinf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|asin
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qAtan
specifier|inline
name|qreal
name|qAtan
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|atan_v
decl_stmt|;
name|Math
operator|::
name|ATan
argument_list|(
name|atan_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|atan_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|atanf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|atan
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qAtan2
specifier|inline
name|qreal
name|qAtan2
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|atan2_v
decl_stmt|;
name|Math
operator|::
name|ATan
argument_list|(
name|atan2_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|x
operator|)
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|y
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|atan2_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|atan2f
argument_list|(
name|float
argument_list|(
name|x
argument_list|)
argument_list|,
name|float
argument_list|(
name|y
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|atan2
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qSqrt
specifier|inline
name|qreal
name|qSqrt
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|sqrt_v
decl_stmt|;
name|Math
operator|::
name|Sqrt
argument_list|(
name|sqrt_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|sqrt_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|sqrtf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|sqrt
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qLn
specifier|inline
name|qreal
name|qLn
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|logf
argument_list|(
name|float
argument_list|(
name|v
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|log
argument_list|(
name|v
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qExp
specifier|inline
name|qreal
name|qExp
parameter_list|(
name|qreal
name|v
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|exp_v
decl_stmt|;
name|Math
operator|::
name|Exp
argument_list|(
name|exp_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|v
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|exp_v
operator|)
return|;
else|#
directive|else
comment|// only one signature
comment|// exists, exp(double)
return|return
name|exp
argument_list|(
name|v
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|qPow
specifier|inline
name|qreal
name|qPow
parameter_list|(
name|qreal
name|x
parameter_list|,
name|qreal
name|y
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
name|TReal
name|pow_v
decl_stmt|;
name|Math
operator|::
name|Pow
argument_list|(
name|pow_v
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|x
operator|)
argument_list|,
name|static_cast
operator|<
name|TReal
operator|>
operator|(
name|y
operator|)
argument_list|)
expr_stmt|;
return|return
name|static_cast
operator|<
name|qreal
operator|>
operator|(
name|pow_v
operator|)
return|;
else|#
directive|else
ifdef|#
directive|ifdef
name|QT_USE_MATH_H_FLOATS
if|if
condition|(
sizeof|sizeof
argument_list|(
name|qreal
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
condition|)
return|return
name|powf
argument_list|(
name|float
argument_list|(
name|x
argument_list|)
argument_list|,
name|float
argument_list|(
name|y
argument_list|)
argument_list|)
return|;
else|else
endif|#
directive|endif
return|return
name|pow
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|M_PI
end_ifndef
begin_define
DECL|macro|M_PI
define|#
directive|define
name|M_PI
value|(3.14159265358979323846)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|qFastSin
specifier|inline
name|qreal
name|qFastSin
parameter_list|(
name|qreal
name|x
parameter_list|)
block|{
name|int
name|si
init|=
name|int
argument_list|(
name|x
operator|*
operator|(
literal|0.5
operator|*
name|QT_SINE_TABLE_SIZE
operator|/
name|M_PI
operator|)
argument_list|)
decl_stmt|;
comment|// Would be more accurate with qRound, but slower.
name|qreal
name|d
init|=
name|x
operator|-
name|si
operator|*
operator|(
literal|2.0
operator|*
name|M_PI
operator|/
name|QT_SINE_TABLE_SIZE
operator|)
decl_stmt|;
name|int
name|ci
init|=
name|si
operator|+
name|QT_SINE_TABLE_SIZE
operator|/
literal|4
decl_stmt|;
name|si
operator|&=
name|QT_SINE_TABLE_SIZE
operator|-
literal|1
expr_stmt|;
name|ci
operator|&=
name|QT_SINE_TABLE_SIZE
operator|-
literal|1
expr_stmt|;
return|return
name|qt_sine_table
index|[
name|si
index|]
operator|+
operator|(
name|qt_sine_table
index|[
name|ci
index|]
operator|-
literal|0.5
operator|*
name|qt_sine_table
index|[
name|si
index|]
operator|*
name|d
operator|)
operator|*
name|d
return|;
block|}
end_function
begin_function
DECL|function|qFastCos
specifier|inline
name|qreal
name|qFastCos
parameter_list|(
name|qreal
name|x
parameter_list|)
block|{
name|int
name|ci
init|=
name|int
argument_list|(
name|x
operator|*
operator|(
literal|0.5
operator|*
name|QT_SINE_TABLE_SIZE
operator|/
name|M_PI
operator|)
argument_list|)
decl_stmt|;
comment|// Would be more accurate with qRound, but slower.
name|qreal
name|d
init|=
name|x
operator|-
name|ci
operator|*
operator|(
literal|2.0
operator|*
name|M_PI
operator|/
name|QT_SINE_TABLE_SIZE
operator|)
decl_stmt|;
name|int
name|si
init|=
name|ci
operator|+
name|QT_SINE_TABLE_SIZE
operator|/
literal|4
decl_stmt|;
name|si
operator|&=
name|QT_SINE_TABLE_SIZE
operator|-
literal|1
expr_stmt|;
name|ci
operator|&=
name|QT_SINE_TABLE_SIZE
operator|-
literal|1
expr_stmt|;
return|return
name|qt_sine_table
index|[
name|si
index|]
operator|-
operator|(
name|qt_sine_table
index|[
name|ci
index|]
operator|+
literal|0.5
operator|*
name|qt_sine_table
index|[
name|si
index|]
operator|*
name|d
operator|)
operator|*
name|d
return|;
block|}
end_function
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QMATH_H
end_comment
end_unit
