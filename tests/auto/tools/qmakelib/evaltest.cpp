begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"tst_qmakelib.h"
end_include
begin_include
include|#
directive|include
file|<proitems.h>
end_include
begin_include
include|#
directive|include
file|<qmakevfs.h>
end_include
begin_include
include|#
directive|include
file|<qmakeparser.h>
end_include
begin_include
include|#
directive|include
file|<qmakeglobals.h>
end_include
begin_include
include|#
directive|include
file|<qmakeevaluator.h>
end_include
begin_function
DECL|function|addAssignments
name|void
name|tst_qmakelib
operator|::
name|addAssignments
parameter_list|()
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"assignment"
argument_list|)
operator|<<
literal|"VAR = foo bar baz"
operator|<<
literal|"VAR = foo bar baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"appending"
argument_list|)
operator|<<
literal|"VAR = foo bar baz\nVAR += foo gaz gaz"
operator|<<
literal|"VAR = foo bar baz foo gaz gaz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unique appending"
argument_list|)
operator|<<
literal|"VAR = foo bar baz\nVAR *= foo gaz gaz"
operator|<<
literal|"VAR = foo bar baz gaz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"removing"
argument_list|)
operator|<<
literal|"VAR = foo bar foo baz\nVAR -= foo gaz gaz"
operator|<<
literal|"VAR = bar baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// Somewhat unexpectedly, the g modifier is implicit within each element.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing"
argument_list|)
operator|<<
literal|"VAR = foo bar foo baz\nVAR ~= s,o,0,"
operator|<<
literal|"VAR = f00 bar foo baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// Consistently with the "there are no empty elements", what becomes empty gets zapped.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing with nothing"
argument_list|)
operator|<<
literal|"VAR = foo bar foo baz\nVAR ~= s,foo,,"
operator|<<
literal|"VAR = bar foo baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing case-insensitively"
argument_list|)
operator|<<
literal|"VAR = foO bar foo baz\nVAR ~= s,o,0,i"
operator|<<
literal|"VAR = f00 bar foo baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// In all elements, not all within each/one/??? element.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing globally"
argument_list|)
operator|<<
literal|"VAR = foo bar foo baz\nVAR ~= s,o,0,g"
operator|<<
literal|"VAR = f00 bar f00 baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// Replacing with the same string counts as no match.
comment|// This is rather questionable ...
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing with same"
argument_list|)
operator|<<
literal|"VAR = foo bar foo baz\nVAR ~= s,ba[rz],bar,"
operator|<<
literal|"VAR = foo bar foo bar"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing with auto-quote"
argument_list|)
operator|<<
literal|"VAR = foo [bar] foo baz\nVAR ~= s,[bar],bar,q"
operator|<<
literal|"VAR = foo bar foo baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"replacing with expansions"
argument_list|)
operator|<<
literal|"VAR = foo bar foo baz\nPAT = foo\nREPL = 'yee haw'\nVAR ~= s,$$PAT,$$REPL,"
operator|<<
literal|"VAR = 'yee haw' bar foo baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"~= with bad function"
argument_list|)
operator|<<
literal|"VAR ~= m/foo/"
operator|<<
literal|""
operator|<<
literal|"##:1: The ~= operator can handle only the s/// function."
operator|<<
literal|true
expr_stmt|;
comment|// rather questionable
name|QTest
operator|::
name|newRow
argument_list|(
literal|"~= s with bad number of arguments"
argument_list|)
operator|<<
literal|"VAR ~= s/bla\nVAR ~= s/bla/foo//"
operator|<<
literal|""
operator|<<
literal|"##:1: The s/// function expects 3 or 4 arguments.\n"
literal|"##:2: The s/// function expects 3 or 4 arguments."
operator|<<
literal|true
expr_stmt|;
comment|// rather questionable
block|}
end_function
begin_function
DECL|function|addExpansions
name|void
name|tst_qmakelib
operator|::
name|addExpansions
parameter_list|()
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand variable"
argument_list|)
operator|<<
literal|"V1 = foo\nVAR = $$V1"
operator|<<
literal|"VAR = foo"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand property"
argument_list|)
operator|<<
literal|"VAR = $$[P1]"
operator|<<
literal|"VAR = 'prop val'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand environment variable"
argument_list|)
operator|<<
literal|"VAR = $$(E1)"
operator|<<
literal|"VAR = 'env var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// These test addStr/addStr.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: str $$(env)"
argument_list|)
operator|<<
literal|"VAR = foo $$(E1)"
operator|<<
literal|"VAR = foo 'env var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: str$$(env)"
argument_list|)
operator|<<
literal|"VAR = foo$$(E1)"
operator|<<
literal|"VAR = 'fooenv var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: 'str $$(env)'"
argument_list|)
operator|<<
literal|"VAR = 'foo $$(E1)'"
operator|<<
literal|"VAR = 'foo env var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// These test addStr/addStrList
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: str $$var"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = str $$V1"
operator|<<
literal|"VAR = str foo barbaz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: $$var str"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$V1 str"
operator|<<
literal|"VAR = foo barbaz str"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: str$$var"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = str$$V1"
operator|<<
literal|"VAR = strfoo barbaz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: $${var}str"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $${V1}str"
operator|<<
literal|"VAR = foo barbazstr"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: 'str $$var'"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = 'str $$V1'"
operator|<<
literal|"VAR = 'str foo barbaz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand: '$$var str'"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = '$$V1 str'"
operator|<<
literal|"VAR = 'foo barbaz str'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// Same again in joined context
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: str $$(env)"
argument_list|)
operator|<<
literal|"VAR = $$quote(foo $$(E1))"
operator|<<
literal|"VAR = 'foo env var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: str$$(env)"
argument_list|)
operator|<<
literal|"VAR = $$quote(foo$$(E1))"
operator|<<
literal|"VAR = 'fooenv var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: 'str $$(env)'"
argument_list|)
operator|<<
literal|"VAR = $$quote('foo $$(E1)')"
operator|<<
literal|"VAR = 'foo env var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: str $$var"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$quote(str $$V1)"
operator|<<
literal|"VAR = 'str foo barbaz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: $$var str"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$quote($$V1 str)"
operator|<<
literal|"VAR = 'foo barbaz str'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: str$$var"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$quote(str$$V1)"
operator|<<
literal|"VAR = 'strfoo barbaz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: $${var}str"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$quote($${V1}str)"
operator|<<
literal|"VAR = 'foo barbazstr'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: 'str $$var'"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$quote('str $$V1')"
operator|<<
literal|"VAR = 'str foo barbaz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"expand joined: '$$var str'"
argument_list|)
operator|<<
literal|"V1 = foo barbaz\nVAR = $$quote('$$V1 str')"
operator|<<
literal|"VAR = 'foo barbaz str'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// Variable expansions on LHS
name|QTest
operator|::
name|newRow
argument_list|(
literal|"indirect assign: $$var"
argument_list|)
operator|<<
literal|"V = VAR\n$$V = foo"
operator|<<
literal|"VAR = foo"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"indirect assign: fix$$var"
argument_list|)
operator|<<
literal|"V = AR\nV$$V = foo"
operator|<<
literal|"VAR = foo"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"indirect assign: $${var}fix"
argument_list|)
operator|<<
literal|"V = VA\n$${V}R = foo"
operator|<<
literal|"VAR = foo"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"indirect assign: eval"
argument_list|)
operator|<<
literal|"V = VAR\n$$eval(V) = foo"
operator|<<
literal|"VAR = foo"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"indirect assign: multiple"
argument_list|)
operator|<<
literal|"V = FOO BAR\n$$V = foo"
operator|<<
literal|""
operator|<<
literal|"##:2: Left hand side of assignment must expand to exactly one word."
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addControlStructs
name|void
name|tst_qmakelib
operator|::
name|addControlStructs
parameter_list|()
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true"
argument_list|)
operator|<<
literal|"true: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false"
argument_list|)
operator|<<
literal|"false: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-config"
argument_list|)
operator|<<
literal|"CONFIG += test\ntest: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-config"
argument_list|)
operator|<<
literal|"test: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-wildcard"
argument_list|)
operator|<<
literal|"CONFIG += testing\ntest*: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-wildcard"
argument_list|)
operator|<<
literal|"test*: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-else"
argument_list|)
operator|<<
literal|"true: VAR1 = 1\nelse: VAR2 = 1"
operator|<<
literal|"VAR1 = 1\nVAR2 = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-else"
argument_list|)
operator|<<
literal|"false: VAR1 = 1\nelse: VAR2 = 1"
operator|<<
literal|"VAR1 = UNDEF\nVAR2 = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-else-true-else"
argument_list|)
operator|<<
literal|"true: VAR1 = 1\nelse: true: VAR2 = 1\nelse: VAR3 = 1"
operator|<<
literal|"VAR1 = 1\nVAR2 = UNDEF\nVAR3 = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-else-false-else"
argument_list|)
operator|<<
literal|"true: VAR1 = 1\nelse: false: VAR2 = 1\nelse: VAR3 = 1"
operator|<<
literal|"VAR1 = 1\nVAR2 = UNDEF\nVAR3 = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-else-true-else"
argument_list|)
operator|<<
literal|"false: VAR1 = 1\nelse: true: VAR2 = 1\nelse: VAR3 = 1"
operator|<<
literal|"VAR1 = UNDEF\nVAR2 = 1\nVAR3 = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-else-false-else"
argument_list|)
operator|<<
literal|"false: VAR1 = 1\nelse: false: VAR2 = 1\nelse: VAR3 = 1"
operator|<<
literal|"VAR1 = UNDEF\nVAR2 = UNDEF\nVAR3 = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-{false-else}-else"
argument_list|)
operator|<<
literal|"true {\nfalse: VAR1 = 1\nelse: VAR2 = 1\n}\nelse: VAR3 = 1"
operator|<<
literal|"VAR1 = UNDEF\nVAR2 = 1\nVAR3 = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-true"
argument_list|)
operator|<<
literal|"!true: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-false"
argument_list|)
operator|<<
literal|"!false: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-AND-true"
argument_list|)
operator|<<
literal|"true:true: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-AND-false"
argument_list|)
operator|<<
literal|"true:false: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-AND-true"
argument_list|)
operator|<<
literal|"false:true: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-OR-false"
argument_list|)
operator|<<
literal|"false|false: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-OR-false"
argument_list|)
operator|<<
literal|"true|false: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-OR-true"
argument_list|)
operator|<<
literal|"false|true: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"NOT-false-AND-true"
argument_list|)
operator|<<
literal|"!false:true: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-AND-message"
argument_list|)
operator|<<
literal|"true:message(hi): VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|"Project MESSAGE: hi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-AND-message"
argument_list|)
operator|<<
literal|"false:message(hi): VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-OR-message"
argument_list|)
operator|<<
literal|"true|message(hi): VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-OR-message"
argument_list|)
operator|<<
literal|"false|message(hi): VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|"Project MESSAGE: hi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-OR-message-AND-false"
argument_list|)
operator|<<
literal|"true|message(hi):false: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-OR-message-AND-false"
argument_list|)
operator|<<
literal|"false|message(hi):false: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|"Project MESSAGE: hi"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true (indirect)"
argument_list|)
operator|<<
literal|"TEST = true\n$$TEST: VAR = 1"
operator|<<
literal|"VAR = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false (indirect)"
argument_list|)
operator|<<
literal|"TEST = false\n$$TEST: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// Yes, this is not supposed to work
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true|false (indirect)"
argument_list|)
operator|<<
literal|"TEST = true|false\n$$TEST: VAR = 1"
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for (var, var)"
argument_list|)
operator|<<
literal|"IN = one two three\nfor (IT, IN) { OUT += $$IT }"
operator|<<
literal|"OUT = one two three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for (var, range)"
argument_list|)
operator|<<
literal|"for (IT, 1..3) { OUT += $$IT }"
operator|<<
literal|"OUT = 1 2 3"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for (var, reverse-range)"
argument_list|)
operator|<<
literal|"for (IT, 3..1) { OUT += $$IT }"
operator|<<
literal|"OUT = 3 2 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// This syntax is rather ridiculous.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for (ever)"
argument_list|)
operator|<<
literal|"for (ever) {}"
operator|<<
literal|""
operator|<<
literal|"##:1: Ran into infinite loop (> 1000 iterations)."
operator|<<
literal|true
expr_stmt|;
comment|// This is even worse.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for (VAR, forever)"
argument_list|)
operator|<<
literal|"for (VAR, forever) { OUT = $$VAR }"
operator|<<
literal|"OUT = 999"
operator|<<
literal|"##:1: Ran into infinite loop (> 1000 iterations)."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"for (garbage)"
argument_list|)
operator|<<
literal|"for (garbage) { OUT = FAIL }"
operator|<<
literal|"OUT = UNDEF"
operator|<<
literal|"##:1: Invalid loop expression."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"next()"
argument_list|)
operator|<<
literal|"IN = one two three\nfor (IT, IN) {\nequals(IT, two):next()\nOUT += $$IT\n}"
operator|<<
literal|"OUT = one three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"nested next()"
argument_list|)
operator|<<
literal|"IN = one two three\nfor (IT, IN) {\nfor (NIT, IN):next()\nOUT += $$IT\n}"
operator|<<
literal|"OUT = one two three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"break()"
argument_list|)
operator|<<
literal|"IN = one two three\nfor (IT, IN) {\nequals(IT, three):break()\nOUT += $$IT\n}"
operator|<<
literal|"OUT = one two"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"nested break()"
argument_list|)
operator|<<
literal|"IN = one two three\nfor (IT, IN) {\nfor (NIT, IN):break()\nOUT += $$IT\n}"
operator|<<
literal|"OUT = one two three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineReplace()"
argument_list|)
operator|<<
literal|"defineReplace(func) { return($$1 + $$2) }\n"
literal|"VAR = $$func(test me, \"foo bar\")"
operator|<<
literal|"VAR = test me + 'foo bar'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defineTest()"
argument_list|)
operator|<<
literal|"defineTest(func) { return($$1) }\n"
literal|"func(true): VAR += true\n"
literal|"func(false): VAR += false"
operator|<<
literal|"VAR = true"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-AND-defineTest()"
argument_list|)
operator|<<
literal|"true: defineTest(func)\n"
literal|"defined(func): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-AND-defineTest()"
argument_list|)
operator|<<
literal|"false: defineTest(func)\n"
literal|"defined(func): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"true-OR-defineTest()"
argument_list|)
operator|<<
literal|"true| defineTest(func)\n"
literal|"defined(func): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"false-OR-defineTest()"
argument_list|)
operator|<<
literal|"false| defineTest(func)\n"
literal|"defined(func): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"variable scoping"
argument_list|)
operator|<<
literal|"defineTest(func) {\n"
literal|"VAR1 = modified\n!equals(VAR1, modified): return(false)\n"
literal|"VAR2 += modified\n!equals(VAR2, original modified): return(false)\n"
literal|"VAR3 = new var\n!equals(VAR3, new var): return(false)\n"
literal|"return(true)\n"
literal|"}\n"
literal|"VAR1 = pristine\nVAR2 = original\nfunc(): OK = 1"
operator|<<
literal|"OK = 1\nVAR1 = pristine\nVAR2 = original\nVAR3 = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ARGC and ARGS"
argument_list|)
operator|<<
literal|"defineTest(func) {\n"
literal|"export(ARGC)\n"
literal|"export(ARGS)\n"
literal|"}\n"
literal|"func(test me, \"foo bar\")"
operator|<<
literal|"ARGC = 2\nARGS = test me 'foo bar'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"recursion"
argument_list|)
operator|<<
literal|"defineReplace(func) {\n"
literal|"RET = *$$member(1, 0)*\n"
literal|"REST = $$member(1, 1, -1)\n"
literal|"!isEmpty(REST): RET += $$func($$REST)\n"
literal|"return($$RET)\n"
literal|"}\n"
literal|"VAR = $$func(you are ...)"
operator|<<
literal|"VAR = *you* *are* *...*"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"top-level return()"
argument_list|)
operator|<<
literal|"VAR = good\nreturn()\nVAR = bad"
operator|<<
literal|"VAR = good"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"return() from function"
argument_list|)
operator|<<
literal|"defineTest(func) {\nVAR = good\nexport(VAR)\nreturn()\nVAR = bad\nexport(VAR)\n}\n"
literal|"func()"
operator|<<
literal|"VAR = good"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"return() from nested function"
argument_list|)
operator|<<
literal|"defineTest(inner) {\nVAR = initial\nexport(VAR)\nreturn()\nVAR = bad\nexport(VAR)\n}\n"
literal|"defineTest(outer) {\ninner()\nVAR = final\nexport(VAR)\n}\n"
literal|"outer()"
operator|<<
literal|"VAR = final"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addReplaceFunctions
name|void
name|tst_qmakelib
operator|::
name|addReplaceFunctions
parameter_list|(
specifier|const
name|QString
modifier|&
name|qindir
parameter_list|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): empty"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$member(IN)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): too short"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN, 1, 5)"
operator|<<
literal|"VAR ="
comment|// this is actually kinda stupid
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): ok"
argument_list|)
operator|<<
literal|"IN = one two three four five six seven\nVAR = $$member(IN, 1, 4)"
operator|<<
literal|"VAR = two three four five"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): ok (default start)"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN)"
operator|<<
literal|"VAR = one"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): ok (default end)"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN, 2)"
operator|<<
literal|"VAR = three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): negative"
argument_list|)
operator|<<
literal|"IN = one two three four five six seven\nVAR = $$member(IN, -4, -3)"
operator|<<
literal|"VAR = four five"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): inverse"
argument_list|)
operator|<<
literal|"IN = one two three four five six seven\nVAR = $$member(IN, 4, 1)"
operator|<<
literal|"VAR = five four three two"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): dots"
argument_list|)
operator|<<
literal|"IN = one two three four five six seven\nVAR = $$member(IN, 1..4)"
operator|<<
literal|"VAR = two three four five"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$member(1, 2, 3, 4)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: member(var, start, end) requires one to three arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): bad args (1)"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN, foo, 4)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:2: member() argument 2 (start) 'foo' invalid."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): bad args (2)"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN, foo..4)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:2: member() argument 2 (start) 'foo..4' invalid."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): bad args (3)"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN, 4, foo)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:2: member() argument 3 (end) 'foo' invalid."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$member(): bad args (4)"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$member(IN, 4..foo)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:2: member() argument 2 (start) '4..foo' invalid."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$first(): empty"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$first(IN)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$first(): one"
argument_list|)
operator|<<
literal|"IN = one\nVAR = $$first(IN)"
operator|<<
literal|"VAR = one"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$first(): multiple"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$first(IN)"
operator|<<
literal|"VAR = one"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$first(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$first(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: first(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$last(): empty"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$last(IN)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$last(): one"
argument_list|)
operator|<<
literal|"IN = one\nVAR = $$last(IN)"
operator|<<
literal|"VAR = one"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$last(): multiple"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$last(IN)"
operator|<<
literal|"VAR = three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$last(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$last(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: last(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$size()"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$size(IN)"
operator|<<
literal|"VAR = 3"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$size(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$size(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: size(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$fromfile(): right var"
argument_list|)
operator|<<
literal|"VAR = $$fromfile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, DEFINES)"
operator|<<
literal|"VAR = QT_DLL"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$fromfile(): wrong var"
argument_list|)
operator|<<
literal|"VAR = $$fromfile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, INCLUDES)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$fromfile(): bad file"
argument_list|)
operator|<<
literal|"VAR = $$fromfile("
operator|+
name|qindir
operator|+
literal|"/fromfile/badfile.prx, DEFINES)"
operator|<<
literal|"VAR ="
operator|<<
literal|"Project ERROR: fail!"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$fromfile(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$fromfile(1) \\\n$$fromfile(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: fromfile(file, variable) requires two arguments.\n"
literal|"##:2: fromfile(file, variable) requires two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$eval()"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$eval(IN)"
operator|<<
literal|"VAR = one two three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$eval(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$eval(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: eval(variable) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$list()"
argument_list|)
operator|<<
literal|"VARNAME = $$list(one, two three, 'four five')\nVAR = $$eval($$VARNAME)"
operator|<<
literal|"VAR = one two three four five"
comment|// total nonsense ...
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$sprintf()"
argument_list|)
operator|<<
literal|"VAR = $$sprintf(hello %1 %2, you, there)"
operator|<<
literal|"VAR = 'hello you there'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): simple number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13)"
operator|<<
literal|"VAR = 13"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): negative number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(-13)"
operator|<<
literal|"VAR = -13"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): hex input number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, ibase=16)"
operator|<<
literal|"VAR = 19"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): hex output number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, obase=16)"
operator|<<
literal|"VAR = d"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): right aligned number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5)"
operator|<<
literal|"VAR = '   13'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): left aligned number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5 leftalign)"
operator|<<
literal|"VAR = '13   '"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): zero-padded number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5 zeropad)"
operator|<<
literal|"VAR = 00013"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): always signed number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5 alwayssign)"
operator|<<
literal|"VAR = '  +13'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): zero-padded always signed number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5 alwayssign zeropad)"
operator|<<
literal|"VAR = +0013"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): sign-padded number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5 padsign)"
operator|<<
literal|"VAR = '   13'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): zero-padded sign-padded number format"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, width=5 padsign zeropad)"
operator|<<
literal|"VAR = ' 0013'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, 1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: format_number(number[, options...]) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$format_number(): invalid option"
argument_list|)
operator|<<
literal|"VAR = $$format_number(13, foo=bar)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: format_number(): invalid format option foo=bar."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$join(): empty"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$join(IN, //)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$join(): multiple"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$join(IN, //)"
operator|<<
literal|"VAR = one//two//three"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$join(): multiple surrounded"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$join(IN, //,<<,>>)"
operator|<<
literal|"VAR =<<one//two//three>>"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$join(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$join(1, 2, 3, 4, 5)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: join(var, glue, before, after) requires one to four arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$split(): default sep"
argument_list|)
operator|<<
literal|"IN = 'one/two three' 'four / five'\nVAR = $$split(IN)"
operator|<<
literal|"VAR = one/two three four / five"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$split(): specified sep"
argument_list|)
operator|<<
literal|"IN = 'one/two three' 'four / five'\nVAR = $$split(IN, /)"
operator|<<
literal|"VAR = one 'two three' 'four ' ' five'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$split(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$split(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: split(var, sep) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$basename(): empty"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$basename(IN)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$basename(): bare"
argument_list|)
operator|<<
literal|"IN = file\nVAR = $$basename(IN)"
operator|<<
literal|"VAR = file"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$basename(): relative"
argument_list|)
operator|<<
literal|"IN = path/file\nVAR = $$basename(IN)"
operator|<<
literal|"VAR = file"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$basename(): absolute"
argument_list|)
operator|<<
literal|"IN = \\\\path\\\\file\nVAR = $$basename(IN)"
operator|<<
literal|"VAR = file"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$basename(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$basename(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: basename(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$dirname(): empty"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$dirname(IN)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$dirname(): bare"
argument_list|)
operator|<<
literal|"IN = file\nVAR = $$dirname(IN)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$dirname(): relative"
argument_list|)
operator|<<
literal|"IN = path/file\nVAR = $$dirname(IN)"
operator|<<
literal|"VAR = path"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$dirname(): absolute"
argument_list|)
operator|<<
literal|"IN = \\\\path\\\\file\nVAR = $$dirname(IN)"
operator|<<
literal|"VAR = \\\\path"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$dirname(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$dirname(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: dirname(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$section(): explicit end"
argument_list|)
operator|<<
literal|"IN = one~two~three~four~five~six\nVAR = $$section(IN, ~, 2, 4)"
operator|<<
literal|"VAR = three~four~five"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$section(): implicit end"
argument_list|)
operator|<<
literal|"IN = one~two~three~four~five~six\nVAR = $$section(IN, ~, 3)"
operator|<<
literal|"VAR = four~five~six"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$section(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$section(1, 2) \\\n$$section(1, 2, 3, 4, 5)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: section(var) section(var, sep, begin, end) requires three or four arguments.\n"
literal|"##:2: section(var) section(var, sep, begin, end) requires three or four arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$find()"
argument_list|)
operator|<<
literal|"IN = foo bar baz blubb\nVAR = $$find(IN, ^ba)"
operator|<<
literal|"VAR = bar baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$find(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$find(1) \\\n$$find(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: find(var, str) requires two arguments.\n"
literal|"##:2: find(var, str) requires two arguments."
operator|<<
literal|true
expr_stmt|;
comment|// FIXME: $$cat()& $$system(): There is no way to generate the newlines
comment|// necessary for testing "multi-line" and "blob" mode adequately.
comment|// Note: these functions have *different* splitting behavior.
comment|// This gives split_value_list() an exercise
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$cat(): default mode"
argument_list|)
operator|<<
literal|"VAR = $$cat("
operator|+
name|qindir
operator|+
literal|"/cat/file2.txt)"
operator|<<
literal|"VAR = foo bar baz \"\\\"Hello, \\' world.\\\"\" post \"\\'Hello, \\\" world.\\'\" post \\\\\\\" \\\\\\' \\\\\\\\ \\\\a \\\\ nix \"\\\" \\\"\""
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$cat(): lines mode"
argument_list|)
operator|<<
literal|"VAR = $$cat("
operator|+
name|qindir
operator|+
literal|"/cat/file1.txt, lines)"
operator|<<
literal|"VAR = '\"Hello, world.\"' 'foo bar baz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$cat(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$cat(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: cat(file, singleline=true) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system(): default mode"
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"VAR = $$system('echo Hello, ^\"world.&& echo foo^\" bar baz')"
else|#
directive|else
operator|<<
literal|"VAR = $$system('echo Hello, \\\\\\\"world.&& echo foo\\\\\\\" bar baz')"
endif|#
directive|endif
operator|<<
literal|"VAR = Hello, '\"world. foo\"' bar baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system(): lines mode"
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"VAR = $$system('echo Hello, ^\"world.&& echo foo^\" bar baz', lines)"
else|#
directive|else
operator|<<
literal|"VAR = $$system('echo Hello, \\\\\\\"world.&& echo foo\\\\\\\" bar baz', lines)"
endif|#
directive|endif
operator|<<
literal|"VAR = 'Hello, \"world.' 'foo\" bar baz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$system(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: system(execute) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$unique()"
argument_list|)
operator|<<
literal|"IN = foo bar foo baz\nVAR = $$unique(IN)"
operator|<<
literal|"VAR = foo bar baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$unique(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$unique(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: unique(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$reverse()"
argument_list|)
operator|<<
literal|"IN = one two three\nVAR = $$reverse(IN)"
operator|<<
literal|"VAR = three two one"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$reverse(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$reverse(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: reverse(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$quote()"
argument_list|)
operator|<<
literal|"VAR = $$quote(foo bar, 'foo bar')"
operator|<<
literal|"VAR = 'foo bar' 'foo bar'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// FIXME: \n and \r go untested, because there is no way to get them into the
comment|// expected result. And if there was one, this function would be unnecessary.
comment|// In other news, the behavior of backslash escaping makes no sense.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$escape_expand()"
argument_list|)
operator|<<
literal|"VAR = $$escape_expand(foo\\\\ttab\\\\\\\\slash\\\\invalid, verbatim)"
operator|<<
literal|"VAR = 'foo\ttab\\\\\\\\slash\\\\invalid' verbatim"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$upper()"
argument_list|)
operator|<<
literal|"VAR = $$upper(kEwL, STuff)"
operator|<<
literal|"VAR = KEWL STUFF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$lower()"
argument_list|)
operator|<<
literal|"VAR = $$lower(kEwL, STuff)"
operator|<<
literal|"VAR = kewl stuff"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$title()"
argument_list|)
operator|<<
literal|"VAR = $$title(kEwL, STuff)"
operator|<<
literal|"VAR = Kewl Stuff"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$re_escape()"
argument_list|)
operator|<<
literal|"VAR = $$re_escape(one, hey.*you[funny]+people)"
operator|<<
literal|"VAR = one hey\\\\.\\\\*you\\\\[funny\\\\]\\\\+people"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$val_escape()"
argument_list|)
operator|<<
literal|"IN = easy \"less easy\" sca$${LITERAL_HASH}ry"
literal|" crazy$$escape_expand(\\\\t\\\\r\\\\n)"
literal|" $$escape_expand(\\\\t)stuff \\'no\\\"way\\\\here\n"
literal|"VAR = $$val_escape(IN)"
operator|<<
literal|"VAR = easy '\\\"less easy\\\"' sca\\$\\${LITERAL_HASH}ry"
literal|" crazy\\$\\$escape_expand(\\\\\\\\t\\\\\\\\r\\\\\\\\n)"
literal|" \\$\\$escape_expand(\\\\\\\\t)stuff \\\\\\'no\\\\\\\"way\\\\\\\\here"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$val_escape(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$val_escape(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: val_escape(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$files(): non-recursive"
argument_list|)
operator|<<
literal|"VAR = $$files("
operator|+
name|qindir
operator|+
literal|"/files/file*.txt)"
operator|<<
literal|"VAR = "
operator|+
name|qindir
operator|+
literal|"/files/file1.txt "
operator|+
name|qindir
operator|+
literal|"/files/file2.txt"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$files(): recursive"
argument_list|)
operator|<<
literal|"VAR = $$files("
operator|+
name|qindir
operator|+
literal|"/files/file*.txt, true)"
operator|<<
literal|"VAR = "
operator|+
name|qindir
operator|+
literal|"/files/file1.txt "
operator|+
name|qindir
operator|+
literal|"/files/file2.txt "
operator|+
name|qindir
operator|+
literal|"/files/dir/file1.txt "
operator|+
name|qindir
operator|+
literal|"/files/dir/file2.txt"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$files(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$files(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: files(pattern, recursive=false) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
if|#
directive|if
literal|0
comment|// FIXME: no emulated input layer
block|QTest::newRow("$$prompt()")<< "VAR = $$prompt(que)"<< "VAR = whatever"<< "Project PROMPT: que? "<< true;
endif|#
directive|endif
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$replace()"
argument_list|)
operator|<<
literal|"IN = foo 'bar baz'\nVAR = $$replace(IN, \\\\bba, hello)"
operator|<<
literal|"VAR = foo 'hellor helloz'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$replace(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$replace(1, 2) \\\n$$replace(1, 2, 3, 4)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: replace(var, before, after) requires three arguments.\n"
literal|"##:2: replace(var, before, after) requires three arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$sort_depends()"
argument_list|)
operator|<<
literal|"foo.depends = bar baz\n"
literal|"bar.depends = baz bak duck\n"
literal|"baz.depends = bak\n"
literal|"bak.depends = duck\n"
literal|"VAR = $$sort_depends($$list(baz foo duck bar))"
operator|<<
literal|"VAR = foo bar baz duck"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$resolve_depends(): basic"
argument_list|)
operator|<<
literal|"foo.depends = bar baz\n"
literal|"bar.depends = baz bak duck\n"
literal|"baz.depends = bak\n"
literal|"bak.depends = duck\n"
literal|"VAR = $$resolve_depends($$list(baz foo duck bar))"
operator|<<
literal|"VAR = foo bar baz bak duck"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$resolve_depends(): prefix and multiple suffixes"
argument_list|)
operator|<<
literal|"MOD.foo.dep = bar baz\n"
literal|"MOD.bar.dep = baz bak\n"
literal|"MOD.bar.priv_dep = duck\n"
literal|"MOD.baz.dep = bak\n"
literal|"MOD.bak.dep = duck\n"
literal|"VAR = $$resolve_depends($$list(baz foo duck bar), MOD., .dep .priv_dep)"
operator|<<
literal|"VAR = foo bar baz bak duck"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$resolve_depends(): priorities: b first"
argument_list|)
operator|<<
literal|"MOD.a.depends =\n"
literal|"MOD.b.depends =\n"
literal|"MOD.b.priority = 1\n"
literal|"MOD.c.depends = a b\n"
literal|"VAR = $$resolve_depends($$list(c), MOD.)"
operator|<<
literal|"VAR = c b a"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$resolve_depends(): priorities: a first"
argument_list|)
operator|<<
literal|"MOD.a.depends =\n"
literal|"MOD.a.priority = 1\n"
literal|"MOD.b.depends =\n"
literal|"MOD.b.priority = 0\n"
literal|"MOD.c.depends = a b\n"
literal|"VAR = $$resolve_depends($$list(c), MOD.)"
operator|<<
literal|"VAR = c a b"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$resolve_depends(): priorities: custom suffix"
argument_list|)
operator|<<
literal|"MOD.a.depends =\n"
literal|"MOD.a.prrt = 1\n"
literal|"MOD.b.depends =\n"
literal|"MOD.b.prrt = 0\n"
literal|"MOD.c.depends = a b\n"
literal|"VAR = $$resolve_depends($$list(c), MOD., .depends, .prrt)"
operator|<<
literal|"VAR = c a b"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$resolve_depends(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$resolve_depends(1, 2, 3, 4, 5)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: resolve_depends(var, [prefix, [suffixes, [prio-suffix]]]) requires one to four arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$enumerate_vars()"
argument_list|)
operator|<<
literal|"V1 = foo\nV2 = bar\nVAR = $$enumerate_vars()\n"
literal|"count(VAR, 2,>=):contains(VAR, V1):contains(VAR, V2): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shadowed(): bare"
argument_list|)
operator|<<
literal|"VAR = $$shadowed(test.txt)"
operator|<<
literal|"VAR = "
operator|+
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
operator|+
literal|"/test.txt"
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shadowed(): subdir"
argument_list|)
operator|<<
literal|"VAR = $$shadowed("
operator|+
name|qindir
operator|+
literal|"/sub/test.txt)"
operator|<<
literal|"VAR = "
operator|+
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
operator|+
literal|"/sub/test.txt"
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shadowed(): outside source dir"
argument_list|)
operator|<<
literal|"VAR = $$shadowed(/some/random/path)"
operator|<<
literal|"VAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shadowed(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$shadowed(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: shadowed(path) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$absolute_path(): relative file"
argument_list|)
operator|<<
literal|"VAR = $$absolute_path(dir/file.ext)"
operator|<<
literal|"VAR = "
operator|+
name|qindir
operator|+
literal|"/dir/file.ext"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$absolute_path(): file& path"
argument_list|)
operator|<<
literal|"VAR = $$absolute_path(dir/file.ext, /root/sub)"
operator|<<
literal|"VAR = /root/sub/dir/file.ext"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$absolute_path(): absolute file& path"
argument_list|)
operator|<<
literal|"VAR = $$absolute_path(/root/sub/dir/file.ext, /other)"
operator|<<
literal|"VAR = /root/sub/dir/file.ext"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$absolute_path(): empty file& path"
argument_list|)
operator|<<
literal|"VAR = $$absolute_path('', /root/sub)"
operator|<<
literal|"VAR = /root/sub"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$absolute_path(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$absolute_path(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: absolute_path(path[, base]) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$relative_path(): relative file"
argument_list|)
operator|<<
literal|"VAR = $$relative_path(dir/file.ext)"
operator|<<
literal|"VAR = dir/file.ext"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$relative_path(): relative file to empty"
argument_list|)
operator|<<
literal|"VAR = $$relative_path(dir/..)"
operator|<<
literal|"VAR = ."
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$relative_path(): absolute file& path"
argument_list|)
operator|<<
literal|"VAR = $$relative_path(/root/sub/dir/file.ext, /root/sub)"
operator|<<
literal|"VAR = dir/file.ext"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$relative_path(): empty file& path"
argument_list|)
operator|<<
literal|"VAR = $$relative_path('', /root/sub)"
operator|<<
literal|"VAR = ."
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$relative_path(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$relative_path(1, 2, 3)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: relative_path(path[, base]) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$clean_path()"
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN
comment|// This is actually kinda stupid.
operator|<<
literal|"VAR = $$clean_path(foo//bar\\\\../baz/)"
else|#
directive|else
operator|<<
literal|"VAR = $$clean_path(foo//bar/../baz/)"
endif|#
directive|endif
operator|<<
literal|"VAR = foo/baz"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$clean_path(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$clean_path(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: clean_path(path) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system_path()"
argument_list|)
operator|<<
literal|"VAR = $$system_path(foo/bar\\\\baz)"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"VAR = foo\\\\bar\\\\baz"
else|#
directive|else
operator|<<
literal|"VAR = foo/bar/baz"
endif|#
directive|endif
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system_path(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$system_path(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: system_path(path) requires one argument."
operator|<<
literal|true
expr_stmt|;
comment|// This is is effectively $$system_path() in this test, as we load no specs
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shell_path()"
argument_list|)
operator|<<
literal|"VAR = $$shell_path(foo/bar\\\\baz)"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"VAR = foo\\\\bar\\\\baz"
else|#
directive|else
operator|<<
literal|"VAR = foo/bar/baz"
endif|#
directive|endif
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shell_path(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$shell_path(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: shell_path(path) requires one argument."
operator|<<
literal|true
expr_stmt|;
comment|// The quoteArgs() test exercises this more thoroughly
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system_quote()"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$system_quote(\"some nasty& ugly\\\" path& thing\\\\\")"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"VAR = \"\\\"some nasty& ugly\\\\\\\" path ^& thing\\\\\\\\^\\\"\""
else|#
directive|else
operator|<<
literal|"VAR = \"'some nasty& ugly\\\" path& thing\\\\'\""
endif|#
directive|endif
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$system_quote(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$system_quote(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: system_quote(arg) requires one argument."
operator|<<
literal|true
expr_stmt|;
comment|// This is is effectively $$system_path() in this test, as we load no specs
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shell_quote()"
argument_list|)
operator|<<
literal|"IN = \nVAR = $$shell_quote(\"some nasty& ugly\\\" path& thing\\\\\")"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"VAR = \"\\\"some nasty& ugly\\\\\\\" path ^& thing\\\\\\\\^\\\"\""
else|#
directive|else
operator|<<
literal|"VAR = \"'some nasty& ugly\\\" path& thing\\\\'\""
endif|#
directive|endif
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$shell_quote(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$shell_quote(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: shell_quote(arg) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$getenv()"
argument_list|)
operator|<<
literal|"VAR = $$getenv(E1)"
operator|<<
literal|"VAR = 'env var'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"$$getenv(): bad number of arguments"
argument_list|)
operator|<<
literal|"VAR = $$getenv(1, 2)"
operator|<<
literal|"VAR ="
operator|<<
literal|"##:1: getenv(arg) requires one argument."
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|addTestFunctions
name|void
name|tst_qmakelib
operator|::
name|addTestFunctions
parameter_list|(
specifier|const
name|QString
modifier|&
name|qindir
parameter_list|)
block|{
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(): found replace"
argument_list|)
operator|<<
literal|"defineReplace(func) {}\ndefined(func): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(): found test"
argument_list|)
operator|<<
literal|"defineTest(func) {}\ndefined(func): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(): not found"
argument_list|)
operator|<<
literal|"defined(func): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(replace): found"
argument_list|)
operator|<<
literal|"defineReplace(func) {}\ndefined(func, replace): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(replace): not found"
argument_list|)
operator|<<
literal|"defineTest(func) {}\ndefined(func, replace): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(test): found"
argument_list|)
operator|<<
literal|"defineTest(func) {}\ndefined(func, test): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(test): not found"
argument_list|)
operator|<<
literal|"defineReplace(func) {}\ndefined(func, test): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(var): found"
argument_list|)
operator|<<
literal|"VAR = 1\ndefined(VAR, var): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(var): not found"
argument_list|)
operator|<<
literal|"defined(VAR, var): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(): invalid type"
argument_list|)
operator|<<
literal|"defined(VAR, nope): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: defined(function, type): unexpected type [nope]."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"defined(): bad number of arguments"
argument_list|)
operator|<<
literal|"defined(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: defined(function, [\"test\"|\"replace\"|\"var\"]) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"export()"
argument_list|)
operator|<<
literal|"defineTest(func) {\n"
literal|"VAR1 += different\nexport(VAR1)\n"
literal|"unset(VAR2)\nexport(VAR2): OK = 1\nexport(OK)\n"
literal|"VAR3 = new var\nexport(VAR3)\n"
literal|"}\n"
literal|"VAR1 = entirely\nVAR2 = set\nfunc()"
operator|<<
literal|"OK = 1\nVAR1 = entirely different\nVAR2 =\nVAR3 = new var"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"export(): bad number of arguments"
argument_list|)
operator|<<
literal|"export(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: export(variable) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(): found"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, DEFINES): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(): not found"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, INCLUDES): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(plain): found"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, DEFINES, QT_DLL): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(plain): not found"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, DEFINES, NOPE): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(regex): found"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, DEFINES, QT_.*): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(regex): not found"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/infile.prx, DEFINES, NO.*): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// The early return is debatable, esp. as it's inconsistent with $$fromfile()
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(): bad file"
argument_list|)
operator|<<
literal|"infile("
operator|+
name|qindir
operator|+
literal|"/fromfile/badfile.prx, DEFINES): OK = 1\nOKE = 1"
operator|<<
literal|"OK = UNDEF\nOKE = UNDEF"
operator|<<
literal|"Project ERROR: fail!"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"infile(): bad number of arguments"
argument_list|)
operator|<<
literal|"infile(1): OK = 1\ninfile(1, 2, 3, 4): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: infile(file, var, [values]) requires two or three arguments.\n"
literal|"##:2: infile(file, var, [values]) requires two or three arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"requires()"
argument_list|)
operator|<<
literal|"requires(true, false, isEmpty(FOO), !isEmpty(BAR), true|false, true:false)"
operator|<<
literal|"QMAKE_FAILED_REQUIREMENTS = false !isEmpty(BAR) true:false"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
comment|// The sparator semantics are *very* questionable.
comment|// The return value semantics are rather questionable.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"eval()"
argument_list|)
operator|<<
literal|"eval(FOO = one, two$$escape_expand(\\\\n)BAR = blah$$escape_expand(\\\\n)error(fail)$$escape_expand(\\\\n)BAZ = nope)"
operator|<<
literal|"FOO = one two\nBAR = blah\nBAZ = UNDEF"
operator|<<
literal|"Project ERROR: fail"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): true"
argument_list|)
operator|<<
literal|"if(false|true): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): true (space)"
argument_list|)
operator|<<
literal|"if(false| true): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): true (spaces)"
argument_list|)
operator|<<
literal|"if( false | true ): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): false"
argument_list|)
operator|<<
literal|"if(false:true): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): false (space)"
argument_list|)
operator|<<
literal|"if(false: true): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): false (spaces)"
argument_list|)
operator|<<
literal|"if( false : true ): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"if(): bad number of arguments"
argument_list|)
operator|<<
literal|"if(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: if(condition) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CONFIG(simple): true"
argument_list|)
operator|<<
literal|"CONFIG = debug release\nCONFIG(debug): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CONFIG(simple): false"
argument_list|)
operator|<<
literal|"CONFIG = debug release\nCONFIG(nope): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CONFIG(alt): true"
argument_list|)
operator|<<
literal|"CONFIG = debug release\nCONFIG(release, debug|release): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CONFIG(alt): false (presence)"
argument_list|)
operator|<<
literal|"CONFIG = not here\nCONFIG(debug, debug|release): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CONFIG(alt): false (order)"
argument_list|)
operator|<<
literal|"CONFIG = debug release\nCONFIG(debug, debug|release): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"CONFIG(): bad number of arguments"
argument_list|)
operator|<<
literal|"CONFIG(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: CONFIG(config) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(simple plain): true"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, two): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(simple plain): false"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, four): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(simple regex): true"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, tw.*): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(simple regex): false"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, fo.*): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(alt plain): true"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, three, two|three): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(alt plain): false (presence)"
argument_list|)
operator|<<
literal|"VAR = one four five\ncontains(VAR, three, two|three): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(alt plain): false (order)"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, two, two|three): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(alt regex): true"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, th.*, two|three): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(alt regex): false (presence)"
argument_list|)
operator|<<
literal|"VAR = one four five\ncontains(VAR, th.*, two|three): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(alt regex): false (order)"
argument_list|)
operator|<<
literal|"VAR = one two three\ncontains(VAR, tw.*, two|three): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"contains(): bad number of arguments"
argument_list|)
operator|<<
literal|"contains(1): OK = 1\ncontains(1, 2, 3, 4): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: contains(var, val) requires two or three arguments.\n"
literal|"##:2: contains(var, val) requires two or three arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"count(): true"
argument_list|)
operator|<<
literal|"VAR = one two three\ncount(VAR, 3): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"count(): false"
argument_list|)
operator|<<
literal|"VAR = one two three\ncount(VAR, 4): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"count(operators): true"
argument_list|)
operator|<<
literal|"VAR = one two three\n"
literal|"count(VAR, 3, equals): OKE1 = 1\n"
literal|"count(VAR, 3, isEqual): OKE2 = 1\n"
literal|"count(VAR, 3, =): OKE3 = 1\n"
literal|"count(VAR, 3, ==): OKE4 = 1\n"
literal|"count(VAR, 2, greaterThan): OKG1 = 1\n"
literal|"count(VAR, 2,>): OKG2 = 1\n"
literal|"count(VAR, 2,>=): OKGE = 1\n"
literal|"count(VAR, 4, lessThan): OKL1 = 1\n"
literal|"count(VAR, 4,<): OKL2 = 1\n"
literal|"count(VAR, 4,<=): OKLE = 1\n"
operator|<<
literal|"OKE1 = 1\nOKE2 = 1\nOKE3 = 1\nOKE4 = 1\n"
literal|"OKG1 = 1\nOKG2 = 1\nOKGE = 1\n"
literal|"OKL1 = 1\nOKL2 = 1\nOKLE = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"count(operators): false"
argument_list|)
operator|<<
literal|"VAR = one two three\n"
literal|"count(VAR, 4, equals): OKE1 = 1\n"
literal|"count(VAR, 4, isEqual): OKE2 = 1\n"
literal|"count(VAR, 4, =): OKE3 = 1\n"
literal|"count(VAR, 4, ==): OKE4 = 1\n"
literal|"count(VAR, 3, greaterThan): OKG1 = 1\n"
literal|"count(VAR, 3,>): OKG2 = 1\n"
literal|"count(VAR, 4,>=): OKGE = 1\n"
literal|"count(VAR, 3, lessThan): OKL1 = 1\n"
literal|"count(VAR, 3,<): OKL2 = 1\n"
literal|"count(VAR, 2,<=): OKLE = 1\n"
operator|<<
literal|"OKE1 = UNDEF\nOKE2 = UNDEF\nOKE3 = UNDEF\nOKE4 = UNDEF\n"
literal|"OKG1 = UNDEF\nOKG2 = UNDEF\nOKGE = UNDEF\n"
literal|"OKL1 = UNDEF\nOKL2 = UNDEF\nOKLE = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"count(): bad operator"
argument_list|)
operator|<<
literal|"VAR = one two three\ncount(VAR, 2, !!!): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:2: Unexpected modifier to count(!!!)."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"count(): bad number of arguments"
argument_list|)
operator|<<
literal|"count(1): OK = 1\ncount(1, 2, 3, 4): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: count(var, count, op=\"equals\") requires two or three arguments.\n"
literal|"##:2: count(var, count, op=\"equals\") requires two or three arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"greaterThan(int): true"
argument_list|)
operator|<<
literal|"VAR = 20\ngreaterThan(VAR, 3): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"greaterThan(int): false"
argument_list|)
operator|<<
literal|"VAR = 3\ngreaterThan(VAR, 20): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"greaterThan(string): true"
argument_list|)
operator|<<
literal|"VAR = foo 3\ngreaterThan(VAR, foo 20): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"greaterThan(string): false"
argument_list|)
operator|<<
literal|"VAR = foo 20\ngreaterThan(VAR, foo 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"greaterThan(): bad number of arguments"
argument_list|)
operator|<<
literal|"greaterThan(1): OK = 1\ngreaterThan(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: greaterThan(variable, value) requires two arguments.\n"
literal|"##:2: greaterThan(variable, value) requires two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lessThan(int): true"
argument_list|)
operator|<<
literal|"VAR = 3\nlessThan(VAR, 20): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lessThan(int): false"
argument_list|)
operator|<<
literal|"VAR = 20\nlessThan(VAR, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lessThan(string): true"
argument_list|)
operator|<<
literal|"VAR = foo 20\nlessThan(VAR, foo 3): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lessThan(string): false"
argument_list|)
operator|<<
literal|"VAR = foo 3\nlessThan(VAR, foo 20): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"lessThan(): bad number of arguments"
argument_list|)
operator|<<
literal|"lessThan(1): OK = 1\nlessThan(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: lessThan(variable, value) requires two arguments.\n"
literal|"##:2: lessThan(variable, value) requires two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"equals(): true"
argument_list|)
operator|<<
literal|"VAR = foo\nequals(VAR, foo): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"equals(): false"
argument_list|)
operator|<<
literal|"VAR = foo\nequals(VAR, bar): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"equals(): bad number of arguments"
argument_list|)
operator|<<
literal|"equals(1): OK = 1\nequals(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: equals(variable, value) requires two arguments.\n"
literal|"##:2: equals(variable, value) requires two arguments."
operator|<<
literal|true
expr_stmt|;
comment|// That's just an alias, so don't test much.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"isEqual(): true"
argument_list|)
operator|<<
literal|"VAR = foo\nisEqual(VAR, foo): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"clear(): top-level"
argument_list|)
operator|<<
literal|"VAR = there\nclear(VAR): OK = 1"
operator|<<
literal|"OK = 1\nVAR ="
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"clear(): scoped"
argument_list|)
operator|<<
literal|"defineTest(func) {\n"
literal|"clear(VAR): OK = 1\nexport(OK)\n"
literal|"equals(VAR, \"\"): OKE = 1\nexport(OKE)\n"
literal|"}\n"
literal|"VAR = there\nfunc()"
operator|<<
literal|"OK = 1\nOKE = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"clear(): absent"
argument_list|)
operator|<<
literal|"clear(VAR): OK = 1"
operator|<<
literal|"OK = UNDEF\nVAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"clear(): bad number of arguments"
argument_list|)
operator|<<
literal|"clear(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: clear(variable) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unset(): top-level"
argument_list|)
operator|<<
literal|"VAR = there\nunset(VAR): OK = 1"
operator|<<
literal|"OK = 1\nVAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unset(): scoped"
argument_list|)
operator|<<
literal|"defineTest(func) {\n"
literal|"unset(VAR): OK = 1\nexport(OK)\n"
literal|"!defined(VAR, var): OKE = 1\nexport(OKE)\n"
literal|"}\n"
literal|"VAR = there\nfunc()"
operator|<<
literal|"OK = 1\nOKE = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unset(): absent"
argument_list|)
operator|<<
literal|"unset(VAR): OK = 1"
operator|<<
literal|"OK = UNDEF\nVAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unset(): bad number of arguments"
argument_list|)
operator|<<
literal|"unset(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: unset(variable) requires one argument."
operator|<<
literal|true
expr_stmt|;
comment|// This function does not follow the established naming pattern.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"parseJson()"
argument_list|)
operator|<<
literal|"jsontext = \\\n"
literal|"    \"{\"\\\n"
literal|"    \"    \\\"array\\\" : [\\\"arrayItem1\\\", \\\"arrayItem2\\\", \\\"arrayItem3\\\"],\"\\\n"
literal|"    \"    \\\"object\\\" : { \\\"key1\\\" : \\\"objectValue1\\\", \\\"key2\\\" : \\\"objectValue2\\\" },\"\\\n"
literal|"    \"    \\\"string\\\" : \\\"test string\\\",\"\\\n"
literal|"    \"    \\\"number\\\" : 999,\"\\\n"
literal|"    \"    \\\"true\\\" : true,\"\\\n"
literal|"    \"    \\\"false\\\" :false,\"\"\\\n"
literal|"    \"    \\\"null\\\" : null\"\"\\\n"
literal|"    \"}\"\n"
literal|"parseJson(jsontext, json): OK = 1"
operator|<<
literal|"OK = 1\n"
literal|"json._KEYS_ = array false null number object string true\n"
comment|// array
literal|"json.array._KEYS_ = 0 1 2\n"
literal|"json.array.0 = arrayItem1\n"
literal|"json.array.1 = arrayItem2\n"
literal|"json.array.2 = arrayItem3\n"
comment|// object
literal|"json.object._KEYS_ = key1 key2\n"
literal|"json.object.key1 = objectValue1\n"
literal|"json.object.key1 = objectValue1\n"
comment|// value types
literal|"json.string = 'test string'\n"
literal|"json.number = 999\n"
literal|"json.true = true\n"
literal|"json.false = false\n"
literal|"json.null = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"parseJson(): bad input"
argument_list|)
operator|<<
literal|"jsontext = not good\n"
literal|"parseJson(jsontext, json): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"parseJson(): bad number of arguments"
argument_list|)
operator|<<
literal|"parseJson(1): OK = 1\nparseJson(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: parseJson(variable, into) requires two arguments.\n"
literal|"##:2: parseJson(variable, into) requires two arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"include()"
argument_list|)
operator|<<
literal|"include(include/inc.pri): OK = 1\nfunc()"
operator|<<
literal|"OK = 1\nVAR = val\n.VAR = nope"
operator|<<
literal|"Project MESSAGE: say hi!"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"include(): fail"
argument_list|)
operator|<<
literal|"include(include/nope.pri): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"Cannot read "
operator|+
name|m_indir
operator|+
literal|"/include/nope.pri: No such file or directory"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"include(): silent fail"
argument_list|)
operator|<<
literal|"include(include/nope.pri, , true): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"include(into)"
argument_list|)
operator|<<
literal|"SUB.MISS = 1\ninclude(include/inc.pri, SUB): OK = 1"
operator|<<
literal|"OK = 1\nSUB.VAR = val\nSUB..VAR = UNDEF\nSUB.MISS = UNDEF\n"
comment|// As a side effect, we test some things that need full project setup
literal|"SUB.MATCH = 1\nSUB.QMAKESPEC = "
operator|+
name|qindir
operator|+
literal|"/mkspecs/fake-g++"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"include(): bad number of arguments"
argument_list|)
operator|<<
literal|"include(1, 2, 3, 4): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: include(file, [into, [silent]]) requires one, two or three arguments."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"load()"
argument_list|)
operator|<<
literal|"load(testfeat): OK = 1"
operator|<<
literal|"OK = 1\nVAR = foo bar"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"load(): fail"
argument_list|)
operator|<<
literal|"load(no_such_feature): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: Cannot find feature no_such_feature"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"load(): silent fail"
argument_list|)
operator|<<
literal|"load(no_such_feature, true): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"load(): bad number of arguments"
argument_list|)
operator|<<
literal|"load(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: load(feature) requires one or two arguments."
operator|<<
literal|true
expr_stmt|;
comment|// We don't test debug() and log(), because they print directly to stderr.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"message()"
argument_list|)
operator|<<
literal|"message('Hello, World!'): OK = 1\nOKE = 1"
operator|<<
literal|"OK = 1\nOKE = 1"
operator|<<
literal|"Project MESSAGE: Hello, World!"
operator|<<
literal|true
expr_stmt|;
comment|// Don't test that for warning() and error(), as it's the same code path.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"message(): bad number of arguments"
argument_list|)
operator|<<
literal|"message(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: message(message) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"warning()"
argument_list|)
operator|<<
literal|"warning('World, be warned!'): OK = 1\nOKE = 1"
operator|<<
literal|"OK = 1\nOKE = 1"
operator|<<
literal|"Project WARNING: World, be warned!"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"error()"
argument_list|)
operator|<<
literal|"error('World, you FAIL!'): OK = 1\nOKE = 1"
operator|<<
literal|"OK = UNDEF\nOKE = UNDEF"
operator|<<
literal|"Project ERROR: World, you FAIL!"
operator|<<
literal|false
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"system()"
argument_list|)
operator|<<
literal|"system('"
ifdef|#
directive|ifdef
name|Q_OS_WIN
literal|"cd"
else|#
directive|else
literal|"pwd"
endif|#
directive|endif
literal|"> '"
operator|+
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|m_outdir
operator|+
literal|"/system_out.txt"
argument_list|)
argument_list|)
argument_list|)
operator|+
literal|"): OK = 1\n"
literal|"DIR = $$cat("
operator|+
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
operator|+
literal|"/system_out.txt"
argument_list|)
argument_list|)
operator|+
literal|")"
operator|<<
literal|"OK = 1\nDIR = "
operator|+
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|m_indir
argument_list|)
argument_list|)
argument_list|)
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"system(): fail"
argument_list|)
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"system(no_such_cmd 2> NUL): OK = 1"
else|#
directive|else
operator|<<
literal|"system(no_such_cmd 2> /dev/null): OK = 1"
endif|#
directive|endif
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"system(): bad number of arguments"
argument_list|)
operator|<<
literal|"system(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: system(exec) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"isEmpty(): true (empty)"
argument_list|)
operator|<<
literal|"VAR =\nisEmpty(VAR): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"isEmpty(): true (undef)"
argument_list|)
operator|<<
literal|"isEmpty(VAR): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"isEmpty(): false"
argument_list|)
operator|<<
literal|"VAR = val\nisEmpty(VAR): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"isEmpty(): bad number of arguments"
argument_list|)
operator|<<
literal|"isEmpty(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: isEmpty(var) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exists(plain): true"
argument_list|)
operator|<<
literal|"exists(files/file1.txt): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exists(plain): false"
argument_list|)
operator|<<
literal|"exists(files/not_there.txt): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exists(wildcard): true"
argument_list|)
operator|<<
literal|"exists(files/fil*.txt): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exists(wildcard): false"
argument_list|)
operator|<<
literal|"exists(files/not_th*.txt): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"exists(): bad number of arguments"
argument_list|)
operator|<<
literal|"exists(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: exists(file) requires one argument."
operator|<<
literal|true
expr_stmt|;
name|QString
name|wpath
init|=
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
operator|+
literal|"/outdir/written.txt"
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"write_file(): create"
argument_list|)
operator|<<
literal|"VAR = 'this is text' 'yet again'\n"
literal|"write_file("
operator|+
name|wpath
operator|+
literal|", VAR): OK = 1\n"
literal|"OUT = $$cat("
operator|+
name|wpath
operator|+
literal|", lines)"
operator|<<
literal|"OK = 1\nOUT = 'this is text' 'yet again'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"write_file(): truncate"
argument_list|)
operator|<<
literal|"VAR = 'other content'\n"
literal|"write_file("
operator|+
name|wpath
operator|+
literal|", VAR): OK = 1\n"
literal|"OUT = $$cat("
operator|+
name|wpath
operator|+
literal|", lines)"
operator|<<
literal|"OK = 1\nOUT = 'other content'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"write_file(): append"
argument_list|)
operator|<<
literal|"VAR = 'one more line'\n"
literal|"write_file("
operator|+
name|wpath
operator|+
literal|", VAR, append): OK = 1\n"
literal|"OUT = $$cat("
operator|+
name|wpath
operator|+
literal|", lines)"
operator|<<
literal|"OK = 1\nOUT = 'other content' 'one more line'"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QString
name|vpath
init|=
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"write_file(): fail"
argument_list|)
operator|<<
literal|"write_file("
operator|+
name|vpath
operator|+
literal|"): OK = 1"
operator|<<
literal|"OK = UNDEF"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"##:1: Cannot write file "
operator|+
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|m_outdir
argument_list|)
operator|+
literal|": Access is denied."
else|#
directive|else
operator|<<
literal|"##:1: Cannot write file "
operator|+
name|m_outdir
operator|+
literal|": Is a directory"
endif|#
directive|endif
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"write_file(): bad number of arguments"
argument_list|)
operator|<<
literal|"write_file(1, 2, 3, 4): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: write_file(name, [content var, [append]]) requires one to three arguments."
operator|<<
literal|true
expr_stmt|;
comment|// FIXME: This doesn't test whether it actually works.
name|QTest
operator|::
name|newRow
argument_list|(
literal|"touch()"
argument_list|)
operator|<<
literal|"touch("
operator|+
name|wpath
operator|+
literal|", files/other.txt): OK = 1"
operator|<<
literal|"OK = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"touch(): missing target"
argument_list|)
operator|<<
literal|"touch(/does/not/exist, files/other.txt): OK = 1"
operator|<<
literal|"OK = UNDEF"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"##:1: Cannot open /does/not/exist: The system cannot find the path specified."
else|#
directive|else
operator|<<
literal|"##:1: Cannot touch /does/not/exist: No such file or directory."
endif|#
directive|endif
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"touch(): missing reference"
argument_list|)
operator|<<
literal|"touch("
operator|+
name|wpath
operator|+
literal|", /does/not/exist): OK = 1"
operator|<<
literal|"OK = UNDEF"
ifdef|#
directive|ifdef
name|Q_OS_WIN
operator|<<
literal|"##:1: Cannot open reference file /does/not/exist: The system cannot find the path specified."
else|#
directive|else
operator|<<
literal|"##:1: Cannot stat() reference file /does/not/exist: No such file or directory."
endif|#
directive|endif
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"touch(): bad number of arguments"
argument_list|)
operator|<<
literal|"touch(1): OK = 1\ntouch(1, 2, 3): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: touch(file, reffile) requires two arguments.\n"
literal|"##:2: touch(file, reffile) requires two arguments."
operator|<<
literal|true
expr_stmt|;
name|QString
name|apath
init|=
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
operator|+
literal|"/a/path"
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mkpath()"
argument_list|)
operator|<<
literal|"mkpath("
operator|+
name|apath
operator|+
literal|"): OK = 1\n"
literal|"exists("
operator|+
name|apath
operator|+
literal|"): OKE = 1"
operator|<<
literal|"OK = 1\nOKE = 1"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|QString
name|bpath
init|=
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_outdir
operator|+
literal|"/fail_me"
argument_list|)
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mkpath(): fail"
argument_list|)
operator|<<
literal|"write_file("
operator|+
name|bpath
operator|+
literal|")|error(FAIL)\n"
literal|"mkpath("
operator|+
name|bpath
operator|+
literal|"): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:2: Cannot create directory "
operator|+
name|QDir
operator|::
name|toNativeSeparators
argument_list|(
name|m_outdir
operator|+
literal|"/fail_me"
argument_list|)
operator|+
literal|'.'
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mkpath(): bad number of arguments"
argument_list|)
operator|<<
literal|"mkpath(1, 2): OK = 1"
operator|<<
literal|"OK = UNDEF"
operator|<<
literal|"##:1: mkpath(file) requires one argument."
operator|<<
literal|true
expr_stmt|;
if|#
directive|if
literal|0
comment|// FIXME ... insanity lies ahead
block|QTest::newRow("cache()")<< ""<< ""<< ""<< true;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|proEval_data
name|void
name|tst_qmakelib
operator|::
name|proEval_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"in"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"out"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QString
argument_list|>
argument_list|(
literal|"msgs"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"ok"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty"
argument_list|)
operator|<<
literal|""
operator|<<
literal|"VAR = UNDEF"
operator|<<
literal|""
operator|<<
literal|true
expr_stmt|;
name|addAssignments
argument_list|()
expr_stmt|;
name|addExpansions
argument_list|()
expr_stmt|;
comment|// Variable, etc. expansions on RHS
name|addControlStructs
argument_list|()
expr_stmt|;
comment|// Conditions, loops, custom functions
name|QString
name|qindir
init|=
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|ProString
argument_list|(
name|m_indir
argument_list|)
argument_list|)
decl_stmt|;
name|addReplaceFunctions
argument_list|(
name|qindir
argument_list|)
expr_stmt|;
comment|// Built-in replace functions
name|addTestFunctions
argument_list|(
name|qindir
argument_list|)
expr_stmt|;
comment|// Built-in test functions
comment|// Some compound tests that verify compatibility with odd Qt 4 edge cases
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty (leading)"
argument_list|)
operator|<<
literal|"defineTest(myMsg) { message(\"$$1\") }\n"
literal|"XMPL = /this/is/a/test\n"
literal|"message(split: $$split(XMPL, /))\n"
literal|"message(split joined:$$split(XMPL, /))\n"
literal|"message(\"split quoted: $$split(XMPL, /)\")\n"
literal|"myMsg(my split: $$split(XMPL, /) :post)\n"
literal|"myMsg(my split joined:$$split(XMPL, /):post)\n"
literal|"myMsg(\"my split quoted: $$split(XMPL, /) post\")\n"
literal|"OUT = word $$split(XMPL, /) done\n"
literal|"message(\"assign split separate: $$OUT\")\n"
literal|"OUT = word:$$split(XMPL, /):done\n"
literal|"message(\"assign split joined: $$OUT\")\n"
literal|"OUT = \"word $$split(XMPL, /) done\"\n"
literal|"message(\"assign split quoted: $$OUT\")\n"
operator|<<
literal|""
operator|<<
literal|"Project MESSAGE: split: this is a test\n"
literal|"Project MESSAGE: split joined: this is a test\n"
literal|"Project MESSAGE: split quoted:  this is a test\n"
literal|"Project MESSAGE: my split: this is a test :post\n"
literal|"Project MESSAGE: my split joined: this is a test:post\n"
literal|"Project MESSAGE: my split quoted:  this is a test post\n"
literal|"Project MESSAGE: assign split separate: word this is a test done\n"
literal|"Project MESSAGE: assign split joined: word: this is a test:done\n"
literal|"Project MESSAGE: assign split quoted: word  this is a test done"
operator|<<
literal|true
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"empty (multiple)"
argument_list|)
operator|<<
literal|"defineTest(myMsg) { message(\"$$1\") }\n"
literal|"XMPL = //this///is/a/////test\n"
literal|"message(split: $$split(XMPL, /) :post)\n"
literal|"message(split joined:$$split(XMPL, /):post)\n"
literal|"message(\"split quoted: $$split(XMPL, /) post\")\n"
literal|"myMsg(my split: $$split(XMPL, /) :post)\n"
literal|"myMsg(my split joined:$$split(XMPL, /):post)\n"
literal|"myMsg(\"my split quoted: $$split(XMPL, /) post\")\n"
literal|"OUT = word $$split(XMPL, /) done\n"
literal|"message(\"assign split separate: $$OUT\")\n"
literal|"OUT = word:$$split(XMPL, /):done\n"
literal|"message(\"assign split joined: $$OUT\")\n"
literal|"OUT = \"word $$split(XMPL, /) done\"\n"
literal|"message(\"assign split quoted: $$OUT\")\n"
operator|<<
literal|""
operator|<<
literal|"Project MESSAGE: split:  this   is a     test :post\n"
literal|"Project MESSAGE: split joined:  this   is a     test:post\n"
literal|"Project MESSAGE: split quoted:   this   is a     test post\n"
literal|"Project MESSAGE: my split:  this   is a     test :post\n"
literal|"Project MESSAGE: my split joined:  this   is a     test:post\n"
literal|"Project MESSAGE: my split quoted:   this   is a     test post\n"
literal|"Project MESSAGE: assign split separate: word this is a test done\n"
literal|"Project MESSAGE: assign split joined: word: this is a test:done\n"
literal|"Project MESSAGE: assign split quoted: word   this   is a     test done"
operator|<<
literal|true
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatValue
specifier|static
name|QString
name|formatValue
parameter_list|(
specifier|const
name|ProStringList
modifier|&
name|vals
parameter_list|)
block|{
name|QString
name|ret
decl_stmt|;
foreach|foreach
control|(
specifier|const
name|ProString
modifier|&
name|str
decl|,
name|vals
control|)
block|{
name|ret
operator|+=
name|QLatin1Char
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|ret
operator|+=
name|QMakeEvaluator
operator|::
name|quoteValue
argument_list|(
name|str
argument_list|)
expr_stmt|;
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|skipNoise
specifier|static
name|void
name|skipNoise
parameter_list|(
specifier|const
name|ushort
modifier|*
modifier|&
name|tokPtr
parameter_list|)
block|{
forever|forever
block|{
name|ushort
name|tok
init|=
operator|*
name|tokPtr
decl_stmt|;
if|if
condition|(
name|tok
operator|!=
name|TokLine
condition|)
break|break;
name|tokPtr
operator|+=
literal|2
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|compareState
specifier|static
name|bool
name|compareState
parameter_list|(
name|QMakeEvaluator
modifier|*
name|eval
parameter_list|,
name|ProFile
modifier|*
name|out
parameter_list|)
block|{
name|bool
name|ret
init|=
literal|true
decl_stmt|;
specifier|const
name|ushort
modifier|*
name|tokPtr
init|=
name|out
operator|->
name|tokPtr
argument_list|()
decl_stmt|;
forever|forever
block|{
name|skipNoise
argument_list|(
name|tokPtr
argument_list|)
expr_stmt|;
name|ushort
name|tok
init|=
operator|*
name|tokPtr
operator|++
decl_stmt|;
if|if
condition|(
operator|!
name|tok
condition|)
break|break;
if|if
condition|(
name|tok
operator|!=
name|TokHashLiteral
condition|)
block|{
name|qWarning
argument_list|(
literal|"Expected output is malformed: not variable%s"
argument_list|,
name|qPrintable
argument_list|(
name|QMakeParser
operator|::
name|formatProBlock
argument_list|(
name|out
operator|->
name|items
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
specifier|const
name|ProKey
modifier|&
name|var
init|=
name|out
operator|->
name|getHashStr
argument_list|(
name|tokPtr
argument_list|)
decl_stmt|;
name|tok
operator|=
operator|*
name|tokPtr
operator|++
expr_stmt|;
if|if
condition|(
name|tok
operator|!=
name|TokAssign
condition|)
block|{
name|qWarning
argument_list|(
literal|"Expected output is malformed: not assignment%s"
argument_list|,
name|qPrintable
argument_list|(
name|QMakeParser
operator|::
name|formatProBlock
argument_list|(
name|out
operator|->
name|items
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|ProStringList
name|value
decl_stmt|;
name|value
operator|.
name|reserve
argument_list|(
operator|*
name|tokPtr
operator|++
argument_list|)
expr_stmt|;
forever|forever
block|{
name|skipNoise
argument_list|(
name|tokPtr
argument_list|)
expr_stmt|;
name|tok
operator|=
operator|*
name|tokPtr
operator|++
expr_stmt|;
if|if
condition|(
name|tok
operator|==
name|TokValueTerminator
condition|)
break|break;
if|if
condition|(
name|tok
operator|!=
operator|(
name|TokLiteral
operator||
name|TokNewStr
operator|)
condition|)
block|{
name|qWarning
argument_list|(
literal|"Expected output is malformed: not literal%s"
argument_list|,
name|qPrintable
argument_list|(
name|QMakeParser
operator|::
name|formatProBlock
argument_list|(
name|out
operator|->
name|items
argument_list|()
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return
literal|false
return|;
block|}
name|value
operator|<<
name|out
operator|->
name|getStr
argument_list|(
name|tokPtr
argument_list|)
expr_stmt|;
block|}
name|ProValueMap
operator|::
name|Iterator
name|it
decl_stmt|;
name|ProValueMap
modifier|*
name|vmap
init|=
name|eval
operator|->
name|findValues
argument_list|(
name|var
argument_list|,
operator|&
name|it
argument_list|)
decl_stmt|;
if|if
condition|(
name|value
operator|.
name|length
argument_list|()
operator|==
literal|1
operator|&&
name|value
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
literal|"UNDEF"
condition|)
block|{
if|if
condition|(
name|vmap
condition|)
block|{
name|qWarning
argument_list|(
literal|"Value of %s is incorrect.\n  Actual:%s\nExpected:<UNDEFINED>"
argument_list|,
name|qPrintable
argument_list|(
name|var
operator|.
name|toQString
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|formatValue
argument_list|(
operator|*
name|it
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|false
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
operator|!
name|vmap
condition|)
block|{
name|qWarning
argument_list|(
literal|"Value of %s is incorrect.\n  Actual:<UNDEFINED>\nExpected:%s"
argument_list|,
name|qPrintable
argument_list|(
name|var
operator|.
name|toQString
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|formatValue
argument_list|(
name|value
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|false
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|*
name|it
operator|!=
name|value
condition|)
block|{
name|qWarning
argument_list|(
literal|"Value of %s is incorrect.\n  Actual:%s\nExpected:%s"
argument_list|,
name|qPrintable
argument_list|(
name|var
operator|.
name|toQString
argument_list|()
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|formatValue
argument_list|(
operator|*
name|it
argument_list|)
argument_list|)
argument_list|,
name|qPrintable
argument_list|(
name|formatValue
argument_list|(
name|value
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|false
expr_stmt|;
block|}
block|}
block|}
return|return
name|ret
return|;
block|}
end_function
begin_function
DECL|function|proEval
name|void
name|tst_qmakelib
operator|::
name|proEval
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|in
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|out
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QString
argument_list|,
name|msgs
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|ok
argument_list|)
expr_stmt|;
name|QString
name|infile
init|=
name|m_indir
operator|+
literal|"/test.pro"
decl_stmt|;
name|bool
name|verified
init|=
literal|true
decl_stmt|;
name|QMakeTestHandler
name|handler
decl_stmt|;
name|handler
operator|.
name|setExpectedMessages
argument_list|(
name|msgs
operator|.
name|replace
argument_list|(
literal|"##:"
argument_list|,
name|infile
operator|+
literal|':'
argument_list|)
operator|.
name|split
argument_list|(
literal|'\n'
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
argument_list|)
expr_stmt|;
name|QMakeVfs
name|vfs
decl_stmt|;
name|QMakeParser
name|parser
argument_list|(
literal|0
argument_list|,
operator|&
name|vfs
argument_list|,
operator|&
name|handler
argument_list|)
decl_stmt|;
name|QMakeGlobals
name|globals
decl_stmt|;
name|globals
operator|.
name|do_cache
operator|=
literal|false
expr_stmt|;
name|globals
operator|.
name|xqmakespec
operator|=
literal|"fake-g++"
expr_stmt|;
name|globals
operator|.
name|environment
operator|=
name|m_env
expr_stmt|;
name|globals
operator|.
name|setProperties
argument_list|(
name|m_prop
argument_list|)
expr_stmt|;
name|globals
operator|.
name|setDirectories
argument_list|(
name|m_indir
argument_list|,
name|m_outdir
argument_list|)
expr_stmt|;
name|ProFile
modifier|*
name|outPro
init|=
name|parser
operator|.
name|parsedProBlock
argument_list|(
name|out
argument_list|,
literal|"out"
argument_list|,
literal|1
argument_list|,
name|QMakeParser
operator|::
name|FullGrammar
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|outPro
operator|->
name|isOk
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Expected output is malformed"
argument_list|)
expr_stmt|;
name|verified
operator|=
literal|false
expr_stmt|;
block|}
name|ProFile
modifier|*
name|pro
init|=
name|parser
operator|.
name|parsedProBlock
argument_list|(
name|in
argument_list|,
name|infile
argument_list|,
literal|1
argument_list|,
name|QMakeParser
operator|::
name|FullGrammar
argument_list|)
decl_stmt|;
name|QMakeEvaluator
name|visitor
argument_list|(
operator|&
name|globals
argument_list|,
operator|&
name|parser
argument_list|,
operator|&
name|vfs
argument_list|,
operator|&
name|handler
argument_list|)
decl_stmt|;
name|visitor
operator|.
name|setOutputDir
argument_list|(
name|m_outdir
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|Q_OS_WIN
name|visitor
operator|.
name|m_dirSep
operator|=
name|ProString
argument_list|(
literal|"\\"
argument_list|)
expr_stmt|;
else|#
directive|else
name|visitor
operator|.
name|m_dirSep
operator|=
name|ProString
argument_list|(
literal|"/"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|QMakeEvaluator
operator|::
name|VisitReturn
name|ret
init|=
name|visitor
operator|.
name|visitProFile
argument_list|(
name|pro
argument_list|,
name|QMakeHandler
operator|::
name|EvalAuxFile
argument_list|,
name|QMakeEvaluator
operator|::
name|LoadProOnly
argument_list|)
decl_stmt|;
if|if
condition|(
name|handler
operator|.
name|printedMessages
argument_list|()
condition|)
block|{
name|qWarning
argument_list|(
literal|"Got unexpected message(s)"
argument_list|)
expr_stmt|;
name|verified
operator|=
literal|false
expr_stmt|;
block|}
name|QStringList
name|missingMsgs
init|=
name|handler
operator|.
name|expectedMessages
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|missingMsgs
operator|.
name|isEmpty
argument_list|()
condition|)
block|{
foreach|foreach
control|(
specifier|const
name|QString
modifier|&
name|msg
decl|,
name|missingMsgs
control|)
name|qWarning
argument_list|(
literal|"Missing message: %s"
argument_list|,
name|qPrintable
argument_list|(
name|msg
argument_list|)
argument_list|)
expr_stmt|;
name|verified
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|ret
operator|==
name|QMakeEvaluator
operator|::
name|ReturnTrue
operator|)
operator|!=
name|ok
condition|)
block|{
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|lbl
index|[]
init|=
block|{
literal|"failure"
block|,
literal|"success"
block|}
decl_stmt|;
name|qWarning
argument_list|(
literal|"Expected %s, got %s"
argument_list|,
name|lbl
index|[
name|int
argument_list|(
name|ok
argument_list|)
index|]
argument_list|,
name|lbl
index|[
literal|1
operator|-
name|int
argument_list|(
name|ok
argument_list|)
index|]
argument_list|)
expr_stmt|;
name|verified
operator|=
literal|false
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|compareState
argument_list|(
operator|&
name|visitor
argument_list|,
name|outPro
argument_list|)
condition|)
name|verified
operator|=
literal|false
expr_stmt|;
name|pro
operator|->
name|deref
argument_list|()
expr_stmt|;
name|outPro
operator|->
name|deref
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|verified
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
