begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftmemory.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    The FreeType memory management macros (specification).               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2002, 2004-2007, 2010, 2013 by                          */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg                       */
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
name|__FTMEMORY_H__
end_ifndef
begin_define
DECL|macro|__FTMEMORY_H__
define|#
directive|define
name|__FTMEMORY_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_CONFIG_CONFIG_H
end_include
begin_include
include|#
directive|include
include|FT_TYPES_H
end_include
begin_expr_stmt
name|FT_BEGIN_HEADER
comment|/*************************************************************************/
comment|/*                                                                       */
comment|/*<Macro>                                                               */
comment|/*    FT_SET_ERROR                                                       */
comment|/*                                                                       */
comment|/*<Description>                                                         */
comment|/*    This macro is used to set an implicit `error' variable to a given  */
comment|/*    expression's value (usually a function call), and convert it to a  */
comment|/*    boolean which is set whenever the value is != 0.                   */
comment|/*                                                                       */
DECL|macro|FT_SET_ERROR
undef|#
directive|undef
name|FT_SET_ERROR
DECL|macro|FT_SET_ERROR
define|#
directive|define
name|FT_SET_ERROR
parameter_list|(
name|expression
parameter_list|)
define|\
value|( ( error = (expression) ) != 0 )
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/****                                                                 ****/
comment|/****                                                                 ****/
comment|/****                           M E M O R Y                           ****/
comment|/****                                                                 ****/
comment|/****                                                                 ****/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*************************************************************************/
comment|/*    *  C++ refuses to handle statements like p = (void*)anything, with `p' a    *  typed pointer.  Since we don't have a `typeof' operator in standard    *  C++, we have to use a template to emulate it.    */
ifdef|#
directive|ifdef
name|__cplusplus
specifier|extern
literal|"C++"
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|T
operator|*
DECL|function|cplusplus_typeof
name|cplusplus_typeof
argument_list|(
argument|T*
argument_list|,
argument|void  *v
argument_list|)
block|{
return|return
name|static_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|v
operator|)
return|;
block|}
end_expr_stmt
begin_define
DECL|macro|FT_ASSIGNP
define|#
directive|define
name|FT_ASSIGNP
parameter_list|(
name|p
parameter_list|,
name|val
parameter_list|)
value|(p) = cplusplus_typeof( (p), (val) )
end_define
begin_else
else|#
directive|else
end_else
begin_define
define|#
directive|define
name|FT_ASSIGNP
parameter_list|(
name|p
parameter_list|,
name|val
parameter_list|)
value|(p) = (val)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_MEMORY
end_ifdef
begin_macro
name|FT_BASE
argument_list|(
argument|const char*
argument_list|)
end_macro
begin_expr_stmt
name|_ft_debug_file
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|long
argument_list|)
end_macro
begin_expr_stmt
name|_ft_debug_lineno
expr_stmt|;
end_expr_stmt
begin_define
DECL|macro|FT_DEBUG_INNER
define|#
directive|define
name|FT_DEBUG_INNER
parameter_list|(
name|exp
parameter_list|)
value|( _ft_debug_file   = __FILE__, \                                  _ft_debug_lineno = __LINE__, \                                  (exp) )
end_define
begin_define
DECL|macro|FT_ASSIGNP_INNER
define|#
directive|define
name|FT_ASSIGNP_INNER
parameter_list|(
name|p
parameter_list|,
name|exp
parameter_list|)
value|( _ft_debug_file   = __FILE__, \                                       _ft_debug_lineno = __LINE__, \                                       FT_ASSIGNP( p, exp ) )
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_DEBUG_MEMORY */
end_comment
begin_define
DECL|macro|FT_DEBUG_INNER
define|#
directive|define
name|FT_DEBUG_INNER
parameter_list|(
name|exp
parameter_list|)
value|(exp)
end_define
begin_define
DECL|macro|FT_ASSIGNP_INNER
define|#
directive|define
name|FT_ASSIGNP_INNER
parameter_list|(
name|p
parameter_list|,
name|exp
parameter_list|)
value|FT_ASSIGNP( p, exp )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_DEBUG_MEMORY */
end_comment
begin_comment
comment|/*    *  The allocation functions return a pointer, and the error code    *  is written to through the `p_error' parameter.  See below for    *  for documentation.    */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
name|ft_mem_alloc
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_Long    size
argument_list|,
argument|FT_Error  *p_error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
DECL|variable|ft_mem_qalloc
name|ft_mem_qalloc
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_Long    size
argument_list|,
argument|FT_Error  *p_error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
name|ft_mem_realloc
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_Long    item_size
argument_list|,
argument|FT_Long    cur_count
argument_list|,
argument|FT_Long    new_count
argument_list|,
argument|void*      block
argument_list|,
argument|FT_Error  *p_error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
DECL|variable|ft_mem_qrealloc
name|ft_mem_qrealloc
argument_list|(
argument|FT_Memory  memory
argument_list|,
argument|FT_Long    item_size
argument_list|,
argument|FT_Long    cur_count
argument_list|,
argument|FT_Long    new_count
argument_list|,
argument|void*      block
argument_list|,
argument|FT_Error  *p_error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|ft_mem_free
argument_list|(
argument|FT_Memory    memory
argument_list|,
argument|const void*  P
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|FT_MEM_ALLOC
define|#
directive|define
name|FT_MEM_ALLOC
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_alloc( memory,          \                                                (FT_Long)(size), \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_FREE
define|#
directive|define
name|FT_MEM_FREE
parameter_list|(
name|ptr
parameter_list|)
define|\
value|FT_BEGIN_STMNT                  \             ft_mem_free( memory, (ptr) ); \             (ptr) = NULL;                 \           FT_END_STMNT
end_define
begin_define
DECL|macro|FT_MEM_NEW
define|#
directive|define
name|FT_MEM_NEW
parameter_list|(
name|ptr
parameter_list|)
define|\
value|FT_MEM_ALLOC( ptr, sizeof ( *(ptr) ) )
end_define
begin_define
DECL|macro|FT_MEM_REALLOC
define|#
directive|define
name|FT_MEM_REALLOC
parameter_list|(
name|ptr
parameter_list|,
name|cursz
parameter_list|,
name|newsz
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_realloc( memory,           \                                                  1,                \                                                  (FT_Long)(cursz), \                                                  (FT_Long)(newsz), \                                                  (ptr),            \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_QALLOC
define|#
directive|define
name|FT_MEM_QALLOC
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_qalloc( memory,          \                                                 (FT_Long)(size), \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_QNEW
define|#
directive|define
name|FT_MEM_QNEW
parameter_list|(
name|ptr
parameter_list|)
define|\
value|FT_MEM_QALLOC( ptr, sizeof ( *(ptr) ) )
end_define
begin_define
DECL|macro|FT_MEM_QREALLOC
define|#
directive|define
name|FT_MEM_QREALLOC
parameter_list|(
name|ptr
parameter_list|,
name|cursz
parameter_list|,
name|newsz
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_qrealloc( memory,           \                                                   1,                \                                                   (FT_Long)(cursz), \                                                   (FT_Long)(newsz), \                                                   (ptr),            \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_ALLOC_MULT
define|#
directive|define
name|FT_MEM_ALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|,
name|item_size
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_realloc( memory,               \                                                  (FT_Long)(item_size), \                                                  0,                    \                                                  (FT_Long)(count),     \                                                  NULL,                 \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_REALLOC_MULT
define|#
directive|define
name|FT_MEM_REALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|oldcnt
parameter_list|,
name|newcnt
parameter_list|,
name|itmsz
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_realloc( memory,            \                                                  (FT_Long)(itmsz),  \                                                  (FT_Long)(oldcnt), \                                                  (FT_Long)(newcnt), \                                                  (ptr),             \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_QALLOC_MULT
define|#
directive|define
name|FT_MEM_QALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|,
name|item_size
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_qrealloc( memory,               \                                                   (FT_Long)(item_size), \                                                   0,                    \                                                   (FT_Long)(count),     \                                                   NULL,                 \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_QREALLOC_MULT
define|#
directive|define
name|FT_MEM_QREALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|oldcnt
parameter_list|,
name|newcnt
parameter_list|,
name|itmsz
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_qrealloc( memory,            \                                                   (FT_Long)(itmsz),  \                                                   (FT_Long)(oldcnt), \                                                   (FT_Long)(newcnt), \                                                   (ptr),             \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_SET_ERROR
define|#
directive|define
name|FT_MEM_SET_ERROR
parameter_list|(
name|cond
parameter_list|)
value|( (cond), error != 0 )
end_define
begin_define
DECL|macro|FT_MEM_SET
define|#
directive|define
name|FT_MEM_SET
parameter_list|(
name|dest
parameter_list|,
name|byte
parameter_list|,
name|count
parameter_list|)
value|ft_memset( dest, byte, count )
end_define
begin_define
DECL|macro|FT_MEM_COPY
define|#
directive|define
name|FT_MEM_COPY
parameter_list|(
name|dest
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
value|ft_memcpy( dest, source, count )
end_define
begin_define
DECL|macro|FT_MEM_MOVE
define|#
directive|define
name|FT_MEM_MOVE
parameter_list|(
name|dest
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
value|ft_memmove( dest, source, count )
end_define
begin_define
DECL|macro|FT_MEM_ZERO
define|#
directive|define
name|FT_MEM_ZERO
parameter_list|(
name|dest
parameter_list|,
name|count
parameter_list|)
value|FT_MEM_SET( dest, 0, count )
end_define
begin_define
DECL|macro|FT_ZERO
define|#
directive|define
name|FT_ZERO
parameter_list|(
name|p
parameter_list|)
value|FT_MEM_ZERO( p, sizeof ( *(p) ) )
end_define
begin_define
DECL|macro|FT_ARRAY_ZERO
define|#
directive|define
name|FT_ARRAY_ZERO
parameter_list|(
name|dest
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_MEM_ZERO( dest, (count) * sizeof ( *(dest) ) )
end_define
begin_define
DECL|macro|FT_ARRAY_COPY
define|#
directive|define
name|FT_ARRAY_COPY
parameter_list|(
name|dest
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_MEM_COPY( dest, source, (count) * sizeof ( *(dest) ) )
end_define
begin_define
DECL|macro|FT_ARRAY_MOVE
define|#
directive|define
name|FT_ARRAY_MOVE
parameter_list|(
name|dest
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_MEM_MOVE( dest, source, (count) * sizeof ( *(dest) ) )
end_define
begin_comment
comment|/*    *  Return the maximum number of addressable elements in an array.    *  We limit ourselves to INT_MAX, rather than UINT_MAX, to avoid    *  any problems.    */
end_comment
begin_define
DECL|macro|FT_ARRAY_MAX
define|#
directive|define
name|FT_ARRAY_MAX
parameter_list|(
name|ptr
parameter_list|)
value|( FT_INT_MAX / sizeof ( *(ptr) ) )
end_define
begin_define
DECL|macro|FT_ARRAY_CHECK
define|#
directive|define
name|FT_ARRAY_CHECK
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|)
value|( (count)<= FT_ARRAY_MAX( ptr ) )
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* The following functions macros expect that their pointer argument is  */
end_comment
begin_comment
comment|/* _typed_ in order to automatically compute array element sizes.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_define
DECL|macro|FT_MEM_NEW_ARRAY
define|#
directive|define
name|FT_MEM_NEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_realloc( memory,            \                                                  sizeof ( *(ptr) ), \                                                  0,                 \                                                  (FT_Long)(count),  \                                                  NULL,              \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_RENEW_ARRAY
define|#
directive|define
name|FT_MEM_RENEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|cursz
parameter_list|,
name|newsz
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_realloc( memory,            \                                                  sizeof ( *(ptr) ), \                                                  (FT_Long)(cursz),  \                                                  (FT_Long)(newsz),  \                                                  (ptr),             \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_QNEW_ARRAY
define|#
directive|define
name|FT_MEM_QNEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_qrealloc( memory,            \                                                   sizeof ( *(ptr) ), \                                                   0,                 \                                                   (FT_Long)(count),  \                                                   NULL,              \&error ) )
end_define
begin_define
DECL|macro|FT_MEM_QRENEW_ARRAY
define|#
directive|define
name|FT_MEM_QRENEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|cursz
parameter_list|,
name|newsz
parameter_list|)
define|\
value|FT_ASSIGNP_INNER( ptr, ft_mem_qrealloc( memory,            \                                                   sizeof ( *(ptr) ), \                                                   (FT_Long)(cursz),  \                                                   (FT_Long)(newsz),  \                                                   (ptr),             \&error ) )
end_define
begin_define
DECL|macro|FT_ALLOC
define|#
directive|define
name|FT_ALLOC
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_ALLOC( ptr, size ) )
end_define
begin_define
DECL|macro|FT_REALLOC
define|#
directive|define
name|FT_REALLOC
parameter_list|(
name|ptr
parameter_list|,
name|cursz
parameter_list|,
name|newsz
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_REALLOC( ptr, cursz, newsz ) )
end_define
begin_define
DECL|macro|FT_ALLOC_MULT
define|#
directive|define
name|FT_ALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|,
name|item_size
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_ALLOC_MULT( ptr, count, item_size ) )
end_define
begin_define
DECL|macro|FT_REALLOC_MULT
define|#
directive|define
name|FT_REALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|oldcnt
parameter_list|,
name|newcnt
parameter_list|,
name|itmsz
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_REALLOC_MULT( ptr, oldcnt,      \                                                  newcnt, itmsz ) )
end_define
begin_define
DECL|macro|FT_QALLOC
define|#
directive|define
name|FT_QALLOC
parameter_list|(
name|ptr
parameter_list|,
name|size
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_QALLOC( ptr, size ) )
end_define
begin_define
DECL|macro|FT_QREALLOC
define|#
directive|define
name|FT_QREALLOC
parameter_list|(
name|ptr
parameter_list|,
name|cursz
parameter_list|,
name|newsz
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_QREALLOC( ptr, cursz, newsz ) )
end_define
begin_define
DECL|macro|FT_QALLOC_MULT
define|#
directive|define
name|FT_QALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|,
name|item_size
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_QALLOC_MULT( ptr, count, item_size ) )
end_define
begin_define
DECL|macro|FT_QREALLOC_MULT
define|#
directive|define
name|FT_QREALLOC_MULT
parameter_list|(
name|ptr
parameter_list|,
name|oldcnt
parameter_list|,
name|newcnt
parameter_list|,
name|itmsz
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_QREALLOC_MULT( ptr, oldcnt,      \                                                   newcnt, itmsz ) )
end_define
begin_define
DECL|macro|FT_FREE
define|#
directive|define
name|FT_FREE
parameter_list|(
name|ptr
parameter_list|)
value|FT_MEM_FREE( ptr )
end_define
begin_define
DECL|macro|FT_NEW
define|#
directive|define
name|FT_NEW
parameter_list|(
name|ptr
parameter_list|)
value|FT_MEM_SET_ERROR( FT_MEM_NEW( ptr ) )
end_define
begin_define
DECL|macro|FT_NEW_ARRAY
define|#
directive|define
name|FT_NEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_NEW_ARRAY( ptr, count ) )
end_define
begin_define
DECL|macro|FT_RENEW_ARRAY
define|#
directive|define
name|FT_RENEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|curcnt
parameter_list|,
name|newcnt
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_RENEW_ARRAY( ptr, curcnt, newcnt ) )
end_define
begin_define
DECL|macro|FT_QNEW
define|#
directive|define
name|FT_QNEW
parameter_list|(
name|ptr
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_QNEW( ptr ) )
end_define
begin_define
DECL|macro|FT_QNEW_ARRAY
define|#
directive|define
name|FT_QNEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|count
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_NEW_ARRAY( ptr, count ) )
end_define
begin_define
DECL|macro|FT_QRENEW_ARRAY
define|#
directive|define
name|FT_QRENEW_ARRAY
parameter_list|(
name|ptr
parameter_list|,
name|curcnt
parameter_list|,
name|newcnt
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_RENEW_ARRAY( ptr, curcnt, newcnt ) )
end_define
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
name|ft_mem_strdup
argument_list|(
argument|FT_Memory    memory
argument_list|,
argument|const char*  str
argument_list|,
argument|FT_Error    *p_error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Pointer
argument_list|)
end_macro
begin_macro
DECL|variable|ft_mem_dup
name|ft_mem_dup
argument_list|(
argument|FT_Memory    memory
argument_list|,
argument|const void*  address
argument_list|,
argument|FT_ULong     size
argument_list|,
argument|FT_Error    *p_error
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|FT_MEM_STRDUP
define|#
directive|define
name|FT_MEM_STRDUP
parameter_list|(
name|dst
parameter_list|,
name|str
parameter_list|)
define|\
value|(dst) = (char*)ft_mem_strdup( memory, (const char*)(str),&error )
end_define
begin_define
DECL|macro|FT_STRDUP
define|#
directive|define
name|FT_STRDUP
parameter_list|(
name|dst
parameter_list|,
name|str
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_STRDUP( dst, str ) )
end_define
begin_define
DECL|macro|FT_MEM_DUP
define|#
directive|define
name|FT_MEM_DUP
parameter_list|(
name|dst
parameter_list|,
name|address
parameter_list|,
name|size
parameter_list|)
define|\
value|(dst) = ft_mem_dup( memory, (address), (FT_ULong)(size),&error )
end_define
begin_define
DECL|macro|FT_DUP
define|#
directive|define
name|FT_DUP
parameter_list|(
name|dst
parameter_list|,
name|address
parameter_list|,
name|size
parameter_list|)
define|\
value|FT_MEM_SET_ERROR( FT_MEM_DUP( dst, address, size ) )
end_define
begin_comment
comment|/* Return>= 1 if a truncation occurs.            */
end_comment
begin_comment
comment|/* Return 0 if the source string fits the buffer. */
end_comment
begin_comment
comment|/* This is *not* the same as strlcpy().           */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_macro
name|ft_mem_strcpyn
argument_list|(
argument|char*        dst
argument_list|,
argument|const char*  src
argument_list|,
argument|FT_ULong     size
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_define
DECL|macro|FT_STRCPYN
define|#
directive|define
name|FT_STRCPYN
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|size
parameter_list|)
define|\
value|ft_mem_strcpyn( (char*)dst, (const char*)(src), (FT_ULong)(size) )
end_define
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
comment|/* __FTMEMORY_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
