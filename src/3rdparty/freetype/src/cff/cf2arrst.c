begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cf2arrst.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Adobe's code for Array Stacks (body).                                */
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
file|"cf2arrst.h"
end_include
begin_include
include|#
directive|include
file|"cf2error.h"
end_include
begin_comment
comment|/*    * CF2_ArrStack uses an error pointer, to enable shared errors.    * Shared errors are necessary when multiple objects allow the program    * to continue after detecting errors.  Only the first error should be    * recorded.    */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_init
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
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* initialize the structure */
name|arrstack
operator|->
name|memory
operator|=
name|memory
expr_stmt|;
name|arrstack
operator|->
name|error
operator|=
name|error
expr_stmt|;
name|arrstack
operator|->
name|sizeItem
operator|=
name|sizeItem
expr_stmt|;
name|arrstack
operator|->
name|allocated
operator|=
literal|0
expr_stmt|;
name|arrstack
operator|->
name|chunk
operator|=
literal|10
expr_stmt|;
comment|/* chunks of 10 items */
name|arrstack
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|arrstack
operator|->
name|totalSize
operator|=
literal|0
expr_stmt|;
name|arrstack
operator|->
name|ptr
operator|=
name|NULL
expr_stmt|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_finalize
name|cf2_arrstack_finalize
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_block
block|{
name|FT_Memory
name|memory
init|=
name|arrstack
operator|->
name|memory
decl_stmt|;
comment|/* for FT_FREE */
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|arrstack
operator|->
name|allocated
operator|=
literal|0
expr_stmt|;
name|arrstack
operator|->
name|count
operator|=
literal|0
expr_stmt|;
name|arrstack
operator|->
name|totalSize
operator|=
literal|0
expr_stmt|;
comment|/* free the data buffer */
name|FT_FREE
argument_list|(
name|arrstack
operator|->
name|ptr
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/* allocate or reallocate the buffer size; */
end_comment
begin_comment
comment|/* return false on memory error */
end_comment
begin_function
specifier|static
name|FT_Bool
DECL|function|cf2_arrstack_setNumElements
name|cf2_arrstack_setNumElements
parameter_list|(
name|CF2_ArrStack
name|arrstack
parameter_list|,
name|size_t
name|numElements
parameter_list|)
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
comment|/* for FT_REALLOC */
name|FT_Memory
name|memory
init|=
name|arrstack
operator|->
name|memory
decl_stmt|;
comment|/* for FT_REALLOC */
name|size_t
name|newSize
init|=
name|numElements
operator|*
name|arrstack
operator|->
name|sizeItem
decl_stmt|;
if|if
condition|(
name|numElements
operator|>
name|FT_LONG_MAX
operator|/
name|arrstack
operator|->
name|sizeItem
condition|)
goto|goto
name|exit
goto|;
name|FT_ASSERT
argument_list|(
name|newSize
operator|>
literal|0
argument_list|)
expr_stmt|;
comment|/* avoid realloc with zero size */
if|if
condition|(
operator|!
name|FT_REALLOC
argument_list|(
name|arrstack
operator|->
name|ptr
argument_list|,
name|arrstack
operator|->
name|totalSize
argument_list|,
name|newSize
argument_list|)
condition|)
block|{
name|arrstack
operator|->
name|allocated
operator|=
name|numElements
expr_stmt|;
name|arrstack
operator|->
name|totalSize
operator|=
name|newSize
expr_stmt|;
if|if
condition|(
name|arrstack
operator|->
name|count
operator|>
name|numElements
condition|)
block|{
comment|/* we truncated the list! */
name|CF2_SET_ERROR
argument_list|(
name|arrstack
operator|->
name|error
argument_list|,
name|Stack_Overflow
argument_list|)
expr_stmt|;
name|arrstack
operator|->
name|count
operator|=
name|numElements
expr_stmt|;
return|return
name|FALSE
return|;
block|}
return|return
name|TRUE
return|;
comment|/* success */
block|}
block|}
name|exit
label|:
comment|/* if there's not already an error, store this one */
name|CF2_SET_ERROR
argument_list|(
name|arrstack
operator|->
name|error
argument_list|,
name|Out_Of_Memory
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
end_function
begin_comment
comment|/* set the count, ensuring allocation is sufficient */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_setCount
name|cf2_arrstack_setCount
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|,
argument|size_t        numElements
argument_list|)
end_macro
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|numElements
operator|>
name|arrstack
operator|->
name|allocated
condition|)
block|{
comment|/* expand the allocation first */
if|if
condition|(
operator|!
name|cf2_arrstack_setNumElements
argument_list|(
name|arrstack
argument_list|,
name|numElements
argument_list|)
condition|)
return|return;
block|}
name|arrstack
operator|->
name|count
operator|=
name|numElements
expr_stmt|;
block|}
end_block
begin_comment
comment|/* clear the count */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_clear
name|cf2_arrstack_clear
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|arrstack
operator|->
name|count
operator|=
literal|0
expr_stmt|;
block|}
end_block
begin_comment
comment|/* current number of items */
end_comment
begin_macro
DECL|function|FT_LOCAL_DEF
name|FT_LOCAL_DEF
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
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|arrstack
operator|->
name|count
return|;
block|}
end_block
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_getBuffer
name|cf2_arrstack_getBuffer
argument_list|(
argument|const CF2_ArrStack  arrstack
argument_list|)
end_macro
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
return|return
name|arrstack
operator|->
name|ptr
return|;
block|}
end_block
begin_comment
comment|/* return pointer to the given element */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_getPointer
name|cf2_arrstack_getPointer
argument_list|(
argument|const CF2_ArrStack  arrstack
argument_list|,
argument|size_t              idx
argument_list|)
end_macro
begin_block
block|{
name|void
modifier|*
name|newPtr
decl_stmt|;
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|idx
operator|>=
name|arrstack
operator|->
name|count
condition|)
block|{
comment|/* overflow */
name|CF2_SET_ERROR
argument_list|(
name|arrstack
operator|->
name|error
argument_list|,
name|Stack_Overflow
argument_list|)
expr_stmt|;
name|idx
operator|=
literal|0
expr_stmt|;
comment|/* choose safe default */
block|}
name|newPtr
operator|=
operator|(
name|FT_Byte
operator|*
operator|)
name|arrstack
operator|->
name|ptr
operator|+
name|idx
operator|*
name|arrstack
operator|->
name|sizeItem
expr_stmt|;
return|return
name|newPtr
return|;
block|}
end_block
begin_comment
comment|/* push (append) an element at the end of the list;         */
end_comment
begin_comment
comment|/* return false on memory error                             */
end_comment
begin_comment
comment|/* TODO: should there be a length param for extra checking? */
end_comment
begin_macro
name|FT_LOCAL_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|cf2_arrstack_push
name|cf2_arrstack_push
argument_list|(
argument|CF2_ArrStack  arrstack
argument_list|,
argument|const void*   ptr
argument_list|)
end_macro
begin_block
block|{
name|FT_ASSERT
argument_list|(
name|arrstack
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|arrstack
operator|->
name|count
operator|==
name|arrstack
operator|->
name|allocated
condition|)
block|{
comment|/* grow the buffer by one chunk */
if|if
condition|(
operator|!
name|cf2_arrstack_setNumElements
argument_list|(
name|arrstack
argument_list|,
name|arrstack
operator|->
name|allocated
operator|+
name|arrstack
operator|->
name|chunk
argument_list|)
condition|)
block|{
comment|/* on error, ignore the push */
return|return;
block|}
block|}
name|FT_ASSERT
argument_list|(
name|ptr
operator|!=
name|NULL
argument_list|)
expr_stmt|;
block|{
name|size_t
name|offset
init|=
name|arrstack
operator|->
name|count
operator|*
name|arrstack
operator|->
name|sizeItem
decl_stmt|;
name|void
modifier|*
name|newPtr
init|=
operator|(
name|FT_Byte
operator|*
operator|)
name|arrstack
operator|->
name|ptr
operator|+
name|offset
decl_stmt|;
name|FT_MEM_COPY
argument_list|(
name|newPtr
argument_list|,
name|ptr
argument_list|,
name|arrstack
operator|->
name|sizeItem
argument_list|)
expr_stmt|;
name|arrstack
operator|->
name|count
operator|+=
literal|1
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
