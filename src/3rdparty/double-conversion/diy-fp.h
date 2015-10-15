begin_unit
begin_comment
comment|// Copyright 2010 the V8 project authors. All rights reserved.
end_comment
begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment
begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment
begin_comment
comment|// met:
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment
begin_comment
comment|//       notice, this list of conditions and the following disclaimer.
end_comment
begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment
begin_comment
comment|//       copyright notice, this list of conditions and the following
end_comment
begin_comment
comment|//       disclaimer in the documentation and/or other materials provided
end_comment
begin_comment
comment|//       with the distribution.
end_comment
begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment
begin_comment
comment|//       contributors may be used to endorse or promote products derived
end_comment
begin_comment
comment|//       from this software without specific prior written permission.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment
begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment
begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment
begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment
begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment
begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment
begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment
begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment
begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment
begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_CONVERSION_DIY_FP_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_DIY_FP_H_
define|#
directive|define
name|DOUBLE_CONVERSION_DIY_FP_H_
end_define
begin_include
include|#
directive|include
file|"utils.h"
end_include
begin_decl_stmt
name|namespace
name|double_conversion
block|{
comment|// This "Do It Yourself Floating Point" class implements a floating-point number
comment|// with a uint64 significand and an int exponent. Normalized DiyFp numbers will
comment|// have the most significant bit of the significand set.
comment|// Multiplication and Subtraction do not normalize their results.
comment|// DiyFp are not designed to contain special doubles (NaN and Infinity).
name|class
name|DiyFp
block|{
name|public
label|:
specifier|static
specifier|const
name|int
name|kSignificandSize
init|=
literal|64
decl_stmt|;
name|DiyFp
argument_list|()
operator|:
name|f_
argument_list|(
literal|0
argument_list|)
operator|,
name|e_
argument_list|(
literal|0
argument_list|)
block|{}
name|DiyFp
argument_list|(
argument|uint64_t f
argument_list|,
argument|int e
argument_list|)
operator|:
name|f_
argument_list|(
name|f
argument_list|)
operator|,
name|e_
argument_list|(
argument|e
argument_list|)
block|{}
comment|// this = this - other.
comment|// The exponents of both numbers must be the same and the significand of this
comment|// must be bigger than the significand of other.
comment|// The result will not be normalized.
name|void
name|Subtract
argument_list|(
argument|const DiyFp& other
argument_list|)
block|{
name|ASSERT
argument_list|(
name|e_
operator|==
name|other
operator|.
name|e_
argument_list|)
block|;
name|ASSERT
argument_list|(
name|f_
operator|>=
name|other
operator|.
name|f_
argument_list|)
block|;
name|f_
operator|-=
name|other
operator|.
name|f_
block|;   }
comment|// Returns a - b.
comment|// The exponents of both numbers must be the same and this must be bigger
comment|// than other. The result will not be normalized.
specifier|static
name|DiyFp
name|Minus
argument_list|(
argument|const DiyFp& a
argument_list|,
argument|const DiyFp& b
argument_list|)
block|{
name|DiyFp
name|result
operator|=
name|a
block|;
name|result
operator|.
name|Subtract
argument_list|(
name|b
argument_list|)
block|;
return|return
name|result
return|;
block|}
comment|// this = this * other.
name|void
name|Multiply
parameter_list|(
specifier|const
name|DiyFp
modifier|&
name|other
parameter_list|)
function_decl|;
comment|// returns a * b;
specifier|static
name|DiyFp
name|Times
parameter_list|(
specifier|const
name|DiyFp
modifier|&
name|a
parameter_list|,
specifier|const
name|DiyFp
modifier|&
name|b
parameter_list|)
block|{
name|DiyFp
name|result
init|=
name|a
decl_stmt|;
name|result
operator|.
name|Multiply
argument_list|(
name|b
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
name|void
name|Normalize
parameter_list|()
block|{
name|ASSERT
argument_list|(
name|f_
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|uint64_t
name|f
init|=
name|f_
decl_stmt|;
name|int
name|e
init|=
name|e_
decl_stmt|;
comment|// This method is mainly called for normalizing boundaries. In general
comment|// boundaries need to be shifted by 10 bits. We thus optimize for this case.
specifier|const
name|uint64_t
name|k10MSBits
init|=
name|UINT64_2PART_C
argument_list|(
literal|0xFFC00000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
while|while
condition|(
operator|(
name|f
operator|&
name|k10MSBits
operator|)
operator|==
literal|0
condition|)
block|{
name|f
operator|<<=
literal|10
expr_stmt|;
name|e
operator|-=
literal|10
expr_stmt|;
block|}
while|while
condition|(
operator|(
name|f
operator|&
name|kUint64MSB
operator|)
operator|==
literal|0
condition|)
block|{
name|f
operator|<<=
literal|1
expr_stmt|;
name|e
operator|--
expr_stmt|;
block|}
name|f_
operator|=
name|f
expr_stmt|;
name|e_
operator|=
name|e
expr_stmt|;
block|}
specifier|static
name|DiyFp
name|Normalize
parameter_list|(
specifier|const
name|DiyFp
modifier|&
name|a
parameter_list|)
block|{
name|DiyFp
name|result
init|=
name|a
decl_stmt|;
name|result
operator|.
name|Normalize
argument_list|()
expr_stmt|;
return|return
name|result
return|;
block|}
name|uint64_t
name|f
argument_list|()
specifier|const
block|{
return|return
name|f_
return|;
block|}
name|int
name|e
argument_list|()
specifier|const
block|{
return|return
name|e_
return|;
block|}
name|void
name|set_f
parameter_list|(
name|uint64_t
name|new_value
parameter_list|)
block|{
name|f_
operator|=
name|new_value
expr_stmt|;
block|}
name|void
name|set_e
parameter_list|(
name|int
name|new_value
parameter_list|)
block|{
name|e_
operator|=
name|new_value
expr_stmt|;
block|}
name|private
label|:
specifier|static
specifier|const
name|uint64_t
name|kUint64MSB
init|=
name|UINT64_2PART_C
argument_list|(
literal|0x80000000
argument_list|,
literal|00000000
argument_list|)
decl_stmt|;
name|uint64_t
name|f_
decl_stmt|;
name|int
name|e_
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt
begin_comment
comment|// namespace double_conversion
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// DOUBLE_CONVERSION_DIY_FP_H_
end_comment
end_unit
