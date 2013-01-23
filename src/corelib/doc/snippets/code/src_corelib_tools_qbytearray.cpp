begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names **     of its contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_function
DECL|function|wrapInFunction
name|void
name|wrapInFunction
parameter_list|()
block|{
comment|//! [0]
name|QByteArray
name|ba
argument_list|(
literal|"Hello"
argument_list|)
decl_stmt|;
comment|//! [0]
comment|//! [1]
name|QByteArray
name|ba
decl_stmt|;
name|ba
operator|.
name|resize
argument_list|(
literal|5
argument_list|)
expr_stmt|;
name|ba
index|[
literal|0
index|]
operator|=
literal|0x3c
expr_stmt|;
name|ba
index|[
literal|1
index|]
operator|=
literal|0xb8
expr_stmt|;
name|ba
index|[
literal|2
index|]
operator|=
literal|0x64
expr_stmt|;
name|ba
index|[
literal|3
index|]
operator|=
literal|0x18
expr_stmt|;
name|ba
index|[
literal|4
index|]
operator|=
literal|0xca
expr_stmt|;
comment|//! [1]
comment|//! [2]
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ba
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
name|ba
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|>=
literal|'a'
operator|&&
name|ba
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<=
literal|'f'
condition|)
name|cout
operator|<<
literal|"Found character in range [a-f]"
operator|<<
name|endl
expr_stmt|;
block|}
comment|//! [2]
comment|//! [3]
name|QByteArray
name|x
argument_list|(
literal|"and"
argument_list|)
decl_stmt|;
name|x
operator|.
name|prepend
argument_list|(
literal|"rock "
argument_list|)
expr_stmt|;
comment|// x == "rock and"
name|x
operator|.
name|append
argument_list|(
literal|" roll"
argument_list|)
expr_stmt|;
comment|// x == "rock and roll"
name|x
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
comment|// x == "rock& roll"
comment|//! [3]
comment|//! [4]
name|QByteArray
name|ba
argument_list|(
literal|"We must be<b>bold</b>, very<b>bold</b>"
argument_list|)
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
name|ba
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
name|cout
operator|<<
literal|"Found<b> tag at index position "
operator|<<
name|j
operator|<<
name|endl
expr_stmt|;
operator|++
name|j
expr_stmt|;
block|}
comment|//! [4]
comment|//! [5]
name|QByteArray
argument_list|()
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns true
name|QByteArray
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QByteArray
argument_list|(
literal|""
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
name|QByteArray
argument_list|(
literal|""
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns false
comment|//! [5]
comment|//! [6]
name|QByteArray
name|ba
argument_list|(
literal|"Hello"
argument_list|)
decl_stmt|;
name|int
name|n
init|=
name|ba
operator|.
name|size
argument_list|()
decl_stmt|;
comment|// n == 5
name|ba
operator|.
name|data
argument_list|()
index|[
literal|0
index|]
expr_stmt|;
comment|// returns 'H'
name|ba
operator|.
name|data
argument_list|()
index|[
literal|4
index|]
expr_stmt|;
comment|// returns 'o'
name|ba
operator|.
name|data
argument_list|()
index|[
literal|5
index|]
expr_stmt|;
comment|// returns '\0'
comment|//! [6]
comment|//! [7]
name|QByteArray
argument_list|()
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QByteArray
argument_list|(
literal|""
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns true
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isEmpty
argument_list|()
expr_stmt|;
comment|// returns false
comment|//! [7]
comment|//! [8]
name|QByteArray
name|ba
argument_list|(
literal|"Hello world"
argument_list|)
decl_stmt|;
name|char
modifier|*
name|data
init|=
name|ba
operator|.
name|data
argument_list|()
decl_stmt|;
while|while
condition|(
operator|*
name|data
condition|)
block|{
name|cout
operator|<<
literal|"["
operator|<<
operator|*
name|data
operator|<<
literal|"]"
operator|<<
name|endl
expr_stmt|;
operator|++
name|data
expr_stmt|;
block|}
comment|//! [8]
comment|//! [9]
name|QByteArray
name|ba
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
name|ba
index|[
name|i
index|]
operator|=
literal|'A'
operator|+
name|i
expr_stmt|;
comment|// ba == "ABCDEFGHIJ"
comment|//! [9]
comment|//! [10]
name|QByteArray
name|ba
argument_list|(
literal|"Stockholm"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|truncate
argument_list|(
literal|5
argument_list|)
expr_stmt|;
comment|// ba == "Stock"
comment|//! [10]
comment|//! [11]
name|QByteArray
name|ba
argument_list|(
literal|"STARTTLS\r\n"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|chop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
comment|// ba == "STARTTLS"
comment|//! [11]
comment|//! [12]
name|QByteArray
name|x
argument_list|(
literal|"free"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
argument_list|(
literal|"dom"
argument_list|)
decl_stmt|;
name|x
operator|+=
name|y
expr_stmt|;
comment|// x == "freedom"
comment|//! [12]
comment|//! [13]
name|QByteArray
argument_list|()
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns true
name|QByteArray
argument_list|(
literal|""
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
name|QByteArray
argument_list|(
literal|"abc"
argument_list|)
operator|.
name|isNull
argument_list|()
expr_stmt|;
comment|// returns false
comment|//! [13]
comment|//! [14]
name|QByteArray
name|ba
argument_list|(
literal|"Istambul"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|fill
argument_list|(
literal|'o'
argument_list|)
expr_stmt|;
comment|// ba == "oooooooo"
name|ba
operator|.
name|fill
argument_list|(
literal|'X'
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// ba == "XX"
comment|//! [14]
comment|//! [15]
name|QByteArray
name|x
argument_list|(
literal|"ship"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
argument_list|(
literal|"air"
argument_list|)
decl_stmt|;
name|x
operator|.
name|prepend
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// x == "airship"
comment|//! [15]
comment|//! [16]
name|QByteArray
name|x
argument_list|(
literal|"free"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
argument_list|(
literal|"dom"
argument_list|)
decl_stmt|;
name|x
operator|.
name|append
argument_list|(
name|y
argument_list|)
expr_stmt|;
comment|// x == "freedom"
comment|//! [16]
comment|//! [17]
name|QByteArray
name|ba
argument_list|(
literal|"Meal"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|insert
argument_list|(
literal|1
argument_list|,
name|QByteArray
argument_list|(
literal|"ontr"
argument_list|)
argument_list|)
expr_stmt|;
comment|// ba == "Montreal"
comment|//! [17]
comment|//! [18]
name|QByteArray
name|ba
argument_list|(
literal|"Montreal"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|remove
argument_list|(
literal|1
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// ba == "Meal"
comment|//! [18]
comment|//! [19]
name|QByteArray
name|x
argument_list|(
literal|"Say yes!"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
argument_list|(
literal|"no"
argument_list|)
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
comment|//! [19]
comment|//! [20]
name|QByteArray
name|ba
argument_list|(
literal|"colour behaviour flavour neighbour"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|replace
argument_list|(
name|QByteArray
argument_list|(
literal|"ou"
argument_list|)
argument_list|,
name|QByteArray
argument_list|(
literal|"o"
argument_list|)
argument_list|)
expr_stmt|;
comment|// ba == "color behavior flavor neighbor"
comment|//! [20]
comment|//! [21]
name|QByteArray
name|x
argument_list|(
literal|"sticky question"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
argument_list|(
literal|"sti"
argument_list|)
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
comment|//! [21]
comment|//! [22]
name|QByteArray
name|ba
argument_list|(
literal|"ABCBA"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|indexOf
argument_list|(
literal|"B"
argument_list|)
expr_stmt|;
comment|// returns 1
name|ba
operator|.
name|indexOf
argument_list|(
literal|"B"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// returns 1
name|ba
operator|.
name|indexOf
argument_list|(
literal|"B"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// returns 3
name|ba
operator|.
name|indexOf
argument_list|(
literal|"X"
argument_list|)
expr_stmt|;
comment|// returns -1
comment|//! [22]
comment|//! [23]
name|QByteArray
name|x
argument_list|(
literal|"crazy azimuths"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
argument_list|(
literal|"az"
argument_list|)
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
comment|//! [23]
comment|//! [24]
name|QByteArray
name|ba
argument_list|(
literal|"ABCBA"
argument_list|)
decl_stmt|;
name|ba
operator|.
name|lastIndexOf
argument_list|(
literal|"B"
argument_list|)
expr_stmt|;
comment|// returns 3
name|ba
operator|.
name|lastIndexOf
argument_list|(
literal|"B"
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// returns 3
name|ba
operator|.
name|lastIndexOf
argument_list|(
literal|"B"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// returns 1
name|ba
operator|.
name|lastIndexOf
argument_list|(
literal|"X"
argument_list|)
expr_stmt|;
comment|// returns -1
comment|//! [24]
comment|//! [25]
name|QByteArray
name|url
argument_list|(
literal|"ftp://ftp.qt-project.org/"
argument_list|)
decl_stmt|;
if|if
condition|(
name|url
operator|.
name|startsWith
argument_list|(
literal|"ftp:"
argument_list|)
condition|)
operator|...
comment|//! [25]
comment|//! [26]
name|QByteArray
name|url
argument_list|(
literal|"http://qt.nokia.com/index.html"
argument_list|)
expr_stmt|;
if|if
condition|(
name|url
operator|.
name|endsWith
argument_list|(
literal|".html"
argument_list|)
condition|)
operator|...
comment|//! [26]
comment|//! [27]
name|QByteArray
name|x
argument_list|(
literal|"Pineapple"
argument_list|)
expr_stmt|;
name|QByteArray
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
comment|//! [27]
comment|//! [28]
name|QByteArray
name|x
argument_list|(
literal|"Pineapple"
argument_list|)
decl_stmt|;
name|QByteArray
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
comment|//! [28]
comment|//! [29]
name|QByteArray
name|x
argument_list|(
literal|"Five pineapples"
argument_list|)
decl_stmt|;
name|QByteArray
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
name|QByteArray
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
comment|//! [29]
comment|//! [30]
name|QByteArray
name|x
argument_list|(
literal|"Qt by NOKIA"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
init|=
name|x
operator|.
name|toLower
argument_list|()
decl_stmt|;
comment|// y == "qt by nokia"
comment|//! [30]
comment|//! [31]
name|QByteArray
name|x
argument_list|(
literal|"Qt by NOKIA"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
init|=
name|x
operator|.
name|toUpper
argument_list|()
decl_stmt|;
comment|// y == "QT BY NOKIA"
comment|//! [31]
comment|//! [32]
name|QByteArray
name|ba
argument_list|(
literal|"  lots\t of\nwhitespace\r\n "
argument_list|)
decl_stmt|;
name|ba
operator|=
name|ba
operator|.
name|simplified
argument_list|()
expr_stmt|;
comment|// ba == "lots of whitespace";
comment|//! [32]
comment|//! [33]
name|QByteArray
name|ba
argument_list|(
literal|"  lots\t of\nwhitespace\r\n "
argument_list|)
decl_stmt|;
name|ba
operator|=
name|ba
operator|.
name|trimmed
argument_list|()
expr_stmt|;
comment|// ba == "lots\t of\nwhitespace";
comment|//! [33]
comment|//! [34]
name|QByteArray
name|x
argument_list|(
literal|"apple"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
init|=
name|x
operator|.
name|leftJustified
argument_list|(
literal|8
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
comment|// y == "apple..."
comment|//! [34]
comment|//! [35]
name|QByteArray
name|x
argument_list|(
literal|"apple"
argument_list|)
decl_stmt|;
name|QByteArray
name|y
init|=
name|x
operator|.
name|rightJustified
argument_list|(
literal|8
argument_list|,
literal|'.'
argument_list|)
decl_stmt|;
comment|// y == "...apple"
comment|//! [35]
comment|//! [36]
name|QByteArray
name|str
argument_list|(
literal|"FF"
argument_list|)
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
comment|//! [36]
comment|//! [37]
name|QByteArray
name|str
argument_list|(
literal|"FF"
argument_list|)
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
comment|//! [37]
comment|//! [38]
name|QByteArray
name|string
argument_list|(
literal|"1234.56"
argument_list|)
decl_stmt|;
name|double
name|a
init|=
name|string
operator|.
name|toDouble
argument_list|()
decl_stmt|;
comment|// a == 1234.56
comment|//! [38]
comment|//! [39]
name|QByteArray
name|text
argument_list|(
literal|"Qt is great!"
argument_list|)
decl_stmt|;
name|text
operator|.
name|toBase64
argument_list|()
expr_stmt|;
comment|// returns "UXQgaXMgZ3JlYXQh"
comment|//! [39]
comment|//! [40]
name|QByteArray
name|ba
decl_stmt|;
name|int
name|n
init|=
literal|63
decl_stmt|;
name|ba
operator|.
name|setNum
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|// ba == "63"
name|ba
operator|.
name|setNum
argument_list|(
name|n
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// ba == "3f"
comment|//! [40]
comment|//! [41]
name|int
name|n
init|=
literal|63
decl_stmt|;
name|QByteArray
operator|::
name|number
argument_list|(
name|n
argument_list|)
expr_stmt|;
comment|// returns "63"
name|QByteArray
operator|::
name|number
argument_list|(
name|n
argument_list|,
literal|16
argument_list|)
expr_stmt|;
comment|// returns "3f"
name|QByteArray
operator|::
name|number
argument_list|(
name|n
argument_list|,
literal|16
argument_list|)
operator|.
name|toUpper
argument_list|()
expr_stmt|;
comment|// returns "3F"
comment|//! [41]
comment|//! [42]
name|QByteArray
name|ba
init|=
name|QByteArray
operator|::
name|number
argument_list|(
literal|12.3456
argument_list|,
literal|'E'
argument_list|,
literal|3
argument_list|)
decl_stmt|;
comment|// ba == 1.235E+01
comment|//! [42]
comment|//! [43]
specifier|static
specifier|const
name|char
name|mydata
index|[]
init|=
block|{
literal|0x00
block|,
literal|0x00
block|,
literal|0x03
block|,
literal|0x84
block|,
literal|0x78
block|,
literal|0x9c
block|,
literal|0x3b
block|,
literal|0x76
block|,
literal|0xec
block|,
literal|0x18
block|,
literal|0xc3
block|,
literal|0x31
block|,
literal|0x0a
block|,
literal|0xf1
block|,
literal|0xcc
block|,
literal|0x99
block|,
operator|...
literal|0x6d
block|,
literal|0x5b
block|}
decl_stmt|;
name|QByteArray
name|data
init|=
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|mydata
argument_list|,
sizeof|sizeof
argument_list|(
name|mydata
argument_list|)
argument_list|)
decl_stmt|;
name|QDataStream
name|in
argument_list|(
operator|&
name|data
argument_list|,
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
decl_stmt|;
operator|...
comment|//! [43]
comment|//! [44]
name|QByteArray
name|text
operator|=
name|QByteArray
operator|::
name|fromBase64
argument_list|(
literal|"UXQgaXMgZ3JlYXQh"
argument_list|)
expr_stmt|;
name|text
operator|.
name|data
argument_list|()
expr_stmt|;
comment|// returns "Qt is great!"
comment|//! [44]
comment|//! [45]
name|QByteArray
name|text
init|=
name|QByteArray
operator|::
name|fromHex
argument_list|(
literal|"517420697320677265617421"
argument_list|)
decl_stmt|;
name|text
operator|.
name|data
argument_list|()
expr_stmt|;
comment|// returns "Qt is great!"
comment|//! [45]
comment|//! [46]
name|QString
name|tmp
init|=
literal|"test"
decl_stmt|;
name|QByteArray
name|text
init|=
name|tmp
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|char
modifier|*
name|data
init|=
operator|new
name|char
index|[
name|text
operator|.
name|size
argument_list|()
index|]
name|strcpy
argument_list|(
name|data
argument_list|,
name|text
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
operator|delete
index|[]
name|data
expr_stmt|;
comment|//! [46]
comment|//! [47]
name|QString
name|tmp
init|=
literal|"test"
decl_stmt|;
name|QByteArray
name|text
init|=
name|tmp
operator|.
name|toLocal8Bit
argument_list|()
decl_stmt|;
name|char
modifier|*
name|data
init|=
operator|new
name|char
index|[
name|text
operator|.
name|size
argument_list|()
operator|+
literal|1
index|]
name|strcpy
argument_list|(
name|data
argument_list|,
name|text
operator|.
name|data
argument_list|()
argument_list|)
decl_stmt|;
operator|delete
index|[]
name|data
expr_stmt|;
comment|//! [47]
comment|//! [48]
name|QByteArray
name|ba1
argument_list|(
literal|"ca\0r\0t"
argument_list|)
decl_stmt|;
name|ba1
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Returns 2.
name|ba1
operator|.
name|constData
argument_list|()
expr_stmt|;
comment|// Returns "ca" with terminating \0.
name|QByteArray
name|ba2
argument_list|(
literal|"ca\0r\0t"
argument_list|,
literal|3
argument_list|)
decl_stmt|;
name|ba2
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Returns 3.
name|ba2
operator|.
name|constData
argument_list|()
expr_stmt|;
comment|// Returns "ca\0" with terminating \0.
name|QByteArray
name|ba3
argument_list|(
literal|"ca\0r\0t"
argument_list|,
literal|4
argument_list|)
decl_stmt|;
name|ba3
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Returns 4.
name|ba2
operator|.
name|constData
argument_list|()
expr_stmt|;
comment|// Returns "ca\0r" with terminating \0.
specifier|const
name|char
name|cart
index|[]
init|=
block|{
literal|'c'
block|,
literal|'a'
block|,
literal|'\0'
block|,
literal|'r'
block|,
literal|'\0'
block|,
literal|'t'
block|}
decl_stmt|;
name|QByteArray
name|ba4
argument_list|(
name|QByteArray
operator|::
name|fromRawData
argument_list|(
name|cart
argument_list|,
literal|6
argument_list|)
argument_list|)
decl_stmt|;
name|ba4
operator|.
name|size
argument_list|()
expr_stmt|;
comment|// Returns 6.
name|ba4
operator|.
name|constData
argument_list|()
expr_stmt|;
comment|// Returns "ca\0r\0t" without terminating \0.
comment|//! [48]
block|}
end_function
end_unit
