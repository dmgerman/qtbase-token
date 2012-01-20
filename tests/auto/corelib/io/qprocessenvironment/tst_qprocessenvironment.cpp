begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_include
include|#
directive|include
file|<QObject>
end_include
begin_include
include|#
directive|include
file|<QProcessEnvironment>
end_include
begin_class
DECL|class|tst_QProcessEnvironment
class|class
name|tst_QProcessEnvironment
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|operator_eq
parameter_list|()
function_decl|;
name|void
name|clearAndIsEmpty
parameter_list|()
function_decl|;
name|void
name|insert
parameter_list|()
function_decl|;
name|void
name|emptyNull
parameter_list|()
function_decl|;
name|void
name|toStringList
parameter_list|()
function_decl|;
name|void
name|keys
parameter_list|()
function_decl|;
name|void
name|insertEnv
parameter_list|()
function_decl|;
name|void
name|caseSensitivity
parameter_list|()
function_decl|;
name|void
name|systemEnvironment
parameter_list|()
function_decl|;
name|void
name|putenv
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|operator_eq
name|void
name|tst_QProcessEnvironment
operator|::
name|operator_eq
parameter_list|()
block|{
name|QProcessEnvironment
name|e1
decl_stmt|;
name|QVERIFY
argument_list|(
name|e1
operator|==
name|e1
argument_list|)
expr_stmt|;
name|e1
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|e1
operator|==
name|e1
argument_list|)
expr_stmt|;
name|e1
operator|=
name|QProcessEnvironment
argument_list|()
expr_stmt|;
name|QProcessEnvironment
name|e2
decl_stmt|;
name|QVERIFY
argument_list|(
name|e1
operator|==
name|e2
argument_list|)
expr_stmt|;
name|e1
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|e1
operator|!=
name|e2
argument_list|)
expr_stmt|;
name|e2
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|e1
operator|==
name|e2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|clearAndIsEmpty
name|void
name|tst_QProcessEnvironment
operator|::
name|clearAndIsEmpty
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|e
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insert
name|void
name|tst_QProcessEnvironment
operator|::
name|insert
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
name|e
operator|.
name|remove
argument_list|(
literal|"FOO"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|e
operator|.
name|clear
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|emptyNull
name|void
name|tst_QProcessEnvironment
operator|::
name|emptyNull
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// don't test if it's NULL, since we shall not make a guarantee
name|e
operator|.
name|remove
argument_list|(
literal|"FOO"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|toStringList
name|void
name|tst_QProcessEnvironment
operator|::
name|toStringList
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|toStringList
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|QStringList
name|result
init|=
name|e
operator|.
name|toStringList
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|result
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|length
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"FOO=bar"
argument_list|)
argument_list|)
expr_stmt|;
name|e
operator|.
name|clear
argument_list|()
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"BAZ"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|result
operator|=
name|e
operator|.
name|toStringList
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"BAZ="
argument_list|)
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"A"
argument_list|,
literal|"bc"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"HELLO"
argument_list|,
literal|"World"
argument_list|)
expr_stmt|;
name|result
operator|=
name|e
operator|.
name|toStringList
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|length
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// order is not specified, so use contains()
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"FOO=bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"BAZ="
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"A=bc"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"HELLO=World"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keys
name|void
name|tst_QProcessEnvironment
operator|::
name|keys
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|keys
argument_list|()
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|QStringList
name|result
init|=
name|e
operator|.
name|keys
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|length
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|e
operator|.
name|clear
argument_list|()
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"BAZ"
argument_list|,
literal|""
argument_list|)
expr_stmt|;
name|result
operator|=
name|e
operator|.
name|keys
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"BAZ"
argument_list|)
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"A"
argument_list|,
literal|"bc"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"HELLO"
argument_list|,
literal|"World"
argument_list|)
expr_stmt|;
name|result
operator|=
name|e
operator|.
name|keys
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|result
operator|.
name|length
argument_list|()
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// order is not specified, so use contains()
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"BAZ"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"A"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|result
operator|.
name|contains
argument_list|(
literal|"HELLO"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|insertEnv
name|void
name|tst_QProcessEnvironment
operator|::
name|insertEnv
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"A"
argument_list|,
literal|"bc"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"Hello"
argument_list|,
literal|"World"
argument_list|)
expr_stmt|;
name|QProcessEnvironment
name|e2
decl_stmt|;
name|e2
operator|.
name|insert
argument_list|(
literal|"FOO2"
argument_list|,
literal|"bar2"
argument_list|)
expr_stmt|;
name|e2
operator|.
name|insert
argument_list|(
literal|"A2"
argument_list|,
literal|"bc2"
argument_list|)
expr_stmt|;
name|e2
operator|.
name|insert
argument_list|(
literal|"Hello"
argument_list|,
literal|"Another World"
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
name|e2
argument_list|)
expr_stmt|;
name|QStringList
name|keys
init|=
name|e
operator|.
name|keys
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|keys
operator|.
name|length
argument_list|()
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"A"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bc"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"Hello"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"Another World"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO2"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar2"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"A2"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bc2"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|caseSensitivity
name|void
name|tst_QProcessEnvironment
operator|::
name|caseSensitivity
parameter_list|()
block|{
name|QProcessEnvironment
name|e
decl_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"foo"
argument_list|,
literal|"bar"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// Windows is case-insensitive, but case-preserving
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"FoO"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"foo"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FoO"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
comment|// Per Windows, this overwrites the value, but keeps the name's original capitalization
name|e
operator|.
name|insert
argument_list|(
literal|"Foo"
argument_list|,
literal|"Bar"
argument_list|)
expr_stmt|;
name|QStringList
name|list
init|=
name|e
operator|.
name|toStringList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|length
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"foo=Bar"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// otherwise, it's case sensitive
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"foo"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|e
operator|.
name|insert
argument_list|(
literal|"FOO"
argument_list|,
literal|"baz"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|e
operator|.
name|contains
argument_list|(
literal|"FOO"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"FOO"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"baz"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|e
operator|.
name|value
argument_list|(
literal|"foo"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QStringList
name|list
init|=
name|e
operator|.
name|toStringList
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|length
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"foo=bar"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"FOO=baz"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|systemEnvironment
name|void
name|tst_QProcessEnvironment
operator|::
name|systemEnvironment
parameter_list|()
block|{
specifier|static
specifier|const
name|char
name|envname
index|[]
init|=
literal|"THIS_ENVIRONMENT_VARIABLE_HOPEFULLY_DOESNT_EXIST"
decl_stmt|;
name|QByteArray
name|path
init|=
name|qgetenv
argument_list|(
literal|"PATH"
argument_list|)
decl_stmt|;
name|QByteArray
name|nonexistant
init|=
name|qgetenv
argument_list|(
name|envname
argument_list|)
decl_stmt|;
name|QProcessEnvironment
name|system
init|=
name|QProcessEnvironment
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
name|nonexistant
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
comment|// Windows CE has no environment
name|QVERIFY
argument_list|(
name|path
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|system
operator|.
name|contains
argument_list|(
literal|"PATH"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|system
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
else|#
directive|else
comment|// all other system have environments
if|if
condition|(
name|path
operator|.
name|isEmpty
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"Could not find the PATH environment variable -- please correct the test environment"
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|system
operator|.
name|contains
argument_list|(
literal|"PATH"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|system
operator|.
name|value
argument_list|(
literal|"PATH"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|system
operator|.
name|contains
argument_list|(
name|envname
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// check case-insensitive too
name|QVERIFY
argument_list|(
name|system
operator|.
name|contains
argument_list|(
literal|"path"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|system
operator|.
name|value
argument_list|(
literal|"path"
argument_list|)
argument_list|,
name|QString
operator|::
name|fromLocal8Bit
argument_list|(
name|path
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|system
operator|.
name|contains
argument_list|(
name|QString
argument_list|(
name|envname
argument_list|)
operator|.
name|toLower
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|putenv
name|void
name|tst_QProcessEnvironment
operator|::
name|putenv
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|QSKIP
argument_list|(
literal|"Windows CE has no environment"
argument_list|)
expr_stmt|;
else|#
directive|else
specifier|static
specifier|const
name|char
name|envname
index|[]
init|=
literal|"WE_RE_SETTING_THIS_ENVIRONMENT_VARIABLE"
decl_stmt|;
specifier|static
name|bool
name|testRan
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|testRan
condition|)
name|QFAIL
argument_list|(
literal|"You cannot run this test more than once, since we modify the environment"
argument_list|)
expr_stmt|;
name|testRan
operator|=
literal|true
expr_stmt|;
name|QByteArray
name|valBefore
init|=
name|qgetenv
argument_list|(
name|envname
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|valBefore
operator|.
name|isNull
argument_list|()
condition|)
name|QFAIL
argument_list|(
literal|"The environment variable we set in the environment is already set! -- please correct the test environment"
argument_list|)
expr_stmt|;
name|QProcessEnvironment
name|eBefore
init|=
name|QProcessEnvironment
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
name|qputenv
argument_list|(
name|envname
argument_list|,
literal|"Hello, World"
argument_list|)
expr_stmt|;
name|QByteArray
name|valAfter
init|=
name|qgetenv
argument_list|(
name|envname
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|valAfter
argument_list|,
name|QByteArray
argument_list|(
literal|"Hello, World"
argument_list|)
argument_list|)
expr_stmt|;
name|QProcessEnvironment
name|eAfter
init|=
name|QProcessEnvironment
operator|::
name|systemEnvironment
argument_list|()
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|eBefore
operator|.
name|contains
argument_list|(
name|envname
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|eAfter
operator|.
name|contains
argument_list|(
name|envname
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|eAfter
operator|.
name|value
argument_list|(
name|envname
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"Hello, World"
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// check case-insensitive too
name|QString
name|lower
init|=
name|envname
decl_stmt|;
name|lower
operator|=
name|lower
operator|.
name|toLower
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|eBefore
operator|.
name|contains
argument_list|(
name|lower
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|eAfter
operator|.
name|contains
argument_list|(
name|lower
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|eAfter
operator|.
name|value
argument_list|(
name|lower
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"Hello, World"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QProcessEnvironment
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qprocessenvironment.moc"
end_include
end_unit
