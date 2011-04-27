begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pfrcmap.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType PFR cmap handling (specification).                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002 by                                                      */
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
name|__PFRCMAP_H__
end_ifndef
begin_define
DECL|macro|__PFRCMAP_H__
define|#
directive|define
name|__PFRCMAP_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
file|"pfrtypes.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|struct|PFR_CMapRec_
typedef|typedef
struct|struct
name|PFR_CMapRec_
block|{
DECL|member|cmap
name|FT_CMapRec
name|cmap
decl_stmt|;
DECL|member|num_chars
name|FT_UInt
name|num_chars
decl_stmt|;
DECL|member|chars
name|PFR_Char
name|chars
decl_stmt|;
block|}
DECL|typedef|PFR_CMapRec
DECL|typedef|PFR_CMap
name|PFR_CMapRec
operator|,
typedef|*
name|PFR_CMap
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|pfr_cmap_class_rec
name|FT_CALLBACK_TABLE
specifier|const
name|FT_CMap_ClassRec
name|pfr_cmap_class_rec
decl_stmt|;
end_decl_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PFRCMAP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
