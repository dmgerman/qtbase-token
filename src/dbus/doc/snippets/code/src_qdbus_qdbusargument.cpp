begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the documentation of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:BSD$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** BSD License Usage ** Alternatively, you may use this file under the terms of the BSD license ** as follows: ** ** "Redistribution and use in source and binary forms, with or without ** modification, are permitted provided that the following conditions are ** met: **   * Redistributions of source code must retain the above copyright **     notice, this list of conditions and the following disclaimer. **   * Redistributions in binary form must reproduce the above copyright **     notice, this list of conditions and the following disclaimer in **     the documentation and/or other materials provided with the **     distribution. **   * Neither the name of The Qt Company Ltd nor the names of its **     contributors may be used to endorse or promote products derived **     from this software without specific prior written permission. ** ** ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE." ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|//! [0]
end_comment
begin_struct
DECL|struct|MyStructure
struct|struct
name|MyStructure
block|{
DECL|member|count
name|int
name|count
decl_stmt|;
DECL|member|name
name|QString
name|name
decl_stmt|;
block|}
struct|;
end_struct
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|MyStructure
argument_list|)
end_macro
begin_comment
comment|// Marshall the MyStructure data into a D-Bus argument
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|MyStructure
modifier|&
name|mystruct
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|mystruct
operator|.
name|count
operator|<<
name|mystruct
operator|.
name|name
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|// Retrieve the MyStructure data from the D-Bus argument
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|MyStructure
modifier|&
name|mystruct
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|mystruct
operator|.
name|count
operator|>>
name|mystruct
operator|.
name|name
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [0]
end_comment
begin_comment
comment|//! [1]
end_comment
begin_expr_stmt
name|qDBusRegisterMetaType
argument_list|<
name|MyStructure
argument_list|>
argument_list|()
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [1]
end_comment
begin_comment
comment|//! [2]
end_comment
begin_decl_stmt
DECL|variable|item
name|MyType
name|item
init|=
name|qdbus_cast
argument_list|<
name|Type
argument_list|>
argument_list|(
name|argument
argument_list|)
decl_stmt|;
end_decl_stmt
begin_comment
comment|//! [2]
end_comment
begin_comment
comment|//! [3]
end_comment
begin_decl_stmt
DECL|variable|item
name|MyType
name|item
decl_stmt|;
end_decl_stmt
begin_expr_stmt
DECL|variable|item
name|argument
operator|>>
name|item
expr_stmt|;
end_expr_stmt
begin_comment
comment|//! [3]
end_comment
begin_comment
comment|//! [4]
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|MyStructure
modifier|&
name|mystruct
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|mystruct
operator|.
name|member1
operator|<<
name|mystruct
operator|.
name|member2
operator|<<
operator|...
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [4]
end_comment
begin_comment
comment|//! [5]
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|MyStructure
modifier|&
name|mystruct
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|mystruct
operator|.
name|member1
operator|<<
name|mystruct
operator|.
name|member2
expr_stmt|;
name|argument
operator|.
name|beginStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|mystruct
operator|.
name|member3
operator|.
name|subMember1
operator|<<
name|mystruct
operator|.
name|member3
operator|.
name|subMember2
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|mystruct
operator|.
name|member4
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [5]
end_comment
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|// append an array of MyElement types
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|MyArray
modifier|&
name|myarray
parameter_list|)
block|{
name|argument
operator|.
name|beginArray
argument_list|(
name|qMetaTypeId
argument_list|<
name|MyElement
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|myarray
operator|.
name|length
condition|;
operator|++
name|i
control|)
name|argument
operator|<<
name|myarray
operator|.
name|elements
index|[
name|i
index|]
expr_stmt|;
name|argument
operator|.
name|endArray
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [6]
end_comment
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|// append a dictionary that associates ints to MyValue types
end_comment
begin_function
DECL|function|operator <<
name|QDBusArgument
modifier|&
name|operator
name|<<
parameter_list|(
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
specifier|const
name|MyDictionary
modifier|&
name|mydict
parameter_list|)
block|{
name|argument
operator|.
name|beginMap
argument_list|(
name|QVariant
operator|::
name|Int
argument_list|,
name|qMetaTypeId
argument_list|<
name|MyValue
argument_list|>
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mydict
operator|.
name|length
condition|;
operator|++
name|i
control|)
block|{
name|argument
operator|.
name|beginMapEntry
argument_list|()
expr_stmt|;
name|argument
operator|<<
name|mydict
operator|.
name|data
index|[
name|i
index|]
operator|.
name|key
operator|<<
name|mydict
operator|.
name|data
index|[
name|i
index|]
operator|.
name|value
expr_stmt|;
name|argument
operator|.
name|endMapEntry
argument_list|()
expr_stmt|;
block|}
name|argument
operator|.
name|endMap
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [7]
end_comment
begin_comment
comment|//! [8]
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|MyStructure
modifier|&
name|mystruct
parameter_list|)
block|{
name|argument
operator|.
name|beginStructure
argument_list|()
name|argument
operator|>>
name|mystruct
operator|.
name|member1
operator|>>
name|mystruct
operator|.
name|member2
operator|>>
name|mystruct
operator|.
name|member3
operator|>>
operator|...
expr_stmt|;
name|argument
operator|.
name|endStructure
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [8]
end_comment
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|// extract a MyArray array of MyElement elements
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|MyArray
modifier|&
name|myarray
parameter_list|)
block|{
name|argument
operator|.
name|beginArray
argument_list|()
expr_stmt|;
name|myarray
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|argument
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|MyElement
name|element
decl_stmt|;
name|argument
operator|>>
name|element
expr_stmt|;
name|myarray
operator|.
name|append
argument_list|(
name|element
argument_list|)
expr_stmt|;
block|}
name|argument
operator|.
name|endArray
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [9]
end_comment
begin_comment
comment|//! [10]
end_comment
begin_comment
comment|// extract a MyDictionary map that associates ints to MyValue elements
end_comment
begin_function
DECL|function|operator >>
specifier|const
name|QDBusArgument
modifier|&
name|operator
name|>>
parameter_list|(
specifier|const
name|QDBusArgument
modifier|&
name|argument
parameter_list|,
name|MyDictionary
modifier|&
name|mydict
parameter_list|)
block|{
name|argument
operator|.
name|beginMap
argument_list|()
expr_stmt|;
name|mydict
operator|.
name|clear
argument_list|()
expr_stmt|;
while|while
condition|(
operator|!
name|argMap
operator|.
name|atEnd
argument_list|()
condition|)
block|{
name|int
name|key
decl_stmt|;
name|MyValue
name|value
decl_stmt|;
name|argument
operator|.
name|beginMapEntry
argument_list|()
expr_stmt|;
name|argument
operator|>>
name|key
operator|>>
name|value
expr_stmt|;
name|argument
operator|.
name|endMapEntry
argument_list|()
expr_stmt|;
name|mydict
operator|.
name|append
argument_list|(
name|key
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
name|argument
operator|.
name|endMap
argument_list|()
expr_stmt|;
return|return
name|argument
return|;
block|}
end_function
begin_comment
comment|//! [10]
end_comment
end_unit
