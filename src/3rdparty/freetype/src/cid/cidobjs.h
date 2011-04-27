begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cidobjs.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    CID objects manager (specification).                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2004, 2006 by                               */
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
name|__CIDOBJS_H__
end_ifndef
begin_define
DECL|macro|__CIDOBJS_H__
define|#
directive|define
name|__CIDOBJS_H__
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
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* The following structures must be defined by the hinter */
end_comment
begin_typedef
DECL|typedef|CID_Size_Hints
typedef|typedef
name|struct
name|CID_Size_Hints_
name|CID_Size_Hints
typedef|;
end_typedef
begin_typedef
DECL|typedef|CID_Glyph_Hints
typedef|typedef
name|struct
name|CID_Glyph_Hints_
name|CID_Glyph_Hints
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    CID_Driver                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a Type 1 driver object.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_Driver
typedef|typedef
name|struct
name|CID_DriverRec_
modifier|*
name|CID_Driver
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    CID_Size                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a Type 1 size object.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_Size
typedef|typedef
name|struct
name|CID_SizeRec_
modifier|*
name|CID_Size
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    CID_GlyphSlot                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a Type 1 glyph slot object.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_GlyphSlot
typedef|typedef
name|struct
name|CID_GlyphSlotRec_
modifier|*
name|CID_GlyphSlot
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    CID_CharMap                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a Type 1 character mapping object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The Type 1 format doesn't use a charmap but an encoding table.     */
end_comment
begin_comment
comment|/*    The driver is responsible for making up charmap objects            */
end_comment
begin_comment
comment|/*    corresponding to these tables.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_CharMap
typedef|typedef
name|struct
name|CID_CharMapRec_
modifier|*
name|CID_CharMap
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* HERE BEGINS THE TYPE 1 SPECIFIC STUFF                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_typedef
DECL|struct|CID_SizeRec_
typedef|typedef
struct|struct
name|CID_SizeRec_
block|{
DECL|member|root
name|FT_SizeRec
name|root
decl_stmt|;
DECL|member|valid
name|FT_Bool
name|valid
decl_stmt|;
block|}
DECL|typedef|CID_SizeRec
name|CID_SizeRec
typedef|;
end_typedef
begin_typedef
DECL|struct|CID_GlyphSlotRec_
typedef|typedef
struct|struct
name|CID_GlyphSlotRec_
block|{
DECL|member|root
name|FT_GlyphSlotRec
name|root
decl_stmt|;
DECL|member|hint
name|FT_Bool
name|hint
decl_stmt|;
DECL|member|scaled
name|FT_Bool
name|scaled
decl_stmt|;
DECL|member|x_scale
name|FT_Fixed
name|x_scale
decl_stmt|;
DECL|member|y_scale
name|FT_Fixed
name|y_scale
decl_stmt|;
block|}
DECL|typedef|CID_GlyphSlotRec
name|CID_GlyphSlotRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|slot
name|cid_slot_done
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|slot
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cid_slot_init
argument_list|(
argument|FT_GlyphSlot  slot
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
DECL|variable|cid_size_done
name|cid_size_done
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cid_size_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|cid_size_done
comment|/* CID_Size */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cid_size_init
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* CID_Size */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|cid_size_request
name|cid_size_request
argument_list|(
argument|FT_Size          size
argument_list|,
comment|/* CID_Size */
argument|FT_Size_Request  req
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
name|cid_face_init
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|FT_Face        face
argument_list|,
comment|/* CID_Face */
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
DECL|variable|cid_face_done
name|cid_face_done
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cid_face_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|cid_face_done
comment|/* CID_Face */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cid_driver_init
argument_list|(
argument|FT_Module  driver
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
DECL|variable|cid_driver_done
name|cid_driver_done
argument_list|(
argument|FT_Module  driver
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cid_driver_done
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
comment|/* __CIDOBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
