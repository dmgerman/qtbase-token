begin_unit
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *             For conditions of distribution and use,                    * */
end_comment
begin_comment
comment|/* *                see copyright notice in libmng.h                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * project   : libmng                                                     * */
end_comment
begin_comment
comment|/* * file      : libmng_error.c            copyright (c) 2000-2007 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.10                                                     * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : Error routines (implementation)                            * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * author    : G.Juyn                                                     * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * comment   : implementation of the general error handling routines      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * changes   : 0.5.1 - 05/08/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed strict-ANSI stuff                                * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/23/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added error telltaling                                   * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/30/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorstrings for delta-image processing            * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/31/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed up punctuation (contributed by Tim Rowley)         * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/06/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorstring for delayed buffer-processing          * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/06/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added MNG_NEEDTIMERWAIT errorstring                      * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/15/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added NEEDSECTIONWAIT errorstring                        * */
end_comment
begin_comment
comment|/* *             - added macro + routine to set returncode without          * */
end_comment
begin_comment
comment|/* *               calling error callback                                   * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/19/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorstring for updatemngheader if not a MNG       * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.2 - 08/05/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed file-prefixes                                    * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.3 - 08/09/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added check for simplicity-bits in MHDR                  * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/11/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed processing of unknown critical chunks              * */
end_comment
begin_comment
comment|/* *             - added support for nEED                                   * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/20/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorcode for delayed delta-processing             * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.4 - 01/18/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorcode for MAGN methods                         * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.2 - 06/23/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added optimization option for MNG-video playback         * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.5 - 07/04/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorcode for extreme chunk-sizes                  * */
end_comment
begin_comment
comment|/* *             1.0.5 - 08/15/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - completed delta-image support                            * */
end_comment
begin_comment
comment|/* *             1.0.5 - 08/19/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B597134 - libmng pollutes the linker namespace           * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/14/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added event handling for dynamic MNG                     * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/15/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed LOOP iteration=0 special case                      * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/19/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - warnings are ignored by default now!                     * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/20/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added support for PAST                                   * */
end_comment
begin_comment
comment|/* *             1.0.5 - 10/07/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added check for TERM placement during create/write       * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.6 - 07/07/2003 - G. R-P                                * */
end_comment
begin_comment
comment|/* *             - added MNG_SKIPCHUNK_CHNK, MNG_NO_DELTA_PNG reductions.   * */
end_comment
begin_comment
comment|/* *             - skipped more code when MNG_INCLUDE_JNG is not enabled.   * */
end_comment
begin_comment
comment|/* *             1.0.6 - 07/29/2003 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added conditional around evNT chunk support              * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.7 - 03/24/2004 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - fixed typo on SKIPCHUNK_evNT (->PAST)                    * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.9 - 12/20/2004 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - cleaned up macro-invocations (thanks to D. Airlie)       * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.10 - 04/08/2007 - G.Juyn                               * */
end_comment
begin_comment
comment|/* *             - added support for mPNG proposal                          * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_include
include|#
directive|include
file|"libmng.h"
end_include
begin_include
include|#
directive|include
file|"libmng_data.h"
end_include
begin_include
include|#
directive|include
file|"libmng_error.h"
end_include
begin_include
include|#
directive|include
file|"libmng_trace.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|__BORLANDC__
end_ifdef
begin_pragma
pragma|#
directive|pragma
name|hdrstop
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|MNG_STRICT_ANSI
argument_list|)
end_if
begin_pragma
pragma|#
directive|pragma
name|option
name|-
name|A
end_pragma
begin_comment
comment|/* force ANSI-C */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_INCLUDE_ERROR_STRINGS
end_ifdef
begin_decl_stmt
DECL|variable|error_table
name|MNG_LOCAL
name|mng_error_entry
specifier|const
name|error_table
index|[]
init|=
block|{
block|{
name|MNG_NOERROR
block|,
literal|"No error"
block|}
block|,
block|{
name|MNG_OUTOFMEMORY
block|,
literal|"Out of memory"
block|}
block|,
block|{
name|MNG_INVALIDHANDLE
block|,
literal|"The handle is invalid"
block|}
block|,
block|{
name|MNG_NOCALLBACK
block|,
literal|"A required callback is not defined"
block|}
block|,
block|{
name|MNG_UNEXPECTEDEOF
block|,
literal|"Encountered unexpected end-of-file"
block|}
block|,
block|{
name|MNG_ZLIBERROR
block|,
literal|"zlib encountered an error"
block|}
block|,
ifdef|#
directive|ifdef
name|MNG_INCLUDE_JNG
block|{
name|MNG_JPEGERROR
block|,
literal|"ijgsrc6b encountered an error"
block|}
block|,
endif|#
directive|endif
block|{
name|MNG_LCMSERROR
block|,
literal|"lcms encountered an error"
block|}
block|,
block|{
name|MNG_NOOUTPUTPROFILE
block|,
literal|"No output-profile defined for CMS"
block|}
block|,
block|{
name|MNG_NOSRGBPROFILE
block|,
literal|"No sRGB-profile defined for CMS"
block|}
block|,
block|{
name|MNG_BUFOVERFLOW
block|,
literal|"Internal buffer-overflow"
block|}
block|,
block|{
name|MNG_FUNCTIONINVALID
block|,
literal|"Function is invalid at this point"
block|}
block|,
block|{
name|MNG_OUTPUTERROR
block|,
literal|"Writing was unsuccessful; disk full?"
block|}
block|,
block|{
name|MNG_JPEGBUFTOOSMALL
block|,
literal|"Internal buffer for JPEG processing too small"
block|}
block|,
block|{
name|MNG_NEEDMOREDATA
block|,
literal|"Reading suspended; waiting for I/O to catch up"
block|}
block|,
block|{
name|MNG_NEEDTIMERWAIT
block|,
literal|"Timer suspension; normal animation delay"
block|}
block|,
block|{
name|MNG_NEEDSECTIONWAIT
block|,
literal|"SEEK suspension; application decides"
block|}
block|,
block|{
name|MNG_LOOPWITHCACHEOFF
block|,
literal|"LOOP encountered when playback cache is turned off"
block|}
block|,
block|{
name|MNG_APPIOERROR
block|,
literal|"Application signalled I/O error"
block|}
block|,
block|{
name|MNG_APPTIMERERROR
block|,
literal|"Application signalled timing error"
block|}
block|,
block|{
name|MNG_APPCMSERROR
block|,
literal|"Application signalled CMS error"
block|}
block|,
block|{
name|MNG_APPMISCERROR
block|,
literal|"Application signalled an error"
block|}
block|,
block|{
name|MNG_APPTRACEABORT
block|,
literal|"Application signalled error during trace-callback"
block|}
block|,
block|{
name|MNG_INTERNALERROR
block|,
literal|"Internal error in libmng"
block|}
block|,
block|{
name|MNG_INVALIDSIG
block|,
literal|"The signature is invalid"
block|}
block|,
block|{
name|MNG_INVALIDCRC
block|,
literal|"The CRC for this chunk is invalid"
block|}
block|,
block|{
name|MNG_INVALIDLENGTH
block|,
literal|"Chunk-length is invalid"
block|}
block|,
block|{
name|MNG_SEQUENCEERROR
block|,
literal|"Chunk out of sequence"
block|}
block|,
block|{
name|MNG_CHUNKNOTALLOWED
block|,
literal|"Chunk not allowed at this point"
block|}
block|,
block|{
name|MNG_MULTIPLEERROR
block|,
literal|"Chunk cannot occur multiple times"
block|}
block|,
block|{
name|MNG_PLTEMISSING
block|,
literal|"Missing PLTE chunk"
block|}
block|,
block|{
name|MNG_IDATMISSING
block|,
literal|"Missing IDAT chunk(s)"
block|}
block|,
block|{
name|MNG_CANNOTBEEMPTY
block|,
literal|"Chunk cannot be empty"
block|}
block|,
block|{
name|MNG_GLOBALLENGTHERR
block|,
literal|"Global data length invalid"
block|}
block|,
block|{
name|MNG_INVALIDBITDEPTH
block|,
literal|"The bit_depth is invalid"
block|}
block|,
block|{
name|MNG_INVALIDCOLORTYPE
block|,
literal|"The color_type is invalid"
block|}
block|,
block|{
name|MNG_INVALIDCOMPRESS
block|,
literal|"The compression_method is invalid"
block|}
block|,
block|{
name|MNG_INVALIDFILTER
block|,
literal|"The filter_method or filter_type is invalid"
block|}
block|,
block|{
name|MNG_INVALIDINTERLACE
block|,
literal|"The interlace_method is invalid"
block|}
block|,
block|{
name|MNG_NOTENOUGHIDAT
block|,
literal|"There is not enough data in the IDAT chunk(s)"
block|}
block|,
block|{
name|MNG_PLTEINDEXERROR
block|,
literal|"Palette-index out of bounds"
block|}
block|,
block|{
name|MNG_NULLNOTFOUND
block|,
literal|"NULL separator not found"
block|}
block|,
block|{
name|MNG_KEYWORDNULL
block|,
literal|"Keyword cannot be zero-length"
block|}
block|,
block|{
name|MNG_OBJECTUNKNOWN
block|,
literal|"Object does not exist"
block|}
block|,
block|{
name|MNG_OBJECTEXISTS
block|,
literal|"Object already exists"
block|}
block|,
block|{
name|MNG_TOOMUCHIDAT
block|,
literal|"Too much data in IDAT chunk(s)"
block|}
block|,
block|{
name|MNG_INVSAMPLEDEPTH
block|,
literal|"The sample_depth is invalid"
block|}
block|,
block|{
name|MNG_INVOFFSETSIZE
block|,
literal|"The offset_type is invalid"
block|}
block|,
block|{
name|MNG_INVENTRYTYPE
block|,
literal|"The entry_type is invalid"
block|}
block|,
block|{
name|MNG_ENDWITHNULL
block|,
literal|"Chunk must not end with NULL byte"
block|}
block|,
block|{
name|MNG_INVIMAGETYPE
block|,
literal|"The image_type is invalid"
block|}
block|,
ifndef|#
directive|ifndef
name|MNG_NO_DELTA_PNG
block|{
name|MNG_INVDELTATYPE
block|,
literal|"The delta_type is invalid"
block|}
block|,
endif|#
directive|endif
block|{
name|MNG_INVALIDINDEX
block|,
literal|"Index-value out of bounds"
block|}
block|,
ifdef|#
directive|ifdef
name|MNG_INCLUDE_JNG
block|{
name|MNG_TOOMUCHJDAT
block|,
literal|"Too much data in JDAT chunk(s)"
block|}
block|,
block|{
name|MNG_JPEGPARMSERR
block|,
literal|"JHDR parameters& JFIF-data do not match"
block|}
block|,
endif|#
directive|endif
block|{
name|MNG_INVFILLMETHOD
block|,
literal|"The fill_method is invalid"
block|}
block|,
ifndef|#
directive|ifndef
name|MNG_NO_DELTA_PNG
block|{
name|MNG_OBJNOTCONCRETE
block|,
literal|"Target object for DHDR must be concrete"
block|}
block|,
endif|#
directive|endif
block|{
name|MNG_TARGETNOALPHA
block|,
literal|"Target object must have alpha-channel"
block|}
block|,
block|{
name|MNG_MNGTOOCOMPLEX
block|,
literal|"MHDR simplicity indicates unsupported feature(s)"
block|}
block|,
block|{
name|MNG_UNKNOWNCRITICAL
block|,
literal|"Unknown critical chunk encountered"
block|}
block|,
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_nEED
block|{
name|MNG_UNSUPPORTEDNEED
block|,
literal|"Requested nEED resources are not supported"
block|}
block|,
endif|#
directive|endif
block|{
name|MNG_INVALIDDELTA
block|,
literal|"The delta operation is invalid (mismatched color_types?)"
block|}
block|,
block|{
name|MNG_INVALIDMETHOD
block|,
literal|"Method is invalid"
block|}
block|,
block|{
name|MNG_IMPROBABLELENGTH
block|,
literal|"Chunklength is incredibly large"
block|}
block|,
block|{
name|MNG_INVALIDBLOCK
block|,
literal|"Delta block width and or height invalid"
block|}
block|,
block|{
name|MNG_INVALIDEVENT
block|,
literal|"Event type is invalid"
block|}
block|,
block|{
name|MNG_INVALIDMASK
block|,
literal|"Mask type is invalid"
block|}
block|,
block|{
name|MNG_NOMATCHINGLOOP
block|,
literal|"ENDL without matching LOOP"
block|}
block|,
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_evNT
block|{
name|MNG_SEEKNOTFOUND
block|,
literal|"evNT points to unknown SEEK"
block|}
block|,
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_PAST
block|{
name|MNG_OBJNOTABSTRACT
block|,
literal|"Destination object for PAST must be abstract"
block|}
block|,
endif|#
directive|endif
block|{
name|MNG_TERMSEQERROR
block|,
literal|"TERM misplaced during creation of MNG stream"
block|}
block|,
block|{
name|MNG_INVALIDFIELDVAL
block|,
literal|"invalid fieldvalue (generic)"
block|}
block|,
block|{
name|MNG_INVALIDWIDTH
block|,
literal|"invalid frame/image width"
block|}
block|,
block|{
name|MNG_INVALIDHEIGHT
block|,
literal|"invalid frame/image height"
block|}
block|,
block|{
name|MNG_INVALIDCNVSTYLE
block|,
literal|"Canvas_style is invalid"
block|}
block|,
block|{
name|MNG_WRONGCHUNK
block|,
literal|"Attempt to access the wrong chunk"
block|}
block|,
block|{
name|MNG_INVALIDENTRYIX
block|,
literal|"Attempt to access an non-existing entry"
block|}
block|,
block|{
name|MNG_NOHEADER
block|,
literal|"No valid header-chunk"
block|}
block|,
block|{
name|MNG_NOCORRCHUNK
block|,
literal|"Parent chunk not found"
block|}
block|,
block|{
name|MNG_NOMHDR
block|,
literal|"No MNG header (MHDR) found"
block|}
block|,
block|{
name|MNG_IMAGETOOLARGE
block|,
literal|"Image is larger than defined maximum"
block|}
block|,
block|{
name|MNG_NOTANANIMATION
block|,
literal|"Image is not an animation"
block|}
block|,
block|{
name|MNG_FRAMENRTOOHIGH
block|,
literal|"Framenr out of bounds"
block|}
block|,
block|{
name|MNG_LAYERNRTOOHIGH
block|,
literal|"Layernr out of bounds"
block|}
block|,
block|{
name|MNG_PLAYTIMETOOHIGH
block|,
literal|"Playtime out of bounds"
block|}
block|,
block|{
name|MNG_FNNOTIMPLEMENTED
block|,
literal|"Function not yet implemented"
block|}
block|,
block|{
name|MNG_IMAGEFROZEN
block|,
literal|"Image is frozen"
block|}
block|,
block|{
name|MNG_LCMS_NOHANDLE
block|,
literal|"Handle could not be initialized"
block|}
block|,
block|{
name|MNG_LCMS_NOMEM
block|,
literal|"No memory for gamma-table(s)"
block|}
block|,
block|{
name|MNG_LCMS_NOTRANS
block|,
literal|"Transformation could not be initialized"
block|}
block|}
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* MNG_INCLUDE_ERROR_STRINGS */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_function
DECL|function|mng_store_error
name|mng_bool
name|mng_store_error
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_retcode
name|iError
parameter_list|,
name|mng_retcode
name|iExtra1
parameter_list|,
name|mng_retcode
name|iExtra2
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MNG_SUPPORT_TRACE
name|MNG_TRACEB
argument_list|(
name|pData
argument_list|,
name|MNG_FN_STORE_ERROR
argument_list|,
name|MNG_LC_START
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|pData
operator|!=
literal|0
condition|)
block|{
name|pData
operator|->
name|iErrorcode
operator|=
name|iError
expr_stmt|;
comment|/* save also for getlasterror */
name|pData
operator|->
name|iErrorx1
operator|=
name|iExtra1
expr_stmt|;
name|pData
operator|->
name|iErrorx2
operator|=
name|iExtra2
expr_stmt|;
ifdef|#
directive|ifdef
name|MNG_INCLUDE_ERROR_STRINGS
block|{
comment|/* binary search variables */
name|mng_int32
name|iTop
decl_stmt|,
name|iLower
decl_stmt|,
name|iUpper
decl_stmt|,
name|iMiddle
decl_stmt|;
name|mng_error_entryp
name|pEntry
decl_stmt|;
comment|/* pointer to found entry */
comment|/* determine max index of table */
name|iTop
operator|=
operator|(
sizeof|sizeof
argument_list|(
name|error_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|error_table
index|[
literal|0
index|]
argument_list|)
operator|)
operator|-
literal|1
expr_stmt|;
name|iLower
operator|=
literal|0
expr_stmt|;
comment|/* initialize binary search */
name|iMiddle
operator|=
name|iTop
operator|>>
literal|1
expr_stmt|;
comment|/* start in the middle */
name|iUpper
operator|=
name|iTop
expr_stmt|;
name|pEntry
operator|=
literal|0
expr_stmt|;
comment|/* no goods yet! */
do|do
comment|/* the binary search itself */
block|{
if|if
condition|(
name|error_table
index|[
name|iMiddle
index|]
operator|.
name|iError
operator|<
name|iError
condition|)
name|iLower
operator|=
name|iMiddle
operator|+
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|error_table
index|[
name|iMiddle
index|]
operator|.
name|iError
operator|>
name|iError
condition|)
name|iUpper
operator|=
name|iMiddle
operator|-
literal|1
expr_stmt|;
else|else
block|{
name|pEntry
operator|=
operator|&
name|error_table
index|[
name|iMiddle
index|]
expr_stmt|;
break|break;
block|}
name|iMiddle
operator|=
operator|(
name|iLower
operator|+
name|iUpper
operator|)
operator|>>
literal|1
expr_stmt|;
block|}
do|while
condition|(
name|iLower
operator|<=
name|iUpper
condition|)
do|;
if|if
condition|(
name|pEntry
condition|)
comment|/* found it ? */
name|pData
operator|->
name|zErrortext
operator|=
name|pEntry
operator|->
name|zErrortext
expr_stmt|;
else|else
name|pData
operator|->
name|zErrortext
operator|=
literal|"Unknown error"
expr_stmt|;
block|}
else|#
directive|else
comment|/* MNG_INCLUDE_ERROR_STRINGS */
name|pData
operator|->
name|zErrortext
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
comment|/* MNG_INCLUDE_ERROR_STRINGS */
if|if
condition|(
name|iError
operator|==
literal|0
condition|)
comment|/* no error is not severe ! */
block|{
name|pData
operator|->
name|iSeverity
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|iError
operator|&
literal|0x3C00
condition|)
comment|/* determine the severity */
block|{
case|case
literal|0x0800
case|:
block|{
name|pData
operator|->
name|iSeverity
operator|=
literal|5
expr_stmt|;
break|break;
block|}
case|case
literal|0x1000
case|:
block|{
name|pData
operator|->
name|iSeverity
operator|=
literal|2
expr_stmt|;
break|break;
block|}
case|case
literal|0x2000
case|:
block|{
name|pData
operator|->
name|iSeverity
operator|=
literal|1
expr_stmt|;
break|break;
block|}
default|default     :
block|{
name|pData
operator|->
name|iSeverity
operator|=
literal|9
expr_stmt|;
block|}
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|MNG_SUPPORT_TRACE
name|MNG_TRACEB
argument_list|(
name|pData
argument_list|,
name|MNG_FN_STORE_ERROR
argument_list|,
name|MNG_LC_END
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|MNG_TRUE
return|;
block|}
end_function
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_function
DECL|function|mng_process_error
name|mng_bool
name|mng_process_error
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_retcode
name|iError
parameter_list|,
name|mng_retcode
name|iExtra1
parameter_list|,
name|mng_retcode
name|iExtra2
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|MNG_SUPPORT_TRACE
name|MNG_TRACEB
argument_list|(
name|pData
argument_list|,
name|MNG_FN_PROCESS_ERROR
argument_list|,
name|MNG_LC_START
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|mng_store_error
argument_list|(
name|pData
argument_list|,
name|iError
argument_list|,
name|iExtra1
argument_list|,
name|iExtra2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|pData
operator|!=
name|MNG_NULL
operator|)
operator|&&
operator|(
name|pData
operator|->
name|iMagic
operator|==
name|MNG_MAGIC
operator|)
condition|)
block|{
if|if
condition|(
name|pData
operator|->
name|fErrorproc
condition|)
comment|/* callback defined ? */
return|return
name|pData
operator|->
name|fErrorproc
argument_list|(
operator|(
operator|(
name|mng_handle
operator|)
name|pData
operator|)
argument_list|,
name|iError
argument_list|,
name|pData
operator|->
name|iSeverity
argument_list|,
name|pData
operator|->
name|iChunkname
argument_list|,
name|pData
operator|->
name|iChunkseq
argument_list|,
name|pData
operator|->
name|iErrorx1
argument_list|,
name|pData
operator|->
name|iErrorx2
argument_list|,
name|pData
operator|->
name|zErrortext
argument_list|)
return|;
block|}
ifdef|#
directive|ifdef
name|MNG_SUPPORT_TRACE
name|MNG_TRACEB
argument_list|(
name|pData
argument_list|,
name|MNG_FN_PROCESS_ERROR
argument_list|,
name|MNG_LC_END
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|MNG_TRUE
return|;
comment|/* warnings are ignored by default ! */
block|}
end_function
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* * end of file                                                            * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
end_unit
