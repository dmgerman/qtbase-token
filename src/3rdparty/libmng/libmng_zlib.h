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
comment|/* * file      : libmng_zlib.h             copyright (c) 2000-2002 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.0                                                      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : ZLIB package interface (definition)                        * */
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
comment|/* * comment   : Definition of the ZLIB package interface                   * */
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
comment|/* *             0.9.2 - 08/05/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed file-prefixes                                    * */
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
name|_libmng_zlib_h_
end_ifndef
begin_define
DECL|macro|_libmng_zlib_h_
define|#
directive|define
name|_libmng_zlib_h_
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_function_decl
name|mng_retcode
name|mngzlib_initialize
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_cleanup
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_inflateinit
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_inflaterows
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_uint32
name|iInlen
parameter_list|,
name|mng_uint8p
name|pIndata
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_inflatedata
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_uint32
name|iInlen
parameter_list|,
name|mng_uint8p
name|pIndata
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_inflatefree
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_deflateinit
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_deflaterows
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_uint32
name|iInlen
parameter_list|,
name|mng_uint8p
name|pIndata
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_deflatedata
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_uint32
name|iInlen
parameter_list|,
name|mng_uint8p
name|pIndata
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|mng_retcode
name|mngzlib_deflatefree
parameter_list|(
name|mng_datap
name|pData
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _libmng_zlib_h_ */
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
