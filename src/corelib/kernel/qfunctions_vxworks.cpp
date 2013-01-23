begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qglobal.h"
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_VXWORKS
end_ifdef
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"qfunctions_vxworks.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WRS_KERNEL
argument_list|)
end_if
begin_include
include|#
directive|include
file|<vmLib.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<selectLib.h>
end_include
begin_include
include|#
directive|include
file|<ioLib.h>
end_include
begin_expr_stmt
name|QT_USE_NAMESPACE
ifdef|#
directive|ifdef
name|__cplusplus
specifier|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// no lfind() - used by the TIF image format
DECL|function|lfind
name|void
operator|*
name|lfind
argument_list|(
argument|const void* key
argument_list|,
argument|const void* base
argument_list|,
argument|size_t* elements
argument_list|,
argument|size_t size
argument_list|,
argument|int (*compare)(const void*, const void*)
argument_list|)
block|{
specifier|const
name|char
operator|*
name|current
operator|=
operator|(
name|char
operator|*
operator|)
name|base
block|;
specifier|const
name|char
operator|*
specifier|const
name|end
operator|=
operator|(
name|char
operator|*
operator|)
operator|(
name|current
operator|+
operator|(
operator|*
name|elements
operator|)
operator|*
name|size
operator|)
block|;
while|while
condition|(
name|current
operator|!=
name|end
condition|)
block|{
if|if
condition|(
name|compare
argument_list|(
name|current
argument_list|,
name|key
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|void
operator|*
operator|)
name|current
return|;
name|current
operator|+=
name|size
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_expr_stmt
begin_comment
comment|// no rand_r(), but rand()
end_comment
begin_comment
comment|// NOTE: this implementation is wrong for multi threaded applications,
end_comment
begin_comment
comment|// but there is no way to get it right on VxWorks (in kernel mode)
end_comment
begin_function
DECL|function|rand_r
name|int
name|rand_r
parameter_list|(
name|unsigned
name|int
modifier|*
comment|/*seedp*/
parameter_list|)
block|{
return|return
name|rand
argument_list|()
return|;
block|}
end_function
begin_comment
comment|// no usleep() support
end_comment
begin_function
DECL|function|usleep
name|int
name|usleep
parameter_list|(
name|unsigned
name|int
name|usec
parameter_list|)
block|{
name|div_t
name|dt
init|=
name|div
argument_list|(
name|usec
argument_list|,
literal|1000000
argument_list|)
decl_stmt|;
name|struct
name|timespec
name|ts
init|=
block|{
name|dt
operator|.
name|quot
block|,
name|dt
operator|.
name|rem
operator|*
literal|1000
block|}
decl_stmt|;
return|return
name|nanosleep
argument_list|(
operator|&
name|ts
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// gettimeofday() is declared, but is missing from the library
end_comment
begin_comment
comment|// It IS however defined in the Curtis-Wright X11 libraries, so
end_comment
begin_comment
comment|// we have to make the symbol 'weak'
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_CC_DIAB
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VXWORKS_DKM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VXWORKS_RTP
argument_list|)
end_if
begin_pragma
DECL|macro|gettimeofday
pragma|#
directive|pragma
name|weak
name|gettimeofday
end_pragma
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|gettimeofday
name|int
name|gettimeofday
parameter_list|(
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|void
comment|/*struct timezone*/
modifier|*
parameter_list|)
block|{
comment|// the compiler will optimize this and will only use one code path
if|if
condition|(
sizeof|sizeof
argument_list|(
expr|struct
name|timeval
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
expr|struct
name|timespec
argument_list|)
condition|)
block|{
name|int
name|res
init|=
name|clock_gettime
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|(
expr|struct
name|timespec
operator|*
operator|)
name|tv
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|res
condition|)
name|tv
operator|->
name|tv_usec
operator|/=
literal|1000
expr_stmt|;
return|return
name|res
return|;
block|}
else|else
block|{
name|struct
name|timespec
name|ts
decl_stmt|;
name|int
name|res
init|=
name|clock_gettime
argument_list|(
name|CLOCK_REALTIME
argument_list|,
operator|&
name|ts
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|res
condition|)
block|{
name|tv
operator|->
name|tv_sec
operator|=
name|ts
operator|.
name|tv_sec
expr_stmt|;
name|tv
operator|->
name|tv_usec
operator|=
name|ts
operator|.
name|tv_nsec
operator|/
literal|1000
expr_stmt|;
block|}
return|return
name|res
return|;
block|}
block|}
end_function
begin_comment
comment|// neither getpagesize() or sysconf(_SC_PAGESIZE) are available
end_comment
begin_function
DECL|function|getpagesize
name|int
name|getpagesize
parameter_list|()
block|{
if|#
directive|if
name|defined
argument_list|(
name|_WRS_KERNEL
argument_list|)
return|return
name|vmPageSizeGet
argument_list|()
return|;
else|#
directive|else
return|return
name|sysconf
argument_list|(
name|_SC_PAGESIZE
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// symlinks are not supported (lstat is now just a call to stat - see qplatformdefs.h)
end_comment
begin_function
DECL|function|symlink
name|int
name|symlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_function
DECL|function|readlink
name|ssize_t
name|readlink
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
block|{
name|errno
operator|=
name|EIO
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|// there's no truncate(), but ftruncate() support...
end_comment
begin_function
DECL|function|truncate
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|off_t
name|length
parameter_list|)
block|{
name|int
name|fd
init|=
name|open
argument_list|(
name|path
argument_list|,
name|O_WRONLY
argument_list|,
literal|00777
argument_list|)
decl_stmt|;
if|if
condition|(
name|fd
operator|>=
literal|0
condition|)
block|{
name|int
name|res
init|=
name|ftruncate
argument_list|(
name|fd
argument_list|,
name|length
argument_list|)
decl_stmt|;
name|int
name|en
init|=
name|errno
decl_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|errno
operator|=
name|en
expr_stmt|;
return|return
name|res
return|;
block|}
comment|// errno is already set by open
return|return
operator|-
literal|1
return|;
block|}
end_function
begin_comment
comment|// VxWorks doesn't know about passwd& friends.
end_comment
begin_comment
comment|// in order to avoid patching the unix fs path everywhere
end_comment
begin_comment
comment|// we introduce some dummy functions that simulate a single
end_comment
begin_comment
comment|// 'root' user on the system.
end_comment
begin_function
DECL|function|getuid
name|uid_t
name|getuid
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|getgid
name|gid_t
name|getgid
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|geteuid
name|uid_t
name|geteuid
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
end_function
begin_function
DECL|function|getpwuid
name|struct
name|passwd
modifier|*
name|getpwuid
parameter_list|(
name|uid_t
name|uid
parameter_list|)
block|{
specifier|static
name|struct
name|passwd
name|pwbuf
init|=
block|{
literal|"root"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
if|if
condition|(
name|uid
operator|==
literal|0
condition|)
block|{
return|return
operator|&
name|pwbuf
return|;
block|}
else|else
block|{
name|errno
operator|=
name|ENOENT
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_function
DECL|function|getgrgid
name|struct
name|group
modifier|*
name|getgrgid
parameter_list|(
name|gid_t
name|gid
parameter_list|)
block|{
specifier|static
name|struct
name|group
name|grbuf
init|=
block|{
literal|"root"
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
if|if
condition|(
name|gid
operator|==
literal|0
condition|)
block|{
return|return
operator|&
name|grbuf
return|;
block|}
else|else
block|{
name|errno
operator|=
name|ENOENT
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_comment
unit|}
comment|// extern "C"
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_VXWORKS
end_comment
end_unit
