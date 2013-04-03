begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afmodule.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter module implementation (body).                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005, 2006 by                                    */
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
begin_include
include|#
directive|include
file|"afmodule.h"
end_include
begin_include
include|#
directive|include
file|"afloader.h"
end_include
begin_include
include|#
directive|include
file|"afpic.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|AF_DEBUG
end_ifdef
begin_decl_stmt
DECL|variable|_af_debug
name|int
name|_af_debug
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_af_debug_disable_horz_hints
name|int
name|_af_debug_disable_horz_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_af_debug_disable_vert_hints
name|int
name|_af_debug_disable_vert_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_af_debug_disable_blue_hints
name|int
name|_af_debug_disable_blue_hints
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|_af_debug_hints
name|void
modifier|*
name|_af_debug_hints
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_typedef
DECL|struct|FT_AutofitterRec_
typedef|typedef
struct|struct
name|FT_AutofitterRec_
block|{
DECL|member|root
name|FT_ModuleRec
name|root
decl_stmt|;
DECL|member|loader
name|AF_LoaderRec
name|loader
index|[
literal|1
index|]
decl_stmt|;
block|}
DECL|typedef|FT_AutofitterRec
DECL|typedef|FT_Autofitter
name|FT_AutofitterRec
operator|,
typedef|*
name|FT_Autofitter
typedef|;
end_typedef
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_autofitter_init
argument_list|(
argument|FT_Autofitter  module
argument_list|)
end_macro
begin_block
block|{
return|return
name|af_loader_init
argument_list|(
name|module
operator|->
name|loader
argument_list|,
name|module
operator|->
name|root
operator|.
name|library
operator|->
name|memory
argument_list|)
return|;
block|}
end_block
begin_macro
name|FT_CALLBACK_DEF
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|function|af_autofitter_done
name|af_autofitter_done
argument_list|(
argument|FT_Autofitter  module
argument_list|)
end_macro
begin_block
block|{
name|af_loader_done
argument_list|(
name|module
operator|->
name|loader
argument_list|)
expr_stmt|;
block|}
end_block
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_autofitter_load_glyph
argument_list|(
argument|FT_Autofitter  module
argument_list|,
argument|FT_GlyphSlot   slot
argument_list|,
argument|FT_Size        size
argument_list|,
argument|FT_UInt        glyph_index
argument_list|,
argument|FT_Int32       load_flags
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|size
argument_list|)
expr_stmt|;
return|return
name|af_loader_load_glyph
argument_list|(
name|module
operator|->
name|loader
argument_list|,
name|slot
operator|->
name|face
argument_list|,
name|glyph_index
argument_list|,
name|load_flags
argument_list|)
return|;
block|}
end_block
begin_macro
name|FT_DEFINE_AUTOHINTER_SERVICE
argument_list|(
argument|af_autofitter_service
argument_list|,
argument|NULL
argument_list|,
argument|NULL
argument_list|,
argument|NULL
argument_list|,
argument|(FT_AutoHinter_GlyphLoadFunc)af_autofitter_load_glyph
argument_list|)
end_macro
begin_macro
name|FT_DEFINE_MODULE
argument_list|(
argument|autofit_module_class
argument_list|,
argument|FT_MODULE_HINTER
argument_list|,
argument|sizeof ( FT_AutofitterRec )
argument_list|,
literal|"autofitter"
argument_list|,
literal|0x10000L
argument_list|,
comment|/* version 1.0 of the autofitter  */
literal|0x20000L
argument_list|,
comment|/* requires FreeType 2.0 or above */
argument|(const void*)&AF_AF_AUTOFITTER_SERVICE_GET
argument_list|,
argument|(FT_Module_Constructor)af_autofitter_init
argument_list|,
argument|(FT_Module_Destructor) af_autofitter_done
argument_list|,
argument|(FT_Module_Requester)  NULL
argument_list|)
end_macro
begin_comment
comment|/* END */
end_comment
end_unit
