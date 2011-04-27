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
comment|/* * file      : libmng_cms.h              copyright (c) 2000-2003 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.6                                                      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : color management routines (definition)                     * */
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
comment|/* * comment   : Definition of color management routines                    * */
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
comment|/* *             0.5.1 - 05/11/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added creatememprofile                                   * */
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
comment|/* *             1.0.1 - 04/25/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - moved mng_clear_cms to libmng_cms                        * */
end_comment
begin_comment
comment|/* *             1.0.1 - 05/02/2001 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - added "default" sRGB generation (Thanks Marti!)          * */
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
comment|/* *             1.0.5 - 09/19/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - optimized color-correction routines                      * */
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
name|_libmng_cms_h_
end_ifndef
begin_define
DECL|macro|_libmng_cms_h_
define|#
directive|define
name|_libmng_cms_h_
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_INCLUDE_LCMS
end_ifdef
begin_function_decl
name|void
name|mnglcms_initlibrary
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_cmsprof
name|mnglcms_createfileprofile
parameter_list|(
name|mng_pchar
name|zFilename
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_cmsprof
name|mnglcms_creatememprofile
parameter_list|(
name|mng_uint32
name|iProfilesize
parameter_list|,
name|mng_ptr
name|pProfile
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_cmsprof
name|mnglcms_createsrgbprofile
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|mnglcms_freeprofile
parameter_list|(
name|mng_cmsprof
name|hProf
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|void
name|mnglcms_freetransform
parameter_list|(
name|mng_cmstrans
name|hTrans
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mng_clear_cms
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
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
name|MNG_FULL_CMS
end_ifdef
begin_function_decl
name|mng_retcode
name|mng_init_full_cms
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_bool
name|bGlobal
parameter_list|,
name|mng_bool
name|bObject
parameter_list|,
name|mng_bool
name|bRetrobj
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mng_correct_full_cms
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|MNG_FULL_CMS
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_GAMMA_ONLY
argument_list|)
operator|||
name|defined
argument_list|(
name|MNG_APP_CMS
argument_list|)
end_if
begin_function_decl
name|mng_retcode
name|mng_init_gamma_only
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_bool
name|bGlobal
parameter_list|,
name|mng_bool
name|bObject
parameter_list|,
name|mng_bool
name|bRetrobj
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mng_correct_gamma_only
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|MNG_APP_CMS
end_ifdef
begin_function_decl
name|mng_retcode
name|mng_init_app_cms
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_bool
name|bGlobal
parameter_list|,
name|mng_bool
name|bObject
parameter_list|,
name|mng_bool
name|bRetrobj
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mng_correct_app_cms
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _libmng_cms_h_ */
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
