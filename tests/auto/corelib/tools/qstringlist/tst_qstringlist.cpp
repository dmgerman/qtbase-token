begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|<qregularexpression.h>
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<locale.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_WINCE
end_ifdef
begin_include
include|#
directive|include
file|<windows.h>
end_include
begin_comment
comment|// needed for GetUserDefaultLCID
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_class
DECL|class|tst_QStringList
class|class
name|tst_QStringList
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|sort
parameter_list|()
function_decl|;
name|void
name|filter
parameter_list|()
function_decl|;
name|void
name|replaceInStrings
parameter_list|()
function_decl|;
name|void
name|removeDuplicates
parameter_list|()
function_decl|;
name|void
name|removeDuplicates_data
parameter_list|()
function_decl|;
name|void
name|contains
parameter_list|()
function_decl|;
name|void
name|indexOf
parameter_list|()
function_decl|;
name|void
name|lastIndexOf
parameter_list|()
function_decl|;
name|void
name|indexOf_regExp
parameter_list|()
function_decl|;
name|void
name|lastIndexOf_regExp
parameter_list|()
function_decl|;
name|void
name|streamingOperator
parameter_list|()
function_decl|;
name|void
name|assignmentOperator
parameter_list|()
function_decl|;
name|void
name|join
parameter_list|()
specifier|const
function_decl|;
name|void
name|join_data
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinEmptiness
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinChar
parameter_list|()
specifier|const
function_decl|;
name|void
name|joinChar_data
parameter_list|()
specifier|const
function_decl|;
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
name|void
name|initializeList
parameter_list|()
specifier|const
function_decl|;
endif|#
directive|endif
block|}
class|;
end_class
begin_decl_stmt
specifier|extern
specifier|const
name|char
name|email
index|[]
decl_stmt|;
end_decl_stmt
begin_function
DECL|function|indexOf_regExp
name|void
name|tst_QStringList
operator|::
name|indexOf_regExp
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"harald"
operator|<<
literal|"trond"
operator|<<
literal|"vohi"
operator|<<
literal|"harald"
expr_stmt|;
block|{
name|QRegExp
name|re
argument_list|(
literal|".*o.*"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
literal|2
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
literal|3
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|QRegExp
argument_list|(
literal|".*x.*"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|3
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|9999
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
literal|9999
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|QRegExp
argument_list|(
literal|"[aeiou]"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|{
name|QRegularExpression
name|re
argument_list|(
literal|".*o.*"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
literal|2
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
literal|3
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|QRegularExpression
argument_list|(
literal|".*x.*"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|3
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|9999
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|re
argument_list|,
literal|9999
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
name|QRegularExpression
argument_list|(
literal|"[aeiou]"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|lastIndexOf_regExp
name|void
name|tst_QStringList
operator|::
name|lastIndexOf_regExp
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"harald"
operator|<<
literal|"trond"
operator|<<
literal|"vohi"
operator|<<
literal|"harald"
expr_stmt|;
block|{
name|QRegExp
name|re
argument_list|(
literal|".*o.*"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
literal|2
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
literal|1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|QRegExp
argument_list|(
literal|".*x.*"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|3
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|9999
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
literal|9999
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|QRegExp
argument_list|(
literal|"[aeiou]"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|{
name|QRegularExpression
name|re
argument_list|(
literal|".*o.*"
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
literal|2
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
literal|1
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|QRegularExpression
argument_list|(
literal|".*x.*"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|3
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
operator|-
literal|9999
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|re
argument_list|,
literal|9999
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
name|QRegularExpression
argument_list|(
literal|"[aeiou]"
argument_list|)
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|indexOf
name|void
name|tst_QStringList
operator|::
name|indexOf
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"harald"
operator|<<
literal|"trond"
operator|<<
literal|"vohi"
operator|<<
literal|"harald"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"harald"
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"trond"
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"vohi"
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"harald"
argument_list|,
literal|1
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"hans"
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"trond"
argument_list|,
literal|2
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"harald"
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|indexOf
argument_list|(
literal|"vohi"
argument_list|,
operator|-
literal|3
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|lastIndexOf
name|void
name|tst_QStringList
operator|::
name|lastIndexOf
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"harald"
operator|<<
literal|"trond"
operator|<<
literal|"vohi"
operator|<<
literal|"harald"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"harald"
argument_list|)
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"trond"
argument_list|)
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"vohi"
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"harald"
argument_list|,
literal|2
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"hans"
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"vohi"
argument_list|,
literal|1
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"vohi"
argument_list|,
operator|-
literal|1
argument_list|)
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
operator|.
name|lastIndexOf
argument_list|(
literal|"vohi"
argument_list|,
operator|-
literal|3
argument_list|)
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|filter
name|void
name|tst_QStringList
operator|::
name|filter
parameter_list|()
block|{
name|QStringList
name|list1
decl_stmt|,
name|list2
decl_stmt|;
name|list1
operator|<<
literal|"Bill Gates"
operator|<<
literal|"Joe Blow"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
name|list1
operator|=
name|list1
operator|.
name|filter
argument_list|(
literal|"Bill"
argument_list|)
expr_stmt|;
name|list2
operator|<<
literal|"Bill Gates"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list1
argument_list|,
name|list2
argument_list|)
expr_stmt|;
name|QStringList
name|list3
decl_stmt|,
name|list4
decl_stmt|;
name|list3
operator|<<
literal|"Bill Gates"
operator|<<
literal|"Joe Blow"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
name|list3
operator|=
name|list3
operator|.
name|filter
argument_list|(
name|QRegExp
argument_list|(
literal|"[i]ll"
argument_list|)
argument_list|)
expr_stmt|;
name|list4
operator|<<
literal|"Bill Gates"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list3
argument_list|,
name|list4
argument_list|)
expr_stmt|;
name|QStringList
name|list5
decl_stmt|,
name|list6
decl_stmt|;
name|list5
operator|<<
literal|"Bill Gates"
operator|<<
literal|"Joe Blow"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
name|list5
operator|=
name|list5
operator|.
name|filter
argument_list|(
name|QRegularExpression
argument_list|(
literal|"[i]ll"
argument_list|)
argument_list|)
expr_stmt|;
name|list6
operator|<<
literal|"Bill Gates"
operator|<<
literal|"Bill Clinton"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list5
argument_list|,
name|list6
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|sort
name|void
name|tst_QStringList
operator|::
name|sort
parameter_list|()
block|{
name|QStringList
name|list1
decl_stmt|,
name|list2
decl_stmt|;
name|list1
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"BETA"
operator|<<
literal|"gamma"
operator|<<
literal|"Gamma"
operator|<<
literal|"gAmma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list1
operator|.
name|sort
argument_list|()
expr_stmt|;
name|list2
operator|<<
literal|"BETA"
operator|<<
literal|"Gamma"
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"epsilon"
operator|<<
literal|"gAmma"
operator|<<
literal|"gamma"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list1
argument_list|,
name|list2
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|DWORD
name|oldLcid
init|=
name|GetUserDefaultLCID
argument_list|()
decl_stmt|;
comment|// Assume c locale to be english
name|SetUserDefaultLCID
argument_list|(
name|MAKELCID
argument_list|(
name|MAKELANGID
argument_list|(
name|LANG_ENGLISH
argument_list|,
name|SUBLANG_ENGLISH_US
argument_list|)
argument_list|,
name|SORT_DEFAULT
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|char
modifier|*
name|current_locale
init|=
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
literal|"C"
argument_list|)
decl_stmt|;
endif|#
directive|endif
name|QStringList
name|list3
decl_stmt|,
name|list4
decl_stmt|;
name|list3
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"BETA"
operator|<<
literal|"gamma"
operator|<<
literal|"Gamma"
operator|<<
literal|"gAmma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list3
operator|.
name|sort
argument_list|(
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
name|list4
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"BETA"
operator|<<
literal|"epsilon"
operator|<<
literal|"Gamma"
operator|<<
literal|"gAmma"
operator|<<
literal|"gamma"
expr_stmt|;
comment|// with this list, case insensitive sorting can give more than one permutation for "equivalent"
comment|// elements; so we check that the sort gave the formally correct result (list[i]<= list[i+1])
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|list4
operator|.
name|count
argument_list|()
operator|-
literal|1
condition|;
operator|++
name|i
control|)
name|QVERIFY2
argument_list|(
name|QString
operator|::
name|compare
argument_list|(
name|list4
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|list4
operator|.
name|at
argument_list|(
name|i
operator|+
literal|1
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
operator|<=
literal|0
argument_list|,
name|qPrintable
argument_list|(
name|QString
argument_list|(
literal|"index %1 failed"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
comment|// additional checks
name|QCOMPARE
argument_list|(
name|list4
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"alpha"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list4
operator|.
name|indexOf
argument_list|(
literal|"epsilon"
argument_list|)
operator|>
literal|0
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list4
operator|.
name|indexOf
argument_list|(
literal|"epsilon"
argument_list|)
operator|<
operator|(
name|list4
operator|.
name|count
argument_list|()
operator|-
literal|1
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WINCE
name|SetUserDefaultLCID
argument_list|(
name|oldLcid
argument_list|)
expr_stmt|;
else|#
directive|else
name|setlocale
argument_list|(
name|LC_ALL
argument_list|,
name|current_locale
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|replaceInStrings
name|void
name|tst_QStringList
operator|::
name|replaceInStrings
parameter_list|()
block|{
name|QStringList
name|list1
decl_stmt|,
name|list2
decl_stmt|;
name|list1
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list1
operator|.
name|replaceInStrings
argument_list|(
literal|"a"
argument_list|,
literal|"o"
argument_list|)
expr_stmt|;
name|list2
operator|<<
literal|"olpho"
operator|<<
literal|"beto"
operator|<<
literal|"gommo"
operator|<<
literal|"epsilon"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list1
argument_list|,
name|list2
argument_list|)
expr_stmt|;
name|QStringList
name|list3
decl_stmt|,
name|list4
decl_stmt|;
name|list3
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list3
operator|.
name|replaceInStrings
argument_list|(
name|QRegExp
argument_list|(
literal|"^a"
argument_list|)
argument_list|,
literal|"o"
argument_list|)
expr_stmt|;
name|list4
operator|<<
literal|"olpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list3
argument_list|,
name|list4
argument_list|)
expr_stmt|;
name|QStringList
name|list5
decl_stmt|,
name|list6
decl_stmt|;
name|list5
operator|<<
literal|"Bill Clinton"
operator|<<
literal|"Gates, Bill"
expr_stmt|;
name|list6
operator|<<
literal|"Bill Clinton"
operator|<<
literal|"Bill Gates"
expr_stmt|;
name|list5
operator|.
name|replaceInStrings
argument_list|(
name|QRegExp
argument_list|(
literal|"^(.*), (.*)$"
argument_list|)
argument_list|,
literal|"\\2 \\1"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list5
argument_list|,
name|list6
argument_list|)
expr_stmt|;
name|QStringList
name|list7
decl_stmt|,
name|list8
decl_stmt|;
name|list7
operator|<<
literal|"alpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|list7
operator|.
name|replaceInStrings
argument_list|(
name|QRegularExpression
argument_list|(
literal|"^a"
argument_list|)
argument_list|,
literal|"o"
argument_list|)
expr_stmt|;
name|list8
operator|<<
literal|"olpha"
operator|<<
literal|"beta"
operator|<<
literal|"gamma"
operator|<<
literal|"epsilon"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list7
argument_list|,
name|list8
argument_list|)
expr_stmt|;
name|QStringList
name|list9
decl_stmt|,
name|list10
decl_stmt|;
name|list9
operator|<<
literal|"Bill Clinton"
operator|<<
literal|"Gates, Bill"
expr_stmt|;
name|list10
operator|<<
literal|"Bill Clinton"
operator|<<
literal|"Bill Gates"
expr_stmt|;
name|list9
operator|.
name|replaceInStrings
argument_list|(
name|QRegularExpression
argument_list|(
literal|"^(.*), (.*)$"
argument_list|)
argument_list|,
literal|"\\2 \\1"
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list9
argument_list|,
name|list10
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|contains
name|void
name|tst_QStringList
operator|::
name|contains
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"arthur"
operator|<<
literal|"Arthur"
operator|<<
literal|"arthuR"
operator|<<
literal|"ARTHUR"
operator|<<
literal|"Dent"
operator|<<
literal|"Hans Dent"
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"arthur"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|list
operator|.
name|contains
argument_list|(
literal|"ArthuR"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|list
operator|.
name|contains
argument_list|(
literal|"Hans"
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"arthur"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"ArthuR"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"ARTHUR"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|list
operator|.
name|contains
argument_list|(
literal|"dent"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|list
operator|.
name|contains
argument_list|(
literal|"hans"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeDuplicates_data
name|void
name|tst_QStringList
operator|::
name|removeDuplicates_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"before"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"after"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"count"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"detached"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty-1"
argument_list|)
operator|<<
literal|"Hello,Hello"
operator|<<
literal|"Hello"
operator|<<
literal|1
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty-2"
argument_list|)
operator|<<
literal|"Hello,World"
operator|<<
literal|"Hello,World"
operator|<<
literal|0
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"middle"
argument_list|)
operator|<<
literal|"Hello,World,Hello"
operator|<<
literal|"Hello,World"
operator|<<
literal|1
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|removeDuplicates
name|void
name|tst_QStringList
operator|::
name|removeDuplicates
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|before
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|after
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|detached
argument_list|)
expr_stmt|;
name|QStringList
name|lbefore
init|=
name|before
operator|.
name|split
argument_list|(
literal|','
argument_list|)
decl_stmt|;
specifier|const
name|QStringList
name|oldlbefore
init|=
name|lbefore
decl_stmt|;
name|QStringList
name|lafter
init|=
name|after
operator|.
name|split
argument_list|(
literal|','
argument_list|)
decl_stmt|;
name|int
name|removed
init|=
name|lbefore
operator|.
name|removeDuplicates
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|removed
argument_list|,
name|count
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|lbefore
argument_list|,
name|lafter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|detached
argument_list|,
operator|!
name|oldlbefore
operator|.
name|isSharedWith
argument_list|(
name|lbefore
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|streamingOperator
name|void
name|tst_QStringList
operator|::
name|streamingOperator
parameter_list|()
block|{
name|QStringList
name|list
decl_stmt|;
name|list
operator|<<
literal|"hei"
expr_stmt|;
name|list
operator|<<
name|list
operator|<<
literal|"hopp"
operator|<<
name|list
expr_stmt|;
name|QList
argument_list|<
name|QString
argument_list|>
name|slist
init|=
name|list
decl_stmt|;
name|list
operator|<<
name|slist
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"hei"
operator|<<
literal|"hei"
operator|<<
literal|"hopp"
operator|<<
literal|"hei"
operator|<<
literal|"hei"
operator|<<
literal|"hopp"
operator|<<
literal|"hei"
operator|<<
literal|"hei"
operator|<<
literal|"hopp"
operator|<<
literal|"hei"
operator|<<
literal|"hei"
operator|<<
literal|"hopp"
argument_list|)
expr_stmt|;
name|QStringList
name|list2
decl_stmt|;
name|list2
operator|<<
literal|"adam"
expr_stmt|;
name|QStringList
name|list3
decl_stmt|;
name|list3
operator|<<
literal|"eva"
expr_stmt|;
name|QCOMPARE
argument_list|(
name|list2
operator|<<
name|list3
argument_list|,
name|QStringList
argument_list|()
operator|<<
literal|"adam"
operator|<<
literal|"eva"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|assignmentOperator
name|void
name|tst_QStringList
operator|::
name|assignmentOperator
parameter_list|()
block|{
comment|// compile-only test
name|QStringList
name|adam
decl_stmt|;
name|adam
operator|<<
literal|"adam"
expr_stmt|;
name|QList
argument_list|<
name|QString
argument_list|>
name|eva
decl_stmt|;
name|eva
operator|<<
literal|"eva"
expr_stmt|;
name|QStringList
name|result
decl_stmt|;
name|QStringList
modifier|&
name|ref1
init|=
operator|(
name|result
operator|=
name|adam
operator|)
decl_stmt|;
name|QStringList
modifier|&
name|ref2
init|=
operator|(
name|result
operator|=
name|eva
operator|)
decl_stmt|;
name|Q_UNUSED
argument_list|(
name|ref1
argument_list|)
expr_stmt|;
name|Q_UNUSED
argument_list|(
name|ref2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|join
name|void
name|tst_QStringList
operator|::
name|join
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|separator
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input
operator|.
name|join
argument_list|(
name|separator
argument_list|)
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|join_data
name|void
name|tst_QStringList
operator|::
name|join_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"separator"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expectedResult"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QStringList
argument_list|()
operator|<<
name|QString
argument_list|()
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data2"
argument_list|)
operator|<<
name|QStringList
argument_list|()
operator|<<
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data3"
argument_list|)
operator|<<
name|QStringList
argument_list|(
literal|"one"
argument_list|)
operator|<<
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data4"
argument_list|)
operator|<<
name|QStringList
argument_list|(
literal|"one"
argument_list|)
operator|<<
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|"separator"
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data5"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"a"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"b"
argument_list|)
operator|)
operator|<<
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"a b"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data6"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"a"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"b"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"c"
argument_list|)
operator|)
operator|<<
name|QString
argument_list|(
name|QLatin1String
argument_list|(
literal|" "
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"a b c"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinChar
name|void
name|tst_QStringList
operator|::
name|joinChar
parameter_list|()
specifier|const
block|{
name|QFETCH
argument_list|(
name|QStringList
argument_list|,
name|input
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QChar
argument_list|,
name|separator
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|input
operator|.
name|join
argument_list|(
name|separator
argument_list|)
argument_list|,
name|expectedResult
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinChar_data
name|void
name|tst_QStringList
operator|::
name|joinChar_data
parameter_list|()
specifier|const
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QStringList
argument_list|>
argument_list|(
literal|"input"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QChar
argument_list|>
argument_list|(
literal|"separator"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expectedResult"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data1"
argument_list|)
operator|<<
name|QStringList
argument_list|()
operator|<<
name|QChar
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data5"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"a"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"b"
argument_list|)
operator|)
operator|<<
name|QChar
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"a b"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"data6"
argument_list|)
operator|<<
operator|(
name|QStringList
argument_list|()
operator|<<
name|QLatin1String
argument_list|(
literal|"a"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"b"
argument_list|)
operator|<<
name|QLatin1String
argument_list|(
literal|"c"
argument_list|)
operator|)
operator|<<
name|QChar
argument_list|(
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
argument_list|)
operator|<<
name|QString
argument_list|(
literal|"a b c"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|joinEmptiness
name|void
name|tst_QStringList
operator|::
name|joinEmptiness
parameter_list|()
specifier|const
block|{
name|QStringList
name|list
decl_stmt|;
name|QString
name|string
init|=
name|list
operator|.
name|join
argument_list|(
name|QString
argument_list|()
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|string
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|string
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_ifdef
ifdef|#
directive|ifdef
name|Q_COMPILER_INITIALIZER_LISTS
end_ifdef
begin_comment
comment|// C++0x support is required
end_comment
begin_function
DECL|function|initializeList
name|void
name|tst_QStringList
operator|::
name|initializeList
parameter_list|()
specifier|const
block|{
name|QStringList
name|v1
argument_list|{
name|QLatin1String
argument_list|(
literal|"hello"
argument_list|)
argument_list|,
literal|"world"
argument_list|,
name|QString
operator|::
name|fromLatin1
operator|(
literal|"plop"
operator|)
argument_list|}
decl_stmt|;
name|QCOMPARE
argument_list|(
name|v1
argument_list|,
operator|(
name|QStringList
argument_list|()
operator|<<
literal|"hello"
operator|<<
literal|"world"
operator|<<
literal|"plop"
operator|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|v1
argument_list|,
operator|(
name|QStringList
block|{
literal|"hello"
block|,
literal|"world"
block|,
literal|"plop"
block|}
operator|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QStringList
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qstringlist.moc"
end_include
end_unit
