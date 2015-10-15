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
name|DOUBLE_CONVERSION_CACHED_POWERS_H_
end_ifndef
begin_define
DECL|macro|DOUBLE_CONVERSION_CACHED_POWERS_H_
define|#
directive|define
name|DOUBLE_CONVERSION_CACHED_POWERS_H_
end_define
begin_include
include|#
directive|include
file|"diy-fp.h"
end_include
begin_decl_stmt
name|namespace
name|double_conversion
block|{
name|class
name|PowersOfTenCache
block|{
name|public
label|:
comment|// Not all powers of ten are cached. The decimal exponent of two neighboring
comment|// cached numbers will differ by kDecimalExponentDistance.
specifier|static
specifier|const
name|int
name|kDecimalExponentDistance
decl_stmt|;
specifier|static
specifier|const
name|int
name|kMinDecimalExponent
decl_stmt|;
specifier|static
specifier|const
name|int
name|kMaxDecimalExponent
decl_stmt|;
comment|// Returns a cached power-of-ten with a binary exponent in the range
comment|// [min_exponent; max_exponent] (boundaries included).
specifier|static
name|void
name|GetCachedPowerForBinaryExponentRange
parameter_list|(
name|int
name|min_exponent
parameter_list|,
name|int
name|max_exponent
parameter_list|,
name|DiyFp
modifier|*
name|power
parameter_list|,
name|int
modifier|*
name|decimal_exponent
parameter_list|)
function_decl|;
comment|// Returns a cached power of ten x ~= 10^k such that
comment|//   k<= decimal_exponent< k + kCachedPowersDecimalDistance.
comment|// The given decimal_exponent must satisfy
comment|//   kMinDecimalExponent<= requested_exponent, and
comment|//   requested_exponent< kMaxDecimalExponent + kDecimalExponentDistance.
specifier|static
name|void
name|GetCachedPowerForDecimalExponent
parameter_list|(
name|int
name|requested_exponent
parameter_list|,
name|DiyFp
modifier|*
name|power
parameter_list|,
name|int
modifier|*
name|found_exponent
parameter_list|)
function_decl|;
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
comment|// DOUBLE_CONVERSION_CACHED_POWERS_H_
end_comment
end_unit
