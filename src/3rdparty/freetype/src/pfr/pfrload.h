begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pfrload.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType PFR loader (specification).                                 */
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
name|__PFRLOAD_H__
end_ifndef
begin_define
DECL|macro|__PFRLOAD_H__
define|#
directive|define
name|__PFRLOAD_H__
end_define
begin_include
include|#
directive|include
file|"pfrobjs.h"
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_STREAM_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_ifdef
ifdef|#
directive|ifdef
name|PFR_CONFIG_NO_CHECKS
end_ifdef
begin_define
DECL|macro|PFR_CHECK
define|#
directive|define
name|PFR_CHECK
parameter_list|(
name|x
parameter_list|)
value|do { } while ( 0 )
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|PFR_CHECK
parameter_list|(
name|x
parameter_list|)
value|do                       \                         {                        \                           if ( p + (x)> limit ) \                             goto Too_Short;      \                         } while ( 0 )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|PFR_NEXT_BYTE
define|#
directive|define
name|PFR_NEXT_BYTE
parameter_list|(
name|p
parameter_list|)
value|FT_NEXT_BYTE( p )
end_define
begin_define
DECL|macro|PFR_NEXT_INT8
define|#
directive|define
name|PFR_NEXT_INT8
parameter_list|(
name|p
parameter_list|)
value|FT_NEXT_CHAR( p )
end_define
begin_define
DECL|macro|PFR_NEXT_SHORT
define|#
directive|define
name|PFR_NEXT_SHORT
parameter_list|(
name|p
parameter_list|)
value|FT_NEXT_SHORT( p )
end_define
begin_define
DECL|macro|PFR_NEXT_USHORT
define|#
directive|define
name|PFR_NEXT_USHORT
parameter_list|(
name|p
parameter_list|)
value|FT_NEXT_USHORT( p )
end_define
begin_define
DECL|macro|PFR_NEXT_LONG
define|#
directive|define
name|PFR_NEXT_LONG
parameter_list|(
name|p
parameter_list|)
value|FT_NEXT_OFF3( p )
end_define
begin_define
DECL|macro|PFR_NEXT_ULONG
define|#
directive|define
name|PFR_NEXT_ULONG
parameter_list|(
name|p
parameter_list|)
value|FT_NEXT_UOFF3( p )
end_define
begin_comment
comment|/* handling extra items */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|PFR_ExtraItem_ParseFunc
modifier|*
name|PFR_ExtraItem_ParseFunc
function_decl|)
parameter_list|(
name|FT_Byte
modifier|*
name|p
parameter_list|,
name|FT_Byte
modifier|*
name|limit
parameter_list|,
name|FT_Pointer
name|data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|PFR_ExtraItemRec_
typedef|typedef
struct|struct
name|PFR_ExtraItemRec_
block|{
DECL|member|type
name|FT_UInt
name|type
decl_stmt|;
DECL|member|parser
name|PFR_ExtraItem_ParseFunc
name|parser
decl_stmt|;
block|}
DECL|typedef|PFR_ExtraItemRec
name|PFR_ExtraItemRec
typedef|;
end_typedef
begin_typedef
DECL|typedef|PFR_ExtraItem
typedef|typedef
specifier|const
name|struct
name|PFR_ExtraItemRec_
modifier|*
name|PFR_ExtraItem
typedef|;
end_typedef
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_expr_stmt
name|pfr_extra_items_skip
argument_list|(
name|FT_Byte
operator|*
operator|*
name|pp
argument_list|,
name|FT_Byte
operator|*
name|limit
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|pfr_extra_items_parse
name|pfr_extra_items_parse
argument_list|(
argument|FT_Byte*      *pp
argument_list|,
argument|FT_Byte*       limit
argument_list|,
argument|PFR_ExtraItem  item_list
argument_list|,
argument|FT_Pointer     item_data
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* load a PFR header */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_header_load
argument_list|(
argument|PFR_Header  header
argument_list|,
argument|FT_Stream   stream
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* check a PFR header */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
DECL|variable|pfr_header_check
name|pfr_header_check
argument_list|(
argument|PFR_Header  header
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|pfr_header_check
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* return number of logical fonts in this file */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_log_font_count
argument_list|(
argument|FT_Stream   stream
argument_list|,
argument|FT_UInt32   log_section_offset
argument_list|,
argument|FT_UInt    *acount
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* load a pfr logical font entry */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|pfr_log_font_load
name|pfr_log_font_load
argument_list|(
argument|PFR_LogFont  log_font
argument_list|,
argument|FT_Stream    stream
argument_list|,
argument|FT_UInt      face_index
argument_list|,
argument|FT_UInt32    section_offset
argument_list|,
argument|FT_Bool      size_increment
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* load a physical font entry */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|pfr_phy_font_load
argument_list|(
argument|PFR_PhyFont  phy_font
argument_list|,
argument|FT_Stream    stream
argument_list|,
argument|FT_UInt32    offset
argument_list|,
argument|FT_UInt32    size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* finalize a physical font */
end_comment
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|pfr_phy_font_done
name|pfr_phy_font_done
argument_list|(
argument|PFR_PhyFont  phy_font
argument_list|,
argument|FT_Memory    memory
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
comment|/* __PFRLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
