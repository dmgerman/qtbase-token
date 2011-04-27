begin_unit
begin_comment
comment|/*    ----------------------------------------------------------------     Notice that the following BSD-style license applies to this one    file (memcheck.h) only.  The rest of Valgrind is licensed under the    terms of the GNU General Public License, version 2, unless    otherwise indicated.  See the COPYING file in the source    distribution for details.     ----------------------------------------------------------------     This file is part of MemCheck, a heavyweight Valgrind tool for    detecting memory errors.     Copyright (C) 2000-2008 Julian Seward.  All rights reserved.     Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions    are met:     1. Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.     2. The origin of this software must not be misrepresented; you must        not claim that you wrote the original software.  If you use this        software in a product, an acknowledgment in the product        documentation would be appreciated but is not required.     3. Altered source versions must be plainly marked as such, and must       not be misrepresented as being the original software.     4. The name of the author may not be used to endorse or promote        products derived from this software without specific prior written        permission.     THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     ----------------------------------------------------------------     Notice that the above BSD-style license applies to this one file    (memcheck.h) only.  The entire rest of Valgrind is licensed under    the terms of the GNU General Public License, version 2.  See the    COPYING file in the source distribution for details.     ----------------------------------------------------------------  */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__MEMCHECK_H
end_ifndef
begin_define
DECL|macro|__MEMCHECK_H
define|#
directive|define
name|__MEMCHECK_H
end_define
begin_comment
comment|/* This file is for inclusion into client (your!) code.     You can use these macros to manipulate and query memory permissions    inside your own programs.     See comment near the top of valgrind.h on how to use them. */
end_comment
begin_include
include|#
directive|include
file|"valgrind.h"
end_include
begin_comment
comment|/* !! ABIWARNING !! ABIWARNING !! ABIWARNING !! ABIWARNING !!     This enum comprises an ABI exported by Valgrind to programs    which use client requests.  DO NOT CHANGE THE ORDER OF THESE    ENTRIES, NOR DELETE ANY -- add new ones at the end. */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|VG_USERREQ__MAKE_MEM_NOACCESS
name|VG_USERREQ__MAKE_MEM_NOACCESS
init|=
name|VG_USERREQ_TOOL_BASE
argument_list|(
literal|'M'
argument_list|,
literal|'C'
argument_list|)
block|,
DECL|enumerator|VG_USERREQ__MAKE_MEM_UNDEFINED
name|VG_USERREQ__MAKE_MEM_UNDEFINED
block|,
DECL|enumerator|VG_USERREQ__MAKE_MEM_DEFINED
name|VG_USERREQ__MAKE_MEM_DEFINED
block|,
DECL|enumerator|VG_USERREQ__DISCARD
name|VG_USERREQ__DISCARD
block|,
DECL|enumerator|VG_USERREQ__CHECK_MEM_IS_ADDRESSABLE
name|VG_USERREQ__CHECK_MEM_IS_ADDRESSABLE
block|,
DECL|enumerator|VG_USERREQ__CHECK_MEM_IS_DEFINED
name|VG_USERREQ__CHECK_MEM_IS_DEFINED
block|,
DECL|enumerator|VG_USERREQ__DO_LEAK_CHECK
name|VG_USERREQ__DO_LEAK_CHECK
block|,
DECL|enumerator|VG_USERREQ__COUNT_LEAKS
name|VG_USERREQ__COUNT_LEAKS
block|,
DECL|enumerator|VG_USERREQ__GET_VBITS
name|VG_USERREQ__GET_VBITS
block|,
DECL|enumerator|VG_USERREQ__SET_VBITS
name|VG_USERREQ__SET_VBITS
block|,
DECL|enumerator|VG_USERREQ__CREATE_BLOCK
name|VG_USERREQ__CREATE_BLOCK
block|,
DECL|enumerator|VG_USERREQ__MAKE_MEM_DEFINED_IF_ADDRESSABLE
name|VG_USERREQ__MAKE_MEM_DEFINED_IF_ADDRESSABLE
block|,
DECL|enumerator|VG_USERREQ__ENABLE_OOM
name|VG_USERREQ__ENABLE_OOM
block|,
DECL|enumerator|VG_USERREQ__GET_ALLOC_INDEX
name|VG_USERREQ__GET_ALLOC_INDEX
block|,
comment|/* This is just for memcheck's internal use - don't use it */
DECL|enumerator|_VG_USERREQ__MEMCHECK_RECORD_OVERLAP_ERROR
name|_VG_USERREQ__MEMCHECK_RECORD_OVERLAP_ERROR
init|=
name|VG_USERREQ_TOOL_BASE
argument_list|(
literal|'M'
argument_list|,
literal|'C'
argument_list|)
operator|+
literal|256
block|,
comment|/* This is just for memcheck's internal use - don't use it */
DECL|enumerator|_VG_USERREQ__EXCEPTION
name|_VG_USERREQ__EXCEPTION
init|=
name|VG_USERREQ_TOOL_BASE
argument_list|(
literal|'M'
argument_list|,
literal|'C'
argument_list|)
operator|+
literal|512
block|,    }
DECL|typedef|Vg_MemCheckClientRequest
name|Vg_MemCheckClientRequest
typedef|;
end_typedef
begin_comment
comment|/* Client-code macros to manipulate the state of memory. */
end_comment
begin_comment
comment|/* Mark memory at _qzz_addr as unaddressable for _qzz_len bytes. */
end_comment
begin_define
DECL|macro|VALGRIND_MAKE_MEM_NOACCESS
define|#
directive|define
name|VALGRIND_MAKE_MEM_NOACCESS
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__MAKE_MEM_NOACCESS,       \                             _qzz_addr, _qzz_len, 0, 0, 0);       \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Similarly, mark memory at _qzz_addr as addressable but undefined    for _qzz_len bytes. */
end_comment
begin_define
DECL|macro|VALGRIND_MAKE_MEM_UNDEFINED
define|#
directive|define
name|VALGRIND_MAKE_MEM_UNDEFINED
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__MAKE_MEM_UNDEFINED,      \                             _qzz_addr, _qzz_len, 0, 0, 0);       \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Similarly, mark memory at _qzz_addr as addressable and defined    for _qzz_len bytes. */
end_comment
begin_define
DECL|macro|VALGRIND_MAKE_MEM_DEFINED
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__MAKE_MEM_DEFINED,        \                             _qzz_addr, _qzz_len, 0, 0, 0);       \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Similar to VALGRIND_MAKE_MEM_DEFINED except that addressability is    not altered: bytes which are addressable are marked as defined,    but those which are not addressable are left unchanged. */
end_comment
begin_define
DECL|macro|VALGRIND_MAKE_MEM_DEFINED_IF_ADDRESSABLE
define|#
directive|define
name|VALGRIND_MAKE_MEM_DEFINED_IF_ADDRESSABLE
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__MAKE_MEM_DEFINED_IF_ADDRESSABLE, \                             _qzz_addr, _qzz_len, 0, 0, 0);       \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Create a block-description handle.  The description is an ascii    string which is included in any messages pertaining to addresses    within the specified memory range.  Has no other effect on the    properties of the memory range. */
end_comment
begin_define
DECL|macro|VALGRIND_CREATE_BLOCK
define|#
directive|define
name|VALGRIND_CREATE_BLOCK
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|,
name|_qzz_desc
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;			 \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__CREATE_BLOCK,            \                             _qzz_addr, _qzz_len, _qzz_desc,      \                             0, 0);                               \     _qzz_res;							 \    }))
end_define
begin_comment
comment|/* Discard a block-description-handle. Returns 1 for an    invalid handle, 0 for a valid handle. */
end_comment
begin_define
DECL|macro|VALGRIND_DISCARD
define|#
directive|define
name|VALGRIND_DISCARD
parameter_list|(
name|_qzz_blkindex
parameter_list|)
define|\
value|(__extension__ ({unsigned long _qzz_res;                      \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__DISCARD,                 \                             0, _qzz_blkindex, 0, 0, 0);          \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Client-code macros to check the state of memory. */
end_comment
begin_comment
comment|/* Check that memory at _qzz_addr is addressable for _qzz_len bytes.    If suitable addressibility is not established, Valgrind prints an    error message and returns the address of the first offending byte.    Otherwise it returns zero. */
end_comment
begin_define
DECL|macro|VALGRIND_CHECK_MEM_IS_ADDRESSABLE
define|#
directive|define
name|VALGRIND_CHECK_MEM_IS_ADDRESSABLE
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                      \                             VG_USERREQ__CHECK_MEM_IS_ADDRESSABLE,\                             _qzz_addr, _qzz_len, 0, 0, 0);       \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Check that memory at _qzz_addr is addressable and defined for    _qzz_len bytes.  If suitable addressibility and definedness are not    established, Valgrind prints an error message and returns the    address of the first offending byte.  Otherwise it returns zero. */
end_comment
begin_define
DECL|macro|VALGRIND_CHECK_MEM_IS_DEFINED
define|#
directive|define
name|VALGRIND_CHECK_MEM_IS_DEFINED
parameter_list|(
name|_qzz_addr
parameter_list|,
name|_qzz_len
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                      \                             VG_USERREQ__CHECK_MEM_IS_DEFINED,    \                             _qzz_addr, _qzz_len, 0, 0, 0);       \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Use this macro to force the definedness and addressibility of an    lvalue to be checked.  If suitable addressibility and definedness    are not established, Valgrind prints an error message and returns    the address of the first offending byte.  Otherwise it returns    zero. */
end_comment
begin_define
DECL|macro|VALGRIND_CHECK_VALUE_IS_DEFINED
define|#
directive|define
name|VALGRIND_CHECK_VALUE_IS_DEFINED
parameter_list|(
name|__lvalue
parameter_list|)
define|\
value|VALGRIND_CHECK_MEM_IS_DEFINED(                                \       (volatile unsigned char *)&(__lvalue),                     \                       (unsigned long)(sizeof (__lvalue)))
end_define
begin_comment
comment|/* Do a memory leak check mid-execution.  */
end_comment
begin_define
DECL|macro|VALGRIND_DO_LEAK_CHECK
define|#
directive|define
name|VALGRIND_DO_LEAK_CHECK
define|\
value|{unsigned long _qzz_res;                                      \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                      \                             VG_USERREQ__DO_LEAK_CHECK,           \                             0, 0, 0, 0, 0);                      \    }
end_define
begin_comment
comment|/* Just display summaries of leaked memory, rather than all the    details */
end_comment
begin_define
DECL|macro|VALGRIND_DO_QUICK_LEAK_CHECK
define|#
directive|define
name|VALGRIND_DO_QUICK_LEAK_CHECK
define|\
value|{unsigned long _qzz_res;                                      \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                      \                             VG_USERREQ__DO_LEAK_CHECK,           \                             1, 0, 0, 0, 0);                      \    }
end_define
begin_comment
comment|/* Return number of leaked, dubious, reachable and suppressed bytes found by    all previous leak checks.  They must be lvalues.  */
end_comment
begin_define
DECL|macro|VALGRIND_COUNT_LEAKS
define|#
directive|define
name|VALGRIND_COUNT_LEAKS
parameter_list|(
name|leaked
parameter_list|,
name|dubious
parameter_list|,
name|reachable
parameter_list|,
name|suppressed
parameter_list|)
define|\
comment|/* For safety on 64-bit platforms we assign the results to private       unsigned long variables, then assign these to the lvalues the user       specified, which works no matter what type 'leaked', 'dubious', etc       are.  We also initialise '_qzz_leaked', etc because       VG_USERREQ__COUNT_LEAKS doesn't mark the values returned as       initialised. */
define|\
value|{unsigned long _qzz_res;                                              \     unsigned long _qzz_leaked    = 0, _qzz_dubious    = 0;               \     unsigned long _qzz_reachable = 0, _qzz_suppressed = 0;               \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                              \                                VG_USERREQ__COUNT_LEAKS,                  \&_qzz_leaked,&_qzz_dubious,              \&_qzz_reachable,&_qzz_suppressed, 0);    \     leaked     = _qzz_leaked;                                            \     dubious    = _qzz_dubious;                                           \     reachable  = _qzz_reachable;                                         \     suppressed = _qzz_suppressed;                                        \    }
end_define
begin_comment
comment|/* Get the validity data for addresses [zza..zza+zznbytes-1] and copy it    into the provided zzvbits array.  Return values:       0   if not running on valgrind       1   success       2   [previously indicated unaligned arrays;  these are now allowed]       3   if any parts of zzsrc/zzvbits are not addressable.    The metadata is not copied in cases 0, 2 or 3 so it should be    impossible to segfault your system by using this call. */
end_comment
begin_define
DECL|macro|VALGRIND_GET_VBITS
define|#
directive|define
name|VALGRIND_GET_VBITS
parameter_list|(
name|zza
parameter_list|,
name|zzvbits
parameter_list|,
name|zznbytes
parameter_list|)
define|\
value|(__extension__({unsigned long _qzz_res;                       \     char* czza     = (char*)zza;                                 \     char* czzvbits = (char*)zzvbits;                             \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                      \                             VG_USERREQ__GET_VBITS,               \                             czza, czzvbits, zznbytes, 0, 0 );    \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Set the validity data for addresses [zza..zza+zznbytes-1], copying it    from the provided zzvbits array.  Return values:       0   if not running on valgrind       1   success       2   [previously indicated unaligned arrays;  these are now allowed]       3   if any parts of zza/zzvbits are not addressable.    The metadata is not copied in cases 0, 2 or 3 so it should be    impossible to segfault your system by using this call. */
end_comment
begin_define
DECL|macro|VALGRIND_SET_VBITS
define|#
directive|define
name|VALGRIND_SET_VBITS
parameter_list|(
name|zza
parameter_list|,
name|zzvbits
parameter_list|,
name|zznbytes
parameter_list|)
define|\
value|(__extension__({unsigned int _qzz_res;                        \     char* czza     = (char*)zza;                                 \     char* czzvbits = (char*)zzvbits;                             \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                      \                             VG_USERREQ__SET_VBITS,               \                             czza, czzvbits, zznbytes, 0, 0 );    \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Enable or disable OOM simulation. */
end_comment
begin_define
DECL|macro|VALGRIND_ENABLE_OOM_AT_ALLOC_INDEX
define|#
directive|define
name|VALGRIND_ENABLE_OOM_AT_ALLOC_INDEX
parameter_list|(
name|index
parameter_list|)
define|\
value|(__extension__ ({unsigned long _qzz_res;                      \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__ENABLE_OOM,              \                             1, index, 0, 0, 0);                  \     _qzz_res;                                                    \    }))
end_define
begin_define
DECL|macro|VALGRIND_DISABLE_OOM_AT_ALLOC_INDEX
define|#
directive|define
name|VALGRIND_DISABLE_OOM_AT_ALLOC_INDEX
parameter_list|(
name|index
parameter_list|)
define|\
value|(__extension__ ({unsigned long _qzz_res;                      \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0
comment|/* default return */
value|, \                             VG_USERREQ__ENABLE_OOM,              \                             0, index, 0, 0, 0);                  \     _qzz_res;                                                    \    }))
end_define
begin_comment
comment|/* Get the current allocation index. */
end_comment
begin_define
DECL|macro|VALGRIND_GET_ALLOC_INDEX
define|#
directive|define
name|VALGRIND_GET_ALLOC_INDEX
define|\
value|(__extension__ ({unsigned long _qzz_res;                      \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, -1
comment|/* default return */
value|, \                             VG_USERREQ__GET_ALLOC_INDEX,         \                             0, 0, 0, 0, 0);                      \     _qzz_res;                                                    \    }))
end_define
begin_endif
endif|#
directive|endif
end_endif
end_unit
