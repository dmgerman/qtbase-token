begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cffobjs.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    OpenType objects manager (specification).                            */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2004, 2006-2008, 2013 by                                */
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
name|__CFFOBJS_H__
end_ifndef
begin_define
DECL|macro|__CFFOBJS_H__
define|#
directive|define
name|__CFFOBJS_H__
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
file|"cfftypes.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TRUETYPE_TYPES_H
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_CMAPS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_POSTSCRIPT_HINTS_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
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
comment|/*    CFF_Driver                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an OpenType driver object.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CFF_Driver
typedef|typedef
name|struct
name|CFF_DriverRec_
modifier|*
name|CFF_Driver
typedef|;
end_typedef
begin_typedef
DECL|typedef|CFF_Face
typedef|typedef
name|TT_Face
name|CFF_Face
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
comment|/*    CFF_Size                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an OpenType size object.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CFF_SizeRec_
typedef|typedef
struct|struct
name|CFF_SizeRec_
block|{
DECL|member|root
name|FT_SizeRec
name|root
decl_stmt|;
DECL|member|strike_index
name|FT_ULong
name|strike_index
decl_stmt|;
comment|/* 0xFFFFFFFF to indicate invalid */
block|}
DECL|typedef|CFF_SizeRec
DECL|typedef|CFF_Size
name|CFF_SizeRec
operator|,
typedef|*
name|CFF_Size
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
comment|/*    CFF_GlyphSlot                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an OpenType glyph slot object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CFF_GlyphSlotRec_
typedef|typedef
struct|struct
name|CFF_GlyphSlotRec_
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
DECL|typedef|CFF_GlyphSlotRec
DECL|typedef|CFF_GlyphSlot
name|CFF_GlyphSlotRec
operator|,
typedef|*
name|CFF_GlyphSlot
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
comment|/*    CFF_Internal                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The interface to the `internal' field of `FT_Size'.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CFF_InternalRec_
typedef|typedef
struct|struct
name|CFF_InternalRec_
block|{
DECL|member|topfont
name|PSH_Globals
name|topfont
decl_stmt|;
DECL|member|subfonts
name|PSH_Globals
name|subfonts
index|[
name|CFF_MAX_CID_FONTS
index|]
decl_stmt|;
block|}
DECL|typedef|CFF_InternalRec
DECL|typedef|CFF_Internal
name|CFF_InternalRec
operator|,
typedef|*
name|CFF_Internal
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Subglyph transformation record.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CFF_Transform_
typedef|typedef
struct|struct
name|CFF_Transform_
block|{
DECL|member|xx
DECL|member|xy
name|FT_Fixed
name|xx
decl_stmt|,
name|xy
decl_stmt|;
comment|/* transformation matrix coefficients */
DECL|member|yx
DECL|member|yy
name|FT_Fixed
name|yx
decl_stmt|,
name|yy
decl_stmt|;
DECL|member|ox
DECL|member|oy
name|FT_F26Dot6
name|ox
decl_stmt|,
name|oy
decl_stmt|;
comment|/* offsets        */
block|}
DECL|typedef|CFF_Transform
name|CFF_Transform
typedef|;
end_typedef
begin_comment
comment|/***********************************************************************/
end_comment
begin_comment
comment|/*                                                                     */
end_comment
begin_comment
comment|/* CFF driver class.                                                   */
end_comment
begin_comment
comment|/*                                                                     */
end_comment
begin_typedef
DECL|struct|CFF_DriverRec_
typedef|typedef
struct|struct
name|CFF_DriverRec_
block|{
DECL|member|root
name|FT_DriverRec
name|root
decl_stmt|;
DECL|member|hinting_engine
name|FT_UInt
name|hinting_engine
decl_stmt|;
DECL|member|no_stem_darkening
name|FT_Bool
name|no_stem_darkening
decl_stmt|;
DECL|member|darken_params
name|FT_Int
name|darken_params
index|[
literal|8
index|]
decl_stmt|;
block|}
DECL|typedef|CFF_DriverRec
name|CFF_DriverRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cff_size_init
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* CFF_Size */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|cff_size_done
name|cff_size_done
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cff_size_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|cff_size_done
comment|/* CFF_Size */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cff_size_request
argument_list|(
argument|FT_Size          size
argument_list|,
argument|FT_Size_Request  req
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_EMBEDDED_BITMAPS
end_ifdef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|cff_size_select
name|cff_size_select
argument_list|(
argument|FT_Size   size
argument_list|,
argument|FT_ULong  strike_index
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|slot
name|cff_slot_done
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
name|cff_slot_init
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Face functions                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|cff_face_init
name|cff_face_init
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|FT_Face        face
argument_list|,
comment|/* CFF_Face */
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
DECL|variable|face
name|cff_face_done
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|face
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|face
comment|/* CFF_Face */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Driver functions                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|cff_driver_init
argument_list|(
argument|FT_Module  module
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* CFF_Driver */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|cff_driver_done
name|cff_driver_done
argument_list|(
argument|FT_Module  module
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|cff_driver_done
empty_stmt|;
end_empty_stmt
begin_comment
DECL|variable|cff_driver_done
comment|/* CFF_Driver */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CFFOBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
