begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pfrobjs.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType PFR object methods (specification).                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004 by                                          */
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
name|__PFROBJS_H__
end_ifndef
begin_define
DECL|macro|__PFROBJS_H__
define|#
directive|define
name|__PFROBJS_H__
end_define
begin_include
include|#
directive|include
file|"pfrtypes.h"
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|typedef|PFR_Face
typedef|typedef
name|struct
name|PFR_FaceRec_
modifier|*
name|PFR_Face
typedef|;
end_typedef
begin_typedef
DECL|typedef|PFR_Size
typedef|typedef
name|struct
name|PFR_SizeRec_
modifier|*
name|PFR_Size
typedef|;
end_typedef
begin_typedef
DECL|typedef|PFR_Slot
typedef|typedef
name|struct
name|PFR_SlotRec_
modifier|*
name|PFR_Slot
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_FaceRec_
typedef|typedef
struct|struct
name|PFR_FaceRec_
block|{
DECL|member|root
name|FT_FaceRec
name|root
decl_stmt|;
DECL|member|header
name|PFR_HeaderRec
name|header
decl_stmt|;
DECL|member|log_font
name|PFR_LogFontRec
name|log_font
decl_stmt|;
DECL|member|phy_font
name|PFR_PhyFontRec
name|phy_font
decl_stmt|;
block|}
DECL|typedef|PFR_FaceRec
name|PFR_FaceRec
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_SizeRec_
typedef|typedef
struct|struct
name|PFR_SizeRec_
block|{
DECL|member|root
name|FT_SizeRec
name|root
decl_stmt|;
block|}
DECL|typedef|PFR_SizeRec
name|PFR_SizeRec
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_SlotRec_
typedef|typedef
struct|struct
name|PFR_SlotRec_
block|{
DECL|member|root
name|FT_GlyphSlotRec
name|root
decl_stmt|;
DECL|member|glyph
name|PFR_GlyphRec
name|glyph
decl_stmt|;
block|}
DECL|typedef|PFR_SlotRec
name|PFR_SlotRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_face_init
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|FT_Face        face
argument_list|,
comment|/* PFR_Face */
argument|FT_Int         face_index
argument_list|,
argument|FT_Int         num_params
argument_list|,
argument|FT_Parameter*  params
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|pfr_face_done
name|pfr_face_done
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|pfr_face_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|pfr_face_done
comment|/* PFR_Face */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_face_get_kerning
argument_list|(
argument|FT_Face     face
argument_list|,
comment|/* PFR_Face */
argument|FT_UInt     glyph1
argument_list|,
argument|FT_UInt     glyph2
argument_list|,
argument|FT_Vector*  kerning
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
DECL|variable|pfr_slot_init
name|pfr_slot_init
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|pfr_slot_init
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|pfr_slot_init
comment|/* PFR_Slot */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|slot
name|pfr_slot_done
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|slot
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|slot
comment|/* PFR_Slot */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_slot_load
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|,
comment|/* PFR_Slot */
argument|FT_Size       size
argument_list|,
comment|/* PFR_Size */
argument|FT_UInt       gindex
argument_list|,
argument|FT_Int32      load_flags
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
comment|/* __PFROBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
