begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_ifdef
ifdef|#
directive|ifdef
name|UNICODE
end_ifdef
begin_ifndef
ifndef|#
directive|ifndef
name|_UNICODE
end_ifndef
begin_define
DECL|macro|_UNICODE
define|#
directive|define
name|_UNICODE
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
comment|// Get Qt defines/settings
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_include
include|#
directive|include
file|<tchar.h>
end_include
begin_include
include|#
directive|include
file|<io.h>
end_include
begin_include
include|#
directive|include
file|<direct.h>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<fcntl.h>
end_include
begin_include
include|#
directive|include
file|<errno.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_WIN32_WINNT
argument_list|)
operator|||
operator|(
name|_WIN32_WINNT
operator|-
literal|0
operator|<
literal|0x0500
operator|)
end_if
begin_typedef
typedef|typedef
enum|enum
block|{
DECL|enumerator|NameUnknown
name|NameUnknown
init|=
literal|0
block|,
DECL|enumerator|NameFullyQualifiedDN
name|NameFullyQualifiedDN
init|=
literal|1
block|,
DECL|enumerator|NameSamCompatible
name|NameSamCompatible
init|=
literal|2
block|,
DECL|enumerator|NameDisplay
name|NameDisplay
init|=
literal|3
block|,
DECL|enumerator|NameUniqueId
name|NameUniqueId
init|=
literal|6
block|,
DECL|enumerator|NameCanonical
name|NameCanonical
init|=
literal|7
block|,
DECL|enumerator|NameUserPrincipal
name|NameUserPrincipal
init|=
literal|8
block|,
DECL|enumerator|NameCanonicalEx
name|NameCanonicalEx
init|=
literal|9
block|,
DECL|enumerator|NameServicePrincipal
name|NameServicePrincipal
init|=
literal|10
block|,
DECL|enumerator|NameDnsDomain
name|NameDnsDomain
init|=
literal|12
block|}
DECL|typedef|EXTENDED_NAME_FORMAT
DECL|typedef|PEXTENDED_NAME_FORMAT
name|EXTENDED_NAME_FORMAT
operator|,
typedef|*
name|PEXTENDED_NAME_FORMAT
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|Q_FS_FAT
define|#
directive|define
name|Q_FS_FAT
end_define
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
value|struct _stati64
end_define
begin_comment
DECL|macro|QT_STATBUF
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STATBUF4TSTAT
define|#
directive|define
name|QT_STATBUF4TSTAT
value|struct _stati64
end_define
begin_comment
DECL|macro|QT_STATBUF4TSTAT
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STAT
define|#
directive|define
name|QT_STAT
value|::_stati64
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::_fstati64
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
value|struct _stat
end_define
begin_comment
DECL|macro|QT_STATBUF
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STATBUF4TSTAT
define|#
directive|define
name|QT_STATBUF4TSTAT
value|struct _stat
end_define
begin_comment
DECL|macro|QT_STATBUF4TSTAT
comment|// non-ANSI defs
end_comment
begin_define
DECL|macro|QT_STAT
define|#
directive|define
name|QT_STAT
value|::_stat
end_define
begin_define
DECL|macro|QT_FSTAT
define|#
directive|define
name|QT_FSTAT
value|::_fstat
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
value|_S_IFREG
end_define
begin_define
DECL|macro|QT_STAT_DIR
define|#
directive|define
name|QT_STAT_DIR
value|_S_IFDIR
end_define
begin_define
DECL|macro|QT_STAT_MASK
define|#
directive|define
name|QT_STAT_MASK
value|_S_IFMT
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_S_IFLNK
argument_list|)
end_if
begin_define
DECL|macro|QT_STAT_LNK
define|#
directive|define
name|QT_STAT_LNK
value|_S_IFLNK
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_FILENO
define|#
directive|define
name|QT_FILENO
value|_fileno
end_define
begin_define
DECL|macro|QT_OPEN
define|#
directive|define
name|QT_OPEN
value|::_open
end_define
begin_define
DECL|macro|QT_CLOSE
define|#
directive|define
name|QT_CLOSE
value|::_close
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LARGEFILE_SUPPORT
end_ifdef
begin_define
DECL|macro|QT_LSEEK
define|#
directive|define
name|QT_LSEEK
value|::_lseeki64
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|UNICODE
end_ifndef
begin_define
DECL|macro|QT_TSTAT
define|#
directive|define
name|QT_TSTAT
value|::_stati64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_TSTAT
define|#
directive|define
name|QT_TSTAT
value|::_wstati64
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_LSEEK
define|#
directive|define
name|QT_LSEEK
value|::_lseek
end_define
begin_ifndef
ifndef|#
directive|ifndef
name|UNICODE
end_ifndef
begin_define
DECL|macro|QT_TSTAT
define|#
directive|define
name|QT_TSTAT
value|::_stat
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_TSTAT
define|#
directive|define
name|QT_TSTAT
value|::_wstat
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_READ
define|#
directive|define
name|QT_READ
value|::_read
end_define
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
value|::_write
end_define
begin_define
DECL|macro|QT_ACCESS
define|#
directive|define
name|QT_ACCESS
value|::_access
end_define
begin_define
DECL|macro|QT_GETCWD
define|#
directive|define
name|QT_GETCWD
value|::_getcwd
end_define
begin_define
DECL|macro|QT_CHDIR
define|#
directive|define
name|QT_CHDIR
value|::_chdir
end_define
begin_define
DECL|macro|QT_MKDIR
define|#
directive|define
name|QT_MKDIR
value|::_mkdir
end_define
begin_define
DECL|macro|QT_RMDIR
define|#
directive|define
name|QT_RMDIR
value|::_rmdir
end_define
begin_define
DECL|macro|QT_OPEN_LARGEFILE
define|#
directive|define
name|QT_OPEN_LARGEFILE
value|0
end_define
begin_define
DECL|macro|QT_OPEN_RDONLY
define|#
directive|define
name|QT_OPEN_RDONLY
value|_O_RDONLY
end_define
begin_define
DECL|macro|QT_OPEN_WRONLY
define|#
directive|define
name|QT_OPEN_WRONLY
value|_O_WRONLY
end_define
begin_define
DECL|macro|QT_OPEN_RDWR
define|#
directive|define
name|QT_OPEN_RDWR
value|_O_RDWR
end_define
begin_define
DECL|macro|QT_OPEN_CREAT
define|#
directive|define
name|QT_OPEN_CREAT
value|_O_CREAT
end_define
begin_define
DECL|macro|QT_OPEN_TRUNC
define|#
directive|define
name|QT_OPEN_TRUNC
value|_O_TRUNC
end_define
begin_define
DECL|macro|QT_OPEN_APPEND
define|#
directive|define
name|QT_OPEN_APPEND
value|_O_APPEND
end_define
begin_if
if|#
directive|if
name|defined
argument_list|(
name|O_TEXT
argument_list|)
end_if
begin_define
DECL|macro|QT_OPEN_TEXT
define|#
directive|define
name|QT_OPEN_TEXT
value|_O_TEXT
end_define
begin_define
DECL|macro|QT_OPEN_BINARY
define|#
directive|define
name|QT_OPEN_BINARY
value|_O_BINARY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|"../common/c89/qplatformdefs.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QT_LARGEFILE_SUPPORT
end_ifdef
begin_undef
DECL|macro|QT_FSEEK
undef|#
directive|undef
name|QT_FSEEK
end_undef
begin_undef
DECL|macro|QT_FTELL
undef|#
directive|undef
name|QT_FTELL
end_undef
begin_undef
DECL|macro|QT_OFF_T
undef|#
directive|undef
name|QT_OFF_T
end_undef
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
DECL|macro|QT_OFF_T
define|#
directive|define
name|QT_OFF_T
value|off64_t
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|QT_SIGNAL_ARGS
define|#
directive|define
name|QT_SIGNAL_ARGS
value|int
end_define
begin_define
DECL|macro|QT_VSNPRINTF
define|#
directive|define
name|QT_VSNPRINTF
value|::_vsnprintf
end_define
begin_define
DECL|macro|QT_SNPRINTF
define|#
directive|define
name|QT_SNPRINTF
value|::_snprintf
end_define
begin_define
DECL|macro|F_OK
define|#
directive|define
name|F_OK
value|0
end_define
begin_define
DECL|macro|X_OK
define|#
directive|define
name|X_OK
value|1
end_define
begin_define
DECL|macro|W_OK
define|#
directive|define
name|W_OK
value|2
end_define
begin_define
DECL|macro|R_OK
define|#
directive|define
name|R_OK
value|4
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPLATFORMDEFS_H
end_comment
end_unit
