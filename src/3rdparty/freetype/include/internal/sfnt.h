begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  sfnt.h                                                                 */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    High-level `sfnt' driver interface (specification).                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2006, 2009, 2012-2014 by                                */
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
name|__SFNT_H__
end_ifndef
begin_define
DECL|macro|__SFNT_H__
define|#
directive|define
name|__SFNT_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DRIVER_H
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_TRUETYPE_TYPES_H
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
comment|/*<FuncType>                                                            */
end_comment
begin_comment
comment|/*    TT_Init_Face_Func                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    First part of the SFNT face object initialization.  This finds     */
end_comment
begin_comment
comment|/*    the face in a SFNT file or collection, and load its format tag in  */
end_comment
begin_comment
comment|/*    face->format_tag.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream     :: The input stream.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face       :: A handle to the target face object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the TrueType font, if we are opening a  */
end_comment
begin_comment
comment|/*                  collection.                                          */
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
comment|/*    params     :: Optional additional parameters.                      */
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
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The stream cursor must be at the font file's origin.               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function recognizes fonts embedded in a `TrueType             */
end_comment
begin_comment
comment|/*    collection'.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    Once the format tag has been validated by the font driver, it      */
end_comment
begin_comment
comment|/*    should then call the TT_Load_Face_Func() callback to read the rest */
end_comment
begin_comment
comment|/*    of the SFNT tables in the object.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Init_Face_Func
modifier|*
name|TT_Init_Face_Func
function_decl|)
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|TT_Face
name|face
parameter_list|,
name|FT_Int
name|face_index
parameter_list|,
name|FT_Int
name|num_params
parameter_list|,
name|FT_Parameter
modifier|*
name|params
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
comment|/*    TT_Load_Face_Func                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Second part of the SFNT face object initialization.  This loads    */
end_comment
begin_comment
comment|/*    the common SFNT tables (head, OS/2, maxp, metrics, etc.) in the    */
end_comment
begin_comment
comment|/*    face object.                                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream     :: The input stream.                                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face       :: A handle to the target face object.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    face_index :: The index of the TrueType font, if we are opening a  */
end_comment
begin_comment
comment|/*                  collection.                                          */
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
comment|/*    params     :: Optional additional parameters.                      */
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
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function must be called after TT_Init_Face_Func().            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_Face_Func
modifier|*
name|TT_Load_Face_Func
function_decl|)
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|TT_Face
name|face
parameter_list|,
name|FT_Int
name|face_index
parameter_list|,
name|FT_Int
name|num_params
parameter_list|,
name|FT_Parameter
modifier|*
name|params
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
comment|/*    TT_Done_Face_Func                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    A callback used to delete the common SFNT data from a face.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the target face object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function does NOT destroy the face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|TT_Done_Face_Func
modifier|*
name|TT_Done_Face_Func
function_decl|)
parameter_list|(
name|TT_Face
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
comment|/*    TT_Load_Any_Func                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load any font table into client memory.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face   :: The face object to look for.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    tag    :: The tag of table to load.  Use the value 0 if you want   */
end_comment
begin_comment
comment|/*              to access the whole font file, else set this parameter   */
end_comment
begin_comment
comment|/*              to a valid TrueType table tag that you can forge with    */
end_comment
begin_comment
comment|/*              the MAKE_TT_TAG macro.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    offset :: The starting offset in the table (or the file if         */
end_comment
begin_comment
comment|/*              tag == 0).                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    length :: The address of the decision variable:                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                If length == NULL:                                     */
end_comment
begin_comment
comment|/*                  Loads the whole table.  Returns an error if          */
end_comment
begin_comment
comment|/*                  `offset' == 0!                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                If *length == 0:                                       */
end_comment
begin_comment
comment|/*                  Exits immediately; returning the length of the given */
end_comment
begin_comment
comment|/*                  table or of the font file, depending on the value of */
end_comment
begin_comment
comment|/*                  `tag'.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*                If *length != 0:                                       */
end_comment
begin_comment
comment|/*                  Loads the next `length' bytes of table or font,      */
end_comment
begin_comment
comment|/*                  starting at offset `offset' (in table or font too).  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    buffer :: The address of target buffer.                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    TrueType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_Any_Func
modifier|*
name|TT_Load_Any_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_ULong
name|tag
parameter_list|,
name|FT_Long
name|offset
parameter_list|,
name|FT_Byte
modifier|*
name|buffer
parameter_list|,
name|FT_ULong
modifier|*
name|length
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
comment|/*    TT_Find_SBit_Image_Func                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Check whether an embedded bitmap (an `sbit') exists for a given    */
end_comment
begin_comment
comment|/*    glyph, at a given strike.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face          :: The target face object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_index   :: The glyph index.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    strike_index  :: The current strike index.                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    arange        :: The SBit range containing the glyph index.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    astrike       :: The SBit strike containing the glyph index.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    aglyph_offset :: The offset of the glyph data in `EBDT' table.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.  Returns                    */
end_comment
begin_comment
comment|/*    SFNT_Err_Invalid_Argument if no sbit exists for the requested      */
end_comment
begin_comment
comment|/*    glyph.                                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Find_SBit_Image_Func
modifier|*
name|TT_Find_SBit_Image_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_ULong
name|strike_index
parameter_list|,
name|TT_SBit_Range
modifier|*
name|arange
parameter_list|,
name|TT_SBit_Strike
modifier|*
name|astrike
parameter_list|,
name|FT_ULong
modifier|*
name|aglyph_offset
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
comment|/*    TT_Load_SBit_Metrics_Func                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Get the big metrics for a given embedded bitmap.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    stream      :: The input stream.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    range       :: The SBit range containing the glyph.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    big_metrics :: A big SBit metrics structure for the glyph.         */
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
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The stream cursor must be positioned at the glyph's offset within  */
end_comment
begin_comment
comment|/*    the `EBDT' table before the call.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    If the image format uses variable metrics, the stream cursor is    */
end_comment
begin_comment
comment|/*    positioned just after the metrics header in the `EBDT' table on    */
end_comment
begin_comment
comment|/*    function exit.                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_SBit_Metrics_Func
modifier|*
name|TT_Load_SBit_Metrics_Func
function_decl|)
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|TT_SBit_Range
name|range
parameter_list|,
name|TT_SBit_Metrics
name|metrics
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
comment|/*    TT_Load_SBit_Image_Func                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load a given glyph sbit image from the font resource.  This also   */
end_comment
begin_comment
comment|/*    returns its metrics.                                               */
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
comment|/*      The target face object.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    strike_index ::                                                    */
end_comment
begin_comment
comment|/*      The strike index.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    glyph_index ::                                                     */
end_comment
begin_comment
comment|/*      The current glyph index.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    load_flags ::                                                      */
end_comment
begin_comment
comment|/*      The current load flags.                                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream ::                                                          */
end_comment
begin_comment
comment|/*      The input stream.                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    amap ::                                                            */
end_comment
begin_comment
comment|/*      The target pixmap.                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    ametrics ::                                                        */
end_comment
begin_comment
comment|/*      A big sbit metrics structure for the glyph image.                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.  Returns an error if no     */
end_comment
begin_comment
comment|/*    glyph sbit exists for the index.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                               */
end_comment
begin_comment
comment|/*    The `map.buffer' field is always freed before the glyph is loaded. */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_SBit_Image_Func
modifier|*
name|TT_Load_SBit_Image_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_ULong
name|strike_index
parameter_list|,
name|FT_UInt
name|glyph_index
parameter_list|,
name|FT_UInt
name|load_flags
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_Bitmap
modifier|*
name|amap
parameter_list|,
name|TT_SBit_MetricsRec
modifier|*
name|ametrics
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
comment|/*    TT_Set_SBit_Strike_Func                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Select an sbit strike for a given size request.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face          :: The target face object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    req           :: The size request.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    astrike_index :: The index of the sbit strike.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.  Returns an error if no     */
end_comment
begin_comment
comment|/*    sbit strike exists for the selected ppem values.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Set_SBit_Strike_Func
modifier|*
name|TT_Set_SBit_Strike_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Size_Request
name|req
parameter_list|,
name|FT_ULong
modifier|*
name|astrike_index
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
comment|/*    TT_Load_Strike_Metrics_Func                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the metrics of a given strike.                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face          :: The target face object.                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    strike_index  :: The strike index.                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    metrics       :: the metrics of the strike.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.  Returns an error if no     */
end_comment
begin_comment
comment|/*    such sbit strike exists.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_Strike_Metrics_Func
modifier|*
name|TT_Load_Strike_Metrics_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_ULong
name|strike_index
parameter_list|,
name|FT_Size_Metrics
modifier|*
name|metrics
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
comment|/*    TT_Get_PS_Name_Func                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Get the PostScript glyph name of a glyph.                          */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    idx  :: The glyph index.                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    PSname :: The address of a string pointer.  Will be NULL in case   */
end_comment
begin_comment
comment|/*              of error, otherwise it is a pointer to the glyph name.   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*              You must not modify the returned string!                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    FreeType error code.  0 means success.                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Get_PS_Name_Func
modifier|*
name|TT_Get_PS_Name_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_UInt
name|idx
parameter_list|,
name|FT_String
modifier|*
modifier|*
name|PSname
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
comment|/*    TT_Load_Metrics_Func                                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load a metrics table, which is a table with a horizontal and a     */
end_comment
begin_comment
comment|/*    vertical version.                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face     :: A handle to the target face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream   :: The input stream.                                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertical :: A boolean flag.  If set, load the vertical one.        */
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
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_Metrics_Func
modifier|*
name|TT_Load_Metrics_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Stream
name|stream
parameter_list|,
name|FT_Bool
name|vertical
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
comment|/*    TT_Get_Metrics_Func                                                */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load the horizontal or vertical header in a face object.           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face     :: A handle to the target face object.                    */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    vertical :: A boolean flag.  If set, load vertical metrics.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    gindex   :: The glyph index.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Output>                                                              */
end_comment
begin_comment
comment|/*    abearing :: The horizontal (or vertical) bearing.  Set to zero in  */
end_comment
begin_comment
comment|/*                case of error.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    aadvance :: The horizontal (or vertical) advance.  Set to zero in  */
end_comment
begin_comment
comment|/*                case of error.                                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|TT_Get_Metrics_Func
modifier|*
name|TT_Get_Metrics_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Bool
name|vertical
parameter_list|,
name|FT_UInt
name|gindex
parameter_list|,
name|FT_Short
modifier|*
name|abearing
parameter_list|,
name|FT_UShort
modifier|*
name|aadvance
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
comment|/*    TT_Load_Table_Func                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Load a given TrueType table.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face   :: A handle to the target face object.                      */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    stream :: The input stream.                                        */
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
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    The function uses `face->goto_table' to seek the stream to the     */
end_comment
begin_comment
comment|/*    start of the table, except while loading the font directory.       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|FT_Error
function_decl|(
DECL|typedef|TT_Load_Table_Func
modifier|*
name|TT_Load_Table_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_Stream
name|stream
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
comment|/*    TT_Free_Table_Func                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Free a given TrueType table.                                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    face :: A handle to the target face object.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
typedef|typedef
name|void
function_decl|(
DECL|typedef|TT_Free_Table_Func
modifier|*
name|TT_Free_Table_Func
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/*    * @functype:    *    TT_Face_GetKerningFunc    *    * @description:    *    Return the horizontal kerning value between two glyphs.    *    * @input:    *    face        :: A handle to the source face object.    *    left_glyph  :: The left glyph index.    *    right_glyph :: The right glyph index.    *    * @return:    *    The kerning value in font units.    */
end_comment
begin_typedef
typedef|typedef
name|FT_Int
function_decl|(
DECL|typedef|TT_Face_GetKerningFunc
modifier|*
name|TT_Face_GetKerningFunc
function_decl|)
parameter_list|(
name|TT_Face
name|face
parameter_list|,
name|FT_UInt
name|left_glyph
parameter_list|,
name|FT_UInt
name|right_glyph
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
comment|/*    SFNT_Interface                                                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    This structure holds pointers to the functions used to load and    */
end_comment
begin_comment
comment|/*    free the basic tables that are required in a `sfnt' font file.     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Fields>                                                              */
end_comment
begin_comment
comment|/*    Check the various xxx_Func() descriptions for details.             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_typedef
DECL|struct|SFNT_Interface_
typedef|typedef
struct|struct
name|SFNT_Interface_
block|{
DECL|member|goto_table
name|TT_Loader_GotoTableFunc
name|goto_table
decl_stmt|;
DECL|member|init_face
name|TT_Init_Face_Func
name|init_face
decl_stmt|;
DECL|member|load_face
name|TT_Load_Face_Func
name|load_face
decl_stmt|;
DECL|member|done_face
name|TT_Done_Face_Func
name|done_face
decl_stmt|;
DECL|member|get_interface
name|FT_Module_Requester
name|get_interface
decl_stmt|;
DECL|member|load_any
name|TT_Load_Any_Func
name|load_any
decl_stmt|;
comment|/* these functions are called by `load_face' but they can also  */
comment|/* be called from external modules, if there is a need to do so */
DECL|member|load_head
name|TT_Load_Table_Func
name|load_head
decl_stmt|;
DECL|member|load_hhea
name|TT_Load_Metrics_Func
name|load_hhea
decl_stmt|;
DECL|member|load_cmap
name|TT_Load_Table_Func
name|load_cmap
decl_stmt|;
DECL|member|load_maxp
name|TT_Load_Table_Func
name|load_maxp
decl_stmt|;
DECL|member|load_os2
name|TT_Load_Table_Func
name|load_os2
decl_stmt|;
DECL|member|load_post
name|TT_Load_Table_Func
name|load_post
decl_stmt|;
DECL|member|load_name
name|TT_Load_Table_Func
name|load_name
decl_stmt|;
DECL|member|free_name
name|TT_Free_Table_Func
name|free_name
decl_stmt|;
comment|/* this field was called `load_kerning' up to version 2.1.10 */
DECL|member|load_kern
name|TT_Load_Table_Func
name|load_kern
decl_stmt|;
DECL|member|load_gasp
name|TT_Load_Table_Func
name|load_gasp
decl_stmt|;
DECL|member|load_pclt
name|TT_Load_Table_Func
name|load_pclt
decl_stmt|;
comment|/* see `ttload.h'; this field was called `load_bitmap_header' up to */
comment|/* version 2.1.10                                                   */
DECL|member|load_bhed
name|TT_Load_Table_Func
name|load_bhed
decl_stmt|;
DECL|member|load_sbit_image
name|TT_Load_SBit_Image_Func
name|load_sbit_image
decl_stmt|;
comment|/* see `ttpost.h' */
DECL|member|get_psname
name|TT_Get_PS_Name_Func
name|get_psname
decl_stmt|;
DECL|member|free_psnames
name|TT_Free_Table_Func
name|free_psnames
decl_stmt|;
comment|/* starting here, the structure differs from version 2.1.7 */
comment|/* this field was introduced in version 2.1.8, named `get_psname' */
DECL|member|get_kerning
name|TT_Face_GetKerningFunc
name|get_kerning
decl_stmt|;
comment|/* new elements introduced after version 2.1.10 */
comment|/* load the font directory, i.e., the offset table and */
comment|/* the table directory                                 */
DECL|member|load_font_dir
name|TT_Load_Table_Func
name|load_font_dir
decl_stmt|;
DECL|member|load_hmtx
name|TT_Load_Metrics_Func
name|load_hmtx
decl_stmt|;
DECL|member|load_eblc
name|TT_Load_Table_Func
name|load_eblc
decl_stmt|;
DECL|member|free_eblc
name|TT_Free_Table_Func
name|free_eblc
decl_stmt|;
DECL|member|set_sbit_strike
name|TT_Set_SBit_Strike_Func
name|set_sbit_strike
decl_stmt|;
DECL|member|load_strike_metrics
name|TT_Load_Strike_Metrics_Func
name|load_strike_metrics
decl_stmt|;
DECL|member|get_metrics
name|TT_Get_Metrics_Func
name|get_metrics
decl_stmt|;
block|}
DECL|typedef|SFNT_Interface
name|SFNT_Interface
typedef|;
end_typedef
begin_comment
comment|/* transitional */
end_comment
begin_typedef
DECL|typedef|SFNT_Service
typedef|typedef
name|SFNT_Interface
modifier|*
name|SFNT_Service
typedef|;
end_typedef
begin_ifndef
ifndef|#
directive|ifndef
name|FT_CONFIG_OPTION_PIC
end_ifndef
begin_define
DECL|macro|FT_DEFINE_SFNT_INTERFACE
define|#
directive|define
name|FT_DEFINE_SFNT_INTERFACE
parameter_list|(        \
name|class_
parameter_list|,                        \
name|goto_table_
parameter_list|,                   \
name|init_face_
parameter_list|,                    \
name|load_face_
parameter_list|,                    \
name|done_face_
parameter_list|,                    \
name|get_interface_
parameter_list|,                \
name|load_any_
parameter_list|,                     \
name|load_head_
parameter_list|,                    \
name|load_hhea_
parameter_list|,                    \
name|load_cmap_
parameter_list|,                    \
name|load_maxp_
parameter_list|,                    \
name|load_os2_
parameter_list|,                     \
name|load_post_
parameter_list|,                    \
name|load_name_
parameter_list|,                    \
name|free_name_
parameter_list|,                    \
name|load_kern_
parameter_list|,                    \
name|load_gasp_
parameter_list|,                    \
name|load_pclt_
parameter_list|,                    \
name|load_bhed_
parameter_list|,                    \
name|load_sbit_image_
parameter_list|,              \
name|get_psname_
parameter_list|,                   \
name|free_psnames_
parameter_list|,                 \
name|get_kerning_
parameter_list|,                  \
name|load_font_dir_
parameter_list|,                \
name|load_hmtx_
parameter_list|,                    \
name|load_eblc_
parameter_list|,                    \
name|free_eblc_
parameter_list|,                    \
name|set_sbit_strike_
parameter_list|,              \
name|load_strike_metrics_
parameter_list|,          \
name|get_metrics_
parameter_list|)
define|\
value|static const SFNT_Interface  class_ =  \   {                                      \     goto_table_,                         \     init_face_,                          \     load_face_,                          \     done_face_,                          \     get_interface_,                      \     load_any_,                           \     load_head_,                          \     load_hhea_,                          \     load_cmap_,                          \     load_maxp_,                          \     load_os2_,                           \     load_post_,                          \     load_name_,                          \     free_name_,                          \     load_kern_,                          \     load_gasp_,                          \     load_pclt_,                          \     load_bhed_,                          \     load_sbit_image_,                    \     get_psname_,                         \     free_psnames_,                       \     get_kerning_,                        \     load_font_dir_,                      \     load_hmtx_,                          \     load_eblc_,                          \     free_eblc_,                          \     set_sbit_strike_,                    \     load_strike_metrics_,                \     get_metrics_,                        \   };
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* FT_CONFIG_OPTION_PIC */
end_comment
begin_define
DECL|macro|FT_INTERNAL
define|#
directive|define
name|FT_INTERNAL
parameter_list|(
name|a
parameter_list|,
name|a_
parameter_list|)
define|\
value|clazz->a = a_;
end_define
begin_define
DECL|macro|FT_DEFINE_SFNT_INTERFACE
define|#
directive|define
name|FT_DEFINE_SFNT_INTERFACE
parameter_list|(                       \
name|class_
parameter_list|,                                       \
name|goto_table_
parameter_list|,                                  \
name|init_face_
parameter_list|,                                   \
name|load_face_
parameter_list|,                                   \
name|done_face_
parameter_list|,                                   \
name|get_interface_
parameter_list|,                               \
name|load_any_
parameter_list|,                                    \
name|load_head_
parameter_list|,                                   \
name|load_hhea_
parameter_list|,                                   \
name|load_cmap_
parameter_list|,                                   \
name|load_maxp_
parameter_list|,                                   \
name|load_os2_
parameter_list|,                                    \
name|load_post_
parameter_list|,                                   \
name|load_name_
parameter_list|,                                   \
name|free_name_
parameter_list|,                                   \
name|load_kern_
parameter_list|,                                   \
name|load_gasp_
parameter_list|,                                   \
name|load_pclt_
parameter_list|,                                   \
name|load_bhed_
parameter_list|,                                   \
name|load_sbit_image_
parameter_list|,                             \
name|get_psname_
parameter_list|,                                  \
name|free_psnames_
parameter_list|,                                \
name|get_kerning_
parameter_list|,                                 \
name|load_font_dir_
parameter_list|,                               \
name|load_hmtx_
parameter_list|,                                   \
name|load_eblc_
parameter_list|,                                   \
name|free_eblc_
parameter_list|,                                   \
name|set_sbit_strike_
parameter_list|,                             \
name|load_strike_metrics_
parameter_list|,                         \
name|get_metrics_
parameter_list|)
define|\
value|void                                                  \   FT_Init_Class_ ## class_( FT_Library       library,   \                             SFNT_Interface*  clazz )    \   {                                                     \     FT_UNUSED( library );                               \                                                         \     clazz->goto_table          = goto_table_;           \     clazz->init_face           = init_face_;            \     clazz->load_face           = load_face_;            \     clazz->done_face           = done_face_;            \     clazz->get_interface       = get_interface_;        \     clazz->load_any            = load_any_;             \     clazz->load_head           = load_head_;            \     clazz->load_hhea           = load_hhea_;            \     clazz->load_cmap           = load_cmap_;            \     clazz->load_maxp           = load_maxp_;            \     clazz->load_os2            = load_os2_;             \     clazz->load_post           = load_post_;            \     clazz->load_name           = load_name_;            \     clazz->free_name           = free_name_;            \     clazz->load_kern           = load_kern_;            \     clazz->load_gasp           = load_gasp_;            \     clazz->load_pclt           = load_pclt_;            \     clazz->load_bhed           = load_bhed_;            \     clazz->load_sbit_image     = load_sbit_image_;      \     clazz->get_psname          = get_psname_;           \     clazz->free_psnames        = free_psnames_;         \     clazz->get_kerning         = get_kerning_;          \     clazz->load_font_dir       = load_font_dir_;        \     clazz->load_hmtx           = load_hmtx_;            \     clazz->load_eblc           = load_eblc_;            \     clazz->free_eblc           = free_eblc_;            \     clazz->set_sbit_strike     = set_sbit_strike_;      \     clazz->load_strike_metrics = load_strike_metrics_;  \     clazz->get_metrics         = get_metrics_;          \   }
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
comment|/* __SFNT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
