begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the qmake application of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"ioutils.h"
end_include
begin_include
include|#
directive|include
file|<qdir.h>
end_include
begin_include
include|#
directive|include
file|<qfile.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WIN
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_else
else|#
directive|else
end_else
begin_include
include|#
directive|include
file|<sys/types.h>
end_include
begin_include
include|#
directive|include
file|<sys/stat.h>
end_include
begin_include
include|#
directive|include
file|<unistd.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_using
using|using
namespace|namespace
name|QMakeInternal
namespace|;
end_using
begin_function
DECL|function|fileType
name|IoUtils
operator|::
name|FileType
name|IoUtils
operator|::
name|fileType
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|fileName
operator|.
name|isEmpty
argument_list|()
operator|||
name|isAbsolutePath
argument_list|(
name|fileName
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|DWORD
name|attr
init|=
name|GetFileAttributesW
argument_list|(
operator|(
name|WCHAR
operator|*
operator|)
name|fileName
operator|.
name|utf16
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|attr
operator|==
name|INVALID_FILE_ATTRIBUTES
condition|)
return|return
name|FileNotFound
return|;
return|return
operator|(
name|attr
operator|&
name|FILE_ATTRIBUTE_DIRECTORY
operator|)
condition|?
name|FileIsDir
else|:
name|FileIsRegular
return|;
else|#
directive|else
name|struct
operator|::
name|stat
name|st
decl_stmt|;
if|if
condition|(
operator|::
name|stat
argument_list|(
name|fileName
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|,
operator|&
name|st
argument_list|)
condition|)
return|return
name|FileNotFound
return|;
return|return
name|S_ISDIR
argument_list|(
name|st
operator|.
name|st_mode
argument_list|)
condition|?
name|FileIsDir
else|:
name|FileIsRegular
return|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|isRelativePath
name|bool
name|IoUtils
operator|::
name|isRelativePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|path
parameter_list|)
block|{
if|if
condition|(
name|path
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
if|if
condition|(
name|path
operator|.
name|startsWith
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
condition|)
return|return
literal|false
return|;
comment|// Unlike QFileInfo, this won't accept a relative path with a drive letter.
comment|// Such paths result in a royal mess anyway ...
if|if
condition|(
name|path
operator|.
name|length
argument_list|()
operator|>=
literal|3
operator|&&
name|path
operator|.
name|at
argument_list|(
literal|1
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|':'
argument_list|)
operator|&&
name|path
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|.
name|isLetter
argument_list|()
operator|&&
operator|(
name|path
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|||
name|path
operator|.
name|at
argument_list|(
literal|2
argument_list|)
operator|==
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
operator|)
condition|)
return|return
literal|false
return|;
endif|#
directive|endif
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|pathName
name|QStringRef
name|IoUtils
operator|::
name|pathName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|fileName
operator|.
name|leftRef
argument_list|(
name|fileName
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|fileName
name|QStringRef
name|IoUtils
operator|::
name|fileName
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
return|return
name|fileName
operator|.
name|midRef
argument_list|(
name|fileName
operator|.
name|lastIndexOf
argument_list|(
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
argument_list|)
operator|+
literal|1
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|resolvePath
name|QString
name|IoUtils
operator|::
name|resolvePath
parameter_list|(
specifier|const
name|QString
modifier|&
name|baseDir
parameter_list|,
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
if|if
condition|(
name|fileName
operator|.
name|isEmpty
argument_list|()
condition|)
return|return
name|QString
argument_list|()
return|;
if|if
condition|(
name|isAbsolutePath
argument_list|(
name|fileName
argument_list|)
condition|)
return|return
name|QDir
operator|::
name|cleanPath
argument_list|(
name|fileName
argument_list|)
return|;
return|return
name|QDir
operator|::
name|cleanPath
argument_list|(
name|baseDir
operator|+
name|QLatin1Char
argument_list|(
literal|'/'
argument_list|)
operator|+
name|fileName
argument_list|)
return|;
block|}
end_function
begin_decl_stmt
specifier|inline
specifier|static
DECL|function|isSpecialChar
name|bool
name|isSpecialChar
argument_list|(
name|ushort
name|c
argument_list|,
specifier|const
name|uchar
argument_list|(
operator|&
name|iqm
argument_list|)
index|[
literal|16
index|]
argument_list|)
argument_list|{     if
operator|(
operator|(
name|c
operator|<
sizeof|sizeof
argument_list|(
name|iqm
argument_list|)
operator|*
literal|8
operator|)
operator|&&
operator|(
name|iqm
index|[
name|c
operator|/
literal|8
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|c
operator|&
literal|7
operator|)
operator|)
operator|)
operator|)
return|return
literal|true
return|;
end_decl_stmt
begin_return
return|return
literal|false
return|;
end_return
begin_decl_stmt
unit|}  inline
specifier|static
DECL|function|hasSpecialChars
name|bool
name|hasSpecialChars
argument_list|(
specifier|const
name|QString
operator|&
name|arg
argument_list|,
specifier|const
name|uchar
argument_list|(
operator|&
name|iqm
argument_list|)
index|[
literal|16
index|]
argument_list|)
argument_list|{     for
operator|(
name|int
name|x
operator|=
name|arg
operator|.
name|length
argument_list|()
operator|-
literal|1
expr|;
name|x
operator|>=
literal|0
expr|;
operator|--
name|x
operator|)
block|{
if|if
condition|(
name|isSpecialChar
argument_list|(
name|arg
operator|.
name|unicode
argument_list|()
index|[
name|x
index|]
operator|.
name|unicode
argument_list|()
argument_list|,
name|iqm
argument_list|)
condition|)
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
end_decl_stmt
begin_macro
unit|}  QString
DECL|function|shellQuoteUnix
name|IoUtils
end_macro
begin_expr_stmt
DECL|function|shellQuoteUnix
operator|::
name|shellQuoteUnix
operator|(
specifier|const
name|QString
operator|&
name|arg
operator|)
block|{
comment|// Chars that should be quoted (TM). This includes:
specifier|static
specifier|const
name|uchar
name|iqm
index|[]
operator|=
block|{
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xdf
block|,
literal|0x07
block|,
literal|0x00
block|,
literal|0xd8
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x38
block|,
literal|0x01
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x78
block|}
block|;
comment|// 0-32 \'"$`<>|;&(){}*?#!~[]
if|if
condition|(
operator|!
name|arg
operator|.
name|length
argument_list|()
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"''"
argument_list|)
return|;
name|QString
name|ret
argument_list|(
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|hasSpecialChars
argument_list|(
name|ret
argument_list|,
name|iqm
argument_list|)
condition|)
block|{
name|ret
operator|.
name|replace
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\''
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"'\\''"
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\''
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'\''
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_if
begin_return
return|return
name|ret
return|;
end_return
begin_macro
unit|}  QString
DECL|function|shellQuoteWin
name|IoUtils
end_macro
begin_expr_stmt
DECL|function|shellQuoteWin
operator|::
name|shellQuoteWin
operator|(
specifier|const
name|QString
operator|&
name|arg
operator|)
block|{
comment|// Chars that should be quoted (TM). This includes:
comment|// - control chars& space
comment|// - the shell meta chars "&()<>^|
comment|// - the potential separators ,;=
specifier|static
specifier|const
name|uchar
name|iqm
index|[]
operator|=
block|{
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0xff
block|,
literal|0x45
block|,
literal|0x13
block|,
literal|0x00
block|,
literal|0x78
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x40
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|}
block|;
comment|// Shell meta chars that need escaping.
specifier|static
specifier|const
name|uchar
name|ism
index|[]
operator|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x40
block|,
literal|0x03
block|,
literal|0x00
block|,
literal|0x50
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x40
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x10
block|}
block|;
comment|//&()<>^|
if|if
condition|(
operator|!
name|arg
operator|.
name|length
argument_list|()
condition|)
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"\"\""
argument_list|)
return|;
name|QString
name|ret
argument_list|(
name|arg
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|hasSpecialChars
argument_list|(
name|ret
argument_list|,
name|iqm
argument_list|)
condition|)
block|{
comment|// The process-level standard quoting allows escaping quotes with backslashes (note
comment|// that backslashes don't escape themselves, unless they are followed by a quote).
comment|// Consequently, quotes are escaped and their preceding backslashes are doubled.
name|ret
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"(\\\\*)\""
argument_list|)
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\1\\1\\\""
argument_list|)
argument_list|)
expr_stmt|;
comment|// Trailing backslashes must be doubled as well, as they are followed by a quote.
name|ret
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
name|QLatin1String
argument_list|(
literal|"(\\\\+)$"
argument_list|)
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"\\1\\1"
argument_list|)
argument_list|)
expr_stmt|;
comment|// However, the shell also interprets the command, and no backslash-escaping exists
comment|// there - a quote always toggles the quoting state, but is nonetheless passed down
comment|// to the called process verbatim. In the unquoted state, the circumflex escapes
comment|// meta chars (including itself and quotes), and is removed from the command.
name|bool
name|quoted
init|=
literal|true
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
name|ret
operator|.
name|length
argument_list|()
condition|;
name|i
operator|++
control|)
block|{
name|QChar
name|c
init|=
name|ret
operator|.
name|unicode
argument_list|()
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|c
operator|.
name|unicode
argument_list|()
operator|==
literal|'"'
condition|)
name|quoted
operator|=
operator|!
name|quoted
expr_stmt|;
elseif|else
if|if
condition|(
operator|!
name|quoted
operator|&&
name|isSpecialChar
argument_list|(
name|c
operator|.
name|unicode
argument_list|()
argument_list|,
name|ism
argument_list|)
condition|)
name|ret
operator|.
name|insert
argument_list|(
name|i
operator|++
argument_list|,
name|QLatin1Char
argument_list|(
literal|'^'
argument_list|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|quoted
condition|)
name|ret
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'^'
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|.
name|append
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|.
name|prepend
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_if
begin_return
return|return
name|ret
return|;
end_return
unit|}  QT_END_NAMESPACE
end_unit
