begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftdriver.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType font driver interface (specification).                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2006, 2008 by                         */
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
name|__FTDRIVER_H__
end_ifndef
begin_define
DECL|macro|__FTDRIVER_H__
define|#
directive|define
name|__FTDRIVER_H__
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
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Face_InitFunc
modifier|*
name|FT_Face_InitFunc
function_decl|)
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|FT_Face
name|face
parameter_list|,
name|FT_Int
name|typeface_index
parameter_list|,
name|FT_Int
name|num_params
parameter_list|,
name|FT_Parameter
modifier|*
name|parameters
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Face_DoneFunc
modifier|*
name|FT_Face_DoneFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Size_InitFunc
modifier|*
name|FT_Size_InitFunc
function_decl|)
parameter_list|(
name|FT_Size
name|size
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Size_DoneFunc
modifier|*
name|FT_Size_DoneFunc
function_decl|)
parameter_list|(
name|FT_Size
name|size
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Slot_InitFunc
modifier|*
name|FT_Slot_InitFunc
function_decl|)
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Slot_DoneFunc
modifier|*
name|FT_Slot_DoneFunc
function_decl|)
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Size_RequestFunc
modifier|*
name|FT_Size_RequestFunc
function_decl|)
parameter_list|(
name|FT_Size
name|size
parameter_list|,
name|FT_Size_Request
name|req
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Size_SelectFunc
modifier|*
name|FT_Size_SelectFunc
function_decl|)
parameter_list|(
name|FT_Size
name|size
parameter_list|,
name|FT_ULong
name|size_index
parameter_list|)
function_decl|;
end_typedef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Size_ResetPointsFunc
modifier|*
name|FT_Size_ResetPointsFunc
function_decl|)
parameter_list|(
name|FT_Size
name|size
parameter_list|,
name|FT_F26Dot6
name|char_width
parameter_list|,
name|FT_F26Dot6
name|char_height
parameter_list|,
name|FT_UInt
name|horz_resolution
parameter_list|,
name|FT_UInt
name|vert_resolution
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Size_ResetPixelsFunc
modifier|*
name|FT_Size_ResetPixelsFunc
function_decl|)
parameter_list|(
name|FT_Size
name|size
parameter_list|,
name|FT_UInt
name|pixel_width
parameter_list|,
name|FT_UInt
name|pixel_height
parameter_list|)
function_decl|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Slot_LoadFunc
modifier|*
name|FT_Slot_LoadFunc
function_decl|)
parameter_list|(
name|FT_GlyphSlot
name|slot
parameter_list|,
name|FT_Size
name|size
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Int32
name|load_flags
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FT_CharMap_CharIndexFunc
modifier|*
name|FT_CharMap_CharIndexFunc
function_decl|)
parameter_list|(
name|FT_CharMap
name|charmap
parameter_list|,
name|FT_Long
name|charcode
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Long
function_decl|(
DECL|typedef|FT_CharMap_CharNextFunc
modifier|*
name|FT_CharMap_CharNextFunc
function_decl|)
parameter_list|(
name|FT_CharMap
name|charmap
parameter_list|,
name|FT_Long
name|charcode
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Face_GetKerningFunc
modifier|*
name|FT_Face_GetKerningFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|left_glyph
parameter_list|,
name|FT_UInt
name|right_glyph
parameter_list|,
name|FT_Vector
modifier|*
name|kerning
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Face_AttachFunc
modifier|*
name|FT_Face_AttachFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_Stream
name|stream
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Face_GetAdvancesFunc
modifier|*
name|FT_Face_GetAdvancesFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|first
parameter_list|,
name|FT_UInt
name|count
parameter_list|,
name|FT_Int32
name|flags
parameter_list|,
name|FT_Fixed
modifier|*
name|advances
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
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_Driver_ClassRec                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The font driver class.  This structure mostly contains pointers to */
end_comment
begin_comment
comment|/*    driver methods.                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    root             :: The parent module.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_object_size :: The size of a face object in bytes.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    size_object_size :: The size of a size object in bytes.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    slot_object_size :: The size of a glyph object in bytes.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    init_face        :: The format-specific face constructor.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    done_face        :: The format-specific face destructor.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    init_size        :: The format-specific size constructor.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    done_size        :: The format-specific size destructor.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    init_slot        :: The format-specific slot constructor.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    done_slot        :: The format-specific slot destructor.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_glyph       :: A function handle to load a glyph to a slot.   */
end_comment
begin_comment
comment|/*                        This field is mandatory!                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    get_kerning      :: A function handle to return the unscaled       */
end_comment
begin_comment
comment|/*                        kerning for a given pair of glyphs.  Can be    */
end_comment
begin_comment
comment|/*                        set to 0 if the format doesn't support         */
end_comment
begin_comment
comment|/*                        kerning.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    attach_file      :: This function handle is used to read           */
end_comment
begin_comment
comment|/*                        additional data for a face from another        */
end_comment
begin_comment
comment|/*                        file/stream.  For example, this can be used to */
end_comment
begin_comment
comment|/*                        add data from AFM or PFM files on a Type 1     */
end_comment
begin_comment
comment|/*                        face, or a CIDMap on a CID-keyed face.         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    get_advances     :: A function handle used to return advance       */
end_comment
begin_comment
comment|/*                        widths of `count' glyphs (in font units),      */
end_comment
begin_comment
comment|/*                        starting at `first'.  The `vertical' flag must */
end_comment
begin_comment
comment|/*                        be set to get vertical advance heights.  The   */
end_comment
begin_comment
comment|/*                        `advances' buffer is caller-allocated.         */
end_comment
begin_comment
comment|/*                        Currently not implemented.  The idea of this   */
end_comment
begin_comment
comment|/*                        function is to be able to perform              */
end_comment
begin_comment
comment|/*                        device-independent text layout without loading */
end_comment
begin_comment
comment|/*                        a single glyph image.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    request_size     :: A handle to a function used to request the new */
end_comment
begin_comment
comment|/*                        character size.  Can be set to 0 if the        */
end_comment
begin_comment
comment|/*                        scaling done in the base layer suffices.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    select_size      :: A handle to a function used to select a new    */
end_comment
begin_comment
comment|/*                        fixed size.  It is used only if                */
end_comment
begin_comment
comment|/*                        @FT_FACE_FLAG_FIXED_SIZES is set.  Can be set  */
end_comment
begin_comment
comment|/*                        to 0 if the scaling done in the base layer     */
end_comment
begin_comment
comment|/*                        suffices.                                      */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Most function pointers, with the exception of `load_glyph', can be */
end_comment
begin_comment
comment|/*    set to 0 to indicate a default behaviour.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Driver_ClassRec_
typedef|typedef
struct|struct
name|FT_Driver_ClassRec_
block|{
DECL|member|root
name|FT_Module_Class
name|root
decl_stmt|;
DECL|member|face_object_size
name|FT_Long
name|face_object_size
decl_stmt|;
DECL|member|size_object_size
name|FT_Long
name|size_object_size
decl_stmt|;
DECL|member|slot_object_size
name|FT_Long
name|slot_object_size
decl_stmt|;
DECL|member|init_face
name|FT_Face_InitFunc
name|init_face
decl_stmt|;
DECL|member|done_face
name|FT_Face_DoneFunc
name|done_face
decl_stmt|;
DECL|member|init_size
name|FT_Size_InitFunc
name|init_size
decl_stmt|;
DECL|member|done_size
name|FT_Size_DoneFunc
name|done_size
decl_stmt|;
DECL|member|init_slot
name|FT_Slot_InitFunc
name|init_slot
decl_stmt|;
DECL|member|done_slot
name|FT_Slot_DoneFunc
name|done_slot
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
DECL|member|set_char_sizes
name|FT_Size_ResetPointsFunc
name|set_char_sizes
decl_stmt|;
DECL|member|set_pixel_sizes
name|FT_Size_ResetPixelsFunc
name|set_pixel_sizes
decl_stmt|;
endif|#
directive|endif
comment|/* FT_CONFIG_OPTION_OLD_INTERNALS */
DECL|member|load_glyph
name|FT_Slot_LoadFunc
name|load_glyph
decl_stmt|;
DECL|member|get_kerning
name|FT_Face_GetKerningFunc
name|get_kerning
decl_stmt|;
DECL|member|attach_file
name|FT_Face_AttachFunc
name|attach_file
decl_stmt|;
DECL|member|get_advances
name|FT_Face_GetAdvancesFunc
name|get_advances
decl_stmt|;
comment|/* since version 2.2 */
DECL|member|request_size
name|FT_Size_RequestFunc
name|request_size
decl_stmt|;
DECL|member|select_size
name|FT_Size_SelectFunc
name|select_size
decl_stmt|;
block|}
DECL|typedef|FT_Driver_ClassRec
DECL|typedef|FT_Driver_Class
name|FT_Driver_ClassRec
operator|,
typedef|*
name|FT_Driver_Class
typedef|;
end_typedef
begin_comment
comment|/*    *  The following functions are used as stubs for `set_char_sizes' and    *  `set_pixel_sizes'; the code uses `request_size' and `select_size'    *  functions instead.    *    *  Implementation is in `src/base/ftobjs.c'.    */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ft_stub_set_char_sizes
argument_list|(
argument|FT_Size     size
argument_list|,
argument|FT_F26Dot6  width
argument_list|,
argument|FT_F26Dot6  height
argument_list|,
argument|FT_UInt     horz_res
argument_list|,
argument|FT_UInt     vert_res
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|ft_stub_set_pixel_sizes
name|ft_stub_set_pixel_sizes
argument_list|(
argument|FT_Size  size
argument_list|,
argument|FT_UInt  width
argument_list|,
argument|FT_UInt  height
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
comment|/* FT_CONFIG_OPTION_OLD_INTERNALS */
end_comment
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
comment|/*    FT_DECLARE_DRIVER                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to create a forward declaration of a                          */
end_comment
begin_comment
comment|/*    FT_Driver_ClassRec stract instance.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_DRIVER                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Driver_ClassRec struct.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is defined a Create funtion will need    */
end_comment
begin_comment
comment|/*    to called with a pointer where the allocated stracture is returned.*/
end_comment
begin_comment
comment|/*    And when it is no longer needed a Destroy function needs           */
end_comment
begin_comment
comment|/*    to be called to release that allocation.                           */
end_comment
begin_comment
comment|/*    fcinit.c (ft_create_default_module_classes) already contains       */
end_comment
begin_comment
comment|/*    a mechanism to call these functions for the default modules        */
end_comment
begin_comment
comment|/*    described in ftmodule.h                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Notice that the created Create and Destroy functions call          */
end_comment
begin_comment
comment|/*    pic_init and pic_free function to allow you to manually allocate   */
end_comment
begin_comment
comment|/*    and initialize any additional global data, like module specific    */
end_comment
begin_comment
comment|/*    interface, and put them in the global pic container defined in     */
end_comment
begin_comment
comment|/*    ftpic.h. if you don't need them just implement the functions as    */
end_comment
begin_comment
comment|/*    empty to resolve the link error.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is not defined the struct will be        */
end_comment
begin_comment
comment|/*    allocated in the global scope (or the scope where the macro        */
end_comment
begin_comment
comment|/*    is used).                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
begin_define
DECL|macro|FT_DEFINE_DRIVERS_OLD_INTERNALS
define|#
directive|define
name|FT_DEFINE_DRIVERS_OLD_INTERNALS
parameter_list|(
name|a_
parameter_list|,
name|b_
parameter_list|)
define|\
value|a_, b_,
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_DEFINE_DRIVERS_OLD_INTERNALS
define|#
directive|define
name|FT_DEFINE_DRIVERS_OLD_INTERNALS
parameter_list|(
name|a_
parameter_list|,
name|b_
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|FT_DECLARE_DRIVER
define|#
directive|define
name|FT_DECLARE_DRIVER
parameter_list|(
name|class_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE                  \   const FT_Driver_ClassRec  class_;
end_define
begin_define
DECL|macro|FT_DEFINE_DRIVER
define|#
directive|define
name|FT_DEFINE_DRIVER
parameter_list|(
name|class_
parameter_list|,                                             \
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,          \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|,           \
name|face_object_size_
parameter_list|,
name|size_object_size_
parameter_list|,               \
name|slot_object_size_
parameter_list|,
name|init_face_
parameter_list|,
name|done_face_
parameter_list|,          \
name|init_size_
parameter_list|,
name|done_size_
parameter_list|,
name|init_slot_
parameter_list|,
name|done_slot_
parameter_list|,     \
name|old_set_char_sizes_
parameter_list|,
name|old_set_pixel_sizes_
parameter_list|,          \
name|load_glyph_
parameter_list|,
name|get_kerning_
parameter_list|,
name|attach_file_
parameter_list|,            \
name|get_advances_
parameter_list|,
name|request_size_
parameter_list|,
name|select_size_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                                      \   const FT_Driver_ClassRec class_ =                                          \   {                                                                          \     FT_DEFINE_ROOT_MODULE(flags_,size_,name_,version_,requires_,interface_,  \                           init_,done_,get_interface_)                        \                                                                              \     face_object_size_,                                                       \     size_object_size_,                                                       \     slot_object_size_,                                                       \                                                                              \     init_face_,                                                              \     done_face_,                                                              \                                                                              \     init_size_,                                                              \     done_size_,                                                              \                                                                              \     init_slot_,                                                              \     done_slot_,                                                              \                                                                              \     FT_DEFINE_DRIVERS_OLD_INTERNALS(old_set_char_sizes_, old_set_pixel_sizes_) \                                                                              \     load_glyph_,                                                             \                                                                              \     get_kerning_,                                                            \     attach_file_,                                                            \     get_advances_,                                                           \                                                                              \     request_size_,                                                           \     select_size_                                                             \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
end_ifdef
begin_define
DECL|macro|FT_DEFINE_DRIVERS_OLD_INTERNALS
define|#
directive|define
name|FT_DEFINE_DRIVERS_OLD_INTERNALS
parameter_list|(
name|a_
parameter_list|,
name|b_
parameter_list|)
define|\
value|clazz->set_char_sizes = a_; \   clazz->set_pixel_sizes = b_;
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|FT_DEFINE_DRIVERS_OLD_INTERNALS
define|#
directive|define
name|FT_DEFINE_DRIVERS_OLD_INTERNALS
parameter_list|(
name|a_
parameter_list|,
name|b_
parameter_list|)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|FT_DECLARE_DRIVER
define|#
directive|define
name|FT_DECLARE_DRIVER
parameter_list|(
name|class_
parameter_list|)
value|FT_DECLARE_MODULE(class_)
end_define
begin_define
DECL|macro|FT_DEFINE_DRIVER
define|#
directive|define
name|FT_DEFINE_DRIVER
parameter_list|(
name|class_
parameter_list|,                                             \
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,          \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|,           \
name|face_object_size_
parameter_list|,
name|size_object_size_
parameter_list|,               \
name|slot_object_size_
parameter_list|,
name|init_face_
parameter_list|,
name|done_face_
parameter_list|,          \
name|init_size_
parameter_list|,
name|done_size_
parameter_list|,
name|init_slot_
parameter_list|,
name|done_slot_
parameter_list|,     \
name|old_set_char_sizes_
parameter_list|,
name|old_set_pixel_sizes_
parameter_list|,          \
name|load_glyph_
parameter_list|,
name|get_kerning_
parameter_list|,
name|attach_file_
parameter_list|,            \
name|get_advances_
parameter_list|,
name|request_size_
parameter_list|,
name|select_size_
parameter_list|)
define|\
value|void class_##_pic_free( FT_Library library );                              \   FT_Error class_##_pic_init( FT_Library library );                          \                                                                              \   void                                                                       \   FT_Destroy_Class_##class_( FT_Library        library,                      \                              FT_Module_Class*  clazz )                       \   {                                                                          \     FT_Memory       memory = library->memory;                                \     FT_Driver_Class dclazz = (FT_Driver_Class)clazz;                         \     class_##_pic_free( library );                                            \     if ( dclazz )                                                            \       FT_FREE( dclazz );                                                     \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library        library,                       \                             FT_Module_Class**  output_class )                \   {                                                                          \     FT_Driver_Class  clazz;                                                  \     FT_Error         error;                                                  \     FT_Memory        memory = library->memory;                               \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz) ) )                                 \       return error;                                                          \                                                                              \     error = class_##_pic_init( library );                                    \     if(error)                                                                \     {                                                                        \       FT_FREE( clazz );                                                      \       return error;                                                          \     }                                                                        \                                                                              \     FT_DEFINE_ROOT_MODULE(flags_,size_,name_,version_,requires_,interface_,  \                           init_,done_,get_interface_)                        \                                                                              \     clazz->face_object_size    = face_object_size_;                          \     clazz->size_object_size    = size_object_size_;                          \     clazz->slot_object_size    = slot_object_size_;                          \                                                                              \     clazz->init_face           = init_face_;                                 \     clazz->done_face           = done_face_;                                 \                                                                              \     clazz->init_size           = init_size_;                                 \     clazz->done_size           = done_size_;                                 \                                                                              \     clazz->init_slot           = init_slot_;                                 \     clazz->done_slot           = done_slot_;                                 \                                                                              \     FT_DEFINE_DRIVERS_OLD_INTERNALS(old_set_char_sizes_, old_set_pixel_sizes_) \                                                                              \     clazz->load_glyph          = load_glyph_;                                \                                                                              \     clazz->get_kerning         = get_kerning_;                               \     clazz->attach_file         = attach_file_;                               \     clazz->get_advances        = get_advances_;                              \                                                                              \     clazz->request_size        = request_size_;                              \     clazz->select_size         = select_size_;                               \                                                                              \     *output_class = (FT_Module_Class*)clazz;                                 \     return FT_Err_Ok;                                                        \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTDRIVER_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
