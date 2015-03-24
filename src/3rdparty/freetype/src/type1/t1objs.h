begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1objs.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Type 1 objects manager (specification).                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2006, 2011 by                               */
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
name|__T1OBJS_H__
end_ifndef
begin_define
DECL|macro|__T1OBJS_H__
define|#
directive|define
name|__T1OBJS_H__
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
DECL|typedef|T1_Size_Hints
typedef|typedef
name|struct
name|T1_Size_Hints_
name|T1_Size_Hints
typedef|;
end_typedef
begin_typedef
DECL|typedef|T1_Glyph_Hints
typedef|typedef
name|struct
name|T1_Glyph_Hints_
name|T1_Glyph_Hints
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
comment|/*    T1_Size                                                            */
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
DECL|typedef|T1_Size
typedef|typedef
name|struct
name|T1_SizeRec_
modifier|*
name|T1_Size
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
comment|/*    T1_GlyphSlot                                                       */
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
DECL|typedef|T1_GlyphSlot
typedef|typedef
name|struct
name|T1_GlyphSlotRec_
modifier|*
name|T1_GlyphSlot
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
comment|/*    T1_CharMap                                                         */
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
DECL|typedef|T1_CharMap
typedef|typedef
name|struct
name|T1_CharMapRec_
modifier|*
name|T1_CharMap
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                  HERE BEGINS THE TYPE1 SPECIFIC STUFF                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
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
comment|/*    T1_SizeRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Type 1 size record.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|T1_SizeRec_
typedef|typedef
struct|struct
name|T1_SizeRec_
block|{
DECL|member|root
name|FT_SizeRec
name|root
decl_stmt|;
block|}
DECL|typedef|T1_SizeRec
name|T1_SizeRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|size
name|T1_Size_Done
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|size
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_Size_Request
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
DECL|variable|T1_Size_Init
name|T1_Size_Init
argument_list|(
argument|FT_Size  size
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T1_Size_Init
empty_stmt|;
end_empty_stmt
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
comment|/*    T1_GlyphSlotRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Type 1 glyph slot record.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|T1_GlyphSlotRec_
typedef|typedef
struct|struct
name|T1_GlyphSlotRec_
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
DECL|member|max_points
name|FT_Int
name|max_points
decl_stmt|;
DECL|member|max_contours
name|FT_Int
name|max_contours
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
DECL|typedef|T1_GlyphSlotRec
name|T1_GlyphSlotRec
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_Face_Init
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
DECL|variable|T1_Face_Done
name|T1_Face_Done
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T1_Face_Done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_GlyphSlot_Init
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
DECL|variable|T1_GlyphSlot_Done
name|T1_GlyphSlot_Done
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T1_GlyphSlot_Done
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|T1_Driver_Init
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
DECL|variable|T1_Driver_Done
name|T1_Driver_Done
argument_list|(
argument|FT_Module  driver
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|T1_Driver_Done
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
comment|/* __T1OBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
