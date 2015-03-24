begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  fterrors.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType error code handling (specification).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2002, 2004, 2007, 2013 by                               */
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
comment|/* This special header file is used to define the handling of FT2        */
end_comment
begin_comment
comment|/* enumeration constants.  It can also be used to generate error message */
end_comment
begin_comment
comment|/* strings with a small macro trick explained below.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* I - Error Formats                                                     */
end_comment
begin_comment
comment|/* -----------------                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   The configuration macro FT_CONFIG_OPTION_USE_MODULE_ERRORS can be   */
end_comment
begin_comment
comment|/*   defined in ftoption.h in order to make the higher byte indicate     */
end_comment
begin_comment
comment|/*   the module where the error has happened (this is not compatible     */
end_comment
begin_comment
comment|/*   with standard builds of FreeType 2).  See the file `ftmoderr.h' for */
end_comment
begin_comment
comment|/*   more details.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* II - Error Message strings                                            */
end_comment
begin_comment
comment|/* --------------------------                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   The error definitions below are made through special macros that    */
end_comment
begin_comment
comment|/*   allow client applications to build a table of error message strings */
end_comment
begin_comment
comment|/*   if they need it.  The strings are not included in a normal build of */
end_comment
begin_comment
comment|/*   FreeType 2 to save space (most client applications do not use       */
end_comment
begin_comment
comment|/*   them).                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   To do so, you have to define the following macros before including  */
end_comment
begin_comment
comment|/*   this file:                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   FT_ERROR_START_LIST ::                                              */
end_comment
begin_comment
comment|/*     This macro is called before anything else to define the start of  */
end_comment
begin_comment
comment|/*     the error list.  It is followed by several FT_ERROR_DEF calls     */
end_comment
begin_comment
comment|/*     (see below).                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   FT_ERROR_DEF( e, v, s ) ::                                          */
end_comment
begin_comment
comment|/*     This macro is called to define one single error.                  */
end_comment
begin_comment
comment|/*     `e' is the error code identifier (e.g. FT_Err_Invalid_Argument).  */
end_comment
begin_comment
comment|/*     `v' is the error numerical value.                                 */
end_comment
begin_comment
comment|/*     `s' is the corresponding error string.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   FT_ERROR_END_LIST ::                                                */
end_comment
begin_comment
comment|/*     This macro ends the list.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Additionally, you have to undefine __FTERRORS_H__ before #including */
end_comment
begin_comment
comment|/*   this file.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   Here is a simple example:                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     {                                                                 */
end_comment
begin_comment
comment|/*       #undef __FTERRORS_H__                                           */
end_comment
begin_comment
comment|/*       #define FT_ERRORDEF( e, v, s )  { e, s },                       */
end_comment
begin_comment
comment|/*       #define FT_ERROR_START_LIST     {                               */
end_comment
begin_comment
comment|/*       #define FT_ERROR_END_LIST       { 0, 0 } };                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       const struct                                                    */
end_comment
begin_comment
comment|/*       {                                                               */
end_comment
begin_comment
comment|/*         int          err_code;                                        */
end_comment
begin_comment
comment|/*         const char*  err_msg;                                         */
end_comment
begin_comment
comment|/*       } ft_errors[] =                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*       #include FT_ERRORS_H                                            */
end_comment
begin_comment
comment|/*     }                                                                 */
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
name|__FTERRORS_H__
end_ifndef
begin_define
DECL|macro|__FTERRORS_H__
define|#
directive|define
name|__FTERRORS_H__
end_define
begin_comment
comment|/* include module base error codes */
end_comment
begin_include
include|#
directive|include
include|FT_MODULE_ERRORS_H
end_include
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
begin_comment
comment|/* FT_ERR_PREFIX is used as a prefix for error identifiers. */
end_comment
begin_comment
comment|/* By default, we use `FT_Err_'.                            */
end_comment
begin_comment
comment|/*                                                          */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_ERR_PREFIX
end_ifndef
begin_define
DECL|macro|FT_ERR_PREFIX
define|#
directive|define
name|FT_ERR_PREFIX
value|FT_Err_
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_ERR_BASE is used as the base for module-specific errors. */
end_comment
begin_comment
comment|/*                                                             */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_USE_MODULE_ERRORS
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_ERR_BASE
end_ifndef
begin_define
DECL|macro|FT_ERR_BASE
define|#
directive|define
name|FT_ERR_BASE
value|FT_Mod_Err_Base
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_undef
DECL|macro|FT_ERR_BASE
undef|#
directive|undef
name|FT_ERR_BASE
end_undef
begin_define
DECL|macro|FT_ERR_BASE
define|#
directive|define
name|FT_ERR_BASE
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_USE_MODULE_ERRORS */
end_comment
begin_comment
comment|/* If FT_ERRORDEF is not defined, we need to define a simple */
end_comment
begin_comment
comment|/* enumeration type.                                         */
end_comment
begin_comment
comment|/*                                                           */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_ERRORDEF
end_ifndef
begin_define
DECL|macro|FT_ERRORDEF
define|#
directive|define
name|FT_ERRORDEF
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|e = v,
end_define
begin_define
DECL|macro|FT_ERROR_START_LIST
define|#
directive|define
name|FT_ERROR_START_LIST
value|enum {
end_define
begin_define
DECL|macro|FT_ERROR_END_LIST
define|#
directive|define
name|FT_ERROR_END_LIST
value|FT_ERR_CAT( FT_ERR_PREFIX, Max ) };
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
comment|/* !FT_ERRORDEF */
comment|/* this macro is used to define an error */
DECL|macro|FT_ERRORDEF_
define|#
directive|define
name|FT_ERRORDEF_
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|FT_ERRORDEF( FT_ERR_CAT( FT_ERR_PREFIX, e ), v + FT_ERR_BASE, s )
comment|/* this is only used for<module>_Err_Ok, which must be 0! */
DECL|macro|FT_NOERRORDEF_
define|#
directive|define
name|FT_NOERRORDEF_
parameter_list|(
name|e
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
define|\
value|FT_ERRORDEF( FT_ERR_CAT( FT_ERR_PREFIX, e ), v, s )
ifdef|#
directive|ifdef
name|FT_ERROR_START_LIST
name|FT_ERROR_START_LIST
endif|#
directive|endif
comment|/* now include the error codes */
include|#
directive|include
include|FT_ERROR_DEFINITIONS_H
ifdef|#
directive|ifdef
name|FT_ERROR_END_LIST
name|FT_ERROR_END_LIST
endif|#
directive|endif
comment|/*******************************************************************/
comment|/*******************************************************************/
comment|/*****                                                         *****/
comment|/*****                      SIMPLE CLEANUP                     *****/
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
DECL|macro|FT_ERROR_START_LIST
undef|#
directive|undef
name|FT_ERROR_START_LIST
end_undef
begin_undef
DECL|macro|FT_ERROR_END_LIST
undef|#
directive|undef
name|FT_ERROR_END_LIST
end_undef
begin_undef
DECL|macro|FT_ERRORDEF
undef|#
directive|undef
name|FT_ERRORDEF
end_undef
begin_undef
DECL|macro|FT_ERRORDEF_
undef|#
directive|undef
name|FT_ERRORDEF_
end_undef
begin_undef
DECL|macro|FT_NOERRORDEF_
undef|#
directive|undef
name|FT_NOERRORDEF_
end_undef
begin_undef
DECL|macro|FT_NEED_EXTERN_C
undef|#
directive|undef
name|FT_NEED_EXTERN_C
end_undef
begin_undef
DECL|macro|FT_ERR_BASE
undef|#
directive|undef
name|FT_ERR_BASE
end_undef
begin_comment
comment|/* FT_ERR_PREFIX is needed internally */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT2_BUILD_LIBRARY
end_ifndef
begin_undef
DECL|macro|FT_ERR_PREFIX
undef|#
directive|undef
name|FT_ERR_PREFIX
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTERRORS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
