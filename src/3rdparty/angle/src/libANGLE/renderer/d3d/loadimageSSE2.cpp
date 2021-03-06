begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright (c) 2002-2015 The ANGLE Project Authors. All rights reserved.
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
comment|// loadimageSSE2.cpp: Defines image loading functions. It's
end_comment
begin_comment
comment|// in a separated file for GCC, which can enable SSE usage only per-file,
end_comment
begin_comment
comment|// not for code blocks that use SSE2 explicitly.
end_comment
begin_include
include|#
directive|include
file|"libANGLE/renderer/d3d/loadimage.h"
end_include
begin_include
include|#
directive|include
file|"common/platform.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|ANGLE_USE_SSE
end_ifdef
begin_include
include|#
directive|include
file|<emmintrin.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_namespace
DECL|namespace|rx
namespace|namespace
name|rx
block|{
DECL|function|LoadA8ToBGRA8_SSE2
name|void
name|LoadA8ToBGRA8_SSE2
parameter_list|(
name|size_t
name|width
parameter_list|,
name|size_t
name|height
parameter_list|,
name|size_t
name|depth
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|input
parameter_list|,
name|size_t
name|inputRowPitch
parameter_list|,
name|size_t
name|inputDepthPitch
parameter_list|,
name|uint8_t
modifier|*
name|output
parameter_list|,
name|size_t
name|outputRowPitch
parameter_list|,
name|size_t
name|outputDepthPitch
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_USE_SSE
argument_list|)
name|__m128i
name|zeroWide
init|=
name|_mm_setzero_si128
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|z
init|=
literal|0
init|;
name|z
operator|<
name|depth
condition|;
name|z
operator|++
control|)
block|{
for|for
control|(
name|size_t
name|y
init|=
literal|0
init|;
name|y
operator|<
name|height
condition|;
name|y
operator|++
control|)
block|{
specifier|const
name|uint8_t
modifier|*
name|source
init|=
name|OffsetDataPointer
argument_list|<
name|uint8_t
argument_list|>
argument_list|(
name|input
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|inputRowPitch
argument_list|,
name|inputDepthPitch
argument_list|)
decl_stmt|;
name|uint32_t
modifier|*
name|dest
init|=
name|OffsetDataPointer
argument_list|<
name|uint32_t
argument_list|>
argument_list|(
name|output
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|outputRowPitch
argument_list|,
name|outputDepthPitch
argument_list|)
decl_stmt|;
name|size_t
name|x
init|=
literal|0
decl_stmt|;
comment|// Make output writes aligned
for|for
control|(
init|;
operator|(
operator|(
cast|reinterpret_cast
argument_list|<
name|intptr_t
argument_list|>
argument_list|(
operator|&
name|dest
index|[
name|x
index|]
argument_list|)
operator|&
literal|0xF
operator|)
operator|!=
literal|0
operator|&&
name|x
operator|<
name|width
operator|)
condition|;
name|x
operator|++
control|)
block|{
name|dest
index|[
name|x
index|]
operator|=
cast|static_cast
argument_list|<
name|uint32_t
argument_list|>
argument_list|(
name|source
index|[
name|x
index|]
argument_list|)
operator|<<
literal|24
expr_stmt|;
block|}
for|for
control|(
init|;
name|x
operator|+
literal|7
operator|<
name|width
condition|;
name|x
operator|+=
literal|8
control|)
block|{
name|__m128i
name|sourceData
init|=
name|_mm_loadl_epi64
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|__m128i
operator|*
argument_list|>
argument_list|(
operator|&
name|source
index|[
name|x
index|]
argument_list|)
argument_list|)
decl_stmt|;
comment|// Interleave each byte to 16bit, make the lower byte to zero
name|sourceData
operator|=
name|_mm_unpacklo_epi8
argument_list|(
name|zeroWide
argument_list|,
name|sourceData
argument_list|)
expr_stmt|;
comment|// Interleave each 16bit to 32bit, make the lower 16bit to zero
name|__m128i
name|lo
init|=
name|_mm_unpacklo_epi16
argument_list|(
name|zeroWide
argument_list|,
name|sourceData
argument_list|)
decl_stmt|;
name|__m128i
name|hi
init|=
name|_mm_unpackhi_epi16
argument_list|(
name|zeroWide
argument_list|,
name|sourceData
argument_list|)
decl_stmt|;
name|_mm_store_si128
argument_list|(
cast|reinterpret_cast
argument_list|<
name|__m128i
operator|*
argument_list|>
argument_list|(
operator|&
name|dest
index|[
name|x
index|]
argument_list|)
argument_list|,
name|lo
argument_list|)
expr_stmt|;
name|_mm_store_si128
argument_list|(
cast|reinterpret_cast
argument_list|<
name|__m128i
operator|*
argument_list|>
argument_list|(
operator|&
name|dest
index|[
name|x
operator|+
literal|4
index|]
argument_list|)
argument_list|,
name|hi
argument_list|)
expr_stmt|;
block|}
comment|// Handle the remainder
for|for
control|(
init|;
name|x
operator|<
name|width
condition|;
name|x
operator|++
control|)
block|{
name|dest
index|[
name|x
index|]
operator|=
cast|static_cast
argument_list|<
name|uint32_t
argument_list|>
argument_list|(
name|source
index|[
name|x
index|]
argument_list|)
operator|<<
literal|24
expr_stmt|;
block|}
block|}
block|}
else|#
directive|else
comment|// Ensure that this function is reported as not implemented for ARM builds because
comment|// the instructions below are not present for that architecture.
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return;
endif|#
directive|endif
block|}
DECL|function|LoadRGBA8ToBGRA8_SSE2
name|void
name|LoadRGBA8ToBGRA8_SSE2
parameter_list|(
name|size_t
name|width
parameter_list|,
name|size_t
name|height
parameter_list|,
name|size_t
name|depth
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|input
parameter_list|,
name|size_t
name|inputRowPitch
parameter_list|,
name|size_t
name|inputDepthPitch
parameter_list|,
name|uint8_t
modifier|*
name|output
parameter_list|,
name|size_t
name|outputRowPitch
parameter_list|,
name|size_t
name|outputDepthPitch
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|ANGLE_USE_SSE
argument_list|)
name|__m128i
name|brMask
init|=
name|_mm_set1_epi32
argument_list|(
literal|0x00ff00ff
argument_list|)
decl_stmt|;
for|for
control|(
name|size_t
name|z
init|=
literal|0
init|;
name|z
operator|<
name|depth
condition|;
name|z
operator|++
control|)
block|{
for|for
control|(
name|size_t
name|y
init|=
literal|0
init|;
name|y
operator|<
name|height
condition|;
name|y
operator|++
control|)
block|{
specifier|const
name|uint32_t
modifier|*
name|source
init|=
name|OffsetDataPointer
argument_list|<
name|uint32_t
argument_list|>
argument_list|(
name|input
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|inputRowPitch
argument_list|,
name|inputDepthPitch
argument_list|)
decl_stmt|;
name|uint32_t
modifier|*
name|dest
init|=
name|OffsetDataPointer
argument_list|<
name|uint32_t
argument_list|>
argument_list|(
name|output
argument_list|,
name|y
argument_list|,
name|z
argument_list|,
name|outputRowPitch
argument_list|,
name|outputDepthPitch
argument_list|)
decl_stmt|;
name|size_t
name|x
init|=
literal|0
decl_stmt|;
comment|// Make output writes aligned
for|for
control|(
init|;
operator|(
operator|(
cast|reinterpret_cast
argument_list|<
name|intptr_t
argument_list|>
argument_list|(
operator|&
name|dest
index|[
name|x
index|]
argument_list|)
operator|&
literal|15
operator|)
operator|!=
literal|0
operator|)
operator|&&
name|x
operator|<
name|width
condition|;
name|x
operator|++
control|)
block|{
name|uint32_t
name|rgba
init|=
name|source
index|[
name|x
index|]
decl_stmt|;
name|dest
index|[
name|x
index|]
operator|=
operator|(
name|ANGLE_ROTL
argument_list|(
name|rgba
argument_list|,
literal|16
argument_list|)
operator|&
literal|0x00ff00ff
operator|)
operator||
operator|(
name|rgba
operator|&
literal|0xff00ff00
operator|)
expr_stmt|;
block|}
for|for
control|(
init|;
name|x
operator|+
literal|3
operator|<
name|width
condition|;
name|x
operator|+=
literal|4
control|)
block|{
name|__m128i
name|sourceData
init|=
name|_mm_loadu_si128
argument_list|(
cast|reinterpret_cast
argument_list|<
specifier|const
name|__m128i
operator|*
argument_list|>
argument_list|(
operator|&
name|source
index|[
name|x
index|]
argument_list|)
argument_list|)
decl_stmt|;
comment|// Mask out g and a, which don't change
name|__m128i
name|gaComponents
init|=
name|_mm_andnot_si128
argument_list|(
name|brMask
argument_list|,
name|sourceData
argument_list|)
decl_stmt|;
comment|// Mask out b and r
name|__m128i
name|brComponents
init|=
name|_mm_and_si128
argument_list|(
name|sourceData
argument_list|,
name|brMask
argument_list|)
decl_stmt|;
comment|// Swap b and r
name|__m128i
name|brSwapped
init|=
name|_mm_shufflehi_epi16
argument_list|(
name|_mm_shufflelo_epi16
argument_list|(
name|brComponents
argument_list|,
name|_MM_SHUFFLE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
argument_list|,
name|_MM_SHUFFLE
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|__m128i
name|result
init|=
name|_mm_or_si128
argument_list|(
name|gaComponents
argument_list|,
name|brSwapped
argument_list|)
decl_stmt|;
name|_mm_store_si128
argument_list|(
cast|reinterpret_cast
argument_list|<
name|__m128i
operator|*
argument_list|>
argument_list|(
operator|&
name|dest
index|[
name|x
index|]
argument_list|)
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
comment|// Perform leftover writes
for|for
control|(
init|;
name|x
operator|<
name|width
condition|;
name|x
operator|++
control|)
block|{
name|uint32_t
name|rgba
init|=
name|source
index|[
name|x
index|]
decl_stmt|;
name|dest
index|[
name|x
index|]
operator|=
operator|(
name|ANGLE_ROTL
argument_list|(
name|rgba
argument_list|,
literal|16
argument_list|)
operator|&
literal|0x00ff00ff
operator|)
operator||
operator|(
name|rgba
operator|&
literal|0xff00ff00
operator|)
expr_stmt|;
block|}
block|}
block|}
else|#
directive|else
comment|// Ensure that this function is reported as not implemented for ARM builds because
comment|// the instructions below are not present for that architecture.
name|UNIMPLEMENTED
argument_list|()
expr_stmt|;
return|return;
endif|#
directive|endif
block|}
block|}
end_namespace
end_unit
