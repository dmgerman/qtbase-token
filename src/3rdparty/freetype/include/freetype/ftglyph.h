begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftglyph.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType convenience functions to handle glyphs (specification).     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2006, 2008, 2009 by                   */
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
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This file contains the definition of several convenience functions    */
end_comment
begin_comment
comment|/* that can be used by client applications to easily retrieve glyph      */
end_comment
begin_comment
comment|/* bitmaps and outlines from a given face.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* These functions should be optional if you are writing a font server   */
end_comment
begin_comment
comment|/* or text layout engine on top of FreeType.  However, they are pretty   */
end_comment
begin_comment
comment|/* handy for many other simple uses of the library.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTGLYPH_H__
end_ifndef
begin_define
DECL|macro|__FTGLYPH_H__
define|#
directive|define
name|__FTGLYPH_H__
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
comment|/*    glyph_management                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Glyph Management                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    Generic interface to manage individual glyph data.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This section contains definitions used to manage glyph data        */
end_comment
begin_comment
comment|/*    through generic FT_Glyph objects.  Each of them can contain a      */
end_comment
begin_comment
comment|/*    bitmap, a vector outline, or even images in other formats.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* forward declaration to a private type */
end_comment
begin_typedef
DECL|typedef|FT_Glyph_Class
typedef|typedef
name|struct
name|FT_Glyph_Class_
name|FT_Glyph_Class
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
comment|/*    FT_Glyph                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Handle to an object used to model generic glyph images.  It is a   */
end_comment
begin_comment
comment|/*    pointer to the @FT_GlyphRec structure and can contain a glyph      */
end_comment
begin_comment
comment|/*    bitmap or pointer.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Glyph objects are not owned by the library.  You must thus release */
end_comment
begin_comment
comment|/*    them manually (through @FT_Done_Glyph) _before_ calling            */
end_comment
begin_comment
comment|/*    @FT_Done_FreeType.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_Glyph
typedef|typedef
name|struct
name|FT_GlyphRec_
modifier|*
name|FT_Glyph
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
comment|/*    FT_GlyphRec                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The root glyph structure contains a given glyph image plus its     */
end_comment
begin_comment
comment|/*    advance width in 16.16 fixed float format.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    library :: A handle to the FreeType library object.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    clazz   :: A pointer to the glyph's class.  Private.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format  :: The format of the glyph's image.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    advance :: A 16.16 vector that gives the glyph's advance width.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_GlyphRec_
typedef|typedef
struct|struct
name|FT_GlyphRec_
block|{
DECL|member|library
name|FT_Library
name|library
decl_stmt|;
DECL|member|clazz
specifier|const
name|FT_Glyph_Class
modifier|*
name|clazz
decl_stmt|;
DECL|member|format
name|FT_Glyph_Format
name|format
decl_stmt|;
DECL|member|advance
name|FT_Vector
name|advance
decl_stmt|;
block|}
DECL|typedef|FT_GlyphRec
name|FT_GlyphRec
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
comment|/*    FT_BitmapGlyph                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an object used to model a bitmap glyph image.  This is */
end_comment
begin_comment
comment|/*    a sub-class of @FT_Glyph, and a pointer to @FT_BitmapGlyphRec.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_BitmapGlyph
typedef|typedef
name|struct
name|FT_BitmapGlyphRec_
modifier|*
name|FT_BitmapGlyph
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
comment|/*    FT_BitmapGlyphRec                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used for bitmap glyph images.  This really is a        */
end_comment
begin_comment
comment|/*    `sub-class' of @FT_GlyphRec.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    root   :: The root @FT_Glyph fields.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    left   :: The left-side bearing, i.e., the horizontal distance     */
end_comment
begin_comment
comment|/*              from the current pen position to the left border of the  */
end_comment
begin_comment
comment|/*              glyph bitmap.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    top    :: The top-side bearing, i.e., the vertical distance from   */
end_comment
begin_comment
comment|/*              the current pen position to the top border of the glyph  */
end_comment
begin_comment
comment|/*              bitmap.  This distance is positive for upwards~y!        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    bitmap :: A descriptor for the bitmap.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You can typecast an @FT_Glyph to @FT_BitmapGlyph if you have       */
end_comment
begin_comment
comment|/*    `glyph->format == FT_GLYPH_FORMAT_BITMAP'.  This lets you access   */
end_comment
begin_comment
comment|/*    the bitmap's contents easily.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The corresponding pixel buffer is always owned by @FT_BitmapGlyph  */
end_comment
begin_comment
comment|/*    and is thus created and destroyed with it.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_BitmapGlyphRec_
typedef|typedef
struct|struct
name|FT_BitmapGlyphRec_
block|{
DECL|member|root
name|FT_GlyphRec
name|root
decl_stmt|;
DECL|member|left
name|FT_Int
name|left
decl_stmt|;
DECL|member|top
name|FT_Int
name|top
decl_stmt|;
DECL|member|bitmap
name|FT_Bitmap
name|bitmap
decl_stmt|;
block|}
DECL|typedef|FT_BitmapGlyphRec
name|FT_BitmapGlyphRec
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
comment|/*    FT_OutlineGlyph                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A handle to an object used to model an outline glyph image.  This  */
end_comment
begin_comment
comment|/*    is a sub-class of @FT_Glyph, and a pointer to @FT_OutlineGlyphRec. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|typedef|FT_OutlineGlyph
typedef|typedef
name|struct
name|FT_OutlineGlyphRec_
modifier|*
name|FT_OutlineGlyph
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
comment|/*    FT_OutlineGlyphRec                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used for outline (vectorial) glyph images.  This       */
end_comment
begin_comment
comment|/*    really is a `sub-class' of @FT_GlyphRec.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    root    :: The root @FT_Glyph fields.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    outline :: A descriptor for the outline.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You can typecast an @FT_Glyph to @FT_OutlineGlyph if you have      */
end_comment
begin_comment
comment|/*    `glyph->format == FT_GLYPH_FORMAT_OUTLINE'.  This lets you access  */
end_comment
begin_comment
comment|/*    the outline's content easily.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    As the outline is extracted from a glyph slot, its coordinates are */
end_comment
begin_comment
comment|/*    expressed normally in 26.6 pixels, unless the flag                 */
end_comment
begin_comment
comment|/*    @FT_LOAD_NO_SCALE was used in @FT_Load_Glyph() or @FT_Load_Char(). */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The outline's tables are always owned by the object and are        */
end_comment
begin_comment
comment|/*    destroyed with it.                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_OutlineGlyphRec_
typedef|typedef
struct|struct
name|FT_OutlineGlyphRec_
block|{
DECL|member|root
name|FT_GlyphRec
name|root
decl_stmt|;
DECL|member|outline
name|FT_Outline
name|outline
decl_stmt|;
block|}
DECL|typedef|FT_OutlineGlyphRec
name|FT_OutlineGlyphRec
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
comment|/*    FT_Get_Glyph                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to extract a glyph image from a slot.  Note that   */
end_comment
begin_comment
comment|/*    the created @FT_Glyph object must be released with @FT_Done_Glyph. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    slot   :: A handle to the source glyph slot.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aglyph :: A handle to the glyph object.                            */
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
name|FT_Get_Glyph
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|,
argument|FT_Glyph     *aglyph
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
comment|/*    FT_Glyph_Copy                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to copy a glyph image.  Note that the created      */
end_comment
begin_comment
comment|/*    @FT_Glyph object must be released with @FT_Done_Glyph.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    source :: A handle to the source glyph object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    target :: A handle to the target glyph object.  0~in case of       */
end_comment
begin_comment
comment|/*              error.                                                   */
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
DECL|variable|FT_Glyph_Copy
name|FT_Glyph_Copy
argument_list|(
argument|FT_Glyph   source
argument_list|,
argument|FT_Glyph  *target
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
comment|/*    FT_Glyph_Transform                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Transform a glyph image if its format is scalable.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    glyph  :: A handle to the target glyph object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    matrix :: A pointer to a 2x2 matrix to apply.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    delta  :: A pointer to a 2d vector to apply.  Coordinates are      */
end_comment
begin_comment
comment|/*              expressed in 1/64th of a pixel.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code (if not 0, the glyph format is not scalable).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The 2x2 transformation matrix is also applied to the glyph's       */
end_comment
begin_comment
comment|/*    advance vector.                                                    */
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
name|FT_Glyph_Transform
argument_list|(
argument|FT_Glyph    glyph
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
comment|/*    FT_Glyph_BBox_Mode                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The mode how the values of @FT_Glyph_Get_CBox are returned.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*    FT_GLYPH_BBOX_UNSCALED ::                                          */
end_comment
begin_comment
comment|/*      Return unscaled font units.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_GLYPH_BBOX_SUBPIXELS ::                                         */
end_comment
begin_comment
comment|/*      Return unfitted 26.6 coordinates.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_GLYPH_BBOX_GRIDFIT ::                                           */
end_comment
begin_comment
comment|/*      Return grid-fitted 26.6 coordinates.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_GLYPH_BBOX_TRUNCATE ::                                          */
end_comment
begin_comment
comment|/*      Return coordinates in integer pixels.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    FT_GLYPH_BBOX_PIXELS ::                                            */
end_comment
begin_comment
comment|/*      Return grid-fitted pixel coordinates.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|enum|FT_Glyph_BBox_Mode_
typedef|typedef
enum|enum
name|FT_Glyph_BBox_Mode_
block|{
DECL|enumerator|FT_GLYPH_BBOX_UNSCALED
name|FT_GLYPH_BBOX_UNSCALED
init|=
literal|0
block|,
DECL|enumerator|FT_GLYPH_BBOX_SUBPIXELS
name|FT_GLYPH_BBOX_SUBPIXELS
init|=
literal|0
block|,
DECL|enumerator|FT_GLYPH_BBOX_GRIDFIT
name|FT_GLYPH_BBOX_GRIDFIT
init|=
literal|1
block|,
DECL|enumerator|FT_GLYPH_BBOX_TRUNCATE
name|FT_GLYPH_BBOX_TRUNCATE
init|=
literal|2
block|,
DECL|enumerator|FT_GLYPH_BBOX_PIXELS
name|FT_GLYPH_BBOX_PIXELS
init|=
literal|3
block|}
DECL|typedef|FT_Glyph_BBox_Mode
name|FT_Glyph_BBox_Mode
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
comment|/*    ft_glyph_bbox_xxx                                                  */
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
comment|/*    @FT_Glyph_BBox_Mode values instead.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Values>                                                              */
end_comment
begin_comment
comment|/*   ft_glyph_bbox_unscaled  :: See @FT_GLYPH_BBOX_UNSCALED.             */
end_comment
begin_comment
comment|/*   ft_glyph_bbox_subpixels :: See @FT_GLYPH_BBOX_SUBPIXELS.            */
end_comment
begin_comment
comment|/*   ft_glyph_bbox_gridfit   :: See @FT_GLYPH_BBOX_GRIDFIT.              */
end_comment
begin_comment
comment|/*   ft_glyph_bbox_truncate  :: See @FT_GLYPH_BBOX_TRUNCATE.             */
end_comment
begin_comment
comment|/*   ft_glyph_bbox_pixels    :: See @FT_GLYPH_BBOX_PIXELS.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|ft_glyph_bbox_unscaled
define|#
directive|define
name|ft_glyph_bbox_unscaled
value|FT_GLYPH_BBOX_UNSCALED
end_define
begin_define
DECL|macro|ft_glyph_bbox_subpixels
define|#
directive|define
name|ft_glyph_bbox_subpixels
value|FT_GLYPH_BBOX_SUBPIXELS
end_define
begin_define
DECL|macro|ft_glyph_bbox_gridfit
define|#
directive|define
name|ft_glyph_bbox_gridfit
value|FT_GLYPH_BBOX_GRIDFIT
end_define
begin_define
DECL|macro|ft_glyph_bbox_truncate
define|#
directive|define
name|ft_glyph_bbox_truncate
value|FT_GLYPH_BBOX_TRUNCATE
end_define
begin_define
DECL|macro|ft_glyph_bbox_pixels
define|#
directive|define
name|ft_glyph_bbox_pixels
value|FT_GLYPH_BBOX_PIXELS
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
comment|/*    FT_Glyph_Get_CBox                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return a glyph's `control box'.  The control box encloses all the  */
end_comment
begin_comment
comment|/*    outline's points, including BÃ©zier control points.  Though it      */
end_comment
begin_comment
comment|/*    coincides with the exact bounding box for most glyphs, it can be   */
end_comment
begin_comment
comment|/*    slightly larger in some situations (like when rotating an outline  */
end_comment
begin_comment
comment|/*    which contains BÃ©zier outside arcs).                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Computing the control box is very fast, while getting the bounding */
end_comment
begin_comment
comment|/*    box can take much more time as it needs to walk over all segments  */
end_comment
begin_comment
comment|/*    and arcs in the outline.  To get the latter, you can use the       */
end_comment
begin_comment
comment|/*    `ftbbox' component which is dedicated to this single task.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    glyph :: A handle to the source glyph object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    mode  :: The mode which indicates how to interpret the returned    */
end_comment
begin_comment
comment|/*             bounding box values.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    acbox :: The glyph coordinate bounding box.  Coordinates are       */
end_comment
begin_comment
comment|/*             expressed in 1/64th of pixels if it is grid-fitted.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Coordinates are relative to the glyph origin, using the y~upwards  */
end_comment
begin_comment
comment|/*    convention.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If the glyph has been loaded with @FT_LOAD_NO_SCALE, `bbox_mode'   */
end_comment
begin_comment
comment|/*    must be set to @FT_GLYPH_BBOX_UNSCALED to get unscaled font        */
end_comment
begin_comment
comment|/*    units in 26.6 pixel format.  The value @FT_GLYPH_BBOX_SUBPIXELS    */
end_comment
begin_comment
comment|/*    is another name for this constant.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note that the maximum coordinates are exclusive, which means that  */
end_comment
begin_comment
comment|/*    one can compute the width and height of the glyph image (be it in  */
end_comment
begin_comment
comment|/*    integer or 26.6 pixels) as:                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      width  = bbox.xMax - bbox.xMin;                                  */
end_comment
begin_comment
comment|/*      height = bbox.yMax - bbox.yMin;                                  */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Note also that for 26.6 coordinates, if `bbox_mode' is set to      */
end_comment
begin_comment
comment|/*    @FT_GLYPH_BBOX_GRIDFIT, the coordinates will also be grid-fitted,  */
end_comment
begin_comment
comment|/*    which corresponds to:                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      bbox.xMin = FLOOR(bbox.xMin);                                    */
end_comment
begin_comment
comment|/*      bbox.yMin = FLOOR(bbox.yMin);                                    */
end_comment
begin_comment
comment|/*      bbox.xMax = CEILING(bbox.xMax);                                  */
end_comment
begin_comment
comment|/*      bbox.yMax = CEILING(bbox.yMax);                                  */
end_comment
begin_comment
comment|/*    }                                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    To get the bbox in pixel coordinates, set `bbox_mode' to           */
end_comment
begin_comment
comment|/*    @FT_GLYPH_BBOX_TRUNCATE.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    To get the bbox in grid-fitted pixel coordinates, set `bbox_mode'  */
end_comment
begin_comment
comment|/*    to @FT_GLYPH_BBOX_PIXELS.                                          */
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
name|FT_Glyph_Get_CBox
argument_list|(
argument|FT_Glyph  glyph
argument_list|,
argument|FT_UInt   bbox_mode
argument_list|,
argument|FT_BBox  *acbox
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
comment|/*    FT_Glyph_To_Bitmap                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Convert a given glyph object to a bitmap glyph object.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    the_glyph   :: A pointer to a handle to the target glyph.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    render_mode :: An enumeration that describes how the data is       */
end_comment
begin_comment
comment|/*                   rendered.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    origin      :: A pointer to a vector used to translate the glyph   */
end_comment
begin_comment
comment|/*                   image before rendering.  Can be~0 (if no            */
end_comment
begin_comment
comment|/*                   translation).  The origin is expressed in           */
end_comment
begin_comment
comment|/*                   26.6 pixels.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    destroy     :: A boolean that indicates that the original glyph    */
end_comment
begin_comment
comment|/*                   image should be destroyed by this function.  It is  */
end_comment
begin_comment
comment|/*                   never destroyed in case of error.                   */
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
comment|/*    This function does nothing if the glyph format isn't scalable.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The glyph image is translated with the `origin' vector before      */
end_comment
begin_comment
comment|/*    rendering.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The first parameter is a pointer to an @FT_Glyph handle, that will */
end_comment
begin_comment
comment|/*    be _replaced_ by this function (with newly allocated data).        */
end_comment
begin_comment
comment|/*    Typically, you would use (omitting error handling):                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      {                                                                */
end_comment
begin_comment
comment|/*        FT_Glyph        glyph;                                         */
end_comment
begin_comment
comment|/*        FT_BitmapGlyph  glyph_bitmap;                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        // load glyph                                                  */
end_comment
begin_comment
comment|/*        error = FT_Load_Char( face, glyph_index, FT_LOAD_DEFAUT );     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        // extract glyph image                                         */
end_comment
begin_comment
comment|/*        error = FT_Get_Glyph( face->glyph,&glyph );                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        // convert to a bitmap (default render mode + destroying old)  */
end_comment
begin_comment
comment|/*        if ( glyph->format != FT_GLYPH_FORMAT_BITMAP )                 */
end_comment
begin_comment
comment|/*        {                                                              */
end_comment
begin_comment
comment|/*          error = FT_Glyph_To_Bitmap(&glyph, FT_RENDER_MODE_NORMAL,   */
end_comment
begin_comment
comment|/*                                      0, 1 );                          */
end_comment
begin_comment
comment|/*          if ( error ) // `glyph' unchanged                            */
end_comment
begin_comment
comment|/*            ...                                                        */
end_comment
begin_comment
comment|/*        }                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        // access bitmap content by typecasting                        */
end_comment
begin_comment
comment|/*        glyph_bitmap = (FT_BitmapGlyph)glyph;                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        // do funny stuff with it, like blitting/drawing               */
end_comment
begin_comment
comment|/*        ...                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        // discard glyph image (bitmap or not)                         */
end_comment
begin_comment
comment|/*        FT_Done_Glyph( glyph );                                        */
end_comment
begin_comment
comment|/*      }                                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Here another example, again without error handling:                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*      {                                                                */
end_comment
begin_comment
comment|/*        FT_Glyph  glyphs[MAX_GLYPHS]                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        ...                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        for ( idx = 0; i< MAX_GLYPHS; i++ )                           */
end_comment
begin_comment
comment|/*          error = FT_Load_Glyph( face, idx, FT_LOAD_DEFAULT ) ||       */
end_comment
begin_comment
comment|/*                  FT_Get_Glyph ( face->glyph,&glyph[idx] );           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        ...                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        for ( idx = 0; i< MAX_GLYPHS; i++ )                           */
end_comment
begin_comment
comment|/*        {                                                              */
end_comment
begin_comment
comment|/*          FT_Glyph  bitmap = glyphs[idx];                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*          ...                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*          // after this call, `bitmap' no longer points into           */
end_comment
begin_comment
comment|/*          // the `glyphs' array (and the old value isn't destroyed)    */
end_comment
begin_comment
comment|/*          FT_Glyph_To_Bitmap(&bitmap, FT_RENDER_MODE_MONO, 0, 0 );    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*          ...                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*          FT_Done_Glyph( bitmap );                                     */
end_comment
begin_comment
comment|/*        }                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        ...                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*        for ( idx = 0; i< MAX_GLYPHS; i++ )                           */
end_comment
begin_comment
comment|/*          FT_Done_Glyph( glyphs[idx] );                                */
end_comment
begin_comment
comment|/*      }                                                                */
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
name|FT_Glyph_To_Bitmap
argument_list|(
argument|FT_Glyph*       the_glyph
argument_list|,
argument|FT_Render_Mode  render_mode
argument_list|,
argument|FT_Vector*      origin
argument_list|,
argument|FT_Bool         destroy
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
comment|/*    FT_Done_Glyph                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroy a given glyph.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    glyph :: A handle to the target glyph object.                      */
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
DECL|variable|FT_Done_Glyph
name|FT_Done_Glyph
argument_list|(
argument|FT_Glyph  glyph
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Done_Glyph
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_comment
comment|/* other helpful functions */
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
comment|/*    computations                                                       */
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
comment|/*    FT_Matrix_Multiply                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Perform the matrix operation `b = a*b'.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    a :: A pointer to matrix `a'.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    b :: A pointer to matrix `b'.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The result is undefined if either `a' or `b' is zero.              */
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
name|FT_Matrix_Multiply
argument_list|(
specifier|const
name|FT_Matrix
operator|*
name|a
argument_list|,
name|FT_Matrix
operator|*
name|b
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
comment|/*    FT_Matrix_Invert                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Invert a 2x2 matrix.  Return an error if it can't be inverted.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    matrix :: A pointer to the target matrix.  Remains untouched in    */
end_comment
begin_comment
comment|/*              case of error.                                           */
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
begin_expr_stmt
name|FT_Matrix_Invert
argument_list|(
name|FT_Matrix
operator|*
name|matrix
argument_list|)
expr_stmt|;
end_expr_stmt
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
comment|/* __FTGLYPH_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
begin_comment
comment|/* Local Variables: */
end_comment
begin_comment
comment|/* coding: utf-8    */
end_comment
begin_comment
comment|/* End:             */
end_comment
end_unit
