begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  tttypes.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Basic SFNT/TrueType type definitions and interface (specification    */
end_comment
begin_comment
comment|/*    only).                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2004, 2005, 2006, 2007, 2008 by             */
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
name|__TTTYPES_H__
end_ifndef
begin_define
DECL|macro|__TTTYPES_H__
define|#
directive|define
name|__TTTYPES_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_TRUETYPE_TABLES_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_OBJECTS_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
end_ifdef
begin_include
include|#
directive|include
include|FT_MULTIPLE_MASTERS_H
end_include
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***             REQUIRED TRUETYPE/OPENTYPE TABLES DEFINITIONS         ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*    TTC_HeaderRec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    TrueType collection header.  This table contains the offsets of    */
end_comment
begin_comment
comment|/*    the font headers of each distinct TrueType face in the file.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    tag     :: Must be `ttc ' to indicate a TrueType collection.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    version :: The version number.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    count   :: The number of faces in the collection.  The             */
end_comment
begin_comment
comment|/*               specification says this should be an unsigned long, but */
end_comment
begin_comment
comment|/*               we use a signed long since we need the value -1 for     */
end_comment
begin_comment
comment|/*               specific purposes.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    offsets :: The offsets of the font headers, one per face.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TTC_HeaderRec_
typedef|typedef
struct|struct
name|TTC_HeaderRec_
block|{
DECL|member|tag
name|FT_ULong
name|tag
decl_stmt|;
DECL|member|version
name|FT_Fixed
name|version
decl_stmt|;
DECL|member|count
name|FT_Long
name|count
decl_stmt|;
DECL|member|offsets
name|FT_ULong
modifier|*
name|offsets
decl_stmt|;
block|}
DECL|typedef|TTC_HeaderRec
name|TTC_HeaderRec
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
comment|/*    SFNT_HeaderRec                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    SFNT file format header.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    format_tag     :: The font format tag.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_tables     :: The number of tables in file.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    search_range   :: Must be `16 * (max power of 2<= num_tables)'.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    entry_selector :: Must be log2 of `search_range / 16'.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    range_shift    :: Must be `num_tables * 16 - search_range'.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|SFNT_HeaderRec_
typedef|typedef
struct|struct
name|SFNT_HeaderRec_
block|{
DECL|member|format_tag
name|FT_ULong
name|format_tag
decl_stmt|;
DECL|member|num_tables
name|FT_UShort
name|num_tables
decl_stmt|;
DECL|member|search_range
name|FT_UShort
name|search_range
decl_stmt|;
DECL|member|entry_selector
name|FT_UShort
name|entry_selector
decl_stmt|;
DECL|member|range_shift
name|FT_UShort
name|range_shift
decl_stmt|;
DECL|member|offset
name|FT_ULong
name|offset
decl_stmt|;
comment|/* not in file */
block|}
DECL|typedef|SFNT_HeaderRec
DECL|typedef|SFNT_Header
name|SFNT_HeaderRec
operator|,
typedef|*
name|SFNT_Header
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
comment|/*    TT_TableRec                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure describes a given table of a TrueType font.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    Tag      :: A four-bytes tag describing the table.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    CheckSum :: The table checksum.  This value can be ignored.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Offset   :: The offset of the table from the start of the TrueType */
end_comment
begin_comment
comment|/*                font in its resource.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Length   :: The table length (in bytes).                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_TableRec_
typedef|typedef
struct|struct
name|TT_TableRec_
block|{
DECL|member|Tag
name|FT_ULong
name|Tag
decl_stmt|;
comment|/*        table type */
DECL|member|CheckSum
name|FT_ULong
name|CheckSum
decl_stmt|;
comment|/*    table checksum */
DECL|member|Offset
name|FT_ULong
name|Offset
decl_stmt|;
comment|/* table file offset */
DECL|member|Length
name|FT_ULong
name|Length
decl_stmt|;
comment|/*      table length */
block|}
DECL|typedef|TT_TableRec
DECL|typedef|TT_Table
name|TT_TableRec
operator|,
typedef|*
name|TT_Table
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
comment|/*    TT_LongMetricsRec                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure modeling the long metrics of the `hmtx' and `vmtx'     */
end_comment
begin_comment
comment|/*    TrueType tables.  The values are expressed in font units.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    advance :: The advance width or height for the glyph.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bearing :: The left-side or top-side bearing for the glyph.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_LongMetricsRec_
typedef|typedef
struct|struct
name|TT_LongMetricsRec_
block|{
DECL|member|advance
name|FT_UShort
name|advance
decl_stmt|;
DECL|member|bearing
name|FT_Short
name|bearing
decl_stmt|;
block|}
DECL|typedef|TT_LongMetricsRec
DECL|typedef|TT_LongMetrics
name|TT_LongMetricsRec
operator|,
typedef|*
name|TT_LongMetrics
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
comment|/*    TT_ShortMetrics                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple type to model the short metrics of the `hmtx' and `vmtx'  */
end_comment
begin_comment
comment|/*    tables.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|TT_ShortMetrics
typedef|typedef
name|FT_Short
name|TT_ShortMetrics
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
comment|/*    TT_NameEntryRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure modeling TrueType name records.  Name records are used */
end_comment
begin_comment
comment|/*    to store important strings like family name, style name,           */
end_comment
begin_comment
comment|/*    copyright, etc. in _localized_ versions (i.e., language, encoding, */
end_comment
begin_comment
comment|/*    etc).                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    platformID   :: The ID of the name's encoding platform.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    encodingID   :: The platform-specific ID for the name's encoding.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    languageID   :: The platform-specific ID for the name's language.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    nameID       :: The ID specifying what kind of name this is.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stringLength :: The length of the string in bytes.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stringOffset :: The offset to the string in the `name' table.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    string       :: A pointer to the string's bytes.  Note that these  */
end_comment
begin_comment
comment|/*                    are usually UTF-16 encoded characters.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_NameEntryRec_
typedef|typedef
struct|struct
name|TT_NameEntryRec_
block|{
DECL|member|platformID
name|FT_UShort
name|platformID
decl_stmt|;
DECL|member|encodingID
name|FT_UShort
name|encodingID
decl_stmt|;
DECL|member|languageID
name|FT_UShort
name|languageID
decl_stmt|;
DECL|member|nameID
name|FT_UShort
name|nameID
decl_stmt|;
DECL|member|stringLength
name|FT_UShort
name|stringLength
decl_stmt|;
DECL|member|stringOffset
name|FT_ULong
name|stringOffset
decl_stmt|;
comment|/* this last field is not defined in the spec */
comment|/* but used by the FreeType engine            */
DECL|member|string
name|FT_Byte
modifier|*
name|string
decl_stmt|;
block|}
DECL|typedef|TT_NameEntryRec
DECL|typedef|TT_NameEntry
name|TT_NameEntryRec
operator|,
typedef|*
name|TT_NameEntry
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
comment|/*    TT_NameTableRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure modeling the TrueType name table.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    format         :: The format of the name table.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    numNameRecords :: The number of names in table.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    storageOffset  :: The offset of the name table in the `name'       */
end_comment
begin_comment
comment|/*                      TrueType table.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    names          :: An array of name records.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream         :: the file's input stream.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_NameTableRec_
typedef|typedef
struct|struct
name|TT_NameTableRec_
block|{
DECL|member|format
name|FT_UShort
name|format
decl_stmt|;
DECL|member|numNameRecords
name|FT_UInt
name|numNameRecords
decl_stmt|;
DECL|member|storageOffset
name|FT_UInt
name|storageOffset
decl_stmt|;
DECL|member|names
name|TT_NameEntryRec
modifier|*
name|names
decl_stmt|;
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
block|}
DECL|typedef|TT_NameTableRec
DECL|typedef|TT_NameTable
name|TT_NameTableRec
operator|,
typedef|*
name|TT_NameTable
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***             OPTIONAL TRUETYPE/OPENTYPE TABLES DEFINITIONS         ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*    TT_GaspRangeRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A tiny structure used to model a gasp range according to the       */
end_comment
begin_comment
comment|/*    TrueType specification.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    maxPPEM  :: The maximum ppem value to which `gaspFlag' applies.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gaspFlag :: A flag describing the grid-fitting and anti-aliasing   */
end_comment
begin_comment
comment|/*                modes to be used.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_GaspRangeRec_
typedef|typedef
struct|struct
name|TT_GaspRangeRec_
block|{
DECL|member|maxPPEM
name|FT_UShort
name|maxPPEM
decl_stmt|;
DECL|member|gaspFlag
name|FT_UShort
name|gaspFlag
decl_stmt|;
block|}
DECL|typedef|TT_GaspRangeRec
DECL|typedef|TT_GaspRange
name|TT_GaspRangeRec
operator|,
typedef|*
name|TT_GaspRange
typedef|;
end_typedef
begin_define
DECL|macro|TT_GASP_GRIDFIT
define|#
directive|define
name|TT_GASP_GRIDFIT
value|0x01
end_define
begin_define
DECL|macro|TT_GASP_DOGRAY
define|#
directive|define
name|TT_GASP_DOGRAY
value|0x02
end_define
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
comment|/*    TT_GaspRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure modeling the TrueType `gasp' table used to specify     */
end_comment
begin_comment
comment|/*    grid-fitting and anti-aliasing behaviour.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    version    :: The version number.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    numRanges  :: The number of gasp ranges in table.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gaspRanges :: An array of gasp ranges.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Gasp_
typedef|typedef
struct|struct
name|TT_Gasp_
block|{
DECL|member|version
name|FT_UShort
name|version
decl_stmt|;
DECL|member|numRanges
name|FT_UShort
name|numRanges
decl_stmt|;
DECL|member|gaspRanges
name|TT_GaspRange
name|gaspRanges
decl_stmt|;
block|}
DECL|typedef|TT_GaspRec
name|TT_GaspRec
typedef|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
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
comment|/*    TT_HdmxEntryRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A small structure used to model the pre-computed widths of a given */
end_comment
begin_comment
comment|/*    size.  They are found in the `hdmx' table.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    ppem      :: The pixels per EM value at which these metrics apply. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_width :: The maximum advance width for this metric.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    widths    :: An array of widths.  Note: These are 8-bit bytes.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_HdmxEntryRec_
typedef|typedef
struct|struct
name|TT_HdmxEntryRec_
block|{
DECL|member|ppem
name|FT_Byte
name|ppem
decl_stmt|;
DECL|member|max_width
name|FT_Byte
name|max_width
decl_stmt|;
DECL|member|widths
name|FT_Byte
modifier|*
name|widths
decl_stmt|;
block|}
DECL|typedef|TT_HdmxEntryRec
DECL|typedef|TT_HdmxEntry
name|TT_HdmxEntryRec
operator|,
typedef|*
name|TT_HdmxEntry
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
comment|/*    TT_HdmxRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model the `hdmx' table, which contains         */
end_comment
begin_comment
comment|/*    pre-computed widths for a set of given sizes/dimensions.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    version     :: The version number.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_records :: The number of hdmx records.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    records     :: An array of hdmx records.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_HdmxRec_
typedef|typedef
struct|struct
name|TT_HdmxRec_
block|{
DECL|member|version
name|FT_UShort
name|version
decl_stmt|;
DECL|member|num_records
name|FT_Short
name|num_records
decl_stmt|;
DECL|member|records
name|TT_HdmxEntry
name|records
decl_stmt|;
block|}
DECL|typedef|TT_HdmxRec
DECL|typedef|TT_Hdmx
name|TT_HdmxRec
operator|,
typedef|*
name|TT_Hdmx
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
comment|/*    TT_Kern0_PairRec                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a kerning pair for the kerning table     */
end_comment
begin_comment
comment|/*    format 0.  The engine now loads this table if it finds one in the  */
end_comment
begin_comment
comment|/*    font file.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    left  :: The index of the left glyph in pair.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    right :: The index of the right glyph in pair.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    value :: The kerning distance.  A positive value spaces the        */
end_comment
begin_comment
comment|/*             glyphs, a negative one makes them closer.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Kern0_PairRec_
typedef|typedef
struct|struct
name|TT_Kern0_PairRec_
block|{
DECL|member|left
name|FT_UShort
name|left
decl_stmt|;
comment|/* index of left  glyph in pair */
DECL|member|right
name|FT_UShort
name|right
decl_stmt|;
comment|/* index of right glyph in pair */
DECL|member|value
name|FT_FWord
name|value
decl_stmt|;
comment|/* kerning value                */
block|}
DECL|typedef|TT_Kern0_PairRec
DECL|typedef|TT_Kern0_Pair
name|TT_Kern0_PairRec
operator|,
typedef|*
name|TT_Kern0_Pair
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                    EMBEDDED BITMAPS SUPPORT                       ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*    TT_SBit_MetricsRec                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to hold the big metrics of a given glyph bitmap   */
end_comment
begin_comment
comment|/*    in a TrueType or OpenType font.  These are usually found in the    */
end_comment
begin_comment
comment|/*    `EBDT' (Microsoft) or `bloc' (Apple) table.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    height       :: The glyph height in pixels.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    width        :: The glyph width in pixels.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiBearingX :: The horizontal left bearing.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiBearingY :: The horizontal top bearing.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiAdvance  :: The horizontal advance.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertBearingX :: The vertical left bearing.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertBearingY :: The vertical top bearing.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertAdvance  :: The vertical advance.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_MetricsRec_
typedef|typedef
struct|struct
name|TT_SBit_MetricsRec_
block|{
DECL|member|height
name|FT_Byte
name|height
decl_stmt|;
DECL|member|width
name|FT_Byte
name|width
decl_stmt|;
DECL|member|horiBearingX
name|FT_Char
name|horiBearingX
decl_stmt|;
DECL|member|horiBearingY
name|FT_Char
name|horiBearingY
decl_stmt|;
DECL|member|horiAdvance
name|FT_Byte
name|horiAdvance
decl_stmt|;
DECL|member|vertBearingX
name|FT_Char
name|vertBearingX
decl_stmt|;
DECL|member|vertBearingY
name|FT_Char
name|vertBearingY
decl_stmt|;
DECL|member|vertAdvance
name|FT_Byte
name|vertAdvance
decl_stmt|;
block|}
DECL|typedef|TT_SBit_MetricsRec
DECL|typedef|TT_SBit_Metrics
name|TT_SBit_MetricsRec
operator|,
typedef|*
name|TT_SBit_Metrics
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
comment|/*    TT_SBit_SmallMetricsRec                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to hold the small metrics of a given glyph bitmap */
end_comment
begin_comment
comment|/*    in a TrueType or OpenType font.  These are usually found in the    */
end_comment
begin_comment
comment|/*    `EBDT' (Microsoft) or the `bdat' (Apple) table.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    height   :: The glyph height in pixels.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    width    :: The glyph width in pixels.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bearingX :: The left-side bearing.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bearingY :: The top-side bearing.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance  :: The advance width or height.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_Small_Metrics_
typedef|typedef
struct|struct
name|TT_SBit_Small_Metrics_
block|{
DECL|member|height
name|FT_Byte
name|height
decl_stmt|;
DECL|member|width
name|FT_Byte
name|width
decl_stmt|;
DECL|member|bearingX
name|FT_Char
name|bearingX
decl_stmt|;
DECL|member|bearingY
name|FT_Char
name|bearingY
decl_stmt|;
DECL|member|advance
name|FT_Byte
name|advance
decl_stmt|;
block|}
DECL|typedef|TT_SBit_SmallMetricsRec
DECL|typedef|TT_SBit_SmallMetrics
name|TT_SBit_SmallMetricsRec
operator|,
typedef|*
name|TT_SBit_SmallMetrics
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
comment|/*    TT_SBit_LineMetricsRec                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to describe the text line metrics of a given      */
end_comment
begin_comment
comment|/*    bitmap strike, for either a horizontal or vertical layout.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    ascender                :: The ascender in pixels.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    descender               :: The descender in pixels.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_width               :: The maximum glyph width in pixels.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_slope_enumerator  :: Rise of the caret slope, typically set  */
end_comment
begin_comment
comment|/*                               to 1 for non-italic fonts.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_slope_denominator :: Rise of the caret slope, typically set  */
end_comment
begin_comment
comment|/*                               to 0 for non-italic fonts.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    caret_offset            :: Offset in pixels to move the caret for  */
end_comment
begin_comment
comment|/*                               proper positioning.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    min_origin_SB           :: Minimum of horiBearingX (resp.          */
end_comment
begin_comment
comment|/*                               vertBearingY).                          */
end_comment
begin_comment
comment|/*    min_advance_SB          :: Minimum of                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                 horizontal advance -                  */
end_comment
begin_comment
comment|/*                                   ( horiBearingX + width )            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                               resp.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                 vertical advance -                    */
end_comment
begin_comment
comment|/*                                   ( vertBearingY + height )           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_before_BL           :: Maximum of horiBearingY (resp.          */
end_comment
begin_comment
comment|/*                               vertBearingY).                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    min_after_BL            :: Minimum of                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                 horiBearingY - height                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                               resp.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                 vertBearingX - width                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pads                    :: Unused (to make the size of the record  */
end_comment
begin_comment
comment|/*                               a multiple of 32 bits.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_LineMetricsRec_
typedef|typedef
struct|struct
name|TT_SBit_LineMetricsRec_
block|{
DECL|member|ascender
name|FT_Char
name|ascender
decl_stmt|;
DECL|member|descender
name|FT_Char
name|descender
decl_stmt|;
DECL|member|max_width
name|FT_Byte
name|max_width
decl_stmt|;
DECL|member|caret_slope_numerator
name|FT_Char
name|caret_slope_numerator
decl_stmt|;
DECL|member|caret_slope_denominator
name|FT_Char
name|caret_slope_denominator
decl_stmt|;
DECL|member|caret_offset
name|FT_Char
name|caret_offset
decl_stmt|;
DECL|member|min_origin_SB
name|FT_Char
name|min_origin_SB
decl_stmt|;
DECL|member|min_advance_SB
name|FT_Char
name|min_advance_SB
decl_stmt|;
DECL|member|max_before_BL
name|FT_Char
name|max_before_BL
decl_stmt|;
DECL|member|min_after_BL
name|FT_Char
name|min_after_BL
decl_stmt|;
DECL|member|pads
name|FT_Char
name|pads
index|[
literal|2
index|]
decl_stmt|;
block|}
DECL|typedef|TT_SBit_LineMetricsRec
DECL|typedef|TT_SBit_LineMetrics
name|TT_SBit_LineMetricsRec
operator|,
typedef|*
name|TT_SBit_LineMetrics
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
comment|/*    TT_SBit_RangeRec                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A TrueType/OpenType subIndexTable as defined in the `EBLC'         */
end_comment
begin_comment
comment|/*    (Microsoft) or `bloc' (Apple) tables.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    first_glyph   :: The first glyph index in the range.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    last_glyph    :: The last glyph index in the range.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    index_format  :: The format of index table.  Valid values are 1    */
end_comment
begin_comment
comment|/*                     to 5.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    image_format  :: The format of `EBDT' image data.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    image_offset  :: The offset to image data in `EBDT'.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    image_size    :: For index formats 2 and 5.  This is the size in   */
end_comment
begin_comment
comment|/*                     bytes of each glyph bitmap.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    big_metrics   :: For index formats 2 and 5.  This is the big       */
end_comment
begin_comment
comment|/*                     metrics for each glyph bitmap.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_glyphs    :: For index formats 4 and 5.  This is the number of */
end_comment
begin_comment
comment|/*                     glyphs in the code array.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_offsets :: For index formats 1 and 3.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_codes   :: For index formats 4 and 5.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    table_offset  :: The offset of the index table in the `EBLC'       */
end_comment
begin_comment
comment|/*                     table.  Only used during strike loading.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_RangeRec_
typedef|typedef
struct|struct
name|TT_SBit_RangeRec_
block|{
DECL|member|first_glyph
name|FT_UShort
name|first_glyph
decl_stmt|;
DECL|member|last_glyph
name|FT_UShort
name|last_glyph
decl_stmt|;
DECL|member|index_format
name|FT_UShort
name|index_format
decl_stmt|;
DECL|member|image_format
name|FT_UShort
name|image_format
decl_stmt|;
DECL|member|image_offset
name|FT_ULong
name|image_offset
decl_stmt|;
DECL|member|image_size
name|FT_ULong
name|image_size
decl_stmt|;
DECL|member|metrics
name|TT_SBit_MetricsRec
name|metrics
decl_stmt|;
DECL|member|num_glyphs
name|FT_ULong
name|num_glyphs
decl_stmt|;
DECL|member|glyph_offsets
name|FT_ULong
modifier|*
name|glyph_offsets
decl_stmt|;
DECL|member|glyph_codes
name|FT_UShort
modifier|*
name|glyph_codes
decl_stmt|;
DECL|member|table_offset
name|FT_ULong
name|table_offset
decl_stmt|;
block|}
DECL|typedef|TT_SBit_RangeRec
DECL|typedef|TT_SBit_Range
name|TT_SBit_RangeRec
operator|,
typedef|*
name|TT_SBit_Range
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
comment|/*    TT_SBit_StrikeRec                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used describe a given bitmap strike in the `EBLC'      */
end_comment
begin_comment
comment|/*    (Microsoft) or `bloc' (Apple) tables.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*   num_index_ranges :: The number of index ranges.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   index_ranges     :: An array of glyph index ranges.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   color_ref        :: Unused.  `color_ref' is put in for future       */
end_comment
begin_comment
comment|/*                       enhancements, but these fields are already      */
end_comment
begin_comment
comment|/*                       in use by other platforms (e.g. Newton).        */
end_comment
begin_comment
comment|/*                       For details, please see                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                         http://fonts.apple.com/                       */
end_comment
begin_comment
comment|/*                                TTRefMan/RM06/Chap6bloc.html           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   hori             :: The line metrics for horizontal layouts.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   vert             :: The line metrics for vertical layouts.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   start_glyph      :: The lowest glyph index for this strike.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   end_glyph        :: The highest glyph index for this strike.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   x_ppem           :: The number of horizontal pixels per EM.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   y_ppem           :: The number of vertical pixels per EM.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   bit_depth        :: The bit depth.  Valid values are 1, 2, 4,       */
end_comment
begin_comment
comment|/*                       and 8.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*   flags            :: Is this a vertical or horizontal strike?  For   */
end_comment
begin_comment
comment|/*                       details, please see                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                         http://fonts.apple.com/                       */
end_comment
begin_comment
comment|/*                                TTRefMan/RM06/Chap6bloc.html           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_StrikeRec_
typedef|typedef
struct|struct
name|TT_SBit_StrikeRec_
block|{
DECL|member|num_ranges
name|FT_Int
name|num_ranges
decl_stmt|;
DECL|member|sbit_ranges
name|TT_SBit_Range
name|sbit_ranges
decl_stmt|;
DECL|member|ranges_offset
name|FT_ULong
name|ranges_offset
decl_stmt|;
DECL|member|color_ref
name|FT_ULong
name|color_ref
decl_stmt|;
DECL|member|hori
name|TT_SBit_LineMetricsRec
name|hori
decl_stmt|;
DECL|member|vert
name|TT_SBit_LineMetricsRec
name|vert
decl_stmt|;
DECL|member|start_glyph
name|FT_UShort
name|start_glyph
decl_stmt|;
DECL|member|end_glyph
name|FT_UShort
name|end_glyph
decl_stmt|;
DECL|member|x_ppem
name|FT_Byte
name|x_ppem
decl_stmt|;
DECL|member|y_ppem
name|FT_Byte
name|y_ppem
decl_stmt|;
DECL|member|bit_depth
name|FT_Byte
name|bit_depth
decl_stmt|;
DECL|member|flags
name|FT_Char
name|flags
decl_stmt|;
block|}
DECL|typedef|TT_SBit_StrikeRec
DECL|typedef|TT_SBit_Strike
name|TT_SBit_StrikeRec
operator|,
typedef|*
name|TT_SBit_Strike
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
comment|/*    TT_SBit_ComponentRec                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure to describe a compound sbit element.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    glyph_code :: The element's glyph index.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x_offset   :: The element's left bearing.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_offset   :: The element's top bearing.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_ComponentRec_
typedef|typedef
struct|struct
name|TT_SBit_ComponentRec_
block|{
DECL|member|glyph_code
name|FT_UShort
name|glyph_code
decl_stmt|;
DECL|member|x_offset
name|FT_Char
name|x_offset
decl_stmt|;
DECL|member|y_offset
name|FT_Char
name|y_offset
decl_stmt|;
block|}
DECL|typedef|TT_SBit_ComponentRec
DECL|typedef|TT_SBit_Component
name|TT_SBit_ComponentRec
operator|,
typedef|*
name|TT_SBit_Component
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
comment|/*    TT_SBit_ScaleRec                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used describe a given bitmap scaling table, as defined */
end_comment
begin_comment
comment|/*    in the `EBSC' table.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    hori              :: The horizontal line metrics.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vert              :: The vertical line metrics.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x_ppem            :: The number of horizontal pixels per EM.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_ppem            :: The number of vertical pixels per EM.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x_ppem_substitute :: Substitution x_ppem value.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_ppem_substitute :: Substitution y_ppem value.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_SBit_ScaleRec_
typedef|typedef
struct|struct
name|TT_SBit_ScaleRec_
block|{
DECL|member|hori
name|TT_SBit_LineMetricsRec
name|hori
decl_stmt|;
DECL|member|vert
name|TT_SBit_LineMetricsRec
name|vert
decl_stmt|;
DECL|member|x_ppem
name|FT_Byte
name|x_ppem
decl_stmt|;
DECL|member|y_ppem
name|FT_Byte
name|y_ppem
decl_stmt|;
DECL|member|x_ppem_substitute
name|FT_Byte
name|x_ppem_substitute
decl_stmt|;
DECL|member|y_ppem_substitute
name|FT_Byte
name|y_ppem_substitute
decl_stmt|;
block|}
DECL|typedef|TT_SBit_ScaleRec
DECL|typedef|TT_SBit_Scale
name|TT_SBit_ScaleRec
operator|,
typedef|*
name|TT_SBit_Scale
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                  POSTSCRIPT GLYPH NAMES SUPPORT                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/*    TT_Post_20Rec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Postscript names sub-table, format 2.0.  Stores the PS name of     */
end_comment
begin_comment
comment|/*    each glyph in the font face.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    num_glyphs    :: The number of named glyphs in the table.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_names     :: The number of PS names stored in the table.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_indices :: The indices of the glyphs in the names arrays.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_names   :: The PS names not in Mac Encoding.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Post_20Rec_
typedef|typedef
struct|struct
name|TT_Post_20Rec_
block|{
DECL|member|num_glyphs
name|FT_UShort
name|num_glyphs
decl_stmt|;
DECL|member|num_names
name|FT_UShort
name|num_names
decl_stmt|;
DECL|member|glyph_indices
name|FT_UShort
modifier|*
name|glyph_indices
decl_stmt|;
DECL|member|glyph_names
name|FT_Char
modifier|*
modifier|*
name|glyph_names
decl_stmt|;
block|}
DECL|typedef|TT_Post_20Rec
DECL|typedef|TT_Post_20
name|TT_Post_20Rec
operator|,
typedef|*
name|TT_Post_20
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
comment|/*    TT_Post_25Rec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Postscript names sub-table, format 2.5.  Stores the PS name of     */
end_comment
begin_comment
comment|/*    each glyph in the font face.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    num_glyphs :: The number of glyphs in the table.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    offsets    :: An array of signed offsets in a normal Mac           */
end_comment
begin_comment
comment|/*                  Postscript name encoding.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Post_25_
typedef|typedef
struct|struct
name|TT_Post_25_
block|{
DECL|member|num_glyphs
name|FT_UShort
name|num_glyphs
decl_stmt|;
DECL|member|offsets
name|FT_Char
modifier|*
name|offsets
decl_stmt|;
block|}
DECL|typedef|TT_Post_25Rec
DECL|typedef|TT_Post_25
name|TT_Post_25Rec
operator|,
typedef|*
name|TT_Post_25
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
comment|/*    TT_Post_NamesRec                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Postscript names table, either format 2.0 or 2.5.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    loaded    :: A flag to indicate whether the PS names are loaded.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format_20 :: The sub-table used for format 2.0.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format_25 :: The sub-table used for format 2.5.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_Post_NamesRec_
typedef|typedef
struct|struct
name|TT_Post_NamesRec_
block|{
DECL|member|loaded
name|FT_Bool
name|loaded
decl_stmt|;
union|union
block|{
DECL|member|format_20
name|TT_Post_20Rec
name|format_20
decl_stmt|;
DECL|member|format_25
name|TT_Post_25Rec
name|format_25
decl_stmt|;
block|}
DECL|member|names
name|names
union|;
block|}
DECL|typedef|TT_Post_NamesRec
DECL|typedef|TT_Post_Names
name|TT_Post_NamesRec
operator|,
typedef|*
name|TT_Post_Names
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                    GX VARIATION TABLE SUPPORT                     ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
end_ifdef
begin_typedef
DECL|typedef|GX_Blend
typedef|typedef
name|struct
name|GX_BlendRec_
modifier|*
name|GX_Blend
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***              EMBEDDED BDF PROPERTIES TABLE SUPPORT                ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*    * These types are used to support a `BDF ' table that isn't part of the    * official TrueType specification.  It is mainly used in SFNT-based    * bitmap fonts that were generated from a set of BDF fonts.    *    * The format of the table is as follows.    *    *   USHORT   version      `BDF ' table version number, should be 0x0001.    *   USHORT   strikeCount  Number of strikes (bitmap sizes) in this table.    *   ULONG    stringTable  Offset (from start of BDF table) to string    *                         table.    *    * This is followed by an array of `strikeCount' descriptors, having the    * following format.    *    *   USHORT   ppem         Vertical pixels per EM for this strike.    *   USHORT   numItems     Number of items for this strike (properties and    *                         atoms).  Maximum is 255.    *    * This array in turn is followed by `strikeCount' value sets.  Each    * `value set' is an array of `numItems' items with the following format.    *    *   ULONG    item_name    Offset in string table to item name.    *   USHORT   item_type    The item type.  Possible values are    *                            0 => string (e.g., COMMENT)    *                            1 => atom   (e.g., FONT or even SIZE)    *                            2 => int32    *                            3 => uint32    *                         0x10 => A flag to indicate a properties.  This    *                                 is ORed with the above values.    *   ULONG    item_value   For strings  => Offset into string table without    *                                         the corresponding double quotes.    *                         For atoms    => Offset into string table.    *                         For integers => Direct value.    *    * All strings in the string table consist of bytes and are    * zero-terminated.    *    */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BDF
end_ifdef
begin_typedef
DECL|struct|TT_BDFRec_
typedef|typedef
struct|struct
name|TT_BDFRec_
block|{
DECL|member|table
name|FT_Byte
modifier|*
name|table
decl_stmt|;
DECL|member|table_end
name|FT_Byte
modifier|*
name|table_end
decl_stmt|;
DECL|member|strings
name|FT_Byte
modifier|*
name|strings
decl_stmt|;
DECL|member|strings_size
name|FT_ULong
name|strings_size
decl_stmt|;
DECL|member|num_strikes
name|FT_UInt
name|num_strikes
decl_stmt|;
DECL|member|loaded
name|FT_Bool
name|loaded
decl_stmt|;
block|}
DECL|typedef|TT_BDFRec
DECL|typedef|TT_BDF
name|TT_BDFRec
operator|,
typedef|*
name|TT_BDF
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* TT_CONFIG_OPTION_BDF */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                  ORIGINAL TT_FACE CLASS DEFINITION                ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/***                                                                   ***/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
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
comment|/* This structure/class is defined here because it is common to the      */
end_comment
begin_comment
comment|/* following formats: TTF, OpenType-TT, and OpenType-CFF.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Note, however, that the classes TT_Size and TT_GlyphSlot are not      */
end_comment
begin_comment
comment|/* shared between font drivers, and are thus defined in `ttobjs.h'.      */
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
comment|/*    TT_Face                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a TrueType face/font object.  A TT_Face encapsulates   */
end_comment
begin_comment
comment|/*    the resolution and scaling independent parts of a TrueType font    */
end_comment
begin_comment
comment|/*    resource.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The TT_Face structure is also used as a `parent class' for the     */
end_comment
begin_comment
comment|/*    OpenType-CFF class (T2_Face).                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|TT_Face
typedef|typedef
name|struct
name|TT_FaceRec_
modifier|*
name|TT_Face
typedef|;
end_typedef
begin_comment
comment|/* a function type used for the truetype bytecode interpreter hooks */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Interpreter
modifier|*
name|TT_Interpreter
function_decl|)
parameter_list|(
name|void
modifier|*
name|exec_context
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* forward declaration */
end_comment
begin_typedef
DECL|typedef|TT_Loader
typedef|typedef
name|struct
name|TT_LoaderRec_
modifier|*
name|TT_Loader
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    TT_Loader_GotoTableFunc                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Seeks a stream to the start of a given TrueType table.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tag    :: A 4-byte tag used to name the table.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream :: The input stream.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    length :: The length of the table in bytes.  Set to 0 if not       */
end_comment
begin_comment
comment|/*              needed.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The stream cursor must be at the font file's origin.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Loader_GotoTableFunc
modifier|*
name|TT_Loader_GotoTableFunc
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_ULong
name|tag
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_ULong
modifier|*
name|length
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    TT_Loader_StartGlyphFunc                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Seeks a stream to the start of a given glyph element, and opens a  */
end_comment
begin_comment
comment|/*    frame for it.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    loader      :: The current TrueType glyph loader object.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph index :: The index of the glyph to access.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    offset      :: The offset of the glyph according to the            */
end_comment
begin_comment
comment|/*                   `locations' table.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    byte_count  :: The size of the frame in bytes.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function is normally equivalent to FT_STREAM_SEEK(offset)     */
end_comment
begin_comment
comment|/*    followed by FT_FRAME_ENTER(byte_count) with the loader's stream,   */
end_comment
begin_comment
comment|/*    but alternative formats (e.g. compressed ones) might use something */
end_comment
begin_comment
comment|/*    different.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Loader_StartGlyphFunc
modifier|*
name|TT_Loader_StartGlyphFunc
function_decl|)
parameter_list|(
name|TT_Loader
name|loader
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_ULong
name|offset
parameter_list|,
name|FT_UInt
name|byte_count
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    TT_Loader_ReadGlyphFunc                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Reads one glyph element (its header, a simple glyph, or a          */
end_comment
begin_comment
comment|/*    composite) from the loader's current stream frame.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    loader :: The current TrueType glyph loader object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Loader_ReadGlyphFunc
modifier|*
name|TT_Loader_ReadGlyphFunc
function_decl|)
parameter_list|(
name|TT_Loader
name|loader
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    TT_Loader_EndGlyphFunc                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Closes the current loader stream frame for the glyph.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    loader :: The current TrueType glyph loader object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|TT_Loader_EndGlyphFunc
modifier|*
name|TT_Loader_EndGlyphFunc
function_decl|)
parameter_list|(
name|TT_Loader
name|loader
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                         TrueType Face Type                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    TT_Face                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The TrueType face class.  These objects model the resolution and   */
end_comment
begin_comment
comment|/*    point-size independent data found in a TrueType font file.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    root                 :: The base FT_Face structure, managed by the */
end_comment
begin_comment
comment|/*                            base layer.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ttc_header           :: The TrueType collection header, used when  */
end_comment
begin_comment
comment|/*                            the file is a `ttc' rather than a `ttf'.   */
end_comment
begin_comment
comment|/*                            For ordinary font files, the field         */
end_comment
begin_comment
comment|/*                            `ttc_header.count' is set to 0.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format_tag           :: The font format tag.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_tables           :: The number of TrueType tables in this font */
end_comment
begin_comment
comment|/*                            file.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    dir_tables           :: The directory of TrueType tables for this  */
end_comment
begin_comment
comment|/*                            font file.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    header               :: The font's font header (`head' table).     */
end_comment
begin_comment
comment|/*                            Read on font opening.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horizontal           :: The font's horizontal header (`hhea'       */
end_comment
begin_comment
comment|/*                            table).  This field also contains the      */
end_comment
begin_comment
comment|/*                            associated horizontal metrics table        */
end_comment
begin_comment
comment|/*                            (`hmtx').                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_profile          :: The font's maximum profile table.  Read on */
end_comment
begin_comment
comment|/*                            font opening.  Note that some maximum      */
end_comment
begin_comment
comment|/*                            values cannot be taken directly from this  */
end_comment
begin_comment
comment|/*                            table.  We thus define additional fields   */
end_comment
begin_comment
comment|/*                            below to hold the computed maxima.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertical_info        :: A boolean which is set when the font file  */
end_comment
begin_comment
comment|/*                            contains vertical metrics.  If not, the    */
end_comment
begin_comment
comment|/*                            value of the `vertical' field is           */
end_comment
begin_comment
comment|/*                            undefined.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertical             :: The font's vertical header (`vhea' table). */
end_comment
begin_comment
comment|/*                            This field also contains the associated    */
end_comment
begin_comment
comment|/*                            vertical metrics table (`vmtx'), if found. */
end_comment
begin_comment
comment|/*                            IMPORTANT: The contents of this field is   */
end_comment
begin_comment
comment|/*                            undefined if the `verticalInfo' field is   */
end_comment
begin_comment
comment|/*                            unset.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_names            :: The number of name records within this     */
end_comment
begin_comment
comment|/*                            TrueType font.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    name_table           :: The table of name records (`name').        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    os2                  :: The font's OS/2 table (`OS/2').            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    postscript           :: The font's PostScript table (`post'        */
end_comment
begin_comment
comment|/*                            table).  The PostScript glyph names are    */
end_comment
begin_comment
comment|/*                            not loaded by the driver on face opening.  */
end_comment
begin_comment
comment|/*                            See the `ttpost' module for more details.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cmap_table           :: Address of the face's `cmap' SFNT table    */
end_comment
begin_comment
comment|/*                            in memory (it's an extracted frame).       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cmap_size            :: The size in bytes of the `cmap_table'      */
end_comment
begin_comment
comment|/*                            described above.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    goto_table           :: A function called by each TrueType table   */
end_comment
begin_comment
comment|/*                            loader to position a stream's cursor to    */
end_comment
begin_comment
comment|/*                            the start of a given table according to    */
end_comment
begin_comment
comment|/*                            its tag.  It defaults to TT_Goto_Face but  */
end_comment
begin_comment
comment|/*                            can be different for strange formats (e.g. */
end_comment
begin_comment
comment|/*                            Type 42).                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    access_glyph_frame   :: A function used to access the frame of a   */
end_comment
begin_comment
comment|/*                            given glyph within the face's font file.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    forget_glyph_frame   :: A function used to forget the frame of a   */
end_comment
begin_comment
comment|/*                            given glyph when all data has been loaded. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    read_glyph_header    :: A function used to read a glyph header.    */
end_comment
begin_comment
comment|/*                            It must be called between an `access' and  */
end_comment
begin_comment
comment|/*                            `forget'.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    read_simple_glyph    :: A function used to read a simple glyph.    */
end_comment
begin_comment
comment|/*                            It must be called after the header was     */
end_comment
begin_comment
comment|/*                            read, and before the `forget'.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    read_composite_glyph :: A function used to read a composite glyph. */
end_comment
begin_comment
comment|/*                            It must be called after the header was     */
end_comment
begin_comment
comment|/*                            read, and before the `forget'.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    sfnt                 :: A pointer to the SFNT service.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    psnames              :: A pointer to the PostScript names service. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    hdmx                 :: The face's horizontal device metrics       */
end_comment
begin_comment
comment|/*                            (`hdmx' table).  This table is optional in */
end_comment
begin_comment
comment|/*                            TrueType/OpenType fonts.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gasp                 :: The grid-fitting and scaling properties    */
end_comment
begin_comment
comment|/*                            table (`gasp').  This table is optional in */
end_comment
begin_comment
comment|/*                            TrueType/OpenType fonts.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pclt                 :: The `pclt' SFNT table.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_sbit_strikes     :: The number of sbit strikes, i.e., bitmap   */
end_comment
begin_comment
comment|/*                            sizes, embedded in this font.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    sbit_strikes         :: An array of sbit strikes embedded in this  */
end_comment
begin_comment
comment|/*                            font.  This table is optional in a         */
end_comment
begin_comment
comment|/*                            TrueType/OpenType font.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_sbit_scales      :: The number of sbit scales for this font.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    sbit_scales          :: Array of sbit scales embedded in this      */
end_comment
begin_comment
comment|/*                            font.  This table is optional in a         */
end_comment
begin_comment
comment|/*                            TrueType/OpenType font.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    postscript_names     :: A table used to store the Postscript names */
end_comment
begin_comment
comment|/*                            of  the glyphs for this font.  See the     */
end_comment
begin_comment
comment|/*                            file  `ttconfig.h' for comments on the     */
end_comment
begin_comment
comment|/*                            TT_CONFIG_OPTION_POSTSCRIPT_NAMES option.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_locations        :: The number of glyph locations in this      */
end_comment
begin_comment
comment|/*                            TrueType file.  This should be             */
end_comment
begin_comment
comment|/*                            identical to the number of glyphs.         */
end_comment
begin_comment
comment|/*                            Ignored for Type 2 fonts.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_locations      :: An array of longs.  These are offsets to   */
end_comment
begin_comment
comment|/*                            glyph data within the `glyf' table.        */
end_comment
begin_comment
comment|/*                            Ignored for Type 2 font faces.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyf_len             :: The length of the `glyf' table.  Needed    */
end_comment
begin_comment
comment|/*                            for malformed `loca' tables.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    font_program_size    :: Size in bytecodes of the face's font       */
end_comment
begin_comment
comment|/*                            program.  0 if none defined.  Ignored for  */
end_comment
begin_comment
comment|/*                            Type 2 fonts.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    font_program         :: The face's font program (bytecode stream)  */
end_comment
begin_comment
comment|/*                            executed at load time, also used during    */
end_comment
begin_comment
comment|/*                            glyph rendering.  Comes from the `fpgm'    */
end_comment
begin_comment
comment|/*                            table.  Ignored for Type 2 font fonts.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cvt_program_size     :: The size in bytecodes of the face's cvt    */
end_comment
begin_comment
comment|/*                            program.  Ignored for Type 2 fonts.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cvt_program          :: The face's cvt program (bytecode stream)   */
end_comment
begin_comment
comment|/*                            executed each time an instance/size is     */
end_comment
begin_comment
comment|/*                            changed/reset.  Comes from the `prep'      */
end_comment
begin_comment
comment|/*                            table.  Ignored for Type 2 fonts.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cvt_size             :: Size of the control value table (in        */
end_comment
begin_comment
comment|/*                            entries).   Ignored for Type 2 fonts.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cvt                  :: The face's original control value table.   */
end_comment
begin_comment
comment|/*                            Coordinates are expressed in unscaled font */
end_comment
begin_comment
comment|/*                            units.  Comes from the `cvt ' table.       */
end_comment
begin_comment
comment|/*                            Ignored for Type 2 fonts.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_kern_pairs       :: The number of kerning pairs present in the */
end_comment
begin_comment
comment|/*                            font file.  The engine only loads the      */
end_comment
begin_comment
comment|/*                            first horizontal format 0 kern table it    */
end_comment
begin_comment
comment|/*                            finds in the font file.  Ignored for       */
end_comment
begin_comment
comment|/*                            Type 2 fonts.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    kern_table_index     :: The index of the kerning table in the font */
end_comment
begin_comment
comment|/*                            kerning directory.  Ignored for Type 2     */
end_comment
begin_comment
comment|/*                            fonts.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    interpreter          :: A pointer to the TrueType bytecode         */
end_comment
begin_comment
comment|/*                            interpreters field is also used to hook    */
end_comment
begin_comment
comment|/*                            the debugger in `ttdebug'.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    unpatented_hinting   :: If true, use only unpatented methods in    */
end_comment
begin_comment
comment|/*                            the bytecode interpreter.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    doblend              :: A boolean which is set if the font should  */
end_comment
begin_comment
comment|/*                            be blended (this is for GX var).           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    blend                :: Contains the data needed to control GX     */
end_comment
begin_comment
comment|/*                            variation tables (rather like Multiple     */
end_comment
begin_comment
comment|/*                            Master data).                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    extra                :: Reserved for third-party font drivers.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    postscript_name      :: The PS name of the font.  Used by the      */
end_comment
begin_comment
comment|/*                            postscript name service.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_FaceRec_
typedef|typedef
struct|struct
name|TT_FaceRec_
block|{
DECL|member|root
name|FT_FaceRec
name|root
decl_stmt|;
DECL|member|ttc_header
name|TTC_HeaderRec
name|ttc_header
decl_stmt|;
DECL|member|format_tag
name|FT_ULong
name|format_tag
decl_stmt|;
DECL|member|num_tables
name|FT_UShort
name|num_tables
decl_stmt|;
DECL|member|dir_tables
name|TT_Table
name|dir_tables
decl_stmt|;
DECL|member|header
name|TT_Header
name|header
decl_stmt|;
comment|/* TrueType header table          */
DECL|member|horizontal
name|TT_HoriHeader
name|horizontal
decl_stmt|;
comment|/* TrueType horizontal header     */
DECL|member|max_profile
name|TT_MaxProfile
name|max_profile
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
DECL|member|max_components
name|FT_ULong
name|max_components
decl_stmt|;
comment|/* stubbed to 0 */
endif|#
directive|endif
DECL|member|vertical_info
name|FT_Bool
name|vertical_info
decl_stmt|;
DECL|member|vertical
name|TT_VertHeader
name|vertical
decl_stmt|;
comment|/* TT Vertical header, if present */
DECL|member|num_names
name|FT_UShort
name|num_names
decl_stmt|;
comment|/* number of name records  */
DECL|member|name_table
name|TT_NameTableRec
name|name_table
decl_stmt|;
comment|/* name table              */
DECL|member|os2
name|TT_OS2
name|os2
decl_stmt|;
comment|/* TrueType OS/2 table            */
DECL|member|postscript
name|TT_Postscript
name|postscript
decl_stmt|;
comment|/* TrueType Postscript table      */
DECL|member|cmap_table
name|FT_Byte
modifier|*
name|cmap_table
decl_stmt|;
comment|/* extracted `cmap' table */
DECL|member|cmap_size
name|FT_ULong
name|cmap_size
decl_stmt|;
DECL|member|goto_table
name|TT_Loader_GotoTableFunc
name|goto_table
decl_stmt|;
DECL|member|access_glyph_frame
name|TT_Loader_StartGlyphFunc
name|access_glyph_frame
decl_stmt|;
DECL|member|forget_glyph_frame
name|TT_Loader_EndGlyphFunc
name|forget_glyph_frame
decl_stmt|;
DECL|member|read_glyph_header
name|TT_Loader_ReadGlyphFunc
name|read_glyph_header
decl_stmt|;
DECL|member|read_simple_glyph
name|TT_Loader_ReadGlyphFunc
name|read_simple_glyph
decl_stmt|;
DECL|member|read_composite_glyph
name|TT_Loader_ReadGlyphFunc
name|read_composite_glyph
decl_stmt|;
comment|/* a typeless pointer to the SFNT_Interface table used to load */
comment|/* the basic TrueType tables in the face object                */
DECL|member|sfnt
name|void
modifier|*
name|sfnt
decl_stmt|;
comment|/* a typeless pointer to the FT_Service_PsCMapsRec table used to */
comment|/* handle glyph names<-> unicode& Mac values                   */
DECL|member|psnames
name|void
modifier|*
name|psnames
decl_stmt|;
comment|/***********************************************************************/
comment|/*                                                                     */
comment|/* Optional TrueType/OpenType tables                                   */
comment|/*                                                                     */
comment|/***********************************************************************/
comment|/* horizontal device metrics */
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
DECL|member|hdmx
name|TT_HdmxRec
name|hdmx
decl_stmt|;
endif|#
directive|endif
comment|/* grid-fitting and scaling table */
DECL|member|gasp
name|TT_GaspRec
name|gasp
decl_stmt|;
comment|/* the `gasp' table */
comment|/* PCL 5 table */
DECL|member|pclt
name|TT_PCLT
name|pclt
decl_stmt|;
comment|/* embedded bitmaps support */
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
DECL|member|num_sbit_strikes
name|FT_ULong
name|num_sbit_strikes
decl_stmt|;
DECL|member|sbit_strikes
name|TT_SBit_Strike
name|sbit_strikes
decl_stmt|;
endif|#
directive|endif
DECL|member|num_sbit_scales
name|FT_ULong
name|num_sbit_scales
decl_stmt|;
DECL|member|sbit_scales
name|TT_SBit_Scale
name|sbit_scales
decl_stmt|;
comment|/* postscript names table */
DECL|member|postscript_names
name|TT_Post_NamesRec
name|postscript_names
decl_stmt|;
comment|/***********************************************************************/
comment|/*                                                                     */
comment|/* TrueType-specific fields (ignored by the OTF-Type2 driver)          */
comment|/*                                                                     */
comment|/***********************************************************************/
comment|/* the glyph locations */
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
DECL|member|num_locations_stub
name|FT_UShort
name|num_locations_stub
decl_stmt|;
DECL|member|glyph_locations_stub
name|FT_Long
modifier|*
name|glyph_locations_stub
decl_stmt|;
endif|#
directive|endif
comment|/* the font program, if any */
DECL|member|font_program_size
name|FT_ULong
name|font_program_size
decl_stmt|;
DECL|member|font_program
name|FT_Byte
modifier|*
name|font_program
decl_stmt|;
comment|/* the cvt program, if any */
DECL|member|cvt_program_size
name|FT_ULong
name|cvt_program_size
decl_stmt|;
DECL|member|cvt_program
name|FT_Byte
modifier|*
name|cvt_program
decl_stmt|;
comment|/* the original, unscaled, control value table */
DECL|member|cvt_size
name|FT_ULong
name|cvt_size
decl_stmt|;
DECL|member|cvt
name|FT_Short
modifier|*
name|cvt
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
comment|/* the format 0 kerning table, if any */
DECL|member|num_kern_pairs
name|FT_Int
name|num_kern_pairs
decl_stmt|;
DECL|member|kern_table_index
name|FT_Int
name|kern_table_index
decl_stmt|;
DECL|member|kern_pairs
name|TT_Kern0_Pair
name|kern_pairs
decl_stmt|;
endif|#
directive|endif
comment|/* A pointer to the bytecode interpreter to use.  This is also */
comment|/* used to hook the debugger for the `ttdebug' utility.        */
DECL|member|interpreter
name|TT_Interpreter
name|interpreter
decl_stmt|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_UNPATENTED_HINTING
comment|/* Use unpatented hinting only. */
DECL|member|unpatented_hinting
name|FT_Bool
name|unpatented_hinting
decl_stmt|;
endif|#
directive|endif
comment|/***********************************************************************/
comment|/*                                                                     */
comment|/* Other tables or fields. This is used by derivative formats like     */
comment|/* OpenType.                                                           */
comment|/*                                                                     */
comment|/***********************************************************************/
DECL|member|extra
name|FT_Generic
name|extra
decl_stmt|;
DECL|member|postscript_name
specifier|const
name|char
modifier|*
name|postscript_name
decl_stmt|;
comment|/* since version 2.1.8, but was originally placed after */
comment|/* `glyph_locations_stub'                               */
DECL|member|glyf_len
name|FT_ULong
name|glyf_len
decl_stmt|;
comment|/* since version 2.1.8, but was originally placed before `extra' */
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_GX_VAR_SUPPORT
DECL|member|doblend
name|FT_Bool
name|doblend
decl_stmt|;
DECL|member|blend
name|GX_Blend
name|blend
decl_stmt|;
endif|#
directive|endif
comment|/* since version 2.2 */
DECL|member|horz_metrics
name|FT_Byte
modifier|*
name|horz_metrics
decl_stmt|;
DECL|member|horz_metrics_size
name|FT_ULong
name|horz_metrics_size
decl_stmt|;
DECL|member|vert_metrics
name|FT_Byte
modifier|*
name|vert_metrics
decl_stmt|;
DECL|member|vert_metrics_size
name|FT_ULong
name|vert_metrics_size
decl_stmt|;
DECL|member|num_locations
name|FT_ULong
name|num_locations
decl_stmt|;
comment|/* in broken TTF, gid> 0xFFFF */
DECL|member|glyph_locations
name|FT_Byte
modifier|*
name|glyph_locations
decl_stmt|;
DECL|member|hdmx_table
name|FT_Byte
modifier|*
name|hdmx_table
decl_stmt|;
DECL|member|hdmx_table_size
name|FT_ULong
name|hdmx_table_size
decl_stmt|;
DECL|member|hdmx_record_count
name|FT_UInt
name|hdmx_record_count
decl_stmt|;
DECL|member|hdmx_record_size
name|FT_ULong
name|hdmx_record_size
decl_stmt|;
DECL|member|hdmx_record_sizes
name|FT_Byte
modifier|*
name|hdmx_record_sizes
decl_stmt|;
DECL|member|sbit_table
name|FT_Byte
modifier|*
name|sbit_table
decl_stmt|;
DECL|member|sbit_table_size
name|FT_ULong
name|sbit_table_size
decl_stmt|;
DECL|member|sbit_num_strikes
name|FT_UInt
name|sbit_num_strikes
decl_stmt|;
DECL|member|kern_table
name|FT_Byte
modifier|*
name|kern_table
decl_stmt|;
DECL|member|kern_table_size
name|FT_ULong
name|kern_table_size
decl_stmt|;
DECL|member|num_kern_tables
name|FT_UInt
name|num_kern_tables
decl_stmt|;
DECL|member|kern_avail_bits
name|FT_UInt32
name|kern_avail_bits
decl_stmt|;
DECL|member|kern_order_bits
name|FT_UInt32
name|kern_order_bits
decl_stmt|;
ifdef|#
directive|ifdef
name|TT_CONFIG_OPTION_BDF
DECL|member|bdf
name|TT_BDFRec
name|bdf
decl_stmt|;
endif|#
directive|endif
comment|/* TT_CONFIG_OPTION_BDF */
comment|/* since 2.3.0 */
DECL|member|horz_metrics_offset
name|FT_ULong
name|horz_metrics_offset
decl_stmt|;
DECL|member|vert_metrics_offset
name|FT_ULong
name|vert_metrics_offset
decl_stmt|;
block|}
DECL|typedef|TT_FaceRec
name|TT_FaceRec
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Struct>                                                             */
end_comment
begin_comment
comment|/*     TT_GlyphZoneRec                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                        */
end_comment
begin_comment
comment|/*     A glyph zone is used to load, scale and hint glyph outline        */
end_comment
begin_comment
comment|/*     coordinates.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                             */
end_comment
begin_comment
comment|/*     memory       :: A handle to the memory manager.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     max_points   :: The maximal size in points of the zone.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     max_contours :: Max size in links contours of the zone.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     n_points     :: The current number of points in the zone.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     n_contours   :: The current number of contours in the zone.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     org          :: The original glyph coordinates (font              */
end_comment
begin_comment
comment|/*                     units/scaled).                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     cur          :: The current glyph coordinates (scaled/hinted).    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     tags         :: The point control tags.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     contours     :: The contours end points.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     first_point  :: Offset of the current subglyph's first point.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|TT_GlyphZoneRec_
typedef|typedef
struct|struct
name|TT_GlyphZoneRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|max_points
name|FT_UShort
name|max_points
decl_stmt|;
DECL|member|max_contours
name|FT_UShort
name|max_contours
decl_stmt|;
DECL|member|n_points
name|FT_UShort
name|n_points
decl_stmt|;
comment|/* number of points in zone    */
DECL|member|n_contours
name|FT_Short
name|n_contours
decl_stmt|;
comment|/* number of contours          */
DECL|member|org
name|FT_Vector
modifier|*
name|org
decl_stmt|;
comment|/* original point coordinates  */
DECL|member|cur
name|FT_Vector
modifier|*
name|cur
decl_stmt|;
comment|/* current point coordinates   */
DECL|member|orus
name|FT_Vector
modifier|*
name|orus
decl_stmt|;
comment|/* original (unscaled) point coordinates */
DECL|member|tags
name|FT_Byte
modifier|*
name|tags
decl_stmt|;
comment|/* current touch flags         */
DECL|member|contours
name|FT_UShort
modifier|*
name|contours
decl_stmt|;
comment|/* contour end points          */
DECL|member|first_point
name|FT_UShort
name|first_point
decl_stmt|;
comment|/* offset of first (#0) point  */
block|}
DECL|typedef|TT_GlyphZoneRec
DECL|typedef|TT_GlyphZone
name|TT_GlyphZoneRec
operator|,
typedef|*
name|TT_GlyphZone
typedef|;
end_typedef
begin_comment
comment|/* handle to execution context */
end_comment
begin_typedef
DECL|typedef|TT_ExecContext
typedef|typedef
name|struct
name|TT_ExecContextRec_
modifier|*
name|TT_ExecContext
typedef|;
end_typedef
begin_comment
comment|/* glyph loader structure */
end_comment
begin_typedef
DECL|struct|TT_LoaderRec_
typedef|typedef
struct|struct
name|TT_LoaderRec_
block|{
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
DECL|member|size
name|FT_Size
name|size
decl_stmt|;
DECL|member|glyph
name|FT_GlyphSlot
name|glyph
decl_stmt|;
DECL|member|gloader
name|FT_GlyphLoader
name|gloader
decl_stmt|;
DECL|member|load_flags
name|FT_ULong
name|load_flags
decl_stmt|;
DECL|member|glyph_index
name|FT_UInt
name|glyph_index
decl_stmt|;
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
DECL|member|byte_len
name|FT_Int
name|byte_len
decl_stmt|;
DECL|member|n_contours
name|FT_Short
name|n_contours
decl_stmt|;
DECL|member|bbox
name|FT_BBox
name|bbox
decl_stmt|;
DECL|member|left_bearing
name|FT_Int
name|left_bearing
decl_stmt|;
DECL|member|advance
name|FT_Int
name|advance
decl_stmt|;
DECL|member|linear
name|FT_Int
name|linear
decl_stmt|;
DECL|member|linear_def
name|FT_Bool
name|linear_def
decl_stmt|;
DECL|member|preserve_pps
name|FT_Bool
name|preserve_pps
decl_stmt|;
DECL|member|pp1
name|FT_Vector
name|pp1
decl_stmt|;
DECL|member|pp2
name|FT_Vector
name|pp2
decl_stmt|;
DECL|member|glyf_offset
name|FT_ULong
name|glyf_offset
decl_stmt|;
comment|/* the zone where we load our glyphs */
DECL|member|base
name|TT_GlyphZoneRec
name|base
decl_stmt|;
DECL|member|zone
name|TT_GlyphZoneRec
name|zone
decl_stmt|;
DECL|member|exec
name|TT_ExecContext
name|exec
decl_stmt|;
DECL|member|instructions
name|FT_Byte
modifier|*
name|instructions
decl_stmt|;
DECL|member|ins_pos
name|FT_ULong
name|ins_pos
decl_stmt|;
comment|/* for possible extensibility in other formats */
DECL|member|other
name|void
modifier|*
name|other
decl_stmt|;
comment|/* since version 2.1.8 */
DECL|member|top_bearing
name|FT_Int
name|top_bearing
decl_stmt|;
DECL|member|vadvance
name|FT_Int
name|vadvance
decl_stmt|;
DECL|member|pp3
name|FT_Vector
name|pp3
decl_stmt|;
DECL|member|pp4
name|FT_Vector
name|pp4
decl_stmt|;
comment|/* since version 2.2.1 */
DECL|member|cursor
name|FT_Byte
modifier|*
name|cursor
decl_stmt|;
DECL|member|limit
name|FT_Byte
modifier|*
name|limit
decl_stmt|;
block|}
DECL|typedef|TT_LoaderRec
name|TT_LoaderRec
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
comment|/* __TTTYPES_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
