begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"preprocessor.h"
end_include
begin_include
include|#
directive|include
file|"moc.h"
end_include
begin_include
include|#
directive|include
file|"outputrevision.h"
end_include
begin_include
include|#
directive|include
file|"../../corelib/global/qconfig.cpp"
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
begin_include
include|#
directive|include
file|<QDir>
end_include
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
file|<ctype.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|/*     This function looks at two file names and returns the name of the     infile with a path relative to outfile.      Examples:          /tmp/abc, /tmp/bcd -> abc         xyz/a/bc, xyz/b/ac -> ../a/bc         /tmp/abc, xyz/klm -> /tmp/abc  */
DECL|function|combinePath
specifier|static
name|QByteArray
name|combinePath
parameter_list|(
specifier|const
name|char
modifier|*
name|infile
parameter_list|,
specifier|const
name|char
modifier|*
name|outfile
parameter_list|)
block|{
name|QFileInfo
name|inFileInfo
argument_list|(
name|QDir
operator|::
name|current
argument_list|()
argument_list|,
name|QFile
operator|::
name|decodeName
argument_list|(
name|infile
argument_list|)
argument_list|)
decl_stmt|;
name|QFileInfo
name|outFileInfo
argument_list|(
name|QDir
operator|::
name|current
argument_list|()
argument_list|,
name|QFile
operator|::
name|decodeName
argument_list|(
name|outfile
argument_list|)
argument_list|)
decl_stmt|;
return|return
name|QFile
operator|::
name|encodeName
argument_list|(
name|outFileInfo
operator|.
name|dir
argument_list|()
operator|.
name|relativeFilePath
argument_list|(
name|inFileInfo
operator|.
name|filePath
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|error
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|msg
init|=
literal|"Invalid argument"
parameter_list|)
block|{
if|if
condition|(
name|msg
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"moc: %s\n"
argument_list|,
name|msg
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: moc [options]<header-file>\n"
literal|"  -o<file>           write output to file rather than stdout\n"
literal|"  -I<dir>            add dir to the include path for header files\n"
literal|"  -E                 preprocess only; do not generate meta object code\n"
literal|"  -D<macro>[=<def>]  define macro, with optional definition\n"
literal|"  -U<macro>          undefine macro\n"
literal|"  -i                 do not generate an #include statement\n"
literal|"  -p<path>           path prefix for included file\n"
literal|"  -f[<file>]         force #include, optional file name (overwrite default)\n"
literal|"  -b<file>           prepend #include<file> (preserve default include)\n"
literal|"  -nn                do not display notes\n"
literal|"  -nw                do not display warnings\n"
literal|"  @<file>            read additional options from file\n"
literal|"  -v                 display version of moc\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|hasNext
specifier|static
specifier|inline
name|bool
name|hasNext
parameter_list|(
specifier|const
name|Symbols
modifier|&
name|symbols
parameter_list|,
name|int
name|i
parameter_list|)
block|{
return|return
operator|(
name|i
operator|<
name|symbols
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
end_function
begin_function
DECL|function|next
specifier|static
specifier|inline
specifier|const
name|Symbol
modifier|&
name|next
parameter_list|(
specifier|const
name|Symbols
modifier|&
name|symbols
parameter_list|,
name|int
modifier|&
name|i
parameter_list|)
block|{
return|return
name|symbols
operator|.
name|at
argument_list|(
name|i
operator|++
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|composePreprocessorOutput
name|QByteArray
name|composePreprocessorOutput
parameter_list|(
specifier|const
name|Symbols
modifier|&
name|symbols
parameter_list|)
block|{
name|QByteArray
name|output
decl_stmt|;
name|int
name|lineNum
init|=
literal|1
decl_stmt|;
name|Token
name|last
init|=
name|PP_NOTOKEN
decl_stmt|;
name|Token
name|secondlast
init|=
name|last
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|hasNext
argument_list|(
name|symbols
argument_list|,
name|i
argument_list|)
condition|)
block|{
name|Symbol
name|sym
init|=
name|next
argument_list|(
name|symbols
argument_list|,
name|i
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|sym
operator|.
name|token
condition|)
block|{
case|case
name|PP_NEWLINE
case|:
case|case
name|PP_WHITESPACE
case|:
if|if
condition|(
name|last
operator|!=
name|PP_WHITESPACE
condition|)
block|{
name|secondlast
operator|=
name|last
expr_stmt|;
name|last
operator|=
name|PP_WHITESPACE
expr_stmt|;
name|output
operator|+=
literal|' '
expr_stmt|;
block|}
continue|continue;
case|case
name|PP_STRING_LITERAL
case|:
if|if
condition|(
name|last
operator|==
name|PP_STRING_LITERAL
condition|)
name|output
operator|.
name|chop
argument_list|(
literal|1
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|secondlast
operator|==
name|PP_STRING_LITERAL
operator|&&
name|last
operator|==
name|PP_WHITESPACE
condition|)
name|output
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
else|else
break|break;
name|output
operator|+=
name|sym
operator|.
name|lexem
argument_list|()
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|secondlast
operator|=
name|last
expr_stmt|;
name|last
operator|=
name|PP_STRING_LITERAL
expr_stmt|;
continue|continue;
case|case
name|MOC_INCLUDE_BEGIN
case|:
name|lineNum
operator|=
literal|0
expr_stmt|;
continue|continue;
case|case
name|MOC_INCLUDE_END
case|:
name|lineNum
operator|=
name|sym
operator|.
name|lineNum
expr_stmt|;
continue|continue;
default|default:
break|break;
block|}
name|secondlast
operator|=
name|last
expr_stmt|;
name|last
operator|=
name|sym
operator|.
name|token
expr_stmt|;
specifier|const
name|int
name|padding
init|=
name|sym
operator|.
name|lineNum
operator|-
name|lineNum
decl_stmt|;
if|if
condition|(
name|padding
operator|>
literal|0
condition|)
block|{
name|output
operator|.
name|resize
argument_list|(
name|output
operator|.
name|size
argument_list|()
operator|+
name|padding
argument_list|)
expr_stmt|;
name|qMemSet
argument_list|(
name|output
operator|.
name|data
argument_list|()
operator|+
name|output
operator|.
name|size
argument_list|()
operator|-
name|padding
argument_list|,
literal|'\n'
argument_list|,
name|padding
argument_list|)
expr_stmt|;
name|lineNum
operator|=
name|sym
operator|.
name|lineNum
expr_stmt|;
block|}
name|output
operator|+=
name|sym
operator|.
name|lexem
argument_list|()
expr_stmt|;
block|}
return|return
name|output
return|;
block|}
end_function
begin_function
DECL|function|runMoc
name|int
name|runMoc
parameter_list|(
name|int
name|_argc
parameter_list|,
name|char
modifier|*
modifier|*
name|_argv
parameter_list|)
block|{
name|bool
name|autoInclude
init|=
literal|true
decl_stmt|;
name|bool
name|defaultInclude
init|=
literal|true
decl_stmt|;
name|Preprocessor
name|pp
decl_stmt|;
name|Moc
name|moc
decl_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"Q_MOC_RUN"
index|]
expr_stmt|;
name|pp
operator|.
name|macros
index|[
literal|"__cplusplus"
index|]
expr_stmt|;
name|QByteArray
name|filename
decl_stmt|;
name|QByteArray
name|output
decl_stmt|;
name|FILE
modifier|*
name|in
init|=
literal|0
decl_stmt|;
name|FILE
modifier|*
name|out
init|=
literal|0
decl_stmt|;
name|bool
name|ignoreConflictingOptions
init|=
literal|false
decl_stmt|;
name|QVector
argument_list|<
name|QByteArray
argument_list|>
name|argv
decl_stmt|;
name|argv
operator|.
name|resize
argument_list|(
name|_argc
operator|-
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|n
init|=
literal|1
init|;
name|n
operator|<
name|_argc
condition|;
operator|++
name|n
control|)
name|argv
index|[
name|n
operator|-
literal|1
index|]
operator|=
name|_argv
index|[
name|n
index|]
expr_stmt|;
name|int
name|argc
init|=
name|argv
operator|.
name|count
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|n
init|=
literal|0
init|;
name|n
operator|<
name|argv
operator|.
name|count
argument_list|()
condition|;
operator|++
name|n
control|)
block|{
if|if
condition|(
name|argv
operator|.
name|at
argument_list|(
name|n
argument_list|)
operator|.
name|startsWith
argument_list|(
literal|'@'
argument_list|)
condition|)
block|{
name|QByteArray
name|optionsFile
init|=
name|argv
operator|.
name|at
argument_list|(
name|n
argument_list|)
decl_stmt|;
name|optionsFile
operator|.
name|remove
argument_list|(
literal|0
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|optionsFile
operator|.
name|isEmpty
argument_list|()
condition|)
name|error
argument_list|(
literal|"The @ option requires an input file"
argument_list|)
expr_stmt|;
name|QFile
name|f
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
name|optionsFile
operator|.
name|constData
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
operator||
name|QIODevice
operator|::
name|Text
argument_list|)
condition|)
name|error
argument_list|(
literal|"Cannot open options file specified with @"
argument_list|)
expr_stmt|;
name|argv
operator|.
name|remove
argument_list|(
name|n
argument_list|)
expr_stmt|;
while|while
condition|(
operator|!
name|f
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|f
operator|.
name|readLine
argument_list|()
operator|.
name|trimmed
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|line
operator|.
name|isEmpty
argument_list|()
condition|)
name|argv
operator|.
name|insert
argument_list|(
name|n
operator|++
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
block|}
block|}
name|argc
operator|=
name|argv
operator|.
name|count
argument_list|()
expr_stmt|;
for|for
control|(
name|int
name|n
init|=
literal|0
init|;
name|n
operator|<
name|argc
condition|;
operator|++
name|n
control|)
block|{
name|QByteArray
name|arg
argument_list|(
name|argv
index|[
name|n
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
block|{
if|if
condition|(
name|filename
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|filename
operator|=
name|arg
expr_stmt|;
continue|continue;
block|}
name|error
argument_list|(
literal|"Too many input files specified"
argument_list|)
expr_stmt|;
block|}
name|QByteArray
name|opt
init|=
name|arg
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|bool
name|more
init|=
operator|(
name|opt
operator|.
name|size
argument_list|()
operator|>
literal|1
operator|)
decl_stmt|;
switch|switch
condition|(
name|opt
index|[
literal|0
index|]
condition|)
block|{
case|case
literal|'o'
case|:
comment|// output redirection
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|n
operator|<
name|argc
operator|-
literal|1
operator|)
condition|)
name|error
argument_list|(
literal|"Missing output file name"
argument_list|)
expr_stmt|;
name|output
operator|=
name|argv
index|[
operator|++
name|n
index|]
expr_stmt|;
block|}
else|else
name|output
operator|=
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'E'
case|:
comment|// only preprocessor
name|pp
operator|.
name|preprocessOnly
operator|=
literal|true
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
comment|// no #include statement
if|if
condition|(
name|more
condition|)
name|error
argument_list|()
expr_stmt|;
name|moc
operator|.
name|noInclude
operator|=
literal|true
expr_stmt|;
name|autoInclude
operator|=
literal|false
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
comment|// produce #include statement
if|if
condition|(
name|ignoreConflictingOptions
condition|)
break|break;
name|moc
operator|.
name|noInclude
operator|=
literal|false
expr_stmt|;
name|autoInclude
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|opt
index|[
literal|1
index|]
condition|)
block|{
comment|// -fsomething.h
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|defaultInclude
operator|=
literal|false
expr_stmt|;
block|}
break|break;
case|case
literal|'b'
case|:
if|if
condition|(
name|ignoreConflictingOptions
condition|)
break|break;
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|n
operator|<
name|argc
operator|-
literal|1
operator|)
condition|)
name|error
argument_list|(
literal|"Missing file name for the -b option."
argument_list|)
expr_stmt|;
name|moc
operator|.
name|includeFiles
operator|.
name|prepend
argument_list|(
name|argv
index|[
operator|++
name|n
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
index|[
literal|1
index|]
condition|)
block|{
name|moc
operator|.
name|includeFiles
operator|.
name|prepend
argument_list|(
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'p'
case|:
comment|// include file path
if|if
condition|(
name|ignoreConflictingOptions
condition|)
break|break;
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|n
operator|<
name|argc
operator|-
literal|1
operator|)
condition|)
name|error
argument_list|(
literal|"Missing path name for the -p option."
argument_list|)
expr_stmt|;
name|moc
operator|.
name|includePath
operator|=
name|argv
index|[
operator|++
name|n
index|]
expr_stmt|;
block|}
else|else
block|{
name|moc
operator|.
name|includePath
operator|=
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'I'
case|:
comment|// produce #include statement
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|n
operator|<
name|argc
operator|-
literal|1
operator|)
condition|)
name|error
argument_list|(
literal|"Missing path name for the -I option."
argument_list|)
expr_stmt|;
name|pp
operator|.
name|includes
operator|+=
name|Preprocessor
operator|::
name|IncludePath
argument_list|(
name|argv
index|[
operator|++
name|n
index|]
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|pp
operator|.
name|includes
operator|+=
name|Preprocessor
operator|::
name|IncludePath
argument_list|(
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'F'
case|:
comment|// minimalistic framework support for the mac
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
operator|!
operator|(
name|n
operator|<
name|argc
operator|-
literal|1
operator|)
condition|)
name|error
argument_list|(
literal|"Missing path name for the -F option."
argument_list|)
expr_stmt|;
name|Preprocessor
operator|::
name|IncludePath
name|p
argument_list|(
name|argv
index|[
operator|++
name|n
index|]
argument_list|)
decl_stmt|;
name|p
operator|.
name|isFrameworkPath
operator|=
literal|true
expr_stmt|;
name|pp
operator|.
name|includes
operator|+=
name|p
expr_stmt|;
block|}
else|else
block|{
name|Preprocessor
operator|::
name|IncludePath
name|p
argument_list|(
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|p
operator|.
name|isFrameworkPath
operator|=
literal|true
expr_stmt|;
name|pp
operator|.
name|includes
operator|+=
name|p
expr_stmt|;
block|}
break|break;
case|case
literal|'D'
case|:
comment|// define macro
block|{
name|QByteArray
name|name
decl_stmt|;
name|QByteArray
name|value
argument_list|(
literal|"1"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
name|n
operator|<
name|argc
operator|-
literal|1
condition|)
name|name
operator|=
name|argv
index|[
operator|++
name|n
index|]
expr_stmt|;
block|}
else|else
name|name
operator|=
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|int
name|eq
init|=
name|name
operator|.
name|indexOf
argument_list|(
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|eq
operator|>=
literal|0
condition|)
block|{
name|value
operator|=
name|name
operator|.
name|mid
argument_list|(
name|eq
operator|+
literal|1
argument_list|)
expr_stmt|;
name|name
operator|=
name|name
operator|.
name|left
argument_list|(
name|eq
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|name
operator|.
name|isEmpty
argument_list|()
condition|)
name|error
argument_list|(
literal|"Missing macro name"
argument_list|)
expr_stmt|;
name|Macro
name|macro
decl_stmt|;
name|macro
operator|.
name|symbols
operator|+=
name|Symbol
argument_list|(
literal|0
argument_list|,
name|PP_IDENTIFIER
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|pp
operator|.
name|macros
operator|.
name|insert
argument_list|(
name|name
argument_list|,
name|macro
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'U'
case|:
block|{
name|QByteArray
name|macro
decl_stmt|;
if|if
condition|(
operator|!
name|more
condition|)
block|{
if|if
condition|(
name|n
operator|<
name|argc
operator|-
literal|1
condition|)
name|macro
operator|=
name|argv
index|[
operator|++
name|n
index|]
expr_stmt|;
block|}
else|else
name|macro
operator|=
name|opt
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|macro
operator|.
name|isEmpty
argument_list|()
condition|)
name|error
argument_list|(
literal|"Missing macro name"
argument_list|)
expr_stmt|;
name|pp
operator|.
name|macros
operator|.
name|remove
argument_list|(
name|macro
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|'v'
case|:
comment|// version number
if|if
condition|(
name|more
operator|&&
name|opt
operator|!=
literal|"version"
condition|)
name|error
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Qt Meta Object Compiler version %d (Qt %s)\n"
argument_list|,
name|mocOutputRevision
argument_list|,
name|QT_VERSION_STR
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
case|case
literal|'n'
case|:
comment|// don't display warnings
if|if
condition|(
name|ignoreConflictingOptions
condition|)
break|break;
if|if
condition|(
name|opt
operator|==
literal|"nw"
condition|)
name|moc
operator|.
name|displayWarnings
operator|=
name|moc
operator|.
name|displayNotes
operator|=
literal|false
expr_stmt|;
elseif|else
if|if
condition|(
name|opt
operator|==
literal|"nn"
condition|)
name|moc
operator|.
name|displayNotes
operator|=
literal|false
expr_stmt|;
else|else
name|error
argument_list|()
expr_stmt|;
break|break;
case|case
literal|'h'
case|:
comment|// help
if|if
condition|(
name|more
operator|&&
name|opt
operator|!=
literal|"help"
condition|)
name|error
argument_list|()
expr_stmt|;
else|else
name|error
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// 0 means usage only
break|break;
case|case
literal|'-'
case|:
if|if
condition|(
name|more
operator|&&
name|arg
operator|==
literal|"--ignore-option-clashes"
condition|)
block|{
comment|// -- ignore all following moc specific options that conflict
comment|// with for example gcc, like -pthread conflicting with moc's
comment|// -p option.
name|ignoreConflictingOptions
operator|=
literal|true
expr_stmt|;
break|break;
block|}
comment|// fall through
default|default:
name|error
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
name|autoInclude
condition|)
block|{
name|int
name|spos
init|=
name|filename
operator|.
name|lastIndexOf
argument_list|(
name|QDir
operator|::
name|separator
argument_list|()
operator|.
name|toLatin1
argument_list|()
argument_list|)
decl_stmt|;
name|int
name|ppos
init|=
name|filename
operator|.
name|lastIndexOf
argument_list|(
literal|'.'
argument_list|)
decl_stmt|;
comment|// spos>= -1&& ppos> spos => ppos>= 0
name|moc
operator|.
name|noInclude
operator|=
operator|(
name|ppos
operator|>
name|spos
operator|&&
name|tolower
argument_list|(
name|filename
index|[
name|ppos
operator|+
literal|1
index|]
argument_list|)
operator|!=
literal|'h'
operator|)
expr_stmt|;
block|}
if|if
condition|(
name|defaultInclude
condition|)
block|{
if|if
condition|(
name|moc
operator|.
name|includePath
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
if|if
condition|(
name|filename
operator|.
name|size
argument_list|()
condition|)
block|{
if|if
condition|(
name|output
operator|.
name|size
argument_list|()
condition|)
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|combinePath
argument_list|(
name|filename
argument_list|,
name|output
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|filename
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|moc
operator|.
name|includeFiles
operator|.
name|append
argument_list|(
name|combinePath
argument_list|(
name|filename
argument_list|,
name|filename
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|filename
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|filename
operator|=
literal|"standard input"
expr_stmt|;
name|in
operator|=
name|stdin
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
if|if
condition|(
name|fopen_s
argument_list|(
operator|&
name|in
argument_list|,
name|filename
operator|.
name|data
argument_list|()
argument_list|,
literal|"rb"
argument_list|)
condition|)
block|{
else|#
directive|else
name|in
operator|=
name|fopen
argument_list|(
name|filename
operator|.
name|data
argument_list|()
argument_list|,
literal|"rb"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|in
condition|)
block|{
endif|#
directive|endif
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"moc: %s: No such file\n"
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|filename
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|moc
operator|.
name|filename
operator|=
name|filename
expr_stmt|;
block|}
name|moc
operator|.
name|currentFilenames
operator|.
name|push
argument_list|(
name|filename
argument_list|)
expr_stmt|;
comment|// 1. preprocess
name|moc
operator|.
name|symbols
operator|=
name|pp
operator|.
name|preprocessed
argument_list|(
name|moc
operator|.
name|filename
argument_list|,
name|in
argument_list|)
expr_stmt|;
name|fclose
argument_list|(
name|in
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pp
operator|.
name|preprocessOnly
condition|)
block|{
comment|// 2. parse
name|moc
operator|.
name|parse
argument_list|()
expr_stmt|;
block|}
comment|// 3. and output meta object code
if|if
condition|(
name|output
operator|.
name|size
argument_list|()
condition|)
block|{
comment|// output file specified
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
name|_MSC_VER
operator|>=
literal|1400
if|if
condition|(
name|fopen_s
argument_list|(
operator|&
name|out
argument_list|,
name|output
operator|.
name|data
argument_list|()
argument_list|,
literal|"w"
argument_list|)
condition|)
else|#
directive|else
name|out
operator|=
name|fopen
argument_list|(
name|output
operator|.
name|data
argument_list|()
argument_list|,
literal|"w"
argument_list|)
expr_stmt|;
comment|// create output file
if|if
condition|(
operator|!
name|out
condition|)
endif|#
directive|endif
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"moc: Cannot create %s\n"
argument_list|,
operator|(
specifier|const
name|char
operator|*
operator|)
name|output
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
else|else
block|{
comment|// use stdout
name|out
operator|=
name|stdout
expr_stmt|;
block|}
if|if
condition|(
name|pp
operator|.
name|preprocessOnly
condition|)
block|{
name|fprintf
argument_list|(
name|out
argument_list|,
literal|"%s\n"
argument_list|,
name|composePreprocessorOutput
argument_list|(
name|moc
operator|.
name|symbols
argument_list|)
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|moc
operator|.
name|classList
operator|.
name|isEmpty
argument_list|()
condition|)
name|moc
operator|.
name|note
argument_list|(
literal|"No relevant classes found. No output generated."
argument_list|)
expr_stmt|;
else|else
name|moc
operator|.
name|generate
argument_list|(
name|out
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|output
operator|.
name|size
argument_list|()
condition|)
name|fclose
argument_list|(
name|out
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
name|QT_END_NAMESPACE
DECL|function|main
name|int
name|main
parameter_list|(
name|int
name|_argc
parameter_list|,
name|char
modifier|*
modifier|*
name|_argv
parameter_list|)
block|{
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|runMoc
argument_list|)
argument_list|(
name|_argc
argument_list|,
name|_argv
argument_list|)
return|;
block|}
end_function
end_unit
