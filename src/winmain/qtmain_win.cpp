begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the Windows main function of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qt_windows.h"
end_include
begin_include
include|#
directive|include
file|"qbytearray.h"
end_include
begin_include
include|#
directive|include
file|"qstring.h"
end_include
begin_include
include|#
directive|include
file|"qvector.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_include
include|#
directive|include
file|<shlobj.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/*   This file contains the code in the qtmain library for Windows.   qtmain contains the Windows startup code and is required for   linking to the Qt DLL.    When a Windows application starts, the WinMain function is   invoked. WinMain calls qWinMain in the Qt DLL/library, which   initializes Qt. */
end_comment
begin_function_decl
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
specifier|extern
name|void
name|__cdecl
name|qWinMain
parameter_list|(
name|HINSTANCE
parameter_list|,
name|HINSTANCE
parameter_list|,
name|LPSTR
parameter_list|,
name|int
parameter_list|,
name|int
modifier|&
parameter_list|,
name|QVector
argument_list|<
name|char
modifier|*
argument_list|>
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_else
else|#
directive|else
end_else
begin_function_decl
specifier|extern
name|void
name|qWinMain
parameter_list|(
name|HINSTANCE
parameter_list|,
name|HINSTANCE
parameter_list|,
name|LPSTR
parameter_list|,
name|int
parameter_list|,
name|int
modifier|&
parameter_list|,
name|QVector
argument_list|<
name|char
modifier|*
argument_list|>
modifier|&
parameter_list|)
function_decl|;
end_function_decl
begin_endif
endif|#
directive|endif
end_endif
begin_function_decl
name|QT_END_NAMESPACE
name|QT_USE_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|QT_NEEDS_QMAIN
argument_list|)
name|int
name|qMain
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl
begin_define
DECL|macro|main
define|#
directive|define
name|main
value|qMain
end_define
begin_else
else|#
directive|else
end_else
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_extern
extern|extern
literal|"C"
name|int
name|__cdecl
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_extern
begin_else
else|#
directive|else
end_else
begin_extern
extern|extern
literal|"C"
name|int
name|main
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
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
comment|/*   WinMain() - Initializes Windows and calls user's startup function main().   NOTE: WinMain() won't be called if the application was linked as a "console"   application. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|Q_OS_WINCE
end_ifndef
begin_comment
comment|// Convert a wchar_t to char string, equivalent to QString::toLocal8Bit()
end_comment
begin_comment
comment|// when passed CP_ACP.
end_comment
begin_function
DECL|function|wideToMulti
specifier|static
specifier|inline
name|char
modifier|*
name|wideToMulti
parameter_list|(
name|int
name|codePage
parameter_list|,
specifier|const
name|wchar_t
modifier|*
name|aw
parameter_list|)
block|{
specifier|const
name|int
name|required
init|=
name|WideCharToMultiByte
argument_list|(
name|codePage
argument_list|,
literal|0
argument_list|,
name|aw
argument_list|,
operator|-
literal|1
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
decl_stmt|;
name|char
modifier|*
name|result
init|=
operator|new
name|char
index|[
name|required
index|]
decl_stmt|;
name|WideCharToMultiByte
argument_list|(
name|codePage
argument_list|,
literal|0
argument_list|,
name|aw
argument_list|,
operator|-
literal|1
argument_list|,
name|result
argument_list|,
name|required
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_extern
DECL|function|WinMain
extern|extern
literal|"C"
name|int
name|APIENTRY
name|WinMain
parameter_list|(
name|HINSTANCE
parameter_list|,
name|HINSTANCE
parameter_list|,
name|LPSTR
comment|/*cmdParamarg*/
parameter_list|,
name|int
comment|/* cmdShow */
parameter_list|)
block|{
name|int
name|argc
decl_stmt|;
name|wchar_t
modifier|*
modifier|*
name|argvW
init|=
name|CommandLineToArgvW
argument_list|(
name|GetCommandLineW
argument_list|()
argument_list|,
operator|&
name|argc
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|argvW
condition|)
return|return
operator|-
literal|1
return|;
name|char
modifier|*
modifier|*
name|argv
init|=
operator|new
name|char
operator|*
index|[
name|argc
operator|+
literal|1
index|]
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
name|argv
index|[
name|i
index|]
operator|=
name|wideToMulti
argument_list|(
name|CP_ACP
argument_list|,
name|argvW
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|argv
index|[
name|argc
index|]
operator|=
name|Q_NULLPTR
expr_stmt|;
name|LocalFree
argument_list|(
name|argvW
argument_list|)
expr_stmt|;
specifier|const
name|int
name|exitCode
init|=
name|main
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
operator|delete
index|[]
name|argv
index|[
name|i
index|]
expr_stmt|;
operator|delete
index|[]
name|argv
expr_stmt|;
return|return
name|exitCode
return|;
block|}
end_extern
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !Q_OS_WINCE
end_comment
begin_function
DECL|function|WinMain
name|int
name|WINAPI
name|WinMain
parameter_list|(
name|HINSTANCE
name|instance
parameter_list|,
name|HINSTANCE
name|prevInstance
parameter_list|,
name|LPWSTR
comment|/*wCmdParam*/
parameter_list|,
name|int
name|cmdShow
parameter_list|)
block|{
name|QByteArray
name|cmdParam
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|GetCommandLine
argument_list|()
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|wchar_t
name|appName
index|[
name|MAX_PATH
index|]
decl_stmt|;
name|GetModuleFileName
argument_list|(
literal|0
argument_list|,
name|appName
argument_list|,
name|MAX_PATH
argument_list|)
expr_stmt|;
name|cmdParam
operator|.
name|prepend
argument_list|(
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"\"%1\" "
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|appName
argument_list|)
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|QVector
argument_list|<
name|char
modifier|*
argument_list|>
name|argv
argument_list|(
literal|8
argument_list|)
decl_stmt|;
name|qWinMain
argument_list|(
name|instance
argument_list|,
name|prevInstance
argument_list|,
name|cmdParam
operator|.
name|data
argument_list|()
argument_list|,
name|cmdShow
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|wchar_t
name|uniqueAppID
index|[
name|MAX_PATH
index|]
decl_stmt|;
name|GetModuleFileName
argument_list|(
literal|0
argument_list|,
name|uniqueAppID
argument_list|,
name|MAX_PATH
argument_list|)
expr_stmt|;
name|QString
name|uid
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|uniqueAppID
argument_list|)
operator|.
name|toLower
argument_list|()
operator|.
name|replace
argument_list|(
name|QLatin1String
argument_list|(
literal|"\\"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"_"
argument_list|)
argument_list|)
decl_stmt|;
comment|// If there exists an other instance of this application
comment|// it will be the owner of a mutex with the unique ID.
name|HANDLE
name|mutex
init|=
name|CreateMutex
argument_list|(
name|NULL
argument_list|,
name|TRUE
argument_list|,
operator|(
name|LPCWSTR
operator|)
name|uid
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|mutex
operator|&&
name|ERROR_ALREADY_EXISTS
operator|==
name|GetLastError
argument_list|()
condition|)
block|{
name|CloseHandle
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
comment|// The app is already running, so we use the unique
comment|// ID to create a unique messageNo, which is used
comment|// as the registered class name for the windows
comment|// created. Set the first instance's window to the
comment|// foreground, else just terminate.
comment|// Use bitwise 0x01 OR to reactivate window state if
comment|// it was hidden
name|UINT
name|msgNo
init|=
name|RegisterWindowMessage
argument_list|(
operator|(
name|LPCWSTR
operator|)
name|uid
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
name|HWND
name|aHwnd
init|=
name|FindWindow
argument_list|(
operator|(
name|LPCWSTR
operator|)
name|QString
operator|::
name|number
argument_list|(
name|msgNo
argument_list|)
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|)
decl_stmt|;
if|if
condition|(
name|aHwnd
condition|)
name|SetForegroundWindow
argument_list|(
call|(
name|HWND
call|)
argument_list|(
operator|(
operator|(
name|ULONG
operator|)
name|aHwnd
operator|)
operator||
literal|0x01
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|int
name|result
init|=
name|main
argument_list|(
name|argc
argument_list|,
name|argv
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
name|CloseHandle
argument_list|(
name|mutex
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINCE
end_comment
end_unit
