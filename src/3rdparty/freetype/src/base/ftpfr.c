begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftpfr.c                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing PFR-specific data (body).                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
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
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_PFR_H
end_include
begin_comment
comment|/* check the format */
end_comment
begin_function
specifier|static
name|FT_Service_PfrMetrics
DECL|function|ft_pfr_check
name|ft_pfr_check
parameter_list|(
name|FT_Face
name|face
parameter_list|)
block|{
name|FT_Service_PfrMetrics
name|service
init|=
name|NULL
decl_stmt|;
if|if
condition|(
name|face
condition|)
name|FT_FACE_LOOKUP_SERVICE
argument_list|(
name|face
argument_list|,
name|service
argument_list|,
name|PFR_METRICS
argument_list|)
expr_stmt|;
return|return
name|service
return|;
block|}
end_function
begin_comment
comment|/* documentation is in ftpfr.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_PFR_Metrics
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt   *aoutline_resolution
argument_list|,
argument|FT_UInt   *ametrics_resolution
argument_list|,
argument|FT_Fixed  *ametrics_x_scale
argument_list|,
argument|FT_Fixed  *ametrics_y_scale
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_Service_PfrMetrics
name|service
decl_stmt|;
if|if
condition|(
operator|!
name|face
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Face_Handle
argument_list|)
return|;
name|service
operator|=
name|ft_pfr_check
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
condition|)
block|{
name|error
operator|=
name|service
operator|->
name|get_metrics
argument_list|(
name|face
argument_list|,
name|aoutline_resolution
argument_list|,
name|ametrics_resolution
argument_list|,
name|ametrics_x_scale
argument_list|,
name|ametrics_y_scale
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|FT_Fixed
name|x_scale
decl_stmt|,
name|y_scale
decl_stmt|;
comment|/* this is not a PFR font */
if|if
condition|(
name|aoutline_resolution
condition|)
operator|*
name|aoutline_resolution
operator|=
name|face
operator|->
name|units_per_EM
expr_stmt|;
if|if
condition|(
name|ametrics_resolution
condition|)
operator|*
name|ametrics_resolution
operator|=
name|face
operator|->
name|units_per_EM
expr_stmt|;
name|x_scale
operator|=
name|y_scale
operator|=
literal|0x10000L
expr_stmt|;
if|if
condition|(
name|face
operator|->
name|size
condition|)
block|{
name|x_scale
operator|=
name|face
operator|->
name|size
operator|->
name|metrics
operator|.
name|x_scale
expr_stmt|;
name|y_scale
operator|=
name|face
operator|->
name|size
operator|->
name|metrics
operator|.
name|y_scale
expr_stmt|;
block|}
if|if
condition|(
name|ametrics_x_scale
condition|)
operator|*
name|ametrics_x_scale
operator|=
name|x_scale
expr_stmt|;
if|if
condition|(
name|ametrics_y_scale
condition|)
operator|*
name|ametrics_y_scale
operator|=
name|y_scale
expr_stmt|;
name|error
operator|=
name|FT_THROW
argument_list|(
name|Unknown_File_Format
argument_list|)
expr_stmt|;
block|}
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftpfr.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_PFR_Kerning
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_UInt     left
argument_list|,
argument|FT_UInt     right
argument_list|,
argument|FT_Vector  *avector
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Service_PfrMetrics
name|service
decl_stmt|;
if|if
condition|(
operator|!
name|face
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Face_Handle
argument_list|)
return|;
if|if
condition|(
operator|!
name|avector
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
return|;
name|service
operator|=
name|ft_pfr_check
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
condition|)
name|error
operator|=
name|service
operator|->
name|get_kerning
argument_list|(
name|face
argument_list|,
name|left
argument_list|,
name|right
argument_list|,
name|avector
argument_list|)
expr_stmt|;
else|else
name|error
operator|=
name|FT_Get_Kerning
argument_list|(
name|face
argument_list|,
name|left
argument_list|,
name|right
argument_list|,
name|FT_KERNING_UNSCALED
argument_list|,
name|avector
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* documentation is in ftpfr.h */
end_comment
begin_macro
DECL|function|FT_EXPORT_DEF
name|FT_EXPORT_DEF
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_PFR_Advance
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt   gindex
argument_list|,
argument|FT_Pos   *aadvance
argument_list|)
end_macro
begin_block
block|{
name|FT_Error
name|error
decl_stmt|;
name|FT_Service_PfrMetrics
name|service
decl_stmt|;
if|if
condition|(
operator|!
name|face
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Face_Handle
argument_list|)
return|;
if|if
condition|(
operator|!
name|aadvance
condition|)
return|return
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
return|;
name|service
operator|=
name|ft_pfr_check
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|service
condition|)
name|error
operator|=
name|service
operator|->
name|get_advance
argument_list|(
name|face
argument_list|,
name|gindex
argument_list|,
name|aadvance
argument_list|)
expr_stmt|;
else|else
comment|/* XXX: TODO: PROVIDE ADVANCE-LOADING METHOD TO ALL FONT DRIVERS */
name|error
operator|=
name|FT_THROW
argument_list|(
name|Invalid_Argument
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
end_block
begin_comment
comment|/* END */
end_comment
end_unit
