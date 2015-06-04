begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the Windows main function of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   This file contains the code in the qtmain library for WinRT.   qtmain contains the WinRT startup code and is required for   linking to the Qt DLL.    When a Windows application starts, the WinMain function is   invoked. This WinMain creates the WinRT application   container, which in turn calls the application's main()   entry point within the newly created GUI thread. */
end_comment
begin_include
include|#
directive|include
file|<new.h>
end_include
begin_typedef
typedef|typedef
struct|struct
block|{
DECL|member|newmode
name|int
name|newmode
decl_stmt|;
block|}
DECL|typedef|_startupinfo
name|_startupinfo
typedef|;
end_typedef
begin_extern
extern|extern
literal|"C"
block|{
name|int
name|__getmainargs
parameter_list|(
name|int
modifier|*
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|env
parameter_list|,
name|int
name|expandWildcards
parameter_list|,
name|_startupinfo
modifier|*
name|info
parameter_list|)
function_decl|;
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
block|}
end_extern
begin_include
include|#
directive|include
file|<qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qvector.h>
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qstandardpaths.h>
end_include
begin_include
include|#
directive|include
file|<qthread.h>
end_include
begin_include
include|#
directive|include
file|<wrl.h>
end_include
begin_include
include|#
directive|include
file|<Windows.ApplicationModel.core.h>
end_include
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|Foundation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|Microsoft
operator|::
name|WRL
operator|::
name|Wrappers
namespace|;
end_using
begin_define
DECL|macro|qHString
define|#
directive|define
name|qHString
parameter_list|(
name|x
parameter_list|)
value|Wrappers::HString::MakeReference(x).Get()
end_define
begin_define
DECL|macro|CoreApplicationClass
define|#
directive|define
name|CoreApplicationClass
value|RuntimeClass_Windows_ApplicationModel_Core_CoreApplication
end_define
begin_typedef
DECL|typedef|ActivatedHandler
typedef|typedef
name|ITypedEventHandler
argument_list|<
name|Core
operator|::
name|CoreApplicationView
operator|*
argument_list|,
name|Activation
operator|::
name|IActivatedEventArgs
operator|*
argument_list|>
name|ActivatedHandler
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|g_mainExitCode
specifier|static
name|int
name|g_mainExitCode
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|defaultMessageHandler
specifier|static
name|QtMessageHandler
name|defaultMessageHandler
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|devMessageHandler
specifier|static
name|void
name|devMessageHandler
parameter_list|(
name|QtMsgType
name|type
parameter_list|,
specifier|const
name|QMessageLogContext
modifier|&
name|context
parameter_list|,
specifier|const
name|QString
modifier|&
name|message
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
specifier|static
name|HANDLE
name|shmem
init|=
literal|0
decl_stmt|;
specifier|static
name|HANDLE
name|event
init|=
literal|0
decl_stmt|;
if|if
condition|(
operator|!
name|shmem
condition|)
name|shmem
operator|=
name|CreateFileMappingFromApp
argument_list|(
name|INVALID_HANDLE_VALUE
argument_list|,
name|NULL
argument_list|,
name|PAGE_READWRITE
argument_list|,
literal|4096
argument_list|,
literal|L"qdebug-shmem"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|event
condition|)
name|event
operator|=
name|CreateEventEx
argument_list|(
name|NULL
argument_list|,
literal|L"qdebug-event"
argument_list|,
literal|0
argument_list|,
name|EVENT_ALL_ACCESS
argument_list|)
expr_stmt|;
name|void
modifier|*
name|data
init|=
name|MapViewOfFileFromApp
argument_list|(
name|shmem
argument_list|,
name|FILE_MAP_WRITE
argument_list|,
literal|0
argument_list|,
literal|4096
argument_list|)
decl_stmt|;
name|memset
argument_list|(
name|data
argument_list|,
name|quint32
argument_list|(
name|type
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|)
expr_stmt|;
name|memcpy_s
argument_list|(
cast|static_cast
argument_list|<
name|quint32
operator|*
argument_list|>
argument_list|(
name|data
argument_list|)
operator|+
literal|1
argument_list|,
literal|4096
operator|-
sizeof|sizeof
argument_list|(
name|quint32
argument_list|)
argument_list|,
name|message
operator|.
name|data
argument_list|()
argument_list|,
operator|(
name|message
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
argument_list|)
expr_stmt|;
name|UnmapViewOfFile
argument_list|(
name|data
argument_list|)
expr_stmt|;
name|SetEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// !Q_OS_WINPHONE
name|defaultMessageHandler
argument_list|(
name|type
argument_list|,
name|context
argument_list|,
name|message
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|AppContainer
class|class
name|AppContainer
super|:
specifier|public
name|Microsoft
operator|::
name|WRL
operator|::
name|RuntimeClass
argument_list|<
name|Core
operator|::
name|IFrameworkView
argument_list|>
block|{
public|public:
DECL|function|AppContainer
name|AppContainer
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
member_init_list|:
name|m_argc
argument_list|(
name|argc
argument_list|)
member_init_list|,
name|m_deleteArgv0
argument_list|(
literal|false
argument_list|)
block|{
name|m_argv
operator|.
name|reserve
argument_list|(
name|argc
argument_list|)
expr_stmt|;
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
block|{
comment|// Workaround for empty argv[0] which occurs when WMAppManifest's ImageParams is used
comment|// The second argument is taken to be the executable
if|if
condition|(
name|i
operator|==
literal|0
operator|&&
name|argc
operator|>=
literal|2
operator|&&
operator|!
name|qstrlen
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
specifier|const
name|QByteArray
name|argv0
init|=
name|QDir
operator|::
name|current
argument_list|()
operator|.
name|absoluteFilePath
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
argument_list|)
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|m_argv
operator|.
name|append
argument_list|(
name|qstrdup
argument_list|(
name|argv0
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|m_argc
operator|-=
literal|1
expr_stmt|;
name|m_deleteArgv0
operator|=
literal|true
expr_stmt|;
operator|++
name|i
expr_stmt|;
continue|continue;
block|}
name|m_argv
operator|.
name|append
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
DECL|function|~AppContainer
name|~
name|AppContainer
parameter_list|()
block|{
if|if
condition|(
name|m_deleteArgv0
condition|)
operator|delete
index|[]
name|m_argv
index|[
literal|0
index|]
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
name|m_argc
init|;
name|i
operator|<
name|m_argv
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
operator|delete
index|[]
name|m_argv
index|[
name|i
index|]
expr_stmt|;
block|}
comment|// IFrameworkView Methods
DECL|function|Initialize
name|HRESULT
name|__stdcall
name|Initialize
parameter_list|(
name|Core
operator|::
name|ICoreApplicationView
modifier|*
name|view
parameter_list|)
block|{
name|view
operator|->
name|add_Activated
argument_list|(
name|Callback
argument_list|<
name|ActivatedHandler
argument_list|>
argument_list|(
name|this
argument_list|,
operator|&
name|AppContainer
operator|::
name|onActivated
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
operator|&
name|m_activationToken
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|SetWindow
name|HRESULT
name|__stdcall
name|SetWindow
parameter_list|(
name|ABI
operator|::
name|Windows
operator|::
name|UI
operator|::
name|Core
operator|::
name|ICoreWindow
modifier|*
parameter_list|)
block|{
return|return
name|S_OK
return|;
block|}
DECL|function|Load
name|HRESULT
name|__stdcall
name|Load
parameter_list|(
name|HSTRING
parameter_list|)
block|{
return|return
name|S_OK
return|;
block|}
DECL|function|Run
name|HRESULT
name|__stdcall
name|Run
parameter_list|()
block|{
name|bool
name|develMode
init|=
literal|false
decl_stmt|;
name|bool
name|debugWait
init|=
literal|false
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|arg
decl|,
name|m_argv
control|)
block|{
if|if
condition|(
name|arg
operator|==
literal|"-qdevel"
condition|)
name|develMode
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|arg
operator|==
literal|"-qdebug"
condition|)
name|debugWait
operator|=
literal|true
expr_stmt|;
block|}
if|if
condition|(
name|develMode
condition|)
block|{
comment|// Write a PID file to help runner
specifier|const
name|QString
name|pidFileName
init|=
name|QDir
argument_list|(
name|QStandardPaths
operator|::
name|writableLocation
argument_list|(
name|QStandardPaths
operator|::
name|DataLocation
argument_list|)
argument_list|)
operator|.
name|absoluteFilePath
argument_list|(
name|QString
operator|::
name|number
argument_list|(
name|uint
argument_list|(
name|GetCurrentProcessId
argument_list|()
argument_list|)
argument_list|)
operator|+
name|QStringLiteral
argument_list|(
literal|".pid"
argument_list|)
argument_list|)
decl_stmt|;
name|CREATEFILE2_EXTENDED_PARAMETERS
name|params
init|=
block|{
sizeof|sizeof
argument_list|(
name|CREATEFILE2_EXTENDED_PARAMETERS
argument_list|)
block|,
name|FILE_ATTRIBUTE_NORMAL
block|,
name|FILE_FLAG_DELETE_ON_CLOSE
block|}
decl_stmt|;
comment|// (Unused) handle will automatically be closed when the app exits
name|CreateFile2
argument_list|(
cast|reinterpret_cast
argument_list|<
name|LPCWSTR
argument_list|>
argument_list|(
name|pidFileName
operator|.
name|utf16
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|,
name|FILE_SHARE_READ
operator||
name|FILE_SHARE_DELETE
argument_list|,
name|CREATE_ALWAYS
argument_list|,
operator|&
name|params
argument_list|)
expr_stmt|;
comment|// Install the develMode message handler
ifndef|#
directive|ifndef
name|Q_OS_WINPHONE
name|defaultMessageHandler
operator|=
name|qInstallMessageHandler
argument_list|(
name|devMessageHandler
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|// Wait for debugger before continuing
if|if
condition|(
name|debugWait
condition|)
block|{
while|while
condition|(
operator|!
name|IsDebuggerPresent
argument_list|()
condition|)
name|WaitForSingleObjectEx
argument_list|(
name|GetCurrentThread
argument_list|()
argument_list|,
literal|1
argument_list|,
literal|true
argument_list|)
expr_stmt|;
block|}
name|g_mainExitCode
operator|=
name|main
argument_list|(
name|m_argv
operator|.
name|count
argument_list|()
argument_list|,
name|m_argv
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|function|Uninitialize
name|HRESULT
name|__stdcall
name|Uninitialize
parameter_list|()
block|{
return|return
name|S_OK
return|;
block|}
private|private:
comment|// Activation handler
DECL|function|onActivated
name|HRESULT
name|onActivated
parameter_list|(
name|Core
operator|::
name|ICoreApplicationView
modifier|*
parameter_list|,
name|Activation
operator|::
name|IActivatedEventArgs
modifier|*
name|args
parameter_list|)
block|{
name|Activation
operator|::
name|ILaunchActivatedEventArgs
modifier|*
name|launchArgs
decl_stmt|;
if|if
condition|(
name|SUCCEEDED
argument_list|(
name|args
operator|->
name|QueryInterface
argument_list|(
operator|&
name|launchArgs
argument_list|)
argument_list|)
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
name|m_argc
init|;
name|i
operator|<
name|m_argv
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
operator|delete
index|[]
name|m_argv
index|[
name|i
index|]
expr_stmt|;
name|m_argv
operator|.
name|resize
argument_list|(
name|m_argc
argument_list|)
expr_stmt|;
name|HString
name|arguments
decl_stmt|;
name|launchArgs
operator|->
name|get_Arguments
argument_list|(
name|arguments
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|arguments
operator|.
name|IsValid
argument_list|()
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QByteArray
modifier|&
name|arg
decl|,
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|arguments
operator|.
name|GetRawBuffer
argument_list|(
literal|nullptr
argument_list|)
argument_list|)
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
control|)
block|{
name|m_argv
operator|.
name|append
argument_list|(
name|qstrdup
argument_list|(
name|arg
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
return|return
name|S_OK
return|;
block|}
DECL|member|m_argc
name|int
name|m_argc
decl_stmt|;
DECL|member|m_argv
name|QVector
argument_list|<
name|char
modifier|*
argument_list|>
name|m_argv
decl_stmt|;
DECL|member|m_deleteArgv0
name|bool
name|m_deleteArgv0
decl_stmt|;
DECL|member|m_activationToken
name|EventRegistrationToken
name|m_activationToken
decl_stmt|;
block|}
class|;
end_class
begin_class
DECL|class|AppViewSource
class|class
name|AppViewSource
super|:
specifier|public
name|Microsoft
operator|::
name|WRL
operator|::
name|RuntimeClass
argument_list|<
name|Core
operator|::
name|IFrameworkViewSource
argument_list|>
block|{
public|public:
DECL|function|AppViewSource
name|AppViewSource
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
member_init_list|:
name|m_argc
argument_list|(
name|argc
argument_list|)
member_init_list|,
name|m_argv
argument_list|(
name|argv
argument_list|)
block|{ }
DECL|function|CreateView
name|HRESULT
name|__stdcall
name|CreateView
parameter_list|(
name|Core
operator|::
name|IFrameworkView
modifier|*
modifier|*
name|frameworkView
parameter_list|)
block|{
return|return
operator|(
operator|*
name|frameworkView
operator|=
name|Make
argument_list|<
name|AppContainer
argument_list|>
argument_list|(
name|m_argc
argument_list|,
name|m_argv
argument_list|)
operator|.
name|Detach
argument_list|()
operator|)
condition|?
name|S_OK
else|:
name|E_OUTOFMEMORY
return|;
block|}
private|private:
DECL|member|m_argc
name|int
name|m_argc
decl_stmt|;
DECL|member|m_argv
name|char
modifier|*
modifier|*
name|m_argv
decl_stmt|;
block|}
class|;
end_class
begin_comment
comment|// Main entry point for Appx containers
end_comment
begin_function
DECL|function|WinMain
name|int
name|__stdcall
name|WinMain
parameter_list|(
name|HINSTANCE
parameter_list|,
name|HINSTANCE
parameter_list|,
name|LPSTR
parameter_list|,
name|int
parameter_list|)
block|{
if|#
directive|if
name|_MSC_VER
operator|<
literal|1900
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|,
modifier|*
modifier|*
name|env
decl_stmt|;
name|_startupinfo
name|info
init|=
block|{
name|_query_new_mode
argument_list|()
block|}
decl_stmt|;
if|if
condition|(
name|int
name|init
init|=
name|__getmainargs
argument_list|(
operator|&
name|argc
argument_list|,
operator|&
name|argv
argument_list|,
operator|&
name|env
argument_list|,
literal|false
argument_list|,
operator|&
name|info
argument_list|)
condition|)
return|return
name|init
return|;
else|#
directive|else
name|QByteArray
name|commandLine
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|GetCommandLine
argument_list|()
argument_list|)
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
name|QVarLengthArray
argument_list|<
name|char
modifier|*
argument_list|>
name|args
decl_stmt|;
name|args
operator|.
name|append
argument_list|(
name|commandLine
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|bool
name|quote
init|=
literal|false
decl_stmt|;
name|bool
name|escape
init|=
literal|false
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
name|commandLine
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
switch|switch
condition|(
name|commandLine
operator|.
name|at
argument_list|(
name|i
argument_list|)
condition|)
block|{
case|case
literal|'\\'
case|:
name|escape
operator|=
literal|true
expr_stmt|;
break|break;
case|case
literal|'"'
case|:
if|if
condition|(
name|escape
condition|)
block|{
name|escape
operator|=
literal|false
expr_stmt|;
break|break;
block|}
name|quote
operator|=
operator|!
name|quote
expr_stmt|;
name|commandLine
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
break|break;
case|case
literal|' '
case|:
if|if
condition|(
name|quote
condition|)
break|break;
name|commandLine
index|[
name|i
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|args
operator|.
name|last
argument_list|()
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|args
operator|.
name|append
argument_list|(
name|commandLine
operator|.
name|data
argument_list|()
operator|+
name|i
operator|+
literal|1
argument_list|)
expr_stmt|;
comment|// fall through
default|default:
if|if
condition|(
name|args
operator|.
name|last
argument_list|()
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|args
operator|.
name|last
argument_list|()
operator|=
name|commandLine
operator|.
name|data
argument_list|()
operator|+
name|i
expr_stmt|;
name|escape
operator|=
literal|false
expr_stmt|;
comment|// only quotes are escaped
break|break;
block|}
block|}
name|int
name|argc
init|=
name|args
operator|.
name|size
argument_list|()
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
init|=
name|args
operator|.
name|data
argument_list|()
decl_stmt|;
name|char
modifier|*
modifier|*
name|env
init|=
name|Q_NULLPTR
decl_stmt|;
endif|#
directive|endif
comment|// _MSC_VER>= 1900
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|env
operator|&&
name|env
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|var
argument_list|(
name|env
index|[
name|i
index|]
argument_list|)
decl_stmt|;
name|int
name|split
init|=
name|var
operator|.
name|indexOf
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|split
operator|>
literal|0
condition|)
name|qputenv
argument_list|(
name|var
operator|.
name|mid
argument_list|(
literal|0
argument_list|,
name|split
argument_list|)
argument_list|,
name|var
operator|.
name|mid
argument_list|(
name|split
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|FAILED
argument_list|(
name|RoInitialize
argument_list|(
name|RO_INIT_MULTITHREADED
argument_list|)
argument_list|)
condition|)
return|return
literal|1
return|;
comment|// Mark the main thread
name|QThread
operator|::
name|currentThread
argument_list|()
expr_stmt|;
name|Core
operator|::
name|ICoreApplication
modifier|*
name|appFactory
decl_stmt|;
if|if
condition|(
name|FAILED
argument_list|(
name|RoGetActivationFactory
argument_list|(
name|qHString
argument_list|(
name|CoreApplicationClass
argument_list|)
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|appFactory
argument_list|)
argument_list|)
argument_list|)
condition|)
return|return
literal|2
return|;
name|appFactory
operator|->
name|Run
argument_list|(
name|Make
argument_list|<
name|AppViewSource
argument_list|>
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|g_mainExitCode
return|;
block|}
end_function
end_unit
