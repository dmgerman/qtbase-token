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
comment|/*    Auto-fitter hinting routines for Indic scripts (body).               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007 by                                                      */
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
name|AF_USE_WARPER
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
name|AF_LatinMetrics
name|metrics
parameter_list|,
name|FT_Face
name|face
parameter_list|)
block|{
comment|/* use CJK routines */
return|return
name|af_cjk_metrics_init
argument_list|(
name|metrics
argument_list|,
name|face
argument_list|)
return|;
block|}
end_function
begin_function
specifier|static
name|void
DECL|function|af_indic_metrics_scale
name|af_indic_metrics_scale
parameter_list|(
name|AF_LatinMetrics
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
name|AF_LatinMetrics
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
name|AF_LatinMetrics
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
begin_decl_stmt
DECL|variable|af_indic_uniranges
specifier|static
specifier|const
name|AF_Script_UniRangeRec
name|af_indic_uniranges
index|[]
init|=
block|{
if|#
directive|if
literal|0
block|AF_UNIRANGE_REC( 0x0100UL, 0xFFFFUL ),
comment|/* why this? */
endif|#
directive|endif
name|AF_UNIRANGE_REC
argument_list|(
literal|0x0900UL
argument_list|,
literal|0x0DFFUL
argument_list|)
block|,
comment|/* Indic Range */
name|AF_UNIRANGE_REC
argument_list|(
literal|0UL
argument_list|,
literal|0UL
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|AF_DEFINE_SCRIPT_CLASS
argument_list|(
argument|af_indic_script_class
argument_list|,
argument|AF_SCRIPT_INDIC
argument_list|,
argument|af_indic_uniranges
argument_list|,
argument|sizeof( AF_LatinMetricsRec )
argument_list|,
argument|(AF_Script_InitMetricsFunc) af_indic_metrics_init
argument_list|,
argument|(AF_Script_ScaleMetricsFunc)af_indic_metrics_scale
argument_list|,
argument|(AF_Script_DoneMetricsFunc) NULL
argument_list|,
argument|(AF_Script_InitHintsFunc)   af_indic_hints_init
argument_list|,
argument|(AF_Script_ApplyHintsFunc)  af_indic_hints_apply
argument_list|)
end_macro
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !AF_CONFIG_OPTION_INDIC */
end_comment
begin_decl_stmt
specifier|static
specifier|const
name|AF_Script_UniRangeRec
name|af_indic_uniranges
index|[]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_macro
name|AF_DEFINE_SCRIPT_CLASS
argument_list|(
argument|af_indic_script_class
argument_list|,
argument|AF_SCRIPT_INDIC
argument_list|,
argument|af_indic_uniranges
argument_list|,
argument|sizeof( AF_LatinMetricsRec )
argument_list|,
argument|(AF_Script_InitMetricsFunc) NULL
argument_list|,
argument|(AF_Script_ScaleMetricsFunc)NULL
argument_list|,
argument|(AF_Script_DoneMetricsFunc) NULL
argument_list|,
argument|(AF_Script_InitHintsFunc)   NULL
argument_list|,
argument|(AF_Script_ApplyHintsFunc)  NULL
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
