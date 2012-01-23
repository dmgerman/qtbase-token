begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|"QtCore/qvector.h"
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
include|#
directive|include
file|"qt_windows.h"
endif|#
directive|endif
name|QT_END_INCLUDE_NAMESPACE
comment|// template implementation of the parsing algorithm
comment|// this is used from qcoreapplication_win.cpp and the tools (rcc, uic...)
name|template
operator|<
name|typename
name|Char
operator|>
DECL|function|qWinCmdLine
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
operator|||
operator|*
name|p
operator|==
name|Char
argument_list|(
literal|'\''
argument_list|)
condition|)
block|{
comment|// " or ' quote
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
name|p
operator|++
expr_stmt|;
if|if
condition|(
operator|*
name|p
operator|==
name|Char
argument_list|(
literal|'\"'
argument_list|)
operator|||
operator|*
name|p
operator|==
name|Char
argument_list|(
literal|'\''
argument_list|)
condition|)
empty_stmt|;
comment|// yes
else|else
name|p
operator|--
expr_stmt|;
comment|// treat \ literally
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
operator|||
operator|*
name|p
operator|==
name|Char
argument_list|(
literal|'\''
argument_list|)
operator|)
condition|)
block|{
comment|// " or ' quote
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
begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
end_if
begin_function
unit|static
DECL|function|qWinCmdArgs
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
DECL|function|qCmdLineArgs
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
begin_endif
endif|#
directive|endif
end_endif
begin_else
else|#
directive|else
end_else
begin_comment
comment|// !Q_OS_WIN
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
comment|// Q_OS_WIN
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCORECMDLINEARGS_WIN_P_H
end_comment
end_unit
