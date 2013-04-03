begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afcjk.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter hinting routines for CJK script (specification).         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2006, 2007 by                                                */
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
name|__AFCJK_H__
end_ifndef
begin_define
DECL|macro|__AFCJK_H__
define|#
directive|define
name|__AFCJK_H__
end_define
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_function_decl
name|FT_BEGIN_HEADER
comment|/* the CJK-specific script class */
name|AF_DECLARE_SCRIPT_CLASS
parameter_list|(
name|af_cjk_script_class
parameter_list|)
function_decl|FT_LOCAL
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|af_cjk_metrics_init
parameter_list|(
name|AF_LatinMetrics
name|metrics
parameter_list|,
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|af_cjk_metrics_scale
name|af_cjk_metrics_scale
argument_list|(
argument|AF_LatinMetrics  metrics
argument_list|,
argument|AF_Scaler        scaler
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|af_cjk_hints_init
argument_list|(
argument|AF_GlyphHints    hints
argument_list|,
argument|AF_LatinMetrics  metrics
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|af_cjk_hints_apply
name|af_cjk_hints_apply
argument_list|(
argument|AF_GlyphHints    hints
argument_list|,
argument|FT_Outline*      outline
argument_list|,
argument|AF_LatinMetrics  metrics
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFCJK_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
