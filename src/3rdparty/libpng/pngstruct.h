begin_unit
begin_comment
comment|/* pngstruct.h - header file for PNG reference library  *  * Last changed in libpng 1.6.1 [March 28, 2013]  * Copyright (c) 1998-2013 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  */
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
begin_ifndef
ifndef|#
directive|ifndef
name|ZLIB_CONST
end_ifndef
begin_comment
comment|/* We must ensure that zlib uses 'const' in declarations. */
end_comment
begin_define
DECL|macro|ZLIB_CONST
define|#
directive|define
name|ZLIB_CONST
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"zlib.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|const
end_ifdef
begin_comment
comment|/* zlib.h sometimes #defines const to nothing, undo this. */
end_comment
begin_undef
DECL|macro|const
undef|#
directive|undef
name|const
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* zlib.h has mediocre z_const use before 1.2.6, this stuff is for compatibility  * with older builds.  */
end_comment
begin_if
if|#
directive|if
name|ZLIB_VERNUM
operator|<
literal|0x1260
end_if
begin_define
DECL|macro|PNGZ_MSG_CAST
define|#
directive|define
name|PNGZ_MSG_CAST
parameter_list|(
name|s
parameter_list|)
value|png_constcast(char*,s)
end_define
begin_define
DECL|macro|PNGZ_INPUT_CAST
define|#
directive|define
name|PNGZ_INPUT_CAST
parameter_list|(
name|b
parameter_list|)
value|png_constcast(png_bytep,b)
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|PNGZ_MSG_CAST
define|#
directive|define
name|PNGZ_MSG_CAST
parameter_list|(
name|s
parameter_list|)
value|(s)
end_define
begin_define
DECL|macro|PNGZ_INPUT_CAST
define|#
directive|define
name|PNGZ_INPUT_CAST
parameter_list|(
name|b
parameter_list|)
value|(b)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* zlib.h declares a magic type 'uInt' that limits the amount of data that zlib  * can handle at once.  This type need be no larger than 16 bits (so maximum of  * 65535), this define allows us to discover how big it is, but limited by the  * maximuum for png_size_t.  The value can be overriden in a library build  * (pngusr.h, or set it in CPPFLAGS) and it works to set it to a considerably  * lower value (e.g. 255 works).  A lower value may help memory usage (slightly)  * and may even improve performance on some systems (and degrade it on others.)  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ZLIB_IO_MAX
end_ifndef
begin_define
DECL|macro|ZLIB_IO_MAX
define|#
directive|define
name|ZLIB_IO_MAX
value|((uInt)-1)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
end_ifdef
begin_comment
comment|/* The type of a compression buffer list used by the write code. */
end_comment
begin_typedef
DECL|struct|png_compression_buffer
typedef|typedef
struct|struct
name|png_compression_buffer
block|{
DECL|member|next
name|struct
name|png_compression_buffer
modifier|*
name|next
decl_stmt|;
DECL|member|output
name|png_byte
name|output
index|[
literal|1
index|]
decl_stmt|;
comment|/* actually zbuf_size */
block|}
DECL|typedef|png_compression_buffer
DECL|typedef|png_compression_bufferp
name|png_compression_buffer
operator|,
typedef|*
name|png_compression_bufferp
typedef|;
end_typedef
begin_define
DECL|macro|PNG_COMPRESSION_BUFFER_SIZE
define|#
directive|define
name|PNG_COMPRESSION_BUFFER_SIZE
parameter_list|(
name|pp
parameter_list|)
define|\
value|(offsetof(png_compression_buffer, output) + (pp)->zbuffer_size)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Colorspace support; structures used in png_struct, png_info and in internal  * functions to hold and communicate information about the color space.  *  * PNG_COLORSPACE_SUPPORTED is only required if the application will perform  * colorspace corrections, otherwise all the colorspace information can be  * skipped and the size of libpng can be reduced (significantly) by compiling  * out the colorspace support.  */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|PNG_COLORSPACE_SUPPORTED
end_ifdef
begin_comment
comment|/* The chromaticities of the red, green and blue colorants and the chromaticity  * of the corresponding white point (i.e. of rgb(1.0,1.0,1.0)).  */
end_comment
begin_typedef
DECL|struct|png_xy
typedef|typedef
struct|struct
name|png_xy
block|{
DECL|member|redx
DECL|member|redy
name|png_fixed_point
name|redx
decl_stmt|,
name|redy
decl_stmt|;
DECL|member|greenx
DECL|member|greeny
name|png_fixed_point
name|greenx
decl_stmt|,
name|greeny
decl_stmt|;
DECL|member|bluex
DECL|member|bluey
name|png_fixed_point
name|bluex
decl_stmt|,
name|bluey
decl_stmt|;
DECL|member|whitex
DECL|member|whitey
name|png_fixed_point
name|whitex
decl_stmt|,
name|whitey
decl_stmt|;
block|}
DECL|typedef|png_xy
name|png_xy
typedef|;
end_typedef
begin_comment
comment|/* The same data as above but encoded as CIE XYZ values.  When this data comes  * from chromaticities the sum of the Y values is assumed to be 1.0  */
end_comment
begin_typedef
DECL|struct|png_XYZ
typedef|typedef
struct|struct
name|png_XYZ
block|{
DECL|member|red_X
DECL|member|red_Y
DECL|member|red_Z
name|png_fixed_point
name|red_X
decl_stmt|,
name|red_Y
decl_stmt|,
name|red_Z
decl_stmt|;
DECL|member|green_X
DECL|member|green_Y
DECL|member|green_Z
name|png_fixed_point
name|green_X
decl_stmt|,
name|green_Y
decl_stmt|,
name|green_Z
decl_stmt|;
DECL|member|blue_X
DECL|member|blue_Y
DECL|member|blue_Z
name|png_fixed_point
name|blue_X
decl_stmt|,
name|blue_Y
decl_stmt|,
name|blue_Z
decl_stmt|;
block|}
DECL|typedef|png_XYZ
name|png_XYZ
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* COLORSPACE */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PNG_COLORSPACE_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_GAMMA_SUPPORTED
argument_list|)
end_if
begin_comment
comment|/* A colorspace is all the above plus, potentially, profile information;  * however at present libpng does not use the profile internally so it is only  * stored in the png_info struct (if iCCP is supported.)  The rendering intent  * is retained here and is checked.  *  * The file gamma encoding information is also stored here and gamma correction  * is done by libpng, whereas color correction must currently be done by the  * application.  */
end_comment
begin_typedef
DECL|struct|png_colorspace
typedef|typedef
struct|struct
name|png_colorspace
block|{
ifdef|#
directive|ifdef
name|PNG_GAMMA_SUPPORTED
DECL|member|gamma
name|png_fixed_point
name|gamma
decl_stmt|;
comment|/* File gamma */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_COLORSPACE_SUPPORTED
DECL|member|end_points_xy
name|png_xy
name|end_points_xy
decl_stmt|;
comment|/* End points as chromaticities */
DECL|member|end_points_XYZ
name|png_XYZ
name|end_points_XYZ
decl_stmt|;
comment|/* End points as CIE XYZ colorant values */
DECL|member|rendering_intent
name|png_uint_16
name|rendering_intent
decl_stmt|;
comment|/* Rendering intent of a profile */
endif|#
directive|endif
comment|/* Flags are always defined to simplify the code. */
DECL|member|flags
name|png_uint_16
name|flags
decl_stmt|;
comment|/* As defined below */
block|}
DECL|typedef|png_colorspace
DECL|typedef|png_colorspacerp
name|png_colorspace
operator|,
typedef|*
name|PNG_RESTRICT
name|png_colorspacerp
typedef|;
end_typedef
begin_typedef
DECL|typedef|png_const_colorspacerp
typedef|typedef
specifier|const
name|png_colorspace
modifier|*
name|PNG_RESTRICT
name|png_const_colorspacerp
typedef|;
end_typedef
begin_comment
comment|/* General flags for the 'flags' field */
end_comment
begin_define
DECL|macro|PNG_COLORSPACE_HAVE_GAMMA
define|#
directive|define
name|PNG_COLORSPACE_HAVE_GAMMA
value|0x0001
end_define
begin_define
DECL|macro|PNG_COLORSPACE_HAVE_ENDPOINTS
define|#
directive|define
name|PNG_COLORSPACE_HAVE_ENDPOINTS
value|0x0002
end_define
begin_define
DECL|macro|PNG_COLORSPACE_HAVE_INTENT
define|#
directive|define
name|PNG_COLORSPACE_HAVE_INTENT
value|0x0004
end_define
begin_define
DECL|macro|PNG_COLORSPACE_FROM_gAMA
define|#
directive|define
name|PNG_COLORSPACE_FROM_gAMA
value|0x0008
end_define
begin_define
DECL|macro|PNG_COLORSPACE_FROM_cHRM
define|#
directive|define
name|PNG_COLORSPACE_FROM_cHRM
value|0x0010
end_define
begin_define
DECL|macro|PNG_COLORSPACE_FROM_sRGB
define|#
directive|define
name|PNG_COLORSPACE_FROM_sRGB
value|0x0020
end_define
begin_define
DECL|macro|PNG_COLORSPACE_ENDPOINTS_MATCH_sRGB
define|#
directive|define
name|PNG_COLORSPACE_ENDPOINTS_MATCH_sRGB
value|0x0040
end_define
begin_define
DECL|macro|PNG_COLORSPACE_MATCHES_sRGB
define|#
directive|define
name|PNG_COLORSPACE_MATCHES_sRGB
value|0x0080
end_define
begin_comment
DECL|macro|PNG_COLORSPACE_MATCHES_sRGB
comment|/* exact match on profile */
end_comment
begin_define
DECL|macro|PNG_COLORSPACE_INVALID
define|#
directive|define
name|PNG_COLORSPACE_INVALID
value|0x8000
end_define
begin_define
DECL|macro|PNG_COLORSPACE_CANCEL
define|#
directive|define
name|PNG_COLORSPACE_CANCEL
parameter_list|(
name|flags
parameter_list|)
value|(0xffff ^ (flags))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* COLORSPACE || GAMMA */
end_comment
begin_struct
DECL|struct|png_struct_def
struct|struct
name|png_struct_def
block|{
ifdef|#
directive|ifdef
name|PNG_SETJMP_SUPPORTED
DECL|member|jmp_buf_local
name|jmp_buf
name|jmp_buf_local
decl_stmt|;
comment|/* New name in 1.6.0 for jmp_buf in png_struct */
DECL|member|longjmp_fn
name|png_longjmp_ptr
name|longjmp_fn
decl_stmt|;
comment|/* setjmp non-local goto function. */
DECL|member|jmp_buf_ptr
name|jmp_buf
modifier|*
name|jmp_buf_ptr
decl_stmt|;
comment|/* passed to longjmp_fn */
DECL|member|jmp_buf_size
name|size_t
name|jmp_buf_size
decl_stmt|;
comment|/* size of the above, if allocated */
endif|#
directive|endif
DECL|member|error_fn
name|png_error_ptr
name|error_fn
decl_stmt|;
comment|/* function for printing errors and aborting */
ifdef|#
directive|ifdef
name|PNG_WARNINGS_SUPPORTED
DECL|member|warning_fn
name|png_error_ptr
name|warning_fn
decl_stmt|;
comment|/* function for printing warnings */
endif|#
directive|endif
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
DECL|member|zowner
name|png_uint_32
name|zowner
decl_stmt|;
comment|/* ID (chunk type) of zstream owner, 0 if none */
DECL|member|zstream
name|z_stream
name|zstream
decl_stmt|;
comment|/* decompression structure */
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
DECL|member|zbuffer_list
name|png_compression_bufferp
name|zbuffer_list
decl_stmt|;
comment|/* Created on demand during write */
DECL|member|zbuffer_size
name|uInt
name|zbuffer_size
decl_stmt|;
comment|/* size of the actual buffer */
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
endif|#
directive|endif
comment|/* Added at libpng 1.5.4 */
ifdef|#
directive|ifdef
name|PNG_WRITE_CUSTOMIZE_ZTXT_COMPRESSION_SUPPORTED
DECL|member|zlib_text_level
name|int
name|zlib_text_level
decl_stmt|;
comment|/* holds zlib compression level */
DECL|member|zlib_text_method
name|int
name|zlib_text_method
decl_stmt|;
comment|/* holds zlib compression method */
DECL|member|zlib_text_window_bits
name|int
name|zlib_text_window_bits
decl_stmt|;
comment|/* holds zlib compression window bits */
DECL|member|zlib_text_mem_level
name|int
name|zlib_text_mem_level
decl_stmt|;
comment|/* holds zlib compression memory level */
DECL|member|zlib_text_strategy
name|int
name|zlib_text_strategy
decl_stmt|;
comment|/* holds zlib compression strategy */
endif|#
directive|endif
comment|/* End of material added at libpng 1.5.4 */
comment|/* Added at libpng 1.6.0 */
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
DECL|member|zlib_set_level
name|int
name|zlib_set_level
decl_stmt|;
comment|/* Actual values set into the zstream on write */
DECL|member|zlib_set_method
name|int
name|zlib_set_method
decl_stmt|;
DECL|member|zlib_set_window_bits
name|int
name|zlib_set_window_bits
decl_stmt|;
DECL|member|zlib_set_mem_level
name|int
name|zlib_set_mem_level
decl_stmt|;
DECL|member|zlib_set_strategy
name|int
name|zlib_set_strategy
decl_stmt|;
endif|#
directive|endif
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
DECL|member|chunk_name
name|png_uint_32
name|chunk_name
decl_stmt|;
comment|/* PNG_CHUNK() id of current chunk */
DECL|member|prev_row
name|png_bytep
name|prev_row
decl_stmt|;
comment|/* buffer to save previous (unfiltered) row.                                * This is a pointer into big_prev_row                                */
DECL|member|row_buf
name|png_bytep
name|row_buf
decl_stmt|;
comment|/* buffer to save current (unfiltered) row.                                * This is a pointer into big_row_buf                                */
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
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
endif|#
directive|endif
DECL|member|info_rowbytes
name|png_size_t
name|info_rowbytes
decl_stmt|;
comment|/* Added in 1.5.4: cache of updated row bytes */
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
comment|/* Added at libpng-1.5.10 */
ifdef|#
directive|ifdef
name|PNG_CHECK_FOR_INVALID_INDEX_SUPPORTED
DECL|member|num_palette_max
name|int
name|num_palette_max
decl_stmt|;
comment|/* maximum palette index found in IDAT */
endif|#
directive|endif
DECL|member|num_trans
name|png_uint_16
name|num_trans
decl_stmt|;
comment|/* number of transparency values */
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
comment|/* bit depth of users row: write only */
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
ifdef|#
directive|ifdef
name|PNG_WRITE_SUPPORTED
DECL|member|usr_channels
name|png_byte
name|usr_channels
decl_stmt|;
comment|/* channels at start of write: write only */
endif|#
directive|endif
DECL|member|sig_bytes
name|png_byte
name|sig_bytes
decl_stmt|;
comment|/* magic bytes read/written from start of file */
DECL|member|maximum_pixel_depth
name|png_byte
name|maximum_pixel_depth
decl_stmt|;
comment|/* pixel depth used for the row buffers */
DECL|member|transformed_pixel_depth
name|png_byte
name|transformed_pixel_depth
decl_stmt|;
comment|/* pixel depth after read/write transforms */
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
if|#
directive|if
name|defined
argument_list|(
name|PNG_bKGD_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_READ_ALPHA_MODE_SUPPORTED
argument_list|)
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
comment|/* bKGD */
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
ifdef|#
directive|ifdef
name|PNG_READ_GAMMA_SUPPORTED
DECL|member|gamma_shift
name|int
name|gamma_shift
decl_stmt|;
comment|/* number of "insignificant" bits in 16-bit gamma */
DECL|member|screen_gamma
name|png_fixed_point
name|screen_gamma
decl_stmt|;
comment|/* screen gamma value (display_exponent) */
DECL|member|gamma_table
name|png_bytep
name|gamma_table
decl_stmt|;
comment|/* gamma table for 8-bit depth files */
DECL|member|gamma_16_table
name|png_uint_16pp
name|gamma_16_table
decl_stmt|;
comment|/* gamma table for 16-bit depth files */
if|#
directive|if
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_READ_ALPHA_MODE_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_READ_RGB_TO_GRAY_SUPPORTED
argument_list|)
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
comment|/* READ_BACKGROUND || READ_ALPHA_MODE || RGB_TO_GRAY */
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
endif|#
directive|endif
comment|/* PROGRESSIVE_READ */
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
comment|/* Options */
ifdef|#
directive|ifdef
name|PNG_SET_OPTION_SUPPORTED
DECL|member|options
name|png_byte
name|options
decl_stmt|;
comment|/* On/off state (up to 4 options) */
endif|#
directive|endif
if|#
directive|if
name|PNG_LIBPNG_VER
operator|<
literal|10700
comment|/* To do: remove this from libpng-1.7 */
ifdef|#
directive|ifdef
name|PNG_TIME_RFC1123_SUPPORTED
DECL|member|time_buffer
name|char
name|time_buffer
index|[
literal|29
index|]
decl_stmt|;
comment|/* String to hold RFC 1123 time text */
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|PNG_READ_USER_CHUNKS_SUPPORTED
DECL|member|read_user_chunk_fn
name|png_user_chunk_ptr
name|read_user_chunk_fn
decl_stmt|;
comment|/* user read chunk handler */
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_SET_UNKNOWN_CHUNKS_SUPPORTED
DECL|member|unknown_default
name|int
name|unknown_default
decl_stmt|;
comment|/* As PNG_HANDLE_* */
DECL|member|num_chunk_list
name|unsigned
name|int
name|num_chunk_list
decl_stmt|;
comment|/* Number of entries in the list */
DECL|member|chunk_list
name|png_bytep
name|chunk_list
decl_stmt|;
comment|/* List of png_byte[5]; the textual chunk name                                   * followed by a PNG_HANDLE_* byte */
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
comment|/* Added in libpng 1.5.5 to record setting of coefficients: */
DECL|member|rgb_to_gray_coefficients_set
name|png_byte
name|rgb_to_gray_coefficients_set
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
comment|/* deleted in 1.5.5: rgb_to_gray_blue_coeff; */
endif|#
directive|endif
comment|/* New member added in libpng-1.0.4 (renamed in 1.0.9) */
if|#
directive|if
name|defined
argument_list|(
name|PNG_MNG_FEATURES_SUPPORTED
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
name|PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
comment|/* Temporary storage for unknown chunk that the library doesn't recognize,     * used while reading the chunk.     */
DECL|member|unknown_chunk
name|png_unknown_chunk
name|unknown_chunk
decl_stmt|;
endif|#
directive|endif
comment|/* New member added in libpng-1.2.26 */
DECL|member|old_big_row_buf_size
name|png_size_t
name|old_big_row_buf_size
decl_stmt|;
ifdef|#
directive|ifdef
name|PNG_READ_SUPPORTED
comment|/* New member added in libpng-1.2.30 */
DECL|member|read_buffer
name|png_bytep
name|read_buffer
decl_stmt|;
comment|/* buffer for reading chunk data */
DECL|member|read_buffer_size
name|png_alloc_size_t
name|read_buffer_size
decl_stmt|;
comment|/* current size of the buffer */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_SEQUENTIAL_READ_SUPPORTED
DECL|member|IDAT_read_size
name|uInt
name|IDAT_read_size
decl_stmt|;
comment|/* limit on read buffer size for IDAT */
endif|#
directive|endif
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
comment|/* New member added in libpng-1.5.6 */
DECL|member|big_prev_row
name|png_bytep
name|big_prev_row
decl_stmt|;
comment|/* New member added in libpng-1.5.7 */
DECL|member|read_filter
name|void
function_decl|(
modifier|*
name|read_filter
index|[
name|PNG_FILTER_VALUE_LAST
operator|-
literal|1
index|]
function_decl|)
parameter_list|(
name|png_row_infop
name|row_info
parameter_list|,
name|png_bytep
name|row
parameter_list|,
name|png_const_bytep
name|prev_row
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|PNG_READ_SUPPORTED
if|#
directive|if
name|defined
argument_list|(
name|PNG_COLORSPACE_SUPPORTED
argument_list|)
operator|||
name|defined
argument_list|(
name|PNG_GAMMA_SUPPORTED
argument_list|)
DECL|member|colorspace
name|png_colorspace
name|colorspace
decl_stmt|;
endif|#
directive|endif
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
