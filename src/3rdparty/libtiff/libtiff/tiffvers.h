begin_unit
begin_define
DECL|macro|TIFFLIB_VERSION_STR
define|#
directive|define
name|TIFFLIB_VERSION_STR
value|"LIBTIFF, Version 3.9.2\nCopyright (c) 1988-1996 Sam Leffler\nCopyright (c) 1991-1996 Silicon Graphics, Inc."
end_define
begin_comment
comment|/*  * This define can be used in code that requires  * compilation-related definitions specific to a  * version or versions of the library.  Runtime  * version checking should be done based on the  * string returned by TIFFGetVersion.  */
end_comment
begin_define
DECL|macro|TIFFLIB_VERSION
define|#
directive|define
name|TIFFLIB_VERSION
value|20091104
end_define
end_unit
