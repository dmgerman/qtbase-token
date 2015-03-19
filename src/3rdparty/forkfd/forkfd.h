begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Intel Corporation ** ** Permission is hereby granted, free of charge, to any person obtaining a copy ** of this software and associated documentation files (the "Software"), to deal ** in the Software without restriction, including without limitation the rights ** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell ** copies of the Software, and to permit persons to whom the Software is ** furnished to do so, subject to the following conditions: ** ** The above copyright notice and this permission notice shall be included in ** all copies or substantial portions of the Software. ** ** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR ** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, ** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE ** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER ** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, ** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN ** THE SOFTWARE. ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|FORKFD_H
end_ifndef
begin_define
DECL|macro|FORKFD_H
define|#
directive|define
name|FORKFD_H
end_define
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|// to get the POSIX flags
end_comment
begin_ifdef
ifdef|#
directive|ifdef
name|_POSIX_SPAWN
end_ifdef
begin_include
include|#
directive|include
file|<spawn.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
DECL|macro|FFD_CLOEXEC
define|#
directive|define
name|FFD_CLOEXEC
value|1
DECL|macro|FFD_NONBLOCK
define|#
directive|define
name|FFD_NONBLOCK
value|2
DECL|macro|FFD_CHILD_PROCESS
define|#
directive|define
name|FFD_CHILD_PROCESS
value|(-2)
name|int
name|forkfd
parameter_list|(
name|int
name|flags
parameter_list|,
name|pid_t
modifier|*
name|ppid
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|_POSIX_SPAWN
comment|/* only for spawnfd: */
DECL|macro|FFD_SPAWN_SEARCH_PATH
define|#
directive|define
name|FFD_SPAWN_SEARCH_PATH
value|O_RDWR
name|int
name|spawnfd
parameter_list|(
name|int
name|flags
parameter_list|,
name|pid_t
modifier|*
name|ppid
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
specifier|const
name|posix_spawn_file_actions_t
modifier|*
name|file_actions
parameter_list|,
name|posix_spawnattr_t
modifier|*
name|attrp
parameter_list|,
name|char
modifier|*
specifier|const
name|argv
index|[]
parameter_list|,
name|char
modifier|*
specifier|const
name|envp
index|[]
parameter_list|)
function_decl|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// FORKFD_H
end_comment
end_unit
