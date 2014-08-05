begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// mathutil.h: Math and bit manipulation functions.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBGLESV2_MATHUTIL_H_
end_ifndef
begin_define
DECL|macro|LIBGLESV2_MATHUTIL_H_
define|#
directive|define
name|LIBGLESV2_MATHUTIL_H_
end_define
begin_include
include|#
directive|include
file|"common/debug.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_include
include|#
directive|include
file|<limits>
end_include
begin_include
include|#
directive|include
file|<algorithm>
end_include
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_decl_stmt
name|namespace
name|gl
block|{
specifier|const
name|unsigned
name|int
name|Float32One
init|=
literal|0x3F800000
decl_stmt|;
specifier|const
name|unsigned
name|short
name|Float16One
init|=
literal|0x3C00
decl_stmt|;
struct|struct
name|Vector4
block|{
name|Vector4
argument_list|()
block|{}
name|Vector4
argument_list|(
argument|float x
argument_list|,
argument|float y
argument_list|,
argument|float z
argument_list|,
argument|float w
argument_list|)
block|:
name|x
argument_list|(
name|x
argument_list|)
operator|,
name|y
argument_list|(
name|y
argument_list|)
operator|,
name|z
argument_list|(
name|z
argument_list|)
operator|,
name|w
argument_list|(
argument|w
argument_list|)
block|{}
name|float
name|x
expr_stmt|;
name|float
name|y
decl_stmt|;
name|float
name|z
decl_stmt|;
name|float
name|w
decl_stmt|;
block|}
struct|;
specifier|inline
name|bool
name|isPow2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
return|return
operator|(
name|x
operator|&
operator|(
name|x
operator|-
literal|1
operator|)
operator|)
operator|==
literal|0
operator|&&
operator|(
name|x
operator|!=
literal|0
operator|)
return|;
block|}
specifier|inline
name|int
name|log2
parameter_list|(
name|int
name|x
parameter_list|)
block|{
name|int
name|r
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|x
operator|>>
name|r
operator|)
operator|>
literal|1
condition|)
name|r
operator|++
expr_stmt|;
return|return
name|r
return|;
block|}
specifier|inline
name|unsigned
name|int
name|ceilPow2
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|!=
literal|0
condition|)
name|x
operator|--
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|1
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|2
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|4
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|8
expr_stmt|;
name|x
operator||=
name|x
operator|>>
literal|16
expr_stmt|;
name|x
operator|++
expr_stmt|;
return|return
name|x
return|;
block|}
specifier|inline
name|int
name|clampToInt
parameter_list|(
name|unsigned
name|int
name|x
parameter_list|)
block|{
return|return
name|static_cast
operator|<
name|int
operator|>
operator|(
name|std
operator|::
name|min
argument_list|(
argument|x
argument_list|,
argument|static_cast<unsigned int>(std::numeric_limits<int>::max())
argument_list|)
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|DestT
operator|,
name|typename
name|SrcT
operator|>
specifier|inline
name|DestT
name|clampCast
argument_list|(
argument|SrcT value
argument_list|)
block|{
comment|// This assumes SrcT can properly represent DestT::min/max
comment|// Unfortunately we can't use META_ASSERT without C++11 constexpr support
name|ASSERT
argument_list|(
name|static_cast
operator|<
name|DestT
operator|>
operator|(
name|static_cast
operator|<
name|SrcT
operator|>
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|DestT
operator|>
operator|::
name|min
argument_list|()
operator|)
operator|)
operator|==
name|std
operator|::
name|numeric_limits
operator|<
name|DestT
operator|>
operator|::
name|min
argument_list|()
argument_list|)
block|;
name|ASSERT
argument_list|(
name|static_cast
operator|<
name|DestT
operator|>
operator|(
name|static_cast
operator|<
name|SrcT
operator|>
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|DestT
operator|>
operator|::
name|max
argument_list|()
operator|)
operator|)
operator|==
name|std
operator|::
name|numeric_limits
operator|<
name|DestT
operator|>
operator|::
name|max
argument_list|()
argument_list|)
block|;
name|SrcT
name|lo
operator|=
name|static_cast
operator|<
name|SrcT
operator|>
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|DestT
operator|>
operator|::
name|min
argument_list|()
operator|)
block|;
name|SrcT
name|hi
operator|=
name|static_cast
operator|<
name|SrcT
operator|>
operator|(
name|std
operator|::
name|numeric_limits
operator|<
name|DestT
operator|>
operator|::
name|max
argument_list|()
operator|)
block|;
return|return
name|static_cast
operator|<
name|DestT
operator|>
operator|(
name|value
operator|>
name|lo
condition|?
operator|(
name|value
operator|>
name|hi
condition|?
name|hi
else|:
name|value
operator|)
else|:
name|lo
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|MIN
operator|,
name|typename
name|MAX
operator|>
specifier|inline
name|T
name|clamp
argument_list|(
argument|T x
argument_list|,
argument|MIN min
argument_list|,
argument|MAX max
argument_list|)
block|{
comment|// Since NaNs fail all comparison tests, a NaN value will default to min
return|return
name|x
operator|>
name|min
operator|?
operator|(
name|x
operator|>
name|max
operator|?
name|max
operator|:
name|x
operator|)
operator|:
name|min
return|;
block|}
specifier|inline
name|float
name|clamp01
parameter_list|(
name|float
name|x
parameter_list|)
block|{
return|return
name|clamp
argument_list|(
name|x
argument_list|,
literal|0.0f
argument_list|,
literal|1.0f
argument_list|)
return|;
block|}
name|template
operator|<
specifier|const
name|int
name|n
operator|>
specifier|inline
name|unsigned
name|int
name|unorm
argument_list|(
argument|float x
argument_list|)
block|{
specifier|const
name|unsigned
name|int
name|max
operator|=
literal|0xFFFFFFFF
operator|>>
operator|(
literal|32
operator|-
name|n
operator|)
block|;
if|if
condition|(
name|x
operator|>
literal|1
condition|)
block|{
return|return
name|max
return|;
block|}
elseif|else
if|if
condition|(
name|x
operator|<
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
call|(
name|unsigned
name|int
call|)
argument_list|(
name|max
operator|*
name|x
operator|+
literal|0.5f
argument_list|)
return|;
block|}
block|}
specifier|inline
name|bool
name|supportsSSE2
argument_list|()
block|{
ifdef|#
directive|ifdef
name|ANGLE_PLATFORM_WINDOWS
specifier|static
name|bool
name|checked
operator|=
name|false
block|;
specifier|static
name|bool
name|supports
operator|=
name|false
block|;
if|if
condition|(
name|checked
condition|)
block|{
return|return
name|supports
return|;
block|}
if|#
directive|if
name|defined
argument_list|(
name|_M_IX86
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_AMD64
argument_list|)
comment|// ARM doesn't provide __cpuid()
name|int
name|info
index|[
literal|4
index|]
decl_stmt|;
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
index|[
literal|0
index|]
operator|>=
literal|1
condition|)
block|{
name|__cpuid
argument_list|(
name|info
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|supports
operator|=
operator|(
name|info
index|[
literal|3
index|]
operator|>>
literal|26
operator|)
operator|&
literal|1
expr_stmt|;
block|}
endif|#
directive|endif
name|checked
operator|=
name|true
expr_stmt|;
return|return
name|supports
return|;
else|#
directive|else
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return
name|false
return|;
endif|#
directive|endif
block|}
end_decl_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|destType
operator|,
name|typename
name|sourceType
operator|>
name|destType
name|bitCast
argument_list|(
argument|const sourceType&source
argument_list|)
block|{
name|size_t
name|copySize
operator|=
name|std
operator|::
name|min
argument_list|(
sizeof|sizeof
argument_list|(
name|destType
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|sourceType
argument_list|)
argument_list|)
block|;
name|destType
name|output
block|;
name|memcpy
argument_list|(
operator|&
name|output
argument_list|,
operator|&
name|source
argument_list|,
name|copySize
argument_list|)
block|;
return|return
name|output
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|unsigned
name|short
name|float32ToFloat16
parameter_list|(
name|float
name|fp32
parameter_list|)
block|{
name|unsigned
name|int
name|fp32i
init|=
operator|(
name|unsigned
name|int
operator|&
operator|)
name|fp32
decl_stmt|;
name|unsigned
name|int
name|sign
init|=
operator|(
name|fp32i
operator|&
literal|0x80000000
operator|)
operator|>>
literal|16
decl_stmt|;
name|unsigned
name|int
name|abs
init|=
name|fp32i
operator|&
literal|0x7FFFFFFF
decl_stmt|;
if|if
condition|(
name|abs
operator|>
literal|0x47FFEFFF
condition|)
comment|// Infinity
block|{
return|return
name|sign
operator||
literal|0x7FFF
return|;
block|}
elseif|else
if|if
condition|(
name|abs
operator|<
literal|0x38800000
condition|)
comment|// Denormal
block|{
name|unsigned
name|int
name|mantissa
init|=
operator|(
name|abs
operator|&
literal|0x007FFFFF
operator|)
operator||
literal|0x00800000
decl_stmt|;
name|int
name|e
init|=
literal|113
operator|-
operator|(
name|abs
operator|>>
literal|23
operator|)
decl_stmt|;
if|if
condition|(
name|e
operator|<
literal|24
condition|)
block|{
name|abs
operator|=
name|mantissa
operator|>>
name|e
expr_stmt|;
block|}
else|else
block|{
name|abs
operator|=
literal|0
expr_stmt|;
block|}
return|return
name|sign
operator||
operator|(
name|abs
operator|+
literal|0x00000FFF
operator|+
operator|(
operator|(
name|abs
operator|>>
literal|13
operator|)
operator|&
literal|1
operator|)
operator|)
operator|>>
literal|13
return|;
block|}
else|else
block|{
return|return
name|sign
operator||
operator|(
name|abs
operator|+
literal|0xC8000000
operator|+
literal|0x00000FFF
operator|+
operator|(
operator|(
name|abs
operator|>>
literal|13
operator|)
operator|&
literal|1
operator|)
operator|)
operator|>>
literal|13
return|;
block|}
block|}
end_function
begin_function_decl
name|float
name|float16ToFloat32
parameter_list|(
name|unsigned
name|short
name|h
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|unsigned
name|int
name|convertRGBFloatsTo999E5
parameter_list|(
name|float
name|red
parameter_list|,
name|float
name|green
parameter_list|,
name|float
name|blue
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|convert999E5toRGBFloats
parameter_list|(
name|unsigned
name|int
name|input
parameter_list|,
name|float
modifier|*
name|red
parameter_list|,
name|float
modifier|*
name|green
parameter_list|,
name|float
modifier|*
name|blue
parameter_list|)
function_decl|;
end_function_decl
begin_function
specifier|inline
name|unsigned
name|short
name|float32ToFloat11
parameter_list|(
name|float
name|fp32
parameter_list|)
block|{
specifier|const
name|unsigned
name|int
name|float32MantissaMask
init|=
literal|0x7FFFFF
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ExponentMask
init|=
literal|0x7F800000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32SignMask
init|=
literal|0x80000000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ValueMask
init|=
operator|~
name|float32SignMask
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ExponentFirstBit
init|=
literal|23
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ExponentBias
init|=
literal|127
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float11Max
init|=
literal|0x7BF
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float11MantissaMask
init|=
literal|0x3F
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float11ExponentMask
init|=
literal|0x7C0
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float11BitMask
init|=
literal|0x7FF
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float11ExponentBias
init|=
literal|14
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32Maxfloat11
init|=
literal|0x477E0000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32Minfloat11
init|=
literal|0x38800000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32Bits
init|=
name|bitCast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|fp32
operator|)
decl_stmt|;
specifier|const
name|bool
name|float32Sign
init|=
operator|(
name|float32Bits
operator|&
name|float32SignMask
operator|)
operator|==
name|float32SignMask
decl_stmt|;
name|unsigned
name|int
name|float32Val
init|=
name|float32Bits
operator|&
name|float32ValueMask
decl_stmt|;
if|if
condition|(
operator|(
name|float32Val
operator|&
name|float32ExponentMask
operator|)
operator|==
name|float32ExponentMask
condition|)
block|{
comment|// INF or NAN
if|if
condition|(
operator|(
name|float32Val
operator|&
name|float32MantissaMask
operator|)
operator|!=
literal|0
condition|)
block|{
return|return
name|float11ExponentMask
operator||
operator|(
operator|(
operator|(
name|float32Val
operator|>>
literal|17
operator|)
operator||
operator|(
name|float32Val
operator|>>
literal|11
operator|)
operator||
operator|(
name|float32Val
operator|>>
literal|6
operator|)
operator||
operator|(
name|float32Val
operator|)
operator|)
operator|&
name|float11MantissaMask
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|float32Sign
condition|)
block|{
comment|// -INF is clamped to 0 since float11 is positive only
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
name|float11ExponentMask
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|float32Sign
condition|)
block|{
comment|// float11 is positive only, so clamp to zero
return|return
literal|0
return|;
block|}
elseif|else
if|if
condition|(
name|float32Val
operator|>
name|float32Maxfloat11
condition|)
block|{
comment|// The number is too large to be represented as a float11, set to max
return|return
name|float11Max
return|;
block|}
else|else
block|{
if|if
condition|(
name|float32Val
operator|<
name|float32Minfloat11
condition|)
block|{
comment|// The number is too small to be represented as a normalized float11
comment|// Convert it to a denormalized value.
specifier|const
name|unsigned
name|int
name|shift
init|=
operator|(
name|float32ExponentBias
operator|-
name|float11ExponentBias
operator|)
operator|-
operator|(
name|float32Val
operator|>>
name|float32ExponentFirstBit
operator|)
decl_stmt|;
name|float32Val
operator|=
operator|(
operator|(
literal|1
operator|<<
name|float32ExponentFirstBit
operator|)
operator||
operator|(
name|float32Val
operator|&
name|float32MantissaMask
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
block|}
else|else
block|{
comment|// Rebias the exponent to represent the value as a normalized float11
name|float32Val
operator|+=
literal|0xC8000000
expr_stmt|;
block|}
return|return
operator|(
operator|(
name|float32Val
operator|+
literal|0xFFFF
operator|+
operator|(
operator|(
name|float32Val
operator|>>
literal|17
operator|)
operator|&
literal|1
operator|)
operator|)
operator|>>
literal|17
operator|)
operator|&
name|float11BitMask
return|;
block|}
block|}
end_function
begin_function
specifier|inline
name|unsigned
name|short
name|float32ToFloat10
parameter_list|(
name|float
name|fp32
parameter_list|)
block|{
specifier|const
name|unsigned
name|int
name|float32MantissaMask
init|=
literal|0x7FFFFF
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ExponentMask
init|=
literal|0x7F800000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32SignMask
init|=
literal|0x80000000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ValueMask
init|=
operator|~
name|float32SignMask
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ExponentFirstBit
init|=
literal|23
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32ExponentBias
init|=
literal|127
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float10Max
init|=
literal|0x3DF
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float10MantissaMask
init|=
literal|0x1F
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float10ExponentMask
init|=
literal|0x3E0
decl_stmt|;
specifier|const
name|unsigned
name|short
name|float10BitMask
init|=
literal|0x3FF
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float10ExponentBias
init|=
literal|14
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32Maxfloat10
init|=
literal|0x477C0000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32Minfloat10
init|=
literal|0x38800000
decl_stmt|;
specifier|const
name|unsigned
name|int
name|float32Bits
init|=
name|bitCast
operator|<
name|unsigned
name|int
operator|>
operator|(
name|fp32
operator|)
decl_stmt|;
specifier|const
name|bool
name|float32Sign
init|=
operator|(
name|float32Bits
operator|&
name|float32SignMask
operator|)
operator|==
name|float32SignMask
decl_stmt|;
name|unsigned
name|int
name|float32Val
init|=
name|float32Bits
operator|&
name|float32ValueMask
decl_stmt|;
if|if
condition|(
operator|(
name|float32Val
operator|&
name|float32ExponentMask
operator|)
operator|==
name|float32ExponentMask
condition|)
block|{
comment|// INF or NAN
if|if
condition|(
operator|(
name|float32Val
operator|&
name|float32MantissaMask
operator|)
operator|!=
literal|0
condition|)
block|{
return|return
name|float10ExponentMask
operator||
operator|(
operator|(
operator|(
name|float32Val
operator|>>
literal|18
operator|)
operator||
operator|(
name|float32Val
operator|>>
literal|13
operator|)
operator||
operator|(
name|float32Val
operator|>>
literal|3
operator|)
operator||
operator|(
name|float32Val
operator|)
operator|)
operator|&
name|float10MantissaMask
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|float32Sign
condition|)
block|{
comment|// -INF is clamped to 0 since float11 is positive only
return|return
literal|0
return|;
block|}
else|else
block|{
return|return
name|float10ExponentMask
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|float32Sign
condition|)
block|{
comment|// float10 is positive only, so clamp to zero
return|return
literal|0
return|;
block|}
elseif|else
if|if
condition|(
name|float32Val
operator|>
name|float32Maxfloat10
condition|)
block|{
comment|// The number is too large to be represented as a float11, set to max
return|return
name|float10Max
return|;
block|}
else|else
block|{
if|if
condition|(
name|float32Val
operator|<
name|float32Minfloat10
condition|)
block|{
comment|// The number is too small to be represented as a normalized float11
comment|// Convert it to a denormalized value.
specifier|const
name|unsigned
name|int
name|shift
init|=
operator|(
name|float32ExponentBias
operator|-
name|float10ExponentBias
operator|)
operator|-
operator|(
name|float32Val
operator|>>
name|float32ExponentFirstBit
operator|)
decl_stmt|;
name|float32Val
operator|=
operator|(
operator|(
literal|1
operator|<<
name|float32ExponentFirstBit
operator|)
operator||
operator|(
name|float32Val
operator|&
name|float32MantissaMask
operator|)
operator|)
operator|>>
name|shift
expr_stmt|;
block|}
else|else
block|{
comment|// Rebias the exponent to represent the value as a normalized float11
name|float32Val
operator|+=
literal|0xC8000000
expr_stmt|;
block|}
return|return
operator|(
operator|(
name|float32Val
operator|+
literal|0x1FFFF
operator|+
operator|(
operator|(
name|float32Val
operator|>>
literal|18
operator|)
operator|&
literal|1
operator|)
operator|)
operator|>>
literal|18
operator|)
operator|&
name|float10BitMask
return|;
block|}
block|}
end_function
begin_function
specifier|inline
name|float
name|float11ToFloat32
parameter_list|(
name|unsigned
name|short
name|fp11
parameter_list|)
block|{
name|unsigned
name|short
name|exponent
init|=
operator|(
name|fp11
operator|>>
literal|6
operator|)
operator|&
literal|0x1F
decl_stmt|;
name|unsigned
name|short
name|mantissa
init|=
name|fp11
operator|&
literal|0x3F
decl_stmt|;
if|if
condition|(
name|exponent
operator|==
literal|0x1F
condition|)
block|{
comment|// INF or NAN
return|return
name|bitCast
operator|<
name|float
operator|>
operator|(
literal|0x7f800000
operator||
operator|(
name|mantissa
operator|<<
literal|17
operator|)
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|exponent
operator|!=
literal|0
condition|)
block|{
comment|// normalized
block|}
elseif|else
if|if
condition|(
name|mantissa
operator|!=
literal|0
condition|)
block|{
comment|// The value is denormalized
name|exponent
operator|=
literal|1
expr_stmt|;
do|do
block|{
name|exponent
operator|--
expr_stmt|;
name|mantissa
operator|<<=
literal|1
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|mantissa
operator|&
literal|0x40
operator|)
operator|==
literal|0
condition|)
do|;
name|mantissa
operator|=
name|mantissa
operator|&
literal|0x3F
expr_stmt|;
block|}
else|else
comment|// The value is zero
block|{
name|exponent
operator|=
operator|-
literal|112
expr_stmt|;
block|}
return|return
name|bitCast
operator|<
name|float
operator|>
operator|(
operator|(
operator|(
name|exponent
operator|+
literal|112
operator|)
operator|<<
literal|23
operator|)
operator||
operator|(
name|mantissa
operator|<<
literal|17
operator|)
operator|)
return|;
block|}
block|}
end_function
begin_function
specifier|inline
name|float
name|float10ToFloat32
parameter_list|(
name|unsigned
name|short
name|fp11
parameter_list|)
block|{
name|unsigned
name|short
name|exponent
init|=
operator|(
name|fp11
operator|>>
literal|5
operator|)
operator|&
literal|0x1F
decl_stmt|;
name|unsigned
name|short
name|mantissa
init|=
name|fp11
operator|&
literal|0x1F
decl_stmt|;
if|if
condition|(
name|exponent
operator|==
literal|0x1F
condition|)
block|{
comment|// INF or NAN
return|return
name|bitCast
operator|<
name|float
operator|>
operator|(
literal|0x7f800000
operator||
operator|(
name|mantissa
operator|<<
literal|17
operator|)
operator|)
return|;
block|}
else|else
block|{
if|if
condition|(
name|exponent
operator|!=
literal|0
condition|)
block|{
comment|// normalized
block|}
elseif|else
if|if
condition|(
name|mantissa
operator|!=
literal|0
condition|)
block|{
comment|// The value is denormalized
name|exponent
operator|=
literal|1
expr_stmt|;
do|do
block|{
name|exponent
operator|--
expr_stmt|;
name|mantissa
operator|<<=
literal|1
expr_stmt|;
block|}
do|while
condition|(
operator|(
name|mantissa
operator|&
literal|0x20
operator|)
operator|==
literal|0
condition|)
do|;
name|mantissa
operator|=
name|mantissa
operator|&
literal|0x1F
expr_stmt|;
block|}
else|else
comment|// The value is zero
block|{
name|exponent
operator|=
operator|-
literal|112
expr_stmt|;
block|}
return|return
name|bitCast
operator|<
name|float
operator|>
operator|(
operator|(
operator|(
name|exponent
operator|+
literal|112
operator|)
operator|<<
literal|23
operator|)
operator||
operator|(
name|mantissa
operator|<<
literal|18
operator|)
operator|)
return|;
block|}
block|}
end_function
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|float
name|normalizedToFloat
argument_list|(
argument|T input
argument_list|)
block|{
name|META_ASSERT
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
argument_list|)
block|;
specifier|const
name|float
name|inverseMax
operator|=
literal|1.0f
operator|/
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
block|;
return|return
name|input
operator|*
name|inverseMax
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|unsigned
name|int
name|inputBitCount
operator|,
name|typename
name|T
operator|>
specifier|inline
name|float
name|normalizedToFloat
argument_list|(
argument|T input
argument_list|)
block|{
name|META_ASSERT
argument_list|(
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_integer
argument_list|)
block|;
name|META_ASSERT
argument_list|(
name|inputBitCount
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
operator|)
argument_list|)
block|;
specifier|const
name|float
name|inverseMax
operator|=
literal|1.0f
operator|/
operator|(
operator|(
literal|1
operator|<<
name|inputBitCount
operator|)
operator|-
literal|1
operator|)
block|;
return|return
name|input
operator|*
name|inverseMax
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
name|floatToNormalized
argument_list|(
argument|float input
argument_list|)
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
operator|*
name|input
operator|+
literal|0.5f
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|unsigned
name|int
name|outputBitCount
operator|,
name|typename
name|T
operator|>
specifier|inline
name|T
name|floatToNormalized
argument_list|(
argument|float input
argument_list|)
block|{
name|META_ASSERT
argument_list|(
name|outputBitCount
operator|<
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
operator|)
argument_list|)
block|;
return|return
operator|(
operator|(
literal|1
operator|<<
name|outputBitCount
operator|)
operator|-
literal|1
operator|)
operator|*
name|input
operator|+
literal|0.5f
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|unsigned
name|int
name|inputBitCount
operator|,
name|unsigned
name|int
name|inputBitStart
operator|,
name|typename
name|T
operator|>
specifier|inline
name|T
name|getShiftedData
argument_list|(
argument|T input
argument_list|)
block|{
name|META_ASSERT
argument_list|(
name|inputBitCount
operator|+
name|inputBitStart
operator|<=
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
operator|)
argument_list|)
block|;
specifier|const
name|T
name|mask
operator|=
operator|(
literal|1
operator|<<
name|inputBitCount
operator|)
operator|-
literal|1
block|;
return|return
operator|(
name|input
operator|>>
name|inputBitStart
operator|)
operator|&
name|mask
return|;
block|}
end_expr_stmt
begin_expr_stmt
name|template
operator|<
name|unsigned
name|int
name|inputBitCount
operator|,
name|unsigned
name|int
name|inputBitStart
operator|,
name|typename
name|T
operator|>
specifier|inline
name|T
name|shiftData
argument_list|(
argument|T input
argument_list|)
block|{
name|META_ASSERT
argument_list|(
name|inputBitCount
operator|+
name|inputBitStart
operator|<=
operator|(
sizeof|sizeof
argument_list|(
name|T
argument_list|)
operator|*
literal|8
operator|)
argument_list|)
block|;
specifier|const
name|T
name|mask
operator|=
operator|(
literal|1
operator|<<
name|inputBitCount
operator|)
operator|-
literal|1
block|;
return|return
operator|(
name|input
operator|&
name|mask
operator|)
operator|<<
name|inputBitStart
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|unsigned
name|char
name|average
parameter_list|(
name|unsigned
name|char
name|a
parameter_list|,
name|unsigned
name|char
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|a
operator|^
name|b
operator|)
operator|>>
literal|1
operator|)
operator|+
operator|(
name|a
operator|&
name|b
operator|)
return|;
block|}
end_function
begin_function
specifier|inline
name|signed
name|char
name|average
parameter_list|(
name|signed
name|char
name|a
parameter_list|,
name|signed
name|char
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|short
operator|)
name|a
operator|+
operator|(
name|short
operator|)
name|b
operator|)
operator|/
literal|2
return|;
block|}
end_function
begin_function
specifier|inline
name|unsigned
name|short
name|average
parameter_list|(
name|unsigned
name|short
name|a
parameter_list|,
name|unsigned
name|short
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|a
operator|^
name|b
operator|)
operator|>>
literal|1
operator|)
operator|+
operator|(
name|a
operator|&
name|b
operator|)
return|;
block|}
end_function
begin_function
specifier|inline
name|signed
name|short
name|average
parameter_list|(
name|signed
name|short
name|a
parameter_list|,
name|signed
name|short
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|int
operator|)
name|a
operator|+
operator|(
name|int
operator|)
name|b
operator|)
operator|/
literal|2
return|;
block|}
end_function
begin_function
specifier|inline
name|unsigned
name|int
name|average
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|,
name|unsigned
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|a
operator|^
name|b
operator|)
operator|>>
literal|1
operator|)
operator|+
operator|(
name|a
operator|&
name|b
operator|)
return|;
block|}
end_function
begin_function
specifier|inline
name|signed
name|int
name|average
parameter_list|(
name|signed
name|int
name|a
parameter_list|,
name|signed
name|int
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|long
name|long
operator|)
name|a
operator|+
operator|(
name|long
name|long
operator|)
name|b
operator|)
operator|/
literal|2
return|;
block|}
end_function
begin_function
specifier|inline
name|float
name|average
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|+
name|b
operator|)
operator|*
literal|0.5f
return|;
block|}
end_function
begin_function
specifier|inline
name|unsigned
name|short
name|averageHalfFloat
parameter_list|(
name|unsigned
name|short
name|a
parameter_list|,
name|unsigned
name|short
name|b
parameter_list|)
block|{
return|return
name|float32ToFloat16
argument_list|(
operator|(
name|float16ToFloat32
argument_list|(
name|a
argument_list|)
operator|+
name|float16ToFloat32
argument_list|(
name|b
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|unsigned
name|int
name|averageFloat11
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|,
name|unsigned
name|int
name|b
parameter_list|)
block|{
return|return
name|float32ToFloat11
argument_list|(
operator|(
name|float11ToFloat32
argument_list|(
name|a
argument_list|)
operator|+
name|float11ToFloat32
argument_list|(
name|b
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
return|;
block|}
end_function
begin_function
specifier|inline
name|unsigned
name|int
name|averageFloat10
parameter_list|(
name|unsigned
name|int
name|a
parameter_list|,
name|unsigned
name|int
name|b
parameter_list|)
block|{
return|return
name|float32ToFloat10
argument_list|(
operator|(
name|float10ToFloat32
argument_list|(
name|a
argument_list|)
operator|+
name|float10ToFloat32
argument_list|(
name|b
argument_list|)
operator|)
operator|*
literal|0.5f
argument_list|)
return|;
block|}
end_function
begin_macro
unit|}  namespace
name|rx
end_macro
begin_block
block|{
struct|struct
name|Range
block|{
name|Range
argument_list|()
block|{}
name|Range
argument_list|(
argument|int lo
argument_list|,
argument|int hi
argument_list|)
block|:
name|start
argument_list|(
name|lo
argument_list|)
operator|,
name|end
argument_list|(
argument|hi
argument_list|)
block|{
name|ASSERT
argument_list|(
name|lo
operator|<=
name|hi
argument_list|)
block|; }
name|int
name|start
expr_stmt|;
name|int
name|end
decl_stmt|;
block|}
struct|;
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|roundUp
argument_list|(
argument|const T value
argument_list|,
argument|const T alignment
argument_list|)
block|{
return|return
name|value
operator|+
name|alignment
operator|-
literal|1
operator|-
operator|(
name|value
operator|-
literal|1
operator|)
operator|%
name|alignment
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|IsUnsignedAdditionSafe
argument_list|(
argument|T lhs
argument_list|,
argument|T rhs
argument_list|)
block|{
name|META_ASSERT
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|)
block|;
return|return
operator|(
name|rhs
operator|<=
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
operator|-
name|lhs
operator|)
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|bool
name|IsUnsignedMultiplicationSafe
argument_list|(
argument|T lhs
argument_list|,
argument|T rhs
argument_list|)
block|{
name|META_ASSERT
argument_list|(
operator|!
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|is_signed
argument_list|)
block|;
return|return
operator|(
name|lhs
operator|==
name|T
argument_list|(
literal|0
argument_list|)
operator|||
name|rhs
operator|==
name|T
argument_list|(
literal|0
argument_list|)
operator|||
operator|(
name|rhs
operator|<=
name|std
operator|::
name|numeric_limits
operator|<
name|T
operator|>
operator|::
name|max
argument_list|()
operator|/
name|lhs
operator|)
operator|)
return|;
block|}
name|template
operator|<
name|class
name|SmallIntT
operator|,
name|class
name|BigIntT
operator|>
specifier|inline
name|bool
name|IsIntegerCastSafe
argument_list|(
argument|BigIntT bigValue
argument_list|)
block|{
return|return
operator|(
name|static_cast
operator|<
name|BigIntT
operator|>
operator|(
name|static_cast
operator|<
name|SmallIntT
operator|>
operator|(
name|bigValue
operator|)
operator|)
operator|==
name|bigValue
operator|)
return|;
block|}
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// LIBGLESV2_MATHUTIL_H_
end_comment
end_unit
