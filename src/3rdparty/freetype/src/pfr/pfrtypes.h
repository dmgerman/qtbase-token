begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  pfrtypes.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType PFR data structures (specification only).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2015 by                                                 */
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
name|__PFRTYPES_H__
end_ifndef
begin_define
DECL|macro|__PFRTYPES_H__
define|#
directive|define
name|__PFRTYPES_H__
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
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/************************************************************************/
end_comment
begin_comment
comment|/* the PFR Header structure */
end_comment
begin_typedef
DECL|struct|PFR_HeaderRec_
typedef|typedef
struct|struct
name|PFR_HeaderRec_
block|{
DECL|member|signature
name|FT_UInt32
name|signature
decl_stmt|;
DECL|member|version
name|FT_UInt
name|version
decl_stmt|;
DECL|member|signature2
name|FT_UInt
name|signature2
decl_stmt|;
DECL|member|header_size
name|FT_UInt
name|header_size
decl_stmt|;
DECL|member|log_dir_size
name|FT_UInt
name|log_dir_size
decl_stmt|;
DECL|member|log_dir_offset
name|FT_UInt
name|log_dir_offset
decl_stmt|;
DECL|member|log_font_max_size
name|FT_UInt
name|log_font_max_size
decl_stmt|;
DECL|member|log_font_section_size
name|FT_UInt32
name|log_font_section_size
decl_stmt|;
DECL|member|log_font_section_offset
name|FT_UInt32
name|log_font_section_offset
decl_stmt|;
DECL|member|phy_font_max_size
name|FT_UInt32
name|phy_font_max_size
decl_stmt|;
DECL|member|phy_font_section_size
name|FT_UInt32
name|phy_font_section_size
decl_stmt|;
DECL|member|phy_font_section_offset
name|FT_UInt32
name|phy_font_section_offset
decl_stmt|;
DECL|member|gps_max_size
name|FT_UInt
name|gps_max_size
decl_stmt|;
DECL|member|gps_section_size
name|FT_UInt32
name|gps_section_size
decl_stmt|;
DECL|member|gps_section_offset
name|FT_UInt32
name|gps_section_offset
decl_stmt|;
DECL|member|max_blue_values
name|FT_UInt
name|max_blue_values
decl_stmt|;
DECL|member|max_x_orus
name|FT_UInt
name|max_x_orus
decl_stmt|;
DECL|member|max_y_orus
name|FT_UInt
name|max_y_orus
decl_stmt|;
DECL|member|phy_font_max_size_high
name|FT_UInt
name|phy_font_max_size_high
decl_stmt|;
DECL|member|color_flags
name|FT_UInt
name|color_flags
decl_stmt|;
DECL|member|bct_max_size
name|FT_UInt32
name|bct_max_size
decl_stmt|;
DECL|member|bct_set_max_size
name|FT_UInt32
name|bct_set_max_size
decl_stmt|;
DECL|member|phy_bct_set_max_size
name|FT_UInt32
name|phy_bct_set_max_size
decl_stmt|;
DECL|member|num_phy_fonts
name|FT_UInt
name|num_phy_fonts
decl_stmt|;
DECL|member|max_vert_stem_snap
name|FT_UInt
name|max_vert_stem_snap
decl_stmt|;
DECL|member|max_horz_stem_snap
name|FT_UInt
name|max_horz_stem_snap
decl_stmt|;
DECL|member|max_chars
name|FT_UInt
name|max_chars
decl_stmt|;
block|}
DECL|typedef|PFR_HeaderRec
DECL|typedef|PFR_Header
name|PFR_HeaderRec
operator|,
typedef|*
name|PFR_Header
typedef|;
end_typedef
begin_comment
comment|/* used in `color_flags' field of the PFR_Header */
end_comment
begin_typedef
DECL|enum|PFR_HeaderFlags_
typedef|typedef
enum|enum
name|PFR_HeaderFlags_
block|{
DECL|enumerator|PFR_FLAG_BLACK_PIXEL
name|PFR_FLAG_BLACK_PIXEL
init|=
literal|1
block|,
DECL|enumerator|PFR_FLAG_INVERT_BITMAP
name|PFR_FLAG_INVERT_BITMAP
init|=
literal|2
block|}
DECL|typedef|PFR_HeaderFlags
name|PFR_HeaderFlags
typedef|;
end_typedef
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|struct|PFR_LogFontRec_
typedef|typedef
struct|struct
name|PFR_LogFontRec_
block|{
DECL|member|size
name|FT_UInt32
name|size
decl_stmt|;
DECL|member|offset
name|FT_UInt32
name|offset
decl_stmt|;
DECL|member|matrix
name|FT_Int32
name|matrix
index|[
literal|4
index|]
decl_stmt|;
DECL|member|stroke_flags
name|FT_UInt
name|stroke_flags
decl_stmt|;
DECL|member|stroke_thickness
name|FT_Int
name|stroke_thickness
decl_stmt|;
DECL|member|bold_thickness
name|FT_Int
name|bold_thickness
decl_stmt|;
DECL|member|miter_limit
name|FT_Int32
name|miter_limit
decl_stmt|;
DECL|member|phys_size
name|FT_UInt32
name|phys_size
decl_stmt|;
DECL|member|phys_offset
name|FT_UInt32
name|phys_offset
decl_stmt|;
block|}
DECL|typedef|PFR_LogFontRec
DECL|typedef|PFR_LogFont
name|PFR_LogFontRec
operator|,
typedef|*
name|PFR_LogFont
typedef|;
end_typedef
begin_typedef
DECL|enum|PFR_LogFlags_
typedef|typedef
enum|enum
name|PFR_LogFlags_
block|{
DECL|enumerator|PFR_LOG_EXTRA_ITEMS
name|PFR_LOG_EXTRA_ITEMS
init|=
literal|0x40
block|,
DECL|enumerator|PFR_LOG_2BYTE_BOLD
name|PFR_LOG_2BYTE_BOLD
init|=
literal|0x20
block|,
DECL|enumerator|PFR_LOG_BOLD
name|PFR_LOG_BOLD
init|=
literal|0x10
block|,
DECL|enumerator|PFR_LOG_2BYTE_STROKE
name|PFR_LOG_2BYTE_STROKE
init|=
literal|8
block|,
DECL|enumerator|PFR_LOG_STROKE
name|PFR_LOG_STROKE
init|=
literal|4
block|,
DECL|enumerator|PFR_LINE_JOIN_MASK
name|PFR_LINE_JOIN_MASK
init|=
literal|3
block|}
DECL|typedef|PFR_LogFlags
name|PFR_LogFlags
typedef|;
end_typedef
begin_typedef
DECL|enum|PFR_LineJoinFlags_
typedef|typedef
enum|enum
name|PFR_LineJoinFlags_
block|{
DECL|enumerator|PFR_LINE_JOIN_MITER
name|PFR_LINE_JOIN_MITER
init|=
literal|0
block|,
DECL|enumerator|PFR_LINE_JOIN_ROUND
name|PFR_LINE_JOIN_ROUND
init|=
literal|1
block|,
DECL|enumerator|PFR_LINE_JOIN_BEVEL
name|PFR_LINE_JOIN_BEVEL
init|=
literal|2
block|}
DECL|typedef|PFR_LineJoinFlags
name|PFR_LineJoinFlags
typedef|;
end_typedef
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|enum|PFR_BitmapFlags_
typedef|typedef
enum|enum
name|PFR_BitmapFlags_
block|{
DECL|enumerator|PFR_BITMAP_3BYTE_OFFSET
name|PFR_BITMAP_3BYTE_OFFSET
init|=
literal|4
block|,
DECL|enumerator|PFR_BITMAP_2BYTE_SIZE
name|PFR_BITMAP_2BYTE_SIZE
init|=
literal|2
block|,
DECL|enumerator|PFR_BITMAP_2BYTE_CHARCODE
name|PFR_BITMAP_2BYTE_CHARCODE
init|=
literal|1
block|}
DECL|typedef|PFR_BitmapFlags
name|PFR_BitmapFlags
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_BitmapCharRec_
typedef|typedef
struct|struct
name|PFR_BitmapCharRec_
block|{
DECL|member|char_code
name|FT_UInt
name|char_code
decl_stmt|;
DECL|member|gps_size
name|FT_UInt
name|gps_size
decl_stmt|;
DECL|member|gps_offset
name|FT_UInt32
name|gps_offset
decl_stmt|;
block|}
DECL|typedef|PFR_BitmapCharRec
DECL|typedef|PFR_BitmapChar
name|PFR_BitmapCharRec
operator|,
typedef|*
name|PFR_BitmapChar
typedef|;
end_typedef
begin_typedef
DECL|enum|PFR_StrikeFlags_
typedef|typedef
enum|enum
name|PFR_StrikeFlags_
block|{
DECL|enumerator|PFR_STRIKE_2BYTE_COUNT
name|PFR_STRIKE_2BYTE_COUNT
init|=
literal|0x10
block|,
DECL|enumerator|PFR_STRIKE_3BYTE_OFFSET
name|PFR_STRIKE_3BYTE_OFFSET
init|=
literal|0x08
block|,
DECL|enumerator|PFR_STRIKE_3BYTE_SIZE
name|PFR_STRIKE_3BYTE_SIZE
init|=
literal|0x04
block|,
DECL|enumerator|PFR_STRIKE_2BYTE_YPPM
name|PFR_STRIKE_2BYTE_YPPM
init|=
literal|0x02
block|,
DECL|enumerator|PFR_STRIKE_2BYTE_XPPM
name|PFR_STRIKE_2BYTE_XPPM
init|=
literal|0x01
block|}
DECL|typedef|PFR_StrikeFlags
name|PFR_StrikeFlags
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_StrikeRec_
typedef|typedef
struct|struct
name|PFR_StrikeRec_
block|{
DECL|member|x_ppm
name|FT_UInt
name|x_ppm
decl_stmt|;
DECL|member|y_ppm
name|FT_UInt
name|y_ppm
decl_stmt|;
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
DECL|member|gps_size
name|FT_UInt32
name|gps_size
decl_stmt|;
DECL|member|gps_offset
name|FT_UInt32
name|gps_offset
decl_stmt|;
DECL|member|bct_size
name|FT_UInt32
name|bct_size
decl_stmt|;
DECL|member|bct_offset
name|FT_UInt32
name|bct_offset
decl_stmt|;
comment|/* optional */
DECL|member|num_bitmaps
name|FT_UInt
name|num_bitmaps
decl_stmt|;
DECL|member|bitmaps
name|PFR_BitmapChar
name|bitmaps
decl_stmt|;
block|}
DECL|typedef|PFR_StrikeRec
DECL|typedef|PFR_Strike
name|PFR_StrikeRec
operator|,
typedef|*
name|PFR_Strike
typedef|;
end_typedef
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|struct|PFR_CharRec_
typedef|typedef
struct|struct
name|PFR_CharRec_
block|{
DECL|member|char_code
name|FT_UInt
name|char_code
decl_stmt|;
DECL|member|advance
name|FT_Int
name|advance
decl_stmt|;
DECL|member|gps_size
name|FT_UInt
name|gps_size
decl_stmt|;
DECL|member|gps_offset
name|FT_UInt32
name|gps_offset
decl_stmt|;
block|}
DECL|typedef|PFR_CharRec
DECL|typedef|PFR_Char
name|PFR_CharRec
operator|,
typedef|*
name|PFR_Char
typedef|;
end_typedef
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|struct|PFR_DimensionRec_
typedef|typedef
struct|struct
name|PFR_DimensionRec_
block|{
DECL|member|standard
name|FT_UInt
name|standard
decl_stmt|;
DECL|member|num_stem_snaps
name|FT_UInt
name|num_stem_snaps
decl_stmt|;
DECL|member|stem_snaps
name|FT_Int
modifier|*
name|stem_snaps
decl_stmt|;
block|}
DECL|typedef|PFR_DimensionRec
DECL|typedef|PFR_Dimension
name|PFR_DimensionRec
operator|,
typedef|*
name|PFR_Dimension
typedef|;
end_typedef
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|typedef|PFR_KernItem
typedef|typedef
name|struct
name|PFR_KernItemRec_
modifier|*
name|PFR_KernItem
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_KernItemRec_
typedef|typedef
struct|struct
name|PFR_KernItemRec_
block|{
DECL|member|next
name|PFR_KernItem
name|next
decl_stmt|;
DECL|member|pair_count
name|FT_Byte
name|pair_count
decl_stmt|;
DECL|member|flags
name|FT_Byte
name|flags
decl_stmt|;
DECL|member|base_adj
name|FT_Short
name|base_adj
decl_stmt|;
DECL|member|pair_size
name|FT_UInt
name|pair_size
decl_stmt|;
DECL|member|offset
name|FT_Offset
name|offset
decl_stmt|;
DECL|member|pair1
name|FT_UInt32
name|pair1
decl_stmt|;
DECL|member|pair2
name|FT_UInt32
name|pair2
decl_stmt|;
block|}
DECL|typedef|PFR_KernItemRec
name|PFR_KernItemRec
typedef|;
end_typedef
begin_define
DECL|macro|PFR_KERN_INDEX
define|#
directive|define
name|PFR_KERN_INDEX
parameter_list|(
name|g1
parameter_list|,
name|g2
parameter_list|)
define|\
value|( ( (FT_UInt32)(g1)<< 16 ) | (FT_UInt16)(g2) )
end_define
begin_define
DECL|macro|PFR_KERN_PAIR_INDEX
define|#
directive|define
name|PFR_KERN_PAIR_INDEX
parameter_list|(
name|pair
parameter_list|)
define|\
value|PFR_KERN_INDEX( (pair)->glyph1, (pair)->glyph2 )
end_define
begin_define
DECL|macro|PFR_NEXT_KPAIR
define|#
directive|define
name|PFR_NEXT_KPAIR
parameter_list|(
name|p
parameter_list|)
value|( p += 2,                              \                                ( (FT_UInt32)p[-2]<< 16 ) | p[-1] )
end_define
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|struct|PFR_PhyFontRec_
typedef|typedef
struct|struct
name|PFR_PhyFontRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|offset
name|FT_UInt32
name|offset
decl_stmt|;
DECL|member|font_ref_number
name|FT_UInt
name|font_ref_number
decl_stmt|;
DECL|member|outline_resolution
name|FT_UInt
name|outline_resolution
decl_stmt|;
DECL|member|metrics_resolution
name|FT_UInt
name|metrics_resolution
decl_stmt|;
DECL|member|bbox
name|FT_BBox
name|bbox
decl_stmt|;
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
DECL|member|standard_advance
name|FT_Int
name|standard_advance
decl_stmt|;
DECL|member|ascent
name|FT_Int
name|ascent
decl_stmt|;
comment|/* optional, bbox.yMax if not present */
DECL|member|descent
name|FT_Int
name|descent
decl_stmt|;
comment|/* optional, bbox.yMin if not present */
DECL|member|leading
name|FT_Int
name|leading
decl_stmt|;
comment|/* optional, 0 if not present         */
DECL|member|horizontal
name|PFR_DimensionRec
name|horizontal
decl_stmt|;
DECL|member|vertical
name|PFR_DimensionRec
name|vertical
decl_stmt|;
DECL|member|font_id
name|FT_String
modifier|*
name|font_id
decl_stmt|;
DECL|member|family_name
name|FT_String
modifier|*
name|family_name
decl_stmt|;
DECL|member|style_name
name|FT_String
modifier|*
name|style_name
decl_stmt|;
DECL|member|num_strikes
name|FT_UInt
name|num_strikes
decl_stmt|;
DECL|member|max_strikes
name|FT_UInt
name|max_strikes
decl_stmt|;
DECL|member|strikes
name|PFR_StrikeRec
modifier|*
name|strikes
decl_stmt|;
DECL|member|num_blue_values
name|FT_UInt
name|num_blue_values
decl_stmt|;
DECL|member|blue_values
name|FT_Int
modifier|*
name|blue_values
decl_stmt|;
DECL|member|blue_fuzz
name|FT_UInt
name|blue_fuzz
decl_stmt|;
DECL|member|blue_scale
name|FT_UInt
name|blue_scale
decl_stmt|;
DECL|member|num_chars
name|FT_UInt
name|num_chars
decl_stmt|;
DECL|member|chars_offset
name|FT_Offset
name|chars_offset
decl_stmt|;
DECL|member|chars
name|PFR_Char
name|chars
decl_stmt|;
DECL|member|num_kern_pairs
name|FT_UInt
name|num_kern_pairs
decl_stmt|;
DECL|member|kern_items
name|PFR_KernItem
name|kern_items
decl_stmt|;
DECL|member|kern_items_tail
name|PFR_KernItem
modifier|*
name|kern_items_tail
decl_stmt|;
comment|/* not part of the spec, but used during load */
DECL|member|bct_offset
name|FT_ULong
name|bct_offset
decl_stmt|;
DECL|member|cursor
name|FT_Byte
modifier|*
name|cursor
decl_stmt|;
block|}
DECL|typedef|PFR_PhyFontRec
DECL|typedef|PFR_PhyFont
name|PFR_PhyFontRec
operator|,
typedef|*
name|PFR_PhyFont
typedef|;
end_typedef
begin_typedef
DECL|enum|PFR_PhyFlags_
typedef|typedef
enum|enum
name|PFR_PhyFlags_
block|{
DECL|enumerator|PFR_PHY_EXTRA_ITEMS
name|PFR_PHY_EXTRA_ITEMS
init|=
literal|0x80
block|,
DECL|enumerator|PFR_PHY_3BYTE_GPS_OFFSET
name|PFR_PHY_3BYTE_GPS_OFFSET
init|=
literal|0x20
block|,
DECL|enumerator|PFR_PHY_2BYTE_GPS_SIZE
name|PFR_PHY_2BYTE_GPS_SIZE
init|=
literal|0x10
block|,
DECL|enumerator|PFR_PHY_ASCII_CODE
name|PFR_PHY_ASCII_CODE
init|=
literal|0x08
block|,
DECL|enumerator|PFR_PHY_PROPORTIONAL
name|PFR_PHY_PROPORTIONAL
init|=
literal|0x04
block|,
DECL|enumerator|PFR_PHY_2BYTE_CHARCODE
name|PFR_PHY_2BYTE_CHARCODE
init|=
literal|0x02
block|,
DECL|enumerator|PFR_PHY_VERTICAL
name|PFR_PHY_VERTICAL
init|=
literal|0x01
block|}
DECL|typedef|PFR_PhyFlags
name|PFR_PhyFlags
typedef|;
end_typedef
begin_typedef
DECL|enum|PFR_KernFlags_
typedef|typedef
enum|enum
name|PFR_KernFlags_
block|{
DECL|enumerator|PFR_KERN_2BYTE_CHAR
name|PFR_KERN_2BYTE_CHAR
init|=
literal|0x01
block|,
DECL|enumerator|PFR_KERN_2BYTE_ADJ
name|PFR_KERN_2BYTE_ADJ
init|=
literal|0x02
block|}
DECL|typedef|PFR_KernFlags
name|PFR_KernFlags
typedef|;
end_typedef
begin_comment
comment|/************************************************************************/
end_comment
begin_typedef
DECL|enum|PFR_GlyphFlags_
typedef|typedef
enum|enum
name|PFR_GlyphFlags_
block|{
DECL|enumerator|PFR_GLYPH_IS_COMPOUND
name|PFR_GLYPH_IS_COMPOUND
init|=
literal|0x80
block|,
DECL|enumerator|PFR_GLYPH_EXTRA_ITEMS
name|PFR_GLYPH_EXTRA_ITEMS
init|=
literal|0x08
block|,
DECL|enumerator|PFR_GLYPH_1BYTE_XYCOUNT
name|PFR_GLYPH_1BYTE_XYCOUNT
init|=
literal|0x04
block|,
DECL|enumerator|PFR_GLYPH_XCOUNT
name|PFR_GLYPH_XCOUNT
init|=
literal|0x02
block|,
DECL|enumerator|PFR_GLYPH_YCOUNT
name|PFR_GLYPH_YCOUNT
init|=
literal|0x01
block|}
DECL|typedef|PFR_GlyphFlags
name|PFR_GlyphFlags
typedef|;
end_typedef
begin_comment
comment|/* controlled coordinate */
end_comment
begin_typedef
DECL|struct|PFR_CoordRec_
typedef|typedef
struct|struct
name|PFR_CoordRec_
block|{
DECL|member|org
name|FT_UInt
name|org
decl_stmt|;
DECL|member|cur
name|FT_UInt
name|cur
decl_stmt|;
block|}
DECL|typedef|PFR_CoordRec
DECL|typedef|PFR_Coord
name|PFR_CoordRec
operator|,
typedef|*
name|PFR_Coord
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_SubGlyphRec_
typedef|typedef
struct|struct
name|PFR_SubGlyphRec_
block|{
DECL|member|x_scale
name|FT_Fixed
name|x_scale
decl_stmt|;
DECL|member|y_scale
name|FT_Fixed
name|y_scale
decl_stmt|;
DECL|member|x_delta
name|FT_Int
name|x_delta
decl_stmt|;
DECL|member|y_delta
name|FT_Int
name|y_delta
decl_stmt|;
DECL|member|gps_offset
name|FT_UInt32
name|gps_offset
decl_stmt|;
DECL|member|gps_size
name|FT_UInt
name|gps_size
decl_stmt|;
block|}
DECL|typedef|PFR_SubGlyphRec
DECL|typedef|PFR_SubGlyph
name|PFR_SubGlyphRec
operator|,
typedef|*
name|PFR_SubGlyph
typedef|;
end_typedef
begin_typedef
DECL|enum|PFR_SubgGlyphFlags_
typedef|typedef
enum|enum
name|PFR_SubgGlyphFlags_
block|{
DECL|enumerator|PFR_SUBGLYPH_3BYTE_OFFSET
name|PFR_SUBGLYPH_3BYTE_OFFSET
init|=
literal|0x80
block|,
DECL|enumerator|PFR_SUBGLYPH_2BYTE_SIZE
name|PFR_SUBGLYPH_2BYTE_SIZE
init|=
literal|0x40
block|,
DECL|enumerator|PFR_SUBGLYPH_YSCALE
name|PFR_SUBGLYPH_YSCALE
init|=
literal|0x20
block|,
DECL|enumerator|PFR_SUBGLYPH_XSCALE
name|PFR_SUBGLYPH_XSCALE
init|=
literal|0x10
block|}
DECL|typedef|PFR_SubGlyphFlags
name|PFR_SubGlyphFlags
typedef|;
end_typedef
begin_typedef
DECL|struct|PFR_GlyphRec_
typedef|typedef
struct|struct
name|PFR_GlyphRec_
block|{
DECL|member|format
name|FT_Byte
name|format
decl_stmt|;
if|#
directive|if
literal|0
block|FT_UInt           num_x_control;     FT_UInt           num_y_control;
endif|#
directive|endif
DECL|member|max_xy_control
name|FT_UInt
name|max_xy_control
decl_stmt|;
DECL|member|x_control
name|FT_Pos
modifier|*
name|x_control
decl_stmt|;
DECL|member|y_control
name|FT_Pos
modifier|*
name|y_control
decl_stmt|;
DECL|member|num_subs
name|FT_UInt
name|num_subs
decl_stmt|;
DECL|member|max_subs
name|FT_UInt
name|max_subs
decl_stmt|;
DECL|member|subs
name|PFR_SubGlyphRec
modifier|*
name|subs
decl_stmt|;
DECL|member|loader
name|FT_GlyphLoader
name|loader
decl_stmt|;
DECL|member|path_begun
name|FT_Bool
name|path_begun
decl_stmt|;
block|}
DECL|typedef|PFR_GlyphRec
DECL|typedef|PFR_Glyph
name|PFR_GlyphRec
operator|,
typedef|*
name|PFR_Glyph
typedef|;
end_typedef
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PFRTYPES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
