begin_unit
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
comment|/* * file      : libmng_conf.h             copyright (c) G.Juyn 2000-2004   * */
end_comment
begin_comment
comment|/* * version   : 1.0.9                                                      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : main configuration file                                    * */
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
comment|/* * comment   : The configuration file. Change this to include/exclude     * */
end_comment
begin_comment
comment|/* *             the options you want or do not want in libmng.             * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * changes   : 0.5.2 - 06/02/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - separated configuration-options into this file           * */
end_comment
begin_comment
comment|/* *             - changed to most likely configuration (?)                 * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/03/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed options to create a standard so-library          * */
end_comment
begin_comment
comment|/* *               with everything enabled                                  * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/04/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed options to create a standard win32-dll           * */
end_comment
begin_comment
comment|/* *               with everything enabled                                  * */
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
comment|/* *             0.9.3 - 08/12/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added workaround for faulty PhotoShop iCCP chunk         * */
end_comment
begin_comment
comment|/* *             0.9.3 - 09/16/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - removed trace-options from default SO/DLL builds         * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.4 - 06/22/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B526138 - returned IJGSRC6B calling convention to        * */
end_comment
begin_comment
comment|/* *               default for MSVC                                         * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.5 - 09/14/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added event handling for dynamic MNG                     * */
end_comment
begin_comment
comment|/* *             - added 'supports' call to check function availability     * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.6 - 06/22/2002 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added MNG_NO_INCLUDE_JNG conditional                     * */
end_comment
begin_comment
comment|/* *             - added MNG_SKIPCHUNK_evNT conditional                     * */
end_comment
begin_comment
comment|/* *             1.0.6 - 07/14/2002 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added MNG_NO_SUPPORT_FUNCQUERY conditional               * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.7 - 03/07/2004 - G.R-P                                 * */
end_comment
begin_comment
comment|/* *             - added MNG_VERSION_QUERY_SUPPORT_ conditional             * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             1.0.9 - 05/12/2004 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - clearified MNG_BIGENDIAN_SUPPORTED conditional           * */
end_comment
begin_comment
comment|/* *             - added MNG_LITTLEENDIAN_SUPPORTED conditional             * */
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
name|_libmng_conf_h_
end_ifndef
begin_define
DECL|macro|_libmng_conf_h_
define|#
directive|define
name|_libmng_conf_h_
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_MOZILLA_CFG
end_ifdef
begin_include
include|#
directive|include
file|"special\mozcfg\mozlibmngconf.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *  User-selectable compile-time options                                  * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable exactly one(1) of the MNG-(sub)set selectors */
end_comment
begin_comment
comment|/* use this to select which (sub)set of the MNG specification you wish    to support */
end_comment
begin_comment
comment|/* generally you'll want full support as the library provides it automatically    for you! if you're really strung on memory-requirements you can opt    to enable less support (but it's just NOT a good idea!) */
end_comment
begin_comment
comment|/* NOTE that this isn't actually implemented yet */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_FULL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_LC
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_VLC
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_FULL
define|#
directive|define
name|MNG_SUPPORT_FULL
end_define
begin_comment
comment|/* #define MNG_SUPPORT_LC */
end_comment
begin_comment
comment|/* #define MNG_SUPPORT_VLC */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable JPEG support if required */
end_comment
begin_comment
comment|/* use this to enable the JNG support routines */
end_comment
begin_comment
comment|/* this requires an external jpeg package;    currently only IJG's jpgsrc6b is supported! */
end_comment
begin_comment
comment|/* NOTE that the IJG code can be either 8- or 12-bit (eg. not both);    so choose the one you've defined in jconfig.h; if you don't know what    the heck I'm talking about, just leave it at 8-bit support (thank you!) */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_NO_INCLUDE_JNG
end_ifndef
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_SUPPORT_FULL
end_ifdef
begin_comment
comment|/* full support includes JNG */
end_comment
begin_define
DECL|macro|MNG_SUPPORT_IJG6B
define|#
directive|define
name|MNG_SUPPORT_IJG6B
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_SUPPORT_IJG6B
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_IJG6B
define|#
directive|define
name|MNG_SUPPORT_IJG6B
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_SUPPORT_IJG6B
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_JPEG8
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_JPEG12
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_JPEG8
define|#
directive|define
name|MNG_SUPPORT_JPEG8
end_define
begin_comment
comment|/* #define MNG_SUPPORT_JPEG12 */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* The following is required to export the IJG routines from the DLL in    the Windows-standard calling convention;    currently this only works for Borland C++ !!! */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_SUPPORT_IJG6B
argument_list|)
operator|&&
name|defined
argument_list|(
name|__BORLANDC__
argument_list|)
end_if
begin_define
DECL|macro|MNG_DEFINE_JPEG_STDCALL
define|#
directive|define
name|MNG_DEFINE_JPEG_STDCALL
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable required high-level functions */
end_comment
begin_comment
comment|/* use this to select the high-level functions you require */
end_comment
begin_comment
comment|/* if you only need to display a MNG, disable write support! */
end_comment
begin_comment
comment|/* if you only need to examine a MNG, disable write& display support! */
end_comment
begin_comment
comment|/* if you only need to copy a MNG, disable display support! */
end_comment
begin_comment
comment|/* if you only need to create a MNG, disable read& display support! */
end_comment
begin_comment
comment|/* NOTE that turning all options off will be very unuseful! */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_READ
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_WRITE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_DISPLAY
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_READ
define|#
directive|define
name|MNG_SUPPORT_READ
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_WRITE
define|#
directive|define
name|MNG_SUPPORT_WRITE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|MNG_SUPPORT_DISPLAY
define|#
directive|define
name|MNG_SUPPORT_DISPLAY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable chunk access functions */
end_comment
begin_comment
comment|/* use this to select whether you need access to the individual chunks */
end_comment
begin_comment
comment|/* useful if you want to examine a read MNG (you'll also need MNG_STORE_CHUNKS !)*/
end_comment
begin_comment
comment|/* required if you need to create& write a new MNG! */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_ACCESS_CHUNKS
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_ACCESS_CHUNKS
define|#
directive|define
name|MNG_ACCESS_CHUNKS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable exactly one(1) of the color-management functionality selectors */
end_comment
begin_comment
comment|/* use this to select the level of automatic color support */
end_comment
begin_comment
comment|/* MNG_FULL_CMS requires the lcms (little cms) external package ! */
end_comment
begin_comment
comment|/* if you want your own app (or the OS) to handle color-management    select MNG_APP_CMS */
end_comment
begin_define
DECL|macro|MNG_GAMMA_ONLY
define|#
directive|define
name|MNG_GAMMA_ONLY
end_define
begin_comment
comment|/* #define MNG_FULL_CMS */
end_comment
begin_comment
comment|/* #define MNG_APP_CMS */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable automatic dithering */
end_comment
begin_comment
comment|/* use this if you need dithering support to convert high-resolution    images to a low-resolution output-device */
end_comment
begin_comment
comment|/* NOTE that this is not supported yet */
end_comment
begin_comment
comment|/* #define MNG_AUTO_DITHER */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable whether chunks should be stored for reference later */
end_comment
begin_comment
comment|/* use this if you need to examine the chunks of a MNG you have read,    or (re-)write a MNG you have read */
end_comment
begin_comment
comment|/* turn this off if you want to reduce memory-consumption */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_STORE_CHUNKS
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_STORE_CHUNKS
define|#
directive|define
name|MNG_STORE_CHUNKS
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable internal memory management (if your compiler supports it) */
end_comment
begin_comment
comment|/* use this if your compiler supports the 'standard' memory functions    (calloc& free), and you want the library to use these functions and not    bother your app with memory-callbacks */
end_comment
begin_comment
comment|/* #define MNG_INTERNAL_MEMMNGMT */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable internal tracing-functionality (manual debugging purposes) */
end_comment
begin_comment
comment|/* use this if you have trouble location bugs or problems */
end_comment
begin_comment
comment|/* NOTE that you'll need to specify the trace callback function! */
end_comment
begin_comment
comment|/* #define MNG_SUPPORT_TRACE */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable extended error- and trace-telltaling */
end_comment
begin_comment
comment|/* use this if you need explanatory messages with errors and/or tracing */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MNG_ERROR_TELLTALE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_TRACE_TELLTALE
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_ERROR_TELLTALE
define|#
directive|define
name|MNG_ERROR_TELLTALE
end_define
begin_define
DECL|macro|MNG_TRACE_TELLTALE
define|#
directive|define
name|MNG_TRACE_TELLTALE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable BIG/LITTLE endian optimizations */
end_comment
begin_comment
comment|/* enable BIG if you're on an architecture that supports big-endian reads    and writes that aren't word-aligned */
end_comment
begin_comment
comment|/* according to reliable sources this only works for PowerPC (bigendian mode)    and 680x0 */
end_comment
begin_comment
comment|/* enable LITTLE if you're on an architecture that supports little-endian */
end_comment
begin_comment
comment|/* when in doubt leave both off !!! */
end_comment
begin_comment
comment|/* #define MNG_BIGENDIAN_SUPPORTED */
end_comment
begin_comment
comment|/* #define MNG_LITTLEENDIAN_SUPPORTED */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable 'version' functions */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MNG_VERSION_QUERY_SUPPORT
argument_list|)
operator|&&
expr|\
operator|!
name|defined
argument_list|(
name|MNG_NO_VERSION_QUERY_SUPPORT
argument_list|)
end_if
begin_define
DECL|macro|MNG_VERSION_QUERY_SUPPORT
define|#
directive|define
name|MNG_VERSION_QUERY_SUPPORT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* enable 'supports' function */
end_comment
begin_comment
comment|/* use this if you need to query the availability of functions at runtime;    useful for apps that dynamically load the library and that need specific    functions */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MNG_NO_SUPPORT_FUNCQUERY
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|MNG_SUPPORT_FUNCQUERY
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_FUNCQUERY
define|#
directive|define
name|MNG_SUPPORT_FUNCQUERY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* enable dynamic MNG features */
end_comment
begin_comment
comment|/* use this if you would like to have dynamic support for specifically    designed MNGs; eg. this is useful for 'rollover' effects such as common    on the world wide web */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_SUPPORT_DYNAMICMNG
end_ifndef
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_BUILD_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_SO
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_BUILD_DLL
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_USE_DLL
argument_list|)
end_if
begin_define
DECL|macro|MNG_SUPPORT_DYNAMICMNG
define|#
directive|define
name|MNG_SUPPORT_DYNAMICMNG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_SUPPORT_DYNAMICMNG
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_SKIPCHUNK_evNT
end_ifndef
begin_define
DECL|macro|MNG_SKIPCHUNK_evNT
define|#
directive|define
name|MNG_SKIPCHUNK_evNT
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_INCLUDE_JNG
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_NO_ACCESS_JPEG
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_ACCESS_JPEG
end_ifndef
begin_define
DECL|macro|MNG_ACCESS_JPEG
define|#
directive|define
name|MNG_ACCESS_JPEG
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_INCLUDE_ZLIB
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_NO_ACCESS_ZLIB
end_ifndef
begin_ifndef
ifndef|#
directive|ifndef
name|MNG_ACCESS_ZLIB
end_ifndef
begin_define
DECL|macro|MNG_ACCESS_ZLIB
define|#
directive|define
name|MNG_ACCESS_ZLIB
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *  End of user-selectable compile-time options                           * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _libmng_conf_h_ */
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
