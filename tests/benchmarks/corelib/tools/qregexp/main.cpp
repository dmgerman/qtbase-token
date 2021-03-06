begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<QRegExp>
end_include
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QFile>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_BOOST
end_ifdef
begin_include
include|#
directive|include
file|<boost/regex.hpp>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_JSC
end_ifdef
begin_include
include|#
directive|include
file|<QtScript>
end_include
begin_include
include|#
directive|include
file|"pcre/pcre.h"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_define
DECL|macro|ZLIB_VERSION
define|#
directive|define
name|ZLIB_VERSION
value|"1.2.3.4"
end_define
begin_class
DECL|class|tst_qregexp
class|class
name|tst_qregexp
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_qregexp
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|escape_old
parameter_list|()
function_decl|;
DECL|function|escape_old_data
name|void
name|escape_old_data
parameter_list|()
block|{
name|escape_data
argument_list|()
expr_stmt|;
block|}
name|void
name|escape_new1
parameter_list|()
function_decl|;
DECL|function|escape_new1_data
name|void
name|escape_new1_data
parameter_list|()
block|{
name|escape_data
argument_list|()
expr_stmt|;
block|}
name|void
name|escape_new2
parameter_list|()
function_decl|;
DECL|function|escape_new2_data
name|void
name|escape_new2_data
parameter_list|()
block|{
name|escape_data
argument_list|()
expr_stmt|;
block|}
name|void
name|escape_new3
parameter_list|()
function_decl|;
DECL|function|escape_new3_data
name|void
name|escape_new3_data
parameter_list|()
block|{
name|escape_data
argument_list|()
expr_stmt|;
block|}
name|void
name|escape_new4
parameter_list|()
function_decl|;
DECL|function|escape_new4_data
name|void
name|escape_new4_data
parameter_list|()
block|{
name|escape_data
argument_list|()
expr_stmt|;
block|}
comment|/*    JSC outperforms everything.    Boost is less impressive then expected.  */
name|void
name|simpleFind1
parameter_list|()
function_decl|;
name|void
name|rangeReplace1
parameter_list|()
function_decl|;
name|void
name|matchReplace1
parameter_list|()
function_decl|;
name|void
name|simpleFind2
parameter_list|()
function_decl|;
name|void
name|rangeReplace2
parameter_list|()
function_decl|;
name|void
name|matchReplace2
parameter_list|()
function_decl|;
name|void
name|simpleFindJSC
parameter_list|()
function_decl|;
name|void
name|rangeReplaceJSC
parameter_list|()
function_decl|;
name|void
name|matchReplaceJSC
parameter_list|()
function_decl|;
name|void
name|simpleFindBoost
parameter_list|()
function_decl|;
name|void
name|rangeReplaceBoost
parameter_list|()
function_decl|;
name|void
name|matchReplaceBoost
parameter_list|()
function_decl|;
comment|/* those apply an (incorrect) regexp on entire source    (this main.cpp). JSC appears to handle this    (ab)use case best. QRegExp performs extremly bad.  */
name|void
name|horribleWrongReplace1
parameter_list|()
function_decl|;
name|void
name|horribleReplace1
parameter_list|()
function_decl|;
name|void
name|horribleReplace2
parameter_list|()
function_decl|;
name|void
name|horribleWrongReplace2
parameter_list|()
function_decl|;
name|void
name|horribleWrongReplaceJSC
parameter_list|()
function_decl|;
name|void
name|horribleReplaceJSC
parameter_list|()
function_decl|;
name|void
name|horribleWrongReplaceBoost
parameter_list|()
function_decl|;
name|void
name|horribleReplaceBoost
parameter_list|()
function_decl|;
private|private:
DECL|member|str1
name|QString
name|str1
decl_stmt|;
DECL|member|str2
name|QString
name|str2
decl_stmt|;
name|void
name|escape_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_qregexp
name|tst_qregexp
operator|::
name|tst_qregexp
parameter_list|()
member_init_list|:
name|QObject
argument_list|()
member_init_list|,
name|str1
argument_list|(
literal|"We are all happy monkeys"
argument_list|)
block|{
name|QFile
name|f
argument_list|(
literal|":/main.cpp"
argument_list|)
decl_stmt|;
name|f
operator|.
name|open
argument_list|(
name|QFile
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|str2
operator|=
name|f
operator|.
name|readAll
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|verify
specifier|static
name|void
name|verify
parameter_list|(
specifier|const
name|QString
modifier|&
name|quoted
parameter_list|,
specifier|const
name|QString
modifier|&
name|expected
parameter_list|)
block|{
if|if
condition|(
name|quoted
operator|!=
name|expected
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"ERROR:"
operator|<<
name|quoted
operator|<<
name|expected
expr_stmt|;
block|}
end_function
begin_function
DECL|function|escape_data
name|void
name|tst_qregexp
operator|::
name|escape_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"pattern"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"expected"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"escape 0"
argument_list|)
operator|<<
literal|"Hello world"
operator|<<
literal|"Hello world"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"escape 1"
argument_list|)
operator|<<
literal|"(Hello world)"
operator|<<
literal|"\\(Hello world\\)"
expr_stmt|;
block|{
name|QString
name|s
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
literal|10
condition|;
operator|++
name|i
control|)
name|s
operator|+=
literal|"(escape)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"escape 10"
argument_list|)
operator|<<
name|s
operator|<<
name|QRegExp
operator|::
name|escape
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|{
name|QString
name|s
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
literal|100
condition|;
operator|++
name|i
control|)
name|s
operator|+=
literal|"(escape)"
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"escape 100"
argument_list|)
operator|<<
name|s
operator|<<
name|QRegExp
operator|::
name|escape
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|escape_old
name|void
name|tst_qregexp
operator|::
name|escape_old
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
specifier|static
specifier|const
name|char
name|meta
index|[]
init|=
literal|"$()*+.?[\\]^{|}"
decl_stmt|;
name|QString
name|quoted
init|=
name|pattern
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|quoted
operator|.
name|length
argument_list|()
condition|)
block|{
if|if
condition|(
name|strchr
argument_list|(
name|meta
argument_list|,
name|quoted
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
argument_list|)
operator|!=
literal|0
condition|)
name|quoted
operator|.
name|insert
argument_list|(
name|i
operator|++
argument_list|,
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
name|verify
argument_list|(
name|quoted
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|escape_new1
name|void
name|tst_qregexp
operator|::
name|escape_new1
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QString
name|quoted
decl_stmt|;
specifier|const
name|int
name|count
init|=
name|pattern
operator|.
name|count
argument_list|()
decl_stmt|;
name|quoted
operator|.
name|reserve
argument_list|(
name|count
operator|*
literal|2
argument_list|)
expr_stmt|;
specifier|const
name|QLatin1Char
name|backslash
argument_list|(
literal|'\\'
argument_list|)
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
name|count
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|pattern
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
condition|)
block|{
case|case
literal|'$'
case|:
case|case
literal|'('
case|:
case|case
literal|')'
case|:
case|case
literal|'*'
case|:
case|case
literal|'+'
case|:
case|case
literal|'.'
case|:
case|case
literal|'?'
case|:
case|case
literal|'['
case|:
case|case
literal|'\\'
case|:
case|case
literal|']'
case|:
case|case
literal|'^'
case|:
case|case
literal|'{'
case|:
case|case
literal|'|'
case|:
case|case
literal|'}'
case|:
name|quoted
operator|.
name|append
argument_list|(
name|backslash
argument_list|)
expr_stmt|;
block|}
name|quoted
operator|.
name|append
argument_list|(
name|pattern
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|verify
argument_list|(
name|quoted
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|escape_new2
name|void
name|tst_qregexp
operator|::
name|escape_new2
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|int
name|count
init|=
name|pattern
operator|.
name|count
argument_list|()
decl_stmt|;
specifier|const
name|QLatin1Char
name|backslash
argument_list|(
literal|'\\'
argument_list|)
decl_stmt|;
name|QString
name|quoted
argument_list|(
name|count
operator|*
literal|2
argument_list|,
name|backslash
argument_list|)
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|patternData
init|=
name|pattern
operator|.
name|data
argument_list|()
decl_stmt|;
name|QChar
modifier|*
name|quotedData
init|=
name|quoted
operator|.
name|data
argument_list|()
decl_stmt|;
name|int
name|escaped
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
operator|--
name|count
operator|>=
literal|0
condition|;
operator|++
name|patternData
control|)
block|{
specifier|const
name|QChar
name|c
init|=
operator|*
name|patternData
decl_stmt|;
switch|switch
condition|(
name|c
operator|.
name|unicode
argument_list|()
condition|)
block|{
case|case
literal|'$'
case|:
case|case
literal|'('
case|:
case|case
literal|')'
case|:
case|case
literal|'*'
case|:
case|case
literal|'+'
case|:
case|case
literal|'.'
case|:
case|case
literal|'?'
case|:
case|case
literal|'['
case|:
case|case
literal|'\\'
case|:
case|case
literal|']'
case|:
case|case
literal|'^'
case|:
case|case
literal|'{'
case|:
case|case
literal|'|'
case|:
case|case
literal|'}'
case|:
operator|++
name|escaped
expr_stmt|;
operator|++
name|quotedData
expr_stmt|;
block|}
operator|*
name|quotedData
operator|=
name|c
expr_stmt|;
operator|++
name|quotedData
expr_stmt|;
block|}
name|quoted
operator|.
name|resize
argument_list|(
name|pattern
operator|.
name|size
argument_list|()
operator|+
name|escaped
argument_list|)
expr_stmt|;
name|verify
argument_list|(
name|quoted
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|escape_new3
name|void
name|tst_qregexp
operator|::
name|escape_new3
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|QString
name|quoted
decl_stmt|;
specifier|const
name|int
name|count
init|=
name|pattern
operator|.
name|count
argument_list|()
decl_stmt|;
name|quoted
operator|.
name|reserve
argument_list|(
name|count
operator|*
literal|2
argument_list|)
expr_stmt|;
specifier|const
name|QLatin1Char
name|backslash
argument_list|(
literal|'\\'
argument_list|)
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
name|count
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|pattern
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|.
name|toLatin1
argument_list|()
condition|)
block|{
case|case
literal|'$'
case|:
case|case
literal|'('
case|:
case|case
literal|')'
case|:
case|case
literal|'*'
case|:
case|case
literal|'+'
case|:
case|case
literal|'.'
case|:
case|case
literal|'?'
case|:
case|case
literal|'['
case|:
case|case
literal|'\\'
case|:
case|case
literal|']'
case|:
case|case
literal|'^'
case|:
case|case
literal|'{'
case|:
case|case
literal|'|'
case|:
case|case
literal|'}'
case|:
name|quoted
operator|+=
name|backslash
expr_stmt|;
block|}
name|quoted
operator|+=
name|pattern
operator|.
name|at
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
name|verify
argument_list|(
name|quoted
argument_list|,
name|expected
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|needsEscaping
specifier|static
specifier|inline
name|bool
name|needsEscaping
parameter_list|(
name|int
name|c
parameter_list|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'$'
case|:
case|case
literal|'('
case|:
case|case
literal|')'
case|:
case|case
literal|'*'
case|:
case|case
literal|'+'
case|:
case|case
literal|'.'
case|:
case|case
literal|'?'
case|:
case|case
literal|'['
case|:
case|case
literal|'\\'
case|:
case|case
literal|']'
case|:
case|case
literal|'^'
case|:
case|case
literal|'{'
case|:
case|case
literal|'|'
case|:
case|case
literal|'}'
case|:
return|return
literal|true
return|;
block|}
return|return
literal|false
return|;
block|}
end_function
begin_function
DECL|function|escape_new4
name|void
name|tst_qregexp
operator|::
name|escape_new4
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|pattern
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|expected
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
specifier|const
name|int
name|n
init|=
name|pattern
operator|.
name|size
argument_list|()
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|patternData
init|=
name|pattern
operator|.
name|data
argument_list|()
decl_stmt|;
comment|// try to prevent copy if no escape is needed
name|int
name|i
init|=
literal|0
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
name|n
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QChar
name|c
init|=
name|patternData
index|[
name|i
index|]
decl_stmt|;
if|if
condition|(
name|needsEscaping
argument_list|(
name|c
operator|.
name|unicode
argument_list|()
argument_list|)
condition|)
break|break;
block|}
if|if
condition|(
name|i
operator|==
name|n
condition|)
block|{
name|verify
argument_list|(
name|pattern
argument_list|,
name|expected
argument_list|)
expr_stmt|;
comment|// no escaping needed, "return pattern" should be done here.
return|return;
block|}
specifier|const
name|QLatin1Char
name|backslash
argument_list|(
literal|'\\'
argument_list|)
decl_stmt|;
name|QString
name|quoted
argument_list|(
name|n
operator|*
literal|2
argument_list|,
name|backslash
argument_list|)
decl_stmt|;
name|QChar
modifier|*
name|quotedData
init|=
name|quoted
operator|.
name|data
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|j
init|=
literal|0
init|;
name|j
operator|!=
name|i
condition|;
operator|++
name|j
control|)
operator|*
name|quotedData
operator|++
operator|=
operator|*
name|patternData
operator|++
expr_stmt|;
name|int
name|escaped
init|=
literal|0
decl_stmt|;
for|for
control|(
init|;
name|i
operator|!=
name|n
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|QChar
name|c
init|=
operator|*
name|patternData
decl_stmt|;
if|if
condition|(
name|needsEscaping
argument_list|(
name|c
operator|.
name|unicode
argument_list|()
argument_list|)
condition|)
block|{
operator|++
name|escaped
expr_stmt|;
operator|++
name|quotedData
expr_stmt|;
block|}
operator|*
name|quotedData
operator|=
name|c
expr_stmt|;
operator|++
name|quotedData
expr_stmt|;
operator|++
name|patternData
expr_stmt|;
block|}
name|quoted
operator|.
name|resize
argument_list|(
name|n
operator|+
name|escaped
argument_list|)
expr_stmt|;
name|verify
argument_list|(
name|quoted
argument_list|,
name|expected
argument_list|)
expr_stmt|;
comment|// "return quoted"
block|}
block|}
end_function
begin_function
DECL|function|simpleFind1
name|void
name|tst_qregexp
operator|::
name|simpleFind1
parameter_list|()
block|{
name|int
name|roff
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|"happy"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|roff
operator|=
name|rx
operator|.
name|indexIn
argument_list|(
name|str1
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|roff
argument_list|,
literal|11
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rangeReplace1
name|void
name|tst_qregexp
operator|::
name|rangeReplace1
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|"[a-f]"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str1
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
literal|"W- -r- -ll h-ppy monk-ys"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|matchReplace1
name|void
name|tst_qregexp
operator|::
name|matchReplace1
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|"[^a-f]*([a-f]+)[^a-f]*"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str1
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"\\1"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
literal|"eaeaae"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|horribleWrongReplace1
name|void
name|tst_qregexp
operator|::
name|horribleWrongReplace1
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|".*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+)\".*"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str2
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"\\1.\\2.\\3"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|str2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|horribleReplace1
name|void
name|tst_qregexp
operator|::
name|horribleReplace1
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|".*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+).*"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str2
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"\\1.\\2.\\3"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
literal|"1.2.3"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|simpleFind2
name|void
name|tst_qregexp
operator|::
name|simpleFind2
parameter_list|()
block|{
name|int
name|roff
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|"happy"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|roff
operator|=
name|rx
operator|.
name|indexIn
argument_list|(
name|str1
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|roff
argument_list|,
literal|11
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|rangeReplace2
name|void
name|tst_qregexp
operator|::
name|rangeReplace2
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|"[a-f]"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str1
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
literal|"W- -r- -ll h-ppy monk-ys"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|matchReplace2
name|void
name|tst_qregexp
operator|::
name|matchReplace2
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|"[^a-f]*([a-f]+)[^a-f]*"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str1
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"\\1"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
literal|"eaeaae"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|horribleWrongReplace2
name|void
name|tst_qregexp
operator|::
name|horribleWrongReplace2
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|".*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+)\".*"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str2
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"\\1.\\2.\\3"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|str2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|horribleReplace2
name|void
name|tst_qregexp
operator|::
name|horribleReplace2
parameter_list|()
block|{
name|QString
name|r
decl_stmt|;
name|QRegExp
name|rx
argument_list|(
literal|".*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+).*"
argument_list|)
decl_stmt|;
name|rx
operator|.
name|setPatternSyntax
argument_list|(
name|QRegExp
operator|::
name|RegExp2
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|QString
argument_list|(
name|str2
argument_list|)
operator|.
name|replace
argument_list|(
name|rx
argument_list|,
literal|"\\1.\\2.\\3"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|QString
argument_list|(
literal|"1.2.3"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|simpleFindJSC
name|void
name|tst_qregexp
operator|::
name|simpleFindJSC
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_JSC
name|int
name|numr
decl_stmt|;
specifier|const
name|char
modifier|*
name|errmsg
init|=
literal|"  "
decl_stmt|;
name|QString
name|rxs
argument_list|(
literal|"happy"
argument_list|)
decl_stmt|;
name|JSRegExp
modifier|*
name|rx
init|=
name|jsRegExpCompile
argument_list|(
name|rxs
operator|.
name|utf16
argument_list|()
argument_list|,
name|rxs
operator|.
name|length
argument_list|()
argument_list|,
name|JSRegExpDoNotIgnoreCase
argument_list|,
name|JSRegExpSingleLine
argument_list|,
literal|0
argument_list|,
operator|&
name|errmsg
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|rx
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|QString
name|s
argument_list|(
name|str1
argument_list|)
decl_stmt|;
name|int
name|offsetVector
index|[
literal|3
index|]
decl_stmt|;
name|QBENCHMARK
block|{
name|numr
operator|=
name|jsRegExpExecute
argument_list|(
name|rx
argument_list|,
name|s
operator|.
name|utf16
argument_list|()
argument_list|,
name|s
operator|.
name|length
argument_list|()
argument_list|,
literal|0
argument_list|,
name|offsetVector
argument_list|,
literal|3
argument_list|)
expr_stmt|;
block|}
name|jsRegExpFree
argument_list|(
name|rx
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|numr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|offsetVector
index|[
literal|0
index|]
argument_list|,
literal|11
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"JSC is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|rangeReplaceJSC
name|void
name|tst_qregexp
operator|::
name|rangeReplaceJSC
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_JSC
name|QScriptValue
name|r
decl_stmt|;
name|QScriptEngine
name|engine
decl_stmt|;
name|engine
operator|.
name|globalObject
argument_list|()
operator|.
name|setProperty
argument_list|(
literal|"s"
argument_list|,
name|str1
argument_list|)
expr_stmt|;
name|QScriptValue
name|replaceFunc
init|=
name|engine
operator|.
name|evaluate
argument_list|(
literal|"(function() { return s.replace(/[a-f]/g, '-')  } )"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|replaceFunc
operator|.
name|isFunction
argument_list|()
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|replaceFunc
operator|.
name|call
argument_list|(
name|QScriptValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"W- -r- -ll h-ppy monk-ys"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"JSC is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|matchReplaceJSC
name|void
name|tst_qregexp
operator|::
name|matchReplaceJSC
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_JSC
name|QScriptValue
name|r
decl_stmt|;
name|QScriptEngine
name|engine
decl_stmt|;
name|engine
operator|.
name|globalObject
argument_list|()
operator|.
name|setProperty
argument_list|(
literal|"s"
argument_list|,
name|str1
argument_list|)
expr_stmt|;
name|QScriptValue
name|replaceFunc
init|=
name|engine
operator|.
name|evaluate
argument_list|(
literal|"(function() { return s.replace(/[^a-f]*([a-f]+)[^a-f]*/g, '$1')  } )"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|replaceFunc
operator|.
name|isFunction
argument_list|()
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|replaceFunc
operator|.
name|call
argument_list|(
name|QScriptValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"eaeaae"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"JSC is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|horribleWrongReplaceJSC
name|void
name|tst_qregexp
operator|::
name|horribleWrongReplaceJSC
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_JSC
name|QScriptValue
name|r
decl_stmt|;
name|QScriptEngine
name|engine
decl_stmt|;
name|engine
operator|.
name|globalObject
argument_list|()
operator|.
name|setProperty
argument_list|(
literal|"s"
argument_list|,
name|str2
argument_list|)
expr_stmt|;
name|QScriptValue
name|replaceFunc
init|=
name|engine
operator|.
name|evaluate
argument_list|(
literal|"(function() { return s.replace(/.*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+)\".*/gm, '$1.$2.$3')  } )"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|replaceFunc
operator|.
name|isFunction
argument_list|()
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|replaceFunc
operator|.
name|call
argument_list|(
name|QScriptValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
operator|.
name|toString
argument_list|()
argument_list|,
name|str2
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"JSC is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|horribleReplaceJSC
name|void
name|tst_qregexp
operator|::
name|horribleReplaceJSC
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_JSC
name|QScriptValue
name|r
decl_stmt|;
name|QScriptEngine
name|engine
decl_stmt|;
comment|// the m flag doesn't actually work here; dunno
name|engine
operator|.
name|globalObject
argument_list|()
operator|.
name|setProperty
argument_list|(
literal|"s"
argument_list|,
name|str2
operator|.
name|replace
argument_list|(
literal|'\n'
argument_list|,
literal|' '
argument_list|)
argument_list|)
expr_stmt|;
name|QScriptValue
name|replaceFunc
init|=
name|engine
operator|.
name|evaluate
argument_list|(
literal|"(function() { return s.replace(/.*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+).*/gm, '$1.$2.$3')  } )"
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|replaceFunc
operator|.
name|isFunction
argument_list|()
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|replaceFunc
operator|.
name|call
argument_list|(
name|QScriptValue
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
operator|.
name|toString
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"1.2.3"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"JSC is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|simpleFindBoost
name|void
name|tst_qregexp
operator|::
name|simpleFindBoost
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_BOOST
name|int
name|roff
decl_stmt|;
name|boost
operator|::
name|regex
name|rx
argument_list|(
literal|"happy"
argument_list|,
name|boost
operator|::
name|regex_constants
operator|::
name|perl
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|s
init|=
name|str1
operator|.
name|toStdString
argument_list|()
decl_stmt|;
name|std
operator|::
name|string
operator|::
name|const_iterator
name|start
decl_stmt|,
name|end
decl_stmt|;
name|start
operator|=
name|s
operator|.
name|begin
argument_list|()
expr_stmt|;
name|end
operator|=
name|s
operator|.
name|end
argument_list|()
expr_stmt|;
name|boost
operator|::
name|match_flag_type
name|flags
init|=
name|boost
operator|::
name|match_default
decl_stmt|;
name|QBENCHMARK
block|{
name|boost
operator|::
name|match_results
argument_list|<
name|std
operator|::
name|string
operator|::
name|const_iterator
argument_list|>
name|what
decl_stmt|;
name|regex_search
argument_list|(
name|start
argument_list|,
name|end
argument_list|,
name|what
argument_list|,
name|rx
argument_list|,
name|flags
argument_list|)
expr_stmt|;
name|roff
operator|=
operator|(
name|what
index|[
literal|0
index|]
operator|.
name|first
operator|)
operator|-
name|start
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|roff
argument_list|,
literal|11
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Boost is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|rangeReplaceBoost
name|void
name|tst_qregexp
operator|::
name|rangeReplaceBoost
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_BOOST
name|boost
operator|::
name|regex
name|pattern
argument_list|(
literal|"[a-f]"
argument_list|,
name|boost
operator|::
name|regex_constants
operator|::
name|perl
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|s
init|=
name|str1
operator|.
name|toStdString
argument_list|()
decl_stmt|;
name|std
operator|::
name|string
name|r
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|boost
operator|::
name|regex_replace
argument_list|(
name|s
argument_list|,
name|pattern
argument_list|,
literal|"-"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|std
operator|::
name|string
argument_list|(
literal|"W- -r- -ll h-ppy monk-ys"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Boost is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|matchReplaceBoost
name|void
name|tst_qregexp
operator|::
name|matchReplaceBoost
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_BOOST
name|boost
operator|::
name|regex
name|pattern
argument_list|(
literal|"[^a-f]*([a-f]+)[^a-f]*"
argument_list|,
name|boost
operator|::
name|regex_constants
operator|::
name|perl
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|s
init|=
name|str1
operator|.
name|toStdString
argument_list|()
decl_stmt|;
name|std
operator|::
name|string
name|r
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|boost
operator|::
name|regex_replace
argument_list|(
name|s
argument_list|,
name|pattern
argument_list|,
literal|"$1"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|std
operator|::
name|string
argument_list|(
literal|"eaeaae"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Boost is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|horribleWrongReplaceBoost
name|void
name|tst_qregexp
operator|::
name|horribleWrongReplaceBoost
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_BOOST
name|boost
operator|::
name|regex
name|pattern
argument_list|(
literal|".*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+)\".*"
argument_list|,
name|boost
operator|::
name|regex_constants
operator|::
name|perl
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|s
init|=
name|str2
operator|.
name|toStdString
argument_list|()
decl_stmt|;
name|std
operator|::
name|string
name|r
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|boost
operator|::
name|regex_replace
argument_list|(
name|s
argument_list|,
name|pattern
argument_list|,
literal|"$1.$2.$3"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Boost is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|horribleReplaceBoost
name|void
name|tst_qregexp
operator|::
name|horribleReplaceBoost
parameter_list|()
block|{
ifdef|#
directive|ifdef
name|HAVE_BOOST
name|boost
operator|::
name|regex
name|pattern
argument_list|(
literal|".*#"
literal|"define ZLIB_VERSION \"([0-9]+)\\.([0-9]+)\\.([0-9]+).*"
argument_list|,
name|boost
operator|::
name|regex_constants
operator|::
name|perl
argument_list|)
decl_stmt|;
name|std
operator|::
name|string
name|s
init|=
name|str2
operator|.
name|toStdString
argument_list|()
decl_stmt|;
name|std
operator|::
name|string
name|r
decl_stmt|;
name|QBENCHMARK
block|{
name|r
operator|=
name|boost
operator|::
name|regex_replace
argument_list|(
name|s
argument_list|,
name|pattern
argument_list|,
literal|"$1.$2.$3"
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|r
argument_list|,
name|std
operator|::
name|string
argument_list|(
literal|"1.2.3"
argument_list|)
argument_list|)
expr_stmt|;
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Boost is not enabled for this platform"
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qregexp
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
