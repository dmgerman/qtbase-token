begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QNUMERIC_P_H
end_ifndef
begin_define
DECL|macro|QNUMERIC_P_H
define|#
directive|define
name|QNUMERIC_P_H
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
file|"QtCore/qglobal.h"
end_include
begin_include
include|#
directive|include
file|<cmath>
end_include
begin_include
include|#
directive|include
file|<limits>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<intrin.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<immintrin.h>
end_include
begin_comment
comment|// for _addcarry_u<nn>
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
end_if
begin_include
include|#
directive|include
file|<float.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|__cplusplus
operator|<
literal|201103L
operator|)
end_if
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|qnumeric_std_wrapper
block|{
comment|// the 'using namespace std' below is cases where the stdlib already put the math.h functions in the std namespace and undefined the macros.
specifier|static
specifier|inline
name|bool
name|math_h_isnan
parameter_list|(
name|double
name|d
parameter_list|)
block|{
name|using
name|namespace
name|std
decl_stmt|;
return|return
name|isnan
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|math_h_isinf
parameter_list|(
name|double
name|d
parameter_list|)
block|{
name|using
name|namespace
name|std
decl_stmt|;
return|return
name|isinf
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|math_h_isfinite
parameter_list|(
name|double
name|d
parameter_list|)
block|{
name|using
name|namespace
name|std
decl_stmt|;
return|return
name|isfinite
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|math_h_isnan
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|using
name|namespace
name|std
decl_stmt|;
return|return
name|isnan
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|math_h_isinf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|using
name|namespace
name|std
decl_stmt|;
return|return
name|isinf
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|math_h_isfinite
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|using
name|namespace
name|std
decl_stmt|;
return|return
name|isfinite
argument_list|(
name|f
argument_list|)
return|;
block|}
block|}
end_decl_stmt
begin_decl_stmt
name|QT_END_NAMESPACE
comment|// These macros from math.h conflict with the real functions in the std namespace.
DECL|macro|signbit
undef|#
directive|undef
name|signbit
DECL|macro|isnan
undef|#
directive|undef
name|isnan
DECL|macro|isinf
undef|#
directive|undef
name|isinf
DECL|macro|isfinite
undef|#
directive|undef
name|isfinite
endif|#
directive|endif
name|QT_BEGIN_NAMESPACE
name|namespace
name|qnumeric_std_wrapper
block|{
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|_MSC_VER
operator|<
literal|1800
specifier|static
specifier|inline
name|bool
name|isnan
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
operator|!
operator|!
name|_isnan
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isinf
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
operator|!
name|_finite
argument_list|(
name|d
argument_list|)
operator|&&
operator|!
name|_isnan
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isfinite
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
operator|!
operator|!
name|_finite
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isnan
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
operator|!
operator|!
name|_isnan
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isinf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
operator|!
name|_finite
argument_list|(
name|f
argument_list|)
operator|&&
operator|!
name|_isnan
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isfinite
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
operator|!
operator|!
name|_finite
argument_list|(
name|f
argument_list|)
return|;
block|}
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_OS_QNX
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|__cplusplus
operator|<
literal|201103L
operator|)
specifier|static
specifier|inline
name|bool
name|isnan
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|math_h_isnan
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isinf
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|math_h_isinf
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isfinite
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|math_h_isfinite
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isnan
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|math_h_isnan
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isinf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|math_h_isinf
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isfinite
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|math_h_isfinite
argument_list|(
name|f
argument_list|)
return|;
block|}
else|#
directive|else
specifier|static
specifier|inline
name|bool
name|isnan
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|std
operator|::
name|isnan
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isinf
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|std
operator|::
name|isinf
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isfinite
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|std
operator|::
name|isfinite
argument_list|(
name|d
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isnan
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|std
operator|::
name|isnan
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isinf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|std
operator|::
name|isinf
argument_list|(
name|f
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isfinite
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|std
operator|::
name|isfinite
argument_list|(
name|f
argument_list|)
return|;
block|}
endif|#
directive|endif
block|}
end_decl_stmt
begin_function
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|double
name|qt_inf
parameter_list|()
function|Q_DECL_NOEXCEPT
block|{
name|Q_STATIC_ASSERT_X
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|has_infinity
argument_list|,
literal|"platform has no definition for infinity for type double"
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|infinity
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Signaling NaN
end_comment
begin_function
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|double
name|qt_snan
parameter_list|()
function|Q_DECL_NOEXCEPT
block|{
name|Q_STATIC_ASSERT_X
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|has_signaling_NaN
argument_list|,
literal|"platform has no definition for signaling NaN for type double"
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|signaling_NaN
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// Quiet NaN
end_comment
begin_function
name|Q_DECL_CONSTEXPR
specifier|static
specifier|inline
name|double
name|qt_qnan
parameter_list|()
function|Q_DECL_NOEXCEPT
block|{
name|Q_STATIC_ASSERT_X
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|has_quiet_NaN
argument_list|,
literal|"platform has no definition for quiet NaN for type double"
argument_list|)
expr_stmt|;
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|double
operator|>
operator|::
name|quiet_NaN
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qt_is_inf
specifier|static
specifier|inline
name|bool
name|qt_is_inf
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|qnumeric_std_wrapper
operator|::
name|isinf
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_is_nan
specifier|static
specifier|inline
name|bool
name|qt_is_nan
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|qnumeric_std_wrapper
operator|::
name|isnan
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_is_finite
specifier|static
specifier|inline
name|bool
name|qt_is_finite
parameter_list|(
name|double
name|d
parameter_list|)
block|{
return|return
name|qnumeric_std_wrapper
operator|::
name|isfinite
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_is_inf
specifier|static
specifier|inline
name|bool
name|qt_is_inf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|qnumeric_std_wrapper
operator|::
name|isinf
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_is_nan
specifier|static
specifier|inline
name|bool
name|qt_is_nan
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|qnumeric_std_wrapper
operator|::
name|isnan
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|qt_is_finite
specifier|static
specifier|inline
name|bool
name|qt_is_finite
parameter_list|(
name|float
name|f
parameter_list|)
block|{
return|return
name|qnumeric_std_wrapper
operator|::
name|isfinite
argument_list|(
name|f
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//
end_comment
begin_comment
comment|// Unsigned overflow math
end_comment
begin_comment
comment|//
end_comment
begin_macro
name|namespace
end_macro
begin_block
block|{
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
name|QtPrivate
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|bool
operator|>
operator|::
name|Type
name|add_overflow
argument_list|(
argument|T v1
argument_list|,
argument|T v2
argument_list|,
argument|T *r
argument_list|)
block|{
comment|// unsigned additions are well-defined
operator|*
name|r
operator|=
name|v1
operator|+
name|v2
block|;
return|return
name|v1
operator|>
name|T
argument_list|(
name|v1
operator|+
name|v2
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|typename
name|QtPrivate
operator|::
name|QEnableIf
operator|<
name|QtPrivate
operator|::
name|is_unsigned
operator|<
name|T
operator|>
operator|::
name|value
operator|,
name|bool
operator|>
operator|::
name|Type
name|mul_overflow
argument_list|(
argument|T v1
argument_list|,
argument|T v2
argument_list|,
argument|T *r
argument_list|)
block|{
comment|// use the next biggest type
comment|// Note: for 64-bit systems where __int128 isn't supported, this will cause an error.
comment|// A fallback is present below.
typedef|typedef
name|typename
name|QIntegerForSize
operator|<
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|2
operator|>
operator|::
name|Unsigned
name|Larger
expr_stmt|;
name|Larger
name|lr
operator|=
name|Larger
argument_list|(
name|v1
argument_list|)
operator|*
name|Larger
argument_list|(
name|v2
argument_list|)
expr_stmt|;
operator|*
name|r
operator|=
name|T
argument_list|(
name|lr
argument_list|)
expr_stmt|;
return|return
name|lr
operator|>
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
return|;
block|}
end_block
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SIZEOF_INT128__
argument_list|)
end_if
begin_define
DECL|macro|HAVE_MUL64_OVERFLOW
define|#
directive|define
name|HAVE_MUL64_OVERFLOW
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// GCC 5 and Clang have builtins to detect overflows
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_uadd_overflow
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|unsigned v1
argument_list|,
argument|unsigned v2
argument_list|,
argument|unsigned *r
argument_list|)
block|{
return|return
name|__builtin_uadd_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_uaddl_overflow
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|unsigned long v1
argument_list|,
argument|unsigned long v2
argument_list|,
argument|unsigned long *r
argument_list|)
block|{
return|return
name|__builtin_uaddl_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_uaddll_overflow
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|unsigned long long v1
argument_list|,
argument|unsigned long long v2
argument_list|,
argument|unsigned long long *r
argument_list|)
block|{
return|return
name|__builtin_uaddll_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_umul_overflow
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|mul_overflow
argument_list|(
argument|unsigned v1
argument_list|,
argument|unsigned v2
argument_list|,
argument|unsigned *r
argument_list|)
block|{
return|return
name|__builtin_umul_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_umull_overflow
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|mul_overflow
argument_list|(
argument|unsigned long v1
argument_list|,
argument|unsigned long v2
argument_list|,
argument|unsigned long *r
argument_list|)
block|{
return|return
name|__builtin_umull_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_umulll_overflow
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|mul_overflow
argument_list|(
argument|unsigned long long v1
argument_list|,
argument|unsigned long long v2
argument_list|,
argument|unsigned long long *r
argument_list|)
block|{
return|return
name|__builtin_umulll_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|HAVE_MUL64_OVERFLOW
define|#
directive|define
name|HAVE_MUL64_OVERFLOW
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1800
operator|)
operator|||
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|unsigned v1
argument_list|,
argument|unsigned v2
argument_list|,
argument|unsigned *r
argument_list|)
block|{
return|return
name|_addcarry_u32
argument_list|(
literal|0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|Q_CC_MSVC
end_ifdef
begin_comment
comment|// longs are 32-bit
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|unsigned long v1
argument_list|,
argument|unsigned long v2
argument_list|,
argument|unsigned long *r
argument_list|)
block|{
return|return
name|_addcarry_u32
argument_list|(
literal|0
argument_list|,
name|v1
argument_list|,
name|v2
argument_list|,
name|reinterpret_cast
operator|<
name|unsigned
operator|*
operator|>
operator|(
name|r
operator|)
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1800
operator|)
operator|||
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86_64
argument_list|)
end_if
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|quint64 v1
argument_list|,
argument|quint64 v2
argument_list|,
argument|quint64 *r
argument_list|)
block|{
return|return
name|_addcarry_u64
argument_list|(
literal|0
argument_list|,
argument|v1
argument_list|,
argument|v2
argument_list|,
argument|reinterpret_cast<unsigned __int64 *>(r)
argument_list|)
return|;
block|}
end_expr_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|Q_CC_MSVC
end_ifndef
begin_comment
comment|// longs are 64-bit
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|add_overflow
argument_list|(
argument|unsigned long v1
argument_list|,
argument|unsigned long v2
argument_list|,
argument|unsigned long *r
argument_list|)
block|{
return|return
name|_addcarry_u64
argument_list|(
literal|0
argument_list|,
argument|v1
argument_list|,
argument|v2
argument_list|,
argument|reinterpret_cast<unsigned __int64 *>(r)
argument_list|)
return|;
block|}
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_MSVC
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|Q_PROCESSOR_X86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_PROCESSOR_IA64
argument_list|)
operator|)
end_if
begin_pragma
pragma|#
directive|pragma
name|intrinsic
name|(
name|_umul128
name|)
end_pragma
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|mul_overflow
argument_list|(
argument|quint64 v1
argument_list|,
argument|quint64 v2
argument_list|,
argument|quint64 *r
argument_list|)
block|{
comment|// use 128-bit multiplication with the _umul128 intrinsic
comment|// https://msdn.microsoft.com/en-us/library/3dayytw9.aspx
name|quint64
name|high
block|;
operator|*
name|r
operator|=
name|_umul128
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
operator|&
name|high
argument_list|)
block|;
return|return
name|high
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|HAVE_MUL64_OVERFLOW
define|#
directive|define
name|HAVE_MUL64_OVERFLOW
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_MUL64_OVERFLOW
argument_list|)
operator|&&
name|defined
argument_list|(
name|__LP64__
argument_list|)
end_if
begin_comment
comment|// no 128-bit multiplication, we need to figure out with a slow division
end_comment
begin_expr_stmt
name|template
operator|<
operator|>
specifier|inline
name|bool
name|mul_overflow
argument_list|(
argument|quint64 v1
argument_list|,
argument|quint64 v2
argument_list|,
argument|quint64 *r
argument_list|)
block|{
if|if
condition|(
name|v2
operator|&&
name|v1
operator|>
name|std
operator|::
name|numeric_limits
operator|<
name|quint64
operator|>
operator|::
name|max
argument_list|()
operator|/
name|v2
condition|)
return|return
name|true
return|;
operator|*
name|r
operator|=
name|v1
operator|*
name|v2
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|false
return|;
end_return
begin_expr_stmt
unit|} template
operator|<
operator|>
specifier|inline
name|bool
name|mul_overflow
argument_list|(
argument|unsigned long v1
argument_list|,
argument|unsigned long v2
argument_list|,
argument|unsigned long *r
argument_list|)
block|{
return|return
name|mul_overflow
operator|<
name|quint64
operator|>
operator|(
name|v1
operator|,
name|v2
operator|,
name|reinterpret_cast
operator|<
name|quint64
operator|*
operator|>
operator|(
name|r
operator|)
operator|)
return|;
block|}
end_expr_stmt
begin_else
else|#
directive|else
end_else
begin_undef
undef|#
directive|undef
name|HAVE_MUL64_OVERFLOW
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//
end_comment
begin_comment
comment|// Signed overflow math
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// In C++, signed overflow math is Undefined Behavior. However, many CPUs do implement some way to
end_comment
begin_comment
comment|// check for overflow. Some compilers expose intrinsics to use this functionality. If the no
end_comment
begin_comment
comment|// intrinsic is exposed, overflow checking can be done by widening the result type and "manually"
end_comment
begin_comment
comment|// checking for overflow. Or, alternatively, by using inline assembly to use the CPU features.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// Only int overflow checking is implemented, because it's the only one used.
end_comment
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_sadd_overflow
argument_list|)
end_if
begin_function
specifier|inline
name|bool
name|add_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
return|return
name|__builtin_sadd_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_function
specifier|inline
name|bool
name|add_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
name|quint8
name|overflow
init|=
literal|0
decl_stmt|;
name|int
name|res
init|=
name|v1
decl_stmt|;
asm|asm ("addl %2, %1\n"          "seto %0"          : "=q" (overflow), "=r" (res)          : "r" (v2), "1" (res)          : "cc"     );
operator|*
name|r
operator|=
name|res
expr_stmt|;
return|return
name|overflow
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
specifier|inline
name|bool
name|add_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
name|qint64
name|t
init|=
name|qint64
argument_list|(
name|v1
argument_list|)
operator|+
name|v2
decl_stmt|;
operator|*
name|r
operator|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|t
operator|)
expr_stmt|;
return|return
name|t
operator|>
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|max
argument_list|()
operator|||
name|t
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|min
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_ssub_overflow
argument_list|)
end_if
begin_function
specifier|inline
name|bool
name|sub_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
return|return
name|__builtin_ssub_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_function
specifier|inline
name|bool
name|sub_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
name|quint8
name|overflow
init|=
literal|0
decl_stmt|;
name|int
name|res
init|=
name|v1
decl_stmt|;
asm|asm ("subl %2, %1\n"          "seto %0"          : "=q" (overflow), "=r" (res)          : "r" (v2), "1" (res)          : "cc"     );
operator|*
name|r
operator|=
name|res
expr_stmt|;
return|return
name|overflow
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
specifier|inline
name|bool
name|sub_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
name|qint64
name|t
init|=
name|qint64
argument_list|(
name|v1
argument_list|)
operator|-
name|v2
decl_stmt|;
operator|*
name|r
operator|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|t
operator|)
expr_stmt|;
return|return
name|t
operator|>
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|max
argument_list|()
operator|||
name|t
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|min
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_CC_INTEL
argument_list|)
operator|&&
name|Q_CC_GNU
operator|>=
literal|500
operator|)
operator|||
name|QT_HAS_BUILTIN
argument_list|(
name|__builtin_smul_overflow
argument_list|)
end_if
begin_function
specifier|inline
name|bool
name|mul_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
return|return
name|__builtin_smul_overflow
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|r
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_CC_GNU
argument_list|)
operator|&&
name|defined
argument_list|(
name|Q_PROCESSOR_X86
argument_list|)
end_elif
begin_function
specifier|inline
name|bool
name|mul_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
name|quint8
name|overflow
init|=
literal|0
decl_stmt|;
name|int
name|res
init|=
name|v1
decl_stmt|;
asm|asm ("imul %2, %1\n"          "seto %0"          : "=q" (overflow), "=r" (res)          : "r" (v2), "1" (res)          : "cc"     );
operator|*
name|r
operator|=
name|res
expr_stmt|;
return|return
name|overflow
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_function
specifier|inline
name|bool
name|mul_overflow
parameter_list|(
name|int
name|v1
parameter_list|,
name|int
name|v2
parameter_list|,
name|int
modifier|*
name|r
parameter_list|)
block|{
name|qint64
name|t
init|=
name|qint64
argument_list|(
name|v1
argument_list|)
operator|*
name|v2
decl_stmt|;
operator|*
name|r
operator|=
name|static_cast
operator|<
name|int
operator|>
operator|(
name|t
operator|)
expr_stmt|;
return|return
name|t
operator|>
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|max
argument_list|()
operator|||
name|t
operator|<
name|std
operator|::
name|numeric_limits
operator|<
name|int
operator|>
operator|::
name|min
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_endif
unit|}  QT_END_NAMESPACE
endif|#
directive|endif
end_endif
begin_comment
comment|// QNUMERIC_P_H
end_comment
end_unit
