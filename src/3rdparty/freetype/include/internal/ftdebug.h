begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftdebug.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    Debugging and logging component (specification).                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 1996-2002, 2004, 2006-2009, 2013 by                          */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
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
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  IMPORTANT: A description of FreeType's debugging support can be        */
end_comment
begin_comment
comment|/*             found in `docs/DEBUG.TXT'.  Read it if you need to use or   */
end_comment
begin_comment
comment|/*             understand this code.                                       */
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
name|__FTDEBUG_H__
end_ifndef
begin_define
DECL|macro|__FTDEBUG_H__
define|#
directive|define
name|__FTDEBUG_H__
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
include|FT_FREETYPE_H
end_include
begin_macro
name|FT_BEGIN_HEADER
end_macro
begin_comment
comment|/* force the definition of FT_DEBUG_LEVEL_ERROR if FT_DEBUG_LEVEL_TRACE */
end_comment
begin_comment
comment|/* is already defined; this simplifies the following #ifdefs            */
end_comment
begin_comment
comment|/*                                                                      */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
end_ifdef
begin_undef
DECL|macro|FT_DEBUG_LEVEL_ERROR
undef|#
directive|undef
name|FT_DEBUG_LEVEL_ERROR
end_undef
begin_define
DECL|macro|FT_DEBUG_LEVEL_ERROR
define|#
directive|define
name|FT_DEBUG_LEVEL_ERROR
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Define the trace enums as well as the trace levels array when they    */
end_comment
begin_comment
comment|/* are needed.                                                           */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
end_ifdef
begin_define
DECL|macro|FT_TRACE_DEF
define|#
directive|define
name|FT_TRACE_DEF
parameter_list|(
name|x
parameter_list|)
value|trace_ ## x ,
end_define
begin_comment
comment|/* defining the enumeration */
end_comment
begin_typedef
DECL|enum|FT_Trace_
typedef|typedef
enum|enum
name|FT_Trace_
block|{
include|#
directive|include
include|FT_INTERNAL_TRACE_H
DECL|enumerator|trace_count
name|trace_count
block|}
DECL|typedef|FT_Trace
name|FT_Trace
typedef|;
end_typedef
begin_comment
comment|/* defining the array of trace levels, provided by `src/base/ftdebug.c' */
end_comment
begin_decl_stmt
specifier|extern
name|int
name|ft_trace_levels
index|[
name|trace_count
index|]
decl_stmt|;
end_decl_stmt
begin_undef
DECL|macro|FT_TRACE_DEF
undef|#
directive|undef
name|FT_TRACE_DEF
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_DEBUG_LEVEL_TRACE */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Define the FT_TRACE macro                                             */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* IMPORTANT!                                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Each component must define the macro FT_COMPONENT to a valid FT_Trace */
end_comment
begin_comment
comment|/* value before using any TRACE macro.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_TRACE
end_ifdef
begin_define
DECL|macro|FT_TRACE
define|#
directive|define
name|FT_TRACE
parameter_list|(
name|level
parameter_list|,
name|varformat
parameter_list|)
define|\
value|do                                              \           {                                               \             if ( ft_trace_levels[FT_COMPONENT]>= level ) \               FT_Message varformat;                       \           } while ( 0 )
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_DEBUG_LEVEL_TRACE */
end_comment
begin_define
DECL|macro|FT_TRACE
define|#
directive|define
name|FT_TRACE
parameter_list|(
name|level
parameter_list|,
name|varformat
parameter_list|)
value|do { } while ( 0 )
end_define
begin_comment
DECL|macro|FT_TRACE
comment|/* nothing */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_DEBUG_LEVEL_TRACE */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Trace_Get_Count                                                 */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the number of available trace components.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The number of trace components.  0 if FreeType 2 is not built with */
end_comment
begin_comment
comment|/*    FT_DEBUG_LEVEL_TRACE definition.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    This function may be useful if you want to access elements of      */
end_comment
begin_comment
comment|/*    the internal `ft_trace_levels' array by an index.                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|FT_Int
argument_list|)
end_macro
begin_expr_stmt
name|FT_Trace_Get_Count
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Function>                                                            */
end_comment
begin_comment
comment|/*    FT_Trace_Get_Name                                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Description>                                                         */
end_comment
begin_comment
comment|/*    Return the name of a trace component.                              */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Input>                                                               */
end_comment
begin_comment
comment|/*    The index of the trace component.                                  */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Return>                                                              */
end_comment
begin_comment
comment|/*    The name of the trace component.  This is a statically allocated   */
end_comment
begin_comment
comment|/*    C string, so do not free it after use.  NULL if FreeType 2 is not  */
end_comment
begin_comment
comment|/*    built with FT_DEBUG_LEVEL_TRACE definition.                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*<Note>                                                                */
end_comment
begin_comment
comment|/*    Use @FT_Trace_Get_Count to get the number of available trace       */
end_comment
begin_comment
comment|/*    components.                                                        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*    This function may be useful if you want to control FreeType 2's    */
end_comment
begin_comment
comment|/*    debug level in your application.                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|const char *
argument_list|)
end_macro
begin_macro
DECL|variable|FT_Trace_Get_Name
name|FT_Trace_Get_Name
argument_list|(
argument|FT_Int  idx
argument_list|)
end_macro
begin_empty_stmt
DECL|variable|FT_Trace_Get_Name
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* You need two opening and closing parentheses!                         */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Example: FT_TRACE0(( "Value is %i", foo ))                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Output of the FT_TRACEX macros is sent to stderr.                     */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_define
DECL|macro|FT_TRACE0
define|#
directive|define
name|FT_TRACE0
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 0, varformat )
end_define
begin_define
DECL|macro|FT_TRACE1
define|#
directive|define
name|FT_TRACE1
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 1, varformat )
end_define
begin_define
DECL|macro|FT_TRACE2
define|#
directive|define
name|FT_TRACE2
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 2, varformat )
end_define
begin_define
DECL|macro|FT_TRACE3
define|#
directive|define
name|FT_TRACE3
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 3, varformat )
end_define
begin_define
DECL|macro|FT_TRACE4
define|#
directive|define
name|FT_TRACE4
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 4, varformat )
end_define
begin_define
DECL|macro|FT_TRACE5
define|#
directive|define
name|FT_TRACE5
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 5, varformat )
end_define
begin_define
DECL|macro|FT_TRACE6
define|#
directive|define
name|FT_TRACE6
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 6, varformat )
end_define
begin_define
DECL|macro|FT_TRACE7
define|#
directive|define
name|FT_TRACE7
parameter_list|(
name|varformat
parameter_list|)
value|FT_TRACE( 7, varformat )
end_define
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Define the FT_ERROR macro.                                            */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Output of this macro is sent to stderr.                               */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_ERROR
end_ifdef
begin_define
DECL|macro|FT_ERROR
define|#
directive|define
name|FT_ERROR
parameter_list|(
name|varformat
parameter_list|)
value|FT_Message  varformat
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_DEBUG_LEVEL_ERROR */
end_comment
begin_define
DECL|macro|FT_ERROR
define|#
directive|define
name|FT_ERROR
parameter_list|(
name|varformat
parameter_list|)
value|do { } while ( 0 )
end_define
begin_comment
DECL|macro|FT_ERROR
comment|/* nothing */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_DEBUG_LEVEL_ERROR */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Define the FT_ASSERT and FT_THROW macros.  The call to `FT_Throw'     */
end_comment
begin_comment
comment|/* makes it possible to easily set a breakpoint at this function.        */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_ERROR
end_ifdef
begin_define
DECL|macro|FT_ASSERT
define|#
directive|define
name|FT_ASSERT
parameter_list|(
name|condition
parameter_list|)
define|\
value|do                                                        \           {                                                         \             if ( !( condition ) )                                   \               FT_Panic( "assertion failed on line %d of file %s\n", \                         __LINE__, __FILE__ );                       \           } while ( 0 )
end_define
begin_define
DECL|macro|FT_THROW
define|#
directive|define
name|FT_THROW
parameter_list|(
name|e
parameter_list|)
define|\
value|( FT_Throw( FT_ERR_CAT( FT_ERR_PREFIX, e ),   \                       __LINE__,                         \                       __FILE__ )                      | \             FT_ERR_CAT( FT_ERR_PREFIX, e )            )
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* !FT_DEBUG_LEVEL_ERROR */
end_comment
begin_define
DECL|macro|FT_ASSERT
define|#
directive|define
name|FT_ASSERT
parameter_list|(
name|condition
parameter_list|)
value|do { } while ( 0 )
end_define
begin_define
DECL|macro|FT_THROW
define|#
directive|define
name|FT_THROW
parameter_list|(
name|e
parameter_list|)
value|FT_ERR_CAT( FT_ERR_PREFIX, e )
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* !FT_DEBUG_LEVEL_ERROR */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Define `FT_Message' and `FT_Panic' when needed.                       */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|FT_DEBUG_LEVEL_ERROR
end_ifdef
begin_include
include|#
directive|include
file|"stdio.h"
end_include
begin_comment
comment|/* for vfprintf() */
end_comment
begin_comment
comment|/* print a message */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|FT_Message
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/* print a message and exit */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|FT_Panic
argument_list|(
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|/* report file name and line number of an error */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|int
argument_list|)
end_macro
begin_macro
name|FT_Throw
argument_list|(
argument|FT_Error     error
argument_list|,
argument|int          line
argument_list|,
argument|const char*  file
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* FT_DEBUG_LEVEL_ERROR */
end_comment
begin_macro
name|FT_BASE
argument_list|(
argument|void
argument_list|)
end_macro
begin_expr_stmt
name|ft_debug_init
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTDEBUG_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
