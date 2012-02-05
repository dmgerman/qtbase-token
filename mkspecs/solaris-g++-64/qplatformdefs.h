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
begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef
begin_define
DECL|macro|_POSIX_PTHREAD_SEMANTICS
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
end_define
begin_endif
endif|#
directive|endif
end_endif
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
file|<sys/filio.h>
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
file|<sys/shm.h>
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
begin_include
include|#
directive|include
file|<netinet/in.h>
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
begin_define
DECL|macro|QT_USE_XOPEN_LFS_EXTENSIONS
define|#
directive|define
name|QT_USE_XOPEN_LFS_EXTENSIONS
end_define
begin_include
include|#
directive|include
file|"../common/posix/qplatformdefs.h"
end_include
begin_undef
DECL|macro|QT_SOCKET_CONNECT
undef|#
directive|undef
name|QT_SOCKET_CONNECT
end_undef
begin_define
DECL|macro|QT_SOCKET_CONNECT
define|#
directive|define
name|QT_SOCKET_CONNECT
value|qt_socket_connect
end_define
begin_comment
comment|// Solaris redefines connect -> __xnet_connect with _XOPEN_SOURCE_EXTENDED
end_comment
begin_function
DECL|function|qt_socket_connect
specifier|static
specifier|inline
name|int
name|qt_socket_connect
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|QT_SOCKLEN_T
name|addrlen
parameter_list|)
block|{
return|return
operator|::
name|connect
argument_list|(
name|s
argument_list|,
name|addr
argument_list|,
name|addrlen
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|connect
argument_list|)
end_if
begin_undef
DECL|macro|connect
undef|#
directive|undef
name|connect
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Solaris redefines bind -> __xnet_bind with _XOPEN_SOURCE_EXTENDED
end_comment
begin_function
DECL|function|qt_socket_bind
specifier|static
specifier|inline
name|int
name|qt_socket_bind
parameter_list|(
name|int
name|s
parameter_list|,
name|struct
name|sockaddr
modifier|*
name|addr
parameter_list|,
name|QT_SOCKLEN_T
name|addrlen
parameter_list|)
block|{
return|return
operator|::
name|bind
argument_list|(
name|s
argument_list|,
name|addr
argument_list|,
name|addrlen
argument_list|)
return|;
block|}
end_function
begin_if
if|#
directive|if
name|defined
argument_list|(
name|bind
argument_list|)
end_if
begin_undef
DECL|macro|bind
undef|#
directive|undef
name|bind
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Only Solaris 7 and better support 64-bit
end_comment
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
begin_comment
comment|// QPLATFORMDEFS_H
end_comment
end_unit
