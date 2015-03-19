begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2read.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for stream handling (body).                             */
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
begin_include
include|#
directive|include
file|"cf2ft.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
file|"cf2glue.h"
end_include
begin_include
include|#
directive|include
file|"cf2error.h"
end_include
begin_comment
comment|/* Define CF2_IO_FAIL as 1 to enable random errors and random */
end_comment
begin_comment
comment|/* value errors in I/O.                                       */
end_comment
begin_define
DECL|macro|CF2_IO_FAIL
define|#
directive|define
name|CF2_IO_FAIL
value|0
end_define
begin_if
if|#
directive|if
name|CF2_IO_FAIL
end_if
begin_comment
comment|/* set the .00 value to a nonzero probability */
end_comment
begin_function
specifier|static
name|int
DECL|function|randomError2
name|randomError2
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* for region buffer ReadByte (interp) function */
return|return
operator|(
name|double
operator|)
name|rand
argument_list|()
operator|/
name|RAND_MAX
operator|<
literal|.00
return|;
block|}
end_function
begin_comment
comment|/* set the .00 value to a nonzero probability */
end_comment
begin_function
specifier|static
name|CF2_Int
DECL|function|randomValue
name|randomValue
parameter_list|()
block|{
return|return
operator|(
name|double
operator|)
name|rand
argument_list|()
operator|/
name|RAND_MAX
operator|<
literal|.00
condition|?
name|rand
argument_list|()
else|:
literal|0
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* CF2_IO_FAIL */
end_comment
begin_comment
comment|/* Region Buffer                                      */
end_comment
begin_comment
comment|/*                                                    */
end_comment
begin_comment
comment|/* Can be constructed from a copied buffer managed by */
end_comment
begin_comment
comment|/* `FCM_getDatablock'.                                */
end_comment
begin_comment
comment|/* Reads bytes with check for end of buffer.          */
end_comment
begin_comment
comment|/* reading past the end of the buffer sets error and returns zero */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|CF2_Int
argument_list|)
end_macro
begin_macro
name|cf2_buf_readByte
argument_list|(
argument|CF2_Buffer  buf
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|buf
operator|->
name|ptr
operator|<
name|buf
operator|->
name|end
condition|)
block|{
if|#
directive|if
name|CF2_IO_FAIL
if|if
condition|(
name|randomError2
argument_list|()
condition|)
block|{
name|CF2_SET_ERROR
argument_list|(
name|buf
operator|->
name|error
argument_list|,
name|Invalid_Stream_Operation
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
return|return
operator|*
operator|(
name|buf
operator|->
name|ptr
operator|)
operator|++
operator|+
name|randomValue
argument_list|()
return|;
else|#
directive|else
return|return
operator|*
operator|(
name|buf
operator|->
name|ptr
operator|)
operator|++
return|;
endif|#
directive|endif
block|}
else|else
block|{
name|CF2_SET_ERROR
argument_list|(
name|buf
operator|->
name|error
argument_list|,
name|Invalid_Stream_Operation
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_block
begin_comment
comment|/* note: end condition can occur without error */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|cf2_buf_isEnd
argument_list|(
argument|CF2_Buffer  buf
argument_list|)
end_macro
begin_block
block|{
return|return
call|(
name|FT_Bool
call|)
argument_list|(
name|buf
operator|->
name|ptr
operator|>=
name|buf
operator|->
name|end
argument_list|)
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
