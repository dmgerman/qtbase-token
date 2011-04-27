begin_unit
begin_comment
comment|/*  * cderror.h  *  * Copyright (C) 1994-1997, Thomas G. Lane.  * Modified 2009 by Guido Vollbeding.  * This file is part of the Independent JPEG Group's software.  * For conditions of distribution and use, see the accompanying README file.  *  * This file defines the error and message codes for the cjpeg/djpeg  * applications.  These strings are not needed as part of the JPEG library  * proper.  * Edit this file to add new codes, or to translate the message strings to  * some other language.  */
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
name|CDERROR_H
end_ifndef
begin_define
DECL|macro|CDERROR_H
define|#
directive|define
name|CDERROR_H
end_define
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
comment|/* CDERROR_H */
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
argument|JMSG_FIRSTADDONCODE=
literal|1000
argument_list|,
argument|NULL
argument_list|)
comment|/* Must be first entry! */
ifdef|#
directive|ifdef
name|BMP_SUPPORTED
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_BADCMAP
argument_list|,
literal|"Unsupported BMP colormap format"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_BADDEPTH
argument_list|,
literal|"Only 8- and 24-bit BMP files are supported"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_BADHEADER
argument_list|,
literal|"Invalid BMP file: bad header length"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_BADPLANES
argument_list|,
literal|"Invalid BMP file: biPlanes not equal to 1"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_COLORSPACE
argument_list|,
literal|"BMP output must be grayscale or RGB"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_COMPRESSED
argument_list|,
literal|"Sorry, compressed BMPs not yet supported"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_EMPTY
argument_list|,
literal|"Empty BMP image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BMP_NOT
argument_list|,
literal|"Not a BMP file - does not start with BM"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_BMP
argument_list|,
literal|"%ux%u 24-bit BMP image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_BMP_MAPPED
argument_list|,
literal|"%ux%u 8-bit colormapped BMP image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_BMP_OS2
argument_list|,
literal|"%ux%u 24-bit OS2 BMP image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_BMP_OS2_MAPPED
argument_list|,
literal|"%ux%u 8-bit colormapped OS2 BMP image"
argument_list|)
endif|#
directive|endif
comment|/* BMP_SUPPORTED */
ifdef|#
directive|ifdef
name|GIF_SUPPORTED
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_GIF_BUG
argument_list|,
literal|"GIF output got confused"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_GIF_CODESIZE
argument_list|,
literal|"Bogus GIF codesize %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_GIF_COLORSPACE
argument_list|,
literal|"GIF output must be grayscale or RGB"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_GIF_IMAGENOTFOUND
argument_list|,
literal|"Too few images in GIF file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_GIF_NOT
argument_list|,
literal|"Not a GIF file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_GIF
argument_list|,
literal|"%ux%ux%d GIF image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_GIF_BADVERSION
argument_list|,
literal|"Warning: unexpected GIF version number '%c%c%c'"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_GIF_EXTENSION
argument_list|,
literal|"Ignoring GIF extension block of type 0x%02x"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_GIF_NONSQUARE
argument_list|,
literal|"Caution: nonsquare pixels in input"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JWRN_GIF_BADDATA
argument_list|,
literal|"Corrupt data in GIF file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JWRN_GIF_CHAR
argument_list|,
literal|"Bogus char 0x%02x in GIF file, ignoring"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JWRN_GIF_ENDCODE
argument_list|,
literal|"Premature end of GIF image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JWRN_GIF_NOMOREDATA
argument_list|,
literal|"Ran out of GIF bits"
argument_list|)
endif|#
directive|endif
comment|/* GIF_SUPPORTED */
ifdef|#
directive|ifdef
name|PPM_SUPPORTED
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_PPM_COLORSPACE
argument_list|,
literal|"PPM output must be grayscale or RGB"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_PPM_NONNUMERIC
argument_list|,
literal|"Nonnumeric data in PPM file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_PPM_NOT
argument_list|,
literal|"Not a PPM/PGM file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_PGM
argument_list|,
literal|"%ux%u PGM image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_PGM_TEXT
argument_list|,
literal|"%ux%u text PGM image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_PPM
argument_list|,
literal|"%ux%u PPM image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_PPM_TEXT
argument_list|,
literal|"%ux%u text PPM image"
argument_list|)
endif|#
directive|endif
comment|/* PPM_SUPPORTED */
ifdef|#
directive|ifdef
name|RLE_SUPPORTED
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_BADERROR
argument_list|,
literal|"Bogus error code from RLE library"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_COLORSPACE
argument_list|,
literal|"RLE output must be grayscale or RGB"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_DIMENSIONS
argument_list|,
literal|"Image dimensions (%ux%u) too large for RLE"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_EMPTY
argument_list|,
literal|"Empty RLE file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_EOF
argument_list|,
literal|"Premature EOF in RLE header"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_MEM
argument_list|,
literal|"Insufficient memory for RLE header"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_NOT
argument_list|,
literal|"Not an RLE file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_TOOMANYCHANNELS
argument_list|,
literal|"Cannot handle %d output channels for RLE"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_RLE_UNSUPPORTED
argument_list|,
literal|"Cannot handle this RLE setup"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_RLE
argument_list|,
literal|"%ux%u full-color RLE file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_RLE_FULLMAP
argument_list|,
literal|"%ux%u full-color RLE file with map of length %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_RLE_GRAY
argument_list|,
literal|"%ux%u grayscale RLE file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_RLE_MAPGRAY
argument_list|,
literal|"%ux%u grayscale RLE file with map of length %d"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_RLE_MAPPED
argument_list|,
literal|"%ux%u colormapped RLE file with map of length %d"
argument_list|)
endif|#
directive|endif
comment|/* RLE_SUPPORTED */
ifdef|#
directive|ifdef
name|TARGA_SUPPORTED
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TGA_BADCMAP
argument_list|,
literal|"Unsupported Targa colormap format"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TGA_BADPARMS
argument_list|,
literal|"Invalid or unsupported Targa file"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TGA_COLORSPACE
argument_list|,
literal|"Targa output must be grayscale or RGB"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_TGA
argument_list|,
literal|"%ux%u RGB Targa image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_TGA_GRAY
argument_list|,
literal|"%ux%u grayscale Targa image"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JTRC_TGA_MAPPED
argument_list|,
literal|"%ux%u colormapped Targa image"
argument_list|)
else|#
directive|else
name|JMESSAGE
argument_list|(
argument|JERR_TGA_NOTCOMP
argument_list|,
literal|"Targa support was not compiled"
argument_list|)
endif|#
directive|endif
comment|/* TARGA_SUPPORTED */
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_BAD_CMAP_FILE
argument_list|,
literal|"Color map file is invalid or of unsupported format"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_TOO_MANY_COLORS
argument_list|,
literal|"Output file format cannot handle %d colormap entries"
argument_list|)
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_UNGETC_FAILED
argument_list|,
literal|"ungetc failed"
argument_list|)
ifdef|#
directive|ifdef
name|TARGA_SUPPORTED
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_UNKNOWN_FORMAT
argument_list|,
literal|"Unrecognized input file format --- perhaps you need -targa"
argument_list|)
else|#
directive|else
name|JMESSAGE
argument_list|(
argument|JERR_UNKNOWN_FORMAT
argument_list|,
literal|"Unrecognized input file format"
argument_list|)
endif|#
directive|endif
DECL|enumerator|JMESSAGE
name|JMESSAGE
argument_list|(
argument|JERR_UNSUPPORTED_FORMAT
argument_list|,
literal|"Unsupported output file format"
argument_list|)
ifdef|#
directive|ifdef
name|JMAKE_ENUM_LIST
DECL|enumerator|JMSG_LASTADDONCODE
name|JMSG_LASTADDONCODE
block|}
DECL|typedef|ADDON_MESSAGE_CODE
name|ADDON_MESSAGE_CODE
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
end_unit
