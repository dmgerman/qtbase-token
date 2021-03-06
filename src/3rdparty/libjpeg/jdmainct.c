begin_unit
begin_comment
comment|/*  * jdmainct.c  *  * Copyright (C) 1994-1996, Thomas G. Lane.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file contains the main buffer controller for decompression.  * The main buffer lies between the JPEG decompressor proper and the  * post-processor; it holds downsampled data in the JPEG colorspace.  *  * Note that this code is bypassed in raw-data mode, since the application  * supplies the equivalent of the main buffer in that case.  */
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
comment|/*  * In the current system design, the main buffer need never be a full-image  * buffer; any full-height buffers will be found inside the coefficient or  * postprocessing controllers.  Nonetheless, the main controller is not  * trivial.  Its responsibility is to provide context rows for upsampling/  * rescaling, and doing this in an efficient fashion is a bit tricky.  *  * Postprocessor input data is counted in "row groups".  A row group  * is defined to be (v_samp_factor * DCT_scaled_size / min_DCT_scaled_size)  * sample rows of each component.  (We require DCT_scaled_size values to be  * chosen such that these numbers are integers.  In practice DCT_scaled_size  * values will likely be powers of two, so we actually have the stronger  * condition that DCT_scaled_size / min_DCT_scaled_size is an integer.)  * Upsampling will typically produce max_v_samp_factor pixel rows from each  * row group (times any additional scale factor that the upsampler is  * applying).  *  * The coefficient controller will deliver data to us one iMCU row at a time;  * each iMCU row contains v_samp_factor * DCT_scaled_size sample rows, or  * exactly min_DCT_scaled_size row groups.  (This amount of data corresponds  * to one row of MCUs when the image is fully interleaved.)  Note that the  * number of sample rows varies across components, but the number of row  * groups does not.  Some garbage sample rows may be included in the last iMCU  * row at the bottom of the image.  *  * Depending on the vertical scaling algorithm used, the upsampler may need  * access to the sample row(s) above and below its current input row group.  * The upsampler is required to set need_context_rows TRUE at global selection  * time if so.  When need_context_rows is FALSE, this controller can simply  * obtain one iMCU row at a time from the coefficient controller and dole it  * out as row groups to the postprocessor.  *  * When need_context_rows is TRUE, this controller guarantees that the buffer  * passed to postprocessing contains at least one row group's worth of samples  * above and below the row group(s) being processed.  Note that the context  * rows "above" the first passed row group appear at negative row offsets in  * the passed buffer.  At the top and bottom of the image, the required  * context rows are manufactured by duplicating the first or last real sample  * row; this avoids having special cases in the upsampling inner loops.  *  * The amount of context is fixed at one row group just because that's a  * convenient number for this controller to work with.  The existing  * upsamplers really only need one sample row of context.  An upsampler  * supporting arbitrary output rescaling might wish for more than one row  * group of context when shrinking the image; tough, we don't handle that.  * (This is justified by the assumption that downsizing will be handled mostly  * by adjusting the DCT_scaled_size values, so that the actual scale factor at  * the upsample step needn't be much less than one.)  *  * To provide the desired context, we have to retain the last two row groups  * of one iMCU row while reading in the next iMCU row.  (The last row group  * can't be processed until we have another row group for its below-context,  * and so we have to save the next-to-last group too for its above-context.)  * We could do this most simply by copying data around in our buffer, but  * that'd be very slow.  We can avoid copying any data by creating a rather  * strange pointer structure.  Here's how it works.  We allocate a workspace  * consisting of M+2 row groups (where M = min_DCT_scaled_size is the number  * of row groups per iMCU row).  We create two sets of redundant pointers to  * the workspace.  Labeling the physical row groups 0 to M+1, the synthesized  * pointer lists look like this:  *                   M+1                          M-1  * master pointer --> 0         master pointer --> 0  *                    1                            1  *                   ...                          ...  *                   M-3                          M-3  *                   M-2                           M  *                   M-1                          M+1  *                    M                           M-2  *                   M+1                          M-1  *                    0                            0  * We read alternate iMCU rows using each master pointer; thus the last two  * row groups of the previous iMCU row remain un-overwritten in the workspace.  * The pointer lists are set up so that the required context rows appear to  * be adjacent to the proper places when we pass the pointer lists to the  * upsampler.  *  * The above pictures describe the normal state of the pointer lists.  * At top and bottom of the image, we diddle the pointer lists to duplicate  * the first or last sample row as necessary (this is cheaper than copying  * sample rows around).  *  * This scheme breaks down if M< 2, ie, min_DCT_scaled_size is 1.  In that  * situation each iMCU row provides only one row group so the buffering logic  * must be different (eg, we must read two iMCU rows before we can emit the  * first row group).  For now, we simply do not support providing context  * rows when min_DCT_scaled_size is 1.  That combination seems unlikely to  * be worth providing --- if someone wants a 1/8th-size preview, they probably  * want it quick and dirty, so a context-free upsampler is sufficient.  */
end_comment
begin_comment
comment|/* Private buffer controller object */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pub
name|struct
name|jpeg_d_main_controller
name|pub
decl_stmt|;
comment|/* public fields */
comment|/* Pointer to allocated workspace (M or M+2 row groups). */
DECL|member|buffer
name|JSAMPARRAY
name|buffer
index|[
name|MAX_COMPONENTS
index|]
decl_stmt|;
DECL|member|buffer_full
name|boolean
name|buffer_full
decl_stmt|;
comment|/* Have we gotten an iMCU row from decoder? */
DECL|member|rowgroup_ctr
name|JDIMENSION
name|rowgroup_ctr
decl_stmt|;
comment|/* counts row groups output to postprocessor */
comment|/* Remaining fields are only used in the context case. */
comment|/* These are the master pointers to the funny-order pointer lists. */
DECL|member|xbuffer
name|JSAMPIMAGE
name|xbuffer
index|[
literal|2
index|]
decl_stmt|;
comment|/* pointers to weird pointer lists */
DECL|member|whichptr
name|int
name|whichptr
decl_stmt|;
comment|/* indicates which pointer set is now in use */
DECL|member|context_state
name|int
name|context_state
decl_stmt|;
comment|/* process_data state machine status */
DECL|member|rowgroups_avail
name|JDIMENSION
name|rowgroups_avail
decl_stmt|;
comment|/* row groups available to postprocessor */
DECL|member|iMCU_row_ctr
name|JDIMENSION
name|iMCU_row_ctr
decl_stmt|;
comment|/* counts iMCU rows to detect image top/bot */
block|}
DECL|typedef|my_main_controller
name|my_main_controller
typedef|;
end_typedef
begin_typedef
DECL|typedef|my_main_ptr
typedef|typedef
name|my_main_controller
modifier|*
name|my_main_ptr
typedef|;
end_typedef
begin_comment
comment|/* context_state values: */
end_comment
begin_define
DECL|macro|CTX_PREPARE_FOR_IMCU
define|#
directive|define
name|CTX_PREPARE_FOR_IMCU
value|0
end_define
begin_comment
DECL|macro|CTX_PREPARE_FOR_IMCU
comment|/* need to prepare for MCU row */
end_comment
begin_define
DECL|macro|CTX_PROCESS_IMCU
define|#
directive|define
name|CTX_PROCESS_IMCU
value|1
end_define
begin_comment
DECL|macro|CTX_PROCESS_IMCU
comment|/* feeding iMCU to postprocessor */
end_comment
begin_define
DECL|macro|CTX_POSTPONED_ROW
define|#
directive|define
name|CTX_POSTPONED_ROW
value|2
end_define
begin_comment
DECL|macro|CTX_POSTPONED_ROW
comment|/* feeding postponed row group */
end_comment
begin_comment
comment|/* Forward declarations */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|process_data_simple_main
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|JSAMPARRAY
name|output_buf
operator|,
name|JDIMENSION
operator|*
name|out_row_ctr
operator|,
name|JDIMENSION
name|out_rows_avail
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|process_data_context_main
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|JSAMPARRAY
name|output_buf
operator|,
name|JDIMENSION
operator|*
name|out_row_ctr
operator|,
name|JDIMENSION
name|out_rows_avail
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|QUANT_2PASS_SUPPORTED
end_ifdef
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_decl_stmt
name|process_data_crank_post
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|JSAMPARRAY
name|output_buf
operator|,
name|JDIMENSION
operator|*
name|out_row_ctr
operator|,
name|JDIMENSION
name|out_rows_avail
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|alloc_funny_pointers
name|alloc_funny_pointers
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_comment
comment|/* Allocate space for the funny pointer lists.  * This is done only once, not once per pass.  */
end_comment
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
name|int
name|ci
decl_stmt|,
name|rgroup
decl_stmt|;
name|int
name|M
init|=
name|cinfo
operator|->
name|min_DCT_v_scaled_size
decl_stmt|;
name|jpeg_component_info
modifier|*
name|compptr
decl_stmt|;
name|JSAMPARRAY
name|xbuf
decl_stmt|;
comment|/* Get top-level space for component array pointers.    * We alloc both arrays with one call to save a few cycles.    */
expr|main
operator|->
name|xbuffer
index|[
literal|0
index|]
operator|=
call|(
name|JSAMPIMAGE
call|)
argument_list|(
operator|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
argument_list|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
name|cinfo
operator|->
name|num_components
operator|*
literal|2
operator|*
name|SIZEOF
argument_list|(
name|JSAMPARRAY
argument_list|)
argument_list|)
expr_stmt|;
expr|main
operator|->
name|xbuffer
index|[
literal|1
index|]
operator|=
expr|main
operator|->
name|xbuffer
index|[
literal|0
index|]
operator|+
name|cinfo
operator|->
name|num_components
expr_stmt|;
for|for
control|(
name|ci
operator|=
literal|0
operator|,
name|compptr
operator|=
name|cinfo
operator|->
name|comp_info
init|;
name|ci
operator|<
name|cinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
operator|,
name|compptr
operator|++
control|)
block|{
name|rgroup
operator|=
operator|(
name|compptr
operator|->
name|v_samp_factor
operator|*
name|compptr
operator|->
name|DCT_v_scaled_size
operator|)
operator|/
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* height of a row group of component */
comment|/* Get space for pointer lists --- M+4 row groups in each list.      * We alloc both pointer lists with one call to save a few cycles.      */
name|xbuf
operator|=
call|(
name|JSAMPARRAY
call|)
argument_list|(
operator|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
argument_list|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
literal|2
operator|*
operator|(
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|4
operator|)
operator|)
operator|*
name|SIZEOF
argument_list|(
name|JSAMPROW
argument_list|)
argument_list|)
expr_stmt|;
name|xbuf
operator|+=
name|rgroup
expr_stmt|;
comment|/* want one row group at negative offsets */
expr|main
operator|->
name|xbuffer
index|[
literal|0
index|]
index|[
name|ci
index|]
operator|=
name|xbuf
expr_stmt|;
name|xbuf
operator|+=
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|4
operator|)
expr_stmt|;
expr|main
operator|->
name|xbuffer
index|[
literal|1
index|]
index|[
name|ci
index|]
operator|=
name|xbuf
expr_stmt|;
block|}
block|}
end_block
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|make_funny_pointers
name|make_funny_pointers
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_comment
comment|/* Create the funny pointer lists discussed in the comments above.  * The actual workspace is already allocated (in main->buffer),  * and the space for the pointer lists is allocated too.  * This routine just fills in the curiously ordered lists.  * This will be repeated at the beginning of each pass.  */
end_comment
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
name|int
name|ci
decl_stmt|,
name|i
decl_stmt|,
name|rgroup
decl_stmt|;
name|int
name|M
init|=
name|cinfo
operator|->
name|min_DCT_v_scaled_size
decl_stmt|;
name|jpeg_component_info
modifier|*
name|compptr
decl_stmt|;
name|JSAMPARRAY
name|buf
decl_stmt|,
name|xbuf0
decl_stmt|,
name|xbuf1
decl_stmt|;
for|for
control|(
name|ci
operator|=
literal|0
operator|,
name|compptr
operator|=
name|cinfo
operator|->
name|comp_info
init|;
name|ci
operator|<
name|cinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
operator|,
name|compptr
operator|++
control|)
block|{
name|rgroup
operator|=
operator|(
name|compptr
operator|->
name|v_samp_factor
operator|*
name|compptr
operator|->
name|DCT_v_scaled_size
operator|)
operator|/
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* height of a row group of component */
name|xbuf0
operator|=
expr|main
operator|->
name|xbuffer
index|[
literal|0
index|]
index|[
name|ci
index|]
expr_stmt|;
name|xbuf1
operator|=
expr|main
operator|->
name|xbuffer
index|[
literal|1
index|]
index|[
name|ci
index|]
expr_stmt|;
comment|/* First copy the workspace pointers as-is */
name|buf
operator|=
expr|main
operator|->
name|buffer
index|[
name|ci
index|]
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|2
operator|)
condition|;
name|i
operator|++
control|)
block|{
name|xbuf0
index|[
name|i
index|]
operator|=
name|xbuf1
index|[
name|i
index|]
operator|=
name|buf
index|[
name|i
index|]
expr_stmt|;
block|}
comment|/* In the second list, put the last four row groups in swapped order */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rgroup
operator|*
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|xbuf1
index|[
name|rgroup
operator|*
operator|(
name|M
operator|-
literal|2
operator|)
operator|+
name|i
index|]
operator|=
name|buf
index|[
name|rgroup
operator|*
name|M
operator|+
name|i
index|]
expr_stmt|;
name|xbuf1
index|[
name|rgroup
operator|*
name|M
operator|+
name|i
index|]
operator|=
name|buf
index|[
name|rgroup
operator|*
operator|(
name|M
operator|-
literal|2
operator|)
operator|+
name|i
index|]
expr_stmt|;
block|}
comment|/* The wraparound pointers at top and bottom will be filled later      * (see set_wraparound_pointers, below).  Initially we want the "above"      * pointers to duplicate the first actual data line.  This only needs      * to happen in xbuffer[0].      */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rgroup
condition|;
name|i
operator|++
control|)
block|{
name|xbuf0
index|[
name|i
operator|-
name|rgroup
index|]
operator|=
name|xbuf0
index|[
literal|0
index|]
expr_stmt|;
block|}
block|}
block|}
end_block
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|set_wraparound_pointers
name|set_wraparound_pointers
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_comment
comment|/* Set up the "wraparound" pointers at top and bottom of the pointer lists.  * This changes the pointer list state from top-of-image to the normal state.  */
end_comment
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
name|int
name|ci
decl_stmt|,
name|i
decl_stmt|,
name|rgroup
decl_stmt|;
name|int
name|M
init|=
name|cinfo
operator|->
name|min_DCT_v_scaled_size
decl_stmt|;
name|jpeg_component_info
modifier|*
name|compptr
decl_stmt|;
name|JSAMPARRAY
name|xbuf0
decl_stmt|,
name|xbuf1
decl_stmt|;
for|for
control|(
name|ci
operator|=
literal|0
operator|,
name|compptr
operator|=
name|cinfo
operator|->
name|comp_info
init|;
name|ci
operator|<
name|cinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
operator|,
name|compptr
operator|++
control|)
block|{
name|rgroup
operator|=
operator|(
name|compptr
operator|->
name|v_samp_factor
operator|*
name|compptr
operator|->
name|DCT_v_scaled_size
operator|)
operator|/
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* height of a row group of component */
name|xbuf0
operator|=
expr|main
operator|->
name|xbuffer
index|[
literal|0
index|]
index|[
name|ci
index|]
expr_stmt|;
name|xbuf1
operator|=
expr|main
operator|->
name|xbuffer
index|[
literal|1
index|]
index|[
name|ci
index|]
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rgroup
condition|;
name|i
operator|++
control|)
block|{
name|xbuf0
index|[
name|i
operator|-
name|rgroup
index|]
operator|=
name|xbuf0
index|[
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|1
operator|)
operator|+
name|i
index|]
expr_stmt|;
name|xbuf1
index|[
name|i
operator|-
name|rgroup
index|]
operator|=
name|xbuf1
index|[
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|1
operator|)
operator|+
name|i
index|]
expr_stmt|;
name|xbuf0
index|[
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|2
operator|)
operator|+
name|i
index|]
operator|=
name|xbuf0
index|[
name|i
index|]
expr_stmt|;
name|xbuf1
index|[
name|rgroup
operator|*
operator|(
name|M
operator|+
literal|2
operator|)
operator|+
name|i
index|]
operator|=
name|xbuf1
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
block|}
end_block
begin_macro
name|LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|set_bottom_pointers
name|set_bottom_pointers
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|)
end_macro
begin_comment
comment|/* Change the pointer lists to duplicate the last sample row at the bottom  * of the image.  whichptr indicates which xbuffer holds the final iMCU row.  * Also sets rowgroups_avail to indicate number of nondummy row groups in row.  */
end_comment
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
name|int
name|ci
decl_stmt|,
name|i
decl_stmt|,
name|rgroup
decl_stmt|,
name|iMCUheight
decl_stmt|,
name|rows_left
decl_stmt|;
name|jpeg_component_info
modifier|*
name|compptr
decl_stmt|;
name|JSAMPARRAY
name|xbuf
decl_stmt|;
for|for
control|(
name|ci
operator|=
literal|0
operator|,
name|compptr
operator|=
name|cinfo
operator|->
name|comp_info
init|;
name|ci
operator|<
name|cinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
operator|,
name|compptr
operator|++
control|)
block|{
comment|/* Count sample rows in one iMCU row and in one row group */
name|iMCUheight
operator|=
name|compptr
operator|->
name|v_samp_factor
operator|*
name|compptr
operator|->
name|DCT_v_scaled_size
expr_stmt|;
name|rgroup
operator|=
name|iMCUheight
operator|/
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* Count nondummy sample rows remaining for this component */
name|rows_left
operator|=
call|(
name|int
call|)
argument_list|(
name|compptr
operator|->
name|downsampled_height
operator|%
operator|(
name|JDIMENSION
operator|)
name|iMCUheight
argument_list|)
expr_stmt|;
if|if
condition|(
name|rows_left
operator|==
literal|0
condition|)
name|rows_left
operator|=
name|iMCUheight
expr_stmt|;
comment|/* Count nondummy row groups.  Should get same answer for each component,      * so we need only do it once.      */
if|if
condition|(
name|ci
operator|==
literal|0
condition|)
block|{
expr|main
operator|->
name|rowgroups_avail
operator|=
call|(
name|JDIMENSION
call|)
argument_list|(
operator|(
name|rows_left
operator|-
literal|1
operator|)
operator|/
name|rgroup
operator|+
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Duplicate the last real sample row rgroup*2 times; this pads out the      * last partial rowgroup and ensures at least one full rowgroup of context.      */
name|xbuf
operator|=
expr|main
operator|->
name|xbuffer
index|[
expr|main
operator|->
name|whichptr
expr|]
index|[
name|ci
index|]
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|rgroup
operator|*
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|xbuf
index|[
name|rows_left
operator|+
name|i
index|]
operator|=
name|xbuf
index|[
name|rows_left
operator|-
literal|1
index|]
expr_stmt|;
block|}
block|}
block|}
end_block
begin_comment
comment|/*  * Initialize for a processing pass.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|start_pass_main
name|start_pass_main
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|J_BUF_MODE pass_mode
argument_list|)
end_macro
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
switch|switch
condition|(
name|pass_mode
condition|)
block|{
case|case
name|JBUF_PASS_THRU
case|:
if|if
condition|(
name|cinfo
operator|->
name|upsample
operator|->
name|need_context_rows
condition|)
block|{
expr|main
operator|->
name|pub
operator|.
name|process_data
operator|=
name|process_data_context_main
expr_stmt|;
name|make_funny_pointers
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Create the xbuffer[] lists */
expr|main
operator|->
name|whichptr
operator|=
literal|0
expr_stmt|;
comment|/* Read first iMCU row into xbuffer[0] */
expr|main
operator|->
name|context_state
operator|=
name|CTX_PREPARE_FOR_IMCU
expr_stmt|;
expr|main
operator|->
name|iMCU_row_ctr
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|/* Simple case with no context needed */
expr|main
operator|->
name|pub
operator|.
name|process_data
operator|=
name|process_data_simple_main
expr_stmt|;
block|}
expr|main
operator|->
name|buffer_full
operator|=
name|FALSE
expr_stmt|;
comment|/* Mark buffer empty */
expr|main
operator|->
name|rowgroup_ctr
operator|=
literal|0
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|QUANT_2PASS_SUPPORTED
case|case
name|JBUF_CRANK_DEST
case|:
comment|/* For last pass of 2-pass quantization, just crank the postprocessor */
expr|main
operator|->
name|pub
operator|.
name|process_data
operator|=
name|process_data_crank_post
expr_stmt|;
break|break;
endif|#
directive|endif
default|default:
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_BUFFER_MODE
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_block
begin_comment
comment|/*  * Process some data.  * This handles the simple case where no context is required.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|process_data_simple_main
name|process_data_simple_main
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|JDIMENSION *out_row_ctr
argument_list|,
argument|JDIMENSION out_rows_avail
argument_list|)
end_macro
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
name|JDIMENSION
name|rowgroups_avail
decl_stmt|;
comment|/* Read input data if we haven't filled the main buffer yet */
if|if
condition|(
operator|!
expr|main
operator|->
name|buffer_full
condition|)
block|{
if|if
condition|(
operator|!
call|(
modifier|*
name|cinfo
operator|->
name|coef
operator|->
name|decompress_data
call|)
argument_list|(
name|cinfo
argument_list|,
expr|main
operator|->
name|buffer
argument_list|)
condition|)
return|return;
comment|/* suspension forced, can do nothing more */
expr|main
operator|->
name|buffer_full
operator|=
name|TRUE
expr_stmt|;
comment|/* OK, we have an iMCU row to work with */
block|}
comment|/* There are always min_DCT_scaled_size row groups in an iMCU row. */
name|rowgroups_avail
operator|=
operator|(
name|JDIMENSION
operator|)
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* Note: at the bottom of the image, we may pass extra garbage row groups    * to the postprocessor.  The postprocessor has to check for bottom    * of image anyway (at row resolution), so no point in us doing it too.    */
comment|/* Feed the postprocessor */
call|(
modifier|*
name|cinfo
operator|->
name|post
operator|->
name|post_process_data
call|)
argument_list|(
name|cinfo
argument_list|,
expr|main
operator|->
name|buffer
argument_list|,
operator|&
expr|main
operator|->
name|rowgroup_ctr
argument_list|,
name|rowgroups_avail
argument_list|,
name|output_buf
argument_list|,
name|out_row_ctr
argument_list|,
name|out_rows_avail
argument_list|)
expr_stmt|;
comment|/* Has postprocessor consumed all the data yet? If so, mark buffer empty */
if|if
condition|(
expr|main
operator|->
name|rowgroup_ctr
operator|>=
name|rowgroups_avail
condition|)
block|{
expr|main
operator|->
name|buffer_full
operator|=
name|FALSE
expr_stmt|;
expr|main
operator|->
name|rowgroup_ctr
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * Process some data.  * This handles the case where context rows must be provided.  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|process_data_context_main
name|process_data_context_main
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|JDIMENSION *out_row_ctr
argument_list|,
argument|JDIMENSION out_rows_avail
argument_list|)
end_macro
begin_block
block|{
name|my_main_ptr
decl|main
init|=
operator|(
name|my_main_ptr
operator|)
name|cinfo
operator|->
expr|main
decl_stmt|;
comment|/* Read input data if we haven't filled the main buffer yet */
if|if
condition|(
operator|!
expr|main
operator|->
name|buffer_full
condition|)
block|{
if|if
condition|(
operator|!
call|(
modifier|*
name|cinfo
operator|->
name|coef
operator|->
name|decompress_data
call|)
argument_list|(
name|cinfo
argument_list|,
expr|main
operator|->
name|xbuffer
index|[
expr|main
operator|->
name|whichptr
expr|]
argument_list|)
condition|)
return|return;
comment|/* suspension forced, can do nothing more */
expr|main
operator|->
name|buffer_full
operator|=
name|TRUE
expr_stmt|;
comment|/* OK, we have an iMCU row to work with */
expr|main
operator|->
name|iMCU_row_ctr
operator|++
expr_stmt|;
comment|/* count rows received */
block|}
comment|/* Postprocessor typically will not swallow all the input data it is handed    * in one call (due to filling the output buffer first).  Must be prepared    * to exit and restart.  This switch lets us keep track of how far we got.    * Note that each case falls through to the next on successful completion.    */
switch|switch
condition|(
expr|main
operator|->
name|context_state
condition|)
block|{
case|case
name|CTX_POSTPONED_ROW
case|:
comment|/* Call postprocessor using previously set pointers for postponed row */
call|(
modifier|*
name|cinfo
operator|->
name|post
operator|->
name|post_process_data
call|)
argument_list|(
name|cinfo
argument_list|,
expr|main
operator|->
name|xbuffer
index|[
expr|main
operator|->
name|whichptr
expr|]
argument_list|,
operator|&
expr|main
operator|->
name|rowgroup_ctr
argument_list|,
expr|main
operator|->
name|rowgroups_avail
argument_list|,
name|output_buf
argument_list|,
name|out_row_ctr
argument_list|,
name|out_rows_avail
argument_list|)
expr_stmt|;
if|if
condition|(
expr|main
operator|->
name|rowgroup_ctr
operator|<
expr|main
operator|->
name|rowgroups_avail
condition|)
return|return;
comment|/* Need to suspend */
expr|main
operator|->
name|context_state
operator|=
name|CTX_PREPARE_FOR_IMCU
expr_stmt|;
if|if
condition|(
operator|*
name|out_row_ctr
operator|>=
name|out_rows_avail
condition|)
return|return;
comment|/* Postprocessor exactly filled output buf */
comment|/*FALLTHROUGH*/
case|case
name|CTX_PREPARE_FOR_IMCU
case|:
comment|/* Prepare to process first M-1 row groups of this iMCU row */
expr|main
operator|->
name|rowgroup_ctr
operator|=
literal|0
expr_stmt|;
expr|main
operator|->
name|rowgroups_avail
operator|=
call|(
name|JDIMENSION
call|)
argument_list|(
name|cinfo
operator|->
name|min_DCT_v_scaled_size
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|/* Check for bottom of image: if so, tweak pointers to "duplicate"      * the last sample row, and adjust rowgroups_avail to ignore padding rows.      */
if|if
condition|(
expr|main
operator|->
name|iMCU_row_ctr
operator|==
name|cinfo
operator|->
name|total_iMCU_rows
condition|)
name|set_bottom_pointers
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
expr|main
operator|->
name|context_state
operator|=
name|CTX_PROCESS_IMCU
expr_stmt|;
comment|/*FALLTHROUGH*/
case|case
name|CTX_PROCESS_IMCU
case|:
comment|/* Call postprocessor using previously set pointers */
call|(
modifier|*
name|cinfo
operator|->
name|post
operator|->
name|post_process_data
call|)
argument_list|(
name|cinfo
argument_list|,
expr|main
operator|->
name|xbuffer
index|[
expr|main
operator|->
name|whichptr
expr|]
argument_list|,
operator|&
expr|main
operator|->
name|rowgroup_ctr
argument_list|,
expr|main
operator|->
name|rowgroups_avail
argument_list|,
name|output_buf
argument_list|,
name|out_row_ctr
argument_list|,
name|out_rows_avail
argument_list|)
expr_stmt|;
if|if
condition|(
expr|main
operator|->
name|rowgroup_ctr
operator|<
expr|main
operator|->
name|rowgroups_avail
condition|)
return|return;
comment|/* Need to suspend */
comment|/* After the first iMCU, change wraparound pointers to normal state */
if|if
condition|(
expr|main
operator|->
name|iMCU_row_ctr
operator|==
literal|1
condition|)
name|set_wraparound_pointers
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Prepare to load new iMCU row using other xbuffer list */
expr|main
operator|->
name|whichptr
operator|^=
literal|1
expr_stmt|;
comment|/* 0=>1 or 1=>0 */
expr|main
operator|->
name|buffer_full
operator|=
name|FALSE
expr_stmt|;
comment|/* Still need to process last row group of this iMCU row, */
comment|/* which is saved at index M+1 of the other xbuffer */
expr|main
operator|->
name|rowgroup_ctr
operator|=
call|(
name|JDIMENSION
call|)
argument_list|(
name|cinfo
operator|->
name|min_DCT_v_scaled_size
operator|+
literal|1
argument_list|)
expr_stmt|;
expr|main
operator|->
name|rowgroups_avail
operator|=
call|(
name|JDIMENSION
call|)
argument_list|(
name|cinfo
operator|->
name|min_DCT_v_scaled_size
operator|+
literal|2
argument_list|)
expr_stmt|;
expr|main
operator|->
name|context_state
operator|=
name|CTX_POSTPONED_ROW
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/*  * Process some data.  * Final pass of two-pass quantization: just call the postprocessor.  * Source data will be the postprocessor controller's internal buffer.  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|QUANT_2PASS_SUPPORTED
end_ifdef
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|process_data_crank_post
name|process_data_crank_post
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|JSAMPARRAY output_buf
argument_list|,
argument|JDIMENSION *out_row_ctr
argument_list|,
argument|JDIMENSION out_rows_avail
argument_list|)
end_macro
begin_block
block|{
call|(
modifier|*
name|cinfo
operator|->
name|post
operator|->
name|post_process_data
call|)
argument_list|(
name|cinfo
argument_list|,
operator|(
name|JSAMPIMAGE
operator|)
name|NULL
argument_list|,
operator|(
name|JDIMENSION
operator|*
operator|)
name|NULL
argument_list|,
operator|(
name|JDIMENSION
operator|)
literal|0
argument_list|,
name|output_buf
argument_list|,
name|out_row_ctr
argument_list|,
name|out_rows_avail
argument_list|)
expr_stmt|;
block|}
end_block
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* QUANT_2PASS_SUPPORTED */
end_comment
begin_comment
comment|/*  * Initialize main buffer controller.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|jinit_d_main_controller
name|jinit_d_main_controller
argument_list|(
argument|j_decompress_ptr cinfo
argument_list|,
argument|boolean need_full_buffer
argument_list|)
end_macro
begin_block
block|{
name|my_main_ptr
decl|main
decl_stmt|;
name|int
name|ci
decl_stmt|,
name|rgroup
decl_stmt|,
name|ngroups
decl_stmt|;
name|jpeg_component_info
modifier|*
name|compptr
decl_stmt|;
expr|main
operator|=
call|(
name|my_main_ptr
call|)
argument_list|(
operator|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_small
argument_list|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
name|SIZEOF
argument_list|(
name|my_main_controller
argument_list|)
argument_list|)
expr_stmt|;
name|cinfo
operator|->
expr|main
operator|=
operator|(
expr|struct
name|jpeg_d_main_controller
operator|*
operator|)
expr|main
expr_stmt|;
expr|main
operator|->
name|pub
operator|.
name|start_pass
operator|=
name|start_pass_main
expr_stmt|;
if|if
condition|(
name|need_full_buffer
condition|)
comment|/* shouldn't happen */
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_BAD_BUFFER_MODE
argument_list|)
expr_stmt|;
comment|/* Allocate the workspace.    * ngroups is the number of row groups we need.    */
if|if
condition|(
name|cinfo
operator|->
name|upsample
operator|->
name|need_context_rows
condition|)
block|{
if|if
condition|(
name|cinfo
operator|->
name|min_DCT_v_scaled_size
operator|<
literal|2
condition|)
comment|/* unsupported, see comments above */
name|ERREXIT
argument_list|(
name|cinfo
argument_list|,
name|JERR_NOTIMPL
argument_list|)
expr_stmt|;
name|alloc_funny_pointers
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Alloc space for xbuffer[] lists */
name|ngroups
operator|=
name|cinfo
operator|->
name|min_DCT_v_scaled_size
operator|+
literal|2
expr_stmt|;
block|}
else|else
block|{
name|ngroups
operator|=
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
block|}
for|for
control|(
name|ci
operator|=
literal|0
operator|,
name|compptr
operator|=
name|cinfo
operator|->
name|comp_info
init|;
name|ci
operator|<
name|cinfo
operator|->
name|num_components
condition|;
name|ci
operator|++
operator|,
name|compptr
operator|++
control|)
block|{
name|rgroup
operator|=
operator|(
name|compptr
operator|->
name|v_samp_factor
operator|*
name|compptr
operator|->
name|DCT_v_scaled_size
operator|)
operator|/
name|cinfo
operator|->
name|min_DCT_v_scaled_size
expr_stmt|;
comment|/* height of a row group of component */
expr|main
operator|->
name|buffer
index|[
name|ci
index|]
operator|=
call|(
modifier|*
name|cinfo
operator|->
name|mem
operator|->
name|alloc_sarray
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
name|compptr
operator|->
name|width_in_blocks
operator|*
name|compptr
operator|->
name|DCT_h_scaled_size
argument_list|,
call|(
name|JDIMENSION
call|)
argument_list|(
name|rgroup
operator|*
name|ngroups
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_block
end_unit
