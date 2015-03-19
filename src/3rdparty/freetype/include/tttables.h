begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  tttables.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Basic SFNT/TrueType tables definitions and interface                 */
end_comment
begin_comment
comment|/*    (specification only).                                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2005, 2008-2014 by                                      */
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
name|__TTTABLES_H__
end_ifndef
begin_define
DECL|macro|__TTTABLES_H__
define|#
directive|define
name|__TTTABLES_H__
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
comment|/*    truetype_tables                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    TrueType Tables                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    TrueType specific table types and functions.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains the definition of TrueType-specific tables   */
end_comment
begin_comment
comment|/*    as well as some routines used to access and process them.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Order>                                                               */
end_comment
begin_comment
comment|/*    TT_Header                                                          */
end_comment
begin_comment
comment|/*    TT_HoriHeader                                                      */
end_comment
begin_comment
comment|/*    TT_VertHeader                                                      */
end_comment
begin_comment
comment|/*    TT_OS2                                                             */
end_comment
begin_comment
comment|/*    TT_Postscript                                                      */
end_comment
begin_comment
comment|/*    TT_PCLT                                                            */
end_comment
begin_comment
comment|/*    TT_MaxProfile                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Sfnt_Tag                                                        */
end_comment
begin_comment
comment|/*    FT_Get_Sfnt_Table                                                  */
end_comment
begin_comment
comment|/*    FT_Load_Sfnt_Table                                                 */
end_comment
begin_comment
comment|/*    FT_Sfnt_Table_Info                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Get_CMap_Language_ID                                            */
end_comment
begin_comment
comment|/*    FT_Get_CMap_Format                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_PARAM_TAG_UNPATENTED_HINTING                                    */
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
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    TT_Header                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a TrueType font header table.  All       */
end_comment
begin_comment
comment|/*    fields follow the TrueType specification.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Header_
typedef|typedef
struct|struct
name|TT_Header_
block|{
DECL|member|Table_Version
name|FT_Fixed
name|Table_Version
decl_stmt|;
DECL|member|Font_Revision
name|FT_Fixed
name|Font_Revision
decl_stmt|;
DECL|member|CheckSum_Adjust
name|FT_Long
name|CheckSum_Adjust
decl_stmt|;
DECL|member|Magic_Number
name|FT_Long
name|Magic_Number
decl_stmt|;
DECL|member|Flags
name|FT_UShort
name|Flags
decl_stmt|;
DECL|member|Units_Per_EM
name|FT_UShort
name|Units_Per_EM
decl_stmt|;
DECL|member|Created
name|FT_Long
name|Created
index|[
literal|2
index|]
decl_stmt|;
DECL|member|Modified
name|FT_Long
name|Modified
index|[
literal|2
index|]
decl_stmt|;
DECL|member|xMin
name|FT_Short
name|xMin
decl_stmt|;
DECL|member|yMin
name|FT_Short
name|yMin
decl_stmt|;
DECL|member|xMax
name|FT_Short
name|xMax
decl_stmt|;
DECL|member|yMax
name|FT_Short
name|yMax
decl_stmt|;
DECL|member|Mac_Style
name|FT_UShort
name|Mac_Style
decl_stmt|;
DECL|member|Lowest_Rec_PPEM
name|FT_UShort
name|Lowest_Rec_PPEM
decl_stmt|;
DECL|member|Font_Direction
name|FT_Short
name|Font_Direction
decl_stmt|;
DECL|member|Index_To_Loc_Format
name|FT_Short
name|Index_To_Loc_Format
decl_stmt|;
DECL|member|Glyph_Data_Format
name|FT_Short
name|Glyph_Data_Format
decl_stmt|;
block|}
DECL|typedef|TT_Header
name|TT_Header
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
comment|/*    TT_HoriHeader                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a TrueType horizontal header, the `hhea' */
end_comment
begin_comment
comment|/*    table, as well as the corresponding horizontal metrics table,      */
end_comment
begin_comment
comment|/*    i.e., the `hmtx' table.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    Version                :: The table version.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Ascender               :: The font's ascender, i.e., the distance  */
end_comment
begin_comment
comment|/*                              from the baseline to the top-most of all */
end_comment
begin_comment
comment|/*                              glyph points found in the font.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                              This value is invalid in many fonts, as  */
end_comment
begin_comment
comment|/*                              it is usually set by the font designer,  */
end_comment
begin_comment
comment|/*                              and often reflects only a portion of the */
end_comment
begin_comment
comment|/*                              glyphs found in the font (maybe ASCII).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                              You should use the `sTypoAscender' field */
end_comment
begin_comment
comment|/*                              of the OS/2 table instead if you want    */
end_comment
begin_comment
comment|/*                              the correct one.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Descender              :: The font's descender, i.e., the distance */
end_comment
begin_comment
comment|/*                              from the baseline to the bottom-most of  */
end_comment
begin_comment
comment|/*                              all glyph points found in the font.  It  */
end_comment
begin_comment
comment|/*                              is negative.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                              This value is invalid in many fonts, as  */
end_comment
begin_comment
comment|/*                              it is usually set by the font designer,  */
end_comment
begin_comment
comment|/*                              and often reflects only a portion of the */
end_comment
begin_comment
comment|/*                              glyphs found in the font (maybe ASCII).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                              You should use the `sTypoDescender'      */
end_comment
begin_comment
comment|/*                              field of the OS/2 table instead if you   */
end_comment
begin_comment
comment|/*                              want the correct one.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Line_Gap               :: The font's line gap, i.e., the distance  */
end_comment
begin_comment
comment|/*                              to add to the ascender and descender to  */
end_comment
begin_comment
comment|/*                              get the BTB, i.e., the                   */
end_comment
begin_comment
comment|/*                              baseline-to-baseline distance for the    */
end_comment
begin_comment
comment|/*                              font.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance_Width_Max      :: This field is the maximum of all advance */
end_comment
begin_comment
comment|/*                              widths found in the font.  It can be     */
end_comment
begin_comment
comment|/*                              used to compute the maximum width of an  */
end_comment
begin_comment
comment|/*                              arbitrary string of text.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    min_Left_Side_Bearing  :: The minimum left side bearing of all     */
end_comment
begin_comment
comment|/*                              glyphs within the font.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    min_Right_Side_Bearing :: The minimum right side bearing of all    */
end_comment
begin_comment
comment|/*                              glyphs within the font.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    xMax_Extent            :: The maximum horizontal extent (i.e., the */
end_comment
begin_comment
comment|/*                              `width' of a glyph's bounding box) for   */
end_comment
begin_comment
comment|/*                              all glyphs in the font.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_Slope_Rise       :: The rise coefficient of the cursor's     */
end_comment
begin_comment
comment|/*                              slope of the cursor (slope=rise/run).    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_Slope_Run        :: The run coefficient of the cursor's      */
end_comment
begin_comment
comment|/*                              slope.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Reserved               :: 8~reserved bytes.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    metric_Data_Format     :: Always~0.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    number_Of_HMetrics     :: Number of HMetrics entries in the `hmtx' */
end_comment
begin_comment
comment|/*                              table -- this value can be smaller than  */
end_comment
begin_comment
comment|/*                              the total number of glyphs in the font.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    long_metrics           :: A pointer into the `hmtx' table.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    short_metrics          :: A pointer into the `hmtx' table.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    IMPORTANT: The TT_HoriHeader and TT_VertHeader structures should   */
end_comment
begin_comment
comment|/*               be identical except for the names of their fields,      */
end_comment
begin_comment
comment|/*               which are different.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*               This ensures that a single function in the `ttload'     */
end_comment
begin_comment
comment|/*               module is able to read both the horizontal and vertical */
end_comment
begin_comment
comment|/*               headers.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_HoriHeader_
typedef|typedef
struct|struct
name|TT_HoriHeader_
block|{
DECL|member|Version
name|FT_Fixed
name|Version
decl_stmt|;
DECL|member|Ascender
name|FT_Short
name|Ascender
decl_stmt|;
DECL|member|Descender
name|FT_Short
name|Descender
decl_stmt|;
DECL|member|Line_Gap
name|FT_Short
name|Line_Gap
decl_stmt|;
DECL|member|advance_Width_Max
name|FT_UShort
name|advance_Width_Max
decl_stmt|;
comment|/* advance width maximum */
DECL|member|min_Left_Side_Bearing
name|FT_Short
name|min_Left_Side_Bearing
decl_stmt|;
comment|/* minimum left-sb       */
DECL|member|min_Right_Side_Bearing
name|FT_Short
name|min_Right_Side_Bearing
decl_stmt|;
comment|/* minimum right-sb      */
DECL|member|xMax_Extent
name|FT_Short
name|xMax_Extent
decl_stmt|;
comment|/* xmax extents          */
DECL|member|caret_Slope_Rise
name|FT_Short
name|caret_Slope_Rise
decl_stmt|;
DECL|member|caret_Slope_Run
name|FT_Short
name|caret_Slope_Run
decl_stmt|;
DECL|member|caret_Offset
name|FT_Short
name|caret_Offset
decl_stmt|;
DECL|member|Reserved
name|FT_Short
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
DECL|member|metric_Data_Format
name|FT_Short
name|metric_Data_Format
decl_stmt|;
DECL|member|number_Of_HMetrics
name|FT_UShort
name|number_Of_HMetrics
decl_stmt|;
comment|/* The following fields are not defined by the TrueType specification */
comment|/* but they are used to connect the metrics header to the relevant    */
comment|/* `HMTX' table.                                                      */
DECL|member|long_metrics
name|void
modifier|*
name|long_metrics
decl_stmt|;
DECL|member|short_metrics
name|void
modifier|*
name|short_metrics
decl_stmt|;
block|}
DECL|typedef|TT_HoriHeader
name|TT_HoriHeader
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
comment|/*    TT_VertHeader                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a TrueType vertical header, the `vhea'   */
end_comment
begin_comment
comment|/*    table, as well as the corresponding vertical metrics table, i.e.,  */
end_comment
begin_comment
comment|/*    the `vmtx' table.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    Version                 :: The table version.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Ascender                :: The font's ascender, i.e., the distance */
end_comment
begin_comment
comment|/*                               from the baseline to the top-most of    */
end_comment
begin_comment
comment|/*                               all glyph points found in the font.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                               This value is invalid in many fonts, as */
end_comment
begin_comment
comment|/*                               it is usually set by the font designer, */
end_comment
begin_comment
comment|/*                               and often reflects only a portion of    */
end_comment
begin_comment
comment|/*                               the glyphs found in the font (maybe     */
end_comment
begin_comment
comment|/*                               ASCII).                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                               You should use the `sTypoAscender'      */
end_comment
begin_comment
comment|/*                               field of the OS/2 table instead if you  */
end_comment
begin_comment
comment|/*                               want the correct one.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Descender               :: The font's descender, i.e., the         */
end_comment
begin_comment
comment|/*                               distance from the baseline to the       */
end_comment
begin_comment
comment|/*                               bottom-most of all glyph points found   */
end_comment
begin_comment
comment|/*                               in the font.  It is negative.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                               This value is invalid in many fonts, as */
end_comment
begin_comment
comment|/*                               it is usually set by the font designer, */
end_comment
begin_comment
comment|/*                               and often reflects only a portion of    */
end_comment
begin_comment
comment|/*                               the glyphs found in the font (maybe     */
end_comment
begin_comment
comment|/*                               ASCII).                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                               You should use the `sTypoDescender'     */
end_comment
begin_comment
comment|/*                               field of the OS/2 table instead if you  */
end_comment
begin_comment
comment|/*                               want the correct one.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Line_Gap                :: The font's line gap, i.e., the distance */
end_comment
begin_comment
comment|/*                               to add to the ascender and descender to */
end_comment
begin_comment
comment|/*                               get the BTB, i.e., the                  */
end_comment
begin_comment
comment|/*                               baseline-to-baseline distance for the   */
end_comment
begin_comment
comment|/*                               font.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance_Height_Max      :: This field is the maximum of all        */
end_comment
begin_comment
comment|/*                               advance heights found in the font.  It  */
end_comment
begin_comment
comment|/*                               can be used to compute the maximum      */
end_comment
begin_comment
comment|/*                               height of an arbitrary string of text.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    min_Top_Side_Bearing    :: The minimum top side bearing of all     */
end_comment
begin_comment
comment|/*                               glyphs within the font.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    min_Bottom_Side_Bearing :: The minimum bottom side bearing of all  */
end_comment
begin_comment
comment|/*                               glyphs within the font.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yMax_Extent             :: The maximum vertical extent (i.e., the  */
end_comment
begin_comment
comment|/*                               `height' of a glyph's bounding box) for */
end_comment
begin_comment
comment|/*                               all glyphs in the font.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_Slope_Rise        :: The rise coefficient of the cursor's    */
end_comment
begin_comment
comment|/*                               slope of the cursor (slope=rise/run).   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_Slope_Run         :: The run coefficient of the cursor's     */
end_comment
begin_comment
comment|/*                               slope.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_Offset            :: The cursor's offset for slanted fonts.  */
end_comment
begin_comment
comment|/*                               This value is `reserved' in vmtx        */
end_comment
begin_comment
comment|/*                               version 1.0.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Reserved                :: 8~reserved bytes.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    metric_Data_Format      :: Always~0.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    number_Of_HMetrics      :: Number of VMetrics entries in the       */
end_comment
begin_comment
comment|/*                               `vmtx' table -- this value can be       */
end_comment
begin_comment
comment|/*                               smaller than the total number of glyphs */
end_comment
begin_comment
comment|/*                               in the font.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    long_metrics           :: A pointer into the `vmtx' table.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    short_metrics          :: A pointer into the `vmtx' table.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    IMPORTANT: The TT_HoriHeader and TT_VertHeader structures should   */
end_comment
begin_comment
comment|/*               be identical except for the names of their fields,      */
end_comment
begin_comment
comment|/*               which are different.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*               This ensures that a single function in the `ttload'     */
end_comment
begin_comment
comment|/*               module is able to read both the horizontal and vertical */
end_comment
begin_comment
comment|/*               headers.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_VertHeader_
typedef|typedef
struct|struct
name|TT_VertHeader_
block|{
DECL|member|Version
name|FT_Fixed
name|Version
decl_stmt|;
DECL|member|Ascender
name|FT_Short
name|Ascender
decl_stmt|;
DECL|member|Descender
name|FT_Short
name|Descender
decl_stmt|;
DECL|member|Line_Gap
name|FT_Short
name|Line_Gap
decl_stmt|;
DECL|member|advance_Height_Max
name|FT_UShort
name|advance_Height_Max
decl_stmt|;
comment|/* advance height maximum */
DECL|member|min_Top_Side_Bearing
name|FT_Short
name|min_Top_Side_Bearing
decl_stmt|;
comment|/* minimum left-sb or top-sb       */
DECL|member|min_Bottom_Side_Bearing
name|FT_Short
name|min_Bottom_Side_Bearing
decl_stmt|;
comment|/* minimum right-sb or bottom-sb   */
DECL|member|yMax_Extent
name|FT_Short
name|yMax_Extent
decl_stmt|;
comment|/* xmax or ymax extents            */
DECL|member|caret_Slope_Rise
name|FT_Short
name|caret_Slope_Rise
decl_stmt|;
DECL|member|caret_Slope_Run
name|FT_Short
name|caret_Slope_Run
decl_stmt|;
DECL|member|caret_Offset
name|FT_Short
name|caret_Offset
decl_stmt|;
DECL|member|Reserved
name|FT_Short
name|Reserved
index|[
literal|4
index|]
decl_stmt|;
DECL|member|metric_Data_Format
name|FT_Short
name|metric_Data_Format
decl_stmt|;
DECL|member|number_Of_VMetrics
name|FT_UShort
name|number_Of_VMetrics
decl_stmt|;
comment|/* The following fields are not defined by the TrueType specification */
comment|/* but they're used to connect the metrics header to the relevant     */
comment|/* `HMTX' or `VMTX' table.                                            */
DECL|member|long_metrics
name|void
modifier|*
name|long_metrics
decl_stmt|;
DECL|member|short_metrics
name|void
modifier|*
name|short_metrics
decl_stmt|;
block|}
DECL|typedef|TT_VertHeader
name|TT_VertHeader
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
comment|/*    TT_OS2                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a TrueType OS/2 table.  All fields       */
end_comment
begin_comment
comment|/*    comply to the OpenType specification.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that we now support old Mac fonts that do not include an OS/2 */
end_comment
begin_comment
comment|/*    table.  In this case, the `version' field is always set to 0xFFFF. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_OS2_
typedef|typedef
struct|struct
name|TT_OS2_
block|{
DECL|member|version
name|FT_UShort
name|version
decl_stmt|;
comment|/* 0x0001 - more or 0xFFFF */
DECL|member|xAvgCharWidth
name|FT_Short
name|xAvgCharWidth
decl_stmt|;
DECL|member|usWeightClass
name|FT_UShort
name|usWeightClass
decl_stmt|;
DECL|member|usWidthClass
name|FT_UShort
name|usWidthClass
decl_stmt|;
DECL|member|fsType
name|FT_Short
name|fsType
decl_stmt|;
DECL|member|ySubscriptXSize
name|FT_Short
name|ySubscriptXSize
decl_stmt|;
DECL|member|ySubscriptYSize
name|FT_Short
name|ySubscriptYSize
decl_stmt|;
DECL|member|ySubscriptXOffset
name|FT_Short
name|ySubscriptXOffset
decl_stmt|;
DECL|member|ySubscriptYOffset
name|FT_Short
name|ySubscriptYOffset
decl_stmt|;
DECL|member|ySuperscriptXSize
name|FT_Short
name|ySuperscriptXSize
decl_stmt|;
DECL|member|ySuperscriptYSize
name|FT_Short
name|ySuperscriptYSize
decl_stmt|;
DECL|member|ySuperscriptXOffset
name|FT_Short
name|ySuperscriptXOffset
decl_stmt|;
DECL|member|ySuperscriptYOffset
name|FT_Short
name|ySuperscriptYOffset
decl_stmt|;
DECL|member|yStrikeoutSize
name|FT_Short
name|yStrikeoutSize
decl_stmt|;
DECL|member|yStrikeoutPosition
name|FT_Short
name|yStrikeoutPosition
decl_stmt|;
DECL|member|sFamilyClass
name|FT_Short
name|sFamilyClass
decl_stmt|;
DECL|member|panose
name|FT_Byte
name|panose
index|[
literal|10
index|]
decl_stmt|;
DECL|member|ulUnicodeRange1
name|FT_ULong
name|ulUnicodeRange1
decl_stmt|;
comment|/* Bits 0-31   */
DECL|member|ulUnicodeRange2
name|FT_ULong
name|ulUnicodeRange2
decl_stmt|;
comment|/* Bits 32-63  */
DECL|member|ulUnicodeRange3
name|FT_ULong
name|ulUnicodeRange3
decl_stmt|;
comment|/* Bits 64-95  */
DECL|member|ulUnicodeRange4
name|FT_ULong
name|ulUnicodeRange4
decl_stmt|;
comment|/* Bits 96-127 */
DECL|member|achVendID
name|FT_Char
name|achVendID
index|[
literal|4
index|]
decl_stmt|;
DECL|member|fsSelection
name|FT_UShort
name|fsSelection
decl_stmt|;
DECL|member|usFirstCharIndex
name|FT_UShort
name|usFirstCharIndex
decl_stmt|;
DECL|member|usLastCharIndex
name|FT_UShort
name|usLastCharIndex
decl_stmt|;
DECL|member|sTypoAscender
name|FT_Short
name|sTypoAscender
decl_stmt|;
DECL|member|sTypoDescender
name|FT_Short
name|sTypoDescender
decl_stmt|;
DECL|member|sTypoLineGap
name|FT_Short
name|sTypoLineGap
decl_stmt|;
DECL|member|usWinAscent
name|FT_UShort
name|usWinAscent
decl_stmt|;
DECL|member|usWinDescent
name|FT_UShort
name|usWinDescent
decl_stmt|;
comment|/* only version 1 and higher: */
DECL|member|ulCodePageRange1
name|FT_ULong
name|ulCodePageRange1
decl_stmt|;
comment|/* Bits 0-31   */
DECL|member|ulCodePageRange2
name|FT_ULong
name|ulCodePageRange2
decl_stmt|;
comment|/* Bits 32-63  */
comment|/* only version 2 and higher: */
DECL|member|sxHeight
name|FT_Short
name|sxHeight
decl_stmt|;
DECL|member|sCapHeight
name|FT_Short
name|sCapHeight
decl_stmt|;
DECL|member|usDefaultChar
name|FT_UShort
name|usDefaultChar
decl_stmt|;
DECL|member|usBreakChar
name|FT_UShort
name|usBreakChar
decl_stmt|;
DECL|member|usMaxContext
name|FT_UShort
name|usMaxContext
decl_stmt|;
comment|/* only version 5 and higher: */
DECL|member|usLowerOpticalPointSize
name|FT_UShort
name|usLowerOpticalPointSize
decl_stmt|;
comment|/* in twips (1/20th points) */
DECL|member|usUpperOpticalPointSize
name|FT_UShort
name|usUpperOpticalPointSize
decl_stmt|;
comment|/* in twips (1/20th points) */
block|}
DECL|typedef|TT_OS2
name|TT_OS2
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
comment|/*    TT_Postscript                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a TrueType PostScript table.  All fields */
end_comment
begin_comment
comment|/*    comply to the TrueType specification.  This structure does not     */
end_comment
begin_comment
comment|/*    reference the PostScript glyph names, which can be nevertheless    */
end_comment
begin_comment
comment|/*    accessed with the `ttpost' module.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Postscript_
typedef|typedef
struct|struct
name|TT_Postscript_
block|{
DECL|member|FormatType
name|FT_Fixed
name|FormatType
decl_stmt|;
DECL|member|italicAngle
name|FT_Fixed
name|italicAngle
decl_stmt|;
DECL|member|underlinePosition
name|FT_Short
name|underlinePosition
decl_stmt|;
DECL|member|underlineThickness
name|FT_Short
name|underlineThickness
decl_stmt|;
DECL|member|isFixedPitch
name|FT_ULong
name|isFixedPitch
decl_stmt|;
DECL|member|minMemType42
name|FT_ULong
name|minMemType42
decl_stmt|;
DECL|member|maxMemType42
name|FT_ULong
name|maxMemType42
decl_stmt|;
DECL|member|minMemType1
name|FT_ULong
name|minMemType1
decl_stmt|;
DECL|member|maxMemType1
name|FT_ULong
name|maxMemType1
decl_stmt|;
comment|/* Glyph names follow in the file, but we don't   */
comment|/* load them by default.  See the ttpost.c file.  */
block|}
DECL|typedef|TT_Postscript
name|TT_Postscript
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
comment|/*    TT_PCLT                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a TrueType PCLT table.  All fields       */
end_comment
begin_comment
comment|/*    comply to the TrueType specification.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_PCLT_
typedef|typedef
struct|struct
name|TT_PCLT_
block|{
DECL|member|Version
name|FT_Fixed
name|Version
decl_stmt|;
DECL|member|FontNumber
name|FT_ULong
name|FontNumber
decl_stmt|;
DECL|member|Pitch
name|FT_UShort
name|Pitch
decl_stmt|;
DECL|member|xHeight
name|FT_UShort
name|xHeight
decl_stmt|;
DECL|member|Style
name|FT_UShort
name|Style
decl_stmt|;
DECL|member|TypeFamily
name|FT_UShort
name|TypeFamily
decl_stmt|;
DECL|member|CapHeight
name|FT_UShort
name|CapHeight
decl_stmt|;
DECL|member|SymbolSet
name|FT_UShort
name|SymbolSet
decl_stmt|;
DECL|member|TypeFace
name|FT_Char
name|TypeFace
index|[
literal|16
index|]
decl_stmt|;
DECL|member|CharacterComplement
name|FT_Char
name|CharacterComplement
index|[
literal|8
index|]
decl_stmt|;
DECL|member|FileName
name|FT_Char
name|FileName
index|[
literal|6
index|]
decl_stmt|;
DECL|member|StrokeWeight
name|FT_Char
name|StrokeWeight
decl_stmt|;
DECL|member|WidthType
name|FT_Char
name|WidthType
decl_stmt|;
DECL|member|SerifStyle
name|FT_Byte
name|SerifStyle
decl_stmt|;
DECL|member|Reserved
name|FT_Byte
name|Reserved
decl_stmt|;
block|}
DECL|typedef|TT_PCLT
name|TT_PCLT
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
comment|/*    TT_MaxProfile                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The maximum profile is a table containing many max values, which   */
end_comment
begin_comment
comment|/*    can be used to pre-allocate arrays.  This ensures that no memory   */
end_comment
begin_comment
comment|/*    allocation occurs during a glyph load.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    version               :: The version number.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    numGlyphs             :: The number of glyphs in this TrueType     */
end_comment
begin_comment
comment|/*                             font.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxPoints             :: The maximum number of points in a         */
end_comment
begin_comment
comment|/*                             non-composite TrueType glyph.  See also   */
end_comment
begin_comment
comment|/*                             the structure element                     */
end_comment
begin_comment
comment|/*                             `maxCompositePoints'.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxContours           :: The maximum number of contours in a       */
end_comment
begin_comment
comment|/*                             non-composite TrueType glyph.  See also   */
end_comment
begin_comment
comment|/*                             the structure element                     */
end_comment
begin_comment
comment|/*                             `maxCompositeContours'.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxCompositePoints    :: The maximum number of points in a         */
end_comment
begin_comment
comment|/*                             composite TrueType glyph.  See also the   */
end_comment
begin_comment
comment|/*                             structure element `maxPoints'.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxCompositeContours  :: The maximum number of contours in a       */
end_comment
begin_comment
comment|/*                             composite TrueType glyph.  See also the   */
end_comment
begin_comment
comment|/*                             structure element `maxContours'.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxZones              :: The maximum number of zones used for      */
end_comment
begin_comment
comment|/*                             glyph hinting.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxTwilightPoints     :: The maximum number of points in the       */
end_comment
begin_comment
comment|/*                             twilight zone used for glyph hinting.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxStorage            :: The maximum number of elements in the     */
end_comment
begin_comment
comment|/*                             storage area used for glyph hinting.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxFunctionDefs       :: The maximum number of function            */
end_comment
begin_comment
comment|/*                             definitions in the TrueType bytecode for  */
end_comment
begin_comment
comment|/*                             this font.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxInstructionDefs    :: The maximum number of instruction         */
end_comment
begin_comment
comment|/*                             definitions in the TrueType bytecode for  */
end_comment
begin_comment
comment|/*                             this font.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxStackElements      :: The maximum number of stack elements used */
end_comment
begin_comment
comment|/*                             during bytecode interpretation.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxSizeOfInstructions :: The maximum number of TrueType opcodes    */
end_comment
begin_comment
comment|/*                             used for glyph hinting.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxComponentElements  :: The maximum number of simple (i.e., non-  */
end_comment
begin_comment
comment|/*                             composite) glyphs in a composite glyph.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maxComponentDepth     :: The maximum nesting depth of composite    */
end_comment
begin_comment
comment|/*                             glyphs.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This structure is only used during font loading.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_MaxProfile_
typedef|typedef
struct|struct
name|TT_MaxProfile_
block|{
DECL|member|version
name|FT_Fixed
name|version
decl_stmt|;
DECL|member|numGlyphs
name|FT_UShort
name|numGlyphs
decl_stmt|;
DECL|member|maxPoints
name|FT_UShort
name|maxPoints
decl_stmt|;
DECL|member|maxContours
name|FT_UShort
name|maxContours
decl_stmt|;
DECL|member|maxCompositePoints
name|FT_UShort
name|maxCompositePoints
decl_stmt|;
DECL|member|maxCompositeContours
name|FT_UShort
name|maxCompositeContours
decl_stmt|;
DECL|member|maxZones
name|FT_UShort
name|maxZones
decl_stmt|;
DECL|member|maxTwilightPoints
name|FT_UShort
name|maxTwilightPoints
decl_stmt|;
DECL|member|maxStorage
name|FT_UShort
name|maxStorage
decl_stmt|;
DECL|member|maxFunctionDefs
name|FT_UShort
name|maxFunctionDefs
decl_stmt|;
DECL|member|maxInstructionDefs
name|FT_UShort
name|maxInstructionDefs
decl_stmt|;
DECL|member|maxStackElements
name|FT_UShort
name|maxStackElements
decl_stmt|;
DECL|member|maxSizeOfInstructions
name|FT_UShort
name|maxSizeOfInstructions
decl_stmt|;
DECL|member|maxComponentElements
name|FT_UShort
name|maxComponentElements
decl_stmt|;
DECL|member|maxComponentDepth
name|FT_UShort
name|maxComponentDepth
decl_stmt|;
block|}
DECL|typedef|TT_MaxProfile
name|TT_MaxProfile
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
comment|/*    FT_Sfnt_Tag                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration used to specify the index of an SFNT table.         */
end_comment
begin_comment
comment|/*    Used in the @FT_Get_Sfnt_Table API function.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_SFNT_HEAD :: To access the font's @TT_Header structure.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SFNT_MAXP :: To access the font's @TT_MaxProfile structure.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SFNT_OS2  :: To access the font's @TT_OS2 structure.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SFNT_HHEA :: To access the font's @TT_HoriHeader structure.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SFNT_VHEA :: To access the font's @TT_VertHeader struture.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SFNT_POST :: To access the font's @TT_Postscript structure.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SFNT_PCLT :: To access the font's @TT_PCLT structure.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_Sfnt_Tag_
typedef|typedef
enum|enum
name|FT_Sfnt_Tag_
block|{
DECL|enumerator|FT_SFNT_HEAD
name|FT_SFNT_HEAD
block|,
DECL|enumerator|FT_SFNT_MAXP
name|FT_SFNT_MAXP
block|,
DECL|enumerator|FT_SFNT_OS2
name|FT_SFNT_OS2
block|,
DECL|enumerator|FT_SFNT_HHEA
name|FT_SFNT_HHEA
block|,
DECL|enumerator|FT_SFNT_VHEA
name|FT_SFNT_VHEA
block|,
DECL|enumerator|FT_SFNT_POST
name|FT_SFNT_POST
block|,
DECL|enumerator|FT_SFNT_PCLT
name|FT_SFNT_PCLT
block|,
DECL|enumerator|FT_SFNT_MAX
name|FT_SFNT_MAX
block|}
DECL|typedef|FT_Sfnt_Tag
name|FT_Sfnt_Tag
typedef|;
end_typedef
begin_comment
comment|/* these constants are deprecated; use the corresponding `FT_Sfnt_Tag' */
end_comment
begin_comment
comment|/* values instead                                                      */
end_comment
begin_define
DECL|macro|ft_sfnt_head
define|#
directive|define
name|ft_sfnt_head
value|FT_SFNT_HEAD
end_define
begin_define
DECL|macro|ft_sfnt_maxp
define|#
directive|define
name|ft_sfnt_maxp
value|FT_SFNT_MAXP
end_define
begin_define
DECL|macro|ft_sfnt_os2
define|#
directive|define
name|ft_sfnt_os2
value|FT_SFNT_OS2
end_define
begin_define
DECL|macro|ft_sfnt_hhea
define|#
directive|define
name|ft_sfnt_hhea
value|FT_SFNT_HHEA
end_define
begin_define
DECL|macro|ft_sfnt_vhea
define|#
directive|define
name|ft_sfnt_vhea
value|FT_SFNT_VHEA
end_define
begin_define
DECL|macro|ft_sfnt_post
define|#
directive|define
name|ft_sfnt_post
value|FT_SFNT_POST
end_define
begin_define
DECL|macro|ft_sfnt_pclt
define|#
directive|define
name|ft_sfnt_pclt
value|FT_SFNT_PCLT
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Get_Sfnt_Table                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return a pointer to a given SFNT table within a face.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the source.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tag  :: The index of the SFNT table.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A type-less pointer to the table.  This will be~0 in case of       */
end_comment
begin_comment
comment|/*    error, or if the corresponding table was not found *OR* loaded     */
end_comment
begin_comment
comment|/*    from the file.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Use a typecast according to `tag' to access the structure          */
end_comment
begin_comment
comment|/*    elements.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The table is owned by the face object and disappears with it.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function is only useful to access SFNT tables that are loaded */
end_comment
begin_comment
comment|/*    by the sfnt, truetype, and opentype drivers.  See @FT_Sfnt_Tag for */
end_comment
begin_comment
comment|/*    a list.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Here an example how to access the `vhea' table:                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      TT_VertHeader*  vert_header;                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      vert_header =                                                    */
end_comment
begin_comment
comment|/*        (TT_VertHeader*)FT_Get_Sfnt_Table( face, FT_SFNT_VHEA );       */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void*
argument_list|)
end_macro
begin_macro
name|FT_Get_Sfnt_Table
argument_list|(
argument|FT_Face      face
argument_list|,
argument|FT_Sfnt_Tag  tag
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************************   *   * @function:   *   FT_Load_Sfnt_Table   *   * @description:   *   Load any font table into client memory.   *   * @input:   *   face ::   *     A handle to the source face.   *   *   tag ::   *     The four-byte tag of the table to load.  Use the value~0 if you want   *     to access the whole font file.  Otherwise, you can use one of the   *     definitions found in the @FT_TRUETYPE_TAGS_H file, or forge a new   *     one with @FT_MAKE_TAG.   *   *   offset ::   *     The starting offset in the table (or file if tag == 0).   *   * @output:   *   buffer ::   *     The target buffer address.  The client must ensure that the memory   *     array is big enough to hold the data.   *   * @inout:   *   length ::   *     If the `length' parameter is NULL, then try to load the whole table.   *     Return an error code if it fails.   *   *     Else, if `*length' is~0, exit immediately while returning the   *     table's (or file) full size in it.   *   *     Else the number of bytes to read from the table or file, from the   *     starting offset.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   If you need to determine the table's length you should first call this   *   function with `*length' set to~0, as in the following example:   *   *     {   *       FT_ULong  length = 0;   *   *   *       error = FT_Load_Sfnt_Table( face, tag, 0, NULL,&length );   *       if ( error ) { ... table does not exist ... }   *   *       buffer = malloc( length );   *       if ( buffer == NULL ) { ... not enough memory ... }   *   *       error = FT_Load_Sfnt_Table( face, tag, 0, buffer,&length );   *       if ( error ) { ... could not load table ... }   *     }   *   *   Note that structures like @TT_Header or @TT_OS2 can't be used with   *   this function; they are limited to @FT_Get_Sfnt_Table.  Reason is that   *   those structures depend on the processor architecture, with varying   *   size (e.g. 32bit vs. 64bit) or order (big endian vs. little endian).   *   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Load_Sfnt_Table
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_ULong   tag
argument_list|,
argument|FT_Long    offset
argument_list|,
argument|FT_Byte*   buffer
argument_list|,
argument|FT_ULong*  length
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************************   *   * @function:   *   FT_Sfnt_Table_Info   *   * @description:   *   Return information on an SFNT table.   *   * @input:   *   face ::   *     A handle to the source face.   *   *   table_index ::   *     The index of an SFNT table.  The function returns   *     FT_Err_Table_Missing for an invalid value.   *   * @inout:   *   tag ::   *     The name tag of the SFNT table.  If the value is NULL, `table_index'   *     is ignored, and `length' returns the number of SFNT tables in the   *     font.   *   * @output:   *   length ::   *     The length of the SFNT table (or the number of SFNT tables, depending   *     on `tag').   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   While parsing fonts, FreeType handles SFNT tables with length zero as   *   missing.   *   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Sfnt_Table_Info
name|FT_Sfnt_Table_Info
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    table_index
argument_list|,
argument|FT_ULong  *tag
argument_list|,
argument|FT_ULong  *length
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Get_CMap_Language_ID                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return TrueType/sfnt specific cmap language ID.  Definitions of    */
end_comment
begin_comment
comment|/*    language ID values are in `ttnameid.h'.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    charmap ::                                                         */
end_comment
begin_comment
comment|/*      The target charmap.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The language ID of `charmap'.  If `charmap' doesn't belong to a    */
end_comment
begin_comment
comment|/*    TrueType/sfnt face, just return~0 as the default value.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    For a format~14 cmap (to access Unicode IVS), the return value is  */
end_comment
begin_comment
comment|/*    0xFFFFFFFF.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_ULong
argument_list|)
end_macro
begin_macro
name|FT_Get_CMap_Language_ID
argument_list|(
argument|FT_CharMap  charmap
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Get_CMap_Format                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return TrueType/sfnt specific cmap format.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    charmap ::                                                         */
end_comment
begin_comment
comment|/*      The target charmap.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The format of `charmap'.  If `charmap' doesn't belong to a         */
end_comment
begin_comment
comment|/*    TrueType/sfnt face, return -1.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_CMap_Format
name|FT_Get_CMap_Format
argument_list|(
argument|FT_CharMap  charmap
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Get_CMap_Format
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
comment|/* __TTTABLES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
