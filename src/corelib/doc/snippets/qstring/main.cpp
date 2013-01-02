begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtGui>
end_include
begin_include
include|#
directive|include
file|<QApplication>
end_include
begin_include
include|#
directive|include
file|<stdio.h>
end_include
begin_class
DECL|class|Widget
class|class
name|Widget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|void
name|constCharPointer
parameter_list|()
function_decl|;
name|void
name|constCharArray
parameter_list|()
function_decl|;
name|void
name|characterReference
parameter_list|()
function_decl|;
name|void
name|atFunction
parameter_list|()
function_decl|;
name|void
name|stringLiteral
parameter_list|()
function_decl|;
name|void
name|modify
parameter_list|()
function_decl|;
name|void
name|index
parameter_list|()
function_decl|;
name|QString
name|boolToString
parameter_list|(
name|bool
name|b
parameter_list|)
function_decl|;
name|void
name|nullVsEmpty
parameter_list|()
function_decl|;
name|void
name|appendFunction
parameter_list|()
function_decl|;
name|void
name|argFunction
parameter_list|()
function_decl|;
name|void
name|chopFunction
parameter_list|()
function_decl|;
name|void
name|compareFunction
parameter_list|()
function_decl|;
name|void
name|compareSensitiveFunction
parameter_list|()
function_decl|;
name|void
name|containsFunction
parameter_list|()
function_decl|;
name|void
name|countFunction
parameter_list|()
function_decl|;
name|void
name|dataFunction
parameter_list|()
function_decl|;
name|void
name|endsWithFunction
parameter_list|()
function_decl|;
name|void
name|fillFunction
parameter_list|()
function_decl|;
name|void
name|fromRawDataFunction
parameter_list|()
function_decl|;
name|void
name|indexOfFunction
parameter_list|()
function_decl|;
name|void
name|firstIndexOfFunction
parameter_list|()
function_decl|;
name|void
name|insertFunction
parameter_list|()
function_decl|;
name|void
name|isNullFunction
parameter_list|()
function_decl|;
name|void
name|isEmptyFunction
parameter_list|()
function_decl|;
name|void
name|lastIndexOfFunction
parameter_list|()
function_decl|;
name|void
name|leftFunction
parameter_list|()
function_decl|;
name|void
name|leftJustifiedFunction
parameter_list|()
function_decl|;
name|void
name|leftRefFunction
parameter_list|()
function_decl|;
name|void
name|midFunction
parameter_list|()
function_decl|;
name|void
name|midRefFunction
parameter_list|()
function_decl|;
name|void
name|numberFunction
parameter_list|()
function_decl|;
name|void
name|prependFunction
parameter_list|()
function_decl|;
name|void
name|removeFunction
parameter_list|()
function_decl|;
name|void
name|replaceFunction
parameter_list|()
function_decl|;
name|void
name|reserveFunction
parameter_list|()
function_decl|;
name|void
name|resizeFunction
parameter_list|()
function_decl|;
name|void
name|rightFunction
parameter_list|()
function_decl|;
name|void
name|rightJustifiedFunction
parameter_list|()
function_decl|;
name|void
name|rightRefFunction
parameter_list|()
function_decl|;
name|void
name|sectionFunction
parameter_list|()
function_decl|;
name|void
name|setNumFunction
parameter_list|()
function_decl|;
name|void
name|simplifiedFunction
parameter_list|()
function_decl|;
name|void
name|sizeFunction
parameter_list|()
function_decl|;
name|void
name|splitFunction
parameter_list|()
function_decl|;
name|void
name|splitCaseSensitiveFunction
parameter_list|()
function_decl|;
name|void
name|sprintfFunction
parameter_list|()
function_decl|;
name|void
name|startsWithFunction
parameter_list|()
function_decl|;
name|void
name|toDoubleFunction
parameter_list|()
function_decl|;
name|void
name|toFloatFunction
parameter_list|()
function_decl|;
name|void
name|toIntFunction
parameter_list|()
function_decl|;
name|void
name|toLongFunction
parameter_list|()
function_decl|;
name|void
name|toLongLongFunction
parameter_list|()
function_decl|;
name|void
name|toLowerFunction
parameter_list|()
function_decl|;
name|void
name|toShortFunction
parameter_list|()
function_decl|;
name|void
name|toUIntFunction
parameter_list|()
function_decl|;
name|void
name|toULongFunction
parameter_list|()
function_decl|;
name|void
name|toULongLongFunction
parameter_list|()
function_decl|;
name|void
name|toUShortFunction
parameter_list|()
function_decl|;
name|void
name|toUpperFunction
parameter_list|()
function_decl|;
name|void
name|trimmedFunction
parameter_list|()
function_decl|;
name|void
name|truncateFunction
parameter_list|()
function_decl|;
name|void
name|plusEqualOperator
parameter_list|()
function_decl|;
name|void
name|arrayOperator
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|Widget
name|Widget
operator|::
name|Widget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{ }
end_constructor
begin_function
DECL|function|constCharPointer
name|void
name|Widget
operator|::
name|constCharPointer
parameter_list|()
block|{
comment|//! [0]
name|QString
name|str
init|=
literal|"Hello"
decl_stmt|;
comment|//! [0]
block|}
end_function
begin_function
DECL|function|constCharArray
name|void
name|Widget
operator|::
name|constCharArray
parameter_list|()
block|{
comment|//! [1]
specifier|static
specifier|const
name|QChar
name|data
index|[
literal|4
index|]
init|=
block|{
literal|0x0055
block|,
literal|0x006e
block|,
literal|0x10e3
block|,
literal|0x03a3
block|}
decl_stmt|;
name|QString
name|str
argument_list|(
name|data
argument_list|,
literal|4
argument_list|)
decl_stmt|;
comment|//! [1]
block|}
end_function
begin_function
DECL|function|characterReference
name|void
name|Widget
operator|::
name|characterReference
parameter_list|()
block|{
comment|//! [2]
name|QString
name|str
decl_stmt|;
name|str
operator|.
name|resize
argument_list|(
literal|4
argument_list|)
expr_stmt|;
name|str
index|[
literal|0
index|]
operator|=
name|QChar
argument_list|(
literal|'U'
argument_list|)
expr_stmt|;
name|str
index|[
literal|1
index|]
operator|=
name|QChar
argument_list|(
literal|'n'
argument_list|)
expr_stmt|;
name|str
index|[
literal|2
index|]
operator|=
name|QChar
argument_list|(
literal|0x10e3
argument_list|)
expr_stmt|;
name|str
index|[
literal|3
index|]
operator|=
name|QChar
argument_list|(
literal|0x03a3
argument_list|)
expr_stmt|;
comment|//! [2]
block|}
end_function
begin_function
DECL|function|atFunction
name|void
name|Widget
operator|::
name|atFunction
parameter_list|()
block|{
comment|//! [3]
name|QString
name|str
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
name|str
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|str
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|>=
name|QChar
argument_list|(
literal|'a'
argument_list|)
operator|&&
name|str
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<=
name|QChar
argument_list|(
literal|'f'
argument_list|)
condition|)
name|qDebug
argument_list|()
operator|<<
literal|"Found character in range [a-f]"
expr_stmt|;
block|}
comment|//! [3]
block|}
end_function
begin_function
DECL|function|stringLiteral
name|void
name|Widget
operator|::
name|stringLiteral
parameter_list|()
block|{
comment|//! [4]
name|QString
name|str
decl_stmt|;
if|if
condition|(
name|str
operator|==
literal|"auto"
operator|||
name|str
operator|==
literal|"extern"
operator|||
name|str
operator|==
literal|"static"
operator|||
name|str
operator|==
literal|"register"
condition|)
block|{
comment|// ...
block|}
comment|//! [4]
block|}
end_function
begin_function
DECL|function|modify
name|void
name|Widget
operator|::
name|modify
parameter_list|()
block|{
comment|//! [5]
name|QString
name|str
init|=
literal|"and"
decl_stmt|;
name|str
operator|.
name|prepend
argument_list|(
literal|"rock "
argument_list|)
expr_stmt|;
comment|// str == "rock and"
name|str
operator|.
name|append
argument_list|(
literal|" roll"
argument_list|)
expr_stmt|;
comment|// str == "rock and roll"
name|str
operator|.
name|replace
argument_list|(
literal|5
argument_list|,
literal|3
argument_list|,
literal|"&"
argument_list|)
expr_stmt|;
comment|// str == "rock& roll"
comment|//! [5]
block|}
end_function
begin_function
DECL|function|index
name|void
name|Widget
operator|::
name|index
parameter_list|()
block|{
comment|//! [6]
name|QString
name|str
init|=
literal|"We must be<b>bold</b>, very<b>bold</b>"
decl_stmt|;
name|int
name|j
init|=
literal|0
decl_stmt|;
while|while
condition|(
operator|(
name|j
operator|=
name|str
operator|.
name|indexOf
argument_list|(
literal|"<b>"
argument_list|,
name|j
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
literal|"Found<b> tag at index position"
operator|<<
name|j
expr_stmt|;
operator|++
name|j
expr_stmt|;
block|}
comment|//! [6]
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|boolToString
name|QString
name|Widget
operator|::
name|boolToString
parameter_list|(
name|bool
name|b
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
if|if
condition|(
name|b
condition|)
name|result
operator|=
literal|"True"
expr_stmt|;
else|else
name|result
operator|=
literal|"False"
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_function
DECL|function|nullVsEmpty
name|void
name|Widget
operator|::
name|nullVsEmpty
parameter_list|()
block|{
comment|//! [8]
name|QString
argument_list|()
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns true
name|QString
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QString
argument_list|(
literal|""
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
name|QString
argument_list|(
literal|""
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QString
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
name|QString
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns false
comment|//! [8]
block|}
end_function
begin_function
DECL|function|appendFunction
name|void
name|Widget
operator|::
name|appendFunction
parameter_list|()
block|{
comment|//! [9]
name|QString
name|x
init|=
literal|"free"
decl_stmt|;
name|QString
name|y
init|=
literal|"dom"
decl_stmt|;
name|x
operator|.
name|append
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// x == "freedom"
comment|//! [9]
comment|//! [10]
name|x
operator|.
name|insert
argument_list|(
name|x
operator|.
name|size
argument_list|()
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|//! [10]
block|}
end_function
begin_function
DECL|function|argFunction
name|void
name|Widget
operator|::
name|argFunction
parameter_list|()
block|{
comment|//! [11]
name|QString
name|i
decl_stmt|;
comment|// current file's number
name|QString
name|total
decl_stmt|;
comment|// number of files to process
name|QString
name|fileName
decl_stmt|;
comment|// current file's name
name|QString
name|status
init|=
name|QString
argument_list|(
literal|"Processing file %1 of %2: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|i
argument_list|)
operator|.
name|arg
argument_list|(
name|total
argument_list|)
operator|.
name|arg
argument_list|(
name|fileName
argument_list|)
decl_stmt|;
comment|//! [11]
comment|//! [12] //! [13]
name|QString
name|str
decl_stmt|;
comment|//! [12]
name|str
operator|=
literal|"%1 %2"
expr_stmt|;
name|str
operator|.
name|arg
argument_list|(
literal|"%1f"
argument_list|,
literal|"Hello"
argument_list|)
expr_stmt|;
comment|// returns "%1f Hello"
name|str
operator|.
name|arg
argument_list|(
literal|"%1f"
argument_list|)
operator|.
name|arg
argument_list|(
literal|"Hello"
argument_list|)
expr_stmt|;
comment|// returns "Hellof %2"
comment|//! [13]
comment|//! [14]
name|str
operator|=
name|QString
argument_list|(
literal|"Decimal 63 is %1 in hexadecimal"
argument_list|)
operator|.
name|arg
argument_list|(
literal|63
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// str == "Decimal 63 is 3f in hexadecimal"
name|QLocale
operator|::
name|setDefault
argument_list|(
name|QLocale
argument_list|(
name|QLocale
operator|::
name|English
argument_list|,
name|QLocale
operator|::
name|UnitedStates
argument_list|)
argument_list|)
expr_stmt|;
name|str
operator|=
name|QString
argument_list|(
literal|"%1 %L2 %L3"
argument_list|)
operator|.
name|arg
argument_list|(
literal|12345
argument_list|)
operator|.
name|arg
argument_list|(
literal|12345
argument_list|)
operator|.
name|arg
argument_list|(
literal|12345
argument_list|,
literal|0
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// str == "12345 12,345 3039"
comment|//! [14]
block|}
end_function
begin_function
DECL|function|chopFunction
name|void
name|Widget
operator|::
name|chopFunction
parameter_list|()
block|{
comment|//! [15]
name|QString
name|str
argument_list|(
literal|"LOGOUT\r\n"
argument_list|)
decl_stmt|;
name|str
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|// str == "LOGOUT"
comment|//! [15]
block|}
end_function
begin_function
DECL|function|compareFunction
name|void
name|Widget
operator|::
name|compareFunction
parameter_list|()
block|{
name|int
name|x
init|=
name|QString
operator|::
name|compare
argument_list|(
literal|"auto"
argument_list|,
literal|"auto"
argument_list|)
decl_stmt|;
comment|// x == 0
name|int
name|y
init|=
name|QString
operator|::
name|compare
argument_list|(
literal|"auto"
argument_list|,
literal|"car"
argument_list|)
decl_stmt|;
comment|// y< 0
name|int
name|z
init|=
name|QString
operator|::
name|compare
argument_list|(
literal|"car"
argument_list|,
literal|"auto"
argument_list|)
decl_stmt|;
comment|// z> 0
block|}
end_function
begin_function
DECL|function|compareSensitiveFunction
name|void
name|Widget
operator|::
name|compareSensitiveFunction
parameter_list|()
block|{
comment|//! [16]
name|int
name|x
init|=
name|QString
operator|::
name|compare
argument_list|(
literal|"aUtO"
argument_list|,
literal|"AuTo"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
decl_stmt|;
comment|// x == 0
name|int
name|y
init|=
name|QString
operator|::
name|compare
argument_list|(
literal|"auto"
argument_list|,
literal|"Car"
argument_list|,
name|Qt
operator|::
name|CaseSensitive
argument_list|)
decl_stmt|;
comment|// y> 0
name|int
name|z
init|=
name|QString
operator|::
name|compare
argument_list|(
literal|"auto"
argument_list|,
literal|"Car"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
decl_stmt|;
comment|// z< 0
comment|//! [16]
block|}
end_function
begin_function
DECL|function|containsFunction
name|void
name|Widget
operator|::
name|containsFunction
parameter_list|()
block|{
comment|//! [17]
name|QString
name|str
init|=
literal|"Peter Pan"
decl_stmt|;
name|str
operator|.
name|contains
argument_list|(
literal|"peter"
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
comment|// returns true
comment|//! [17]
block|}
end_function
begin_function
DECL|function|countFunction
name|void
name|Widget
operator|::
name|countFunction
parameter_list|()
block|{
comment|//! [18]
name|QString
name|str
init|=
literal|"banana and panama"
decl_stmt|;
name|str
operator|.
name|count
argument_list|(
name|QRegExp
argument_list|(
literal|"a[nm]a"
argument_list|)
argument_list|)
expr_stmt|;
comment|// returns 4
comment|//! [18]
comment|//! [95]
name|QString
name|str
init|=
literal|"banana and panama"
decl_stmt|;
name|str
operator|.
name|count
argument_list|(
name|QRegularExpression
argument_list|(
literal|"a[nm]a"
argument_list|)
argument_list|)
expr_stmt|;
comment|// returns 4
comment|//! [95]
block|}
end_function
begin_function
DECL|function|dataFunction
name|void
name|Widget
operator|::
name|dataFunction
parameter_list|()
block|{
comment|//! [19]
name|QString
name|str
init|=
literal|"Hello world"
decl_stmt|;
name|QChar
modifier|*
name|data
init|=
name|str
operator|.
name|data
argument_list|()
decl_stmt|;
while|while
condition|(
operator|!
name|data
operator|->
name|isNull
argument_list|()
condition|)
block|{
name|qDebug
argument_list|()
operator|<<
name|data
operator|->
name|unicode
argument_list|()
expr_stmt|;
operator|++
name|data
expr_stmt|;
block|}
comment|//! [19]
block|}
end_function
begin_function
DECL|function|endsWithFunction
name|void
name|Widget
operator|::
name|endsWithFunction
parameter_list|()
block|{
comment|//! [20]
name|QString
name|str
init|=
literal|"Bananas"
decl_stmt|;
name|str
operator|.
name|endsWith
argument_list|(
literal|"anas"
argument_list|)
expr_stmt|;
comment|// returns true
name|str
operator|.
name|endsWith
argument_list|(
literal|"pple"
argument_list|)
expr_stmt|;
comment|// returns false
comment|//! [20]
block|}
end_function
begin_function
DECL|function|fillFunction
name|void
name|Widget
operator|::
name|fillFunction
parameter_list|()
block|{
comment|//! [21]
name|QString
name|str
init|=
literal|"Berlin"
decl_stmt|;
name|str
operator|.
name|fill
argument_list|(
literal|'z'
argument_list|)
expr_stmt|;
comment|// str == "zzzzzz"
name|str
operator|.
name|fill
argument_list|(
literal|'A'
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// str == "AA"
comment|//! [21]
block|}
end_function
begin_function
DECL|function|fromRawDataFunction
name|void
name|Widget
operator|::
name|fromRawDataFunction
parameter_list|()
block|{
comment|//! [22]
name|QRegExp
name|pattern
decl_stmt|;
specifier|static
specifier|const
name|QChar
name|unicode
index|[]
init|=
block|{
literal|0x005A
block|,
literal|0x007F
block|,
literal|0x00A4
block|,
literal|0x0060
block|,
literal|0x1009
block|,
literal|0x0020
block|,
literal|0x0020
block|}
decl_stmt|;
name|int
name|size
init|=
sizeof|sizeof
argument_list|(
name|unicode
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
decl_stmt|;
name|QString
name|str
init|=
name|QString
operator|::
name|fromRawData
argument_list|(
name|unicode
argument_list|,
name|size
argument_list|)
decl_stmt|;
if|if
condition|(
name|str
operator|.
name|contains
argument_list|(
name|QRegExp
argument_list|(
name|pattern
argument_list|)
argument_list|)
condition|)
block|{
comment|// ...
comment|//! [22] //! [23]
block|}
comment|//! [23]
block|}
end_function
begin_function
DECL|function|indexOfFunction
name|void
name|Widget
operator|::
name|indexOfFunction
parameter_list|()
block|{
comment|//! [24]
name|QString
name|x
init|=
literal|"sticky question"
decl_stmt|;
name|QString
name|y
init|=
literal|"sti"
decl_stmt|;
name|x
operator|.
name|indexOf
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// returns 0
name|x
operator|.
name|indexOf
argument_list|(
name|y
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// returns 10
name|x
operator|.
name|indexOf
argument_list|(
name|y
argument_list|,
literal|10
argument_list|)
expr_stmt|;
comment|// returns 10
name|x
operator|.
name|indexOf
argument_list|(
name|y
argument_list|,
literal|11
argument_list|)
expr_stmt|;
comment|// returns -1
comment|//! [24]
block|}
end_function
begin_function
DECL|function|firstIndexOfFunction
name|void
name|Widget
operator|::
name|firstIndexOfFunction
parameter_list|()
block|{
comment|//! [25]
name|QString
name|str
init|=
literal|"the minimum"
decl_stmt|;
name|str
operator|.
name|indexOf
argument_list|(
name|QRegExp
argument_list|(
literal|"m[aeiou]"
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// returns 4
comment|//! [25]
comment|//! [93]
name|QString
name|str
init|=
literal|"the minimum"
decl_stmt|;
name|str
operator|.
name|indexOf
argument_list|(
name|QRegularExpression
argument_list|(
literal|"m[aeiou]"
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// returns 4
comment|//! [93]
block|}
end_function
begin_function
DECL|function|insertFunction
name|void
name|Widget
operator|::
name|insertFunction
parameter_list|()
block|{
comment|//! [26]
name|QString
name|str
init|=
literal|"Meal"
decl_stmt|;
name|str
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
name|QString
argument_list|(
literal|"ontr"
argument_list|)
argument_list|)
expr_stmt|;
comment|// str == "Montreal"
comment|//! [26]
block|}
end_function
begin_function
DECL|function|isEmptyFunction
name|void
name|Widget
operator|::
name|isEmptyFunction
parameter_list|()
block|{
comment|//! [27]
name|QString
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QString
argument_list|(
literal|""
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QString
argument_list|(
literal|"x"
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns false
name|QString
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns false
comment|//! [27]
block|}
end_function
begin_function
DECL|function|isNullFunction
name|void
name|Widget
operator|::
name|isNullFunction
parameter_list|()
block|{
comment|//! [28]
name|QString
argument_list|()
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns true
name|QString
argument_list|(
literal|""
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
name|QString
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
comment|//! [28]
block|}
end_function
begin_function
DECL|function|lastIndexOfFunction
name|void
name|Widget
operator|::
name|lastIndexOfFunction
parameter_list|()
block|{
comment|//! [29]
name|QString
name|x
init|=
literal|"crazy azimuths"
decl_stmt|;
name|QString
name|y
init|=
literal|"az"
decl_stmt|;
name|x
operator|.
name|lastIndexOf
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// returns 6
name|x
operator|.
name|lastIndexOf
argument_list|(
name|y
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// returns 6
name|x
operator|.
name|lastIndexOf
argument_list|(
name|y
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// returns 2
name|x
operator|.
name|lastIndexOf
argument_list|(
name|y
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// returns -1
comment|//! [29]
comment|//! [30]
name|QString
name|str
init|=
literal|"the minimum"
decl_stmt|;
name|str
operator|.
name|lastIndexOf
argument_list|(
name|QRegExp
argument_list|(
literal|"m[aeiou]"
argument_list|)
argument_list|)
expr_stmt|;
comment|// returns 8
comment|//! [30]
comment|//! [94]
name|QString
name|str
init|=
literal|"the minimum"
decl_stmt|;
name|str
operator|.
name|lastIndexOf
argument_list|(
name|QRegularExpression
argument_list|(
literal|"m[aeiou]"
argument_list|)
argument_list|)
expr_stmt|;
comment|// returns 8
comment|//! [94]
block|}
end_function
begin_function
DECL|function|leftFunction
name|void
name|Widget
operator|::
name|leftFunction
parameter_list|()
block|{
comment|//! [31]
name|QString
name|x
init|=
literal|"Pineapple"
decl_stmt|;
name|QString
name|y
init|=
name|x
operator|.
name|left
argument_list|(
literal|4
argument_list|)
decl_stmt|;
comment|// y == "Pine"
comment|//! [31]
block|}
end_function
begin_function
DECL|function|leftJustifiedFunction
name|void
name|Widget
operator|::
name|leftJustifiedFunction
parameter_list|()
block|{
comment|//! [32]
name|QString
name|s
init|=
literal|"apple"
decl_stmt|;
name|QString
name|t
init|=
name|s
operator|.
name|leftJustified
argument_list|(
literal|8
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
comment|// t == "apple..."
comment|//! [32]
comment|//! [33]
name|QString
name|str
init|=
literal|"Pineapple"
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|leftJustified
argument_list|(
literal|5
argument_list|,
literal|'.'
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// str == "Pinea"
comment|//! [33]
block|}
end_function
begin_function
DECL|function|midFunction
name|void
name|Widget
operator|::
name|midFunction
parameter_list|()
block|{
comment|//! [34]
name|QString
name|x
init|=
literal|"Nine pineapples"
decl_stmt|;
name|QString
name|y
init|=
name|x
operator|.
name|mid
argument_list|(
literal|5
argument_list|,
literal|4
argument_list|)
decl_stmt|;
comment|// y == "pine"
name|QString
name|z
init|=
name|x
operator|.
name|mid
argument_list|(
literal|5
argument_list|)
decl_stmt|;
comment|// z == "pineapples"
comment|//! [34]
block|}
end_function
begin_function
DECL|function|numberFunction
name|void
name|Widget
operator|::
name|numberFunction
parameter_list|()
block|{
comment|//! [35]
name|long
name|a
init|=
literal|63
decl_stmt|;
name|QString
name|s
init|=
name|QString
operator|::
name|number
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// s == "3f"
name|QString
name|t
init|=
name|QString
operator|::
name|number
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
operator|.
name|toUpper
argument_list|()
decl_stmt|;
comment|// t == "3F"
comment|//! [35]
block|}
end_function
begin_function
DECL|function|prependFunction
name|void
name|Widget
operator|::
name|prependFunction
parameter_list|()
block|{
comment|//! [36]
name|QString
name|x
init|=
literal|"ship"
decl_stmt|;
name|QString
name|y
init|=
literal|"air"
decl_stmt|;
name|x
operator|.
name|prepend
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// x == "airship"
comment|//! [36]
block|}
end_function
begin_function
DECL|function|removeFunction
name|void
name|Widget
operator|::
name|removeFunction
parameter_list|()
block|{
comment|//! [37]
name|QString
name|s
init|=
literal|"Montreal"
decl_stmt|;
name|s
operator|.
name|remove
argument_list|(
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// s == "Meal"
comment|//! [37]
comment|//! [38]
name|QString
name|t
init|=
literal|"Ali Baba"
decl_stmt|;
name|t
operator|.
name|remove
argument_list|(
name|QChar
argument_list|(
literal|'a'
argument_list|)
argument_list|,
name|Qt
operator|::
name|CaseInsensitive
argument_list|)
expr_stmt|;
comment|// t == "li Bb"
comment|//! [38]
comment|//! [39]
name|QString
name|r
init|=
literal|"Telephone"
decl_stmt|;
name|r
operator|.
name|remove
argument_list|(
name|QRegExp
argument_list|(
literal|"[aeiou]."
argument_list|)
argument_list|)
expr_stmt|;
comment|// r == "The"
comment|//! [39]
comment|//! [96]
name|QString
name|r
init|=
literal|"Telephone"
decl_stmt|;
name|r
operator|.
name|remove
argument_list|(
name|QRegularExpression
argument_list|(
literal|"[aeiou]."
argument_list|)
argument_list|)
expr_stmt|;
comment|// r == "The"
comment|//! [96]
block|}
end_function
begin_function
DECL|function|replaceFunction
name|void
name|Widget
operator|::
name|replaceFunction
parameter_list|()
block|{
comment|//! [40]
name|QString
name|x
init|=
literal|"Say yes!"
decl_stmt|;
name|QString
name|y
init|=
literal|"no"
decl_stmt|;
name|x
operator|.
name|replace
argument_list|(
literal|4
argument_list|,
literal|3
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|// x == "Say no!"
comment|//! [40]
comment|//! [41]
name|QString
name|str
init|=
literal|"colour behaviour flavour neighbour"
decl_stmt|;
name|str
operator|.
name|replace
argument_list|(
name|QString
argument_list|(
literal|"ou"
argument_list|)
argument_list|,
name|QString
argument_list|(
literal|"o"
argument_list|)
argument_list|)
expr_stmt|;
comment|// str == "color behavior flavor neighbor"
comment|//! [41]
comment|//! [42]
name|QString
name|s
init|=
literal|"Banana"
decl_stmt|;
name|s
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"a[mn]"
argument_list|)
argument_list|,
literal|"ox"
argument_list|)
expr_stmt|;
comment|// s == "Boxoxa"
comment|//! [42]
comment|//! [43]
name|QString
name|t
init|=
literal|"A<i>bon mot</i>."
decl_stmt|;
name|t
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"<i>([^<]*)</i>"
argument_list|)
argument_list|,
literal|"\\emph{\\1}"
argument_list|)
expr_stmt|;
comment|// t == "A \\emph{bon mot}."
comment|//! [43]
comment|//! [86]
name|QString
name|equis
init|=
literal|"xxxxxx"
decl_stmt|;
name|equis
operator|.
name|replace
argument_list|(
literal|"xx"
argument_list|,
literal|"x"
argument_list|)
expr_stmt|;
comment|// equis == "xxx"
comment|//! [86]
comment|//! [87]
name|QString
name|s
init|=
literal|"Banana"
decl_stmt|;
name|s
operator|.
name|replace
argument_list|(
name|QRegularExpression
argument_list|(
literal|"a[mn]"
argument_list|)
argument_list|,
literal|"ox"
argument_list|)
expr_stmt|;
comment|// s == "Boxoxa"
comment|//! [87]
comment|//! [88]
name|QString
name|t
init|=
literal|"A<i>bon mot</i>."
decl_stmt|;
name|t
operator|.
name|replace
argument_list|(
name|QRegularExpression
argument_list|(
literal|"<i>([^<]*)</i>"
argument_list|)
argument_list|,
literal|"\\emph{\\1}"
argument_list|)
expr_stmt|;
comment|// t == "A \\emph{bon mot}."
comment|//! [88]
block|}
end_function
begin_function
DECL|function|reserveFunction
name|void
name|Widget
operator|::
name|reserveFunction
parameter_list|()
block|{
comment|//! [44]
name|QString
name|result
decl_stmt|;
name|int
name|maxSize
decl_stmt|;
name|bool
name|condition
decl_stmt|;
name|QChar
name|nextChar
decl_stmt|;
name|result
operator|.
name|reserve
argument_list|(
name|maxSize
argument_list|)
expr_stmt|;
while|while
condition|(
name|condition
condition|)
name|result
operator|.
name|append
argument_list|(
name|nextChar
argument_list|)
expr_stmt|;
name|result
operator|.
name|squeeze
argument_list|()
expr_stmt|;
comment|//! [44]
block|}
end_function
begin_function
DECL|function|resizeFunction
name|void
name|Widget
operator|::
name|resizeFunction
parameter_list|()
block|{
comment|//! [45]
name|QString
name|s
init|=
literal|"Hello world"
decl_stmt|;
name|s
operator|.
name|resize
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|// s == "Hello"
name|s
operator|.
name|resize
argument_list|(
literal|8
argument_list|)
expr_stmt|;
comment|// s == "Hello???" (where ? stands for any character)
comment|//! [45]
comment|//! [46]
name|QString
name|t
init|=
literal|"Hello"
decl_stmt|;
name|t
operator|+=
name|QString
argument_list|(
literal|10
argument_list|,
literal|'X'
argument_list|)
expr_stmt|;
comment|// t == "HelloXXXXXXXXXX"
comment|//! [46]
comment|//! [47]
name|QString
name|r
init|=
literal|"Hello"
decl_stmt|;
name|r
operator|=
name|r
operator|.
name|leftJustified
argument_list|(
literal|10
argument_list|,
literal|' '
argument_list|)
expr_stmt|;
comment|// r == "Hello     "
comment|//! [47]
block|}
end_function
begin_function
DECL|function|rightFunction
name|void
name|Widget
operator|::
name|rightFunction
parameter_list|()
block|{
comment|//! [48]
name|QString
name|x
init|=
literal|"Pineapple"
decl_stmt|;
name|QString
name|y
init|=
name|x
operator|.
name|right
argument_list|(
literal|5
argument_list|)
decl_stmt|;
comment|// y == "apple"
comment|//! [48]
block|}
end_function
begin_function
DECL|function|rightJustifiedFunction
name|void
name|Widget
operator|::
name|rightJustifiedFunction
parameter_list|()
block|{
comment|//! [49]
name|QString
name|s
init|=
literal|"apple"
decl_stmt|;
name|QString
name|t
init|=
name|s
operator|.
name|rightJustified
argument_list|(
literal|8
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
comment|// t == "...apple"
comment|//! [49]
comment|//! [50]
name|QString
name|str
init|=
literal|"Pineapple"
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|rightJustified
argument_list|(
literal|5
argument_list|,
literal|'.'
argument_list|,
literal|true
argument_list|)
expr_stmt|;
comment|// str == "Pinea"
comment|//! [50]
block|}
end_function
begin_function
DECL|function|sectionFunction
name|void
name|Widget
operator|::
name|sectionFunction
parameter_list|()
block|{
comment|//! [51] //! [52]
name|QString
name|str
decl_stmt|;
comment|//! [51]
name|QString
name|csv
init|=
literal|"forename,middlename,surname,phone"
decl_stmt|;
name|QString
name|path
init|=
literal|"/usr/local/bin/myapp"
decl_stmt|;
comment|// First field is empty
name|QString
operator|::
name|SectionFlag
name|flag
init|=
name|QString
operator|::
name|SectionSkipEmpty
decl_stmt|;
name|str
operator|=
name|csv
operator|.
name|section
argument_list|(
literal|','
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// str == "surname"
name|str
operator|=
name|path
operator|.
name|section
argument_list|(
literal|'/'
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// str == "bin/myapp"
name|str
operator|=
name|path
operator|.
name|section
argument_list|(
literal|'/'
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
name|flag
argument_list|)
expr_stmt|;
comment|// str == "myapp"
comment|//! [52]
comment|//! [53]
name|str
operator|=
name|csv
operator|.
name|section
argument_list|(
literal|','
argument_list|,
operator|-
literal|3
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// str == "middlename,surname"
name|str
operator|=
name|path
operator|.
name|section
argument_list|(
literal|'/'
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
comment|// str == "myapp"
comment|//! [53]
comment|//! [54]
name|QString
name|data
init|=
literal|"forename**middlename**surname**phone"
decl_stmt|;
name|str
operator|=
name|data
operator|.
name|section
argument_list|(
literal|"**"
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// str == "surname"
name|str
operator|=
name|data
operator|.
name|section
argument_list|(
literal|"**"
argument_list|,
operator|-
literal|3
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// str == "middlename**surname"
comment|//! [54]
comment|//! [55]
name|QString
name|line
init|=
literal|"forename\tmiddlename  surname \t \t phone"
decl_stmt|;
name|QRegExp
name|sep
argument_list|(
literal|"\\s+"
argument_list|)
decl_stmt|;
name|str
operator|=
name|line
operator|.
name|section
argument_list|(
name|sep
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// str == "surname"
name|str
operator|=
name|line
operator|.
name|section
argument_list|(
name|sep
argument_list|,
operator|-
literal|3
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// str == "middlename  surname"
comment|//! [55]
comment|//! [89]
name|QString
name|line
init|=
literal|"forename\tmiddlename  surname \t \t phone"
decl_stmt|;
name|QRegularExpression
name|sep
argument_list|(
literal|"\\s+"
argument_list|)
decl_stmt|;
name|str
operator|=
name|line
operator|.
name|section
argument_list|(
name|sep
argument_list|,
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// str == "surname"
name|str
operator|=
name|line
operator|.
name|section
argument_list|(
name|sep
argument_list|,
operator|-
literal|3
argument_list|,
operator|-
literal|2
argument_list|)
expr_stmt|;
comment|// str == "middlename  surname"
comment|//! [89]
block|}
end_function
begin_function
DECL|function|setNumFunction
name|void
name|Widget
operator|::
name|setNumFunction
parameter_list|()
block|{
comment|//! [56]
name|QString
name|str
decl_stmt|;
name|str
operator|.
name|setNum
argument_list|(
literal|1234
argument_list|)
expr_stmt|;
comment|// str == "1234"
comment|//! [56]
block|}
end_function
begin_function
DECL|function|simplifiedFunction
name|void
name|Widget
operator|::
name|simplifiedFunction
parameter_list|()
block|{
comment|//! [57]
name|QString
name|str
init|=
literal|"  lots\t of\nwhitespace\r\n "
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|simplified
argument_list|()
expr_stmt|;
comment|// str == "lots of whitespace";
comment|//! [57]
block|}
end_function
begin_function
DECL|function|sizeFunction
name|void
name|Widget
operator|::
name|sizeFunction
parameter_list|()
block|{
comment|//! [58]
name|QString
name|str
init|=
literal|"World"
decl_stmt|;
name|int
name|n
init|=
name|str
operator|.
name|size
argument_list|()
decl_stmt|;
comment|// n == 5
name|str
operator|.
name|data
argument_list|()
index|[
literal|0
index|]
expr_stmt|;
comment|// returns 'W'
name|str
operator|.
name|data
argument_list|()
index|[
literal|4
index|]
expr_stmt|;
comment|// returns 'd'
name|str
operator|.
name|data
argument_list|()
index|[
literal|5
index|]
expr_stmt|;
comment|// returns '\0'
comment|//! [58]
block|}
end_function
begin_function
DECL|function|splitFunction
name|void
name|Widget
operator|::
name|splitFunction
parameter_list|()
block|{
comment|//! [59]
name|QString
name|str
decl_stmt|;
name|QStringList
name|list
decl_stmt|;
name|str
operator|=
literal|"Some  text\n\twith  strange whitespace."
expr_stmt|;
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
name|QRegExp
argument_list|(
literal|"\\s+"
argument_list|)
argument_list|)
expr_stmt|;
comment|// list: [ "Some", "text", "with", "strange", "whitespace." ]
comment|//! [59]
comment|//! [60]
name|str
operator|=
literal|"This time, a normal English sentence."
expr_stmt|;
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
name|QRegExp
argument_list|(
literal|"\\W+"
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
comment|// list: [ "This", "time", "a", "normal", "English", "sentence" ]
comment|//! [60]
comment|//! [61]
name|str
operator|=
literal|"Now: this sentence fragment."
expr_stmt|;
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
name|QRegExp
argument_list|(
literal|"\\b"
argument_list|)
argument_list|)
expr_stmt|;
comment|// list: [ "", "Now", ": ", "this", " ", "sentence", " ", "fragment", "." ]
comment|//! [61]
comment|//! [90]
name|QString
name|str
decl_stmt|;
name|QStringList
name|list
decl_stmt|;
name|str
operator|=
literal|"Some  text\n\twith  strange whitespace."
expr_stmt|;
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
name|QRegularExpression
argument_list|(
literal|"\\s+"
argument_list|)
argument_list|)
expr_stmt|;
comment|// list: [ "Some", "text", "with", "strange", "whitespace." ]
comment|//! [90]
comment|//! [91]
name|str
operator|=
literal|"This time, a normal English sentence."
expr_stmt|;
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
name|QRegularExpression
argument_list|(
literal|"\\W+"
argument_list|)
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
expr_stmt|;
comment|// list: [ "This", "time", "a", "normal", "English", "sentence" ]
comment|//! [91]
comment|//! [92]
name|str
operator|=
literal|"Now: this sentence fragment."
expr_stmt|;
name|list
operator|=
name|str
operator|.
name|split
argument_list|(
name|QRegularExpression
argument_list|(
literal|"\\b"
argument_list|)
argument_list|)
expr_stmt|;
comment|// list: [ "", "Now", ": ", "this", " ", "sentence", " ", "fragment", "." ]
comment|//! [92]
block|}
end_function
begin_function
DECL|function|splitCaseSensitiveFunction
name|void
name|Widget
operator|::
name|splitCaseSensitiveFunction
parameter_list|()
block|{
comment|//! [62]
name|QString
name|str
init|=
literal|"a,,b,c"
decl_stmt|;
name|QStringList
name|list1
init|=
name|str
operator|.
name|split
argument_list|(
literal|","
argument_list|)
decl_stmt|;
comment|// list1: [ "a", "", "b", "c" ]
name|QStringList
name|list2
init|=
name|str
operator|.
name|split
argument_list|(
literal|","
argument_list|,
name|QString
operator|::
name|SkipEmptyParts
argument_list|)
decl_stmt|;
comment|// list2: [ "a", "b", "c" ]
comment|//! [62]
block|}
end_function
begin_function
DECL|function|sprintfFunction
name|void
name|Widget
operator|::
name|sprintfFunction
parameter_list|()
block|{
comment|//! [63]
name|size_t
name|BufSize
decl_stmt|;
name|char
name|buf
index|[
name|BufSize
index|]
decl_stmt|;
operator|::
name|snprintf
argument_list|(
name|buf
argument_list|,
name|BufSize
argument_list|,
literal|"%lld"
argument_list|,
literal|123456789LL
argument_list|)
expr_stmt|;
name|QString
name|str
init|=
name|QString
operator|::
name|fromUtf8
argument_list|(
name|buf
argument_list|)
decl_stmt|;
comment|//! [63]
comment|//! [64]
name|QString
name|result
decl_stmt|;
name|QTextStream
argument_list|(
operator|&
name|result
argument_list|)
operator|<<
literal|"pi = "
operator|<<
literal|3.14
expr_stmt|;
comment|// result == "pi = 3.14"
comment|//! [64]
block|}
end_function
begin_function
DECL|function|startsWithFunction
name|void
name|Widget
operator|::
name|startsWithFunction
parameter_list|()
block|{
comment|//! [65]
name|QString
name|str
init|=
literal|"Bananas"
decl_stmt|;
name|str
operator|.
name|startsWith
argument_list|(
literal|"Ban"
argument_list|)
expr_stmt|;
comment|// returns true
name|str
operator|.
name|startsWith
argument_list|(
literal|"Car"
argument_list|)
expr_stmt|;
comment|// returns false
comment|//! [65]
block|}
end_function
begin_function
DECL|function|toDoubleFunction
name|void
name|Widget
operator|::
name|toDoubleFunction
parameter_list|()
block|{
comment|//! [66]
name|QString
name|str
init|=
literal|"1234.56"
decl_stmt|;
name|double
name|val
init|=
name|str
operator|.
name|toDouble
argument_list|()
decl_stmt|;
comment|// val == 1234.56
comment|//! [66]
comment|//! [67]
name|bool
name|ok
decl_stmt|;
name|double
name|d
decl_stmt|;
name|d
operator|=
name|QString
argument_list|(
literal|"1234.56e-02"
argument_list|)
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
comment|// ok == true, d == 12.3456
comment|//! [67]
comment|//! [68]
name|d
operator|=
name|QString
argument_list|(
literal|"1234,56"
argument_list|)
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
comment|// ok == false
name|d
operator|=
name|QString
argument_list|(
literal|"1234.56"
argument_list|)
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
comment|// ok == true, d == 1234.56
comment|//! [68]
comment|//! [69]
name|d
operator|=
name|QString
argument_list|(
literal|"1,234,567.89"
argument_list|)
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
comment|// ok == false
name|d
operator|=
name|QString
argument_list|(
literal|"1234567.89"
argument_list|)
operator|.
name|toDouble
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
comment|// ok == true
comment|//! [69]
block|}
end_function
begin_function
DECL|function|toFloatFunction
name|void
name|Widget
operator|::
name|toFloatFunction
parameter_list|()
block|{
comment|//! [71]
name|QString
name|str1
init|=
literal|"1234.56"
decl_stmt|;
name|str1
operator|.
name|toFloat
argument_list|()
expr_stmt|;
comment|// returns 1234.56
name|bool
name|ok
decl_stmt|;
name|QString
name|str2
init|=
literal|"R2D2"
decl_stmt|;
name|str2
operator|.
name|toFloat
argument_list|(
operator|&
name|ok
argument_list|)
expr_stmt|;
comment|// returns 0.0, sets ok to false
comment|//! [71]
block|}
end_function
begin_function
DECL|function|toIntFunction
name|void
name|Widget
operator|::
name|toIntFunction
parameter_list|()
block|{
comment|//! [72]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|int
name|hex
init|=
name|str
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|int
name|dec
init|=
name|str
operator|.
name|toInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [72]
block|}
end_function
begin_function
DECL|function|toLongFunction
name|void
name|Widget
operator|::
name|toLongFunction
parameter_list|()
block|{
comment|//! [73]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|long
name|hex
init|=
name|str
operator|.
name|toLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|long
name|dec
init|=
name|str
operator|.
name|toLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [73]
block|}
end_function
begin_function
DECL|function|toLongLongFunction
name|void
name|Widget
operator|::
name|toLongLongFunction
parameter_list|()
block|{
comment|//! [74]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|qint64
name|hex
init|=
name|str
operator|.
name|toLongLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|qint64
name|dec
init|=
name|str
operator|.
name|toLongLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [74]
block|}
end_function
begin_function
DECL|function|toLowerFunction
name|void
name|Widget
operator|::
name|toLowerFunction
parameter_list|()
block|{
comment|//! [75]
name|QString
name|str
init|=
literal|"Qt by NOKIA"
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|toLower
argument_list|()
expr_stmt|;
comment|// str == "qt by nokia"
comment|//! [75]
block|}
end_function
begin_function
DECL|function|toShortFunction
name|void
name|Widget
operator|::
name|toShortFunction
parameter_list|()
block|{
comment|//! [76]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|short
name|hex
init|=
name|str
operator|.
name|toShort
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|short
name|dec
init|=
name|str
operator|.
name|toShort
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [76]
block|}
end_function
begin_function
DECL|function|toUIntFunction
name|void
name|Widget
operator|::
name|toUIntFunction
parameter_list|()
block|{
comment|//! [77]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|uint
name|hex
init|=
name|str
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|uint
name|dec
init|=
name|str
operator|.
name|toUInt
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [77]
block|}
end_function
begin_function
DECL|function|toULongFunction
name|void
name|Widget
operator|::
name|toULongFunction
parameter_list|()
block|{
comment|//! [78]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|ulong
name|hex
init|=
name|str
operator|.
name|toULong
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|ulong
name|dec
init|=
name|str
operator|.
name|toULong
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [78]
block|}
end_function
begin_function
DECL|function|toULongLongFunction
name|void
name|Widget
operator|::
name|toULongLongFunction
parameter_list|()
block|{
comment|//! [79]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|quint64
name|hex
init|=
name|str
operator|.
name|toULongLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|quint64
name|dec
init|=
name|str
operator|.
name|toULongLong
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [79]
block|}
end_function
begin_function
DECL|function|toUShortFunction
name|void
name|Widget
operator|::
name|toUShortFunction
parameter_list|()
block|{
comment|//! [80]
name|QString
name|str
init|=
literal|"FF"
decl_stmt|;
name|bool
name|ok
decl_stmt|;
name|ushort
name|hex
init|=
name|str
operator|.
name|toUShort
argument_list|(
operator|&
name|ok
argument_list|,
literal|16
argument_list|)
decl_stmt|;
comment|// hex == 255, ok == true
name|ushort
name|dec
init|=
name|str
operator|.
name|toUShort
argument_list|(
operator|&
name|ok
argument_list|,
literal|10
argument_list|)
decl_stmt|;
comment|// dec == 0, ok == false
comment|//! [80]
block|}
end_function
begin_function
DECL|function|toUpperFunction
name|void
name|Widget
operator|::
name|toUpperFunction
parameter_list|()
block|{
comment|//! [81]
name|QString
name|str
init|=
literal|"TeXt"
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|toUpper
argument_list|()
expr_stmt|;
comment|// str == "TEXT"
comment|//! [81]
block|}
end_function
begin_function
DECL|function|trimmedFunction
name|void
name|Widget
operator|::
name|trimmedFunction
parameter_list|()
block|{
comment|//! [82]
name|QString
name|str
init|=
literal|"  lots\t of\nwhitespace\r\n "
decl_stmt|;
name|str
operator|=
name|str
operator|.
name|trimmed
argument_list|()
expr_stmt|;
comment|// str == "lots\t of\nwhitespace"
comment|//! [82]
block|}
end_function
begin_function
DECL|function|truncateFunction
name|void
name|Widget
operator|::
name|truncateFunction
parameter_list|()
block|{
comment|//! [83]
name|QString
name|str
init|=
literal|"Vladivostok"
decl_stmt|;
name|str
operator|.
name|truncate
argument_list|(
literal|4
argument_list|)
expr_stmt|;
comment|// str == "Vlad"
comment|//! [83]
block|}
end_function
begin_function
DECL|function|plusEqualOperator
name|void
name|Widget
operator|::
name|plusEqualOperator
parameter_list|()
block|{
comment|//! [84]
name|QString
name|x
init|=
literal|"free"
decl_stmt|;
name|QString
name|y
init|=
literal|"dom"
decl_stmt|;
name|x
operator|+=
name|y
expr_stmt|;
comment|// x == "freedom"
comment|//! [84]
block|}
end_function
begin_function
DECL|function|arrayOperator
name|void
name|Widget
operator|::
name|arrayOperator
parameter_list|()
block|{
comment|//! [85]
name|QString
name|str
decl_stmt|;
if|if
condition|(
name|str
index|[
literal|0
index|]
operator|==
name|QChar
argument_list|(
literal|'?'
argument_list|)
condition|)
name|str
index|[
literal|0
index|]
operator|=
name|QChar
argument_list|(
literal|'_'
argument_list|)
expr_stmt|;
comment|//! [85]
block|}
end_function
begin_function
DECL|function|midRefFunction
name|void
name|Widget
operator|::
name|midRefFunction
parameter_list|()
block|{
comment|//! [midRef]
name|QString
name|x
init|=
literal|"Nine pineapples"
decl_stmt|;
name|QStringRef
name|y
init|=
name|x
operator|.
name|midRef
argument_list|(
literal|5
argument_list|,
literal|4
argument_list|)
decl_stmt|;
comment|// y == "pine"
name|QStringRef
name|z
init|=
name|x
operator|.
name|midRef
argument_list|(
literal|5
argument_list|)
decl_stmt|;
comment|// z == "pineapples"
comment|//! [midRef]
block|}
end_function
begin_function
DECL|function|leftRefFunction
name|void
name|Widget
operator|::
name|leftRefFunction
parameter_list|()
block|{
comment|//! [leftRef]
name|QString
name|x
init|=
literal|"Pineapple"
decl_stmt|;
name|QStringRef
name|y
init|=
name|x
operator|.
name|leftRef
argument_list|(
literal|4
argument_list|)
decl_stmt|;
comment|// y == "Pine"
comment|//! [leftRef]
block|}
end_function
begin_function
DECL|function|rightRefFunction
name|void
name|Widget
operator|::
name|rightRefFunction
parameter_list|()
block|{
comment|//! [rightRef]
name|QString
name|x
init|=
literal|"Pineapple"
decl_stmt|;
name|QStringRef
name|y
init|=
name|x
operator|.
name|rightRef
argument_list|(
literal|5
argument_list|)
decl_stmt|;
comment|// y == "apple"
comment|//! [rightRef]
block|}
end_function
begin_function
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
name|QApplication
name|app
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
decl_stmt|;
name|Widget
name|widget
decl_stmt|;
name|widget
operator|.
name|show
argument_list|()
expr_stmt|;
return|return
name|app
operator|.
name|exec
argument_list|()
return|;
block|}
end_function
end_unit
