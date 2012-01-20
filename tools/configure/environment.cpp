begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"environment.h"
end_include
begin_include
include|#
directive|include
file|<process.h>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QMap>
end_include
begin_include
include|#
directive|include
file|<QDir>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QFileInfo>
end_include
begin_comment
comment|//#define CONFIGURE_DEBUG_EXECUTE
end_comment
begin_comment
comment|//#define CONFIGURE_DEBUG_CP_DIR
end_comment
begin_using
using|using
namespace|namespace
name|std
namespace|;
end_using
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN32
end_ifdef
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<windows/registry_p.h>
end_include
begin_comment
comment|// from tools/shared
end_comment
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|CompilerInfo
struct|struct
name|CompilerInfo
block|{
DECL|member|compiler
name|Compiler
name|compiler
decl_stmt|;
DECL|member|compilerStr
specifier|const
name|char
modifier|*
name|compilerStr
decl_stmt|;
DECL|member|regKey
specifier|const
name|char
modifier|*
name|regKey
decl_stmt|;
DECL|member|executable
specifier|const
name|char
modifier|*
name|executable
decl_stmt|;
block|}
DECL|variable|compiler_info
name|compiler_info
index|[]
init|=
block|{
comment|// The compilers here are sorted in a reversed-preferred order
block|{
name|CC_BORLAND
block|,
literal|"Borland C++"
block|,
literal|0
block|,
literal|"bcc32.exe"
block|}
block|,
block|{
name|CC_MINGW
block|,
literal|"MinGW (Minimalist GNU for Windows)"
block|,
literal|0
block|,
literal|"g++.exe"
block|}
block|,
block|{
name|CC_INTEL
block|,
literal|"Intel(R) C++ Compiler for 32-bit applications"
block|,
literal|0
block|,
literal|"icl.exe"
block|}
block|,
comment|// xilink.exe, xilink5.exe, xilink6.exe, xilib.exe
block|{
name|CC_NET2003
block|,
literal|"Microsoft (R) 32-bit C/C++ Optimizing Compiler.NET 2003 (7.1)"
block|,
literal|"Software\\Microsoft\\VisualStudio\\7.1\\Setup\\VC\\ProductDir"
block|,
literal|"cl.exe"
block|}
block|,
comment|// link.exe, lib.exe
block|{
name|CC_NET2005
block|,
literal|"Microsoft (R) 32-bit C/C++ Optimizing Compiler.NET 2005 (8.0)"
block|,
literal|"Software\\Microsoft\\VisualStudio\\SxS\\VC7\\8.0"
block|,
literal|"cl.exe"
block|}
block|,
comment|// link.exe, lib.exe
block|{
name|CC_NET2008
block|,
literal|"Microsoft (R) 32-bit C/C++ Optimizing Compiler.NET 2008 (9.0)"
block|,
literal|"Software\\Microsoft\\VisualStudio\\SxS\\VC7\\9.0"
block|,
literal|"cl.exe"
block|}
block|,
comment|// link.exe, lib.exe
block|{
name|CC_NET2010
block|,
literal|"Microsoft (R) 32-bit C/C++ Optimizing Compiler.NET 2010 (10.0)"
block|,
literal|"Software\\Microsoft\\VisualStudio\\SxS\\VC7\\10.0"
block|,
literal|"cl.exe"
block|}
block|,
comment|// link.exe, lib.exe
block|{
name|CC_UNKNOWN
block|,
literal|"Unknown"
block|,
literal|0
block|,
literal|0
block|}
block|, }
struct|;
end_struct
begin_comment
comment|// Initialize static variables
end_comment
begin_decl_stmt
DECL|member|detectedCompiler
name|Compiler
name|Environment
operator|::
name|detectedCompiler
init|=
name|CC_UNKNOWN
decl_stmt|;
end_decl_stmt
begin_comment
comment|/*!     Returns the pointer to the CompilerInfo for a \a compiler. */
end_comment
begin_function
DECL|function|compilerInfo
name|CompilerInfo
modifier|*
name|Environment
operator|::
name|compilerInfo
parameter_list|(
name|Compiler
name|compiler
parameter_list|)
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|compiler_info
index|[
name|i
index|]
operator|.
name|compiler
operator|!=
name|compiler
operator|&&
name|compiler_info
index|[
name|i
index|]
operator|.
name|compiler
operator|!=
name|CC_UNKNOWN
condition|)
operator|++
name|i
expr_stmt|;
return|return
operator|&
operator|(
name|compiler_info
index|[
name|i
index|]
operator|)
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the qmakespec for the compiler detected on the system. */
end_comment
begin_function
DECL|function|detectQMakeSpec
name|QString
name|Environment
operator|::
name|detectQMakeSpec
parameter_list|()
block|{
name|QString
name|spec
decl_stmt|;
switch|switch
condition|(
name|detectCompiler
argument_list|()
condition|)
block|{
case|case
name|CC_NET2010
case|:
name|spec
operator|=
literal|"win32-msvc2010"
expr_stmt|;
break|break;
case|case
name|CC_NET2008
case|:
name|spec
operator|=
literal|"win32-msvc2008"
expr_stmt|;
break|break;
case|case
name|CC_NET2005
case|:
name|spec
operator|=
literal|"win32-msvc2005"
expr_stmt|;
break|break;
case|case
name|CC_NET2003
case|:
name|spec
operator|=
literal|"win32-msvc2003"
expr_stmt|;
break|break;
case|case
name|CC_INTEL
case|:
name|spec
operator|=
literal|"win32-icc"
expr_stmt|;
break|break;
case|case
name|CC_MINGW
case|:
name|spec
operator|=
literal|"win32-g++"
expr_stmt|;
break|break;
case|case
name|CC_BORLAND
case|:
name|spec
operator|=
literal|"win32-borland"
expr_stmt|;
break|break;
default|default:
break|break;
block|}
return|return
name|spec
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the enum of the compiler which was detected on the system.     The compilers are detected in the order as entered into the     compiler_info list.      If more than one compiler is found, CC_UNKNOWN is returned. */
end_comment
begin_function
DECL|function|detectCompiler
name|Compiler
name|Environment
operator|::
name|detectCompiler
parameter_list|()
block|{
ifndef|#
directive|ifndef
name|Q_OS_WIN32
return|return
name|CC_UNKNOWN
return|;
comment|// Always generate CC_UNKNOWN on other platforms
else|#
directive|else
if|if
condition|(
name|detectedCompiler
operator|!=
name|CC_UNKNOWN
condition|)
return|return
name|detectedCompiler
return|;
name|int
name|installed
init|=
literal|0
decl_stmt|;
comment|// Check for compilers in registry first, to see which version is in PATH
name|QString
name|paths
init|=
name|qgetenv
argument_list|(
literal|"PATH"
argument_list|)
decl_stmt|;
name|QStringList
name|pathlist
init|=
name|paths
operator|.
name|toLower
argument_list|()
operator|.
name|split
argument_list|(
literal|";"
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|compiler_info
index|[
name|i
index|]
operator|.
name|compiler
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|productPath
init|=
name|qt_readRegistryKey
argument_list|(
name|HKEY_LOCAL_MACHINE
argument_list|,
name|compiler_info
index|[
name|i
index|]
operator|.
name|regKey
argument_list|)
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|productPath
operator|.
name|length
argument_list|()
condition|)
block|{
name|QStringList
operator|::
name|iterator
name|it
decl_stmt|;
for|for
control|(
name|it
operator|=
name|pathlist
operator|.
name|begin
argument_list|()
init|;
name|it
operator|!=
name|pathlist
operator|.
name|end
argument_list|()
condition|;
operator|++
name|it
control|)
block|{
if|if
condition|(
operator|(
operator|*
name|it
operator|)
operator|.
name|contains
argument_list|(
name|productPath
argument_list|)
condition|)
block|{
operator|++
name|installed
expr_stmt|;
name|detectedCompiler
operator|=
name|compiler_info
index|[
name|i
index|]
operator|.
name|compiler
expr_stmt|;
break|break;
block|}
block|}
block|}
block|}
comment|// Now just go looking for the executables, and accept any executable as the lowest version
if|if
condition|(
operator|!
name|installed
condition|)
block|{
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|compiler_info
index|[
name|i
index|]
operator|.
name|compiler
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|executable
init|=
name|QString
argument_list|(
name|compiler_info
index|[
name|i
index|]
operator|.
name|executable
argument_list|)
operator|.
name|toLower
argument_list|()
decl_stmt|;
if|if
condition|(
name|executable
operator|.
name|length
argument_list|()
operator|&&
name|Environment
operator|::
name|detectExecutable
argument_list|(
name|executable
argument_list|)
condition|)
block|{
operator|++
name|installed
expr_stmt|;
name|detectedCompiler
operator|=
name|compiler_info
index|[
name|i
index|]
operator|.
name|compiler
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|installed
operator|>
literal|1
condition|)
block|{
name|cout
operator|<<
literal|"Found more than one known compiler! Using \""
operator|<<
name|compilerInfo
argument_list|(
name|detectedCompiler
argument_list|)
operator|->
name|compilerStr
operator|<<
literal|"\""
operator|<<
name|endl
expr_stmt|;
name|detectedCompiler
operator|=
name|CC_UNKNOWN
expr_stmt|;
block|}
return|return
name|detectedCompiler
return|;
endif|#
directive|endif
block|}
end_function
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_comment
comment|/*!     Returns true if the \a executable could be loaded, else false.     This means that the executable either is in the current directory     or in the PATH. */
end_comment
begin_function
DECL|function|detectExecutable
name|bool
name|Environment
operator|::
name|detectExecutable
parameter_list|(
specifier|const
name|QString
modifier|&
name|executable
parameter_list|)
block|{
name|PROCESS_INFORMATION
name|procInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|procInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|procInfo
argument_list|)
argument_list|)
expr_stmt|;
name|STARTUPINFO
name|startInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|startInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|startInfo
argument_list|)
argument_list|)
expr_stmt|;
name|startInfo
operator|.
name|cb
operator|=
sizeof|sizeof
argument_list|(
name|startInfo
argument_list|)
expr_stmt|;
name|bool
name|couldExecute
init|=
name|CreateProcess
argument_list|(
literal|0
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|executable
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|false
argument_list|,
name|CREATE_NO_WINDOW
operator||
name|CREATE_SUSPENDED
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|&
name|startInfo
argument_list|,
operator|&
name|procInfo
argument_list|)
decl_stmt|;
if|if
condition|(
name|couldExecute
condition|)
block|{
name|CloseHandle
argument_list|(
name|procInfo
operator|.
name|hThread
argument_list|)
expr_stmt|;
name|TerminateProcess
argument_list|(
name|procInfo
operator|.
name|hProcess
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|procInfo
operator|.
name|hProcess
argument_list|)
expr_stmt|;
block|}
return|return
name|couldExecute
return|;
block|}
end_function
begin_comment
comment|/*!     Creates a commandling from \a program and it \a arguments,     escaping characters that needs it. */
end_comment
begin_function
DECL|function|qt_create_commandline
specifier|static
name|QString
name|qt_create_commandline
parameter_list|(
specifier|const
name|QString
modifier|&
name|program
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|arguments
parameter_list|)
block|{
name|QString
name|programName
init|=
name|program
decl_stmt|;
if|if
condition|(
operator|!
name|programName
operator|.
name|startsWith
argument_list|(
literal|"\""
argument_list|)
operator|&&
operator|!
name|programName
operator|.
name|endsWith
argument_list|(
literal|"\""
argument_list|)
operator|&&
name|programName
operator|.
name|contains
argument_list|(
literal|" "
argument_list|)
condition|)
name|programName
operator|=
literal|"\""
operator|+
name|programName
operator|+
literal|"\""
expr_stmt|;
name|programName
operator|.
name|replace
argument_list|(
literal|"/"
argument_list|,
literal|"\\"
argument_list|)
expr_stmt|;
name|QString
name|args
decl_stmt|;
comment|// add the prgram as the first arrg ... it works better
name|args
operator|=
name|programName
operator|+
literal|" "
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
name|arguments
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|tmp
init|=
name|arguments
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// in the case of \" already being in the string the \ must also be escaped
name|tmp
operator|.
name|replace
argument_list|(
literal|"\\\""
argument_list|,
literal|"\\\\\""
argument_list|)
expr_stmt|;
comment|// escape a single " because the arguments will be parsed
name|tmp
operator|.
name|replace
argument_list|(
literal|"\""
argument_list|,
literal|"\\\""
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|.
name|isEmpty
argument_list|()
operator|||
name|tmp
operator|.
name|contains
argument_list|(
literal|' '
argument_list|)
operator|||
name|tmp
operator|.
name|contains
argument_list|(
literal|'\t'
argument_list|)
condition|)
block|{
comment|// The argument must not end with a \ since this would be interpreted
comment|// as escaping the quote -- rather put the \ behind the quote: e.g.
comment|// rather use "foo"\ than "foo\"
name|QString
name|endQuote
argument_list|(
literal|"\""
argument_list|)
decl_stmt|;
name|int
name|i
init|=
name|tmp
operator|.
name|length
argument_list|()
decl_stmt|;
while|while
condition|(
name|i
operator|>
literal|0
operator|&&
name|tmp
operator|.
name|at
argument_list|(
name|i
operator|-
literal|1
argument_list|)
operator|==
literal|'\\'
condition|)
block|{
operator|--
name|i
expr_stmt|;
name|endQuote
operator|+=
literal|"\\"
expr_stmt|;
block|}
name|args
operator|+=
name|QString
argument_list|(
literal|" \""
argument_list|)
operator|+
name|tmp
operator|.
name|left
argument_list|(
name|i
argument_list|)
operator|+
name|endQuote
expr_stmt|;
block|}
else|else
block|{
name|args
operator|+=
literal|' '
operator|+
name|tmp
expr_stmt|;
block|}
block|}
return|return
name|args
return|;
block|}
end_function
begin_comment
comment|/*!     Creates a QByteArray of the \a environment. */
end_comment
begin_function
DECL|function|qt_create_environment
specifier|static
name|QByteArray
name|qt_create_environment
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|environment
parameter_list|)
block|{
name|QByteArray
name|envlist
decl_stmt|;
if|if
condition|(
name|environment
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|envlist
return|;
name|int
name|pos
init|=
literal|0
decl_stmt|;
comment|// add PATH if necessary (for DLL loading)
name|QByteArray
name|path
init|=
name|qgetenv
argument_list|(
literal|"PATH"
argument_list|)
decl_stmt|;
if|if
condition|(
name|environment
operator|.
name|filter
argument_list|(
name|QRegExp
argument_list|(
literal|"^PATH="
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|!
name|path
operator|.
name|isNull
argument_list|()
condition|)
block|{
name|QString
name|tmp
init|=
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"PATH=%1"
argument_list|)
argument_list|)
operator|.
name|arg
argument_list|(
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|)
argument_list|)
decl_stmt|;
name|uint
name|tmpSize
init|=
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|*
operator|(
name|tmp
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|)
decl_stmt|;
name|envlist
operator|.
name|resize
argument_list|(
name|envlist
operator|.
name|size
argument_list|()
operator|+
name|tmpSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|envlist
operator|.
name|data
argument_list|()
operator|+
name|pos
argument_list|,
name|tmp
operator|.
name|utf16
argument_list|()
argument_list|,
name|tmpSize
argument_list|)
expr_stmt|;
name|pos
operator|+=
name|tmpSize
expr_stmt|;
block|}
comment|// add the user environment
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|tmp
decl|,
name|environment
control|)
block|{
name|uint
name|tmpSize
init|=
sizeof|sizeof
argument_list|(
name|wchar_t
argument_list|)
operator|*
operator|(
name|tmp
operator|.
name|length
argument_list|()
operator|+
literal|1
operator|)
decl_stmt|;
name|envlist
operator|.
name|resize
argument_list|(
name|envlist
operator|.
name|size
argument_list|()
operator|+
name|tmpSize
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|envlist
operator|.
name|data
argument_list|()
operator|+
name|pos
argument_list|,
name|tmp
operator|.
name|utf16
argument_list|()
argument_list|,
name|tmpSize
argument_list|)
expr_stmt|;
name|pos
operator|+=
name|tmpSize
expr_stmt|;
block|}
comment|// add the 2 terminating 0 (actually 4, just to be on the safe side)
name|envlist
operator|.
name|resize
argument_list|(
name|envlist
operator|.
name|size
argument_list|()
operator|+
literal|4
argument_list|)
expr_stmt|;
name|envlist
index|[
name|pos
operator|++
index|]
operator|=
literal|0
expr_stmt|;
name|envlist
index|[
name|pos
operator|++
index|]
operator|=
literal|0
expr_stmt|;
name|envlist
index|[
name|pos
operator|++
index|]
operator|=
literal|0
expr_stmt|;
name|envlist
index|[
name|pos
operator|++
index|]
operator|=
literal|0
expr_stmt|;
return|return
name|envlist
return|;
block|}
end_function
begin_comment
comment|/*!     Executes the command described in \a arguments, in the     environment inherited from the parent process, with the     \a additionalEnv settings applied.     \a removeEnv removes the specified environment variables from     the environment of the executed process.      Returns the exit value of the process, or -1 if the command could     not be executed.      This function uses _(w)spawnvpe to spawn a process by searching     through the PATH environment variable. */
end_comment
begin_function
DECL|function|execute
name|int
name|Environment
operator|::
name|execute
parameter_list|(
name|QStringList
name|arguments
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|additionalEnv
parameter_list|,
specifier|const
name|QStringList
modifier|&
name|removeEnv
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|CONFIGURE_DEBUG_EXECUTE
name|qDebug
argument_list|()
operator|<<
literal|"About to Execute: "
operator|<<
name|arguments
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"   "
operator|<<
name|QDir
operator|::
name|currentPath
argument_list|()
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"   "
operator|<<
name|additionalEnv
expr_stmt|;
name|qDebug
argument_list|()
operator|<<
literal|"   "
operator|<<
name|removeEnv
expr_stmt|;
endif|#
directive|endif
comment|// Create the full environment from the current environment and
comment|// the additionalEnv strings, then remove all variables defined
comment|// in removeEnv
name|QMap
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|fullEnvMap
decl_stmt|;
name|LPWSTR
name|envStrings
init|=
name|GetEnvironmentStrings
argument_list|()
decl_stmt|;
if|if
condition|(
name|envStrings
condition|)
block|{
name|int
name|strLen
init|=
literal|0
decl_stmt|;
for|for
control|(
name|LPWSTR
name|envString
init|=
name|envStrings
init|;
operator|*
operator|(
name|envString
operator|)
condition|;
name|envString
operator|+=
name|strLen
operator|+
literal|1
control|)
block|{
name|strLen
operator|=
name|wcslen
argument_list|(
name|envString
argument_list|)
expr_stmt|;
name|QString
name|str
init|=
name|QString
argument_list|(
operator|(
specifier|const
name|QChar
operator|*
operator|)
name|envString
argument_list|,
name|strLen
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|str
operator|.
name|startsWith
argument_list|(
literal|"="
argument_list|)
condition|)
block|{
comment|// These are added by the system
name|int
name|sepIndex
init|=
name|str
operator|.
name|indexOf
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
name|fullEnvMap
operator|.
name|insert
argument_list|(
name|str
operator|.
name|left
argument_list|(
name|sepIndex
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|,
name|str
operator|.
name|mid
argument_list|(
name|sepIndex
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|FreeEnvironmentStrings
argument_list|(
name|envStrings
argument_list|)
expr_stmt|;
comment|// Add additionalEnv variables
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|additionalEnv
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
modifier|&
name|str
init|=
name|additionalEnv
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|int
name|sepIndex
init|=
name|str
operator|.
name|indexOf
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
name|fullEnvMap
operator|.
name|insert
argument_list|(
name|str
operator|.
name|left
argument_list|(
name|sepIndex
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|,
name|str
operator|.
name|mid
argument_list|(
name|sepIndex
operator|+
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Remove removeEnv variables
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|<
name|removeEnv
operator|.
name|count
argument_list|()
condition|;
operator|++
name|j
control|)
name|fullEnvMap
operator|.
name|remove
argument_list|(
name|removeEnv
operator|.
name|at
argument_list|(
name|j
argument_list|)
operator|.
name|toUpper
argument_list|()
argument_list|)
expr_stmt|;
comment|// Add all variables to a QStringList
name|QStringList
name|fullEnv
decl_stmt|;
name|QMapIterator
argument_list|<
name|QString
argument_list|,
name|QString
argument_list|>
name|it
argument_list|(
name|fullEnvMap
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
name|fullEnv
operator|+=
name|QString
argument_list|(
name|it
operator|.
name|key
argument_list|()
operator|+
literal|"="
operator|+
name|it
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|// ----------------------------
name|QString
name|program
init|=
name|arguments
operator|.
name|takeAt
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QString
name|args
init|=
name|qt_create_commandline
argument_list|(
name|program
argument_list|,
name|arguments
argument_list|)
decl_stmt|;
name|QByteArray
name|envlist
init|=
name|qt_create_environment
argument_list|(
name|fullEnv
argument_list|)
decl_stmt|;
name|DWORD
name|exitCode
init|=
name|DWORD
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
name|PROCESS_INFORMATION
name|procInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|procInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|procInfo
argument_list|)
argument_list|)
expr_stmt|;
name|STARTUPINFO
name|startInfo
decl_stmt|;
name|memset
argument_list|(
operator|&
name|startInfo
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|startInfo
argument_list|)
argument_list|)
expr_stmt|;
name|startInfo
operator|.
name|cb
operator|=
sizeof|sizeof
argument_list|(
name|startInfo
argument_list|)
expr_stmt|;
name|bool
name|couldExecute
init|=
name|CreateProcess
argument_list|(
literal|0
argument_list|,
operator|(
name|wchar_t
operator|*
operator|)
name|args
operator|.
name|utf16
argument_list|()
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|true
argument_list|,
name|CREATE_UNICODE_ENVIRONMENT
argument_list|,
name|envlist
operator|.
name|isEmpty
argument_list|()
condition|?
literal|0
else|:
name|envlist
operator|.
name|data
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|&
name|startInfo
argument_list|,
operator|&
name|procInfo
argument_list|)
decl_stmt|;
if|if
condition|(
name|couldExecute
condition|)
block|{
name|WaitForSingleObject
argument_list|(
name|procInfo
operator|.
name|hProcess
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
name|GetExitCodeProcess
argument_list|(
name|procInfo
operator|.
name|hProcess
argument_list|,
operator|&
name|exitCode
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|procInfo
operator|.
name|hThread
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|procInfo
operator|.
name|hProcess
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|exitCode
operator|==
name|DWORD
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
block|{
switch|switch
condition|(
name|GetLastError
argument_list|()
condition|)
block|{
case|case
name|E2BIG
case|:
name|cerr
operator|<<
literal|"execute: Argument list exceeds 1024 bytes"
operator|<<
name|endl
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|arguments
control|)
name|cerr
operator|<<
literal|"   ("
operator|<<
name|arg
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
literal|")"
operator|<<
name|endl
expr_stmt|;
break|break;
case|case
name|ENOENT
case|:
name|cerr
operator|<<
literal|"execute: File or path is not found ("
operator|<<
name|program
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
literal|")"
operator|<<
name|endl
expr_stmt|;
break|break;
case|case
name|ENOEXEC
case|:
name|cerr
operator|<<
literal|"execute: Specified file is not executable or has invalid executable-file format ("
operator|<<
name|program
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
literal|")"
operator|<<
name|endl
expr_stmt|;
break|break;
case|case
name|ENOMEM
case|:
name|cerr
operator|<<
literal|"execute: Not enough memory is available to execute new process."
operator|<<
name|endl
expr_stmt|;
break|break;
default|default:
name|cerr
operator|<<
literal|"execute: Unknown error"
operator|<<
name|endl
expr_stmt|;
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|arg
decl|,
name|arguments
control|)
name|cerr
operator|<<
literal|"   ("
operator|<<
name|arg
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
operator|<<
literal|")"
operator|<<
name|endl
expr_stmt|;
break|break;
block|}
block|}
return|return
name|exitCode
return|;
block|}
end_function
begin_comment
comment|/*!     Copies the \a srcDir contents into \a destDir.      If \a includeSrcDir is not empty, any files with 'h', 'prf', or 'conf' suffixes     will not be copied over from \a srcDir. Instead a new file will be created     in \a destDir with the same name and that file will include a file with the     same name from the \a includeSrcDir using relative path and appropriate     syntax for the file type.      Returns true if copying was successful. */
end_comment
begin_function
DECL|function|cpdir
name|bool
name|Environment
operator|::
name|cpdir
parameter_list|(
specifier|const
name|QString
modifier|&
name|srcDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|destDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|includeSrcDir
parameter_list|)
block|{
name|QString
name|cleanSrcName
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|srcDir
argument_list|)
decl_stmt|;
name|QString
name|cleanDstName
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|destDir
argument_list|)
decl_stmt|;
name|QString
name|cleanIncludeName
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|includeSrcDir
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIGURE_DEBUG_CP_DIR
name|qDebug
argument_list|()
operator|<<
literal|"Attempt to cpdir "
operator|<<
name|cleanSrcName
operator|<<
literal|"->"
operator|<<
name|cleanDstName
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|QFile
operator|::
name|exists
argument_list|(
name|cleanDstName
argument_list|)
operator|&&
operator|!
name|QDir
argument_list|()
operator|.
name|mkpath
argument_list|(
name|cleanDstName
argument_list|)
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"cpdir: Failure to create "
operator|<<
name|cleanDstName
expr_stmt|;
return|return
literal|false
return|;
block|}
name|bool
name|result
init|=
literal|true
decl_stmt|;
name|QDir
name|dir
init|=
name|QDir
argument_list|(
name|cleanSrcName
argument_list|)
decl_stmt|;
name|QDir
name|destinationDir
init|=
name|QDir
argument_list|(
name|cleanDstName
argument_list|)
decl_stmt|;
name|QFileInfoList
name|allEntries
init|=
name|dir
operator|.
name|entryInfoList
argument_list|(
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|result
operator|&&
operator|(
name|i
operator|<
name|allEntries
operator|.
name|count
argument_list|()
operator|)
condition|;
operator|++
name|i
control|)
block|{
name|QFileInfo
name|entry
init|=
name|allEntries
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|bool
name|intermediate
init|=
literal|true
decl_stmt|;
if|if
condition|(
name|entry
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|QString
name|newIncSrcDir
decl_stmt|;
if|if
condition|(
operator|!
name|includeSrcDir
operator|.
name|isEmpty
argument_list|()
condition|)
name|newIncSrcDir
operator|=
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|cleanIncludeName
argument_list|)
operator|.
name|arg
argument_list|(
name|entry
operator|.
name|fileName
argument_list|()
argument_list|)
expr_stmt|;
name|intermediate
operator|=
name|cpdir
argument_list|(
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|cleanSrcName
argument_list|)
operator|.
name|arg
argument_list|(
name|entry
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|cleanDstName
argument_list|)
operator|.
name|arg
argument_list|(
name|entry
operator|.
name|fileName
argument_list|()
argument_list|)
argument_list|,
name|newIncSrcDir
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QString
name|destFile
init|=
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|cleanDstName
argument_list|)
operator|.
name|arg
argument_list|(
name|entry
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|CONFIGURE_DEBUG_CP_DIR
name|qDebug
argument_list|()
operator|<<
literal|"About to cp (file)"
operator|<<
name|entry
operator|.
name|absoluteFilePath
argument_list|()
operator|<<
literal|"->"
operator|<<
name|destFile
expr_stmt|;
endif|#
directive|endif
name|QFile
operator|::
name|remove
argument_list|(
name|destFile
argument_list|)
expr_stmt|;
name|QString
name|suffix
init|=
name|entry
operator|.
name|suffix
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|includeSrcDir
operator|.
name|isEmpty
argument_list|()
operator|&&
operator|(
name|suffix
operator|==
literal|"prf"
operator|||
name|suffix
operator|==
literal|"conf"
operator|||
name|suffix
operator|==
literal|"h"
operator|)
condition|)
block|{
name|QString
name|relativeIncludeFilePath
init|=
name|QString
argument_list|(
literal|"%1/%2"
argument_list|)
operator|.
name|arg
argument_list|(
name|cleanIncludeName
argument_list|)
operator|.
name|arg
argument_list|(
name|entry
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|relativeIncludeFilePath
operator|=
name|destinationDir
operator|.
name|relativeFilePath
argument_list|(
name|relativeIncludeFilePath
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|CONFIGURE_DEBUG_CP_DIR
name|qDebug
argument_list|()
operator|<<
literal|"...instead generate relative include to"
operator|<<
name|relativeIncludeFilePath
expr_stmt|;
endif|#
directive|endif
name|QFile
name|currentFile
argument_list|(
name|destFile
argument_list|)
decl_stmt|;
if|if
condition|(
name|currentFile
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|QTextStream
name|fileStream
decl_stmt|;
name|fileStream
operator|.
name|setDevice
argument_list|(
operator|&
name|currentFile
argument_list|)
expr_stmt|;
if|if
condition|(
name|suffix
operator|==
literal|"prf"
operator|||
name|suffix
operator|==
literal|"conf"
condition|)
block|{
if|if
condition|(
name|entry
operator|.
name|fileName
argument_list|()
operator|==
literal|"qmake.conf"
condition|)
block|{
comment|// While QMAKESPEC_ORIGINAL being relative or absolute doesn't matter for the
comment|// primary use of this variable by qmake to identify the original mkspec, the
comment|// variable is also used for few special cases where the absolute path is required.
comment|// Conversely, the include of the original qmake.conf must be done using relative path,
comment|// as some Qt binary deployments are done in a manner that doesn't allow for patching
comment|// the paths at the installation time.
name|fileStream
operator|<<
literal|"QMAKESPEC_ORIGINAL="
operator|<<
name|cleanSrcName
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
name|fileStream
operator|<<
literal|"include("
operator|<<
name|relativeIncludeFilePath
operator|<<
literal|")"
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|suffix
operator|==
literal|"h"
condition|)
block|{
name|fileStream
operator|<<
literal|"#include \""
operator|<<
name|relativeIncludeFilePath
operator|<<
literal|"\""
operator|<<
name|endl
operator|<<
name|endl
expr_stmt|;
block|}
name|fileStream
operator|.
name|flush
argument_list|()
expr_stmt|;
name|currentFile
operator|.
name|close
argument_list|()
expr_stmt|;
block|}
block|}
else|else
block|{
name|intermediate
operator|=
name|QFile
operator|::
name|copy
argument_list|(
name|entry
operator|.
name|absoluteFilePath
argument_list|()
argument_list|,
name|destFile
argument_list|)
expr_stmt|;
name|SetFileAttributes
argument_list|(
operator|(
name|wchar_t
operator|*
operator|)
name|destFile
operator|.
name|utf16
argument_list|()
argument_list|,
name|FILE_ATTRIBUTE_NORMAL
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|intermediate
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"cpdir: Failure for "
operator|<<
name|entry
operator|.
name|fileName
argument_list|()
operator|<<
name|entry
operator|.
name|isDir
argument_list|()
expr_stmt|;
name|result
operator|=
literal|false
expr_stmt|;
block|}
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|rmdir
name|bool
name|Environment
operator|::
name|rmdir
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|bool
name|result
init|=
literal|true
decl_stmt|;
name|QString
name|cleanName
init|=
name|QDir
operator|::
name|cleanPath
argument_list|(
name|name
argument_list|)
decl_stmt|;
name|QDir
name|dir
init|=
name|QDir
argument_list|(
name|cleanName
argument_list|)
decl_stmt|;
name|QFileInfoList
name|allEntries
init|=
name|dir
operator|.
name|entryInfoList
argument_list|(
name|QDir
operator|::
name|AllDirs
operator||
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|result
operator|&&
operator|(
name|i
operator|<
name|allEntries
operator|.
name|count
argument_list|()
operator|)
condition|;
operator|++
name|i
control|)
block|{
name|QFileInfo
name|entry
init|=
name|allEntries
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|entry
operator|.
name|isDir
argument_list|()
condition|)
block|{
name|result
operator|&=
name|rmdir
argument_list|(
name|entry
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|result
operator|&=
name|QFile
operator|::
name|remove
argument_list|(
name|entry
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
expr_stmt|;
block|}
block|}
name|result
operator|&=
name|dir
operator|.
name|rmdir
argument_list|(
name|cleanName
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
