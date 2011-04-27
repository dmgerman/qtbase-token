begin_unit
begin_comment
comment|/* pngstruct.h - header file for PNG reference library  *  * Copyright (c) 1998-2011 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * Last changed in libpng 1.5.0 [January 6, 2011]  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  */
end_comment
begin_comment
comment|/* The structure that holds the information to read and write PNG files.  * The only people who need to care about what is inside of this are the  * people who will be modifying the library for their own special needs.  * It should NOT be accessed directly by an application.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNGSTRUCT_H
end_ifndef
begin_define
DECL|macro|PNGSTRUCT_H
define|#
directive|define
name|PNGSTRUCT_H
end_define
begin_comment
comment|/* zlib.h defines the structure z_stream, an instance of which is included  * in this structure and is required for decompressing the LZ compressed  * data in PNG files.  */
end_comment
begin_include
include|#
directive|include
file|"zlib.h"
end_include
begin_struct
DECL|struct|png_struct_def
struct|struct
name|png_struct_def
block|{
ifdef|#
directive|ifdef
name|PNG_SETJMP_SUPPORTED
DECL|member|png_jmpbuf
name|jmp_buf
name|png_jmpbuf
decl_stmt|;
comment|/* used in png_error */
DECL|member|longjmp_fn
name|png_longjmp_ptr
name|longjmp_fn
decl_stmt|;
comment|/* setjmp non-local goto function. */
endif|#
directive|endif
DECL|member|error_fn
name|png_error_ptr
name|error_fn
decl_stmt|;
comment|/* function for printing errors and aborting */
DECL|member|warning_fn
name|png_error_ptr
name|warning_fn
decl_stmt|;
comment|/* function for printing warnings */
DECL|member|error_ptr
name|png_voidp
name|error_ptr
decl_stmt|;
comment|/* user supplied struct for error functions */
DECL|member|write_data_fn
name|png_rw_ptr
name|write_data_fn
decl_stmt|;
comment|/* function for writing output data */
DECL|member|read_data_fn
name|png_rw_ptr
name|read_data_fn
decl_stmt|;
comment|/* function for reading input data */
DECL|member|io_ptr
name|png_voidp
name|io_ptr
decl_stmt|;
comment|/* ptr to application struct for I/O functions */
ifdef|#
directive|ifdef
name|PNG_READ_USER_TRANSFORM_SUPPORTED
DECL|member|read_user_transform_fn
name|png_user_transform_ptr
name|read_user_transform_fn
decl_stmt|;
comment|/* user read transform */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_USER_TRANSFORM_SUPPORTED
DECL|member|write_user_transform_fn
name|png_user_transform_ptr
name|write_user_transform_fn
decl_stmt|;
comment|/* user write transform */
endif|#
directive|endif
comment|/* These were added in libpng-1.0.2 */
ifdef|#
directive|ifdef
name|PNG_USER_TRANSFORM_PTR_SUPPORTED
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_USER_TRANSFORM_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_WRITE_USER_TRANSFORM_SUPPORTED
argument_list|)
DECL|member|user_transform_ptr
name|png_voidp
name|user_transform_ptr
decl_stmt|;
comment|/* user supplied struct for user transform */
DECL|member|user_transform_depth
name|png_byte
name|user_transform_depth
decl_stmt|;
comment|/* bit depth of user transformed pixels */
DECL|member|user_transform_channels
name|png_byte
name|user_transform_channels
decl_stmt|;
comment|/* channels in user transformed pixels */
endif|#
directive|endif
endif|#
directive|endif
DECL|member|mode
name|png_uint_32
name|mode
decl_stmt|;
comment|/* tells us where we are in the PNG file */
DECL|member|flags
name|png_uint_32
name|flags
decl_stmt|;
comment|/* flags indicating various things to libpng */
DECL|member|transformations
name|png_uint_32
name|transformations
decl_stmt|;
comment|/* which transformations to perform */
DECL|member|zstream
name|z_stream
name|zstream
decl_stmt|;
comment|/* pointer to decompression structure (below) */
DECL|member|zbuf
name|png_bytep
name|zbuf
decl_stmt|;
comment|/* buffer for zlib */
DECL|member|zbuf_size
name|uInt
name|zbuf_size
decl_stmt|;
comment|/* size of zbuf (typically 65536) */
DECL|member|zlib_level
name|int
name|zlib_level
decl_stmt|;
comment|/* holds zlib compression level */
DECL|member|zlib_method
name|int
name|zlib_method
decl_stmt|;
comment|/* holds zlib compression method */
DECL|member|zlib_window_bits
name|int
name|zlib_window_bits
decl_stmt|;
comment|/* holds zlib compression window bits */
DECL|member|zlib_mem_level
name|int
name|zlib_mem_level
decl_stmt|;
comment|/* holds zlib compression memory level */
DECL|member|zlib_strategy
name|int
name|zlib_strategy
decl_stmt|;
comment|/* holds zlib compression strategy */
DECL|member|width
name|png_uint_32
name|width
decl_stmt|;
comment|/* width of image in pixels */
DECL|member|height
name|png_uint_32
name|height
decl_stmt|;
comment|/* height of image in pixels */
DECL|member|num_rows
name|png_uint_32
name|num_rows
decl_stmt|;
comment|/* number of rows in current pass */
DECL|member|usr_width
name|png_uint_32
name|usr_width
decl_stmt|;
comment|/* width of row at start of write */
DECL|member|rowbytes
name|png_size_t
name|rowbytes
decl_stmt|;
comment|/* size of row in bytes */
DECL|member|iwidth
name|png_uint_32
name|iwidth
decl_stmt|;
comment|/* width of current interlaced row in pixels */
DECL|member|row_number
name|png_uint_32
name|row_number
decl_stmt|;
comment|/* current row in interlace pass */
DECL|member|prev_row
name|png_bytep
name|prev_row
decl_stmt|;
comment|/* buffer to save previous (unfiltered) row */
DECL|member|row_buf
name|png_bytep
name|row_buf
decl_stmt|;
comment|/* buffer to save current (unfiltered) row */
DECL|member|sub_row
name|png_bytep
name|sub_row
decl_stmt|;
comment|/* buffer to save "sub" row when filtering */
DECL|member|up_row
name|png_bytep
name|up_row
decl_stmt|;
comment|/* buffer to save "up" row when filtering */
DECL|member|avg_row
name|png_bytep
name|avg_row
decl_stmt|;
comment|/* buffer to save "avg" row when filtering */
DECL|member|paeth_row
name|png_bytep
name|paeth_row
decl_stmt|;
comment|/* buffer to save "Paeth" row when filtering */
DECL|member|row_info
name|png_row_info
name|row_info
decl_stmt|;
comment|/* used for transformation routines */
DECL|member|idat_size
name|png_uint_32
name|idat_size
decl_stmt|;
comment|/* current IDAT size for read */
DECL|member|crc
name|png_uint_32
name|crc
decl_stmt|;
comment|/* current chunk CRC value */
DECL|member|palette
name|png_colorp
name|palette
decl_stmt|;
comment|/* palette from the input file */
DECL|member|num_palette
name|png_uint_16
name|num_palette
decl_stmt|;
comment|/* number of color entries in palette */
DECL|member|num_trans
name|png_uint_16
name|num_trans
decl_stmt|;
comment|/* number of transparency values */
DECL|member|chunk_name
name|png_byte
name|chunk_name
index|[
literal|5
index|]
decl_stmt|;
comment|/* null-terminated name of current chunk */
DECL|member|compression
name|png_byte
name|compression
decl_stmt|;
comment|/* file compression type (always 0) */
DECL|member|filter
name|png_byte
name|filter
decl_stmt|;
comment|/* file filter type (always 0) */
DECL|member|interlaced
name|png_byte
name|interlaced
decl_stmt|;
comment|/* PNG_INTERLACE_NONE, PNG_INTERLACE_ADAM7 */
DECL|member|pass
name|png_byte
name|pass
decl_stmt|;
comment|/* current interlace pass (0 - 6) */
DECL|member|do_filter
name|png_byte
name|do_filter
decl_stmt|;
comment|/* row filter flags (see PNG_FILTER_ below ) */
DECL|member|color_type
name|png_byte
name|color_type
decl_stmt|;
comment|/* color type of file */
DECL|member|bit_depth
name|png_byte
name|bit_depth
decl_stmt|;
comment|/* bit depth of file */
DECL|member|usr_bit_depth
name|png_byte
name|usr_bit_depth
decl_stmt|;
comment|/* bit depth of users row */
DECL|member|pixel_depth
name|png_byte
name|pixel_depth
decl_stmt|;
comment|/* number of bits per pixel */
DECL|member|channels
name|png_byte
name|channels
decl_stmt|;
comment|/* number of channels in file */
DECL|member|usr_channels
name|png_byte
name|usr_channels
decl_stmt|;
comment|/* channels at start of write */
DECL|member|sig_bytes
name|png_byte
name|sig_bytes
decl_stmt|;
comment|/* magic bytes read/written from start of file */
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_FILLER_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_WRITE_FILLER_SUPPORTED
argument_list|)
DECL|member|filler
name|png_uint_16
name|filler
decl_stmt|;
comment|/* filler bytes for pixel expansion */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_bKGD_SUPPORTED
DECL|member|background_gamma_type
name|png_byte
name|background_gamma_type
decl_stmt|;
DECL|member|background_gamma
name|png_fixed_point
name|background_gamma
decl_stmt|;
DECL|member|background
name|png_color_16
name|background
decl_stmt|;
comment|/* background color in screen gamma space */
ifdef|#
directive|ifdef
name|PNG_READ_GAMMA_SUPPORTED
DECL|member|background_1
name|png_color_16
name|background_1
decl_stmt|;
comment|/* background normalized to gamma 1.0 */
endif|#
directive|endif
endif|#
directive|endif
comment|/* PNG_bKGD_SUPPORTED */
ifdef|#
directive|ifdef
name|PNG_WRITE_FLUSH_SUPPORTED
DECL|member|output_flush_fn
name|png_flush_ptr
name|output_flush_fn
decl_stmt|;
comment|/* Function for flushing output */
DECL|member|flush_dist
name|png_uint_32
name|flush_dist
decl_stmt|;
comment|/* how many rows apart to flush, 0 - no flush */
DECL|member|flush_rows
name|png_uint_32
name|flush_rows
decl_stmt|;
comment|/* number of rows written since last flush */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_GAMMA_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
DECL|member|gamma_shift
name|int
name|gamma_shift
decl_stmt|;
comment|/* number of "insignificant" bits in 16-bit gamma */
DECL|member|gamma
name|png_fixed_point
name|gamma
decl_stmt|;
comment|/* file gamma value */
DECL|member|screen_gamma
name|png_fixed_point
name|screen_gamma
decl_stmt|;
comment|/* screen gamma value (display_exponent) */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_GAMMA_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
DECL|member|gamma_table
name|png_bytep
name|gamma_table
decl_stmt|;
comment|/* gamma table for 8-bit depth files */
DECL|member|gamma_from_1
name|png_bytep
name|gamma_from_1
decl_stmt|;
comment|/* converts from 1.0 to screen */
DECL|member|gamma_to_1
name|png_bytep
name|gamma_to_1
decl_stmt|;
comment|/* converts from file to 1.0 */
DECL|member|gamma_16_table
name|png_uint_16pp
name|gamma_16_table
decl_stmt|;
comment|/* gamma table for 16-bit depth files */
DECL|member|gamma_16_from_1
name|png_uint_16pp
name|gamma_16_from_1
decl_stmt|;
comment|/* converts from 1.0 to screen */
DECL|member|gamma_16_to_1
name|png_uint_16pp
name|gamma_16_to_1
decl_stmt|;
comment|/* converts from file to 1.0 */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_GAMMA_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_sBIT_SUPPORTED
argument_list|)
DECL|member|sig_bit
name|png_color_8
name|sig_bit
decl_stmt|;
comment|/* significant bits in each available channel */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_SHIFT_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_WRITE_SHIFT_SUPPORTED
argument_list|)
DECL|member|shift
name|png_color_8
name|shift
decl_stmt|;
comment|/* shift for significant bit tranformation */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PNG_tRNS_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|PNG_READ_EXPAND_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
DECL|member|trans_alpha
name|png_bytep
name|trans_alpha
decl_stmt|;
comment|/* alpha values for paletted files */
DECL|member|trans_color
name|png_color_16
name|trans_color
decl_stmt|;
comment|/* transparent color for non-paletted files */
endif|#
directive|endif
DECL|member|read_row_fn
name|png_read_status_ptr
name|read_row_fn
decl_stmt|;
comment|/* called after each row is decoded */
DECL|member|write_row_fn
name|png_write_status_ptr
name|write_row_fn
decl_stmt|;
comment|/* called after each row is encoded */
ifdef|#
directive|ifdef
name|PNG_PROGRESSIVE_READ_SUPPORTED
DECL|member|info_fn
name|png_progressive_info_ptr
name|info_fn
decl_stmt|;
comment|/* called after header data fully read */
DECL|member|row_fn
name|png_progressive_row_ptr
name|row_fn
decl_stmt|;
comment|/* called after a prog. row is decoded */
DECL|member|end_fn
name|png_progressive_end_ptr
name|end_fn
decl_stmt|;
comment|/* called after image is complete */
DECL|member|save_buffer_ptr
name|png_bytep
name|save_buffer_ptr
decl_stmt|;
comment|/* current location in save_buffer */
DECL|member|save_buffer
name|png_bytep
name|save_buffer
decl_stmt|;
comment|/* buffer for previously read data */
DECL|member|current_buffer_ptr
name|png_bytep
name|current_buffer_ptr
decl_stmt|;
comment|/* current location in current_buffer */
DECL|member|current_buffer
name|png_bytep
name|current_buffer
decl_stmt|;
comment|/* buffer for recently used data */
DECL|member|push_length
name|png_uint_32
name|push_length
decl_stmt|;
comment|/* size of current input chunk */
DECL|member|skip_length
name|png_uint_32
name|skip_length
decl_stmt|;
comment|/* bytes to skip in input data */
DECL|member|save_buffer_size
name|png_size_t
name|save_buffer_size
decl_stmt|;
comment|/* amount of data now in save_buffer */
DECL|member|save_buffer_max
name|png_size_t
name|save_buffer_max
decl_stmt|;
comment|/* total size of save_buffer */
DECL|member|buffer_size
name|png_size_t
name|buffer_size
decl_stmt|;
comment|/* total amount of available input data */
DECL|member|current_buffer_size
name|png_size_t
name|current_buffer_size
decl_stmt|;
comment|/* amount of data now in current_buffer */
DECL|member|process_mode
name|int
name|process_mode
decl_stmt|;
comment|/* what push library is currently doing */
DECL|member|cur_palette
name|int
name|cur_palette
decl_stmt|;
comment|/* current push library palette index */
ifdef|#
directive|ifdef
name|PNG_TEXT_SUPPORTED
DECL|member|current_text_size
name|png_size_t
name|current_text_size
decl_stmt|;
comment|/* current size of text input data */
DECL|member|current_text_left
name|png_size_t
name|current_text_left
decl_stmt|;
comment|/* how much text left to read in input */
DECL|member|current_text
name|png_charp
name|current_text
decl_stmt|;
comment|/* current text chunk buffer */
DECL|member|current_text_ptr
name|png_charp
name|current_text_ptr
decl_stmt|;
comment|/* current location in current_text */
endif|#
directive|endif
comment|/* PNG_PROGRESSIVE_READ_SUPPORTED&& PNG_TEXT_SUPPORTED */
endif|#
directive|endif
comment|/* PNG_PROGRESSIVE_READ_SUPPORTED */
if|#
directive|if
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_Windows
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FLAT__
argument_list|)
comment|/* For the Borland special 64K segment handler */
DECL|member|offset_table_ptr
name|png_bytepp
name|offset_table_ptr
decl_stmt|;
DECL|member|offset_table
name|png_bytep
name|offset_table
decl_stmt|;
DECL|member|offset_table_number
name|png_uint_16
name|offset_table_number
decl_stmt|;
DECL|member|offset_table_count
name|png_uint_16
name|offset_table_count
decl_stmt|;
DECL|member|offset_table_count_free
name|png_uint_16
name|offset_table_count_free
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_READ_QUANTIZE_SUPPORTED
DECL|member|palette_lookup
name|png_bytep
name|palette_lookup
decl_stmt|;
comment|/* lookup table for quantizing */
DECL|member|quantize_index
name|png_bytep
name|quantize_index
decl_stmt|;
comment|/* index translation for palette files */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_QUANTIZE_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_hIST_SUPPORTED
argument_list|)
DECL|member|hist
name|png_uint_16p
name|hist
decl_stmt|;
comment|/* histogram */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_WRITE_WEIGHTED_FILTER_SUPPORTED
DECL|member|heuristic_method
name|png_byte
name|heuristic_method
decl_stmt|;
comment|/* heuristic for row filter selection */
DECL|member|num_prev_filters
name|png_byte
name|num_prev_filters
decl_stmt|;
comment|/* number of weights for previous rows */
DECL|member|prev_filters
name|png_bytep
name|prev_filters
decl_stmt|;
comment|/* filter type(s) of previous row(s) */
DECL|member|filter_weights
name|png_uint_16p
name|filter_weights
decl_stmt|;
comment|/* weight(s) for previous line(s) */
DECL|member|inv_filter_weights
name|png_uint_16p
name|inv_filter_weights
decl_stmt|;
comment|/* 1/weight(s) for previous line(s) */
DECL|member|filter_costs
name|png_uint_16p
name|filter_costs
decl_stmt|;
comment|/* relative filter calculation cost */
DECL|member|inv_filter_costs
name|png_uint_16p
name|inv_filter_costs
decl_stmt|;
comment|/* 1/relative filter calculation cost */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_TIME_RFC1123_SUPPORTED
DECL|member|time_buffer
name|png_charp
name|time_buffer
decl_stmt|;
comment|/* String to hold RFC 1123 time text */
endif|#
directive|endif
comment|/* New members added in libpng-1.0.6 */
DECL|member|free_me
name|png_uint_32
name|free_me
decl_stmt|;
comment|/* flags items libpng is responsible for freeing */
ifdef|#
directive|ifdef
name|PNG_USER_CHUNKS_SUPPORTED
DECL|member|user_chunk_ptr
name|png_voidp
name|user_chunk_ptr
decl_stmt|;
DECL|member|read_user_chunk_fn
name|png_user_chunk_ptr
name|read_user_chunk_fn
decl_stmt|;
comment|/* user read chunk handler */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_HANDLE_AS_UNKNOWN_SUPPORTED
DECL|member|num_chunk_list
name|int
name|num_chunk_list
decl_stmt|;
DECL|member|chunk_list
name|png_bytep
name|chunk_list
decl_stmt|;
endif|#
directive|endif
comment|/* New members added in libpng-1.0.3 */
ifdef|#
directive|ifdef
name|PNG_READ_RGB_TO_GRAY_SUPPORTED
DECL|member|rgb_to_gray_status
name|png_byte
name|rgb_to_gray_status
decl_stmt|;
comment|/* These were changed from png_byte in libpng-1.0.6 */
DECL|member|rgb_to_gray_red_coeff
name|png_uint_16
name|rgb_to_gray_red_coeff
decl_stmt|;
DECL|member|rgb_to_gray_green_coeff
name|png_uint_16
name|rgb_to_gray_green_coeff
decl_stmt|;
DECL|member|rgb_to_gray_blue_coeff
name|png_uint_16
name|rgb_to_gray_blue_coeff
decl_stmt|;
endif|#
directive|endif
comment|/* New member added in libpng-1.0.4 (renamed in 1.0.9) */
if|#
directive|if
name|defined
argument_list|(
name|PNG_MNG_FEATURES_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_READ_EMPTY_PLTE_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_WRITE_EMPTY_PLTE_SUPPORTED
argument_list|)
comment|/* Changed from png_byte to png_uint_32 at version 1.2.0 */
DECL|member|mng_features_permitted
name|png_uint_32
name|mng_features_permitted
decl_stmt|;
endif|#
directive|endif
comment|/* New member added in libpng-1.0.9, ifdef'ed out in 1.0.12, enabled in 1.2.0 */
ifdef|#
directive|ifdef
name|PNG_MNG_FEATURES_SUPPORTED
DECL|member|filter_type
name|png_byte
name|filter_type
decl_stmt|;
endif|#
directive|endif
comment|/* New members added in libpng-1.2.0 */
comment|/* New members added in libpng-1.0.2 but first enabled by default in 1.2.0 */
ifdef|#
directive|ifdef
name|PNG_USER_MEM_SUPPORTED
DECL|member|mem_ptr
name|png_voidp
name|mem_ptr
decl_stmt|;
comment|/* user supplied struct for mem functions */
DECL|member|malloc_fn
name|png_malloc_ptr
name|malloc_fn
decl_stmt|;
comment|/* function for allocating memory */
DECL|member|free_fn
name|png_free_ptr
name|free_fn
decl_stmt|;
comment|/* function for freeing memory */
endif|#
directive|endif
comment|/* New member added in libpng-1.0.13 and 1.2.0 */
DECL|member|big_row_buf
name|png_bytep
name|big_row_buf
decl_stmt|;
comment|/* buffer to save current (unfiltered) row */
ifdef|#
directive|ifdef
name|PNG_READ_QUANTIZE_SUPPORTED
comment|/* The following three members were added at version 1.0.14 and 1.2.4 */
DECL|member|quantize_sort
name|png_bytep
name|quantize_sort
decl_stmt|;
comment|/* working sort array */
DECL|member|index_to_palette
name|png_bytep
name|index_to_palette
decl_stmt|;
comment|/* where the original index currently is                                         in the palette */
DECL|member|palette_to_index
name|png_bytep
name|palette_to_index
decl_stmt|;
comment|/* which original index points to this                                          palette color */
endif|#
directive|endif
comment|/* New members added in libpng-1.0.16 and 1.2.6 */
DECL|member|compression_type
name|png_byte
name|compression_type
decl_stmt|;
ifdef|#
directive|ifdef
name|PNG_USER_LIMITS_SUPPORTED
DECL|member|user_width_max
name|png_uint_32
name|user_width_max
decl_stmt|;
DECL|member|user_height_max
name|png_uint_32
name|user_height_max
decl_stmt|;
comment|/* Added in libpng-1.4.0: Total number of sPLT, text, and unknown     * chunks that can be stored (0 means unlimited).     */
DECL|member|user_chunk_cache_max
name|png_uint_32
name|user_chunk_cache_max
decl_stmt|;
comment|/* Total memory that a zTXt, sPLT, iTXt, iCCP, or unknown chunk     * can occupy when decompressed.  0 means unlimited.     */
DECL|member|user_chunk_malloc_max
name|png_alloc_size_t
name|user_chunk_malloc_max
decl_stmt|;
endif|#
directive|endif
comment|/* New member added in libpng-1.0.25 and 1.2.17 */
ifdef|#
directive|ifdef
name|PNG_UNKNOWN_CHUNKS_SUPPORTED
comment|/* Storage for unknown chunk that the library doesn't recognize. */
DECL|member|unknown_chunk
name|png_unknown_chunk
name|unknown_chunk
decl_stmt|;
endif|#
directive|endif
comment|/* New members added in libpng-1.2.26 */
DECL|member|old_big_row_buf_size
name|png_size_t
name|old_big_row_buf_size
decl_stmt|;
DECL|member|old_prev_row_size
name|png_size_t
name|old_prev_row_size
decl_stmt|;
comment|/* New member added in libpng-1.2.30 */
DECL|member|chunkdata
name|png_charp
name|chunkdata
decl_stmt|;
comment|/* buffer for reading chunk data */
ifdef|#
directive|ifdef
name|PNG_IO_STATE_SUPPORTED
comment|/* New member added in libpng-1.4.0 */
DECL|member|io_state
name|png_uint_32
name|io_state
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PNGSTRUCT_H */
end_comment
end_unit
