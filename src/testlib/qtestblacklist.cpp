begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtestblacklist_p.h"
end_include
begin_include
include|#
directive|include
file|"qtestresult_p.h"
end_include
begin_include
include|#
directive|include
file|<QtTest/qtestcase.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qfile.h>
end_include
begin_include
include|#
directive|include
file|<set>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|/*  The file format is simply a grouped listing of keywords  Ungrouped entries at the beginning apply to the whole testcase  Groups define testfunctions or specific test data to ignore.  After the groups come a list of entries (one per line) that define  for which platform/os combination to ignore the test result.  All keys in a single line have to match to blacklist the test.   mac  [testFunction]  linux  windows 64bit  [testfunction2:testData]  msvc   The known keys are listed below: */
comment|// this table can be extended with new keywords as required
DECL|variable|matchedConditions
specifier|const
name|char
modifier|*
name|matchedConditions
index|[]
init|=
block|{
literal|"*"
block|,
ifdef|#
directive|ifdef
name|Q_OS_LINUX
literal|"linux"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_OSX
literal|"osx"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WIN
literal|"windows"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_IOS
literal|"ios"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_ANDROID
literal|"android"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_QNX
literal|"qnx"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINRT
literal|"winrt"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_OS_WINCE
literal|"wince"
block|,
endif|#
directive|endif
if|#
directive|if
name|QT_POINTER_SIZE
operator|==
literal|8
literal|"64bit"
block|,
else|#
directive|else
literal|"32bit"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_CC_GNU
literal|"gcc"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_CC_CLANG
literal|"clang"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_CC_MSVC
literal|"msvc"
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|Q_AUTOTEST_EXPORT
literal|"developer-build"
block|,
endif|#
directive|endif
literal|0
block|}
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|checkCondition
specifier|static
name|bool
name|checkCondition
parameter_list|(
specifier|const
name|QByteArray
modifier|&
name|condition
parameter_list|)
block|{
name|QList
argument_list|<
name|QByteArray
argument_list|>
name|conds
init|=
name|condition
operator|.
name|split
argument_list|(
literal|' '
argument_list|)
decl_stmt|;
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
name|matches
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|m
init|=
name|matchedConditions
decl_stmt|;
while|while
condition|(
operator|*
name|m
condition|)
block|{
name|matches
operator|.
name|insert
argument_list|(
operator|*
name|m
argument_list|)
expr_stmt|;
operator|++
name|m
expr_stmt|;
block|}
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|conds
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QByteArray
name|c
init|=
name|conds
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|bool
name|result
init|=
name|c
operator|.
name|startsWith
argument_list|(
literal|'!'
argument_list|)
decl_stmt|;
if|if
condition|(
name|result
condition|)
name|c
operator|=
name|c
operator|.
name|mid
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|result
operator|^=
operator|(
name|matches
operator|.
name|find
argument_list|(
name|c
argument_list|)
operator|!=
name|matches
operator|.
name|end
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|result
condition|)
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_decl_stmt
DECL|variable|ignoreAll
specifier|static
name|bool
name|ignoreAll
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|ignoredTests
specifier|static
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
modifier|*
name|ignoredTests
init|=
literal|0
decl_stmt|;
end_decl_stmt
begin_namespace
DECL|namespace|QTestPrivate
namespace|namespace
name|QTestPrivate
block|{
DECL|function|parseBlackList
name|void
name|parseBlackList
parameter_list|()
block|{
name|QString
name|filename
init|=
name|QTest
operator|::
name|qFindTestData
argument_list|(
name|QStringLiteral
argument_list|(
literal|"BLACKLIST"
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|filename
operator|.
name|isEmpty
argument_list|()
condition|)
return|return;
name|QFile
name|ignored
argument_list|(
name|filename
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|ignored
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
condition|)
return|return;
name|QByteArray
name|function
decl_stmt|;
while|while
condition|(
operator|!
name|ignored
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|QByteArray
name|line
init|=
name|ignored
operator|.
name|readLine
argument_list|()
operator|.
name|simplified
argument_list|()
decl_stmt|;
if|if
condition|(
name|line
operator|.
name|isEmpty
argument_list|()
operator|||
name|line
operator|.
name|startsWith
argument_list|(
literal|'#'
argument_list|)
condition|)
continue|continue;
if|if
condition|(
name|line
operator|.
name|startsWith
argument_list|(
literal|'['
argument_list|)
condition|)
block|{
name|function
operator|=
name|line
operator|.
name|mid
argument_list|(
literal|1
argument_list|,
name|line
operator|.
name|length
argument_list|()
operator|-
literal|2
argument_list|)
expr_stmt|;
continue|continue;
block|}
name|bool
name|condition
init|=
name|checkCondition
argument_list|(
name|line
argument_list|)
decl_stmt|;
if|if
condition|(
name|condition
condition|)
block|{
if|if
condition|(
operator|!
name|function
operator|.
name|size
argument_list|()
condition|)
block|{
name|ignoreAll
operator|=
literal|true
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|!
name|ignoredTests
condition|)
name|ignoredTests
operator|=
operator|new
name|std
operator|::
name|set
argument_list|<
name|QByteArray
argument_list|>
expr_stmt|;
name|ignoredTests
operator|->
name|insert
argument_list|(
name|function
argument_list|)
expr_stmt|;
block|}
block|}
block|}
block|}
DECL|function|checkBlackList
name|void
name|checkBlackList
parameter_list|(
specifier|const
name|char
modifier|*
name|slot
parameter_list|,
specifier|const
name|char
modifier|*
name|data
parameter_list|)
block|{
name|bool
name|ignore
init|=
name|ignoreAll
decl_stmt|;
if|if
condition|(
operator|!
name|ignore
operator|&&
name|ignoredTests
condition|)
block|{
name|QByteArray
name|s
init|=
name|slot
decl_stmt|;
name|ignore
operator|=
operator|(
name|ignoredTests
operator|->
name|find
argument_list|(
name|s
argument_list|)
operator|!=
name|ignoredTests
operator|->
name|end
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|ignore
operator|&&
name|data
condition|)
block|{
name|s
operator|+=
literal|':'
expr_stmt|;
name|s
operator|+=
name|data
expr_stmt|;
name|ignore
operator|=
operator|(
name|ignoredTests
operator|->
name|find
argument_list|(
name|s
argument_list|)
operator|!=
name|ignoredTests
operator|->
name|end
argument_list|()
operator|)
expr_stmt|;
block|}
block|}
name|QTestResult
operator|::
name|setBlacklistCurrentTest
argument_list|(
name|ignore
argument_list|)
expr_stmt|;
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
