begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QLALR module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<cstdlib>
end_include
begin_include
include|#
directive|include
file|<cstdio>
end_include
begin_enum
DECL|enum|Token
enum|enum
name|Token
block|{
DECL|enumerator|EOF_SYMBOL
name|EOF_SYMBOL
block|,
DECL|enumerator|LEFT_ANGLE
name|LEFT_ANGLE
block|,
DECL|enumerator|RIGHT_ANGLE
name|RIGHT_ANGLE
block|,
DECL|enumerator|ANY
name|ANY
block|, }
enum|;
end_enum
begin_decl_stmt
DECL|variable|current_char
specifier|static
name|int
name|current_char
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|yytoken
specifier|static
name|int
name|yytoken
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|in_tag
specifier|static
name|bool
name|in_tag
init|=
literal|false
decl_stmt|;
end_decl_stmt
begin_function_decl
name|bool
name|parseXmlStream
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|parseTagOrWord
parameter_list|()
function_decl|;
end_function_decl
begin_function_decl
name|bool
name|parseTagName
parameter_list|()
function_decl|;
end_function_decl
begin_function
DECL|function|nextToken
specifier|inline
name|int
name|nextToken
parameter_list|()
block|{
name|current_char
operator|=
name|fgetc
argument_list|(
name|stdin
argument_list|)
expr_stmt|;
if|if
condition|(
name|current_char
operator|==
name|EOF
condition|)
block|{
return|return
operator|(
name|yytoken
operator|=
name|EOF_SYMBOL
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|current_char
operator|==
literal|'<'
condition|)
block|{
name|in_tag
operator|=
literal|true
expr_stmt|;
return|return
operator|(
name|yytoken
operator|=
name|LEFT_ANGLE
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|in_tag
operator|&&
name|current_char
operator|==
literal|'>'
condition|)
block|{
name|in_tag
operator|=
literal|false
expr_stmt|;
return|return
operator|(
name|yytoken
operator|=
name|RIGHT_ANGLE
operator|)
return|;
block|}
return|return
operator|(
name|yytoken
operator|=
name|ANY
operator|)
return|;
block|}
end_function
begin_function
DECL|function|parse
name|bool
name|parse
parameter_list|()
block|{
name|nextToken
argument_list|()
expr_stmt|;
return|return
name|parseXmlStream
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|parseXmlStream
name|bool
name|parseXmlStream
parameter_list|()
block|{
while|while
condition|(
name|parseTagOrWord
argument_list|()
condition|)
empty_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parseTagOrWord
name|bool
name|parseTagOrWord
parameter_list|()
block|{
if|if
condition|(
name|yytoken
operator|==
name|LEFT_ANGLE
condition|)
block|{
name|nextToken
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|parseTagName
argument_list|()
condition|)
return|return
literal|false
return|;
if|if
condition|(
name|yytoken
operator|!=
name|RIGHT_ANGLE
condition|)
return|return
literal|false
return|;
name|nextToken
argument_list|()
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"*** found a tag\n"
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|yytoken
operator|==
name|ANY
condition|)
block|{
name|nextToken
argument_list|()
expr_stmt|;
block|}
else|else
block|{
return|return
literal|false
return|;
block|}
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|parseTagName
name|bool
name|parseTagName
parameter_list|()
block|{
while|while
condition|(
name|yytoken
operator|==
name|ANY
condition|)
name|nextToken
argument_list|()
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|main
name|int
name|main
parameter_list|()
block|{
if|if
condition|(
name|parse
argument_list|()
condition|)
name|printf
argument_list|(
literal|"OK\n"
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"KO\n"
argument_list|)
expr_stmt|;
block|}
end_function
end_unit
