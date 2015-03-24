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
comment|/*    Adobe's CFF Interpreter (specification).                             */
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
name|__CF2INTRP_H__
end_ifndef
begin_define
DECL|macro|__CF2INTRP_H__
define|#
directive|define
name|__CF2INTRP_H__
end_define
begin_include
include|#
directive|include
file|"cf2ft.h"
end_include
begin_include
include|#
directive|include
file|"cf2hints.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|void
parameter_list|)
function_decl|cf2_hintmask_init
parameter_list|(
name|CF2_HintMask
name|hintmask
parameter_list|,
name|FT_Error
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|cf2_hintmask_isValid
argument_list|(
argument|const CF2_HintMask  hintmask
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
DECL|variable|cf2_hintmask_isNew
name|cf2_hintmask_isNew
argument_list|(
argument|const CF2_HintMask  hintmask
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_hintmask_isNew
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_hintmask_setNew
argument_list|(
argument|CF2_HintMask  hintmask
argument_list|,
argument|FT_Bool       val
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Byte*
argument_list|)
end_macro
begin_macro
DECL|variable|hintmask
name|cf2_hintmask_getMaskPtr
argument_list|(
argument|CF2_HintMask  hintmask
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|hintmask
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_hintmask_setAll
argument_list|(
argument|CF2_HintMask  hintmask
argument_list|,
argument|size_t        bitCount
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_interpT2CharString
argument_list|(
argument|CF2_Font              font
argument_list|,
argument|CF2_Buffer            charstring
argument_list|,
argument|CF2_OutlineCallbacks  callbacks
argument_list|,
argument|const FT_Vector*      translation
argument_list|,
argument|FT_Bool               doingSeac
argument_list|,
argument|CF2_Fixed             curX
argument_list|,
argument|CF2_Fixed             curY
argument_list|,
argument|CF2_Fixed*            width
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
comment|/* __CF2INTRP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
