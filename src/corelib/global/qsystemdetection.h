begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QGLOBAL_H
end_ifndef
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QSYSTEMDETECTION_H
end_ifndef
begin_define
DECL|macro|QSYSTEMDETECTION_H
define|#
directive|define
name|QSYSTEMDETECTION_H
end_define
begin_comment
comment|/*    The operating system, must be one of: (Q_OS_x)       DARWIN   - Darwin OS (synonym for Q_OS_MAC)      MSDOS    - MS-DOS and Windows      OS2      - OS/2      OS2EMX   - XFree86 on OS/2 (not PM)      WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)      WINCE    - WinCE (Windows CE 5.0)      CYGWIN   - Cygwin      SOLARIS  - Sun Solaris      HPUX     - HP-UX      ULTRIX   - DEC Ultrix      LINUX    - Linux      FREEBSD  - FreeBSD      NETBSD   - NetBSD      OPENBSD  - OpenBSD      BSDI     - BSD/OS      IRIX     - SGI Irix      OSF      - HP Tru64 UNIX      SCO      - SCO OpenServer 5      UNIXWARE - UnixWare 7, Open UNIX 8      AIX      - AIX      HURD     - GNU Hurd      DGUX     - DG/UX      RELIANT  - Reliant UNIX      DYNIX    - DYNIX/ptx      QNX      - QNX      QNX6     - QNX RTP 6.1      LYNX     - LynxOS      BSD4     - Any BSD 4.4 system      UNIX     - Any UNIX BSD/SYSV system */
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__xlC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__xlc__
argument_list|)
operator|)
end_if
begin_define
DECL|macro|Q_OS_DARWIN
define|#
directive|define
name|Q_OS_DARWIN
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef
begin_define
DECL|macro|Q_OS_DARWIN64
define|#
directive|define
name|Q_OS_DARWIN64
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_OS_DARWIN32
define|#
directive|define
name|Q_OS_DARWIN32
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
name|__CYGWIN__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_CYGWIN
define|#
directive|define
name|Q_OS_CYGWIN
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|SAG_COM
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN64__
argument_list|)
operator|)
end_elif
begin_define
DECL|macro|Q_OS_WIN32
define|#
directive|define
name|Q_OS_WIN32
end_define
begin_define
DECL|macro|Q_OS_WIN64
define|#
directive|define
name|Q_OS_WIN64
end_define
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|SAG_COM
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|__WIN32__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NT__
argument_list|)
operator|)
end_elif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|WINCE
argument_list|)
operator|||
name|defined
argument_list|(
name|_WIN32_WCE
argument_list|)
end_if
begin_define
DECL|macro|Q_OS_WINCE
define|#
directive|define
name|Q_OS_WINCE
end_define
begin_else
else|#
directive|else
end_else
begin_define
DECL|macro|Q_OS_WIN32
define|#
directive|define
name|Q_OS_WIN32
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
name|__sun
argument_list|)
operator|||
name|defined
argument_list|(
name|sun
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_SOLARIS
define|#
directive|define
name|Q_OS_SOLARIS
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|hpux
argument_list|)
operator|||
name|defined
argument_list|(
name|__hpux
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_HPUX
define|#
directive|define
name|Q_OS_HPUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ultrix
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_ULTRIX
define|#
directive|define
name|Q_OS_ULTRIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|sinix
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_RELIANT
define|#
directive|define
name|Q_OS_RELIANT
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__native_client__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_NACL
define|#
directive|define
name|Q_OS_NACL
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__linux
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_LINUX
define|#
directive|define
name|Q_OS_LINUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_FREEBSD
define|#
directive|define
name|Q_OS_FREEBSD
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_NETBSD
define|#
directive|define
name|Q_OS_NETBSD
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_OPENBSD
define|#
directive|define
name|Q_OS_OPENBSD
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__bsdi__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_BSDI
define|#
directive|define
name|Q_OS_BSDI
end_define
begin_define
DECL|macro|Q_OS_BSD4
define|#
directive|define
name|Q_OS_BSD4
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sgi
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_IRIX
define|#
directive|define
name|Q_OS_IRIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__osf__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_OSF
define|#
directive|define
name|Q_OS_OSF
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_AIX
define|#
directive|define
name|Q_OS_AIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__Lynx__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_LYNX
define|#
directive|define
name|Q_OS_LYNX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNU__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_HURD
define|#
directive|define
name|Q_OS_HURD
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__DGUX__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_DGUX
define|#
directive|define
name|Q_OS_DGUX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__QNXNTO__
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_QNX
define|#
directive|define
name|Q_OS_QNX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_SEQUENT_
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_DYNIX
define|#
directive|define
name|Q_OS_DYNIX
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_SCO_DS
argument_list|)
end_elif
begin_comment
comment|/* SCO OpenServer 5 + GCC */
end_comment
begin_define
DECL|macro|Q_OS_SCO
define|#
directive|define
name|Q_OS_SCO
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__USLC__
argument_list|)
end_elif
begin_comment
comment|/* all SCO platforms + UDK or OUDK */
end_comment
begin_define
DECL|macro|Q_OS_UNIXWARE
define|#
directive|define
name|Q_OS_UNIXWARE
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__svr4__
argument_list|)
operator|&&
name|defined
argument_list|(
name|i386
argument_list|)
end_elif
begin_comment
comment|/* Open UNIX 8 + GCC */
end_comment
begin_define
DECL|macro|Q_OS_UNIXWARE
define|#
directive|define
name|Q_OS_UNIXWARE
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__INTEGRITY
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_INTEGRITY
define|#
directive|define
name|Q_OS_INTEGRITY
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|VXWORKS
argument_list|)
end_elif
begin_comment
comment|/* there is no "real" VxWorks define - this has to be set in the mkspec! */
end_comment
begin_define
DECL|macro|Q_OS_VXWORKS
define|#
directive|define
name|Q_OS_VXWORKS
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MAKEDEPEND__
argument_list|)
end_elif
begin_else
else|#
directive|else
end_else
begin_error
error|#
directive|error
literal|"Qt has not been ported to this OS - see http://www.qt-project.org/"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WIN64
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_define
DECL|macro|Q_OS_WIN
define|#
directive|define
name|Q_OS_WIN
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_DARWIN
argument_list|)
end_if
begin_define
DECL|macro|Q_OS_MAC
define|#
directive|define
name|Q_OS_MAC
end_define
begin_define
DECL|macro|Q_OS_MACX
define|#
directive|define
name|Q_OS_MACX
end_define
begin_comment
DECL|macro|Q_OS_MACX
comment|/* Q_OS_MACX is only for compatibility.*/
end_comment
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_DARWIN64
argument_list|)
end_if
begin_define
DECL|macro|Q_OS_MAC64
define|#
directive|define
name|Q_OS_MAC64
end_define
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_DARWIN32
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_MAC32
define|#
directive|define
name|Q_OS_MAC32
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_undef
DECL|macro|Q_OS_UNIX
undef|#
directive|undef
name|Q_OS_UNIX
end_undef
begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|Q_OS_UNIX
argument_list|)
end_elif
begin_define
DECL|macro|Q_OS_UNIX
define|#
directive|define
name|Q_OS_UNIX
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_DARWIN
end_ifdef
begin_ifdef
ifdef|#
directive|ifdef
name|MAC_OS_X_VERSION_MIN_REQUIRED
end_ifdef
begin_undef
DECL|macro|MAC_OS_X_VERSION_MIN_REQUIRED
undef|#
directive|undef
name|MAC_OS_X_VERSION_MIN_REQUIRED
end_undef
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|MAC_OS_X_VERSION_MIN_REQUIRED
define|#
directive|define
name|MAC_OS_X_VERSION_MIN_REQUIRED
value|MAC_OS_X_VERSION_10_4
end_define
begin_include
include|#
directive|include
file|<AvailabilityMacros.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MAC_OS_X_VERSION_10_3
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_3
define|#
directive|define
name|MAC_OS_X_VERSION_10_3
value|MAC_OS_X_VERSION_10_2 + 1
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
name|MAC_OS_X_VERSION_10_4
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_4
define|#
directive|define
name|MAC_OS_X_VERSION_10_4
value|MAC_OS_X_VERSION_10_3 + 1
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
name|MAC_OS_X_VERSION_10_5
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_5
define|#
directive|define
name|MAC_OS_X_VERSION_10_5
value|MAC_OS_X_VERSION_10_4 + 1
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
name|MAC_OS_X_VERSION_10_6
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_6
define|#
directive|define
name|MAC_OS_X_VERSION_10_6
value|MAC_OS_X_VERSION_10_5 + 1
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
name|MAC_OS_X_VERSION_10_7
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_7
define|#
directive|define
name|MAC_OS_X_VERSION_10_7
value|MAC_OS_X_VERSION_10_6 + 1
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
name|MAC_OS_X_VERSION_10_8
argument_list|)
end_if
begin_define
DECL|macro|MAC_OS_X_VERSION_10_8
define|#
directive|define
name|MAC_OS_X_VERSION_10_8
value|MAC_OS_X_VERSION_10_7 + 1
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_if
if|#
directive|if
operator|(
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>
name|MAC_OS_X_VERSION_10_8
operator|)
end_if
begin_warning
warning|#
directive|warning
literal|"This version of Mac OS X is unsupported"
end_warning
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__LSB_VERSION__
end_ifdef
begin_if
if|#
directive|if
name|__LSB_VERSION__
operator|<
literal|40
end_if
begin_error
error|#
directive|error
literal|"This version of the Linux Standard Base is unsupported"
end_error
begin_endif
endif|#
directive|endif
end_endif
begin_ifndef
ifndef|#
directive|ifndef
name|QT_LINUXBASE
end_ifndef
begin_define
DECL|macro|QT_LINUXBASE
define|#
directive|define
name|QT_LINUXBASE
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QSYSTEMDETECTION_H
end_comment
end_unit
