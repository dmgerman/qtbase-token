begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QDRAWINGPRIMITIVE_SSE2_P_H
end_ifndef
begin_define
DECL|macro|QDRAWINGPRIMITIVE_SSE2_P_H
define|#
directive|define
name|QDRAWINGPRIMITIVE_SSE2_P_H
end_define
begin_include
include|#
directive|include
file|<private/qsimd_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__SSE2__
end_ifdef
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
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*  * Multiply the components of pixelVector by alphaChannel  * Each 32bits components of alphaChannel must be in the form 0x00AA00AA  * colorMask must have 0x00ff00ff on each 32 bits component  * half must have the value 128 (0x80) for each 32 bits compnent  */
DECL|macro|BYTE_MUL_SSE2
define|#
directive|define
name|BYTE_MUL_SSE2
parameter_list|(
name|result
parameter_list|,
name|pixelVector
parameter_list|,
name|alphaChannel
parameter_list|,
name|colorMask
parameter_list|,
name|half
parameter_list|)
define|\
value|{ \
comment|/* 1. separate the colors in 2 vectors so each color is on 16 bits \        (in order to be multiplied by the alpha \        each 32 bit of dstVectorAG are in the form 0x00AA00GG \        each 32 bit of dstVectorRB are in the form 0x00RR00BB */
value|\     __m128i pixelVectorAG = _mm_srli_epi16(pixelVector, 8); \     __m128i pixelVectorRB = _mm_and_si128(pixelVector, colorMask); \  \
comment|/* 2. multiply the vectors by the alpha channel */
value|\     pixelVectorAG = _mm_mullo_epi16(pixelVectorAG, alphaChannel); \     pixelVectorRB = _mm_mullo_epi16(pixelVectorRB, alphaChannel); \  \
comment|/* 3. divide by 255, that's the tricky part. \        we do it like for BYTE_MUL(), with bit shift: X/255 ~= (X + X/256 + rounding)/256 */
value|\
comment|/** so first (X + X/256 + rounding) */
value|\     pixelVectorRB = _mm_add_epi16(pixelVectorRB, _mm_srli_epi16(pixelVectorRB, 8)); \     pixelVectorRB = _mm_add_epi16(pixelVectorRB, half); \     pixelVectorAG = _mm_add_epi16(pixelVectorAG, _mm_srli_epi16(pixelVectorAG, 8)); \     pixelVectorAG = _mm_add_epi16(pixelVectorAG, half); \  \
comment|/** second divide by 256 */
value|\     pixelVectorRB = _mm_srli_epi16(pixelVectorRB, 8); \
comment|/** for AG, we could>> 8 to divide followed by<< 8 to put the \         bytes in the correct position. By masking instead, we execute \         only one instruction */
value|\     pixelVectorAG = _mm_andnot_si128(colorMask, pixelVectorAG); \  \
comment|/* 4. combine the 2 pairs of colors */
value|\     result = _mm_or_si128(pixelVectorAG, pixelVectorRB); \ }
comment|/*  * Each 32bits components of alphaChannel must be in the form 0x00AA00AA  * oneMinusAlphaChannel must be 255 - alpha for each 32 bits component  * colorMask must have 0x00ff00ff on each 32 bits component  * half must have the value 128 (0x80) for each 32 bits compnent  */
DECL|macro|INTERPOLATE_PIXEL_255_SSE2
define|#
directive|define
name|INTERPOLATE_PIXEL_255_SSE2
parameter_list|(
name|result
parameter_list|,
name|srcVector
parameter_list|,
name|dstVector
parameter_list|,
name|alphaChannel
parameter_list|,
name|oneMinusAlphaChannel
parameter_list|,
name|colorMask
parameter_list|,
name|half
parameter_list|)
value|{ \
comment|/* interpolate AG */
value|\     __m128i srcVectorAG = _mm_srli_epi16(srcVector, 8); \     __m128i dstVectorAG = _mm_srli_epi16(dstVector, 8); \     __m128i srcVectorAGalpha = _mm_mullo_epi16(srcVectorAG, alphaChannel); \     __m128i dstVectorAGoneMinusAlphalpha = _mm_mullo_epi16(dstVectorAG, oneMinusAlphaChannel); \     __m128i finalAG = _mm_add_epi16(srcVectorAGalpha, dstVectorAGoneMinusAlphalpha); \     finalAG = _mm_add_epi16(finalAG, _mm_srli_epi16(finalAG, 8)); \     finalAG = _mm_add_epi16(finalAG, half); \     finalAG = _mm_andnot_si128(colorMask, finalAG); \  \
comment|/* interpolate RB */
value|\     __m128i srcVectorRB = _mm_and_si128(srcVector, colorMask); \     __m128i dstVectorRB = _mm_and_si128(dstVector, colorMask); \     __m128i srcVectorRBalpha = _mm_mullo_epi16(srcVectorRB, alphaChannel); \     __m128i dstVectorRBoneMinusAlphalpha = _mm_mullo_epi16(dstVectorRB, oneMinusAlphaChannel); \     __m128i finalRB = _mm_add_epi16(srcVectorRBalpha, dstVectorRBoneMinusAlphalpha); \     finalRB = _mm_add_epi16(finalRB, _mm_srli_epi16(finalRB, 8)); \     finalRB = _mm_add_epi16(finalRB, half); \     finalRB = _mm_srli_epi16(finalRB, 8); \  \
comment|/* combine */
value|\     result = _mm_or_si128(finalAG, finalRB); \ }
comment|// same as BLEND_SOURCE_OVER_ARGB32_SSE2, but for one vector srcVector
DECL|macro|BLEND_SOURCE_OVER_ARGB32_SSE2_helper
define|#
directive|define
name|BLEND_SOURCE_OVER_ARGB32_SSE2_helper
parameter_list|(
name|dst
parameter_list|,
name|srcVector
parameter_list|,
name|nullVector
parameter_list|,
name|half
parameter_list|,
name|one
parameter_list|,
name|colorMask
parameter_list|,
name|alphaMask
parameter_list|)
value|{ \         const __m128i srcVectorAlpha = _mm_and_si128(srcVector, alphaMask); \         if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVectorAlpha, alphaMask)) == 0xffff) { \
comment|/* all opaque */
value|\             _mm_store_si128((__m128i *)&dst[x], srcVector); \         } else if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVectorAlpha, nullVector)) != 0xffff) { \
comment|/* not fully transparent */
value|\
comment|/* extract the alpha channel on 2 x 16 bits */
value|\
comment|/* so we have room for the multiplication */
value|\
comment|/* each 32 bits will be in the form 0x00AA00AA */
value|\
comment|/* with A being the 1 - alpha */
value|\             __m128i alphaChannel = _mm_srli_epi32(srcVector, 24); \             alphaChannel = _mm_or_si128(alphaChannel, _mm_slli_epi32(alphaChannel, 16)); \             alphaChannel = _mm_sub_epi16(one, alphaChannel); \  \             const __m128i dstVector = _mm_load_si128((__m128i *)&dst[x]); \             __m128i destMultipliedByOneMinusAlpha; \             BYTE_MUL_SSE2(destMultipliedByOneMinusAlpha, dstVector, alphaChannel, colorMask, half); \  \
comment|/* result = s + d * (1-alpha) */
value|\             const __m128i result = _mm_add_epi8(srcVector, destMultipliedByOneMinusAlpha); \             _mm_store_si128((__m128i *)&dst[x], result); \         } \     }
comment|// Basically blend src over dst with the const alpha defined as constAlphaVector.
comment|// nullVector, half, one, colorMask are constant across the whole image/texture, and should be defined as:
comment|//const __m128i nullVector = _mm_set1_epi32(0);
comment|//const __m128i half = _mm_set1_epi16(0x80);
comment|//const __m128i one = _mm_set1_epi16(0xff);
comment|//const __m128i colorMask = _mm_set1_epi32(0x00ff00ff);
comment|//const __m128i alphaMask = _mm_set1_epi32(0xff000000);
comment|//
comment|// The computation being done is:
comment|// result = s + d * (1-alpha)
comment|// with shortcuts if fully opaque or fully transparent.
DECL|macro|BLEND_SOURCE_OVER_ARGB32_SSE2
define|#
directive|define
name|BLEND_SOURCE_OVER_ARGB32_SSE2
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|length
parameter_list|,
name|nullVector
parameter_list|,
name|half
parameter_list|,
name|one
parameter_list|,
name|colorMask
parameter_list|,
name|alphaMask
parameter_list|)
value|{ \     int x = 0; \ \
comment|/* First, get dst aligned. */
value|\     ALIGNMENT_PROLOGUE_16BYTES(dst, x, length) { \         uint s = src[x]; \         if (s>= 0xff000000) \             dst[x] = s; \         else if (s != 0) \             dst[x] = s + BYTE_MUL(dst[x], qAlpha(~s)); \     } \ \     for (; x< length-3; x += 4) { \         const __m128i srcVector = _mm_loadu_si128((const __m128i *)&src[x]); \         BLEND_SOURCE_OVER_ARGB32_SSE2_helper(dst, srcVector, nullVector, half, one, colorMask, alphaMask) \     } \     for (; x< length; ++x) { \         uint s = src[x]; \         if (s>= 0xff000000) \             dst[x] = s; \         else if (s != 0) \             dst[x] = s + BYTE_MUL(dst[x], qAlpha(~s)); \     } \ }
comment|// Basically blend src over dst with the const alpha defined as constAlphaVector.
comment|// nullVector, half, one, colorMask are constant across the whole image/texture, and should be defined as:
comment|//const __m128i nullVector = _mm_set1_epi32(0);
comment|//const __m128i half = _mm_set1_epi16(0x80);
comment|//const __m128i one = _mm_set1_epi16(0xff);
comment|//const __m128i colorMask = _mm_set1_epi32(0x00ff00ff);
comment|//
comment|// The computation being done is:
comment|// dest = (s + d * sia) * ca + d * cia
comment|//      = s * ca + d * (sia * ca + cia)
comment|//      = s * ca + d * (1 - sa*ca)
DECL|macro|BLEND_SOURCE_OVER_ARGB32_WITH_CONST_ALPHA_SSE2
define|#
directive|define
name|BLEND_SOURCE_OVER_ARGB32_WITH_CONST_ALPHA_SSE2
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|length
parameter_list|,
name|nullVector
parameter_list|,
name|half
parameter_list|,
name|one
parameter_list|,
name|colorMask
parameter_list|,
name|constAlphaVector
parameter_list|)
define|\
value|{ \     int x = 0; \ \     ALIGNMENT_PROLOGUE_16BYTES(dst, x, length) { \         quint32 s = src[x]; \         if (s != 0) { \             s = BYTE_MUL(s, const_alpha); \             dst[x] = s + BYTE_MUL(dst[x], qAlpha(~s)); \         } \     } \ \     for (; x< length-3; x += 4) { \         __m128i srcVector = _mm_loadu_si128((const __m128i *)&src[x]); \         if (_mm_movemask_epi8(_mm_cmpeq_epi32(srcVector, nullVector)) != 0xffff) { \             BYTE_MUL_SSE2(srcVector, srcVector, constAlphaVector, colorMask, half); \ \             __m128i alphaChannel = _mm_srli_epi32(srcVector, 24); \             alphaChannel = _mm_or_si128(alphaChannel, _mm_slli_epi32(alphaChannel, 16)); \             alphaChannel = _mm_sub_epi16(one, alphaChannel); \  \             const __m128i dstVector = _mm_load_si128((__m128i *)&dst[x]); \             __m128i destMultipliedByOneMinusAlpha; \             BYTE_MUL_SSE2(destMultipliedByOneMinusAlpha, dstVector, alphaChannel, colorMask, half); \  \             const __m128i result = _mm_add_epi8(srcVector, destMultipliedByOneMinusAlpha); \             _mm_store_si128((__m128i *)&dst[x], result); \         } \     } \     for (; x< length; ++x) { \         quint32 s = src[x]; \         if (s != 0) { \             s = BYTE_MUL(s, const_alpha); \             dst[x] = s + BYTE_MUL(dst[x], qAlpha(~s)); \         } \     } \ }
name|QT_END_NAMESPACE
endif|#
directive|endif
comment|// __SSE2__
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|QT_COMPILER_SUPPORTS_HERE
argument_list|(
name|SSE4_1
argument_list|)
DECL|function|QT_FUNCTION_TARGET
name|QT_FUNCTION_TARGET
argument_list|(
name|SSE4_1
argument_list|)
specifier|inline
namespace|QRgb
name|qUnpremultiply_sse4
namespace|(
name|QRgb
name|p
decl_stmt|)
block|{
specifier|const
name|uint
name|alpha
init|=
name|qAlpha
argument_list|(
name|p
argument_list|)
decl_stmt|;
specifier|const
name|uint
name|invAlpha
init|=
name|qt_inv_premul_factor
index|[
name|alpha
index|]
decl_stmt|;
specifier|const
name|__m128i
name|via
init|=
name|_mm_set1_epi32
argument_list|(
name|invAlpha
argument_list|)
decl_stmt|;
specifier|const
name|__m128i
name|vr
init|=
name|_mm_set1_epi32
argument_list|(
literal|0x8000
argument_list|)
decl_stmt|;
name|__m128i
name|vl
init|=
name|_mm_cvtepu8_epi32
argument_list|(
name|_mm_cvtsi32_si128
argument_list|(
name|p
argument_list|)
argument_list|)
decl_stmt|;
name|vl
operator|=
name|_mm_mullo_epi32
argument_list|(
name|vl
argument_list|,
name|via
argument_list|)
expr_stmt|;
name|vl
operator|=
name|_mm_add_epi32
argument_list|(
name|vl
argument_list|,
name|vr
argument_list|)
expr_stmt|;
name|vl
operator|=
name|_mm_srai_epi32
argument_list|(
name|vl
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|vl
operator|=
name|_mm_insert_epi32
argument_list|(
name|vl
argument_list|,
name|alpha
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|vl
operator|=
name|_mm_packus_epi32
argument_list|(
name|vl
argument_list|,
name|_mm_setzero_si128
argument_list|()
argument_list|)
expr_stmt|;
name|vl
operator|=
name|_mm_packus_epi16
argument_list|(
name|vl
argument_list|,
name|_mm_setzero_si128
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|_mm_cvtsi128_si32
argument_list|(
name|vl
argument_list|)
return|;
block|}
end_decl_stmt
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
begin_comment
comment|// QDRAWINGPRIMITIVE_SSE2_P_H
end_comment
end_unit
