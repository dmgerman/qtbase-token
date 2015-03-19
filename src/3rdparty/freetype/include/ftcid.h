begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftcid.h                                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType API for accessing CID font information (specification).     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2007, 2009 by Dereg Clegg, Michael Toftdal.                  */
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
name|__FTCID_H__
end_ifndef
begin_define
DECL|macro|__FTCID_H__
define|#
directive|define
name|__FTCID_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_FREETYPE_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    cid_fonts                                                          */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    CID Fonts                                                          */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    CID-keyed font specific API.                                       */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains the declaration of CID-keyed font specific   */
comment|/*    functions.                                                         */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/**********************************************************************    *    * @function:    *    FT_Get_CID_Registry_Ordering_Supplement    *    * @description:    *    Retrieve the Registry/Ordering/Supplement triple (also known as the    *    "R/O/S") from a CID-keyed font.    *    * @input:    *    face ::    *       A handle to the input face.    *    * @output:    *    registry ::    *       The registry, as a C~string, owned by the face.    *    *    ordering ::    *       The ordering, as a C~string, owned by the face.    *    *    supplement ::    *       The supplement.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *    This function only works with CID faces, returning an error    *    otherwise.    *    * @since:    *    2.3.6    */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Get_CID_Registry_Ordering_Supplement
parameter_list|(
name|FT_Face
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
function_decl|;
end_function_decl
begin_comment
comment|/**********************************************************************    *    * @function:    *    FT_Get_CID_Is_Internally_CID_Keyed    *    * @description:    *    Retrieve the type of the input face, CID keyed or not.  In    *    constrast to the @FT_IS_CID_KEYED macro this function returns    *    successfully also for CID-keyed fonts in an SNFT wrapper.    *    * @input:    *    face ::    *       A handle to the input face.    *    * @output:    *    is_cid ::    *       The type of the face as an @FT_Bool.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *    This function only works with CID faces and OpenType fonts,    *    returning an error otherwise.    *    * @since:    *    2.3.9    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_CID_Is_Internally_CID_Keyed
name|FT_Get_CID_Is_Internally_CID_Keyed
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_Bool  *is_cid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**********************************************************************    *    * @function:    *    FT_Get_CID_From_Glyph_Index    *    * @description:    *    Retrieve the CID of the input glyph index.    *    * @input:    *    face ::    *       A handle to the input face.    *    *    glyph_index ::    *       The input glyph index.    *    * @output:    *    cid ::    *       The CID as an @FT_UInt.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *    This function only works with CID faces and OpenType fonts,    *    returning an error otherwise.    *    * @since:    *    2.3.9    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_CID_From_Glyph_Index
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt   glyph_index
argument_list|,
argument|FT_UInt  *cid
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
comment|/* __FTCID_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
