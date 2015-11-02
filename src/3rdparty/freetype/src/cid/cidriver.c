begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cidriver.c                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    CID driver interface (body).                                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2015 by                                                 */
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
file|"cidriver.h"
end_include
begin_include
include|#
directive|include
file|"cidgload.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DEBUG_H
end_include
begin_include
include|#
directive|include
file|"ciderrs.h"
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_NAME_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_FONT_FORMAT_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_INFO_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_CID_H
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
value|trace_ciddriver
end_define
begin_comment
comment|/*    *  POSTSCRIPT NAME SERVICE    *    */
end_comment
begin_function
specifier|static
specifier|const
name|char
modifier|*
DECL|function|cid_get_postscript_name
name|cid_get_postscript_name
parameter_list|(
name|CID_Face
name|face
parameter_list|)
block|{
specifier|const
name|char
modifier|*
name|result
init|=
name|face
operator|->
name|cid
operator|.
name|cid_font_name
decl_stmt|;
if|if
condition|(
name|result
operator|&&
name|result
index|[
literal|0
index|]
operator|==
literal|'/'
condition|)
name|result
operator|++
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|cid_service_ps_name
specifier|static
specifier|const
name|FT_Service_PsFontNameRec
name|cid_service_ps_name
init|=
block|{
operator|(
name|FT_PsName_GetFunc
operator|)
name|cid_get_postscript_name
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *  POSTSCRIPT INFO SERVICE    *    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|cid_ps_get_font_info
name|cid_ps_get_font_info
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_FontInfoRec
modifier|*
name|afont_info
parameter_list|)
block|{
operator|*
name|afont_info
operator|=
operator|(
operator|(
name|CID_Face
operator|)
name|face
operator|)
operator|->
name|cid
operator|.
name|font_info
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|cid_ps_get_font_extra
name|cid_ps_get_font_extra
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|PS_FontExtraRec
modifier|*
name|afont_extra
parameter_list|)
block|{
operator|*
name|afont_extra
operator|=
operator|(
operator|(
name|CID_Face
operator|)
name|face
operator|)
operator|->
name|font_extra
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|cid_service_ps_info
specifier|static
specifier|const
name|FT_Service_PsInfoRec
name|cid_service_ps_info
init|=
block|{
operator|(
name|PS_GetFontInfoFunc
operator|)
name|cid_ps_get_font_info
block|,
operator|(
name|PS_GetFontExtraFunc
operator|)
name|cid_ps_get_font_extra
block|,
operator|(
name|PS_HasGlyphNamesFunc
operator|)
name|NULL
block|,
comment|/* unsupported with CID fonts */
operator|(
name|PS_GetFontPrivateFunc
operator|)
name|NULL
block|,
comment|/* unsupported                */
operator|(
name|PS_GetFontValueFunc
operator|)
name|NULL
comment|/* not implemented            */
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *  CID INFO SERVICE    *    */
end_comment
begin_function
specifier|static
name|FT_Error
DECL|function|cid_get_ros
name|cid_get_ros
parameter_list|(
name|CID_Face
name|face
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|registry
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|ordering
parameter_list|,
name|FT_Int
modifier|*
name|supplement
parameter_list|)
block|{
name|CID_FaceInfo
name|cid
init|=
operator|&
name|face
operator|->
name|cid
decl_stmt|;
if|if
condition|(
name|registry
condition|)
operator|*
name|registry
operator|=
name|cid
operator|->
name|registry
expr_stmt|;
if|if
condition|(
name|ordering
condition|)
operator|*
name|ordering
operator|=
name|cid
operator|->
name|ordering
expr_stmt|;
if|if
condition|(
name|supplement
condition|)
operator|*
name|supplement
operator|=
name|cid
operator|->
name|supplement
expr_stmt|;
return|return
name|FT_Err_Ok
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|cid_get_is_cid
name|cid_get_is_cid
parameter_list|(
name|CID_Face
name|face
parameter_list|,
name|FT_Bool
modifier|*
name|is_cid
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|is_cid
condition|)
operator|*
name|is_cid
operator|=
literal|1
expr_stmt|;
comment|/* cid driver is only used for CID keyed fonts */
return|return
name|error
return|;
block|}
end_function
begin_function
specifier|static
name|FT_Error
DECL|function|cid_get_cid_from_glyph_index
name|cid_get_cid_from_glyph_index
parameter_list|(
name|CID_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_UInt
modifier|*
name|cid
parameter_list|)
block|{
name|FT_Error
name|error
init|=
name|FT_Err_Ok
decl_stmt|;
name|FT_UNUSED
argument_list|(
name|face
argument_list|)
expr_stmt|;
if|if
condition|(
name|cid
condition|)
operator|*
name|cid
operator|=
name|glyph_index
expr_stmt|;
comment|/* identity mapping */
return|return
name|error
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|cid_service_cid_info
specifier|static
specifier|const
name|FT_Service_CIDRec
name|cid_service_cid_info
init|=
block|{
operator|(
name|FT_CID_GetRegistryOrderingSupplementFunc
operator|)
name|cid_get_ros
block|,
operator|(
name|FT_CID_GetIsInternallyCIDKeyedFunc
operator|)
name|cid_get_is_cid
block|,
operator|(
name|FT_CID_GetCIDFromGlyphIndexFunc
operator|)
name|cid_get_cid_from_glyph_index
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*    *  SERVICE LIST    *    */
end_comment
begin_decl_stmt
DECL|variable|cid_services
specifier|static
specifier|const
name|FT_ServiceDescRec
name|cid_services
index|[]
init|=
block|{
block|{
name|FT_SERVICE_ID_FONT_FORMAT
block|,
name|FT_FONT_FORMAT_CID
block|}
block|,
block|{
name|FT_SERVICE_ID_POSTSCRIPT_FONT_NAME
block|,
operator|&
name|cid_service_ps_name
block|}
block|,
block|{
name|FT_SERVICE_ID_POSTSCRIPT_INFO
block|,
operator|&
name|cid_service_ps_info
block|}
block|,
block|{
name|FT_SERVICE_ID_CID
block|,
operator|&
name|cid_service_cid_info
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_macro
DECL|function|FT_CALLBACK_DEF
name|FT_CALLBACK_DEF
argument_list|(
argument|FT_Module_Interface
argument_list|)
end_macro
begin_macro
name|cid_get_interface
argument_list|(
argument|FT_Module    module
argument_list|,
argument|const char*  cid_interface
argument_list|)
end_macro
begin_block
block|{
name|FT_UNUSED
argument_list|(
name|module
argument_list|)
expr_stmt|;
return|return
name|ft_service_list_lookup
argument_list|(
name|cid_services
argument_list|,
name|cid_interface
argument_list|)
return|;
block|}
end_block
begin_decl_stmt
name|FT_CALLBACK_TABLE_DEF
DECL|variable|t1cid_driver_class
specifier|const
name|FT_Driver_ClassRec
name|t1cid_driver_class
init|=
block|{
comment|/* first of all, the FT_Module_Class fields */
block|{
name|FT_MODULE_FONT_DRIVER
operator||
name|FT_MODULE_DRIVER_SCALABLE
operator||
name|FT_MODULE_DRIVER_HAS_HINTER
block|,
sizeof|sizeof
argument_list|(
name|FT_DriverRec
argument_list|)
block|,
literal|"t1cid"
block|,
comment|/* module name           */
literal|0x10000L
block|,
comment|/* version 1.0 of driver */
literal|0x20000L
block|,
comment|/* requires FreeType 2.0 */
literal|0
block|,
name|cid_driver_init
block|,
name|cid_driver_done
block|,
name|cid_get_interface
block|}
block|,
comment|/* then the other font drivers fields */
sizeof|sizeof
argument_list|(
name|CID_FaceRec
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|CID_SizeRec
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|CID_GlyphSlotRec
argument_list|)
block|,
name|cid_face_init
block|,
name|cid_face_done
block|,
name|cid_size_init
block|,
name|cid_size_done
block|,
name|cid_slot_init
block|,
name|cid_slot_done
block|,
name|cid_slot_load_glyph
block|,
literal|0
block|,
comment|/* FT_Face_GetKerningFunc  */
literal|0
block|,
comment|/* FT_Face_AttachFunc      */
literal|0
block|,
comment|/* FT_Face_GetAdvancesFunc */
name|cid_size_request
block|,
literal|0
comment|/* FT_Size_SelectFunc      */
block|}
decl_stmt|;
end_decl_stmt
begin_comment
comment|/* END */
end_comment
end_unit
