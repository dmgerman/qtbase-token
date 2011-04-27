begin_unit
begin_comment
comment|/*  * jmemnobs.c  *  * Copyright (C) 1992-1996, Thomas G. Lane.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file provides a really simple implementation of the system-  * dependent portion of the JPEG memory manager.  This implementation  * assumes that no backing-store files are needed: all required space  * can be obtained from malloc().  * This is very portable in the sense that it'll compile on almost anything,  * but you'd better have lots of main memory (or virtual memory) if you want  * to process big images.  * Note that the max_memory_to_use option is ignored by this implementation.  */
end_comment
begin_define
DECL|macro|JPEG_INTERNALS
define|#
directive|define
name|JPEG_INTERNALS
end_define
begin_include
include|#
directive|include
file|"jinclude.h"
end_include
begin_include
include|#
directive|include
file|"jpeglib.h"
end_include
begin_include
include|#
directive|include
file|"jmemsys.h"
end_include
begin_comment
comment|/* import the system-dependent declarations */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STDLIB_H
end_ifndef
begin_comment
comment|/*<stdlib.h> should declare malloc(),free() */
end_comment
begin_decl_stmt
specifier|extern
name|void
modifier|*
name|malloc
name|JPP
argument_list|(
operator|(
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_decl_stmt
specifier|extern
name|void
name|free
name|JPP
argument_list|(
operator|(
name|void
operator|*
name|ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*  * Memory allocation and freeing are controlled by the regular library  * routines malloc() and free().  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void *
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_get_small
name|jpeg_get_small
argument_list|(
argument|j_common_ptr cinfo
argument_list|,
argument|size_t sizeofobject
argument_list|)
end_macro
begin_block
block|{
return|return
operator|(
name|void
operator|*
operator|)
name|malloc
argument_list|(
name|sizeofobject
argument_list|)
return|;
block|}
end_block
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_free_small
name|jpeg_free_small
argument_list|(
argument|j_common_ptr cinfo
argument_list|,
argument|void * object
argument_list|,
argument|size_t sizeofobject
argument_list|)
end_macro
begin_block
block|{
name|free
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * "Large" objects are treated the same as "small" ones.  * NB: although we include FAR keywords in the routine declarations,  * this file won't actually work in 80x86 small/medium model; at least,  * you probably won't be able to process useful-size images in only 64KB.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void FAR *
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_get_large
name|jpeg_get_large
argument_list|(
argument|j_common_ptr cinfo
argument_list|,
argument|size_t sizeofobject
argument_list|)
end_macro
begin_block
block|{
return|return
operator|(
name|void
name|FAR
operator|*
operator|)
name|malloc
argument_list|(
name|sizeofobject
argument_list|)
return|;
block|}
end_block
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_free_large
name|jpeg_free_large
argument_list|(
argument|j_common_ptr cinfo
argument_list|,
argument|void FAR * object
argument_list|,
argument|size_t sizeofobject
argument_list|)
end_macro
begin_block
block|{
name|free
argument_list|(
name|object
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * This routine computes the total memory space available for allocation.  * Here we always say, "we got all you want bud!"  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|long
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_mem_available
name|jpeg_mem_available
argument_list|(
argument|j_common_ptr cinfo
argument_list|,
argument|long min_bytes_needed
argument_list|,
argument|long max_bytes_needed
argument_list|,
argument|long already_allocated
argument_list|)
end_macro
begin_block
block|{
return|return
name|max_bytes_needed
return|;
block|}
end_block
begin_comment
comment|/*  * Backing store (temporary file) management.  * Since jpeg_mem_available always promised the moon,  * this should never be called and we can just error out.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_open_backing_store
name|jpeg_open_backing_store
argument_list|(
argument|j_common_ptr cinfo
argument_list|,
argument|backing_store_ptr info
argument_list|,
argument|long total_bytes_needed
argument_list|)
end_macro
begin_block
block|{
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_NO_BACKING_STORE
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * These routines take care of any system-dependent initialization and  * cleanup required.  Here, there isn't any.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|long
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_mem_init
name|jpeg_mem_init
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
return|return
literal|0
return|;
comment|/* just set max_memory_to_use to 0 */
block|}
end_block
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jpeg_mem_term
name|jpeg_mem_term
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* no work */
block|}
end_block
end_unit
