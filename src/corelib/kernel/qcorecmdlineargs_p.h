begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCORECMDLINEARGS_P_H
end_ifndef
begin_define
DECL|macro|QCORECMDLINEARGS_P_H
define|#
directive|define
name|QCORECMDLINEARGS_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|"QtCore/qstring.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
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
begin_comment
comment|// first to suppress min, max macros.
end_comment
begin_include
include|#
directive|include
file|<shlobj.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|"QtCore/qvector.h"
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_function
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
DECL|function|qWinCmdArgs
specifier|static
specifier|inline
name|QStringList
name|qWinCmdArgs
parameter_list|(
specifier|const
name|QString
modifier|&
name|cmdLine
parameter_list|)
block|{
name|QStringList
name|result
decl_stmt|;
name|int
name|size
decl_stmt|;
if|if
condition|(
name|wchar_t
modifier|*
modifier|*
name|argv
init|=
name|CommandLineToArgvW
argument_list|(
operator|(
specifier|const
name|wchar_t
operator|*
operator|)
name|cmdLine
operator|.
name|utf16
argument_list|()
argument_list|,
operator|&
name|size
argument_list|)
condition|)
block|{
name|result
operator|.
name|reserve
argument_list|(
name|size
argument_list|)
expr_stmt|;
name|wchar_t
modifier|*
modifier|*
name|argvEnd
init|=
name|argv
operator|+
name|size
decl_stmt|;
for|for
control|(
name|wchar_t
modifier|*
modifier|*
name|a
init|=
name|argv
init|;
name|a
operator|<
name|argvEnd
condition|;
operator|++
name|a
control|)
name|result
operator|.
name|append
argument_list|(
name|QString
operator|::
name|fromWCharArray
argument_list|(
operator|*
name|a
argument_list|)
argument_list|)
expr_stmt|;
name|LocalFree
argument_list|(
name|argv
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_elif
begin_comment
comment|// Q_OS_WIN32
end_comment
begin_comment
comment|// template implementation of the parsing algorithm
end_comment
begin_comment
comment|// this is used from qcoreapplication_win.cpp and the tools (rcc, uic...)
end_comment
begin_expr_stmt
name|template
operator|<
name|typename
name|Char
operator|>
specifier|static
name|QVector
operator|<
name|Char
operator|*
operator|>
name|qWinCmdLine
argument_list|(
argument|Char *cmdParam
argument_list|,
argument|int length
argument_list|,
argument|int&argc
argument_list|)
block|{
name|QVector
operator|<
name|Char
operator|*
operator|>
name|argv
argument_list|(
literal|8
argument_list|)
block|;
name|Char
operator|*
name|p
operator|=
name|cmdParam
block|;
name|Char
operator|*
name|p_end
operator|=
name|p
operator|+
name|length
block|;
name|argc
operator|=
literal|0
block|;
while|while
condition|(
operator|*
name|p
operator|&&
name|p
operator|<
name|p_end
condition|)
block|{
comment|// parse cmd line arguments
while|while
condition|(
name|QChar
argument_list|(
call|(
name|short
call|)
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
operator|.
name|isSpace
argument_list|()
condition|)
comment|// skip white space
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|&&
name|p
operator|<
name|p_end
condition|)
block|{
comment|// arg starts
name|int
name|quote
decl_stmt|;
name|Char
modifier|*
name|start
decl_stmt|,
modifier|*
name|r
decl_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
name|Char
argument_list|(
literal|'\"'
argument_list|)
condition|)
block|{
name|quote
operator|=
operator|*
name|p
expr_stmt|;
name|start
operator|=
operator|++
name|p
expr_stmt|;
block|}
end_expr_stmt
begin_else
else|else
block|{
name|quote
operator|=
literal|0
expr_stmt|;
name|start
operator|=
name|p
expr_stmt|;
block|}
end_else
begin_expr_stmt
name|r
operator|=
name|start
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
operator|*
name|p
operator|&&
name|p
operator|<
name|p_end
condition|)
block|{
if|if
condition|(
name|quote
condition|)
block|{
if|if
condition|(
operator|*
name|p
operator|==
name|quote
condition|)
block|{
name|p
operator|++
expr_stmt|;
if|if
condition|(
name|QChar
argument_list|(
call|(
name|short
call|)
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
operator|.
name|isSpace
argument_list|()
condition|)
break|break;
name|quote
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|*
name|p
operator|==
literal|'\\'
condition|)
block|{
comment|// escape char?
comment|// testing by looking at argc, argv shows that it only escapes quotes
if|if
condition|(
name|p
operator|<
name|p_end
operator|&&
operator|(
operator|*
operator|(
name|p
operator|+
literal|1
operator|)
operator|==
name|Char
argument_list|(
literal|'\"'
argument_list|)
operator|)
condition|)
name|p
operator|++
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|quote
operator|&&
operator|(
operator|*
name|p
operator|==
name|Char
argument_list|(
literal|'\"'
argument_list|)
operator|)
condition|)
block|{
name|quote
operator|=
operator|*
name|p
operator|++
expr_stmt|;
continue|continue;
block|}
elseif|else
if|if
condition|(
name|QChar
argument_list|(
call|(
name|short
call|)
argument_list|(
operator|*
name|p
argument_list|)
argument_list|)
operator|.
name|isSpace
argument_list|()
operator|&&
operator|!
name|quote
condition|)
break|break;
block|}
if|if
condition|(
operator|*
name|p
condition|)
operator|*
name|r
operator|++
operator|=
operator|*
name|p
operator|++
expr_stmt|;
block|}
end_while
begin_if
if|if
condition|(
operator|*
name|p
operator|&&
name|p
operator|<
name|p_end
condition|)
name|p
operator|++
expr_stmt|;
end_if
begin_expr_stmt
operator|*
name|r
operator|=
name|Char
argument_list|(
literal|'\0'
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|argc
operator|>=
operator|(
name|int
operator|)
name|argv
operator|.
name|size
argument_list|()
operator|-
literal|1
condition|)
comment|// expand array
name|argv
operator|.
name|resize
argument_list|(
name|argv
operator|.
name|size
argument_list|()
operator|*
literal|2
argument_list|)
expr_stmt|;
end_if
begin_expr_stmt
name|argv
index|[
name|argc
operator|++
index|]
operator|=
name|start
expr_stmt|;
end_expr_stmt
begin_expr_stmt
unit|}     }
name|argv
index|[
name|argc
index|]
operator|=
literal|0
expr_stmt|;
end_expr_stmt
begin_return
return|return
name|argv
return|;
end_return
begin_function
unit|}  static
specifier|inline
name|QStringList
name|qWinCmdArgs
parameter_list|(
name|QString
name|cmdLine
parameter_list|)
comment|// not const-ref: this might be modified
block|{
name|QStringList
name|args
decl_stmt|;
name|int
name|argc
init|=
literal|0
decl_stmt|;
name|QVector
operator|<
name|wchar_t
operator|*
operator|>
name|argv
operator|=
name|qWinCmdLine
operator|<
name|wchar_t
operator|>
operator|(
operator|(
name|wchar_t
operator|*
operator|)
name|cmdLine
operator|.
name|utf16
argument_list|()
operator|,
name|cmdLine
operator|.
name|length
argument_list|()
operator|,
name|argc
operator|)
expr_stmt|;
for|for
control|(
name|int
name|a
init|=
literal|0
init|;
name|a
operator|<
name|argc
condition|;
operator|++
name|a
control|)
block|{
name|args
operator|<<
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|argv
index|[
name|a
index|]
argument_list|)
expr_stmt|;
block|}
return|return
name|args
return|;
block|}
end_function
begin_function
specifier|static
specifier|inline
name|QStringList
name|qCmdLineArgs
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|argc
argument_list|)
name|Q_UNUSED
argument_list|(
argument|argv
argument_list|)
name|QString
name|cmdLine
init|=
name|QString
operator|::
name|fromWCharArray
argument_list|(
name|GetCommandLine
argument_list|()
argument_list|)
decl_stmt|;
return|return
name|qWinCmdArgs
argument_list|(
name|cmdLine
argument_list|)
return|;
block|}
end_function
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_WINRT
argument_list|)
end_elif
begin_comment
comment|// Q_OS_WINCE
end_comment
begin_function
specifier|static
specifier|inline
name|QStringList
name|qCmdLineArgs
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|QStringList
name|args
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|argc
condition|;
operator|++
name|i
control|)
name|args
operator|+=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
return|return
name|args
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WINRT
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// Q_OS_WIN
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCORECMDLINEARGS_WIN_P_H
end_comment
end_unit
