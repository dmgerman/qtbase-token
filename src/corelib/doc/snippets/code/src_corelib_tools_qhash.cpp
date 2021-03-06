begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|hash
index|[
literal|"one"
index|]
operator|=
literal|1
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|hash
index|[
literal|"three"
index|]
operator|=
literal|3
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|hash
index|[
literal|"seven"
index|]
operator|=
literal|7
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"twelve"
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|num1
name|int
name|num1
init|=
name|hash
index|[
literal|"thirteen"
index|]
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|num2
name|int
name|num2
init|=
name|hash
operator|.
name|value
argument_list|(
literal|"thirteen"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|timeout
name|int
name|timeout
init|=
literal|30
decl_stmt|;
end_decl_stmt
begin_if
if|if
condition|(
name|hash
operator|.
name|contains
argument_list|(
literal|"TIMEOUT"
argument_list|)
condition|)
name|timeout
operator|=
name|hash
operator|.
name|value
argument_list|(
literal|"TIMEOUT"
argument_list|)
expr_stmt|;
end_if
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|timeout
name|int
name|timeout
init|=
name|hash
operator|.
name|value
argument_list|(
literal|"TIMEOUT"
argument_list|,
literal|30
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|// WRONG
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|int
argument_list|,
name|QWidget
modifier|*
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|1000
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|hash
index|[
name|i
index|]
operator|==
name|okButton
condition|)
name|cout
operator|<<
literal|"Found button at index "
operator|<<
name|i
operator|<<
name|endl
expr_stmt|;
block|}
end_for
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_function_decl
name|QHashIterator
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|i
parameter_list|(
name|hash
parameter_list|)
function_decl|;
end_function_decl
begin_while
while|while
condition|(
name|i
operator|.
name|hasNext
argument_list|()
condition|)
block|{
name|i
operator|.
name|next
argument_list|()
expr_stmt|;
name|cout
operator|<<
name|i
operator|.
name|key
argument_list|()
operator|<<
literal|": "
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|i
init|=
name|hash
operator|.
name|constBegin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|constEnd
argument_list|()
condition|)
block|{
name|cout
operator|<<
name|i
operator|.
name|key
argument_list|()
operator|<<
literal|": "
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"plenty"
argument_list|,
literal|100
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"plenty"
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// hash.value("plenty") == 2000
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|values
name|QList
argument_list|<
name|int
argument_list|>
name|values
init|=
name|hash
operator|.
name|values
argument_list|(
literal|"plenty"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|values
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|cout
operator|<<
name|values
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<<
name|endl
expr_stmt|;
end_for
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|hash
operator|.
name|find
argument_list|(
literal|"plenty"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
operator|&&
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"plenty"
condition|)
block|{
name|cout
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
end_expr_stmt
begin_foreach
foreach|foreach
control|(
name|int
name|value
decl|,
name|hash
control|)
DECL|variable|endl
name|cout
operator|<<
name|value
operator|<<
name|endl
expr_stmt|;
end_foreach
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|EMPLOYEE_H
end_ifndef
begin_define
DECL|macro|EMPLOYEE_H
define|#
directive|define
name|EMPLOYEE_H
end_define
begin_class
DECL|class|Employee
class|class
name|Employee
block|{
public|public:
DECL|function|Employee
name|Employee
parameter_list|()
block|{}
name|Employee
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QDate
modifier|&
name|dateOfBirth
parameter_list|)
constructor_decl|;
operator|...
specifier|private
operator|:
DECL|member|myName
name|QString
name|myName
expr_stmt|;
DECL|member|myDateOfBirth
name|QDate
name|myDateOfBirth
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|operator ==
specifier|inline
name|bool
name|operator
name|==
parameter_list|(
specifier|const
name|Employee
modifier|&
name|e1
parameter_list|,
specifier|const
name|Employee
modifier|&
name|e2
parameter_list|)
block|{
return|return
name|e1
operator|.
name|name
argument_list|()
operator|==
name|e2
operator|.
name|name
argument_list|()
operator|&&
name|e1
operator|.
name|dateOfBirth
argument_list|()
operator|==
name|e2
operator|.
name|dateOfBirth
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|Employee
modifier|&
name|key
parameter_list|,
name|uint
name|seed
parameter_list|)
block|{
return|return
name|qHash
argument_list|(
name|key
operator|.
name|name
argument_list|()
argument_list|,
name|seed
argument_list|)
operator|^
name|key
operator|.
name|dateOfBirth
argument_list|()
operator|.
name|day
argument_list|()
return|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// EMPLOYEE_H
end_comment
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|hash
operator|.
name|reserve
argument_list|(
literal|20000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
literal|20000
condition|;
operator|++
name|i
control|)
name|hash
operator|.
name|insert
argument_list|(
name|keys
index|[
name|i
index|]
argument_list|,
name|values
index|[
name|i
index|]
argument_list|)
expr_stmt|;
end_for
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_decl_stmt
DECL|variable|objectHash
name|QHash
argument_list|<
name|QObject
modifier|*
argument_list|,
name|int
argument_list|>
name|objectHash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QHash
argument_list|<
name|QObject
operator|*
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
operator|=
name|objectHash
operator|.
name|find
argument_list|(
name|obj
argument_list|)
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|objectHash
operator|.
name|end
argument_list|()
operator|&&
name|i
operator|.
name|key
argument_list|()
operator|==
name|obj
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|value
argument_list|()
operator|==
literal|0
condition|)
block|{
name|i
operator|=
name|objectHash
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|++
name|i
expr_stmt|;
block|}
block|}
end_while
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|i
operator|=
name|hash
operator|.
name|find
argument_list|(
literal|"HDR"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
operator|&&
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"HDR"
condition|)
block|{
name|cout
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"January"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"February"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
name|hash
operator|.
name|insert
argument_list|(
literal|"December"
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|i
operator|=
name|hash
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
name|cout
operator|<<
name|i
operator|.
name|key
argument_list|()
operator|<<
literal|": "
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
end_for
begin_comment
comment|//! [17]
end_comment
begin_comment
comment|//! [18]
end_comment
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|i
operator|=
name|hash
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
name|i
operator|.
name|value
argument_list|()
operator|+=
literal|2
expr_stmt|;
end_for
begin_comment
comment|//! [18]
end_comment
begin_comment
comment|//! [19]
end_comment
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|hash
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|key
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|'_'
argument_list|)
condition|)
name|i
operator|=
name|hash
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
else|else
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [19]
end_comment
begin_comment
comment|//! [20]
end_comment
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|hash
operator|.
name|begin
argument_list|()
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
condition|)
block|{
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|prev
init|=
name|i
decl_stmt|;
operator|++
name|i
expr_stmt|;
if|if
condition|(
name|prev
operator|.
name|key
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|'_'
argument_list|)
condition|)
name|hash
operator|.
name|erase
argument_list|(
name|prev
argument_list|)
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [20]
end_comment
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|// WRONG
end_comment
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
name|i
operator|.
name|key
argument_list|()
operator|.
name|startsWith
argument_list|(
literal|'_'
argument_list|)
condition|)
name|hash
operator|.
name|erase
argument_list|(
name|i
argument_list|)
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [21]
end_comment
begin_comment
comment|//! [22]
end_comment
begin_if
if|if
condition|(
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"Hello"
condition|)
name|i
operator|.
name|value
argument_list|()
operator|=
literal|"Bonjour"
expr_stmt|;
end_if
begin_comment
comment|//! [22]
end_comment
begin_comment
comment|//! [23]
end_comment
begin_decl_stmt
DECL|variable|hash
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"January"
argument_list|,
literal|1
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|hash
operator|.
name|insert
argument_list|(
literal|"February"
argument_list|,
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
name|hash
operator|.
name|insert
argument_list|(
literal|"December"
argument_list|,
literal|12
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|const_iterator
name|i
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|i
operator|=
name|hash
operator|.
name|constBegin
argument_list|()
init|;
name|i
operator|!=
name|hash
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|i
control|)
name|cout
operator|<<
name|i
operator|.
name|key
argument_list|()
operator|<<
literal|": "
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
end_for
begin_comment
comment|//! [23]
end_comment
begin_comment
comment|//! [24]
end_comment
begin_decl_stmt
DECL|variable|hash1
DECL|variable|hash2
DECL|variable|hash3
name|QMultiHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
name|hash1
decl_stmt|,
name|hash2
decl_stmt|,
name|hash3
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|hash1
operator|.
name|insert
argument_list|(
literal|"plenty"
argument_list|,
literal|100
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|hash1
operator|.
name|insert
argument_list|(
literal|"plenty"
argument_list|,
literal|2000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// hash1.size() == 2
end_comment
begin_expr_stmt
name|hash2
operator|.
name|insert
argument_list|(
literal|"plenty"
argument_list|,
literal|5000
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// hash2.size() == 1
end_comment
begin_expr_stmt
name|hash3
operator|=
name|hash1
operator|+
name|hash2
expr_stmt|;
end_expr_stmt
begin_comment
comment|// hash3.size() == 3
end_comment
begin_comment
comment|//! [24]
end_comment
begin_comment
comment|//! [25]
end_comment
begin_decl_stmt
DECL|variable|values
name|QList
argument_list|<
name|int
argument_list|>
name|values
init|=
name|hash
operator|.
name|values
argument_list|(
literal|"plenty"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_for
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|values
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|cout
operator|<<
name|values
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|<<
name|endl
expr_stmt|;
end_for
begin_comment
comment|//! [25]
end_comment
begin_comment
comment|//! [26]
end_comment
begin_decl_stmt
DECL|variable|i
name|QMultiHash
argument_list|<
name|QString
argument_list|,
name|int
argument_list|>
operator|::
name|iterator
name|i
init|=
name|hash
operator|.
name|find
argument_list|(
literal|"plenty"
argument_list|)
decl_stmt|;
end_decl_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|hash
operator|.
name|end
argument_list|()
operator|&&
name|i
operator|.
name|key
argument_list|()
operator|==
literal|"plenty"
condition|)
block|{
name|cout
operator|<<
name|i
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
operator|++
name|i
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [26]
end_comment
begin_comment
comment|//! [27]
end_comment
begin_for
for|for
control|(
name|QHash
argument_list|<
name|int
argument_list|,
name|QString
argument_list|>
operator|::
name|const_iterator
name|it
init|=
name|hash
operator|.
name|cbegin
argument_list|()
init|,
name|end
init|=
name|hash
operator|.
name|cend
argument_list|()
init|;
name|it
operator|!=
name|end
condition|;
operator|++
name|it
control|)
block|{
name|cout
operator|<<
literal|"The key: "
operator|<<
name|it
operator|.
name|key
argument_list|()
operator|<<
name|endl
name|cout
operator|<<
literal|"The value: "
operator|<<
name|it
operator|.
name|value
argument_list|()
operator|<<
name|endl
expr_stmt|;
name|cout
operator|<<
literal|"Also the value: "
operator|<<
operator|(
operator|*
name|it
operator|)
operator|<<
name|endl
expr_stmt|;
block|}
end_for
begin_comment
comment|//! [27]
end_comment
begin_comment
comment|//! [28]
end_comment
begin_comment
comment|// Inefficient, keys() is expensive
end_comment
begin_decl_stmt
DECL|variable|keys
name|QList
argument_list|<
name|int
argument_list|>
name|keys
init|=
name|hash
operator|.
name|keys
argument_list|()
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|numPrimes
name|int
name|numPrimes
init|=
name|std
operator|::
name|count_if
argument_list|(
name|keys
operator|.
name|cbegin
argument_list|()
argument_list|,
name|keys
operator|.
name|cend
argument_list|()
argument_list|,
name|isPrimeNumber
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDeleteAll
argument_list|(
name|hash2
operator|.
name|keys
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// Efficient, no memory allocation needed
end_comment
begin_decl_stmt
DECL|variable|numPrimes
name|int
name|numPrimes
init|=
name|std
operator|::
name|count_if
argument_list|(
name|hash
operator|.
name|keyBegin
argument_list|()
argument_list|,
name|hash
operator|.
name|keyEnd
argument_list|()
argument_list|,
name|isPrimeNumber
argument_list|)
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|qDeleteAll
argument_list|(
name|hash2
operator|.
name|keyBegin
argument_list|()
argument_list|,
name|hash2
operator|.
name|keyEnd
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [28]
end_comment
begin_comment
comment|//! [qhashbits]
end_comment
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|int
argument_list|>
modifier|&
name|key
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
block|{
if|if
condition|(
name|key
operator|.
name|empty
argument_list|()
condition|)
return|return
name|seed
return|;
else|else
return|return
name|qHashBits
argument_list|(
operator|&
name|key
operator|.
name|front
argument_list|()
argument_list|,
name|key
operator|.
name|size
argument_list|()
operator|*
sizeof|sizeof
argument_list|(
name|int
argument_list|)
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [qhashbits]
end_comment
begin_comment
comment|//! [qhashrange]
end_comment
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|std
operator|::
name|vector
argument_list|<
name|int
argument_list|>
modifier|&
name|key
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
block|{
return|return
name|qHashRange
argument_list|(
name|key
operator|.
name|begin
argument_list|()
argument_list|,
name|key
operator|.
name|end
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [qhashrange]
end_comment
begin_comment
comment|//! [qhashrangecommutative]
end_comment
begin_function
DECL|function|qHash
specifier|inline
name|uint
name|qHash
parameter_list|(
specifier|const
name|std
operator|::
name|unordered_set
argument_list|<
name|int
argument_list|>
modifier|&
name|key
parameter_list|,
name|uint
name|seed
init|=
literal|0
parameter_list|)
block|{
return|return
name|qHashRangeCommutative
argument_list|(
name|key
operator|.
name|begin
argument_list|()
argument_list|,
name|key
operator|.
name|end
argument_list|()
argument_list|,
name|seed
argument_list|)
return|;
block|}
end_function
begin_comment
comment|//! [qhashrangecommutative]
end_comment
end_unit
