begin_unit
begin_comment
comment|/* pnginfo.h - header file for PNG reference library  *  * Last changed in libpng 1.6.1 [March 28, 2013]  * Copyright (c) 1998-2013 Glenn Randers-Pehrson  * (Version 0.96 Copyright (c) 1996, 1997 Andreas Dilger)  * (Version 0.88 Copyright (c) 1995, 1996 Guy Eric Schalnat, Group 42, Inc.)  *  * This code is released under the libpng license.  * For conditions of distribution and use, see the disclaimer  * and license in png.h  */
end_comment
begin_comment
comment|/* png_info is a structure that holds the information in a PNG file so  * that the application can find out the characteristics of the image.  * If you are reading the file, this structure will tell you what is  * in the PNG file.  If you are writing the file, fill in the information  * you want to put into the PNG file, using png_set_*() functions, then  * call png_write_info().  *  * The names chosen should be very close to the PNG specification, so  * consult that document for information about the meaning of each field.  *  * With libpng< 0.95, it was only possible to directly set and read the  * the values in the png_info_struct, which meant that the contents and  * order of the values had to remain fixed.  With libpng 0.95 and later,  * however, there are now functions that abstract the contents of  * png_info_struct from the application, so this makes it easier to use  * libpng with dynamic libraries, and even makes it possible to use  * libraries that don't have all of the libpng ancillary chunk-handing  * functionality.  In libpng-1.5.0 this was moved into a separate private  * file that is not visible to applications.  *  * The following members may have allocated storage attached that should be  * cleaned up before the structure is discarded: palette, trans, text,  * pcal_purpose, pcal_units, pcal_params, hist, iccp_name, iccp_profile,  * splt_palettes, scal_unit, row_pointers, and unknowns.   By default, these  * are automatically freed when the info structure is deallocated, if they were  * allocated internally by libpng.  This behavior can be changed by means  * of the png_data_freer() function.  *  * More allocation details: all the chunk-reading functions that  * change these members go through the corresponding png_set_*  * functions.  A function to clear these members is available: see  * png_free_data().  The png_set_* functions do not depend on being  * able to point info structure members to any of the storage they are  * passed (they make their own copies), EXCEPT that the png_set_text  * functions use the same storage passed to them in the text_ptr or  * itxt_ptr structure argument, and the png_set_rows and png_set_unknowns  * functions do not make their own copies.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|PNGINFO_H
end_ifndef
begin_define
DECL|macro|PNGINFO_H
define|#
directive|define
name|PNGINFO_H
end_define
begin_struct
DECL|struct|png_info_def
struct|struct
name|png_info_def
block|{
comment|/* The following are necessary for every PNG file */
DECL|member|width
name|png_uint_32
name|width
decl_stmt|;
comment|/* width of image in pixels (from IHDR) */
DECL|member|height
name|png_uint_32
name|height
decl_stmt|;
comment|/* height of image in pixels (from IHDR) */
DECL|member|valid
name|png_uint_32
name|valid
decl_stmt|;
comment|/* valid chunk data (see PNG_INFO_ below) */
DECL|member|rowbytes
name|png_size_t
name|rowbytes
decl_stmt|;
comment|/* bytes needed to hold an untransformed row */
DECL|member|palette
name|png_colorp
name|palette
decl_stmt|;
comment|/* array of color values (valid& PNG_INFO_PLTE) */
DECL|member|num_palette
name|png_uint_16
name|num_palette
decl_stmt|;
comment|/* number of color entries in "palette" (PLTE) */
DECL|member|num_trans
name|png_uint_16
name|num_trans
decl_stmt|;
comment|/* number of transparent palette color (tRNS) */
DECL|member|bit_depth
name|png_byte
name|bit_depth
decl_stmt|;
comment|/* 1, 2, 4, 8, or 16 bits/channel (from IHDR) */
DECL|member|color_type
name|png_byte
name|color_type
decl_stmt|;
comment|/* see PNG_COLOR_TYPE_ below (from IHDR) */
comment|/* The following three should have been named *_method not *_type */
DECL|member|compression_type
name|png_byte
name|compression_type
decl_stmt|;
comment|/* must be PNG_COMPRESSION_TYPE_BASE (IHDR) */
DECL|member|filter_type
name|png_byte
name|filter_type
decl_stmt|;
comment|/* must be PNG_FILTER_TYPE_BASE (from IHDR) */
DECL|member|interlace_type
name|png_byte
name|interlace_type
decl_stmt|;
comment|/* One of PNG_INTERLACE_NONE, PNG_INTERLACE_ADAM7 */
comment|/* The following are set by png_set_IHDR, called from the application on     * write, but the are never actually used by the write code.     */
DECL|member|channels
name|png_byte
name|channels
decl_stmt|;
comment|/* number of data channels per pixel (1, 2, 3, 4) */
DECL|member|pixel_depth
name|png_byte
name|pixel_depth
decl_stmt|;
comment|/* number of bits per pixel */
DECL|member|spare_byte
name|png_byte
name|spare_byte
decl_stmt|;
comment|/* to align the data, and for future use */
ifdef|#
directive|ifdef
name|PNG_READ_SUPPORTED
comment|/* This is never set during write */
DECL|member|signature
name|png_byte
name|signature
index|[
literal|8
index|]
decl_stmt|;
comment|/* magic bytes read by libpng from start of file */
endif|#
directive|endif
comment|/* The rest of the data is optional.  If you are reading, check the     * valid field to see if the information in these are valid.  If you     * are writing, set the valid field to those chunks you want written,     * and initialize the appropriate fields below.     */
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
comment|/* png_colorspace only contains 'flags' if neither GAMMA or COLORSPACE are     * defined.  When COLORSPACE is switched on all the colorspace-defining     * chunks should be enabled, when GAMMA is switched on all the gamma-defining     * chunks should be enabled.  If this is not done it becomes possible to read     * inconsistent PNG files and assign a probably incorrect interpretation to     * the information.  (In other words, by carefully choosing which chunks to     * recognize the system configuration can select an interpretation for PNG     * files containing ambiguous data and this will result in inconsistent     * behavior between different libpng builds!)     */
DECL|member|colorspace
name|png_colorspace
name|colorspace
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_iCCP_SUPPORTED
comment|/* iCCP chunk data. */
DECL|member|iccp_name
name|png_charp
name|iccp_name
decl_stmt|;
comment|/* profile name */
DECL|member|iccp_profile
name|png_bytep
name|iccp_profile
decl_stmt|;
comment|/* International Color Consortium profile data */
DECL|member|iccp_proflen
name|png_uint_32
name|iccp_proflen
decl_stmt|;
comment|/* ICC profile data length */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_TEXT_SUPPORTED
comment|/* The tEXt, and zTXt chunks contain human-readable textual data in     * uncompressed, compressed, and optionally compressed forms, respectively.     * The data in "text" is an array of pointers to uncompressed,     * null-terminated C strings. Each chunk has a keyword that describes the     * textual data contained in that chunk.  Keywords are not required to be     * unique, and the text string may be empty.  Any number of text chunks may     * be in an image.     */
DECL|member|num_text
name|int
name|num_text
decl_stmt|;
comment|/* number of comments read or comments to write */
DECL|member|max_text
name|int
name|max_text
decl_stmt|;
comment|/* current size of text array */
DECL|member|text
name|png_textp
name|text
decl_stmt|;
comment|/* array of comments read or comments to write */
endif|#
directive|endif
comment|/* TEXT */
ifdef|#
directive|ifdef
name|PNG_tIME_SUPPORTED
comment|/* The tIME chunk holds the last time the displayed image data was     * modified.  See the png_time struct for the contents of this struct.     */
DECL|member|mod_time
name|png_time
name|mod_time
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_sBIT_SUPPORTED
comment|/* The sBIT chunk specifies the number of significant high-order bits     * in the pixel data.  Values are in the range [1, bit_depth], and are     * only specified for the channels in the pixel data.  The contents of     * the low-order bits is not specified.  Data is valid if     * (valid& PNG_INFO_sBIT) is non-zero.     */
DECL|member|sig_bit
name|png_color_8
name|sig_bit
decl_stmt|;
comment|/* significant bits in color channels */
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
name|PNG_READ_EXPAND_SUPPORTED
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|PNG_READ_BACKGROUND_SUPPORTED
argument_list|)
comment|/* The tRNS chunk supplies transparency data for paletted images and     * other image types that don't need a full alpha channel.  There are     * "num_trans" transparency values for a paletted image, stored in the     * same order as the palette colors, starting from index 0.  Values     * for the data are in the range [0, 255], ranging from fully transparent     * to fully opaque, respectively.  For non-paletted images, there is a     * single color specified that should be treated as fully transparent.     * Data is valid if (valid& PNG_INFO_tRNS) is non-zero.     */
DECL|member|trans_alpha
name|png_bytep
name|trans_alpha
decl_stmt|;
comment|/* alpha values for paletted image */
DECL|member|trans_color
name|png_color_16
name|trans_color
decl_stmt|;
comment|/* transparent color for non-palette image */
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
comment|/* The bKGD chunk gives the suggested image background color if the     * display program does not have its own background color and the image     * is needs to composited onto a background before display.  The colors     * in "background" are normally in the same color space/depth as the     * pixel data.  Data is valid if (valid& PNG_INFO_bKGD) is non-zero.     */
DECL|member|background
name|png_color_16
name|background
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_oFFs_SUPPORTED
comment|/* The oFFs chunk gives the offset in "offset_unit_type" units rightwards     * and downwards from the top-left corner of the display, page, or other     * application-specific co-ordinate space.  See the PNG_OFFSET_ defines     * below for the unit types.  Valid if (valid& PNG_INFO_oFFs) non-zero.     */
DECL|member|x_offset
name|png_int_32
name|x_offset
decl_stmt|;
comment|/* x offset on page */
DECL|member|y_offset
name|png_int_32
name|y_offset
decl_stmt|;
comment|/* y offset on page */
DECL|member|offset_unit_type
name|png_byte
name|offset_unit_type
decl_stmt|;
comment|/* offset units type */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_pHYs_SUPPORTED
comment|/* The pHYs chunk gives the physical pixel density of the image for     * display or printing in "phys_unit_type" units (see PNG_RESOLUTION_     * defines below).  Data is valid if (valid& PNG_INFO_pHYs) is non-zero.     */
DECL|member|x_pixels_per_unit
name|png_uint_32
name|x_pixels_per_unit
decl_stmt|;
comment|/* horizontal pixel density */
DECL|member|y_pixels_per_unit
name|png_uint_32
name|y_pixels_per_unit
decl_stmt|;
comment|/* vertical pixel density */
DECL|member|phys_unit_type
name|png_byte
name|phys_unit_type
decl_stmt|;
comment|/* resolution type (see PNG_RESOLUTION_ below) */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_hIST_SUPPORTED
comment|/* The hIST chunk contains the relative frequency or importance of the     * various palette entries, so that a viewer can intelligently select a     * reduced-color palette, if required.  Data is an array of "num_palette"     * values in the range [0,65535]. Data valid if (valid& PNG_INFO_hIST)     * is non-zero.     */
DECL|member|hist
name|png_uint_16p
name|hist
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_pCAL_SUPPORTED
comment|/* The pCAL chunk describes a transformation between the stored pixel     * values and original physical data values used to create the image.     * The integer range [0, 2^bit_depth - 1] maps to the floating-point     * range given by [pcal_X0, pcal_X1], and are further transformed by a     * (possibly non-linear) transformation function given by "pcal_type"     * and "pcal_params" into "pcal_units".  Please see the PNG_EQUATION_     * defines below, and the PNG-Group's PNG extensions document for a     * complete description of the transformations and how they should be     * implemented, and for a description of the ASCII parameter strings.     * Data values are valid if (valid& PNG_INFO_pCAL) non-zero.     */
DECL|member|pcal_purpose
name|png_charp
name|pcal_purpose
decl_stmt|;
comment|/* pCAL chunk description string */
DECL|member|pcal_X0
name|png_int_32
name|pcal_X0
decl_stmt|;
comment|/* minimum value */
DECL|member|pcal_X1
name|png_int_32
name|pcal_X1
decl_stmt|;
comment|/* maximum value */
DECL|member|pcal_units
name|png_charp
name|pcal_units
decl_stmt|;
comment|/* Latin-1 string giving physical units */
DECL|member|pcal_params
name|png_charpp
name|pcal_params
decl_stmt|;
comment|/* ASCII strings containing parameter values */
DECL|member|pcal_type
name|png_byte
name|pcal_type
decl_stmt|;
comment|/* equation type (see PNG_EQUATION_ below) */
DECL|member|pcal_nparams
name|png_byte
name|pcal_nparams
decl_stmt|;
comment|/* number of parameters given in pcal_params */
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
name|PNG_STORE_UNKNOWN_CHUNKS_SUPPORTED
comment|/* Storage for unknown chunks that the library doesn't recognize. */
DECL|member|unknown_chunks
name|png_unknown_chunkp
name|unknown_chunks
decl_stmt|;
comment|/* The type of this field is limited by the type of      * png_struct::user_chunk_cache_max, else overflow can occur.     */
DECL|member|unknown_chunks_num
name|int
name|unknown_chunks_num
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_sPLT_SUPPORTED
comment|/* Data on sPLT chunks (there may be more than one). */
DECL|member|splt_palettes
name|png_sPLT_tp
name|splt_palettes
decl_stmt|;
DECL|member|splt_palettes_num
name|int
name|splt_palettes_num
decl_stmt|;
comment|/* Match type returned by png_get API */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_sCAL_SUPPORTED
comment|/* The sCAL chunk describes the actual physical dimensions of the     * subject matter of the graphic.  The chunk contains a unit specification     * a byte value, and two ASCII strings representing floating-point     * values.  The values are width and height corresponsing to one pixel     * in the image.  Data values are valid if (valid& PNG_INFO_sCAL) is     * non-zero.     */
DECL|member|scal_unit
name|png_byte
name|scal_unit
decl_stmt|;
comment|/* unit of physical scale */
DECL|member|scal_s_width
name|png_charp
name|scal_s_width
decl_stmt|;
comment|/* string containing height */
DECL|member|scal_s_height
name|png_charp
name|scal_s_height
decl_stmt|;
comment|/* string containing width */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PNG_INFO_IMAGE_SUPPORTED
comment|/* Memory has been allocated if (valid& PNG_ALLOCATED_INFO_ROWS)       non-zero */
comment|/* Data valid if (valid& PNG_INFO_IDAT) non-zero */
DECL|member|row_pointers
name|png_bytepp
name|row_pointers
decl_stmt|;
comment|/* the image bits */
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
comment|/* PNGINFO_H */
end_comment
end_unit
