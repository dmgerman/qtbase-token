begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2stack.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for emulating a CFF stack (specification).              */
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
name|__CF2STACK_H__
end_ifndef
begin_define
DECL|macro|__CF2STACK_H__
define|#
directive|define
name|__CF2STACK_H__
end_define
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* CFF operand stack; specified maximum of 48 or 192 values */
end_comment
begin_typedef
DECL|struct|CF2_StackNumber_
typedef|typedef
struct|struct
name|CF2_StackNumber_
block|{
union|union
block|{
DECL|member|r
name|CF2_Fixed
name|r
decl_stmt|;
comment|/* 16.16 fixed point */
DECL|member|f
name|CF2_Frac
name|f
decl_stmt|;
comment|/* 2.30 fixed point (for font matrix) */
DECL|member|i
name|CF2_Int
name|i
decl_stmt|;
block|}
DECL|member|u
name|u
union|;
DECL|member|type
name|CF2_NumberType
name|type
decl_stmt|;
block|}
DECL|typedef|CF2_StackNumber
name|CF2_StackNumber
typedef|;
end_typedef
begin_typedef
DECL|struct|CF2_StackRec_
typedef|typedef
struct|struct
name|CF2_StackRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|error
name|FT_Error
modifier|*
name|error
decl_stmt|;
DECL|member|buffer
name|CF2_StackNumber
name|buffer
index|[
name|CF2_OPERAND_STACK_SIZE
index|]
decl_stmt|;
DECL|member|top
name|CF2_StackNumber
modifier|*
name|top
decl_stmt|;
block|}
DECL|typedef|CF2_StackRec
DECL|typedef|CF2_Stack
name|CF2_StackRec
operator|,
typedef|*
name|CF2_Stack
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Stack
argument_list|)
end_macro
begin_macro
name|cf2_stack_init
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_Error*  error
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
DECL|variable|cf2_stack_free
name|cf2_stack_free
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_stack_free
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_UInt
argument_list|)
end_macro
begin_macro
name|cf2_stack_count
argument_list|(
argument|CF2_Stack  stack
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
DECL|variable|cf2_stack_pushInt
name|cf2_stack_pushInt
argument_list|(
argument|CF2_Stack  stack
argument_list|,
argument|CF2_Int    val
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
name|cf2_stack_pushFixed
argument_list|(
argument|CF2_Stack  stack
argument_list|,
argument|CF2_Fixed  val
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Int
argument_list|)
end_macro
begin_macro
name|cf2_stack_popInt
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_macro
DECL|variable|cf2_stack_popFixed
name|cf2_stack_popFixed
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_stack_popFixed
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|CF2_Fixed
argument_list|)
end_macro
begin_macro
name|cf2_stack_getReal
argument_list|(
argument|CF2_Stack  stack
argument_list|,
argument|CF2_UInt   idx
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
DECL|variable|cf2_stack_clear
name|cf2_stack_clear
argument_list|(
argument|CF2_Stack  stack
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_stack_clear
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
comment|/* __CF2STACK_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
