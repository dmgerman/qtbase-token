begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2font.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for font instances (specification).                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007-2013 Adobe Systems Incorporated.                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This software, and all works of authorship, whether in source or       */
end_comment
begin_comment
comment|/*  object code form as indicated by the copyright notice(s) included      */
end_comment
begin_comment
comment|/*  herein (collectively, the "Work") is made available, and may only be   */
end_comment
begin_comment
comment|/*  used, modified, and distributed under the FreeType Project License,    */
end_comment
begin_comment
comment|/*  LICENSE.TXT.  Additionally, subject to the terms and conditions of the */
end_comment
begin_comment
comment|/*  FreeType Project License, each contributor to the Work hereby grants   */
end_comment
begin_comment
comment|/*  to any individual or legal entity exercising permissions granted by    */
end_comment
begin_comment
comment|/*  the FreeType Project License and this section (hereafter, "You" or     */
end_comment
begin_comment
comment|/*  "Your") a perpetual, worldwide, non-exclusive, no-charge,              */
end_comment
begin_comment
comment|/*  royalty-free, irrevocable (except as stated in this section) patent    */
end_comment
begin_comment
comment|/*  license to make, have made, use, offer to sell, sell, import, and      */
end_comment
begin_comment
comment|/*  otherwise transfer the Work, where such license applies only to those  */
end_comment
begin_comment
comment|/*  patent claims licensable by such contributor that are necessarily      */
end_comment
begin_comment
comment|/*  infringed by their contribution(s) alone or by combination of their    */
end_comment
begin_comment
comment|/*  contribution(s) with the Work to which such contribution(s) was        */
end_comment
begin_comment
comment|/*  submitted.  If You institute patent litigation against any entity      */
end_comment
begin_comment
comment|/*  (including a cross-claim or counterclaim in a lawsuit) alleging that   */
end_comment
begin_comment
comment|/*  the Work or a contribution incorporated within the Work constitutes    */
end_comment
begin_comment
comment|/*  direct or contributory patent infringement, then any patent licenses   */
end_comment
begin_comment
comment|/*  granted to You under this License for that Work shall terminate as of  */
end_comment
begin_comment
comment|/*  the date such litigation is filed.                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  By using, modifying, or distributing the Work you indicate that you    */
end_comment
begin_comment
comment|/*  have read and understood the terms and conditions of the               */
end_comment
begin_comment
comment|/*  FreeType Project License as well as those provided in this section,    */
end_comment
begin_comment
comment|/*  and you accept them fully.                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__CF2FONT_H__
end_ifndef
begin_define
DECL|macro|__CF2FONT_H__
define|#
directive|define
name|__CF2FONT_H__
end_define
begin_include
include|#
directive|include
file|"cf2ft.h"
end_include
begin_include
include|#
directive|include
file|"cf2blues.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|CF2_OPERAND_STACK_SIZE
define|#
directive|define
name|CF2_OPERAND_STACK_SIZE
value|48
end_define
begin_define
DECL|macro|CF2_MAX_SUBR
define|#
directive|define
name|CF2_MAX_SUBR
value|10
end_define
begin_comment
DECL|macro|CF2_MAX_SUBR
comment|/* maximum subroutine nesting */
end_comment
begin_comment
comment|/* typedef is in `cf2glue.h' */
end_comment
begin_struct
DECL|struct|CF2_FontRec_
struct|struct
name|CF2_FontRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|error
name|FT_Error
name|error
decl_stmt|;
comment|/* shared error for this instance */
DECL|member|renderingFlags
name|CF2_RenderingFlags
name|renderingFlags
decl_stmt|;
comment|/* variables that depend on Transform:  */
comment|/* the following have zero translation; */
comment|/* inner * outer = font * original      */
DECL|member|currentTransform
name|CF2_Matrix
name|currentTransform
decl_stmt|;
comment|/* original client matrix           */
DECL|member|innerTransform
name|CF2_Matrix
name|innerTransform
decl_stmt|;
comment|/* for hinting; erect, scaled       */
DECL|member|outerTransform
name|CF2_Matrix
name|outerTransform
decl_stmt|;
comment|/* post hinting; includes rotations */
DECL|member|ppem
name|CF2_Fixed
name|ppem
decl_stmt|;
comment|/* transform-dependent              */
DECL|member|unitsPerEm
name|CF2_Int
name|unitsPerEm
decl_stmt|;
DECL|member|syntheticEmboldeningAmountX
name|CF2_Fixed
name|syntheticEmboldeningAmountX
decl_stmt|;
comment|/* character space units */
DECL|member|syntheticEmboldeningAmountY
name|CF2_Fixed
name|syntheticEmboldeningAmountY
decl_stmt|;
comment|/* character space units */
comment|/* FreeType related members */
DECL|member|outline
name|CF2_OutlineRec
name|outline
decl_stmt|;
comment|/* freetype glyph outline functions */
DECL|member|decoder
name|CFF_Decoder
modifier|*
name|decoder
decl_stmt|;
DECL|member|lastSubfont
name|CFF_SubFont
name|lastSubfont
decl_stmt|;
comment|/* FreeType parsed data; */
comment|/* top font or subfont   */
comment|/* these flags can vary from one call to the next */
DECL|member|hinted
name|FT_Bool
name|hinted
decl_stmt|;
DECL|member|darkened
name|FT_Bool
name|darkened
decl_stmt|;
comment|/* true if stemDarkened or synthetic bold */
comment|/* i.e. darkenX != 0 || darkenY != 0      */
DECL|member|stemDarkened
name|FT_Bool
name|stemDarkened
decl_stmt|;
DECL|member|darkenParams
name|FT_Int
name|darkenParams
index|[
literal|8
index|]
decl_stmt|;
comment|/* 1000 unit character space */
comment|/* variables that depend on both FontDict and Transform */
DECL|member|stdVW
name|CF2_Fixed
name|stdVW
decl_stmt|;
comment|/* in character space; depends on dict entry */
DECL|member|stdHW
name|CF2_Fixed
name|stdHW
decl_stmt|;
comment|/* in character space; depends on dict entry */
DECL|member|darkenX
name|CF2_Fixed
name|darkenX
decl_stmt|;
comment|/* character space units    */
DECL|member|darkenY
name|CF2_Fixed
name|darkenY
decl_stmt|;
comment|/* depends on transform     */
comment|/* and private dict (StdVW) */
DECL|member|reverseWinding
name|FT_Bool
name|reverseWinding
decl_stmt|;
comment|/* darken assuming          */
comment|/* counterclockwise winding */
DECL|member|blues
name|CF2_BluesRec
name|blues
decl_stmt|;
comment|/* computed zone data */
block|}
struct|;
end_struct
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cf2_getGlyphOutline
argument_list|(
argument|CF2_Font           font
argument_list|,
argument|CF2_Buffer         charstring
argument_list|,
argument|const CF2_Matrix*  transform
argument_list|,
argument|CF2_F16Dot16*      glyphWidth
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CF2FONT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
