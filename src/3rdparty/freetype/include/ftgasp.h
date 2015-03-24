begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgasp.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Access of TrueType's `gasp' table (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007, 2008, 2011 by                                          */
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
name|_FT_GASP_H_
end_ifndef
begin_define
DECL|macro|_FT_GASP_H_
define|#
directive|define
name|_FT_GASP_H_
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/***************************************************************************    *    * @section:    *   gasp_table    *    * @title:    *   Gasp Table    *    * @abstract:    *   Retrieving TrueType `gasp' table entries.    *    * @description:    *   The function @FT_Get_Gasp can be used to query a TrueType or OpenType    *   font for specific entries in its `gasp' table, if any.  This is    *   mainly useful when implementing native TrueType hinting with the    *   bytecode interpreter to duplicate the Windows text rendering results.    */
end_comment
begin_comment
comment|/*************************************************************************    *    * @enum:    *   FT_GASP_XXX    *    * @description:    *   A list of values and/or bit-flags returned by the @FT_Get_Gasp    *   function.    *    * @values:    *   FT_GASP_NO_TABLE ::    *     This special value means that there is no GASP table in this face.    *     It is up to the client to decide what to do.    *    *   FT_GASP_DO_GRIDFIT ::    *     Grid-fitting and hinting should be performed at the specified ppem.    *     This *really* means TrueType bytecode interpretation.  If this bit    *     is not set, no hinting gets applied.    *    *   FT_GASP_DO_GRAY ::    *     Anti-aliased rendering should be performed at the specified ppem.    *     If not set, do monochrome rendering.    *    *   FT_GASP_SYMMETRIC_SMOOTHING ::    *     If set, smoothing along multiple axes must be used with ClearType.    *    *   FT_GASP_SYMMETRIC_GRIDFIT ::    *     Grid-fitting must be used with ClearType's symmetric smoothing.    *    * @note:    *   The bit-flags `FT_GASP_DO_GRIDFIT' and `FT_GASP_DO_GRAY' are to be    *   used for standard font rasterization only.  Independently of that,    *   `FT_GASP_SYMMETRIC_SMOOTHING' and `FT_GASP_SYMMETRIC_GRIDFIT' are to    *   be used if ClearType is enabled (and `FT_GASP_DO_GRIDFIT' and    *   `FT_GASP_DO_GRAY' are consequently ignored).    *    *   `ClearType' is Microsoft's implementation of LCD rendering, partly    *   protected by patents.    *    * @since:    *   2.3.0    */
end_comment
begin_define
DECL|macro|FT_GASP_NO_TABLE
define|#
directive|define
name|FT_GASP_NO_TABLE
value|-1
end_define
begin_define
DECL|macro|FT_GASP_DO_GRIDFIT
define|#
directive|define
name|FT_GASP_DO_GRIDFIT
value|0x01
end_define
begin_define
DECL|macro|FT_GASP_DO_GRAY
define|#
directive|define
name|FT_GASP_DO_GRAY
value|0x02
end_define
begin_define
DECL|macro|FT_GASP_SYMMETRIC_SMOOTHING
define|#
directive|define
name|FT_GASP_SYMMETRIC_SMOOTHING
value|0x08
end_define
begin_define
DECL|macro|FT_GASP_SYMMETRIC_GRIDFIT
define|#
directive|define
name|FT_GASP_SYMMETRIC_GRIDFIT
value|0x10
end_define
begin_comment
comment|/*************************************************************************    *    * @func:    *   FT_Get_Gasp    *    * @description:    *   Read the `gasp' table from a TrueType or OpenType font file and    *   return the entry corresponding to a given character pixel size.    *    * @input:    *   face :: The source face handle.    *   ppem :: The vertical character pixel size.    *    * @return:    *   Bit flags (see @FT_GASP_XXX), or @FT_GASP_NO_TABLE if there is no    *   `gasp' table in the face.    *    * @since:    *   2.3.0    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|FT_Get_Gasp
argument_list|(
argument|FT_Face  face
argument_list|,
argument|FT_UInt  ppem
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _FT_GASP_H_ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
