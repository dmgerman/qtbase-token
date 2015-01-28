begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2015 The Qt Company Ltd. ** Contact: http://www.qt.io/licensing/ ** ** This file is part of the QtXml module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see http://www.qt.io/terms-conditions. For further ** information use the contact form at http://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** As a special exception, The Qt Company gives you certain additional ** rights. These rights are described in The Qt Company LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXML_P_H
end_ifndef
begin_define
DECL|macro|QXML_P_H
define|#
directive|define
name|QXML_P_H
end_define
begin_include
include|#
directive|include
file|<qstack.h>
end_include
begin_include
include|#
directive|include
file|<qmap.h>
end_include
begin_include
include|#
directive|include
file|<qxml.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
comment|//
comment|//  W A R N I N G
comment|//  -------------
comment|//
comment|// This file is not part of the Qt API. It exists for the convenience of
comment|// qxml.cpp and qdom.cpp. This header file may change from version to version without
comment|// notice, or even be removed.
comment|//
comment|// We mean it.
comment|//
name|class
name|QXmlSimpleReaderPrivate
block|{
name|public
label|:
operator|~
name|QXmlSimpleReaderPrivate
argument_list|()
expr_stmt|;
name|private
label|:
comment|// functions
name|QXmlSimpleReaderPrivate
argument_list|(
name|QXmlSimpleReader
operator|*
name|reader
argument_list|)
expr_stmt|;
name|void
name|initIncrementalParsing
parameter_list|()
function_decl|;
comment|// used to determine if elements are correctly nested
name|QStack
operator|<
name|QString
operator|>
name|tags
expr_stmt|;
comment|// used by parseReference() and parsePEReference()
enum|enum
name|EntityRecognitionContext
block|{
name|InContent
block|,
name|InAttributeValue
block|,
name|InEntityValue
block|,
name|InDTD
block|}
enum|;
comment|// used for entity declarations
struct|struct
name|ExternParameterEntity
block|{
name|ExternParameterEntity
argument_list|()
block|{}
name|ExternParameterEntity
argument_list|(
specifier|const
name|QString
operator|&
name|p
argument_list|,
specifier|const
name|QString
operator|&
name|s
argument_list|)
operator|:
name|publicId
argument_list|(
name|p
argument_list|)
operator|,
name|systemId
argument_list|(
argument|s
argument_list|)
block|{}
name|QString
name|publicId
expr_stmt|;
name|QString
name|systemId
decl_stmt|;
name|Q_DUMMY_COMPARISON_OPERATOR
argument_list|(
argument|ExternParameterEntity
argument_list|)
block|}
struct|;
struct|struct
name|ExternEntity
block|{
name|ExternEntity
argument_list|()
block|{}
name|ExternEntity
argument_list|(
specifier|const
name|QString
operator|&
name|p
argument_list|,
specifier|const
name|QString
operator|&
name|s
argument_list|,
specifier|const
name|QString
operator|&
name|n
argument_list|)
operator|:
name|publicId
argument_list|(
name|p
argument_list|)
operator|,
name|systemId
argument_list|(
name|s
argument_list|)
operator|,
name|notation
argument_list|(
argument|n
argument_list|)
block|{}
name|QString
name|publicId
expr_stmt|;
name|QString
name|systemId
decl_stmt|;
name|QString
name|notation
decl_stmt|;
name|Q_DUMMY_COMPARISON_OPERATOR
argument_list|(
argument|ExternEntity
argument_list|)
block|}
struct|;
name|QMap
operator|<
name|QString
operator|,
name|ExternParameterEntity
operator|>
name|externParameterEntities
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|parameterEntities
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|ExternEntity
operator|>
name|externEntities
expr_stmt|;
name|QMap
operator|<
name|QString
operator|,
name|QString
operator|>
name|entities
expr_stmt|;
comment|// used for parsing of entity references
struct|struct
name|XmlRef
block|{
name|XmlRef
argument_list|()
operator|:
name|index
argument_list|(
literal|0
argument_list|)
block|{}
name|XmlRef
argument_list|(
specifier|const
name|QString
operator|&
name|_name
argument_list|,
specifier|const
name|QString
operator|&
name|_value
argument_list|)
operator|:
name|name
argument_list|(
name|_name
argument_list|)
operator|,
name|value
argument_list|(
name|_value
argument_list|)
operator|,
name|index
argument_list|(
literal|0
argument_list|)
block|{}
name|bool
name|isEmpty
argument_list|()
specifier|const
block|{
return|return
name|index
operator|==
name|value
operator|.
name|length
argument_list|()
return|;
block|}
name|QChar
name|next
parameter_list|()
block|{
return|return
name|value
operator|.
name|at
argument_list|(
name|index
operator|++
argument_list|)
return|;
block|}
name|QString
name|name
decl_stmt|;
name|QString
name|value
decl_stmt|;
name|int
name|index
decl_stmt|;
block|}
struct|;
name|QStack
operator|<
name|XmlRef
operator|>
name|xmlRefStack
expr_stmt|;
comment|// used for standalone declaration
enum|enum
name|Standalone
block|{
name|Yes
block|,
name|No
block|,
name|Unknown
block|}
enum|;
name|QString
name|doctype
decl_stmt|;
comment|// only used for the doctype
name|QString
name|xmlVersion
decl_stmt|;
comment|// only used to store the version information
name|QString
name|encoding
decl_stmt|;
comment|// only used to store the encoding
name|Standalone
name|standalone
decl_stmt|;
comment|// used to store the value of the standalone declaration
name|QString
name|publicId
decl_stmt|;
comment|// used by parseExternalID() to store the public ID
name|QString
name|systemId
decl_stmt|;
comment|// used by parseExternalID() to store the system ID
comment|// Since publicId/systemId is used as temporary variables by parseExternalID(), it
comment|// might overwrite the PUBLIC/SYSTEM for the document we're parsing. In effect, we would
comment|// possibly send off an QXmlParseException that has the PUBLIC/SYSTEM of a entity declaration
comment|// instead of those of the current document.
comment|// Hence we have these two variables for storing the document's data.
name|QString
name|thisPublicId
decl_stmt|;
name|QString
name|thisSystemId
decl_stmt|;
name|QString
name|attDeclEName
decl_stmt|;
comment|// use by parseAttlistDecl()
name|QString
name|attDeclAName
decl_stmt|;
comment|// use by parseAttlistDecl()
comment|// flags for some features support
name|bool
name|useNamespaces
decl_stmt|;
name|bool
name|useNamespacePrefixes
decl_stmt|;
name|bool
name|reportWhitespaceCharData
decl_stmt|;
name|bool
name|reportEntities
decl_stmt|;
comment|// used to build the attribute list
name|QXmlAttributes
name|attList
decl_stmt|;
comment|// used in QXmlSimpleReader::parseContent() to decide whether character
comment|// data was read
name|bool
name|contentCharDataRead
decl_stmt|;
comment|// Hack for letting QDom know where the skipped entity occurred
name|bool
name|skipped_entity_in_content
decl_stmt|;
comment|// helper classes
name|QScopedPointer
operator|<
name|QXmlLocator
operator|>
name|locator
expr_stmt|;
name|QXmlNamespaceSupport
name|namespaceSupport
decl_stmt|;
comment|// error string
name|QString
name|error
decl_stmt|;
comment|// arguments for parse functions (this is needed to allow incremental
comment|// parsing)
name|bool
name|parsePI_xmldecl
decl_stmt|;
name|bool
name|parseName_useRef
decl_stmt|;
name|bool
name|parseReference_charDataRead
decl_stmt|;
name|EntityRecognitionContext
name|parseReference_context
decl_stmt|;
name|bool
name|parseExternalID_allowPublicID
decl_stmt|;
name|EntityRecognitionContext
name|parsePEReference_context
decl_stmt|;
name|QString
name|parseString_s
decl_stmt|;
comment|// for incremental parsing
struct|struct
name|ParseState
block|{
typedef|typedef
name|bool
argument_list|(
name|QXmlSimpleReaderPrivate
operator|::
operator|*
name|ParseFunction
argument_list|)
argument_list|()
expr_stmt|;
name|ParseFunction
name|function
decl_stmt|;
name|int
name|state
decl_stmt|;
block|}
struct|;
name|QStack
operator|<
name|ParseState
operator|>
operator|*
name|parseStack
expr_stmt|;
comment|// used in parseProlog()
name|bool
name|xmldecl_possible
decl_stmt|;
name|bool
name|doctype_read
decl_stmt|;
comment|// used in parseDoctype()
name|bool
name|startDTDwasReported
decl_stmt|;
comment|// used in parseString()
name|signed
name|char
name|Done
decl_stmt|;
comment|// variables
name|QXmlContentHandler
modifier|*
name|contentHnd
decl_stmt|;
name|QXmlErrorHandler
modifier|*
name|errorHnd
decl_stmt|;
name|QXmlDTDHandler
modifier|*
name|dtdHnd
decl_stmt|;
name|QXmlEntityResolver
modifier|*
name|entityRes
decl_stmt|;
name|QXmlLexicalHandler
modifier|*
name|lexicalHnd
decl_stmt|;
name|QXmlDeclHandler
modifier|*
name|declHnd
decl_stmt|;
name|QXmlInputSource
modifier|*
name|inputSource
decl_stmt|;
name|QChar
name|c
decl_stmt|;
comment|// the character at reading position
name|int
name|lineNr
decl_stmt|;
comment|// number of line
name|int
name|columnNr
decl_stmt|;
comment|// position in line
name|QChar
name|nameArray
index|[
literal|256
index|]
decl_stmt|;
comment|// only used for names
name|QString
name|nameValue
decl_stmt|;
comment|// only used for names
name|int
name|nameArrayPos
decl_stmt|;
name|int
name|nameValueLen
decl_stmt|;
name|QChar
name|refArray
index|[
literal|256
index|]
decl_stmt|;
comment|// only used for references
name|QString
name|refValue
decl_stmt|;
comment|// only used for references
name|int
name|refArrayPos
decl_stmt|;
name|int
name|refValueLen
decl_stmt|;
name|QChar
name|stringArray
index|[
literal|256
index|]
decl_stmt|;
comment|// used for any other strings that are parsed
name|QString
name|stringValue
decl_stmt|;
comment|// used for any other strings that are parsed
name|int
name|stringArrayPos
decl_stmt|;
name|int
name|stringValueLen
decl_stmt|;
name|QString
name|emptyStr
decl_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|int
operator|>
name|literalEntitySizes
expr_stmt|;
comment|// The entity at (QMap<QString,) referenced the entities at (QMap<QString,) (int>) times.
name|QHash
operator|<
name|QString
operator|,
name|QHash
operator|<
name|QString
operator|,
name|int
operator|>
expr|>
name|referencesToOtherEntities
expr_stmt|;
name|QHash
operator|<
name|QString
operator|,
name|int
operator|>
name|expandedSizes
expr_stmt|;
comment|// The limit to the amount of times the DTD parsing functions can be called
comment|// for the DTD currently being parsed.
specifier|static
specifier|const
name|int
name|dtdRecursionLimit
init|=
literal|2
decl_stmt|;
comment|// The maximum amount of characters an entity value may contain, after expansion.
specifier|static
specifier|const
name|int
name|entityCharacterLimit
init|=
literal|1024
decl_stmt|;
specifier|const
name|QString
modifier|&
name|string
parameter_list|()
function_decl|;
name|void
name|stringClear
parameter_list|()
function_decl|;
name|void
name|stringAddC
parameter_list|(
name|QChar
parameter_list|)
function_decl|;
specifier|inline
name|void
name|stringAddC
parameter_list|()
block|{
name|stringAddC
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QString
modifier|&
name|name
parameter_list|()
function_decl|;
name|void
name|nameClear
parameter_list|()
function_decl|;
name|void
name|nameAddC
parameter_list|(
name|QChar
parameter_list|)
function_decl|;
specifier|inline
name|void
name|nameAddC
parameter_list|()
block|{
name|nameAddC
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
specifier|const
name|QString
modifier|&
name|ref
parameter_list|()
function_decl|;
name|void
name|refClear
parameter_list|()
function_decl|;
name|void
name|refAddC
parameter_list|(
name|QChar
parameter_list|)
function_decl|;
specifier|inline
name|void
name|refAddC
parameter_list|()
block|{
name|refAddC
argument_list|(
name|c
argument_list|)
expr_stmt|;
block|}
comment|// private functions
name|bool
name|eat_ws
parameter_list|()
function_decl|;
name|bool
name|next_eat_ws
parameter_list|()
function_decl|;
name|void
name|QT_FASTCALL
name|next
parameter_list|()
function_decl|;
name|bool
name|atEnd
parameter_list|()
function_decl|;
name|void
name|init
parameter_list|(
specifier|const
name|QXmlInputSource
modifier|*
name|i
parameter_list|)
function_decl|;
name|void
name|initData
parameter_list|()
function_decl|;
name|bool
name|entityExist
argument_list|(
specifier|const
name|QString
operator|&
argument_list|)
decl|const
decl_stmt|;
name|bool
name|parseBeginOrContinue
parameter_list|(
name|int
name|state
parameter_list|,
name|bool
name|incremental
parameter_list|)
function_decl|;
name|bool
name|parseProlog
parameter_list|()
function_decl|;
name|bool
name|parseElement
parameter_list|()
function_decl|;
name|bool
name|processElementEmptyTag
parameter_list|()
function_decl|;
name|bool
name|processElementETagBegin2
parameter_list|()
function_decl|;
name|bool
name|processElementAttribute
parameter_list|()
function_decl|;
name|bool
name|parseMisc
parameter_list|()
function_decl|;
name|bool
name|parseContent
parameter_list|()
function_decl|;
name|bool
name|parsePI
parameter_list|()
function_decl|;
name|bool
name|parseDoctype
parameter_list|()
function_decl|;
name|bool
name|parseComment
parameter_list|()
function_decl|;
name|bool
name|parseName
parameter_list|()
function_decl|;
name|bool
name|parseNmtoken
parameter_list|()
function_decl|;
name|bool
name|parseAttribute
parameter_list|()
function_decl|;
name|bool
name|parseReference
parameter_list|()
function_decl|;
name|bool
name|processReference
parameter_list|()
function_decl|;
name|bool
name|parseExternalID
parameter_list|()
function_decl|;
name|bool
name|parsePEReference
parameter_list|()
function_decl|;
name|bool
name|parseMarkupdecl
parameter_list|()
function_decl|;
name|bool
name|parseAttlistDecl
parameter_list|()
function_decl|;
name|bool
name|parseAttType
parameter_list|()
function_decl|;
name|bool
name|parseAttValue
parameter_list|()
function_decl|;
name|bool
name|parseElementDecl
parameter_list|()
function_decl|;
name|bool
name|parseNotationDecl
parameter_list|()
function_decl|;
name|bool
name|parseChoiceSeq
parameter_list|()
function_decl|;
name|bool
name|parseEntityDecl
parameter_list|()
function_decl|;
name|bool
name|parseEntityValue
parameter_list|()
function_decl|;
name|bool
name|parseString
parameter_list|()
function_decl|;
name|bool
name|insertXmlRef
parameter_list|(
specifier|const
name|QString
modifier|&
parameter_list|,
specifier|const
name|QString
modifier|&
parameter_list|,
name|bool
parameter_list|)
function_decl|;
name|bool
name|reportEndEntities
parameter_list|()
function_decl|;
name|void
name|reportParseError
parameter_list|(
specifier|const
name|QString
modifier|&
name|error
parameter_list|)
function_decl|;
typedef|typedef
name|bool
argument_list|(
name|QXmlSimpleReaderPrivate
operator|::
operator|*
name|ParseFunction
argument_list|)
argument_list|()
expr_stmt|;
name|void
name|unexpectedEof
parameter_list|(
name|ParseFunction
name|where
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
name|void
name|parseFailed
parameter_list|(
name|ParseFunction
name|where
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
name|void
name|pushParseState
parameter_list|(
name|ParseFunction
name|function
parameter_list|,
name|int
name|state
parameter_list|)
function_decl|;
name|bool
name|isExpandedEntityValueTooLarge
parameter_list|(
name|QString
modifier|*
name|errorMessage
parameter_list|)
function_decl|;
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QXmlSimpleReader
argument_list|)
name|QXmlSimpleReader
modifier|*
name|q_ptr
decl_stmt|;
name|friend
name|class
name|QXmlSimpleReaderLocator
decl_stmt|;
name|friend
name|class
name|QDomHandler
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXML_P_H
end_comment
end_unit
