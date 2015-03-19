begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftgzip.h                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Gzip-compressed stream support.                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002-2004, 2006, 2013 by                                     */
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
name|__FTGZIP_H__
end_ifndef
begin_define
DECL|macro|__FTGZIP_H__
define|#
directive|define
name|__FTGZIP_H__
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
comment|/*    gzip                                                               */
comment|/*                                                                       */
comment|/*<Title>                                                               */
comment|/*    GZIP Streams                                                       */
comment|/*                                                                       */
comment|/*<Abstract>                                                            */
comment|/*    Using gzip-compressed font files.                                  */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This section contains the declaration of Gzip-specific functions.  */
comment|/*                                                                       */
comment|/*************************************************************************/
comment|/************************************************************************   *   * @function:   *   FT_Stream_OpenGzip   *   * @description:   *   Open a new stream to parse gzip-compressed font files.  This is   *   mainly used to support the compressed `*.pcf.gz' fonts that come   *   with XFree86.   *   * @input:   *   stream ::   *     The target embedding stream.   *   *   source ::   *     The source stream.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   The source stream must be opened _before_ calling this function.   *   *   Calling the internal function `FT_Stream_Close' on the new stream will   *   *not* call `FT_Stream_Close' on the source stream.  None of the stream   *   objects will be released to the heap.   *   *   The stream implementation is very basic and resets the decompression   *   process each time seeking backwards is needed within the stream.   *   *   In certain builds of the library, gzip compression recognition is   *   automatically handled when calling @FT_New_Face or @FT_Open_Face.   *   This means that if no font driver is capable of handling the raw   *   compressed file, the library will try to open a gzipped stream from   *   it and re-open the face with it.   *   *   This function may return `FT_Err_Unimplemented_Feature' if your build   *   of FreeType was not compiled with zlib support.   */
name|FT_EXPORT
parameter_list|(
name|FT_Error
parameter_list|)
function_decl|FT_Stream_OpenGzip
parameter_list|(
name|FT_Stream
name|stream
parameter_list|,
name|FT_Stream
name|source
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/************************************************************************   *   * @function:   *   FT_Gzip_Uncompress   *   * @description:   *   Decompress a zipped input buffer into an output buffer.  This function   *   is modeled after zlib's `uncompress' function.   *   * @input:   *   memory ::   *     A FreeType memory handle.   *   *   input ::   *     The input buffer.   *   *   input_len ::   *     The length of the input buffer.   *   * @output:   *   output::   *     The output buffer.   *   * @inout:   *   output_len ::   *     Before calling the function, this is the the total size of the   *     output buffer, which must be large enough to hold the entire   *     uncompressed data (so the size of the uncompressed data must be   *     known in advance).  After calling the function, `output_len' is the   *     size of the used data in `output'.   *   * @return:   *   FreeType error code.  0~means success.   *   * @note:   *   This function may return `FT_Err_Unimplemented_Feature' if your build   *   of FreeType was not compiled with zlib support.   */
end_comment
begin_macro
name|FT_EXPORT
argument_list|(
argument|FT_Error
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Gzip_Uncompress
name|FT_Gzip_Uncompress
argument_list|(
argument|FT_Memory       memory
argument_list|,
argument|FT_Byte*        output
argument_list|,
argument|FT_ULong*       output_len
argument_list|,
argument|const FT_Byte*  input
argument_list|,
argument|FT_ULong        input_len
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
comment|/* __FTGZIP_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
