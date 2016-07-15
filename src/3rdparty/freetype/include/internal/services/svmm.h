begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  svmm.h                                                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType Multiple Masters and GX var services (specification).   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2003, 2004, 2009, 2012 by                                    */
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
name|__SVMM_H__
end_ifndef
begin_define
DECL|macro|__SVMM_H__
define|#
directive|define
name|__SVMM_H__
end_define
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/*    *  A service used to manage multiple-masters data in a given face.    *    *  See the related APIs in `ftmm.h' (FT_MULTIPLE_MASTERS_H).    *    */
end_comment
begin_define
DECL|macro|FT_SERVICE_ID_MULTI_MASTERS
define|#
directive|define
name|FT_SERVICE_ID_MULTI_MASTERS
value|"multi-masters"
end_define
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Get_MM_Func
modifier|*
name|FT_Get_MM_Func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_Multi_Master
modifier|*
name|master
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Get_MM_Var_Func
modifier|*
name|FT_Get_MM_Var_Func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_MM_Var
modifier|*
modifier|*
name|master
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Set_MM_Design_Func
modifier|*
name|FT_Set_MM_Design_Func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|num_coords
parameter_list|,
name|FT_Long
modifier|*
name|coords
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Set_Var_Design_Func
modifier|*
name|FT_Set_Var_Design_Func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|num_coords
parameter_list|,
name|FT_Fixed
modifier|*
name|coords
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Set_MM_Blend_Func
modifier|*
name|FT_Set_MM_Blend_Func
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|num_coords
parameter_list|,
name|FT_Long
modifier|*
name|coords
parameter_list|)
function_decl|;
end_typedef
begin_macro
DECL|function|FT_DEFINE_SERVICE
name|FT_DEFINE_SERVICE
argument_list|(
argument|MultiMasters
argument_list|)
end_macro
begin_block
block|{
name|FT_Get_MM_Func
name|get_mm
decl_stmt|;
name|FT_Set_MM_Design_Func
name|set_mm_design
decl_stmt|;
name|FT_Set_MM_Blend_Func
name|set_mm_blend
decl_stmt|;
name|FT_Get_MM_Var_Func
name|get_mm_var
decl_stmt|;
name|FT_Set_Var_Design_Func
name|set_var_design
decl_stmt|;
block|}
end_block
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_SERVICE_MULTIMASTERSREC
define|#
directive|define
name|FT_DEFINE_SERVICE_MULTIMASTERSREC
parameter_list|(
name|class_
parameter_list|,                          \
name|get_mm_
parameter_list|,                         \
name|set_mm_design_
parameter_list|,                  \
name|set_mm_blend_
parameter_list|,                   \
name|get_mm_var_
parameter_list|,                     \
name|set_var_design_
parameter_list|)
define|\
value|static const FT_Service_MultiMastersRec  class_ =                         \   {                                                                         \     get_mm_, set_mm_design_, set_mm_blend_, get_mm_var_, set_var_design_    \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_SERVICE_MULTIMASTERSREC
define|#
directive|define
name|FT_DEFINE_SERVICE_MULTIMASTERSREC
parameter_list|(
name|class_
parameter_list|,                          \
name|get_mm_
parameter_list|,                         \
name|set_mm_design_
parameter_list|,                  \
name|set_mm_blend_
parameter_list|,                   \
name|get_mm_var_
parameter_list|,                     \
name|set_var_design_
parameter_list|)
define|\
value|void                                                                      \   FT_Init_Class_ ## class_( FT_Service_MultiMastersRec*  clazz )            \   {                                                                         \     clazz->get_mm         = get_mm_;                                        \     clazz->set_mm_design  = set_mm_design_;                                 \     clazz->set_mm_blend   = set_mm_blend_;                                  \     clazz->get_mm_var     = get_mm_var_;                                    \     clazz->set_var_design = set_var_design_;                                \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
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
comment|/* __SVMM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
