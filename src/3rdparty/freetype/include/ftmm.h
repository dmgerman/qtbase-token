begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmm.h                                                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType Multiple Master font interface (specification).             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2003, 2004, 2006, 2009, 2013 by                   */
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
name|__FTMM_H__
end_ifndef
begin_define
DECL|macro|__FTMM_H__
define|#
directive|define
name|__FTMM_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_TYPE1_TABLES_H
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
comment|/*    multiple_masters                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Title>                                                               */
end_comment
begin_comment
comment|/*    Multiple Masters                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Abstract>                                                            */
end_comment
begin_comment
comment|/*    How to manage Multiple Masters fonts.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The following types and functions are used to manage Multiple      */
end_comment
begin_comment
comment|/*    Master fonts, i.e., the selection of specific design instances by  */
end_comment
begin_comment
comment|/*    setting design axis coordinates.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    George Williams has extended this interface to make it work with   */
end_comment
begin_comment
comment|/*    both Type~1 Multiple Masters fonts and GX distortable (var)        */
end_comment
begin_comment
comment|/*    fonts.  Some of these routines only work with MM fonts, others     */
end_comment
begin_comment
comment|/*    will work with both types.  They are similar enough that a         */
end_comment
begin_comment
comment|/*    consistent interface makes sense.                                  */
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
comment|/*    FT_MM_Axis                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to model a given axis in design space for  */
end_comment
begin_comment
comment|/*    Multiple Masters fonts.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This structure can't be used for GX var fonts.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    name    :: The axis's name.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    minimum :: The axis's minimum design coordinate.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maximum :: The axis's maximum design coordinate.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_MM_Axis_
typedef|typedef
struct|struct
name|FT_MM_Axis_
block|{
DECL|member|name
name|FT_String
modifier|*
name|name
decl_stmt|;
DECL|member|minimum
name|FT_Long
name|minimum
decl_stmt|;
DECL|member|maximum
name|FT_Long
name|maximum
decl_stmt|;
block|}
DECL|typedef|FT_MM_Axis
name|FT_MM_Axis
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
comment|/*    FT_Multi_Master                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model the axes and space of a Multiple Masters */
end_comment
begin_comment
comment|/*    font.                                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This structure can't be used for GX var fonts.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    num_axis    :: Number of axes.  Cannot exceed~4.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_designs :: Number of designs; should be normally 2^num_axis    */
end_comment
begin_comment
comment|/*                   even though the Type~1 specification strangely      */
end_comment
begin_comment
comment|/*                   allows for intermediate designs to be present. This */
end_comment
begin_comment
comment|/*                   number cannot exceed~16.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    axis        :: A table of axis descriptors.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Multi_Master_
typedef|typedef
struct|struct
name|FT_Multi_Master_
block|{
DECL|member|num_axis
name|FT_UInt
name|num_axis
decl_stmt|;
DECL|member|num_designs
name|FT_UInt
name|num_designs
decl_stmt|;
DECL|member|axis
name|FT_MM_Axis
name|axis
index|[
name|T1_MAX_MM_AXIS
index|]
decl_stmt|;
block|}
DECL|typedef|FT_Multi_Master
name|FT_Multi_Master
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
comment|/*    FT_Var_Axis                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to model a given axis in design space for  */
end_comment
begin_comment
comment|/*    Multiple Masters and GX var fonts.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    name    :: The axis's name.                                        */
end_comment
begin_comment
comment|/*               Not always meaningful for GX.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    minimum :: The axis's minimum design coordinate.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    def     :: The axis's default design coordinate.                   */
end_comment
begin_comment
comment|/*               FreeType computes meaningful default values for MM; it  */
end_comment
begin_comment
comment|/*               is then an integer value, not in 16.16 format.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    maximum :: The axis's maximum design coordinate.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tag     :: The axis's tag (the GX equivalent to `name').           */
end_comment
begin_comment
comment|/*               FreeType provides default values for MM if possible.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    strid   :: The entry in `name' table (another GX version of        */
end_comment
begin_comment
comment|/*               `name').                                                */
end_comment
begin_comment
comment|/*               Not meaningful for MM.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Var_Axis_
typedef|typedef
struct|struct
name|FT_Var_Axis_
block|{
DECL|member|name
name|FT_String
modifier|*
name|name
decl_stmt|;
DECL|member|minimum
name|FT_Fixed
name|minimum
decl_stmt|;
DECL|member|def
name|FT_Fixed
name|def
decl_stmt|;
DECL|member|maximum
name|FT_Fixed
name|maximum
decl_stmt|;
DECL|member|tag
name|FT_ULong
name|tag
decl_stmt|;
DECL|member|strid
name|FT_UInt
name|strid
decl_stmt|;
block|}
DECL|typedef|FT_Var_Axis
name|FT_Var_Axis
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
comment|/*    FT_Var_Named_Style                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A simple structure used to model a named style in a GX var font.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This structure can't be used for MM fonts.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    coords :: The design coordinates for this style.                   */
end_comment
begin_comment
comment|/*              This is an array with one entry for each axis.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    strid  :: The entry in `name' table identifying this style.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Var_Named_Style_
typedef|typedef
struct|struct
name|FT_Var_Named_Style_
block|{
DECL|member|coords
name|FT_Fixed
modifier|*
name|coords
decl_stmt|;
DECL|member|strid
name|FT_UInt
name|strid
decl_stmt|;
block|}
DECL|typedef|FT_Var_Named_Style
name|FT_Var_Named_Style
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
comment|/*    FT_MM_Var                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A structure used to model the axes and space of a Multiple Masters */
end_comment
begin_comment
comment|/*    or GX var distortable font.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Some fields are specific to one format and not to the other.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    num_axis        :: The number of axes.  The maximum value is~4 for */
end_comment
begin_comment
comment|/*                       MM; no limit in GX.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_designs     :: The number of designs; should be normally       */
end_comment
begin_comment
comment|/*                       2^num_axis for MM fonts.  Not meaningful for GX */
end_comment
begin_comment
comment|/*                       (where every glyph could have a different       */
end_comment
begin_comment
comment|/*                       number of designs).                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_namedstyles :: The number of named styles; only meaningful for */
end_comment
begin_comment
comment|/*                       GX that allows certain design coordinates to    */
end_comment
begin_comment
comment|/*                       have a string ID (in the `name' table)          */
end_comment
begin_comment
comment|/*                       associated with them.  The font can tell the    */
end_comment
begin_comment
comment|/*                       user that, for example, Weight=1.5 is `Bold'.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    axis            :: A table of axis descriptors.                    */
end_comment
begin_comment
comment|/*                       GX fonts contain slightly more data than MM.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    namedstyles     :: A table of named styles.                        */
end_comment
begin_comment
comment|/*                       Only meaningful with GX.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_MM_Var_
typedef|typedef
struct|struct
name|FT_MM_Var_
block|{
DECL|member|num_axis
name|FT_UInt
name|num_axis
decl_stmt|;
DECL|member|num_designs
name|FT_UInt
name|num_designs
decl_stmt|;
DECL|member|num_namedstyles
name|FT_UInt
name|num_namedstyles
decl_stmt|;
DECL|member|axis
name|FT_Var_Axis
modifier|*
name|axis
decl_stmt|;
DECL|member|namedstyle
name|FT_Var_Named_Style
modifier|*
name|namedstyle
decl_stmt|;
block|}
DECL|typedef|FT_MM_Var
name|FT_MM_Var
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
comment|/*    FT_Get_Multi_Master                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the Multiple Master descriptor of a given font.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function can't be used with GX fonts.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face    :: A handle to the source face.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    amaster :: The Multiple Masters descriptor.                        */
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
name|FT_Get_Multi_Master
argument_list|(
argument|FT_Face           face
argument_list|,
argument|FT_Multi_Master  *amaster
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
comment|/*    FT_Get_MM_Var                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the Multiple Master/GX var descriptor of a given font.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face    :: A handle to the source face.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    amaster :: The Multiple Masters/GX var descriptor.                 */
end_comment
begin_comment
comment|/*               Allocates a data structure, which the user must free.   */
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
DECL|variable|FT_Get_MM_Var
name|FT_Get_MM_Var
argument_list|(
argument|FT_Face      face
argument_list|,
argument|FT_MM_Var*  *amaster
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
comment|/*    FT_Set_MM_Design_Coordinates                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    For Multiple Masters fonts, choose an interpolated font design     */
end_comment
begin_comment
comment|/*    through design coordinates.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function can't be used with GX fonts.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face       :: A handle to the source face.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    num_coords :: The number of design coordinates (must be equal to   */
end_comment
begin_comment
comment|/*                  the number of axes in the font).                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    coords     :: An array of design coordinates.                      */
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
name|FT_Set_MM_Design_Coordinates
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_UInt   num_coords
argument_list|,
argument|FT_Long*  coords
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
comment|/*    FT_Set_Var_Design_Coordinates                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    For Multiple Master or GX Var fonts, choose an interpolated font   */
end_comment
begin_comment
comment|/*    design through design coordinates.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face       :: A handle to the source face.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    num_coords :: The number of design coordinates (must be equal to   */
end_comment
begin_comment
comment|/*                  the number of axes in the font).                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    coords     :: An array of design coordinates.                      */
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
DECL|variable|FT_Set_Var_Design_Coordinates
name|FT_Set_Var_Design_Coordinates
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
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
comment|/*    FT_Set_MM_Blend_Coordinates                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    For Multiple Masters and GX var fonts, choose an interpolated font */
end_comment
begin_comment
comment|/*    design through normalized blend coordinates.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    face       :: A handle to the source face.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    num_coords :: The number of design coordinates (must be equal to   */
end_comment
begin_comment
comment|/*                  the number of axes in the font).                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    coords     :: The design coordinates array (each element must be   */
end_comment
begin_comment
comment|/*                  between 0 and 1.0).                                  */
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
name|FT_Set_MM_Blend_Coordinates
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
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
comment|/*    FT_Set_Var_Blend_Coordinates                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This is another name of @FT_Set_MM_Blend_Coordinates.              */
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
DECL|variable|FT_Set_Var_Blend_Coordinates
name|FT_Set_Var_Blend_Coordinates
argument_list|(
argument|FT_Face    face
argument_list|,
argument|FT_UInt    num_coords
argument_list|,
argument|FT_Fixed*  coords
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
comment|/* __FTMM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
