begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftoption.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    User-selectable configuration macros (specification only).           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2014 by                                                 */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTOPTION_H__
end_ifndef
begin_define
DECL|macro|__FTOPTION_H__
define|#
directive|define
name|__FTOPTION_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_expr_stmt
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*                 USER-SELECTABLE CONFIGURATION MACROS                  */
comment|/*                                                                       */
comment|/* This file contains the default configuration macro definitions for    */
comment|/* a standard build of the FreeType library.  There are three ways to    */
comment|/* use this file to build project-specific versions of the library:      */
comment|/*                                                                       */
comment|/*  - You can modify this file by hand, but this is not recommended in   */
comment|/*    cases where you would like to build several versions of the        */
comment|/*    library from a single source directory.                            */
comment|/*                                                                       */
comment|/*  - You can put a copy of this file in your build directory, more      */
comment|/*    precisely in `$BUILD/config/ftoption.h', where `$BUILD' is the     */
comment|/*    name of a directory that is included _before_ the FreeType include */
comment|/*    path during compilation.                                           */
comment|/*                                                                       */
comment|/*    The default FreeType Makefiles and Jamfiles use the build          */
comment|/*    directory `builds/<system>' by default, but you can easily change  */
comment|/*    that for your own projects.                                        */
comment|/*                                                                       */
comment|/*  - Copy the file<ft2build.h> to `$BUILD/ft2build.h' and modify it    */
comment|/*    slightly to pre-define the macro FT_CONFIG_OPTIONS_H used to       */
comment|/*    locate this file during the build.  For example,                   */
comment|/*                                                                       */
comment|/*      #define FT_CONFIG_OPTIONS_H<myftoptions.h>                     */
comment|/*      #include<config/ftheader.h>                                     */
comment|/*                                                                       */
comment|/*    will use `$BUILD/myftoptions.h' instead of this file for macro     */
comment|/*    definitions.                                                       */
comment|/*                                                                       */
comment|/*    Note also that you can similarly pre-define the macro              */
comment|/*    FT_CONFIG_MODULES_H used to locate the file listing of the modules */
comment|/*    that are statically linked to the library at compile time.  By     */
comment|/*    default, this file is<config/ftmodule.h>.                         */
comment|/*                                                                       */
comment|/* We highly recommend using the third method whenever possible.         */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/**** G E N E R A L   F R E E T Y P E   2   C O N F I G U R A T I O N ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Uncomment the line below if you want to activate sub-pixel rendering  */
comment|/* (a.k.a. LCD rendering, or ClearType) in this build of the library.    */
comment|/*                                                                       */
comment|/* Note that this feature is covered by several Microsoft patents        */
comment|/* and should not be activated in any default build of the library.      */
comment|/*                                                                       */
comment|/* This macro has no impact on the FreeType API, only on its             */
comment|/* _implementation_.  For example, using FT_RENDER_MODE_LCD when calling */
comment|/* FT_Render_Glyph still generates a bitmap that is 3 times wider than   */
comment|/* the original size in case this macro isn't defined; however, each     */
comment|/* triplet of subpixels has R=G=B.                                       */
comment|/*                                                                       */
comment|/* This is done to allow FreeType clients to run unmodified, forcing     */
comment|/* them to display normal gray-level anti-aliased glyphs.                */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_SUBPIXEL_RENDERING */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Many compilers provide a non-ANSI 64-bit data type that can be used   */
comment|/* by FreeType to speed up some computations.  However, this will create */
comment|/* some problems when compiling the library in strict ANSI mode.         */
comment|/*                                                                       */
comment|/* For this reason, the use of 64-bit integers is normally disabled when */
comment|/* the __STDC__ macro is defined.  You can however disable this by       */
comment|/* defining the macro FT_CONFIG_OPTION_FORCE_INT64 here.                 */
comment|/*                                                                       */
comment|/* For most compilers, this will only create compilation warnings when   */
comment|/* building the library.                                                 */
comment|/*                                                                       */
comment|/* ObNote: The compiler-specific 64-bit integers are detected in the     */
comment|/*         file `ftconfig.h' either statically or through the            */
comment|/*         `configure' script on supported platforms.                    */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_FORCE_INT64
undef|#
directive|undef
name|FT_CONFIG_OPTION_FORCE_INT64
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* If this macro is defined, do not try to use an assembler version of   */
comment|/* performance-critical functions (e.g. FT_MulFix).  You should only do  */
comment|/* that to verify that the assembler function works properly, or to      */
comment|/* execute benchmark tests of the various implementations.               */
comment|/* #define FT_CONFIG_OPTION_NO_ASSEMBLER */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* If this macro is defined, try to use an inlined assembler version of  */
comment|/* the `FT_MulFix' function, which is a `hotspot' when loading and       */
comment|/* hinting glyphs, and which should be executed as fast as possible.     */
comment|/*                                                                       */
comment|/* Note that if your compiler or CPU is not supported, this will default */
comment|/* to the standard and portable implementation found in `ftcalc.c'.      */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_INLINE_MULFIX
define|#
directive|define
name|FT_CONFIG_OPTION_INLINE_MULFIX
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* LZW-compressed file support.                                          */
comment|/*                                                                       */
comment|/*   FreeType now handles font files that have been compressed with the  */
comment|/*   `compress' program.  This is mostly used to parse many of the PCF   */
comment|/*   files that come with various X11 distributions.  The implementation */
comment|/*   uses NetBSD's `zopen' to partially uncompress the file on the fly   */
comment|/*   (see src/lzw/ftgzip.c).                                             */
comment|/*                                                                       */
comment|/*   Define this macro if you want to enable this `feature'.             */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_USE_LZW
define|#
directive|define
name|FT_CONFIG_OPTION_USE_LZW
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Gzip-compressed file support.                                         */
comment|/*                                                                       */
comment|/*   FreeType now handles font files that have been compressed with the  */
comment|/*   `gzip' program.  This is mostly used to parse many of the PCF files */
comment|/*   that come with XFree86.  The implementation uses `zlib' to          */
comment|/*   partially uncompress the file on the fly (see src/gzip/ftgzip.c).   */
comment|/*                                                                       */
comment|/*   Define this macro if you want to enable this `feature'.  See also   */
comment|/*   the macro FT_CONFIG_OPTION_SYSTEM_ZLIB below.                       */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_USE_ZLIB
define|#
directive|define
name|FT_CONFIG_OPTION_USE_ZLIB
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* ZLib library selection                                                */
comment|/*                                                                       */
comment|/*   This macro is only used when FT_CONFIG_OPTION_USE_ZLIB is defined.  */
comment|/*   It allows FreeType's `ftgzip' component to link to the system's     */
comment|/*   installation of the ZLib library.  This is useful on systems like   */
comment|/*   Unix or VMS where it generally is already available.                */
comment|/*                                                                       */
comment|/*   If you let it undefined, the component will use its own copy        */
comment|/*   of the zlib sources instead.  These have been modified to be        */
comment|/*   included directly within the component and *not* export external    */
comment|/*   function names.  This allows you to link any program with FreeType  */
comment|/*   _and_ ZLib without linking conflicts.                               */
comment|/*                                                                       */
comment|/*   Do not #undef this macro here since the build system might define   */
comment|/*   it for certain configurations only.                                 */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_SYSTEM_ZLIB */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Bzip2-compressed file support.                                        */
comment|/*                                                                       */
comment|/*   FreeType now handles font files that have been compressed with the  */
comment|/*   `bzip2' program.  This is mostly used to parse many of the PCF      */
comment|/*   files that come with XFree86.  The implementation uses `libbz2' to  */
comment|/*   partially uncompress the file on the fly (see src/bzip2/ftbzip2.c). */
comment|/*   Contrary to gzip, bzip2 currently is not included and need to use   */
comment|/*   the system available bzip2 implementation.                          */
comment|/*                                                                       */
comment|/*   Define this macro if you want to enable this `feature'.             */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_USE_BZIP2 */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define to disable the use of file stream functions and types, FILE,   */
comment|/* fopen() etc.  Enables the use of smaller system libraries on embedded */
comment|/* systems that have multiple system libraries, some with or without     */
comment|/* file stream support, in the cases where file stream support is not    */
comment|/* necessary such as memory loading of font files.                       */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_DISABLE_STREAM_SUPPORT */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* PNG bitmap support.                                                   */
comment|/*                                                                       */
comment|/*   FreeType now handles loading color bitmap glyphs in the PNG format. */
comment|/*   This requires help from the external libpng library.  Uncompressed  */
comment|/*   color bitmaps do not need any external libraries and will be        */
comment|/*   supported regardless of this configuration.                         */
comment|/*                                                                       */
comment|/*   Define this macro if you want to enable this `feature'.             */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_USE_PNG */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* HarfBuzz support.                                                     */
comment|/*                                                                       */
comment|/*   FreeType uses the HarfBuzz library to improve auto-hinting of       */
comment|/*   OpenType fonts.  If available, many glyphs not directly addressable */
comment|/*   by a font's character map will be hinted also.                      */
comment|/*                                                                       */
comment|/*   Define this macro if you want to enable this `feature'.             */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_USE_HARFBUZZ */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* DLL export compilation                                                */
comment|/*                                                                       */
comment|/*   When compiling FreeType as a DLL, some systems/compilers need a     */
comment|/*   special keyword in front OR after the return type of function       */
comment|/*   declarations.                                                       */
comment|/*                                                                       */
comment|/*   Two macros are used within the FreeType source code to define       */
comment|/*   exported library functions: FT_EXPORT and FT_EXPORT_DEF.            */
comment|/*                                                                       */
comment|/*     FT_EXPORT( return_type )                                          */
comment|/*                                                                       */
comment|/*       is used in a function declaration, as in                        */
comment|/*                                                                       */
comment|/*         FT_EXPORT( FT_Error )                                         */
comment|/*         FT_Init_FreeType( FT_Library*  alibrary );                    */
comment|/*                                                                       */
comment|/*                                                                       */
comment|/*     FT_EXPORT_DEF( return_type )                                      */
comment|/*                                                                       */
comment|/*       is used in a function definition, as in                         */
comment|/*                                                                       */
comment|/*         FT_EXPORT_DEF( FT_Error )                                     */
comment|/*         FT_Init_FreeType( FT_Library*  alibrary )                     */
comment|/*         {                                                             */
comment|/*           ... some code ...                                           */
comment|/*           return FT_Err_Ok;                                           */
comment|/*         }                                                             */
comment|/*                                                                       */
comment|/*   You can provide your own implementation of FT_EXPORT and            */
comment|/*   FT_EXPORT_DEF here if you want.  If you leave them undefined, they  */
comment|/*   will be later automatically defined as `extern return_type' to      */
comment|/*   allow normal compilation.                                           */
comment|/*                                                                       */
comment|/*   Do not #undef these macros here since the build system might define */
comment|/*   them for certain configurations only.                               */
comment|/*                                                                       */
comment|/* #define FT_EXPORT(x)      extern x */
comment|/* #define FT_EXPORT_DEF(x)  x */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Glyph Postscript Names handling                                       */
comment|/*                                                                       */
comment|/*   By default, FreeType 2 is compiled with the `psnames' module.  This */
comment|/*   module is in charge of converting a glyph name string into a        */
comment|/*   Unicode value, or return a Macintosh standard glyph name for the    */
comment|/*   use with the TrueType `post' table.                                 */
comment|/*                                                                       */
comment|/*   Undefine this macro if you do not want `psnames' compiled in your   */
comment|/*   build of FreeType.  This has the following effects:                 */
comment|/*                                                                       */
comment|/*   - The TrueType driver will provide its own set of glyph names,      */
comment|/*     if you build it to support postscript names in the TrueType       */
comment|/*     `post' table.                                                     */
comment|/*                                                                       */
comment|/*   - The Type 1 driver will not be able to synthesize a Unicode        */
comment|/*     charmap out of the glyphs found in the fonts.                     */
comment|/*                                                                       */
comment|/*   You would normally undefine this configuration macro when building  */
comment|/*   a version of FreeType that doesn't contain a Type 1 or CFF driver.  */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_POSTSCRIPT_NAMES
define|#
directive|define
name|FT_CONFIG_OPTION_POSTSCRIPT_NAMES
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Postscript Names to Unicode Values support                            */
comment|/*                                                                       */
comment|/*   By default, FreeType 2 is built with the `PSNames' module compiled  */
comment|/*   in.  Among other things, the module is used to convert a glyph name */
comment|/*   into a Unicode value.  This is especially useful in order to        */
comment|/*   synthesize on the fly a Unicode charmap from the CFF/Type 1 driver  */
comment|/*   through a big table named the `Adobe Glyph List' (AGL).             */
comment|/*                                                                       */
comment|/*   Undefine this macro if you do not want the Adobe Glyph List         */
comment|/*   compiled in your `PSNames' module.  The Type 1 driver will not be   */
comment|/*   able to synthesize a Unicode charmap out of the glyphs found in the */
comment|/*   fonts.                                                              */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_ADOBE_GLYPH_LIST
define|#
directive|define
name|FT_CONFIG_OPTION_ADOBE_GLYPH_LIST
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Support for Mac fonts                                                 */
comment|/*                                                                       */
comment|/*   Define this macro if you want support for outline fonts in Mac      */
comment|/*   format (mac dfont, mac resource, macbinary containing a mac         */
comment|/*   resource) on non-Mac platforms.                                     */
comment|/*                                                                       */
comment|/*   Note that the `FOND' resource isn't checked.                        */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_MAC_FONTS
define|#
directive|define
name|FT_CONFIG_OPTION_MAC_FONTS
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Guessing methods to access embedded resource forks                    */
comment|/*                                                                       */
comment|/*   Enable extra Mac fonts support on non-Mac platforms (e.g.           */
comment|/*   GNU/Linux).                                                         */
comment|/*                                                                       */
comment|/*   Resource forks which include fonts data are stored sometimes in     */
comment|/*   locations which users or developers don't expected.  In some cases, */
comment|/*   resource forks start with some offset from the head of a file.  In  */
comment|/*   other cases, the actual resource fork is stored in file different   */
comment|/*   from what the user specifies.  If this option is activated,         */
comment|/*   FreeType tries to guess whether such offsets or different file      */
comment|/*   names must be used.                                                 */
comment|/*                                                                       */
comment|/*   Note that normal, direct access of resource forks is controlled via */
comment|/*   the FT_CONFIG_OPTION_MAC_FONTS option.                              */
comment|/*                                                                       */
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_MAC_FONTS
DECL|macro|FT_CONFIG_OPTION_GUESSING_EMBEDDED_RFORK
define|#
directive|define
name|FT_CONFIG_OPTION_GUESSING_EMBEDDED_RFORK
endif|#
directive|endif
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Allow the use of FT_Incremental_Interface to load typefaces that      */
comment|/* contain no glyph data, but supply it via a callback function.         */
comment|/* This is required by clients supporting document formats which         */
comment|/* supply font data incrementally as the document is parsed, such        */
comment|/* as the Ghostscript interpreter for the PostScript language.           */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_INCREMENTAL
define|#
directive|define
name|FT_CONFIG_OPTION_INCREMENTAL
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* The size in bytes of the render pool used by the scan-line converter  */
comment|/* to do all of its work.                                                */
comment|/*                                                                       */
comment|/* This must be greater than 4KByte if you use FreeType to rasterize     */
comment|/* glyphs; otherwise, you may set it to zero to avoid unnecessary        */
comment|/* allocation of the render pool.                                        */
comment|/*                                                                       */
DECL|macro|FT_RENDER_POOL_SIZE
define|#
directive|define
name|FT_RENDER_POOL_SIZE
value|16384L
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* FT_MAX_MODULES                                                        */
comment|/*                                                                       */
comment|/*   The maximum number of modules that can be registered in a single    */
comment|/*   FreeType library object.  32 is the default.                        */
comment|/*                                                                       */
DECL|macro|FT_MAX_MODULES
define|#
directive|define
name|FT_MAX_MODULES
value|32
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Debug level                                                           */
comment|/*                                                                       */
comment|/*   FreeType can be compiled in debug or trace mode.  In debug mode,    */
comment|/*   errors are reported through the `ftdebug' component.  In trace      */
comment|/*   mode, additional messages are sent to the standard output during    */
comment|/*   execution.                                                          */
comment|/*                                                                       */
comment|/*   Define FT_DEBUG_LEVEL_ERROR to build the library in debug mode.     */
comment|/*   Define FT_DEBUG_LEVEL_TRACE to build it in trace mode.              */
comment|/*                                                                       */
comment|/*   Don't define any of these macros to compile in `release' mode!      */
comment|/*                                                                       */
comment|/*   Do not #undef these macros here since the build system might define */
comment|/*   them for certain configurations only.                               */
comment|/*                                                                       */
comment|/* #define FT_DEBUG_LEVEL_ERROR */
comment|/* #define FT_DEBUG_LEVEL_TRACE */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Autofitter debugging                                                  */
comment|/*                                                                       */
comment|/*   If FT_DEBUG_AUTOFIT is defined, FreeType provides some means to     */
comment|/*   control the autofitter behaviour for debugging purposes with global */
comment|/*   boolean variables (consequently, you should *never* enable this     */
comment|/*   while compiling in `release' mode):                                 */
comment|/*                                                                       */
comment|/*     _af_debug_disable_horz_hints                                      */
comment|/*     _af_debug_disable_vert_hints                                      */
comment|/*     _af_debug_disable_blue_hints                                      */
comment|/*                                                                       */
comment|/*   Additionally, the following functions provide dumps of various      */
comment|/*   internal autofit structures to stdout (using `printf'):             */
comment|/*                                                                       */
comment|/*     af_glyph_hints_dump_points                                        */
comment|/*     af_glyph_hints_dump_segments                                      */
comment|/*     af_glyph_hints_dump_edges                                         */
comment|/*                                                                       */
comment|/*   As an argument, they use another global variable:                   */
comment|/*                                                                       */
comment|/*     _af_debug_hints                                                   */
comment|/*                                                                       */
comment|/*   Please have a look at the `ftgrid' demo program to see how those    */
comment|/*   variables and macros should be used.                                */
comment|/*                                                                       */
comment|/*   Do not #undef these macros here since the build system might define */
comment|/*   them for certain configurations only.                               */
comment|/*                                                                       */
comment|/* #define FT_DEBUG_AUTOFIT */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Memory Debugging                                                      */
comment|/*                                                                       */
comment|/*   FreeType now comes with an integrated memory debugger that is       */
comment|/*   capable of detecting simple errors like memory leaks or double      */
comment|/*   deletes.  To compile it within your build of the library, you       */
comment|/*   should define FT_DEBUG_MEMORY here.                                 */
comment|/*                                                                       */
comment|/*   Note that the memory debugger is only activated at runtime when     */
comment|/*   when the _environment_ variable `FT2_DEBUG_MEMORY' is defined also! */
comment|/*                                                                       */
comment|/*   Do not #undef this macro here since the build system might define   */
comment|/*   it for certain configurations only.                                 */
comment|/*                                                                       */
comment|/* #define FT_DEBUG_MEMORY */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Module errors                                                         */
comment|/*                                                                       */
comment|/*   If this macro is set (which is _not_ the default), the higher byte  */
comment|/*   of an error code gives the module in which the error has occurred,  */
comment|/*   while the lower byte is the real error code.                        */
comment|/*                                                                       */
comment|/*   Setting this macro makes sense for debugging purposes only, since   */
comment|/*   it would break source compatibility of certain programs that use    */
comment|/*   FreeType 2.                                                         */
comment|/*                                                                       */
comment|/*   More details can be found in the files ftmoderr.h and fterrors.h.   */
comment|/*                                                                       */
DECL|macro|FT_CONFIG_OPTION_USE_MODULE_ERRORS
undef|#
directive|undef
name|FT_CONFIG_OPTION_USE_MODULE_ERRORS
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Position Independent Code                                             */
comment|/*                                                                       */
comment|/*   If this macro is set (which is _not_ the default), FreeType2 will   */
comment|/*   avoid creating constants that require address fixups.  Instead the  */
comment|/*   constants will be moved into a struct and additional intialization  */
comment|/*   code will be used.                                                  */
comment|/*                                                                       */
comment|/*   Setting this macro is needed for systems that prohibit address      */
comment|/*   fixups, such as BREW.                                               */
comment|/*                                                                       */
comment|/* #define FT_CONFIG_OPTION_PIC */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/****        S F N T   D R I V E R    C O N F I G U R A T I O N       ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_EMBEDDED_BITMAPS if you want to support       */
comment|/* embedded bitmaps in all formats using the SFNT module (namely         */
comment|/* TrueType& OpenType).                                                 */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
define|#
directive|define
name|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_POSTSCRIPT_NAMES if you want to be able to    */
comment|/* load and enumerate the glyph Postscript names in a TrueType or        */
comment|/* OpenType file.                                                        */
comment|/*                                                                       */
comment|/* Note that when you do not compile the `PSNames' module by undefining  */
comment|/* the above FT_CONFIG_OPTION_POSTSCRIPT_NAMES, the `sfnt' module will   */
comment|/* contain additional code used to read the PS Names table from a font.  */
comment|/*                                                                       */
comment|/* (By default, the module uses `PSNames' to extract glyph names.)       */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
define|#
directive|define
name|TT_CONFIG_OPTION_POSTSCRIPT_NAMES
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_SFNT_NAMES if your applications need to       */
comment|/* access the internal name table in a SFNT-based format like TrueType   */
comment|/* or OpenType.  The name table contains various strings used to         */
comment|/* describe the font, like family name, copyright, version, etc.  It     */
comment|/* does not contain any glyph name though.                               */
comment|/*                                                                       */
comment|/* Accessing SFNT names is done through the functions declared in        */
comment|/* `ftsnames.h'.                                                         */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_SFNT_NAMES
define|#
directive|define
name|TT_CONFIG_OPTION_SFNT_NAMES
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* TrueType CMap support                                                 */
comment|/*                                                                       */
comment|/*   Here you can fine-tune which TrueType CMap table format shall be    */
comment|/*   supported.                                                          */
DECL|macro|TT_CONFIG_CMAP_FORMAT_0
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_0
DECL|macro|TT_CONFIG_CMAP_FORMAT_2
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_2
DECL|macro|TT_CONFIG_CMAP_FORMAT_4
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_4
DECL|macro|TT_CONFIG_CMAP_FORMAT_6
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_6
DECL|macro|TT_CONFIG_CMAP_FORMAT_8
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_8
DECL|macro|TT_CONFIG_CMAP_FORMAT_10
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_10
DECL|macro|TT_CONFIG_CMAP_FORMAT_12
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_12
DECL|macro|TT_CONFIG_CMAP_FORMAT_13
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_13
DECL|macro|TT_CONFIG_CMAP_FORMAT_14
define|#
directive|define
name|TT_CONFIG_CMAP_FORMAT_14
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/****    T R U E T Y P E   D R I V E R    C O N F I G U R A T I O N   ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_BYTECODE_INTERPRETER if you want to compile   */
comment|/* a bytecode interpreter in the TrueType driver.                        */
comment|/*                                                                       */
comment|/* By undefining this, you will only compile the code necessary to load  */
comment|/* TrueType glyphs without hinting.                                      */
comment|/*                                                                       */
comment|/*   Do not #undef this macro here, since the build system might         */
comment|/*   define it for certain configurations only.                          */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_BYTECODE_INTERPRETER
define|#
directive|define
name|TT_CONFIG_OPTION_BYTECODE_INTERPRETER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_SUBPIXEL_HINTING if you want to compile       */
comment|/* EXPERIMENTAL subpixel hinting support into the TrueType driver.  This */
comment|/* replaces the native TrueType hinting mechanism when anything but      */
comment|/* FT_RENDER_MODE_MONO is requested.                                     */
comment|/*                                                                       */
comment|/* Enabling this causes the TrueType driver to ignore instructions under */
comment|/* certain conditions.  This is done in accordance with the guide here,  */
comment|/* with some minor differences:                                          */
comment|/*                                                                       */
comment|/*  http://www.microsoft.com/typography/cleartype/truetypecleartype.aspx */
comment|/*                                                                       */
comment|/* By undefining this, you only compile the code necessary to hint       */
comment|/* TrueType glyphs with native TT hinting.                               */
comment|/*                                                                       */
comment|/*   This option requires TT_CONFIG_OPTION_BYTECODE_INTERPRETER to be    */
comment|/*   defined.                                                            */
comment|/*                                                                       */
comment|/* #define TT_CONFIG_OPTION_SUBPIXEL_HINTING */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* If you define TT_CONFIG_OPTION_UNPATENTED_HINTING, a special version  */
comment|/* of the TrueType bytecode interpreter is used that doesn't implement   */
comment|/* any of the patented opcodes and algorithms.  The patents related to   */
comment|/* TrueType hinting have expired worldwide since May 2010; this option   */
comment|/* is now deprecated.                                                    */
comment|/*                                                                       */
comment|/* Note that the TT_CONFIG_OPTION_UNPATENTED_HINTING macro is *ignored*  */
comment|/* if you define TT_CONFIG_OPTION_BYTECODE_INTERPRETER; in other words,  */
comment|/* either define TT_CONFIG_OPTION_BYTECODE_INTERPRETER or                */
comment|/* TT_CONFIG_OPTION_UNPATENTED_HINTING but not both at the same time.    */
comment|/*                                                                       */
comment|/* This macro is only useful for a small number of font files (mostly    */
comment|/* for Asian scripts) that require bytecode interpretation to properly   */
comment|/* load glyphs.  For all other fonts, this produces unpleasant results,  */
comment|/* thus the unpatented interpreter is never used to load glyphs from     */
comment|/* TrueType fonts unless one of the following two options is used.       */
comment|/*                                                                       */
comment|/*   - The unpatented interpreter is explicitly activated by the user    */
comment|/*     through the FT_PARAM_TAG_UNPATENTED_HINTING parameter tag         */
comment|/*     when opening the FT_Face.                                         */
comment|/*                                                                       */
comment|/*   - FreeType detects that the FT_Face corresponds to one of the       */
comment|/*     `trick' fonts (e.g., `Mingliu') it knows about.  The font engine  */
comment|/*     contains a hard-coded list of font names and other matching       */
comment|/*     parameters (see function `tt_face_init' in file                   */
comment|/*     `src/truetype/ttobjs.c').                                         */
comment|/*                                                                       */
comment|/* Here a sample code snippet for using FT_PARAM_TAG_UNPATENTED_HINTING. */
comment|/*                                                                       */
comment|/*   {                                                                   */
comment|/*     FT_Parameter  parameter;                                          */
comment|/*     FT_Open_Args  open_args;                                          */
comment|/*                                                                       */
comment|/*                                                                       */
comment|/*     parameter.tag = FT_PARAM_TAG_UNPATENTED_HINTING;                  */
comment|/*                                                                       */
comment|/*     open_args.flags      = FT_OPEN_PATHNAME | FT_OPEN_PARAMS;         */
comment|/*     open_args.pathname   = my_font_pathname;                          */
comment|/*     open_args.num_params = 1;                                         */
comment|/*     open_args.params     =&parameter;                                */
comment|/*                                                                       */
comment|/*     error = FT_Open_Face( library,&open_args, index,&face );        */
comment|/*     ...                                                               */
comment|/*   }                                                                   */
comment|/*                                                                       */
comment|/* #define TT_CONFIG_OPTION_UNPATENTED_HINTING */
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_INTERPRETER_SWITCH to compile the TrueType    */
comment|/* bytecode interpreter with a huge switch statement, rather than a call */
comment|/* table.  This results in smaller and faster code for a number of       */
comment|/* architectures.                                                        */
comment|/*                                                                       */
comment|/* Note however that on some compiler/processor combinations, undefining */
comment|/* this macro will generate faster, though larger, code.                 */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_INTERPRETER_SWITCH
define|#
directive|define
name|TT_CONFIG_OPTION_INTERPRETER_SWITCH
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_COMPONENT_OFFSET_SCALED to compile the        */
comment|/* TrueType glyph loader to use Apple's definition of how to handle      */
comment|/* component offsets in composite glyphs.                                */
comment|/*                                                                       */
comment|/* Apple and MS disagree on the default behavior of component offsets    */
comment|/* in composites.  Apple says that they should be scaled by the scaling  */
comment|/* factors in the transformation matrix (roughly, it's more complex)     */
comment|/* while MS says they should not.  OpenType defines two bits in the      */
comment|/* composite flags array which can be used to disambiguate, but old      */
comment|/* fonts will not have them.                                             */
comment|/*                                                                       */
comment|/*   http://www.microsoft.com/typography/otspec/glyf.htm                 */
comment|/*   http://fonts.apple.com/TTRefMan/RM06/Chap6glyf.html                 */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_COMPONENT_OFFSET_SCALED
undef|#
directive|undef
name|TT_CONFIG_OPTION_COMPONENT_OFFSET_SCALED
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_GX_VAR_SUPPORT if you want to include         */
comment|/* support for Apple's distortable font technology (fvar, gvar, cvar,    */
comment|/* and avar tables).  This has many similarities to Type 1 Multiple      */
comment|/* Masters support.                                                      */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_GX_VAR_SUPPORT
define|#
directive|define
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define TT_CONFIG_OPTION_BDF if you want to include support for        */
comment|/* an embedded `BDF ' table within SFNT-based bitmap formats.            */
comment|/*                                                                       */
DECL|macro|TT_CONFIG_OPTION_BDF
define|#
directive|define
name|TT_CONFIG_OPTION_BDF
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/****      T Y P E 1   D R I V E R    C O N F I G U R A T I O N       ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* T1_MAX_DICT_DEPTH is the maximum depth of nest dictionaries and       */
comment|/* arrays in the Type 1 stream (see t1load.c).  A minimum of 4 is        */
comment|/* required.                                                             */
comment|/*                                                                       */
DECL|macro|T1_MAX_DICT_DEPTH
define|#
directive|define
name|T1_MAX_DICT_DEPTH
value|5
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* T1_MAX_SUBRS_CALLS details the maximum number of nested sub-routine   */
comment|/* calls during glyph loading.                                           */
comment|/*                                                                       */
DECL|macro|T1_MAX_SUBRS_CALLS
define|#
directive|define
name|T1_MAX_SUBRS_CALLS
value|16
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* T1_MAX_CHARSTRING_OPERANDS is the charstring stack's capacity.  A     */
comment|/* minimum of 16 is required.                                            */
comment|/*                                                                       */
comment|/* The Chinese font MingTiEG-Medium (CNS 11643 character set) needs 256. */
comment|/*                                                                       */
DECL|macro|T1_MAX_CHARSTRINGS_OPERANDS
define|#
directive|define
name|T1_MAX_CHARSTRINGS_OPERANDS
value|256
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define this configuration macro if you want to prevent the            */
comment|/* compilation of `t1afm', which is in charge of reading Type 1 AFM      */
comment|/* files into an existing face.  Note that if set, the T1 driver will be */
comment|/* unable to produce kerning distances.                                  */
comment|/*                                                                       */
DECL|macro|T1_CONFIG_OPTION_NO_AFM
undef|#
directive|undef
name|T1_CONFIG_OPTION_NO_AFM
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Define this configuration macro if you want to prevent the            */
comment|/* compilation of the Multiple Masters font support in the Type 1        */
comment|/* driver.                                                               */
comment|/*                                                                       */
DECL|macro|T1_CONFIG_OPTION_NO_MM_SUPPORT
undef|#
directive|undef
name|T1_CONFIG_OPTION_NO_MM_SUPPORT
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/****         C F F   D R I V E R    C O N F I G U R A T I O N        ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Using CFF_CONFIG_OPTION_DARKENING_PARAMETER_{X,Y}{1,2,3,4} it is      */
comment|/* possible to set up the default values of the four control points that */
comment|/* define the stem darkening behaviour of the (new) CFF engine.  For     */
comment|/* more details please read the documentation of the                     */
comment|/* `darkening-parameters' property of the cff driver module (file        */
comment|/* `ftcffdrv.h'), which allows the control at run-time.                  */
comment|/*                                                                       */
comment|/* Do *not* undefine these macros!                                       */
comment|/*                                                                       */
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X1
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X1
value|500
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y1
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y1
value|400
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X2
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X2
value|1000
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y2
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y2
value|275
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X3
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X3
value|1667
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y3
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y3
value|275
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X4
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X4
value|2333
DECL|macro|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y4
define|#
directive|define
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y4
value|0
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* CFF_CONFIG_OPTION_OLD_ENGINE controls whether the pre-Adobe CFF       */
comment|/* engine gets compiled into FreeType.  If defined, it is possible to    */
comment|/* switch between the two engines using the `hinting-engine' property of */
comment|/* the cff driver module.                                                */
comment|/*                                                                       */
comment|/* #define CFF_CONFIG_OPTION_OLD_ENGINE */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/****    A U T O F I T   M O D U L E    C O N F I G U R A T I O N     ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Compile autofit module with CJK (Chinese, Japanese, Korean) script    */
comment|/* support.                                                              */
comment|/*                                                                       */
DECL|macro|AF_CONFIG_OPTION_CJK
define|#
directive|define
name|AF_CONFIG_OPTION_CJK
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Compile autofit module with Indic script support.                     */
comment|/*                                                                       */
DECL|macro|AF_CONFIG_OPTION_INDIC
define|#
directive|define
name|AF_CONFIG_OPTION_INDIC
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Compile autofit module with warp hinting.  The idea of the warping    */
comment|/* code is to slightly scale and shift a glyph within a single dimension */
comment|/* so that as much of its segments are aligned (more or less) on the     */
comment|/* grid.  To find out the optimal scaling and shifting value, various    */
comment|/* parameter combinations are tried and scored.                          */
comment|/*                                                                       */
comment|/* This experimental option is only active if the render mode is         */
comment|/* FT_RENDER_MODE_LIGHT.                                                 */
comment|/*                                                                       */
comment|/* #define AF_CONFIG_OPTION_USE_WARPER */
comment|/* */
comment|/*    * This macro is obsolete.  Support has been removed in FreeType    * version 2.5.    */
comment|/* #define FT_CONFIG_OPTION_OLD_INTERNALS */
comment|/*    * This macro is defined if either unpatented or native TrueType    * hinting is requested by the definitions above.    */
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BYTECODE_INTERPRETER
DECL|macro|TT_USE_BYTECODE_INTERPRETER
define|#
directive|define
name|TT_USE_BYTECODE_INTERPRETER
DECL|macro|TT_CONFIG_OPTION_UNPATENTED_HINTING
undef|#
directive|undef
name|TT_CONFIG_OPTION_UNPATENTED_HINTING
elif|#
directive|elif
name|defined
name|TT_CONFIG_OPTION_UNPATENTED_HINTING
define|#
directive|define
name|TT_USE_BYTECODE_INTERPRETER
endif|#
directive|endif
comment|/*    * Check CFF darkening parameters.  The checks are the same as in function    * `cff_property_set' in file `cffdrivr.c'.    */
if|#
directive|if
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X1
operator|<
literal|0
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X2
operator|<
literal|0
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X3
operator|<
literal|0
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X4
operator|<
literal|0
operator|||
expr|\                                                       \
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y1
operator|<
literal|0
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y2
operator|<
literal|0
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y3
operator|<
literal|0
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y4
operator|<
literal|0
operator|||
expr|\                                                       \
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X1
operator|>
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X2
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X2
operator|>
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X3
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X3
operator|>
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_X4
operator|||
expr|\                                                       \
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y1
operator|>
literal|500
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y2
operator|>
literal|500
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y3
operator|>
literal|500
operator|||
expr|\
name|CFF_CONFIG_OPTION_DARKENING_PARAMETER_Y4
operator|>
literal|500
error|#
directive|error
literal|"Invalid CFF darkening parameters!"
endif|#
directive|endif
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTOPTION_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
