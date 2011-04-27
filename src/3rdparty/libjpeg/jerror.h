begin_unit
begin_comment
comment|/*  * jerror.h  *  * Copyright (C) 1994-1997, Thomas G. Lane.  * Modified 1997-2009 by Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file defines the error and message codes for the JPEG library.  * Edit this file to add new codes, or to translate the message strings to  * some other language.  * A set of error-reporting macros are defined too.  Some applications using  * the JPEG library may wish to include this file to get the error codes  * and/or the macros.  */
end_comment
begin_comment
comment|/*  * To define the enum list of message codes, include this file without  * defining macro JMESSAGE.  To create a message string table, include it  * again with a suitable JMESSAGE definition (see jerror.c for an example).  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|JMESSAGE
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|JERROR_H
end_ifndef
begin_comment
comment|/* First time through, define the enum list */
end_comment
begin_define
DECL|macro|JMAKE_ENUM_LIST
define|#
directive|define
name|JMAKE_ENUM_LIST
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* Repeated inclusions of this file are no-ops unless JMESSAGE is defined */
end_comment
begin_define
DECL|macro|JMESSAGE
define|#
directive|define
name|JMESSAGE
parameter_list|(
name|code
parameter_list|,
name|string
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* JERROR_H */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* JMESSAGE */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|JMAKE_ENUM_LIST
end_ifdef
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|macro|JMESSAGE
define|#
directive|define
name|JMESSAGE
parameter_list|(
name|code
parameter_list|,
name|string
parameter_list|)
value|code ,
endif|#
directive|endif
comment|/* JMAKE_ENUM_LIST */
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JMSG_NOMESSAGE
argument_list|,
literal|"Bogus message code %d"
argument_list|)
comment|/* Must be first entry! */
comment|/* For maintenance convenience, list is alphabetical by message code name */
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_ALIGN_TYPE
argument_list|,
literal|"ALIGN_TYPE is wrong, please fix"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_ALLOC_CHUNK
argument_list|,
literal|"MAX_ALLOC_CHUNK is wrong, please fix"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_BUFFER_MODE
argument_list|,
literal|"Bogus buffer control mode"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_COMPONENT_ID
argument_list|,
literal|"Invalid component ID %d in SOS"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_CROP_SPEC
argument_list|,
literal|"Invalid crop request"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_DCT_COEF
argument_list|,
literal|"DCT coefficient out of range"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_DCTSIZE
argument_list|,
literal|"DCT scaled block size %dx%d not supported"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_DROP_SAMPLING
argument_list|,
literal|"Component index %d: mismatching sampling ratio %d:%d, %d:%d, %c"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_HUFF_TABLE
argument_list|,
literal|"Bogus Huffman table definition"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_IN_COLORSPACE
argument_list|,
literal|"Bogus input colorspace"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_J_COLORSPACE
argument_list|,
literal|"Bogus JPEG colorspace"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_LENGTH
argument_list|,
literal|"Bogus marker length"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_LIB_VERSION
argument_list|,
literal|"Wrong JPEG library version: library is %d, caller expects %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_MCU_SIZE
argument_list|,
literal|"Sampling factors too large for interleaved scan"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_POOL_ID
argument_list|,
literal|"Invalid memory pool code %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_PRECISION
argument_list|,
literal|"Unsupported JPEG data precision %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_PROGRESSION
argument_list|,
literal|"Invalid progressive parameters Ss=%d Se=%d Ah=%d Al=%d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_PROG_SCRIPT
argument_list|,
literal|"Invalid progressive parameters at scan script entry %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_SAMPLING
argument_list|,
literal|"Bogus sampling factors"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_SCAN_SCRIPT
argument_list|,
literal|"Invalid scan script at entry %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_STATE
argument_list|,
literal|"Improper call to JPEG library in state %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_STRUCT_SIZE
argument_list|,
literal|"JPEG parameter struct mismatch: library thinks size is %u, caller expects %u"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_VIRTUAL_ACCESS
argument_list|,
literal|"Bogus virtual array access"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BUFFER_SIZE
argument_list|,
literal|"Buffer passed to JPEG library is too small"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_CANT_SUSPEND
argument_list|,
literal|"Suspension not allowed here"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_CCIR601_NOTIMPL
argument_list|,
literal|"CCIR601 sampling not implemented yet"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_COMPONENT_COUNT
argument_list|,
literal|"Too many color components: %d, max %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_CONVERSION_NOTIMPL
argument_list|,
literal|"Unsupported color conversion request"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_DAC_INDEX
argument_list|,
literal|"Bogus DAC index %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_DAC_VALUE
argument_list|,
literal|"Bogus DAC value 0x%x"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_DHT_INDEX
argument_list|,
literal|"Bogus DHT index %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_DQT_INDEX
argument_list|,
literal|"Bogus DQT index %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_EMPTY_IMAGE
argument_list|,
literal|"Empty JPEG image (DNL not supported)"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_EMS_READ
argument_list|,
literal|"Read from EMS failed"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_EMS_WRITE
argument_list|,
literal|"Write to EMS failed"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_EOI_EXPECTED
argument_list|,
literal|"Didn't expect more than one scan"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_FILE_READ
argument_list|,
literal|"Input file read error"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_FILE_WRITE
argument_list|,
literal|"Output file write error --- out of disk space?"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_FRACT_SAMPLE_NOTIMPL
argument_list|,
literal|"Fractional sampling not implemented yet"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_HUFF_CLEN_OVERFLOW
argument_list|,
literal|"Huffman code size table overflow"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_HUFF_MISSING_CODE
argument_list|,
literal|"Missing Huffman code table entry"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_IMAGE_TOO_BIG
argument_list|,
literal|"Maximum supported image dimension is %u pixels"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_INPUT_EMPTY
argument_list|,
literal|"Empty input file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_INPUT_EOF
argument_list|,
literal|"Premature end of input file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_MISMATCHED_QUANT_TABLE
argument_list|,
literal|"Cannot transcode due to multiple use of quantization table %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_MISSING_DATA
argument_list|,
literal|"Scan script does not transmit all data"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_MODE_CHANGE
argument_list|,
literal|"Invalid color quantization mode change"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NOTIMPL
argument_list|,
literal|"Not implemented yet"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NOT_COMPILED
argument_list|,
literal|"Requested feature was omitted at compile time"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NO_ARITH_TABLE
argument_list|,
literal|"Arithmetic table 0x%02x was not defined"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NO_BACKING_STORE
argument_list|,
literal|"Backing store not supported"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NO_HUFF_TABLE
argument_list|,
literal|"Huffman table 0x%02x was not defined"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NO_IMAGE
argument_list|,
literal|"JPEG datastream contains no image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NO_QUANT_TABLE
argument_list|,
literal|"Quantization table 0x%02x was not defined"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_NO_SOI
argument_list|,
literal|"Not a JPEG file: starts with 0x%02x 0x%02x"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_OUT_OF_MEMORY
argument_list|,
literal|"Insufficient memory (case %d)"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_QUANT_COMPONENTS
argument_list|,
literal|"Cannot quantize more than %d color components"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_QUANT_FEW_COLORS
argument_list|,
literal|"Cannot quantize to fewer than %d colors"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_QUANT_MANY_COLORS
argument_list|,
literal|"Cannot quantize to more than %d colors"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_SOF_DUPLICATE
argument_list|,
literal|"Invalid JPEG file structure: two SOF markers"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_SOF_NO_SOS
argument_list|,
literal|"Invalid JPEG file structure: missing SOS marker"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_SOF_UNSUPPORTED
argument_list|,
literal|"Unsupported JPEG process: SOF type 0x%02x"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_SOI_DUPLICATE
argument_list|,
literal|"Invalid JPEG file structure: two SOI markers"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_SOS_NO_SOF
argument_list|,
literal|"Invalid JPEG file structure: SOS before SOF"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TFILE_CREATE
argument_list|,
literal|"Failed to create temporary file %s"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TFILE_READ
argument_list|,
literal|"Read failed on temporary file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TFILE_SEEK
argument_list|,
literal|"Seek failed on temporary file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TFILE_WRITE
argument_list|,
literal|"Write failed on temporary file --- out of disk space?"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TOO_LITTLE_DATA
argument_list|,
literal|"Application transferred too few scanlines"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_UNKNOWN_MARKER
argument_list|,
literal|"Unsupported marker type 0x%02x"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_VIRTUAL_BUG
argument_list|,
literal|"Virtual array controller messed up"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_WIDTH_OVERFLOW
argument_list|,
literal|"Image too wide for this implementation"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_XMS_READ
argument_list|,
literal|"Read from XMS failed"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_XMS_WRITE
argument_list|,
literal|"Write to XMS failed"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JMSG_COPYRIGHT
argument_list|,
argument|JCOPYRIGHT
argument_list|)
name|JMESSAGE
argument_list|(
argument|JMSG_VERSION
argument_list|,
argument|JVERSION
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_16BIT_TABLES
argument_list|,
literal|"Caution: quantization tables are too coarse for baseline JPEG"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_ADOBE
argument_list|,
literal|"Adobe APP14 marker: version %d, flags 0x%04x 0x%04x, transform %d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_APP0
argument_list|,
literal|"Unknown APP0 marker (not JFIF), length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_APP14
argument_list|,
literal|"Unknown APP14 marker (not Adobe), length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_DAC
argument_list|,
literal|"Define Arithmetic Table 0x%02x: 0x%02x"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_DHT
argument_list|,
literal|"Define Huffman Table 0x%02x"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_DQT
argument_list|,
literal|"Define Quantization Table %d  precision %d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_DRI
argument_list|,
literal|"Define Restart Interval %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_EMS_CLOSE
argument_list|,
literal|"Freed EMS handle %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_EMS_OPEN
argument_list|,
literal|"Obtained EMS handle %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_EOI
argument_list|,
literal|"End Of Image"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_HUFFBITS
argument_list|,
literal|"        %3d %3d %3d %3d %3d %3d %3d %3d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_JFIF
argument_list|,
literal|"JFIF APP0 marker: version %d.%02d, density %dx%d  %d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_JFIF_BADTHUMBNAILSIZE
argument_list|,
literal|"Warning: thumbnail image size does not match data length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_JFIF_EXTENSION
argument_list|,
literal|"JFIF extension marker: type 0x%02x, length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_JFIF_THUMBNAIL
argument_list|,
literal|"    with %d x %d thumbnail image"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_MISC_MARKER
argument_list|,
literal|"Miscellaneous marker 0x%02x, length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_PARMLESS_MARKER
argument_list|,
literal|"Unexpected marker 0x%02x"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_QUANTVALS
argument_list|,
literal|"        %4u %4u %4u %4u %4u %4u %4u %4u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_QUANT_3_NCOLORS
argument_list|,
literal|"Quantizing to %d = %d*%d*%d colors"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_QUANT_NCOLORS
argument_list|,
literal|"Quantizing to %d colors"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_QUANT_SELECTED
argument_list|,
literal|"Selected %d colors for quantization"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_RECOVERY_ACTION
argument_list|,
literal|"At marker 0x%02x, recovery action %d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_RST
argument_list|,
literal|"RST%d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SMOOTH_NOTIMPL
argument_list|,
literal|"Smoothing not supported with nonstandard sampling ratios"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SOF
argument_list|,
literal|"Start Of Frame 0x%02x: width=%u, height=%u, components=%d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SOF_COMPONENT
argument_list|,
literal|"    Component %d: %dhx%dv q=%d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SOI
argument_list|,
literal|"Start of Image"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SOS
argument_list|,
literal|"Start Of Scan: %d components"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SOS_COMPONENT
argument_list|,
literal|"    Component %d: dc=%d ac=%d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_SOS_PARAMS
argument_list|,
literal|"  Ss=%d, Se=%d, Ah=%d, Al=%d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_TFILE_CLOSE
argument_list|,
literal|"Closed temporary file %s"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_TFILE_OPEN
argument_list|,
literal|"Opened temporary file %s"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_THUMB_JPEG
argument_list|,
literal|"JFIF extension marker: JPEG-compressed thumbnail image, length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_THUMB_PALETTE
argument_list|,
literal|"JFIF extension marker: palette thumbnail image, length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_THUMB_RGB
argument_list|,
literal|"JFIF extension marker: RGB thumbnail image, length %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_UNKNOWN_IDS
argument_list|,
literal|"Unrecognized component IDs %d %d %d, assuming YCbCr"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_XMS_CLOSE
argument_list|,
literal|"Freed XMS handle %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JTRC_XMS_OPEN
argument_list|,
literal|"Obtained XMS handle %u"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_ADOBE_XFORM
argument_list|,
literal|"Unknown Adobe color transform code %d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_ARITH_BAD_CODE
argument_list|,
literal|"Corrupt JPEG data: bad arithmetic code"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_BOGUS_PROGRESSION
argument_list|,
literal|"Inconsistent progression sequence for component %d coefficient %d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_EXTRANEOUS_DATA
argument_list|,
literal|"Corrupt JPEG data: %u extraneous bytes before marker 0x%02x"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_HIT_MARKER
argument_list|,
literal|"Corrupt JPEG data: premature end of data segment"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_HUFF_BAD_CODE
argument_list|,
literal|"Corrupt JPEG data: bad Huffman code"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_JFIF_MAJOR
argument_list|,
literal|"Warning: unknown JFIF revision number %d.%02d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_JPEG_EOF
argument_list|,
literal|"Premature end of JPEG file"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_MUST_RESYNC
argument_list|,
literal|"Corrupt JPEG data: found marker 0x%02x instead of RST%d"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_NOT_SEQUENTIAL
argument_list|,
literal|"Invalid SOS parameters for sequential JPEG"
argument_list|)
name|JMESSAGE
argument_list|(
argument|JWRN_TOO_MUCH_DATA
argument_list|,
literal|"Application transferred too many scanlines"
argument_list|)
ifdef|#
directive|ifdef
name|JMAKE_ENUM_LIST
name|JMSG_LASTMSGCODE
block|}
DECL|typedef|J_MESSAGE_CODE
name|J_MESSAGE_CODE
typedef|;
end_typedef
begin_undef
DECL|macro|JMAKE_ENUM_LIST
undef|#
directive|undef
name|JMAKE_ENUM_LIST
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* JMAKE_ENUM_LIST */
end_comment
begin_comment
comment|/* Zap JMESSAGE macro so that future re-inclusions do nothing by default */
end_comment
begin_undef
DECL|macro|JMESSAGE
undef|#
directive|undef
name|JMESSAGE
end_undef
begin_ifndef
ifndef|#
directive|ifndef
name|JERROR_H
end_ifndef
begin_define
DECL|macro|JERROR_H
define|#
directive|define
name|JERROR_H
end_define
begin_comment
comment|/* Macros to simplify using the error and trace message stuff */
end_comment
begin_comment
comment|/* The first parameter is either type of cinfo pointer */
end_comment
begin_comment
comment|/* Fatal errors (print message and exit) */
end_comment
begin_define
DECL|macro|ERREXIT
define|#
directive|define
name|ERREXIT
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|ERREXIT1
define|#
directive|define
name|ERREXIT1
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|ERREXIT2
define|#
directive|define
name|ERREXIT2
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (cinfo)->err->msg_parm.i[1] = (p2), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|ERREXIT3
define|#
directive|define
name|ERREXIT3
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (cinfo)->err->msg_parm.i[1] = (p2), \    (cinfo)->err->msg_parm.i[2] = (p3), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|ERREXIT4
define|#
directive|define
name|ERREXIT4
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (cinfo)->err->msg_parm.i[1] = (p2), \    (cinfo)->err->msg_parm.i[2] = (p3), \    (cinfo)->err->msg_parm.i[3] = (p4), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|ERREXIT6
define|#
directive|define
name|ERREXIT6
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (cinfo)->err->msg_parm.i[1] = (p2), \    (cinfo)->err->msg_parm.i[2] = (p3), \    (cinfo)->err->msg_parm.i[3] = (p4), \    (cinfo)->err->msg_parm.i[4] = (p5), \    (cinfo)->err->msg_parm.i[5] = (p6), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|ERREXITS
define|#
directive|define
name|ERREXITS
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|str
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    strncpy((cinfo)->err->msg_parm.s, (str), JMSG_STR_PARM_MAX), \    (*(cinfo)->err->error_exit) ((j_common_ptr) (cinfo)))
end_define
begin_define
DECL|macro|MAKESTMT
define|#
directive|define
name|MAKESTMT
parameter_list|(
name|stuff
parameter_list|)
value|do { stuff } while (0)
end_define
begin_comment
comment|/* Nonfatal errors (we can keep going, but the data is probably corrupt) */
end_comment
begin_define
DECL|macro|WARNMS
define|#
directive|define
name|WARNMS
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), -1))
end_define
begin_define
DECL|macro|WARNMS1
define|#
directive|define
name|WARNMS1
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), -1))
end_define
begin_define
DECL|macro|WARNMS2
define|#
directive|define
name|WARNMS2
parameter_list|(
name|cinfo
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (cinfo)->err->msg_parm.i[1] = (p2), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), -1))
end_define
begin_comment
comment|/* Informational/debugging messages */
end_comment
begin_define
DECL|macro|TRACEMS
define|#
directive|define
name|TRACEMS
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)))
end_define
begin_define
DECL|macro|TRACEMS1
define|#
directive|define
name|TRACEMS1
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)))
end_define
begin_define
DECL|macro|TRACEMS2
define|#
directive|define
name|TRACEMS2
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    (cinfo)->err->msg_parm.i[0] = (p1), \    (cinfo)->err->msg_parm.i[1] = (p2), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)))
end_define
begin_define
DECL|macro|TRACEMS3
define|#
directive|define
name|TRACEMS3
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
define|\
value|MAKESTMT(int * _mp = (cinfo)->err->msg_parm.i; \ 	   _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); \ 	   (cinfo)->err->msg_code = (code); \ 	   (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)); )
end_define
begin_define
DECL|macro|TRACEMS4
define|#
directive|define
name|TRACEMS4
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
define|\
value|MAKESTMT(int * _mp = (cinfo)->err->msg_parm.i; \ 	   _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); _mp[3] = (p4); \ 	   (cinfo)->err->msg_code = (code); \ 	   (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)); )
end_define
begin_define
DECL|macro|TRACEMS5
define|#
directive|define
name|TRACEMS5
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|)
define|\
value|MAKESTMT(int * _mp = (cinfo)->err->msg_parm.i; \ 	   _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); _mp[3] = (p4); \ 	   _mp[4] = (p5); \ 	   (cinfo)->err->msg_code = (code); \ 	   (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)); )
end_define
begin_define
DECL|macro|TRACEMS8
define|#
directive|define
name|TRACEMS8
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|,
name|p5
parameter_list|,
name|p6
parameter_list|,
name|p7
parameter_list|,
name|p8
parameter_list|)
define|\
value|MAKESTMT(int * _mp = (cinfo)->err->msg_parm.i; \ 	   _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); _mp[3] = (p4); \ 	   _mp[4] = (p5); _mp[5] = (p6); _mp[6] = (p7); _mp[7] = (p8); \ 	   (cinfo)->err->msg_code = (code); \ 	   (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)); )
end_define
begin_define
DECL|macro|TRACEMSS
define|#
directive|define
name|TRACEMSS
parameter_list|(
name|cinfo
parameter_list|,
name|lvl
parameter_list|,
name|code
parameter_list|,
name|str
parameter_list|)
define|\
value|((cinfo)->err->msg_code = (code), \    strncpy((cinfo)->err->msg_parm.s, (str), JMSG_STR_PARM_MAX), \    (*(cinfo)->err->emit_message) ((j_common_ptr) (cinfo), (lvl)))
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* JERROR_H */
end_comment
end_unit
