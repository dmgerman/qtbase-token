begin_unit
begin_comment
comment|/* -*- c -*-    ----------------------------------------------------------------     Notice that the following BSD-style license applies to this one    file (valgrind.h) only.  The rest of Valgrind is licensed under the    terms of the GNU General Public License, version 2, unless    otherwise indicated.  See the COPYING file in the source    distribution for details.     ----------------------------------------------------------------     This file is part of Valgrind, a dynamic binary instrumentation    framework.     Copyright (C) 2000-2007 Julian Seward.  All rights reserved.     Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions    are met:     1. Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.     2. The origin of this software must not be misrepresented; you must        not claim that you wrote the original software.  If you use this        software in a product, an acknowledgment in the product        documentation would be appreciated but is not required.     3. Altered source versions must be plainly marked as such, and must       not be misrepresented as being the original software.     4. The name of the author may not be used to endorse or promote        products derived from this software without specific prior written        permission.     THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     ----------------------------------------------------------------     Notice that the above BSD-style license applies to this one file    (valgrind.h) only.  The entire rest of Valgrind is licensed under    the terms of the GNU General Public License, version 2.  See the    COPYING file in the source distribution for details.     ----------------------------------------------------------------  */
end_comment
begin_comment
comment|/* This file is for inclusion into client (your!) code.     You can use these macros to manipulate and query Valgrind's     execution inside your own programs.     The resulting executables will still run without Valgrind, just a    little bit more slowly than they otherwise would, but otherwise    unchanged.  When not running on valgrind, each client request    consumes very few (eg. 7) instructions, so the resulting performance    loss is negligible unless you plan to execute client requests    millions of times per second.  Nevertheless, if that is still a    problem, you can compile with the NVALGRIND symbol defined (gcc    -DNVALGRIND) so that client requests are not even compiled in.  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__VALGRIND_H
end_ifndef
begin_define
DECL|macro|__VALGRIND_H
define|#
directive|define
name|__VALGRIND_H
end_define
begin_include
include|#
directive|include
file|<stdarg.h>
end_include
begin_comment
comment|/* Nb: this file might be included in a file compiled with -ansi.  So    we can't use C++ style "//" comments nor the "asm" keyword (instead    use "__asm__"). */
end_comment
begin_comment
comment|/* Derive some tags indicating what the target platform is.  Note    that in this file we're using the compiler's CPP symbols for    identifying architectures, which are different to the ones we use    within the rest of Valgrind.  Note, __powerpc__ is active for both    32 and 64-bit PPC, whereas __powerpc64__ is only active for the    latter (on Linux, that is). */
end_comment
begin_undef
DECL|macro|PLAT_x86_linux
undef|#
directive|undef
name|PLAT_x86_linux
end_undef
begin_undef
DECL|macro|PLAT_amd64_linux
undef|#
directive|undef
name|PLAT_amd64_linux
end_undef
begin_undef
DECL|macro|PLAT_ppc32_linux
undef|#
directive|undef
name|PLAT_ppc32_linux
end_undef
begin_undef
DECL|macro|PLAT_ppc64_linux
undef|#
directive|undef
name|PLAT_ppc64_linux
end_undef
begin_undef
DECL|macro|PLAT_ppc32_aix5
undef|#
directive|undef
name|PLAT_ppc32_aix5
end_undef
begin_undef
DECL|macro|PLAT_ppc64_aix5
undef|#
directive|undef
name|PLAT_ppc64_aix5
end_undef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if
begin_define
DECL|macro|PLAT_x86_linux
define|#
directive|define
name|PLAT_x86_linux
value|1
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_elif
begin_define
DECL|macro|PLAT_amd64_linux
define|#
directive|define
name|PLAT_amd64_linux
value|1
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif
begin_define
DECL|macro|PLAT_ppc32_linux
define|#
directive|define
name|PLAT_ppc32_linux
value|1
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif
begin_define
DECL|macro|PLAT_ppc64_linux
define|#
directive|define
name|PLAT_ppc64_linux
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_elif
begin_define
DECL|macro|PLAT_ppc64_aix5
define|#
directive|define
name|PLAT_ppc64_aix5
value|1
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__64BIT__
argument_list|)
end_elif
begin_define
DECL|macro|PLAT_ppc32_aix5
define|#
directive|define
name|PLAT_ppc32_aix5
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* If we're not compiling for our target platform, don't generate    any inline asms.  */
end_comment
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PLAT_x86_linux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PLAT_amd64_linux
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|PLAT_ppc32_linux
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PLAT_ppc64_linux
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|PLAT_ppc32_aix5
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PLAT_ppc64_aix5
argument_list|)
end_if
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NVALGRIND
argument_list|)
end_if
begin_define
DECL|macro|NVALGRIND
define|#
directive|define
name|NVALGRIND
value|1
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
comment|/* ------------------------------------------------------------------ */
end_comment
begin_comment
comment|/* ARCHITECTURE SPECIFICS for SPECIAL INSTRUCTIONS.  There is nothing */
end_comment
begin_comment
comment|/* in here of use to end-users -- skip to the next section.           */
end_comment
begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|NVALGRIND
argument_list|)
end_if
begin_comment
comment|/* Define NVALGRIND to completely remove the Valgrind magic sequence    from the compiled code (analogous to NDEBUG's effects on    assert()) */
end_comment
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\
value|{                                                              \       (_zzq_rlval) = (_zzq_default);                              \    }
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* ! NVALGRIND */
end_comment
begin_comment
comment|/* The following defines the magic code sequences which the JITter    spots and handles magically.  Don't look too closely at them as    they will rot your brain.     The assembly code sequences for all architectures is in this one    file.  This is because this file must be stand-alone, and we don't    want to have multiple files.     For VALGRIND_DO_CLIENT_REQUEST, we must ensure that the default    value gets put in the return slot, so that everything works when    this is executed not under Valgrind.  Args are passed in a memory    block, and so there's no intrinsic limit to the number that could    be passed, but it's currently five.        The macro args are:        _zzq_rlval    result lvalue       _zzq_default  default value (result returned when running on real CPU)       _zzq_request  request code       _zzq_arg1..5  request params     The other two macros are used to support function wrapping, and are    a lot simpler.  VALGRIND_GET_NR_CONTEXT returns the value of the    guest's NRADDR pseudo-register and whatever other information is    needed to safely run the call original from the wrapper: on    ppc64-linux, the R2 value at the divert point is also needed.  This    information is abstracted into a user-visible type, OrigFn.     VALGRIND_CALL_NOREDIR_* behaves the same as the following on the    guest, but guarantees that the branch instruction will not be    redirected: x86: call *%eax, amd64: call *%rax, ppc32/ppc64:    branch-and-link-to-r11.  VALGRIND_CALL_NOREDIR is just text, not a    complete inline asm, since it needs to be combined with more magic    inline asm stuff to be useful. */
end_comment
begin_comment
comment|/* ------------------------- x86-linux ------------------------- */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_x86_linux
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|nraddr
name|unsigned
name|int
name|nraddr
decl_stmt|;
comment|/* where's the code? */
block|}
DECL|typedef|OrigFn
name|OrigFn
typedef|;
end_typedef
begin_define
DECL|macro|__SPECIAL_INSTRUCTION_PREAMBLE
define|#
directive|define
name|__SPECIAL_INSTRUCTION_PREAMBLE
define|\
value|"roll $3,  %%edi ; roll $13, %%edi\n\t"      \                      "roll $29, %%edi ; roll $19, %%edi\n\t"
end_define
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\
value|{ volatile unsigned int _zzq_args[6];                           \     volatile unsigned int _zzq_result;                            \     _zzq_args[0] = (unsigned int)(_zzq_request);                  \     _zzq_args[1] = (unsigned int)(_zzq_arg1);                     \     _zzq_args[2] = (unsigned int)(_zzq_arg2);                     \     _zzq_args[3] = (unsigned int)(_zzq_arg3);                     \     _zzq_args[4] = (unsigned int)(_zzq_arg4);                     \     _zzq_args[5] = (unsigned int)(_zzq_arg5);                     \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %EDX = client_request ( %EAX ) */
value|\                      "xchgl %%ebx,%%ebx"                          \                      : "=d" (_zzq_result)                         \                      : "a" (&_zzq_args[0]), "0" (_zzq_default)    \                      : "cc", "memory"                             \                     );                                            \     _zzq_rlval = _zzq_result;                                     \   }
end_define
begin_define
DECL|macro|VALGRIND_GET_NR_CONTEXT
define|#
directive|define
name|VALGRIND_GET_NR_CONTEXT
parameter_list|(
name|_zzq_rlval
parameter_list|)
define|\
value|{ volatile OrigFn* _zzq_orig =&(_zzq_rlval);                   \     volatile unsigned int __addr;                                 \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %EAX = guest_NRADDR */
value|\                      "xchgl %%ecx,%%ecx"                          \                      : "=a" (__addr)                              \                      :                                            \                      : "cc", "memory"                             \                     );                                            \     _zzq_orig->nraddr = __addr;                                   \   }
end_define
begin_define
DECL|macro|VALGRIND_CALL_NOREDIR_EAX
define|#
directive|define
name|VALGRIND_CALL_NOREDIR_EAX
define|\
value|__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* call-noredir *%EAX */
value|\                      "xchgl %%edx,%%edx\n\t"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_x86_linux */
end_comment
begin_comment
comment|/* ------------------------ amd64-linux ------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_amd64_linux
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|nraddr
name|unsigned
name|long
name|long
name|int
name|nraddr
decl_stmt|;
comment|/* where's the code? */
block|}
DECL|typedef|OrigFn
name|OrigFn
typedef|;
end_typedef
begin_define
DECL|macro|__SPECIAL_INSTRUCTION_PREAMBLE
define|#
directive|define
name|__SPECIAL_INSTRUCTION_PREAMBLE
define|\
value|"rolq $3,  %%rdi ; rolq $13, %%rdi\n\t"      \                      "rolq $61, %%rdi ; rolq $51, %%rdi\n\t"
end_define
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\
value|{ volatile unsigned long long int _zzq_args[6];                 \     volatile unsigned long long int _zzq_result;                  \     _zzq_args[0] = (unsigned long long int)(_zzq_request);        \     _zzq_args[1] = (unsigned long long int)(_zzq_arg1);           \     _zzq_args[2] = (unsigned long long int)(_zzq_arg2);           \     _zzq_args[3] = (unsigned long long int)(_zzq_arg3);           \     _zzq_args[4] = (unsigned long long int)(_zzq_arg4);           \     _zzq_args[5] = (unsigned long long int)(_zzq_arg5);           \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %RDX = client_request ( %RAX ) */
value|\                      "xchgq %%rbx,%%rbx"                          \                      : "=d" (_zzq_result)                         \                      : "a" (&_zzq_args[0]), "0" (_zzq_default)    \                      : "cc", "memory"                             \                     );                                            \     _zzq_rlval = _zzq_result;                                     \     (void)_zzq_rlval;                                             \   }
end_define
begin_define
DECL|macro|VALGRIND_GET_NR_CONTEXT
define|#
directive|define
name|VALGRIND_GET_NR_CONTEXT
parameter_list|(
name|_zzq_rlval
parameter_list|)
define|\
value|{ volatile OrigFn* _zzq_orig =&(_zzq_rlval);                   \     volatile unsigned long long int __addr;                       \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %RAX = guest_NRADDR */
value|\                      "xchgq %%rcx,%%rcx"                          \                      : "=a" (__addr)                              \                      :                                            \                      : "cc", "memory"                             \                     );                                            \     _zzq_orig->nraddr = __addr;                                   \   }
end_define
begin_define
DECL|macro|VALGRIND_CALL_NOREDIR_RAX
define|#
directive|define
name|VALGRIND_CALL_NOREDIR_RAX
define|\
value|__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* call-noredir *%RAX */
value|\                      "xchgq %%rdx,%%rdx\n\t"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_amd64_linux */
end_comment
begin_comment
comment|/* ------------------------ ppc32-linux ------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc32_linux
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|nraddr
name|unsigned
name|int
name|nraddr
decl_stmt|;
comment|/* where's the code? */
block|}
DECL|typedef|OrigFn
name|OrigFn
typedef|;
end_typedef
begin_define
DECL|macro|__SPECIAL_INSTRUCTION_PREAMBLE
define|#
directive|define
name|__SPECIAL_INSTRUCTION_PREAMBLE
define|\
value|"rlwinm 0,0,3,0,0  ; rlwinm 0,0,13,0,0\n\t"  \                      "rlwinm 0,0,29,0,0 ; rlwinm 0,0,19,0,0\n\t"
end_define
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\                                                                   \
value|{          unsigned int  _zzq_args[6];                          \              unsigned int  _zzq_result;                           \              unsigned int* _zzq_ptr;                              \     _zzq_args[0] = (unsigned int)(_zzq_request);                  \     _zzq_args[1] = (unsigned int)(_zzq_arg1);                     \     _zzq_args[2] = (unsigned int)(_zzq_arg2);                     \     _zzq_args[3] = (unsigned int)(_zzq_arg3);                     \     _zzq_args[4] = (unsigned int)(_zzq_arg4);                     \     _zzq_args[5] = (unsigned int)(_zzq_arg5);                     \     _zzq_ptr = _zzq_args;                                         \     __asm__ volatile("mr 3,%1\n\t"
comment|/*default*/
value|\                      "mr 4,%2\n\t"
comment|/*ptr*/
value|\                      __SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = client_request ( %R4 ) */
value|\                      "or 1,1,1\n\t"                               \                      "mr %0,3"
comment|/*result*/
value|\                      : "=b" (_zzq_result)                         \                      : "b" (_zzq_default), "b" (_zzq_ptr)         \                      : "cc", "memory", "r3", "r4");               \     _zzq_rlval = _zzq_result;                                     \   }
end_define
begin_define
DECL|macro|VALGRIND_GET_NR_CONTEXT
define|#
directive|define
name|VALGRIND_GET_NR_CONTEXT
parameter_list|(
name|_zzq_rlval
parameter_list|)
define|\
value|{ volatile OrigFn* _zzq_orig =&(_zzq_rlval);                   \     unsigned int __addr;                                          \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR */
value|\                      "or 2,2,2\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (__addr)                              \                      :                                            \                      : "cc", "memory", "r3"                       \                     );                                            \     _zzq_orig->nraddr = __addr;                                   \   }
end_define
begin_define
DECL|macro|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|#
directive|define
name|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|\
value|__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* branch-and-link-to-noredir *%R11 */
value|\                      "or 3,3,3\n\t"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc32_linux */
end_comment
begin_comment
comment|/* ------------------------ ppc64-linux ------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc64_linux
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|nraddr
name|unsigned
name|long
name|long
name|int
name|nraddr
decl_stmt|;
comment|/* where's the code? */
DECL|member|r2
name|unsigned
name|long
name|long
name|int
name|r2
decl_stmt|;
comment|/* what tocptr do we need? */
block|}
DECL|typedef|OrigFn
name|OrigFn
typedef|;
end_typedef
begin_define
DECL|macro|__SPECIAL_INSTRUCTION_PREAMBLE
define|#
directive|define
name|__SPECIAL_INSTRUCTION_PREAMBLE
define|\
value|"rotldi 0,0,3  ; rotldi 0,0,13\n\t"          \                      "rotldi 0,0,61 ; rotldi 0,0,51\n\t"
end_define
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\                                                                   \
value|{          unsigned long long int  _zzq_args[6];                \     register unsigned long long int  _zzq_result __asm__("r3");   \     register unsigned long long int* _zzq_ptr __asm__("r4");      \     _zzq_args[0] = (unsigned long long int)(_zzq_request);        \     _zzq_args[1] = (unsigned long long int)(_zzq_arg1);           \     _zzq_args[2] = (unsigned long long int)(_zzq_arg2);           \     _zzq_args[3] = (unsigned long long int)(_zzq_arg3);           \     _zzq_args[4] = (unsigned long long int)(_zzq_arg4);           \     _zzq_args[5] = (unsigned long long int)(_zzq_arg5);           \     _zzq_ptr = _zzq_args;                                         \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = client_request ( %R4 ) */
value|\                      "or 1,1,1"                                   \                      : "=r" (_zzq_result)                         \                      : "0" (_zzq_default), "r" (_zzq_ptr)         \                      : "cc", "memory");                           \     _zzq_rlval = _zzq_result;                                     \   }
end_define
begin_define
DECL|macro|VALGRIND_GET_NR_CONTEXT
define|#
directive|define
name|VALGRIND_GET_NR_CONTEXT
parameter_list|(
name|_zzq_rlval
parameter_list|)
define|\
value|{ volatile OrigFn* _zzq_orig =&(_zzq_rlval);                   \     register unsigned long long int __addr __asm__("r3");         \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR */
value|\                      "or 2,2,2"                                   \                      : "=r" (__addr)                              \                      :                                            \                      : "cc", "memory"                             \                     );                                            \     _zzq_orig->nraddr = __addr;                                   \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR_GPR2 */
value|\                      "or 4,4,4"                                   \                      : "=r" (__addr)                              \                      :                                            \                      : "cc", "memory"                             \                     );                                            \     _zzq_orig->r2 = __addr;                                       \   }
end_define
begin_define
DECL|macro|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|#
directive|define
name|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|\
value|__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* branch-and-link-to-noredir *%R11 */
value|\                      "or 3,3,3\n\t"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc64_linux */
end_comment
begin_comment
comment|/* ------------------------ ppc32-aix5 ------------------------- */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc32_aix5
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|nraddr
name|unsigned
name|int
name|nraddr
decl_stmt|;
comment|/* where's the code? */
DECL|member|r2
name|unsigned
name|int
name|r2
decl_stmt|;
comment|/* what tocptr do we need? */
block|}
DECL|typedef|OrigFn
name|OrigFn
typedef|;
end_typedef
begin_define
DECL|macro|__SPECIAL_INSTRUCTION_PREAMBLE
define|#
directive|define
name|__SPECIAL_INSTRUCTION_PREAMBLE
define|\
value|"rlwinm 0,0,3,0,0  ; rlwinm 0,0,13,0,0\n\t"  \                      "rlwinm 0,0,29,0,0 ; rlwinm 0,0,19,0,0\n\t"
end_define
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\                                                                   \
value|{          unsigned int  _zzq_args[7];                          \     register unsigned int  _zzq_result;                           \     register unsigned int* _zzq_ptr;                              \     _zzq_args[0] = (unsigned int)(_zzq_request);                  \     _zzq_args[1] = (unsigned int)(_zzq_arg1);                     \     _zzq_args[2] = (unsigned int)(_zzq_arg2);                     \     _zzq_args[3] = (unsigned int)(_zzq_arg3);                     \     _zzq_args[4] = (unsigned int)(_zzq_arg4);                     \     _zzq_args[5] = (unsigned int)(_zzq_arg5);                     \     _zzq_args[6] = (unsigned int)(_zzq_default);                  \     _zzq_ptr = _zzq_args;                                         \     __asm__ volatile("mr 4,%1\n\t"                                \                      "lwz 3, 24(4)\n\t"                           \                      __SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = client_request ( %R4 ) */
value|\                      "or 1,1,1\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (_zzq_result)                         \                      : "b" (_zzq_ptr)                             \                      : "r3", "r4", "cc", "memory");               \     _zzq_rlval = _zzq_result;                                     \   }
end_define
begin_define
DECL|macro|VALGRIND_GET_NR_CONTEXT
define|#
directive|define
name|VALGRIND_GET_NR_CONTEXT
parameter_list|(
name|_zzq_rlval
parameter_list|)
define|\
value|{ volatile OrigFn* _zzq_orig =&(_zzq_rlval);                   \     register unsigned int __addr;                                 \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR */
value|\                      "or 2,2,2\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (__addr)                              \                      :                                            \                      : "r3", "cc", "memory"                       \                     );                                            \     _zzq_orig->nraddr = __addr;                                   \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR_GPR2 */
value|\                      "or 4,4,4\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (__addr)                              \                      :                                            \                      : "r3", "cc", "memory"                       \                     );                                            \     _zzq_orig->r2 = __addr;                                       \   }
end_define
begin_define
DECL|macro|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|#
directive|define
name|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|\
value|__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* branch-and-link-to-noredir *%R11 */
value|\                      "or 3,3,3\n\t"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc32_aix5 */
end_comment
begin_comment
comment|/* ------------------------ ppc64-aix5 ------------------------- */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc64_aix5
argument_list|)
end_if
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|nraddr
name|unsigned
name|long
name|long
name|int
name|nraddr
decl_stmt|;
comment|/* where's the code? */
DECL|member|r2
name|unsigned
name|long
name|long
name|int
name|r2
decl_stmt|;
comment|/* what tocptr do we need? */
block|}
DECL|typedef|OrigFn
name|OrigFn
typedef|;
end_typedef
begin_define
DECL|macro|__SPECIAL_INSTRUCTION_PREAMBLE
define|#
directive|define
name|__SPECIAL_INSTRUCTION_PREAMBLE
define|\
value|"rotldi 0,0,3  ; rotldi 0,0,13\n\t"          \                      "rotldi 0,0,61 ; rotldi 0,0,51\n\t"
end_define
begin_define
DECL|macro|VALGRIND_DO_CLIENT_REQUEST
define|#
directive|define
name|VALGRIND_DO_CLIENT_REQUEST
parameter_list|(                               \
name|_zzq_rlval
parameter_list|,
name|_zzq_default
parameter_list|,
name|_zzq_request
parameter_list|,                   \
name|_zzq_arg1
parameter_list|,
name|_zzq_arg2
parameter_list|,
name|_zzq_arg3
parameter_list|,
name|_zzq_arg4
parameter_list|,
name|_zzq_arg5
parameter_list|)
define|\                                                                   \
value|{          unsigned long long int  _zzq_args[7];                \     register unsigned long long int  _zzq_result;                 \     register unsigned long long int* _zzq_ptr;                    \     _zzq_args[0] = (unsigned int long long)(_zzq_request);        \     _zzq_args[1] = (unsigned int long long)(_zzq_arg1);           \     _zzq_args[2] = (unsigned int long long)(_zzq_arg2);           \     _zzq_args[3] = (unsigned int long long)(_zzq_arg3);           \     _zzq_args[4] = (unsigned int long long)(_zzq_arg4);           \     _zzq_args[5] = (unsigned int long long)(_zzq_arg5);           \     _zzq_args[6] = (unsigned int long long)(_zzq_default);        \     _zzq_ptr = _zzq_args;                                         \     __asm__ volatile("mr 4,%1\n\t"                                \                      "ld 3, 48(4)\n\t"                            \                      __SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = client_request ( %R4 ) */
value|\                      "or 1,1,1\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (_zzq_result)                         \                      : "b" (_zzq_ptr)                             \                      : "r3", "r4", "cc", "memory");               \     _zzq_rlval = _zzq_result;                                     \   }
end_define
begin_define
DECL|macro|VALGRIND_GET_NR_CONTEXT
define|#
directive|define
name|VALGRIND_GET_NR_CONTEXT
parameter_list|(
name|_zzq_rlval
parameter_list|)
define|\
value|{ volatile OrigFn* _zzq_orig =&(_zzq_rlval);                   \     register unsigned long long int __addr;                       \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR */
value|\                      "or 2,2,2\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (__addr)                              \                      :                                            \                      : "r3", "cc", "memory"                       \                     );                                            \     _zzq_orig->nraddr = __addr;                                   \     __asm__ volatile(__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* %R3 = guest_NRADDR_GPR2 */
value|\                      "or 4,4,4\n\t"                               \                      "mr %0,3"                                    \                      : "=b" (__addr)                              \                      :                                            \                      : "r3", "cc", "memory"                       \                     );                                            \     _zzq_orig->r2 = __addr;                                       \   }
end_define
begin_define
DECL|macro|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|#
directive|define
name|VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11
define|\
value|__SPECIAL_INSTRUCTION_PREAMBLE               \
comment|/* branch-and-link-to-noredir *%R11 */
value|\                      "or 3,3,3\n\t"
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc64_aix5 */
end_comment
begin_comment
comment|/* Insert assembly code for other platforms here... */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* NVALGRIND */
end_comment
begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment
begin_comment
comment|/* PLATFORM SPECIFICS for FUNCTION WRAPPING.  This is all very        */
end_comment
begin_comment
comment|/* ugly.  It's the least-worst tradeoff I can think of.               */
end_comment
begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment
begin_comment
comment|/* This section defines magic (a.k.a appalling-hack) macros for doing    guaranteed-no-redirection macros, so as to get from function    wrappers to the functions they are wrapping.  The whole point is to    construct standard call sequences, but to do the call itself with a    special no-redirect call pseudo-instruction that the JIT    understands and handles specially.  This section is long and    repetitious, and I can't see a way to make it shorter.     The naming scheme is as follows:        CALL_FN_{W,v}_{v,W,WW,WWW,WWWW,5W,6W,7W,etc}     'W' stands for "word" and 'v' for "void".  Hence there are    different macros for calling arity 0, 1, 2, 3, 4, etc, functions,    and for each, the possibility of returning a word-typed result, or    no result. */
end_comment
begin_comment
comment|/* Use these to write the name of your wrapper.  NOTE: duplicates    VG_WRAP_FUNCTION_Z{U,Z} in pub_tool_redir.h. */
end_comment
begin_define
DECL|macro|I_WRAP_SONAME_FNNAME_ZU
define|#
directive|define
name|I_WRAP_SONAME_FNNAME_ZU
parameter_list|(
name|soname
parameter_list|,
name|fnname
parameter_list|)
define|\
value|_vgwZU_##soname##_##fnname
end_define
begin_define
DECL|macro|I_WRAP_SONAME_FNNAME_ZZ
define|#
directive|define
name|I_WRAP_SONAME_FNNAME_ZZ
parameter_list|(
name|soname
parameter_list|,
name|fnname
parameter_list|)
define|\
value|_vgwZZ_##soname##_##fnname
end_define
begin_comment
comment|/* Use this macro from within a wrapper function to collect the    context (address and possibly other info) of the original function.    Once you have that you can then use it in one of the CALL_FN_    macros.  The type of the argument _lval is OrigFn. */
end_comment
begin_define
DECL|macro|VALGRIND_GET_ORIG_FN
define|#
directive|define
name|VALGRIND_GET_ORIG_FN
parameter_list|(
name|_lval
parameter_list|)
value|VALGRIND_GET_NR_CONTEXT(_lval)
end_define
begin_comment
comment|/* Derivatives of the main macros below, for calling functions    returning void. */
end_comment
begin_define
DECL|macro|CALL_FN_v_v
define|#
directive|define
name|CALL_FN_v_v
parameter_list|(
name|fnptr
parameter_list|)
define|\
value|do { volatile unsigned long _junk;                             \         CALL_FN_W_v(_junk,fnptr); } while (0)
end_define
begin_define
DECL|macro|CALL_FN_v_W
define|#
directive|define
name|CALL_FN_v_W
parameter_list|(
name|fnptr
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do { volatile unsigned long _junk;                             \         CALL_FN_W_W(_junk,fnptr,arg1); } while (0)
end_define
begin_define
DECL|macro|CALL_FN_v_WW
define|#
directive|define
name|CALL_FN_v_WW
parameter_list|(
name|fnptr
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do { volatile unsigned long _junk;                             \         CALL_FN_W_WW(_junk,fnptr,arg1,arg2); } while (0)
end_define
begin_define
DECL|macro|CALL_FN_v_WWW
define|#
directive|define
name|CALL_FN_v_WWW
parameter_list|(
name|fnptr
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do { volatile unsigned long _junk;                             \         CALL_FN_W_WWW(_junk,fnptr,arg1,arg2,arg3); } while (0)
end_define
begin_comment
comment|/* ------------------------- x86-linux ------------------------- */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_x86_linux
argument_list|)
end_if
begin_comment
comment|/* These regs are trashed by the hidden call.  No need to mention eax    as gcc can already see that, plus causes gcc to bomb. */
end_comment
begin_define
DECL|macro|__CALLER_SAVED_REGS
define|#
directive|define
name|__CALLER_SAVED_REGS
comment|/*"eax"*/
value|"ecx", "edx"
end_define
begin_comment
comment|/* These CALL_FN_ macros assume that on x86-linux, sizeof(unsigned    long) == 4. */
end_comment
begin_define
DECL|macro|CALL_FN_W_v
define|#
directive|define
name|CALL_FN_W_v
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[1];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       __asm__ volatile(                                           \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_W
define|#
directive|define
name|CALL_FN_W_W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[2];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       __asm__ volatile(                                           \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $4, %%esp\n"                                       \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WW
define|#
directive|define
name|CALL_FN_W_WW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       __asm__ volatile(                                           \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $8, %%esp\n"                                       \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWW
define|#
directive|define
name|CALL_FN_W_WWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[4];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       __asm__ volatile(                                           \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $12, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWWW
define|#
directive|define
name|CALL_FN_W_WWWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[5];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       __asm__ volatile(                                           \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $16, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_5W
define|#
directive|define
name|CALL_FN_W_5W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[6];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       __asm__ volatile(                                           \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $20, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_6W
define|#
directive|define
name|CALL_FN_W_6W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[7];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       __asm__ volatile(                                           \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $24, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_7W
define|#
directive|define
name|CALL_FN_W_7W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[8];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       __asm__ volatile(                                           \          "pushl 28(%%eax)\n\t"                                    \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $28, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_8W
define|#
directive|define
name|CALL_FN_W_8W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[9];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       __asm__ volatile(                                           \          "pushl 32(%%eax)\n\t"                                    \          "pushl 28(%%eax)\n\t"                                    \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $32, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_9W
define|#
directive|define
name|CALL_FN_W_9W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[10];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       __asm__ volatile(                                           \          "pushl 36(%%eax)\n\t"                                    \          "pushl 32(%%eax)\n\t"                                    \          "pushl 28(%%eax)\n\t"                                    \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $36, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_10W
define|#
directive|define
name|CALL_FN_W_10W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[11];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       _argvec[10] = (unsigned long)(arg10);                       \       __asm__ volatile(                                           \          "pushl 40(%%eax)\n\t"                                    \          "pushl 36(%%eax)\n\t"                                    \          "pushl 32(%%eax)\n\t"                                    \          "pushl 28(%%eax)\n\t"                                    \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $40, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_11W
define|#
directive|define
name|CALL_FN_W_11W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,       \
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,      \
name|arg11
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[12];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       _argvec[10] = (unsigned long)(arg10);                       \       _argvec[11] = (unsigned long)(arg11);                       \       __asm__ volatile(                                           \          "pushl 44(%%eax)\n\t"                                    \          "pushl 40(%%eax)\n\t"                                    \          "pushl 36(%%eax)\n\t"                                    \          "pushl 32(%%eax)\n\t"                                    \          "pushl 28(%%eax)\n\t"                                    \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $44, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_12W
define|#
directive|define
name|CALL_FN_W_12W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,       \
name|arg6
parameter_list|,
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,      \
name|arg11
parameter_list|,
name|arg12
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[13];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       _argvec[10] = (unsigned long)(arg10);                       \       _argvec[11] = (unsigned long)(arg11);                       \       _argvec[12] = (unsigned long)(arg12);                       \       __asm__ volatile(                                           \          "pushl 48(%%eax)\n\t"                                    \          "pushl 44(%%eax)\n\t"                                    \          "pushl 40(%%eax)\n\t"                                    \          "pushl 36(%%eax)\n\t"                                    \          "pushl 32(%%eax)\n\t"                                    \          "pushl 28(%%eax)\n\t"                                    \          "pushl 24(%%eax)\n\t"                                    \          "pushl 20(%%eax)\n\t"                                    \          "pushl 16(%%eax)\n\t"                                    \          "pushl 12(%%eax)\n\t"                                    \          "pushl 8(%%eax)\n\t"                                     \          "pushl 4(%%eax)\n\t"                                     \          "movl (%%eax), %%eax\n\t"
comment|/* target->%eax */
value|\          VALGRIND_CALL_NOREDIR_EAX                                \          "addl $48, %%esp\n"                                      \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_x86_linux */
end_comment
begin_comment
comment|/* ------------------------ amd64-linux ------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_amd64_linux
argument_list|)
end_if
begin_comment
comment|/* ARGREGS: rdi rsi rdx rcx r8 r9 (the rest on stack in R-to-L order) */
end_comment
begin_comment
comment|/* These regs are trashed by the hidden call. */
end_comment
begin_define
DECL|macro|__CALLER_SAVED_REGS
define|#
directive|define
name|__CALLER_SAVED_REGS
comment|/*"rax",*/
value|"rcx", "rdx", "rsi",       \                             "rdi", "r8", "r9", "r10", "r11"
end_define
begin_comment
comment|/* These CALL_FN_ macros assume that on amd64-linux, sizeof(unsigned    long) == 8. */
end_comment
begin_comment
comment|/* NB 9 Sept 07.  There is a nasty kludge here in all these CALL_FN_    macros.  In order not to trash the stack redzone, we need to drop    %rsp by 128 before the hidden call, and restore afterwards.  The    nastyness is that it is only by luck that the stack still appears    to be unwindable during the hidden call - since then the behaviour    of any routine using this macro does not match what the CFI data    says.  Sigh.     Why is this important?  Imagine that a wrapper has a stack    allocated local, and passes to the hidden call, a pointer to it.    Because gcc does not know about the hidden call, it may allocate    that local in the redzone.  Unfortunately the hidden call may then    trash it before it comes to use it.  So we must step clear of the    redzone, for the duration of the hidden call, to make it safe.     Probably the same problem afflicts the other redzone-style ABIs too    (ppc64-linux, ppc32-aix5, ppc64-aix5); but for those, the stack is    self describing (none of this CFI nonsense) so at least messing    with the stack pointer doesn't give a danger of non-unwindable    stack. */
end_comment
begin_define
DECL|macro|CALL_FN_W_v
define|#
directive|define
name|CALL_FN_W_v
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[1];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_W
define|#
directive|define
name|CALL_FN_W_W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[2];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WW
define|#
directive|define
name|CALL_FN_W_WW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWW
define|#
directive|define
name|CALL_FN_W_WWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[4];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWWW
define|#
directive|define
name|CALL_FN_W_WWWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[5];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_5W
define|#
directive|define
name|CALL_FN_W_5W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[6];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_6W
define|#
directive|define
name|CALL_FN_W_6W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[7];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          "addq $128,%%rsp\n\t"                                    \          VALGRIND_CALL_NOREDIR_RAX                                \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_7W
define|#
directive|define
name|CALL_FN_W_7W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[8];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "pushq 56(%%rax)\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $8, %%rsp\n"                                       \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_8W
define|#
directive|define
name|CALL_FN_W_8W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[9];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "pushq 64(%%rax)\n\t"                                    \          "pushq 56(%%rax)\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $16, %%rsp\n"                                      \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_9W
define|#
directive|define
name|CALL_FN_W_9W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[10];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "pushq 72(%%rax)\n\t"                                    \          "pushq 64(%%rax)\n\t"                                    \          "pushq 56(%%rax)\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $24, %%rsp\n"                                      \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_10W
define|#
directive|define
name|CALL_FN_W_10W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[11];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       _argvec[10] = (unsigned long)(arg10);                       \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "pushq 80(%%rax)\n\t"                                    \          "pushq 72(%%rax)\n\t"                                    \          "pushq 64(%%rax)\n\t"                                    \          "pushq 56(%%rax)\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $32, %%rsp\n"                                      \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_11W
define|#
directive|define
name|CALL_FN_W_11W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[12];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       _argvec[10] = (unsigned long)(arg10);                       \       _argvec[11] = (unsigned long)(arg11);                       \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "pushq 88(%%rax)\n\t"                                    \          "pushq 80(%%rax)\n\t"                                    \          "pushq 72(%%rax)\n\t"                                    \          "pushq 64(%%rax)\n\t"                                    \          "pushq 56(%%rax)\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $40, %%rsp\n"                                      \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_12W
define|#
directive|define
name|CALL_FN_W_12W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|,
name|arg12
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[13];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)(arg1);                         \       _argvec[2] = (unsigned long)(arg2);                         \       _argvec[3] = (unsigned long)(arg3);                         \       _argvec[4] = (unsigned long)(arg4);                         \       _argvec[5] = (unsigned long)(arg5);                         \       _argvec[6] = (unsigned long)(arg6);                         \       _argvec[7] = (unsigned long)(arg7);                         \       _argvec[8] = (unsigned long)(arg8);                         \       _argvec[9] = (unsigned long)(arg9);                         \       _argvec[10] = (unsigned long)(arg10);                       \       _argvec[11] = (unsigned long)(arg11);                       \       _argvec[12] = (unsigned long)(arg12);                       \       __asm__ volatile(                                           \          "subq $128,%%rsp\n\t"                                    \          "pushq 96(%%rax)\n\t"                                    \          "pushq 88(%%rax)\n\t"                                    \          "pushq 80(%%rax)\n\t"                                    \          "pushq 72(%%rax)\n\t"                                    \          "pushq 64(%%rax)\n\t"                                    \          "pushq 56(%%rax)\n\t"                                    \          "movq 48(%%rax), %%r9\n\t"                               \          "movq 40(%%rax), %%r8\n\t"                               \          "movq 32(%%rax), %%rcx\n\t"                              \          "movq 24(%%rax), %%rdx\n\t"                              \          "movq 16(%%rax), %%rsi\n\t"                              \          "movq 8(%%rax), %%rdi\n\t"                               \          "movq (%%rax), %%rax\n\t"
comment|/* target->%rax */
value|\          VALGRIND_CALL_NOREDIR_RAX                                \          "addq $48, %%rsp\n"                                      \          "addq $128,%%rsp\n\t"                                    \          :
comment|/*out*/
value|"=a" (_res)                                  \          :
comment|/*in*/
value|"a" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_amd64_linux */
end_comment
begin_comment
comment|/* ------------------------ ppc32-linux ------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc32_linux
argument_list|)
end_if
begin_comment
comment|/* This is useful for finding out about the on-stack stuff:     extern int f9  ( int,int,int,int,int,int,int,int,int );    extern int f10 ( int,int,int,int,int,int,int,int,int,int );    extern int f11 ( int,int,int,int,int,int,int,int,int,int,int );    extern int f12 ( int,int,int,int,int,int,int,int,int,int,int,int );     int g9 ( void ) {       return f9(11,22,33,44,55,66,77,88,99);    }    int g10 ( void ) {       return f10(11,22,33,44,55,66,77,88,99,110);    }    int g11 ( void ) {       return f11(11,22,33,44,55,66,77,88,99,110,121);    }    int g12 ( void ) {       return f12(11,22,33,44,55,66,77,88,99,110,121,132);    } */
end_comment
begin_comment
comment|/* ARGREGS: r3 r4 r5 r6 r7 r8 r9 r10 (the rest on stack somewhere) */
end_comment
begin_comment
comment|/* These regs are trashed by the hidden call. */
end_comment
begin_define
DECL|macro|__CALLER_SAVED_REGS
define|#
directive|define
name|__CALLER_SAVED_REGS
define|\
value|"lr", "ctr", "xer",                                            \    "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",        \    "r0", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10",   \    "r11", "r12", "r13"
end_define
begin_comment
comment|/* These CALL_FN_ macros assume that on ppc32-linux,     sizeof(unsigned long) == 4. */
end_comment
begin_define
DECL|macro|CALL_FN_W_v
define|#
directive|define
name|CALL_FN_W_v
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[1];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_W
define|#
directive|define
name|CALL_FN_W_W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[2];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WW
define|#
directive|define
name|CALL_FN_W_WW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWW
define|#
directive|define
name|CALL_FN_W_WWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[4];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWWW
define|#
directive|define
name|CALL_FN_W_WWWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[5];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_5W
define|#
directive|define
name|CALL_FN_W_5W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[6];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_6W
define|#
directive|define
name|CALL_FN_W_6W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[7];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_7W
define|#
directive|define
name|CALL_FN_W_7W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[8];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       _argvec[7] = (unsigned long)arg7;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 9,28(11)\n\t"                                       \          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_8W
define|#
directive|define
name|CALL_FN_W_8W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[9];                          \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       _argvec[7] = (unsigned long)arg7;                           \       _argvec[8] = (unsigned long)arg8;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 9,28(11)\n\t"                                       \          "lwz 10,32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_9W
define|#
directive|define
name|CALL_FN_W_9W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[10];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       _argvec[7] = (unsigned long)arg7;                           \       _argvec[8] = (unsigned long)arg8;                           \       _argvec[9] = (unsigned long)arg9;                           \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "addi 1,1,-16\n\t"                                       \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,8(1)\n\t"                                         \
comment|/* args1-8 */
value|\          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 9,28(11)\n\t"                                       \          "lwz 10,32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "addi 1,1,16\n\t"                                        \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_10W
define|#
directive|define
name|CALL_FN_W_10W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[11];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       _argvec[7] = (unsigned long)arg7;                           \       _argvec[8] = (unsigned long)arg8;                           \       _argvec[9] = (unsigned long)arg9;                           \       _argvec[10] = (unsigned long)arg10;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "addi 1,1,-16\n\t"                                       \
comment|/* arg10 */
value|\          "lwz 3,40(11)\n\t"                                       \          "stw 3,12(1)\n\t"                                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,8(1)\n\t"                                         \
comment|/* args1-8 */
value|\          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 9,28(11)\n\t"                                       \          "lwz 10,32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "addi 1,1,16\n\t"                                        \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_11W
define|#
directive|define
name|CALL_FN_W_11W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[12];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       _argvec[7] = (unsigned long)arg7;                           \       _argvec[8] = (unsigned long)arg8;                           \       _argvec[9] = (unsigned long)arg9;                           \       _argvec[10] = (unsigned long)arg10;                         \       _argvec[11] = (unsigned long)arg11;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "addi 1,1,-32\n\t"                                       \
comment|/* arg11 */
value|\          "lwz 3,44(11)\n\t"                                       \          "stw 3,16(1)\n\t"                                        \
comment|/* arg10 */
value|\          "lwz 3,40(11)\n\t"                                       \          "stw 3,12(1)\n\t"                                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,8(1)\n\t"                                         \
comment|/* args1-8 */
value|\          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 9,28(11)\n\t"                                       \          "lwz 10,32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "addi 1,1,32\n\t"                                        \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_12W
define|#
directive|define
name|CALL_FN_W_12W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|,
name|arg12
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[13];                         \       volatile unsigned long _res;                                \       _argvec[0] = (unsigned long)_orig.nraddr;                   \       _argvec[1] = (unsigned long)arg1;                           \       _argvec[2] = (unsigned long)arg2;                           \       _argvec[3] = (unsigned long)arg3;                           \       _argvec[4] = (unsigned long)arg4;                           \       _argvec[5] = (unsigned long)arg5;                           \       _argvec[6] = (unsigned long)arg6;                           \       _argvec[7] = (unsigned long)arg7;                           \       _argvec[8] = (unsigned long)arg8;                           \       _argvec[9] = (unsigned long)arg9;                           \       _argvec[10] = (unsigned long)arg10;                         \       _argvec[11] = (unsigned long)arg11;                         \       _argvec[12] = (unsigned long)arg12;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "addi 1,1,-32\n\t"                                       \
comment|/* arg12 */
value|\          "lwz 3,48(11)\n\t"                                       \          "stw 3,20(1)\n\t"                                        \
comment|/* arg11 */
value|\          "lwz 3,44(11)\n\t"                                       \          "stw 3,16(1)\n\t"                                        \
comment|/* arg10 */
value|\          "lwz 3,40(11)\n\t"                                       \          "stw 3,12(1)\n\t"                                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,8(1)\n\t"                                         \
comment|/* args1-8 */
value|\          "lwz 3,4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 4,8(11)\n\t"                                        \          "lwz 5,12(11)\n\t"                                       \          "lwz 6,16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 7,20(11)\n\t"                                       \          "lwz 8,24(11)\n\t"                                       \          "lwz 9,28(11)\n\t"                                       \          "lwz 10,32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11,0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "addi 1,1,32\n\t"                                        \          "mr %0,3"                                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[0])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc32_linux */
end_comment
begin_comment
comment|/* ------------------------ ppc64-linux ------------------------ */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc64_linux
argument_list|)
end_if
begin_comment
comment|/* ARGREGS: r3 r4 r5 r6 r7 r8 r9 r10 (the rest on stack somewhere) */
end_comment
begin_comment
comment|/* These regs are trashed by the hidden call. */
end_comment
begin_define
DECL|macro|__CALLER_SAVED_REGS
define|#
directive|define
name|__CALLER_SAVED_REGS
define|\
value|"lr", "ctr", "xer",                                            \    "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",        \    "r0", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10",   \    "r11", "r12", "r13"
end_define
begin_comment
comment|/* These CALL_FN_ macros assume that on ppc64-linux, sizeof(unsigned    long) == 8. */
end_comment
begin_define
DECL|macro|CALL_FN_W_v
define|#
directive|define
name|CALL_FN_W_v
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+0];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1] = (unsigned long)_orig.r2;                       \       _argvec[2] = (unsigned long)_orig.nraddr;                   \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_W
define|#
directive|define
name|CALL_FN_W_W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+1];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WW
define|#
directive|define
name|CALL_FN_W_WW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+2];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWW
define|#
directive|define
name|CALL_FN_W_WWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+3];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWWW
define|#
directive|define
name|CALL_FN_W_WWWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+4];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_5W
define|#
directive|define
name|CALL_FN_W_5W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+5];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_6W
define|#
directive|define
name|CALL_FN_W_6W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+6];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_7W
define|#
directive|define
name|CALL_FN_W_7W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+7];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_8W
define|#
directive|define
name|CALL_FN_W_8W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+8];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)"
comment|/* restore tocptr */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_9W
define|#
directive|define
name|CALL_FN_W_9W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+9];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "addi 1,1,-128\n\t"
comment|/* expand stack frame */
value|\
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          "addi 1,1,128"
comment|/* restore frame */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_10W
define|#
directive|define
name|CALL_FN_W_10W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+10];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "addi 1,1,-128\n\t"
comment|/* expand stack frame */
value|\
comment|/* arg10 */
value|\          "ld  3,80(11)\n\t"                                       \          "std 3,120(1)\n\t"                                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          "addi 1,1,128"
comment|/* restore frame */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_11W
define|#
directive|define
name|CALL_FN_W_11W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+11];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       _argvec[2+11] = (unsigned long)arg11;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "addi 1,1,-144\n\t"
comment|/* expand stack frame */
value|\
comment|/* arg11 */
value|\          "ld  3,88(11)\n\t"                                       \          "std 3,128(1)\n\t"                                       \
comment|/* arg10 */
value|\          "ld  3,80(11)\n\t"                                       \          "std 3,120(1)\n\t"                                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          "addi 1,1,144"
comment|/* restore frame */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_12W
define|#
directive|define
name|CALL_FN_W_12W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|,
name|arg12
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+12];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       _argvec[2+11] = (unsigned long)arg11;                       \       _argvec[2+12] = (unsigned long)arg12;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          "std 2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "addi 1,1,-144\n\t"
comment|/* expand stack frame */
value|\
comment|/* arg12 */
value|\          "ld  3,96(11)\n\t"                                       \          "std 3,136(1)\n\t"                                       \
comment|/* arg11 */
value|\          "ld  3,88(11)\n\t"                                       \          "std 3,128(1)\n\t"                                       \
comment|/* arg10 */
value|\          "ld  3,80(11)\n\t"                                       \          "std 3,120(1)\n\t"                                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          "addi 1,1,144"
comment|/* restore frame */
value|\          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc64_linux */
end_comment
begin_comment
comment|/* ------------------------ ppc32-aix5 ------------------------- */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc32_aix5
argument_list|)
end_if
begin_comment
comment|/* ARGREGS: r3 r4 r5 r6 r7 r8 r9 r10 (the rest on stack somewhere) */
end_comment
begin_comment
comment|/* These regs are trashed by the hidden call. */
end_comment
begin_define
DECL|macro|__CALLER_SAVED_REGS
define|#
directive|define
name|__CALLER_SAVED_REGS
define|\
value|"lr", "ctr", "xer",                                            \    "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",        \    "r0", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10",   \    "r11", "r12", "r13"
end_define
begin_comment
comment|/* Expand the stack frame, copying enough info that unwinding    still works.  Trashes r3. */
end_comment
begin_define
DECL|macro|VG_EXPAND_FRAME_BY_trashes_r3
define|#
directive|define
name|VG_EXPAND_FRAME_BY_trashes_r3
parameter_list|(
name|_n_fr
parameter_list|)
define|\
value|"addi 1,1,-" #_n_fr "\n\t"                               \          "lwz  3," #_n_fr "(1)\n\t"                               \          "stw  3,0(1)\n\t"
end_define
begin_define
DECL|macro|VG_CONTRACT_FRAME_BY
define|#
directive|define
name|VG_CONTRACT_FRAME_BY
parameter_list|(
name|_n_fr
parameter_list|)
define|\
value|"addi 1,1," #_n_fr "\n\t"
end_define
begin_comment
comment|/* These CALL_FN_ macros assume that on ppc32-aix5, sizeof(unsigned    long) == 4. */
end_comment
begin_define
DECL|macro|CALL_FN_W_v
define|#
directive|define
name|CALL_FN_W_v
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+0];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1] = (unsigned long)_orig.r2;                       \       _argvec[2] = (unsigned long)_orig.nraddr;                   \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_W
define|#
directive|define
name|CALL_FN_W_W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+1];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WW
define|#
directive|define
name|CALL_FN_W_WW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+2];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWW
define|#
directive|define
name|CALL_FN_W_WWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+3];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWWW
define|#
directive|define
name|CALL_FN_W_WWWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+4];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_5W
define|#
directive|define
name|CALL_FN_W_5W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+5];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_6W
define|#
directive|define
name|CALL_FN_W_6W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+6];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_7W
define|#
directive|define
name|CALL_FN_W_7W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+7];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz  9, 28(11)\n\t"
comment|/* arg7->r9 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_8W
define|#
directive|define
name|CALL_FN_W_8W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+8];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz  9, 28(11)\n\t"
comment|/* arg7->r9 */
value|\          "lwz 10, 32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_9W
define|#
directive|define
name|CALL_FN_W_9W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+9];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(64)                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,56(1)\n\t"                                        \
comment|/* args1-8 */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz  9, 28(11)\n\t"
comment|/* arg7->r9 */
value|\          "lwz 10, 32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(64)                                 \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_10W
define|#
directive|define
name|CALL_FN_W_10W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+10];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(64)                        \
comment|/* arg10 */
value|\          "lwz 3,40(11)\n\t"                                       \          "stw 3,60(1)\n\t"                                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,56(1)\n\t"                                        \
comment|/* args1-8 */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz  9, 28(11)\n\t"
comment|/* arg7->r9 */
value|\          "lwz 10, 32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(64)                                 \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_11W
define|#
directive|define
name|CALL_FN_W_11W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+11];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       _argvec[2+11] = (unsigned long)arg11;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(72)                        \
comment|/* arg11 */
value|\          "lwz 3,44(11)\n\t"                                       \          "stw 3,64(1)\n\t"                                        \
comment|/* arg10 */
value|\          "lwz 3,40(11)\n\t"                                       \          "stw 3,60(1)\n\t"                                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,56(1)\n\t"                                        \
comment|/* args1-8 */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz  9, 28(11)\n\t"
comment|/* arg7->r9 */
value|\          "lwz 10, 32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(72)                                 \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_12W
define|#
directive|define
name|CALL_FN_W_12W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|,
name|arg12
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+12];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       _argvec[2+11] = (unsigned long)arg11;                       \       _argvec[2+12] = (unsigned long)arg12;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "stw  2,-8(11)\n\t"
comment|/* save tocptr */
value|\          "lwz  2,-4(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(72)                        \
comment|/* arg12 */
value|\          "lwz 3,48(11)\n\t"                                       \          "stw 3,68(1)\n\t"                                        \
comment|/* arg11 */
value|\          "lwz 3,44(11)\n\t"                                       \          "stw 3,64(1)\n\t"                                        \
comment|/* arg10 */
value|\          "lwz 3,40(11)\n\t"                                       \          "stw 3,60(1)\n\t"                                        \
comment|/* arg9 */
value|\          "lwz 3,36(11)\n\t"                                       \          "stw 3,56(1)\n\t"                                        \
comment|/* args1-8 */
value|\          "lwz  3, 4(11)\n\t"
comment|/* arg1->r3 */
value|\          "lwz  4, 8(11)\n\t"
comment|/* arg2->r4 */
value|\          "lwz  5, 12(11)\n\t"
comment|/* arg3->r5 */
value|\          "lwz  6, 16(11)\n\t"
comment|/* arg4->r6 */
value|\          "lwz  7, 20(11)\n\t"
comment|/* arg5->r7 */
value|\          "lwz  8, 24(11)\n\t"
comment|/* arg6->r8 */
value|\          "lwz  9, 28(11)\n\t"
comment|/* arg7->r9 */
value|\          "lwz 10, 32(11)\n\t"
comment|/* arg8->r10 */
value|\          "lwz 11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "lwz 2,-8(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(72)                                 \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc32_aix5 */
end_comment
begin_comment
comment|/* ------------------------ ppc64-aix5 ------------------------- */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|PLAT_ppc64_aix5
argument_list|)
end_if
begin_comment
comment|/* ARGREGS: r3 r4 r5 r6 r7 r8 r9 r10 (the rest on stack somewhere) */
end_comment
begin_comment
comment|/* These regs are trashed by the hidden call. */
end_comment
begin_define
DECL|macro|__CALLER_SAVED_REGS
define|#
directive|define
name|__CALLER_SAVED_REGS
define|\
value|"lr", "ctr", "xer",                                            \    "cr0", "cr1", "cr2", "cr3", "cr4", "cr5", "cr6", "cr7",        \    "r0", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10",   \    "r11", "r12", "r13"
end_define
begin_comment
comment|/* Expand the stack frame, copying enough info that unwinding    still works.  Trashes r3. */
end_comment
begin_define
DECL|macro|VG_EXPAND_FRAME_BY_trashes_r3
define|#
directive|define
name|VG_EXPAND_FRAME_BY_trashes_r3
parameter_list|(
name|_n_fr
parameter_list|)
define|\
value|"addi 1,1,-" #_n_fr "\n\t"                               \          "ld   3," #_n_fr "(1)\n\t"                               \          "std  3,0(1)\n\t"
end_define
begin_define
DECL|macro|VG_CONTRACT_FRAME_BY
define|#
directive|define
name|VG_CONTRACT_FRAME_BY
parameter_list|(
name|_n_fr
parameter_list|)
define|\
value|"addi 1,1," #_n_fr "\n\t"
end_define
begin_comment
comment|/* These CALL_FN_ macros assume that on ppc64-aix5, sizeof(unsigned    long) == 8. */
end_comment
begin_define
DECL|macro|CALL_FN_W_v
define|#
directive|define
name|CALL_FN_W_v
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+0];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1] = (unsigned long)_orig.r2;                       \       _argvec[2] = (unsigned long)_orig.nraddr;                   \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_W
define|#
directive|define
name|CALL_FN_W_W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+1];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld 2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WW
define|#
directive|define
name|CALL_FN_W_WW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+2];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWW
define|#
directive|define
name|CALL_FN_W_WWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+3];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_WWWW
define|#
directive|define
name|CALL_FN_W_WWWW
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+4];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_5W
define|#
directive|define
name|CALL_FN_W_5W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+5];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_6W
define|#
directive|define
name|CALL_FN_W_6W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+6];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_7W
define|#
directive|define
name|CALL_FN_W_7W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+7];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_8W
define|#
directive|define
name|CALL_FN_W_8W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+8];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_9W
define|#
directive|define
name|CALL_FN_W_9W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,   \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+9];                        \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(128)                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(128)                                \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_10W
define|#
directive|define
name|CALL_FN_W_10W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+10];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(128)                       \
comment|/* arg10 */
value|\          "ld  3,80(11)\n\t"                                       \          "std 3,120(1)\n\t"                                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(128)                                \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_11W
define|#
directive|define
name|CALL_FN_W_11W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+11];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       _argvec[2+11] = (unsigned long)arg11;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(144)                       \
comment|/* arg11 */
value|\          "ld  3,88(11)\n\t"                                       \          "std 3,128(1)\n\t"                                       \
comment|/* arg10 */
value|\          "ld  3,80(11)\n\t"                                       \          "std 3,120(1)\n\t"                                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(144)                                \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_define
DECL|macro|CALL_FN_W_12W
define|#
directive|define
name|CALL_FN_W_12W
parameter_list|(
name|lval
parameter_list|,
name|orig
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|,
name|arg4
parameter_list|,
name|arg5
parameter_list|,
name|arg6
parameter_list|,  \
name|arg7
parameter_list|,
name|arg8
parameter_list|,
name|arg9
parameter_list|,
name|arg10
parameter_list|,
name|arg11
parameter_list|,
name|arg12
parameter_list|)
define|\
value|do {                                                           \       volatile OrigFn        _orig = (orig);                      \       volatile unsigned long _argvec[3+12];                       \       volatile unsigned long _res;                                \
comment|/* _argvec[0] holds current r2 across the call */
value|\       _argvec[1]   = (unsigned long)_orig.r2;                     \       _argvec[2]   = (unsigned long)_orig.nraddr;                 \       _argvec[2+1] = (unsigned long)arg1;                         \       _argvec[2+2] = (unsigned long)arg2;                         \       _argvec[2+3] = (unsigned long)arg3;                         \       _argvec[2+4] = (unsigned long)arg4;                         \       _argvec[2+5] = (unsigned long)arg5;                         \       _argvec[2+6] = (unsigned long)arg6;                         \       _argvec[2+7] = (unsigned long)arg7;                         \       _argvec[2+8] = (unsigned long)arg8;                         \       _argvec[2+9] = (unsigned long)arg9;                         \       _argvec[2+10] = (unsigned long)arg10;                       \       _argvec[2+11] = (unsigned long)arg11;                       \       _argvec[2+12] = (unsigned long)arg12;                       \       __asm__ volatile(                                           \          "mr 11,%1\n\t"                                           \          VG_EXPAND_FRAME_BY_trashes_r3(512)                       \          "std  2,-16(11)\n\t"
comment|/* save tocptr */
value|\          "ld   2,-8(11)\n\t"
comment|/* use nraddr's tocptr */
value|\          VG_EXPAND_FRAME_BY_trashes_r3(144)                       \
comment|/* arg12 */
value|\          "ld  3,96(11)\n\t"                                       \          "std 3,136(1)\n\t"                                       \
comment|/* arg11 */
value|\          "ld  3,88(11)\n\t"                                       \          "std 3,128(1)\n\t"                                       \
comment|/* arg10 */
value|\          "ld  3,80(11)\n\t"                                       \          "std 3,120(1)\n\t"                                       \
comment|/* arg9 */
value|\          "ld  3,72(11)\n\t"                                       \          "std 3,112(1)\n\t"                                       \
comment|/* args1-8 */
value|\          "ld   3, 8(11)\n\t"
comment|/* arg1->r3 */
value|\          "ld   4, 16(11)\n\t"
comment|/* arg2->r4 */
value|\          "ld   5, 24(11)\n\t"
comment|/* arg3->r5 */
value|\          "ld   6, 32(11)\n\t"
comment|/* arg4->r6 */
value|\          "ld   7, 40(11)\n\t"
comment|/* arg5->r7 */
value|\          "ld   8, 48(11)\n\t"
comment|/* arg6->r8 */
value|\          "ld   9, 56(11)\n\t"
comment|/* arg7->r9 */
value|\          "ld  10, 64(11)\n\t"
comment|/* arg8->r10 */
value|\          "ld  11, 0(11)\n\t"
comment|/* target->r11 */
value|\          VALGRIND_BRANCH_AND_LINK_TO_NOREDIR_R11                  \          "mr 11,%1\n\t"                                           \          "mr %0,3\n\t"                                            \          "ld  2,-16(11)\n\t"
comment|/* restore tocptr */
value|\          VG_CONTRACT_FRAME_BY(144)                                \          VG_CONTRACT_FRAME_BY(512)                                \          :
comment|/*out*/
value|"=r" (_res)                                  \          :
comment|/*in*/
value|"r" (&_argvec[2])                            \          :
comment|/*trash*/
value|"cc", "memory", __CALLER_SAVED_REGS          \       );                                                          \       lval = (__typeof__(lval)) _res;                             \    } while (0)
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* PLAT_ppc64_aix5 */
end_comment
begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment
begin_comment
comment|/* ARCHITECTURE INDEPENDENT MACROS for CLIENT REQUESTS.               */
end_comment
begin_comment
comment|/*                                                                    */
end_comment
begin_comment
comment|/* ------------------------------------------------------------------ */
end_comment
begin_comment
comment|/* Some request codes.  There are many more of these, but most are not    exposed to end-user view.  These are the public ones, all of the    form 0x1000 + small_number.     Core ones are in the range 0x00000000--0x0000ffff.  The non-public    ones start at 0x2000. */
end_comment
begin_comment
comment|/* These macros are used by tools -- they must be public, but don't    embed them into other programs. */
end_comment
begin_define
DECL|macro|VG_USERREQ_TOOL_BASE
define|#
directive|define
name|VG_USERREQ_TOOL_BASE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((unsigned int)(((a)&0xff)<< 24 | ((b)&0xff)<< 16))
end_define
begin_define
DECL|macro|VG_IS_TOOL_USERREQ
define|#
directive|define
name|VG_IS_TOOL_USERREQ
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|v
parameter_list|)
define|\
value|(VG_USERREQ_TOOL_BASE(a,b) == ((v)& 0xffff0000))
end_define
begin_comment
comment|/* !! ABIWARNING !! ABIWARNING !! ABIWARNING !! ABIWARNING !!     This enum comprises an ABI exported by Valgrind to programs    which use client requests.  DO NOT CHANGE THE ORDER OF THESE    ENTRIES, NOR DELETE ANY -- add new ones at the end. */
end_comment
begin_typedef
typedef|typedef
DECL|enumerator|VG_USERREQ__RUNNING_ON_VALGRIND
enum|enum
block|{
name|VG_USERREQ__RUNNING_ON_VALGRIND
init|=
literal|0x1001
block|,
DECL|enumerator|VG_USERREQ__DISCARD_TRANSLATIONS
name|VG_USERREQ__DISCARD_TRANSLATIONS
init|=
literal|0x1002
block|,
comment|/* These allow any function to be called from the simulated              CPU but run on the real CPU.  Nb: the first arg passed to              the function is always the ThreadId of the running              thread!  So CLIENT_CALL0 actually requires a 1 arg              function, etc. */
DECL|enumerator|VG_USERREQ__CLIENT_CALL0
name|VG_USERREQ__CLIENT_CALL0
init|=
literal|0x1101
block|,
DECL|enumerator|VG_USERREQ__CLIENT_CALL1
name|VG_USERREQ__CLIENT_CALL1
init|=
literal|0x1102
block|,
DECL|enumerator|VG_USERREQ__CLIENT_CALL2
name|VG_USERREQ__CLIENT_CALL2
init|=
literal|0x1103
block|,
DECL|enumerator|VG_USERREQ__CLIENT_CALL3
name|VG_USERREQ__CLIENT_CALL3
init|=
literal|0x1104
block|,
comment|/* Can be useful in regression testing suites -- eg. can              send Valgrind's output to /dev/null and still count              errors. */
DECL|enumerator|VG_USERREQ__COUNT_ERRORS
name|VG_USERREQ__COUNT_ERRORS
init|=
literal|0x1201
block|,
comment|/* These are useful and can be interpreted by any tool that              tracks malloc() et al, by using vg_replace_malloc.c. */
DECL|enumerator|VG_USERREQ__MALLOCLIKE_BLOCK
name|VG_USERREQ__MALLOCLIKE_BLOCK
init|=
literal|0x1301
block|,
DECL|enumerator|VG_USERREQ__FREELIKE_BLOCK
name|VG_USERREQ__FREELIKE_BLOCK
init|=
literal|0x1302
block|,
comment|/* Memory pool support. */
DECL|enumerator|VG_USERREQ__CREATE_MEMPOOL
name|VG_USERREQ__CREATE_MEMPOOL
init|=
literal|0x1303
block|,
DECL|enumerator|VG_USERREQ__DESTROY_MEMPOOL
name|VG_USERREQ__DESTROY_MEMPOOL
init|=
literal|0x1304
block|,
DECL|enumerator|VG_USERREQ__MEMPOOL_ALLOC
name|VG_USERREQ__MEMPOOL_ALLOC
init|=
literal|0x1305
block|,
DECL|enumerator|VG_USERREQ__MEMPOOL_FREE
name|VG_USERREQ__MEMPOOL_FREE
init|=
literal|0x1306
block|,
DECL|enumerator|VG_USERREQ__MEMPOOL_TRIM
name|VG_USERREQ__MEMPOOL_TRIM
init|=
literal|0x1307
block|,
DECL|enumerator|VG_USERREQ__MOVE_MEMPOOL
name|VG_USERREQ__MOVE_MEMPOOL
init|=
literal|0x1308
block|,
DECL|enumerator|VG_USERREQ__MEMPOOL_CHANGE
name|VG_USERREQ__MEMPOOL_CHANGE
init|=
literal|0x1309
block|,
DECL|enumerator|VG_USERREQ__MEMPOOL_EXISTS
name|VG_USERREQ__MEMPOOL_EXISTS
init|=
literal|0x130a
block|,
comment|/* Allow printfs to valgrind log. */
DECL|enumerator|VG_USERREQ__PRINTF
name|VG_USERREQ__PRINTF
init|=
literal|0x1401
block|,
DECL|enumerator|VG_USERREQ__PRINTF_BACKTRACE
name|VG_USERREQ__PRINTF_BACKTRACE
init|=
literal|0x1402
block|,
comment|/* Stack support. */
DECL|enumerator|VG_USERREQ__STACK_REGISTER
name|VG_USERREQ__STACK_REGISTER
init|=
literal|0x1501
block|,
DECL|enumerator|VG_USERREQ__STACK_DEREGISTER
name|VG_USERREQ__STACK_DEREGISTER
init|=
literal|0x1502
block|,
DECL|enumerator|VG_USERREQ__STACK_CHANGE
name|VG_USERREQ__STACK_CHANGE
init|=
literal|0x1503
block|}
DECL|typedef|Vg_ClientRequest
name|Vg_ClientRequest
typedef|;
end_typedef
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if
begin_define
DECL|macro|__extension__
define|#
directive|define
name|__extension__
end_define
begin_comment
DECL|macro|__extension__
comment|/* */
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* Returns the number of Valgrinds this code is running under.  That    is, 0 if running natively, 1 if running under Valgrind, 2 if    running under Valgrind which is running under another Valgrind,    etc. */
end_comment
begin_define
DECL|macro|RUNNING_ON_VALGRIND
define|#
directive|define
name|RUNNING_ON_VALGRIND
value|__extension__                        \    ({unsigned int _qzz_res;                                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* if not */
value|,          \                                VG_USERREQ__RUNNING_ON_VALGRIND,   \                                0, 0, 0, 0, 0);                    \     _qzz_res;                                                     \    })
end_define
begin_comment
comment|/* Discard translation of code in the range [_qzz_addr .. _qzz_addr +    _qzz_len - 1].  Useful if you are debugging a JITter or some such,    since it provides a way to make sure valgrind will retranslate the    invalidated area.  Returns no value. */
end_comment
begin_define
DECL|macro|VALGRIND_DISCARD_TRANSLATIONS
define|#
directive|define
name|VALGRIND_DISCARD_TRANSLATIONS
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__DISCARD_TRANSLATIONS,  \                                _qzz_addr, _qzz_len, 0, 0, 0);     \    }
end_define
begin_comment
comment|/* These requests are for getting Valgrind itself to print something.    Possibly with a backtrace.  This is a really ugly hack. */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|NVALGRIND
argument_list|)
end_if
begin_define
DECL|macro|VALGRIND_PRINTF
define|#
directive|define
name|VALGRIND_PRINTF
parameter_list|(
modifier|...
parameter_list|)
end_define
begin_define
DECL|macro|VALGRIND_PRINTF_BACKTRACE
define|#
directive|define
name|VALGRIND_PRINTF_BACKTRACE
parameter_list|(
modifier|...
parameter_list|)
end_define
begin_else
else|#
directive|else
end_else
begin_comment
comment|/* NVALGRIND */
end_comment
begin_comment
comment|/* Modern GCC will optimize the static routine out if unused,    and unused attribute will shut down warnings about it.  */
end_comment
begin_function_decl
specifier|static
name|int
name|VALGRIND_PRINTF
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl
begin_operator
unit|)
operator|,
end_operator
begin_expr_stmt
name|__unused__
end_expr_stmt
begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt
begin_function
specifier|static
name|int
DECL|function|VALGRIND_PRINTF
name|VALGRIND_PRINTF
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|unsigned
name|long
name|_qzz_res
decl_stmt|;
name|va_list
name|vargs
decl_stmt|;
name|va_start
argument_list|(
name|vargs
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|VALGRIND_DO_CLIENT_REQUEST
argument_list|(
name|_qzz_res
argument_list|,
literal|0
argument_list|,
name|VG_USERREQ__PRINTF
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|format
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|vargs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vargs
argument_list|)
expr_stmt|;
return|return
operator|(
name|int
operator|)
name|_qzz_res
return|;
block|}
end_function
begin_function_decl
specifier|static
name|int
name|VALGRIND_PRINTF_BACKTRACE
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl
begin_operator
unit|)
operator|,
end_operator
begin_expr_stmt
name|__unused__
end_expr_stmt
begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt
begin_function
specifier|static
name|int
DECL|function|VALGRIND_PRINTF_BACKTRACE
name|VALGRIND_PRINTF_BACKTRACE
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
block|{
name|unsigned
name|long
name|_qzz_res
decl_stmt|;
name|va_list
name|vargs
decl_stmt|;
name|va_start
argument_list|(
name|vargs
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|VALGRIND_DO_CLIENT_REQUEST
argument_list|(
name|_qzz_res
argument_list|,
literal|0
argument_list|,
name|VG_USERREQ__PRINTF_BACKTRACE
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|format
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|vargs
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|vargs
argument_list|)
expr_stmt|;
return|return
operator|(
name|int
operator|)
name|_qzz_res
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* NVALGRIND */
end_comment
begin_comment
comment|/* These requests allow control to move from the simulated CPU to the    real CPU, calling an arbitary function.        Note that the current ThreadId is inserted as the first argument.    So this call:       VALGRIND_NON_SIMD_CALL2(f, arg1, arg2)     requires f to have this signature:       Word f(Word tid, Word arg1, Word arg2)     where "Word" is a word-sized type.     Note that these client requests are not entirely reliable.  For example,    if you call a function with them that subsequently calls printf(),    there's a high chance Valgrind will crash.  Generally, your prospects of    these working are made higher if the called function does not refer to    any global variables, and does not refer to any libc or other functions    (printf et al).  Any kind of entanglement with libc or dynamic linking is    likely to have a bad outcome, for tricky reasons which we've grappled    with a lot in the past. */
end_comment
begin_define
DECL|macro|VALGRIND_NON_SIMD_CALL0
define|#
directive|define
name|VALGRIND_NON_SIMD_CALL0
parameter_list|(
name|_qyy_fn
parameter_list|)
define|\
value|__extension__                                                  \    ({unsigned long _qyy_res;                                      \     VALGRIND_DO_CLIENT_REQUEST(_qyy_res, 0
comment|/* default return */
value|,  \                                VG_USERREQ__CLIENT_CALL0,          \                                _qyy_fn,                           \                                0, 0, 0, 0);                       \     _qyy_res;                                                     \    })
end_define
begin_define
DECL|macro|VALGRIND_NON_SIMD_CALL1
define|#
directive|define
name|VALGRIND_NON_SIMD_CALL1
parameter_list|(
name|_qyy_fn
parameter_list|,
name|_qyy_arg1
parameter_list|)
define|\
value|__extension__                                                  \    ({unsigned long _qyy_res;                                      \     VALGRIND_DO_CLIENT_REQUEST(_qyy_res, 0
comment|/* default return */
value|,  \                                VG_USERREQ__CLIENT_CALL1,          \                                _qyy_fn,                           \                                _qyy_arg1, 0, 0, 0);               \     _qyy_res;                                                     \    })
end_define
begin_define
DECL|macro|VALGRIND_NON_SIMD_CALL2
define|#
directive|define
name|VALGRIND_NON_SIMD_CALL2
parameter_list|(
name|_qyy_fn
parameter_list|,
name|_qyy_arg1
parameter_list|,
name|_qyy_arg2
parameter_list|)
define|\
value|__extension__                                                  \    ({unsigned long _qyy_res;                                      \     VALGRIND_DO_CLIENT_REQUEST(_qyy_res, 0
comment|/* default return */
value|,  \                                VG_USERREQ__CLIENT_CALL2,          \                                _qyy_fn,                           \                                _qyy_arg1, _qyy_arg2, 0, 0);       \     _qyy_res;                                                     \    })
end_define
begin_define
DECL|macro|VALGRIND_NON_SIMD_CALL3
define|#
directive|define
name|VALGRIND_NON_SIMD_CALL3
parameter_list|(
name|_qyy_fn
parameter_list|,
name|_qyy_arg1
parameter_list|,
name|_qyy_arg2
parameter_list|,
name|_qyy_arg3
parameter_list|)
define|\
value|__extension__                                                  \    ({unsigned long _qyy_res;                                      \     VALGRIND_DO_CLIENT_REQUEST(_qyy_res, 0
comment|/* default return */
value|,  \                                VG_USERREQ__CLIENT_CALL3,          \                                _qyy_fn,                           \                                _qyy_arg1, _qyy_arg2,              \                                _qyy_arg3, 0);                     \     _qyy_res;                                                     \    })
end_define
begin_comment
comment|/* Counts the number of errors that have been recorded by a tool.  Nb:    the tool must record the errors with VG_(maybe_record_error)() or    VG_(unique_error)() for them to be counted. */
end_comment
begin_define
DECL|macro|VALGRIND_COUNT_ERRORS
define|#
directive|define
name|VALGRIND_COUNT_ERRORS
define|\
value|__extension__                                                  \    ({unsigned int _qyy_res;                                       \     VALGRIND_DO_CLIENT_REQUEST(_qyy_res, 0
comment|/* default return */
value|,  \                                VG_USERREQ__COUNT_ERRORS,          \                                0, 0, 0, 0, 0);                    \     _qyy_res;                                                     \    })
end_define
begin_comment
comment|/* Mark a block of memory as having been allocated by a malloc()-like    function.  `addr' is the start of the usable block (ie. after any    redzone) `rzB' is redzone size if the allocator can apply redzones;    use '0' if not.  Adding redzones makes it more likely Valgrind will spot    block overruns.  `is_zeroed' indicates if the memory is zeroed, as it is    for calloc().  Put it immediately after the point where a block is    allocated.         If you're using Memcheck: If you're allocating memory via superblocks,    and then handing out small chunks of each superblock, if you don't have    redzones on your small blocks, it's worth marking the superblock with    VALGRIND_MAKE_MEM_NOACCESS when it's created, so that block overruns are    detected.  But if you can put redzones on, it's probably better to not do    this, so that messages for small overruns are described in terms of the    small block rather than the superblock (but if you have a big overrun    that skips over a redzone, you could miss an error this way).  See    memcheck/tests/custom_alloc.c for an example.     WARNING: if your allocator uses malloc() or 'new' to allocate    superblocks, rather than mmap() or brk(), this will not work properly --    you'll likely get assertion failures during leak detection.  This is    because Valgrind doesn't like seeing overlapping heap blocks.  Sorry.     Nb: block must be freed via a free()-like function specified    with VALGRIND_FREELIKE_BLOCK or mismatch errors will occur. */
end_comment
begin_define
DECL|macro|VALGRIND_MALLOCLIKE_BLOCK
define|#
directive|define
name|VALGRIND_MALLOCLIKE_BLOCK
parameter_list|(
name|addr
parameter_list|,
name|sizeB
parameter_list|,
name|rzB
parameter_list|,
name|is_zeroed
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MALLOCLIKE_BLOCK,      \                                addr, sizeB, rzB, is_zeroed, 0);   \    }
end_define
begin_comment
comment|/* Mark a block of memory as having been freed by a free()-like function.    `rzB' is redzone size;  it must match that given to    VALGRIND_MALLOCLIKE_BLOCK.  Memory not freed will be detected by the leak    checker.  Put it immediately after the point where the block is freed. */
end_comment
begin_define
DECL|macro|VALGRIND_FREELIKE_BLOCK
define|#
directive|define
name|VALGRIND_FREELIKE_BLOCK
parameter_list|(
name|addr
parameter_list|,
name|rzB
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__FREELIKE_BLOCK,        \                                addr, rzB, 0, 0, 0);               \    }
end_define
begin_comment
comment|/* Create a memory pool. */
end_comment
begin_define
DECL|macro|VALGRIND_CREATE_MEMPOOL
define|#
directive|define
name|VALGRIND_CREATE_MEMPOOL
parameter_list|(
name|pool
parameter_list|,
name|rzB
parameter_list|,
name|is_zeroed
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__CREATE_MEMPOOL,        \                                pool, rzB, is_zeroed, 0, 0);       \    }
end_define
begin_comment
comment|/* Destroy a memory pool. */
end_comment
begin_define
DECL|macro|VALGRIND_DESTROY_MEMPOOL
define|#
directive|define
name|VALGRIND_DESTROY_MEMPOOL
parameter_list|(
name|pool
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__DESTROY_MEMPOOL,       \                                pool, 0, 0, 0, 0);                 \    }
end_define
begin_comment
comment|/* Associate a piece of memory with a memory pool. */
end_comment
begin_define
DECL|macro|VALGRIND_MEMPOOL_ALLOC
define|#
directive|define
name|VALGRIND_MEMPOOL_ALLOC
parameter_list|(
name|pool
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MEMPOOL_ALLOC,         \                                pool, addr, size, 0, 0);           \    }
end_define
begin_comment
comment|/* Disassociate a piece of memory from a memory pool. */
end_comment
begin_define
DECL|macro|VALGRIND_MEMPOOL_FREE
define|#
directive|define
name|VALGRIND_MEMPOOL_FREE
parameter_list|(
name|pool
parameter_list|,
name|addr
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MEMPOOL_FREE,          \                                pool, addr, 0, 0, 0);              \    }
end_define
begin_comment
comment|/* Disassociate any pieces outside a particular range. */
end_comment
begin_define
DECL|macro|VALGRIND_MEMPOOL_TRIM
define|#
directive|define
name|VALGRIND_MEMPOOL_TRIM
parameter_list|(
name|pool
parameter_list|,
name|addr
parameter_list|,
name|size
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MEMPOOL_TRIM,          \                                pool, addr, size, 0, 0);           \    }
end_define
begin_comment
comment|/* Resize and/or move a piece associated with a memory pool. */
end_comment
begin_define
DECL|macro|VALGRIND_MOVE_MEMPOOL
define|#
directive|define
name|VALGRIND_MOVE_MEMPOOL
parameter_list|(
name|poolA
parameter_list|,
name|poolB
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MOVE_MEMPOOL,          \                                poolA, poolB, 0, 0, 0);            \    }
end_define
begin_comment
comment|/* Resize and/or move a piece associated with a memory pool. */
end_comment
begin_define
DECL|macro|VALGRIND_MEMPOOL_CHANGE
define|#
directive|define
name|VALGRIND_MEMPOOL_CHANGE
parameter_list|(
name|pool
parameter_list|,
name|addrA
parameter_list|,
name|addrB
parameter_list|,
name|size
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MEMPOOL_CHANGE,        \                                pool, addrA, addrB, size, 0);      \    }
end_define
begin_comment
comment|/* Return 1 if a mempool exists, else 0. */
end_comment
begin_define
DECL|macro|VALGRIND_MEMPOOL_EXISTS
define|#
directive|define
name|VALGRIND_MEMPOOL_EXISTS
parameter_list|(
name|pool
parameter_list|)
define|\
value|({unsigned int _qzz_res;                                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__MEMPOOL_EXISTS,        \                                pool, 0, 0, 0, 0);                 \     _qzz_res;                                                     \    })
end_define
begin_comment
comment|/* Mark a piece of memory as being a stack. Returns a stack id. */
end_comment
begin_define
DECL|macro|VALGRIND_STACK_REGISTER
define|#
directive|define
name|VALGRIND_STACK_REGISTER
parameter_list|(
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|({unsigned int _qzz_res;                                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__STACK_REGISTER,        \                                start, end, 0, 0, 0);              \     _qzz_res;                                                     \    })
end_define
begin_comment
comment|/* Unmark the piece of memory associated with a stack id as being a    stack. */
end_comment
begin_define
DECL|macro|VALGRIND_STACK_DEREGISTER
define|#
directive|define
name|VALGRIND_STACK_DEREGISTER
parameter_list|(
name|id
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__STACK_DEREGISTER,      \                                id, 0, 0, 0, 0);                   \    }
end_define
begin_comment
comment|/* Change the start and end address of the stack id. */
end_comment
begin_define
DECL|macro|VALGRIND_STACK_CHANGE
define|#
directive|define
name|VALGRIND_STACK_CHANGE
parameter_list|(
name|id
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                        \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                       \                                VG_USERREQ__STACK_CHANGE,          \                                id, start, end, 0, 0);             \    }
end_define
begin_undef
DECL|macro|PLAT_x86_linux
undef|#
directive|undef
name|PLAT_x86_linux
end_undef
begin_undef
DECL|macro|PLAT_amd64_linux
undef|#
directive|undef
name|PLAT_amd64_linux
end_undef
begin_undef
DECL|macro|PLAT_ppc32_linux
undef|#
directive|undef
name|PLAT_ppc32_linux
end_undef
begin_undef
DECL|macro|PLAT_ppc64_linux
undef|#
directive|undef
name|PLAT_ppc64_linux
end_undef
begin_undef
DECL|macro|PLAT_ppc32_aix5
undef|#
directive|undef
name|PLAT_ppc32_aix5
end_undef
begin_undef
DECL|macro|PLAT_ppc64_aix5
undef|#
directive|undef
name|PLAT_ppc64_aix5
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __VALGRIND_H */
end_comment
end_unit
