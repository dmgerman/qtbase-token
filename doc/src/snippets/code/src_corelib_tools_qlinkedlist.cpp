begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: http://www.qt-project.org/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** You may use this file under the terms of the BSD license as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor **     the names of its contributors may be used to endorse or promote **     products derived from this software without specific prior written **     permission. ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_decl_stmt
DECL|variable|integerList
name|QLinkedList
argument_list|<
name|int
argument_list|>
name|integerList
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|timeList
name|QLinkedList
argument_list|<
name|QTime
argument_list|>
name|timeList
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"one"
operator|<<
literal|"two"
operator|<<
literal|"three"
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: ["one", "two", "three"]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
end_expr_stmt
begin_while
while|while
condition|(
operator|!
name|list
operator|.
name|isEmpty
argument_list|()
condition|)
operator|delete
name|list
operator|.
name|takeFirst
argument_list|()
expr_stmt|;
end_while
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"two"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"three"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: ["one", "two", "three"]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|prepend
argument_list|(
literal|"one"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|prepend
argument_list|(
literal|"two"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|prepend
argument_list|(
literal|"three"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: ["three", "two", "one"]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"sun"
operator|<<
literal|"cloud"
operator|<<
literal|"sun"
operator|<<
literal|"rain"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|removeAll
argument_list|(
literal|"sun"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: ["cloud", "rain"]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_decl_stmt
DECL|variable|list
name|QList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|"sun"
operator|<<
literal|"cloud"
operator|<<
literal|"sun"
operator|<<
literal|"rain"
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|removeOne
argument_list|(
literal|"sun"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_comment
comment|// list: ["cloud", "sun", "rain"]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"January"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"February"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
name|list
operator|.
name|append
argument_list|(
literal|"December"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QLinkedList
argument_list|<
name|QString
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
name|list
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
DECL|variable|endl
name|cout
operator|<<
operator|*
name|i
operator|<<
name|endl
expr_stmt|;
end_for
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QLinkedList
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|it
operator|=
name|qFind
argument_list|(
name|list
operator|.
name|begin
argument_list|()
argument_list|,
name|list
operator|.
name|end
argument_list|()
argument_list|,
literal|"Joel"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|it
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|)
DECL|variable|endl
name|cout
operator|<<
literal|"Found Joel"
operator|<<
name|endl
expr_stmt|;
end_if
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_decl_stmt
DECL|variable|i
name|QLinkedList
argument_list|<
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
name|list
operator|.
name|begin
argument_list|()
init|;
name|i
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|;
operator|++
name|i
control|)
operator|*
name|i
operator|+=
literal|2
expr_stmt|;
end_for
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QLinkedList
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|i
operator|=
name|list
operator|.
name|begin
argument_list|()
expr_stmt|;
end_expr_stmt
begin_while
while|while
condition|(
name|i
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|i
operator|)
operator|.
name|startsWith
argument_list|(
literal|"_"
argument_list|)
condition|)
name|i
operator|=
name|list
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
comment|//! [10]
end_comment
begin_comment
comment|//! [11]
end_comment
begin_decl_stmt
DECL|variable|i
name|QLinkedList
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|i
init|=
name|list
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
name|list
operator|.
name|end
argument_list|()
condition|)
block|{
name|QLinkedList
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|previous
init|=
name|i
decl_stmt|;
operator|++
name|i
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|previous
operator|)
operator|.
name|startsWith
argument_list|(
literal|"_"
argument_list|)
condition|)
name|list
operator|.
name|erase
argument_list|(
name|previous
argument_list|)
expr_stmt|;
block|}
end_while
begin_comment
comment|//! [11]
end_comment
begin_comment
comment|//! [12]
end_comment
begin_comment
comment|// WRONG
end_comment
begin_while
while|while
condition|(
name|i
operator|!=
name|list
operator|.
name|end
argument_list|()
condition|)
block|{
if|if
condition|(
operator|(
operator|*
name|i
operator|)
operator|.
name|startsWith
argument_list|(
literal|"_"
argument_list|)
condition|)
name|list
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
comment|//! [12]
end_comment
begin_comment
comment|//! [13]
end_comment
begin_if
if|if
condition|(
operator|*
name|it
operator|==
literal|"Hello"
condition|)
operator|*
name|it
operator|=
literal|"Bonjour"
expr_stmt|;
end_if
begin_comment
comment|//! [13]
end_comment
begin_comment
comment|//! [14]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"January"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|append
argument_list|(
literal|"February"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
operator|...
name|list
operator|.
name|append
argument_list|(
literal|"December"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|i
name|QLinkedList
argument_list|<
name|QString
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
name|list
operator|.
name|constBegin
argument_list|()
init|;
name|i
operator|!=
name|list
operator|.
name|constEnd
argument_list|()
condition|;
operator|++
name|i
control|)
DECL|variable|endl
name|cout
operator|<<
operator|*
name|i
operator|<<
name|endl
expr_stmt|;
end_for
begin_comment
comment|//! [14]
end_comment
begin_comment
comment|//! [15]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|QString
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
operator|...
name|QLinkedList
argument_list|<
name|QString
argument_list|>
operator|::
name|iterator
name|it
operator|=
name|qFind
argument_list|(
name|list
operator|.
name|constBegin
argument_list|()
argument_list|,
name|list
operator|.
name|constEnd
argument_list|()
argument_list|,
literal|"Joel"
argument_list|)
expr_stmt|;
end_expr_stmt
begin_if
if|if
condition|(
name|it
operator|!=
name|list
operator|.
name|constEnd
argument_list|()
condition|)
DECL|variable|endl
name|cout
operator|<<
literal|"Found Joel"
operator|<<
name|endl
expr_stmt|;
end_if
begin_comment
comment|//! [15]
end_comment
begin_comment
comment|//! [16]
end_comment
begin_decl_stmt
DECL|variable|stdlist
name|std
operator|::
name|list
argument_list|<
name|double
argument_list|>
name|stdlist
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|.
name|push_back
argument_list|(
literal|1.2
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|push_back
argument_list|(
literal|0.5
argument_list|)
expr_stmt|;
end_expr_stmt
begin_expr_stmt
name|list
operator|.
name|push_back
argument_list|(
literal|3.14
argument_list|)
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|double
argument_list|>
name|list
init|=
name|QLinkedList
argument_list|<
name|double
argument_list|>
operator|::
name|fromStdList
argument_list|(
name|stdlist
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [16]
end_comment
begin_comment
comment|//! [17]
end_comment
begin_decl_stmt
DECL|variable|list
name|QLinkedList
argument_list|<
name|double
argument_list|>
name|list
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|list
operator|<<
literal|1.2
operator|<<
literal|0.5
operator|<<
literal|3.14
expr_stmt|;
end_expr_stmt
begin_decl_stmt
DECL|variable|stdlist
name|std
operator|::
name|list
argument_list|<
name|double
argument_list|>
name|stdlist
init|=
name|list
operator|.
name|toStdList
argument_list|()
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [17]
end_comment
end_unit
