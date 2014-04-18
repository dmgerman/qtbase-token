begin_unit
begin_comment
comment|/************************************************* *      Perl-Compatible Regular Expressions       * *************************************************/
end_comment
begin_comment
comment|/* PCRE is a library of functions to support regular expressions whose syntax and semantics are as close as possible to those of the Perl 5 language.                         Written by Philip Hazel            Copyright (c) 1997-2014 University of Cambridge  ----------------------------------------------------------------------------- Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      * Redistributions of source code must retain the above copyright notice,       this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright       notice, this list of conditions and the following disclaimer in the       documentation and/or other materials provided with the distribution.      * Neither the name of the University of Cambridge nor the names of its       contributors may be used to endorse or promote products derived from       this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. ----------------------------------------------------------------------------- */
end_comment
begin_comment
comment|/* This module contains global variables that are exported by the PCRE library. PCRE is thread-clean and doesn't use any global variables in the normal sense. However, it calls memory allocation and freeing functions via the four indirections below, and it can optionally do callouts, using the fifth indirection. These values can be changed by the caller, but are shared between all threads.  For MS Visual Studio and Symbian OS, there are problems in initializing these variables to non-local functions. In these cases, therefore, an indirection via a local function is used.  Also, when compiling for Virtual Pascal, things are done differently, and global variables are not used. */
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|PCRE_HAVE_CONFIG_H
end_ifdef
begin_include
include|#
directive|include
file|"config.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"pcre_internal.h"
end_include
begin_if
if|#
directive|if
name|defined
name|_MSC_VER
operator|||
name|defined
name|__SYMBIAN32__
end_if
begin_function
DECL|function|LocalPcreMalloc
specifier|static
name|void
modifier|*
name|LocalPcreMalloc
parameter_list|(
name|size_t
name|aSize
parameter_list|)
block|{
return|return
name|malloc
argument_list|(
name|aSize
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|LocalPcreFree
specifier|static
name|void
name|LocalPcreFree
parameter_list|(
name|void
modifier|*
name|aPtr
parameter_list|)
block|{
name|free
argument_list|(
name|aPtr
argument_list|)
expr_stmt|;
block|}
end_function
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
modifier|*
argument_list|(
operator|*
name|PUBL
argument_list|(
name|malloc
argument_list|)
argument_list|)
argument_list|(
name|size_t
argument_list|)
init|=
name|LocalPcreMalloc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
argument_list|(
operator|*
name|PUBL
argument_list|(
name|free
argument_list|)
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
init|=
name|LocalPcreFree
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
modifier|*
argument_list|(
operator|*
name|PUBL
argument_list|(
name|stack_malloc
argument_list|)
argument_list|)
argument_list|(
name|size_t
argument_list|)
init|=
name|LocalPcreMalloc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
argument_list|(
operator|*
name|PUBL
argument_list|(
name|stack_free
argument_list|)
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
init|=
name|LocalPcreFree
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|int
argument_list|(
operator|*
name|PUBL
argument_list|(
name|callout
argument_list|)
argument_list|)
argument_list|(
name|PUBL
argument_list|(
name|callout_block
argument_list|)
operator|*
argument_list|)
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|int
argument_list|(
operator|*
name|PUBL
argument_list|(
name|stack_guard
argument_list|)
argument_list|)
argument_list|(
name|void
argument_list|)
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_elif
elif|#
directive|elif
operator|!
name|defined
name|VPCOMPAT
end_elif
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
modifier|*
argument_list|(
operator|*
name|PUBL
argument_list|(
name|malloc
argument_list|)
argument_list|)
argument_list|(
name|size_t
argument_list|)
init|=
name|malloc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
argument_list|(
operator|*
name|PUBL
argument_list|(
name|free
argument_list|)
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
init|=
name|free
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
modifier|*
argument_list|(
operator|*
name|PUBL
argument_list|(
name|stack_malloc
argument_list|)
argument_list|)
argument_list|(
name|size_t
argument_list|)
init|=
name|malloc
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|void
argument_list|(
operator|*
name|PUBL
argument_list|(
name|stack_free
argument_list|)
argument_list|)
argument_list|(
name|void
operator|*
argument_list|)
init|=
name|free
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|int
argument_list|(
operator|*
name|PUBL
argument_list|(
name|callout
argument_list|)
argument_list|)
argument_list|(
name|PUBL
argument_list|(
name|callout_block
argument_list|)
operator|*
argument_list|)
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|PCRE_EXP_DATA_DEFN
name|int
argument_list|(
operator|*
name|PUBL
argument_list|(
name|stack_guard
argument_list|)
argument_list|)
argument_list|(
name|void
argument_list|)
init|=
name|NULL
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* End of pcre_globals.c */
end_comment
end_unit
