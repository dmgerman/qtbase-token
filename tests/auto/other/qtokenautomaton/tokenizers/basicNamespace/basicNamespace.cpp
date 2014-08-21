begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|/* NOTE: This file is AUTO GENERATED by qtokenautomaton2cpp.xsl. */
end_comment
begin_include
include|#
directive|include
file|"basicNamespace.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_using
using|using
namespace|namespace
name|BasicNamespace
namespace|;
end_using
begin_function
DECL|function|classifier3
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|classifier3
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
block|{
if|if
condition|(
name|data
index|[
literal|0
index|]
operator|==
literal|100
condition|)
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|string
index|[]
init|=
block|{
literal|101
block|,
literal|102
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
operator|&
name|data
index|[
literal|1
index|]
argument_list|,
operator|&
name|string
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
literal|2
argument_list|)
operator|==
literal|0
condition|)
return|return
name|_111
return|;
block|}
elseif|else
if|if
condition|(
name|data
index|[
literal|0
index|]
operator|==
literal|97
condition|)
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|string
index|[]
init|=
block|{
literal|98
block|,
literal|99
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
operator|&
name|data
index|[
literal|1
index|]
argument_list|,
operator|&
name|string
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
literal|2
argument_list|)
operator|==
literal|0
condition|)
return|return
name|_
return|;
block|}
elseif|else
if|if
condition|(
name|data
index|[
literal|0
index|]
operator|==
literal|103
condition|)
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|string
index|[]
init|=
block|{
literal|104
block|,
literal|105
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
operator|&
name|data
index|[
literal|1
index|]
argument_list|,
operator|&
name|string
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
literal|2
argument_list|)
operator|==
literal|0
condition|)
return|return
name|wobbly
return|;
block|}
return|return
name|NoKeyword
return|;
block|}
end_function
begin_function
DECL|function|classifier4
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|classifier4
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
block|{
if|if
condition|(
name|data
index|[
literal|0
index|]
operator|==
literal|70
condition|)
block|{
if|if
condition|(
name|data
index|[
literal|1
index|]
operator|==
literal|70
condition|)
block|{
if|if
condition|(
name|data
index|[
literal|2
index|]
operator|==
literal|70
condition|)
block|{
if|if
condition|(
name|data
index|[
literal|3
index|]
operator|==
literal|70
condition|)
block|{
return|return
name|FFFF
return|;
block|}
elseif|else
if|if
condition|(
name|data
index|[
literal|3
index|]
operator|==
literal|71
condition|)
block|{
return|return
name|FFFG
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|data
index|[
literal|2
index|]
operator|==
literal|71
condition|)
block|{
if|if
condition|(
name|data
index|[
literal|3
index|]
operator|==
literal|70
condition|)
block|{
return|return
name|FFGF
return|;
block|}
elseif|else
if|if
condition|(
name|data
index|[
literal|3
index|]
operator|==
literal|71
condition|)
block|{
return|return
name|FFGG
return|;
block|}
block|}
elseif|else
if|if
condition|(
name|data
index|[
literal|2
index|]
operator|==
literal|76
condition|)
block|{
if|if
condition|(
name|data
index|[
literal|3
index|]
operator|==
literal|77
condition|)
return|return
name|FFLM
return|;
block|}
block|}
block|}
return|return
name|NoKeyword
return|;
block|}
end_function
begin_function
DECL|function|classifier14
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|classifier14
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|string
index|[]
init|=
block|{
literal|99
block|,
literal|111
block|,
literal|108
block|,
literal|111
block|,
literal|110
block|,
literal|58
block|,
literal|105
block|,
literal|110
block|,
literal|58
block|,
literal|110
block|,
literal|97
block|,
literal|109
block|,
literal|101
block|,
literal|58
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
operator|&
name|data
index|[
literal|0
index|]
argument_list|,
operator|&
name|string
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
literal|14
argument_list|)
operator|==
literal|0
condition|)
return|return
name|ColonInName
return|;
return|return
name|NoKeyword
return|;
block|}
end_function
begin_function
DECL|function|classifier44
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|classifier44
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|)
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|string
index|[]
init|=
block|{
literal|97
block|,
literal|82
block|,
literal|101
block|,
literal|97
block|,
literal|108
block|,
literal|108
block|,
literal|121
block|,
literal|76
block|,
literal|111
block|,
literal|110
block|,
literal|103
block|,
literal|84
block|,
literal|111
block|,
literal|107
block|,
literal|101
block|,
literal|110
block|,
literal|73
block|,
literal|70
block|,
literal|114
block|,
literal|101
block|,
literal|97
block|,
literal|107
block|,
literal|105
block|,
literal|110
block|,
literal|77
block|,
literal|101
block|,
literal|97
block|,
literal|110
block|,
literal|73
block|,
literal|116
block|,
literal|85
block|,
literal|75
block|,
literal|110
block|,
literal|111
block|,
literal|119
block|,
literal|85
block|,
literal|75
block|,
literal|110
block|,
literal|111
block|,
literal|119
block|,
literal|75
block|,
literal|110
block|,
literal|111
block|,
literal|119
block|}
decl_stmt|;
if|if
condition|(
name|memcmp
argument_list|(
operator|&
name|data
index|[
literal|0
index|]
argument_list|,
operator|&
name|string
argument_list|,
sizeof|sizeof
argument_list|(
name|QChar
argument_list|)
operator|*
literal|44
argument_list|)
operator|==
literal|0
condition|)
return|return
name|AReallyLongTokenIFreakinMeanItUKnowUKnowKnow
return|;
return|return
name|NoKeyword
return|;
block|}
end_function
begin_function
DECL|function|toToken
name|Basic
operator|::
name|Token
name|Basic
operator|::
name|toToken
parameter_list|(
specifier|const
name|QChar
modifier|*
name|data
parameter_list|,
name|int
name|length
parameter_list|)
block|{
switch|switch
condition|(
name|length
condition|)
block|{
case|case
literal|3
case|:
return|return
name|classifier3
argument_list|(
name|data
argument_list|)
return|;
case|case
literal|4
case|:
return|return
name|classifier4
argument_list|(
name|data
argument_list|)
return|;
case|case
literal|14
case|:
return|return
name|classifier14
argument_list|(
name|data
argument_list|)
return|;
case|case
literal|44
case|:
return|return
name|classifier44
argument_list|(
name|data
argument_list|)
return|;
default|default:
return|return
name|NoKeyword
return|;
block|}
block|}
end_function
begin_function
DECL|function|toString
name|QString
name|Basic
operator|::
name|toString
parameter_list|(
name|Token
name|token
parameter_list|)
block|{
specifier|const
name|unsigned
name|short
modifier|*
name|data
init|=
literal|0
decl_stmt|;
name|int
name|length
init|=
literal|0
decl_stmt|;
switch|switch
condition|(
name|token
condition|)
block|{
case|case
name|AReallyLongTokenIFreakinMeanItUKnowUKnowKnow
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredAReallyLongTokenIFreakinMeanItUKnowUKnowKnow
index|[]
init|=
block|{
literal|97
block|,
literal|82
block|,
literal|101
block|,
literal|97
block|,
literal|108
block|,
literal|108
block|,
literal|121
block|,
literal|76
block|,
literal|111
block|,
literal|110
block|,
literal|103
block|,
literal|84
block|,
literal|111
block|,
literal|107
block|,
literal|101
block|,
literal|110
block|,
literal|73
block|,
literal|70
block|,
literal|114
block|,
literal|101
block|,
literal|97
block|,
literal|107
block|,
literal|105
block|,
literal|110
block|,
literal|77
block|,
literal|101
block|,
literal|97
block|,
literal|110
block|,
literal|73
block|,
literal|116
block|,
literal|85
block|,
literal|75
block|,
literal|110
block|,
literal|111
block|,
literal|119
block|,
literal|85
block|,
literal|75
block|,
literal|110
block|,
literal|111
block|,
literal|119
block|,
literal|75
block|,
literal|110
block|,
literal|111
block|,
literal|119
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredAReallyLongTokenIFreakinMeanItUKnowUKnowKnow
expr_stmt|;
name|length
operator|=
literal|44
expr_stmt|;
break|break;
block|}
case|case
name|ColonInName
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredColonInName
index|[]
init|=
block|{
literal|99
block|,
literal|111
block|,
literal|108
block|,
literal|111
block|,
literal|110
block|,
literal|58
block|,
literal|105
block|,
literal|110
block|,
literal|58
block|,
literal|110
block|,
literal|97
block|,
literal|109
block|,
literal|101
block|,
literal|58
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredColonInName
expr_stmt|;
name|length
operator|=
literal|14
expr_stmt|;
break|break;
block|}
case|case
name|FFFF
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredFFFF
index|[]
init|=
block|{
literal|70
block|,
literal|70
block|,
literal|70
block|,
literal|70
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredFFFF
expr_stmt|;
name|length
operator|=
literal|4
expr_stmt|;
break|break;
block|}
case|case
name|FFFG
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredFFFG
index|[]
init|=
block|{
literal|70
block|,
literal|70
block|,
literal|70
block|,
literal|71
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredFFFG
expr_stmt|;
name|length
operator|=
literal|4
expr_stmt|;
break|break;
block|}
case|case
name|FFGF
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredFFGF
index|[]
init|=
block|{
literal|70
block|,
literal|70
block|,
literal|71
block|,
literal|70
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredFFGF
expr_stmt|;
name|length
operator|=
literal|4
expr_stmt|;
break|break;
block|}
case|case
name|FFGG
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredFFGG
index|[]
init|=
block|{
literal|70
block|,
literal|70
block|,
literal|71
block|,
literal|71
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredFFGG
expr_stmt|;
name|length
operator|=
literal|4
expr_stmt|;
break|break;
block|}
case|case
name|FFLM
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredFFLM
index|[]
init|=
block|{
literal|70
block|,
literal|70
block|,
literal|76
block|,
literal|77
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredFFLM
expr_stmt|;
name|length
operator|=
literal|4
expr_stmt|;
break|break;
block|}
case|case
name|_
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStored_
index|[]
init|=
block|{
literal|97
block|,
literal|98
block|,
literal|99
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStored_
expr_stmt|;
name|length
operator|=
literal|3
expr_stmt|;
break|break;
block|}
case|case
name|_111
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStored_111
index|[]
init|=
block|{
literal|100
block|,
literal|101
block|,
literal|102
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStored_111
expr_stmt|;
name|length
operator|=
literal|3
expr_stmt|;
break|break;
block|}
case|case
name|wobbly
case|:
block|{
specifier|static
specifier|const
name|unsigned
name|short
name|staticallyStoredwobbly
index|[]
init|=
block|{
literal|103
block|,
literal|104
block|,
literal|105
block|,
literal|0
block|}
decl_stmt|;
name|data
operator|=
name|staticallyStoredwobbly
expr_stmt|;
name|length
operator|=
literal|3
expr_stmt|;
break|break;
block|}
default|default:
comment|/* It's either the default token, or an undefined enum                              * value. We silence a compiler warning, and return the                              * empty string. */
empty_stmt|;
block|}
union|union
block|{
specifier|const
name|unsigned
name|short
modifier|*
name|data
decl_stmt|;
specifier|const
name|QChar
modifier|*
name|asQChar
decl_stmt|;
block|}
name|converter
union|;
name|converter
operator|.
name|data
operator|=
name|data
expr_stmt|;
return|return
name|QString
operator|::
name|fromRawData
argument_list|(
name|converter
operator|.
name|asQChar
argument_list|,
name|length
argument_list|)
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
