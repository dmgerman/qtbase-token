begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftinit.c                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType initialization layer (body).                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2005, 2007 by                               */
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
comment|/*  The purpose of this file is to implement the following two           */
end_comment
begin_comment
comment|/*  functions:                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  FT_Add_Default_Modules():                                            */
end_comment
begin_comment
comment|/*     This function is used to add the set of default modules to a      */
end_comment
begin_comment
comment|/*     fresh new library object.  The set is taken from the header file  */
end_comment
begin_comment
comment|/*     `freetype/config/ftmodule.h'.  See the document `FreeType 2.0     */
end_comment
begin_comment
comment|/*     Build System' for more information.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  FT_Init_FreeType():                                                  */
end_comment
begin_comment
comment|/*     This function creates a system object for the current platform,   */
end_comment
begin_comment
comment|/*     builds a library out of it, then calls FT_Default_Drivers().      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*  Note that even if FT_Init_FreeType() uses the implementation of the  */
end_comment
begin_comment
comment|/*  system object defined at build time, client applications are still   */
end_comment
begin_comment
comment|/*  able to provide their own `ftsystem.c'.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_MODULE_H
end_include
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The macro FT_COMPONENT is used in trace mode.  It is an implicit      */
end_comment
begin_comment
comment|/* parameter of the FT_TRACE() and FT_ERROR() macros, used to print/log  */
end_comment
begin_comment
comment|/* messages during execution.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_undef
DECL|macro|FT_COMPONENT
undef|#
directive|undef
name|FT_COMPONENT
end_undef
begin_define
DECL|macro|FT_COMPONENT
define|#
directive|define
name|FT_COMPONENT
value|trace_init
end_define
begin_undef
DECL|macro|FT_USE_MODULE
undef|#
directive|undef
name|FT_USE_MODULE
end_undef
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_define
DECL|macro|FT_USE_MODULE
define|#
directive|define
name|FT_USE_MODULE
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|)
value|extern "C" const type  x;
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_USE_MODULE
define|#
directive|define
name|FT_USE_MODULE
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|)
value|extern const type  x;
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
include|FT_CONFIG_MODULES_H
end_include
begin_undef
DECL|macro|FT_USE_MODULE
undef|#
directive|undef
name|FT_USE_MODULE
end_undef
begin_define
DECL|macro|FT_USE_MODULE
define|#
directive|define
name|FT_USE_MODULE
parameter_list|(
name|type
parameter_list|,
name|x
parameter_list|)
value|(const FT_Module_Class*)&(x),
end_define
begin_decl_stmt
specifier|static
DECL|variable|ft_default_modules
specifier|const
name|FT_Module_Class
modifier|*
specifier|const
name|ft_default_modules
index|[]
init|=
block|{
include|#
directive|include
include|FT_CONFIG_MODULES_H
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* documentation is in ftmodapi.h */
end_comment
begin_macro
name|FT_EXPORT_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|FT_Add_Default_Modules
name|FT_Add_Default_Modules
argument_list|(
argument|FT_Library  library
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
specifier|const
name|FT_Module_Class
modifier|*
specifier|const
modifier|*
name|cur
decl_stmt|;
comment|/* test for valid `library' delayed to FT_Add_Module() */
name|cur
operator|=
name|ft_default_modules
expr_stmt|;
while|while
condition|(
operator|*
name|cur
condition|)
block|{
name|error
operator|=
name|FT_Add_Module
argument_list|(
name|library
argument_list|,
operator|*
name|cur
argument_list|)
expr_stmt|;
comment|/* notify errors, but don't stop */
if|if
condition|(
name|error
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"FT_Add_Default_Module: Cannot install `%s', error = 0x%x\n"
operator|,
operator|(
operator|*
name|cur
operator|)
operator|->
name|module_name
operator|,
name|error
operator|)
argument_list|)
expr_stmt|;
block|}
name|cur
operator|++
expr_stmt|;
block|}
block|}
end_block
begin_comment
comment|/* documentation is in freetype.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Init_FreeType
argument_list|(
argument|FT_Library  *alibrary
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Memory
name|memory
decl_stmt|;
comment|/* First of all, allocate a new system object -- this function is part */
comment|/* of the system-specific component, i.e. `ftsystem.c'.                */
name|memory
operator|=
name|FT_New_Memory
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|memory
condition|)
block|{
name|FT_ERROR
argument_list|(
operator|(
literal|"FT_Init_FreeType: cannot find memory manager\n"
operator|)
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Unimplemented_Feature
return|;
block|}
comment|/* build a library out of it, then fill it with the set of */
comment|/* default drivers.                                        */
name|error
operator|=
name|FT_New_Library
argument_list|(
name|memory
argument_list|,
name|alibrary
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|FT_Done_Memory
argument_list|(
name|memory
argument_list|)
expr_stmt|;
else|else
block|{
operator|(
operator|*
name|alibrary
operator|)
operator|->
name|version_major
operator|=
name|FREETYPE_MAJOR
expr_stmt|;
operator|(
operator|*
name|alibrary
operator|)
operator|->
name|version_minor
operator|=
name|FREETYPE_MINOR
expr_stmt|;
operator|(
operator|*
name|alibrary
operator|)
operator|->
name|version_patch
operator|=
name|FREETYPE_PATCH
expr_stmt|;
name|FT_Add_Default_Modules
argument_list|(
operator|*
name|alibrary
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* documentation is in freetype.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Done_FreeType
argument_list|(
argument|FT_Library  library
argument_list|)
end_macro
begin_block
block|{
if|if
condition|(
name|library
condition|)
block|{
name|FT_Memory
name|memory
init|=
name|library
operator|->
name|memory
decl_stmt|;
comment|/* Discard the library object */
name|FT_Done_Library
argument_list|(
name|library
argument_list|)
expr_stmt|;
comment|/* discard memory manager */
name|FT_Done_Memory
argument_list|(
name|memory
argument_list|)
expr_stmt|;
block|}
return|return
name|FT_Err_Ok
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
