begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  ftstdlib.h                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    ANSI-specific library and header configuration file (specification   */
end_comment
begin_comment
comment|/*    only).                                                               */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2002, 2003, 2004, 2005, 2006, 2007, 2009 by                  */
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
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* This file is used to group all #includes to the ANSI C library that   */
end_comment
begin_comment
comment|/* FreeType normally requires.  It also defines macros to rename the     */
end_comment
begin_comment
comment|/* standard functions within the FreeType source code.                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/* Load a file which defines __FTSTDLIB_H__ before this one to override  */
end_comment
begin_comment
comment|/* it.                                                                   */
end_comment
begin_comment
comment|/*                                                                       */
end_comment
begin_comment
comment|/*************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__FTSTDLIB_H__
end_ifndef
begin_define
DECL|macro|__FTSTDLIB_H__
define|#
directive|define
name|__FTSTDLIB_H__
end_define
begin_include
include|#
directive|include
file|<stddef.h>
end_include
begin_define
DECL|macro|ft_ptrdiff_t
define|#
directive|define
name|ft_ptrdiff_t
value|ptrdiff_t
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                           integer limits                           */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/* UINT_MAX and ULONG_MAX are used to automatically compute the size  */
end_comment
begin_comment
comment|/* of `int' and `long' in bytes at compile-time.  So far, this works  */
end_comment
begin_comment
comment|/* for all platforms the library has been tested on.                  */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/* Note that on the extremely rare platforms that do not provide      */
end_comment
begin_comment
comment|/* integer types that are _exactly_ 16 and 32 bits wide (e.g. some    */
end_comment
begin_comment
comment|/* old Crays where `int' is 36 bits), we do not make any guarantee    */
end_comment
begin_comment
comment|/* about the correct behaviour of FT2 with all fonts.                 */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/* In these case, `ftconfig.h' will refuse to compile anyway with a   */
end_comment
begin_comment
comment|/* message like `couldn't find 32-bit type' or something similar.     */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_define
DECL|macro|FT_CHAR_BIT
define|#
directive|define
name|FT_CHAR_BIT
value|CHAR_BIT
end_define
begin_define
DECL|macro|FT_INT_MAX
define|#
directive|define
name|FT_INT_MAX
value|INT_MAX
end_define
begin_define
DECL|macro|FT_INT_MIN
define|#
directive|define
name|FT_INT_MIN
value|INT_MIN
end_define
begin_define
DECL|macro|FT_UINT_MAX
define|#
directive|define
name|FT_UINT_MAX
value|UINT_MAX
end_define
begin_define
DECL|macro|FT_ULONG_MAX
define|#
directive|define
name|FT_ULONG_MAX
value|ULONG_MAX
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                 character and string processing                    */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_include
include|#
directive|include
file|<string.h>
end_include
begin_define
DECL|macro|ft_memchr
define|#
directive|define
name|ft_memchr
value|memchr
end_define
begin_define
DECL|macro|ft_memcmp
define|#
directive|define
name|ft_memcmp
value|memcmp
end_define
begin_define
DECL|macro|ft_memcpy
define|#
directive|define
name|ft_memcpy
value|memcpy
end_define
begin_define
DECL|macro|ft_memmove
define|#
directive|define
name|ft_memmove
value|memmove
end_define
begin_define
DECL|macro|ft_memset
define|#
directive|define
name|ft_memset
value|memset
end_define
begin_define
DECL|macro|ft_strcat
define|#
directive|define
name|ft_strcat
value|strcat
end_define
begin_define
DECL|macro|ft_strcmp
define|#
directive|define
name|ft_strcmp
value|strcmp
end_define
begin_define
DECL|macro|ft_strcpy
define|#
directive|define
name|ft_strcpy
value|strcpy
end_define
begin_define
DECL|macro|ft_strlen
define|#
directive|define
name|ft_strlen
value|strlen
end_define
begin_define
DECL|macro|ft_strncmp
define|#
directive|define
name|ft_strncmp
value|strncmp
end_define
begin_define
DECL|macro|ft_strncpy
define|#
directive|define
name|ft_strncpy
value|strncpy
end_define
begin_define
DECL|macro|ft_strrchr
define|#
directive|define
name|ft_strrchr
value|strrchr
end_define
begin_define
DECL|macro|ft_strstr
define|#
directive|define
name|ft_strstr
value|strstr
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                           file handling                            */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_define
DECL|macro|FT_FILE
define|#
directive|define
name|FT_FILE
value|FILE
end_define
begin_define
DECL|macro|ft_fclose
define|#
directive|define
name|ft_fclose
value|fclose
end_define
begin_define
DECL|macro|ft_fopen
define|#
directive|define
name|ft_fopen
value|fopen
end_define
begin_define
DECL|macro|ft_fread
define|#
directive|define
name|ft_fread
value|fread
end_define
begin_define
DECL|macro|ft_fseek
define|#
directive|define
name|ft_fseek
value|fseek
end_define
begin_define
DECL|macro|ft_ftell
define|#
directive|define
name|ft_ftell
value|ftell
end_define
begin_define
DECL|macro|ft_sprintf
define|#
directive|define
name|ft_sprintf
value|sprintf
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                             sorting                                */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_define
DECL|macro|ft_qsort
define|#
directive|define
name|ft_qsort
value|qsort
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                        memory allocation                           */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_define
DECL|macro|ft_scalloc
define|#
directive|define
name|ft_scalloc
value|calloc
end_define
begin_define
DECL|macro|ft_sfree
define|#
directive|define
name|ft_sfree
value|free
end_define
begin_define
DECL|macro|ft_smalloc
define|#
directive|define
name|ft_smalloc
value|malloc
end_define
begin_define
DECL|macro|ft_srealloc
define|#
directive|define
name|ft_srealloc
value|realloc
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                          miscellaneous                             */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_define
DECL|macro|ft_atol
define|#
directive|define
name|ft_atol
value|atol
end_define
begin_define
DECL|macro|ft_labs
define|#
directive|define
name|ft_labs
value|labs
end_define
begin_comment
comment|/**********************************************************************/
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/*                         execution control                          */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/**********************************************************************/
end_comment
begin_include
include|#
directive|include
file|<setjmp.h>
end_include
begin_define
DECL|macro|ft_jmp_buf
define|#
directive|define
name|ft_jmp_buf
value|jmp_buf
end_define
begin_comment
DECL|macro|ft_jmp_buf
comment|/* note: this cannot be a typedef since */
end_comment
begin_comment
comment|/*       jmp_buf is defined as a macro  */
end_comment
begin_comment
comment|/*       on certain platforms           */
end_comment
begin_define
DECL|macro|ft_longjmp
define|#
directive|define
name|ft_longjmp
value|longjmp
end_define
begin_define
DECL|macro|ft_setjmp
define|#
directive|define
name|ft_setjmp
parameter_list|(
name|b
parameter_list|)
value|setjmp( *(jmp_buf*)&(b) )
end_define
begin_comment
DECL|macro|ft_setjmp
comment|/* same thing here */
end_comment
begin_comment
comment|/* the following is only used for debugging purposes, i.e., if */
end_comment
begin_comment
comment|/* FT_DEBUG_LEVEL_ERROR or FT_DEBUG_LEVEL_TRACE are defined    */
end_comment
begin_include
include|#
directive|include
file|<stdarg.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __FTSTDLIB_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
