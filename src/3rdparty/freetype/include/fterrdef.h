begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  fterrdef.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType error codes (specification).                                */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2004, 2006, 2007, 2010-2013 by                         */
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
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*****                                                         *****/
end_comment
begin_comment
comment|/*****                LIST OF ERROR CODES/MESSAGES             *****/
end_comment
begin_comment
comment|/*****                                                         *****/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/*******************************************************************/
end_comment
begin_comment
comment|/* You need to define both FT_ERRORDEF_ and FT_NOERRORDEF_ before */
end_comment
begin_comment
comment|/* including this file.                                           */
end_comment
begin_comment
comment|/* generic errors */
end_comment
begin_macro
name|FT_NOERRORDEF_
argument_list|(
argument|Ok
argument_list|,
literal|0x00
argument_list|,
literal|"no error"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Cannot_Open_Resource
argument_list|,
literal|0x01
argument_list|,
literal|"cannot open resource"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Unknown_File_Format
argument_list|,
literal|0x02
argument_list|,
literal|"unknown file format"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_File_Format
argument_list|,
literal|0x03
argument_list|,
literal|"broken file"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Version
argument_list|,
literal|0x04
argument_list|,
literal|"invalid FreeType version"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Lower_Module_Version
argument_list|,
literal|0x05
argument_list|,
literal|"module version is too low"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Argument
argument_list|,
literal|0x06
argument_list|,
literal|"invalid argument"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Unimplemented_Feature
argument_list|,
literal|0x07
argument_list|,
literal|"unimplemented feature"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Table
argument_list|,
literal|0x08
argument_list|,
literal|"broken table"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Offset
argument_list|,
literal|0x09
argument_list|,
literal|"broken offset within table"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Array_Too_Large
argument_list|,
literal|0x0A
argument_list|,
literal|"array allocation size too large"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Module
argument_list|,
literal|0x0B
argument_list|,
literal|"missing module"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Property
argument_list|,
literal|0x0C
argument_list|,
literal|"missing property"
argument_list|)
end_macro
begin_comment
comment|/* glyph/character errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Glyph_Index
argument_list|,
literal|0x10
argument_list|,
literal|"invalid glyph index"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Character_Code
argument_list|,
literal|0x11
argument_list|,
literal|"invalid character code"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Glyph_Format
argument_list|,
literal|0x12
argument_list|,
literal|"unsupported glyph image format"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Cannot_Render_Glyph
argument_list|,
literal|0x13
argument_list|,
literal|"cannot render this glyph format"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Outline
argument_list|,
literal|0x14
argument_list|,
literal|"invalid outline"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Composite
argument_list|,
literal|0x15
argument_list|,
literal|"invalid composite glyph"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Many_Hints
argument_list|,
literal|0x16
argument_list|,
literal|"too many hints"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Pixel_Size
argument_list|,
literal|0x17
argument_list|,
literal|"invalid pixel size"
argument_list|)
end_macro
begin_comment
comment|/* handle errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Handle
argument_list|,
literal|0x20
argument_list|,
literal|"invalid object handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Library_Handle
argument_list|,
literal|0x21
argument_list|,
literal|"invalid library handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Driver_Handle
argument_list|,
literal|0x22
argument_list|,
literal|"invalid module handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Face_Handle
argument_list|,
literal|0x23
argument_list|,
literal|"invalid face handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Size_Handle
argument_list|,
literal|0x24
argument_list|,
literal|"invalid size handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Slot_Handle
argument_list|,
literal|0x25
argument_list|,
literal|"invalid glyph slot handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_CharMap_Handle
argument_list|,
literal|0x26
argument_list|,
literal|"invalid charmap handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Cache_Handle
argument_list|,
literal|0x27
argument_list|,
literal|"invalid cache manager handle"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Stream_Handle
argument_list|,
literal|0x28
argument_list|,
literal|"invalid stream handle"
argument_list|)
end_macro
begin_comment
comment|/* driver errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Many_Drivers
argument_list|,
literal|0x30
argument_list|,
literal|"too many modules"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Many_Extensions
argument_list|,
literal|0x31
argument_list|,
literal|"too many extensions"
argument_list|)
end_macro
begin_comment
comment|/* memory errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Out_Of_Memory
argument_list|,
literal|0x40
argument_list|,
literal|"out of memory"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Unlisted_Object
argument_list|,
literal|0x41
argument_list|,
literal|"unlisted object"
argument_list|)
end_macro
begin_comment
comment|/* stream errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Cannot_Open_Stream
argument_list|,
literal|0x51
argument_list|,
literal|"cannot open stream"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Stream_Seek
argument_list|,
literal|0x52
argument_list|,
literal|"invalid stream seek"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Stream_Skip
argument_list|,
literal|0x53
argument_list|,
literal|"invalid stream skip"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Stream_Read
argument_list|,
literal|0x54
argument_list|,
literal|"invalid stream read"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Stream_Operation
argument_list|,
literal|0x55
argument_list|,
literal|"invalid stream operation"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Frame_Operation
argument_list|,
literal|0x56
argument_list|,
literal|"invalid frame operation"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Nested_Frame_Access
argument_list|,
literal|0x57
argument_list|,
literal|"nested frame access"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Frame_Read
argument_list|,
literal|0x58
argument_list|,
literal|"invalid frame read"
argument_list|)
end_macro
begin_comment
comment|/* raster errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Raster_Uninitialized
argument_list|,
literal|0x60
argument_list|,
literal|"raster uninitialized"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Raster_Corrupted
argument_list|,
literal|0x61
argument_list|,
literal|"raster corrupted"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Raster_Overflow
argument_list|,
literal|0x62
argument_list|,
literal|"raster overflow"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Raster_Negative_Height
argument_list|,
literal|0x63
argument_list|,
literal|"negative height while rastering"
argument_list|)
end_macro
begin_comment
comment|/* cache errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Many_Caches
argument_list|,
literal|0x70
argument_list|,
literal|"too many registered caches"
argument_list|)
end_macro
begin_comment
comment|/* TrueType and SFNT errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Opcode
argument_list|,
literal|0x80
argument_list|,
literal|"invalid opcode"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Few_Arguments
argument_list|,
literal|0x81
argument_list|,
literal|"too few arguments"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Stack_Overflow
argument_list|,
literal|0x82
argument_list|,
literal|"stack overflow"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Code_Overflow
argument_list|,
literal|0x83
argument_list|,
literal|"code overflow"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Bad_Argument
argument_list|,
literal|0x84
argument_list|,
literal|"bad argument"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Divide_By_Zero
argument_list|,
literal|0x85
argument_list|,
literal|"division by zero"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Reference
argument_list|,
literal|0x86
argument_list|,
literal|"invalid reference"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Debug_OpCode
argument_list|,
literal|0x87
argument_list|,
literal|"found debug opcode"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|ENDF_In_Exec_Stream
argument_list|,
literal|0x88
argument_list|,
literal|"found ENDF opcode in execution stream"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Nested_DEFS
argument_list|,
literal|0x89
argument_list|,
literal|"nested DEFS"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_CodeRange
argument_list|,
literal|0x8A
argument_list|,
literal|"invalid code range"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Execution_Too_Long
argument_list|,
literal|0x8B
argument_list|,
literal|"execution context too long"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Many_Function_Defs
argument_list|,
literal|0x8C
argument_list|,
literal|"too many function definitions"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Too_Many_Instruction_Defs
argument_list|,
literal|0x8D
argument_list|,
literal|"too many instruction definitions"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Table_Missing
argument_list|,
literal|0x8E
argument_list|,
literal|"SFNT font table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Horiz_Header_Missing
argument_list|,
literal|0x8F
argument_list|,
literal|"horizontal header (hhea) table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Locations_Missing
argument_list|,
literal|0x90
argument_list|,
literal|"locations (loca) table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Name_Table_Missing
argument_list|,
literal|0x91
argument_list|,
literal|"name table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|CMap_Table_Missing
argument_list|,
literal|0x92
argument_list|,
literal|"character map (cmap) table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Hmtx_Table_Missing
argument_list|,
literal|0x93
argument_list|,
literal|"horizontal metrics (hmtx) table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Post_Table_Missing
argument_list|,
literal|0x94
argument_list|,
literal|"PostScript (post) table missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Horiz_Metrics
argument_list|,
literal|0x95
argument_list|,
literal|"invalid horizontal metrics"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_CharMap_Format
argument_list|,
literal|0x96
argument_list|,
literal|"invalid character map (cmap) format"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_PPem
argument_list|,
literal|0x97
argument_list|,
literal|"invalid ppem value"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Vert_Metrics
argument_list|,
literal|0x98
argument_list|,
literal|"invalid vertical metrics"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Could_Not_Find_Context
argument_list|,
literal|0x99
argument_list|,
literal|"could not find context"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Post_Table_Format
argument_list|,
literal|0x9A
argument_list|,
literal|"invalid PostScript (post) table format"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Invalid_Post_Table
argument_list|,
literal|0x9B
argument_list|,
literal|"invalid PostScript (post) table"
argument_list|)
end_macro
begin_comment
comment|/* CFF, CID, and Type 1 errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Syntax_Error
argument_list|,
literal|0xA0
argument_list|,
literal|"opcode syntax error"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Stack_Underflow
argument_list|,
literal|0xA1
argument_list|,
literal|"argument stack underflow"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Ignore
argument_list|,
literal|0xA2
argument_list|,
literal|"ignore"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|No_Unicode_Glyph_Name
argument_list|,
literal|0xA3
argument_list|,
literal|"no Unicode glyph name found"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Glyph_Too_Big
argument_list|,
literal|0xA4
argument_list|,
literal|"glyph to big for hinting"
argument_list|)
end_macro
begin_comment
comment|/* BDF errors */
end_comment
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Startfont_Field
argument_list|,
literal|0xB0
argument_list|,
literal|"`STARTFONT' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Font_Field
argument_list|,
literal|0xB1
argument_list|,
literal|"`FONT' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Size_Field
argument_list|,
literal|0xB2
argument_list|,
literal|"`SIZE' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Fontboundingbox_Field
argument_list|,
literal|0xB3
argument_list|,
literal|"`FONTBOUNDINGBOX' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Chars_Field
argument_list|,
literal|0xB4
argument_list|,
literal|"`CHARS' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Startchar_Field
argument_list|,
literal|0xB5
argument_list|,
literal|"`STARTCHAR' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Encoding_Field
argument_list|,
literal|0xB6
argument_list|,
literal|"`ENCODING' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Missing_Bbx_Field
argument_list|,
literal|0xB7
argument_list|,
literal|"`BBX' field missing"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Bbx_Too_Big
argument_list|,
literal|0xB8
argument_list|,
literal|"`BBX' too big"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Corrupted_Font_Header
argument_list|,
literal|0xB9
argument_list|,
literal|"Font header corrupted or missing fields"
argument_list|)
end_macro
begin_macro
name|FT_ERRORDEF_
argument_list|(
argument|Corrupted_Font_Glyphs
argument_list|,
literal|0xBA
argument_list|,
literal|"Font glyphs corrupted or missing fields"
argument_list|)
end_macro
begin_comment
comment|/* END */
end_comment
end_unit
