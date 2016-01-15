begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the tools applications of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|UTILS_H
end_ifndef
begin_define
DECL|macro|UTILS_H
define|#
directive|define
name|UTILS_H
end_define
begin_include
include|#
directive|include
file|"ui4.h"
end_include
begin_include
include|#
directive|include
file|<qstring.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|toBool
specifier|inline
name|bool
name|toBool
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|)
block|{
return|return
name|str
operator|.
name|toLower
argument_list|()
operator|==
name|QLatin1String
argument_list|(
literal|"true"
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|toString
specifier|inline
name|QString
name|toString
parameter_list|(
specifier|const
name|DomString
modifier|*
name|str
parameter_list|)
block|{
return|return
name|str
condition|?
name|str
operator|->
name|text
argument_list|()
else|:
name|QString
argument_list|()
return|;
block|}
end_function
begin_enum
DECL|enum|StringFlags
enum|enum
name|StringFlags
block|{
DECL|enumerator|Utf8String
name|Utf8String
init|=
literal|0x1
block|,
DECL|enumerator|MultiLineString
name|MultiLineString
init|=
literal|0x2
block|}
enum|;
end_enum
begin_function
DECL|function|fixString
specifier|inline
name|QString
name|fixString
parameter_list|(
specifier|const
name|QString
modifier|&
name|str
parameter_list|,
specifier|const
name|QString
modifier|&
name|indent
parameter_list|,
name|unsigned
modifier|*
name|stringFlags
init|=
literal|0
parameter_list|)
block|{
name|QString
name|cursegment
decl_stmt|;
name|QStringList
name|result
decl_stmt|;
specifier|const
name|QByteArray
name|utf8
init|=
name|str
operator|.
name|toUtf8
argument_list|()
decl_stmt|;
specifier|const
name|int
name|utf8Length
init|=
name|utf8
operator|.
name|length
argument_list|()
decl_stmt|;
name|unsigned
name|flags
init|=
literal|0
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
name|utf8Length
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|uchar
name|cbyte
init|=
name|utf8
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
name|cbyte
operator|>=
literal|0x80
condition|)
block|{
name|cursegment
operator|+=
name|QLatin1Char
argument_list|(
literal|'\\'
argument_list|)
expr_stmt|;
name|cursegment
operator|+=
name|QString
operator|::
name|number
argument_list|(
name|cbyte
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|flags
operator||=
name|Utf8String
expr_stmt|;
block|}
else|else
block|{
switch|switch
condition|(
name|cbyte
condition|)
block|{
case|case
literal|'\\'
case|:
name|cursegment
operator|+=
name|QLatin1String
argument_list|(
literal|"\\\\"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'\"'
case|:
name|cursegment
operator|+=
name|QLatin1String
argument_list|(
literal|"\\\""
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'\r'
case|:
break|break;
case|case
literal|'\n'
case|:
name|flags
operator||=
name|MultiLineString
expr_stmt|;
name|cursegment
operator|+=
name|QLatin1String
argument_list|(
literal|"\\n\"\n\""
argument_list|)
expr_stmt|;
break|break;
default|default:
name|cursegment
operator|+=
name|QLatin1Char
argument_list|(
name|cbyte
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|cursegment
operator|.
name|length
argument_list|()
operator|>
literal|1024
condition|)
block|{
name|result
operator|<<
name|cursegment
expr_stmt|;
name|cursegment
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|cursegment
operator|.
name|isEmpty
argument_list|()
condition|)
name|result
operator|<<
name|cursegment
expr_stmt|;
name|QString
name|joinstr
init|=
name|QLatin1String
argument_list|(
literal|"\"\n"
argument_list|)
decl_stmt|;
name|joinstr
operator|+=
name|indent
expr_stmt|;
name|joinstr
operator|+=
name|indent
expr_stmt|;
name|joinstr
operator|+=
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
name|QString
name|rc
argument_list|(
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
argument_list|)
decl_stmt|;
name|rc
operator|+=
name|result
operator|.
name|join
argument_list|(
name|joinstr
argument_list|)
expr_stmt|;
name|rc
operator|+=
name|QLatin1Char
argument_list|(
literal|'"'
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|.
name|size
argument_list|()
operator|>
literal|1
condition|)
name|flags
operator||=
name|MultiLineString
expr_stmt|;
if|if
condition|(
name|stringFlags
condition|)
operator|*
name|stringFlags
operator|=
name|flags
expr_stmt|;
return|return
name|rc
return|;
block|}
end_function
begin_function
DECL|function|writeString
specifier|inline
name|QString
name|writeString
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|,
specifier|const
name|QString
modifier|&
name|indent
parameter_list|)
block|{
name|unsigned
name|flags
init|=
literal|0
decl_stmt|;
specifier|const
name|QString
name|ret
init|=
name|fixString
argument_list|(
name|s
argument_list|,
name|indent
argument_list|,
operator|&
name|flags
argument_list|)
decl_stmt|;
if|if
condition|(
name|flags
operator|&
name|Utf8String
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"QString::fromUtf8("
argument_list|)
operator|+
name|ret
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
return|;
comment|// MSVC cannot concat L"foo" "bar" (C2308: concatenating mismatched strings),
comment|// use QLatin1String instead (all platforms to avoid cross-compiling issues).
if|if
condition|(
name|flags
operator|&
name|MultiLineString
condition|)
return|return
name|QLatin1String
argument_list|(
literal|"QLatin1String("
argument_list|)
operator|+
name|ret
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
return|;
return|return
name|QLatin1String
argument_list|(
literal|"QStringLiteral("
argument_list|)
operator|+
name|ret
operator|+
name|QLatin1Char
argument_list|(
literal|')'
argument_list|)
return|;
block|}
end_function
begin_expr_stmt
DECL|variable|QString
specifier|inline
name|QHash
operator|<
name|QString
operator|,
name|DomProperty
operator|*
operator|>
name|propertyMap
argument_list|(
argument|const QList<DomProperty *>&properties
argument_list|)
block|{
name|QHash
operator|<
name|QString
block|,
name|DomProperty
operator|*
operator|>
name|map
block|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|properties
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
block|{
name|DomProperty
modifier|*
name|p
init|=
name|properties
operator|.
name|at
argument_list|(
name|i
argument_list|)
decl_stmt|;
name|map
operator|.
name|insert
argument_list|(
name|p
operator|->
name|attributeName
argument_list|()
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_expr_stmt
begin_return
return|return
name|map
return|;
end_return
begin_function
unit|}  inline
DECL|function|unique
name|QStringList
name|unique
parameter_list|(
specifier|const
name|QStringList
modifier|&
name|lst
parameter_list|)
block|{
name|QHash
operator|<
name|QString
operator|,
name|bool
operator|>
name|h
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
name|lst
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|h
operator|.
name|insert
argument_list|(
name|lst
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|true
argument_list|)
expr_stmt|;
return|return
name|h
operator|.
name|keys
argument_list|()
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// UTILS_H
end_comment
end_unit
