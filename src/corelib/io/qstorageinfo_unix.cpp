begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Ivan Komissarov<ABBAPOH@gmail.com> ** Copyright (C) 2016 Intel Corporation. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qstorageinfo_p.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/qdiriterator.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfileinfo.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qtextstream.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qcore_unix_p.h>
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
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
end_if
begin_include
include|#
directive|include
file|<sys/mount.h>
end_include
begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<sys/mount.h>
end_include
begin_include
include|#
directive|include
file|<sys/vfs.h>
end_include
begin_include
include|#
directive|include
file|<mntent.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_HURD
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<mntent.h>
end_include
begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SOLARIS
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<sys/mnttab.h>
end_include
begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_HAIKU
argument_list|)
end_elif
begin_include
include|#
directive|include
file|<Directory.h>
end_include
begin_include
include|#
directive|include
file|<Path.h>
end_include
begin_include
include|#
directive|include
file|<Volume.h>
end_include
begin_include
include|#
directive|include
file|<VolumeRoster.h>
end_include
begin_include
include|#
directive|include
file|<fs_info.h>
end_include
begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<sys/statvfs.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
end_if
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_NETBSD
argument_list|)
end_if
begin_define
DECL|macro|QT_STATFSBUF
define|#
directive|define
name|QT_STATFSBUF
value|struct statvfs
end_define
begin_define
DECL|macro|QT_STATFS
define|#
directive|define
name|QT_STATFS
value|::statvfs
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_STATFSBUF
define|#
directive|define
name|QT_STATFSBUF
value|struct statfs
end_define
begin_define
DECL|macro|QT_STATFS
define|#
directive|define
name|QT_STATFS
value|::statfs
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ST_RDONLY
argument_list|)
end_if
begin_define
DECL|macro|ST_RDONLY
define|#
directive|define
name|ST_RDONLY
value|MNT_RDONLY
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_STATFS_F_FLAGS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_NETBSD
argument_list|)
end_if
begin_define
DECL|macro|_STATFS_F_FLAGS
define|#
directive|define
name|_STATFS_F_FLAGS
value|1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_elif
begin_define
DECL|macro|QT_STATFS
define|#
directive|define
name|QT_STATFS
value|::statfs
end_define
begin_define
DECL|macro|QT_STATFSBUF
define|#
directive|define
name|QT_STATFSBUF
value|struct statfs
end_define
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ST_RDONLY
argument_list|)
end_if
begin_define
DECL|macro|ST_RDONLY
define|#
directive|define
name|ST_RDONLY
value|1
end_define
begin_comment
DECL|macro|ST_RDONLY
comment|// hack for missing define on Android
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_HAIKU
argument_list|)
end_elif
begin_define
DECL|macro|QT_STATFSBUF
define|#
directive|define
name|QT_STATFSBUF
value|struct statvfs
end_define
begin_define
DECL|macro|QT_STATFS
define|#
directive|define
name|QT_STATFS
value|::statvfs
end_define
begin_else
else|#
directive|else
end_else
begin_if
if|#
directive|if
name|defined
argument_list|(
name|QT_LARGEFILE_SUPPORT
argument_list|)
end_if
begin_define
DECL|macro|QT_STATFSBUF
define|#
directive|define
name|QT_STATFSBUF
value|struct statvfs64
end_define
begin_define
DECL|macro|QT_STATFS
define|#
directive|define
name|QT_STATFS
value|::statvfs64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|QT_STATFSBUF
define|#
directive|define
name|QT_STATFSBUF
value|struct statvfs
end_define
begin_define
DECL|macro|QT_STATFS
define|#
directive|define
name|QT_STATFS
value|::statvfs
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_LARGEFILE_SUPPORT
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_BSD4
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_class
DECL|class|QStorageIterator
class|class
name|QStorageIterator
block|{
public|public:
name|QStorageIterator
parameter_list|()
constructor_decl|;
name|~
name|QStorageIterator
parameter_list|()
destructor_decl|;
specifier|inline
name|bool
name|isValid
parameter_list|()
specifier|const
function_decl|;
specifier|inline
name|bool
name|next
parameter_list|()
function_decl|;
specifier|inline
name|QString
name|rootPath
parameter_list|()
specifier|const
function_decl|;
specifier|inline
name|QByteArray
name|fileSystemType
parameter_list|()
specifier|const
function_decl|;
specifier|inline
name|QByteArray
name|device
parameter_list|()
specifier|const
function_decl|;
private|private:
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
DECL|member|stat_buf
name|QT_STATFSBUF
modifier|*
name|stat_buf
decl_stmt|;
DECL|member|entryCount
name|int
name|entryCount
decl_stmt|;
DECL|member|currentIndex
name|int
name|currentIndex
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SOLARIS
argument_list|)
DECL|member|fp
name|FILE
modifier|*
name|fp
decl_stmt|;
DECL|member|mnt
name|mnttab
name|mnt
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
DECL|member|file
name|QFile
name|file
decl_stmt|;
DECL|member|m_rootPath
name|QByteArray
name|m_rootPath
decl_stmt|;
DECL|member|m_fileSystemType
name|QByteArray
name|m_fileSystemType
decl_stmt|;
DECL|member|m_device
name|QByteArray
name|m_device
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_HURD
argument_list|)
DECL|member|fp
name|FILE
modifier|*
name|fp
decl_stmt|;
DECL|member|mnt
name|mntent
name|mnt
decl_stmt|;
DECL|member|buffer
name|QByteArray
name|buffer
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_HAIKU
argument_list|)
DECL|member|m_volumeRoster
name|BVolumeRoster
name|m_volumeRoster
decl_stmt|;
DECL|member|m_rootPath
name|QByteArray
name|m_rootPath
decl_stmt|;
DECL|member|m_fileSystemType
name|QByteArray
name|m_fileSystemType
decl_stmt|;
DECL|member|m_device
name|QByteArray
name|m_device
decl_stmt|;
endif|#
directive|endif
block|}
class|;
end_class
begin_function
template|template
parameter_list|<
name|typename
name|String
parameter_list|>
DECL|function|isParentOf
specifier|static
name|bool
name|isParentOf
parameter_list|(
specifier|const
name|String
modifier|&
name|parent
parameter_list|,
specifier|const
name|QString
modifier|&
name|dirName
parameter_list|)
block|{
return|return
name|dirName
operator|.
name|startsWith
argument_list|(
name|parent
argument_list|)
operator|&&
operator|(
name|dirName
operator|.
name|size
argument_list|()
operator|==
name|parent
operator|.
name|size
argument_list|()
operator|||
name|dirName
operator|.
name|at
argument_list|(
name|parent
operator|.
name|size
argument_list|()
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|||
name|parent
operator|.
name|size
argument_list|()
operator|==
literal|1
operator|)
return|;
block|}
end_function
begin_function
DECL|function|shouldIncludeFs
specifier|static
name|bool
name|shouldIncludeFs
parameter_list|(
specifier|const
name|QStorageIterator
modifier|&
name|it
parameter_list|)
block|{
comment|/*      * This function implements a heuristic algorithm to determine whether a      * given mount should be reported to the user. Our objective is to list      * only entries that the end-user would find useful.      *      * We therefore ignore:      *  - mounted in /dev, /proc, /sys: special mounts      *    (this will catch /sys/fs/cgroup, /proc/sys/fs/binfmt_misc, /dev/pts,      *    some of which are tmpfs on Linux)      *  - mounted in /var/run or /var/lock: most likely pseudofs      *    (on earlier systemd versions, /var/run was a bind-mount of /run, so      *    everything would be unnecessarily duplicated)      *  - filesystem type is "rootfs": artifact of the root-pivot on some Linux      *    initrd      *  - if the filesystem total size is zero, it's a pseudo-fs (not checked here).      */
name|QString
name|mountDir
init|=
name|it
operator|.
name|rootPath
argument_list|()
decl_stmt|;
if|if
condition|(
name|isParentOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"/dev"
argument_list|)
argument_list|,
name|mountDir
argument_list|)
operator|||
name|isParentOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"/proc"
argument_list|)
argument_list|,
name|mountDir
argument_list|)
operator|||
name|isParentOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"/sys"
argument_list|)
argument_list|,
name|mountDir
argument_list|)
operator|||
name|isParentOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"/var/run"
argument_list|)
argument_list|,
name|mountDir
argument_list|)
operator|||
name|isParentOf
argument_list|(
name|QLatin1String
argument_list|(
literal|"/var/lock"
argument_list|)
argument_list|,
name|mountDir
argument_list|)
condition|)
block|{
return|return
literal|false
return|;
block|}
ifdef|#
directive|ifdef
name|Q_OS_LINUX
if|if
condition|(
name|it
operator|.
name|fileSystemType
argument_list|()
operator|==
literal|"rootfs"
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
comment|// size checking in mountedVolumes()
return|return
literal|true
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
end_if
begin_constructor
DECL|function|QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|QStorageIterator
parameter_list|()
member_init_list|:
name|entryCount
argument_list|(
operator|::
name|getmntinfo
argument_list|(
operator|&
name|stat_buf
argument_list|,
literal|0
argument_list|)
argument_list|)
member_init_list|,
name|currentIndex
argument_list|(
operator|-
literal|1
argument_list|)
block|{ }
end_constructor
begin_destructor
DECL|function|~QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|~
name|QStorageIterator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|entryCount
operator|!=
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|next
parameter_list|()
block|{
return|return
operator|++
name|currentIndex
operator|<
name|entryCount
return|;
block|}
end_function
begin_function
DECL|function|rootPath
specifier|inline
name|QString
name|QStorageIterator
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|stat_buf
index|[
name|currentIndex
index|]
operator|.
name|f_mntonname
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fileSystemType
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|stat_buf
index|[
name|currentIndex
index|]
operator|.
name|f_fstypename
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|device
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|stat_buf
index|[
name|currentIndex
index|]
operator|.
name|f_mntfromname
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SOLARIS
argument_list|)
end_elif
begin_decl_stmt
DECL|variable|pathMounted
specifier|static
specifier|const
name|char
name|pathMounted
index|[]
init|=
literal|"/etc/mnttab"
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|QStorageIterator
parameter_list|()
block|{
specifier|const
name|int
name|fd
init|=
name|qt_safe_open
argument_list|(
name|pathMounted
argument_list|,
name|O_RDONLY
argument_list|)
decl_stmt|;
name|fp
operator|=
operator|::
name|fdopen
argument_list|(
name|fd
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|~
name|QStorageIterator
parameter_list|()
block|{
if|if
condition|(
name|fp
condition|)
operator|::
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isValid
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|fp
operator|!=
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|next
parameter_list|()
block|{
return|return
operator|::
name|getmntent
argument_list|(
name|fp
argument_list|,
operator|&
name|mnt
argument_list|)
operator|==
literal|0
return|;
block|}
end_function
begin_function
DECL|function|rootPath
specifier|inline
name|QString
name|QStorageIterator
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|mnt
operator|.
name|mnt_mountp
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fileSystemType
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|mnt
operator|.
name|mnt_fstype
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|device
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|mnt
operator|.
name|mnt_mntopts
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
end_elif
begin_decl_stmt
specifier|static
specifier|const
name|QLatin1String
name|pathMounted
argument_list|(
literal|"/proc/mounts"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_constructor
DECL|function|QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|QStorageIterator
parameter_list|()
block|{
name|file
operator|.
name|setFileName
argument_list|(
name|pathMounted
argument_list|)
expr_stmt|;
name|file
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|~
name|QStorageIterator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|file
operator|.
name|isOpen
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|next
parameter_list|()
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|data
decl_stmt|;
do|do
block|{
specifier|const
name|QByteArray
name|line
init|=
name|file
operator|.
name|readLine
argument_list|()
decl_stmt|;
name|data
operator|=
name|line
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|data
operator|.
name|count
argument_list|()
operator|<
literal|3
operator|&&
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
do|;
if|if
condition|(
name|file
operator|.
name|atEnd
argument_list|()
condition|)
return|return
literal|false
return|;
name|m_device
operator|=
name|data
operator|.
name|at
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|m_rootPath
operator|=
name|data
operator|.
name|at
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|m_fileSystemType
operator|=
name|data
operator|.
name|at
argument_list|(
literal|2
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|rootPath
specifier|inline
name|QString
name|QStorageIterator
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|m_rootPath
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fileSystemType
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|m_fileSystemType
return|;
block|}
end_function
begin_function
DECL|function|device
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|m_device
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_LINUX
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_HURD
argument_list|)
end_elif
begin_decl_stmt
DECL|variable|pathMounted
specifier|static
specifier|const
name|char
name|pathMounted
index|[]
init|=
literal|"/etc/mtab"
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|bufferSize
specifier|static
specifier|const
name|int
name|bufferSize
init|=
literal|1024
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|bufferSize
comment|// 2 paths (mount point+device) and metainfo;
end_comment
begin_comment
comment|// should be enough
end_comment
begin_constructor
DECL|function|QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|QStorageIterator
parameter_list|()
member_init_list|:
name|buffer
argument_list|(
name|QByteArray
argument_list|(
name|bufferSize
argument_list|,
literal|0
argument_list|)
argument_list|)
block|{
name|fp
operator|=
operator|::
name|setmntent
argument_list|(
name|pathMounted
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|~
name|QStorageIterator
parameter_list|()
block|{
if|if
condition|(
name|fp
condition|)
operator|::
name|endmntent
argument_list|(
name|fp
argument_list|)
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|isValid
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
name|fp
operator|!=
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|next
parameter_list|()
block|{
return|return
operator|::
name|getmntent_r
argument_list|(
name|fp
argument_list|,
operator|&
name|mnt
argument_list|,
name|buffer
operator|.
name|data
argument_list|()
argument_list|,
name|buffer
operator|.
name|size
argument_list|()
argument_list|)
operator|!=
name|Q_NULLPTR
return|;
block|}
end_function
begin_function
DECL|function|rootPath
specifier|inline
name|QString
name|QStorageIterator
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|mnt
operator|.
name|mnt_dir
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fileSystemType
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|mnt
operator|.
name|mnt_type
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|device
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|(
name|mnt
operator|.
name|mnt_fsname
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_HAIKU
argument_list|)
end_elif
begin_constructor
DECL|function|QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|QStorageIterator
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|~
name|QStorageIterator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|next
parameter_list|()
block|{
name|BVolume
name|volume
decl_stmt|;
if|if
condition|(
name|m_volumeRoster
operator|.
name|GetNextVolume
argument_list|(
operator|&
name|volume
argument_list|)
operator|!=
name|B_OK
condition|)
return|return
literal|false
return|;
name|BDirectory
name|directory
decl_stmt|;
if|if
condition|(
name|volume
operator|.
name|GetRootDirectory
argument_list|(
operator|&
name|directory
argument_list|)
operator|!=
name|B_OK
condition|)
return|return
literal|false
return|;
specifier|const
name|BPath
name|path
argument_list|(
operator|&
name|directory
argument_list|)
decl_stmt|;
name|fs_info
name|fsInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|fsInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|fsInfo
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|fs_stat_dev
argument_list|(
name|volume
operator|.
name|Device
argument_list|()
argument_list|,
operator|&
name|fsInfo
argument_list|)
operator|!=
literal|0
condition|)
return|return
literal|false
return|;
name|m_rootPath
operator|=
name|path
operator|.
name|Path
argument_list|()
expr_stmt|;
name|m_fileSystemType
operator|=
name|QByteArray
argument_list|(
name|fsInfo
operator|.
name|fsh_name
argument_list|)
expr_stmt|;
specifier|const
name|QByteArray
name|deviceName
argument_list|(
name|fsInfo
operator|.
name|device_name
argument_list|)
decl_stmt|;
name|m_device
operator|=
operator|(
name|deviceName
operator|.
name|isEmpty
argument_list|()
condition|?
name|QByteArray
operator|::
name|number
argument_list|(
name|qint32
argument_list|(
name|volume
operator|.
name|Device
argument_list|()
argument_list|)
argument_list|)
else|:
name|deviceName
operator|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|rootPath
specifier|inline
name|QString
name|QStorageIterator
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|QFile
operator|::
name|decodeName
argument_list|(
name|m_rootPath
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fileSystemType
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|m_fileSystemType
return|;
block|}
end_function
begin_function
DECL|function|device
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|m_device
return|;
block|}
end_function
begin_else
else|#
directive|else
end_else
begin_constructor
DECL|function|QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|QStorageIterator
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~QStorageIterator
specifier|inline
name|QStorageIterator
operator|::
name|~
name|QStorageIterator
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|isValid
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|isValid
parameter_list|()
specifier|const
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|inline
name|bool
name|QStorageIterator
operator|::
name|next
parameter_list|()
block|{
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|rootPath
specifier|inline
name|QString
name|QStorageIterator
operator|::
name|rootPath
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|fileSystemType
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|fileSystemType
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|device
specifier|inline
name|QByteArray
name|QStorageIterator
operator|::
name|device
parameter_list|()
specifier|const
block|{
return|return
name|QByteArray
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|initRootPath
name|void
name|QStorageInfoPrivate
operator|::
name|initRootPath
parameter_list|()
block|{
name|rootPath
operator|=
name|QFileInfo
argument_list|(
name|rootPath
argument_list|)
operator|.
name|canonicalFilePath
argument_list|()
expr_stmt|;
if|if
condition|(
name|rootPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QStorageIterator
name|it
decl_stmt|;
if|if
condition|(
operator|!
name|it
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|rootPath
operator|=
name|QStringLiteral
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
return|return;
block|}
name|int
name|maxLength
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|oldRootPath
init|=
name|rootPath
decl_stmt|;
name|rootPath
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
name|it
operator|.
name|next
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|mountDir
init|=
name|it
operator|.
name|rootPath
argument_list|()
decl_stmt|;
specifier|const
name|QByteArray
name|fsName
init|=
name|it
operator|.
name|fileSystemType
argument_list|()
decl_stmt|;
comment|// we try to find most suitable entry
if|if
condition|(
name|isParentOf
argument_list|(
name|mountDir
argument_list|,
name|oldRootPath
argument_list|)
operator|&&
name|maxLength
operator|<
name|mountDir
operator|.
name|length
argument_list|()
condition|)
block|{
name|maxLength
operator|=
name|mountDir
operator|.
name|length
argument_list|()
expr_stmt|;
name|rootPath
operator|=
name|mountDir
expr_stmt|;
name|device
operator|=
name|it
operator|.
name|device
argument_list|()
expr_stmt|;
name|fileSystemType
operator|=
name|fsName
expr_stmt|;
block|}
block|}
block|}
end_function
begin_function
DECL|function|retrieveLabel
specifier|static
specifier|inline
name|QString
name|retrieveLabel
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|device
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|Q_OS_LINUX
specifier|static
specifier|const
name|char
name|pathDiskByLabel
index|[]
init|=
literal|"/dev/disk/by-label"
decl_stmt|;
name|QFileInfo
name|devinfo
argument_list|(
name|QFile
operator|::
name|decodeName
argument_list|(
name|device
argument_list|)
argument_list|)
decl_stmt|;
name|QString
name|devicePath
init|=
name|devinfo
operator|.
name|canonicalFilePath
argument_list|()
decl_stmt|;
name|QDirIterator
name|it
argument_list|(
name|QLatin1String
argument_list|(
name|pathDiskByLabel
argument_list|)
argument_list|,
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|it
operator|.
name|next
argument_list|()
expr_stmt|;
name|QFileInfo
name|fileInfo
argument_list|(
name|it
operator|.
name|fileInfo
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|fileInfo
operator|.
name|isSymLink
argument_list|()
operator|&&
name|fileInfo
operator|.
name|symLinkTarget
argument_list|()
operator|==
name|devicePath
condition|)
return|return
name|fileInfo
operator|.
name|fileName
argument_list|()
return|;
block|}
elif|#
directive|elif
name|defined
name|Q_OS_HAIKU
name|fs_info
name|fsInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|fsInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|fsInfo
argument_list|)
argument_list|)
expr_stmt|;
name|int32
name|pos
init|=
literal|0
decl_stmt|;
name|dev_t
name|dev
decl_stmt|;
while|while
condition|(
operator|(
name|dev
operator|=
name|next_dev
argument_list|(
operator|&
name|pos
argument_list|)
operator|)
operator|>=
literal|0
condition|)
block|{
if|if
condition|(
name|fs_stat_dev
argument_list|(
name|dev
argument_list|,
operator|&
name|fsInfo
argument_list|)
operator|!=
literal|0
condition|)
continue|continue;
if|if
condition|(
name|qstrcmp
argument_list|(
name|fsInfo
operator|.
name|device_name
argument_list|,
name|device
operator|.
name|constData
argument_list|()
argument_list|)
operator|==
literal|0
condition|)
return|return
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|fsInfo
operator|.
name|volume_name
argument_list|)
return|;
block|}
else|#
directive|else
name|Q_UNUSED
argument_list|(
name|device
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|QString
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|doStat
name|void
name|QStorageInfoPrivate
operator|::
name|doStat
parameter_list|()
block|{
name|initRootPath
argument_list|()
expr_stmt|;
if|if
condition|(
name|rootPath
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|retrieveVolumeInfo
argument_list|()
expr_stmt|;
name|name
operator|=
name|retrieveLabel
argument_list|(
name|device
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|retrieveVolumeInfo
name|void
name|QStorageInfoPrivate
operator|::
name|retrieveVolumeInfo
parameter_list|()
block|{
name|QT_STATFSBUF
name|statfs_buf
decl_stmt|;
name|int
name|result
decl_stmt|;
name|EINTR_LOOP
argument_list|(
name|result
argument_list|,
name|QT_STATFS
argument_list|(
name|QFile
operator|::
name|encodeName
argument_list|(
name|rootPath
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|statfs_buf
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
literal|0
condition|)
block|{
name|valid
operator|=
literal|true
expr_stmt|;
name|ready
operator|=
literal|true
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|Q_OS_NETBSD
argument_list|)
operator|)
name|bytesTotal
operator|=
name|statfs_buf
operator|.
name|f_blocks
operator|*
name|statfs_buf
operator|.
name|f_bsize
expr_stmt|;
name|bytesFree
operator|=
name|statfs_buf
operator|.
name|f_bfree
operator|*
name|statfs_buf
operator|.
name|f_bsize
expr_stmt|;
name|bytesAvailable
operator|=
name|statfs_buf
operator|.
name|f_bavail
operator|*
name|statfs_buf
operator|.
name|f_bsize
expr_stmt|;
else|#
directive|else
name|bytesTotal
operator|=
name|statfs_buf
operator|.
name|f_blocks
operator|*
name|statfs_buf
operator|.
name|f_frsize
expr_stmt|;
name|bytesFree
operator|=
name|statfs_buf
operator|.
name|f_bfree
operator|*
name|statfs_buf
operator|.
name|f_frsize
expr_stmt|;
name|bytesAvailable
operator|=
name|statfs_buf
operator|.
name|f_bavail
operator|*
name|statfs_buf
operator|.
name|f_frsize
expr_stmt|;
endif|#
directive|endif
name|blockSize
operator|=
name|statfs_buf
operator|.
name|f_bsize
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_ANDROID
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_BSD4
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_INTEGRITY
argument_list|)
if|#
directive|if
name|defined
argument_list|(
name|_STATFS_F_FLAGS
argument_list|)
name|readOnly
operator|=
operator|(
name|statfs_buf
operator|.
name|f_flags
operator|&
name|ST_RDONLY
operator|)
operator|!=
literal|0
expr_stmt|;
endif|#
directive|endif
else|#
directive|else
name|readOnly
operator|=
operator|(
name|statfs_buf
operator|.
name|f_flag
operator|&
name|ST_RDONLY
operator|)
operator|!=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
block|}
end_function
begin_function
DECL|function|mountedVolumes
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
name|QStorageInfoPrivate
operator|::
name|mountedVolumes
parameter_list|()
block|{
name|QStorageIterator
name|it
decl_stmt|;
if|if
condition|(
operator|!
name|it
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
argument_list|()
operator|<<
name|root
argument_list|()
return|;
name|QList
argument_list|<
name|QStorageInfo
argument_list|>
name|volumes
decl_stmt|;
while|while
condition|(
name|it
operator|.
name|next
argument_list|()
condition|)
block|{
if|if
condition|(
operator|!
name|shouldIncludeFs
argument_list|(
name|it
argument_list|)
condition|)
continue|continue;
specifier|const
name|QString
name|mountDir
init|=
name|it
operator|.
name|rootPath
argument_list|()
decl_stmt|;
name|QStorageInfo
name|info
argument_list|(
name|mountDir
argument_list|)
decl_stmt|;
if|if
condition|(
name|info
operator|.
name|bytesTotal
argument_list|()
operator|==
literal|0
condition|)
continue|continue;
name|volumes
operator|.
name|append
argument_list|(
name|info
argument_list|)
expr_stmt|;
block|}
return|return
name|volumes
return|;
block|}
end_function
begin_function
DECL|function|root
name|QStorageInfo
name|QStorageInfoPrivate
operator|::
name|root
parameter_list|()
block|{
return|return
name|QStorageInfo
argument_list|(
name|QStringLiteral
argument_list|(
literal|"/"
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
