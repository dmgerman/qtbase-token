begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  internal.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Internal header files (specification only).                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2004, 2013 by                                           */
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
comment|/* This file is automatically included by `ft2build.h'.                  */
end_comment
begin_comment
comment|/* Do not include it manually!                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|FT_INTERNAL_OBJECTS_H
define|#
directive|define
name|FT_INTERNAL_OBJECTS_H
value|<internal/ftobjs.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_PIC_H
define|#
directive|define
name|FT_INTERNAL_PIC_H
value|<internal/ftpic.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_STREAM_H
define|#
directive|define
name|FT_INTERNAL_STREAM_H
value|<internal/ftstream.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_MEMORY_H
define|#
directive|define
name|FT_INTERNAL_MEMORY_H
value|<internal/ftmemory.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_DEBUG_H
define|#
directive|define
name|FT_INTERNAL_DEBUG_H
value|<internal/ftdebug.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_CALC_H
define|#
directive|define
name|FT_INTERNAL_CALC_H
value|<internal/ftcalc.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_DRIVER_H
define|#
directive|define
name|FT_INTERNAL_DRIVER_H
value|<internal/ftdriver.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_TRACE_H
define|#
directive|define
name|FT_INTERNAL_TRACE_H
value|<internal/fttrace.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_GLYPH_LOADER_H
define|#
directive|define
name|FT_INTERNAL_GLYPH_LOADER_H
value|<internal/ftgloadr.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_SFNT_H
define|#
directive|define
name|FT_INTERNAL_SFNT_H
value|<internal/sfnt.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_SERVICE_H
define|#
directive|define
name|FT_INTERNAL_SERVICE_H
value|<internal/ftserv.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_RFORK_H
define|#
directive|define
name|FT_INTERNAL_RFORK_H
value|<internal/ftrfork.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_VALIDATE_H
define|#
directive|define
name|FT_INTERNAL_VALIDATE_H
value|<internal/ftvalid.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_TRUETYPE_TYPES_H
define|#
directive|define
name|FT_INTERNAL_TRUETYPE_TYPES_H
value|<internal/tttypes.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_TYPE1_TYPES_H
define|#
directive|define
name|FT_INTERNAL_TYPE1_TYPES_H
value|<internal/t1types.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_POSTSCRIPT_AUX_H
define|#
directive|define
name|FT_INTERNAL_POSTSCRIPT_AUX_H
value|<internal/psaux.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_POSTSCRIPT_HINTS_H
define|#
directive|define
name|FT_INTERNAL_POSTSCRIPT_HINTS_H
value|<internal/pshints.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_POSTSCRIPT_GLOBALS_H
define|#
directive|define
name|FT_INTERNAL_POSTSCRIPT_GLOBALS_H
value|<internal/psglobal.h>
end_define
begin_define
DECL|macro|FT_INTERNAL_AUTOHINT_H
define|#
directive|define
name|FT_INTERNAL_AUTOHINT_H
value|<internal/autohint.h>
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if
begin_comment
comment|/* Visual C++ (and Intel C++) */
end_comment
begin_comment
comment|/* We disable the warning `conditional expression is constant' here */
end_comment
begin_comment
comment|/* in order to compile cleanly with the maximum level of warnings.  */
end_comment
begin_comment
comment|/* In particular, the warning complains about stuff like `while(0)' */
end_comment
begin_comment
comment|/* which is very useful in macro definitions.  There is no benefit  */
end_comment
begin_comment
comment|/* in having it enabled.                                            */
end_comment
begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4127
name|)
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _MSC_VER */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
