begin_unit
begin_if
if|#
directive|if
literal|0
end_if
begin_comment
comment|/* in case someone actually tries to compile this */
end_comment
begin_comment
comment|/* example.c - an example of using libpng  * Last changed in libpng 1.5.0 [January 6, 2011]  * This file has been placed in the public domain by the authors.  * Maintained 1998-2011 Glenn Randers-Pehrson  * Maintained 1996, 1997 Andreas Dilger)  * Written 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  */
end_comment
begin_comment
comment|/* This is an example of how to use libpng to read and write PNG files.  * The file libpng-manual.txt is much more verbose then this.  If you have not  * read it, do so first.  This was designed to be a starting point of an  * implementation.  This is not officially part of libpng, is hereby placed  * in the public domain, and therefore does not require a copyright notice.  *  * This file does not currently compile, because it is missing certain  * parts, like allocating memory to hold an image.  You will have to  * supply these parts to get it to compile.  For an example of a minimal  * working PNG reader/writer, see pngtest.c, included in this distribution;  * see also the programs in the contrib directory.  */
end_comment
begin_include
include|#
directive|include
file|"png.h"
end_include
begin_comment
comment|/* The png_jmpbuf() macro, used in error handling, became available in   * libpng version 1.0.6.  If you want to be able to run your code with older   * versions of libpng, you must define the macro yourself (but only if it   * is not already defined by libpng!).   */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|png_jmpbuf
end_ifndef
begin_define
define|#
directive|define
name|png_jmpbuf
parameter_list|(
name|png_ptr
parameter_list|)
value|((png_ptr)->png_jmpbuf)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Check to see if a file is a PNG file using png_sig_cmp().  png_sig_cmp()  * returns zero if the image is a PNG and nonzero if it isn't a PNG.  *  * The function check_if_png() shown here, but not used, returns nonzero (true)  * if the file can be opened and is a PNG, 0 (false) otherwise.  *  * If this call is successful, and you are going to keep the file open,  * you should call png_set_sig_bytes(png_ptr, PNG_BYTES_TO_CHECK); once  * you have created the png_ptr, so that libpng knows your application  * has read that many bytes from the start of the file.  Make sure you  * don't call png_set_sig_bytes() with more than 8 bytes read or give it  * an incorrect number of bytes read, or you will either have read too  * many bytes (your fault), or you are telling libpng to read the wrong  * number of magic bytes (also your fault).  *  * Many applications already read the first 2 or 4 bytes from the start  * of the image to determine the file type, so it would be easiest just  * to pass the bytes to png_sig_cmp() or even skip that if you know  * you have a PNG file, and call png_set_sig_bytes().  */
end_comment
begin_define
define|#
directive|define
name|PNG_BYTES_TO_CHECK
value|4
end_define
begin_comment
unit|int check_if_png(char *file_name, FILE **fp) {    char buf[PNG_BYTES_TO_CHECK];
comment|/* Open the prospective PNG file. */
end_comment
begin_comment
unit|if ((*fp = fopen(file_name, "rb")) == NULL)       return 0;
comment|/* Read in some of the signature bytes */
end_comment
begin_comment
unit|if (fread(buf, 1, PNG_BYTES_TO_CHECK, *fp) != PNG_BYTES_TO_CHECK)       return 0;
comment|/* Compare the first PNG_BYTES_TO_CHECK bytes of the signature.       Return nonzero (true) if they match */
end_comment
begin_comment
unit|return(!png_sig_cmp(buf, (png_size_t)0, PNG_BYTES_TO_CHECK)); }
comment|/* Read a PNG file.  You may want to return an error code if the read  * fails (depending upon the failure).  There are two "prototypes" given  * here - one where we are given the filename, and we need to open the  * file, and the other where we are given an open file (possibly with  * some or all of the magic bytes read - see comments above).  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|open_file
end_ifdef
begin_comment
comment|/* prototype 1 */
end_comment
begin_comment
unit|void read_png(char *file_name)
comment|/* We need to open the file */
end_comment
begin_else
unit|{    png_structp png_ptr;    png_infop info_ptr;    unsigned int sig_read = 0;    png_uint_32 width, height;    int bit_depth, color_type, interlace_type;    FILE *fp;     if ((fp = fopen(file_name, "rb")) == NULL)       return (ERROR);
else|#
directive|else
else|no_open_file
end_else
begin_comment
comment|/* prototype 2 */
end_comment
begin_comment
unit|void read_png(FILE *fp, unsigned int sig_read)
comment|/* File is already open */
end_comment
begin_endif
unit|{    png_structp png_ptr;    png_infop info_ptr;    png_uint_32 width, height;    int bit_depth, color_type, interlace_type;
endif|#
directive|endif
endif|no_open_file
end_endif
begin_comment
comment|/* Only use one prototype! */
end_comment
begin_comment
comment|/* Create and initialize the png_struct with the desired error handler     * functions.  If you want to use the default stderr and longjump method,     * you can supply NULL for the last three parameters.  We also supply the     * the compiler header file version, so that we know if the application     * was compiled with a compatible version of the library.  REQUIRED     */
end_comment
begin_comment
unit|png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,       png_voidp user_error_ptr, user_error_fn, user_warning_fn);     if (png_ptr == NULL)    {       fclose(fp);       return (ERROR);    }
comment|/* Allocate/initialize the memory for image information.  REQUIRED. */
end_comment
begin_comment
unit|info_ptr = png_create_info_struct(png_ptr);    if (info_ptr == NULL)    {       fclose(fp);       png_destroy_read_struct(&png_ptr, NULL, NULL);       return (ERROR);    }
comment|/* Set error handling if you are using the setjmp/longjmp method (this is     * the normal method of doing things with libpng).  REQUIRED unless you     * set up your own error handlers in the png_create_read_struct() earlier.     */
end_comment
begin_comment
unit|if (setjmp(png_jmpbuf(png_ptr)))    {
comment|/* Free all of the memory associated with the png_ptr and info_ptr */
end_comment
begin_comment
unit|png_destroy_read_struct(&png_ptr,&info_ptr, NULL);       fclose(fp);
comment|/* If we get here, we had a problem reading the file */
end_comment
begin_comment
unit|return (ERROR);    }
comment|/* One of the following I/O initialization methods is REQUIRED */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|streams
end_ifdef
begin_comment
comment|/* PNG file I/O method 1 */
end_comment
begin_comment
comment|/* Set up the input control if you are using standard C streams */
end_comment
begin_else
unit|png_init_io(png_ptr, fp);
else|#
directive|else
else|no_streams
end_else
begin_comment
comment|/* PNG file I/O method 2 */
end_comment
begin_comment
comment|/* If you are using replacement read functions, instead of calling     * png_init_io() here you would call:     */
end_comment
begin_comment
unit|png_set_read_fn(png_ptr, (void *)user_io_ptr, user_read_fn);
comment|/* where user_io_ptr is a structure you want available to the callbacks */
end_comment
begin_endif
endif|#
directive|endif
endif|no_streams
end_endif
begin_comment
comment|/* Use only one I/O method! */
end_comment
begin_comment
comment|/* If we have already read some of the signature */
end_comment
begin_ifdef
unit|png_set_sig_bytes(png_ptr, sig_read);
ifdef|#
directive|ifdef
name|hilevel
end_ifdef
begin_comment
comment|/*     * If you have enough memory to read in the entire image at once,     * and you need to specify only transforms that can be controlled     * with one of the PNG_TRANSFORM_* bits (this presently excludes     * quantizing, filling, setting background, and doing gamma     * adjustment), then you can read the entire image (including     * pixels) into the info structure with this call:     */
end_comment
begin_else
unit|png_read_png(png_ptr, info_ptr, png_transforms, NULL);
else|#
directive|else
end_else
begin_comment
comment|/* OK, you're doing it the hard way, with the lower-level functions */
end_comment
begin_comment
comment|/* The call to png_read_info() gives us all of the information from the     * PNG file before the first IDAT (image data chunk).  REQUIRED     */
end_comment
begin_comment
unit|png_read_info(png_ptr, info_ptr);     png_get_IHDR(png_ptr, info_ptr,&width,&height,&bit_depth,&color_type,&interlace_type, NULL, NULL);
comment|/* Set up the data transformations you want.  Note that these are all     * optional.  Only call them if you want/need them.  Many of the     * transformations only work on specific types of images, and many     * are mutually exclusive.     */
end_comment
begin_comment
comment|/* Tell libpng to strip 16 bit/color files down to 8 bits/color */
end_comment
begin_comment
unit|png_set_strip_16(png_ptr);
comment|/* Strip alpha bytes from the input data without combining with the     * background (not recommended).     */
end_comment
begin_comment
unit|png_set_strip_alpha(png_ptr);
comment|/* Extract multiple pixels with bit depths of 1, 2, and 4 from a single     * byte into separate bytes (useful for paletted and grayscale images).     */
end_comment
begin_comment
unit|png_set_packing(png_ptr);
comment|/* Change the order of packed pixels to least significant bit first     * (not useful if you are using png_set_packing). */
end_comment
begin_comment
unit|png_set_packswap(png_ptr);
comment|/* Expand paletted colors into true RGB triplets */
end_comment
begin_comment
unit|if (color_type == PNG_COLOR_TYPE_PALETTE)       png_set_palette_to_rgb(png_ptr);
comment|/* Expand grayscale images to the full 8 bits from 1, 2, or 4 bits/pixel */
end_comment
begin_comment
unit|if (color_type == PNG_COLOR_TYPE_GRAY&& bit_depth< 8)       png_set_expand_gray_1_2_4_to_8(png_ptr);
comment|/* Expand paletted or RGB images with transparency to full alpha channels     * so the data will be available as RGBA quartets.     */
end_comment
begin_comment
unit|if (png_get_valid(png_ptr, info_ptr, PNG_INFO_tRNS))       png_set_tRNS_to_alpha(png_ptr);
comment|/* Set the background color to draw transparent and alpha images over.     * It is possible to set the red, green, and blue components directly     * for paletted images instead of supplying a palette index.  Note that     * even if the PNG file supplies a background, you are not required to     * use it - you should use the (solid) application background if it has one.     */
end_comment
begin_comment
unit|png_color_16 my_background, *image_background;     if (png_get_bKGD(png_ptr, info_ptr,&image_background))       png_set_background(png_ptr, image_background,                          PNG_BACKGROUND_GAMMA_FILE, 1, 1.0);    else       png_set_background(png_ptr,&my_background,                          PNG_BACKGROUND_GAMMA_SCREEN, 0, 1.0);
comment|/* Some suggestions as to how to get a screen gamma value     *     * Note that screen gamma is the display_exponent, which includes     * the CRT_exponent and any correction for viewing conditions     */
end_comment
begin_comment
unit|if (
comment|/* We have a user-defined screen gamma value */
end_comment
begin_comment
unit|)    {       screen_gamma = user-defined screen_gamma;    }
comment|/* This is one way that applications share the same screen gamma value */
end_comment
begin_comment
unit|else if ((gamma_str = getenv("SCREEN_GAMMA")) != NULL)    {       screen_gamma = atof(gamma_str);    }
comment|/* If we don't have another value */
end_comment
begin_comment
unit|else    {       screen_gamma = 2.2;
comment|/* A good guess for a PC monitor in a dimly                               lit room */
end_comment
begin_comment
unit|screen_gamma = 1.7 or 1.0;
comment|/* A good guess for Mac systems */
end_comment
begin_comment
unit|}
comment|/* Tell libpng to handle the gamma conversion for you.  The final call     * is a good guess for PC generated images, but it should be configurable     * by the user at run time by the user.  It is strongly suggested that     * your application support gamma correction.     */
end_comment
begin_ifdef
unit|int intent;     if (png_get_sRGB(png_ptr, info_ptr,&intent))       png_set_gamma(png_ptr, screen_gamma, 0.45455);    else    {       double image_gamma;       if (png_get_gAMA(png_ptr, info_ptr,&image_gamma))          png_set_gamma(png_ptr, screen_gamma, image_gamma);       else          png_set_gamma(png_ptr, screen_gamma, 0.45455);    }
ifdef|#
directive|ifdef
name|PNG_READ_QUANTIZE_SUPPORTED
end_ifdef
begin_comment
comment|/* Quantize RGB files down to 8 bit palette or reduce palettes     * to the number of colors available on your screen.     */
end_comment
begin_comment
unit|if (color_type& PNG_COLOR_MASK_COLOR)    {       int num_palette;       png_colorp palette;
comment|/* This reduces the image to the application supplied palette */
end_comment
begin_comment
unit|if (
comment|/* We have our own palette */
end_comment
begin_comment
unit|)       {
comment|/* An array of colors to which the image should be quantized */
end_comment
begin_comment
unit|png_color std_color_cube[MAX_SCREEN_COLORS];           png_set_quantize(png_ptr, std_color_cube, MAX_SCREEN_COLORS,             MAX_SCREEN_COLORS, NULL, 0);       }
comment|/* This reduces the image to the palette supplied in the file */
end_comment
begin_endif
unit|else if (png_get_PLTE(png_ptr, info_ptr,&palette,&num_palette))       {          png_uint_16p histogram = NULL;           png_get_hIST(png_ptr, info_ptr,&histogram);           png_set_quantize(png_ptr, palette, num_palette,                         max_screen_colors, histogram, 0);       }    }
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNG_READ_QUANTIZE_SUPPORTED */
end_comment
begin_comment
comment|/* Invert monochrome files to have 0 as white and 1 as black */
end_comment
begin_comment
unit|png_set_invert_mono(png_ptr);
comment|/* If you want to shift the pixel values from the range [0,255] or     * [0,65535] to the original [0,7] or [0,31], or whatever range the     * colors were originally in:     */
end_comment
begin_comment
unit|if (png_get_valid(png_ptr, info_ptr, PNG_INFO_sBIT))    {       png_color_8p sig_bit_p;        png_get_sBIT(png_ptr, info_ptr,&sig_bit_p);       png_set_shift(png_ptr, sig_bit_p);    }
comment|/* Flip the RGB pixels to BGR (or RGBA to BGRA) */
end_comment
begin_comment
unit|if (color_type& PNG_COLOR_MASK_COLOR)       png_set_bgr(png_ptr);
comment|/* Swap the RGBA or GA data to ARGB or AG (or BGRA to ABGR) */
end_comment
begin_comment
unit|png_set_swap_alpha(png_ptr);
comment|/* Swap bytes of 16 bit files to least significant byte first */
end_comment
begin_comment
unit|png_set_swap(png_ptr);
comment|/* Add filler (or alpha) byte (before/after each RGB triplet) */
end_comment
begin_comment
unit|png_set_filler(png_ptr, 0xff, PNG_FILLER_AFTER);
comment|/* Turn on interlace handling.  REQUIRED if you are not using     * png_read_image().  To see how to handle interlacing passes,     * see the png_read_row() method below:     */
end_comment
begin_comment
unit|number_passes = png_set_interlace_handling(png_ptr);
comment|/* Optional call to gamma correct and add the background to the palette     * and update info structure.  REQUIRED if you are expecting libpng to     * update the palette for you (ie you selected such a transform above).     */
end_comment
begin_comment
unit|png_read_update_info(png_ptr, info_ptr);
comment|/* Allocate the memory to hold the image using the fields of info_ptr. */
end_comment
begin_comment
comment|/* The easiest way to read the image: */
end_comment
begin_comment
unit|png_bytep row_pointers[height];
comment|/* Clear the pointer array */
end_comment
begin_comment
unit|for (row = 0; row< height; row++)       row_pointers[row] = NULL;     for (row = 0; row< height; row++)       row_pointers[row] = png_malloc(png_ptr, png_get_rowbytes(png_ptr,          info_ptr));
comment|/* Now it's time to read the image.  One of these methods is REQUIRED */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|entire
end_ifdef
begin_comment
comment|/* Read the entire image in one go */
end_comment
begin_else
unit|png_read_image(png_ptr, row_pointers);
else|#
directive|else
else|no_entire
end_else
begin_comment
comment|/* Read the image one or more scanlines at a time */
end_comment
begin_comment
comment|/* The other way to read images - deal with interlacing: */
end_comment
begin_ifdef
unit|for (pass = 0; pass< number_passes; pass++)    {
ifdef|#
directive|ifdef
name|single
end_ifdef
begin_comment
comment|/* Read the image a single row at a time */
end_comment
begin_else
unit|for (y = 0; y< height; y++)       {          png_read_rows(png_ptr,&row_pointers[y], NULL, 1);       }
else|#
directive|else
else|no_single
end_else
begin_comment
comment|/* Read the image several rows at a time */
end_comment
begin_ifdef
unit|for (y = 0; y< height; y += number_of_rows)       {
ifdef|#
directive|ifdef
name|sparkle
end_ifdef
begin_comment
comment|/* Read the image using the "sparkle" effect. */
end_comment
begin_else
unit|png_read_rows(png_ptr,&row_pointers[y], NULL,             number_of_rows);
else|#
directive|else
else|no_sparkle
end_else
begin_comment
comment|/* Read the image using the "rectangle" effect */
end_comment
begin_endif
unit|png_read_rows(png_ptr, NULL,&row_pointers[y],             number_of_rows);
endif|#
directive|endif
endif|no_sparkle
end_endif
begin_comment
comment|/* Use only one of these two methods */
end_comment
begin_comment
unit|}
comment|/* If you want to display the image after every pass, do so here */
end_comment
begin_endif
endif|#
directive|endif
endif|no_single
end_endif
begin_comment
comment|/* Use only one of these two methods */
end_comment
begin_endif
unit|}
endif|#
directive|endif
endif|no_entire
end_endif
begin_comment
comment|/* Use only one of these two methods */
end_comment
begin_comment
comment|/* Read rest of file, and get additional chunks in info_ptr - REQUIRED */
end_comment
begin_endif
unit|png_read_end(png_ptr, info_ptr);
endif|#
directive|endif
endif|hilevel
end_endif
begin_comment
comment|/* At this point you have read the entire image */
end_comment
begin_comment
comment|/* Clean up after the read, and free any memory allocated - REQUIRED */
end_comment
begin_comment
unit|png_destroy_read_struct(&png_ptr,&info_ptr, NULL);
comment|/* Close the file */
end_comment
begin_comment
unit|fclose(fp);
comment|/* That's it */
end_comment
begin_comment
unit|return (OK); }
comment|/* Progressively read a file */
end_comment
begin_comment
unit|int initialize_png_reader(png_structp *png_ptr, png_infop *info_ptr) {
comment|/* Create and initialize the png_struct with the desired error handler     * functions.  If you want to use the default stderr and longjump method,     * you can supply NULL for the last three parameters.  We also check that     * the library version is compatible in case we are using dynamically     * linked libraries.     */
end_comment
begin_comment
unit|*png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,        png_voidp user_error_ptr, user_error_fn, user_warning_fn);     if (*png_ptr == NULL)    {       *info_ptr = NULL;       return (ERROR);    }     *info_ptr = png_create_info_struct(png_ptr);     if (*info_ptr == NULL)    {       png_destroy_read_struct(png_ptr, info_ptr, NULL);       return (ERROR);    }     if (setjmp(png_jmpbuf((*png_ptr))))    {       png_destroy_read_struct(png_ptr, info_ptr, NULL);       return (ERROR);    }
comment|/* This one's new.  You will need to provide all three     * function callbacks, even if you aren't using them all.     * If you aren't using all functions, you can specify NULL     * parameters.  Even when all three functions are NULL,     * you need to call png_set_progressive_read_fn().     * These functions shouldn't be dependent on global or     * static variables if you are decoding several images     * simultaneously.  You should store stream specific data     * in a separate struct, given as the second parameter,     * and retrieve the pointer from inside the callbacks using     * the function png_get_progressive_ptr(png_ptr).     */
end_comment
begin_comment
unit|png_set_progressive_read_fn(*png_ptr, (void *)stream_data,       info_callback, row_callback, end_callback);     return (OK); }  int process_data(png_structp *png_ptr, png_infop *info_ptr,    png_bytep buffer, png_uint_32 length) {    if (setjmp(png_jmpbuf((*png_ptr))))    {
comment|/* Free the png_ptr and info_ptr memory on error */
end_comment
begin_comment
unit|png_destroy_read_struct(png_ptr, info_ptr, NULL);       return (ERROR);    }
comment|/* This one's new also.  Simply give it chunks of data as     * they arrive from the data stream (in order, of course).     * On segmented machines, don't give it any more than 64K.     * The library seems to run fine with sizes of 4K, although     * you can give it much less if necessary (I assume you can     * give it chunks of 1 byte, but I haven't tried with less     * than 256 bytes yet).  When this function returns, you may     * want to display any rows that were generated in the row     * callback, if you aren't already displaying them there.     */
end_comment
begin_comment
unit|png_process_data(*png_ptr, *info_ptr, buffer, length);    return (OK); }  info_callback(png_structp png_ptr, png_infop info) {
comment|/* Do any setup here, including setting any of the transformations     * mentioned in the Reading PNG files section.  For now, you _must_     * call either png_start_read_image() or png_read_update_info()     * after all the transformations are set (even if you don't set     * any).  You may start getting rows before png_process_data()     * returns, so this is your last chance to prepare for that.     */
end_comment
begin_comment
unit|}  row_callback(png_structp png_ptr, png_bytep new_row,    png_uint_32 row_num, int pass) {
comment|/*     * This function is called for every row in the image.  If the     * image is interlaced, and you turned on the interlace handler,     * this function will be called for every row in every pass.     *     * In this function you will receive a pointer to new row data from     * libpng called new_row that is to replace a corresponding row (of     * the same data format) in a buffer allocated by your application.     *     * The new row data pointer "new_row" may be NULL, indicating there is     * no new data to be replaced (in cases of interlace loading).     *     * If new_row is not NULL then you need to call     * png_progressive_combine_row() to replace the corresponding row as     * shown below:     */
end_comment
begin_comment
comment|/* Get pointer to corresponding row in our     * PNG read buffer.     */
end_comment
begin_comment
unit|png_bytep old_row = ((png_bytep *)our_data)[row_num];
comment|/* If both rows are allocated then copy the new row     * data to the corresponding row data.     */
end_comment
begin_comment
unit|if ((old_row != NULL)&& (new_row != NULL))    png_progressive_combine_row(png_ptr, old_row, new_row);
comment|/*     * The rows and passes are called in order, so you don't really     * need the row_num and pass, but I'm supplying them because it     * may make your life easier.     *     * For the non-NULL rows of interlaced images, you must call     * png_progressive_combine_row() passing in the new row and the     * old row, as demonstrated above.  You can call this function for     * NULL rows (it will just return) and for non-interlaced images     * (it just does the png_memcpy for you) if it will make the code     * easier.  Thus, you can just do this for all cases:     */
end_comment
begin_comment
unit|png_progressive_combine_row(png_ptr, old_row, new_row);
comment|/* where old_row is what was displayed for previous rows.  Note     * that the first pass (pass == 0 really) will completely cover     * the old row, so the rows do not have to be initialized.  After     * the first pass (and only for interlaced images), you will have     * to pass the current row as new_row, and the function will combine     * the old row and the new row.     */
end_comment
begin_comment
unit|}  end_callback(png_structp png_ptr, png_infop info) {
comment|/* This function is called when the whole image has been read,     * including any chunks after the image (up to and including     * the IEND).  You will usually have the same info chunk as you     * had in the header, although some data may have been added     * to the comments and time fields.     *     * Most people won't do much here, perhaps setting a flag that     * marks the image as finished.     */
end_comment
begin_comment
unit|}
comment|/* Write a png file */
end_comment
begin_comment
unit|void write_png(char *file_name
comment|/* , ... other image information ... */
end_comment
begin_comment
unit|) {    FILE *fp;    png_structp png_ptr;    png_infop info_ptr;    png_colorp palette;
comment|/* Open the file */
end_comment
begin_comment
unit|fp = fopen(file_name, "wb");    if (fp == NULL)       return (ERROR);
comment|/* Create and initialize the png_struct with the desired error handler     * functions.  If you want to use the default stderr and longjump method,     * you can supply NULL for the last three parameters.  We also check that     * the library version is compatible with the one used at compile time,     * in case we are using dynamically linked libraries.  REQUIRED.     */
end_comment
begin_comment
unit|png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING,       png_voidp user_error_ptr, user_error_fn, user_warning_fn);     if (png_ptr == NULL)    {       fclose(fp);       return (ERROR);    }
comment|/* Allocate/initialize the image information data.  REQUIRED */
end_comment
begin_comment
unit|info_ptr = png_create_info_struct(png_ptr);    if (info_ptr == NULL)    {       fclose(fp);       png_destroy_write_struct(&png_ptr,  NULL);       return (ERROR);    }
comment|/* Set error handling.  REQUIRED if you aren't supplying your own     * error handling functions in the png_create_write_struct() call.     */
end_comment
begin_comment
unit|if (setjmp(png_jmpbuf(png_ptr)))    {
comment|/* If we get here, we had a problem writing the file */
end_comment
begin_comment
unit|fclose(fp);       png_destroy_write_struct(&png_ptr,&info_ptr);       return (ERROR);    }
comment|/* One of the following I/O initialization functions is REQUIRED */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|streams
end_ifdef
begin_comment
comment|/* I/O initialization method 1 */
end_comment
begin_comment
comment|/* Set up the output control if you are using standard C streams */
end_comment
begin_else
unit|png_init_io(png_ptr, fp);
else|#
directive|else
else|no_streams
end_else
begin_comment
comment|/* I/O initialization method 2 */
end_comment
begin_comment
comment|/* If you are using replacement write functions, instead of calling     * png_init_io() here you would call     */
end_comment
begin_comment
unit|png_set_write_fn(png_ptr, (void *)user_io_ptr, user_write_fn,       user_IO_flush_function);
comment|/* where user_io_ptr is a structure you want available to the callbacks */
end_comment
begin_endif
endif|#
directive|endif
endif|no_streams
end_endif
begin_comment
comment|/* Only use one initialization method */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|hilevel
end_ifdef
begin_comment
comment|/* This is the easy way.  Use it if you already have all the     * image info living in the structure.  You could "|" many     * PNG_TRANSFORM flags into the png_transforms integer here.     */
end_comment
begin_else
unit|png_write_png(png_ptr, info_ptr, png_transforms, NULL);
else|#
directive|else
end_else
begin_comment
comment|/* This is the hard way */
end_comment
begin_comment
comment|/* Set the image information here.  Width and height are up to 2^31,     * bit_depth is one of 1, 2, 4, 8, or 16, but valid values also depend on     * the color_type selected. color_type is one of PNG_COLOR_TYPE_GRAY,     * PNG_COLOR_TYPE_GRAY_ALPHA, PNG_COLOR_TYPE_PALETTE, PNG_COLOR_TYPE_RGB,     * or PNG_COLOR_TYPE_RGB_ALPHA.  interlace is either PNG_INTERLACE_NONE or     * PNG_INTERLACE_ADAM7, and the compression_type and filter_type MUST     * currently be PNG_COMPRESSION_TYPE_BASE and PNG_FILTER_TYPE_BASE. REQUIRED     */
end_comment
begin_comment
unit|png_set_IHDR(png_ptr, info_ptr, width, height, bit_depth, PNG_COLOR_TYPE_???,       PNG_INTERLACE_????, PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);
comment|/* Set the palette if there is one.  REQUIRED for indexed-color images */
end_comment
begin_comment
unit|palette = (png_colorp)png_malloc(png_ptr, PNG_MAX_PALETTE_LENGTH              * png_sizeof(png_color));
comment|/* ... Set palette colors ... */
end_comment
begin_comment
unit|png_set_PLTE(png_ptr, info_ptr, palette, PNG_MAX_PALETTE_LENGTH);
comment|/* You must not free palette here, because png_set_PLTE only makes a link to     * the palette that you malloced.  Wait until you are about to destroy     * the png structure.     */
end_comment
begin_comment
comment|/* Optional significant bit (sBIT) chunk */
end_comment
begin_comment
unit|png_color_8 sig_bit;
comment|/* If we are dealing with a grayscale image then */
end_comment
begin_comment
unit|sig_bit.gray = true_bit_depth;
comment|/* Otherwise, if we are dealing with a color image then */
end_comment
begin_comment
unit|sig_bit.red = true_red_bit_depth;    sig_bit.green = true_green_bit_depth;    sig_bit.blue = true_blue_bit_depth;
comment|/* If the image has an alpha channel then */
end_comment
begin_comment
unit|sig_bit.alpha = true_alpha_bit_depth;     png_set_sBIT(png_ptr, info_ptr,&sig_bit);
comment|/* Optional gamma chunk is strongly suggested if you have any guess     * as to the correct gamma of the image.     */
end_comment
begin_comment
unit|png_set_gAMA(png_ptr, info_ptr, gamma);
comment|/* Optionally write comments into the image */
end_comment
begin_comment
unit|text_ptr[0].key = "Title";    text_ptr[0].text = "Mona Lisa";    text_ptr[0].compression = PNG_TEXT_COMPRESSION_NONE;    text_ptr[0].itxt_length = 0;    text_ptr[0].lang = NULL;    text_ptr[0].lang_key = NULL;    text_ptr[1].key = "Author";    text_ptr[1].text = "Leonardo DaVinci";    text_ptr[1].compression = PNG_TEXT_COMPRESSION_NONE;    text_ptr[1].itxt_length = 0;    text_ptr[1].lang = NULL;    text_ptr[1].lang_key = NULL;    text_ptr[2].key = "Description";    text_ptr[2].text = "<long text>";    text_ptr[2].compression = PNG_TEXT_COMPRESSION_zTXt;    text_ptr[2].itxt_length = 0;    text_ptr[2].lang = NULL;    text_ptr[2].lang_key = NULL;    png_set_text(png_ptr, info_ptr, text_ptr, 3);
comment|/* Other optional chunks like cHRM, bKGD, tRNS, tIME, oFFs, pHYs */
end_comment
begin_comment
comment|/* Note that if sRGB is present the gAMA and cHRM chunks must be ignored     * on read and, if your application chooses to write them, they must     * be written in accordance with the sRGB profile     */
end_comment
begin_comment
comment|/* Write the file header information.  REQUIRED */
end_comment
begin_comment
unit|png_write_info(png_ptr, info_ptr);
comment|/* If you want, you can write the info in two steps, in case you need to     * write your private chunk ahead of PLTE:     *     *   png_write_info_before_PLTE(write_ptr, write_info_ptr);     *   write_my_chunk();     *   png_write_info(png_ptr, info_ptr);     *     * However, given the level of known- and unknown-chunk support in 1.2.0     * and up, this should no longer be necessary.     */
end_comment
begin_comment
comment|/* Once we write out the header, the compression type on the text     * chunks gets changed to PNG_TEXT_COMPRESSION_NONE_WR or     * PNG_TEXT_COMPRESSION_zTXt_WR, so it doesn't get written out again     * at the end.     */
end_comment
begin_comment
comment|/* Set up the transformations you want.  Note that these are     * all optional.  Only call them if you want them.     */
end_comment
begin_comment
comment|/* Invert monochrome pixels */
end_comment
begin_comment
unit|png_set_invert_mono(png_ptr);
comment|/* Shift the pixels up to a legal bit depth and fill in     * as appropriate to correctly scale the image.     */
end_comment
begin_comment
unit|png_set_shift(png_ptr,&sig_bit);
comment|/* Pack pixels into bytes */
end_comment
begin_comment
unit|png_set_packing(png_ptr);
comment|/* Swap location of alpha bytes from ARGB to RGBA */
end_comment
begin_comment
unit|png_set_swap_alpha(png_ptr);
comment|/* Get rid of filler (OR ALPHA) bytes, pack XRGB/RGBX/ARGB/RGBA into     * RGB (4 channels -> 3 channels). The second parameter is not used.     */
end_comment
begin_comment
unit|png_set_filler(png_ptr, 0, PNG_FILLER_BEFORE);
comment|/* Flip BGR pixels to RGB */
end_comment
begin_comment
unit|png_set_bgr(png_ptr);
comment|/* Swap bytes of 16-bit files to most significant byte first */
end_comment
begin_comment
unit|png_set_swap(png_ptr);
comment|/* Swap bits of 1, 2, 4 bit packed pixel formats */
end_comment
begin_comment
unit|png_set_packswap(png_ptr);
comment|/* Turn on interlace handling if you are not using png_write_image() */
end_comment
begin_comment
unit|if (interlacing)       number_passes = png_set_interlace_handling(png_ptr);     else       number_passes = 1;
comment|/* The easiest way to write the image (you may have a different memory     * layout, however, so choose what fits your needs best).  You need to     * use the first method if you aren't handling interlacing yourself.     */
end_comment
begin_comment
unit|png_uint_32 k, height, width;    png_byte image[height][width*bytes_per_pixel];    png_bytep row_pointers[height];     if (height> PNG_UINT_32_MAX/png_sizeof(png_bytep))      png_error (png_ptr, "Image is too tall to process in memory");     for (k = 0; k< height; k++)      row_pointers[k] = image + k*width*bytes_per_pixel;
comment|/* One of the following output methods is REQUIRED */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|entire
end_ifdef
begin_comment
comment|/* Write out the entire image data in one call */
end_comment
begin_comment
unit|png_write_image(png_ptr, row_pointers);
comment|/* The other way to write the image - deal with interlacing */
end_comment
begin_else
else|#
directive|else
else|no_entire
end_else
begin_comment
comment|/* Write out the image data by one or more scanlines */
end_comment
begin_comment
comment|/* The number of passes is either 1 for non-interlaced images,     * or 7 for interlaced images.     */
end_comment
begin_comment
unit|for (pass = 0; pass< number_passes; pass++)    {
comment|/* Write a few rows at a time. */
end_comment
begin_comment
unit|png_write_rows(png_ptr,&row_pointers[first_row], number_of_rows);
comment|/* If you are only writing one row at a time, this works */
end_comment
begin_endif
unit|for (y = 0; y< height; y++)          png_write_rows(png_ptr,&row_pointers[y], 1);    }
endif|#
directive|endif
endif|no_entire
end_endif
begin_comment
comment|/* Use only one output method */
end_comment
begin_comment
comment|/* You can write optional chunks like tEXt, zTXt, and tIME at the end     * as well.  Shouldn't be necessary in 1.2.0 and up as all the public     * chunks are supported and you can use png_set_unknown_chunks() to     * register unknown chunks into the info structure to be written out.     */
end_comment
begin_comment
comment|/* It is REQUIRED to call this to finish writing the rest of the file */
end_comment
begin_endif
unit|png_write_end(png_ptr, info_ptr);
endif|#
directive|endif
endif|hilevel
end_endif
begin_comment
comment|/* If you png_malloced a palette, free it here (don't free info_ptr->palette,     * as recommended in versions 1.0.5m and earlier of this example; if     * libpng mallocs info_ptr->palette, libpng will free it).  If you     * allocated it with malloc() instead of png_malloc(), use free() instead     * of png_free().     */
end_comment
begin_comment
unit|png_free(png_ptr, palette);    palette = NULL;
comment|/* Similarly, if you png_malloced any data that you passed in with     * png_set_something(), such as a hist or trans array, free it here,     * when you can be sure that libpng is through with it.     */
end_comment
begin_comment
unit|png_free(png_ptr, trans);    trans = NULL;
comment|/* Whenever you use png_free() it is a good idea to set the pointer to     * NULL in case your application inadvertently tries to png_free() it     * again.  When png_free() sees a NULL it returns without action, thus     * avoiding the double-free security problem.     */
end_comment
begin_comment
comment|/* Clean up after the write, and free any memory allocated */
end_comment
begin_comment
unit|png_destroy_write_struct(&png_ptr,&info_ptr);
comment|/* Close the file */
end_comment
begin_comment
unit|fclose(fp);
comment|/* That's it */
end_comment
begin_endif
unit|return (OK); }
endif|#
directive|endif
end_endif
begin_comment
comment|/* if 0 */
end_comment
end_unit
