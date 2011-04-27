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
comment|/* * file      : libmng_memory.h           copyright (c) 2000-2003 G.Juyn   * */
end_comment
begin_comment
comment|/* * version   : 1.0.0                                                      * */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * purpose   : Memory management (definition)                             * */
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
comment|/* * comment   : Definition of memory management functions                  * */
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
comment|/* *             0.5.3 - 06/12/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - swapped MNG_COPY parameter-names                         * */
end_comment
begin_comment
comment|/* *             0.5.3 - 06/27/2000 - G.Juyn                                * */
end_comment
begin_comment
comment|/* *             - changed size parameter to mng_size_t                     * */
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
name|_libmng_memory_h_
end_ifndef
begin_define
DECL|macro|_libmng_memory_h_
define|#
directive|define
name|_libmng_memory_h_
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_comment
comment|/* *                                                                        * */
end_comment
begin_comment
comment|/* * Generic memory manager macros                                          * */
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
name|MNG_INTERNAL_MEMMNGMT
end_ifdef
begin_define
DECL|macro|MNG_ALLOC
define|#
directive|define
name|MNG_ALLOC
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ P = calloc (1, (mng_size_t)(L)); \                             if (P == 0) { MNG_ERROR (H, MNG_OUTOFMEMORY) } }
end_define
begin_define
DECL|macro|MNG_ALLOCX
define|#
directive|define
name|MNG_ALLOCX
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ P = calloc (1, (mng_size_t)(L)); }
end_define
begin_define
DECL|macro|MNG_FREE
define|#
directive|define
name|MNG_FREE
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ if (P) { free (P); P = 0; } }
end_define
begin_define
DECL|macro|MNG_FREEX
define|#
directive|define
name|MNG_FREEX
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ if (P) free (P); }
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|MNG_ALLOC
define|#
directive|define
name|MNG_ALLOC
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ P = H->fMemalloc ((mng_size_t)(L)); \                             if (P == 0) { MNG_ERROR (H, MNG_OUTOFMEMORY) } }
end_define
begin_define
DECL|macro|MNG_ALLOCX
define|#
directive|define
name|MNG_ALLOCX
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ P = H->fMemalloc ((mng_size_t)(L)); }
end_define
begin_define
DECL|macro|MNG_FREE
define|#
directive|define
name|MNG_FREE
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ if (P) { H->fMemfree (P, (mng_size_t)(L)); P = 0; } }
end_define
begin_define
DECL|macro|MNG_FREEX
define|#
directive|define
name|MNG_FREEX
parameter_list|(
name|H
parameter_list|,
name|P
parameter_list|,
name|L
parameter_list|)
value|{ if (P) { H->fMemfree (P, (mng_size_t)(L)); } }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* mng_internal_memmngmt */
end_comment
begin_define
DECL|macro|MNG_COPY
define|#
directive|define
name|MNG_COPY
parameter_list|(
name|D
parameter_list|,
name|S
parameter_list|,
name|L
parameter_list|)
value|{ memcpy (D, S, (mng_size_t)(L)); }
end_define
begin_comment
comment|/* ************************************************************************** */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* _libmng_memory_h_ */
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
