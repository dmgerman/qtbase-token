begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cffcmap.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    CFF character mapping table (cmap) support (specification).          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2006 by                                          */
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
name|__CFFCMAP_H__
end_ifndef
begin_define
DECL|macro|__CFFCMAP_H__
define|#
directive|define
name|__CFFCMAP_H__
end_define
begin_include
include|#
directive|include
file|"cffobjs.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
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
comment|/*****          TYPE1 STANDARD (AND EXPERT) ENCODING CMAPS           *****/
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
begin_comment
comment|/* standard (and expert) encoding cmaps */
end_comment
begin_typedef
DECL|typedef|CFF_CMapStd
typedef|typedef
name|struct
name|CFF_CMapStdRec_
modifier|*
name|CFF_CMapStd
typedef|;
end_typedef
begin_typedef
DECL|struct|CFF_CMapStdRec_
typedef|typedef
struct|struct
name|CFF_CMapStdRec_
block|{
DECL|member|cmap
name|FT_CMapRec
name|cmap
decl_stmt|;
DECL|member|gids
name|FT_UShort
modifier|*
name|gids
decl_stmt|;
comment|/* up to 256 elements */
block|}
DECL|typedef|CFF_CMapStdRec
name|CFF_CMapStdRec
typedef|;
end_typedef
begin_macro
name|FT_DECLARE_CMAP_CLASS
argument_list|(
argument|cff_cmap_encoding_class_rec
argument_list|)
end_macro
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
comment|/*****               CFF SYNTHETIC UNICODE ENCODING CMAP             *****/
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
begin_comment
comment|/* unicode (synthetic) cmaps */
end_comment
begin_macro
name|FT_DECLARE_CMAP_CLASS
argument_list|(
argument|cff_cmap_unicode_class_rec
argument_list|)
end_macro
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CFFCMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
