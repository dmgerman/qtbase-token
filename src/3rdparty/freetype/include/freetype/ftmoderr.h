begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmoderr.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType module error offsets (specification).                       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2001, 2002, 2003, 2004, 2005 by                              */
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
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This file is used to define the FreeType module error offsets.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The lower byte gives the error code, the higher byte gives the        */
end_comment
begin_comment
comment|/* module.  The base module has error offset 0.  For example, the error  */
end_comment
begin_comment
comment|/* `FT_Err_Invalid_File_Format' has value 0x003, the error               */
end_comment
begin_comment
comment|/* `TT_Err_Invalid_File_Format' has value 0x1103, the error              */
end_comment
begin_comment
comment|/* `T1_Err_Invalid_File_Format' has value 0x1203, etc.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Undefine the macro FT_CONFIG_OPTION_USE_MODULE_ERRORS in ftoption.h   */
end_comment
begin_comment
comment|/* to make the higher byte always zero (disabling the module error       */
end_comment
begin_comment
comment|/* mechanism).                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* It can also be used to create a module error message table easily     */
end_comment
begin_comment
comment|/* with something like                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   {                                                                   */
end_comment
begin_comment
comment|/*     #undef __FTMODERR_H__                                             */
end_comment
begin_comment
comment|/*     #define FT_MODERRDEF( e, v, s )  { FT_Mod_Err_ ## e, s },         */
end_comment
begin_comment
comment|/*     #define FT_MODERR_START_LIST     {                                */
end_comment
begin_comment
comment|/*     #define FT_MODERR_END_LIST       { 0, 0 } };                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     const struct                                                      */
end_comment
begin_comment
comment|/*     {                                                                 */
end_comment
begin_comment
comment|/*       int          mod_err_offset;                                    */
end_comment
begin_comment
comment|/*       const char*  mod_err_msg                                        */
end_comment
begin_comment
comment|/*     } ft_mod_errors[] =                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     #include FT_MODULE_ERRORS_H                                       */
end_comment
begin_comment
comment|/*   }                                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* To use such a table, all errors must be ANDed with 0xFF00 to remove   */
end_comment
begin_comment
comment|/* the error code.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTMODERR_H__
end_ifndef
begin_define
DECL|macro|__FTMODERR_H__
define|#
directive|define
name|__FTMODERR_H__
end_define
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*****                                                         *****/
end_comment
begin_comment
comment|/*****                       SETUP MACROS                      *****/
end_comment
begin_comment
comment|/*****                                                         *****/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_undef
DECL|macro|FT_NEED_EXTERN_C
undef|#
directive|undef
name|FT_NEED_EXTERN_C
end_undef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_MODERRDEF
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_MODULE_ERRORS
end_ifdef
begin_define
DECL|macro|FT_MODERRDEF
define|#
directive|define
name|FT_MODERRDEF
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|FT_Mod_Err_ ## e = v,
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_MODERRDEF
define|#
directive|define
name|FT_MODERRDEF
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|FT_Mod_Err_ ## e = 0,
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|FT_MODERR_START_LIST
define|#
directive|define
name|FT_MODERR_START_LIST
value|enum {
end_define
begin_define
DECL|macro|FT_MODERR_END_LIST
define|#
directive|define
name|FT_MODERR_END_LIST
value|FT_Mod_Err_Max };
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_NEED_EXTERN_C
define|#
directive|define
name|FT_NEED_EXTERN_C
end_define
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
endif|#
directive|endif
comment|/* !FT_MODERRDEF */
comment|/*******************************************************************/
comment|/*******************************************************************/
comment|/*****                                                         *****/
comment|/*****               LIST MODULE ERROR BASES                   *****/
comment|/*****                                                         *****/
comment|/*******************************************************************/
comment|/*******************************************************************/
ifdef|#
directive|ifdef
name|FT_MODERR_START_LIST
name|FT_MODERR_START_LIST
endif|#
directive|endif
name|FT_MODERRDEF
argument_list|(
name|Base
argument_list|,
literal|0x000
argument_list|,
literal|"base module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Autofit
argument_list|,
literal|0x100
argument_list|,
literal|"autofitter module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|BDF
argument_list|,
literal|0x200
argument_list|,
literal|"BDF module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Cache
argument_list|,
literal|0x300
argument_list|,
literal|"cache module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|CFF
argument_list|,
literal|0x400
argument_list|,
literal|"CFF module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|CID
argument_list|,
literal|0x500
argument_list|,
literal|"CID module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Gzip
argument_list|,
literal|0x600
argument_list|,
literal|"Gzip module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|LZW
argument_list|,
literal|0x700
argument_list|,
literal|"LZW module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|OTvalid
argument_list|,
literal|0x800
argument_list|,
literal|"OpenType validation module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PCF
argument_list|,
literal|0x900
argument_list|,
literal|"PCF module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PFR
argument_list|,
literal|0xA00
argument_list|,
literal|"PFR module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PSaux
argument_list|,
literal|0xB00
argument_list|,
literal|"PS auxiliary module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PShinter
argument_list|,
literal|0xC00
argument_list|,
literal|"PS hinter module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|PSnames
argument_list|,
literal|0xD00
argument_list|,
literal|"PS names module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Raster
argument_list|,
literal|0xE00
argument_list|,
literal|"raster module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|SFNT
argument_list|,
literal|0xF00
argument_list|,
literal|"SFNT module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Smooth
argument_list|,
literal|0x1000
argument_list|,
literal|"smooth raster module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|TrueType
argument_list|,
literal|0x1100
argument_list|,
literal|"TrueType module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Type1
argument_list|,
literal|0x1200
argument_list|,
literal|"Type 1 module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Type42
argument_list|,
literal|0x1300
argument_list|,
literal|"Type 42 module"
argument_list|)
name|FT_MODERRDEF
argument_list|(
name|Winfonts
argument_list|,
literal|0x1400
argument_list|,
literal|"Windows FON/FNT module"
argument_list|)
ifdef|#
directive|ifdef
name|FT_MODERR_END_LIST
name|FT_MODERR_END_LIST
endif|#
directive|endif
comment|/*******************************************************************/
comment|/*******************************************************************/
comment|/*****                                                         *****/
comment|/*****                      CLEANUP                            *****/
comment|/*****                                                         *****/
comment|/*******************************************************************/
comment|/*******************************************************************/
ifdef|#
directive|ifdef
name|FT_NEED_EXTERN_C
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_undef
DECL|macro|FT_MODERR_START_LIST
undef|#
directive|undef
name|FT_MODERR_START_LIST
end_undef
begin_undef
DECL|macro|FT_MODERR_END_LIST
undef|#
directive|undef
name|FT_MODERR_END_LIST
end_undef
begin_undef
DECL|macro|FT_MODERRDEF
undef|#
directive|undef
name|FT_MODERRDEF
end_undef
begin_undef
DECL|macro|FT_NEED_EXTERN_C
undef|#
directive|undef
name|FT_NEED_EXTERN_C
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTMODERR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
