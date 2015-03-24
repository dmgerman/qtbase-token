begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftheader.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Build macros of the FreeType 2 library.                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2008, 2010, 2012, 2013 by                               */
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
name|__FT_HEADER_H__
end_ifndef
begin_define
DECL|macro|__FT_HEADER_H__
define|#
directive|define
name|__FT_HEADER_H__
end_define
begin_comment
comment|/*@***********************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_BEGIN_HEADER                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This macro is used in association with @FT_END_HEADER in header    */
end_comment
begin_comment
comment|/*    files to ensure that the declarations within are properly          */
end_comment
begin_comment
comment|/*    encapsulated in an `extern "C" { .. }' block when included from a  */
end_comment
begin_comment
comment|/*    C++ compiler.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_BEGIN_HEADER
define|#
directive|define
name|FT_BEGIN_HEADER
value|extern "C" {
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_BEGIN_HEADER
define|#
directive|define
name|FT_BEGIN_HEADER
end_define
begin_comment
DECL|macro|FT_BEGIN_HEADER
comment|/* nothing */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*@***********************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_END_HEADER                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This macro is used in association with @FT_BEGIN_HEADER in header  */
end_comment
begin_comment
comment|/*    files to ensure that the declarations within are properly          */
end_comment
begin_comment
comment|/*    encapsulated in an `extern "C" { .. }' block when included from a  */
end_comment
begin_comment
comment|/*    C++ compiler.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_END_HEADER
define|#
directive|define
name|FT_END_HEADER
value|}
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_END_HEADER
define|#
directive|define
name|FT_END_HEADER
end_define
begin_comment
DECL|macro|FT_END_HEADER
comment|/* nothing */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Aliases for the FreeType 2 public and configuration files.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    header_file_macros                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Header File Macros                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Macro definitions used to #include specific header files.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The following macros are defined to the name of specific           */
end_comment
begin_comment
comment|/*    FreeType~2 header files.  They can be used directly in #include    */
end_comment
begin_comment
comment|/*    statements as in:                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      #include FT_FREETYPE_H                                           */
end_comment
begin_comment
comment|/*      #include FT_MULTIPLE_MASTERS_H                                   */
end_comment
begin_comment
comment|/*      #include FT_GLYPH_H                                              */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    There are several reasons why we are now using macros to name      */
end_comment
begin_comment
comment|/*    public header files.  The first one is that such macros are not    */
end_comment
begin_comment
comment|/*    limited to the infamous 8.3~naming rule required by DOS (and       */
end_comment
begin_comment
comment|/*    `FT_MULTIPLE_MASTERS_H' is a lot more meaningful than `ftmm.h').   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The second reason is that it allows for more flexibility in the    */
end_comment
begin_comment
comment|/*    way FreeType~2 is installed on a given system.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* configuration files */
end_comment
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CONFIG_CONFIG_H    *    * @description:    *   A macro used in #include statements to name the file containing    *   FreeType~2 configuration data.    *    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_CONFIG_H
end_ifndef
begin_define
DECL|macro|FT_CONFIG_CONFIG_H
define|#
directive|define
name|FT_CONFIG_CONFIG_H
value|<config/ftconfig.h>
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CONFIG_STANDARD_LIBRARY_H    *    * @description:    *   A macro used in #include statements to name the file containing    *   FreeType~2 interface to the standard C library functions.    *    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_STANDARD_LIBRARY_H
end_ifndef
begin_define
DECL|macro|FT_CONFIG_STANDARD_LIBRARY_H
define|#
directive|define
name|FT_CONFIG_STANDARD_LIBRARY_H
value|<config/ftstdlib.h>
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CONFIG_OPTIONS_H    *    * @description:    *   A macro used in #include statements to name the file containing    *   FreeType~2 project-specific configuration options.    *    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTIONS_H
end_ifndef
begin_define
DECL|macro|FT_CONFIG_OPTIONS_H
define|#
directive|define
name|FT_CONFIG_OPTIONS_H
value|<config/ftoption.h>
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CONFIG_MODULES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   list of FreeType~2 modules that are statically linked to new library    *   instances in @FT_Init_FreeType.    *    */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_MODULES_H
end_ifndef
begin_define
DECL|macro|FT_CONFIG_MODULES_H
define|#
directive|define
name|FT_CONFIG_MODULES_H
value|<config/ftmodule.h>
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* */
end_comment
begin_comment
comment|/* public headers */
end_comment
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_FREETYPE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   base FreeType~2 API.    *    */
end_comment
begin_define
DECL|macro|FT_FREETYPE_H
define|#
directive|define
name|FT_FREETYPE_H
value|<freetype.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_ERRORS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   list of FreeType~2 error codes (and messages).    *    *   It is included by @FT_FREETYPE_H.    *    */
end_comment
begin_define
DECL|macro|FT_ERRORS_H
define|#
directive|define
name|FT_ERRORS_H
value|<fterrors.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_MODULE_ERRORS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   list of FreeType~2 module error offsets (and messages).    *    */
end_comment
begin_define
DECL|macro|FT_MODULE_ERRORS_H
define|#
directive|define
name|FT_MODULE_ERRORS_H
value|<ftmoderr.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_SYSTEM_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 interface to low-level operations (i.e., memory management    *   and stream i/o).    *    *   It is included by @FT_FREETYPE_H.    *    */
end_comment
begin_define
DECL|macro|FT_SYSTEM_H
define|#
directive|define
name|FT_SYSTEM_H
value|<ftsystem.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_IMAGE_H    *    * @description:    *   A macro used in #include statements to name the file containing type    *   definitions related to glyph images (i.e., bitmaps, outlines,    *   scan-converter parameters).    *    *   It is included by @FT_FREETYPE_H.    *    */
end_comment
begin_define
DECL|macro|FT_IMAGE_H
define|#
directive|define
name|FT_IMAGE_H
value|<ftimage.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TYPES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   basic data types defined by FreeType~2.    *    *   It is included by @FT_FREETYPE_H.    *    */
end_comment
begin_define
DECL|macro|FT_TYPES_H
define|#
directive|define
name|FT_TYPES_H
value|<fttypes.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_LIST_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   list management API of FreeType~2.    *    *   (Most applications will never need to include this file.)    *    */
end_comment
begin_define
DECL|macro|FT_LIST_H
define|#
directive|define
name|FT_LIST_H
value|<ftlist.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_OUTLINE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   scalable outline management API of FreeType~2.    *    */
end_comment
begin_define
DECL|macro|FT_OUTLINE_H
define|#
directive|define
name|FT_OUTLINE_H
value|<ftoutln.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_SIZES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   API which manages multiple @FT_Size objects per face.    *    */
end_comment
begin_define
DECL|macro|FT_SIZES_H
define|#
directive|define
name|FT_SIZES_H
value|<ftsizes.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_MODULE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   module management API of FreeType~2.    *    */
end_comment
begin_define
DECL|macro|FT_MODULE_H
define|#
directive|define
name|FT_MODULE_H
value|<ftmodapi.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_RENDER_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   renderer module management API of FreeType~2.    *    */
end_comment
begin_define
DECL|macro|FT_RENDER_H
define|#
directive|define
name|FT_RENDER_H
value|<ftrender.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_AUTOHINTER_H    *    * @description:    *   A macro used in #include statements to name the file containing    *   structures and macros related to the auto-hinting module.    *    */
end_comment
begin_define
DECL|macro|FT_AUTOHINTER_H
define|#
directive|define
name|FT_AUTOHINTER_H
value|<ftautoh.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CFF_DRIVER_H    *    * @description:    *   A macro used in #include statements to name the file containing    *   structures and macros related to the CFF driver module.    *    */
end_comment
begin_define
DECL|macro|FT_CFF_DRIVER_H
define|#
directive|define
name|FT_CFF_DRIVER_H
value|<ftcffdrv.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TRUETYPE_DRIVER_H    *    * @description:    *   A macro used in #include statements to name the file containing    *   structures and macros related to the TrueType driver module.    *    */
end_comment
begin_define
DECL|macro|FT_TRUETYPE_DRIVER_H
define|#
directive|define
name|FT_TRUETYPE_DRIVER_H
value|<ftttdrv.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TYPE1_TABLES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   types and API specific to the Type~1 format.    *    */
end_comment
begin_define
DECL|macro|FT_TYPE1_TABLES_H
define|#
directive|define
name|FT_TYPE1_TABLES_H
value|<t1tables.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TRUETYPE_IDS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   enumeration values which identify name strings, languages, encodings,    *   etc.  This file really contains a _large_ set of constant macro    *   definitions, taken from the TrueType and OpenType specifications.    *    */
end_comment
begin_define
DECL|macro|FT_TRUETYPE_IDS_H
define|#
directive|define
name|FT_TRUETYPE_IDS_H
value|<ttnameid.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TRUETYPE_TABLES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   types and API specific to the TrueType (as well as OpenType) format.    *    */
end_comment
begin_define
DECL|macro|FT_TRUETYPE_TABLES_H
define|#
directive|define
name|FT_TRUETYPE_TABLES_H
value|<tttables.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TRUETYPE_TAGS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of TrueType four-byte `tags' which identify blocks in    *   SFNT-based font formats (i.e., TrueType and OpenType).    *    */
end_comment
begin_define
DECL|macro|FT_TRUETYPE_TAGS_H
define|#
directive|define
name|FT_TRUETYPE_TAGS_H
value|<tttags.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_BDF_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of an API which accesses BDF-specific strings from a    *   face.    *    */
end_comment
begin_define
DECL|macro|FT_BDF_H
define|#
directive|define
name|FT_BDF_H
value|<ftbdf.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CID_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of an API which access CID font information from a    *   face.    *    */
end_comment
begin_define
DECL|macro|FT_CID_H
define|#
directive|define
name|FT_CID_H
value|<ftcid.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_GZIP_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of an API which supports gzip-compressed files.    *    */
end_comment
begin_define
DECL|macro|FT_GZIP_H
define|#
directive|define
name|FT_GZIP_H
value|<ftgzip.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_LZW_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of an API which supports LZW-compressed files.    *    */
end_comment
begin_define
DECL|macro|FT_LZW_H
define|#
directive|define
name|FT_LZW_H
value|<ftlzw.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_BZIP2_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of an API which supports bzip2-compressed files.    *    */
end_comment
begin_define
DECL|macro|FT_BZIP2_H
define|#
directive|define
name|FT_BZIP2_H
value|<ftbzip2.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_WINFONTS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   definitions of an API which supports Windows FNT files.    *    */
end_comment
begin_define
DECL|macro|FT_WINFONTS_H
define|#
directive|define
name|FT_WINFONTS_H
value|<ftwinfnt.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_GLYPH_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   API of the optional glyph management component.    *    */
end_comment
begin_define
DECL|macro|FT_GLYPH_H
define|#
directive|define
name|FT_GLYPH_H
value|<ftglyph.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_BITMAP_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   API of the optional bitmap conversion component.    *    */
end_comment
begin_define
DECL|macro|FT_BITMAP_H
define|#
directive|define
name|FT_BITMAP_H
value|<ftbitmap.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_BBOX_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   API of the optional exact bounding box computation routines.    *    */
end_comment
begin_define
DECL|macro|FT_BBOX_H
define|#
directive|define
name|FT_BBOX_H
value|<ftbbox.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CACHE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   API of the optional FreeType~2 cache sub-system.    *    */
end_comment
begin_define
DECL|macro|FT_CACHE_H
define|#
directive|define
name|FT_CACHE_H
value|<ftcache.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CACHE_IMAGE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   `glyph image' API of the FreeType~2 cache sub-system.    *    *   It is used to define a cache for @FT_Glyph elements.  You can also    *   use the API defined in @FT_CACHE_SMALL_BITMAPS_H if you only need to    *   store small glyph bitmaps, as it will use less memory.    *    *   This macro is deprecated.  Simply include @FT_CACHE_H to have all    *   glyph image-related cache declarations.    *    */
end_comment
begin_define
DECL|macro|FT_CACHE_IMAGE_H
define|#
directive|define
name|FT_CACHE_IMAGE_H
value|FT_CACHE_H
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CACHE_SMALL_BITMAPS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   `small bitmaps' API of the FreeType~2 cache sub-system.    *    *   It is used to define a cache for small glyph bitmaps in a relatively    *   memory-efficient way.  You can also use the API defined in    *   @FT_CACHE_IMAGE_H if you want to cache arbitrary glyph images,    *   including scalable outlines.    *    *   This macro is deprecated.  Simply include @FT_CACHE_H to have all    *   small bitmaps-related cache declarations.    *    */
end_comment
begin_define
DECL|macro|FT_CACHE_SMALL_BITMAPS_H
define|#
directive|define
name|FT_CACHE_SMALL_BITMAPS_H
value|FT_CACHE_H
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_CACHE_CHARMAP_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   `charmap' API of the FreeType~2 cache sub-system.    *    *   This macro is deprecated.  Simply include @FT_CACHE_H to have all    *   charmap-based cache declarations.    *    */
end_comment
begin_define
DECL|macro|FT_CACHE_CHARMAP_H
define|#
directive|define
name|FT_CACHE_CHARMAP_H
value|FT_CACHE_H
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_MAC_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   Macintosh-specific FreeType~2 API.  The latter is used to access    *   fonts embedded in resource forks.    *    *   This header file must be explicitly included by client applications    *   compiled on the Mac (note that the base API still works though).    *    */
end_comment
begin_define
DECL|macro|FT_MAC_H
define|#
directive|define
name|FT_MAC_H
value|<ftmac.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_MULTIPLE_MASTERS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   optional multiple-masters management API of FreeType~2.    *    */
end_comment
begin_define
DECL|macro|FT_MULTIPLE_MASTERS_H
define|#
directive|define
name|FT_MULTIPLE_MASTERS_H
value|<ftmm.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_SFNT_NAMES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   optional FreeType~2 API which accesses embedded `name' strings in    *   SFNT-based font formats (i.e., TrueType and OpenType).    *    */
end_comment
begin_define
DECL|macro|FT_SFNT_NAMES_H
define|#
directive|define
name|FT_SFNT_NAMES_H
value|<ftsnames.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_OPENTYPE_VALIDATE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   optional FreeType~2 API which validates OpenType tables (BASE, GDEF,    *   GPOS, GSUB, JSTF).    *    */
end_comment
begin_define
DECL|macro|FT_OPENTYPE_VALIDATE_H
define|#
directive|define
name|FT_OPENTYPE_VALIDATE_H
value|<ftotval.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_GX_VALIDATE_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   optional FreeType~2 API which validates TrueTypeGX/AAT tables (feat,    *   mort, morx, bsln, just, kern, opbd, trak, prop).    *    */
end_comment
begin_define
DECL|macro|FT_GX_VALIDATE_H
define|#
directive|define
name|FT_GX_VALIDATE_H
value|<ftgxval.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_PFR_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which accesses PFR-specific data.    *    */
end_comment
begin_define
DECL|macro|FT_PFR_H
define|#
directive|define
name|FT_PFR_H
value|<ftpfr.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_STROKER_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which provides functions to stroke outline paths.    */
end_comment
begin_define
DECL|macro|FT_STROKER_H
define|#
directive|define
name|FT_STROKER_H
value|<ftstroke.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_SYNTHESIS_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which performs artificial obliquing and emboldening.    */
end_comment
begin_define
DECL|macro|FT_SYNTHESIS_H
define|#
directive|define
name|FT_SYNTHESIS_H
value|<ftsynth.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_XFREE86_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which provides functions specific to the XFree86 and    *   X.Org X11 servers.    */
end_comment
begin_define
DECL|macro|FT_XFREE86_H
define|#
directive|define
name|FT_XFREE86_H
value|<ftxf86.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_TRIGONOMETRY_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which performs trigonometric computations (e.g.,    *   cosines and arc tangents).    */
end_comment
begin_define
DECL|macro|FT_TRIGONOMETRY_H
define|#
directive|define
name|FT_TRIGONOMETRY_H
value|<fttrigon.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_LCD_FILTER_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which performs color filtering for subpixel rendering.    */
end_comment
begin_define
DECL|macro|FT_LCD_FILTER_H
define|#
directive|define
name|FT_LCD_FILTER_H
value|<ftlcdfil.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_UNPATENTED_HINTING_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which performs color filtering for subpixel rendering.    */
end_comment
begin_define
DECL|macro|FT_UNPATENTED_HINTING_H
define|#
directive|define
name|FT_UNPATENTED_HINTING_H
value|<ttunpat.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_INCREMENTAL_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which performs color filtering for subpixel rendering.    */
end_comment
begin_define
DECL|macro|FT_INCREMENTAL_H
define|#
directive|define
name|FT_INCREMENTAL_H
value|<ftincrem.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_GASP_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which returns entries from the TrueType GASP table.    */
end_comment
begin_define
DECL|macro|FT_GASP_H
define|#
directive|define
name|FT_GASP_H
value|<ftgasp.h>
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_ADVANCES_H    *    * @description:    *   A macro used in #include statements to name the file containing the    *   FreeType~2 API which returns individual and ranged glyph advances.    */
end_comment
begin_define
DECL|macro|FT_ADVANCES_H
define|#
directive|define
name|FT_ADVANCES_H
value|<ftadvanc.h>
end_define
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|FT_ERROR_DEFINITIONS_H
define|#
directive|define
name|FT_ERROR_DEFINITIONS_H
value|<fterrdef.h>
end_define
begin_comment
comment|/* The internals of the cache sub-system are no longer exposed.  We */
end_comment
begin_comment
comment|/* default to FT_CACHE_H at the moment just in case, but we know of */
end_comment
begin_comment
comment|/* no rogue client that uses them.                                  */
end_comment
begin_comment
comment|/*                                                                  */
end_comment
begin_define
DECL|macro|FT_CACHE_MANAGER_H
define|#
directive|define
name|FT_CACHE_MANAGER_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_CACHE_INTERNAL_MRU_H
define|#
directive|define
name|FT_CACHE_INTERNAL_MRU_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_CACHE_INTERNAL_MANAGER_H
define|#
directive|define
name|FT_CACHE_INTERNAL_MANAGER_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_CACHE_INTERNAL_CACHE_H
define|#
directive|define
name|FT_CACHE_INTERNAL_CACHE_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_CACHE_INTERNAL_GLYPH_H
define|#
directive|define
name|FT_CACHE_INTERNAL_GLYPH_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_CACHE_INTERNAL_IMAGE_H
define|#
directive|define
name|FT_CACHE_INTERNAL_IMAGE_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_CACHE_INTERNAL_SBITS_H
define|#
directive|define
name|FT_CACHE_INTERNAL_SBITS_H
value|<ftcache.h>
end_define
begin_define
DECL|macro|FT_INCREMENTAL_H
define|#
directive|define
name|FT_INCREMENTAL_H
value|<ftincrem.h>
end_define
begin_define
DECL|macro|FT_TRUETYPE_UNPATENTED_H
define|#
directive|define
name|FT_TRUETYPE_UNPATENTED_H
value|<ttunpat.h>
end_define
begin_comment
comment|/*    * Include internal headers definitions from<internal/...>    * only when building the library.    */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT2_BUILD_LIBRARY
end_ifdef
begin_define
DECL|macro|FT_INTERNAL_INTERNAL_H
define|#
directive|define
name|FT_INTERNAL_INTERNAL_H
value|<internal/internal.h>
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_INTERNAL_H
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT2_BUILD_LIBRARY */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FT2_BUILD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
