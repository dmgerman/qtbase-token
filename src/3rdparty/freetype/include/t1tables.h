begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  t1tables.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Basic Type 1/Type 2 tables definitions and interface (specification  */
end_comment
begin_comment
comment|/*    only).                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2004, 2006, 2008, 2009, 2011, 2014 by                   */
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
name|__T1TABLES_H__
end_ifndef
begin_define
DECL|macro|__T1TABLES_H__
define|#
directive|define
name|__T1TABLES_H__
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
begin_ifdef
ifdef|#
directive|ifdef
name|FREETYPE_H
end_ifdef
begin_error
error|#
directive|error
literal|"freetype.h of FreeType 1 has been loaded!"
end_error
begin_error
error|#
directive|error
literal|"Please fix the directory search order for header files"
end_error
begin_error
error|#
directive|error
literal|"so that freetype.h of FreeType 2 is found first."
end_error
begin_endif
endif|#
directive|endif
end_endif
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    type1_tables                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Type 1 Tables                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Type~1 (PostScript) specific font tables.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains the definition of Type 1-specific tables,    */
end_comment
begin_comment
comment|/*    including structures related to other PostScript font formats.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Order>                                                               */
end_comment
begin_comment
comment|/*    PS_FontInfoRec                                                     */
end_comment
begin_comment
comment|/*    PS_FontInfo                                                        */
end_comment
begin_comment
comment|/*    PS_PrivateRec                                                      */
end_comment
begin_comment
comment|/*    PS_Private                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    CID_FaceDictRec                                                    */
end_comment
begin_comment
comment|/*    CID_FaceDict                                                       */
end_comment
begin_comment
comment|/*    CID_FaceInfoRec                                                    */
end_comment
begin_comment
comment|/*    CID_FaceInfo                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Has_PS_Glyph_Names                                              */
end_comment
begin_comment
comment|/*    FT_Get_PS_Font_Info                                                */
end_comment
begin_comment
comment|/*    FT_Get_PS_Font_Private                                             */
end_comment
begin_comment
comment|/*    FT_Get_PS_Font_Value                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    T1_Blend_Flags                                                     */
end_comment
begin_comment
comment|/*    T1_EncodingType                                                    */
end_comment
begin_comment
comment|/*    PS_Dict_Keys                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* Note that we separate font data in PS_FontInfoRec and PS_PrivateRec */
end_comment
begin_comment
comment|/* structures in order to support Multiple Master fonts.               */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    PS_FontInfoRec                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a Type~1 or Type~2 FontInfo dictionary.  */
end_comment
begin_comment
comment|/*    Note that for Multiple Master fonts, each instance has its own     */
end_comment
begin_comment
comment|/*    FontInfo dictionary.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|PS_FontInfoRec_
typedef|typedef
struct|struct
name|PS_FontInfoRec_
block|{
DECL|member|version
name|FT_String
modifier|*
name|version
decl_stmt|;
DECL|member|notice
name|FT_String
modifier|*
name|notice
decl_stmt|;
DECL|member|full_name
name|FT_String
modifier|*
name|full_name
decl_stmt|;
DECL|member|family_name
name|FT_String
modifier|*
name|family_name
decl_stmt|;
DECL|member|weight
name|FT_String
modifier|*
name|weight
decl_stmt|;
DECL|member|italic_angle
name|FT_Long
name|italic_angle
decl_stmt|;
DECL|member|is_fixed_pitch
name|FT_Bool
name|is_fixed_pitch
decl_stmt|;
DECL|member|underline_position
name|FT_Short
name|underline_position
decl_stmt|;
DECL|member|underline_thickness
name|FT_UShort
name|underline_thickness
decl_stmt|;
block|}
DECL|typedef|PS_FontInfoRec
name|PS_FontInfoRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    PS_FontInfo                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a @PS_FontInfoRec structure.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|PS_FontInfo
typedef|typedef
name|struct
name|PS_FontInfoRec_
modifier|*
name|PS_FontInfo
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    T1_FontInfo                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This type is equivalent to @PS_FontInfoRec.  It is deprecated but  */
end_comment
begin_comment
comment|/*    kept to maintain source compatibility between various versions of  */
end_comment
begin_comment
comment|/*    FreeType.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|T1_FontInfo
typedef|typedef
name|PS_FontInfoRec
name|T1_FontInfo
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    PS_PrivateRec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a Type~1 or Type~2 private dictionary.   */
end_comment
begin_comment
comment|/*    Note that for Multiple Master fonts, each instance has its own     */
end_comment
begin_comment
comment|/*    Private dictionary.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|PS_PrivateRec_
typedef|typedef
struct|struct
name|PS_PrivateRec_
block|{
DECL|member|unique_id
name|FT_Int
name|unique_id
decl_stmt|;
DECL|member|lenIV
name|FT_Int
name|lenIV
decl_stmt|;
DECL|member|num_blue_values
name|FT_Byte
name|num_blue_values
decl_stmt|;
DECL|member|num_other_blues
name|FT_Byte
name|num_other_blues
decl_stmt|;
DECL|member|num_family_blues
name|FT_Byte
name|num_family_blues
decl_stmt|;
DECL|member|num_family_other_blues
name|FT_Byte
name|num_family_other_blues
decl_stmt|;
DECL|member|blue_values
name|FT_Short
name|blue_values
index|[
literal|14
index|]
decl_stmt|;
DECL|member|other_blues
name|FT_Short
name|other_blues
index|[
literal|10
index|]
decl_stmt|;
DECL|member|family_blues
name|FT_Short
name|family_blues
index|[
literal|14
index|]
decl_stmt|;
DECL|member|family_other_blues
name|FT_Short
name|family_other_blues
index|[
literal|10
index|]
decl_stmt|;
DECL|member|blue_scale
name|FT_Fixed
name|blue_scale
decl_stmt|;
DECL|member|blue_shift
name|FT_Int
name|blue_shift
decl_stmt|;
DECL|member|blue_fuzz
name|FT_Int
name|blue_fuzz
decl_stmt|;
DECL|member|standard_width
name|FT_UShort
name|standard_width
index|[
literal|1
index|]
decl_stmt|;
DECL|member|standard_height
name|FT_UShort
name|standard_height
index|[
literal|1
index|]
decl_stmt|;
DECL|member|num_snap_widths
name|FT_Byte
name|num_snap_widths
decl_stmt|;
DECL|member|num_snap_heights
name|FT_Byte
name|num_snap_heights
decl_stmt|;
DECL|member|force_bold
name|FT_Bool
name|force_bold
decl_stmt|;
DECL|member|round_stem_up
name|FT_Bool
name|round_stem_up
decl_stmt|;
DECL|member|snap_widths
name|FT_Short
name|snap_widths
index|[
literal|13
index|]
decl_stmt|;
comment|/* including std width  */
DECL|member|snap_heights
name|FT_Short
name|snap_heights
index|[
literal|13
index|]
decl_stmt|;
comment|/* including std height */
DECL|member|expansion_factor
name|FT_Fixed
name|expansion_factor
decl_stmt|;
DECL|member|language_group
name|FT_Long
name|language_group
decl_stmt|;
DECL|member|password
name|FT_Long
name|password
decl_stmt|;
DECL|member|min_feature
name|FT_Short
name|min_feature
index|[
literal|2
index|]
decl_stmt|;
block|}
DECL|typedef|PS_PrivateRec
name|PS_PrivateRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    PS_Private                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a @PS_PrivateRec structure.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|PS_Private
typedef|typedef
name|struct
name|PS_PrivateRec_
modifier|*
name|PS_Private
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    T1_Private                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*   This type is equivalent to @PS_PrivateRec.  It is deprecated but    */
end_comment
begin_comment
comment|/*   kept to maintain source compatibility between various versions of   */
end_comment
begin_comment
comment|/*   FreeType.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|T1_Private
typedef|typedef
name|PS_PrivateRec
name|T1_Private
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    T1_Blend_Flags                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A set of flags used to indicate which fields are present in a      */
end_comment
begin_comment
comment|/*    given blend dictionary (font info or private).  Used to support    */
end_comment
begin_comment
comment|/*    Multiple Masters fonts.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    T1_BLEND_UNDERLINE_POSITION ::                                     */
end_comment
begin_comment
comment|/*    T1_BLEND_UNDERLINE_THICKNESS ::                                    */
end_comment
begin_comment
comment|/*    T1_BLEND_ITALIC_ANGLE ::                                           */
end_comment
begin_comment
comment|/*    T1_BLEND_BLUE_VALUES ::                                            */
end_comment
begin_comment
comment|/*    T1_BLEND_OTHER_BLUES ::                                            */
end_comment
begin_comment
comment|/*    T1_BLEND_STANDARD_WIDTH ::                                         */
end_comment
begin_comment
comment|/*    T1_BLEND_STANDARD_HEIGHT ::                                        */
end_comment
begin_comment
comment|/*    T1_BLEND_STEM_SNAP_WIDTHS ::                                       */
end_comment
begin_comment
comment|/*    T1_BLEND_STEM_SNAP_HEIGHTS ::                                      */
end_comment
begin_comment
comment|/*    T1_BLEND_BLUE_SCALE ::                                             */
end_comment
begin_comment
comment|/*    T1_BLEND_BLUE_SHIFT ::                                             */
end_comment
begin_comment
comment|/*    T1_BLEND_FAMILY_BLUES ::                                           */
end_comment
begin_comment
comment|/*    T1_BLEND_FAMILY_OTHER_BLUES ::                                     */
end_comment
begin_comment
comment|/*    T1_BLEND_FORCE_BOLD ::                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|T1_Blend_Flags_
typedef|typedef
enum|enum
name|T1_Blend_Flags_
block|{
comment|/* required fields in a FontInfo blend dictionary */
DECL|enumerator|T1_BLEND_UNDERLINE_POSITION
name|T1_BLEND_UNDERLINE_POSITION
init|=
literal|0
block|,
DECL|enumerator|T1_BLEND_UNDERLINE_THICKNESS
name|T1_BLEND_UNDERLINE_THICKNESS
block|,
DECL|enumerator|T1_BLEND_ITALIC_ANGLE
name|T1_BLEND_ITALIC_ANGLE
block|,
comment|/* required fields in a Private blend dictionary */
DECL|enumerator|T1_BLEND_BLUE_VALUES
name|T1_BLEND_BLUE_VALUES
block|,
DECL|enumerator|T1_BLEND_OTHER_BLUES
name|T1_BLEND_OTHER_BLUES
block|,
DECL|enumerator|T1_BLEND_STANDARD_WIDTH
name|T1_BLEND_STANDARD_WIDTH
block|,
DECL|enumerator|T1_BLEND_STANDARD_HEIGHT
name|T1_BLEND_STANDARD_HEIGHT
block|,
DECL|enumerator|T1_BLEND_STEM_SNAP_WIDTHS
name|T1_BLEND_STEM_SNAP_WIDTHS
block|,
DECL|enumerator|T1_BLEND_STEM_SNAP_HEIGHTS
name|T1_BLEND_STEM_SNAP_HEIGHTS
block|,
DECL|enumerator|T1_BLEND_BLUE_SCALE
name|T1_BLEND_BLUE_SCALE
block|,
DECL|enumerator|T1_BLEND_BLUE_SHIFT
name|T1_BLEND_BLUE_SHIFT
block|,
DECL|enumerator|T1_BLEND_FAMILY_BLUES
name|T1_BLEND_FAMILY_BLUES
block|,
DECL|enumerator|T1_BLEND_FAMILY_OTHER_BLUES
name|T1_BLEND_FAMILY_OTHER_BLUES
block|,
DECL|enumerator|T1_BLEND_FORCE_BOLD
name|T1_BLEND_FORCE_BOLD
block|,
DECL|enumerator|T1_BLEND_MAX
name|T1_BLEND_MAX
comment|/* do not remove */
block|}
DECL|typedef|T1_Blend_Flags
name|T1_Blend_Flags
typedef|;
end_typedef
begin_comment
comment|/* these constants are deprecated; use the corresponding */
end_comment
begin_comment
comment|/* `T1_Blend_Flags' values instead                       */
end_comment
begin_define
DECL|macro|t1_blend_underline_position
define|#
directive|define
name|t1_blend_underline_position
value|T1_BLEND_UNDERLINE_POSITION
end_define
begin_define
DECL|macro|t1_blend_underline_thickness
define|#
directive|define
name|t1_blend_underline_thickness
value|T1_BLEND_UNDERLINE_THICKNESS
end_define
begin_define
DECL|macro|t1_blend_italic_angle
define|#
directive|define
name|t1_blend_italic_angle
value|T1_BLEND_ITALIC_ANGLE
end_define
begin_define
DECL|macro|t1_blend_blue_values
define|#
directive|define
name|t1_blend_blue_values
value|T1_BLEND_BLUE_VALUES
end_define
begin_define
DECL|macro|t1_blend_other_blues
define|#
directive|define
name|t1_blend_other_blues
value|T1_BLEND_OTHER_BLUES
end_define
begin_define
DECL|macro|t1_blend_standard_widths
define|#
directive|define
name|t1_blend_standard_widths
value|T1_BLEND_STANDARD_WIDTH
end_define
begin_define
DECL|macro|t1_blend_standard_height
define|#
directive|define
name|t1_blend_standard_height
value|T1_BLEND_STANDARD_HEIGHT
end_define
begin_define
DECL|macro|t1_blend_stem_snap_widths
define|#
directive|define
name|t1_blend_stem_snap_widths
value|T1_BLEND_STEM_SNAP_WIDTHS
end_define
begin_define
DECL|macro|t1_blend_stem_snap_heights
define|#
directive|define
name|t1_blend_stem_snap_heights
value|T1_BLEND_STEM_SNAP_HEIGHTS
end_define
begin_define
DECL|macro|t1_blend_blue_scale
define|#
directive|define
name|t1_blend_blue_scale
value|T1_BLEND_BLUE_SCALE
end_define
begin_define
DECL|macro|t1_blend_blue_shift
define|#
directive|define
name|t1_blend_blue_shift
value|T1_BLEND_BLUE_SHIFT
end_define
begin_define
DECL|macro|t1_blend_family_blues
define|#
directive|define
name|t1_blend_family_blues
value|T1_BLEND_FAMILY_BLUES
end_define
begin_define
DECL|macro|t1_blend_family_other_blues
define|#
directive|define
name|t1_blend_family_other_blues
value|T1_BLEND_FAMILY_OTHER_BLUES
end_define
begin_define
DECL|macro|t1_blend_force_bold
define|#
directive|define
name|t1_blend_force_bold
value|T1_BLEND_FORCE_BOLD
end_define
begin_define
DECL|macro|t1_blend_max
define|#
directive|define
name|t1_blend_max
value|T1_BLEND_MAX
end_define
begin_comment
comment|/* */
end_comment
begin_comment
comment|/* maximum number of Multiple Masters designs, as defined in the spec */
end_comment
begin_define
DECL|macro|T1_MAX_MM_DESIGNS
define|#
directive|define
name|T1_MAX_MM_DESIGNS
value|16
end_define
begin_comment
comment|/* maximum number of Multiple Masters axes, as defined in the spec */
end_comment
begin_define
DECL|macro|T1_MAX_MM_AXIS
define|#
directive|define
name|T1_MAX_MM_AXIS
value|4
end_define
begin_comment
comment|/* maximum number of elements in a design map */
end_comment
begin_define
DECL|macro|T1_MAX_MM_MAP_POINTS
define|#
directive|define
name|T1_MAX_MM_MAP_POINTS
value|20
end_define
begin_comment
comment|/* this structure is used to store the BlendDesignMap entry for an axis */
end_comment
begin_typedef
DECL|struct|PS_DesignMap_
typedef|typedef
struct|struct
name|PS_DesignMap_
block|{
DECL|member|num_points
name|FT_Byte
name|num_points
decl_stmt|;
DECL|member|design_points
name|FT_Long
modifier|*
name|design_points
decl_stmt|;
DECL|member|blend_points
name|FT_Fixed
modifier|*
name|blend_points
decl_stmt|;
block|}
DECL|typedef|PS_DesignMapRec
DECL|typedef|PS_DesignMap
name|PS_DesignMapRec
operator|,
typedef|*
name|PS_DesignMap
typedef|;
end_typedef
begin_comment
comment|/* backwards-compatible definition */
end_comment
begin_typedef
DECL|typedef|T1_DesignMap
typedef|typedef
name|PS_DesignMapRec
name|T1_DesignMap
typedef|;
end_typedef
begin_typedef
DECL|struct|PS_BlendRec_
typedef|typedef
struct|struct
name|PS_BlendRec_
block|{
DECL|member|num_designs
name|FT_UInt
name|num_designs
decl_stmt|;
DECL|member|num_axis
name|FT_UInt
name|num_axis
decl_stmt|;
DECL|member|axis_names
name|FT_String
modifier|*
name|axis_names
index|[
name|T1_MAX_MM_AXIS
index|]
decl_stmt|;
DECL|member|design_pos
name|FT_Fixed
modifier|*
name|design_pos
index|[
name|T1_MAX_MM_DESIGNS
index|]
decl_stmt|;
DECL|member|design_map
name|PS_DesignMapRec
name|design_map
index|[
name|T1_MAX_MM_AXIS
index|]
decl_stmt|;
DECL|member|weight_vector
name|FT_Fixed
modifier|*
name|weight_vector
decl_stmt|;
DECL|member|default_weight_vector
name|FT_Fixed
modifier|*
name|default_weight_vector
decl_stmt|;
DECL|member|font_infos
name|PS_FontInfo
name|font_infos
index|[
name|T1_MAX_MM_DESIGNS
operator|+
literal|1
index|]
decl_stmt|;
DECL|member|privates
name|PS_Private
name|privates
index|[
name|T1_MAX_MM_DESIGNS
operator|+
literal|1
index|]
decl_stmt|;
DECL|member|blend_bitflags
name|FT_ULong
name|blend_bitflags
decl_stmt|;
DECL|member|bboxes
name|FT_BBox
modifier|*
name|bboxes
index|[
name|T1_MAX_MM_DESIGNS
operator|+
literal|1
index|]
decl_stmt|;
comment|/* since 2.3.0 */
comment|/* undocumented, optional: the default design instance;   */
comment|/* corresponds to default_weight_vector --                */
comment|/* num_default_design_vector == 0 means it is not present */
comment|/* in the font and associated metrics files               */
DECL|member|default_design_vector
name|FT_UInt
name|default_design_vector
index|[
name|T1_MAX_MM_DESIGNS
index|]
decl_stmt|;
DECL|member|num_default_design_vector
name|FT_UInt
name|num_default_design_vector
decl_stmt|;
block|}
DECL|typedef|PS_BlendRec
DECL|typedef|PS_Blend
name|PS_BlendRec
operator|,
typedef|*
name|PS_Blend
typedef|;
end_typedef
begin_comment
comment|/* backwards-compatible definition */
end_comment
begin_typedef
DECL|typedef|T1_Blend
typedef|typedef
name|PS_BlendRec
name|T1_Blend
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    CID_FaceDictRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to represent data in a CID top-level dictionary.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CID_FaceDictRec_
typedef|typedef
struct|struct
name|CID_FaceDictRec_
block|{
DECL|member|private_dict
name|PS_PrivateRec
name|private_dict
decl_stmt|;
DECL|member|len_buildchar
name|FT_UInt
name|len_buildchar
decl_stmt|;
DECL|member|forcebold_threshold
name|FT_Fixed
name|forcebold_threshold
decl_stmt|;
DECL|member|stroke_width
name|FT_Pos
name|stroke_width
decl_stmt|;
DECL|member|expansion_factor
name|FT_Fixed
name|expansion_factor
decl_stmt|;
DECL|member|paint_type
name|FT_Byte
name|paint_type
decl_stmt|;
DECL|member|font_type
name|FT_Byte
name|font_type
decl_stmt|;
DECL|member|font_matrix
name|FT_Matrix
name|font_matrix
decl_stmt|;
DECL|member|font_offset
name|FT_Vector
name|font_offset
decl_stmt|;
DECL|member|num_subrs
name|FT_UInt
name|num_subrs
decl_stmt|;
DECL|member|subrmap_offset
name|FT_ULong
name|subrmap_offset
decl_stmt|;
DECL|member|sd_bytes
name|FT_Int
name|sd_bytes
decl_stmt|;
block|}
DECL|typedef|CID_FaceDictRec
name|CID_FaceDictRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    CID_FaceDict                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a @CID_FaceDictRec structure.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_FaceDict
typedef|typedef
name|struct
name|CID_FaceDictRec_
modifier|*
name|CID_FaceDict
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    CID_FontDict                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This type is equivalent to @CID_FaceDictRec.  It is deprecated but */
end_comment
begin_comment
comment|/*    kept to maintain source compatibility between various versions of  */
end_comment
begin_comment
comment|/*    FreeType.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_FontDict
typedef|typedef
name|CID_FaceDictRec
name|CID_FontDict
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    CID_FaceInfoRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to represent CID Face information.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|CID_FaceInfoRec_
typedef|typedef
struct|struct
name|CID_FaceInfoRec_
block|{
DECL|member|cid_font_name
name|FT_String
modifier|*
name|cid_font_name
decl_stmt|;
DECL|member|cid_version
name|FT_Fixed
name|cid_version
decl_stmt|;
DECL|member|cid_font_type
name|FT_Int
name|cid_font_type
decl_stmt|;
DECL|member|registry
name|FT_String
modifier|*
name|registry
decl_stmt|;
DECL|member|ordering
name|FT_String
modifier|*
name|ordering
decl_stmt|;
DECL|member|supplement
name|FT_Int
name|supplement
decl_stmt|;
DECL|member|font_info
name|PS_FontInfoRec
name|font_info
decl_stmt|;
DECL|member|font_bbox
name|FT_BBox
name|font_bbox
decl_stmt|;
DECL|member|uid_base
name|FT_ULong
name|uid_base
decl_stmt|;
DECL|member|num_xuid
name|FT_Int
name|num_xuid
decl_stmt|;
DECL|member|xuid
name|FT_ULong
name|xuid
index|[
literal|16
index|]
decl_stmt|;
DECL|member|cidmap_offset
name|FT_ULong
name|cidmap_offset
decl_stmt|;
DECL|member|fd_bytes
name|FT_Int
name|fd_bytes
decl_stmt|;
DECL|member|gd_bytes
name|FT_Int
name|gd_bytes
decl_stmt|;
DECL|member|cid_count
name|FT_ULong
name|cid_count
decl_stmt|;
DECL|member|num_dicts
name|FT_Int
name|num_dicts
decl_stmt|;
DECL|member|font_dicts
name|CID_FaceDict
name|font_dicts
decl_stmt|;
DECL|member|data_offset
name|FT_ULong
name|data_offset
decl_stmt|;
block|}
DECL|typedef|CID_FaceInfoRec
name|CID_FaceInfoRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    CID_FaceInfo                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a @CID_FaceInfoRec structure.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_FaceInfo
typedef|typedef
name|struct
name|CID_FaceInfoRec_
modifier|*
name|CID_FaceInfo
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    CID_Info                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*   This type is equivalent to @CID_FaceInfoRec.  It is deprecated but  */
end_comment
begin_comment
comment|/*   kept to maintain source compatibility between various versions of   */
end_comment
begin_comment
comment|/*   FreeType.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|CID_Info
typedef|typedef
name|CID_FaceInfoRec
name|CID_Info
typedef|;
end_typedef
begin_comment
comment|/************************************************************************    *    * @function:    *    FT_Has_PS_Glyph_Names    *    * @description:    *    Return true if a given face provides reliable PostScript glyph    *    names.  This is similar to using the @FT_HAS_GLYPH_NAMES macro,    *    except that certain fonts (mostly TrueType) contain incorrect    *    glyph name tables.    *    *    When this function returns true, the caller is sure that the glyph    *    names returned by @FT_Get_Glyph_Name are reliable.    *    * @input:    *    face ::    *       face handle    *    * @return:    *    Boolean.  True if glyph names are reliable.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|FT_Has_PS_Glyph_Names
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/************************************************************************    *    * @function:    *    FT_Get_PS_Font_Info    *    * @description:    *    Retrieve the @PS_FontInfoRec structure corresponding to a given    *    PostScript font.    *    * @input:    *    face ::    *       PostScript face handle.    *    * @output:    *    afont_info ::    *       Output font info structure pointer.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *    The string pointers within the font info structure are owned by    *    the face and don't need to be freed by the caller.    *    *    If the font's format is not PostScript-based, this function will    *    return the `FT_Err_Invalid_Argument' error code.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_PS_Font_Info
name|FT_Get_PS_Font_Info
argument_list|(
argument|FT_Face      face
argument_list|,
argument|PS_FontInfo  afont_info
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/************************************************************************    *    * @function:    *    FT_Get_PS_Font_Private    *    * @description:    *    Retrieve the @PS_PrivateRec structure corresponding to a given    *    PostScript font.    *    * @input:    *    face ::    *       PostScript face handle.    *    * @output:    *    afont_private ::    *       Output private dictionary structure pointer.    *    * @return:    *    FreeType error code.  0~means success.    *    * @note:    *    The string pointers within the @PS_PrivateRec structure are owned by    *    the face and don't need to be freed by the caller.    *    *    If the font's format is not PostScript-based, this function returns    *    the `FT_Err_Invalid_Argument' error code.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_PS_Font_Private
argument_list|(
argument|FT_Face     face
argument_list|,
argument|PS_Private  afont_private
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
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    T1_EncodingType                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration describing the `Encoding' entry in a Type 1         */
end_comment
begin_comment
comment|/*    dictionary.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    T1_ENCODING_TYPE_NONE ::                                           */
end_comment
begin_comment
comment|/*    T1_ENCODING_TYPE_ARRAY ::                                          */
end_comment
begin_comment
comment|/*    T1_ENCODING_TYPE_STANDARD ::                                       */
end_comment
begin_comment
comment|/*    T1_ENCODING_TYPE_ISOLATIN1 ::                                      */
end_comment
begin_comment
comment|/*    T1_ENCODING_TYPE_EXPERT ::                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|T1_EncodingType_
typedef|typedef
enum|enum
name|T1_EncodingType_
block|{
DECL|enumerator|T1_ENCODING_TYPE_NONE
name|T1_ENCODING_TYPE_NONE
init|=
literal|0
block|,
DECL|enumerator|T1_ENCODING_TYPE_ARRAY
name|T1_ENCODING_TYPE_ARRAY
block|,
DECL|enumerator|T1_ENCODING_TYPE_STANDARD
name|T1_ENCODING_TYPE_STANDARD
block|,
DECL|enumerator|T1_ENCODING_TYPE_ISOLATIN1
name|T1_ENCODING_TYPE_ISOLATIN1
block|,
DECL|enumerator|T1_ENCODING_TYPE_EXPERT
name|T1_ENCODING_TYPE_EXPERT
block|}
DECL|typedef|T1_EncodingType
name|T1_EncodingType
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Enum>                                                                */
end_comment
begin_comment
comment|/*    PS_Dict_Keys                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration used in calls to @FT_Get_PS_Font_Value to identify  */
end_comment
begin_comment
comment|/*    the Type~1 dictionary entry to retrieve.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    PS_DICT_FONT_TYPE ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_FONT_MATRIX ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_FONT_BBOX ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_PAINT_TYPE ::                                              */
end_comment
begin_comment
comment|/*    PS_DICT_FONT_NAME ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_UNIQUE_ID ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_CHAR_STRINGS ::                                        */
end_comment
begin_comment
comment|/*    PS_DICT_CHAR_STRING_KEY ::                                         */
end_comment
begin_comment
comment|/*    PS_DICT_CHAR_STRING ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_ENCODING_TYPE ::                                           */
end_comment
begin_comment
comment|/*    PS_DICT_ENCODING_ENTRY ::                                          */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_SUBRS ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_SUBR ::                                                    */
end_comment
begin_comment
comment|/*    PS_DICT_STD_HW ::                                                  */
end_comment
begin_comment
comment|/*    PS_DICT_STD_VW ::                                                  */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_BLUE_VALUES ::                                         */
end_comment
begin_comment
comment|/*    PS_DICT_BLUE_VALUE ::                                              */
end_comment
begin_comment
comment|/*    PS_DICT_BLUE_FUZZ ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_OTHER_BLUES ::                                         */
end_comment
begin_comment
comment|/*    PS_DICT_OTHER_BLUE ::                                              */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_FAMILY_BLUES ::                                        */
end_comment
begin_comment
comment|/*    PS_DICT_FAMILY_BLUE ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_FAMILY_OTHER_BLUES ::                                  */
end_comment
begin_comment
comment|/*    PS_DICT_FAMILY_OTHER_BLUE ::                                       */
end_comment
begin_comment
comment|/*    PS_DICT_BLUE_SCALE ::                                              */
end_comment
begin_comment
comment|/*    PS_DICT_BLUE_SHIFT ::                                              */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_STEM_SNAP_H ::                                         */
end_comment
begin_comment
comment|/*    PS_DICT_STEM_SNAP_H ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_NUM_STEM_SNAP_V ::                                         */
end_comment
begin_comment
comment|/*    PS_DICT_STEM_SNAP_V ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_FORCE_BOLD ::                                              */
end_comment
begin_comment
comment|/*    PS_DICT_RND_STEM_UP ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_MIN_FEATURE ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_LEN_IV ::                                                  */
end_comment
begin_comment
comment|/*    PS_DICT_PASSWORD ::                                                */
end_comment
begin_comment
comment|/*    PS_DICT_LANGUAGE_GROUP ::                                          */
end_comment
begin_comment
comment|/*    PS_DICT_VERSION ::                                                 */
end_comment
begin_comment
comment|/*    PS_DICT_NOTICE ::                                                  */
end_comment
begin_comment
comment|/*    PS_DICT_FULL_NAME ::                                               */
end_comment
begin_comment
comment|/*    PS_DICT_FAMILY_NAME ::                                             */
end_comment
begin_comment
comment|/*    PS_DICT_WEIGHT ::                                                  */
end_comment
begin_comment
comment|/*    PS_DICT_IS_FIXED_PITCH ::                                          */
end_comment
begin_comment
comment|/*    PS_DICT_UNDERLINE_POSITION ::                                      */
end_comment
begin_comment
comment|/*    PS_DICT_UNDERLINE_THICKNESS ::                                     */
end_comment
begin_comment
comment|/*    PS_DICT_FS_TYPE ::                                                 */
end_comment
begin_comment
comment|/*    PS_DICT_ITALIC_ANGLE ::                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|PS_Dict_Keys_
typedef|typedef
enum|enum
name|PS_Dict_Keys_
block|{
comment|/* conventionally in the font dictionary */
DECL|enumerator|PS_DICT_FONT_TYPE
name|PS_DICT_FONT_TYPE
block|,
comment|/* FT_Byte         */
DECL|enumerator|PS_DICT_FONT_MATRIX
name|PS_DICT_FONT_MATRIX
block|,
comment|/* FT_Fixed        */
DECL|enumerator|PS_DICT_FONT_BBOX
name|PS_DICT_FONT_BBOX
block|,
comment|/* FT_Fixed        */
DECL|enumerator|PS_DICT_PAINT_TYPE
name|PS_DICT_PAINT_TYPE
block|,
comment|/* FT_Byte         */
DECL|enumerator|PS_DICT_FONT_NAME
name|PS_DICT_FONT_NAME
block|,
comment|/* FT_String*      */
DECL|enumerator|PS_DICT_UNIQUE_ID
name|PS_DICT_UNIQUE_ID
block|,
comment|/* FT_Int          */
DECL|enumerator|PS_DICT_NUM_CHAR_STRINGS
name|PS_DICT_NUM_CHAR_STRINGS
block|,
comment|/* FT_Int          */
DECL|enumerator|PS_DICT_CHAR_STRING_KEY
name|PS_DICT_CHAR_STRING_KEY
block|,
comment|/* FT_String*      */
DECL|enumerator|PS_DICT_CHAR_STRING
name|PS_DICT_CHAR_STRING
block|,
comment|/* FT_String*      */
DECL|enumerator|PS_DICT_ENCODING_TYPE
name|PS_DICT_ENCODING_TYPE
block|,
comment|/* T1_EncodingType */
DECL|enumerator|PS_DICT_ENCODING_ENTRY
name|PS_DICT_ENCODING_ENTRY
block|,
comment|/* FT_String*      */
comment|/* conventionally in the font Private dictionary */
DECL|enumerator|PS_DICT_NUM_SUBRS
name|PS_DICT_NUM_SUBRS
block|,
comment|/* FT_Int     */
DECL|enumerator|PS_DICT_SUBR
name|PS_DICT_SUBR
block|,
comment|/* FT_String* */
DECL|enumerator|PS_DICT_STD_HW
name|PS_DICT_STD_HW
block|,
comment|/* FT_UShort  */
DECL|enumerator|PS_DICT_STD_VW
name|PS_DICT_STD_VW
block|,
comment|/* FT_UShort  */
DECL|enumerator|PS_DICT_NUM_BLUE_VALUES
name|PS_DICT_NUM_BLUE_VALUES
block|,
comment|/* FT_Byte    */
DECL|enumerator|PS_DICT_BLUE_VALUE
name|PS_DICT_BLUE_VALUE
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_BLUE_FUZZ
name|PS_DICT_BLUE_FUZZ
block|,
comment|/* FT_Int     */
DECL|enumerator|PS_DICT_NUM_OTHER_BLUES
name|PS_DICT_NUM_OTHER_BLUES
block|,
comment|/* FT_Byte    */
DECL|enumerator|PS_DICT_OTHER_BLUE
name|PS_DICT_OTHER_BLUE
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_NUM_FAMILY_BLUES
name|PS_DICT_NUM_FAMILY_BLUES
block|,
comment|/* FT_Byte    */
DECL|enumerator|PS_DICT_FAMILY_BLUE
name|PS_DICT_FAMILY_BLUE
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_NUM_FAMILY_OTHER_BLUES
name|PS_DICT_NUM_FAMILY_OTHER_BLUES
block|,
comment|/* FT_Byte    */
DECL|enumerator|PS_DICT_FAMILY_OTHER_BLUE
name|PS_DICT_FAMILY_OTHER_BLUE
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_BLUE_SCALE
name|PS_DICT_BLUE_SCALE
block|,
comment|/* FT_Fixed   */
DECL|enumerator|PS_DICT_BLUE_SHIFT
name|PS_DICT_BLUE_SHIFT
block|,
comment|/* FT_Int     */
DECL|enumerator|PS_DICT_NUM_STEM_SNAP_H
name|PS_DICT_NUM_STEM_SNAP_H
block|,
comment|/* FT_Byte    */
DECL|enumerator|PS_DICT_STEM_SNAP_H
name|PS_DICT_STEM_SNAP_H
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_NUM_STEM_SNAP_V
name|PS_DICT_NUM_STEM_SNAP_V
block|,
comment|/* FT_Byte    */
DECL|enumerator|PS_DICT_STEM_SNAP_V
name|PS_DICT_STEM_SNAP_V
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_FORCE_BOLD
name|PS_DICT_FORCE_BOLD
block|,
comment|/* FT_Bool    */
DECL|enumerator|PS_DICT_RND_STEM_UP
name|PS_DICT_RND_STEM_UP
block|,
comment|/* FT_Bool    */
DECL|enumerator|PS_DICT_MIN_FEATURE
name|PS_DICT_MIN_FEATURE
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_LEN_IV
name|PS_DICT_LEN_IV
block|,
comment|/* FT_Int     */
DECL|enumerator|PS_DICT_PASSWORD
name|PS_DICT_PASSWORD
block|,
comment|/* FT_Long    */
DECL|enumerator|PS_DICT_LANGUAGE_GROUP
name|PS_DICT_LANGUAGE_GROUP
block|,
comment|/* FT_Long    */
comment|/* conventionally in the font FontInfo dictionary */
DECL|enumerator|PS_DICT_VERSION
name|PS_DICT_VERSION
block|,
comment|/* FT_String* */
DECL|enumerator|PS_DICT_NOTICE
name|PS_DICT_NOTICE
block|,
comment|/* FT_String* */
DECL|enumerator|PS_DICT_FULL_NAME
name|PS_DICT_FULL_NAME
block|,
comment|/* FT_String* */
DECL|enumerator|PS_DICT_FAMILY_NAME
name|PS_DICT_FAMILY_NAME
block|,
comment|/* FT_String* */
DECL|enumerator|PS_DICT_WEIGHT
name|PS_DICT_WEIGHT
block|,
comment|/* FT_String* */
DECL|enumerator|PS_DICT_IS_FIXED_PITCH
name|PS_DICT_IS_FIXED_PITCH
block|,
comment|/* FT_Bool    */
DECL|enumerator|PS_DICT_UNDERLINE_POSITION
name|PS_DICT_UNDERLINE_POSITION
block|,
comment|/* FT_Short   */
DECL|enumerator|PS_DICT_UNDERLINE_THICKNESS
name|PS_DICT_UNDERLINE_THICKNESS
block|,
comment|/* FT_UShort  */
DECL|enumerator|PS_DICT_FS_TYPE
name|PS_DICT_FS_TYPE
block|,
comment|/* FT_UShort  */
DECL|enumerator|PS_DICT_ITALIC_ANGLE
name|PS_DICT_ITALIC_ANGLE
block|,
comment|/* FT_Long    */
DECL|enumerator|PS_DICT_MAX
name|PS_DICT_MAX
init|=
name|PS_DICT_ITALIC_ANGLE
block|}
DECL|typedef|PS_Dict_Keys
name|PS_Dict_Keys
typedef|;
end_typedef
begin_comment
comment|/************************************************************************    *    * @function:    *    FT_Get_PS_Font_Value    *    * @description:    *    Retrieve the value for the supplied key from a PostScript font.    *    * @input:    *    face ::    *       PostScript face handle.    *    *    key ::    *       An enumeration value representing the dictionary key to retrieve.    *    *    idx ::    *       For array values, this specifies the index to be returned.    *    *    value ::    *       A pointer to memory into which to write the value.    *    *    valen_len ::    *       The size, in bytes, of the memory supplied for the value.    *    * @output:    *    value ::    *       The value matching the above key, if it exists.    *    * @return:    *    The amount of memory (in bytes) required to hold the requested    *    value (if it exists, -1 otherwise).    *    * @note:    *    The values returned are not pointers into the internal structures of    *    the face, but are `fresh' copies, so that the memory containing them    *    belongs to the calling application.  This also enforces the    *    `read-only' nature of these values, i.e., this function cannot be    *    used to manipulate the face.    *    *    `value' is a void pointer because the values returned can be of    *    various types.    *    *    If either `value' is NULL or `value_len' is too small, just the    *    required memory size for the requested entry is returned.    *    *    The `idx' parameter is used, not only to retrieve elements of, for    *    example, the FontMatrix or FontBBox, but also to retrieve name keys    *    from the CharStrings dictionary, and the charstrings themselves.  It    *    is ignored for atomic values.    *    *    PS_DICT_BLUE_SCALE returns a value that is scaled up by 1000.  To    *    get the value as in the font stream, you need to divide by    *    65536000.0 (to remove the FT_Fixed scale, and the x1000 scale).    *    *    IMPORTANT: Only key/value pairs read by the FreeType interpreter can    *    be retrieved.  So, for example, PostScript procedures such as NP,    *    ND, and RD are not available.  Arbitrary keys are, obviously, not be    *    available either.    *    *    If the font's format is not PostScript-based, this function returns    *    the `FT_Err_Invalid_Argument' error code.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
name|FT_Get_PS_Font_Value
argument_list|(
argument|FT_Face       face
argument_list|,
argument|PS_Dict_Keys  key
argument_list|,
argument|FT_UInt       idx
argument_list|,
argument|void         *value
argument_list|,
argument|FT_Long       value_len
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
comment|/* __T1TABLES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
