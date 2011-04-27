begin_unit
begin_comment
comment|/*    ----------------------------------------------------------------     Notice that the following BSD-style license applies to this one    file (callgrind.h) only.  The rest of Valgrind is licensed under the    terms of the GNU General Public License, version 2, unless    otherwise indicated.  See the COPYING file in the source    distribution for details.     ----------------------------------------------------------------     This file is part of callgrind, a valgrind tool for cache simulation    and call tree tracing.     Copyright (C) 2003-2007 Josef Weidendorfer.  All rights reserved.     Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions    are met:     1. Redistributions of source code must retain the above copyright       notice, this list of conditions and the following disclaimer.     2. The origin of this software must not be misrepresented; you must       not claim that you wrote the original software.  If you use this       software in a product, an acknowledgment in the product       documentation would be appreciated but is not required.     3. Altered source versions must be plainly marked as such, and must       not be misrepresented as being the original software.     4. The name of the author may not be used to endorse or promote       products derived from this software without specific prior written       permission.     THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS    OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE    GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.     ----------------------------------------------------------------     Notice that the above BSD-style license applies to this one file    (vgprof.h) only.  The entire rest of Valgrind is licensed under    the terms of the GNU General Public License, version 2.  See the    COPYING file in the source distribution for details.     ---------------------------------------------------------------- */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__CALLGRIND_H
end_ifndef
begin_define
DECL|macro|__CALLGRIND_H
define|#
directive|define
name|__CALLGRIND_H
end_define
begin_include
include|#
directive|include
file|"valgrind_p.h"
end_include
begin_comment
comment|/* !! ABIWARNING !! ABIWARNING !! ABIWARNING !! ABIWARNING !!    This enum comprises an ABI exported by Valgrind to programs    which use client requests.  DO NOT CHANGE THE ORDER OF THESE    ENTRIES, NOR DELETE ANY -- add new ones at the end.     The identification ('C','T') for Callgrind has historical    reasons: it was called "Calltree" before. Besides, ('C','G') would    clash with cachegrind.  */
end_comment
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|VG_USERREQ__DUMP_STATS
name|VG_USERREQ__DUMP_STATS
init|=
name|VG_USERREQ_TOOL_BASE
argument_list|(
literal|'C'
argument_list|,
literal|'T'
argument_list|)
block|,
DECL|enumerator|VG_USERREQ__ZERO_STATS
name|VG_USERREQ__ZERO_STATS
block|,
DECL|enumerator|VG_USERREQ__TOGGLE_COLLECT
name|VG_USERREQ__TOGGLE_COLLECT
block|,
DECL|enumerator|VG_USERREQ__DUMP_STATS_AT
name|VG_USERREQ__DUMP_STATS_AT
block|,
DECL|enumerator|VG_USERREQ__START_INSTRUMENTATION
name|VG_USERREQ__START_INSTRUMENTATION
block|,
DECL|enumerator|VG_USERREQ__STOP_INSTRUMENTATION
name|VG_USERREQ__STOP_INSTRUMENTATION
block|}
DECL|typedef|Vg_CallgrindClientRequest
name|Vg_CallgrindClientRequest
typedef|;
end_typedef
begin_comment
comment|/* Dump current state of cost centers, and zero them afterwards */
end_comment
begin_define
DECL|macro|CALLGRIND_DUMP_STATS
define|#
directive|define
name|CALLGRIND_DUMP_STATS
define|\
value|{unsigned int _qzz_res;                                              \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \                             VG_USERREQ__DUMP_STATS,                     \                             0, 0, 0, 0, 0);                             \    }
end_define
begin_comment
comment|/* Dump current state of cost centers, and zero them afterwards.    The argument is appended to a string stating the reason which triggered    the dump. This string is written as a description field into the    profile data dump. */
end_comment
begin_define
DECL|macro|CALLGRIND_DUMP_STATS_AT
define|#
directive|define
name|CALLGRIND_DUMP_STATS_AT
parameter_list|(
name|pos_str
parameter_list|)
define|\
value|{unsigned int _qzz_res;                                              \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \                             VG_USERREQ__DUMP_STATS_AT,                  \                             pos_str, 0, 0, 0, 0);                       \    }
end_define
begin_comment
comment|/* Zero cost centers */
end_comment
begin_define
DECL|macro|CALLGRIND_ZERO_STATS
define|#
directive|define
name|CALLGRIND_ZERO_STATS
define|\
value|{unsigned int _qzz_res;                                              \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \                             VG_USERREQ__ZERO_STATS,                     \                             0, 0, 0, 0, 0);                             \    }
end_define
begin_comment
comment|/* Toggles collection state.    The collection state specifies whether the happening of events    should be noted or if they are to be ignored. Events are noted    by increment of counters in a cost center */
end_comment
begin_define
DECL|macro|CALLGRIND_TOGGLE_COLLECT
define|#
directive|define
name|CALLGRIND_TOGGLE_COLLECT
define|\
value|{unsigned int _qzz_res;                                              \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \                             VG_USERREQ__TOGGLE_COLLECT,                 \                             0, 0, 0, 0, 0);                             \    }
end_define
begin_comment
comment|/* Start full callgrind instrumentation if not already switched on.    When cache simulation is done, it will flush the simulated cache;    this will lead to an artifical cache warmup phase afterwards with    cache misses which would not have happened in reality. */
end_comment
begin_define
DECL|macro|CALLGRIND_START_INSTRUMENTATION
define|#
directive|define
name|CALLGRIND_START_INSTRUMENTATION
define|\
value|{unsigned int _qzz_res;                                              \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \                             VG_USERREQ__START_INSTRUMENTATION,          \                             0, 0, 0, 0, 0);                             \    }
end_define
begin_comment
comment|/* Stop full callgrind instrumentation if not already switched off.    This flushes Valgrinds translation cache, and does no additional    instrumentation afterwards, which effectivly will run at the same    speed as the "none" tool (ie. at minimal slowdown).    Use this to bypass Callgrind aggregation for uninteresting code parts.    To start Callgrind in this mode to ignore the setup phase, use    the option "--instr-atstart=no". */
end_comment
begin_define
DECL|macro|CALLGRIND_STOP_INSTRUMENTATION
define|#
directive|define
name|CALLGRIND_STOP_INSTRUMENTATION
define|\
value|{unsigned int _qzz_res;                                              \     VALGRIND_DO_CLIENT_REQUEST(_qzz_res, 0,                             \                             VG_USERREQ__STOP_INSTRUMENTATION,           \                             0, 0, 0, 0, 0);                             \    }
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __CALLGRIND_H */
end_comment
end_unit
