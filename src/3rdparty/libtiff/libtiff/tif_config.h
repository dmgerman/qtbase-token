begin_unit
begin_comment
comment|/*   Configuration defines for Qt. */
end_comment
begin_include
include|#
directive|include
file|<qglobal.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_include
include|#
directive|include
file|<qfunctions_wince.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define if building universal (internal helper macro) */
end_comment
begin_comment
comment|/* #undef AC_APPLE_UNIVERSAL_BUILD */
end_comment
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
comment|/* Support C++ stream API (requires C++ compiler) */
end_comment
begin_comment
comment|/* #undef CXX_SUPPORT */
end_comment
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
comment|/* Use the Apple OpenGL framework. */
end_comment
begin_comment
comment|/* #undef HAVE_APPLE_OPENGL_FRAMEWORK */
end_comment
begin_comment
comment|/* Define to 1 if you have the<assert.h> header file. */
end_comment
begin_define
DECL|macro|HAVE_ASSERT_H
define|#
directive|define
name|HAVE_ASSERT_H
value|1
end_define
begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_DLFCN_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_define
DECL|macro|HAVE_FCNTL_H
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if you have the `floor' function. */
end_comment
begin_comment
comment|/* #undef HAVE_FLOOR */
end_comment
begin_comment
comment|/* Define to 1 if you have the `getopt' function. */
end_comment
begin_comment
comment|/* #undef HAVE_GETOPT */
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
comment|/* Define to 1 if the system has the type `int16'. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_AIX
end_ifdef
begin_define
DECL|macro|HAVE_INT16
define|#
directive|define
name|HAVE_INT16
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if the system has the type `int32'. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_AIX
end_ifdef
begin_define
DECL|macro|HAVE_INT32
define|#
directive|define
name|HAVE_INT32
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if the system has the type `int8'. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_AIX
end_ifdef
begin_define
DECL|macro|HAVE_INT8
define|#
directive|define
name|HAVE_INT8
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_INTTYPES_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<io.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_IO_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the `isascii' function. */
end_comment
begin_comment
comment|/* #undef HAVE_ISASCII */
end_comment
begin_comment
comment|/* Define to 1 if you have the `jbg_newlen' function. */
end_comment
begin_comment
comment|/* #undef HAVE_JBG_NEWLEN */
end_comment
begin_comment
comment|/* Define to 1 if you have the `lfind' function. */
end_comment
begin_comment
comment|/* #undef HAVE_LFIND */
end_comment
begin_comment
comment|/* Define to 1 if you have the `c' library (-lc). */
end_comment
begin_comment
comment|/* #undef HAVE_LIBC */
end_comment
begin_comment
comment|/* Define to 1 if you have the `m' library (-lm). */
end_comment
begin_comment
comment|/* #undef HAVE_LIBM */
end_comment
begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_LIMITS_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<malloc.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the `memmove' function. */
end_comment
begin_comment
comment|/* #undef HAVE_MEMMOVE */
end_comment
begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_MEMORY_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the `memset' function. */
end_comment
begin_comment
comment|/* #undef HAVE_MEMSET */
end_comment
begin_comment
comment|/* Define to 1 if you have the `mmap' function. */
end_comment
begin_comment
comment|/* #undef HAVE_MMAP */
end_comment
begin_comment
comment|/* Define to 1 if you have the `pow' function. */
end_comment
begin_comment
comment|/* #undef HAVE_POW */
end_comment
begin_comment
comment|/* Define if you have POSIX threads libraries and header files. */
end_comment
begin_comment
comment|/* #undef HAVE_PTHREAD */
end_comment
begin_comment
comment|/* Define to 1 if you have the<search.h> header file. */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_VXWORKS
argument_list|)
end_if
begin_define
DECL|macro|HAVE_SEARCH_H
define|#
directive|define
name|HAVE_SEARCH_H
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if you have the `setmode' function. */
end_comment
begin_comment
comment|/* #undef HAVE_SETMODE */
end_comment
begin_comment
comment|/* Define to 1 if you have the `sqrt' function. */
end_comment
begin_comment
comment|/* #undef HAVE_SQRT */
end_comment
begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_STDINT_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_STDLIB_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the `strcasecmp' function. */
end_comment
begin_comment
comment|/* #undef HAVE_STRCASECMP */
end_comment
begin_comment
comment|/* Define to 1 if you have the `strchr' function. */
end_comment
begin_comment
comment|/* #undef HAVE_STRCHR */
end_comment
begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_STRINGS_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment
begin_define
DECL|macro|HAVE_STRING_H
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define
begin_comment
comment|/* Define to 1 if you have the `strrchr' function. */
end_comment
begin_comment
comment|/* #undef HAVE_STRRCHR */
end_comment
begin_comment
comment|/* Define to 1 if you have the `strstr' function. */
end_comment
begin_comment
comment|/* #undef HAVE_STRSTR */
end_comment
begin_comment
comment|/* Define to 1 if you have the `strtol' function. */
end_comment
begin_comment
comment|/* #undef HAVE_STRTOL */
end_comment
begin_comment
comment|/* Define to 1 if you have the `strtoul' function. */
end_comment
begin_comment
comment|/* #undef HAVE_STRTOUL */
end_comment
begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_SYS_STAT_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_SYS_TIME_H */
end_comment
begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment
begin_define
DECL|macro|HAVE_SYS_TYPES_H
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define
begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_define
DECL|macro|HAVE_UNISTD_H
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if you have the<windows.h> header file. */
end_comment
begin_comment
comment|/* #undef HAVE_WINDOWS_H */
end_comment
begin_comment
comment|/* Native cpu byte order: 1 if big-endian (Motorola) or 0 if little-endian    (Intel) */
end_comment
begin_if
if|#
directive|if
operator|(
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
operator|)
end_if
begin_define
DECL|macro|HOST_BIGENDIAN
define|#
directive|define
name|HOST_BIGENDIAN
value|1
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|HOST_BIGENDIAN
define|#
directive|define
name|HOST_BIGENDIAN
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
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
comment|/* Support ISO JBIG compression (requires JBIG-KIT library) */
end_comment
begin_comment
comment|/* #undef JBIG_SUPPORT */
end_comment
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
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment
begin_comment
comment|/* #undef LT_OBJDIR */
end_comment
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
comment|/* Support Microsoft Document Imaging format */
end_comment
begin_define
DECL|macro|MDI_SUPPORT
define|#
directive|define
name|MDI_SUPPORT
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
comment|/* Define to 1 if your C compiler doesn't accept -c and -o together. */
end_comment
begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment
begin_comment
comment|/* Support Old JPEG compresson (read-only) */
end_comment
begin_comment
comment|/* #undef OJPEG_SUPPORT */
end_comment
begin_comment
comment|/* Name of package */
end_comment
begin_comment
comment|/* #undef PACKAGE */
end_comment
begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment
begin_comment
comment|/* #undef PACKAGE_BUGREPORT */
end_comment
begin_comment
comment|/* Define to the full name of this package. */
end_comment
begin_comment
comment|/* #undef PACKAGE_NAME */
end_comment
begin_comment
comment|/* Define to the full name and version of this package. */
end_comment
begin_comment
comment|/* #undef PACKAGE_STRING */
end_comment
begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment
begin_comment
comment|/* #undef PACKAGE_TARNAME */
end_comment
begin_comment
comment|/* Define to the home page for this package. */
end_comment
begin_comment
comment|/* #undef PACKAGE_URL */
end_comment
begin_comment
comment|/* Define to the version of this package. */
end_comment
begin_define
DECL|macro|PACKAGE_VERSION
define|#
directive|define
name|PACKAGE_VERSION
value|"3.9.2"
end_define
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
begin_define
DECL|macro|PIXARLOG_SUPPORT
define|#
directive|define
name|PIXARLOG_SUPPORT
value|1
end_define
begin_comment
comment|/* Define to necessary symbol if this constant uses a non-standard name on    your system. */
end_comment
begin_comment
comment|/* #undef PTHREAD_CREATE_JOINABLE */
end_comment
begin_comment
comment|/* The size of `int', as computed by sizeof. */
end_comment
begin_define
DECL|macro|SIZEOF_INT
define|#
directive|define
name|SIZEOF_INT
value|4
end_define
begin_comment
comment|/* The size of `long', as computed by sizeof. */
end_comment
begin_if
if|#
directive|if
operator|(
name|QT_POINTER_SIZE
operator|==
literal|8
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
end_if
begin_define
DECL|macro|SIZEOF_LONG
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|SIZEOF_LONG
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* The size of `signed long', as computed by sizeof. */
end_comment
begin_comment
comment|/* #undef SIZEOF_SIGNED_LONG */
end_comment
begin_comment
comment|/* The size of `signed long long', as computed by sizeof. */
end_comment
begin_comment
comment|/* #undef SIZEOF_SIGNED_LONG_LONG */
end_comment
begin_comment
comment|/* The size of `unsigned long', as computed by sizeof. */
end_comment
begin_comment
comment|/* #undef SIZEOF_UNSIGNED_LONG */
end_comment
begin_comment
comment|/* The size of `unsigned long long', as computed by sizeof. */
end_comment
begin_comment
comment|/* #undef SIZEOF_UNSIGNED_LONG_LONG */
end_comment
begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment
begin_comment
comment|/* #undef STDC_HEADERS */
end_comment
begin_comment
comment|/* Support strip chopping (whether or not to convert single-strip uncompressed    images to mutiple strips of specified size to reduce memory usage) */
end_comment
begin_define
DECL|macro|STRIPCHOP_DEFAULT
define|#
directive|define
name|STRIPCHOP_DEFAULT
value|TIFF_STRIPCHOP
end_define
begin_comment
comment|/* Default size of the strip in bytes (when strip chopping enabled) */
end_comment
begin_comment
comment|/* #undef STRIP_SIZE_DEFAULT */
end_comment
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
comment|/* Signed 64-bit type formatter */
end_comment
begin_comment
comment|/* #undef TIFF_INT64_FORMAT */
end_comment
begin_comment
comment|/* Signed 64-bit type */
end_comment
begin_define
DECL|macro|TIFF_INT64_T
define|#
directive|define
name|TIFF_INT64_T
value|qint64
end_define
begin_comment
comment|/* Unsigned 64-bit type formatter */
end_comment
begin_comment
comment|/* #undef TIFF_UINT64_FORMAT */
end_comment
begin_comment
comment|/* Unsigned 64-bit type */
end_comment
begin_define
DECL|macro|TIFF_UINT64_T
define|#
directive|define
name|TIFF_UINT64_T
value|quint64
end_define
begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment
begin_comment
comment|/* #undef TIME_WITH_SYS_TIME */
end_comment
begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment
begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment
begin_comment
comment|/* Version number of package */
end_comment
begin_comment
comment|/* #undef VERSION */
end_comment
begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment
begin_if
if|#
directive|if
operator|(
name|Q_BYTE_ORDER
operator|==
name|Q_BIG_ENDIAN
operator|)
end_if
begin_define
DECL|macro|WORDS_BIGENDIAN
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to 1 if the X Window System is missing or not being used. */
end_comment
begin_comment
comment|/* #undef X_DISPLAY_MISSING */
end_comment
begin_comment
comment|/* Support Deflate compression */
end_comment
begin_define
DECL|macro|ZIP_SUPPORT
define|#
directive|define
name|ZIP_SUPPORT
value|1
end_define
begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment
begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment
begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment
begin_comment
comment|/* #undef _LARGE_FILES */
end_comment
begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment
begin_comment
comment|/* #undef const */
end_comment
begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_SYMBIAN
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef
begin_undef
DECL|macro|inline
undef|#
directive|undef
name|inline
end_undef
begin_define
DECL|macro|inline
define|#
directive|define
name|inline
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment
begin_comment
comment|/* #undef off_t */
end_comment
begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment
begin_comment
comment|/* #undef size_t */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_define
DECL|macro|TIF_PLATFORM_CONSOLE
define|#
directive|define
name|TIF_PLATFORM_CONSOLE
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
