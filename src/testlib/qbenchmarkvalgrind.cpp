begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmark_p.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|QTESTLIB_USE_VALGRIND
end_ifdef
begin_include
include|#
directive|include
file|<QtTest/private/qbenchmarkvalgrind_p.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qprocess.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qdir.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qset.h>
end_include
begin_include
include|#
directive|include
file|<QtTest/private/callgrind_p.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
comment|// Returns true iff a sufficiently recent valgrind is available.
DECL|function|haveValgrind
name|bool
name|QBenchmarkValgrindUtils
operator|::
name|haveValgrind
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|NVALGRIND
return|return
literal|false
return|;
else|#
directive|else
name|QProcess
name|process
decl_stmt|;
name|QStringList
name|args
decl_stmt|;
name|args
operator|<<
name|QLatin1String
argument_list|(
literal|"--version"
argument_list|)
expr_stmt|;
name|process
operator|.
name|start
argument_list|(
name|QLatin1String
argument_list|(
literal|"valgrind"
argument_list|)
argument_list|,
name|args
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|process
operator|.
name|waitForFinished
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
return|return
literal|false
return|;
specifier|const
name|QByteArray
name|out
init|=
name|process
operator|.
name|readAllStandardOutput
argument_list|()
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
name|QLatin1String
argument_list|(
literal|"^valgrind-([0-9]).([0-9]).[0-9]"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|rx
operator|.
name|indexIn
argument_list|(
name|QLatin1String
argument_list|(
name|out
operator|.
name|data
argument_list|()
argument_list|)
argument_list|)
operator|==
operator|-
literal|1
condition|)
return|return
literal|false
return|;
name|bool
name|ok
decl_stmt|;
specifier|const
name|int
name|major
init|=
name|rx
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
specifier|const
name|int
name|minor
init|=
name|rx
operator|.
name|cap
argument_list|(
literal|2
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ok
condition|)
return|return
literal|false
return|;
comment|//    return (major> 3 || (major == 3&& minor>= 3)); // v>= 3.3 for --callgrind-out-file option
name|Q_UNUSED
argument_list|(
name|major
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|minor
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
comment|// skip version restriction for now
endif|#
directive|endif
block|}
end_function
begin_comment
comment|// Reruns this program through callgrind.
end_comment
begin_comment
comment|// Returns true upon success, otherwise false.
end_comment
begin_function
DECL|function|rerunThroughCallgrind
name|bool
name|QBenchmarkValgrindUtils
operator|::
name|rerunThroughCallgrind
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|origAppArgs
parameter_list|,
name|int
modifier|&
name|exitCode
parameter_list|)
block|{
if|if
condition|(
operator|!
name|QBenchmarkValgrindUtils
operator|::
name|runCallgrindSubProcess
argument_list|(
name|origAppArgs
argument_list|,
name|exitCode
argument_list|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"failed to run callgrind subprocess"
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|dumpOutput
specifier|static
name|void
name|dumpOutput
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|data
parameter_list|,
name|FILE
modifier|*
name|fh
parameter_list|)
block|{
name|QFile
name|file
decl_stmt|;
name|file
operator|.
name|open
argument_list|(
name|fh
argument_list|,
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|file
operator|.
name|write
argument_list|(
name|data
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|extractResult
name|qint64
name|QBenchmarkValgrindUtils
operator|::
name|extractResult
parameter_list|(
specifier|const
name|QString
modifier|&
name|fileName
parameter_list|)
block|{
name|QFile
name|file
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
specifier|const
name|bool
name|openOk
init|=
name|file
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
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|openOk
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|openOk
argument_list|)
expr_stmt|;
name|qint64
name|val
init|=
operator|-
literal|1
decl_stmt|;
name|bool
name|valSeen
init|=
literal|false
decl_stmt|;
name|QRegExp
name|rxValue
argument_list|(
name|QLatin1String
argument_list|(
literal|"^summary: (\\d+)"
argument_list|)
argument_list|)
decl_stmt|;
while|while
condition|(
operator|!
name|file
operator|.
name|atEnd
argument_list|()
condition|)
block|{
specifier|const
name|QString
name|line
argument_list|(
name|QLatin1String
argument_list|(
name|file
operator|.
name|readLine
argument_list|()
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|rxValue
operator|.
name|indexIn
argument_list|(
name|line
argument_list|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|Q_ASSERT
argument_list|(
name|rxValue
operator|.
name|captureCount
argument_list|()
operator|==
literal|1
argument_list|)
expr_stmt|;
name|bool
name|ok
decl_stmt|;
name|val
operator|=
name|rxValue
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toLongLong
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|valSeen
operator|=
literal|true
expr_stmt|;
break|break;
block|}
block|}
name|Q_ASSERT
argument_list|(
name|valSeen
argument_list|)
expr_stmt|;
return|return
name|val
return|;
block|}
end_function
begin_comment
comment|// Gets the newest file name (i.e. the one with the highest integer suffix).
end_comment
begin_function
DECL|function|getNewestFileName
name|QString
name|QBenchmarkValgrindUtils
operator|::
name|getNewestFileName
parameter_list|()
block|{
name|QStringList
name|nameFilters
decl_stmt|;
name|QString
name|base
init|=
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|callgrindOutFileBase
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|base
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|nameFilters
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1.*"
argument_list|)
operator|.
name|arg
argument_list|(
name|base
argument_list|)
expr_stmt|;
name|QFileInfoList
name|fiList
init|=
name|QDir
argument_list|()
operator|.
name|entryInfoList
argument_list|(
name|nameFilters
argument_list|,
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Readable
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|fiList
operator|.
name|empty
argument_list|()
argument_list|)
expr_stmt|;
name|int
name|hiSuffix
init|=
operator|-
literal|1
decl_stmt|;
name|QFileInfo
name|lastFileInfo
decl_stmt|;
specifier|const
name|QString
name|pattern
init|=
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1.(\\d+)"
argument_list|)
operator|.
name|arg
argument_list|(
name|base
argument_list|)
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QFileInfo
name|fileInfo
decl|,
name|fiList
control|)
block|{
specifier|const
name|int
name|index
init|=
name|rx
operator|.
name|indexIn
argument_list|(
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|index
operator|==
literal|0
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|index
argument_list|)
expr_stmt|;
name|bool
name|ok
decl_stmt|;
specifier|const
name|int
name|suffix
init|=
name|rx
operator|.
name|cap
argument_list|(
literal|1
argument_list|)
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|ok
argument_list|)
expr_stmt|;
name|Q_ASSERT
argument_list|(
name|suffix
operator|>=
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|suffix
operator|>
name|hiSuffix
condition|)
block|{
name|lastFileInfo
operator|=
name|fileInfo
expr_stmt|;
name|hiSuffix
operator|=
name|suffix
expr_stmt|;
block|}
block|}
return|return
name|lastFileInfo
operator|.
name|fileName
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|extractLastResult
name|qint64
name|QBenchmarkValgrindUtils
operator|::
name|extractLastResult
parameter_list|()
block|{
return|return
name|extractResult
argument_list|(
name|getNewestFileName
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|QBenchmarkValgrindUtils
operator|::
name|cleanup
parameter_list|()
block|{
name|QStringList
name|nameFilters
decl_stmt|;
name|QString
name|base
init|=
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|callgrindOutFileBase
decl_stmt|;
name|Q_ASSERT
argument_list|(
operator|!
name|base
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|nameFilters
operator|<<
name|base
comment|// overall summary
operator|<<
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"%1.*"
argument_list|)
operator|.
name|arg
argument_list|(
name|base
argument_list|)
expr_stmt|;
comment|// individual dumps
name|QFileInfoList
name|fiList
init|=
name|QDir
argument_list|()
operator|.
name|entryInfoList
argument_list|(
name|nameFilters
argument_list|,
name|QDir
operator|::
name|Files
operator||
name|QDir
operator|::
name|Readable
argument_list|)
decl_stmt|;
foreach|foreach
control|(
name|QFileInfo
name|fileInfo
decl|,
name|fiList
control|)
block|{
specifier|const
name|bool
name|removeOk
init|=
name|QFile
operator|::
name|remove
argument_list|(
name|fileInfo
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|Q_ASSERT
argument_list|(
name|removeOk
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|removeOk
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|outFileBase
name|QString
name|QBenchmarkValgrindUtils
operator|::
name|outFileBase
parameter_list|(
name|qint64
name|pid
parameter_list|)
block|{
return|return
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"callgrind.out.%1"
argument_list|)
operator|.
name|arg
argument_list|(
name|pid
operator|!=
operator|-
literal|1
condition|?
name|pid
else|:
name|QCoreApplication
operator|::
name|applicationPid
argument_list|()
argument_list|)
return|;
block|}
end_function
begin_comment
comment|// Reruns this program through callgrind, storing callgrind result files in the
end_comment
begin_comment
comment|// current directory.
end_comment
begin_comment
comment|// Returns true upon success, otherwise false.
end_comment
begin_function
DECL|function|runCallgrindSubProcess
name|bool
name|QBenchmarkValgrindUtils
operator|::
name|runCallgrindSubProcess
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|origAppArgs
parameter_list|,
name|int
modifier|&
name|exitCode
parameter_list|)
block|{
specifier|const
name|QString
name|execFile
argument_list|(
name|origAppArgs
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|QStringList
name|args
decl_stmt|;
name|args
operator|<<
name|QLatin1String
argument_list|(
literal|"--tool=callgrind"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"--instr-atstart=yes"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"--quiet"
argument_list|)
operator|<<
name|execFile
operator|<<
name|QLatin1String
argument_list|(
literal|"-callgrindchild"
argument_list|)
expr_stmt|;
comment|// pass on original arguments that make sense (e.g. avoid wasting time producing output
comment|// that will be ignored anyway) ...
for|for
control|(
name|int
name|i
init|=
literal|1
init|;
name|i
operator|<
name|origAppArgs
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QString
name|arg
argument_list|(
name|origAppArgs
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|arg
operator|==
name|QLatin1String
argument_list|(
literal|"-callgrind"
argument_list|)
condition|)
continue|continue;
name|args
operator|<<
name|arg
expr_stmt|;
comment|// ok to pass on
block|}
name|QProcess
name|process
decl_stmt|;
name|process
operator|.
name|start
argument_list|(
name|QLatin1String
argument_list|(
literal|"valgrind"
argument_list|)
argument_list|,
name|args
argument_list|)
expr_stmt|;
name|process
operator|.
name|waitForStarted
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QBenchmarkGlobalData
operator|::
name|current
operator|->
name|callgrindOutFileBase
operator|=
name|QBenchmarkValgrindUtils
operator|::
name|outFileBase
argument_list|(
name|process
operator|.
name|pid
argument_list|()
argument_list|)
expr_stmt|;
specifier|const
name|bool
name|finishedOk
init|=
name|process
operator|.
name|waitForFinished
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
name|exitCode
operator|=
name|process
operator|.
name|exitCode
argument_list|()
expr_stmt|;
name|dumpOutput
argument_list|(
name|process
operator|.
name|readAllStandardOutput
argument_list|()
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|dumpOutput
argument_list|(
name|process
operator|.
name|readAllStandardError
argument_list|()
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
return|return
name|finishedOk
return|;
block|}
end_function
begin_function
DECL|function|start
name|void
name|QBenchmarkCallgrindMeasurer
operator|::
name|start
parameter_list|()
block|{
name|CALLGRIND_ZERO_STATS
expr_stmt|;
block|}
end_function
begin_function
DECL|function|checkpoint
name|qint64
name|QBenchmarkCallgrindMeasurer
operator|::
name|checkpoint
parameter_list|()
block|{
name|CALLGRIND_DUMP_STATS
expr_stmt|;
specifier|const
name|qint64
name|result
init|=
name|QBenchmarkValgrindUtils
operator|::
name|extractLastResult
argument_list|()
decl_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|stop
name|qint64
name|QBenchmarkCallgrindMeasurer
operator|::
name|stop
parameter_list|()
block|{
return|return
name|checkpoint
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|isMeasurementAccepted
name|bool
name|QBenchmarkCallgrindMeasurer
operator|::
name|isMeasurementAccepted
parameter_list|(
name|qint64
name|measurement
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|measurement
argument_list|)
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|adjustIterationCount
name|int
name|QBenchmarkCallgrindMeasurer
operator|::
name|adjustIterationCount
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|adjustMedianCount
name|int
name|QBenchmarkCallgrindMeasurer
operator|::
name|adjustMedianCount
parameter_list|(
name|int
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function
begin_function
DECL|function|needsWarmupIteration
name|bool
name|QBenchmarkCallgrindMeasurer
operator|::
name|needsWarmupIteration
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|metricType
name|QTest
operator|::
name|QBenchmarkMetric
name|QBenchmarkCallgrindMeasurer
operator|::
name|metricType
parameter_list|()
block|{
return|return
name|QTest
operator|::
name|InstructionReads
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QTESTLIB_USE_VALGRIND
end_comment
end_unit
