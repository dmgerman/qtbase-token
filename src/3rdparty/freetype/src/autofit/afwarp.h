begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  afwarp.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Auto-fitter warping algorithm (specification).                       */
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
name|__AFWARP_H__
end_ifndef
begin_define
DECL|macro|__AFWARP_H__
define|#
directive|define
name|__AFWARP_H__
end_define
begin_include
include|#
directive|include
file|"afhints.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_define
DECL|macro|AF_WARPER_SCALE
define|#
directive|define
name|AF_WARPER_SCALE
end_define
begin_define
DECL|macro|AF_WARPER_FLOOR
define|#
directive|define
name|AF_WARPER_FLOOR
parameter_list|(
name|x
parameter_list|)
value|( (x)& ~63 )
end_define
begin_define
DECL|macro|AF_WARPER_CEIL
define|#
directive|define
name|AF_WARPER_CEIL
parameter_list|(
name|x
parameter_list|)
value|AF_WARPER_FLOOR( (x) + 63 )
end_define
begin_typedef
DECL|typedef|AF_WarpScore
typedef|typedef
name|FT_Int32
name|AF_WarpScore
typedef|;
end_typedef
begin_typedef
DECL|struct|AF_WarperRec_
typedef|typedef
struct|struct
name|AF_WarperRec_
block|{
DECL|member|x1
DECL|member|x2
name|FT_Pos
name|x1
decl_stmt|,
name|x2
decl_stmt|;
DECL|member|t1
DECL|member|t2
name|FT_Pos
name|t1
decl_stmt|,
name|t2
decl_stmt|;
DECL|member|x1min
DECL|member|x1max
name|FT_Pos
name|x1min
decl_stmt|,
name|x1max
decl_stmt|;
DECL|member|x2min
DECL|member|x2max
name|FT_Pos
name|x2min
decl_stmt|,
name|x2max
decl_stmt|;
DECL|member|w0
DECL|member|wmin
DECL|member|wmax
name|FT_Pos
name|w0
decl_stmt|,
name|wmin
decl_stmt|,
name|wmax
decl_stmt|;
DECL|member|best_scale
name|FT_Fixed
name|best_scale
decl_stmt|;
DECL|member|best_delta
name|FT_Pos
name|best_delta
decl_stmt|;
DECL|member|best_score
name|AF_WarpScore
name|best_score
decl_stmt|;
DECL|member|best_distort
name|AF_WarpScore
name|best_distort
decl_stmt|;
block|}
DECL|typedef|AF_WarperRec
DECL|typedef|AF_Warper
name|AF_WarperRec
operator|,
typedef|*
name|AF_Warper
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|af_warper_compute
argument_list|(
argument|AF_Warper      warper
argument_list|,
argument|AF_GlyphHints  hints
argument_list|,
argument|AF_Dimension   dim
argument_list|,
argument|FT_Fixed      *a_scale
argument_list|,
argument|FT_Fixed      *a_delta
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __AFWARP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
