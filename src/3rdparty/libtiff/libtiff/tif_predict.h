begin_unit
begin_comment
comment|/* $Id: tif_predict.h,v 1.3.2.1 2007/11/22 21:24:51 fwarmerdam Exp $ */
end_comment
begin_comment
comment|/*  * Copyright (c) 1995-1997 Sam Leffler  * Copyright (c) 1995-1997 Silicon Graphics, Inc.  *  * Permission to use, copy, modify, distribute, and sell this software and   * its documentation for any purpose is hereby granted without fee, provided  * that (i) the above copyright notices and this permission notice appear in  * all copies of the software and related documentation, and (ii) the names of  * Sam Leffler and Silicon Graphics may not be used in any advertising or  * publicity relating to the software without the specific, prior written  * permission of Sam Leffler and Silicon Graphics.  *   * THE SOFTWARE IS PROVIDED "AS-IS" AND WITHOUT WARRANTY OF ANY KIND,   * EXPRESS, IMPLIED OR OTHERWISE, INCLUDING WITHOUT LIMITATION, ANY   * WARRANTY OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.    *   * IN NO EVENT SHALL SAM LEFFLER OR SILICON GRAPHICS BE LIABLE FOR  * ANY SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY KIND,  * OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,  * WHETHER OR NOT ADVISED OF THE POSSIBILITY OF DAMAGE, AND ON ANY THEORY OF   * LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE   * OF THIS SOFTWARE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_TIFFPREDICT_
end_ifndef
begin_define
DECL|macro|_TIFFPREDICT_
define|#
directive|define
name|_TIFFPREDICT_
end_define
begin_comment
comment|/*  * ``Library-private'' Support for the Predictor Tag  */
end_comment
begin_comment
comment|/*  * Codecs that want to support the Predictor tag must place  * this structure first in their private state block so that  * the predictor code can cast tif_data to find its state.  */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|predictor
name|int
name|predictor
decl_stmt|;
comment|/* predictor tag value */
DECL|member|stride
name|int
name|stride
decl_stmt|;
comment|/* sample stride over data */
DECL|member|rowsize
name|tsize_t
name|rowsize
decl_stmt|;
comment|/* tile/strip row size */
DECL|member|encoderow
name|TIFFCodeMethod
name|encoderow
decl_stmt|;
comment|/* parent codec encode/decode row */
DECL|member|encodestrip
name|TIFFCodeMethod
name|encodestrip
decl_stmt|;
comment|/* parent codec encode/decode strip */
DECL|member|encodetile
name|TIFFCodeMethod
name|encodetile
decl_stmt|;
comment|/* parent codec encode/decode tile */
DECL|member|encodepfunc
name|TIFFPostMethod
name|encodepfunc
decl_stmt|;
comment|/* horizontal differencer */
DECL|member|decoderow
name|TIFFCodeMethod
name|decoderow
decl_stmt|;
comment|/* parent codec encode/decode row */
DECL|member|decodestrip
name|TIFFCodeMethod
name|decodestrip
decl_stmt|;
comment|/* parent codec encode/decode strip */
DECL|member|decodetile
name|TIFFCodeMethod
name|decodetile
decl_stmt|;
comment|/* parent codec encode/decode tile */
DECL|member|decodepfunc
name|TIFFPostMethod
name|decodepfunc
decl_stmt|;
comment|/* horizontal accumulator */
DECL|member|vgetparent
name|TIFFVGetMethod
name|vgetparent
decl_stmt|;
comment|/* super-class method */
DECL|member|vsetparent
name|TIFFVSetMethod
name|vsetparent
decl_stmt|;
comment|/* super-class method */
DECL|member|printdir
name|TIFFPrintMethod
name|printdir
decl_stmt|;
comment|/* super-class method */
DECL|member|setupdecode
name|TIFFBoolMethod
name|setupdecode
decl_stmt|;
comment|/* super-class method */
DECL|member|setupencode
name|TIFFBoolMethod
name|setupencode
decl_stmt|;
comment|/* super-class method */
block|}
DECL|typedef|TIFFPredictorState
name|TIFFPredictorState
typedef|;
end_typedef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
specifier|extern
name|int
name|TIFFPredictorInit
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
specifier|extern
name|int
name|TIFFPredictorCleanup
parameter_list|(
name|TIFF
modifier|*
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _TIFFPREDICT_ */
end_comment
begin_comment
comment|/* vim: set ts=8 sts=8 sw=8 noet: */
end_comment
end_unit
