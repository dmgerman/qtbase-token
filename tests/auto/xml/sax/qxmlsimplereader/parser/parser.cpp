begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:GPL-EXCEPT$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3 as published by the Free Software ** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qxml.h>
end_include
begin_include
include|#
directive|include
file|<qregexp.h>
end_include
begin_include
include|#
directive|include
file|"parser.h"
end_include
begin_class
DECL|class|ContentHandler
class|class
name|ContentHandler
super|:
specifier|public
name|QXmlDefaultHandler
block|{
public|public:
name|ContentHandler
parameter_list|()
constructor_decl|;
comment|// QXmlContentHandler methods
name|bool
name|startDocument
parameter_list|()
function_decl|;
name|bool
name|endDocument
parameter_list|()
function_decl|;
name|bool
name|startElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceURI
parameter_list|,
specifier|const
name|QString
modifier|&
name|localName
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|,
specifier|const
name|QXmlAttributes
modifier|&
name|atts
parameter_list|)
function_decl|;
name|bool
name|endElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceURI
parameter_list|,
specifier|const
name|QString
modifier|&
name|localName
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|)
function_decl|;
name|bool
name|characters
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
function_decl|;
name|void
name|setDocumentLocator
parameter_list|(
name|QXmlLocator
modifier|*
name|locator
parameter_list|)
function_decl|;
name|bool
name|startPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|uri
parameter_list|)
function_decl|;
name|bool
name|endPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
function_decl|;
name|bool
name|ignorableWhitespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
function_decl|;
name|bool
name|processingInstruction
parameter_list|(
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
specifier|const
name|QString
modifier|&
name|data
parameter_list|)
function_decl|;
name|bool
name|skippedEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
comment|// QXmlErrorHandler methods
name|bool
name|warning
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
function_decl|;
name|bool
name|error
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
function_decl|;
name|bool
name|fatalError
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
function_decl|;
comment|// QXmlDTDHandler methods
name|bool
name|notationDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
function_decl|;
name|bool
name|unparsedEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
specifier|const
name|QString
modifier|&
name|notationName
parameter_list|)
function_decl|;
comment|// QXmlEntityResolver methods
name|bool
name|resolveEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
name|QXmlInputSource
modifier|*
modifier|&
parameter_list|)
function_decl|;
comment|// QXmlLexicalHandler methods
name|bool
name|startDTD
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
function_decl|;
name|bool
name|endDTD
parameter_list|()
function_decl|;
name|bool
name|startEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|bool
name|endEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
function_decl|;
name|bool
name|startCDATA
parameter_list|()
function_decl|;
name|bool
name|endCDATA
parameter_list|()
function_decl|;
name|bool
name|comment
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
function_decl|;
comment|// QXmlDeclHandler methods
name|bool
name|attributeDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|eName
parameter_list|,
specifier|const
name|QString
modifier|&
name|aName
parameter_list|,
specifier|const
name|QString
modifier|&
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|valueDefault
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|internalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
function_decl|;
name|bool
name|externalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
function_decl|;
DECL|function|result
specifier|const
name|QString
modifier|&
name|result
parameter_list|()
specifier|const
block|{
return|return
name|m_result
return|;
block|}
DECL|function|errorMsg
specifier|const
name|QString
modifier|&
name|errorMsg
parameter_list|()
specifier|const
block|{
return|return
name|m_error_msg
return|;
block|}
private|private:
DECL|function|nestPrefix
name|QString
name|nestPrefix
parameter_list|()
specifier|const
block|{
return|return
name|QString
argument_list|()
operator|.
name|fill
argument_list|(
literal|' '
argument_list|,
literal|3
operator|*
name|m_nest
argument_list|)
return|;
block|}
name|QString
name|formatAttributes
parameter_list|(
specifier|const
name|QXmlAttributes
modifier|&
name|atts
parameter_list|)
function_decl|;
name|QString
name|escapeStr
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
function_decl|;
DECL|member|m_nest
name|unsigned
name|m_nest
decl_stmt|;
DECL|member|m_result
DECL|member|m_error_msg
name|QString
name|m_result
decl_stmt|,
name|m_error_msg
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|ContentHandler
name|ContentHandler
operator|::
name|ContentHandler
parameter_list|()
block|{
name|m_nest
operator|=
literal|0
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|startDocument
name|bool
name|ContentHandler
operator|::
name|startDocument
parameter_list|()
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"startDocument()\n"
expr_stmt|;
operator|++
name|m_nest
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|endDocument
name|bool
name|ContentHandler
operator|::
name|endDocument
parameter_list|()
block|{
operator|--
name|m_nest
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"endDocument()\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|startElement
name|bool
name|ContentHandler
operator|::
name|startElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceURI
parameter_list|,
specifier|const
name|QString
modifier|&
name|localName
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|,
specifier|const
name|QXmlAttributes
modifier|&
name|atts
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"startElement(namespaceURI=\""
operator|+
name|escapeStr
argument_list|(
name|namespaceURI
argument_list|)
operator|+
literal|"\", localName=\""
operator|+
name|escapeStr
argument_list|(
name|localName
argument_list|)
operator|+
literal|"\", qName=\""
operator|+
name|escapeStr
argument_list|(
name|qName
argument_list|)
operator|+
literal|"\", atts=["
operator|+
name|formatAttributes
argument_list|(
name|atts
argument_list|)
operator|+
literal|"])\n"
expr_stmt|;
operator|++
name|m_nest
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|escapeStr
name|QString
name|ContentHandler
operator|::
name|escapeStr
parameter_list|(
specifier|const
name|QString
modifier|&
name|s
parameter_list|)
block|{
name|QString
name|result
init|=
name|s
decl_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\""
argument_list|)
argument_list|,
literal|"\\\""
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\\"
argument_list|)
argument_list|,
literal|"\\\\"
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\n"
argument_list|)
argument_list|,
literal|"\\n"
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\r"
argument_list|)
argument_list|,
literal|"\\r"
argument_list|)
expr_stmt|;
name|result
operator|.
name|replace
argument_list|(
name|QRegExp
argument_list|(
literal|"\t"
argument_list|)
argument_list|,
literal|"\\t"
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|formatAttributes
name|QString
name|ContentHandler
operator|::
name|formatAttributes
parameter_list|(
specifier|const
name|QXmlAttributes
modifier|&
name|atts
parameter_list|)
block|{
name|QString
name|result
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|,
name|cnt
init|=
name|atts
operator|.
name|count
argument_list|()
init|;
name|i
operator|<
name|cnt
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|i
operator|!=
literal|0
condition|)
name|result
operator|+=
literal|", "
expr_stmt|;
name|result
operator|+=
literal|"{localName=\""
operator|+
name|escapeStr
argument_list|(
name|atts
operator|.
name|localName
argument_list|(
name|i
argument_list|)
argument_list|)
operator|+
literal|"\", qName=\""
operator|+
name|escapeStr
argument_list|(
name|atts
operator|.
name|qName
argument_list|(
name|i
argument_list|)
argument_list|)
operator|+
literal|"\", uri=\""
operator|+
name|escapeStr
argument_list|(
name|atts
operator|.
name|uri
argument_list|(
name|i
argument_list|)
argument_list|)
operator|+
literal|"\", type=\""
operator|+
name|escapeStr
argument_list|(
name|atts
operator|.
name|type
argument_list|(
name|i
argument_list|)
argument_list|)
operator|+
literal|"\", value=\""
operator|+
name|escapeStr
argument_list|(
name|atts
operator|.
name|value
argument_list|(
name|i
argument_list|)
argument_list|)
operator|+
literal|"\"}"
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
end_function
begin_function
DECL|function|endElement
name|bool
name|ContentHandler
operator|::
name|endElement
parameter_list|(
specifier|const
name|QString
modifier|&
name|namespaceURI
parameter_list|,
specifier|const
name|QString
modifier|&
name|localName
parameter_list|,
specifier|const
name|QString
modifier|&
name|qName
parameter_list|)
block|{
operator|--
name|m_nest
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"endElement(namespaceURI=\""
operator|+
name|escapeStr
argument_list|(
name|namespaceURI
argument_list|)
operator|+
literal|"\", localName=\""
operator|+
name|escapeStr
argument_list|(
name|localName
argument_list|)
operator|+
literal|"\", qName=\""
operator|+
name|escapeStr
argument_list|(
name|qName
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|characters
name|bool
name|ContentHandler
operator|::
name|characters
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"characters(ch=\""
operator|+
name|escapeStr
argument_list|(
name|ch
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|setDocumentLocator
name|void
name|ContentHandler
operator|::
name|setDocumentLocator
parameter_list|(
name|QXmlLocator
modifier|*
name|locator
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"setDocumentLocator(locator={columnNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|locator
operator|->
name|columnNumber
argument_list|()
argument_list|)
operator|+
literal|", lineNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|locator
operator|->
name|lineNumber
argument_list|()
argument_list|)
operator|+
literal|"})\n"
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startPrefixMapping
name|bool
name|ContentHandler
operator|::
name|startPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|,
specifier|const
name|QString
modifier|&
name|uri
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"startPrefixMapping(prefix=\""
operator|+
name|escapeStr
argument_list|(
name|prefix
argument_list|)
operator|+
literal|"\", uri=\""
operator|+
name|escapeStr
argument_list|(
name|uri
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
operator|++
name|m_nest
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|endPrefixMapping
name|bool
name|ContentHandler
operator|::
name|endPrefixMapping
parameter_list|(
specifier|const
name|QString
modifier|&
name|prefix
parameter_list|)
block|{
operator|--
name|m_nest
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"endPrefixMapping(prefix=\""
operator|+
name|escapeStr
argument_list|(
name|prefix
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|ignorableWhitespace
name|bool
name|ContentHandler
operator|::
name|ignorableWhitespace
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"ignorableWhitespace(ch=\""
operator|+
name|escapeStr
argument_list|(
name|ch
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|processingInstruction
name|bool
name|ContentHandler
operator|::
name|processingInstruction
parameter_list|(
specifier|const
name|QString
modifier|&
name|target
parameter_list|,
specifier|const
name|QString
modifier|&
name|data
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"processingInstruction(target=\""
operator|+
name|escapeStr
argument_list|(
name|target
argument_list|)
operator|+
literal|"\", data=\""
operator|+
name|escapeStr
argument_list|(
name|data
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|skippedEntity
name|bool
name|ContentHandler
operator|::
name|skippedEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"skippedEntity(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|warning
name|bool
name|ContentHandler
operator|::
name|warning
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
block|{
name|m_error_msg
operator|=
name|QString
argument_list|(
literal|"Warning %1:%2: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"warning(exception={columnNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|+
literal|", lineNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|+
literal|", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|publicId
argument_list|()
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|systemId
argument_list|()
argument_list|)
operator|+
literal|"\", message=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
operator|+
literal|"\"})\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|error
name|bool
name|ContentHandler
operator|::
name|error
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
block|{
name|m_error_msg
operator|=
name|QString
argument_list|(
literal|"Error %1:%2: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"error(exception={columnNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|+
literal|", lineNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|+
literal|", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|publicId
argument_list|()
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|systemId
argument_list|()
argument_list|)
operator|+
literal|"\", message=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
operator|+
literal|"\"})\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|fatalError
name|bool
name|ContentHandler
operator|::
name|fatalError
parameter_list|(
specifier|const
name|QXmlParseException
modifier|&
name|exception
parameter_list|)
block|{
name|m_error_msg
operator|=
name|QString
argument_list|(
literal|"Fatal error %1:%2: %3"
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|.
name|arg
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"fatalError(exception={columnNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|exception
operator|.
name|columnNumber
argument_list|()
argument_list|)
operator|+
literal|", lineNumber="
operator|+
name|QString
operator|::
name|number
argument_list|(
name|exception
operator|.
name|lineNumber
argument_list|()
argument_list|)
operator|+
literal|", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|publicId
argument_list|()
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|systemId
argument_list|()
argument_list|)
operator|+
literal|"\", message=\""
operator|+
name|escapeStr
argument_list|(
name|exception
operator|.
name|message
argument_list|()
argument_list|)
operator|+
literal|"\"})\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|notationDecl
name|bool
name|ContentHandler
operator|::
name|notationDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"notationDecl(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|publicId
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|systemId
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|unparsedEntityDecl
name|bool
name|ContentHandler
operator|::
name|unparsedEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
specifier|const
name|QString
modifier|&
name|notationName
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"unparsedEntityDecl(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|publicId
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|systemId
argument_list|)
operator|+
literal|"\", notationName=\""
operator|+
name|escapeStr
argument_list|(
name|notationName
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|resolveEntity
name|bool
name|ContentHandler
operator|::
name|resolveEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|,
name|QXmlInputSource
modifier|*
modifier|&
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"resolveEntity(publicId=\""
operator|+
name|escapeStr
argument_list|(
name|publicId
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|systemId
argument_list|)
operator|+
literal|"\", ret={})\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|startDTD
name|bool
name|ContentHandler
operator|::
name|startDTD
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"startDTD(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|publicId
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|systemId
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
operator|++
name|m_nest
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|endDTD
name|bool
name|ContentHandler
operator|::
name|endDTD
parameter_list|()
block|{
operator|--
name|m_nest
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"endDTD()\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|startEntity
name|bool
name|ContentHandler
operator|::
name|startEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"startEntity(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
operator|++
name|m_nest
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|endEntity
name|bool
name|ContentHandler
operator|::
name|endEntity
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|)
block|{
operator|--
name|m_nest
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"endEntity(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|startCDATA
name|bool
name|ContentHandler
operator|::
name|startCDATA
parameter_list|()
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"startCDATA()\n"
expr_stmt|;
operator|++
name|m_nest
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|endCDATA
name|bool
name|ContentHandler
operator|::
name|endCDATA
parameter_list|()
block|{
operator|--
name|m_nest
expr_stmt|;
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"endCDATA()\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|comment
name|bool
name|ContentHandler
operator|::
name|comment
parameter_list|(
specifier|const
name|QString
modifier|&
name|ch
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"comment(ch=\""
operator|+
name|escapeStr
argument_list|(
name|ch
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|attributeDecl
name|bool
name|ContentHandler
operator|::
name|attributeDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|eName
parameter_list|,
specifier|const
name|QString
modifier|&
name|aName
parameter_list|,
specifier|const
name|QString
modifier|&
name|type
parameter_list|,
specifier|const
name|QString
modifier|&
name|valueDefault
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"attributeDecl(eName=\""
operator|+
name|escapeStr
argument_list|(
name|eName
argument_list|)
operator|+
literal|"\", aName=\""
operator|+
name|escapeStr
argument_list|(
name|aName
argument_list|)
operator|+
literal|"\", type=\""
operator|+
name|escapeStr
argument_list|(
name|type
argument_list|)
operator|+
literal|"\", valueDefault=\""
operator|+
name|escapeStr
argument_list|(
name|valueDefault
argument_list|)
operator|+
literal|"\", value=\""
operator|+
name|escapeStr
argument_list|(
name|value
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|internalEntityDecl
name|bool
name|ContentHandler
operator|::
name|internalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|value
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"internatlEntityDecl(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\", value=\""
operator|+
name|escapeStr
argument_list|(
name|value
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_function
DECL|function|externalEntityDecl
name|bool
name|ContentHandler
operator|::
name|externalEntityDecl
parameter_list|(
specifier|const
name|QString
modifier|&
name|name
parameter_list|,
specifier|const
name|QString
modifier|&
name|publicId
parameter_list|,
specifier|const
name|QString
modifier|&
name|systemId
parameter_list|)
block|{
name|m_result
operator|+=
name|nestPrefix
argument_list|()
expr_stmt|;
name|m_result
operator|+=
literal|"externalEntityDecl(name=\""
operator|+
name|escapeStr
argument_list|(
name|name
argument_list|)
operator|+
literal|"\", publicId=\""
operator|+
name|escapeStr
argument_list|(
name|publicId
argument_list|)
operator|+
literal|"\", systemId=\""
operator|+
name|escapeStr
argument_list|(
name|systemId
argument_list|)
operator|+
literal|"\")\n"
expr_stmt|;
return|return
literal|true
return|;
block|}
end_function
begin_constructor
DECL|function|Parser
name|Parser
operator|::
name|Parser
parameter_list|()
block|{
name|handler
operator|=
operator|new
name|ContentHandler
expr_stmt|;
name|setContentHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
name|setDTDHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
name|setDeclHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
name|setEntityResolver
argument_list|(
name|handler
argument_list|)
expr_stmt|;
name|setErrorHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
name|setLexicalHandler
argument_list|(
name|handler
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_destructor
DECL|function|~Parser
name|Parser
operator|::
name|~
name|Parser
parameter_list|()
block|{
operator|delete
name|handler
expr_stmt|;
block|}
end_destructor
begin_function
DECL|function|parseFile
name|bool
name|Parser
operator|::
name|parseFile
parameter_list|(
name|QFile
modifier|*
name|file
parameter_list|)
block|{
name|QXmlInputSource
name|source
argument_list|(
name|file
argument_list|)
decl_stmt|;
return|return
name|parse
argument_list|(
name|source
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|result
name|QString
name|Parser
operator|::
name|result
parameter_list|()
specifier|const
block|{
return|return
name|handler
operator|->
name|result
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|errorMsg
name|QString
name|Parser
operator|::
name|errorMsg
parameter_list|()
specifier|const
block|{
return|return
name|handler
operator|->
name|errorMsg
argument_list|()
return|;
block|}
end_function
end_unit
