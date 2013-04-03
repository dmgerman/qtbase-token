begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftobjs.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType private base classes (specification).                   */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2001, 2002, 2003, 2004, 2005, 2006, 2008 by             */
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
comment|/*  This file contains the definition of all internal FreeType classes.  */
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
name|__FTOBJS_H__
end_ifndef
begin_define
DECL|macro|__FTOBJS_H__
define|#
directive|define
name|__FTOBJS_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_RENDER_H
end_include
begin_include
include|#
directive|include
include|FT_SIZES_H
end_include
begin_include
include|#
directive|include
include|FT_LCD_FILTER_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_MEMORY_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_GLYPH_LOADER_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DRIVER_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_AUTOHINT_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_SERVICE_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_PIC_H
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_INCREMENTAL
end_ifdef
begin_include
include|#
directive|include
include|FT_INCREMENTAL_H
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* Some generic definitions.                                             */
comment|/*                                                                       */
ifndef|#
directive|ifndef
name|TRUE
DECL|macro|TRUE
define|#
directive|define
name|TRUE
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FALSE
DECL|macro|FALSE
define|#
directive|define
name|FALSE
value|0
endif|#
directive|endif
ifndef|#
directive|ifndef
name|NULL
DECL|macro|NULL
define|#
directive|define
name|NULL
value|(void*)0
endif|#
directive|endif
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/* The min and max functions missing in C.  As usual, be careful not to  */
comment|/* write things like FT_MIN( a++, b++ ) to avoid side effects.           */
comment|/*                                                                       */
DECL|macro|FT_MIN
define|#
directive|define
name|FT_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( (a)< (b) ? (a) : (b) )
DECL|macro|FT_MAX
define|#
directive|define
name|FT_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|( (a)> (b) ? (a) : (b) )
DECL|macro|FT_ABS
define|#
directive|define
name|FT_ABS
parameter_list|(
name|a
parameter_list|)
value|( (a)< 0 ? -(a) : (a) )
DECL|macro|FT_PAD_FLOOR
define|#
directive|define
name|FT_PAD_FLOOR
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|( (x)& ~((n)-1) )
DECL|macro|FT_PAD_ROUND
define|#
directive|define
name|FT_PAD_ROUND
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|FT_PAD_FLOOR( (x) + ((n)/2), n )
DECL|macro|FT_PAD_CEIL
define|#
directive|define
name|FT_PAD_CEIL
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|)
value|FT_PAD_FLOOR( (x) + ((n)-1), n )
DECL|macro|FT_PIX_FLOOR
define|#
directive|define
name|FT_PIX_FLOOR
parameter_list|(
name|x
parameter_list|)
value|( (x)& ~63 )
DECL|macro|FT_PIX_ROUND
define|#
directive|define
name|FT_PIX_ROUND
parameter_list|(
name|x
parameter_list|)
value|FT_PIX_FLOOR( (x) + 32 )
DECL|macro|FT_PIX_CEIL
define|#
directive|define
name|FT_PIX_CEIL
parameter_list|(
name|x
parameter_list|)
value|FT_PIX_FLOOR( (x) + 63 )
comment|/*    *  Return the highest power of 2 that is<= value; this correspond to    *  the highest bit in a given 32-bit value.    */
name|FT_BASE
parameter_list|(
name|FT_UInt32
parameter_list|)
function_decl|ft_highpow2
parameter_list|(
name|FT_UInt32
name|value
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/*    *  character classification functions -- since these are used to parse    *  font files, we must not use those in<ctypes.h> which are    *  locale-dependent    */
end_comment
begin_define
DECL|macro|ft_isdigit
define|#
directive|define
name|ft_isdigit
parameter_list|(
name|x
parameter_list|)
value|( ( (unsigned)(x) - '0' )< 10U )
end_define
begin_define
DECL|macro|ft_isxdigit
define|#
directive|define
name|ft_isxdigit
parameter_list|(
name|x
parameter_list|)
value|( ( (unsigned)(x) - '0' )< 10U || \                              ( (unsigned)(x) - 'a' )< 6U  || \                              ( (unsigned)(x) - 'A' )< 6U  )
end_define
begin_comment
comment|/* the next two macros assume ASCII representation */
end_comment
begin_define
DECL|macro|ft_isupper
define|#
directive|define
name|ft_isupper
parameter_list|(
name|x
parameter_list|)
value|( ( (unsigned)(x) - 'A' )< 26U )
end_define
begin_define
DECL|macro|ft_islower
define|#
directive|define
name|ft_islower
parameter_list|(
name|x
parameter_list|)
value|( ( (unsigned)(x) - 'a' )< 26U )
end_define
begin_define
DECL|macro|ft_isalpha
define|#
directive|define
name|ft_isalpha
parameter_list|(
name|x
parameter_list|)
value|( ft_isupper( x ) || ft_islower( x ) )
end_define
begin_define
DECL|macro|ft_isalnum
define|#
directive|define
name|ft_isalnum
parameter_list|(
name|x
parameter_list|)
value|( ft_isdigit( x ) || ft_isalpha( x ) )
end_define
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                       C H A R M A P S                           ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/* handle to internal charmap object */
end_comment
begin_typedef
DECL|typedef|FT_CMap
typedef|typedef
name|struct
name|FT_CMapRec_
modifier|*
name|FT_CMap
typedef|;
end_typedef
begin_comment
comment|/* handle to charmap class structure */
end_comment
begin_typedef
DECL|typedef|FT_CMap_Class
typedef|typedef
specifier|const
name|struct
name|FT_CMap_ClassRec_
modifier|*
name|FT_CMap_Class
typedef|;
end_typedef
begin_comment
comment|/* internal charmap object structure */
end_comment
begin_typedef
DECL|struct|FT_CMapRec_
typedef|typedef
struct|struct
name|FT_CMapRec_
block|{
DECL|member|charmap
name|FT_CharMapRec
name|charmap
decl_stmt|;
DECL|member|clazz
name|FT_CMap_Class
name|clazz
decl_stmt|;
block|}
DECL|typedef|FT_CMapRec
name|FT_CMapRec
typedef|;
end_typedef
begin_comment
comment|/* typecase any pointer to a charmap handle */
end_comment
begin_define
DECL|macro|FT_CMAP
define|#
directive|define
name|FT_CMAP
parameter_list|(
name|x
parameter_list|)
value|((FT_CMap)( x ))
end_define
begin_comment
comment|/* obvious macros */
end_comment
begin_define
DECL|macro|FT_CMAP_PLATFORM_ID
define|#
directive|define
name|FT_CMAP_PLATFORM_ID
parameter_list|(
name|x
parameter_list|)
value|FT_CMAP( x )->charmap.platform_id
end_define
begin_define
DECL|macro|FT_CMAP_ENCODING_ID
define|#
directive|define
name|FT_CMAP_ENCODING_ID
parameter_list|(
name|x
parameter_list|)
value|FT_CMAP( x )->charmap.encoding_id
end_define
begin_define
DECL|macro|FT_CMAP_ENCODING
define|#
directive|define
name|FT_CMAP_ENCODING
parameter_list|(
name|x
parameter_list|)
value|FT_CMAP( x )->charmap.encoding
end_define
begin_define
DECL|macro|FT_CMAP_FACE
define|#
directive|define
name|FT_CMAP_FACE
parameter_list|(
name|x
parameter_list|)
value|FT_CMAP( x )->charmap.face
end_define
begin_comment
comment|/* class method definitions */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_CMap_InitFunc
modifier|*
name|FT_CMap_InitFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_Pointer
name|init_data
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_CMap_DoneFunc
modifier|*
name|FT_CMap_DoneFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FT_CMap_CharIndexFunc
modifier|*
name|FT_CMap_CharIndexFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_UInt32
name|char_code
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FT_CMap_CharNextFunc
modifier|*
name|FT_CMap_CharNextFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_UInt32
modifier|*
name|achar_code
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FT_CMap_CharVarIndexFunc
modifier|*
name|FT_CMap_CharVarIndexFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_CMap
name|unicode_cmap
parameter_list|,
name|FT_UInt32
name|char_code
parameter_list|,
name|FT_UInt32
name|variant_selector
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_Bool
function_decl|(
DECL|typedef|FT_CMap_CharVarIsDefaultFunc
modifier|*
name|FT_CMap_CharVarIsDefaultFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_UInt32
name|char_code
parameter_list|,
name|FT_UInt32
name|variant_selector
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt32
modifier|*
function_decl|(
DECL|typedef|FT_CMap_VariantListFunc
modifier|*
name|FT_CMap_VariantListFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_Memory
name|mem
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt32
modifier|*
function_decl|(
DECL|typedef|FT_CMap_CharVariantListFunc
modifier|*
name|FT_CMap_CharVariantListFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_Memory
name|mem
parameter_list|,
name|FT_UInt32
name|char_code
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt32
modifier|*
function_decl|(
DECL|typedef|FT_CMap_VariantCharListFunc
modifier|*
name|FT_CMap_VariantCharListFunc
function_decl|)
parameter_list|(
name|FT_CMap
name|cmap
parameter_list|,
name|FT_Memory
name|mem
parameter_list|,
name|FT_UInt32
name|variant_selector
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|struct|FT_CMap_ClassRec_
typedef|typedef
struct|struct
name|FT_CMap_ClassRec_
block|{
DECL|member|size
name|FT_ULong
name|size
decl_stmt|;
DECL|member|init
name|FT_CMap_InitFunc
name|init
decl_stmt|;
DECL|member|done
name|FT_CMap_DoneFunc
name|done
decl_stmt|;
DECL|member|char_index
name|FT_CMap_CharIndexFunc
name|char_index
decl_stmt|;
DECL|member|char_next
name|FT_CMap_CharNextFunc
name|char_next
decl_stmt|;
comment|/* Subsequent entries are special ones for format 14 -- the variant */
comment|/* selector subtable which behaves like no other                    */
DECL|member|char_var_index
name|FT_CMap_CharVarIndexFunc
name|char_var_index
decl_stmt|;
DECL|member|char_var_default
name|FT_CMap_CharVarIsDefaultFunc
name|char_var_default
decl_stmt|;
DECL|member|variant_list
name|FT_CMap_VariantListFunc
name|variant_list
decl_stmt|;
DECL|member|charvariant_list
name|FT_CMap_CharVariantListFunc
name|charvariant_list
decl_stmt|;
DECL|member|variantchar_list
name|FT_CMap_VariantCharListFunc
name|variantchar_list
decl_stmt|;
block|}
DECL|typedef|FT_CMap_ClassRec
name|FT_CMap_ClassRec
typedef|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DECLARE_CMAP_CLASS
define|#
directive|define
name|FT_DECLARE_CMAP_CLASS
parameter_list|(
name|class_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE const FT_CMap_ClassRec class_;
end_define
begin_define
DECL|macro|FT_DEFINE_CMAP_CLASS
define|#
directive|define
name|FT_DEFINE_CMAP_CLASS
parameter_list|(
name|class_
parameter_list|,
name|size_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|char_index_
parameter_list|,       \
name|char_next_
parameter_list|,
name|char_var_index_
parameter_list|,
name|char_var_default_
parameter_list|,
name|variant_list_
parameter_list|,       \
name|charvariant_list_
parameter_list|,
name|variantchar_list_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                                      \   const FT_CMap_ClassRec class_ =                                            \   {                                                                          \     size_, init_, done_, char_index_, char_next_, char_var_index_,           \     char_var_default_, variant_list_, charvariant_list_, variantchar_list_   \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DECLARE_CMAP_CLASS
define|#
directive|define
name|FT_DECLARE_CMAP_CLASS
parameter_list|(
name|class_
parameter_list|)
define|\
value|void FT_Init_Class_##class_( FT_Library library, FT_CMap_ClassRec*  clazz);
end_define
begin_define
DECL|macro|FT_DEFINE_CMAP_CLASS
define|#
directive|define
name|FT_DEFINE_CMAP_CLASS
parameter_list|(
name|class_
parameter_list|,
name|size_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|char_index_
parameter_list|,       \
name|char_next_
parameter_list|,
name|char_var_index_
parameter_list|,
name|char_var_default_
parameter_list|,
name|variant_list_
parameter_list|,       \
name|charvariant_list_
parameter_list|,
name|variantchar_list_
parameter_list|)
define|\
value|void                                                                       \   FT_Init_Class_##class_( FT_Library library,                                \                           FT_CMap_ClassRec*  clazz)                          \   {                                                                          \     FT_UNUSED(library);                                                      \     clazz->size = size_;                                                     \     clazz->init = init_;                                                     \     clazz->done = done_;                                                     \     clazz->char_index = char_index_;                                         \     clazz->char_next = char_next_;                                           \     clazz->char_var_index = char_var_index_;                                 \     clazz->char_var_default = char_var_default_;                             \     clazz->variant_list = variant_list_;                                     \     clazz->charvariant_list = charvariant_list_;                             \     clazz->variantchar_list = variantchar_list_;                             \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_comment
comment|/* create a new charmap and add it to charmap->face */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_CMap_New
argument_list|(
argument|FT_CMap_Class  clazz
argument_list|,
argument|FT_Pointer     init_data
argument_list|,
argument|FT_CharMap     charmap
argument_list|,
argument|FT_CMap       *acmap
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* destroy a charmap and remove it from face's list */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_CMap_Done
name|FT_CMap_Done
argument_list|(
argument|FT_CMap  cmap
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_CMap_Done
empty_stmt|;
end_empty_stmt
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
comment|/*    FT_Face_InternalRec                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure contains the internal fields of each FT_Face        */
end_comment
begin_comment
comment|/*    object.  These fields may change between different releases of     */
end_comment
begin_comment
comment|/*    FreeType.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    max_points ::                                                      */
end_comment
begin_comment
comment|/*      The maximal number of points used to store the vectorial outline */
end_comment
begin_comment
comment|/*      of any glyph in this face.  If this value cannot be known in     */
end_comment
begin_comment
comment|/*      advance, or if the face isn't scalable, this should be set to 0. */
end_comment
begin_comment
comment|/*      Only relevant for scalable formats.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    max_contours ::                                                    */
end_comment
begin_comment
comment|/*      The maximal number of contours used to store the vectorial       */
end_comment
begin_comment
comment|/*      outline of any glyph in this face.  If this value cannot be      */
end_comment
begin_comment
comment|/*      known in advance, or if the face isn't scalable, this should be  */
end_comment
begin_comment
comment|/*      set to 0.  Only relevant for scalable formats.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    transform_matrix ::                                                */
end_comment
begin_comment
comment|/*      A 2x2 matrix of 16.16 coefficients used to transform glyph       */
end_comment
begin_comment
comment|/*      outlines after they are loaded from the font.  Only used by the  */
end_comment
begin_comment
comment|/*      convenience functions.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    transform_delta ::                                                 */
end_comment
begin_comment
comment|/*      A translation vector used to transform glyph outlines after they */
end_comment
begin_comment
comment|/*      are loaded from the font.  Only used by the convenience          */
end_comment
begin_comment
comment|/*      functions.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    transform_flags ::                                                 */
end_comment
begin_comment
comment|/*      Some flags used to classify the transform.  Only used by the     */
end_comment
begin_comment
comment|/*      convenience functions.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    services ::                                                        */
end_comment
begin_comment
comment|/*      A cache for frequently used services.  It should be only         */
end_comment
begin_comment
comment|/*      accessed with the macro `FT_FACE_LOOKUP_SERVICE'.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    incremental_interface ::                                           */
end_comment
begin_comment
comment|/*      If non-null, the interface through which glyph data and metrics  */
end_comment
begin_comment
comment|/*      are loaded incrementally for faces that do not provide all of    */
end_comment
begin_comment
comment|/*      this data when first opened.  This field exists only if          */
end_comment
begin_comment
comment|/*      @FT_CONFIG_OPTION_INCREMENTAL is defined.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ignore_unpatented_hinter ::                                        */
end_comment
begin_comment
comment|/*      This boolean flag instructs the glyph loader to ignore the       */
end_comment
begin_comment
comment|/*      native font hinter, if one is found.  This is exclusively used   */
end_comment
begin_comment
comment|/*      in the case when the unpatented hinter is compiled within the    */
end_comment
begin_comment
comment|/*      library.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_Face_InternalRec_
typedef|typedef
struct|struct
name|FT_Face_InternalRec_
block|{
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_OLD_INTERNALS
DECL|member|reserved1
name|FT_UShort
name|reserved1
decl_stmt|;
DECL|member|reserved2
name|FT_Short
name|reserved2
decl_stmt|;
endif|#
directive|endif
DECL|member|transform_matrix
name|FT_Matrix
name|transform_matrix
decl_stmt|;
DECL|member|transform_delta
name|FT_Vector
name|transform_delta
decl_stmt|;
DECL|member|transform_flags
name|FT_Int
name|transform_flags
decl_stmt|;
DECL|member|services
name|FT_ServiceCacheRec
name|services
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_INCREMENTAL
DECL|member|incremental_interface
name|FT_Incremental_InterfaceRec
modifier|*
name|incremental_interface
decl_stmt|;
endif|#
directive|endif
DECL|member|ignore_unpatented_hinter
name|FT_Bool
name|ignore_unpatented_hinter
decl_stmt|;
block|}
DECL|typedef|FT_Face_InternalRec
name|FT_Face_InternalRec
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
comment|/*    FT_Slot_InternalRec                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure contains the internal fields of each FT_GlyphSlot   */
end_comment
begin_comment
comment|/*    object.  These fields may change between different releases of     */
end_comment
begin_comment
comment|/*    FreeType.                                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    loader            :: The glyph loader object used to load outlines */
end_comment
begin_comment
comment|/*                         into the glyph slot.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    flags             :: Possible values are zero or                   */
end_comment
begin_comment
comment|/*                         FT_GLYPH_OWN_BITMAP.  The latter indicates    */
end_comment
begin_comment
comment|/*                         that the FT_GlyphSlot structure owns the      */
end_comment
begin_comment
comment|/*                         bitmap buffer.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_transformed :: Boolean.  Set to TRUE when the loaded glyph   */
end_comment
begin_comment
comment|/*                         must be transformed through a specific        */
end_comment
begin_comment
comment|/*                         font transformation.  This is _not_ the same  */
end_comment
begin_comment
comment|/*                         as the face transform set through             */
end_comment
begin_comment
comment|/*                         FT_Set_Transform().                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_matrix      :: The 2x2 matrix corresponding to the glyph     */
end_comment
begin_comment
comment|/*                         transformation, if necessary.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_delta       :: The 2d translation vector corresponding to    */
end_comment
begin_comment
comment|/*                         the glyph transformation, if necessary.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_hints       :: Format-specific glyph hints management.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_GLYPH_OWN_BITMAP
define|#
directive|define
name|FT_GLYPH_OWN_BITMAP
value|0x1
end_define
begin_typedef
DECL|struct|FT_Slot_InternalRec_
typedef|typedef
struct|struct
name|FT_Slot_InternalRec_
block|{
DECL|member|loader
name|FT_GlyphLoader
name|loader
decl_stmt|;
DECL|member|flags
name|FT_UInt
name|flags
decl_stmt|;
DECL|member|glyph_transformed
name|FT_Bool
name|glyph_transformed
decl_stmt|;
DECL|member|glyph_matrix
name|FT_Matrix
name|glyph_matrix
decl_stmt|;
DECL|member|glyph_delta
name|FT_Vector
name|glyph_delta
decl_stmt|;
DECL|member|glyph_hints
name|void
modifier|*
name|glyph_hints
decl_stmt|;
block|}
DECL|typedef|FT_GlyphSlot_InternalRec
name|FT_GlyphSlot_InternalRec
typedef|;
end_typedef
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
comment|/*<Struct>                                                              */
end_comment
begin_comment
comment|/*    FT_Size_InternalRec                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure contains the internal fields of each FT_Size        */
end_comment
begin_comment
comment|/*    object.  Currently, it's empty.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
unit|typedef struct  FT_Size_InternalRec_   {
comment|/* empty */
end_comment
begin_endif
unit|} FT_Size_InternalRec;
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                         M O D U L E S                           ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/*    FT_ModuleRec                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A module object instance.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    clazz   :: A pointer to the module's class.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    library :: A handle to the parent library object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    memory  :: A handle to the memory manager.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    generic :: A generic structure for user-level extensibility (?).   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_ModuleRec_
typedef|typedef
struct|struct
name|FT_ModuleRec_
block|{
DECL|member|clazz
name|FT_Module_Class
modifier|*
name|clazz
decl_stmt|;
DECL|member|library
name|FT_Library
name|library
decl_stmt|;
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
DECL|member|generic
name|FT_Generic
name|generic
decl_stmt|;
block|}
DECL|typedef|FT_ModuleRec
name|FT_ModuleRec
typedef|;
end_typedef
begin_comment
comment|/* typecast an object to a FT_Module */
end_comment
begin_define
DECL|macro|FT_MODULE
define|#
directive|define
name|FT_MODULE
parameter_list|(
name|x
parameter_list|)
value|((FT_Module)( x ))
end_define
begin_define
DECL|macro|FT_MODULE_CLASS
define|#
directive|define
name|FT_MODULE_CLASS
parameter_list|(
name|x
parameter_list|)
value|FT_MODULE( x )->clazz
end_define
begin_define
DECL|macro|FT_MODULE_LIBRARY
define|#
directive|define
name|FT_MODULE_LIBRARY
parameter_list|(
name|x
parameter_list|)
value|FT_MODULE( x )->library
end_define
begin_define
DECL|macro|FT_MODULE_MEMORY
define|#
directive|define
name|FT_MODULE_MEMORY
parameter_list|(
name|x
parameter_list|)
value|FT_MODULE( x )->memory
end_define
begin_define
DECL|macro|FT_MODULE_IS_DRIVER
define|#
directive|define
name|FT_MODULE_IS_DRIVER
parameter_list|(
name|x
parameter_list|)
value|( FT_MODULE_CLASS( x )->module_flags& \                                     FT_MODULE_FONT_DRIVER )
end_define
begin_define
DECL|macro|FT_MODULE_IS_RENDERER
define|#
directive|define
name|FT_MODULE_IS_RENDERER
parameter_list|(
name|x
parameter_list|)
value|( FT_MODULE_CLASS( x )->module_flags& \                                       FT_MODULE_RENDERER )
end_define
begin_define
DECL|macro|FT_MODULE_IS_HINTER
define|#
directive|define
name|FT_MODULE_IS_HINTER
parameter_list|(
name|x
parameter_list|)
value|( FT_MODULE_CLASS( x )->module_flags& \                                     FT_MODULE_HINTER )
end_define
begin_define
DECL|macro|FT_MODULE_IS_STYLER
define|#
directive|define
name|FT_MODULE_IS_STYLER
parameter_list|(
name|x
parameter_list|)
value|( FT_MODULE_CLASS( x )->module_flags& \                                     FT_MODULE_STYLER )
end_define
begin_define
DECL|macro|FT_DRIVER_IS_SCALABLE
define|#
directive|define
name|FT_DRIVER_IS_SCALABLE
parameter_list|(
name|x
parameter_list|)
value|( FT_MODULE_CLASS( x )->module_flags& \                                       FT_MODULE_DRIVER_SCALABLE )
end_define
begin_define
DECL|macro|FT_DRIVER_USES_OUTLINES
define|#
directive|define
name|FT_DRIVER_USES_OUTLINES
parameter_list|(
name|x
parameter_list|)
value|!( FT_MODULE_CLASS( x )->module_flags& \                                          FT_MODULE_DRIVER_NO_OUTLINES )
end_define
begin_define
DECL|macro|FT_DRIVER_HAS_HINTER
define|#
directive|define
name|FT_DRIVER_HAS_HINTER
parameter_list|(
name|x
parameter_list|)
value|( FT_MODULE_CLASS( x )->module_flags& \                                      FT_MODULE_DRIVER_HAS_HINTER )
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
comment|/*    FT_Get_Module_Interface                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Finds a module and returns its specific interface as a typeless    */
end_comment
begin_comment
comment|/*    pointer.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    library     :: A handle to the library object.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    module_name :: The module's name (as an ASCII string).             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A module-specific interface if available, 0 otherwise.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    You should better be familiar with FreeType internals to know      */
end_comment
begin_comment
comment|/*    which module to look for, and what its interface is :-)            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|const void*
argument_list|)
end_macro
begin_macro
name|FT_Get_Module_Interface
argument_list|(
argument|FT_Library   library
argument_list|,
argument|const char*  mod_name
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
name|ft_module_get_service
argument_list|(
argument|FT_Module    module
argument_list|,
argument|const char*  service_id
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****               FACE, SIZE& GLYPH SLOT OBJECTS                   ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/* a few macros used to perform easy typecasts with minimal brain damage */
end_comment
begin_define
DECL|macro|FT_FACE
define|#
directive|define
name|FT_FACE
parameter_list|(
name|x
parameter_list|)
value|((FT_Face)(x))
end_define
begin_define
DECL|macro|FT_SIZE
define|#
directive|define
name|FT_SIZE
parameter_list|(
name|x
parameter_list|)
value|((FT_Size)(x))
end_define
begin_define
DECL|macro|FT_SLOT
define|#
directive|define
name|FT_SLOT
parameter_list|(
name|x
parameter_list|)
value|((FT_GlyphSlot)(x))
end_define
begin_define
DECL|macro|FT_FACE_DRIVER
define|#
directive|define
name|FT_FACE_DRIVER
parameter_list|(
name|x
parameter_list|)
value|FT_FACE( x )->driver
end_define
begin_define
DECL|macro|FT_FACE_LIBRARY
define|#
directive|define
name|FT_FACE_LIBRARY
parameter_list|(
name|x
parameter_list|)
value|FT_FACE_DRIVER( x )->root.library
end_define
begin_define
DECL|macro|FT_FACE_MEMORY
define|#
directive|define
name|FT_FACE_MEMORY
parameter_list|(
name|x
parameter_list|)
value|FT_FACE( x )->memory
end_define
begin_define
DECL|macro|FT_FACE_STREAM
define|#
directive|define
name|FT_FACE_STREAM
parameter_list|(
name|x
parameter_list|)
value|FT_FACE( x )->stream
end_define
begin_define
DECL|macro|FT_SIZE_FACE
define|#
directive|define
name|FT_SIZE_FACE
parameter_list|(
name|x
parameter_list|)
value|FT_SIZE( x )->face
end_define
begin_define
DECL|macro|FT_SLOT_FACE
define|#
directive|define
name|FT_SLOT_FACE
parameter_list|(
name|x
parameter_list|)
value|FT_SLOT( x )->face
end_define
begin_define
DECL|macro|FT_FACE_SLOT
define|#
directive|define
name|FT_FACE_SLOT
parameter_list|(
name|x
parameter_list|)
value|FT_FACE( x )->glyph
end_define
begin_define
DECL|macro|FT_FACE_SIZE
define|#
directive|define
name|FT_FACE_SIZE
parameter_list|(
name|x
parameter_list|)
value|FT_FACE( x )->size
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
comment|/*    FT_New_GlyphSlot                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    It is sometimes useful to have more than one glyph slot for a      */
end_comment
begin_comment
comment|/*    given face object.  This function is used to create additional     */
end_comment
begin_comment
comment|/*    slots.  All of them are automatically discarded when the face is   */
end_comment
begin_comment
comment|/*    destroyed.                                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face  :: A handle to a parent face object.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    aslot :: A handle to a new glyph slot object.                      */
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
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_New_GlyphSlot
name|FT_New_GlyphSlot
argument_list|(
argument|FT_Face        face
argument_list|,
argument|FT_GlyphSlot  *aslot
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
comment|/*    FT_Done_GlyphSlot                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Destroys a given glyph slot.  Remember however that all slots are  */
end_comment
begin_comment
comment|/*    automatically destroyed with its parent.  Using this function is   */
end_comment
begin_comment
comment|/*    not always mandatory.                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    slot :: A handle to a target glyph slot.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|slot
name|FT_Done_GlyphSlot
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|slot
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* */
end_comment
begin_define
DECL|macro|FT_REQUEST_WIDTH
define|#
directive|define
name|FT_REQUEST_WIDTH
parameter_list|(
name|req
parameter_list|)
define|\
value|( (req)->horiResolution                                          \               ? (FT_Pos)( (req)->width * (req)->horiResolution + 36 ) / 72 \               : (req)->width )
end_define
begin_define
DECL|macro|FT_REQUEST_HEIGHT
define|#
directive|define
name|FT_REQUEST_HEIGHT
parameter_list|(
name|req
parameter_list|)
define|\
value|( (req)->vertResolution                                           \               ? (FT_Pos)( (req)->height * (req)->vertResolution + 36 ) / 72 \               : (req)->height )
end_define
begin_comment
comment|/* Set the metrics according to a bitmap strike. */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Select_Metrics
argument_list|(
argument|FT_Face   face
argument_list|,
argument|FT_ULong  strike_index
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Set the metrics according to a size request. */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|FT_Request_Metrics
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
comment|/* Match a size request against `available_sizes'. */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|FT_Match_Size
argument_list|(
argument|FT_Face          face
argument_list|,
argument|FT_Size_Request  req
argument_list|,
argument|FT_Bool          ignore_width
argument_list|,
argument|FT_ULong*        size_index
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Use the horizontal metrics to synthesize the vertical metrics. */
end_comment
begin_comment
comment|/* If `advance' is zero, it is also synthesized.                  */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|ft_synthesize_vertical_metrics
name|ft_synthesize_vertical_metrics
argument_list|(
argument|FT_Glyph_Metrics*  metrics
argument_list|,
argument|FT_Pos             advance
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Free the bitmap of a given glyphslot when needed (i.e., only when it */
end_comment
begin_comment
comment|/* was allocated with ft_glyphslot_alloc_bitmap).                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|slot
name|ft_glyphslot_free_bitmap
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|slot
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Allocate a new bitmap buffer in a glyph slot. */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
name|ft_glyphslot_alloc_bitmap
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|,
argument|FT_ULong      size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/* Set the bitmap buffer in a glyph slot to a given pointer.  The buffer */
end_comment
begin_comment
comment|/* will not be freed by a later call to ft_glyphslot_free_bitmap.        */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|ft_glyphslot_set_bitmap
name|ft_glyphslot_set_bitmap
argument_list|(
argument|FT_GlyphSlot  slot
argument_list|,
argument|FT_Byte*      buffer
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                        R E N D E R E R S                        ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
begin_define
DECL|macro|FT_RENDERER
define|#
directive|define
name|FT_RENDERER
parameter_list|(
name|x
parameter_list|)
value|((FT_Renderer)( x ))
end_define
begin_define
DECL|macro|FT_GLYPH
define|#
directive|define
name|FT_GLYPH
parameter_list|(
name|x
parameter_list|)
value|((FT_Glyph)( x ))
end_define
begin_define
DECL|macro|FT_BITMAP_GLYPH
define|#
directive|define
name|FT_BITMAP_GLYPH
parameter_list|(
name|x
parameter_list|)
value|((FT_BitmapGlyph)( x ))
end_define
begin_define
DECL|macro|FT_OUTLINE_GLYPH
define|#
directive|define
name|FT_OUTLINE_GLYPH
parameter_list|(
name|x
parameter_list|)
value|((FT_OutlineGlyph)( x ))
end_define
begin_typedef
DECL|struct|FT_RendererRec_
typedef|typedef
struct|struct
name|FT_RendererRec_
block|{
DECL|member|root
name|FT_ModuleRec
name|root
decl_stmt|;
DECL|member|clazz
name|FT_Renderer_Class
modifier|*
name|clazz
decl_stmt|;
DECL|member|glyph_format
name|FT_Glyph_Format
name|glyph_format
decl_stmt|;
DECL|member|glyph_class
name|FT_Glyph_Class
name|glyph_class
decl_stmt|;
DECL|member|raster
name|FT_Raster
name|raster
decl_stmt|;
DECL|member|raster_render
name|FT_Raster_Render_Func
name|raster_render
decl_stmt|;
DECL|member|render
name|FT_Renderer_RenderFunc
name|render
decl_stmt|;
block|}
DECL|typedef|FT_RendererRec
name|FT_RendererRec
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                    F O N T   D R I V E R S                      ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/* typecast a module into a driver easily */
end_comment
begin_define
DECL|macro|FT_DRIVER
define|#
directive|define
name|FT_DRIVER
parameter_list|(
name|x
parameter_list|)
value|((FT_Driver)(x))
end_define
begin_comment
comment|/* typecast a module as a driver, and get its driver class */
end_comment
begin_define
DECL|macro|FT_DRIVER_CLASS
define|#
directive|define
name|FT_DRIVER_CLASS
parameter_list|(
name|x
parameter_list|)
value|FT_DRIVER( x )->clazz
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
comment|/*    FT_DriverRec                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The root font driver class.  A font driver is responsible for      */
end_comment
begin_comment
comment|/*    managing and loading font files of a given format.                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                             */
end_comment
begin_comment
comment|/*     root         :: Contains the fields of the root module class.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     clazz        :: A pointer to the font driver's class.  Note that  */
end_comment
begin_comment
comment|/*                     this is NOT root.clazz.  `class' wasn't used      */
end_comment
begin_comment
comment|/*                     as it is a reserved word in C++.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     faces_list   :: The list of faces currently opened by this        */
end_comment
begin_comment
comment|/*                     driver.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     extensions   :: A typeless pointer to the driver's extensions     */
end_comment
begin_comment
comment|/*                     registry, if they are supported through the       */
end_comment
begin_comment
comment|/*                     configuration macro FT_CONFIG_OPTION_EXTENSIONS.  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*     glyph_loader :: The glyph loader for all faces managed by this    */
end_comment
begin_comment
comment|/*                     driver.  This object isn't defined for unscalable */
end_comment
begin_comment
comment|/*                     formats.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_DriverRec_
typedef|typedef
struct|struct
name|FT_DriverRec_
block|{
DECL|member|root
name|FT_ModuleRec
name|root
decl_stmt|;
DECL|member|clazz
name|FT_Driver_Class
name|clazz
decl_stmt|;
DECL|member|faces_list
name|FT_ListRec
name|faces_list
decl_stmt|;
DECL|member|extensions
name|void
modifier|*
name|extensions
decl_stmt|;
DECL|member|glyph_loader
name|FT_GlyphLoader
name|glyph_loader
decl_stmt|;
block|}
DECL|typedef|FT_DriverRec
name|FT_DriverRec
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                       L I B R A R I E S                         ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/* This hook is used by the TrueType debugger.  It must be set to an */
end_comment
begin_comment
comment|/* alternate truetype bytecode interpreter function.                 */
end_comment
begin_define
DECL|macro|FT_DEBUG_HOOK_TRUETYPE
define|#
directive|define
name|FT_DEBUG_HOOK_TRUETYPE
value|0
end_define
begin_comment
comment|/* Set this debug hook to a non-null pointer to force unpatented hinting */
end_comment
begin_comment
comment|/* for all faces when both TT_USE_BYTECODE_INTERPRETER and               */
end_comment
begin_comment
comment|/* TT_CONFIG_OPTION_UNPATENTED_HINTING are defined.  This is only used   */
end_comment
begin_comment
comment|/* during debugging.                                                     */
end_comment
begin_define
DECL|macro|FT_DEBUG_HOOK_UNPATENTED_HINTING
define|#
directive|define
name|FT_DEBUG_HOOK_UNPATENTED_HINTING
value|1
end_define
begin_typedef
DECL|typedef|FT_Bitmap_LcdFilterFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|FT_Bitmap_LcdFilterFunc
function_decl|)
parameter_list|(
name|FT_Bitmap
modifier|*
name|bitmap
parameter_list|,
name|FT_Render_Mode
name|render_mode
parameter_list|,
name|FT_Library
name|library
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
comment|/*    FT_LibraryRec                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    The FreeType library class.  This is the root of all FreeType      */
end_comment
begin_comment
comment|/*    data.  Use FT_New_Library() to create a library object, and        */
end_comment
begin_comment
comment|/*    FT_Done_Library() to discard it and all child objects.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    memory           :: The library's memory object.  Manages memory   */
end_comment
begin_comment
comment|/*                        allocation.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    generic          :: Client data variable.  Used to extend the      */
end_comment
begin_comment
comment|/*                        Library class by higher levels and clients.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    version_major    :: The major version number of the library.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    version_minor    :: The minor version number of the library.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    version_patch    :: The current patch level of the library.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    num_modules      :: The number of modules currently registered     */
end_comment
begin_comment
comment|/*                        within this library.  This is set to 0 for new */
end_comment
begin_comment
comment|/*                        libraries.  New modules are added through the  */
end_comment
begin_comment
comment|/*                        FT_Add_Module() API function.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    modules          :: A table used to store handles to the currently */
end_comment
begin_comment
comment|/*                        registered modules. Note that each font driver */
end_comment
begin_comment
comment|/*                        contains a list of its opened faces.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    renderers        :: The list of renderers currently registered     */
end_comment
begin_comment
comment|/*                        within the library.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    cur_renderer     :: The current outline renderer.  This is a       */
end_comment
begin_comment
comment|/*                        shortcut used to avoid parsing the list on     */
end_comment
begin_comment
comment|/*                        each call to FT_Outline_Render().  It is a     */
end_comment
begin_comment
comment|/*                        handle to the current renderer for the         */
end_comment
begin_comment
comment|/*                        FT_GLYPH_FORMAT_OUTLINE format.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    auto_hinter      :: XXX                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_pool      :: The raster object's render pool.  This can     */
end_comment
begin_comment
comment|/*                        ideally be changed dynamically at run-time.    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    raster_pool_size :: The size of the render pool in bytes.          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    debug_hooks      :: XXX                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    pic_container    :: Contains global structs and tables, instead    */
end_comment
begin_comment
comment|/*                        of defining them globallly.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|FT_LibraryRec_
typedef|typedef
struct|struct
name|FT_LibraryRec_
block|{
DECL|member|memory
name|FT_Memory
name|memory
decl_stmt|;
comment|/* library's memory manager */
DECL|member|generic
name|FT_Generic
name|generic
decl_stmt|;
DECL|member|version_major
name|FT_Int
name|version_major
decl_stmt|;
DECL|member|version_minor
name|FT_Int
name|version_minor
decl_stmt|;
DECL|member|version_patch
name|FT_Int
name|version_patch
decl_stmt|;
DECL|member|num_modules
name|FT_UInt
name|num_modules
decl_stmt|;
DECL|member|modules
name|FT_Module
name|modules
index|[
name|FT_MAX_MODULES
index|]
decl_stmt|;
comment|/* module objects  */
DECL|member|renderers
name|FT_ListRec
name|renderers
decl_stmt|;
comment|/* list of renderers        */
DECL|member|cur_renderer
name|FT_Renderer
name|cur_renderer
decl_stmt|;
comment|/* current outline renderer */
DECL|member|auto_hinter
name|FT_Module
name|auto_hinter
decl_stmt|;
DECL|member|raster_pool
name|FT_Byte
modifier|*
name|raster_pool
decl_stmt|;
comment|/* scan-line conversion */
comment|/* render pool          */
DECL|member|raster_pool_size
name|FT_ULong
name|raster_pool_size
decl_stmt|;
comment|/* size of render pool in bytes */
DECL|member|debug_hooks
name|FT_DebugHook_Func
name|debug_hooks
index|[
literal|4
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_SUBPIXEL_RENDERING
DECL|member|lcd_filter
name|FT_LcdFilter
name|lcd_filter
decl_stmt|;
DECL|member|lcd_extra
name|FT_Int
name|lcd_extra
decl_stmt|;
comment|/* number of extra pixels */
DECL|member|lcd_weights
name|FT_Byte
name|lcd_weights
index|[
literal|7
index|]
decl_stmt|;
comment|/* filter weights, if any */
DECL|member|lcd_filter_func
name|FT_Bitmap_LcdFilterFunc
name|lcd_filter_func
decl_stmt|;
comment|/* filtering callback     */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
DECL|member|pic_container
name|FT_PIC_Container
name|pic_container
decl_stmt|;
endif|#
directive|endif
block|}
DECL|typedef|FT_LibraryRec
name|FT_LibraryRec
typedef|;
end_typedef
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Renderer
argument_list|)
end_macro
begin_macro
name|FT_Lookup_Renderer
argument_list|(
argument|FT_Library       library
argument_list|,
argument|FT_Glyph_Format  format
argument_list|,
argument|FT_ListNode*     node
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
DECL|variable|FT_Render_Glyph_Internal
name|FT_Render_Glyph_Internal
argument_list|(
argument|FT_Library      library
argument_list|,
argument|FT_GlyphSlot    slot
argument_list|,
argument|FT_Render_Mode  render_mode
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_typedef
typedef|typedef
specifier|const
name|char
modifier|*
function_decl|(
DECL|typedef|FT_Face_GetPostscriptNameFunc
modifier|*
name|FT_Face_GetPostscriptNameFunc
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
DECL|typedef|FT_Face_GetGlyphNameFunc
modifier|*
name|FT_Face_GetGlyphNameFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Pointer
name|buffer
parameter_list|,
name|FT_UInt
name|buffer_max
parameter_list|)
function_decl|;
end_typedef
begin_typedef
typedef|typedef
name|FT_UInt
function_decl|(
DECL|typedef|FT_Face_GetGlyphNameIndexFunc
modifier|*
name|FT_Face_GetGlyphNameIndexFunc
function_decl|)
parameter_list|(
name|FT_Face
name|face
parameter_list|,
name|FT_String
modifier|*
name|glyph_name
parameter_list|)
function_decl|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_NO_DEFAULT_SYSTEM
end_ifndef
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
comment|/*    FT_New_Memory                                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Creates a new memory object.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    A pointer to the new memory object.  0 in case of error.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Memory
argument_list|)
end_macro
begin_expr_stmt
name|FT_New_Memory
argument_list|(
name|void
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
comment|/*    FT_Done_Memory                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Discards memory manager.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory :: A handle to the memory manager.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Done_Memory
name|FT_Done_Memory
argument_list|(
argument|FT_Memory  memory
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Done_Memory
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_CONFIG_OPTION_NO_DEFAULT_SYSTEM */
end_comment
begin_comment
comment|/* Define default raster's interface.  The default raster is located in  */
end_comment
begin_comment
comment|/* `src/base/ftraster.c'.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Client applications can register new rasters through the              */
end_comment
begin_comment
comment|/* FT_Set_Raster() API.                                                  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_NO_DEFAULT_RASTER
end_ifndef
begin_macro
name|FT_EXPORT_VAR
argument_list|(
argument|FT_Raster_Funcs
argument_list|)
end_macro
begin_expr_stmt
name|ft_default_raster
expr_stmt|;
end_expr_stmt
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****              PIC-Support Macros for ftimage.h                   ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_OUTLINE_FUNCS                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Outline_Funcs struct.         */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is defined an init funtion will need to  */
end_comment
begin_comment
comment|/*    called with a pre-allocated stracture to be filled.                */
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
begin_define
DECL|macro|FT_DEFINE_OUTLINE_FUNCS
define|#
directive|define
name|FT_DEFINE_OUTLINE_FUNCS
parameter_list|(
name|class_
parameter_list|,
name|move_to_
parameter_list|,
name|line_to_
parameter_list|,
name|conic_to_
parameter_list|,       \
name|cubic_to_
parameter_list|,
name|shift_
parameter_list|,
name|delta_
parameter_list|)
define|\
value|static const FT_Outline_Funcs class_ =                                     \   {                                                                          \     move_to_, line_to_, conic_to_, cubic_to_, shift_, delta_                 \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_OUTLINE_FUNCS
define|#
directive|define
name|FT_DEFINE_OUTLINE_FUNCS
parameter_list|(
name|class_
parameter_list|,
name|move_to_
parameter_list|,
name|line_to_
parameter_list|,
name|conic_to_
parameter_list|,       \
name|cubic_to_
parameter_list|,
name|shift_
parameter_list|,
name|delta_
parameter_list|)
define|\
value|static FT_Error                                                            \   Init_Class_##class_( FT_Outline_Funcs*  clazz )                            \   {                                                                          \     clazz->move_to = move_to_;                                               \     clazz->line_to = line_to_;                                               \     clazz->conic_to = conic_to_;                                             \     clazz->cubic_to = cubic_to_;                                             \     clazz->shift = shift_;                                                   \     clazz->delta = delta_;                                                   \     return FT_Err_Ok;                                                        \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
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
comment|/*    FT_DEFINE_RASTER_FUNCS                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Raster_Funcs struct.          */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is defined an init funtion will need to  */
end_comment
begin_comment
comment|/*    called with a pre-allocated stracture to be filled.                */
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
begin_define
DECL|macro|FT_DEFINE_RASTER_FUNCS
define|#
directive|define
name|FT_DEFINE_RASTER_FUNCS
parameter_list|(
name|class_
parameter_list|,
name|glyph_format_
parameter_list|,
name|raster_new_
parameter_list|,           \
name|raster_reset_
parameter_list|,
name|raster_set_mode_
parameter_list|,              \
name|raster_render_
parameter_list|,
name|raster_done_
parameter_list|)
define|\
value|const FT_Raster_Funcs class_ =                                      \   {                                                                          \     glyph_format_, raster_new_, raster_reset_,                               \     raster_set_mode_, raster_render_, raster_done_                           \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_RASTER_FUNCS
define|#
directive|define
name|FT_DEFINE_RASTER_FUNCS
parameter_list|(
name|class_
parameter_list|,
name|glyph_format_
parameter_list|,
name|raster_new_
parameter_list|,           \
name|raster_reset_
parameter_list|,
name|raster_set_mode_
parameter_list|,
name|raster_render_
parameter_list|,
name|raster_done_
parameter_list|)
define|\
value|void                                                                       \   FT_Init_Class_##class_( FT_Raster_Funcs*  clazz )                          \   {                                                                          \     clazz->glyph_format = glyph_format_;                                     \     clazz->raster_new = raster_new_;                                         \     clazz->raster_reset = raster_reset_;                                     \     clazz->raster_set_mode = raster_set_mode_;                               \     clazz->raster_render = raster_render_;                                   \     clazz->raster_done = raster_done_;                                       \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****              PIC-Support Macros for ftrender.h                  ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_GLYPH                                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Glyph_Class struct.           */
end_comment
begin_comment
comment|/*    When FT_CONFIG_OPTION_PIC is defined an init funtion will need to  */
end_comment
begin_comment
comment|/*    called with a pre-allocated stracture to be filled.                */
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
begin_define
DECL|macro|FT_DEFINE_GLYPH
define|#
directive|define
name|FT_DEFINE_GLYPH
parameter_list|(
name|class_
parameter_list|,
name|size_
parameter_list|,
name|format_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|copy_
parameter_list|,         \
name|transform_
parameter_list|,
name|bbox_
parameter_list|,
name|prepare_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                                      \   const FT_Glyph_Class class_ =                                              \   {                                                                          \     size_, format_, init_, done_, copy_, transform_, bbox_, prepare_         \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DEFINE_GLYPH
define|#
directive|define
name|FT_DEFINE_GLYPH
parameter_list|(
name|class_
parameter_list|,
name|size_
parameter_list|,
name|format_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|copy_
parameter_list|,         \
name|transform_
parameter_list|,
name|bbox_
parameter_list|,
name|prepare_
parameter_list|)
define|\
value|void                                                                       \   FT_Init_Class_##class_( FT_Glyph_Class*  clazz )                           \   {                                                                          \     clazz->glyph_size = size_;                                               \     clazz->glyph_format = format_;                                           \     clazz->glyph_init = init_;                                               \     clazz->glyph_done = done_;                                               \     clazz->glyph_copy = copy_;                                               \     clazz->glyph_transform = transform_;                                     \     clazz->glyph_bbox = bbox_;                                               \     clazz->glyph_prepare = prepare_;                                         \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
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
comment|/*    FT_DECLARE_RENDERER                                                */
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
comment|/*    FT_Renderer_Class stract instance.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_RENDERER                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Renderer_Class struct.        */
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
begin_define
DECL|macro|FT_DECLARE_RENDERER
define|#
directive|define
name|FT_DECLARE_RENDERER
parameter_list|(
name|class_
parameter_list|)
define|\
value|FT_EXPORT_VAR( const FT_Renderer_Class ) class_;
end_define
begin_define
DECL|macro|FT_DEFINE_RENDERER
define|#
directive|define
name|FT_DEFINE_RENDERER
parameter_list|(
name|class_
parameter_list|,                                           \
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,        \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|,         \
name|glyph_format_
parameter_list|,
name|render_glyph_
parameter_list|,
name|transform_glyph_
parameter_list|,   \
name|get_glyph_cbox_
parameter_list|,
name|set_mode_
parameter_list|,
name|raster_class_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                                      \   const FT_Renderer_Class  class_ =                                          \   {                                                                          \     FT_DEFINE_ROOT_MODULE(flags_,size_,name_,version_,requires_,             \                           interface_,init_,done_,get_interface_)             \     glyph_format_,                                                           \                                                                              \     render_glyph_,                                                           \     transform_glyph_,                                                        \     get_glyph_cbox_,                                                         \     set_mode_,                                                               \                                                                              \     raster_class_                                                            \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DECLARE_RENDERER
define|#
directive|define
name|FT_DECLARE_RENDERER
parameter_list|(
name|class_
parameter_list|)
value|FT_DECLARE_MODULE(class_)
end_define
begin_define
DECL|macro|FT_DEFINE_RENDERER
define|#
directive|define
name|FT_DEFINE_RENDERER
parameter_list|(
name|class_
parameter_list|, \
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,        \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|,         \
name|glyph_format_
parameter_list|,
name|render_glyph_
parameter_list|,
name|transform_glyph_
parameter_list|,   \
name|get_glyph_cbox_
parameter_list|,
name|set_mode_
parameter_list|,
name|raster_class_
parameter_list|)
define|\
value|void class_##_pic_free( FT_Library library );                              \   FT_Error class_##_pic_init( FT_Library library );                          \                                                                              \   void                                                                       \   FT_Destroy_Class_##class_( FT_Library        library,                      \                         FT_Module_Class*  clazz )                            \   {                                                                          \     FT_Renderer_Class* rclazz = (FT_Renderer_Class*)clazz;                   \     FT_Memory         memory = library->memory;                              \     class_##_pic_free( library );                                            \     if ( rclazz )                                                            \       FT_FREE( rclazz );                                                     \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library         library,                      \                             FT_Module_Class**  output_class )                \   {                                                                          \     FT_Renderer_Class*  clazz;                                               \     FT_Error            error;                                               \     FT_Memory           memory = library->memory;                            \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz) ) )                                 \       return error;                                                          \                                                                              \     error = class_##_pic_init( library );                                    \     if(error)                                                                \     {                                                                        \       FT_FREE( clazz );                                                      \       return error;                                                          \     }                                                                        \                                                                              \     FT_DEFINE_ROOT_MODULE(flags_,size_,name_,version_,requires_,             \                           interface_,init_,done_,get_interface_)             \                                                                              \     clazz->glyph_format       = glyph_format_;                               \                                                                              \     clazz->render_glyph       = render_glyph_;                               \     clazz->transform_glyph    = transform_glyph_;                            \     clazz->get_glyph_cbox     = get_glyph_cbox_;                             \     clazz->set_mode           = set_mode_;                                   \                                                                              \     clazz->raster_class       = raster_class_;                               \                                                                              \     *output_class = (FT_Module_Class*)clazz;                                 \     return FT_Err_Ok;                                                        \   }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
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
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****              PIC-Support Macros for ftmodapi.h                  ****/
end_comment
begin_comment
comment|/****                                                                 ****/
end_comment
begin_comment
comment|/****                                                                 ****/
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
name|FT_CONFIG_OPTION_PIC
end_ifdef
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
comment|/*    FT_Module_Creator                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to create (allocate) a new module class object.    */
end_comment
begin_comment
comment|/*    The object's members are initialized, but the module itself is     */
end_comment
begin_comment
comment|/*    not.                                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory       :: A handle to the memory manager.                    */
end_comment
begin_comment
comment|/*    output_class :: Initialized with the newly allocated class.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Module_Creator
modifier|*
name|FT_Module_Creator
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|FT_Module_Class
modifier|*
modifier|*
name|output_class
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
comment|/*    FT_Module_Destroyer                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A function used to destroy (deallocate) a module class object.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    memory :: A handle to the memory manager.                          */
end_comment
begin_comment
comment|/*    clazz  :: Module class to destroy.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Module_Destroyer
modifier|*
name|FT_Module_Destroyer
function_decl|)
parameter_list|(
name|FT_Memory
name|memory
parameter_list|,
name|FT_Module_Class
modifier|*
name|clazz
parameter_list|)
function_decl|;
end_typedef
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
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DECLARE_MODULE                                                  */
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
comment|/*    FT_Module_Class stract instance.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_MODULE                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Module_Class struct.          */
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
begin_comment
comment|/*<Macro>                                                               */
end_comment
begin_comment
comment|/*    FT_DEFINE_ROOT_MODULE                                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Used to initialize an instance of FT_Module_Class struct inside    */
end_comment
begin_comment
comment|/*    another stract that contains it or in a function that initializes  */
end_comment
begin_comment
comment|/*    that containing stract                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DECLARE_MODULE
define|#
directive|define
name|FT_DECLARE_MODULE
parameter_list|(
name|class_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE                                                          \   const FT_Module_Class  class_;                                             \  #define FT_DEFINE_ROOT_MODULE(flags_, size_, name_, version_, requires_,     \                               interface_, init_, done_, get_interface_)      \   {                                                                          \     flags_,                                                                  \     size_,                                                                   \                                                                              \     name_,                                                                   \     version_,                                                                \     requires_,                                                               \                                                                              \     interface_,                                                              \                                                                              \     init_,                                                                   \     done_,                                                                   \     get_interface_,                                                          \   },
end_define
begin_define
DECL|macro|FT_DEFINE_MODULE
define|#
directive|define
name|FT_DEFINE_MODULE
parameter_list|(
name|class_
parameter_list|,
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,  \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|)
define|\
value|FT_CALLBACK_TABLE_DEF                                                      \   const FT_Module_Class class_ =                                             \   {                                                                          \     flags_,                                                                  \     size_,                                                                   \                                                                              \     name_,                                                                   \     version_,                                                                \     requires_,                                                               \                                                                              \     interface_,                                                              \                                                                              \     init_,                                                                   \     done_,                                                                   \     get_interface_,                                                          \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_DECLARE_MODULE
define|#
directive|define
name|FT_DECLARE_MODULE
parameter_list|(
name|class_
parameter_list|)
define|\
value|FT_Error FT_Create_Class_##class_( FT_Library library,                     \                                      FT_Module_Class** output_class );       \   void     FT_Destroy_Class_##class_( FT_Library library,                    \                                       FT_Module_Class*  clazz );
end_define
begin_define
DECL|macro|FT_DEFINE_ROOT_MODULE
define|#
directive|define
name|FT_DEFINE_ROOT_MODULE
parameter_list|(
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,     \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|)
define|\
value|clazz->root.module_flags       = flags_;                                 \     clazz->root.module_size        = size_;                                  \     clazz->root.module_name        = name_;                                  \     clazz->root.module_version     = version_;                               \     clazz->root.module_requires    = requires_;                              \                                                                              \     clazz->root.module_interface   = interface_;                             \                                                                              \     clazz->root.module_init        = init_;                                  \     clazz->root.module_done        = done_;                                  \     clazz->root.get_interface      = get_interface_;
end_define
begin_define
DECL|macro|FT_DEFINE_MODULE
define|#
directive|define
name|FT_DEFINE_MODULE
parameter_list|(
name|class_
parameter_list|,
name|flags_
parameter_list|,
name|size_
parameter_list|,
name|name_
parameter_list|,
name|version_
parameter_list|,
name|requires_
parameter_list|,  \
name|interface_
parameter_list|,
name|init_
parameter_list|,
name|done_
parameter_list|,
name|get_interface_
parameter_list|)
define|\
value|void class_##_pic_free( FT_Library library );                              \   FT_Error class_##_pic_init( FT_Library library );                          \                                                                              \   void                                                                       \   FT_Destroy_Class_##class_( FT_Library library,                             \                              FT_Module_Class*  clazz )                       \   {                                                                          \     FT_Memory memory = library->memory;                                      \     class_##_pic_free( library );                                            \     if ( clazz )                                                             \       FT_FREE( clazz );                                                      \   }                                                                          \                                                                              \   FT_Error                                                                   \   FT_Create_Class_##class_( FT_Library library,                              \                             FT_Module_Class**  output_class )                \   {                                                                          \     FT_Memory memory = library->memory;                                      \     FT_Module_Class*  clazz;                                                 \     FT_Error          error;                                                 \                                                                              \     if ( FT_ALLOC( clazz, sizeof(*clazz) ) )                                 \       return error;                                                          \     error = class_##_pic_init( library );                                    \     if(error)                                                                \     {                                                                        \       FT_FREE( clazz );                                                      \       return error;                                                          \     }                                                                        \                                                                              \     clazz->module_flags       = flags_;                                      \     clazz->module_size        = size_;                                       \     clazz->module_name        = name_;                                       \     clazz->module_version     = version_;                                    \     clazz->module_requires    = requires_;                                   \                                                                              \     clazz->module_interface   = interface_;                                  \                                                                              \     clazz->module_init        = init_;                                       \     clazz->module_done        = done_;                                       \     clazz->get_interface      = get_interface_;                              \                                                                              \     *output_class = clazz;                                                   \     return FT_Err_Ok;                                                        \   }
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
comment|/* __FTOBJS_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
