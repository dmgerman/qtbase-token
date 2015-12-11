begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the Windows main function of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/*   This file contains the code in the qtmain library for WinRT.   qtmain contains the WinRT startup code and is required for   linking to the Qt DLL.    When a Windows application starts, the WinMain function is   invoked. This WinMain creates the WinRT application   container, which in turn calls the application's main()   entry point within the newly created GUI thread. */
end_comment
begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1900
end_if
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
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// _MSC_VER< 1900
end_comment
begin_extern
extern|extern
literal|"C"
block|{
if|#
directive|if
name|_MSC_VER
operator|<
literal|1900
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
endif|#
directive|endif
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
file|<qfunctions_winrt.h>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
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
begin_include
include|#
directive|include
file|<windows.ui.xaml.h>
end_include
begin_include
include|#
directive|include
file|<windows.ui.xaml.controls.h>
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
name|ApplicationModel
operator|::
name|Activation
namespace|;
end_using
begin_using
using|using
namespace|namespace
name|ABI
operator|::
name|Windows
operator|::
name|ApplicationModel
operator|::
name|Core
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
name|ABI
operator|::
name|Windows
operator|::
name|UI
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
name|CoreApplicationView
modifier|*
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
DECL|class|QActivationEvent
class|class
name|QActivationEvent
super|:
specifier|public
name|QEvent
block|{
public|public:
DECL|function|QActivationEvent
specifier|explicit
name|QActivationEvent
parameter_list|(
name|IInspectable
modifier|*
name|args
parameter_list|)
member_init_list|:
name|QEvent
argument_list|(
name|QEvent
operator|::
name|WinEventAct
argument_list|)
block|{
name|setAccepted
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|args
operator|->
name|AddRef
argument_list|()
expr_stmt|;
name|d
operator|=
cast|reinterpret_cast
argument_list|<
name|QEventPrivate
operator|*
argument_list|>
argument_list|(
name|args
argument_list|)
expr_stmt|;
block|}
DECL|function|~QActivationEvent
name|~
name|QActivationEvent
parameter_list|()
block|{
name|IUnknown
modifier|*
name|args
init|=
cast|reinterpret_cast
argument_list|<
name|IUnknown
operator|*
argument_list|>
argument_list|(
name|d
argument_list|)
decl_stmt|;
name|args
operator|->
name|Release
argument_list|()
expr_stmt|;
name|d
operator|=
literal|nullptr
expr_stmt|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|AppContainer
class|class
name|AppContainer
super|:
specifier|public
name|RuntimeClass
argument_list|<
name|Xaml
operator|::
name|IApplicationOverrides
argument_list|>
block|{
public|public:
DECL|function|AppContainer
name|AppContainer
parameter_list|()
block|{
name|ComPtr
argument_list|<
name|Xaml
operator|::
name|IApplicationFactory
argument_list|>
name|applicationFactory
decl_stmt|;
name|HRESULT
name|hr
init|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_Xaml_Application
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|applicationFactory
argument_list|)
argument_list|)
decl_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|applicationFactory
operator|->
name|CreateInstance
argument_list|(
name|this
argument_list|,
operator|&
name|base
argument_list|,
operator|&
name|core
argument_list|)
expr_stmt|;
name|RETURN_VOID_IF_FAILED
argument_list|(
literal|"Failed to create application container instance"
argument_list|)
expr_stmt|;
name|pidFile
operator|=
name|INVALID_HANDLE_VALUE
expr_stmt|;
block|}
DECL|function|~AppContainer
name|~
name|AppContainer
parameter_list|()
block|{     }
DECL|function|exec
name|int
name|exec
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|args
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
name|args
operator|.
name|append
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|mainThread
operator|=
name|CreateThread
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
capture|[]
parameter_list|(
name|void
modifier|*
name|param
parameter_list|)
lambda|->
name|DWORD
block|{
name|AppContainer
modifier|*
name|app
type|= reinterpret_cast
type|<
name|AppContainer
modifier|*
type|>(
name|param
decl_stmt|);
name|int
name|argc
type|=
name|app
operator|->
name|args
operator|.
name|count
type|(
decl_stmt|);
name|char
modifier|*
modifier|*
name|argv
type|=
name|app
operator|->
name|args
operator|.
name|data
type|(
decl_stmt|);
specifier|const
name|int
name|res
type|= main(
name|argc
decl_stmt|,
name|argv
decl_stmt|);
if|if
condition|(
name|app
operator|->
name|pidFile
operator|!=
name|INVALID_HANDLE_VALUE
condition|)
block|{
specifier|const
name|QByteArray
name|resString
type|=
name|QByteArray
operator|::
name|number
type|(
name|res
decl_stmt|);
name|WriteFile
argument_list|(
name|app
operator|->
name|pidFile
argument_list|,
cast|reinterpret_cast
argument_list|<
name|LPCVOID
argument_list|>
argument_list|(
name|resString
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|,
name|resString
operator|.
name|size
argument_list|()
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|FlushFileBuffers
argument_list|(
name|app
operator|->
name|pidFile
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|app
operator|->
name|pidFile
argument_list|)
expr_stmt|;
block|}
name|app
operator|->
name|core
operator|->
name|Exit
argument_list|()
expr_stmt|;
return|return
name|res
return|;
block|}
argument_list|,
name|this
argument_list|,
name|CREATE_SUSPENDED
argument_list|,
literal|nullptr
argument_list|)
expr_stmt|;
name|HRESULT
name|hr
decl_stmt|;
name|ComPtr
argument_list|<
name|Xaml
operator|::
name|IApplicationStatics
argument_list|>
name|appStatics
decl_stmt|;
name|hr
operator|=
name|RoGetActivationFactory
argument_list|(
name|HString
operator|::
name|MakeReference
argument_list|(
name|RuntimeClass_Windows_UI_Xaml_Application
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|,
name|IID_PPV_ARGS
argument_list|(
operator|&
name|appStatics
argument_list|)
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|hr
operator|=
name|appStatics
operator|->
name|Start
argument_list|(
name|Callback
argument_list|<
name|Xaml
operator|::
name|IApplicationInitializationCallback
argument_list|>
argument_list|(
capture|[]
parameter_list|(
name|Xaml
operator|::
name|IApplicationInitializationCallbackParams
modifier|*
parameter_list|)
block|{
return|return
name|S_OK
return|;
block|}
argument_list|)
operator|.
name|Get
argument_list|()
argument_list|)
expr_stmt|;
name|Q_ASSERT_SUCCEEDED
argument_list|(
name|hr
argument_list|)
expr_stmt|;
name|WaitForSingleObjectEx
argument_list|(
name|mainThread
argument_list|,
name|INFINITE
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
name|DWORD
name|exitCode
decl_stmt|;
name|GetExitCodeThread
argument_list|(
name|mainThread
argument_list|,
operator|&
name|exitCode
argument_list|)
expr_stmt|;
return|return
name|exitCode
return|;
block|}
private|private:
name|HRESULT
name|__stdcall
name|OnActivated
parameter_list|(
name|IActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|QAbstractEventDispatcher
modifier|*
name|dispatcher
init|=
name|QCoreApplication
operator|::
name|eventDispatcher
argument_list|()
decl_stmt|;
if|if
condition|(
name|dispatcher
condition|)
name|QCoreApplication
operator|::
name|postEvent
argument_list|(
name|dispatcher
argument_list|,
operator|new
name|QActivationEvent
argument_list|(
name|args
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnLaunched
parameter_list|(
name|ILaunchActivatedEventArgs
modifier|*
name|launchArgs
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
if|#
directive|if
name|_MSC_VER
operator|>=
literal|1900
name|commandLine
operator|=
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
expr_stmt|;
endif|#
directive|endif
name|HString
name|launchCommandLine
decl_stmt|;
name|launchArgs
operator|->
name|get_Arguments
argument_list|(
name|launchCommandLine
operator|.
name|GetAddressOf
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|launchCommandLine
operator|.
name|IsValid
argument_list|()
condition|)
block|{
name|quint32
name|launchCommandLineLength
decl_stmt|;
specifier|const
name|wchar_t
modifier|*
name|launchCommandLineBuffer
init|=
name|launchCommandLine
operator|.
name|GetRawBuffer
argument_list|(
operator|&
name|launchCommandLineLength
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|commandLine
operator|.
name|isEmpty
argument_list|()
operator|&&
name|launchCommandLineLength
condition|)
name|commandLine
operator|+=
literal|' '
expr_stmt|;
if|if
condition|(
name|launchCommandLineLength
condition|)
name|commandLine
operator|+=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|launchCommandLineBuffer
argument_list|,
name|launchCommandLineLength
argument_list|)
operator|.
name|toUtf8
argument_list|()
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|commandLine
operator|.
name|isEmpty
argument_list|()
condition|)
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
if|if
condition|(
name|args
operator|.
name|count
argument_list|()
operator|>=
literal|2
operator|&&
name|strncmp
argument_list|(
name|args
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|,
literal|"-ServerName:"
argument_list|,
literal|12
argument_list|)
operator|==
literal|0
condition|)
name|args
operator|.
name|remove
argument_list|(
literal|1
argument_list|)
expr_stmt|;
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
name|char
modifier|*
name|arg
decl|,
name|args
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-qdevel"
argument_list|)
operator|==
literal|0
condition|)
name|develMode
operator|=
literal|true
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|arg
argument_list|,
literal|"-qdebug"
argument_list|)
operator|==
literal|0
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
block|}
decl_stmt|;
name|pidFile
operator|=
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
name|GENERIC_READ
operator||
name|GENERIC_WRITE
argument_list|,
name|FILE_SHARE_READ
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
name|ResumeThread
argument_list|(
name|mainThread
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnFileActivated
parameter_list|(
name|IFileActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnSearchActivated
parameter_list|(
name|ISearchActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnShareTargetActivated
parameter_list|(
name|IShareTargetActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnFileOpenPickerActivated
parameter_list|(
name|IFileOpenPickerActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnFileSavePickerActivated
parameter_list|(
name|IFileSavePickerActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnCachedFileUpdaterActivated
parameter_list|(
name|ICachedFileUpdaterActivatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
name|HRESULT
name|__stdcall
name|OnWindowCreated
parameter_list|(
name|Xaml
operator|::
name|IWindowCreatedEventArgs
modifier|*
name|args
parameter_list|)
name|Q_DECL_OVERRIDE
block|{
name|Q_UNUSED
argument_list|(
name|args
argument_list|)
expr_stmt|;
return|return
name|S_OK
return|;
block|}
DECL|member|base
name|ComPtr
argument_list|<
name|Xaml
operator|::
name|IApplicationOverrides
argument_list|>
name|base
decl_stmt|;
DECL|member|core
name|ComPtr
argument_list|<
name|Xaml
operator|::
name|IApplication
argument_list|>
name|core
decl_stmt|;
DECL|member|commandLine
name|QByteArray
name|commandLine
decl_stmt|;
DECL|member|args
name|QVarLengthArray
argument_list|<
name|char
modifier|*
argument_list|>
name|args
decl_stmt|;
DECL|member|mainThread
name|HANDLE
name|mainThread
decl_stmt|;
DECL|member|pidFile
name|HANDLE
name|pidFile
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
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
init|=
literal|0
decl_stmt|,
modifier|*
modifier|*
name|env
init|=
literal|0
decl_stmt|;
if|#
directive|if
name|_MSC_VER
operator|<
literal|1900
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
name|ComPtr
argument_list|<
name|AppContainer
argument_list|>
name|app
init|=
name|Make
argument_list|<
name|AppContainer
argument_list|>
argument_list|()
decl_stmt|;
return|return
name|app
operator|->
name|exec
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function
end_unit
