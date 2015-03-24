begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t42objs.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 42 objects manager (specification).                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2006, 2007, 2011 by Roberto Alameda.             */
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
name|__T42OBJS_H__
end_ifndef
begin_define
DECL|macro|__T42OBJS_H__
define|#
directive|define
name|__T42OBJS_H__
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
begin_include
include|#
directive|include
include|FT_TYPE1_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TYPE1_TYPES_H
end_include
begin_include
include|#
directive|include
file|"t42types.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DRIVER_H
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
comment|/* Type42 size */
end_comment
begin_typedef
DECL|struct|T42_SizeRec_
typedef|typedef
struct|struct
name|T42_SizeRec_
block|{
DECL|member|root
name|FT_SizeRec
name|root
decl_stmt|;
DECL|member|ttsize
name|FT_Size
name|ttsize
decl_stmt|;
block|}
DECL|typedef|T42_SizeRec
DECL|typedef|T42_Size
name|T42_SizeRec
operator|,
typedef|*
name|T42_Size
typedef|;
end_typedef
begin_comment
comment|/* Type42 slot */
end_comment
begin_typedef
DECL|struct|T42_GlyphSlotRec_
typedef|typedef
struct|struct
name|T42_GlyphSlotRec_
block|{
DECL|member|root
name|FT_GlyphSlotRec
name|root
decl_stmt|;
DECL|member|ttslot
name|FT_GlyphSlot
name|ttslot
decl_stmt|;
block|}
DECL|typedef|T42_GlyphSlotRec
DECL|typedef|T42_GlyphSlot
name|T42_GlyphSlotRec
operator|,
typedef|*
name|T42_GlyphSlot
typedef|;
end_typedef
begin_comment
comment|/* Type 42 driver */
end_comment
begin_typedef
DECL|struct|T42_DriverRec_
typedef|typedef
struct|struct
name|T42_DriverRec_
block|{
DECL|member|root
name|FT_DriverRec
name|root
decl_stmt|;
DECL|member|ttclazz
name|FT_Driver_Class
name|ttclazz
decl_stmt|;
DECL|member|extension_component
name|void
modifier|*
name|extension_component
decl_stmt|;
block|}
DECL|typedef|T42_DriverRec
DECL|typedef|T42_Driver
name|T42_DriverRec
operator|,
typedef|*
name|T42_Driver
typedef|;
end_typedef
begin_comment
comment|/* */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Face_Init
argument_list|(
argument|FT_Stream      stream
argument_list|,
argument|FT_Face        face
argument_list|,
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
DECL|variable|T42_Face_Done
name|T42_Face_Done
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T42_Face_Done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_Size_Init
argument_list|(
argument|FT_Size  size
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
DECL|variable|T42_Size_Request
name|T42_Size_Request
argument_list|(
argument|FT_Size          size
argument_list|,
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
name|T42_Size_Select
argument_list|(
argument|FT_Size   size
argument_list|,
argument|FT_ULong  strike_index
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
DECL|variable|T42_Size_Done
name|T42_Size_Done
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T42_Size_Done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T42_GlyphSlot_Init
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|T42_GlyphSlot_Load
name|T42_GlyphSlot_Load
argument_list|(
argument|FT_GlyphSlot  glyph
argument_list|,
argument|FT_Size       size
argument_list|,
argument|FT_UInt       glyph_index
argument_list|,
argument|FT_Int32      load_flags
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
DECL|variable|slot
name|T42_GlyphSlot_Done
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
name|T42_Driver_Init
argument_list|(
argument|FT_Module  module
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
DECL|variable|T42_Driver_Done
name|T42_Driver_Done
argument_list|(
argument|FT_Module  module
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T42_Driver_Done
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
comment|/* __T42OBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
