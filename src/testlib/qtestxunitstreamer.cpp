begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtTest module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qtestxunitstreamer.h"
end_include
begin_include
include|#
directive|include
file|"qtestelement.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qtestlog_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qtestresult_p.h"
end_include
begin_include
include|#
directive|include
file|"QtTest/private/qxmltestlogger_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_constructor
DECL|function|QTestXunitStreamer
name|QTestXunitStreamer
operator|::
name|QTestXunitStreamer
parameter_list|()
member_init_list|:
name|QTestBasicStreamer
argument_list|()
block|{}
end_constructor
begin_destructor
DECL|function|~QTestXunitStreamer
name|QTestXunitStreamer
operator|::
name|~
name|QTestXunitStreamer
parameter_list|()
block|{}
end_destructor
begin_function
DECL|function|indentForElement
name|void
name|QTestXunitStreamer
operator|::
name|indentForElement
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|size
parameter_list|)
block|{
if|if
condition|(
name|size
operator|==
literal|0
condition|)
return|return;
name|buf
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|element
condition|)
return|return;
name|char
modifier|*
name|endbuf
init|=
name|buf
operator|+
name|size
decl_stmt|;
name|element
operator|=
name|element
operator|->
name|parentElement
argument_list|()
expr_stmt|;
while|while
condition|(
name|element
operator|&&
name|buf
operator|+
literal|2
operator|<
name|endbuf
condition|)
block|{
operator|*
operator|(
name|buf
operator|++
operator|)
operator|=
literal|' '
expr_stmt|;
operator|*
operator|(
name|buf
operator|++
operator|)
operator|=
literal|' '
expr_stmt|;
operator|*
name|buf
operator|=
literal|0
expr_stmt|;
name|element
operator|=
name|element
operator|->
name|parentElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|formatStart
name|void
name|QTestXunitStreamer
operator|::
name|formatStart
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
name|char
name|indent
index|[
literal|20
index|]
decl_stmt|;
name|indentForElement
argument_list|(
name|element
argument_list|,
name|indent
argument_list|,
sizeof|sizeof
argument_list|(
name|indent
argument_list|)
argument_list|)
expr_stmt|;
comment|// Errors are written as CDATA within system-err, comments elsewhere
if|if
condition|(
name|element
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_Error
condition|)
block|{
if|if
condition|(
name|element
operator|->
name|parentElement
argument_list|()
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_SystemError
condition|)
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"<![CDATA["
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"%s<!--"
argument_list|,
name|indent
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"%s<%s"
argument_list|,
name|indent
argument_list|,
name|element
operator|->
name|elementName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatEnd
name|void
name|QTestXunitStreamer
operator|::
name|formatEnd
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
if|if
condition|(
operator|!
name|element
operator|->
name|childElements
argument_list|()
condition|)
block|{
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return;
block|}
name|char
name|indent
index|[
literal|20
index|]
decl_stmt|;
name|indentForElement
argument_list|(
name|element
argument_list|,
name|indent
argument_list|,
sizeof|sizeof
argument_list|(
name|indent
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"%s</%s>\n"
argument_list|,
name|indent
argument_list|,
name|element
operator|->
name|elementName
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|formatAttributes
name|void
name|QTestXunitStreamer
operator|::
name|formatAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
specifier|const
name|QTestElementAttribute
modifier|*
name|attribute
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|attribute
operator|||
operator|!
name|formatted
condition|)
return|return;
name|QTest
operator|::
name|AttributeIndex
name|attrindex
init|=
name|attribute
operator|->
name|index
argument_list|()
decl_stmt|;
comment|// For errors within system-err, we only want to output `message'
if|if
condition|(
name|element
operator|&&
name|element
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_Error
operator|&&
name|element
operator|->
name|parentElement
argument_list|()
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_SystemError
condition|)
block|{
if|if
condition|(
name|attrindex
operator|!=
name|QTest
operator|::
name|AI_Description
condition|)
return|return;
name|QXmlTestLogger
operator|::
name|xmlCdata
argument_list|(
name|formatted
argument_list|,
name|attribute
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
return|return;
block|}
name|char
specifier|const
modifier|*
name|key
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|attrindex
operator|==
name|QTest
operator|::
name|AI_Description
condition|)
name|key
operator|=
literal|"message"
expr_stmt|;
elseif|else
if|if
condition|(
name|attrindex
operator|!=
name|QTest
operator|::
name|AI_File
operator|&&
name|attrindex
operator|!=
name|QTest
operator|::
name|AI_Line
condition|)
name|key
operator|=
name|attribute
operator|->
name|name
argument_list|()
expr_stmt|;
if|if
condition|(
name|key
condition|)
block|{
name|QTestCharBuffer
name|quotedValue
decl_stmt|;
name|QXmlTestLogger
operator|::
name|xmlQuote
argument_list|(
operator|&
name|quotedValue
argument_list|,
name|attribute
operator|->
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|" %s=\"%s\""
argument_list|,
name|key
argument_list|,
name|quotedValue
operator|.
name|constData
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|formatted
operator|->
name|data
argument_list|()
index|[
literal|0
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|formatAfterAttributes
name|void
name|QTestXunitStreamer
operator|::
name|formatAfterAttributes
parameter_list|(
specifier|const
name|QTestElement
modifier|*
name|element
parameter_list|,
name|QTestCharBuffer
modifier|*
name|formatted
parameter_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|element
operator|||
operator|!
name|formatted
condition|)
return|return;
comment|// Errors are written as CDATA within system-err, comments elsewhere
if|if
condition|(
name|element
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_Error
condition|)
block|{
if|if
condition|(
name|element
operator|->
name|parentElement
argument_list|()
operator|->
name|elementType
argument_list|()
operator|==
name|QTest
operator|::
name|LET_SystemError
condition|)
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"]]>\n"
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|" -->\n"
argument_list|)
expr_stmt|;
block|}
return|return;
block|}
if|if
condition|(
operator|!
name|element
operator|->
name|childElements
argument_list|()
condition|)
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|"/>\n"
argument_list|)
expr_stmt|;
else|else
name|QTest
operator|::
name|qt_asprintf
argument_list|(
name|formatted
argument_list|,
literal|">\n"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|output
name|void
name|QTestXunitStreamer
operator|::
name|output
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|)
specifier|const
block|{
name|outputString
argument_list|(
literal|"<?xml version=\"1.0\" encoding=\"UTF-8\" ?>\n"
argument_list|)
expr_stmt|;
name|QTestBasicStreamer
operator|::
name|output
argument_list|(
name|element
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|outputElements
name|void
name|QTestXunitStreamer
operator|::
name|outputElements
parameter_list|(
name|QTestElement
modifier|*
name|element
parameter_list|,
name|bool
parameter_list|)
specifier|const
block|{
name|QTestCharBuffer
name|buf
decl_stmt|;
name|bool
name|hasChildren
decl_stmt|;
comment|/*         Elements are in reverse order of occurrence, so start from the end and work         our way backwards.     */
while|while
condition|(
name|element
operator|&&
name|element
operator|->
name|nextElement
argument_list|()
condition|)
block|{
name|element
operator|=
name|element
operator|->
name|nextElement
argument_list|()
expr_stmt|;
block|}
while|while
condition|(
name|element
condition|)
block|{
name|hasChildren
operator|=
name|element
operator|->
name|childElements
argument_list|()
expr_stmt|;
if|if
condition|(
name|element
operator|->
name|elementType
argument_list|()
operator|!=
name|QTest
operator|::
name|LET_Benchmark
condition|)
block|{
name|formatStart
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|formatBeforeAttributes
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
name|outputElementAttributes
argument_list|(
name|element
argument_list|,
name|element
operator|->
name|attributes
argument_list|()
argument_list|)
expr_stmt|;
name|formatAfterAttributes
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|hasChildren
condition|)
name|outputElements
argument_list|(
name|element
operator|->
name|childElements
argument_list|()
argument_list|,
literal|true
argument_list|)
expr_stmt|;
name|formatEnd
argument_list|(
name|element
argument_list|,
operator|&
name|buf
argument_list|)
expr_stmt|;
name|outputString
argument_list|(
name|buf
operator|.
name|data
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|element
operator|=
name|element
operator|->
name|previousElement
argument_list|()
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
