begin_unit
begin_comment
comment|/*  * jpeglib.h  *  * Copyright (C) 1991-1998, Thomas G. Lane.  * Modified 2002-2010 by Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file defines the application interface for the JPEG library.  * Most applications using the library need only include this file,  * and perhaps jerror.h if they want to know the exact error codes.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|JPEGLIB_H
end_ifndef
begin_define
DECL|macro|JPEGLIB_H
define|#
directive|define
name|JPEGLIB_H
end_define
begin_comment
comment|/*  * First we include the configuration files that record how this  * installation of the JPEG library is set up.  jconfig.h can be  * generated automatically for many systems.  jmorecfg.h contains  * manual configuration options that most people need not worry about.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|JCONFIG_INCLUDED
end_ifndef
begin_comment
comment|/* in case jinclude.h already did */
end_comment
begin_include
include|#
directive|include
file|"jconfig.h"
end_include
begin_comment
comment|/* widely used configuration options */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"jmorecfg.h"
end_include
begin_comment
comment|/* seldom changed options */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|DONT_USE_EXTERN_C
end_ifndef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
endif|#
directive|endif
comment|/* Version IDs for the JPEG library.  * Might be useful for tests like "#if JPEG_LIB_VERSION>= 80".  */
DECL|macro|JPEG_LIB_VERSION
define|#
directive|define
name|JPEG_LIB_VERSION
value|80
comment|/* Compatibility version 8.0 */
DECL|macro|JPEG_LIB_VERSION_MAJOR
define|#
directive|define
name|JPEG_LIB_VERSION_MAJOR
value|8
DECL|macro|JPEG_LIB_VERSION_MINOR
define|#
directive|define
name|JPEG_LIB_VERSION_MINOR
value|3
comment|/* Various constants determining the sizes of things.  * All of these are specified by the JPEG standard, so don't change them  * if you want to be compatible.  */
DECL|macro|DCTSIZE
define|#
directive|define
name|DCTSIZE
value|8
comment|/* The basic DCT block is 8x8 samples */
DECL|macro|DCTSIZE2
define|#
directive|define
name|DCTSIZE2
value|64
comment|/* DCTSIZE squared; # of elements in a block */
DECL|macro|NUM_QUANT_TBLS
define|#
directive|define
name|NUM_QUANT_TBLS
value|4
comment|/* Quantization tables are numbered 0..3 */
DECL|macro|NUM_HUFF_TBLS
define|#
directive|define
name|NUM_HUFF_TBLS
value|4
comment|/* Huffman tables are numbered 0..3 */
DECL|macro|NUM_ARITH_TBLS
define|#
directive|define
name|NUM_ARITH_TBLS
value|16
comment|/* Arith-coding tables are numbered 0..15 */
DECL|macro|MAX_COMPS_IN_SCAN
define|#
directive|define
name|MAX_COMPS_IN_SCAN
value|4
comment|/* JPEG limit on # of components in one scan */
DECL|macro|MAX_SAMP_FACTOR
define|#
directive|define
name|MAX_SAMP_FACTOR
value|4
comment|/* JPEG limit on sampling factors */
comment|/* Unfortunately, some bozo at Adobe saw no reason to be bound by the standard;  * the PostScript DCT filter can emit files with many more than 10 blocks/MCU.  * If you happen to run across such a file, you can up D_MAX_BLOCKS_IN_MCU  * to handle it.  We even let you do this from the jconfig.h file.  However,  * we strongly discourage changing C_MAX_BLOCKS_IN_MCU; just because Adobe  * sometimes emits noncompliant files doesn't mean you should too.  */
DECL|macro|C_MAX_BLOCKS_IN_MCU
define|#
directive|define
name|C_MAX_BLOCKS_IN_MCU
value|10
comment|/* compressor's limit on blocks per MCU */
ifndef|#
directive|ifndef
name|D_MAX_BLOCKS_IN_MCU
DECL|macro|D_MAX_BLOCKS_IN_MCU
define|#
directive|define
name|D_MAX_BLOCKS_IN_MCU
value|10
comment|/* decompressor's limit on blocks per MCU */
endif|#
directive|endif
comment|/* Data structures for images (arrays of samples and of DCT coefficients).  * On 80x86 machines, the image arrays are too big for near pointers,  * but the pointer arrays can fit in near memory.  */
DECL|typedef|JSAMPROW
typedef|typedef
name|JSAMPLE
name|FAR
modifier|*
name|JSAMPROW
typedef|;
comment|/* ptr to one image row of pixel samples. */
DECL|typedef|JSAMPARRAY
typedef|typedef
name|JSAMPROW
modifier|*
name|JSAMPARRAY
typedef|;
comment|/* ptr to some rows (a 2-D sample array) */
DECL|typedef|JSAMPIMAGE
typedef|typedef
name|JSAMPARRAY
modifier|*
name|JSAMPIMAGE
typedef|;
comment|/* a 3-D sample array: top index is color */
DECL|typedef|JBLOCK
typedef|typedef
name|JCOEF
name|JBLOCK
index|[
name|DCTSIZE2
index|]
typedef|;
comment|/* one block of coefficients */
DECL|typedef|JBLOCKROW
typedef|typedef
name|JBLOCK
name|FAR
modifier|*
name|JBLOCKROW
typedef|;
comment|/* pointer to one row of coefficient blocks */
DECL|typedef|JBLOCKARRAY
typedef|typedef
name|JBLOCKROW
modifier|*
name|JBLOCKARRAY
typedef|;
comment|/* a 2-D array of coefficient blocks */
DECL|typedef|JBLOCKIMAGE
typedef|typedef
name|JBLOCKARRAY
modifier|*
name|JBLOCKIMAGE
typedef|;
comment|/* a 3-D array of coefficient blocks */
DECL|typedef|JCOEFPTR
typedef|typedef
name|JCOEF
name|FAR
modifier|*
name|JCOEFPTR
typedef|;
comment|/* useful in a couple of places */
comment|/* Types for JPEG compression parameters and working tables. */
comment|/* DCT coefficient quantization tables. */
typedef|typedef
struct|struct
block|{
comment|/* This array gives the coefficient quantizers in natural array order    * (not the zigzag order in which they are stored in a JPEG DQT marker).    * CAUTION: IJG versions prior to v6a kept this array in zigzag order.    */
DECL|member|quantval
name|UINT16
name|quantval
index|[
name|DCTSIZE2
index|]
decl_stmt|;
comment|/* quantization step for each coefficient */
comment|/* This field is used only during compression.  It's initialized FALSE when    * the table is created, and set TRUE when it's been output to the file.    * You could suppress output of a table by setting this to TRUE.    * (See jpeg_suppress_tables for an example.)    */
DECL|member|sent_table
name|boolean
name|sent_table
decl_stmt|;
comment|/* TRUE when table has been output */
block|}
DECL|typedef|JQUANT_TBL
name|JQUANT_TBL
typedef|;
comment|/* Huffman coding tables. */
typedef|typedef
struct|struct
block|{
comment|/* These two fields directly represent the contents of a JPEG DHT marker */
DECL|member|bits
name|UINT8
name|bits
index|[
literal|17
index|]
decl_stmt|;
comment|/* bits[k] = # of symbols with codes of */
comment|/* length k bits; bits[0] is unused */
DECL|member|huffval
name|UINT8
name|huffval
index|[
literal|256
index|]
decl_stmt|;
comment|/* The symbols, in order of incr code length */
comment|/* This field is used only during compression.  It's initialized FALSE when    * the table is created, and set TRUE when it's been output to the file.    * You could suppress output of a table by setting this to TRUE.    * (See jpeg_suppress_tables for an example.)    */
DECL|member|sent_table
name|boolean
name|sent_table
decl_stmt|;
comment|/* TRUE when table has been output */
block|}
DECL|typedef|JHUFF_TBL
name|JHUFF_TBL
typedef|;
comment|/* Basic info about one component (color channel). */
typedef|typedef
struct|struct
block|{
comment|/* These values are fixed over the whole image. */
comment|/* For compression, they must be supplied by parameter setup; */
comment|/* for decompression, they are read from the SOF marker. */
DECL|member|component_id
name|int
name|component_id
decl_stmt|;
comment|/* identifier for this component (0..255) */
DECL|member|component_index
name|int
name|component_index
decl_stmt|;
comment|/* its index in SOF or cinfo->comp_info[] */
DECL|member|h_samp_factor
name|int
name|h_samp_factor
decl_stmt|;
comment|/* horizontal sampling factor (1..4) */
DECL|member|v_samp_factor
name|int
name|v_samp_factor
decl_stmt|;
comment|/* vertical sampling factor (1..4) */
DECL|member|quant_tbl_no
name|int
name|quant_tbl_no
decl_stmt|;
comment|/* quantization table selector (0..3) */
comment|/* These values may vary between scans. */
comment|/* For compression, they must be supplied by parameter setup; */
comment|/* for decompression, they are read from the SOS marker. */
comment|/* The decompressor output side may not use these variables. */
DECL|member|dc_tbl_no
name|int
name|dc_tbl_no
decl_stmt|;
comment|/* DC entropy table selector (0..3) */
DECL|member|ac_tbl_no
name|int
name|ac_tbl_no
decl_stmt|;
comment|/* AC entropy table selector (0..3) */
comment|/* Remaining fields should be treated as private by applications. */
comment|/* These values are computed during compression or decompression startup: */
comment|/* Component's size in DCT blocks.    * Any dummy blocks added to complete an MCU are not counted; therefore    * these values do not depend on whether a scan is interleaved or not.    */
DECL|member|width_in_blocks
name|JDIMENSION
name|width_in_blocks
decl_stmt|;
DECL|member|height_in_blocks
name|JDIMENSION
name|height_in_blocks
decl_stmt|;
comment|/* Size of a DCT block in samples,    * reflecting any scaling we choose to apply during the DCT step.    * Values from 1 to 16 are supported.    * Note that different components may receive different DCT scalings.    */
DECL|member|DCT_h_scaled_size
name|int
name|DCT_h_scaled_size
decl_stmt|;
DECL|member|DCT_v_scaled_size
name|int
name|DCT_v_scaled_size
decl_stmt|;
comment|/* The downsampled dimensions are the component's actual, unpadded number    * of samples at the main buffer (preprocessing/compression interface);    * DCT scaling is included, so    * downsampled_width = ceil(image_width * Hi/Hmax * DCT_h_scaled_size/DCTSIZE)    * and similarly for height.    */
DECL|member|downsampled_width
name|JDIMENSION
name|downsampled_width
decl_stmt|;
comment|/* actual width in samples */
DECL|member|downsampled_height
name|JDIMENSION
name|downsampled_height
decl_stmt|;
comment|/* actual height in samples */
comment|/* This flag is used only for decompression.  In cases where some of the    * components will be ignored (eg grayscale output from YCbCr image),    * we can skip most computations for the unused components.    */
DECL|member|component_needed
name|boolean
name|component_needed
decl_stmt|;
comment|/* do we need the value of this component? */
comment|/* These values are computed before starting a scan of the component. */
comment|/* The decompressor output side may not use these variables. */
DECL|member|MCU_width
name|int
name|MCU_width
decl_stmt|;
comment|/* number of blocks per MCU, horizontally */
DECL|member|MCU_height
name|int
name|MCU_height
decl_stmt|;
comment|/* number of blocks per MCU, vertically */
DECL|member|MCU_blocks
name|int
name|MCU_blocks
decl_stmt|;
comment|/* MCU_width * MCU_height */
DECL|member|MCU_sample_width
name|int
name|MCU_sample_width
decl_stmt|;
comment|/* MCU width in samples: MCU_width * DCT_h_scaled_size */
DECL|member|last_col_width
name|int
name|last_col_width
decl_stmt|;
comment|/* # of non-dummy blocks across in last MCU */
DECL|member|last_row_height
name|int
name|last_row_height
decl_stmt|;
comment|/* # of non-dummy blocks down in last MCU */
comment|/* Saved quantization table for component; NULL if none yet saved.    * See jdinput.c comments about the need for this information.    * This field is currently used only for decompression.    */
DECL|member|quant_table
name|JQUANT_TBL
modifier|*
name|quant_table
decl_stmt|;
comment|/* Private per-component storage for DCT or IDCT subsystem. */
DECL|member|dct_table
name|void
modifier|*
name|dct_table
decl_stmt|;
block|}
DECL|typedef|jpeg_component_info
name|jpeg_component_info
typedef|;
comment|/* The script for encoding a multiple-scan file is an array of these: */
typedef|typedef
struct|struct
block|{
DECL|member|comps_in_scan
name|int
name|comps_in_scan
decl_stmt|;
comment|/* number of components encoded in this scan */
DECL|member|component_index
name|int
name|component_index
index|[
name|MAX_COMPS_IN_SCAN
index|]
decl_stmt|;
comment|/* their SOF/comp_info[] indexes */
DECL|member|Ss
DECL|member|Se
name|int
name|Ss
decl_stmt|,
name|Se
decl_stmt|;
comment|/* progressive JPEG spectral selection parms */
DECL|member|Ah
DECL|member|Al
name|int
name|Ah
decl_stmt|,
name|Al
decl_stmt|;
comment|/* progressive JPEG successive approx. parms */
block|}
DECL|typedef|jpeg_scan_info
name|jpeg_scan_info
typedef|;
comment|/* The decompressor can save APPn and COM markers in a list of these: */
DECL|typedef|jpeg_saved_marker_ptr
typedef|typedef
name|struct
name|jpeg_marker_struct
name|FAR
modifier|*
name|jpeg_saved_marker_ptr
typedef|;
DECL|struct|jpeg_marker_struct
struct|struct
name|jpeg_marker_struct
block|{
DECL|member|next
name|jpeg_saved_marker_ptr
name|next
decl_stmt|;
comment|/* next in list, or NULL */
DECL|member|marker
name|UINT8
name|marker
decl_stmt|;
comment|/* marker code: JPEG_COM, or JPEG_APP0+n */
DECL|member|original_length
name|unsigned
name|int
name|original_length
decl_stmt|;
comment|/* # bytes of data in the file */
DECL|member|data_length
name|unsigned
name|int
name|data_length
decl_stmt|;
comment|/* # bytes of data saved at data[] */
DECL|member|data
name|JOCTET
name|FAR
modifier|*
name|data
decl_stmt|;
comment|/* the data contained in the marker */
comment|/* the marker length word is not counted in data_length or original_length */
block|}
struct|;
comment|/* Known color spaces. */
typedef|typedef
enum|enum
block|{
DECL|enumerator|JCS_UNKNOWN
name|JCS_UNKNOWN
block|,
comment|/* error/unspecified */
DECL|enumerator|JCS_GRAYSCALE
name|JCS_GRAYSCALE
block|,
comment|/* monochrome */
DECL|enumerator|JCS_RGB
name|JCS_RGB
block|,
comment|/* red/green/blue */
DECL|enumerator|JCS_YCbCr
name|JCS_YCbCr
block|,
comment|/* Y/Cb/Cr (also known as YUV) */
DECL|enumerator|JCS_CMYK
name|JCS_CMYK
block|,
comment|/* C/M/Y/K */
DECL|enumerator|JCS_YCCK
name|JCS_YCCK
comment|/* Y/Cb/Cr/K */
block|}
DECL|typedef|J_COLOR_SPACE
name|J_COLOR_SPACE
typedef|;
comment|/* DCT/IDCT algorithm options. */
typedef|typedef
enum|enum
block|{
DECL|enumerator|JDCT_ISLOW
name|JDCT_ISLOW
block|,
comment|/* slow but accurate integer algorithm */
DECL|enumerator|JDCT_IFAST
name|JDCT_IFAST
block|,
comment|/* faster, less accurate integer method */
DECL|enumerator|JDCT_FLOAT
name|JDCT_FLOAT
comment|/* floating-point: accurate, fast on fast HW */
block|}
DECL|typedef|J_DCT_METHOD
name|J_DCT_METHOD
typedef|;
ifndef|#
directive|ifndef
name|JDCT_DEFAULT
comment|/* may be overridden in jconfig.h */
DECL|macro|JDCT_DEFAULT
define|#
directive|define
name|JDCT_DEFAULT
value|JDCT_ISLOW
endif|#
directive|endif
ifndef|#
directive|ifndef
name|JDCT_FASTEST
comment|/* may be overridden in jconfig.h */
DECL|macro|JDCT_FASTEST
define|#
directive|define
name|JDCT_FASTEST
value|JDCT_IFAST
endif|#
directive|endif
comment|/* Dithering options for decompression. */
typedef|typedef
enum|enum
block|{
DECL|enumerator|JDITHER_NONE
name|JDITHER_NONE
block|,
comment|/* no dithering */
DECL|enumerator|JDITHER_ORDERED
name|JDITHER_ORDERED
block|,
comment|/* simple ordered dither */
DECL|enumerator|JDITHER_FS
name|JDITHER_FS
comment|/* Floyd-Steinberg error diffusion dither */
block|}
DECL|typedef|J_DITHER_MODE
name|J_DITHER_MODE
typedef|;
comment|/* Common fields between JPEG compression and decompression master structs. */
DECL|macro|jpeg_common_fields
define|#
directive|define
name|jpeg_common_fields
define|\
value|struct jpeg_error_mgr * err;
comment|/* Error handler module */
value|\   struct jpeg_memory_mgr * mem;
comment|/* Memory manager module */
value|\   struct jpeg_progress_mgr * progress;
comment|/* Progress monitor, or NULL if none */
value|\   void * client_data;
comment|/* Available for use by application */
value|\   boolean is_decompressor;
comment|/* So common code can tell which is which */
value|\   int global_state
comment|/* For checking call sequence validity */
comment|/* Routines that are to be used by both halves of the library are declared  * to receive a pointer to this structure.  There are no actual instances of  * jpeg_common_struct, only of jpeg_compress_struct and jpeg_decompress_struct.  */
DECL|struct|jpeg_common_struct
struct|struct
name|jpeg_common_struct
block|{
DECL|member|jpeg_common_fields
name|jpeg_common_fields
expr_stmt|;
comment|/* Fields common to both master struct types */
comment|/* Additional fields follow in an actual jpeg_compress_struct or    * jpeg_decompress_struct.  All three structs must agree on these    * initial fields!  (This would be a lot cleaner in C++.)    */
block|}
struct|;
DECL|typedef|j_common_ptr
typedef|typedef
name|struct
name|jpeg_common_struct
modifier|*
name|j_common_ptr
typedef|;
DECL|typedef|j_compress_ptr
typedef|typedef
name|struct
name|jpeg_compress_struct
modifier|*
name|j_compress_ptr
typedef|;
DECL|typedef|j_decompress_ptr
typedef|typedef
name|struct
name|jpeg_decompress_struct
modifier|*
name|j_decompress_ptr
typedef|;
comment|/* Master record for a compression instance */
DECL|struct|jpeg_compress_struct
struct|struct
name|jpeg_compress_struct
block|{
DECL|member|jpeg_common_fields
name|jpeg_common_fields
expr_stmt|;
comment|/* Fields shared with jpeg_decompress_struct */
comment|/* Destination for compressed data */
DECL|member|dest
name|struct
name|jpeg_destination_mgr
modifier|*
name|dest
decl_stmt|;
comment|/* Description of source image --- these fields must be filled in by    * outer application before starting compression.  in_color_space must    * be correct before you can even call jpeg_set_defaults().    */
DECL|member|image_width
name|JDIMENSION
name|image_width
decl_stmt|;
comment|/* input image width */
DECL|member|image_height
name|JDIMENSION
name|image_height
decl_stmt|;
comment|/* input image height */
DECL|member|input_components
name|int
name|input_components
decl_stmt|;
comment|/* # of color components in input image */
DECL|member|in_color_space
name|J_COLOR_SPACE
name|in_color_space
decl_stmt|;
comment|/* colorspace of input image */
DECL|member|input_gamma
name|double
name|input_gamma
decl_stmt|;
comment|/* image gamma of input image */
comment|/* Compression parameters --- these fields must be set before calling    * jpeg_start_compress().  We recommend calling jpeg_set_defaults() to    * initialize everything to reasonable defaults, then changing anything    * the application specifically wants to change.  That way you won't get    * burnt when new parameters are added.  Also note that there are several    * helper routines to simplify changing parameters.    */
DECL|member|scale_num
DECL|member|scale_denom
name|unsigned
name|int
name|scale_num
decl_stmt|,
name|scale_denom
decl_stmt|;
comment|/* fraction by which to scale image */
DECL|member|jpeg_width
name|JDIMENSION
name|jpeg_width
decl_stmt|;
comment|/* scaled JPEG image width */
DECL|member|jpeg_height
name|JDIMENSION
name|jpeg_height
decl_stmt|;
comment|/* scaled JPEG image height */
comment|/* Dimensions of actual JPEG image that will be written to file,    * derived from input dimensions by scaling factors above.    * These fields are computed by jpeg_start_compress().    * You can also use jpeg_calc_jpeg_dimensions() to determine these values    * in advance of calling jpeg_start_compress().    */
DECL|member|data_precision
name|int
name|data_precision
decl_stmt|;
comment|/* bits of precision in image data */
DECL|member|num_components
name|int
name|num_components
decl_stmt|;
comment|/* # of color components in JPEG image */
DECL|member|jpeg_color_space
name|J_COLOR_SPACE
name|jpeg_color_space
decl_stmt|;
comment|/* colorspace of JPEG image */
DECL|member|comp_info
name|jpeg_component_info
modifier|*
name|comp_info
decl_stmt|;
comment|/* comp_info[i] describes component that appears i'th in SOF */
DECL|member|quant_tbl_ptrs
name|JQUANT_TBL
modifier|*
name|quant_tbl_ptrs
index|[
name|NUM_QUANT_TBLS
index|]
decl_stmt|;
DECL|member|q_scale_factor
name|int
name|q_scale_factor
index|[
name|NUM_QUANT_TBLS
index|]
decl_stmt|;
comment|/* ptrs to coefficient quantization tables, or NULL if not defined,    * and corresponding scale factors (percentage, initialized 100).    */
DECL|member|dc_huff_tbl_ptrs
name|JHUFF_TBL
modifier|*
name|dc_huff_tbl_ptrs
index|[
name|NUM_HUFF_TBLS
index|]
decl_stmt|;
DECL|member|ac_huff_tbl_ptrs
name|JHUFF_TBL
modifier|*
name|ac_huff_tbl_ptrs
index|[
name|NUM_HUFF_TBLS
index|]
decl_stmt|;
comment|/* ptrs to Huffman coding tables, or NULL if not defined */
DECL|member|arith_dc_L
name|UINT8
name|arith_dc_L
index|[
name|NUM_ARITH_TBLS
index|]
decl_stmt|;
comment|/* L values for DC arith-coding tables */
DECL|member|arith_dc_U
name|UINT8
name|arith_dc_U
index|[
name|NUM_ARITH_TBLS
index|]
decl_stmt|;
comment|/* U values for DC arith-coding tables */
DECL|member|arith_ac_K
name|UINT8
name|arith_ac_K
index|[
name|NUM_ARITH_TBLS
index|]
decl_stmt|;
comment|/* Kx values for AC arith-coding tables */
DECL|member|num_scans
name|int
name|num_scans
decl_stmt|;
comment|/* # of entries in scan_info array */
DECL|member|scan_info
specifier|const
name|jpeg_scan_info
modifier|*
name|scan_info
decl_stmt|;
comment|/* script for multi-scan file, or NULL */
comment|/* The default value of scan_info is NULL, which causes a single-scan    * sequential JPEG file to be emitted.  To create a multi-scan file,    * set num_scans and scan_info to point to an array of scan definitions.    */
DECL|member|raw_data_in
name|boolean
name|raw_data_in
decl_stmt|;
comment|/* TRUE=caller supplies downsampled data */
DECL|member|arith_code
name|boolean
name|arith_code
decl_stmt|;
comment|/* TRUE=arithmetic coding, FALSE=Huffman */
DECL|member|optimize_coding
name|boolean
name|optimize_coding
decl_stmt|;
comment|/* TRUE=optimize entropy encoding parms */
DECL|member|CCIR601_sampling
name|boolean
name|CCIR601_sampling
decl_stmt|;
comment|/* TRUE=first samples are cosited */
DECL|member|do_fancy_downsampling
name|boolean
name|do_fancy_downsampling
decl_stmt|;
comment|/* TRUE=apply fancy downsampling */
DECL|member|smoothing_factor
name|int
name|smoothing_factor
decl_stmt|;
comment|/* 1..100, or 0 for no input smoothing */
DECL|member|dct_method
name|J_DCT_METHOD
name|dct_method
decl_stmt|;
comment|/* DCT algorithm selector */
comment|/* The restart interval can be specified in absolute MCUs by setting    * restart_interval, or in MCU rows by setting restart_in_rows    * (in which case the correct restart_interval will be figured    * for each scan).    */
DECL|member|restart_interval
name|unsigned
name|int
name|restart_interval
decl_stmt|;
comment|/* MCUs per restart, or 0 for no restart */
DECL|member|restart_in_rows
name|int
name|restart_in_rows
decl_stmt|;
comment|/* if> 0, MCU rows per restart interval */
comment|/* Parameters controlling emission of special markers. */
DECL|member|write_JFIF_header
name|boolean
name|write_JFIF_header
decl_stmt|;
comment|/* should a JFIF marker be written? */
DECL|member|JFIF_major_version
name|UINT8
name|JFIF_major_version
decl_stmt|;
comment|/* What to write for the JFIF version number */
DECL|member|JFIF_minor_version
name|UINT8
name|JFIF_minor_version
decl_stmt|;
comment|/* These three values are not used by the JPEG code, merely copied */
comment|/* into the JFIF APP0 marker.  density_unit can be 0 for unknown, */
comment|/* 1 for dots/inch, or 2 for dots/cm.  Note that the pixel aspect */
comment|/* ratio is defined by X_density/Y_density even when density_unit=0. */
DECL|member|density_unit
name|UINT8
name|density_unit
decl_stmt|;
comment|/* JFIF code for pixel size units */
DECL|member|X_density
name|UINT16
name|X_density
decl_stmt|;
comment|/* Horizontal pixel density */
DECL|member|Y_density
name|UINT16
name|Y_density
decl_stmt|;
comment|/* Vertical pixel density */
DECL|member|write_Adobe_marker
name|boolean
name|write_Adobe_marker
decl_stmt|;
comment|/* should an Adobe marker be written? */
comment|/* State variable: index of next scanline to be written to    * jpeg_write_scanlines().  Application may use this to control its    * processing loop, e.g., "while (next_scanline< image_height)".    */
DECL|member|next_scanline
name|JDIMENSION
name|next_scanline
decl_stmt|;
comment|/* 0 .. image_height-1  */
comment|/* Remaining fields are known throughout compressor, but generally    * should not be touched by a surrounding application.    */
comment|/*    * These fields are computed during compression startup    */
DECL|member|progressive_mode
name|boolean
name|progressive_mode
decl_stmt|;
comment|/* TRUE if scan script uses progressive mode */
DECL|member|max_h_samp_factor
name|int
name|max_h_samp_factor
decl_stmt|;
comment|/* largest h_samp_factor */
DECL|member|max_v_samp_factor
name|int
name|max_v_samp_factor
decl_stmt|;
comment|/* largest v_samp_factor */
DECL|member|min_DCT_h_scaled_size
name|int
name|min_DCT_h_scaled_size
decl_stmt|;
comment|/* smallest DCT_h_scaled_size of any component */
DECL|member|min_DCT_v_scaled_size
name|int
name|min_DCT_v_scaled_size
decl_stmt|;
comment|/* smallest DCT_v_scaled_size of any component */
DECL|member|total_iMCU_rows
name|JDIMENSION
name|total_iMCU_rows
decl_stmt|;
comment|/* # of iMCU rows to be input to coef ctlr */
comment|/* The coefficient controller receives data in units of MCU rows as defined    * for fully interleaved scans (whether the JPEG file is interleaved or not).    * There are v_samp_factor * DCTSIZE sample rows of each component in an    * "iMCU" (interleaved MCU) row.    */
comment|/*    * These fields are valid during any one scan.    * They describe the components and MCUs actually appearing in the scan.    */
DECL|member|comps_in_scan
name|int
name|comps_in_scan
decl_stmt|;
comment|/* # of JPEG components in this scan */
DECL|member|cur_comp_info
name|jpeg_component_info
modifier|*
name|cur_comp_info
index|[
name|MAX_COMPS_IN_SCAN
index|]
decl_stmt|;
comment|/* *cur_comp_info[i] describes component that appears i'th in SOS */
DECL|member|MCUs_per_row
name|JDIMENSION
name|MCUs_per_row
decl_stmt|;
comment|/* # of MCUs across the image */
DECL|member|MCU_rows_in_scan
name|JDIMENSION
name|MCU_rows_in_scan
decl_stmt|;
comment|/* # of MCU rows in the image */
DECL|member|blocks_in_MCU
name|int
name|blocks_in_MCU
decl_stmt|;
comment|/* # of DCT blocks per MCU */
DECL|member|MCU_membership
name|int
name|MCU_membership
index|[
name|C_MAX_BLOCKS_IN_MCU
index|]
decl_stmt|;
comment|/* MCU_membership[i] is index in cur_comp_info of component owning */
comment|/* i'th block in an MCU */
DECL|member|Ss
DECL|member|Se
DECL|member|Ah
DECL|member|Al
name|int
name|Ss
decl_stmt|,
name|Se
decl_stmt|,
name|Ah
decl_stmt|,
name|Al
decl_stmt|;
comment|/* progressive JPEG parameters for scan */
DECL|member|block_size
name|int
name|block_size
decl_stmt|;
comment|/* the basic DCT block size: 1..16 */
DECL|member|natural_order
specifier|const
name|int
modifier|*
name|natural_order
decl_stmt|;
comment|/* natural-order position array */
DECL|member|lim_Se
name|int
name|lim_Se
decl_stmt|;
comment|/* min( Se, DCTSIZE2-1 ) */
comment|/*    * Links to compression subobjects (methods and private variables of modules)    */
DECL|member|master
name|struct
name|jpeg_comp_master
modifier|*
name|master
decl_stmt|;
DECL|member|main
name|struct
name|jpeg_c_main_controller
modifier|*
decl|main
decl_stmt|;
DECL|member|prep
name|struct
name|jpeg_c_prep_controller
modifier|*
name|prep
decl_stmt|;
DECL|member|coef
name|struct
name|jpeg_c_coef_controller
modifier|*
name|coef
decl_stmt|;
DECL|member|marker
name|struct
name|jpeg_marker_writer
modifier|*
name|marker
decl_stmt|;
DECL|member|cconvert
name|struct
name|jpeg_color_converter
modifier|*
name|cconvert
decl_stmt|;
DECL|member|downsample
name|struct
name|jpeg_downsampler
modifier|*
name|downsample
decl_stmt|;
DECL|member|fdct
name|struct
name|jpeg_forward_dct
modifier|*
name|fdct
decl_stmt|;
DECL|member|entropy
name|struct
name|jpeg_entropy_encoder
modifier|*
name|entropy
decl_stmt|;
DECL|member|script_space
name|jpeg_scan_info
modifier|*
name|script_space
decl_stmt|;
comment|/* workspace for jpeg_simple_progression */
DECL|member|script_space_size
name|int
name|script_space_size
decl_stmt|;
block|}
struct|;
comment|/* Master record for a decompression instance */
DECL|struct|jpeg_decompress_struct
struct|struct
name|jpeg_decompress_struct
block|{
DECL|member|jpeg_common_fields
name|jpeg_common_fields
expr_stmt|;
comment|/* Fields shared with jpeg_compress_struct */
comment|/* Source of compressed data */
DECL|member|src
name|struct
name|jpeg_source_mgr
modifier|*
name|src
decl_stmt|;
comment|/* Basic description of image --- filled in by jpeg_read_header(). */
comment|/* Application may inspect these values to decide how to process image. */
DECL|member|image_width
name|JDIMENSION
name|image_width
decl_stmt|;
comment|/* nominal image width (from SOF marker) */
DECL|member|image_height
name|JDIMENSION
name|image_height
decl_stmt|;
comment|/* nominal image height */
DECL|member|num_components
name|int
name|num_components
decl_stmt|;
comment|/* # of color components in JPEG image */
DECL|member|jpeg_color_space
name|J_COLOR_SPACE
name|jpeg_color_space
decl_stmt|;
comment|/* colorspace of JPEG image */
comment|/* Decompression processing parameters --- these fields must be set before    * calling jpeg_start_decompress().  Note that jpeg_read_header() initializes    * them to default values.    */
DECL|member|out_color_space
name|J_COLOR_SPACE
name|out_color_space
decl_stmt|;
comment|/* colorspace for output */
DECL|member|scale_num
DECL|member|scale_denom
name|unsigned
name|int
name|scale_num
decl_stmt|,
name|scale_denom
decl_stmt|;
comment|/* fraction by which to scale image */
DECL|member|output_gamma
name|double
name|output_gamma
decl_stmt|;
comment|/* image gamma wanted in output */
DECL|member|buffered_image
name|boolean
name|buffered_image
decl_stmt|;
comment|/* TRUE=multiple output passes */
DECL|member|raw_data_out
name|boolean
name|raw_data_out
decl_stmt|;
comment|/* TRUE=downsampled data wanted */
DECL|member|dct_method
name|J_DCT_METHOD
name|dct_method
decl_stmt|;
comment|/* IDCT algorithm selector */
DECL|member|do_fancy_upsampling
name|boolean
name|do_fancy_upsampling
decl_stmt|;
comment|/* TRUE=apply fancy upsampling */
DECL|member|do_block_smoothing
name|boolean
name|do_block_smoothing
decl_stmt|;
comment|/* TRUE=apply interblock smoothing */
DECL|member|quantize_colors
name|boolean
name|quantize_colors
decl_stmt|;
comment|/* TRUE=colormapped output wanted */
comment|/* the following are ignored if not quantize_colors: */
DECL|member|dither_mode
name|J_DITHER_MODE
name|dither_mode
decl_stmt|;
comment|/* type of color dithering to use */
DECL|member|two_pass_quantize
name|boolean
name|two_pass_quantize
decl_stmt|;
comment|/* TRUE=use two-pass color quantization */
DECL|member|desired_number_of_colors
name|int
name|desired_number_of_colors
decl_stmt|;
comment|/* max # colors to use in created colormap */
comment|/* these are significant only in buffered-image mode: */
DECL|member|enable_1pass_quant
name|boolean
name|enable_1pass_quant
decl_stmt|;
comment|/* enable future use of 1-pass quantizer */
DECL|member|enable_external_quant
name|boolean
name|enable_external_quant
decl_stmt|;
comment|/* enable future use of external colormap */
DECL|member|enable_2pass_quant
name|boolean
name|enable_2pass_quant
decl_stmt|;
comment|/* enable future use of 2-pass quantizer */
comment|/* Description of actual output image that will be returned to application.    * These fields are computed by jpeg_start_decompress().    * You can also use jpeg_calc_output_dimensions() to determine these values    * in advance of calling jpeg_start_decompress().    */
DECL|member|output_width
name|JDIMENSION
name|output_width
decl_stmt|;
comment|/* scaled image width */
DECL|member|output_height
name|JDIMENSION
name|output_height
decl_stmt|;
comment|/* scaled image height */
DECL|member|out_color_components
name|int
name|out_color_components
decl_stmt|;
comment|/* # of color components in out_color_space */
DECL|member|output_components
name|int
name|output_components
decl_stmt|;
comment|/* # of color components returned */
comment|/* output_components is 1 (a colormap index) when quantizing colors;    * otherwise it equals out_color_components.    */
DECL|member|rec_outbuf_height
name|int
name|rec_outbuf_height
decl_stmt|;
comment|/* min recommended height of scanline buffer */
comment|/* If the buffer passed to jpeg_read_scanlines() is less than this many rows    * high, space and time will be wasted due to unnecessary data copying.    * Usually rec_outbuf_height will be 1 or 2, at most 4.    */
comment|/* When quantizing colors, the output colormap is described by these fields.    * The application can supply a colormap by setting colormap non-NULL before    * calling jpeg_start_decompress; otherwise a colormap is created during    * jpeg_start_decompress or jpeg_start_output.    * The map has out_color_components rows and actual_number_of_colors columns.    */
DECL|member|actual_number_of_colors
name|int
name|actual_number_of_colors
decl_stmt|;
comment|/* number of entries in use */
DECL|member|colormap
name|JSAMPARRAY
name|colormap
decl_stmt|;
comment|/* The color map as a 2-D pixel array */
comment|/* State variables: these variables indicate the progress of decompression.    * The application may examine these but must not modify them.    */
comment|/* Row index of next scanline to be read from jpeg_read_scanlines().    * Application may use this to control its processing loop, e.g.,    * "while (output_scanline< output_height)".    */
DECL|member|output_scanline
name|JDIMENSION
name|output_scanline
decl_stmt|;
comment|/* 0 .. output_height-1  */
comment|/* Current input scan number and number of iMCU rows completed in scan.    * These indicate the progress of the decompressor input side.    */
DECL|member|input_scan_number
name|int
name|input_scan_number
decl_stmt|;
comment|/* Number of SOS markers seen so far */
DECL|member|input_iMCU_row
name|JDIMENSION
name|input_iMCU_row
decl_stmt|;
comment|/* Number of iMCU rows completed */
comment|/* The "output scan number" is the notional scan being displayed by the    * output side.  The decompressor will not allow output scan/row number    * to get ahead of input scan/row, but it can fall arbitrarily far behind.    */
DECL|member|output_scan_number
name|int
name|output_scan_number
decl_stmt|;
comment|/* Nominal scan number being displayed */
DECL|member|output_iMCU_row
name|JDIMENSION
name|output_iMCU_row
decl_stmt|;
comment|/* Number of iMCU rows read */
comment|/* Current progression status.  coef_bits[c][i] indicates the precision    * with which component c's DCT coefficient i (in zigzag order) is known.    * It is -1 when no data has yet been received, otherwise it is the point    * transform (shift) value for the most recent scan of the coefficient    * (thus, 0 at completion of the progression).    * This pointer is NULL when reading a non-progressive file.    */
DECL|member|coef_bits
name|int
argument_list|(
operator|*
name|coef_bits
argument_list|)
index|[
name|DCTSIZE2
index|]
expr_stmt|;
comment|/* -1 or current Al value for each coef */
comment|/* Internal JPEG parameters --- the application usually need not look at    * these fields.  Note that the decompressor output side may not use    * any parameters that can change between scans.    */
comment|/* Quantization and Huffman tables are carried forward across input    * datastreams when processing abbreviated JPEG datastreams.    */
DECL|member|quant_tbl_ptrs
name|JQUANT_TBL
modifier|*
name|quant_tbl_ptrs
index|[
name|NUM_QUANT_TBLS
index|]
decl_stmt|;
comment|/* ptrs to coefficient quantization tables, or NULL if not defined */
DECL|member|dc_huff_tbl_ptrs
name|JHUFF_TBL
modifier|*
name|dc_huff_tbl_ptrs
index|[
name|NUM_HUFF_TBLS
index|]
decl_stmt|;
DECL|member|ac_huff_tbl_ptrs
name|JHUFF_TBL
modifier|*
name|ac_huff_tbl_ptrs
index|[
name|NUM_HUFF_TBLS
index|]
decl_stmt|;
comment|/* ptrs to Huffman coding tables, or NULL if not defined */
comment|/* These parameters are never carried across datastreams, since they    * are given in SOF/SOS markers or defined to be reset by SOI.    */
DECL|member|data_precision
name|int
name|data_precision
decl_stmt|;
comment|/* bits of precision in image data */
DECL|member|comp_info
name|jpeg_component_info
modifier|*
name|comp_info
decl_stmt|;
comment|/* comp_info[i] describes component that appears i'th in SOF */
DECL|member|is_baseline
name|boolean
name|is_baseline
decl_stmt|;
comment|/* TRUE if Baseline SOF0 encountered */
DECL|member|progressive_mode
name|boolean
name|progressive_mode
decl_stmt|;
comment|/* TRUE if SOFn specifies progressive mode */
DECL|member|arith_code
name|boolean
name|arith_code
decl_stmt|;
comment|/* TRUE=arithmetic coding, FALSE=Huffman */
DECL|member|arith_dc_L
name|UINT8
name|arith_dc_L
index|[
name|NUM_ARITH_TBLS
index|]
decl_stmt|;
comment|/* L values for DC arith-coding tables */
DECL|member|arith_dc_U
name|UINT8
name|arith_dc_U
index|[
name|NUM_ARITH_TBLS
index|]
decl_stmt|;
comment|/* U values for DC arith-coding tables */
DECL|member|arith_ac_K
name|UINT8
name|arith_ac_K
index|[
name|NUM_ARITH_TBLS
index|]
decl_stmt|;
comment|/* Kx values for AC arith-coding tables */
DECL|member|restart_interval
name|unsigned
name|int
name|restart_interval
decl_stmt|;
comment|/* MCUs per restart interval, or 0 for no restart */
comment|/* These fields record data obtained from optional markers recognized by    * the JPEG library.    */
DECL|member|saw_JFIF_marker
name|boolean
name|saw_JFIF_marker
decl_stmt|;
comment|/* TRUE iff a JFIF APP0 marker was found */
comment|/* Data copied from JFIF marker; only valid if saw_JFIF_marker is TRUE: */
DECL|member|JFIF_major_version
name|UINT8
name|JFIF_major_version
decl_stmt|;
comment|/* JFIF version number */
DECL|member|JFIF_minor_version
name|UINT8
name|JFIF_minor_version
decl_stmt|;
DECL|member|density_unit
name|UINT8
name|density_unit
decl_stmt|;
comment|/* JFIF code for pixel size units */
DECL|member|X_density
name|UINT16
name|X_density
decl_stmt|;
comment|/* Horizontal pixel density */
DECL|member|Y_density
name|UINT16
name|Y_density
decl_stmt|;
comment|/* Vertical pixel density */
DECL|member|saw_Adobe_marker
name|boolean
name|saw_Adobe_marker
decl_stmt|;
comment|/* TRUE iff an Adobe APP14 marker was found */
DECL|member|Adobe_transform
name|UINT8
name|Adobe_transform
decl_stmt|;
comment|/* Color transform code from Adobe marker */
DECL|member|CCIR601_sampling
name|boolean
name|CCIR601_sampling
decl_stmt|;
comment|/* TRUE=first samples are cosited */
comment|/* Aside from the specific data retained from APPn markers known to the    * library, the uninterpreted contents of any or all APPn and COM markers    * can be saved in a list for examination by the application.    */
DECL|member|marker_list
name|jpeg_saved_marker_ptr
name|marker_list
decl_stmt|;
comment|/* Head of list of saved markers */
comment|/* Remaining fields are known throughout decompressor, but generally    * should not be touched by a surrounding application.    */
comment|/*    * These fields are computed during decompression startup    */
DECL|member|max_h_samp_factor
name|int
name|max_h_samp_factor
decl_stmt|;
comment|/* largest h_samp_factor */
DECL|member|max_v_samp_factor
name|int
name|max_v_samp_factor
decl_stmt|;
comment|/* largest v_samp_factor */
DECL|member|min_DCT_h_scaled_size
name|int
name|min_DCT_h_scaled_size
decl_stmt|;
comment|/* smallest DCT_h_scaled_size of any component */
DECL|member|min_DCT_v_scaled_size
name|int
name|min_DCT_v_scaled_size
decl_stmt|;
comment|/* smallest DCT_v_scaled_size of any component */
DECL|member|total_iMCU_rows
name|JDIMENSION
name|total_iMCU_rows
decl_stmt|;
comment|/* # of iMCU rows in image */
comment|/* The coefficient controller's input and output progress is measured in    * units of "iMCU" (interleaved MCU) rows.  These are the same as MCU rows    * in fully interleaved JPEG scans, but are used whether the scan is    * interleaved or not.  We define an iMCU row as v_samp_factor DCT block    * rows of each component.  Therefore, the IDCT output contains    * v_samp_factor*DCT_v_scaled_size sample rows of a component per iMCU row.    */
DECL|member|sample_range_limit
name|JSAMPLE
modifier|*
name|sample_range_limit
decl_stmt|;
comment|/* table for fast range-limiting */
comment|/*    * These fields are valid during any one scan.    * They describe the components and MCUs actually appearing in the scan.    * Note that the decompressor output side must not use these fields.    */
DECL|member|comps_in_scan
name|int
name|comps_in_scan
decl_stmt|;
comment|/* # of JPEG components in this scan */
DECL|member|cur_comp_info
name|jpeg_component_info
modifier|*
name|cur_comp_info
index|[
name|MAX_COMPS_IN_SCAN
index|]
decl_stmt|;
comment|/* *cur_comp_info[i] describes component that appears i'th in SOS */
DECL|member|MCUs_per_row
name|JDIMENSION
name|MCUs_per_row
decl_stmt|;
comment|/* # of MCUs across the image */
DECL|member|MCU_rows_in_scan
name|JDIMENSION
name|MCU_rows_in_scan
decl_stmt|;
comment|/* # of MCU rows in the image */
DECL|member|blocks_in_MCU
name|int
name|blocks_in_MCU
decl_stmt|;
comment|/* # of DCT blocks per MCU */
DECL|member|MCU_membership
name|int
name|MCU_membership
index|[
name|D_MAX_BLOCKS_IN_MCU
index|]
decl_stmt|;
comment|/* MCU_membership[i] is index in cur_comp_info of component owning */
comment|/* i'th block in an MCU */
DECL|member|Ss
DECL|member|Se
DECL|member|Ah
DECL|member|Al
name|int
name|Ss
decl_stmt|,
name|Se
decl_stmt|,
name|Ah
decl_stmt|,
name|Al
decl_stmt|;
comment|/* progressive JPEG parameters for scan */
comment|/* These fields are derived from Se of first SOS marker.    */
DECL|member|block_size
name|int
name|block_size
decl_stmt|;
comment|/* the basic DCT block size: 1..16 */
DECL|member|natural_order
specifier|const
name|int
modifier|*
name|natural_order
decl_stmt|;
comment|/* natural-order position array for entropy decode */
DECL|member|lim_Se
name|int
name|lim_Se
decl_stmt|;
comment|/* min( Se, DCTSIZE2-1 ) for entropy decode */
comment|/* This field is shared between entropy decoder and marker parser.    * It is either zero or the code of a JPEG marker that has been    * read from the data source, but has not yet been processed.    */
DECL|member|unread_marker
name|int
name|unread_marker
decl_stmt|;
comment|/*    * Links to decompression subobjects (methods, private variables of modules)    */
DECL|member|master
name|struct
name|jpeg_decomp_master
modifier|*
name|master
decl_stmt|;
DECL|member|main
name|struct
name|jpeg_d_main_controller
modifier|*
decl|main
decl_stmt|;
DECL|member|coef
name|struct
name|jpeg_d_coef_controller
modifier|*
name|coef
decl_stmt|;
DECL|member|post
name|struct
name|jpeg_d_post_controller
modifier|*
name|post
decl_stmt|;
DECL|member|inputctl
name|struct
name|jpeg_input_controller
modifier|*
name|inputctl
decl_stmt|;
DECL|member|marker
name|struct
name|jpeg_marker_reader
modifier|*
name|marker
decl_stmt|;
DECL|member|entropy
name|struct
name|jpeg_entropy_decoder
modifier|*
name|entropy
decl_stmt|;
DECL|member|idct
name|struct
name|jpeg_inverse_dct
modifier|*
name|idct
decl_stmt|;
DECL|member|upsample
name|struct
name|jpeg_upsampler
modifier|*
name|upsample
decl_stmt|;
DECL|member|cconvert
name|struct
name|jpeg_color_deconverter
modifier|*
name|cconvert
decl_stmt|;
DECL|member|cquantize
name|struct
name|jpeg_color_quantizer
modifier|*
name|cquantize
decl_stmt|;
block|}
struct|;
comment|/* "Object" declarations for JPEG modules that may be supplied or called  * directly by the surrounding application.  * As with all objects in the JPEG library, these structs only define the  * publicly visible methods and state variables of a module.  Additional  * private fields may exist after the public ones.  */
comment|/* Error handler object */
DECL|struct|jpeg_error_mgr
struct|struct
name|jpeg_error_mgr
block|{
comment|/* Error exit handler: does not return to caller */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|error_exit
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
comment|/* Conditionally emit a trace or warning message */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|emit_message
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|msg_level
operator|)
argument_list|)
expr_stmt|;
comment|/* Routine that actually outputs a trace or error message */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|output_message
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
comment|/* Format a message string for the most recent JPEG error or message */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|format_message
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|char
operator|*
name|buffer
operator|)
argument_list|)
expr_stmt|;
DECL|macro|JMSG_LENGTH_MAX
define|#
directive|define
name|JMSG_LENGTH_MAX
value|200
comment|/* recommended size of format_message buffer */
comment|/* Reset error state variables at start of a new image */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|reset_error_mgr
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
comment|/* The message ID code and any parameters are saved here.    * A message can have one string parameter or up to 8 int parameters.    */
DECL|member|msg_code
name|int
name|msg_code
decl_stmt|;
DECL|macro|JMSG_STR_PARM_MAX
define|#
directive|define
name|JMSG_STR_PARM_MAX
value|80
union|union
block|{
DECL|member|i
name|int
name|i
index|[
literal|8
index|]
decl_stmt|;
DECL|member|s
name|char
name|s
index|[
name|JMSG_STR_PARM_MAX
index|]
decl_stmt|;
block|}
DECL|member|msg_parm
name|msg_parm
union|;
comment|/* Standard state variables for error facility */
DECL|member|trace_level
name|int
name|trace_level
decl_stmt|;
comment|/* max msg_level that will be displayed */
comment|/* For recoverable corrupt-data errors, we emit a warning message,    * but keep going unless emit_message chooses to abort.  emit_message    * should count warnings in num_warnings.  The surrounding application    * can check for bad data by seeing if num_warnings is nonzero at the    * end of processing.    */
DECL|member|num_warnings
name|long
name|num_warnings
decl_stmt|;
comment|/* number of corrupt-data warnings */
comment|/* These fields point to the table(s) of error message strings.    * An application can change the table pointer to switch to a different    * message list (typically, to change the language in which errors are    * reported).  Some applications may wish to add additional error codes    * that will be handled by the JPEG library error mechanism; the second    * table pointer is used for this purpose.    *    * First table includes all errors generated by JPEG library itself.    * Error code 0 is reserved for a "no such error string" message.    */
DECL|member|jpeg_message_table
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|jpeg_message_table
decl_stmt|;
comment|/* Library errors */
DECL|member|last_jpeg_message
name|int
name|last_jpeg_message
decl_stmt|;
comment|/* Table contains strings 0..last_jpeg_message */
comment|/* Second table can be added by application (see cjpeg/djpeg for example).    * It contains strings numbered first_addon_message..last_addon_message.    */
DECL|member|addon_message_table
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|addon_message_table
decl_stmt|;
comment|/* Non-library errors */
DECL|member|first_addon_message
name|int
name|first_addon_message
decl_stmt|;
comment|/* code for first string in addon table */
DECL|member|last_addon_message
name|int
name|last_addon_message
decl_stmt|;
comment|/* code for last string in addon table */
block|}
struct|;
comment|/* Progress monitor object */
DECL|struct|jpeg_progress_mgr
struct|struct
name|jpeg_progress_mgr
block|{
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|progress_monitor
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
DECL|member|pass_counter
name|long
name|pass_counter
decl_stmt|;
comment|/* work units completed in this pass */
DECL|member|pass_limit
name|long
name|pass_limit
decl_stmt|;
comment|/* total number of work units in this pass */
DECL|member|completed_passes
name|int
name|completed_passes
decl_stmt|;
comment|/* passes completed so far */
DECL|member|total_passes
name|int
name|total_passes
decl_stmt|;
comment|/* total number of passes expected */
block|}
struct|;
comment|/* Data destination object for compression */
DECL|struct|jpeg_destination_mgr
struct|struct
name|jpeg_destination_mgr
block|{
DECL|member|next_output_byte
name|JOCTET
modifier|*
name|next_output_byte
decl_stmt|;
comment|/* => next byte to write in buffer */
DECL|member|free_in_buffer
name|size_t
name|free_in_buffer
decl_stmt|;
comment|/* # of byte spaces remaining in buffer */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|init_destination
argument_list|,
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|boolean
argument_list|,
name|empty_output_buffer
argument_list|,
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|term_destination
argument_list|,
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
comment|/* Data source object for decompression */
DECL|struct|jpeg_source_mgr
struct|struct
name|jpeg_source_mgr
block|{
DECL|member|next_input_byte
specifier|const
name|JOCTET
modifier|*
name|next_input_byte
decl_stmt|;
comment|/* => next byte to read from buffer */
DECL|member|bytes_in_buffer
name|size_t
name|bytes_in_buffer
decl_stmt|;
comment|/* # of bytes remaining in buffer */
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|init_source
argument_list|,
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|boolean
argument_list|,
name|fill_input_buffer
argument_list|,
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|skip_input_data
argument_list|,
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|long
name|num_bytes
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|boolean
argument_list|,
name|resync_to_restart
argument_list|,
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|int
name|desired
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|term_source
argument_list|,
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
comment|/* Memory manager object.  * Allocates "small" objects (a few K total), "large" objects (tens of K),  * and "really big" objects (virtual arrays with backing store if needed).  * The memory manager does not allow individual objects to be freed; rather,  * each created object is assigned to a pool, and whole pools can be freed  * at once.  This is faster and more convenient than remembering exactly what  * to free, especially where malloc()/free() are not too speedy.  * NB: alloc routines never return NULL.  They exit to error_exit if not  * successful.  */
DECL|macro|JPOOL_PERMANENT
define|#
directive|define
name|JPOOL_PERMANENT
value|0
comment|/* lasts until master record is destroyed */
DECL|macro|JPOOL_IMAGE
define|#
directive|define
name|JPOOL_IMAGE
value|1
comment|/* lasts until done with image/datastream */
DECL|macro|JPOOL_NUMPOOLS
define|#
directive|define
name|JPOOL_NUMPOOLS
value|2
DECL|typedef|jvirt_sarray_ptr
typedef|typedef
name|struct
name|jvirt_sarray_control
modifier|*
name|jvirt_sarray_ptr
typedef|;
DECL|typedef|jvirt_barray_ptr
typedef|typedef
name|struct
name|jvirt_barray_control
modifier|*
name|jvirt_barray_ptr
typedef|;
DECL|struct|jpeg_memory_mgr
struct|struct
name|jpeg_memory_mgr
block|{
comment|/* Method pointers */
name|JMETHOD
argument_list|(
name|void
operator|*
argument_list|,
name|alloc_small
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|pool_id
operator|,
name|size_t
name|sizeofobject
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
argument|void FAR *
argument_list|,
argument|alloc_large
argument_list|,
argument|(j_common_ptr cinfo, int pool_id, 				     size_t sizeofobject)
argument_list|)
empty_stmt|;
name|JMETHOD
argument_list|(
name|JSAMPARRAY
argument_list|,
name|alloc_sarray
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|pool_id
operator|,
name|JDIMENSION
name|samplesperrow
operator|,
name|JDIMENSION
name|numrows
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|JBLOCKARRAY
argument_list|,
name|alloc_barray
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|pool_id
operator|,
name|JDIMENSION
name|blocksperrow
operator|,
name|JDIMENSION
name|numrows
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|jvirt_sarray_ptr
argument_list|,
name|request_virt_sarray
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|pool_id
operator|,
name|boolean
name|pre_zero
operator|,
name|JDIMENSION
name|samplesperrow
operator|,
name|JDIMENSION
name|numrows
operator|,
name|JDIMENSION
name|maxaccess
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|jvirt_barray_ptr
argument_list|,
name|request_virt_barray
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|pool_id
operator|,
name|boolean
name|pre_zero
operator|,
name|JDIMENSION
name|blocksperrow
operator|,
name|JDIMENSION
name|numrows
operator|,
name|JDIMENSION
name|maxaccess
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|realize_virt_arrays
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|JSAMPARRAY
argument_list|,
name|access_virt_sarray
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|jvirt_sarray_ptr
name|ptr
operator|,
name|JDIMENSION
name|start_row
operator|,
name|JDIMENSION
name|num_rows
operator|,
name|boolean
name|writable
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|JBLOCKARRAY
argument_list|,
name|access_virt_barray
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|jvirt_barray_ptr
name|ptr
operator|,
name|JDIMENSION
name|start_row
operator|,
name|JDIMENSION
name|num_rows
operator|,
name|boolean
name|writable
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|free_pool
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|,
name|int
name|pool_id
operator|)
argument_list|)
expr_stmt|;
name|JMETHOD
argument_list|(
name|void
argument_list|,
name|self_destruct
argument_list|,
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
comment|/* Limit on memory allocation for this JPEG object.  (Note that this is    * merely advisory, not a guaranteed maximum; it only affects the space    * used for virtual-array buffers.)  May be changed by outer application    * after creating the JPEG object.    */
DECL|member|max_memory_to_use
name|long
name|max_memory_to_use
decl_stmt|;
comment|/* Maximum allocation request accepted by alloc_large. */
DECL|member|max_alloc_chunk
name|long
name|max_alloc_chunk
decl_stmt|;
block|}
struct|;
comment|/* Routine signature for application-supplied marker processing methods.  * Need not pass marker code since it is stored in cinfo->unread_marker.  */
DECL|typedef|JMETHOD
typedef|typedef
name|JMETHOD
argument_list|(
name|boolean
argument_list|,
name|jpeg_marker_parser_method
argument_list|,
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
expr_stmt|;
comment|/* Declarations for routines called by application.  * The JPP macro hides prototype parameters from compilers that can't cope.  * Note JPP requires double parentheses.  */
ifdef|#
directive|ifdef
name|HAVE_PROTOTYPES
DECL|macro|JPP
define|#
directive|define
name|JPP
parameter_list|(
name|arglist
parameter_list|)
value|arglist
else|#
directive|else
DECL|macro|JPP
define|#
directive|define
name|JPP
parameter_list|(
name|arglist
parameter_list|)
value|()
endif|#
directive|endif
comment|/* Short forms of external names for systems with brain-damaged linkers.  * We shorten external names to be unique in the first six letters, which  * is good enough for all known systems.  * (If your compiler itself needs names to be unique in less than 15   * characters, you are out of luck.  Get a better compiler.)  */
ifdef|#
directive|ifdef
name|NEED_SHORT_EXTERNAL_NAMES
DECL|macro|jpeg_std_error
define|#
directive|define
name|jpeg_std_error
value|jStdError
DECL|macro|jpeg_CreateCompress
define|#
directive|define
name|jpeg_CreateCompress
value|jCreaCompress
DECL|macro|jpeg_CreateDecompress
define|#
directive|define
name|jpeg_CreateDecompress
value|jCreaDecompress
DECL|macro|jpeg_destroy_compress
define|#
directive|define
name|jpeg_destroy_compress
value|jDestCompress
DECL|macro|jpeg_destroy_decompress
define|#
directive|define
name|jpeg_destroy_decompress
value|jDestDecompress
DECL|macro|jpeg_stdio_dest
define|#
directive|define
name|jpeg_stdio_dest
value|jStdDest
DECL|macro|jpeg_stdio_src
define|#
directive|define
name|jpeg_stdio_src
value|jStdSrc
DECL|macro|jpeg_mem_dest
define|#
directive|define
name|jpeg_mem_dest
value|jMemDest
DECL|macro|jpeg_mem_src
define|#
directive|define
name|jpeg_mem_src
value|jMemSrc
DECL|macro|jpeg_set_defaults
define|#
directive|define
name|jpeg_set_defaults
value|jSetDefaults
DECL|macro|jpeg_set_colorspace
define|#
directive|define
name|jpeg_set_colorspace
value|jSetColorspace
DECL|macro|jpeg_default_colorspace
define|#
directive|define
name|jpeg_default_colorspace
value|jDefColorspace
DECL|macro|jpeg_set_quality
define|#
directive|define
name|jpeg_set_quality
value|jSetQuality
DECL|macro|jpeg_set_linear_quality
define|#
directive|define
name|jpeg_set_linear_quality
value|jSetLQuality
DECL|macro|jpeg_default_qtables
define|#
directive|define
name|jpeg_default_qtables
value|jDefQTables
DECL|macro|jpeg_add_quant_table
define|#
directive|define
name|jpeg_add_quant_table
value|jAddQuantTable
DECL|macro|jpeg_quality_scaling
define|#
directive|define
name|jpeg_quality_scaling
value|jQualityScaling
DECL|macro|jpeg_simple_progression
define|#
directive|define
name|jpeg_simple_progression
value|jSimProgress
DECL|macro|jpeg_suppress_tables
define|#
directive|define
name|jpeg_suppress_tables
value|jSuppressTables
DECL|macro|jpeg_alloc_quant_table
define|#
directive|define
name|jpeg_alloc_quant_table
value|jAlcQTable
DECL|macro|jpeg_alloc_huff_table
define|#
directive|define
name|jpeg_alloc_huff_table
value|jAlcHTable
DECL|macro|jpeg_start_compress
define|#
directive|define
name|jpeg_start_compress
value|jStrtCompress
DECL|macro|jpeg_write_scanlines
define|#
directive|define
name|jpeg_write_scanlines
value|jWrtScanlines
DECL|macro|jpeg_finish_compress
define|#
directive|define
name|jpeg_finish_compress
value|jFinCompress
DECL|macro|jpeg_calc_jpeg_dimensions
define|#
directive|define
name|jpeg_calc_jpeg_dimensions
value|jCjpegDimensions
DECL|macro|jpeg_write_raw_data
define|#
directive|define
name|jpeg_write_raw_data
value|jWrtRawData
DECL|macro|jpeg_write_marker
define|#
directive|define
name|jpeg_write_marker
value|jWrtMarker
DECL|macro|jpeg_write_m_header
define|#
directive|define
name|jpeg_write_m_header
value|jWrtMHeader
DECL|macro|jpeg_write_m_byte
define|#
directive|define
name|jpeg_write_m_byte
value|jWrtMByte
DECL|macro|jpeg_write_tables
define|#
directive|define
name|jpeg_write_tables
value|jWrtTables
DECL|macro|jpeg_read_header
define|#
directive|define
name|jpeg_read_header
value|jReadHeader
DECL|macro|jpeg_start_decompress
define|#
directive|define
name|jpeg_start_decompress
value|jStrtDecompress
DECL|macro|jpeg_read_scanlines
define|#
directive|define
name|jpeg_read_scanlines
value|jReadScanlines
DECL|macro|jpeg_finish_decompress
define|#
directive|define
name|jpeg_finish_decompress
value|jFinDecompress
DECL|macro|jpeg_read_raw_data
define|#
directive|define
name|jpeg_read_raw_data
value|jReadRawData
DECL|macro|jpeg_has_multiple_scans
define|#
directive|define
name|jpeg_has_multiple_scans
value|jHasMultScn
DECL|macro|jpeg_start_output
define|#
directive|define
name|jpeg_start_output
value|jStrtOutput
DECL|macro|jpeg_finish_output
define|#
directive|define
name|jpeg_finish_output
value|jFinOutput
DECL|macro|jpeg_input_complete
define|#
directive|define
name|jpeg_input_complete
value|jInComplete
DECL|macro|jpeg_new_colormap
define|#
directive|define
name|jpeg_new_colormap
value|jNewCMap
DECL|macro|jpeg_consume_input
define|#
directive|define
name|jpeg_consume_input
value|jConsumeInput
DECL|macro|jpeg_core_output_dimensions
define|#
directive|define
name|jpeg_core_output_dimensions
value|jCoreDimensions
DECL|macro|jpeg_calc_output_dimensions
define|#
directive|define
name|jpeg_calc_output_dimensions
value|jCalcDimensions
DECL|macro|jpeg_save_markers
define|#
directive|define
name|jpeg_save_markers
value|jSaveMarkers
DECL|macro|jpeg_set_marker_processor
define|#
directive|define
name|jpeg_set_marker_processor
value|jSetMarker
DECL|macro|jpeg_read_coefficients
define|#
directive|define
name|jpeg_read_coefficients
value|jReadCoefs
DECL|macro|jpeg_write_coefficients
define|#
directive|define
name|jpeg_write_coefficients
value|jWrtCoefs
DECL|macro|jpeg_copy_critical_parameters
define|#
directive|define
name|jpeg_copy_critical_parameters
value|jCopyCrit
DECL|macro|jpeg_abort_compress
define|#
directive|define
name|jpeg_abort_compress
value|jAbrtCompress
DECL|macro|jpeg_abort_decompress
define|#
directive|define
name|jpeg_abort_decompress
value|jAbrtDecompress
DECL|macro|jpeg_abort
define|#
directive|define
name|jpeg_abort
value|jAbort
DECL|macro|jpeg_destroy
define|#
directive|define
name|jpeg_destroy
value|jDestroy
DECL|macro|jpeg_resync_to_restart
define|#
directive|define
name|jpeg_resync_to_restart
value|jResyncRestart
endif|#
directive|endif
comment|/* NEED_SHORT_EXTERNAL_NAMES */
comment|/* Default error-management setup */
name|EXTERN
argument_list|(
argument|struct jpeg_error_mgr *
argument_list|)
name|jpeg_std_error
name|JPP
argument_list|(
operator|(
expr|struct
name|jpeg_error_mgr
operator|*
name|err
operator|)
argument_list|)
decl_stmt|;
comment|/* Initialization of JPEG compression objects.  * jpeg_create_compress() and jpeg_create_decompress() are the exported  * names that applications should call.  These expand to calls on  * jpeg_CreateCompress and jpeg_CreateDecompress with additional information  * passed for version mismatch checking.  * NB: you must set up the error-manager BEFORE calling jpeg_create_xxx.  */
DECL|macro|jpeg_create_compress
define|#
directive|define
name|jpeg_create_compress
parameter_list|(
name|cinfo
parameter_list|)
define|\
value|jpeg_CreateCompress((cinfo), JPEG_LIB_VERSION, \ 			(size_t) sizeof(struct jpeg_compress_struct))
DECL|macro|jpeg_create_decompress
define|#
directive|define
name|jpeg_create_decompress
parameter_list|(
name|cinfo
parameter_list|)
define|\
value|jpeg_CreateDecompress((cinfo), JPEG_LIB_VERSION, \ 			  (size_t) sizeof(struct jpeg_decompress_struct))
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_CreateCompress
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|version
operator|,
name|size_t
name|structsize
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_CreateDecompress
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|int
name|version
operator|,
name|size_t
name|structsize
operator|)
argument_list|)
decl_stmt|;
comment|/* Destruction of JPEG compression objects */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_destroy_compress
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_destroy_decompress
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Standard data source and destination managers: stdio streams. */
comment|/* Caller is responsible for opening the file before and closing after. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_stdio_dest
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|FILE
operator|*
name|outfile
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_stdio_src
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|FILE
operator|*
name|infile
operator|)
argument_list|)
decl_stmt|;
comment|/* Data source and destination managers: memory buffers. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_mem_dest
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|unsigned
name|char
operator|*
operator|*
name|outbuffer
operator|,
name|unsigned
name|long
operator|*
name|outsize
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_mem_src
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|unsigned
name|char
operator|*
name|inbuffer
operator|,
name|unsigned
name|long
name|insize
operator|)
argument_list|)
decl_stmt|;
comment|/* Default parameter setup for compression */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_set_defaults
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Compression parameter setup aids */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_set_colorspace
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|J_COLOR_SPACE
name|colorspace
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_default_colorspace
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_set_quality
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|quality
operator|,
name|boolean
name|force_baseline
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_set_linear_quality
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|scale_factor
operator|,
name|boolean
name|force_baseline
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_default_qtables
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|boolean
name|force_baseline
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_add_quant_table
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|which_tbl
operator|,
specifier|const
name|unsigned
name|int
operator|*
name|basic_table
operator|,
name|int
name|scale_factor
operator|,
name|boolean
name|force_baseline
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|int
argument_list|)
name|jpeg_quality_scaling
name|JPP
argument_list|(
operator|(
name|int
name|quality
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_simple_progression
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_suppress_tables
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|boolean
name|suppress
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|JQUANT_TBL *
argument_list|)
name|jpeg_alloc_quant_table
name|JPP
argument_list|(
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|JHUFF_TBL *
argument_list|)
name|jpeg_alloc_huff_table
name|JPP
argument_list|(
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Main entry points for compression */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_start_compress
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|boolean
name|write_all_tables
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|JDIMENSION
argument_list|)
name|jpeg_write_scanlines
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|JSAMPARRAY
name|scanlines
operator|,
name|JDIMENSION
name|num_lines
operator|)
argument_list|)
decl_stmt|;
DECL|variable|jpeg_finish_compress
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_finish_compress
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Precalculate JPEG dimensions for current compression parameters. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_calc_jpeg_dimensions
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Replaces jpeg_write_scanlines when writing raw downsampled data. */
name|EXTERN
argument_list|(
argument|JDIMENSION
argument_list|)
name|jpeg_write_raw_data
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|JSAMPIMAGE
name|data
operator|,
name|JDIMENSION
name|num_lines
operator|)
argument_list|)
decl_stmt|;
comment|/* Write a special marker.  See libjpeg.txt concerning safe usage. */
DECL|variable|jpeg_write_marker
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_write_marker
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|marker
operator|,
specifier|const
name|JOCTET
operator|*
name|dataptr
operator|,
name|unsigned
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
comment|/* Same, but piecemeal. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_write_m_header
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|marker
operator|,
name|unsigned
name|int
name|datalen
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_write_m_byte
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|int
name|val
operator|)
argument_list|)
decl_stmt|;
comment|/* Alternate compression function: just write an abbreviated table file */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_write_tables
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Decompression startup: read start of JPEG datastream to see what's there */
name|EXTERN
argument_list|(
argument|int
argument_list|)
name|jpeg_read_header
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|boolean
name|require_image
operator|)
argument_list|)
decl_stmt|;
comment|/* Return value is one of: */
DECL|macro|JPEG_SUSPENDED
define|#
directive|define
name|JPEG_SUSPENDED
value|0
comment|/* Suspended due to lack of input data */
DECL|macro|JPEG_HEADER_OK
define|#
directive|define
name|JPEG_HEADER_OK
value|1
comment|/* Found valid image datastream */
DECL|macro|JPEG_HEADER_TABLES_ONLY
define|#
directive|define
name|JPEG_HEADER_TABLES_ONLY
value|2
comment|/* Found valid table-specs-only datastream */
comment|/* If you pass require_image = TRUE (normal case), you need not check for  * a TABLES_ONLY return code; an abbreviated file will cause an error exit.  * JPEG_SUSPENDED is only possible if you use a data source module that can  * give a suspension return (the stdio source module doesn't).  */
comment|/* Main entry points for decompression */
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_start_decompress
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
DECL|variable|jpeg_read_scanlines
name|EXTERN
argument_list|(
argument|JDIMENSION
argument_list|)
name|jpeg_read_scanlines
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|JSAMPARRAY
name|scanlines
operator|,
name|JDIMENSION
name|max_lines
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_finish_decompress
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Replaces jpeg_read_scanlines when reading raw downsampled data. */
DECL|variable|jpeg_read_raw_data
name|EXTERN
argument_list|(
argument|JDIMENSION
argument_list|)
name|jpeg_read_raw_data
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|JSAMPIMAGE
name|data
operator|,
name|JDIMENSION
name|max_lines
operator|)
argument_list|)
decl_stmt|;
comment|/* Additional entry points for buffered-image mode. */
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_has_multiple_scans
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
DECL|variable|jpeg_start_output
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_start_output
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|int
name|scan_number
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_finish_output
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
DECL|variable|jpeg_input_complete
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_input_complete
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_new_colormap
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|int
argument_list|)
name|jpeg_consume_input
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Return value is one of: */
comment|/* #define JPEG_SUSPENDED	0    Suspended due to lack of input data */
DECL|macro|JPEG_REACHED_SOS
define|#
directive|define
name|JPEG_REACHED_SOS
value|1
comment|/* Reached start of new scan */
DECL|macro|JPEG_REACHED_EOI
define|#
directive|define
name|JPEG_REACHED_EOI
value|2
comment|/* Reached end of image */
DECL|macro|JPEG_ROW_COMPLETED
define|#
directive|define
name|JPEG_ROW_COMPLETED
value|3
comment|/* Completed one iMCU row */
DECL|macro|JPEG_SCAN_COMPLETED
define|#
directive|define
name|JPEG_SCAN_COMPLETED
value|4
comment|/* Completed last iMCU row of a scan */
comment|/* Precalculate output dimensions for current decompression parameters. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_core_output_dimensions
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_calc_output_dimensions
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Control saving of COM and APPn markers into marker_list. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_save_markers
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|int
name|marker_code
operator|,
name|unsigned
name|int
name|length_limit
operator|)
argument_list|)
decl_stmt|;
comment|/* Install a special processing method for COM or APPn markers. */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_set_marker_processor
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|int
name|marker_code
operator|,
name|jpeg_marker_parser_method
name|routine
operator|)
argument_list|)
decl_stmt|;
comment|/* Read or write raw DCT coefficients --- useful for lossless transcoding. */
name|EXTERN
argument_list|(
argument|jvirt_barray_ptr *
argument_list|)
name|jpeg_read_coefficients
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_write_coefficients
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|,
name|jvirt_barray_ptr
operator|*
name|coef_arrays
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_copy_critical_parameters
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|srcinfo
operator|,
name|j_compress_ptr
name|dstinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* If you choose to abort compression or decompression before completing  * jpeg_finish_(de)compress, then you need to clean up to release memory,  * temporary files, etc.  You can just call jpeg_destroy_(de)compress  * if you're done with the JPEG object, but if you want to clean it up and  * reuse it, call this:  */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_abort_compress
name|JPP
argument_list|(
operator|(
name|j_compress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_abort_decompress
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Generic versions of jpeg_abort and jpeg_destroy that work on either  * flavor of JPEG object.  These may be more convenient in some places.  */
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_abort
name|JPP
argument_list|(
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
name|EXTERN
argument_list|(
argument|void
argument_list|)
name|jpeg_destroy
name|JPP
argument_list|(
operator|(
name|j_common_ptr
name|cinfo
operator|)
argument_list|)
decl_stmt|;
comment|/* Default restart-marker-resync procedure for use by data source modules */
name|EXTERN
argument_list|(
argument|boolean
argument_list|)
name|jpeg_resync_to_restart
name|JPP
argument_list|(
operator|(
name|j_decompress_ptr
name|cinfo
operator|,
name|int
name|desired
operator|)
argument_list|)
decl_stmt|;
comment|/* These marker codes are exported since applications and data source modules  * are likely to want to use them.  */
DECL|macro|JPEG_RST0
define|#
directive|define
name|JPEG_RST0
value|0xD0
comment|/* RST0 marker code */
DECL|macro|JPEG_EOI
define|#
directive|define
name|JPEG_EOI
value|0xD9
comment|/* EOI marker code */
DECL|macro|JPEG_APP0
define|#
directive|define
name|JPEG_APP0
value|0xE0
comment|/* APP0 marker code */
DECL|macro|JPEG_COM
define|#
directive|define
name|JPEG_COM
value|0xFE
comment|/* COM marker code */
comment|/* If we have a brain-damaged compiler that emits warnings (or worse, errors)  * for structure definitions that are never filled in, keep it quiet by  * supplying dummy definitions for the various substructures.  */
ifdef|#
directive|ifdef
name|INCOMPLETE_TYPES_BROKEN
ifndef|#
directive|ifndef
name|JPEG_INTERNALS
comment|/* will be defined in jpegint.h */
DECL|struct|jvirt_sarray_control
DECL|member|dummy
struct|struct
name|jvirt_sarray_control
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jvirt_barray_control
DECL|member|dummy
struct|struct
name|jvirt_barray_control
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_comp_master
DECL|member|dummy
struct|struct
name|jpeg_comp_master
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_c_main_controller
DECL|member|dummy
struct|struct
name|jpeg_c_main_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_c_prep_controller
DECL|member|dummy
struct|struct
name|jpeg_c_prep_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_c_coef_controller
DECL|member|dummy
struct|struct
name|jpeg_c_coef_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_marker_writer
DECL|member|dummy
struct|struct
name|jpeg_marker_writer
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_color_converter
DECL|member|dummy
struct|struct
name|jpeg_color_converter
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_downsampler
DECL|member|dummy
struct|struct
name|jpeg_downsampler
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_forward_dct
DECL|member|dummy
struct|struct
name|jpeg_forward_dct
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_entropy_encoder
DECL|member|dummy
struct|struct
name|jpeg_entropy_encoder
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_decomp_master
DECL|member|dummy
struct|struct
name|jpeg_decomp_master
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_d_main_controller
DECL|member|dummy
struct|struct
name|jpeg_d_main_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_d_coef_controller
DECL|member|dummy
struct|struct
name|jpeg_d_coef_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_d_post_controller
DECL|member|dummy
struct|struct
name|jpeg_d_post_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_input_controller
DECL|member|dummy
struct|struct
name|jpeg_input_controller
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_marker_reader
DECL|member|dummy
struct|struct
name|jpeg_marker_reader
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_entropy_decoder
DECL|member|dummy
struct|struct
name|jpeg_entropy_decoder
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_inverse_dct
DECL|member|dummy
struct|struct
name|jpeg_inverse_dct
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_upsampler
DECL|member|dummy
struct|struct
name|jpeg_upsampler
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_color_deconverter
DECL|member|dummy
struct|struct
name|jpeg_color_deconverter
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
DECL|struct|jpeg_color_quantizer
DECL|member|dummy
struct|struct
name|jpeg_color_quantizer
block|{
name|long
name|dummy
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
comment|/* JPEG_INTERNALS */
endif|#
directive|endif
comment|/* INCOMPLETE_TYPES_BROKEN */
comment|/*  * The JPEG library modules define JPEG_INTERNALS before including this file.  * The internal structure declarations are read only when that is true.  * Applications using the library should not include jpegint.h, but may wish  * to include jerror.h.  */
ifdef|#
directive|ifdef
name|JPEG_INTERNALS
include|#
directive|include
file|"jpegint.h"
comment|/* fetch private declarations */
include|#
directive|include
file|"jerror.h"
comment|/* fetch error codes too */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
ifndef|#
directive|ifndef
name|DONT_USE_EXTERN_C
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* JPEGLIB_H */
end_comment
end_unit
