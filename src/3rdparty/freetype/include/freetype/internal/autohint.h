begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  autohint.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    High-level `autohint' module-specific interface (specification).     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2007 by                                     */
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
comment|/* The auto-hinter is used to load and automatically hint glyphs if a    */
end_comment
begin_comment
comment|/* format-specific hinter isn't available.                               */
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
name|__AUTOHINT_H__
end_ifndef
begin_define
DECL|macro|__AUTOHINT_H__
define|#
directive|define
name|__AUTOHINT_H__
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* A small technical note regarding automatic hinting in order to        */
end_comment
begin_comment
comment|/* clarify this module interface.                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* An automatic hinter might compute two kinds of data for a given face: */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* - global hints: Usually some metrics that describe global properties  */
end_comment
begin_comment
comment|/*                 of the face.  It is computed by scanning more or less */
end_comment
begin_comment
comment|/*                 aggressively the glyphs in the face, and thus can be  */
end_comment
begin_comment
comment|/*                 very slow to compute (even if the size of global      */
end_comment
begin_comment
comment|/*                 hints is really small).                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* - glyph hints:  These describe some important features of the glyph   */
end_comment
begin_comment
comment|/*                 outline, as well as how to align them.  They are      */
end_comment
begin_comment
comment|/*                 generally much faster to compute than global hints.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The current FreeType auto-hinter does a pretty good job while         */
end_comment
begin_comment
comment|/* performing fast computations for both global and glyph hints.         */
end_comment
begin_comment
comment|/* However, we might be interested in introducing more complex and       */
end_comment
begin_comment
comment|/* powerful algorithms in the future, like the one described in the John */
end_comment
begin_comment
comment|/* D. Hobby paper, which unfortunately requires a lot more horsepower.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Because a sufficiently sophisticated font management system would     */
end_comment
begin_comment
comment|/* typically implement an LRU cache of opened face objects to reduce     */
end_comment
begin_comment
comment|/* memory usage, it is a good idea to be able to avoid recomputing       */
end_comment
begin_comment
comment|/* global hints every time the same face is re-opened.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* We thus provide the ability to cache global hints outside of the face */
end_comment
begin_comment
comment|/* object, in order to speed up font re-opening time.  Of course, this   */
end_comment
begin_comment
comment|/* feature is purely optional, so most client programs won't even notice */
end_comment
begin_comment
comment|/* it.                                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* I initially thought that it would be a good idea to cache the glyph   */
end_comment
begin_comment
comment|/* hints too.  However, my general idea now is that if you really need   */
end_comment
begin_comment
comment|/* to cache these too, you are simply in need of a new font format,      */
end_comment
begin_comment
comment|/* where all this information could be stored within the font file and   */
end_comment
begin_comment
comment|/* decoded on the fly.                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
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
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_typedef
DECL|typedef|FT_AutoHinter
typedef|typedef
name|struct
name|FT_AutoHinterRec_
modifier|*
name|FT_AutoHinter
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
comment|/*    FT_AutoHinter_GlobalGetFunc                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Retrieves the global hints computed for a given face object the    */
end_comment
begin_comment
comment|/*    resulting data is dissociated from the face and will survive a     */
end_comment
begin_comment
comment|/*    call to FT_Done_Face().  It must be discarded through the API      */
end_comment
begin_comment
comment|/*    FT_AutoHinter_GlobalDoneFunc().                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    hinter        :: A handle to the source auto-hinter.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face          :: A handle to the source face object.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    global_hints  :: A typeless pointer to the global hints.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    global_len    :: The size in bytes of the global hints.            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_AutoHinter_GlobalGetFunc
modifier|*
name|FT_AutoHinter_GlobalGetFunc
function_decl|)
parameter_list|(
name|FT_AutoHinter
name|hinter
parameter_list|,
name|FT_Face
name|face
parameter_list|,
name|void
modifier|*
modifier|*
name|global_hints
parameter_list|,
name|long
modifier|*
name|global_len
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
comment|/*    FT_AutoHinter_GlobalDoneFunc                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Discards the global hints retrieved through                        */
end_comment
begin_comment
comment|/*    FT_AutoHinter_GlobalGetFunc().  This is the only way these hints   */
end_comment
begin_comment
comment|/*    are freed from memory.                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    hinter :: A handle to the auto-hinter module.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    global :: A pointer to retrieved global hints to discard.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_AutoHinter_GlobalDoneFunc
modifier|*
name|FT_AutoHinter_GlobalDoneFunc
function_decl|)
parameter_list|(
name|FT_AutoHinter
name|hinter
parameter_list|,
name|void
modifier|*
name|global
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
comment|/*    FT_AutoHinter_GlobalResetFunc                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used to recompute the global metrics in a given   */
end_comment
begin_comment
comment|/*    font.  This is useful when global font data changes (e.g. Multiple */
end_comment
begin_comment
comment|/*    Masters fonts where blend coordinates change).                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    hinter :: A handle to the source auto-hinter.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face   :: A handle to the face.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_AutoHinter_GlobalResetFunc
modifier|*
name|FT_AutoHinter_GlobalResetFunc
function_decl|)
parameter_list|(
name|FT_AutoHinter
name|hinter
parameter_list|,
name|FT_Face
name|face
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
comment|/*    FT_AutoHinter_GlyphLoadFunc                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This function is used to load, scale, and automatically hint a     */
end_comment
begin_comment
comment|/*    glyph from a given face.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face        :: A handle to the face.                               */
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
comment|/*    load_flags  :: The load flags.                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function is capable of loading composite glyphs by hinting    */
end_comment
begin_comment
comment|/*    each sub-glyph independently (which improves quality).             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    It will call the font driver with FT_Load_Glyph(), with            */
end_comment
begin_comment
comment|/*    FT_LOAD_NO_SCALE set.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_AutoHinter_GlyphLoadFunc
modifier|*
name|FT_AutoHinter_GlyphLoadFunc
function_decl|)
parameter_list|(
name|FT_AutoHinter
name|hinter
parameter_list|,
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
comment|/*    FT_AutoHinter_ServiceRec                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The auto-hinter module's interface.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_AutoHinter_ServiceRec_
typedef|typedef
struct|struct
name|FT_AutoHinter_ServiceRec_
block|{
DECL|member|reset_face
name|FT_AutoHinter_GlobalResetFunc
name|reset_face
decl_stmt|;
DECL|member|get_global_hints
name|FT_AutoHinter_GlobalGetFunc
name|get_global_hints
decl_stmt|;
DECL|member|done_global_hints
name|FT_AutoHinter_GlobalDoneFunc
name|done_global_hints
decl_stmt|;
DECL|member|load_glyph
name|FT_AutoHinter_GlyphLoadFunc
name|load_glyph
decl_stmt|;
block|}
DECL|typedef|FT_AutoHinter_ServiceRec
DECL|typedef|FT_AutoHinter_Service
name|FT_AutoHinter_ServiceRec
operator|,
typedef|*
name|FT_AutoHinter_Service
typedef|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_AUTOHINTER_SERVICE
define|#
directive|define
name|FT_DEFINE_AUTOHINTER_SERVICE
parameter_list|(
name|class_
parameter_list|,
name|reset_face_
parameter_list|,
name|get_global_hints_
parameter_list|, \
name|done_global_hints_
parameter_list|,
name|load_glyph_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                                      \   const FT_AutoHinter_ServiceRec class_ =                                    \   {                                                                          \     reset_face_, get_global_hints_, done_global_hints_, load_glyph_          \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_AUTOHINTER_SERVICE
define|#
directive|define
name|FT_DEFINE_AUTOHINTER_SERVICE
parameter_list|(
name|class_
parameter_list|,
name|reset_face_
parameter_list|,
name|get_global_hints_
parameter_list|, \
name|done_global_hints_
parameter_list|,
name|load_glyph_
parameter_list|)
define|\
value|void                                                                       \   FT_Init_Class_##class_( FT_Library library,                                \                           FT_AutoHinter_ServiceRec* clazz)                   \   {                                                                          \     FT_UNUSED(library);                                                      \     clazz->reset_face = reset_face_;                                         \     clazz->get_global_hints = get_global_hints_;                             \     clazz->done_global_hints = done_global_hints_;                           \     clazz->load_glyph = load_glyph_;                                         \   }
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
comment|/* __AUTOHINT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
