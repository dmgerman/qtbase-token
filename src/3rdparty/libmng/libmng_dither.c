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
comment|/* * file      : libmng_dither.c           copyright (c) 2000-2004 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.9                                                      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : Dithering routines (implementation)                        * */
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
comment|/* * comment   : implementation of the dithering routines                   * */
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
comment|/* *             1.0.5 - 08/19/2002 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - B597134 - libmng pollutes the linker namespace           * */
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
begin_include
include|#
directive|include
file|"libmng_dither.h"
end_include
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
begin_function
DECL|function|mng_dither_a_row
name|mng_retcode
name|mng_dither_a_row
parameter_list|(
name|mng_datap
name|pData
parameter_list|,
name|mng_uint8p
name|pRow
parameter_list|)
block|{
return|return
name|MNG_NOERROR
return|;
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
