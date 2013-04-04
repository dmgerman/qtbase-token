begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftincrem.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    FreeType incremental loading (specification).                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2006, 2007, 2008, 2010 by                        */
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
name|__FTINCREM_H__
end_ifndef
begin_define
DECL|macro|__FTINCREM_H__
define|#
directive|define
name|__FTINCREM_H__
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
comment|/***************************************************************************    *    * @section:    *    incremental    *    * @title:    *    Incremental Loading    *    * @abstract:    *    Custom Glyph Loading.    *    * @description:    *   This section contains various functions used to perform so-called    *   `incremental' glyph loading.  This is a mode where all glyphs loaded    *   from a given @FT_Face are provided by the client application,    *    *   Apart from that, all other tables are loaded normally from the font    *   file.  This mode is useful when FreeType is used within another    *   engine, e.g., a PostScript Imaging Processor.    *    *   To enable this mode, you must use @FT_Open_Face, passing an    *   @FT_Parameter with the @FT_PARAM_TAG_INCREMENTAL tag and an    *   @FT_Incremental_Interface value.  See the comments for    *   @FT_Incremental_InterfaceRec for an example.    *    */
end_comment
begin_comment
comment|/***************************************************************************    *    * @type:    *   FT_Incremental    *    * @description:    *   An opaque type describing a user-provided object used to implement    *   `incremental' glyph loading within FreeType.  This is used to support    *   embedded fonts in certain environments (e.g., PostScript interpreters),    *   where the glyph data isn't in the font file, or must be overridden by    *   different values.    *    * @note:    *   It is up to client applications to create and implement @FT_Incremental    *   objects, as long as they provide implementations for the methods    *   @FT_Incremental_GetGlyphDataFunc, @FT_Incremental_FreeGlyphDataFunc    *   and @FT_Incremental_GetGlyphMetricsFunc.    *    *   See the description of @FT_Incremental_InterfaceRec to understand how    *   to use incremental objects with FreeType.    *    */
end_comment
begin_typedef
DECL|typedef|FT_Incremental
typedef|typedef
name|struct
name|FT_IncrementalRec_
modifier|*
name|FT_Incremental
typedef|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @struct:    *   FT_Incremental_MetricsRec    *    * @description:    *   A small structure used to contain the basic glyph metrics returned    *   by the @FT_Incremental_GetGlyphMetricsFunc method.    *    * @fields:    *   bearing_x ::    *     Left bearing, in font units.    *    *   bearing_y ::    *     Top bearing, in font units.    *    *   advance ::    *     Horizontal component of glyph advance, in font units.    *    *   advance_v ::    *     Vertical component of glyph advance, in font units.    *    * @note:    *   These correspond to horizontal or vertical metrics depending on the    *   value of the `vertical' argument to the function    *   @FT_Incremental_GetGlyphMetricsFunc.    *    */
end_comment
begin_typedef
DECL|struct|FT_Incremental_MetricsRec_
typedef|typedef
struct|struct
name|FT_Incremental_MetricsRec_
block|{
DECL|member|bearing_x
name|FT_Long
name|bearing_x
decl_stmt|;
DECL|member|bearing_y
name|FT_Long
name|bearing_y
decl_stmt|;
DECL|member|advance
name|FT_Long
name|advance
decl_stmt|;
DECL|member|advance_v
name|FT_Long
name|advance_v
decl_stmt|;
comment|/* since 2.3.12 */
block|}
DECL|typedef|FT_Incremental_MetricsRec
name|FT_Incremental_MetricsRec
typedef|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @struct:    *   FT_Incremental_Metrics    *    * @description:    *   A handle to an @FT_Incremental_MetricsRec structure.    *    */
end_comment
begin_typedef
DECL|typedef|FT_Incremental_Metrics
typedef|typedef
name|struct
name|FT_Incremental_MetricsRec_
modifier|*
name|FT_Incremental_Metrics
typedef|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @type:    *   FT_Incremental_GetGlyphDataFunc    *    * @description:    *   A function called by FreeType to access a given glyph's data bytes    *   during @FT_Load_Glyph or @FT_Load_Char if incremental loading is    *   enabled.    *    *   Note that the format of the glyph's data bytes depends on the font    *   file format.  For TrueType, it must correspond to the raw bytes within    *   the `glyf' table.  For PostScript formats, it must correspond to the    *   *unencrypted* charstring bytes, without any `lenIV' header.  It is    *   undefined for any other format.    *    * @input:    *   incremental ::    *     Handle to an opaque @FT_Incremental handle provided by the client    *     application.    *    *   glyph_index ::    *     Index of relevant glyph.    *    * @output:    *   adata ::    *     A structure describing the returned glyph data bytes (which will be    *     accessed as a read-only byte block).    *    * @return:    *   FreeType error code.  0~means success.    *    * @note:    *   If this function returns successfully the method    *   @FT_Incremental_FreeGlyphDataFunc will be called later to release    *   the data bytes.    *    *   Nested calls to @FT_Incremental_GetGlyphDataFunc can happen for    *   compound glyphs.    *    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Incremental_GetGlyphDataFunc
modifier|*
name|FT_Incremental_GetGlyphDataFunc
function_decl|)
parameter_list|(
name|FT_Incremental
name|incremental
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Data
modifier|*
name|adata
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @type:    *   FT_Incremental_FreeGlyphDataFunc    *    * @description:    *   A function used to release the glyph data bytes returned by a    *   successful call to @FT_Incremental_GetGlyphDataFunc.    *    * @input:    *   incremental ::    *     A handle to an opaque @FT_Incremental handle provided by the client    *     application.    *    *   data ::    *     A structure describing the glyph data bytes (which will be accessed    *     as a read-only byte block).    *    */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|FT_Incremental_FreeGlyphDataFunc
modifier|*
name|FT_Incremental_FreeGlyphDataFunc
function_decl|)
parameter_list|(
name|FT_Incremental
name|incremental
parameter_list|,
name|FT_Data
modifier|*
name|data
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @type:    *   FT_Incremental_GetGlyphMetricsFunc    *    * @description:    *   A function used to retrieve the basic metrics of a given glyph index    *   before accessing its data.  This is necessary because, in certain    *   formats like TrueType, the metrics are stored in a different place from    *   the glyph images proper.    *    * @input:    *   incremental ::    *     A handle to an opaque @FT_Incremental handle provided by the client    *     application.    *    *   glyph_index ::    *     Index of relevant glyph.    *    *   vertical ::    *     If true, return vertical metrics.    *    *   ametrics ::    *     This parameter is used for both input and output.    *     The original glyph metrics, if any, in font units.  If metrics are    *     not available all the values must be set to zero.    *    * @output:    *   ametrics ::    *     The replacement glyph metrics in font units.    *    */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|FT_Incremental_GetGlyphMetricsFunc
modifier|*
name|FT_Incremental_GetGlyphMetricsFunc
function_decl|)
parameter_list|(
name|FT_Incremental
name|incremental
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_Bool
name|vertical
parameter_list|,
name|FT_Incremental_MetricsRec
modifier|*
name|ametrics
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/**************************************************************************    *    * @struct:    *   FT_Incremental_FuncsRec    *    * @description:    *   A table of functions for accessing fonts that load data    *   incrementally.  Used in @FT_Incremental_InterfaceRec.    *    * @fields:    *   get_glyph_data ::    *     The function to get glyph data.  Must not be null.    *    *   free_glyph_data ::    *     The function to release glyph data.  Must not be null.    *    *   get_glyph_metrics ::    *     The function to get glyph metrics.  May be null if the font does    *     not provide overriding glyph metrics.    *    */
end_comment
begin_typedef
DECL|struct|FT_Incremental_FuncsRec_
typedef|typedef
struct|struct
name|FT_Incremental_FuncsRec_
block|{
DECL|member|get_glyph_data
name|FT_Incremental_GetGlyphDataFunc
name|get_glyph_data
decl_stmt|;
DECL|member|free_glyph_data
name|FT_Incremental_FreeGlyphDataFunc
name|free_glyph_data
decl_stmt|;
DECL|member|get_glyph_metrics
name|FT_Incremental_GetGlyphMetricsFunc
name|get_glyph_metrics
decl_stmt|;
block|}
DECL|typedef|FT_Incremental_FuncsRec
name|FT_Incremental_FuncsRec
typedef|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @struct:    *   FT_Incremental_InterfaceRec    *    * @description:    *   A structure to be used with @FT_Open_Face to indicate that the user    *   wants to support incremental glyph loading.  You should use it with    *   @FT_PARAM_TAG_INCREMENTAL as in the following example:    *    *     {    *       FT_Incremental_InterfaceRec  inc_int;    *       FT_Parameter                 parameter;    *       FT_Open_Args                 open_args;    *    *    *       // set up incremental descriptor    *       inc_int.funcs  = my_funcs;    *       inc_int.object = my_object;    *    *       // set up optional parameter    *       parameter.tag  = FT_PARAM_TAG_INCREMENTAL;    *       parameter.data =&inc_int;    *    *       // set up FT_Open_Args structure    *       open_args.flags      = FT_OPEN_PATHNAME | FT_OPEN_PARAMS;    *       open_args.pathname   = my_font_pathname;    *       open_args.num_params = 1;    *       open_args.params     =&parameter; // we use one optional argument    *    *       // open the font    *       error = FT_Open_Face( library,&open_args, index,&face );    *       ...    *     }    *    */
end_comment
begin_typedef
DECL|struct|FT_Incremental_InterfaceRec_
typedef|typedef
struct|struct
name|FT_Incremental_InterfaceRec_
block|{
DECL|member|funcs
specifier|const
name|FT_Incremental_FuncsRec
modifier|*
name|funcs
decl_stmt|;
DECL|member|object
name|FT_Incremental
name|object
decl_stmt|;
block|}
DECL|typedef|FT_Incremental_InterfaceRec
name|FT_Incremental_InterfaceRec
typedef|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @type:    *   FT_Incremental_Interface    *    * @description:    *   A pointer to an @FT_Incremental_InterfaceRec structure.    *    */
end_comment
begin_typedef
DECL|typedef|FT_Incremental_Interface
typedef|typedef
name|FT_Incremental_InterfaceRec
modifier|*
name|FT_Incremental_Interface
typedef|;
end_typedef
begin_comment
comment|/***************************************************************************    *    * @constant:    *   FT_PARAM_TAG_INCREMENTAL    *    * @description:    *   A constant used as the tag of @FT_Parameter structures to indicate    *   an incremental loading object to be used by FreeType.    *    */
end_comment
begin_define
DECL|macro|FT_PARAM_TAG_INCREMENTAL
define|#
directive|define
name|FT_PARAM_TAG_INCREMENTAL
value|FT_MAKE_TAG( 'i', 'n', 'c', 'r' )
end_define
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
comment|/* __FTINCREM_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
