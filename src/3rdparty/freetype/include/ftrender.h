begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftrender.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType renderer modules public interface (specification).          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2005, 2006, 2010 by                               */
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
name|__FTRENDER_H__
end_ifndef
begin_define
DECL|macro|__FTRENDER_H__
define|#
directive|define
name|__FTRENDER_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_MODULE_H
end_include
begin_include
include|#
directive|include
include|FT_GLYPH_H
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
comment|/*    module_management                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/* create a new glyph object */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Glyph_InitFunc
modifier|*
name|FT_Glyph_InitFunc
function_decl|)
parameter_list|(
name|FT_Glyph
name|glyph
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* destroys a given glyph object */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Glyph_DoneFunc
modifier|*
name|FT_Glyph_DoneFunc
function_decl|)
parameter_list|(
name|FT_Glyph
name|glyph
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Glyph_TransformFunc
modifier|*
name|FT_Glyph_TransformFunc
function_decl|)
parameter_list|(
name|FT_Glyph
name|glyph
parameter_list|,
specifier|const
name|FT_Matrix
modifier|*
name|matrix
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|delta
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Glyph_GetBBoxFunc
modifier|*
name|FT_Glyph_GetBBoxFunc
function_decl|)
parameter_list|(
name|FT_Glyph
name|glyph
parameter_list|,
name|FT_BBox
modifier|*
name|abbox
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Glyph_CopyFunc
modifier|*
name|FT_Glyph_CopyFunc
function_decl|)
parameter_list|(
name|FT_Glyph
name|source
parameter_list|,
name|FT_Glyph
name|target
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Glyph_PrepareFunc
modifier|*
name|FT_Glyph_PrepareFunc
function_decl|)
parameter_list|(
name|FT_Glyph
name|glyph
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* deprecated */
end_comment
begin_define
DECL|macro|FT_Glyph_Init_Func
define|#
directive|define
name|FT_Glyph_Init_Func
value|FT_Glyph_InitFunc
end_define
begin_define
DECL|macro|FT_Glyph_Done_Func
define|#
directive|define
name|FT_Glyph_Done_Func
value|FT_Glyph_DoneFunc
end_define
begin_define
DECL|macro|FT_Glyph_Transform_Func
define|#
directive|define
name|FT_Glyph_Transform_Func
value|FT_Glyph_TransformFunc
end_define
begin_define
DECL|macro|FT_Glyph_BBox_Func
define|#
directive|define
name|FT_Glyph_BBox_Func
value|FT_Glyph_GetBBoxFunc
end_define
begin_define
DECL|macro|FT_Glyph_Copy_Func
define|#
directive|define
name|FT_Glyph_Copy_Func
value|FT_Glyph_CopyFunc
end_define
begin_define
DECL|macro|FT_Glyph_Prepare_Func
define|#
directive|define
name|FT_Glyph_Prepare_Func
value|FT_Glyph_PrepareFunc
end_define
begin_struct
DECL|struct|FT_Glyph_Class_
struct|struct
name|FT_Glyph_Class_
block|{
DECL|member|glyph_size
name|FT_Long
name|glyph_size
decl_stmt|;
DECL|member|glyph_format
name|FT_Glyph_Format
name|glyph_format
decl_stmt|;
DECL|member|glyph_init
name|FT_Glyph_InitFunc
name|glyph_init
decl_stmt|;
DECL|member|glyph_done
name|FT_Glyph_DoneFunc
name|glyph_done
decl_stmt|;
DECL|member|glyph_copy
name|FT_Glyph_CopyFunc
name|glyph_copy
decl_stmt|;
DECL|member|glyph_transform
name|FT_Glyph_TransformFunc
name|glyph_transform
decl_stmt|;
DECL|member|glyph_bbox
name|FT_Glyph_GetBBoxFunc
name|glyph_bbox
decl_stmt|;
DECL|member|glyph_prepare
name|FT_Glyph_PrepareFunc
name|glyph_prepare
decl_stmt|;
block|}
struct|;
end_struct
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Renderer_RenderFunc
modifier|*
name|FT_Renderer_RenderFunc
function_decl|)
parameter_list|(
name|FT_Renderer
name|renderer
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_UInt
name|mode
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|origin
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Renderer_TransformFunc
modifier|*
name|FT_Renderer_TransformFunc
function_decl|)
parameter_list|(
name|FT_Renderer
name|renderer
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
specifier|const
name|FT_Matrix
modifier|*
name|matrix
parameter_list|,
specifier|const
name|FT_Vector
modifier|*
name|delta
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Renderer_GetCBoxFunc
modifier|*
name|FT_Renderer_GetCBoxFunc
function_decl|)
parameter_list|(
name|FT_Renderer
name|renderer
parameter_list|,
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_BBox
modifier|*
name|cbox
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Renderer_SetModeFunc
modifier|*
name|FT_Renderer_SetModeFunc
function_decl|)
parameter_list|(
name|FT_Renderer
name|renderer
parameter_list|,
name|FT_ULong
name|mode_tag
parameter_list|,
name|FT_Pointer
name|mode_ptr
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* deprecated identifiers */
end_comment
begin_define
DECL|macro|FTRenderer_render
define|#
directive|define
name|FTRenderer_render
value|FT_Renderer_RenderFunc
end_define
begin_define
DECL|macro|FTRenderer_transform
define|#
directive|define
name|FTRenderer_transform
value|FT_Renderer_TransformFunc
end_define
begin_define
DECL|macro|FTRenderer_getCBox
define|#
directive|define
name|FTRenderer_getCBox
value|FT_Renderer_GetCBoxFunc
end_define
begin_define
DECL|macro|FTRenderer_setMode
define|#
directive|define
name|FTRenderer_setMode
value|FT_Renderer_SetModeFunc
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
comment|/*    FT_Renderer_Class                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The renderer module class descriptor.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    root            :: The root @FT_Module_Class fields.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_format    :: The glyph image format this renderer handles.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    render_glyph    :: A method used to render the image that is in a  */
end_comment
begin_comment
comment|/*                       given glyph slot into a bitmap.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    transform_glyph :: A method used to transform the image that is in */
end_comment
begin_comment
comment|/*                       a given glyph slot.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    get_glyph_cbox  :: A method used to access the glyph's cbox.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    set_mode        :: A method used to pass additional parameters.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_class    :: For @FT_GLYPH_FORMAT_OUTLINE renderers only.    */
end_comment
begin_comment
comment|/*                       This is a pointer to its raster's class.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Renderer_Class_
typedef|typedef
struct|struct
name|FT_Renderer_Class_
block|{
DECL|member|root
name|FT_Module_Class
name|root
decl_stmt|;
DECL|member|glyph_format
name|FT_Glyph_Format
name|glyph_format
decl_stmt|;
DECL|member|render_glyph
name|FT_Renderer_RenderFunc
name|render_glyph
decl_stmt|;
DECL|member|transform_glyph
name|FT_Renderer_TransformFunc
name|transform_glyph
decl_stmt|;
DECL|member|get_glyph_cbox
name|FT_Renderer_GetCBoxFunc
name|get_glyph_cbox
decl_stmt|;
DECL|member|set_mode
name|FT_Renderer_SetModeFunc
name|set_mode
decl_stmt|;
DECL|member|raster_class
name|FT_Raster_Funcs
modifier|*
name|raster_class
decl_stmt|;
block|}
DECL|typedef|FT_Renderer_Class
name|FT_Renderer_Class
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
comment|/*    FT_Get_Renderer                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieve the current renderer for a given glyph format.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library :: A handle to the library object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    format  :: The glyph format.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A renderer handle.  0~if none found.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    An error will be returned if a module already exists by that name, */
end_comment
begin_comment
comment|/*    or if the module requires a version of FreeType that is too great. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    To add a new renderer, simply use @FT_Add_Module.  To retrieve a   */
end_comment
begin_comment
comment|/*    renderer by its name, use @FT_Get_Module.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Renderer
argument_list|)
end_macro
begin_macro
name|FT_Get_Renderer
argument_list|(
argument|FT_Library       library
argument_list|,
argument|FT_Glyph_Format  format
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
comment|/*    FT_Set_Renderer                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Set the current renderer to use, and set additional mode.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<InOut>                                                               */
end_comment
begin_comment
comment|/*    library    :: A handle to the library object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    renderer   :: A handle to the renderer object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_params :: The number of additional parameters.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    parameters :: Additional parameters.                               */
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
comment|/*    In case of success, the renderer will be used to convert glyph     */
end_comment
begin_comment
comment|/*    images in the renderer's known format into bitmaps.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This doesn't change the current renderer for other formats.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Currently, only the B/W renderer, if compiled with                 */
end_comment
begin_comment
comment|/*    FT_RASTER_OPTION_ANTI_ALIASING (providing a 5-levels               */
end_comment
begin_comment
comment|/*    anti-aliasing mode; this option must be set directly in            */
end_comment
begin_comment
comment|/*    `ftraster.c' and is undefined by default) accepts a single tag     */
end_comment
begin_comment
comment|/*    `pal5' to set its gray palette as a character string with          */
end_comment
begin_comment
comment|/*    5~elements.  Consequently, the third and fourth argument are zero  */
end_comment
begin_comment
comment|/*    normally.                                                          */
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
DECL|variable|FT_Set_Renderer
name|FT_Set_Renderer
argument_list|(
argument|FT_Library     library
argument_list|,
argument|FT_Renderer    renderer
argument_list|,
argument|FT_UInt        num_params
argument_list|,
argument|FT_Parameter*  parameters
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
comment|/* __FTRENDER_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
