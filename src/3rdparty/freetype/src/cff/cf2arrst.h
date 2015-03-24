begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2arrst.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for Array Stacks (specification).                       */
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
name|__CF2ARRST_H__
end_ifndef
begin_define
DECL|macro|__CF2ARRST_H__
define|#
directive|define
name|__CF2ARRST_H__
end_define
begin_include
include|#
directive|include
file|"cf2error.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* need to define the struct here (not opaque) so it can be allocated by */
end_comment
begin_comment
comment|/* clients                                                               */
end_comment
begin_typedef
DECL|struct|CF2_ArrStackRec_
typedef|typedef
struct|struct
name|CF2_ArrStackRec_
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
DECL|member|sizeItem
name|size_t
name|sizeItem
decl_stmt|;
comment|/* bytes per element             */
DECL|member|allocated
name|size_t
name|allocated
decl_stmt|;
comment|/* items allocated               */
DECL|member|chunk
name|size_t
name|chunk
decl_stmt|;
comment|/* allocation increment in items */
DECL|member|count
name|size_t
name|count
decl_stmt|;
comment|/* number of elements allocated  */
DECL|member|totalSize
name|size_t
name|totalSize
decl_stmt|;
comment|/* total bytes allocated         */
DECL|member|ptr
name|void
modifier|*
name|ptr
decl_stmt|;
comment|/* ptr to data                   */
block|}
DECL|typedef|CF2_ArrStackRec
DECL|typedef|CF2_ArrStack
name|CF2_ArrStackRec
operator|,
typedef|*
name|CF2_ArrStack
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_arrstack_init
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|,
argument|FT_Memory     memory
argument_list|,
argument|FT_Error*     error
argument_list|,
argument|size_t        sizeItem
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
DECL|variable|arrstack
name|cf2_arrstack_finalize
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|arrstack
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|cf2_arrstack_setCount
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|,
argument|size_t        numElements
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
DECL|variable|arrstack
name|cf2_arrstack_clear
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|arrstack
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|size_t
argument_list|)
end_macro
begin_macro
name|cf2_arrstack_size
argument_list|(
argument|const CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
DECL|variable|cf2_arrstack_getBuffer
name|cf2_arrstack_getBuffer
argument_list|(
argument|const CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cf2_arrstack_getBuffer
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
name|cf2_arrstack_getPointer
argument_list|(
argument|const CF2_ArrStack  arrstack
argument_list|,
argument|size_t              idx
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
name|cf2_arrstack_push
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|,
argument|const void*   ptr
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
comment|/* __CF2ARRST_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
