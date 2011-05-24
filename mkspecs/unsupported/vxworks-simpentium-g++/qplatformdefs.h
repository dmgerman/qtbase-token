begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the qmake spec of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_include
include|#
directive|include
file|"qfunctions_vxworks.h"
end_include
begin_define
DECL|macro|QT_USE_XOPEN_LFS_EXTENSIONS
define|#
directive|define
name|QT_USE_XOPEN_LFS_EXTENSIONS
end_define
begin_include
include|#
directive|include
file|"../../common/posix/qplatformdefs.h"
end_include
begin_undef
DECL|macro|QT_LSTAT
undef|#
directive|undef
name|QT_LSTAT
end_undef
begin_undef
DECL|macro|QT_MKDIR
undef|#
directive|undef
name|QT_MKDIR
end_undef
begin_undef
DECL|macro|QT_READ
undef|#
directive|undef
name|QT_READ
end_undef
begin_undef
DECL|macro|QT_WRITE
undef|#
directive|undef
name|QT_WRITE
end_undef
begin_undef
DECL|macro|QT_SOCKLEN_T
undef|#
directive|undef
name|QT_SOCKLEN_T
end_undef
begin_undef
DECL|macro|QT_SOCKET_CONNECT
undef|#
directive|undef
name|QT_SOCKET_CONNECT
end_undef
begin_define
DECL|macro|QT_LSTAT
define|#
directive|define
name|QT_LSTAT
value|QT_STAT
end_define
begin_define
DECL|macro|QT_MKDIR
define|#
directive|define
name|QT_MKDIR
parameter_list|(
name|dir
parameter_list|,
name|perm
parameter_list|)
value|::mkdir(dir)
end_define
begin_define
DECL|macro|QT_READ
define|#
directive|define
name|QT_READ
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|::read(fd, (char*) buf, len)
end_define
begin_define
DECL|macro|QT_WRITE
define|#
directive|define
name|QT_WRITE
parameter_list|(
name|fd
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|::write(fd, (char*) buf, len)
end_define
begin_comment
comment|// there IS a socklen_t in sys/socket.h (unsigned int),
end_comment
begin_comment
comment|// but sockLib.h uses int in all function declaration...
end_comment
begin_define
DECL|macro|QT_SOCKLEN_T
define|#
directive|define
name|QT_SOCKLEN_T
value|int
end_define
begin_define
DECL|macro|QT_SOCKET_CONNECT
define|#
directive|define
name|QT_SOCKET_CONNECT
parameter_list|(
name|sd
parameter_list|,
name|to
parameter_list|,
name|tolen
parameter_list|)
define|\
value|::connect(sd, (struct sockaddr *) to, tolen)
end_define
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
