begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afdummy.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter dummy routines to be used if no hinting should be        */
end_comment
begin_comment
comment|/*    performed (body).                                                    */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2005 by                                          */
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
file|"afdummy.h"
end_include
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_function
specifier|static
name|FT_Error
DECL|function|af_dummy_hints_init
name|af_dummy_hints_init
parameter_list|(
name|AF_GlyphHints
name|hints
parameter_list|,
name|AF_ScriptMetrics
name|metrics
parameter_list|)
block|{
name|af_glyph_hints_rescale
argument_list|(
name|hints
argument_list|,
name|metrics
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|af_dummy_hints_apply
name|af_dummy_hints_apply
parameter_list|(
name|AF_GlyphHints
name|hints
parameter_list|,
name|FT_Outline
modifier|*
name|outline
parameter_list|)
block|{
name|FT_UNUSED
argument_list|(
name|hints
argument_list|)
expr_stmt|;
name|FT_UNUSED
argument_list|(
name|outline
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function
begin_macro
name|AF_DEFINE_SCRIPT_CLASS
argument_list|(
argument|af_dummy_script_class
argument_list|,
argument|AF_SCRIPT_NONE
argument_list|,
argument|NULL
argument_list|,
argument|sizeof( AF_ScriptMetricsRec )
argument_list|,
argument|(AF_Script_InitMetricsFunc) NULL
argument_list|,
argument|(AF_Script_ScaleMetricsFunc)NULL
argument_list|,
argument|(AF_Script_DoneMetricsFunc) NULL
argument_list|,
argument|(AF_Script_InitHintsFunc)   af_dummy_hints_init
argument_list|,
argument|(AF_Script_ApplyHintsFunc)  af_dummy_hints_apply
argument_list|)
end_macro
begin_comment
comment|/* END */
end_comment
end_unit
