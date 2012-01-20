begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"uic.h"
end_include
begin_include
include|#
directive|include
file|"option.h"
end_include
begin_include
include|#
directive|include
file|"driver.h"
end_include
begin_include
include|#
directive|include
file|"../../corelib/global/qconfig.cpp"
end_include
begin_include
include|#
directive|include
file|<QtCore/QFile>
end_include
begin_include
include|#
directive|include
file|<QtCore/QDir>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextStream>
end_include
begin_include
include|#
directive|include
file|<QtCore/QTextCodec>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|error
specifier|static
specifier|const
name|char
modifier|*
name|error
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|showHelp
name|void
name|showHelp
parameter_list|(
specifier|const
name|char
modifier|*
name|appName
parameter_list|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Qt User Interface Compiler version %s\n"
argument_list|,
name|QT_VERSION_STR
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|appName
argument_list|,
name|error
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: %s [options]<uifile>\n\n"
literal|"  -h, -help                 display this help and exit\n"
literal|"  -v, -version              display version\n"
literal|"  -d, -dependencies         display the dependencies\n"
literal|"  -o<file>                 place the output into<file>\n"
literal|"  -tr<func>                use func() for i18n\n"
literal|"  -p, -no-protection        disable header protection\n"
literal|"  -n, -no-implicit-includes disable generation of #include-directives\n"
literal|"                            for forms generated by uic3\n"
literal|"  -g<name>                 change generator\n"
literal|"\n"
argument_list|,
name|appName
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|runUic
name|int
name|runUic
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
name|Driver
name|driver
decl_stmt|;
specifier|const
name|char
modifier|*
name|fileName
init|=
literal|0
decl_stmt|;
name|int
name|arg
init|=
literal|1
decl_stmt|;
while|while
condition|(
name|arg
operator|<
name|argc
condition|)
block|{
name|QString
name|opt
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|)
decl_stmt|;
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-h"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-help"
argument_list|)
condition|)
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-d"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-dependencies"
argument_list|)
condition|)
block|{
name|driver
operator|.
name|option
argument_list|()
operator|.
name|dependencies
operator|=
literal|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-v"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-version"
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Qt User Interface Compiler version %s\n"
argument_list|,
name|QT_VERSION_STR
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-o"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-output"
argument_list|)
condition|)
block|{
operator|++
name|arg
expr_stmt|;
if|if
condition|(
operator|!
name|argv
index|[
name|arg
index|]
condition|)
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
operator|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-p"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-no-protection"
argument_list|)
condition|)
block|{
name|driver
operator|.
name|option
argument_list|()
operator|.
name|headerProtection
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-n"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-no-implicit-includes"
argument_list|)
condition|)
block|{
name|driver
operator|.
name|option
argument_list|()
operator|.
name|implicitIncludes
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-postfix"
argument_list|)
condition|)
block|{
operator|++
name|arg
expr_stmt|;
if|if
condition|(
operator|!
name|argv
index|[
name|arg
index|]
condition|)
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|driver
operator|.
name|option
argument_list|()
operator|.
name|postfix
operator|=
name|QLatin1String
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-3"
argument_list|)
condition|)
block|{
operator|++
name|arg
expr_stmt|;
if|if
condition|(
operator|!
name|argv
index|[
name|arg
index|]
condition|)
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|driver
operator|.
name|option
argument_list|()
operator|.
name|uic3
operator|=
name|QFile
operator|::
name|decodeName
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-tr"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-translate"
argument_list|)
condition|)
block|{
operator|++
name|arg
expr_stmt|;
if|if
condition|(
operator|!
name|argv
index|[
name|arg
index|]
condition|)
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|driver
operator|.
name|option
argument_list|()
operator|.
name|translateFunction
operator|=
name|QLatin1String
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-g"
argument_list|)
operator|||
name|opt
operator|==
name|QLatin1String
argument_list|(
literal|"-generator"
argument_list|)
condition|)
block|{
operator|++
name|arg
expr_stmt|;
if|if
condition|(
operator|!
name|argv
index|[
name|arg
index|]
condition|)
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|QString
name|name
init|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|argv
index|[
name|arg
index|]
argument_list|)
operator|.
name|toLower
argument_list|()
decl_stmt|;
name|driver
operator|.
name|option
argument_list|()
operator|.
name|generator
operator|=
operator|(
name|name
operator|==
name|QLatin1String
argument_list|(
literal|"java"
argument_list|)
operator|)
condition|?
name|Option
operator|::
name|JavaGenerator
else|:
name|Option
operator|::
name|CppGenerator
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|fileName
condition|)
block|{
name|fileName
operator|=
name|argv
index|[
name|arg
index|]
expr_stmt|;
block|}
else|else
block|{
name|showHelp
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
operator|++
name|arg
expr_stmt|;
block|}
name|QString
name|inputFile
decl_stmt|;
if|if
condition|(
name|fileName
condition|)
name|inputFile
operator|=
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|fileName
argument_list|)
expr_stmt|;
else|else
name|driver
operator|.
name|option
argument_list|()
operator|.
name|headerProtection
operator|=
literal|false
expr_stmt|;
if|if
condition|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|dependencies
condition|)
block|{
return|return
operator|!
name|driver
operator|.
name|printDependencies
argument_list|(
name|inputFile
argument_list|)
return|;
block|}
name|QTextStream
modifier|*
name|out
init|=
literal|0
decl_stmt|;
name|QFile
name|f
decl_stmt|;
if|if
condition|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
operator|.
name|size
argument_list|()
condition|)
block|{
name|f
operator|.
name|setFileName
argument_list|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|f
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not create output file\n"
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|out
operator|=
operator|new
name|QTextStream
argument_list|(
operator|&
name|f
argument_list|)
expr_stmt|;
name|out
operator|->
name|setCodec
argument_list|(
name|QTextCodec
operator|::
name|codecForName
argument_list|(
literal|"UTF-8"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|bool
name|rtn
init|=
name|driver
operator|.
name|uic
argument_list|(
name|inputFile
argument_list|,
name|out
argument_list|)
decl_stmt|;
operator|delete
name|out
expr_stmt|;
if|if
condition|(
operator|!
name|rtn
condition|)
block|{
if|if
condition|(
name|driver
operator|.
name|option
argument_list|()
operator|.
name|outputFile
operator|.
name|size
argument_list|()
condition|)
block|{
name|f
operator|.
name|close
argument_list|()
expr_stmt|;
name|f
operator|.
name|remove
argument_list|()
expr_stmt|;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"File '%s' is not valid\n"
argument_list|,
name|inputFile
operator|.
name|isEmpty
argument_list|()
condition|?
literal|"<stdin>"
else|:
name|inputFile
operator|.
name|toLocal8Bit
argument_list|()
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
operator|!
name|rtn
return|;
block|}
end_function
begin_function
name|QT_END_NAMESPACE
DECL|function|main
name|int
name|main
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
return|return
name|QT_PREPEND_NAMESPACE
argument_list|(
name|runUic
argument_list|)
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
return|;
block|}
end_function
end_unit
