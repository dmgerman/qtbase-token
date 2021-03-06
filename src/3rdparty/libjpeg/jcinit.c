begin_unit
begin_comment
comment|/*  * jcinit.c  *  * Copyright (C) 1991-1997, Thomas G. Lane.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains initialization logic for the JPEG compressor.  * This routine is in charge of selecting the modules to be executed and  * making an initialization call to each one.  *  * Logically, this code belongs in jcmaster.c.  It's split out because  * linking this routine implies linking the entire compression library.  * For a transcoding-only application, we want to be able to use jcmaster.c  * without linking in the whole library.  */
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
begin_comment
comment|/*  * Master selection of compression modules.  * This is done once at the start of processing an image.  We determine  * which modules will be used and give them appropriate initialization calls.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jinit_compress_master
name|jinit_compress_master
argument_list|(
argument|j_compress_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* Initialize master control (includes parameter checking/processing) */
name|jinit_c_master_control
argument_list|(
name|cinfo
argument_list|,
name|FALSE
comment|/* full compression */
argument_list|)
expr_stmt|;
comment|/* Preprocessing */
if|if
condition|(
operator|!
name|cinfo
operator|->
name|raw_data_in
condition|)
block|{
name|jinit_color_converter
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
name|jinit_downsampler
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
name|jinit_c_prep_controller
argument_list|(
name|cinfo
argument_list|,
name|FALSE
comment|/* never need full buffer here */
argument_list|)
expr_stmt|;
block|}
comment|/* Forward DCT */
name|jinit_forward_dct
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Entropy encoding: either Huffman or arithmetic coding. */
if|if
condition|(
name|cinfo
operator|->
name|arith_code
condition|)
name|jinit_arith_encoder
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
else|else
block|{
name|jinit_huff_encoder
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
comment|/* Need a full-image coefficient buffer in any multi-pass mode. */
name|jinit_c_coef_controller
argument_list|(
name|cinfo
argument_list|,
call|(
name|boolean
call|)
argument_list|(
name|cinfo
operator|->
name|num_scans
operator|>
literal|1
operator|||
name|cinfo
operator|->
name|optimize_coding
argument_list|)
argument_list|)
expr_stmt|;
name|jinit_c_main_controller
argument_list|(
name|cinfo
argument_list|,
name|FALSE
comment|/* never need full buffer here */
argument_list|)
expr_stmt|;
name|jinit_marker_writer
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* We can now tell the memory manager to allocate virtual arrays. */
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|realize_virt_arrays
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Write the datastream header (SOI) immediately.    * Frame and scan headers are postponed till later.    * This lets application insert special markers after the SOI.    */
call|(
modifier|*
name|cinfo
operator|->
name|marker
operator|->
name|write_file_header
call|)
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
block|}
end_block
end_unit
