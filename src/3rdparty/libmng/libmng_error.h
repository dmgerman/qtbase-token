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
comment|/* * file      : libmng_error.h            copyright (c) 2000-2002 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.5                                                      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : Error functions (definition)                               * */
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
comment|/* * comment   : Definition of the generic error-codes and functions        * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * changes   : 0.5.1 - 05/06/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added some errorcodes                                    * */
end_comment
begin_comment
comment|/* *             0.5.1 - 05/08/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added some errorcodes                                    * */
end_comment
begin_comment
comment|/* *             - changed strict-ANSI stuff                                * */
end_comment
begin_comment
comment|/* *             0.5.1 - 05/11/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added application errorcodes (used with callbacks)       * */
end_comment
begin_comment
comment|/* *             - moved chunk-access errorcodes to severity 5              * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/20/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added JNG errorcodes                                     * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/23/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added error tell-tale definition                         * */
end_comment
begin_comment
comment|/* *             0.5.2 - 05/30/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorcodes for delta-image processing              * */
end_comment
begin_comment
comment|/* *             0.5.2 - 06/06/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added errorcode for delayed buffer-processing            * */
end_comment
begin_comment
comment|/* *             - moved errorcodes to "libmng.h"                           * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* *             0.9.1 - 07/15/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added macro + routine to set returncode without          * */
end_comment
begin_comment
comment|/* *               calling error callback                                   * */
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
comment|/* *             1.0.5 - 08/19/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B597134 - libmng pollutes the linker namespace           * */
end_comment
begin_comment
comment|/* *             1.0.5 - 08/20/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added option for soft-handling of errors                 * */
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
name|_libmng_error_h_
end_ifndef
begin_define
DECL|macro|_libmng_error_h_
define|#
directive|define
name|_libmng_error_h_
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Default error routines                                                 * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_function_decl
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
function_decl|;
end_function_decl
begin_function_decl
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
function_decl|;
end_function_decl
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Error handling macros                                                  * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_SOFTERRORS
end_ifdef
begin_define
DECL|macro|MNG_ERROR
define|#
directive|define
name|MNG_ERROR
parameter_list|(
name|D
parameter_list|,
name|C
parameter_list|)
value|{ if (!mng_process_error (D, C, 0, 0)) return C; }
end_define
begin_define
DECL|macro|MNG_ERRORZ
define|#
directive|define
name|MNG_ERRORZ
parameter_list|(
name|D
parameter_list|,
name|Z
parameter_list|)
value|{ if (!mng_process_error (D, MNG_ZLIBERROR, Z, 0)) return MNG_ZLIBERROR; }
end_define
begin_define
DECL|macro|MNG_ERRORJ
define|#
directive|define
name|MNG_ERRORJ
parameter_list|(
name|D
parameter_list|,
name|J
parameter_list|)
value|{ if (!mng_process_error (D, MNG_JPEGERROR, J, 0)) return MNG_JPEGERROR; }
end_define
begin_define
DECL|macro|MNG_ERRORL
define|#
directive|define
name|MNG_ERRORL
parameter_list|(
name|D
parameter_list|,
name|L
parameter_list|)
value|{ if (!mng_process_error (D, MNG_LCMSERROR, L, 0)) return MNG_LCMSERROR; }
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|MNG_ERROR
define|#
directive|define
name|MNG_ERROR
parameter_list|(
name|D
parameter_list|,
name|C
parameter_list|)
value|{ mng_process_error (D, C, 0, 0); return C; }
end_define
begin_define
DECL|macro|MNG_ERRORZ
define|#
directive|define
name|MNG_ERRORZ
parameter_list|(
name|D
parameter_list|,
name|Z
parameter_list|)
value|{ mng_process_error (D, MNG_ZLIBERROR, Z, 0); return MNG_ZLIBERROR; }
end_define
begin_define
DECL|macro|MNG_ERRORJ
define|#
directive|define
name|MNG_ERRORJ
parameter_list|(
name|D
parameter_list|,
name|J
parameter_list|)
value|{ mng_process_error (D, MNG_JPEGERROR, J, 0); return MNG_JPEGERROR; }
end_define
begin_define
DECL|macro|MNG_ERRORL
define|#
directive|define
name|MNG_ERRORL
parameter_list|(
name|D
parameter_list|,
name|L
parameter_list|)
value|{ mng_process_error (D, MNG_LCMSERROR, L, 0); return MNG_LCMSERROR; }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|MNG_RETURN
define|#
directive|define
name|MNG_RETURN
parameter_list|(
name|D
parameter_list|,
name|C
parameter_list|)
value|{ mng_store_error (D, C, 0, 0); return C; }
end_define
begin_define
DECL|macro|MNG_WARNING
define|#
directive|define
name|MNG_WARNING
parameter_list|(
name|D
parameter_list|,
name|C
parameter_list|)
value|{ if (!mng_process_error (D, C, 0, 0)) return C; }
end_define
begin_define
DECL|macro|MNG_VALIDHANDLE
define|#
directive|define
name|MNG_VALIDHANDLE
parameter_list|(
name|H
parameter_list|)
value|{ if ((H == 0) || (((mng_datap)H)->iMagic != MNG_MAGIC)) \                                 return MNG_INVALIDHANDLE; }
end_define
begin_define
DECL|macro|MNG_VALIDHANDLEX
define|#
directive|define
name|MNG_VALIDHANDLEX
parameter_list|(
name|H
parameter_list|)
value|{ if ((H == 0) || (((mng_datap)H)->iMagic != MNG_MAGIC)) \                                 return 0; }
end_define
begin_define
DECL|macro|MNG_VALIDCB
define|#
directive|define
name|MNG_VALIDCB
parameter_list|(
name|D
parameter_list|,
name|C
parameter_list|)
value|{ if (!((mng_datap)D)->C) \                                 MNG_ERROR (((mng_datap)D), MNG_NOCALLBACK) }
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Error string-table entry                                               * */
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
DECL|member|iError
name|mng_retcode
name|iError
decl_stmt|;
DECL|member|zErrortext
name|mng_pchar
name|zErrortext
decl_stmt|;
block|}
DECL|typedef|mng_error_entry
name|mng_error_entry
typedef|;
end_typedef
begin_typedef
DECL|typedef|mng_error_entryp
typedef|typedef
name|mng_error_entry
specifier|const
modifier|*
name|mng_error_entryp
typedef|;
end_typedef
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _libmng_error_h_ */
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
