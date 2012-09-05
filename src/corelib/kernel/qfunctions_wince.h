begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QFUNCTIONS_WINCE_H
end_ifndef
begin_define
DECL|macro|QFUNCTIONS_WINCE_H
define|#
directive|define
name|QFUNCTIONS_WINCE_H
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_include
include|#
directive|include
file|<stdlib.h>
end_include
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_include
include|#
directive|include
file|<winuser.h>
end_include
begin_include
include|#
directive|include
file|<winbase.h>
end_include
begin_include
include|#
directive|include
file|<objbase.h>
end_include
begin_include
include|#
directive|include
file|<kfuncs.h>
end_include
begin_include
include|#
directive|include
file|<ctype.h>
end_include
begin_include
include|#
directive|include
file|<time.h>
end_include
begin_include
include|#
directive|include
file|<crtdefs.h>
end_include
begin_include
include|#
directive|include
file|<altcecrt.h>
end_include
begin_include
include|#
directive|include
file|<winsock.h>
end_include
begin_include
include|#
directive|include
file|<ceconfig.h>
end_include
begin_function_decl
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
ifdef|#
directive|ifdef
name|QT_BUILD_CORE_LIB
endif|#
directive|endif
name|QT_END_NAMESPACE
name|QT_END_HEADER
comment|// The standard SDK misses this define...
DECL|macro|_control87
define|#
directive|define
name|_control87
value|_controlfp
if|#
directive|if
operator|!
name|defined
name|__cplusplus
DECL|macro|bool
define|#
directive|define
name|bool
value|int
DECL|macro|true
define|#
directive|define
name|true
value|1
DECL|macro|false
define|#
directive|define
name|false
value|0
endif|#
directive|endif
comment|// Environment ------------------------------------------------------
name|errno_t
name|qt_wince_getenv_s
parameter_list|(
name|size_t
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_function_decl
name|errno_t
name|qt_wince__putenv_s
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_comment
comment|// have this as tiff plugin is written in C
end_comment
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NO_ERRNO_H
argument_list|)
DECL|macro|NO_ERRNO_H
define|#
directive|define
name|NO_ERRNO_H
endif|#
directive|endif
comment|// Environment ------------------------------------------------------
name|int
name|qt_wince__getpid
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|// Time -------------------------------------------------------------
ifndef|#
directive|ifndef
name|_TM_DEFINED
DECL|macro|_TM_DEFINED
define|#
directive|define
name|_TM_DEFINED
DECL|struct|tm
struct|struct
name|tm
block|{
DECL|member|tm_sec
name|int
name|tm_sec
decl_stmt|;
comment|/* seconds after the minute - [0,59] */
DECL|member|tm_min
name|int
name|tm_min
decl_stmt|;
comment|/* minutes after the hour - [0,59] */
DECL|member|tm_hour
name|int
name|tm_hour
decl_stmt|;
comment|/* hours since midnight - [0,23] */
DECL|member|tm_mday
name|int
name|tm_mday
decl_stmt|;
comment|/* day of the month - [1,31] */
DECL|member|tm_mon
name|int
name|tm_mon
decl_stmt|;
comment|/* months since January - [0,11] */
DECL|member|tm_year
name|int
name|tm_year
decl_stmt|;
comment|/* years since 1900 */
DECL|member|tm_wday
name|int
name|tm_wday
decl_stmt|;
comment|/* days since Sunday - [0,6] */
DECL|member|tm_yday
name|int
name|tm_yday
decl_stmt|;
comment|/* days since January 1 - [0,365] */
DECL|member|tm_isdst
name|int
name|tm_isdst
decl_stmt|;
comment|/* daylight savings time flag */
block|}
struct|;
endif|#
directive|endif
comment|// _TM_DEFINED
name|FILETIME
name|qt_wince_time_tToFt
parameter_list|(
name|time_t
name|tt
parameter_list|)
function_decl|;
comment|// File I/O ---------------------------------------------------------
DECL|macro|_O_RDONLY
define|#
directive|define
name|_O_RDONLY
value|0x0001
DECL|macro|_O_RDWR
define|#
directive|define
name|_O_RDWR
value|0x0002
DECL|macro|_O_WRONLY
define|#
directive|define
name|_O_WRONLY
value|0x0004
DECL|macro|_O_CREAT
define|#
directive|define
name|_O_CREAT
value|0x0008
DECL|macro|_O_TRUNC
define|#
directive|define
name|_O_TRUNC
value|0x0010
DECL|macro|_O_APPEND
define|#
directive|define
name|_O_APPEND
value|0x0020
DECL|macro|_O_EXCL
define|#
directive|define
name|_O_EXCL
value|0x0040
DECL|macro|O_RDONLY
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
DECL|macro|O_RDWR
define|#
directive|define
name|O_RDWR
value|_O_RDWR
DECL|macro|O_WRONLY
define|#
directive|define
name|O_WRONLY
value|_O_WRONLY
DECL|macro|O_CREAT
define|#
directive|define
name|O_CREAT
value|_O_CREAT
DECL|macro|O_TRUNC
define|#
directive|define
name|O_TRUNC
value|_O_TRUNC
DECL|macro|O_APPEND
define|#
directive|define
name|O_APPEND
value|_O_APPEND
DECL|macro|O_EXCL
define|#
directive|define
name|O_EXCL
value|_O_EXCL
DECL|macro|_S_IFMT
define|#
directive|define
name|_S_IFMT
value|0x0600
DECL|macro|_S_IFDIR
define|#
directive|define
name|_S_IFDIR
value|0x0200
DECL|macro|_S_IFCHR
define|#
directive|define
name|_S_IFCHR
value|0x0100
DECL|macro|_S_IFREG
define|#
directive|define
name|_S_IFREG
value|0x0400
DECL|macro|_S_IREAD
define|#
directive|define
name|_S_IREAD
value|0x0010
DECL|macro|_S_IWRITE
define|#
directive|define
name|_S_IWRITE
value|0x0008
DECL|macro|S_IFMT
define|#
directive|define
name|S_IFMT
value|_S_IFMT
DECL|macro|S_IFDIR
define|#
directive|define
name|S_IFDIR
value|_S_IFDIR
DECL|macro|S_IFCHR
define|#
directive|define
name|S_IFCHR
value|_S_IFCHR
DECL|macro|S_IFREG
define|#
directive|define
name|S_IFREG
value|_S_IFREG
DECL|macro|S_IREAD
define|#
directive|define
name|S_IREAD
value|_S_IREAD
DECL|macro|S_IWRITE
define|#
directive|define
name|S_IWRITE
value|_S_IWRITE
ifndef|#
directive|ifndef
name|_IOFBF
DECL|macro|_IOFBF
define|#
directive|define
name|_IOFBF
value|0x0000
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_IOLBF
DECL|macro|_IOLBF
define|#
directive|define
name|_IOLBF
value|0x0040
endif|#
directive|endif
ifndef|#
directive|ifndef
name|_IONBF
DECL|macro|_IONBF
define|#
directive|define
name|_IONBF
value|0x0004
endif|#
directive|endif
comment|// Regular Berkeley error constants
ifndef|#
directive|ifndef
name|_STAT_DEFINED
DECL|macro|_STAT_DEFINED
define|#
directive|define
name|_STAT_DEFINED
DECL|struct|stat
struct|struct
name|stat
block|{
DECL|member|st_mode
name|int
name|st_mode
decl_stmt|;
DECL|member|st_size
name|int
name|st_size
decl_stmt|;
DECL|member|st_nlink
name|int
name|st_nlink
decl_stmt|;
DECL|member|st_mtime
name|time_t
name|st_mtime
decl_stmt|;
DECL|member|st_atime
name|time_t
name|st_atime
decl_stmt|;
DECL|member|st_ctime
name|time_t
name|st_ctime
decl_stmt|;
block|}
struct|;
endif|#
directive|endif
DECL|typedef|mode_t
typedef|typedef
name|int
name|mode_t
typedef|;
specifier|extern
name|int
name|errno
decl_stmt|;
name|int
name|qt_wince__getdrive
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|int
name|qt_wince__waccess
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|path
parameter_list|,
name|int
name|pmode
parameter_list|)
function_decl|;
name|int
name|qt_wince__wopen
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|filename
parameter_list|,
name|int
name|oflag
parameter_list|,
name|int
name|pmode
parameter_list|)
function_decl|;
name|long
name|qt_wince__lseek
parameter_list|(
name|int
name|handle
parameter_list|,
name|long
name|offset
parameter_list|,
name|int
name|origin
parameter_list|)
function_decl|;
name|int
name|qt_wince__read
parameter_list|(
name|int
name|handle
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
function_decl|;
name|int
name|qt_wince__write
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|void
modifier|*
name|buffer
parameter_list|,
name|unsigned
name|int
name|count
parameter_list|)
function_decl|;
name|int
name|qt_wince__close
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|qt_wince__fdopen
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|qt_wince_fdopen
parameter_list|(
name|int
name|handle
parameter_list|,
specifier|const
name|char
modifier|*
name|mode
parameter_list|)
function_decl|;
name|void
name|qt_wince_rewind
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|)
function_decl|;
name|int
name|qt_wince___fileno
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|FILE
modifier|*
name|qt_wince_tmpfile
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|//For zlib we need these helper functions, but they break the build when
comment|//set globally, so just set them for zlib use
ifdef|#
directive|ifdef
name|ZLIB_H
DECL|macro|open
define|#
directive|define
name|open
value|qt_wince_open
DECL|macro|close
define|#
directive|define
name|close
value|qt_wince__close
DECL|macro|lseek
define|#
directive|define
name|lseek
value|qt_wince__lseek
DECL|macro|read
define|#
directive|define
name|read
value|qt_wince__read
DECL|macro|write
define|#
directive|define
name|write
value|qt_wince__write
endif|#
directive|endif
name|int
name|qt_wince__mkdir
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
name|int
name|qt_wince__rmdir
parameter_list|(
specifier|const
name|char
modifier|*
name|dirname
parameter_list|)
function_decl|;
name|int
name|qt_wince__access
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|int
name|pmode
parameter_list|)
function_decl|;
name|int
name|qt_wince__rename
parameter_list|(
specifier|const
name|char
modifier|*
name|oldname
parameter_list|,
specifier|const
name|char
modifier|*
name|newname
parameter_list|)
function_decl|;
name|int
name|qt_wince__remove
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
name|int
name|qt_wince_open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|oflag
parameter_list|,
name|int
name|pmode
init|=
literal|0
parameter_list|)
function_decl|;
else|#
directive|else
name|int
name|qt_wince_open
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|int
name|oflag
parameter_list|,
name|int
name|pmode
parameter_list|)
function_decl|;
endif|#
directive|endif
name|int
name|qt_wince_stat
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|struct
name|stat
modifier|*
name|buffer
parameter_list|)
function_decl|;
name|int
name|qt_wince__fstat
parameter_list|(
name|int
name|handle
parameter_list|,
name|struct
name|stat
modifier|*
name|buffer
parameter_list|)
function_decl|;
DECL|macro|SEM_FAILCRITICALERRORS
define|#
directive|define
name|SEM_FAILCRITICALERRORS
value|0x0001
DECL|macro|SEM_NOOPENFILEERRORBOX
define|#
directive|define
name|SEM_NOOPENFILEERRORBOX
value|0x0002
name|int
name|qt_wince_SetErrorMode
parameter_list|(
name|int
parameter_list|)
function_decl|;
ifndef|#
directive|ifndef
name|CoInitialize
DECL|macro|CoInitialize
define|#
directive|define
name|CoInitialize
parameter_list|(
name|x
parameter_list|)
value|CoInitializeEx(x, COINIT_MULTITHREADED)
endif|#
directive|endif
name|bool
name|qt_wince__chmod
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
name|bool
name|qt_wince__wchmod
parameter_list|(
specifier|const
name|wchar_t
modifier|*
name|file
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|4273
name|)
name|HANDLE
name|qt_wince_CreateFileA
parameter_list|(
name|LPCSTR
parameter_list|,
name|DWORD
parameter_list|,
name|DWORD
parameter_list|,
name|LPSECURITY_ATTRIBUTES
parameter_list|,
name|DWORD
parameter_list|,
name|DWORD
parameter_list|,
name|HANDLE
parameter_list|)
function_decl|;
comment|// Printer ----------------------------------------------------------
DECL|macro|ETO_GLYPH_INDEX
define|#
directive|define
name|ETO_GLYPH_INDEX
value|0x0010
comment|// Graphics ---------------------------------------------------------
ifndef|#
directive|ifndef
name|SM_CXCURSOR
DECL|macro|SM_CXCURSOR
define|#
directive|define
name|SM_CXCURSOR
value|13
endif|#
directive|endif
ifndef|#
directive|ifndef
name|SM_CYCURSOR
DECL|macro|SM_CYCURSOR
define|#
directive|define
name|SM_CYCURSOR
value|14
endif|#
directive|endif
name|BOOL
name|qt_wince_SetWindowOrgEx
parameter_list|(
name|HDC
name|hdc
parameter_list|,
name|int
name|X
parameter_list|,
name|int
name|Y
parameter_list|,
name|LPPOINT
name|lpPoint
parameter_list|)
function_decl|;
comment|// Other stuff ------------------------------------------------------
DECL|macro|MWMO_ALERTABLE
define|#
directive|define
name|MWMO_ALERTABLE
value|0x0002
comment|// ### not the real values
DECL|macro|CREATE_NO_WINDOW
define|#
directive|define
name|CREATE_NO_WINDOW
value|2
DECL|macro|CF_HDROP
define|#
directive|define
name|CF_HDROP
value|15
name|void
modifier|*
name|qt_wince_calloc
parameter_list|(
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TLS_OUT_OF_INDEXES
argument_list|)
DECL|macro|TLS_OUT_OF_INDEXES
define|#
directive|define
name|TLS_OUT_OF_INDEXES
value|0xffffffff
endif|#
directive|endif
name|DWORD
name|qt_wince_GetThreadLocale
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|HANDLE
name|qt_wince__beginthread
parameter_list|(
name|void
function_decl|(
modifier|*
name|start_address
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|unsigned
name|stack_size
parameter_list|,
name|void
modifier|*
name|arglist
parameter_list|)
function_decl|;
name|unsigned
name|long
name|qt_wince__beginthreadex
parameter_list|(
name|void
modifier|*
name|security
parameter_list|,
name|unsigned
name|stack_size
parameter_list|,
name|unsigned
function_decl|(
name|__stdcall
modifier|*
name|start_address
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arglist
parameter_list|,
name|unsigned
name|initflag
parameter_list|,
name|unsigned
modifier|*
name|thrdaddr
parameter_list|)
function_decl|;
name|void
name|qt_wince__endthreadex
parameter_list|(
name|unsigned
name|nExitCode
parameter_list|)
function_decl|;
comment|// bsearch is needed for building the tiff plugin
comment|// otherwise it could go into qguifunctions_wce
name|void
modifier|*
name|qt_wince_bsearch
parameter_list|(
specifier|const
name|void
modifier|*
name|key
parameter_list|,
specifier|const
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|num
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
function_decl|(
name|__cdecl
modifier|*
name|compare
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
comment|// Missing typedefs
ifndef|#
directive|ifndef
name|_TIME_T_DEFINED
DECL|typedef|time_t
typedef|typedef
name|unsigned
name|long
name|time_t
typedef|;
DECL|macro|_TIME_T_DEFINED
define|#
directive|define
name|_TIME_T_DEFINED
endif|#
directive|endif
DECL|typedef|HDROP
typedef|typedef
name|HANDLE
name|HDROP
typedef|;
ifndef|#
directive|ifndef
name|WS_THICKFRAME
DECL|macro|WS_THICKFRAME
define|#
directive|define
name|WS_THICKFRAME
value|WS_DLGFRAME
endif|#
directive|endif
DECL|typedef|UWORD
typedef|typedef
name|UINT
name|UWORD
typedef|;
comment|// Missing definitions: not necessary equal to their Win32 values
comment|// (the goal is to just have a clean compilation of MFC)
DECL|macro|WS_MAXIMIZE
define|#
directive|define
name|WS_MAXIMIZE
value|0
DECL|macro|WS_MINIMIZE
define|#
directive|define
name|WS_MINIMIZE
value|0
ifndef|#
directive|ifndef
name|WS_EX_TOOLWINDOW
DECL|macro|WS_EX_TOOLWINDOW
define|#
directive|define
name|WS_EX_TOOLWINDOW
value|0
endif|#
directive|endif
DECL|macro|WS_EX_NOPARENTNOTIFY
define|#
directive|define
name|WS_EX_NOPARENTNOTIFY
value|0
DECL|macro|WM_ENTERIDLE
define|#
directive|define
name|WM_ENTERIDLE
value|0x0121
DECL|macro|WM_PRINT
define|#
directive|define
name|WM_PRINT
value|WM_PAINT
DECL|macro|WM_NCCREATE
define|#
directive|define
name|WM_NCCREATE
value|(0x0081)
DECL|macro|WM_PARENTNOTIFY
define|#
directive|define
name|WM_PARENTNOTIFY
value|0
DECL|macro|WM_NCDESTROY
define|#
directive|define
name|WM_NCDESTROY
value|(WM_APP-1)
ifndef|#
directive|ifndef
name|SW_RESTORE
DECL|macro|SW_RESTORE
define|#
directive|define
name|SW_RESTORE
value|(SW_SHOWNORMAL)
endif|#
directive|endif
DECL|macro|SW_NORMAL
define|#
directive|define
name|SW_NORMAL
value|(SW_SHOWNORMAL)
DECL|macro|WAIT_OBJECT_0
define|#
directive|define
name|WAIT_OBJECT_0
value|0x00000000L
DECL|macro|DEFAULT_GUI_FONT
define|#
directive|define
name|DEFAULT_GUI_FONT
value|SYSTEM_FONT
ifndef|#
directive|ifndef
name|SWP_NOREDRAW
DECL|macro|SWP_NOREDRAW
define|#
directive|define
name|SWP_NOREDRAW
value|0
endif|#
directive|endif
DECL|macro|WSAGETSELECTEVENT
define|#
directive|define
name|WSAGETSELECTEVENT
parameter_list|(
name|lParam
parameter_list|)
value|LOWORD(lParam)
DECL|macro|HWND_TOPMOST
define|#
directive|define
name|HWND_TOPMOST
value|((HWND)-1)
DECL|macro|HWND_NOTOPMOST
define|#
directive|define
name|HWND_NOTOPMOST
value|((HWND)-2)
DECL|macro|PS_DOT
define|#
directive|define
name|PS_DOT
value|2
DECL|macro|PD_ALLPAGES
define|#
directive|define
name|PD_ALLPAGES
value|0
DECL|macro|PD_USEDEVMODECOPIES
define|#
directive|define
name|PD_USEDEVMODECOPIES
value|0
DECL|macro|PD_NOSELECTION
define|#
directive|define
name|PD_NOSELECTION
value|0
DECL|macro|PD_HIDEPRINTTOFILE
define|#
directive|define
name|PD_HIDEPRINTTOFILE
value|0
DECL|macro|PD_NOPAGENUMS
define|#
directive|define
name|PD_NOPAGENUMS
value|0
DECL|macro|CF_METAFILEPICT
define|#
directive|define
name|CF_METAFILEPICT
value|3
DECL|macro|MM_ANISOTROPIC
define|#
directive|define
name|MM_ANISOTROPIC
value|8
DECL|macro|KF_ALTDOWN
define|#
directive|define
name|KF_ALTDOWN
value|0x2000
DECL|macro|SPI_GETWORKAREA
define|#
directive|define
name|SPI_GETWORKAREA
value|48
ifndef|#
directive|ifndef
name|WM_SETCURSOR
DECL|macro|WM_SETCURSOR
define|#
directive|define
name|WM_SETCURSOR
value|0x0020
DECL|macro|IDC_ARROW
define|#
directive|define
name|IDC_ARROW
value|MAKEINTRESOURCE(32512)
DECL|macro|IDC_IBEAM
define|#
directive|define
name|IDC_IBEAM
value|MAKEINTRESOURCE(32513)
DECL|macro|IDC_WAIT
define|#
directive|define
name|IDC_WAIT
value|MAKEINTRESOURCE(32514)
DECL|macro|IDC_CROSS
define|#
directive|define
name|IDC_CROSS
value|MAKEINTRESOURCE(32515)
DECL|macro|IDC_UPARROW
define|#
directive|define
name|IDC_UPARROW
value|MAKEINTRESOURCE(32516)
DECL|macro|IDC_SIZE
define|#
directive|define
name|IDC_SIZE
value|MAKEINTRESOURCE(32646)
DECL|macro|IDC_ICON
define|#
directive|define
name|IDC_ICON
value|MAKEINTRESOURCE(32512)
DECL|macro|IDC_SIZENWSE
define|#
directive|define
name|IDC_SIZENWSE
value|MAKEINTRESOURCE(32642)
DECL|macro|IDC_SIZENESW
define|#
directive|define
name|IDC_SIZENESW
value|MAKEINTRESOURCE(32643)
DECL|macro|IDC_SIZEWE
define|#
directive|define
name|IDC_SIZEWE
value|MAKEINTRESOURCE(32644)
DECL|macro|IDC_SIZENS
define|#
directive|define
name|IDC_SIZENS
value|MAKEINTRESOURCE(32645)
DECL|macro|IDC_SIZEALL
define|#
directive|define
name|IDC_SIZEALL
value|MAKEINTRESOURCE(32646)
DECL|macro|IDC_NO
define|#
directive|define
name|IDC_NO
value|MAKEINTRESOURCE(32648)
DECL|macro|IDC_APPSTARTING
define|#
directive|define
name|IDC_APPSTARTING
value|MAKEINTRESOURCE(32650)
DECL|macro|IDC_HELP
define|#
directive|define
name|IDC_HELP
value|MAKEINTRESOURCE(32651)
DECL|macro|IDC_HAND
define|#
directive|define
name|IDC_HAND
value|MAKEINTRESOURCE(32649)
endif|#
directive|endif
DECL|macro|GMEM_MOVEABLE
define|#
directive|define
name|GMEM_MOVEABLE
value|LMEM_MOVEABLE
DECL|macro|GPTR
define|#
directive|define
name|GPTR
value|LPTR
comment|// WinCE: CESYSGEN prunes the following FRP defines,
comment|// and INTERNET_TRANSFER_TYPE_ASCII breaks in wininet.h
DECL|macro|FTP_TRANSFER_TYPE_ASCII
undef|#
directive|undef
name|FTP_TRANSFER_TYPE_ASCII
DECL|macro|FTP_TRANSFER_TYPE_ASCII
define|#
directive|define
name|FTP_TRANSFER_TYPE_ASCII
value|0x00000001
DECL|macro|FTP_TRANSFER_TYPE_BINARY
undef|#
directive|undef
name|FTP_TRANSFER_TYPE_BINARY
DECL|macro|FTP_TRANSFER_TYPE_BINARY
define|#
directive|define
name|FTP_TRANSFER_TYPE_BINARY
value|0x00000002
DECL|typedef|OLE_COLOR
typedef|typedef
name|DWORD
name|OLE_COLOR
typedef|;
comment|// Define the Windows Styles which are not defined by MS
ifndef|#
directive|ifndef
name|WS_POPUPWINDOW
DECL|macro|WS_POPUPWINDOW
define|#
directive|define
name|WS_POPUPWINDOW
value|WS_POPUP|WS_BORDER|WS_SYSMENU|WS_CAPTION
endif|#
directive|endif
ifndef|#
directive|ifndef
name|WS_OVERLAPPEDWINDOW
DECL|macro|WS_OVERLAPPEDWINDOW
define|#
directive|define
name|WS_OVERLAPPEDWINDOW
value|WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_THICKFRAME|WS_MINIMIZEBOX|WS_MAXIMIZEBOX
endif|#
directive|endif
ifndef|#
directive|ifndef
name|WS_TILED
DECL|macro|WS_TILED
define|#
directive|define
name|WS_TILED
value|WS_OVERLAPPED
endif|#
directive|endif
ifndef|#
directive|ifndef
name|WS_TILEDWINDOW
DECL|macro|WS_TILEDWINDOW
define|#
directive|define
name|WS_TILEDWINDOW
value|WS_OVERLAPPEDWINDOW
endif|#
directive|endif
ifndef|#
directive|ifndef
name|WS_EX_CAPTIONOKBTN
DECL|macro|WS_EX_CAPTIONOKBTN
define|#
directive|define
name|WS_EX_CAPTIONOKBTN
value|0x80000000L
endif|#
directive|endif
ifndef|#
directive|ifndef
name|WS_EX_NODRAG
DECL|macro|WS_EX_NODRAG
define|#
directive|define
name|WS_EX_NODRAG
value|0x40000000L
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_comment
comment|// Extern C.
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_comment
comment|// As Windows CE lacks some standard functions used in Qt, these got
end_comment
begin_comment
comment|// reimplemented. Other projects do this as well. Inline functions are used
end_comment
begin_comment
comment|// that there is a central place to disable functions for newer versions if
end_comment
begin_comment
comment|// they get available. There are no defines used anymore, because this
end_comment
begin_comment
comment|// will break member functions of classes which are called like these
end_comment
begin_comment
comment|// functions. Also inline functions are only supported by C++, so just define
end_comment
begin_comment
comment|// them for C++, as only 3rd party dependencies are C, this is no issue.
end_comment
begin_comment
comment|// The other declarations available in this file are being used per
end_comment
begin_comment
comment|// define inside qplatformdefs.h of the corresponding WinCE mkspec.
end_comment
begin_define
DECL|macro|generate_inline_return_func0
define|#
directive|define
name|generate_inline_return_func0
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|)
define|\
value|inline returntype funcname() \         { \             return qt_wince_##funcname(); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func1
define|#
directive|define
name|generate_inline_return_func1
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|)
define|\
value|inline returntype funcname(param1 p1) \         { \             return qt_wince_##funcname(p1); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func2
define|#
directive|define
name|generate_inline_return_func2
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2) \         { \             return qt_wince_##funcname(p1,  p2); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func3
define|#
directive|define
name|generate_inline_return_func3
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3) \         { \             return qt_wince_##funcname(p1,  p2, p3); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func4
define|#
directive|define
name|generate_inline_return_func4
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4) \         { \             return qt_wince_##funcname(p1,  p2, p3, p4); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func5
define|#
directive|define
name|generate_inline_return_func5
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|,
name|param5
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4, param5 p5) \         { \             return qt_wince_##funcname(p1,  p2, p3, p4, p5); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func6
define|#
directive|define
name|generate_inline_return_func6
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|,
name|param5
parameter_list|,
name|param6
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4, param5 p5, param6 p6) \         { \             return qt_wince_##funcname(p1,  p2, p3, p4, p5, p6); \         }
end_define
begin_define
DECL|macro|generate_inline_return_func7
define|#
directive|define
name|generate_inline_return_func7
parameter_list|(
name|funcname
parameter_list|,
name|returntype
parameter_list|,
name|param1
parameter_list|,
name|param2
parameter_list|,
name|param3
parameter_list|,
name|param4
parameter_list|,
name|param5
parameter_list|,
name|param6
parameter_list|,
name|param7
parameter_list|)
define|\
value|inline returntype funcname(param1 p1, param2 p2, param3 p3, param4 p4, param5 p5, param6 p6, param7 p7) \         { \             return qt_wince_##funcname(p1,  p2, p3, p4, p5, p6, p7); \         }
end_define
begin_typedef
DECL|typedef|StartAdressExFunc
typedef|typedef
name|unsigned
function_decl|(
name|__stdcall
modifier|*
name|StartAdressExFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|StartAdressFunc
typedef|typedef
name|void
function_decl|(
modifier|*
name|StartAdressFunc
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_typedef
DECL|typedef|CompareFunc
typedef|typedef
name|int
function_decl|(
name|__cdecl
modifier|*
name|CompareFunc
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef
begin_macro
name|generate_inline_return_func4
argument_list|(
argument|getenv_s
argument_list|,
argument|errno_t
argument_list|,
argument|size_t *
argument_list|,
argument|char *
argument_list|,
argument|size_t
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_putenv_s
argument_list|,
argument|errno_t
argument_list|,
argument|const char *
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func0
argument_list|(
argument|_getpid
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func1
argument_list|(
argument|time_tToFt
argument_list|,
argument|FILETIME
argument_list|,
argument|time_t
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func0
argument_list|(
argument|_getdrive
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_waccess
argument_list|,
argument|int
argument_list|,
argument|const wchar_t *
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func3
argument_list|(
argument|_wopen
argument_list|,
argument|int
argument_list|,
argument|const wchar_t *
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_fdopen
argument_list|,
argument|FILE *
argument_list|,
argument|int
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|fdopen
argument_list|,
argument|FILE *
argument_list|,
argument|int
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func1
argument_list|(
argument|rewind
argument_list|,
argument|void
argument_list|,
argument|FILE *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func0
argument_list|(
argument|tmpfile
argument_list|,
argument|FILE *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_rename
argument_list|,
argument|int
argument_list|,
argument|const char *
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func1
argument_list|(
argument|_remove
argument_list|,
argument|int
argument_list|,
argument|const char *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func1
argument_list|(
argument|SetErrorMode
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_chmod
argument_list|,
argument|bool
argument_list|,
argument|const char *
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|_wchmod
argument_list|,
argument|bool
argument_list|,
argument|const wchar_t *
argument_list|,
argument|int
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func7
argument_list|(
argument|CreateFileA
argument_list|,
argument|HANDLE
argument_list|,
argument|LPCSTR
argument_list|,
argument|DWORD
argument_list|,
argument|DWORD
argument_list|,
argument|LPSECURITY_ATTRIBUTES
argument_list|,
argument|DWORD
argument_list|,
argument|DWORD
argument_list|,
argument|HANDLE
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func4
argument_list|(
argument|SetWindowOrgEx
argument_list|,
argument|BOOL
argument_list|,
argument|HDC
argument_list|,
argument|int
argument_list|,
argument|int
argument_list|,
argument|LPPOINT
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func2
argument_list|(
argument|calloc
argument_list|,
argument|void *
argument_list|,
argument|size_t
argument_list|,
argument|size_t
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func0
argument_list|(
argument|GetThreadLocale
argument_list|,
argument|DWORD
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func3
argument_list|(
argument|_beginthread
argument_list|,
argument|HANDLE
argument_list|,
argument|StartAdressFunc
argument_list|,
argument|unsigned
argument_list|,
argument|void *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func6
argument_list|(
argument|_beginthreadex
argument_list|,
argument|unsigned long
argument_list|,
argument|void *
argument_list|,
argument|unsigned
argument_list|,
argument|StartAdressExFunc
argument_list|,
argument|void *
argument_list|,
argument|unsigned
argument_list|,
argument|unsigned *
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func1
argument_list|(
argument|_endthreadex
argument_list|,
argument|void
argument_list|,
argument|unsigned
argument_list|)
end_macro
begin_macro
name|generate_inline_return_func5
argument_list|(
argument|bsearch
argument_list|,
argument|void *
argument_list|,
argument|const void *
argument_list|,
argument|const void *
argument_list|,
argument|size_t
argument_list|,
argument|size_t
argument_list|,
argument|CompareFunc
argument_list|)
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//__cplusplus
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINCE
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QFUNCTIONS_WINCE_H
end_comment
end_unit
