begin_unit
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
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment
begin_define
DECL|macro|HAVE_FCNTL_H
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define
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
comment|/* Define to 1 if you have the `jbg_newlen' function. */
end_comment
begin_define
DECL|macro|HAVE_JBG_NEWLEN
define|#
directive|define
name|HAVE_JBG_NEWLEN
value|1
end_define
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
comment|/* Define to 1 if you have the<io.h> header file. */
end_comment
begin_define
DECL|macro|HAVE_IO_H
define|#
directive|define
name|HAVE_IO_H
value|1
end_define
begin_comment
comment|/* Define to 1 if you have the<search.h> header file. */
end_comment
begin_define
DECL|macro|HAVE_SEARCH_H
define|#
directive|define
name|HAVE_SEARCH_H
value|1
end_define
begin_comment
comment|/* Define to 1 if you have the `setmode' function. */
end_comment
begin_define
DECL|macro|HAVE_SETMODE
define|#
directive|define
name|HAVE_SETMODE
value|1
end_define
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
comment|/* Set the native cpu bit order */
end_comment
begin_define
DECL|macro|HOST_FILLORDER
define|#
directive|define
name|HOST_FILLORDER
value|FILLORDER_LSB2MSB
end_define
begin_comment
comment|/* Define to 1 if your processor stores words with the most significant byte    first (like Motorola and SPARC, unlike Intel and VAX). */
end_comment
begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment
begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|inline
end_ifndef
begin_define
DECL|macro|inline
define|#
directive|define
name|inline
value|__inline
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|lfind
define|#
directive|define
name|lfind
value|_lfind
end_define
end_unit
