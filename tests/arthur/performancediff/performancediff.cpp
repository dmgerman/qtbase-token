begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"performancediff.h"
end_include
begin_include
include|#
directive|include
file|"xmldata.h"
end_include
begin_include
include|#
directive|include
file|<QtXml>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QDateTime>
end_include
begin_include
include|#
directive|include
file|<QtDebug>
end_include
begin_include
include|#
directive|include
file|<iostream>
end_include
begin_include
include|#
directive|include
file|<iomanip>
end_include
begin_decl_stmt
DECL|variable|MIN_TEST_VAL
specifier|static
specifier|const
name|int
name|MIN_TEST_VAL
init|=
literal|20
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|TEST_EPSILON
specifier|static
specifier|const
name|int
name|TEST_EPSILON
init|=
literal|5
decl_stmt|;
end_decl_stmt
begin_comment
DECL|variable|TEST_EPSILON
comment|//ms
end_comment
begin_function
DECL|function|usage
specifier|static
name|void
name|usage
parameter_list|(
specifier|const
name|char
modifier|*
name|progname
parameter_list|)
block|{
name|std
operator|::
name|cerr
operator|<<
literal|"Couldn't find 'framework.ini' "
operator|<<
literal|"file and no output has been specified."
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
name|std
operator|::
name|cerr
operator|<<
literal|"Usage: "
operator|<<
name|progname
operator|<<
literal|" oldDataDir"
operator|<<
literal|" newDataDir\n"
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|PerformanceDiff
name|PerformanceDiff
operator|::
name|PerformanceDiff
parameter_list|()
member_init_list|:
name|settings
argument_list|(
literal|0
argument_list|)
block|{
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
literal|"framework.ini"
argument_list|)
condition|)
block|{
name|settings
operator|=
operator|new
name|QSettings
argument_list|(
literal|"framework.ini"
argument_list|,
name|QSettings
operator|::
name|IniFormat
argument_list|)
expr_stmt|;
block|}
block|}
end_constructor
begin_function
DECL|function|loadEngines
specifier|static
name|void
name|loadEngines
parameter_list|(
specifier|const
name|QString
modifier|&
name|dirName
parameter_list|,
name|QMap
argument_list|<
name|QString
argument_list|,
name|XMLEngine
modifier|*
argument_list|>
modifier|&
name|engines
parameter_list|)
block|{
name|QDir
name|dir
argument_list|(
name|dirName
argument_list|)
decl_stmt|;
name|dir
operator|.
name|setFilter
argument_list|(
name|QDir
operator|::
name|Dirs
operator||
name|QDir
operator|::
name|NoSymLinks
operator||
name|QDir
operator|::
name|NoDotAndDotDot
argument_list|)
expr_stmt|;
name|QFileInfoList
name|list
init|=
name|dir
operator|.
name|entryInfoList
argument_list|()
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
name|list
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QFileInfo
name|fileInfo
init|=
name|list
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|QString
name|dataFile
init|=
name|QString
argument_list|(
literal|"%1/data.xml"
argument_list|)
operator|.
name|arg
argument_list|(
name|fileInfo
operator|.
name|absoluteFilePath
argument_list|()
argument_list|)
decl_stmt|;
if|if
condition|(
name|QFile
operator|::
name|exists
argument_list|(
name|dataFile
argument_list|)
condition|)
block|{
name|XMLReader
name|handler
decl_stmt|;
name|QXmlSimpleReader
name|reader
decl_stmt|;
name|reader
operator|.
name|setContentHandler
argument_list|(
operator|&
name|handler
argument_list|)
expr_stmt|;
name|reader
operator|.
name|setErrorHandler
argument_list|(
operator|&
name|handler
argument_list|)
expr_stmt|;
name|QFile
name|file
argument_list|(
name|dataFile
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
operator||
name|QFile
operator|::
name|Text
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Cannot open file '%s', because: %s"
argument_list|,
name|qPrintable
argument_list|(
name|dataFile
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|file
operator|.
name|errorString
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|QXmlInputSource
name|xmlInputSource
argument_list|(
operator|&
name|file
argument_list|)
decl_stmt|;
if|if
condition|(
name|reader
operator|.
name|parse
argument_list|(
name|xmlInputSource
argument_list|)
condition|)
block|{
name|XMLEngine
modifier|*
name|engine
init|=
name|handler
operator|.
name|xmlEngine
argument_list|()
decl_stmt|;
name|engines
operator|.
name|insert
argument_list|(
name|engine
operator|->
name|name
argument_list|,
name|engine
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
end_function
begin_function
DECL|function|run
name|void
name|PerformanceDiff
operator|::
name|run
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
name|processArguments
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|loadEngines
argument_list|(
name|inputDirName
argument_list|,
name|inputEngines
argument_list|)
expr_stmt|;
name|loadEngines
argument_list|(
name|diffDirName
argument_list|,
name|diffEngines
argument_list|)
expr_stmt|;
if|if
condition|(
name|inputEngines
operator|.
name|isEmpty
argument_list|()
operator|||
name|diffEngines
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
name|usage
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
return|return;
block|}
name|generateDiff
argument_list|()
expr_stmt|;
comment|//generateOutput();
block|}
end_function
begin_function
DECL|function|processArguments
name|void
name|PerformanceDiff
operator|::
name|processArguments
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
if|if
condition|(
name|argc
operator|!=
literal|3
condition|)
return|return;
name|inputDirName
operator|=
name|QString
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|diffDirName
operator|=
name|QString
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|generateDiff
name|void
name|PerformanceDiff
operator|::
name|generateDiff
parameter_list|()
block|{
name|qreal
name|totalIn
init|=
literal|0
decl_stmt|;
name|qreal
name|totalDiff
init|=
literal|0
decl_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|setiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|left
argument_list|)
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|30
argument_list|)
operator|<<
literal|"Testcase"
operator|<<
name|std
operator|::
name|setiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|right
argument_list|)
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|10
argument_list|)
operator|<<
literal|"Before"
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|15
argument_list|)
operator|<<
literal|"After"
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|20
argument_list|)
operator|<<
literal|"Difference"
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|resetiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|right
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|resetiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|left
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|setfill
argument_list|(
literal|'-'
argument_list|)
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|75
argument_list|)
operator|<<
literal|'-'
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
foreach|foreach
control|(
name|XMLEngine
modifier|*
name|diffEngine
decl|,
name|diffEngines
control|)
block|{
name|XMLEngine
modifier|*
name|inEngine
init|=
name|inputEngines
index|[
name|diffEngine
operator|->
name|name
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|inEngine
condition|)
continue|continue;
foreach|foreach
control|(
name|XMLSuite
modifier|*
name|diffSuite
decl|,
name|diffEngine
operator|->
name|suites
control|)
block|{
name|XMLSuite
modifier|*
name|inSuite
init|=
name|inEngine
operator|->
name|suites
index|[
name|diffSuite
operator|->
name|name
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|inSuite
condition|)
continue|continue;
foreach|foreach
control|(
name|XMLFile
modifier|*
name|diffFile
decl|,
name|diffSuite
operator|->
name|files
control|)
block|{
name|XMLFile
modifier|*
name|inFile
init|=
name|inSuite
operator|->
name|files
index|[
name|diffFile
operator|->
name|name
index|]
decl_stmt|;
if|if
condition|(
operator|!
name|inFile
condition|)
continue|continue;
name|qreal
name|inAvg
init|=
literal|0
decl_stmt|;
name|qreal
name|diffAvg
init|=
literal|0
decl_stmt|;
name|qreal
name|inMin
init|=
literal|0
decl_stmt|;
name|qreal
name|inMax
init|=
literal|0
decl_stmt|;
foreach|foreach
control|(
name|XMLData
name|data
decl|,
name|inFile
operator|->
name|data
control|)
block|{
name|inAvg
operator|=
operator|(
name|double
argument_list|(
name|data
operator|.
name|timeToRender
argument_list|)
operator|/
name|data
operator|.
name|iterations
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|inMin
condition|)
name|inMin
operator|=
name|data
operator|.
name|minElapsed
expr_stmt|;
elseif|else
if|if
condition|(
name|data
operator|.
name|minElapsed
operator|<
name|inMin
condition|)
name|inMin
operator|=
name|data
operator|.
name|minElapsed
expr_stmt|;
if|if
condition|(
operator|!
name|inMax
condition|)
name|inMax
operator|=
name|data
operator|.
name|maxElapsed
expr_stmt|;
elseif|else
if|if
condition|(
name|inMax
operator|<
name|data
operator|.
name|maxElapsed
condition|)
name|inMax
operator|=
name|data
operator|.
name|maxElapsed
expr_stmt|;
block|}
comment|//skipping really small tests
if|if
condition|(
name|inAvg
operator|<
name|MIN_TEST_VAL
condition|)
block|{
continue|continue;
block|}
name|totalIn
operator|+=
name|inAvg
expr_stmt|;
foreach|foreach
control|(
name|XMLData
name|data
decl|,
name|diffFile
operator|->
name|data
control|)
block|{
name|diffAvg
operator|=
operator|(
name|double
argument_list|(
name|data
operator|.
name|timeToRender
argument_list|)
operator|/
name|data
operator|.
name|iterations
operator|)
expr_stmt|;
block|}
name|totalDiff
operator|+=
name|diffAvg
expr_stmt|;
name|QFileInfo
name|fi
argument_list|(
name|diffFile
operator|->
name|name
argument_list|)
decl_stmt|;
name|std
operator|::
name|cout
operator|.
name|width
argument_list|(
literal|80
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|.
name|setf
argument_list|(
name|std
operator|::
name|ios
operator|::
name|fixed
argument_list|,
name|std
operator|::
name|ios
operator|::
name|floatfield
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|.
name|setf
argument_list|(
name|std
operator|::
name|ios
operator|::
name|showpoint
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|resetiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|right
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|resetiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|left
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|30
argument_list|)
operator|<<
name|std
operator|::
name|setfill
argument_list|(
literal|'.'
argument_list|)
operator|<<
name|std
operator|::
name|setiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|left
argument_list|)
operator|<<
name|qPrintable
argument_list|(
name|fi
operator|.
name|fileName
argument_list|()
argument_list|)
operator|<<
literal|"\t"
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|setfill
argument_list|(
literal|' '
argument_list|)
operator|<<
name|std
operator|::
name|setprecision
argument_list|(
literal|2
argument_list|)
operator|<<
name|std
operator|::
name|setiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|right
argument_list|)
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|8
argument_list|)
operator|<<
name|std
operator|::
name|setiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|right
argument_list|)
operator|<<
name|inAvg
operator|<<
literal|"\t"
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|8
argument_list|)
operator|<<
name|diffAvg
operator|<<
literal|"\t"
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|7
argument_list|)
operator|<<
operator|(
operator|(
literal|1.0
operator|-
operator|(
name|diffAvg
operator|/
name|inAvg
operator|)
operator|)
operator|*
literal|100.0
operator|)
operator|<<
literal|"%"
expr_stmt|;
if|if
condition|(
name|diffAvg
operator|<
name|inMin
operator|&&
operator|(
name|qAbs
argument_list|(
name|inMin
operator|-
name|diffAvg
argument_list|)
operator|>
name|TEST_EPSILON
operator|)
condition|)
block|{
name|std
operator|::
name|cout
operator|<<
literal|" + ("
operator|<<
name|inMin
operator|<<
literal|")"
expr_stmt|;
block|}
if|if
condition|(
name|diffAvg
operator|>
name|inMax
operator|&&
operator|(
name|qAbs
argument_list|(
name|diffAvg
operator|-
name|inMax
argument_list|)
operator|>
name|TEST_EPSILON
operator|)
condition|)
block|{
name|std
operator|::
name|cout
operator|<<
literal|" - ("
operator|<<
name|inMax
operator|<<
literal|")"
expr_stmt|;
block|}
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
block|}
block|}
block|}
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|resetiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|right
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|resetiosflags
argument_list|(
name|std
operator|::
name|ios
operator|::
name|left
argument_list|)
expr_stmt|;
name|std
operator|::
name|cout
operator|<<
name|std
operator|::
name|setfill
argument_list|(
literal|'-'
argument_list|)
operator|<<
name|std
operator|::
name|setw
argument_list|(
literal|75
argument_list|)
operator|<<
literal|'-'
operator|<<
name|std
operator|::
name|endl
expr_stmt|;
block|}
end_function
end_unit
