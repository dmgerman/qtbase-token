begin_unit
begin_comment
comment|/*  * example.c  *  * This file illustrates how to use the IJG code as a subroutine library  * to read or write JPEG image files.  You should look at this code in  * conjunction with the documentation file libjpeg.txt.  *  * This code will not do anything useful as-is, but it may be helpful as a  * skeleton for constructing routines that call the JPEG library.    *  * We present these routines in the same coding style used in the JPEG code  * (ANSI function definitions, etc); but you are of course free to code your  * routines in a different style if you prefer.  */
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_comment
comment|/*  * Include file for users of JPEG library.  * You will need to have included system headers that define at least  * the typedefs FILE and size_t before you can include jpeglib.h.  * (stdio.h is sufficient on ANSI-conforming systems.)  * You may also wish to include "jerror.h".  */
end_comment
begin_include
include|#
directive|include
file|"jpeglib.h"
end_include
begin_comment
comment|/*  *<setjmp.h> is used for the optional error recovery mechanism shown in  * the second part of the example.  */
end_comment
begin_include
include|#
directive|include
file|<setjmp.h>
end_include
begin_comment
comment|/******************** JPEG COMPRESSION SAMPLE INTERFACE *******************/
end_comment
begin_comment
comment|/* This half of the example shows how to feed data into the JPEG compressor.  * We present a minimal version that does not worry about refinements such  * as error recovery (the JPEG code will just exit() if it gets an error).  */
end_comment
begin_comment
comment|/*  * IMAGE DATA FORMATS:  *  * The standard input image format is a rectangular array of pixels, with  * each pixel having the same number of "component" values (color channels).  * Each pixel row is an array of JSAMPLEs (which typically are unsigned chars).  * If you are working with color data, then the color values for each pixel  * must be adjacent in the row; for example, R,G,B,R,G,B,R,G,B,... for 24-bit  * RGB color.  *  * For this example, we'll assume that this data structure matches the way  * our application has stored the image in memory, so we can just pass a  * pointer to our image buffer.  In particular, let's say that the image is  * RGB color and is described by:  */
end_comment
begin_decl_stmt
specifier|extern
name|JSAMPLE
modifier|*
name|image_buffer
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Points to large array of R,G,B-order data */
end_comment
begin_decl_stmt
specifier|extern
name|int
name|image_height
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Number of rows in image */
end_comment
begin_decl_stmt
specifier|extern
name|int
name|image_width
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* Number of columns in image */
end_comment
begin_comment
comment|/*  * Sample routine for JPEG compression.  We assume that the target file name  * and a compression quality factor are passed in.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|write_JPEG_file
name|write_JPEG_file
argument_list|(
argument|char * filename
argument_list|,
argument|int quality
argument_list|)
end_macro
begin_block
block|{
comment|/* This struct contains the JPEG compression parameters and pointers to    * working space (which is allocated as needed by the JPEG library).    * It is possible to have several such structures, representing multiple    * compression/decompression processes, in existence at once.  We refer    * to any one struct (and its associated working data) as a "JPEG object".    */
name|struct
name|jpeg_compress_struct
name|cinfo
decl_stmt|;
comment|/* This struct represents a JPEG error handler.  It is declared separately    * because applications often want to supply a specialized error handler    * (see the second half of this file for an example).  But here we just    * take the easy way out and use the standard error handler, which will    * print a message on stderr and call exit() if compression fails.    * Note that this struct must live as long as the main JPEG parameter    * struct, to avoid dangling-pointer problems.    */
name|struct
name|jpeg_error_mgr
name|jerr
decl_stmt|;
comment|/* More stuff */
name|FILE
modifier|*
name|outfile
decl_stmt|;
comment|/* target file */
name|JSAMPROW
name|row_pointer
index|[
literal|1
index|]
decl_stmt|;
comment|/* pointer to JSAMPLE row[s] */
name|int
name|row_stride
decl_stmt|;
comment|/* physical row width in image buffer */
comment|/* Step 1: allocate and initialize JPEG compression object */
comment|/* We have to set up the error handler first, in case the initialization    * step fails.  (Unlikely, but it could happen if you are out of memory.)    * This routine fills in the contents of struct jerr, and returns jerr's    * address which we place into the link field in cinfo.    */
name|cinfo
operator|.
name|err
operator|=
name|jpeg_std_error
argument_list|(
operator|&
name|jerr
argument_list|)
expr_stmt|;
comment|/* Now we can initialize the JPEG compression object. */
name|jpeg_create_compress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Step 2: specify data destination (eg, a file) */
comment|/* Note: steps 2 and 3 can be done in either order. */
comment|/* Here we use the library-supplied code to send compressed data to a    * stdio stream.  You can also write your own code to do something else.    * VERY IMPORTANT: use "b" option to fopen() if you are on a machine that    * requires it in order to write binary files.    */
if|if
condition|(
operator|(
name|outfile
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"wb"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't open %s\n"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|jpeg_stdio_dest
argument_list|(
operator|&
name|cinfo
argument_list|,
name|outfile
argument_list|)
expr_stmt|;
comment|/* Step 3: set parameters for compression */
comment|/* First we supply a description of the input image.    * Four fields of the cinfo struct must be filled in:    */
name|cinfo
operator|.
name|image_width
operator|=
name|image_width
expr_stmt|;
comment|/* image width and height, in pixels */
name|cinfo
operator|.
name|image_height
operator|=
name|image_height
expr_stmt|;
name|cinfo
operator|.
name|input_components
operator|=
literal|3
expr_stmt|;
comment|/* # of color components per pixel */
name|cinfo
operator|.
name|in_color_space
operator|=
name|JCS_RGB
expr_stmt|;
comment|/* colorspace of input image */
comment|/* Now use the library's routine to set default compression parameters.    * (You must set at least cinfo.in_color_space before calling this,    * since the defaults depend on the source color space.)    */
name|jpeg_set_defaults
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Now you can set any non-default parameters you wish to.    * Here we just illustrate the use of quality (quantization table) scaling:    */
name|jpeg_set_quality
argument_list|(
operator|&
name|cinfo
argument_list|,
name|quality
argument_list|,
name|TRUE
comment|/* limit to baseline-JPEG values */
argument_list|)
expr_stmt|;
comment|/* Step 4: Start compressor */
comment|/* TRUE ensures that we will write a complete interchange-JPEG file.    * Pass TRUE unless you are very sure of what you're doing.    */
name|jpeg_start_compress
argument_list|(
operator|&
name|cinfo
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* Step 5: while (scan lines remain to be written) */
comment|/*           jpeg_write_scanlines(...); */
comment|/* Here we use the library's state variable cinfo.next_scanline as the    * loop counter, so that we don't have to keep track ourselves.    * To keep things simple, we pass one scanline per call; you can pass    * more if you wish, though.    */
name|row_stride
operator|=
name|image_width
operator|*
literal|3
expr_stmt|;
comment|/* JSAMPLEs per row in image_buffer */
while|while
condition|(
name|cinfo
operator|.
name|next_scanline
operator|<
name|cinfo
operator|.
name|image_height
condition|)
block|{
comment|/* jpeg_write_scanlines expects an array of pointers to scanlines.      * Here the array is only one element long, but you could pass      * more than one scanline at a time if that's more convenient.      */
name|row_pointer
index|[
literal|0
index|]
operator|=
operator|&
name|image_buffer
index|[
name|cinfo
operator|.
name|next_scanline
operator|*
name|row_stride
index|]
expr_stmt|;
operator|(
name|void
operator|)
name|jpeg_write_scanlines
argument_list|(
operator|&
name|cinfo
argument_list|,
name|row_pointer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
comment|/* Step 6: Finish compression */
name|jpeg_finish_compress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* After finish_compress, we can close the output file. */
name|fclose
argument_list|(
name|outfile
argument_list|)
expr_stmt|;
comment|/* Step 7: release JPEG compression object */
comment|/* This is an important step since it will release a good deal of memory. */
name|jpeg_destroy_compress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* And we're done! */
block|}
end_block
begin_comment
comment|/*  * SOME FINE POINTS:  *  * In the above loop, we ignored the return value of jpeg_write_scanlines,  * which is the number of scanlines actually written.  We could get away  * with this because we were only relying on the value of cinfo.next_scanline,  * which will be incremented correctly.  If you maintain additional loop  * variables then you should be careful to increment them properly.  * Actually, for output to a stdio stream you needn't worry, because  * then jpeg_write_scanlines will write all the lines passed (or else exit  * with a fatal error).  Partial writes can only occur if you use a data  * destination module that can demand suspension of the compressor.  * (If you don't know what that's for, you don't need it.)  *  * If the compressor requires full-image buffers (for entropy-coding  * optimization or a multi-scan JPEG file), it will create temporary  * files for anything that doesn't fit within the maximum-memory setting.  * (Note that temp files are NOT needed if you use the default parameters.)  * On some systems you may need to set up a signal handler to ensure that  * temporary files are deleted if the program is interrupted.  See libjpeg.txt.  *  * Scanlines MUST be supplied in top-to-bottom order if you want your JPEG  * files to be compatible with everyone else's.  If you cannot readily read  * your data in that order, you'll need an intermediate array to hold the  * image.  See rdtarga.c or rdbmp.c for examples of handling bottom-to-top  * source data using the JPEG code's internal virtual-array mechanisms.  */
end_comment
begin_comment
comment|/******************** JPEG DECOMPRESSION SAMPLE INTERFACE *******************/
end_comment
begin_comment
comment|/* This half of the example shows how to read data from the JPEG decompressor.  * It's a bit more refined than the above, in that we show:  *   (a) how to modify the JPEG library's standard error-reporting behavior;  *   (b) how to allocate workspace using the library's memory manager.  *  * Just to make this example a little different from the first one, we'll  * assume that we do not intend to put the whole image into an in-memory  * buffer, but to send it line-by-line someplace else.  We need a one-  * scanline-high JSAMPLE array as a work buffer, and we will let the JPEG  * memory manager allocate it for us.  This approach is actually quite useful  * because we don't need to remember to deallocate the buffer separately: it  * will go away automatically when the JPEG object is cleaned up.  */
end_comment
begin_comment
comment|/*  * ERROR HANDLING:  *  * The JPEG library's standard error handler (jerror.c) is divided into  * several "methods" which you can override individually.  This lets you  * adjust the behavior without duplicating a lot of code, which you might  * have to update with each future release.  *  * Our example here shows how to override the "error_exit" method so that  * control is returned to the library's caller when a fatal error occurs,  * rather than calling exit() as the standard error_exit method does.  *  * We use C's setjmp/longjmp facility to return control.  This means that the  * routine which calls the JPEG library must first execute a setjmp() call to  * establish the return point.  We want the replacement error_exit to do a  * longjmp().  But we need to make the setjmp buffer accessible to the  * error_exit routine.  To do this, we make a private extension of the  * standard JPEG error handler object.  (If we were using C++, we'd say we  * were making a subclass of the regular error handler.)  *  * Here's the extended error handler struct:  */
end_comment
begin_struct
DECL|struct|my_error_mgr
struct|struct
name|my_error_mgr
block|{
DECL|member|pub
name|struct
name|jpeg_error_mgr
name|pub
decl_stmt|;
comment|/* "public" fields */
DECL|member|setjmp_buffer
name|jmp_buf
name|setjmp_buffer
decl_stmt|;
comment|/* for return to caller */
block|}
struct|;
end_struct
begin_typedef
DECL|typedef|my_error_ptr
typedef|typedef
name|struct
name|my_error_mgr
modifier|*
name|my_error_ptr
typedef|;
end_typedef
begin_comment
comment|/*  * Here's the routine that will replace the standard error_exit method:  */
end_comment
begin_macro
name|METHODDEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|my_error_exit
name|my_error_exit
argument_list|(
argument|j_common_ptr cinfo
argument_list|)
end_macro
begin_block
block|{
comment|/* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
name|my_error_ptr
name|myerr
init|=
operator|(
name|my_error_ptr
operator|)
name|cinfo
operator|->
name|err
decl_stmt|;
comment|/* Always display the message. */
comment|/* We could postpone this until after returning, if we chose. */
call|(
modifier|*
name|cinfo
operator|->
name|err
operator|->
name|output_message
call|)
argument_list|(
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Return control to the setjmp point */
name|longjmp
argument_list|(
name|myerr
operator|->
name|setjmp_buffer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block
begin_comment
comment|/*  * Sample routine for JPEG decompression.  We assume that the source file name  * is passed in.  We want to return 1 on success, 0 on error.  */
end_comment
begin_macro
name|GLOBAL
argument_list|(
argument|int
argument_list|)
end_macro
begin_macro
DECL|function|read_JPEG_file
name|read_JPEG_file
argument_list|(
argument|char * filename
argument_list|)
end_macro
begin_block
block|{
comment|/* This struct contains the JPEG decompression parameters and pointers to    * working space (which is allocated as needed by the JPEG library).    */
name|struct
name|jpeg_decompress_struct
name|cinfo
decl_stmt|;
comment|/* We use our private extension JPEG error handler.    * Note that this struct must live as long as the main JPEG parameter    * struct, to avoid dangling-pointer problems.    */
name|struct
name|my_error_mgr
name|jerr
decl_stmt|;
comment|/* More stuff */
name|FILE
modifier|*
name|infile
decl_stmt|;
comment|/* source file */
name|JSAMPARRAY
name|buffer
decl_stmt|;
comment|/* Output row buffer */
name|int
name|row_stride
decl_stmt|;
comment|/* physical row width in output buffer */
comment|/* In this example we want to open the input file before doing anything else,    * so that the setjmp() error recovery below can assume the file is open.    * VERY IMPORTANT: use "b" option to fopen() if you are on a machine that    * requires it in order to read binary files.    */
if|if
condition|(
operator|(
name|infile
operator|=
name|fopen
argument_list|(
name|filename
argument_list|,
literal|"rb"
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"can't open %s\n"
argument_list|,
name|filename
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* Step 1: allocate and initialize JPEG decompression object */
comment|/* We set up the normal JPEG error routines, then override error_exit. */
name|cinfo
operator|.
name|err
operator|=
name|jpeg_std_error
argument_list|(
operator|&
name|jerr
operator|.
name|pub
argument_list|)
expr_stmt|;
name|jerr
operator|.
name|pub
operator|.
name|error_exit
operator|=
name|my_error_exit
expr_stmt|;
comment|/* Establish the setjmp return context for my_error_exit to use. */
if|if
condition|(
name|setjmp
argument_list|(
name|jerr
operator|.
name|setjmp_buffer
argument_list|)
condition|)
block|{
comment|/* If we get here, the JPEG code has signaled an error.      * We need to clean up the JPEG object, close the input file, and return.      */
name|jpeg_destroy_decompress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|infile
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
comment|/* Now we can initialize the JPEG decompression object. */
name|jpeg_create_decompress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* Step 2: specify data source (eg, a file) */
name|jpeg_stdio_src
argument_list|(
operator|&
name|cinfo
argument_list|,
name|infile
argument_list|)
expr_stmt|;
comment|/* Step 3: read file parameters with jpeg_read_header() */
operator|(
name|void
operator|)
name|jpeg_read_header
argument_list|(
operator|&
name|cinfo
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
comment|/* We can ignore the return value from jpeg_read_header since    *   (a) suspension is not possible with the stdio data source, and    *   (b) we passed TRUE to reject a tables-only JPEG file as an error.    * See libjpeg.txt for more info.    */
comment|/* Step 4: set parameters for decompression */
comment|/* In this example, we don't need to change any of the defaults set by    * jpeg_read_header(), so we do nothing here.    */
comment|/* Step 5: Start decompressor */
operator|(
name|void
operator|)
name|jpeg_start_decompress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* We can ignore the return value since suspension is not possible    * with the stdio data source.    */
comment|/* We may need to do some setup of our own at this point before reading    * the data.  After jpeg_start_decompress() we have the correct scaled    * output image dimensions available, as well as the output colormap    * if we asked for color quantization.    * In this example, we need to make an output work buffer of the right size.    */
comment|/* JSAMPLEs per row in output buffer */
name|row_stride
operator|=
name|cinfo
operator|.
name|output_width
operator|*
name|cinfo
operator|.
name|output_components
expr_stmt|;
comment|/* Make a one-row-high sample array that will go away when done with image */
name|buffer
operator|=
call|(
modifier|*
name|cinfo
operator|.
name|mem
operator|->
name|alloc_sarray
call|)
argument_list|(
operator|(
name|j_common_ptr
operator|)
operator|&
name|cinfo
argument_list|,
name|JPOOL_IMAGE
argument_list|,
name|row_stride
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Step 6: while (scan lines remain to be read) */
comment|/*           jpeg_read_scanlines(...); */
comment|/* Here we use the library's state variable cinfo.output_scanline as the    * loop counter, so that we don't have to keep track ourselves.    */
while|while
condition|(
name|cinfo
operator|.
name|output_scanline
operator|<
name|cinfo
operator|.
name|output_height
condition|)
block|{
comment|/* jpeg_read_scanlines expects an array of pointers to scanlines.      * Here the array is only one element long, but you could ask for      * more than one scanline at a time if that's more convenient.      */
operator|(
name|void
operator|)
name|jpeg_read_scanlines
argument_list|(
operator|&
name|cinfo
argument_list|,
name|buffer
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* Assume put_scanline_someplace wants a pointer and sample count. */
name|put_scanline_someplace
argument_list|(
name|buffer
index|[
literal|0
index|]
argument_list|,
name|row_stride
argument_list|)
expr_stmt|;
block|}
comment|/* Step 7: Finish decompression */
operator|(
name|void
operator|)
name|jpeg_finish_decompress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* We can ignore the return value since suspension is not possible    * with the stdio data source.    */
comment|/* Step 8: Release JPEG decompression object */
comment|/* This is an important step since it will release a good deal of memory. */
name|jpeg_destroy_decompress
argument_list|(
operator|&
name|cinfo
argument_list|)
expr_stmt|;
comment|/* After finish_decompress, we can close the input file.    * Here we postpone it until after no more JPEG errors are possible,    * so as to simplify the setjmp error logic above.  (Actually, I don't    * think that jpeg_destroy can do an error exit, but why assume anything...)    */
name|fclose
argument_list|(
name|infile
argument_list|)
expr_stmt|;
comment|/* At this point you may want to check to see whether any corrupt-data    * warnings occurred (test whether jerr.pub.num_warnings is nonzero).    */
comment|/* And we're done! */
return|return
literal|1
return|;
block|}
end_block
begin_comment
comment|/*  * SOME FINE POINTS:  *  * In the above code, we ignored the return value of jpeg_read_scanlines,  * which is the number of scanlines actually read.  We could get away with  * this because we asked for only one line at a time and we weren't using  * a suspending data source.  See libjpeg.txt for more info.  *  * We cheated a bit by calling alloc_sarray() after jpeg_start_decompress();  * we should have done it beforehand to ensure that the space would be  * counted against the JPEG max_memory setting.  In some systems the above  * code would risk an out-of-memory error.  However, in general we don't  * know the output image dimensions before jpeg_start_decompress(), unless we  * call jpeg_calc_output_dimensions().  See libjpeg.txt for more about this.  *  * Scanlines are returned in the same order as they appear in the JPEG file,  * which is standardly top-to-bottom.  If you must emit data bottom-to-top,  * you can use one of the virtual arrays provided by the JPEG memory manager  * to invert the data.  See wrbmp.c for an example.  *  * As with compression, some operating modes may require temporary files.  * On some systems you may need to set up a signal handler to ensure that  * temporary files are deleted if the program is interrupted.  See libjpeg.txt.  */
end_comment
end_unit
