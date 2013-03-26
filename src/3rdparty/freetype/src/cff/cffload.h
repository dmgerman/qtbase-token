begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  cffload.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    OpenType& CFF data/program tables loader (specification).           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2007, 2008 by                         */
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
name|__CFFLOAD_H__
end_ifndef
begin_define
DECL|macro|__CFFLOAD_H__
define|#
directive|define
name|__CFFLOAD_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
file|"cfftypes.h"
end_include
begin_include
include|#
directive|include
include|FT_SERVICE_POSTSCRIPT_CMAPS_H
end_include
begin_function_decl
name|FT_BEGIN_HEADER
name|FT_LOCAL
parameter_list|(
name|FT_UShort
parameter_list|)
function_decl|cff_get_standard_encoding
parameter_list|(
name|FT_UInt
name|charcode
parameter_list|)
function_decl|;
end_function_decl
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_String*
argument_list|)
end_macro
begin_macro
DECL|variable|cff_index_get_name
name|cff_index_get_name
argument_list|(
argument|CFF_Index  idx
argument_list|,
argument|FT_UInt    element
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_String*
argument_list|)
end_macro
begin_macro
name|cff_index_get_sid_string
argument_list|(
argument|CFF_Index          idx
argument_list|,
argument|FT_UInt            sid
argument_list|,
argument|FT_Service_PsCMaps psnames
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
name|cff_index_access_element
argument_list|(
argument|CFF_Index  idx
argument_list|,
argument|FT_UInt    element
argument_list|,
argument|FT_Byte**  pbytes
argument_list|,
argument|FT_ULong*  pbyte_len
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
DECL|variable|cff_index_forget_element
name|cff_index_forget_element
argument_list|(
argument|CFF_Index  idx
argument_list|,
argument|FT_Byte**  pbytes
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|cff_charset_cid_to_gindex
argument_list|(
argument|CFF_Charset  charset
argument_list|,
argument|FT_UInt      cid
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
DECL|variable|cff_font_load
name|cff_font_load
argument_list|(
argument|FT_Library library
argument_list|,
argument|FT_Stream  stream
argument_list|,
argument|FT_Int     face_index
argument_list|,
argument|CFF_Font   font
argument_list|,
argument|FT_Bool    pure_cff
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
DECL|variable|font
name|cff_font_done
argument_list|(
argument|CFF_Font  font
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|font
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|FT_Byte
argument_list|)
end_macro
begin_macro
name|cff_fd_select_get
argument_list|(
argument|CFF_FDSelect  fdselect
argument_list|,
argument|FT_UInt       glyph_index
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
comment|/* __CFFLOAD_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
