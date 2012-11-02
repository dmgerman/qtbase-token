begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Giuseppe D'Angelo<dangelog@gmail.com>. ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QString>
end_include
begin_include
include|#
directive|include
file|<QStringList>
end_include
begin_include
include|#
directive|include
file|<QRegularExpression>
end_include
begin_include
include|#
directive|include
file|<QRegularExpressionMatch>
end_include
begin_include
include|#
directive|include
file|<QRegularExpressionMatchIterator>
end_include
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
block|{
comment|//! [0]
name|QRegularExpression
name|re
argument_list|(
literal|"a pattern"
argument_list|)
decl_stmt|;
comment|//! [0]
block|}
block|{
comment|//! [1]
name|QRegularExpression
name|re
decl_stmt|;
name|re
operator|.
name|setPattern
argument_list|(
literal|"another pattern"
argument_list|)
expr_stmt|;
comment|//! [1]
block|}
block|{
comment|//! [2]
comment|// matches two digits followed by a space and a word
name|QRegularExpression
name|re
argument_list|(
literal|"\\d\\d \\w+"
argument_list|)
decl_stmt|;
comment|// matches a backslash
name|QRegularExpression
name|re2
argument_list|(
literal|"\\\\"
argument_list|)
decl_stmt|;
comment|//! [2]
block|}
block|{
comment|//! [3]
name|QRegularExpression
name|re
argument_list|(
literal|"a third pattern"
argument_list|)
decl_stmt|;
name|QString
name|pattern
init|=
name|re
operator|.
name|pattern
argument_list|()
decl_stmt|;
comment|// pattern == "a third pattern"
comment|//! [3]
block|}
block|{
comment|//! [4]
comment|// matches "Qt rocks", but also "QT rocks", "QT ROCKS", "qT rOcKs", etc.
name|QRegularExpression
name|re
argument_list|(
literal|"Qt rocks"
argument_list|,
name|QRegularExpression
operator|::
name|CaseInsensitiveOption
argument_list|)
decl_stmt|;
comment|//! [4]
block|}
block|{
comment|//! [5]
name|QRegularExpression
name|re
argument_list|(
literal|"^\\d+$"
argument_list|)
decl_stmt|;
name|re
operator|.
name|setPatternOptions
argument_list|(
name|QRegularExpression
operator|::
name|MultilineOption
argument_list|)
expr_stmt|;
comment|// re matches any line in the subject string that contains only digits (but at least one)
comment|//! [5]
block|}
block|{
comment|//! [6]
name|QRegularExpression
name|re
init|=
name|QRegularExpression
argument_list|(
literal|"^two.*words$"
argument_list|,
name|QRegularExpression
operator|::
name|MultilineOption
operator||
name|QRegularExpression
operator|::
name|DotMatchesEverythingOption
argument_list|)
decl_stmt|;
name|QRegularExpression
operator|::
name|PatternOptions
name|options
init|=
name|re
operator|.
name|patternOptions
argument_list|()
decl_stmt|;
comment|// options == QRegularExpression::MultilineOption | QRegularExpression::DotMatchesEverythingOption
comment|//! [6]
block|}
block|{
comment|//! [7]
comment|// match two digits followed by a space and a word
name|QRegularExpression
name|re
argument_list|(
literal|"\\d\\d \\w+"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"abc123 def"
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// true
comment|//! [7]
block|}
block|{
comment|//! [8]
name|QRegularExpression
name|re
argument_list|(
literal|"\\d\\d \\w+"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"abc123 def"
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
block|{
name|QString
name|matched
init|=
name|match
operator|.
name|captured
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// matched == "23 def"
comment|// ...
block|}
comment|//! [8]
block|}
block|{
comment|//! [9]
name|QRegularExpression
name|re
argument_list|(
literal|"\\d\\d \\w+"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"12 abc 45 def"
argument_list|,
literal|1
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
block|{
name|QString
name|matched
init|=
name|match
operator|.
name|captured
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// matched == "45 def"
comment|// ...
block|}
comment|//! [9]
block|}
block|{
comment|//! [10]
name|QRegularExpression
name|re
argument_list|(
literal|"^(\\d\\d)/(\\d\\d)/(\\d\\d\\d\\d)$"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"08/12/1985"
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
block|{
name|QString
name|day
init|=
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// day == "08"
name|QString
name|month
init|=
name|match
operator|.
name|captured
argument_list|(
literal|2
argument_list|)
decl_stmt|;
comment|// month == "12"
name|QString
name|year
init|=
name|match
operator|.
name|captured
argument_list|(
literal|3
argument_list|)
decl_stmt|;
comment|// year == "1985"
comment|// ...
block|}
comment|//! [10]
block|}
block|{
comment|//! [11]
name|QRegularExpression
name|re
argument_list|(
literal|"abc(\\d+)def"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"XYZabc123defXYZ"
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
block|{
name|int
name|startOffset
init|=
name|match
operator|.
name|capturedStart
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// startOffset == 6
name|int
name|endOffset
init|=
name|match
operator|.
name|capturedEnd
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// endOffset == 9
comment|// ...
block|}
comment|//! [11]
block|}
block|{
comment|//! [12]
name|QRegularExpression
name|re
argument_list|(
literal|"^(?<date>\\d\\d)/(?<month>\\d\\d)/(?<year>\\d\\d\\d\\d)$"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"08/12/1985"
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
block|{
name|QString
name|date
init|=
name|match
operator|.
name|captured
argument_list|(
literal|"date"
argument_list|)
decl_stmt|;
comment|// date == "08"
name|QString
name|month
init|=
name|match
operator|.
name|captured
argument_list|(
literal|"month"
argument_list|)
decl_stmt|;
comment|// month == "12"
name|QString
name|year
init|=
name|match
operator|.
name|captured
argument_list|(
literal|"year"
argument_list|)
decl_stmt|;
comment|// year == 1985
block|}
comment|//! [12]
block|}
block|{
comment|//! [13]
name|QRegularExpression
name|re
argument_list|(
literal|"(\\w+)"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatchIterator
name|i
init|=
name|re
operator|.
name|globalMatch
argument_list|(
literal|"the quick fox"
argument_list|)
decl_stmt|;
comment|//! [13]
comment|//! [14]
name|QStringList
name|words
decl_stmt|;
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QRegularExpressionMatch
name|match
init|=
name|i
operator|.
name|next
argument_list|()
decl_stmt|;
name|QString
name|word
init|=
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
decl_stmt|;
name|words
operator|<<
name|word
expr_stmt|;
block|}
comment|// words contains "the", "quick", "fox"
comment|//! [14]
block|}
block|{
comment|//! [15]
name|QString
name|pattern
argument_list|(
literal|"^(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) \\d\\d?, \\d\\d\\d\\d$"
argument_list|)
decl_stmt|;
name|QRegularExpression
name|re
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
name|QString
name|input
argument_list|(
literal|"Jan 21,"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
name|input
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferCompleteMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// false
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// true
comment|//! [15]
block|}
block|{
name|QString
name|pattern
argument_list|(
literal|"^(Jan|Feb|Mar|Apr|May|Jun|Jul|Aug|Sep|Oct|Nov|Dec) \\d\\d?, \\d\\d\\d\\d$"
argument_list|)
decl_stmt|;
name|QRegularExpression
name|re
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
comment|//! [16]
name|QString
name|input
argument_list|(
literal|"Dec 8, 1985"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
name|input
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferCompleteMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// true
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// false
comment|//! [16]
block|}
block|{
comment|//! [17]
name|QRegularExpression
name|re
argument_list|(
literal|"abc\\w+X|def"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"abcdef"
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferCompleteMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// true
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// false
name|QString
name|captured
init|=
name|match
operator|.
name|captured
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// captured == "def"
comment|//! [17]
block|}
block|{
comment|//! [18]
name|QRegularExpression
name|re
argument_list|(
literal|"abc\\w+X|defY"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"abcdef"
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferCompleteMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// false
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// true
name|QString
name|captured
init|=
name|match
operator|.
name|captured
argument_list|(
literal|0
argument_list|)
decl_stmt|;
comment|// captured == "abcdef"
comment|//! [18]
block|}
block|{
comment|//! [19]
name|QRegularExpression
name|re
argument_list|(
literal|"abc|ab"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"ab"
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferFirstMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// false
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// true
comment|//! [19]
block|}
block|{
comment|//! [20]
name|QRegularExpression
name|re
argument_list|(
literal|"abc(def)?"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"abc"
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferFirstMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// false
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// true
comment|//! [20]
block|}
block|{
comment|//! [21]
name|QRegularExpression
name|re
argument_list|(
literal|"(abc)*"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"abc"
argument_list|,
literal|0
argument_list|,
name|QRegularExpression
operator|::
name|PartialPreferFirstMatch
argument_list|)
decl_stmt|;
name|bool
name|hasMatch
init|=
name|match
operator|.
name|hasMatch
argument_list|()
decl_stmt|;
comment|// false
name|bool
name|hasPartialMatch
init|=
name|match
operator|.
name|hasPartialMatch
argument_list|()
decl_stmt|;
comment|// true
comment|//! [21]
block|}
block|{
comment|//! [22]
name|QRegularExpression
name|invalidRe
argument_list|(
literal|"(unmatched|parenthesis"
argument_list|)
decl_stmt|;
name|bool
name|isValid
init|=
name|invalidRe
operator|.
name|isValid
argument_list|()
decl_stmt|;
comment|// false
comment|//! [22]
block|}
block|{
comment|//! [23]
name|QRegularExpression
name|invalidRe
argument_list|(
literal|"(unmatched|parenthesis"
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|invalidRe
operator|.
name|isValid
argument_list|()
condition|)
block|{
name|QString
name|errorString
init|=
name|invalidRe
operator|.
name|errorString
argument_list|()
decl_stmt|;
comment|// errorString == "missing )"
name|int
name|errorOffset
init|=
name|invalidRe
operator|.
name|patternErrorOffset
argument_list|()
decl_stmt|;
comment|// errorOffset == 22
comment|// ...
block|}
comment|//! [23]
block|}
block|{
comment|//! [24]
name|QRegularExpression
name|re
argument_list|(
literal|"^this pattern must match exactly$"
argument_list|)
decl_stmt|;
comment|//! [24]
block|}
block|{
comment|//! [25]
name|QString
name|p
argument_list|(
literal|"a .*|pattern"
argument_list|)
decl_stmt|;
name|QRegularExpression
name|re
argument_list|(
literal|"\\A(?:"
operator|+
name|p
operator|+
literal|")\\z"
argument_list|)
decl_stmt|;
comment|// re matches exactly the pattern string p
comment|//! [25]
block|}
block|{
comment|//! [26]
name|QString
name|escaped
init|=
name|QRegularExpression
operator|::
name|escape
argument_list|(
literal|"a(x) = f(x) + g(x)"
argument_list|)
decl_stmt|;
comment|// escaped == "a\\(x\\)\\ \\=\\ f\\(x\\)\\ \\+\\ g\\(x\\)"
comment|//! [26]
block|}
block|{
name|QString
name|name
decl_stmt|;
name|QString
name|nickname
decl_stmt|;
comment|//! [27]
name|QString
name|pattern
init|=
literal|"("
operator|+
name|QRegularExpression
operator|::
name|escape
argument_list|(
name|name
argument_list|)
operator|+
literal|"|"
operator|+
name|QRegularExpression
operator|::
name|escape
argument_list|(
name|nickname
argument_list|)
operator|+
literal|")"
decl_stmt|;
name|QRegularExpression
name|re
argument_list|(
name|pattern
argument_list|)
decl_stmt|;
comment|//! [27]
block|}
block|{
name|QString
name|string
decl_stmt|;
name|QRegularExpression
name|re
decl_stmt|;
comment|//! [28]
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
name|string
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
operator|<=
name|match
operator|.
name|lastCapturedIndex
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|QString
name|captured
init|=
name|match
operator|.
name|captured
argument_list|(
name|i
argument_list|)
decl_stmt|;
comment|// ...
block|}
comment|//! [28]
block|}
block|{
comment|//! [29]
name|QRegularExpression
name|re
argument_list|(
literal|"(\\d\\d) (?<name>\\w+)"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatch
name|match
init|=
name|re
operator|.
name|match
argument_list|(
literal|"23 Jordan"
argument_list|)
decl_stmt|;
if|if
condition|(
name|match
operator|.
name|hasMatch
argument_list|()
condition|)
block|{
name|QString
name|number
init|=
name|match
operator|.
name|captured
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// first == "23"
name|QString
name|name
init|=
name|match
operator|.
name|captured
argument_list|(
literal|"name"
argument_list|)
decl_stmt|;
comment|// name == "Jordan"
block|}
comment|//! [29]
block|}
block|{
comment|//! [30]
comment|// extracts the words
name|QRegularExpression
name|re
argument_list|(
literal|"(\\w+)"
argument_list|)
decl_stmt|;
name|QString
name|subject
argument_list|(
literal|"the quick fox"
argument_list|)
decl_stmt|;
name|QRegularExpressionMatchIterator
name|i
init|=
name|re
operator|.
name|globalMatch
argument_list|(
name|subject
argument_list|)
decl_stmt|;
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|QRegularExpressionMatch
name|match
init|=
name|i
operator|.
name|next
argument_list|()
decl_stmt|;
comment|// ...
block|}
comment|//! [30]
block|}
block|}
end_function
end_unit
