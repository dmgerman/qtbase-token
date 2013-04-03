begin_unit
begin_comment
comment|/*  *    Stack-less Just-In-Time compiler  *  *    Copyright 2009-2012 Zoltan Herczeg (hzmester@freemail.hu). All rights reserved.  *  * Redistribution and use in source and binary forms, with or without modification, are  * permitted provided that the following conditions are met:  *  *   1. Redistributions of source code must retain the above copyright notice, this list of  *      conditions and the following disclaimer.  *  *   2. Redistributions in binary form must reproduce the above copyright notice, this list  *      of conditions and the following disclaimer in the documentation and/or other materials  *      provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND CONTRIBUTORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT  * SHALL THE COPYRIGHT HOLDER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|_SLJIT_CONFIG_H_
end_ifndef
begin_define
DECL|macro|_SLJIT_CONFIG_H_
define|#
directive|define
name|_SLJIT_CONFIG_H_
end_define
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/*  Custom defines                                                       */
end_comment
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* Put your custom defines here. This empty section will never change    which helps maintaining patches (with diff / patch utilities). */
end_comment
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/*  Architecture                                                         */
end_comment
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* Architecture selection. */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_X86_32 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_X86_64 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_ARM_V5 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_ARM_V7 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_ARM_THUMB2 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_PPC_32 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_PPC_64 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_MIPS_32 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_SPARC_32 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_AUTO 1 */
end_comment
begin_comment
comment|/* #define SLJIT_CONFIG_UNSUPPORTED 1 */
end_comment
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/*  Utilities                                                            */
end_comment
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* Useful for thread-safe compiling of global functions. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_UTIL_GLOBAL_LOCK
end_ifndef
begin_comment
comment|/* Enabled by default */
end_comment
begin_define
DECL|macro|SLJIT_UTIL_GLOBAL_LOCK
define|#
directive|define
name|SLJIT_UTIL_GLOBAL_LOCK
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Implements a stack like data structure (by using mmap / VirtualAlloc). */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_UTIL_STACK
end_ifndef
begin_comment
comment|/* Enabled by default */
end_comment
begin_define
DECL|macro|SLJIT_UTIL_STACK
define|#
directive|define
name|SLJIT_UTIL_STACK
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Single threaded application. Does not require any locks. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_SINGLE_THREADED
end_ifndef
begin_comment
comment|/* Disabled by default. */
end_comment
begin_define
DECL|macro|SLJIT_SINGLE_THREADED
define|#
directive|define
name|SLJIT_SINGLE_THREADED
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/*  Configuration                                                        */
end_comment
begin_comment
comment|/* --------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* If SLJIT_STD_MACROS_DEFINED is not defined, the application should    define SLJIT_MALLOC, SLJIT_FREE, SLJIT_MEMMOVE, and NULL. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_STD_MACROS_DEFINED
end_ifndef
begin_comment
comment|/* Disabled by default. */
end_comment
begin_define
DECL|macro|SLJIT_STD_MACROS_DEFINED
define|#
directive|define
name|SLJIT_STD_MACROS_DEFINED
value|0
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Executable code allocation:    If SLJIT_EXECUTABLE_ALLOCATOR is not defined, the application should    define both SLJIT_MALLOC_EXEC and SLJIT_FREE_EXEC. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_EXECUTABLE_ALLOCATOR
end_ifndef
begin_comment
comment|/* Enabled by default. */
end_comment
begin_define
DECL|macro|SLJIT_EXECUTABLE_ALLOCATOR
define|#
directive|define
name|SLJIT_EXECUTABLE_ALLOCATOR
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Debug checks (assertions, etc.). */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_DEBUG
end_ifndef
begin_comment
comment|/* Enabled by default */
end_comment
begin_define
DECL|macro|SLJIT_DEBUG
define|#
directive|define
name|SLJIT_DEBUG
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Verbose operations */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|SLJIT_VERBOSE
end_ifndef
begin_comment
comment|/* Enabled by default */
end_comment
begin_define
DECL|macro|SLJIT_VERBOSE
define|#
directive|define
name|SLJIT_VERBOSE
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* See the beginning of sljitConfigInternal.h */
end_comment
begin_endif
endif|#
directive|endif
end_endif
end_unit
