begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  freetype.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType high-level API and common types (specification only).       */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009,   */
end_comment
begin_comment
comment|/*            2010 by                                                      */
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
name|FT_FREETYPE_H
end_ifndef
begin_error
error|#
directive|error
literal|"`ft2build.h' hasn't been included yet!"
end_error
begin_error
error|#
directive|error
literal|"Please always use macros to include FreeType header files."
end_error
begin_error
error|#
directive|error
literal|"Example:"
end_error
begin_error
error|#
directive|error
literal|"  #include<ft2build.h>"
end_error
begin_error
error|#
directive|error
literal|"  #include FT_FREETYPE_H"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|__FREETYPE_H__
end_ifndef
begin_define
DECL|macro|__FREETYPE_H__
define|#
directive|define
name|__FREETYPE_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_ERRORS_H
end_include
begin_include
include|#
directive|include
include|FT_TYPES_H
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    user_allocation                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    User allocation                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    How client applications should allocate FreeType data structures.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    FreeType assumes that structures allocated by the user and passed  */
end_comment
begin_comment
comment|/*    as arguments are zeroed out except for the actual data.  In other  */
end_comment
begin_comment
comment|/*    words, it is recommended to use `calloc' (or variants of it)       */
end_comment
begin_comment
comment|/*    instead of `malloc' for allocation.                                */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                        B A S I C   T Y P E S                          */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    base_interface                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Base Interface                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    The FreeType~2 base font interface.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section describes the public high-level API of FreeType~2.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Order>                                                               */
end_comment
begin_comment
comment|/*    FT_Library                                                         */
end_comment
begin_comment
comment|/*    FT_Face                                                            */
end_comment
begin_comment
comment|/*    FT_Size                                                            */
end_comment
begin_comment
comment|/*    FT_GlyphSlot                                                       */
end_comment
begin_comment
comment|/*    FT_CharMap                                                         */
end_comment
begin_comment
comment|/*    FT_Encoding                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FaceRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_SCALABLE                                              */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_FIXED_SIZES                                           */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_FIXED_WIDTH                                           */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_HORIZONTAL                                            */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_VERTICAL                                              */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_SFNT                                                  */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_KERNING                                               */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_MULTIPLE_MASTERS                                      */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_GLYPH_NAMES                                           */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_EXTERNAL_STREAM                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_FAST_GLYPHS                                           */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_HINTER                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_STYLE_FLAG_BOLD                                                 */
end_comment
begin_comment
comment|/*    FT_STYLE_FLAG_ITALIC                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SizeRec                                                         */
end_comment
begin_comment
comment|/*    FT_Size_Metrics                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_GlyphSlotRec                                                    */
end_comment
begin_comment
comment|/*    FT_Glyph_Metrics                                                   */
end_comment
begin_comment
comment|/*    FT_SubGlyph                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Bitmap_Size                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Init_FreeType                                                   */
end_comment
begin_comment
comment|/*    FT_Done_FreeType                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_New_Face                                                        */
end_comment
begin_comment
comment|/*    FT_Done_Face                                                       */
end_comment
begin_comment
comment|/*    FT_New_Memory_Face                                                 */
end_comment
begin_comment
comment|/*    FT_Open_Face                                                       */
end_comment
begin_comment
comment|/*    FT_Open_Args                                                       */
end_comment
begin_comment
comment|/*    FT_Parameter                                                       */
end_comment
begin_comment
comment|/*    FT_Attach_File                                                     */
end_comment
begin_comment
comment|/*    FT_Attach_Stream                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Set_Char_Size                                                   */
end_comment
begin_comment
comment|/*    FT_Set_Pixel_Sizes                                                 */
end_comment
begin_comment
comment|/*    FT_Request_Size                                                    */
end_comment
begin_comment
comment|/*    FT_Select_Size                                                     */
end_comment
begin_comment
comment|/*    FT_Size_Request_Type                                               */
end_comment
begin_comment
comment|/*    FT_Size_Request                                                    */
end_comment
begin_comment
comment|/*    FT_Set_Transform                                                   */
end_comment
begin_comment
comment|/*    FT_Load_Glyph                                                      */
end_comment
begin_comment
comment|/*    FT_Get_Char_Index                                                  */
end_comment
begin_comment
comment|/*    FT_Get_Name_Index                                                  */
end_comment
begin_comment
comment|/*    FT_Load_Char                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_OPEN_MEMORY                                                     */
end_comment
begin_comment
comment|/*    FT_OPEN_STREAM                                                     */
end_comment
begin_comment
comment|/*    FT_OPEN_PATHNAME                                                   */
end_comment
begin_comment
comment|/*    FT_OPEN_DRIVER                                                     */
end_comment
begin_comment
comment|/*    FT_OPEN_PARAMS                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_LOAD_DEFAULT                                                    */
end_comment
begin_comment
comment|/*    FT_LOAD_RENDER                                                     */
end_comment
begin_comment
comment|/*    FT_LOAD_MONOCHROME                                                 */
end_comment
begin_comment
comment|/*    FT_LOAD_LINEAR_DESIGN                                              */
end_comment
begin_comment
comment|/*    FT_LOAD_NO_SCALE                                                   */
end_comment
begin_comment
comment|/*    FT_LOAD_NO_HINTING                                                 */
end_comment
begin_comment
comment|/*    FT_LOAD_NO_BITMAP                                                  */
end_comment
begin_comment
comment|/*    FT_LOAD_CROP_BITMAP                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_LOAD_VERTICAL_LAYOUT                                            */
end_comment
begin_comment
comment|/*    FT_LOAD_IGNORE_TRANSFORM                                           */
end_comment
begin_comment
comment|/*    FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH                                */
end_comment
begin_comment
comment|/*    FT_LOAD_FORCE_AUTOHINT                                             */
end_comment
begin_comment
comment|/*    FT_LOAD_NO_RECURSE                                                 */
end_comment
begin_comment
comment|/*    FT_LOAD_PEDANTIC                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_LOAD_TARGET_NORMAL                                              */
end_comment
begin_comment
comment|/*    FT_LOAD_TARGET_LIGHT                                               */
end_comment
begin_comment
comment|/*    FT_LOAD_TARGET_MONO                                                */
end_comment
begin_comment
comment|/*    FT_LOAD_TARGET_LCD                                                 */
end_comment
begin_comment
comment|/*    FT_LOAD_TARGET_LCD_V                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Render_Glyph                                                    */
end_comment
begin_comment
comment|/*    FT_Render_Mode                                                     */
end_comment
begin_comment
comment|/*    FT_Get_Kerning                                                     */
end_comment
begin_comment
comment|/*    FT_Kerning_Mode                                                    */
end_comment
begin_comment
comment|/*    FT_Get_Track_Kerning                                               */
end_comment
begin_comment
comment|/*    FT_Get_Glyph_Name                                                  */
end_comment
begin_comment
comment|/*    FT_Get_Postscript_Name                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_CharMapRec                                                      */
end_comment
begin_comment
comment|/*    FT_Select_Charmap                                                  */
end_comment
begin_comment
comment|/*    FT_Set_Charmap                                                     */
end_comment
begin_comment
comment|/*    FT_Get_Charmap_Index                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_INSTALLABLE_EMBEDDING                                    */
end_comment
begin_comment
comment|/*    FT_FSTYPE_RESTRICTED_LICENSE_EMBEDDING                             */
end_comment
begin_comment
comment|/*    FT_FSTYPE_PREVIEW_AND_PRINT_EMBEDDING                              */
end_comment
begin_comment
comment|/*    FT_FSTYPE_EDITABLE_EMBEDDING                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_NO_SUBSETTING                                            */
end_comment
begin_comment
comment|/*    FT_FSTYPE_BITMAP_EMBEDDING_ONLY                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Get_FSType_Flags                                                */
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
comment|/*    FT_Glyph_Metrics                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model the metrics of a single glyph.  The      */
end_comment
begin_comment
comment|/*    values are expressed in 26.6 fractional pixel format; if the flag  */
end_comment
begin_comment
comment|/*    @FT_LOAD_NO_SCALE has been used while loading the glyph, values    */
end_comment
begin_comment
comment|/*    are expressed in font units instead.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    width ::                                                           */
end_comment
begin_comment
comment|/*      The glyph's width.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    height ::                                                          */
end_comment
begin_comment
comment|/*      The glyph's height.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiBearingX ::                                                    */
end_comment
begin_comment
comment|/*      Left side bearing for horizontal layout.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiBearingY ::                                                    */
end_comment
begin_comment
comment|/*      Top side bearing for horizontal layout.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiAdvance ::                                                     */
end_comment
begin_comment
comment|/*      Advance width for horizontal layout.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertBearingX ::                                                    */
end_comment
begin_comment
comment|/*      Left side bearing for vertical layout.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertBearingY ::                                                    */
end_comment
begin_comment
comment|/*      Top side bearing for vertical layout.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertAdvance ::                                                     */
end_comment
begin_comment
comment|/*      Advance height for vertical layout.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If not disabled with @FT_LOAD_NO_HINTING, the values represent     */
end_comment
begin_comment
comment|/*    dimensions of the hinted glyph (in case hinting is applicable).    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Glyph_Metrics_
typedef|typedef
struct|struct
name|FT_Glyph_Metrics_
block|{
DECL|member|width
name|FT_Pos
name|width
decl_stmt|;
DECL|member|height
name|FT_Pos
name|height
decl_stmt|;
DECL|member|horiBearingX
name|FT_Pos
name|horiBearingX
decl_stmt|;
DECL|member|horiBearingY
name|FT_Pos
name|horiBearingY
decl_stmt|;
DECL|member|horiAdvance
name|FT_Pos
name|horiAdvance
decl_stmt|;
DECL|member|vertBearingX
name|FT_Pos
name|vertBearingX
decl_stmt|;
DECL|member|vertBearingY
name|FT_Pos
name|vertBearingY
decl_stmt|;
DECL|member|vertAdvance
name|FT_Pos
name|vertAdvance
decl_stmt|;
block|}
DECL|typedef|FT_Glyph_Metrics
name|FT_Glyph_Metrics
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
comment|/*    FT_Bitmap_Size                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure models the metrics of a bitmap strike (i.e., a set  */
end_comment
begin_comment
comment|/*    of glyphs for a given point size and resolution) in a bitmap font. */
end_comment
begin_comment
comment|/*    It is used for the `available_sizes' field of @FT_Face.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    height :: The vertical distance, in pixels, between two            */
end_comment
begin_comment
comment|/*              consecutive baselines.  It is always positive.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    width  :: The average width, in pixels, of all glyphs in the       */
end_comment
begin_comment
comment|/*              strike.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    size   :: The nominal size of the strike in 26.6 fractional        */
end_comment
begin_comment
comment|/*              points.  This field is not very useful.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x_ppem :: The horizontal ppem (nominal width) in 26.6 fractional   */
end_comment
begin_comment
comment|/*              pixels.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_ppem :: The vertical ppem (nominal height) in 26.6 fractional    */
end_comment
begin_comment
comment|/*              pixels.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Windows FNT:                                                       */
end_comment
begin_comment
comment|/*      The nominal size given in a FNT font is not reliable.  Thus when */
end_comment
begin_comment
comment|/*      the driver finds it incorrect, it sets `size' to some calculated */
end_comment
begin_comment
comment|/*      values and sets `x_ppem' and `y_ppem' to the pixel width and     */
end_comment
begin_comment
comment|/*      height given in the font, respectively.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    TrueType embedded bitmaps:                                         */
end_comment
begin_comment
comment|/*      `size', `width', and `height' values are not contained in the    */
end_comment
begin_comment
comment|/*      bitmap strike itself.  They are computed from the global font    */
end_comment
begin_comment
comment|/*      parameters.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Bitmap_Size_
typedef|typedef
struct|struct
name|FT_Bitmap_Size_
block|{
DECL|member|height
name|FT_Short
name|height
decl_stmt|;
DECL|member|width
name|FT_Short
name|width
decl_stmt|;
DECL|member|size
name|FT_Pos
name|size
decl_stmt|;
DECL|member|x_ppem
name|FT_Pos
name|x_ppem
decl_stmt|;
DECL|member|y_ppem
name|FT_Pos
name|y_ppem
decl_stmt|;
block|}
DECL|typedef|FT_Bitmap_Size
name|FT_Bitmap_Size
typedef|;
end_typedef
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
comment|/*                     O B J E C T   C L A S S E S                       */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Library                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a FreeType library instance.  Each `library' is        */
end_comment
begin_comment
comment|/*    completely independent from the others; it is the `root' of a set  */
end_comment
begin_comment
comment|/*    of objects like fonts, faces, sizes, etc.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    It also embeds a memory manager (see @FT_Memory), as well as a     */
end_comment
begin_comment
comment|/*    scan-line converter object (see @FT_Raster).                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    For multi-threading applications each thread should have its own   */
end_comment
begin_comment
comment|/*    FT_Library object.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Library objects are normally created by @FT_Init_FreeType, and     */
end_comment
begin_comment
comment|/*    destroyed with @FT_Done_FreeType.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Library
typedef|typedef
name|struct
name|FT_LibraryRec_
modifier|*
name|FT_Library
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
comment|/*    FT_Module                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a given FreeType module object.  Each module can be a  */
end_comment
begin_comment
comment|/*    font driver, a renderer, or anything else that provides services   */
end_comment
begin_comment
comment|/*    to the formers.                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Module
typedef|typedef
name|struct
name|FT_ModuleRec_
modifier|*
name|FT_Module
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
comment|/*    FT_Driver                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a given FreeType font driver object.  Each font driver */
end_comment
begin_comment
comment|/*    is a special module capable of creating faces from font files.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Driver
typedef|typedef
name|struct
name|FT_DriverRec_
modifier|*
name|FT_Driver
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
comment|/*    FT_Renderer                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a given FreeType renderer.  A renderer is a special    */
end_comment
begin_comment
comment|/*    module in charge of converting a glyph image to a bitmap, when     */
end_comment
begin_comment
comment|/*    necessary.  Each renderer supports a given glyph image format, and */
end_comment
begin_comment
comment|/*    one or more target surface depths.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Renderer
typedef|typedef
name|struct
name|FT_RendererRec_
modifier|*
name|FT_Renderer
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
comment|/*    FT_Face                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a given typographic face object.  A face object models */
end_comment
begin_comment
comment|/*    a given typeface, in a given style.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Each face object also owns a single @FT_GlyphSlot object, as well  */
end_comment
begin_comment
comment|/*    as one or more @FT_Size objects.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Use @FT_New_Face or @FT_Open_Face to create a new face object from */
end_comment
begin_comment
comment|/*    a given filepathname or a custom input stream.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Use @FT_Done_Face to destroy it (along with its slot and sizes).   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Also>                                                                */
end_comment
begin_comment
comment|/*    See @FT_FaceRec for the publicly accessible fields of a given face */
end_comment
begin_comment
comment|/*    object.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Face
typedef|typedef
name|struct
name|FT_FaceRec_
modifier|*
name|FT_Face
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
comment|/*    FT_Size                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an object used to model a face scaled to a given       */
end_comment
begin_comment
comment|/*    character size.                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Each @FT_Face has an _active_ @FT_Size object that is used by      */
end_comment
begin_comment
comment|/*    functions like @FT_Load_Glyph to determine the scaling             */
end_comment
begin_comment
comment|/*    transformation which is used to load and hint glyphs and metrics.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    You can use @FT_Set_Char_Size, @FT_Set_Pixel_Sizes,                */
end_comment
begin_comment
comment|/*    @FT_Request_Size or even @FT_Select_Size to change the content     */
end_comment
begin_comment
comment|/*    (i.e., the scaling values) of the active @FT_Size.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    You can use @FT_New_Size to create additional size objects for a   */
end_comment
begin_comment
comment|/*    given @FT_Face, but they won't be used by other functions until    */
end_comment
begin_comment
comment|/*    you activate it through @FT_Activate_Size.  Only one size can be   */
end_comment
begin_comment
comment|/*    activated at any given time per face.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Also>                                                                */
end_comment
begin_comment
comment|/*    See @FT_SizeRec for the publicly accessible fields of a given size */
end_comment
begin_comment
comment|/*    object.                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Size
typedef|typedef
name|struct
name|FT_SizeRec_
modifier|*
name|FT_Size
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
comment|/*    FT_GlyphSlot                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a given `glyph slot'.  A slot is a container where it  */
end_comment
begin_comment
comment|/*    is possible to load any of the glyphs contained in its parent      */
end_comment
begin_comment
comment|/*    face.                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    In other words, each time you call @FT_Load_Glyph or               */
end_comment
begin_comment
comment|/*    @FT_Load_Char, the slot's content is erased by the new glyph data, */
end_comment
begin_comment
comment|/*    i.e., the glyph's metrics, its image (bitmap or outline), and      */
end_comment
begin_comment
comment|/*    other control information.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Also>                                                                */
end_comment
begin_comment
comment|/*    See @FT_GlyphSlotRec for the publicly accessible glyph fields.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_GlyphSlot
typedef|typedef
name|struct
name|FT_GlyphSlotRec_
modifier|*
name|FT_GlyphSlot
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
comment|/*    FT_CharMap                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a given character map.  A charmap is used to translate */
end_comment
begin_comment
comment|/*    character codes in a given encoding into glyph indexes for its     */
end_comment
begin_comment
comment|/*    parent's face.  Some font formats may provide several charmaps per */
end_comment
begin_comment
comment|/*    font.                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Each face object owns zero or more charmaps, but only one of them  */
end_comment
begin_comment
comment|/*    can be `active' and used by @FT_Get_Char_Index or @FT_Load_Char.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The list of available charmaps in a face is available through the  */
end_comment
begin_comment
comment|/*    `face->num_charmaps' and `face->charmaps' fields of @FT_FaceRec.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The currently active charmap is available as `face->charmap'.      */
end_comment
begin_comment
comment|/*    You should call @FT_Set_Charmap to change it.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    When a new face is created (either through @FT_New_Face or         */
end_comment
begin_comment
comment|/*    @FT_Open_Face), the library looks for a Unicode charmap within     */
end_comment
begin_comment
comment|/*    the list and automatically activates it.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Also>                                                                */
end_comment
begin_comment
comment|/*    See @FT_CharMapRec for the publicly accessible fields of a given   */
end_comment
begin_comment
comment|/*    character map.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_CharMap
typedef|typedef
name|struct
name|FT_CharMapRec_
modifier|*
name|FT_CharMap
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_ENC_TAG                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This macro converts four-letter tags into an unsigned long.  It is */
end_comment
begin_comment
comment|/*    used to define `encoding' identifiers (see @FT_Encoding).          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Since many 16-bit compilers don't like 32-bit enumerations, you    */
end_comment
begin_comment
comment|/*    should redefine this macro in case of problems to something like   */
end_comment
begin_comment
comment|/*    this:                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      #define FT_ENC_TAG( value, a, b, c, d )  value                   */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to get a simple enumeration without assigning special numbers.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_ENC_TAG
end_ifndef
begin_define
DECL|macro|FT_ENC_TAG
define|#
directive|define
name|FT_ENC_TAG
parameter_list|(
name|value
parameter_list|,
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|value = ( ( (FT_UInt32)(a)<< 24 ) |  \                     ( (FT_UInt32)(b)<< 16 ) |  \                     ( (FT_UInt32)(c)<<  8 ) |  \                       (FT_UInt32)(d)         )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_ENC_TAG */
end_comment
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
comment|/*    FT_Encoding                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration used to specify character sets supported by         */
end_comment
begin_comment
comment|/*    charmaps.  Used in the @FT_Select_Charmap API function.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Despite the name, this enumeration lists specific character        */
end_comment
begin_comment
comment|/*    repertories (i.e., charsets), and not text encoding methods (e.g., */
end_comment
begin_comment
comment|/*    UTF-8, UTF-16, etc.).                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Other encodings might be defined in the future.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_ENCODING_NONE ::                                                */
end_comment
begin_comment
comment|/*      The encoding value~0 is reserved.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_UNICODE ::                                             */
end_comment
begin_comment
comment|/*      Corresponds to the Unicode character set.  This value covers     */
end_comment
begin_comment
comment|/*      all versions of the Unicode repertoire, including ASCII and      */
end_comment
begin_comment
comment|/*      Latin-1.  Most fonts include a Unicode charmap, but not all      */
end_comment
begin_comment
comment|/*      of them.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      For example, if you want to access Unicode value U+1F028 (and    */
end_comment
begin_comment
comment|/*      the font contains it), use value 0x1F028 as the input value for  */
end_comment
begin_comment
comment|/*      @FT_Get_Char_Index.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_MS_SYMBOL ::                                           */
end_comment
begin_comment
comment|/*      Corresponds to the Microsoft Symbol encoding, used to encode     */
end_comment
begin_comment
comment|/*      mathematical symbols in the 32..255 character code range.  For   */
end_comment
begin_comment
comment|/*      more information, see `http://www.ceviz.net/symbol.htm'.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_SJIS ::                                                */
end_comment
begin_comment
comment|/*      Corresponds to Japanese SJIS encoding.  More info at             */
end_comment
begin_comment
comment|/*      at `http://langsupport.japanreference.com/encoding.shtml'.       */
end_comment
begin_comment
comment|/*      See note on multi-byte encodings below.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_GB2312 ::                                              */
end_comment
begin_comment
comment|/*      Corresponds to an encoding system for Simplified Chinese as used */
end_comment
begin_comment
comment|/*      used in mainland China.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_BIG5 ::                                                */
end_comment
begin_comment
comment|/*      Corresponds to an encoding system for Traditional Chinese as     */
end_comment
begin_comment
comment|/*      used in Taiwan and Hong Kong.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_WANSUNG ::                                             */
end_comment
begin_comment
comment|/*      Corresponds to the Korean encoding system known as Wansung.      */
end_comment
begin_comment
comment|/*      For more information see                                         */
end_comment
begin_comment
comment|/*      `http://www.microsoft.com/typography/unicode/949.txt'.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_JOHAB ::                                               */
end_comment
begin_comment
comment|/*      The Korean standard character set (KS~C 5601-1992), which        */
end_comment
begin_comment
comment|/*      corresponds to MS Windows code page 1361.  This character set    */
end_comment
begin_comment
comment|/*      includes all possible Hangeul character combinations.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_ADOBE_LATIN_1 ::                                       */
end_comment
begin_comment
comment|/*      Corresponds to a Latin-1 encoding as defined in a Type~1         */
end_comment
begin_comment
comment|/*      PostScript font.  It is limited to 256 character codes.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_ADOBE_STANDARD ::                                      */
end_comment
begin_comment
comment|/*      Corresponds to the Adobe Standard encoding, as found in Type~1,  */
end_comment
begin_comment
comment|/*      CFF, and OpenType/CFF fonts.  It is limited to 256 character     */
end_comment
begin_comment
comment|/*      codes.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_ADOBE_EXPERT ::                                        */
end_comment
begin_comment
comment|/*      Corresponds to the Adobe Expert encoding, as found in Type~1,    */
end_comment
begin_comment
comment|/*      CFF, and OpenType/CFF fonts.  It is limited to 256 character     */
end_comment
begin_comment
comment|/*      codes.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_ADOBE_CUSTOM ::                                        */
end_comment
begin_comment
comment|/*      Corresponds to a custom encoding, as found in Type~1, CFF, and   */
end_comment
begin_comment
comment|/*      OpenType/CFF fonts.  It is limited to 256 character codes.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_APPLE_ROMAN ::                                         */
end_comment
begin_comment
comment|/*      Corresponds to the 8-bit Apple roman encoding.  Many TrueType    */
end_comment
begin_comment
comment|/*      and OpenType fonts contain a charmap for this encoding, since    */
end_comment
begin_comment
comment|/*      older versions of Mac OS are able to use it.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_OLD_LATIN_2 ::                                         */
end_comment
begin_comment
comment|/*      This value is deprecated and was never used nor reported by      */
end_comment
begin_comment
comment|/*      FreeType.  Don't use or test for it.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_MS_SJIS ::                                             */
end_comment
begin_comment
comment|/*      Same as FT_ENCODING_SJIS.  Deprecated.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_MS_GB2312 ::                                           */
end_comment
begin_comment
comment|/*      Same as FT_ENCODING_GB2312.  Deprecated.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_MS_BIG5 ::                                             */
end_comment
begin_comment
comment|/*      Same as FT_ENCODING_BIG5.  Deprecated.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_MS_WANSUNG ::                                          */
end_comment
begin_comment
comment|/*      Same as FT_ENCODING_WANSUNG.  Deprecated.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_MS_JOHAB ::                                            */
end_comment
begin_comment
comment|/*      Same as FT_ENCODING_JOHAB.  Deprecated.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    By default, FreeType automatically synthesizes a Unicode charmap   */
end_comment
begin_comment
comment|/*    for PostScript fonts, using their glyph names dictionaries.        */
end_comment
begin_comment
comment|/*    However, it also reports the encodings defined explicitly in the   */
end_comment
begin_comment
comment|/*    font file, for the cases when they are needed, with the Adobe      */
end_comment
begin_comment
comment|/*    values as well.                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_NONE is set by the BDF and PCF drivers if the charmap  */
end_comment
begin_comment
comment|/*    is neither Unicode nor ISO-8859-1 (otherwise it is set to          */
end_comment
begin_comment
comment|/*    FT_ENCODING_UNICODE).  Use @FT_Get_BDF_Charset_ID to find out      */
end_comment
begin_comment
comment|/*    which encoding is really present.  If, for example, the            */
end_comment
begin_comment
comment|/*    `cs_registry' field is `KOI8' and the `cs_encoding' field is `R',  */
end_comment
begin_comment
comment|/*    the font is encoded in KOI8-R.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_NONE is always set (with a single exception) by the    */
end_comment
begin_comment
comment|/*    winfonts driver.  Use @FT_Get_WinFNT_Header and examine the        */
end_comment
begin_comment
comment|/*    `charset' field of the @FT_WinFNT_HeaderRec structure to find out  */
end_comment
begin_comment
comment|/*    which encoding is really present.  For example,                    */
end_comment
begin_comment
comment|/*    @FT_WinFNT_ID_CP1251 (204) means Windows code page 1251 (for       */
end_comment
begin_comment
comment|/*    Russian).                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_ENCODING_NONE is set if `platform_id' is @TT_PLATFORM_MACINTOSH */
end_comment
begin_comment
comment|/*    and `encoding_id' is not @TT_MAC_ID_ROMAN (otherwise it is set to  */
end_comment
begin_comment
comment|/*    FT_ENCODING_APPLE_ROMAN).                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If `platform_id' is @TT_PLATFORM_MACINTOSH, use the function       */
end_comment
begin_comment
comment|/*    @FT_Get_CMap_Language_ID  to query the Mac language ID which may   */
end_comment
begin_comment
comment|/*    be needed to be able to distinguish Apple encoding variants.  See  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      http://www.unicode.org/Public/MAPPINGS/VENDORS/APPLE/README.TXT  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    to get an idea how to do that.  Basically, if the language ID      */
end_comment
begin_comment
comment|/*    is~0, don't use it, otherwise subtract 1 from the language ID.     */
end_comment
begin_comment
comment|/*    Then examine `encoding_id'.  If, for example, `encoding_id' is     */
end_comment
begin_comment
comment|/*    @TT_MAC_ID_ROMAN and the language ID (minus~1) is                  */
end_comment
begin_comment
comment|/*    `TT_MAC_LANGID_GREEK', it is the Greek encoding, not Roman.        */
end_comment
begin_comment
comment|/*    @TT_MAC_ID_ARABIC with `TT_MAC_LANGID_FARSI' means the Farsi       */
end_comment
begin_comment
comment|/*    variant the Arabic encoding.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_Encoding_
typedef|typedef
enum|enum
name|FT_Encoding_
block|{
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_NONE
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_MS_SYMBOL
argument_list|,
literal|'s'
argument_list|,
literal|'y'
argument_list|,
literal|'m'
argument_list|,
literal|'b'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_UNICODE
argument_list|,
literal|'u'
argument_list|,
literal|'n'
argument_list|,
literal|'i'
argument_list|,
literal|'c'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_SJIS
argument_list|,
literal|'s'
argument_list|,
literal|'j'
argument_list|,
literal|'i'
argument_list|,
literal|'s'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_GB2312
argument_list|,
literal|'g'
argument_list|,
literal|'b'
argument_list|,
literal|' '
argument_list|,
literal|' '
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_BIG5
argument_list|,
literal|'b'
argument_list|,
literal|'i'
argument_list|,
literal|'g'
argument_list|,
literal|'5'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_WANSUNG
argument_list|,
literal|'w'
argument_list|,
literal|'a'
argument_list|,
literal|'n'
argument_list|,
literal|'s'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_JOHAB
argument_list|,
literal|'j'
argument_list|,
literal|'o'
argument_list|,
literal|'h'
argument_list|,
literal|'a'
argument_list|)
block|,
comment|/* for backwards compatibility */
DECL|enumerator|FT_ENCODING_MS_SJIS
name|FT_ENCODING_MS_SJIS
init|=
name|FT_ENCODING_SJIS
block|,
DECL|enumerator|FT_ENCODING_MS_GB2312
name|FT_ENCODING_MS_GB2312
init|=
name|FT_ENCODING_GB2312
block|,
DECL|enumerator|FT_ENCODING_MS_BIG5
name|FT_ENCODING_MS_BIG5
init|=
name|FT_ENCODING_BIG5
block|,
DECL|enumerator|FT_ENCODING_MS_WANSUNG
name|FT_ENCODING_MS_WANSUNG
init|=
name|FT_ENCODING_WANSUNG
block|,
DECL|enumerator|FT_ENCODING_MS_JOHAB
name|FT_ENCODING_MS_JOHAB
init|=
name|FT_ENCODING_JOHAB
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_ADOBE_STANDARD
argument_list|,
literal|'A'
argument_list|,
literal|'D'
argument_list|,
literal|'O'
argument_list|,
literal|'B'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_ADOBE_EXPERT
argument_list|,
literal|'A'
argument_list|,
literal|'D'
argument_list|,
literal|'B'
argument_list|,
literal|'E'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_ADOBE_CUSTOM
argument_list|,
literal|'A'
argument_list|,
literal|'D'
argument_list|,
literal|'B'
argument_list|,
literal|'C'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_ADOBE_LATIN_1
argument_list|,
literal|'l'
argument_list|,
literal|'a'
argument_list|,
literal|'t'
argument_list|,
literal|'1'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
name|FT_ENCODING_OLD_LATIN_2
argument_list|,
literal|'l'
argument_list|,
literal|'a'
argument_list|,
literal|'t'
argument_list|,
literal|'2'
argument_list|)
block|,
DECL|enumerator|FT_ENC_TAG
name|FT_ENC_TAG
argument_list|(
argument|FT_ENCODING_APPLE_ROMAN
argument_list|,
literal|'a'
argument_list|,
literal|'r'
argument_list|,
literal|'m'
argument_list|,
literal|'n'
argument_list|)
block|}
DECL|typedef|FT_Encoding
name|FT_Encoding
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
comment|/*    ft_encoding_xxx                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    These constants are deprecated; use the corresponding @FT_Encoding */
end_comment
begin_comment
comment|/*    values instead.                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|ft_encoding_none
define|#
directive|define
name|ft_encoding_none
value|FT_ENCODING_NONE
end_define
begin_define
DECL|macro|ft_encoding_unicode
define|#
directive|define
name|ft_encoding_unicode
value|FT_ENCODING_UNICODE
end_define
begin_define
DECL|macro|ft_encoding_symbol
define|#
directive|define
name|ft_encoding_symbol
value|FT_ENCODING_MS_SYMBOL
end_define
begin_define
DECL|macro|ft_encoding_latin_1
define|#
directive|define
name|ft_encoding_latin_1
value|FT_ENCODING_ADOBE_LATIN_1
end_define
begin_define
DECL|macro|ft_encoding_latin_2
define|#
directive|define
name|ft_encoding_latin_2
value|FT_ENCODING_OLD_LATIN_2
end_define
begin_define
DECL|macro|ft_encoding_sjis
define|#
directive|define
name|ft_encoding_sjis
value|FT_ENCODING_SJIS
end_define
begin_define
DECL|macro|ft_encoding_gb2312
define|#
directive|define
name|ft_encoding_gb2312
value|FT_ENCODING_GB2312
end_define
begin_define
DECL|macro|ft_encoding_big5
define|#
directive|define
name|ft_encoding_big5
value|FT_ENCODING_BIG5
end_define
begin_define
DECL|macro|ft_encoding_wansung
define|#
directive|define
name|ft_encoding_wansung
value|FT_ENCODING_WANSUNG
end_define
begin_define
DECL|macro|ft_encoding_johab
define|#
directive|define
name|ft_encoding_johab
value|FT_ENCODING_JOHAB
end_define
begin_define
DECL|macro|ft_encoding_adobe_standard
define|#
directive|define
name|ft_encoding_adobe_standard
value|FT_ENCODING_ADOBE_STANDARD
end_define
begin_define
DECL|macro|ft_encoding_adobe_expert
define|#
directive|define
name|ft_encoding_adobe_expert
value|FT_ENCODING_ADOBE_EXPERT
end_define
begin_define
DECL|macro|ft_encoding_adobe_custom
define|#
directive|define
name|ft_encoding_adobe_custom
value|FT_ENCODING_ADOBE_CUSTOM
end_define
begin_define
DECL|macro|ft_encoding_apple_roman
define|#
directive|define
name|ft_encoding_apple_roman
value|FT_ENCODING_APPLE_ROMAN
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
comment|/*    FT_CharMapRec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The base charmap structure.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    face        :: A handle to the parent face object.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    encoding    :: An @FT_Encoding tag identifying the charmap.  Use   */
end_comment
begin_comment
comment|/*                   this with @FT_Select_Charmap.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    platform_id :: An ID number describing the platform for the        */
end_comment
begin_comment
comment|/*                   following encoding ID.  This comes directly from    */
end_comment
begin_comment
comment|/*                   the TrueType specification and should be emulated   */
end_comment
begin_comment
comment|/*                   for other formats.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    encoding_id :: A platform specific encoding number.  This also     */
end_comment
begin_comment
comment|/*                   comes from the TrueType specification and should be */
end_comment
begin_comment
comment|/*                   emulated similarly.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_CharMapRec_
typedef|typedef
struct|struct
name|FT_CharMapRec_
block|{
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
DECL|member|encoding
name|FT_Encoding
name|encoding
decl_stmt|;
DECL|member|platform_id
name|FT_UShort
name|platform_id
decl_stmt|;
DECL|member|encoding_id
name|FT_UShort
name|encoding_id
decl_stmt|;
block|}
DECL|typedef|FT_CharMapRec
name|FT_CharMapRec
typedef|;
end_typedef
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
comment|/*                 B A S E   O B J E C T   C L A S S E S                 */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Type>                                                                */
end_comment
begin_comment
comment|/*    FT_Face_Internal                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An opaque handle to an `FT_Face_InternalRec' structure, used to    */
end_comment
begin_comment
comment|/*    model private data of a given @FT_Face object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This structure might change between releases of FreeType~2 and is  */
end_comment
begin_comment
comment|/*    not generally available to client applications.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Face_Internal
typedef|typedef
name|struct
name|FT_Face_InternalRec_
modifier|*
name|FT_Face_Internal
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
comment|/*    FT_FaceRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    FreeType root face class structure.  A face object models a        */
end_comment
begin_comment
comment|/*    typeface in a font file.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    num_faces           :: The number of faces in the font file.  Some */
end_comment
begin_comment
comment|/*                           font formats can have multiple faces in     */
end_comment
begin_comment
comment|/*                           a font file.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index          :: The index of the face in the font file.  It */
end_comment
begin_comment
comment|/*                           is set to~0 if there is only one face in    */
end_comment
begin_comment
comment|/*                           the font file.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_flags          :: A set of bit flags that give important      */
end_comment
begin_comment
comment|/*                           information about the face; see             */
end_comment
begin_comment
comment|/*                           @FT_FACE_FLAG_XXX for the details.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    style_flags         :: A set of bit flags indicating the style of  */
end_comment
begin_comment
comment|/*                           the face; see @FT_STYLE_FLAG_XXX for the    */
end_comment
begin_comment
comment|/*                           details.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_glyphs          :: The number of glyphs in the face.  If the   */
end_comment
begin_comment
comment|/*                           face is scalable and has sbits (see         */
end_comment
begin_comment
comment|/*                           `num_fixed_sizes'), it is set to the number */
end_comment
begin_comment
comment|/*                           of outline glyphs.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                           For CID-keyed fonts, this value gives the   */
end_comment
begin_comment
comment|/*                           highest CID used in the font.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    family_name         :: The face's family name.  This is an ASCII   */
end_comment
begin_comment
comment|/*                           string, usually in English, which describes */
end_comment
begin_comment
comment|/*                           the typeface's family (like `Times New      */
end_comment
begin_comment
comment|/*                           Roman', `Bodoni', `Garamond', etc).  This   */
end_comment
begin_comment
comment|/*                           is a least common denominator used to list  */
end_comment
begin_comment
comment|/*                           fonts.  Some formats (TrueType& OpenType)  */
end_comment
begin_comment
comment|/*                           provide localized and Unicode versions of   */
end_comment
begin_comment
comment|/*                           this string.  Applications should use the   */
end_comment
begin_comment
comment|/*                           format specific interface to access them.   */
end_comment
begin_comment
comment|/*                           Can be NULL (e.g., in fonts embedded in a   */
end_comment
begin_comment
comment|/*                           PDF file).                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    style_name          :: The face's style name.  This is an ASCII    */
end_comment
begin_comment
comment|/*                           string, usually in English, which describes */
end_comment
begin_comment
comment|/*                           the typeface's style (like `Italic',        */
end_comment
begin_comment
comment|/*                           `Bold', `Condensed', etc).  Not all font    */
end_comment
begin_comment
comment|/*                           formats provide a style name, so this field */
end_comment
begin_comment
comment|/*                           is optional, and can be set to NULL.  As    */
end_comment
begin_comment
comment|/*                           for `family_name', some formats provide     */
end_comment
begin_comment
comment|/*                           localized and Unicode versions of this      */
end_comment
begin_comment
comment|/*                           string.  Applications should use the format */
end_comment
begin_comment
comment|/*                           specific interface to access them.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_fixed_sizes     :: The number of bitmap strikes in the face.   */
end_comment
begin_comment
comment|/*                           Even if the face is scalable, there might   */
end_comment
begin_comment
comment|/*                           still be bitmap strikes, which are called   */
end_comment
begin_comment
comment|/*                           `sbits' in that case.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    available_sizes     :: An array of @FT_Bitmap_Size for all bitmap  */
end_comment
begin_comment
comment|/*                           strikes in the face.  It is set to NULL if  */
end_comment
begin_comment
comment|/*                           there is no bitmap strike.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_charmaps        :: The number of charmaps in the face.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    charmaps            :: An array of the charmaps of the face.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    generic             :: A field reserved for client uses.  See the  */
end_comment
begin_comment
comment|/*                           @FT_Generic type description.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bbox                :: The font bounding box.  Coordinates are     */
end_comment
begin_comment
comment|/*                           expressed in font units (see                */
end_comment
begin_comment
comment|/*                           `units_per_EM').  The box is large enough   */
end_comment
begin_comment
comment|/*                           to contain any glyph from the font.  Thus,  */
end_comment
begin_comment
comment|/*                           `bbox.yMax' can be seen as the `maximal     */
end_comment
begin_comment
comment|/*                           ascender', and `bbox.yMin' as the `minimal  */
end_comment
begin_comment
comment|/*                           descender'.  Only relevant for scalable     */
end_comment
begin_comment
comment|/*                           formats.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                           Note that the bounding box might be off by  */
end_comment
begin_comment
comment|/*                           (at least) one pixel for hinted fonts.  See */
end_comment
begin_comment
comment|/*                           @FT_Size_Metrics for further discussion.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    units_per_EM        :: The number of font units per EM square for  */
end_comment
begin_comment
comment|/*                           this face.  This is typically 2048 for      */
end_comment
begin_comment
comment|/*                           TrueType fonts, and 1000 for Type~1 fonts.  */
end_comment
begin_comment
comment|/*                           Only relevant for scalable formats.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ascender            :: The typographic ascender of the face,       */
end_comment
begin_comment
comment|/*                           expressed in font units.  For font formats  */
end_comment
begin_comment
comment|/*                           not having this information, it is set to   */
end_comment
begin_comment
comment|/*                           `bbox.yMax'.  Only relevant for scalable    */
end_comment
begin_comment
comment|/*                           formats.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    descender           :: The typographic descender of the face,      */
end_comment
begin_comment
comment|/*                           expressed in font units.  For font formats  */
end_comment
begin_comment
comment|/*                           not having this information, it is set to   */
end_comment
begin_comment
comment|/*                           `bbox.yMin'.  Note that this field is       */
end_comment
begin_comment
comment|/*                           usually negative.  Only relevant for        */
end_comment
begin_comment
comment|/*                           scalable formats.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    height              :: The height is the vertical distance         */
end_comment
begin_comment
comment|/*                           between two consecutive baselines,          */
end_comment
begin_comment
comment|/*                           expressed in font units.  It is always      */
end_comment
begin_comment
comment|/*                           positive.  Only relevant for scalable       */
end_comment
begin_comment
comment|/*                           formats.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_advance_width   :: The maximal advance width, in font units,   */
end_comment
begin_comment
comment|/*                           for all glyphs in this face.  This can be   */
end_comment
begin_comment
comment|/*                           used to make word wrapping computations     */
end_comment
begin_comment
comment|/*                           faster.  Only relevant for scalable         */
end_comment
begin_comment
comment|/*                           formats.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_advance_height  :: The maximal advance height, in font units,  */
end_comment
begin_comment
comment|/*                           for all glyphs in this face.  This is only  */
end_comment
begin_comment
comment|/*                           relevant for vertical layouts, and is set   */
end_comment
begin_comment
comment|/*                           to `height' for fonts that do not provide   */
end_comment
begin_comment
comment|/*                           vertical metrics.  Only relevant for        */
end_comment
begin_comment
comment|/*                           scalable formats.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    underline_position  :: The position, in font units, of the         */
end_comment
begin_comment
comment|/*                           underline line for this face.  It is the    */
end_comment
begin_comment
comment|/*                           center of the underlining stem.  Only       */
end_comment
begin_comment
comment|/*                           relevant for scalable formats.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    underline_thickness :: The thickness, in font units, of the        */
end_comment
begin_comment
comment|/*                           underline for this face.  Only relevant for */
end_comment
begin_comment
comment|/*                           scalable formats.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph               :: The face's associated glyph slot(s).        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    size                :: The current active size for this face.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    charmap             :: The current active charmap for this face.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Fields may be changed after a call to @FT_Attach_File or           */
end_comment
begin_comment
comment|/*    @FT_Attach_Stream.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_FaceRec_
typedef|typedef
struct|struct
name|FT_FaceRec_
block|{
DECL|member|num_faces
name|FT_Long
name|num_faces
decl_stmt|;
DECL|member|face_index
name|FT_Long
name|face_index
decl_stmt|;
DECL|member|face_flags
name|FT_Long
name|face_flags
decl_stmt|;
DECL|member|style_flags
name|FT_Long
name|style_flags
decl_stmt|;
DECL|member|num_glyphs
name|FT_Long
name|num_glyphs
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
DECL|member|num_fixed_sizes
name|FT_Int
name|num_fixed_sizes
decl_stmt|;
DECL|member|available_sizes
name|FT_Bitmap_Size
modifier|*
name|available_sizes
decl_stmt|;
DECL|member|num_charmaps
name|FT_Int
name|num_charmaps
decl_stmt|;
DECL|member|charmaps
name|FT_CharMap
modifier|*
name|charmaps
decl_stmt|;
DECL|member|generic
name|FT_Generic
name|generic
decl_stmt|;
comment|/*# The following member variables (down to `underline_thickness') */
comment|/*# are only relevant to scalable outlines; cf. @FT_Bitmap_Size    */
comment|/*# for bitmap fonts.                                              */
DECL|member|bbox
name|FT_BBox
name|bbox
decl_stmt|;
DECL|member|units_per_EM
name|FT_UShort
name|units_per_EM
decl_stmt|;
DECL|member|ascender
name|FT_Short
name|ascender
decl_stmt|;
DECL|member|descender
name|FT_Short
name|descender
decl_stmt|;
DECL|member|height
name|FT_Short
name|height
decl_stmt|;
DECL|member|max_advance_width
name|FT_Short
name|max_advance_width
decl_stmt|;
DECL|member|max_advance_height
name|FT_Short
name|max_advance_height
decl_stmt|;
DECL|member|underline_position
name|FT_Short
name|underline_position
decl_stmt|;
DECL|member|underline_thickness
name|FT_Short
name|underline_thickness
decl_stmt|;
DECL|member|glyph
name|FT_GlyphSlot
name|glyph
decl_stmt|;
DECL|member|size
name|FT_Size
name|size
decl_stmt|;
DECL|member|charmap
name|FT_CharMap
name|charmap
decl_stmt|;
comment|/*@private begin */
DECL|member|driver
name|FT_Driver
name|driver
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
DECL|member|sizes_list
name|FT_ListRec
name|sizes_list
decl_stmt|;
DECL|member|autohint
name|FT_Generic
name|autohint
decl_stmt|;
DECL|member|extensions
name|void
modifier|*
name|extensions
decl_stmt|;
DECL|member|internal
name|FT_Face_Internal
name|internal
decl_stmt|;
comment|/*@private end */
block|}
DECL|typedef|FT_FaceRec
name|FT_FaceRec
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
comment|/*    FT_FACE_FLAG_XXX                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of bit flags used in the `face_flags' field of the          */
end_comment
begin_comment
comment|/*    @FT_FaceRec structure.  They inform client applications of         */
end_comment
begin_comment
comment|/*    properties of the corresponding face.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_SCALABLE ::                                           */
end_comment
begin_comment
comment|/*      Indicates that the face contains outline glyphs.  This doesn't   */
end_comment
begin_comment
comment|/*      prevent bitmap strikes, i.e., a face can have both this and      */
end_comment
begin_comment
comment|/*      and @FT_FACE_FLAG_FIXED_SIZES set.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_FIXED_SIZES ::                                        */
end_comment
begin_comment
comment|/*      Indicates that the face contains bitmap strikes.  See also the   */
end_comment
begin_comment
comment|/*      `num_fixed_sizes' and `available_sizes' fields of @FT_FaceRec.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_FIXED_WIDTH ::                                        */
end_comment
begin_comment
comment|/*      Indicates that the face contains fixed-width characters (like    */
end_comment
begin_comment
comment|/*      Courier, Lucido, MonoType, etc.).                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_SFNT ::                                               */
end_comment
begin_comment
comment|/*      Indicates that the face uses the `sfnt' storage scheme.  For     */
end_comment
begin_comment
comment|/*      now, this means TrueType and OpenType.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_HORIZONTAL ::                                         */
end_comment
begin_comment
comment|/*      Indicates that the face contains horizontal glyph metrics.  This */
end_comment
begin_comment
comment|/*      should be set for all common formats.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_VERTICAL ::                                           */
end_comment
begin_comment
comment|/*      Indicates that the face contains vertical glyph metrics.  This   */
end_comment
begin_comment
comment|/*      is only available in some formats, not all of them.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_KERNING ::                                            */
end_comment
begin_comment
comment|/*      Indicates that the face contains kerning information.  If set,   */
end_comment
begin_comment
comment|/*      the kerning distance can be retrieved through the function       */
end_comment
begin_comment
comment|/*      @FT_Get_Kerning.  Otherwise the function always return the       */
end_comment
begin_comment
comment|/*      vector (0,0).  Note that FreeType doesn't handle kerning data    */
end_comment
begin_comment
comment|/*      from the `GPOS' table (as present in some OpenType fonts).       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_FAST_GLYPHS ::                                        */
end_comment
begin_comment
comment|/*      THIS FLAG IS DEPRECATED.  DO NOT USE OR TEST IT.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_MULTIPLE_MASTERS ::                                   */
end_comment
begin_comment
comment|/*      Indicates that the font contains multiple masters and is capable */
end_comment
begin_comment
comment|/*      of interpolating between them.  See the multiple-masters         */
end_comment
begin_comment
comment|/*      specific API for details.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_GLYPH_NAMES ::                                        */
end_comment
begin_comment
comment|/*      Indicates that the font contains glyph names that can be         */
end_comment
begin_comment
comment|/*      retrieved through @FT_Get_Glyph_Name.  Note that some TrueType   */
end_comment
begin_comment
comment|/*      fonts contain broken glyph name tables.  Use the function        */
end_comment
begin_comment
comment|/*      @FT_Has_PS_Glyph_Names when needed.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_EXTERNAL_STREAM ::                                    */
end_comment
begin_comment
comment|/*      Used internally by FreeType to indicate that a face's stream was */
end_comment
begin_comment
comment|/*      provided by the client application and should not be destroyed   */
end_comment
begin_comment
comment|/*      when @FT_Done_Face is called.  Don't read or test this flag.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_HINTER ::                                             */
end_comment
begin_comment
comment|/*      Set if the font driver has a hinting machine of its own.  For    */
end_comment
begin_comment
comment|/*      example, with TrueType fonts, it makes sense to use data from    */
end_comment
begin_comment
comment|/*      the SFNT `gasp' table only if the native TrueType hinting engine */
end_comment
begin_comment
comment|/*      (with the bytecode interpreter) is available and active.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_CID_KEYED ::                                          */
end_comment
begin_comment
comment|/*      Set if the font is CID-keyed.  In that case, the font is not     */
end_comment
begin_comment
comment|/*      accessed by glyph indices but by CID values.  For subsetted      */
end_comment
begin_comment
comment|/*      CID-keyed fonts this has the consequence that not all index      */
end_comment
begin_comment
comment|/*      values are a valid argument to FT_Load_Glyph.  Only the CID      */
end_comment
begin_comment
comment|/*      values for which corresponding glyphs in the subsetted font      */
end_comment
begin_comment
comment|/*      exist make FT_Load_Glyph return successfully; in all other cases */
end_comment
begin_comment
comment|/*      you get an `FT_Err_Invalid_Argument' error.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      Note that CID-keyed fonts which are in an SFNT wrapper don't     */
end_comment
begin_comment
comment|/*      have this flag set since the glyphs are accessed in the normal   */
end_comment
begin_comment
comment|/*      way (using contiguous indices); the `CID-ness' isn't visible to  */
end_comment
begin_comment
comment|/*      the application.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FACE_FLAG_TRICKY ::                                             */
end_comment
begin_comment
comment|/*      Set if the font is `tricky', this is, it always needs the        */
end_comment
begin_comment
comment|/*      font format's native hinting engine to get a reasonable result.  */
end_comment
begin_comment
comment|/*      A typical example is the Chinese font `mingli.ttf' which uses    */
end_comment
begin_comment
comment|/*      TrueType bytecode instructions to move and scale all of its      */
end_comment
begin_comment
comment|/*      subglyphs.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      It is not possible to autohint such fonts using                  */
end_comment
begin_comment
comment|/*      @FT_LOAD_FORCE_AUTOHINT; it will also ignore                     */
end_comment
begin_comment
comment|/*      @FT_LOAD_NO_HINTING.  You have to set both FT_LOAD_NO_HINTING    */
end_comment
begin_comment
comment|/*      and @FT_LOAD_NO_AUTOHINT to really disable hinting; however, you */
end_comment
begin_comment
comment|/*      probably never want this except for demonstration purposes.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      Currently, there are six TrueType fonts in the list of tricky    */
end_comment
begin_comment
comment|/*      fonts; they are hard-coded in file `ttobjs.c'.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_FACE_FLAG_SCALABLE
define|#
directive|define
name|FT_FACE_FLAG_SCALABLE
value|( 1L<<  0 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_FIXED_SIZES
define|#
directive|define
name|FT_FACE_FLAG_FIXED_SIZES
value|( 1L<<  1 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_FIXED_WIDTH
define|#
directive|define
name|FT_FACE_FLAG_FIXED_WIDTH
value|( 1L<<  2 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_SFNT
define|#
directive|define
name|FT_FACE_FLAG_SFNT
value|( 1L<<  3 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_HORIZONTAL
define|#
directive|define
name|FT_FACE_FLAG_HORIZONTAL
value|( 1L<<  4 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_VERTICAL
define|#
directive|define
name|FT_FACE_FLAG_VERTICAL
value|( 1L<<  5 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_KERNING
define|#
directive|define
name|FT_FACE_FLAG_KERNING
value|( 1L<<  6 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_FAST_GLYPHS
define|#
directive|define
name|FT_FACE_FLAG_FAST_GLYPHS
value|( 1L<<  7 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_MULTIPLE_MASTERS
define|#
directive|define
name|FT_FACE_FLAG_MULTIPLE_MASTERS
value|( 1L<<  8 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_GLYPH_NAMES
define|#
directive|define
name|FT_FACE_FLAG_GLYPH_NAMES
value|( 1L<<  9 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_EXTERNAL_STREAM
define|#
directive|define
name|FT_FACE_FLAG_EXTERNAL_STREAM
value|( 1L<< 10 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_HINTER
define|#
directive|define
name|FT_FACE_FLAG_HINTER
value|( 1L<< 11 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_CID_KEYED
define|#
directive|define
name|FT_FACE_FLAG_CID_KEYED
value|( 1L<< 12 )
end_define
begin_define
DECL|macro|FT_FACE_FLAG_TRICKY
define|#
directive|define
name|FT_FACE_FLAG_TRICKY
value|( 1L<< 13 )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_HORIZONTAL( face )    *    * @description:    *   A macro that returns true whenever a face object contains    *   horizontal metrics (this is true for all font formats though).    *    * @also:    *   @FT_HAS_VERTICAL can be used to check for vertical metrics.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_HORIZONTAL
define|#
directive|define
name|FT_HAS_HORIZONTAL
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_HORIZONTAL )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_VERTICAL( face )    *    * @description:    *   A macro that returns true whenever a face object contains vertical    *   metrics.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_VERTICAL
define|#
directive|define
name|FT_HAS_VERTICAL
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_VERTICAL )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_KERNING( face )    *    * @description:    *   A macro that returns true whenever a face object contains kerning    *   data that can be accessed with @FT_Get_Kerning.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_KERNING
define|#
directive|define
name|FT_HAS_KERNING
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_KERNING )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_IS_SCALABLE( face )    *    * @description:    *   A macro that returns true whenever a face object contains a scalable    *   font face (true for TrueType, Type~1, Type~42, CID, OpenType/CFF,    *   and PFR font formats.    *    */
end_comment
begin_define
DECL|macro|FT_IS_SCALABLE
define|#
directive|define
name|FT_IS_SCALABLE
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_SCALABLE )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_IS_SFNT( face )    *    * @description:    *   A macro that returns true whenever a face object contains a font    *   whose format is based on the SFNT storage scheme.  This usually    *   means: TrueType fonts, OpenType fonts, as well as SFNT-based embedded    *   bitmap fonts.    *    *   If this macro is true, all functions defined in @FT_SFNT_NAMES_H and    *   @FT_TRUETYPE_TABLES_H are available.    *    */
end_comment
begin_define
DECL|macro|FT_IS_SFNT
define|#
directive|define
name|FT_IS_SFNT
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_SFNT )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_IS_FIXED_WIDTH( face )    *    * @description:    *   A macro that returns true whenever a face object contains a font face    *   that contains fixed-width (or `monospace', `fixed-pitch', etc.)    *   glyphs.    *    */
end_comment
begin_define
DECL|macro|FT_IS_FIXED_WIDTH
define|#
directive|define
name|FT_IS_FIXED_WIDTH
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_FIXED_WIDTH )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_FIXED_SIZES( face )    *    * @description:    *   A macro that returns true whenever a face object contains some    *   embedded bitmaps.  See the `available_sizes' field of the    *   @FT_FaceRec structure.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_FIXED_SIZES
define|#
directive|define
name|FT_HAS_FIXED_SIZES
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_FIXED_SIZES )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_FAST_GLYPHS( face )    *    * @description:    *   Deprecated.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_FAST_GLYPHS
define|#
directive|define
name|FT_HAS_FAST_GLYPHS
parameter_list|(
name|face
parameter_list|)
value|0
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_GLYPH_NAMES( face )    *    * @description:    *   A macro that returns true whenever a face object contains some glyph    *   names that can be accessed through @FT_Get_Glyph_Name.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_GLYPH_NAMES
define|#
directive|define
name|FT_HAS_GLYPH_NAMES
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_GLYPH_NAMES )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_HAS_MULTIPLE_MASTERS( face )    *    * @description:    *   A macro that returns true whenever a face object contains some    *   multiple masters.  The functions provided by @FT_MULTIPLE_MASTERS_H    *   are then available to choose the exact design you want.    *    */
end_comment
begin_define
DECL|macro|FT_HAS_MULTIPLE_MASTERS
define|#
directive|define
name|FT_HAS_MULTIPLE_MASTERS
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_MULTIPLE_MASTERS )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_IS_CID_KEYED( face )    *    * @description:    *   A macro that returns true whenever a face object contains a CID-keyed    *   font.  See the discussion of @FT_FACE_FLAG_CID_KEYED for more    *   details.    *    *   If this macro is true, all functions defined in @FT_CID_H are    *   available.    *    */
end_comment
begin_define
DECL|macro|FT_IS_CID_KEYED
define|#
directive|define
name|FT_IS_CID_KEYED
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_CID_KEYED )
end_define
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_IS_TRICKY( face )    *    * @description:    *   A macro that returns true whenever a face represents a `tricky' font.    *   See the discussion of @FT_FACE_FLAG_TRICKY for more details.    *    */
end_comment
begin_define
DECL|macro|FT_IS_TRICKY
define|#
directive|define
name|FT_IS_TRICKY
parameter_list|(
name|face
parameter_list|)
define|\
value|( face->face_flags& FT_FACE_FLAG_TRICKY )
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Const>                                                               */
end_comment
begin_comment
comment|/*    FT_STYLE_FLAG_XXX                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of bit-flags used to indicate the style of a given face.    */
end_comment
begin_comment
comment|/*    These are used in the `style_flags' field of @FT_FaceRec.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_STYLE_FLAG_ITALIC ::                                            */
end_comment
begin_comment
comment|/*      Indicates that a given face style is italic or oblique.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_STYLE_FLAG_BOLD ::                                              */
end_comment
begin_comment
comment|/*      Indicates that a given face is bold.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The style information as provided by FreeType is very basic.  More */
end_comment
begin_comment
comment|/*    details are beyond the scope and should be done on a higher level  */
end_comment
begin_comment
comment|/*    (for example, by analyzing various fields of the `OS/2' table in   */
end_comment
begin_comment
comment|/*    SFNT based fonts).                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_STYLE_FLAG_ITALIC
define|#
directive|define
name|FT_STYLE_FLAG_ITALIC
value|( 1<< 0 )
end_define
begin_define
DECL|macro|FT_STYLE_FLAG_BOLD
define|#
directive|define
name|FT_STYLE_FLAG_BOLD
value|( 1<< 1 )
end_define
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
comment|/*    FT_Size_Internal                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An opaque handle to an `FT_Size_InternalRec' structure, used to    */
end_comment
begin_comment
comment|/*    model private data of a given @FT_Size object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Size_Internal
typedef|typedef
name|struct
name|FT_Size_InternalRec_
modifier|*
name|FT_Size_Internal
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
comment|/*    FT_Size_Metrics                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The size metrics structure gives the metrics of a size object.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    x_ppem       :: The width of the scaled EM square in pixels, hence */
end_comment
begin_comment
comment|/*                    the term `ppem' (pixels per EM).  It is also       */
end_comment
begin_comment
comment|/*                    referred to as `nominal width'.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_ppem       :: The height of the scaled EM square in pixels,      */
end_comment
begin_comment
comment|/*                    hence the term `ppem' (pixels per EM).  It is also */
end_comment
begin_comment
comment|/*                    referred to as `nominal height'.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    x_scale      :: A 16.16 fractional scaling value used to convert   */
end_comment
begin_comment
comment|/*                    horizontal metrics from font units to 26.6         */
end_comment
begin_comment
comment|/*                    fractional pixels.  Only relevant for scalable     */
end_comment
begin_comment
comment|/*                    font formats.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    y_scale      :: A 16.16 fractional scaling value used to convert   */
end_comment
begin_comment
comment|/*                    vertical metrics from font units to 26.6           */
end_comment
begin_comment
comment|/*                    fractional pixels.  Only relevant for scalable     */
end_comment
begin_comment
comment|/*                    font formats.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ascender     :: The ascender in 26.6 fractional pixels.  See       */
end_comment
begin_comment
comment|/*                    @FT_FaceRec for the details.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    descender    :: The descender in 26.6 fractional pixels.  See      */
end_comment
begin_comment
comment|/*                    @FT_FaceRec for the details.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    height       :: The height in 26.6 fractional pixels.  See         */
end_comment
begin_comment
comment|/*                    @FT_FaceRec for the details.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_advance  :: The maximal advance width in 26.6 fractional       */
end_comment
begin_comment
comment|/*                    pixels.  See @FT_FaceRec for the details.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The scaling values, if relevant, are determined first during a     */
end_comment
begin_comment
comment|/*    size changing operation.  The remaining fields are then set by the */
end_comment
begin_comment
comment|/*    driver.  For scalable formats, they are usually set to scaled      */
end_comment
begin_comment
comment|/*    values of the corresponding fields in @FT_FaceRec.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that due to glyph hinting, these values might not be exact    */
end_comment
begin_comment
comment|/*    for certain fonts.  Thus they must be treated as unreliable        */
end_comment
begin_comment
comment|/*    with an error margin of at least one pixel!                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Indeed, the only way to get the exact metrics is to render _all_   */
end_comment
begin_comment
comment|/*    glyphs.  As this would be a definite performance hit, it is up to  */
end_comment
begin_comment
comment|/*    client applications to perform such computations.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The FT_Size_Metrics structure is valid for bitmap fonts also.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Size_Metrics_
typedef|typedef
struct|struct
name|FT_Size_Metrics_
block|{
DECL|member|x_ppem
name|FT_UShort
name|x_ppem
decl_stmt|;
comment|/* horizontal pixels per EM               */
DECL|member|y_ppem
name|FT_UShort
name|y_ppem
decl_stmt|;
comment|/* vertical pixels per EM                 */
DECL|member|x_scale
name|FT_Fixed
name|x_scale
decl_stmt|;
comment|/* scaling values used to convert font    */
DECL|member|y_scale
name|FT_Fixed
name|y_scale
decl_stmt|;
comment|/* units to 26.6 fractional pixels        */
DECL|member|ascender
name|FT_Pos
name|ascender
decl_stmt|;
comment|/* ascender in 26.6 frac. pixels          */
DECL|member|descender
name|FT_Pos
name|descender
decl_stmt|;
comment|/* descender in 26.6 frac. pixels         */
DECL|member|height
name|FT_Pos
name|height
decl_stmt|;
comment|/* text height in 26.6 frac. pixels       */
DECL|member|max_advance
name|FT_Pos
name|max_advance
decl_stmt|;
comment|/* max horizontal advance, in 26.6 pixels */
block|}
DECL|typedef|FT_Size_Metrics
name|FT_Size_Metrics
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
comment|/*    FT_SizeRec                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    FreeType root size class structure.  A size object models a face   */
end_comment
begin_comment
comment|/*    object at a given size.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    face    :: Handle to the parent face object.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    generic :: A typeless pointer, which is unused by the FreeType     */
end_comment
begin_comment
comment|/*               library or any of its drivers.  It can be used by       */
end_comment
begin_comment
comment|/*               client applications to link their own data to each size */
end_comment
begin_comment
comment|/*               object.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    metrics :: Metrics for this size object.  This field is read-only. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_SizeRec_
typedef|typedef
struct|struct
name|FT_SizeRec_
block|{
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
comment|/* parent face object              */
DECL|member|generic
name|FT_Generic
name|generic
decl_stmt|;
comment|/* generic pointer for client uses */
DECL|member|metrics
name|FT_Size_Metrics
name|metrics
decl_stmt|;
comment|/* size metrics                    */
DECL|member|internal
name|FT_Size_Internal
name|internal
decl_stmt|;
block|}
DECL|typedef|FT_SizeRec
name|FT_SizeRec
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
comment|/*    FT_SubGlyph                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The subglyph structure is an internal object used to describe      */
end_comment
begin_comment
comment|/*    subglyphs (for example, in the case of composites).                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The subglyph implementation is not part of the high-level API,     */
end_comment
begin_comment
comment|/*    hence the forward structure declaration.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    You can however retrieve subglyph information with                 */
end_comment
begin_comment
comment|/*    @FT_Get_SubGlyph_Info.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_SubGlyph
typedef|typedef
name|struct
name|FT_SubGlyphRec_
modifier|*
name|FT_SubGlyph
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
comment|/*    FT_Slot_Internal                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An opaque handle to an `FT_Slot_InternalRec' structure, used to    */
end_comment
begin_comment
comment|/*    model private data of a given @FT_GlyphSlot object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Slot_Internal
typedef|typedef
name|struct
name|FT_Slot_InternalRec_
modifier|*
name|FT_Slot_Internal
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
comment|/*    FT_GlyphSlotRec                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    FreeType root glyph slot class structure.  A glyph slot is a       */
end_comment
begin_comment
comment|/*    container where individual glyphs can be loaded, be they in        */
end_comment
begin_comment
comment|/*    outline or bitmap format.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    library           :: A handle to the FreeType library instance     */
end_comment
begin_comment
comment|/*                         this slot belongs to.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face              :: A handle to the parent face object.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    next              :: In some cases (like some font tools), several */
end_comment
begin_comment
comment|/*                         glyph slots per face object can be a good     */
end_comment
begin_comment
comment|/*                         thing.  As this is rare, the glyph slots are  */
end_comment
begin_comment
comment|/*                         listed through a direct, single-linked list   */
end_comment
begin_comment
comment|/*                         using its `next' field.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    generic           :: A typeless pointer which is unused by the     */
end_comment
begin_comment
comment|/*                         FreeType library or any of its drivers.  It   */
end_comment
begin_comment
comment|/*                         can be used by client applications to link    */
end_comment
begin_comment
comment|/*                         their own data to each glyph slot object.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    metrics           :: The metrics of the last loaded glyph in the   */
end_comment
begin_comment
comment|/*                         slot.  The returned values depend on the last */
end_comment
begin_comment
comment|/*                         load flags (see the @FT_Load_Glyph API        */
end_comment
begin_comment
comment|/*                         function) and can be expressed either in 26.6 */
end_comment
begin_comment
comment|/*                         fractional pixels or font units.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                         Note that even when the glyph image is        */
end_comment
begin_comment
comment|/*                         transformed, the metrics are not.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    linearHoriAdvance :: The advance width of the unhinted glyph.      */
end_comment
begin_comment
comment|/*                         Its value is expressed in 16.16 fractional    */
end_comment
begin_comment
comment|/*                         pixels, unless @FT_LOAD_LINEAR_DESIGN is set  */
end_comment
begin_comment
comment|/*                         when loading the glyph.  This field can be    */
end_comment
begin_comment
comment|/*                         important to perform correct WYSIWYG layout.  */
end_comment
begin_comment
comment|/*                         Only relevant for outline glyphs.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    linearVertAdvance :: The advance height of the unhinted glyph.     */
end_comment
begin_comment
comment|/*                         Its value is expressed in 16.16 fractional    */
end_comment
begin_comment
comment|/*                         pixels, unless @FT_LOAD_LINEAR_DESIGN is set  */
end_comment
begin_comment
comment|/*                         when loading the glyph.  This field can be    */
end_comment
begin_comment
comment|/*                         important to perform correct WYSIWYG layout.  */
end_comment
begin_comment
comment|/*                         Only relevant for outline glyphs.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance           :: This shorthand is, depending on               */
end_comment
begin_comment
comment|/*                         @FT_LOAD_IGNORE_TRANSFORM, the transformed    */
end_comment
begin_comment
comment|/*                         advance width for the glyph (in 26.6          */
end_comment
begin_comment
comment|/*                         fractional pixel format).  As specified with  */
end_comment
begin_comment
comment|/*                         @FT_LOAD_VERTICAL_LAYOUT, it uses either the  */
end_comment
begin_comment
comment|/*                         `horiAdvance' or the `vertAdvance' value of   */
end_comment
begin_comment
comment|/*                         `metrics' field.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format            :: This field indicates the format of the image  */
end_comment
begin_comment
comment|/*                         contained in the glyph slot.  Typically       */
end_comment
begin_comment
comment|/*                         @FT_GLYPH_FORMAT_BITMAP,                      */
end_comment
begin_comment
comment|/*                         @FT_GLYPH_FORMAT_OUTLINE, or                  */
end_comment
begin_comment
comment|/*                         @FT_GLYPH_FORMAT_COMPOSITE, but others are    */
end_comment
begin_comment
comment|/*                         possible.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bitmap            :: This field is used as a bitmap descriptor     */
end_comment
begin_comment
comment|/*                         when the slot format is                       */
end_comment
begin_comment
comment|/*                         @FT_GLYPH_FORMAT_BITMAP.  Note that the       */
end_comment
begin_comment
comment|/*                         address and content of the bitmap buffer can  */
end_comment
begin_comment
comment|/*                         change between calls of @FT_Load_Glyph and a  */
end_comment
begin_comment
comment|/*                         few other functions.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bitmap_left       :: This is the bitmap's left bearing expressed   */
end_comment
begin_comment
comment|/*                         in integer pixels.  Of course, this is only   */
end_comment
begin_comment
comment|/*                         valid if the format is                        */
end_comment
begin_comment
comment|/*                         @FT_GLYPH_FORMAT_BITMAP.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bitmap_top        :: This is the bitmap's top bearing expressed in */
end_comment
begin_comment
comment|/*                         integer pixels.  Remember that this is the    */
end_comment
begin_comment
comment|/*                         distance from the baseline to the top-most    */
end_comment
begin_comment
comment|/*                         glyph scanline, upwards y~coordinates being   */
end_comment
begin_comment
comment|/*                         *positive*.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    outline           :: The outline descriptor for the current glyph  */
end_comment
begin_comment
comment|/*                         image if its format is                        */
end_comment
begin_comment
comment|/*                         @FT_GLYPH_FORMAT_OUTLINE.  Once a glyph is    */
end_comment
begin_comment
comment|/*                         loaded, `outline' can be transformed,         */
end_comment
begin_comment
comment|/*                         distorted, embolded, etc.  However, it must   */
end_comment
begin_comment
comment|/*                         not be freed.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_subglyphs     :: The number of subglyphs in a composite glyph. */
end_comment
begin_comment
comment|/*                         This field is only valid for the composite    */
end_comment
begin_comment
comment|/*                         glyph format that should normally only be     */
end_comment
begin_comment
comment|/*                         loaded with the @FT_LOAD_NO_RECURSE flag.     */
end_comment
begin_comment
comment|/*                         For now this is internal to FreeType.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    subglyphs         :: An array of subglyph descriptors for          */
end_comment
begin_comment
comment|/*                         composite glyphs.  There are `num_subglyphs'  */
end_comment
begin_comment
comment|/*                         elements in there.  Currently internal to     */
end_comment
begin_comment
comment|/*                         FreeType.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    control_data      :: Certain font drivers can also return the      */
end_comment
begin_comment
comment|/*                         control data for a given glyph image (e.g.    */
end_comment
begin_comment
comment|/*                         TrueType bytecode, Type~1 charstrings, etc.). */
end_comment
begin_comment
comment|/*                         This field is a pointer to such data.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    control_len       :: This is the length in bytes of the control    */
end_comment
begin_comment
comment|/*                         data.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    other             :: Really wicked formats can use this pointer to */
end_comment
begin_comment
comment|/*                         present their own glyph image to client       */
end_comment
begin_comment
comment|/*                         applications.  Note that the application      */
end_comment
begin_comment
comment|/*                         needs to know about the image format.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    lsb_delta         :: The difference between hinted and unhinted    */
end_comment
begin_comment
comment|/*                         left side bearing while autohinting is        */
end_comment
begin_comment
comment|/*                         active.  Zero otherwise.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    rsb_delta         :: The difference between hinted and unhinted    */
end_comment
begin_comment
comment|/*                         right side bearing while autohinting is       */
end_comment
begin_comment
comment|/*                         active.  Zero otherwise.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If @FT_Load_Glyph is called with default flags (see                */
end_comment
begin_comment
comment|/*    @FT_LOAD_DEFAULT) the glyph image is loaded in the glyph slot in   */
end_comment
begin_comment
comment|/*    its native format (e.g., an outline glyph for TrueType and Type~1  */
end_comment
begin_comment
comment|/*    formats).                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This image can later be converted into a bitmap by calling         */
end_comment
begin_comment
comment|/*    @FT_Render_Glyph.  This function finds the current renderer for    */
end_comment
begin_comment
comment|/*    the native image's format, then invokes it.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The renderer is in charge of transforming the native image through */
end_comment
begin_comment
comment|/*    the slot's face transformation fields, then converting it into a   */
end_comment
begin_comment
comment|/*    bitmap that is returned in `slot->bitmap'.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that `slot->bitmap_left' and `slot->bitmap_top' are also used */
end_comment
begin_comment
comment|/*    to specify the position of the bitmap relative to the current pen  */
end_comment
begin_comment
comment|/*    position (e.g., coordinates (0,0) on the baseline).  Of course,    */
end_comment
begin_comment
comment|/*    `slot->format' is also changed to @FT_GLYPH_FORMAT_BITMAP.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Here a small pseudo code fragment which shows how to use           */
end_comment
begin_comment
comment|/*    `lsb_delta' and `rsb_delta':                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      FT_Pos  origin_x       = 0;                                      */
end_comment
begin_comment
comment|/*      FT_Pos  prev_rsb_delta = 0;                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      for all glyphs do                                                */
end_comment
begin_comment
comment|/*<compute kern between current and previous glyph and add it to */
end_comment
begin_comment
comment|/*         `origin_x'>                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<load glyph with `FT_Load_Glyph'>                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        if ( prev_rsb_delta - face->glyph->lsb_delta>= 32 )           */
end_comment
begin_comment
comment|/*          origin_x -= 64;                                              */
end_comment
begin_comment
comment|/*        else if ( prev_rsb_delta - face->glyph->lsb_delta< -32 )      */
end_comment
begin_comment
comment|/*          origin_x += 64;                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        prev_rsb_delta = face->glyph->rsb_delta;                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<save glyph image, or render glyph, or ...>                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        origin_x += face->glyph->advance.x;                            */
end_comment
begin_comment
comment|/*      endfor                                                           */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_GlyphSlotRec_
typedef|typedef
struct|struct
name|FT_GlyphSlotRec_
block|{
DECL|member|library
name|FT_Library
name|library
decl_stmt|;
DECL|member|face
name|FT_Face
name|face
decl_stmt|;
DECL|member|next
name|FT_GlyphSlot
name|next
decl_stmt|;
DECL|member|reserved
name|FT_UInt
name|reserved
decl_stmt|;
comment|/* retained for binary compatibility */
DECL|member|generic
name|FT_Generic
name|generic
decl_stmt|;
DECL|member|metrics
name|FT_Glyph_Metrics
name|metrics
decl_stmt|;
DECL|member|linearHoriAdvance
name|FT_Fixed
name|linearHoriAdvance
decl_stmt|;
DECL|member|linearVertAdvance
name|FT_Fixed
name|linearVertAdvance
decl_stmt|;
DECL|member|advance
name|FT_Vector
name|advance
decl_stmt|;
DECL|member|format
name|FT_Glyph_Format
name|format
decl_stmt|;
DECL|member|bitmap
name|FT_Bitmap
name|bitmap
decl_stmt|;
DECL|member|bitmap_left
name|FT_Int
name|bitmap_left
decl_stmt|;
DECL|member|bitmap_top
name|FT_Int
name|bitmap_top
decl_stmt|;
DECL|member|outline
name|FT_Outline
name|outline
decl_stmt|;
DECL|member|num_subglyphs
name|FT_UInt
name|num_subglyphs
decl_stmt|;
DECL|member|subglyphs
name|FT_SubGlyph
name|subglyphs
decl_stmt|;
DECL|member|control_data
name|void
modifier|*
name|control_data
decl_stmt|;
DECL|member|control_len
name|long
name|control_len
decl_stmt|;
DECL|member|lsb_delta
name|FT_Pos
name|lsb_delta
decl_stmt|;
DECL|member|rsb_delta
name|FT_Pos
name|rsb_delta
decl_stmt|;
DECL|member|other
name|void
modifier|*
name|other
decl_stmt|;
DECL|member|internal
name|FT_Slot_Internal
name|internal
decl_stmt|;
block|}
DECL|typedef|FT_GlyphSlotRec
name|FT_GlyphSlotRec
typedef|;
end_typedef
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
comment|/*                         F U N C T I O N S                             */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Init_FreeType                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Initialize a new FreeType library object.  The set of modules      */
end_comment
begin_comment
comment|/*    that are registered by this function is determined at build time.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    alibrary :: A handle to a new library object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    In case you want to provide your own memory allocating routines,   */
end_comment
begin_comment
comment|/*    use @FT_New_Library instead, followed by a call to                 */
end_comment
begin_comment
comment|/*    @FT_Add_Default_Modules (or a series of calls to @FT_Add_Module).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_expr_stmt
name|FT_Init_FreeType
argument_list|(
name|FT_Library
operator|*
name|alibrary
argument_list|)
expr_stmt|;
end_expr_stmt
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
comment|/*    FT_Done_FreeType                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroy a given FreeType library object and all of its children,   */
end_comment
begin_comment
comment|/*    including resources, drivers, faces, sizes, etc.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to the target library object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Done_FreeType
name|FT_Done_FreeType
argument_list|(
argument|FT_Library  library
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Done_FreeType
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
comment|/*    FT_OPEN_XXX                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of bit-field constants used within the `flags' field of the */
end_comment
begin_comment
comment|/*    @FT_Open_Args structure.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_OPEN_MEMORY   :: This is a memory-based stream.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_OPEN_STREAM   :: Copy the stream from the `stream' field.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_OPEN_PATHNAME :: Create a new input stream from a C~path        */
end_comment
begin_comment
comment|/*                        name.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_OPEN_DRIVER   :: Use the `driver' field.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_OPEN_PARAMS   :: Use the `num_params' and `params' fields.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ft_open_memory   :: Deprecated; use @FT_OPEN_MEMORY instead.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ft_open_stream   :: Deprecated; use @FT_OPEN_STREAM instead.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ft_open_pathname :: Deprecated; use @FT_OPEN_PATHNAME instead.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ft_open_driver   :: Deprecated; use @FT_OPEN_DRIVER instead.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ft_open_params   :: Deprecated; use @FT_OPEN_PARAMS instead.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The `FT_OPEN_MEMORY', `FT_OPEN_STREAM', and `FT_OPEN_PATHNAME'     */
end_comment
begin_comment
comment|/*    flags are mutually exclusive.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_OPEN_MEMORY
define|#
directive|define
name|FT_OPEN_MEMORY
value|0x1
end_define
begin_define
DECL|macro|FT_OPEN_STREAM
define|#
directive|define
name|FT_OPEN_STREAM
value|0x2
end_define
begin_define
DECL|macro|FT_OPEN_PATHNAME
define|#
directive|define
name|FT_OPEN_PATHNAME
value|0x4
end_define
begin_define
DECL|macro|FT_OPEN_DRIVER
define|#
directive|define
name|FT_OPEN_DRIVER
value|0x8
end_define
begin_define
DECL|macro|FT_OPEN_PARAMS
define|#
directive|define
name|FT_OPEN_PARAMS
value|0x10
end_define
begin_define
DECL|macro|ft_open_memory
define|#
directive|define
name|ft_open_memory
value|FT_OPEN_MEMORY
end_define
begin_comment
DECL|macro|ft_open_memory
comment|/* deprecated */
end_comment
begin_define
DECL|macro|ft_open_stream
define|#
directive|define
name|ft_open_stream
value|FT_OPEN_STREAM
end_define
begin_comment
DECL|macro|ft_open_stream
comment|/* deprecated */
end_comment
begin_define
DECL|macro|ft_open_pathname
define|#
directive|define
name|ft_open_pathname
value|FT_OPEN_PATHNAME
end_define
begin_comment
DECL|macro|ft_open_pathname
comment|/* deprecated */
end_comment
begin_define
DECL|macro|ft_open_driver
define|#
directive|define
name|ft_open_driver
value|FT_OPEN_DRIVER
end_define
begin_comment
DECL|macro|ft_open_driver
comment|/* deprecated */
end_comment
begin_define
DECL|macro|ft_open_params
define|#
directive|define
name|ft_open_params
value|FT_OPEN_PARAMS
end_define
begin_comment
DECL|macro|ft_open_params
comment|/* deprecated */
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
comment|/*    FT_Parameter                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to pass more or less generic parameters to */
end_comment
begin_comment
comment|/*    @FT_Open_Face.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    tag  :: A four-byte identification tag.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    data :: A pointer to the parameter data.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The ID and function of parameters are driver-specific.  See the    */
end_comment
begin_comment
comment|/*    various FT_PARAM_TAG_XXX flags for more information.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Parameter_
typedef|typedef
struct|struct
name|FT_Parameter_
block|{
DECL|member|tag
name|FT_ULong
name|tag
decl_stmt|;
DECL|member|data
name|FT_Pointer
name|data
decl_stmt|;
block|}
DECL|typedef|FT_Parameter
name|FT_Parameter
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
comment|/*    FT_Open_Args                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to indicate how to open a new font file or        */
end_comment
begin_comment
comment|/*    stream.  A pointer to such a structure can be used as a parameter  */
end_comment
begin_comment
comment|/*    for the functions @FT_Open_Face and @FT_Attach_Stream.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    flags       :: A set of bit flags indicating how to use the        */
end_comment
begin_comment
comment|/*                   structure.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    memory_base :: The first byte of the file in memory.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    memory_size :: The size in bytes of the file in memory.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pathname    :: A pointer to an 8-bit file pathname.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream      :: A handle to a source stream object.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    driver      :: This field is exclusively used by @FT_Open_Face;    */
end_comment
begin_comment
comment|/*                   it simply specifies the font driver to use to open  */
end_comment
begin_comment
comment|/*                   the face.  If set to~0, FreeType tries to load the  */
end_comment
begin_comment
comment|/*                   face with each one of the drivers in its list.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_params  :: The number of extra parameters.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    params      :: Extra parameters passed to the font driver when     */
end_comment
begin_comment
comment|/*                   opening a new face.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The stream type is determined by the contents of `flags' which     */
end_comment
begin_comment
comment|/*    are tested in the following order by @FT_Open_Face:                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If the `FT_OPEN_MEMORY' bit is set, assume that this is a          */
end_comment
begin_comment
comment|/*    memory file of `memory_size' bytes, located at `memory_address'.   */
end_comment
begin_comment
comment|/*    The data are are not copied, and the client is responsible for     */
end_comment
begin_comment
comment|/*    releasing and destroying them _after_ the corresponding call to    */
end_comment
begin_comment
comment|/*    @FT_Done_Face.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Otherwise, if the `FT_OPEN_STREAM' bit is set, assume that a       */
end_comment
begin_comment
comment|/*    custom input stream `stream' is used.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Otherwise, if the `FT_OPEN_PATHNAME' bit is set, assume that this  */
end_comment
begin_comment
comment|/*    is a normal file and use `pathname' to open it.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If the `FT_OPEN_DRIVER' bit is set, @FT_Open_Face only tries to    */
end_comment
begin_comment
comment|/*    open the file with the driver whose handler is in `driver'.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If the `FT_OPEN_PARAMS' bit is set, the parameters given by        */
end_comment
begin_comment
comment|/*    `num_params' and `params' is used.  They are ignored otherwise.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Ideally, both the `pathname' and `params' fields should be tagged  */
end_comment
begin_comment
comment|/*    as `const'; this is missing for API backwards compatibility.  In   */
end_comment
begin_comment
comment|/*    other words, applications should treat them as read-only.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Open_Args_
typedef|typedef
struct|struct
name|FT_Open_Args_
block|{
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
DECL|member|memory_base
specifier|const
name|FT_Byte
modifier|*
name|memory_base
decl_stmt|;
DECL|member|memory_size
name|FT_Long
name|memory_size
decl_stmt|;
DECL|member|pathname
name|FT_String
modifier|*
name|pathname
decl_stmt|;
DECL|member|stream
name|FT_Stream
name|stream
decl_stmt|;
DECL|member|driver
name|FT_Module
name|driver
decl_stmt|;
DECL|member|num_params
name|FT_Int
name|num_params
decl_stmt|;
DECL|member|params
name|FT_Parameter
modifier|*
name|params
decl_stmt|;
block|}
DECL|typedef|FT_Open_Args
name|FT_Open_Args
typedef|;
end_typedef
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
comment|/*    FT_New_Face                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function calls @FT_Open_Face to open a font by its pathname.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library resource.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    pathname   :: A path to the font file.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the face within the font.  The first    */
end_comment
begin_comment
comment|/*                  face has index~0.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aface      :: A handle to a new face object.  If `face_index' is   */
end_comment
begin_comment
comment|/*                  greater than or equal to zero, it must be non-NULL.  */
end_comment
begin_comment
comment|/*                  See @FT_Open_Face for more details.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_New_Face
argument_list|(
argument|FT_Library   library
argument_list|,
argument|const char*  filepathname
argument_list|,
argument|FT_Long      face_index
argument_list|,
argument|FT_Face     *aface
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
comment|/*    FT_New_Memory_Face                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function calls @FT_Open_Face to open a font which has been    */
end_comment
begin_comment
comment|/*    loaded into memory.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library resource.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    file_base  :: A pointer to the beginning of the font data.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    file_size  :: The size of the memory chunk used by the font data.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the face within the font.  The first    */
end_comment
begin_comment
comment|/*                  face has index~0.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aface      :: A handle to a new face object.  If `face_index' is   */
end_comment
begin_comment
comment|/*                  greater than or equal to zero, it must be non-NULL.  */
end_comment
begin_comment
comment|/*                  See @FT_Open_Face for more details.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You must not deallocate the memory before calling @FT_Done_Face.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_New_Memory_Face
name|FT_New_Memory_Face
argument_list|(
argument|FT_Library      library
argument_list|,
argument|const FT_Byte*  file_base
argument_list|,
argument|FT_Long         file_size
argument_list|,
argument|FT_Long         face_index
argument_list|,
argument|FT_Face        *aface
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
comment|/*    FT_Open_Face                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a face object from a given resource described by            */
end_comment
begin_comment
comment|/*    @FT_Open_Args.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library resource.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    args       :: A pointer to an `FT_Open_Args' structure which must  */
end_comment
begin_comment
comment|/*                  be filled by the caller.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the face within the font.  The first    */
end_comment
begin_comment
comment|/*                  face has index~0.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aface      :: A handle to a new face object.  If `face_index' is   */
end_comment
begin_comment
comment|/*                  greater than or equal to zero, it must be non-NULL.  */
end_comment
begin_comment
comment|/*                  See note below.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Unlike FreeType 1.x, this function automatically creates a glyph   */
end_comment
begin_comment
comment|/*    slot for the face object which can be accessed directly through    */
end_comment
begin_comment
comment|/*    `face->glyph'.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_Open_Face can be used to quickly check whether the font         */
end_comment
begin_comment
comment|/*    format of a given font resource is supported by FreeType.  If the  */
end_comment
begin_comment
comment|/*    `face_index' field is negative, the function's return value is~0   */
end_comment
begin_comment
comment|/*    if the font format is recognized, or non-zero otherwise;           */
end_comment
begin_comment
comment|/*    the function returns a more or less empty face handle in `*aface'  */
end_comment
begin_comment
comment|/*    (if `aface' isn't NULL).  The only useful field in this special    */
end_comment
begin_comment
comment|/*    case is `face->num_faces' which gives the number of faces within   */
end_comment
begin_comment
comment|/*    the font file.  After examination, the returned @FT_Face structure */
end_comment
begin_comment
comment|/*    should be deallocated with a call to @FT_Done_Face.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Each new face object created with this function also owns a        */
end_comment
begin_comment
comment|/*    default @FT_Size object, accessible as `face->size'.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Open_Face
argument_list|(
argument|FT_Library           library
argument_list|,
argument|const FT_Open_Args*  args
argument_list|,
argument|FT_Long              face_index
argument_list|,
argument|FT_Face             *aface
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
comment|/*    FT_Attach_File                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function calls @FT_Attach_Stream to attach a file.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face         :: The target face object.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    filepathname :: The pathname.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Attach_File
name|FT_Attach_File
argument_list|(
argument|FT_Face      face
argument_list|,
argument|const char*  filepathname
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
comment|/*    FT_Attach_Stream                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    `Attach' data to a face object.  Normally, this is used to read    */
end_comment
begin_comment
comment|/*    additional information for the face object.  For example, you can  */
end_comment
begin_comment
comment|/*    attach an AFM file that comes with a Type~1 font to get the        */
end_comment
begin_comment
comment|/*    kerning values and other metrics.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face       :: The target face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    parameters :: A pointer to @FT_Open_Args which must be filled by   */
end_comment
begin_comment
comment|/*                  the caller.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The meaning of the `attach' (i.e., what really happens when the    */
end_comment
begin_comment
comment|/*    new file is read) is not fixed by FreeType itself.  It really      */
end_comment
begin_comment
comment|/*    depends on the font format (and thus the font driver).             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Client applications are expected to know what they are doing       */
end_comment
begin_comment
comment|/*    when invoking this function.  Most drivers simply do not implement */
end_comment
begin_comment
comment|/*    file attachments.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Attach_Stream
argument_list|(
argument|FT_Face        face
argument_list|,
argument|FT_Open_Args*  parameters
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
comment|/*    FT_Done_Face                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Discard a given face object, as well as all of its child slots and */
end_comment
begin_comment
comment|/*    sizes.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to a target face object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Done_Face
name|FT_Done_Face
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Done_Face
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
comment|/*    FT_Select_Size                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Select a bitmap strike.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face         :: A handle to a target face object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    strike_index :: The index of the bitmap strike in the              */
end_comment
begin_comment
comment|/*                    `available_sizes' field of @FT_FaceRec structure.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Select_Size
argument_list|(
argument|FT_Face  face
argument_list|,
argument|FT_Int   strike_index
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
comment|/*    FT_Size_Request_Type                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration type that lists the supported size request types.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_SIZE_REQUEST_TYPE_NOMINAL ::                                    */
end_comment
begin_comment
comment|/*      The nominal size.  The `units_per_EM' field of @FT_FaceRec is    */
end_comment
begin_comment
comment|/*      used to determine both scaling values.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SIZE_REQUEST_TYPE_REAL_DIM ::                                   */
end_comment
begin_comment
comment|/*      The real dimension.  The sum of the the `Ascender' and (minus    */
end_comment
begin_comment
comment|/*      of) the `Descender' fields of @FT_FaceRec are used to determine  */
end_comment
begin_comment
comment|/*      both scaling values.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SIZE_REQUEST_TYPE_BBOX ::                                       */
end_comment
begin_comment
comment|/*      The font bounding box.  The width and height of the `bbox' field */
end_comment
begin_comment
comment|/*      of @FT_FaceRec are used to determine the horizontal and vertical */
end_comment
begin_comment
comment|/*      scaling value, respectively.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SIZE_REQUEST_TYPE_CELL ::                                       */
end_comment
begin_comment
comment|/*      The `max_advance_width' field of @FT_FaceRec is used to          */
end_comment
begin_comment
comment|/*      determine the horizontal scaling value; the vertical scaling     */
end_comment
begin_comment
comment|/*      value is determined the same way as                              */
end_comment
begin_comment
comment|/*      @FT_SIZE_REQUEST_TYPE_REAL_DIM does.  Finally, both scaling      */
end_comment
begin_comment
comment|/*      values are set to the smaller one.  This type is useful if you   */
end_comment
begin_comment
comment|/*      want to specify the font size for, say, a window of a given      */
end_comment
begin_comment
comment|/*      dimension and 80x24 cells.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_SIZE_REQUEST_TYPE_SCALES ::                                     */
end_comment
begin_comment
comment|/*      Specify the scaling values directly.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The above descriptions only apply to scalable formats.  For bitmap */
end_comment
begin_comment
comment|/*    formats, the behaviour is up to the driver.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    See the note section of @FT_Size_Metrics if you wonder how size    */
end_comment
begin_comment
comment|/*    requesting relates to scaling values.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_Size_Request_Type_
typedef|typedef
enum|enum
name|FT_Size_Request_Type_
block|{
DECL|enumerator|FT_SIZE_REQUEST_TYPE_NOMINAL
name|FT_SIZE_REQUEST_TYPE_NOMINAL
block|,
DECL|enumerator|FT_SIZE_REQUEST_TYPE_REAL_DIM
name|FT_SIZE_REQUEST_TYPE_REAL_DIM
block|,
DECL|enumerator|FT_SIZE_REQUEST_TYPE_BBOX
name|FT_SIZE_REQUEST_TYPE_BBOX
block|,
DECL|enumerator|FT_SIZE_REQUEST_TYPE_CELL
name|FT_SIZE_REQUEST_TYPE_CELL
block|,
DECL|enumerator|FT_SIZE_REQUEST_TYPE_SCALES
name|FT_SIZE_REQUEST_TYPE_SCALES
block|,
DECL|enumerator|FT_SIZE_REQUEST_TYPE_MAX
name|FT_SIZE_REQUEST_TYPE_MAX
block|}
DECL|typedef|FT_Size_Request_Type
name|FT_Size_Request_Type
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
comment|/*    FT_Size_RequestRec                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model a size request.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    type           :: See @FT_Size_Request_Type.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    width          :: The desired width.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    height         :: The desired height.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horiResolution :: The horizontal resolution.  If set to zero,      */
end_comment
begin_comment
comment|/*                      `width' is treated as a 26.6 fractional pixel    */
end_comment
begin_comment
comment|/*                      value.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertResolution :: The vertical resolution.  If set to zero,        */
end_comment
begin_comment
comment|/*                      `height' is treated as a 26.6 fractional pixel   */
end_comment
begin_comment
comment|/*                      value.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If `width' is zero, then the horizontal scaling value is set equal */
end_comment
begin_comment
comment|/*    to the vertical scaling value, and vice versa.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Size_RequestRec_
typedef|typedef
struct|struct
name|FT_Size_RequestRec_
block|{
DECL|member|type
name|FT_Size_Request_Type
name|type
decl_stmt|;
DECL|member|width
name|FT_Long
name|width
decl_stmt|;
DECL|member|height
name|FT_Long
name|height
decl_stmt|;
DECL|member|horiResolution
name|FT_UInt
name|horiResolution
decl_stmt|;
DECL|member|vertResolution
name|FT_UInt
name|vertResolution
decl_stmt|;
block|}
DECL|typedef|FT_Size_RequestRec
name|FT_Size_RequestRec
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
comment|/*    FT_Size_Request                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to a size request structure.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Size_Request
typedef|typedef
name|struct
name|FT_Size_RequestRec_
modifier|*
name|FT_Size_Request
typedef|;
end_typedef
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
comment|/*    FT_Request_Size                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Resize the scale of the active @FT_Size object in a face.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to a target face object.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    req  :: A pointer to a @FT_Size_RequestRec.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Although drivers may select the bitmap strike matching the         */
end_comment
begin_comment
comment|/*    request, you should not rely on this if you intend to select a     */
end_comment
begin_comment
comment|/*    particular bitmap strike.  Use @FT_Select_Size instead in that     */
end_comment
begin_comment
comment|/*    case.                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Request_Size
argument_list|(
argument|FT_Face          face
argument_list|,
argument|FT_Size_Request  req
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
comment|/*    FT_Set_Char_Size                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function calls @FT_Request_Size to request the nominal size   */
end_comment
begin_comment
comment|/*    (in points).                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face            :: A handle to a target face object.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    char_width      :: The nominal width, in 26.6 fractional points.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    char_height     :: The nominal height, in 26.6 fractional points.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    horz_resolution :: The horizontal resolution in dpi.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vert_resolution :: The vertical resolution in dpi.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If either the character width or height is zero, it is set equal   */
end_comment
begin_comment
comment|/*    to the other value.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If either the horizontal or vertical resolution is zero, it is set */
end_comment
begin_comment
comment|/*    equal to the other value.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A character width or height smaller than 1pt is set to 1pt; if     */
end_comment
begin_comment
comment|/*    both resolution values are zero, they are set to 72dpi.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Don't use this function if you are using the FreeType cache API.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Set_Char_Size
name|FT_Set_Char_Size
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_F26Dot6  char_width
argument_list|,
argument|FT_F26Dot6  char_height
argument_list|,
argument|FT_UInt     horz_resolution
argument_list|,
argument|FT_UInt     vert_resolution
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
comment|/*    FT_Set_Pixel_Sizes                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function calls @FT_Request_Size to request the nominal size   */
end_comment
begin_comment
comment|/*    (in pixels).                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face         :: A handle to the target face object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    pixel_width  :: The nominal width, in pixels.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pixel_height :: The nominal height, in pixels.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Set_Pixel_Sizes
argument_list|(
argument|FT_Face  face
argument_list|,
argument|FT_UInt  pixel_width
argument_list|,
argument|FT_UInt  pixel_height
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
comment|/*    FT_Load_Glyph                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to load a single glyph into the glyph slot of a    */
end_comment
begin_comment
comment|/*    face object.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face        :: A handle to the target face object where the glyph  */
end_comment
begin_comment
comment|/*                   is loaded.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    glyph_index :: The index of the glyph in the font file.  For       */
end_comment
begin_comment
comment|/*                   CID-keyed fonts (either in PS or in CFF format)     */
end_comment
begin_comment
comment|/*                   this argument specifies the CID value.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_flags  :: A flag indicating what to load for this glyph.  The */
end_comment
begin_comment
comment|/*                   @FT_LOAD_XXX constants can be used to control the   */
end_comment
begin_comment
comment|/*                   glyph loading process (e.g., whether the outline    */
end_comment
begin_comment
comment|/*                   should be scaled, whether to load bitmaps or not,   */
end_comment
begin_comment
comment|/*                   whether to hint the outline, etc).                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The loaded glyph may be transformed.  See @FT_Set_Transform for    */
end_comment
begin_comment
comment|/*    the details.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    For subsetted CID-keyed fonts, `FT_Err_Invalid_Argument' is        */
end_comment
begin_comment
comment|/*    returned for invalid CID values (this is, for CID values which     */
end_comment
begin_comment
comment|/*    don't have a corresponding glyph in the font).  See the discussion */
end_comment
begin_comment
comment|/*    of the @FT_FACE_FLAG_CID_KEYED flag for more details.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Load_Glyph
name|FT_Load_Glyph
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt   glyph_index
argument_list|,
argument|FT_Int32  load_flags
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
comment|/*    FT_Load_Char                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to load a single glyph into the glyph slot of a    */
end_comment
begin_comment
comment|/*    face object, according to its character code.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face        :: A handle to a target face object where the glyph    */
end_comment
begin_comment
comment|/*                   is loaded.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    char_code   :: The glyph's character code, according to the        */
end_comment
begin_comment
comment|/*                   current charmap used in the face.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_flags  :: A flag indicating what to load for this glyph.  The */
end_comment
begin_comment
comment|/*                   @FT_LOAD_XXX constants can be used to control the   */
end_comment
begin_comment
comment|/*                   glyph loading process (e.g., whether the outline    */
end_comment
begin_comment
comment|/*                   should be scaled, whether to load bitmaps or not,   */
end_comment
begin_comment
comment|/*                   whether to hint the outline, etc).                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function simply calls @FT_Get_Char_Index and @FT_Load_Glyph.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Load_Char
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  char_code
argument_list|,
argument|FT_Int32  load_flags
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @enum:    *   FT_LOAD_XXX    *    * @description:    *   A list of bit-field constants used with @FT_Load_Glyph to indicate    *   what kind of operations to perform during glyph loading.    *    * @values:    *   FT_LOAD_DEFAULT ::    *     Corresponding to~0, this value is used as the default glyph load    *     operation.  In this case, the following happens:    *    *     1. FreeType looks for a bitmap for the glyph corresponding to the    *        face's current size.  If one is found, the function returns.    *        The bitmap data can be accessed from the glyph slot (see note    *        below).    *    *     2. If no embedded bitmap is searched or found, FreeType looks for a    *        scalable outline.  If one is found, it is loaded from the font    *        file, scaled to device pixels, then `hinted' to the pixel grid    *        in order to optimize it.  The outline data can be accessed from    *        the glyph slot (see note below).    *    *     Note that by default, the glyph loader doesn't render outlines into    *     bitmaps.  The following flags are used to modify this default    *     behaviour to more specific and useful cases.    *    *   FT_LOAD_NO_SCALE ::    *     Don't scale the outline glyph loaded, but keep it in font units.    *    *     This flag implies @FT_LOAD_NO_HINTING and @FT_LOAD_NO_BITMAP, and    *     unsets @FT_LOAD_RENDER.    *    *   FT_LOAD_NO_HINTING ::    *     Disable hinting.  This generally generates `blurrier' bitmap glyph    *     when the glyph is rendered in any of the anti-aliased modes.  See    *     also the note below.    *    *     This flag is implied by @FT_LOAD_NO_SCALE.    *    *   FT_LOAD_RENDER ::    *     Call @FT_Render_Glyph after the glyph is loaded.  By default, the    *     glyph is rendered in @FT_RENDER_MODE_NORMAL mode.  This can be    *     overridden by @FT_LOAD_TARGET_XXX or @FT_LOAD_MONOCHROME.    *    *     This flag is unset by @FT_LOAD_NO_SCALE.    *    *   FT_LOAD_NO_BITMAP ::    *     Ignore bitmap strikes when loading.  Bitmap-only fonts ignore this    *     flag.    *    *     @FT_LOAD_NO_SCALE always sets this flag.    *    *   FT_LOAD_VERTICAL_LAYOUT ::    *     Load the glyph for vertical text layout.  _Don't_ use it as it is    *     problematic currently.    *    *   FT_LOAD_FORCE_AUTOHINT ::    *     Indicates that the auto-hinter is preferred over the font's native    *     hinter.  See also the note below.    *    *   FT_LOAD_CROP_BITMAP ::    *     Indicates that the font driver should crop the loaded bitmap glyph    *     (i.e., remove all space around its black bits).  Not all drivers    *     implement this.    *    *   FT_LOAD_PEDANTIC ::    *     Indicates that the font driver should perform pedantic verifications    *     during glyph loading.  This is mostly used to detect broken glyphs    *     in fonts.  By default, FreeType tries to handle broken fonts also.    *    *   FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH ::    *     Indicates that the font driver should ignore the global advance    *     width defined in the font.  By default, that value is used as the    *     advance width for all glyphs when the face has    *     @FT_FACE_FLAG_FIXED_WIDTH set.    *    *     This flag exists for historical reasons (to support buggy CJK    *     fonts).    *    *   FT_LOAD_NO_RECURSE ::    *     This flag is only used internally.  It merely indicates that the    *     font driver should not load composite glyphs recursively.  Instead,    *     it should set the `num_subglyph' and `subglyphs' values of the    *     glyph slot accordingly, and set `glyph->format' to    *     @FT_GLYPH_FORMAT_COMPOSITE.    *    *     The description of sub-glyphs is not available to client    *     applications for now.    *    *     This flag implies @FT_LOAD_NO_SCALE and @FT_LOAD_IGNORE_TRANSFORM.    *    *   FT_LOAD_IGNORE_TRANSFORM ::    *     Indicates that the transform matrix set by @FT_Set_Transform should    *     be ignored.    *    *   FT_LOAD_MONOCHROME ::    *     This flag is used with @FT_LOAD_RENDER to indicate that you want to    *     render an outline glyph to a 1-bit monochrome bitmap glyph, with    *     8~pixels packed into each byte of the bitmap data.    *    *     Note that this has no effect on the hinting algorithm used.  You    *     should rather use @FT_LOAD_TARGET_MONO so that the    *     monochrome-optimized hinting algorithm is used.    *    *   FT_LOAD_LINEAR_DESIGN ::    *     Indicates that the `linearHoriAdvance' and `linearVertAdvance'    *     fields of @FT_GlyphSlotRec should be kept in font units.  See    *     @FT_GlyphSlotRec for details.    *    *   FT_LOAD_NO_AUTOHINT ::    *     Disable auto-hinter.  See also the note below.    *    * @note:    *   By default, hinting is enabled and the font's native hinter (see    *   @FT_FACE_FLAG_HINTER) is preferred over the auto-hinter.  You can    *   disable hinting by setting @FT_LOAD_NO_HINTING or change the    *   precedence by setting @FT_LOAD_FORCE_AUTOHINT.  You can also set    *   @FT_LOAD_NO_AUTOHINT in case you don't want the auto-hinter to be    *   used at all.    *    *   See the description of @FT_FACE_FLAG_TRICKY for a special exception    *   (affecting only a handful of Asian fonts).    *    *   Besides deciding which hinter to use, you can also decide which    *   hinting algorithm to use.  See @FT_LOAD_TARGET_XXX for details.    *    */
end_comment
begin_define
DECL|macro|FT_LOAD_DEFAULT
define|#
directive|define
name|FT_LOAD_DEFAULT
value|0x0
end_define
begin_define
DECL|macro|FT_LOAD_NO_SCALE
define|#
directive|define
name|FT_LOAD_NO_SCALE
value|0x1
end_define
begin_define
DECL|macro|FT_LOAD_NO_HINTING
define|#
directive|define
name|FT_LOAD_NO_HINTING
value|0x2
end_define
begin_define
DECL|macro|FT_LOAD_RENDER
define|#
directive|define
name|FT_LOAD_RENDER
value|0x4
end_define
begin_define
DECL|macro|FT_LOAD_NO_BITMAP
define|#
directive|define
name|FT_LOAD_NO_BITMAP
value|0x8
end_define
begin_define
DECL|macro|FT_LOAD_VERTICAL_LAYOUT
define|#
directive|define
name|FT_LOAD_VERTICAL_LAYOUT
value|0x10
end_define
begin_define
DECL|macro|FT_LOAD_FORCE_AUTOHINT
define|#
directive|define
name|FT_LOAD_FORCE_AUTOHINT
value|0x20
end_define
begin_define
DECL|macro|FT_LOAD_CROP_BITMAP
define|#
directive|define
name|FT_LOAD_CROP_BITMAP
value|0x40
end_define
begin_define
DECL|macro|FT_LOAD_PEDANTIC
define|#
directive|define
name|FT_LOAD_PEDANTIC
value|0x80
end_define
begin_define
DECL|macro|FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH
define|#
directive|define
name|FT_LOAD_IGNORE_GLOBAL_ADVANCE_WIDTH
value|0x200
end_define
begin_define
DECL|macro|FT_LOAD_NO_RECURSE
define|#
directive|define
name|FT_LOAD_NO_RECURSE
value|0x400
end_define
begin_define
DECL|macro|FT_LOAD_IGNORE_TRANSFORM
define|#
directive|define
name|FT_LOAD_IGNORE_TRANSFORM
value|0x800
end_define
begin_define
DECL|macro|FT_LOAD_MONOCHROME
define|#
directive|define
name|FT_LOAD_MONOCHROME
value|0x1000
end_define
begin_define
DECL|macro|FT_LOAD_LINEAR_DESIGN
define|#
directive|define
name|FT_LOAD_LINEAR_DESIGN
value|0x2000
end_define
begin_define
DECL|macro|FT_LOAD_NO_AUTOHINT
define|#
directive|define
name|FT_LOAD_NO_AUTOHINT
value|0x8000U
end_define
begin_comment
comment|/* */
end_comment
begin_comment
comment|/* used internally only by certain font drivers! */
end_comment
begin_define
DECL|macro|FT_LOAD_ADVANCE_ONLY
define|#
directive|define
name|FT_LOAD_ADVANCE_ONLY
value|0x100
end_define
begin_define
DECL|macro|FT_LOAD_SBITS_ONLY
define|#
directive|define
name|FT_LOAD_SBITS_ONLY
value|0x4000
end_define
begin_comment
comment|/**************************************************************************    *    * @enum:    *   FT_LOAD_TARGET_XXX    *    * @description:    *   A list of values that are used to select a specific hinting algorithm    *   to use by the hinter.  You should OR one of these values to your    *   `load_flags' when calling @FT_Load_Glyph.    *    *   Note that font's native hinters may ignore the hinting algorithm you    *   have specified (e.g., the TrueType bytecode interpreter).  You can set    *   @FT_LOAD_FORCE_AUTOHINT to ensure that the auto-hinter is used.    *    *   Also note that @FT_LOAD_TARGET_LIGHT is an exception, in that it    *   always implies @FT_LOAD_FORCE_AUTOHINT.    *    * @values:    *   FT_LOAD_TARGET_NORMAL ::    *     This corresponds to the default hinting algorithm, optimized for    *     standard gray-level rendering.  For monochrome output, use    *     @FT_LOAD_TARGET_MONO instead.    *    *   FT_LOAD_TARGET_LIGHT ::    *     A lighter hinting algorithm for non-monochrome modes.  Many    *     generated glyphs are more fuzzy but better resemble its original    *     shape.  A bit like rendering on Mac OS~X.    *    *     As a special exception, this target implies @FT_LOAD_FORCE_AUTOHINT.    *    *   FT_LOAD_TARGET_MONO ::    *     Strong hinting algorithm that should only be used for monochrome    *     output.  The result is probably unpleasant if the glyph is rendered    *     in non-monochrome modes.    *    *   FT_LOAD_TARGET_LCD ::    *     A variant of @FT_LOAD_TARGET_NORMAL optimized for horizontally    *     decimated LCD displays.    *    *   FT_LOAD_TARGET_LCD_V ::    *     A variant of @FT_LOAD_TARGET_NORMAL optimized for vertically    *     decimated LCD displays.    *    * @note:    *   You should use only _one_ of the FT_LOAD_TARGET_XXX values in your    *   `load_flags'.  They can't be ORed.    *    *   If @FT_LOAD_RENDER is also set, the glyph is rendered in the    *   corresponding mode (i.e., the mode which matches the used algorithm    *   best) unless @FT_LOAD_MONOCHROME is set.    *    *   You can use a hinting algorithm that doesn't correspond to the same    *   rendering mode.  As an example, it is possible to use the `light'    *   hinting algorithm and have the results rendered in horizontal LCD    *   pixel mode, with code like    *    *     {    *       FT_Load_Glyph( face, glyph_index,    *                      load_flags | FT_LOAD_TARGET_LIGHT );    *    *       FT_Render_Glyph( face->glyph, FT_RENDER_MODE_LCD );    *     }    *    */
end_comment
begin_define
DECL|macro|FT_LOAD_TARGET_
define|#
directive|define
name|FT_LOAD_TARGET_
parameter_list|(
name|x
parameter_list|)
value|( (FT_Int32)( (x)& 15 )<< 16 )
end_define
begin_define
DECL|macro|FT_LOAD_TARGET_NORMAL
define|#
directive|define
name|FT_LOAD_TARGET_NORMAL
value|FT_LOAD_TARGET_( FT_RENDER_MODE_NORMAL )
end_define
begin_define
DECL|macro|FT_LOAD_TARGET_LIGHT
define|#
directive|define
name|FT_LOAD_TARGET_LIGHT
value|FT_LOAD_TARGET_( FT_RENDER_MODE_LIGHT  )
end_define
begin_define
DECL|macro|FT_LOAD_TARGET_MONO
define|#
directive|define
name|FT_LOAD_TARGET_MONO
value|FT_LOAD_TARGET_( FT_RENDER_MODE_MONO   )
end_define
begin_define
DECL|macro|FT_LOAD_TARGET_LCD
define|#
directive|define
name|FT_LOAD_TARGET_LCD
value|FT_LOAD_TARGET_( FT_RENDER_MODE_LCD    )
end_define
begin_define
DECL|macro|FT_LOAD_TARGET_LCD_V
define|#
directive|define
name|FT_LOAD_TARGET_LCD_V
value|FT_LOAD_TARGET_( FT_RENDER_MODE_LCD_V  )
end_define
begin_comment
comment|/**************************************************************************    *    * @macro:    *   FT_LOAD_TARGET_MODE    *    * @description:    *   Return the @FT_Render_Mode corresponding to a given    *   @FT_LOAD_TARGET_XXX value.    *    */
end_comment
begin_define
DECL|macro|FT_LOAD_TARGET_MODE
define|#
directive|define
name|FT_LOAD_TARGET_MODE
parameter_list|(
name|x
parameter_list|)
value|( (FT_Render_Mode)( ( (x)>> 16 )& 15 ) )
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
comment|/*    FT_Set_Transform                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to set the transformation that is applied to glyph */
end_comment
begin_comment
comment|/*    images when they are loaded into a glyph slot through              */
end_comment
begin_comment
comment|/*    @FT_Load_Glyph.                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the source face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    matrix :: A pointer to the transformation's 2x2 matrix.  Use~0 for */
end_comment
begin_comment
comment|/*              the identity matrix.                                     */
end_comment
begin_comment
comment|/*    delta  :: A pointer to the translation vector.  Use~0 for the null */
end_comment
begin_comment
comment|/*              vector.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The transformation is only applied to scalable image formats after */
end_comment
begin_comment
comment|/*    the glyph has been loaded.  It means that hinting is unaltered by  */
end_comment
begin_comment
comment|/*    the transformation and is performed on the character size given in */
end_comment
begin_comment
comment|/*    the last call to @FT_Set_Char_Size or @FT_Set_Pixel_Sizes.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that this also transforms the `face.glyph.advance' field, but */
end_comment
begin_comment
comment|/*    *not* the values in `face.glyph.metrics'.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Set_Transform
name|FT_Set_Transform
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_Matrix*  matrix
argument_list|,
argument|FT_Vector*  delta
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
comment|/*    FT_Render_Mode                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration type that lists the render modes supported by       */
end_comment
begin_comment
comment|/*    FreeType~2.  Each mode corresponds to a specific type of scanline  */
end_comment
begin_comment
comment|/*    conversion performed on the outline.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    For bitmap fonts and embedded bitmaps the `bitmap->pixel_mode'     */
end_comment
begin_comment
comment|/*    field in the @FT_GlyphSlotRec structure gives the format of the    */
end_comment
begin_comment
comment|/*    returned bitmap.                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    All modes except @FT_RENDER_MODE_MONO use 256 levels of opacity.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_RENDER_MODE_NORMAL ::                                           */
end_comment
begin_comment
comment|/*      This is the default render mode; it corresponds to 8-bit         */
end_comment
begin_comment
comment|/*      anti-aliased bitmaps.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_RENDER_MODE_LIGHT ::                                            */
end_comment
begin_comment
comment|/*      This is equivalent to @FT_RENDER_MODE_NORMAL.  It is only        */
end_comment
begin_comment
comment|/*      defined as a separate value because render modes are also used   */
end_comment
begin_comment
comment|/*      indirectly to define hinting algorithm selectors.  See           */
end_comment
begin_comment
comment|/*      @FT_LOAD_TARGET_XXX for details.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_RENDER_MODE_MONO ::                                             */
end_comment
begin_comment
comment|/*      This mode corresponds to 1-bit bitmaps (with 2~levels of         */
end_comment
begin_comment
comment|/*      opacity).                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_RENDER_MODE_LCD ::                                              */
end_comment
begin_comment
comment|/*      This mode corresponds to horizontal RGB and BGR sub-pixel        */
end_comment
begin_comment
comment|/*      displays like LCD screens.  It produces 8-bit bitmaps that are   */
end_comment
begin_comment
comment|/*      3~times the width of the original glyph outline in pixels, and   */
end_comment
begin_comment
comment|/*      which use the @FT_PIXEL_MODE_LCD mode.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_RENDER_MODE_LCD_V ::                                            */
end_comment
begin_comment
comment|/*      This mode corresponds to vertical RGB and BGR sub-pixel displays */
end_comment
begin_comment
comment|/*      (like PDA screens, rotated LCD displays, etc.).  It produces     */
end_comment
begin_comment
comment|/*      8-bit bitmaps that are 3~times the height of the original        */
end_comment
begin_comment
comment|/*      glyph outline in pixels and use the @FT_PIXEL_MODE_LCD_V mode.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The LCD-optimized glyph bitmaps produced by FT_Render_Glyph can be */
end_comment
begin_comment
comment|/*    filtered to reduce color-fringes by using @FT_Library_SetLcdFilter */
end_comment
begin_comment
comment|/*    (not active in the default builds).  It is up to the caller to     */
end_comment
begin_comment
comment|/*    either call @FT_Library_SetLcdFilter (if available) or do the      */
end_comment
begin_comment
comment|/*    filtering itself.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The selected render mode only affects vector glyphs of a font.     */
end_comment
begin_comment
comment|/*    Embedded bitmaps often have a different pixel mode like            */
end_comment
begin_comment
comment|/*    @FT_PIXEL_MODE_MONO.  You can use @FT_Bitmap_Convert to transform  */
end_comment
begin_comment
comment|/*    them into 8-bit pixmaps.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_Render_Mode_
typedef|typedef
enum|enum
name|FT_Render_Mode_
block|{
DECL|enumerator|FT_RENDER_MODE_NORMAL
name|FT_RENDER_MODE_NORMAL
init|=
literal|0
block|,
DECL|enumerator|FT_RENDER_MODE_LIGHT
name|FT_RENDER_MODE_LIGHT
block|,
DECL|enumerator|FT_RENDER_MODE_MONO
name|FT_RENDER_MODE_MONO
block|,
DECL|enumerator|FT_RENDER_MODE_LCD
name|FT_RENDER_MODE_LCD
block|,
DECL|enumerator|FT_RENDER_MODE_LCD_V
name|FT_RENDER_MODE_LCD_V
block|,
DECL|enumerator|FT_RENDER_MODE_MAX
name|FT_RENDER_MODE_MAX
block|}
DECL|typedef|FT_Render_Mode
name|FT_Render_Mode
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
comment|/*    ft_render_mode_xxx                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    These constants are deprecated.  Use the corresponding             */
end_comment
begin_comment
comment|/*    @FT_Render_Mode values instead.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    ft_render_mode_normal :: see @FT_RENDER_MODE_NORMAL                */
end_comment
begin_comment
comment|/*    ft_render_mode_mono   :: see @FT_RENDER_MODE_MONO                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|ft_render_mode_normal
define|#
directive|define
name|ft_render_mode_normal
value|FT_RENDER_MODE_NORMAL
end_define
begin_define
DECL|macro|ft_render_mode_mono
define|#
directive|define
name|ft_render_mode_mono
value|FT_RENDER_MODE_MONO
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
comment|/*    FT_Render_Glyph                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Convert a given glyph image to a bitmap.  It does so by inspecting */
end_comment
begin_comment
comment|/*    the glyph image format, finding the relevant renderer, and         */
end_comment
begin_comment
comment|/*    invoking it.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    slot        :: A handle to the glyph slot containing the image to  */
end_comment
begin_comment
comment|/*                   convert.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    render_mode :: This is the render mode used to render the glyph    */
end_comment
begin_comment
comment|/*                   image into a bitmap.  See @FT_Render_Mode for a     */
end_comment
begin_comment
comment|/*                   list of possible values.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Render_Glyph
argument_list|(
argument|FT_GlyphSlot    slot
argument_list|,
argument|FT_Render_Mode  render_mode
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
comment|/*    FT_Kerning_Mode                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    An enumeration used to specify which kerning values to return in   */
end_comment
begin_comment
comment|/*    @FT_Get_Kerning.                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_KERNING_DEFAULT  :: Return scaled and grid-fitted kerning       */
end_comment
begin_comment
comment|/*                           distances (value is~0).                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_KERNING_UNFITTED :: Return scaled but un-grid-fitted kerning    */
end_comment
begin_comment
comment|/*                           distances.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_KERNING_UNSCALED :: Return the kerning vector in original font  */
end_comment
begin_comment
comment|/*                           units.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_Kerning_Mode_
typedef|typedef
enum|enum
name|FT_Kerning_Mode_
block|{
DECL|enumerator|FT_KERNING_DEFAULT
name|FT_KERNING_DEFAULT
init|=
literal|0
block|,
DECL|enumerator|FT_KERNING_UNFITTED
name|FT_KERNING_UNFITTED
block|,
DECL|enumerator|FT_KERNING_UNSCALED
name|FT_KERNING_UNSCALED
block|}
DECL|typedef|FT_Kerning_Mode
name|FT_Kerning_Mode
typedef|;
end_typedef
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Const>                                                               */
end_comment
begin_comment
comment|/*    ft_kerning_default                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This constant is deprecated.  Please use @FT_KERNING_DEFAULT       */
end_comment
begin_comment
comment|/*    instead.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|ft_kerning_default
define|#
directive|define
name|ft_kerning_default
value|FT_KERNING_DEFAULT
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Const>                                                               */
end_comment
begin_comment
comment|/*    ft_kerning_unfitted                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This constant is deprecated.  Please use @FT_KERNING_UNFITTED      */
end_comment
begin_comment
comment|/*    instead.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|ft_kerning_unfitted
define|#
directive|define
name|ft_kerning_unfitted
value|FT_KERNING_UNFITTED
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Const>                                                               */
end_comment
begin_comment
comment|/*    ft_kerning_unscaled                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This constant is deprecated.  Please use @FT_KERNING_UNSCALED      */
end_comment
begin_comment
comment|/*    instead.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|ft_kerning_unscaled
define|#
directive|define
name|ft_kerning_unscaled
value|FT_KERNING_UNSCALED
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
comment|/*    FT_Get_Kerning                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the kerning vector between two glyphs of a same face.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face        :: A handle to a source face object.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    left_glyph  :: The index of the left glyph in the kern pair.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    right_glyph :: The index of the right glyph in the kern pair.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    kern_mode   :: See @FT_Kerning_Mode for more information.          */
end_comment
begin_comment
comment|/*                   Determines the scale and dimension of the returned  */
end_comment
begin_comment
comment|/*                   kerning vector.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    akerning    :: The kerning vector.  This is either in font units   */
end_comment
begin_comment
comment|/*                   or in pixels (26.6 format) for scalable formats,    */
end_comment
begin_comment
comment|/*                   and in pixels for fixed-sizes formats.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Only horizontal layouts (left-to-right& right-to-left) are        */
end_comment
begin_comment
comment|/*    supported by this method.  Other layouts, or more sophisticated    */
end_comment
begin_comment
comment|/*    kernings, are out of the scope of this API function -- they can be */
end_comment
begin_comment
comment|/*    implemented through format-specific interfaces.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_Kerning
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_UInt     left_glyph
argument_list|,
argument|FT_UInt     right_glyph
argument_list|,
argument|FT_UInt     kern_mode
argument_list|,
argument|FT_Vector  *akerning
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
comment|/*    FT_Get_Track_Kerning                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the track kerning for a given face object at a given size.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face       :: A handle to a source face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    point_size :: The point size in 16.16 fractional points.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    degree     :: The degree of tightness.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    akerning   :: The kerning in 16.16 fractional points.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_Track_Kerning
name|FT_Get_Track_Kerning
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_Fixed   point_size
argument_list|,
argument|FT_Int     degree
argument_list|,
argument|FT_Fixed*  akerning
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
comment|/*    FT_Get_Glyph_Name                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the ASCII name of a given glyph in a face.  This only     */
end_comment
begin_comment
comment|/*    works for those faces where @FT_HAS_GLYPH_NAMES(face) returns~1.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face        :: A handle to a source face object.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_index :: The glyph index.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    buffer_max  :: The maximal number of bytes available in the        */
end_comment
begin_comment
comment|/*                   buffer.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    buffer      :: A pointer to a target buffer where the name is      */
end_comment
begin_comment
comment|/*                   copied to.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    An error is returned if the face doesn't provide glyph names or if */
end_comment
begin_comment
comment|/*    the glyph index is invalid.  In all cases of failure, the first    */
end_comment
begin_comment
comment|/*    byte of `buffer' is set to~0 to indicate an empty name.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The glyph name is truncated to fit within the buffer if it is too  */
end_comment
begin_comment
comment|/*    long.  The returned string is always zero-terminated.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function is not compiled within the library if the config     */
end_comment
begin_comment
comment|/*    macro `FT_CONFIG_OPTION_NO_GLYPH_NAMES' is defined in              */
end_comment
begin_comment
comment|/*    `include/freetype/config/ftoptions.h'.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Get_Glyph_Name
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_UInt     glyph_index
argument_list|,
argument|FT_Pointer  buffer
argument_list|,
argument|FT_UInt     buffer_max
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
comment|/*    FT_Get_Postscript_Name                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the ASCII PostScript name of a given face, if available.  */
end_comment
begin_comment
comment|/*    This only works with PostScript and TrueType fonts.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the source face object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A pointer to the face's PostScript name.  NULL if unavailable.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The returned pointer is owned by the face and is destroyed with    */
end_comment
begin_comment
comment|/*    it.                                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|const char*
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_Postscript_Name
name|FT_Get_Postscript_Name
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Get_Postscript_Name
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
comment|/*    FT_Select_Charmap                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Select a given charmap by its encoding tag (as listed in           */
end_comment
begin_comment
comment|/*    `freetype.h').                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face     :: A handle to the source face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    encoding :: A handle to the selected encoding.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function returns an error if no charmap in the face           */
end_comment
begin_comment
comment|/*    corresponds to the encoding queried here.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Because many fonts contain more than a single cmap for Unicode     */
end_comment
begin_comment
comment|/*    encoding, this function has some special code to select the one    */
end_comment
begin_comment
comment|/*    which covers Unicode best (`best' in the sense that a UCS-4 cmap   */
end_comment
begin_comment
comment|/*    is preferred to a UCS-2 cmap).  It is thus preferable to           */
end_comment
begin_comment
comment|/*    @FT_Set_Charmap in this case.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Select_Charmap
argument_list|(
argument|FT_Face      face
argument_list|,
argument|FT_Encoding  encoding
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
comment|/*    FT_Set_Charmap                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Select a given charmap for character code to glyph index mapping.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face    :: A handle to the source face object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    charmap :: A handle to the selected charmap.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0~means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function returns an error if the charmap is not part of       */
end_comment
begin_comment
comment|/*    the face (i.e., if it is not listed in the `face->charmaps'        */
end_comment
begin_comment
comment|/*    table).                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    It also fails if a type~14 charmap is selected.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Set_Charmap
name|FT_Set_Charmap
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_CharMap  charmap
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @function:    *   FT_Get_Charmap_Index    *    * @description:    *   Retrieve index of a given charmap.    *    * @input:    *   charmap ::    *     A handle to a charmap.    *    * @return:    *   The index into the array of character maps within the face to which    *   `charmap' belongs.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|FT_Get_Charmap_Index
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
comment|/*    FT_Get_Char_Index                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the glyph index of a given character code.  This function   */
end_comment
begin_comment
comment|/*    uses a charmap object to do the mapping.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face     :: A handle to the source face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    charcode :: The character code.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The glyph index.  0~means `undefined character code'.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If you use FreeType to manipulate the contents of font files       */
end_comment
begin_comment
comment|/*    directly, be aware that the glyph index returned by this function  */
end_comment
begin_comment
comment|/*    doesn't always correspond to the internal indices used within      */
end_comment
begin_comment
comment|/*    the file.  This is done to ensure that value~0 always corresponds  */
end_comment
begin_comment
comment|/*    to the `missing glyph'.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_Char_Index
name|FT_Get_Char_Index
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  charcode
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
comment|/*    FT_Get_First_Char                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used to return the first character code in the    */
end_comment
begin_comment
comment|/*    current charmap of a given face.  It also returns the              */
end_comment
begin_comment
comment|/*    corresponding glyph index.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face    :: A handle to the source face object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    agindex :: Glyph index of first character code.  0~if charmap is   */
end_comment
begin_comment
comment|/*               empty.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The charmap's first character code.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You should use this function with @FT_Get_Next_Char to be able to  */
end_comment
begin_comment
comment|/*    parse all character codes available in a given charmap.  The code  */
end_comment
begin_comment
comment|/*    should look like this:                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      FT_ULong  charcode;                                              */
end_comment
begin_comment
comment|/*      FT_UInt   gindex;                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      charcode = FT_Get_First_Char( face,&gindex );                   */
end_comment
begin_comment
comment|/*      while ( gindex != 0 )                                            */
end_comment
begin_comment
comment|/*      {                                                                */
end_comment
begin_comment
comment|/*        ... do something with (charcode,gindex) pair ...               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        charcode = FT_Get_Next_Char( face, charcode,&gindex );        */
end_comment
begin_comment
comment|/*      }                                                                */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that `*agindex' is set to~0 if the charmap is empty.  The     */
end_comment
begin_comment
comment|/*    result itself can be~0 in two cases: if the charmap is empty or    */
end_comment
begin_comment
comment|/*    if the value~0 is the first valid character code.                  */
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
name|FT_Get_First_Char
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt  *agindex
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
comment|/*    FT_Get_Next_Char                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used to return the next character code in the     */
end_comment
begin_comment
comment|/*    current charmap of a given face following the value `char_code',   */
end_comment
begin_comment
comment|/*    as well as the corresponding glyph index.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face      :: A handle to the source face object.                   */
end_comment
begin_comment
comment|/*    char_code :: The starting character code.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    agindex   :: Glyph index of next character code.  0~if charmap     */
end_comment
begin_comment
comment|/*                 is empty.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The charmap's next character code.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You should use this function with @FT_Get_First_Char to walk       */
end_comment
begin_comment
comment|/*    over all character codes available in a given charmap.  See the    */
end_comment
begin_comment
comment|/*    note for this function for a simple code example.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that `*agindex' is set to~0 when there are no more codes in   */
end_comment
begin_comment
comment|/*    the charmap.                                                       */
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
DECL|variable|FT_Get_Next_Char
name|FT_Get_Next_Char
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_ULong   char_code
argument_list|,
argument|FT_UInt   *agindex
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
comment|/*    FT_Get_Name_Index                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the glyph index of a given glyph name.  This function uses  */
end_comment
begin_comment
comment|/*    driver specific objects to do the translation.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face       :: A handle to the source face object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_name :: The glyph name.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The glyph index.  0~means `undefined character code'.              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
name|FT_Get_Name_Index
argument_list|(
argument|FT_Face     face
argument_list|,
argument|FT_String*  glyph_name
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************    *    * @macro:    *   FT_SUBGLYPH_FLAG_XXX    *    * @description:    *   A list of constants used to describe subglyphs.  Please refer to the    *   TrueType specification for the meaning of the various flags.    *    * @values:    *   FT_SUBGLYPH_FLAG_ARGS_ARE_WORDS ::    *   FT_SUBGLYPH_FLAG_ARGS_ARE_XY_VALUES ::    *   FT_SUBGLYPH_FLAG_ROUND_XY_TO_GRID ::    *   FT_SUBGLYPH_FLAG_SCALE ::    *   FT_SUBGLYPH_FLAG_XY_SCALE ::    *   FT_SUBGLYPH_FLAG_2X2 ::    *   FT_SUBGLYPH_FLAG_USE_MY_METRICS ::    *    */
end_comment
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_ARGS_ARE_WORDS
define|#
directive|define
name|FT_SUBGLYPH_FLAG_ARGS_ARE_WORDS
value|1
end_define
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_ARGS_ARE_XY_VALUES
define|#
directive|define
name|FT_SUBGLYPH_FLAG_ARGS_ARE_XY_VALUES
value|2
end_define
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_ROUND_XY_TO_GRID
define|#
directive|define
name|FT_SUBGLYPH_FLAG_ROUND_XY_TO_GRID
value|4
end_define
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_SCALE
define|#
directive|define
name|FT_SUBGLYPH_FLAG_SCALE
value|8
end_define
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_XY_SCALE
define|#
directive|define
name|FT_SUBGLYPH_FLAG_XY_SCALE
value|0x40
end_define
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_2X2
define|#
directive|define
name|FT_SUBGLYPH_FLAG_2X2
value|0x80
end_define
begin_define
DECL|macro|FT_SUBGLYPH_FLAG_USE_MY_METRICS
define|#
directive|define
name|FT_SUBGLYPH_FLAG_USE_MY_METRICS
value|0x200
end_define
begin_comment
comment|/*************************************************************************    *    * @func:    *   FT_Get_SubGlyph_Info    *    * @description:    *   Retrieve a description of a given subglyph.  Only use it if    *   `glyph->format' is @FT_GLYPH_FORMAT_COMPOSITE; an error is    *   returned otherwise.    *    * @input:    *   glyph ::    *     The source glyph slot.    *    *   sub_index ::    *     The index of the subglyph.  Must be less than    *     `glyph->num_subglyphs'.    *    * @output:    *   p_index ::    *     The glyph index of the subglyph.    *    *   p_flags ::    *     The subglyph flags, see @FT_SUBGLYPH_FLAG_XXX.    *    *   p_arg1 ::    *     The subglyph's first argument (if any).    *    *   p_arg2 ::    *     The subglyph's second argument (if any).    *    *   p_transform ::    *     The subglyph transformation (if any).    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   The values of `*p_arg1', `*p_arg2', and `*p_transform' must be    *   interpreted depending on the flags returned in `*p_flags'.  See the    *   TrueType specification for details.    *    */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Get_SubGlyph_Info
name|FT_Get_SubGlyph_Info
argument_list|(
argument|FT_GlyphSlot  glyph
argument_list|,
argument|FT_UInt       sub_index
argument_list|,
argument|FT_Int       *p_index
argument_list|,
argument|FT_UInt      *p_flags
argument_list|,
argument|FT_Int       *p_arg1
argument_list|,
argument|FT_Int       *p_arg2
argument_list|,
argument|FT_Matrix    *p_transform
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
comment|/*    FT_FSTYPE_XXX                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A list of bit flags used in the `fsType' field of the OS/2 table   */
end_comment
begin_comment
comment|/*    in a TrueType or OpenType font and the `FSType' entry in a         */
end_comment
begin_comment
comment|/*    PostScript font.  These bit flags are returned by                  */
end_comment
begin_comment
comment|/*    @FT_Get_FSType_Flags; they inform client applications of embedding */
end_comment
begin_comment
comment|/*    and subsetting restrictions associated with a font.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    See http://www.adobe.com/devnet/acrobat/pdfs/FontPolicies.pdf for  */
end_comment
begin_comment
comment|/*    more details.                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_FSTYPE_INSTALLABLE_EMBEDDING ::                                 */
end_comment
begin_comment
comment|/*      Fonts with no fsType bit set may be embedded and permanently     */
end_comment
begin_comment
comment|/*      installed on the remote system by an application.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_RESTRICTED_LICENSE_EMBEDDING ::                          */
end_comment
begin_comment
comment|/*      Fonts that have only this bit set must not be modified, embedded */
end_comment
begin_comment
comment|/*      or exchanged in any manner without first obtaining permission of */
end_comment
begin_comment
comment|/*      the font software copyright owner.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_PREVIEW_AND_PRINT_EMBEDDING ::                           */
end_comment
begin_comment
comment|/*      If this bit is set, the font may be embedded and temporarily     */
end_comment
begin_comment
comment|/*      loaded on the remote system.  Documents containing Preview&     */
end_comment
begin_comment
comment|/*      Print fonts must be opened `read-only'; no edits can be applied  */
end_comment
begin_comment
comment|/*      to the document.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_EDITABLE_EMBEDDING ::                                    */
end_comment
begin_comment
comment|/*      If this bit is set, the font may be embedded but must only be    */
end_comment
begin_comment
comment|/*      installed temporarily on other systems.  In contrast to Preview  */
end_comment
begin_comment
comment|/*& Print fonts, documents containing editable fonts may be opened */
end_comment
begin_comment
comment|/*      for reading, editing is permitted, and changes may be saved.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_NO_SUBSETTING ::                                         */
end_comment
begin_comment
comment|/*      If this bit is set, the font may not be subsetted prior to       */
end_comment
begin_comment
comment|/*      embedding.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_FSTYPE_BITMAP_EMBEDDING_ONLY ::                                 */
end_comment
begin_comment
comment|/*      If this bit is set, only bitmaps contained in the font may be    */
end_comment
begin_comment
comment|/*      embedded; no outline data may be embedded.  If there are no      */
end_comment
begin_comment
comment|/*      bitmaps available in the font, then the font is unembeddable.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    While the fsType flags can indicate that a font may be embedded, a */
end_comment
begin_comment
comment|/*    license with the font vendor may be separately required to use the */
end_comment
begin_comment
comment|/*    font in this way.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_FSTYPE_INSTALLABLE_EMBEDDING
define|#
directive|define
name|FT_FSTYPE_INSTALLABLE_EMBEDDING
value|0x0000
end_define
begin_define
DECL|macro|FT_FSTYPE_RESTRICTED_LICENSE_EMBEDDING
define|#
directive|define
name|FT_FSTYPE_RESTRICTED_LICENSE_EMBEDDING
value|0x0002
end_define
begin_define
DECL|macro|FT_FSTYPE_PREVIEW_AND_PRINT_EMBEDDING
define|#
directive|define
name|FT_FSTYPE_PREVIEW_AND_PRINT_EMBEDDING
value|0x0004
end_define
begin_define
DECL|macro|FT_FSTYPE_EDITABLE_EMBEDDING
define|#
directive|define
name|FT_FSTYPE_EDITABLE_EMBEDDING
value|0x0008
end_define
begin_define
DECL|macro|FT_FSTYPE_NO_SUBSETTING
define|#
directive|define
name|FT_FSTYPE_NO_SUBSETTING
value|0x0100
end_define
begin_define
DECL|macro|FT_FSTYPE_BITMAP_EMBEDDING_ONLY
define|#
directive|define
name|FT_FSTYPE_BITMAP_EMBEDDING_ONLY
value|0x0200
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
comment|/*    FT_Get_FSType_Flags                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the fsType flags for a font.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the source face object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The fsType flags, @FT_FSTYPE_XXX.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Use this function rather than directly reading the `fs_type' field */
end_comment
begin_comment
comment|/*    in the @PS_FontInfoRec structure which is only guaranteed to       */
end_comment
begin_comment
comment|/*    return the correct results for Type~1 fonts.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UShort
argument_list|)
end_macro
begin_macro
name|FT_Get_FSType_Flags
argument_list|(
argument|FT_Face  face
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    glyph_variants                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Glyph Variants                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    The FreeType~2 interface to Unicode Ideographic Variation          */
end_comment
begin_comment
comment|/*    Sequences (IVS), using the SFNT cmap format~14.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Many CJK characters have variant forms.  They are a sort of grey   */
end_comment
begin_comment
comment|/*    area somewhere between being totally irrelevant and semantically   */
end_comment
begin_comment
comment|/*    distinct; for this reason, the Unicode consortium decided to       */
end_comment
begin_comment
comment|/*    introduce Ideographic Variation Sequences (IVS), consisting of a   */
end_comment
begin_comment
comment|/*    Unicode base character and one of 240 variant selectors            */
end_comment
begin_comment
comment|/*    (U+E0100-U+E01EF), instead of further extending the already huge   */
end_comment
begin_comment
comment|/*    code range for CJK characters.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    An IVS is registered and unique; for further details please refer  */
end_comment
begin_comment
comment|/*    to Unicode Technical Report #37, the Ideographic Variation         */
end_comment
begin_comment
comment|/*    Database.  To date (October 2007), the character with the most     */
end_comment
begin_comment
comment|/*    variants is U+908A, having 8~such IVS.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Adobe and MS decided to support IVS with a new cmap subtable       */
end_comment
begin_comment
comment|/*    (format~14).  It is an odd subtable because it is not a mapping of */
end_comment
begin_comment
comment|/*    input code points to glyphs, but contains lists of all variants    */
end_comment
begin_comment
comment|/*    supported by the font.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    A variant may be either `default' or `non-default'.  A default     */
end_comment
begin_comment
comment|/*    variant is the one you will get for that code point if you look it */
end_comment
begin_comment
comment|/*    up in the standard Unicode cmap.  A non-default variant is a       */
end_comment
begin_comment
comment|/*    different glyph.                                                   */
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Face_GetCharVariantIndex                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the glyph index of a given character code as modified by    */
end_comment
begin_comment
comment|/*    the variation selector.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face ::                                                            */
end_comment
begin_comment
comment|/*      A handle to the source face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    charcode ::                                                        */
end_comment
begin_comment
comment|/*      The character code point in Unicode.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    variantSelector ::                                                 */
end_comment
begin_comment
comment|/*      The Unicode code point of the variation selector.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The glyph index.  0~means either `undefined character code', or    */
end_comment
begin_comment
comment|/*    `undefined selector code', or `no variation selector cmap          */
end_comment
begin_comment
comment|/*    subtable', or `current CharMap is not Unicode'.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    If you use FreeType to manipulate the contents of font files       */
end_comment
begin_comment
comment|/*    directly, be aware that the glyph index returned by this function  */
end_comment
begin_comment
comment|/*    doesn't always correspond to the internal indices used within      */
end_comment
begin_comment
comment|/*    the file.  This is done to ensure that value~0 always corresponds  */
end_comment
begin_comment
comment|/*    to the `missing glyph'.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function is only meaningful if                                */
end_comment
begin_comment
comment|/*      a) the font has a variation selector cmap sub table,             */
end_comment
begin_comment
comment|/*    and                                                                */
end_comment
begin_comment
comment|/*      b) the current charmap has a Unicode encoding.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.6                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Face_GetCharVariantIndex
name|FT_Face_GetCharVariantIndex
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  charcode
argument_list|,
argument|FT_ULong  variantSelector
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
comment|/*    FT_Face_GetCharVariantIsDefault                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Check whether this variant of this Unicode character is the one to */
end_comment
begin_comment
comment|/*    be found in the `cmap'.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face ::                                                            */
end_comment
begin_comment
comment|/*      A handle to the source face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    charcode ::                                                        */
end_comment
begin_comment
comment|/*      The character codepoint in Unicode.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    variantSelector ::                                                 */
end_comment
begin_comment
comment|/*      The Unicode codepoint of the variation selector.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    1~if found in the standard (Unicode) cmap, 0~if found in the       */
end_comment
begin_comment
comment|/*    variation selector cmap, or -1 if it is not a variant.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function is only meaningful if the font has a variation       */
end_comment
begin_comment
comment|/*    selector cmap subtable.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.6                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|FT_Face_GetCharVariantIsDefault
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  charcode
argument_list|,
argument|FT_ULong  variantSelector
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
comment|/*    FT_Face_GetVariantSelectors                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return a zero-terminated list of Unicode variant selectors found   */
end_comment
begin_comment
comment|/*    in the font.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face ::                                                            */
end_comment
begin_comment
comment|/*      A handle to the source face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A pointer to an array of selector code points, or NULL if there is */
end_comment
begin_comment
comment|/*    no valid variant selector cmap subtable.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The last item in the array is~0; the array is owned by the         */
end_comment
begin_comment
comment|/*    @FT_Face object but can be overwritten or released on the next     */
end_comment
begin_comment
comment|/*    call to a FreeType function.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.6                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt32*
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Face_GetVariantSelectors
name|FT_Face_GetVariantSelectors
argument_list|(
argument|FT_Face  face
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Face_GetVariantSelectors
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
comment|/*    FT_Face_GetVariantsOfChar                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return a zero-terminated list of Unicode variant selectors found   */
end_comment
begin_comment
comment|/*    for the specified character code.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face ::                                                            */
end_comment
begin_comment
comment|/*      A handle to the source face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    charcode ::                                                        */
end_comment
begin_comment
comment|/*      The character codepoint in Unicode.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A pointer to an array of variant selector code points which are    */
end_comment
begin_comment
comment|/*    active for the given character, or NULL if the corresponding list  */
end_comment
begin_comment
comment|/*    is empty.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The last item in the array is~0; the array is owned by the         */
end_comment
begin_comment
comment|/*    @FT_Face object but can be overwritten or released on the next     */
end_comment
begin_comment
comment|/*    call to a FreeType function.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.6                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt32*
argument_list|)
end_macro
begin_macro
name|FT_Face_GetVariantsOfChar
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  charcode
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
comment|/*    FT_Face_GetCharsOfVariant                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return a zero-terminated list of Unicode character codes found for */
end_comment
begin_comment
comment|/*    the specified variant selector.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face ::                                                            */
end_comment
begin_comment
comment|/*      A handle to the source face object.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    variantSelector ::                                                 */
end_comment
begin_comment
comment|/*      The variant selector code point in Unicode.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A list of all the code points which are specified by this selector */
end_comment
begin_comment
comment|/*    (both default and non-default codes are returned) or NULL if there */
end_comment
begin_comment
comment|/*    is no valid cmap or the variant selector is invalid.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The last item in the array is~0; the array is owned by the         */
end_comment
begin_comment
comment|/*    @FT_Face object but can be overwritten or released on the next     */
end_comment
begin_comment
comment|/*    call to a FreeType function.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.6                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_UInt32*
argument_list|)
end_macro
begin_macro
name|FT_Face_GetCharsOfVariant
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  variantSelector
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
comment|/*<Section>                                                             */
end_comment
begin_comment
comment|/*    computations                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Computations                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Crunching fixed numbers and vectors.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains various functions used to perform            */
end_comment
begin_comment
comment|/*    computations on 16.16 fixed-float numbers or 2d vectors.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Order>                                                               */
end_comment
begin_comment
comment|/*    FT_MulDiv                                                          */
end_comment
begin_comment
comment|/*    FT_MulFix                                                          */
end_comment
begin_comment
comment|/*    FT_DivFix                                                          */
end_comment
begin_comment
comment|/*    FT_RoundFix                                                        */
end_comment
begin_comment
comment|/*    FT_CeilFix                                                         */
end_comment
begin_comment
comment|/*    FT_FloorFix                                                        */
end_comment
begin_comment
comment|/*    FT_Vector_Transform                                                */
end_comment
begin_comment
comment|/*    FT_Matrix_Multiply                                                 */
end_comment
begin_comment
comment|/*    FT_Matrix_Invert                                                   */
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_MulDiv                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to perform the computation `(a*b)/c'   */
end_comment
begin_comment
comment|/*    with maximal accuracy (it uses a 64-bit intermediate integer       */
end_comment
begin_comment
comment|/*    whenever necessary).                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function isn't necessarily as fast as some processor specific */
end_comment
begin_comment
comment|/*    operations, but is at least completely portable.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The first multiplier.                                         */
end_comment
begin_comment
comment|/*    b :: The second multiplier.                                        */
end_comment
begin_comment
comment|/*    c :: The divisor.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `(a*b)/c'.  This function never traps when trying to */
end_comment
begin_comment
comment|/*    divide by zero; it simply returns `MaxInt' or `MinInt' depending   */
end_comment
begin_comment
comment|/*    on the signs of `a' and `b'.                                       */
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
name|FT_MulDiv
argument_list|(
argument|FT_Long  a
argument_list|,
argument|FT_Long  b
argument_list|,
argument|FT_Long  c
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_comment
comment|/* The following #if 0 ... #endif is for the documentation formatter, */
end_comment
begin_comment
comment|/* hiding the internal `FT_MULFIX_INLINED' macro.                     */
end_comment
begin_if
if|#
directive|if
literal|0
end_if
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
comment|/*    FT_MulFix                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to perform the computation             */
end_comment
begin_comment
comment|/*    `(a*b)/0x10000' with maximal accuracy.  Most of the time this is   */
end_comment
begin_comment
comment|/*    used to multiply a given value by a 16.16 fixed float factor.      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The first multiplier.                                         */
end_comment
begin_comment
comment|/*    b :: The second multiplier.  Use a 16.16 factor here whenever      */
end_comment
begin_comment
comment|/*         possible (see note below).                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `(a*b)/0x10000'.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function has been optimized for the case where the absolute   */
end_comment
begin_comment
comment|/*    value of `a' is less than 2048, and `b' is a 16.16 scaling factor. */
end_comment
begin_comment
comment|/*    As this happens mainly when scaling from notional units to         */
end_comment
begin_comment
comment|/*    fractional pixels in FreeType, it resulted in noticeable speed     */
end_comment
begin_comment
comment|/*    improvements between versions 2.x and 1.x.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    As a conclusion, always try to place a 16.16 factor as the         */
end_comment
begin_comment
comment|/*    _second_ argument of this function; this can make a great          */
end_comment
begin_comment
comment|/*    difference.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
unit|FT_EXPORT( FT_Long )   FT_MulFix( FT_Long  a,              FT_Long  b );
comment|/* */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|FT_MULFIX_INLINED
end_ifdef
begin_define
DECL|macro|FT_MulFix
define|#
directive|define
name|FT_MulFix
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|FT_MULFIX_INLINED( a, b )
end_define
begin_else
else|#
directive|else
end_else
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Long
argument_list|)
end_macro
begin_macro
name|FT_MulFix
argument_list|(
argument|FT_Long  a
argument_list|,
argument|FT_Long  b
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
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
comment|/*    FT_DivFix                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to perform the computation             */
end_comment
begin_comment
comment|/*    `(a*0x10000)/b' with maximal accuracy.  Most of the time, this is  */
end_comment
begin_comment
comment|/*    used to divide a given value by a 16.16 fixed float factor.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The first multiplier.                                         */
end_comment
begin_comment
comment|/*    b :: The second multiplier.  Use a 16.16 factor here whenever      */
end_comment
begin_comment
comment|/*         possible (see note below).                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `(a*0x10000)/b'.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The optimization for FT_DivFix() is simple: If (a~<<~16) fits in   */
end_comment
begin_comment
comment|/*    32~bits, then the division is computed directly.  Otherwise, we    */
end_comment
begin_comment
comment|/*    use a specialized version of @FT_MulDiv.                           */
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
DECL|variable|FT_DivFix
name|FT_DivFix
argument_list|(
argument|FT_Long  a
argument_list|,
argument|FT_Long  b
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
comment|/*    FT_RoundFix                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to round a 16.16 fixed number.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The number to be rounded.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `(a + 0x8000)& -0x10000'.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
name|FT_RoundFix
argument_list|(
argument|FT_Fixed  a
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
comment|/*    FT_CeilFix                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to compute the ceiling function of a   */
end_comment
begin_comment
comment|/*    16.16 fixed number.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The number for which the ceiling function is to be computed.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `(a + 0x10000 - 1)& -0x10000'.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
DECL|variable|FT_CeilFix
name|FT_CeilFix
argument_list|(
argument|FT_Fixed  a
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_CeilFix
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
comment|/*    FT_FloorFix                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A very simple function used to compute the floor function of a     */
end_comment
begin_comment
comment|/*    16.16 fixed number.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: The number for which the floor function is to be computed.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The result of `a& -0x10000'.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Fixed
argument_list|)
end_macro
begin_macro
name|FT_FloorFix
argument_list|(
argument|FT_Fixed  a
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
comment|/*    FT_Vector_Transform                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Transform a single vector through a 2x2 matrix.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    vector :: The target vector to transform.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    matrix :: A pointer to the source 2x2 matrix.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The result is undefined if either `vector' or `matrix' is invalid. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
DECL|variable|FT_Vector_Transform
name|FT_Vector_Transform
argument_list|(
name|FT_Vector
operator|*
name|vec
argument_list|,
specifier|const
name|FT_Matrix
operator|*
name|matrix
argument_list|)
expr_stmt|;
end_expr_stmt
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
comment|/*    version                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    FreeType Version                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Functions and macros related to FreeType versions.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Note that those functions and macros are of limited use because    */
end_comment
begin_comment
comment|/*    even a new release of FreeType with only documentation changes     */
end_comment
begin_comment
comment|/*    increases the version number.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************    *    * @enum:    *   FREETYPE_XXX    *    * @description:    *   These three macros identify the FreeType source code version.    *   Use @FT_Library_Version to access them at runtime.    *    * @values:    *   FREETYPE_MAJOR :: The major version number.    *   FREETYPE_MINOR :: The minor version number.    *   FREETYPE_PATCH :: The patch level.    *    * @note:    *   The version number of FreeType if built as a dynamic link library    *   with the `libtool' package is _not_ controlled by these three    *   macros.    *    */
end_comment
begin_define
DECL|macro|FREETYPE_MAJOR
define|#
directive|define
name|FREETYPE_MAJOR
value|2
end_define
begin_define
DECL|macro|FREETYPE_MINOR
define|#
directive|define
name|FREETYPE_MINOR
value|3
end_define
begin_define
DECL|macro|FREETYPE_PATCH
define|#
directive|define
name|FREETYPE_PATCH
value|12
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
comment|/*    FT_Library_Version                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the version of the FreeType library being used.  This is    */
end_comment
begin_comment
comment|/*    useful when dynamically linking to the library, since one cannot   */
end_comment
begin_comment
comment|/*    use the macros @FREETYPE_MAJOR, @FREETYPE_MINOR, and               */
end_comment
begin_comment
comment|/*    @FREETYPE_PATCH.                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A source library handle.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    amajor  :: The major version number.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    aminor  :: The minor version number.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    apatch  :: The patch version number.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The reason why this function takes a `library' argument is because */
end_comment
begin_comment
comment|/*    certain programs implement library initialization in a custom way  */
end_comment
begin_comment
comment|/*    that doesn't use @FT_Init_FreeType.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    In such cases, the library version might not be available before   */
end_comment
begin_comment
comment|/*    the library object has been created.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Library_Version
argument_list|(
argument|FT_Library   library
argument_list|,
argument|FT_Int      *amajor
argument_list|,
argument|FT_Int      *aminor
argument_list|,
argument|FT_Int      *apatch
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
comment|/*    FT_Face_CheckTrueTypePatents                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Parse all bytecode instructions of a TrueType font file to check   */
end_comment
begin_comment
comment|/*    whether any of the patented opcodes are used.  This is only useful */
end_comment
begin_comment
comment|/*    if you want to be able to use the unpatented hinter with           */
end_comment
begin_comment
comment|/*    fonts that do *not* use these opcodes.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that this function parses *all* glyph instructions in the     */
end_comment
begin_comment
comment|/*    font file, which may be slow.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A face handle.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    1~if this is a TrueType font that uses one of the patented         */
end_comment
begin_comment
comment|/*    opcodes, 0~otherwise.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.5                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
name|FT_Face_CheckTrueTypePatents
argument_list|(
argument|FT_Face  face
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
comment|/*    FT_Face_SetUnpatentedHinting                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Enable or disable the unpatented hinter for a given face.          */
end_comment
begin_comment
comment|/*    Only enable it if you have determined that the face doesn't        */
end_comment
begin_comment
comment|/*    use any patented opcodes (see @FT_Face_CheckTrueTypePatents).      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face  :: A face handle.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    value :: New boolean setting.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The old setting value.  This will always be false if this is not   */
end_comment
begin_comment
comment|/*    an SFNT font, or if the unpatented hinter is not compiled in this  */
end_comment
begin_comment
comment|/*    instance of the library.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Since>                                                               */
end_comment
begin_comment
comment|/*    2.3.5                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Bool
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Face_SetUnpatentedHinting
name|FT_Face_SetUnpatentedHinting
argument_list|(
argument|FT_Face  face
argument_list|,
argument|FT_Bool  value
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
comment|/* __FREETYPE_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
