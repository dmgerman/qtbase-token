begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftttdrv.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for controlling the TrueType driver                     */
end_comment
begin_comment
comment|/*    (specification only).                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2013 by                                                      */
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
name|__FTTTDRV_H__
end_ifndef
begin_define
DECL|macro|__FTTTDRV_H__
define|#
directive|define
name|__FTTTDRV_H__
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
begin_expr_stmt
name|FT_BEGIN_HEADER
comment|/**************************************************************************    *    * @section:    *   tt_driver    *    * @title:    *   The TrueType driver    *    * @abstract:    *   Controlling the TrueType driver module.    *    * @description:    *   While FreeType's TrueType driver doesn't expose API functions by    *   itself, it is possible to control its behaviour with @FT_Property_Set    *   and @FT_Property_Get.  The following lists the available properties    *   together with the necessary macros and structures.    *    *   The TrueType driver's module name is `truetype'.    *    */
comment|/**************************************************************************    *    * @property:    *   interpreter-version    *    * @description:    *   Currently, two versions are available, representing the bytecode    *   interpreter with and without subpixel hinting support,    *   respectively.  The default is subpixel support if    *   TT_CONFIG_OPTION_SUBPIXEL_HINTING is defined, and no subpixel    *   support otherwise (since it isn't available then).    *    *   If subpixel hinting is on, many TrueType bytecode instructions    *   behave differently compared to B/W or grayscale rendering.  The    *   main idea is to render at a much increased horizontal resolution,    *   then sampling down the created output to subpixel precision.    *   However, many older fonts are not suited to this and must be    *   specially taken care of by applying (hardcoded) font-specific    *   tweaks.    *    *   Details on subpixel hinting and some of the necessary tweaks can be    *   found in Greg Hitchcock's whitepaper at    *   `http://www.microsoft.com/typography/cleartype/truetypecleartype.aspx'.    *    *   The following example code demonstrates how to activate subpixel    *   hinting (omitting the error handling).    *    *   {    *     FT_Library  library;    *     FT_Face     face;    *     FT_UInt     interpreter_version = TT_INTERPRETER_VERSION_38;    *    *    *     FT_Init_FreeType(&library );    *    *     FT_Property_Set( library, "truetype",    *                               "interpreter-version",    *&interpreter_version );    *   }    *    * @note:    *   This property can be used with @FT_Property_Get also.    *    */
comment|/**************************************************************************    *    * @enum:    *   TT_INTERPRETER_VERSION_XXX    *    * @description:    *   A list of constants used for the @interpreter-version property to    *   select the hinting engine for Truetype fonts.    *    *   The numeric value in the constant names represents the version    *   number as returned by the `GETINFO' bytecode instruction.    *    * @values:    *   TT_INTERPRETER_VERSION_35 ::    *     Version~35 corresponds to MS rasterizer v.1.7 as used e.g. in    *     Windows~98; only grayscale and B/W rasterizing is supported.    *    *   TT_INTERPRETER_VERSION_38 ::    *     Version~38 corresponds to MS rasterizer v.1.9; it is roughly    *     equivalent to the hinting provided by DirectWrite ClearType (as    *     can be found, for example, in the Internet Explorer~9 running on    *     Windows~7).    *    * @note:    *   This property controls the behaviour of the bytecode interpreter    *   and thus how outlines get hinted.  It does *not* control how glyph    *   get rasterized!  In particular, it does not control subpixel color    *   filtering.    *    *   If FreeType has not been compiled with configuration option    *   FT_CONFIG_OPTION_SUBPIXEL_HINTING, selecting version~38 causes an    *   `FT_Err_Unimplemented_Feature' error.    *    *   Depending on the graphics framework, Microsoft uses different    *   bytecode engines.  As a consequence, the version numbers returned by    *   a call to the `GETINFO[1]' bytecode instruction are more convoluted    *   than desired.    *    *   {    *      framework   Windows version   result of GETINFO[1]    *     ----------------------------------------------------    *       GDI         before XP         35    *       GDI         XP and later      37    *       GDI+ old    before Vista      37    *       GDI+ old    Vista, 7          38    *       GDI+        after 7           40    *       DWrite      before 8          39    *       DWrite      8 and later       40    *   }    *    *   Since FreeType doesn't provide all capabilities of DWrite ClearType,    *   using version~38 seems justified.    *    */
DECL|macro|TT_INTERPRETER_VERSION_35
define|#
directive|define
name|TT_INTERPRETER_VERSION_35
value|35
DECL|macro|TT_INTERPRETER_VERSION_38
define|#
directive|define
name|TT_INTERPRETER_VERSION_38
value|38
comment|/* */
name|FT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTTTDRV_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
