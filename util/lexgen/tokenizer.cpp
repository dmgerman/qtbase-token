begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the utils of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// auto generated. DO NOT EDIT.
end_comment
begin_class
DECL|class|RegExpTokenizer
class|class
name|RegExpTokenizer
block|{
public|public:
name|RegExpTokenizer
parameter_list|(
specifier|const
name|QString
modifier|&
name|inp
parameter_list|)
constructor_decl|;
DECL|function|next
specifier|inline
name|QChar
name|next
parameter_list|()
block|{
return|return
operator|(
name|pos
operator|<
name|input
operator|.
name|length
argument_list|()
operator|)
condition|?
name|input
operator|.
name|at
argument_list|(
name|pos
operator|++
argument_list|)
else|:
name|QChar
argument_list|()
return|;
block|}
name|int
name|lex
parameter_list|()
function_decl|;
DECL|member|input
name|QString
name|input
decl_stmt|;
DECL|member|pos
name|int
name|pos
decl_stmt|;
DECL|member|lexemStart
name|int
name|lexemStart
decl_stmt|;
DECL|member|lexemLength
name|int
name|lexemLength
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|RegExpTokenizer
name|RegExpTokenizer
operator|::
name|RegExpTokenizer
parameter_list|(
specifier|const
name|QString
modifier|&
name|inp
parameter_list|)
block|{
name|input
operator|=
name|inp
expr_stmt|;
name|pos
operator|=
literal|0
expr_stmt|;
name|lexemStart
operator|=
literal|0
expr_stmt|;
name|lexemLength
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|lex
name|int
name|RegExpTokenizer
operator|::
name|lex
parameter_list|()
block|{
name|lexemStart
operator|=
name|pos
expr_stmt|;
name|lexemLength
operator|=
literal|0
expr_stmt|;
name|int
name|lastAcceptingPos
init|=
operator|-
literal|1
decl_stmt|;
name|int
name|token
init|=
operator|-
literal|1
decl_stmt|;
name|QChar
name|ch
decl_stmt|;
comment|// initial state
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|33
condition|)
goto|goto
name|state_1
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|34
condition|)
goto|goto
name|state_2
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|35
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|39
condition|)
goto|goto
name|state_1
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|40
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_LPAREN
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|41
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_RPAREN
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|42
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_STAR
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|43
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_PLUS
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|44
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_COMMA
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|45
condition|)
goto|goto
name|state_1
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|46
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_DOT
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|47
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|62
condition|)
goto|goto
name|state_1
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|63
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_QUESTION
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|64
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|90
condition|)
goto|goto
name|state_1
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|91
condition|)
goto|goto
name|state_10
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|92
condition|)
goto|goto
name|state_11
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|93
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|122
condition|)
goto|goto
name|state_1
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|123
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_LBRACE
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|124
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_OR
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|125
condition|)
block|{
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_RBRACE
expr_stmt|;
goto|goto
name|found
goto|;
block|}
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|126
condition|)
goto|goto
name|state_1
goto|;
goto|goto
name|out
goto|;
name|state_1
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_STRING
expr_stmt|;
goto|goto
name|out
goto|;
name|state_2
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_STRING
expr_stmt|;
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|33
condition|)
goto|goto
name|state_15
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|34
condition|)
goto|goto
name|state_16
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|35
condition|)
goto|goto
name|state_15
goto|;
goto|goto
name|out
goto|;
name|state_10
label|:
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|91
condition|)
goto|goto
name|state_17
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|92
condition|)
goto|goto
name|state_18
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|93
condition|)
goto|goto
name|state_19
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|94
condition|)
goto|goto
name|state_17
goto|;
goto|goto
name|out
goto|;
name|state_11
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_STRING
expr_stmt|;
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
condition|)
goto|goto
name|state_20
goto|;
goto|goto
name|out
goto|;
name|state_15
label|:
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|33
condition|)
goto|goto
name|state_15
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|34
condition|)
goto|goto
name|state_16
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|35
condition|)
goto|goto
name|state_15
goto|;
goto|goto
name|out
goto|;
name|state_16
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_QUOTED_STRING
expr_stmt|;
goto|goto
name|out
goto|;
name|state_17
label|:
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|91
condition|)
goto|goto
name|state_17
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|92
condition|)
goto|goto
name|state_18
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|93
condition|)
goto|goto
name|state_19
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|94
condition|)
goto|goto
name|state_17
goto|;
goto|goto
name|out
goto|;
name|state_18
label|:
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|91
condition|)
goto|goto
name|state_17
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|92
condition|)
goto|goto
name|state_18
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|93
condition|)
goto|goto
name|state_21
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|94
condition|)
goto|goto
name|state_17
goto|;
goto|goto
name|out
goto|;
name|state_19
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_SEQUENCE
expr_stmt|;
goto|goto
name|out
goto|;
name|state_20
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_STRING
expr_stmt|;
goto|goto
name|out
goto|;
name|state_21
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|token
operator|=
name|RE2NFA
operator|::
name|TOK_SEQUENCE
expr_stmt|;
name|ch
operator|=
name|next
argument_list|()
expr_stmt|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|1
operator|&&
name|ch
operator|.
name|unicode
argument_list|()
operator|<=
literal|91
condition|)
goto|goto
name|state_17
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|92
condition|)
goto|goto
name|state_18
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|==
literal|93
condition|)
goto|goto
name|state_19
goto|;
if|if
condition|(
name|ch
operator|.
name|unicode
argument_list|()
operator|>=
literal|94
condition|)
goto|goto
name|state_17
goto|;
goto|goto
name|out
goto|;
name|found
label|:
name|lastAcceptingPos
operator|=
name|pos
expr_stmt|;
name|out
label|:
if|if
condition|(
name|lastAcceptingPos
operator|!=
operator|-
literal|1
condition|)
block|{
name|lexemLength
operator|=
name|lastAcceptingPos
operator|-
name|lexemStart
expr_stmt|;
name|pos
operator|=
name|lastAcceptingPos
expr_stmt|;
block|}
return|return
name|token
return|;
block|}
end_function
end_unit
