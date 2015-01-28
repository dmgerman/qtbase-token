begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPLATFORMDEFS_H
end_ifndef
begin_define
DECL|macro|QPLATFORMDEFS_H
define|#
directive|define
name|QPLATFORMDEFS_H
end_define
begin_define
DECL|macro|QT_QPA_DEFAULT_PLATFORM_NAME
define|#
directive|define
name|QT_QPA_DEFAULT_PLATFORM_NAME
value|"android"
end_define
begin_comment
comment|// Get Qt defines/settings
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_comment
comment|// Set any POSIX/XOPEN defines at the top of this file to turn on specific APIs
end_comment
begin_comment
comment|// 1) need to reset default environment if _BSD_SOURCE is defined
end_comment
begin_comment
comment|// 2) need to specify POSIX thread interfaces explicitly in glibc 2.0
end_comment
begin_comment
comment|// 3) it seems older glibc need this to include the X/Open stuff
end_comment
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_comment
comment|// We are hot - unistd.h should have turned on the specific APIs we requested
end_comment
begin_include
include|#
directive|include
file|<features.h>
end_include
begin_include
include|#
directive|include
file|<pthread.h>
end_include
begin_include
include|#
directive|include
file|<dirent.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<grp.h>
end_include
begin_include
include|#
directive|include
file|<pwd.h>
end_include
begin_include
include|#
directive|include
file|<signal.h>
end_include
begin_include
include|#
directive|include
file|<dlfcn.h>
end_include
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include
begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include
begin_include
include|#
directive|include
file|<sys/time.h>
end_include
begin_include
include|#
directive|include
file|<sys/socket.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<sys/wait.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IPV6IFNAME
end_ifndef
begin_include
include|#
directive|include
file|<net/if.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef
begin_define
DECL|macro|_GNU_SOURCE
define|#
directive|define
name|_GNU_SOURCE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LARGEFILE_SUPPORT
end_ifdef
begin_define
DECL|macro|QT_STATBUF
define|#
directive|define
name|QT_STATBUF
value|struct stat64
end_define
begin_define
DECL|macro|QT_STATBUF4TSTAT
define|#
directive|define
name|QT_STATBUF4TSTAT
value|struct stat64
end_define
begin_define
DECL|macro|QT_STAT
define|#
directive|define
name|QT_STAT
value|::stat64
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::fstat64
end_define
begin_define
DECL|macro|QT_LSTAT
define|#
directive|define
name|QT_LSTAT
value|::lstat64
end_define
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|::open64
end_define
begin_define
DECL|macro|QT_TRUNCATE
define|#
directive|define
name|QT_TRUNCATE
value|::truncate64
end_define
begin_define
DECL|macro|QT_FTRUNCATE
define|#
directive|define
name|QT_FTRUNCATE
value|::ftruncate64
end_define
begin_define
DECL|macro|QT_LSEEK
define|#
directive|define
name|QT_LSEEK
value|::lseek64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_STATBUF
define|#
directive|define
name|QT_STATBUF
value|struct stat
end_define
begin_define
DECL|macro|QT_STATBUF4TSTAT
define|#
directive|define
name|QT_STATBUF4TSTAT
value|struct stat
end_define
begin_define
DECL|macro|QT_STAT
define|#
directive|define
name|QT_STAT
value|::stat
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::fstat
end_define
begin_define
DECL|macro|QT_LSTAT
define|#
directive|define
name|QT_LSTAT
value|::lstat
end_define
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|::open
end_define
begin_define
DECL|macro|QT_TRUNCATE
define|#
directive|define
name|QT_TRUNCATE
value|::truncate
end_define
begin_define
DECL|macro|QT_FTRUNCATE
define|#
directive|define
name|QT_FTRUNCATE
value|::ftruncate
end_define
begin_define
DECL|macro|QT_LSEEK
define|#
directive|define
name|QT_LSEEK
value|::lseek
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LARGEFILE_SUPPORT
end_ifdef
begin_define
DECL|macro|QT_FOPEN
define|#
directive|define
name|QT_FOPEN
value|::fopen64
end_define
begin_define
DECL|macro|QT_FSEEK
define|#
directive|define
name|QT_FSEEK
value|::fseeko64
end_define
begin_define
DECL|macro|QT_FTELL
define|#
directive|define
name|QT_FTELL
value|::ftello64
end_define
begin_define
DECL|macro|QT_FGETPOS
define|#
directive|define
name|QT_FGETPOS
value|::fgetpos64
end_define
begin_define
DECL|macro|QT_FSETPOS
define|#
directive|define
name|QT_FSETPOS
value|::fsetpos64
end_define
begin_define
DECL|macro|QT_MMAP
define|#
directive|define
name|QT_MMAP
value|::mmap64
end_define
begin_define
DECL|macro|QT_FPOS_T
define|#
directive|define
name|QT_FPOS_T
value|fpos64_t
end_define
begin_define
DECL|macro|QT_OFF_T
define|#
directive|define
name|QT_OFF_T
value|off64_t
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_FOPEN
define|#
directive|define
name|QT_FOPEN
value|::fopen
end_define
begin_define
DECL|macro|QT_FSEEK
define|#
directive|define
name|QT_FSEEK
value|::fseek
end_define
begin_define
DECL|macro|QT_FTELL
define|#
directive|define
name|QT_FTELL
value|::ftell
end_define
begin_define
DECL|macro|QT_FGETPOS
define|#
directive|define
name|QT_FGETPOS
value|::fgetpos
end_define
begin_define
DECL|macro|QT_FSETPOS
define|#
directive|define
name|QT_FSETPOS
value|::fsetpos
end_define
begin_define
DECL|macro|QT_MMAP
define|#
directive|define
name|QT_MMAP
value|::mmap
end_define
begin_define
DECL|macro|QT_FPOS_T
define|#
directive|define
name|QT_FPOS_T
value|fpos_t
end_define
begin_define
DECL|macro|QT_OFF_T
define|#
directive|define
name|QT_OFF_T
value|long
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_STAT_REG
define|#
directive|define
name|QT_STAT_REG
value|S_IFREG
end_define
begin_define
DECL|macro|QT_STAT_DIR
define|#
directive|define
name|QT_STAT_DIR
value|S_IFDIR
end_define
begin_define
DECL|macro|QT_STAT_MASK
define|#
directive|define
name|QT_STAT_MASK
value|S_IFMT
end_define
begin_define
DECL|macro|QT_STAT_LNK
define|#
directive|define
name|QT_STAT_LNK
value|S_IFLNK
end_define
begin_define
DECL|macro|QT_SOCKET_CONNECT
define|#
directive|define
name|QT_SOCKET_CONNECT
value|::connect
end_define
begin_define
DECL|macro|QT_SOCKET_BIND
define|#
directive|define
name|QT_SOCKET_BIND
value|::bind
end_define
begin_define
DECL|macro|QT_FILENO
define|#
directive|define
name|QT_FILENO
value|fileno
end_define
begin_define
DECL|macro|QT_CLOSE
define|#
directive|define
name|QT_CLOSE
value|::close
end_define
begin_define
DECL|macro|QT_READ
define|#
directive|define
name|QT_READ
value|::read
end_define
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
value|::write
end_define
begin_define
DECL|macro|QT_ACCESS
define|#
directive|define
name|QT_ACCESS
value|::access
end_define
begin_define
DECL|macro|QT_GETCWD
define|#
directive|define
name|QT_GETCWD
value|::getcwd
end_define
begin_define
DECL|macro|QT_CHDIR
define|#
directive|define
name|QT_CHDIR
value|::chdir
end_define
begin_define
DECL|macro|QT_MKDIR
define|#
directive|define
name|QT_MKDIR
value|::mkdir
end_define
begin_define
DECL|macro|QT_RMDIR
define|#
directive|define
name|QT_RMDIR
value|::rmdir
end_define
begin_define
DECL|macro|QT_OPEN_LARGEFILE
define|#
directive|define
name|QT_OPEN_LARGEFILE
value|O_LARGEFILE
end_define
begin_define
DECL|macro|QT_OPEN_RDONLY
define|#
directive|define
name|QT_OPEN_RDONLY
value|O_RDONLY
end_define
begin_define
DECL|macro|QT_OPEN_WRONLY
define|#
directive|define
name|QT_OPEN_WRONLY
value|O_WRONLY
end_define
begin_define
DECL|macro|QT_OPEN_RDWR
define|#
directive|define
name|QT_OPEN_RDWR
value|O_RDWR
end_define
begin_define
DECL|macro|QT_OPEN_CREAT
define|#
directive|define
name|QT_OPEN_CREAT
value|O_CREAT
end_define
begin_define
DECL|macro|QT_OPEN_TRUNC
define|#
directive|define
name|QT_OPEN_TRUNC
value|O_TRUNC
end_define
begin_define
DECL|macro|QT_OPEN_APPEND
define|#
directive|define
name|QT_OPEN_APPEND
value|O_APPEND
end_define
begin_comment
comment|// Directory iteration
end_comment
begin_define
DECL|macro|QT_DIR
define|#
directive|define
name|QT_DIR
value|DIR
end_define
begin_define
DECL|macro|QT_OPENDIR
define|#
directive|define
name|QT_OPENDIR
value|::opendir
end_define
begin_define
DECL|macro|QT_CLOSEDIR
define|#
directive|define
name|QT_CLOSEDIR
value|::closedir
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LARGEFILE_SUPPORT
argument_list|)
expr|\
operator|&&
name|defined
argument_list|(
name|QT_USE_XOPEN_LFS_EXTENSIONS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|QT_NO_READDIR64
argument_list|)
end_if
begin_define
DECL|macro|QT_DIRENT
define|#
directive|define
name|QT_DIRENT
value|struct dirent64
end_define
begin_define
DECL|macro|QT_READDIR
define|#
directive|define
name|QT_READDIR
value|::readdir64
end_define
begin_define
DECL|macro|QT_READDIR_R
define|#
directive|define
name|QT_READDIR_R
value|::readdir64_r
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_DIRENT
define|#
directive|define
name|QT_DIRENT
value|struct dirent
end_define
begin_define
DECL|macro|QT_READDIR
define|#
directive|define
name|QT_READDIR
value|::readdir
end_define
begin_define
DECL|macro|QT_READDIR_R
define|#
directive|define
name|QT_READDIR_R
value|::readdir_r
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_SOCKET_CONNECT
define|#
directive|define
name|QT_SOCKET_CONNECT
value|::connect
end_define
begin_define
DECL|macro|QT_SOCKET_BIND
define|#
directive|define
name|QT_SOCKET_BIND
value|::bind
end_define
begin_define
DECL|macro|QT_SIGNAL_RETTYPE
define|#
directive|define
name|QT_SIGNAL_RETTYPE
value|void
end_define
begin_define
DECL|macro|QT_SIGNAL_ARGS
define|#
directive|define
name|QT_SIGNAL_ARGS
value|int
end_define
begin_define
DECL|macro|QT_SIGNAL_IGNORE
define|#
directive|define
name|QT_SIGNAL_IGNORE
value|SIG_IGN
end_define
begin_define
DECL|macro|QT_SOCKLEN_T
define|#
directive|define
name|QT_SOCKLEN_T
value|socklen_t
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_XOPEN_SOURCE
argument_list|)
operator|&&
operator|(
name|_XOPEN_SOURCE
operator|>=
literal|500
operator|)
end_if
begin_define
DECL|macro|QT_SNPRINTF
define|#
directive|define
name|QT_SNPRINTF
value|::snprintf
end_define
begin_define
DECL|macro|QT_VSNPRINTF
define|#
directive|define
name|QT_VSNPRINTF
value|::vsnprintf
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
comment|// QPLATFORMDEFS_H
end_comment
end_unit
