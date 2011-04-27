begin_unit
begin_comment
comment|/* $Id: tiffconf.wince.h,v 1.1.2.1 2009-01-01 17:52:51 bfriesen Exp $ */
end_comment
begin_comment
comment|/*  * Windows CE platform tiffconf.wince.h  * Created by Mateusz Loskot (mateusz@loskot.net)  *  * NOTE: Requires WCELIBCEX library with wceex_* functions,  * It's an extension to C library on Windows CE platform.  * For example, HAVE_STDIO_H definition indicates there are  * following files available:  * stdio.h - from Windows CE / Windows Mobile SDK   * wce_stdio.h - from WCELIBCEX library  */
end_comment
begin_comment
comment|/*   Configuration defines for installed libtiff.   This file maintained for backward compatibility. Do not use definitions   from this file in your programs. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef
begin_error
error|#
directive|error
error|This version of tif_config.h header is dedicated for Windows CE platform!
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|_TIFFCONF_
end_ifndef
begin_define
DECL|macro|_TIFFCONF_
define|#
directive|define
name|_TIFFCONF_
end_define
begin_comment
comment|/* Define to 1 if the system has the type `int16'. */
end_comment
begin_comment
comment|/* #undef HAVE_INT16 */
end_comment
begin_comment
comment|/* Define to 1 if the system has the type `int32'. */
end_comment
begin_comment
comment|/* #undef HAVE_INT32 */
end_comment
begin_comment
comment|/* Define to 1 if the system has the type `int8'. */
end_comment
begin_comment
comment|/* #undef HAVE_INT8 */
end_comment
begin_comment
comment|/* The size of a `int', as computed by sizeof. */
end_comment
begin_define
DECL|macro|SIZEOF_INT
define|#
directive|define
name|SIZEOF_INT
value|4
end_define
begin_comment
comment|/* The size of a `long', as computed by sizeof. */
end_comment
begin_define
DECL|macro|SIZEOF_LONG
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define
begin_comment
comment|/* Signed 64-bit type formatter */
end_comment
begin_define
DECL|macro|TIFF_INT64_FORMAT
define|#
directive|define
name|TIFF_INT64_FORMAT
value|"%I64d"
end_define
begin_comment
comment|/* Signed 64-bit type */
end_comment
begin_define
DECL|macro|TIFF_INT64_T
define|#
directive|define
name|TIFF_INT64_T
value|signed __int64
end_define
begin_comment
comment|/* Unsigned 64-bit type formatter */
end_comment
begin_define
DECL|macro|TIFF_UINT64_FORMAT
define|#
directive|define
name|TIFF_UINT64_FORMAT
value|"%I64u"
end_define
begin_comment
comment|/* Unsigned 64-bit type */
end_comment
begin_define
DECL|macro|TIFF_UINT64_T
define|#
directive|define
name|TIFF_UINT64_T
value|unsigned __int64
end_define
begin_comment
comment|/* Compatibility stuff. */
end_comment
begin_comment
comment|/* Define as 0 or 1 according to the floating point format suported by the    machine */
end_comment
begin_define
DECL|macro|HAVE_IEEEFP
define|#
directive|define
name|HAVE_IEEEFP
value|1
end_define
begin_comment
comment|/* Set the native cpu bit order (FILLORDER_LSB2MSB or FILLORDER_MSB2LSB) */
end_comment
begin_define
DECL|macro|HOST_FILLORDER
define|#
directive|define
name|HOST_FILLORDER
value|FILLORDER_LSB2MSB
end_define
begin_comment
comment|/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian    (Intel) */
end_comment
begin_define
DECL|macro|HOST_BIGENDIAN
define|#
directive|define
name|HOST_BIGENDIAN
value|0
end_define
begin_comment
comment|/* Support CCITT Group 3& 4 algorithms */
end_comment
begin_define
DECL|macro|CCITT_SUPPORT
define|#
directive|define
name|CCITT_SUPPORT
value|1
end_define
begin_comment
comment|/* Support JPEG compression (requires IJG JPEG library) */
end_comment
begin_comment
comment|/* #undef JPEG_SUPPORT */
end_comment
begin_comment
comment|/* Support LogLuv high dynamic range encoding */
end_comment
begin_define
DECL|macro|LOGLUV_SUPPORT
define|#
directive|define
name|LOGLUV_SUPPORT
value|1
end_define
begin_comment
comment|/* Support LZW algorithm */
end_comment
begin_define
DECL|macro|LZW_SUPPORT
define|#
directive|define
name|LZW_SUPPORT
value|1
end_define
begin_comment
comment|/* Support NeXT 2-bit RLE algorithm */
end_comment
begin_define
DECL|macro|NEXT_SUPPORT
define|#
directive|define
name|NEXT_SUPPORT
value|1
end_define
begin_comment
comment|/* Support Old JPEG compresson (read contrib/ojpeg/README first! Compilation    fails with unpatched IJG JPEG library) */
end_comment
begin_comment
comment|/* #undef OJPEG_SUPPORT */
end_comment
begin_comment
comment|/* Support Macintosh PackBits algorithm */
end_comment
begin_define
DECL|macro|PACKBITS_SUPPORT
define|#
directive|define
name|PACKBITS_SUPPORT
value|1
end_define
begin_comment
comment|/* Support Pixar log-format algorithm (requires Zlib) */
end_comment
begin_comment
comment|/* #undef PIXARLOG_SUPPORT */
end_comment
begin_comment
comment|/* Support ThunderScan 4-bit RLE algorithm */
end_comment
begin_define
DECL|macro|THUNDER_SUPPORT
define|#
directive|define
name|THUNDER_SUPPORT
value|1
end_define
begin_comment
comment|/* Support Deflate compression */
end_comment
begin_comment
comment|/* #undef ZIP_SUPPORT */
end_comment
begin_comment
comment|/* Support strip chopping (whether or not to convert single-strip uncompressed    images to mutiple strips of ~8Kb to reduce memory usage) */
end_comment
begin_define
DECL|macro|STRIPCHOP_DEFAULT
define|#
directive|define
name|STRIPCHOP_DEFAULT
value|TIFF_STRIPCHOP
end_define
begin_comment
comment|/* Enable SubIFD tag (330) support */
end_comment
begin_define
DECL|macro|SUBIFD_SUPPORT
define|#
directive|define
name|SUBIFD_SUPPORT
value|1
end_define
begin_comment
comment|/* Treat extra sample as alpha (default enabled). The RGBA interface will    treat a fourth sample with no EXTRASAMPLE_ value as being ASSOCALPHA. Many    packages produce RGBA files but don't mark the alpha properly. */
end_comment
begin_define
DECL|macro|DEFAULT_EXTRASAMPLE_AS_ALPHA
define|#
directive|define
name|DEFAULT_EXTRASAMPLE_AS_ALPHA
value|1
end_define
begin_comment
comment|/* Pick up YCbCr subsampling info from the JPEG data stream to support files    lacking the tag (default enabled). */
end_comment
begin_define
DECL|macro|CHECK_JPEG_YCBCR_SUBSAMPLING
define|#
directive|define
name|CHECK_JPEG_YCBCR_SUBSAMPLING
value|1
end_define
begin_comment
comment|/*  * Feature support definitions.  * XXX: These macros are obsoleted. Don't use them in your apps!  * Macros stays here for backward compatibility and should be always defined.  */
end_comment
begin_define
DECL|macro|COLORIMETRY_SUPPORT
define|#
directive|define
name|COLORIMETRY_SUPPORT
end_define
begin_define
DECL|macro|YCBCR_SUPPORT
define|#
directive|define
name|YCBCR_SUPPORT
end_define
begin_define
DECL|macro|CMYK_SUPPORT
define|#
directive|define
name|CMYK_SUPPORT
end_define
begin_define
DECL|macro|ICC_SUPPORT
define|#
directive|define
name|ICC_SUPPORT
end_define
begin_define
DECL|macro|PHOTOSHOP_SUPPORT
define|#
directive|define
name|PHOTOSHOP_SUPPORT
end_define
begin_define
DECL|macro|IPTC_SUPPORT
define|#
directive|define
name|IPTC_SUPPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _TIFFCONF_ */
end_comment
end_unit
