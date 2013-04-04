begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftoutln.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Support for the FT_Outline type used to store glyph shapes of        */
end_comment
begin_comment
comment|/*    most scalable font formats (specification).                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2005, 2006, 2007, 2008, 2009, 2010 by */
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
name|__FTOUTLN_H__
end_ifndef
begin_define
DECL|macro|__FTOUTLN_H__
define|#
directive|define
name|__FTOUTLN_H__
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
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Section>                                                             */
comment|/*    outline_processing                                                 */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    Outline Processing                                                 */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Functions to create, transform, and render vectorial glyph images. */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains routines used to create and destroy scalable */
comment|/*    glyph images known as `outlines'.  These can also be measured,     */
comment|/*    transformed, and converted into bitmaps and pixmaps.               */
comment|/*                                                                       */
comment|/*<Order>                                                               */
comment|/*    FT_Outline                                                         */
comment|/*    FT_OUTLINE_FLAGS                                                   */
comment|/*    FT_Outline_New                                                     */
comment|/*    FT_Outline_Done                                                    */
comment|/*    FT_Outline_Copy                                                    */
comment|/*    FT_Outline_Translate                                               */
comment|/*    FT_Outline_Transform                                               */
comment|/*    FT_Outline_Embolden                                                */
comment|/*    FT_Outline_Reverse                                                 */
comment|/*    FT_Outline_Check                                                   */
comment|/*                                                                       */
comment|/*    FT_Outline_Get_CBox                                                */
comment|/*    FT_Outline_Get_BBox                                                */
comment|/*                                                                       */
comment|/*    FT_Outline_Get_Bitmap                                              */
comment|/*    FT_Outline_Render                                                  */
comment|/*                                                                       */
comment|/*    FT_Outline_Decompose                                               */
comment|/*    FT_Outline_Funcs                                                   */
comment|/*    FT_Outline_MoveTo_Func                                             */
comment|/*    FT_Outline_LineTo_Func                                             */
comment|/*    FT_Outline_ConicTo_Func                                            */
comment|/*    FT_Outline_CubicTo_Func                                            */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Function>                                                            */
comment|/*    FT_Outline_Decompose                                               */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    Walk over an outline's structure to decompose it into individual   */
comment|/*    segments and BÃ©zier arcs.  This function also emits `move to'      */
comment|/*    operations to indicate the start of new contours in the outline.   */
comment|/*                                                                       */
comment|/*<Input>                                                               */
comment|/*    outline        :: A pointer to the source target.                  */
comment|/*                                                                       */
comment|/*    func_interface :: A table of `emitters', i.e., function pointers   */
comment|/*                      called during decomposition to indicate path     */
comment|/*                      operations.                                      */
comment|/*                                                                       */
comment|/*<InOut>                                                               */
comment|/*    user           :: A typeless pointer which is passed to each       */
comment|/*                      emitter during the decomposition.  It can be     */
comment|/*                      used to store the state during the               */
comment|/*                      decomposition.                                   */
comment|/*                                                                       */
comment|/*<Return>                                                              */
comment|/*    FreeType error code.  0~means success.                             */
comment|/*                                                                       */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Outline_Decompose
parameter_list|(
name|FT_Outline
modifier|*
name|outline
parameter_list|,
specifier|const
name|FT_Outline_Funcs
modifier|*
name|func_interface
parameter_list|,
name|void
modifier|*
name|user
parameter_list|)
function_decl|;
end_function_decl
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
comment|/*    FT_Outline_New                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Create a new outline of a given size.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library     :: A handle to the library object from where the       */
end_comment
begin_comment
comment|/*                   outline is allocated.  Note however that the new    */
end_comment
begin_comment
comment|/*                   outline will *not* necessarily be *freed*, when     */
end_comment
begin_comment
comment|/*                   destroying the library, by @FT_Done_FreeType.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    numPoints   :: The maximal number of points within the outline.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    numContours :: The maximal number of contours within the outline.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    anoutline   :: A handle to the new outline.                        */
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
comment|/*    The reason why this function takes a `library' parameter is simply */
end_comment
begin_comment
comment|/*    to use the library's memory allocator.                             */
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
DECL|variable|FT_Outline_New
name|FT_Outline_New
argument_list|(
argument|FT_Library   library
argument_list|,
argument|FT_UInt      numPoints
argument_list|,
argument|FT_Int       numContours
argument_list|,
argument|FT_Outline  *anoutline
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Outline_New_Internal
argument_list|(
argument|FT_Memory    memory
argument_list|,
argument|FT_UInt      numPoints
argument_list|,
argument|FT_Int       numContours
argument_list|,
argument|FT_Outline  *anoutline
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
comment|/*    FT_Outline_Done                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroy an outline created with @FT_Outline_New.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle of the library object used to allocate the     */
end_comment
begin_comment
comment|/*               outline.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    outline :: A pointer to the outline object to be discarded.        */
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
comment|/*    If the outline's `owner' field is not set, only the outline        */
end_comment
begin_comment
comment|/*    descriptor will be released.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The reason why this function takes an `library' parameter is       */
end_comment
begin_comment
comment|/*    simply to use ft_mem_free().                                       */
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
DECL|variable|FT_Outline_Done
name|FT_Outline_Done
argument_list|(
argument|FT_Library   library
argument_list|,
argument|FT_Outline*  outline
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Outline_Done_Internal
argument_list|(
argument|FT_Memory    memory
argument_list|,
argument|FT_Outline*  outline
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
comment|/*    FT_Outline_Check                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Check the contents of an outline descriptor.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    outline :: A handle to a source outline.                           */
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
DECL|variable|FT_Outline_Check
name|FT_Outline_Check
argument_list|(
name|FT_Outline
operator|*
name|outline
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
comment|/*    FT_Outline_Get_CBox                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return an outline's `control box'.  The control box encloses all   */
end_comment
begin_comment
comment|/*    the outline's points, including BÃ©zier control points.  Though it  */
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
comment|/*    outline :: A pointer to the source outline descriptor.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    acbox   :: The outline's control box.                              */
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
name|FT_Outline_Get_CBox
argument_list|(
specifier|const
name|FT_Outline
operator|*
name|outline
argument_list|,
name|FT_BBox
operator|*
name|acbox
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
comment|/*    FT_Outline_Translate                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Apply a simple translation to the points of an outline.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    outline :: A pointer to the target outline descriptor.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    xOffset :: The horizontal offset.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    yOffset :: The vertical offset.                                    */
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
name|FT_Outline_Translate
argument_list|(
argument|const FT_Outline*  outline
argument_list|,
argument|FT_Pos             xOffset
argument_list|,
argument|FT_Pos             yOffset
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
comment|/*    FT_Outline_Copy                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Copy an outline into another one.  Both objects must have the      */
end_comment
begin_comment
comment|/*    same sizes (number of points& number of contours) when this       */
end_comment
begin_comment
comment|/*    function is called.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    source :: A handle to the source outline.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    target :: A handle to the target outline.                          */
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
name|FT_Outline_Copy
argument_list|(
specifier|const
name|FT_Outline
operator|*
name|source
argument_list|,
name|FT_Outline
operator|*
name|target
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
comment|/*    FT_Outline_Transform                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Apply a simple 2x2 matrix to all of an outline's points.  Useful   */
end_comment
begin_comment
comment|/*    for applying rotations, slanting, flipping, etc.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    outline :: A pointer to the target outline descriptor.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    matrix  :: A pointer to the transformation matrix.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You can use @FT_Outline_Translate if you need to translate the     */
end_comment
begin_comment
comment|/*    outline's points.                                                  */
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
DECL|variable|FT_Outline_Transform
name|FT_Outline_Transform
argument_list|(
specifier|const
name|FT_Outline
operator|*
name|outline
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
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Outline_Embolden                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Embolden an outline.  The new outline will be at most 4~times      */
end_comment
begin_comment
comment|/*    `strength' pixels wider and higher.  You may think of the left and */
end_comment
begin_comment
comment|/*    bottom borders as unchanged.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Negative `strength' values to reduce the outline thickness are     */
end_comment
begin_comment
comment|/*    possible also.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    outline  :: A handle to the target outline.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    strength :: How strong the glyph is emboldened.  Expressed in      */
end_comment
begin_comment
comment|/*                26.6 pixel format.                                     */
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
comment|/*    The used algorithm to increase or decrease the thickness of the    */
end_comment
begin_comment
comment|/*    glyph doesn't change the number of points; this means that certain */
end_comment
begin_comment
comment|/*    situations like acute angles or intersections are sometimes        */
end_comment
begin_comment
comment|/*    handled incorrectly.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If you need `better' metrics values you should call                */
end_comment
begin_comment
comment|/*    @FT_Outline_Get_CBox ot @FT_Outline_Get_BBox.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Example call:                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    {                                                                  */
end_comment
begin_comment
comment|/*      FT_Load_Glyph( face, index, FT_LOAD_DEFAULT );                   */
end_comment
begin_comment
comment|/*      if ( face->slot->format == FT_GLYPH_FORMAT_OUTLINE )             */
end_comment
begin_comment
comment|/*        FT_Outline_Embolden(&face->slot->outline, strength );         */
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
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Outline_Embolden
argument_list|(
argument|FT_Outline*  outline
argument_list|,
argument|FT_Pos       strength
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
comment|/*    FT_Outline_Reverse                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Reverse the drawing direction of an outline.  This is used to      */
end_comment
begin_comment
comment|/*    ensure consistent fill conventions for mirrored glyphs.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    outline :: A pointer to the target outline descriptor.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function toggles the bit flag @FT_OUTLINE_REVERSE_FILL in     */
end_comment
begin_comment
comment|/*    the outline's `flags' field.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    It shouldn't be used by a normal client application, unless it     */
end_comment
begin_comment
comment|/*    knows what it is doing.                                            */
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
DECL|variable|FT_Outline_Reverse
name|FT_Outline_Reverse
argument_list|(
name|FT_Outline
operator|*
name|outline
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
comment|/*    FT_Outline_Get_Bitmap                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Render an outline within a bitmap.  The outline's image is simply  */
end_comment
begin_comment
comment|/*    OR-ed to the target bitmap.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to a FreeType library object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    outline :: A pointer to the source outline descriptor.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    abitmap :: A pointer to the target bitmap descriptor.              */
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
comment|/*    This function does NOT CREATE the bitmap, it only renders an       */
end_comment
begin_comment
comment|/*    outline image within the one you pass to it!  Consequently, the    */
end_comment
begin_comment
comment|/*    various fields in `abitmap' should be set accordingly.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    It will use the raster corresponding to the default glyph format.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The value of the `num_grays' field in `abitmap' is ignored.  If    */
end_comment
begin_comment
comment|/*    you select the gray-level rasterizer, and you want less than 256   */
end_comment
begin_comment
comment|/*    gray levels, you have to use @FT_Outline_Render directly.          */
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
name|FT_Outline_Get_Bitmap
argument_list|(
argument|FT_Library        library
argument_list|,
argument|FT_Outline*       outline
argument_list|,
argument|const FT_Bitmap  *abitmap
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
comment|/*    FT_Outline_Render                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Render an outline within a bitmap using the current scan-convert.  */
end_comment
begin_comment
comment|/*    This function uses an @FT_Raster_Params structure as an argument,  */
end_comment
begin_comment
comment|/*    allowing advanced features like direct composition, translucency,  */
end_comment
begin_comment
comment|/*    etc.                                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to a FreeType library object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    outline :: A pointer to the source outline descriptor.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    params  :: A pointer to an @FT_Raster_Params structure used to     */
end_comment
begin_comment
comment|/*               describe the rendering operation.                       */
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
comment|/*    You should know what you are doing and how @FT_Raster_Params works */
end_comment
begin_comment
comment|/*    to use this function.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The field `params.source' will be set to `outline' before the scan */
end_comment
begin_comment
comment|/*    converter is called, which means that the value you give to it is  */
end_comment
begin_comment
comment|/*    actually ignored.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    The gray-level rasterizer always uses 256 gray levels.  If you     */
end_comment
begin_comment
comment|/*    want less gray levels, you have to provide your own span callback. */
end_comment
begin_comment
comment|/*    See the @FT_RASTER_FLAG_DIRECT value of the `flags' field in the   */
end_comment
begin_comment
comment|/*    @FT_Raster_Params structure for more details.                      */
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
DECL|variable|FT_Outline_Render
name|FT_Outline_Render
argument_list|(
argument|FT_Library         library
argument_list|,
argument|FT_Outline*        outline
argument_list|,
argument|FT_Raster_Params*  params
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/**************************************************************************   *   * @enum:   *   FT_Orientation   *   * @description:   *   A list of values used to describe an outline's contour orientation.   *   *   The TrueType and PostScript specifications use different conventions   *   to determine whether outline contours should be filled or unfilled.   *   * @values:   *   FT_ORIENTATION_TRUETYPE ::   *     According to the TrueType specification, clockwise contours must   *     be filled, and counter-clockwise ones must be unfilled.   *   *   FT_ORIENTATION_POSTSCRIPT ::   *     According to the PostScript specification, counter-clockwise contours   *     must be filled, and clockwise ones must be unfilled.   *   *   FT_ORIENTATION_FILL_RIGHT ::   *     This is identical to @FT_ORIENTATION_TRUETYPE, but is used to   *     remember that in TrueType, everything that is to the right of   *     the drawing direction of a contour must be filled.   *   *   FT_ORIENTATION_FILL_LEFT ::   *     This is identical to @FT_ORIENTATION_POSTSCRIPT, but is used to   *     remember that in PostScript, everything that is to the left of   *     the drawing direction of a contour must be filled.   *   *   FT_ORIENTATION_NONE ::   *     The orientation cannot be determined.  That is, different parts of   *     the glyph have different orientation.   *   */
end_comment
begin_typedef
DECL|enum|FT_Orientation_
typedef|typedef
enum|enum
name|FT_Orientation_
block|{
DECL|enumerator|FT_ORIENTATION_TRUETYPE
name|FT_ORIENTATION_TRUETYPE
init|=
literal|0
block|,
DECL|enumerator|FT_ORIENTATION_POSTSCRIPT
name|FT_ORIENTATION_POSTSCRIPT
init|=
literal|1
block|,
DECL|enumerator|FT_ORIENTATION_FILL_RIGHT
name|FT_ORIENTATION_FILL_RIGHT
init|=
name|FT_ORIENTATION_TRUETYPE
block|,
DECL|enumerator|FT_ORIENTATION_FILL_LEFT
name|FT_ORIENTATION_FILL_LEFT
init|=
name|FT_ORIENTATION_POSTSCRIPT
block|,
DECL|enumerator|FT_ORIENTATION_NONE
name|FT_ORIENTATION_NONE
block|}
DECL|typedef|FT_Orientation
name|FT_Orientation
typedef|;
end_typedef
begin_comment
comment|/**************************************************************************   *   * @function:   *   FT_Outline_Get_Orientation   *   * @description:   *   This function analyzes a glyph outline and tries to compute its   *   fill orientation (see @FT_Orientation).  This is done by computing   *   the direction of each global horizontal and/or vertical extrema   *   within the outline.   *   *   Note that this will return @FT_ORIENTATION_TRUETYPE for empty   *   outlines.   *   * @input:   *   outline ::   *     A handle to the source outline.   *   * @return:   *   The orientation.   *   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Orientation
argument_list|)
end_macro
begin_expr_stmt
name|FT_Outline_Get_Orientation
argument_list|(
name|FT_Outline
operator|*
name|outline
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
comment|/* __FTOUTLN_H__ */
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
