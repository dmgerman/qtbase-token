begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afindic.c                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter hinting routines for Indic writing system (body).        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007, 2011-2013 by                                           */
end_comment
begin_comment
comment|/*  Rahul Bhalerao<rahul.bhalerao@redhat.com>,<b.rahul.pm@gmail.com>.    */
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
file|"aftypes.h"
end_include
begin_include
include|#
directive|include
file|"aflatin.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_INDIC
end_ifdef
begin_include
include|#
directive|include
file|"afindic.h"
end_include
begin_include
include|#
directive|include
file|"aferrors.h"
end_include
begin_include
include|#
directive|include
file|"afcjk.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|AF_CONFIG_OPTION_USE_WARPER
end_ifdef
begin_include
include|#
directive|include
file|"afwarp.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
specifier|static
name|FT_Error
DECL|function|af_indic_metrics_init
name|af_indic_metrics_init
parameter_list|(
name|AF_CJKMetrics
name|metrics
parameter_list|,
name|FT_Face
name|face
parameter_list|)
block|{
comment|/* skip blue zone init in CJK routines */
name|FT_CharMap
name|oldmap
init|=
name|face
operator|->
name|charmap
decl_stmt|;
name|metrics
operator|->
name|units_per_em
operator|=
name|face
operator|->
name|units_per_EM
expr_stmt|;
if|if
condition|(
name|FT_Select_Charmap
argument_list|(
name|face
argument_list|,
name|FT_ENCODING_UNICODE
argument_list|)
condition|)
name|face
operator|->
name|charmap
operator|=
name|NULL
expr_stmt|;
else|else
block|{
name|af_cjk_metrics_init_widths
argument_list|(
name|metrics
argument_list|,
name|face
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|/* either need indic specific blue_chars[] or just skip blue zones */
block|af_cjk_metrics_init_blues( metrics, face, af_cjk_blue_chars );
endif|#
directive|endif
name|af_cjk_metrics_check_digits
argument_list|(
name|metrics
argument_list|,
name|face
argument_list|)
expr_stmt|;
block|}
name|FT_Set_Charmap
argument_list|(
name|face
argument_list|,
name|oldmap
argument_list|)
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|af_indic_metrics_scale
name|af_indic_metrics_scale
parameter_list|(
name|AF_CJKMetrics
name|metrics
parameter_list|,
name|AF_Scaler
name|scaler
parameter_list|)
block|{
comment|/* use CJK routines */
name|af_cjk_metrics_scale
argument_list|(
name|metrics
argument_list|,
name|scaler
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|af_indic_hints_init
name|af_indic_hints_init
parameter_list|(
name|AF_GlyphHints
name|hints
parameter_list|,
name|AF_CJKMetrics
name|metrics
parameter_list|)
block|{
comment|/* use CJK routines */
return|return
name|af_cjk_hints_init
argument_list|(
name|hints
argument_list|,
name|metrics
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|af_indic_hints_apply
name|af_indic_hints_apply
parameter_list|(
name|AF_GlyphHints
name|hints
parameter_list|,
name|FT_Outline
modifier|*
name|outline
parameter_list|,
name|AF_CJKMetrics
name|metrics
parameter_list|)
block|{
comment|/* use CJK routines */
return|return
name|af_cjk_hints_apply
argument_list|(
name|hints
argument_list|,
name|outline
argument_list|,
name|metrics
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*****                I N D I C   S C R I P T   C L A S S            *****/
end_comment
begin_comment
comment|/*****                                                               *****/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_macro
name|AF_DEFINE_WRITING_SYSTEM_CLASS
argument_list|(
argument|af_indic_writing_system_class
argument_list|,
argument|AF_WRITING_SYSTEM_INDIC
argument_list|,
argument|sizeof ( AF_CJKMetricsRec )
argument_list|,
argument|(AF_WritingSystem_InitMetricsFunc) af_indic_metrics_init
argument_list|,
argument|(AF_WritingSystem_ScaleMetricsFunc)af_indic_metrics_scale
argument_list|,
argument|(AF_WritingSystem_DoneMetricsFunc) NULL
argument_list|,
argument|(AF_WritingSystem_InitHintsFunc)   af_indic_hints_init
argument_list|,
argument|(AF_WritingSystem_ApplyHintsFunc)  af_indic_hints_apply
argument_list|)
end_macro
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !AF_CONFIG_OPTION_INDIC */
end_comment
begin_macro
name|AF_DEFINE_WRITING_SYSTEM_CLASS
argument_list|(
argument|af_indic_writing_system_class
argument_list|,
argument|AF_WRITING_SYSTEM_INDIC
argument_list|,
argument|sizeof ( AF_CJKMetricsRec )
argument_list|,
argument|(AF_WritingSystem_InitMetricsFunc) NULL
argument_list|,
argument|(AF_WritingSystem_ScaleMetricsFunc)NULL
argument_list|,
argument|(AF_WritingSystem_DoneMetricsFunc) NULL
argument_list|,
argument|(AF_WritingSystem_InitHintsFunc)   NULL
argument_list|,
argument|(AF_WritingSystem_ApplyHintsFunc)  NULL
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !AF_CONFIG_OPTION_INDIC */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
