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
comment|/* * file      : libmng_data.h             copyright (c) 2000-2007 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.10                                                     * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : main data structure definition                             * */
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
comment|/* * comment   : Definition of the library main data structure              * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * changes   : 0.5.1 - 05/04/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added CRC table to main structure (for thread-safety)    * */
end_comment
begin_comment
comment|/* *             0.5.1 - 05/06/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added iPLTEentries for checking hIST-length              * */
end_comment
begin_comment
comment|/* *             0.5.1 - 05/08/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed palette definition to exported palette-type      * */
end_comment
begin_comment
comment|/* *             - removed frozen indicator                                 * */
end_comment
begin_comment
comment|/* *             - added create/write indicators                            * */
end_comment
begin_comment
comment|/* *             - changed strict-ANSI stuff                                * */
end_comment
begin_comment
comment|/* *             0.5.1 - 05/13/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added eMNGma hack (will be removed in 1.0.0 !!!)         * */
end_comment
begin_comment
comment|/* *             - added TERM animation object pointer (easier reference)   * */
end_comment
begin_comment
comment|/* *             - added saved-data structure for SAVE/SEEK processing      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/18/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added fields for JNG support (IJG-based)                 * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/24/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed global tRNS definition                           * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/30/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added delta-image fields                                 * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/01/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added internal delta-image processing callbacks          * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/02/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed SWAP_ENDIAN to BIGENDIAN_SUPPORTED               * */
end_comment
begin_comment
comment|/* *               (contributed by Tim Rowley)                              * */
end_comment
begin_comment
comment|/* *             - added getalphaline callback for RGB8_A8 canvasstyle      * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/06/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added parameter for delayed buffer-processing            * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.5.3 - 06/16/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added update-region parms for refresh calback            * */
end_comment
begin_comment
comment|/* *             - added Needrefresh parameter                              * */
end_comment
begin_comment
comment|/* *             0.5.3 - 06/17/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added Deltaimmediate parm for faster delta-processing    * */
end_comment
begin_comment
comment|/* *             0.5.3 - 06/21/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added Speed parameter to facilitate testing              * */
end_comment
begin_comment
comment|/* *             - added Imagelevel parameter for processtext callback      * */
end_comment
begin_comment
comment|/* *             0.5.3 - 06/26/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed userdata variable to mng_ptr                     * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/07/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added variables for go_xxxx processing                   * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/08/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added variables for improved timing support              * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/15/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added callbacks for SAVE/SEEK processing                 * */
end_comment
begin_comment
comment|/* *             - added variable for NEEDSECTIONWAIT breaks                * */
end_comment
begin_comment
comment|/* *             - added variable for freeze& reset processing             * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/17/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed suspension-buffering for 32K+ chunks               * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.2 - 07/29/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - removed Nextbackxxx fields (no longer used)              * */
end_comment
begin_comment
comment|/* *             0.9.2 - 07/31/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed wrapping of suspension parameters                  * */
end_comment
begin_comment
comment|/* *             0.9.2 - 08/04/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B111096 - fixed large-buffer read-suspension             * */
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
comment|/* *             0.9.3 - 08/26/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added MAGN chunk                                         * */
end_comment
begin_comment
comment|/* *             0.9.3 - 09/07/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added support for new filter_types                       * */
end_comment
begin_comment
comment|/* *             0.9.3 - 09/10/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed DEFI behavior                                      * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/10/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added support for alpha-depth prediction                 * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/11/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added support for nEED                                   * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/16/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added optional support for bKGD for PNG images           * */
end_comment
begin_comment
comment|/* *             - added support for JDAA                                   * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/17/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added callback to process non-critical unknown chunks    * */
end_comment
begin_comment
comment|/* *             - fixed support for bKGD                                   * */
end_comment
begin_comment
comment|/* *             0.9.3 - 10/19/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - implemented delayed delta-processing                     * */
end_comment
begin_comment
comment|/* *             0.9.4 - 12/16/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed mixup of data-& function-pointers (thanks Dimitri)* */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.1 - 02/08/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added MEND processing callback                           * */
end_comment
begin_comment
comment|/* *             1.0.1 - 02/13/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed first FRAM_MODE=4 timing problem                   * */
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
comment|/* *             - added processterm callback                               * */
end_comment
begin_comment
comment|/* *             1.0.2 - 06/25/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added option to turn off progressive refresh             * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.5 - 07/08/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B578572 - removed eMNGma hack (thanks Dimitri!)          * */
end_comment
begin_comment
comment|/* *             1.0.5 - 07/16/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B581625 - large chunks fail with suspension reads        * */
end_comment
begin_comment
comment|/* *             1.0.5 - 08/15/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - completed PROM support                                   * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/15/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed LOOP iteration=0 special case                      * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/20/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - finished support for BACK image& tiling                 * */
end_comment
begin_comment
comment|/* *             1.0.5 - 10/07/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added another fix for misplaced TERM chunk               * */
end_comment
begin_comment
comment|/* *             - completed support for condition=2 in TERM chunk          * */
end_comment
begin_comment
comment|/* *             1.0.5 - 10/20/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - fixed processing for multiple objects in MAGN            * */
end_comment
begin_comment
comment|/* *             - fixed display of visible target of PAST operation        * */
end_comment
begin_comment
comment|/* *             1.0.5 - 11/07/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added support to get totals after mng_read()             * */
end_comment
begin_comment
comment|/* *             1.0.5 - 24/02/2003 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B683152 - libjpeg suspension not always honored correctly* */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.6 - 04/11/2003 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B719420 - fixed several MNG_APP_CMS problems             * */
end_comment
begin_comment
comment|/* *             1.0.6 - 07/05/2003 - G. R-P                                * */
end_comment
begin_comment
comment|/* *             - optionally use zlib's crc32() function                   * */
end_comment
begin_comment
comment|/* *             1.0.6 - 07/29/2003 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added SKIPCHUNK conditionals around PAST chunk support   * */
end_comment
begin_comment
comment|/* *             1.0.6 - 08/17/2003 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added iPNGdepth member to pData structure                * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.7 - 03/10/2004 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added conditionals around openstream/closestream         * */
end_comment
begin_comment
comment|/* *             1.0.7 - 03/24/2004 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added more SKIPCHUNK conditionals                        * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.8 - 04/02/2004 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added CRC existence& checking flags                     * */
end_comment
begin_comment
comment|/* *             1.0.8 - 04/10/2004 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added data-push mechanisms for specialized decoders      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.9 - 12/11/2004 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added conditional MNG_OPTIMIZE_DISPLAYCALLS              * */
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
comment|/* *             1.0.10 - 04/12/2007 - G.Juyn                               * */
end_comment
begin_comment
comment|/* *             - added support for ANG proposal                           * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
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
begin_ifndef
ifndef|#
directive|ifndef
name|_libmng_data_h_
end_ifndef
begin_define
DECL|macro|_libmng_data_h_
define|#
directive|define
name|_libmng_data_h_
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_define
DECL|macro|MNG_MAGIC
define|#
directive|define
name|MNG_MAGIC
value|0x52530a0aL
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Internal structures                                                    * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_typedef
DECL|typedef|mng_rgbpaltab
typedef|typedef
name|mng_palette8
name|mng_rgbpaltab
typedef|;
end_typedef
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * The saved_data structure                                               * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * This contains the saved data after a SAVE chunk has been processed.    * */
end_comment
begin_comment
comment|/* * The data is saved from the main data structure during SAVE processing, * */
end_comment
begin_comment
comment|/* * and restored to the main data structure during SEEK processing.        * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_typedef
DECL|struct|mng_savedata_struct
typedef|typedef
struct|struct
name|mng_savedata_struct
block|{
if|#
directive|if
name|defined
argument_list|(
name|MNG_SUPPORT_READ
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_SUPPORT_WRITE
argument_list|)
DECL|member|bHasglobalPLTE
name|mng_bool
name|bHasglobalPLTE
decl_stmt|;
comment|/* global PLTE chunk processed */
DECL|member|bHasglobalTRNS
name|mng_bool
name|bHasglobalTRNS
decl_stmt|;
comment|/* global tRNS chunk processed */
DECL|member|bHasglobalGAMA
name|mng_bool
name|bHasglobalGAMA
decl_stmt|;
comment|/* global gAMA chunk processed */
DECL|member|bHasglobalCHRM
name|mng_bool
name|bHasglobalCHRM
decl_stmt|;
comment|/* global cHRM chunk processed */
DECL|member|bHasglobalSRGB
name|mng_bool
name|bHasglobalSRGB
decl_stmt|;
comment|/* global sRGB chunk processed */
DECL|member|bHasglobalICCP
name|mng_bool
name|bHasglobalICCP
decl_stmt|;
comment|/* global iCCP chunk processed */
DECL|member|bHasglobalBKGD
name|mng_bool
name|bHasglobalBKGD
decl_stmt|;
comment|/* global bKGD chunk processed */
endif|#
directive|endif
comment|/* MNG_SUPPORT_READ || MNG_SUPPORT_WRITE */
ifdef|#
directive|ifdef
name|MNG_SUPPORT_DISPLAY
DECL|member|iBACKred
name|mng_uint16
name|iBACKred
decl_stmt|;
comment|/* BACK fields */
DECL|member|iBACKgreen
name|mng_uint16
name|iBACKgreen
decl_stmt|;
DECL|member|iBACKblue
name|mng_uint16
name|iBACKblue
decl_stmt|;
DECL|member|iBACKmandatory
name|mng_uint8
name|iBACKmandatory
decl_stmt|;
DECL|member|iBACKimageid
name|mng_uint16
name|iBACKimageid
decl_stmt|;
DECL|member|iBACKtile
name|mng_uint8
name|iBACKtile
decl_stmt|;
DECL|member|iFRAMmode
name|mng_uint8
name|iFRAMmode
decl_stmt|;
comment|/* FRAM fields (global) */
DECL|member|iFRAMdelay
name|mng_uint32
name|iFRAMdelay
decl_stmt|;
DECL|member|iFRAMtimeout
name|mng_uint32
name|iFRAMtimeout
decl_stmt|;
DECL|member|bFRAMclipping
name|mng_bool
name|bFRAMclipping
decl_stmt|;
DECL|member|iFRAMclipl
name|mng_int32
name|iFRAMclipl
decl_stmt|;
DECL|member|iFRAMclipr
name|mng_int32
name|iFRAMclipr
decl_stmt|;
DECL|member|iFRAMclipt
name|mng_int32
name|iFRAMclipt
decl_stmt|;
DECL|member|iFRAMclipb
name|mng_int32
name|iFRAMclipb
decl_stmt|;
DECL|member|iGlobalPLTEcount
name|mng_uint32
name|iGlobalPLTEcount
decl_stmt|;
comment|/* global PLTE fields */
DECL|member|aGlobalPLTEentries
name|mng_rgbpaltab
name|aGlobalPLTEentries
decl_stmt|;
DECL|member|iGlobalTRNSrawlen
name|mng_uint32
name|iGlobalTRNSrawlen
decl_stmt|;
comment|/* global tRNS fields */
DECL|member|aGlobalTRNSrawdata
name|mng_uint8arr
name|aGlobalTRNSrawdata
decl_stmt|;
DECL|member|iGlobalGamma
name|mng_uint32
name|iGlobalGamma
decl_stmt|;
comment|/* global gAMA fields */
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_cHRM
DECL|member|iGlobalWhitepointx
name|mng_uint32
name|iGlobalWhitepointx
decl_stmt|;
comment|/* global cHRM fields */
DECL|member|iGlobalWhitepointy
name|mng_uint32
name|iGlobalWhitepointy
decl_stmt|;
DECL|member|iGlobalPrimaryredx
name|mng_uint32
name|iGlobalPrimaryredx
decl_stmt|;
DECL|member|iGlobalPrimaryredy
name|mng_uint32
name|iGlobalPrimaryredy
decl_stmt|;
DECL|member|iGlobalPrimarygreenx
name|mng_uint32
name|iGlobalPrimarygreenx
decl_stmt|;
DECL|member|iGlobalPrimarygreeny
name|mng_uint32
name|iGlobalPrimarygreeny
decl_stmt|;
DECL|member|iGlobalPrimarybluex
name|mng_uint32
name|iGlobalPrimarybluex
decl_stmt|;
DECL|member|iGlobalPrimarybluey
name|mng_uint32
name|iGlobalPrimarybluey
decl_stmt|;
endif|#
directive|endif
DECL|member|iGlobalRendintent
name|mng_uint8
name|iGlobalRendintent
decl_stmt|;
comment|/* global sRGB fields */
DECL|member|iGlobalProfilesize
name|mng_uint32
name|iGlobalProfilesize
decl_stmt|;
comment|/* global iCCP fields */
DECL|member|pGlobalProfile
name|mng_ptr
name|pGlobalProfile
decl_stmt|;
DECL|member|iGlobalBKGDred
name|mng_uint16
name|iGlobalBKGDred
decl_stmt|;
comment|/* global bKGD fields */
DECL|member|iGlobalBKGDgreen
name|mng_uint16
name|iGlobalBKGDgreen
decl_stmt|;
DECL|member|iGlobalBKGDblue
name|mng_uint16
name|iGlobalBKGDblue
decl_stmt|;
endif|#
directive|endif
comment|/* MNG_SUPPORT_DISPLAY */
block|}
DECL|typedef|mng_savedata
name|mng_savedata
typedef|;
end_typedef
begin_typedef
DECL|typedef|mng_savedatap
typedef|typedef
name|mng_savedata
modifier|*
name|mng_savedatap
typedef|;
end_typedef
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Internal buffer structure for data push mechanisms                     * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|pNext
name|mng_ptr
name|pNext
decl_stmt|;
comment|/* for linked list */
DECL|member|pData
name|mng_ptr
name|pData
decl_stmt|;
comment|/* used for chunks& data */
DECL|member|iLength
name|mng_uint32
name|iLength
decl_stmt|;
DECL|member|bOwned
name|mng_bool
name|bOwned
decl_stmt|;
DECL|member|pDatanext
name|mng_uint8p
name|pDatanext
decl_stmt|;
comment|/* only used for data */
DECL|member|iRemaining
name|mng_uint32
name|iRemaining
decl_stmt|;
block|}
DECL|typedef|mng_pushdata
name|mng_pushdata
typedef|;
end_typedef
begin_typedef
DECL|typedef|mng_pushdatap
typedef|typedef
name|mng_pushdata
modifier|*
name|mng_pushdatap
typedef|;
end_typedef
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * The main libmng data structure                                         * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * The handle used in all functions points to this structure which        * */
end_comment
begin_comment
comment|/* * contains all volatile data necessary to process the network graphic.   * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_typedef
DECL|struct|mng_data_struct
typedef|typedef
struct|struct
name|mng_data_struct
block|{
DECL|member|iMagic
name|mng_uint32
name|iMagic
decl_stmt|;
comment|/* magic number to validate                                                     a given handle */
DECL|member|pUserdata
name|mng_ptr
name|pUserdata
decl_stmt|;
comment|/* application workdata */
DECL|member|eSigtype
name|mng_imgtype
name|eSigtype
decl_stmt|;
comment|/* image information */
DECL|member|eImagetype
name|mng_imgtype
name|eImagetype
decl_stmt|;
comment|/* initially zeroed */
DECL|member|iWidth
name|mng_uint32
name|iWidth
decl_stmt|;
comment|/* filled after header is processed */
DECL|member|iHeight
name|mng_uint32
name|iHeight
decl_stmt|;
DECL|member|iTicks
name|mng_uint32
name|iTicks
decl_stmt|;
comment|/* these only after MHDR */
DECL|member|iLayercount
name|mng_uint32
name|iLayercount
decl_stmt|;
DECL|member|iFramecount
name|mng_uint32
name|iFramecount
decl_stmt|;
DECL|member|iPlaytime
name|mng_uint32
name|iPlaytime
decl_stmt|;
DECL|member|iSimplicity
name|mng_uint32
name|iSimplicity
decl_stmt|;
DECL|member|iAlphadepth
name|mng_uint8
name|iAlphadepth
decl_stmt|;
comment|/* indicates expected alpha-depth */
DECL|member|iImagelevel
name|mng_uint32
name|iImagelevel
decl_stmt|;
comment|/* level of image inside a stream */
DECL|member|iCanvasstyle
name|mng_uint32
name|iCanvasstyle
decl_stmt|;
comment|/* layout of the drawing-canvas */
DECL|member|iBkgdstyle
name|mng_uint32
name|iBkgdstyle
decl_stmt|;
comment|/* layout of the background-canvas */
DECL|member|iMagnify
name|mng_int8
name|iMagnify
decl_stmt|;
comment|/* magnification factor (not used yet) */
DECL|member|iOffsetx
name|mng_uint32
name|iOffsetx
decl_stmt|;
comment|/* x-offset for extremely large image */
DECL|member|iOffsety
name|mng_uint32
name|iOffsety
decl_stmt|;
comment|/* y-offset for extremely large image */
DECL|member|iCanvaswidth
name|mng_uint32
name|iCanvaswidth
decl_stmt|;
comment|/* real canvas size */
DECL|member|iCanvasheight
name|mng_uint32
name|iCanvasheight
decl_stmt|;
comment|/* must be set by processheader callback */
DECL|member|iBGred
name|mng_uint16
name|iBGred
decl_stmt|;
comment|/* default background color */
DECL|member|iBGgreen
name|mng_uint16
name|iBGgreen
decl_stmt|;
comment|/* initially "black" */
DECL|member|iBGblue
name|mng_uint16
name|iBGblue
decl_stmt|;
DECL|member|bUseBKGD
name|mng_bool
name|bUseBKGD
decl_stmt|;
comment|/* preferred use of bKGD for PNG */
DECL|member|bIssRGB
name|mng_bool
name|bIssRGB
decl_stmt|;
comment|/* indicates sRGB system */
ifdef|#
directive|ifdef
name|MNG_FULL_CMS
comment|/* little CMS variables */
DECL|member|hProf1
name|mng_cmsprof
name|hProf1
decl_stmt|;
comment|/* image input profile */
DECL|member|hProf2
name|mng_cmsprof
name|hProf2
decl_stmt|;
comment|/* default output profile */
DECL|member|hProf3
name|mng_cmsprof
name|hProf3
decl_stmt|;
comment|/* default sRGB profile */
DECL|member|hTrans
name|mng_cmstrans
name|hTrans
decl_stmt|;
comment|/* current transformation handle */
endif|#
directive|endif
DECL|member|dViewgamma
name|mng_float
name|dViewgamma
decl_stmt|;
comment|/* gamma calculation variables */
DECL|member|dDisplaygamma
name|mng_float
name|dDisplaygamma
decl_stmt|;
comment|/* initially set for sRGB conditions */
DECL|member|dDfltimggamma
name|mng_float
name|dDfltimggamma
decl_stmt|;
DECL|member|bStorechunks
name|mng_bool
name|bStorechunks
decl_stmt|;
comment|/* switch for storing chunkdata */
DECL|member|bSectionbreaks
name|mng_bool
name|bSectionbreaks
decl_stmt|;
comment|/* indicate NEEDSECTIONWAIT breaks */
DECL|member|bCacheplayback
name|mng_bool
name|bCacheplayback
decl_stmt|;
comment|/* switch to cache playback info */
DECL|member|bDoProgressive
name|mng_bool
name|bDoProgressive
decl_stmt|;
comment|/* progressive refresh for large images */
DECL|member|iCrcmode
name|mng_uint32
name|iCrcmode
decl_stmt|;
comment|/* CRC existence& checking flags */
DECL|member|iSpeed
name|mng_speedtype
name|iSpeed
decl_stmt|;
comment|/* speed-modifier for animations */
DECL|member|iMaxwidth
name|mng_uint32
name|iMaxwidth
decl_stmt|;
comment|/* maximum canvas size */
DECL|member|iMaxheight
name|mng_uint32
name|iMaxheight
decl_stmt|;
comment|/* initially set to 1024 x 1024 */
DECL|member|iErrorcode
name|mng_int32
name|iErrorcode
decl_stmt|;
comment|/* error reporting fields */
DECL|member|iSeverity
name|mng_int8
name|iSeverity
decl_stmt|;
DECL|member|iErrorx1
name|mng_int32
name|iErrorx1
decl_stmt|;
DECL|member|iErrorx2
name|mng_int32
name|iErrorx2
decl_stmt|;
DECL|member|zErrortext
name|mng_pchar
name|zErrortext
decl_stmt|;
DECL|member|fMemalloc
name|mng_memalloc
name|fMemalloc
decl_stmt|;
comment|/* callback pointers */
DECL|member|fMemfree
name|mng_memfree
name|fMemfree
decl_stmt|;
comment|/* initially nulled */
DECL|member|fReleasedata
name|mng_releasedata
name|fReleasedata
decl_stmt|;
ifndef|#
directive|ifndef
name|MNG_NO_OPEN_CLOSE_STREAM
DECL|member|fOpenstream
name|mng_openstream
name|fOpenstream
decl_stmt|;
DECL|member|fClosestream
name|mng_closestream
name|fClosestream
decl_stmt|;
endif|#
directive|endif
DECL|member|fReaddata
name|mng_readdata
name|fReaddata
decl_stmt|;
DECL|member|fWritedata
name|mng_writedata
name|fWritedata
decl_stmt|;
DECL|member|fErrorproc
name|mng_errorproc
name|fErrorproc
decl_stmt|;
DECL|member|fTraceproc
name|mng_traceproc
name|fTraceproc
decl_stmt|;
DECL|member|fProcessheader
name|mng_processheader
name|fProcessheader
decl_stmt|;
DECL|member|fProcesstext
name|mng_processtext
name|fProcesstext
decl_stmt|;
DECL|member|fProcesssave
name|mng_processsave
name|fProcesssave
decl_stmt|;
DECL|member|fProcessseek
name|mng_processseek
name|fProcessseek
decl_stmt|;
DECL|member|fProcessneed
name|mng_processneed
name|fProcessneed
decl_stmt|;
DECL|member|fProcessmend
name|mng_processmend
name|fProcessmend
decl_stmt|;
DECL|member|fProcessunknown
name|mng_processunknown
name|fProcessunknown
decl_stmt|;
DECL|member|fProcessterm
name|mng_processterm
name|fProcessterm
decl_stmt|;
DECL|member|fGetcanvasline
name|mng_getcanvasline
name|fGetcanvasline
decl_stmt|;
DECL|member|fGetbkgdline
name|mng_getbkgdline
name|fGetbkgdline
decl_stmt|;
DECL|member|fGetalphaline
name|mng_getalphaline
name|fGetalphaline
decl_stmt|;
DECL|member|fRefresh
name|mng_refresh
name|fRefresh
decl_stmt|;
DECL|member|fGettickcount
name|mng_gettickcount
name|fGettickcount
decl_stmt|;
DECL|member|fSettimer
name|mng_settimer
name|fSettimer
decl_stmt|;
DECL|member|fProcessgamma
name|mng_processgamma
name|fProcessgamma
decl_stmt|;
DECL|member|fProcesschroma
name|mng_processchroma
name|fProcesschroma
decl_stmt|;
DECL|member|fProcesssrgb
name|mng_processsrgb
name|fProcesssrgb
decl_stmt|;
DECL|member|fProcessiccp
name|mng_processiccp
name|fProcessiccp
decl_stmt|;
DECL|member|fProcessarow
name|mng_processarow
name|fProcessarow
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|MNG_SUPPORT_READ
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_SUPPORT_WRITE
argument_list|)
ifndef|#
directive|ifndef
name|MNG_NO_OLD_VERSIONS
DECL|member|bPreDraft48
name|mng_bool
name|bPreDraft48
decl_stmt|;
comment|/* flags ancient style draft */
endif|#
directive|endif
DECL|member|iChunkname
name|mng_chunkid
name|iChunkname
decl_stmt|;
comment|/* read/write-state variables */
DECL|member|iChunkseq
name|mng_uint32
name|iChunkseq
decl_stmt|;
DECL|member|pFirstchunk
name|mng_chunkp
name|pFirstchunk
decl_stmt|;
comment|/* double-linked list of */
DECL|member|pLastchunk
name|mng_chunkp
name|pLastchunk
decl_stmt|;
comment|/* stored chunk-structures */
DECL|member|bHasheader
name|mng_bool
name|bHasheader
decl_stmt|;
comment|/* first header chunk processed */
DECL|member|bHasMHDR
name|mng_bool
name|bHasMHDR
decl_stmt|;
comment|/* inside a MHDR-MEND sequence */
DECL|member|bHasIHDR
name|mng_bool
name|bHasIHDR
decl_stmt|;
comment|/* inside a IHDR-IEND sequence */
DECL|member|bHasBASI
name|mng_bool
name|bHasBASI
decl_stmt|;
comment|/* inside a BASI-IEND sequence */
DECL|member|bHasDHDR
name|mng_bool
name|bHasDHDR
decl_stmt|;
comment|/* inside a DHDR-IEND sequence */
ifdef|#
directive|ifdef
name|MNG_INCLUDE_JNG
DECL|member|bHasJHDR
name|mng_bool
name|bHasJHDR
decl_stmt|;
comment|/* inside a JHDR-IEND sequence */
DECL|member|bHasJSEP
name|mng_bool
name|bHasJSEP
decl_stmt|;
comment|/* passed the JSEP separator */
DECL|member|bHasJDAA
name|mng_bool
name|bHasJDAA
decl_stmt|;
comment|/* at least 1 JDAA processed */
DECL|member|bHasJDAT
name|mng_bool
name|bHasJDAT
decl_stmt|;
comment|/* at least 1 JDAT processed */
endif|#
directive|endif
DECL|member|bHasPLTE
name|mng_bool
name|bHasPLTE
decl_stmt|;
comment|/* PLTE chunk processed */
DECL|member|bHasTRNS
name|mng_bool
name|bHasTRNS
decl_stmt|;
comment|/* tRNS chunk processed */
DECL|member|bHasGAMA
name|mng_bool
name|bHasGAMA
decl_stmt|;
comment|/* gAMA chunk processed */
DECL|member|bHasCHRM
name|mng_bool
name|bHasCHRM
decl_stmt|;
comment|/* cHRM chunk processed */
DECL|member|bHasSRGB
name|mng_bool
name|bHasSRGB
decl_stmt|;
comment|/* sRGB chunk processed */
DECL|member|bHasICCP
name|mng_bool
name|bHasICCP
decl_stmt|;
comment|/* iCCP chunk processed */
DECL|member|bHasBKGD
name|mng_bool
name|bHasBKGD
decl_stmt|;
comment|/* bKGD chunk processed */
DECL|member|bHasIDAT
name|mng_bool
name|bHasIDAT
decl_stmt|;
comment|/* at least 1 IDAT processed */
DECL|member|bHasSAVE
name|mng_bool
name|bHasSAVE
decl_stmt|;
comment|/* SAVE chunk processed */
DECL|member|bHasBACK
name|mng_bool
name|bHasBACK
decl_stmt|;
comment|/* BACK chunk processed */
DECL|member|bHasFRAM
name|mng_bool
name|bHasFRAM
decl_stmt|;
comment|/* FRAM chunk processed */
DECL|member|bHasTERM
name|mng_bool
name|bHasTERM
decl_stmt|;
comment|/* TERM chunk processed */
DECL|member|bHasLOOP
name|mng_bool
name|bHasLOOP
decl_stmt|;
comment|/* at least 1 LOOP open */
DECL|member|bHasglobalPLTE
name|mng_bool
name|bHasglobalPLTE
decl_stmt|;
comment|/* global PLTE chunk processed */
DECL|member|bHasglobalTRNS
name|mng_bool
name|bHasglobalTRNS
decl_stmt|;
comment|/* global tRNS chunk processed */
DECL|member|bHasglobalGAMA
name|mng_bool
name|bHasglobalGAMA
decl_stmt|;
comment|/* global gAMA chunk processed */
DECL|member|bHasglobalCHRM
name|mng_bool
name|bHasglobalCHRM
decl_stmt|;
comment|/* global cHRM chunk processed */
DECL|member|bHasglobalSRGB
name|mng_bool
name|bHasglobalSRGB
decl_stmt|;
comment|/* global sRGB chunk processed */
DECL|member|bHasglobalICCP
name|mng_bool
name|bHasglobalICCP
decl_stmt|;
comment|/* global iCCP chunk processed */
DECL|member|bHasglobalBKGD
name|mng_bool
name|bHasglobalBKGD
decl_stmt|;
comment|/* global bKGD chunk processed */
DECL|member|iDatawidth
name|mng_uint32
name|iDatawidth
decl_stmt|;
comment|/* IHDR/BASI/DHDR fields */
DECL|member|iDataheight
name|mng_uint32
name|iDataheight
decl_stmt|;
comment|/* valid if inside IHDR-IEND, */
DECL|member|iBitdepth
name|mng_uint8
name|iBitdepth
decl_stmt|;
comment|/* BASI-IEND or DHDR-IEND */
DECL|member|iColortype
name|mng_uint8
name|iColortype
decl_stmt|;
DECL|member|iCompression
name|mng_uint8
name|iCompression
decl_stmt|;
DECL|member|iFilter
name|mng_uint8
name|iFilter
decl_stmt|;
DECL|member|iInterlace
name|mng_uint8
name|iInterlace
decl_stmt|;
DECL|member|iPLTEcount
name|mng_uint32
name|iPLTEcount
decl_stmt|;
comment|/* PLTE fields */
ifdef|#
directive|ifdef
name|MNG_INCLUDE_JNG
DECL|member|iJHDRcolortype
name|mng_uint8
name|iJHDRcolortype
decl_stmt|;
comment|/* JHDR fields */
DECL|member|iJHDRimgbitdepth
name|mng_uint8
name|iJHDRimgbitdepth
decl_stmt|;
comment|/* valid if inside JHDR-IEND */
DECL|member|iJHDRimgcompression
name|mng_uint8
name|iJHDRimgcompression
decl_stmt|;
DECL|member|iJHDRimginterlace
name|mng_uint8
name|iJHDRimginterlace
decl_stmt|;
DECL|member|iJHDRalphabitdepth
name|mng_uint8
name|iJHDRalphabitdepth
decl_stmt|;
DECL|member|iJHDRalphacompression
name|mng_uint8
name|iJHDRalphacompression
decl_stmt|;
DECL|member|iJHDRalphafilter
name|mng_uint8
name|iJHDRalphafilter
decl_stmt|;
DECL|member|iJHDRalphainterlace
name|mng_uint8
name|iJHDRalphainterlace
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* MNG_SUPPORT_READ || MNG_SUPPORT_WRITE */
ifdef|#
directive|ifdef
name|MNG_SUPPORT_READ
DECL|member|bReading
name|mng_bool
name|bReading
decl_stmt|;
comment|/* read processing variables */
DECL|member|bHavesig
name|mng_bool
name|bHavesig
decl_stmt|;
DECL|member|bEOF
name|mng_bool
name|bEOF
decl_stmt|;
DECL|member|iReadbufsize
name|mng_uint32
name|iReadbufsize
decl_stmt|;
DECL|member|pReadbuf
name|mng_uint8p
name|pReadbuf
decl_stmt|;
DECL|member|iLargebufsize
name|mng_uint32
name|iLargebufsize
decl_stmt|;
comment|/* temp for very large chunks */
DECL|member|pLargebuf
name|mng_uint8p
name|pLargebuf
decl_stmt|;
DECL|member|iSuspendtime
name|mng_uint32
name|iSuspendtime
decl_stmt|;
comment|/* tickcount at last suspension */
DECL|member|bSuspended
name|mng_bool
name|bSuspended
decl_stmt|;
comment|/* input-reading has been suspended;                                                     we're expecting a call to                                                     mng_read_resume! */
DECL|member|iSuspendpoint
name|mng_uint8
name|iSuspendpoint
decl_stmt|;
comment|/* indicates at which point the flow                                                     was broken to suspend input-reading */
DECL|member|bSuspensionmode
name|mng_bool
name|bSuspensionmode
decl_stmt|;
comment|/* I/O-suspension variables */
DECL|member|iSuspendbufsize
name|mng_uint32
name|iSuspendbufsize
decl_stmt|;
DECL|member|pSuspendbuf
name|mng_uint8p
name|pSuspendbuf
decl_stmt|;
DECL|member|pSuspendbufnext
name|mng_uint8p
name|pSuspendbufnext
decl_stmt|;
DECL|member|iSuspendbufleft
name|mng_uint32
name|iSuspendbufleft
decl_stmt|;
DECL|member|iChunklen
name|mng_uint32
name|iChunklen
decl_stmt|;
comment|/* chunk length */
DECL|member|pReadbufnext
name|mng_uint8p
name|pReadbufnext
decl_stmt|;
comment|/* 32K+ suspension-processing */
DECL|member|pLargebufnext
name|mng_uint8p
name|pLargebufnext
decl_stmt|;
DECL|member|pFirstpushchunk
name|mng_pushdatap
name|pFirstpushchunk
decl_stmt|;
comment|/* variables for push mechanisms */
DECL|member|pLastpushchunk
name|mng_pushdatap
name|pLastpushchunk
decl_stmt|;
DECL|member|pFirstpushdata
name|mng_pushdatap
name|pFirstpushdata
decl_stmt|;
DECL|member|pLastpushdata
name|mng_pushdatap
name|pLastpushdata
decl_stmt|;
endif|#
directive|endif
comment|/* MNG_SUPPORT_READ */
ifdef|#
directive|ifdef
name|MNG_SUPPORT_WRITE
DECL|member|bCreating
name|mng_bool
name|bCreating
decl_stmt|;
comment|/* create/write processing variables */
DECL|member|bWriting
name|mng_bool
name|bWriting
decl_stmt|;
DECL|member|iFirstchunkadded
name|mng_chunkid
name|iFirstchunkadded
decl_stmt|;
DECL|member|iWritebufsize
name|mng_uint32
name|iWritebufsize
decl_stmt|;
DECL|member|pWritebuf
name|mng_uint8p
name|pWritebuf
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MNG_SUPPORT_DISPLAY
DECL|member|bDisplaying
name|mng_bool
name|bDisplaying
decl_stmt|;
comment|/* display-state variables */
DECL|member|bFramedone
name|mng_bool
name|bFramedone
decl_stmt|;
DECL|member|iFrameseq
name|mng_uint32
name|iFrameseq
decl_stmt|;
DECL|member|iLayerseq
name|mng_uint32
name|iLayerseq
decl_stmt|;
DECL|member|iFrametime
name|mng_uint32
name|iFrametime
decl_stmt|;
comment|/* millisecs */
DECL|member|iTotalframes
name|mng_uint32
name|iTotalframes
decl_stmt|;
comment|/* end-totals after mng_read() */
DECL|member|iTotallayers
name|mng_uint32
name|iTotallayers
decl_stmt|;
DECL|member|iTotalplaytime
name|mng_uint32
name|iTotalplaytime
decl_stmt|;
comment|/* millisecs */
DECL|member|bSkipping
name|mng_bool
name|bSkipping
decl_stmt|;
comment|/* LOOP iteration=0 */
ifdef|#
directive|ifdef
name|MNG_SUPPORT_DYNAMICMNG
DECL|member|bDynamic
name|mng_bool
name|bDynamic
decl_stmt|;
comment|/* MNG is dynamic (eg. has events) */
DECL|member|bRunningevent
name|mng_bool
name|bRunningevent
decl_stmt|;
comment|/* currently processing an event */
DECL|member|bStopafterseek
name|mng_bool
name|bStopafterseek
decl_stmt|;
comment|/* stop after next SEEK */
DECL|member|iEventx
name|mng_int32
name|iEventx
decl_stmt|;
comment|/* X/Y of current event */
DECL|member|iEventy
name|mng_int32
name|iEventy
decl_stmt|;
DECL|member|pLastmousemove
name|mng_objectp
name|pLastmousemove
decl_stmt|;
comment|/* last event triggered */
endif|#
directive|endif
DECL|member|iRequestframe
name|mng_uint32
name|iRequestframe
decl_stmt|;
comment|/* go_xxxx variables */
DECL|member|iRequestlayer
name|mng_uint32
name|iRequestlayer
decl_stmt|;
DECL|member|iRequesttime
name|mng_uint32
name|iRequesttime
decl_stmt|;
DECL|member|bSearching
name|mng_bool
name|bSearching
decl_stmt|;
DECL|member|bRestorebkgd
name|mng_bool
name|bRestorebkgd
decl_stmt|;
comment|/* flags restore required before IDAT/JDAT */
DECL|member|iRuntime
name|mng_uint32
name|iRuntime
decl_stmt|;
comment|/* millisecs since start */
DECL|member|iSynctime
name|mng_uint32
name|iSynctime
decl_stmt|;
comment|/* tickcount at last framesync */
DECL|member|iStarttime
name|mng_uint32
name|iStarttime
decl_stmt|;
comment|/* tickcount at start */
DECL|member|iEndtime
name|mng_uint32
name|iEndtime
decl_stmt|;
comment|/* tickcount at end */
DECL|member|bRunning
name|mng_bool
name|bRunning
decl_stmt|;
comment|/* animation is active */
DECL|member|bTimerset
name|mng_bool
name|bTimerset
decl_stmt|;
comment|/* the timer has been set;                                                     we're expecting a call to                                                     mng_display_resume! */
DECL|member|iBreakpoint
name|mng_uint8
name|iBreakpoint
decl_stmt|;
comment|/* indicates at which point the                                                     flow was broken to run the timer */
DECL|member|bSectionwait
name|mng_bool
name|bSectionwait
decl_stmt|;
comment|/* indicates a section break */
DECL|member|bFreezing
name|mng_bool
name|bFreezing
decl_stmt|;
comment|/* indicates app requested a freeze */
DECL|member|bResetting
name|mng_bool
name|bResetting
decl_stmt|;
comment|/* indicates app requested a reset */
DECL|member|bNeedrefresh
name|mng_bool
name|bNeedrefresh
decl_stmt|;
comment|/* indicates screen-refresh is needed */
DECL|member|bMisplacedTERM
name|mng_bool
name|bMisplacedTERM
decl_stmt|;
comment|/* indicates TERM is out of place */
DECL|member|bOnlyfirstframe
name|mng_bool
name|bOnlyfirstframe
decl_stmt|;
comment|/* show first frame after TERM and stop */
DECL|member|iFramesafterTERM
name|mng_uint32
name|iFramesafterTERM
decl_stmt|;
comment|/* determines frame-count after TERM */
DECL|member|pCurrentobj
name|mng_objectp
name|pCurrentobj
decl_stmt|;
comment|/* current "object" */
DECL|member|pCurraniobj
name|mng_objectp
name|pCurraniobj
decl_stmt|;
comment|/* current animation object                                                     "to be"/"being" processed */
DECL|member|pTermaniobj
name|mng_objectp
name|pTermaniobj
decl_stmt|;
comment|/* TERM animation object */
DECL|member|iIterations
name|mng_uint32
name|iIterations
decl_stmt|;
comment|/* TERM/MEND iteration count */
DECL|member|pObjzero
name|mng_objectp
name|pObjzero
decl_stmt|;
comment|/* "on-the-fly" image (object = 0) */
DECL|member|pLastclone
name|mng_objectp
name|pLastclone
decl_stmt|;
comment|/* last clone */
DECL|member|pStoreobj
name|mng_objectp
name|pStoreobj
decl_stmt|;
comment|/* current store object for row routines */
DECL|member|pStorebuf
name|mng_objectp
name|pStorebuf
decl_stmt|;
comment|/* current store object-buffer for row routines */
DECL|member|pRetrieveobj
name|mng_objectp
name|pRetrieveobj
decl_stmt|;
comment|/* current retrieve object for row routines */
DECL|member|pSavedata
name|mng_savedatap
name|pSavedata
decl_stmt|;
comment|/* pointer to saved data (after SAVE) */
DECL|member|iUpdateleft
name|mng_uint32
name|iUpdateleft
decl_stmt|;
comment|/* update region for refresh */
DECL|member|iUpdateright
name|mng_uint32
name|iUpdateright
decl_stmt|;
DECL|member|iUpdatetop
name|mng_uint32
name|iUpdatetop
decl_stmt|;
DECL|member|iUpdatebottom
name|mng_uint32
name|iUpdatebottom
decl_stmt|;
DECL|member|iPass
name|mng_int8
name|iPass
decl_stmt|;
comment|/* current interlacing pass;                                                     negative value means no interlace */
DECL|member|iRow
name|mng_int32
name|iRow
decl_stmt|;
comment|/* current row counter */
DECL|member|iRowinc
name|mng_int32
name|iRowinc
decl_stmt|;
comment|/* row increment for this pass */
DECL|member|iCol
name|mng_int32
name|iCol
decl_stmt|;
comment|/* current starting column */
DECL|member|iColinc
name|mng_int32
name|iColinc
decl_stmt|;
comment|/* column increment for this pass */
DECL|member|iRowsamples
name|mng_int32
name|iRowsamples
decl_stmt|;
comment|/* nr. of samples in current workrow */
DECL|member|iSamplemul
name|mng_int32
name|iSamplemul
decl_stmt|;
comment|/* needed to calculate rowsize */
DECL|member|iSampleofs
name|mng_int32
name|iSampleofs
decl_stmt|;
comment|/* from rowsamples */
DECL|member|iSamplediv
name|mng_int32
name|iSamplediv
decl_stmt|;
DECL|member|iRowsize
name|mng_int32
name|iRowsize
decl_stmt|;
comment|/* size of actual data in work row */
DECL|member|iRowmax
name|mng_int32
name|iRowmax
decl_stmt|;
comment|/* maximum size of data in work row */
DECL|member|iFilterofs
name|mng_int32
name|iFilterofs
decl_stmt|;
comment|/* offset to filter-byte in work row */
DECL|member|iPixelofs
name|mng_int32
name|iPixelofs
decl_stmt|;
comment|/* offset to pixel-bytes in work row */
DECL|member|iLevel0
name|mng_uint32
name|iLevel0
decl_stmt|;
comment|/* leveling variables */
DECL|member|iLevel1
name|mng_uint32
name|iLevel1
decl_stmt|;
DECL|member|iLevel2
name|mng_uint32
name|iLevel2
decl_stmt|;
DECL|member|iLevel3
name|mng_uint32
name|iLevel3
decl_stmt|;
DECL|member|pWorkrow
name|mng_uint8p
name|pWorkrow
decl_stmt|;
comment|/* working row of pixel-data */
DECL|member|pPrevrow
name|mng_uint8p
name|pPrevrow
decl_stmt|;
comment|/* previous row of pixel-data */
DECL|member|pRGBArow
name|mng_uint8p
name|pRGBArow
decl_stmt|;
comment|/* intermediate row of RGBA8 or RGBA16 data */
DECL|member|bIsRGBA16
name|mng_bool
name|bIsRGBA16
decl_stmt|;
comment|/* indicates intermediate row is RGBA16 */
DECL|member|bIsOpaque
name|mng_bool
name|bIsOpaque
decl_stmt|;
comment|/* indicates intermediate row is fully opaque */
DECL|member|iFilterbpp
name|mng_int32
name|iFilterbpp
decl_stmt|;
comment|/* bpp index for filtering routines */
DECL|member|iSourcel
name|mng_int32
name|iSourcel
decl_stmt|;
comment|/* variables for showing objects */
DECL|member|iSourcer
name|mng_int32
name|iSourcer
decl_stmt|;
DECL|member|iSourcet
name|mng_int32
name|iSourcet
decl_stmt|;
DECL|member|iSourceb
name|mng_int32
name|iSourceb
decl_stmt|;
DECL|member|iDestl
name|mng_int32
name|iDestl
decl_stmt|;
DECL|member|iDestr
name|mng_int32
name|iDestr
decl_stmt|;
DECL|member|iDestt
name|mng_int32
name|iDestt
decl_stmt|;
DECL|member|iDestb
name|mng_int32
name|iDestb
decl_stmt|;
DECL|member|pFirstimgobj
name|mng_objectp
name|pFirstimgobj
decl_stmt|;
comment|/* double-linked list of */
DECL|member|pLastimgobj
name|mng_objectp
name|pLastimgobj
decl_stmt|;
comment|/* image-object structures */
DECL|member|pFirstaniobj
name|mng_objectp
name|pFirstaniobj
decl_stmt|;
comment|/* double-linked list of */
DECL|member|pLastaniobj
name|mng_objectp
name|pLastaniobj
decl_stmt|;
comment|/* animation-object structures */
ifdef|#
directive|ifdef
name|MNG_SUPPORT_DYNAMICMNG
DECL|member|pFirstevent
name|mng_objectp
name|pFirstevent
decl_stmt|;
comment|/* double-linked list of */
DECL|member|pLastevent
name|mng_objectp
name|pLastevent
decl_stmt|;
comment|/* event-object structures */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|MNG_GAMMA_ONLY
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_FULL_CMS
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_APP_CMS
argument_list|)
DECL|member|aGammatab
name|mng_uint8
name|aGammatab
index|[
literal|256
index|]
decl_stmt|;
comment|/* precomputed gamma lookup table */
DECL|member|dLastgamma
name|mng_float
name|dLastgamma
decl_stmt|;
comment|/* last gamma used to compute table */
endif|#
directive|endif
DECL|member|fDisplayrow
name|mng_fptr
name|fDisplayrow
decl_stmt|;
comment|/* internal callback to display an                                                     uncompressed/unfiltered/                                                     color-corrected row */
DECL|member|fRestbkgdrow
name|mng_fptr
name|fRestbkgdrow
decl_stmt|;
comment|/* internal callback for restore-                                                     background processing of a row */
DECL|member|fCorrectrow
name|mng_fptr
name|fCorrectrow
decl_stmt|;
comment|/* internal callback to color-correct an                                                     uncompressed/unfiltered row */
DECL|member|fRetrieverow
name|mng_fptr
name|fRetrieverow
decl_stmt|;
comment|/* internal callback to retrieve an                                                     uncompressed/unfiltered row of data */
DECL|member|fStorerow
name|mng_fptr
name|fStorerow
decl_stmt|;
comment|/* internal callback to store an                                                     uncompressed/unfiltered row of data */
DECL|member|fProcessrow
name|mng_fptr
name|fProcessrow
decl_stmt|;
comment|/* internal callback to process an                                                     uncompressed row of data */
DECL|member|fDifferrow
name|mng_fptr
name|fDifferrow
decl_stmt|;
comment|/* internal callback to perform                                                     added filter leveling and                                                     differing on an unfiltered row */
DECL|member|fScalerow
name|mng_fptr
name|fScalerow
decl_stmt|;
comment|/* internal callback to scale a                                                     delta-row to the bitdepth of its target */
DECL|member|fDeltarow
name|mng_fptr
name|fDeltarow
decl_stmt|;
comment|/* internal callback to execute a                                                     delta-row onto a target */
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_PAST
DECL|member|fFliprow
name|mng_fptr
name|fFliprow
decl_stmt|;
comment|/* internal callback to flip a row of pixels                                                     left<->right for a PAST operation */
DECL|member|fTilerow
name|mng_fptr
name|fTilerow
decl_stmt|;
comment|/* internal callback to tile a row of pixels                                                     during a PAST operation */
endif|#
directive|endif
DECL|member|fInitrowproc
name|mng_fptr
name|fInitrowproc
decl_stmt|;
comment|/* internal callback to initialize                                                     the row processing */
DECL|member|iDEFIobjectid
name|mng_uint16
name|iDEFIobjectid
decl_stmt|;
comment|/* DEFI fields */
DECL|member|bDEFIhasdonotshow
name|mng_bool
name|bDEFIhasdonotshow
decl_stmt|;
DECL|member|iDEFIdonotshow
name|mng_uint8
name|iDEFIdonotshow
decl_stmt|;
DECL|member|bDEFIhasconcrete
name|mng_bool
name|bDEFIhasconcrete
decl_stmt|;
DECL|member|iDEFIconcrete
name|mng_uint8
name|iDEFIconcrete
decl_stmt|;
DECL|member|bDEFIhasloca
name|mng_bool
name|bDEFIhasloca
decl_stmt|;
DECL|member|iDEFIlocax
name|mng_int32
name|iDEFIlocax
decl_stmt|;
DECL|member|iDEFIlocay
name|mng_int32
name|iDEFIlocay
decl_stmt|;
DECL|member|bDEFIhasclip
name|mng_bool
name|bDEFIhasclip
decl_stmt|;
DECL|member|iDEFIclipl
name|mng_int32
name|iDEFIclipl
decl_stmt|;
DECL|member|iDEFIclipr
name|mng_int32
name|iDEFIclipr
decl_stmt|;
DECL|member|iDEFIclipt
name|mng_int32
name|iDEFIclipt
decl_stmt|;
DECL|member|iDEFIclipb
name|mng_int32
name|iDEFIclipb
decl_stmt|;
DECL|member|iBACKred
name|mng_uint16
name|iBACKred
decl_stmt|;
comment|/* BACK fields */
DECL|member|iBACKgreen
name|mng_uint16
name|iBACKgreen
decl_stmt|;
DECL|member|iBACKblue
name|mng_uint16
name|iBACKblue
decl_stmt|;
DECL|member|iBACKmandatory
name|mng_uint8
name|iBACKmandatory
decl_stmt|;
DECL|member|iBACKimageid
name|mng_uint16
name|iBACKimageid
decl_stmt|;
DECL|member|iBACKtile
name|mng_uint8
name|iBACKtile
decl_stmt|;
DECL|member|iBackimgoffsx
name|mng_int32
name|iBackimgoffsx
decl_stmt|;
comment|/* temp variables for restore_bkgd */
DECL|member|iBackimgoffsy
name|mng_int32
name|iBackimgoffsy
decl_stmt|;
DECL|member|iBackimgwidth
name|mng_uint32
name|iBackimgwidth
decl_stmt|;
DECL|member|iBackimgheight
name|mng_uint32
name|iBackimgheight
decl_stmt|;
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_FRAM
DECL|member|iFRAMmode
name|mng_uint8
name|iFRAMmode
decl_stmt|;
comment|/* FRAM fields (global) */
DECL|member|iFRAMdelay
name|mng_uint32
name|iFRAMdelay
decl_stmt|;
DECL|member|iFRAMtimeout
name|mng_uint32
name|iFRAMtimeout
decl_stmt|;
DECL|member|bFRAMclipping
name|mng_bool
name|bFRAMclipping
decl_stmt|;
DECL|member|iFRAMclipl
name|mng_int32
name|iFRAMclipl
decl_stmt|;
DECL|member|iFRAMclipr
name|mng_int32
name|iFRAMclipr
decl_stmt|;
DECL|member|iFRAMclipt
name|mng_int32
name|iFRAMclipt
decl_stmt|;
DECL|member|iFRAMclipb
name|mng_int32
name|iFRAMclipb
decl_stmt|;
DECL|member|iFramemode
name|mng_uint8
name|iFramemode
decl_stmt|;
comment|/* current subframe variables */
DECL|member|iFramedelay
name|mng_uint32
name|iFramedelay
decl_stmt|;
DECL|member|iFrametimeout
name|mng_uint32
name|iFrametimeout
decl_stmt|;
DECL|member|bFrameclipping
name|mng_bool
name|bFrameclipping
decl_stmt|;
DECL|member|iFrameclipl
name|mng_int32
name|iFrameclipl
decl_stmt|;
DECL|member|iFrameclipr
name|mng_int32
name|iFrameclipr
decl_stmt|;
DECL|member|iFrameclipt
name|mng_int32
name|iFrameclipt
decl_stmt|;
DECL|member|iFrameclipb
name|mng_int32
name|iFrameclipb
decl_stmt|;
DECL|member|iNextdelay
name|mng_uint32
name|iNextdelay
decl_stmt|;
comment|/* delay *after* next image */
DECL|member|bForcedelay
name|mng_bool
name|bForcedelay
decl_stmt|;
DECL|member|iAccumdelay
name|mng_uint32
name|iAccumdelay
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_SHOW
DECL|member|iSHOWmode
name|mng_uint8
name|iSHOWmode
decl_stmt|;
comment|/* SHOW fields */
DECL|member|iSHOWfromid
name|mng_uint16
name|iSHOWfromid
decl_stmt|;
DECL|member|iSHOWtoid
name|mng_uint16
name|iSHOWtoid
decl_stmt|;
DECL|member|iSHOWnextid
name|mng_uint16
name|iSHOWnextid
decl_stmt|;
DECL|member|iSHOWskip
name|mng_int16
name|iSHOWskip
decl_stmt|;
endif|#
directive|endif
DECL|member|iGlobalPLTEcount
name|mng_uint32
name|iGlobalPLTEcount
decl_stmt|;
comment|/* global PLTE fields */
DECL|member|aGlobalPLTEentries
name|mng_rgbpaltab
name|aGlobalPLTEentries
decl_stmt|;
DECL|member|iGlobalTRNSrawlen
name|mng_uint32
name|iGlobalTRNSrawlen
decl_stmt|;
comment|/* global tRNS fields */
DECL|member|aGlobalTRNSrawdata
name|mng_uint8arr
name|aGlobalTRNSrawdata
decl_stmt|;
DECL|member|iGlobalGamma
name|mng_uint32
name|iGlobalGamma
decl_stmt|;
comment|/* global gAMA fields */
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_cHRM
DECL|member|iGlobalWhitepointx
name|mng_uint32
name|iGlobalWhitepointx
decl_stmt|;
comment|/* global cHRM fields */
DECL|member|iGlobalWhitepointy
name|mng_uint32
name|iGlobalWhitepointy
decl_stmt|;
DECL|member|iGlobalPrimaryredx
name|mng_uint32
name|iGlobalPrimaryredx
decl_stmt|;
DECL|member|iGlobalPrimaryredy
name|mng_uint32
name|iGlobalPrimaryredy
decl_stmt|;
DECL|member|iGlobalPrimarygreenx
name|mng_uint32
name|iGlobalPrimarygreenx
decl_stmt|;
DECL|member|iGlobalPrimarygreeny
name|mng_uint32
name|iGlobalPrimarygreeny
decl_stmt|;
DECL|member|iGlobalPrimarybluex
name|mng_uint32
name|iGlobalPrimarybluex
decl_stmt|;
DECL|member|iGlobalPrimarybluey
name|mng_uint32
name|iGlobalPrimarybluey
decl_stmt|;
endif|#
directive|endif
DECL|member|iGlobalRendintent
name|mng_uint8
name|iGlobalRendintent
decl_stmt|;
comment|/* global sRGB fields */
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_iCCP
DECL|member|iGlobalProfilesize
name|mng_uint32
name|iGlobalProfilesize
decl_stmt|;
comment|/* global iCCP fields */
DECL|member|pGlobalProfile
name|mng_ptr
name|pGlobalProfile
decl_stmt|;
endif|#
directive|endif
DECL|member|iGlobalBKGDred
name|mng_uint16
name|iGlobalBKGDred
decl_stmt|;
comment|/* global bKGD fields */
DECL|member|iGlobalBKGDgreen
name|mng_uint16
name|iGlobalBKGDgreen
decl_stmt|;
DECL|member|iGlobalBKGDblue
name|mng_uint16
name|iGlobalBKGDblue
decl_stmt|;
DECL|member|pDeltaImage
name|mng_ptr
name|pDeltaImage
decl_stmt|;
comment|/* delta-image fields */
DECL|member|iDeltaImagetype
name|mng_uint8
name|iDeltaImagetype
decl_stmt|;
endif|#
directive|endif
comment|/* MNG_SUPPORT_DISPLAY */
DECL|member|iDeltatype
name|mng_uint8
name|iDeltatype
decl_stmt|;
comment|/* need this one in read processing !! */
ifdef|#
directive|ifdef
name|MNG_SUPPORT_DISPLAY
DECL|member|iDeltaBlockwidth
name|mng_uint32
name|iDeltaBlockwidth
decl_stmt|;
DECL|member|iDeltaBlockheight
name|mng_uint32
name|iDeltaBlockheight
decl_stmt|;
DECL|member|iDeltaBlockx
name|mng_uint32
name|iDeltaBlockx
decl_stmt|;
DECL|member|iDeltaBlocky
name|mng_uint32
name|iDeltaBlocky
decl_stmt|;
DECL|member|bDeltaimmediate
name|mng_bool
name|bDeltaimmediate
decl_stmt|;
DECL|member|fDeltagetrow
name|mng_fptr
name|fDeltagetrow
decl_stmt|;
comment|/* internal delta-proc callbacks */
DECL|member|fDeltaaddrow
name|mng_fptr
name|fDeltaaddrow
decl_stmt|;
DECL|member|fDeltareplacerow
name|mng_fptr
name|fDeltareplacerow
decl_stmt|;
DECL|member|fDeltaputrow
name|mng_fptr
name|fDeltaputrow
decl_stmt|;
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_PROM
DECL|member|fPromoterow
name|mng_fptr
name|fPromoterow
decl_stmt|;
comment|/* internal PROM fields */
DECL|member|fPromBitdepth
name|mng_fptr
name|fPromBitdepth
decl_stmt|;
DECL|member|pPromBuf
name|mng_ptr
name|pPromBuf
decl_stmt|;
DECL|member|iPromColortype
name|mng_uint8
name|iPromColortype
decl_stmt|;
DECL|member|iPromBitdepth
name|mng_uint8
name|iPromBitdepth
decl_stmt|;
DECL|member|iPromFilltype
name|mng_uint8
name|iPromFilltype
decl_stmt|;
DECL|member|iPromWidth
name|mng_uint32
name|iPromWidth
decl_stmt|;
DECL|member|pPromSrc
name|mng_ptr
name|pPromSrc
decl_stmt|;
DECL|member|pPromDst
name|mng_ptr
name|pPromDst
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_MAGN
DECL|member|iMAGNfromid
name|mng_uint16
name|iMAGNfromid
decl_stmt|;
DECL|member|iMAGNcurrentid
name|mng_uint16
name|iMAGNcurrentid
decl_stmt|;
DECL|member|iMAGNtoid
name|mng_uint16
name|iMAGNtoid
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_PAST
DECL|member|iPASTid
name|mng_uint16
name|iPASTid
decl_stmt|;
DECL|member|iPastx
name|mng_int32
name|iPastx
decl_stmt|;
comment|/* target x/y of last PAST */
DECL|member|iPasty
name|mng_int32
name|iPasty
decl_stmt|;
endif|#
directive|endif
DECL|member|pLastseek
name|mng_objectp
name|pLastseek
decl_stmt|;
comment|/* last processed ani_seek object */
ifdef|#
directive|ifdef
name|MNG_INCLUDE_MPNG_PROPOSAL
DECL|member|pMPNG
name|mng_objectp
name|pMPNG
decl_stmt|;
comment|/* mpNG object if available */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MNG_INCLUDE_ANG_PROPOSAL
DECL|member|pANG
name|mng_objectp
name|pANG
decl_stmt|;
comment|/* ANG object if available */
endif|#
directive|endif
endif|#
directive|endif
comment|/* MNG_SUPPORT_DISPLAY */
ifdef|#
directive|ifdef
name|MNG_INCLUDE_ZLIB
DECL|member|sZlib
name|z_stream
name|sZlib
decl_stmt|;
comment|/* zlib (de)compression variables */
DECL|member|iZlevel
name|mng_int32
name|iZlevel
decl_stmt|;
comment|/* zlib compression parameters */
DECL|member|iZmethod
name|mng_int32
name|iZmethod
decl_stmt|;
DECL|member|iZwindowbits
name|mng_int32
name|iZwindowbits
decl_stmt|;
DECL|member|iZmemlevel
name|mng_int32
name|iZmemlevel
decl_stmt|;
DECL|member|iZstrategy
name|mng_int32
name|iZstrategy
decl_stmt|;
DECL|member|iMaxIDAT
name|mng_uint32
name|iMaxIDAT
decl_stmt|;
comment|/* maximum size of IDAT data */
DECL|member|bInflating
name|mng_bool
name|bInflating
decl_stmt|;
comment|/* indicates "inflate" in progress */
DECL|member|bDeflating
name|mng_bool
name|bDeflating
decl_stmt|;
comment|/* indicates "deflate" in progress */
endif|#
directive|endif
comment|/* MNG_INCLUDE_ZLIB */
ifdef|#
directive|ifdef
name|MNG_INCLUDE_JNG
DECL|member|eJPEGdctmethod
name|mngjpeg_dctmethod
name|eJPEGdctmethod
decl_stmt|;
comment|/* IJG compression variables */
DECL|member|iJPEGquality
name|mng_int32
name|iJPEGquality
decl_stmt|;
DECL|member|iJPEGsmoothing
name|mng_int32
name|iJPEGsmoothing
decl_stmt|;
DECL|member|bJPEGcompressprogr
name|mng_bool
name|bJPEGcompressprogr
decl_stmt|;
DECL|member|bJPEGcompressopt
name|mng_bool
name|bJPEGcompressopt
decl_stmt|;
DECL|member|iMaxJDAT
name|mng_uint32
name|iMaxJDAT
decl_stmt|;
comment|/* maximum size of JDAT/JDAA data */
DECL|member|pJPEGcinfo
name|mngjpeg_compp
name|pJPEGcinfo
decl_stmt|;
comment|/* compression structure */
DECL|member|pJPEGcerr
name|mngjpeg_errorp
name|pJPEGcerr
decl_stmt|;
comment|/* error-manager compress */
DECL|member|pJPEGdinfo
name|mngjpeg_decompp
name|pJPEGdinfo
decl_stmt|;
comment|/* decompression structure (JDAT) */
DECL|member|pJPEGderr
name|mngjpeg_errorp
name|pJPEGderr
decl_stmt|;
comment|/* error-manager decompress (JDAT) */
DECL|member|pJPEGdsrc
name|mngjpeg_sourcep
name|pJPEGdsrc
decl_stmt|;
comment|/* source-manager decompress (JDAT) */
DECL|member|pJPEGdinfo2
name|mngjpeg_decompp
name|pJPEGdinfo2
decl_stmt|;
comment|/* decompression structure (JDAA) */
DECL|member|pJPEGderr2
name|mngjpeg_errorp
name|pJPEGderr2
decl_stmt|;
comment|/* error-manager decompress (JDAA) */
DECL|member|pJPEGdsrc2
name|mngjpeg_sourcep
name|pJPEGdsrc2
decl_stmt|;
comment|/* source-manager decompress (JDAA) */
DECL|member|pJPEGbuf
name|mng_uint8p
name|pJPEGbuf
decl_stmt|;
comment|/* buffer for JPEG (de)compression (JDAT) */
DECL|member|iJPEGbufmax
name|mng_uint32
name|iJPEGbufmax
decl_stmt|;
comment|/* allocated space for buffer (JDAT) */
DECL|member|pJPEGcurrent
name|mng_uint8p
name|pJPEGcurrent
decl_stmt|;
comment|/* current pointer into buffer (JDAT) */
DECL|member|iJPEGbufremain
name|mng_uint32
name|iJPEGbufremain
decl_stmt|;
comment|/* remaining bytes in buffer (JDAT) */
DECL|member|iJPEGtoskip
name|mng_uint32
name|iJPEGtoskip
decl_stmt|;
comment|/* bytes to skip on next input-block (JDAT) */
DECL|member|pJPEGbuf2
name|mng_uint8p
name|pJPEGbuf2
decl_stmt|;
comment|/* buffer for JPEG (de)compression (JDAA) */
DECL|member|iJPEGbufmax2
name|mng_uint32
name|iJPEGbufmax2
decl_stmt|;
comment|/* allocated space for buffer (JDAA) */
DECL|member|pJPEGcurrent2
name|mng_uint8p
name|pJPEGcurrent2
decl_stmt|;
comment|/* current pointer into buffer (JDAA) */
DECL|member|iJPEGbufremain2
name|mng_uint32
name|iJPEGbufremain2
decl_stmt|;
comment|/* remaining bytes in buffer (JDAA) */
DECL|member|iJPEGtoskip2
name|mng_uint32
name|iJPEGtoskip2
decl_stmt|;
comment|/* bytes to skip on next input-block (JDAA) */
DECL|member|pJPEGrow
name|mng_uint8p
name|pJPEGrow
decl_stmt|;
comment|/* buffer for a JPEG row of samples (JDAT) */
DECL|member|iJPEGrowlen
name|mng_uint32
name|iJPEGrowlen
decl_stmt|;
DECL|member|pJPEGrow2
name|mng_uint8p
name|pJPEGrow2
decl_stmt|;
comment|/* buffer for a JPEG row of samples (JDAA) */
DECL|member|iJPEGrowlen2
name|mng_uint32
name|iJPEGrowlen2
decl_stmt|;
DECL|member|bJPEGcompress
name|mng_bool
name|bJPEGcompress
decl_stmt|;
comment|/* indicates "compress" initialized */
DECL|member|bJPEGdecompress
name|mng_bool
name|bJPEGdecompress
decl_stmt|;
comment|/* indicates "decompress" initialized (JDAT) */
DECL|member|bJPEGhasheader
name|mng_bool
name|bJPEGhasheader
decl_stmt|;
comment|/* indicates "readheader" succeeded (JDAT) */
DECL|member|bJPEGdecostarted
name|mng_bool
name|bJPEGdecostarted
decl_stmt|;
comment|/* indicates "decompress" started (JDAT) */
DECL|member|bJPEGscanstarted
name|mng_bool
name|bJPEGscanstarted
decl_stmt|;
comment|/* indicates "first scan" started (JDAT) */
DECL|member|bJPEGscanending
name|mng_bool
name|bJPEGscanending
decl_stmt|;
comment|/* indicates "finish_output" suspended (JDAT) */
DECL|member|bJPEGprogressive
name|mng_bool
name|bJPEGprogressive
decl_stmt|;
comment|/* indicates a progressive image (JDAT) */
DECL|member|bJPEGdecompress2
name|mng_bool
name|bJPEGdecompress2
decl_stmt|;
comment|/* indicates "decompress" initialized (JDAA) */
DECL|member|bJPEGhasheader2
name|mng_bool
name|bJPEGhasheader2
decl_stmt|;
comment|/* indicates "readheader" succeeded (JDAA) */
DECL|member|bJPEGdecostarted2
name|mng_bool
name|bJPEGdecostarted2
decl_stmt|;
comment|/* indicates "decompress" started (JDAA) */
DECL|member|bJPEGscanstarted2
name|mng_bool
name|bJPEGscanstarted2
decl_stmt|;
comment|/* indicates "first scan" started (JDAA) */
DECL|member|bJPEGprogressive2
name|mng_bool
name|bJPEGprogressive2
decl_stmt|;
comment|/* indicates a progressive image (JDAA) */
DECL|member|fStorerow2
name|mng_fptr
name|fStorerow2
decl_stmt|;
comment|/* internal callback to store an                                                     uncompressed/unfiltered row of JPEG-data (JDAT) */
DECL|member|fStorerow3
name|mng_fptr
name|fStorerow3
decl_stmt|;
comment|/* internal callback to store an                                                     uncompressed/unfiltered row of JPEG-data (JDAA) */
DECL|member|iJPEGrow
name|mng_uint32
name|iJPEGrow
decl_stmt|;
comment|/* row-number for current JPEG row */
DECL|member|iJPEGalpharow
name|mng_uint32
name|iJPEGalpharow
decl_stmt|;
comment|/* nr. of rows filled with alpha */
DECL|member|iJPEGrgbrow
name|mng_uint32
name|iJPEGrgbrow
decl_stmt|;
comment|/* nr. of rows filled with 'color'-info */
DECL|member|iJPEGdisprow
name|mng_uint32
name|iJPEGdisprow
decl_stmt|;
comment|/* nr. of rows already displayed "on-the-fly" */
if|#
directive|if
name|defined
argument_list|(
name|MNG_USE_SETJMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|MNG_INCLUDE_IJG6B
argument_list|)
DECL|member|sErrorbuf
name|jmp_buf
name|sErrorbuf
decl_stmt|;
comment|/* setjmp/longjmp buffer (error-recovery) */
endif|#
directive|endif
endif|#
directive|endif
comment|/* MNG_INCLUDE_JNG */
ifndef|#
directive|ifndef
name|MNG_USE_ZLIB_CRC
DECL|member|aCRCtable
name|mng_uint32
name|aCRCtable
index|[
literal|256
index|]
decl_stmt|;
comment|/* CRC prefab table */
DECL|member|bCRCcomputed
name|mng_bool
name|bCRCcomputed
decl_stmt|;
comment|/* "has been built" indicator */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MNG_OPTIMIZE_FOOTPRINT_INIT
DECL|member|ePng_imgtype
name|png_imgtype
name|ePng_imgtype
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|MNG_NO_1_2_4BIT_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_NO_16BIT_SUPPORT
argument_list|)
DECL|member|iPNGdepth
name|mng_uint8
name|iPNGdepth
decl_stmt|;
comment|/* Real input depth */
DECL|member|iPNGmult
name|mng_uint8
name|iPNGmult
decl_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MNG_OPTIMIZE_DISPLAYCALLS
DECL|member|iRawlen
name|mng_uint32
name|iRawlen
decl_stmt|;
comment|/* temp vars for display processing */
DECL|member|pRawdata
name|mng_uint8p
name|pRawdata
decl_stmt|;
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_BASI
DECL|member|iBASIred
name|mng_uint16
name|iBASIred
decl_stmt|;
DECL|member|iBASIgreen
name|mng_uint16
name|iBASIgreen
decl_stmt|;
DECL|member|iBASIblue
name|mng_uint16
name|iBASIblue
decl_stmt|;
DECL|member|bBASIhasalpha
name|mng_bool
name|bBASIhasalpha
decl_stmt|;
DECL|member|iBASIalpha
name|mng_uint16
name|iBASIalpha
decl_stmt|;
DECL|member|iBASIviewable
name|mng_uint8
name|iBASIviewable
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_CLON
DECL|member|iCLONsourceid
name|mng_uint16
name|iCLONsourceid
decl_stmt|;
DECL|member|iCLONcloneid
name|mng_uint16
name|iCLONcloneid
decl_stmt|;
DECL|member|iCLONclonetype
name|mng_uint8
name|iCLONclonetype
decl_stmt|;
DECL|member|bCLONhasdonotshow
name|mng_bool
name|bCLONhasdonotshow
decl_stmt|;
DECL|member|iCLONdonotshow
name|mng_uint8
name|iCLONdonotshow
decl_stmt|;
DECL|member|iCLONconcrete
name|mng_uint8
name|iCLONconcrete
decl_stmt|;
DECL|member|bCLONhasloca
name|mng_bool
name|bCLONhasloca
decl_stmt|;
DECL|member|iCLONlocationtype
name|mng_uint8
name|iCLONlocationtype
decl_stmt|;
DECL|member|iCLONlocationx
name|mng_int32
name|iCLONlocationx
decl_stmt|;
DECL|member|iCLONlocationy
name|mng_int32
name|iCLONlocationy
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_DISC
DECL|member|iDISCcount
name|mng_uint32
name|iDISCcount
decl_stmt|;
DECL|member|pDISCids
name|mng_uint16p
name|pDISCids
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_FRAM
DECL|member|iTempFramemode
name|mng_uint8
name|iTempFramemode
decl_stmt|;
DECL|member|iTempChangedelay
name|mng_uint8
name|iTempChangedelay
decl_stmt|;
DECL|member|iTempDelay
name|mng_uint32
name|iTempDelay
decl_stmt|;
DECL|member|iTempChangetimeout
name|mng_uint8
name|iTempChangetimeout
decl_stmt|;
DECL|member|iTempTimeout
name|mng_uint32
name|iTempTimeout
decl_stmt|;
DECL|member|iTempChangeclipping
name|mng_uint8
name|iTempChangeclipping
decl_stmt|;
DECL|member|iTempCliptype
name|mng_uint8
name|iTempCliptype
decl_stmt|;
DECL|member|iTempClipl
name|mng_int32
name|iTempClipl
decl_stmt|;
DECL|member|iTempClipr
name|mng_int32
name|iTempClipr
decl_stmt|;
DECL|member|iTempClipt
name|mng_int32
name|iTempClipt
decl_stmt|;
DECL|member|iTempClipb
name|mng_int32
name|iTempClipb
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_MOVE
DECL|member|iMOVEfromid
name|mng_uint16
name|iMOVEfromid
decl_stmt|;
DECL|member|iMOVEtoid
name|mng_uint16
name|iMOVEtoid
decl_stmt|;
DECL|member|iMOVEmovetype
name|mng_uint8
name|iMOVEmovetype
decl_stmt|;
DECL|member|iMOVEmovex
name|mng_int32
name|iMOVEmovex
decl_stmt|;
DECL|member|iMOVEmovey
name|mng_int32
name|iMOVEmovey
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_CLIP
DECL|member|iCLIPfromid
name|mng_uint16
name|iCLIPfromid
decl_stmt|;
DECL|member|iCLIPtoid
name|mng_uint16
name|iCLIPtoid
decl_stmt|;
DECL|member|iCLIPcliptype
name|mng_uint8
name|iCLIPcliptype
decl_stmt|;
DECL|member|iCLIPclipl
name|mng_int32
name|iCLIPclipl
decl_stmt|;
DECL|member|iCLIPclipr
name|mng_int32
name|iCLIPclipr
decl_stmt|;
DECL|member|iCLIPclipt
name|mng_int32
name|iCLIPclipt
decl_stmt|;
DECL|member|iCLIPclipb
name|mng_int32
name|iCLIPclipb
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_NO_DELTA_PNG
DECL|member|iDHDRobjectid
name|mng_uint16
name|iDHDRobjectid
decl_stmt|;
DECL|member|iDHDRimagetype
name|mng_uint8
name|iDHDRimagetype
decl_stmt|;
DECL|member|iDHDRdeltatype
name|mng_uint8
name|iDHDRdeltatype
decl_stmt|;
DECL|member|iDHDRblockwidth
name|mng_uint32
name|iDHDRblockwidth
decl_stmt|;
DECL|member|iDHDRblockheight
name|mng_uint32
name|iDHDRblockheight
decl_stmt|;
DECL|member|iDHDRblockx
name|mng_uint32
name|iDHDRblockx
decl_stmt|;
DECL|member|iDHDRblocky
name|mng_uint32
name|iDHDRblocky
decl_stmt|;
DECL|member|iPROMbitdepth
name|mng_uint8
name|iPROMbitdepth
decl_stmt|;
DECL|member|iPROMcolortype
name|mng_uint8
name|iPROMcolortype
decl_stmt|;
DECL|member|iPROMfilltype
name|mng_uint8
name|iPROMfilltype
decl_stmt|;
DECL|member|iPPLTtype
name|mng_uint8
name|iPPLTtype
decl_stmt|;
DECL|member|iPPLTcount
name|mng_uint32
name|iPPLTcount
decl_stmt|;
DECL|member|paPPLTindexentries
name|mng_palette8ep
name|paPPLTindexentries
decl_stmt|;
DECL|member|paPPLTalphaentries
name|mng_uint8p
name|paPPLTalphaentries
decl_stmt|;
DECL|member|paPPLTusedentries
name|mng_uint8p
name|paPPLTusedentries
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_MAGN
DECL|member|iMAGNfirstid
name|mng_uint16
name|iMAGNfirstid
decl_stmt|;
DECL|member|iMAGNlastid
name|mng_uint16
name|iMAGNlastid
decl_stmt|;
DECL|member|iMAGNmethodX
name|mng_uint8
name|iMAGNmethodX
decl_stmt|;
DECL|member|iMAGNmX
name|mng_uint16
name|iMAGNmX
decl_stmt|;
DECL|member|iMAGNmY
name|mng_uint16
name|iMAGNmY
decl_stmt|;
DECL|member|iMAGNmL
name|mng_uint16
name|iMAGNmL
decl_stmt|;
DECL|member|iMAGNmR
name|mng_uint16
name|iMAGNmR
decl_stmt|;
DECL|member|iMAGNmT
name|mng_uint16
name|iMAGNmT
decl_stmt|;
DECL|member|iMAGNmB
name|mng_uint16
name|iMAGNmB
decl_stmt|;
DECL|member|iMAGNmethodY
name|mng_uint8
name|iMAGNmethodY
decl_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_PAST
DECL|member|iPASTtargetid
name|mng_uint16
name|iPASTtargetid
decl_stmt|;
DECL|member|iPASTtargettype
name|mng_uint8
name|iPASTtargettype
decl_stmt|;
DECL|member|iPASTtargetx
name|mng_int32
name|iPASTtargetx
decl_stmt|;
DECL|member|iPASTtargety
name|mng_int32
name|iPASTtargety
decl_stmt|;
DECL|member|iPASTcount
name|mng_uint32
name|iPASTcount
decl_stmt|;
DECL|member|pPASTsources
name|mng_ptr
name|pPASTsources
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
comment|/* MNG_OPTIMIZE_DISPLAYCALLS */
block|}
DECL|typedef|mng_data
name|mng_data
typedef|;
end_typedef
begin_typedef
DECL|typedef|mng_datap
typedef|typedef
name|mng_data
modifier|*
name|mng_datap
typedef|;
end_typedef
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Internal Callback-Function prototypes                                  * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_typedef
DECL|typedef|mng_displayrow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_displayrow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_restbkgdrow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_restbkgdrow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_correctrow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_correctrow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_retrieverow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_retrieverow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_storerow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_storerow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_processrow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_processrow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_initrowproc
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_initrowproc
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_differrow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_differrow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_scalerow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_scalerow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_deltarow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_deltarow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_promoterow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_promoterow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_fliprow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_fliprow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_tilerow
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_tilerow
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_bitdepth_8
typedef|typedef
name|mng_uint8
function_decl|(
modifier|*
name|mng_bitdepth_8
function_decl|)
parameter_list|(
name|mng_uint8
name|iB
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_bitdepth_16
typedef|typedef
name|mng_uint16
function_decl|(
modifier|*
name|mng_bitdepth_16
function_decl|)
parameter_list|(
name|mng_uint8
name|iB
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_magnify_x
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_magnify_x
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_uint16
name|iMX
parameter_list|,
name|mng_uint16
name|iML
parameter_list|,
name|mng_uint16
name|iMR
parameter_list|,
name|mng_uint32
name|iWidth
parameter_list|,
name|mng_uint8p
name|iSrcline
parameter_list|,
name|mng_uint8p
name|iDstline
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|mng_magnify_y
typedef|typedef
name|mng_retcode
function_decl|(
modifier|*
name|mng_magnify_y
function_decl|)
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_int32
name|iM
parameter_list|,
name|mng_int32
name|iS
parameter_list|,
name|mng_uint32
name|iWidth
parameter_list|,
name|mng_uint8p
name|iSrcline1
parameter_list|,
name|mng_uint8p
name|iSrcline2
parameter_list|,
name|mng_uint8p
name|iDstline
parameter_list|)
function_decl|;
end_typedef
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Routines for swapping byte-order from and to graphic files             * */
end_comment
begin_comment
comment|/* * (This code is adapted from the libpng package)                         * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_BIGENDIAN_SUPPORTED
end_ifndef
begin_function_decl
name|mng_uint32
name|mng_get_uint32
parameter_list|(
name|mng_uint8p
name|pBuf
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_int32
name|mng_get_int32
parameter_list|(
name|mng_uint8p
name|pBuf
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_uint16
name|mng_get_uint16
parameter_list|(
name|mng_uint8p
name|pBuf
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|mng_put_uint32
parameter_list|(
name|mng_uint8p
name|pBuf
parameter_list|,
name|mng_uint32
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|mng_put_int32
parameter_list|(
name|mng_uint8p
name|pBuf
parameter_list|,
name|mng_int32
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|mng_put_uint16
parameter_list|(
name|mng_uint8p
name|pBuf
parameter_list|,
name|mng_uint16
name|i
parameter_list|)
function_decl|;
end_function_decl
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* MNG_BIGENDIAN_SUPPORTED */
end_comment
begin_define
DECL|macro|mng_get_uint32
define|#
directive|define
name|mng_get_uint32
parameter_list|(
name|P
parameter_list|)
value|*(mng_uint32p)(P)
end_define
begin_define
DECL|macro|mng_get_int32
define|#
directive|define
name|mng_get_int32
parameter_list|(
name|P
parameter_list|)
value|*(mng_int32p)(P)
end_define
begin_define
DECL|macro|mng_get_uint16
define|#
directive|define
name|mng_get_uint16
parameter_list|(
name|P
parameter_list|)
value|*(mng_uint16p)(P)
end_define
begin_define
DECL|macro|mng_put_uint32
define|#
directive|define
name|mng_put_uint32
parameter_list|(
name|P
parameter_list|,
name|I
parameter_list|)
value|*(mng_uint32p)(P) = (I)
end_define
begin_define
DECL|macro|mng_put_int32
define|#
directive|define
name|mng_put_int32
parameter_list|(
name|P
parameter_list|,
name|I
parameter_list|)
value|*(mng_int32p)(P) = (I)
end_define
begin_define
DECL|macro|mng_put_uint16
define|#
directive|define
name|mng_put_uint16
parameter_list|(
name|P
parameter_list|,
name|I
parameter_list|)
value|*(mng_uint16p)(P) = (I)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* MNG_BIGENDIAN_SUPPORTED */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Some handy(?) macro definitions                                        * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_define
DECL|macro|MAX_COORD
define|#
directive|define
name|MAX_COORD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)> (b)) ? (a) : (b))
end_define
begin_define
DECL|macro|MIN_COORD
define|#
directive|define
name|MIN_COORD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|(((a)< (b)) ? (a) : (b))
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _libmng_data_h_ */
end_comment
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
