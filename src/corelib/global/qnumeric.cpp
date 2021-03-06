begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qnumeric.h"
end_include
begin_include
include|#
directive|include
file|"qnumeric_p.h"
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*!     Returns \c true if the double \a {d} is equivalent to infinity.     \relates<QtGlobal> */
DECL|function|qIsInf
name|Q_CORE_EXPORT
name|bool
name|qIsInf
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|qt_is_inf
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the double \a {d} is not a number (NaN).     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qIsNaN
name|Q_CORE_EXPORT
name|bool
name|qIsNaN
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|qt_is_nan
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the double \a {d} is a finite number.     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qIsFinite
name|Q_CORE_EXPORT
name|bool
name|qIsFinite
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|qt_is_finite
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the float \a {f} is equivalent to infinity.     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qIsInf
name|Q_CORE_EXPORT
name|bool
name|qIsInf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|qt_is_inf
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the float \a {f} is not a number (NaN).     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qIsNaN
name|Q_CORE_EXPORT
name|bool
name|qIsNaN
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|qt_is_nan
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns \c true if the float \a {f} is a finite number.     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qIsFinite
name|Q_CORE_EXPORT
name|bool
name|qIsFinite
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|qt_is_finite
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the bit pattern of a signalling NaN as a double.     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qSNaN
name|Q_CORE_EXPORT
name|double
name|qSNaN
parameter_list|()
block|{
return|return
name|qt_snan
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the bit pattern of a quiet NaN as a double.     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qQNaN
name|Q_CORE_EXPORT
name|double
name|qQNaN
parameter_list|()
block|{
return|return
name|qt_qnan
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the bit pattern for an infinite number as a double.     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qInf
name|Q_CORE_EXPORT
name|double
name|qInf
parameter_list|()
block|{
return|return
name|qt_inf
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!    \internal  */
end_comment
begin_function
DECL|function|f2i
specifier|static
specifier|inline
name|quint32
name|f2i
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|quint32
name|i
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|i
argument_list|,
operator|&
name|f
argument_list|,
sizeof|sizeof
argument_list|(
name|f
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of representable floating-point numbers between \a a and \a b.      This function provides an alternative way of doing approximated comparisons of floating-point     numbers similar to qFuzzyCompare(). However, it returns the distance between two numbers, which     gives the caller a possibility to choose the accepted error. Errors are relative, so for     instance the distance between 1.0E-5 and 1.00001E-5 will give 110, while the distance between     1.0E36 and 1.00001E36 will give 127.      This function is useful if a floating point comparison requires a certain precision.     Therefore, if \a a and \a b are equal it will return 0. The maximum value it will return for 32-bit     floating point numbers is 4,278,190,078. This is the distance between \c{-FLT_MAX} and     \c{+FLT_MAX}.      The function does not give meaningful results if any of the arguments are \c Infinite or \c NaN.     You can check for this by calling qIsFinite().      The return value can be considered as the "error", so if you for instance want to compare     two 32-bit floating point numbers and all you need is an approximated 24-bit precision, you can     use this function like this:      \code     if (qFloatDistance(a, b)< (1<< 7)) {   // The last 7 bits are not                                             // significant         // precise enough     }     \endcode      \sa qFuzzyCompare()     \since 5.2     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qFloatDistance
name|Q_CORE_EXPORT
name|quint32
name|qFloatDistance
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
specifier|static
specifier|const
name|quint32
name|smallestPositiveFloatAsBits
init|=
literal|0x00000001
decl_stmt|;
comment|// denormalized, (SMALLEST), (1.4E-45)
comment|/* Assumes:        * IEE754 format.        * Integers and floats have the same endian     */
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|qIsFinite
argument_list|(
name|a
argument_list|)
operator|&&
name|qIsFinite
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|b
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|(
name|a
operator|<
literal|0
operator|)
operator|!=
operator|(
name|b
operator|<
literal|0
operator|)
condition|)
block|{
comment|// if they have different signs
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|a
operator|=
operator|-
name|a
expr_stmt|;
else|else
comment|/*if (b< 0)*/
name|b
operator|=
operator|-
name|b
expr_stmt|;
return|return
name|qFloatDistance
argument_list|(
literal|0.0F
argument_list|,
name|a
argument_list|)
operator|+
name|qFloatDistance
argument_list|(
literal|0.0F
argument_list|,
name|b
argument_list|)
return|;
block|}
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|a
operator|=
operator|-
name|a
expr_stmt|;
name|b
operator|=
operator|-
name|b
expr_stmt|;
block|}
comment|// at this point a and b should not be negative
comment|// 0 is special
if|if
condition|(
operator|!
name|a
condition|)
return|return
name|f2i
argument_list|(
name|b
argument_list|)
operator|-
name|smallestPositiveFloatAsBits
operator|+
literal|1
return|;
if|if
condition|(
operator|!
name|b
condition|)
return|return
name|f2i
argument_list|(
name|a
argument_list|)
operator|-
name|smallestPositiveFloatAsBits
operator|+
literal|1
return|;
comment|// finally do the common integer subtraction
return|return
name|a
operator|>
name|b
condition|?
name|f2i
argument_list|(
name|a
argument_list|)
operator|-
name|f2i
argument_list|(
name|b
argument_list|)
else|:
name|f2i
argument_list|(
name|b
argument_list|)
operator|-
name|f2i
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!    \internal  */
end_comment
begin_function
DECL|function|d2i
specifier|static
specifier|inline
name|quint64
name|d2i
parameter_list|(
name|double
name|d
parameter_list|)
block|{
name|quint64
name|i
decl_stmt|;
name|memcpy
argument_list|(
operator|&
name|i
argument_list|,
operator|&
name|d
argument_list|,
sizeof|sizeof
argument_list|(
name|d
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|i
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the number of representable floating-point numbers between \a a and \a b.      This function serves the same purpose as \c{qFloatDistance(float, float)}, but     returns the distance between two \c double numbers. Since the range is larger     than for two \c float numbers (\c{[-DBL_MAX,DBL_MAX]}), the return type is quint64.       \sa qFuzzyCompare()     \since 5.2     \relates<QtGlobal> */
end_comment
begin_function
DECL|function|qFloatDistance
name|Q_CORE_EXPORT
name|quint64
name|qFloatDistance
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|)
block|{
specifier|static
specifier|const
name|quint64
name|smallestPositiveFloatAsBits
init|=
literal|0x1
decl_stmt|;
comment|// denormalized, (SMALLEST)
comment|/* Assumes:        * IEE754 format double precision        * Integers and floats have the same endian     */
name|Q_STATIC_ASSERT
argument_list|(
sizeof|sizeof
argument_list|(
name|quint64
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|double
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|qIsFinite
argument_list|(
name|a
argument_list|)
operator|&&
name|qIsFinite
argument_list|(
name|b
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|a
operator|==
name|b
condition|)
return|return
literal|0
return|;
if|if
condition|(
operator|(
name|a
operator|<
literal|0
operator|)
operator|!=
operator|(
name|b
operator|<
literal|0
operator|)
condition|)
block|{
comment|// if they have different signs
if|if
condition|(
name|a
operator|<
literal|0
condition|)
name|a
operator|=
operator|-
name|a
expr_stmt|;
else|else
comment|/*if (b< 0)*/
name|b
operator|=
operator|-
name|b
expr_stmt|;
return|return
name|qFloatDistance
argument_list|(
literal|0.0
argument_list|,
name|a
argument_list|)
operator|+
name|qFloatDistance
argument_list|(
literal|0.0
argument_list|,
name|b
argument_list|)
return|;
block|}
if|if
condition|(
name|a
operator|<
literal|0
condition|)
block|{
name|a
operator|=
operator|-
name|a
expr_stmt|;
name|b
operator|=
operator|-
name|b
expr_stmt|;
block|}
comment|// at this point a and b should not be negative
comment|// 0 is special
if|if
condition|(
operator|!
name|a
condition|)
return|return
name|d2i
argument_list|(
name|b
argument_list|)
operator|-
name|smallestPositiveFloatAsBits
operator|+
literal|1
return|;
if|if
condition|(
operator|!
name|b
condition|)
return|return
name|d2i
argument_list|(
name|a
argument_list|)
operator|-
name|smallestPositiveFloatAsBits
operator|+
literal|1
return|;
comment|// finally do the common integer subtraction
return|return
name|a
operator|>
name|b
condition|?
name|d2i
argument_list|(
name|a
argument_list|)
operator|-
name|d2i
argument_list|(
name|b
argument_list|)
else|:
name|d2i
argument_list|(
name|b
argument_list|)
operator|-
name|d2i
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
